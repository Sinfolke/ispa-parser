// Standard LALR(k): merge identical LR(0) cores and union their LR(1) lookaheads.
export module LALRParser;
export import LRParser;
import AST.Tree;
import std;

export class LALRParser : public LRParser {
protected:
    void build() override;
    auto cacheKind() const -> std::string_view override { return "LALR"; }
    void mergeLR0Cores();
public:
    explicit LALRParser(AST::Tree* tree, std::size_t k = 1, std::string_view cache = {});
    explicit LALRParser(AST::Tree& tree, std::size_t k = 1);
};
