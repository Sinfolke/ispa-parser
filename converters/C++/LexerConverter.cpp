module LexerConverter;
import Converter.DFA;
import hash;
import corelib;
import dstd;
import std;

void LexerConverter::output() {
    // 1. print DFAS
    DFAConverter dfa_converter(lexer_data.getDFAS(), namespace_name, "Lexer", "dfa_table");
    DFAConverter dfa_func_table_converter(lexer_data.getFunctionDFAS(), namespace_name, "Lexer", "dfa_func_table");
    dfa_converter.create();
    dfa_func_table_converter.create();
    out << dfa_converter.get().str();
    out << dfa_func_table_converter.get().str();
    // 2. Print First Character Dispatch Table
    out << "std::array<std::variant<DFA::Token_res>, " << std::to_string(std::numeric_limits<unsigned char>::max() + 1) << "> first_character_dispatch_table = {\n\t";
    const auto &dfa_involved_table = lexer_data.getIsDfaInvolvedTable();
    std::size_t count = 0;
    for (const auto &names : lexer_data.getFCDT().get()) {
        for (const auto &name : names) {
            out << "{ ";
            if (dfa_involved_table.at(name)) {
                out << "&dfa_table_" << count++;
            } else {
                out << "&" << corelib::text::join(name, "_");
            }
            out << "},\n\t";
        }
    }
    out << "}\n";
    // 2. Print makeToken function
    //out << "::" << namespace_name << "::Lexer::makeToken(const char* &pos) {\n\t";
    //  1. Print First Character Dispatch Table
}
void LexerConverter::outputHeader() {

}
