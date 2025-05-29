export module LLIR.Builder;
import LLIR;
import AST.Tree;
import AST.API;
import dstd;
import std;
import std.compat;
namespace LLIR {
    export class Builder {
        stdu::vector<LLIR::Data> data;
    public:
        Builder(AST::Tree &tree, int tokensOnly = -1);
        Builder(AST::Tree &tree, const AST::RuleMember& rule);
        Builder(AST::Tree &tree, const stdu::vector<AST::RuleMember>& rules);
        auto get() -> IR;
        auto getRawData() -> stdu::vector<Data>&;
        auto getRawData() const -> const stdu::vector<Data>&;
    };
}