module LLIR.IR;
import corelib;
import hash;
import logging;
import cpuf.printf;
import std;

auto LLIR::IR::begin() -> ::stdu::vector<Production>::iterator {
    return data.begin();
}
auto LLIR::IR::end() -> stdu::vector<Production>::iterator {
    return data.end();
}
auto LLIR::IR::cbegin() -> stdu::vector<Production>::const_iterator {
    return data.cbegin();
}
auto LLIR::IR::cend() -> stdu::vector<Production>::const_iterator {
    return data.cend();
}
auto LLIR::IR::size() -> std::size_t {
    return data.size();
}
auto LLIR::IR::empty() -> bool {
    return data.empty();
}
auto LLIR::IR::clear() -> void {
    data.clear();
}
LLIR::DataBlockList LLIR::IR::getDataBlocks(bool isToken) const {
    LLIR::DataBlockList list;
    for (const auto &[data_block, name, members] : data) {
        if (isToken) {
            if (corelib::text::isLower(name.back())) continue;
        } else {
            if (corelib::text::isUpper(name.back())) continue;
        }
        list[name] = data_block;
    }
    return list;
}
LLIR::DataBlockList LLIR::IR::getDataBlocksTerminals() const {
    return getDataBlocks(true);
}
LLIR::DataBlockList LLIR::IR::getDataBlocksNonTerminals() const {
    return getDataBlocks(false);
}
auto LLIR::IR::getData() const -> const stdu::vector<Production> & {
    return data;
}
auto LLIR::IR::getDfas() const -> const DFA::Collection<DFA::TokenMachineDFA> & {
    return dfa_collection;
}

auto LLIR::IR::operator[](std::size_t index) const -> const Production& {
    return data[index];
}