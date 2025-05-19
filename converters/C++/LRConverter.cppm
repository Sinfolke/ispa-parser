
export module LRConverter;
import Converter;
import LRHeader;
import corelib;
import LRParser;
import AST;
import std;
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
    LRConverter(LRParser &parser, AST &tree) : LRConverter_base(parser, tree) {}
    ~LRConverter() {}
    void output(std::filesystem::path filename);
};