export module LangRepresentation.Construct;

import LangRepresentation.Holder;

import LexerBuilder;
import LLIR.API;
import LLIR.IR;

export namespace LangRepresentation {
    auto constructTypes() -> LLIR::Declarations;
    auto construct(LexerBuilder &&lexer_builder, LLIR::IR &&ir) -> Holder;
}