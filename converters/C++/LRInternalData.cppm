module;
#include <vector>
#include <string>
#include <cstdlib>
#include <stack>
#include <cstddef>
export module LRInternalData;
import LRParser;
import LLIR;
class LRInternalData {
    protected:
        std::size_t max_states = 0, max_dfa_token_map_size = 0;
        LLIR::DataBlockList data_block_tokens, data_block_rules;
        std::vector<std::vector<std::string>> tokens, rules;
        LRParser::Rules rules_table;
};