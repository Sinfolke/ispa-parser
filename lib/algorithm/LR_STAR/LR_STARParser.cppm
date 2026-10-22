// Reserved for a future LR(*) algorithm. Explicitly unsupported at present.
export module LR_STARParser;
export import LRParser;
import AST.Tree;

// Export the DLL API as well as the C++ module interface, like LRParser.
#if defined(_WIN32)
#define ISPA_LR_STAR_EXPORT __declspec(dllexport)
#else
#define ISPA_LR_STAR_EXPORT
#endif

export class ISPA_LR_STAR_EXPORT LR_STARParser : public LRParser {
protected:
    void build() override; // no-op; no LR/LALR automaton is constructed
public:
    explicit LR_STARParser(AST::Tree* tree, std::size_t k = 1);
    explicit LR_STARParser(AST::Tree& tree, std::size_t k = 1);
    bool isSupported() const noexcept override { return false; }
};

#undef ISPA_LR_STAR_EXPORT
