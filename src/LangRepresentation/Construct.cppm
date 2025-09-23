export module LangRepresentation.Construct;

import LangRepresentation.Holder;

import LexerBuilder;
import LangAPI;
import LLIR.IR;

export namespace LangRepresentation {
    class Construct {
        Holder holder;
        LexerBuilder lexer_builder;
        LLIR::IR ir;
        LangAPI::Language lang;
        auto constructTokensAndRulesEnum() -> void;
        auto constructTokensAndRulesEnumToString() -> void;
    public:
        Construct(LexerBuilder &&lexer_builder, LLIR::IR &&ir, LangAPI::Language lang) : lexer_builder(std::move(lexer_builder)), ir(std::move(ir)), lang(lang) {}

        auto construct() -> Holder&;
        static auto construct(LexerBuilder &&lexer_builder, LLIR::IR &&ir, LangAPI::Language lang) -> Holder;
    };

}