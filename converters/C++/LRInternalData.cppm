export module LRInternalData;
import LRParser;
import LLIR.API;
import dstd;
import std;
export class LRInternalData {
    protected:
        std::size_t max_states = 0, max_dfa_token_map_size = 0;
        LLIR::DataBlockList data_block_tokens, data_block_rules;
        stdu::vector<stdu::vector<std::string>> tokens, rules;
        LRParser::Rules rules_table;
};