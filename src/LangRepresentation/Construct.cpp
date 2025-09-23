module LangRepresentation.Construct;

import constants;
import std;

namespace LangRepresentation {
    auto constructTypes(Holder &holder, constants::Language lang) -> LangAPI::Declarations {
        holder.push(
            LangAPI::TypeAlias::createDeclaration(
                LangAPI::TypeAlias {
                    .name = "Rule",
                    .type = constants::stdlib_get_type(lang, constants::StdlibExports::Rule)
                }
            )
        );
        return {};
    }
    auto construct(LexerBuilder &&lexer_builder, LLIR::IR &&ir, constants::Language lang) -> Holder {
        return {};
    }
}