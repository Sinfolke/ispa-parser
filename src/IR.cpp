#include <IR.h>
#include <internal_types.h>
#include <corelib.h>
#include <parser.h>

void IR::ir::add(IR::ir repr) {
    elements.insert(elements.end(), repr.elements.begin(), repr.elements.end());
}
void IR::ir::push(IR::member member) {
    elements.push_back(member);
}
IR::ir ruleToIr(Parser::Rule rule_rule) {
    IR::ir member;
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
                values.elements.size(),
                var_rule,
            };
            member.push(var);
            member.add(values);
            break;
        }
        case Parser::Rules::Rule_csequence:
        {
            auto data = std::any_cast<obj_t>(rule.data);
            auto _not = std::any_cast<bool>(corelib::map::get(data, "not"));
            auto values = std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(data, "val"));
            std::string expr;
            bool first = true;
            for (auto &value : values) {
                if (first) {
                    expr += '(';
                    if (_not) {
                        expr += "!(";
                    }
                } else {
                    expr += "&&";
                }
                switch (value.name) {
                    case Parser::Rules::Rule_csequence_diapason:
                    {
                        auto data = std::any_cast<arr_t<char>>(value.data);
                        expr += "(^0 >= '";
                        expr += data[0];
                        expr += "' && value <= '";
                        expr += data[1];
                        expr += "')";
                        break;
                    }
                    default:
                    {
                        if (value.name != Parser::Rules::Rule_csequence_escape && value.name != Parser::Rules::Rule_csequence_symbol)
                            throw Error("undefined csequence subrule");
                        auto data = std::any_cast<std::string>(value.data);
                        expr += "^0 == '";
                        expr += data;
                        expr += "'";
                    }
                }
            }
            if (_not)
                expr += "))";
            else
                expr += ")";
            auto member = {
                IR::types::IF,

            }
        }
        default:
            throw Error("Converting undefined rule");
    }

    return member;
}
IR::ir rulesToIr(arr_t<Parser::Rule> rules) {
    IR::ir result;
    for (auto &rule : rules) {
        result.add(ruleToIr(rule));
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