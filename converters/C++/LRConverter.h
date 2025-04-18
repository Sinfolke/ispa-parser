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
#include <LLConverter.h>
class LRConverter : public LRConverter_base, public LLHeader {
private:
    size_t max_terminals, max_nonterminals, max_states;
    data_block_t data_block_tokens, data_block_rules;
    // private variables used for convertion
    void addIncludesCpp(std::ostringstream &out, const std::string &name);
    void addIncludes_h(std::ostringstream &out);
    void createTableTypes(std::ostringstream &out);
    void create_parser_header(std::ostringstream &out);
    void createActionStruct(std::ostringstream &out);
    void createActionTable(std::ostringstream &out);
    void createGotoTable(std::ostringstream &out);
    void createRulesTable(std::ostringstream &out);
    void outputIR(std::ostringstream &out, std::string &filename);
    void outputHeader(std::ostringstream& out, std::string &filename);
public:
    LRConverter(LRParser &parser, Tree &tree) : LRConverter_base(parser, tree) {}
    ~LRConverter() {}
    void output(std::string filename);
};