#pragma once
#include <IR/IR.h>
#include <LRParser.h>
#include <tree.h>
class LLConverter_base {
    protected:
        // data
        use_prop_t use;
        std::vector<LLIR::member> data;
        std::vector<std::string> tokens;
        std::vector<std::string> rules;
        data_block_t data_block_tokens;
        data_block_t data_block_rules;        
        LLIR lexer_code;
        LLIR::node_ret_t lexer_code_access_var;

    public:
        LLConverter_base(LLIR &ir, Tree &tree) : lexer_code(tree.getRawTree()) {
            auto use_places = tree.getUsePlacesTable();
            auto lc = tree.getCodeForLexer(use_places);
            auto [tokens, rules] = tree.getTokenAndRuleNames();
            auto [data_block_tokens, data_block_rules] = tree.get_data_blocks(ir);
            this->tokens = tokens;
            this->rules = rules;
            this->data_block_tokens = data_block_tokens;
            this->data_block_rules = data_block_rules;
            this->lexer_code = std::move(lc.code);
            this->lexer_code_access_var = lc.success_var;
            this->use = tree.accamulate_use_data_to_map();
            this->data = std::move(ir.getDataRef());
        }
        virtual void outputIR(std::string filename) = 0;
};
class LRConverter_base {
    protected:
        // data
        use_prop_t use;
        LRParser data;        
        LLIR lexer_code;
        Tree* tree;
    public:
        LRConverter_base(LRParser &data, Tree &tree) : lexer_code(tree.getRawTree()), data(data), tree(&tree) {
            auto use_places = tree.getUsePlacesTable();
            auto lc = tree.getCodeForLexer(use_places);
            this->lexer_code = std::move(lc.code);
            this->use = tree.accamulate_use_data_to_map();
        }
        virtual void output(std::string filename) = 0;
};