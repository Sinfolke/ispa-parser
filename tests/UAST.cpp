#include <gtest/gtest.h>
#include <output/Parser.h>
import UAST;
import UAST.Parser;
import UAST.Python;
import AST.Builder;
import AST.API;
import AST.Tree;
import std;

namespace {
AST::Tree convert(const char* source) {
    Parser::Parser parser;
    AST::Builder builder(parser.parse(source), "feature.isc");
    builder.build();
    return builder.get();
}
template<class T> const T& feature(const AST::RuleMember& member) {
    for (const auto& f : member.features)
        if (const auto* value = std::get_if<T>(&f)) return *value;
    throw std::runtime_error("missing expected feature");
}
}

TEST(UAST, PlainEbnfAndCapture) {
    Parser::Parser parser;
    auto syntax = parser.parse("WORD: @ 'a'+ {@};");
    AST::Builder builder(syntax);
    builder.build();
    auto tree = builder.get();
    const auto& rule = tree.getTreeMap().at({"WORD"});
    ASSERT_EQ(rule.rule_members.size(), 1u);
    const auto& member = *rule.rule_members.front();
    EXPECT_TRUE(member.prefix.present);
    EXPECT_EQ(member.quantifier, '+');
    ASSERT_TRUE(member.isString());
    EXPECT_EQ(member.getString().value, "a");
    ASSERT_TRUE(rule.data_block.isRegularDataBlock());
    EXPECT_TRUE(std::holds_alternative<AST::At>(rule.data_block.getRegDataBlock()));
    ASSERT_TRUE(rule.data_block.type.has_value());
    EXPECT_EQ(rule.data_block.type->kind, AST::DataType::Kind::Character);
}

TEST(UAST, OwnsParserDataAndPositions) {
    UAST::main syntax;
    {
        std::string source = "WORD: 'a';";
        Parser::Parser parser;
        syntax = parser.parse(source.c_str());
    }
    const auto& declaration = std::get<UAST::Node<UAST::grammar>>(syntax.value.at(0));
    EXPECT_EQ(UAST::positionOf(declaration.data().name.data().primary, "owned.isc").file, "owned.isc");
    EXPECT_EQ(UAST::positionOf(declaration.data().name.data().primary, "owned.isc").offset, 0u);
    EXPECT_EQ(UAST::positionOf(declaration.data().name.data().primary, "owned.isc").line, 1u);
    EXPECT_EQ(UAST::positionOf(declaration.data().name.data().primary, "owned.isc").column, 1u);
    EXPECT_FALSE(declaration.empty());
    EXPECT_EQ(declaration.data().name.data().primary.data().value, "WORD");
    AST::Builder builder(syntax);
    EXPECT_NO_THROW(builder.build());
}

TEST(UAST, FailBindingsAndMarkers) {
    auto tree = convert("T: % 'a' %handler 'b' %{handler, fallback};");
    const auto& rule = tree.getTreeMap().at({"T"});
    ASSERT_EQ(rule.rule_members.size(), 2u);
    EXPECT_TRUE(feature<AST::FailMarker>(*rule.rule_members[0]).name.empty());
    EXPECT_EQ(feature<AST::FailMarker>(*rule.rule_members[1]).name.front(), "handler");
    ASSERT_EQ(rule.features.size(), 1u);
    const auto& binding = std::get<AST::FailBinding>(rule.features.front());
    EXPECT_EQ(binding.names.size(), 2u);
    EXPECT_EQ(binding.position.file, "feature.isc");
}

TEST(UAST, RegionCapture) {
    auto tree = convert("T: @=('a' 'b');");
    const auto& member = *tree.getTreeMap().at({"T"}).rule_members.front();
    ASSERT_TRUE(member.isGroup());
    EXPECT_EQ(member.getGroup().values.size(), 2u);
    EXPECT_EQ(feature<AST::RegionCapture>(member).capture, '@');
    auto failTree = convert("T: %=('a' 'b');");
    const auto& fail = *failTree.getTreeMap().at({"T"}).rule_members.front();
    EXPECT_EQ(feature<AST::RegionCapture>(fail).capture, '%');
}

TEST(UAST, DynamicPattern) {
    auto tree = convert("T: $name;");
    const auto& member = *tree.getTreeMap().at({"T"}).rule_members.front();
    EXPECT_EQ(feature<AST::DynamicPattern>(member).name, "name");
    EXPECT_FALSE(member.empty());
}

TEST(UAST, KeepsCombinedCapturesAndDeclarationParameters) {
    auto tree = convert("#[inline] T<type>(arg): &value @node 'a';");
    const auto& rule = tree.getTreeMap().at({"T"});
    const auto& member = *rule.rule_members.front();
    EXPECT_EQ(member.prefix.name, "node");
    EXPECT_EQ(feature<AST::VariableCapture>(member).name, "value");
    const auto& declaration = std::get<AST::DeclarationSyntax>(rule.features.front());
    EXPECT_EQ(declaration.modifiers.front(), "inline");
    EXPECT_EQ(declaration.parameters.front(), "arg");
    EXPECT_EQ(declaration.templateParameters.front(), "type");
}

TEST(UAST, PreservesUnknownReferences) {
    auto tree = convert("T: externallyQualifiedName;");
    const auto& member = *tree.getTreeMap().at({"T"}).rule_members.front();
    ASSERT_TRUE(member.isName());
    EXPECT_EQ(member.getName().name.front(), "externallyQualifiedName");
}

TEST(UAST, ResolvesQualifiedAndScopedReferences) {
    auto tree = convert(
        "caller: rule->ast; ast: 'g'; "
        "rule: (ast | other) #ast: 'n'; #other: ast;;");
    const auto& rules = tree.getTreeMap();
    const auto check = [](const AST::RuleMember& member, auto expected) {
        ASSERT_TRUE(member.isName());
        EXPECT_EQ(member.getName().name, expected);
    };
    const auto nested = rules.at({"caller"}).rule_members.front()->getName().name;
    ASSERT_EQ(nested.size(), 2u);
    EXPECT_EQ(nested[0], "rule");
    EXPECT_EQ(nested[1], "ast");
    const auto& group = rules.at({"rule"}).rule_members.front()->getGroup();
    const auto& options = group.values.front()->getOp().options;
    check(*options[0], nested);
    check(*rules.at({"rule", "other"}).rule_members.front(), nested);
    auto other = nested;
    other.back() = "other";
    check(*options[1], other);
}

TEST(UAST, DoesNotResolveQualifiedReferencesBySuffix) {
    auto tree = convert("caller: missing->ast; ast: 'g';");
    const auto& name = tree.getTreeMap().at({"caller"}).rule_members.front()->getName().name;
    ASSERT_EQ(name.size(), 2u);
    EXPECT_EQ(name[0], "missing");
    EXPECT_EQ(name[1], "ast");
}

TEST(UAST, BoundedCountersAndSharedRegistration) {
    auto tree = convert("T: 'a'+=3 => count 'b'+=limit;");
    const auto& members = tree.getTreeMap().at({"T"}).rule_members;
    ASSERT_EQ(members.size(), 2u);
    EXPECT_EQ(feature<AST::Counter>(*members[0]).bound, "3");
    EXPECT_EQ(feature<AST::Counter>(*members[0]).kind, "number");
    EXPECT_EQ(feature<AST::Counter>(*members[1]).bound, "limit");
    EXPECT_EQ(feature<AST::SharedCounterRegistration>(*members[0]).name, "count");
}

TEST(UAST, PythonActionAndFailBlock) {
    Parser::Parser parser;
    auto syntax = parser.parse("fail recover(value) p{py} T: 'a';");
    AST::Builder builder(syntax);
    builder.build();
    auto tree = builder.get();
    ASSERT_EQ(tree.getFailBlocks().size(), 1u);
    const auto& fail = tree.getFailBlocks().front();
    EXPECT_EQ(fail.name.front(), "recover");
    EXPECT_EQ(fail.parameters.front(), "value");
    EXPECT_EQ(fail.action.python.kind, "main");
    EXPECT_TRUE(fail.action.bindings.empty());
}

TEST(UAST, PythonSubtreeRetainsStatementsAndExpressions) {
    UAST::SourcePosition pos{"action.isc", 25, 0, 4, 2};
    const auto statements = UAST::parsePythonSnapshot("x = 3\nif x:\n    return x\n", pos, false);
    EXPECT_EQ(statements.kind, "main");
    ASSERT_FALSE(statements.children.empty());
    const auto expression = UAST::parsePythonSnapshot("x + 2", pos, true);
    EXPECT_EQ(expression.kind, "expr");
    EXPECT_EQ(expression.position.file, "action.isc");
}

TEST(UAST, PythonExpressionInDynamicPatternAndCounter) {
    auto tree = convert("T: ${p{py}} 'a'+=p{py};");
    const auto& members = tree.getTreeMap().at({"T"}).rule_members;
    ASSERT_EQ(members.size(), 2u);
    EXPECT_EQ(feature<AST::DynamicPattern>(*members[0]).expression.python.kind, "expr");
    EXPECT_EQ(feature<AST::Counter>(*members[1]).expression.python.kind, "expr");
}

TEST(UAST, ConvertsBootstrapGrammar) {
    UAST::main syntax;
    for (const auto* name : {"entry.isc", "common.isc", "rule.isc", "adv_rule.isc", "fail_block.isc"}) {
        const auto path = std::filesystem::path(ROOT_DIR) / "parser/ispa/grammar" / name;
        std::ifstream input(path);
        ASSERT_TRUE(input.is_open());
        std::string source((std::istreambuf_iterator<char>(input)), {});
        Parser::Parser parser;
        auto file = parser.parse(source.c_str());
        ASSERT_FALSE(file.value.empty()) << path;
        syntax.value.insert(syntax.value.end(), file.value.begin(), file.value.end());
    }
    AST::Builder builder(syntax);
    ASSERT_NO_THROW(builder.build());
    auto tree = builder.get();
    EXPECT_GT(tree.getTreeMap().size(), 30u);
    EXPECT_TRUE(tree.contains({"rule", "value", "mul_capture"}));
    EXPECT_TRUE(tree.contains({"advanced_rule"}));
}

TEST(UAST, AdvancedRuleKeepsPythonActions) {
    auto tree = convert("T { p{py} }");
    const auto& features = tree.getTreeMap().at({"T"}).features;
    ASSERT_EQ(features.size(), 2u);
    EXPECT_EQ(std::get<AST::AdvancedRule>(features[0]).syntax.kind, "advanced_rule");
    EXPECT_EQ(std::get<AST::PythonAction>(features[1]).python.kind, "main");
}

TEST(UAST, PythonAstBlocksKeepTargets) {
    auto tree = convert("T: 'a' &{ result: p{py} }; S: 'b' {p{py}};");
    const auto& keyed = tree.getTreeMap().at({"T"}).features;
    ASSERT_EQ(keyed.size(), 1u);
    const auto& action = std::get<AST::PythonAction>(keyed.front());
    EXPECT_EQ(action.target, "result");
    EXPECT_EQ(action.python.kind, "expr");
    const auto& single = tree.getTreeMap().at({"S"}).features;
    ASSERT_EQ(single.size(), 1u);
    EXPECT_TRUE(std::get<AST::PythonAction>(single.front()).target.empty());
}

TEST(UAST, DataBlockMetadataUsesResolvedNamesAndFieldOrder) {
    auto tree = convert("main: @ WORD @ 'x' @{word, suffix}; WORD: 'w';");
    const auto& fields = tree.getTreeMap().at({"main"}).data_block.fields;
    ASSERT_EQ(fields.size(), 2u);
    EXPECT_EQ(fields[0].first, "word");
    EXPECT_EQ(fields[0].second.kind, AST::DataType::Kind::Token);
    ASSERT_EQ(fields[0].second.name.size(), 1u);
    EXPECT_EQ(fields[0].second.name.front(), "WORD");
    EXPECT_EQ(fields[1].first, "suffix");
    EXPECT_EQ(fields[1].second.kind, AST::DataType::Kind::Character);
}
