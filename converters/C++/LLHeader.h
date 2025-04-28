#pragma once
#include <LLStringConvertions.h>
#include <internal_types.h>
class LLHeader : public LLStringConvertions {
    protected:
    // header output functions
    void createIncludes(std::ostringstream &out) const;
    void createLibrary(std::ostringstream& out, std::string namespace_name) const;
    void createDefaultTypes(std::ostringstream &out) const;
    void close_library(std::ostringstream &out, std::string namespace_name) const;
    void createNamespace(std::ostringstream &out, std::string namespace_name) const;
    void createTypes(std::ostringstream &out, std::string namespace_name) const;
    void writeEnum(std::ostringstream& out, const std::vector<std::vector<std::string>>& enm) const;
    void createTokensEnum(std::ostringstream &out, const std::vector<std::vector<std::string>> &tokens) const;
    void createRulesEnum(std::ostringstream &out, const std::vector<std::vector<std::string>> &rules) const;
    void getTypesFromStdlib(std::ostringstream& out) const;
    void createToStringFunction(std::ostringstream &out) const;
    void addStandardFunctions(std::ostringstream &out) const;
    void convert_inclosed_map(std::ostringstream &out, LLIR::inclosed_map map) const;
    void convert_single_assignment_data(std::ostringstream &out, LLIR::var_type type, std::string name) const;
    void write_data_block(std::ostringstream &out, data_block_t dtb) const;
    void createTypesNamespace(std::ostringstream &out, const data_block_t &data_block_tokens, const data_block_t &data_block_rules) const;
    void create_lexer_header(std::ostringstream &out, const std::vector<std::vector<std::string>> &tokens) const;
    void addConstructorsLexer(std::ostringstream &out) const;
    void close_parser_header(std::ostringstream &out) const;
    void create_parser_header(std::ostringstream &out) const;
    void create_get_namespace(std::ostringstream &out, std::string namespace_name, const data_block_t &data_block_tokens, const data_block_t &data_block_rules) const;
};