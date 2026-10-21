module LLIR.Builder;
import RuleLower;
import Parser.Base;
import corelib;
import std;
namespace LLIR {
using namespace ParserIR;
Builder::Builder(AST::Tree& tree, int) : Builder(tree, AST::TreeMap{}, {}) {}

Builder::Builder(AST::Tree& tree, const AST::TreeMap& changed,
                 const std::unordered_map<std::string, Production>& cache) {
    Parser::Ctx ctx{};
    RuleLower lower(ctx, tree);
    for (const auto& [name, rule] : tree) {
        if (corelib::text::isUpper(name.back())) continue;
        const auto cached = cache.find(corelib::text::join(name, "."));
        if (!changed.contains(name) && cached != cache.end()) {
            data.push_back(cached->second);
            continue;
        }
        lower.build(name, rule);
        Production production;
        production.name = name;
        production.block = dataBlock(rule.data_block);
        const auto& lowered = lower.lowered_functions_meta().at(name);
        // The body is opaque to the Builder: all value bindings come from the
        // semantic exports, regardless of declaration placement or control flow.
        production.rule_members = lowered.function.statements;
        std::size_t capture = 0;
        for (const auto& exported : lowered.captures) {
            if (exported.prefix.empty()) continue;
            const auto& value = exported.meta.value.name.empty()
                ? exported.meta.value_list : exported.meta.value;
            auto expression = LangAPI::Symbol::createExpression(LangAPI::Symbol{value.name});
            if (production.block.is_regular_data_block())
                production.block.getRegularDataBlock().first = std::move(expression);
            else if (production.block.is_inclosed_map()) {
                const auto& field = rule.data_block.fields.at(capture).first;
                production.block.getInclosedMap().at(field).first = std::move(expression);
            }
            ++capture;
        }
        data.push_back(std::move(production));
    }
}
auto Builder::get() -> IR { return IR{std::move(data), false, std::move(dfas)}; }
auto Builder::getRawData() -> stdu::vector<Production>& { return data; }
auto Builder::getRawData() const -> const stdu::vector<Production>& { return data; }
}
