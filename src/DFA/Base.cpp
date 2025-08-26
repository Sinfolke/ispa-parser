module DFA.Base;
import logging;
import std;

auto DFA::Base::getEmptyState(std::size_t stateIndex) -> std::size_t {
    if (!dfa_empty_state_map_.empty())
        return dfa_empty_state_map_.at(stateIndex);
    if (empty_state != NULL_STATE)
        return empty_state;
    throw Error("Dfa has no empty state registered");
}
auto DFA::Base::getEmptyStateByDfaId(std::size_t dfaIndex) -> std::size_t {
    if (!dfa_index_to_empty_state_map_.empty())
        return dfa_index_to_empty_state_map_.at(dfaIndex);
    throw Error("Dfa is not merged, but the dfa_index_to_empty_state_map is called");
}
auto DFA::Base::isMerged() -> bool {
    return merged;
}