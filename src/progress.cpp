#include <sstream>
#include <algorithm>
#include <progress.h>
#include <corelib.h>
#include <internal_types.h>
#include <token_management.h>
#include <cpuf/printf.h>
// this function should replace all token dublications 
void replaceDublications(Parser::Tree& tree) {
    for (auto& member  : tree) {
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
            for (auto& pos : matched_pos) {
                // replace here with token the repeated rule
                auto tokenId = Tokens::make_rule(Parser::Rules::id, token_name_str);
                auto other = Tokens::make_rule(Parser::Rules::Rule_other, obj_t {
                    { "is_nested", false },
                    { "name", tokenId },
                    { "nested_name", std::vector<Parser::Rule> {} }
                });
                auto newToken = Tokens::make_rule(Parser::Rules::Rule_rule, obj_t {
                    {"val", other },
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
        for (int i = 0; i < rule.size(); i++) {
            auto el = rule[i];
            if (!el.data.has_value())
                continue;
            auto el_data = std::any_cast<obj_t>(el.data);
            auto val = std::any_cast<Parser::Rule>(corelib::map::get(el_data, "val"));
            auto qualifier = std::any_cast<::Parser::Rule>(corelib::map::get(el_data, "qualifier"));
            if (val.name == Parser::Rules::string || val.name == Parser::Rules::Rule_hex || val.name == Parser::Rules::Rule_bin) {
                // convert into token & add here token instead o string
                auto newToken = Tokens::singleRuleToToken(val);
                auto newTokenData = std::any_cast<obj_t>(newToken.data);
                auto newToken_name = std::any_cast<Parser::Rule>( corelib::map::get(newTokenData, "name") );
                auto newToken_name_str = std::any_cast<std::string>(newToken_name.data);
                auto id = Tokens::make_rule(Parser::Rules::id, newToken_name_str);
                auto Rule_other = Tokens::make_rule(Parser::Rules::Rule_other, obj_t {
                    { "is_nested", false },
                    { "name", id },
                    { "nested_names", arr_t<Parser::Rule>() }
                });
                auto _rule = Tokens::make_rule(Parser::Rules::Rule_rule, obj_t {
                    { "val", Rule_other  },
                    { "qualfier", qualifier }
                });
                tree.push_back(newToken);
                // use token here instead of literal
                rule[i] = _rule;
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
bool compareByPriority(Parser::Rule first, Parser::Rule second) {
    auto first_data = std::any_cast<obj_t>(first.data);
    auto second_data = std::any_cast<obj_t>(second.data);
    auto first_val = std::any_cast<Parser::Rule>(corelib::map::get(first_data, "val"));
    auto second_val = std::any_cast<Parser::Rule>(corelib::map::get(second_data, "val"));
    if (first_val.name != Parser::Rules::Rule_other || second_val.name != Parser::Rules::Rule_other)
        throw Error("Value is not identifier, name: %s, %s", Parser::RulesToString(first_val.name), Parser::RulesToString(second_val.name));
    return true;
}
void sortByPriority(Parser::Tree &tree)  {
    for (auto &member : tree) {
        if (member.name == Parser::Rules::Rule) {
            auto data = std::any_cast<obj_t>(member.data);
            auto name = std::any_cast<Parser::Rule>(corelib::map::get(data, "name"));
            auto name_str = std::any_cast<std::string>(name.data);
            auto rules = std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(data, "rule"));
            if (corelib::text::startsWithRange(name_str, 'a', 'z')) {
                // is a rule
                std::vector<int> priority;
                for (int i = 0; i < rules.size(); i++) {
                    std::sort(rules.begin(), rules.end(), compareByPriority);
                }
            }
        }
    }
} 