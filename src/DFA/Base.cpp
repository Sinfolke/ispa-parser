module DFA.Base;
import LexerBuilder;
import logging;
import hash;
import std;

template<typename StateType>
auto DFA::Base::getType(const States<StateType> &states) const -> DfaType {
    DfaType dfa_type = DfaType::NONE;
    if (states.empty())
        throw Error("Get type of empty states");
    if constexpr (std::is_same_v<StateType, CharMachineState>) {
        for (const auto &state : states) {
            if (std::holds_alternative<FullCharTable>(state.transitions)) {
                if (dfa_type == DfaType::Char || dfa_type == DfaType::NONE) {
                    dfa_type = DfaType::Char;
                } else {
                    dfa_type = DfaType::Multi;
                    return dfa_type;
                }
            } else {
                if (std::get<SortedTransitions>(state.transitions).empty())
                    continue;
                if (dfa_type == DfaType::Token || dfa_type == DfaType::NONE) {
                    dfa_type = DfaType::Token;
                } else {
                    dfa_type = DfaType::Multi;
                    return dfa_type;
                }
            }
        }
    } else {
        for (const auto &state : states) {
            for (const auto &[symbol, next] : state.transitions) {
                if (std::holds_alternative<char>(symbol)) {
                    if (dfa_type == DfaType::Char || dfa_type == DfaType::NONE) {
                        dfa_type = DfaType::Char;
                    } else {
                        dfa_type = DfaType::Multi;
                        return dfa_type;
                    }
                } else {
                    const auto &sym = std::get<stdu::vector<std::string>>(symbol);
                    dfa_type = DfaType::Multi;
                    return dfa_type;
                }
            }
        }
    }

    return dfa_type;
}
auto DFA::Base::getTransitionKeyType(const NFA::TransitionKey &transition_key) -> DfaType {
    if (std::holds_alternative<char>(transition_key)) {
        return DfaType::Char;
    } else {
        return DfaType::Token;
    }
}
template<typename Transitions>
auto DFA::Base::getStateType(const Transitions &transitions) -> DfaType {
    if constexpr (std::is_same_v<Transitions, SortedTransitions>) {
        for (const auto &[symbol, next] : transitions) {
            if (!std::holds_alternative<char>(symbol)) {
                return DfaType::Multi;
            }
        }
    } else if constexpr (std::is_same_v<Transitions, CharMachineStateVariant>) {
        return std::holds_alternative<FullCharTable>(transitions) ? DfaType::Char : DfaType::Multi;
    }
    return DfaType::Char;
}

auto DFA::Base::getEmptyState(std::size_t stateIndex) const -> std::size_t {
    if (!dfa_empty_state_map_.empty())
        return dfa_empty_state_map_.at(stateIndex);
    if (empty_state != NULL_STATE)
        return empty_state;
    throw Error("Dfa has no empty state registered");
}
auto DFA::Base::getEmptyState() -> std::size_t& {
    if (empty_state == NULL_STATE)
        throw Error("Dfa has no empty state registered");
    return empty_state;
}
auto DFA::Base::getEmptyStateByDfaId(std::size_t dfaIndex) -> std::size_t {
    if (!dfa_index_to_empty_state_map_.empty())
        return dfa_index_to_empty_state_map_.at(dfaIndex);
    throw Error("Dfa is not merged, but the dfa_index_to_empty_state_map is called");
}
auto DFA::Base::isMerged() -> bool {
    return merged;
}
template auto DFA::Base::getStateType(const Transitions &transitions) -> DfaType;
template auto DFA::Base::getStateType(const MultiTransitions &transitions) -> DfaType;
template auto DFA::Base::getStateType(const SortedTransitions &transitions) -> DfaType;
template auto DFA::Base::getStateType(const CharMachineStateVariant &transitions) -> DfaType;
template auto DFA::Base::getType(const States<SingleState> &states) const -> DfaType;
template auto DFA::Base::getType(const States<MultiState> &states) const -> DfaType;
template auto DFA::Base::getType(const States<SortedState> &states) const -> DfaType;
template auto DFA::Base::getType(const States<CharMachineState> &states) const -> DfaType;