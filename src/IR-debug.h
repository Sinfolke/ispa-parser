#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <any>
#include <unordered_map>
#include <internal_types.h>
#include <IR.h>
#include <corelib.h>

namespace IR {
    std::string convert_var_type(var_types type);
    std::string convert_var_assing_values(var_assign_values value);
    std::string convert_var_assing_types(var_assign_types value);
    std::string conditionTypesToString(condition_types type, std::any data);
    std::string convertFunctionCall(function_call call);
    std::string convertAssign(assign asgn);
    void convertVariable(variable var, std::ostream& out, int &indentLevel);
    std::string convertExpression(arr_t<expr> expression, bool with_braces);
    void convertBlock(arr_t<IR::member> block, std::ostream& out, int &indentLevel);
    void convertCondition(condition cond, std::ostream& out, int &indentLevel);
    std::string convertAccessor(accessor acc);
    void convertAssignVariable(variable_assign var, std::ostream &out, int &indentLevel);
    std::string convertMethodCall(method_call method);
    void convertMember(const member& mem, std::ostream& out, int &indentLevel);
    void convertMembers(arr_t<member> members, std::ostream& out, int &indentLevel);
    std::string typesToString(types type);
    void printIR(const ir& representation, std::ostream& out, int &indentLevel);
    void outputIRToFile(ir representation, std::string filename);
    void outputIRToConsole(const ir& representation);
}