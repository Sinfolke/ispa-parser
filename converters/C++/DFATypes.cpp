module DFATypes;
import DFA.API;
import DFA.Base;
import logging;
import std;


auto DFATypes::getTypeStr(DFA::DfaType type, const std::string &namespace_name, std::size_t size) -> std::string {
    switch (type) {
        case DFA::DfaType::Char:
            return std::string("CharTable<::") + namespace_name + "::Tokens, " + std::to_string(size) + std::string(">");
        case DFA::DfaType::Token:
            return std::string("TokenTable<::") + namespace_name + "::Tokens, " + std::to_string(size) + std::string(">");
        case DFA::DfaType::CallableToken:
            return std::string("CallableTokenTable<::") + namespace_name + "::Tokens, " + std::to_string(size) + std::string(">");
        case DFA::DfaType::Multi:
            return std::string("MultiTable<::") + namespace_name + "::Tokens, " + std::to_string(size) + std::string(">");
        default:
            throw Error("Undefined DFA type");;
    }
}
auto DFATypes::getTypeStr(bool isToken, const utype::unordered_map<stdu::vector<std::string>, std::size_t> *dct, const std::string &namespace_name, std::size_t count) const -> std::string {
    return getTypeStr(dfa.getType(isToken, dct), namespace_name, count);
}

auto DFATypes::getSpanTypeStr(DFA::DfaType type, const std::string &namespace_name) -> std::string {
    switch (type) {
        case DFA::DfaType::Char:
            return "SpanCharTable<::"  + namespace_name + "::Tokens>";
        case DFA::DfaType::Token:
            return "SpanTokenTable<::" + namespace_name + "::Tokens>";
        case DFA::DfaType::CallableToken:
            return "SpanCallableTokenTable<::" + namespace_name + "::Tokens>";
        case DFA::DfaType::Multi:
            return "SpanMultiTable<::" + namespace_name + "::Tokens>";
        default:
            throw Error("Unknown DFA type for span");
    }
}
auto DFATypes::getSpanTypeStr(bool isToken, const utype::unordered_map<stdu::vector<std::string>, std::size_t> *dct, const std::string &namespace_name) const -> std::string {
    return getSpanTypeStr(dfa.getType(isToken, dct), namespace_name);
}

auto DFATypes::getTransitionsTypeStr(DFA::DfaType type, const std::string &namespace_name) -> std::string {
    switch (type) {
        case DFA::DfaType::Char:
            return "CharTableTransition<::" + namespace_name + "::Tokens>";
        case DFA::DfaType::Token:
            return "TokenTransition<::" + namespace_name + "::Tokens>";
        case DFA::DfaType::CallableToken:
            return "CallableTokenTableTransition<::" + namespace_name + "::Tokens>";
        case DFA::DfaType::Multi:
            return "MultiTableTransition<::" + namespace_name + "::Tokens>";
        default:
            throw Error("Undefined DFA type");;
    }
}
auto DFATypes::getTransitionsTypeStr(bool isToken, const utype::unordered_map<stdu::vector<std::string>, std::size_t> *dct, const std::string &namespace_name) const -> std::string {
    return getTransitionsTypeStr(dfa.getType(isToken, dct), namespace_name);
}
auto DFATypes::getTransitionKeyTypeStr(DFA::DfaType type, const std::string &namespace_name) -> std::string {
    switch (type) {
        case DFA::DfaType::Char:
            return std::string("CharTableTransition") + namespace_name + "::Tokens>";
        case DFA::DfaType::Token:
            return std::string("TokenTransition<::") + namespace_name + "::Tokens>";
        case DFA::DfaType::CallableToken:
            return std::string("CallableTokenTableTransition<::") + namespace_name + "::Tokens>";
        default:
            throw Error("Not allowed DFA transition type");
    }
}
auto DFATypes::getTransitionKeyTypeStr(const NFA::TransitionKey &transition_key, bool isToken, const std::string &namespace_name) -> std::string {
    return getTransitionKeyTypeStr(DFA::Base::getTransitionKeyType(transition_key, isToken), namespace_name);
}
auto DFATypes::getStatesTypeStr(bool isToken, const utype::unordered_map<stdu::vector<std::string>, std::size_t> *dct, const std::string &namespace_name, std::size_t count) const -> std::string {
    return getTypeStr(isToken, dct, namespace_name, count) + "State";
}
auto DFATypes::getStateTypeStr(DFA::DfaType table_type, DFA::DfaType type, const std::string &namespace_name, std::size_t size) -> std::string {
    switch (type) {
        case DFA::DfaType::Char:
            return std::string("CharTableState<") + std::to_string(size) + std::string(">");
        case DFA::DfaType::Token:
            return std::string("TokenTableState<::") + namespace_name + "::Tokens, " + std::to_string(size) + std::string(">");
        case DFA::DfaType::CallableToken:
            return std::string("CallableTokenTableState<::") + namespace_name + "::Tokens, " + std::to_string(size) + std::string(">");
        case DFA::DfaType::Multi:
            return std::string("MultiTableState<::") + namespace_name + "::Tokens, " + std::to_string(size) + std::string(">");
        case DFA::DfaType::NONE:
            return getEmptyTypeStr(table_type, namespace_name);
        default:
            throw Error("Undefined DFA type");
    }
}
template<typename Transitions>
auto DFATypes::getStateTypeStr(const Transitions &transitions, const utype::unordered_map<stdu::vector<std::string>, std::size_t> *dct, bool isToken, const std::string &namespace_name, std::size_t size) -> std::string {
    return getStateTypeStr(dfa.getType(isToken, dct), DFA::Base::getStateType(transitions, dct, isToken), namespace_name, size);
}
auto DFATypes::getSpanStateTypeStr(DFA::DfaType table_type, DFA::DfaType type, const std::string &namespace_name) -> std::string {
    switch (type) {
        case DFA::DfaType::Char:
            return "CharTableState";
        case DFA::DfaType::Token:
            return "TokenTableState<::" + namespace_name + "::Tokens>";
        case DFA::DfaType::CallableToken:
            return "CallableTokenTableState<::" + namespace_name + "::Tokens>";
        case DFA::DfaType::Multi:
            return "MultiTableState<::" + namespace_name + "::Tokens>";
        case DFA::DfaType::NONE:
            return getEmptyTypeStr(table_type, namespace_name);
        default:
            throw Error("Undefined DFA type");;
    }
}
template<typename Transitions>
auto DFATypes::getSpanStateTypeStr(const Transitions &transitions, const utype::unordered_map<stdu::vector<std::string>, std::size_t> *dct, const std::string &namespace_name, bool isToken) -> std::string {
    return getSpanStateTypeStr(dfa.getType(isToken, dct), DFA::Base::getStateType(transitions, dct, isToken), namespace_name);
}
auto DFATypes::getEmptyTypeStr(DFA::DfaType type, const std::string &namespace_name) -> std::string {
    switch (type) {
        case DFA::DfaType::Char:
            return "CharEmptyState<::" + namespace_name + "::Tokens>";
        case DFA::DfaType::CallableToken:
            return "CallableTokenEmptyState<::" + namespace_name + "::Tokens>";
        case DFA::DfaType::Token:
            return "SpanTokenTableState<::" + namespace_name + "::Tokens>";
        case DFA::DfaType::Multi:
            return "MultiTableEmptyState<::" + namespace_name + "::Tokens>";
        default:
            throw Error("Undefined type to get empty type str");
    }
}

auto DFATypes::getDataVectorType(const DFA::DfaType type, const std::string &namespace_name) -> std::string {
    switch (type) {
        case DFA::DfaType::Char:
            return "CharTableDataVector";
        case DFA::DfaType::CallableToken:
            return std::string("CallableTokenDataVector<::") + namespace_name + "::Tokens>";
        case DFA::DfaType::Multi:
            return std::string("MultiTableDataVector<::") + namespace_name + "::Tokens>";
        default:
            throw Error("Undefined Data vector type");
    }
}

template auto DFATypes::getStateTypeStr(const DFA::Transitions &transitions, const utype::unordered_map<stdu::vector<std::string>, std::size_t> *dct, bool isToken, const std::string &namespace_name, std::size_t size) -> std::string;
template auto DFATypes::getStateTypeStr(const DFA::MultiTransitions &transitions, const utype::unordered_map<stdu::vector<std::string>, std::size_t> *dct, bool isToken, const std::string &namespace_name, std::size_t size) -> std::string;
template auto DFATypes::getStateTypeStr(const DFA::SortedTransitions &transitions, const utype::unordered_map<stdu::vector<std::string>, std::size_t> *dct, bool isToken, const std::string &namespace_name, std::size_t size) -> std::string;

template auto DFATypes::getSpanStateTypeStr(const DFA::Transitions &transitions, const utype::unordered_map<stdu::vector<std::string>, std::size_t> *dct, const std::string &namespace_name, bool isToken) -> std::string;
template auto DFATypes::getSpanStateTypeStr(const DFA::MultiTransitions &transitions, const utype::unordered_map<stdu::vector<std::string>, std::size_t> *dct, const std::string &namespace_name, bool isToken) -> std::string;
template auto DFATypes::getSpanStateTypeStr(const DFA::SortedTransitions &transitions, const utype::unordered_map<stdu::vector<std::string>, std::size_t> *dct, const std::string &namespace_name, bool isToken) -> std::string;