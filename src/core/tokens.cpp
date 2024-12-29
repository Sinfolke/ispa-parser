#include <core/tokens.h>
#include <core/text.h>
#include <string>
#include <vector>
#include <unordered_map>
#include <any>

static auto count = 0;

namespace Tokens {
    ::Parser::Rule ruleToToken(::Parser::Rule input) {
        // Construct a token here
        std::vector<::Parser::Rule> rule {input};
        ::Parser::Rule data_block = {
            0, nullptr, nullptr, Parser::Rules::Rule_data_block, // data block
            ::Parser::Rule { 
                0, nullptr, nullptr, Parser::Rules::accessor, std::unordered_map<const char*, std::any> {  // data - accessor
                    { "first", ::Parser::Rule { 
                            0, nullptr, nullptr, Parser::Rules::accessor_all, ::Parser::Rule {
                                0, nullptr, nullptr, Parser::Rules::accessors_element, ::Parser::Rule {
                                    0, nullptr, nullptr, Parser::Rules::number, std::unordered_map<const char*, std::any> {
                                        { "sign", "" },
                                        { "main", "1" },
                                        { "main_n", 1 },
                                        { "point", "" },
                                        { "dec", "" },
                                        { "dev_n", 0 }
                                    }
                                }
                            } 
                        } 
                    }
                }
            }
        };

        std::unordered_map<const char*, std::any> data {
            { "name", std::string("auto_") + std::to_string(count++) },
            { "rule", rule },
            { "data_block", data_block },
            { "nestedRules", std::vector<::Parser::Rule>() }
        };

        return ::Parser::Rule {
            0, nullptr, nullptr, Parser::Rules::Rule, data
        };
    }
    void literalsToToken(Parser::Tree& tree) {
        for (int i = 0; i < tree.size(); i++) {
            auto member = tree[i];
            if (member.name == Parser::Rules::Rule) {
                auto data = std::any_cast<std::unordered_map<const char*, std::any>>(member.data);
                auto name = std::any_cast<std::string>(data["name"]);
                auto rule = std::any_cast<std::vector<Parser::Rule>>(data["rule"]);
                if (core::startsWithRange(name, 'a', 'z')) {
                    // is rule
                    for (int j = 0; j < rule.size(); j++) {
                        auto el = rule[i];
                        auto el_data = std::any_cast<std::unordered_map<const char*, std::any>>(el.data);
                        auto val = std::any_cast<Parser::Rule>(el_data["val"]);
                        auto qualifier = std::any_cast<::Parser::Rule>(el_data["qualifier"]);

                        if (val.name == Parser::Rules::string || val.name == Parser::Rules::Rule_hex || val.name == Parser::Rules::Rule_bin) {
                            // convert into token & add here token instead of string
                            auto newToken = Tokens::ruleToToken(val);
                            // use token here instead of literal
                            std::any_cast<std::vector<Parser::Rule>>(data["rule"])[j] = newToken;
                        }
                    }   

                }
            }
        }
    }
}
