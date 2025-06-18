module LexerConverter;
import Converter.DFA;
import LLConverter;
import LexerBuilder;
import hash;
import corelib;
import logging;
import LLIR;
import AST.Tree;
import dstd;
import std;

void LexerConverter::output() {
    // 1. print DFAS
    DFAConverter dfa_converter(lexer_data.getDFAS(), &lexer_data.getDfaCompatibleTable(), namespace_name, "Lexer", "dfa_table");
    DFAConverter dfa_func_table_converter(lexer_data.getFunctionsIR().getDfas(), &lexer_data.getDfaCompatibleTable(), namespace_name, "Lexer", "dfa_func_table");
    dfa_converter.create();
    dfa_func_table_converter.create();
    out << dfa_converter.get().str();
    out << dfa_func_table_converter.get().str();
    // 2. Print First Character Dispatch Table
    out << "std::array<std::variant<::" << namespace_name << "::DFA::TokenTable, ::" << namespace_name << "::DFA::CharTable, ::" << namespace_name << "::DFA::MultiTable, " << namespace_name << "::Token_res (*) (const char*)>, " << std::to_string(std::numeric_limits<unsigned char>::max() + 1) << "> " << namespace_name << "::Lexer::first_character_dispatch_table = {\n";
    const auto &dfa_involved_table = lexer_data.getDispatchNamesInvolve();
    char c = 0;
    for (const auto &names : lexer_data.getFCDT().get()) {
        out << "\t{ ";
        std::unordered_set<std::size_t> used;
        utype::unordered_set<stdu::vector<std::string>> used_func;
        bool was_dfa = false;
        for (const auto &name : names) {
            const auto &involve_tale = dfa_involved_table.at(names);
            auto index = involve_tale.at(name);
            if (used.contains(index) || used_func.contains(name.name))
                continue;
            if (index != LexerBuilder::DFA_NOT_COMPATIBLE) {
                used.insert(index);
                // if (was_dfa)
                //     throw Error("Several DFA's in one dispatch sequence");
                // was_dfa = true;
                out << "&dfa_table_" << index;
            } else {
                used_func.insert(name.name);
                out << "&" << corelib::text::join(name.name, "_");
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
    // print tokens that are callable functions
    LLConverter converter(lexer_data.getFunctionsIR(), ast, namespace_name);
    converter.printIR(out, namespace_name);
}
void LexerConverter::outputHeader() {

}