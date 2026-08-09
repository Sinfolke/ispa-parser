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
        struct DfaSpan {
            std::size_t start;
            std::size_t length;
        };
        auto makeCharClassTableDecl(const DFA::CharClassTable &table)
            -> std::pair<std::shared_ptr<LangAPI::Declaration>, LangAPI::Visibility>;
        auto makeDfaTableDecl(
            const auto &states,
            std::size_t state_count,
            std::size_t class_count
        ) -> std::pair<std::shared_ptr<LangAPI::Declaration>, LangAPI::Visibility>;
        auto makeAcceptTableDecl(const auto &states, std::size_t state_count)
            -> std::pair<std::shared_ptr<LangAPI::Declaration>, LangAPI::Visibility>;
        auto makeConstructTableDecl(const auto &states)
            -> std::pair<std::shared_ptr<LangAPI::Declaration>, LangAPI::Visibility>;
        auto constructLexer() -> void;
        ConstructLexer(Holder &holder, LexerBuilder &lexer_builder, LLIR::IR &ir) : ConstructBase(holder, lexer_builder, ir) {}
    };
}