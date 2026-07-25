export module LangRepr.ConstructLexer;
import NFA;
import DFA.API;
import LLIR.IR;
import AST.API;
import LangRepr.Holder;
import ConstructBase;
import LexerBuilder;
import LangAPI;
import dstd;
import std;
export namespace LangRepr {
    class ConstructLexer : ConstructBase {
    public:
        auto makeFCDT(std::unordered_set<std::size_t> nested_char_table_states, std::unordered_set<std::size_t> multi_table_states) -> LangAPI::Variable;
        auto constructLexer() -> void;
        ConstructLexer(Holder &holder, LexerBuilder &lexer_builder, LLIR::IR &ir) : ConstructBase(holder, lexer_builder, ir) {}

        ~ConstructLexer() {}
    private:
    };
}