export module LLIRBuilder;
import LLIR;
import AST;
import TreeAPI;
import std;
import std.compat;
namespace LLIR {
    export class Builder {
        std::vector<LLIR::Data> data;
    public:
        Builder(AST &tree, int tokensOnly = -1);
        Builder(AST &tree, const TreeAPI::RuleMember& rule);
        Builder(AST &tree, const std::vector<TreeAPI::RuleMember>& rules);
        auto get() -> IR;
        auto getRawData() -> std::vector<Data>&;
        auto getRawData() const -> const std::vector<Data>&;
    };
}