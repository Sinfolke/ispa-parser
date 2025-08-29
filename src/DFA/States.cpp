module DFA.States;
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
            if (!leadToEmptyState(t, visited)) {
                return 0;
            }
        }
        return current;
    }
}
template<typename State>
auto DFA::States<State>::leadToEmptyState(std::size_t current) const -> std::size_t {
    std::unordered_set<std::size_t> visited;
    return leadToEmptyState(current, visited);
}

template<typename State>
auto DFA::States<State>::leadToEmptyStateDfa(const std::size_t current, std::unordered_set<std::size_t> &visited) -> std::size_t {
    if (states[current].transitions.empty())
        return current;
    for (const auto &t : states[current].transitions) {
        if constexpr (std::is_same_v<State, MultiState>) {
            for (const auto &n : t.second) {
                if (!visited.insert(n.value.next).second)
                    continue;
                if (auto lead_check = leadToEmptyStateDfa(n.value.next, visited); lead_check != 0) {
                    return lead_check;
                }
            }
        } else {
            if (!visited.insert(t.second.next).second)
                continue;
            if (auto lead_check = leadToEmptyStateDfa(t.second.next, visited); lead_check != 0) {
                return lead_check;
            }
        }
    }
    return 0;
}
template<typename State>
auto DFA::States<State>::leadToEmptyStateDfa(const std::size_t current) -> std::size_t {
    std::unordered_set<std::size_t> visited;
    return leadToEmptyStateDfa(current, visited);
}
template<typename State>
auto DFA::States<State>::canBeEndState(const std::size_t current) -> std::size_t {
    const auto &state = states[current];
    if (state.transitions.empty()) {
        return current;
    }
    if (state.else_goto) {
        return canBeEndState(state.else_goto);
    }
    return NFA::NULL_STATE;
}

template<typename State>
bool DFA::States<State>::includesWhitespace(const State &state) const {
    for (const auto &t : state.transitions) {
        if (t.first == NFA::TransitionKey {constants::whitespace})
            return true;
    }
    return false;
}
template<typename State>
bool DFA::States<State>::isTerminateState(const State &state) const {
    if (state.else_goto || nfa && nfa->isCharNfa() || state.transitions.size() != 1)
        return false;
    if constexpr (std::is_same_v<State, MultiState>) {
        for (const auto &t : state.transitions) {
            if (t.second.size() > 1)
                return false;
        }
    }
    return true;
}
template<typename State>
auto DFA::States<State>::makeNew() -> std::size_t {
    states.emplace_back();
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
template class DFA::States<DFA::MultiState>;
template class DFA::States<DFA::SortedState>;