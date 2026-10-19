#include <gtest/gtest.h>
#include <output/Parser.h>
import UAST.Parser;
import AST.Builder;
import AST.Tree;
import AST.BackendGuard;
import std;
namespace {
AST::Tree convert(const char* source) {
    Parser::Parser parser;
    AST::Builder builder(UAST::fromParser(parser.parse(source), "feature.isc"));
    builder.build();
    return builder.get();
}
}

TEST(UAST, BackendGuardAllowsSupportedGrammar) {
    auto tree = convert("T: @ ('a' | 'b')+ {@}; main: @ T {@};");
    EXPECT_NO_THROW(AST::requireCppSupport(tree));
}

TEST(UAST, BackendGuardRejectsUnsupportedFeaturesWithPositions) {
    for (const auto* source : {
        "T: $name;", "T: @=('a');", "T: % 'a';",
        "T: 'a' %{handler};", "T: 'a'+=3;", "T: 'a' => count;",
        "fail handler p{py} T: 'a';", "T: 'a' {p{py}};", "T: \\s;"
    }) {
        auto tree = convert(source);
        try {
            AST::requireCppSupport(tree);
            FAIL() << source;
        } catch (const std::runtime_error& error) {
            const std::string message = error.what();
            EXPECT_NE(message.find("feature.isc:1:"), std::string::npos) << message;
            EXPECT_NE(message.find("is not yet supported by the C++ backend"), std::string::npos) << message;
        }
    }
}
