import LALRParser;

extern "C" {
    auto LALRParser_create(AST::Tree *tree, std::size_t k) -> LRBase* {
        return new LALRParser(tree, k);
    }
    auto LALRParser_finish(LRBase* parser) -> void {
        delete parser;
    }
}