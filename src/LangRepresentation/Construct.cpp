module LangRepresentation.Construct;

import LLIR.API;

import constants;
import corelib;
import std;

namespace LangRepresentation {
    auto Construct::constructTokensAndRulesEnum() -> void {
        LangAPI::Enum tokens_enum("Tokens");
        LangAPI::Enum rules_enum("Rules");
        for (const auto &dtb : lexer_builder.getDataBlocks()) {
            tokens_enum.value.push_back(corelib::text::join(dtb.first, "_"));
        }
        for (const auto &dtb : ir.getDataBlocks()) {
            rules_enum.value.push_back(corelib::text::join(dtb.first, "_"));
        }
        holder.push(tokens_enum);
        holder.push(rules_enum);
    }
    auto Construct::constructTokensAndRulesEnumToString() -> void {
        auto constructSwitchFromDataBlockList = [](const LLIR::DataBlockList &list, const char* name) {
            LangAPI::Switch ss;
            ss.expression = LangAPI::Symbol::createExpression(LangAPI::Symbol {name});
            for (const auto &[name, block] : list) {
                ss.cases.emplace_back();
                ss.cases.back().first = LangAPI::Symbol::createRValue(LangAPI::Symbol {corelib::text::join(name, "_")});
                ss.cases.back().second = LangAPI::Return::createStatements(LangAPI::Return {.value = LangAPI::String::createExpression(corelib::text::join(name, "_"))});
            }
            return ss;
        };
        LangAPI::Function tokens_fun {
            .name = "tokensToString",
            .parameters = { std::make_pair<LangAPI::Type>(LangAPI::Symbol {"Tokens"}, "token") },
            .statements = LangAPI::Switch::createStatements(constructSwitchFromDataBlockList(lexer_builder.getDataBlocks(), "tokens"))
        };
        LangAPI::Function rules_fun {
            .name = "rulesToString",
            .parameters = { std::make_pair<LangAPI::Type>(LangAPI::Symbol {"Rules"}, "rules") },
            .statements = LangAPI::Switch::createStatements(constructSwitchFromDataBlockList(ir.getDataBlocks(), "rules"))
        };
        holder.push(tokens_fun);
        holder.push(rules_fun);
    }

    auto Construct::construct() -> Holder& {
        constructTokensAndRulesEnum();
        return holder;
    }
    auto Construct::construct(LexerBuilder &&lexer_builder, LLIR::IR &&ir, LangAPI::Language lang) -> Holder {
        Construct construct(std::move(lexer_builder), std::move(ir), lang);
        return construct.construct();
    }
}