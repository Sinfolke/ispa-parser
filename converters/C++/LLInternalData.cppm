export module LLInternalData;
import DFA;
import dstd;
import std;

export class LLInternalData {
    protected:
    // private variables used for convertion
    std::size_t pos_counter = 0;
    std::size_t indentLevel = 0;
    std::stack<std::size_t> pos_counter_stack;
    std::stack<std::string> current_pos_counter;
    stdu::vector<std::string> dynamic_pos_counter = {};
    stdu::vector<std::string> rule_prev_name;
    std::string rule_prev_name_str;
    std::string namespace_name;
    bool add_semicolon = false;
    bool has_data_block = false;
    bool isToken = false;
    bool cpp_file = true;
public:
    void setIndentLevet(std::size_t indent_level) {
        this->indentLevel = indent_level;
    }
};