#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <any>
#include <unordered_map>
#include <internal_types.h>
#include <IR/IR.h>
#include <tree.h>
#include <corelib.h>
#include <stack>
#include <logging.h>
#include <converter_base.h>
#include <LRParser.h>
#include <LLHeader.h>


class LLConverter : public LLConverter_base, public LLHeader {
private:

    void outputHeader(std::ostringstream &out, const std::string &filename);
    
    // cpp output functions
    void writeRules(std::ostringstream &out);
    void convertVariable(LLIR::variable var, std::ostringstream &out);
    void convertBlock(std::vector<LLIR::member> block, std::ostringstream &out);
    void convertCondition(LLIR::condition cond, std::ostringstream &out);
    void convertAssignVariable(LLIR::variable_assign var, std::ostringstream &out);
    void convertMember(const LLIR::member& mem, std::ostringstream &out);
    void convertMembers(const std::vector<LLIR::member> &members, std::ostringstream &out);


public:
    LLConverter(LLIR &ir, Tree &tree, LLIR *custom_lexer_code = nullptr, LLIR::node_ret_t *access_var = nullptr, std::string namespace_name = "") : LLConverter_base(ir, tree, custom_lexer_code, access_var) {
        this->namespace_name = namespace_name;
        current_pos_counter.push("pos");
    }
    ~LLConverter() {}
    void convertData(std::ostringstream &out);
    void printIR(std::ostringstream& out, const std::string &filename);
    void addHeader(std::ostringstream &out);
    void addTokensToString(std::vector<std::string> tokens, std::ostringstream &out);
    void addRulesToString(std::vector<std::string> rules, std::ostringstream &out);
    void addStandardFunctionsLexer(std::ostringstream &out);
    void addGetRuleFunction(std::ostringstream &out);
    void addparseFromFunctions(std::ostringstream &out);
    void addStandardFunctionsParser(std::ostringstream &out);
    void addGetFunctions(std::ostringstream &out, data_block_t datablocks_tokens, data_block_t datablocks_rules);
    void addLexerCode_Header(std::ostringstream &out);
    void convertLexerCode(const std::vector<LLIR::member> &members, std::ostringstream &out);
    void addLexerCode_Bottom(std::ostringstream &out, LLIR::variable var);
    void outputIR(std::string filename);
};