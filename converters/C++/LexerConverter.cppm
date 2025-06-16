export module LexerConverter;
import Converter;
export class LexerConverter : LexerConverter_base  {

public:
    using LexerConverter_base::LexerConverter_base;
    void output() override;
    void outputHeader() override;
};