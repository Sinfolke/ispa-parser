module DFATypes;
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
auto DFATypes::getTypeStr(bool isToken, const std::string &namespace_name, std::size_t count) const -> std::string {
    return getTypeStr(dfa.getType(isToken), namespace_name, count);
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
auto DFATypes::getSpanTypeStr(bool isToken, const std::string &namespace_name) const -> std::string {
    return getSpanTypeStr(dfa.getType(isToken), namespace_name);
}

auto DFATypes::getTransitionsTypeStr(DFA::DfaType type, const std::string &namespace_name) -> std::string {
    switch (type) {
        case DFA::DfaType::Char:
            return "CharTableTransition<::" + namespace_name + "::Tokens>";
        case DFA::DfaType::Token:
            return "TokenTransition<::" + namespace_name + "::Tokens>";
        case DFA::DfaType::CallableToken:
            return "CallableTableTokenTransition<::" + namespace_name + "::Tokens>";
        case DFA::DfaType::Multi:
            return "MultiTableTransition<::" + namespace_name + "::Tokens>";
        default:
            throw Error("Undefined DFA type");;
    }
}
auto DFATypes::getTransitionsTypeStr(bool isToken, const std::string &namespace_name) const -> std::string {
    return getTransitionsTypeStr(dfa.getType(isToken), namespace_name);
}
auto DFATypes::getTransitionKeyTypeStr(DFA::DfaType type, const std::string &namespace_name) -> std::string {
    switch (type) {
        case DFA::DfaType::Char:
            return std::string("CharTableTransition") + namespace_name + "::Tokens>";
        case DFA::DfaType::Token:
            return std::string("TokenTransition<::") + namespace_name + "::Tokens>";
        case DFA::DfaType::CallableToken:
            return std::string("CallableTokenTableTransition<") + namespace_name + "::Tokens>";
        default:
            throw Error("Not allowed DFA transition type");
    }
}
auto DFATypes::getTransitionKeyTypeStr(const NFA::TransitionKey &transition_key, bool isToken, const std::string &namespace_name) -> std::string {
    return getTransitionKeyTypeStr(DFA::getTransitionKeyType(transition_key, isToken), namespace_name);
}
auto DFATypes::getStatesTypeStr(bool isToken, const std::string &namespace_name, std::size_t count) const -> std::string {
    return getTypeStr(isToken, namespace_name, count) + "State";
}
auto DFATypes::getStateTypeStr(DFA::DfaType table_type, DFA::DfaType type, const std::string &namespace_name, std::size_t size) -> std::string {
    switch (type) {
        case DFA::DfaType::Char:
            return std::string("CharTableState<::") + namespace_name + "::Tokens, " + std::to_string(size) + std::string(">");
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
auto DFATypes::getStateTypeStr(const DFA::Transitions &transitions, const utype::unordered_map<stdu::vector<std::string>, std::size_t> *dct, bool isToken, const std::string &namespace_name, std::size_t size) -> std::string {
    return getStateTypeStr(dfa.getType(isToken), DFA::getStateType(transitions, dct, isToken), namespace_name, size);
}
auto DFATypes::getSpanStateTypeStr(DFA::DfaType table_type, DFA::DfaType type, const std::string &namespace_name) -> std::string {
    switch (type) {
        case DFA::DfaType::Char:
            return "CharTableState<::" + namespace_name + "::Tokens>";
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
auto DFATypes::getSpanStateTypeStr(const DFA::Transitions &transitions, const utype::unordered_map<stdu::vector<std::string>, std::size_t> *dct, const std::string &namespace_name, bool isToken) -> std::string {
    return getSpanStateTypeStr(dfa.getType(isToken), DFA::getStateType(transitions, dct, isToken), namespace_name);
}
auto DFATypes::getEmptyTypeStr(DFA::DfaType type, const std::string &namespace_name) -> std::string {
    switch (type) {
        case DFA::DfaType::Char:
            return "CharEmptyState<::" + namespace_name + "::Tokens>";
        case DFA::DfaType::CallableToken:
            return "CallableTokenTableState<::" + namespace_name + "::Tokens>";
        case DFA::DfaType::Multi:
            return "MultiTableState<::" + namespace_name + "::Tokens>";
        default:
            return "";
    }
}
