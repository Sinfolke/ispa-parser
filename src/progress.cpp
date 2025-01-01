#include <progress.h>
#include <corelib.h>
#include <internal_types.h>
#include <token_management.h>
#include <cpuf/printf.h>
// this function should replace all token dublications 
void replaceDublications(Parser::Tree tree) {
    for (int i = 0; i < tree.size(); i++) {
        auto member = tree[i];
        if (member.name == Parser::Rules::Rule) {
            auto data = std::any_cast<obj_t>(member.data);
            auto rules = std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(data, "rule"));
            auto newRules = getReplacedTree(tree, rules);
        }
    }
}
Parser::Tree getReplacedTree(Parser::Tree tree, Parser::Tree rules) {
    for (int i = 0; i < tree.size(); i++) {
        auto member = tree[i];
        if (member.name == Parser::Rules::Rule) {
            auto data = std::any_cast<obj_t>(member.data);
            auto name_str = std::any_cast<std::string>(std::any_cast<Parser::Rule>(corelib::map::get(data, "name")).data);
            auto token_rule = std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(data, "rule"));
            auto nested_rule = std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(data, "nestedRules"));
            if (corelib::text::startsWithRange(name_str, 'A', 'Z')) {
                compare_rules(token_rule, rules);
            }
            getReplacedTree(nested_rule, rules);
        }

    }
}
Parser::Tree getTokensFromRule(Parser::Rule member) {
    Parser::Tree tree;
    auto data = std::any_cast<obj_t>(member.data);
    auto name = std::any_cast<Parser::Rule>(corelib::map::get(data, "name"));
    auto name_str = std::any_cast<std::string>(name.data);
    auto rule = std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(data, "rule"));
    auto nested_rule = std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(data, "nestedRules"));
    if (corelib::text::startsWithRange(name_str, 'a', 'z')) {
        // is rule
        for (int j = 0; j < rule.size(); j++) {
            auto el = rule[j];
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
                tree.push_back(newToken);
                // use token here instead of literal
                std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(data, "rule"))[j] = id;
            }
        }

    }
    literalsToToken(nested_rule);
    return tree;
}
void literalsToToken(Parser::Tree& tree) {
    Parser::Tree tokenSeq;
    for (int i = 0; i < tree.size(); i++) {
        auto member = tree[i];
        if (member.name == Parser::Rules::Rule) {
            Parser::Tree tokenseq = getTokensFromRule(member);
            tokenSeq.insert(tokenSeq.end(), tokenseq.begin(), tokenseq.end());
        }
    }
    // Append tokenSeq to the existing tree
    tree.insert(tree.end(), tokenSeq.begin(), tokenSeq.end());
}
// replace all dublicated tokens
// void removeDublicateTokens(Parser::Tree& tree) {
//     std::unordered_map<std::string, Parser::Rule> binds;
//     std::unordered_map<std::string, std::string> dublicated;
//     for (const auto member : tree) {
//         auto data = std::any_cast<obj_t>(member.data);
//         auto name = std::any_cast<Parser::Rule>(corelib::map::get(data, "name"));
//         auto name_str = std::any_cast<std::string>(name.data);
//         auto rule = std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(data, "rule"));
//         auto nested_rule = std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(data, "nestedRules"));
//         if (corelib::text::startsWithRange(name_str, 'A', 'Z')) {}
//     }
// }