module DFAS;
import std;
void DFAS::getStateSet(StateSet &state_set, StateSetLocationMap &location_in_set) const {
    utype::unordered_map<DFA::Transitions, std::size_t> state_to_map;

    std::size_t dfa_count = 0;
    for (const auto &dfa : dfas) {
        std::size_t state_count = 0;
        for (const auto &state : dfa.getStates()) {
            auto it = state_to_map.find(state.transitions);
            std::size_t index;
            if (it == state_to_map.end()) {
                index = state_set.size();
                state_set.insert(state.transitions);
                state_to_map.emplace(state.transitions, index);
            } else {
                index = it->second;
            }
            location_in_set[{dfa_count, state_count++}] = index;
        }
        ++dfa_count;
    }
}
auto DFAS::getStateSet() const -> std::pair<StateSet, StateSetLocationMap> {
    StateSet transition_set;
    StateSetLocationMap location_in_set;
    getStateSet(transition_set, location_in_set);
    return {transition_set, location_in_set};
}
