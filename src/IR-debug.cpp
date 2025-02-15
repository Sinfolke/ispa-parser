#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <any>
#include <typeinfo>
#include <unordered_map>
#include <iomanip>
#include <IR.h>
#include <IR-debug.h>
// Assume arr_t is defined as:
template <typename T>
using arr_t = std::vector<T>;

namespace IR {
    std::string convert_var_type(var_types type) {
        static const std::unordered_map<var_types, std::string> typesMap = {
            {var_types::UNDEFINED, "UNDEF"}, {var_types::BOOLEAN, "bool"}, {var_types::STRING, "str"}, {var_types::NUMBER, "num"},
            {var_types::ARRAY, "array"}, {var_types::OBJECT, "object"}, {var_types::FUNCTION, "function"},
            {var_types::ANY, "any"}, {var_types::Rule, "rule"}, {var_types::Token, "token"},
            {var_types::CHAR, "char"}, {var_types::UCHAR, "unsigned char"}, 
            {var_types::SHORT, "short"}, {var_types::USHORT, "unsigned short"},
            {var_types::INT, "int"}, {var_types::UINT, "unsigned int"},
            {var_types::LONG, "long"}, {var_types::ULONG, "unsigned long"},
            {var_types::LONGLONG, "long long"}, {var_types::ULONGLONG, "unsigned long long"}
        };
        return typesMap.at(type);
    }
    

    std::string convert_var_assing_values(var_assign_values value, std::any data) {
        switch (value) {
            case var_assign_values::STRING:
                cpuf::printf("on String\n");
                return std::string('"', 1) + std::any_cast<std::string>(data) + std::string('"', 1);
            case var_assign_values::VAR_REFER:
            {
                cpuf::printf("ON var_refer\n");
                auto dt = std::any_cast<var_refer>(data);
                std::string res;
                if (dt.pre_increament)
                    res += "++";
                res += dt.name;
                if (dt.post_increament)
                    res += "++";
                return res;
            }
            case var_assign_values::ID:
                cpuf::printf("on ID\n");
            case var_assign_values::INT:
                cpuf::printf("on INT\n");
                return std::any_cast<std::string>(data);
            case var_assign_values::ARRAY:
            {
                cpuf::printf("on array\n");
                auto arr = std::any_cast<IR::array>(data);
                std::string res = "[";
                for (auto &el : arr) {
                    res += convertAssign(el);
                    res += ',';
                }
                res += ']';
                return res;
            }
            case var_assign_values::OBJECT:
            {
                cpuf::printf("on object\n");
                auto obj = std::any_cast<IR::object>(data);
                std::string res = "{";
                for (auto [key, value] : obj) {
                    res += key;
                    res += ": ";
                    res += convertAssign(value);
                    res += ",";
                }
                res += "}";
                return res;
            }
            case var_assign_values::ACCESSOR: 
            {
                cpuf::printf("accessor\n");
                return convertAccessor(std::any_cast<accessor>(data));
            }
            case var_assign_values::FUNCTION_CALL:
                return convertFunctionCall(std::any_cast<function_call>(data));
            case var_assign_values::EXPR:
                cpuf::printf("On expr\n");
                return convertExpression(std::any_cast<arr_t<IR::expr>>(data), false);
        }
        static const std::unordered_map<var_assign_values, std::string> typesMap = {
            {var_assign_values::NONE, "NONE"},
            {var_assign_values::_TRUE, "TRUE"},
            {var_assign_values::_FALSE, "FALSE"},
            {var_assign_values::CURRENT_POS_COUNTER, "CURRENT_POS_COUNTER"},
            {var_assign_values::CURRENT_POS_SEQUENCE, "CURRENT_POS_SEQUENCE"},
            {var_assign_values::CURRENT_TOKEN, "CURRENT_TOKEN"},
            {var_assign_values::TOKEN_SEQUENCE, "TOKEN_SEQUENCE"},
        };
        return typesMap.at(value);
    }

    std::string convert_var_assing_types(var_assign_types value) {
        static const std::unordered_map<var_assign_types, std::string> valueToString = {
            {var_assign_types::ASSIGN, "="},
            {var_assign_types::ADD, "+="},
            {var_assign_types::SUBSTR, "-="},
            {var_assign_types::MULTIPLY, "*="},
            {var_assign_types::DIVIDE, "/="},
            {var_assign_types::MODULO, "%="}
        };
        return valueToString.at(value);
    }

    std::string conditionTypesToString(condition_types type, std::any data) {
        if (type == condition_types::CHARACTER) {
            //cpuf::printf("character\n");
            auto dt = std::any_cast<char>(data);
            if (dt == '\0')
                return std::string("'\\0'");
            else
                return std::string("'") + dt + std::string("'");
        } else if (type == condition_types::CURRENT_CHARACTER) {
            //cpuf::printf("current_character\n");
            return "*pos";
        } else if (type == condition_types::NUMBER) {
            //cpuf::printf("number\n");    
            return std::to_string(std::any_cast<long long>(data));
        } else if (type == condition_types::STRING) {
            //cpuf::printf("string\n");
            return std::string(1, '"') + std::any_cast<std::string>(data) + std::string(1, '"');
        } else if (type == condition_types::STRNCMP) {
            //cpuf::printf("strncmp\n");
            return std::string("!STRNCMP(pos, \"") + std::any_cast<std::string>(data) + std::string("\")");
        } else if (type == condition_types::VARIABLE) {
            //cpuf::printf("variable\n");    
            return std::any_cast<std::string>(data);
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
            return convert_var_assing_values(dt.kind, dt.data);
        } else if (type == condition_types::METHOD_CALL) {
            return convertMethodCall(std::any_cast<method_call>(data));
        } else if (type == IR::condition_types::FUNCTION_CALL) {
            auto call = std::any_cast<function_call>(data);
            return convertFunctionCall(call);
        }
        static const std::unordered_map<condition_types, std::string> condTypesMap = {
            {condition_types::GROUP_OPEN, "("}, {condition_types::GROUP_CLOSE, ")"},
            {condition_types::AND, "&&"}, {condition_types::OR, "||"}, {condition_types::NOT, "!"},
            {condition_types::EQUAL, "=="}, {condition_types::NOT_EQUAL, "!="},
            {condition_types::HIGHER, ">"}, {condition_types::LOWER, "<"},
            {condition_types::HIGHER_OR_EQUAL, ">="}, {condition_types::LOWER_OR_EQUAL, "<="},
            {condition_types::LEFT_BITWISE, "<<"}, {condition_types::RIGHT_BITWISE, ">>"},
            {condition_types::BITWISE_AND, "&"}, {condition_types::CHARACTER, ""},
            {condition_types::CURRENT_TOKEN, "CURRENT_TOKEN"}, 
        };
        return condTypesMap.at(type);
    }
    std::string convertFunctionCall(function_call call) {
        std::string res = call.name + "(";
        for (auto param : call.params) {
            res += convertAssign(param);
        }
        res += ')';
        return res;
    }
    std::string convertAssign(assign asgn) {
        if (asgn.kind == var_assign_values::FUNCTION_CALL)
            return convertFunctionCall(std::any_cast<function_call>(asgn.data));
        return convert_var_assing_values(asgn.kind, asgn.data);
    }

    std::string convertAccessor(accessor acc) {
        std::string str;
        for (auto el : acc.elements) {
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
        }
        str += '\n';
        return str;
    }
    void convertVariable(variable var, std::ostream& out, int &indentLevel) {
        out << convert_var_type(var.type.type) << " " << var.name << " = " << convertAssign(var.value);
    }

    std::string convertExpression(arr_t<expr> expression, bool with_braces) {
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
                result += conditionTypesToString(current.id, current.value);
                result += ' ';
            } else {
                result += conditionTypesToString(current.id, current.value);
            }
        }
        if (with_braces)
            result += ")\n";
        return result;
    }

    void convertBlock(arr_t<IR::member> block, std::ostream& out, int &indentLevel) {
        out << std::string(indentLevel, '\t') << "{\n";
        indentLevel++;
        convertMembers(block, out, indentLevel);
        indentLevel--;
        out << std::string(indentLevel, '\t') << "}";
    }

    void convertCondition(condition cond, std::ostream& out, int &indentLevel) {
        out << convertExpression(cond.expression, true);
        convertBlock(cond.block, out, indentLevel);
        if (!cond.else_block.empty()) {
            out << "\n" << std::string(indentLevel, '\t') << "else \n";
            convertBlock(cond.else_block, out, indentLevel);
        }
    }


    void convertAssignVariable(variable_assign var, std::ostream &out, int &indentLevel) {
        out << var.name << " " << convert_var_assing_types(var.assign_type) << " " << convertAssign(var.value);
    }

    std::string convertMethodCall(method_call method) {
        // Implement method call conversion with proper indentation
        std::string res = method.var_name;
        for (auto call : method.calls) {
            res += '.';
            res += convertFunctionCall(call);
        }
        return res;
    }

    void convertMember(const member& mem, std::ostream& out, int &indentLevel) {
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
            convertVariable(std::any_cast<variable>(mem.value), out, indentLevel);
            break;
        case types::METHOD_CALL:
            out << convertMethodCall(std::any_cast<method_call>(mem.value));
            break;
        case types::IF:
            out << "if ";
            convertCondition(std::any_cast<condition>(mem.value), out, indentLevel);
            break;
        case types::WHILE:
            out << "while ";
            convertCondition(std::any_cast<condition>(mem.value), out, indentLevel);
            break;
        case types::DOWHILE:
            out << "do\n";
            convertBlock(std::any_cast<condition>(mem.value).block, out, indentLevel);
            out << std::string(indentLevel, '\t') << "while";
            out << convertExpression(std::any_cast<condition>(mem.value).expression, true);
            break;
        case types::INCREASE_POS_COUNTER:
            out << "pos++";
            break;
        case types::ACCESSOR:
            convertAccessor(std::any_cast<accessor>(mem.value));
            break;
        case types::ASSIGN_VARIABLE:
            convertAssignVariable(std::any_cast<variable_assign>(mem.value), out, indentLevel);
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
        default:
            throw Error("Undefined IR member\n");
        }
        out << '\n';
    }

    void convertMembers(arr_t<member> members, std::ostream& out, int &indentLevel) {
        for (auto mem : members)
            convertMember(mem, out, indentLevel);
    }

    void printIR(const ir& representation, std::ostream& out, int &indentLevel) {
        for (const auto& mem : representation.elements) {
            convertMember(mem, out, indentLevel);
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