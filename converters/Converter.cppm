export module Converter;
import LLIR.API;
import LLIR;
import LRParser;
import AST.Tree;
import DFA;
import fcdt;
import LexerBuilder;
import dstd;
import std;
export class LexerConverter_base {
protected:
    std::ostringstream &out;
    const LexerBuilder &lexer_data;
    const std::string &namespace_name;
public:
    LexerConverter_base(std::ostringstream &out, const LexerBuilder &lexer_data, const std::string &name) : out(out), lexer_data(lexer_data), namespace_name(name) {}
    virtual void output() = 0;
    virtual void outputHeader() = 0;
};
export class LLConverter_base {
    protected:
        // data
        stdu::vector<LLIR::Data> data;
        stdu::vector<DFA> dfas;
        stdu::vector<stdu::vector<std::string>> tokens;
        stdu::vector<stdu::vector<std::string>> rules;
        LLIR::DataBlockList data_block_tokens;
        LLIR::DataBlockList data_block_rules;
        LLIR::Nodes lexer_code;
        LLIR::variable lexer_code_access_var;
        AST::Tree &tree;
        const LexerBuilder &lexer_data;
    public:
        LLConverter_base(LLIR::IR &ir, AST::Tree &tree, const LexerBuilder &lexer_data, const LLIR::Nodes *custom_lexer_code = nullptr, const LLIR::variable *access_var = nullptr)
        : tree(tree), lexer_data(lexer_data) {
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
            data = ir.getData();
            dfas = ir.getDfas();
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
        const LexerBuilder &lexer_data;
        AST::Tree &tree;
    public:
        LRConverter_base(const LRParser &data, const LexerBuilder &lexer_data, AST::Tree &tree) : data(&data), lexer_data(lexer_data), tree(tree) {
            auto use_places = tree.getUsePlacesTable();
            auto lc = tree.getCodeForLexer();
            lexer_code = lc.first;
            return_var = lc.second;
        }
        virtual void output(std::filesystem::path filename) = 0;
};