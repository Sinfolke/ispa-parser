#include <LRParser.h>
static size_t compute_group_length(const std::vector<Parser::Rule> &group) {
    size_t count = 0;
    for (auto &rule_rule : group) {
        Parser::Rule quantifier;
        auto rule = Tokens::getValueFromRule_rule(rule_rule, quantifier);
        if (rule.name == Parser::Rules::Rule_group && !quantifier.data.has_value()) {
            auto val = Tokens::getValueFromGroup(rule);
            count += compute_group_length(val);
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
auto LRParser::getTerminalNames(Parser::Tree &tree, std::vector<std::vector<std::string>> &names, std::vector<std::string> &fullname) const -> void {
    for (auto el : tree) {
        if (el.name != Parser::Rules::Rule)
            continue;

        auto data = std::any_cast<obj_t>(el.data);
        auto name = std::any_cast<Parser::Rule>(corelib::map::get(data, "name"));
        auto name_str = std::any_cast<std::string>(name.data);
        auto rules = std::any_cast<std::vector<Parser::Rule>>(corelib::map::get(data, "rule"));
        auto nested_rules = std::any_cast<std::vector<Parser::Rule>>(corelib::map::get(data, "nestedRules"));
        fullname.push_back(name_str);
        if (corelib::text::isUpper(name_str)) {
            names.push_back(fullname);
        }
        fullname.pop_back();
    }
}
auto LRParser::getTerminalNames() const ->  std::vector<std::vector<std::string>> {
    std::vector<std::vector<std::string>> names;
    std::vector<std::string> fullname;
    getTerminalNames(tree->getRawTree(), names, fullname);
    return names;
}
auto LRParser::getNonTerminalNames(Parser::Tree &tree, std::vector<std::vector<std::string>> &names, std::vector<std::string> &fullname) const -> void {
    for (auto el : tree) {
        if (el.name != Parser::Rules::Rule)
            continue;

        auto data = std::any_cast<obj_t>(el.data);
        auto name = std::any_cast<Parser::Rule>(corelib::map::get(data, "name"));
        auto name_str = std::any_cast<std::string>(name.data);
        auto rules = std::any_cast<std::vector<Parser::Rule>>(corelib::map::get(data, "rule"));
        auto nested_rules = std::any_cast<std::vector<Parser::Rule>>(corelib::map::get(data, "nestedRules"));
        fullname.push_back(name_str);
        if (corelib::text::isLower(name_str)) {
            names.push_back(fullname);
        }
        fullname.pop_back();
    }
}
auto LRParser::getNonTerminalNames() const ->  std::vector<std::vector<std::string>> {
    std::vector<std::vector<std::string>> names;
    std::vector<std::string> fullname;
    getNonTerminalNames(tree->getRawTree(), names, fullname);
    return names;
}
auto LRParser::ActionTypeToString(const Action_type &type) -> std::string {
    switch (type) {
        case Action_type::SHIFT:
            return "SHIFT";
        case Action_type::REDUCE:
            return "REDUCE";
        case Action_type::ERROR:
            return "ERROR";
        case Action_type::ACCEPT:
            return "ACCEPT";
    }
    throw Error("Undefined action type");
}
void LRParser::transform_helper(Parser::Tree &tree, std::vector<Parser::Rule> &rules, std::vector<std::string> &fullname, std::unordered_map<std::vector<std::string>, std::pair<char, rule_other>, VectorHash> &replacements) {
    for (size_t i = 0; i < rules.size(); i++) {
        auto &rule_rule = rules[i];
        Parser::Rule quantifier;
        char quantifier_char = '\0';
        auto rule = Tokens::getValueFromRule_rule(rule_rule, quantifier);
        if (quantifier.data.has_value()) {
            quantifier_char = std::any_cast<char>(quantifier.data);
        }

        switch (rule.name) {
        case Parser::Rules::Rule_group:
        {
            auto val = Tokens::getValueFromGroup(rule);

            // Recursively process the group
            transform_helper(tree, val, fullname, replacements);
            // If only one rule, inline it
            if (val.size() == 1) {
                rules[i] = val[0];
                continue;
            }

            if (quantifier_char == '\0') {
                // Replace current rule with expanded group
                cpuf::printf("inlining group\n");
                rules.erase(rules.begin() + i);
                rules.insert(rules.begin() + i, val.begin(), val.end());
                i += val.size() - 2;
                continue;
            }
            std::string quant_rule_name = "__grp" + std::to_string(i);
            auto new_fullname = fullname;
            new_fullname.back() = quant_rule_name;
            // Replace with reference to new quant rule
            rules[i] = Tokens::make_rule(Parser::Rules::Rule_rule, obj_t {
                {"val", Tokens::make_rule(Parser::Rules::Rule_other, rule_other {quant_rule_name, new_fullname, true})},
                {"qualifier", Parser::Rule()}
            });

            std::vector<std::vector<Parser::Rule>> new_alternatives;
            switch (quantifier_char) {
                case '?':
                    new_alternatives.push_back({Parser::Rule()});
                    new_alternatives.push_back(val);
                    break;
                case '+':
                {
                    // create A
                    std::string recurse_name = quant_rule_name + "_tail";
                    new_fullname.back() = quant_rule_name;
                    for (auto el : val) {
                        new_alternatives.push_back(val);
                    }
                    new_alternatives.back().push_back({
                        Tokens::make_rule(Parser::Rules::Rule_rule, obj_t {
                            {"val", Tokens::make_rule(Parser::Rules::Rule_other, rule_other {recurse_name, new_fullname, true})},
                            {"qualifier", Parser::Rule()}
                        })
                    });
                    // create A*
                    std::vector<std::vector<Parser::Rule>> recurse_alternatives;
                    recurse_alternatives.push_back({Parser::Rule()});
                    recurse_alternatives.push_back(val);
                    recurse_alternatives.back().push_back({
                        Tokens::make_rule(Parser::Rules::Rule_rule, obj_t {
                            {"val", Tokens::make_rule(Parser::Rules::Rule_other, rule_other {recurse_name, new_fullname, true})},
                            {"qualifier", Parser::Rule()}
                        })
                    });
                    for (auto &alt : recurse_alternatives) {
                        tree.push_back(Tokens::make_rule(Parser::Rules::Rule, obj_t {
                            {"name", Tokens::make_rule(Parser::Rules::id, recurse_name)},
                            {"rule", alt},
                            {"nestedRules", std::vector<Parser::Rule>{}},
                            {"data_block", Parser::Rule {}}
                        }));
                    }

                    break;
                }
                case '*':
                    new_alternatives.push_back({Parser::Rule()});
                    new_alternatives.push_back(val);
                    new_alternatives.back().push_back(
                        Tokens::make_rule(Parser::Rules::Rule_rule, obj_t {
                            {"val", Tokens::make_rule(Parser::Rules::Rule_other, rule_other {quant_rule_name, new_fullname, true})},
                            {"qualifier", Parser::Rule()}
                        })
                    );
            }
            for (auto &alt : new_alternatives) {
                tree.push_back(Tokens::make_rule(Parser::Rules::Rule, obj_t {
                    {"name", Tokens::make_rule(Parser::Rules::id, quant_rule_name)},
                    {"rule", alt},
                    {"nestedRules", std::vector<Parser::Rule>{}},
                    {"data_block", Parser::Rule {}}
                }));
            }
            continue;
        }
        case Parser::Rules::Rule_op:
        {
            cpuf::printf("Replacing rule_op\n");
        
            auto val = std::any_cast<std::vector<Parser::Rule>>(rule.data);
        
            std::string push_name;
            std::vector<Parser::Rule>::iterator val_it;
            std::vector<std::pair<size_t, size_t>> group_pos = {};
            size_t _count = 0;
            if (rules.size() == 1) {
                size_t count = 0;
                bool is_first_group = false;
        
                for (auto rule_rule : val) {
                    Parser::Rule quantifier;
                    auto rule = Tokens::getValueFromRule_rule(rule_rule, quantifier);
                    if (rule.name == Parser::Rules::Rule_group && quantifier.empty()) {
                        if (count == 0)
                            is_first_group = true;
        
                        auto group_val = Tokens::getValueFromGroup(rule);
                        auto len = compute_group_length(group_val);
                        group_pos.push_back({count, len});
                        count += len;
                        continue;
                    }
                    count++;
                }        
                transform_helper(tree, val, fullname, replacements); // process internal ops/groups
                val_it = val.begin();
                if (is_first_group) {
                    auto [pos, len] = group_pos[0];
                    group_pos.erase(group_pos.begin());
        
                    rules.erase(rules.begin() + i);
        
                    for (int j = 0; j < len; j++, val_it++, _count++) {
                        rules.insert(rules.begin() + i + j, *val_it);
                    }
                } else {
                    rules[i] = val[0];
                    val_it++;
                }
        
                push_name = fullname.back();
            } else {
                push_name = "__rop" + std::to_string(i);
                auto new_fullname = fullname;
                new_fullname.back() = push_name;
                
                rules[i] = Tokens::make_rule(Parser::Rules::Rule_rule, obj_t {
                    {"val", Tokens::make_rule(Parser::Rules::Rule_other, rule_other {push_name, new_fullname, true})},
                    {"qualifier", Parser::Rule()}
                });
        
                transform_helper(tree, val, fullname, replacements); // process internal ops/groups
                val_it = val.begin();
            }
            for (; val_it != val.end(); val_it++, _count++) {
                auto group = std::find_if(group_pos.begin(), group_pos.end(), [&_count](const std::pair<size_t, size_t> &unit) {return unit.first == _count;});
                std::vector<Parser::Rule> values;
                if (group != group_pos.end()) {
                    for (size_t i = 0; i < group->second && val_it != val.end(); i++, _count++, val_it++) {
                        values.push_back(*val_it);
                    }
                    val_it--;
                } else values.push_back(*val_it);
                tree.push_back(Tokens::make_rule(Parser::Rules::Rule, obj_t {
                    {"name", Tokens::make_rule(Parser::Rules::Rule_other, push_name)},
                    {"rule", values},
                    {"nestedRules", std::vector<Parser::Rule>{}},
                    {"data_block", Parser::Rule {}}
                }));
            }
            continue;
        }        
        default:
            break;
        }
        auto find = replacements.find(fullname);
        if (find != replacements.end()) {
            if (find->second.first == quantifier_char) {
                rules[i] = Tokens::make_rule(Parser::Rules::Rule_rule, obj_t {
                    {"val", Tokens::make_rule(Parser::Rules::Rule_other, rule_other {find->second.second.name, find->second.second.fullname, true})},
                    {"qualifier", Parser::Rule()}
                });
                continue;
            }
            
        }
        // Quantifier handling
        if (quantifier_char != '\0') {
            std::string quant_rule_name = "__q" + std::to_string(i);
            auto new_fullname = fullname;
            new_fullname.back() = quant_rule_name;
            // Replace with reference to new quant rule
            rules[i] = Tokens::make_rule(Parser::Rules::Rule_rule, obj_t {
                {"val", Tokens::make_rule(Parser::Rules::Rule_other, rule_other {quant_rule_name, new_fullname, true})},
                {"qualifier", Parser::Rule()}
            });

            std::vector<std::vector<Parser::Rule>> new_alternatives;

            if (quantifier_char == '?') {
                new_alternatives.push_back({Parser::Rule()});
                new_alternatives.push_back({
                    Tokens::make_rule(Parser::Rules::Rule_rule, obj_t {
                        {"val", rule},
                        {"qualifier", Parser::Rule()}
                    })
                });
            }
             else if (quantifier_char == '+') {
                std::string recurse_name = quant_rule_name + "_tail";
                new_fullname.back() = recurse_name;
                new_alternatives.push_back({
                    Tokens::make_rule(Parser::Rules::Rule_rule, obj_t {
                        {"val", rule},
                        {"qualifier", Parser::Rule()}
                    }),
                    Tokens::make_rule(Parser::Rules::Rule_rule, obj_t {
                        {"val", Tokens::make_rule(Parser::Rules::Rule_other, rule_other {recurse_name, new_fullname, true})},
                        {"qualifier", Parser::Rule()}
                    })
                });
                new_fullname.back() = quant_rule_name;
                std::vector<std::vector<Parser::Rule>> recurse_alternatives;
                recurse_alternatives.push_back({Parser::Rule()});
                recurse_alternatives.push_back({
                    Tokens::make_rule(Parser::Rules::Rule_rule, obj_t {
                        {"val", rule},
                        {"qualifier", Parser::Rule()}
                    }),
                    Tokens::make_rule(Parser::Rules::Rule_rule, obj_t {
                        {"val", Tokens::make_rule(Parser::Rules::Rule_other, rule_other {recurse_name, new_fullname, true})},
                        {"qualifier", Parser::Rule()}
                    })
                });
                for (auto &alt : recurse_alternatives) {
                    tree.push_back(Tokens::make_rule(Parser::Rules::Rule, obj_t {
                        {"name", Tokens::make_rule(Parser::Rules::id, recurse_name)},
                        {"rule", alt},
                        {"nestedRules", std::vector<Parser::Rule>{}},
                        {"data_block", Parser::Rule {}}
                    }));
                }

            } else if (quantifier_char == '*') {
                std::string recurse_name = quant_rule_name + "_tail";
                new_fullname.back() = recurse_name;
                // This is the initial entry point: optional ε and recursive call
                new_alternatives.push_back({Parser::Rule()}); // ε
                new_alternatives.push_back({
                    Tokens::make_rule(Parser::Rules::Rule_rule, obj_t {
                        {"val", Tokens::make_rule(Parser::Rules::Rule_other, rule_other {recurse_name, new_fullname, true})},
                        {"qualifier", Parser::Rule()}
                    })
                });
            
                // This is the recursive body: rule followed by recurse
                std::vector<std::vector<Parser::Rule>> recurse_alternatives;
                recurse_alternatives.push_back({
                    Tokens::make_rule(Parser::Rules::Rule_rule, obj_t {
                        {"val", rule},
                        {"qualifier", Parser::Rule()}
                    }),
                    Tokens::make_rule(Parser::Rules::Rule_rule, obj_t {
                        {"val", Tokens::make_rule(Parser::Rules::Rule_other, rule_other {recurse_name, new_fullname, true})},
                        {"qualifier", Parser::Rule()}
                    })
                });
                recurse_alternatives.push_back({Parser::Rule()}); // ε to allow termination
            
                for (auto &alt : recurse_alternatives) {
                    tree.push_back(Tokens::make_rule(Parser::Rules::Rule, obj_t {
                        {"name", Tokens::make_rule(Parser::Rules::id, recurse_name)},
                        {"rule", alt},
                        {"nestedRules", std::vector<Parser::Rule>{}},
                        {"data_block", Parser::Rule {}}
                    }));
                }
            }

            for (auto &alt : new_alternatives) {
                tree.push_back(Tokens::make_rule(Parser::Rules::Rule, obj_t {
                    {"name", Tokens::make_rule(Parser::Rules::id, quant_rule_name)},
                    {"rule", alt},
                    {"nestedRules", std::vector<Parser::Rule>{}},
                    {"data_block", Parser::Rule {}}
                }));
            }
            new_fullname.back() = quant_rule_name;
            replacements[fullname] = {quantifier_char, {quant_rule_name, new_fullname, true}};
        }
    }
}

void LRParser::transform(Parser::Tree &tree, std::vector<std::string> &fullname, std::unordered_map<std::vector<std::string>, std::pair<char, rule_other>, VectorHash> &replacements) {
    size_t size = tree.size();
    for (size_t i = 0; i < size; i++) {
        auto &member = tree[i];
        if (member.name != Parser::Rules::Rule)
            continue;
        if (!member.data.has_value()) {
            continue;
        }
        auto data = std::any_cast<obj_t&>(member.data);
        auto name = std::any_cast<Parser::Rule>(corelib::map::get(data, "name"));
        auto name_str = std::any_cast<std::string>(name.data);
        auto rules = std::any_cast<std::vector<Parser::Rule>&>(corelib::map::get(data, "rule"));
        auto nested_rules = std::any_cast<std::vector<Parser::Rule>&>(corelib::map::get(data, "nestedRules"));
        // do not include tokens
        if (corelib::text::isUpper(name_str))
            continue;
        fullname.push_back(name_str);
        transform_helper(tree, rules, fullname, replacements);
        transform(nested_rules, fullname, replacements);
        corelib::map::set(data, "rule", std::any(rules));
        corelib::map::set(data, "nestedRules", std::any(nested_rules));
        tree[i].data = data;
        fullname.pop_back();
    }
}
// void LRParser::debug(Parser::Tree &tree, std::vector<std::string> &fullname) {
//     size_t size = tree.size();
//     for (size_t i = 0; i < size; i++) {
//         auto &member = tree[i];
//         if (member.name != Parser::Rules::Rule)
//             continue;
//         if (!member.data.has_value()) {
//             continue;
//         }
//         auto data = std::any_cast<obj_t&>(member.data);
//         auto name = std::any_cast<Parser::Rule>(corelib::map::get(data, "name"));
//         auto name_str = std::any_cast<std::string>(name.data);
//         auto rules = std::any_cast<std::vector<Parser::Rule>&>(corelib::map::get(data, "rule"));
//         auto nested_rules = std::any_cast<std::vector<Parser::Rule>&>(corelib::map::get(data, "nestedRules"));
//         // do not include tokens
//         if (corelib::text::isUpper(name_str))
//             continue;
//         fullname.push_back(name_str);
//         cpuf::printf("%$: ", fullname);
//         for (auto rule_rule : rules) {
//             if (!rule_rule.data.has_value())
//                 continue;
//             auto rule = Tokens::getValueFromRule_rule(rule_rule);
//             if (rule.name != Parser::Rules::Rule_other) {
//                 cpuf::printf("<%s>", Parser::RulesToString(rule_rule.name));
//                 continue;
//             }
//             auto ro = std::any_cast<rule_other>(rule.data);
//             cpuf::printf("%$ ", ro.fullname);
//         }
//         cpuf::printf("\n");
//         debug(nested_rules, fullname);
//         fullname.pop_back();
//     }
// }
void LRParser::transform() {
    tree->removeEmptyRule();
    std::vector<std::string> fullname;
    std::unordered_map<std::vector<std::string>, std::pair<char, rule_other>, VectorHash> replacements;
    transform(tree->getRawTree(), fullname, replacements);
    // debug(tree->getRawTree(), fullname);
}

void LRParser::addAugmentedRule() {
    tree->getRawTree().push_back(Tokens::make_rule(Parser::Rules::Rule, obj_t {
        {"name", Tokens::make_rule(Parser::Rules::id, std::string("__start"))},
        {"rule", std::vector<Parser::Rule>{
                Tokens::make_rule(Parser::Rules::Rule_rule, obj_t {
                    {"val", Tokens::make_rule(Parser::Rules::Rule_other, rule_other {std::string("main"), {std::string("main")}})},
                    {"qualifier", Parser::Rule()}
                })
            }
        },
        {"nestedRules", std::vector<Parser::Rule> {}},
        {"data_block", Parser::Rule {}}
    }));
}
// since map cannot store std::vector<std::string> as key use std::vector<std::pair>
void LRParser::construct_initial_item_set(Parser::Tree &tree, InitialItemSet &initial_item_set, std::vector<std::string> &fullname) {
    for (auto &member : tree) {
        if (member.name != Parser::Rules::Rule)
            continue;
        auto data = std::any_cast<obj_t>(member.data);
        auto name = std::any_cast<Parser::Rule>(corelib::map::get(data, "name"));
        auto name_str = std::any_cast<std::string>(name.data);
        auto rules = std::any_cast<std::vector<Parser::Rule>>(corelib::map::get(data, "rule"));
        auto nested_rules = std::any_cast<std::vector<Parser::Rule>>(corelib::map::get(data, "nestedRules"));
        // do not include tokens
        if (corelib::text::isUpper(name_str))
            continue;
        fullname.push_back(name_str);
        std::vector<rule_other> item_set;
        for (auto rule : rules) {
            if (!rule.data.has_value())
                continue;
            auto arule = Tokens::getValueFromRule_rule(rule);
            if (!arule.data.has_value() || arule.name == Parser::Rules::Rule_escaped)
                continue;
            auto arule_data = std::any_cast<rule_other>(arule.data);
            item_set.push_back(arule_data);
        }
        auto find_it = initial_item_set.find(fullname);
        if (find_it == initial_item_set.end()) {
            initial_item_set[fullname] = {item_set};
        } else {
            find_it->second.push_back(item_set);
        }
        construct_initial_item_set(nested_rules, initial_item_set, fullname);
        fullname.pop_back();
    }
}
LRParser::InitialItemSet LRParser::construct_initial_item_set() {
    std::vector<std::string> fullname;
    InitialItemSet initial_item_set;
    construct_initial_item_set(tree->getRawTree(), initial_item_set, fullname);
    return initial_item_set;
}
void LRParser::constructFirstSet(const std::vector<std::vector<rule_other>>& options) {

    // Start with an initial assumption: all First sets are empty
    for (auto &option : options) {
        for (auto rule : option) {
            first[rule.fullname] = {};  // Initialize empty set for each rule
        }
    }

    bool changed;

    // Continue until no changes occur in the First sets
    do {
        changed = false;

        for (auto &option : options) {
            for (auto &rule : option) {
                auto &firstSetForRule = first[rule.fullname];

                if (corelib::text::isUpper(rule.name)) {
                    // Non-terminal: expand its First set
                    auto &nextSet = first[rule.fullname]; // First set of the current rule
                    size_t initialSize = firstSetForRule.size();

                    // Recursively add First set of the rule
                    firstSetForRule.insert(nextSet.begin(), nextSet.end());

                    // If the set size changed, mark that we need another iteration
                    if (firstSetForRule.size() > initialSize) {
                        changed = true;
                    }
                } else {
                    // Terminal: directly add to the First set
                    if (firstSetForRule.find(rule.fullname) == firstSetForRule.end()) {
                        firstSetForRule.insert(rule.fullname); // Add terminal
                        changed = true;
                    }
                }
            }
        }
    } while (changed);
}

void LRParser::constructFirstSet() {
    // Assuming initial_item_set is properly structured
    for (auto &el : initial_item_set) {
        auto name = el.first;
        auto itemSet = el.second;
        constructFirstSet(itemSet);  // Recurse through all initial items
    }
}
void LRParser::constructFollowSet() {
    follow[{"__start"}] = {{"$"}};
    bool hasChanges;
    do {
        hasChanges = false;
        for (auto &member : initial_item_set) {
            auto name = member.first;
            auto options = member.second;
            if (corelib::text::isUpper(name.back()))
                continue;
            for (auto rules : options) {
                for (auto it = rules.begin(); it != rules.end(); it++) {
                    auto current = *it;
                    if (it + 1 == rules.end()) {
                        if (follow[current.fullname].insert({"$"}).second) 
                            hasChanges = true;
                    } else {
                        auto next = *(it + 1);
                        if (corelib::text::isUpper(next.name)) {
                            // terminal, just push
                            if (follow[current.fullname].insert(next.fullname).second)
                                hasChanges = true;
                        } else {
                            // non-terminal, insert it's first
                            auto f = first[next.fullname];
                            bool has_epsilon = false;
                            for (auto &e : f) {
                                if (e == std::vector<std::string>{"ε"}) {
                                    has_epsilon = true;
                                    continue;
                                }
                                if (follow[current.fullname].insert(e).second)
                                    hasChanges = true;
                            }
                            if (has_epsilon) {
                                // if ε in FIRST(next), add FOLLOW of LHS
                                auto &f_lhs = follow[name];
                                for (auto &sym : f_lhs) {
                                    if (follow[current.fullname].insert(sym).second)
                                        hasChanges = true;
                                }
                            }
                        }
                    }
                }

            }
        }
    } while(hasChanges);
}

void LRParser::create_item_collection(CanonicalItem &closure, const ItemSet &item, const std::vector<std::string> &lhs_name) {
    for (const auto& rhs_group : item) {
        CanonicalEl new_item;
        // Create LHS rule_other
        rule_other lhs;
        lhs.name = lhs_name.back();  // Use last component as rule name
        lhs.fullname = lhs_name;

        new_item.lhs = lhs;
        new_item.rhs = rhs_group;
        new_item.dot_pos = 0;
        new_item.rule_index = rule_index++;

        // Avoid duplicate
        if (std::find(closure.begin(), closure.end(), new_item) != closure.end()) {
            continue;
        }

        closure.push_back(new_item);

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

        std::map<std::string, CanonicalItem> transitions;

        for (const auto& item : current) {
            if (item.dot_pos < item.rhs.size()) {
                const std::string& sym = item.rhs[item.dot_pos].name;
                CanonicalEl advanced = item;
                advanced.dot_pos++;
                transitions[sym].push_back(advanced);
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
            CanonicalEl shifted = item;
            shifted.dot_pos++;
            next_state.push_back(shifted);
        }
    }

    // Step 2: Compute closure of this new state
    CanonicalItem closure;
    for (const auto &item : next_state) {
        closure.push_back(item);
    }
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
    for (size_t i = 0; i < canonical_item_set.size(); ++i) {
        if (canonical_item_set[i] == closure) {
            return i;
        }
    }

    // Step 4: If not, add it (only do this if building dynamically — otherwise error)
    throw Error("GOTO leads to non-existent state. Should be precomputed.");
}
std::vector<std::string> LRParser::getLookaheadToken(const CanonicalEl& rule) {
    // Get the lookahead token after the dot
    if (rule.dot_pos < rule.rhs.size()) {
        const auto& next = rule.rhs[rule.dot_pos];
        if (corelib::text::isLower(next.name)) {
            // If it’s a terminal symbol
            return next.fullname;
        }
    }
    // If no valid lookahead token, return a default (e.g., "$")
    return {"$"};
}
void LRParser::build() {
    addAugmentedRule();
    initial_item_set = construct_initial_item_set();
    canonical_item_set = construct_cannonical_collections_of_items();
    rule_index = 0;
    constructFirstSet();
    constructFollowSet();
    size_t I = 0;

    for (const auto& item_set : canonical_item_set) {
        for (const auto& rule : item_set) {
            // Dot is at the end → Reduce or Accept
            if (rule.dot_pos >= rule.rhs.size()) {

                // Accept condition: augmented rule with start symbol
                if (rule.lhs.name == "__start" && rule.rhs.size() == 1) {
                    action_table[I]["$"] = Action{Action_type::ACCEPT, 0};
                    continue;
                }

                // Reduce: only insert reduce if no conflicting shift action exists
                // Use the lookahead token for LR(1)
                auto lookahead = getLookaheadToken(rule); // Define a function to get the lookahead token
                auto key = corelib::text::join(lookahead, "_");
                size_t reduce_index = 0;
                if (action_table[I].count(key) == 0) {
                    // No existing shift, safe to reduce
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
                    action_table[I][key] = Action{Action_type::REDUCE, reduce_index};
                } else {
                    // Shift/Reduce conflict warning (can be logged or handled)
                    const auto& existing = action_table[I][key];
                    if (existing.type == Action_type::SHIFT) {
                        // Conflict resolution (log or handle)
                        cpuf::printf("Conflict: SHIFT/REDUCE on state %$ for token %$\n", I, lookahead);
                    }
                }
            }
            // Dot is before a symbol
            else {
                const auto& next = rule.rhs[rule.dot_pos];
                size_t next_state = find_goto_state(item_set, next); // goto(I, X)

                if (corelib::text::isLower(next.name)) {
                    // Non-terminal → GOTO
                    goto_table[I][corelib::text::join(next.fullname, "_")] = next_state;
                } else {
                    // Terminal → SHIFT (unconditionally)
                    std::string token_name = corelib::text::join(next.fullname, "_");
                    if (action_table[I].count(token_name) == 0) {
                        action_table[I][token_name] = Action{Action_type::SHIFT, next_state};
                    } else {
                        // Optional: warn if double SHIFT or SHIFT/REDUCE
                        const auto& existing = action_table[I][token_name];
                        if (existing.type != Action_type::SHIFT || existing.state != next_state) {
                            cpuf::printf("Conflict: Duplicate or incompatible SHIFT at state %$ for token %$\n", I, token_name);
                        }
                    }
                }
            }
        }
        I++;
    }
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
            for (const auto &lhs_part : item.lhs.fullname) {
                oss << '\t' << lhs_part << " ";
            }
            oss << "→ ";

            // Print RHS with dot position
            for (size_t i = 0; i <= item.rhs.size(); ++i) {
                if (i == item.dot_pos) {
                    oss << "• ";
                }
                if (i < item.rhs.size()) {
                    oss << "{ ";
                    for (const auto &part : item.rhs[i].fullname) {
                        oss << part << " ";
                    }
                    oss << "} ";
                }
            }

            oss << "\n";
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
            const std::string& token = token_entry.first;
            const Action& action = token_entry.second;

            std::string action_str;
            switch (action.type) {
                case Action_type::SHIFT:
                    action_str = "SHIFT";
                    break;
                case Action_type::REDUCE:
                    action_str = "REDUCE";
                    break;
                case Action_type::ACCEPT:
                    action_str = "ACCEPT";
                    break;
                case Action_type::ERROR:
                    action_str = "ERROR";
                    break;
            }

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
            const std::string& non_terminal = non_terminal_entry.first;
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