module LexerConverter;
import Converter.DFA;
import hash;
import corelib;
import dstd;
import std;

void LexerConverter::output() {
    // 1. print DFAS
    DFAConverter dfa_converter(lexer_data.getDFAS(), &lexer_data.getIsDfaInvolvedTable(), namespace_name, "Lexer", "dfa_table");
    DFAConverter dfa_func_table_converter(lexer_data.getFunctionDFAS(), &lexer_data.getIsDfaInvolvedTable(), namespace_name, "Lexer", "dfa_func_table");
    dfa_converter.create();
    dfa_func_table_converter.create();
    out << dfa_converter.get().str();
    out << dfa_func_table_converter.get().str();
    // 2. Print First Character Dispatch Table
    out << "std::array<std::variant<::" << namespace_name << "::DFA::TokenTable, ::" << namespace_name << "::DFA::CharTable, ::" << namespace_name << "::DFA::MultiTable, " << namespace_name << "::Token_res (*) (const char*)>, " << std::to_string(std::numeric_limits<unsigned char>::max() + 1) << "> " << namespace_name << "::Lexer::first_character_dispatch_table = {\n";
    const auto &dfa_involved_table = lexer_data.getIsDfaInvolvedTable();
    char c = 0;
    for (const auto &names : lexer_data.getFCDT().get()) {
        out << "\t{ ";
        for (const auto &name : names) {
            auto index = dfa_involved_table.at(name);
            if (index != std::numeric_limits<std::size_t>::max()) {
                out << "&dfa_table_" << index;
            } else {
                out << "&" << corelib::text::join(name, "_");
            }
            out << ", ";
        }
        out << "}, // '" << corelib::text::getEscapedAsStr(c++, false) << "'\n";
    }
    out << "};\n";
    // 2. Print makeToken function
    out << "::" << namespace_name << "::Lexer::makeToken(const char* &pos) {\n";
    out << "\tfcdt_lookup<DFA::CharTable, DFA::TokenTable, DFA::MultiTable, DFA::Transition>(first_character_dispatch_table, pos);\n";
    out << "}\n";
}
void LexerConverter::outputHeader() {

}
