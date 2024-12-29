#include <progress.h>
#include <internal_types.h>
#include <core/tokens.h>
#include <core/text.h>
#include <cpuf/printf.h>

void literalsToToken(Parser::Tree& tree) {
    for (int i = 0; i < tree.size(); i++) {
        auto member = tree[i];
        if (member.name == Parser::Rules::Rule) {
            cpuf::printf("1\n");
            auto data = std::any_cast<obj_t>(member.data);
            cpuf::printf("2, hasName: %d\n", data.count("rule"));
            auto name = std::any_cast<Parser::Rule>(data["name"]);
            auto name_str = std::any_cast<std::string>(name.data);
            cpuf::printf("3\n");
            auto rule = std::any_cast<arr_t<Parser::Rule>>(data["rule"]);
            if (core::startsWithRange(name_str, 'a', 'z')) {
                // is rule
                for (int j = 0; j < rule.size(); j++) {
                    auto el = rule[i];
                    auto el_data = std::any_cast<obj_t>(el.data);
                    auto val = std::any_cast<Parser::Rule>(el_data["val"]);
                    auto qualifier = std::any_cast<::Parser::Rule>(el_data["qualifier"]);

                    if (val.name == Parser::Rules::string || val.name == Parser::Rules::Rule_hex || val.name == Parser::Rules::Rule_bin) {
                        // convert into token & add here token instead o string
                        auto newToken = Tokens::singleRuleToToken(val);
                        // use token here instead of literal
                        std::any_cast<arr_t<Parser::Rule>>(data["rule"])[j] = newToken;
                    }
                }   

            }
        }
    }
}