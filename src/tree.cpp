#include <sstream>
#include <algorithm>
#include <queue>
#include <tree.h>
#include <corelib.h>
#include <internal_types.h>
#include <cpuf/printf.h>
#include <list>
#include <IR/IR.h>
Tree::TreeMap& Tree::getTreeMap() {
    return treeMap;
}
void Tree::reduceRuleToUniversal(Parser::Types::Rule_data &rule_data, TreeMapMember &member) {
    // convert rule into an universal
    for (auto rule_rule : rule_data.rule) {
        auto &rule = Parser::get::Rule_rule(rule_rule);
        UniversalRule new_rule;
        if (rule.val.type() == typeid(Parser::Rule)) {
            auto &val = std::any_cast<Parser::Rule&>(rule.val);
            switch (val.name())
            {
            case Parser::Rules::Rule_name:
                new_rule.name = UniversalRules::Rule_name;
                break;
            case Parser::Rules::Rule_group:
                new_rule.name = UniversalRules::Rule_group;
                break;
            case Parser::Rules::Rule_data_block:
                new_rule.name = UniversalRules::Rule_data_block;
                break;
            default:
                throw Error("Undefined rule to be converted to universal rule");
                break;
            }
            new_rule.rule_data = std::move(val);
        } else {
            auto &val = std::any_cast<Parser::Token&>(rule.val);
            switch (val.name())
            {
            case Parser::Tokens::Rule_OP:
                new_rule.name = UniversalRules::Rule_op;
                break;
            case Parser::Tokens::Rule_CSEQUENCE:
                new_rule.name = UniversalRules::Rule_csequence;
                break;
            case Parser::Tokens::Rule_NOSPACE:
                new_rule.name = UniversalRules::Rule_nospace;
                break;
            case Parser::Tokens::Rule_ESCAPED:
                new_rule.name = UniversalRules::Rule_escaped;
                break;
            // !! TEMPORARY SOLUTION!
            case Parser::Tokens::AUTO_18:
                new_rule.name = UniversalRules::Rule_any;
                break;
            case Parser::Tokens::Rule_HEX:
                new_rule.name = UniversalRules::Rule_hex;
                break;
            case Parser::Tokens::Rule_BIN:
                new_rule.name = UniversalRules::Rule_bin;
                break;
            default:
                throw Error("Undefined token to be converted to universal rule");
                break;
            }
            new_rule.token_data = std::move(val);
        }
        new_rule.prefix = std::move(rule.prefix);
        new_rule.quantifier = std::move(rule.quantifier);
        member.rules.push_back(new_rule);
    }
}
void Tree::buildTreeMapFromRule(Parser::Rule &rule, std::vector<std::string> &fullname) {
    // use or Rule
    if (rule.name() == Parser::Rules::Rule) {
        auto &rule_data = Parser::get::Rule(rule);
        fullname.push_back(Parser::get::ID(rule_data.name));
        TreeMapMember member;
        reduceRuleToUniversal(rule_data, member);
        for (auto &rule : rule_data.nested_rules) {
            fullname.push_back(Parser::get::ID(Parser::get::Rule(rule).name));
            member.nested_rule_names.push_back(fullname);
            fullname.pop_back();
            buildTreeMapFromRule(rule, fullname);
        }
        member.data_block = std::move(rule_data.data_block);
        treeMap[fullname] = member;
        fullname.pop_back();
    }
}
void Tree::buildTreeMap(std::vector<Parser::Rule> &modules) {
    for (auto &md : modules) {
        const auto &entries = Parser::get::main(md);
        for (auto &entry : entries) {
            if (entry.type() == typeid(Parser::Rule)) {
                auto &rule = std::any_cast<Parser::Rule&>(entry);
                if (rule.name() == Parser::Rules::Rule) {
                    std::vector<std::string> fullname;
                    buildTreeMapFromRule(rule, fullname);
                }
            }
        }
    }
}
// checks rule points as result to a given name
bool Tree::checkForPointing(const std::vector<std::string> &name, const std::vector<Parser::Rule> &rules, std::unordered_set<std::vector<std::string>> &visited) {
    const auto &first = rules[0];
    auto rule = getValueFromRule_rule(first);
    if (rule.name == Parser::Rules::Rule_other) {
        auto ro = std::any_cast<rule_other>(rule.data);
        if (visited.count(ro.fullname))
            return false;
        visited.insert(ro.fullname);
        if (ro.fullname == name)
            return true;
        auto fromTree = find_token_in_tree(ro.fullname);
        if (fromTree == nullptr)
            return false;
        auto data = std::any_cast<obj_t>(fromTree->data);
        auto rules = std::any_cast<std::vector<Parser::Rule>>(corelib::map::get(data, "rule"));
        return checkForPointing(name, rules, visited);
    }
    return false;
}
void Tree::getReplacedTree(Parser::Tree &tree, std::vector<Parser::Rule> &rules, const std::vector<std::string> &name, std::vector<std::string> fullname) {
    // Create a copy of the rules to avoid modifying the original while iterating
    for (auto& member : tree) {
        if (member.name == Parser::Rules::Rule) {
            auto data = std::any_cast<obj_t>(member.data);
            auto token_name_str = std::any_cast<std::string>(std::any_cast<Parser::Rule>(corelib::map::get(data, "name")).data);
            auto token_rule = std::any_cast<std::vector<Parser::Rule>>(corelib::map::get(data, "rule"));
            fullname.push_back(token_name_str);
            if (name == fullname) {
                fullname.pop_back();
                continue;
            }
            auto matched_pos = find_token_in_rule(token_rule, rules);
            std::unordered_set<std::vector<std::string>> visited;
            if (checkForPointing(name, token_rule, visited)) {
                fullname.pop_back();
                continue;
            }
            for (auto& pos : matched_pos) {
                cpuf::printf("replacing in %$ to %$, pos: %$\n", name, fullname, pos);
                // Replace the repeated rule with a token
                auto other = make_rule(Parser::Rules::Rule_other, rule_other {token_name_str, {token_name_str}, true});
                auto newToken = make_rule(Parser::Rules::Rule_rule, obj_t {
                    { "val", other },
                    { "qualifier", make_rule() }
                });

                // Ensure valid range for erase and insert operations
                if (pos + token_rule.size() <= rules.size()) {
                    rules.erase(rules.begin() + pos, rules.begin() + pos + token_rule.size());
                    rules.insert(rules.begin() + pos, newToken);
                }
            }
            fullname.pop_back();
        }
    }
}

// Function to replace all duplicate tokens in the parse tree
void Tree::replaceDublicationsHelper(Parser::Tree &tree, std::vector<std::string> fullname, bool global) {
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
            fullname.push_back(name_str);
            replaceDublicationsHelper(nested_rules, fullname, false);
            // Get replaced tree and update the member's rules
            std::vector<std::string> fullname_grt;
            getReplacedTree(this->treeMap, rules, fullname, fullname_grt);
            corelib::map::set(data, "rule", std::any(rules));
            corelib::map::set(data, "nestedRules", std::any(nested_rules));
            member.data = data;
            fullname.pop_back();
        }
    }
}
void Tree::replaceDublications() {
    std::vector<std::string> fullname;
    replaceDublicationsHelper(treeMap, fullname, true);
}
void Tree::removeEmptyRule() {
    for (auto it = treeMap.begin(); it != treeMap.end();) {
        auto &[name, value] = *it;
        if (value.rules.size() == 0) {
            it = treeMap.erase(it);
            continue;
        }
        it++;
    }
}
void Tree::accumulateInlineNamesAndRemove(Parser::Tree& tree, std::unordered_map<std::vector<std::string>, Parser::Rule> &map, std::vector<std::string> nested) {
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
                    map[nested] = first_val;

                    nested.pop_back();
                    it = tree.erase(it);
                    continue;
                }
            }

            // Recurse with updated nested_rules and modified state
            accumulateInlineNamesAndRemove(nested_rules, map, nested);
            nested.pop_back();
            // Ensure that the data gets set back correctly after recursion
            corelib::map::set(data, "rule", std::any(rules));
            corelib::map::set(data, "nestedRules", std::any(nested_rules));
            it->data = data;
        }
        ++it;
    }
}

void Tree::inlineTokensInTable(std::unordered_map<std::vector<std::string>, Parser::Rule> &map) {
    int inlineCount;
    do {
        inlineCount = 0;
        for (auto &[key, value] : map) {
            auto name = std::any_cast<rule_other>(value.data);
            auto it = map.find(name.fullname);
            if (it != map.end()) {
                //cpuf::printf("Inlining %$ to rule %$\n", name.fullname, it->first);
                value = it->second;
                inlineCount++;
            }
        }
    } while(inlineCount > 0);
}
void Tree::inline_Rule_rule(std::vector<Parser::Rule> &rules, const std::unordered_map<std::vector<std::string>, Parser::Rule> &map, std::vector<std::string> nested) {
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
            auto find_it = map.find(fullname);

            if (find_it != map.end()) {
                corelib::map::set(rule_data, "val", std::any(find_it->second));
            }
        } else if (rule_val.name == Parser::Rules::Rule_group) {
            auto data = std::any_cast<obj_t>(rule_val.data);
            auto val = std::any_cast<std::vector<Parser::Rule>>(corelib::map::get(data, "val"));
            inline_Rule_rule(val, map, nested);
            corelib::map::set(data, "val", std::any(val));
            rule_val.data = data;
            corelib::map::set(rule_data, "val", std::any(rule_val));
        } else if (rule_val.name == Parser::Rules::Rule_op) {
            auto data = std::any_cast<std::vector<Parser::Rule>>(rule_val.data);
            inline_Rule_rule(data, map, nested);
            rule_val.data = data;
            corelib::map::set(rule_data, "val", std::any(rule_val));
        }

        rule.data = rule_data;
    }
}

void Tree::inlineTokensHelper(Parser::Tree &tree, const std::unordered_map<std::vector<std::string>, Parser::Rule> &map, std::vector<std::string> nested) {
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
            inline_Rule_rule(rules, map, nested);
            inlineTokensHelper(nested_rules, map, nested);
            nested.pop_back();

            corelib::map::set(data, "rule", std::any(rules));
            corelib::map::set(data, "nestedRules", std::any(nested_rules));
            member.data = data;
        }
    }
}
void Tree::inlineTokensHelper(Parser::Tree &tree) {
    std::unordered_map<std::vector<std::string>, Parser::Rule> map;
    accumulateInlineNamesAndRemove(tree, map, {});
    inlineTokensInTable(map);
    // for (int i = 0; i < keys.size(); i++) {
    //     print_str_vector(keys[i]);
    //     cpuf::printf(" : ");
    //     auto val = values[i];
    //     auto data = std::any_cast<obj_t>(val.data);
    //     auto name = std::any_cast<Parser::Rule>(corelib::map::get(data, "name"));
    //     cpuf::printf("%s\n", std::any_cast<std::string>(name.data));
    // }
    inlineTokensHelper(tree, map, {});
}
void Tree::inlineTokens() {
    return inlineTokensHelper(treeMap);
}

std::pair<Parser::Rule, Parser::Rule> Tree::getNewRuleAndToken(const Parser::Rule &val, const Parser::Rule &qualifier, std::vector<std::pair<Parser::Rule, Parser::Rule>> &generated) {
    auto newToken = singleRuleToToken(val, token_count);
    auto newTokenData = std::any_cast<obj_t>(newToken.data);
    auto newToken_name = std::any_cast<Parser::Rule>( corelib::map::get(newTokenData, "name") );
    auto newToken_name_str = std::any_cast<std::string>(newToken_name.data);
    auto Rule_other = make_rule(Parser::Rules::Rule_other, rule_other {newToken_name_str, {newToken_name_str}});
    auto _rule = make_rule(Parser::Rules::Rule_rule, obj_t {
        { "val", Rule_other  },
        { "qualifier", qualifier }
    });
    generated.push_back({val, _rule});
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
void Tree::getTokensFromRule_rule(Parser::Tree &tree, std::vector<Parser::Rule>& rule, std::vector<std::pair<Parser::Rule, Parser::Rule>> &generated, bool is_not_rule_rule) {
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
            auto find_it = std::find_if(generated.begin(), generated.end(), [&val, this](std::pair<Parser::Rule, Parser::Rule> pair) {
                return compare_rule(val, pair.first);
            });
            if (find_it != generated.end()) {
                // use already created literal instead of token here
                el = find_it->second;
            } else {
                // add new token instead of literal
                auto [newToken, _rule] = getNewRuleAndToken(val, qualifier, generated);
                tree.push_back(newToken);
                // use token here instead of literal
                el = _rule;
            }

        } else if (val.name == Parser::Rules::Rule_group) {
            auto group_data = std::any_cast<obj_t>(val.data);
            auto group_val = std::any_cast<std::vector<Parser::Rule>>(corelib::map::get(group_data, "val"));
            getTokensFromRule_rule(tree, group_val, generated);
            corelib::map::set(group_data, "val", std::any(group_val));
            val.data = std::any(group_data);

            corelib::map::set(el_data, "val", std::any(val));
            el.data = std::any(el_data);

        } else if (val.name == Parser::Rules::Rule_op) {
            auto rules = std::any_cast<std::vector<Parser::Rule>>(val.data);
            getTokensFromRule_rule(tree, rules, generated);
            val.data = rules;

            corelib::map::set(el_data, "val", std::any(val));
            el.data = std::any(el_data);
        }
    }
}
Parser::Tree Tree::getTokensFromRule(Parser::Rule &member, std::vector<std::pair<Parser::Rule, Parser::Rule>> &generated) {
    Parser::Tree tree;
    auto data = std::any_cast<obj_t>(member.data);
    auto name = std::any_cast<Parser::Rule>(corelib::map::get(data, "name"));
    auto name_str = std::any_cast<std::string>(name.data);
    auto rules = std::any_cast<std::vector<Parser::Rule>>(corelib::map::get(data, "rule"));
    auto nested_rule = std::any_cast<std::vector<Parser::Rule>>(corelib::map::get(data, "nestedRules"));
    if (corelib::text::isLower(name_str)) {
        getTokensFromRule_rule(treeMap, rules, generated);

        // apply changes to map
        corelib::map::set(data, "rule", std::any(rules));
    }

    literalsToTokenHelper(nested_rule, treeMap, generated);
    // apply changes to map
    corelib::map::set(data, "nestedRules", std::any(nested_rule));
    member.data = std::any(data); // apply changes to member
    return treeMap;
}
void Tree::literalsToTokenHelper(Parser::Tree& tree, Parser::Tree &treeInsert, std::vector<std::pair<Parser::Rule, Parser::Rule>> &generated)  {
    Parser::Tree tokenSeq;
    for (auto& member : tree) {
        if (member.name == Parser::Rules::Rule) {
            Parser::Tree tokenseq = getTokensFromRule(member, generated);
            tokenSeq.insert(tokenSeq.end(), tokenseq.begin(), tokenseq.end());
        }
    }
    // Append tokenSeq to the existing tree
    treeInsert.insert(treeInsert.end(), tokenSeq.begin(), tokenSeq.end());
}
void Tree::literalsToToken() {
    std::vector<std::pair<Parser::Rule, Parser::Rule>> generated;
    literalsToTokenHelper(treeMap, treeMap, generated);
}
bool Tree::sortPriority(const Parser::Rule &first, const Parser::Rule &second) {
    if (first.name == Parser::Rules::Rule_rule) {
        auto rule = getValueFromRule_rule(first);
        return sortPriority(rule, second);
    }
    if (second.name == Parser::Rules::Rule_rule) {
        auto rule = getValueFromRule_rule(second);
        return sortPriority(first, rule);
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

        return first_str > second_str;
    }
    // here is same as with strings
    if (first.name == Parser::Rules::Rule_bin && second.name == Parser::Rules::Rule_bin) {
        return std::any_cast<std::string>(first.data).size() > std::any_cast<std::string>(second.data).size();
    } 
    if (first.name == Parser::Rules::Rule_hex && second.name == Parser::Rules::Rule_hex) {
        return std::any_cast<std::string>(first.data).size() > std::any_cast<std::string>(second.data).size();
    }
    if (first.name == Parser::Rules::Rule_other && second.name == Parser::Rules::Rule_other) {
        auto first_data = std::any_cast<rule_other>(first.data);
        auto second_data = std::any_cast<rule_other>(second.data);
        auto first_token = find_token_in_tree(first_data.fullname);
        auto second_token = find_token_in_tree(second_data.fullname);
        if (first_token == nullptr || second_token == nullptr || !first_token->data.has_value() || !second_token->data.has_value()) {
            return 0;
        }
        auto first_token_data = std::any_cast<obj_t>(first_token->data);
        auto second_token_data = std::any_cast<obj_t>(second_token->data);

        auto first_rules = std::any_cast<std::vector<Parser::Rule>>(corelib::map::get(first_token_data, "rule"));
        auto second_rules = std::any_cast<std::vector<Parser::Rule>>(corelib::map::get(second_token_data, "rule"));
        for (size_t i = 0; i < first_rules.size() && i < second_rules.size(); i++) {
            auto first_rules_data = std::any_cast<obj_t>(first_rules[i].data);
            auto second_rules_data = std::any_cast<obj_t>(second_rules[i].data);
            auto first_rules_val = std::any_cast<Parser::Rule>(corelib::map::get(first_rules_data, "val"));
            auto second_rules_val = std::any_cast<Parser::Rule>(corelib::map::get(second_rules_data, "val"));
            // go to same part
            std::unordered_set<std::pair<std::vector<std::string>, std::vector<std::string>>> visited;
            if (compare_rule_matching(first_rules_val, second_rules_val, visited))
                continue;
            // found not same part, call this function to determine which should go before
            return sortPriority(first_rules[i], second_rules[i]);       
        }
        cpuf::printf("Comparing by size %$ and %$\n", first_data.fullname, second_data.fullname);
        // rules are same, compare by size
        return first_rules.size() > second_rules.size();
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
    if (first.name == Parser::Rules::Rule_group && second.name == Parser::Rules::Rule_group) {
        auto first_rules = getValueFromGroup(first);
        auto second_rules = getValueFromGroup(second);
        for (size_t i = 0; i < first_rules.size() && i < second_rules.size(); i++) {
            std::unordered_set<std::pair<std::vector<std::string>, std::vector<std::string>>> visited;
            if (compare_rule_matching(first_rules[i], second_rules[i], visited))
                continue;
            return sortPriority(first_rules[i], second_rules[i]);
        }
        // match by size
        return first_rules.size() > second_rules.size();
    }
    if (first.name == Parser::Rules::Rule_group) {
        auto val = getValueFromGroup(first);
        if (val.size() == 1)
            return sortPriority(val[0], second);
        return 0;
    } else if (second.name == Parser::Rules::Rule_group) {
        auto val = getValueFromGroup(second);
        if (val.size() == 1)
            return sortPriority(first, val[0]);
        return 0;
    }

    if (first.name == Parser::Rules::Rule_other) {
        auto first_data = std::any_cast<rule_other>(first.data);
        auto first_token = find_token_in_tree(first_data.fullname);
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
        auto second_token = find_token_in_tree(second_data.fullname);
        if (second_token == nullptr || !second_token->data.has_value()) {
            return 0;
        }
        auto second_token_data = std::any_cast<obj_t>(second_token->data);
        auto second_rules = std::any_cast<std::vector<Parser::Rule>>(corelib::map::get(second_token_data, "rule"));

        auto second_rules_data = std::any_cast<obj_t>(second_rules[0].data);
        auto second_rules_val = std::any_cast<Parser::Rule>(corelib::map::get(second_rules_data, "val"));
        return sortPriority(first, second_rules[0]);       
    }

    if (first.name == Parser::Rules::Rule_op) {
        auto dt = std::any_cast<std::vector<Parser::Rule>>(first.data);
        std::sort(dt.begin(), dt.end(), [this](auto &first, auto &second) { return this->sortPriority(first, second); });
        return sortPriority(dt.back(), second);
    } else if (second.name == Parser::Rules::Rule_op) {
        auto dt = std::any_cast<std::vector<Parser::Rule>>(second.data);
        std::sort(dt.begin(), dt.end(), [this](auto &first, auto &second) { return this->sortPriority(first, second); });
        return sortPriority(first, dt.back());
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
    } else if (first_pos != priority_order.end()) {
        return 1; // known comes before unknown
    } else if (second_pos != priority_order.end()) {
        return 0;
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
    return sortByPriority(treeMap);
}
void Tree::addSpaceToken() {
    std::vector<Parser::Rule> chars = {
        { make_rule(Parser::Rules::Rule_csequence_escape, std::string(1, ' '))  },
        { make_rule(Parser::Rules::Rule_csequence_escape, std::string(1, '\t')) },
        { make_rule(Parser::Rules::Rule_csequence_escape, std::string(1, '\n')) },
        { make_rule(Parser::Rules::Rule_csequence_escape, std::string(1, '\r')) },
        { make_rule(Parser::Rules::Rule_csequence_escape, std::string(1, '\v')) },
        { make_rule(Parser::Rules::Rule_csequence_escape, std::string(1, '\f')) },
    };
    auto csequence = make_rule(Parser::Rules::Rule_csequence, obj_t {
        {"not", false},
        {"val", chars}
    });
    auto Rule_rule = make_rule(Parser::Rules::Rule_rule, obj_t {
        { "val", csequence },
        { "qualifier", make_rule(Parser::Rules::Rule_qualifier, '+') }
    });
    auto token = make_rule(Parser::Rules::Rule, obj_t {
        {"name", make_rule(Parser::Rules::id, std::string("__WHITESPACE"))},
        {"rule", std::vector<Parser::Rule> {Rule_rule}},
        {"data_block", make_rule()},
        {"nestedRules", std::vector<Parser::Rule>()}
    });
    treeMap.push_back(token);
}
void Tree::getTokenAndRuleNamesHelper(const Parser::Tree &tree, std::vector<std::vector<std::string>> &tokens, std::vector<std::vector<std::string>> &rules, std::unordered_set<std::vector<std::string>> &seen, std::vector<std::string> &fullname) {   
    for (auto el : tree) {
        if (el.name == Parser::Rules::Rule) {
            auto data = std::any_cast<obj_t>(el.data);
            auto name = std::any_cast<Parser::Rule>(corelib::map::get(data, "name"));
            auto name_str = std::any_cast<std::string>(name.data);
            auto nested_rules = std::any_cast<std::vector<Parser::Rule>>(corelib::map::get(data, "nestedRules"));

            // Construct the full rule name properly
            fullname.push_back(name_str);

            // Categorize as token or rule
            if (seen.count(fullname) == 0) {
                seen.insert(fullname);
                if (corelib::text::isUpper(name_str)) {
                    tokens.push_back(fullname);
                } else {
                    rules.push_back(fullname);
                }
            }


            // Recursively process nested rules with the updated name
            getTokenAndRuleNamesHelper(nested_rules, tokens, rules, seen, fullname);
            fullname.pop_back();
        }
    }
}
std::pair<std::vector<std::vector<std::string>>, std::vector<std::vector<std::string>>> Tree::getTokenAndRuleNames() {
    std::vector<std::string> fullname;
    std::vector<std::vector<std::string>> tokens;
    std::vector<std::vector<std::string>> rules;
    std::unordered_set<std::vector<std::string>> seen;
    getTokenAndRuleNamesHelper(treeMap, tokens, rules, seen, fullname);
    return {tokens, rules};
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
    for (auto el : treeMap) {
        if (el.name != Parser::Rules::use)
            continue;
        
        auto res = get_use_data(el);
        for (auto [key, value] : res) {
            result[key] = value;
        }
    }
    return result;
}
void Tree::accamulateUsePlaces(std::vector<Parser::Rule>& rules, use_place_table &use_places, std::vector<std::string> &fullname) {
    size_t index;
    for (auto &el : rules) {
        if (!el.data.has_value())
            continue;
        auto dt = std::any_cast<obj_t>(el.data);
        auto val = std::any_cast<Parser::Rule>(corelib::map::get(dt, "val"));
        if (val.name == Parser::Rules::Rule_other) {
            auto data = std::any_cast<rule_other>(val.data);
            use_places[data.fullname].push_back({index, fullname});
        } else if (val.name == Parser::Rules::Rule_group) {
            auto data = std::any_cast<obj_t>(val.data);
            auto rules = std::any_cast<std::vector<Parser::Rule>>(corelib::map::get(data, "val"));
            accamulateUsePlaces(rules, use_places, fullname);
        } else if (val.name == Parser::Rules::Rule_op) {
            auto data = std::any_cast<std::vector<Parser::Rule>>(val.data);
            accamulateUsePlaces(data, use_places, fullname);
        }
        index++;
    }
}
void Tree::getUsePlacesTableHelper(Parser::Tree &tree, use_place_table &use_places, std::vector<std::string> &fullname) {
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
Tree::use_place_table Tree::getUsePlacesTable() {
    use_place_table use_places;
    std::vector<std::string> fullname;
    getUsePlacesTableHelper(treeMap, use_places, fullname);
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

void Tree::getTokensForLexer(Parser::Tree &tree, use_place_table &use_places, std::vector<Parser::Rule> &rule_op, std::vector<std::string> &fullname) {
    for (auto &member : tree) {
        if (member.name != Parser::Rules::Rule) 
            continue;
        auto data = std::any_cast<obj_t>(member.data);
        auto name = std::any_cast<Parser::Rule>(corelib::map::get(data, "name"));
        auto name_str = std::any_cast<std::string>(name.data);
        auto nested_rules = std::any_cast<std::vector<Parser::Rule>>(corelib::map::get(data, "nestedRules"));
        fullname.push_back(name_str);
        if (corelib::text::isUpper(name_str)) {
            if (fullname.size() != 1) {
                auto data_in_use_place = use_places.find(fullname);
                bool add = false;
                if (data_in_use_place != use_places.end()) {
                    for (auto &fn : data_in_use_place->second) {
                        if (corelib::text::isLower(fn.name.back())) {
                            add = true;
                            break;
                        }
                    }
                } else {
                    cpuf::printf("could not find data for %$\n", fullname);
                }
                if (add) {
                    // if not found fall back to add the token
                    auto _rule_other = make_rule(Parser::Rules::Rule_other, rule_other {name_str, fullname});
                    auto rule_rule = make_rule(Parser::Rules::Rule_rule, obj_t {
                        {"val", _rule_other},
                        {"qualifier", make_rule(Parser::Rules::Rule_qualifier)}
                    });
                    rule_op.push_back(rule_rule);
                }
            } else {
                // if not found fall back to add the token
                auto _rule_other = make_rule(Parser::Rules::Rule_other, rule_other {name_str, fullname});
                auto rule_rule = make_rule(Parser::Rules::Rule_rule, obj_t {
                    {"val", _rule_other},
                    {"qualifier", make_rule(Parser::Rules::Rule_qualifier)}
                });
                rule_op.push_back(rule_rule);
            }
        }

        getTokensForLexer(nested_rules, use_places, rule_op, fullname);
        fullname.pop_back();
    }
}
lexer_code Tree::getCodeForLexer(use_place_table use_places) {
    std::vector<Parser::Rule> rule_op;
    std::vector<std::string> fullname;
    getTokensForLexer(treeMap, use_places, rule_op, fullname);
    auto rule_op_rule_rule = make_rule(Parser::Rules::Rule_rule, obj_t {
        {"val", make_rule(Parser::Rules::Rule_op, rule_op)},
        {"qualifier", make_rule(Parser::Rules::Rule_qualifier)}
    });
    std::vector<Parser::Rule> rule_op2 = {rule_op_rule_rule};
    sortByPriorityHelper(rule_op2);
    // auto rule = make_rule(Parser::Rules::Rule, obj_t {
    //     {"name", make_rule(Parser::Rules::id, std::string("makeTokens"))},
    //     {"rule", std::vector<Parser::Rule>{rule_rule}},
    //     {"data_block", make_rule()},
    //     {"nestedRules", std::vector<Parser::Rule>()}
    // });
    //Parser::Tree tree = {rule};

    // auto rule_data = std::any_cast<obj_t>(rule.data);
    // auto new_rule_rule = std::any_cast<std::vector<Parser::Rule>>(corelib::map::get(rule_data, "rule"))[0];
    LLIR code(this->treeMap, rule_op2);
    code.setIsToken(true);
    auto success_var = code.makeIR();
    code.pop(); // remove space skip
    code.push_begin({LLIR::types::TOKEN});
    code.push({LLIR::types::RULE_END});
    code.optimizeIR();
    return {code, success_var[0]};
}
std::vector<Parser::Rule> Tree::getFirstSet(const Parser::Rule &rule) {
    if (rule.name == Parser::Rules::Rule_rule) {
        auto rule_rule = getValueFromRule_rule(rule);
        return getFirstSet(rule_rule);
    }
    std::vector<Parser::Rule> first;
    switch (rule.name) {
        case Parser::Rules::Rule_op:
        case Parser::Rules::Rule_group:
        {
            auto options = std::any_cast<std::vector<Parser::Rule>>(rule.data);
            for (auto option : options) {
                auto first_set = getFirstSet(option);
                first.insert(first.end(), first_set.begin(), first_set.end());
            }
            break;
        }
        case Parser::Rules::Rule_other:
        {
            auto ro = std::any_cast<rule_other>(rule.data);
            const auto token = find_token_in_tree(ro.fullname);
            auto data = std::any_cast<obj_t>(token->data);
            auto rules = std::any_cast<std::vector<Parser::Rule>>(corelib::map::get(data, "rule"));
            for (const auto &rule_rule : rules) {
                Parser::Rule quantifier;
                char quantifier_char = '\0';
                const auto rule = getValueFromRule_rule(rule_rule, quantifier);
                if (!quantifier.data.has_value()) {
                    quantifier_char = std::any_cast<char>(quantifier.data);
                }
                auto set = getFirstSet(rule);
                first.insert(first.end(), set.begin(), set.end());
                if (quantifier_char == '?' || quantifier_char == '*')
                    continue;
                break;
            }
        }
        default:
            first.push_back(rule);
    }
    return first;
}
// void Tree::insertNot(Parser::Rule &current, const Parser::Rule &next) {
//     Parser::Rule current, next;
//     if (current.name == Parser::Rules::Rule_other) {
//         auto rule = getValueFromRule_rule(current);
//         insertNot(rule, next);
//         return;
//     }
//     if (next.name == Parser::Rules::Rule_other) {
//         auto rule = getValueFromRule_rule(next);
//         insertNot(current, rule);
//         return;
//     }
//     auto& current_data = std::any_cast<rule_other&>(current.data);
//     auto& next_data = std::any_cast<rule_other&>(next.data);
//     cpuf::printf("%$ with %$\n", current_data.fullname, next_data.fullname);
//     auto current_rule = find_token_in_tree(tree, current_data.fullname);
//     auto next_rule = find_token_in_tree(tree, next_data.fullname);
//     if (current_rule == nullptr || next_rule == nullptr)
//         return;
//     auto& current_rule_data = std::any_cast<obj_t&>(current_rule->data);
//     auto& next_rule_data = std::any_cast<obj_t&>(next_rule->data);

//     auto current_rule_rules = std::any_cast<std::vector<Parser::Rule>&>(corelib::map::get(current_rule_data, "rule"));
//     auto next_rule_rules = std::any_cast<std::vector<Parser::Rule>&>(corelib::map::get(next_rule_data, "rule"));

//     if (current_rule_rules.empty() || next_rule_rules.empty())
//         return;

//     if (!compare_rule_matching(current_rule_rules.begin(), next_rule_rules.begin())) {
//         Parser::Rule currentx, nextx;
//         if (current_rule_rules[0].name == Parser::Rules::Rule_rule) {
//             auto data = std::any_cast<obj_t>(current_rule_rules[0].data);
//             currentx = std::any_cast<Parser::Rule&>(corelib::map::get(data, "val"));

//         }
//         if (next_rule_rules[0].name == Parser::Rules::Rule_rule) {
//             auto data = std::any_cast<obj_t>(next_rule_rules[0].data);
//             nextx = std::any_cast<Parser::Rule>(corelib::map::get(data, "val"));
//         }
//         cpuf::printf("current_rule_rules[0]: %s, next_rule_rules[0]: %s\n", Parser::RulesToString(currentx.name), Parser::RulesToString(nextx.name));
//         cpuf:printf("First Compare unsucess\n");
//         return;
//     }
//     auto get_quantifier = [](const Parser::Rule &quantifier) {
//         if (!quantifier.empty())
//             return std::any_cast<char>(quantifier.data);
//         return '\0';
//     };
//     for (size_t i = 0; i < current_rule_rules.size() && i < next_rule_rules.size(); i++) {
//         auto current_rule_rule = current_rule_rules[i];
//         auto next_rule_rule = next_rule_rules[i];
//         Parser::Rule current, next;
//         if (current_rule_rule.name == Parser::Rules::Rule_rule) {
//             current = getValueFromRule_rule(current_rule_rule);
//         } else current = current_rule_rule;
//         if (next_rule_rule.name == Parser::Rules::Rule_rule) {
//             next = getValueFromRule_rule(next_rule_rule);
//         } else next = next_rule_rule;

//     }
// }
void Tree::getConflictsTableForRule(const std::vector<Parser::Rule> &rules, ConflictsList &conflict_list) {
    if (rules.empty())
        return;

    for (auto it = rules.begin(); it != rules.end() - 1; it++) {
        const auto& current_rule_rule = *it;
        bool optional_quantifier = true;
        for (auto next_it = it + 1; next_it != rules.end() && optional_quantifier; next_it++) {
 
            //insertNot(current_rule_rules, next_rule_rules);
        }
    }
}
void Tree::resolveConflictsHelper(const std::vector<Parser::Rule> &rules) {
    ConflictsList conflict_list;
    cpuf::printf("In resolve conflicts helper\n");
    getConflictsTableForRule(rules, conflict_list);
    cpuf::printf("conflicts_list_size: %$\n", conflict_list.size());
    for (auto [lhs_rule_p, rhs_rule_p, lhs_it, rhs_it] : conflict_list) {
        lhs_rule_p->insert(lhs_it, make_rule(Parser::Rules::Rule_not, *rhs_it));
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
    resolveConflicts(treeMap);
}