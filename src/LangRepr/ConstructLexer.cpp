module LangRepr.ConstructLexer;

import LLIR.Builder.Base;
import cpuf.printf;
import std;

namespace LangRepr {
    auto ConstructLexer::createTypeToken() -> LangAPI::TypeAlias {
        LangAPI::Type variant_type = LangAPI::ValueType::Variant;
        for (const auto &[name, dtb] : lexer_builder.getDataBlocks()) {
            LangAPI::Symbol tn = name;
            tn.path.insert(tn.path.begin(), "Types");
            variant_type.template_parameters.push_back(LangAPI::Type {tn});
        }
        Token = LangAPI::Symbol { "Token" };
        return LangAPI::TypeAlias {.name = "Token", .type = variant_type};
    }
    auto ConstructLexer::createLexerClass() -> LangAPI::Class {
        LangAPI::IspaLibSymbol lexer_s {LangAPI::StdlibExports::Lexer};
        lexer_s.template_parameters.push_back(std::make_shared<LangAPI::Type>(LangAPI::Symbol {"Tokens"}));
        lexer_s.template_parameters.push_back(std::make_shared<LangAPI::Type>(LangAPI::Symbol {"Token"}));
        return LangAPI::Class {
            .name = "Lexer",
            .inherit_members = {std::make_pair(LangAPI::Visibility::Public, lexer_s)},
            .default_visibility = LangAPI::Visibility::Private
        };
    }
    auto ConstructLexer::getTransitionCount(const std::variant<DFA::FullCharTable, DFA::SortedTransitions> &transitions) -> std::size_t {
        return std::holds_alternative<DFA::FullCharTable>(transitions) ?
            static_cast<int>(std::get<DFA::FullCharTable>(transitions).size())
            :
            static_cast<int>(std::get<DFA::SortedTransitions>(transitions).size());
    }

    auto ConstructLexer::makeIntRValue(int v) -> std::shared_ptr<LangAPI::RValue> {
        return std::make_shared<LangAPI::RValue>(
            LangAPI::Int::createRValue(LangAPI::Int{.value = v})
        );
    };
    auto ConstructLexer::ensureTypesNs(LangAPI::Type t) -> LangAPI::Type {
        if (t.isSymbol())
            if (std::get<std::string>(t.getSymbol().path.front()) != "Types") {
                t.getSymbol().path.insert(t.getSymbol().path.begin(), "Types");
            }
        if (!t.template_parameters.empty()) {
            for (auto &p : t.template_parameters) p = ensureTypesNs(std::get<LangAPI::Type>(p));
        }
        return t;
    };
    auto ConstructLexer::getStateType(DFA::DfaType state_type) -> LangAPI::IspaLibSymbol {
        LangAPI::IspaLibSymbol s;
        auto makeReturnType = [&]() -> std::shared_ptr<LangAPI::Type> {
            auto rt = std::make_shared<LangAPI::Type>(LangAPI::Symbol{"Token"});
            return rt;
        };
        switch (state_type) {
            case DFA::DfaType::Char:
                s.exports = LangAPI::StdlibExports::DfaCharState;
                break;
            case DFA::DfaType::Token:
                s.exports = LangAPI::StdlibExports::DfaTokenState;
                break;
            case DFA::DfaType::Multi:
                s.exports = LangAPI::StdlibExports::DfaMultiTableState;
                s.template_parameters = { makeReturnType() };
                break;
            default:
                s.exports = LangAPI::StdlibExports::EmptyState;
                s.template_parameters.push_back(makeReturnType());
        }
        return s;
    }

    auto ConstructLexer::buildLambdaContent(
        LangAPI::Symbol builder_sym,
        const LangAPI::Expression &expr,
        const LangAPI::Type &type,
        const NFA::TemplatedDataBlockValue &data_block,
        long long N
    ) -> LangAPI::StorageSymbol {
        // where to look for data
        LangAPI::Symbol position_manager = (data_block.type == NFA::StoreCstNode::CST_GROUP ? "gb" : "mb");

        decltype(LangAPI::FunctionCall::template_parameters) template_parameters;
        LangAPI::Array indices_with_groups {.template_parameters = {{std::make_shared<LangAPI::Type>(LangAPI::Type {LangAPI::ValueType::Int})}}};
        decltype(LangAPI::FunctionCall::args) args;
        std::string call_name;
        template_parameters.push_back(LangAPI::RValue {LangAPI::Int {.value = N}});
        if (data_block.type == NFA::StoreCstNode::CST_CONDITION) {
            call_name = "condition";
            // determine what indices have groups
            long long el_count = 0;
            for (const auto &element : data_block.AST->getOp().options) {
                if (element.isGroup())
                    indices_with_groups.values.push_back(LangAPI::Int::createExpression(LangAPI::Int {.value = el_count}));
                el_count++;
                template_parameters.push_back(ensureTypesNs(LLIR::BuilderBase::deduceVarTypeByRuleMember(element)));
            }
            args = {LangAPI::Array::createExpression(indices_with_groups)};
        } else {
            call_name = data_block.type == NFA::StoreCstNode::CST_GROUP ? "group" : "element";
        }


        LangAPI::StorageSymbol call_to_function;
        call_to_function.what = LangAPI::Symbol::createExpression(builder_sym);
        call_to_function.path = {
            LangAPI::FunctionCall {
                .name = call_name,
                .template_parameters=template_parameters,
                .args = args
            }
        };
        return call_to_function;
    }

    auto ConstructLexer::makeEmptyStateLambda(DFA::DfaType dfa_type, const stdu::vector<std::string> &name, const stdu::vector<std::string> &clear_name,
                                              const NFA::DataBlock &nfa_dtb) -> LangAPI::Lambda {
        stdu::vector<std::pair<LangAPI::Type, std::string>> params;
        params.push_back({LangAPI::Type{LangAPI::IspaLibSymbol{.exports = LangAPI::StdlibExports::DfaEmptyStateMemberBegin, .Const =  true, .Reference = true}}, "mb"});
        params.push_back({LangAPI::Type{LangAPI::IspaLibSymbol{.exports = LangAPI::StdlibExports::DfaEmptyStateGroupBegin, .Const = true, .Reference = true}}, "gb"});
        params.push_back({
            LangAPI::Type{LangAPI::IspaLibSymbol{
                .exports = LangAPI::StdlibExports::DfaUniversalDataVector,
                .template_parameters = {std::make_shared<LangAPI::Type>(LangAPI::Type {Token})},
                .Const = true,
                .Reference = true}
            }, "dv"}
        );

        LangAPI::Statements body;
        const auto data_blocks = lexer_builder.getDataBlocks();
        const auto &data_block = data_blocks.at(clear_name);
        // declare builder
        auto builder_internal_type = LangAPI::IspaLibSymbol {.exports = LangAPI::StdlibExports::DfaCstBuilder,
            .template_parameters = {
                std::make_shared<LangAPI::Type>(ensureTypesNs(LangAPI::Type {LangAPI::Symbol {name}})),
                std::make_shared<LangAPI::Type>(Token),
            }
        };
        auto builder_symbol = LangAPI::Symbol {"builder"};
        if (data_block.is_inclosed_map()) {
            const auto &templated_data_block = std::get<NFA::TemplatedDataBlock>(nfa_dtb);
            long long N = 0;
            for (const auto &[mname, mdata] : data_block.getInclosedMap()) {
                // add this node type to builder
                builder_internal_type.template_parameters.push_back(std::make_shared<LangAPI::Type>(ensureTypesNs(mdata.second)));
                auto current_templated_data_block = templated_data_block.at(mname);
                body.push_back(LangAPI::StorageSymbol::createStatement(buildLambdaContent(builder_symbol, mdata.first, mdata.second, current_templated_data_block, N)));
                ++N;
            }
        } else if (!data_block.empty()) {
            const auto &[data, type] = data_block.getRegularDataBlock();
            const auto &sv_data_block = std::get<NFA::TemplatedDataBlockValue>(nfa_dtb);
            builder_internal_type.template_parameters.push_back(std::make_shared<LangAPI::Type>(ensureTypesNs(type)));
            body.push_back(LangAPI::StorageSymbol::createStatement(buildLambdaContent(builder_symbol, data, type, sv_data_block, 0)));
        }
        auto args = LangAPI::Inheritance {
            .name = builder_internal_type,
            .args = {
                LangAPI::Symbol::createExpression(LangAPI::Symbol {"dv"}),
                LangAPI::Symbol::createExpression(LangAPI::Symbol {"mb"}),
                LangAPI::Symbol::createExpression(LangAPI::Symbol {"gb"})
            }
        };
        auto builder = LangAPI::Variable {
            .name = "builder",
            .type = builder_internal_type,
            .value = LangAPI::Inheritance::createExpression(args)
        };
        body.insert(body.begin(), LangAPI::Variable::createStatement(builder));;
        LangAPI::StorageSymbol return_storage_symbol;
        return_storage_symbol.what = LangAPI::Symbol::createExpression(builder_symbol);
        return_storage_symbol.path = {LangAPI::FunctionCall {.name = "build"}};
        body.push_back(LangAPI::Return::createStatement(
            LangAPI::Return {
                .value = LangAPI::StorageSymbol::createExpression(return_storage_symbol)
            }
        ));
        return LangAPI::Lambda{ .parameters = std::move(params), .statements = std::move(body)};
    }
    auto ConstructLexer::constructLexer() -> void {
        holder.push(LangAPI::TypeAlias::createDeclaration(createTypeToken()));
        std::size_t count = 0;
        const auto &dfas = lexer_builder.getDFAS().get();
        auto states = lexer_builder.getDFAS().getStateSet();
        auto lexer = createLexerClass();
        std::unordered_set<std::size_t> char_table_states;
        std::unordered_set<std::size_t> multi_table_states;
        for (const auto &state : states.state_set) {
            const auto [dfa_idx, local_state_index] = states.state_in_dfa_location_map.at(count);
            const auto &dfa = dfas.at(dfa_idx);
            auto [type, tn_path] = states.state_to_type.at(count);
            LangAPI::Symbol tn = tn_path;

            const int transition_size = getTransitionCount(state.transitions);
            auto s = getStateType(type);

            stdu::vector<LangAPI::Expression> transitions;
            stdu::vector<std::string> token_type = {"Types"};
            LangAPI::Lambda construct_lambda;
            bool empty = false;
            if (std::holds_alternative<DFA::FullCharTable>(state.transitions)) {
                const auto &char_transitions = std::get<DFA::FullCharTable>(state.transitions);
                unsigned char c = std::numeric_limits<unsigned char>::min();
                for (const auto &transition : char_transitions) {
                    transitions.push_back(
                        LangAPI::IspaLibDfaTransition::createExpression(LangAPI::IspaLibDfaTransition {
                            .symbol = static_cast<char>(c),
                            .next = transition.next,
                            .new_cst_node = transition.new_cst_node,
                            .new_member = transition.new_member,
                            .close_cst_node = transition.close_cst_node,
                            .new_group = transition.new_group,
                            .group_close = transition.group_close,
                            .accept = transition.accept_index,
                            .transition_type = LangAPI::IspaLibSymbol {.exports = LangAPI::StdlibExports::DfaCharTransition}
                        })
                    );
                    c++;
                }
            } else {
                const auto &sorted_transitions = std::get<DFA::SortedTransitions>(state.transitions);
                if (sorted_transitions.empty()) {
                    empty = true;
                    if (state.else_goto == 0) {
                        token_type.insert(token_type.end(), state.rule_name.begin(), state.rule_name.end());

                        construct_lambda = makeEmptyStateLambda(dfa.getType(), token_type, state.rule_name, state.dtb);
                        s.exports = LangAPI::StdlibExports::EmptyState;
                    } else {
                        s.exports = LangAPI::StdlibExports::DfaCharState;
                    }
                } else s.template_parameters.push_back(makeIntRValue(transition_size));
                // Determine if all DFA-reference transitions in this state point to Char tables.
                // Ignore plain char-symbol transitions when making this decision.
                bool is_referring_char_table = false;
                if (!empty) {
                    bool has_ref_transitions = false;
                    bool all_char_refs = true;
                    for (const auto &transition_pair : sorted_transitions) {
                        if (std::holds_alternative<stdu::vector<std::string>>(transition_pair.first)) {
                            has_ref_transitions = true;
                            const auto &ref_name = std::get<stdu::vector<std::string>>(transition_pair.first);
                            const auto &ref_dfa = dfas.at(lexer_builder.getNameToDFAIndex().at(ref_name));
                            if (ref_dfa.getType() != DFA::DfaType::Char) {
                                all_char_refs = false;
                                break;
                            }
                        }
                    }
                    is_referring_char_table = has_ref_transitions && all_char_refs;
                    if (is_referring_char_table) {
                        s.exports = LangAPI::StdlibExports::DfaCharTableState;
                        char_table_states.insert(count);
                    } else {
                        multi_table_states.insert(count);
                    }
                }

                for (const auto &[symbol, transition] : sorted_transitions) {
                    if (std::holds_alternative<stdu::vector<std::string>>(symbol)) {
                        const auto &sym_name = std::get<stdu::vector<std::string>>(symbol);
                        const auto referred_dfa_idx = lexer_builder.getNameToDFAIndex().at(sym_name);
                        const auto &referred_dfa = dfas.at(referred_dfa_idx);
                        bool local_is_referring_char_table = referred_dfa.getType() == DFA::DfaType::Char;

                        LangAPI::IspaLibSymbol new_s;
                        auto token_type_ptr = std::make_shared<LangAPI::Type>(LangAPI::Symbol{"Token"});
                        if (local_is_referring_char_table) {
                            new_s = LangAPI::IspaLibSymbol {
                                .exports = LangAPI::StdlibExports::DfaCharTableTransition,
                                .template_parameters = { token_type_ptr }
                            };
                        } else {
                            new_s = {
                                .exports = LangAPI::StdlibExports::DfaMultiTransition,
                                .template_parameters = { token_type_ptr }
                            };
                        }
                        transitions.push_back(
                            LangAPI::IspaLibDfaTransition::createExpression(
                                LangAPI::IspaLibDfaTransition{
                                    .symbol = referred_dfa_idx,
                                    .next = transition.next,
                                    .new_cst_node = transition.new_cst_node,
                                    .new_member = transition.new_member,
                                    .close_cst_node = transition.close_cst_node,
                                    .new_group = transition.new_group,
                                    .group_close = transition.group_close,
                                    .accept = transition.accept_index,
                                    .transition_type = new_s,
                                    .is_refferring_char_table = local_is_referring_char_table
                                }
                            )
                        );
                    } else {
                        transitions.push_back(
                         LangAPI::IspaLibDfaTransition::createExpression(LangAPI::IspaLibDfaTransition {
                                 .symbol = std::get<char>(symbol),
                                 .next = transition.next,
                                 .new_cst_node = transition.new_cst_node,
                                 .new_member = transition.new_member,
                                 .close_cst_node = transition.close_cst_node,
                                 .new_group = transition.new_group,
                                 .group_close = transition.group_close,
                                 .accept = transition.accept_index,
                                 .transition_type = s,
                                 .is_refferring_char_table = false
                             })
                         );
                    }
                }
            }
            lexer.data.push_back(
                std::make_pair(
	                std::make_shared<LangAPI::Declaration>(LangAPI::Variable::createDeclaration( LangAPI::Variable {
	                .name = std::string("dfa_state_") + std::to_string(count),
	                .type = s,
                    .value = empty && state.else_goto == 0 ? LangAPI::IspaLibDfaEmptyState::createExpression(LangAPI::IspaLibDfaEmptyState {.token_name = state.rule_name, .construction_lambda = std::make_shared<LangAPI::Lambda>(construct_lambda)}) : LangAPI::Array::createExpression(LangAPI::Array { .values = transitions}),
                    .is_static = true
	            })),
                LangAPI::Visibility::Private
                )
            );
            ++count;
        }
        // construct DFA tables
        for (std::size_t dfa_count = 0; dfa_count < dfas.size(); ++dfa_count) {
            const auto &dfa = dfas.at(dfa_count);
            std::vector<LangAPI::Expression> dfa_table_states;
            bool multitable = dfa.getType() == DFA::DfaType::Multi;

            for (std::size_t state_count = 0; state_count < dfa.get().size(); ++state_count) {
                const auto &state_id = states.location_in_set.at(std::make_pair(dfa_count, state_count));
                const auto &state_type = states.state_to_type.at(state_id).first;
                const auto &state = states.state_set.get().at(state_id);

                if (std::holds_alternative<DFA::SortedTransitions>(state.transitions) && std::get<DFA::SortedTransitions>(state.transitions).empty() && state.else_goto == 0) {
                    dfa_table_states.push_back(
                        LangAPI::Symbol::createExpression(LangAPI::Symbol {"Lexer", "dfa_state_" + std::to_string(state_id)})
                    );
                } else {
                    // FIX: Query the exact structural properties that dictate the state's variable declaration type
                    LangAPI::StdlibExports selected_export;

                    if (multi_table_states.contains(state_id)) {
                        // If the header pass declared this state_id as a MultiTableState
                        selected_export = LangAPI::StdlibExports::DfaSpanMultiTableState;
                    } else if (char_table_states.contains(state_id)) {
                        // If the header pass declared this state_id as a CharTableState
                        selected_export = LangAPI::StdlibExports::DfaSpanCharTableState;
                    } else {
                        // Default fallback matching static ::ISPA_STD::DFAAPI::CharState definitions
                        selected_export = LangAPI::StdlibExports::DfaSpanCharState;
                    }

                    LangAPI::IspaLibSymbol span_type = {
                        .exports = selected_export,
                        .template_parameters = {std::make_shared<LangAPI::Type>(Token)}
                    };
                    dfa_table_states.push_back(LangAPI::RValue::createExpression(
                        LangAPI::RValue {LangAPI::Inheritance {
                            .name = span_type,
                            .args = {
                                LangAPI::Int::createExpression(LangAPI::Int {.value = static_cast<long long>(state.else_goto)}),
                                LangAPI::Int::createExpression(LangAPI::Int {.value = static_cast<long long>(state.else_goto_accept)}),
                                LangAPI::Symbol::createExpression(LangAPI::Symbol {"Lexer", "dfa_state_" + std::to_string(state_id)})
                            }
                        }}
                    ));
                }
            }

            auto table_params = std::vector<std::variant<std::shared_ptr<LangAPI::Type>, std::shared_ptr<LangAPI::RValue>>> {
                std::make_shared<LangAPI::Type>(LangAPI::Symbol{"Token"}),
                std::make_shared<LangAPI::RValue>(
                    LangAPI::Int::createRValue(LangAPI::Int {.value = (long long) dfa.get().size()})
                )
            };

            LangAPI::Variable dfa_table_var {
                .name = "dfa_table_" + std::to_string(dfa_count),
                .type = LangAPI::Type {
                    LangAPI::IspaLibSymbol {
                        multitable ? LangAPI::StdlibExports::DfaMultiTable : LangAPI::StdlibExports::DfaCharTable,
                        table_params
                    }
                },
                .value = LangAPI::Array::createExpression(LangAPI::Array { .values = dfa_table_states }),
                .is_static = true
            };
            lexer.data.emplace_back(std::make_shared<LangAPI::Declaration>(LangAPI::Statement::createDeclaration(dfa_table_var)), LangAPI::Visibility::Private);
        }
        holder.push(lexer);
    }
}