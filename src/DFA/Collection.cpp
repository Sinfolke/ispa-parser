module DFA.Collection;
import DFA.TokenMachineDFA;
import DFA.CharMachineDFA;
import DFA.Base;
import LangAPI;
import std;
import cpuf.printf;

template<typename DfaTable>
void DFA::Collection<DfaTable>::getStateSet(StateSet_t &state_set) const {
    // To prevent the "Local Index Trap", include the dfa_index in the deduplication key
    // if your states still contain raw local transition offsets.
    utype::unordered_map<std::pair<std::size_t, typename DfaTable::StateType>, std::size_t> state_to_map;

    std::size_t dfa_index = 0;
    for (const auto &dfa : collection) {
        std::size_t local_state_index = 0;
        const auto dfa_type = dfa.getType();

        for (const auto &state : dfa.get()) {
            if (!isToken) {
                bool is_empty = false;
                if constexpr (std::is_same_v<DfaTable, CharMachineDFA>) {
                    const auto* full = std::get_if<FullCharTable>(&state.transitions);
                    const auto* sorted = std::get_if<SortedTransitions>(&state.transitions);
                    if ((full && full->empty()) || (sorted && sorted->empty())) is_empty = true;
                } else {
                    if (state.transitions.empty()) is_empty = true;
                }

                if (is_empty) {
                    // Register a safe placeholder global index or map to a unified dead state
                    // right here instead of doing a blind 'continue'.
                }
            }

            // FIX 3: Keying by both dfa_index and state to prevent cross-DFA index collisions
            auto lookup_key = std::make_pair(dfa_index, state);
            auto it = state_to_map.find(lookup_key);
            std::size_t global_index;

            if (it == state_to_map.end()) {
                global_index = state_set.state_set.size();
                state_set.state_set.get().push_back(state);
                state_to_map.emplace(lookup_key, global_index);

                DFA::DfaType effective_state_type = DFA::DfaType::Multi;
                if constexpr (std::is_same_v<DfaTable, CharMachineDFA>) {
                    if (std::get_if<FullCharTable>(&state.transitions)) {
                        effective_state_type = DFA::DfaType::Char;
                    } else if (std::get_if<SortedTransitions>(&state.transitions)) {
                        effective_state_type = DFA::DfaType::Multi;
                    }
                } else {
                    effective_state_type = dfa_type;
                }

                // FIX 1: Defend against virtual empty state IDs exceeding vector boundaries
                auto empty_state = dfa.getEmptyStateIF(local_state_index);
                stdu::vector<std::string> rule_name;
                if (empty_state != NULL_STATE) {
                    state_set.state_to_type.emplace(global_index, std::make_pair(effective_state_type, dfa.get()[empty_state].rule_name));
                } else {
                    state_set.state_to_type.emplace(global_index, std::make_pair(effective_state_type, stdu::vector<std::string> {}));
                }


                // FIX 2: Only assign the original/authoritative creator location
                state_set.state_in_dfa_location_map[global_index] = std::make_pair(dfa_index, local_state_index);
            } else {
                global_index = it->second;
            }

            // This directional map is always safe to write for every occurrence
            state_set.location_in_set[std::make_pair(dfa_index, local_state_index)] = global_index;

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