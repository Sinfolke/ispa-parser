module DFA.MachineDFA;
import std;

auto DFA::MachineDFA::build() -> States<SortedState> {
    for (std::size_t i = 0; i < sorted_dfa.get().size(); i++) {
        const auto &state = sorted_dfa.get().get()[i];
        auto type = sorted_dfa.getType(false, nullptr);
        auto initial_else_goto = state.else_goto;
        if (type == DfaType::Multi) {
            // found multitable - partition using else_goto

            // find where to begin to partition transitions
            std::size_t type = NULL_STATE;
            std::size_t begin = 0;
            for (const auto &[symbol, next] : state.transitions) {
                if (type == NULL_STATE) {
                    type = symbol.index();
                } else if (symbol.index() != type) {
                    break;
                }
                begin++;
            }
            auto partitioned_state = sorted_dfa.get().makeNew();
            type = NULL_STATE;
            for (std::size_t j = begin; j < state.transitions.size(); j++) {
                const auto &[symbol, value] = state.transitions.sequence()[j];
                if (type == NULL_STATE) {
                    type = symbol.index();
                } else if (type != symbol.index()) {
                    auto prev = partitioned_state;
                    partitioned_state = sorted_dfa.get().makeNew();
                    sorted_dfa.get()[prev].else_goto = partitioned_state;
                }
                sorted_dfa.get()[partitioned_state].transitions.emplace(symbol, value);
            }
        }
    }
    // move to current class
    for (auto &state : sorted_dfa.get()) {
        auto new_state_id = states.makeNew();
        states[new_state_id] = std::move(state);
    }
    return states;
}
auto DFA::MachineDFA::getType(bool isToken, const utype::unordered_map<stdu::vector<std::string>, std::size_t> *dct) const -> DfaType {
    return Base::getType(states, isToken, dct);
}
