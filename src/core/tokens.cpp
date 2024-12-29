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
}
