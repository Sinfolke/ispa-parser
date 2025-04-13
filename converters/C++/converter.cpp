#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <any>
#include <typeinfo>
#include <unordered_map>
#include <iomanip>
#include <stack>
#include <IR/IR.h>
#include <logging.h>
#include <converter.h>
#include <logging.h>
static size_t count_strlen(const char* str) {
    size_t count = 0;
    for (const char* pos = str; *pos; pos++) {
        if (*pos == '\\' && *(pos - 1) != '\\') {
            continue;
        }
        count++;
    }
    return count;
}
static std::string format_str(std::string str) {
    std::string res;
    for (auto &c : str) {
        if (c == '"') {
            res += "\\\"";
            continue;
        }
        res += c;
    }
    return res;
}

std::string Converter::convert_var_type(LLIR::var_types type, std::vector<LLIR::var_type> data) {
    if (type == LLIR::var_types::ARRAY) {
        if (data.empty())
            data.push_back({LLIR::var_types::ANY});
        std::string t = "::" + namespace_name + "::arr_t";
        t += "<";
        t += convert_var_type(data[0].type, data[0].templ);
        t += ">";
        return t;
    } else if (type == LLIR::var_types::OBJECT) {
        if (data.size() < 1) {
            data.push_back({LLIR::var_types::ANY});
        }
        if (data.size() < 2) {
            data.push_back({LLIR::var_types::ANY});
        }
        std::string t = "::" + namespace_name + "::obj_t";
        t += "<";
        t += convert_var_type(data[0].type, data[0].templ);
        t += ", ";
        t += convert_var_type(data[1].type, data[1].templ);
        t += ">";
        return t;
    }
    static const std::unordered_map<LLIR::var_types, std::string> typesMap = {
        {LLIR::var_types::UNDEFINED, "UNDEF"}, {LLIR::var_types::BOOLEAN, "bool_t"}, 
        {LLIR::var_types::STRING, "str_t"}, {LLIR::var_types::NUMBER, "num_t"},
        {LLIR::var_types::FUNCTION, "function"},
        {LLIR::var_types::ANY, "any_t"}, {LLIR::var_types::Rule, "Rule"}, {LLIR::var_types::Token, "Token"},
        {LLIR::var_types::Rule_result, "Rule_res"}, {LLIR::var_types::Token_result, "Token_res"},
        {LLIR::var_types::CHAR, "char"}, {LLIR::var_types::UCHAR, "unsigned char"}, 
        {LLIR::var_types::SHORT, "short"}, {LLIR::var_types::USHORT, "unsigned short"},
        {LLIR::var_types::INT, "int"}, {LLIR::var_types::UINT, "unsigned int"},
        {LLIR::var_types::LONG, "long"}, {LLIR::var_types::ULONG, "unsigned long"},
        {LLIR::var_types::LONGLONG, "long long"}, {LLIR::var_types::ULONGLONG, "unsigned long long"}
    };
    if (type < LLIR::var_types::CHAR)
        return "::" + namespace_name + "::" + typesMap.at(type);
    else
        return typesMap.at(type);
}


std::string Converter::convert_var_assing_values(LLIR::var_assign_values value, std::any data) {
    switch (value) {
        case LLIR::var_assign_values::STRING:
            //cpuf::printf("on String\n");
            return std::string(1, '"') + format_str(std::any_cast<std::string>(data)) + std::string(1, '"');
        case LLIR::var_assign_values::VAR_REFER:
        {
            //cpuf::printf("ON var_refer\n");
            auto dt = std::any_cast<LLIR::var_refer>(data);
            std::string res;
            if (dt.pre_increament)
                res += "++";
            res += dt.name;
            if (dt.post_increament)
                res += "++";
            return res;
        }
        case LLIR::var_assign_values::VARIABLE:
        {
            //cpuf::printf("on ID\n");
            auto dt = std::any_cast<LLIR::variable>(data);
            std::string res = dt.name;
            for (auto el : dt.property_access)
                res += "." + el;
            return res;
        }
        case LLIR::var_assign_values::INT:
            //cpuf::printf("on INT\n");
            return std::any_cast<std::string>(data);
        case LLIR::var_assign_values::ARRAY:
        {
            //cpuf::printf("on array\n");
            auto arr = std::any_cast<LLIR::array>(data);
            std::string res = "{";
            for (auto &el : arr) {
                res += convertAssign(el);
                res += ',';
            }
            if (res.size() > 1)
                res.back() = '}';
            else
                res += '}';
            return res;
        }
        case LLIR::var_assign_values::OBJECT:
        {
            //cpuf::printf("on object\n");
            auto obj = std::any_cast<LLIR::object>(data);
            std::string res = "{";
            for (auto [key, value] : obj) {
                res += "{";
                res += key;
                res += ", ";
                res += convertAssign(value);
                res += "},";
            }
            if (res.size() > 1) {
                res.back() = '}';
            } else {
                res += '}';
            }
            return res;
        }
        case LLIR::var_assign_values::ACCESSOR: 
            //cpuf::printf("accessor\n");
            return "";
            throw Error("Accessor cannot be here\n");
        case LLIR::var_assign_values::FUNCTION_CALL:
            return convertFunctionCall(std::any_cast<LLIR::function_call>(data));
        case LLIR::var_assign_values::EXPR:
            //cpuf::printf("On expr\n");
            return convertExpression(std::any_cast<std::vector<LLIR::expr>>(data), false);
        case LLIR::var_assign_values::CURRENT_POS:
        {
            auto dt = std::any_cast<double>(data);
            char sign = dt >= 0 ? '+' : '-';
            dt = std::abs(dt);
            if (dt == 0)
                return current_pos_counter.top();
            return current_pos_counter.top() + sign + std::to_string((int) dt);
        }
    }
    switch (value) {
        case LLIR::var_assign_values::NONE:
            return "NONE";
        case LLIR::var_assign_values::_TRUE:
            return "true";
        case LLIR::var_assign_values::_FALSE:
            return "false";
        case LLIR::var_assign_values::CURRENT_POS_COUNTER:
            return current_pos_counter.top();
        case LLIR::var_assign_values::CURRENT_POS_SEQUENCE:
        {
            std::string count_str = std::to_string(pos_counter_stack.top() + 1);
            if (dynamic_pos_counter.size()) {
                for (auto el : dynamic_pos_counter)
                    count_str += " + " + el;
            }
            dynamic_pos_counter = {};
            return "::" + namespace_name + "::str_t(" + current_pos_counter.top() + ", " + count_str + ")";
        }
        case LLIR::var_assign_values::CURRENT_TOKEN:
            return "*" + current_pos_counter.top();
        case LLIR::var_assign_values::TOKEN_SEQUENCE:
            return current_pos_counter.top();
        default:
            return "NONE";
    }
}

std::string Converter::convert_var_assing_types(LLIR::var_assign_types value) {
    switch (value) {
        case LLIR::var_assign_types::ASSIGN:    return "=";
        case LLIR::var_assign_types::ADD:       return "+=";
        case LLIR::var_assign_types::SUBSTR:    return "-=";
        case LLIR::var_assign_types::MULTIPLY:  return "*=";
        case LLIR::var_assign_types::DIVIDE:    return "/=";
        case LLIR::var_assign_types::MODULO:    return "%=";
        default: return "="; // Handle unknown values
    }
}

std::string Converter::conditionTypesToString(LLIR::condition_types type, std::any data) {
    if (type == LLIR::condition_types::CHARACTER) {
        //cpuf::printf("character\n");
        return std::string("'") + corelib::text::getCharFromEscaped(std::any_cast<char>(data), false) + std::string("'");
    } else if (type == LLIR::condition_types::CURRENT_CHARACTER) {
        //cpuf::printf("current_character\n");
        return "*(" + current_pos_counter.top() + " + " + std::to_string(pos_counter) + ")";
    } else if (type == LLIR::condition_types::NUMBER) {
        //cpuf::printf("number\n");    
        return std::to_string(std::any_cast<long long>(data));
    } else if (type == LLIR::condition_types::STRING) {
        //cpuf::printf("string\n");
        return std::string(1, '"') + std::any_cast<std::string>(data) + std::string(1, '"');
    } else if (type == LLIR::condition_types::STRNCMP) {
        //cpuf::printf("strncmp\n");
        auto dt = std::any_cast<LLIR::strncmp>(data);
        std::string val;
        if (dt.is_string) {
            val = std::string("!std::strncmp(" + current_pos_counter.top() + " + " +  std::to_string(pos_counter) + ", \"") + format_str(dt.value.name) + std::string("\", ") + std::to_string(count_strlen(dt.value.name.c_str())) + ")";
            pos_counter += count_strlen(dt.value.name.c_str()) - 1;
        } else {
            dynamic_pos_counter.push_back("strlen(" + dt.value.name + ")");
            val = std::string("!std::strncmp(" + current_pos_counter.top() + " + " + std::to_string(pos_counter) + ", ") + format_str(dt.value.name) + ", strlen(" + dt.value.name + "))";
        }
        return val;
    } else if (type == LLIR::condition_types::STRNCMP_PREV) {
        //cpuf::printf("strncmp\n");
        auto dt = std::any_cast<LLIR::strncmp>(data);
        std::string val;
        if (dt.is_string) {
            val = std::string("!std::strncmp(" + current_pos_counter.top() + ", \"") + format_str(dt.value.name) + std::string("\", ") + std::to_string(count_strlen(dt.value.name.c_str())) + ")";
            pos_counter += count_strlen(dt.value.name.c_str()) - 1;
        } else {
            dynamic_pos_counter.push_back("strlen(" + dt.value.name + ")");
            val = std::string("!std::strncmp(" + current_pos_counter.top() + ", ") + format_str(dt.value.name) + ", strlen(" + dt.value.name + "))";
        }
        return val;
    } else if (type == LLIR::condition_types::VARIABLE) {
        //cpuf::printf("variable\n");   
        auto dt = std::any_cast<LLIR::variable>(data);
        std::string res = dt.name;
        for (auto el : dt.property_access)
            res += "." + el;
        return res;
    } else if (type == LLIR::condition_types::SUCCESS_CHECK) {
        //cpuf::printf("success_check\n");
        return std::any_cast<std::string>(data) + ".status";
    } else if (type == LLIR::condition_types::HEX) {
        //cpuf::printf("hex\n");
        return std::string("0x") + std::any_cast<std::string>(data);
    } else if (type == LLIR::condition_types::ANY_DATA) {
        auto dt = std::any_cast<LLIR::assign>(data);
        return convert_var_assing_values(dt.kind, dt.data);
    } else if (type == LLIR::condition_types::METHOD_CALL) {
        return convertMethodCall(std::any_cast<LLIR::method_call>(data));
    } else if (type == LLIR::condition_types::FUNCTION_CALL) {
        return convertFunctionCall( std::any_cast<LLIR::function_call>(data));
    } else if (type == LLIR::condition_types::CURRENT_TOKEN) {
        pos_counter++;
        if (data.has_value()) {
            auto dt = std::any_cast<LLIR::current_token>(data);
            auto op = conditionTypesToString(dt.op, std::any());
            return current_pos_counter.top() + "->name() " + op + " " + "Tokens::" + dt.name;
        } else {
            return "*" + current_pos_counter.top();
        }
    }
    static const std::unordered_map<LLIR::condition_types, std::string> condTypesMap = {
        {LLIR::condition_types::GROUP_OPEN, "("}, {LLIR::condition_types::GROUP_CLOSE, ")"},
        {LLIR::condition_types::AND, "&&"}, {LLIR::condition_types::OR, "||"}, {LLIR::condition_types::NOT, "!"},
        {LLIR::condition_types::EQUAL, "=="}, {LLIR::condition_types::NOT_EQUAL, "!="},
        {LLIR::condition_types::HIGHER, ">"}, {LLIR::condition_types::LOWER, "<"},
        {LLIR::condition_types::HIGHER_OR_EQUAL, ">="}, {LLIR::condition_types::LOWER_OR_EQUAL, "<="},
        {LLIR::condition_types::LEFT_BITWISE, "<<"}, {LLIR::condition_types::RIGHT_BITWISE, ">>"},
        {LLIR::condition_types::BITWISE_AND, "&"}, {LLIR::condition_types::BITWISE_ANDR, "^"},
        {LLIR::condition_types::ADD, "+"}, {LLIR::condition_types::SUBSTR, "-"},
        {LLIR::condition_types::MULTIPLY, "*"}, {LLIR::condition_types::DIVIDE, "/"},
        {LLIR::condition_types::MODULO, "%"}, 
    };
    return condTypesMap.at(type);
}
std::string Converter::convertFunctionCall(LLIR::function_call call) {
    std::string res = call.name + "(";
    bool first = true;
    for (auto param : call.params) {
        if (!first)
            res += ", ";
        res += convertAssign(param);
        first = false;
    }
    res += ')';
    return res;
}
std::string Converter::convertAssign(LLIR::assign asgn) {
    if (asgn.kind == LLIR::var_assign_values::FUNCTION_CALL)
        return convertFunctionCall(std::any_cast<LLIR::function_call>(asgn.data));
    return convert_var_assing_values(asgn.kind, asgn.data);
}
void Converter::convertVariable(LLIR::variable var, std::ostringstream &out) {
    out << convert_var_type(var.type.type, var.type.templ) << " " << var.name;
    if (var.value.kind != LLIR::var_assign_values::NONE)
        out << " = " << convertAssign(var.value);
    out << ';';
}

std::string Converter::convertExpression(std::vector<LLIR::expr> expression, bool with_braces) {
    std::string result;
    pos_counter = 0;
    if (with_braces)
        result += '(';
    for (int i = 0; i < expression.size(); i++) {
        LLIR::expr current = expression[i];
        if (
            current.id == LLIR::condition_types::AND || 
            current.id == LLIR::condition_types::OR || 
            current.id == LLIR::condition_types::EQUAL ||
            current.id == LLIR::condition_types::NOT_EQUAL
            ) {
            result += ' ';
            result += conditionTypesToString(current.id, current.value);
            result += ' ';
        } else {
            result += conditionTypesToString(current.id, current.value);
        }
    }
    if (with_braces)
        result += ")\n";
    pos_counter_stack.push(pos_counter);
    pos_counter = 0;
    return result;
}
void Converter::convertBlock(std::vector<LLIR::member> block, std::ostringstream &out) {
    out << std::string(indentLevel, '\t') << "{\n";
    indentLevel++;
    convertMembers(block, out);
    indentLevel--;
    out << std::string(indentLevel, '\t') << "}";
}
void Converter::convertCondition(LLIR::condition cond, std::ostringstream &out) {
    out << convertExpression(cond.expression, true);
    convertBlock(cond.block, out);
    if (!cond.else_block.empty()) {
        out << "\n" << std::string(indentLevel, '\t') << "else \n";
        convertBlock(cond.else_block, out);
    }
}


void Converter::convertAssignVariable(LLIR::variable_assign var, std::ostringstream &out) {
    out << var.name << " " << convert_var_assing_types(var.assign_type) << " " << convertAssign(var.value);
}

std::string Converter::convertMethodCall(LLIR::method_call method) {
    // Implement method call conversion with proper indentation
    std::string res = method.var_name;
    for (auto call : method.calls) {
        res += '.';
        if (call.name == "push")
            call.name = "push_back";

        res += convertFunctionCall(call);
    }
    return res;
}

std::string Converter::convertDataBlock(LLIR::data_block dtb) {
    // Implement method call conversion with proper indentation
    std::string res;
    res += "Types::" + rule_prev_name_str + "_data data";
    if (dtb.is_inclosed_map) {
        res += ";";
        res += "\n";
        for (auto [key, value] : std::any_cast<LLIR::inclosed_map>(dtb.value.data)) {
            res += std::string(indentLevel, '\t') + "data." + key + " = " + convertExpression(value.first, false) + ";\n";
        }
        add_semicolon = false;
    } else {
        res += " = ";
        res += convertAssign(std::any_cast<LLIR::assign>(dtb.value));
        res += ";";
    }
    return res;
}

void Converter::convertMember(const LLIR::member& mem, std::ostringstream &out) {
    if (mem.type != LLIR::types::RULE_END)
        out << std::string(indentLevel, '\t');
    switch (mem.type)
    {
    case LLIR::types::RULE:
        has_data_block = false;
        rule_prev_name = std::any_cast<std::pair<std::string, std::vector<std::string>>>(mem.value);
        rule_prev_name_str = corelib::text::join(rule_prev_name.second, "_");
        out << namespace_name << "::Rule_res " << namespace_name << "::Parser::" << rule_prev_name_str << "(::" << namespace_name << "::TokenFlow::iterator pos) {\n";
        out << "\tauto in = pos;" ;
        indentLevel++;
        isToken = false;
        break;
    case LLIR::types::TOKEN:
        has_data_block = false;
        rule_prev_name = std::any_cast<std::pair<std::string, std::vector<std::string>>>(mem.value);
        rule_prev_name_str = corelib::text::join(rule_prev_name.second, "_");
        out << namespace_name << "::Token_res " << namespace_name << "::Lexer::" << rule_prev_name_str << "(const char* pos) {\n";
        out << "\tauto in = pos";
        indentLevel++;
        isToken = true;
        break;
    case LLIR::types::RULE_END:
        if (isToken) {
            out << "\treturn {true, ::" << namespace_name << "::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), Tokens::" << rule_prev_name_str;
            if (has_data_block)
                out << ", data";
            out << ")};\n";
        } else {
            out << "\treturn {true, ::" << namespace_name << "::Rule(in->startpos(), in->start(), pos->end(), std::distance(in, pos), pos->line(), pos->column(), Rules::" << rule_prev_name_str;
            if (has_data_block)
                out << ", data";
            out << ")};\n";
        }

        out << "}";
        indentLevel--;
        break;
    case LLIR::types::VARIABLE:
        convertVariable(std::any_cast<LLIR::variable>(mem.value), out);
        break;
    case LLIR::types::METHOD_CALL:
        out << convertMethodCall(std::any_cast<LLIR::method_call>(mem.value));
        break;
    case LLIR::types::IF:
        out << "if ";
        convertCondition(std::any_cast<LLIR::condition>(mem.value), out);
        break;
    case LLIR::types::WHILE:
        out << "while ";
        convertCondition(std::any_cast<LLIR::condition>(mem.value), out);
        break;
    case LLIR::types::DOWHILE:
        out << "do\n";
        convertBlock(std::any_cast<LLIR::condition>(mem.value).block, out);
        out << '\n' << std::string(indentLevel, '\t') << "while";
        out << convertExpression(std::any_cast<LLIR::condition>(mem.value).expression, true);
        break;
    case LLIR::types::INCREASE_POS_COUNTER:
        if (isToken) {
            out << current_pos_counter.top() << " += " + std::to_string(pos_counter_stack.top() + 1);
        } else {
            if (pos_counter_stack.top() == 1)
                out << current_pos_counter.top() << "++";
            else
                out << "std::advance(" << current_pos_counter.top() << ", " << pos_counter_stack.top() + 1 << ")";
        }
        pos_counter_stack.pop();
        break;
    case LLIR::types::INCREASE_POS_COUNTER_BY_TOKEN_LENGTH: {
        auto var = std::any_cast<std::string>(mem.value);
        if (isToken) {
            out << current_pos_counter.top() << " += " + var + ".node.length()";
        } else {
            out << "std::advance(" << current_pos_counter.top() << ", " << var << ".node.length())";
        }
        break;
    }
    case LLIR::types::RESET_POS_COUNTER:
        pos_counter_stack.pop();
        break;
    case LLIR::types::ACCESSOR:
        throw Error("Accessor cannot be here\n");
    case LLIR::types::ASSIGN_VARIABLE:
        convertAssignVariable(std::any_cast<LLIR::variable_assign>(mem.value), out);
        break;
    case LLIR::types::BREAK_LOOP:
        out << "break";
        break;
    case LLIR::types::CONTINUE_LOOP:
        out << "continue";
        break;
    case LLIR::types::EXIT:
        out << "return {};";
        break;
    case LLIR::types::ERR:
        out << "reportError(pos, \"";
        for (auto &c : std::any_cast<std::string>(mem.value)) {
            out << corelib::text::getCharFromEscapedAsStr(c, true);
        }
        out << "\");";
        break;
    case LLIR::types::SKIP_SPACES:
        if (isToken)            
            out << "skip_spaces(" << current_pos_counter.top() << ")";
        else
            out << "skip_spaces<::" << namespace_name << "::TokenFlow::iterator, ::" << namespace_name << "::Tokens>(pos)";
        break;
    case LLIR::types::DATA_BLOCK:
        has_data_block = true;
        out << convertDataBlock(std::any_cast<LLIR::data_block>(mem.value));
        break;
    case LLIR::types::PUSH_POS_COUNTER: {
        out << "auto " << std::any_cast<std::string>(mem.value) << " = " << current_pos_counter.top();
        current_pos_counter.push(std::any_cast<std::string>(mem.value));
        break;
    }
    case LLIR::types::POP_POS_COUNTER: {
        auto el = current_pos_counter.top();
        current_pos_counter.pop();
        out << current_pos_counter.top() << " = " << el;
        break;
    }
    default:
        throw Error("Undefined IR member\n");
    }
    auto back = out.str().back();
    if (back != '{' && back != '}' && back != ';' && add_semicolon)
        out << ";";
    out << "\n";
    add_semicolon = true;
}

void Converter::convertMembers(const std::vector<LLIR::member> &members, std::ostringstream &out) {
    for (auto mem : members)
        convertMember(mem, out);
}
void Converter::convertLexerCode(const std::vector<LLIR::member> &members, std::ostringstream &out) {
    isToken = true;
    if (!members.empty()) {
        for (auto it = members.begin() + 1; it != members.end() - 1; it++) {
            auto mem = *it;
            convertMember(mem, out);
        }
    }
    isToken = false;
}
void Converter::printIR(std::ostringstream &out) {
    addHeader(out);
    addStandardFunctionsLexer(out);
    addStandardFunctionsParser(out);
    addTokensToString(tokens, out);
    addRulesToString(rules, out);
    addGetFunctions(out, data_block_tokens, data_block_rules);
    addLexerCode_Header(out);
    current_pos_counter.push("pos");
    convertLexerCode(lexer_code.getDataRef(), out);
    addLexerCode_Bottom(out,  lexer_code_access_var.var);
    convertMembers(data, out);
}
void Converter::addHeader(std::ostringstream &out) {
    out << "#include \"" << std::any_cast<std::string>(use["name"].data) << ".h\"\n";
}
void Converter::addTokensToString(std::vector<std::string> tokens, std::ostringstream &out) {
    // Implement method call conversion with proper indentation
    out << "std::string " << namespace_name << "::TokensToString(Tokens token) {\n";
    out << "\tswitch (token) {\n";
    out << "\t\tcase Tokens::NONE:" << " return \"NONE\";\n";
    for (auto token : tokens) {
        out << "\t\tcase Tokens::" << token << ":" << " return \"" << token << "\";\n";
    }
    out << "\t}\n";
    out << "\treturn \"NONE\";\n";
    out << "}\n";
}
void Converter::addRulesToString(std::vector<std::string> rules, std::ostringstream &out) {
    // Implement method call conversion with proper indentation
    out << "std::string " << namespace_name << "::RulesToString(Rules rule) {\n";
    out << "\tswitch (rule) {\n";
    out << "\t\tcase Rules::NONE:" << " return \"NONE\";\n";
    for (auto rule : rules) {
        out << "\t\tcase Rules::" << rule << ":" << " return \"" << rule << "\";\n";
    }
    out << "\t}\n";
    out << "\treturn \"NONE\";\n";
    out << "}\n";
}
void Converter::addStandardFunctionsLexer(std::ostringstream &out) {
    out << "void " + namespace_name + R"(::Lexer::printTokens(std::ostream& os) {
    for (const auto& token : tokens)
        printToken(os, token);
})";
    out << '\n' << "void " + namespace_name + R"(::Lexer::printToken(std::ostream& os, const Token& token) {
    os << TokensToString(token.name()) << ": ";

    if (token.data().type() == typeid(str_t)) {
        os << '"' << std::any_cast<str_t>(token.data()) << '"';
    } else if (token.data().type() == typeid(num_t)) {
        os << std::any_cast<num_t>(token.data());
    } else if (token.data().type() == typeid(bool_t)) {
        os << std::boolalpha << std::any_cast<bool_t>(token.data());
    } else if (token.data().type() == typeid(Token)) {
        os << "{ ";
        printToken(os, std::any_cast<Token>(token.data())); // Recursive call
        os << " }";
    } else if (token.data().type() == typeid(arr_t<Token>)) { // Handle array of tokens
        os << "[ ";
        auto arr = std::any_cast<arr_t<Token>>(token.data());
        for (auto it = arr.begin(); it != arr.end(); ++it) {
            printToken(os, *it);
            if (std::next(it) != arr.end()) os << ", ";
        }
        os << " ]";
    } else if (token.data().type() == typeid(arr_t<str_t>)) {
        os << "[ ";
        auto arr = std::any_cast<arr_t<str_t>>(token.data());
        for (auto it = arr.begin(); it != arr.end(); ++it) {
            os << '"' << *it << '"';
            if (std::next(it) != arr.end()) os << ", ";
        }
        os << " ]";
    } else if (token.data().type() == typeid(arr_t<num_t>)) {
        os << "[ ";
        auto arr = std::any_cast<arr_t<num_t>>(token.data());
        for (auto it = arr.begin(); it != arr.end(); ++it) {
            os << *it;
            if (std::next(it) != arr.end()) os << ", ";
        }
        os << " ]";
    } else if (token.data().type() == typeid(arr_t<bool_t>)) {
        os << "[ ";
        auto arr = std::any_cast<arr_t<bool_t>>(token.data());
        for (auto it = arr.begin(); it != arr.end(); ++it) {
            os << std::boolalpha << *it;
            if (std::next(it) != arr.end()) os << ", ";
        }
        os << " ]";
    }
    os << " # " << token.startpos();
    os << '\n';
})";
    out << "\n";
}
void Converter::addStandardFunctionsParser(std::ostringstream &out) {
    out << namespace_name <<  "::Rule_res " << namespace_name << R"(::Parser::getRule() {
    return main(pos);
})";
    out << '\n';
//     out << "void " << namespace_name << R"(::Parser::parseFromInput() {
//         Lexer lexer;

//         if (parallel_parsing) {
//             TokenFlow tokens;
//             std::mutex mtx;
//             std::condition_variable cv;
//             bool done = false;

//             // Token accumulation thread
//             std::future<void> token_future = std::async(std::launch::async, [&]() {
//                 while (true) {
//                     auto token = lexer.makeToken(input);  // Generate one token
//                     if (token.empty()) {
//                         // parsing has finished
//                         std::lock_guard<std::mutex> lock(mtx);
//                         done = true;
//                         cv.notify_one();
//                         return;
//                     }
//                     input += token.length();
//                     {
//                         std::lock_guard<std::mutex> lock(mtx);
//                         tokens.push_back(token);
//                     }
//                     // notify new token added
//                     cv.notify_one();
//                 }
//             });

//             // Parsing loop
//             while (true) {
//                 std::unique_lock<std::mutex> lock(mtx);
//                 cv.wait(lock, [&]() { return !tokens.empty() || done; });

//                 if (tokens.empty() && done) break; // no tokens anymore and lexical analyzation has finished

//                 auto rule_res = getRule();
//                 if (rule_res.status) {
//                     // push parsed rule to tree
//                     tree.push_back(rule_res.node);
//                     tokens.erase(tokens.begin(), std::next(tokens.begin(), rule_res.node.length()));
//                 }
//             }

//             // Ensure token accamulation is completed
//             token_future.get();
//         } else {
//             // single thread parsing
//             TokenFlow tokens;
//             while (true) {
//                 // Accumulate tokens (at least 10) before parsing
//                 for (int i = 0; i < 10; i++) {
//                     auto token = lexer.makeToken(input);  // Generate one token
//                     if (token.empty()) break;
//                     tokens.push_back(token);
//                 }
//                 if (tokens.empty()) return; // parsing has finished

//                 // parse the tokens and consume used one
//                 pos = tokens.begin();
//                 auto rule_res = getRule();
//                 if (rule_res.status) {
//                     tree.push_back(rule_res.node);
//                     tokens.erase(tokens.begin(), std::next(tokens.begin(), rule_res.node.length()));
//                 }
//             }
//         }
// })";
//     out << "\n";
}

void Converter::addGetFunctions(std::ostringstream &out, data_block_t datablocks_tokens, data_block_t datablocks_rules) {
    for (const auto &[name, dtb] : datablocks_tokens) {
        out << "::" << namespace_name << "::Types::" << name << "_data " << namespace_name << "::get::" << name << "(::" << namespace_name << "::Token &token) {\n";
        out << "\treturn std::any_cast<Types::" << name << "_data>(token.data());";
        out << "\n}\n";
    }
    for (const auto &[name, dtb] : datablocks_rules) {
        out << "::" << namespace_name << "::Types::" << name << "_data " << namespace_name << "::get::" << name << "(::" << namespace_name << "::Rule &rule) {\n";
        out << "\treturn std::any_cast<Types::" << name << "_data>(rule.data());";
        out << "\n}\n";
    }
}

void Converter::addLexerCode_Header(std::ostringstream &out) {
    out << "\n" << namespace_name << "::Token " << namespace_name << "::Lexer::makeToken(const char*& pos) {\n";
    indentLevel++;
}
void Converter::addLexerCode_Bottom(std::ostringstream &out, LLIR::variable var) {
    out << "\treturn " << var.name << ";\n";
    out << "}\n";
    indentLevel--;
}
void Converter::outputIR(std::string filename) {
    namespace_name = filename;
    std::ofstream cpp(filename + ".cpp");
    std::ofstream h(filename + ".h");
    if (!cpp) {
        throw std::runtime_error("Unable to open file for writing: " + filename + ".cpp");
    }
    if (!h) {
        throw std::runtime_error("Unable to open file for writing: " + filename + ".h");
    }
    std::ostringstream cpp_ss, h_ss;
    printIR(cpp_ss);
    outputHeader(h_ss);
    cpp << cpp_ss.str();
    h << h_ss.str();
}
extern "C" Converter_base* getConverter(LLIR& ir, Tree& tree) {
    return new Converter(ir, tree);
}
// IR &ir, IR &lexer_code, IR::node_ret_t& tokenizator_access_var, std::list<std::string> tokens, std::list<std::string> rules, data_block_t datablocks_tokens, data_block_t datablocks_rules, const use_prop_t &use