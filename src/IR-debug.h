#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <any>
#include <typeinfo>
#include <unordered_map>
#include <iomanip>
#include "IR.h"

// Assume arr_t is defined as:
template <typename T>
using arr_t = std::vector<T>;

namespace IR {
    std::string convert_var_type(var_type type);
    // Function to convert enum to string using a map
    std::string convert_var_assing_values(var_assign_values value);
    // Function to print the condition type enum as a string
    std::string conditionTypesToString(condition_types type, std::any data);
    void convertVariable(variable var, std::ostream& out);
    void convertCondition(condition cond, std::ostream& out);
    std::string typesToString(types type);
    void convertMember(const member& mem, std::ostream& out);
    void convertMembers(arr_t<member> members, std::ostream& out);
    void printIR(const ir& representation, std::ostream& out, int indentLevel);
    void outputIRToFile(const ir& representation, const std::string& filename);
    // Function to output the IR to the console
    void outputIRToConsole(const ir& representation);

    std::string convert_var_type(var_type type) {
        static const std::unordered_map<var_type, std::string> typesMap = {
            {var_type::UNDEFINED, "UNDEFINED"}, {var_type::BOOLEAN, "bool"}, {var_type::STRING, "str"}, {var_type::NUMBER, "num"},
            {var_type::ARRAY, "array"}, {var_type::OBJECT, "object"}, {var_type::FUNCTION, "function"},
            {var_type::ANY, "any"}, {var_type::Rule, "rule"}, {var_type::Token, "token"}
        };
        return typesMap.at(type);
    }
    // Function to convert enum to string using a map
    std::string convert_var_assing_values(var_assign_values value) {
        static const std::map<var_assign_values, std::string> typesMap = {
            {var_assign_values::NONE, "NONE"},
            {var_assign_values::_TRUE, "TRUE"},
            {var_assign_values::_FALSE, "FALSE"},
            {var_assign_values::CURRENT_POS_COUNTER, "CURRENT_POS_COUNTER"},
            {var_assign_values::CURRENT_POS_SEQUENCE, "CURRENT_POS_SEQUENCE"}
        };
        return typesMap.at(value);
    }

    // Function to print the condition type enum as a string
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
            return "STRNCMP";
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
    void convertVariable(variable var, std::ostream& out) {
        out << convert_var_type(var.type) << " " << var.name << " = " << convert_var_assing_values(var.value) << " %" << var.assign_next_rules << ";\n";
    }
    void convertCondition(condition cond, std::ostream& out) {
        out << '(';
        for (int i = 0; i < cond.expression.size(); i++) {
            expr expression = cond.expression[i];
                out << ' ' << conditionTypesToString(expression.id, expression.value) << ' ';
        }
        out << ") {\n";
        convertMembers(cond.block, out);
        out << "}";
    }
    void convertAccessor(accessor acc, std::ostream &out) {
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
    }
    void convertMethodCall(method_call method, std::ostream &out) {

    }
    // Function to print a member object
    void convertMember(const member& mem, std::ostream& out) {
        switch (mem.type)
        {
        case types::VARIABLE:
            convertVariable(std::any_cast<variable>(mem.value), out);
            break;
        case types::METHOD_CALL:
            convertMethodCall(std::any_cast<method_call>(mem.value), out);
            break;
        case types::IF:
            out << "if ";
            convertCondition(std::any_cast<condition>(mem.value), out);
            break;
        case types::WHILE:
            out << "while ";
            convertCondition(std::any_cast<condition>(mem.value), out);
            break;
        case types::INCREASE_POS_COUNTER:
            out << "pos++";
            break;
        case types::ACCESSOR:
            convertAccessor(std::any_cast<accessor>(mem.value), out);
            break;
        default:
            break;
        }
        out << '\n';
        // Add handling for other types as needed
    }
    void convertMembers(arr_t<member> members, std::ostream& out) {
        for (auto mem : members)
            convertMember(mem, out);
    }
    // Function to print the type enum as a string
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

    // // Function to print the IR structure
    void printIR(const ir& representation, std::ostream& out) {
        for (const auto& mem : representation.elements) {
            convertMember(mem, out);
        }
    }

    // Function to output the IR to a file
    void outputIRToFile(const ir& representation, const std::string& filename) {
        std::ofstream file(filename);
        if (file.is_open()) {
            printIR(representation, file);
            file.close();
        } else {
            std::cerr << "Unable to open file " << filename << "\n";
        }
    }

    // Function to output the IR to the console
    void outputIRToConsole(const ir& representation) {
        printIR(representation, std::cout);
    }
}