#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <any>
#include <unordered_map>
#include <internal_types.h>
#include <IR/IR.h>
#include <corelib.h>
#include <stack>
#include <logging.h>
class Converter : public IR {
private:
    // private variables used for convertion
    size_t pos_counter = 0;
    size_t indentLevel = 0;
    std::stack<size_t> pos_counter_stack;
    std::stack<std::string> current_pos_counter;
    std::vector<std::string> dynamic_pos_counter = {};
    use_prop_t use;
    std::pair<std::string, std::vector<std::string>> rule_prev_name;
    std::string rule_prev_name_str;
    std::string namespace_name;
    bool add_semicolon;
    bool has_data_block;
    bool isToken;
    // data
    std::vector<IR::member> data;
    IR lexer_code;
    const node_ret_t lexer_code_access_var;
    const data_block_t data_block_tokens;
    const data_block_t data_block_rules;
    const std::vector<std::string> tokens;
    const std::vector<std::string> rules;
    
    // cpp output functions
    std::string convert_var_type(IR::var_types type, std::vector<IR::var_type> data);
    std::string convert_var_assing_values(IR::var_assign_values value, std::any data);
    std::string convert_var_assing_types(IR::var_assign_types value);
    std::string conditionTypesToString(IR::condition_types type, std::any data);
    std::string convertFunctionCall(IR::function_call call);
    std::string convertAssign(IR::assign asgn);
    void convertVariable(IR::variable var, std::ostringstream &out);
    std::string convertExpression(std::vector<IR::expr> expression, bool with_braces);
    void convertBlock(std::vector<IR::member> block, std::ostringstream &out);
    void convertCondition(IR::condition cond, std::ostringstream &out);
    void convertAssignVariable(IR::variable_assign var, std::ostringstream &out);
    std::string convertMethodCall(IR::method_call method);
    std::string convertDataBlock(IR::data_block dtb);
    void convertMember(const IR::member& mem, std::ostringstream &out);
    void convertMembers(const std::vector<IR::member> &members, std::ostringstream &out);
    void printIR(std::ostringstream& out);
    void addHeader(std::ostringstream &out);
    void addTokensToString(std::vector<std::string> tokens, std::ostringstream &out);
    void addRulesToString(std::vector<std::string> rules, std::ostringstream &out);
    void addStandardFunctionsLexer(std::ostringstream &out);
    void addStandardFunctionsParser(std::ostringstream &out);
    void addGetFunctions(std::ostringstream &out, data_block_t datablocks_tokens, data_block_t datablocks_rules);
    void addLexer_codeHeader(std::ostringstream &out);
    void addLexer_codeBottom(std::ostringstream &out, IR::variable var);

    // header output functions
    void createLibrary(std::ostringstream& out);
    void close_library(std::ostringstream &out);
    void createNamespace(std::ostringstream &out);
    void createTypes(std::ostringstream &out);
    void writeEnum(std::ostringstream& out, const std::vector<std::string>& enm);
    void createTokensEnum(std::ostringstream &out);
    void createRulesEnum(std::ostringstream &out);
    void getTypesFromStdlib(std::ostringstream& out);
    void createToStringFunction(std::ostringstream &out);
    void addStandardFunctions(std::ostringstream &out);
    void convert_inclosed_map(std::ostringstream &out, IR::inclosed_map map);
    void convert_single_assignment_data(std::ostringstream &out, IR::var_type type, std::string name);
    void write_data_block(std::ostringstream &out, data_block_t dtb);
    void createTypesNamespace(std::ostringstream &out);
    void create_tokenizator_header(std::ostringstream &out);
    void create_parser_header(std::ostringstream &out);
    void create_get_namespace(std::ostringstream &out);
    void outputHeader(std::ostringstream &out);
public:
    Converter(
        IR&& ir, IR& lexer_code, const node_ret_t &lexer_code_access_var, const std::vector<std::string>& tokens, const std::vector<std::string>& rules,
        const data_block_t& data_block_tokens, const data_block_t& data_block_rules, use_prop_t use
    )
    : IR(*ir.getTree()),
    data(std::move(ir.getDataRef())), // now move or reference the already moved IR data
    lexer_code(lexer_code),
    lexer_code_access_var(lexer_code_access_var),
    tokens(tokens),
    rules(rules),
    data_block_tokens(data_block_tokens),
    data_block_rules(data_block_rules),
    use(use)
    {}
    void outputIRToFile(std::string filename);
    void outputIRToConsole();
};