#include <gtest/gtest.h>
#include <PyRawParser.h>
import Parser.Base;
import ParserIR.API;
import AST.API;
import UAST.Python;
import LangAPI;
import LangRepr.Holder;
import LangRepr.Converter;
import std;

namespace {
const UAST::SourcePosition position{"conversion.isc", 0, 0, 7, 3};
auto expression(const std::string& source) {
    return Parser::ParserBase::convertPython(*UAST::parsePythonExpr(source, position));
}
auto statements(const std::string& source) {
    return Parser::ParserBase::convertPython(UAST::parsePythonModule(source, position));
}
}
TEST(PythonConversion, ExternalExpressionUsesOriginalParserTypeAndSource) {
    using Binding = PyRawParser::Exports::ExpressionBlock;
    static_assert(std::is_same_v<Binding::node_type, PyRawParser::Types::expr>);
    const std::string source = "host\n(a + 2) * b} trailing";
    auto result = Binding::parse(source.c_str(), source.c_str() + 5);
    ASSERT_TRUE(result.status);
    EXPECT_EQ(result.node.start(), source.c_str() + 5);
    EXPECT_EQ(result.node.line(), 2u);
    EXPECT_EQ(std::string_view(result.end), "} trailing");
    const auto syntax = UAST::convertPythonExpr(result.node, {"extern.isc", 5, result.node.length(), 2, 1});
    ASSERT_TRUE(syntax);
    EXPECT_FALSE(Parser::ParserBase::convertPython(*syntax).empty());
}

TEST(PythonConversion, ExternalStatementsPreserveIndentationAndHostBoundary) {
    using Binding = PyRawParser::Exports::StatementsBlock;
    static_assert(std::is_same_v<Binding::node_type, PyRawParser::Types::main>);
    const std::string source = "p{x = 1\nif x:\n    x = x + 1\n} NEXT";
    const auto result = Binding::parse(source.c_str(), source.c_str());
    ASSERT_TRUE(result.status);
    EXPECT_EQ(std::string_view(result.end), " NEXT");
    const auto syntax = UAST::convertPythonModule(result.node, {"extern.isc", 2, result.node.length(), 1, 3});
    EXPECT_EQ(syntax.body.size(), 2u);
    const char invalid[] = "p{x = }";
    EXPECT_THROW(Binding::parse(invalid, invalid), std::runtime_error);
}

TEST(PythonConversion, RawStatementsRespectPythonBoundariesAndBaseIndent) {
    using Binding = PyRawParser::Exports::RawStatements;
    const std::string source = R"(
    value = {'brace': '}', 'word': 'match A;'}
    # } match B;
    if value:
        value = 2
    match A -> captured;
})";
    auto parsed = Binding::parse(source.c_str(), source.c_str());
    ASSERT_TRUE(parsed.status);
    EXPECT_TRUE(std::string_view(parsed.end).starts_with("match A"));
    auto syntax = UAST::convertPythonModule(parsed.node, {"raw.isc", parsed.node.startpos(), parsed.node.length(), parsed.node.line(), parsed.node.column()});
    EXPECT_EQ(syntax.body.size(), 2u);
    EXPECT_FALSE(Binding::starts(source.c_str(), parsed.end));
    EXPECT_FALSE(Binding::starts(source.c_str(), " }"));
}

TEST(PythonConversion, ArithmeticPreservesGrouping) {
    const auto value = expression("(a + b) * c");
    ASSERT_FALSE(value.empty());
    EXPECT_EQ(value.front().getExpressionElement(), LangAPI::ExpressionElement::GroupOpen);
    int adds = 0, multiplies = 0;
    for (const auto& item : value) if (item.isExpressionElement()) {
        adds += item.getExpressionElement() == LangAPI::ExpressionElement::Add;
        multiplies += item.getExpressionElement() == LangAPI::ExpressionElement::Multiply;
    }
    EXPECT_EQ(adds, 1);
    EXPECT_EQ(multiplies, 1);
}
TEST(PythonConversion, CallsAndStorage) {
    auto call = expression("make(1, True)").front().getFunctionCall();
    ASSERT_EQ(call.args.size(), 2u);
    EXPECT_EQ(call.args[0].front().getRValue().getInt().value, 1);
    EXPECT_TRUE(call.args[1].front().getRValue().getBool().value);
    auto attribute = expression("node.value").front().getRValue().getStorageSymbol();
    EXPECT_EQ(std::get<std::string>(attribute.path.front()), "value");
    auto index = expression("values[2]").front().getRValue().getStorageSymbol();
    EXPECT_EQ(std::get<LangAPI::StorageOffset>(index.path.front()).offset.front().getRValue().getInt().value, 2);
}
TEST(PythonConversion, AssignmentAndControlFlow) {
    const auto output = statements("x: int = 1\nx = x + 1\nif x > 1:\n    x += 2\nelse:\n    x -= 1\nwhile x < 10:\n    x += 1\nreturn x\n");
    ASSERT_EQ(output.size(), 5u);
    EXPECT_TRUE(output[0].isVariable());
    EXPECT_TRUE(output[1].getExpression().front().isVariableAssignment());
    EXPECT_EQ(output[2].getIf().else_stmt.size(), 1u);
    EXPECT_EQ(output[3].getWhile().stmt.size(), 1u);
    EXPECT_TRUE(output[4].getExpression().front().isReturn());
}
TEST(PythonConversion, DeclarationsKeepTypesAndParameters) {
    auto module = UAST::parsePythonModule("def add(x: int, y: int) -> int:\n    return x + y\nclass Box:\n    value: int = 0\n", position);
    auto output = Parser::ParserBase::convertPythonDeclarations(module);
    ASSERT_EQ(output.size(), 2u);
    const auto& f = output[0].getFunction();
    EXPECT_EQ(f.name, "add");
    EXPECT_TRUE(f.type == LangAPI::ValueType::Int);
    EXPECT_EQ(f.parameters.size(), 2u);
    EXPECT_EQ(output[1].getClass().data.size(), 1u);
}
TEST(PythonConversion, RejectsUnsupportedSyntaxWithPosition) {
    try {
        expression("a ** b");
        FAIL() << "expected unsupported operator";
    } catch (const std::invalid_argument& error) {
        EXPECT_NE(std::string(error.what()).find("conversion.isc:7:3:"), std::string::npos);
    }
    EXPECT_THROW(expression("a < f() < c"), std::invalid_argument);
    EXPECT_THROW(statements("while True:\n    pass\nelse:\n    pass\n"), std::invalid_argument);
}
TEST(PythonConversion, DataBlockPreservesInitializer) {
    AST::DataBlock block;
    block.value = AST::RegularDataBlock{*UAST::parsePythonExpr("42", position)};
    auto output = ParserIR::dataBlock(block);
    ASSERT_TRUE(output.is_regular_data_block());
    EXPECT_EQ(output.getRegularDataBlock().first.front().getRValue().getInt().value, 42);
}

TEST(PythonConversion, ContainersAndExistingBindings) {
    EXPECT_EQ(expression("[1, 2]").front().getRValue().getArray().values.size(), 2u);
    EXPECT_EQ(expression("(1, 2)").front().getRValue().getMakeTuple().args.size(), 2u);
    EXPECT_EQ(expression("{'key': 1}").front().getRValue().getMap().keys.size(), 1u);
    auto module = UAST::parsePythonModule("capture = 5\n", position);
    auto output = Parser::ParserBase::convertPython(module, {"capture"});
    ASSERT_EQ(output.size(), 1u);
    EXPECT_TRUE(output.front().getExpression().front().isVariableAssignment());
    EXPECT_THROW(statements("if True:\n    x = 1\n"), std::invalid_argument);
    EXPECT_THROW(statements("break\n"), std::invalid_argument);
}
TEST(PythonConversion, BoundedSourcePositions) {
    const auto value = UAST::parsePythonExpr("a + b", position);
    const auto& right = value->get<UAST::py::BinaryExpr>()->right;
    EXPECT_EQ(right->pos.offset, 4u);
    EXPECT_EQ(right->pos.line, 7u);
    EXPECT_EQ(right->pos.column, 7u);
}

TEST(PythonConversion, DeclarationsReachExistingCodeEmitter) {
    const auto module = UAST::parsePythonModule("def add(x: int, y: int) -> int:\n    return x + y\n", position);
    LangRepr::Holder holder{Parser::ParserBase::convertPythonDeclarations(module)};
    LangRepr::Converter converter(holder, "cpp", "PythonConversionTest", false);
    converter.init();
    converter.construct();
    std::string output;
    for (const auto& [name, source] : converter.get()) output += source;
    EXPECT_NE(output.find("add("), std::string::npos);
    EXPECT_NE(output.find("return "), std::string::npos);
    EXPECT_NE(output.find(" + "), std::string::npos);
}

TEST(PythonConversion, ActionContextValidatesMetadataAndPreservesLocals) {
    const auto action = [](const std::string& source) {
        AST::PythonAction result;
        result.code = UAST::parsePythonModule(source, position);
        return result;
    };
    std::set<std::string> locals;
    EXPECT_NO_THROW(Parser::ParserBase::convertPythonAction(action("saved = ctx.pos\nctx.ast.count: int = 3\n"), locals));
    EXPECT_TRUE(locals.contains("saved"));
    const auto restore = Parser::ParserBase::convertPythonAction(action("ctx.pos = saved\n"), locals);
    EXPECT_TRUE(restore.front().getExpression().front().isVariableAssignment());
    for (const auto* source : {"ctx = 1\n", "ctx: int = 1\n", "ctx.rule = 'x'\n", "ctx.start_pos += 1\n", "x = ctx.unknown\n", "x = ctx.failed_rule\n"})
        EXPECT_THROW(Parser::ParserBase::convertPythonAction(action(source), locals), std::invalid_argument) << source;
    EXPECT_NO_THROW(Parser::ParserBase::convertPythonAction(action("name = ctx.failed_rule\nreturn\n"), locals, true));
    EXPECT_NO_THROW(Parser::ParserBase::convertPythonAction(action("ctx.sync('}', ';')\nctx.insert()\n"), locals, true));
    EXPECT_NO_THROW(Parser::ParserBase::convertPythonAction(action("x = ctx.at(ID) or ctx.at(common.ID) or ctx.at('=')\n"), locals, true));
    for (const auto* source : {"ctx.sync()\n", "ctx.sync('')\n", "ctx.sync(42)\n"})
        EXPECT_THROW(Parser::ParserBase::convertPythonAction(action(source), locals, true), std::invalid_argument);
}
