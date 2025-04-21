#include <LRParser.h>
#include <internal_types.h>
class LALRParser : public LRParser {
protected:
    void build() override;
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