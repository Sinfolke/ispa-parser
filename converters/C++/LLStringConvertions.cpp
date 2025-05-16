
#include <LLStringConvertions.h>
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
std::string LLStringConvertions::convert_var_type(const LLIR_old::var_types &type, const std::vector<LLIR_old::var_type> &data) const {
    if (type == LLIR_old::var_types::ARRAY) {
        std::vector<LLIR_old::var_type> type = data;
        if (data.empty())
            type.push_back({LLIR_old::var_types::ANY});
        std::string t = "::" + namespace_name + "::arr_t";
        t += "<";
        t += convert_var_type(type[0].type, type[0].templ);
        t += ">";
        return t;
    } else if (type == LLIR_old::var_types::OBJECT) {
        std::vector<LLIR_old::var_type> type = data;
        if (data.size() < 1) {
            type.push_back({LLIR_old::var_types::ANY});
        }
        if (data.size() < 2) {
            type.push_back({LLIR_old::var_types::ANY});
        }
        std::string t = "::" + namespace_name + "::obj_t";
        t += "<";
        t += convert_var_type(type[0].type, type[0].templ);
        t += ", ";
        t += convert_var_type(type[1].type, type[1].templ);
        t += ">";
        return t;
    }
    static const std::unordered_map<LLIR_old::var_types, std::string> typesMap = {
        {LLIR_old::var_types::UNDEFINED, "UNDEF"}, {LLIR_old::var_types::BOOLEAN, "bool_t"}, 
        {LLIR_old::var_types::STRING, "str_t"}, {LLIR_old::var_types::NUMBER, "num_t"},
        {LLIR_old::var_types::FUNCTION, "function"},
        {LLIR_old::var_types::ANY, "any_t"}, {LLIR_old::var_types::Rule, "Rule"}, {LLIR_old::var_types::Token, "Token"},
        {LLIR_old::var_types::Rule_result, "Rule_res"}, {LLIR_old::var_types::Token_result, "Token_res"},
        {LLIR_old::var_types::CHAR, "char"}, {LLIR_old::var_types::UCHAR, "unsigned char"}, 
        {LLIR_old::var_types::SHORT, "short"}, {LLIR_old::var_types::USHORT, "unsigned short"},
        {LLIR_old::var_types::INT, "int"}, {LLIR_old::var_types::UINT, "unsigned int"},
        {LLIR_old::var_types::LONG, "long"}, {LLIR_old::var_types::ULONG, "unsigned long"},
        {LLIR_old::var_types::LONGLONG, "long long"}, {LLIR_old::var_types::ULONGLONG, "unsigned long long"}
    };
    if (type < LLIR_old::var_types::CHAR)
        return "::" + namespace_name + "::" + typesMap.at(type);
    else
        return typesMap.at(type);
}


std::string LLStringConvertions::convert_var_assing_values(const LLIR_old::var_assign_values &value, const std::any &data) {
    switch (value) {
        case LLIR_old::var_assign_values::STRING:
            //cpuf::printf("on String\n");
            return std::string(1, '"') + format_str(std::any_cast<std::string>(data)) + std::string(1, '"');
        case LLIR_old::var_assign_values::VAR_REFER:
        {
            auto dt = std::any_cast<LLIR_old::var_refer>(data);
            std::string name = dt.var.name;
            for (const auto &el : dt.var.property_access)
                name += "." + el;
            if (dt.post_increament.value_or('\0') == '-') {
                name.insert(0, "--");
            } else if (dt.post_increament.value_or('\0') == '+') {
                name.insert(0, "++");
            }
            if (!dt.brace_expression.empty()) {
                name += '[' + convertExpression(dt.brace_expression, false) + ']';
            }
            if (dt.post_increament.value_or('\0') == '-') {
                name += "--";
            } else if (dt.post_increament.value_or('\0') == '+') {
                name += "++";
            }
            return name;
        }
        case LLIR_old::var_assign_values::INT:
            //cpuf::printf("on INT\n");
            return std::any_cast<std::string>(data);
        case LLIR_old::var_assign_values::ARRAY:
        {
            //cpuf::printf("on array\n");
            auto arr = std::any_cast<LLIR_old::array>(data);
            std::string res = "{";
            for (auto &el : arr) {
                res += convertExpression(el, false);
                res += ',';
            }
            if (res.size() > 1)
                res.back() = '}';
            else
                res += '}';
            return res;
        }
        case LLIR_old::var_assign_values::OBJECT:
        {
            //cpuf::printf("on object\n");
            auto obj = std::any_cast<LLIR_old::object>(data);
            std::string res = "{";
            for (auto [key, value] : obj) {
                res += "{";
                res += key;
                res += ", ";
                res += convertExpression(value, false);
                res += "},";
            }
            if (res.size() > 1) {
                res.back() = '}';
            } else {
                res += '}';
            }
            return res;
        }
        case LLIR_old::var_assign_values::ACCESSOR: 
            //cpuf::printf("accessor\n");
            return "";
            throw Error("Accessor cannot be here\n");
        case LLIR_old::var_assign_values::FUNCTION_CALL:
            return convertFunctionCall(std::any_cast<LLIR_old::function_call>(data));
        case LLIR_old::var_assign_values::EXPR:
            //cpuf::printf("On expr\n");
            return convertExpression(std::any_cast<std::vector<LLIR_old::expr>>(data), false);
        case LLIR_old::var_assign_values::CURRENT_POS:
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
        case LLIR_old::var_assign_values::NONE:
            return "NONE";
        case LLIR_old::var_assign_values::True:
            return "true";
        case LLIR_old::var_assign_values::False:
            return "false";
        case LLIR_old::var_assign_values::CURRENT_POS_COUNTER:
            return current_pos_counter.top();
        case LLIR_old::var_assign_values::CURRENT_POS_SEQUENCE:
        {
            std::string count_str = std::to_string(pos_counter_stack.top() + 1);
            if (dynamic_pos_counter.size()) {
                for (auto el : dynamic_pos_counter)
                    count_str += " + " + el;
            }
            dynamic_pos_counter = {};
            return "::" + namespace_name + "::str_t(" + current_pos_counter.top() + ", " + count_str + ")";
        }
        case LLIR_old::var_assign_values::CURRENT_CHARACTER:
            return "*(" + current_pos_counter.top() + " + " + std::to_string(pos_counter) + ")";
        case LLIR_old::var_assign_values::CURRENT_TOKEN:
            return "*" + current_pos_counter.top();
        case LLIR_old::var_assign_values::TOKEN_SEQUENCE:
            return current_pos_counter.top();
        default:
            return "NONE";
    }
}

std::string LLStringConvertions::convert_var_assing_types(const LLIR_old::var_assign_types &value) const {
    switch (value) {
        case LLIR_old::var_assign_types::ASSIGN:    return "=";
        case LLIR_old::var_assign_types::ADD:       return "+=";
        case LLIR_old::var_assign_types::SUBSTR:    return "-=";
        case LLIR_old::var_assign_types::MULTIPLY:  return "*=";
        case LLIR_old::var_assign_types::DIVIDE:    return "/=";
        case LLIR_old::var_assign_types::MODULO:    return "%=";
        default: return "="; // Handle unknown values
    }
}

std::string LLStringConvertions::conditionTypesToString(const LLIR_old::condition_types &type, const std::any &data) {
    if (type == LLIR_old::condition_types::CHARACTER) {
        //cpuf::printf("character\n");
        const auto c = std::any_cast<char>(data);
        if (c == '\'') {
            return std::string("'\\''");
        } else {
            return std::string("'") + std::any_cast<char>(data) + std::string("'");
        }
    } else if (type == LLIR_old::condition_types::ESCAPED_CHARACTER) {
        return std::string("'\\") + std::any_cast<char>(data) + std::string("'");
    } else if (type == LLIR_old::condition_types::CURRENT_CHARACTER) {
        //cpuf::printf("current_character\n");
        return "*(" + current_pos_counter.top() + " + " + std::to_string(std::any_cast<size_t>(data)) + ")";
    } else if (type == LLIR_old::condition_types::TOKEN_SEQUENCE) {
        return current_pos_counter.top();
    } else if (type == LLIR_old::condition_types::NUMBER) {
        //cpuf::printf("number\n");    
        return std::to_string(std::any_cast<long long>(data));
    } else if (type == LLIR_old::condition_types::STRING) {
        //cpuf::printf("string\n");
        return std::string(1, '"') + std::any_cast<std::string>(data) + std::string(1, '"');
    } else if (type == LLIR_old::condition_types::STRNCMP) {
        //cpuf::printf("strncmp\n");
        auto dt = std::any_cast<LLIR_old::strncmp>(data);
        std::string val;
        if (dt.is_string) {
            val = std::string("!std::strncmp(" + current_pos_counter.top() + " + " + std::to_string(dt.begin) + ", \"") + format_str(dt.value.name) + std::string("\", ") + std::to_string(count_strlen(dt.value.name.c_str())) + ")";
            pos_counter += count_strlen(dt.value.name.c_str()) - 1;
        } else {
            dynamic_pos_counter.push_back("strlen(" + dt.value.name + ")");
            val = std::string("!std::strncmp(" + current_pos_counter.top() + " + " + std::to_string(dt.begin) + ", ") + format_str(dt.value.name) + ", strlen(" + dt.value.name + "))";
        }
        return val;
    } else if (type == LLIR_old::condition_types::VARIABLE) {
        //cpuf::printf("variable\n");
        auto dt = std::any_cast<LLIR_old::var_refer>(data);
        std::string name = dt.var.name;
        for (const auto &el : dt.var.property_access)
            name += "." + el;
        if (dt.post_increament.value_or('\0') == '-') {
            name.insert(0, "--");
        } else if (dt.post_increament.value_or('\0') == '+') {
            name.insert(0, "++");
        }
        if (!dt.brace_expression.empty()) {
            name += '[' + convertExpression(dt.brace_expression, false) + ']';
        }
        if (dt.post_increament.value_or('\0') == '-') {
            name += "--";
        } else if (dt.post_increament.value_or('\0') == '+') {
            name += "++";
        }
        return name;
    } else if (type == LLIR_old::condition_types::SUCCESS_CHECK) {
        //cpuf::printf("success_check\n");
        return std::any_cast<std::string>(data) + ".status";
    } else if (type == LLIR_old::condition_types::HEX) {
        //cpuf::printf("hex\n");
        return std::string("0x") + std::any_cast<std::string>(data);
    } else if (type == LLIR_old::condition_types::RVALUE) {
        auto dt = std::any_cast<LLIR_old::assign>(data);
        return convert_var_assing_values(dt.kind, dt.data);
    } else if (type == LLIR_old::condition_types::METHOD_CALL) {
        return convertMethodCall(std::any_cast<LLIR_old::method_call>(data));
    } else if (type == LLIR_old::condition_types::FUNCTION_CALL) {
        return convertFunctionCall( std::any_cast<LLIR_old::function_call>(data));
    } else if (type == LLIR_old::condition_types::CURRENT_TOKEN) {
        if (data.has_value()) {
            auto dt = std::any_cast<LLIR_old::current_token>(data);
            auto op = conditionTypesToString(dt.op, std::any());
            return current_pos_counter.top() + "->name() " + op + " " + "::" + namespace_name + "::Tokens::" + dt.name;
        } else {
            return "*" + current_pos_counter.top();
        }
    }
    static const std::unordered_map<LLIR_old::condition_types, std::string> condTypesMap = {
        {LLIR_old::condition_types::GROUP_OPEN, "("}, {LLIR_old::condition_types::GROUP_CLOSE, ")"},
        {LLIR_old::condition_types::AND, "&&"}, {LLIR_old::condition_types::OR, "||"}, {LLIR_old::condition_types::NOT, "!"},
        {LLIR_old::condition_types::EQUAL, "=="}, {LLIR_old::condition_types::NOT_EQUAL, "!="},
        {LLIR_old::condition_types::HIGHER, ">"}, {LLIR_old::condition_types::LOWER, "<"},
        {LLIR_old::condition_types::HIGHER_OR_EQUAL, ">="}, {LLIR_old::condition_types::LOWER_OR_EQUAL, "<="},
        {LLIR_old::condition_types::LEFT_BITWISE, "<<"}, {LLIR_old::condition_types::RIGHT_BITWISE, ">>"},
        {LLIR_old::condition_types::BITWISE_AND, "&"}, {LLIR_old::condition_types::BITWISE_ANDR, "^"},
        {LLIR_old::condition_types::ADD, "+"}, {LLIR_old::condition_types::SUBSTR, "-"},
        {LLIR_old::condition_types::MULTIPLY, "*"}, {LLIR_old::condition_types::DIVIDE, "/"},
        {LLIR_old::condition_types::MODULO, "%"}, 
    };
    return condTypesMap.at(type);
}
std::string LLStringConvertions::convertFunctionCall(const LLIR_old::function_call &call) {
    std::string res = call.name + "(";
    bool first = true;
    for (auto param : call.params) {
        if (!first)
            res += ", ";
        res += convertExpression(param, false);
        first = false;
    }
    res += ')';
    return res;
}
std::string LLStringConvertions::convertAssign(const LLIR_old::assign &asgn) {
    if (asgn.kind == LLIR_old::var_assign_values::FUNCTION_CALL)
        return convertFunctionCall(std::any_cast<LLIR_old::function_call>(asgn.data));
    return convert_var_assing_values(asgn.kind, asgn.data);
}
std::string LLStringConvertions::convertMethodCall(const LLIR_old::method_call &method) {
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

std::string LLStringConvertions::convertDataBlock(const LLIR_old::DataBlock &dtb) {
    // Implement method call conversion with proper indentation
    std::string res;
    res += "::" + namespace_name + "::Types::" + rule_prev_name_str + " data";
    if (dtb.is_inclosed_map()) {
        res += ";";
        res += "\n";
        for (auto [key, value] : std::any_cast<LLIR_old::inclosed_map>(dtb.getInclosedMap())) {
            res += std::string(indentLevel, '\t') + "data." + key + " = " + convertExpression(value.first, false) + ";\n";
        }
        add_semicolon = false;
    } else {
        res += " = ";
        res += convertExpression(dtb.getRegularDataBlock().first, false);
        res += ";";
    }
    return res;
}
std::string LLStringConvertions::convertExpression(const std::vector<LLIR_old::expr> &expression, bool with_braces) {
    std::string result;
    pos_counter = 0;
    if (with_braces)
        result += '(';
    for (int i = 0; i < expression.size(); i++) {
        LLIR_old::expr current = expression[i];
        if (
            current.id == LLIR_old::condition_types::AND || 
            current.id == LLIR_old::condition_types::OR || 
            current.id == LLIR_old::condition_types::EQUAL ||
            current.id == LLIR_old::condition_types::NOT_EQUAL
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