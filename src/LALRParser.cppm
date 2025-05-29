export module LALRParser;
import LRParser;
import AST.Tree;
import dstd;
import std;
import std.compat;
export class LALRParser : public LRParser {
protected:
    void rebuildActionTable(const stdu::vector<size_t>& state_mapping);
    void rebuildGotoTable(const stdu::vector<size_t>& state_mapping);
    auto getActionType(const LR1Core& item, size_t state) -> stdu::vector<std::pair<stdu::vector<std::string>, LRParser::Action_type>>;
    void build() override;
public:
    LALRParser(AST::Tree *tree) : LRParser(tree, true) {
        build();
    }
    LALRParser(AST::Tree &tree) : LRParser(&tree, true) {
        build();
    }
};