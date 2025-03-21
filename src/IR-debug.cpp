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
#include <IR-debug.h>

namespace IR {
    std::string convert_var_type(var_types type) {
        static const std::unordered_map<var_types, std::string> typesMap = {
            {var_types::UNDEFINED, "UNDEF"}, {var_types::BOOLEAN, "bool"}, {var_types::STRING, "str"}, {var_types::NUMBER, "num"},
            {var_types::ARRAY, "array"}, {var_types::OBJECT, "object"}, {var_types::FUNCTION, "function"},
            {var_types::ANY, "any"}, {var_types::Rule, "rule"}, {var_types::Token, "token"},
            {var_types::Rule_result, "Rule_result"}, {var_types::Token_result, "Token_result"},
            {var_types::CHAR, "char"}, {var_types::UCHAR, "unsigned char"}, 
            {var_types::SHORT, "short"}, {var_types::USHORT, "unsigned short"},
            {var_types::INT, "int"}, {var_types::UINT, "unsigned int"},
            {var_types::LONG, "long"}, {var_types::ULONG, "unsigned long"},
            {var_types::LONGLONG, "long long"}, {var_types::ULONGLONG, "unsigned long long"}
        };
        return typesMap.at(type);
    }
    

    std::string convert_var_assing_values(var_assign_values value, std::any data, std::stack<std::string> &current_pos_counter) {
        switch (value) {
            case var_assign_values::STRING:
                //cpuf::printf("on String\n");
                return std::string(1, '"') + std::any_cast<std::string>(data) + std::string(1, '"');
            case var_assign_values::VAR_REFER:
            {
                //cpuf::printf("ON var_refer\n");
                auto dt = std::any_cast<var_refer>(data);
                std::string res;
                if (dt.pre_increament)
                    res += "++";
                res += dt.name;
                if (dt.post_increament)
                    res += "++";
                return res;
            }
            case var_assign_values::VARIABLE:
            {
                //cpuf::printf("on ID\n");
                auto dt = std::any_cast<IR::variable>(data);
                std::string res = dt.name;
                for (auto el : dt.property_access)
                    res += "." + el;
                return res;
            }
            case var_assign_values::INT:
                //cpuf::printf("on INT, type: %s\n", data.type().name());
                return std::any_cast<std::string>(data);
            case var_assign_values::ARRAY:
            {
                //cpuf::printf("on array\n");
                auto arr = std::any_cast<IR::array>(data);
                std::string res = "[";
                for (auto &el : arr) {
                    res += convertAssign(el, current_pos_counter);
                    res += ',';
                }
                res += ']';
                return res;
            }
            case var_assign_values::OBJECT:
            {
                //cpuf::printf("on object\n");
                auto obj = std::any_cast<IR::object>(data);
                std::string res = "{";
                for (auto [key, value] : obj) {
                    res += key;
                    res += ": ";
                    res += convertAssign(value, current_pos_counter);
                    res += ",";
                }
                res += "}";
                return res;
            }
            case var_assign_values::ACCESSOR: 
                //cpuf::printf("accessor\n");
                return convertAccessor(std::any_cast<accessor>(data), current_pos_counter);
            case var_assign_values::FUNCTION_CALL:
                return convertFunctionCall(std::any_cast<function_call>(data), current_pos_counter);
            case var_assign_values::EXPR:
                //cpuf::printf("On expr\n");
                return convertExpression(std::any_cast<arr_t<IR::expr>>(data), false, current_pos_counter);
            case var_assign_values::CURRENT_POS:
            {
                auto dt = std::any_cast<double>(data);
                char sign = dt >= 0 ? '+' : '-';
                if (dt == 0)
                    return current_pos_counter.top();
                return current_pos_counter.top() + sign + std::to_string((int) dt);
            }
            case var_assign_values::PROPERTY:
            {
                auto dt = std::any_cast<IR::property>(data);
                std::string res = dt.obj;
                for (auto el : dt.properties) {
                    res += "." + el;
                }
                return res;
            }
        }
        switch (value) {
            case var_assign_values::NONE:                  return "NONE";
            case var_assign_values::_TRUE:                 return "TRUE";
            case var_assign_values::_FALSE:                return "FALSE";
            case var_assign_values::CURRENT_POS_COUNTER:   return "CURRENT_POS_COUNTER";
            case var_assign_values::CURRENT_POS_SEQUENCE:  return "CURRENT_POS_SEQUENCE";
            case var_assign_values::CURRENT_TOKEN:         return "CURRENT_TOKEN";
            case var_assign_values::TOKEN_SEQUENCE:        return "TOKEN_SEQUENCE";
            default: return "NONE"; // Handle unknown values
        }
    }
    std::string convert_var_assing_types(var_assign_types type) {
        switch (type) {
            case var_assign_types::ASSIGN:    return "=";
            case var_assign_types::ADD:       return "+=";
            case var_assign_types::SUBSTR:    return "-=";
            case var_assign_types::MULTIPLY:  return "*=";
            case var_assign_types::DIVIDE:    return "/=";
            case var_assign_types::MODULO:    return "%=";
            default: return "="; // Handle unknown values
        }
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
    std::string conditionTypesToString(condition_types type, std::any data, std::stack<std::string> &current_pos_counter) {
        if (type == condition_types::CHARACTER) {
            //cpuf::printf("character\n");
            return std::string("'") + getCharFromEscaped(std::any_cast<char>(data), false) + std::string("'");
        } else if (type == condition_types::CURRENT_CHARACTER) {
            //cpuf::printf("current_character\n");
            return "*pos";
        } else if (type == IR::condition_types::PREV_CHARACTER) {
            return "*pos";
        } else if (type == condition_types::NUMBER) {
            //cpuf::printf("number\n");    
            return std::to_string(std::any_cast<long long>(data));
        } else if (type == condition_types::STRING) {
            //cpuf::printf("string\n");
            return std::string(1, '"') + std::any_cast<std::string>(data) + std::string(1, '"');
        } else if (type == condition_types::STRNCMP || type == condition_types::STRNCMP_PREV) {
            //cpuf::printf("strncmp\n");
            auto dt = std::any_cast<IR::strncmp>(data);
            if (dt.is_string) {
                return std::string("!STRNCMP(pos, \"") + dt.value.name + std::string("\")");
            } else {
                return std::string("!STRNCMP(pos, ") + dt.value.name + std::string(")");
            }
        } else if (type == condition_types::VARIABLE) {
            //cpuf::printf("variable\n");   
            auto dt = std::any_cast<IR::variable>(data);
            std::string res = dt.name;
            for (auto el : dt.property_access)
                res += "." + el;
            return res;
        } else if (type == condition_types::SUCCESS_CHECK) {
            //cpuf::printf("success_check\n");
            return std::any_cast<std::string>(data) + ".res";
        } else if (type == condition_types::HEX) {
            //cpuf::printf("hex\n");
            return std::string("0x") + std::any_cast<std::string>(data);
        } else if (type == condition_types::BIN) {
            //cpuf::printf("bin\n");
            return std::string("0b") + std::any_cast<std::string>(data);
        } else if (type == condition_types::ANY_DATA) {
            auto dt = std::any_cast<assign>(data);
            return convert_var_assing_values(dt.kind, dt.data, current_pos_counter);
        } else if (type == condition_types::METHOD_CALL) {
            return convertMethodCall(std::any_cast<method_call>(data), current_pos_counter);
        } else if (type == IR::condition_types::FUNCTION_CALL) {
            return convertFunctionCall( std::any_cast<function_call>(data), current_pos_counter);
        } else if (type == IR::condition_types::CURRENT_TOKEN) {
            if (data.has_value()) {
                auto dt = std::any_cast<IR::current_token>(data);
                auto op = conditionTypesToString(dt.op, std::any(), current_pos_counter);
                return "CURRENT_TOKEN " + op + " " + dt.name;
            } else {
                return "CURRENT_TOKEN";
            }
        }
        static const std::unordered_map<condition_types, std::string> condTypesMap = {
            {condition_types::GROUP_OPEN, "("}, {condition_types::GROUP_CLOSE, ")"},
            {condition_types::AND, "&&"}, {condition_types::OR, "||"}, {condition_types::NOT, "!"},
            {condition_types::EQUAL, "=="}, {condition_types::NOT_EQUAL, "!="},
            {condition_types::HIGHER, ">"}, {condition_types::LOWER, "<"},
            {condition_types::HIGHER_OR_EQUAL, ">="}, {condition_types::LOWER_OR_EQUAL, "<="},
            {condition_types::LEFT_BITWISE, "<<"}, {condition_types::RIGHT_BITWISE, ">>"},
            {condition_types::BITWISE_AND, "&"}, {condition_types::BITWISE_ANDR, "^"},
            {condition_types::ADD, "+"}, {condition_types::SUBSTR, "-"},
            {condition_types::MULTIPLY, "*"}, {condition_types::DIVIDE, "/"},
            {condition_types::MODULO, "%"}, {condition_types::CURRENT_TOKEN, "CURRENT_TOKEN"}, 
        };
        return condTypesMap.at(type);
    }
    std::string convertFunctionCall(function_call call, std::stack<std::string> &current_pos_counter) {
        std::string res = call.name + "(";
        for (auto param : call.params) {
            res += convertAssign(param, current_pos_counter);
        }
        res += ')';
        return res;
    }
    std::string convertAssign(assign asgn, std::stack<std::string> &current_pos_counter) {
        if (asgn.kind == var_assign_values::FUNCTION_CALL)
            return convertFunctionCall(std::any_cast<function_call>(asgn.data), current_pos_counter);
        return convert_var_assing_values(asgn.kind, asgn.data, current_pos_counter);
    }

    std::string convertAccessor(accessor acc, std::stack<std::string> &current_pos_counter) {
        std::string str;
        bool first = true;
        for (auto el : acc.elements) {
            if (!first)
                str += '>';
            auto el_num = std::any_cast<Parser::Rule>(el.data);
            auto el_num_data = std::any_cast<obj_t>(el_num.data);
            auto main = std::any_cast<std::string>(corelib::map::get(el_num_data, "main"));
            switch (el.name) {
                case Parser::Rules::accessors_group:
                    str += '$';
                    break;
                case Parser::Rules::accessors_element:
                    str += '%';
                    break;
                case Parser::Rules::accessors_char:
                    str += '^';
                    break;
                default:
                    throw Error("Undefined accessor");
            }
            str += main;
            first = false;
        }
        str += '\n';
        return str;
    }
    void convertVariable(variable var, std::ostream& out, int &indentLevel, std::stack<std::string> &current_pos_counter) {
        out << convert_var_type(var.type.type) << " " << var.name << " = " << convertAssign(var.value, current_pos_counter);
    }

    std::string convertExpression(arr_t<expr> expression, bool with_braces, std::stack<std::string> &current_pos_counter) {
        std::string result;
        if (with_braces)
            result += '(';
        for (int i = 0; i < expression.size(); i++) {
            expr current = expression[i];
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

    void convertBlock(arr_t<IR::member> block, std::ostream& out, int &indentLevel, std::stack<std::string> &current_pos_counter) {
        out << std::string(indentLevel, '\t') << "{\n";
        indentLevel++;
        convertMembers(block, out, indentLevel, current_pos_counter);
        indentLevel--;
        out << std::string(indentLevel, '\t') << "}";
    }

    void convertCondition(condition cond, std::ostream& out, int &indentLevel, std::stack<std::string> &current_pos_counter) {
        out << convertExpression(cond.expression, true, current_pos_counter);
        convertBlock(cond.block, out, indentLevel, current_pos_counter);
        if (!cond.else_block.empty()) {
            out << "\n" << std::string(indentLevel, '\t') << "else \n";
            convertBlock(cond.else_block, out, indentLevel, current_pos_counter);
        }
    }


    void convertAssignVariable(variable_assign var, std::ostream &out, int &indentLevel, std::stack<std::string> &current_pos_counter) {
        out << var.name << " " << convert_var_assing_types(var.assign_type) << " " << convertAssign(var.value, current_pos_counter);
    }

    std::string convertMethodCall(method_call method, std::stack<std::string> &current_pos_counter) {
        // Implement method call conversion with proper indentation
        std::string res = method.var_name;
        for (auto call : method.calls) {
            res += '.';
            res += convertFunctionCall(call, current_pos_counter);
        }
        return res;
    }

    std::string convertDataBlock(data_block dtb, int indentLevel, std::stack<std::string> &current_pos_counter) {
        // Implement method call conversion with proper indentation
        std::string res;
        res += "data = ";
        if (dtb.is_inclosed_map) {
            res += "\n";
            for (auto [key, value] : std::any_cast<inclosed_map>(dtb.value.data)) {
                res += std::string(indentLevel + 1, '\t');
                res += key;
                res += ": ";
                res += convertExpression(value.first, false, current_pos_counter);
                res += " # ";
                res += convert_var_type(value.second.type);
                res += '\n';
            }
            res += std::string(indentLevel, '\t') + ";";
        } else {
            res += convertAssign(std::any_cast<assign>(dtb.value), current_pos_counter);
            res += " # ";
            res += convert_var_type(dtb.assign_type.type);
        }
        return res;
    }

    void convertMember(const member& mem, std::ostream& out, int &indentLevel, std::stack<std::string> &current_pos_counter) {
        if (mem.type != types::RULE_END)
            out << std::string(indentLevel, '\t');
        switch (mem.type)
        {
        case types::RULE:
            out << "Rule(" << std::any_cast<std::string>(mem.value) << ") {";
            indentLevel++;
            break;
        case types::TOKEN:
            out << "Token(" << std::any_cast<std::string>(mem.value) << ") {";
            indentLevel++;
            break;
        case types::RULE_END:
            out << "}";
            indentLevel--;
            break;
        case types::VARIABLE:
            convertVariable(std::any_cast<variable>(mem.value), out, indentLevel, current_pos_counter);
            break;
        case types::METHOD_CALL:
            out << convertMethodCall(std::any_cast<method_call>(mem.value), current_pos_counter);
            break;
        case types::IF:
            out << "if ";
            convertCondition(std::any_cast<condition>(mem.value), out, indentLevel, current_pos_counter);
            break;
        case types::WHILE:
            out << "while ";
            convertCondition(std::any_cast<condition>(mem.value), out, indentLevel, current_pos_counter);
            break;
        case types::DOWHILE:
            out << "do\n";
            convertBlock(std::any_cast<condition>(mem.value).block, out, indentLevel, current_pos_counter);
            out << std::string(indentLevel, '\t') << "while";
            out << convertExpression(std::any_cast<condition>(mem.value).expression, true, current_pos_counter);
            break;
        case types::INCREASE_POS_COUNTER:
            out << current_pos_counter.top() << "++";
            break;
        case IR::types::INCREASE_POS_COUNTER_BY_TOKEN_LENGTH: {
            auto var = std::any_cast<std::string>(mem.value);
            out << current_pos_counter.top() << " += " << var << ".token.length()";
            break;
        }
        case IR::types::RESET_POS_COUNTER:
            break;
        case types::ACCESSOR:
            out << convertAccessor(std::any_cast<accessor>(mem.value), current_pos_counter);
            break;
        case types::ASSIGN_VARIABLE:
            convertAssignVariable(std::any_cast<variable_assign>(mem.value), out, indentLevel, current_pos_counter);
            break;
        case types::BREAK_LOOP:
            out << "break";
            break;
        case types::CONTINUE_LOOP:
            out << "continue";
            break;
        case types::EXIT:
            out << "return {}";
            break;
        case types::SKIP_SPACES:
            if (std::any_cast<bool>(mem.value)) // isToken
                out << "skipspaces(pos)";
            else
                out << "skipspaces(TOKEN_SEQUENCE)";
            break;
        case types::DATA_BLOCK:
            out << convertDataBlock(std::any_cast<IR::data_block>(mem.value), indentLevel, current_pos_counter);
            break;
        case types::PUSH_POS_COUNTER: {
            out << "auto " << std::any_cast<std::string>(mem.value) << " = " << current_pos_counter.top();
            current_pos_counter.push(std::any_cast<std::string>(mem.value));
            break;
        }
        case types::POP_POS_COUNTER: {
            auto el = current_pos_counter.top();
            current_pos_counter.pop();
            out << current_pos_counter.top() << " = " << el;
            break;
        }
        default:
            throw Error("Undefined IR member\n");
        }
        out << '\n';
    }

    void convertMembers(arr_t<member> members, std::ostream& out, int &indentLevel, std::stack<std::string> &current_pos_counter) {
        for (auto mem : members)
            convertMember(mem, out, indentLevel, current_pos_counter);
    }

    void printIR(const ir& representation, std::ostream& out, int &indentLevel) {
        std::stack<std::string> current_pos_counter;
        current_pos_counter.push("pos");
        for (const auto& mem : representation.elements) {
            convertMember(mem, out, indentLevel, current_pos_counter);
        }
    }

    void outputIRToFile(ir representation, std::string filename) {
        int identLevel = 0;
        std::ofstream file(filename);
        if (file.is_open()) {
            printIR(representation, file, identLevel);
            file.close();
        } else {
            std::cerr << "Unable to open file " << filename << "\n";
        }
    }

    void outputIRToConsole(const ir& representation) {
        int identLevel = 0;
        printIR(representation, std::cout, identLevel);
    }

    std::string typesToString(types t) {
        switch (t) {
            case types::NONE:                return "NONE";
            case types::RULE:                return "RULE";
            case types::TOKEN:               return "TOKEN";
            case types::RULE_END:            return "RULE_END";
            case types::VARIABLE:            return "VARIABLE";
            case types::IF:                  return "IF";
            case types::WHILE:               return "WHILE";
            case types::DOWHILE:             return "DOWHILE";
            case types::ACCESSOR:            return "ACCESSOR";
            case types::METHOD_CALL:         return "METHOD_CALL";
            case types::FUNCTION_CALL:       return "FUNCTION_CALL";
            case types::EXIT:                return "EXIT";
            case types::BREAK_LOOP:          return "BREAK_LOOP";
            case types::CONTINUE_LOOP:       return "CONTINUE_LOOP";
            case types::ASSIGN_VARIABLE:     return "ASSIGN_VARIABLE";
            case types::INCREASE_POS_COUNTER:return "INCREASE_POS_COUNTER";
            case types::SKIP_SPACES:         return "SKIP_SPACES";
            default:                         return "UNKNOWN";
        }
    }
}