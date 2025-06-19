export module LexerConverter;
import Converter;
import std;
export class LexerConverter : LexerConverter_base  {
    std::vector<std::size_t> token_type;
    void addStandardFunctionsLexer(std::ostringstream &out) const;
public:
    using LexerConverter_base::LexerConverter_base;
    void output() override;
    void outputHeader() override;
};