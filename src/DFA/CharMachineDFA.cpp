module DFA.CharMachineDFA;
import logging;
import std;
import cpuf.printf;

auto DFA::CharMachineDFA::build() -> const States<CharMachineState>& {
    // move to current class
    auto &sorted_states = sorted_dfa.get();
    auto &states = this->states.get();
    auto states_size = sorted_states.size();
    for (std::size_t i = 0; i < states_size; i++) {
        auto type = sorted_dfa.getStateType(sorted_states[i].transitions);
        auto initial_else_goto = sorted_states[i].else_goto;
        if (type == DfaType::Multi && !sorted_states[i].transitions.empty()) {
            // Copy maps from the original state

            std::size_t current_type = sorted_states[i].transitions.begin()->first.index();
            std::size_t partitioned_state = i;
            SortedState *current_partition = nullptr;
            std::size_t erase_from = sorted_states[i].transitions.size();
            for (std::size_t j = 0; j < sorted_states[i].transitions.size(); ++j) {
                const auto &[symbol, value] = sorted_states[i].transitions[j];
                if (symbol.index() != current_type) {
                    // Start a new partition
                    auto new_state = sorted_states.makeNew();
                    if (current_partition == nullptr) {
                        sorted_states[i].else_goto = new_state;
                        erase_from = j;
                    } else {
                        current_partition->else_goto = new_state;
                    }

                    getEmptyStateMap()[new_state] = getEmptyStateMap()[partitioned_state];
                    getIndexToEmptyStateMap()[new_state] = getIndexToEmptyStateMap()[partitioned_state];

                    current_type = symbol.index();
                    current_partition = &sorted_states[new_state];
                    partitioned_state = new_state;
                } else if (current_partition == nullptr)
                    continue;

                current_partition->transitions.emplace_back(symbol, value);
            }

            // Connect the last partition to the original else_goto
            if (current_partition != nullptr) {
                current_partition->else_goto = initial_else_goto;
                sorted_states[i].transitions.erase(sorted_states[i].transitions.begin() + erase_from, sorted_states[i].transitions.end());
            }
        }
    }
    // add all characters to transition & unroll else_goto in character states
    bool has_multi_state = false;
    for (auto &state : sorted_states) {
        FullCharTable char_table;
        if (state.transitions.empty()) {
            states.emplace_back(state.nfa_states, std::variant<FullCharTable, SortedTransitions> {SortedTransitions {}}, state.else_goto, state.else_goto_accept, state.rule_name, state.dtb);
            cpuf::printf("State empty");
            continue;
        }
        if (std::holds_alternative<char>(state.transitions.begin()->first)) {
            // a state is always either char or advanced in this stage
            for (unsigned char uc = 0; uc < std::numeric_limits<unsigned char>::max() - 1; uc++) {
                auto c = static_cast<char>(uc);
                TransitionValue transition;
                if (auto it = std::find_if(state.transitions.begin(), state.transitions.end(), [&](const auto &v) { return std::get<char>(v.first) == c; }); it != state.transitions.end()) {
                    transition = it->second;
                } else {
                    transition.next = NULL_STATE;
                }
                char_table[c] = transition;
            }
            states.emplace_back(state.nfa_states, char_table, state.else_goto, state.else_goto_accept, state.rule_name, state.dtb);
        } else {
            has_multi_state = true;
            states.emplace_back(state.nfa_states, state.transitions, state.else_goto, state.else_goto_accept, state.rule_name, state.dtb);
        }
    }
    cpuf::printf("has multi state: {}", has_multi_state);
    return this->states;
}
auto DFA::CharMachineDFA::getType() const -> DfaType {
    return Base::getType(states);
}
auto DFA::CharMachineDFA::clear() -> void {
    states.clear();
}

