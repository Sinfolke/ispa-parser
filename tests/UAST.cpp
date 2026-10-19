#include <gtest/gtest.h>
#include <output/Parser.h>
import UAST;
import UAST.Parser;
import AST.Builder;
import AST.API;
import AST.Tree;
import std;

namespace {
AST::Tree convert(const char* source) {
    Parser::Parser parser;
    AST::Builder builder(UAST::fromParser(parser.parse(source), "feature.isc"));
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
    auto syntax = UAST::fromParser(parser.parse("WORD: @ 'a'+ {@};"), "plain.isc");
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
    EXPECT_TRUE(rule.data_block.isRegularDataBlock());
}

TEST(UAST, OwnsParserDataAndPositions) {
    UAST::main syntax;
    {
        std::string source = "WORD: 'a';";
        Parser::Parser parser;
        syntax = UAST::fromParser(parser.parse(source.c_str()), "owned.isc");
    }
    const auto& declaration = std::get<UAST::Node<UAST::grammar>>(syntax.value.at(0));
    EXPECT_EQ(declaration.position.file, "owned.isc");
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
}

TEST(UAST, DynamicPattern) {
    auto tree = convert("T: $name;");
    const auto& member = *tree.getTreeMap().at({"T"}).rule_members.front();
    EXPECT_EQ(feature<AST::DynamicPattern>(member).name, "name");
}

TEST(UAST, LeavesReferenceResolutionToSemanticStage) {
    auto tree = convert("T: externallyQualifiedName;");
    const auto& member = *tree.getTreeMap().at({"T"}).rule_members.front();
    ASSERT_TRUE(member.isName());
    EXPECT_EQ(member.getName().name.front(), "externallyQualifiedName");
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
