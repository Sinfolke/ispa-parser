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
import fcdt;
import std;
export class LLConverter : public LLConverter_base, public LLHeader {
    void outputHeader(std::ostringstream &out, const std::string &filename);
    
    // cpp output functions
    void writeRules(std::ostringstream &out, bool startName);
    void convertVariable(LLIR::variable var, std::ostringstream &out);
    void convertBlock(stdu::vector<LLIR::member> block, std::ostringstream &out);
    void convertCondition(LLIR::condition cond, std::ostringstream &out);
    void convertAssignVariable(LLIR::variable_assign var, std::ostringstream &out);
    void convertSwitch(const LLIR::switch_statement &statement, std::ostringstream &out);
    void convertMember(const LLIR::member& mem, std::ostringstream &out);
    void convertMembers(const stdu::vector<LLIR::member> &members, std::ostringstream &out);

    void addDFATables(std::ostringstream &out);
public:
    LLConverter(LLIR::IR &ir, AST::Tree &tree, const FCDT &fcdt, LLIR::Nodes *custom_lexer_code = nullptr, LLIR::variable *access_var = nullptr, std::string namespace_name = "") : LLConverter_base(ir, tree, fcdt, custom_lexer_code, access_var) {
        this->namespace_name = namespace_name;
        current_pos_counter.push("pos");
    }
    ~LLConverter() {}
    void convertData(std::ostringstream &out);
    void printIR(std::ostringstream& out, const std::string &filename);
    void addHeader(std::ostringstream &out);
    void addStandardFunctionsLexer(std::ostringstream &out);
    void addGetRuleFunction(std::ostringstream &out);
    void addparseFromFunctions(std::ostringstream &out);
    void addStandardFunctionsParser(std::ostringstream &out);
    void addGetFunctions(std::ostringstream &out, const LLIR::DataBlockList &datablocks_tokens, const LLIR::DataBlockList &datablocks_rules);
    void addLexerCode_Header(std::ostringstream &out);
    void convertLexerCode(const stdu::vector<LLIR::member> &members, std::ostringstream &out);
    void addLexerCode_Bottom(std::ostringstream &out, LLIR::variable var);
    void outputIR(std::filesystem::path filename);
};