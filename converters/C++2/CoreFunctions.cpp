module Cpp.CoreFunctions;

import corelib;
import logging;

import dstd;

auto Core::convertType(const LangAPI::Type &type) -> std::string {
    if (type.isValueType()) {
        switch (type.getValueType()) {
            case LangAPI::ValueType::Char:
                return "char";
            case LangAPI::ValueType::Int:
                return "int";
            case LangAPI::ValueType::Float:
                return "double";
            case LangAPI::ValueType::Bool:
                return "bool";
            case LangAPI::ValueType::String:
                return "std::string";
            case LangAPI::ValueType::Array:
                return std::string("std::vector<") + convertTemplates(type.template_parameters) + ">";
            case LangAPI::ValueType::FixedSizeArray:
                return std::string("std::array<") + convertTemplates(type.template_parameters) + ">";
            case LangAPI::ValueType::Map:
                return std::string("std::unordered_map<") + convertTemplates(type.template_parameters) + ">";
            case LangAPI::ValueType::Token:
                return std::string("::ISPA_STD::Node<Tokens, ") + convertTemplates(type.template_parameters) + ">";
            case LangAPI::ValueType::Rule:
                return std::string("::ISPA_STD::Node<Rules, ") + convertTemplates(type.template_parameters) + ">";
            case LangAPI::ValueType::TokenResult:
                return std::string("::ISPA_STD::MatchResult<Tokens, ") + convertTemplates(type.template_parameters) + ">";
            case LangAPI::ValueType::RuleResult:
                return std::string("::ISPA_STD::MatchResult<Rules, ") + convertTemplates(type.template_parameters) + ">";
            case LangAPI::ValueType::Variant:
                return std::string("std::variant<") + convertTemplates(type.template_parameters) + ">";
            case LangAPI::ValueType::Box:
                return std::string("std::shared_ptr<") + convertTemplates(type.template_parameters) + ">";
            case LangAPI::ValueType::Undef:
                return "Undef";;
                throw Error("Type is undefined");
            default:
                throw Error("Unknown type");
        }
    } else if (type.isSymbol()) {
        return convertSymbol(type.getSymbol());
    } else if (type.isIspaLibSymbol()) {
        return convertIspaLibSymbol(type.getIspaLibSymbol());
    } else throw Error("unknown variant type in Type::type");
}

auto Core::convertTemplates(const decltype(LangAPI::Type::template_parameters) &template_parameters) -> std::string {
    std::string res;
    for (const auto &param : template_parameters) {
        if (std::holds_alternative<LangAPI::Type>(param)) {
            res += convertType(std::get<LangAPI::Type>(param));
        } else {
            res += convertRValue(std::get<LangAPI::RValue>(param));
        }
        res += ", ";
    }
    return res.substr(0, res.size() - 2);
}
auto Core::convertTemplates(const decltype(LangAPI::Array::template_parameters) &template_parameters) -> std::string {
    std::string res;
    for (const auto &param : template_parameters) {
        if (std::holds_alternative<std::shared_ptr<LangAPI::Type>>(param)) {
            res += convertType(*std::get<std::shared_ptr<LangAPI::Type>>(param));
        } else {
            res += convertRValue(std::get<LangAPI::RValue>(param));
        }
        res += ", ";
    }
    return res.substr(0, res.size() - 2);
}
auto Core::convertTemplates(const decltype(LangAPI::IspaLibSymbol::template_parameters) &template_parameters) -> std::string {
    std::string res;
    for (const auto &param : template_parameters) {
        res += convertType(param);
        res += ", ";
    }
    return res.substr(0, res.size() - 2);
}

auto Core::convertSymbol(const LangAPI::Symbol &symbol) -> std::string {
    std::string res;
    for (const auto &part : symbol.path) {
        if (std::holds_alternative<std::string>(part)) {
            res += std::get<std::string>(part);
        } else {
            res = convertFunctionCall(std::get<LangAPI::FunctionCall>(part));
        }
        res += "::";
    }
    res.pop_back();
    res.pop_back();
    return res;
}
auto Core::convertStorageSymbol(const LangAPI::StorageSymbol &symbol) -> std::string {
    std::string res = convertExpression(symbol.what);
    for (const auto &part : symbol.path) {
        res += ".";
        if (std::holds_alternative<std::string>(part)) {
            res += std::get<std::string>(part);
        } else if (std::holds_alternative<LangAPI::ArrayMethodCall>(part)) {
            const auto &method_call = std::get<LangAPI::ArrayMethodCall>(part);
            switch (method_call.method) {
                case LangAPI::ArrayMethods::Push:
                    res += "push_back";
                    break;
                case LangAPI::ArrayMethods::Pop:
                    res += "pop_back";
                    break;
            }
            res += "(";
            for (const auto &param : method_call.args) {
                res += convertExpression(param) + ", ";
            }
            res += ")";
        } else {
            res = convertFunctionCall(std::get<LangAPI::FunctionCall>(part));
        }
    }
    return res;
}
auto Core::convertIspaLibSymbol(const LangAPI::IspaLibSymbol &symbol) -> std::string {
    switch (symbol.exports) {
        case LangAPI::StdlibExports::Node:
            return "::ISPA_STD::Node<Tokens>";
        case LangAPI::StdlibExports::Lexer:
            return "::ISPA_STD::Lexer_base<Tokens>";
        case LangAPI::StdlibExports::Parser:
            return "::ISPA_STD::Parser_base<Tokens, Rules>";
        case LangAPI::StdlibExports::DfaCharTransition:
            return "::ISPA_STD::DFAAPI::CharTransition";
        case LangAPI::StdlibExports::DfaTokenTransition:
            return "::ISPA_STD::DFAAPI::TokenTransition<Tokens>";
        case LangAPI::StdlibExports::DfaCharTableTransition:
            return "::ISPA_STD::DFAAPI::CharTableTransition<Tokens, " + convertTemplates(symbol.template_parameters) + ">";
        case LangAPI::StdlibExports::DfaMultiTransition:
            return "::ISPA_STD::DFAAPI::MultiTableTransition<Tokens, " + convertTemplates(symbol.template_parameters) + ">";
        default:
            throw Error("Unknown IspaLibSymbol exports");
    }
}

auto Core::convertExpression(const LangAPI::Expression &expression) -> std::string {
    for (const auto &expr : expression) {
        switch (expr.type()) {
            case LangAPI::ExpressionValueType::Empty:
                return "";
            case LangAPI::ExpressionValueType::RValue:
                return convertRValue(expr.getRValue());
            case LangAPI::ExpressionValueType::ExpressionElement:
                return convertExpressionElement(expr.getExpressionElement());
            case LangAPI::ExpressionValueType::FunctionCall:
                return convertFunctionCall(expr.getFunctionCall());
            case LangAPI::ExpressionValueType::StringCompare: {
                auto compare = expr.getStringCompare();
                return std::string("strncmp(") + counter.back() + ", " + (compare.is_string ? std::string("\"") + compare.str.value + "\""  : std::string("'") + compare.str.value + "'");
            }
            case LangAPI::ExpressionValueType::Return:
                return std::string("return ") + convertExpression(expr.getReturn().value) + ';';
            case LangAPI::ExpressionValueType::Break:
                return "break;";
            case LangAPI::ExpressionValueType::Continue:
                return "continue;";
            case LangAPI::ExpressionValueType::VariableAssignment: {
                const auto &var = expr.getVariableAssignment();
                std::string type;
                switch (var.type) {
                    case LangAPI::OperatorType::Assign:
                        type = "=";
                    case LangAPI::OperatorType::Add:
                        type = "+=";
                    case LangAPI::OperatorType::Minus:
                        type = "-=";
                    case LangAPI::OperatorType::Multiply:
                        type = "*=";
                    case LangAPI::OperatorType::Divide:
                        type = "/=";
                    case LangAPI::OperatorType::Modulo:
                        type = "%=";
                }
                return var.name + " " + type + " " + convertExpression(var.value) + ';';
            }
            case LangAPI::ExpressionValueType::CounterIncreament:
                return std::string("++") + counter.back();
            case LangAPI::ExpressionValueType::CounterIncreamentByLength:
                return counter.back() + " += " + expr.getCounterIncreamentByLength().name + ".token.length();";
            // case LangAPI::ExpressionValueType::ResetPosCounter: {
            //
            // }
            case LangAPI::ExpressionValueType::PushPosCounter: {
                const auto &a = expr.getPushPosCounter();
                std::string str("auto " + a.name + " = " + counter.back() + ";");
                counter.push_back(a.name);
                return str;
            }
            case LangAPI::ExpressionValueType::PopPosCounter: {
                std::string str(counter[counter.size() - 2] + " = " + counter.back() + ";");
                counter.pop_back();
                return str;
            }
            case LangAPI::ExpressionValueType::SkipSpaces:
                return "skip_spaces(" + counter.back() + ")";
            case LangAPI::ExpressionValueType::DfaLookup: {
                const auto &lookup = expr.getDfaLookup();
                return lookup.output_name + " = ISPA_STD::DFA<Tokens>::decide(dfa_span_"  + std::to_string(lookup.dfa_count) + ", pos, &ISPA_STD::LLParser_base<Tokens, Rules>::PANIC_MODE);";
            }
            default:
                throw Error("Unknown expression type");
        }
    }
    return ""; // empty expression
}
auto Core::convertExpressionElement(LangAPI::ExpressionElement element) -> const char * {
    switch (element) {
        case LangAPI::ExpressionElement::GroupOpen:
            return "(";
        case LangAPI::ExpressionElement::GroupClose:
            return ")";
        case LangAPI::ExpressionElement::SquareBraceOpen:
            return "[";
        case LangAPI::ExpressionElement::SquareBraceClose:
            return "]";
        case LangAPI::ExpressionElement::And:
            return "&&";
        case LangAPI::ExpressionElement::Or:
            return "||";
        case LangAPI::ExpressionElement::Not:
            return "!";
        case LangAPI::ExpressionElement::Equal:
            return "==";
        case LangAPI::ExpressionElement::NotEqual:
            return "!=";
        case LangAPI::ExpressionElement::Higher:
            return ">";
        case LangAPI::ExpressionElement::Lower:
            return "<";
        case LangAPI::ExpressionElement::HigherOrEqual:
            return ">=";
        case LangAPI::ExpressionElement::LowerOrEqual:
            return "<=";
        case LangAPI::ExpressionElement::Add:
            return "+";
        case LangAPI::ExpressionElement::Minus:
            return "-";
        case LangAPI::ExpressionElement::Multiply:
            return "*";
        case LangAPI::ExpressionElement::Divide:
            return "/";
        case LangAPI::ExpressionElement::Modulo:
            return "%";
        case LangAPI::ExpressionElement::PlusPlus:
            return "++";
        case LangAPI::ExpressionElement::MinusMinus:
            return "--";
        default:
            throw Error("Unknown expression element");
    }
}
auto Core::convertFunctionCall(const LangAPI::FunctionCall &call) -> std::string {
    std::string str = call.name + "(";
    for (const auto &param : call.args) {
        str += convertExpression(param) + ", ";
    }
    str.pop_back();
    str.pop_back();
    str += ")";
    return str;
}
auto Core::convertRValue(const LangAPI::RValue &rvalue) -> std::string {
    switch (rvalue.type()) {
        case LangAPI::RValueType::Undef:
            throw Error("RValue type is undefined");
        case LangAPI::RValueType::Char:
            return "'" + (rvalue.getChar().escaped ? std::string("\\") : std::string()) + std::string(1, rvalue.getChar().value) + "'";
        case LangAPI::RValueType::Int:
            return std::to_string(rvalue.getInt().value);
        case LangAPI::RValueType::Bool:
            return rvalue.getBool().value ? "true" : "false";
        case LangAPI::RValueType::Float:
            return std::to_string(rvalue.getFloat().value);
        case LangAPI::RValueType::String:
            return std::string("\"") + rvalue.getString().value + "\"";
        case LangAPI::RValueType::Array: {
            std::string res = "std::vector<" + convertTemplates(rvalue.getArray().template_parameters) + ">{";
            for (const auto &el : rvalue.getArray().values) {
                res += convertExpression(el) + ", ";
            }
            res.pop_back();
            res.pop_back();
            res += "}";
            return res;
        }
        case LangAPI::RValueType::FixedSizeArray: {
            const auto &array = rvalue.getFixedSizeArray();
            std::string res = std::string("std::array<") + convertTemplates(array.template_parameters) + "> {";
            for (const auto &el : array.values) {
                res += convertExpression(el) + ", ";
            }
            res.pop_back();
            res.pop_back();
            res += "}";
            return res;
        }
        case LangAPI::RValueType::Map: {
            std::string res = "std::unordered_map<" + convertTemplates(rvalue.getMap().template_parameters) + ">{";
            for (std::size_t i = 0; i < rvalue.getMap().keys.size(); i++) {
                if (std::holds_alternative<LangAPI::String>(rvalue.getMap().keys[i])) {
                    res += std::string("\"") + std::get<LangAPI::String>(rvalue.getMap().keys[i]).value + "\", ";
                } else {
                    res += std::to_string(std::get<LangAPI::Int>(rvalue.getMap().keys[i]).value) + ", ";
                }
                res += "{ " + convertExpression(rvalue.getMap().values[i]) + "}, " ;
            }
            res.pop_back();
            res.pop_back();
            res += " }";
            return res;
        }
        case LangAPI::RValueType::Pos:
            return counter.back();
        case LangAPI::RValueType::Symbol:
            return convertSymbol(rvalue.getSymbol());
        case LangAPI::RValueType::StorageSymbol:
            return convertStorageSymbol(rvalue.getStorageSymbol());
        case LangAPI::RValueType::Inheritance:
            // TODO: Make inheritance
            return "";
        case LangAPI::RValueType::IspaLibDfaTransition: {
            const auto &transition = rvalue.getIspaLibDfaTransition();
            auto number_or_null = [](std::size_t number) -> std::string {
                return number != std::numeric_limits<std::size_t>::max() ? std::to_string(number) : "ISPA_STD::DFAAPI::null_state";
            };
            std::ostringstream out_content;
            out_content << "{ ";
            if (std::holds_alternative<char>(transition.symbol)) {
                out_content << std::string("'") << corelib::text::getEscapedAsStr(std::get<char>(transition.symbol), false) << "'";
            } else if (std::holds_alternative<std::size_t>(transition.symbol)) {
                out_content << "&dfa_span_" << std::to_string(std::get<std::size_t>(transition.symbol));
            } else {
                out_content << "Tokens::" << corelib::text::join(std::get<stdu::vector<std::string>>(transition.symbol), "_");
            }
            out_content << ", ";
            out_content << number_or_null(transition.next) << ", "
            << std::boolalpha << transition.new_cst_node << ", "
            << std::boolalpha << transition.new_member << ", "
            << std::boolalpha << transition.close_cst_node << ", "
            << number_or_null(transition.new_group) << ", "
            << number_or_null(transition.group_close) << ", "
            << number_or_null(transition.accept)
            << " }";
            return out_content.str();
        }
        case LangAPI::RValueType::Reference:
            return convertRValue(*rvalue.getReference().value) + "&";
        default:
            throw Error("Unknown RValue type");
    }
}