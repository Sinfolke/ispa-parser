module Cpp.Statement;

import Cpp.CoreFunctions;
import std;
auto Cpp::Statement::createVariable(const LangAPI::Variable &v) -> void {
    output.write("{} {}", Core::convertType(v.type), v.name);
    if (!v.value.empty()) {
        output.dwrite(" = {}", Core::convertExpression(v.value));
    }
    output.dwriteln(";");
}
auto Cpp::Statement::createIf(const LangAPI::Expression &expression) -> void {
    output.writeln("if ({}) {", Core::convertExpression(expression));
}
