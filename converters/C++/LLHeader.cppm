export module LLHeader;
import dstd;
import LLStringConvertions;
import buildLLParser;
import LLIR.API;
import LLIR;
import LexerBuilder;
import AST.Tree;
import DFA.Collection;
import std;
export class LLHeader : public LLStringConvertions {
    friend void buildLLParser(const std::filesystem::path name, const LLIR::IR &ir, const LexerBuilder &lexer_data, AST::Tree& ast);
    public:
    // header output functions
    void createIncludes(std::ostringstream &out) const;
    void createLibrary(std::ostringstream& out, std::string namespace_name) const;
    void createDefaultTypes(std::ostringstream &out) const;
    void close_library(std::ostringstream &out, std::string namespace_name) const;
    void createNamespace(std::ostringstream &out, std::string namespace_name) const;
    void createTypes(std::ostringstream &out, std::string namespace_name) const;
    void writeEnum(std::ostringstream& out, const stdu::vector<stdu::vector<std::string>>& enm) const;
    void createTokensEnum(std::ostringstream &out, const stdu::vector<stdu::vector<std::string>> &tokens) const;
    void createRulesEnum(std::ostringstream &out, const stdu::vector<stdu::vector<std::string>> &rules) const;
    void getTypesFromStdlib(std::ostringstream& out) const;
    void addTokensToString(const stdu::vector<stdu::vector<std::string>> &tokens, std::ostringstream &out) const;
    void addRulesToString(const stdu::vector<stdu::vector<std::string>> &rules, std::ostringstream &out) const;
    void createDFATypes(std::ostringstream &out) const;
    void createDFAVars(const DFA::Collection &dfas, const DFA::Collection::StateSet_t &states_set, std::ostringstream &out) const;
    void createToStringFunction(const stdu::vector<stdu::vector<std::string>> &tokens, const stdu::vector<stdu::vector<std::string>> &rules, std::ostringstream &out) const;
    void addStandardFunctionsParser(std::ostringstream &out) const;
    void convert_inclosed_map(std::ostringstream &out, LLIR::inclosed_map map) const;
    void convert_single_assignment_data(std::ostringstream &out, LLIR::var_type type, std::string name) const;
    void write_data_block(std::ostringstream &out, const LLIR::DataBlockList &dtb) const;
    void createTypesNamespace(std::ostringstream &out, const LLIR::DataBlockList &data_block_tokens, const LLIR::DataBlockList &data_block_rules) const;
    void addConstructorsLexer(std::ostringstream &out) const;
    void close_parser_header(std::ostringstream &out) const;
    void create_parser_header(std::ostringstream &out, const DFA::Collection &dfas, const DFA::Collection::StateSet_t &states_set) const;
    void create_get_namespace(std::ostringstream &out, std::string namespace_name, const LLIR::DataBlockList &data_block_tokens, const LLIR::DataBlockList &data_block_rules) const;
};