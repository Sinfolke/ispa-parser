#include <IR.h>
#include <internal_types.h>
#include <token_management.h>
#include <corelib.h>
#include <parser.h>
// a structure used to cout
void IR::ir::add(IR::ir repr) {
    elements.insert(elements.end(), repr.elements.begin(), repr.elements.end());
}
void IR::ir::push(IR::member member) {
    elements.push_back(member);
}
size_t IR::ir::size() {
    return elements.size();
}
struct element_count {
    size_t index;
    arr_t<IR::member> subrule;
    bool is_group = false;
    size_t group_length = 0;
};
element_count getGroup(arr_t<element_count> elements, double index) {
    for (auto el : elements) {
        if (el.is_group)
            index--;
        if (index == 0)
            return el;
    }
    throw UError("invalid accesor number");
}
std::pair<element_count, int> getElementByAccessor(arr_t<element_count> &elements, Parser::Rule accessor) {
    auto data = std::any_cast<obj_t>(accessor.data);
    auto first = std::any_cast<Parser::Rule>(corelib::map::get(data, "first"));
    auto second = std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(data, "second"));
    second.insert(second.begin(), first);
    bool is_first = true;
    Parser::Rules prev = Parser::Rules::NONE;
    element_count result;
    double prev_index = 0;

    int i;
    for (auto &el : second) {
        auto accessor = std::any_cast<Parser::Rule>(el.data);
        auto number = std::any_cast<Parser::Rule>(accessor.data);
        auto num_data = std::any_cast<obj_t>(number.data);
        auto num_main_n = std::any_cast<double>(corelib::map::get(num_data, "main_n"));
        
        switch (accessor.name) {
            case Parser::Rules::accessors_element:
                if (prev == Parser::Rules::accessors_element)
                    throw UError("Accessor '%' cannot have subaccessors");
                prev = Parser::Rules::accessors_element;
                result = elements[(size_t) num_main_n];
            case Parser::Rules::accessors_group:
                if (prev == Parser::Rules::accessors_element)
                    throw UError("Accessor '%' cannot have subaccessors");
                prev_index += num_main_n;
                result = getGroup(elements, prev_index);
            case Parser::Rules::accessors_char:
                if (!is_first)
                    throw UError("accessor '^' cannot be a subaccessor");
                return {};
        }
        is_first = false;
        i++;
    }
    return { result, i };
}
IR::ir ruleToIr(Parser::Rule &rule_rule, IR::ir &member, arr_t<element_count> &elements, int &variable_count) {
    member.elements.push_back(IR::member{ IR::types::RULE, });

    auto rule_data = std::any_cast<obj_t>(rule_rule.data);
    auto rule = std::any_cast<Parser::Rule>(corelib::map::get(rule_data, "val"));
    auto qualifier = std::any_cast<Parser::Rule>(corelib::map::get(rule_data, "qualifier"));


    switch (rule.name) {
        case Parser::Rules::Rule_group: 
        {
            auto data = std::any_cast<obj_t>(rule.data);

            // Extract variables within this block to avoid scope conflicts.
            auto variable = std::any_cast<Parser::Rule>(corelib::map::get(data, "variable"));
            auto val = std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(data, "val"));
            auto var_rule = std::any_cast<Parser::Rule>(variable.data);

            IR::ir values = rulesToIr(val);
            IR::member var = {
                IR::types::VARIABLE,
                var_rule,
                values.size(),
            };
            member.push(var);
            member.add(values);
            elements.push_back({ member.size() - 1, {var} });
            elements.push_back({ member.size(), values.elements, true, values.size()});
            break;
        }
        case Parser::Rules::Rule_csequence:
        {
            auto data = std::any_cast<obj_t>(rule.data);
            auto _not = std::any_cast<bool>(corelib::map::get(data, "not"));
            auto values = std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(data, "val"));
            arr_t<IR::cond_unit> expr;
            bool first = true;
            for (auto &value : values) {
                if (first) {
                    expr.push_back({IR::condition::GROUP_OPEN});
                    if (_not) {
                        expr.push_back({IR::condition::NOT});
                        expr.push_back({IR::condition::GROUP_OPEN});
                    }
                } else {
                    expr.push_back({IR::condition::AND});
                }
                switch (value.name) {
                    case Parser::Rules::Rule_csequence_diapason:
                    {
                        auto data = std::any_cast<arr_t<char>>(value.data);
                        expr.push_back({IR::condition::GROUP_OPEN});
                        expr.push_back({IR::condition::ACCESSOR, 0, Parser::Rules::accessors_char});
                        expr.push_back({IR::condition::HIGHER_OR_EQUAL});
                        expr.push_back({IR::condition::CHARACTER, data[0]});
                        expr.push_back({IR::condition::AND});
                        expr.push_back({IR::condition::ACCESSOR, 0, Parser::Rules::accessors_char});
                        expr.push_back({IR::condition::HIGHER_OR_EQUAL});
                        expr.push_back({IR::condition::CHARACTER, data[1]});
                        expr.push_back({IR::condition::GROUP_CLOSE});
                        break;
                    }
                    default:
                    {
                        if (value.name != Parser::Rules::Rule_csequence_escape && value.name != Parser::Rules::Rule_csequence_symbol)
                            throw Error("undefined csequence subrule");
                        auto data = std::any_cast<std::string>(value.data);
                        expr.push_back({IR::condition::ACCESSOR, 0, Parser::Rules::accessors_char});
                        expr.push_back({IR::condition::EQUAL});
                        expr.push_back({IR::condition::CHARACTER, data});
                    }
                }
            }
            expr.push_back({IR::condition::GROUP_CLOSE});
            if (_not)
                expr.push_back({IR::condition::GROUP_CLOSE});
            auto mem = IR::member {
                IR::types::IF,
                expr
            };
            member.push(mem);
            elements.push_back({member.size() - 1, {mem} });
        }
        case Parser::Rules::string:
        {
            auto data = std::any_cast<std::string>(rule.data);
            arr_t<IR::cond_unit> expr = {
                {IR::condition::STRNCMP, data}
            };
            auto mem = IR::member {
                IR::types::IF,
                expr
            };
            member.push(mem);
            elements.push_back({member.size() - 1, {mem} });
        }
        case Parser::Rules::accessor:
        {
            auto [element, i] = getElementByAccessor(elements, rule);
            auto var = IR::member {
                IR::types::VARIABLE,
                Tokens::make_rule(Parser::Rules::id, "_" + std::to_string(variable_count++)),
            };
            member.elements.insert(member.elements.begin() + element.index, var);
        }

        default:
            throw Error("Converting undefined rule");
    }

    return member;
}
IR::ir rulesToIr(arr_t<Parser::Rule> rules) {
    IR::ir result;
    arr_t<element_count> elements;
    int variable_count = 0;
    for (auto &rule : rules) {
        ruleToIr(rule, result, elements, variable_count);
    }
    return result;
}
IR::ir treeToIr(Parser::Tree &tree) {
    IR::ir result_ir;
    for (auto &el : tree) {
        if (el.name != Parser::Rules::Rule)
            continue;
        auto data = std::any_cast<obj_t>(el.data);
        auto rules = std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(data, "rule"));
        result_ir.add(rulesToIr(rules));
    }
    return result_ir;
}