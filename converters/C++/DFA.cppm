export module Converter.DFA;
import DFA;
import LexerBuilder;
import dstd;
import std;
import std.compat;
export class DFAConverter {
    const stdu::vector<DFA> &dfas;
    const LexerBuilder::DfaCompatibleTable *dfa_compatible_table;
    const std::string &namespace_name;
    const std::string &prefix;
    const std::string &name;
    std::ostringstream out;
    bool isToken;
    void createDFATable(const DFA& dfa, size_t count);
public:
    DFAConverter(
        const stdu::vector<DFA> &dfa,
        const LexerBuilder::DfaCompatibleTable *dfa_compatible_table,
        const std::string& namespace_name,
        const std::string &prefix,
        const std::string &name,
        bool isToken
        )
    : dfas(dfa), dfa_compatible_table(dfa_compatible_table), namespace_name(namespace_name), prefix(prefix), name(name), isToken(isToken) {}
    void create();
    auto get() -> std::ostringstream &;
};