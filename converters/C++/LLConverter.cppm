module;
export module LLConverter;
import Converter;
import corelib;
import logging;
import AST;
import LLIR;
import LLHeader;
export class LLConverter : public LLConverter_base, public LLHeader {
    void outputHeader(std::ostringstream &out, const std::string &filename);
    
    // cpp output functions
    void writeRules(std::ostringstream &out, bool startName);
    void convertVariable(IR::variable var, std::ostringstream &out);
    void convertBlock(std::vector<IR::member> block, std::ostringstream &out);
    void convertCondition(IR::condition cond, std::ostringstream &out);
    void convertAssignVariable(IR::variable_assign var, std::ostringstream &out);
    void convertMember(const IR::member& mem, std::ostringstream &out);
    void convertMembers(const std::vector<IR::member> &members, std::ostringstream &out);


public:
    LLConverter(IR &ir, AST &tree, IR *custom_lexer_code = nullptr, IR::variable *access_var = nullptr, std::string namespace_name = "") : LLConverter_base(ir, tree, custom_lexer_code, access_var) {
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
    void addGetFunctions(std::ostringstream &out, const IR::DataBlockList &datablocks_tokens, const IR::DataBlockList &datablocks_rules);
    void addLexerCode_Header(std::ostringstream &out);
    void convertLexerCode(const std::vector<IR::member> &members, std::ostringstream &out);
    void addLexerCode_Bottom(std::ostringstream &out, IR::variable var);
    void outputIR(std::filesystem::path filename);
};