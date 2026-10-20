import LR_STARParser;

extern "C" {
    auto LR_STARParser_create(AST::Tree *tree, std::size_t k) -> LRBase* {
        return new LR_STARParser(tree, k);
    }
    auto LR_STARParser_finish(LRBase *parser) -> void {
        delete parser;
    }
}