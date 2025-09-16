module LLIR.Builder.Base;
import logging;
import corelib;
import LLIR;
import cpuf.printf;
import std;

auto LLIR::BuilderBase::getData() -> Statements & {
    return statements;
}
auto LLIR::BuilderBase::getData() const -> const Statements & {
    return statements;
}
auto LLIR::BuilderBase::getReturnVars() const -> const stdu::vector<LLIR::ExportsAfterBuild> & {
    return exports_list;
}
auto LLIR::BuilderBase::createEmptyVariable(const std::string &name) -> Variable {
    return Variable {.name = name};
}
void LLIR::BuilderBase::processExitStatements(Statements &values) {
    for (auto &el : values) {
        if (el.isExpression()) {
            auto &expr = el.getExpression();
            if (expr.size() == 1 && expr.back().isReturn()) {
                expr = Break::createExpression(Break {});
                continue;
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
    return Variable {.name = "success" + generateVariableName(variable_count), .value = Bool::createRValue(false)};
}
auto LLIR::BuilderBase::generateVariableName() -> std::string {
    return generateVariableName(variable_count);
}
auto LLIR::BuilderBase::createSuccessVariable() -> Variable {
    return createSuccessVariable(variable_count);
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
void LLIR::BuilderBase::handle_plus_qualifier(const AST::RuleMember &rule, ConditionalElement loop, const Variable &uvar, const Variable &var, Variable &shadow_var, bool addError) {
    auto postCheckVar = createSuccessVariable();
    loop.stmt.push_back(VariableAssignment::createStatement(VariableAssignment {.name = postCheckVar.name, .value = Bool::createRValue(true)}));
    statements.push_back(Variable::createStatement(postCheckVar));
    statements.push_back(While::createStatement(loop));
    addPostLoopCheck(rule, postCheckVar, addError);
}
void LLIR::BuilderBase::addPostLoopCheck(const AST::RuleMember &rule, const Variable &var, bool addError) {
    auto stmt = Return::createStatements(Return {});
    if (addError && !isFirst) {
        stmt.insert(stmt.begin(), ReportError { .message = getErrorName(rule) });
    }
    If post_loop_condition;
    post_loop_condition.expr = { { .value =  { ExpressionElement::Not, Symbol::createExpressionValue(Symbol { .path = { var.name }}) } } };
    post_loop_condition.stmt = std::move(stmt);
    statements.push_back(If::createStatement(post_loop_condition));
}
auto LLIR::BuilderBase::createDefaultStatements(const Variable &var, const Variable &svar) -> Statements {
    if (var.type.type == ValueType::Char) {
        return VariableAssignment::createStatements(VariableAssignment {.name = var.name, .value = Pos::createExpression(Pos {.dereference = true})});
    } else {
        return {
            VariableAssignment::createStatement(VariableAssignment { .name = var.name, .type = OperatorType::Add, .value = Pos::createExpression(Pos {.sequence = true}) }),
            VariableAssignment::createStatement(VariableAssignment { .name = svar.name, .value = Bool::createExpression(true)}),
            Expression::createStatement(increasePos())
        };
    }
}
auto LLIR::BuilderBase::createDefaultStatements(const Variable &svar) -> Statements {
    return {
        VariableAssignment::createStatement(VariableAssignment { .name = svar.name, .value = Bool::createExpression(true)}),
        Expression::createStatement(increasePos())
    };
}
auto LLIR::BuilderBase::createDefaultStatements() -> Statements {
    return Expression::createStatements(increasePos());
}
auto LLIR::BuilderBase::createDefaultCall(Statements &block, const Variable &var, const std::string &name, Expression &expr) -> Statement  { // var must be copy
    FunctionCall function_call = {.name = name, .args = {Pos::createExpression(Pos {.sequence = true}) }};
    VariableAssignment assignment = {
        .name = var.name,
        .value = FunctionCall::createExpression(function_call)
    };
    expr = StorageSymbol::createExpression(StorageSymbol {.what = Symbol::createExpression(Symbol {.path = {var.name }}), {{"status"}}});;
    return VariableAssignment::createStatement(assignment);
}
auto LLIR::BuilderBase::add_shadow_variable(Statements &block, const Variable &var) -> Variable {
    Variable shadow_var = createEmptyVariable("shadow" + generateVariableName());
    if (var.type.type == ValueType::TokenResult) {
        shadow_var.type.type = ValueType::Token;
    } else if (var.type.type == ValueType::RuleResult) {
        shadow_var.type.type = ValueType::Rule;
    }
    shadow_var.type.template_parameters = {{shadow_var.type.type}};
    shadow_var.type.type = ValueType::Array;
    statements.push_back(Variable::createStatement(shadow_var));
    statements.push_back(
        StorageSymbol::createStatement(StorageSymbol {
                .what = Symbol::createExpression(Symbol {
                    .path = shadow_var.name
                }),
                .path = {
                    ArrayMethodCall {
                        .method = ArrayMethods::Push,
                        .args = {
                            Symbol::createExpression(Symbol {
                                .path = var.name
                            })
                        }
                    }
                }
        })
    );
    return shadow_var;
}

auto LLIR::BuilderBase::pushBasedOnQualifier(
    const AST::RuleMember &rule,
    Expression &expr,
    Statements &stmt,
    Variable &uvar,
    const Variable &var,
    const Variable &svar,
    char quantifier,
    bool add_shadow_var
) -> Variable {
    //block.push_back({LLIR::types::ASSIGN_VARIABLE, Variable_assign {svar.name, LLIR::var_assign_types::ASSIGN, LLIR::var_assign_values::_TRUE}});
    Variable shadow_variable;
    if ((insideLoop || quantifier == '+' || quantifier == '*') && add_shadow_var) {
       shadow_variable = add_shadow_variable(stmt, var);
       add_shadow_var = false;
    }

    if (!uvar.name.empty()) {
        uvar.type = deduceUvarType(var, shadow_variable);
        statements.push_back(Variable::createStatement(uvar));
    }
    switch (quantifier) {
        case '+':
            handle_plus_qualifier(rule, ConditionalElement {.expr = expr, .stmt = stmt}, uvar, var, shadow_variable);
            break;
        case '*': {
            statements.push_back(While::createStatement(While {expr, stmt}));
            break;
        }
        case '?':
            statements.push_back(If::createStatement(If {expr, stmt}));
            break;
        default:
            // add the negative into condition
            stmt.push_back(createAssignUvarBlock(uvar, var, shadow_variable));
            expr.insert(expr.begin(), ExpressionValue { .value = ExpressionElement::Not });
            expr.insert(expr.begin() + 1, ExpressionValue { .value = ExpressionElement::GroupOpen });
            expr.push_back(ExpressionValue {.value = ExpressionElement::GroupClose});
            // add exit statement
            Statements blk = Return::createStatements(Return {});
            if (!isFirst) {
                blk.insert(blk.begin(), ReportError::createStatement( ReportError { .message = getErrorName(rule)}));
            }
            statements.push_back(If::createStatement(If {expr, blk}));
            statements.insert(statements.end(), stmt.begin(), stmt.end());
            break;
    }
    statements.push_back(createAssignUvarBlock(uvar, var, shadow_variable));
    return shadow_variable;
}
void LLIR::BuilderBase::pushConvResult(const AST::RuleMember &rule, const Variable &var, const Variable &uvar, const Variable &svar, const Variable &shadow_var, char quantifier) {
    const auto insert_var = [this](const Variable &var) {
        if (!var.name.empty()) {
            vars.push_back(var);
        }
    };
    const auto v_or_empty = [this](const Variable &var) -> Variable {
        if (!var.name.empty() && var.type.type != ValueType::Undef) {
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
            unnamed_datablock_units.push_back(uvar.name.empty() ? (shadow_var.name.empty() ? var : shadow_var) : uvar);
        } else {
            key_vars.emplace_back(rule.prefix.name, uvar);
        }
    }
    exports_list.push_back(ExportsAfterBuild {v_or_empty(svar), v_or_empty(uvar), v_or_empty(var), v_or_empty(shadow_var), quantifier});
}
void LLIR::BuilderBase::undoRuleResult(ValueType &type) {
    if (type == ValueType::RuleResult)
        type = ValueType::Rule;
    if (type == ValueType::TokenResult)
        type = ValueType::Token;
}

auto LLIR::BuilderBase::getPrefixAsExpressionValue(const std::optional<char> &prefix) -> ExpressionValue {
    if (prefix.has_value()) {
        if (prefix.value() == '+')
            return ExpressionValue { .value = ExpressionElement::PlusPlus };
        else
            return ExpressionValue { .value = ExpressionElement::MinusMinus };
    }
    return ExpressionValue {};
}
void LLIR::BuilderBase::pushVariablePrefix(Expression &expr, const std::optional<char> &prefix) {
    if (prefix.has_value())
        expr.push_back(getPrefixAsExpressionValue(prefix));
}


bool LLIR::BuilderBase::compare_templ(const stdu::vector<Type>& templ1, const stdu::vector<Type>& templ2) {
    if (templ1.size() != templ2.size()) return false;

    for (std::size_t i = 0; i < templ1.size(); ++i) {
        if (templ1[i].type != templ2[i].type) return false;
        if (!compare_templ(templ1[i].template_parameters, templ2[i].template_parameters)) return false;
    }
    return true;
}
auto LLIR::BuilderBase::increasePos() -> Expression {
    return {Pos::createExpressionValue(Pos{}), ExpressionValue {.value = ExpressionElement::PlusPlus}};
}

auto LLIR::BuilderBase::CllTypeToIR(const AST::CllType &type) -> Type {
    if (type.type == "var")
        return {ValueType::Any, {}};
    if (type.type == "str")
        return {ValueType::String, {}};
    if (type.type == "bool")
        return {ValueType::Bool, {}};
    if (type.type == "num")
        return {ValueType::Int, {}};
    if (type.type == "arr") {
        ValueType tp = ValueType::Array;
        Type _template = CllTypeToIR(type.templ[0]);
        return {tp, {_template}};
    }
    if (type.type == "obj") {
        ValueType tp = ValueType::Map;
        Type _template1 = CllTypeToIR(type.templ[0]);
        Type _template2 = CllTypeToIR(type.templ[1]);
        return {tp, {_template1, _template2}};
    }
    throw Error("Undefined type");
}
auto LLIR::BuilderBase::CllOpToIR(const char op) -> OperatorType {
    // all other is single character so can use switch
    switch (op) {
        case '+':
            return OperatorType::Add;
        case '-':
            return OperatorType::Minus;
        case '*':
            return OperatorType::Multiply;
        case '/':
            return OperatorType::Divide;
        case '%':
            return OperatorType::Modulo;
        default:
            throw Error("Undefined operator");
    }
}
auto LLIR::BuilderBase::CllOpToExpr(const char op) -> ExpressionElement {
    switch (op) {
        case '+':
            return ExpressionElement::Add;
        case '-':
            return ExpressionElement::Minus;
        case '*':
            return ExpressionElement::Multiply;
        case '/':
            return ExpressionElement::Divide;
        case '%':
            return ExpressionElement::Modulo;
        default:
            throw Error("Undefined operator");
    }
}
auto LLIR::BuilderBase::CllCompareOpToExpr(const AST::CllCompareOp &op) -> ExpressionElement {
    if (op.op == "==")
        return ExpressionElement::Equal;
    if (op.op == "!=")
        return ExpressionElement::NotEqual;
    if (op.op == ">")
        return ExpressionElement::Higher;
    if (op.op == "<")
        return ExpressionElement::Lower;
    if (op.op == ">=")
        return ExpressionElement::HigherOrEqual;
    if (op.op == "<=")
        return ExpressionElement::LowerOrEqual;
    throw Error("undefined compare operator");
}
auto LLIR::BuilderBase::CllLogicalOpToIR(const AST::CllLogicalOp &lop) -> ExpressionElement {
    if (lop.isAnd)
        return ExpressionElement::And;
    return ExpressionElement::Or;
}
auto LLIR::BuilderBase::CllAssignmentOpToIR(const char op) -> OperatorType {
    if (op == '\0')
        return OperatorType::Assign;
    switch (op) {
        case '+':
            return OperatorType::Add;
        case '-':
            return OperatorType::Minus;
        case '*':
            return OperatorType::Multiply;
        case '/':
            return OperatorType::Divide;
        case '%':
            return OperatorType::Modulo;
        default:
            throw Error("Undefined operator");
    }
    return CllOpToIR(op);
}
auto LLIR::BuilderBase::assignSvar(const variable &svar, var_assign_values value) -> Statement {
    return VariableAssignment::createStatement(VariableAssignment {.name = svar.name, .value = Bool::createExpression(true)});
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
            const auto& firsts = tree.getFirstSet().at(n.name);
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
        const auto& follow = tree.getFollowSet()[symbols[pos].getName().name];
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
            const auto r = tree.getTreeMap()[name.name];
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
    const auto& use_places = tree.getUsePlacesTable()[symbol_name.name];
    const auto& first_set = tree.getFirstSet();
    const auto& follow_set = tree.getFollowSet();

    LLIR::BuilderData::SymbolFollow result;

    for (const auto& use_place : use_places) {
        const auto& rule = tree.getTreeMap()[use_place];
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


auto LLIR::BuilderBase::deduceUvarType(const Variable &var, const Variable &shadow_var) -> Type {
    return shadow_var.name.empty() ? var.type : shadow_var.type;
}
auto LLIR::BuilderBase::deduceVarTypeByProd(const AST::RuleMember &mem) -> ValueType {
    ValueType type = ValueType::Undef;
    if (mem.isGroup()) {
        const auto &val = mem.getGroup().values;
        if (val.size() == 1) {
            type = deduceVarTypeByProd(val[0]);
        } else {
            for (auto i = 0; i < val.size(); i++) {
                if (deduceVarTypeByProd(val[i]) != ValueType::String) {
                    return ValueType::Undef;
                }
            }
            type = ValueType::String;
        }
    } else if (mem.isOp()) {
        std::optional<ValueType> first_type;
        char prev_quantifier = '\0';
        for (const auto &el : mem.getOp().options) {
            auto t = deduceVarTypeByProd(el);
            // if (t == LLIR::var_types::UNDEFINED)
            //     return {LLIR::var_types::UNDEFINED};
            if (!first_type) {
                first_type = t;
                prev_quantifier = el.quantifier;
            } else if (t != *first_type || prev_quantifier != el.quantifier) {
                return ValueType::Any;
            }
        }
        type = first_type.value_or(LLIR::var_types::UNDEFINED);
    } else if (mem.isName()) {
        type = corelib::text::isUpper(mem.getName().name.back()) ? ValueType::Token : ValueType::Rule;
    } else type = ValueType::String;
    return type;
}

void LLIR::BuilderBase::getVariablesToTable(Statements& data, Statements& table, std::string& var_name, bool retain_value, bool recursive) {
    for (std::size_t i = 0; i < data.size(); /* manual increment */) {
        if (data[i].isVariable()) {
            auto variable = data[i].getVariable();
            if (!var_name.empty() && var_name != variable.name) {
                ++i;
                continue;
            }

            // Optionally retain value
            if (!variable.value.empty() && retain_value) {
                data.insert(data.begin() + i, VariableAssignment::createStatement(VariableAssignment {.name = variable.name, .value = RValue::createExpression(variable.value) }));
                ++i; // skip over inserted assignment
            }

            // Move variable declaration to table
            table.push_back(data[i]);
            data.erase(data.begin() + i); // do NOT increment i, stay at current index
            if (!var_name.empty())
                break;
        } else if (data[i].isIf() && recursive) {
            auto &condition = data[i].getIf();
            getVariablesToTable(condition.stmt, table, var_name, retain_value, recursive);
            getVariablesToTable(condition.else_stmt, table, var_name, retain_value, recursive);
        } else if ((data[i].isWhile() || data[i].isDoWhile()) && recursive) {
            auto &loop = data[i].getWhileOrDoWhile();
            getVariablesToTable(loop.stmt, table, var_name, retain_value, recursive);
        } else {
            ++i;
        }
    }
}


void LLIR::BuilderBase::insertVariablesOnTop(Statements &insertPlace, Statements& table) {
    std::size_t i = 0;
    // cpuf::printf("Raise vars on top : table size %$\n", table.size());
    for (auto& el : table) {
        insertPlace.insert(insertPlace.begin() + i++, el);
    }
}

void LLIR::BuilderBase::raiseVarsTop(Statements &insertPlace, Statements &readPlace, std::string var_name, bool all_rule, bool retain_value, bool recursive) {
    Statements table;
    getVariablesToTable(readPlace, table, var_name, retain_value, recursive);
    insertVariablesOnTop(insertPlace, table);
}
void LLIR::BuilderBase::optimizeIR() {
    // cpuf::printf("Optimze IR\n");
    raiseVarsTop(statements, statements);
}

