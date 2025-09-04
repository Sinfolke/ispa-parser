export module Converter;
import LLIR.API;
import LLIR;
import LRParser;
import AST.Tree;
import fcdt;
import LexerBuilder;
import dstd;
import std;
export class LexerConverter_base {
protected:
    std::ostringstream &out, &h_out;
    const LexerBuilder &lexer_data;
    const std::string &namespace_name;
    AST::Tree &ast;
public:
    LexerConverter_base(AST::Tree &ast, std::ostringstream &out, std::ostringstream &h_out, const LexerBuilder &lexer_data, const std::string &name)
    : ast(ast), out(out), h_out(h_out), lexer_data(lexer_data), namespace_name(name) {}
    virtual void output() = 0;
    virtual void outputHeader() = 0;
};
export class LLConverter_base {
    protected:
        // data
        stdu::vector<stdu::vector<std::string>> tokens;
        stdu::vector<stdu::vector<std::string>> rules;
        LLIR::DataBlockList data_block_tokens;
        LLIR::DataBlockList data_block_rules;
        const LLIR::IR &ir;
        const AST::Tree &tree;
    public:
        LLConverter_base(const LLIR::IR &ir, AST::Tree &tree)
        : tree(tree), ir(ir) {
            auto use_places = tree.getUsePlacesTable();
            tokens = tree.getTerminals();
            rules = tree.getNonTerminals();
            tokens.insert(tokens.begin(), {"NONE"});
            rules.insert(rules.begin(), {"NONE"});
            data_block_tokens = ir.getDataBlocksTerminals();
            data_block_rules = ir.getDataBlocksNonTerminals();
        }
        auto getDataBlockToken() {
            return data_block_tokens;
        }
        auto getDataBlockRules() {
            return data_block_rules;
        }
        auto& getTokens() {
            return tokens;
        }
        auto& getRules() {
            return rules;
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