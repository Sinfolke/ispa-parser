module LexerConverter;
import Converter.DFA;
import DFA;
import LLConverter;
import LexerBuilder;
import StateArrayBuilder;
import hash;
import corelib;
import logging;
import LLIR;
import AST.Tree;
import DFATypes;
import DFASpans;
import dstd;
import std;
import cpuf.op;
import cpuf.printf;
void LexerConverter::addStandardFunctionsLexer() const {
    h_out << R"(
        /**
         * @param os the output stream
         * Print the tokens into an output stream
         */
        void printTokens(std::ostream& os);
        /**
         * @param os the output stream
         * @param token the token to print
         * Prints a single token into an output stream
         */
        static void printToken(std::ostream& os, const Token& token);)";
    out << "\n";
}
void LexerConverter::output() {
    // 1. print DFAS
    // for (const auto &[a, b] : lexer_data.getDfaCompatibleTable()) {
    //     cpuf::printf("({}, {})", a, b);
    // }
    StateArrayBuilder dfa_states(out, true, state_set, namespace_name, lexer_data.getDFAS(), &lexer_data.getDfaCompatibleTable(), "Lexer");
    DFAConverter dfa_converter(lexer_data.getDFAS(), &lexer_data.getDfaCompatibleTable(), state_set, namespace_name, "Lexer", "dfa_table", true);
    DFAConverter dfa_func_table_converter(lexer_data.getFunctionsIR().getDfas(), &lexer_data.getDfaCompatibleTable(), state_set, namespace_name, "Lexer", "dfa_func_table", true);
    DFASpans dfa_spans(out, namespace_name, lexer_data.getDFAS(), &lexer_data.getDfaCompatibleTable());
    dfa_states.output();
    dfa_converter.create();
    dfa_func_table_converter.create();
    out << dfa_converter.get().str();
    out << dfa_func_table_converter.get().str();
    // print spans tables
    dfa_spans.output(true, "Lexer");
    // 2. Print First Character Dispatch Table
    out << "const ISPA_STD::fcdt_table<::" << namespace_name << "::Tokens> " << namespace_name << "::Lexer::first_character_dispatch_table = {\n";
    const auto &dfa_involved_table = lexer_data.getDispatchNamesInvolve();
    unsigned char c = std::numeric_limits<unsigned char>::min();
    for (const auto &names : lexer_data.getFCDT().get()) {
        out << "\tISPA_STD::fcdt_variant<::" << namespace_name << "::Tokens> { ";
        std::unordered_set<std::size_t> used;
        utype::unordered_set<stdu::vector<std::string>> used_func;
        bool was_dfa = false;
        if (names.empty())
            out << "std::monostate {} ";
        for (const auto &name : names) {
            const auto &involve_table = dfa_involved_table.at(names);
            auto index = involve_table.at(name);
            if (used.contains(index) || used_func.contains(name))
                continue;
            if (index != LexerBuilder::DFA_NOT_COMPATIBLE) {
                used.insert(index);
                // if (was_dfa)
                //     throw Error("Several DFA's in one dispatch sequence");
                // was_dfa = true;
                out << "dfa_span_" << index;
            } else {
                used_func.insert(name);
                out << "&" << corelib::text::join(name, "_");
            }
            out << ", ";
        }
        out << "}, // '" << corelib::text::getEscapedAsStr(c++, false) << "', " << names << "\n";
    }
    out << "};\n";
    // 2. Print makeToken function
    out << "auto ::" << namespace_name << "::Lexer::makeToken(const char* &pos) -> Token {\n";
    out << "\treturn fcdt_lookup(first_character_dispatch_table, pos);\n";
    out << "}\n";
    // print tokens that are callable functions
    LLConverter converter(lexer_data.getFunctionsIR(), ast, namespace_name);
    converter.writeRules(out);
}
void LexerConverter::outputHeader() {
    StateArrayBuilder dfa_states(h_out, true, state_set, namespace_name, lexer_data.getDFAS(), &lexer_data.getDfaCompatibleTable(), "Lexer");
    DFASpans dfa_spans(h_out, namespace_name, lexer_data.getDFAS(), &lexer_data.getDfaCompatibleTable());
    h_out << "\tclass Lexer : public ISPA_STD::Lexer_base<Tokens> {\n"
        << "\t\tpublic:\n"
        << "\t\t\tusing ISPA_STD::Lexer_base<Tokens>::Lexer_base;";
    addStandardFunctionsLexer();
    h_out << "\t\tprivate:\n"
          << "\t\t\tToken makeToken(const char*& pos);\n";
    dfa_states.outputHeader();
    for (std::size_t i = 0; i < lexer_data.getDFAS().getDFAS().size(); ++i) {
        const auto &dfa = lexer_data.getDFAS().getDFAS().at(i);
        h_out << "\t\tstatic const ::ISPA_STD::DFAAPI::" << DFATypes(dfa).getTypeStr(true, &lexer_data.getDfaCompatibleTable(), namespace_name, dfa.getStates().size()) << " dfa_table_" << i << ";\n";
    }
    dfa_spans.outputH(true);
    for (std::size_t i = 0; i < lexer_data.getFunctionsIR().getDfas().getDFAS().size(); ++i) {
        const auto &dfa = lexer_data.getDFAS().getDFAS().at(i);
        h_out << "\t\tstatic const ::ISPA_STD::DFAAPI::" << DFATypes(dfa).getTypeStr(true, &lexer_data.getDfaCompatibleTable(), namespace_name, dfa.getStates().size()) << " dfa_func_table_" << i << ";\n";
    }
    // add first character dispatch table
    h_out << "\t\tstatic const ISPA_STD::fcdt_table<Tokens> first_character_dispatch_table;\n";
    // close
    h_out << "\t};\n";
}