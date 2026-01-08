module Cpp.CoreFunctions;

import corelib;
import logging;
import Cpp.Statement;
import Cpp.Declarations;

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
            case LangAPI::ValueType::Span:
                return "::ISPA_STD::Span<" + convertTemplates(type.template_parameters) + ">";
            case LangAPI::ValueType::Undef:
                return "Undef";
                // throw Error("Type is undefined");
            default:
                throw Error("Unknown type");
        }
    } else if (type.isSymbol()) {
        auto sym = convertSymbol(type.getSymbol());
        if (sym == "std::any") return "Tokens";
        return sym;
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
auto Core::convertTemplates(const stdu::vector<std::variant<std::shared_ptr<LangAPI::Type>, std::shared_ptr<LangAPI::RValue>>> &template_parameters) -> std::string {
    std::string res;
    for (const auto &param : template_parameters) {
        if (std::holds_alternative<std::shared_ptr<LangAPI::Type>>(param)) {
            res += convertType(*std::get<std::shared_ptr<LangAPI::Type>>(param));
        } else {
            res += convertRValue(*std::get<std::shared_ptr<LangAPI::RValue>>(param));
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

auto Core::convertSymbol(const LangAPI::Symbol &symbol) -> std::string {
    std::string res;
    for (const auto &part : symbol.path) {
        if (std::holds_alternative<std::string>(part)) {
            res += std::get<std::string>(part);
        } else {
            // Append function call as a symbol path segment (do not overwrite the accumulated path)
            res += convertFunctionCall(std::get<LangAPI::FunctionCall>(part));
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
            bool first = true;
            for (const auto &param : method_call.args) {
                if (!first) res += ", ";
                res += convertExpression(param);
                first = false;
            }
            res += ")";
        } else {
            // Append function call to the current storage symbol chain
            res += convertFunctionCall(std::get<LangAPI::FunctionCall>(part));
        }
    }
    return res;
}
auto Core::convertIspaLibSymbol(const LangAPI::IspaLibSymbol &symbol) -> std::string {
    switch (symbol.exports) {
        case LangAPI::StdlibExports::Node:
            return std::string("::ISPA_STD::Node<") + convertTemplates(symbol.template_parameters) + ">";
        case LangAPI::StdlibExports::Lexer:
            return "::ISPA_STD::Lexer_base<Tokens>";
        case LangAPI::StdlibExports::Parser:
            return "::ISPA_STD::LLParser_base<Tokens, Rules>";
        case LangAPI::StdlibExports::DfaCharTransition:
            return "::ISPA_STD::DFAAPI::CharTransition";
        case LangAPI::StdlibExports::DfaCharTableTransition:
            return "::ISPA_STD::DFAAPI::CharTableTransition<Tokens, " + convertTemplates(symbol.template_parameters) + ">";
        case LangAPI::StdlibExports::DfaTokenTransition:
            return "::ISPA_STD::DFAAPI::TokenTransition<Tokens>";
        case LangAPI::StdlibExports::DfaMultiTransition:
            return "::ISPA_STD::DFAAPI::MultiTableTransition<Tokens, " + convertTemplates(symbol.template_parameters) + ">";
        case LangAPI::StdlibExports::DfaCharState:
            return "::ISPA_STD::DFAAPI::CharState<" + convertTemplates(symbol.template_parameters) + ">";
        case LangAPI::StdlibExports::DfaCharTableState:
            return "::ISPA_STD::DFAAPI::CharTableState<Tokens, " + convertTemplates(symbol.template_parameters) + ">";
        case LangAPI::StdlibExports::DfaTokenState:
            return "::ISPA_STD::DFAAPI::TokenTableState<Tokens, " + convertTemplates(symbol.template_parameters) + ">";
        case LangAPI::StdlibExports::DfaMultiTableState:
            return "::ISPA_STD::DFAAPI::MultiTableState<Tokens, " + convertTemplates(symbol.template_parameters) + ">";
        case LangAPI::StdlibExports::DfaCharEmptyState:
            // CharEmptyState requires <Tokens, ReturnType>
            // ReturnType is provided via template_parameters
            return "::ISPA_STD::DFAAPI::CharEmptyState<Tokens, " + convertTemplates(symbol.template_parameters) + ">";
        case LangAPI::StdlibExports::DfaMultiTableEmptyState:
            return "::ISPA_STD::DFAAPI::MultiTableEmptyState<Tokens, " + convertTemplates(symbol.template_parameters) + ">";
        case LangAPI::StdlibExports::DfaCharTable:
            return "::ISPA_STD::DFAAPI::CharTable<Tokens, " + convertTemplates(symbol.template_parameters) + ">";
        case LangAPI::StdlibExports::DfaTokenTable:
            return "::ISPA_STD::DFAAPI::TokenTable<Tokens, " + convertTemplates(symbol.template_parameters) + ">";
        case LangAPI::StdlibExports::DfaMultiTable:
            return "::ISPA_STD::DFAAPI::MultiTable<Tokens, " + convertTemplates(symbol.template_parameters) + ">";
        case LangAPI::StdlibExports::DfaSpanMultiTableState:
            return "::ISPA_STD::DFAAPI::SpanMultiTableState<Tokens, " + convertTemplates(symbol.template_parameters) + ">";
        case LangAPI::StdlibExports::DfaSpanCharTableState:
            // SpanCharTableState<Tokens, ReturnType>
            return "::ISPA_STD::DFAAPI::SpanCharTableState<Tokens, " + convertTemplates(symbol.template_parameters) + ">";
        case LangAPI::StdlibExports::DfaSpanTokenTableState:
            return "::ISPA_STD::DFAAPI::SpanTokenTableState<Tokens, " + convertTemplates(symbol.template_parameters) + ">";
        case LangAPI::StdlibExports::ParserFunctionParameter:
            return "Iterator";
        case LangAPI::StdlibExports::DfaCharTableEmptyStateLambdaParameter:
            return "::ISPA_STD::DFAAPI::CharTableDataVector";
        case LangAPI::StdlibExports::DfaMultiTableEmptyStateLambdaParameter:
            return "::ISPA_STD::DFAAPI::MultiTableDataVector<" + convertTemplates(symbol.template_parameters) + ">";
        case LangAPI::StdlibExports::DfaEmptyStateGroupBegin:
            return "::ISPA_STD::DFAAPI::GroupBegin";
        case LangAPI::StdlibExports::DfaEmptyStateMemberBegin:
            return "::ISPA_STD::DFAAPI::MemberBegin";
        case LangAPI::StdlibExports::DfaCstStore:
            return "::ISPA_STD::DFAAPI::cst_store";
        case LangAPI::StdlibExports::DfaCstGroupStore:
            return "::ISPA_STD::DFAAPI::cst_group_store";
        default:
            throw Error("Unknown IspaLibSymbol exports: {}", (int) symbol.exports);
    }
}

auto Core::convertExpression(const LangAPI::Expression &expression) -> std::string {
    std::ostringstream out;
    for (const auto &expr : expression) {
        switch (expr.type()) {
            case LangAPI::ExpressionValueType::Empty:
                break;
            case LangAPI::ExpressionValueType::RValue:
                out << convertRValue(expr.getRValue());
                break;
            case LangAPI::ExpressionValueType::ExpressionElement:
                out << convertExpressionElement(expr.getExpressionElement());
                break;
            case LangAPI::ExpressionValueType::FunctionCall:
                out << convertFunctionCall(expr.getFunctionCall());
                break;
            case LangAPI::ExpressionValueType::StringCompare: {
                auto compare = expr.getStringCompare();
                out << "strncmp(" << counter.back() << ", " << (compare.is_string ? std::string("\"") + compare.str.value + "\""  : std::string("'") + compare.str.value + "'");
                break;
            }
            case LangAPI::ExpressionValueType::Return:
                out << "return " << convertExpression(expr.getReturn().value);
                break;
            case LangAPI::ExpressionValueType::Break:
                out << "break";
                break;
            case LangAPI::ExpressionValueType::Continue:
                out << "continue";
                break;
            case LangAPI::ExpressionValueType::VariableAssignment: {
                const auto &var = expr.getVariableAssignment();
                std::string type;
                switch (var.type) {
                    case LangAPI::OperatorType::Assign:
                        type = "=";
                        break;
                    case LangAPI::OperatorType::Add:
                        type = "+=";
                        break;
                    case LangAPI::OperatorType::Minus:
                        type = "-=";
                        break;
                    case LangAPI::OperatorType::Multiply:
                        type = "*=";
                        break;
                    case LangAPI::OperatorType::Divide:
                        type = "/=";
                        break;
                    case LangAPI::OperatorType::Modulo:
                        type = "%=";
                        break;
                }
                out << var.name << " " << type << " " << convertExpression(var.value);
                break;
            }
            case LangAPI::ExpressionValueType::CounterIncreament:
                out << std::string("++") + counter.back();
                break;
            case LangAPI::ExpressionValueType::CounterIncreamentByLength:
                out << counter.back() + " += " + expr.getCounterIncreamentByLength().name + ".token.length()";
                break;
            case LangAPI::ExpressionValueType::ResetPosCounter:
                counter.pop_back();
                break;
            case LangAPI::ExpressionValueType::PushPosCounter: {
                const auto &a = expr.getPushPosCounter();
                out << "auto " << a.name << " = " << counter.back();
                counter.push_back(a.name);;
                break;
            }
            case LangAPI::ExpressionValueType::PopPosCounter: {
                out << counter[counter.size() - 2] + " = " << counter.back();
                counter.pop_back();
                break;
            }
            case LangAPI::ExpressionValueType::SkipSpaces:
                out << "skip_spaces(" << counter.back() << ")";
                break;
            case LangAPI::ExpressionValueType::DfaLookup: {
                const auto &lookup = expr.getDfaLookup();
                out << lookup.output_name << " = ISPA_STD::DFA<Tokens>::decide(dfa_span_"  << std::to_string(lookup.dfa_count) << ", pos, &ISPA_STD::LLParser_base<Tokens, Rules>::PANIC_MODE)";
                break;
            }
            case LangAPI::ExpressionValueType::ReportError:
                out << "[Error]";
                break;
            case LangAPI::ExpressionValueType::Lambda:
                out << convertLambda(expr.getLambda());
                break;
            case LangAPI::ExpressionValueType::IspaLibFunctionCall:
                out << convertIspaLibFunctionCall(expr.getIspaLibFunctionCall());
                break;
            default:
                throw Error("Unknown expression type");
        }
    }
    return out.str();
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
            return " && ";
        case LangAPI::ExpressionElement::Or:
            return " || ";
        case LangAPI::ExpressionElement::Not:
            return "!";
        case LangAPI::ExpressionElement::Equal:
            return " == ";
        case LangAPI::ExpressionElement::NotEqual:
            return " != ";
        case LangAPI::ExpressionElement::Higher:
            return " > ";
        case LangAPI::ExpressionElement::Lower:
            return " < ";
        case LangAPI::ExpressionElement::HigherOrEqual:
            return " >= ";
        case LangAPI::ExpressionElement::LowerOrEqual:
            return " <= ";
        case LangAPI::ExpressionElement::Add:
            return " + ";
        case LangAPI::ExpressionElement::Minus:
            return " - ";
        case LangAPI::ExpressionElement::Multiply:
            return " * ";
        case LangAPI::ExpressionElement::Divide:
            return " / ";
        case LangAPI::ExpressionElement::Modulo:
            return " % ";
        case LangAPI::ExpressionElement::PlusPlus:
            return "++";
        case LangAPI::ExpressionElement::MinusMinus:
            return "--";
        default:
            throw Error("Unknown expression element");
    }
}
auto Core::buildStatement(const LangAPI::Statement &stmt) -> void {
    if (stmt.isIf()) {
        stmts_converter->createIf(stmt.getIf().expr);
        buildStatements(stmt.getIf().stmt);
        stmts_converter->closeIf();
    } else if (stmt.isWhile()) {
        stmts_converter->createWhile(stmt.getWhile().expr);
        buildStatements(stmt.getWhile().stmt);
        stmts_converter->closeWhile();
    } else if (stmt.isDoWhile()) {
        const auto dowhile = stmt.getDoWhile();
        stmts_converter->openDoWhile();
        buildStatements(dowhile.stmt);
        stmts_converter->closeDoWhile(dowhile.expr);
    } else if (stmt.isSwitch()) {
        const auto switch_statement = stmt.getSwitch();
        stmts_converter->createSwitch(switch_statement.expression);
        for (const auto &case_statement : switch_statement.cases) {
            stmts_converter->createCase(case_statement.first);
            buildStatements(case_statement.second);
            stmts_converter->closeCase();
        }
        stmts_converter->closeSwitch();
    } else if (stmt.isExpression()) {
        stmts_converter->createExpression(stmt.getExpression());
    } else if (stmt.isVariable()) {
        stmts_converter->createVariable(stmt.getVariable());
    }
}
auto Core::buildStatements(const LangAPI::Statements &statements) -> void {
    for (const auto &stmt : statements) {
        buildStatement(stmt);
    }
}
auto Core::convertLambda(const LangAPI::Lambda &lambda) -> std::string {
    // use lower level interaction to writer to output lambda in correct place with correct indentation
    std::ostringstream out;
    out << "(";
    bool first = true;
    for (const auto &p : lambda.parameters) {
        if (!first) {
            out << ", ";
        }
        out << convertType(p.first) << ' ' << p.second;
        first = false;
    }
    out << ") {\n";
    auto prev_writer = stmts_converter->getWriter();
    stmts_converter->getWriter().increaseIndentation();
    buildStatements(lambda.statements);
    Core::symbol_path.push_back("");
    declarations_converter->closeFunction();
    const auto text = stmts_converter->getWriter().get().erase(0, prev_writer.get().size());
    out << text;
    stmts_converter->getWriter() = prev_writer;
    return out.str();
}
auto Core::convertFunctionCall(const LangAPI::FunctionCall &call) -> std::string {
    std::string str = call.name + "(";
    bool first = true;
    for (const auto &param : call.args) {
        if (!first) str += ", ";
        str += convertExpression(param);
        first = false;
    }
    str += ")";
    return str;
}
auto Core::convertIspaLibFunctionCall(const LangAPI::IspaLibFunctionCall &call) -> std::string {
    std::ostringstream out;
    out << convertIspaLibSymbol(call.symbol) << "(";
    bool first = true;
    for (const auto &param : call.args) {
        if (!first) out << ", ";
        out << convertExpression(param);
        first = false;
    }
    out << ")";
    return out.str();
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
            const auto &array = rvalue.getArray();
            std::string res;
            if (!array.template_parameters.empty()) {
                res += "std::vector<" + convertTemplates(rvalue.getArray().template_parameters) + "> ";
            }
            if (array.values.empty()) {
                // For empty arrays (including std::array with N=0), emit a simple empty initializer
                res += "{}";
            } else {
                res += "{{";
                for (const auto &el : rvalue.getArray().values) {
                    res += convertExpression(el) + ", ";
                }
                // Remove the trailing comma+space and close braces
                res.pop_back();
                res.pop_back();
                res += "}}";
            }
            return res;
        }
        case LangAPI::RValueType::FixedSizeArray: {
            const auto &array = rvalue.getFixedSizeArray();
            std::string res;
            if (!array.template_parameters.empty()) {
                res += std::string("std::array<") + convertTemplates(array.template_parameters) + "> ";
            }
            if (array.values.empty()) {
                // For empty std::array initializers print just {}
                res += "{}";
            } else {
                res += "{{";
                for (const auto &el : array.values) {
                    res += convertExpression(el) + ", ";
                }
                // Remove the trailing comma+space and close braces
                res.pop_back();
                res.pop_back();
                res += "}}";
            }
            return res;
        }
        case LangAPI::RValueType::Map: {
            const auto &map = rvalue.getMap();
            std::string res;
            if (!map.template_parameters.empty()) {
                res += "std::unordered_map<" + convertTemplates(rvalue.getMap().template_parameters) + "> ";
            }
            res +=  "{";
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
        case LangAPI::RValueType::Pos: {
            const auto &counter_data = rvalue.getPos();
            std::string res;
            if (counter_data.dereference) res += "*";
            if (counter_data.offset != 0) res += "(" + counter.back() + " + " + std::to_string(counter_data.offset) + ")";
            else                          res += counter.back();
            return res;
        }
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
            out_content << (transition.is_refferring_char_table ? "::ISPA_STD::DFAAPI::CharTableTransition<Tokens>" : convertIspaLibSymbol(transition.transition_type)) << "{ ";
            if (std::holds_alternative<char>(transition.symbol)) {
                out_content << std::string("'") << corelib::text::getEscapedAsStr(std::get<char>(transition.symbol), false) << "'";
            } else if (std::holds_alternative<std::size_t>(transition.symbol)) {
                const auto sym = std::to_string(std::get<std::size_t>(transition.symbol));
                // When referring to another DFA table as a symbol, the expected key type depends on transition kind:
                // - CharTableTransition expects Span<const variant<SpanState<CharTransition>, CharEmptyState<TOKEN_T>>> → plain ::ISPA_STD::Span{...}
                // - MultiTableTransition expects DFAAPI::SpanMultiTable<Tokens, Nodes...> → wrap span into SpanMultiTable
                if (transition.is_refferring_char_table) {
                    // Key type for CharTableTransition is SpanCharTable<Tokens>
                    out_content << "::ISPA_STD::DFAAPI::SpanCharTable<Tokens> {dfa_table_" + sym + ".data(), dfa_table_" + sym + ".size()}";
                } else {
                    // Build SpanMultiTable type using transition.transition_type template parameters (the node types)
                    out_content << "::ISPA_STD::DFAAPI::SpanMultiTable<Tokens, "
                                << convertTemplates(transition.transition_type.template_parameters)
                                << ">{ ::ISPA_STD::Span {dfa_table_" << sym << ".data(), dfa_table_" << sym << ".size()} }";
                }
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
        case LangAPI::RValueType::IspaLibDfaSpanCharState: {
            const auto &state = rvalue.getIspaLibDfaSpanCharState();
            auto number_or_null = [](std::size_t number) -> std::string {
                return number != std::numeric_limits<std::size_t>::max() ? std::to_string(number) : "ISPA_STD::DFAAPI::null_state";
            };
            std::ostringstream out_content;
            out_content << "::ISPA_STD::DFAAPI::SpanCharState {" << number_or_null(state.else_goto) << ", " << number_or_null(state.else_goto_accept) << ", "
                        << "::ISPA_STD::Span<::ISPA_STD::DFAAPI::CharTransition> {dfa_state_" << state.state_id << ".data(), dfa_state_" << state.state_id << ".size()}}";
            return out_content.str();
        }
        case LangAPI::RValueType::IspaLibDfaSpanMultiTableState: {
            const auto &state = rvalue.getIspaLibDfaSpanMultiTableState();
            auto number_or_null = [](std::size_t number) -> std::string {
                return number != std::numeric_limits<std::size_t>::max() ? std::to_string(number) : "ISPA_STD::DFAAPI::null_state";
            };
            std::ostringstream out_content;
            // Build template argument list: <Tokens[, MultiTableTransition<Tokens, ...> ...]>
            std::string tmpl = "<Tokens";
            for (const auto &sym : state.mutli_table_transitions) {
                tmpl += ", " + convertIspaLibSymbol(sym);
            }
            tmpl += ">";
            out_content << "::ISPA_STD::DFAAPI::SpanMultiTableState" << tmpl << " {" << number_or_null(state.else_goto) << ", " << number_or_null(state.else_goto_accept) << ", "
                        << "{dfa_state_" << state.state_id << ".data(), dfa_state_" << state.state_id << ".size()}}";
            return out_content.str();
        }
        case LangAPI::RValueType::IspaLibDfaEmptyState: {
            const auto &state = rvalue.getIspaLibDfaEmptyState();
            return "{ Tokens::" + corelib::text::join(state.token_name, "_") + ", " + convertLambda(*state.construction_lambda) + " }";
        }
        case LangAPI::RValueType::Reference:
            return "&" + convertRValue(*rvalue.getReference().value);
        case LangAPI::RValueType::Span:
            return "::ISPA_STD::Span<" + convertType(*rvalue.getSpan().type) + "> { " + convertSymbol(rvalue.getSpan().sym) + ".data(), " + convertSymbol(rvalue.getSpan().sym) + ".size() }";
        default:
            throw Error("Unknown RValue type: {}", (int) rvalue.type());
    }
}