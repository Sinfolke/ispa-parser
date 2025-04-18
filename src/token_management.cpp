#include <corelib.h>
#include <token_management.h>
#include <internal_types.h>
#include <string>
#include <vector>
#include <unordered_map>
#include <any>
#include <list>
#include <forward_list>
namespace Tokens {
    std::vector<Parser::Rule> getValueFromGroup(const Parser::Rule &rule) {
        if (!rule.data.has_value())
            return {};
        auto data = std::any_cast<obj_t>(rule.data);
        auto val = std::any_cast<std::vector<Parser::Rule>>(corelib::map::get(data, "val"));
        return val;
    }
    Parser::Rule getValueFromRule_rule(const Parser::Rule &rule) {
        auto data = std::any_cast<obj_t>(rule.data);
        return std::any_cast<Parser::Rule>(corelib::map::get(data, "val"));
    }
    Parser::Rule getValueFromRule_rule(const Parser::Rule &rule, Parser::Rule &quantifier) {
        auto data = std::any_cast<obj_t>(rule.data);
        quantifier = std::any_cast<Parser::Rule>(corelib::map::get(data, "qualifier"));
        return std::any_cast<Parser::Rule>(corelib::map::get(data, "val"));
    }
    Parser::Rule make_id(std::string name) {
        return make_rule(Parser::Rules::id, name);
    }
    ::Parser::Rule singleRuleToToken(const Parser::Rule &input, size_t &count) {
        // Construct a token here
        ::Parser::Rule numberRule = make_rule(Parser::Rules::number, 
            obj_t {
                    { "sign", "" },
                    { "main", std::string("1") },
                    { "main_n", (double) 1 },
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
                { "second", std::vector<Parser::Rule>{} }
            }
        );
        ::Parser::Rule any_data = make_rule(Parser::Rules::any_data, accessorRule);
        ::Parser::Rule data_block = make_rule(Parser::Rules::Rule_data_block, any_data);
        std::vector<Parser::Rule> rule { make_rule(Parser::Rules::Rule_rule, 
            obj_t {
                { "val", input },
                { "qualifier", Parser::Rule() }
            }
        )};
        obj_t data {
            { "name", make_rule(Parser::Rules::id, std::string("AUTO_") + std::to_string(count++)) },
            { "rule", rule },
            { "data_block", data_block },
            { "nestedRules", std::vector<Parser::Rule>() }
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
    bool compare_rule_matching(const Parser::Rule &first, const Parser::Rule &second) {
        if (first.name == Parser::Rules::Rule_op && second.name == Parser::Rules::Rule_op) {
            auto first_options = std::any_cast<std::vector<Parser::Rule>>(first.data);
            auto second_options = std::any_cast<std::vector<Parser::Rule>>(second.data);

            for (auto &opt1 : first_options) {
                for (auto &opt2 : second_options) {
                    if (!compare_rule_matching(opt1, opt2))
                        return false;
                }
            }
            return true;
        }
        switch (first.name)
        {
            case Parser::Rules::Rule_op:
            {
                if (!first.data.has_value())
                    return false;
                auto options = std::any_cast<std::vector<Parser::Rule>>(first.data);
                for (auto &rule : options) {
                    if (!compare_rule_matching(rule, second))
                        return false;
                }
                return true;
            }
            case Parser::Rules::Rule_group:
            {
                if (!first.data.has_value())
                    return false;
                
                auto data = std::any_cast<obj_t>(first.data);
                auto val = std::any_cast<std::vector<Parser::Rule>>(corelib::map::get(data, "val"));
                if (val.size() > 1)
                    return false;
                
                return compare_rule_matching(val[0], second);
            }
        }
        if (second.name == Parser::Rules::Rule_op || second.name == Parser::Rules::Rule_group) {
            return compare_rule_matching(second, first);
        } else {
            return compare_rule(first, second);
        }
    }
    bool compare_rule_matching(std::vector<Parser::Rule>::iterator first_it, std::vector<Parser::Rule>::iterator second_it) {
        Parser::Rule first, second;
        if (first_it->name == Parser::Rules::Rule_rule) {
            auto rule1 = std::any_cast<obj_t&>(first_it->data);
            first = std::any_cast<Parser::Rule&>(corelib::map::get(rule1, "val"));
        } else first = *first_it;
        if (second_it->name == Parser::Rules::Rule_rule) {
            auto rule1 = std::any_cast<obj_t&>(second_it->data);
            second = std::any_cast<Parser::Rule&>(corelib::map::get(rule1, "val"));
        } else second = *second_it;
        return compare_rule_matching(first, second);
    }
    bool compare_rule(const Parser::Rule &first, const Parser::Rule &second) {

        if (first.name != second.name) {
            // group
            if (first.name == Parser::Rules::Rule_group) {
                auto values = getValueFromGroup(first);
                if (values.size() > 1)
                    return false;
                return compare_rule(values[0], second);
            } else if (second.name == Parser::Rules::Rule_group) {
                auto values = getValueFromGroup(second);
                if (values.size() > 1)
                    return false;
                return compare_rule(first, values[0]);
            }

            
            return false;
        }
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
            case Parser::Rules::Rule_op:
                return compare_op_rule(first, second);
            case Parser::Rules::Rule_other:
                return compare_other_rule(first, second);
            case Parser::Rules::Rule_group:
                return compare_group_rule(first, second);
            case Parser::Rules::Rule_any:
                return true;
            case Parser::Rules::Rule_escaped:
                return compare_escape_rule(first, second);
            case Parser::Rules::linear_comment:
                return true; // comments shall be ignored
            case Parser::Rules::cll:
                return compare_cll_rule(first, second);
            case Parser::Rules::Rule_rule: {
                auto rule1 = std::any_cast<obj_t>(first.data);
                auto first = std::any_cast<Parser::Rule>(corelib::map::get(rule1, "val"));
                auto rule2 = std::any_cast<obj_t>(second.data);
                auto second = std::any_cast<Parser::Rule>(corelib::map::get(rule2, "val"));
                return compare_rule(first, second);
            }
            default:
                throw Error("Comparing unknown rule: %$", Parser::RulesToString(first.name));
        }
    }
    bool compare_string_rule(const Parser::Rule &first, const Parser::Rule &second) {
        return compareStringRule(first, second);
    }
    bool compare_hex_rule(const Parser::Rule &first, const Parser::Rule &second) {
        return compareStringRule(first, second);
    }
    bool compare_bin_rule(const Parser::Rule &first, const Parser::Rule &second) {
        return compareStringRule(first, second);
    }
    bool compare_accessor_rule(const Parser::Rule &first, const Parser::Rule &second) {
        auto first_data = std::any_cast<obj_t>(first.data);
        auto second_data = std::any_cast<obj_t>(second.data);

        auto first_first = std::any_cast<Parser::Rule> (corelib::map::get(first_data, "first"));
        auto second_first = std::any_cast<Parser::Rule> (corelib::map::get(second_data, "first"));
        
        auto first_second = std::any_cast<std::vector<Parser::Rule>> (corelib::map::get(first_data, "second"));
        auto second_second = std::any_cast<std::vector<Parser::Rule>> (corelib::map::get(second_data, "second"));
        return compare_accessor_internal(first_first, second_first) && compare_accessor_internal(first_second, second_second);
    }
    bool compare_accessor_internal(const Parser::Rule &first, const Parser::Rule &second) {
        auto first_d = std::any_cast<Parser::Rule>(first.data);
        auto second_d = std::any_cast<Parser::Rule>(second.data);

        if (first_d.name != second_d.name)
            return false;
        return compare_number_rule(std::any_cast<Parser::Rule>(first_d.data), std::any_cast<Parser::Rule>(second_d.data));
    }
    bool compare_accessor_internal(const std::vector<Parser::Rule> &first, const std::vector<Parser::Rule> &second) {
        if (first.size() != second.size())
            return false;
        for (int i = 0; i < first.size(); i++) {
            if (!compare_accessor_internal(first[i], second[i]))
                return false;
        }
        return true;
    }
    bool compare_booolean_rule(const Parser::Rule &first, const Parser::Rule &second) {
        auto first_data = std::any_cast<obj_t>(first);
        auto second_data = std::any_cast<obj_t>(second);
        return std::any_cast<int>(corelib::map::get(first_data, "val")) == std::any_cast<int>(corelib::map::get(second_data, "val"));
    }
    bool compare_array_rule(const Parser::Rule &first, const Parser::Rule &second) {
        auto first_data = std::any_cast<std::vector<std::any>>(first.data);
        auto second_data = std::any_cast<std::vector<std::any>>(first.data);

        auto first_vec = std::any_cast<std::vector<std::any>>(first_data[1]);
        auto second_vec = std::any_cast<std::vector<std::any>>(second_data[1]);
        if (!compare_any_data_rule(std::any_cast<Parser::Rule>(first_data[0]), std::any_cast<Parser::Rule>(second_data[0])))
            return false;
        
        if (first_vec.size() != second_vec.size())
            return false;
        for (int i = 0; i < first_vec.size(); i++) {
            if (!compare_any_data_rule(std::any_cast<Parser::Rule>(first_vec[i]), std::any_cast<Parser::Rule>(second_vec[i])))
                return false;
        }
        return true;
    }
    bool compare_object_rule(const Parser::Rule &first, const Parser::Rule &second) {
        auto first_data = std::any_cast<obj_t>(first.data);
        auto second_data = std::any_cast<obj_t>(second.data);

        auto first_key = std::any_cast<Parser::Rule>(corelib::map::get(first_data, "key"));
        auto second_key = std::any_cast<Parser::Rule>(corelib::map::get(second_data, "key"));
        auto first_value = std::any_cast<Parser::Rule>(corelib::map::get(first_data, "value"));
        auto second_value = std::any_cast<Parser::Rule>(corelib::map::get(second_data, "value"));

        auto first_keys = std::any_cast<std::vector<Parser::Rule>>(corelib::map::get(first_data, "keys"));
        auto second_keys = std::any_cast<std::vector<Parser::Rule>>(corelib::map::get(second_data, "keys"));

        auto first_values = std::any_cast<std::vector<Parser::Rule>>(corelib::map::get(first_data, "values"));
        auto second_values = std::any_cast<std::vector<Parser::Rule>>(corelib::map::get(second_data, "values"));

        if (!compare_any_data_rule(first_key, second_key) || !compare_any_data_rule(first_value, second_value))
            return false;
        
        if (first_keys.size() < second_keys.size() || first_values.size() < second_values.size())
            return false;

        for (int i = 0; i < first_keys.size(); i++) {
            if (!compare_any_data_rule(first_keys[i], second_keys[i]))
                return false;
        }
        for (int i = 0; i < first_values.size(); i++) {
            if (!compare_any_data_rule(first_values[i], second_values[i]))
                return false;
        }
        return true;
    }
    bool compare_number_rule(const Parser::Rule &first, const Parser::Rule &second) {
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
    bool compare_id_rule(const Parser::Rule &first, const Parser::Rule &second) {
        return compareStringRule(first, second);
    }
    bool compare_op_rule(const Parser::Rule &first, const Parser::Rule &second) {
        return compare_rules(std::any_cast<std::vector<Parser::Rule>>(first.data), std::any_cast<std::vector<Parser::Rule>>(second.data));
    }
    bool compare_other_rule(const Parser::Rule &first, const Parser::Rule &second) {
        auto first_data = std::any_cast<rule_other>(first.data);
        auto second_data = std::any_cast<rule_other>(second.data);
        return first_data.fullname == second_data.fullname;
    }
    bool compare_escape_rule(const Parser::Rule &first, const Parser::Rule &second) {
        auto first_data = std::any_cast<obj_t>(first.data);
        auto second_data = std::any_cast<obj_t>(second.data);

        auto first_c = std::any_cast<std::string>(corelib::map::get(first_data, "c"));
        auto second_c = std::any_cast<std::string>(corelib::map::get(second_data, "c"));

        auto first_number = std::any_cast<Parser::Rule>(corelib::map::get(first_data, "num"));
        auto second_number = std::any_cast<Parser::Rule>(corelib::map::get(second_data, "num"));

        if (first_number.data.has_value() != second_number.data.has_value())
            return false;
        if (first_c != second_c)
            return false;
        if (first_number.data.has_value()) {
            return compare_number_rule(first_number, second_number);
        }
        return true;
    }
    bool compare_csequence_rule(const Parser::Rule &first, const Parser::Rule &second) {
        auto first_data = std::any_cast<obj_t>(first.data);
        auto second_data = std::any_cast<obj_t>(second.data);
        auto first_not = std::any_cast<bool>(corelib::map::get(first_data, "not"));
        auto second_not = std::any_cast<bool>(corelib::map::get(second_data, "not"));
        auto first_val = std::any_cast<std::vector<Parser::Rule>>(corelib::map::get(first_data, "val"));
        auto second_val = std::any_cast<std::vector<Parser::Rule>>(corelib::map::get(second_data, "val"));
        if (first_not != second_not || first_val.size() > second_val.size())
            return false; // not equal
        for (int i = 0; i < second_val.size(); i++) {
            for (int j = 0; j < first_val.size(); j++) {
                if (compare_csequence_internal_dt(first_val[j], second_val[i]))
                    break;
                if (j == first_val.size() - 1)
                    return false;
            }
        }
        return true;
    }
    bool compare_csequence_internal_dt(const Parser::Rule &first, const Parser::Rule &second) {
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
    bool compare_csequence_diapason_rule(const Parser::Rule &first, const Parser::Rule &second) {
        auto first_data = std::any_cast<std::vector<Parser::Rule>>(first.data);
        auto second_data = std::any_cast<std::vector<Parser::Rule>>(second.data);
        return compare_csequence_symbol_rule(first_data[0], second_data[0]) && compare_csequence_symbol_rule(first_data[1], second_data[1]);
    }
    bool compare_csequence_symbol_rule(const Parser::Rule &first, const Parser::Rule &second) {
        return compareStringRule(first, second);
    }
    bool compare_csequence_escape_rule(const Parser::Rule &first, const Parser::Rule &second) {
        return compareStringRule(first, second);
    }
    bool compare_group_rule(const Parser::Rule &first, const Parser::Rule &second) {
        auto first_data = std::any_cast<obj_t>(first.data);
        auto second_data = std::any_cast<obj_t>(second.data);
        auto first_variable = corelib::map::get(first_data, "variable");
        auto second_variable = corelib::map::get(second_data, "variable");
        auto first_rule = corelib::map::get(first_data, "val");
        auto second_rule = corelib::map::get(second_data, "val");
        if (first_variable.has_value() != second_variable.has_value()) {
            return false;
        }
        if (first_variable.has_value()) {
            // compare method/id
            auto first_data = std::any_cast<Parser::Rule>(first_variable);
            auto second_data = std::any_cast<Parser::Rule>(second_variable);
            if (first_data.name != second_data.name)
                return false;
            if (first_data.name == Parser::Rules::id) {
                if (!compare_id_rule(first_data, second_data)) return false;
            } else {
                if (!compare_method_call_rule(first_data, second_data)) return false;
            }
        }
        return compare_rules(std::any_cast<std::vector<Parser::Rule>>(first_rule), std::any_cast<std::vector<Parser::Rule>>(second_rule));
    }

    bool compare_method_call_rule(const Parser::Rule &first, const Parser::Rule &second) {
        auto first_data = std::any_cast<obj_t>(first.data);
        auto second_data = std::any_cast<obj_t>(second.data);

        auto first_object = std::any_cast<Parser::Rule>(corelib::map::get(first_data, "object"));
        auto second_object = std::any_cast<Parser::Rule>(corelib::map::get(second_data, "object"));

        auto first_function_call = std::any_cast<Parser::Rule>(corelib::map::get(first_data, "call"));
        auto second_function_call = std::any_cast<Parser::Rule>(corelib::map::get(second_data, "call"));

        return compareStringRule(first_object, second_object) && compare_cll_function_call(first_function_call, second_function_call);
    }
    bool compare_cll_rule(const Parser::Rule &first, const Parser::Rule &second) {
        return false;
    }
    bool compare_cll_function_call(const Parser::Rule &first, const Parser::Rule &second) {
        auto first_data = std::any_cast<obj_t>(first.data);
        auto second_data = std::any_cast<obj_t>(second.data);

        auto first_name = std::any_cast<Parser::Rule>(corelib::map::get(first_data, "name"));
        auto second_name = std::any_cast<Parser::Rule>(corelib::map::get(second_data, "name"));

        auto first_body = std::any_cast<Parser::Rule>(corelib::map::get(first_data, "body"));
        auto second_body = std::any_cast<Parser::Rule>(corelib::map::get(second_data, "body"));

        return compareStringRule(first_name, second_name) && compare_cll_function_body(first_body, second_body);
    }
    bool compare_cll_function_body(const Parser::Rule &first, const Parser::Rule &second) {
        return compare_cll_function_arguments(std::any_cast<Parser::Rule>(first.data), std::any_cast<Parser::Rule>(second.data));
    }
    bool compare_cll_function_arguments(const Parser::Rule &first, const Parser::Rule &second) {
        auto first_data = std::any_cast<std::vector<std::any>>(first.data);
        auto second_data = std::any_cast<std::vector<std::any>>(second.data);

        if (!compare_any_data_rule(std::any_cast<Parser::Rule>(first_data[0]), std::any_cast<Parser::Rule>(second_data[0])))
            return false;
        auto first_vec = std::any_cast<std::vector<Parser::Rule>>(first_data[1]);
        auto second_vec = std::any_cast<std::vector<Parser::Rule>>(second_data[1]);
        if (first_vec.size() != second_vec.size()) 
            return false;
        for (int i = 0; i < first_vec.size(); i++) {
            if (!compare_any_data_rule(std::any_cast<Parser::Rule>(first_vec[i]), std::any_cast<Parser::Rule>(second_vec[i])))
                return false;
        }
        return true;
    }
    bool compare_any_data_rule(const Parser::Rule &first, const Parser::Rule &second) {
        auto first_data = std::any_cast<Parser::Rule>(first.data);
        auto second_data = std::any_cast<Parser::Rule>(second.data);
        if (first_data.name != second_data.name)
            return false;
        
        switch (first_data.name)
        {
        case Parser::Rules::boolean:
            return compare_booolean_rule(first_data, second_data);
        case Parser::Rules::number:
            return compare_number_rule(first_data, second_data);
        case Parser::Rules::string:
            return compare_string_rule(first_data, second_data);
        case Parser::Rules::array:
            return compare_array_rule(first_data, second_data);
        case Parser::Rules::object:
            return compare_object_rule(first_data, second_data);
        case Parser::Rules::id:
            return compare_id_rule(first_data, second_data);
        case Parser::Rules::accessor:
            return compare_accessor_rule(first_data, second_data);
        default:
            throw Error("Comparing unknown rule: %$", Parser::RulesToString(first.name));
        }
    }
    bool compareStringViewRule(const Parser::Rule &first, const Parser::Rule &second) {
        return std::any_cast<std::string_view>(first.data) == std::any_cast<std::string_view>(second.data);
    }
    bool compareStringRule(const Parser::Rule &first, const Parser::Rule &second) {
        return std::any_cast<std::string>(first.data) == std::any_cast<std::string>(second.data);
    }
    bool compare_rules(const std::vector<Parser::Rule> &first, const std::vector<Parser::Rule> &second) {
        if (first.size() != second.size())
            return false;
        for (int i = 0; i < first.size(); i++) {
            if (!compare_rule(first[i], second[i]))
                return false;
        }
        return true;
    }
    bool compare_token_with_rules(const Parser::Tree &first, const Parser::Tree &second) {
        if (first.size() != second.size())
            return false;
        
        for (int i = 0; i < first.size(); i++) {
            Parser::Rule _first = first[i], _second = second[i];
            if (_first.name == Parser::Rules::Rule_rule) {
                auto data = std::any_cast<obj_t>(_first.data);
                _first = std::any_cast<Parser::Rule>(corelib::map::get(data, "val"));
            }
            if (_second.name == Parser::Rules::Rule_rule) {
                auto data = std::any_cast<obj_t>(_second.data);
                _second = std::any_cast<Parser::Rule>(corelib::map::get(data, "val"));
            }
            if (!compare_rule(_first, _second))
                return false;
        }
        return true;
    }
    // compares the token with rules and return an index where match discovered
    std::vector<int> find_token_in_rule(const Parser::Tree &token_rule, const Parser::Tree &rules) {
        std::vector<int> where;

        if (token_rule.size() > rules.size()) // never match
            return {};

        for (size_t i = 0; i <= rules.size() - token_rule.size(); ++i) {
            bool success = true;
            int _where = i;

            for (size_t j = 0; j < token_rule.size(); ++j) {
                auto token_data = std::any_cast<obj_t>(token_rule[j].data);
                auto token_val = std::any_cast<Parser::Rule>(corelib::map::get(token_data, "val"));

                auto rules_data = std::any_cast<obj_t>(rules[i + j].data);
                auto rules_val = std::any_cast<Parser::Rule>(corelib::map::get(rules_data, "val"));

                if (!compare_rule(token_val, rules_val)) {
                    success = false;
                    break;
                }
            }

            if (success) {
                where.push_back(_where);
            }
        }

        return where;
    }
    Parser::Rule* find_token_in_tree(Parser::Tree &tree, std::vector<std::string> names, size_t pos) {
        if (names.empty())
            return nullptr;
        for (auto &member : tree) {
            if (member.name != Parser::Rules::Rule)
                continue;
            auto &data = std::any_cast<obj_t&>(member.data);
            auto &name = std::any_cast<Parser::Rule&>(corelib::map::get(data, "name"));
            auto &name_str = std::any_cast<std::string&>(name.data);
            auto &nested_rules = std::any_cast<std::vector<Parser::Rule>&>(corelib::map::get(data, "nestedRules"));
            //cpuf::printf("comparing %s with %s\n", std::any_cast<std::string>(name.data), std::any_cast<std::string>(id.data));
            if (name_str == names[pos]) {
                if (pos == names.size() - 1) {
                    return &member;
                }
                pos++;
                return find_token_in_tree(nested_rules, names, pos);
            }
        }
        cpuf::printf("Not found: %$\n", names);
        return nullptr;
    }

}
