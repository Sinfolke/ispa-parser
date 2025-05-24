export module LLIRBuilder;
import LLIR;
import AST;
import TreeAPI;
import types;
import std;
import std.compat;
namespace LLIR {
    export class Builder {
        vector<LLIR::Data> data;
    public:
        Builder(AST &tree, int tokensOnly = -1);
        Builder(AST &tree, const TreeAPI::RuleMember& rule);
        Builder(AST &tree, const vector<TreeAPI::RuleMember>& rules);
        auto get() -> IR;
        auto getRawData() -> vector<Data>&;
        auto getRawData() const -> const vector<Data>&;
    };
}