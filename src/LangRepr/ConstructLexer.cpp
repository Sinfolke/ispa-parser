module LangRepr.ConstructLexer;

import LLIR.Builder.Base;
import cpuf.printf;
import NFA;
import DFA.API;
import LangAPI;
import logging;
import std;

// -----------------------------------------------------------------------
// ARCHITECTURE NOTE
//
// Exactly two tables are emitted:
//
//   1. dfa_table       -- the actual (unified, classified) DFA. No FCDT,
//                          no per-token spans. State 0 is the single
//                          shared start state for every token.
//   2. char_class_table -- raw byte -> class id, shared globally across
//                          every state in dfa_table.
//
// No third table for acceptance. Instead, wherever a transition would
// have pointed at a materialized "empty"/accepting placeholder state, the
// target is encoded directly as:
//
//       state_count + 1 + <token enum value>
//
// i.e. any `next` value >= state_count is not a real state index at all;
// it's an accept marker, and the matched token id is `next - state_count
// - 1`. Genuinely dead transitions (no match, no accept) keep using
// DFA::NULL_STATE, which is far outside this range, so the three cases
// (real state / accept sentinel / dead) never collide:
//
//     next <  state_count           -> real continuing state
//     next == DFA::NULL_STATE       -> dead transition
//     otherwise (next > state_count)-> accept for token (next - state_count - 1)
//
// This removes the need to ever materialize placeholder "empty" states,
// and removes any separate accept_table/construct_table -- the token id
// is recoverable by arithmetic directly from the transition that was
// actually taken, with zero extra storage.
//
// RUNTIME TYPE ASSUMPTION: DFAAPI::Table<N> as given constrains state
// count == class count via a single template parameter. That only holds
// by coincidence; this file assumes the corrected two-parameter form:
//
//   template<std::size_t Classes> using State = std::array<std::size_t, Classes>;
//   template<std::size_t States, std::size_t Classes>
//   using Table = std::array<State<Classes>, States>;
//
// The runtime's DfaLookup lowering must decode accept sentinels using the
// SAME formula used here to encode them -- these two sides have to agree
// bit-for-bit.
// -----------------------------------------------------------------------

namespace LangRepr {

    auto ConstructLexer::makeCharClassTableDecl(const DFA::CharClassTable &table)
        -> std::pair<std::shared_ptr<LangAPI::Declaration>, LangAPI::Visibility> {

        LangAPI::Array arr;
        arr.values.reserve(256);
        for (std::size_t c = 0; c < 256; ++c) {
            arr.values.push_back(
                LangAPI::Int::createExpression(LangAPI::Int {
                    .value = static_cast<long long>(table.char_to_class[c])
                })
            );
        }

        LangAPI::IspaLibSymbol class_table_symbol {.exports = LangAPI::StdlibExports::DfaClassTable};
        class_table_symbol.template_parameters.push_back(
            std::make_shared<LangAPI::RValue>(LangAPI::Int {.value = 256})
        );

        LangAPI::Variable var {
            .name = "char_class_table",
            .type = LangAPI::Type {class_table_symbol},
            .value = LangAPI::Array::createExpression(arr),
            .is_static = true
        };

        return {
            std::make_shared<LangAPI::Declaration>(LangAPI::Variable::createDeclaration(var)),
            LangAPI::Visibility::Private
        };
    }

    // Emits the single unified transition table. Each entry is a plain
    // size_t, sentinel-encoded per the scheme above -- no wrapper type,
    // no per-transition metadata struct, since acceptance now lives
    // entirely in the numeric value rather than needing its own field.
    auto ConstructLexer::makeDfaTableDecl(
        const auto &states,          // iterable of DFA::State<DFA::ClassTransitions>
        std::size_t state_count,
        std::size_t class_count
    ) -> std::pair<std::shared_ptr<LangAPI::Declaration>, LangAPI::Visibility> {

        stdu::vector<LangAPI::Expression> rows;
        rows.reserve(state_count);

        for (const auto &state : states) {
            stdu::vector<LangAPI::Expression> row;
            row.reserve(class_count);

            for (std::size_t cls = 0; cls < class_count; ++cls) {
                std::size_t encoded = DFA::NULL_STATE;

                if (cls < state.transitions.size()) {
                    const auto &t = state.transitions[cls];
                    if (t.accept_index != DFA::NULL_STATE) {
                        // This transition completes a token -- encode
                        // directly, no placeholder state ever created.
                        encoded = state_count + 1 + t.accept_index;
                    } else if (t.next != DFA::NULL_STATE) {
                        encoded = t.next; // real continuing state
                    }
                    // else: leave as DFA::NULL_STATE -- genuinely dead
                }

                row.push_back(LangAPI::Int::createExpression(LangAPI::Int {
                    .value = static_cast<long long>(encoded)
                }));
            }
            rows.push_back(LangAPI::Array::createExpression(LangAPI::Array {.values = row}));
        }

        LangAPI::IspaLibSymbol dfa_table_symbol {.exports = LangAPI::StdlibExports::DfaTable};
        dfa_table_symbol.template_parameters.push_back(
            std::make_shared<LangAPI::RValue>(LangAPI::Int {.value = static_cast<long long>(state_count)})
        );
        dfa_table_symbol.template_parameters.push_back(
            std::make_shared<LangAPI::RValue>(LangAPI::Int {.value = static_cast<long long>(class_count)})
        );

        LangAPI::Variable var {
            .name = "dfa_table",
            .type = LangAPI::Type {dfa_table_symbol},
            .value = LangAPI::Array::createExpression(LangAPI::Array {.values = rows}),
            .is_static = true
        };

        return {
            std::make_shared<LangAPI::Declaration>(LangAPI::Variable::createDeclaration(var)),
            LangAPI::Visibility::Private
        };
    }

    auto ConstructLexer::constructLexer() -> void {
        holder.push(LangAPI::TypeAlias::createDeclaration(createTypeToken()));
        Tlog::Branch b(logger, "LangRepr/ConstructLexer.log");
        auto lexer = createLexerClass();

        // Single unified, classified DFA -- no per-token list, no FCDT.
        const auto &dfa = lexer_builder.getDFA();
        const auto &class_table = dfa.table;
        const auto &states = dfa.states.get();
        const std::size_t state_count = states.size();
        const std::size_t class_count = class_table.num_classes;

        logger.log("---- [0] LEXER: CHAR CLASS TABLE ----");
        lexer.data.push_back(makeCharClassTableDecl(class_table));

        logger.log("---- [1] LEXER: DFA TABLE (accept sentinel-encoded) ----");
        lexer.data.push_back(makeDfaTableDecl(states, state_count, class_count));

        if (lexer_builder.getDFA().states.size() > 0) {
            lexer.data.push_back(std::make_pair(
                std::make_shared<LangAPI::Declaration>(LangAPI::Variable::createDeclaration(LangAPI::Variable {
                    .type = LangAPI::ValueType::Bool, .name = "init_done",
                    .value = LangAPI::Bool::createExpression(LangAPI::Bool {.value = false})
                })),
                LangAPI::Visibility::Private
            ));
            lexer.data.push_back(std::make_pair(
                std::make_shared<LangAPI::Declaration>(LangAPI::Function::createDeclaration(LangAPI::Function {
                    .type = LangAPI::ValueType::Void, .name = "init", .override = true
                })),
                LangAPI::Visibility::Private
            ));
        }

        // makeToken is a single DfaLookup expression -- the runtime
        // backing it is expected to walk dfa_table from state 0, using
        // char_class_table for dispatch, and decode any `next >=
        // state_count` as an accept for token `next - state_count - 1`
        // (same formula used above to encode the table). No FCDT, no
        // spans, no separate accept/construct tables to pass in --
        // dfa_table's own type already carries state_count/class_count.
        LangAPI::DfaLookup lookup {
            .dfa_count = 1,           // ASSUMPTION: "number of DFA tables"
                                       // is now always 1 under the unified
                                       // design. If the DfaLookup backend
                                       // actually expects this field to
                                       // carry state_count (for the
                                       // sentinel-decode threshold instead
                                       // of reading it off dfa_table's own
                                       // type), change this to state_count.
            .return_type = LangAPI::Type {Token},
            .output_name = "token"    // ASSUMPTION: bound result name;
                                       // adjust to match whatever the
                                       // DfaLookup lowering expects here.
        };

        lexer.data.push_back(
            std::make_pair(
                std::make_shared<LangAPI::Declaration>(LangAPI::Function::createDeclaration(LangAPI::Function {
                    .type = LangAPI::Type {Token},
                    .name = "makeToken",
                    .parameters = {std::make_pair(
                        LangAPI::Type {LangAPI::IspaLibSymbol {
                            .exports = LangAPI::StdlibExports::LexerMakeTokenParameter,
                            .Const = true, .Reference = true
                        }},
                        std::string("pos")
                    )},
                    .statements = LangAPI::Return::createStatements(LangAPI::Return {
                        .value = LangAPI::DfaLookup::createExpression(lookup)
                    }),
                    .override = true,
                })),
                LangAPI::Visibility::Public
            )
        );

        holder.push(lexer);
    }
}