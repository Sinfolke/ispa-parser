#include <LLInternalData.h>
#include <LRParser.h>
class LRInternalData {
    protected:
        size_t max_states, max_dfa_token_map_size = 0;
        LLIR_old::DataBlockList data_block_tokens, data_block_rules;
        std::vector<std::vector<std::string>> tokens, rules;
        LRParser::Rules rules_table;
};