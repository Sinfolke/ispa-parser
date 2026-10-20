module LLIR.Builder;
import RuleLower;
import Parser.Base;
import corelib;
import std;
namespace LLIR {
// Compatibility bridge for the current Lower output. It supplies declarations,
// failure returns and data-block assignments expected by LangRepr; it does not
// implement additional grammar forms.
Builder::Builder(AST::Tree& tree, int) {
    Parser::Ctx ctx{};
    RuleLower lower(ctx, tree);
    for (const auto& [name, rule] : tree) {
        if (corelib::text::isUpper(name.back())) continue;
        for (const auto& member : rule.rule_members)
            if (!member->isName() || !member->getName().isTerminal() || (member->quantifier != '\0' && member->quantifier != '?'))
                throw std::invalid_argument("LL Lower currently supports only required and optional terminal sequences");
        lower.build(name, rule);
        Production production;
        production.name = name;
        production.block = dataBlock(rule.data_block);
        production.rule_members = lower.declarations().back().getFunction().statements;
        LangAPI::Statements statements;
        std::size_t capture = 0;
        for (std::size_t i = 0; i < rule.rule_members.size(); ++i) {
            const auto& member = *rule.rule_members[i];
            const std::string variable = "ll_token_" + std::to_string(i);
            LangAPI::Type node{LangAPI::ValueType::Token,
                LangAPI::Type{LangAPI::Symbol{member.getName().name}}};
            auto call = production.rule_members.at(i).getExpression().front()
                .getVariableAssignment().value.front().getIspaLibFunctionCall();
            call.symbol.exports = LangAPI::StdlibExports::ParserOptional;
            call.args = {LangAPI::Symbol::createExpression(LangAPI::Symbol{"pos"})};
            call.template_parameters = {std::make_shared<LangAPI::Type>(
                LangAPI::Symbol{"Types", member.getName().name})};
            LangAPI::Variable value;
            value.name = variable;
            value.type = node;
            value.value = LangAPI::IspaLibFunctionCall::createExpression(call);
            statements.push_back(value);
            LangAPI::StorageSymbol empty;
            empty.what = LangAPI::Symbol::createExpression(LangAPI::Symbol{variable});
            empty.path.push_back(LangAPI::FunctionCall{.name = std::make_shared<LangAPI::Symbol>("empty")});
            LangAPI::If failed{LangAPI::StorageSymbol::createExpression(empty)};
            failed.stmt.push_back(LangAPI::Return::createStatement(LangAPI::Return{}));
            if (member.quantifier != '?')
                statements.push_back(LangAPI::If::createStatement(failed));
            if (!member.prefix.empty()) {
                auto expression = LangAPI::Symbol::createExpression(LangAPI::Symbol{variable});
                if (production.block.is_regular_data_block())
                    production.block.getRegularDataBlock().first = expression;
                else if (production.block.is_inclosed_map())
                    production.block.getInclosedMap().at(rule.data_block.fields.at(capture).first).first = expression;
                ++capture;
            }
        }
        production.rule_members = std::move(statements);
        data.push_back(std::move(production));
    }
}
// Rebuild while the Lower representation is in transition; cached productions
// from the retired generator must not be mixed with these functions.
Builder::Builder(AST::Tree& tree, AST::TreeMap&, const std::unordered_map<std::string, Production>&)
    : Builder(tree) {}
auto Builder::get() -> IR { return IR{std::move(data), false, std::move(dfas)}; }
auto Builder::getRawData() -> stdu::vector<Production>& { return data; }
auto Builder::getRawData() const -> const stdu::vector<Production>& { return data; }
}
