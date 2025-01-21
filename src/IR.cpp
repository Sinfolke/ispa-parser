#include <IR.h>
#include <internal_types.h>
#include <token_management.h>
#include <corelib.h>
#include <parser.h>
#include <cpuf/hex.h>
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
IR::var_type deduceTypeOfSingleUnit(Parser::Rule rule) {
    return IR::var_type::UNDEFINED;
}
void push_to_elements(arr_t<IR::element_count> &elements, IR::ir &member) {
    elements.push_back({member.size(), elements.size() > 0 ? elements.back().index_in_rule : 0});
}
void push_to_elements_increament(arr_t<IR::element_count> &elements, IR::ir &member) {
    elements.push_back({member.size(), elements.size() > 0 ? elements.back().index_in_rule + 1 : 0});
}
IR::variable createEmptyVariable(std::string name, int assign_next_rules=0) {
    IR::variable var {
        IR::var_type::UNDEFINED,
        name,
        IR::var_assign_types::NONE,
        assign_next_rules
    };
    return var;
}
std::string generateVariableName(int &variable_count) {
    return std::string("_") + std::to_string(variable_count++);
}
void affectGroupByQualifier(IR::ir values, char qualifier, int &variable_count) {
    IR::ir new_ir;
    if (qualifier == '*' || qualifier == '+') {
        // create a while loop with elements inside
        int i = 0;
        IR::condition loop = {
            { { IR::condition_types::NUMBER, 1 } },
            {} 
        };
        for (; i < values.size(); i++) {
            auto &el = values.elements[i];

            if (el.type == IR::types::IF) {
                auto condition = std::any_cast<IR::condition>(el.value);
                for (auto &unit : condition.block) {
                    if (unit.type == IR::types::EXIT) {
                        unit.type = IR::types::BREAK_LOOP;
                    }
                }
            }
        }
        loop.block = values.elements;
        new_ir.push({IR::types::WHILE, loop});
        if (qualifier == '+') {
            // insert variable that will containt whether first iteration is success
            // at the end insert check that will exit if not success
            IR::variable var = createEmptyVariable(generateVariableName(variable_count));
            var.type = IR::var_type::BOOLEAN;
            var.value = IR::var_assign_types::FALSE;
            // assign variable to true at the end of the loop
            IR::variable_assign assign = {
                var.name,
                IR::var_assign_types::TRUE
            };
            IR::condition check_cond = {
                { 
                    { IR::condition_types::VARIABLE, var.name },
                    { IR::condition_types::EQUAL },
                    { IR::condition_types::NUMBER, false }
                },
                {
                    { IR::types::EXIT }
                }
            };
            loop.block.insert(loop.block.end(), {IR::types::ASSIGN_VARIABLE, assign});
            new_ir.elements.clear();
            new_ir.push({IR::types::VARIABLE, var});
            new_ir.push({IR::types::WHILE, loop});
            new_ir.push({IR::types::IF, check_cond});
        }

    } else if (qualifier == '?') {
        // create do while(0) loop to use break statements
        IR::condition loop = {
            { {IR::condition_types::NUMBER, 0} },
            values.elements
        };
        for (auto &el : loop.block) {
            if (el.type == IR::types::IF) {
                // replace condition to while or for loop
                auto condition = std::any_cast<IR::condition>(el.value);
                for (auto &unit : condition.block) {
                    if (unit.type == IR::types::EXIT)
                        unit.type = IR::types::BREAK_LOOP;
                }
                el.value = condition;
            }
        }
        IR::member loop_mem = {
            IR::types::DOWHILE,
            loop
        };
        new_ir.push(loop_mem);
    } else {
        // no qualifier, values should not be affected
        return;
    }
    values = new_ir;

}
void ruleToIr(Parser::Rule &rule_rule, IR::ir &member, arr_t<IR::element_count> &elements, int &variable_count) {
    member.push({ IR::types::RULE, });
    auto rule_data = std::any_cast<obj_t>(rule_rule.data);
    auto rule = std::any_cast<Parser::Rule>(corelib::map::get(rule_data, "val"));
    auto qualifier = std::any_cast<Parser::Rule>(corelib::map::get(rule_data, "qualifier"));
    char qualifier_char = '\0';
    if (qualifier.data.type() == typeid(char)) {
        qualifier_char = std::any_cast<char>(qualifier.data);
    }
    switch (rule.name) {
        case Parser::Rules::Rule_group: 
        {
            cpuf::printf("group\n");
            cpuf::printf("1\n");
            auto data = std::any_cast<obj_t>(rule.data);

            cpuf::printf("2, type: %s\n", corelib::map::get(data, "variable").type().name());
            // Extract variables within this block to avoid scope conflicts.
            Parser::Rule variable;
            if (corelib::map::get(data, "variable").has_value()) {
                variable = std::any_cast<Parser::Rule>(corelib::map::get(data, "variable"));
            }
            cpuf::printf("3\n");
            auto val = std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(data, "val"));
            cpuf::printf("4\n");
            IR::ir values = rulesToIr(val);
            IR::variable var;
            IR::member method_call {IR::types::METHOD_CALL};
            if (!variable.empty() && std::any_cast<Parser::Rule>(variable.data).name == Parser::Rules::id) {
                auto var_rule = std::any_cast<Parser::Rule>(variable.data);
                var = createEmptyVariable(std::any_cast<std::string>(var_rule.data), values.size());
            } else {
                var = createEmptyVariable(generateVariableName(variable_count), values.size());
            }

            affectGroupByQualifier(values, qualifier_char, variable_count);
            if (!variable.empty() && std::any_cast<Parser::Rule>(variable.data).name == Parser::Rules::method_call) {
                auto var_rule = std::any_cast<Parser::Rule>(variable.data);
                auto var_rule_data = std::any_cast<obj_t>(var_rule.data);
                method_call.value = var_rule_data;
                member.push({IR::types::VARIABLE, var});
                member.push({IR::types::GROUP});
                member.add(values);
                member.push({IR::types::METHOD_CALL, method_call});
            } else {
                member.push({IR::types::VARIABLE, var});
                member.push({IR::types::GROUP, values});
                affectGroupByQualifier(values, qualifier_char, variable_count);
            }

            cpuf::printf("5\n");
            break;
        }
        case Parser::Rules::Rule_csequence:
        {
            cpuf::printf("csequence\n");
            auto data = std::any_cast<obj_t>(rule.data);
            auto _not = std::any_cast<bool>(corelib::map::get(data, "not"));
            auto values = std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(data, "val"));
            arr_t<IR::expr> expr;
            bool first = true;
            for (auto &value : values) {
                if (first) {
                    if (!_not) {
                        expr.push_back({IR::condition_types::NOT});
                        expr.push_back({IR::condition_types::GROUP_OPEN});
                    }
                } else {
                    expr.push_back({IR::condition_types::AND});
                }
                switch (value.name) {
                    case Parser::Rules::Rule_csequence_diapason:
                    {
                        auto data = std::any_cast<arr_t<char>>(value.data);
                        expr.push_back({IR::condition_types::GROUP_OPEN});
                        expr.push_back({IR::condition_types::CURRENT_CHARACTER});
                        expr.push_back({IR::condition_types::HIGHER_OR_EQUAL});
                        expr.push_back({IR::condition_types::CHARACTER, data[0]});
                        expr.push_back({IR::condition_types::AND});
                        expr.push_back({IR::condition_types::CURRENT_CHARACTER});
                        expr.push_back({IR::condition_types::HIGHER_OR_EQUAL});
                        expr.push_back({IR::condition_types::CHARACTER, data[1]});
                        expr.push_back({IR::condition_types::GROUP_CLOSE});
                        break;
                    }
                    default:
                    {
                        if (value.name != Parser::Rules::Rule_csequence_escape && value.name != Parser::Rules::Rule_csequence_symbol)
                            throw Error("undefined csequence subrule");
                        auto data = std::any_cast<std::string>(value.data);
                        expr.push_back({IR::condition_types::CURRENT_CHARACTER});
                        expr.push_back({IR::condition_types::EQUAL});
                        expr.push_back({IR::condition_types::CHARACTER, data});
                    }
                }
            }
            if (!_not)
                expr.push_back({IR::condition_types::GROUP_CLOSE});
            auto mem = IR::member {
                IR::types::IF,
                expr
            };
            member.push(mem);
            push_to_elements(elements, member);
        }
        case Parser::Rules::string:
        {
            cpuf::printf("string\n");
            auto data = std::any_cast<std::string>(rule.data);
            arr_t<IR::expr> expr = {
                {IR::condition_types::STRNCMP, data}
            };
            auto mem = IR::member {
                IR::types::IF,
                expr
            };
            member.push(mem);
            push_to_elements(elements, member);
        }
        case Parser::Rules::accessor:
        {
            cpuf::printf("accessor\n");
            cpuf::printf("1, type: %s, data: %s\n", rule.data.type().name(), std::any_cast<std::string>(rule.data));
            auto data = std::any_cast<obj_t>(rule.data);
            cpuf::printf("2\n"); 
            auto first = std::any_cast<Parser::Rule>(corelib::map::get(data, "first"));
            cpuf::printf("3\n");
            auto second = std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(data, "second"));
            second.insert(second.begin(), first);
            for (auto &el : second) {
                el = std::any_cast<Parser::Rule>(el.data);
            }
            auto mem = IR::member {
                IR::types::ACCESSOR,
                second,
            };
            push_to_elements(elements, member);
        }
        case Parser::Rules::Rule_hex:
        {
            cpuf::printf("hex\n");
            auto data = std::any_cast<std::string_view>(rule.data);
            std::string data_str(data.data(), data.size());
            arr_t<IR::expr> expr = {};
            bool is_first = true;
            if (data.size() % 2 != 0)
                data_str.insert(data_str.begin(), '0');
            for (int i = 0; i < data_str.size(); i += 2) {
                std::string hex(data_str.data() + i, 2);
                if (!is_first)
                    expr.push_back({IR::condition_types::AND});
                expr.push_back({IR::condition_types::CURRENT_CHARACTER});
                expr.push_back({IR::condition_types::EQUAL});
                expr.push_back({IR::condition_types::NUMBER, (char) hex::to_decimal(hex)});
                is_first = false;
            }
            // if (data.size() % 2 != 0) {
            //     auto last_char = data[data.size() - 1];
            //     std::string last_char_str(last_char, 1);
            //     if (!is_first)
            //         expr.push_back({IR::condition_types::AND});
                
            //     expr.push_back({IR::condition_types::GROUP_OPEN});
            //     expr.push_back({IR::condition_types::GROUP_OPEN});
            //     expr.push_back({IR::condition_types::CURRENT_CHARACTER});
            //     expr.push_back({IR::condition_types::BITWISE_AND});
            //     expr.push_back({IR::condition_types::NUMBER, 0xF0});
            //     expr.push_back({IR::condition_types::GROUP_CLOSE});
            //     expr.push_back({IR::condition_types::RIGHT_BITWISE});
            //     expr.push_back({IR::condition_types::NUMBER, 4});
            //     expr.push_back({IR::condition_types::GROUP_CLOSE});
            //     expr.push_back({IR::condition_types::EQUAL});
            //     expr.push_back({IR::condition_types::NUMBER, hex::to_decimal(last_char_str)});
            // }
            auto mem = IR::member {
                IR::types::IF,
                expr
            };
            member.push(mem);
            push_to_elements(elements, member);
        }
        case Parser::Rules::Rule_bin: 
        {
            cpuf::printf("bin\n");
            auto data = std::any_cast<std::string_view>(rule.data);
            std::string data_str(data.data(), data.size());
            arr_t<IR::expr> expr = {};
            bool is_first = true;
            while (data.size() % 4 != 0)
                data_str.insert(data_str.begin(), '0');
            for (int i = 0; i < data_str.size(); i += 4) {
                std::string hex(data_str, 2);
                if (!is_first)
                    expr.push_back({IR::condition_types::AND});
                expr.push_back({IR::condition_types::CURRENT_CHARACTER});
                expr.push_back({IR::condition_types::EQUAL});
                expr.push_back({IR::condition_types::NUMBER, (char) hex::to_decimal(hex::from_binary(hex))});
                is_first = false;
            }
            auto mem = IR::member {
                IR::types::IF,
                expr
            };
            member.push(mem);
            push_to_elements(elements, member);
        }
        default:
            return;
            //throw Error("Converting undefined rule");
    }
}
IR::ir rulesToIr(arr_t<Parser::Rule> rules) {
    IR::ir result;
    arr_t<IR::element_count> elements;
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