export module LLIR.IR;
import hash;
import dstd;
import LLIR.API;
import DFA.Collection;
import DFA.TokenMachineDFA;
import std;

export namespace LLIR {
    class IR {
        auto getDataBlocks(bool isToken) const -> DataBlockList;
    protected:
        stdu::vector<Production> data;
        DFA::Collection<DFA::TokenMachineDFA> dfa_collection;
        // output functions
        std::stack<std::string> current_pos_counter;
        std::size_t indentLevel = 0;
    public:
        explicit IR(const stdu::vector<Production> &data, bool isToken, DFA::Collection<DFA::TokenMachineDFA> &dfa_collection) : data(data), dfa_collection(dfa_collection) {}
        explicit IR(const stdu::vector<Production> &&data, bool isToken, DFA::Collection<DFA::TokenMachineDFA> &&dfa_collection) : data(std::move(data)), dfa_collection(dfa_collection) {}
        IR() = default;
        auto getData() const -> const stdu::vector<Production>&;
        auto getDfas() const -> const DFA::Collection<DFA::TokenMachineDFA>&;
        auto operator[](std::size_t pos) const -> const Production&;
        auto begin() -> stdu::vector<Production>::iterator;
        auto end() -> stdu::vector<Production>::iterator;
        auto cbegin() -> stdu::vector<Production>::const_iterator;
        auto cend() -> stdu::vector<Production>::const_iterator;
        auto size() -> std::size_t;
        auto empty() -> bool;
        auto clear() -> void;
        auto getDataBlocksTerminals() const -> DataBlockList;
        auto getDataBlocksNonTerminals() const -> DataBlockList;

        // print function
        void outputIRToFile(std::string filename);
        void outputIRToConsole();
    };
}