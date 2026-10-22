module;
#include <tsl/ordered_map.h>
module LangRepr.ConstructParser;
import ParserIR.API;
import corelib;
import constants;
import std;

namespace LangRepr {
auto ConstructParser::constructLRParser(LangAPI::Class &parser) -> void {
    using namespace LangAPI;
    auto integer = [](long long value) { return Int::createExpression(Int{.value = value}); };
    auto symbol = [](std::string name) { return Symbol::createExpression(Symbol{std::move(name)}); };
    auto memberCall = [&](std::string object, std::string name, stdu::vector<Expression> args = {}) {
        StorageSymbol s;
        s.what = symbol(std::move(object));
        s.path.emplace_back(FunctionCall{.name = std::make_shared<Symbol>(std::move(name)), .args = std::move(args)});
        return StorageSymbol::createExpression(s);
    };
    auto tokenId = [](const LRBase::Name &name) {
        Symbol id{"Tokens", name};
        id.path.emplace_back("id");
        return Symbol::createExpression(id);
    };
    auto returned = [](Expression value) { return Return::createStatement(Return{.value = std::move(value)}); };
    auto fail = [] {
        return Throw::createStatement(Throw{.throw_value = FunctionCall::createExpression(FunctionCall{
            .name = std::make_shared<Symbol>(Symbol{"std", "runtime_error"}),
            .args = {String::createExpression(String{.value = "Invalid LR table entry or unexpected token"})}})});
    };
    auto equals = [](Expression left, Expression right) {
        left.push_back(ExpressionElement::Equal);
        left.insert(left.end(), right.begin(), right.end());
        return left;
    };
    auto conjunction = [](Expression left, Expression right) {
        left.push_back(ExpressionElement::And);
        left.insert(left.end(), right.begin(), right.end());
        return left;
    };
    auto add = [&](std::string name, Type type, stdu::vector<std::pair<Type, std::string>> parameters, Statements statements) {
        parser.data.emplace_back(std::make_shared<Declaration>(Function::createDeclaration(Function{
            .type = std::move(type), .name = std::move(name), .parameters = std::move(parameters),
            .statements = std::move(statements), .is_static = true})), Visibility::Public);
    };
    const Type size{ValueType::LargeUInt};
    const Type number{ValueType::Int};
    const Type any{Symbol{"std", "any"}};
    const Type sizes{ValueType::Array, size};
    const Type values{ValueType::Array, any};
    auto &base = std::get<IspaLibSymbol>(parser.inherit_members.front().second);
    const bool dynamic = lr->automaticConflictResolution() && lr->needsRuntimeConflictResolution();
    base.exports = dynamic ? StdlibExports::LRGeneralizedParser : StdlibExports::LRParser;
    add("lr_k", size, {}, {returned(integer(lr->getDecisionLookaheadK()))});

    Expression is_space = Bool::createExpression(Bool{.value = false});
    if (lr->skipsAutomaticWhitespace())
        is_space = equals(memberCall("token", "kind"), tokenId(constants::whitespace));
    add("lr_is_space", Type{ValueType::Bool},
        {{Type{ValueType::Const, Type{ValueType::Reference, Type{Symbol{"Token"}}}}, "token"}},
        {returned(std::move(is_space))});
    Statements spaces;
    for (std::size_t i = 1; i < lr->getProductions().size(); ++i) {
        const auto& gaps = lr->getProductions()[i].whitespace_gaps;
        for (std::size_t j = 0; j < gaps.size(); ++j) if (gaps[j]) {
            auto condition = conjunction(equals(symbol("rule"), integer(i - 1)), equals(symbol("gap"), integer(j)));
            spaces.push_back(If::createStatement(If{std::move(condition), {returned(Bool::createExpression(Bool{.value = true}))}}));
        }
    }
    spaces.push_back(returned(Bool::createExpression(Bool{.value = false})));
    add("lr_space", Type{ValueType::Bool}, {{size, "rule"}, {size, "gap"}}, std::move(spaces));

    // Static continuation windows are emitted only for proven disjoint cells.
    // The generalized runtime and conflict callbacks are absent if none remain.
    auto conditionFor = [&](std::size_t state, const LRBase::Lookahead& window) {
        auto condition = equals(symbol("state"), integer(state));
        for (std::size_t i = 0; i < window.size(); ++i) {
            auto token = window[i] == LRBase::Name{"$"}
                ? Cast::createExpression(Cast{.type = std::make_shared<Type>(size), .what = integer(-1)}) : tokenId(window[i]);
            condition = conjunction(std::move(condition), equals(memberCall("window", "at", {integer(i)}), std::move(token)));
        }
        return condition;
    };
    auto encode = [](const LRBase::Action& action) -> long long {
        switch (action.type) {
            case LRBase::Action_type::SHIFT: return static_cast<long long>(action.state) + 1;
            case LRBase::Action_type::REDUCE: return -static_cast<long long>(action.state) - 1;
            case LRBase::Action_type::ACCEPT: return 0;
            default: throw std::invalid_argument("Unsupported LR action in LangRepr");
        }
    };
    Statements actions, conflicts;
    for (const auto& [state, row] : lr->getKActionTable()) for (const auto& [window, action] : row)
        actions.push_back(If::createStatement(If{conditionFor(state, window), {returned(integer(encode(action)))}}));
    for (const auto& resolution : lr->getConflictResolutions()) {
        if (resolution.lookahead) {
            for (const auto& decision : resolution.decisions)
                actions.push_back(If::createStatement(If{conditionFor(decision.state, decision.window), {returned(integer(encode(decision.action)))}}));
        } else {
            const auto& conflict = lr->getConflicts().at(resolution.conflict);
            actions.push_back(If::createStatement(If{conditionFor(conflict.state, conflict.lookahead_sequence),
                {returned(integer(std::numeric_limits<long long>::max()))}}));
            Array choices;
            for (const auto& action : conflict.actions) choices.values.push_back(integer(encode(action)));
            conflicts.push_back(If::createStatement(If{conditionFor(conflict.state, conflict.lookahead_sequence),
                {returned(Array::createExpression(std::move(choices)))}}));
        }
    }
    if (dynamic) actions.push_back(returned(integer(-std::numeric_limits<long long>::max())));
    else actions.push_back(fail());
    const stdu::vector<std::pair<Type, std::string>> action_parameters{
        {size, "state"}, {Type{ValueType::Const, Type{ValueType::Reference, sizes}}, "window"}};
    add("lr_action", number, action_parameters, std::move(actions));
    if (dynamic) {
        conflicts.push_back(returned(Array::createExpression(Array{})));
        add("lr_conflict", Type{ValueType::Array, number}, action_parameters, std::move(conflicts));
        Statements labels;
        for (std::size_t i = 1; i < lr->getProductions().size(); ++i) {
            const auto& production = lr->getProductions()[i];
            const auto& name = production.source.original_rules.empty() ? production.lhs : production.source.original_rules;
            auto label = corelib::text::join(name, "::") + " (production " + std::to_string(i - 1) + ")";
            if (!production.source.position.file.empty()) label += " at " + production.source.position.file;
            labels.push_back(If::createStatement(If{equals(symbol("rule"), integer(i - 1)),
                {returned(String::createExpression(String{.value = std::move(label)}))}}));
        }
        labels.push_back(fail());
        add("lr_rule_label", Type{ValueType::String}, {{size, "rule"}}, std::move(labels));
    }

    std::map<LRBase::Name, std::size_t> ids;
    for (const auto &production : lr->getProductions()) if (!ids.contains(production.lhs)) ids.emplace(production.lhs, ids.size());
    Statements gotos;
    for (const auto &[state, row] : lr->getGotoTable()) for (const auto &[name, next] : row) {
        auto condition = conjunction(equals(symbol("state"), integer(state)), equals(symbol("lhs"), integer(ids.at(name))));
        gotos.push_back(If::createStatement(If{std::move(condition), {returned(integer(next))}}));
    }
    gotos.push_back(fail());
    add("lr_goto", size, {{size, "state"}, {size, "lhs"}}, std::move(gotos));
    Statements lengths, lhs, reductions;
    for (std::size_t i = 1; i < lr->getProductions().size(); ++i) {
        const auto &production = lr->getProductions()[i];
        const auto id = i - 1;
        lengths.push_back(If::createStatement(If{equals(symbol("rule"), integer(id)), {returned(integer(production.rhs.size()))}}));
        lhs.push_back(If::createStatement(If{equals(symbol("rule"), integer(id)), {returned(integer(ids.at(production.lhs)))}}));
        Statements reduce;
        std::function<std::size_t(const AST::RuleMember&)> captureCount;
        captureCount = [&](const AST::RuleMember& member) -> std::size_t {
            if (!member.prefix.empty()) return 1;
            std::size_t count = 0;
            if (member.isGroup()) for (const auto& child : member.getGroup().values) count += captureCount(*child);
            else if (member.isOp() && !member.getOp().options.empty()) count = captureCount(*member.getOp().options.front());
            return count;
        };
        const auto helperSource = [&](const LRBase::Name& name) -> const AST::RuleMember* {
            for (const auto& candidate : lr->getProductions())
                if (candidate.lhs == name && candidate.source.normalization_source)
                    return candidate.source.normalization_source.get();
            return nullptr;
        };
        const auto innerCaptures = [&](const AST::RuleMember& source) {
            auto uncaptured = source;
            uncaptured.prefix.clear();
            return captureCount(uncaptured);
        };
        if (const auto* source = production.source.normalization_source.get()) {
            Array indices, offsets, splice;
            std::size_t count = 0;
            const bool explicit_captures = innerCaptures(*source) != 0;
            for (std::size_t m = 0; m < production.rhs.size(); ++m) {
                const auto& member = *production.source.rule_members[m];
                const auto* child = helperSource(production.rhs[m]);
                const bool recursive = child && (production.rhs[m] == production.lhs || production.rhs[m].back() == "__tail");
                const bool expanded = child && member.prefix.empty() && innerCaptures(*child);
                if (explicit_captures && member.prefix.empty() && !expanded && !recursive) continue;
                indices.values.push_back(integer(m));
                offsets.values.push_back(integer(recursive ? 0 : count));
                splice.values.push_back(integer(recursive || expanded));
                if (!recursive) count += expanded ? innerCaptures(*child) : 1;
            }
            // Empty optional/repetition alternatives retain the same column schema.
            if (!count) count = explicit_captures ? innerCaptures(*source) : 1;
            reduce.push_back(returned(IspaLibFunctionCall::createExpression(IspaLibFunctionCall{
                .symbol = IspaLibSymbol{.exports = StdlibExports::LRPack},
                .args = {symbol("values"), Array::createExpression(indices), Array::createExpression(offsets),
                         Array::createExpression(splice), integer(count),
                         Bool::createExpression(Bool{.value = source->quantifier == '*' || source->quantifier == '+'})}})));
        } else {
            Type result_type = Type{Symbol{"Types", production.lhs}};
            reduce.push_back(Variable{.name = "result", .type = result_type});
            auto block = ParserIR::dataBlock(production.source.data_block);
            std::size_t capture = 0;
            for (std::size_t m = 0; m < production.source.rule_members.size(); ++m) {
                const auto& member = *production.source.rule_members[m];
                const auto* helper = helperSource(production.rhs[m]);
                const auto count = !member.prefix.empty() ? 1 : helper ? innerCaptures(*helper) : 0;
                for (std::size_t column = 0; column < count; ++column) {
                    if (!block.empty()) {
                        StorageSymbol destination;
                        destination.what = symbol("result");
                        if (block.is_regular_data_block()) destination.path.emplace_back("value");
                        else if (block.is_inclosed_map()) destination.path.emplace_back(production.source.data_block.fields.at(capture).first);
                        else throw std::invalid_argument("LR capture has undefined datablock");
                        reduce.push_back(IspaLibFunctionCall::createStatement(IspaLibFunctionCall{
                            .symbol = IspaLibSymbol{.exports = StdlibExports::LRCaptureAssign},
                            .args = {StorageSymbol::createExpression(destination), symbol("values"), integer(m),
                                Cast::createExpression(Cast{.type = std::make_shared<Type>(size),
                                    .what = integer(member.prefix.empty() ? static_cast<long long>(column) : -1)})}}));
                    }
                    ++capture;
                }
            }
            reduce.push_back(returned(IspaLibFunctionCall::createExpression(IspaLibFunctionCall{
                .symbol = IspaLibSymbol{.exports = StdlibExports::LRNode},
                .args = {symbol("result")}, .template_parameters = {std::make_shared<Type>(result_type)}})));
        }
        reductions.push_back(If::createStatement(If{equals(symbol("rule"), integer(id)), std::move(reduce)}));
    }
    lengths.push_back(fail()); lhs.push_back(fail()); reductions.push_back(fail());
    add("lr_length", size, {{size, "rule"}}, std::move(lengths));
    add("lr_lhs", size, {{size, "rule"}}, std::move(lhs));
    add("lr_reduce", any, {{size, "rule"}, {Type{ValueType::Const, Type{ValueType::Reference, values}}, "values"}}, std::move(reductions));

    Statements shifts;
    for (const auto &[name, block] : lexer_builder.getDataBlocks()) {
        auto condition = equals(memberCall("token", "kind"), tokenId(name));
        StorageSymbol node;
        node.what = symbol("token");
        node.path.emplace_back(FunctionCall{.name = std::make_shared<Symbol>("to_node"),
            .template_parameters = {std::make_shared<Type>(Type{Symbol{"Types", name}})}});
        shifts.push_back(If::createStatement(If{std::move(condition), {returned(IspaLibFunctionCall::createExpression(IspaLibFunctionCall{
            .symbol = IspaLibSymbol{.exports = StdlibExports::LRToken},
            .args = {StorageSymbol::createExpression(node)}}))}}));
    }
    shifts.push_back(fail());
    add("lr_shift", any, {{Type{ValueType::Const, Type{ValueType::Reference, Type{Symbol{"Token"}}}}, "token"}}, std::move(shifts));

    Function main;
    main.type = Type{ValueType::RuleResult, Type{Symbol{"Types", "main"}}, Type{Symbol{"IT"}}};
    main.name = "main";
    main.parameters = {{Type{Symbol{"IT"}}, "pos"}};
    main.template_parameters = {{"IT", {IspaLibSymbol{.exports = StdlibExports::LexerTokenIterator}, IspaLibSymbol{.exports = StdlibExports::LexerLazyIterator}}}};
    main.statements.push_back(returned(IspaLibFunctionCall::createExpression(IspaLibFunctionCall{
        .symbol = IspaLibSymbol{.exports = dynamic ? StdlibExports::LRParseGeneralized : StdlibExports::LRParse},
        .args = {symbol("pos")}, .template_parameters = {std::make_shared<Type>(Symbol{"Parser"})}})));
    parser.data.emplace_back(std::make_shared<Declaration>(Function::createDeclaration(std::move(main))), Visibility::Protected);
}
}
