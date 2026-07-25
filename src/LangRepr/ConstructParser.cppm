export module LangRepr.ConstructParser;
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
    class ConstructParser : ConstructBase {
        auto ensureTypesNs(LangAPI::Symbol s) -> LangAPI::Symbol;
        auto ensureTypesNs(LangAPI::StorageSymbol s) -> LangAPI::StorageSymbol;
        auto ensureTypesNs(LangAPI::Inheritance s) -> LangAPI::Inheritance;
        auto ensureTypesNs(LangAPI::RValue r) -> LangAPI::RValue;
        auto ensureTypesNs(LangAPI::FunctionCall s) -> LangAPI::FunctionCall;
        auto ensureTypesNs(LangAPI::Lambda l) -> LangAPI::Lambda;
        auto ensureTypesNs(LangAPI::ExpressionValue ev) -> LangAPI::ExpressionValue;
        auto ensureTypesNs(LangAPI::Expression expr) -> LangAPI::Expression;
        auto ensureTypesNs(LangAPI::Variable v) -> LangAPI::Variable;
        auto ensureTypesNs(LangAPI::If s) -> LangAPI::If;
        auto ensureTypesNs(LangAPI::While s) -> LangAPI::While;
        auto ensureTypesNs(LangAPI::DoWhile s) -> LangAPI::DoWhile;
        auto ensureTypesNs(LangAPI::Switch s) -> LangAPI::Switch;
        auto ensureTypesNs(const LangAPI::Statement &s) -> LangAPI::Statement;
        auto ensureTypesNs(LangAPI::Statements stmts) -> LangAPI::Statements;

    public:
        auto ensureTypesNs(LangAPI::Type t) -> LangAPI::Type;

        auto createParserClass(std::string main_node = "main") -> LangAPI::Class;

        auto constructTokenMachineDFA(LangAPI::Class &parser_class) -> void;

        auto constructParser() -> void;
        ConstructParser(Holder &holder, LexerBuilder &lexer_builder, LLIR::IR &ir) : ConstructBase(holder, lexer_builder, ir) {}

        ~ConstructParser() {}
    private:
    };
}