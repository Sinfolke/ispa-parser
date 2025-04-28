#include <LLHeader.h>
#include <internal_types.h>
#include <LRParser.h>
#include <LRInternalData.h>
class LRHeader : public LLHeader, public LRInternalData {
    protected:
    void addIncludes_h(std::ostringstream &out) const;
    void createActionStruct(std::ostringstream &out) const;
    void createTableTypes(std::ostringstream &out, long long DFA_size) const;
    void create_parser_header(std::ostringstream &out, bool hasDFA) const;
    void addStandardFunctionsParser(std::ostringstream &out) const;
};