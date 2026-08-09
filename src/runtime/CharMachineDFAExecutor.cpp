// module DFA.Runtime;
//
// import DFA.CharMachineDFA;
// import DFA.API;
// import logging;
// import std;
// auto DFA::Runtime::CharMachineDFAExecutor::find_key(const DFA::FullCharTable &state, char input) const -> DFA::TransitionValue {
//     return state[static_cast<unsigned char>(input)];
// }
// auto DFA::Runtime::CharMachineDFAExecutor::find_key(const DFA::SortedTransitions &state, std::string_view input) const -> std::tuple<DFA::TransitionValue, decltype(Runtime::ExecutionResult::values), std::size_t> {
//     using Ret = std::tuple<DFA::TransitionValue, decltype(ExecutionResult::values), std::size_t>;
//     if (input.empty()) {
//         return Ret{DFA::TransitionValue{}, {}, 0};
//     }
//     for (const auto &[name, transition] : state) {
//         if (std::holds_alternative<char>(name)) {
//             if (input.front() == std::get<char>(name)) {
//                 return Ret{transition, {}, 1};
//             }
//         } else {
//             // Nested name transition: requires lexer_builder to resolve
//             if (!lexer_builder) {
//                 continue;
//             }
//             const auto &sym_name = std::get<stdu::vector<std::string>>(name);
//             const auto &name_map = lexer_builder->getNameToDFAIndex();
//             auto it = name_map.find(sym_name);
//             if (it == name_map.end()) continue;
//             const auto table_id = it->second;
//             // run table separately
//             const auto &sub_dfa = lexer_builder->getDFA().get();;
//             CharMachineDFAExecutor table_executor(sub_dfa, *lexer_builder);
//             auto result = table_executor.execute(input);
//             if (result.accepted && result.consumed_length > 0) {
//                 return Ret{transition, result.values, result.consumed_length};
//             }
//         }
//     }
//     return Ret{DFA::TransitionValue{}, {}, 0};
// }
//
// auto DFA::Runtime::CharMachineDFAExecutor::execute(std::string_view input) const -> ExecutionResult {
//     ExecutionResult res{};
//     std::size_t pos = 0;
//     std::size_t state_id = 0;
//
//     std::size_t last_pos = std::numeric_limits<std::size_t>::max();
//     std::size_t last_state_id = DFA::NULL_STATE;
//
//     while (true) {
//         if (pos == last_pos && state_id == last_state_id) {
//             break;
//         }
//         last_pos = pos;
//         last_state_id = state_id;
//
//         const auto &state = dfa.get().get().at(state_id);
//         std::cout << "DFA State: " << state_id << " Pos: " << pos << "/" << input.size() << " Current Char: "
//                   << (pos < input.size() ? std::string(1, input[pos]) : "EOF") << std::endl;
//         if (std::holds_alternative<DFA::SortedTransitions>(state.transitions)) {
//             const auto &tr = std::get<DFA::SortedTransitions>(state.transitions);
//             std::cout << "  Type: SortedTransitions, size: " << tr.size() << std::endl;
//         } else if (std::holds_alternative<DFA::FullCharTable>(state.transitions)) {
//             std::cout << "  Type: FullCharTable" << std::endl;
//         }
//         if (state.else_goto != 0) std::cout << "  else_goto: " << state.else_goto << std::endl;
//         if (state.else_goto_accept != DFA::NULL_STATE) std::cout << "  else_goto_accept: " << state.else_goto_accept << std::endl;
//         // If no transitions (empty vector in SortedTransitions), stop
//         if (std::holds_alternative<DFA::SortedTransitions>(state.transitions)) {
//             const auto &tr = std::get<DFA::SortedTransitions>(state.transitions);
//             if (tr.empty()) {
//                 break;
//             }
//             if (pos >= input.size()) {
//                 // End of input, accept via else_goto_accept if available
//                 if (state.else_goto_accept != DFA::NULL_STATE) {
//                     res.accepted = true;
//                     res.accept_index = state.else_goto_accept;
//                 }
//                 break;
//             }
//             auto [tv, captured, consumed] = find_key(tr, input.substr(pos));
//             if (tv.next == DFA::NULL_STATE) {
//                 // fallback to else_goto_accept if any
//                 if (state.else_goto_accept != DFA::NULL_STATE) {
//                     res.accepted = true;
//                     res.accept_index = state.else_goto_accept;
//                     break;
//                 }
//                 // fallback to else_goto if no match but else_goto is set
//                 if (state.else_goto != 0) {
//                     state_id = state.else_goto;
//                     continue;
//                 }
//                 break;
//             }
//             // apply consume
//             pos += consumed;
//             // merge captured values from nested match
//             for (auto &p : captured) {
//                 res.values[p.first] += p.second;
//             }
//             state_id = tv.next;
//             if (tv.accept_index != DFA::NULL_STATE) {
//                 res.accepted = true;
//                 res.accept_index = tv.accept_index;
//             }
//             continue;
//         }
//         // Full char table case
//         if (std::holds_alternative<DFA::FullCharTable>(state.transitions)) {
//             if (pos >= input.size()) {
//                 if (state.else_goto_accept != DFA::NULL_STATE) {
//                     res.accepted = true;
//                     res.accept_index = state.else_goto_accept;
//                 }
//                 break;
//             }
//             const auto &tbl = std::get<DFA::FullCharTable>(state.transitions);
//             auto tv = find_key(tbl, input[pos]);
//             if (tv.next == DFA::NULL_STATE) {
//                 if (state.else_goto_accept != DFA::NULL_STATE) {
//                     res.accepted = true;
//                     res.accept_index = state.else_goto_accept;
//                     std::cout << "  Accepting via else_goto_accept: " << state.else_goto_accept << std::endl;
//                     break;
//                 }
//                 if (state.else_goto != 0) {
//                     state_id = state.else_goto;
//                     std::cout << "  Transitioning via else_goto: " << state.else_goto << std::endl;
//                     continue;
//                 }
//                 break;
//             }
//             ++pos;
//             state_id = tv.next;
//             if (tv.accept_index != DFA::NULL_STATE) {
//                 res.accepted = true;
//                 res.accept_index = tv.accept_index;
//             }
//             continue;
//         }
//         // Unknown state variant; stop
//         break;
//     }
//
//     res.consumed_length = pos;
//     return res;
// }