#include <corelib.h>
#include <token_management.h>
#include <internal_types.h>
#include <string>
#include <vector>
#include <unordered_map>
#include <any>

static size_t count = 0;

namespace Tokens {
    ::Parser::Rule singleRuleToToken(::Parser::Rule input) {
        // Construct a token here
        ::Parser::Rule numberRule = make_rule(Parser::Rules::number, 
            obj_t {
                    { "sign", "" },
                    { "main", "1" },
                    { "main_n", 1 },
                    { "point", "" },
                    { "dec", "" },
                    { "dec_n", 0 }
            }
        );
        ::Parser::Rule accessorsElementRule = make_rule(Parser::Rules::accessors_element, numberRule);
        ::Parser::Rule accessorAllRule = make_rule(Parser::Rules::accessor_all, accessorsElementRule);
        ::Parser::Rule accessorRule = make_rule(Parser::Rules::accessor, 
            obj_t { { "first", accessorAllRule } }
        );
        ::Parser::Rule data_block = make_rule(Parser::Rules::Rule_data_block, accessorRule);
        arr_t<Parser::Rule> rule {input};

        obj_t data {
            { "name", make_rule(Parser::Rules::id, std::string("auto_") + std::to_string(count++)) },
            { "rule", rule },
            { "data_block", data_block },
            { "nestedRules", arr_t<Parser::Rule>() }
        };

        return make_rule(Parser::Rules::Rule, data);
    }
    Parser::Rule make_rule(Parser::Rules name, std::any data) {
        return {0, nullptr, nullptr, name, data};
    };
}
