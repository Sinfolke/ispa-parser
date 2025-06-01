module AST.Tree;
import ASTPass;
import logging;
import dstd;
import AST.API;
import LLIR.Builder;
import LLIR.Builder.DataWrapper;
import LLIR.Rule.MemberBuilder;
import LLIR.Builder.Data;
import cpuf.printf;
import Tlog.Logger;
import std;
import std.compat;

auto AST::Tree::getTerminals() -> stdu::vector<stdu::vector<std::string>> {
    stdu::vector<stdu::vector<std::string>> set;
    for (const auto &[name, value] : tree_map) {
        if (corelib::text::isUpper(name.back()))
            set.push_back(name);
    }
    return set;
}
auto AST::Tree::getNonTerminals() -> stdu::vector<stdu::vector<std::string>> {
    stdu::vector<stdu::vector<std::string>> set;
    for (const auto &[name, value] : tree_map) {
        if (corelib::text::isLower(name.back()))
            set.push_back(name);
    }
    return set;
}
void AST::Tree::getUsePlacesTable(const stdu::vector<AST::RuleMember> &members, const stdu::vector<std::string> &name) {
    for (const auto &member : members) {
        if (member.isGroup()) {
            getUsePlacesTable(member.getGroup().values, name);
        } else if (member.isOp()) {
            getUsePlacesTable(member.getOp().options, name);
        } else if (member.isName()) {
            use_places[member.getName().name].push_back(name);
        }
    }
}
auto AST::Tree::createUsePlacesTable() -> UsePlaceTable& {
    for (const auto &[name, value] : tree_map) {
        getUsePlacesTable(value.rule_members, name);
    }
    return use_places;
}
auto AST::Tree::compute_group_length(const stdu::vector<AST::RuleMember> &group) -> size_t {
    size_t count = 0;
    for (auto &rule : group) {
        if (rule.isGroup() && rule.quantifier == '\0') {
            count += compute_group_length(rule.getGroup().values);
        } else count++;
    }
    return count;
};
void AST::Tree::transform_helper(
    stdu::vector<AST::RuleMember> &members,
    const stdu::vector<std::string> &fullname,
    const stdu::vector<std::string> &original_fullname,
    utype::unordered_map<stdu::vector<std::string>, std::pair<char, stdu::vector<std::string>>> &replacements
) {
    logger.increaseIndentLevel();
    auto size = members.size();
    for (size_t i = 0; i < size; ++i) {
        auto &member = members[i];
        if (member.isGroup()) {
            logger.increaseIndentLevel();
            logger.log("IsGroup, data: ");
            logger.increaseIndentLevel();
            logger.log("{}", member.getGroup().values);
            logger.decreaseIndentLevel();
            auto data = member.getGroup(); // should be copy!!!
            if (member.quantifier == '\0') {
                transform_helper(data.values, fullname, original_fullname, replacements);
                logger.log("Unrolling group with empty quantifier: {}", members);

                // Remove the group at position i
                auto it = members.erase(members.begin() + i);

                // Insert inlined values at position i
                members.insert(it, data.values.begin(), data.values.end());

                logger.log("Unrolled to {}, inserted {} elements at {}", members, data.values.size(), i);

                // Move i past inserted values
                i += data.values.size();  // Already erased 1, inserted N — so we skip N

                continue;
            }
            std::string quant_rule_name = "__grp" + std::to_string(i);
            auto quant_fullname = fullname;
            quant_fullname.push_back(quant_rule_name);
            // Recursively process the group
            logger.log("running transform_helper on group");
            transform_helper(data.values, quant_fullname, original_fullname, replacements);

            stdu::vector<stdu::vector<AST::RuleMember>> new_alternatives;
            logger.log("quant_fullname: {}", quant_fullname);
            // Replace current member with reference to new rule
            member = AST::RuleMember { .value = AST::RuleMemberName {.name = quant_fullname} };

            stdu::vector<stdu::vector<AST::RuleMember>> new_alts;
            logger.log("dealing with quantifier {}", member.quantifier);
            switch (member.quantifier) {
                case '?':
                    new_alts.push_back({}); // empty
                    new_alts.push_back(data.values);
                    break;

                case '+': {
                    // + = A A*
                    std::string tail_name = quant_rule_name + "_tail";
                    auto tail_fullname = quant_fullname;
                    tail_fullname.push_back(tail_name);

                    // A → data tail
                    auto base = data.values;
                    base.push_back(AST::RuleMember { .value = AST::RuleMemberName {.name = tail_fullname} });
                    new_alts.push_back(base);

                    // A* tail: ε | data tail
                    stdu::vector<stdu::vector<AST::RuleMember>> tail_alts;
                    tail_alts.push_back({});
                    auto recur = data.values;
                    recur.push_back(AST::RuleMember { .value = AST::RuleMemberName {.name = tail_fullname} });
                    tail_alts.push_back(recur);

                    for (auto &alt : tail_alts)
                        initial_item_set[tail_fullname].push_back(AST::Rule {.rule_members = alt, .original_rules = original_fullname});
                    break;
                }

                case '*': {
                    // * = ε | data A*
                    new_alts.push_back({});
                    auto recur = data.values;
                    recur.push_back(AST::RuleMember { .value = AST::RuleMemberName {.name = quant_fullname} });
                    new_alts.push_back(recur);
                    break;
                }
                default:
                    initial_item_set[quant_fullname].push_back(AST::Rule {
                        .rule_members = data.values,
                        .original_rules = original_fullname
                    });
            }

            for (auto &alt : new_alts) {
                logger.log("alt: ", alt);
                logger.increaseIndentLevel();
                logger.log("{}", alt);
                logger.decreaseIndentLevel();
                initial_item_set[quant_fullname].push_back(AST::Rule {.rule_members = alt, .original_rules = original_fullname});
            }
            logger.log("<leaving group>");
            logger.decreaseIndentLevel();
            continue;
        }
        if (member.isOp()) {
            logger.log("in Op: {}", member.getOp());
            auto data = member.getOp(); // should be copy !!!
            stdu::vector<std::string> push_name;
            stdu::vector<AST::RuleMember>::iterator val_it;
            stdu::vector<std::pair<size_t, size_t>> group_pos = {};
            size_t _count = 0;
            if (members.size() == 1) {
                logger.log("[branch] members.size() == 1");
                size_t count = 0;
                bool is_first_going_group = false;

                for (const auto &rule : data.options) {
                    if (rule.isGroup()) {
                        if (count == 0)
                            is_first_going_group = true;

                        auto len = compute_group_length(rule.getGroup().values);
                        group_pos.push_back({count, len});
                        count += len;
                        continue;
                    }
                    count++;
                }
                logger.log("group_pos: {}", group_pos);
                logger.log("running transform_helper on op");
                transform_helper(data.options, fullname, original_fullname, replacements); // process internal ops/groups
                if (is_first_going_group) {
                    logger.log("[branch] is_first_going_group == true");
                    logger.log("group_pos[0]: {}", group_pos[0]);
                    auto [pos, len] = group_pos[0];
                    auto insert_pos = members.begin() + i;
                    members.erase(insert_pos);  // erase original group placeholder

                    // Reset insert_pos, because erase invalidates it
                    insert_pos = members.begin() + i;

                    size_t j = 0;
                    val_it = data.options.begin();
                    logger.increaseIndentLevel();
                    for (; j < len; ++j, ++val_it, ++_count) {
                        logger.log("j: {}, _count: {}, val_it: {}", j, _count, &(*val_it));
                        insert_pos = members.insert(insert_pos, *val_it);
                        ++insert_pos; // move insert position forward for next item
                    }
                    logger.decreaseIndentLevel();

                    // val_it now correctly points to the remaining options, if any
                    val_it = data.options.begin() + j;
                } else {
                    logger.log("[branch] is_first_going_group == false");
                    logger.log("data.options[0]: {}, data.options.begin(): {}, data.options.begin() + 1: {}, _count: {}, _count + 1: {}",
                        data.options[0], &(*data.options.begin()), &(*data.options.begin()) + 1, _count, _count + 1
                    );
                    logger.log("remain element {} in set", data.options[0]);
                    members[i] = data.options[0];
                    val_it = data.options.begin() + 1;
                    _count++;
                }

                push_name = fullname;
            } else {
                logger.log("[branch] members.size() == {} (!= 1)", members.size());
                std::string name ="__rop" + std::to_string(i);
                auto new_fullname = fullname;
                new_fullname.push_back(name);
                members[i] = AST::RuleMember {.value = AST::RuleMemberName {.name = new_fullname}};

                transform_helper(data.options, fullname, original_fullname, replacements); // process internal ops/groups
                val_it = data.options.begin();
                push_name = new_fullname;
                logger.log("new_fullname: {}", new_fullname);
            }
            for (; val_it != data.options.end(); val_it++, _count++) {
                auto group = std::find_if(group_pos.begin(), group_pos.end(), [&_count](const std::pair<size_t, size_t> &unit) {return unit.first == _count;});
                stdu::vector<AST::RuleMember> values;
                logger.log("found group: {}", group != group_pos.end());
                if (group != group_pos.end()) {
                    logger.log("iterating through group");
                    for (size_t i = 0; i < group->second && val_it != data.options.end(); i++, _count++, val_it++) {
                        logger.log("i: {}, _count: {}, val_it: {}", i, _count, &(*val_it));
                        values.push_back(*val_it);
                    }
                    val_it--;
                    _count--;
                    logger.log("final _count: {}, val_it: {}", _count, &(*val_it));
                } else {
                    logger.log("inserting raw element {}", *val_it);
                    values.push_back(*val_it);
                }
                initial_item_set[push_name].push_back(AST::Rule {.rule_members = values, .original_rules = original_fullname});
            }
            logger.log("<Leaving Op>");
            continue;
        }
        // Handle standalone quantifier case (e.g., id?, id+, id*)
        if (member.quantifier == '\0')
            continue;

        auto find = replacements.find(fullname);
        if (find != replacements.end() && find->second.first == member.quantifier) {
            members[i] = AST::RuleMember {
                .quantifier = '\0',
                .value = AST::RuleMemberName {.name = find->second.second}
            };
            continue;
        }

        std::string quant_rule_name = "__q" + std::to_string(i);

        auto quant_fullname = fullname;
        quant_fullname.push_back(quant_rule_name);

        AST::RuleMember replaced = member;
        replaced.quantifier = '\0';

        stdu::vector<stdu::vector<AST::RuleMember>> new_alts;
        logger.log("dealing with quantifier {} for rule {}", member.quantifier, member);
        switch (member.quantifier) {
            case '?':
                new_alts.push_back({});
                new_alts.push_back({replaced});
                break;
            case '+': {
                std::string tail_name = quant_rule_name + "_tail";
                auto tail_fullname = quant_fullname;
                tail_fullname.push_back(tail_name);

                new_alts.push_back({
                    replaced,
                    AST::RuleMember {
                        .value = AST::RuleMemberName {.name = tail_fullname}
                    }
                });

                stdu::vector<stdu::vector<AST::RuleMember>> tail_alts = {
                    {},
                    {
                        replaced,
                        AST::RuleMember {
                            .value = AST::RuleMemberName {.name = tail_fullname}
                        }
                    }
                };
                for (auto &alt : tail_alts) {
                    initial_item_set[tail_fullname].push_back(AST::Rule {.rule_members = alt, .original_rules = original_fullname});
                }
                break;
            }
            case '*':
                new_alts.push_back({});
                new_alts.push_back({
                    replaced,
                    AST::RuleMember {
                        .value = AST::RuleMemberName {.name = quant_fullname}
                    }
                });
                break;
        }

        for (auto &alt : new_alts) {
            initial_item_set[quant_fullname].push_back(AST::Rule {.rule_members = alt, .original_rules = original_fullname});
        }
    }
    logger.decreaseIndentLevel();
}
void AST::Tree::transform() {
    stdu::vector<stdu::vector<std::string>> keys;
    for (const auto &pair : initial_item_set) {
        if (corelib::text::isLower(pair.first.back()))
            keys.push_back(pair.first);
    }

    utype::unordered_map<stdu::vector<std::string>, std::pair<char, stdu::vector<std::string>>> replacement;
    Tlog::Branch lb(logger, "AST/transform.log");
    for (const auto &name : keys) {
        auto it = initial_item_set.find(name);
        if (it == initial_item_set.end())
            throw Error("Previous key disappeared");
        if (it->second.empty())
            throw Error("Rule {} empty", name);
        logger.log("transforming {}: {}", name, it->second[0].rule_members);
        transform_helper(it->second[0].rule_members, name, name, replacement);
        logger.log("new rule {}: {}", name, it->second[0].rule_members);
    }
}
void AST::Tree::createInitialItemSet() {
    if (!initial_item_set.empty())
        return;
    for (auto [name, value] : tree_map) {
        value.original_rules = {name};
        initial_item_set[name] = {value};
    }
    transform();
}
auto AST::Tree::getInitialItemSet() -> InitialItemSet & {
    if (initial_item_set.empty())
        createInitialItemSet();
    return initial_item_set;
}

void AST::Tree::computeNullableSet() {
    bool changed;
    do {
        changed = false;
        for (const auto &[nonterminal, productions] : initial_item_set) {
            for (const auto &prod : productions) {
                bool allNullable = true;
                for (const auto &sym : prod.rule_members) {
                    if (!sym.isName()) {
                        allNullable = false;
                        break;
                    }
                    const auto &rule = sym.getName();
                    if (!nullable.count(rule.name)) {
                        allNullable = false;
                        break;
                    }
                }
                if (allNullable && nullable.insert(nonterminal).second)
                    changed = true;
            }
        }
    } while (changed);
}

void AST::Tree::constructFirstSet(const stdu::vector<AST::Rule>& options, const stdu::vector<std::string>& nonterminal, bool& changed) {
    logger.increaseIndentLevel();
    for (const auto& option : options) {
        bool nullable_prefix = true;
        for (const auto& member : option.rule_members) {
            if (member.isNospace())
                continue;
            if (!member.isName())
                throw Error("Non-RuleMemberName class, rule {}", nonterminal);

            const auto& rule_name = member.getName();
            auto& currentFirst = first[nonterminal];

            if (rule_name.name == nonterminal) {
                logger.log("rule.name == non-terminal -> continue");
                continue;  // Avoid self-loop
            }

            if (corelib::text::isLower(rule_name.name.back())) {
                // Nonterminal
                const auto& otherFirst = first[rule_name.name];
                logger.log("inserting non-terminal's[{}] first set: {} to {}", rule_name.name, otherFirst, nonterminal);
                for (const auto& el : otherFirst) {
                    if (corelib::text::isUpper(el.back()) && el != stdu::vector<std::string>{"ε"}) continue;
                    if (currentFirst.insert(el).second)
                        changed = true;
                }

                if (nullable.find(rule_name.name) == nullable.end()) {
                    nullable_prefix = false;
                    break;
                }

            } else {
                // Terminal
                logger.log("inserting terminal {} to {}", rule_name.name, nonterminal);
                if (currentFirst.insert(rule_name.name).second) {
                    changed = true;
                }
                nullable_prefix = false;
                break;
            }
        }

        if (nullable_prefix) {
            if (first[nonterminal].insert({"ε"}).second) {
                changed = true;
            }
        }
    }
    logger.decreaseIndentLevel();
}
void AST::Tree::constructFirstSet() {
    if (!first.empty())
        return;
    createInitialItemSet();
    computeNullableSet();
    bool changed;
    Tlog::Branch lb(logger, "AST/constructFirstSet.log");
    do {
        changed = false;
        logger.log("------------enter first set------------------");
        for (const auto &[nonterminal, productions] : initial_item_set) {
            logger.dlog("constructing first set for {} -> ", nonterminal);
            if (corelib::text::isUpper(nonterminal.back())) {
                logger.log("skipped\n");
                continue;
            }
            logger.dlog("\n");
            constructFirstSet(productions, productions[0].original_rules, changed);
        }
    } while (changed);
}

void AST::Tree::constructFollowSet() {
    if (!follow.empty())
        return;
    createInitialItemSet();
    follow[{"__start"}] = {{"$"}};
    bool hasChanges;
    bool prevDependedChanged;
    stdu::vector<stdu::vector<std::string>> prev_depend;
    stdu::vector<stdu::vector<std::string>> changed;
    Tlog::Branch lb(logger, "AST/constructFollowSet.log");
    do {
        hasChanges = false;
        prevDependedChanged = false;
        prev_depend.clear();
        changed.clear();
        for (const auto &[name, options] : initial_item_set) {
            bool is_left_recursive = false;
            if (corelib::text::isUpper(name.back()))
                continue;
            for (const auto &rules : options) {
                if (rules.rule_members.empty())
                    continue;
                auto rules_members_it = rules.rule_members.begin();
                while (rules_members_it->isNospace())
                    rules_members_it++;
                if (!rules_members_it->isName())
                    throw Error("Not RuleMemberName for rule {}", name);
                if (!rules.rule_members.empty() && name == rules_members_it->getName().name) {
                    is_left_recursive = true;
                }
                logger.dlog("Processing {} -> ", name);
                for (auto it = rules_members_it; it != rules.rule_members.end(); it++) {
                    if (it->isNospace())
                        continue;
                    if (!it->isName()) {
                        throw Error("Not RuleMemberName: {}, {}, name: {}", it->isGroup(), it->isOp(), name);
                    }
                    auto current_n = it->getName().name;
                    const stdu::vector<std::string> *current;
                    if (corelib::text::isUpper(current_n.back())) {
                        continue;
                    }
                    if (!initial_item_set[current_n][0].original_rules.empty()) {
                        current = &initial_item_set[current_n][0].original_rules;
                    } else {
                        current = &it->getName().name;
                    }

                    if (name == *current) {
                        // include first(name)
                        auto f = first[name];
                        logger.dlog("[right recursion] first[name: {}]: {}, ", name, first[name]);
                        for (auto &e : f) {
                            if (e == stdu::vector<std::string>{"ε"}) {
                                continue;
                            }
                            if (follow[name].insert(e).second)
                                hasChanges = true;
                        }
                        prev_depend.push_back(name);
                        continue;
                    }
                    if (is_left_recursive && corelib::text::isLower(current->back())) {
                        auto prev_size = follow[*current].size();
                        logger.log("[left_recursion] follow[current.name: {}]: {}, ", *current, follow[*current]);
                        follow[*current].insert(follow[name].begin(), follow[name].end());
                        if (prev_size != follow[*current].size())
                            hasChanges = true;
                        prev_depend.push_back(*current);
                    }
                    auto next_it = it + 1;
                    while (next_it != rules.rule_members.end() && !next_it->isName())
                        next_it++;
                    if (next_it == rules.rule_members.end()) {
                        if (name != *current) { // prevent self-insertion
                            auto &f_lhs = follow[name];
                            logger.log("current -> {}, [end of rule] follow[name: {}]: {}, ", *current, name, follow[name]);
                            for (auto &sym : f_lhs) {
                                if (follow[*current].insert(sym).second)
                                    hasChanges = true;
                            }
                        } else {
                            logger.log("[end of rule - skip self follow insertion] {} ", name);
                        }
                    } else {
                        auto next = next_it->getName();
                        if (next.isTerminal()) {
                            // terminal - just push
                            logger.dlog("[next is terminal] follow[name: {}]: {} insert {}, ", name, follow[name], next.name);
                            if (follow[*current].insert(next.name).second)
                                hasChanges = true;
                        } else {
                            // non-terminal, insert it's first
                            logger.dlog("[next is non-terminal] first[name: {}]: {}, ", name, follow[name]);
                            auto f = first[next.name];
                            bool has_epsilon = false;
                            for (auto &e : f) {
                                if (e == stdu::vector<std::string>{"ε"}) {
                                    has_epsilon = true;
                                    continue;
                                }
                                if (follow[*current].insert(e).second)
                                    hasChanges = true;
                            }
                            if (has_epsilon) {
                                // if ε in FIRST(next), add FOLLOW of LHS
                                auto &f_lhs = follow[name];
                                logger.dlog("[has_epsilon] follow[name: {}]: {}", name, follow[name]);
                                for (auto &sym : f_lhs) {
                                    if (follow[*current].insert(sym).second)
                                        hasChanges = true;
                                }
                            }
                            prev_depend.push_back(next.name);
                        }
                    }
                }
            }
            if (hasChanges) {
                changed.push_back(name);
            }
        }
        if (!hasChanges) {
            // slight optimization: perform check only if this could be last iteration
            for (auto &change_symbol : changed) {
                if (std::find(prev_depend.begin(), prev_depend.end(), change_symbol) != prev_depend.end()) {
                    prevDependedChanged = true;
                    break;
                }
            }
        }
        logger.log("");
    } while(hasChanges || prevDependedChanged);
}
auto AST::Tree::getCodeForLexer() -> lexer_code {
    AST::RuleMemberOp options;
    for (const auto &[name, value] : tree_map) {
        if (corelib::text::isLower(name.back()))
            continue;
        auto find_it = use_places.find(name);
        if (find_it != use_places.end() && name != stdu::vector<std::string>{"__WHITESPACE"}) {
            bool to_add = false;
            for (const auto &use_name : find_it->second) {
                if (corelib::text::isLower(use_name.back())) {
                    to_add = true;
                    break;
                }
            }
            if (to_add) {
                // add this token
                options.options.push_back(AST::RuleMember { .value = AST::RuleMemberName { name } });
            }
        } else if (name == stdu::vector<std::string> { "__WHITESPACE" }) {
            options.options.push_back(AST::RuleMember { .value = AST::RuleMemberName { name } });
        } else {
            printf("Not found %s in use_places\n", name.back().c_str());
        }
        // if not found, do not add this means the token is never used
    }
    TreePass::sortByPriority(*this, options);
    AST::RuleMember resultRule = { .value = options };
    // get lexer code
    LLIR::BuilderData bd(*this);
    LLIR::BuilderDataWrapper wrapper(bd);
    bd.fullname = {""};
    LLIR::MemberBuilder code(wrapper, resultRule);
    code.build();
    const auto &return_vars = code.getReturnVars();
    code.pop(); // remove space skip
    if (return_vars.empty())
        throw Error("Empty success var\n");
    return std::make_pair(code.getData(), return_vars[0].var);
}

void AST::Tree::formatFirstOrFollowSet(std::ostringstream &oss, AST::First &set) {
    for (auto &el : set) {
        oss << corelib::text::join(el.first, "_") << ": " << '{';
        for (auto name : el.second) {
            oss << corelib::text::join(name, "_") << ", ";
        }
        oss << "}\n";
    }
}

void AST::Tree::printFirstSet(const std::string &fileName) {
    // Step 1: Print to std::ostringstream
    std::ostringstream oss;
    formatFirstOrFollowSet(oss, getFirstSet());

    // Step 2: Output the stringstream content to a file
    std::ofstream outFile(fileName);
    if (outFile.is_open()) {
        outFile << oss.str();
        outFile.close();
    } else {
        std::cerr << "Failed to open the file for writing: " << fileName << "\n";
    }
}
void AST::Tree::printFollowSet(const std::string &fileName) {
    // Step 1: Print to std::ostringstream
    std::ostringstream oss;
    formatFirstOrFollowSet(oss, getFollowSet());

    // Step 2: Output the stringstream content to a file
    std::ofstream outFile(fileName);
    if (outFile.is_open()) {
        outFile << oss.str();
        outFile.close();
    } else {
        std::cerr << "Failed to open the file for writing: " << fileName << "\n";
    }
}