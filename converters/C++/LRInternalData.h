#include <LLInternalData.h>
#include <internal_types.h>
#include <LRParser.h>
class LRInternalData {
    protected:
        size_t max_states, max_dfa_token_map_size = 0;
        data_block_t data_block_tokens, data_block_rules;
        std::vector<std::vector<std::string>> tokens, rules;
        LRParser::Rules rules_table;
};