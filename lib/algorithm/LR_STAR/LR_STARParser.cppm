// Reserved for a future LR(*) algorithm. Explicitly unsupported at present.
export module LR_STARParser;
export import LRParser;
import AST.Tree;

export class LR_STARParser : public LRParser {
protected:
    void build() override; // no-op; no LR/LALR automaton is constructed
public:
    explicit LR_STARParser(AST::Tree* tree, std::size_t k = 1);
    explicit LR_STARParser(AST::Tree& tree, std::size_t k = 1);
    bool isSupported() const noexcept override { return false; }
};
