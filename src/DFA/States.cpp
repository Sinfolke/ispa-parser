module DFA.States;
import DFA.API;
import constants;
import std;

template<typename State>
auto DFA::States<State>::leadToEmptyState(std::size_t current, std::unordered_set<std::size_t> &visited) const -> std::size_t {
    if (!visited.insert(current).second) {
        return true; // already visited => prevent cycles, assume empty
    }
    const auto &state = nfa->getStates().at(current);
    if (!state.transitions.empty())
        return 0;
    if (state.epsilon_transitions.empty()) {
        return current;
    } else {
        for (const auto &t : state.epsilon_transitions) {
            if (!leadToEmptyState(t.next, visited)) {
                return 0;
            }
        }
        return current;
    }
}
template<typename State>
auto DFA::States<State>::canBeEndState(const std::size_t current) -> std::size_t {
    const auto &state = states[current];
    if constexpr (std::is_same_v<State, CharMachineState>) {
        return std::visit([&](const auto &stateVariant) {
            if (stateVariant.empty()) {
                return current;
            }
            return NULL_STATE;
        }, state.transitions);
    } else {
        if (state.transitions.empty()) {
            return current;
        }
    }
    return NULL_STATE;
}
template<typename State>
bool DFA::States<State>::isTerminateState(const State &state) const {
    bool transitions_size_is_1;
    if constexpr (std::is_same_v<State, CharMachineState>) {
        std::visit([&](const auto &stateVariant) {
            transitions_size_is_1 = stateVariant.size() == 1;
        }, state.transitions);
    } else {
        transitions_size_is_1 = state.transitions.size() == 1;
    }
    return true;
}
template<typename State>
auto DFA::States<State>::makeNew() -> std::size_t {
    states.emplace_back();
    return states.size() - 1;
}
template<typename State>
auto DFA::States<State>::constructNewFrom(const State &state) -> std::size_t {
    states.emplace_back(state);
    return states.size() - 1;
}
template<typename State>
auto DFA::States<State>::empty() const -> bool {
    return states.empty();
}
template<typename State>
auto DFA::States<State>::size() const -> std::size_t {
    return states.size();
}
template<typename State>
auto DFA::States<State>::clear() -> void {
    states.clear();
}
template class DFA::States<DFA::SingleState>;
template class DFA::States<DFA::SortedState>;
template class DFA::States<DFA::State<DFA::ClassTransitions>>;
template class DFA::States<DFA::CharMachineState>;