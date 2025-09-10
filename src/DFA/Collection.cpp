module DFA.Collection;
import DFA.TokenMachineDFA;
import DFA.CharMachineDFA;
import std;

template<typename DfaTable>
void DFA::Collection<DfaTable>::getStateSet(StateSet_t &state_set) const {
    utype::unordered_map<std::pair<typename DfaTable::StatesType, DfaType>, std::size_t> state_to_map;
    std::size_t dfa_count = 0;
    for (const auto &dfa : collection) {
        std::size_t state_count = 0;
        for (const auto &state : dfa.get()) {
            if (!isToken) {
                auto is_empty_variant = [&](auto type_ptr) {
                    if constexpr (std::is_same_v<DfaTable, CharMachineDFA>) {
                        return type_ptr && type_ptr->empty();
                    } else return state.transitions.empty();
                };

                if (is_empty_variant(std::get_if<FullCharTable>(&state.transitions)) ||
                    is_empty_variant(std::get_if<SortedTransitions>(&state.transitions))) {
                    state_count++;
                    continue;
                }
            }
            auto type = dfa.getType(isToken, dct);
            auto it = state_to_map.find(std::make_pair(state, type));
            std::size_t index;
            if (it == state_to_map.end()) {
                index = state_set.state_set.size();
                state_set.state_set.push_back(state);
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