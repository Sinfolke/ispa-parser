#include <gtest/gtest.h>
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
