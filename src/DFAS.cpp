module DFAS;
import cpuf.printf;
import std;
void DFAS::getStateSet(StateSet_t &state_set) const {
    utype::unordered_map<DFA::Transitions, std::size_t> state_to_map;
    std::size_t dfa_count = 0;
    for (const auto &dfa : dfas) {
        std::size_t state_count = 0;
        for (const auto &state : dfa.getStates()) {
            auto it = state_to_map.find(state.transitions);
            std::size_t index;
            if (it == state_to_map.end()) {
                index = state_set.state_set.size();
                state_set.state_set.push_back(state.transitions);
                state_to_map.emplace(state.transitions, index);
            } else {
                index = it->second;
            }
            state_set.location_in_set[std::make_pair(dfa_count, state_count++)] = index;
            state_set.state_in_dfa_location_map[state_set.state_set.size() - 1] = dfa_count;
        }
        dfa_count++;
    }
    // Deduplicate state_set:
    StateSet deduped_states;
    deduped_states.reserve(state_set.state_set.size());  // reserve max possible size
    utype::unordered_map<std::size_t, std::size_t> old_to_new_index;
    utype::unordered_map<DFA::Transitions, std::size_t> dedup_map;

    for (std::size_t old_idx = 0; old_idx < state_set.state_set.size(); ++old_idx) {
        const auto &state = state_set.state_set[old_idx];
        auto it = dedup_map.find(state);
        if (it == dedup_map.end()) {
            // New unique state, add to deduped vector
            std::size_t new_idx = deduped_states.size();
            deduped_states.push_back(state);
            dedup_map.emplace(state, new_idx);
            old_to_new_index[old_idx] = new_idx;
        } else {
            // Already seen state
            old_to_new_index[old_idx] = it->second;
        }
    }

    // Replace original state_set with deduplicated one
    state_set.state_set = std::move(deduped_states);

    // Update indices in location_in_set to new deduplicated indices
    for (auto &[key, old_idx] : state_set.location_in_set) {
        old_idx = old_to_new_index[old_idx];
    }

}
auto DFAS::getStateSet() const -> StateSet_t {
    StateSet_t state_set;
    getStateSet(state_set);
    return state_set;
}
