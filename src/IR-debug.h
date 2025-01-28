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
    // Function to print the type enum as a string
    std::string typesToString(types type) {
        static const std::unordered_map<types, std::string> typesMap = {
            {types::RULE, "RULE"}, {types::GROUP, "GROUP"}, {types::VARIABLE, "VARIABLE"},
            {types::IF, "IF"}, {types::WHILE, "WHILE"}, {types::DOWHILE, "DOWHILE"},
            {types::ACCESSOR, "ACCESSOR"}, {types::METHOD_CALL, "METHOD_CALL"}, {types::EXIT, "EXIT"},
            {types::BREAK_LOOP, "BREAK_LOOP"}, {types::CONTINUE_LOOP, "CONTINUE_LOOP"},
            {types::ASSIGN_VARIABLE, "ASSIGN_VARIABLE"}, {types::INCREASE_POS_COUNTER, "INCREASE_POS_COUNTER"}
        };
        return typesMap.at(type);
    }

    // Function to print the condition type enum as a string
    std::string conditionTypesToString(condition_types type) {
        static const std::unordered_map<condition_types, std::string> condTypesMap = {
            {condition_types::GROUP_OPEN, "GROUP_OPEN"}, {condition_types::GROUP_CLOSE, "GROUP_CLOSE"},
            {condition_types::AND, "AND"}, {condition_types::OR, "OR"}, {condition_types::NOT, "NOT"},
            {condition_types::EQUAL, "EQUAL"}, {condition_types::NOT_EQUAL, "NOT_EQUAL"},
            {condition_types::HIGHER, "HIGHER"}, {condition_types::LOWER, "LOWER"},
            {condition_types::HIGHER_OR_EQUAL, "HIGHER_OR_EQUAL"}, {condition_types::LOWER_OR_EQUAL, "LOWER_OR_EQUAL"},
            {condition_types::LEFT_BITWISE, "LEFT_BITWISE"}, {condition_types::RIGHT_BITWISE, "RIGHT_BITWISE"},
            {condition_types::BITWISE_AND, "BITWISE_AND"}, {condition_types::CHARACTER, "CHARACTER"},
            {condition_types::CURRENT_CHARACTER, "CURRENT_CHARACTER"}, {condition_types::NUMBER, "NUMBER"},
            {condition_types::STRING, "STRING"}, {condition_types::STRNCMP, "STRNCMP"},
            {condition_types::VARIABLE, "VARIABLE"}
        };
        return condTypesMap.at(type);
    }

    // Function to print a variable object
    void printVariable(const variable& var, std::ostream& out, const std::string& indent) {
        out << indent << "Type: " << static_cast<int>(var.type);
        out << indent << ", Name: " << var.name;
        out << indent << ", Value: " << static_cast<int>(var.value);
        out << indent << ", Assign Next Rules: \n" << var.assign_next_rules << "\n";
    }

    // Function to print a variable_assign object
    void printVariableAssign(const variable_assign& var_assign, std::ostream& out, const std::string& indent) {
        out << indent << "Name: " << var_assign.name << "";
        out << indent << ", Assign Type: " << static_cast<int>(var_assign.assign_type);
        out << indent << ", Value: " << static_cast<int>(var_assign.value) << "\n";
    }

    // Function to print a method_call object
    void printMethodCall(const method_call& method, std::ostream& out, const std::string& indent) {
        out << indent << "Method Call: \n";
        out << indent << "  Var Name: " << method.var_name << "\n";
    }

    // Function to print an accessor object
    void printAccessor(const accessor& acc, std::ostream& out, const std::string& indent) {
        out << indent << "Accessor: \n";
        out << indent << "  Qualifier: " << acc.qualifier << "\n";
        out << indent << "  Elements: \n";
        for (const auto& el : acc.elements) {
            out << indent << "    Rule Name: " << Parser::RulesToString(el.name) << "\n";
        }
    }

    // Function to print an expression object
    void printExpr(const expr& expression, std::ostream& out, const std::string& indent) {
        out << indent << "Expression: " << conditionTypesToString(expression.id);
        if (expression.value.has_value()) {
            try {
                out << " Value: " << std::any_cast<std::string>(expression.value);
            } catch (const std::bad_any_cast&) {
                out << " (non-string value)";
            }
        }
        out << "\n";
    }

    // Function to print a condition object
    void printCondition(const condition& cond, std::ostream& out, int indentLevel);

    // Function to print a member object
    void printMember(const member& mem, std::ostream& out, int indentLevel) {
        std::string indent(indentLevel * 2, ' ');
        out << indent << "Type: " << typesToString(mem.type);
        if (mem.type == types::VARIABLE) {
            printVariable(std::any_cast<variable>(mem.value), out, indent);
        } else if (mem.type == types::ASSIGN_VARIABLE) {
            printVariableAssign(std::any_cast<variable_assign>(mem.value), out, indent);
        } else if (mem.type == types::METHOD_CALL) {
            printMethodCall(std::any_cast<method_call>(mem.value), out, indent);
        } else if (mem.type == types::ACCESSOR) {
            printAccessor(std::any_cast<accessor>(mem.value), out, indent);
        } else if (mem.value.type() == typeid(condition)) {
            out << indent << "Condition:\n";
            printCondition(std::any_cast<condition>(mem.value), out, indentLevel + 1);
        } else if (mem.value.type() == typeid(std::string)) {
            out << indent << "Value: " << std::any_cast<std::string>(mem.value) << "\n";
        }
        // Add handling for other types as needed
    }

    // Function to print a condition object
    void printCondition(const condition& cond, std::ostream& out, int indentLevel) {
        std::string indent(indentLevel * 2, ' ');
        out << indent << "Condition Expressions:\n";
        for (const auto& expr : cond.expression) {
            out << indent << "  ";
            printExpr(expr, out, indent);
        }
        out << indent << "Condition Block:\n";
        for (const auto& mem : cond.block) {
            printMember(mem, out, indentLevel + 1);
        }
    }

    // Function to print the IR structure
    void printIR(const ir& representation, std::ostream& out, int indentLevel = 0) {
        for (const auto& mem : representation.elements) {
            printMember(mem, out, indentLevel);
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