module DFA.Collection;
import DFA.TokenMachineDFA;
import DFA.CharMachineDFA;
import std;

template<typename DfaTable>
void DFA::Collection<DfaTable>::getStateSet(StateSet_t &state_set) const {
    utype::unordered_map<std::pair<typename DfaTable::StateType, DfaType>, std::size_t> state_to_map;
    std::size_t dfa_count = 0;
    for (const auto &dfa : collection) {
        std::size_t state_count = 0;
        for (const auto &state : dfa.get()) {
            if (!isToken) {
                if constexpr (std::is_same_v<DfaTable, CharMachineDFA>) {
                    // In this case transitions is a variant<FullCharTable, SortedTransitions>
                    const auto* full = std::get_if<FullCharTable>(&state.transitions);
                    const auto* sorted = std::get_if<SortedTransitions>(&state.transitions);

                    if ((full && full->empty()) || (sorted && sorted->empty())) {
                        state_count++;
                        continue;
                    }
                } else {
                    // In all other DFAs, transitions is just a map
                    if (state.transitions.empty()) {
                        state_count++;
                        continue;
                    }
                }
            }
            auto type = dfa.getType();
            auto it = state_to_map.find(std::make_pair(state, type));
            std::size_t index;
            if (it == state_to_map.end()) {
                index = state_set.state_set.size();
                state_set.state_set.get().push_back(state);
                state_to_map.emplace(std::make_pair(state, type), index);
            } else {
                index = it->second;
            }
            state_set.location_in_set[std::make_pair(dfa_count, state_count++)] = index;
            state_set.state_in_dfa_location_map[index] = dfa_count;
        }
        dfa_count++;
    }
}
template<typename DfaTable>
auto DFA::Collection<DfaTable>::getStateSet() const -> StateSet_t {
    StateSet_t state_set;
    getStateSet(state_set);
    return state_set;
}

template void DFA::Collection<DFA::CharMachineDFA>::getStateSet(StateSet_t &state_set) const;
template auto DFA::Collection<DFA::CharMachineDFA>::getStateSet() const -> StateSet_t;

template void DFA::Collection<DFA::TokenMachineDFA>::getStateSet(StateSet_t &state_set) const;
template auto DFA::Collection<DFA::TokenMachineDFA>::getStateSet() const -> StateSet_t;