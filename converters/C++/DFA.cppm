export module Converter.DFA;
import DFA;
import dstd;
import std;
import std.compat;
export class DFAConverter {
    const stdu::vector<DFA> &dfas;
    std::ostringstream out;
    void createDFATable(const DFA& dfa, size_t count);
public:
    DFAConverter(const stdu::vector<DFA> &dfa) : dfas(dfa) {}
    void create();
    auto get() -> std::ostringstream &;
};