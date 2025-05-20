export module LALRParser;
import LRParser;
import AST;
import std;
import std.compat;
export class LALRParser : public LRParser {
protected:
    void rebuildActionTable(const std::vector<size_t>& state_mapping);
    void rebuildGotoTable(const std::vector<size_t>& state_mapping);
    auto getActionType(const LR1Core& item, size_t state) -> std::vector<std::pair<std::vector<std::string>, LRParser::Action_type>>;
    void build() override;
public:
    LALRParser(AST *tree) : LRParser(tree, true) {
        build();
    }
    LALRParser(AST &tree) : LRParser(&tree, true) {
        build();
    }
};