// Standard LALR(k): merge identical LR(0) cores and union their LR(1) lookaheads.
export module LALRParser;
export import LRParser;
import AST.Tree;
import std;

// Export the DLL API as well as the C++ module interface, like LRParser.
#if defined(_WIN32)
#define ISPA_LALR_EXPORT __declspec(dllexport)
#else
#define ISPA_LALR_EXPORT
#endif

export class ISPA_LALR_EXPORT LALRParser : public LRParser {
protected:
    void build() override;
    auto cacheKind() const -> std::string_view override { return "LALR"; }
    void mergeLR0Cores();
public:
    explicit LALRParser(AST::Tree* tree, std::size_t k = 1, std::string_view cache = {});
    explicit LALRParser(AST::Tree& tree, std::size_t k = 1);
};

#undef ISPA_LALR_EXPORT
