module;
export module LLConverter;
import Converter;
import corelib;
import logging;
import dstd;
import AST.Tree;
import LLIR.API;
import LLIR;
import LLHeader;
import LexerBuilder;
import buildLLParser;
import DFAS;
import fcdt;
import std;
export class LLConverter : public LLConverter_base, public LLHeader {
    friend void buildLLParser(const std::filesystem::path name, const LLIR::IR &ir, const LexerBuilder &lexer_data, AST::Tree& ast);
    void outputHeader(std::ostringstream &out, const std::string &filename);
    
    // cpp output functions
    void convertVariable(LLIR::variable var, std::ostringstream &out);
    void convertBlock(stdu::vector<LLIR::member> block, std::ostringstream &out);
    void convertCondition(LLIR::condition cond, std::ostringstream &out);
    void convertAssignVariable(LLIR::variable_assign var, std::ostringstream &out);
    void convertSwitch(const LLIR::switch_statement &statement, std::ostringstream &out);
    void convertMember(const LLIR::member& mem, std::ostringstream &out);
    void convertMembers(const stdu::vector<LLIR::member> &members, std::ostringstream &out);

public:
    LLConverter(const LLIR::IR &ir, AST::Tree &tree, const std::string &name) : LLConverter_base(ir, tree) {
        namespace_name = name;
        current_pos_counter.emplace("pos");
    }
    ~LLConverter() {}
    void convertData(std::ostringstream &out);
    void addDFATables(std::ostringstream &out, const std::pair<DFAS::StateSet, DFAS::StateSetLocationMap> &states_pair);
    void writeRules(std::ostringstream &out);
    void addHeader(std::ostringstream &out);
    void addStandardFunctionsLexer(std::ostringstream &out);
    void addGetRuleFunction(std::ostringstream &out);
    void addparseFromFunctions(std::ostringstream &out);
    void addStandardFunctionsParser(std::ostringstream &out);
    void addGetFunctions(std::ostringstream &out, const LLIR::DataBlockList &datablocks_tokens, const LLIR::DataBlockList &datablocks_rules);
};