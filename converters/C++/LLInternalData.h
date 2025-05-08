#pragma once
#include <string>
#include <stack>
#include <vector>
class LLInternalData {
    protected:
    // private variables used for convertion
    size_t pos_counter = 0;
    size_t indentLevel = 0;
    std::stack<size_t> pos_counter_stack;
    std::stack<std::string> current_pos_counter;
    std::vector<std::string> dynamic_pos_counter = {};
    std::vector<std::string> rule_prev_name;
    std::string rule_prev_name_str;
    std::string namespace_name;
    bool add_semicolon;
    bool has_data_block;
    bool isToken;
    bool cpp_file = true;
};