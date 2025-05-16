#include "LLIR_old.h"

#include <chrono>
#include <corelib.h>
#include <cpuf/hex.h>
#include <tree.h>
#include <sys/stat.h>

#include "ErrorIR.h"

bool LLIR_old::DataBlock::is_inclosed_map() const {
    return std::holds_alternative<LLIR_old::inclosed_map>(value);
}
bool LLIR_old::DataBlock::is_raw_expr() const {
    return std::holds_alternative<LLIR_old::regular_data_block>(value);
}
bool LLIR_old::DataBlock::empty() const {
    return std::holds_alternative<std::monostate>(value);
}

LLIR_old::regular_data_block &LLIR_old::DataBlock::getRegularDataBlock() {
    return std::get<LLIR_old::regular_data_block>(value);
};
LLIR_old::inclosed_map &LLIR_old::DataBlock::getInclosedMap() {
    return std::get<LLIR_old::inclosed_map>(value);
};
const LLIR_old::regular_data_block &LLIR_old::DataBlock::getRegularDataBlock() const {
    return std::get<LLIR_old::regular_data_block>(value);
};
const LLIR_old::inclosed_map &LLIR_old::DataBlock::getInclosedMap() const {
    return std::get<LLIR_old::inclosed_map>(value);
};
// a structure used to cout
void LLIR_old::add(LLIR_old &repr) {
    members.insert(members.end(), repr.members.begin(), repr.members.end());
}
void LLIR_old::add(std::vector<LLIR_old::member> repr) {
    members.insert(members.end(), repr.begin(), repr.end());
}
void LLIR_old::push(LLIR_old::member member) {
    members.push_back(member);
}
void LLIR_old::pop() {
    members.pop_back();
};
void LLIR_old::push_begin(LLIR_old::member member) {
    members.insert(members.begin(), member);
}
void LLIR_old::pop_begin() {
    members.erase(members.begin());
};
size_t LLIR_old::size() {
    return members.size();
}
bool LLIR_old::empty() {
    return members.empty();
}
auto LLIR_old::getSuccessVars() const -> const std::vector<ConvertionResult>& {
    return success_vars;
}
std::vector<LLIR_old::Data> LLIR_old::getData() const {
    return data;
}
std::vector<LLIR_old::Data> &LLIR_old::getData() {
    return data;
}
const std::vector<LLIR_old::member> &LLIR_old::getMembers() const {
    return members;
}
std::vector<std::string> LLIR_old::getFullName() const {
    return fullname;
}
const Tree* LLIR_old::getTree() const {
    return tree;
}
void LLIR_old::erase_begin() {
    data.erase(data.begin());
}
void LLIR_old::clear_thread() {
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
void LLIR_old::proceed(const LLIR_old &ir) {
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
    symbol_follow = ir.symbol_follow;
}
void LLIR_old::update(LLIR_old &ir) {
    variable_count = ir.variable_count;
    insideLoop = ir.insideLoop;
    addSpaceSkip = ir.addSpaceSkip;
    vars = ir.vars;
    key_vars = ir.key_vars;
    unnamed_datablock_units = ir.unnamed_datablock_units;
}
LLIR_old::DataBlockList LLIR_old::getDataBlocks(bool isToken) {
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
LLIR_old::DataBlockList LLIR_old::getDataBlocksTerminals() {
    return getDataBlocks(true);
}
LLIR_old::DataBlockList LLIR_old::getDataBlocksNonTerminals() {
    return getDataBlocks(false);
}
LLIR_old::variable LLIR_old::createEmptyVariable(std::string name) {
    LLIR_old::variable var {
        name,
        {LLIR_old::var_types::UNDEFINED},
        LLIR_old::var_assign_values::NONE,
    };
    return var;
}
std::string LLIR_old::generateVariableName() {
    return std::string("_") + std::to_string(variable_count++);
}
auto LLIR_old::getNextTerminal(std::vector<TreeAPI::RuleMember> symbols, size_t pos) -> std::set<std::vector<std::string>> {
    std::set<std::vector<std::string>> terminals;
    for (size_t i = pos; i < symbols.size(); i++) {
        const auto &sym = symbols[i];
        if (!sym.isName())
            continue;
        const auto n = sym.getName();
        if (corelib::text::isUpper(n.name.back())) {
            terminals.insert(n.name);
        } else {
            auto &terms = tree->getFirstSet()[n.name];
            terminals.insert(terms.begin(), terms.end());
        }
        if (sym.quantifier == '?' || sym.quantifier == '*')
            continue;
        break;
    }
    return terminals;
}
void LLIR_old::processExitStatements(std::vector<LLIR_old::member> &values) {
    for (auto &el : values) {
        if (el.type == LLIR_old::types::IF || el.type == LLIR_old::types::WHILE || el.type == LLIR_old::types::DOWHILE) {
            auto &condition = std::any_cast<LLIR_old::condition&>(el.value); // Avoid unnecessary copies

            // Process the block and else block of the condition recursively
            processExitStatements(condition.block);
            processExitStatements(condition.else_block);

            // Ensure that any EXIT statements within the blocks are replaced with BREAK_LOOP
            for (auto &unit : condition.block) {
                if (unit.type == LLIR_old::types::EXIT) {
                    unit.type = LLIR_old::types::BREAK_LOOP; // Replacing EXIT with BREAK_LOOP
                } else if (unit.type == LLIR_old::types::IF || unit.type == LLIR_old::types::WHILE || unit.type == LLIR_old::types::DOWHILE) {
                    auto &cond = std::any_cast<LLIR_old::condition&>(unit.value);

                    processExitStatements(cond.block); // Recursive call on nested blocks
                    processExitStatements(cond.else_block); // Recursive call on else blocks
                }
            }
        }
    }
}


LLIR_old::variable LLIR_old::createSuccessVariable() {
    LLIR_old::variable var = createEmptyVariable("success" + generateVariableName());
    var.type = {LLIR_old::var_types::BOOLEAN};
    var.value = {LLIR_old::var_assign_values::False};
    return var;
}
auto LLIR_old::createAssignUvarBlock(const LLIR_old::variable uvar, const LLIR_old::variable var, const LLIR_old::variable &shadow_var) -> LLIR_old::member {
    return !uvar.name.empty() ?
        LLIR_old::member {LLIR_old::types::ASSIGN_VARIABLE, LLIR_old::variable_assign {uvar.name, LLIR_old::var_assign_types::ASSIGN, {LLIR_old::var_assign_values::VAR_REFER, LLIR_old::var_refer {.var = shadow_var.name.empty() ? var : shadow_var}}}}
    :
        LLIR_old::member {LLIR_old::types::EMPTY};
}
void LLIR_old::addPostLoopCheck(const TreeAPI::RuleMember &rule, const LLIR_old::variable &var, bool addError) {
    std::vector<LLIR_old::member> block = {{ LLIR_old::types::EXIT }};
    if (addError && !isFirst) {
        block.insert(block.begin(), { LLIR_old::types::ERR, getErrorName(rule)});
    }
    LLIR_old::condition check_cond = {
        {
            {LLIR_old::condition_types::NOT},
            { LLIR_old::condition_types::VARIABLE, LLIR_old::var_refer {.var = var}},
        },
        block
    };
    push({LLIR_old::types::IF, check_cond});
}
void LLIR_old::handle_plus_qualifier(const TreeAPI::RuleMember &rule, LLIR_old::condition loop, const LLIR_old::variable &uvar, const LLIR_old::variable &var, LLIR_old::variable &shadow_var, bool addError) {
    auto postCheckVar = createSuccessVariable();
    loop.block.push_back({LLIR_old::types::ASSIGN_VARIABLE, LLIR_old::variable_assign {postCheckVar.name, LLIR_old::var_assign_types::ASSIGN, LLIR_old::var_assign_values::True}});
    push({LLIR_old::types::VARIABLE, postCheckVar});
    push({LLIR_old::types::WHILE, loop});
    addPostLoopCheck(rule, postCheckVar, addError);
}
std::vector<LLIR_old::member> LLIR_old::createDefaultBlock(const LLIR_old::variable &var, const LLIR_old::variable &svar) {
    return {
        var.type.type == LLIR_old::var_types::CHAR ?
        LLIR_old::member {LLIR_old::types::ASSIGN_VARIABLE, LLIR_old::variable_assign {var.name, LLIR_old::var_assign_types::ASSIGN, LLIR_old::var_assign_values::CURRENT_CHARACTER}}
        :
        LLIR_old::member {LLIR_old::types::ASSIGN_VARIABLE, LLIR_old::variable_assign {var.name, LLIR_old::var_assign_types::ADD, LLIR_old::var_assign_values::CURRENT_POS_SEQUENCE}},
        {LLIR_old::types::ASSIGN_VARIABLE, LLIR_old::variable_assign {svar.name, LLIR_old::var_assign_types::ASSIGN, LLIR_old::var_assign_values::True}},
        {LLIR_old::types::INCREASE_POS_COUNTER}
    };
}
std::vector<LLIR_old::member> LLIR_old::createDefaultBlock(const LLIR_old::variable &svar) {
    return {
        {LLIR_old::types::ASSIGN_VARIABLE, LLIR_old::variable_assign {svar.name, LLIR_old::var_assign_types::ASSIGN, LLIR_old::var_assign_values::True}},
        {LLIR_old::types::INCREASE_POS_COUNTER}
    };
}
std::vector<LLIR_old::member> LLIR_old::createDefaultBlock() {
    return {
        {LLIR_old::types::INCREASE_POS_COUNTER}
    };
}
char LLIR_old::getEscapedChar(char in) {
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

LLIR_old::member LLIR_old::createDefaultCall(std::vector<LLIR_old::member> &block, LLIR_old::variable var, const std::string &name, std::vector<LLIR_old::expr> &expr) {
    auto function_call = LLIR_old::function_call {
        name,
        std::vector<std::vector<LLIR_old::expr>> {{LLIR_old::expr {LLIR_old::condition_types::TOKEN_SEQUENCE}}},

    };
    auto var_assign = LLIR_old::variable_assign {
        var.name,
        LLIR_old::var_assign_types::ASSIGN,
        { LLIR_old::var_assign_values::FUNCTION_CALL, function_call }
    };
    var.property_access = {"status"};
    expr = {
        {LLIR_old::condition_types::VARIABLE, LLIR_old::var_refer {.var = var}}
    };
    return {LLIR_old::types::ASSIGN_VARIABLE, var_assign};
}
LLIR_old::variable LLIR_old::add_shadow_variable(std::vector<LLIR_old::member> &block, const LLIR_old::variable &var) {
    LLIR_old::variable shadow_var = createEmptyVariable("shadow" + generateVariableName());
    auto type = var.type;
    if (type.type == LLIR_old::var_types::Rule_result)
        type.type = LLIR_old::var_types::Rule;
    else if (type.type == LLIR_old::var_types::Token_result)
        type.type = LLIR_old::var_types::Token;
    shadow_var.type = {LLIR_old::var_types::ARRAY, {type}};
    push({LLIR_old::types::VARIABLE, shadow_var});
    block.push_back({LLIR_old::types::METHOD_CALL, LLIR_old::method_call { shadow_var.name, {LLIR_old::function_call {"push", {std::vector<std::vector<LLIR_old::expr>> {{LLIR_old::expr {LLIR_old::condition_types::VARIABLE, LLIR_old::var_refer {.var = var}}}}}}}}});
    return shadow_var;
}
LLIR_old::variable LLIR_old::pushBasedOnQualifier(const TreeAPI::RuleMember &rule, std::vector<LLIR_old::expr> &expr, std::vector<LLIR_old::member> &block, LLIR_old::variable &uvar, const LLIR_old::variable &var, const LLIR_old::variable &svar, char quantifier, bool add_shadow_var) {
    //block.push_back({IR::types::ASSIGN_VARIABLE, IR::variable_assign {svar.name, IR::var_assign_types::ASSIGN, IR::var_assign_values::_TRUE}});
    LLIR_old::variable shadow_variable;
    if ((insideLoop || quantifier == '+' || quantifier == '*') && add_shadow_var) {
       shadow_variable = add_shadow_variable(block, var);
       add_shadow_var = false;
    }

    if (!uvar.name.empty()) {
        uvar.type = deduceUvarType(var, shadow_variable);
        push({LLIR_old::types::VARIABLE, uvar});
    }
    switch (quantifier) {
        case '+':
            if (add_shadow_var)
                shadow_variable = add_shadow_variable(block, var);
            handle_plus_qualifier(rule, LLIR_old::condition {expr, block}, uvar, var, shadow_variable);
            break;
        case '*': {
            if (add_shadow_var)
                shadow_variable = add_shadow_variable(block, var);
            push({LLIR_old::types::WHILE, LLIR_old::condition{expr, block}});
            //member.push(pop);
            break;
        }
        case '?':
            push({LLIR_old::types::IF, LLIR_old::condition{expr, block}});
            break;
        default:
            // add the negative into condition
            block.push_back(createAssignUvarBlock(uvar, var, shadow_variable));
            expr.insert(expr.begin(), {LLIR_old::condition_types::NOT});
            expr.insert(expr.begin() + 1, {LLIR_old::condition_types::GROUP_OPEN});
            expr.push_back({LLIR_old::condition_types::GROUP_CLOSE});
            // add exit statement
            std::vector<LLIR_old::member> blk = {{LLIR_old::types::EXIT}};
            if (!isFirst) {
                blk.insert(blk.begin(), {LLIR_old::types::ERR, getErrorName(rule)});
            }
            push({LLIR_old::types::IF, LLIR_old::condition{expr, blk}});
            add(block);
            break;
    }
    push(createAssignUvarBlock(uvar, var, shadow_variable));
    return shadow_variable;
}
// function to push based on qualifier for Rule_other
LLIR_old::variable LLIR_old::pushBasedOnQualifier_Rule_name(const TreeAPI::RuleMember &rule, std::vector<LLIR_old::expr> &expr, std::vector<LLIR_old::member> &block, LLIR_old::variable &uvar, const LLIR_old::variable &var, const LLIR_old::variable &svar, const LLIR_old::member &call, char quantifier, bool add_shadow_var) {
    //block.push_back({IR::types::ASSIGN_VARIABLE, IR::variable_assign {svar.name, IR::var_assign_types::ASSIGN, IR::var_assign_values::_TRUE}});
    LLIR_old::variable shadow_variable;
    if (insideLoop|| quantifier == '+' || quantifier == '*') {
        shadow_variable = add_shadow_variable(block, var);
        add_shadow_var = false;
    }
    if (!uvar.name.empty()) {
        uvar.type = deduceUvarType(var, shadow_variable);
        push({LLIR_old::types::VARIABLE, uvar});
    }
    switch (quantifier) {
        case '+':
            if (add_shadow_var)
                shadow_variable = add_shadow_variable(block, var);
            block.push_back(call);
            block.push_back(createAssignUvarBlock(uvar, var, shadow_variable));
            handle_plus_qualifier(rule, LLIR_old::condition {expr, block}, uvar, var, shadow_variable);
            break;
        case '*': {
            if (add_shadow_var)
                shadow_variable = add_shadow_variable(block, var);
            block.push_back(call);
            block.push_back(createAssignUvarBlock(uvar, var, shadow_variable));
            push({LLIR_old::types::WHILE, LLIR_old::condition{expr, block}});
            break;
        }
        case '?':
            block.push_back(createAssignUvarBlock(uvar, var, shadow_variable));
            push({LLIR_old::types::IF, LLIR_old::condition{expr, block}});
            break;
        default:
        {
            // add the negative into condition
            block.push_back(createAssignUvarBlock(uvar, var, shadow_variable));
            expr.insert(expr.begin(), {LLIR_old::condition_types::NOT});
            expr.insert(expr.begin() + 1, {LLIR_old::condition_types::GROUP_OPEN});
            expr.push_back({LLIR_old::condition_types::GROUP_CLOSE});
            // add exit statement
            std::vector<LLIR_old::member> blk;
            if (has_symbol_follow) {
                ErrorIR error(tree, rule, symbol_follow, isFirst);
                blk = {error.lowerToLLIR(variable_count)};
            } else {
                blk = {{LLIR_old::types::EXIT}};
                if (!isFirst) {
                    blk.insert(blk.begin(), {LLIR_old::types::ERR, getErrorName(rule)});
                }
            }

            if (!isFirst) {
                blk.insert(blk.begin(), {LLIR_old::types::ERR, getErrorName(rule)});
            }
            push({LLIR_old::types::IF, LLIR_old::condition{expr, blk}});
            add(block);
            break;
        }
    }
    return shadow_variable;
}
LLIR_old::variable LLIR_old::affectIrByQuantifier(const TreeAPI::RuleMember &rule, LLIR_old::variable &uvar, const LLIR_old::variable &var, char quantifier) {
    LLIR_old::variable shadow_var;
    if ((insideLoop || quantifier == '*' || quantifier == '+') && (var.type.type != LLIR_old::var_types::UNDEFINED && var.type.type != LLIR_old::var_types::STRING)) {
        shadow_var = add_shadow_variable(members, var);
    }
    if (!uvar.name.empty()) {
        uvar.type = deduceUvarType(var, shadow_var);
        push({LLIR_old::types::VARIABLE, uvar});
    }
    if (quantifier == '*' || quantifier == '+') {
        LLIR_old::condition loop = { { { LLIR_old::condition_types::NUMBER, (long long) 1 } }, {} };
        loop.block = members;
        members.clear();
        processExitStatements(loop.block);
        // raiseVarsTop(data, loop.block, true, false, false);
        // raiseVarsTop(data, loop.else_block, true, false, false);
        if (quantifier == '+') {
            handle_plus_qualifier(rule, loop, uvar, var, shadow_var);
        } else {
            push({LLIR_old::types::WHILE, loop});
        }
    } else if (quantifier == '?') {
        LLIR_old::condition loop = { { {LLIR_old::condition_types::NUMBER, (long long) 0} } };
        loop.block = members;
        members.clear();
        processExitStatements(loop.block);
        push({ LLIR_old::types::DOWHILE, loop });
    }
    return shadow_var;
}

// Function to compare two `templ` arrays
bool LLIR_old::compare_templ(const std::vector<LLIR_old::var_type>& templ1, const std::vector<LLIR_old::var_type>& templ2) {
    if (templ1.size() != templ2.size()) return false;

    for (size_t i = 0; i < templ1.size(); ++i) {
        if (templ1[i].type != templ2[i].type) return false;
        if (!compare_templ(templ1[i].templ, templ2[i].templ)) return false;  // Recursively compare nested `templ`
    }
    return true;
}
std::string LLIR_old::getErrorName(const TreeAPI::RuleMember &rule) {
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
        } else {
            std::string result;
            for (const auto &part : name.name) {
                for (const auto &char_part : part) {
                    result += tolower(char_part);
                }
                result += " ";
            }
            return result;
        }
        return name.name.back();
    }
    if (rule.isEscaped()) {
        return std::string("\\") + rule.getEscaped().c;
    }
    if (rule.isAny()) {
        return "symbol";
    }
    if (rule.isOp()) {
        std::string res;
        const auto &op = rule.getOp();
        for (const auto &option : op.options) {
            res += getErrorName(option);
            if (&option != &op.options.back())
                res += " or ";
        }
        return res;
    }
    throw Error("Undefined rule member");
}
LLIR_old::assign LLIR_old::TreeRvalueToIR(const TreeAPI::rvalue &value) {
    LLIR_old::assign newval;
    if (value.isString()) {
        newval.kind = LLIR_old::var_assign_values::STRING;
        newval.data = std::any_cast<std::string>(value.getString().value);
    } else if (value.isBoolean()) {
        newval.kind = LLIR_old::var_assign_values::BOOLEAN;
        newval.data = value.getBoolean().getBoolean() ? LLIR_old::var_assign_values::True : LLIR_old::var_assign_values::False;
    } else if (value.isNumber()) {
        newval.kind = LLIR_old::var_assign_values::NUMBER;
        newval.data = value.getNumber().getFull();
    } else if (value.isID()) {
        newval.kind = LLIR_old::var_assign_values::VAR_REFER;
        auto find_it = std::find_if(vars.begin(), vars.end(), [&value](const LLIR_old::variable &var) { return var.name == value.getID().value; });
        if (find_it == vars.end())
            throw Error("Not found variable to convert into expr");
        newval.data = LLIR_old::var_refer {.var = *find_it };
    } else if (value.isAt()) {
        newval.kind = LLIR_old::var_assign_values::VAR_REFER;
        newval.data = LLIR_old::var_refer {.var = unnamed_datablock_units.front()};
        unnamed_datablock_units.erase(unnamed_datablock_units.end());
    } else if (value.isArray()) {
        newval.kind = LLIR_old::var_assign_values::ARRAY;
        LLIR_old::array arr;
        for (const auto el : value.getArray().value) {
            arr.push_back(TreeExprToIR(el));
        }
        newval.data = arr;
    } else if (value.isObject()) {
        newval.kind = LLIR_old::var_assign_values::OBJECT;
        LLIR_old::object obj;
        for (const auto &[key, value] : value.getObject().value) {
            obj[key] = TreeExprToIR(value);
        }
        newval.data = obj;
    } else throw Error("Undefined rvalue");
    return newval;
}
std::vector<std::vector<LLIR_old::expr>> LLIR_old::TreeFunctionBodyCallToIR(const TreeAPI::CllFunctionBodyCall &body) {
    std::vector<std::vector<LLIR_old::expr>> newExpr;
    for (const auto &expr : body.expr) {
        newExpr.push_back(TreeExprToIR(expr));
    }
    return newExpr;
}
LLIR_old::function_call LLIR_old::TreeFunctionToIR(const TreeAPI::CllFunctionCall &call) {
    LLIR_old::function_call newCall;
    newCall.name = call.name;
    newCall.params = TreeFunctionBodyCallToIR(call.body);
    return newCall;
}

LLIR_old::method_call LLIR_old::TreeMethodCallToIR(const TreeAPI::CllMethodCall &method) {
    LLIR_old::method_call newMethod;
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
LLIR_old::var_type LLIR_old::cllTreeTypeToIR(const TreeAPI::CllType &type) {
    if (type.type == "var")
        return {LLIR_old::var_types::ANY, {}};
    else if (type.type == "str")
        return {LLIR_old::var_types::STRING, {}};
    else if (type.type == "bool")
        return {LLIR_old::var_types::BOOLEAN, {}};
    else if (type.type == "num")
        return {LLIR_old::var_types::NUMBER, {}};
    else if (type.type == "arr") {
        LLIR_old::var_types tp = LLIR_old::var_types::ARRAY;
        LLIR_old::var_type _template = cllTreeTypeToIR(type.templ[0]);
        return {tp, {_template}};
    } else if (type.type == "obj") {
        LLIR_old::var_types tp = LLIR_old::var_types::OBJECT;
        LLIR_old::var_type _template1 = cllTreeTypeToIR(type.templ[0]);
        LLIR_old::var_type _template2 = cllTreeTypeToIR(type.templ[1]);
        return {tp, {_template1, _template2}};
    }
    throw Error("Undefined type");
}
LLIR_old::var_assign_types LLIR_old::TreeOpToIR(const char op) {
    // all other is single character so can use switch
    switch (op) {
        case '+':
            return LLIR_old::var_assign_types::ADD;
        case '-':
            return LLIR_old::var_assign_types::SUBSTR;
        case '*':
            return LLIR_old::var_assign_types::MULTIPLY;
        case '/':
            return LLIR_old::var_assign_types::DIVIDE;
        case '%':
            return LLIR_old::var_assign_types::MODULO;
    }
    throw Error("Undefined operator");
}
LLIR_old::expr LLIR_old::TreeOpToExpr(const char op) {
    switch (op) {
        case '+':
            return {LLIR_old::condition_types::ADD};
        case '-':
            return {LLIR_old::condition_types::SUBSTR};
        case '*':
            return {LLIR_old::condition_types::MULTIPLY};
        case '/':
            return {LLIR_old::condition_types::DIVIDE};
        case '%':
            return {LLIR_old::condition_types::MODULO};
    }
    throw Error("Undefined operator");
}
LLIR_old::expr LLIR_old::TreeCompareOpToExpr(const TreeAPI::CllCompareOp &op) {
    if (op.op == "==")
        return {LLIR_old::condition_types::EQUAL};
    if (op.op == "!=")
        return {LLIR_old::condition_types::NOT_EQUAL};
    if (op.op == ">")
        return {LLIR_old::condition_types::HIGHER};
    if (op.op == "<")
        return {LLIR_old::condition_types::LOWER};
    if (op.op == ">=")
        return {LLIR_old::condition_types::HIGHER_OR_EQUAL};
    if (op.op == "<=")
        return {LLIR_old::condition_types::LOWER_OR_EQUAL};
    throw Error("undefined compare operator");
}
LLIR_old::expr LLIR_old::TreeLogicalOpToIR(const TreeAPI::CllLogicalOp &lop) {
    if (lop.isAnd)
        return {LLIR_old::condition_types::AND};
    return {LLIR_old::condition_types::OR};
}
LLIR_old::var_assign_types LLIR_old::TreeAssignmentOpToIR(const char op) {
    if (op == '\0')
        return LLIR_old::var_assign_types::ASSIGN;
    auto v = TreeOpToIR(op);
    v = static_cast<LLIR_old::var_assign_types>(static_cast<int>(v) + static_cast<int>(LLIR_old::var_assign_types::ASSIGN));
    return v;
}
std::vector<LLIR_old::expr> LLIR_old::TreeExprGroupToIR(const TreeAPI::CllExpr &group) {
    std::vector<LLIR_old::expr> expr;
    auto expression = TreeExprToIR(group);
    expr.push_back({LLIR_old::condition_types::GROUP_OPEN});
    expr.insert(expr.end(), expression.begin(), expression.end());
    expr.push_back({LLIR_old::condition_types::GROUP_CLOSE});
    return expr;
}
std::vector<LLIR_old::expr> LLIR_old::TreeExprValueToIR(const TreeAPI::CllExprValue &value) {
    std::vector<LLIR_old::expr> expr;
    if (value.isGroup()) {
        expr = TreeExprGroupToIR(value.getGroup());
    } else if (value.isMethodCall()) {
        expr.push_back({LLIR_old::condition_types::METHOD_CALL, TreeMethodCallToIR(value.getMethodCall())});
    } else if (value.isFunctionCall()) {
        expr.push_back({LLIR_old::condition_types::FUNCTION_CALL, TreeFunctionToIR(value.getFunctionCall())});
    } else if (value.isVariable()) {
        LLIR_old::var_refer refer;
        const auto &v = value.getVariable();
        refer.var = { .name = v.name };
        refer.pre_increament = v.pre_increament;
        refer.post_increament = v.post_increament;
        if (v.braceExpression.has_value()) {
            refer.brace_expression = TreeExprToIR(v.braceExpression.value());
        }
        expr.push_back({LLIR_old::condition_types::VARIABLE, refer});
    } else if (value.isrvalue()) {
        expr.push_back({LLIR_old::condition_types::RVALUE, TreeRvalueToIR(value.getrvalue())});
    } else throw Error("Undefined expression");
    return expr;
}
std::vector<LLIR_old::expr> LLIR_old::TreeExprTermToIR(const TreeAPI::CllExprTerm &term) {
    // if (rule.name == Parser::Rules::cll_function_call)
    std::vector<LLIR_old::expr> cond;
    auto res = TreeExprValueToIR(term.value);
    cond.insert(cond.end(), res.begin(), res.end());
    for (int i = 0; i < term.rights.size(); i++) {
        cond.push_back(TreeOpToExpr(term.rights[i].first));
        res = TreeExprValueToIR(term.rights[i].second);
        cond.insert(cond.end(), res.begin(), res.end());
    }
    return cond;
}
std::vector<LLIR_old::expr> LLIR_old::TreeExprAdditionToIR(const TreeAPI::CllExprAddition &addition) {
    // if (rule.name == Parser::Rules::cll_function_call)
    std::vector<LLIR_old::expr> cond;
    auto res = TreeExprTermToIR(addition.value);
    cond.insert(cond.end(), res.begin(), res.end());
    for (int i = 0; i < addition.rights.size(); i++) {
        cond.push_back(TreeOpToExpr(addition.rights[i].first));
        res = TreeExprTermToIR(addition.rights[i].second);
        cond.insert(cond.end(), res.begin(), res.end());
    }
    return cond;
}
std::vector<LLIR_old::expr> LLIR_old::TreeExprCompareToIR(const TreeAPI::CllExprCompare &compare) {
    std::vector<LLIR_old::expr> cond;
    auto res = TreeExprAdditionToIR(compare.value);
    cond.insert(cond.end(), res.begin(), res.end());
    for (int i = 0; i < compare.rights.size(); i++) {
        cond.push_back(TreeCompareOpToExpr(compare.rights[i].first));
        res = TreeExprAdditionToIR(compare.rights[i].second);
        cond.insert(cond.end(), res.begin(), res.end());
    }
    return cond;
}
std::vector<LLIR_old::expr> LLIR_old::TreeExprLogicalToIR(const TreeAPI::CllExprLogical &logical) {
    std::vector<LLIR_old::expr> cond;
    auto res = TreeExprCompareToIR(logical.value);
    cond.insert(cond.end(), res.begin(), res.end());
    for (int i = 0; i < logical.rights.size(); i++) {
        cond.push_back(TreeLogicalOpToIR(logical.rights[i].first));
        res = TreeExprCompareToIR(logical.rights[i].second);
        cond.insert(cond.end(), res.begin(), res.end());
    }
    return cond;
}
std::vector<LLIR_old::expr> LLIR_old::TreeExprToIR(const TreeAPI::CllExpr &expr) {
    return TreeExprLogicalToIR(expr.value);
}
auto LLIR_old::deduceUvarType(const LLIR_old::variable &var, const LLIR_old::variable &shadow_var) -> LLIR_old::var_type {
    return shadow_var.name.empty() ? var.type : shadow_var.type;
}
LLIR_old::var_type LLIR_old::deduceVarTypeByProd(const TreeAPI::RuleMember &mem) {
    LLIR_old::var_type type = {LLIR_old::var_types::UNDEFINED};
    if (mem.isGroup()) {
        const auto &val = mem.getGroup().values;
        if (val.size() == 1) {
            type = deduceVarTypeByProd(val[0]);
        } else {
            for (auto i = 0; i < val.size(); i++) {
                if (deduceVarTypeByProd(val[i]).type != LLIR_old::var_types::STRING) {
                    return {LLIR_old::var_types::UNDEFINED};
                }
            }
            type = {LLIR_old::var_types::STRING};
        }
    } else if (mem.isOp()) {
        std::optional<LLIR_old::var_types> first_type;
        char prev_quantifier = '\0';
        for (const auto &el : mem.getOp().options) {
            auto t = deduceVarTypeByProd(el).type;
            // if (t == LLIR::var_types::UNDEFINED)
            //     return {LLIR::var_types::UNDEFINED};
            if (!first_type) {
                first_type = t;
                prev_quantifier = el.quantifier;
            } else if (t != *first_type || prev_quantifier != el.quantifier) {
                return {LLIR_old::var_types::ANY};
            }
        }
        type.type = first_type.value_or(LLIR_old::var_types::UNDEFINED);
    } else if (mem.isName()) {
        type.type = corelib::text::isUpper(mem.getName().name.back()) ? LLIR_old::var_types::Token : LLIR_old::var_types::Rule;
    } else type.type = LLIR_old::var_types::STRING;
    return type;
}
LLIR_old::var_type LLIR_old::deduceTypeFromRvalue(const TreeAPI::rvalue &value) {
    LLIR_old::var_type type = {LLIR_old::var_types::UNDEFINED};
    if (value.isString())
        type.type = LLIR_old::var_types::STRING;
    else if (value.isBoolean())
        type.type = LLIR_old::var_types::BOOLEAN;
    else if (value.isNumber())
        type.type = LLIR_old::var_types::NUMBER;
    else if (value.isID()) {
        // likely never execute
        auto find_it = std::find_if(vars.begin(), vars.end(), [&value](const LLIR_old::variable &var) { return var.name == value.getID().value; });
        if (find_it == vars.end())
            throw Error("Not found variable to deduce type from expr");
        if (find_it->type.type == LLIR_old::var_types::Rule_result)
            type = {LLIR_old::var_types::Rule};
        else if (find_it->type.type == LLIR_old::var_types::Token_result)
            type = {LLIR_old::var_types::Token};
        else type = find_it->type;
    } else if (value.isAt()) {
        if (unnamed_datablock_units.empty())
            throw Error("no more data accamulated with @");
        const auto &t = unnamed_datablock_units.front().type;
        if (t.type == LLIR_old::var_types::Rule_result)
            type = {LLIR_old::var_types::Rule};
        else if (t.type == LLIR_old::var_types::Token_result)
            type = {LLIR_old::var_types::Token};
        else type = t;
    } else if (value.isArray()) {
        LLIR_old::var_type types;
        for (const auto &el : value.getArray().value) {
            if (types.type == LLIR_old::var_types::UNDEFINED) {
                types = deduceTypeFromExpr(el);
            } else {
                auto newType = deduceTypeFromExpr(el);
                if (newType.type != types.type || !compare_templ(newType.templ, types.templ)) {
                    type.type = LLIR_old::var_types::ANY;
                    break;
                }
            }
        }
        if (types.type != LLIR_old::var_types::ANY) {
            type.templ = {types};
            type.type = LLIR_old::var_types::ARRAY;
        }
    } else if (value.isObject()) {
        // todo: add handle key of different types (int or string)
        LLIR_old::var_type types;
        for (const auto &[key, value] : value.getObject().value) {
            if (types.type == LLIR_old::var_types::UNDEFINED) {
                types = deduceTypeFromExpr(value);
            } else {
                auto newType = deduceTypeFromExpr(value);
                if (newType.type != types.type || !compare_templ(newType.templ, types.templ)) {
                    type.type = LLIR_old::var_types::ANY;
                    break;
                }
            }
        }
        if (types.type != LLIR_old::var_types::ANY) {
            type.templ = {types};
            type.type = LLIR_old::var_types::OBJECT;
        }
    } else {
        throw Error("Undefined rule");
    }
    return type;
}
LLIR_old::var_type LLIR_old::deduceTypeFromExprValue(const TreeAPI::CllExprValue &value) {
    if (value.isFunctionCall()) {
        // todo - get function call type
    } else if (value.isGroup()) {
        return deduceTypeFromExpr(value.getGroup());
    } else if (value.isMethodCall()) {
        // todo - get method call type
    } else if (value.isVariable()) {
        auto find_it = std::find_if(vars.begin(), vars.end(), [&value](const LLIR_old::variable &var) { return var.name == value.getVariable().name; });
        if (find_it == vars.end())
            throw Error("Not found variable to deduce type from expr");
        if (find_it->type.type == LLIR_old::var_types::Rule_result)
            return {LLIR_old::var_types::Rule};
        if (find_it->type.type == LLIR_old::var_types::Token_result)
            return {LLIR_old::var_types::Token};
        return find_it->type;
    } else if (value.isrvalue()) {
        return deduceTypeFromRvalue(value.getrvalue());
    } else
        throw Error("Undefined expr value member: %s in rule %s", value.value.type().name(), fullname);
    return {};
}
LLIR_old::var_type LLIR_old::deduceTypeFromExprTerm(const TreeAPI::CllExprTerm &term) {
    // type is explicitly based on value. We may not check others in addition
    return deduceTypeFromExprValue(term.value);
}
LLIR_old::var_type LLIR_old::deduceTypeFromExprAddition(const TreeAPI::CllExprAddition &addition) {
    // same as with term
    return deduceTypeFromExprTerm(addition.value);
}
LLIR_old::var_type LLIR_old::deduceTypeFromExprCompare(const TreeAPI::CllExprCompare &compare) {
    // if any comparasion exists it is boolean
    if (compare.rights.size() != 0)
        return {LLIR_old::var_types::BOOLEAN};
    return deduceTypeFromExprAddition(compare.value);
}
LLIR_old::var_type LLIR_old::deduceTypeFromExprLogical(const TreeAPI::CllExprLogical &logical) {
    // if &&/|| exists it is always boolean
    if (logical.rights.size() != 0)
        return {LLIR_old::var_types::BOOLEAN};
    return deduceTypeFromExprCompare(logical.value);
}
LLIR_old::var_type LLIR_old::deduceTypeFromExpr(const TreeAPI::CllExpr &expr) {
    return deduceTypeFromExprLogical(expr.value);
}
LLIR_old::ConvertionResult LLIR_old::processGroup(const TreeAPI::RuleMember &rule) {
    //cpuf::printf("group\n");
    // create variable with name of "var" or with auto-generated one
    auto var = createEmptyVariable(generateVariableName());
    auto uvar = !rule.prefix.name.empty() ? createEmptyVariable(rule.prefix.name) : createEmptyVariable("");
    auto svar = createSuccessVariable();
    auto prev_insideLoop = insideLoop;
    const auto &quantifier = rule.quantifier;
    if (quantifier == '*' || quantifier == '+')
        insideLoop = true;
    bool addSpaceSkipFirst;
    auto values = rulesToIr(rule.getGroup().values, addSpaceSkipFirst);
    update(values);
    insideLoop = prev_insideLoop;
    // remove previous space skip it there was \s0
    if (members.size() > 0 && !addSpaceSkipFirst) {
        // remove previous skip of spaces if it does exists
        for (auto rit = this->members.rbegin(); rit != this->members.rend(); rit++) {
            if (rit->type == LLIR_old::types::SKIP_SPACES) {
                this->members.erase(rit.base());
                break;
            }
        }
    }

    var.type = {deduceVarTypeByProd(rule)};
    if ((quantifier == '*' || quantifier == '+') && var.type.type != LLIR_old::var_types::UNDEFINED && var.type.type != LLIR_old::var_types::STRING) {
        var.type.templ = {{var.type.type}};
        var.type.type = LLIR_old::var_types::ARRAY;
    }
    std::vector<LLIR_old::member> var_members;
    switch (var.type.type == LLIR_old::var_types::ARRAY ? var.type.templ[0].type : var.type.type) {
        case LLIR_old::var_types::STRING:
            // it is a string so add all values
            for (auto node : values.success_vars) {
                if (node.var.name.empty())
                    continue;
                var_members.push_back(
                    {
                        LLIR_old::types::ASSIGN_VARIABLE,
                        LLIR_old::variable_assign {var.name, LLIR_old::var_assign_types::ADD, LLIR_old::assign { LLIR_old::var_assign_values::VAR_REFER, LLIR_old::var_refer {.var = node.var} }}
                    }
                );
            }
            break;
        case LLIR_old::var_types::Token:
        case LLIR_old::var_types::Rule:
            // it is token so perform a single assign
            var_members.push_back( LLIR_old::member
                {
                    LLIR_old::types::ASSIGN_VARIABLE,
                    LLIR_old::variable_assign {var.name, LLIR_old::var_assign_types::ASSIGN, LLIR_old::assign { LLIR_old::var_assign_values::VAR_REFER,  LLIR_old::var_refer {.var = values.success_vars[0].var}}}
                }
            );

            var.type = values.success_vars[0].var.type;
            if (var.type.type == LLIR_old::var_types::Rule_result)
                var.type.type = LLIR_old::var_types::Rule;
            else if (var.type.type == LLIR_old::var_types::Token_result)
                var.type.type = LLIR_old::var_types::Token;
            break;
        default:
            var.type = {LLIR_old::var_types::UNDEFINED};
            break;
    }
    std::string begin_var_name = "begin" + generateVariableName();
    std::vector<LLIR_old::expr> svar_expr = {};
    std::vector<std::string> used_vars;
    //cpuf::printf("success_vars.size(): %d\n", success_vars.size());
    if (!values.success_vars.empty()) {
        bool first = true;
        for (auto el : values.success_vars) {
            if (el.qualifier == '*' || el.qualifier == '?' || el.svar.name.empty())
                continue;
            if (!first)
                svar_expr.push_back({LLIR_old::condition_types::AND});
            used_vars.push_back(el.svar.name);
            svar_expr.push_back({LLIR_old::condition_types::VARIABLE, LLIR_old::var_refer {.var = el.svar}});
            first = false;
        }
    }
    // for (int i = 0; i < node_ret.size(); i++) {
    //     if (i != 0)
    //         svar_expr.push_back({IR::condition_types::AND});
    //     svar_expr.push_back({IR::condition_types::VARIABLE, node_ret[i].svar});
    // }

    if (!values.members.empty() && values.members.back().type == LLIR_old::types::SKIP_SPACES) {
        values.pop();
    }
    values.add(var_members);
    auto shadow_var = values.affectIrByQuantifier(rule, uvar, var, quantifier);
    for (const auto &svar : used_vars) {
        raiseVarsTop(values.members, values.members, svar, true, false, true);
    }
    std::vector<LLIR_old::member> svar_cond;
    if (svar_expr.empty()) {
        svar_cond = {
            {LLIR_old::types::ASSIGN_VARIABLE, LLIR_old::variable_assign {svar.name, LLIR_old::var_assign_types::ASSIGN, LLIR_old::var_assign_values::True}},
            createAssignUvarBlock(uvar, var, shadow_var),
            {LLIR_old::types::POP_POS_COUNTER}
        };
    } else {
        svar_cond = {{
            LLIR_old::types::IF,
            LLIR_old::condition {
                svar_expr,
                {
                    {LLIR_old::types::ASSIGN_VARIABLE, LLIR_old::variable_assign {svar.name, LLIR_old::var_assign_types::ASSIGN, LLIR_old::var_assign_values::True}},
                    createAssignUvarBlock(uvar, var, shadow_var),
                    {LLIR_old::types::POP_POS_COUNTER}
                }
            }
        }};
    }
    if (var.type.type != LLIR_old::var_types::UNDEFINED) {
        push({LLIR_old::types::VARIABLE, var});
    }
    push({LLIR_old::types::VARIABLE, svar});
    push({LLIR_old::types::PUSH_POS_COUNTER, begin_var_name});
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
    if (uvar.type.type == LLIR_old::var_types::UNDEFINED)
        return LLIR_old::ConvertionResult {svar, {}, var, shadow_var, quantifier};
    return LLIR_old::ConvertionResult {svar, uvar, var, shadow_var, quantifier};
}
LLIR_old::ConvertionResult LLIR_old::processRuleCsequence(const TreeAPI::RuleMember &rule) {
    //cpuf::printf("csequence\n");
    const auto &csequence = rule.getCsequence();

    auto uvar = !rule.prefix.name.empty() ? createEmptyVariable(rule.prefix.name) : createEmptyVariable("");
    auto var = createEmptyVariable(generateVariableName());
    auto svar = createSuccessVariable();
    std::vector<LLIR_old::expr> expr;

    if (csequence.negative) {
        expr = {
            {LLIR_old::condition_types::NOT},
            {LLIR_old::condition_types::GROUP_OPEN}
        };
    }

    bool first = true;
    size_t count = 0;
    for (const auto c : csequence.characters) {
        if (!first)
            expr.push_back({LLIR_old::condition_types::OR});
        expr.insert(expr.end(), {
            {LLIR_old::condition_types::CURRENT_CHARACTER, (size_t) 0},
            {LLIR_old::condition_types::EQUAL},
            {LLIR_old::condition_types::CHARACTER, c}
        });
        first = false;
    }
    for (const auto c : csequence.escaped) {
        if (!first)
            expr.push_back({LLIR_old::condition_types::OR});
        expr.insert(expr.end(), {
            {LLIR_old::condition_types::CURRENT_CHARACTER, (size_t) 0},
            {LLIR_old::condition_types::EQUAL},
            {LLIR_old::condition_types::ESCAPED_CHARACTER, c}
        });
        first = false;
    }
    for (const auto &[from, to] : csequence.diapasons) {
        if (!first)
            expr.push_back({LLIR_old::condition_types::OR});
        expr.insert(expr.end(), {
            {LLIR_old::condition_types::GROUP_OPEN},
            {LLIR_old::condition_types::CURRENT_CHARACTER, (size_t) 0},
            {LLIR_old::condition_types::HIGHER_OR_EQUAL},
            {LLIR_old::condition_types::CHARACTER, from},
            {LLIR_old::condition_types::AND},
            {LLIR_old::condition_types::CURRENT_CHARACTER, (size_t) 0},
            {LLIR_old::condition_types::LOWER_OR_EQUAL},
            {LLIR_old::condition_types::CHARACTER, to},
            {LLIR_old::condition_types::GROUP_CLOSE}
        });
        first = false;
    }
    if (csequence.negative) {
        if (rule.quantifier == '+' || rule.quantifier == '*')
            expr.insert(expr.end(), {
                {LLIR_old::condition_types::AND}, {LLIR_old::condition_types::CURRENT_CHARACTER, (size_t) 0}, {LLIR_old::condition_types::NOT_EQUAL}, {LLIR_old::condition_types::ESCAPED_CHARACTER, '0'},
            });
        expr.push_back({LLIR_old::condition_types::GROUP_CLOSE});
    }
    if (rule.quantifier == '\0')
        var.type = {LLIR_old::var_types::CHAR};
    else
        var.type = {LLIR_old::var_types::STRING};
    push({LLIR_old::types::VARIABLE, var});
    push({LLIR_old::types::VARIABLE, svar});
    std::vector<LLIR_old::member> block = createDefaultBlock(var, svar);
    auto shadow_var = pushBasedOnQualifier(rule, expr, block, uvar, var, svar, rule.quantifier, false);
    return {svar, uvar, var, shadow_var, rule.quantifier};
}
LLIR_old::ConvertionResult LLIR_old::processString(const TreeAPI::RuleMember &rule) {
    //cpuf::printf("string, data: %s\n", std::any_cast<std::string>(rule.data));
    const auto &str = rule.getString();
    const auto &value = str.value;
    auto uvar = !rule.prefix.name.empty() ? createEmptyVariable(rule.prefix.name) : createEmptyVariable("");
    auto var = createEmptyVariable(generateVariableName());
    auto svar = createSuccessVariable();
    std::vector<LLIR_old::expr> expr;
    if (value.size() == 0)
        return {};
    if (str.count_strlen() == 1) {
        // micro optimization - compare as single character for single character strings
        expr = {
            {LLIR_old::condition_types::CURRENT_CHARACTER, (size_t) 0},
            {LLIR_old::condition_types::EQUAL},
            value[0] == '\\' ? LLIR_old::expr {LLIR_old::condition_types::ESCAPED_CHARACTER, value[1]} :  LLIR_old::expr {LLIR_old::condition_types::CHARACTER, value[0]}
        };
        var.type.type = LLIR_old::var_types::CHAR;
    } else {
        expr = {
            {LLIR_old::condition_types::STRNCMP, LLIR_old::strncmp{true, value}}
        };
        var.type = {LLIR_old::var_types::STRING};
    }
    if (corelib::text::isAllAlpha(value)) {
        // it is keyword, add conditional check that it is not start of ID
        expr.insert(expr.end(), {
            {LLIR_old::condition_types::AND},
            {LLIR_old::condition_types::NOT},
            {LLIR_old::condition_types::GROUP_OPEN},
                {LLIR_old::condition_types::CURRENT_CHARACTER, str.count_strlen()}, {LLIR_old::condition_types::HIGHER_OR_EQUAL}, {LLIR_old::condition_types::CHARACTER, 'a'},
                {LLIR_old::condition_types::AND},
                {LLIR_old::condition_types::CURRENT_CHARACTER, str.count_strlen()}, {LLIR_old::condition_types::LOWER_OR_EQUAL}, {LLIR_old::condition_types::CHARACTER, 'z'},
                {LLIR_old::condition_types::OR},
                {LLIR_old::condition_types::CURRENT_CHARACTER, str.count_strlen()}, {LLIR_old::condition_types::HIGHER_OR_EQUAL}, {LLIR_old::condition_types::CHARACTER, 'A'},
                {LLIR_old::condition_types::AND},
                {LLIR_old::condition_types::CURRENT_CHARACTER, str.count_strlen()}, {LLIR_old::condition_types::LOWER_OR_EQUAL}, {LLIR_old::condition_types::CHARACTER, 'Z'},
                {LLIR_old::condition_types::OR},
                {LLIR_old::condition_types::CURRENT_CHARACTER, str.count_strlen()}, {LLIR_old::condition_types::HIGHER_OR_EQUAL}, {LLIR_old::condition_types::CHARACTER, '0'},
                {LLIR_old::condition_types::AND},
                {LLIR_old::condition_types::CURRENT_CHARACTER, str.count_strlen()}, {LLIR_old::condition_types::LOWER_OR_EQUAL}, {LLIR_old::condition_types::CHARACTER, '9'},
                {LLIR_old::condition_types::OR},
                {LLIR_old::condition_types::CURRENT_CHARACTER, str.count_strlen()}, {LLIR_old::condition_types::EQUAL}, {LLIR_old::condition_types::CHARACTER, '_'},
            {LLIR_old::condition_types::GROUP_CLOSE},
        });
    }
    std::vector<LLIR_old::member> block = createDefaultBlock(var, svar);
    push({LLIR_old::types::VARIABLE, var});
    push({LLIR_old::types::VARIABLE, svar});
    pushBasedOnQualifier(rule, expr, block, uvar, var, svar, rule.quantifier, false);
    return {svar, uvar, var, {}, rule.quantifier};
}
LLIR_old::ConvertionResult LLIR_old::process_Rule_hex(const TreeAPI::RuleMember &rule) {
    //cpuf::printf("hex\n");
    auto data = rule.getHex().hex_chars;
    std::vector<LLIR_old::expr> expr = {};
    auto uvar = !rule.prefix.name.empty() ? createEmptyVariable(rule.prefix.name) : createEmptyVariable("");
    auto var = createEmptyVariable(generateVariableName());
    auto svar = createSuccessVariable();
    var.type = {LLIR_old::var_types::STRING};
    std::vector<LLIR_old::member> block = createDefaultBlock(var, svar);
    bool is_first = true, is_negative = false;
    if (rule.quantifier == '\0') {
        expr.push_back({LLIR_old::condition_types::NOT});
        expr.push_back({LLIR_old::condition_types::GROUP_OPEN});
        is_negative = true;
    }
    if (data.size() % 2 != 0)
        data.insert(data.begin(), '0');
    for (size_t i = 0; i < data.size(); i += 2) {
        std::string hex(data.data() + i, 2);
        if (!is_first)
            expr.push_back({LLIR_old::condition_types::AND});
        is_first = false;
        expr.push_back({LLIR_old::condition_types::CURRENT_CHARACTER, i});
        expr.push_back({LLIR_old::condition_types::EQUAL});
        expr.push_back({LLIR_old::condition_types::HEX, hex});
    }
    if (is_negative) {
        expr.push_back({LLIR_old::condition_types::GROUP_CLOSE});
    }
    //cpuf::printf("hex_open\n");
    push({LLIR_old::types::VARIABLE, var});
    push({LLIR_old::types::VARIABLE, svar});
    auto shadow_var = pushBasedOnQualifier(rule, expr, block, uvar, var, svar, rule.quantifier, false);
    return {svar, uvar, var, shadow_var, rule.quantifier};
}
LLIR_old::ConvertionResult LLIR_old::process_Rule_bin(const TreeAPI::RuleMember &rule) {
    //cpuf::printf("hex\n");
    auto data = rule.getBin().bin_chars;
    std::vector<LLIR_old::expr> expr = {};
    auto uvar = !rule.prefix.name.empty() ? createEmptyVariable(rule.prefix.name) : createEmptyVariable("");
    auto var = createEmptyVariable(generateVariableName());
    auto svar = createSuccessVariable();
    std::vector<LLIR_old::member> block = {
        {LLIR_old::types::ASSIGN_VARIABLE, LLIR_old::variable_assign {var.name, LLIR_old::var_assign_types::ADD, LLIR_old::var_assign_values::CURRENT_POS_SEQUENCE}},
        {LLIR_old::types::INCREASE_POS_COUNTER},
    };
    bool is_first = true, is_negative = false;
    if (rule.quantifier == '\0') {
        expr.push_back({LLIR_old::condition_types::NOT});
        expr.push_back({LLIR_old::condition_types::GROUP_OPEN});
        is_negative = true;
    }
    while (data.size() % 8 != 0)
        data.insert(data.begin(), '0');
    for (size_t i = 0; i < data.size(); i += 8) {
        std::string bin(data.data() + i, 8);
        auto as_hex = hex::from_binary(bin);
        as_hex.erase(as_hex.begin(), as_hex.begin() + 2);
        if (!is_first)
            expr.push_back({LLIR_old::condition_types::AND});
        is_first = false;
        expr.push_back({LLIR_old::condition_types::CURRENT_CHARACTER, i});
        expr.push_back({LLIR_old::condition_types::EQUAL});
        expr.push_back({LLIR_old::condition_types::HEX, as_hex});
    }
    if (is_negative) {
        expr.push_back({LLIR_old::condition_types::GROUP_CLOSE});
    }
    push({LLIR_old::types::VARIABLE, var});
    push({LLIR_old::types::VARIABLE, svar});
    auto shadow_var = pushBasedOnQualifier(rule, expr, block, uvar, var, svar, rule.quantifier, false);
    return {svar, uvar, var, shadow_var, rule.quantifier};
}
LLIR_old::ConvertionResult LLIR_old::process_Rule_name(const TreeAPI::RuleMember &rule) {
    //cpuf::printf("Rule_other");
    auto name = rule.getName().name;
    //cpuf::printf(", name: %s\n", name_str);
    auto uvar = !rule.prefix.name.empty() ? createEmptyVariable(rule.prefix.name) : createEmptyVariable("");
    auto var = createEmptyVariable(generateVariableName());
    auto svar = createSuccessVariable();
    LLIR_old::variable shadow_var;
    bool isCallingToken = corelib::text::isUpper(name.back());
    if (has_symbol_follow) {
        if (symbol_follow.empty())
            throw Error("empty symbol follow on rule %$\n", fullname);
        symbol_follow.back().first = name;
    }
    if (!isToken && isCallingToken) {
        var.type.type = LLIR_old::var_types::Token;
    } else {
        var.type = isCallingToken ? LLIR_old::var_type {LLIR_old::var_types::Token_result} : LLIR_old::var_type {LLIR_old::var_types::Rule_result};
    }
    auto block = createDefaultBlock(var, svar);
    push({LLIR_old::types::VARIABLE, var});
    push({LLIR_old::types::VARIABLE, svar});
    if (isToken) {
        if (!isCallingToken)
            throw Error("Cannot call rule from token");
        // remove variable assignemnt
        block.back().type = LLIR_old::types::INCREASE_POS_COUNTER_BY_TOKEN_LENGTH;
        block.back().value = var.name;
        var.property_access = {"node"};
        block.erase(block.begin());
        std::vector<LLIR_old::expr> expr;
        auto call = createDefaultCall(block, var, corelib::text::join(name, "_"), expr);
        push(call);
        shadow_var = pushBasedOnQualifier_Rule_name(rule, expr, block, uvar, var, svar, call, rule.quantifier);

    } else {
        if (isCallingToken) {
            block[0] = {
                LLIR_old::types::ASSIGN_VARIABLE,
                LLIR_old::variable_assign {
                    var.name,
                    LLIR_old::var_assign_types::ASSIGN,
                    LLIR_old::var_assign_values::CURRENT_TOKEN
                }
            };
            std::vector<LLIR_old::expr> expr = {
                {LLIR_old::condition_types::CURRENT_TOKEN, LLIR_old::current_token {LLIR_old::condition_types::EQUAL, corelib::text::join(name, "_")}},
            };
            shadow_var = pushBasedOnQualifier(rule, expr, block, uvar, var, svar, rule.quantifier);
        } else {
            block.back().type = LLIR_old::types::INCREASE_POS_COUNTER_BY_TOKEN_LENGTH;
            block.back().value = var.name;
            var.property_access = {"node"};
            block.erase(block.begin()); // remove variable assignment
            std::vector<LLIR_old::expr> expr;
            auto call = createDefaultCall(block, var, corelib::text::join(name, "_"), expr);
            push(call);
            shadow_var = pushBasedOnQualifier_Rule_name(rule, expr, block, uvar, var, svar, call, rule.quantifier);

        }

    }
    return {svar, uvar, var, shadow_var, rule.quantifier};
}
LLIR_old::ConvertionResult LLIR_old::process_Rule_nospace(const TreeAPI::RuleMember &rule) {
    addSpaceSkip = false;
    if (members.size() > 0) {
        // remove previous skip of spaces if it does exists
        for (auto rit = this->members.rbegin(); rit != this->members.rend(); rit++) {
            if (rit->type == LLIR_old::types::SKIP_SPACES) {
                this->members.erase(rit.base());
                break;
            }
        }
    }
    return {};
}
LLIR_old::ConvertionResult LLIR_old::process_Rule_escaped(const TreeAPI::RuleMember &rule) {
    //cpuf::printf("Rule_escaped\n");
    const auto &escaped_c = rule.getEscaped();

    std::vector<LLIR_old::expr> expression;
    switch (escaped_c.c) {
        case 's':
            // do not add skip of spaces
            addSpaceSkip = false;
            if (data.size() > 0) {
                // remove previous skip of spaces if it does exists
                for (auto rit = this->members.rbegin(); rit != this->members.rend(); rit++) {
                    if (rit->type == LLIR_old::types::SKIP_SPACES) {
                        this->members.erase(rit.base());
                        break;
                    }
                }
            }
            //cpuf::printf("ON_EXPRESSION\n");
            expression = {
                {LLIR_old::condition_types::CURRENT_CHARACTER, (size_t) 0},
                {LLIR_old::condition_types::NOT_EQUAL},
                {LLIR_old::condition_types::CHARACTER, ' '}
            };
            break;
        default:
            throw Error("Undefined char '%c'", escaped_c);

    }
    //cpuf::printf("escaped_open\n");
    auto uvar = !rule.prefix.name.empty() ? createEmptyVariable(rule.prefix.name) : createEmptyVariable("");
    auto var = createEmptyVariable(generateVariableName());
    auto svar = createSuccessVariable();
    var.type = {LLIR_old::var_types::CHAR};
    std::vector<LLIR_old::member> block = {{LLIR_old::types::EXIT}};
    if (!isFirst) {
        block.insert(block.begin(), {LLIR_old::types::ERR, getErrorName(rule)});
    }
    auto block_after = createDefaultBlock(var, svar);
    push({LLIR_old::types::VARIABLE, var});
    push({LLIR_old::types::VARIABLE, svar});
    auto shadow_var = pushBasedOnQualifier(rule, expression, block, uvar, var, svar, rule.quantifier);
    push({LLIR_old::types::IF, LLIR_old::condition{expression, block}});
    add(block_after);
    //cpuf::printf("escaped_close\n");
    return {svar, uvar, var, shadow_var, rule.quantifier};
}
LLIR_old::ConvertionResult LLIR_old::process_Rule_any(const TreeAPI::RulePrefix &prefix) {
    //cpuf::printf("Rule_any\n");
    auto var = prefix.name.empty() ? createEmptyVariable(generateVariableName()) : createEmptyVariable(prefix.name);
    auto svar = createSuccessVariable();
    var.type = {isToken ? LLIR_old::var_types::CHAR : LLIR_old::var_types::Token};
    std::vector<LLIR_old::expr> expression;
    std::vector<LLIR_old::member> block = {{LLIR_old::types::EXIT}};
    if (!isFirst) {
        auto rm = TreeAPI::RuleMember {.value = TreeAPI::RuleMemberAny() };
        block.insert(block.begin(), LLIR_old::member {LLIR_old::types::ERR, getErrorName(rm)});
    }
    std::vector<LLIR_old::member> block_after = createDefaultBlock(var, svar);
    if (isToken) {
        expression = {
            {LLIR_old::condition_types::CURRENT_CHARACTER, (size_t) 0},
            {LLIR_old::condition_types::EQUAL},
            isToken ?
            LLIR_old::expr {LLIR_old::condition_types::ESCAPED_CHARACTER, '0'}
            :
            LLIR_old::expr {LLIR_old::condition_types::CURRENT_TOKEN, "NONE"}
        };
    } else {

    }

    push({LLIR_old::types::VARIABLE, var});
    push({LLIR_old::types::VARIABLE, svar});
    push({LLIR_old::types::IF, LLIR_old::condition{expression, block}});
    add(block_after);
    return {svar, {}, var};
}
std::vector<LLIR_old::member> LLIR_old::convert_op_rule(const std::vector<TreeAPI::RuleMember> &rules, size_t index, LLIR_old::variable &var, LLIR_old::variable &svar) {
    //[[assume(rules.size() >= 2)]];
    if (index >= rules.size()) {
        return {{LLIR_old::types::EXIT}};
    }

    LLIR_old::ConvertionResult success_var;
    std::vector<std::vector<LLIR_old::member>> blocks;
    std::vector<std::vector<LLIR_old::expr>> conditions;
    auto rule = rules[index++];
    LLIR_old new_ir(tree, -1, false);
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
        new_ir.members.back().type = LLIR_old::types::RESET_POS_COUNTER; // remove space skip
        auto cond = LLIR_old::condition {
            std::vector<LLIR_old::expr> {
                {LLIR_old::condition_types::NOT}, {LLIR_old::condition_types::VARIABLE, LLIR_old::var_refer {.var = success_var.svar}}
            },
            convert_op_rule(rules, index, var, svar),
        };
        auto v = !success_var.shadow_var.name.empty() && var.type.type != LLIR_old::var_types::STRING ? success_var.shadow_var : success_var.var;
        auto assign_type = v.type.type == LLIR_old::var_types::STRING ? LLIR_old::var_assign_types::ADD : LLIR_old::var_assign_types::ASSIGN;
        if (!v.name.empty() && v.type.type != LLIR_old::var_types::UNDEFINED) {
            cond.else_block = {{
                LLIR_old::types::ASSIGN_VARIABLE,
                LLIR_old::variable_assign
                {
                    var.name,
                    LLIR_old::var_assign_types::ASSIGN,
                    LLIR_old::assign {
                        LLIR_old::var_assign_values::VAR_REFER,
                        LLIR_old::var_refer {.var = v }
                    }
                }
            }};
        }
        new_ir.push({LLIR_old::types::IF, cond});
    } else {
        for (int i = 0; i < new_ir.members.size(); i++) {
            auto &el = new_ir.members[i];
            if (el.type == LLIR_old::types::IF) {
                auto val = std::any_cast<LLIR_old::condition>(el.value);
                // get recursively nested block
                val.block = convert_op_rule(rules, index, var, svar);
                // change condition and remove it's content into else blocks
                for (int j = i + 1; j < new_ir.members.size(); j++) {
                    auto el = new_ir.members[j];
                    erase_indices.push_back(j);
                    if (el.type != LLIR_old::types::SKIP_SPACES) {
                        if (el.type == LLIR_old::types::ASSIGN_VARIABLE) {
                            auto assignment = std::any_cast<LLIR_old::variable_assign>(el.value);
                            assignment.assign_type = LLIR_old::var_assign_types::ASSIGN;
                            el.value = assignment;
                        }
                        val.else_block.push_back(el);
                    }
                }
                // push into else block an assignment to variable
                if (var.type.type == LLIR_old::var_types::ARRAY) {
                    val.else_block.push_back({LLIR_old::types::METHOD_CALL, LLIR_old::method_call { var.name, {LLIR_old::function_call {"push", {std::vector<std::vector<LLIR_old::expr>> {{LLIR_old::expr {LLIR_old::condition_types::VARIABLE, LLIR_old::var_refer {.var = success_var.var}}}}}}}}});
                } else {
                    auto v = !success_var.shadow_var.name.empty() && var.type.type != LLIR_old::var_types::STRING ? success_var.shadow_var : success_var.var;
                    auto assign_type = v.type.type == LLIR_old::var_types::STRING ? LLIR_old::var_assign_types::ADD : LLIR_old::var_assign_types::ASSIGN;
                    val.else_block.push_back({
                        LLIR_old::types::ASSIGN_VARIABLE,
                        LLIR_old::variable_assign
                        {
                            var.name,
                            LLIR_old::var_assign_types::ASSIGN,
                            LLIR_old::assign {
                                LLIR_old::var_assign_values::VAR_REFER,
                                LLIR_old::var_refer {.var = v}
                            }
                        }
                    });
                }

                // update the value
                el.value = val;
            }
        }
    }

    for (auto it = erase_indices.rbegin(); it != erase_indices.rend(); ++it) {
        new_ir.members.erase(new_ir.members.begin() + *it);
    }
    return new_ir.members;
}

LLIR_old::ConvertionResult LLIR_old::process_Rule_op(const TreeAPI::RuleMember &rule) {
    // cpuf::printf("Rule_op\n");
    auto &rules = rule.getOp();
    auto uvar = !rule.prefix.name.empty() ? createEmptyVariable(rule.prefix.name) : createEmptyVariable("");
    auto var = createEmptyVariable(generateVariableName());
    auto svar = createSuccessVariable();
    auto block = createDefaultBlock(var, svar);
    // cpuf::printf("op prefix: %$\n", rule.prefix);
    // Add success variable
    var.type = {deduceVarTypeByProd(rule)};
    if (insideLoop && var.type.type != LLIR_old::var_types::STRING) {
        var.type.templ = {{var.type.type}};
        var.type.type = LLIR_old::var_types::ARRAY;
    }
    if (var.type.type != LLIR_old::var_types::UNDEFINED) {
        push({LLIR_old::types::VARIABLE, var});
    }
    push({LLIR_old::types::VARIABLE, svar});
    if (!uvar.name.empty()) {
        uvar.type = var.type;
        push({LLIR_old::types::VARIABLE, uvar});
    }
    const auto res = convert_op_rule(rules.options, 0, var, svar);
    add(res);
    block.erase(block.begin()); // remove variable assignment (it is done in else blocks)
    block.erase(block.end() - 1);
    // Append default block
    add(block);
    const auto shadow_var = createEmptyVariable("");
    if (!uvar.name.empty())
        push(createAssignUvarBlock(uvar, var, shadow_var));
    return {svar, uvar, var, {}, rule.quantifier};
}
void LLIR_old::process_cll_var(const TreeAPI::CllVar &var) {
    // get data section
    LLIR_old::var_type ir_type;
    LLIR_old::var_assign_types assign_types;
    LLIR_old::assign assign;
    if (!var.type.type.empty())
        ir_type = cllTreeTypeToIR(var.type);
    if (var.op != '\0') {
        assign_types = TreeOpToIR(var.op);
        assign = {LLIR_old::var_assign_values::EXPR, TreeExprToIR(var.value)};
    }
    if (!var.type.type.empty()) {
        LLIR_old::variable v = {var.name, ir_type, assign};
        push({LLIR_old::types::VARIABLE, v});
        vars.push_back(v);
    } else {
        push({LLIR_old::types::ASSIGN_VARIABLE, LLIR_old::variable_assign {var.name, assign_types, assign}});
    }
}
LLIR_old::condition LLIR_old::process_cll_if(const TreeAPI::CllIf &cond) {
    auto block_ir = rulesToIr(cond.stmt);
    variable_count = block_ir.variable_count;
    LLIR_old::condition condition;
    condition.expression = TreeExprToIR(cond.expr);
    condition.block.assign(block_ir.members.begin(), block_ir.members.end());
    return condition;
}
LLIR_old::ConvertionResult LLIR_old::process_cll(const TreeAPI::Cll &cll) {
    addSpaceSkip = false;
    LLIR_old::condition cond;
    if (cll.isVar()) {
        process_cll_var(cll.getVar());
    } else if (cll.isIf()) {
        process_cll_if(cll.getIf());
    } else if (cll.isExpr()) {
        // ignore right now, has no side effects
    } else throw Error("Undefined cll entry");
    return {{}, {}};
}

void LLIR_old::ruleToIr(const TreeAPI::RuleMember &rule) {
    addSpaceSkip = true;
    LLIR_old::ConvertionResult success_var;
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
    } else if (rule.empty()) {
        throw Error("Empty rule in %$", fullname);
    } else throw Error("Undefined rule");
    if (rule.prefix.is_key_value) {
        if (rule.prefix.name.empty()) {
            unnamed_datablock_units.push_back(success_var.uvar.name.empty() ? (success_var.shadow_var.name.empty() ? success_var.var : success_var.shadow_var) : success_var.uvar);
        } else {
            key_vars.emplace_back(rule.prefix.name, success_var.uvar);
        }
    }
    const auto insert_var = [this](const LLIR_old::variable &var) {
        if (!var.name.empty())
            vars.push_back(var);
    };
    insert_var(success_var.uvar);
    insert_var(success_var.svar);
    insert_var(success_var.var);
    insert_var(success_var.shadow_var);
    isFirst = false;
    if (addSpaceSkip)
        push({LLIR_old::types::SKIP_SPACES, isToken});
    success_vars.push_back(success_var);
}
LLIR_old LLIR_old::rulesToIr(const std::vector<TreeAPI::RuleMember> &rules) {
    LLIR_old result(tree, -1, false);
    result.proceed(*this);
    size_t pos = 0;
    for (const auto &rule : rules) {
        if (rule.empty())
            continue;
        result.symbol_follow.emplace_back(std::vector<std::string> {}, getNextTerminal(rules, pos));
        result.ruleToIr(rule);
        result.symbol_follow.pop_back();
        pos++;
    }
    return result;
}
LLIR_old LLIR_old::rulesToIr(const std::vector<TreeAPI::RuleMember> &rules, bool &addSpaceSkipFirst) {
    LLIR_old result(tree, -1, false);
    result.proceed(*this);
    bool isFirst = true;
    size_t pos = 0;
    for (const auto &rule : rules) {
        if (rule.empty())
            continue;
        result.symbol_follow.emplace_back(std::vector<std::string> {}, getNextTerminal(rules, pos));
        result.ruleToIr(rule);
        result.symbol_follow.pop_back();
        if (isFirst)
            addSpaceSkipFirst = result.addSpaceSkip;
        isFirst = false;
        pos++;
    }
    return result;
}
void LLIR_old::treeToIr() {
    for (auto &[name, value] : tree->getRawAst().getTreeMap()) {
        bool isToken = corelib::text::isUpper(name.back());
        fullname = name;
        bool to_add = true;
        if (tokensOnly != -1 && ((isToken && !tokensOnly) || (!isToken && tokensOnly))) {
            to_add = false;
        }
        this->isToken = isToken;
        if (to_add) {
            auto values = rulesToIr(value.members);
            if (!values.members.empty() && values.members.back().type == LLIR_old::types::SKIP_SPACES)
                values.pop(); // remove skip of spaces at the end
            data.push_back({values.createDataBlock(value.data_block), fullname, values.members});
        }
        clear_thread();
    }
}
LLIR_old::inclosed_map LLIR_old::getInclosedMapFromKeyValueBinding() {
    inclosed_map map;
    for (const auto &[name, variable] : key_vars) {
        map.try_emplace(name, std::vector<LLIR_old::expr> {LLIR_old::expr {LLIR_old::condition_types::VARIABLE, LLIR_old::var_refer {.var = variable}}}, variable.type);
    }
    return map;
}
LLIR_old::DataBlock LLIR_old::createDataBlock(const TreeAPI::DataBlock &data_block) {
    LLIR_old::DataBlock block;
    if (data_block.empty()) {
        return block;
    }
    if (data_block.isRegularDataBlock()) {
        if (data_block.isWithKeys()) {
            LLIR_old::inclosed_map initial_map = getInclosedMapFromKeyValueBinding();
            const auto &key_based_data_block = data_block.getRegDataBlockWKeys();
            for (const auto &[name, expr] : key_based_data_block.value) {
                initial_map.try_emplace(name, TreeExprToIR(expr), deduceTypeFromExpr(expr));
            }
            block.value = initial_map;
        } else {
            Assert(key_vars.empty(), "Key variable in expression-only data block");
            auto type = deduceTypeFromExpr(data_block.getRegDataBlock());
            if (type.type == LLIR_old::var_types::Rule_result) {
                type.type = LLIR_old::var_types::Rule;
            } else if (type.type == LLIR_old::var_types::Token_result) {
                type.type = LLIR_old::var_types::Token;
            }
            block.value = std::make_pair(TreeExprToIR(data_block.getRegDataBlock()), type);
        }
    } else {
        // templated data block
        LLIR_old::inclosed_map initial_map = getInclosedMapFromKeyValueBinding();
        const auto &templated_datablock = data_block.getTemplatedDataBlock();
        for (const auto &name : templated_datablock.names) {
            Assert(!unnamed_datablock_units.empty(), "More keys than values in rule %$", fullname);
            auto type = unnamed_datablock_units.front().type;
            if (type.type == LLIR_old::var_types::Rule_result) {
                type.type = LLIR_old::var_types::Rule;
            } else if (type.type == LLIR_old::var_types::Token_result) {
                type.type = LLIR_old::var_types::Token;
            }
            initial_map.try_emplace(name, std::vector<LLIR_old::expr> {LLIR_old::expr {condition_types::VARIABLE, var_refer {.var = unnamed_datablock_units.front()}}}, type);
            unnamed_datablock_units.erase(unnamed_datablock_units.begin());
        }
        block.value = initial_map;
    }
    return block;
}