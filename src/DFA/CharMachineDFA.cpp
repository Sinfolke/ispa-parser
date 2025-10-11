module DFA.CharMachineDFA;
import logging;
import std;

auto DFA::CharMachineDFA::build() -> const States<CharMachineState>& {
    // move to current class
    auto &sorted_states = sorted_dfa.get();
    auto &states = this->states.get();
    auto states_size = sorted_states.size();
    for (std::size_t i = 0; i < states_size; i++) {
        const auto &state = sorted_states[i];
        auto type = sorted_dfa.getType();
        auto initial_else_goto = state.else_goto;
        if (type == DfaType::Multi) {
            // found multitable - partition using else_goto

            // find where to begin to partition transitions
            std::size_t partition_type = NULL_STATE;
            std::size_t begin = 0;
            for (const auto &[symbol, next] : state.transitions) {
                if (partition_type == NULL_STATE) {
                    partition_type = symbol.index();
                } else if (symbol.index() != partition_type) {
                    break;
                }
                begin++;
            }
            auto partitioned_state = sorted_states.makeNew();
            partition_type = NULL_STATE;
            for (std::size_t j = begin; j < state.transitions.size(); j++) {
                const auto &[symbol, value] = state.transitions.sequence()[j];
                if (partition_type == NULL_STATE) {
                    partition_type = symbol.index();
                    getEmptyStateMap()[partitioned_state] = getEmptyStateMap()[i];
                    getIndexToEmptyStateMap()[partitioned_state] = getIndexToEmptyStateMap()[i];
                } else if (partition_type != symbol.index()) {
                    auto prev = partitioned_state;
                    partitioned_state = sorted_states.makeNew();
                    sorted_states[prev].else_goto = partitioned_state;
                    partition_type = symbol.index();
                    getEmptyStateMap()[partitioned_state] = getEmptyStateMap()[prev];
                    getIndexToEmptyStateMap()[partitioned_state] = getIndexToEmptyStateMap()[prev];
                }
                sorted_states[partitioned_state].transitions.emplace(symbol, value);
            }
            sorted_states[partitioned_state].else_goto = initial_else_goto;
        }
    }
    // add all characters to transition & unroll else_goto in character states
    for (auto &state : sorted_states) {
        FullCharTable char_table;
        if (state.transitions.empty()) {
            states.emplace_back(state.nfa_states, std::variant<FullCharTable, SortedTransitions> {}, state.else_goto, state.else_goto_accept, state.rule_name, state.dtb);
            continue;
        }
        if (std::holds_alternative<char>(state.transitions.begin()->first)) {
            // a state is always either char or advanced in this stage
            for (unsigned char uc = 0; uc < std::numeric_limits<unsigned char>::max() - 1; uc++) {
                auto c = static_cast<char>(uc);
                TransitionValue transition;
                if (state.transitions.contains(c)) {
                    transition = state.transitions.at(c);
                } else {
                    transition.next = NULL_STATE;
                }
                char_table[c] = transition;
            }
            states.emplace_back(state.nfa_states, char_table, state.else_goto, state.else_goto_accept, state.rule_name, state.dtb);
        } else {
            states.emplace_back(state.nfa_states, state.transitions, state.else_goto, state.else_goto_accept, state.rule_name, state.dtb);
        }
    }
    return this->states;
}
auto DFA::CharMachineDFA::getType() const -> DfaType {
    return Base::getType(states);
}
auto DFA::CharMachineDFA::clear() -> void {
    states.clear();
}

