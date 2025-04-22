#include <LRParser.h>
#include <internal_types.h>
class LALRParser : public LRParser {
protected:
    void rebuildActionTable(const std::vector<size_t>& state_mapping);
    void rebuildGotoTable(const std::vector<size_t>& state_mapping);
    void build();
public:
    LALRParser(Tree *tree) : LRParser(tree, false) {
        LRParser::transform();
        build();
    }
    LALRParser(Tree &tree) : LRParser(&tree, false) {
        LRParser::transform();
        build();
    }
};