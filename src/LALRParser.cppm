export module LALRParser;
import LRParser;
import AST;
import std;
export class LALRParser : public LRParser {
protected:
    void rebuildActionTable(const std::vector<size_t>& state_mapping);
    void rebuildGotoTable(const std::vector<size_t>& state_mapping);
    std::vector<std::pair<std::vector<std::string>, LRParser::Action_type>> getActionType(const LR1Core& item, size_t state);
    void build() override;
public:
    LALRParser(AST *tree) : LRParser(tree, true) {
        build();
    }
    LALRParser(AST &tree) : LRParser(&tree, true) {
        build();
    }
};