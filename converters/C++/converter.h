#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <any>
#include <unordered_map>
#include <internal_types.h>
#include <IR/IR.h>
#include <corelib.h>
#include <stack>
#include <logging.h>
std::string convert_var_type(IR::var_types type, arr_t<IR::var_type> data);
std::string convert_var_assing_values(IR::var_assign_values value, std::any data, std::stack<std::string> &current_pos_counter);
std::string convert_var_assing_types(IR::var_assign_types value);
std::string getCharFromEscaped(char in, bool string);
std::string conditionTypesToString(IR::condition_types type, std::any data, std::stack<std::string> &current_pos_counter);
std::string convertFunctionCall(IR::function_call call, std::stack<std::string> &current_pos_counter);
std::string convertAssign(IR::assign asgn, std::stack<std::string> &current_pos_counter);
void convertVariable(IR::variable var, std::ostringstream &out, int &indentLevel, std::stack<std::string> &current_pos_counter);
std::string convertExpression(arr_t<IR::expr> expression, bool with_braces, std::stack<std::string> &current_pos_counter);
void convertBlock(arr_t<IR::member> block, std::ostringstream &out, int &indentLevel, std::stack<std::string> &current_pos_counter);
void convertCondition(IR::condition cond, std::ostringstream &out, int &indentLevel, std::stack<std::string> &current_pos_counter);
void convertAssignVariable(IR::variable_assign var, std::ostream &out, int &indentLevel, std::stack<std::string> &current_pos_counter);
std::string convertMethodCall(IR::method_call method, std::stack<std::string> &current_pos_counter);
std::string convertDataBlock(IR::data_block dtb, int indentLevel, std::stack<std::string> &current_pos_counter);
void convertMember(const IR::member& mem, std::ostringstream &out, int &indentLevel, std::stack<std::string> &current_pos_counter);
void convertMembers(const arr_t<IR::member> &members, std::ostringstream &out, int &indentLevel, std::stack<std::string> &current_pos_counter);