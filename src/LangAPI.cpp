module LangAPI;
namespace LangAPI {
    template<typename Param>
    inline void printTemplateParameters(std::ostream &os, stdu::vector<Param> params) {
        os << '<';
        for (const auto &p : params) {
            std::visit([&os](const auto &v) { os << v; }, p);
        }
        os << '>';
    }
    template<typename Param>
    inline void printTemplateParametersShared(std::ostream &os, stdu::vector<Param> params) {
        os << '<';
        for (const auto &p : params) {
            std::visit([&os](const auto &v) { os << *v; }, p);
        }
        os << '>';
    }
    inline void printExpressionArgs(std::ostream &os, stdu::vector<Expression> args) {
        bool first = true;
        for (const auto &arg : args) {
            os << arg;
            if (!first) {
                os << ", ";
            }
            first = false;
        }
    }
    auto operator<<(std::ostream &os, const Char &c) -> std::ostream& {
        return os << (c.escaped ? "\\" : "") << c.value;
    }
    auto operator<<(std::ostream &os, const Int &i) -> std::ostream& {
        return os << i.value;
    }
    auto operator<<(std::ostream &os, const Bool &b) -> std::ostream& {
        return os << b.value;
    }
    auto operator<<(std::ostream &os, const Float &f) -> std::ostream& {
        return os << f.value;
    }
    auto operator<<(std::ostream &os, const String &s) -> std::ostream& {
        return os << '"' << s.value << '"';
    }


    auto operator<<(std::ostream &os, ExpressionElement e) -> std::ostream& {
        switch (e) {
            case ExpressionElement::GroupOpen: os << "GroupOpen"; break;
            case ExpressionElement::GroupClose: os << "GroupClose"; break;
            case ExpressionElement::SquareBraceOpen: os << "SquareBraceOpen"; break;
            case ExpressionElement::SquareBraceClose: os << "SquareBraceClose"; break;
            case ExpressionElement::And: os << "And"; break;
            case ExpressionElement::Or: os << "Or"; break;
            case ExpressionElement::Not: os << "Not"; break;
            case ExpressionElement::Equal: os << "Equal"; break;
            case ExpressionElement::NotEqual: os << "NotEqual"; break;
            case ExpressionElement::Higher: os << "Higher"; break;
            case ExpressionElement::Lower: os << "Lower"; break;
            case ExpressionElement::HigherOrEqual: os << "HigherOrEqual"; break;
            case ExpressionElement::LowerOrEqual: os << "LowerOrEqual"; break;
            case ExpressionElement::Add: os << "Add"; break;
            case ExpressionElement::Minus: os << "Minus"; break;
            case ExpressionElement::Multiply: os << "Multiply"; break;
            case ExpressionElement::Divide: os << "Divide"; break;
            case ExpressionElement::Modulo: os << "Modulo"; break;
            case ExpressionElement::PlusPlus: os << "PlusPlus"; break;
            case ExpressionElement::MinusMinus: os << "MinusMinus"; break;
        }
        return os;
    }

    auto operator<<(std::ostream &os, OperatorType op) -> std::ostream& {
        switch (op) {
            case OperatorType::Assign: os << "Assign"; break;
            case OperatorType::Add: os << "Add"; break;
            case OperatorType::Minus: os << "Minus"; break;
            case OperatorType::Multiply: os << "Multiply"; break;
            case OperatorType::Divide: os << "Divide"; break;
            case OperatorType::Modulo: os << "Modulo"; break;
        }
        return os;
    }

    auto operator<<(std::ostream &os, ValueType v) -> std::ostream& {
        switch (v) {
            case ValueType::Undef: os << "Undef"; break;
            case ValueType::Char: os << "Char"; break;
            case ValueType::Int: os << "Int"; break;
            case ValueType::Bool: os << "Bool"; break;
            case ValueType::Float: os << "Float"; break;
            case ValueType::String: os << "String"; break;
            case ValueType::Array: os << "Array"; break;
            case ValueType::FixedSizeArray: os << "FixedSizeArray"; break;
            case ValueType::Map: os << "Map"; break;
            case ValueType::Symbol: os << "Symbol"; break;
            case ValueType::StorageSymbol: os << "StorageSymbol"; break;
            case ValueType::Inheritance: os << "Inheritance"; break;
            case ValueType::Token: os << "Token"; break;
            case ValueType::Rule: os << "Rule"; break;
            case ValueType::TokenResult: os << "TokenResult"; break;
            case ValueType::RuleResult: os << "RuleResult"; break;
            case ValueType::Span: os << "Span"; break;
            case ValueType::Variant: os << "Variant"; break;
            case ValueType::Box: os << "Box"; break;
            case ValueType::Any: os << "Any"; break;
        }
        return os;
    }

    auto operator<<(std::ostream &os, RValueType r) -> std::ostream& {
        switch (r) {
            case RValueType::Undef: os << "Undef"; break;
            case RValueType::Char: os << "Char"; break;
            case RValueType::Int: os << "Int"; break;
            case RValueType::Bool: os << "Bool"; break;
            case RValueType::Float: os << "Float"; break;
            case RValueType::String: os << "String"; break;
            case RValueType::Array: os << "Array"; break;
            case RValueType::FixedSizeArray: os << "FixedSizeArray"; break;
            case RValueType::Map: os << "Map"; break;
            case RValueType::Pos: os << "Pos"; break;
            case RValueType::Symbol: os << "Symbol"; break;
            case RValueType::StorageSymbol: os << "StorageSymbol"; break;
            case RValueType::Inheritance: os << "Inheritance"; break;
            case RValueType::IspaLibDfaTransition: os << "IspaLibDfaTransition"; break;
            case RValueType::IspaLibDfaSpanCharState: os << "IspaLibDfaSpanCharState"; break;
            case RValueType::IspaLibDfaSpanMultiTableState: os << "IspaLibDfaSpanMultiTableState"; break;
            case RValueType::IspaLibDfaEmptyState: os << "IspaLibDfaEmptyState"; break;
            case RValueType::Reference: os << "Reference"; break;
            case RValueType::Span: os << "Span"; break;
        }
        return os;
    }

    auto operator<<(std::ostream &os, ExpressionValueType e) -> std::ostream& {
        switch (e) {
            case ExpressionValueType::Empty: os << "Empty"; break;
            case ExpressionValueType::RValue: os << "RValue"; break;
            case ExpressionValueType::ExpressionElement: os << "ExpressionElement"; break;
            case ExpressionValueType::FunctionCall: os << "FunctionCall"; break;
            case ExpressionValueType::IspaLibFunctionCall: os << "IspaLibFunctionCall"; break;
            case ExpressionValueType::StringCompare: os << "StringCompare"; break;
            case ExpressionValueType::Return: os << "Return"; break;
            case ExpressionValueType::Break: os << "Break"; break;
            case ExpressionValueType::Continue: os << "Continue"; break;
            case ExpressionValueType::VariableAssignment: os << "VariableAssignment"; break;
            case ExpressionValueType::CounterIncreament: os << "CounterIncreament"; break;
            case ExpressionValueType::CounterIncreamentByLength: os << "CounterIncreamentByLength"; break;
            case ExpressionValueType::ResetPosCounter: os << "ResetPosCounter"; break;
            case ExpressionValueType::PushPosCounter: os << "PushPosCounter"; break;
            case ExpressionValueType::PopPosCounter: os << "PopPosCounter"; break;
            case ExpressionValueType::SkipSpaces: os << "SkipSpaces"; break;
            case ExpressionValueType::DfaLookup: os << "DfaLookup"; break;
            case ExpressionValueType::ReportError: os << "ReportError"; break;
            case ExpressionValueType::Lambda: os << "Lambda"; break;
        }
        return os;
    }

    auto operator<<(std::ostream &os, ArrayMethods m) -> std::ostream& {
        switch (m) {
            case ArrayMethods::Push: os << "Push"; break;
            case ArrayMethods::Pop: os << "Pop"; break;
        }
        return os;
    }

    auto operator<<(std::ostream &os, Visibility v) -> std::ostream& {
        switch (v) {
            case Visibility::Private: os << "Private"; break;
            case Visibility::Public: os << "Public"; break;
        }
        return os;
    }

    auto operator<<(std::ostream &os, Language l) -> std::ostream& {
        switch (l) {
            case Language::Cpp: os << "Cpp"; break;
        }
        return os;
    }

    auto operator<<(std::ostream &os, StdlibExports e) -> std::ostream& {
        switch (e) {
            case StdlibExports::Node: os << "Node"; break;
            case StdlibExports::MatchResult: os << "MatchResult"; break;
            case StdlibExports::Lexer: os << "Lexer"; break;
            case StdlibExports::Parser: os << "Parser"; break;
            case StdlibExports::DfaTokenTransition: os << "DfaTokenTransition"; break;
            case StdlibExports::DfaCharTransition: os << "DfaCharTransition"; break;
            case StdlibExports::DfaCharTableTransition: os << "DfaCharTableTransition"; break;
            case StdlibExports::DfaMultiTransition: os << "DfaMultiTransition"; break;
            case StdlibExports::DfaCharState: os << "DfaCharState"; break;
            case StdlibExports::DfaCharTableState: os << "DfaCharTableState"; break;
            case StdlibExports::DfaTokenState: os << "DfaTokenState"; break;
            case StdlibExports::DfaMultiTableState: os << "DfaMultiTableState"; break;
            case StdlibExports::DfaCharEmptyState: os << "DfaCharEmptyState"; break;
            case StdlibExports::DfaMultiTableEmptyState: os << "DfaMultiTableEmptyState"; break;
            case StdlibExports::DfaSpanCharTableState: os << "DfaSpanCharTableState"; break;
            case StdlibExports::DfaSpanTokenTableState: os << "DfaSpanTokenTableState"; break;
            case StdlibExports::DfaSpanMultiTableState: os << "DfaSpanMultiTableState"; break;
            case StdlibExports::DfaCharTable: os << "DfaCharTable"; break;
            case StdlibExports::DfaTokenTable: os << "DfaTokenTable"; break;
            case StdlibExports::DfaMultiTable: os << "DfaMultiTable"; break;
            case StdlibExports::ParserFunctionParameter: os << "ParserFunctionParameter"; break;
            case StdlibExports::DfaEmptyStateGroupBegin: os << "DfaEmptyStateGroupBegin"; break;
            case StdlibExports::DfaEmptyStateMemberBegin: os << "DfaEmptyStateMemberBegin"; break;
            case StdlibExports::DfaCharTableEmptyStateLambdaParameter: os << "DfaCharTableEmptyStateLambdaParameter"; break;
            case StdlibExports::DfaMultiTableEmptyStateLambdaParameter: os << "DfaMultiTableEmptyStateLambdaParameter"; break;
            case StdlibExports::DfaSpanCharTableEmptyStateLambdaParameter: os << "DfaSpanCharTableEmptyStateLambdaParameter"; break;
            case StdlibExports::DfaCstStore: os << "DfaCstStore"; break;
            case StdlibExports::DfaCstGroupStore: os << "DfaCstGroupStore"; break;
        }
        return os;
    }
    auto operator<<(std::ostream& os, const Declarations &expression) -> std::ostream& {
        for (const auto &declaration : expression) {
            os << declaration << "\n";
        }
        return os;
    }
    auto operator<<(std::ostream& os, const Statements &statements) -> std::ostream& {
        for (const auto &statement : statements) {
            os << statement << "\n";
        }
        return os;
    }
    auto operator<<(std::ostream& os, const Expression &expression) -> std::ostream& {
        for (const auto &expr : expression) {
            os << expr;
        }
        return os;
    }
    auto operator<<(std::ostream& os, const Array &arr) -> std::ostream& {
        printTemplateParameters(os, arr.template_parameters);
        printExpressionArgs(os, arr.values);
        return os;
    }
    auto operator<<(std::ostream& os, const FixedSizeArray &arr)  -> std::ostream&{
        printTemplateParameters(os, arr.template_parameters);
        printExpressionArgs(os, arr.values);
        return os;
    }
    auto operator<<(std::ostream& os, const Map &map) -> std::ostream& {
        printTemplateParameters(os, map.template_parameters);
        os << '{';
        for (std::size_t i = 0; i < map.values.size(); ++i) {
            std::visit([&os](const auto &key) {
                os << key;
            }, map.keys[i]);
            os << ": " << map.values[i];
            if (i != map.values.size() - 1) os << ", ";
        }
        return os << '}';
    }
    auto operator<<(std::ostream& os, const Pos &pos)  -> std::ostream&{
        os << (pos.dereference ? "*" : "");
        if (pos.offset) {
            os << "(pos + " << pos.offset << ")";
        } else {
            os << "pos";
        }
        return os;
    }

    auto operator<<(std::ostream& os, const ArrayMethodCall &amc)  -> std::ostream&{
        os << amc.method;
        os << "(";
        printExpressionArgs(os, amc.args);
        os << ")";
        return os;
    }

    auto operator<<(std::ostream& os, const FunctionCall &fc)  -> std::ostream& {
        os << fc.name;
        printExpressionArgs(os, fc.args);
        return os;
    }

    auto operator<<(std::ostream &os, const Symbol &obj) -> std::ostream& {
        bool first = true;
        for (const auto &part : obj.path) {
            std::visit([&os](const auto &v) { os << v; }, part);
            if (!first)
                os << "::";
            first = false;
        }
        return os;
    }

    auto operator<<(std::ostream &os, const StorageSymbol &obj) -> std::ostream& {
        os << "(" << obj.what << ")";
        for (const auto &part : obj.path) {
            os << ".";
            std::visit([&os](const auto &v) { os << v; }, part);
        }
        return os;
    }

    auto operator<<(std::ostream &os, const IspaLibSymbol &obj) -> std::ostream& {
        os << obj.exports;
        printTemplateParametersShared(os, obj.template_parameters);
        return os;
    }

    auto operator<<(std::ostream &os, const IspaLibFunctionCall &obj) -> std::ostream& {
        os << obj.symbol;
        printExpressionArgs(os, obj.args);
        return os;
    }

    auto operator<<(std::ostream &os, const Inheritance &obj) -> std::ostream& {
        os << obj.name;
        printExpressionArgs(os, obj.args);
        return os;
    }

    auto operator<<(std::ostream &os, const Token &obj) -> std::ostream& {
        os << "[token]";
        return os;
    }

    auto operator<<(std::ostream &os, const Rule &obj) -> std::ostream& {
        os << "[Rule]";
        return os;
    }

    auto operator<<(std::ostream &os, const TokenResult &obj) -> std::ostream& {
        os << "[TokenResult]";
        return os;
    }

    auto operator<<(std::ostream &os, const RuleResult &obj) -> std::ostream& {
        os << "[RuleResult]";
        return os;
    }

    auto operator<<(std::ostream &os, const IspaLibDfaTransition &obj) -> std::ostream& {
        os << "[dfa_transition]";
        return os;
    }

    auto operator<<(std::ostream &os, const IspaLibDfaState &obj) -> std::ostream& {
        os << "[dfa_state]";
        return os;
    }

    auto operator<<(std::ostream &os, const IspaLibDfaSpanCharState &obj) -> std::ostream& {
        os << "[dfa_span_char_state]";
        return os;
    }

    auto operator<<(std::ostream &os, const IspaLibDfaSpanMultiTableState &obj) -> std::ostream& {
        os << "[dfa_span_multi_table_state]";
        return os;
    }

    auto operator<<(std::ostream &os, const IspaLibDfaEmptyState &obj) -> std::ostream& {
        os << "[dfa_empty_state]";
        return os;
    }

    auto operator<<(std::ostream &os, const Reference &obj) -> std::ostream& {
        os << obj.value;
        return os;
    }

    auto operator<<(std::ostream &os, const Span &obj) -> std::ostream& {
        os << "Span<" << obj.type << "> of " << obj.sym;
        return os;
    }

    auto operator<<(std::ostream &os, const RValue &obj) -> std::ostream& {
        std::visit([&os](const auto &value) { if constexpr (!std::is_same_v<std::decay_t<decltype(value)>, std::monostate>) os << value; }, obj.get());
        return os;
    }

    auto operator<<(std::ostream &os, const Type &obj) -> std::ostream& {
        if (obj.isSymbol()) {
            bool first = true;
            for (const auto &t : obj.getSymbol().path) {
                if (std::holds_alternative<std::string>(t)) {
                    if (!first) os << "::";
                    os << std::get<std::string>(t);
                    first = false;
                } else {
                    os << std::get<FunctionCall>(t);
                }
            }
        } else if (obj.isValueType()) {
            os << '[' << obj.getValueType() << ']';
        } else if (obj.isIspaLibSymbol()) {
            os << obj.getIspaLibSymbol();
        }
        if (!obj.template_parameters.empty()) {
            os << "<";
            for (const auto &t : obj.template_parameters) {
                if (std::holds_alternative<Type>(t)) {
                    os << std::get<Type>(t) << ",";
                } else os << std::get<RValue>(t);
            }
            os << ">";
        }
        return os;
    }

    auto operator<<(std::ostream &os, const ForwardDeclaredClass &obj) -> std::ostream& {
        os << (obj.isStruct ? "struct" : "class") << ' ' << obj.name;
        return os;
    }

    auto operator<<(std::ostream &os, const Class &obj) -> std::ostream& {
        os << "class " << obj.name;
        if (!obj.inherit_members.empty()) {
            os << " : ";
            for (const auto &inherit : obj.inherit_members) {
                os << inherit.first << ' ';
                std::visit([&os](const auto &value) { os << value; }, inherit.second);
            }
        }
        os << "{\n";
        Visibility visibility = obj.default_visibility;
        for (const auto &member : obj.data) {
            if (visibility != member.second) {
                os << member.second << ":\n";
                visibility = member.second;
            }
            os << member.first << ";\n";
        }
        return os;
    }

    auto operator<<(std::ostream &os, const Namespace &obj) -> std::ostream& {
        os << "namespace " << obj.name << "{\n";
        os << obj.declarations;
        os << "}\n";
        return os;
    }

    auto operator<<(std::ostream &os, const Function &obj) -> std::ostream& {
        if (!obj.template_parameters.empty()) {
            os << "template<";
            bool first = true;
            for (const auto &t : obj.template_parameters) {
                if (!first)
                    os << ", ";
                os << "typename " << t;
                first = false;
            }
            os << ">\n";
        }
        os << "auto " << obj.name;
        bool first = true;
        for (const auto &[type, name] : obj.parameters) {
            os << type << ' ' << name;
            if (!first) os << ", ";
            first = false;
        }
        os << " -> " << obj.type << " {\n";
        os << obj.statements;
        os << "}";
        return os;
    }

    auto operator<<(std::ostream &os, const TypeAlias &obj) -> std::ostream& {
        os << "using " << obj.name << " = " << obj.type;
        return os;
    }

    auto operator<<(std::ostream &os, const Enum &obj) -> std::ostream& {
        os << "enum class " << obj.name << "{\n";
        for (const auto &member : obj.value) {
            os << member << ",\n";
        }
        return os << "};\n";
    }

    auto operator<<(std::ostream &os, const Variable &obj) -> std::ostream& {
        os << obj.type << ' ' << obj.name << " = " << obj.value;
        return os;
    }

    auto operator<<(std::ostream &os, const Declaration &obj) -> std::ostream& {
        std::visit([&os](const auto &v) { os << v; }, obj.value);
        return os;
    }

    auto operator<<(std::ostream &os, const Break &obj) -> std::ostream& {
        return os << "break;";
    }

    auto operator<<(std::ostream &os, const Continue &obj) -> std::ostream& {
        return os << "continue;";
    }

    auto operator<<(std::ostream &os, const Return &obj) -> std::ostream& {
        return os << "return " << obj.value << ";";
    }

    auto operator<<(std::ostream &os, const StringCompare &obj) -> std::ostream& {
        return os << "[string_compare]";
    }

    auto operator<<(std::ostream &os, const VariableAssignment &obj) -> std::ostream& {
        return os << obj.name << ' ' << obj.type << "=" << ' ' << obj.value << ';';
    }

    auto operator<<(std::ostream &os, const CounterIncreament &obj) -> std::ostream& {
        return os << "++pos";
    }

    auto operator<<(std::ostream &os, const CounterIncreamentByLength &obj) -> std::ostream& {
        return os << "pos += " << obj.name << ".lenght();";
    }

    auto operator<<(std::ostream &os, const ResetPosCounter &obj) -> std::ostream& {
        return os << "[reset_pos_counter]";
    }

    auto operator<<(std::ostream &os, const PushPosCounter &obj) -> std::ostream& {
        return os << "[push_pos_counter]: " << obj.name;
    }

    auto operator<<(std::ostream &os, const PopPosCounter &obj) -> std::ostream& {
        return os << "[pop_pos_counter]";
    }

    auto operator<<(std::ostream &os, const SkipSpaces &obj) -> std::ostream& {
        return os << "[skip_spaces]";
    }

    auto operator<<(std::ostream &os, const DfaLookup &obj) -> std::ostream& {
        return os << "[dfa_lookup]";
    }

    auto operator<<(std::ostream &os, const ReportError &obj) -> std::ostream& {
        return os << "[report_error]";
    }

    auto operator<<(std::ostream &os, const Lambda &obj) -> std::ostream& {
        os << "[]";
        bool first = true;
        for (const auto &[type, name] : obj.parameters) {
            os << type << ' ' << name;
            if (!first) os << ", ";
            first = false;
        }
        os << "{\n";
        os << obj.statements;
        os << "}\n";
        return os;
    }

    auto operator<<(std::ostream &os, const ExpressionValue &obj) -> std::ostream& {
        std::visit([&os](const auto &v) { os << v; }, obj.value);
        return os;
    }

    auto operator<<(std::ostream &os, const If &obj) -> std::ostream& {
        return os << "if (" << obj.expr << ") {\n" << obj.stmt << "} else {\n" << obj.else_stmt << "}";
    }

    auto operator<<(std::ostream &os, const While &obj) -> std::ostream& {
        return os << "while (" << obj.expr << ") {\n" << obj.stmt << "}";
    }

    auto operator<<(std::ostream &os, const DoWhile &obj) -> std::ostream& {
        return os << "do {\n" << obj.stmt << "} while (" << obj.expr << ");";
    }

    auto operator<<(std::ostream &os, const Switch &obj) -> std::ostream& {
        os << "switch (" << obj.expression << ") {\n";
        for (const auto &[value, statements] : obj.cases) {
            os << "case " << value << ": {\n" << statements << "}\n";
        }
        os << "}";
        return os;
    }

    auto operator<<(std::ostream &os, const Statement &obj) -> std::ostream& {
        std::visit([&os](const auto &v) { os << v; }, obj.value);
        return os;
    }
}