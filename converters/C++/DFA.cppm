export module Converter.DFA;
import DFA;
import LexerBuilder;
import DFAS;
import dstd;
import std;

export class DFAConverter {
    const DFAS &dfas;
    const LexerBuilder::DfaCompatibleTable *dfa_compatible_table;
    const DFAS::StateSet_t &state_set;
    const std::string &namespace_name;
    const std::string &prefix;
    const std::string &name;
    std::ostringstream out;
    bool isToken;
    void createDFATable(const DFA& dfa, std::size_t count);
public:
    DFAConverter(
        const DFAS &dfa,
        const LexerBuilder::DfaCompatibleTable *dfa_compatible_table,
        const DFAS::StateSet_t &state_set,
        const std::string &namespace_name,
        const std::string &prefix,
        const std::string &name,
        bool isToken
        )
    : dfas(dfa), dfa_compatible_table(dfa_compatible_table), state_set(state_set), namespace_name(namespace_name), prefix(prefix), name(name), isToken(isToken) {}
    void create();
    auto get() -> std::ostringstream &;
};