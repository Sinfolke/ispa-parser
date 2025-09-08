module DFA.Base;
import LexerBuilder;
import logging;
import hash;
import std;

template<typename StateType>
auto DFA::Base::getType(const States<StateType> &states, bool isToken, const utype::unordered_map<stdu::vector<std::string>, std::size_t> *dct) const -> DfaType {
    DfaType dfa_type = DfaType::NONE;
    if (states.empty())
        throw Error("Get type of empty states");
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
                if (dfa_type == DfaType::Token || dfa_type == DfaType::CallableToken || dfa_type == DfaType::NONE) {
                    if (isToken && dct && dct->at(sym) != LexerBuilder::DFA_NOT_COMPATIBLE) {
                        dfa_type = DfaType::Multi;
                        return dfa_type;
                    }
                    dfa_type = isToken ? DfaType::CallableToken : DfaType::Token;
                } else {
                    dfa_type = DfaType::Multi;
                    return dfa_type;
                }
            }
        }
    }
    return dfa_type;
}
auto DFA::Base::getTransitionKeyType(const NFA::TransitionKey &transition_key, bool isToken) -> DfaType {
    if (std::holds_alternative<char>(transition_key)) {
        return DfaType::Char;
    } else {
        return isToken ? DfaType::CallableToken : DfaType::Token;
    }
}
template<typename Transitions>
auto DFA::Base::getStateType(const Transitions &transitions, const utype::unordered_map<stdu::vector<std::string>, std::size_t> *dct, bool isToken) -> DfaType {
    DfaType dfa_type = DfaType::NONE;
    for (const auto &[symbol, next] : transitions) {
        if (std::holds_alternative<char>(symbol)) {
            if (dfa_type == DfaType::Char || dfa_type == DfaType::NONE) {
                dfa_type = DfaType::Char;
            } else {
                dfa_type = DfaType::Multi;
                break;
            }
        } else {
            auto &sym = std::get<stdu::vector<std::string>>(symbol);
            bool is_callable = isToken && dct && dct->at(sym) == LexerBuilder::DFA_NOT_COMPATIBLE;
            bool is_not_multi = (isToken && is_callable) || !isToken;
            if ((dfa_type == DfaType::Token || dfa_type == DfaType::CallableToken || dfa_type == DfaType::NONE) && is_not_multi) {
                dfa_type = isToken ? DfaType::CallableToken : DfaType::Token;
            } else if (dfa_type != DfaType::CallableToken || dfa_type != DfaType::Token) {
                dfa_type = DfaType::Multi;
                break;
            }
        }
    }
    return dfa_type;
}
auto DFA::Base::getEmptyState(std::size_t stateIndex) -> std::size_t {
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
template auto DFA::Base::getStateType(const Transitions &transitions, const utype::unordered_map<stdu::vector<std::string>, std::size_t> *dct, bool isToken) -> DfaType;
template auto DFA::Base::getStateType(const MultiTransitions &transitions, const utype::unordered_map<stdu::vector<std::string>, std::size_t> *dct, bool isToken) -> DfaType;
template auto DFA::Base::getStateType(const SortedTransitions &transitions, const utype::unordered_map<stdu::vector<std::string>, std::size_t> *dct, bool isToken) -> DfaType;
template auto DFA::Base::getType(const States<SingleState> &states, bool isToken, const utype::unordered_map<stdu::vector<std::string>, std::size_t> *dct) const -> DfaType;
template auto DFA::Base::getType(const States<MultiState> &states, bool isToken, const utype::unordered_map<stdu::vector<std::string>, std::size_t> *dct) const -> DfaType;
template auto DFA::Base::getType(const States<SortedState> &states, bool isToken, const utype::unordered_map<stdu::vector<std::string>, std::size_t> *dct) const -> DfaType;
