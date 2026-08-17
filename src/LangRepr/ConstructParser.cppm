export module LangRepr.ConstructParser;
import NFA;
import DFA.API;
import LLIR.IR;
import AST.API;
import LangRepr.Holder;
import ConstructBase;
import LexerBuilder;
import LangAPI;
import logging;
import dstd;
import std;
export namespace LangRepr {
    class ConstructParser : ConstructBase {

    public:
        auto createParserClass(std::string main_node = "main") -> LangAPI::Class;
        auto finalizeReturnStatement(const LangAPI::Statement &stmt) -> LangAPI::Statement;

        auto constructTokenMachineDFA(LangAPI::Class &parser_class) -> void;

        auto constructParser() -> void;
        ConstructParser(Holder &holder, LexerBuilder &lexer_builder, LLIR::IR &ir) : ConstructBase(holder, lexer_builder, ir) {}

        ~ConstructParser() {}
    private:
    };
}