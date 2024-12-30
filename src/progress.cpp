#include <progress.h>
#include <corelib.h>
#include <internal_types.h>
#include <token_management.h>
#include <cpuf/printf.h>

void literalsToToken(Parser::Tree& tree) {
    for (int i = 0; i < tree.size(); i++) {
        auto member = tree[i];
        cpuf::printf("i: %d\n", i);
        if (member.name == Parser::Rules::Rule) {
            auto data = std::any_cast<obj_t>(member.data);
            auto name = std::any_cast<Parser::Rule>(corelib::map::get(data, "name"));
            auto name_str = std::any_cast<std::string>(name.data);
            auto rule = std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(data, "rule"));
            if (corelib::text::startsWithRange(name_str, 'a', 'z')) {
                // is rule
                for (int j = 0; j < rule.size(); j++) {
                    auto el = rule[i];
                    auto el_data = std::any_cast<obj_t>(el.data);
                    auto val = std::any_cast<Parser::Rule>(corelib::map::get(el_data, "val"));
                    auto qualifier = std::any_cast<::Parser::Rule>(corelib::map::get(el_data, "qualifier"));

                    if (val.name == Parser::Rules::string || val.name == Parser::Rules::Rule_hex || val.name == Parser::Rules::Rule_bin) {
                        // convert into token & add here token instead o string
                        auto newToken = Tokens::singleRuleToToken(val);
                        // use token here instead of literal
                        printf("Before segmentation fail\n");
                        std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(data, "rule"))[j] = newToken;
                    }
                }   

            }
        }
    }
}