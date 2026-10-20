export module LLIR.Builder;
import LangAPI;
import LLIR.API;
import LLIR.IR;
import AST.Tree;
import AST.API;
import AST.types;
import DFA;
import dstd;
import std;

namespace LLIR {
    export class Builder {
        stdu::vector<Production> data;
        stdu::vector<DFA::DFA> dfas;
    public:
        Builder(AST::Tree &tree, int tokensOnly = -1);
        Builder(
            AST::Tree &tree,
            AST::TreeMap &rules_to_build,
            const std::unordered_map<std::string, Production> &cache
        );
        auto get() -> IR;
        auto getRawData() -> stdu::vector<Production>&;
        auto getRawData() const -> const stdu::vector<Production>&;
    };
}