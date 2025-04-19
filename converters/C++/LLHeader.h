#pragma once
#include <LLStringConvertions.h>
class LLHeader : public LLStringConvertions {
    protected:
    // header output functions
    void createIncludes(std::ostringstream &out);
    void createLibrary(std::ostringstream& out, std::string namespace_name);
    void createDefaultTypes(std::ostringstream &out);
    void close_library(std::ostringstream &out, std::string namespace_name);
    void createNamespace(std::ostringstream &out, std::string namespace_name);
    void createTypes(std::ostringstream &out, std::string namespace_name);
    void writeEnum(std::ostringstream& out, const std::vector<std::string>& enm);
    void createTokensEnum(std::ostringstream &out, const std::vector<std::string> &tokens);
    void createRulesEnum(std::ostringstream &out, const std::vector<std::string> &rules);
    void getTypesFromStdlib(std::ostringstream& out);
    void createToStringFunction(std::ostringstream &out);
    void addStandardFunctions(std::ostringstream &out);
    void convert_inclosed_map(std::ostringstream &out, LLIR::inclosed_map map);
    void convert_single_assignment_data(std::ostringstream &out, LLIR::var_type type, std::string name);
    void write_data_block(std::ostringstream &out, data_block_t dtb);
    void createTypesNamespace(std::ostringstream &out, const data_block_t &data_block_tokens, const data_block_t &data_block_rules);
    void create_lexer_header(std::ostringstream &out, const std::vector<std::string> &tokens);
    void addConstructorsLexer(std::ostringstream &out);
    void close_parser_header(std::ostringstream &out);
    void create_parser_header(std::ostringstream &out);
    void create_get_namespace(std::ostringstream &out, std::string namespace_name, const data_block_t &data_block_tokens, const data_block_t &data_block_rules);
};