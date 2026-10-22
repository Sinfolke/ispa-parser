export module Cpp.CoreFunctions;

import LangAPI;
import Converter.Writer;
import dstd;
import std;

export namespace Core {
    constexpr const char* base_pointer = "pos";
    std::vector<std::string> counter = { base_pointer };
    bool first_template_parameter = true;
    std::string name;
    stdu::vector<std::string> *symbol_path = nullptr;
    std::size_t inside_array = 0;
    std::function<std::string(const LangAPI::Statements&)> lambda_body;
    std::stringstream init_content;
    // helper
    auto isNestedArrayType(const LangAPI::Type &t) -> bool;

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
    auto convertFunctionParams(const stdu::vector<LangAPI::Expression> &args);
    auto convertFunctionCall(const LangAPI::FunctionCall &call, bool need_template = false) -> std::string;
    auto convertIspaLibFunctionCall(const LangAPI::IspaLibFunctionCall &call) -> std::string;
    auto convertMakeTuple(const LangAPI::MakeTuple &make_tuple) -> std::string;
    auto convertGetVariant(const LangAPI::GetVariant &make_tuple) -> std::string;
    auto convertCheckVariant(const LangAPI::CheckVariant &check_variant) -> std::string;
    auto convertDFADebug(const LangAPI::DFADebug &dfa_debug) -> std::string;
    // rvalue
    auto convertArrayValues(
        const auto& values,
        bool double_braces = false
    ) -> std::string;
    auto convertRValue(const LangAPI::RValue &rvalue) -> std::string;

    auto optionalTemplates(const auto &template_parameters) -> std::string {
        if (!template_parameters.empty()) {
            return "<" + convertTemplates(template_parameters) + ">";
        }
        return "";
    }
    auto optionalTemplatesWithTokensParameter(const auto &template_parameters) -> std::string {
        if (!template_parameters.empty()) {
            return "<Tokens, " + convertTemplates(template_parameters) + ">";
        } else return "<Tokens>";
    }
    auto flushInitContent() -> void;
    // Forward declarations of overloads
    auto ensureNamespaced(const std::string &ns, const LangAPI::Symbol &sym) -> LangAPI::Symbol;
    auto ensureNamespaced(const std::string &ns, const LangAPI::StorageSymbol &ssym) -> LangAPI::StorageSymbol;
    auto ensureNamespaced(const std::string &ns, const LangAPI::IspaLibSymbol &sym) -> const LangAPI::IspaLibSymbol&;
    auto ensureNamespaced(const std::string &ns, const LangAPI::Type &type) -> LangAPI::Type;
    auto ensureNamespaced(const std::string &ns, const LangAPI::FunctionCall &fc) -> LangAPI::FunctionCall;
    auto ensureNamespaced(const std::string &ns, const LangAPI::RValue &rval) -> LangAPI::RValue;
    auto ensureNamespaced(const std::string &ns, const LangAPI::ExpressionValue &val) -> LangAPI::ExpressionValue;
    auto ensureNamespaced(const std::string &ns, const LangAPI::Expression &expr) -> LangAPI::Expression;
    auto ensureNamespaced(const std::string &ns, const LangAPI::Statement &stmt) -> LangAPI::Statement;
    auto ensureNamespaced(const std::string &ns, const LangAPI::Statements &stmts) -> LangAPI::Statements;
}
