#include <corelib.h>
#include <token_management.h>
#include <internal_types.h>
#include <string>
#include <vector>
#include <unordered_map>
#include <any>
#include <forward_list>

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
            case Parser::Rules::accessor:
                return compare_accessor_rule(first, second);
            case Parser::Rules::id:
                return compare_id_rule(first, second);
            case Parser::Rules::Rule_csequence:
                return compare_csequence_rule(first, second);
            case Parser::Rules::op:
                return compare_op_rule(first, second);
            case Parser::Rules::Rule_other:
                return compare_other_rule(first, second);
            default:
                throw Error("Comparing unknown rule: %$", Parser::RulesToString(first.name));
        }
    }
    bool compare_string_rule(Parser::Rule first, Parser::Rule second) {
        return compareStringRule(first, second);
    }
    bool compare_hex_rule(Parser::Rule first, Parser::Rule second) {
        return compareStringViewRule(first, second);
    }
    bool compare_bin_rule(Parser::Rule first, Parser::Rule second) {
        return compareStringViewRule(first, second);
    }
    bool compare_accessor_rule(Parser::Rule first, Parser::Rule second) {
        auto first_data = std::any_cast<obj_t>(first.data);
        auto second_data = std::any_cast<obj_t>(second.data);

        auto first_first = std::any_cast<Parser::Rule> (corelib::map::get(first_data, "first"));
        auto second_first = std::any_cast<Parser::Rule> (corelib::map::get(second_data, "first"));
        
        auto first_second = std::any_cast<arr_t<Parser::Rule>> (corelib::map::get(first_data, "second"));
        auto second_second = std::any_cast<arr_t<Parser::Rule>> (corelib::map::get(second_data, "second"));
        return compare_accessor_internal(first_first, second_first) && compare_accessor_internal(first_second, second_second);
    }
    bool compare_accessor_internal(Parser::Rule first, Parser::Rule second) {
        auto first_d = std::any_cast<Parser::Rule>(first.data);
        auto second_d = std::any_cast<Parser::Rule>(second.data);

        if (first_d.name != second_d.name)
            return false;
        return compare_number_rules(std::any_cast<Parser::Rule>(first_d.data), std::any_cast<Parser::Rule>(second_d.data));
    }
    bool compare_accessor_internal(arr_t<Parser::Rule> first, arr_t<Parser::Rule> second) {
        if (first.size() != second.size())
            return false;
        for (int i = 0; i < first.size(); i++) {
            if (!compare_accessor_internal(first[i], second[i]))
                return false;
        }
        return true;
    }
    bool compare_number_rules(Parser::Rule first, Parser::Rule second) {
        auto first_data = std::any_cast<obj_t>(first.data);
        auto second_data = std::any_cast<obj_t>(second.data);
        std::string sign_first = std::any_cast<std::string>(corelib::map::get(first_data, "sign"));
        std::string sign_second = std::any_cast<std::string>(corelib::map::get(second_data, "sign"));

        std::string main_first = std::any_cast<std::string>(corelib::map::get(first_data, "main"));
        std::string main_second = std::any_cast<std::string>(corelib::map::get(second_data, "main"));

        std::string dec_first = std::any_cast<std::string>(corelib::map::get(first_data, "dec"));
        std::string dec_second = std::any_cast<std::string>(corelib::map::get(second_data, "dec"));

        double main_n_first = std::any_cast<double>(corelib::map::get(first_data, "main_n"));
        double main_n_second = std::any_cast<double>(corelib::map::get(second_data, "main_n"));

        double dec_n_first = std::any_cast<double>(corelib::map::get(first_data, "dec_n"));
        double dec_n_second = std::any_cast<double>(corelib::map::get(second_data, "dec_n"));
        return
            sign_first == sign_second &&
            main_first == main_second &&
            dec_first == dec_second &&
            main_n_first == main_n_second &&
            dec_n_first == dec_n_second
        ;
    }
    bool compare_id_rule(Parser::Rule first, Parser::Rule second) {
        return compareStringRule(first, second);
    }
    bool compare_op_rule(Parser::Rule first, Parser::Rule second) {
        return compareStringRule(first, second);
    }
    bool compare_other_rule(Parser::Rule first, Parser::Rule second) {
        auto first_data = std::any_cast<obj_t>(first.data);
        auto second_data = std::any_cast<obj_t>(second.data);

        auto is_nested1 = std::any_cast<bool>(corelib::map::get(first_data, "is_nested"));
        auto is_nested2 = std::any_cast<bool>(corelib::map::get(second_data, "is_nested"));
        auto name1 = std::any_cast<Parser::Rule>(corelib::map::get(first_data, "name"));
        auto name2 = std::any_cast<Parser::Rule>(corelib::map::get(second_data, "name"));

        auto nested_names1 = std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(first_data, "nested_names"));
        auto nested_names2 = std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(second_data, "nested_names"));

        return 
            is_nested1 == is_nested2 && 
            compareStringRule(name1, name2) && 
            compare_other_nested_name(nested_names1, nested_names2)
        ;
    }
    bool compare_other_nested_name(arr_t<Parser::Rule> nested_name1, arr_t<Parser::Rule> nested_name2) {
        if (nested_name1.size() != nested_name2.size())
            return false;
        for (int i = 0; i < nested_name1.size(); i++) {
            if (!compareStringRule(nested_name1[i], nested_name2[i]))
                return false;
        }
        return true;
    }
    bool compare_csequence_rule(Parser::Rule first, Parser::Rule second) {
        auto first_data = std::any_cast<obj_t>(first.data);
        auto second_data = std::any_cast<obj_t>(second.data);

        auto first_not = std::any_cast<bool>(corelib::map::get(first_data, "not"));
        auto second_not = std::any_cast<bool>(corelib::map::get(second_data, "not"));

        auto first_val = std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(first_data, "val"));
        auto second_val = std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(first_data, "val"));

        if (first_not != second_not || first_val.size() != second_val.size())
            return false; // not equal
        
        for (int i = 0; i < first_val.size(); i++) {
            if (!compare_csequence_internal_dt(first_val[i], second_val[i]))
                return false;
        }
        return true;
    }
    bool compare_csequence_internal_dt(Parser::Rule first, Parser::Rule second) {
        if (first.name != second.name)
            return false;
        switch (first.name) {
            case Parser::Rules::Rule_csequence_diapason:
                return compare_csequence_diapason_rule(first, second);
            case Parser::Rules::Rule_csequence_escape:
                return compare_csequence_escape_rule(first, second);
            case Parser::Rules::Rule_csequence_symbol:
                return compare_csequence_symbol_rule(first, second);
            default:
                throw Error("Csequence having new rules unhandled by compare_csequence_internal_dt");
        }
    }
    bool compare_csequence_diapason_rule(Parser::Rule first, Parser::Rule second) {
        auto first_data = std::any_cast<arr_t<Parser::Rule>>(first.data);
        auto second_data = std::any_cast<arr_t<Parser::Rule>>(second.data);
        return compare_csequence_symbol_rule(first_data[0], second_data[0]) && compare_csequence_symbol_rule(first_data[1], second_data[1]);
    }
    bool compare_csequence_symbol_rule(Parser::Rule first, Parser::Rule second) {
        return compareStringRule(first, second);
    }
    bool compare_csequence_escape_rule(Parser::Rule first, Parser::Rule second) {
        return compareStringRule(first, second);
    }
    bool compareStringViewRule(Parser::Rule first, Parser::Rule second) {
        return std::any_cast<std::string_view>(first.data) == std::any_cast<std::string_view>(second.data);
    }
    bool compareStringRule(Parser::Rule first, Parser::Rule second) {
        return std::any_cast<std::string>(first.data) == std::any_cast<std::string>(second.data);
    }
    // compares the token with rules and return an index where match discovered
    std::forward_list<int> compare_rules(Parser::Tree token_rule, Parser::Tree rules) {
        std::forward_list<int> where;
        if (token_rule.size() > rules.size()) // never match
            return where;
        for (int i = 0; i + token_rule.size() < rules.size(); i += token_rule.size()) {
            bool success = true;
            for (int j = i; j < token_rule.size(); j++) {
                auto token_data = std::any_cast<obj_t>(token_rule[j].data);
                auto token_val = std::any_cast<Parser::Rule>(corelib::map::get(token_data, "val"));

                auto rules_data = std::any_cast<obj_t>(rules[j].data);
                auto rules_val = std::any_cast<Parser::Rule>(corelib::map::get(rules_data, "val"));
                if (!compare_rule(token_val, rules_val)) {
                    success = false;
                    break;
                }
            }
            if (success) {
                where.push_front(i);
            }
        }
        return where;
    }
}
