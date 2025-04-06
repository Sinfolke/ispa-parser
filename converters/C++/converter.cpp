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
static std::string getCharFromEscaped(char in, bool string) {
    if (in == '"')
        return string ? "\\\"" : "\"";
    if (in == '\'')
        return string ? "'" : "\\'";
    switch (in)
    {
    case '\n': return "\\n";  // Newline
    case '\r': return "\\r";  // Carriage return
    case '\t': return "\\t";  // Horizontal tab
    case '\a': return "\\a";  // Bell (alert)
    case '\b': return "\\b";  // Backspace
    case '\f': return "\\f";  // Form feed (new page)
    case '\v': return "\\v";  // Vertical tab
    case '\\': return "\\";   // Backslash
    case '\0': return "\\0";  // end of string
    default: return std::string(1, in);      // Return the character itself if not an escape sequence
    }
}
std::string Converter::convert_var_type(IR::var_types type, std::vector<IR::var_type> data) {
    if (type == IR::var_types::ARRAY) {
        if (data.empty())
            data.push_back({IR::var_types::ANY});
        std::string t = "::" + namespace_name + "::std::vector";
        t += "<";
        t += convert_var_type(data[0].type, data[0].templ);
        t += ">";
        return t;
    } else if (type == IR::var_types::OBJECT) {
        if (data.size() < 1) {
            data.push_back({IR::var_types::ANY});
        }
        if (data.size() < 2) {
            data.push_back({IR::var_types::ANY});
        }
        std::string t = "::" + namespace_name + "::obj_t";
        t += "<";
        t += convert_var_type(data[0].type, data[0].templ);
        t += ", ";
        t += convert_var_type(data[1].type, data[1].templ);
        t += ">";
        return t;
    }
    static const std::unordered_map<IR::var_types, std::string> typesMap = {
        {IR::var_types::UNDEFINED, "UNDEF"}, {IR::var_types::BOOLEAN, "bool_t"}, 
        {IR::var_types::STRING, "str_t"}, {IR::var_types::NUMBER, "num_t"},
        {IR::var_types::FUNCTION, "function"},
        {IR::var_types::ANY, "any_t"}, {IR::var_types::Rule, "Rule"}, {IR::var_types::Token, "Token"},
        {IR::var_types::Rule_result, "Rule_res"}, {IR::var_types::Token_result, "Token_res"},
        {IR::var_types::CHAR, "char"}, {IR::var_types::UCHAR, "unsigned char"}, 
        {IR::var_types::SHORT, "short"}, {IR::var_types::USHORT, "unsigned short"},
        {IR::var_types::INT, "int"}, {IR::var_types::UINT, "unsigned int"},
        {IR::var_types::LONG, "long"}, {IR::var_types::ULONG, "unsigned long"},
        {IR::var_types::LONGLONG, "long long"}, {IR::var_types::ULONGLONG, "unsigned long long"}
    };
    if (type < IR::var_types::CHAR)
        return "::" + namespace_name + "::" + typesMap.at(type);
    else
        return typesMap.at(type);
}


std::string Converter::convert_var_assing_values(IR::var_assign_values value, std::any data) {
    switch (value) {
        case IR::var_assign_values::STRING:
            //cpuf::printf("on String\n");
            return std::string(1, '"') + format_str(std::any_cast<std::string>(data)) + std::string(1, '"');
        case IR::var_assign_values::VAR_REFER:
        {
            //cpuf::printf("ON var_refer\n");
            auto dt = std::any_cast<IR::var_refer>(data);
            std::string res;
            if (dt.pre_increament)
                res += "++";
            res += dt.name;
            if (dt.post_increament)
                res += "++";
            return res;
        }
        case IR::var_assign_values::VARIABLE:
        {
            //cpuf::printf("on ID\n");
            auto dt = std::any_cast<IR::variable>(data);
            std::string res = dt.name;
            for (auto el : dt.property_access)
                res += "." + el;
            return res;
        }
        case IR::var_assign_values::INT:
            //cpuf::printf("on INT\n");
            return std::any_cast<std::string>(data);
        case IR::var_assign_values::ARRAY:
        {
            //cpuf::printf("on array\n");
            auto arr = std::any_cast<IR::array>(data);
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
        case IR::var_assign_values::OBJECT:
        {
            //cpuf::printf("on object\n");
            auto obj = std::any_cast<IR::object>(data);
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
        case IR::var_assign_values::ACCESSOR: 
            //cpuf::printf("accessor\n");
            return "";
            throw Error("Accessor cannot be here\n");
        case IR::var_assign_values::FUNCTION_CALL:
            return convertFunctionCall(std::any_cast<IR::function_call>(data));
        case IR::var_assign_values::EXPR:
            //cpuf::printf("On expr\n");
            return convertExpression(std::any_cast<std::vector<IR::expr>>(data), false);
        case IR::var_assign_values::CURRENT_POS:
        {
            auto dt = std::any_cast<double>(data);
            char sign = dt >= 0 ? '+' : '-';
            dt = abs(dt);
            if (dt == 0)
                return current_pos_counter.top();
            return current_pos_counter.top() + sign + std::to_string((int) dt);
        }
    }
    switch (value) {
        case IR::var_assign_values::NONE:
            return "NONE";
        case IR::var_assign_values::_TRUE:
            return "true";
        case IR::var_assign_values::_FALSE:
            return "false";
        case IR::var_assign_values::CURRENT_POS_COUNTER:
            return current_pos_counter.top();
        case IR::var_assign_values::CURRENT_POS_SEQUENCE:
        {
            std::string count_str = std::to_string(pos_counter_stack.top() + 1);
            if (dynamic_pos_counter.size()) {
                for (auto el : dynamic_pos_counter)
                    count_str += " + " + el;
            }
            dynamic_pos_counter = {};
            return "::" + namespace_name + "::str_t(" + current_pos_counter.top() + ", " + count_str + ")";
        }
        case IR::var_assign_values::CURRENT_TOKEN:
            return "*" + current_pos_counter.top();
        case IR::var_assign_values::TOKEN_SEQUENCE:
            return current_pos_counter.top();
        default:
            return "NONE";
    }
}

std::string Converter::convert_var_assing_types(IR::var_assign_types value) {
    switch (value) {
        case IR::var_assign_types::ASSIGN:    return "=";
        case IR::var_assign_types::ADD:       return "+=";
        case IR::var_assign_types::SUBSTR:    return "-=";
        case IR::var_assign_types::MULTIPLY:  return "*=";
        case IR::var_assign_types::DIVIDE:    return "/=";
        case IR::var_assign_types::MODULO:    return "%=";
        default: return "="; // Handle unknown values
    }
}

std::string Converter::conditionTypesToString(IR::condition_types type, std::any data) {
    if (type == IR::condition_types::CHARACTER) {
        //cpuf::printf("character\n");
        return std::string("'") + getCharFromEscaped(std::any_cast<char>(data), false) + std::string("'");
    } else if (type == IR::condition_types::CURRENT_CHARACTER) {
        //cpuf::printf("current_character\n");
        return "*(" + current_pos_counter.top() + " + " + std::to_string(pos_counter) + ")";
    } else if (type == IR::condition_types::NUMBER) {
        //cpuf::printf("number\n");    
        return std::to_string(std::any_cast<long long>(data));
    } else if (type == IR::condition_types::STRING) {
        //cpuf::printf("string\n");
        return std::string(1, '"') + std::any_cast<std::string>(data) + std::string(1, '"');
    } else if (type == IR::condition_types::STRNCMP) {
        //cpuf::printf("strncmp\n");
        auto dt = std::any_cast<IR::strncmp>(data);
        std::string val;
        if (dt.is_string) {
            val = std::string("!std::strncmp(" + current_pos_counter.top() + " + " +  std::to_string(pos_counter) + ", \"") + format_str(dt.value.name) + std::string("\", ") + std::to_string(count_strlen(dt.value.name.c_str())) + ")";
            pos_counter += count_strlen(dt.value.name.c_str()) - 1;
        } else {
            dynamic_pos_counter.push_back("strlen(" + dt.value.name + ")");
            val = std::string("!std::strncmp(" + current_pos_counter.top() + " + " + std::to_string(pos_counter) + ", ") + format_str(dt.value.name) + ", strlen(" + dt.value.name + "))";
        }
        return val;
    } else if (type == IR::condition_types::STRNCMP_PREV) {
        //cpuf::printf("strncmp\n");
        auto dt = std::any_cast<IR::strncmp>(data);
        std::string val;
        if (dt.is_string) {
            val = std::string("!std::strncmp(" + current_pos_counter.top() + ", \"") + format_str(dt.value.name) + std::string("\", ") + std::to_string(count_strlen(dt.value.name.c_str())) + ")";
            pos_counter += count_strlen(dt.value.name.c_str()) - 1;
        } else {
            dynamic_pos_counter.push_back("strlen(" + dt.value.name + ")");
            val = std::string("!std::strncmp(" + current_pos_counter.top() + ", ") + format_str(dt.value.name) + ", strlen(" + dt.value.name + "))";
        }
        return val;
    } else if (type == IR::condition_types::VARIABLE) {
        //cpuf::printf("variable\n");   
        auto dt = std::any_cast<IR::variable>(data);
        std::string res = dt.name;
        for (auto el : dt.property_access)
            res += "." + el;
        return res;
    } else if (type == IR::condition_types::SUCCESS_CHECK) {
        //cpuf::printf("success_check\n");
        return std::any_cast<std::string>(data) + ".status";
    } else if (type == IR::condition_types::HEX) {
        //cpuf::printf("hex\n");
        return std::string("0x") + std::any_cast<std::string>(data);
    } else if (type == IR::condition_types::ANY_DATA) {
        auto dt = std::any_cast<IR::assign>(data);
        return convert_var_assing_values(dt.kind, dt.data);
    } else if (type == IR::condition_types::METHOD_CALL) {
        return convertMethodCall(std::any_cast<IR::method_call>(data));
    } else if (type == IR::condition_types::FUNCTION_CALL) {
        return convertFunctionCall( std::any_cast<IR::function_call>(data));
    } else if (type == IR::condition_types::CURRENT_TOKEN) {
        pos_counter++;
        if (data.has_value()) {
            auto dt = std::any_cast<IR::current_token>(data);
            auto op = conditionTypesToString(dt.op, std::any());
            return current_pos_counter.top() + "->name() " + op + " " + "Tokens::" + dt.name;
        } else {
            return "*" + current_pos_counter.top();
        }
    }
    static const std::unordered_map<IR::condition_types, std::string> condTypesMap = {
        {IR::condition_types::GROUP_OPEN, "("}, {IR::condition_types::GROUP_CLOSE, ")"},
        {IR::condition_types::AND, "&&"}, {IR::condition_types::OR, "||"}, {IR::condition_types::NOT, "!"},
        {IR::condition_types::EQUAL, "=="}, {IR::condition_types::NOT_EQUAL, "!="},
        {IR::condition_types::HIGHER, ">"}, {IR::condition_types::LOWER, "<"},
        {IR::condition_types::HIGHER_OR_EQUAL, ">="}, {IR::condition_types::LOWER_OR_EQUAL, "<="},
        {IR::condition_types::LEFT_BITWISE, "<<"}, {IR::condition_types::RIGHT_BITWISE, ">>"},
        {IR::condition_types::BITWISE_AND, "&"}, {IR::condition_types::BITWISE_ANDR, "^"},
        {IR::condition_types::ADD, "+"}, {IR::condition_types::SUBSTR, "-"},
        {IR::condition_types::MULTIPLY, "*"}, {IR::condition_types::DIVIDE, "/"},
        {IR::condition_types::MODULO, "%"}, 
    };
    return condTypesMap.at(type);
}
std::string Converter::convertFunctionCall(IR::function_call call) {
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
std::string Converter::convertAssign(IR::assign asgn) {
    if (asgn.kind == IR::var_assign_values::FUNCTION_CALL)
        return convertFunctionCall(std::any_cast<IR::function_call>(asgn.data));
    return convert_var_assing_values(asgn.kind, asgn.data);
}
void Converter::convertVariable(IR::variable var, std::ostringstream &out) {
    out << convert_var_type(var.type.type, var.type.templ) << " " << var.name;
    if (var.value.kind != IR::var_assign_values::NONE)
        out << " = " << convertAssign(var.value);
    out << ';';
}

std::string Converter::convertExpression(std::vector<IR::expr> expression, bool with_braces) {
    std::string result;
    pos_counter = 0;
    if (with_braces)
        result += '(';
    for (int i = 0; i < expression.size(); i++) {
        IR::expr current = expression[i];
        if (
            current.id == IR::condition_types::AND || 
            current.id == IR::condition_types::OR || 
            current.id == IR::condition_types::EQUAL ||
            current.id == IR::condition_types::NOT_EQUAL
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
void Converter::convertBlock(std::vector<IR::member> block, std::ostringstream &out) {
    out << std::string(indentLevel, '\t') << "{\n";
    indentLevel++;
    convertMembers(block, out);
    indentLevel--;
    out << std::string(indentLevel, '\t') << "}";
}
void Converter::convertCondition(IR::condition cond, std::ostringstream &out) {
    out << convertExpression(cond.expression, true);
    convertBlock(cond.block, out);
    if (!cond.else_block.empty()) {
        out << "\n" << std::string(indentLevel, '\t') << "else \n";
        convertBlock(cond.else_block, out);
    }
}


void Converter::convertAssignVariable(IR::variable_assign var, std::ostringstream &out) {
    out << var.name << " " << convert_var_assing_types(var.assign_type) << " " << convertAssign(var.value);
}

std::string Converter::convertMethodCall(IR::method_call method) {
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

std::string Converter::convertDataBlock(IR::data_block dtb) {
    // Implement method call conversion with proper indentation
    std::string res;
    res += "Types::" + rule_prev_name_str + "_data data";
    if (dtb.is_inclosed_map) {
        res += ";";
        res += "\n";
        for (auto [key, value] : std::any_cast<IR::inclosed_map>(dtb.value.data)) {
            res += std::string(indentLevel, '\t') + "data." + key + " = " + convertExpression(value.first, false) + ";\n";
        }
        add_semicolon = false;
    } else {
        res += " = ";
        res += convertAssign(std::any_cast<IR::assign>(dtb.value));
        res += ";";
    }
    return res;
}

void Converter::convertMember(const IR::member& mem, std::ostringstream &out) {
    if (mem.type != IR::types::RULE_END)
        out << std::string(indentLevel, '\t');
    switch (mem.type)
    {
    case IR::types::RULE:
        has_data_block = false;
        rule_prev_name = std::any_cast<std::pair<std::string, std::vector<std::string>>>(mem.value);
        rule_prev_name_str = corelib::text::join(rule_prev_name.second, "_");
        out << namespace_name << "::Rule_res " << namespace_name << "::Parser::" << rule_prev_name_str << "(::" << namespace_name << "::TokenFlow::iterator pos) {\n";
        out << "\tauto in = pos;" ;
        indentLevel++;
        isToken = false;
        break;
    case IR::types::TOKEN:
        has_data_block = false;
        rule_prev_name = std::any_cast<std::pair<std::string, std::vector<std::string>>>(mem.value);
        rule_prev_name_str = corelib::text::join(rule_prev_name.second, "_");
        out << namespace_name << "::Token_res " << namespace_name << "::Lexer::" << rule_prev_name_str << "(const char* pos) {\n";
        out << "\tauto in = pos";
        indentLevel++;
        isToken = true;
        break;
    case IR::types::RULE_END:
        if (isToken) {
            out << "\treturn {true, ::" << namespace_name << "::Token(getCurrentPos(in), in, pos, pos - in, Tokens::" << rule_prev_name_str;
            if (has_data_block)
                out << ", data";
            out << ")};\n";
        } else {
            out << "\treturn {true, ::" << namespace_name << "::Rule(in->startpos(), in->start(), pos->end(), std::distance(in, pos), Rules::" << rule_prev_name_str;
            if (has_data_block)
                out << ", data";
            out << ")};\n";
        }

        out << "}";
        indentLevel--;
        break;
    case IR::types::VARIABLE:
        convertVariable(std::any_cast<IR::variable>(mem.value), out);
        break;
    case IR::types::METHOD_CALL:
        out << convertMethodCall(std::any_cast<IR::method_call>(mem.value));
        break;
    case IR::types::IF:
        out << "if ";
        convertCondition(std::any_cast<IR::condition>(mem.value), out);
        break;
    case IR::types::WHILE:
        out << "while ";
        convertCondition(std::any_cast<IR::condition>(mem.value), out);
        break;
    case IR::types::DOWHILE:
        out << "do\n";
        convertBlock(std::any_cast<IR::condition>(mem.value).block, out);
        out << '\n' << std::string(indentLevel, '\t') << "while";
        out << convertExpression(std::any_cast<IR::condition>(mem.value).expression, true);
        break;
    case IR::types::INCREASE_POS_COUNTER:
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
    case IR::types::INCREASE_POS_COUNTER_BY_TOKEN_LENGTH: {
        auto var = std::any_cast<std::string>(mem.value);
        if (isToken) {
            out << current_pos_counter.top() << " += " + var + ".node.length()";
        } else {
            out << "std::advance(" << current_pos_counter.top() << ", " << var << ".node.length())";
        }
        break;
    }
    case IR::types::RESET_POS_COUNTER:
        pos_counter_stack.pop();
        break;
    case IR::types::ACCESSOR:
        throw Error("Accessor cannot be here\n");
    case IR::types::ASSIGN_VARIABLE:
        convertAssignVariable(std::any_cast<IR::variable_assign>(mem.value), out);
        break;
    case IR::types::BREAK_LOOP:
        out << "break";
        break;
    case IR::types::CONTINUE_LOOP:
        out << "continue";
        break;
    case IR::types::EXIT:
        out << "return {};";
        break;
    case IR::types::SKIP_SPACES:
        if (isToken)            
            out << "skip_spaces(" << current_pos_counter.top() << ")";
        else
            out << "skip_spaces<::" << namespace_name << "::TokenFlow::iterator, ::" << namespace_name << "::Tokens>(pos)";
        break;
    case IR::types::DATA_BLOCK:
        has_data_block = true;
        out << convertDataBlock(std::any_cast<IR::data_block>(mem.value));
        break;
    case IR::types::PUSH_POS_COUNTER: {
        out << "auto " << std::any_cast<std::string>(mem.value) << " = " << current_pos_counter.top();
        current_pos_counter.push(std::any_cast<std::string>(mem.value));
        break;
    }
    case IR::types::POP_POS_COUNTER: {
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

void Converter::convertMembers(const std::vector<IR::member> &members, std::ostringstream &out) {
    for (auto mem : members)
        convertMember(mem, out);
}
void Converter::printIR(std::ostringstream &out) {
    namespace_name = std::any_cast<std::string>(use["name"].data);

    addHeader(out);
    addStandardFunctionsLexer(out);
    addStandardFunctionsParser(out);
    addTokensToString(tokens, out);
    addRulesToString(rules, out);
    addGetFunctions(out, data_block_tokens, data_block_rules);
    addLexer_codeHeader(out);
    current_pos_counter.push("pos");
    isToken = true;
    lexer_code.pop_begin();
    lexer_code.pop();
    convertMembers(lexer_code.getDataRef(), out);
    isToken = false;
    addLexer_codeBottom(out,  lexer_code_access_var.var);
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
    out << "void " + namespace_name + R"(::Lexer::printTokens(std::ostringstream& os, bool sensitiveInfo) {
    for (const auto& token : tokens)
        printToken(os, token, sensitiveInfo);
})";
    out << '\n' << "void " + namespace_name + R"(::Lexer::printToken(std::ostringstream& os, const Token& token, bool sensitiveInfo) {
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
    } else if (token.data().type() == typeid(std::vector<Token>)) { // Handle array of tokens
        os << "[ ";
        auto arr = std::any_cast<std::vector<Token>>(token.data());
        for (auto it = arr.begin(); it != arr.end(); ++it) {
            printToken(os, *it);
            if (std::next(it) != arr.end()) os << ", ";
        }
        os << " ]";
    } else if (token.data().type() == typeid(std::vector<str_t>)) {
        os << "[ ";
        auto arr = std::any_cast<std::vector<str_t>>(token.data());
        for (auto it = arr.begin(); it != arr.end(); ++it) {
            os << '"' << *it << '"';
            if (std::next(it) != arr.end()) os << ", ";
        }
        os << " ]";
    } else if (token.data().type() == typeid(std::vector<num_t>)) {
        os << "[ ";
        auto arr = std::any_cast<std::vector<num_t>>(token.data());
        for (auto it = arr.begin(); it != arr.end(); ++it) {
            os << *it;
            if (std::next(it) != arr.end()) os << ", ";
        }
        os << " ]";
    } else if (token.data().type() == typeid(std::vector<bool_t>)) {
        os << "[ ";
        auto arr = std::any_cast<std::vector<bool_t>>(token.data());
        for (auto it = arr.begin(); it != arr.end(); ++it) {
            os << std::boolalpha << *it;
            if (std::next(it) != arr.end()) os << ", ";
        }
        os << " ]";
    }
    os << " # " << token.startpos();
    if (sensitiveInfo)
        os << ", line " << token.line() << ", pos " << token.positionInLine();
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

void Converter::addLexer_codeHeader(std::ostringstream &out) {
    out << "\n" << namespace_name << "::Token " << namespace_name << "::Lexer::makeToken(const char*& pos) {\n";
    indentLevel++;
}
void Converter::addLexer_codeBottom(std::ostringstream &out, IR::variable var) {
    out << "\treturn " << var.name << ";\n";
    out << "}\n";
    indentLevel--;
}
void Converter::outputIRToFile(std::string filename) {
    std::ostringstream ss;

    std::ofstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Unable to open file for writing: " + filename);
    }
    file << ss.str();
}
void Converter::outputIRToConsole() {
    std::ostringstream ss;
    printIR(ss);
    std::cout << ss.str() << '\n';
}
// IR &ir, IR &lexer_code, IR::node_ret_t& tokenizator_access_var, std::list<std::string> tokens, std::list<std::string> rules, data_block_t datablocks_tokens, data_block_t datablocks_rules, const use_prop_t &use