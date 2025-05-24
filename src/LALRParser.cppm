export module LALRParser;
import LRParser;
import AST;
import types;
import std;
import std.compat;
export class LALRParser : public LRParser {
protected:
    void rebuildActionTable(const vector<size_t>& state_mapping);
    void rebuildGotoTable(const vector<size_t>& state_mapping);
    auto getActionType(const LR1Core& item, size_t state) -> vector<std::pair<vector<std::string>, LRParser::Action_type>>;
    void build() override;
public:
    LALRParser(AST *tree) : LRParser(tree, true) {
        build();
    }
    LALRParser(AST &tree) : LRParser(&tree, true) {
        build();
    }
};