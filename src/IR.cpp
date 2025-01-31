#include <IR.h>
#include <IR-debug.h>
#include <internal_types.h>
#include <token_management.h>
#include <corelib.h>
#include <parser.h>
#include <cpuf/hex.h>
// a structure used to cout
void IR::ir::add(IR::ir repr) {
    elements.insert(elements.end(), repr.elements.begin(), repr.elements.end());
}
void IR::ir::add(arr_t<IR::member> repr) {
    elements.insert(elements.end(), repr.begin(), repr.end());
}
void IR::ir::push(IR::member member) {
    elements.push_back(member);
}
size_t IR::ir::size() {
    return elements.size();
}
bool IR::ir::empty() {
    return elements.empty();
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
    IR::variable var = createEmptyVariable("success" + generateVariableName(variable_count));
    var.type = IR::var_type::BOOLEAN;
    var.value = {IR::var_assign_values::_FALSE};
    return var;
}

void addPostLoopCheck(IR::ir &new_ir, const IR::variable &var) {
    IR::condition check_cond = {
        { { IR::condition_types::VARIABLE, var.name },
          { IR::condition_types::EQUAL },
          { IR::condition_types::NUMBER, (long long) false } },
        { { IR::types::EXIT } }
    };
    new_ir.push({IR::types::IF, check_cond});
}
void handle_plus_qualifier(IR::condition loop, IR::ir &new_ir, int &variable_count) {
    IR::variable var = createSuccessVariable(variable_count);
    loop.block.push_back({IR::types::ASSIGN_VARIABLE, IR::variable_assign {var.name, IR::var_assign_types::ASSIGN, IR::var_assign_values::_TRUE}});
    new_ir.push({IR::types::VARIABLE, var});
    new_ir.push({IR::types::WHILE, loop});
    addPostLoopCheck(new_ir, var);
}
arr_t<IR::member> createDefaultBlock(IR::variable var, IR::variable svar) {
    return {
        {IR::types::ASSIGN_VARIABLE, IR::variable_assign {var.name, IR::var_assign_types::ADD, IR::var_assign_values::CURRENT_POS_SEQUENCE}},
        {IR::types::ASSIGN_VARIABLE, IR::variable_assign {svar.name, IR::var_assign_types::ASSIGN, IR::var_assign_values::_TRUE}},
        {IR::types::INCREASE_POS_COUNTER}
    };
}
arr_t<IR::member> createDefaultBlock(IR::variable svar) {
    return {
        {IR::types::ASSIGN_VARIABLE, IR::variable_assign {svar.name, IR::var_assign_types::ASSIGN, IR::var_assign_values::_TRUE}},
        {IR::types::INCREASE_POS_COUNTER}
    };
}
arr_t<IR::member> createDefaultBlock() {
    return {
        {IR::types::INCREASE_POS_COUNTER}
    };
}
void createDefaultCall(const arr_t<IR::member> &block, const IR::variable var, const std::string &name, IR::ir &member, arr_t<IR::expr> &expr) {
    auto function_call = IR::function_call {
        name,
        {{IR::var_assign_values::TOKEN_SEQUENCE}}
    };
    auto var_assign = IR::variable_assign {
        var.name, 
        IR::var_assign_types::ASSIGN,
        { IR::var_assign_values::FUNCTION_CALL, function_call }
    };
    expr = {
        {IR::condition_types::SUCCESS_CHECK, var.name}
    };
    member.push({IR::types::ASSIGN_VARIABLE, var_assign});
}
void pushBasedOnQualifier(arr_t<IR::expr> expr, arr_t<IR::member> block, IR::variable svar, IR::ir &member, char qualifier_char, int &variable_count) {
    //block.push_back({IR::types::ASSIGN_VARIABLE, IR::variable_assign {svar.name, IR::var_assign_types::ASSIGN, IR::var_assign_values::_TRUE}});
    switch (qualifier_char) {
        case '+':
            handle_plus_qualifier({expr, block}, member, variable_count);
            break;
        case '*': {
            IR::member pop = block.back();
 
            //block.pop_back();
            member.push({IR::types::WHILE, IR::condition{expr, block}});
            //member.push(pop);
            break;
        }
        case '?':
            member.push({IR::types::IF, IR::condition{expr, block}});
            break;
        default:
            expr.insert(expr.begin(), {IR::condition_types::NOT});
            expr.insert(expr.begin() + 1, {IR::condition_types::GROUP_OPEN});
            expr.push_back({IR::condition_types::GROUP_CLOSE});
            member.push({IR::types::IF, IR::condition{expr, {{IR::types::EXIT}}}});
            member.add(block);
            break;
    }
}
void affectIrByQualifier(IR::ir values, char qualifier, int &variable_count) {
    IR::ir new_ir;
    if (qualifier == '*' || qualifier == '+') {
        IR::condition loop = { { { IR::condition_types::NUMBER, (long long) 1 } }, {} };
        processExitStatements(values);
        loop.block = values.elements;
        new_ir.push({IR::types::WHILE, loop});
        if (qualifier == '+') {
            new_ir.elements.clear();
            handle_plus_qualifier(loop, new_ir, variable_count);
        }
    } else if (qualifier == '?') {
        IR::condition loop = { { {IR::condition_types::NUMBER, (long long) 0} }, values.elements };
        processExitStatements(values);
        new_ir.push({ IR::types::DOWHILE, loop });
    } else {
        return;
    }
    values = new_ir;
}
IR::node_ret_t processGroup(Parser::Rule rule, IR::ir &member, int &variable_count, char qualifier_char, bool isToken) {
    //cpuf::printf("group\n");
    auto data = std::any_cast<obj_t>(rule.data);
    auto variable = corelib::map::get(data, "variable").has_value() ? std::any_cast<Parser::Rule>(corelib::map::get(data, "variable")) : Parser::Rule();
    auto val = std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(data, "val"));
    arr_t<IR::node_ret_t> success_vars;
    auto values = rulesToIr(val, isToken, success_vars, variable_count);
    //cpuf::printf("Values got: \n");
    IR::outputIRToConsole(values);
    //cpuf::printf("End values\n");
    auto method_call = IR::member {IR::types::METHOD_CALL};
    // create variable with name of "var" or with auto-generated one
    auto var = (!variable.empty() && variable.name == Parser::Rules::id) ?
                        createEmptyVariable(std::any_cast<std::string>(variable.data), values.size()) :
                        createEmptyVariable(generateVariableName(variable_count), values.size());
    auto svar = createSuccessVariable(variable_count);
    arr_t<IR::expr> svar_expr = {};
    //cpuf::printf("success_vars.size(): %d\n", success_vars.size());
    for (int i = 0; i < success_vars.size(); i++) {
        if (i != 0)
            svar_expr.push_back({IR::condition_types::AND});
        svar_expr.push_back({IR::condition_types::VARIABLE, success_vars[i]});
    }
    auto svar_cond = IR::member {
        IR::types::IF,
        IR::condition {
            svar_expr,
            {{IR::types::ASSIGN_VARIABLE, IR::variable_assign {svar.name, IR::var_assign_types::ASSIGN, IR::var_assign_values::_TRUE}}}
        }
    };
    affectIrByQualifier(values, qualifier_char, variable_count);
    if (!variable.empty() && variable.name == Parser::Rules::method_call) {
        auto var_rule = std::any_cast<Parser::Rule>(variable.data);
        auto var_rule_data = std::any_cast<obj_t>(var_rule.data);
        method_call.value = var_rule_data;
        member.push({IR::types::VARIABLE, var});
        member.push({IR::types::VARIABLE, svar});
        member.push({IR::types::GROUP});
        member.add(values);
        member.push({IR::types::METHOD_CALL, method_call});
    } else {
        member.push({IR::types::VARIABLE, var});
        member.push({IR::types::VARIABLE, svar});
        member.add(values);
    }
    member.push(svar_cond);
    return svar.name;
}
IR::node_ret_t processRuleCsequence(const Parser::Rule &rule, IR::ir &member, int &variable_count, char qualifier_char) {
    //cpuf::printf("csequence\n");
    auto data = std::any_cast<obj_t>(rule.data);
    auto _not = std::any_cast<bool>(corelib::map::get(data, "not"));
    auto values = std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(data, "val"));

    auto var = createEmptyVariable(generateVariableName(variable_count));
    auto svar = createSuccessVariable(variable_count);
    var.type = IR::var_type::STRING;
    bool is_negative = false;
    arr_t<IR::expr> expr;

    if (_not) {
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

        switch (value.name) {
            case Parser::Rules::Rule_csequence_diapason: {
                auto range_data = std::any_cast<arr_t<Parser::Rule>>(value.data);
                auto first = std::any_cast<std::string>(range_data[0].data)[0];
                auto second = std::any_cast<std::string>(range_data[1].data)[0];
                expr.insert(expr.end(), {
                    {IR::condition_types::GROUP_OPEN},
                    {IR::condition_types::CURRENT_CHARACTER},
                    {IR::condition_types::HIGHER_OR_EQUAL},
                    {IR::condition_types::CHARACTER, first},
                    {IR::condition_types::AND},
                    {IR::condition_types::CURRENT_CHARACTER},
                    {IR::condition_types::LOWER_OR_EQUAL},
                    {IR::condition_types::CHARACTER, second},
                    {IR::condition_types::GROUP_CLOSE}
                });
                break;
            }
            case Parser::Rules::Rule_csequence_escape:
            case Parser::Rules::Rule_csequence_symbol:
                expr.insert(expr.end(), {
                    {IR::condition_types::CURRENT_CHARACTER},
                    {IR::condition_types::EQUAL},
                    {IR::condition_types::CHARACTER, (char) std::any_cast<std::string>(value.data)[0]}
                });
                break;
            default:
                throw Error("undefined csequence subrule");
        }
        first = false;
    }

    if (is_negative) {
        expr.push_back({IR::condition_types::GROUP_CLOSE});
    }
    int size = member.size();
    member.push({IR::types::VARIABLE, var});
    member.push({IR::types::VARIABLE, svar});
    arr_t<IR::member> block = createDefaultBlock(var, svar);
    pushBasedOnQualifier(expr, block, svar, member, qualifier_char, variable_count);
    return svar.name;
}
IR::node_ret_t processString(const Parser::Rule &rule, IR::ir &member, int &variable_count, char qualifier_char) {
    //cpuf::printf("string, data: %s\n", std::any_cast<std::string>(rule.data));
    auto data = std::any_cast<std::string>(rule.data);
    auto var = createEmptyVariable(generateVariableName(variable_count));
    auto svar = createSuccessVariable(variable_count);
    var.type = IR::var_type::STRING;
    arr_t<IR::expr> expr = {
        {IR::condition_types::STRNCMP, data}
    };
    arr_t<IR::member> block = createDefaultBlock(var, svar);
    member.push({IR::types::VARIABLE, var});
    member.push({IR::types::VARIABLE, svar});
    pushBasedOnQualifier(expr, block, svar, member, qualifier_char, variable_count);
    return svar.name;
}
IR::node_ret_t process_Rule_hex(const Parser::Rule &rule, IR::ir &member, int &variable_count, char qualifier_char) {
    //cpuf::printf("hex\n");
    auto data = std::any_cast<std::string_view>(rule.data);
    std::string data_str(data.data(), data.size());
    arr_t<IR::expr> expr = {};
    auto var = createEmptyVariable(generateVariableName(variable_count));
    auto svar = createSuccessVariable(variable_count);
    var.type = IR::var_type::STRING;
    arr_t<IR::member> block = createDefaultBlock(var, svar);
    bool is_first = true, is_negative = false;
    if (qualifier_char == '\0') {
        expr.push_back({IR::condition_types::NOT});
        expr.push_back({IR::condition_types::GROUP_OPEN});
        is_negative = true;
    }
    if (data.size() % 2 != 0)
        data_str.insert(data_str.begin(), '0');
    for (int i = 0; i < data_str.size(); i += 2) {
        std::string hex(data_str.data() + i, 2);
        if (!is_first)
            expr.push_back({IR::condition_types::AND});
        is_first = false;
        expr.push_back({IR::condition_types::CURRENT_CHARACTER});
        expr.push_back({IR::condition_types::EQUAL});
        expr.push_back({IR::condition_types::NUMBER, (long long) hex::to_decimal(hex)});
    }
    if (is_negative) {
        expr.push_back({IR::condition_types::GROUP_CLOSE});
    }
    //cpuf::printf("hex_open\n");
    int size = member.size();
    member.push({IR::types::VARIABLE, var});
    member.push({IR::types::VARIABLE, svar});
    pushBasedOnQualifier(expr, block, svar, member, qualifier_char, variable_count);
    for (int i = size; i < member.size(); i++) {
        IR::convertMember(member.elements[i], std::cout, 0);
    }
    //cpuf::printf("hex_close\n");
    return svar.name;
}
IR::node_ret_t process_Rule_bin(const Parser::Rule &rule, IR::ir &member, int &variable_count, char qualifier_char) {
    //cpuf::printf("hex\n");
    auto data = std::any_cast<std::string_view>(rule.data);
    std::string data_str(data.data(), data.size());
    arr_t<IR::expr> expr = {};
    auto var = createEmptyVariable(generateVariableName(variable_count));
    auto svar = createSuccessVariable(variable_count);
    arr_t<IR::member> block = {
        {IR::types::ASSIGN_VARIABLE, IR::variable_assign {var.name, IR::var_assign_types::ADD, IR::var_assign_values::CURRENT_POS_SEQUENCE}},
        {IR::types::INCREASE_POS_COUNTER},
    };
    bool is_first = true, is_negative = false;
    if (qualifier_char == '\0') {
        expr.push_back({IR::condition_types::NOT});
        expr.push_back({IR::condition_types::GROUP_OPEN});
        is_negative = true;
    }
    while (data.size() % 4 != 0)
        data_str.insert(data_str.begin(), '0');
    for (int i = 0; i < data_str.size(); i += 2) {
        std::string bin(data_str.data() + i, 4);
        if (!is_first)
            expr.push_back({IR::condition_types::AND});
        is_first = false;
        expr.push_back({IR::condition_types::CURRENT_CHARACTER});
        expr.push_back({IR::condition_types::EQUAL});
        expr.push_back({IR::condition_types::NUMBER, (long long) hex::to_decimal(hex::from_binary(bin))});
    }
    if (is_negative) {
        expr.push_back({IR::condition_types::GROUP_CLOSE});
    }
    member.push({IR::types::VARIABLE, var});
    member.push({IR::types::VARIABLE, svar});
    pushBasedOnQualifier(expr, block, svar, member, qualifier_char, variable_count);
    return svar.name;
}
IR::node_ret_t processAccessor(const Parser::Rule &rule, IR::ir &member, int &variable_count, char qualifier_char) {
    //cpuf::printf("accessor\n");
    auto data = std::any_cast<obj_t>(rule.data);
    auto first = std::any_cast<Parser::Rule>(corelib::map::get(data, "first"));
    auto second = std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(data, "second"));
    auto svar = createSuccessVariable(variable_count);
    second.insert(second.begin(), first);
    for (auto &el : second) {
        el = std::any_cast<Parser::Rule>(el.data);
    }
    auto mem = IR::member {
        IR::types::ACCESSOR,
        IR::accessor { second, qualifier_char }
    };
    member.push({IR::types::VARIABLE, svar});
    member.push(mem);
    return svar.name;
}
IR::node_ret_t process_Rule_other(const Parser::Rule &rule, IR::ir &member, int &variable_count, char qualifier_char, bool isToken) {
    //cpuf::printf("Rule_other");
    auto data = std::any_cast<obj_t>(rule.data);
    auto name = std::any_cast<Parser::Rule>(corelib::map::get(data, "name"));
    auto name_str = std::any_cast<std::string>(name.data);
    //cpuf::printf(", name: %s\n", name_str);

    auto var = createEmptyVariable(generateVariableName(variable_count));
    auto svar = createSuccessVariable(variable_count);
    
    bool isCallingToken = isupper(name_str[0]);
    var.type = isCallingToken ? IR::var_type::Token : IR::var_type::Rule;
    auto block = createDefaultBlock(var, svar);
    if (isToken) {
        // replace variable assignment from pos sequence to current token
        if (!isCallingToken) return svar.name;
            //throw Error("Cannot call rule from token");
        // remove variable assignemnt
        block.erase(block.begin());
        arr_t<IR::expr> expr;
        createDefaultCall(block, var, name_str, member, expr);
        pushBasedOnQualifier(expr, block, svar, member, qualifier_char, variable_count);
    } else {
        if (isCallingToken) {
            block[0] = {
                IR::types::ASSIGN_VARIABLE, 
                IR::variable_assign {
                    var.name,
                    IR::var_assign_types::ASSIGN,
                    IR::var_assign_values::CURRENT_TOKEN
                }
            };
            arr_t<IR::expr> expr = {
                {IR::condition_types::CURRENT_TOKEN},
                {IR::condition_types::EQUAL},
                {IR::condition_types::STRING, name_str}
            };
            pushBasedOnQualifier(expr, block, svar, member, qualifier_char, variable_count);
        } else {

            // remove variable assignemnt
            block.erase(block.begin());
            arr_t<IR::expr> expr;
            createDefaultCall(block, var, name_str, member, expr);
            pushBasedOnQualifier(expr, block, svar, member, qualifier_char, variable_count);
        }

    }
    return svar.name;
}
IR::node_ret_t process_Rule_escaped(const Parser::Rule &rule, IR::ir &member, int &variable_count, char qualifier_char, bool &add_space) {
    //cpuf::printf("Rule_escaped\n");
    auto data = std::any_cast<obj_t>(rule.data);
    auto c = std::any_cast<std::string>(corelib::map::get(data, "c"));
    auto num = std::any_cast<Parser::Rule>(corelib::map::get(data, "num"));
    obj_t num_data;
    double num_main;
    if (num.data.has_value()) {
        num_data = num.as<obj_t>();
        num_main = std::any_cast<double>(corelib::map::get(num_data, "main_n"));
    } else {
        num_main = -1;
    }
    auto var = createEmptyVariable(generateVariableName(variable_count));
    auto svar = createSuccessVariable(variable_count);
    var.type = IR::var_type::STRING;
    arr_t<IR::expr> expression;
    arr_t<IR::member> block = {{IR::types::EXIT}};
    arr_t<IR::member> block_after = createDefaultBlock(var, svar);
    if (qualifier_char != '\0')
        UWarning("Qualifier after \\%s ignored", c).print();
    switch (c[0]) {
        case 's':
            if (num_main == 0) {
                // means do not add skip of spaces
                add_space = false;
                //cpuf::printf("on_exit\n");
                return svar.name;
            } else if (num_main != -1) {
                UWarning("Number after \\s ignored").print();
            }
            //cpuf::printf("ON_EXPRESSION\n");
            expression = {
                {IR::condition_types::CURRENT_CHARACTER},
                {IR::condition_types::NOT_EQUAL},
                {IR::condition_types::CHARACTER, ' '}
            };
            break;
        default:
            throw Error("Undefined char '%c'", c[0]);
            
    }
    //cpuf::printf("escaped_open\n");
    int size = member.size();

    member.push({IR::types::VARIABLE, var});
    member.push({IR::types::VARIABLE, svar});
    member.push({IR::types::IF, IR::condition{expression, block}});
    member.add(block_after);
    for (int i = size; i < member.size(); i++) {
        IR::convertMember(member.elements[i], std::cout, 0);
    }
    //cpuf::printf("escaped_close\n");
    return svar.name;
}
IR::node_ret_t process_Rule_any(const Parser::Rule &rule, IR::ir &member, int &variable_count, char qualifier_char, bool &add_space) {
    //cpuf::printf("Rule_any\n");
    auto var = createEmptyVariable(generateVariableName(variable_count));
    auto svar = createSuccessVariable(variable_count);
    arr_t<IR::expr> expression;
    arr_t<IR::member> block = {{IR::types::EXIT}};
    arr_t<IR::member> block_after = createDefaultBlock(var, svar);
    if (qualifier_char != '\0')
        UWarning("Qualifier after . ignored").print();
    expression = {
        {IR::condition_types::CURRENT_CHARACTER},
        {IR::condition_types::EQUAL},
        {IR::condition_types::CHARACTER, '\0'}
    };
    member.push({IR::types::VARIABLE, var});
    member.push({IR::types::IF, IR::condition{expression, block}});
    member.add(block_after);
    return svar.name;
}
arr_t<IR::member> construct_block(const arr_t<arr_t<IR::member>> &blocks, const arr_t<arr_t<IR::expr>> &conditions, size_t i = 0) {
    if (i >= blocks.size()) {
        return {{IR::types::EXIT}};
    }

    arr_t<IR::member> block = blocks[i];

    block.push_back({
        IR::types::IF,
        IR::condition {
            conditions[i],
            construct_block(blocks, conditions, i + 1) // Instead of recursive call, directly reference the next block
        }
    });


    return block;
}

arr_t<IR::member> convert_op_rule(arr_t<Parser::Rule> &rules, IR::ir &member, int &variable_count, char qualifier_char, bool isToken) {
    if (rules.empty()) {
        return {{IR::types::EXIT}};
    }

    IR::node_ret_t success_var;
    arr_t<arr_t<IR::member>> blocks;
    arr_t<arr_t<IR::expr>> conditions;
    auto rule = rules[0];
    rules.erase(rules.begin());
    IR::ir new_ir;
    cpuf::printf("rule name: %s, IF_RULE_OTHER_VALUE: ", Parser::RulesToString(rule.name));
    if (rule.name == Parser::Rules::Rule_other) {
        auto data = std::any_cast<obj_t>(rule.data);
        auto first = std::any_cast<Parser::Rule>(corelib::map::get(data, "name"));
        auto first_str = std::any_cast<std::string>(first.data);
        cpuf::printf("%s\n", first_str);
    } else {
        cpuf::printf("<null>\n");
    }
    auto Rule_rule = Tokens::make_rule(Parser::Rules::Rule_rule, obj_t {
        {"val", rule},
        {"qualifier", Parser::Rule()}
    });
    ruleToIr(Rule_rule, new_ir, variable_count, isToken, success_var);

    std::vector<int> erase_indices;
    std::vector<int> push_indices;
    switch(rule.name) {
        case Parser::Rules::string:
        case Parser::Rules::Rule_any:
        case Parser::Rules::Rule_csequence:
        case Parser::Rules::Rule_escaped:
        case Parser::Rules::Rule_other:
            for (int i = 0; i < new_ir.elements.size(); i++) {
                auto &el = new_ir.elements[i];
                if (el.type == IR::types::IF) {
                    auto val = std::any_cast<IR::condition>(el.value);
                    if (!val.block.empty() && val.block[0].type == IR::types::EXIT) {
                        val.block = convert_op_rule(rules, member, variable_count, qualifier_char, isToken);
                        for (int j = i + 1; j < new_ir.elements.size(); j++) {
                            if (new_ir.elements[j].type == IR::types::INCREASE_POS_COUNTER)
                                continue;
                            val.else_block.push_back(new_ir.elements[j]);
                            erase_indices.push_back(j);
                        }
                        el.value = val;  // Ensure value is update
                    }
                } else if (el.type == IR::types::INCREASE_POS_COUNTER) {
                    erase_indices.push_back(i);
                }
            }
            break;
        case Parser::Rules::Rule_group:
            break;
    }

    // Erase marked indices in reverse to prevent shifting issues
    for (int i = erase_indices.size() - 1; i >= 0; i--) {
        new_ir.elements.erase(new_ir.elements.begin() + erase_indices[i]);
    }

    return new_ir.elements;
}

IR::node_ret_t process_Rule_op(const Parser::Rule &rule, IR::ir &member, int &variable_count, char qualifier_char, bool isToken) {
    cpuf::printf("Rule_op, type: %s\n", rule.data.type().name());

    auto op = std::any_cast<arr_t<Parser::Rule>>(rule.data);
    auto var = createEmptyVariable(generateVariableName(variable_count));
    auto svar = createSuccessVariable(variable_count);
    auto block = createDefaultBlock(var, svar);
    auto size = member.size();

    // Add success variable
    member.push({IR::types::VARIABLE, var});
    member.push({IR::types::VARIABLE, svar});

    // Convert rules into IR
    member.add(convert_op_rule(op, member, variable_count, qualifier_char, isToken));

    // Append default block
    member.add(block);

    // Debug output
    cpuf::printf("rules got (rule_op): \n");
    for (int i = size; i < member.size(); i++) {
        IR::convertMember(member.elements[i], std::cout, 0);
    }
    cpuf::printf("\n");

    return svar.name;
}
void ruleToIr(Parser::Rule &rule_rule, IR::ir &member, int &variable_count, bool isToken, IR::node_ret_t &success_var) {
    //member.push({ IR::types::RULE, });
    auto rule_data = std::any_cast<obj_t>(rule_rule.data);
    auto rule = std::any_cast<Parser::Rule>(corelib::map::get(rule_data, "val"));
    auto qualifier = std::any_cast<Parser::Rule>(corelib::map::get(rule_data, "qualifier"));
    char qualifier_char = '\0';
    if (qualifier.data.has_value()) {
        qualifier_char = std::any_cast<char>(qualifier.data);
    }
    if (!isToken && (rule.name != Parser::Rules::Rule_other && rule.name != Parser::Rules::Rule_group && rule.name != Parser::Rules::Rule_op && rule.name != Parser::Rules::cll && rule.name != Parser::Rules::linear_comment && rule.name != Parser::Rules::accessor)  ) {
        //throw Error("Rule having literals. Name: %s", Parser::RulesToString(rule.name));
        return;
    }
    bool add_space_skip = true;
    switch (rule.name) {
        case Parser::Rules::Rule_group: 
            success_var = processGroup(rule, member, variable_count, qualifier_char, isToken);
            break;
        case Parser::Rules::Rule_csequence:
            success_var = processRuleCsequence(rule, member, variable_count, qualifier_char);
            break;
        case Parser::Rules::string:
            success_var = processString(rule, member, variable_count, qualifier_char);
            break;
        case Parser::Rules::accessor:
            success_var = processAccessor(rule, member, variable_count, qualifier_char);
            break;
        case Parser::Rules::Rule_hex:
            success_var = process_Rule_hex(rule, member, variable_count, qualifier_char);
            break;
        case Parser::Rules::Rule_bin: 
            success_var = process_Rule_bin(rule, member, variable_count, qualifier_char);
            break;
        case Parser::Rules::Rule_other:
            success_var = process_Rule_other(rule, member, variable_count, qualifier_char, isToken);
            break;
        case Parser::Rules::Rule_escaped:
            success_var = process_Rule_escaped(rule, member, variable_count, qualifier_char, add_space_skip);
            break;
        case Parser::Rules::Rule_any:
            success_var = process_Rule_any(rule, member, variable_count, qualifier_char, add_space_skip);
            break;
        case Parser::Rules::Rule_op:
            success_var = process_Rule_op(rule, member, variable_count, qualifier_char, isToken);
            break;
        case Parser::Rules::cll:
            break;
        case Parser::Rules::linear_comment:
            return;
        default:
            return;
            throw Error("Converting undefined rule");
    }
}
IR::ir rulesToIr(arr_t<Parser::Rule> rules, bool isToken, arr_t<IR::node_ret_t> &success_vars, int &variable_count) {
    IR::ir result;
    arr_t<IR::element_count> elements;
    for (auto &rule : rules) {
        IR::node_ret_t success_var;
        ruleToIr(rule, result, variable_count, isToken, success_var);
        success_vars.push_back(success_var);
    }
    return result;
}
IR::ir rulesToIr(arr_t<Parser::Rule> rules, bool isToken, arr_t<IR::node_ret_t> &success_vars) {
    IR::ir result;
    arr_t<IR::element_count> elements;
    int variable_count = 0;
    for (auto &rule : rules) {
        IR::node_ret_t success_var;
        ruleToIr(rule, result, variable_count, isToken, success_var);
        success_vars.push_back(success_var);
    }
    return result;
}
IR::ir rulesToIr(arr_t<Parser::Rule> rules, bool isToken, int &variable_count) {
    IR::ir result;
    arr_t<IR::element_count> elements;
    for (auto &rule : rules) {
        IR::node_ret_t success_var;
        ruleToIr(rule, result, variable_count, isToken, success_var);
    }
    return result;
}
IR::ir rulesToIr(arr_t<Parser::Rule> rules, bool isToken) {
    IR::ir result;
    arr_t<IR::element_count> elements;
    int variable_count = 0;
    for (auto &rule : rules) {
        IR::node_ret_t success_var;
        ruleToIr(rule, result, variable_count, isToken, success_var);
    }
    return result;
}
IR::ir treeToIr(Parser::Tree &tree) {
    IR::ir result_ir;
    for (auto &el : tree) {
        if (el.name != Parser::Rules::Rule)
            continue;
        auto data = std::any_cast<obj_t>(el.data);
        auto name = std::any_cast<std::string>(std::any_cast<Parser::Rule>(corelib::map::get(data, "name")).data);
        auto rules = std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(data, "rule"));
        result_ir.add(rulesToIr(rules, isupper(name[0])));
    }
    return result_ir;
}