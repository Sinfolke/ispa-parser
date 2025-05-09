#include <IR/IR.h>
#include <corelib.h>
#include <cpuf/hex.h>
#include <tree.h>
bool LLIR::DataBlock::is_inclosed_map() const {
    return std::holds_alternative<LLIR::inclosed_map>(value);
}
bool LLIR::DataBlock::is_raw_expr() const {
    return std::holds_alternative<LLIR::regular_data_block>(value);
}
bool LLIR::DataBlock::empty() const {
    return std::holds_alternative<std::monostate>(value);
}

LLIR::regular_data_block &LLIR::DataBlock::getExpr() {
    return std::get<LLIR::regular_data_block>(value);
};
LLIR::inclosed_map &LLIR::DataBlock::getInclosedMap() {
    return std::get<LLIR::inclosed_map>(value);
};
const LLIR::regular_data_block &LLIR::DataBlock::getExpr() const {
    return std::get<LLIR::regular_data_block>(value);
};
const LLIR::inclosed_map &LLIR::DataBlock::getInclosedMap() const {
    return std::get<LLIR::inclosed_map>(value);
};
// a structure used to cout
void LLIR::add(LLIR &repr) {
    members.insert(members.end(), repr.members.begin(), repr.members.end());
}
void LLIR::add(std::vector<LLIR::member> repr) {
    members.insert(members.end(), repr.begin(), repr.end());
}
void LLIR::push(LLIR::member member) {
    members.push_back(member);
}
void LLIR::pop() {
    members.pop_back();
};
void LLIR::push_begin(LLIR::member member) {
    members.insert(members.begin(), member);
}
void LLIR::pop_begin() {
    members.erase(members.begin());
};
size_t LLIR::size() {
    return members.size();
}
bool LLIR::empty() {
    return members.empty();
}
auto LLIR::getSuccessVars() const -> const std::vector<ConvertionResult>& {
    return success_vars;
}
std::vector<LLIR::Data> LLIR::getData() const {
    return data;
}
std::vector<LLIR::Data> &LLIR::getData() {
    return data;
}
const std::vector<LLIR::member> &LLIR::getMembers() const {
    return members;
}
std::vector<std::string> LLIR::getFullName() const {
    return fullname;
}
const Tree* LLIR::getTree() const {
    return tree;
}
void LLIR::erase_begin() {
    data.erase(data.begin());
}
void LLIR::clear_thread() {
    variable_count = 0;
    isToken = false;
    insideLoop = false;
    addSpaceSkip = false;
    success_vars.clear();
    vars.clear();
    unnamed_datablock_units.clear();
    key_vars.clear();
    fullname.clear();
}
void LLIR::proceed(const LLIR &ir) {
    variable_count = ir.variable_count;
    isToken = ir.isToken;
    tokensOnly = ir.tokensOnly;
    insideLoop = ir.insideLoop;
    addSpaceSkip = ir.addSpaceSkip;
    fullname = ir.fullname;
    vars = ir.vars;
    isFirst = ir.isFirst;
    key_vars = ir.key_vars;
    unnamed_datablock_units = ir.unnamed_datablock_units;
}
void LLIR::update(LLIR &ir) {
    variable_count = ir.variable_count;
    insideLoop = ir.insideLoop;
    addSpaceSkip = ir.addSpaceSkip;
    vars = ir.vars;
    key_vars = ir.key_vars;
    unnamed_datablock_units = ir.unnamed_datablock_units;
}
LLIR::DataBlockList LLIR::getDataBlocks(bool isToken) {
    DataBlockList list;
    for (const auto &[data_block, name, members] : data) {
        if (isToken) {
            if (corelib::text::isLower(name.back())) continue;
        } else {
            if (corelib::text::isUpper(name.back())) continue;
        }
        list[name] = {data_block};
    }
    return list;
}
LLIR::DataBlockList LLIR::getDataBlocksTerminals() {
    return getDataBlocks(true);
}
LLIR::DataBlockList LLIR::getDataBlocksNonTerminals() {
    return getDataBlocks(false);
}
LLIR::variable LLIR::createEmptyVariable(std::string name) {
    LLIR::variable var {
        name,
        {LLIR::var_types::UNDEFINED},
        LLIR::var_assign_values::NONE,
    };
    return var;
}
std::string LLIR::generateVariableName() {
    return std::string("_") + std::to_string(variable_count++);
}
void LLIR::processExitStatements(std::vector<LLIR::member> &values) {
    for (auto &el : values) {
        if (el.type == LLIR::types::IF || el.type == LLIR::types::WHILE || el.type == LLIR::types::DOWHILE) {
            auto &condition = std::any_cast<LLIR::condition&>(el.value); // Avoid unnecessary copies

            // Process the block and else block of the condition recursively
            processExitStatements(condition.block);
            processExitStatements(condition.else_block);

            // Ensure that any EXIT statements within the blocks are replaced with BREAK_LOOP
            for (auto &unit : condition.block) {
                if (unit.type == LLIR::types::EXIT) {
                    unit.type = LLIR::types::BREAK_LOOP; // Replacing EXIT with BREAK_LOOP
                } else if (unit.type == LLIR::types::IF || unit.type == LLIR::types::WHILE || unit.type == LLIR::types::DOWHILE) {
                    auto &cond = std::any_cast<LLIR::condition&>(unit.value);

                    processExitStatements(cond.block); // Recursive call on nested blocks
                    processExitStatements(cond.else_block); // Recursive call on else blocks
                }
            }
        }
    }
}


LLIR::variable LLIR::createSuccessVariable() {
    LLIR::variable var = createEmptyVariable("success" + generateVariableName());
    var.type = {LLIR::var_types::BOOLEAN};
    var.value = {LLIR::var_assign_values::False};
    return var;
}

void LLIR::addPostLoopCheck(const TreeAPI::RuleMember &rule, const LLIR::variable &var, bool addError) {
    std::vector<LLIR::member> block = {{ LLIR::types::EXIT }};
    if (addError && !isFirst) {
        block.insert(block.begin(), { LLIR::types::ERR, getErrorName(rule)});
    }
    LLIR::condition check_cond = {
        { 
            {LLIR::condition_types::NOT}, 
            { LLIR::condition_types::VARIABLE, var },
        },
        block
    };
    push({LLIR::types::IF, check_cond});
}
void LLIR::handle_plus_qualifier(const TreeAPI::RuleMember &rule, LLIR::condition loop, bool addError) {
    auto var = createSuccessVariable();
    loop.block.push_back({LLIR::types::ASSIGN_VARIABLE, LLIR::variable_assign {var.name, LLIR::var_assign_types::ASSIGN, LLIR::var_assign_values::True}});
    push({LLIR::types::VARIABLE, var});
    push({LLIR::types::WHILE, loop});
    addPostLoopCheck(rule, var, addError);
}
void LLIR::replaceToPrevChar(std::vector<LLIR::member> &elements, int i) {
    for (; i < elements.size(); i++) {
        auto &el = elements[i];
        if (el.type == LLIR::types::IF || el.type == LLIR::types::WHILE || el.type == LLIR::types::DOWHILE) {
            // replace CURRENT_CHARACTER to PREV_CHARACTER
            auto val = std::any_cast<LLIR::condition>(el.value);
            for (auto &expr : val.expression) {
                if (expr.id == LLIR::condition_types::STRNCMP) {
                    expr.id = LLIR::condition_types::STRNCMP_PREV;
                }

            }
            replaceToPrevChar(val.block, 0);
            if (el.type == LLIR::types::IF)
                replaceToPrevChar(val.else_block, 0);
            elements[i].value = val;
        }
    }
}
std::vector<LLIR::member> LLIR::createDefaultBlock(const LLIR::variable &var, const LLIR::variable &svar) {
    return {
        {LLIR::types::ASSIGN_VARIABLE, LLIR::variable_assign {var.name, LLIR::var_assign_types::ADD, LLIR::var_assign_values::CURRENT_POS_SEQUENCE}},
        {LLIR::types::ASSIGN_VARIABLE, LLIR::variable_assign {svar.name, LLIR::var_assign_types::ASSIGN, LLIR::var_assign_values::True}},
        {LLIR::types::INCREASE_POS_COUNTER}
    };
}
std::vector<LLIR::member> LLIR::createDefaultBlock(const LLIR::variable &svar) {
    return {
        {LLIR::types::ASSIGN_VARIABLE, LLIR::variable_assign {svar.name, LLIR::var_assign_types::ASSIGN, LLIR::var_assign_values::True}},
        {LLIR::types::INCREASE_POS_COUNTER}
    };
}
std::vector<LLIR::member> LLIR::createDefaultBlock() {
    return {
        {LLIR::types::INCREASE_POS_COUNTER}
    };
}
char LLIR::getEscapedChar(char in) {
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

LLIR::member LLIR::createDefaultCall(std::vector<LLIR::member> &block, LLIR::variable var, const std::string &name, std::vector<LLIR::expr> &expr) {
    auto function_call = LLIR::function_call {
        name,
        std::vector<std::vector<LLIR::expr>> {{LLIR::expr {LLIR::condition_types::TOKEN_SEQUENCE}}},
        
    };
    auto var_assign = LLIR::variable_assign {
        var.name, 
        LLIR::var_assign_types::ASSIGN,
        { LLIR::var_assign_values::FUNCTION_CALL, function_call }
    };
    var.property_access = {"status"};
    expr = {
        {LLIR::condition_types::VARIABLE, var}
    };
    return {LLIR::types::ASSIGN_VARIABLE, var_assign};
}
LLIR::variable LLIR::add_shadow_variable(std::vector<LLIR::member> &block, const LLIR::variable &var) {
    LLIR::variable shadow_var = createEmptyVariable("shadow" + generateVariableName());
    auto type = var.type;
    if (type.type == LLIR::var_types::Rule_result)
        type.type = LLIR::var_types::Rule;
    else if (type.type == LLIR::var_types::Token_result)
        type.type = LLIR::var_types::Token;
    shadow_var.type = {LLIR::var_types::ARRAY, {type}};
    push({LLIR::types::VARIABLE, shadow_var});
    block.push_back({LLIR::types::METHOD_CALL, LLIR::method_call { shadow_var.name, {LLIR::function_call {"push", {std::vector<std::vector<LLIR::expr>> {{LLIR::expr {LLIR::condition_types::VARIABLE, var}}}}}}}});
    return shadow_var;
}
LLIR::variable LLIR::pushBasedOnQualifier(const TreeAPI::RuleMember &rule, std::vector<LLIR::expr> &expr, std::vector<LLIR::member> &block, const LLIR::variable &var, const LLIR::variable &svar, char quantifier, bool add_shadow_var) {
    //block.push_back({IR::types::ASSIGN_VARIABLE, IR::variable_assign {svar.name, IR::var_assign_types::ASSIGN, IR::var_assign_values::_TRUE}});
    LLIR::variable shadow_variable;
    if ((insideLoop || quantifier == '+' || quantifier == '*') && add_shadow_var) {
       shadow_variable = add_shadow_variable(block, var);
       add_shadow_var = false;
    }
    switch (quantifier) {
        case '+':
            if (add_shadow_var)
                shadow_variable = add_shadow_variable(block, var);
            handle_plus_qualifier(rule, LLIR::condition {expr, block});
            break;
        case '*': {
            if (add_shadow_var)
                shadow_variable = add_shadow_variable(block, var);
            push({LLIR::types::WHILE, LLIR::condition{expr, block}});
            //member.push(pop);
            break;
        }
        case '?':
            push({LLIR::types::IF, LLIR::condition{expr, block}});
            break;
        default:
            // add the negative into condition
            expr.insert(expr.begin(), {LLIR::condition_types::NOT});
            expr.insert(expr.begin() + 1, {LLIR::condition_types::GROUP_OPEN});
            expr.push_back({LLIR::condition_types::GROUP_CLOSE});
            // add exit statement
            std::vector<LLIR::member> blk = {{LLIR::types::EXIT}};
            if (!isFirst) {
                blk.insert(blk.begin(), {LLIR::types::ERR, getErrorName(rule)});
            }
            push({LLIR::types::IF, LLIR::condition{expr, blk}});
            add(block);
            break;
    }
    return shadow_variable;
}
// function to push based on qualifier for Rule_other
LLIR::variable LLIR::pushBasedOnQualifier_Rule_name(const TreeAPI::RuleMember &rule, std::vector<LLIR::expr> &expr, std::vector<LLIR::member> &block, const LLIR::variable &var, const LLIR::variable &svar, const LLIR::member &call, char quantifier, bool add_shadow_var) {
    //block.push_back({IR::types::ASSIGN_VARIABLE, IR::variable_assign {svar.name, IR::var_assign_types::ASSIGN, IR::var_assign_values::_TRUE}});
    LLIR::variable shadow_variable;
    if (insideLoop|| quantifier == '+' || quantifier == '*') {
        shadow_variable = add_shadow_variable(block, var);
        add_shadow_var = false;
    }
    switch (quantifier) {
        case '+':
            if (add_shadow_var)
                shadow_variable = add_shadow_variable(block, var);
            block.push_back(call);
            handle_plus_qualifier(rule, LLIR::condition {expr, block});
            break;
        case '*': {
            if (add_shadow_var)
                shadow_variable = add_shadow_variable(block, var);
            block.push_back(call);
            push({LLIR::types::WHILE, LLIR::condition{expr, block}});
            break;
        }
        case '?':
            push({LLIR::types::IF, LLIR::condition{expr, block}});
            break;
        default:
        {
            // add the negative into condition
            expr.insert(expr.begin(), {LLIR::condition_types::NOT});
            expr.insert(expr.begin() + 1, {LLIR::condition_types::GROUP_OPEN});
            expr.push_back({LLIR::condition_types::GROUP_CLOSE});
            // add exit statement
            std::vector<LLIR::member> blk = {{LLIR::types::EXIT}};
            if (!isFirst) {
                blk.insert(blk.begin(), {LLIR::types::ERR, getErrorName(rule)});
            }
            push({LLIR::types::IF, LLIR::condition{expr, blk}});
            add(block);
            break;
        }
    }
    return shadow_variable;
}
LLIR::variable LLIR::affectIrByQuantifier(const TreeAPI::RuleMember &rule, const LLIR::variable &var, char quantifier) {
    LLIR::variable shadow_var;
    if ((insideLoop || quantifier == '*' || quantifier == '+') && (var.type.type != LLIR::var_types::UNDEFINED && var.type.type != LLIR::var_types::STRING)) {
        shadow_var = add_shadow_variable(members, var);
    }
    if (quantifier == '*' || quantifier == '+') {
        LLIR::condition loop = { { { LLIR::condition_types::NUMBER, (long long) 1 } }, {} };
        loop.block = members;
        data.clear();
        processExitStatements(loop.block);
        // raiseVarsTop(data, loop.block, true, false, false);
        // raiseVarsTop(data, loop.else_block, true, false, false);
        if (quantifier == '+') {
            handle_plus_qualifier(rule, loop);
        } else {
            push({LLIR::types::WHILE, loop});
        }
    } else if (quantifier == '?') {
        LLIR::condition loop = { { {LLIR::condition_types::NUMBER, (long long) 0} } };
        loop.block = members;
        data.clear();
        processExitStatements(loop.block);
        push({ LLIR::types::DOWHILE, loop });
    }
    return shadow_var;
}

// Function to compare two `templ` arrays
bool LLIR::compare_templ(const std::vector<LLIR::var_type>& templ1, const std::vector<LLIR::var_type>& templ2) {
    if (templ1.size() != templ2.size()) return false;

    for (size_t i = 0; i < templ1.size(); ++i) {
        if (templ1[i].type != templ2[i].type) return false;
        if (!compare_templ(templ1[i].templ, templ2[i].templ)) return false;  // Recursively compare nested `templ`
    }
    return true;
}
std::string LLIR::getErrorName(const TreeAPI::RuleMember &rule) {
    if (rule.isGroup()) {
        return "";
    }
    if (rule.isCsequence()) {
        std::string message;
        const auto &csequence = rule.getCsequence();
        
        // Add "not " if negative
        if (csequence.negative) {
            message = "not ";
        }
        
        std::vector<std::string> parts;
        
        // Process characters
        for (const auto &character : csequence.characters) {
            parts.push_back(std::string(1, character));
        }
        
        // Process diapasons
        for (const auto &diapason : csequence.diapasons) {
            parts.push_back(diapason.first + std::string("-") + diapason.second);
        }
        
        // Process escaped sequences
        for (const auto &escaped : csequence.escaped) {
            parts.push_back(std::string("\\") + escaped);
        }


        // Join parts with commas, but "or" only between the last two items
        if (parts.size() > 1) {
            for (size_t i = 0; i < parts.size(); ++i) {
                if (i == parts.size() - 2) {
                    message += parts[i] + " or ";
                } else if (i < parts.size() - 1) {
                    message += parts[i] + ", ";
                } else {
                    message += parts[i];
                }
            }
        } else {
            message += parts.empty() ? "" : parts[0];  // Handle empty or single element case
        }
        return message;
    }
    if (rule.isString()) {
        return '"' + rule.getString().value + '"';
    }
    if (rule.isHex())
        return "0x" + rule.getHex().hex_chars;
    if (rule.isBin())
        return "0b" + rule.getBin().bin_chars;
    if (rule.isName()) {
        const auto &name = rule.getName();
        if (name.isAutoGenerated) {
            const auto r = tree->getRawAst().getTreeMap()[name.name];
            return getErrorName(r.members[0]);
        }
        return name.name.back();
    }
    if (rule.isEscaped()) {
        return std::string("\\") + rule.getEscaped();
    }
    if (rule.isAny()) {
        return "symbol";
    }
    if (rule.isOp()) {
        std::string res;
        const auto &op = rule.getOp();
        for (const auto &option : op) {
            res += getErrorName(option);
            if (&option != &op.back())
                res += " or ";
        }
        return res;
    }
    throw Error("Undefined rule member");
}
LLIR::assign LLIR::TreeRvalueToIR(const TreeAPI::rvalue &value) {
    LLIR::assign newval;
    if (value.isString()) {
        newval.kind = LLIR::var_assign_values::STRING;
        newval.data = std::any_cast<std::string>(value.getString().value);
    } else if (value.isBoolean()) {
        newval.kind = LLIR::var_assign_values::BOOLEAN;
        newval.data = value.getBoolean().getBoolean() ? LLIR::var_assign_values::True : LLIR::var_assign_values::False;
    } else if (value.isNumber()) {
        newval.kind = LLIR::var_assign_values::NUMBER;
        newval.data = value.getNumber().getFull();
    } else if (value.isID()) {
        newval.kind = LLIR::var_assign_values::VARIABLE;
        auto find_it = std::find_if(vars.begin(), vars.end(), [&value](const LLIR::variable &var) { return var.name == value.getID(); });
        if (find_it == vars.end())
            throw Error("Not found variable to convert into expr");
        newval.data = *find_it;
    } else if (value.isAt()) {
        newval.kind = LLIR::var_assign_values::VARIABLE;
        newval.data = unnamed_datablock_units.front();
        unnamed_datablock_units.erase(unnamed_datablock_units.end());
    } else if (value.isArray()) {
        newval.kind = LLIR::var_assign_values::ARRAY;
        LLIR::array arr;
        for (const auto el : value.getArray()) {
            arr.push_back(TreeExprToIR(el));
        }
        newval.data = arr;
    } else if (value.isObject()) {
        newval.kind = LLIR::var_assign_values::OBJECT;
        LLIR::object obj;
        for (const auto &[key, value] : value.getObject()) {
            obj[key] = TreeExprToIR(value);
        }
        newval.data = obj;
    } else throw Error("Undefined rvalue");
    return newval;
}
std::vector<std::vector<LLIR::expr>> LLIR::TreeFunctionBodyCallToIR(const TreeAPI::CllFunctionBodyCall &body) {
    std::vector<std::vector<LLIR::expr>> newExpr;
    for (const auto &expr : body.expr) {
        newExpr.push_back(TreeExprToIR(expr));
    }
    return newExpr;
}
LLIR::function_call LLIR::TreeFunctionToIR(const TreeAPI::CllFunctionCall &call) {
    LLIR::function_call newCall;
    newCall.name = call.name;
    newCall.params = TreeFunctionBodyCallToIR(call.body);
    return newCall;
}

LLIR::method_call LLIR::TreeMethodCallToIR(const TreeAPI::CllMethodCall &method) {
    LLIR::method_call newMethod;
    newMethod.var_name = method.name;
    newMethod.calls = {TreeFunctionToIR(method.body)};
    return newMethod;
}
// possibly outdated
// LLIR::var_type LLIR::cllTreeCsupportTypeToIR(const Parser::Rule &rule) {
//     auto data = std::any_cast<obj_t>(rule.data);
//     bool is_unsigned = std::any_cast<bool>(corelib::map::get(data, "is_unsigned"));
//     auto val = std::any_cast<std::string>(corelib::map::get(data, "val"));
//     // cpuf::printf("3, type: %s\n", corelib::map::get(data, "template").type().name());
//     // auto templ = std::any_cast<Parser::Rule>(corelib::map::get(data, "template"));
//     // std::vector<Parser::Rule> templ_val;
//     // if (templ.data.has_value()) {
//     //     cpuf::printf("4\n");
//     //     templ_val = std::any_cast<std::vector<Parser::Rule>>(templ.data);
//     // }
//     LLIR::var_types result;
//     if (val == "char")
//         result = LLIR::var_types::CHAR;
//     else if (val == "short")
//         result = LLIR::var_types::SHORT;
//     else if (val == "int")
//         result = LLIR::var_types::INT;
//     else if (val == "long")
//         result = LLIR::var_types::LONG;
//     else if (val == "long long")
//         result = LLIR::var_types::LONGLONG;
    
//     if (is_unsigned)
//         result = static_cast<LLIR::var_types>(static_cast<int>(result) + 1); // result++
//     return { result };
//     throw Error("Undefined csupport type");
// }
LLIR::var_type LLIR::cllTreeTypeToIR(const TreeAPI::CllType &type) {
    if (type.type == "var")
        return {LLIR::var_types::ANY, {}};
    else if (type.type == "str")
        return {LLIR::var_types::STRING, {}};
    else if (type.type == "bool")
        return {LLIR::var_types::BOOLEAN, {}};
    else if (type.type == "num")
        return {LLIR::var_types::NUMBER, {}};
    else if (type.type == "arr") {
        LLIR::var_types tp = LLIR::var_types::ARRAY;
        LLIR::var_type _template = cllTreeTypeToIR(type.templ[0]);
        return {tp, {_template}};
    } else if (type.type == "obj") {        
        LLIR::var_types tp = LLIR::var_types::OBJECT;
        LLIR::var_type _template1 = cllTreeTypeToIR(type.templ[0]);
        LLIR::var_type _template2 = cllTreeTypeToIR(type.templ[1]);
        return {tp, {_template1, _template2}};
    }
    throw Error("Undefined type");
}
LLIR::var_assign_types LLIR::TreeOpToIR(const char op) {
    // all other is single character so can use switch
    switch (op) {
        case '+':
            return LLIR::var_assign_types::ADD;
        case '-':
            return LLIR::var_assign_types::SUBSTR;
        case '*':
            return LLIR::var_assign_types::MULTIPLY;
        case '/':
            return LLIR::var_assign_types::DIVIDE;
        case '%':
            return LLIR::var_assign_types::MODULO;
    }
    throw Error("Undefined operator");
}
LLIR::expr LLIR::TreeOpToExpr(const char op) {
    switch (op) {
        case '+':
            return {LLIR::condition_types::ADD};
        case '-':
            return {LLIR::condition_types::SUBSTR};
        case '*':
            return {LLIR::condition_types::MULTIPLY};
        case '/':
            return {LLIR::condition_types::DIVIDE};
        case '%':
            return {LLIR::condition_types::MODULO};
    }
    throw Error("Undefined operator");
}
LLIR::expr LLIR::TreeCompareOpToExpr(const TreeAPI::CllCompareOp &op) {
    if (op.op == "==")
        return {LLIR::condition_types::EQUAL};
    if (op.op == "!=")
        return {LLIR::condition_types::NOT_EQUAL};
    if (op.op == ">")
        return {LLIR::condition_types::HIGHER};
    if (op.op == "<")
        return {LLIR::condition_types::LOWER};
    if (op.op == ">=")
        return {LLIR::condition_types::HIGHER_OR_EQUAL};
    if (op.op == "<=")
        return {LLIR::condition_types::LOWER_OR_EQUAL};
    throw Error("undefined compare operator");
}
LLIR::expr LLIR::TreeLogicalOpToIR(const TreeAPI::CllLogicalOp &lop) {
    if (lop.isAnd)
        return {LLIR::condition_types::AND};
    return {LLIR::condition_types::OR};
}
LLIR::var_assign_types LLIR::TreeAssignmentOpToIR(const char op) {
    if (op == '\0')
        return LLIR::var_assign_types::ASSIGN;
    auto v = TreeOpToIR(op);
    v = static_cast<LLIR::var_assign_types>(static_cast<int>(v) + static_cast<int>(LLIR::var_assign_types::ASSIGN));
    return v;
}
std::vector<LLIR::expr> LLIR::TreeExprGroupToIR(const TreeAPI::CllExpr &group) {
    std::vector<LLIR::expr> expr;
    auto expression = TreeExprToIR(group);
    expr.push_back({LLIR::condition_types::GROUP_OPEN});
    expr.insert(expr.end(), expression.begin(), expression.end());
    expr.push_back({LLIR::condition_types::GROUP_CLOSE});
    return expr;
}
std::vector<LLIR::expr> LLIR::TreeExprValueToIR(const TreeAPI::CllExprValue &value) {
    std::vector<LLIR::expr> expr(1);
    if (value.isGroup()) {
        expr = TreeExprGroupToIR(value.getGroup());
    } else if (value.isMethodCall()) {
        expr.push_back({LLIR::condition_types::METHOD_CALL, TreeMethodCallToIR(value.getMethodCall())});
    } else if (value.isFunctionCall()) {
        expr.push_back({LLIR::condition_types::FUNCTION_CALL, TreeFunctionToIR(value.getFunctionCall())});
    } else if (value.isVariable()) {
        // todo
       // expr.push_back({LLIR::condition_types::VARIABLE, })
    } else if (value.isrvalue()) {
        expr.push_back({LLIR::condition_types::ANY_DATA, TreeRvalueToIR(value.getrvalue())});
    } else throw Error("Undefined expression");
    return expr;
}
std::vector<LLIR::expr> LLIR::TreeExprTermToIR(const TreeAPI::CllExprTerm &term) {
    // if (rule.name == Parser::Rules::cll_function_call)
    std::vector<LLIR::expr> cond;
    auto res = TreeExprValueToIR(term.value);
    cond.insert(cond.end(), res.begin(), res.end());
    for (int i = 0; i < term.rights.size(); i++) {
        cond.push_back(TreeOpToExpr(term.rights[i].first));
        res = TreeExprValueToIR(term.rights[i].second);
        cond.insert(cond.end(), res.begin(), res.end());
    }
    return cond;
}
std::vector<LLIR::expr> LLIR::TreeExprAdditionToIR(const TreeAPI::CllExprAddition &addition) {
    // if (rule.name == Parser::Rules::cll_function_call)
    std::vector<LLIR::expr> cond;
    auto res = TreeExprTermToIR(addition.value);
    cond.insert(cond.end(), res.begin(), res.end());
    for (int i = 0; i < addition.rights.size(); i++) {
        cond.push_back(TreeOpToExpr(addition.rights[i].first));
        res = TreeExprTermToIR(addition.rights[i].second);
        cond.insert(cond.end(), res.begin(), res.end());
    }
    return cond;
}
std::vector<LLIR::expr> LLIR::TreeExprCompareToIR(const TreeAPI::CllExprCompare &compare) {
    std::vector<LLIR::expr> cond;
    auto res = TreeExprAdditionToIR(compare.value);
    cond.insert(cond.end(), res.begin(), res.end());
    for (int i = 0; i < compare.rights.size(); i++) {
        cond.push_back(TreeCompareOpToExpr(compare.rights[i].first));
        res = TreeExprAdditionToIR(compare.rights[i].second);
        cond.insert(cond.end(), res.begin(), res.end());
    }
    return cond;
}
std::vector<LLIR::expr> LLIR::TreeExprLogicalToIR(const TreeAPI::CllExprLogical &logical) {
    std::vector<LLIR::expr> cond;
    auto res = TreeExprCompareToIR(logical.value);
    cond.insert(cond.end(), res.begin(), res.end());
    for (int i = 0; i < logical.rights.size(); i++) {
        cond.push_back(TreeLogicalOpToIR(logical.rights[i].first));
        res = TreeExprCompareToIR(logical.rights[i].second);
        cond.insert(cond.end(), res.begin(), res.end());
    }
    return cond;
}
std::vector<LLIR::expr> LLIR::TreeExprToIR(const TreeAPI::CllExpr &expr) {
    return TreeExprLogicalToIR(expr.value);
}

LLIR::var_type LLIR::deduceVarTypeByProd(const TreeAPI::RuleMember &mem) {
    LLIR::var_type type;
    if (mem.isGroup()) {
        for (auto i = 0; i < mem.getGroup().size(); i++) {
            if (deduceVarTypeByProd(mem.getGroup()[i]).type != LLIR::var_types::STRING)
                return {LLIR::var_types::UNDEFINED};
        }
        return {LLIR::var_types::STRING};
    }
    if (mem.isOp()) {
        LLIR::var_type type = {LLIR::var_types::UNDEFINED};
        
        for (auto el : mem.getOp()) {
            if (type.type == LLIR::var_types::UNDEFINED) {
                type = deduceVarTypeByProd(el);
            } else if (deduceVarTypeByProd(el).type != type.type) {
                return {LLIR::var_types::ANY};
            }
        }
        return type;
    }
    if (mem.isName()) {
        return corelib::text::isUpper(mem.getName().name.back()) ? LLIR::var_type {LLIR::var_types::Token} : LLIR::var_type {LLIR::var_types::Rule};
    }
    return {LLIR::var_types::STRING};
}
LLIR::var_type LLIR::deduceTypeFromRvalue(const TreeAPI::rvalue &value) {
    LLIR::var_type type = {LLIR::var_types::UNDEFINED};
    if (value.isString())
        type.type = LLIR::var_types::STRING;
    else if (value.isBoolean()) 
        type.type = LLIR::var_types::BOOLEAN;
    else if (value.isNumber())
        type.type = LLIR::var_types::NUMBER;
    else if (value.isID()) {
        // likely never execute
        auto find_it = std::find_if(vars.begin(), vars.end(), [&value](const LLIR::variable &var) { return var.name == value.getID(); });
        cpuf::printf("var name: %s\n", value.getID());
        if (find_it == vars.end())
            throw Error("Not found variable to deduce type from expr");
        return find_it->type;
    } else if (value.isAt()) {
        if (unnamed_datablock_units.empty())
            throw Error("no more data accamulated with @");
        return unnamed_datablock_units.front().type;
    } else if (value.isArray()) {
        LLIR::var_type types;
        for (const auto &el : value.getArray()) {
            if (types.type == LLIR::var_types::UNDEFINED) {
                types = deduceTypeFromExpr(el);
            } else {
                auto newType = deduceTypeFromExpr(el);
                if (newType.type != types.type || !compare_templ(newType.templ, types.templ)) {
                    type.type = LLIR::var_types::ANY;
                    break;
                }
            }
        }
        if (types.type != LLIR::var_types::ANY) {
            type.templ = {types};
            type.type = LLIR::var_types::ARRAY;
        }
    } else if (value.isObject()) {
        // todo: add handle key of different types (int or string)
        LLIR::var_type types;
        for (const auto &[key, value] : value.getObject()) {
            if (types.type == LLIR::var_types::UNDEFINED) {
                types = deduceTypeFromExpr(value);
            } else {
                auto newType = deduceTypeFromExpr(value);
                if (newType.type != types.type || !compare_templ(newType.templ, types.templ)) {
                    type.type = LLIR::var_types::ANY;
                    break;
                }
            }
        }
        if (types.type != LLIR::var_types::ANY) {
            type.templ = {types};
            type.type = LLIR::var_types::OBJECT;
        }
    } else {
        throw Error("Undefined rule");
    }
    return type;
}
LLIR::var_type LLIR::deduceTypeFromExprValue(const TreeAPI::CllExprValue &value) {
    if (value.isFunctionCall()) {
        // todo - get function call type
    } else if (value.isGroup()) {
        return deduceTypeFromExpr(value.getGroup());
    } else if (value.isMethodCall()) {
        // todo - get method call type
    } else if (value.isVariable()) {
        auto find_it = std::find_if(vars.begin(), vars.end(), [&value](const LLIR::variable &var) { return var.name == value.getVariable().name; });
        if (find_it == vars.end())
            throw Error("Not found variable to deduce type from expr");
        return find_it->type;
    } else if (value.isrvalue()) {
        return deduceTypeFromRvalue(value.getrvalue());
    } else
        throw Error("Undefined expr value member: %s in rule %s", value.value.type().name(), fullname);
    return {};
}
LLIR::var_type LLIR::deduceTypeFromExprTerm(const TreeAPI::CllExprTerm &term) {
    // type is explicitly based on value. We may not check others in addition
    return deduceTypeFromExprValue(term.value);
}
LLIR::var_type LLIR::deduceTypeFromExprAddition(const TreeAPI::CllExprAddition &addition) {
    // same as with term
    return deduceTypeFromExprTerm(addition.value);
}
LLIR::var_type LLIR::deduceTypeFromExprCompare(const TreeAPI::CllExprCompare &compare) {
    // if any comparasion exists it is boolean
    if (compare.rights.size() != 0)
        return {LLIR::var_types::BOOLEAN};
    return deduceTypeFromExprAddition(compare.value);
}
LLIR::var_type LLIR::deduceTypeFromExprLogical(const TreeAPI::CllExprLogical &logical) {
    // if &&/|| exists it is always boolean
    if (logical.rights.size() != 0)
        return {LLIR::var_types::BOOLEAN};
    return deduceTypeFromExprCompare(logical.value);
}
LLIR::var_type LLIR::deduceTypeFromExpr(const TreeAPI::CllExpr &expr) {
    return deduceTypeFromExprLogical(expr.value);
}
LLIR::ConvertionResult LLIR::processGroup(const TreeAPI::RuleMember &rule) {
    //cpuf::printf("group\n");
    // create variable with name of "var" or with auto-generated one
    auto var = createEmptyVariable(generateVariableName());
    auto uvar = !rule.prefix.empty() && !rule.prefix.is_key_value ? createEmptyVariable(rule.prefix.name) : createEmptyVariable("");
    auto svar = createSuccessVariable();
    auto prev_insideLoop = insideLoop;
    const auto &quantifier = rule.quantifier;
    if (quantifier == '*' || quantifier == '+')
        insideLoop = true;
    bool addSpaceSkipFirst;
    auto values = rulesToIr(rule.getGroup(), addSpaceSkipFirst);
    // remove previous space skip it there was \s0
    if (data.size() > 0 && !addSpaceSkipFirst) {
        // remove previous skip of spaces if it does exists
        for (auto rit = this->members.rbegin(); rit != this->members.rend(); rit++) {
            if (rit->type == LLIR::types::SKIP_SPACES) {
                this->members.erase(rit.base());
                break;
            }
        }
    }
    var.type = {deduceVarTypeByProd(rule)};
    if ((quantifier == '*' || quantifier == '+') && var.type.type != LLIR::var_types::UNDEFINED && var.type.type != LLIR::var_types::STRING) {
        var.type.templ = {{var.type.type}};
        var.type.type = LLIR::var_types::ARRAY;
    }
    std::vector<LLIR::member> var_members;
    auto switch_type = var.type.type == LLIR::var_types::ARRAY ? var.type.templ[0].type : var.type.type;
    switch (switch_type) {
        case LLIR::var_types::STRING:
            // it is a string so add all values
            for (auto node : values.success_vars) {
                if (node.var.name == "" && node.svar.name == "")
                    continue;
                var_members.push_back(
                    {
                        LLIR::types::ASSIGN_VARIABLE, 
                        LLIR::variable_assign {var.name, LLIR::var_assign_types::ADD, LLIR::assign { LLIR::var_assign_values::VARIABLE, node.var }}
                    }
                );
            }
            break;
        case LLIR::var_types::Token:
        case LLIR::var_types::Rule:
            // it is token so perform a single assign
            var_members.push_back( LLIR::member
                {
                    LLIR::types::ASSIGN_VARIABLE,
                    LLIR::variable_assign {var.name, LLIR::var_assign_types::ASSIGN, LLIR::assign { LLIR::var_assign_values::VARIABLE,  values.success_vars[0].var }}
                }
            );
            var.type = values.success_vars[0].var.type;
            if (var.type.type == LLIR::var_types::Rule_result)
                var.type.type = LLIR::var_types::Rule;
            else if (var.type.type == LLIR::var_types::Token_result)
                var.type.type = LLIR::var_types::Token;
            break;
    }
    std::string begin_var_name = "begin" + generateVariableName();
    std::vector<LLIR::expr> svar_expr = {};
    std::vector<std::string> used_vars;
    //cpuf::printf("success_vars.size(): %d\n", success_vars.size());
    if (!values.success_vars.empty()) {
        bool first = true;
        for (auto el : values.success_vars) {
            if (el.qualifier == '*' || el.qualifier == '?' || el.svar.name.empty())
                continue;
            if (!first)
                svar_expr.push_back({LLIR::condition_types::AND});
            used_vars.push_back(el.svar.name);
            svar_expr.push_back({LLIR::condition_types::VARIABLE, el.svar});
            first = false;
        }
    }
    // for (int i = 0; i < node_ret.size(); i++) {
    //     if (i != 0)
    //         svar_expr.push_back({IR::condition_types::AND});
    //     svar_expr.push_back({IR::condition_types::VARIABLE, node_ret[i].svar});
    // }

    if (!values.members.empty() && values.members.back().type == LLIR::types::SKIP_SPACES) {
        values.pop();
    }
    values.add(var_members);
    auto shadow_var = values.affectIrByQuantifier(rule, var, quantifier);
    for (const auto &svar : used_vars) {
        raiseVarsTop(values.members, values.members, svar, true, false, true);
    }
    std::vector<LLIR::member> svar_cond;
    if (svar_expr.empty()) {
        svar_cond = {
            {LLIR::types::ASSIGN_VARIABLE, LLIR::variable_assign {svar.name, LLIR::var_assign_types::ASSIGN, LLIR::var_assign_values::True}},
            !uvar.name.empty() ? 
                LLIR::member {LLIR::types::ASSIGN_VARIABLE, LLIR::variable_assign {svar.name, LLIR::var_assign_types::ASSIGN, LLIR::var_assign_values::True}}
            :
                LLIR::member {LLIR::types::EMPTY},
            {LLIR::types::POP_POS_COUNTER}
        };
    } else {
        svar_cond = {{
            LLIR::types::IF,
            LLIR::condition {
                svar_expr,
                {
                    {LLIR::types::ASSIGN_VARIABLE, LLIR::variable_assign {svar.name, LLIR::var_assign_types::ASSIGN, LLIR::var_assign_values::True}},
                    !uvar.name.empty() ? 
                        LLIR::member {LLIR::types::ASSIGN_VARIABLE, LLIR::variable_assign {uvar.name, LLIR::var_assign_types::ASSIGN, {LLIR::var_assign_values::VARIABLE, shadow_var.name.empty() ? var : shadow_var}}}
                    :
                        LLIR::member {LLIR::types::EMPTY},
                    {LLIR::types::POP_POS_COUNTER}
                }
            }
        }};
    }
    if (var.type.type != LLIR::var_types::UNDEFINED) {
        push({LLIR::types::VARIABLE, var});
    }
    if (!uvar.name.empty()) {
        uvar.type = shadow_var.name.empty() ? var.type : shadow_var.type;
        push({LLIR::types::VARIABLE, uvar});
    }
    update(values);
    insideLoop = prev_insideLoop;
    push({LLIR::types::VARIABLE, svar});
    push({LLIR::types::PUSH_POS_COUNTER, begin_var_name});
    // maybe implemente later
    // if (!variable.empty() && variable.name == Parser::Rules::method_call) 
    // {
    //     LLIR::method_call method_call = TreeMethodCallToIR(std::any_cast<Parser::Rule>(variable.data));
    //     add(values);
    //     push({LLIR::types::METHOD_CALL, method_call});
    // } else {
        add(values);
    // }
    add(svar_cond);
    if (uvar.type.type == LLIR::var_types::UNDEFINED)
        return LLIR::ConvertionResult {svar, {}, var, shadow_var, quantifier};
    return LLIR::ConvertionResult {svar, uvar, var, shadow_var, quantifier};
}
LLIR::ConvertionResult LLIR::processRuleCsequence(const TreeAPI::RuleMember &rule) {
    //cpuf::printf("csequence\n");
    const auto &csequence = rule.getCsequence();

    auto var = rule.prefix.empty() && !rule.prefix.is_key_value? createEmptyVariable(generateVariableName()) : createEmptyVariable(rule.prefix.name);
    auto svar = createSuccessVariable();
    var.type = {LLIR::var_types::STRING};
    std::vector<LLIR::expr> expr;

    if (csequence.negative) {
        expr = {
            {LLIR::condition_types::NOT},
            {LLIR::condition_types::GROUP_OPEN}
        };
    }

    bool first = true;
    for (const auto c : csequence.characters) {
        if (!first)
            expr.push_back({LLIR::condition_types::OR});
        expr.insert(expr.end(), {
            {LLIR::condition_types::CURRENT_CHARACTER},
            {LLIR::condition_types::EQUAL},
            {LLIR::condition_types::CHARACTER, c}
        });
        first = false;
    }
    for (const auto c : csequence.escaped) {
        if (!first)
            expr.push_back({LLIR::condition_types::OR});
        expr.insert(expr.end(), {
            {LLIR::condition_types::CURRENT_CHARACTER},
            {LLIR::condition_types::EQUAL},
            {LLIR::condition_types::CHARACTER, getEscapedChar(c)}
        });
        first = false;
    }
    for (const auto &[from, to] : csequence.diapasons) {
        if (!first)
            expr.push_back({LLIR::condition_types::OR});
        expr.insert(expr.end(), {
            {LLIR::condition_types::GROUP_OPEN},
            {LLIR::condition_types::CURRENT_CHARACTER},
            {LLIR::condition_types::HIGHER_OR_EQUAL},
            {LLIR::condition_types::CHARACTER, from},
            {LLIR::condition_types::AND},
            {LLIR::condition_types::CURRENT_CHARACTER},
            {LLIR::condition_types::LOWER_OR_EQUAL},
            {LLIR::condition_types::CHARACTER, to},
            {LLIR::condition_types::GROUP_CLOSE}
        });
        first = false;
    }
    if (csequence.negative) {
        if (rule.quantifier == '+' || rule.quantifier == '*')
            expr.insert(expr.end(), {
                {LLIR::condition_types::AND}, {LLIR::condition_types::CURRENT_CHARACTER}, {LLIR::condition_types::NOT_EQUAL}, {LLIR::condition_types::CHARACTER, '\0'}, 
            });
        expr.push_back({LLIR::condition_types::GROUP_CLOSE});
    }
    push({LLIR::types::VARIABLE, var});
    push({LLIR::types::VARIABLE, svar});
    std::vector<LLIR::member> block = createDefaultBlock(var, svar);
    auto shadow_var = pushBasedOnQualifier(rule, expr, block, var, svar, rule.quantifier, false);
    return {svar, shadow_var.name.empty() ? (var.name.empty() ? LLIR::variable {} : var) : shadow_var, var, shadow_var, rule.quantifier};
}
LLIR::ConvertionResult LLIR::processString(const TreeAPI::RuleMember &rule) {
    //cpuf::printf("string, data: %s\n", std::any_cast<std::string>(rule.data));
    const auto &str = rule.getString().value;
    auto var = rule.prefix.empty() && !rule.prefix.is_key_value ? createEmptyVariable(generateVariableName()) : createEmptyVariable(rule.prefix.name);
    auto svar = createSuccessVariable();
    var.type = {LLIR::var_types::STRING};
    std::vector<LLIR::expr> expr;
    if (str.size() == 0)
        return {};
    if (str.size() == 1) {
        // micro optimization - compare as single character for single character strings
        expr = {
            {LLIR::condition_types::CURRENT_CHARACTER},
            {LLIR::condition_types::EQUAL},
            {LLIR::condition_types::CHARACTER, str[0]}
        };
    } else {
        expr = {
            {LLIR::condition_types::STRNCMP, LLIR::strncmp{true, str}}
        };
    }

    std::vector<LLIR::member> block = createDefaultBlock(var, svar);
    push({LLIR::types::VARIABLE, var});
    push({LLIR::types::VARIABLE, svar});
    auto shadow_var = pushBasedOnQualifier(rule, expr, block, var, svar, rule.quantifier, false);
    return {svar, shadow_var.name.empty() ? (var.name.empty() ? LLIR::variable {} : var) : shadow_var, var, shadow_var, rule.quantifier};
}
LLIR::ConvertionResult LLIR::process_Rule_hex(const TreeAPI::RuleMember &rule) {
    //cpuf::printf("hex\n");
    auto data = rule.getHex().hex_chars;
    std::vector<LLIR::expr> expr = {};
    auto var = rule.prefix.empty() && !rule.prefix.is_key_value ? createEmptyVariable(generateVariableName()) : createEmptyVariable(rule.prefix.name);
    auto svar = createSuccessVariable();
    var.type = {LLIR::var_types::STRING};
    std::vector<LLIR::member> block = createDefaultBlock(var, svar);
    bool is_first = true, is_negative = false;
    if (rule.quantifier == '\0') {
        expr.push_back({LLIR::condition_types::NOT});
        expr.push_back({LLIR::condition_types::GROUP_OPEN});
        is_negative = true;
    }
    if (data.size() % 2 != 0)
        data.insert(data.begin(), '0');
    for (int i = 0; i < data.size(); i += 2) {
        std::string hex(data.data() + i, 2);
        if (!is_first)
            expr.push_back({LLIR::condition_types::AND});
        is_first = false;
        expr.push_back({LLIR::condition_types::CURRENT_CHARACTER});
        expr.push_back({LLIR::condition_types::EQUAL});
        expr.push_back({LLIR::condition_types::HEX, hex});
    }
    if (is_negative) {
        expr.push_back({LLIR::condition_types::GROUP_CLOSE});
    }
    //cpuf::printf("hex_open\n");
    push({LLIR::types::VARIABLE, var});
    push({LLIR::types::VARIABLE, svar});
    auto shadow_var = pushBasedOnQualifier(rule, expr, block, var, svar, rule.quantifier, false);
    return {svar, shadow_var.name.empty() ? (var.name.empty() ? LLIR::variable {} : var) : shadow_var, var, shadow_var, rule.quantifier};
}
LLIR::ConvertionResult LLIR::process_Rule_bin(const TreeAPI::RuleMember &rule) {
    //cpuf::printf("hex\n");
    auto data = rule.getBin().bin_chars;
    std::vector<LLIR::expr> expr = {};
    auto var = rule.prefix.empty() && !rule.prefix.is_key_value ? createEmptyVariable(generateVariableName()) : createEmptyVariable(rule.prefix.name);
    auto svar = createSuccessVariable();
    std::vector<LLIR::member> block = {
        {LLIR::types::ASSIGN_VARIABLE, LLIR::variable_assign {var.name, LLIR::var_assign_types::ADD, LLIR::var_assign_values::CURRENT_POS_SEQUENCE}},
        {LLIR::types::INCREASE_POS_COUNTER},
    };
    bool is_first = true, is_negative = false;
    if (rule.quantifier == '\0') {
        expr.push_back({LLIR::condition_types::NOT});
        expr.push_back({LLIR::condition_types::GROUP_OPEN});
        is_negative = true;
    }
    while (data.size() % 8 != 0)
        data.insert(data.begin(), '0');
    for (int i = 0; i < data.size(); i += 8) {
        std::string bin(data.data() + i, 8);
        auto as_hex = hex::from_binary(bin);
        as_hex.erase(as_hex.begin(), as_hex.begin() + 2);
        if (!is_first)
            expr.push_back({LLIR::condition_types::AND});
        is_first = false;
        expr.push_back({LLIR::condition_types::CURRENT_CHARACTER});
        expr.push_back({LLIR::condition_types::EQUAL});
        expr.push_back({LLIR::condition_types::HEX, as_hex});
    }
    if (is_negative) {
        expr.push_back({LLIR::condition_types::GROUP_CLOSE});
    }
    push({LLIR::types::VARIABLE, var});
    push({LLIR::types::VARIABLE, svar});
    auto shadow_var = pushBasedOnQualifier(rule, expr, block, var, svar, rule.quantifier, false);
    return {svar, shadow_var.name.empty() ? (var.name.empty() ? LLIR::variable {} : var) : shadow_var, var, shadow_var, rule.quantifier};
}
LLIR::ConvertionResult LLIR::process_Rule_name(const TreeAPI::RuleMember &rule) {
    //cpuf::printf("Rule_other");
    auto name = rule.getName().name;
    //cpuf::printf(", name: %s\n", name_str);

    auto var = rule.prefix.empty() && !rule.prefix.is_key_value ? createEmptyVariable(generateVariableName()) : createEmptyVariable(rule.prefix.name);
    auto svar = createSuccessVariable();
    LLIR::variable shadow_var;
    bool isCallingToken = corelib::text::isUpper(name.back());
    if (!isToken && isCallingToken) {
        var.type.type = LLIR::var_types::Token;
    } else {
        var.type = isCallingToken ? LLIR::var_type {LLIR::var_types::Token_result} : LLIR::var_type {LLIR::var_types::Rule_result};
    }
    auto block = createDefaultBlock(var, svar);
    push({LLIR::types::VARIABLE, var});
    push({LLIR::types::VARIABLE, svar});
    if (isToken) {
        // if (!isCallingToken)
        //     throw Error("Cannot call rule from token");
        // remove variable assignemnt
        block.back().type = LLIR::types::INCREASE_POS_COUNTER_BY_TOKEN_LENGTH;
        block.back().value = var.name;
        var.property_access = {"node"};
        block.erase(block.begin());
        std::vector<LLIR::expr> expr;
        auto call = createDefaultCall(block, var, corelib::text::join(name, "_"), expr);
        push(call);
        shadow_var = pushBasedOnQualifier_Rule_name(rule, expr, block, var, svar, call, rule.quantifier);

    } else {
        if (isCallingToken) {
            block[0] = {
                LLIR::types::ASSIGN_VARIABLE, 
                LLIR::variable_assign {
                    var.name,
                    LLIR::var_assign_types::ASSIGN,
                    LLIR::var_assign_values::CURRENT_TOKEN
                }
            };
            std::vector<LLIR::expr> expr = {
                {LLIR::condition_types::CURRENT_TOKEN, LLIR::current_token {LLIR::condition_types::EQUAL, corelib::text::join(name, "_")}},
            };
            shadow_var = pushBasedOnQualifier(rule, expr, block, var, svar, rule.quantifier);
        } else {
            block.back().type = LLIR::types::INCREASE_POS_COUNTER_BY_TOKEN_LENGTH;
            block.back().value = var.name;
            var.property_access = {"node"};
            block.erase(block.begin()); // remove variable assignment
            std::vector<LLIR::expr> expr;
            auto call = createDefaultCall(block, var, corelib::text::join(name, "_"), expr);
            push(call);
            shadow_var = pushBasedOnQualifier_Rule_name(rule, expr, block, var, svar, call, rule.quantifier);

        }

    }
    return {svar, shadow_var.name.empty() ? (var.name.empty() ? LLIR::variable {} : var) : shadow_var, var, shadow_var, rule.quantifier};
}
LLIR::ConvertionResult LLIR::process_Rule_nospace(const TreeAPI::RuleMember &rule) {
    addSpaceSkip = false;
    if (members.size() > 0) {
        // remove previous skip of spaces if it does exists
        for (auto rit = this->members.rbegin(); rit != this->members.rend(); rit++) {
            if (rit->type == LLIR::types::SKIP_SPACES) {
                this->members.erase(rit.base());
                break;
            }
        }
    }
    return {};
}
LLIR::ConvertionResult LLIR::process_Rule_escaped(const TreeAPI::RuleMember &rule) {
    //cpuf::printf("Rule_escaped\n");
    const auto &escaped_c = rule.getEscaped();

    std::vector<LLIR::expr> expression;
    switch (escaped_c) {
        case 's':
            // do not add skip of spaces
            addSpaceSkip = false;
            if (data.size() > 0) {
                // remove previous skip of spaces if it does exists
                for (auto rit = this->members.rbegin(); rit != this->members.rend(); rit++) {
                    if (rit->type == LLIR::types::SKIP_SPACES) {
                        this->members.erase(rit.base());
                        break;
                    }
                }
            }
            //cpuf::printf("ON_EXPRESSION\n");
            expression = {
                {LLIR::condition_types::CURRENT_CHARACTER},
                {LLIR::condition_types::NOT_EQUAL},
                {LLIR::condition_types::CHARACTER, ' '}
            };
            break;
        default:
            throw Error("Undefined char '%c'", escaped_c);
            
    }
    //cpuf::printf("escaped_open\n");

    auto var = rule.prefix.empty() && !rule.prefix.is_key_value ? createEmptyVariable(generateVariableName()) : createEmptyVariable(rule.prefix.name);
    auto svar = createSuccessVariable();
    var.type = {LLIR::var_types::STRING};
    std::vector<LLIR::member> block = {{LLIR::types::EXIT}};
    if (!isFirst) {
        block.insert(block.begin(), {LLIR::types::ERR, getErrorName(rule)});
    }
    auto block_after = createDefaultBlock(var, svar);
    push({LLIR::types::VARIABLE, var});
    push({LLIR::types::VARIABLE, svar});
    auto shadow_var = pushBasedOnQualifier(rule, expression, block, var, svar, rule.quantifier);
    push({LLIR::types::IF, LLIR::condition{expression, block}});
    add(block_after);
    //cpuf::printf("escaped_close\n");
    return {svar, shadow_var.name.empty() ? (var.name.empty() ? LLIR::variable {} : var) : shadow_var, var, shadow_var, rule.quantifier};
}
LLIR::ConvertionResult LLIR::process_Rule_any(const TreeAPI::RulePrefix &prefix) {
    //cpuf::printf("Rule_any\n");
    auto var = prefix.empty() && !prefix.is_key_value ? createEmptyVariable(generateVariableName()) : createEmptyVariable(prefix.name);
    auto svar = createSuccessVariable();
    var.type = {LLIR::var_types::STRING};
    std::vector<LLIR::expr> expression;
    std::vector<LLIR::member> block = {{LLIR::types::EXIT}};
    if (!isFirst) {
        auto rm = TreeAPI::RuleMember {.value = TreeAPI::RuleMemberAny() };
        block.insert(block.begin(), LLIR::member {LLIR::types::ERR, getErrorName(rm)});
    }
    std::vector<LLIR::member> block_after = createDefaultBlock(var, svar);
    expression = {
        {LLIR::condition_types::CURRENT_CHARACTER},
        {LLIR::condition_types::EQUAL},
        {LLIR::condition_types::CHARACTER, '\0'}
    };
    push({LLIR::types::VARIABLE, var});
    push({LLIR::types::VARIABLE, svar});
    push({LLIR::types::IF, LLIR::condition{expression, block}});
    add(block_after);
    return {svar, var};
}
std::vector<LLIR::member> LLIR::convert_op_rule(const std::vector<TreeAPI::RuleMember> &rules, size_t index, LLIR::variable &var, LLIR::variable &svar) {
    //[[assume(rules.size() >= 2)]];
    if (index >= rules.size()) {
        return {{LLIR::types::EXIT}};
    }

    LLIR::ConvertionResult success_var;
    std::vector<std::vector<LLIR::member>> blocks;
    std::vector<std::vector<LLIR::expr>> conditions;
    auto rule = rules[index++];
    LLIR new_ir(tree);
    new_ir.proceed(*this);

    if (rule.isGroup()) {
        char new_qualifier;
        if (rule.quantifier == '+')
            new_qualifier = '*';
        else if (rule.quantifier == '\0')
            new_qualifier = '?';
        auto prev_quantifier = rule.quantifier;
        rule.quantifier = new_qualifier;
        new_ir.ruleToIr(rule);
        rule.quantifier = prev_quantifier;
    }
    else {
        new_ir.ruleToIr(rule);
    }    
    variable_count = new_ir.variable_count;
    vars = new_ir.vars;
    unnamed_datablock_units = new_ir.unnamed_datablock_units;
    key_vars = new_ir.key_vars;
    success_var = new_ir.success_vars[0];
    std::vector<int> erase_indices;
    std::vector<int> push_indices;
    if (rule.isGroup()) {
        new_ir.members.back().type = LLIR::types::RESET_POS_COUNTER; // remove space skip
        auto cond = LLIR::condition {
            std::vector<LLIR::expr> {
                {LLIR::condition_types::NOT}, {LLIR::condition_types::VARIABLE, success_var.svar}
            },
            convert_op_rule(rules, index, var, svar),
        };
        auto v = !success_var.shadow_var.name.empty() && var.type.type != LLIR::var_types::STRING ? success_var.shadow_var : success_var.var;
        auto assign_type = v.type.type == LLIR::var_types::STRING ? LLIR::var_assign_types::ADD : LLIR::var_assign_types::ASSIGN;
        if (!v.name.empty()) {
            cond.else_block = {{
                LLIR::types::ASSIGN_VARIABLE,
                LLIR::variable_assign 
                {
                    var.name,
                    LLIR::var_assign_types::ASSIGN,
                    LLIR::assign {
                        LLIR::var_assign_values::VARIABLE,
                        v
                    }
                }
            }};
        } 
        new_ir.push({LLIR::types::IF, cond});
    } else {
        replaceToPrevChar(new_ir.members, 0);
        for (int i = 0; i < new_ir.members.size(); i++) {
            auto &el = new_ir.members[i];
            if (el.type == LLIR::types::IF) {
                auto val = std::any_cast<LLIR::condition>(el.value);
                // get recursively nested block
                val.block = convert_op_rule(rules, index, var, svar);
                // change condition and remove it's content into else blocks
                for (int j = i + 1; j < new_ir.members.size(); j++) {
                    auto el = new_ir.members[j];
                    erase_indices.push_back(j);
                    if (el.type != LLIR::types::SKIP_SPACES) {
                        if (el.type == LLIR::types::ASSIGN_VARIABLE) {
                            auto assignment = std::any_cast<LLIR::variable_assign>(el.value);
                            assignment.assign_type = LLIR::var_assign_types::ASSIGN;
                            el.value = assignment;
                        }
                        val.else_block.push_back(el);
                    }
                }
                // push into else block an assignment to variable
                if (var.type.type == LLIR::var_types::ARRAY) {
                    val.else_block.push_back({LLIR::types::METHOD_CALL, LLIR::method_call { var.name, {LLIR::function_call {"push", {std::vector<std::vector<LLIR::expr>> {{LLIR::expr {LLIR::condition_types::VARIABLE, success_var.var}}}}}}}});
                } else {
                    auto v = !success_var.shadow_var.name.empty() && var.type.type != LLIR::var_types::STRING ? success_var.shadow_var : success_var.var;
                    auto assign_type = v.type.type == LLIR::var_types::STRING ? LLIR::var_assign_types::ADD : LLIR::var_assign_types::ASSIGN;
                    val.else_block.push_back({
                        LLIR::types::ASSIGN_VARIABLE,
                        LLIR::variable_assign 
                        {
                            var.name,
                            LLIR::var_assign_types::ASSIGN,
                            LLIR::assign {
                                LLIR::var_assign_values::VARIABLE,
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
    for (auto it = erase_indices.rbegin(); it != erase_indices.rend(); ++it) {
        new_ir.members.erase(new_ir.members.begin() + *it);
    }
    return new_ir.members;
}

LLIR::ConvertionResult LLIR::process_Rule_op(const TreeAPI::RuleMember &rule) {
    // cpuf::printf("Rule_op\n");
    auto &rules = rule.getOp();
    auto var = rule.prefix.empty() && !rule.prefix.is_key_value ? createEmptyVariable(generateVariableName()) : createEmptyVariable(rule.prefix.name);
    auto svar = createSuccessVariable();
    auto block = createDefaultBlock(var, svar);
    // Add success variable
    var.type = {deduceVarTypeByProd(rule)};
    if (insideLoop && var.type.type != LLIR::var_types::STRING) {
        var.type.templ = {{var.type.type}};
        var.type.type = LLIR::var_types::ARRAY;
    }
    push({LLIR::types::VARIABLE, var});
    push({LLIR::types::VARIABLE, svar});
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
    const auto res = convert_op_rule(rules, 0, var, svar);
    add(res);
    block.erase(block.begin()); // remove variable assignment (it is done in else blocks)
    block.erase(block.end() - 1);
    // Append default block
    add(block);
    return {svar, var, var, {}, rule.quantifier};
}
void LLIR::process_cll_var(const TreeAPI::CllVar &var) {
    // get data section
    LLIR::var_type ir_type;
    LLIR::var_assign_types assign_types;
    LLIR::assign assign;
    if (!var.type.type.empty())
        ir_type = cllTreeTypeToIR(var.type);
    if (var.op != '\0') {
        assign_types = TreeOpToIR(var.op);
        assign = {LLIR::var_assign_values::EXPR, TreeExprToIR(var.value)};
    }
    if (!var.type.type.empty()) {
        LLIR::variable v = {var.name, ir_type, assign};
        push({LLIR::types::VARIABLE, v});
        vars.push_back(v);
    } else {
        push({LLIR::types::ASSIGN_VARIABLE, LLIR::variable_assign {var.name, assign_types, assign}});
    }
}
LLIR::condition LLIR::process_cll_if(const TreeAPI::CllIf &cond) {
    auto block_ir = rulesToIr(cond.stmt);
    variable_count = block_ir.variable_count;
    LLIR::condition condition;
    condition.expression = TreeExprToIR(cond.expr);
    condition.block.assign(block_ir.members.begin(), block_ir.members.end());
    return condition;
}
LLIR::ConvertionResult LLIR::process_cll(const TreeAPI::Cll &cll) {
    addSpaceSkip = false;
    LLIR::condition cond;
    if (cll.isVar()) {
        process_cll_var(cll.getVar());
    } else if (cll.isIf()) {
        process_cll_if(cll.getIf());
    } else if (cll.isExpr()) {
        // ignore right now, has no side effects
    } else throw Error("Undefined cll entry");
    return {{}, {}};
}

void LLIR::ruleToIr(const TreeAPI::RuleMember &rule) {
    addSpaceSkip = true;
    LLIR::ConvertionResult success_var;
    if (rule.isGroup()) {
        success_var = processGroup(rule);
    } else if (rule.isCsequence()) {
        success_var = processRuleCsequence(rule);
    } else if (rule.isString()) {
        success_var = processString(rule);
    } else if (rule.isHex()) {
        success_var = process_Rule_hex(rule);
    } else if (rule.isBin()) {
        success_var = process_Rule_bin(rule);
    } else if (rule.isName()) {
        success_var = process_Rule_name(rule);
    } else if (rule.isEscaped()) {
        success_var = process_Rule_escaped(rule);
    } else if (rule.isNospace()) {
        success_var = process_Rule_nospace(rule);
    } else if (rule.isOp()) {
        success_var = process_Rule_op(rule);
    } else if (rule.isAny()) {
        success_var = process_Rule_any(rule.prefix);
    } else if (rule.isCll()) {
        success_var = process_cll(rule.getCll());
    } else throw Error("Undefined rule");
    if (rule.prefix.is_key_value) {
        if (rule.prefix.name.empty()) {
            unnamed_datablock_units.push_back(success_var.uvar);
        } else {
            key_vars.push_back(std::make_pair(rule.prefix.name, success_var.uvar));
        }
    }
    const auto insert_var = [this](const LLIR::variable &var) {
        if (!var.name.empty())
            vars.push_back(var);
    };
    insert_var(success_var.uvar);
    insert_var(success_var.svar);
    insert_var(success_var.var);
    insert_var(success_var.shadow_var);
    isFirst = false;
    if (addSpaceSkip)
        push({LLIR::types::SKIP_SPACES, isToken});
    success_vars.push_back(success_var);
}
LLIR LLIR::rulesToIr(const std::vector<TreeAPI::RuleMember> &rules) {
    LLIR result(tree, -1, false);
    result.proceed(*this);
    for (const auto &rule : rules) {
        result.ruleToIr(rule);
    }
    return result;
}
LLIR LLIR::rulesToIr(const std::vector<TreeAPI::RuleMember> &rules, bool &addSpaceSkipFirst) {
    LLIR result(tree, -1, false);
    result.proceed(*this);
    bool isFirst = true;
    for (const auto &rule : rules) {
        result.ruleToIr(rule);
        if (isFirst)
            addSpaceSkipFirst = result.addSpaceSkip;
        isFirst = false;
    }
    return result;
}
void LLIR::treeToIr() {
    for (auto &[name, value] : tree->getRawAst().getTreeMap()) {
        bool isToken = corelib::text::isUpper(name.back());
        fullname = name;
        bool to_add = true;
        if (tokensOnly != -1 && ((isToken && !tokensOnly) || (!isToken && tokensOnly))) {
            to_add = false;
        }
        this->isToken = isToken;
        cpuf::printf("rule: %s\n", fullname);
        if (to_add) {
            auto values = rulesToIr(value.members);
            if (!values.members.empty() && values.members.back().type == LLIR::types::SKIP_SPACES)
                values.pop(); // remove skip of spaces at the end
            data.push_back({values.createDataBlock(value.data_block), fullname, values.members});
        }
        clear_thread();
    }
}
LLIR::inclosed_map LLIR::getInclosedMapFromKeyValueBinding() {
    inclosed_map map;
    for (const auto &[name, variable] : key_vars) {
        map.try_emplace(name, std::vector<LLIR::expr> {LLIR::expr {LLIR::condition_types::VARIABLE, variable}}, variable.type);
    }
    return map;
}
LLIR::DataBlock LLIR::createDataBlock(const TreeAPI::DataBlock &data_block) {
    LLIR::DataBlock block;
    if (data_block.empty())
        return block;
    if (data_block.isRegularDataBlock()) {
        if (data_block.isWithKeys()) {
            LLIR::inclosed_map initial_map = getInclosedMapFromKeyValueBinding();
            const auto &key_based_data_block = data_block.getRegDataBlockWKeys();
            for (const auto &[name, expr] : key_based_data_block.value) {
                initial_map[name] = std::make_pair(TreeExprToIR(expr), deduceTypeFromExpr(expr));
            }
            block.value = initial_map;
        } else {
            Assert(key_vars.empty(), "Key variable in expression-only data block");
            cpuf::printf("unnamed size: %$\n", unnamed_datablock_units.size());
            const auto type = deduceTypeFromExpr(data_block.getRegDataBlock());
            block.value = std::make_pair(TreeExprToIR(data_block.getRegDataBlock()), type);
        }
    } else {
        // templated data block
        LLIR::inclosed_map initial_map = getInclosedMapFromKeyValueBinding();
        const auto &templated_datablock = data_block.getTemplatedDataBlock();
        cpuf::printf("Keys size: %$, values size: %$\n", unnamed_datablock_units.size(), templated_datablock.names.size());
        for (const auto &name : templated_datablock.names) {
            Assert(!unnamed_datablock_units.empty(), "More keys than values");
            initial_map[name] = std::make_pair(std::vector<LLIR::expr> {LLIR::expr {condition_types::VARIABLE, unnamed_datablock_units.front()}}, unnamed_datablock_units.front().type);
            unnamed_datablock_units.erase(unnamed_datablock_units.begin());
        }
    }
    return block;
}