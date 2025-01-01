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
            std::unordered_map<const char*, std::any> { 
                { "first", accessorAllRule },
                { "second", arr_t<Parser::Rule>{} }
            }
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
    Parser::Rule make_rule() {
        return {0, nullptr, nullptr, Parser::Rules::NONE};
    };
    Parser::Rule make_rule(Parser::Rules name) {
        return {0, nullptr, nullptr, name};
    };
    Parser::Rule make_rule(Parser::Rules name, std::any data) {
        return {0, nullptr, nullptr, name, data};
    };
    bool compare_rule(Parser::Rule first, Parser::Rule second) {
        if (first.name != second.name)
            return false;
        switch (first.name)
        {
            case Parser::Rules::string:
                return compare_string_rule(first, second);
            case Parser::Rules::Rule_hex:
                return compare_hex_rule(first, second);
            case Parser::Rules::Rule_bin:
                return compare_bin_rule(first, second);
            case Parser::Rules::id:
                return compare_id_rule(first, second);
            case Parser::Rules::Rule_csequence:
                return compare_csequence_rule(first, second);
            case Parser::Rules::op:
                return compare_op_rule(first, second);
            default:
                throw Error("Comparing unknown rule");
        }
    }
    bool compare_string_rule(Parser::Rule first, Parser::Rule second) {
        return std::any_cast<std::string>(first.data) == std::any_cast<std::string>(second.data);
    }
    bool compare_hex_rule(Parser::Rule first, Parser::Rule second) {
        return std::any_cast<std::string>(first.data) == std::any_cast<std::string>(second.data);
    }
    // compares the token with rules and 
    int compare_rules(Parser::Tree token_rule, Parser::Tree rules) {
        int i = 0;
        for (; i < token_rule.size(); i++) {
            if (!compare_rule(token_rule[i], rules[i]))
                break;
        }
        return i;
    }
}
