#pragma once
#include <IR/IR.h>
#include <LRParser.h>
#include <tree.h>
class LLConverter_base {
    protected:
        // data
        use_prop_t use;
        std::vector<LLIR::member> data;
        std::vector<std::vector<std::string>> tokens;
        std::vector<std::vector<std::string>> rules;
        data_block_t data_block_tokens;
        data_block_t data_block_rules;        
        LLIR lexer_code;
        LLIR::node_ret_t lexer_code_access_var;
    public:
        LLConverter_base(LLIR &ir, Tree &tree, LLIR *custom_lexer_code = nullptr, LLIR::node_ret_t *access_var = nullptr) : lexer_code(tree.getRawTree()) {
            auto use_places = tree.getUsePlacesTable();
            auto [tokens, rules] = tree.getTokenAndRuleNames();
            tokens.insert(tokens.begin(), {"NONE"});
            rules.insert(rules.begin(), {"NONE"});
            auto [data_block_tokens, data_block_rules] = tree.get_data_blocks(ir);
            this->tokens = tokens;
            this->rules = rules;
            this->data_block_tokens = data_block_tokens;
            this->data_block_rules = data_block_rules;
            if (custom_lexer_code == nullptr || access_var == nullptr) {
                auto lc = tree.getCodeForLexer(use_places);            
                this->lexer_code = lc.code;
                this->lexer_code_access_var = lc.success_var;
            } else {
                this->lexer_code = *custom_lexer_code;
                this->lexer_code_access_var = *access_var;
            }
            this->use = tree.accamulate_use_data_to_map();
            this->data = std::move(ir.getDataRef());
        }
        virtual void outputIR(std::string filename) = 0;
        auto getDataBlockToken() {
            return data_block_tokens;
        }
        auto getDataBlockRules() {
            return data_block_rules;
        }
};
class LRConverter_base {
    protected:
        // data
        use_prop_t use;
        const LRParser* data;        
        LLIR lexer_code;
        LLIR::node_ret_t success_var;
        Tree* tree;
    public:
        LRConverter_base(const LRParser &data, Tree &tree) : lexer_code(tree.getRawTree()), data(&data), tree(&tree) {
            auto use_places = tree.getUsePlacesTable();
            auto lc = tree.getCodeForLexer(use_places);
            lexer_code = lc.code;
            success_var = lc.success_var;
            use = tree.accamulate_use_data_to_map();
        }
        virtual void output(std::string filename) = 0;
};