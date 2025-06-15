export module Converter.DFA;
import DFA;
import dstd;
import std;
import std.compat;
export class DFAConverter {
    const stdu::vector<DFA> &dfas;
    const std::string &namespace_name;
    std::ostringstream out;
    void createDFATable(const DFA& dfa, size_t count);
public:
    DFAConverter(const stdu::vector<DFA> &dfa, const std::string& namespace_name) : dfas(dfa), namespace_name(namespace_name) {}
    void create();
    auto get() -> std::ostringstream &;
};