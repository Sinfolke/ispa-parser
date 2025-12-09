module Cpp.Statement;

import Cpp.CoreFunctions;
import Converter.Statement;
import std;
Cpp::Statement::Statement(Converter::Writer &output) : Converter::Statement(output) {
    Core::writer = &output;
    Core::stmts_converter = this;
}

auto Cpp::Statement::createVariable(const LangAPI::Variable &v) -> void {
    output.write("{} {}", Core::convertType(v.type), v.name);
    if (!v.value.empty()) {
        output.dwrite(" = {}", Core::convertExpression(v.value));
    }
    output.dwriteln(";");
}
auto Cpp::Statement::createIf(const LangAPI::Expression &expression) -> void {
    output.writeln("if ({}) {", Core::convertExpression(expression));
    output.increaseIndentation();
}
auto Cpp::Statement::closeIf() -> void {
    output.decreaseIndentation();
    output.writeln("}");
}
auto Cpp::Statement::createWhile(const LangAPI::Expression &expression) -> void {
    output.writeln("while ({}) {", Core::convertExpression(expression));
    output.increaseIndentation();
}
auto Cpp::Statement::closeWhile() -> void {
    output.decreaseIndentation();
    output.writeln("}");
}
auto Cpp::Statement::openDoWhile() -> void {
    output.writeln("do {");
    output.increaseIndentation();
}
auto Cpp::Statement::closeDoWhile(const LangAPI::Expression &expression) -> void {
    output.decreaseIndentation();
    output.writeln("} while ({});", Core::convertExpression(expression));
}
auto Cpp::Statement::createSwitch(const LangAPI::Expression &expression) -> void {
    output.writeln("switch ({}) {", Core::convertExpression(expression));
    output.increaseIndentation();
}
auto Cpp::Statement::createCase(const LangAPI::RValue &rvalue) -> void {
    output.writeln("case {}: {", Core::convertRValue(rvalue));
    output.increaseIndentation();
}
auto Cpp::Statement::closeCase() -> void {
    output.writeln("break;");
    output.decreaseIndentation();
    output.writeln("}");
}
auto Cpp::Statement::closeSwitch() -> void {
    output.decreaseIndentation();
    output.writeln("}");
}
auto Cpp::Statement::createExpression(const LangAPI::Expression &expression) -> void {
    output.writeln("{};", Core::convertExpression(expression));
}
extern "C" Cpp::Statement* create_cpp_statement(Converter::Writer *output) {
    return new Cpp::Statement(*output);
}
extern "C" void delete_cpp_statement(Cpp::Statement *decl) {
    delete decl;
}