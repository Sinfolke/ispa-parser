#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <any>
#include <typeinfo>
#include <unordered_map>
#include <iomanip>
#include "IR.h"
#include <IR-debug.h>
// Assume arr_t is defined as:
template <typename T>
using arr_t = std::vector<T>;

namespace IR {
    std::string convert_var_type(var_type type) {
        static const std::unordered_map<var_type, std::string> typesMap = {
            {var_type::UNDEFINED, "UNDEFINED"}, {var_type::BOOLEAN, "bool"}, {var_type::STRING, "str"}, {var_type::NUMBER, "num"},
            {var_type::ARRAY, "array"}, {var_type::OBJECT, "object"}, {var_type::FUNCTION, "function"},
            {var_type::ANY, "any"}, {var_type::Rule, "rule"}, {var_type::Token, "token"}
        };
        return typesMap.at(type);
    }

    std::string convert_var_assing_values(var_assign_values value) {
        static const std::unordered_map<var_assign_values, std::string> typesMap = {
            {var_assign_values::NONE, "NONE"},
            {var_assign_values::_TRUE, "TRUE"},
            {var_assign_values::_FALSE, "FALSE"},
            {var_assign_values::CURRENT_POS_COUNTER, "CURRENT_POS_COUNTER"},
            {var_assign_values::CURRENT_POS_SEQUENCE, "CURRENT_POS_SEQUENCE"}
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
            return std::string("'") + std::any_cast<char>(data) + std::string("'");
        } else if (type == condition_types::CURRENT_CHARACTER) {
            return "*pos";
        } else if (type == condition_types::NUMBER) {
            return std::to_string(std::any_cast<long long>(data));
        } else if (type == condition_types::STRING) {
            return std::string('"', 1) + std::any_cast<std::string>(data) + std::string('"', 1);
        } else if (type == condition_types::STRNCMP) {
            return std::string("!STRNCMP(pos, \"") + std::any_cast<std::string>(data) + std::string("\")");
        } else if (type == condition_types::VARIABLE) {
            return std::any_cast<std::string>(data);
        }
        static const std::unordered_map<condition_types, std::string> condTypesMap = {
            {condition_types::GROUP_OPEN, "("}, {condition_types::GROUP_CLOSE, ")"},
            {condition_types::AND, "&&"}, {condition_types::OR, "||"}, {condition_types::NOT, "!"},
            {condition_types::EQUAL, "=="}, {condition_types::NOT_EQUAL, "!="},
            {condition_types::HIGHER, ">"}, {condition_types::LOWER, "<"},
            {condition_types::HIGHER_OR_EQUAL, ">="}, {condition_types::LOWER_OR_EQUAL, "<="},
            {condition_types::LEFT_BITWISE, "<<"}, {condition_types::RIGHT_BITWISE, ">>"},
            {condition_types::BITWISE_AND, "&"}, {condition_types::CHARACTER, ""},
            {condition_types::CURRENT_CHARACTER, "CURRENT_CHARACTER"}, {condition_types::NUMBER, "NUMBER"},
            {condition_types::STRING, "STRING"}, {condition_types::STRNCMP, "STRNCMP"},
            {condition_types::VARIABLE, "VARIABLE"}
        };
        return condTypesMap.at(type);
    }

    void convertVariable(variable var, std::ostream& out, int indentLevel) {
        out << std::string(indentLevel, '\t') << convert_var_type(var.type) << " " << var.name << " = " << convert_var_assing_values(var.value) << " %" << var.assign_next_rules << ";\n";
    }

    void convertExpression(arr_t<expr> expression, std::ostream &out, int indentLevel) {
        out << std::string(indentLevel, '\t') << '(';
        for (int i = 0; i < expression.size(); i++) {
            expr current = expression[i];
            out << ' ' << conditionTypesToString(current.id, current.value) << ' ';
        }
        out << ")\n";
    }

    void convertBlock(arr_t<IR::member> block, std::ostream& out, int indentLevel) {
        out << std::string(indentLevel, '\t') << "{\n";
        convertMembers(block, out, indentLevel + 1);
        out << std::string(indentLevel, '\t') << "}\n";
    }

    void convertCondition(condition cond, std::ostream& out, int indentLevel) {
        convertExpression(cond.expression, out, indentLevel);
        convertBlock(cond.block, out, indentLevel);
    }

    void convertAccessor(accessor acc, std::ostream &out, int indentLevel) {
        out << std::string(indentLevel, '\t');
        for (auto el : acc.elements) {
            auto el_num = std::any_cast<Parser::Rule>(el.data);
            auto el_num_data = std::any_cast<obj_t>(el_num.data);
            auto main = std::any_cast<std::string>(corelib::map::get(el_num_data, "main"));
            if (el.name == Parser::Rules::accessors_group)
                out << '$';
            else if (el.name == Parser::Rules::accessors_element)
                out << '%';
            else 
                out << '^';
            out << main;
        }
        out << '\n';
    }

    void convertAssignVariable(variable_assign var, std::ostream &out, int indentLevel) {
        out << std::string(indentLevel, '\t') << var.name << " " << convert_var_assing_types(var.assign_type) << " " << convert_var_assing_values(var.value) << ";\n";
    }

    void convertMethodCall(method_call method, std::ostream &out, int indentLevel) {
        // Implement method call conversion with proper indentation
    }

    void convertMember(const member& mem, std::ostream& out, int indentLevel) {
        out << std::string(indentLevel, '\t');
        switch (mem.type)
        {
        case types::VARIABLE:
            convertVariable(std::any_cast<variable>(mem.value), out, indentLevel);
            break;
        case types::METHOD_CALL:
            convertMethodCall(std::any_cast<method_call>(mem.value), out, indentLevel);
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
            out << "do";
            convertBlock(std::any_cast<condition>(mem.value).block, out, indentLevel);
            out << "while";
            convertExpression(std::any_cast<condition>(mem.value).expression, out, indentLevel);
            break;
        case types::INCREASE_POS_COUNTER:
            out << "pos++";
            break;
        case types::ACCESSOR:
            convertAccessor(std::any_cast<accessor>(mem.value), out, indentLevel);
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
        default:
            break;
        }
        out << '\n';
    }

    void convertMembers(arr_t<member> members, std::ostream& out, int indentLevel) {
        for (auto mem : members)
            convertMember(mem, out, indentLevel);
    }

    std::string typesToString(types type) {
        static const std::unordered_map<types, std::string> typesMap = {
            {types::NONE, "NONE"}, {types::RULE, "RULE"}, {types::GROUP, "GROUP"}, {types::VARIABLE, "VARIABLE"},
            {types::IF, "IF"}, {types::WHILE, "WHILE"}, {types::DOWHILE, "DOWHILE"},
            {types::ACCESSOR, "ACCESSOR"}, {types::METHOD_CALL, "METHOD_CALL"}, {types::EXIT, "EXIT"},
            {types::BREAK_LOOP, "BREAK_LOOP"}, {types::CONTINUE_LOOP, "CONTINUE_LOOP"},
            {types::ASSIGN_VARIABLE, "ASSIGN_VARIABLE"}, {types::INCREASE_POS_COUNTER, "INCREASE_POS_COUNTER"}
        };
        return typesMap.at(type);
    }

    void printIR(const ir& representation, std::ostream& out, int indentLevel) {
        for (const auto& mem : representation.elements) {
            convertMember(mem, out, indentLevel);
        }
    }

    void outputIRToFile(ir representation, std::string filename) {
        std::ofstream file(filename);
        if (file.is_open()) {
            printIR(representation, file, 0);
            file.close();
        } else {
            std::cerr << "Unable to open file " << filename << "\n";
        }
    }

    void outputIRToConsole(const ir& representation) {
        printIR(representation, std::cout, 0);
    }
}