#include <LRParser.h>
#include <internal_types.h>
class LALRParser : public LRParser {
protected:
    void build();
    std::set<std::vector<std::string>> compute_first_sequence(const std::vector<rule_other>& beta, const std::set<std::vector<std::string>>& la);
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