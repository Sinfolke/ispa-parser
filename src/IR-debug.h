#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <any>
#include <unordered_map>
#include <internal_types.h>
#include <IR.h>
#include <corelib.h>
#include <stack>

namespace IR {
    std::string convert_var_type(var_types type);
    std::string convert_var_assing_values(var_assign_values value, std::any data, std::stack<std::string> &current_pos_counter);
    std::string convert_var_assing_types(var_assign_types value);
    std::string getCharFromEscaped(char in, bool string);
    std::string conditionTypesToString(condition_types type, std::any data, std::stack<std::string> &current_pos_counter);
    std::string convertFunctionCall(function_call call, std::stack<std::string> &current_pos_counter);
    std::string convertAssign(assign asgn, std::stack<std::string> &current_pos_counter);
    std::string convertAccessor(accessor acc, std::stack<std::string> &current_pos_counter);
    void convertVariable(variable var, std::ostream& out, int &indentLevel, std::stack<std::string> &current_pos_counter);
    std::string convertExpression(arr_t<expr> expression, bool with_braces, std::stack<std::string> &current_pos_counter);
    void convertBlock(arr_t<IR::member> block, std::ostream& out, int &indentLevel, std::stack<std::string> &current_pos_counter);
    void convertCondition(condition cond, std::ostream& out, int &indentLevel, std::stack<std::string> &current_pos_counter);
    void convertAssignVariable(variable_assign var, std::ostream &out, int &indentLevel, std::stack<std::string> &current_pos_counter);
    std::string convertMethodCall(method_call method, std::stack<std::string> &current_pos_counter);
    std::string convertDataBlock(data_block dtb, int indentLevel, std::stack<std::string> &current_pos_counter);
    void convertMember(const member& mem, std::ostream& out, int &indentLevel, std::stack<std::string> &current_pos_counter);
    void convertMembers(arr_t<member> members, std::ostream& out, int &indentLevel, std::stack<std::string> &current_pos_counter);
    void printIR(const ir& representation, std::ostream& out, int &indentLevel);
    void outputIRToFile(ir representation, std::string filename);
    void outputIRToConsole(const ir& representation);
    std::string typesToString(types t);
}