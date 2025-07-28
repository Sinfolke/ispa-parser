module DFAS;
import cpuf.printf;
import std;
void DFAS::getStateSet(StateSet_t &state_set) const {
    utype::unordered_map<std::pair<DFA::SingleState, DFA::DfaType>, std::size_t> state_to_map;
    std::size_t dfa_count = 0;
    for (const auto &dfa : dfas) {
        std::size_t state_count = 0;
        for (const auto &state : dfa.getStates()) {
            if (!isToken && state.transitions.empty()) {
                state_count++;
                continue;
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
auto DFAS::getStateSet() const -> StateSet_t {
    StateSet_t state_set;
    getStateSet(state_set);
    return state_set;
}
