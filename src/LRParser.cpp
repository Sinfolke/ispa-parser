#include <LRParser.h>
static size_t compute_group_length(const std::vector<TreeAPI::RuleMember> &group) {
    size_t count = 0;
    for (auto &rule : group) {
        Parser::Rule quantifier;
        if (rule.isGroup() && rule.quantifier == '\0') {
            count += compute_group_length(rule.getGroup());
        } else count++;
    }
    return count;
};
auto LRParser::getActionTable() const -> const ActionTable& {
    return action_table;
}
auto LRParser::getGotoTable() const -> const GotoTable& {
    return goto_table;
}
auto LRParser::getRulesTable() const -> const Rules& {
    return rules;
}
auto LRParser::getMaxStatesCount() const -> size_t {
    size_t max_state = 0;
    for (const auto& [state, _] : action_table) {
        max_state = std::max(max_state, state);
    }
    return max_state;
}
auto LRParser::ActionTypeToString(const Action_type &type) -> std::string {
    switch (type) {
        case Action_type::SHIFT:
            return "SHIFT";
        case Action_type::REDUCE:
            return "REDUCE";
        case Action_type::ACCEPT:
            return "ACCEPT";
        case Action_type::DFA_RESOLVE:
            return "DFA_RESOLVE";
        case Action_type::ERROR:
            return "ERROR";

    }
    throw Error("Undefined action type: %$", (int) type);
}
auto LRParser::getActionTableAsRow() const -> std::vector<std::unordered_map<std::vector<std::string>, LRParser::Action>> {
    std::vector<std::unordered_map<std::vector<std::string>, LRParser::Action>> row_table;
    for (auto [state, value] : action_table) {
        while(row_table.size() <= state) {
            row_table.push_back({});
        }
        row_table[state] = value;
    }
    return row_table;
}
auto LRParser::getGotoTableAsRow() const -> std::vector<std::unordered_map<std::vector<std::string>, size_t>> {
    std::vector<std::unordered_map<std::vector<std::string>, size_t>> row_table;
    for (auto [state, value] : goto_table) {
        while(row_table.size() <= state) {
            row_table.push_back({});
        }
        row_table[state] = value;
    }
    return row_table;
}
bool LRParser::isELR() const {
    return false;
}
void LRParser::createInitialItemSet() {
    for (auto &[name, value] : tree->getRawAst().getTreeMap()) {
        initial_item_set[name] = {value};
    }
    tree->getRawAst().getTreeMap().clear();
}
void LRParser::transform_helper(std::vector<TreeAPI::RuleMember> members, const std::vector<std::string> &fullname, std::unordered_map<std::vector<std::string>, std::pair<char, std::vector<std::string>>> &replacements) {
    for (size_t i = 0; i < members.size(); i++) {
        auto &member = members[i];
        if (member.isGroup()) {
            for (auto &member : members) {
                if (member.isGroup()) {
                    auto data = member.getGroup();
                    // Recursively process the group
                    transform_helper(data, fullname, replacements);
        
                    if (member.quantifier == '\0') {
                        // Replace current rule with expanded group
                        members.erase(members.begin() + i);
                        members.insert(members.begin() + i, data.begin(), data.end());
                        i += data.size() - 2;
                        continue;
                    }
                    std::string quant_rule_name = "__grp" + std::to_string(i);
                    auto new_fullname = fullname;
                    new_fullname.back() = quant_rule_name;
                    // Replace with reference to new quant rule
                    member = TreeAPI::RuleMember {.value = TreeAPI::RuleMemberName {new_fullname}};
        
                    std::vector<std::vector<TreeAPI::RuleMember>> new_alternatives;
                    auto quant_fullname = fullname;
                    quant_fullname.back() = quant_rule_name;
                
                    // Replace current member with reference to new rule
                    member = TreeAPI::RuleMember { .value = TreeAPI::RuleMemberName {quant_fullname} };
                
                    std::vector<std::vector<TreeAPI::RuleMember>> new_alts;
                
                    switch (member.quantifier) {
                        case '?':
                            new_alts.push_back({}); // empty
                            new_alts.push_back(data);
                            break;
                
                        case '+': {
                            // + = A A*
                            std::string tail_name = quant_rule_name + "_tail";
                            auto tail_fullname = quant_fullname;
                            tail_fullname.back() = tail_name;
                
                            // A → data tail
                            auto base = data;
                            base.push_back(TreeAPI::RuleMember { .value = TreeAPI::RuleMemberName {tail_fullname} });
                            new_alts.push_back(base);
                
                            // A* tail: ε | data tail
                            std::vector<std::vector<TreeAPI::RuleMember>> tail_alts;
                            tail_alts.push_back({});
                            auto recur = data;
                            recur.push_back(TreeAPI::RuleMember { .value = TreeAPI::RuleMemberName {tail_fullname} });
                            tail_alts.push_back(recur);
                
                            for (auto &alt : tail_alts)
                                initial_item_set[tail_fullname].push_back(TreeAPI::Rule {alt});
                            break;
                        }
                
                        case '*': {
                            // * = ε | data A*
                            new_alts.push_back({});
                            auto recur = data;
                            recur.push_back(TreeAPI::RuleMember { .value = TreeAPI::RuleMemberName {quant_fullname} });
                            new_alts.push_back(recur);
                            break;
                        }
                    }
                
                    for (auto &alt : new_alts) {
                        initial_item_set[quant_fullname].push_back(TreeAPI::Rule {alt});
                    }

                    continue;
                } else if (member.isOp()) {
       
                    auto &data = member.getOp();
        
                    std::vector<std::string> push_name;
                    std::vector<TreeAPI::RuleMember>::iterator val_it;
                    std::vector<std::pair<size_t, size_t>> group_pos = {};
                    size_t _count = 0;
                    if (members.size() == 1) {
                        size_t count = 0;
                        bool is_first_going_group = false;
                
                        for (const auto &rule : data) {
                            if (rule.isGroup() && rule.quantifier != '\0') {
                                if (count == 0)
                                    is_first_going_group = true;
                
                                auto len = compute_group_length(rule.getGroup());
                                group_pos.push_back({count, len});
                                count += len;
                                continue;
                            }
                            count++;
                        }        
                        transform_helper(data, fullname, replacements); // process internal ops/groups
                        if (is_first_going_group) {
                            auto [pos, len] = group_pos[0];
                            group_pos.erase(group_pos.begin());
                
                            members.erase(members.begin() + i);
                            size_t j = 0;
                            for (; j < len; j++, val_it++, _count++) {
                                members.insert(members.begin() + i + j, *val_it);
                            }
                            val_it = data.begin() + j;
                        } else {
                            members[i] = data[0];
                            val_it = data.begin() + 1;
                            _count++;
                        }
                
                        push_name = fullname;
                    } else {
                        std::string name ="__rop" + std::to_string(i);
                        auto new_fullname = fullname;
                        new_fullname.back() = name;
                        push_name = new_fullname;
                        members[i] = TreeAPI::RuleMember {.value = TreeAPI::RuleMemberName {new_fullname}};
                
                        transform_helper(data, fullname, replacements); // process internal ops/groups
                        val_it = data.begin();
                    }
                    for (; val_it != data.end(); val_it++, _count++) {
                        auto group = std::find_if(group_pos.begin(), group_pos.end(), [&_count](const std::pair<size_t, size_t> &unit) {return unit.first == _count;});
                        std::vector<TreeAPI::RuleMember> values;
                        if (group != group_pos.end()) {
                            for (size_t i = 0; i < group->second && val_it != data.end(); i++, _count++, val_it++) {
                                values.push_back(*val_it);
                            }
                            val_it--;
                            _count--;
                        } else values.push_back(*val_it);
                        initial_item_set[push_name].push_back(TreeAPI::Rule {values});
                    }
                    continue;
                }
            }
            if (member.quantifier == '\0')
                continue;
            auto find = replacements.find(fullname);
            if (find != replacements.end()) {
                if (find->second.first == member.quantifier) {
                    members[i] = TreeAPI::RuleMember {.value = TreeAPI::RuleMemberName {find->second.second}};
                    continue;
                }
                
            }
            // Quantifier handling
            std::string quant_rule_name;
            auto new_fullname = fullname;
            if (fullname.size() == 1) {
                quant_rule_name = fullname.back() + "__q" + std::to_string(i);
            } else {
                quant_rule_name = "__q" + std::to_string(i);
            }
            new_fullname.back() = quant_rule_name;
            // Replace with reference to new quant rule
            members[i].value = TreeAPI::RuleMemberName {new_fullname};
            std::vector<std::vector<TreeAPI::RuleMember>> new_alternatives;

            if (member.quantifier == '?') {
                new_alternatives.push_back({});
                new_alternatives.push_back({member});
            }
            else if (member.quantifier == '+') {
                std::string recurse_name = quant_rule_name + "_tail";
                auto recurse_fullname = new_fullname;
                recurse_fullname.back() = recurse_name;
                
                new_alternatives.push_back({
                    member,
                    TreeAPI::RuleMember{.value = TreeAPI::RuleMemberName{recurse_fullname}}
                });
                
                std::vector<std::vector<TreeAPI::RuleMember>> recurse_alternatives = {
                    {},
                    {
                        member,
                        TreeAPI::RuleMember{.value = TreeAPI::RuleMemberName{recurse_fullname}}
                    }
                };
                
                for (auto &alt : recurse_alternatives) {
                    initial_item_set[recurse_fullname].push_back(TreeAPI::Rule{alt});
                }
                
            } else if (member.quantifier == '*') {
                std::string recurse_name = quant_rule_name + "_tail";
                auto recurse_fullname = new_fullname;
                recurse_fullname.back() = recurse_name;
            
                new_alternatives.push_back({}); // ε
                new_alternatives.push_back({
                    member,
                    TreeAPI::RuleMember{.value = TreeAPI::RuleMemberName{recurse_fullname}}
                });
            
                std::vector<std::vector<TreeAPI::RuleMember>> recurse_alternatives = {
                    {},
                    {
                        member,
                        TreeAPI::RuleMember{.value = TreeAPI::RuleMemberName{recurse_fullname}}
                    }
                };
            
                for (auto &alt : recurse_alternatives) {
                    initial_item_set[recurse_fullname].push_back(TreeAPI::Rule{alt});
                }
            }

            for (auto &alt : new_alternatives) {
                initial_item_set[new_fullname].push_back(TreeAPI::Rule{alt});
            }
            replacements[fullname] = {member.quantifier, new_fullname};
        }
    }
}

void LRParser::transform() {
    size_t size = initial_item_set.size();
    std::unordered_map<std::vector<std::string>, std::pair<char, std::vector<std::string>>> replacement;
    for (auto &[name, value] : initial_item_set) {
        transform_helper(value[0].members, name, replacement);
    }
}
void LRParser::getPriorityTree(const std::vector<TreeAPI::Rule> *rule, std::unordered_set<std::vector<std::string>> &visited, size_t depth) {
    for (const auto &r : *rule) {
        // Avoid re-expansion of already visited rules
        if (!corelib::text::isLower(r.members.name) || visited.count(r.fullname))
            continue;

        // Assign priority if not yet assigned
        if (priority.find(r.fullname) == priority.end()) {
            priority[r.fullname] = depth;
        }

        visited.insert(r.fullname);

        // Recurse into rule alternatives
        auto it = initial_item_set.find(r.fullname);
        if (it != initial_item_set.end()) {
            for (const auto &subrule : it->second) {
                getPriorityTree(&subrule, visited, depth + 1);
            }
        }
    }
}

void LRParser::getPriorityTree() {
    std::unordered_set<std::vector<std::string>> visited;

    auto it = initial_item_set.find({"main"});
    if (it != initial_item_set.end()) {
        for (const auto &r : it->second) {
            getPriorityTree(&r, visited, 0);
        }
    } else {
        throw Error("No main rule found");
    }
}

void LRParser::addAugmentedRule() {
    initial_item_set[{"__start"}] = TreeAPI::Rule { TreeAPI::RuleMember {.value = TreeAPI::RuleMemberName {{"main"}}}};
}
void LRParser::constructFirstSet(const std::vector<TreeAPI::Rule>& options, const std::vector<std::string> &nonterminal, bool &changed) {
    for (const auto &option : options) {
        bool nullable_prefix = true;
        for (const auto &member : option.members) {
            if (!member.isName())
                throw Error("Non-RuleMemberName class");
            const auto &rule = member.getName();
            auto &currentFirst = first[nonterminal];
            if (rule.name == nonterminal) {
                continue;
            }
            if (corelib::text::isLower(rule.name)) {
                // Nonterminal: take FIRST(rule.fullname)
                // cpuf::printf("[nonterminal %$] ", rule.fullname);
                auto find = first.find(rule.name);
                const auto &otherFirst = first[rule.name];
                // cpuf::printf("FIRST(%$) = ", rule.fullname);
                for (const auto& el : otherFirst) {
                    // cpuf::printf("%$, ", el);
                }
                auto currentFirst_size = currentFirst.size();
                currentFirst.insert(otherFirst.begin(), otherFirst.end());
                if (currentFirst_size > currentFirst.size()) {
                    changed = true;
                    // cpuf::printf("(changed), ");
                } else {
                    // cpuf::printf("(not changed), ");
                }
                // Check if nullable
                bool isNullable = false;
                auto &rules = initial_item_set[rule.name];
                for (const auto &r : rules) {
                    bool break_this = false;
                    for (const auto &member : r.members) {
                        if (member.empty()) {
                            isNullable = true;
                            break_this = true;
                            break;
                        }
                    }
                    if (break_this)
                        break;
                }

                if (!isNullable) {
                    nullable_prefix = false;
                    break;
                }

            } else {
                // Terminal: add directly
                // cpuf::printf("[terminal %$] ", rule.fullname);
                if (first[nonterminal].insert(rule.name).second) {
                    // cpuf::printf("(added), ");
                    changed = true;
                }

                nullable_prefix = false;
                break;
            }
        }
        // cpuf::printf("\n");
        // If all symbols in this production were nullable
        if (nullable_prefix) {
            if (first[nonterminal].insert({"ε"}).second)
                changed = true;
        }
    }
}
void LRParser::constructFirstSet() {
    bool changed;
    do {
        changed = false;
        for (const auto &[nonterminal, productions] : initial_item_set) {
            // cpuf::printf("constructing first set for %$ -> ", nonterminal);
            constructFirstSet(productions, nonterminal, changed);
        }
    } while (changed);
}

void LRParser::constructFollowSet() {
    follow[{"__start"}] = {{"$"}};
    bool hasChanges;
    bool prevDependedChanged;
    std::vector<std::vector<std::string>> prev_depend;
    std::vector<std::vector<std::string>> changed;
    do {
        hasChanges = false;
        prevDependedChanged = false;
        prev_depend.clear();
        changed.clear();
        for (const auto &[name, options] : initial_item_set) {
            bool is_left_recursive = false;
            for (const auto &rules : options) {
                if (!rules.members[0].isName())
                    throw Error("Not RuleMemberName");
                if (rules.members.size() > 0 && name == rules.members[0].getName().name) {
                    is_left_recursive = true;
                }
                for (auto it = rules.members.begin(); it != rules.members.end(); it++) {
                    if (!it->isName()) {
                        throw Error("Not RuleMemberName");
                    }
                    auto current = it->getName();

                    if (corelib::text::isUpper(current.name.back())) {
                        continue;
                    }
                    if (name == current.name) {
                        // include first(name)
                        auto f = first[name];
                        for (auto &e : f) {
                            if (e == std::vector<std::string>{"ε"}) {
                                continue;
                            }
                            if (follow[name].insert(e).second)
                                hasChanges = true;
                        }
                        prev_depend.push_back(name);
                    } else if (is_left_recursive && corelib::text::isLower(current.name.back())) {
                        auto prev_size = follow[current.name].size();
                        follow[current.name].insert(follow[name].begin(), follow[name].end());
                        if (prev_size != follow[current.name].size())
                            hasChanges = true;
                        prev_depend.push_back(current.name);
                    }
                    if (it + 1 == rules.members.end()) {
                        // Add FOLLOW of LHS (the left-hand-side nonterminal)
                        auto &f_lhs = follow[name];
                        for (auto &sym : f_lhs) {
                            if (follow[current.name].insert(sym).second)
                                hasChanges = true;
                        }
                    } else {
                        auto next = (it + 1)->getName();
                        if (corelib::text::isUpper(next.name.back())) {
                            // terminal, just push
                            if (follow[current.name].insert(next.name).second)
                                hasChanges = true;
                        } else {
                            // non-terminal, insert it's first
                            auto f = first[next.name];
                            bool has_epsilon = false;
                            for (auto &e : f) {
                                if (e == std::vector<std::string>{"ε"}) {
                                    has_epsilon = true;
                                    continue;
                                }
                                if (follow[current.name].insert(e).second)
                                    hasChanges = true;
                            }
                            if (has_epsilon) {
                                // if ε in FIRST(next), add FOLLOW of LHS
                                auto &f_lhs = follow[name];
                                for (auto &sym : f_lhs) {
                                    if (follow[current.name].insert(sym).second)
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
            for (auto change_symbol : changed) {
                if (std::find(prev_depend.begin(), prev_depend.end(), change_symbol) != prev_depend.end()) {
                    prevDependedChanged = true;
                    break;
                }
            }
        }
    } while(hasChanges || prevDependedChanged);
}
void LRParser::compute_cci_lookahead(const std::vector<rule_other> &rhs_group, const std::vector<std::string> &lhs_name, LR1Core &new_item) {
    size_t next_pos = new_item.dot_pos + 1;
    // cpuf::printf("computing lookahead for %$ -> ", lhs_name);
    if (rhs_group.empty() || next_pos >= rhs_group.size()) {
        // end of rule, compute lookahead of follow(current)
        auto &lookahead = follow[lhs_name];
        new_item.lookahead.insert(lookahead.begin(), lookahead.end());
        return;
    }
    // check whether next symbol is terminal or non-terminal
    bool epsilon_in_all = true;
    for (size_t i = next_pos; i < rhs_group.size(); i++) {
        auto &symbol = rhs_group[i];
        if (corelib::text::isUpper(symbol.name)) {
            // terminal
            // cpuf::printf("[terminal] %$", symbol.fullname);
            new_item.lookahead.insert(symbol.fullname);
            epsilon_in_all = false;
            break;
        } else {
            // non-terminal, insert FIRST of next symbol
            auto &first_set = first[symbol.fullname];
            bool has_espsilon = false;
            // cpuf::printf("[non-terminal %$] ", symbol.fullname);
            for (const auto& el : first_set) {
                if (el == std::vector<std::string>{"ε"}) {
                    has_espsilon = true;
                    continue;
                }
                // cpuf::printf("%$, ", el);
                new_item.lookahead.insert(el);
            }
        }
    }
    // If all symbols after dot can derive ε, add FOLLOW(lhs)
    if (epsilon_in_all) {
        const auto& follow_set = follow[lhs_name];
        new_item.lookahead.insert(follow_set.begin(), follow_set.end());
    }
    // for (auto el : new_item.lookahead) {
    //     cpuf::printf("%$, ", el);
    // }
    // cpuf::printf("\n");
}
void LRParser::create_item_collection(CanonicalItem &closure, const ItemSet &item, const std::vector<std::string> &lhs_name) {
    for (const auto& rhs_group : item) {
        LR1Core new_item;
        // Create LHS rule_other
        rule_other lhs;
        lhs.name = lhs_name.back();  // Use last component as rule name
        lhs.fullname = lhs_name;

        new_item.lhs = lhs;
        new_item.rhs = rhs_group;
        new_item.dot_pos = 0;
        if (closure.find(new_item) != closure.end())
            continue;
        compute_cci_lookahead(rhs_group, lhs_name, new_item);
        // Avoid duplicate

        closure.insert(new_item);

        // If rule is epsilon, no need to recurse further
        if (rhs_group.empty()) {
            continue;
        }

        // Expand first symbol if it's non-terminal
        const auto& sym = rhs_group[0];
        if (corelib::text::isLower(sym.name)) {
            auto rule = initial_item_set.find(sym.fullname);
            if (rule != initial_item_set.end()) {
                create_item_collection(closure, rule->second, sym.fullname);
            }
        }
    }
}


LRParser::CanonicalItemSet LRParser::construct_cannonical_collections_of_items() {
    CanonicalItemSet cci;

    auto begin_rule = initial_item_set.find({"__start"});
    if (begin_rule == initial_item_set.end()) {
        throw Error("No augmented rule\n");
    }

    CanonicalItem I0;
    create_item_collection(I0, begin_rule->second, begin_rule->first);
    cci.push_back(I0);

    std::queue<CanonicalItem> worklist;
    worklist.push(I0);

    while (!worklist.empty()) {
        CanonicalItem current = worklist.front();
        worklist.pop();

        // You likely need to aggregate per symbol with a merged lookahead set
        std::unordered_map<std::vector<std::string>, CanonicalItem> transitions;

        for (const auto& item : current) {
            if (item.dot_pos < item.rhs.size()) {
                const auto& sym = item.rhs[item.dot_pos].fullname;

                LR1Core advanced = item;
                advanced.dot_pos++;
                compute_cci_lookahead(advanced.rhs, advanced.lhs.fullname, advanced);

                // Merge item into the transition set for this symbol
                auto& itemset = transitions[sym];

                // If an identical core+dot_pos exists but with different lookahead, merge
                bool found = false;
                for (auto& e : itemset) {
                    if (e.lhs == advanced.lhs && e.rhs == advanced.rhs && e.dot_pos == advanced.dot_pos) {
                        e.lookahead.insert(advanced.lookahead.begin(), advanced.lookahead.end());
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    itemset.insert(advanced);
                }
            }
        }


        for (auto& [sym, items] : transitions) {
            CanonicalItem closure = items;

            for (const auto& el : items) {
                if (el.dot_pos < el.rhs.size()) {
                    const auto& sym_rhs = el.rhs[el.dot_pos];
                    if (corelib::text::isLower(sym_rhs.name)) {
                        auto rule = initial_item_set.find(sym_rhs.fullname);
                        if (rule != initial_item_set.end()) {
                            create_item_collection(closure, rule->second, sym_rhs.fullname);
                        }
                    }
                }
            }

            if (std::find(cci.begin(), cci.end(), closure) == cci.end()) {
                cci.push_back(closure);
                worklist.push(closure);
            }
        }
    }

    return cci;
}


size_t LRParser::find_goto_state(const CanonicalItem &item_set, const rule_other &symbol) {
    CanonicalItem next_state;

    // Step 1: Shift dot over symbol where possible
    for (const auto &item : item_set) {
        if (item.dot_pos < item.rhs.size() && item.rhs[item.dot_pos] == symbol) {
            LR1Core shifted = item;
            shifted.dot_pos++;
            next_state.insert(shifted);
        }
    }
    CanonicalItem closure = next_state;
    // Step 2: Compute closure of this new state
    for (const auto &item : next_state) {
        if (item.dot_pos < item.rhs.size()) {
            const auto &next_sym = item.rhs[item.dot_pos];
            if (corelib::text::isLower(next_sym.name)) {
                // Non-terminal → expand it
                auto rule = initial_item_set.find(next_sym.fullname);
                if (rule != initial_item_set.end()) {
                    create_item_collection(closure, rule->second, rule->first);
                }
            }
        }
    }


    // Step 3: Check if this closure already exists in canonical set
    auto it = std::find(canonical_item_set.begin(), canonical_item_set.end(), closure);
    if (it != canonical_item_set.end()) {
        return std::distance(canonical_item_set.begin(), it);
    }

    // Step 4: If not, add it (only do this if building dynamically — otherwise error)
    throw Error("GOTO leads to non-existent state. Should be precomputed.");
}
size_t LRParser::find_rules_index(const LR1Core &rule) {
    size_t reduce_index;
    auto found_rhs = std::find_if(rules.begin(), rules.end(), [&rule](const Rules_part &el) {
        if (rule.lhs.fullname != el.first)
            return false;
        auto &rhs = el.second.second;
        if (rhs.size() != rule.rhs.size())
            return false;
        for (size_t i = 0; i < rhs.size(); i++) {
            if (rhs[i].fullname != rule.rhs[i].fullname) 
                return false;
        }
        return true;
    });
    if (found_rhs != rules.end()) {
        reduce_index = found_rhs - rules.begin();
    } else {
        rules.push_back(Rules_part {rule.lhs.fullname, {rule.rhs.size(), rule.rhs}});
        reduce_index = rules.size() - 1;
    }
    return reduce_index;
}
bool isInUsePlace(const Tree::UsePlaceTable &use_places, const std::vector<std::string> &first, const std::vector<std::string> &second, std::unordered_set<std::vector<std::string>> &checked) {
    checked.insert(first);
    auto find_it = use_places.find(first);
    if (find_it == use_places.end())
        return false;
    const auto &[name, used_nonterminals] = *find_it;
    for (auto [place, nonterminal] : used_nonterminals) {
        if (nonterminal == second) {
            return true;
        } else if (checked.count(nonterminal) == 0 && isInUsePlace(use_places, nonterminal, second, checked)) {
            return true;
        }
    }
    return false;
}
void LRParser::resolveCertainConflict(const Conflict &conflict) {
    auto &[item, place, conflicts, state] = conflict;
    const Action* shift_place = nullptr;
    bool reduce_conflict = false;
    for (const auto &conflict : conflicts) {
        if (conflict.type == Action_type::SHIFT)
            shift_place = &conflict;
        else if (conflict.type == Action_type::REDUCE) 
            reduce_conflict = true;
    }
    if (shift_place != nullptr && reduce_conflict) {
        // SHIFT/REDUCE conflict, prefer shift
        *place = *shift_place;
        return;
    }
    // resolve reduce/reduce conflict statically
    // build small nested table
    if (conflict.conflicts.size() > 2)
        throw Error("Parser is unable to resolve 3 or more reduce/reduce conflicts\n");
    const auto &first = item[0];
    const auto &second = item[1];
    if (!first.rhs.empty() && second.rhs.empty()) {
        *place = conflicts[0];
    } else if (first.rhs.empty() && !second.rhs.empty()) {
        *place = conflicts[1];
    } else if (first.rhs.empty() && second.rhs.empty()) {
        throw Error("REDUCE/REDUCE conflict for two epsilon rules");
    }
    std::unordered_set<std::vector<std::string>> checked;
    // check whether second rule is nested in first
    if (isInUsePlace(use_places, first.lhs.fullname, second.lhs.fullname, checked)) {
        *place = conflicts[0];
    } else {
        checked.clear();
        if (isInUsePlace(use_places, second.lhs.fullname, first.lhs.fullname, checked)) {
            *place = conflicts[1];
        } else {
            // both rules are not relative, use deepth
            if (priority[first.lhs.fullname] > priority[second.lhs.fullname]) {
                *place = conflicts[0];
            } else {
                *place = conflicts[1];
            }
        }
    }
}
void LRParser::resolveConflictsStatically() {
    for (const auto &conflict : conflicts) {
        resolveCertainConflict(conflict);
    }
}
void LRParser::buildTable() {
    size_t I = 0;
    for (const auto& item_set : canonical_item_set) {
        const LR1Core* prev_rule = nullptr;
        Action* prev_action = nullptr;
        for (const auto& rule : item_set) {
            // cpuf::printf("I%$: %$ → ", I, rule.lhs.fullname);
            // for (size_t j = 0; j < rule.rhs.size(); ++j) {
            //     if (j == rule.dot_pos) {
            //         cpuf::printf("• ");
            //     }
            //     cpuf::printf("%$, ", rule.rhs[j].fullname);
            // }
            // if (rule.dot_pos == rule.rhs.size()) {
            //     cpuf::printf("• ");
            // }
            // cpuf::printf("  lookahead: ");
            // for (const auto& lookahead : rule.lookahead) {
            //     cpuf::printf("%$, ", lookahead);
            // }
            // cpuf::printf("\n");

            if (rule.rhs.size() == 1 && rule.lhs.fullname == rule.rhs[0].fullname) {
                // cpuf::printf("skipping %$ -> %$\n", rule.lhs.fullname, rule.rhs[0].fullname);
                continue;
            }
            // Dot is at the end → Reduce or Accept
            if (rule.dot_pos >= rule.rhs.size()) {
                // Accept condition: augmented rule with start symbol
                if (rule.lhs.name == "__start" && rule.rhs.size() == 1) {
                    action_table[I][{"$"}] = Action{Action_type::ACCEPT, 0};
                    continue;
                }

                // Reduce: only insert reduce if no conflicting shift action exists
                // Use the lookahead token for LR(1)
                // cpuf::printf("Got lookahead for %$ -> ", rule.lhs.fullname);
                for (auto lookahead : rule.lookahead) {
                    if (action_table[I].count(lookahead) == 0) {
                        // No existing shift, safe to reduce
                        action_table[I][lookahead] = Action{Action_type::REDUCE, find_rules_index(rule)};
                    } else {
                        const auto& existing = action_table[I][lookahead];
                        auto rules_index = find_rules_index(rule);
                        if (existing.type != Action_type::REDUCE || existing.state != rules_index) {
                            // Always include the current action and the one already in the action table
                            Conflict new_conflict;
                            if (prev_rule) {
                                new_conflict.item.push_back(*prev_rule);
                            }
                            new_conflict.item.push_back(rule);
                            new_conflict.place = &action_table[I][lookahead];

                            // Add the existing action in the action table as a conflict
                            const auto& existing = action_table[I][lookahead];
                            new_conflict.conflicts.push_back(existing);

                            // Add the current action
                            new_conflict.conflicts.push_back(Action{Action_type::REDUCE, rules_index});
                            new_conflict.state = I;

                            // Check if this conflict already exists
                            auto find_it = std::find_if(conflicts.begin(), conflicts.end(), [&I, &lookahead, this](const Conflict &c) {
                                return c.state == I && c.place == &action_table[I].at(lookahead);
                            });

                            if (find_it != conflicts.end()) {
                                // Add the current rule to the existing conflict
                                find_it->item.push_back(rule);
                                find_it->conflicts.push_back(Action{Action_type::REDUCE, find_rules_index(rule)});
                            } else {
                                // Add a new conflict
                                conflicts.push_back(new_conflict);
                            }
                        }
                        
                    }
                }
                // cpuf::printf("\n");
            } else { // Dot is before a symbol
                const auto& next = rule.rhs[rule.dot_pos];
                size_t next_state = find_goto_state(item_set, next); // goto(I, X)
                if (corelib::text::isUpper(next.name)) {
                    // Terminal → SHIFT (unconditionally)
                    if (action_table[I].count(next.fullname) == 0) {
                        action_table[I][next.fullname] = Action{Action_type::SHIFT, next_state};
                    } else {
                        const auto& existing = action_table[I][next.fullname];
                        if (existing.type != Action_type::SHIFT || existing.state != next_state) {
                            // Avoid duplicate SHIFT actions
                            Conflict new_conflict;
                            if (prev_rule) {
                                new_conflict.item.push_back(*prev_rule);
                            }
                            new_conflict.item.push_back(rule);
                            new_conflict.place = &action_table[I][next.fullname];

                            // Add the existing action in the action table as a conflict
                            new_conflict.conflicts.push_back(existing);

                            // Add the current action
                            new_conflict.conflicts.push_back(Action{Action_type::SHIFT, next_state});
                            new_conflict.state = I;

                            // Check if this conflict already exists
                            auto find_it = std::find_if(conflicts.begin(), conflicts.end(), [&I, &next, this](const Conflict &c) {
                                return c.state == I && c.place == &action_table[I].at(next.fullname);
                            });

                            if (find_it != conflicts.end()) {
                                // Add the current rule to the existing conflict
                                find_it->item.push_back(rule);
                                find_it->conflicts.push_back(Action{Action_type::SHIFT, next_state});
                            } else {
                                // Add a new conflict
                                conflicts.push_back(new_conflict);
                            }
                        }

                        
                    }
                    prev_action = &action_table[I][next.fullname];
                } else {// Non-terminal → GOTO
                    goto_table[I][next.fullname] = next_state;
                }
            }
            prev_rule = &rule;
        }
        I++;
    }

    for (auto &conflict : conflicts) {
        cpuf::printf("Conflict in state %$:", conflict.state);
        for (auto conf : conflict.conflicts) {
            cpuf::printf("[%$ %$]", LRParser::ActionTypeToString(conf.type), conf.state, conflict.item.size());
        }
        cpuf::printf("\n");
    }
}

void LRParser::prepare() {
    addAugmentedRule();
    use_places = tree->getUsePlacesTable();
    initial_item_set = construct_initial_item_set();
    getPriorityTree();
    constructFirstSet();
    constructFollowSet();
    canonical_item_set = construct_cannonical_collections_of_items();
}
void LRParser::build() {
    prepare();
    buildTable();
    resolveConflictsStatically();
}


void LRParser::formatFirstOrFollowSet(std::ostringstream &oss, First &set) {
    for (auto &el : set) {
        oss << corelib::text::join(el.first, "_") << ": " << '{';
        for (auto name : el.second) {
            oss << corelib::text::join(name, "_") << ", ";
        }
        oss << "}\n";
    }
}

void LRParser::printFirstSet(const std::string &fileName) {
    // Step 1: Print to std::ostringstream
    std::ostringstream oss;
    formatFirstOrFollowSet(oss, first);

    // Step 2: Output the stringstream content to a file
    std::ofstream outFile(fileName);
    if (outFile.is_open()) {
        outFile << oss.str();
        outFile.close();
    } else {
        std::cerr << "Failed to open the file for writing: " << fileName << "\n";
    }
}
void LRParser::printFollowSet(const std::string &fileName) {
    // Step 1: Print to std::ostringstream
    std::ostringstream oss;
    formatFirstOrFollowSet(oss, follow);

    // Step 2: Output the stringstream content to a file
    std::ofstream outFile(fileName);
    if (outFile.is_open()) {
        outFile << oss.str();
        outFile.close();
    } else {
        std::cerr << "Failed to open the file for writing: " << fileName << "\n";
    }
}
void LRParser::formatRulesTable(std::ostringstream& oss) {
    oss << "Rules:\n";
    for (const auto& rule : rules) {
        const auto& rule_name_parts = rule.first;
        const auto& lhs = corelib::text::join(rule_name_parts, "_");

        const size_t rule_index = rule.second.first;
        const auto& body = rule.second.second;

        oss << '\t' << rule_index << ": " << lhs << " → ";

        for (const auto& token : body) {
            oss << corelib::text::join(token.fullname, "_") << " ";
        }
        oss << '\n';
    }
}
void LRParser::formatCanonicalItemSet(std::ostringstream &oss) {
    size_t count = 0;
    for (const auto &item_set : canonical_item_set) {
        oss << "I" << count++ << ":\n";
        for (const auto &item : item_set) {
            // Print the LHS
            oss << '\t'
                << corelib::text::join(item.lhs.fullname, "_")
                << " → ";

            // Print RHS with dot position
            for (size_t i = 0; i <= item.rhs.size(); ++i) {
                if (i == item.dot_pos) {
                    oss << "• ";
                }
                if (i < item.rhs.size()) {
                    oss << corelib::text::join(item.rhs[i].fullname, "_") << ' ';
                }
            }
            oss << "; lookahead: {";
            for (auto el : item.lookahead) {
                oss << corelib::text::join(el, "_") << ", ";
            }
            oss << "}\n";
        }
        oss << "\n";
    }
}

void LRParser::printCanonicalCollection(const std::string &fileName) {
    // Step 1: Print to std::ostringstream
    std::ostringstream oss;
    formatCanonicalItemSet(oss);

    // Step 2: Output the stringstream content to a file
    std::ofstream outFile(fileName);
    if (outFile.is_open()) {
        outFile << oss.str();
        outFile.close();
    } else {
        std::cerr << "Failed to open the file for writing: " << fileName << "\n";
    }
}

// Helper function to format the Action Table into a string
#include <iomanip> // For std::setw

std::string LRParser::formatActionTable() const {
    std::ostringstream oss;
    const int stateWidth = 6;
    const int tokenWidth = 15;
    const int actionWidth = 10;
    const int nextStateWidth = 10;

    oss << "Action Table:\n";
    oss << std::left
        << std::setw(stateWidth) << "State"
        << std::setw(tokenWidth) << "Token"
        << std::setw(actionWidth) << "Action"
        << std::setw(nextStateWidth) << "Next State"
        << "\n";

    for (const auto& state_entry : action_table) {
        size_t state = state_entry.first;
        for (const auto& token_entry : state_entry.second) {
            const std::string& token = corelib::text::join(token_entry.first, "_");
            const Action& action = token_entry.second;

            std::string action_str = ActionTypeToString(action.type);

            oss << std::left
                << std::setw(stateWidth) << state
                << std::setw(tokenWidth) << token
                << std::setw(actionWidth) << action_str
                << std::setw(nextStateWidth) << action.state
                << "\n";
        }
    }
    return oss.str();
}

std::string LRParser::formatGotoTable() const {
    std::ostringstream oss;
    const int stateWidth = 6;
    const int nonTerminalWidth = 20;
    const int nextStateWidth = 12;

    oss << "Goto Table:\n";
    oss << std::left
        << std::setw(stateWidth) << "State"
        << std::setw(nonTerminalWidth) << "Non-Terminal"
        << std::setw(nextStateWidth) << "Next State"
        << "\n";

    for (const auto& state_entry : goto_table) {
        size_t state = state_entry.first;
        for (const auto& non_terminal_entry : state_entry.second) {
            const std::string& non_terminal = corelib::text::join(non_terminal_entry.first, "_");
            size_t next_state = non_terminal_entry.second;

            oss << std::left
                << std::setw(stateWidth) << state
                << std::setw(nonTerminalWidth) << non_terminal
                << std::setw(nextStateWidth) << next_state
                << "\n";
        }
    }
    return oss.str();
}

// Method to print both Action and Goto tables into a single file
void LRParser::printTables(const std::string& filename) {
    std::ofstream out_file(filename);

    if (!out_file.is_open()) {
        std::cerr << "Error opening file for writing tables.\n";
        return;
    }

    // Format the Action Table and Goto Table
    std::string action_table_str = formatActionTable();
    std::string goto_table_str = formatGotoTable();
    std::ostringstream out;
    formatRulesTable(out);

    // Write both tables to the file
    out_file << action_table_str << "\n" << goto_table_str << "\n" << out.str();

    out_file.close();
}