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
void push_to_elements(arr_t<IR::element_count> &elements, IR::ir &member) {
    elements.push_back({member.size(), elements.size() > 0 ? elements.back().index_in_rule : 0});
}
void push_to_elements_increament(arr_t<IR::element_count> &elements, IR::ir &member) {
    elements.push_back({member.size(), elements.size() > 0 ? elements.back().index_in_rule + 1 : 0});
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
IR::var_types deduceVarTypeByValue(Parser::Rule mem) {
    if (mem.name == Parser::Rules::Rule_rule) {
        auto memdata = std::any_cast<obj_t>(mem.data);
        mem = std::any_cast<Parser::Rule>(corelib::map::get(memdata, "val"));
    }
    if (mem.name == Parser::Rules::Rule_group) {
        auto data = std::any_cast<obj_t>(mem.data);
        auto group = std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(data, "val"));
        if (group.size() == 0) {
            return IR::var_types::UNDEFINED;
        }
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
IR::var_type cllTreeCsupportTypeToIR(Parser::Rule rule) {
    auto data = std::any_cast<obj_t>(rule.data);
    cpuf::printf("1\n");
    bool is_unsigned = std::any_cast<bool>(corelib::map::get(data, "is_unsigned"));
    cpuf::printf("2\n");
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
        cpuf::printf("4\n");
        templ_val = std::any_cast<arr_t<Parser::Rule>>(templ.data);
    }
    cpuf::printf("type: %s\n", val);
    if (val == "var" || val == "any")
        return {IR::var_types::ANY, {}};
    else if (val == "str")
        return {IR::var_types::STRING, {}};
    else if (val == "bool")
        return {IR::var_types::BOOLEAN, {}};
    else if (val == "num")
        return {IR::var_types::NUMBER, {}};
    else if (val == "arr") {
        cpuf::printf("5");
        IR::var_types type = IR::var_types::ARRAY;
        IR::var_type _template = cllTreeTypeToIR(templ_val[0]);
        return {type, {_template}};
    } else if (val == "obj") {        
        cpuf::printf("6");
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
    cpuf::printf("name: %s\n", Parser::RulesToString(rule.name));
    // if (rule.name == Parser::Rules::cll_function_call)
    auto data = std::any_cast<obj_t>(rule.data);
    cpuf::printf("2\n");
    auto first = std::any_cast<Parser::Rule>(corelib::map::get(data, "first"));
    cpuf::printf("3\n");
    auto operators = std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(data, "operators"));
    cpuf::printf("4\n");
    auto sequence = std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(data, "sequence"));
    cpuf::printf("5\n");
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
IR::data_block TreeDataBlockToIR(Parser::Rule rule) {
    auto val = std::any_cast<Parser::Rule>(rule.data);
    IR::data_block datablock;
    if (val.name == Parser::Rules::any_data) {
        datablock.is_inclosed_map = false;
        
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
                        createEmptyVariable(std::any_cast<std::string>(variable.data)) :
                        createEmptyVariable(generateVariableName(variable_count));
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
    if (!node_ret.empty()) {
        svar_expr.push_back({IR::condition_types::VARIABLE, node_ret.back().svar});
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
            {{IR::types::ASSIGN_VARIABLE, IR::variable_assign {svar.name, IR::var_assign_types::ASSIGN, IR::var_assign_values::_TRUE}}}
        }
    };
    affectIrByQualifier(values, qualifier_char, variable_count);
    member.push({IR::types::VARIABLE, var});
    member.push({IR::types::VARIABLE, svar});
    if (!variable.empty() && variable.name == Parser::Rules::method_call) 
    {
        cpuf::printf("On method call\n");
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
    pushBasedOnQualifier(expr, block, svar, member, qualifier_char, variable_count);
    return {svar.name, var.name};
}
IR::node_ret_t processString(const Parser::Rule &rule, IR::ir &member, int &variable_count, char qualifier_char) {
    //cpuf::printf("string, data: %s\n", std::any_cast<std::string>(rule.data));
    auto data = std::any_cast<std::string>(rule.data);
    auto var = createEmptyVariable(generateVariableName(variable_count));
    auto svar = createSuccessVariable(variable_count);
    var.type = {IR::var_types::STRING};
    arr_t<IR::expr> expr;
    if (data.size() == 0)
        return {};
    if (data.size() == 1) {
        expr = {
            {IR::condition_types::CURRENT_CHARACTER},
            {IR::condition_types::EQUAL},
            {IR::condition_types::CHARACTER, data[0]}
        };
    } else {
        expr = {
            {IR::condition_types::STRNCMP, data}
        };
    }

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
IR::node_ret_t process_Rule_other(const Parser::Rule &rule, IR::ir &member, int &variable_count, char qualifier_char, std::string fullname, bool isToken) {
    //cpuf::printf("Rule_other");
    auto data = std::any_cast<obj_t>(rule.data);
    auto is_nested = std::any_cast<bool>(corelib::map::get(data, "is_nested"));
    auto name = std::any_cast<Parser::Rule>(corelib::map::get(data, "name"));
    auto nested_name = std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(data, "nested_name"));
    auto name_str = std::any_cast<std::string>(name.data);
    if (is_nested) {
        name_str.insert(0, "_");
        name_str.insert(0, fullname);
    }
    for (auto &name : nested_name) {
        name_str += '_' + std::any_cast<std::string>(name.data);
    }
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
        UWarning("Qualifier after \\\\%s ignored", c).print();
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

arr_t<IR::member> convert_op_rule(arr_t<Parser::Rule> &rules, int &variable_count, IR::variable var, char qualifier_char, std::string fullname, bool isToken) {
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
        ruleToIr(rule, new_ir, variable_count, isToken, fullname, success_var, new_qualifier);
    else    
        ruleToIr(rule, new_ir, variable_count, isToken, fullname, success_var);
    
    
    std::vector<int> erase_indices;
    std::vector<int> push_indices;
    cpuf::printf("Rule_Val.name: %s\n", Parser::RulesToString(rule_val.name));
    if (rule_val.name == Parser::Rules::Rule_group) {
        auto cond = IR::condition {
            arr_t<IR::expr> {
                {IR::condition_types::NOT}, {IR::condition_types::VARIABLE, success_var.svar}
            },
            convert_op_rule(rules, variable_count, var, qualifier_char, fullname, isToken),
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
                    val.block = convert_op_rule(rules, variable_count, var, qualifier_char, fullname, isToken);
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

IR::node_ret_t process_Rule_op(const Parser::Rule &rule, IR::ir &member, int &variable_count, char qualifier_char, std::string fullname, bool isToken) {
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
        if (rule_val.name == Parser::Rules::Rule_other) {
            auto data = std::any_cast<obj_t>(rule_val.data);
            auto id = std::any_cast<Parser::Rule>(corelib::map::get(data, "name"));
            auto id_str = std::any_cast<std::string>(id.data);
        }
    }
    member.add(convert_op_rule(op, variable_count, var, qualifier_char,  fullname, isToken));

    // Append default block
    member.add(block);

    return {svar.name, var.name};
}
IR::node_ret_t process_cll_var(const Parser::Rule &rule, IR::ir &member, int &variable_count, char qualifier_char, bool isToken) {
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
        member.push({IR::types::VARIABLE, IR::variable {name_str, ir_type, assign}});
    } else {
        member.push({IR::types::ASSIGN_VARIABLE, IR::variable_assign {name_str, assign_types, assign}});
    }
    return {};
}
IR::node_ret_t process_cll_cond(const Parser::Rule &rule, IR::ir &member, int &varriable_count, std::string fullname, bool isToken, bool is_if) {
    auto data = std::any_cast<obj_t>(rule.data);
    auto expr = std::any_cast<Parser::Rule>(corelib::map::get(data, "expr"));
    auto block = std::any_cast<Parser::Rule>(corelib::map::get(data, "block"));
    auto block_data = std::any_cast<arr_t<Parser::Rule>>(block.data);
    auto block_ir = rulesToIr(block_data, fullname, isToken, varriable_count);
    IR::condition cond;
    cond.expression = TreeExprToIR(expr);
    cond.block = block_ir.elements;
    member.push({ is_if ? IR::types::IF : IR::types::WHILE, cond});
    return {};
}
IR::node_ret_t process_cll(const Parser::Rule &rule, IR::ir &member, int &variable_count, char qualifier_char, std::string fullname, bool &add_skip_space, bool isToken) {
    add_skip_space = false;
    auto rule_val = std::any_cast<Parser::Rule>(rule.data);
    switch (rule_val.name)
    {
    case Parser::Rules::cll_var:
        process_cll_var(rule_val, member, variable_count, qualifier_char, isToken);
        break;
    case Parser::Rules::cll_if:
        process_cll_cond(rule_val, member, variable_count, fullname, isToken, true);
        break;
    case Parser::Rules::loop_while:
        process_cll_cond(rule_val, member, variable_count, fullname, isToken, false);
        break;
    default:
        break;
    }
    return {};
}

void ruleToIr(Parser::Rule &rule_rule, IR::ir &member, int &variable_count, bool isToken, std::string fullname, IR::node_ret_t &success_var, char custom_qualifier) {
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
            success_var = process_Rule_other(rule, member, variable_count, qualifier_char, fullname, isToken);
            break;
        case Parser::Rules::Rule_escaped:
            success_var = process_Rule_escaped(rule, member, variable_count, qualifier_char, add_space_skip);
            break;
        case Parser::Rules::Rule_any:
            success_var = process_Rule_any(rule, member, variable_count, qualifier_char, add_space_skip);
            break;
        case Parser::Rules::Rule_op:
            success_var = process_Rule_op(rule, member, variable_count, qualifier_char, fullname, isToken);
            break;
        case Parser::Rules::cll:
            process_cll(rule, member, variable_count, qualifier_char, fullname, add_space_skip, isToken);
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
    if (new_rule) {
        if (isToken)
            result.push({IR::types::TOKEN, rule_name});  
        else
            result.push({IR::types::RULE, rule_name});  
    }

    for (auto &rule : rules) {
        IR::node_ret_t success_var;
        ruleToIr(rule, result, variable_count, isToken, rule_name, success_var);
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
    if (new_rule) {
        if (isToken)
            result.push({IR::types::TOKEN, rule_name});  
        else
            result.push({IR::types::RULE, rule_name});  
    }

    for (auto &rule : rules) {
        IR::node_ret_t success_var;
        ruleToIr(rule, result, variable_count, isToken, rule_name, success_var);
        success_vars.push_back(success_var);
    }

    if (new_rule)
        result.push({IR::types::RULE_END});

    return result;
}
IR::ir rulesToIr(arr_t<Parser::Rule> rules, std::string rule_name, bool isToken, int &variable_count) {
    IR::ir result;
    arr_t<IR::element_count> elements;
    for (auto &rule : rules) {
        IR::node_ret_t success_var;
        ruleToIr(rule, result, variable_count, isToken, rule_name, success_var);
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
        ruleToIr(rule, result, variable_count, isToken, rule_name, success_var);
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
        auto data_block = std::any_cast<Parser::Rule>(corelib::map::get(data, "data_block"));
        auto nested_rules = std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(data, "nestedRules"));
        auto fullname = nested_name.empty() ? name : nested_name + "_" + name;

        if (!nested_rules.empty())
            result_ir.add(treeToIr(nested_rules, fullname));

        result_ir.add(rulesToIr(rules, fullname, corelib::text::isUpper(name), true));
        //result_ir.elements.insert(result_ir.elements.end() - 1, TreeDataBlockToIR(data_block));

    }
    return result_ir;
}
