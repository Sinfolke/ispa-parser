export module Converter;
import LLIR;
import LRParser;
import AST.Tree;
import dstd;
import std;
export class LLConverter_base {
    protected:
        // data
        stdu::vector<LLIR::Data> data;
        stdu::vector<stdu::vector<std::string>> tokens;
        stdu::vector<stdu::vector<std::string>> rules;
        LLIR::DataBlockList data_block_tokens;
        LLIR::DataBlockList data_block_rules;
        LLIR::Nodes lexer_code;
        LLIR::variable lexer_code_access_var;
        AST::Tree *tree;
    public:
        LLConverter_base(LLIR::IR &ir, AST::Tree &tree, const LLIR::Nodes *custom_lexer_code = nullptr, const LLIR::variable *access_var = nullptr) : tree(&tree) {
            auto use_places = tree.getUsePlacesTable();
            tokens = tree.getTerminals();
            rules = tree.getNonTerminals();
            tokens.insert(tokens.begin(), {"NONE"});
            rules.insert(rules.begin(), {"NONE"});
            data_block_tokens = ir.getDataBlocksTerminals();
            data_block_rules = ir.getDataBlocksNonTerminals();
            if (custom_lexer_code == nullptr || access_var == nullptr) {
                auto lc = tree.getCodeForLexer();
                lexer_code = lc.first;
                lexer_code_access_var = lc.second;
            } else {
                lexer_code = *custom_lexer_code;
                lexer_code_access_var = *access_var;
            }
            this->data = ir.getData();
        }
        virtual void outputIR(std::filesystem::path filename) = 0;
        auto getDataBlockToken() {
            return data_block_tokens;
        }
        auto getDataBlockRules() {
            return data_block_rules;
        }
};
export class LRConverter_base {
    protected:
        // data
        const LRParser* data;
        LLIR::Nodes lexer_code;
        LLIR::variable return_var;
        AST::Tree * tree;
    public:
        LRConverter_base(const LRParser &data, AST::Tree &tree) : data(&data), tree(&tree) {
            auto use_places = tree.getUsePlacesTable();
            auto lc = tree.getCodeForLexer();
            lexer_code = lc.first;
            return_var = lc.second;
        }
        virtual void output(std::filesystem::path filename) = 0;
};