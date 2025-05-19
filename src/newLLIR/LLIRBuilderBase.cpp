module;
#include <ostream>
#include <any>
#include <algorithm>
#include <optional>
#include <vector>
#include <set>
module LLIRBuilderBase;
import logging;
import corelib;
import LLIR;
auto LLIR::BuilderBase::getData() -> ::LLIR::Nodes & {
    return data;
}
auto LLIR::BuilderBase::getData() const -> const ::LLIR::Nodes & {
    return data;
}
auto LLIR::BuilderBase::getReturnVars() const -> const std::vector<LLIR::ConvertionResult> & {
    return return_vars;
}

auto operator<<(std::ostream &os, const LLIR::BuilderBase &data) -> std::ostream& {
    data.print(os);
    return os;
}
auto LLIR::BuilderBase::createEmptyVariable(std::string name) -> LLIR::variable {
    LLIR::variable var {
        name,
        {LLIR::var_types::UNDEFINED},
        LLIR::var_assign_values::NONE,
    };
    return var;
}
void LLIR::BuilderBase::processExitStatements(std::vector<LLIR::member> &values) {
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
auto LLIR::BuilderBase::generateVariableName(size_t &variable_count) -> std::string {
    return std::string("_") + std::to_string(variable_count++);
}
auto LLIR::BuilderBase::createSuccessVariable(size_t &variable_count) -> LLIR::variable {
    LLIR::variable var = createEmptyVariable("success" + generateVariableName(variable_count));
    var.type = {LLIR::var_types::BOOLEAN};
    var.value = {LLIR::var_assign_values::False};
    return var;
}
auto LLIR::BuilderBase::createAssignUvarBlock(const LLIR::variable &uvar, const LLIR::variable &var, const LLIR::variable &shadow_var) -> LLIR::member {
    return !uvar.name.empty() ?
        LLIR::member {LLIR::types::ASSIGN_VARIABLE, LLIR::variable_assign {uvar.name, LLIR::var_assign_types::ASSIGN, {LLIR::var_assign_values::VAR_REFER, LLIR::var_refer {.var = shadow_var.name.empty() ? var : shadow_var}}}}
    :
        LLIR::member {LLIR::types::EMPTY};
}
void LLIR::BuilderBase::handle_plus_qualifier(const TreeAPI::RuleMember &rule, LLIR::condition loop, const LLIR::variable &uvar, const LLIR::variable &var, LLIR::variable &shadow_var, bool addError) {
    auto postCheckVar = createSuccessVariable();
    loop.block.push_back({LLIR::types::ASSIGN_VARIABLE, LLIR::variable_assign {postCheckVar.name, LLIR::var_assign_types::ASSIGN, LLIR::var_assign_values::True}});
    addPostLoopCheck(rule, postCheckVar, addError);
}
void LLIR::BuilderBase::addPostLoopCheck(const TreeAPI::RuleMember &rule, const LLIR::variable &var, bool addError) {
    std::vector<LLIR::member> block = {{ LLIR::types::EXIT }};
    if (addError && !*isFirst) {
        block.insert(block.begin(), { LLIR::types::ERR, getErrorName(rule)});
    }
    LLIR::condition check_cond = {
        {
            {LLIR::condition_types::NOT},
            { LLIR::condition_types::VARIABLE, LLIR::var_refer {.var = var}},
        },
        block
    };
    push({LLIR::types::IF, check_cond});
}
auto LLIR::BuilderBase::createDefaultBlock(const LLIR::variable &var, const LLIR::variable &svar) -> LLIR::Nodes {
    return {
        var.type.type == LLIR::var_types::CHAR ?
        LLIR::member {LLIR::types::ASSIGN_VARIABLE, LLIR::variable_assign {var.name, LLIR::var_assign_types::ASSIGN, LLIR::var_assign_values::CURRENT_CHARACTER}}
        :
        LLIR::member {LLIR::types::ASSIGN_VARIABLE, LLIR::variable_assign {var.name, LLIR::var_assign_types::ADD, LLIR::var_assign_values::CURRENT_POS_SEQUENCE}},
        {LLIR::types::ASSIGN_VARIABLE, LLIR::variable_assign {svar.name, LLIR::var_assign_types::ASSIGN, LLIR::var_assign_values::True}},
        {LLIR::types::INCREASE_POS_COUNTER}
    };
}
auto LLIR::BuilderBase::createDefaultBlock(const LLIR::variable &svar) -> LLIR::Nodes {
    return {
            {LLIR::types::ASSIGN_VARIABLE, LLIR::variable_assign {svar.name, LLIR::var_assign_types::ASSIGN, LLIR::var_assign_values::True}},
            {LLIR::types::INCREASE_POS_COUNTER}
    };
}
auto LLIR::BuilderBase::createDefaultBlock() -> LLIR::Nodes {
    return {
            {LLIR::types::INCREASE_POS_COUNTER}
    };
}
auto LLIR::BuilderBase::createDefaultCall(LLIR::Nodes &block, LLIR::variable &var, const std::string &name, LLIR::Expression &expr) -> LLIR::member  {
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
        {LLIR::condition_types::VARIABLE, LLIR::var_refer {.var = var}}
    };
    return {LLIR::types::ASSIGN_VARIABLE, var_assign};
}
auto LLIR::BuilderBase::add_shadow_variable(std::vector<LLIR::member> &block, const LLIR::variable &var) -> LLIR::variable {
    LLIR::variable shadow_var = createEmptyVariable("shadow" + generateVariableName());
    auto type = var.type;
    if (type.type == LLIR::var_types::Rule_result)
        type.type = LLIR::var_types::Rule;
    else if (type.type == LLIR::var_types::Token_result)
        type.type = LLIR::var_types::Token;
    shadow_var.type = {LLIR::var_types::ARRAY, {type}};
    push({LLIR::types::VARIABLE, shadow_var});
    block.push_back({LLIR::types::METHOD_CALL, LLIR::method_call { shadow_var.name, {LLIR::function_call {"push", {std::vector<std::vector<LLIR::expr>> {{LLIR::expr {LLIR::condition_types::VARIABLE, LLIR::var_refer {.var = var}}}}}}}}});
    return shadow_var;
}

auto LLIR::BuilderBase::pushBasedOnQualifier(
    const TreeAPI::RuleMember &rule,
    std::vector<LLIR::expr> &expr,
    std::vector<LLIR::member> &block,
    LLIR::variable &uvar,
    const LLIR::variable &var,
    const LLIR::variable &svar,
    char quantifier,
    bool add_shadow_var
) -> LLIR::variable {
    //block.push_back({LLIR::types::ASSIGN_VARIABLE, LLIR::variable_assign {svar.name, LLIR::var_assign_types::ASSIGN, LLIR::var_assign_values::_TRUE}});
    LLIR::variable shadow_variable;
    if ((*insideLoop || quantifier == '+' || quantifier == '*') && add_shadow_var) {
       shadow_variable = add_shadow_variable(block, var);
       add_shadow_var = false;
    }

    if (!uvar.name.empty()) {
        uvar.type = deduceUvarType(var, shadow_variable);
        push({LLIR::types::VARIABLE, uvar});
    }
    switch (quantifier) {
        case '+':
            if (add_shadow_var)
                shadow_variable = add_shadow_variable(block, var);
            handle_plus_qualifier(rule, LLIR::condition {expr, block}, uvar, var, shadow_variable);
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
            block.push_back(createAssignUvarBlock(uvar, var, shadow_variable));
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
    push(createAssignUvarBlock(uvar, var, shadow_variable));
    return shadow_variable;
}
bool LLIR::BuilderBase::compare_templ(const std::vector<LLIR::var_type>& templ1, const std::vector<LLIR::var_type>& templ2) {
    if (templ1.size() != templ2.size()) return false;

    for (size_t i = 0; i < templ1.size(); ++i) {
        if (templ1[i].type != templ2[i].type) return false;
        if (!compare_templ(templ1[i].templ, templ2[i].templ)) return false;  // Recursively compare nested `templ`
    }
    return true;
}
auto LLIR::BuilderBase::getNextTerminal(std::vector<TreeAPI::RuleMember> symbols, size_t pos) -> std::set<std::vector<std::string>> {
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
auto LLIR::BuilderBase::getErrorName(const TreeAPI::RuleMember &rule) -> std::string {
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
            const auto r = tree->getTreeMap()[name.name];
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
auto LLIR::BuilderBase::deduceUvarType(const LLIR::variable &var, const LLIR::variable &shadow_var) -> LLIR::var_type {
    return shadow_var.name.empty() ? var.type : shadow_var.type;
}
auto LLIR::BuilderBase::deduceVarTypeByProd(const TreeAPI::RuleMember &mem) -> LLIR::var_type {
    LLIR::var_type type = {LLIR::var_types::UNDEFINED};
    if (mem.isGroup()) {
        const auto &val = mem.getGroup().values;
        if (val.size() == 1) {
            type = deduceVarTypeByProd(val[0]);
        } else {
            for (auto i = 0; i < val.size(); i++) {
                if (deduceVarTypeByProd(val[i]).type != LLIR::var_types::STRING) {
                    return {LLIR::var_types::UNDEFINED};
                }
            }
            type = {LLIR::var_types::STRING};
        }
    } else if (mem.isOp()) {
        std::optional<LLIR::var_types> fLLIRst_type;
        char prev_quantifier = '\0';
        for (const auto &el : mem.getOp().options) {
            auto t = deduceVarTypeByProd(el).type;
            // if (t == LLIR::var_types::UNDEFINED)
            //     return {LLIR::var_types::UNDEFINED};
            if (!fLLIRst_type) {
                fLLIRst_type = t;
                prev_quantifier = el.quantifier;
            } else if (t != *fLLIRst_type || prev_quantifier != el.quantifier) {
                return {LLIR::var_types::ANY};
            }
        }
        type.type = fLLIRst_type.value_or(LLIR::var_types::UNDEFINED);
    } else if (mem.isName()) {
        type.type = corelib::text::isUpper(mem.getName().name.back()) ? LLIR::var_types::Token : LLIR::var_types::Rule;
    } else type.type = LLIR::var_types::STRING;
    return type;
}
auto LLIR::BuilderBase::deduceTypeFromRvalue(const TreeAPI::rvalue &value) -> LLIR::var_type {
    LLIR::var_type type = {LLIR::var_types::UNDEFINED};
    if (value.isString())
        type.type = LLIR::var_types::STRING;
    else if (value.isBoolean())
        type.type = LLIR::var_types::BOOLEAN;
    else if (value.isNumber())
        type.type = LLIR::var_types::NUMBER;
    else if (value.isID()) {
        // likely never execute
        auto find_it = std::find_if(vars->begin(), vars->end(), [&value](const LLIR::variable &var) { return var.name == value.getID().value; });
        if (find_it == vars->end())
            throw Error("Not found variable to deduce type from expr");
        if (find_it->type.type == LLIR::var_types::Rule_result)
            type = {LLIR::var_types::Rule};
        else if (find_it->type.type == LLIR::var_types::Token_result)
            type = {LLIR::var_types::Token};
        else type = find_it->type;
    } else if (value.isAt()) {
        if (unnamed_datablock_units->empty())
            throw Error("no more data accamulated with @");
        const auto &t = unnamed_datablock_units->front().type;
        if (t.type == LLIR::var_types::Rule_result)
            type = {LLIR::var_types::Rule};
        else if (t.type == LLIR::var_types::Token_result)
            type = {LLIR::var_types::Token};
        else type = t;
    } else if (value.isArray()) {
        LLIR::var_type types;
        for (const auto &el : value.getArray().value) {
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
        for (const auto &[key, value] : value.getObject().value) {
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
auto LLIR::BuilderBase::deduceTypeFromExprValue(const TreeAPI::CllExprValue &value) -> LLIR::var_type {
    if (value.isFunctionCall()) {
        // todo - get function call type
    } else if (value.isGroup()) {
        return deduceTypeFromExpr(value.getGroup());
    } else if (value.isMethodCall()) {
        // todo - get method call type
    } else if (value.isVariable()) {
        auto find_it = std::find_if(vars->begin(), vars->end(), [&value](const LLIR::variable &var) { return var.name == value.getVariable().name; });
        if (find_it == vars->end())
            throw Error("Not found variable to deduce type from expr");
        if (find_it->type.type == LLIR::var_types::Rule_result)
            return {LLIR::var_types::Rule};
        if (find_it->type.type == LLIR::var_types::Token_result)
            return {LLIR::var_types::Token};
        return find_it->type;
    } else if (value.isrvalue()) {
        return deduceTypeFromRvalue(value.getrvalue());
    } else
        throw Error("Undefined expr value member: %s in rule %s", value.value.type().name(), fullname);
    return {};
}
auto LLIR::BuilderBase::deduceTypeFromExprTerm(const TreeAPI::CllExprTerm &term) -> LLIR::var_type {
    // type is explicitly based on value. We may not check others in addition
    return deduceTypeFromExprValue(term.value);
}
auto LLIR::BuilderBase::deduceTypeFromExprAddition(const TreeAPI::CllExprAddition &addition) -> LLIR::var_type{
    // same as with term
    return deduceTypeFromExprTerm(addition.value);
}
auto LLIR::BuilderBase::deduceTypeFromExprCompare(const TreeAPI::CllExprCompare &compare) -> LLIR::var_type {
    // if any comparasion exists it is boolean
    if (compare.rights.size() != 0)
        return {LLIR::var_types::BOOLEAN};
    return deduceTypeFromExprAddition(compare.value);
}
auto LLIR::BuilderBase::deduceTypeFromExprLogical(const TreeAPI::CllExprLogical &logical) -> LLIR::var_type {
    // if &&/|| exists it is always boolean
    if (logical.rights.size() != 0)
        return {LLIR::var_types::BOOLEAN};
    return deduceTypeFromExprCompare(logical.value);
}
auto LLIR::BuilderBase::deduceTypeFromExpr(const TreeAPI::CllExpr &expr) -> LLIR::var_type {
    return deduceTypeFromExprLogical(expr.value);
}

void LLIR::BuilderBase::push(LLIR::member mem) {
    data.push_back(mem);
}
void LLIR::BuilderBase::pop() {
    data.pop_back();
}
void LLIR::BuilderBase::add(LLIR::Nodes block) {
    data.insert(data.end(), block.begin(), block.end());
}

