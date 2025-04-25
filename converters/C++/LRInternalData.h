#include <LLInternalData.h>
#include <internal_types.h>
#include <LRParser.h>
class LRInternalData {
    protected:
        size_t max_states;
        data_block_t data_block_tokens, data_block_rules;
        std::vector<std::vector<std::string>> tokens, rules;
        LRParser::Rules rules_table;
};