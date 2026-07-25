module LangRepr.ConstructParser;

import LLIR.Builder.Base;
import cpuf.printf;
import NFA;
import DFA.CharMachineDFA;

import corelib;

import std;

namespace LangRepr {
    auto ConstructParser::ensureTypesNs(LangAPI::Type t) -> LangAPI::Type {
        if (t.isSymbol())
            if (std::get<std::string>(t.getSymbol().path.front()) != "Types") {
                t.getSymbol().path.insert(t.getSymbol().path.begin(), "Types");
            }
        if (!t.template_parameters.empty()) {
            for (auto &p : t.template_parameters) p = ensureTypesNs(std::get<LangAPI::Type>(p));
        }
        return t;
    };
    // 1. Symbol Traversal
    auto ConstructParser::ensureTypesNs(LangAPI::Symbol s) -> LangAPI::Symbol {
        for (auto &part : s.path) {
            if (std::holds_alternative<LangAPI::FunctionCall>(part)) {
                part = ensureTypesNs(std::get<LangAPI::FunctionCall>(part));
            }
        }
        return s;
    }

    // 2. StorageSymbol Traversal
    auto ConstructParser::ensureTypesNs(LangAPI::StorageSymbol s) -> LangAPI::StorageSymbol {
        s.what = ensureTypesNs(s.what);
        for (auto &part : s.path) {
            if (std::holds_alternative<LangAPI::FunctionCall>(part)) {
                part = ensureTypesNs(std::get<LangAPI::FunctionCall>(part));
            }
        }
        return s;
    }

    // 3. Inheritance Traversal
    auto ConstructParser::ensureTypesNs(LangAPI::Inheritance s) -> LangAPI::Inheritance {
        if (std::holds_alternative<LangAPI::Symbol>(s.name)) {
            s.name = ensureTypesNs(std::get<LangAPI::Symbol>(s.name));
        }
        for (auto &arg : s.args) {
            arg = ensureTypesNs(arg);
        }
        return s;
    }

    // 4. RValue Traversal
    auto ConstructParser::ensureTypesNs(LangAPI::RValue r) -> LangAPI::RValue {
        if (r.isSymbol()) {
            r.set(ensureTypesNs(r.getSymbol()));
        } else if (r.isStorageSymbol()) {
            r.set(ensureTypesNs(r.getStorageSymbol()));
        } else if (r.isInheritance()) {
            r.set(ensureTypesNs(r.getInheritance()));
        } else if (r.isArray()) {
            auto &arr = r.getArray();
            for (auto &val : arr.values) val = ensureTypesNs(val);
            for (auto &param : arr.template_parameters) {
                std::visit([&](auto &p) {
                    using T = std::decay_t<decltype(p)>;
                    if constexpr (std::is_same_v<T, std::shared_ptr<LangAPI::Type>>) {
                        if (p) *p = ensureTypesNs(*p);
                    } else if constexpr (std::is_same_v<T, LangAPI::RValue>) {
                        p = ensureTypesNs(p);
                    }
                }, param);
            }
        } else if (r.isMap()) {
            auto &m = r.getMap();
            for (auto &val : m.values) val = ensureTypesNs(val);
        } else if (r.isSpan()) {
            auto &span = r.getSpan();
            if (span.type) *span.type = ensureTypesNs(*span.type);
            span.sym = ensureTypesNs(span.sym);
        }
        return r;
    }

    // 5. FunctionCall Traversal
    auto ConstructParser::ensureTypesNs(LangAPI::FunctionCall s) -> LangAPI::FunctionCall {
        if (s.name) {
            *s.name = ensureTypesNs(*s.name);
        }
        for (auto &p : s.template_parameters) {
            std::visit([&](auto &param) {
                using T = std::decay_t<decltype(param)>;
                if constexpr (std::is_same_v<T, LangAPI::Type>) {
                    param = ensureTypesNs(param);
                } else if constexpr (std::is_same_v<T, LangAPI::RValue>) {
                    param = ensureTypesNs(param);
                }
            }, p);
        }
        for (auto &arg : s.args) {
            arg = ensureTypesNs(arg);
        }
        return s;
    }

    // 6. Lambda Traversal
    auto ConstructParser::ensureTypesNs(LangAPI::Lambda l) -> LangAPI::Lambda {
        for (auto &[type, param_name] : l.parameters) {
            type = ensureTypesNs(type);
        }
        l.statements = ensureTypesNs(l.statements);
        return l;
    }

    // 7. ExpressionValue Traversal
    auto ConstructParser::ensureTypesNs(LangAPI::ExpressionValue ev) -> LangAPI::ExpressionValue {
        std::visit([&](auto &val) {
            using T = std::decay_t<decltype(val)>;
            if constexpr (std::is_same_v<T, LangAPI::RValue>) {
                val = ensureTypesNs(val);
            } else if constexpr (std::is_same_v<T, LangAPI::FunctionCall>) {
                val = ensureTypesNs(val);
            } else if constexpr (std::is_same_v<T, LangAPI::Return>) {
                val.value = ensureTypesNs(val.value);
            } else if constexpr (std::is_same_v<T, LangAPI::VariableAssignment>) {
                val.value = ensureTypesNs(val.value);
            } else if constexpr (std::is_same_v<T, LangAPI::Lambda>) {
                val = ensureTypesNs(val);
            } else if constexpr (std::is_same_v<T, LangAPI::DfaLookup>) {
                val.return_type = ensureTypesNs(val.return_type);
            }
        }, ev.value);
        return ev;
    }

    // 8. Expression Traversal
    auto ConstructParser::ensureTypesNs(LangAPI::Expression expr) -> LangAPI::Expression {
        for (auto &val : expr) {
            val = ensureTypesNs(val);
        }
        return expr;
    }

    // 9. Variable Traversal
    auto ConstructParser::ensureTypesNs(LangAPI::Variable v) -> LangAPI::Variable {
        v.type = ensureTypesNs(v.type);
        v.value = ensureTypesNs(v.value);
        return v;
    }

    // 10. Control Flow Traversals (If, While, DoWhile, Switch)
    auto ConstructParser::ensureTypesNs(LangAPI::If s) -> LangAPI::If {
        s.expr = ensureTypesNs(s.expr);
        s.stmt = ensureTypesNs(s.stmt);
        s.else_stmt = ensureTypesNs(s.else_stmt);
        return s;
    }

    auto ConstructParser::ensureTypesNs(LangAPI::While s) -> LangAPI::While {
        s.expr = ensureTypesNs(s.expr);
        s.stmt = ensureTypesNs(s.stmt);
        return s;
    }

    auto ConstructParser::ensureTypesNs(LangAPI::DoWhile s) -> LangAPI::DoWhile {
        s.expr = ensureTypesNs(s.expr);
        s.stmt = ensureTypesNs(s.stmt);
        return s;
    }

    auto ConstructParser::ensureTypesNs(LangAPI::Switch s) -> LangAPI::Switch {
        s.expression = ensureTypesNs(s.expression);
        for (auto &[case_val, case_stmts] : s.cases) {
            case_val = ensureTypesNs(case_val);
            case_stmts = ensureTypesNs(case_stmts);
        }
        return s;
    }

    // 11. Statement Traversal
    auto ConstructParser::ensureTypesNs(const LangAPI::Statement &s) -> LangAPI::Statement {
        LangAPI::Statement new_statement;
        std::visit([&](const auto &unpacked) {
            using T = std::decay_t<decltype(unpacked)>;
            if constexpr (!std::is_same_v<T, std::monostate>) {
                new_statement.value = ensureTypesNs(unpacked);
            }
        }, s.value);
        return new_statement;
    }

    // 12. Statements Vector Traversal
    auto ConstructParser::ensureTypesNs(LangAPI::Statements stmts) -> LangAPI::Statements {
        for (auto &stmt : stmts) {
            stmt = ensureTypesNs(stmt);
        }
        return stmts;
    }
    auto ConstructParser::createParserClass(std::string main_node) -> LangAPI::Class {
        LangAPI::IspaLibSymbol parser_s {LangAPI::StdlibExports::Parser};
        parser_s.template_parameters.push_back(std::make_shared<LangAPI::Type>(LangAPI::Symbol {"Types", main_node}));
        parser_s.template_parameters.push_back(std::make_shared<LangAPI::Type>(LangAPI::Symbol {"Token"}));
        return LangAPI::Class {
            .name = "Parser",
            .inherit_members = {std::make_pair(LangAPI::Visibility::Public, parser_s)},
            .default_visibility = LangAPI::Visibility::Private
        };
    }
    auto ConstructParser::constructTokenMachineDFA(LangAPI::Class &parser_class) -> void {
        std::size_t count = 0;
        const auto &dfas = ir.getDfas().get();
        auto states = ir.getDfas().getStateSet();
        // 1. Construct the State Variables
        for (const auto &state : states.state_set) {
            const auto [dfa_idx, local_state_index] = states.state_in_dfa_location_map.at(count);
            const auto &dfa = dfas.at(dfa_idx);

            const int transition_size = state.transitions.size();
            auto s = getStateType(DFA::DfaType::Token);
            // FIX: Ensure this is exported as a State, not a single Transition
            s.exports = LangAPI::StdlibExports::DfaTokenState;
            s.template_parameters.push_back(makeIntRValue(transition_size));

            stdu::vector<LangAPI::Expression> transitions;
            // Construct standard token transitions (No CST metadata, No nested DFAs)
            for (const auto &[symbol, transition] : state.transitions) {
                transitions.push_back(
                    LangAPI::IspaLibDfaTransition::createExpression(LangAPI::IspaLibDfaTransition {
                        .symbol = std::get<stdu::vector<std::string>>(symbol),
                        .next = transition.next,
                        .accept = transition.accept_index,
                        .transition_type = { LangAPI::StdlibExports::DfaTokenTransition },
                        .is_refferring_char_table = false
                    })
                );
            }
            parser_class.data.push_back(
                std::make_pair(
                    std::make_shared<LangAPI::Declaration>(LangAPI::Variable::createDeclaration(LangAPI::Variable {
                        .name = std::string("dfa_state_") + std::to_string(count),
                        .type = s,
                        .value = LangAPI::Array::createExpression(LangAPI::Array { .values = transitions }),
                        .is_static = true
                    })),
                    LangAPI::Visibility::Private
                )
            );
            ++count;
        }

        // 2. Construct the DFA Tables
        for (std::size_t dfa_count = 0; dfa_count < dfas.size(); ++dfa_count) {
            const auto &dfa = dfas.at(dfa_count);
            std::vector<LangAPI::Expression> dfa_table_states;

            for (std::size_t state_count = 0; state_count < dfa.get().size(); ++state_count) {
                const auto &state_id = states.location_in_set.at(std::make_pair(dfa_count, state_count));
                const auto &state = states.state_set.get().at(state_id);

                LangAPI::IspaLibSymbol span_type = {
                    .exports = LangAPI::StdlibExports::DfaSpanTokenTableState,
                    .template_parameters = {std::make_shared<LangAPI::Type>(Token)}
                };

                dfa_table_states.push_back(LangAPI::RValue::createExpression(
                    LangAPI::RValue {LangAPI::Inheritance {
                        .name = span_type,
                        .args = {
                            LangAPI::Int::createExpression(LangAPI::Int {.value = static_cast<long long>(state.else_goto)}),
                            LangAPI::Int::createExpression(LangAPI::Int {.value = static_cast<long long>(state.else_goto_accept)}),
                            // FIX: Match the class name ("Parser") and the variable name ("dfa_state_") from Loop 1
                            LangAPI::Symbol::createExpression(LangAPI::Symbol {"Parser", "dfa_state_" + std::to_string(state_id)})
                        }
                    }}
                ));
            }

            auto table_params = std::vector<std::variant<std::shared_ptr<LangAPI::Type>, std::shared_ptr<LangAPI::RValue>>> {
                std::make_shared<LangAPI::RValue>(
                    LangAPI::Int::createRValue(LangAPI::Int {.value = (long long) dfa.get().size()})
                )
            };

            LangAPI::Variable dfa_table_var {
                .name = "dfa_table_" + std::to_string(dfa_count),
                .type = LangAPI::Type {
                    LangAPI::IspaLibSymbol {
                        LangAPI::StdlibExports::DfaTokenTable,
                        table_params
                    }
                },
                .value = LangAPI::Array::createExpression(LangAPI::Array { .values = dfa_table_states }),
                .is_static = true
            };

            // FIX: Use Variable::createDeclaration instead of Statement::createDeclaration
            parser_class.data.emplace_back(
                std::make_shared<LangAPI::Declaration>(LangAPI::Variable::createDeclaration(dfa_table_var)),
                LangAPI::Visibility::Private
            );
        }
    }
    auto ConstructParser::constructParser() -> void {
        auto parser = createParserClass();
        constructTokenMachineDFA(parser);
        std::cout << "Parser size: " << parser.data.size() << std::endl;
        for (const auto &prod : ir) {
            LangAPI::Type fun_type = ensureTypesNs(LangAPI::Type {LangAPI::Symbol {prod.name} }); // must be type as symbols are not automatically assigned
            LangAPI::Statements stmts;
            bool pushed = false;
            for (const auto &statement : prod.members) {
                if (statement.isExpression()) {
                    const auto &expr = statement.getExpression();
                    if (expr.size() == 1 && expr.front().isReturn()) {
                        auto ret = expr.front().getReturn();
                        ret.value = LangAPI::EmptyInitializer::createExpression(LangAPI::EmptyInitializer {});
                        stmts.push_back(LangAPI::Return::createStatement(ret));
                        pushed = true;
                    }
                }
                if (!pushed) {
                    stmts.push_back(ensureTypesNs(statement));
                }
            }
            LangAPI::Variable result_v;
            result_v.type = ensureTypesNs(LangAPI::Type {LangAPI::Symbol {prod.name} });
            result_v.name = "result";
            stmts.push_back(LangAPI::Variable::createStatement(result_v));
            if (prod.block.is_inclosed_map()) {
                const auto ib = prod.block.getInclosedMap();
                for (const auto &[name, expr] : ib) {
                    LangAPI::StorageSymbol s;
                    s.what = LangAPI::Symbol::createExpression(LangAPI::Symbol {"result"});
                    s.path.push_back(name);
                    LangAPI::VariableAssignment variable_assignment;
                    variable_assignment.name = s;
                    variable_assignment.type = LangAPI::OperatorType::Assign;
                    variable_assignment.value = ensureTypesNs(expr.first);
                    stmts.push_back(LangAPI::VariableAssignment::createStatement(variable_assignment));
                }
            } else {
                auto v = LangAPI::StorageSymbol {"value"};
                v.what = LangAPI::Symbol::createExpression(LangAPI::Symbol {"result"});
                stmts.push_back(LangAPI::VariableAssignment::createStatement(LangAPI::VariableAssignment {
                    .name = v,
                    .value = ensureTypesNs(prod.block.getRegularDataBlock().first)
                }));
            }
            stmts.push_back(LangAPI::Return::createStatement(LangAPI::Return { .value = LangAPI::Symbol::createExpression(LangAPI::Symbol {"result"}) }));
            LangAPI::Function prod_fun {
                .type = fun_type,
                .name = corelib::text::join(prod.name, "_"),
                .parameters = {std::make_pair(LangAPI::Type {LangAPI::Symbol {"IT"}}, "pos")},
                .statements = stmts,
                .template_parameters = {"IT"},
            };
            parser.data.push_back(std::make_pair(std::make_shared<LangAPI::Declaration>(std::move(prod_fun)), LangAPI::Visibility::Private));
        }
        holder.push(parser);
    }
}
