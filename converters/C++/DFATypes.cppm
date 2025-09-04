export module DFATypes;
import NFA;
import DFA.API;
import DFA.MachineDFA;
import hash;
import dstd;
import std;

export class DFATypes {
    const DFA::MachineDFA &dfa;
public:
    DFATypes(const DFA::MachineDFA &dfa) : dfa(dfa) {}
    static auto getTypeStr(DFA::DfaType type, const std::string &namespace_name, std::size_t count) -> std::string;
    static auto getSpanTypeStr(DFA::DfaType type, const std::string &namespace_name) -> std::string;
    static auto getTransitionsTypeStr(DFA::DfaType type, const std::string &namespace_name) -> std::string;
    auto getTypeStr(bool isToken, const utype::unordered_map<stdu::vector<std::string>, std::size_t> *dct, const std::string &namespace_name, std::size_t count) const -> std::string;
    auto getSpanTypeStr(bool isToken, const utype::unordered_map<stdu::vector<std::string>, std::size_t> *dct, const std::string &namespace_name) const -> std::string;
    auto getTransitionsTypeStr(bool isToken, const utype::unordered_map<stdu::vector<std::string>, std::size_t> *dct, const std::string &namespace_name) const -> std::string;
    static auto getTransitionKeyTypeStr(DFA::DfaType type, const std::string &namespace_name) -> std::string;
    static auto getTransitionKeyTypeStr(const NFA::TransitionKey &transition_key, bool isToken, const std::string &namespace_name) -> std::string;

    auto getStatesTypeStr(bool isToken, const utype::unordered_map<stdu::vector<std::string>, std::size_t> *dct, const std::string &namespace_name, std::size_t count) const -> std::string;
    static auto getStateTypeStr(DFA::DfaType table_type, DFA::DfaType type, const std::string &namespace_name, std::size_t size) -> std::string;
    template<typename Transitions>
    auto getStateTypeStr(const Transitions &transitions, const utype::unordered_map<stdu::vector<std::string>, std::size_t> *dct, bool isToken, const std::string &namespace_name, std::size_t size) -> std::string;

    static auto getSpanStateTypeStr(DFA::DfaType table_type, DFA::DfaType type, const std::string &namespace_name) -> std::string;
    template<typename Transitions>
    auto getSpanStateTypeStr(const Transitions &transitions, const utype::unordered_map<stdu::vector<std::string>, std::size_t> *dct, const std::string &namespace_name, bool isToken) -> std::string;

    static auto getEmptyTypeStr(DFA::DfaType type, const std::string &namespace_name) -> std::string;

    static auto getDataVectorType(const DFA::DfaType type, const std::string &namespace_name) -> std::string;
};