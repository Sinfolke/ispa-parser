export module Converter.DFA;
import DFA;
import LexerBuilder;
import dstd;
import std;
import std.compat;
export class DFAConverter {
    const stdu::vector<DFA> &dfas;
    const LexerBuilder::isDfaInvolvedTable *is_dfa_involved;
    const std::string &namespace_name;
    const std::string &prefix;
    const std::string &name;
    std::ostringstream out;
    void createDFATable(const DFA& dfa, size_t count);
public:
    DFAConverter(const stdu::vector<DFA> &dfa, const LexerBuilder::isDfaInvolvedTable *is_dfa_involved, const std::string& namespace_name, const std::string &prefix, const std::string &name)
    : dfas(dfa), is_dfa_involved(is_dfa_involved), namespace_name(namespace_name), prefix(prefix), name(name) {}
    void create();
    auto get() -> std::ostringstream &;
};