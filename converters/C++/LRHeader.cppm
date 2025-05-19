export module LRHeader;
import LLHeader;
import LRParser;
import LRInternalData;
import std;
export class LRHeader : public LLHeader, public LRInternalData {
    protected:
    void addIncludes_h(std::ostringstream &out) const;
    void createActionStruct(std::ostringstream &out) const;
    void createTableTypes(std::ostringstream &out, long long DFA_size) const;
    void create_parser_header(std::ostringstream &out, bool hasDFA) const;
    void addStandardFunctionsParser(std::ostringstream &out) const;
};