module LLIR.Builder.Base;
import logging;
import corelib;
import LLIR.IR;
import cpuf.printf;
import std;

auto LLIR::BuilderBase::getData() -> LangAPI::Statements & {
    return statements;
}
auto LLIR::BuilderBase::getData() const -> const LangAPI::Statements & {
    return statements;
}
auto LLIR::BuilderBase::getReturnVars() const -> const stdu::vector<LLIR::ExportsAfterBuild> & {
    return exports_list;
}
auto LLIR::BuilderBase::createEmptyVariable(const std::string &name) -> LangAPI::Variable {
    return LangAPI::Variable {.name = name};
}
void LLIR::BuilderBase::processExitStatements(LangAPI::Statements &values) {
    for (auto &el : values) {
        if (el.isExpression()) {
            auto &expr = el.getExpression();
            if (expr.size() == 1 && expr.back().isReturn()) {
                expr = LangAPI::Break::createExpression(LangAPI::Break {});
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
auto LLIR::BuilderBase::createSuccessVariable(std::size_t &variable_count) -> LangAPI::Variable {
    LangAPI::Variable var = createEmptyVariable("success" + generateVariableName(variable_count));
    var.value = LangAPI::Bool::createExpression(LangAPI::Bool {.value = false});
    return LangAPI::Variable {.name = "success" + generateVariableName(variable_count), .value = LangAPI::Bool::createExpression(LangAPI::Bool { .value = false })};
}
auto LLIR::BuilderBase::generateVariableName() -> std::string {
    return generateVariableName(variable_count);
}
auto LLIR::BuilderBase::createSuccessVariable() -> LangAPI::Variable {
    return createSuccessVariable(variable_count);
}
auto LLIR::BuilderBase::createAssignUvarBlock(LangAPI::Statements &statements, const LangAPI::Variable &uvar, const LangAPI::Variable &var, const LangAPI::Variable &shadow_var) -> void {
    if (!uvar.name.empty()) {
        statements.push_back(LangAPI::VariableAssignment::createStatement(LangAPI::VariableAssignment {
                .name = uvar.name,
                .value = LangAPI::Symbol::createExpression(LangAPI::Symbol {
                    shadow_var.name.empty() ? var.name : shadow_var.name
                })
            })
        );
    }
}
void LLIR::BuilderBase::handle_plus_qualifier(const AST::RuleMember &rule, LangAPI::ConditionalElement loop, const LangAPI::Variable &uvar, const LangAPI::Variable &var, LangAPI::Variable &shadow_var, bool addError) {
    auto postCheckVar = createSuccessVariable();
    loop.stmt.push_back(LangAPI::VariableAssignment::createStatement(LangAPI::VariableAssignment {.name = postCheckVar.name, .value = LangAPI::Bool::createExpression(LangAPI::Bool {.value = true} )}));
    statements.push_back(LangAPI::Variable::createStatement(postCheckVar));
    statements.push_back(LangAPI::While::createStatement(loop));
    addPostLoopCheck(rule, postCheckVar, addError);
}
void LLIR::BuilderBase::addPostLoopCheck(const AST::RuleMember &rule, const LangAPI::Variable &var, bool addError) {
    auto stmt = LangAPI::Return::createStatements(LangAPI::Return {});
    if (addError && !isFirst) {
        stmt.insert(stmt.begin(), LangAPI::ReportError::createExpression(LangAPI::ReportError { .message = getErrorName(rule) }));
    }
    LangAPI::If post_loop_condition;
    post_loop_condition.expr = { { { LangAPI::ExpressionElement::Not, LangAPI::Symbol::createExpressionValue(LangAPI::Symbol { var.name }) } } };
    post_loop_condition.stmt = std::move(stmt);
    statements.push_back(LangAPI::If::createStatement(post_loop_condition));
}
auto LLIR::BuilderBase::createDefaultStatements(const LangAPI::Variable &var, const LangAPI::Variable &svar) -> LangAPI::Statements {
    if (var.type == LangAPI::ValueType::Char) {
        return LangAPI::VariableAssignment::createStatements(LangAPI::VariableAssignment {.name = var.name, .value = LangAPI::Pos::createExpression(LangAPI::Pos {.dereference = true})});
    } else {
        return {
            LangAPI::VariableAssignment::createStatement(LangAPI::VariableAssignment { .name = var.name, .type = LangAPI::OperatorType::Add, .value = LangAPI::Pos::createExpression(LangAPI::Pos {.sequence = true}) }),
            LangAPI::VariableAssignment::createStatement(LangAPI::VariableAssignment { .name = svar.name, .value = LangAPI::Bool::createExpression(LangAPI::Bool {.value = true })}),
            LangAPI::Expression::createStatement(increasePos())
        };
    }
}
auto LLIR::BuilderBase::createDefaultStatements(const LangAPI::Variable &svar) -> LangAPI::Statements {
    return {
        LangAPI::VariableAssignment::createStatement(LangAPI::VariableAssignment { .name = svar.name, .value = LangAPI::Bool::createExpression(LangAPI::Bool {.value = true})}),
        LangAPI::Expression::createStatement(increasePos())
    };
}
auto LLIR::BuilderBase::createDefaultStatements() -> LangAPI::Statements {
    return LangAPI::Expression::createStatements(increasePos());
}
auto LLIR::BuilderBase::createDefaultCall(LangAPI::Statements &block, const LangAPI::Variable &var, const std::string &name, LangAPI::Expression &expr) -> LangAPI::Statement  { // var must be copy
    LangAPI::FunctionCall function_call = {.name = name, .args = {LangAPI::Pos::createExpression(LangAPI::Pos {.sequence = true}) }};
    LangAPI::VariableAssignment assignment = {
        .name = var.name,
        .value = LangAPI::FunctionCall::createExpression(function_call)
    };
    expr = LangAPI::StorageSymbol::createExpression(LangAPI::StorageSymbol {.what = LangAPI::Symbol::createExpression(LangAPI::Symbol {var.name }), .path = {{"status"}}});;
    return LangAPI::VariableAssignment::createStatement(assignment);
}
auto LLIR::BuilderBase::add_shadow_variable(LangAPI::Statements &block, const LangAPI::Variable &var) -> LangAPI::Variable {
    LangAPI::Variable shadow_var = createEmptyVariable("shadow" + generateVariableName());
    if (var.type == LangAPI::ValueType::TokenResult) {
        shadow_var.type.type = LangAPI::ValueType::Token;
    } else if (var.type == LangAPI::ValueType::RuleResult) {
        shadow_var.type.type = LangAPI::ValueType::Rule;
    }
    shadow_var.type.template_parameters = {{shadow_var.type}};
    shadow_var.type.type = LangAPI::ValueType::Array;
    statements.push_back(LangAPI::Variable::createStatement(shadow_var));
    statements.push_back(
        LangAPI::StorageSymbol::createStatement(LangAPI::StorageSymbol {
                .what = LangAPI::Symbol::createExpression(LangAPI::Symbol {
                    shadow_var.name
                }),
                .path = {
                    LangAPI::ArrayMethodCall {
                        .method = LangAPI::ArrayMethods::Push,
                        .args = {
                            LangAPI::Symbol::createExpression(LangAPI::Symbol {
                                var.name
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
    LangAPI::Expression &expr,
    LangAPI::Statements &stmt,
    LangAPI::Variable &uvar,
    const LangAPI::Variable &var,
    const LangAPI::Variable &svar,
    char quantifier,
    bool add_shadow_var
) -> LangAPI::Variable {
    //block.push_back({LLIR::types::ASSIGN_VARIABLE, Variable_assign {svar.name, LLIR::var_assign_types::ASSIGN, LLIR::var_assign_values::_TRUE}});
    LangAPI::Variable shadow_variable;
    if ((insideLoop || quantifier == '+' || quantifier == '*') && add_shadow_var) {
       shadow_variable = add_shadow_variable(stmt, var);
       add_shadow_var = false;
    }

    if (!uvar.name.empty()) {
        uvar.type = deduceUvarType(var, shadow_variable);
        statements.push_back(LangAPI::Variable::createStatement(uvar));
    }
    switch (quantifier) {
        case '+':
            handle_plus_qualifier(rule, LangAPI::ConditionalElement {.expr = expr, .stmt = stmt}, uvar, var, shadow_variable);
            break;
        case '*': {
            statements.push_back(LangAPI::While::createStatement(LangAPI::While {expr, stmt}));
            break;
        }
        case '?':
            statements.push_back(LangAPI::If::createStatement(LangAPI::If {expr, stmt}));
            break;
        default:
            // add the negative into condition
            createAssignUvarBlock(stmt, uvar, var, shadow_variable);
            expr.insert(expr.begin(), LangAPI::ExpressionValue { LangAPI::ExpressionElement::Not });
            expr.insert(expr.begin() + 1, LangAPI::ExpressionValue { LangAPI::ExpressionElement::GroupOpen });
            expr.push_back(LangAPI::ExpressionValue { LangAPI::ExpressionElement::GroupClose});
            // add exit statement
            LangAPI::Statements blk = LangAPI::Return::createStatements(LangAPI::Return {});
            if (!isFirst) {
                blk.insert(blk.begin(), LangAPI::ReportError::createStatement( LangAPI::ReportError { .message = getErrorName(rule)}));
            }
            statements.push_back(LangAPI::If::createStatement(LangAPI::If {expr, blk}));
            statements.insert(statements.end(), stmt.begin(), stmt.end());
            break;
    }
    createAssignUvarBlock(statements, uvar, var, shadow_variable);
    return shadow_variable;
}
void LLIR::BuilderBase::pushConvResult(const AST::RuleMember &rule, const LangAPI::Variable &var, const LangAPI::Variable &uvar, const LangAPI::Variable &svar, const LangAPI::Variable &shadow_var, char quantifier) {
    const auto insert_var = [this](const LangAPI::Variable &var) {
        if (!var.name.empty()) {
            vars.push_back(var);
        }
    };
    const auto v_or_empty = [this](const LangAPI::Variable &var) -> LangAPI::Variable {
        if (!var.name.empty() && var.type != LangAPI::ValueType::Undef) {
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
void LLIR::BuilderBase::undoRuleResult(LangAPI::ValueType &type) {
    if (type == LangAPI::ValueType::RuleResult)
        type = LangAPI::ValueType::Rule;
    if (type == LangAPI::ValueType::TokenResult)
        type = LangAPI::ValueType::Token;
}

auto LLIR::BuilderBase::getPrefixAsExpressionValue(const std::optional<char> &prefix) -> LangAPI::ExpressionValue {
    if (prefix.has_value()) {
        if (prefix.value() == '+')
            return LangAPI::ExpressionValue { LangAPI::ExpressionElement::PlusPlus };
        else
            return LangAPI::ExpressionValue { LangAPI::ExpressionElement::MinusMinus };
    }
    return LangAPI::ExpressionValue {};
}
void LLIR::BuilderBase::pushVariablePrefix(LangAPI::Expression &expr, const std::optional<char> &prefix) {
    if (prefix.has_value())
        expr.push_back(getPrefixAsExpressionValue(prefix));
}
auto LLIR::BuilderBase::increasePos() -> LangAPI::Expression {
    return {LangAPI::Pos::createExpressionValue(LangAPI::Pos{}), LangAPI::ExpressionValue { LangAPI::ExpressionElement::PlusPlus}};
}

auto LLIR::BuilderBase::CllTypeToIR(const AST::CllType &type) -> LangAPI::Type {
    if (type.type == "var")
        return LangAPI::ValueType::Any;
    if (type.type == "str")
        return LangAPI::ValueType::String;
    if (type.type == "bool")
        return LangAPI::ValueType::Bool;
    if (type.type == "num")
        return LangAPI::ValueType::Int;
    if (type.type == "arr") {
        LangAPI::ValueType tp = LangAPI::ValueType::Array;
        LangAPI::Type _template = CllTypeToIR(type.templ[0]);
        return {tp, _template};
    }
    if (type.type == "obj") {
        LangAPI::ValueType tp = LangAPI::ValueType::Map;
        LangAPI::Type _template1 = CllTypeToIR(type.templ[0]);
        LangAPI::Type _template2 = CllTypeToIR(type.templ[1]);
        return {tp, _template1, _template2};
    }
    throw Error("Undefined type");
}
auto LLIR::BuilderBase::CllOpToIR(const char op) -> LangAPI::OperatorType {
    // all other is single character so can use switch
    switch (op) {
        case '+':
            return LangAPI::OperatorType::Add;
        case '-':
            return LangAPI::OperatorType::Minus;
        case '*':
            return LangAPI::OperatorType::Multiply;
        case '/':
            return LangAPI::OperatorType::Divide;
        case '%':
            return LangAPI::OperatorType::Modulo;
        default:
            throw Error("Undefined operator");
    }
}
auto LLIR::BuilderBase::CllOpToExpr(const char op) -> LangAPI::ExpressionElement {
    switch (op) {
        case '+':
            return LangAPI::ExpressionElement::Add;
        case '-':
            return LangAPI::ExpressionElement::Minus;
        case '*':
            return LangAPI::ExpressionElement::Multiply;
        case '/':
            return LangAPI::ExpressionElement::Divide;
        case '%':
            return LangAPI::ExpressionElement::Modulo;
        default:
            throw Error("Undefined operator");
    }
}
auto LLIR::BuilderBase::CllCompareOpToExpr(const AST::CllCompareOp &op) -> LangAPI::ExpressionElement {
    if (op.op == "==")
        return LangAPI::ExpressionElement::Equal;
    if (op.op == "!=")
        return LangAPI::ExpressionElement::NotEqual;
    if (op.op == ">")
        return LangAPI::ExpressionElement::Higher;
    if (op.op == "<")
        return LangAPI::ExpressionElement::Lower;
    if (op.op == ">=")
        return LangAPI::ExpressionElement::HigherOrEqual;
    if (op.op == "<=")
        return LangAPI::ExpressionElement::LowerOrEqual;
    throw Error("undefined compare operator");
}
auto LLIR::BuilderBase::CllLogicalOpToIR(const AST::CllLogicalOp &lop) -> LangAPI::ExpressionElement {
    if (lop.isAnd)
        return LangAPI::ExpressionElement::And;
    return LangAPI::ExpressionElement::Or;
}
auto LLIR::BuilderBase::CllAssignmentOpToIR(const char op) -> LangAPI::OperatorType {
    if (op == '\0')
        return LangAPI::OperatorType::Assign;
    switch (op) {
        case '+':
            return LangAPI::OperatorType::Add;
        case '-':
            return LangAPI::OperatorType::Minus;
        case '*':
            return LangAPI::OperatorType::Multiply;
        case '/':
            return LangAPI::OperatorType::Divide;
        case '%':
            return LangAPI::OperatorType::Modulo;
        default:
            throw Error("Undefined operator");
    }
    return CllOpToIR(op);
}
auto LLIR::BuilderBase::assignSvar(const LangAPI::Variable &svar, bool value) -> LangAPI::Statement {
    return LangAPI::VariableAssignment::createStatement(LangAPI::VariableAssignment {.name = svar.name, .value = LangAPI::Bool::createExpression(LangAPI::Bool { .value = value })});
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

        // LangAPI::If this is not optional, break after processing it
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


auto LLIR::BuilderBase::deduceUvarType(const LangAPI::Variable &var, const LangAPI::Variable &shadow_var) -> LangAPI::Type {
    return shadow_var.name.empty() ? var.type : shadow_var.type;
}
auto LLIR::BuilderBase::deduceVarTypeByRuleMember(const AST::RuleMember &mem) -> LangAPI::Type {
    LangAPI::Type type = LangAPI::ValueType::Undef;
    if (mem.isGroup()) {
        const auto &val = mem.getGroup().values;
        if (val.size() == 1) {
            type = deduceVarTypeByRuleMember(val[0]);
        } else {
            for (auto i = 0; i < val.size(); i++) {
                if (deduceVarTypeByRuleMember(val[i]) != LangAPI::ValueType::String) {
                    return LangAPI::ValueType::Undef;
                }
            }
            type = LangAPI::ValueType::String;
        }
    } else if (mem.isOp()) {
        std::optional<LangAPI::Type> first_type;
        char prev_quantifier = '\0';
        for (const auto &el : mem.getOp().options) {
            auto t = deduceVarTypeByRuleMember(el);
            // if (t == LLIR::var_types::UNDEFINED)
            //     return {LLIR::var_types::UNDEFINED};
            if (!first_type) {
                first_type = t;
                prev_quantifier = el.quantifier;
            } else if (t != *first_type || prev_quantifier != el.quantifier && type.getValueType() != LangAPI::ValueType::Variant) {
                type = {LangAPI::ValueType::Variant, first_type.value()};
                return LangAPI::ValueType::Any;
            } else {
                type.template_parameters.push_back(t);
            }
        }
    } else if (mem.isName()) {
        type = corelib::text::isUpper(mem.getName().name.back()) ? LangAPI::ValueType::Token : LangAPI::ValueType::Rule;
    } else type = LangAPI::ValueType::String;
    return type;
}

void LLIR::BuilderBase::getVariablesToTable(LangAPI::Statements& data, LangAPI::Statements& table, std::string& var_name, bool retain_value, bool recursive) {
    for (std::size_t i = 0; i < data.size(); /* manual increment */) {
        if (data[i].isVariable()) {
            auto variable = data[i].getVariable();
            if (!var_name.empty() && var_name != variable.name) {
                ++i;
                continue;
            }

            // Optionally retain value
            if (!variable.value.empty() && retain_value) {
                data.insert(data.begin() + i, LangAPI::VariableAssignment::createStatement(LangAPI::VariableAssignment {.name = variable.name, .value = LangAPI::RValue::createExpression(variable.value) }));
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


void LLIR::BuilderBase::insertVariablesOnTop(LangAPI::Statements &insertPlace, LangAPI::Statements& table) {
    std::size_t i = 0;
    // cpuf::printf("Raise vars on top : table size %$\n", table.size());
    for (auto& el : table) {
        insertPlace.insert(insertPlace.begin() + i++, el);
    }
}

void LLIR::BuilderBase::raiseVarsTop(LangAPI::Statements &insertPlace, LangAPI::Statements &readPlace, std::string var_name, bool all_rule, bool retain_value, bool recursive) {
    LangAPI::Statements table;
    getVariablesToTable(readPlace, table, var_name, retain_value, recursive);
    insertVariablesOnTop(insertPlace, table);
}
void LLIR::BuilderBase::optimizeIR() {
    // cpuf::printf("Optimze IR\n");
    raiseVarsTop(statements, statements);
}

