export module LLIR.Builder;
import LLIR.API;
import LLIR.IR;
import AST.Tree;
import AST.API;
import DFA.Collection;
import DFA.TokenMachineDFA;
import dstd;
import std;

namespace LLIR {
    export class Builder {
        stdu::vector<LLIR::Production> data;
        DFA::Collection<DFA::TokenMachineDFA> dfas;
        bool isToken;
    public:
        Builder(AST::Tree &tree, int tokensOnly = -1);
        Builder(AST::Tree &tree, bool isToken, const AST::RuleMember& rule);
        Builder(AST::Tree &tree, bool isToken, const stdu::vector<AST::RuleMember>& rules);
        auto get() -> IR;
        auto getRawData() -> stdu::vector<Production>&;
        auto getRawData() const -> const stdu::vector<Production>&;
    };
}