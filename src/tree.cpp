#include <sstream>
#include <algorithm>
#include <queue>
#include <tree.h>
#include <corelib.h>
#include <internal_types.h>
#include <token_management.h>
#include <cpuf/printf.h>
#include <list>
#include <IR/IR.h>
const Parser::Tree& Tree::getRawTree() {
    return tree;
}
void Tree::getReplacedTree(std::vector<Parser::Rule> &rules, std::string name) {
    // Create a copy of the rules to avoid modifying the original while iterating
    for (auto& member : tree) {
        if (member.name == Parser::Rules::Rule) {
            auto data = std::any_cast<obj_t>(member.data);
            auto token_name_str = std::any_cast<std::string>(std::any_cast<Parser::Rule>(corelib::map::get(data, "name")).data);
            auto token_rule = std::any_cast<std::vector<Parser::Rule>>(corelib::map::get(data, "rule"));

            if (name == token_name_str) {
                continue;
            }

            auto matched_pos = Tokens::find_token_in_rule(token_rule, rules);

            for (auto& pos : matched_pos) {
                // Replace the repeated rule with a token
                auto other = Tokens::make_rule(Parser::Rules::Rule_other, rule_other {token_name_str, {token_name_str}, true});
                auto newToken = Tokens::make_rule(Parser::Rules::Rule_rule, obj_t {
                    { "val", other },
                    { "qualifier", Tokens::make_rule() }
                });

                // Ensure valid range for erase and insert operations
                if (pos + token_rule.size() <= rules.size()) {
                    rules.erase(rules.begin() + pos, rules.begin() + pos + token_rule.size());
                    rules.insert(rules.begin() + pos, newToken);
                }
            }
        }
    }
}

// Function to replace all duplicate tokens in the parse tree
void Tree::replaceDublicationsHelper(Parser::Tree &tree) {
    for (auto& member : tree) {
        if (member.name == Parser::Rules::Rule) {
            auto data = std::any_cast<obj_t>(member.data);
            auto rules = std::any_cast<std::vector<Parser::Rule>>(corelib::map::get(data, "rule"));
            auto name = std::any_cast<Parser::Rule>(corelib::map::get(data, "name"));
            auto nested_rules = std::any_cast<std::vector<Parser::Rule>>(corelib::map::get(data, "nestedRules"));
            replaceDublicationsHelper(nested_rules);
            // Get replaced tree and update the member's rules
            getReplacedTree(rules, std::any_cast<std::string>(name.data));
            corelib::map::set(data, "rule", std::any(rules));
            corelib::map::set(data, "nestedRules", std::any(nested_rules));
            member.data = data;
        }
    }
}
void Tree::replaceDublications() {
    replaceDublicationsHelper(tree);
}
void Tree::accumulateInlineNamesAndRemove(Parser::Tree& tree,
                                    std::vector<std::vector<std::string>>& table_key, 
                                    std::vector<Parser::Rule>& table_value, 
                                    std::vector<std::string> nested) {
    for (auto it = tree.begin(); it != tree.end(); ) {
        auto member = *it;
        if (member.name == Parser::Rules::Rule) {
            auto data = std::any_cast<obj_t>(member.data);
            auto rules = std::any_cast<std::vector<Parser::Rule>>(corelib::map::get(data, "rule"));
            auto name = std::any_cast<Parser::Rule>(corelib::map::get(data, "name"));
            auto nested_rules = std::any_cast<std::vector<Parser::Rule>>(corelib::map::get(data, "nestedRules"));

            nested.push_back(std::any_cast<std::string>(name.data));

            if (rules.size() == 1) {
                auto first = rules[0];
                auto first_data = std::any_cast<obj_t>(first.data);
                auto first_val = std::any_cast<Parser::Rule>(corelib::map::get(first_data, "val"));
                auto qualifier = std::any_cast<Parser::Rule>(corelib::map::get(first_data, "qualifier"));
                // ensure it is clear replacement (e.g no custom qualifier)
                if (qualifier.data.type() != typeid(void)) {
                    it++;
                    continue;
                }
                if (first_val.name == Parser::Rules::Rule_other) {
                    table_key.push_back(nested);
                    table_value.push_back(first_val);

                    // Instead of removing the element here, 
                    // we continue processing and just advance the iterator.
                    nested.pop_back();
                    it = tree.erase(it);  // Correctly remove element
                    continue;
                }
            }

            // Recurse with updated nested_rules and modified state
            accumulateInlineNamesAndRemove(nested_rules, table_key, table_value, nested);
            nested.pop_back();
            // Ensure that the data gets set back correctly after recursion
            corelib::map::set(data, "rule", std::any(rules));
            corelib::map::set(data, "nestedRules", std::any(nested_rules));
            it->data = data;
        }
        ++it;
    }
}
Parser::Rule Tree::find_key_in_table_by_name(const std::vector<std::vector<std::string>>& table_key,  const std::vector<Parser::Rule>& table_value, const std::vector<std::string>& name) {
    for (size_t i = 0; i < table_key.size(); ++i) {
        if (table_key[i] == name) {
            return table_value[i];
        }
    }

    return Parser::Rule{};
}

void Tree::inlineTokensInTable(std::vector<std::vector<std::string>> &table_key, std::vector<Parser::Rule> &table_value) {
    int inlineCount;
    do {
        inlineCount = 0;
        for (int i = 0; i < table_key.size(); i++) {
            auto key = table_key[i];
            auto value = table_value[i];
            
            auto name = std::any_cast<rule_other>(table_value[i].data);
            auto rule = find_key_in_table_by_name(table_key, table_value, name.fullname);
            if (!rule.empty()) {
                table_value[i] = rule;
                inlineCount++;
            }
        }
    } while(inlineCount > 0);
}
void Tree::inline_Rule_rule(std::vector<Parser::Rule> &rules, const std::vector<std::vector<std::string>> &table_key, const std::vector<Parser::Rule> &table_value, std::vector<std::string> nested) {
    for (auto &rule : rules) {
        auto rule_data = std::any_cast<obj_t>(rule.data);
        auto rule_val = std::any_cast<Parser::Rule>(corelib::map::get(rule_data, "val"));

        if (rule_val.name == Parser::Rules::Rule_other) {
            auto data = std::any_cast<rule_other>(rule_val.data);
            auto name = data.name;
            auto fullname = data.fullname;
            // // Debugging: Log the constructed nested names
            // std::cerr << "Rule: " << rule_name_str << " | Nested names:";
            // for (const auto& nested_name : rule_nested_names_str) {
            //     std::cerr << " " << nested_name;
            // }
            // std::cerr << std::endl;

            // // Debugging: Log the contents of table_key
            // std::cerr << "table_key contents:" << std::endl;
            // for (const auto& key : table_key) {
            //     std::cerr << "Key: ";
            //     for (const auto& k : key) {
            //         std::cerr << k << " ";
            //     }
            //     std::cerr << std::endl;
            // }

            // Check if we are only trying to match the last element (the identifier)
            //std::cerr << "Trying to find: " << rule_name_to_find << std::endl;

            // Search for the rule name in table_key
            auto find_it = std::find_if(table_key.begin(), table_key.end(),
                [&name](const std::vector<std::string>& key) {
                    return std::find(key.begin(), key.end(), name) != key.end();
                });

            if (find_it != table_key.end()) {
                auto index = find_it - table_key.begin();
                corelib::map::set(rule_data, "val", std::any(table_value[index]));
            }
        } else if (rule_val.name == Parser::Rules::Rule_group) {
            auto data = std::any_cast<obj_t>(rule_val.data);
            auto val = std::any_cast<std::vector<Parser::Rule>>(corelib::map::get(data, "val"));
            inline_Rule_rule(val, table_key, table_value, nested);
            corelib::map::set(data, "val", std::any(val));
            rule_val.data = data;
            corelib::map::set(rule_data, "val", std::any(rule_val));
        } else if (rule_val.name == Parser::Rules::Rule_op) {
            auto data = std::any_cast<std::vector<Parser::Rule>>(rule_val.data);
            inline_Rule_rule(data, table_key, table_value, nested);
            rule_val.data = data;
            corelib::map::set(rule_data, "val", std::any(rule_val));
        }

        rule.data = rule_data;
    }
}

void Tree::inlineTokensHelper(Parser::Tree &tree, const std::vector<std::vector<std::string>> &table_key, const std::vector<Parser::Rule> &table_value, std::vector<std::string> nested) {
    for (auto &member : tree) {
        if (member.name == Parser::Rules::Rule) {
            auto data = std::any_cast<obj_t>(member.data);
            auto rules = std::any_cast<std::vector<Parser::Rule>>(corelib::map::get(data, "rule"));
            auto name = std::any_cast<Parser::Rule>(corelib::map::get(data, "name"));
            auto nested_rules = std::any_cast<std::vector<Parser::Rule>>(corelib::map::get(data, "nestedRules"));
            //cpuf::printf("Rule: %s\n", std::any_cast<std::string>(name.data));
            nested.push_back(std::any_cast<std::string>(name.data));
            inline_Rule_rule(rules, table_key, table_value, nested);
            inlineTokensHelper(nested_rules, table_key, table_value, nested);
            nested.pop_back();

            corelib::map::set(data, "rule", std::any(rules));
            corelib::map::set(data, "nestedRules", std::any(nested_rules));
            member.data = data;
        }
    }
}
void Tree::inlineTokensHelper(Parser::Tree &tree) {
    std::vector<std::vector<std::string>> keys;
    std::vector<Parser::Rule> values;
    accumulateInlineNamesAndRemove(tree, keys, values, {});
    inlineTokensInTable(keys, values);
    // for (int i = 0; i < keys.size(); i++) {
    //     print_str_vector(keys[i]);
    //     cpuf::printf(" : ");
    //     auto val = values[i];
    //     auto data = std::any_cast<obj_t>(val.data);
    //     auto name = std::any_cast<Parser::Rule>(corelib::map::get(data, "name"));
    //     cpuf::printf("%s\n", std::any_cast<std::string>(name.data));
    // }
    inlineTokensHelper(tree, keys, values, {});
}
void Tree::inlineTokens() {
    return inlineTokensHelper(tree);
}

std::pair<Parser::Rule, Parser::Rule> Tree::getNewRuleAndToken(const Parser::Rule &val, const Parser::Rule &qualifier) {
    auto newToken = Tokens::singleRuleToToken(val);
    auto newTokenData = std::any_cast<obj_t>(newToken.data);
    auto newToken_name = std::any_cast<Parser::Rule>( corelib::map::get(newTokenData, "name") );
    auto newToken_name_str = std::any_cast<std::string>(newToken_name.data);
    auto Rule_other = Tokens::make_rule(Parser::Rules::Rule_other, rule_other {newToken_name_str, {newToken_name_str}});
    auto _rule = Tokens::make_rule(Parser::Rules::Rule_rule, obj_t {
        { "val", Rule_other  },
        { "qualifier", qualifier }
    });
    return {newToken, _rule};
}
bool Tree::checkRuleEscaped(const Parser::Rule &rule) {
    auto data = std::any_cast<obj_t>(rule.data);
    auto c = std::any_cast<std::string>(corelib::map::get(data, "c"));
    auto num = std::any_cast<Parser::Rule>(corelib::map::get(data, "num"));
    obj_t num_data;
    double num_main;
    if (num.data.has_value()) {
        num_data = num.as<obj_t>();
        num_main = std::any_cast<double>(corelib::map::get(num_data, "main_n"));
    } else {
        num_main = -1;
    }
    if (c[0] == 's' && num_main == 0)
        return 1;
    return 0;
}
void Tree::getTokensFromRule_rule(Parser::Tree &tree, std::vector<Parser::Rule>& rule, bool is_not_rule_rule) {
    // is rule
    for (auto &el : rule) {
        obj_t el_data = std::any_cast<obj_t>(el.data);
        Parser::Rule val = std::any_cast<Parser::Rule>(corelib::map::get(el_data, "val"));
        Parser::Rule qualifier = std::any_cast<::Parser::Rule>(corelib::map::get(el_data, "qualifier"));
        if (
            val.name == Parser::Rules::string || val.name == Parser::Rules::Rule_hex || val.name == Parser::Rules::Rule_bin || 
            val.name == Parser::Rules::Rule_csequence || val.name == Parser::Rules::Rule_escaped || val.name == Parser::Rules::Rule_any
        )
        {
            // do not tokenize rule_escaped if it is \s0
            if (val.name == Parser::Rules::Rule_escaped && checkRuleEscaped(val))
                continue;
            // convert into token & add here token instead of string
            auto [newToken, _rule] = getNewRuleAndToken(val, qualifier);
            tree.push_back(newToken);
            // use token here instead of literal
            el = _rule;
        } else if (val.name == Parser::Rules::Rule_group) {
            auto group_data = std::any_cast<obj_t>(val.data);
            auto group_val = std::any_cast<std::vector<Parser::Rule>>(corelib::map::get(group_data, "val"));
            getTokensFromRule_rule(tree, group_val);
            corelib::map::set(group_data, "val", std::any(group_val));
            val.data = std::any(group_data);

            corelib::map::set(el_data, "val", std::any(val));
            el.data = std::any(el_data);

        } else if (val.name == Parser::Rules::Rule_op) {
            auto rules = std::any_cast<std::vector<Parser::Rule>>(val.data);
            getTokensFromRule_rule(tree, rules);
            val.data = rules;

            corelib::map::set(el_data, "val", std::any(val));
            el.data = std::any(el_data);
        }
    }
}
Parser::Tree Tree::getTokensFromRule(Parser::Rule &member) {
    Parser::Tree tree;
    auto data = std::any_cast<obj_t>(member.data);
    auto name = std::any_cast<Parser::Rule>(corelib::map::get(data, "name"));
    auto name_str = std::any_cast<std::string>(name.data);
    auto rules = std::any_cast<std::vector<Parser::Rule>>(corelib::map::get(data, "rule"));
    auto nested_rule = std::any_cast<std::vector<Parser::Rule>>(corelib::map::get(data, "nestedRules"));
    if (corelib::text::isLower(name_str)) {
        getTokensFromRule_rule(tree, rules);

        // apply changes to map
        corelib::map::set(data, "rule", std::any(rules));
    }

    literalsToTokenHelper(nested_rule, tree);
    // apply changes to map
    corelib::map::set(data, "nestedRules", std::any(nested_rule));
    member.data = std::any(data); // apply changes to member
    return tree;
}
void Tree::literalsToTokenHelper(Parser::Tree& tree, Parser::Tree &treeInsert) {
    Parser::Tree tokenSeq;
    for (auto& member : tree) {
        if (member.name == Parser::Rules::Rule) {
            Parser::Tree tokenseq = getTokensFromRule(member);
            tokenSeq.insert(tokenSeq.end(), tokenseq.begin(), tokenseq.end());
        }
    }
    // Append tokenSeq to the existing tree
    treeInsert.insert(treeInsert.end(), tokenSeq.begin(), tokenSeq.end());
}
void Tree::literalsToToken() {
    literalsToTokenHelper(tree, tree);
}
std::vector<Parser::Rule> Tree::getValueFromGroup(const Parser::Rule &first) {
    auto first_data = std::any_cast<obj_t>(first.data);
    return std::any_cast<std::vector<Parser::Rule>>(corelib::map::get(first_data, "val"));
}
Parser::Rule Tree::getValueFromRule_rule(const Parser::Rule &rule) {
    auto data = std::any_cast<obj_t>(rule.data);
    return std::any_cast<Parser::Rule>(corelib::map::get(data, "val"));
}
bool Tree::processGroup_helper(Parser::Tree &tree, const std::vector<Parser::Rule>& group, const Parser::Rule &second) {
    if (second.name == Parser::Rules::Rule_group) {
        auto second_group = getValueFromGroup(second);
        if (group.size() == second_group.size()) {
            for (int i = 0; i < group.size(); i++) {
                auto groupv = getValueFromRule_rule(group[i]);
                auto second_groupv = getValueFromRule_rule(second_group[i]);

                if (Tokens::compare_rule(groupv, second_groupv))
                    continue;
                return sortPriority(groupv, second_groupv);
            }
        }
        return group.size() > second_group.size();
    }
    if (group.size() > 1)
        return 0;

    return sortPriority(group[0], second);;
}
bool Tree::sortPriority(Parser::Rule first, Parser::Rule second) {
    if (first.name == Parser::Rules::Rule_rule) {
        auto first_data = std::any_cast<obj_t>(first.data);
        first = std::any_cast<Parser::Rule>(corelib::map::get(first_data, "val"));
    }
    if (second.name == Parser::Rules::Rule_rule) {
        auto second_data = std::any_cast<obj_t>(second.data);
        second = std::any_cast<Parser::Rule>(corelib::map::get(second_data, "val"));
    }
    if (first.name == Parser::Rules::string && second.name == Parser::Rules::string) {
        // if first value size is lower second, put the second before
        // this ensure correct match of values
        auto first_str = std::any_cast<std::string>(first.data);
        auto second_str = std::any_cast<std::string>(second.data);
        size_t first_size = first_str.size();
        size_t second_size = second_str.size();

        // Sort by descending size first (longer strings come first)
        if (first_size != second_size) {
            return first_size > second_size;  
        }

        return 0;
    }
    // here is same as with strings
    if (first.name == Parser::Rules::Rule_bin && second.name == Parser::Rules::Rule_bin) {
        return std::any_cast<std::string>(first.data).size() > std::any_cast<std::string>(second.data).size();
    } 
    if (first.name == Parser::Rules::Rule_hex && second.name == Parser::Rules::Rule_hex) {
        return std::any_cast<std::string>(first.data).size() > std::any_cast<std::string>(second.data).size();
    }
    if (first.name == Parser::Rules::Rule_group && second.name == Parser::Rules::Rule_group) {
        auto first_data = std::any_cast<obj_t>(first.data);
        auto val = std::any_cast<std::vector<Parser::Rule>>(corelib::map::get(first_data, "val"));

        return processGroup_helper(tree, val, second);
    }
    if (first.name == Parser::Rules::Rule_other && second.name == Parser::Rules::Rule_other) {
        auto first_data = std::any_cast<rule_other>(first.data);
        auto second_data = std::any_cast<rule_other>(second.data);
        auto first_token = Tokens::find_token_in_tree(tree, first_data.fullname);
        auto second_token = Tokens::find_token_in_tree(tree, second_data.fullname);
        if (!first_token.data.has_value() || !second_token.data.has_value()) {
            return 0;
        }
        auto first_token_data = std::any_cast<obj_t>(first_token.data);
        auto second_token_data = std::any_cast<obj_t>(second_token.data);

        auto first_rules = std::any_cast<std::vector<Parser::Rule>>(corelib::map::get(first_token_data, "rule"));
        auto second_rules = std::any_cast<std::vector<Parser::Rule>>(corelib::map::get(second_token_data, "rule"));
        if (first_rules.size() != second_rules.size())
            return first_rules.size() > second_rules.size(); // bigger rule come first
        for (int i = 0; i < first_rules.size(); i++) {
            auto first_rules_data = std::any_cast<obj_t>(first_rules[i].data);
            auto second_rules_data = std::any_cast<obj_t>(second_rules[i].data);
            auto first_rules_val = std::any_cast<Parser::Rule>(corelib::map::get(first_rules_data, "val"));
            auto second_rules_val = std::any_cast<Parser::Rule>(corelib::map::get(second_rules_data, "val"));
            // go to same part
            if (Tokens::compare_rule(first_rules_val, second_rules_val))
                continue;

            // found not same part, call this function to determine which should go before
            return sortPriority(first_rules[i], second_rules[i]);       
        }

        // first_token = processNestedRuleHelper(first_nested_name, first_ruleother_data, first_token);
        // second_token = processNestedRuleHelper(second_nested_name, second_ruleother_data, second_token);


        

        // rules are same, do nothing
        return 0;
    }
    if (first.name == Parser::Rules::Rule_csequence && second.name == Parser::Rules::Rule_csequence) {
        auto first_data = std::any_cast<obj_t>(first.data);
        auto second_data = std::any_cast<obj_t>(second.data);
    
        auto first_not = std::any_cast<bool>(corelib::map::get(first_data, "not"));
        auto first_val = std::any_cast<std::vector<Parser::Rule>>(corelib::map::get(first_data, "val"));
    
        auto second_not = std::any_cast<bool>(corelib::map::get(second_data, "not"));
        auto second_val = std::any_cast<std::vector<Parser::Rule>>(corelib::map::get(second_data, "val"));
    
        // Rule: Negative should go after non-negative
        if (!first_not && second_not)
            return true; // first < second → first comes first
        if (first_not && !second_not)
            return false; // second < first → second comes first
    
        // Rule: Longer sequence should go before shorter
        return first_val.size() > second_val.size(); // true if first should come first
    }
    if (first.name == Parser::Rules::Rule_group) {
        auto first_data = std::any_cast<obj_t>(first.data);
        auto val = std::any_cast<std::vector<Parser::Rule>>(corelib::map::get(first_data, "val"));

        return processGroup_helper(tree, val, second);
    } else if (first.name == Parser::Rules::Rule_group) {
        auto second_data = std::any_cast<obj_t>(second.data);
        auto val = std::any_cast<std::vector<Parser::Rule>>(corelib::map::get(second_data, "val"));

        return !processGroup_helper(tree, val, first);
    }
    // if non above is true but the value kind is same, remain values in their order
    if (first.name == second.name)
       return 0;
    if (first.name == Parser::Rules::Rule_other) {
        auto first_data = std::any_cast<rule_other>(first.data);
        auto first_token = Tokens::find_token_in_tree(tree, first_data.fullname);
        if (!first_token.data.has_value()) {
            return 0;
        }
        auto first_token_data = std::any_cast<obj_t>(first_token.data);
        auto first_rules = std::any_cast<std::vector<Parser::Rule>>(corelib::map::get(first_token_data, "rule"));

        auto first_rules_data = std::any_cast<obj_t>(first_rules[0].data);
        auto first_rules_val = std::any_cast<Parser::Rule>(corelib::map::get(first_rules_data, "val"));
        return sortPriority(first_rules[0], second);       
    } else if (second.name == Parser::Rules::Rule_other) {
        auto second_data = std::any_cast<rule_other>(second.data);
        auto second_token = Tokens::find_token_in_tree(tree, second_data.fullname);
        if (!second_token.data.has_value()) {
            return 0;
        }
        auto second_token_data = std::any_cast<obj_t>(second_token.data);
        auto second_rules = std::any_cast<std::vector<Parser::Rule>>(corelib::map::get(second_token_data, "rule"));

        auto second_rules_data = std::any_cast<obj_t>(second_rules[0].data);
        auto second_rules_val = std::any_cast<Parser::Rule>(corelib::map::get(second_rules_data, "val"));
        return sortPriority(first, second_rules[0]);       
    }

    // Prioritization logic for different rule types
    const std::vector<Parser::Rules> priority_order = {
        Parser::Rules::string,
        Parser::Rules::Rule_escaped,
        Parser::Rules::Rule_csequence,
        Parser::Rules::Rule_bin,
        Parser::Rules::Rule_hex,
        Parser::Rules::Rule_other,
        Parser::Rules::Rule_group,
        Parser::Rules::Rule_any,
    };
    
    auto first_pos = std::find(priority_order.begin(), priority_order.end(), first.name);
    auto second_pos = std::find(priority_order.begin(), priority_order.end(), second.name);
    
    if (first_pos != priority_order.end() && second_pos != priority_order.end()) {
        return first_pos < second_pos;
    }
    return 0;
}
void Tree::sortByPriorityHelper(std::vector<Parser::Rule> &rules) {
    bool apply_val = false;
    for (int i = 0; i < rules.size(); i++) {
        auto data = std::any_cast<obj_t>(rules[i].data);
        auto val = std::any_cast<Parser::Rule>(corelib::map::get(data, "val"));
        // apply the sort for groups
        // note this does not have relation to the sortion itself
        if (val.name == Parser::Rules::Rule_group) {
            auto data = std::any_cast<obj_t>(val.data);
            auto this_val = std::any_cast<std::vector<Parser::Rule>>(corelib::map::get(data, "val"));
            sortByPriorityHelper(this_val);
            
            // assign result to the current group value
            corelib::map::set(data, "val", std::any(this_val));
            val.data = data;
            apply_val = true;
        }

        // sort process
        if (val.name == Parser::Rules::Rule_op)
        {
            auto dt = std::any_cast<std::vector<Parser::Rule>>(val.data);
            std::sort(dt.begin(), dt.end(), [this](auto &first, auto &second) { return this->sortPriority(first, second); });
            val.data = dt;
            apply_val = true;
        }
        if (apply_val) {
            corelib::map::set(data, "val", std::any(val));
            rules[i].data = data;
        }
    }
    //LOG CHANGES
    // cpuf::printf("result: \n");
    // for (auto el : rules) {
    //     auto first_data = std::any_cast<obj_t>(el.data);
    //     auto first_val = std::any_cast<Parser::Rule>(corelib::map::get(first_data, "val"));
    //     cpuf::printf("\t%s\n", Parser::RulesToString(first_val.name));
    // }


}
void Tree::sortByPriority(Parser::Tree &tree)  {
    for (auto &member : tree) {
        if (member.name == Parser::Rules::Rule) {
            auto data = std::any_cast<obj_t>(member.data);
            auto name = std::any_cast<Parser::Rule>(corelib::map::get(data, "name"));
            auto name_str = std::any_cast<std::string>(name.data);
            auto rules = std::any_cast<std::vector<Parser::Rule>>(corelib::map::get(data, "rule"));
            auto nested_rules = std::any_cast<std::vector<Parser::Rule>>(corelib::map::get(data, "nestedRules"));
            sortByPriorityHelper(rules);
            sortByPriority(nested_rules);
            // sort nested rule
            corelib::map::set(data, "nestedRules", std::any(nested_rules));
            // apply changes

            corelib::map::set(data, "rule", std::any(rules));
            member.data = data;
        }
    }
}
void Tree::sortByPriority() {
    return sortByPriority(tree);
}
void Tree::addSpaceToken() {
    std::vector<Parser::Rule> chars = {
        { Tokens::make_rule(Parser::Rules::Rule_csequence_escape, std::string(1, ' '))  },
        { Tokens::make_rule(Parser::Rules::Rule_csequence_escape, std::string(1, '\t')) },
        { Tokens::make_rule(Parser::Rules::Rule_csequence_escape, std::string(1, '\n')) },
        { Tokens::make_rule(Parser::Rules::Rule_csequence_escape, std::string(1, '\r')) },
        { Tokens::make_rule(Parser::Rules::Rule_csequence_escape, std::string(1, '\v')) },
        { Tokens::make_rule(Parser::Rules::Rule_csequence_escape, std::string(1, '\f')) },
    };
    auto csequence = Tokens::make_rule(Parser::Rules::Rule_csequence, obj_t {
        {"not", false},
        {"val", chars}
    });
    auto Rule_rule = Tokens::make_rule(Parser::Rules::Rule_rule, obj_t {
        { "val", csequence },
        { "qualifier", Tokens::make_rule(Parser::Rules::Rule_qualifier, '+') }
    });
    auto token = Tokens::make_rule(Parser::Rules::Rule, obj_t {
        {"name", Tokens::make_rule(Parser::Rules::id, std::string("__WHITESPACE"))},
        {"rule", std::vector<Parser::Rule> {Rule_rule}},
        {"data_block", Tokens::make_rule()},
        {"nestedRules", std::vector<Parser::Rule>()}
    });
    tree.push_back(token);
}
std::pair<std::vector<std::string>, std::vector<std::string>> Tree::getTokenAndRuleNamesHelper(const Parser::Tree &tree, std::string nested_name) {
    std::vector<std::string> tokens, rules;
    
    for (auto el : tree) {
        if (el.name == Parser::Rules::Rule) {
            auto data = std::any_cast<obj_t>(el.data);
            auto name = std::any_cast<Parser::Rule>(corelib::map::get(data, "name"));
            auto name_str = std::any_cast<std::string>(name.data);
            auto nested_rules = std::any_cast<std::vector<Parser::Rule>>(corelib::map::get(data, "nestedRules"));

            // Construct the full rule name properly
            std::string new_nested_name = nested_name.empty() ? name_str : nested_name + "_" + name_str;

            // Categorize as token or rule
            if (corelib::text::isUpper(name_str)) {
                tokens.push_back(new_nested_name);
            } else {
                rules.push_back(new_nested_name);
            }

            // Recursively process nested rules with the updated name
            auto [new_tokens, new_rules] = getTokenAndRuleNamesHelper(nested_rules, new_nested_name);

            // Insert the results into the main lists
            tokens.insert(tokens.end(), new_tokens.begin(), new_tokens.end());
            rules.insert(rules.end(), new_rules.begin(), new_rules.end());
        }
    }

    return {tokens, rules};
}
std::pair<std::vector<std::string>, std::vector<std::string>> Tree::getTokenAndRuleNames() {
    return getTokenAndRuleNamesHelper(tree, "");
}
use_prop_t Tree::get_use_data(const Parser::Rule &use) {
    use_prop_t result;
    auto data = std::any_cast<std::vector<Parser::Rule>>(use.data);
    for (auto &el : data) {
        auto el_data = std::any_cast<obj_t>(el.data);
        auto el_id = std::any_cast<Parser::Rule>(corelib::map::get(el_data, "name"));
        auto el_name = std::any_cast<std::string>(el_id.data);
        auto value = std::any_cast<Parser::Rule>(corelib::map::get(el_data, "value"));
        if (value.data.has_value()) {
            auto value_data = std::any_cast<Parser::Rule>(value.data);
            result[el_name] = value_data;
        } else {
            result[el_name] = Parser::Rule();
        }

    }
    return result;
}
use_prop_t Tree::accamulate_use_data_to_map() {
    use_prop_t result;
    for (auto el : tree) {
        if (el.name != Parser::Rules::use)
            continue;
        
        auto res = get_use_data(el);
        for (auto [key, value] : res) {
            result[key] = value;
        }
    }
    return result;
}
void Tree::accamulateUsePlaces(std::vector<Parser::Rule>& rules, use_place_t &use_places, std::vector<std::string> &fullname) {
    for (auto &el : rules) {
        auto dt = std::any_cast<obj_t>(el.data);
        auto val = std::any_cast<Parser::Rule>(corelib::map::get(dt, "val"));
        if (val.name == Parser::Rules::Rule_other) {
            auto data = std::any_cast<rule_other>(val.data);
            auto ptr = std::find_if(use_places.begin(), use_places.end(), [&data](const use_place_t_part &part1) {
                return part1.first == data.fullname;
            });
            if (ptr != use_places.end()) {
                ptr->second.push_back(fullname);
            } else {
                use_places.push_back({data.fullname, {fullname}});
            }
        } else if (val.name == Parser::Rules::Rule_group) {
            auto data = std::any_cast<obj_t>(val.data);
            auto rules = std::any_cast<std::vector<Parser::Rule>>(corelib::map::get(data, "val"));
            accamulateUsePlaces(rules, use_places, fullname);
        } else if (val.name == Parser::Rules::Rule_op) {
            auto data = std::any_cast<std::vector<Parser::Rule>>(val.data);
            accamulateUsePlaces(data, use_places, fullname);
        }
    }
}
void Tree::getUsePlacesTableHelper(Parser::Tree &tree, use_place_t &use_places, std::vector<std::string> &fullname) {
    for (auto el : tree) {
        if (el.name == Parser::Rules::Rule) {
            auto data = std::any_cast<obj_t>(el.data);
            auto name = std::any_cast<Parser::Rule>(corelib::map::get(data, "name"));
            auto name_str = std::any_cast<std::string>(name.data);
            auto rules = std::any_cast<std::vector<Parser::Rule>>(corelib::map::get(data, "rule"));
            auto nested_rules = std::any_cast<std::vector<Parser::Rule>>(corelib::map::get(data, "nestedRules"));
            fullname.push_back(name_str);
            accamulateUsePlaces(rules, use_places, fullname);
            getUsePlacesTableHelper(nested_rules, use_places, fullname);
            fullname.pop_back();
        }
    }
}
use_place_t Tree::getUsePlacesTable() {
    use_place_t use_places;
    std::vector<std::string> fullname;
    getUsePlacesTableHelper(tree, use_places, fullname);
    return use_places;
}
std::pair<data_block_t, data_block_t> Tree::get_data_blocks(const IR &ir) {
    data_block_t datablocks_tokens;
    data_block_t datablocks_rules;
    bool isToken;
    std::string name;
    for (auto el : ir.getData()) {
        if (el.type == IR::types::TOKEN) {
            name = corelib::text::join(std::any_cast<std::pair<std::string, std::vector<std::string>>>(el.value).second, "_");
            isToken = true;
        } else if (el.type == IR::types::RULE) {
            name = corelib::text::join(std::any_cast<std::pair<std::string, std::vector<std::string>>>(el.value).second, "_");
            isToken = false;
        } else if (el.type == IR::types::DATA_BLOCK) {
            if (isToken)
                datablocks_tokens.push_back({name, std::any_cast<IR::data_block>(el.value)});
            else
                datablocks_rules.push_back({name, std::any_cast<IR::data_block>(el.value)});
        }
    }
    return {datablocks_tokens, datablocks_rules};
}


lexer_code Tree::getCodeForLexer(use_place_t use_places, const IR &ir) {
    std::vector<Parser::Rule> rule_op;
    for (auto &el : ir.getData()) {
        if (el.type == IR::types::TOKEN) {
            auto name = std::any_cast<std::pair<std::string, std::vector<std::string>>>(el.value);
            if (name.second.size() > 1) { // this is nested rule
                auto data_in_use_place = std::find_if(use_places.begin(), use_places.end(), [&name](use_place_t_part &part) {
                    return part.first == name.second;
                });
                if (data_in_use_place != use_places.end()) {
                    bool add = false;
                    for (auto &fullname : data_in_use_place->second) {
                        if (corelib::text::isLower(fullname.back())) {
                            add = true;
                            break;
                        }
                    }
                    if (!add)
                        continue;
                } else {
                    cpuf::printf("could not find data for %$\n", name.second);
                }
            }

            // if not found fall back to add the token
            auto _rule_other = Tokens::make_rule(Parser::Rules::Rule_other, rule_other {name.first, name.second});
            auto rule_rule = Tokens::make_rule(Parser::Rules::Rule_rule, obj_t {
                {"val", _rule_other},
                {"qualifier", Tokens::make_rule(Parser::Rules::Rule_qualifier)}
            });
            rule_op.push_back(rule_rule);
        }

    }
    auto rule_op_rule_rule = Tokens::make_rule(Parser::Rules::Rule_rule, obj_t {
        {"val", Tokens::make_rule(Parser::Rules::Rule_op, rule_op)},
        {"qualifier", Tokens::make_rule(Parser::Rules::Rule_qualifier)}
    });
    std::vector<Parser::Rule> rule_op2 = {rule_op_rule_rule};
    sortByPriorityHelper(rule_op2);
    // auto rule = Tokens::make_rule(Parser::Rules::Rule, obj_t {
    //     {"name", Tokens::make_rule(Parser::Rules::id, std::string("makeTokens"))},
    //     {"rule", std::vector<Parser::Rule>{rule_rule}},
    //     {"data_block", Tokens::make_rule()},
    //     {"nestedRules", std::vector<Parser::Rule>()}
    // });
    //Parser::Tree tree = {rule};

    // auto rule_data = std::any_cast<obj_t>(rule.data);
    // auto new_rule_rule = std::any_cast<std::vector<Parser::Rule>>(corelib::map::get(rule_data, "rule"))[0];
    IR code(this->tree, rule_op2);
    code.setIsToken(true);
    auto success_var = code.makeIR();
    code.push_begin({IR::types::TOKEN});
    code.push({IR::types::RULE_END});
    code.optimizeIR();
    return {code, success_var[0]};
}
void Tree::getConflictsTableForRule(const std::vector<Parser::Rule> &rules, ConflictsList &conflict_list) {
    if (rules.empty())
        return;
    for (auto it = rules.begin(); it != rules.end() - 1; it++) {
        auto current_rule_rule = *it;
        auto next_rule_rule = *(it + 1);
        Parser::Rule current, next;
        if (current_rule_rule.name == Parser::Rules::Rule_rule) {
            auto data = std::any_cast<obj_t>(current_rule_rule.data);
            current = std::any_cast<Parser::Rule>(corelib::map::get(data, "val"));
        }
        if (next_rule_rule.name == Parser::Rules::Rule_rule) {
            auto data = std::any_cast<obj_t>(next_rule_rule.data);
            next = std::any_cast<Parser::Rule>(corelib::map::get(data, "val"));
        }
        if (current.name != Parser::Rules::Rule_other || next.name != Parser::Rules::Rule_other)
            continue;
        
        auto current_data = std::any_cast<rule_other>(current.data);
        auto next_data = std::any_cast<rule_other>(next.data);
        auto current_rule = Tokens::find_token_in_tree(tree, current_data.fullname);
        auto next_rule = Tokens::find_token_in_tree(tree, next_data.fullname);

        auto current_rule_data = std::any_cast<obj_t>(current_rule.data);
        auto current_rule_rules = std::any_cast<std::vector<Parser::Rule>>(corelib::map::get(current_rule_data, "rule"));
        auto next_rule_data = std::any_cast<obj_t>(next_rule.data);
        auto next_rule_rules = std::any_cast<std::vector<Parser::Rule>>(corelib::map::get(next_rule_data, "rule"));
        if (current_rule_rules.empty() || next_rule_rules.empty())
            continue;
        
        if (!Tokens::compare_rule(current_rule_rules[0], next_rule_rules[0]))
            continue;
        
        std::vector<Parser::Rule>::iterator current_rule_it = current_rule_rules.begin();
        std::vector<Parser::Rule>::iterator next_rule_it = next_rule_rules.begin();
        if (current_rule_rules.size() > next_rule_rules.size())
            continue; // first rule is bigger next, no conflicts possible
        while (current_rule_it != current_rule_rules.end() && next_rule_it != next_rule_rules.end() && Tokens::compare_rule(*current_rule_it, *next_rule_it))
        {
            ++current_rule_it;
            ++next_rule_it;
        }
        if (next_rule_it == next_rule_rules.end())
            continue;   // same rules
        conflict_list.push_back({&current_rule_rules, &next_rule_rules, current_rule_it, next_rule_it});
    }
}
void Tree::resolveConflictsHelper(const std::vector<Parser::Rule> &rules) {
    ConflictsList conflict_list;
    getConflictsTableForRule(rules, conflict_list);
    for (auto [lhs_rule_p, rhs_rule_p, lhs_it, rhs_it] : conflict_list) {
        lhs_rule_p->insert(lhs_it, Tokens::make_rule(Parser::Rules::Rule_not, *rhs_it));
    }
}
void Tree::resolveConflicts(Parser::Tree &tree) {
    for (auto node : tree) {
        if (node.name != Parser::Rules::Rule)
            continue;
        
        auto data = std::any_cast<obj_t>(node.data);
        auto name = std::any_cast<Parser::Rule>(corelib::map::get(data, "name"));
        auto name_str = std::any_cast<std::string>(name.data);
        auto rules = std::any_cast<std::vector<Parser::Rule>>(corelib::map::get(data, "rule"));
        auto nested_rules = std::any_cast<std::vector<Parser::Rule>>(corelib::map::get(data, "nestedRules"));
        resolveConflictsHelper(rules);
        resolveConflicts(nested_rules);
    }
}
void Tree::resolveConflicts() {
    resolveConflicts(tree);
}