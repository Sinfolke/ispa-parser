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
import dstd;
import std;

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

void LexerConverter::addDFASpansCpp() const {
    std::size_t count = 0;
    for (const auto &dfa : lexer_data.getDFAS()) {
        const auto span_type = dfa.getType(true);
        const std::string span_type_str = DFATypes::getSpanTypeStr(span_type, namespace_name);

        const std::string table_name = "dfa_table_" + std::to_string(count);

        out << "const ::" << namespace_name << "::" << span_type_str << " "
            << namespace_name << "::Lexer::dfa_span_" << count << " = {\n";
        if (span_type == DFA::DfaType::Multi)
            out << "\t{ ";
        out << "\t" << table_name << ".data(), " << table_name << ".size()";
        if (span_type == DFA::DfaType::Multi)
            out << " }\n";
        else
            out << "\n";
        out << "};\n";

        ++count;
    }
}
void LexerConverter::addDFASpansH() const {
    std::size_t count = 0;
    for (const auto &dfa : lexer_data.getDFAS()) {
        const std::string span_type = DFATypes(dfa).getSpanTypeStr(true, namespace_name);

        const std::string table_name = "dfa_table_" + std::to_string(count);

        h_out << "\t\tstatic const ::ISPA_STD::DFAAPI::" << span_type << " dfa_span_" << count << ";\n";

        ++count;
    }
}
void LexerConverter::output() {
    // 1. print DFAS
    StateArrayBuilder dfa_states(out, true, state_set, namespace_name, lexer_data, "Lexer");
    DFAConverter dfa_converter(lexer_data.getDFAS(), &lexer_data.getDfaCompatibleTable(), state_set.first, state_set.second, namespace_name, "Lexer", "dfa_table", true);
    DFAConverter dfa_func_table_converter(lexer_data.getFunctionsIR().getDfas(), &lexer_data.getDfaCompatibleTable(), state_set.first, state_set.second, namespace_name, "Lexer", "dfa_func_table", true);
    dfa_states.output();
    dfa_converter.create();
    dfa_func_table_converter.create();
    out << dfa_converter.get().str();
    out << dfa_func_table_converter.get().str();
    // 2. Print First Character Dispatch Table
    out << "const ISPA_STD::fcdt_table " << namespace_name << "::Lexer::first_character_dispatch_table = {\n";
    const auto &dfa_involved_table = lexer_data.getDispatchNamesInvolve();
    char c = 0;
    for (const auto &names : lexer_data.getFCDT().get()) {
        out << "\tISPA_STD::fcdt_variant { ";
        std::unordered_set<std::size_t> used;
        utype::unordered_set<stdu::vector<std::string>> used_func;
        bool was_dfa = false;
        if (names.empty())
            out << "std::monostate {} ";
        for (const auto &name : names) {
            const auto &involve_tale = dfa_involved_table.at(names);
            auto index = involve_tale.at(name);
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
        out << "}, // '" << corelib::text::getEscapedAsStr(c++, false) << "'\n";
    }
    out << "};\n";
    // print spans tables
    addDFASpansCpp();
    // 2. Print makeToken function
    out << "auto ::" << namespace_name << "::Lexer::makeToken(const char* &pos) -> Token {\n";
    out << "\tfcdt_lookup(first_character_dispatch_table, pos);\n";
    out << "}\n";
    // print tokens that are callable functions
    LLConverter converter(lexer_data.getFunctionsIR(), ast, namespace_name);
    converter.writeRules(out);
}
void LexerConverter::outputHeader() {
    StateArrayBuilder dfa_states(h_out, true, state_set, namespace_name, lexer_data, "Lexer");
    h_out << "\tclass Lexer : public ISPA_STD::Lexer_base<Tokens> {\n"
        << "\t\tpublic:\n"
        << "\t\t\tusing ISPA_STD::Lexer_base<Tokens>::Lexer_base;";
    addStandardFunctionsLexer();
    h_out << "\t\tprivate:\n"
          << "\t\t\tToken makeToken(const char*& pos);\n";
    dfa_states.outputHeader();
    for (std::size_t i = 0; i < lexer_data.getDFAS().getDFAS().size(); ++i) {
        const auto &dfa = lexer_data.getDFAS().getDFAS().at(i);
        h_out << "\t\tstatic const ::ISPA_STD::DFAAPI::" << DFATypes(dfa).getTypeStr(true, namespace_name, dfa.getStates().size()) << " dfa_table_" << i << ";\n";
    }
    addDFASpansH();
    for (std::size_t i = 0; i < lexer_data.getFunctionsIR().getDfas().getDFAS().size(); ++i) {
        const auto &dfa = lexer_data.getDFAS().getDFAS().at(i);
        h_out << "\t\tstatic const ::ISPA_STD::DFAAPI::" << DFATypes(dfa).getTypeStr(true, namespace_name, dfa.getStates().size()) << " dfa_func_table_" << i << ";\n";
    }
    // add first character dispatch table
    h_out << "\t\tstatic const ISPA_STD::fcdt_table<Tokens> first_character_dispatch_table;\n";
    h_out << "\t};\n";
}