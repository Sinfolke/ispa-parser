module LLIRBuilderBase;
import logging;
import corelib;
import LLIR;
import CllBuilder;
import cpuf.printf;
import std;

auto LLIR::BuilderBase::getData() -> ::LLIR::Nodes & {
    return data;
}
auto LLIR::BuilderBase::getData() const -> const ::LLIR::Nodes & {
    return data;
}
auto LLIR::BuilderBase::getReturnVars() const -> const std::vector<LLIR::ConvertionResult> & {
    return return_vars;
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
auto LLIR::BuilderBase::generateVariableName() -> std::string {
    return generateVariableName(*variable_count);
}
auto LLIR::BuilderBase::createSuccessVariable() -> LLIR::variable {
    return createSuccessVariable(*variable_count);
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
void LLIR::BuilderBase::pushConvResult(const TreeAPI::RuleMember &rule, const LLIR::variable &var, const LLIR::variable &uvar, const LLIR::variable &svar, const LLIR::variable &shadow_var, char quantifier) {
    const auto insert_var = [this](const LLIR::variable &var) {
        if (!var.name.empty()) {
            vars->push_back(var);
        }
    };
    const auto v_or_empty = [this](const LLIR::variable &var) -> LLIR::variable {
        if (!var.name.empty() && var.type.type != LLIR::var_types::UNDEFINED) {
            return var;
        } else {
            return {};
        }
    };
    insert_var(uvar);
    insert_var(svar);
    insert_var(var);
    insert_var(shadow_var);
    if (rule.prefix.is_key_value) {
        if (rule.prefix.name.empty()) {
            cpuf::printf("Adding key to unnamed dtb of size {}", unnamed_datablock_units->size());
            unnamed_datablock_units->push_back(uvar.name.empty() ? (shadow_var.name.empty() ? var : shadow_var) : uvar);
        } else {
            key_vars->emplace_back(rule.prefix.name, uvar);
        }
    }
    return_vars.push_back({v_or_empty(svar), v_or_empty(uvar), v_or_empty(var), v_or_empty(shadow_var), quantifier});
}


bool LLIR::BuilderBase::compare_templ(const std::vector<LLIR::var_type>& templ1, const std::vector<LLIR::var_type>& templ2) {
    if (templ1.size() != templ2.size()) return false;

    for (size_t i = 0; i < templ1.size(); ++i) {
        if (templ1[i].type != templ2[i].type) return false;
        if (!compare_templ(templ1[i].templ, templ2[i].templ)) return false;  // Recursively compare nested `templ`
    }
    return true;
}

auto LLIR::BuilderBase::CllTypeToIR(const TreeAPI::CllType &type) -> LLIR::var_type {
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
        LLIR::var_type _template = CllTypeToIR(type.templ[0]);
        return {tp, {_template}};
    } else if (type.type == "obj") {
        LLIR::var_types tp = LLIR::var_types::OBJECT;
        LLIR::var_type _template1 = CllTypeToIR(type.templ[0]);
        LLIR::var_type _template2 = CllTypeToIR(type.templ[1]);
        return {tp, {_template1, _template2}};
    }
    throw Error("Undefined type");
}
auto LLIR::BuilderBase::CllOpToIR(const char op) -> LLIR::var_assign_types {
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
auto LLIR::BuilderBase::CllOpToExpr(const char op) -> LLIR::expr {
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
auto LLIR::BuilderBase::CllCompareOpToExpr(const TreeAPI::CllCompareOp &op) -> expr {
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
auto LLIR::BuilderBase::CllLogicalOpToIR(const TreeAPI::CllLogicalOp &lop) -> LLIR::condition_types {
    if (lop.isAnd)
        return {LLIR::condition_types::AND};
    return {LLIR::condition_types::OR};
}
LLIR::var_assign_types LLIR::BuilderBase::CllAssignmentOpToIR(const char op) {
    if (op == '\0')
        return LLIR::var_assign_types::ASSIGN;
    auto v = CllOpToIR(op);
    v = static_cast<LLIR::var_assign_types>(static_cast<int>(v) + static_cast<int>(LLIR::var_assign_types::ASSIGN));
    return v;
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
            return getErrorName(r.rule_members[0]);
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

void LLIR::BuilderBase::getVariablesToTable(std::vector<LLIR::member>& data, std::vector<LLIR::member>& table, std::string& var_name, bool retain_value, bool recursive) {
    for (size_t i = 0; i < data.size(); /* manual increment */) {
        if (data[i].type == LLIR::types::VARIABLE) {
            auto variable = std::any_cast<LLIR::variable>(data[i].value);
            if (!var_name.empty() && var_name != variable.name) {
                ++i;
                continue;
            }

            // Optionally retain value
            if (variable.value.kind != LLIR::var_assign_values::NONE && retain_value) {
                data.insert(data.begin() + i, LLIR::member{
                    LLIR::types::ASSIGN_VARIABLE,
                    LLIR::variable_assign{variable.name, LLIR::var_assign_types::ASSIGN, variable.value}
                });
                ++i; // skip over inserted assignment
            }

            // Move variable declaration to table
            table.push_back(data[i]);
            data.erase(data.begin() + i); // do NOT increment i, stay at current index
            if (!var_name.empty())
                break;
        } else if ((data[i].type == LLIR::types::IF || data[i].type == LLIR::types::WHILE || data[i].type == LLIR::types::DOWHILE) && recursive) {
            auto block = std::any_cast<LLIR::condition>(data[i].value);
            getVariablesToTable(block.block, table, var_name, retain_value, recursive);
            getVariablesToTable(block.else_block, table, var_name, retain_value, recursive);
            data[i].value = block;
            ++i;
        } else {
            ++i;
        }
    }
}


void LLIR::BuilderBase::insertVariablesOnTop(std::vector<LLIR::member> &insertPlace, std::vector<LLIR::member>& table) {
    size_t i = 0;
    // cpuf::printf("Raise vars on top : table size %$\n", table.size());
    for (auto& el : table) {
        insertPlace.insert(insertPlace.begin() + i++, el);
    }
}

void LLIR::BuilderBase::raiseVarsTop(std::vector<LLIR::member> &insertPlace, std::vector<LLIR::member> &readPlace, std::string var_name, bool all_rule, bool retain_value, bool recursive) {
    std::vector<LLIR::member> table;
    getVariablesToTable(readPlace, table, var_name, retain_value, recursive);
    insertVariablesOnTop(insertPlace, table);
}
void LLIR::BuilderBase::optimizeIR() {
    // cpuf::printf("Optimze IR\n");
    if (data.empty()) {
        raiseVarsTop(data, data);
    } else {
        // cpuf::printf("Optimze IR on non-empty data\n");
        for (auto &d : data) {
            raiseVarsTop(data, data);
        }
    }
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

