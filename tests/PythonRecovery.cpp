#include <python/parser.hpp>
#include <gtest/gtest.h>
import UAST.Python;

namespace {
void expectPreservedTail(const PyRawParser::Types::main& tree, const std::string& source) {
    PyRawParser::Types::main tail;
    tail.value.push_back(tree.value.back());
    ISPA_STD::Node<PyRawParser::Types::main> node{
        0, source.c_str(), source.c_str() + source.size(), source.size(), 1, 1, 0, tail};
    const UAST::SourcePosition position{"recovery.py", 0, source.size(), 1, 1};
    const auto actual = UAST::convertPythonModule(node, position);
    const auto expected = UAST::parsePythonModule("y = 2\n", position);
    EXPECT_EQ(UAST::py::dump(actual), UAST::py::dump(expected));
}
}

TEST(PythonRecovery, PreservesFollowingStatementsInBothIteratorModes) {
    for (const bool lazy : {false, true}) {
        for (const char* source : {"x =\ny = 2\n", "x = 1 +\ny = 2\n",
                                   "x = 1 unexpected\ny = 2\n", "x = f(1, +)\ny = 2\n"}) {
            SCOPED_TRACE(source);
            SCOPED_TRACE(lazy);
            const std::string input(source);
            PyParser parser;
            PyRawParser::Types::main tree;
            if (lazy) tree = parser.parseLazy(input);
            else {
                PyLexer lexer;
                lexer.makeTokens(input);
                tree = parser.parse(lexer);
            }
            ASSERT_EQ(tree.value.size(), 2u);
            expectPreservedTail(tree, input);
            ASSERT_FALSE(parser.getErrors().empty());
            EXPECT_NE(parser.getErrors().front().message.find("Expected"), std::string::npos);
            EXPECT_LE(parser.getErrors().front().offset, std::string_view(source).size());
        }
    }
}

TEST(PythonRecovery, MissingColonPreservesNestedBlockAndOuterStatement) {
    PyParser parser;
    const std::string input = "if True\n    x =\ny = 2\n";
    const auto tree = parser.parseLazy(input);
    ASSERT_EQ(tree.value.size(), 2u);
    expectPreservedTail(tree, input);
    ASSERT_GE(parser.getErrors().size(), 2u);
    EXPECT_EQ(parser.getErrors().front().message, "Expected ':' after Python compound statement header");
}

TEST(PythonRecovery, MissingClosingDelimiterAtEofIsDiagnosedByParser) {
    for (const char* source : {"x = (1", "x = [1", "x = {'k': 1", "x = f(1"}) {
        SCOPED_TRACE(source);
        PyParser parser;
        EXPECT_NO_THROW(parser.parseLazy(std::string(source)));
        ASSERT_FALSE(parser.getErrors().empty());
        EXPECT_NE(parser.getErrors().front().message.find("to close Python expression"), std::string::npos);
    }
}

TEST(PythonRecovery, ValidSyntaxAndNewParseHaveNoDiagnostics) {
    PyParser parser;
    parser.parseLazy("x =\n");
    ASSERT_FALSE(parser.getErrors().empty());
    const auto tree = parser.parseLazy("x = f(1, 2)\nif x:\n    y = [1,\n         2]\nelse:\n    y = {'k': (3, 4)}\nz = y\n");
    EXPECT_EQ(tree.value.size(), 3u);
    EXPECT_TRUE(parser.getErrors().empty());
    EXPECT_TRUE(parser.getContextErrors().empty());
}
