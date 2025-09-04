export module Converter.DFA;
import LexerBuilder;
import DFA.Collection;
import DFA.MachineDFA;
import dstd;
import std;

export class DFAConverter {
    const DFA::Collection &dfas;
    const LexerBuilder::DfaCompatibleTable *dfa_compatible_table;
    const DFA::Collection::StateSet_t &state_set;
    const std::string &namespace_name;
    const std::string prefix;
    const std::string name;
    std::ostringstream out;
    bool isToken;
    void createDFATable(const DFA::MachineDFA& dfa, std::size_t count);
public:
    DFAConverter(
        const DFA::Collection &dfa,
        const LexerBuilder::DfaCompatibleTable *dfa_compatible_table,
        const DFA::Collection::StateSet_t &state_set,
        const std::string &namespace_name,
        const std::string &prefix,
        const std::string &name,
        bool isToken
        )
    : dfas(dfa), dfa_compatible_table(dfa_compatible_table), state_set(state_set), namespace_name(namespace_name), prefix(prefix), name(name), isToken(isToken) {}
    void create();
    auto get() -> std::ostringstream &;
};