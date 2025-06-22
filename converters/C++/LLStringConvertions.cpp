module;
module LLStringConvertions;
import LLIR;
import std;
import std.compat;
static std::size_t count_strlen(const char* str) {
    std::size_t count = 0;
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
std::string LLStringConvertions::convert_var_type(const LLIR::var_types &type, const stdu::vector<LLIR::var_type> &data) const {
    if (type == LLIR::var_types::ARRAY) {
        stdu::vector<LLIR::var_type> type = data;
        if (data.empty())
            type.push_back({LLIR::var_types::ANY});
        std::string t = "::" + namespace_name + "::arr_t";
        t += "<";
        t += convert_var_type(type[0].type, type[0].templ);
        t += ">";
        return t;
    } else if (type == LLIR::var_types::OBJECT) {
        stdu::vector<LLIR::var_type> type = data;
        if (data.size() < 1) {
            type.push_back({LLIR::var_types::ANY});
        }
        if (data.size() < 2) {
            type.push_back({LLIR::var_types::ANY});
        }
        std::string t = "::" + namespace_name + "::obj_t";
        t += "<";
        t += convert_var_type(type[0].type, type[0].templ);
        t += ", ";
        t += convert_var_type(type[1].type, type[1].templ);
        t += ">";
        return t;
    }
    static const std::unordered_map<LLIR::var_types, std::string> typesMap = {
        {LLIR::var_types::UNDEFINED, "UNDEF"}, {LLIR::var_types::BOOLEAN, "bool_t"},
        {LLIR::var_types::STRING, "str_t"}, {LLIR::var_types::NUMBER, "num_t"},
        {LLIR::var_types::INT, "int"}, {LLIR::var_types::FUNCTION, "function"},
        {LLIR::var_types::ANY, "any_t"}, {LLIR::var_types::Rule, "Rule"}, {LLIR::var_types::Token, "Token"},
        {LLIR::var_types::Rule_result, "Rule_res"}, {LLIR::var_types::Token_result, "Token_res"},
        {LLIR::var_types::CHAR, "char"}
    };
    if (type != LLIR::var_types::INT && type != LLIR::var_types::CHAR)
        return "::" + namespace_name + "::" + typesMap.at(type);
    else
        return typesMap.at(type);
}


std::string LLStringConvertions::convert_var_assing_values(const LLIR::var_assign_values &value, const std::any &data) {
    switch (value) {
        case LLIR::var_assign_values::STRING:
            //cpuf::printf("on String\n");
            return std::string(1, '"') + format_str(std::any_cast<std::string>(data)) + std::string(1, '"');
        case LLIR::var_assign_values::VAR_REFER:
        {
            auto dt = std::any_cast<LLIR::var_refer>(data);
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
        case LLIR::var_assign_values::NUMBER:
            //cpuf::printf("on INT\n");
            return std::to_string(std::any_cast<int>(data));
        case LLIR::var_assign_values::ARRAY:
        {
            //cpuf::printf("on array\n");
            auto arr = std::any_cast<LLIR::array>(data);
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
        case LLIR::var_assign_values::OBJECT:
        {
            //cpuf::printf("on object\n");
            auto obj = std::any_cast<LLIR::object>(data);
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
        case LLIR::var_assign_values::ACCESSOR:
            //cpuf::printf("accessor\n");
            return "";
            throw Error("Accessor cannot be here\n");
        case LLIR::var_assign_values::FUNCTION_CALL:
            return convertFunctionCall(std::any_cast<LLIR::function_call>(data));
        case LLIR::var_assign_values::EXPR:
            //cpuf::printf("On expr\n");
            return convertExpression(std::any_cast<stdu::vector<LLIR::expr>>(data), false);
        case LLIR::var_assign_values::CURRENT_POS:
        {
            auto dt = std::any_cast<double>(data);
            char sign = dt >= 0 ? '+' : '-';
            dt = std::abs(dt);
            if (dt == 0)
                return current_pos_counter.top();
            return current_pos_counter.top() + sign + std::to_string((int) dt);
        }
        case LLIR::var_assign_values::TOKEN_NAME:
            return std::string("Tokens::") + corelib::text::join(std::any_cast<stdu::vector<std::string>>(data), "_");
        case LLIR::var_assign_values::INTERNAL_FUNCTION_CALL: {
            const auto &dt = std::any_cast<const LLIR::function_call&>(data);
            if (dt.name == LLIR::internal_functions::dfa_decide)
            {
                return std::string("DFA_DECIDE(&table_") + std::to_string(std::any_cast<std::size_t>(dt.params[0][0].value)) + ", " + current_pos_counter.top() + ")";
            }
            break;
        }
        case LLIR::var_assign_values::NONE:
            return "NONE";
        case LLIR::var_assign_values::True:
            return "true";
        case LLIR::var_assign_values::False:
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
        case LLIR::var_assign_values::CURRENT_CHARACTER:
            return "*(" + current_pos_counter.top() + " + " + std::to_string(pos_counter) + ")";
        case LLIR::var_assign_values::CURRENT_TOKEN:
            return "*" + current_pos_counter.top();
        case LLIR::var_assign_values::TOKEN_SEQUENCE:
            return current_pos_counter.top();
        default:
            throw Error("Undefined assign_value: {}", (int) value);
    }
}

std::string LLStringConvertions::convert_var_assing_types(const LLIR::var_assign_types &value) const {
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

std::string LLStringConvertions::conditionTypesToString(const LLIR::condition_types &type, const std::any &data) {
    if (type == LLIR::condition_types::CHARACTER) {
        //cpuf::printf("character\n");
        const auto c = std::any_cast<char>(data);
        if (c == '\'') {
            return std::string("'\\''");
        } else {
            return std::string("'") + std::any_cast<char>(data) + std::string("'");
        }
    } else if (type == LLIR::condition_types::ESCAPED_CHARACTER) {
        return std::string("'\\") + std::any_cast<char>(data) + std::string("'");
    } else if (type == LLIR::condition_types::CURRENT_CHARACTER) {
        //cpuf::printf("current_character\n");
        return "*(" + current_pos_counter.top() + " + " + std::to_string(std::any_cast<std::size_t>(data)) + ")";
    } else if (type == LLIR::condition_types::TOKEN_SEQUENCE) {
        return current_pos_counter.top();
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
            val = std::string("!std::strncmp(" + current_pos_counter.top() + " + " + std::to_string(dt.begin) + ", \"") + format_str(dt.value.name) + std::string("\", ") + std::to_string(count_strlen(dt.value.name.c_str())) + ")";
            pos_counter += count_strlen(dt.value.name.c_str()) - 1;
        } else {
            dynamic_pos_counter.push_back("strlen(" + dt.value.name + ")");
            val = std::string("!std::strncmp(" + current_pos_counter.top() + " + " + std::to_string(dt.begin) + ", ") + format_str(dt.value.name) + ", strlen(" + dt.value.name + "))";
        }
        return val;
    } else if (type == LLIR::condition_types::VARIABLE) {
        //cpuf::printf("variable\n");
        auto dt = std::any_cast<LLIR::var_refer>(data);
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
    } else if (type == LLIR::condition_types::SUCCESS_CHECK) {
        //cpuf::printf("success_check\n");
        return std::any_cast<std::string>(data) + ".status";
    } else if (type == LLIR::condition_types::HEX) {
        //cpuf::printf("hex\n");
        return std::string("0x") + std::any_cast<std::string>(data);
    } else if (type == LLIR::condition_types::RVALUE) {
        auto dt = std::any_cast<LLIR::assign>(data);
        return convert_var_assing_values(dt.kind, dt.data);
    } else if (type == LLIR::condition_types::METHOD_CALL) {
        return convertMethodCall(std::any_cast<LLIR::method_call>(data));
    } else if (type == LLIR::condition_types::FUNCTION_CALL) {
        return convertFunctionCall( std::any_cast<LLIR::function_call>(data));
    } else if (type == LLIR::condition_types::CURRENT_TOKEN) {
        if (data.has_value()) {
            auto dt = std::any_cast<LLIR::current_token>(data);
            auto op = conditionTypesToString(dt.op, std::any());
            return current_pos_counter.top() + "->name() " + op + " " + "::" + namespace_name + "::Tokens::" + dt.name;
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
std::string LLStringConvertions::convertFunctionCall(const LLIR::function_call &call) {
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
std::string LLStringConvertions::convertAssign(const LLIR::assign &asgn) {
    if (asgn.kind == LLIR::var_assign_values::FUNCTION_CALL)
        return convertFunctionCall(std::any_cast<LLIR::function_call>(asgn.data));
    return convert_var_assing_values(asgn.kind, asgn.data);
}
std::string LLStringConvertions::convertMethodCall(const LLIR::method_call &method) {
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

std::string LLStringConvertions::convertDataBlock(const LLIR::DataBlock &dtb) {
    // Implement method call conversion with proper indentation
    std::string res;
    res += "::" + namespace_name + "::Types::" + rule_prev_name_str + " data";
    if (dtb.is_inclosed_map()) {
        res += ";";
        res += "\n";
        for (auto [key, value] : std::any_cast<LLIR::inclosed_map>(dtb.getInclosedMap())) {
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
std::string LLStringConvertions::convertExpression(const stdu::vector<LLIR::expr> &expression, bool with_braces) {
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