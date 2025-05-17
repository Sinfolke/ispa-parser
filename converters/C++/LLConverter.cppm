module;
#include <string>
#include <vector>

export module LLConverter;
import Converter;
import corelib;
import logging;
import LRParser;
import ASTPass;
import LLIR;
import LLHeader;
export class LLConverter : public LLConverter_base, public LLHeader {
private:

    void outputHeader(std::ostringstream &out, const std::string &filename);
    
    // cpp output functions
    void writeRules(std::ostringstream &out, bool startName);
    void convertVariable(LLIR_old::variable var, std::ostringstream &out);
    void convertBlock(std::vector<LLIR_old::member> block, std::ostringstream &out);
    void convertCondition(LLIR_old::condition cond, std::ostringstream &out);
    void convertAssignVariable(LLIR_old::variable_assign var, std::ostringstream &out);
    void convertMember(const LLIR_old::member& mem, std::ostringstream &out);
    void convertMembers(const std::vector<LLIR_old::member> &members, std::ostringstream &out);


public:
    LLConverter(LLIR_old &ir, ASTPass &tree, LLIR_old *custom_lexer_code = nullptr, LLIR_old::variable *access_var = nullptr, std::string namespace_name = "") : LLConverter_base(ir, tree, custom_lexer_code, access_var) {
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
    void addGetFunctions(std::ostringstream &out, const LLIR_old::DataBlockList &datablocks_tokens, const LLIR_old::DataBlockList &datablocks_rules);
    void addLexerCode_Header(std::ostringstream &out);
    void convertLexerCode(const std::vector<LLIR_old::member> &members, std::ostringstream &out);
    void addLexerCode_Bottom(std::ostringstream &out, LLIR_old::variable var);
    void outputIR(std::filesystem::path filename);
};