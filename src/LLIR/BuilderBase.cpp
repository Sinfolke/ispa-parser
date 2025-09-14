module LLIR.Builder.Base;
import logging;
import corelib;
import LLIR;
import cpuf.printf;
import std;
#include <queue>

auto LLIR::BuilderBase::getData() -> Statements & {
    return statements;
}
auto LLIR::BuilderBase::getData() const -> const Statements & {
    return statements;
}
auto LLIR::BuilderBase::getReturnVars() const -> const stdu::vector<LLIR::ConvertionResult> & {
    return return_vars;
}
auto LLIR::BuilderBase::createEmptyVariable(const std::string &name) -> Variable {
    return Variable {.name = name};
}
void LLIR::BuilderBase::processExitStatements(Statements &values) {
    for (auto &el : values) {
        if (el.isExpression()) {
            auto &expr = el.getExpression();
            if (expr.size() == 1 && expr.back().isReturn()) {
                expr.back() = Break::createExpression(Break {});
            }
        }
        if (el.isIf()) {
            auto &condition = el.getIf();

            // Process the block and else block of the condition recursively
            processExitStatements(condition.stmt);
            processExitStatements(condition.else_stmt);
        } else if (el.isWhile() || el.isDoWhile()) {
            auto &condition = el.getWhileOrDoWhile();

            // Process the block and else block of the condition recursively
            processExitStatements(condition.stmt);
        }
    }
}
auto LLIR::BuilderBase::generateVariableName(std::size_t &variable_count) -> std::string {
    return std::string("_") + std::to_string(variable_count++);
}
auto LLIR::BuilderBase::createSuccessVariable(std::size_t &variable_count) -> Variable {
    Variable var = createEmptyVariable("success" + generateVariableName(variable_count));
    var.value = Bool::createRValue(false);
    return Variable {"success" + generateVariableName(variable_count), Bool::createRValue(false)};
}
auto LLIR::BuilderBase::generateVariableName() -> std::string {
    return generateVariableName(*variable_count);
}
auto LLIR::BuilderBase::createSuccessVariable() -> Variable {
    return createSuccessVariable(*variable_count);
}
auto LLIR::BuilderBase::createAssignUvarBlock(const Variable &uvar, const Variable &var, const Variable &shadow_var) -> Statement {
    return !uvar.name.empty()
        ?
            VariableAssignment::createStatement(VariableAssignment {
                .name = uvar.name,
                .value = Symbol::createExpression(Symbol {
                    .path = {shadow_var.name.empty() ? var.name : shadow_var.name }
                })
            })
        :
            Statement {};
}
void LLIR::BuilderBase::handle_plus_qualifier(const AST::RuleMember &rule, LLIR::ConditionalElement loop, const Variable &uvar, const Variable &var, Variable &shadow_var, bool addError) {
    auto postCheckVar = createSuccessVariable();
    loop.stmt.push_back(VariableAssignment::createStatement(VariableAssignment {.name = postCheckVar.name, .value = Bool::createRValue(true)}));
    push({LLIR::types::VARIABLE, postCheckVar});
    push({LLIR::types::WHILE, loop});
    addPostLoopCheck(rule, postCheckVar, addError);
}
void LLIR::BuilderBase::addPostLoopCheck(const AST::RuleMember &rule, const Variable &var, bool addError) {
    auto stmt = Return::createStatements(Return {});
    if (addError && !*isFirst) {
        stmt.insert(stmt.begin(), ReportError { .message = getErrorName(rule) });
    }
    If post_loop_condition;
    post_loop_condition.expr = { { .value =  { ExpressionElement::NOT, Symbol::createExpressionValue(Symbol { .path = { var.name }}) } } };
    post_loop_condition.stmt = std::move(stmt);
    statements.push_back(If::createStatement(post_loop_condition));
}
auto LLIR::BuilderBase::createDefaultBlock(const Variable &var, const Variable &svar) -> Statements {
    if (var.value.isChar()) {
        return VariableAssignment::createStatements(VariableAssignment {.name = var.name, .value = Pos::createExpression(Pos {.dereference = true})});
    } else {
        return {
            VariableAssignment::createStatement(VariableAssignment { .name = var.name, .type = OperatorType::Add, .value = Pos::createExpression(Pos {.sequence = true}) }),
            VariableAssignment::createStatement(VariableAssignment { .name = svar.name, .value = Bool::createExpression(true)}),
            Expression::createStatement(increasePos())
        };
    }
}
auto LLIR::BuilderBase::createDefaultBlock(const Variable &svar) -> Statements {
    return {
        VariableAssignment::createStatement(VariableAssignment { .name = svar.name, .value = Bool::createExpression(true)}),
        Expression::createStatement(increasePos())
    };
}
auto LLIR::BuilderBase::createDefaultBlock() -> Statements {
    return Expression::createStatements(increasePos());
}
auto LLIR::BuilderBase::createDefaultCall(Statements &block, Variable var, const std::string &name, Expression &expr) -> Statement  { // var must be copy
    FunctionCall function_call = {.name = name, .args = {Pos::createExpression(Pos {.sequence = true}) }};
    VariableAssignment assignment = {
        .name = var.name,
        .value = FunctionCall::createExpression(function_call)
    };
    expr =StorageSymbol::createExpression(StorageSymbol {.what = Symbol::createExpression(Symbol {.path = {var.name }}), {{"status"}}});;
    return VariableAssignment::createStatement(assignment);
}
auto LLIR::BuilderBase::add_shadow_variable(stdu::vector<Statement> &block, const Variable &var) -> Variable {
    Variable shadow_var = createEmptyVariable("shadow" + generateVariableName());
    auto type = var.type;
    if (type.type == LLIR::var_types::Rule_result)
        type.type = LLIR::var_types::Rule;
    else if (type.type == LLIR::var_types::Token_result)
        type.type = LLIR::var_types::Token;
    shadow_var.type = {LLIR::var_types::ARRAY, {type}};
    push({LLIR::types::VARIABLE, shadow_var});
    block.push_back({LLIR::types::METHOD_CALL, LLIR::method_call { shadow_var.name, {LLIR::function_call {"push", {stdu::vector<stdu::vector<LLIR::expr>> {{LLIR::expr {LLIR::condition_types::VARIABLE, LLIR::var_refer {.var = var}}}}}}}}});
    return shadow_var;
}

auto LLIR::BuilderBase::pushBasedOnQualifier(
    const AST::RuleMember &rule,
    stdu::vector<LLIR::expr> &expr,
    stdu::vector<Statement> &block,
    Variable &uvar,
    const Variable &var,
    const Variable &svar,
    char quantifier,
    bool add_shadow_var
) -> Variable {
    //block.push_back({LLIR::types::ASSIGN_VARIABLE, Variable_assign {svar.name, LLIR::var_assign_types::ASSIGN, LLIR::var_assign_values::_TRUE}});
    Variable shadow_variable;
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
            handle_plus_qualifier(rule, LLIR::condition {expr, block}, uvar, var, shadow_variable);
            break;
        case '*': {
            push({LLIR::types::WHILE, LLIR::condition{expr, block}});
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
            stdu::vector<Statement> blk = {{LLIR::types::EXIT}};
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
void LLIR::BuilderBase::pushConvResult(const AST::RuleMember &rule, const Variable &var, const Variable &uvar, const Variable &svar, const Variable &shadow_var, char quantifier) {
    const auto insert_var = [this](const Variable &var) {
        if (!var.name.empty()) {
            vars->push_back(var);
        }
    };
    const auto v_or_empty = [this](const Variable &var) -> Variable {
        if (!var.name.empty() && var.type.type != LLIR::var_types::UNDEFINED) {
            return var;
        }
        return {};
    };
    insert_var(uvar);
    insert_var(svar);
    insert_var(var);
    insert_var(shadow_var);
    if (rule.prefix.is_key_value) {
        if (rule.prefix.name.empty()) {
            unnamed_datablock_units->push_back(uvar.name.empty() ? (shadow_var.name.empty() ? var : shadow_var) : uvar);
        } else {
            key_vars->emplace_back(rule.prefix.name, uvar);
        }
    }
    return_vars.push_back({v_or_empty(svar), v_or_empty(uvar), v_or_empty(var), v_or_empty(shadow_var), quantifier});
}


bool LLIR::BuilderBase::compare_templ(const stdu::vector<LLIR::var_type>& templ1, const stdu::vector<LLIR::var_type>& templ2) {
    if (templ1.size() != templ2.size()) return false;

    for (std::size_t i = 0; i < templ1.size(); ++i) {
        if (templ1[i].type != templ2[i].type) return false;
        if (!compare_templ(templ1[i].templ, templ2[i].templ)) return false;  // Recursively compare nested `templ`
    }
    return true;
}
auto LLIR::BuilderBase::increasePos() -> Expression {
    return {Pos::createExpressionValue(Pos{}), ExpressionValue {.value = ExpressionElement::PlusPlus}};
}

auto LLIR::BuilderBase::CllTypeToIR(const AST::CllType &type) -> LLIR::var_type {
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
auto LLIR::BuilderBase::CllCompareOpToExpr(const AST::CllCompareOp &op) -> expr {
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
auto LLIR::BuilderBase::CllLogicalOpToIR(const AST::CllLogicalOp &lop) -> LLIR::condition_types {
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
auto LLIR::BuilderBase::assignSvar(const variable &svar, var_assign_values value) -> Statement {
    return {types::ASSIGN_VARIABLE, Variable_assign {
            svar.name, var_assign_types::ASSIGN, LLIR::assign {
                var_assign_values::True,
            }
        }
    };
}


auto LLIR::BuilderBase::getNextTerminal(stdu::vector<AST::RuleMember> symbols, std::size_t pos) -> std::set<stdu::vector<std::string>> {
    std::set<stdu::vector<std::string>> terminals;
    bool found_terminal = false;

    for (std::size_t i = pos + 1; i < symbols.size(); ++i) {
        const auto& sym = symbols[i];
        if (!sym.isName()) {
            continue; // skip non-names
        }

        const auto& n = sym.getName();

        if (corelib::text::isUpper(n.name.back())) {
            // It's a terminal
            terminals.insert({ n.name });
            found_terminal = true;
        } else {
            // Nonterminal: insert its FIRST set
            const auto& firsts = tree->getFirstSet().at(n.name);
            bool has_epsilon = false;
            for (const auto& seq : firsts) {
                if (seq.empty()) {
                    has_epsilon = true;
                } else {
                    terminals.insert(seq);
                    found_terminal = true;
                }
            }

            if (!has_epsilon) {
                break;
            }
        }

        // If this is not optional, break after processing it
        if (sym.quantifier != '?' && sym.quantifier != '*') {
            break;
        }
    }

    if (!found_terminal) {
        // Fallback to FOLLOW set of the current symbol
        if (corelib::text::isUpper(symbols[pos].getName().name.back())) {
            return {symbols[pos].getName().name};
        }
        const auto& follow = tree->getFollowSet()[symbols[pos].getName().name];
        terminals.insert(follow.begin(), follow.end());
    }

    return terminals;
}
auto LLIR::BuilderBase::getErrorName(const AST::RuleMember &rule) -> std::string {
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

        stdu::vector<std::string> parts;

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
            for (std::size_t i = 0; i < parts.size(); ++i) {
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
                    result += std::tolower(char_part);
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
auto LLIR::BuilderBase::getLookaheadTerminals(const AST::RuleMember& symbol, const stdu::vector<std::string> &lhs_name) -> LLIR::BuilderData::SymbolFollow {
    const auto& symbol_name = symbol.getName();
    const auto& use_places = tree->getUsePlacesTable()[symbol_name.name];
    const auto& first_set = tree->getFirstSet();
    const auto& follow_set = tree->getFollowSet();

    LLIR::BuilderData::SymbolFollow result;

    for (const auto& use_place : use_places) {
        const auto& rule = tree->getTreeMap()[use_place];
        const auto& rhs = rule.rule_members;

        for (auto it = rhs.begin(); it != rhs.end(); ++it) {
            if (!it->isName() || it->getName().name != symbol_name.name)
                continue;

            // Begin collecting lookahead tokens
            stdu::vector<stdu::vector<std::string>> sequences;

            auto next = it + 1;

            while (next != rhs.end()) {
                if (!next->isName()) {
                    ++next;
                    continue;
                }

                const auto& next_name = next->getName();

                if (corelib::text::isUpper(next_name.name.back())) {
                    // Terminal: one token sequence
                    sequences.push_back({ next_name.name });
                    break;
                } else {
                    // Nonterminal: expand FIRST set
                    const auto& firsts = first_set.at(next_name.name);
                    bool epsilon_included = false;

                    for (const auto& seq : firsts) {
                        if (seq.empty()) {
                            epsilon_included = true;
                        } else {
                            sequences.push_back(seq);
                        }
                    }

                    if (!epsilon_included) break;
                    ++next;
                }
            }

            if (next == rhs.end()) {
                // We're at the end of the rule body — use FOLLOW of the rule LHS
                if (corelib::text::isUpper(lhs_name.back())) {
                    sequences.push_back({lhs_name});
                } else {
                    try {
                        const auto& follows = follow_set.at(lhs_name);
                        for (const auto& seq : follows) {
                            sequences.push_back(seq);
                        }
                    } catch (...) {}
                }
            }

            result.emplace_back(use_place, std::set(sequences.begin(), sequences.end()));
        }
    }

    return result;
}


auto LLIR::BuilderBase::deduceUvarType(const Variable &var, const Variable &shadow_var) -> LLIR::var_type {
    return shadow_var.name.empty() ? var.type : shadow_var.type;
}
auto LLIR::BuilderBase::deduceVarTypeByProd(const AST::RuleMember &mem) -> LLIR::var_type {
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

void LLIR::BuilderBase::getVariablesToTable(stdu::vector<Statement>& data, stdu::vector<Statement>& table, std::string& var_name, bool retain_value, bool recursive) {
    for (std::size_t i = 0; i < data.size(); /* manual increment */) {
        if (data[i].type == LLIR::types::VARIABLE) {
            auto variable = std::any_cast<Variable>(data[i].value);
            if (!var_name.empty() && var_name != variable.name) {
                ++i;
                continue;
            }

            // Optionally retain value
            if (variable.value.kind != LLIR::var_assign_values::NONE && retain_value) {
                data.insert(data.begin() + i, Statement{
                    LLIR::types::ASSIGN_VARIABLE,
                    Variable_assign{variable.name, LLIR::var_assign_types::ASSIGN, variable.value}
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


void LLIR::BuilderBase::insertVariablesOnTop(stdu::vector<Statement> &insertPlace, stdu::vector<Statement>& table) {
    std::size_t i = 0;
    // cpuf::printf("Raise vars on top : table size %$\n", table.size());
    for (auto& el : table) {
        insertPlace.insert(insertPlace.begin() + i++, el);
    }
}

void LLIR::BuilderBase::raiseVarsTop(stdu::vector<Statement> &insertPlace, stdu::vector<Statement> &readPlace, std::string var_name, bool all_rule, bool retain_value, bool recursive) {
    stdu::vector<Statement> table;
    getVariablesToTable(readPlace, table, var_name, retain_value, recursive);
    insertVariablesOnTop(insertPlace, table);
}
void LLIR::BuilderBase::optimizeIR() {
    // cpuf::printf("Optimze IR\n");
    raiseVarsTop(statements, statements);
}

void LLIR::BuilderBase::push(Statement mem) {
    statements.push_back(mem);
}
void LLIR::BuilderBase::pop() {
    statements.pop_back();
}
void LLIR::BuilderBase::add(Statements block) {
    statements.insert(statements.end(), block.begin(), block.end());
}

