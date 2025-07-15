export module LexerConverter;
import Converter;
import AST.API;
import AST.Tree;
import LexerBuilder;
import DFAS;
import std;
export class LexerConverter : LexerConverter_base  {
    std::vector<std::size_t> token_type;
    DFAS::StateSet_t state_set;
    void addStandardFunctionsLexer() const;
    void printTransitionsSeparately() const;
    void addDFASpansCpp() const;
    void addDFASpansH() const;
public:
    LexerConverter(AST::Tree &ast, std::ostringstream &out, std::ostringstream &h_out, const LexerBuilder &lexer_data, const std::string &name)
        : LexerConverter_base(ast, out, h_out, lexer_data, name), state_set(lexer_data.getStateSet()) {}
    using LexerConverter_base::LexerConverter_base;
    void output() override;
    void outputHeader() override;
};