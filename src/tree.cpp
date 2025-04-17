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
Parser::Tree& Tree::getRawTree() {
    return tree;
}
Parser::Tree::iterator Tree::begin() {
    return tree.begin();
}
Parser::Tree::iterator Tree::end() {
    return tree.end();
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
void Tree::replaceDublicationsHelper(Parser::Tree &tree, bool global) {
    for (auto& member : tree) {
        if (member.name == Parser::Rules::Rule) {
            auto data = std::any_cast<obj_t>(member.data);
            auto rules = std::any_cast<std::vector<Parser::Rule>>(corelib::map::get(data, "rule"));
            auto name = std::any_cast<Parser::Rule>(corelib::map::get(data, "name"));
            auto name_str = std::any_cast<std::string>(name.data);
            auto nested_rules = std::any_cast<std::vector<Parser::Rule>>(corelib::map::get(data, "nestedRules"));
            if (name_str == "main" && global) {
                continue;
            }
            replaceDublicationsHelper(nested_rules, false);
            // Get replaced tree and update the member's rules
            getReplacedTree(rules, name_str);
            corelib::map::set(data, "rule", std::any(rules));
            corelib::map::set(data, "nestedRules", std::any(nested_rules));
            member.data = data;
        }
    }
}
void Tree::replaceDublications() {
    replaceDublicationsHelper(tree);
}
void Tree::removeEmptyRule(Parser::Tree &tree) {
    for (auto it = tree.begin(); it != tree.end(); it++) {
        auto member = *it;
        if (member.name != Parser::Rules::Rule)
            continue;
        if (!member.data.has_value()) {
            continue;
        }
        auto data = std::any_cast<obj_t>(member.data);
        auto name = std::any_cast<Parser::Rule>(corelib::map::get(data, "name"));
        auto name_str = std::any_cast<std::string>(name.data);
        auto rules = std::any_cast<std::vector<Parser::Rule>>(corelib::map::get(data, "rule"));
        auto nested_rules = std::any_cast<std::vector<Parser::Rule>>(corelib::map::get(data, "nestedRules"));
        // do not include tokens
        if (rules.empty()) {
            it = tree.erase(it);
        }
        removeEmptyRule(nested_rules);
        corelib::map::set(data, "nestedRules", std::any(nested_rules));
        it->data = data;
    }
}
void Tree::removeEmptyRule() {
    removeEmptyRule(tree);
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
            auto name_str = std::any_cast<std::string>(name.data);
            auto nested_rules = std::any_cast<std::vector<Parser::Rule>>(corelib::map::get(data, "nestedRules"));
            if (nested.size() == 0 && name_str == "main") {
                it++;
                continue;
            }
            nested.push_back(name_str);

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
            auto name_str = std::any_cast<std::string>(name.data);
            auto nested_rules = std::any_cast<std::vector<Parser::Rule>>(corelib::map::get(data, "nestedRules"));
            //cpuf::printf("Rule: %s\n", std::any_cast<std::string>(name.data));
            nested.push_back(name_str);
            if (name_str == "main" && nested.size() == 1)
                continue;
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
    auto newToken = Tokens::singleRuleToToken(val, token_count);
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
bool Tree::processGroup_helper(Parser::Tree &tree, const std::vector<Parser::Rule>& group, const Parser::Rule &second) {
    if (second.name == Parser::Rules::Rule_group) {
        auto second_group = Tokens::getValueFromGroup(second);
        if (group.size() == second_group.size()) {
            for (int i = 0; i < group.size(); i++) {
                auto groupv = Tokens::getValueFromRule_rule(group[i]);
                auto second_groupv = Tokens::getValueFromRule_rule(second_group[i]);

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
        if (first_token == nullptr || second_token == nullptr || !first_token->data.has_value() || !second_token->data.has_value()) {
            return 0;
        }
        auto first_token_data = std::any_cast<obj_t>(first_token->data);
        auto second_token_data = std::any_cast<obj_t>(second_token->data);

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
        if (first_token == nullptr || !first_token->data.has_value()) {
            return 0;
        }
        auto first_token_data = std::any_cast<obj_t>(first_token->data);
        auto first_rules = std::any_cast<std::vector<Parser::Rule>>(corelib::map::get(first_token_data, "rule"));

        auto first_rules_data = std::any_cast<obj_t>(first_rules[0].data);
        auto first_rules_val = std::any_cast<Parser::Rule>(corelib::map::get(first_rules_data, "val"));
        return sortPriority(first_rules[0], second);       
    } else if (second.name == Parser::Rules::Rule_other) {
        auto second_data = std::any_cast<rule_other>(second.data);
        auto second_token = Tokens::find_token_in_tree(tree, second_data.fullname);
        if (second_token == nullptr || !second_token->data.has_value()) {
            return 0;
        }
        auto second_token_data = std::any_cast<obj_t>(second_token->data);
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
        if (!el.data.has_value())
            continue;
        auto dt = std::any_cast<obj_t>(el.data);
        auto val = std::any_cast<Parser::Rule>(corelib::map::get(dt, "val"));
        if (val.name == Parser::Rules::Rule_other) {
            auto data = std::any_cast<rule_other>(val.data);
            use_places[data.fullname].push_back(fullname);
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
Tree::use_place_t Tree::getUsePlacesTable() {
    use_place_t use_places;
    std::vector<std::string> fullname;
    getUsePlacesTableHelper(tree, use_places, fullname);
    return use_places;
}
std::pair<data_block_t, data_block_t> Tree::get_data_blocks(const LLIR &ir) {
    data_block_t datablocks_tokens;
    data_block_t datablocks_rules;
    bool isToken;
    std::string name;
    for (auto el : ir.getData()) {
        if (el.type == LLIR::types::TOKEN) {
            name = corelib::text::join(std::any_cast<std::pair<std::string, std::vector<std::string>>>(el.value).second, "_");
            isToken = true;
        } else if (el.type == LLIR::types::RULE) {
            name = corelib::text::join(std::any_cast<std::pair<std::string, std::vector<std::string>>>(el.value).second, "_");
            isToken = false;
        } else if (el.type == LLIR::types::DATA_BLOCK) {
            if (isToken)
                datablocks_tokens.push_back({name, std::any_cast<LLIR::data_block>(el.value)});
            else
                datablocks_rules.push_back({name, std::any_cast<LLIR::data_block>(el.value)});
        }
    }
    return {datablocks_tokens, datablocks_rules};
}

void Tree::getTokensForLexer(Parser::Tree &tree, use_place_t &use_places, std::vector<Parser::Rule> &rule_op, std::vector<std::string> &fullname) {
    for (auto &member : tree) {
        if (member.name != Parser::Rules::Rule) 
            continue;
        auto data = std::any_cast<obj_t>(member.data);
        auto name = std::any_cast<Parser::Rule>(corelib::map::get(data, "name"));
        auto name_str = std::any_cast<std::string>(name.data);
        auto nested_rules = std::any_cast<std::vector<Parser::Rule>>(corelib::map::get(data, "nestedRules"));
        fullname.push_back(name_str);
        if (fullname.size() != 1 && corelib::text::isUpper(name_str)) {
            auto data_in_use_place = use_places.find(fullname);
            if (data_in_use_place != use_places.end()) {
                bool add = false;
                for (auto &fn : data_in_use_place->second) {
                    if (corelib::text::isLower(fn.back())) {
                        add = true;
                        break;
                    }
                }
                if (!add) {
                    fullname.pop_back();
                    continue;
                }
            } else {
                cpuf::printf("could not find data for %$\n", fullname);
            }

            // if not found fall back to add the token
            auto _rule_other = Tokens::make_rule(Parser::Rules::Rule_other, rule_other {name_str, fullname});
            auto rule_rule = Tokens::make_rule(Parser::Rules::Rule_rule, obj_t {
                {"val", _rule_other},
                {"qualifier", Tokens::make_rule(Parser::Rules::Rule_qualifier)}
            });
            rule_op.push_back(rule_rule);
        }
        getTokensForLexer(nested_rules, use_places, rule_op, fullname);
        fullname.pop_back();
    }
}
lexer_code Tree::getCodeForLexer(use_place_t use_places) {
    std::vector<Parser::Rule> rule_op;
    std::vector<std::string> fullname;
    getTokensForLexer(tree, use_places, rule_op, fullname);
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
    LLIR code(this->tree, rule_op2);
    code.setIsToken(true);
    auto success_var = code.makeIR();
    code.push_begin({LLIR::types::TOKEN});
    code.push({LLIR::types::RULE_END});
    code.optimizeIR();
    return {code, success_var[0]};
}

void Tree::getConflictsTableForRule(const std::vector<Parser::Rule> &rules, ConflictsList &conflict_list) {
    if (rules.empty())
        return;

    for (auto it = rules.begin(); it != rules.end() - 1; it++) {
        const auto& current_rule_rule = *it;
        bool optional_quantifier = true;
        for (auto next_it = it + 1; next_it != rules.end() && optional_quantifier; next_it++) {
            Parser::Rule current, next;
            const auto& next_rule_rule = *next_it;
            current = Tokens::getValueFromRule_rule(current_rule_rule);
            if (next_rule_rule.name == Parser::Rules::Rule_rule) {
                Parser::Rule quantifier_rule;
                char quantifier_char = '\0';
                next = Tokens::getValueFromRule_rule(next_rule_rule, quantifier_rule);
                if (quantifier_rule.data.has_value()) {
                    quantifier_char = std::any_cast<char>(quantifier_rule.data);
                }
                optional_quantifier = quantifier_char == '?' || quantifier_char == '*';
            }
            if (current.name != Parser::Rules::Rule_other || next.name != Parser::Rules::Rule_other)
                break;
            auto& current_data = std::any_cast<rule_other&>(current.data);
            auto& next_data = std::any_cast<rule_other&>(next.data);
            cpuf::printf("%$ with %$\n", current_data.fullname, next_data.fullname);
            auto current_rule = Tokens::find_token_in_tree(tree, current_data.fullname);
            auto next_rule = Tokens::find_token_in_tree(tree, next_data.fullname);
            if (current_rule == nullptr || next_rule == nullptr)
                continue;
            auto& current_rule_data = std::any_cast<obj_t&>(current_rule->data);
            auto& next_rule_data = std::any_cast<obj_t&>(next_rule->data);
    
            auto current_rule_rules = std::any_cast<std::vector<Parser::Rule>&>(corelib::map::get(current_rule_data, "rule"));
            auto next_rule_rules = std::any_cast<std::vector<Parser::Rule>&>(corelib::map::get(next_rule_data, "rule"));
    
            if (current_rule_rules.empty() || next_rule_rules.empty())
                continue;

            if (!Tokens::compare_rule_matching(current_rule_rules.begin(), next_rule_rules.begin())) {
                Parser::Rule currentx, nextx;
                if (current_rule_rules[0].name == Parser::Rules::Rule_rule) {
                    auto data = std::any_cast<obj_t>(current_rule_rules[0].data);
                    currentx = std::any_cast<Parser::Rule&>(corelib::map::get(data, "val"));

                }
                if (next_rule_rules[0].name == Parser::Rules::Rule_rule) {
                    auto data = std::any_cast<obj_t>(next_rule_rules[0].data);
                    nextx = std::any_cast<Parser::Rule>(corelib::map::get(data, "val"));
                }
                cpuf::printf("current_rule_rules[0]: %s, next_rule_rules[0]: %s\n", Parser::RulesToString(currentx.name), Parser::RulesToString(nextx.name));
                cpuf:printf("First Compare unsucess\n");
                continue;
            }
    
            using iterator = std::vector<Parser::Rule>::iterator;
            struct point { iterator pos, end; };
    
            std::stack<point> current_rule_stack;
            std::stack<point> next_rule_stack;
    
            std::stack<std::vector<Parser::Rule>*> current_rule_vector_stack;
            std::stack<std::vector<Parser::Rule>*> next_rule_vector_stack;
    
            current_rule_stack.push({current_rule_rules.begin() + 1, current_rule_rules.end()});
            next_rule_stack.push({next_rule_rules.begin() + 1, next_rule_rules.end()});
    
            bool conflict_found = false, 
                success_rule_found = true,
                current_optional = true,
                next_optional = true;
            std::vector<Parser::Rule>::iterator current_optional_place(nullptr), next_optional_place(nullptr);
            auto pop_rules_stack_on_end = [](std::stack<std::vector<Parser::Rule>*> vstack, std::stack<point> &stack) {
                if (stack.top().pos == stack.top().end) {
                    if (stack.size() > 1) {
                        stack.pop();
                        vstack.pop();
                        return 1;
                    } else return 2;
                }
                return 0;
            };
            auto get_quantifier = [](const Parser::Rule &quantifier) {
                if (!quantifier.empty())
                    return std::any_cast<char>(quantifier.data);
                return '\0';
            };
            auto getRuleOtherRules = [this](const Parser::Rule &rule) -> std::vector<Parser::Rule>* {
                auto data = std::any_cast<rule_other>(rule.data);
                auto *token = Tokens::find_token_in_tree(this->tree, data.fullname);
                if (token == nullptr)
                    return nullptr;
                auto &token_data = std::any_cast<obj_t&>(token->data);
                auto &rules = std::any_cast<std::vector<Parser::Rule>&>(corelib::map::get(token_data, "rule"));
                return &rules;
            };
            auto switch_to_nested_rule = [getRuleOtherRules](const Parser::Rule &r, std::stack<std::vector<Parser::Rule>*> &vstack, std::stack<point> &stack) -> bool {
                auto *rule = getRuleOtherRules(r);
                if (rule == nullptr) {
                    return false;
                }
                vstack.push(rule);
                stack.push({vstack.top()->begin(), vstack.top()->end()});
                return true;
            };
            auto process_csequence_with_string = [](const Parser::Rule &csequence_rule, const Parser::Rule &str_rule) -> std::pair<bool /*loop status*/, bool /*conflict_found*/> {
                auto csequence_data = std::any_cast<obj_t>(csequence_rule.data);
                auto csequence_not = std::any_cast<bool>(corelib::map::get(csequence_data, "not"));
                auto csequence = std::any_cast<std::vector<Parser::Rule>>(corelib::map::get(csequence_data, "val"));
                auto str_data = std::any_cast<std::string>(str_rule.data);
                if (csequence.empty())
                    return {0, 0};
                auto symbol = csequence[0]; 
                if (str_data.empty())
                    return {0, 0};
                if (symbol.name == Parser::Rules::Rule_csequence_symbol) {
                    auto data = std::any_cast<std::string>(symbol.data);
                    if (str_data[0] == data[0]) {
                        return {1, 1};
                    }
                } else if (symbol.name == Parser::Rules::Rule_csequence_escape) {
                    auto data = std::any_cast<std::string>(symbol.data);
                    if (str_data.size() >= 2) 
                        return {1, 0};
                    if (str_data[0] == '\\' && str_data[1] == data[0]) {
                        return {1, 1};
                    }
                } else if (symbol.name == Parser::Rules::Rule_csequence_diapason) {
                    auto data = std::any_cast<std::vector<Parser::Rule>>(symbol.data);
                    auto first_data = std::any_cast<std::string>(data[0].data);
                    auto second_data = std::any_cast<std::string>(data[1].data);
                    if (str_data[0] >= first_data[0] && str_data[0] <= second_data[0]) {
                        return {1, 1};
                    }
                } else {
                    throw Error("Undefiened csequene symbol type\n");
                }
                return {0, 0};
            };
            while (true) {
                auto pop_res1 = pop_rules_stack_on_end(current_rule_vector_stack, current_rule_stack);
                auto pop_res2 = pop_rules_stack_on_end(current_rule_vector_stack, current_rule_stack);
                if (pop_res1 == 1) {
                    continue;
                } else if (pop_res1 == 2)
                    break;
                if (pop_res2 == 1) {
                    continue;
                } else if (pop_res2 == 2)
                    break;
                Parser::Rule current_quantifier, next_quantifier;
                auto current_it = current_rule_stack.top().pos;
                auto next_it = next_rule_stack.top().pos;
                auto current_rule = Tokens::getValueFromRule_rule(*current_it, current_quantifier);
                auto next_rule = Tokens::getValueFromRule_rule(*next_it, next_quantifier);

                char current_quantifier_char = get_quantifier(current_quantifier), next_quantifier_char = get_quantifier(next_quantifier);

                if (current_quantifier_char == '?' || next_quantifier_char == '*') {
                    current_optional = true;
                }
                if (current_quantifier_char == '?' || next_quantifier_char == '*')
                    next_optional = true;

                
                if (current_optional && next_optional) {
                    current_optional_place = current_it;
                    next_optional_place = next_it;
                }
                bool status;
                if (current_rule.name == Parser::Rules::Rule_other) {
                    status = switch_to_nested_rule(current_rule, current_rule_vector_stack, current_rule_stack);
                }
                if (next_rule.name == Parser::Rules::Rule_other) {
                    status = switch_to_nested_rule(next_rule, next_rule_vector_stack, next_rule_stack);
                }
                if (!status) {
                    success_rule_found = false;
                    break;
                }
                if (current_rule.name == Parser::Rules::Rule_csequence && next_rule.name == Parser::Rules::string) {
                    auto [loop_status, conflict] = process_csequence_with_string(current_rule, next_rule);
                    conflict_found = conflict;
                    if (loop_status)
                        continue;
                    else
                        break;
                }
                if (!Tokens::compare_rule_matching(current_it, next_it)) {
                    conflict_found = true;
                    if (!current_optional && !next_optional) {
                        break;
                    }
                }
                current_it++;
                next_it++;
            }
            if (!success_rule_found || !conflict_found)
                break;
    
            conflict_list.push_back({ current_rule_vector_stack.top(), next_rule_vector_stack.top(), current_rule_stack.top().pos, next_rule_stack.top().pos });
        }
    }
}
void Tree::resolveConflictsHelper(const std::vector<Parser::Rule> &rules) {
    ConflictsList conflict_list;
    cpuf::printf("In resolve conflicts helper\n");
    getConflictsTableForRule(rules, conflict_list);
    cpuf::printf("conflicts_list_size: %$\n", conflict_list.size());
    for (auto [lhs_rule_p, rhs_rule_p, lhs_it, rhs_it] : conflict_list) {
        lhs_rule_p->insert(lhs_it, Tokens::make_rule(Parser::Rules::Rule_not, *rhs_it));
    }
}
void Tree::resolveConflicts(Parser::Tree &tree) {
    for (auto member : tree) {
        if (member.name != Parser::Rules::Rule)
            continue;
        
        auto data = std::any_cast<obj_t>(member.data);
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