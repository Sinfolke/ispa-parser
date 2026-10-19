#include <gtest/gtest.h>
#include <output/Parser.h>
import UAST;
import UAST.Parser;
import AST.Builder;
import AST.API;
import AST.Tree;
import std;

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
