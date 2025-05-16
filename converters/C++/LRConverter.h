#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <any>
#include <unordered_map>
#include <IR/LLIR_old.h>
#include <tree.h>
#include <corelib.h>
#include <stack>
#include <logging.h>
#include <converter_base.h>
#include <LRParser.h>
#include <ELRParser.h>
#include <LLConverter.h>
#include <LRHeader.h>
class LRConverter : public LRConverter_base, public LRHeader {
private:
    // private variables used for convertion
    void addIncludesCpp(std::ostringstream &out, const std::string &name) const;
    void addparseFromFunctions(std::ostringstream &out, bool hasDFA) const;
    void createActionTable(std::ostringstream &out) const;
    void createGotoTable(std::ostringstream &out) const;
    void createRulesTable(std::ostringstream &out);
    void createDFATable(std::ostringstream &out);
    void outputIR(std::ostringstream &out, std::string &filename);
    void outputHeader(std::ostringstream& out, std::string &filename) const;
public:
    LRConverter(LRParser &parser, Tree &tree) : LRConverter_base(parser, tree) {}
    ~LRConverter() {}
    void output(std::filesystem::path filename);
};