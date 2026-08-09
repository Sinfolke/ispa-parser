export module DFA.Runtime;

import DFA.API;
import DFA;
import LexerBuilder;
import hash;
import std;
import dstd;

// export namespace DFA::Runtime {
//
//     struct ExecutionResult {
//         bool accepted = false;
//         std::size_t consumed_length = 0;
//         utype::unordered_map<stdu::vector<std::string>, std::string> values;
//         std::size_t accept_index = DFA::NULL_STATE;
//     };
//
//     class CharMachineDFAExecutor {
//         const DFA &dfa;
//         LexerBuilder *lexer_builder = nullptr; // optional, required only for nested-name transitions
//         auto find_key(const D &state, char c) const -> TransitionValue;
//         // returns: transition, captured values, consumed length
//         auto find_key(const DFA::SortedTransitions &state, std::string_view input) const -> std::tuple<TransitionValue, decltype(ExecutionResult::values), std::size_t>;
//     public:
//         explicit CharMachineDFAExecutor(const CharMachineDFA &dfa, LexerBuilder &lexer_builder) : dfa(dfa), lexer_builder(&lexer_builder) {}
//         explicit CharMachineDFAExecutor(const CharMachineDFA &dfa) : dfa(dfa), lexer_builder(nullptr) {}
//         auto execute(std::string_view input) const -> ExecutionResult;
//     };
//
// }
