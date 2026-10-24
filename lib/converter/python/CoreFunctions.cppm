export module Python.CoreFunctions;

import LangAPI;
import std;
import dstd;

export namespace Python {
    // All conversion state is per Construct, unlike Cpp.CoreFunctions globals.
    class Core {
        std::vector<std::string> counters_{"pos"};
        std::string module_name_;
        std::size_t lambda_number_ = 0;
    public:
        struct LambdaDefinition { std::string name, params, body; };
    private:
        std::vector<LambdaDefinition> pending_lambdas_;
        std::function<std::string(const LangAPI::Statements&)> statement_writer_;
        std::string symbol(const LangAPI::Symbol& symbol);
        std::string storage(const LangAPI::StorageSymbol& symbol);
        std::string lib(const LangAPI::IspaLibSymbol& symbol);
        std::string rvalue(const LangAPI::RValue& value);
        std::string call(const LangAPI::FunctionCall& value);
        std::string lib_call(const LangAPI::IspaLibFunctionCall& value);
        std::string lambda(const LangAPI::Lambda& value);
        std::string element(LangAPI::ExpressionElement value, bool real_division = false);
        std::string templates(const decltype(LangAPI::Type::template_parameters)& values);
        std::string templates(const stdu::vector<std::variant<std::shared_ptr<LangAPI::Type>, std::shared_ptr<LangAPI::RValue>>>& values);
        std::string counter() const;
    public:
        explicit Core(std::string module_name);
        void set_statement_writer(std::function<std::string(const LangAPI::Statements&)> callback);
        std::vector<LambdaDefinition> take_pending_lambdas();
        // Used when a nested statement list is rendered while outer lambdas are still queued.
        void restore_pending_lambdas(std::vector<LambdaDefinition> saved);
        bool has_pending_lambdas() const { return !pending_lambdas_.empty(); }
        std::string type(const LangAPI::Type& value);
        std::string value(const LangAPI::RValue& v) { return rvalue(v); }
        std::string expression(const LangAPI::Expression& value);
        std::string statement_expression(const LangAPI::Expression& value);
        std::string literal(const std::string& source) const;
        static std::string identifier(const std::string& s);
        static std::string symbol_path(const std::string& text);
    };
}
