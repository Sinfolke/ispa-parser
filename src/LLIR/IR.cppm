export module LLIR.IR;
import hash;
import dstd;
import LangAPI;
import LLIR.API;
import DFA;
import std;

export namespace LLIR {
    class IR {
    protected:
        stdu::vector<Production> data;
        stdu::vector<DFA::DFA> dfa_collection;
    public:
        explicit IR(const stdu::vector<Production> &data, bool isToken, stdu::vector<DFA::DFA> &dfa_collection) : data(data), dfa_collection(dfa_collection) {}
        explicit IR(const stdu::vector<Production> &&data, bool isToken, stdu::vector<DFA::DFA> &&dfa_collection) : data(std::move(data)), dfa_collection(dfa_collection) {}
        IR() = default;
        auto getDataBlocks() const -> DataBlockList;
        auto getData() const -> const stdu::vector<Production>&;
        auto getDfas() const -> const stdu::vector<DFA::DFA>&;
        auto operator[](std::size_t pos) const -> const Production&;
        auto begin() -> stdu::vector<Production>::iterator;
        auto end() -> stdu::vector<Production>::iterator;
        auto cbegin() -> stdu::vector<Production>::const_iterator;
        auto cend() -> stdu::vector<Production>::const_iterator;
        auto size() -> std::size_t;
        auto empty() -> bool;
        auto clear() -> void;
    };
}