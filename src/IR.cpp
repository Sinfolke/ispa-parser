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
void IR::ir::pop() {
    elements.pop_back();
};
size_t IR::ir::size() {
    return elements.size();
}
bool IR::ir::empty() {
    return elements.empty();
}
void push_to_elements(arr_t<IR::element_count> &elements, IR::ir &member) {
    elements.push_back({member.size(), elements.size() > 0 ? elements.back().index_in_rule : 0});
}
void push_to_elements_increament(arr_t<IR::element_count> &elements, IR::ir &member) {
    elements.push_back({member.size(), elements.size() > 0 ? elements.back().index_in_rule + 1 : 0});
}
IR::variable createEmptyVariable(std::string name, int assign_next_rules=0) {
    IR::variable var {
        {IR::var_types::UNDEFINED},
        name,
        IR::var_assign_values::NONE,
        assign_next_rules
    };
    return var;
}
std::string generateVariableName(int &variable_count) {
    return std::string("_") + std::to_string(variable_count++);
}
void processExitStatements(arr_t<IR::member> &values) {
    for (auto &el : values) {
        if (el.type == IR::types::IF || el.type == IR::types::WHILE || el.type == IR::types::DOWHILE) {
            auto condition = std::any_cast<IR::condition>(el.value);
            
            // Process the block and else block of the condition recursively
            processExitStatements(condition.block);
            processExitStatements(condition.else_block);

            // Ensure that any EXIT statements within the blocks are replaced with BREAK_LOOP
            for (auto &unit : condition.block) {
                if (unit.type == IR::types::EXIT) {
                    unit.type = IR::types::BREAK_LOOP; // Replacing EXIT with BREAK_LOOP
                } else if (unit.type == IR::types::IF || unit.type == IR::types::WHILE || unit.type == IR::types::DOWHILE) {
                    auto cond = std::any_cast<IR::condition>(unit.value);
                    processExitStatements(cond.block); // Recursive call on nested blocks
                    processExitStatements(cond.else_block); // Recursive call on else blocks
                    unit.value = cond; // Update unit with the modified condition
                }
            }
            el.value = condition; // Update the original element with the modified condition
        }
    }
}

IR::variable createSuccessVariable(int &variable_count) {
    IR::variable var = createEmptyVariable("success" + generateVariableName(variable_count));
    var.type = {IR::var_types::BOOLEAN};
    var.value = {IR::var_assign_values::_FALSE};
    return var;
}

void addPostLoopCheck(IR::ir &new_ir, const IR::variable &var) {
    IR::condition check_cond = {
        { 
            {IR::condition_types::NOT}, 
            { IR::condition_types::VARIABLE, var.name },
        },
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
void affectIrByQualifier(IR::ir &values, char qualifier, int &variable_count) {
    IR::ir new_ir;
    if (qualifier == '*' || qualifier == '+') {
        IR::condition loop = { { { IR::condition_types::NUMBER, (long long) 1 } }, {} };
        processExitStatements(values.elements);
        loop.block = values.elements;
        new_ir.push({IR::types::WHILE, loop});
        if (qualifier == '+') {
            new_ir.elements.clear();
            handle_plus_qualifier(loop, new_ir, variable_count);
        }
    } else if (qualifier == '?') {
        processExitStatements(values.elements);
        IR::condition loop = { { {IR::condition_types::NUMBER, (long long) 0} }, values.elements };
        new_ir.push({ IR::types::DOWHILE, loop });
    } else {
        return;
    }
    values = new_ir;
}
IR::assign TreeAnyDataToIR(Parser::Rule value) {
    auto val = std::any_cast<Parser::Rule>(value.data);
    IR::assign newval;
    switch (val.name)
    {
    case Parser::Rules::string:
        newval.value = IR::var_assign_values::STRING;
        newval.data = std::any_cast<std::string>(val.data);
        break;
    case Parser::Rules::id:
        newval.value = IR::var_assign_values::ID;
        newval.data = std::any_cast<std::string>(val.data);
        break;
    case Parser::Rules::boolean: 
    {
        auto data = std::any_cast<obj_t>(val.data);
        auto val = std::any_cast<int>(corelib::map::get(data, "val"));
        newval.value = val ? IR::var_assign_values::_TRUE : IR::var_assign_values::_FALSE;
        break;
    }
    case Parser::Rules::number: 
    {
        auto data = std::any_cast<obj_t>(val.data);
        auto full = std::any_cast<std::string>(corelib::map::get(data, "full"));
        newval.value = IR::var_assign_values::NUMBER;
        newval.data = full;
    }
    case Parser::Rules::array:
    {
        auto data = std::any_cast<arr_t<Parser::Rule>>(val.data);
        IR::array arr;
        for (auto &el : data) {
            auto truedata = std::any_cast<Parser::Rule>(el.data);
            arr.push_back(TreeAnyDataToIR(truedata));
        }
        newval.value = IR::var_assign_values::ARRAY;
        newval.data = arr;
    }
    case Parser::Rules::object:
    {
        auto data = std::any_cast<obj_t>(val.data);
        auto key = std::any_cast<Parser::Rule>(corelib::map::get(data, "key"));
        auto value = std::any_cast<Parser::Rule>(corelib::map::get(data, "value"));
        auto keys = std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(data, "keys"));
        auto values = std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(data, "values"));
        
        keys.insert(keys.begin(), key);
        values.insert(values.begin(), value);
        IR::object obj;
        for (int i = 0; i < keys.size(); i++) {
            auto key = keys[i];
            auto value = values[i];
            auto strkey = std::any_cast<std::string>(key.data);
            auto value_data = TreeAnyDataToIR(value);
            obj[strkey] = value_data;
        }
        newval.value = IR::var_assign_values::OBJECT;
        newval.data = obj;
    }
    default:
        break;
    }
    return newval;
}
IR::function_call TreeFunctionToIR(Parser::Rule rule) {
    IR::function_call call;
    auto data = std::any_cast<obj_t>(rule.data);
    call.name = std::any_cast<std::string>(std::any_cast<Parser::Rule>(corelib::map::get(data, "name")));
    auto body = std::any_cast<Parser::Rule>(corelib::map::get(data, "body")); 
    auto params = std::any_cast<arr_t<Parser::Rule>>(std::any_cast<Parser::Rule>(body.data));
    arr_t<IR::assign> new_params;
    for (auto arg : params) {
        new_params.push_back(TreeAnyDataToIR(arg));
    }
    call.params = new_params;
    return call;
}

IR::method_call TreeMethodCallToIR(Parser::Rule rule) {
    IR::method_call method_call;
    auto var_rule_data = std::any_cast<obj_t>(rule.data);
    auto id = std::any_cast<Parser::Rule>(corelib::map::get(var_rule_data, "object"));
    auto call = std::any_cast<Parser::Rule>(corelib::map::get(var_rule_data, "call"));
    method_call.var_name = std::any_cast<std::string>(id.data);
    method_call.call = TreeFunctionToIR(call);
    return method_call;
}
IR::var_types deduceVarTypeByValue(Parser::Rule mem) {
    if (mem.name == Parser::Rules::Rule_rule) {
        auto memdata = std::any_cast<obj_t>(mem.data);
        mem = std::any_cast<Parser::Rule>(corelib::map::get(memdata, "val"));
    }
    if (mem.name == Parser::Rules::Rule_group) {
        auto data = std::any_cast<obj_t>(mem.data);
        auto group = std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(data, "val"));
        if (group.size() > 1) {
            return IR::var_types::STRING;
        } else {
            return deduceVarTypeByValue(group[0]);
        }
    } if (mem.name == Parser::Rules::Rule_op) {
        Parser::Rules rules = Parser::Rules::NONE;
        bool isToken = false;
        auto val = std::any_cast<arr_t<Parser::Rule>>(mem.data);
        for (auto el : val) {
            auto el_data = std::any_cast<obj_t>(el.data);
            auto el_val = std::any_cast<Parser::Rule>(corelib::map::get(el_data, "val"));
            if (rules == Parser::Rules::NONE) {
                rules = el_val.name;
                if (el_val.name == Parser::Rules::Rule_other) {
                    auto data = std::any_cast<obj_t>(el_val.data);
                    auto name = std::any_cast<Parser::Rule>(corelib::map::get(data, "name"));
                    auto name_str = std::any_cast<std::string>(name.data);
                    isToken = corelib::text::isUpper(name_str);
                }
            } else if (rules == el_val.name) {
                if (el_val.name == Parser::Rules::Rule_other) {
                    auto data = std::any_cast<obj_t>(el_val.data);
                    auto name = std::any_cast<Parser::Rule>(corelib::map::get(data, "name"));
                    auto name_str = std::any_cast<std::string>(name.data);
                    bool _isToken = corelib::text::isUpper(name_str);
                    if (isToken != _isToken) {
                        rules = Parser::Rules::NONE;
                        break;
                    }
                }
            } else {
                rules = Parser::Rules::NONE;
                break;
            }
        }
        switch(rules) {
            case Parser::Rules::NONE:
                return IR::var_types::ANY; // there are different values so use any type
            case Parser::Rules::Rule_other:
                if (isToken)
                    return IR::var_types::Token;
                else
                    return IR::var_types::Rule;
            default:
                return IR::var_types::STRING;
        }
    } else if (mem.name == Parser::Rules::Rule_other) {
        auto data = std::any_cast<obj_t>(mem.data);
        auto name = std::any_cast<Parser::Rule>(corelib::map::get(data, "name"));
        auto name_str = std::any_cast<std::string>(name.data);
        bool isToken = corelib::text::isUpper(name_str);
        if (isToken)
            return IR::var_types::Token;
        else 
            return IR::var_types::Rule;
    } else {
        return IR::var_types::STRING;
    }
}
IR::node_ret_t processGroup(Parser::Rule rule, IR::ir &member, int &variable_count, char qualifier_char, bool isToken) {
    //cpuf::printf("group\n");
    auto data = std::any_cast<obj_t>(rule.data);
    auto variable = corelib::map::get(data, "variable").has_value() ? std::any_cast<Parser::Rule>(corelib::map::get(data, "variable")) : Parser::Rule();
    auto val = std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(data, "val"));
    arr_t<IR::node_ret_t> node_ret;
    auto values = rulesToIr(val, "", isToken, node_ret, variable_count);
    cpuf::printf("Group Values got: \n");
    //IR::outputIRToConsole(values);
    cpuf::printf("End values\n");
    // create variable with name of "var" or with auto-generated one
    auto var = (!variable.empty() && variable.name == Parser::Rules::id) ?
                        createEmptyVariable(std::any_cast<std::string>(variable.data), values.size()) :
                        createEmptyVariable(generateVariableName(variable_count), values.size());
    auto svar = createSuccessVariable(variable_count);
    var.type = {deduceVarTypeByValue(rule)};
    arr_t<IR::member> var_members;
    switch (var.type.type) {
        case IR::var_types::STRING:
        {
            // it is a string so add all values
            for (auto node : node_ret) {
                var_members.push_back(
                    {
                        IR::types::ASSIGN_VARIABLE, 
                        IR::variable_assign {var.name, IR::var_assign_types::ADD, IR::assign { IR::var_assign_values::ID,  node.var }}
                    }
                );
            }
        }
        case IR::var_types::Token:
        case IR::var_types::Rule:
            // it is token so perform a single assign
            var_members.push_back(
                {
                    IR::types::ASSIGN_VARIABLE,
                    IR::variable_assign {var.name, IR::var_assign_types::ADD, IR::assign { IR::var_assign_values::ID,  node_ret[0].var }}
                }
            );
        break;
    }
    arr_t<IR::expr> svar_expr = {};
    //cpuf::printf("success_vars.size(): %d\n", success_vars.size());
    for (int i = 0; i < node_ret.size(); i++) {
        if (i != 0)
            svar_expr.push_back({IR::condition_types::AND});
        svar_expr.push_back({IR::condition_types::VARIABLE, node_ret[i].svar});
    }
    auto svar_cond = IR::member {
        IR::types::IF,
        IR::condition {
            svar_expr,
            {{IR::types::ASSIGN_VARIABLE, IR::variable_assign {svar.name, IR::var_assign_types::ASSIGN, IR::var_assign_values::_TRUE}}}
        }
    };
    affectIrByQualifier(values, qualifier_char, variable_count);
    member.push({IR::types::VARIABLE, var});
    member.push({IR::types::VARIABLE, svar});
    if (!variable.empty() && variable.name == Parser::Rules::method_call) {
        IR::method_call method_call = TreeMethodCallToIR(std::any_cast<Parser::Rule>(variable.data));
        member.add(values);
        member.push({IR::types::METHOD_CALL, method_call});
    } else {
        member.add(values);
    }
    member.push(svar_cond);
    return {svar.name, var.name};
}
IR::node_ret_t processRuleCsequence(const Parser::Rule &rule, IR::ir &member, int &variable_count, char qualifier_char) {
    //cpuf::printf("csequence\n");
    auto data = std::any_cast<obj_t>(rule.data);
    auto _not = std::any_cast<bool>(corelib::map::get(data, "not"));
    auto values = std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(data, "val"));

    auto var = createEmptyVariable(generateVariableName(variable_count));
    auto svar = createSuccessVariable(variable_count);
    var.type = {IR::var_types::STRING};
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
            expr.push_back({IR::condition_types::OR});

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
    return {svar.name, var.name};
}
IR::node_ret_t processString(const Parser::Rule &rule, IR::ir &member, int &variable_count, char qualifier_char) {
    //cpuf::printf("string, data: %s\n", std::any_cast<std::string>(rule.data));
    auto data = std::any_cast<std::string>(rule.data);
    auto var = createEmptyVariable(generateVariableName(variable_count));
    auto svar = createSuccessVariable(variable_count);
    var.type = {IR::var_types::STRING};
    arr_t<IR::expr> expr = {
        {IR::condition_types::STRNCMP, data}
    };
    arr_t<IR::member> block = createDefaultBlock(var, svar);
    member.push({IR::types::VARIABLE, var});
    member.push({IR::types::VARIABLE, svar});
    pushBasedOnQualifier(expr, block, svar, member, qualifier_char, variable_count);
    return {svar.name, var.name};
}
IR::node_ret_t process_Rule_hex(const Parser::Rule &rule, IR::ir &member, int &variable_count, char qualifier_char) {
    //cpuf::printf("hex\n");
    auto data = std::any_cast<std::string>(rule.data);
    arr_t<IR::expr> expr = {};
    auto var = createEmptyVariable(generateVariableName(variable_count));
    auto svar = createSuccessVariable(variable_count);
    var.type = {IR::var_types::STRING};
    arr_t<IR::member> block = createDefaultBlock(var, svar);
    bool is_first = true, is_negative = false;
    if (qualifier_char == '\0') {
        expr.push_back({IR::condition_types::NOT});
        expr.push_back({IR::condition_types::GROUP_OPEN});
        is_negative = true;
    }
    if (data.size() % 2 != 0)
        data.insert(data.begin(), '0');
    cpuf::printf("hex_str: %$\n", data);
    for (int i = 0; i < data.size(); i += 2) {
        std::string hex(data.data() + i, 2);
        if (!is_first)
            expr.push_back({IR::condition_types::AND});
        is_first = false;
        expr.push_back({IR::condition_types::CURRENT_CHARACTER});
        expr.push_back({IR::condition_types::EQUAL});
        expr.push_back({IR::condition_types::HEX, hex});
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
        int identLevel = 0;
        IR::convertMember(member.elements[i], std::cout, identLevel);
    }
    //cpuf::printf("hex_close\n");
    return {svar.name, var.name};
}
IR::node_ret_t process_Rule_bin(const Parser::Rule &rule, IR::ir &member, int &variable_count, char qualifier_char) {
    //cpuf::printf("hex\n");
    auto data = std::any_cast<std::string>(rule.data);
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
    while (data.size() % 8 != 0)
        data.insert(data.begin(), '0');
    for (int i = 0; i < data.size(); i += 8) {
        std::string bin(data.data() + i, 8);
        auto as_hex = hex::from_binary(bin);
        as_hex.erase(as_hex.begin(), as_hex.begin() + 2);
        if (!is_first)
            expr.push_back({IR::condition_types::AND});
        is_first = false;
        expr.push_back({IR::condition_types::CURRENT_CHARACTER});
        expr.push_back({IR::condition_types::EQUAL});
        expr.push_back({IR::condition_types::HEX, as_hex});
    }
    if (is_negative) {
        expr.push_back({IR::condition_types::GROUP_CLOSE});
    }
    member.push({IR::types::VARIABLE, var});
    member.push({IR::types::VARIABLE, svar});
    pushBasedOnQualifier(expr, block, svar, member, qualifier_char, variable_count);
    return {svar.name, var.name};
}
IR::node_ret_t processAccessor(const Parser::Rule &rule, IR::ir &member, int &variable_count, char qualifier_char) {
    //cpuf::printf("accessor\n");
    auto data = std::any_cast<obj_t>(rule.data);
    auto first = std::any_cast<Parser::Rule>(corelib::map::get(data, "first"));
    auto second = std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(data, "second"));
    auto svar = createSuccessVariable(variable_count);
    auto var = createEmptyVariable(generateVariableName(variable_count));
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
    return {svar.name, var.name};
}
IR::node_ret_t process_Rule_other(const Parser::Rule &rule, IR::ir &member, int &variable_count, char qualifier_char, bool isToken) {
    //cpuf::printf("Rule_other");
    auto data = std::any_cast<obj_t>(rule.data);
    auto name = std::any_cast<Parser::Rule>(corelib::map::get(data, "name"));
    auto name_str = std::any_cast<std::string>(name.data);
    //cpuf::printf(", name: %s\n", name_str);

    auto var = createEmptyVariable(generateVariableName(variable_count));
    auto svar = createSuccessVariable(variable_count);
    
    bool isCallingToken = corelib::text::isUpper(name_str);
    var.type = isCallingToken ? IR::var_type {IR::var_types::Token} : IR::var_type {IR::var_types::Rule};
    auto block = createDefaultBlock(var, svar);
    member.push({IR::types::VARIABLE, var});
    member.push({IR::types::VARIABLE, svar});
    if (isToken) {
        // replace variable assignment from pos sequence to current token
        if (!isCallingToken) return {svar.name, var.name};
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
                    (qualifier_char == '*' || qualifier_char == '+') ? IR::var_assign_types::ADD : IR::var_assign_types::ASSIGN,
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
    return {svar.name, var.name};
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
    var.type = {IR::var_types::STRING};
    arr_t<IR::expr> expression;
    arr_t<IR::member> block = {{IR::types::EXIT}};
    arr_t<IR::member> block_after = createDefaultBlock(var, svar);
    if (qualifier_char != '\0')
        UWarning("Qualifier after \\%s ignored", c).print();
    switch (c[0]) {
        case 's':
            // means do not add skip of spaces
            add_space = false;
            cpuf::printf("member prev element: %s\n", IR::typesToString(member.elements.back().type));
            if (member.elements.back().type == IR::types::SKIP_SPACES)
                member.pop();

            if (num_main == 0) {
                //cpuf::printf("on_exit\n");
                return {svar.name, var.name};
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
        int identLevel = 0;
        IR::convertMember(member.elements[i], std::cout, identLevel);
    }
    //cpuf::printf("escaped_close\n");
    return {svar.name, var.name};
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
    member.push({IR::types::VARIABLE, svar});
    member.push({IR::types::IF, IR::condition{expression, block}});
    member.add(block_after);
    return {svar.name, var.name};
}
// arr_t<IR::member> construct_block(const arr_t<arr_t<IR::member>> &blocks, const arr_t<arr_t<IR::expr>> &conditions, size_t i = 0) {
//     if (i >= blocks.size()) {
//         return {{IR::types::EXIT}};
//     }

//     arr_t<IR::member> block = blocks[i];

//     block.push_back({
//         IR::types::IF,
//         IR::condition {
//             conditions[i],
//             construct_block(blocks, conditions, i + 1) // Instead of recursive call, directly reference the next block
//         }
//     });


//     return block;
// }

arr_t<IR::member> convert_op_rule(arr_t<Parser::Rule> &rules, int &variable_count, IR::variable var, char qualifier_char, bool isToken) {
    if (rules.empty()) {
        return {{IR::types::EXIT}};
    }

    IR::node_ret_t success_var;
    arr_t<arr_t<IR::member>> blocks;
    arr_t<arr_t<IR::expr>> conditions;
    auto rule = rules[0];
    rules.erase(rules.begin());
    IR::ir new_ir;
    auto rule_data = std::any_cast<obj_t>(rule.data);
    auto rule_val = std::any_cast<Parser::Rule>(corelib::map::get(rule_data, "val"));
    auto qualifier = std::any_cast<Parser::Rule>(corelib::map::get(rule_data, "qualifier"));
    char qualifier_c;
    if (qualifier.data.has_value()) {
        qualifier_c = std::any_cast<char>(qualifier.data);
    } else {
        qualifier_c = '\0';
    }
    char new_qualifier;
    if (qualifier_c == '+')
        new_qualifier = '*';
    else if (qualifier_c == '\0')
        new_qualifier = '?';
    
    if (rule_val.name == Parser::Rules::Rule_group)
        ruleToIr(rule, new_ir, variable_count, isToken, success_var, new_qualifier);
    else    
        ruleToIr(rule, new_ir, variable_count, isToken, success_var);
    
    
    std::vector<int> erase_indices;
    std::vector<int> push_indices;
    cpuf::printf("Rule_Val.name: %s\n", Parser::RulesToString(rule_val.name));
    if (rule_val.name == Parser::Rules::Rule_group) {
        auto cond = IR::condition {
            arr_t<IR::expr> {
                {IR::condition_types::NOT}, {IR::condition_types::VARIABLE, success_var.svar}
            },
            convert_op_rule(rules, variable_count, var, qualifier_char, isToken),
            {{
                IR::types::ASSIGN_VARIABLE,
                IR::variable_assign 
                {
                    var.name,
                    IR::var_assign_types::ASSIGN,
                    IR::assign {
                        IR::var_assign_values::ID,
                        success_var.var
                    }
                }
            }}
        };
        new_ir.push({IR::types::IF, cond});
    } else {
        for (int i = 0; i < new_ir.elements.size(); i++) {
            auto &el = new_ir.elements[i];
            if (el.type == IR::types::IF) {
                auto val = std::any_cast<IR::condition>(el.value);
                if (!val.block.empty() && val.block[0].type == IR::types::EXIT) {
                    val.block = convert_op_rule(rules, variable_count, var, qualifier_char, isToken);
                    for (int j = i + 1; j < new_ir.elements.size(); j++) {
                        if (new_ir.elements[j].type == IR::types::INCREASE_POS_COUNTER || new_ir.elements[j].type == IR::types::SKIP_SPACES)
                            continue;
                        val.else_block.push_back(new_ir.elements[j]);
                        erase_indices.push_back(j);
                    }
                    val.else_block.push_back({
                        IR::types::ASSIGN_VARIABLE,
                        IR::variable_assign 
                        {
                            var.name,
                            IR::var_assign_types::ASSIGN,
                            IR::assign {
                                IR::var_assign_values::ID,
                                success_var.var
                            }
                        }
                    });
                    el.value = val;  // Ensure value is update
                }
            } else if (el.type == IR::types::INCREASE_POS_COUNTER || el.type == IR::types::SKIP_SPACES) {
                erase_indices.push_back(i);
            }
        }
    }

    // Erase marked indices in reverse to prevent shifting issues
    for (int i = erase_indices.size() - 1; i >= 0; i--) {
        new_ir.elements.erase(new_ir.elements.begin() + erase_indices[i]);
    }

    return new_ir.elements;
}

IR::node_ret_t process_Rule_op(const Parser::Rule &rule, IR::ir &member, int &variable_count, char qualifier_char, bool isToken) {
    cpuf::printf("Rule_op\n");
    auto op = std::any_cast<arr_t<Parser::Rule>>(rule.data);
    auto var = createEmptyVariable(generateVariableName(variable_count));
    auto svar = createSuccessVariable(variable_count);
    auto block = createDefaultBlock(var, svar);
    auto size = member.size();
    // Add success variable
    var.type = {deduceVarTypeByValue(rule)};
    member.push({IR::types::VARIABLE, var});
    member.push({IR::types::VARIABLE, svar});

    // Convert rules into IR
    cpuf::printf("rules.size(): %d\n", op.size());
    for (auto rule : op) {
        auto rule_data = std::any_cast<obj_t>(rule.data);
        auto rule_val = std::any_cast<Parser::Rule>(corelib::map::get(rule_data, "val"));
        auto qualifier = std::any_cast<Parser::Rule>(corelib::map::get(rule_data, "qualifier"));
        cpuf::printf("rule.name: %s\n", Parser::RulesToString(rule_val.name));
        if (rule_val.name == Parser::Rules::Rule_other) {
            auto data = std::any_cast<obj_t>(rule_val.data);
            auto id = std::any_cast<Parser::Rule>(corelib::map::get(data, "name"));
            auto id_str = std::any_cast<std::string>(id.data);
            cpuf::printf("\tname: %s\n", id_str);
        }
    }
    member.add(convert_op_rule(op, variable_count, var, qualifier_char, isToken));

    // Append default block
    member.add(block);

    return {svar.name, var.name};
}
IR::var_type cllTreeCsupportTypeToIR(Parser::Rule rule) {
    auto data = std::any_cast<obj_t>(rule.data);
    bool is_unsigned = std::any_cast<bool>(corelib::map::get(data, "is_unsigned"));
    auto val = std::any_cast<std::string>(corelib::map::get(data, "val"));
    auto templ = std::any_cast<Parser::Rule>(corelib::map::get(data, "template"));
    IR::var_types result;
    if (val == "char")
        result = IR::var_types::CHAR;
    else if (val == "short")
        result = IR::var_types::SHORT;
    else if (val == "int")
        result = IR::var_types::INT;
    else if (val == "long")
        result = IR::var_types::LONG;
    else if (val == "long long")
        result = IR::var_types::LONGLONG;
    
    if (is_unsigned)
        result = static_cast<IR::var_types>(static_cast<int>(result) + 1); // result++
    return { result, {} };
    throw Error("Undefined csupport type");
}
IR::var_type cllTreeAbstactTypeToIR(Parser::Rule rule);
IR::var_type cllTreeTypeToIR(Parser::Rule rule) {
    auto data = std::any_cast<Parser::Rule>(rule.data);
    if (data.name == Parser::Rules::cll_csupport_types)
        return cllTreeCsupportTypeToIR(data);
    else
        return cllTreeAbstactTypeToIR(data);
}
IR::var_type cllTreeAbstactTypeToIR(Parser::Rule rule) {
    auto data = std::any_cast<obj_t>(rule.data);
    auto val = std::any_cast<std::string>(corelib::map::get(data, "val"));
    auto templ = std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(data, "template"));
    if (val == "str")
        return {IR::var_types::STRING, {}};
    else if (val == "bool")
        return {IR::var_types::BOOLEAN, {}};
    else if (val == "num")
        return {IR::var_types::NUMBER, {}};
    else if (val == "arr") {
        IR::var_types type = IR::var_types::ARRAY;
        IR::var_type _template = cllTreeTypeToIR(templ[0]);
        return {type, {_template}};
    } else if (val == "obj") {
        IR::var_types type = IR::var_types::OBJECT;
        IR::var_type _template1 = cllTreeTypeToIR(templ[0]);
        IR::var_type _template2 = cllTreeTypeToIR(templ[1]);
        return {type, {_template1, _template2}};
    }
    throw Error("undefined abstract type");
}
IR::var_assign_types TreeOpToIR(Parser::Rule rule) {
    auto data = std::any_cast<std::string>(rule.data);
    if (data == ">>")
        return IR::var_assign_types::BITWISE_RIGHTSHFT;
    if (data == "<<")
        return IR::var_assign_types::BITWISE_LEFTSHIFT;
    // all other is single character so can use switch
    switch (data[0]) {
        case '+':
            return IR::var_assign_types::ADD;
        case '-':
            return IR::var_assign_types::SUBSTR;
        case '*':
            return IR::var_assign_types::MULTIPLY;
        case '/':
            return IR::var_assign_types::DIVIDE;
        case '%':
            return IR::var_assign_types::MODULO;
        case '&':
            return IR::var_assign_types::BITWISE_AND;
        case '|':
            return IR::var_assign_types::BITWISE_OR;
        case '^':
            return IR::var_assign_types::BITWISE_ANDR;
        default:
            throw Error("Undefined operator");
    }
}
IR::var_assign_types TreeAssignmentOpToIR(Parser::Rule rule) {
    auto val = std::any_cast<Parser::Rule>(rule.data);
    auto v = TreeOpToIR(val);
    v = static_cast<IR::var_assign_types>(static_cast<int>(v) + static_cast<int>(IR::var_assign_types::ASSIGN));
    return v;
}
IR::var_assign_types TreeOperatorsToIR(Parser::Rule rule) {
    if (rule.name == Parser::Rules::op)
        return TreeOpToIR(rule);
    else if (rule.name == Parser::Rules::assignment_op)
        return TreeAssignmentOpToIR(rule);
    else
        throw Error("Undefined operator");
}
IR::node_ret_t process_cll_var(const Parser::Rule &rule, IR::ir &member, int &variable_count, char qualifier_char, bool isToken) {
    // get data section
    auto data = std::any_cast<obj_t>(rule.data);
    auto type = std::any_cast<Parser::Rule>(corelib::map::get(data, "type"));
    auto name = std::any_cast<Parser::Rule>(corelib::map::get(data, "id"));
    auto op = std::any_cast<Parser::Rule>(corelib::map::get(data, "operator"));
    auto value = std::any_cast<Parser::Rule>(corelib::map::get(data, "value"));

    IR::var_type ir_type;
    IR::var_assign_types assign_types;
    IR::var_assign_values assign_values;
    IR::assign assign;
    if (type.data.has_value()) {
        ir_type = cllTreeTypeToIR(type);
    }
    // if (op.data.has_value()) {
    //     assign_types = TreeOpToIR(op);
    //     if (value.name == Parser::Rules::expr)
    //         assign = TreeExprToIR();
    //     else
    //         assign = TreeTernaryToIR();
    // }
}
IR::node_ret_t process_cll(const Parser::Rule &rule, IR::ir &member, int &variable_count, char qualifier_char, bool isToken) {
    auto rule_val = std::any_cast<Parser::Rule>(rule.data);
    switch (rule_val.name)
    {
    case Parser::Rules::cll_var:
        process_cll_var(rule_val, member, variable_count, qualifier_char, isToken);
        break;
    
    default:
        break;
    }
}

void ruleToIr(Parser::Rule &rule_rule, IR::ir &member, int &variable_count, bool isToken, IR::node_ret_t &success_var, char custom_qualifier) {
    //member.push({ IR::types::RULE, });
    auto rule_data = std::any_cast<obj_t>(rule_rule.data);
    auto rule = std::any_cast<Parser::Rule>(corelib::map::get(rule_data, "val"));
    auto qualifier = std::any_cast<Parser::Rule>(corelib::map::get(rule_data, "qualifier"));
    char qualifier_char = '\0';
    if (custom_qualifier != -1) {
        qualifier_char = custom_qualifier;
    } else if (qualifier.data.has_value()) {
        qualifier_char = std::any_cast<char>(qualifier.data);
    }
    if (!isToken && (rule.name != Parser::Rules::Rule_other && rule.name != Parser::Rules::Rule_group && rule.name != Parser::Rules::Rule_op && rule.name != Parser::Rules::cll && rule.name != Parser::Rules::linear_comment && rule.name != Parser::Rules::accessor)  ) {
        //throw Error("Rule having literals. Name: %s", Parser::RulesToString(rule.name));
        //return;
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
            throw Error("Converting undefined rule: %s,%s", Parser::RulesToString(rule_rule.name), Parser::RulesToString(rule.name));
    }
    if (add_space_skip)
        member.push({IR::types::SKIP_SPACES, isToken});
}
IR::ir rulesToIr(arr_t<Parser::Rule> rules, std::string rule_name, bool isToken, arr_t<IR::node_ret_t> &success_vars, int &variable_count, bool new_rule) {
    IR::ir result;
    arr_t<IR::element_count> elements;
    if (new_rule)
        result.push({IR::types::RULE, rule_name});

    for (auto &rule : rules) {
        IR::node_ret_t success_var;
        ruleToIr(rule, result, variable_count, isToken, success_var);
        success_vars.push_back(success_var);
    }

    if (new_rule)
        result.push({IR::types::RULE_END});

    return result;
}
IR::ir rulesToIr(arr_t<Parser::Rule> rules, std::string rule_name, bool isToken, arr_t<IR::node_ret_t> &success_vars, bool new_rule) {
    IR::ir result;
    arr_t<IR::element_count> elements;
    int variable_count = 0;
    if (new_rule)
        result.push({IR::types::RULE, rule_name});

    for (auto &rule : rules) {
        IR::node_ret_t success_var;
        ruleToIr(rule, result, variable_count, isToken, success_var);
        success_vars.push_back(success_var);
    }

    if (new_rule)
        result.push({IR::types::RULE_END});

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
IR::ir rulesToIr(arr_t<Parser::Rule> rules, std::string rule_name, bool isToken, bool new_rule) {
    IR::ir result;
    arr_t<IR::element_count> elements;
    int variable_count = 0;
    if (new_rule) {
        if (isToken)
            result.push({IR::types::TOKEN, rule_name});  
        else
            result.push({IR::types::RULE, rule_name});  
    }

    for (auto &rule : rules) {
        IR::node_ret_t success_var;
        ruleToIr(rule, result, variable_count, isToken, success_var);
    }
    if (new_rule)
        result.push({IR::types::RULE_END});
    return result;
}
IR::ir treeToIr(Parser::Tree &tree, std::string nested_name) {
    IR::ir result_ir;
    for (auto &el : tree) {
        if (el.name != Parser::Rules::Rule)
            continue;

        auto data = std::any_cast<obj_t>(el.data);
        auto name = std::any_cast<std::string>(std::any_cast<Parser::Rule>(corelib::map::get(data, "name")).data);
        auto rules = std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(data, "rule"));
        auto nested_rules = std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(data, "nestedRules"));
        auto fullname = nested_name.empty() ? name : nested_name + "_" + name;
        result_ir.add(treeToIr(nested_rules, fullname));
        result_ir.add(rulesToIr(rules, fullname, corelib::text::isUpper(name), true));

    }
    return result_ir;
}