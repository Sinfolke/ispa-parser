export module LLIRBuilder;
import LLIR;
import AST;
import std;
import std.compat;
namespace LLIR {
    export class Builder {
        std::vector<LLIR::Data> data;
    public:
        Builder(AST &tree, int tokensOnly = -1);
        auto get() -> IR;
        auto getRawData() -> std::vector<Data>&;
        auto getRawData() const -> const std::vector<Data>&;
    };
}