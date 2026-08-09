module ConstructBase;
import LLIR.Builder.Base;
namespace LangRepr {
    auto ConstructBase::createTypeToken() -> LangAPI::TypeAlias {
        LangAPI::Type variant_type = LangAPI::ValueType::Variant;
        for (const auto &[name, dtb] : lexer_builder.getDataBlocks()) {
            LangAPI::Symbol tn = name;
            tn.path.insert(tn.path.begin(), "Types");
            variant_type.template_parameters.push_back(LangAPI::Type {tn});
        }
        Token = LangAPI::Symbol { "Token" };
        return LangAPI::TypeAlias {.name = "Token", .type = variant_type};
    }
    auto ConstructBase::createLexerClass() -> LangAPI::Class {
        LangAPI::IspaLibSymbol lexer_s {LangAPI::StdlibExports::Lexer};
        lexer_s.template_parameters.push_back(std::make_shared<LangAPI::Type>(LangAPI::Symbol {"Token"}));
        return LangAPI::Class {
            .name = "Lexer",
            .inherit_members = {std::make_pair(LangAPI::Visibility::Public, lexer_s)},
            .default_visibility = LangAPI::Visibility::Private
        };
    }
    auto ConstructBase::getTransitionCount(const std::variant<DFA::FullCharTable, DFA::SortedTransitions> &transitions) -> std::size_t {
        return std::holds_alternative<DFA::FullCharTable>(transitions) ?
            static_cast<int>(std::get<DFA::FullCharTable>(transitions).size())
            :
            static_cast<int>(std::get<DFA::SortedTransitions>(transitions).size());
    }

    auto ConstructBase::makeIntRValue(int v) -> std::shared_ptr<LangAPI::RValue> {
        return std::make_shared<LangAPI::RValue>(
            LangAPI::Int::createRValue(LangAPI::Int{.value = v})
        );
    };
    auto ConstructBase::ensureTypesNs(LangAPI::Type t) -> LangAPI::Type {
        if (t.isSymbol())
            if (std::get<std::string>(t.getSymbol().path.front()) != "Types") {
                t.getSymbol().path.insert(t.getSymbol().path.begin(), "Types");
            }
        if (!t.template_parameters.empty()) {
            for (auto &p : t.template_parameters) p = ensureTypesNs(std::get<LangAPI::Type>(p));
        }
        return t;
    };
    auto ConstructBase::extractRawSymbol(const LangAPI::Type &t) -> stdu::vector<LangAPI::Type> {
        if (t.isSymbol())
            return {t};
        if (!t.template_parameters.empty()) {
            std::vector<LangAPI::Type> types;
            for (auto &p : t.template_parameters) {
                auto r = extractRawSymbol(std::get<LangAPI::Type>(p));
                types.insert(types.end(), r.begin(), r.end());
            }
            return types;
        }
        return {t};
    };
}