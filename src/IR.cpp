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
void IR::ir::push_begin(IR::member member) {
    elements.insert(elements.begin(), member);
}
void IR::ir::pop_begin() {
    elements.erase(elements.begin());
};
size_t IR::ir::size() {
    return elements.size();
}
bool IR::ir::empty() {
    return elements.empty();
}
IR::variable createEmptyVariable(std::string name) {
    IR::variable var {
        name,
        {IR::var_types::UNDEFINED},
        IR::var_assign_values::NONE,
    };
    return var;
}
std::string generateVariableName(int &variable_count) {
    return std::string("_") + std::to_string(variable_count++);
}
void processExitStatements(arr_t<IR::member> &values) {
    for (auto &el : values) {
        if (el.type == IR::types::IF || el.type == IR::types::WHILE || el.type == IR::types::DOWHILE) {
            auto &condition = std::any_cast<IR::condition&>(el.value); // Avoid unnecessary copies
            
            // Prevent potential infinite recursion by checking if we already processed this condition
            static std::unordered_set<IR::condition*> visited;
            if (visited.find(&condition) != visited.end()) {
                continue; // Skip already processed conditions to avoid infinite loops
            }
            visited.insert(&condition);

            // Process the block and else block of the condition recursively
            processExitStatements(condition.block);
            processExitStatements(condition.else_block);

            // Ensure that any EXIT statements within the blocks are replaced with BREAK_LOOP
            for (auto &unit : condition.block) {
                if (unit.type == IR::types::EXIT) {
                    unit.type = IR::types::BREAK_LOOP; // Replacing EXIT with BREAK_LOOP
                } else if (unit.type == IR::types::IF || unit.type == IR::types::WHILE || unit.type == IR::types::DOWHILE) {
                    auto &cond = std::any_cast<IR::condition&>(unit.value);
                    
                    // Check if we've processed this before
                    if (visited.find(&cond) != visited.end()) {
                        continue;
                    }
                    visited.insert(&cond);

                    processExitStatements(cond.block); // Recursive call on nested blocks
                    processExitStatements(cond.else_block); // Recursive call on else blocks
                }
            }
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
            { IR::condition_types::VARIABLE, var },
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
void replaceToPrevChar(arr_t<IR::member> &elements, int i) {
    for (; i < elements.size(); i++) {
        auto &el = elements[i];
        if (el.type == IR::types::IF || el.type == IR::types::WHILE || el.type == IR::types::DOWHILE) {
            // replace CURRENT_CHARACTER to PREV_CHARACTER
            auto val = std::any_cast<IR::condition>(el.value);
            for (auto &expr : val.expression) {
                if (expr.id == IR::condition_types::STRNCMP) {
                    expr.id = IR::condition_types::STRNCMP_PREV;
                }

            }
            replaceToPrevChar(val.block, 0);
            if (el.type == IR::types::IF)
                replaceToPrevChar(val.else_block, 0);
            elements[i].value = val;
        }
    }

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
void replace_exit_to_unsuccess(arr_t<IR::member> &elements, IR::variable svar) {
    for (auto &el : elements) {
        if (el.type == IR::types::IF) {
            auto block = std::any_cast<IR::condition>(el.value).block;
            replace_exit_to_unsuccess(block, svar);
            el.value = block;
        } else if (el.type == IR::types::EXIT) {
            el = {IR::types::ASSIGN_VARIABLE, IR::variable_assign {svar.name, IR::var_assign_types::ASSIGN, {IR::var_assign_values::_FALSE}}};
        }
    }
}
char getEscapedChar(char in) {
    switch (in)
    {
    case 'n': return '\n';   // Newline
    case 'r': return '\r';   // Carriage return
    case 't': return '\t';   // Horizontal tab
    case 'a': return '\a';   // Bell (alert)
    case 'b': return '\b';   // Backspace
    case 'f': return '\f';   // Form feed (new page)
    case 'v': return '\v';   // Vertical tab
    case '\\': return '\\';  // Backslash
    case '\'': return '\'';  // Single quote
    case '"': return '"';    // Double quote
    default: return in;      // Return the character itself if not an escape sequence
    }
}

IR::member createDefaultCall(arr_t<IR::member> &block, const IR::variable var, const std::string &name, IR::ir &member, arr_t<IR::expr> &expr) {
    auto function_call = IR::function_call {
        name,
        {{IR::var_assign_values::TOKEN_SEQUENCE}},
        
    };
    auto var_assign = IR::variable_assign {
        var.name, 
        IR::var_assign_types::ASSIGN,
        { IR::var_assign_values::FUNCTION_CALL, function_call }
    };
    expr = {
        {IR::condition_types::SUCCESS_CHECK, var.name}
    };
    return {IR::types::ASSIGN_VARIABLE, var_assign};
}
IR::variable add_shadow_variable(IR::ir &member, arr_t<IR::member> &block, IR::variable &var, int &variable_count) {
    IR::variable shadow_var = createEmptyVariable("shadow" + generateVariableName(variable_count));
    auto type = var.type;
    if (type.type == IR::var_types::Rule_result)
        type.type = IR::var_types::Rule;
    else if (type.type == IR::var_types::Token_result)
        type.type = IR::var_types::Token;
    shadow_var.type = {IR::var_types::ARRAY, {type}};
    member.push({IR::types::VARIABLE, shadow_var});
    block.push_back({IR::types::METHOD_CALL, IR::method_call { shadow_var.name, {IR::function_call {"push", {IR::assign {IR::var_assign_values::VARIABLE, var}}}}}});
    return shadow_var;
}
IR::variable pushBasedOnQualifier(arr_t<IR::expr> expr, arr_t<IR::member> block, IR::variable var, IR::variable svar, IR::ir &member, char qualifier_char, int &variable_count, bool insideLoop, bool add_shadow_var = true) {
    //block.push_back({IR::types::ASSIGN_VARIABLE, IR::variable_assign {svar.name, IR::var_assign_types::ASSIGN, IR::var_assign_values::_TRUE}});
    IR::variable shadow_variable;
    if (insideLoop && add_shadow_var) {
       shadow_variable = add_shadow_variable(member, block, var, variable_count);
       add_shadow_var = false;
    }
    switch (qualifier_char) {
        case '+':
            if (add_shadow_var)
                shadow_variable = add_shadow_variable(member, block, var, variable_count);
            handle_plus_qualifier({expr, block}, member, variable_count);
            break;
        case '*': {
            IR::member pop = block.back();
 
            //block.pop_back();
            if (add_shadow_var)
                shadow_variable = add_shadow_variable(member, block, var, variable_count);
            member.push({IR::types::WHILE, IR::condition{expr, block}});
            //member.push(pop);
            break;
        }
        case '?':
            member.push({IR::types::IF, IR::condition{expr, block}});
            break;
        default:
            // add the negative into condition
            expr.insert(expr.begin(), {IR::condition_types::NOT});
            expr.insert(expr.begin() + 1, {IR::condition_types::GROUP_OPEN});
            expr.push_back({IR::condition_types::GROUP_CLOSE});
            // add exit statement
            member.push({IR::types::IF, IR::condition{expr, {{IR::types::EXIT}}}});
            member.add(block);
            break;
    }
    return shadow_variable;
}
// function to push based on qualifier for Rule_other
IR::variable pushBasedOnQualifier_Rule_other(arr_t<IR::expr> expr, arr_t<IR::member> block, IR::variable var, IR::variable svar, IR::member call, IR::ir &member, char qualifier_char, int &variable_count, bool &insideLoop, bool add_shadow_var = false) {
    //block.push_back({IR::types::ASSIGN_VARIABLE, IR::variable_assign {svar.name, IR::var_assign_types::ASSIGN, IR::var_assign_values::_TRUE}});
    IR::variable shadow_variable;
    if (insideLoop) {
        shadow_variable = add_shadow_variable(member, block, var, variable_count);
        add_shadow_var = false;
    }
    switch (qualifier_char) {
        case '+':
            if (add_shadow_var)
                shadow_variable = add_shadow_variable(member, block, var, variable_count);
            block.push_back(call);
            handle_plus_qualifier({expr, block}, member, variable_count);
            break;
        case '*': {
            if (add_shadow_var)
                shadow_variable = add_shadow_variable(member, block, var, variable_count);
            block.push_back(call);
            member.push({IR::types::WHILE, IR::condition{expr, block}});
            break;
        }
        case '?':
            member.push({IR::types::IF, IR::condition{expr, block}});
            break;
        default:
            // add the negative into condition
            expr.insert(expr.begin(), {IR::condition_types::NOT});
            expr.insert(expr.begin() + 1, {IR::condition_types::GROUP_OPEN});
            expr.push_back({IR::condition_types::GROUP_CLOSE});
            // add exit statement
            member.push({IR::types::IF, IR::condition{expr, {{IR::types::EXIT}}}});
            member.add(block);
            break;
    }
    return shadow_variable;
}
IR::variable affectIrByQuantifier(IR::ir &member, IR::ir &values, char qualifier, IR::variable var, int &variable_count, bool insideLoop) {
    IR::ir new_ir;
    IR::variable shadow_var;
    if (qualifier == '*' || qualifier == '+') {
        IR::condition loop = { { { IR::condition_types::NUMBER, (long long) 1 } }, {} };
        processExitStatements(values.elements);
        loop.block = values.elements;
        if (var.type.type != IR::var_types::UNDEFINED && var.type.type != IR::var_types::STRING)
            shadow_var = add_shadow_variable(member, loop.block, var, variable_count);
        new_ir.push({IR::types::WHILE, loop});
        if (qualifier == '+') {
            new_ir.elements.clear();
            handle_plus_qualifier(loop, new_ir, variable_count);
        }
    } else if (qualifier == '?') {
        processExitStatements(values.elements);
        IR::condition loop = { { {IR::condition_types::NUMBER, (long long) 0} }, values.elements };
        if (insideLoop) {
            shadow_var = add_shadow_variable(member, loop.block, var, variable_count);
        }
        new_ir.push({ IR::types::DOWHILE, loop });
    } else {
        return shadow_var;
    }
    values = new_ir;
    return shadow_var;
}
IR::assign TreeAnyDataToIR(Parser::Rule value) {
    auto val = std::any_cast<Parser::Rule>(value.data);
    IR::assign newval;
    switch (val.name)
    {
    case Parser::Rules::string:
        //cpuf::printf("string, type: %s\n", val.data.type().name());
        newval.kind = IR::var_assign_values::STRING;
        newval.data = std::any_cast<std::string>(val.data);
        break;
    case Parser::Rules::var_refer:
    {        
        //cpuf::printf("var_refer\n");
        IR::var_refer refer;
        //cpuf::printf("1\n");
        auto data = std::any_cast<obj_t>(val.data);
        //cpuf::printf("2\n");
        auto name = std::any_cast<Parser::Rule>(corelib::map::get(data, "name"));
        //cpuf::printf("3\n");
        auto name_str = std::any_cast<std::string>(name.data);
        //cpuf::printf("4\n");
        auto pre = std::any_cast<bool>(corelib::map::get(data, "pre"));
        //cpuf::printf("5\n");
        auto post = std::any_cast<bool>(corelib::map::get(data, "post"));
        refer.pre_increament = pre;
        refer.post_increament = post;
        refer.name = name_str;
        // skip brace expression for now as it is not used in rules for parser
        newval.kind = IR::var_assign_values::VAR_REFER;
        newval.data = refer;
        break;
    }

    case Parser::Rules::boolean: 
    {
        //cpuf::printf("boolean\n");
        auto data = std::any_cast<obj_t>(val.data);
        auto val = std::any_cast<int>(corelib::map::get(data, "val"));
        newval.kind = val ? IR::var_assign_values::_TRUE : IR::var_assign_values::_FALSE;
        break;
    }
    case Parser::Rules::number: 
    {
        //cpuf::printf("number\n");
        auto data = std::any_cast<obj_t>(val.data);
        auto full = std::any_cast<std::string>(corelib::map::get(data, "full"));
        newval.kind = IR::var_assign_values::NUMBER;
        newval.data = full;
        break;
    }
    case Parser::Rules::array:
    {
        //cpuf::printf("array\n");
        auto data = std::any_cast<arr_t<Parser::Rule>>(val.data);
        IR::array arr;
        for (auto &el : data) {
            arr.push_back(TreeAnyDataToIR(el));
        }
        newval.kind = IR::var_assign_values::ARRAY;
        newval.data = arr;
        break;
    }
    case Parser::Rules::object:
    {
        //cpuf::printf("object\n");
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
        newval.kind = IR::var_assign_values::OBJECT;
        newval.data = obj;
        break;
    }
    case Parser::Rules::accessor:
    {
        //cpuf::printf("accessor\n");
        auto data = std::any_cast<obj_t>(val.data);
        auto first = std::any_cast<Parser::Rule>(corelib::map::get(data, "first"));
        auto second = std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(data, "second"));
        second.insert(second.begin(), first);
        for (auto &el : second) {
            el = std::any_cast<Parser::Rule>(el.data);
        }
        IR::accessor mem = {second};
        newval.kind = IR::var_assign_values::ACCESSOR;
        newval.data = mem;
        break;
    }
    default:
        throw Error("Undefined rule");
        break;
    }
    return newval;
}
IR::function_call TreeFunctionToIR(Parser::Rule rule) {
    IR::function_call call;
    auto data = std::any_cast<obj_t>(rule.data);
    call.name = std::any_cast<std::string>(std::any_cast<Parser::Rule>(std::any_cast<Parser::Rule>(corelib::map::get(data, "name"))).data);
    auto body = std::any_cast<Parser::Rule>(corelib::map::get(data, "body")); 
    auto params = std::any_cast<arr_t<Parser::Rule>>(std::any_cast<Parser::Rule>(body.data).data);
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
    auto call = std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(var_rule_data, "call"));
    method_call.var_name = std::any_cast<std::string>(id.data);
    std::vector<IR::function_call> calls;
    for (auto cl : call) {
        calls.push_back(TreeFunctionToIR(cl));
    }
    method_call.calls = calls;
    return method_call;
}
IR::var_type deduceVarTypeByValue(Parser::Rule mem, char qualifier_char = '\0') {
    IR::var_type type;
    if (mem.name == Parser::Rules::Rule_rule) {
        auto memdata = std::any_cast<obj_t>(mem.data);
        mem = std::any_cast<Parser::Rule>(corelib::map::get(memdata, "val"));
    }
    if (mem.name == Parser::Rules::Rule_group) {
        auto data = std::any_cast<obj_t>(mem.data);
        auto group = std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(data, "val"));
        if (group.size() == 0) {
            return {IR::var_types::UNDEFINED};
        } else {
            if (group.size() > 1) {
                for (auto i = 0; i < group.size(); i++) {
                    if (deduceVarTypeByValue(group[i]).type != IR::var_types::STRING)
                        return {IR::var_types::UNDEFINED};
                }
                return {IR::var_types::STRING};
            }

            return deduceVarTypeByValue(group[0], qualifier_char);
        }
    } else if (mem.name == Parser::Rules::Rule_op) {
        IR::var_type type = {IR::var_types::UNDEFINED};
        auto val = std::any_cast<arr_t<Parser::Rule>>(mem.data);
        if (val.size() == 0)
            return {IR::var_types::UNDEFINED};
        for (auto el : val) {
            auto el_data = std::any_cast<obj_t>(el.data);
            auto el_val = std::any_cast<Parser::Rule>(corelib::map::get(el_data, "val"));
            if (type.type == IR::var_types::UNDEFINED) {
                type = deduceVarTypeByValue(el_val);
            } else if (deduceVarTypeByValue(el_val).type != type.type) {
                return {IR::var_types::ANY};
            }
        }
        return type;
    } else if (mem.name == Parser::Rules::Rule_other) {
        auto data = std::any_cast<obj_t>(mem.data);
        auto name = std::any_cast<Parser::Rule>(corelib::map::get(data, "name"));
        auto name_str = std::any_cast<std::string>(name.data);
        return corelib::text::isUpper(name_str) ? IR::var_type {IR::var_types::Token} : IR::var_type {IR::var_types::Rule};
    }
    return {IR::var_types::STRING};
}
IR::var_type cllTreeCsupportTypeToIR(Parser::Rule rule) {
    auto data = std::any_cast<obj_t>(rule.data);
    bool is_unsigned = std::any_cast<bool>(corelib::map::get(data, "is_unsigned"));
    auto val = std::any_cast<std::string>(corelib::map::get(data, "val"));
    // cpuf::printf("3, type: %s\n", corelib::map::get(data, "template").type().name());
    // auto templ = std::any_cast<Parser::Rule>(corelib::map::get(data, "template"));
    // arr_t<Parser::Rule> templ_val;
    // if (templ.data.has_value()) {
    //     cpuf::printf("4\n");
    //     templ_val = std::any_cast<arr_t<Parser::Rule>>(templ.data);
    // }
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
    return { result };
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
    auto val = std::any_cast<std::string>(corelib::map::get(data, "type"));
    auto templ = std::any_cast<Parser::Rule>(corelib::map::get(data, "template"));
    arr_t<Parser::Rule> templ_val;
    if (templ.data.has_value()) {
        templ_val = std::any_cast<arr_t<Parser::Rule>>(templ.data);
    }
    if (val == "var" || val == "any")
        return {IR::var_types::ANY, {}};
    else if (val == "str")
        return {IR::var_types::STRING, {}};
    else if (val == "bool")
        return {IR::var_types::BOOLEAN, {}};
    else if (val == "num")
        return {IR::var_types::NUMBER, {}};
    else if (val == "arr") {
        IR::var_types type = IR::var_types::ARRAY;
        IR::var_type _template = cllTreeTypeToIR(templ_val[0]);
        return {type, {_template}};
    } else if (val == "obj") {        
        IR::var_types type = IR::var_types::OBJECT;
        IR::var_type _template1 = cllTreeTypeToIR(templ_val[0]);
        IR::var_type _template2 = cllTreeTypeToIR(templ_val[1]);
        return {type, {_template1, _template2}};
    }
    throw Error("undefined abstract type");
}
IR::var_assign_types TreeOpToIR(Parser::Rule rule) {
    auto data = std::any_cast<Parser::Rule>(rule.data);
    if (!data.data.has_value())
        return IR::var_assign_types::ASSIGN;
    auto val = std::any_cast<std::string>(data.data);
    if (val == ">>")
        return IR::var_assign_types::BITWISE_RIGHTSHFT;
    if (val == "<<")
        return IR::var_assign_types::BITWISE_LEFTSHIFT;
    // all other is single character so can use switch
    switch (val[0]) {
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
    }
    throw Error("Undefined operator");
}
IR::expr TreeOpToExpr(Parser::Rule rule) {
    auto data = std::any_cast<std::string>(rule.data);
    if (data == ">>")
        return {IR::condition_types::RIGHT_BITWISE};
    if (data == "<<")
        return {IR::condition_types::LEFT_BITWISE};
    // all other is single character so can use switch
    switch (data[0]) {
        case '+':
            return {IR::condition_types::ADD};
        case '-':
            return {IR::condition_types::SUBSTR};
        case '*':
            return {IR::condition_types::MULTIPLY};
        case '/':
            return {IR::condition_types::DIVIDE};
        case '%':
            return {IR::condition_types::MODULO};
        case '&':
            return {IR::condition_types::BITWISE_AND};
        case '|':
            return {IR::condition_types::BITWISE_OR};
        case '^':
            return {IR::condition_types::BITWISE_ANDR};
        default:
            throw Error("Undefined operator");
    }
}
IR::expr TreeCompareOpToExpr(Parser::Rule rule) {
    auto data = std::any_cast<std::string>(rule.data);
    if (data == "==")
        return {IR::condition_types::EQUAL};
    if (data == "!=")
        return {IR::condition_types::NOT_EQUAL};
    if (data == ">")
        return {IR::condition_types::HIGHER};
    if (data == "<")
        return {IR::condition_types::LOWER};
    if (data == ">=")
        return {IR::condition_types::HIGHER_OR_EQUAL};
    if (data == "<=")
        return {IR::condition_types::LOWER_OR_EQUAL};
    throw Error("undefined compare operator");
}
IR::expr TreeLogicalOpToIR(Parser::Rule rule) {
    auto data = std::any_cast<Parser::Rule>(rule.data);
    if (data.name == Parser::Rules::logical_and)
        return {IR::condition_types::AND};
    else if (data.name == Parser::Rules::logical_or)
        return {IR::condition_types::OR};
    throw Error("undefined logical operator");
}
IR::var_assign_types TreeAssignmentOpToIR(Parser::Rule rule) {
    auto data = std::any_cast<Parser::Rule>(rule.data);
    if (!data.data.has_value())
        return IR::var_assign_types::ASSIGN;
    auto v = TreeOpToIR(data);
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
arr_t<IR::expr> TreeExprToIR(Parser::Rule expr);
arr_t<IR::expr> TreeExprGroupToIR(Parser::Rule rule) {
    arr_t<IR::expr> expr;
    auto data = std::any_cast<Parser::Rule>(rule.data);
    auto expression = TreeExprToIR(data);
    expr.push_back({IR::condition_types::GROUP_OPEN});
    expr.insert(expr.end(), expression.begin(), expression.end());
    expr.push_back({IR::condition_types::GROUP_CLOSE});
    return expr;
}
arr_t<IR::expr> TreeExprArithmetic_forToIR(Parser::Rule rule) {
    arr_t<IR::expr> expr;
    auto data = std::any_cast<Parser::Rule>(rule.data);
    switch (data.name)
    {
    case Parser::Rules::expr_group:
    {
        auto group_res = TreeExprGroupToIR(data);
        expr.insert(expr.end(), group_res.begin(), group_res.end());
        break;
    }
    case Parser::Rules::method_call:
        expr.push_back({IR::condition_types::METHOD_CALL, TreeMethodCallToIR(data)});
        break;
    case Parser::Rules::cll_function_call:
        expr.push_back({IR::condition_types::FUNCTION_CALL, TreeFunctionToIR(data)});
        break;
    case Parser::Rules::any_data:
        expr.push_back({IR::condition_types::ANY_DATA, TreeAnyDataToIR(data)});
        break;
    default:
        throw Error("Undefined data in arithmetic_for %s", Parser::RulesToString(data.name));
        break;
    }
    return expr;
}
arr_t<IR::expr> TreeExprArithmeticToIR(Parser::Rule rule) {
    // if (rule.name == Parser::Rules::cll_function_call)
    auto data = std::any_cast<obj_t>(rule.data);
    auto first = std::any_cast<Parser::Rule>(corelib::map::get(data, "first"));
    auto operators = std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(data, "operators"));
    auto sequence = std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(data, "sequence"));
    arr_t<IR::expr> cond;
    auto res = TreeExprArithmetic_forToIR(first);
    cond.insert(cond.end(), res.begin(), res.end());
    for (int i = 0; i < operators.size(); i++) {
        cond.push_back(TreeOpToExpr(operators[i]));
        res = TreeExprArithmetic_forToIR(sequence[i]);
        cond.insert(cond.end(), res.begin(), res.end());
    }
    return cond;
}
arr_t<IR::expr> TreeExprCompareToIR_unit(Parser::Rule rule) {
    switch (rule.name)
    {
    case Parser::Rules::expr_arithmetic:
        return TreeExprArithmeticToIR(rule);
    case Parser::Rules::expr_for_arithmetic:
        return TreeExprArithmetic_forToIR(rule);
    case Parser::Rules::expr_group:
        return TreeExprGroupToIR(rule);
    default:
        throw Error("Undefined expr compare unit\n");
        break;
    }
}
arr_t<IR::expr> TreeExprCompareToIR(Parser::Rule rule) {
    auto data = std::any_cast<obj_t>(rule.data);
    auto first = std::any_cast<Parser::Rule>(corelib::map::get(data, "first"));
    auto operators = std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(data, "operators"));
    auto sequence = std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(data, "sequence"));

    arr_t<IR::expr> cond;
    auto res = TreeExprCompareToIR_unit(first);
    cond.insert(cond.end(), res.begin(), res.end());
    for (int i = 0; i < operators.size(); i++) {
        cond.push_back(TreeCompareOpToExpr(operators[i]));
        res = TreeExprCompareToIR_unit(sequence[i]);
        cond.insert(cond.end(), res.begin(), res.end());
    }
    return cond;
}
arr_t<IR::expr> TreeExprLogicalUnitToIR(Parser::Rule rule) {
    switch (rule.name)
    {
    case Parser::Rules::expr_compare:
        return TreeExprCompareToIR(rule);
    case Parser::Rules::expr_arithmetic:
        return TreeExprArithmeticToIR(rule);
    case Parser::Rules::expr_for_arithmetic:
        return TreeExprArithmetic_forToIR(rule);
    default:
        throw Error("Undefined unit\n");
    }
} 
arr_t<IR::expr> TreeExprLogicalToIR(Parser::Rule rule) {
    auto data = std::any_cast<obj_t>(rule.data);
    auto left = std::any_cast<Parser::Rule>(corelib::map::get(data, "left"));
    auto op = std::any_cast<Parser::Rule>(corelib::map::get(data, "op"));
    auto right = std::any_cast<Parser::Rule>(corelib::map::get(data, "right"));

    arr_t<IR::expr> cond;
    auto left_res = TreeExprLogicalUnitToIR(left);
    auto op_res = TreeLogicalOpToIR(op);
    auto rigth_res = TreeExprLogicalUnitToIR(right);
    cond.insert(cond.end(), left_res.begin(), left_res.end());
    cond.push_back(op_res);
    cond.insert(cond.end(), rigth_res.begin(), rigth_res.end());
    return cond;
}
arr_t<IR::expr> TreeExprToIR(Parser::Rule expr) {
    auto val = std::any_cast<Parser::Rule>(expr.data);
    switch(val.name) {
        case Parser::Rules::expr_logical:
            return TreeExprLogicalToIR(val);
        case Parser::Rules::expr_compare:
            return TreeExprCompareToIR(val);
        case Parser::Rules::expr_arithmetic:
            return TreeExprArithmeticToIR(val);
        case Parser::Rules::expr_group:
            return TreeExprGroupToIR(val);
        case Parser::Rules::cll_function_call:
            return {{IR::condition_types::FUNCTION_CALL, TreeFunctionToIR(val)}};
        case Parser::Rules::any_data:
            return {{IR::condition_types::ANY_DATA, TreeAnyDataToIR(val)}};
        case Parser::Rules::method_call:
            return {{IR::condition_types::METHOD_CALL, TreeMethodCallToIR(val)}};
    }
    throw Error("Undefined tree unit: %s", Parser::RulesToString(val.name));
}

// Function to compare two `templ` arrays
bool compare_templ(const arr_t<IR::var_type>& templ1, const arr_t<IR::var_type>& templ2) {
    if (templ1.size() != templ2.size()) return false;

    for (size_t i = 0; i < templ1.size(); ++i) {
        if (templ1[i].type != templ2[i].type) return false;
        if (!compare_templ(templ1[i].templ, templ2[i].templ)) return false;  // Recursively compare nested `templ`
    }
    return true;
}
bool compare_types(std::list<IR::var_type> types) {
    if (types.empty())
        return false;
    IR::var_type first_type = types.front();
    bool is_same = true;
    bool begin = true;
    for (auto el : types) {
        if (begin) {
            begin = false;
            continue;
        }
        if (first_type.type != el.type || compare_templ(first_type.templ, el.templ)) {
            is_same = false;
            break;
        }
    }
    return is_same;
}
IR::variable getElementbyAccessor(IR::accessor &accessor, IR::var_elements &elements, IR::groups &groups, bool is_match_rule) {
    enum class accessor_states {
        GROUP, ELEMENT, CHAR, UNKNOWN
    };
    accessor_states state = accessor_states::UNKNOWN;
    IR::variable* elements_pointer = nullptr;
    IR::var_group* group_pointer = nullptr; 
    for (auto &unit : accessor.elements) {
        auto num = std::any_cast<Parser::Rule>(unit.data);
        auto num_data = std::any_cast<obj_t>(num.data);
        auto num_main = std::any_cast<double>(corelib::map::get(num_data, "main_n")) - 1;
        switch (unit.name)
        {
        case Parser::Rules::accessors_group:
            //cpuf::printf("accessor $%d\n", (int) num_main);
            if (state == accessor_states::ELEMENT)
                throw Error("accessor %% cannot refer to accessor $");
            else if (state == accessor_states::GROUP) {
                if (num_main > group_pointer->end)
                    throw Error("Group %d does not exist", (int) group_pointer->end + num_main);
                group_pointer += (int) num_main;
            } else {
                state = accessor_states::GROUP;
                if (num_main > groups.size())
                    throw Error("Group %d does not exist", (int) num_main);
                //cpuf::printf("Accessing %d, group size: %llu\n", (int) num_main, groups.size());
                group_pointer = &groups[num_main];
            }
            break;
        case Parser::Rules::accessors_element:
            //cpuf::printf("accessor %%%d\n", (int) num_main);
            if (state == accessor_states::ELEMENT) {
                if (&elements_pointer[(int) num_main] >= elements.data() + elements.size())
                    throw Error("Element does not exist");
                elements_pointer += (int) num_main;
            } else if (state == accessor_states::GROUP) {
                if (group_pointer->begin + (int) num_main >= elements.size())
                    throw Error("Element does not exist: %d", group_pointer->begin + (int) num_main);
                elements_pointer = &elements[group_pointer->begin + (int) num_main];
            } else {
                if (num_main >= elements.size())
                    throw Error("Element does not exist. elements size(): %llu while num_main: %d. elements.back().var=%s", elements.size(), (int) num_main, elements.back().name);
                elements_pointer = &elements[num_main];
            }
            state = accessor_states::ELEMENT;
            break;
        case Parser::Rules::accessors_char:
            //cpuf::printf("accessor ^%d\n", (int) num_main);
            if (state != accessor_states::UNKNOWN)
                throw Error("accessor ^ cannot be reffered by another accessor");
            if (is_match_rule)
                throw Error("accessor ^ cannot be used as a match rule");
            break;
        default:
            break;
        }
    }
    return state == accessor_states::ELEMENT ? *elements_pointer : group_pointer->var;
}
void inlineExprAccessor(IR::assign &data, IR::var_elements &elements, IR::groups &groups);
void inlineExprAccessor(arr_t<IR::expr> &expr, IR::var_elements &elements, IR::groups &groups);
void inlineExprAccessor(IR::assign &data, IR::var_elements &elements, IR::groups &groups) {
    if (data.kind == IR::var_assign_values::ACCESSOR) {
        auto accessor = std::any_cast<IR::accessor>(data.data);
        if (accessor.elements[0].name == Parser::Rules::accessors_char) {
            if (accessor.elements.size() > 1)
                throw Error("Cannot refer subaccessor for accessor '^");

            auto num = std::any_cast<Parser::Rule>(accessor.elements[0].data);
            auto num_data = std::any_cast<obj_t>(num.data);
            auto num_main = std::any_cast<double>(corelib::map::get(num_data, "main_n")) - 1;
            data.kind = IR::var_assign_values::CURRENT_POS;
            data.data = num_main;
            return;
        }
        // a regular accessor
        auto var = getElementbyAccessor(accessor, elements, groups, false);
        data.kind = IR::var_assign_values::VARIABLE;
        data.data = var;
    } else if (data.kind == IR::var_assign_values::EXPR) {
        auto dt = std::any_cast<arr_t<IR::expr>>(data.data);
        inlineExprAccessor(dt, elements, groups);
        data.data = dt;

    }
}
void inlineExprAccessor(arr_t<IR::expr> &expr, IR::var_elements &elements, IR::groups &groups) {
    for (auto &unit : expr) {
        if (unit.id == IR::condition_types::ANY_DATA) {
            auto data = std::any_cast<IR::assign>(unit.value);
            inlineExprAccessor(data, elements, groups);
            unit.value = data;
        }
    }
}
void inlineAccessors(arr_t<IR::member> &values, IR::var_elements elements, IR::groups groups, int &variable_count) {
    if (values.empty() || elements.empty())
        return;
    for (auto it = values.begin(); it != values.end(); it++) {
        auto el = *it;
        if (el.type == IR::types::ACCESSOR) {
            auto accessor = std::any_cast<IR::accessor>(el.value);
            auto var = getElementbyAccessor(accessor, elements, groups, true);
            arr_t<IR::expr> expr = {
                {IR::condition_types::STRNCMP, IR::strncmp{0, var}}
            };
            // go to reverse to get names of var and svar
            bool insideLoop;
            IR::variable accessor_var, accessor_shadow, accessor_svar;
            for (auto reverse_it = std::make_reverse_iterator(it + 1); reverse_it != values.rend(); reverse_it++) {
                if (reverse_it->type == IR::types::INSIDE_LOOP) {
                    insideLoop = true;
                    reverse_it = std::make_reverse_iterator(values.erase(std::prev(reverse_it.base())));
                } else if (reverse_it->type == IR::types::VARIABLE) {
                    auto data = std::any_cast<IR::variable>(reverse_it->value);
                    if (accessor_svar.name.empty()) {
                        accessor_svar = data;
                    } else if (accessor_shadow.name.empty()) {
                        accessor_shadow = data;
                    } else {
                        accessor_var = data;
                        break;
                    }
                }
            }
            if (accessor_var.name.empty() || accessor_svar.name.empty())
                throw Error("Cannot find variable and success variable for accessor");
            // replace accessor with rule
            it = values.erase(it); // Erase the accessor element and update iterator
            arr_t<IR::member> block = createDefaultBlock(accessor_var, accessor_svar);
            IR::ir result_rule;
            pushBasedOnQualifier(expr, block, accessor_var, accessor_svar, result_rule, accessor.qualifier, variable_count, insideLoop, false);
            // replace_exit_to_unsuccess(result_rule.elements, accessor_svar);
            it = values.insert(it, result_rule.elements.begin(), result_rule.elements.end()); // Insert new elements and update iterator
            if (it != values.end())
                std::advance(it, result_rule.elements.size() - 1); // Move iterator past the newly inserted elements
        } else if (el.type == IR::types::IF || el.type == IR::types::WHILE || el.type == IR::types::DOWHILE) {
            auto dt = std::any_cast<IR::condition>(el.value);
            inlineExprAccessor(dt.expression, elements, groups);
            inlineAccessors(dt.block, elements, groups, variable_count);
            it->value = dt;
        } else if (el.type == IR::types::VARIABLE) {
            auto data = std::any_cast<IR::variable>(el.value);
            inlineExprAccessor(data.value, elements, groups);
            it->value = data;
        } else if (el.type == IR::types::ASSIGN_VARIABLE) {
            auto data = std::any_cast<IR::variable_assign>(el.value);
            inlineExprAccessor(data.value, elements, groups);
            it->value = data;
        }
    }
}
IR::var_type deduceTypeFromAnyData(Parser::Rule value, std::list<IR::variable> &vars, IR::var_elements &elements, IR::groups &groups) {
    auto val = std::any_cast<Parser::Rule>(value.data);
    IR::var_type type;
    switch (val.name)
    {
    case Parser::Rules::string:
        type.type = IR::var_types::STRING;
        break;
    case Parser::Rules::var_refer:
    {        
        IR::var_refer refer;
        auto data = std::any_cast<obj_t>(val.data);
        auto name = std::any_cast<Parser::Rule>(corelib::map::get(data, "name"));
        auto name_str = std::any_cast<std::string>(name.data);
        auto var = std::find_if(vars.begin(), vars.end(), [&name_str](const IR::variable var) {return var.name == name_str;});
        if (var == vars.end())
            throw Error("Requested variable in expression could not be found: %s", name_str);
        if (var->type.type == IR::var_types::Token_result) {
            type.type = IR::var_types::Token;
        } else if (var->type.type == IR::var_types::Rule_result) {
            type.type = IR::var_types::Rule;
        } else {
            type = var->type;
        }
        break;
    }
    case Parser::Rules::boolean: 
    {
        type.type = IR::var_types::BOOLEAN;
        break;
    }
    case Parser::Rules::number: 
    {
        
        type.type = IR::var_types::NUMBER;
        break;
    }
    case Parser::Rules::array:
    {
        //cpuf::printf("array\n");
        auto data = std::any_cast<arr_t<Parser::Rule>>(val.data);
        std::list<IR::var_type> types;
        
        for (auto &el : data) {
            types.push_back(deduceTypeFromAnyData(el, vars, elements, groups));
        }
        bool is_same = compare_types(types);
        type.type = IR::var_types::ARRAY;
        type.templ = {is_same ? types.front() : IR::var_type {IR::var_types::ANY}};
        break;
    }
    case Parser::Rules::object:
    {
        //cpuf::printf("object\n");
        auto data = std::any_cast<obj_t>(val.data);
        auto key = std::any_cast<Parser::Rule>(corelib::map::get(data, "key"));
        auto value = std::any_cast<Parser::Rule>(corelib::map::get(data, "value"));
        auto keys = std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(data, "keys"));
        auto values = std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(data, "values"));
        
        keys.insert(keys.begin(), key);
        values.insert(values.begin(), value);
        std::list <IR::var_type> types;
        for (int i = 0; i < keys.size(); i++) {
            auto key = keys[i];
            auto value = values[i];
            auto type = deduceTypeFromAnyData(value, vars, elements, groups);
            types.push_back(type);
        }
        bool is_same = compare_types(types);
        type.type = IR::var_types::OBJECT;
        type.templ = {is_same ? arr_t<IR::var_type> {{IR::var_types::STRING}, types.front()} : arr_t<IR::var_type> {{IR::var_types::STRING}, {IR::var_types::ANY}}};
        break;
    }
    case Parser::Rules::accessor:
    {
        //cpuf::printf("accessor\n");
        auto accessor = std::any_cast<IR::accessor>(TreeAnyDataToIR(value).data);
        auto name = getElementbyAccessor(accessor, elements, groups, false);
        auto var = std::find_if(vars.begin(), vars.end(), [&name](const IR::variable var) {return var.name == name.name;});
        if (var->type.type == IR::var_types::Token_result) {
            type.type = IR::var_types::Token;
        } else if (var->type.type == IR::var_types::Rule_result) {
            type.type = IR::var_types::Rule;
        } else {
            type = var->type;
        }
        break;
    }
    default:
        throw Error("Undefined rule");
        break;
    }
    return type;
}
IR::var_type deduceTypeFromExpr(Parser::Rule expr, std::list<IR::variable> &vars, IR::var_elements &elements, IR::groups &groups) {
    switch (expr.name) {
        // case Parser::Rules::expr_logical:
        //     return exprLogicalDeduceType(data);
        // case Parser::Rules::expr_compare:
        //     return exprCompareDeduceType(data);
        // case Parser::Rules::expr_arithmetic:
        //     return exprArithmeticDeduceType(data);
        // case Parser::Rules::expr_group:
        //     return deduceTypeFromExpr(std::any_cast<Parser::Rule>(data.data));
        case Parser::Rules::any_data:
            return deduceTypeFromAnyData(expr, vars, elements, groups);
        default:
            throw Error("Undefined expression unit: %s", Parser::RulesToString(expr.name));
    }
}
IR::data_block TreeDataBlockToIR(Parser::Rule rule, IR::var_elements elements, IR::groups groups, IR::variables vars) {
    auto val = std::any_cast<Parser::Rule>(rule.data);
    IR::data_block datablock;
    if (val.name == Parser::Rules::Rule_data_block_inclosed_map) {
        // inclosed map
        datablock.is_inclosed_map = true;
        IR::inclosed_map map;
        auto keys = std::any_cast<arr_t<Parser::Rule>>(val.data);
        for (auto &key : keys) {
            auto data = std::any_cast<obj_t>(key.data);
            auto k = std::any_cast<Parser::Rule>(corelib::map::get(data, "name"));
            auto v = std::any_cast<Parser::Rule>(corelib::map::get(data, "val"));
            if (v.name == Parser::Rules::expr) {
                auto expr = TreeExprToIR(v);
                inlineExprAccessor(expr, elements, groups);
                map[std::any_cast<std::string>(k.data)] = {expr, deduceTypeFromExpr(std::any_cast<Parser::Rule>(v.data), vars, elements, groups)};
            } 
        }
        datablock.value = {IR::var_assign_values::INCLOSED_MAP, map};
    } else if (val.name == Parser::Rules::any_data) {
        datablock.is_inclosed_map = false;
        datablock.value = TreeAnyDataToIR(val);
        datablock.assign_type = deduceTypeFromExpr(val, vars, elements, groups);
        inlineExprAccessor(datablock.value, elements, groups);
    } else throw Error("Undefined data block val\n");
    return datablock;
}
IR::node_ret_t processGroup(Parser::Rule rule, IR::ir &member, int &variable_count, char qualifier_char, std::string &fullname, bool isToken, IR::nested_rule_name nested_rule_name, IR::var_elements &elements, IR::groups &groups, IR::variables &vars, bool &insideLoop) {
    //cpuf::printf("group\n");
    auto data = std::any_cast<obj_t>(rule.data);
    auto variable = corelib::map::get(data, "variable").has_value() ? std::any_cast<Parser::Rule>(corelib::map::get(data, "variable")) : Parser::Rule();
    auto val = std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(data, "val"));

    // create variable with name of "var" or with auto-generated one
    auto var = (!variable.empty() && variable.name == Parser::Rules::id) ?
                        createEmptyVariable(std::any_cast<std::string>(variable.data)) :
                        createEmptyVariable(generateVariableName(variable_count));
    auto svar = createSuccessVariable(variable_count);

    arr_t<IR::node_ret_t> node_ret;
    auto groups_el = groups.size();
    groups.push_back({var, elements.size(), 0});
    auto inside_loop_prev = insideLoop;
    if (qualifier_char == '*' || qualifier_char == '+')
        insideLoop = true;
    auto values = rulesToIr(val, fullname, isToken, nested_rule_name, elements, groups, vars, insideLoop, node_ret, variable_count);
    insideLoop = inside_loop_prev;
    groups[groups_el].end = elements.size() - 1;
    var.type = {deduceVarTypeByValue(rule, qualifier_char)};
    if ((qualifier_char == '*' || qualifier_char == '+') && var.type.type != IR::var_types::UNDEFINED && var.type.type != IR::var_types::STRING) {
        var.type.templ = {{var.type.type}};
        var.type.type = IR::var_types::ARRAY;
    }
    arr_t<IR::member> var_members;
    auto switch_type = var.type.type == IR::var_types::ARRAY ? var.type.templ[0].type : var.type.type;
    switch (switch_type) {
        case IR::var_types::STRING:
            // it is a string so add all values
            for (auto node : node_ret) {
                if (node.var.name == "" && node.svar.name == "")
                    continue;
                var_members.push_back(
                    {
                        IR::types::ASSIGN_VARIABLE, 
                        IR::variable_assign {var.name, IR::var_assign_types::ADD, IR::assign { IR::var_assign_values::VARIABLE, node.var }}
                    }
                );
            }
            break;
        case IR::var_types::Token:
        case IR::var_types::Rule:
            // it is token so perform a single assign
            var_members.push_back(
                {
                    IR::types::ASSIGN_VARIABLE,
                    IR::variable_assign {var.name, IR::var_assign_types::ASSIGN, IR::assign { IR::var_assign_values::VARIABLE,  node_ret[0].var }}
                }
            );
            var.type = node_ret[0].var.type;
            if (var.type.type == IR::var_types::Rule_result)
                var.type.type = IR::var_types::Rule;
            else if (var.type.type == IR::var_types::Token_result)
                var.type.type = IR::var_types::Token;
            break;
    }
    std::string begin_var_name = "begin" + generateVariableName(variable_count);
    arr_t<IR::expr> svar_expr = {};
    //cpuf::printf("success_vars.size(): %d\n", success_vars.size());
    if (!node_ret.empty()) {
        bool first = true;
        for (auto el : node_ret) {
            if (el.qualifier == '*' || el.qualifier == '?' || el.svar.name.empty())
                continue;
            if (!first)
                svar_expr.push_back({IR::condition_types::AND});

            svar_expr.push_back({IR::condition_types::VARIABLE, el.svar});
            first = false;
        }
    }
    // for (int i = 0; i < node_ret.size(); i++) {
    //     if (i != 0)
    //         svar_expr.push_back({IR::condition_types::AND});
    //     svar_expr.push_back({IR::condition_types::VARIABLE, node_ret[i].svar});
    // }
    auto svar_cond = IR::member {
        IR::types::IF,
        IR::condition {
            svar_expr,
            {
                {IR::types::ASSIGN_VARIABLE, IR::variable_assign {svar.name, IR::var_assign_types::ASSIGN, IR::var_assign_values::_TRUE}},
                {IR::types::POP_POS_COUNTER}
            }
        }
    };
    if (!values.elements.empty() && values.elements.back().type == IR::types::SKIP_SPACES) {
        values.elements.pop_back();
    }
    values.add(var_members);
    auto shadow_var = affectIrByQuantifier(member, values, qualifier_char, var, variable_count, insideLoop);

    if (!shadow_var.name.empty()) {
        groups[groups_el].var = shadow_var;
    }
    if (var.type.type != IR::var_types::UNDEFINED) {
        member.push({IR::types::VARIABLE, var});
    }
    member.push({IR::types::VARIABLE, svar});
    member.push({IR::types::PUSH_POS_COUNTER, begin_var_name});
    if (!variable.empty() && variable.name == Parser::Rules::method_call) 
    {
        IR::method_call method_call = TreeMethodCallToIR(std::any_cast<Parser::Rule>(variable.data));
        member.add(values);
        member.push({IR::types::METHOD_CALL, method_call});
    } else {
        member.add(values);
    }
    member.push(svar_cond);
    if (var.type.type == IR::var_types::UNDEFINED)
        return {svar};
    return {svar, var, shadow_var, qualifier_char};
}
IR::node_ret_t processRuleCsequence(const Parser::Rule &rule, IR::ir &member, int &variable_count, char qualifier_char, bool &insideLoop) {
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
                expr.insert(expr.end(), {
                    {IR::condition_types::CURRENT_CHARACTER},
                    {IR::condition_types::EQUAL},
                    {IR::condition_types::CHARACTER, getEscapedChar(std::any_cast<std::string>(value.data)[0])}
                });
                break;
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
    pushBasedOnQualifier(expr, block, var, svar, member, qualifier_char, variable_count, insideLoop, false);
    return {svar, var, {}, qualifier_char};
}
IR::node_ret_t processString(const Parser::Rule &rule, IR::ir &member, int &variable_count, char qualifier_char, bool &insideLoop) {
    //cpuf::printf("string, data: %s\n", std::any_cast<std::string>(rule.data));
    auto data = std::any_cast<std::string>(rule.data);
    auto var = createEmptyVariable(generateVariableName(variable_count));
    auto svar = createSuccessVariable(variable_count);
    var.type = {IR::var_types::STRING};
    arr_t<IR::expr> expr;
    if (data.size() == 0)
        return {};
    if (data.size() == 1) {
        // micro optimization - compare as single character for single character strings
        expr = {
            {IR::condition_types::CURRENT_CHARACTER},
            {IR::condition_types::EQUAL},
            {IR::condition_types::CHARACTER, data[0]}
        };
    } else {
        expr = {
            {IR::condition_types::STRNCMP, IR::strncmp{1, data}}
        };
    }

    arr_t<IR::member> block = createDefaultBlock(var, svar);
    member.push({IR::types::VARIABLE, var});
    member.push({IR::types::VARIABLE, svar});
    pushBasedOnQualifier(expr, block, var, svar, member, qualifier_char, variable_count, insideLoop, false);
    return {svar, var, {}, qualifier_char};
}
IR::node_ret_t process_Rule_hex(const Parser::Rule &rule, IR::ir &member, int &variable_count, char qualifier_char, bool &insideLoop) {
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
    member.push({IR::types::VARIABLE, var});
    member.push({IR::types::VARIABLE, svar});
    auto shadow_var = pushBasedOnQualifier(expr, block, var, svar, member, qualifier_char, variable_count, insideLoop, false);
    return {svar, var, shadow_var, qualifier_char};
}
IR::node_ret_t process_Rule_bin(const Parser::Rule &rule, IR::ir &member, int &variable_count, char qualifier_char, bool &insideLoop) {
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
    auto shadow_var = pushBasedOnQualifier(expr, block, var, svar, member, qualifier_char, variable_count, insideLoop, false);
    return {svar, var, shadow_var, qualifier_char};
}
IR::node_ret_t processAccessor(const Parser::Rule &rule, IR::ir &member, int &variable_count, char qualifier_char, bool &insideLoop) {
    //cpuf::printf("accessor\n");
    auto data = std::any_cast<obj_t>(rule.data);
    auto first = std::any_cast<Parser::Rule>(corelib::map::get(data, "first"));
    auto second = std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(data, "second"));
    auto svar = createSuccessVariable(variable_count);
    auto var = createEmptyVariable(generateVariableName(variable_count));
    auto shadow_var = createEmptyVariable("shadow" + generateVariableName(variable_count));
    second.insert(second.begin(), first);
    for (auto &el : second) {
        el = std::any_cast<Parser::Rule>(el.data);
    }
    auto mem = IR::member {
        IR::types::ACCESSOR,
        IR::accessor { second, qualifier_char }
    };
    if (insideLoop)
        member.push({IR::types::INSIDE_LOOP});
    member.push({IR::types::VARIABLE, var});
    member.push({IR::types::VARIABLE, shadow_var});
    member.push({IR::types::VARIABLE, svar});
    member.push(mem);
    return {svar, var, shadow_var};
}
IR::node_ret_t process_Rule_other(const Parser::Rule &rule, IR::ir &member, int &variable_count, char qualifier_char, std::string fullname, bool isToken, IR::nested_rule_name nested_rule_names, bool &insideLoop) {
    //cpuf::printf("Rule_other");
    auto data = std::any_cast<obj_t>(rule.data);
    auto is_nested = std::any_cast<bool>(corelib::map::get(data, "is_nested"));
    auto name = std::any_cast<Parser::Rule>(corelib::map::get(data, "name"));
    auto nested_name = std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(data, "nested_name"));
    auto name_str = std::any_cast<std::string>(name.data);
    if (is_nested) {
        name_str.insert(0, "_");
        name_str.insert(0, fullname);
    } else if (nested_rule_names.size()) {
        for (int i = nested_rule_names.size() - 1; i; i--) {
            auto current = nested_rule_names[i];
            if (name_str == current.first) {
                name_str = current.second;
            }
        }
    }
    for (auto &name : nested_name) {
        name_str += '_' + std::any_cast<std::string>(name.data);
    }
    //cpuf::printf(", name: %s\n", name_str);

    auto var = createEmptyVariable(generateVariableName(variable_count));
    auto svar = createSuccessVariable(variable_count);
    IR::variable shadow_var;
    bool isCallingToken = corelib::text::isUpper(name_str);
    if (!isToken && isCallingToken) {
        var.type.type = IR::var_types::Token;
    } else {
        var.type = isCallingToken ? IR::var_type {IR::var_types::Token_result} : IR::var_type {IR::var_types::Rule_result};
    }
   
    auto block = createDefaultBlock(var, svar);
    member.push({IR::types::VARIABLE, var});
    member.push({IR::types::VARIABLE, svar});
    if (isToken) {
        // replace variable assignment from pos sequence to current token
        if (!isCallingToken) return {svar, var};
            //throw Error("Cannot call rule from token");
        // remove variable assignemnt
        block.back().type = IR::types::INCREASE_POS_COUNTER_BY_TOKEN_LENGTH;
        block.back().value = var.name;
        var.property_access = {"token"};
        block.erase(block.begin());
        arr_t<IR::expr> expr;
        auto call = createDefaultCall(block, var, name_str, member, expr);
        member.push(call);
        shadow_var = pushBasedOnQualifier_Rule_other(expr, block, var, svar, call, member, qualifier_char, variable_count, insideLoop);

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
                {IR::condition_types::CURRENT_TOKEN, IR::current_token {IR::condition_types::EQUAL, name_str}},
            };
            shadow_var = pushBasedOnQualifier(expr, block, var, svar, member, qualifier_char, variable_count, insideLoop);
        } else {
            block.back().type = IR::types::INCREASE_POS_COUNTER_BY_TOKEN_LENGTH;
            block.back().value = var.name;
            var.property_access = {"token"};
            block.erase(block.begin()); // remove variable assignment
            arr_t<IR::expr> expr;
            auto call = createDefaultCall(block, var, name_str, member, expr);
            member.push(call);
            shadow_var = pushBasedOnQualifier_Rule_other(expr, block, var, svar, call, member, qualifier_char, variable_count, insideLoop);

        }

    }
    return {svar, var, shadow_var, qualifier_char};
}
IR::node_ret_t process_Rule_escaped(const Parser::Rule &rule, IR::ir &member, int &variable_count, char qualifier_char, bool &add_space, bool &insideLoop) {
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

    arr_t<IR::expr> expression;
    if (qualifier_char != '\0')
        UWarning(std::string("Qualifier '%c' after \\") + c + std::string(" ignored"), qualifier_char, c).print();
    switch (c[0]) {
        case 's':
            // do not add skip of spaces
            add_space = false;
            if (member.elements.size() > 0) {
                // remove previous skip of spaces if it does exists
                for (auto rit = member.elements.rbegin(); rit != member.elements.rend(); rit++) {
                    if (rit->type == IR::types::SKIP_SPACES) {
                        member.elements.erase(rit.base());
                        break;
                    }
                }
            }

            if (num_main == 0) {
                //cpuf::printf("on_exit\n");
                return {{}, {}};
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

    auto var = createEmptyVariable(generateVariableName(variable_count));
    auto svar = createSuccessVariable(variable_count);
    var.type = {IR::var_types::STRING};
    arr_t<IR::member> block = {{IR::types::EXIT}};
    arr_t<IR::member> block_after = createDefaultBlock(var, svar);
    member.push({IR::types::VARIABLE, var});
    member.push({IR::types::VARIABLE, svar});
    member.push({IR::types::IF, IR::condition{expression, block}});
    member.add(block_after);
    //cpuf::printf("escaped_close\n");
    return {svar, var, {}, qualifier_char};
}
IR::node_ret_t process_Rule_any(const Parser::Rule &rule, IR::ir &member, int &variable_count, char qualifier_char, bool &add_space, bool &insideLoop) {
    //cpuf::printf("Rule_any\n");
    auto var = createEmptyVariable(generateVariableName(variable_count));
    auto svar = createSuccessVariable(variable_count);
    var.type = {IR::var_types::STRING};
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
    return {svar, var};
}
arr_t<IR::member> convert_op_rule(arr_t<Parser::Rule> &rules, int &variable_count, IR::variable var, char qualifier_char, std::string fullname, bool isToken, IR::nested_rule_name nested_rule_names, IR::var_elements &elements, IR::groups &groups, IR::variables &vars, bool &insideLoop) {
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
    IR::var_elements new_elements;
    IR::groups new_groups;
    if (rule_val.name == Parser::Rules::Rule_group || rule_val.name == Parser::Rules::accessor)
        ruleToIr(rule, new_ir, variable_count, isToken, nested_rule_names, new_elements, new_groups, vars, insideLoop, fullname, success_var, new_qualifier);
    else    
        ruleToIr(rule, new_ir, variable_count, isToken, nested_rule_names, new_elements, new_groups, vars, insideLoop, fullname, success_var);
    
    groups.insert(groups.end(), new_groups.begin(), new_groups.end());
    for (auto el : new_groups) {
        for (int i = el.begin; i < el.end; i++) {
            elements.push_back(new_elements[i]);
        }
    }
    std::vector<int> erase_indices;
    std::vector<int> push_indices;
    if (rule_val.name == Parser::Rules::Rule_group || rule_val.name == Parser::Rules::accessor) {
        new_ir.elements.back().type = IR::types::RESET_POS_COUNTER; // remove space skip
        auto cond = IR::condition {
            arr_t<IR::expr> {
                {IR::condition_types::NOT}, {IR::condition_types::VARIABLE, success_var.svar}
            },
            convert_op_rule(rules, variable_count, var, qualifier_char, fullname, isToken, nested_rule_names, elements, groups, vars, insideLoop),
        };
        auto v = !success_var.shadow_var.name.empty() ? success_var.shadow_var : success_var.var;
        auto assign_type = v.type.type == IR::var_types::STRING ? IR::var_assign_types::ADD : IR::var_assign_types::ASSIGN;
        if (!v.name.empty()) {
            cond.else_block = {{
                IR::types::ASSIGN_VARIABLE,
                IR::variable_assign 
                {
                    var.name,
                    assign_type,
                    IR::assign {
                        IR::var_assign_values::VARIABLE,
                        v
                    }
                }
            }};
        } 
        new_ir.push({IR::types::IF, cond});
    } else {
        replaceToPrevChar(new_ir.elements, 0);
        for (int i = 0; i < new_ir.elements.size(); i++) {
            auto &el = new_ir.elements[i];
            if (el.type == IR::types::IF) {
                auto val = std::any_cast<IR::condition>(el.value);
                // get recursively nested block
                val.block = convert_op_rule(rules, variable_count, var, qualifier_char, fullname, isToken, nested_rule_names, elements, groups, vars, insideLoop);
                // change condition and remove it's content into else blocks
                for (int j = i + 1; j < new_ir.elements.size(); j++) {
                    auto el = new_ir.elements[j];
                    erase_indices.push_back(j);
                    if (el.type != IR::types::SKIP_SPACES) {
                        val.else_block.push_back(el);
                    }
                }
                // push into else block an assignment to variable
                if (var.type.type == IR::var_types::ARRAY) {
                    val.else_block.push_back({IR::types::METHOD_CALL, IR::method_call { var.name, {IR::function_call {"push", {IR::assign {IR::var_assign_values::VARIABLE, success_var.var}}}}}});
                } else {
                    auto v = !success_var.shadow_var.name.empty() ? success_var.shadow_var : success_var.var;
                    auto assign_type = v.type.type == IR::var_types::STRING ? IR::var_assign_types::ADD : IR::var_assign_types::ASSIGN;
                    val.else_block.push_back({
                        IR::types::ASSIGN_VARIABLE,
                        IR::variable_assign 
                        {
                            var.name,
                            assign_type,
                            IR::assign {
                                IR::var_assign_values::VARIABLE,
                                v
                            }
                        }
                    });
                }
                
                // update the value
                el.value = val;
            }
        }
    }

    // Erase marked indices in reverse to prevent shifting issues
    for (int i = erase_indices.size() - 1; i >= 0; i--) {
        new_ir.elements.erase(new_ir.elements.begin() + erase_indices[i]);
    }
    cpuf::printf("fullname: %s\n", fullname.c_str());

    return new_ir.elements;
}

IR::node_ret_t process_Rule_op(const Parser::Rule &rule, IR::ir &member, int &variable_count, char qualifier_char, std::string fullname, bool isToken, IR::nested_rule_name nested_rule_name, IR::var_elements &elements, IR::groups &groups, IR::variables &vars, bool &insideLoop) {
    //cpuf::printf("Rule_op\n");
    auto op = std::any_cast<arr_t<Parser::Rule>>(rule.data);
    auto var = createEmptyVariable(generateVariableName(variable_count));
    auto svar = createSuccessVariable(variable_count);
    auto block = createDefaultBlock(var, svar);
    // Add success variable
    var.type = {deduceVarTypeByValue(rule)};
    if (insideLoop && var.type.type != IR::var_types::STRING) {
        var.type.templ = {{var.type.type}};
        var.type.type = IR::var_types::ARRAY;
    }
    member.push({IR::types::VARIABLE, var});
    member.push({IR::types::VARIABLE, svar});
    // Convert rules into IR
    // for (auto rule : op) {
    //     auto rule_data = std::any_cast<obj_t>(rule.data);
    //     auto rule_val = std::any_cast<Parser::Rule>(corelib::map::get(rule_data, "val"));
    //     auto qualifier = std::any_cast<Parser::Rule>(corelib::map::get(rule_data, "qualifier"));
    //     if (rule_val.name == Parser::Rules::Rule_other) {
    //         auto data = std::any_cast<obj_t>(rule_val.data);
    //         auto id = std::any_cast<Parser::Rule>(corelib::map::get(data, "name"));
    //         auto id_str = std::any_cast<std::string>(id.data);
    //     }
    // }
    auto res = convert_op_rule(op, variable_count, var, qualifier_char,  fullname, isToken, nested_rule_name, elements, groups, vars, insideLoop);
    member.add(res);
    block.erase(block.begin()); // remove variable assignment (it is done in else blocks)
    block.erase(block.end() - 1);
    // Append default block
    member.add(block);
    return {svar, var, {}, qualifier_char};
}
void process_cll_var(const Parser::Rule &rule, IR::ir &member, int &variable_count, char qualifier_char, bool isToken, IR::variables &vars) {
    // get data section
    auto data = std::any_cast<obj_t>(rule.data);
    auto type = std::any_cast<Parser::Rule>(corelib::map::get(data, "type"));
    auto name = std::any_cast<Parser::Rule>(corelib::map::get(data, "id"));
    auto name_str = std::any_cast<std::string>(name.data);
    auto op = std::any_cast<Parser::Rule>(corelib::map::get(data, "operator"));
    auto value = std::any_cast<Parser::Rule>(corelib::map::get(data, "value"));

    IR::var_type ir_type;
    IR::var_assign_types assign_types;
    IR::assign assign;
    if (type.data.has_value()) {
        ir_type = cllTreeTypeToIR(type);
    }
    if (op.data.has_value()) {
        assign_types = TreeOpToIR(op);
        if (value.name == Parser::Rules::expr)
            assign = {IR::var_assign_values::EXPR, TreeExprToIR(value)};
        // else
        //     assign = TreeTernaryToIR(value);
    }
    if (type.data.has_value()) {
        IR::variable var = {name_str, ir_type, assign};
        member.push({IR::types::VARIABLE, var});
        vars.push_back(var);
    } else {
        member.push({IR::types::ASSIGN_VARIABLE, IR::variable_assign {name_str, assign_types, assign}});
    }
}
IR::condition process_cll_cond(const Parser::Rule &rule, IR::ir &member, int &varriable_count, std::string fullname, bool isToken, IR::nested_rule_name nested_rule_names, IR::var_elements &elements, IR::groups &groups, IR::variables &vars, bool &insideLoop) {
    auto data = std::any_cast<obj_t>(rule.data);
    auto expr = std::any_cast<Parser::Rule>(corelib::map::get(data, "expr"));
    auto block = std::any_cast<Parser::Rule>(corelib::map::get(data, "block"));
    auto block_data = std::any_cast<arr_t<Parser::Rule>>(block.data);
    auto block_ir = rulesToIr(block_data, fullname, isToken, nested_rule_names, elements, groups, vars, insideLoop, varriable_count);
    IR::condition cond;
    cond.expression = TreeExprToIR(expr);
    cond.block = block_ir.elements;
    return cond;
}
IR::node_ret_t process_cll(const Parser::Rule &rule, IR::ir &member, int &variable_count, char qualifier_char, std::string fullname, bool &add_skip_space, bool isToken, IR::nested_rule_name nested_rule_names, IR::var_elements &elements, IR::groups &groups, IR::variables &vars, bool &insideLoop) {
    add_skip_space = false;
    auto rule_val = std::any_cast<Parser::Rule>(rule.data);
    IR::condition cond;
    switch (rule_val.name)
    {
    case Parser::Rules::cll_var:
        process_cll_var(rule_val, member, variable_count, qualifier_char, isToken, vars);
        break;
    case Parser::Rules::cll_if:
        cond = process_cll_cond(rule_val, member, variable_count, fullname, isToken, nested_rule_names, elements, groups, vars, insideLoop);
        member.push({IR::types::IF, cond});
        break;
    case Parser::Rules::loop_while:
    {
        bool insideLoop_prev = insideLoop;
        insideLoop = true;
        cond = process_cll_cond(rule_val, member, variable_count, fullname, isToken, nested_rule_names, elements, groups, vars, insideLoop);
        member.push({IR::types::WHILE, cond});
        insideLoop = insideLoop_prev;
        break;
    }
    default:
        break;
    }
    return {{}, {}};
}

void ruleToIr(Parser::Rule &rule_rule, IR::ir &member, int &variable_count, bool isToken, IR::nested_rule_name nested_rule_name, IR::var_elements &elements, IR::groups &groups, IR::variables &vars, bool &insideLoop, std::string &fullname, IR::node_ret_t &success_var, char custom_qualifier) {
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
            success_var = processGroup(rule, member, variable_count, qualifier_char, fullname, isToken, nested_rule_name, elements, groups, vars, insideLoop);
            break;
        case Parser::Rules::Rule_csequence:
            success_var = processRuleCsequence(rule, member, variable_count, qualifier_char, insideLoop);
            break;
        case Parser::Rules::string:
            success_var = processString(rule, member, variable_count, qualifier_char, insideLoop);
            break;
        case Parser::Rules::accessor:
            success_var = processAccessor(rule, member, variable_count, qualifier_char, insideLoop);
            break;
        case Parser::Rules::Rule_hex:
            success_var = process_Rule_hex(rule, member, variable_count, qualifier_char, insideLoop);
            break;
        case Parser::Rules::Rule_bin: 
            success_var = process_Rule_bin(rule, member, variable_count, qualifier_char, insideLoop);
            break;
        case Parser::Rules::Rule_other:
            success_var = process_Rule_other(rule, member, variable_count, qualifier_char, fullname, isToken, nested_rule_name, insideLoop);
            break;
        case Parser::Rules::Rule_escaped:
            success_var = process_Rule_escaped(rule, member, variable_count, qualifier_char, add_space_skip, insideLoop);
            break;
        case Parser::Rules::Rule_any:
            success_var = process_Rule_any(rule, member, variable_count, qualifier_char, add_space_skip, insideLoop);
            break;
        case Parser::Rules::Rule_op:
            success_var = process_Rule_op(rule, member, variable_count, qualifier_char, fullname, isToken, nested_rule_name, elements, groups, vars, insideLoop);
            break;
        case Parser::Rules::cll:
            success_var = process_cll(rule, member, variable_count, qualifier_char, fullname, add_space_skip, isToken, nested_rule_name, elements, groups, vars, insideLoop);
            break;
        case Parser::Rules::linear_comment:
            return;
        default:
            throw Error("Converting undefined rule: %s,%s", Parser::RulesToString(rule_rule.name), Parser::RulesToString(rule.name));
    }
    if (!success_var.shadow_var.name.empty())
        elements.push_back(success_var.shadow_var);
    else if (!success_var.var.name.empty())
        elements.push_back(success_var.var);
    if (add_space_skip)
        member.push({IR::types::SKIP_SPACES, isToken});
    vars.push_back(success_var.var);
    vars.push_back(success_var.svar);
    vars.push_back(success_var.shadow_var);
}
IR::ir rulesToIr(arr_t<Parser::Rule> rules, std::string &rule_name, bool isToken, IR::nested_rule_name &nested_rule_names, IR::var_elements &elements, IR::groups &groups, IR::variables &vars, bool &insideLoop, arr_t<IR::node_ret_t> &success_vars, int &variable_count) {
    IR::ir result;
    for (auto &rule : rules) {
        IR::node_ret_t success_var;
        ruleToIr(rule, result, variable_count, isToken, nested_rule_names, elements, groups, vars, insideLoop, rule_name, success_var);
        success_vars.push_back(success_var);
    }
    return result;
}
IR::ir rulesToIr(arr_t<Parser::Rule> rules, std::string &rule_name, bool isToken, IR::nested_rule_name &nested_rule_names, IR::var_elements &elements, IR::groups &groups, IR::variables &vars, bool &insideLoop, arr_t<IR::node_ret_t> &success_vars) {
    IR::ir result;
    int variable_count = 0;

    for (auto &rule : rules) {
        IR::node_ret_t success_var;
        ruleToIr(rule, result, variable_count, isToken, nested_rule_names, elements, groups, vars, insideLoop, rule_name, success_var);
        success_vars.push_back(success_var);
    }
    return result;
}
IR::ir rulesToIr(arr_t<Parser::Rule> rules, std::string &rule_name, bool isToken, IR::nested_rule_name &nested_rule_names, IR::var_elements &elements, IR::groups &groups, IR::variables &vars, bool &insideLoop, int &variable_count) {
    IR::ir result;
    for (auto &rule : rules) {
        IR::node_ret_t success_var;
        ruleToIr(rule, result, variable_count, isToken, nested_rule_names, elements, groups, vars, insideLoop, rule_name, success_var);
    }
    return result;
}
IR::ir rulesToIr(arr_t<Parser::Rule> rules, std::string &rule_name, bool isToken, IR::nested_rule_name &nested_rule_names, IR::var_elements &elements, IR::groups &groups, IR::variables &vars, bool &insideLoop) {
    IR::ir result;
    int variable_count = 0;
    for (auto &rule : rules) {
        IR::node_ret_t success_var;
        ruleToIr(rule, result, variable_count, isToken, nested_rule_names, elements, groups, vars, insideLoop, rule_name, success_var);
    }
    return result;
}

void getNestedRuleNames(IR::nested_rule_name &nested_rule_name, std::string &fullname, arr_t<Parser::Rule> nested_rules) {
    for (auto el : nested_rules) {
        auto data = std::any_cast<obj_t>(el.data);
        auto name = std::any_cast<std::string>(std::any_cast<Parser::Rule>(corelib::map::get(data, "name")).data); 
        nested_rule_name.push_back({name, fullname + "_" + name}); 
    }
}
IR::ir treeToIr(Parser::Tree &tree, std::string nested_name, IR::nested_rule_name &nested_rule_names) {
    IR::ir result_ir;
    for (auto &el : tree) {
        if (el.name == Parser::Rules::id)
            cpuf::printf("file: %s\n", std::any_cast<std::string>(el.data));
        if (el.name != Parser::Rules::Rule)
            continue;
        IR::var_elements elements;
        IR::groups groups;
        IR::variables vars;
        int variable_count = 0;
        bool insideLoop = false;
        auto data = std::any_cast<obj_t>(el.data);
        auto name = std::any_cast<std::string>(std::any_cast<Parser::Rule>(corelib::map::get(data, "name")).data);
        auto rules = std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(data, "rule"));
        auto data_block = std::any_cast<Parser::Rule>(corelib::map::get(data, "data_block"));
        auto nested_rules = std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(data, "nestedRules"));
        auto fullname = nested_name.empty() ? name : nested_name + "_" + name;
        bool isToken = corelib::text::isUpper(name);
        cpuf::printf("rule: %s\n", name);
        getNestedRuleNames(nested_rule_names, fullname, nested_rules);
        if (!nested_rules.empty())
            result_ir.add(treeToIr(nested_rules, fullname, nested_rule_names));

        auto values = rulesToIr(rules, fullname, isToken, nested_rule_names, elements, groups, vars, insideLoop, variable_count);
        if (!values.elements.empty() && values.elements.back().type == IR::types::SKIP_SPACES)
            values.pop(); // remove skip of spaces at the end
        inlineAccessors(values.elements, elements, groups, variable_count);
        result_ir.push({ isToken ? IR::types::TOKEN : IR::types::RULE, fullname});  
        result_ir.add(values);
        if (data_block.data.has_value())
            result_ir.push({IR::types::DATA_BLOCK, TreeDataBlockToIR(data_block, elements, groups, vars)});
        result_ir.push({IR::types::RULE_END});

    }
    return result_ir;
}
