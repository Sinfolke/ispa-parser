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
        IR::var_assign_values::NONE,
        assign_next_rules
    };
    return var;
}
std::string generateVariableName(int &variable_count) {
    return std::string("_") + std::to_string(variable_count++);
}
void processExitStatements(IR::ir &values) {
    for (auto &el : values.elements) {
        if (el.type == IR::types::IF) {
            auto condition = std::any_cast<IR::condition>(el.value);
            for (auto &unit : condition.block) {
                if (unit.type == IR::types::EXIT) {
                    unit.type = IR::types::BREAK_LOOP;
                }
            }
            el.value = condition;
        }
    }
}

IR::variable createSuccessVariable(int &variable_count) {
    IR::variable var = createEmptyVariable(generateVariableName(variable_count));
    var.type = IR::var_type::BOOLEAN;
    var.value = IR::var_assign_values::FALSE;
    return var;
}

void addPostLoopCheck(IR::ir &new_ir, const IR::variable &var) {
    IR::variable_assign assign = { var.name, IR::var_assign_types::ASSIGN, IR::var_assign_values::TRUE };
    IR::condition check_cond = {
        { { IR::condition_types::VARIABLE, var.name },
          { IR::condition_types::EQUAL },
          { IR::condition_types::NUMBER, false } },
        { { IR::types::EXIT } }
    };
    new_ir.push({IR::types::ASSIGN_VARIABLE, assign});
    new_ir.push({IR::types::IF, check_cond});
}

// void handleQualifier(arr_t<IR::member> block, arr_t<expr> expression, char qualifier, int &variable_count) {
//     IR::ir new_ir;
//     if (qualifier == '*' || qualifier == '+') {
//         IR::condition loop = {{expression}, {} };
//         loop.block = block;
//         new_ir.push({IR::types::WHILE, loop});
//         if (qualifier == '+') {
//             IR::variable var = createSuccessVariable(variable_count);
//             new_ir.elements.clear();
//             new_ir.push({IR::types::VARIABLE, var});
//             new_ir.push({IR::types::WHILE, loop});
//             addPostLoopCheck(new_ir, var);
//         }
//     } else if (qualifier == '?') {
//         IR::condition loop = { { {IR::condition_types::NUMBER, 0} }, block };
//         new_ir.push({ IR::types::DOWHILE, loop });
//     } else {
//         return;
//     }
// }

void affectIrByQualifier(IR::ir values, char qualifier, int &variable_count) {
    IR::ir new_ir;
    if (qualifier == '*' || qualifier == '+') {
        IR::condition loop = { { { IR::condition_types::NUMBER, 1 } }, {} };
        processExitStatements(values);
        loop.block = values.elements;
        new_ir.push({IR::types::WHILE, loop});
        if (qualifier == '+') {
            IR::variable var = createSuccessVariable(variable_count);
            new_ir.elements.clear();
            new_ir.push({IR::types::VARIABLE, var});
            new_ir.push({IR::types::WHILE, loop});
            addPostLoopCheck(new_ir, var);
        }
    } else if (qualifier == '?') {
        IR::condition loop = { { {IR::condition_types::NUMBER, 0} }, values.elements };
        processExitStatements(values);
        new_ir.push({ IR::types::DOWHILE, loop });
    } else {
        return;
    }
    values = new_ir;
}
void processGroup(Parser::Rule rule, IR::ir &member, int &variable_count, char qualifier_char) {
    cpuf::printf("group\n");
    auto data = std::any_cast<obj_t>(rule.data);
    auto variable = corelib::map::get(data, "variable").has_value() ? std::any_cast<Parser::Rule>(corelib::map::get(data, "variable")) : Parser::Rule();
    auto val = std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(data, "val"));
    auto values = rulesToIr(val);
    auto method_call = IR::member {IR::types::METHOD_CALL};
    // create variable with name of "var" or with auto-generated one
    auto var = (!variable.empty() && std::any_cast<Parser::Rule>(variable.data).name == Parser::Rules::id) ?
                        createEmptyVariable(std::any_cast<std::string>(std::any_cast<Parser::Rule>(variable.data)), values.size()) :
                        createEmptyVariable(generateVariableName(variable_count), values.size());

    affectIrByQualifier(values, qualifier_char, variable_count);
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
    }

    cpuf::printf("5\n");
}
void processRuleCsequence(Parser::Rule rule, IR::ir &member, int &variable_count, char qualifier_char) {
    cpuf::printf("csequence\n");
    auto data = std::any_cast<obj_t>(rule.data);
    auto _not = std::any_cast<bool>(corelib::map::get(data, "not"));
    auto values = std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(data, "val"));

    auto var = createEmptyVariable(generateVariableName(variable_count));
    bool is_negative = false;
    arr_t<IR::expr> expr;

    if ((!_not && qualifier_char == '\0') || _not) {
        expr = {
            {IR::condition_types::NOT},
            {IR::condition_types::GROUP_OPEN}
        };
        is_negative = true;
    }

    bool first = true;
    for (auto &value : values) {
        if (!first)
            expr.push_back({IR::condition_types::AND});
        first = false;

        switch (value.name) {
            case Parser::Rules::Rule_csequence_diapason: {
                auto range_data = std::any_cast<arr_t<char>>(value.data);
                expr.insert(expr.end(), {
                    {IR::condition_types::GROUP_OPEN},
                    {IR::condition_types::CURRENT_CHARACTER},
                    {IR::condition_types::HIGHER_OR_EQUAL},
                    {IR::condition_types::CHARACTER, range_data[0]},
                    {IR::condition_types::AND},
                    {IR::condition_types::CURRENT_CHARACTER},
                    {IR::condition_types::LOWER_OR_EQUAL},
                    {IR::condition_types::CHARACTER, range_data[1]},
                    {IR::condition_types::GROUP_CLOSE}
                });
                break;
            }
            case Parser::Rules::Rule_csequence_escape:
            case Parser::Rules::Rule_csequence_symbol: {
                auto char_data = std::any_cast<std::string>(value.data);
                expr.insert(expr.end(), {
                    {IR::condition_types::CURRENT_CHARACTER},
                    {IR::condition_types::EQUAL},
                    {IR::condition_types::CHARACTER, char_data}
                });
                break;
            }
            default:
                throw Error("undefined csequence subrule");
        }
    }

    if (is_negative) {
        expr.push_back({IR::condition_types::GROUP_CLOSE});
    }
    member.push({IR::types::VARIABLE, var});
    arr_t<IR::member> block = {
        {IR::types::ASSIGN_VARIABLE, IR::variable_assign {var.name, IR::var_assign_types::ADD, IR::var_assign_values::CURRENT_POS_SEQUENCE}},
        {IR::types::INCREASE_POS_COUNTER}
    };

    switch (qualifier_char) {
        case '+':
        case '*':
            member.push({IR::types::WHILE, IR::condition{expr, block}});
            break;
        case '?':
            member.push({IR::types::IF, IR::condition{expr, block}});
            break;
        default:
            member.push({IR::types::IF, IR::condition{expr, {{IR::types::EXIT}}}});
            member.push(
                IR::member{ 
                    IR::types::ASSIGN_VARIABLE, 
                    IR::variable_assign {var.name, IR::var_assign_types::ASSIGN, IR::var_assign_values::CURRENT_POS_SEQUENCE}
                }
            );
            member.push({IR::types::INCREASE_POS_COUNTER});
            break;
    }
}
void processString(Parser::Rule rule, IR::ir &member, char qualifier_char) {
    cpuf::printf("string, type: %s\n", rule.data.type().name());
    auto data = std::any_cast<std::string>(rule.data);
    arr_t<IR::expr> expr = {
        {IR::condition_types::STRNCMP, data}
    };
    arr_t<IR::member> block;
    switch (qualifier_char) {
        case '+':
        case '*':
            member.push({IR::types::WHILE, IR::condition{expr}});
            break;
        case '?':
            member.push({IR::types::IF, IR::condition{expr}});
            break;
        default:
            expr.insert(expr.begin(), {IR::condition_types::NOT});
            member.push({IR::types::IF, IR::condition{expr}});
            break;
    }
    auto mem = IR::member {
        IR::types::IF,
        expr
    };
    member.push(mem);
}
void ruleToIr(Parser::Rule &rule_rule, IR::ir &member, arr_t<IR::element_count> &elements, int &variable_count) {
    member.push({ IR::types::RULE, });
    cpuf::printf("ENTER_1\n");
    auto rule_data = std::any_cast<obj_t>(rule_rule.data);
    cpuf::printf("ENTER_2\n");
    auto rule = std::any_cast<Parser::Rule>(corelib::map::get(rule_data, "val"));
    cpuf::printf("ENTER_3\n");
    auto qualifier = std::any_cast<Parser::Rule>(corelib::map::get(rule_data, "qualifier"));
    char qualifier_char = '\0';
    if (qualifier.data.type() == typeid(char)) {
        cpuf::printf("ENTER_4\n");
        qualifier_char = std::any_cast<char>(qualifier.data);
    }
    switch (rule.name) {
        case Parser::Rules::Rule_group: 
            processGroup(rule, member, variable_count, qualifier_char);
            break;
        case Parser::Rules::Rule_csequence:
            processRuleCsequence(rule, member, variable_count, qualifier_char);
            break;
        case Parser::Rules::string:
            processString(rule, member, qualifier_char);
            break;
        case Parser::Rules::accessor:
        {
            cpuf::printf("accessor, type: %s\n", Parser::RulesToString(rule.name));
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
            break;
        }
        case Parser::Rules::Rule_hex:
        {
            cpuf::printf("hex\n");
            auto data = std::any_cast<std::string_view>(rule.data);
            std::string data_str(data.data(), data.size());
            arr_t<IR::expr> expr = {};
            bool is_first = true;
            if (qualifier_char == '?' || qualifier_char == '\0') {
                expr.push_back({IR::condition_types::NOT});
                expr.push_back({IR::condition_types::GROUP_OPEN});
            }
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
            break;
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
            break;
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