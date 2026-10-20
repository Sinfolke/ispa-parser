export module LangRepr.ConstructParser;
import NFA.TNFA.API;
import DFA.API;
import LLIR.IR;
import LRBase;
import AST.API;
import LangRepr.Holder;
import ConstructBase;
import LexerBuilder;
import AST.Tree;
import LangAPI;
import logging;
import dstd;
import std;
export namespace LangRepr {
    class ConstructParser : ConstructBase {

    public:
        auto createParserClass(std::string main_node = "main") -> LangAPI::Class;
        auto finalizeReturnStatement(const LangAPI::Statement &stmt) -> LangAPI::Statement;
        auto finalizeTypes(const LangAPI::Statement &stmt) -> LangAPI::Statement;

        auto constructTokenMachineDFA(LangAPI::Class &parser_class) -> void;

        auto constructParser() -> void;
        auto constructLRParser(LangAPI::Class &parser) -> void;
        ConstructParser(Holder &holder, LexerBuilder &lexer_builder, LLIR::IR &ir, AST::Tree &tree) : ConstructBase(holder, lexer_builder, ir, tree) {}
        ConstructParser(Holder &holder, LexerBuilder &lexer_builder, LLIR::IR &ir, LRBase &parser, AST::Tree &tree) : ConstructBase(holder, lexer_builder, ir, parser, tree) {}

        ~ConstructParser() {}
    private:
    };
}