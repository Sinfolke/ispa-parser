import LRParser;

extern "C" {
    auto LRParser_create(AST::Tree *tree, std::size_t k) -> LRBase* {
        return new LRParser(tree, k);
    }
    auto LRParser_finish(LRBase *parser) -> void {
        delete parser;
    }
}