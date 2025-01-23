#include <sstream>
#include <algorithm>
#include <queue>
#include <progress.h>
#include <corelib.h>
#include <internal_types.h>
#include <token_management.h>
#include <cpuf/printf.h>
// this function should replace all token dublications 
void replaceDublications(Parser::Tree& tree) {
    for (auto& member : tree) {
        if (member.name == Parser::Rules::Rule) {
            auto data = std::any_cast<obj_t>(member.data);
            auto rules = std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(data, "rule"));
            auto newRules = getReplacedTree(tree, rules);
            corelib::map::set(data, "rule", std::any(newRules));
            member.data = data;
        }
    }
}
Parser::Tree getReplacedTree(Parser::Tree& tree, Parser::Tree& rules) {
    for (auto& member : tree) {
        if (member.name == Parser::Rules::Rule) {
            auto data = std::any_cast<obj_t>(member.data);
            auto token_name_str = std::any_cast<std::string>(std::any_cast<Parser::Rule>(corelib::map::get(data, "name")).data);
            auto token_rule = std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(data, "rule"));
            auto nested_rule = std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(data, "nestedRules"));
            auto matched_pos = Tokens::find_token_in_rule(token_rule, rules);
            // for (auto el : token_rule) {
            //     auto dt = std::any_cast<obj_t>(el.data);
            //     cpuf::printf("el name: %s\n", Parser::RulesToString(std::any_cast<Parser::Rule>(corelib::map::get(dt, "val")).name));
            // }
            for (auto& pos : matched_pos) {
                // replace here with token the repeated rule
                auto tokenId = Tokens::make_rule(Parser::Rules::id, token_name_str);
                auto other = Tokens::make_rule(Parser::Rules::Rule_other, obj_t {
                    { "is_nested", false },
                    { "name", tokenId },
                    { "nested_name", std::vector<Parser::Rule> {} },
                });
                auto newToken = Tokens::make_rule(Parser::Rules::Rule_rule, obj_t {
                    { "val", other },
                    { "qualifier", Tokens::make_rule() }
                });
                rules.erase(rules.begin() + pos, rules.begin() + pos + token_rule.size());
                rules.insert(rules.begin() + pos, newToken);
            }
        }
    }
    return rules;
}
Parser::Tree getTokensFromRule(Parser::Rule &member) {
    Parser::Tree tree;
    auto data = std::any_cast<obj_t>(member.data);
    auto name = std::any_cast<Parser::Rule>(corelib::map::get(data, "name"));
    auto name_str = std::any_cast<std::string>(name.data);
    auto rule = std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(data, "rule"));
    auto nested_rule = std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(data, "nestedRules"));
    if (corelib::text::startsWithRange(name_str, 'a', 'z')) {
        // is rule
        for (auto &el : rule) {
            if (!el.data.has_value())
                continue;
            auto el_data = std::any_cast<obj_t>(el.data);
            auto val = std::any_cast<Parser::Rule>(corelib::map::get(el_data, "val"));
            auto qualifier = std::any_cast<::Parser::Rule>(corelib::map::get(el_data, "qualifier"));
            if (
                val.name == Parser::Rules::string || val.name == Parser::Rules::Rule_hex || val.name == Parser::Rules::Rule_bin || 
                val.name == Parser::Rules::Rule_csequence || val.name == Parser::Rules::Rule_escaped || val.name == Parser::Rules::Rule_any
            )
            {
                // convert into token & add here token instead of string
                auto newToken = Tokens::singleRuleToToken(val);
                auto newTokenData = std::any_cast<obj_t>(newToken.data);
                auto newToken_name = std::any_cast<Parser::Rule>( corelib::map::get(newTokenData, "name") );
                auto newToken_name_str = std::any_cast<std::string>(newToken_name.data);
                auto id = Tokens::make_rule(Parser::Rules::id, newToken_name_str);
                auto Rule_other = Tokens::make_rule(Parser::Rules::Rule_other, obj_t {
                    { "is_nested", false },
                    { "name", id },
                    { "nested_name", arr_t<Parser::Rule>() }
                });
                auto _rule = Tokens::make_rule(Parser::Rules::Rule_rule, obj_t {
                    { "val", Rule_other  },
                    { "qualifier", qualifier }
                });
                tree.push_back(newToken);
                // use token here instead of literal
                el = _rule;
            }
        }

    }
    corelib::map::set(data, "rule", std::any(rule));
    member.data = std::any(data);
    literalsToToken(nested_rule);
    return tree;
}
void literalsToToken(Parser::Tree& tree) {
    Parser::Tree tokenSeq;
    for (auto& member : tree) {
        if (member.name == Parser::Rules::Rule) {
            Parser::Tree tokenseq = getTokensFromRule(member);
            tokenSeq.insert(tokenSeq.end(), tokenseq.begin(), tokenseq.end());
        }
    }
    // Append tokenSeq to the existing tree
    tree.insert(tree.end(), tokenSeq.begin(), tokenSeq.end());
}

struct priority_t {
    int pos;
    Parser::Rule rule;
};
bool sortPriority(priority_t first, priority_t second);
static arr_t<Parser::Rule> getValueFromGroup(Parser::Rule first) {
    auto first_data = std::any_cast<obj_t>(first.data);
    return std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(first_data, "val"));
}
static bool processGroup_helper(arr_t<Parser::Rule> group, Parser::Rule second) {

    if (second.name == Parser::Rules::Rule_group) {
        auto data = std::any_cast<obj_t>(second.data);  
        auto val = std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(data, "val"));
        return group.size() < val.size();
    }
    if (second.name == Parser::Rules::string)
        return 1;
    return sortPriority({0, group[0]}, {0, Tokens::make_rule(Parser::Rules::Rule_rule, obj_t {{ "val", second }}) });
}
static Parser::Rule processNestedRuleHelper(arr_t<Parser::Rule> nestedName, obj_t ruleother_data, Parser::Rule token) {
    while(!nestedName.empty()) {
        auto nested_rules = std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(ruleother_data, "nestedRules"));
        auto new_token = Tokens::find_token_in_tree(nested_rules, nestedName[0]);
        nestedName.erase(nestedName.begin());
    }
    return token;
}
extern Parser::Tree tree;
bool sortPriority(priority_t first, priority_t second) {

    auto first_data = std::any_cast<obj_t>(first.rule.data);
    auto first_val = std::any_cast<Parser::Rule>(corelib::map::get(first_data, "val"));
    auto second_data = std::any_cast<obj_t>(second.rule.data);
    auto second_val = std::any_cast<Parser::Rule>(corelib::map::get(second_data, "val"));
    if (first_val.name == Parser::Rules::string && second_val.name == Parser::Rules::string) {
        // if first value size is lower second, put the second before
        // this ensure correct match of values
        return std::any_cast<std::string>(first_val.data).size() < std::any_cast<std::string>(second_val.data).size(); 
    }
    // here is same as with strings
    if (first_val.name == Parser::Rules::Rule_bin && second_val.name == Parser::Rules::Rule_bin) {
        return std::any_cast<std::string>(first_val.data).size() < std::any_cast<std::string>(second_val.data).size();
    } 
    if (first_val.name == Parser::Rules::Rule_hex && second_val.name == Parser::Rules::Rule_hex) {
        return std::any_cast<std::string>(first_val.data).size() < std::any_cast<std::string>(second_val.data).size();
    }
    if (first_val.name == Parser::Rules::Rule_other && second_val.name == Parser::Rules::Rule_other) {
        auto first_ruleother_data = std::any_cast<obj_t>(first_val.data);
        auto second_ruleother_data = std::any_cast<obj_t>(second_val.data);

        auto first_name = std::any_cast<Parser::Rule>(corelib::map::get(first_ruleother_data, "name"));
        auto second_name = std::any_cast<Parser::Rule>(corelib::map::get(first_ruleother_data, "name"));

        auto first_nested_name = std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(first_ruleother_data, "nested_name"));
        auto second_nested_name = std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(second_ruleother_data, "nested_name"));
        auto first_token = Tokens::find_token_in_tree(tree, first_name);
        auto second_token = Tokens::find_token_in_tree(tree, second_name);
        if (!first_token.data.has_value() || !second_token.data.has_value()) {
            return 0;
        }
        first_token = processNestedRuleHelper(first_nested_name, first_ruleother_data, first_token);
        second_token = processNestedRuleHelper(second_nested_name, second_ruleother_data, second_token);

        auto first_token_data = std::any_cast<obj_t>(first_token.data);
        auto second_token_data = std::any_cast<obj_t>(second_token.data);

        auto first_rules = std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(first_token_data, "rule"));
        auto second_rules = std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(second_token_data, "rule"));
        
        int i;
        for (i = 0; i < first_rules.size(); i++) {
            auto first_rules_data = std::any_cast<obj_t>(first_rules[i].data);
            auto second_rules_data = std::any_cast<obj_t>(second_rules[i].data);
            auto first_rules_val = std::any_cast<Parser::Rule>(corelib::map::get(first_rules_data, "val"));
            auto second_rules_val = std::any_cast<Parser::Rule>(corelib::map::get(first_rules_data, "val"));
            // go to same part
            if (Tokens::compare_rule(first_rules_val, second_rules_val))
                continue;
            // found not same part, call this function to determine which should go before
            return sortPriority({0, first_rules_val}, {1, second_rules_val});            
        }
        // rules are same, do nothing
        return 0;
    }
    // if non above is true but the value kind is same, remain values in their order
    if (first_val.name == second_val.name)
        return 0;
    // string goes before csequence
    if (first_val.name == Parser::Rules::string && second_val.name == Parser::Rules::Rule_csequence)
        return 0;
    else if (first_val.name == Parser::Rules::Rule_csequence && second_val.name == Parser::Rules::string)
        return 1;
    // string goes before escape
    if (first_val.name == Parser::Rules::string && second_val.name == Parser::Rules::Rule_escaped)
        return 0;
    else if (first_val.name == Parser::Rules::Rule_escaped && second_val.name == Parser::Rules::string)
        return 1;
    // any goes the last one
    if (first_val.name == Parser::Rules::Rule_any)
        return 1;
    else if (second_val.name == Parser::Rules::Rule_any)
        return 0;
    // literals go before identifier
    if (first_val.name == Parser::Rules::Rule_other && (second_val.name == Parser::Rules::string || second_val.name == Parser::Rules::Rule_csequence_escape))
        return 1;
    else if ((first_val.name == Parser::Rules::string || first_val.name == Parser::Rules::Rule_csequence) && second_val.name == Parser::Rules::Rule_other) 
        return 0;
    if (first_val.name == Parser::Rules::Rule_group) {
        return processGroup_helper(getValueFromGroup(first_val), second_val);
    }    
    if (second_val.name == Parser::Rules::Rule_group) {
        return !processGroup_helper(getValueFromGroup(second_val), first_val);
    }
    return 0;
}
void sortByPriority(Parser::Tree &tree)  {
    int i = 0;
    for (auto &member : tree) {
        if (member.name == Parser::Rules::Rule) {
            auto data = std::any_cast<obj_t>(member.data);
            auto name = std::any_cast<Parser::Rule>(corelib::map::get(data, "name"));
            auto name_str = std::any_cast<std::string>(name.data);
            auto rules = std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(data, "rule"));
            auto nested_rules = std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(data, "nestedRules"));
            
            std::vector<priority_t> priority;
            bool have_op = false;
            bool prev_op = false;
            for (int i = 0; i < rules.size(); i++) {
                auto data = std::any_cast<obj_t>(rules[i].data);
                auto val = std::any_cast<Parser::Rule>(corelib::map::get(data, "val"));
                // apply the sort for groups
                // note this does not have relation to the sortion itself
                if (val.name == Parser::Rules::Rule_group) {
                    auto data = std::any_cast<obj_t>(val.data);
                    auto this_val = std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(data, "val"));
                    sortByPriority(this_val);
                    
                    // assign result to the current group value
                    corelib::map::set(data, "val", std::any(this_val));
                    val.data = data;
                }

                // sort process
                if (val.name == Parser::Rules::Rule_op)
                {
                    if (!have_op)
                        priority.push_back({i - 1, rules[i - 1]});

                    prev_op = true;
                    have_op = true;
                } else if (prev_op) 
                {
                    prev_op = false;
                    priority.push_back({i, rules[i]});
                } else 
                {
                    have_op = false;
                }
            }
            std::stable_sort(priority.begin(), priority.end(), sortPriority);
            while(priority.size() != 0) {
                auto min = std::min_element(priority.begin(), priority.end(), [](priority_t first, priority_t second) { return first.pos < second.pos; });
                rules[min->pos] = priority[0].rule;
                // pop first element
                priority.erase(priority.begin());
            }

            //LOG CHANGES
            // cpuf::printf("result: \n");
            // for (auto el : rules) {
            //     auto first_data = std::any_cast<obj_t>(el.data);
            //     auto first_val = std::any_cast<Parser::Rule>(corelib::map::get(first_data, "val"));
            //     cpuf::printf("\t%s\n", Parser::RulesToString(first_val.name));
            // }

            // sort nested rule
            sortByPriority(nested_rules);
            corelib::map::set(data, "nestedRules", std::any(nested_rules));
            // apply changes

            corelib::map::set(data, "rule", std::any(rules));
            member.data = data;
        }
        i++;
    }
} 