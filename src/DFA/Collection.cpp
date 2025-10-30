module DFA.Collection;
import DFA.TokenMachineDFA;
import DFA.CharMachineDFA;
import DFA.Base;
import LangAPI;
import std;

template<typename DfaTable>
void DFA::Collection<DfaTable>::getStateSet(StateSet_t &state_set) const {
    // NOTE: StateType must be hashable and comparable for state_to_map to work correctly.
    utype::unordered_map<typename DfaTable::StateType, std::size_t> state_to_map;

    std::size_t dfa_index = 0;
    for (const auto &dfa : collection) {
        std::size_t local_state_index = 0;
        // Determine DFA-level type once (authoritative)
        const auto dfa_type = dfa.getType();

        for (const auto &state : dfa.get()) {
            // Skip empty states consistently for Char DFAs (same logic as before)
            if (!isToken) {
                if constexpr (std::is_same_v<DfaTable, CharMachineDFA>) {
                    const auto* full = std::get_if<FullCharTable>(&state.transitions);
                    const auto* sorted = std::get_if<SortedTransitions>(&state.transitions);
                    if ((full && full->empty()) || (sorted && sorted->empty())) {
                        ++local_state_index;
                        continue;
                    }
                } else {
                    if (state.transitions.empty()) {
                        ++local_state_index;
                        continue;
                    }
                }
            }

            // Deduplicate identical states (requires correct StateType hash/eq)
            auto it = state_to_map.find(state);
            std::size_t global_index;
            if (it == state_to_map.end()) {
                global_index = state_set.state_set.size();
                state_set.state_set.get().push_back(state);
                state_to_map.emplace(state, global_index);

                // Decide per-state type robustly: prefer DFA-level type when applicable,
                // otherwise inspect the state's transitions variant to decide.
                DFA::DfaType effective_state_type = DFA::DfaType::Multi; // default
                if constexpr (std::is_same_v<DfaTable, CharMachineDFA>) {
                    if (std::get_if<FullCharTable>(&state.transitions)) {
                        effective_state_type = DFA::DfaType::Char;
                    } else if (std::get_if<SortedTransitions>(&state.transitions)) {
                        effective_state_type = DFA::DfaType::Multi;
                    }
                } else {
                    // For non-Char DFAs, use DFA-level type
                    effective_state_type = dfa_type;
                }

                // If you want DFA-level to override per-state when consistent:
                // if (dfa_type == DFA::DfaType::Char) effective_state_type = DFA::DfaType::Char;

                // Use the DFA's empty-state index to get rule_name — ensure getEmptyState expects local_state_index
                auto empty_state_idx = dfa.getEmptyState(local_state_index);
                auto rule_name = dfa.get()[empty_state_idx].rule_name;

                state_set.state_to_type.emplace(global_index, std::make_pair(effective_state_type, rule_name));
            } else {
                global_index = it->second;
            }

            state_set.location_in_set[std::make_pair(dfa_index, local_state_index)] = global_index;
            state_set.state_in_dfa_location_map[global_index] = dfa_index;

            ++local_state_index;
        }
        ++dfa_index;
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