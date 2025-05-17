module;
#include <filesystem>
export module Converter;
import LLIR;
import LRParser;
import ASTPass;
export class LLConverter_base {
    protected:
        // data
        std::vector<LLIR_old::Data> data;
        std::vector<std::vector<std::string>> tokens;
        std::vector<std::vector<std::string>> rules;
        LLIR_old::DataBlockList data_block_tokens;
        LLIR_old::DataBlockList data_block_rules;        
        LLIR_old lexer_code;
        LLIR_old::variable lexer_code_access_var;
        ASTPass* tree;
    public:
        LLConverter_base(LLIR_old &ir, ASTPass &tree, const LLIR_old *custom_lexer_code = nullptr, const LLIR_old::variable *access_var = nullptr) : lexer_code(tree), tree(&tree) {
            auto use_places = tree.getUsePlacesTable();
            tokens = tree.getTerminals();
            rules = tree.getNonTerminals();
            tokens.insert(tokens.begin(), {"NONE"});
            rules.insert(rules.begin(), {"NONE"});
            data_block_tokens = ir.getDataBlocksTerminals();
            data_block_rules = ir.getDataBlocksNonTerminals();
            if (custom_lexer_code == nullptr || access_var == nullptr) {
                auto lc = tree.getCodeForLexer();            
                lexer_code = lc.code;
                lexer_code_access_var = lc.success_var;
            } else {
                lexer_code = *custom_lexer_code;
                lexer_code_access_var = *access_var;
            }
            this->data = std::move(ir.getData());
        }
        virtual void outputIR(std::filesystem::path filename) = 0;
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
        const LRParser* data;        
        LLIR_old lexer_code;
        LLIR_old::variable success_var;
        ASTPass* tree;
    public:
        LRConverter_base(const LRParser &data, ASTPass &tree) : lexer_code(tree), data(&data), tree(&tree) {
            auto use_places = tree.getUsePlacesTable();
            auto lc = tree.getCodeForLexer();
            lexer_code = lc.code;
            success_var = lc.success_var;
        }
        virtual void output(std::filesystem::path filename) = 0;
};