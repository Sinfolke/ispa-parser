module ParserIR.IR;
import corelib;
import hash;
import logging;
import cpuf.printf;
import cpuf.op;
import std;

auto ParserIR::IR::begin() -> ::stdu::vector<Production>::iterator {
    return data.begin();
}
auto ParserIR::IR::end() -> stdu::vector<Production>::iterator {
    return data.end();
}
auto ParserIR::IR::cbegin() -> stdu::vector<Production>::const_iterator {
    return data.cbegin();
}
auto ParserIR::IR::cend() -> stdu::vector<Production>::const_iterator {
    return data.cend();
}
auto ParserIR::IR::size() -> std::size_t {
    return data.size();
}
auto ParserIR::IR::empty() -> bool {
    return data.empty();
}
auto ParserIR::IR::clear() -> void {
    data.clear();
}
auto ParserIR::IR::getDataBlocks() const -> DataBlockList {
    DataBlockList list;
    for (const auto &production : data) {
        list.emplace(production.name, production.block);
    }
    return list;
}
auto ParserIR::IR::getData() const -> const stdu::vector<Production> & {
    return data;
}
auto ParserIR::IR::getDfas() const -> const stdu::vector<DFA::DFA> & {
    return dfa_collection;
}

auto ParserIR::IR::operator[](std::size_t index) const -> const Production& {
    return data[index];
}