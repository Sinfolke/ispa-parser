#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <any>
#include <typeinfo>
#include <unordered_map>
#include <iomanip>
#include <stack>
#include <IR/LLIR_old.h>
#include <corelib.h>
std::string LLIR_old::convert_var_type(var_types type) {
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


std::string LLIR_old::convert_var_assing_values(var_assign_values value, std::any data) {
    switch (value) {
        case var_assign_values::STRING:
            //cpuf::printf("on String\n");
            return std::string(1, '"') + std::any_cast<std::string>(data) + std::string(1, '"');
        case var_assign_values::VAR_REFER:
        {
            //cpuf::printf("ON var_refer\n");
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
        case var_assign_values::INT:
            //cpuf::printf("on INT, type: %s\n", data.type().name());
            return std::any_cast<std::string>(data);
        case var_assign_values::ARRAY:
        {
            //cpuf::printf("on array\n");
            auto arr = std::any_cast<LLIR_old::array>(data);
            std::string res = "[";
            for (auto &el : arr) {
                res += convertExpression(el, false);
                res += ',';
            }
            res += ']';
            return res;
        }
        case var_assign_values::OBJECT:
        {
            //cpuf::printf("on object\n");
            auto obj = std::any_cast<LLIR_old::object>(data);
            std::string res = "{";
            for (const auto &[key, value] : obj) {
                res += key;
                res += ": ";
                res += convertExpression(value, false);
                res += ",";
            }
            res += "}";
            return res;
        }
        case var_assign_values::FUNCTION_CALL:
            return convertFunctionCall(std::any_cast<function_call>(data));
        case var_assign_values::EXPR:
            //cpuf::printf("On expr\n");
            return convertExpression(std::any_cast<std::vector<LLIR_old::expr>>(data), false);
        case var_assign_values::CURRENT_POS:
        {
            auto dt = std::any_cast<double>(data);
            char sign = dt >= 0 ? '+' : '-';
            if (dt == 0)
                return current_pos_counter.top();
            return current_pos_counter.top() + sign + std::to_string((int) dt);
        }
        case var_assign_values::CURRENT_CHARACTER:
            return "*pos";
    }
    switch (value) {
        case var_assign_values::NONE:                  return "NONE";
        case var_assign_values::True:                 return "TRUE";
        case var_assign_values::False:                return "FALSE";
        case var_assign_values::CURRENT_POS_COUNTER:   return "CURRENT_POS_COUNTER";
        case var_assign_values::CURRENT_POS_SEQUENCE:  return "CURRENT_POS_SEQUENCE";
        case var_assign_values::CURRENT_TOKEN:         return "CURRENT_TOKEN";
        case var_assign_values::TOKEN_SEQUENCE:        return "TOKEN_SEQUENCE";
        default: return "NONE"; // Handle unknown values
    }
}
std::string LLIR_old::convert_var_assing_types(var_assign_types type) {
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
std::string LLIR_old::conditionTypesToString(condition_types type, std::any data) {
    if (type == condition_types::CHARACTER) {
        //cpuf::printf("character\n");
        return std::string("'") + std::any_cast<char>(data) + std::string("'");
    } else if (type == condition_types::ESCAPED_CHARACTER) {
        return std::string("'\\") + std::any_cast<char>(data) + std::string("'");
    } else if (type == condition_types::CURRENT_CHARACTER) {
        //cpuf::printf("current_character\n");
        return "*pos";
    } else if (type == condition_types::TOKEN_NAME) {
        return std::any_cast<LLIR_old::variable>(data).name + "->name()";
    } else if (type == condition_types::TOKEN) {
        return "Tokens::" + std::any_cast<std::string>(data);
    } else if (type == condition_types::NUMBER) {
        //cpuf::printf("number\n");    
        return std::to_string(std::any_cast<long long>(data));
    } else if (type == condition_types::STRING) {
        //cpuf::printf("string\n");
        return std::string(1, '"') + std::any_cast<std::string>(data) + std::string(1, '"');
    } else if (type == condition_types::STRNCMP) {
        //cpuf::printf("strncmp\n");
        auto dt = std::any_cast<LLIR_old::strncmp>(data);
        if (dt.is_string) {
            return std::string("!STRNCMP(pos, \"") + dt.value.name + std::string("\")");
        } else {
            return std::string("!STRNCMP(pos, ") + dt.value.name + std::string(")");
        }
    } else if (type == condition_types::VARIABLE) {
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
    } else if (type == condition_types::SUCCESS_CHECK) {
        //cpuf::printf("success_check\n");
        return std::any_cast<std::string>(data) + ".res";
    } else if (type == condition_types::HEX) {
        //cpuf::printf("hex\n");
        return std::string("0x") + std::any_cast<std::string>(data);
    } else if (type == condition_types::BIN) {
        //cpuf::printf("bin\n");
        return std::string("0b") + std::any_cast<std::string>(data);
    } else if (type == condition_types::RVALUE) {
        auto dt = std::any_cast<assign>(data);
        return convert_var_assing_values(dt.kind, dt.data);
    } else if (type == condition_types::METHOD_CALL) {
        return convertMethodCall(std::any_cast<method_call>(data));
    } else if (type == LLIR_old::condition_types::FUNCTION_CALL) {
        return convertFunctionCall( std::any_cast<function_call>(data));
    } else if (type == LLIR_old::condition_types::CURRENT_TOKEN) {
        if (data.has_value()) {
            auto dt = std::any_cast<LLIR_old::current_token>(data);
            auto op = conditionTypesToString(dt.op, std::any());
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
        {condition_types::TOKEN_SEQUENCE, "pos"},
    };
    return condTypesMap.at(type);
}
std::string LLIR_old::convertFunctionCall(function_call call) {
    std::string res = call.name + "(";
    for (auto param : call.params) {
        res += convertExpression(param, false);
    }
    res += ')';
    return res;
}
std::string LLIR_old::convertAssign(assign asgn) {
    if (asgn.kind == var_assign_values::FUNCTION_CALL)
        return convertFunctionCall(std::any_cast<function_call>(asgn.data));
    return convert_var_assing_values(asgn.kind, asgn.data);
}
void LLIR_old::convertVariable(variable var, std::ostream& out) {
    out << convert_var_type(var.type.type) << " " << var.name << " = " << convertAssign(var.value);
}

std::string LLIR_old::convertExpression(std::vector<expr> expression, bool with_braces) {
    std::string result;
    if (with_braces)
        result += '(';
    for (int i = 0; i < expression.size(); i++) {
        expr current = expression[i];
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
    return result;
}
void LLIR_old::convertBlock(std::vector<LLIR_old::member> block, std::ostream& out) {
    out << std::string(indentLevel, '\t') << "{\n";
    indentLevel++;
    convertMembers(block, out);
    indentLevel--;
    out << std::string(indentLevel, '\t') << "}";
}
void LLIR_old::convertCondition(condition cond, std::ostream& out) {
    out << convertExpression(cond.expression, true);
    convertBlock(cond.block, out);
    if (!cond.else_block.empty()) {
        out << "\n" << std::string(indentLevel, '\t') << "else \n";
        convertBlock(cond.else_block, out);
    }
}


void LLIR_old::convertAssignVariable(variable_assign var, std::ostream &out) {
    out << var.name << " " << convert_var_assing_types(var.assign_type) << " " << convertAssign(var.value);
}

std::string LLIR_old::convertMethodCall(method_call method) {
    // Implement method call conversion with proper indentation
    std::string res = method.var_name;
    for (auto call : method.calls) {
        res += '.';
        res += convertFunctionCall(call);
    }
    return res;
}

std::string LLIR_old::convertDataBlock(const DataBlock &dtb) {
    // Implement method call conversion with proper indentation
    std::string res;
    res += "data = ";
    if (dtb.empty())
        return "";
    if (dtb.is_inclosed_map()) {
        res += "\n";
        for (const auto &[key, value] : dtb.getInclosedMap()) {
            res += std::string(indentLevel + 1, '\t');
            res += key;
            res += ": ";
            res += convertExpression(value.first, false);
            res += " # ";
            res += convert_var_type(value.second.type);
            res += '\n';
        }
        res += std::string(indentLevel, '\t') + ";";
    } else {
        res += convertExpression(dtb.getRegularDataBlock().first, false);
        res += " # ";
        res += convert_var_type(dtb.getRegularDataBlock().second.type);
    }
    res += '\n';
    return res;
}

void LLIR_old::convertMember(const member& mem, std::ostream& out) {
    out << std::string(indentLevel, '\t');
    switch (mem.type)
    {
    case types::VARIABLE:
        convertVariable(std::any_cast<variable>(mem.value), out);
        break;
    case types::METHOD_CALL:
        out << convertMethodCall(std::any_cast<method_call>(mem.value));
        break;
    case types::IF:
        out << "if ";
        convertCondition(std::any_cast<condition>(mem.value), out);
        break;
    case types::WHILE:
        out << "while ";
        convertCondition(std::any_cast<condition>(mem.value), out);
        break;
    case types::DOWHILE:
        out << "do\n";
        convertBlock(std::any_cast<condition>(mem.value).block, out);
        out << std::string(indentLevel, '\t') << "while";
        out << convertExpression(std::any_cast<condition>(mem.value).expression, true);
        break;
    case types::INCREASE_POS_COUNTER:
        out << current_pos_counter.top() << "++";
        break;
    case LLIR_old::types::INCREASE_POS_COUNTER_BY_TOKEN_LENGTH: {
        auto var = std::any_cast<std::string>(mem.value);
        out << current_pos_counter.top() << " += " << var << ".token.length()";
        break;
    }
    case LLIR_old::types::RESET_POS_COUNTER:
        break;
    case types::ASSIGN_VARIABLE:
        convertAssignVariable(std::any_cast<variable_assign>(mem.value), out);
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
    case types::ERR:
        out << "error" << std::any_cast<std::string>(mem.value) << '\n';
        break;
    case types::SKIP_SPACES:
        if (std::any_cast<bool>(mem.value)) // isToken
            out << "skipspaces(pos)";
        else
            out << "skipspaces(TOKEN_SEQUENCE)";
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
    case types::JUMP:
        out << "jump " << corelib::text::join(std::any_cast<std::vector<std::string>>(mem.value), "_");
        break;
    case types::JUMP_FROM_VARIABLE:
        out << "jump $" << std::any_cast<std::string>(mem.value);
        break;
    case types::EMPTY:
        return;
    default:
        throw Error("Undefined IR member: %$\n", (int) mem.type);
    }
    out << '\n';
}

void LLIR_old::convertMembers(const std::vector<member> &members, std::ostream& out) {
    for (const auto &mem : members)
        convertMember(mem, out);
}
void LLIR_old::convertData(const LLIR_old::Data &data, std::ostream& out) {
    if (corelib::text::isUpper(data.name.back())) {
        // token
        out << "Rule(" << corelib::text::join(data.name, "_") << ") {";
    } else {
        // rule
        out << "Token(" << corelib::text::join(data.name, "_") << ") {";
    }
    out << '\n';
    indentLevel++;
    convertMembers(data.members, out);
    if (!data.block.empty()) {
        out << '\t' << convertDataBlock(data.block);
    }
    indentLevel--;
    out << "}\n";
}
void LLIR_old::printIR(std::ostream& out) {
    current_pos_counter.push("pos");
    for (const auto &d : data)
        convertData(d, out);
}

void LLIR_old::outputIRToFile(std::string filename) {
    int identLevel = 0;
    std::ofstream file(filename);
    if (file.is_open()) {
        printIR(file);
        file.close();
    } else {
        std::cerr << "Unable to open file " << filename << "\n";
    }
}

void LLIR_old::outputIRToConsole() {
    int identLevel = 0;
    printIR(std::cout);
}