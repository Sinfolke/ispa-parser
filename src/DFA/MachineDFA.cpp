module DFA.MachineDFA;
import logging;
import std;

auto DFA::MachineDFA::build() -> States<SortedState> {
    // move to current class
    Assert(!sorted_dfa.get().empty(), "Empty sorted DFA");
    for (auto &state : sorted_dfa.get()) {
        auto new_state_id = states.makeNew();
        states[new_state_id] = std::move(state);
    }
    if (!sorted_dfa.isMerged())
        return states;
    auto states_size = states.size();
    for (std::size_t i = 0; i < states_size; i++) {
        const auto &state = states[i];
        auto type = getType(false, nullptr);
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
            auto partitioned_state = states.makeNew();
            partition_type = NULL_STATE;
            for (std::size_t j = begin; j < state.transitions.size(); j++) {
                const auto &[symbol, value] = state.transitions.sequence()[j];
                if (partition_type == NULL_STATE) {
                    partition_type = symbol.index();
                } else if (partition_type != symbol.index()) {
                    auto prev = partitioned_state;
                    partitioned_state = states.makeNew();
                    states[prev].else_goto = partitioned_state;
                    partition_type = symbol.index();
                }
                states[partitioned_state].transitions.emplace(symbol, value);
            }
            states[partitioned_state].else_goto = initial_else_goto;
        }
    }
    // add all characters to transition & unroll else_goto in character states
    for (auto &state : states) {
        bool notCharState = false;
        for (const auto &[symbol, value] : state.transitions) {
            if (!std::holds_alternative<char>(symbol)) {
                notCharState = true;
                break;
            }
        }
        if (notCharState)
            continue;

        for (unsigned char uc = 0; uc < std::numeric_limits<unsigned char>::max() - 1; uc++) {
            auto c = static_cast<char>(uc);
            if (state.transitions.contains(c)) {
                continue;
            }
            state.transitions.emplace(c, state.else_goto ? state.else_goto : NULL_STATE);
        }
        state.else_goto = 0;
    }
    return states;
}
auto DFA::MachineDFA::getType(bool isToken, const utype::unordered_map<stdu::vector<std::string>, std::size_t> *dct) const -> DfaType {
    return Base::getType(states, isToken, dct);
}
auto DFA::MachineDFA::clear() -> void {
    states.clear();
}

