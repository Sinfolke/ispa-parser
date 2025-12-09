export module Cpp.CoreFunctions;

import LangAPI;
import Rope.String;
import Cpp.Statement;
import Cpp.Declarations;
import Converter.Writer;
import dstd;
import std;

export namespace Core {
    constexpr const char* base_pointer = "pos";
    std::vector<std::string> counter = { base_pointer };
    LangAPI::Visibility prev_visibility = LangAPI::Visibility::Private;
    bool first_template_parameter = true;
    Cpp::Statement *stmts_converter;
    Cpp::Declarations *declarations_converter;
    Converter::Writer *writer;
    // type
    auto convertType(const LangAPI::Type &type) -> std::string;
    auto convertTemplates(const decltype(LangAPI::Type::template_parameters) &template_parameters) -> std::string;
    auto convertTemplates(const decltype(LangAPI::Array::template_parameters) &template_parameters) -> std::string;
    auto convertTemplates(const stdu::vector<std::variant<std::shared_ptr<LangAPI::Type>, std::shared_ptr<LangAPI::RValue>>> &template_parameters) -> std::string;
    auto convertSymbol(const LangAPI::Symbol &symbol) -> std::string;
    auto convertStorageSymbol(const LangAPI::StorageSymbol &symbol) -> std::string;
    auto convertIspaLibSymbol(const LangAPI::IspaLibSymbol &symbol) -> std::string;

    // expression
    auto convertExpression(const LangAPI::Expression &expression) -> std::string;
    auto convertExpressionElement(LangAPI::ExpressionElement element) -> const char *;
    auto buildStatement(const LangAPI::Statement &stmt) -> void;
    auto buildStatements(const LangAPI::Statements &statements) -> void;
    auto convertLambda(const LangAPI::Lambda &lambda) -> std::string;
    auto convertFunctionCall(const LangAPI::FunctionCall &call) -> std::string;
    // rvalue
    auto convertRValue(const LangAPI::RValue &rvalue) -> std::string;
}
