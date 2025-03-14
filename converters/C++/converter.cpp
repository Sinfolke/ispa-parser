#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <any>
#include <typeinfo>
#include <unordered_map>
#include <iomanip>
#include <stack>
#include <IR.h>
#include <logging.h>
#include <converter.h>
namespace global {
    size_t pos_counter;
    std::list<std::string> dynamic_pos_counter;
    use_prop_t use;
    std::string rule_prev_name;
    std::string namespace_name;
    bool add_semicolon;
    bool has_data_block;
    bool isToken;
}
size_t count_strlen(const char* str) {
    size_t count = 0;
    for (const char* pos = str; *pos; pos++) {
        if (*pos == '\\' && *(pos - 1) != '\\') {
            continue;
        }
        count++;
    }
    return count;
}
std::string format_str(std::string str) {
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
std::string getCharFromEscaped(char in, bool string) {
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
std::string convert_var_type(IR::var_types type, arr_t<IR::var_type> data) {
    if (type == IR::var_types::ARRAY) {
        std::string t = "::" + global::namespace_name + "::arr_t";
        t += "<";
        t += convert_var_type(data[0].type, data[0].templ);
        t += ">";
        return t;
    } else if (type == IR::var_types::OBJECT) {
        std::string t = "::" + global::namespace_name + "::obj_t";
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
        return "::" + global::namespace_name + "::" + typesMap.at(type);
    else
        return typesMap.at(type);
}


std::string convert_var_assing_values(IR::var_assign_values value, std::any data, std::stack<std::string> &current_pos_counter) {
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
                res += convertAssign(el, current_pos_counter);
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
                res += convertAssign(value, current_pos_counter);
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
            return convertFunctionCall(std::any_cast<IR::function_call>(data), current_pos_counter);
        case IR::var_assign_values::EXPR:
            //cpuf::printf("On expr\n");
            return convertExpression(std::any_cast<arr_t<IR::expr>>(data), false, current_pos_counter);
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
            std::string count_str = std::to_string(global::pos_counter);
            if (global::dynamic_pos_counter.size()) {
                for (auto el : global::dynamic_pos_counter)
                    count_str += " + " + el;
            }
            global::dynamic_pos_counter = {};
            return "::" + global::namespace_name + "::str_t(" + current_pos_counter.top() + ", " + count_str + ")";
        }
        case IR::var_assign_values::CURRENT_TOKEN:
            return "*" + current_pos_counter.top();
        case IR::var_assign_values::TOKEN_SEQUENCE:
            return current_pos_counter.top();
        default:
            return "NONE";
    }
}

std::string convert_var_assing_types(IR::var_assign_types value) {
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

std::string conditionTypesToString(IR::condition_types type, std::any data, std::stack<std::string> &current_pos_counter) {
    if (type == IR::condition_types::CHARACTER) {
        //cpuf::printf("character\n");
        return std::string("'") + getCharFromEscaped(std::any_cast<char>(data), false) + std::string("'");
    } else if (type == IR::condition_types::CURRENT_CHARACTER) {
        //cpuf::printf("current_character\n");
        return "*(pos + " + std::to_string(global::pos_counter++) + ")";
    } else if (type == IR::condition_types::PREV_CHARACTER) {
        return "*(pos + " + std::to_string(global::pos_counter - 1) + ")";
    } else if (type == IR::condition_types::NUMBER) {
        //cpuf::printf("number\n");    
        return std::to_string(std::any_cast<long long>(data));
    } else if (type == IR::condition_types::STRING) {
        //cpuf::printf("string\n");
        return std::string(1, '"') + std::any_cast<std::string>(data) + std::string(1, '"');
    } else if (type == IR::condition_types::STRNCMP) {
        //cpuf::printf("strncmp\n");
        auto dt = std::any_cast<IR::strncmp>(data);
        if (dt.is_string) {
            global::pos_counter += count_strlen(dt.value.name.c_str());
            return std::string("!std::strncmp(pos, \"") + format_str(dt.value.name) + std::string("\", ") + std::to_string(count_strlen(dt.value.name.c_str())) + ")";
        } else {
            global::dynamic_pos_counter.push_back("strlen(" + dt.value.name + ")");
            return std::string("!std::strncmp(pos, ") + format_str(dt.value.name) + ", strlen(" + dt.value.name + "))";
        }
    } else if (type == IR::condition_types::VARIABLE) {
        //cpuf::printf("variable\n");   
        auto dt = std::any_cast<IR::variable>(data);
        std::string res = dt.name;
        for (auto el : dt.property_access)
            res += "." + el;
        return res;
    } else if (type == IR::condition_types::SUCCESS_CHECK) {
        //cpuf::printf("success_check\n");
        return std::any_cast<std::string>(data) + ".result";
    } else if (type == IR::condition_types::HEX) {
        //cpuf::printf("hex\n");
        return std::string("0x") + std::any_cast<std::string>(data);
    } else if (type == IR::condition_types::ANY_DATA) {
        auto dt = std::any_cast<IR::assign>(data);
        return convert_var_assing_values(dt.kind, dt.data, current_pos_counter);
    } else if (type == IR::condition_types::METHOD_CALL) {
        return convertMethodCall(std::any_cast<IR::method_call>(data), current_pos_counter);
    } else if (type == IR::condition_types::FUNCTION_CALL) {
        return convertFunctionCall( std::any_cast<IR::function_call>(data), current_pos_counter);
    } else if (type == IR::condition_types::CURRENT_TOKEN) {
        global::pos_counter++;
        if (data.has_value()) {
            auto dt = std::any_cast<IR::current_token>(data);
            auto op = conditionTypesToString(dt.op, std::any(), current_pos_counter);
            return current_pos_counter.top() + "->name " + op + " " + "Tokens::" + dt.name;
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
std::string convertFunctionCall(IR::function_call call, std::stack<std::string> &current_pos_counter) {
    std::string res = call.name + "(";
    for (auto param : call.params) {
        res += convertAssign(param, current_pos_counter);
    }
    res += ')';
    return res;
}
std::string convertAssign(IR::assign asgn, std::stack<std::string> &current_pos_counter) {
    if (asgn.kind == IR::var_assign_values::FUNCTION_CALL)
        return convertFunctionCall(std::any_cast<IR::function_call>(asgn.data), current_pos_counter);
    return convert_var_assing_values(asgn.kind, asgn.data, current_pos_counter);
}
void convertVariable(IR::variable var, std::ostringstream &out, int &indentLevel, std::stack<std::string> &current_pos_counter) {
    out << convert_var_type(var.type.type, var.type.templ) << " " << var.name;
    if (var.value.kind != IR::var_assign_values::NONE)
        out << " = " << convertAssign(var.value, current_pos_counter);
}

std::string convertExpression(arr_t<IR::expr> expression, bool with_braces, std::stack<std::string> &current_pos_counter) {
    std::string result;
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
            result += conditionTypesToString(current.id, current.value, current_pos_counter);
            result += ' ';
        } else {
            result += conditionTypesToString(current.id, current.value, current_pos_counter);
        }
    }
    if (with_braces)
        result += ")\n";
    return result;
}

void convertBlock(arr_t<IR::member> block, std::ostringstream &out, int &indentLevel, std::stack<std::string> &current_pos_counter) {
    out << std::string(indentLevel, '\t') << "{\n";
    indentLevel++;
    convertMembers(block, out, indentLevel, current_pos_counter);
    indentLevel--;
    out << std::string(indentLevel, '\t') << "}";
}

void convertCondition(IR::condition cond, std::ostringstream &out, int &indentLevel, std::stack<std::string> &current_pos_counter) {
    out << convertExpression(cond.expression, true, current_pos_counter);
    convertBlock(cond.block, out, indentLevel, current_pos_counter);
    if (!cond.else_block.empty()) {
        out << "\n" << std::string(indentLevel, '\t') << "else \n";
        convertBlock(cond.else_block, out, indentLevel, current_pos_counter);
    }
}


void convertAssignVariable(IR::variable_assign var, std::ostream &out, int &indentLevel, std::stack<std::string> &current_pos_counter) {
    out << var.name << " " << convert_var_assing_types(var.assign_type) << " " << convertAssign(var.value, current_pos_counter);
}

std::string convertMethodCall(IR::method_call method, std::stack<std::string> &current_pos_counter) {
    // Implement method call conversion with proper indentation
    std::string res = method.var_name;
    for (auto call : method.calls) {
        res += '.';
        if (call.name == "push")
            call.name = "push_back";

        res += convertFunctionCall(call, current_pos_counter);
    }
    return res;
}

std::string convertDataBlock(IR::data_block dtb, int indentLevel, std::stack<std::string> &current_pos_counter) {
    // Implement method call conversion with proper indentation
    std::string res;
    res += global::rule_prev_name + "_data data";
    if (dtb.is_inclosed_map) {
        res += ";";
        res += "\n";
        for (auto [key, value] : std::any_cast<IR::inclosed_map>(dtb.value.data)) {
            res += std::string(indentLevel, '\t') + "data." + key + " = " + convertExpression(value.first, false, current_pos_counter) + ";\n";
        }
        global::add_semicolon = false;
    } else {
        res += " = ";
        res += convertAssign(std::any_cast<IR::assign>(dtb.value), current_pos_counter);
        res += ";";
    }
    return res;
}

void convertMember(const IR::member& mem, std::ostringstream &out, int &indentLevel, std::stack<std::string> &current_pos_counter) {
    if (mem.type != IR::types::RULE_END)
        out << std::string(indentLevel, '\t');
    global::namespace_name = std::any_cast<std::string>(global::use["name"].data);
    switch (mem.type)
    {
    case IR::types::RULE:
        global::has_data_block = false;
        global::rule_prev_name = std::any_cast<std::string>(mem.value);
        out << global::namespace_name << "::Rule_res " << global::namespace_name << "::Parser::" << std::any_cast<std::string>(mem.value) << "(Token*& pos) {\n";
        out << "\tauto in = pos" ;
        indentLevel++;
        global::isToken = false;
        break;
    case IR::types::TOKEN:
        global::has_data_block = false;
        global::rule_prev_name = std::any_cast<std::string>(mem.value);
        out << global::namespace_name << "::Token_res " << global::namespace_name << "::Tokenizator::" << std::any_cast<std::string>(mem.value) << "(const char* &pos) {\n";
        out << "\tauto in = pos";
        indentLevel++;
        global::isToken = true;
        break;
    case IR::types::RULE_END:
        if (global::has_data_block) {
            if (global::isToken) {
                out << "\treturn {true, ::" << global::namespace_name << "::Token(in - str, in, pos, Tokens::" << global::rule_prev_name;
                if (global::has_data_block)
                    out << ", data";
                out << ")};\n";
            } else {
                out << "\treturn {true, ::" << global::namespace_name << "::Rule(in->startpos, in->start, pos->end, Rules::" << global::rule_prev_name;
                if (global::has_data_block)
                    out << ", data";
                out << ")};\n";
            }
        }
        else
            out << "\treturn {};\n";
        out << "}";
        indentLevel--;
        break;
    case IR::types::VARIABLE:
        convertVariable(std::any_cast<IR::variable>(mem.value), out, indentLevel, current_pos_counter);
        break;
    case IR::types::METHOD_CALL:
        out << convertMethodCall(std::any_cast<IR::method_call>(mem.value), current_pos_counter);
        break;
    case IR::types::IF:
        out << "if ";
        convertCondition(std::any_cast<IR::condition>(mem.value), out, indentLevel, current_pos_counter);
        break;
    case IR::types::WHILE:
        out << "while ";
        convertCondition(std::any_cast<IR::condition>(mem.value), out, indentLevel, current_pos_counter);
        break;
    case IR::types::DOWHILE:
        out << "do\n";
        convertBlock(std::any_cast<IR::condition>(mem.value).block, out, indentLevel, current_pos_counter);
        out << std::string(indentLevel, '\t') << "while";
        out << convertExpression(std::any_cast<IR::condition>(mem.value).expression, true, current_pos_counter);
        break;
    case IR::types::INCREASE_POS_COUNTER:
        out << current_pos_counter.top() << " += " + std::to_string(global::pos_counter);
        global::pos_counter = 0;
        break;
    case IR::types::ACCESSOR:
        throw Error("Accessor cannot be here\n");
    case IR::types::ASSIGN_VARIABLE:
        convertAssignVariable(std::any_cast<IR::variable_assign>(mem.value), out, indentLevel, current_pos_counter);
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
        out << "skipspaces(pos)";
        break;
    case IR::types::DATA_BLOCK:
        global::has_data_block = true;
        out << convertDataBlock(std::any_cast<IR::data_block>(mem.value), indentLevel, current_pos_counter);
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
    if (back != '{' && back != '}' && back != ';' && global::add_semicolon)
        out << ";";
    out << "\n";
    global::add_semicolon = true;
}

void convertMembers(arr_t<IR::member> members, std::ostringstream &out, int &indentLevel, std::stack<std::string> &current_pos_counter) {
    for (auto mem : members)
        convertMember(mem, out, indentLevel, current_pos_counter);
}
void addHeader(std::ostringstream &out) {
    out << "#include \"" << std::any_cast<std::string>(global::use["name"].data) << ".h\"\n";
}
extern "C" std::string convert(const IR::ir &ir, const use_prop_t &use) {
    std::ostringstream ss;
    std::stack<std::string> current_pos_counter;
    int identLevel = 0;
    current_pos_counter.push("pos");
    global::use = use;
    global::pos_counter = 0;

    addHeader(ss);

    convertMembers(ir.elements, ss, identLevel, current_pos_counter);
    return ss.str();
}