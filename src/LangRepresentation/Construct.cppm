export module LangRepresentation.Construct;

import LangRepresentation.Holder;

import LexerBuilder;
import LangAPI;
import LLIR.IR;

export namespace LangRepresentation {
    auto constructTypes() -> LangAPI::Declarations;
    auto construct(LexerBuilder &&lexer_builder, LLIR::IR &&ir) -> Holder;
}