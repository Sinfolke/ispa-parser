module LLHeader;
import Converter;
import LLIR;
import logging;
import corelib;
import std;
import std.compat;
void LLHeader::createIncludes(std::ostringstream &out) const {
    out << "#include <string>\n";
    out << "#include <unordered_map>\n";
    out << "#include <iterator>\n";
    out << "#include <array>\n";
    out << "#include <memory>\n";
    out << "#include <ispastdlib.hpp>\n";
}
void LLHeader::createLibrary(std::ostringstream& out, std::string namespace_name) const {


    out << "#pragma once\n";
    out << "#ifndef " << corelib::text::ToUpper(namespace_name) << "\n";
    out << "#define " << corelib::text::ToUpper(namespace_name) << "\n\n";

}
void LLHeader::createDefaultTypes(std::ostringstream &out) const {
    std::unordered_map<std::string, std::string> macros = {
        {"BOOL_TYPE", "bool"},
        {"NUM_TYPE", "double"},
        {"STR_TYPE", "std::string"},
        {"ANY_TYPE", "std::any"},
        {"ARR_TYPE", "std::vector"},
        {"OBJ_TYPE", "std::unordered_map"}
    };


    for (auto [macro, deftype] : macros) {
        auto actual_name = corelib::text::ToUpper(namespace_name) + "_" + macro;
        
        out << "#ifndef " << actual_name << "\n";
        out << "#define " << actual_name << " " << deftype << "\n";
        out << "#endif\n";
    }
}
void LLHeader::close_library(std::ostringstream &out, std::string namespace_name) const {
    out << "\n} // " << namespace_name << "\n"; // close enum
    out << "\n\n#endif // " << corelib::text::ToUpper(namespace_name) << "\n"; // close header
}
void LLHeader::createNamespace(std::ostringstream &out, std::string namespace_name) const {
    out << "namespace " << namespace_name << " {\n";
}
void LLHeader::createTypes(std::ostringstream &out, std::string namespace_name) const {
    const auto ns = corelib::text::ToUpper(namespace_name);

    out << "\tusing str_t = " << ns << "_STR_TYPE;\n";
    out << "\tusing num_t = " << ns << "_NUM_TYPE;\n";
    out << "\tusing bool_t = " << ns << "_BOOL_TYPE;\n";
    out << "\tusing any_t = " << ns << "_ANY_TYPE;\n";
    out << "\ttemplate<typename T>\n";
    out << "\tusing arr_t = " << ns << "_ARR_TYPE<T>;\n";
    out << "\ttemplate<typename Key, typename Value>\n";
    out << "\tusing obj_t = " << ns << "_OBJ_TYPE<Key, Value>;\n";
}

void LLHeader::writeEnum(std::ostringstream& out, const stdu::vector<stdu::vector<std::string>>& enm) const {
    out << "\t\t";
    for (auto it = enm.begin(); it != enm.end() - 1; it++) {
        out << corelib::text::join(*it, "_") << ", ";
    }
    out << corelib::text::join(*(enm.end() - 1), "_");
}

void LLHeader::createTokensEnum(std::ostringstream &out, const stdu::vector<stdu::vector<std::string>>& tokens) const {
    out << "\tenum class Tokens {\n";
    writeEnum(out, tokens);
    out << "\n\t};\n";
}

void LLHeader::createRulesEnum(std::ostringstream &out, const stdu::vector<stdu::vector<std::string>>& rules) const {
    out << "\tenum class Rules {\n";
    writeEnum(out, rules);
    out << "\n\t};\n";
}
void LLHeader::getTypesFromStdlib(std::ostringstream& out) const {
    out << "\tusing Rule = ISPA_STD::Node<Rules>;\n";
    out << "\tusing Rule_res = ISPA_STD::match_result<Rules>;\n";
    out << "\tusing Token = ISPA_STD::Node<Tokens>;\n";
    out << "\tusing Token_res = ISPA_STD::match_result<Tokens>;\n";
    out << "\tusing TokenFlow = ISPA_STD::TokenFlow<Tokens>;\n";
    out << "\tusing RuleSeq = ISPA_STD::Seq<Rules>;\n";
    out << "\tusing TokenSeq = ISPA_STD::Seq<Tokens>;\n";
}
void LLHeader::addTokensToString(const stdu::vector<stdu::vector<std::string>> &tokens, std::ostringstream &out) const {
    // Implement method call conversion with proper indentation
    out << "\tconstexpr const char* TokensToString(Tokens token) {\n";
    out << "\t\tswitch (token) {\n";
    for (auto token : tokens) {
        out << "\t\t\tcase Tokens::" << corelib::text::join(token, "_") << ":" << " return \"" << corelib::text::join(token, "_") << "\";\n";
    }
    out << "\t\t}\n";
    out << "\t\treturn \"NONE\";\n";
    out << "\t}\n";
}
void LLHeader::addRulesToString(const stdu::vector<stdu::vector<std::string>> &rules, std::ostringstream &out) const {
    // Implement method call conversion with proper indentation
    out << "\tconstexpr const char* RulesToString(Rules rule) {\n";
    out << "\t\tswitch (rule) {\n";
    for (auto rule : rules) {
        out << "\t\t\tcase Rules::" << corelib::text::join(rule, "_") << ":" << " return \"" << corelib::text::join(rule, "_") << "\";\n";
    }
    out << "\t\t}\n";
    out << "\t\treturn \"NONE\";\n";
    out << "\t}\n";
}
void LLHeader::createToStringFunction(const stdu::vector<stdu::vector<std::string>> &tokens, const stdu::vector<stdu::vector<std::string>> &rules, std::ostringstream &out) const {
    addTokensToString(tokens, out);
    addRulesToString(rules, out);
}
void LLHeader::createDFATypes(std::ostringstream &out) const {
    out << R"(
namespace DFA {
    constexpr size_t null_state = std::numeric_limits<size_t>::max();
    template<typename Key>
    struct Transition {
        Key symbol;
        size_t next;
        size_t accept;
    };

    template<size_t MAX, typename Key>
    struct State {
        size_t else_goto;
        size_t else_goto_accept;
        std::array<Transition<Key>, MAX> transitions;
    };
    struct SpanMultiTable;

    template<typename Key>
    struct SpanState {
        size_t else_goto;
        size_t else_goto_accept;
        ISPA_STD::Span<Transition<Key>> transitions;
    };

    using MultiKey = std::variant<
        char,
        Token_res (*)(const char*),
        ISPA_STD::Span<SpanState<Token_res (*) (const char*)>>,     // SpanCallableTokenTable
        ISPA_STD::Span<SpanState<char>>,                            // SpanCharTable
        std::unique_ptr<SpanMultiTable>                             // Recursive wrapped
    >;
    // transition types
    using CharTableTransition = Transition<char>;
    using TokenTableTransition = Transition<Tokens>;
    using CallableTokenTableTransition = Transition<Token_res (*) (const char*)>;
    using MultiTableTransition = Transition<MultiKey>;

    // state types
    template<size_t N> using CharTableState = State<N, char>;
    template<size_t N> using TokenTableState = State<N, Tokens>;
    template<size_t N> using CallableTokenState = State<N, Token_res (*) (const char*)>;
    template<size_t N> using MultiTableState = State<N, MultiKey>;

    // span state types
    using SpanCharTableState = SpanState<char>;
    using SpanTokenTableState = SpanState<Tokens>;
    using SpanCallableTokenState = SpanState<Token_res (*) (const char*)>;
    using SpanMultiTableState = SpanState<MultiKey>;

    // span types
    using SpanTokenTable = ISPA_STD::Span<SpanState<Tokens>>;
    using SpanCallableTokenTable = ISPA_STD::Span<SpanState<Token_res (*) (const char*)>>;
    using SpanCharTable = ISPA_STD::Span<SpanState<char>>;
    using SpanMultiState = ISPA_STD::Span<SpanState<MultiKey>>;

    struct SpanMultiTable {
        ISPA_STD::Span<SpanMultiState> states;
    };

    // Storage types
    template<size_t N, size_t MAX> using TokenTable = std::array<State<MAX, Tokens>, N>;
    template<size_t N, size_t MAX> using CallableTokenTable = std::array<State<MAX, Token_res (*) (const char*)>, N>;
    template<size_t N, size_t MAX> using CharTable = std::array<State<MAX, char>, N>;
    template<size_t N, size_t MAX> using MultiTable = std::array<State<MAX, MultiKey>, N>; // avoid direct recursion here
}
)";
}
void LLHeader::createDFAVars(const stdu::vector<DFA> &dfas, std::ostringstream &out) const {
    size_t count = 0;
    for (const auto &dfa : dfas) {
        out << "\n\t\t\tconst " << "DFA::" << dfa.getTypeStr(false) << '<' << dfa.getStates().size() << ", " << dfa.getMaxTransitionCount() << "> table_" << count++ << ';';
    }
    out << '\n';
}



void LLHeader::addStandardFunctionsParser(std::ostringstream &out) const {
    out << R"(
            /**
             * @param os the output stream
             * Print the ast into output stream
             */
            void printAST(std::ostream& os);
            /**
             * @param os the output stream
             * @param rule the rule to print
             * Prints a single rule into an output stream
             */
            static void printRule(std::ostream &os, const Token &token, size_t &indentLevel, bool addSpaceOnBegin);
            static void printRule(std::ostream &os, const Rule &rule, size_t &indentLevel, bool addSpaceOnBegin);
            static void printRule(std::ostream &os, const std::any& data, size_t &indentLevel, bool addSpaceOnBegin);)";
    out << "\n";
}
void LLHeader::convert_inclosed_map(std::ostringstream &out, LLIR::inclosed_map map) const {
    for (auto [key, value] : map) {
        auto [expr, type] = value;
        out << "\t\t\t" << convert_var_type(type.type, type.templ) << " " << key << ";\n";
    }
}
void LLHeader::convert_single_assignment_data(std::ostringstream &out, LLIR::var_type type, std::string name) const {
    out << "\t\tusing " << name << " = " << convert_var_type(type.type, type.templ) << ";\n";
}
void LLHeader::write_data_block(std::ostringstream &out, const LLIR::DataBlockList &dtb) const {
    for (auto [name, block] : dtb) {
        if (block.empty())
            continue;
        if (block.is_inclosed_map()) {
            out << "\t\tstruct " + corelib::text::join(name, "_") + " {\n";
            convert_inclosed_map(out, block.getInclosedMap());
            out << "\t\t};\n";
        } else {
            convert_single_assignment_data(out, block.getRegularDataBlock().second, corelib::text::join(name, "_"));
        }
    }
}
void LLHeader::createTypesNamespace(std::ostringstream &out, const LLIR::DataBlockList &data_block_tokens, const LLIR::DataBlockList &data_block_rules) const {
    out << "\tnamespace Types {\n"; 
    write_data_block(out, data_block_tokens); 
    write_data_block(out, data_block_rules); 
    out << "\t}\n";
}
void LLHeader::addConstructorsLexer(std::ostringstream &out) const {
    out << "\t\t"<< R"(Lexer(const std::string& in) : Lexer_base(in) {}
        Lexer(const char* in) : Lexer_base(in) {}
        Lexer(TokenFlow &tokens) : Lexer_base(tokens) {}
        Lexer() {})";
    out << "\n";
}
void LLHeader::close_parser_header(std::ostringstream &out) const {
    out << "\t};\n";
}
void LLHeader::create_parser_header(std::ostringstream &out, const stdu::vector<DFA> &dfas) const {
    out << "\tclass Parser : public ISPA_STD::LLParser_base<Tokens, Rules> {\n"
        << "\t\tpublic:";
        addStandardFunctionsParser(out);
    out << "\t\tprivate:";
        createDFAVars(dfas, out);
    out
        << "\t\t\tRule_res getRule(Lexer::lazy_iterator&);\n"
        << "\t\t\tRule_res getRule(Lexer::iterator&);\n"
        ;
    out
        << "\t\tvoid parseFromTokens();\n"
        << "\t\tvoid lazyParse();\n";
}
void LLHeader::create_get_namespace(std::ostringstream &out, std::string namespace_name, const LLIR::DataBlockList &data_block_tokens, const LLIR::DataBlockList &data_block_rules) const {
    out << "\n\tnamespace get {\n";
    for (const auto &[fullname, block] : data_block_tokens) {
        if (block.empty())
            continue;
        const auto name = corelib::text::join(fullname, "_");
        out << "\t\tconst ::" << namespace_name << "::" << "Types::" << name << "& " << name << "(const ::" << namespace_name << "::Token &token);\n";
        out << "\t\t::" << namespace_name << "::" << "Types::" << name << "& " << name << "(::" << namespace_name << "::Token &token);\n";
    }
    for (const auto &[fullname, block] : data_block_rules) {
        if (block.empty())
            continue;
        const auto name = corelib::text::join(fullname, "_");
        out << "\t\tconst ::" << namespace_name << "::" << "Types::" << name << "& " << name << "(const ::" << namespace_name << "::Rule &rule);\n";
        out << "\t\t::" << namespace_name << "::" << "Types::" << name << "& " << name << "(::" << namespace_name << "::Rule &rule);\n";
    }
    out << "\t}\n";
}
