import Algorithm.API;
import Algorithm.LRAdapter;
import LALRParser;

extern "C" {
    auto LALRParser_create(AST::Tree *tree, std::size_t k) -> LRBase* {
        return new LALRParser(tree, k);
    }
    auto LALRParser_finish(LRBase* parser) -> void {
        delete parser;
    }
}
extern "C" auto ispa_algorithm_v1() -> const Algorithm::Descriptor* {
    static const Algorithm::Descriptor descriptor{Algorithm::interface_version, "LALR", 2, Algorithm::buildLR<LALRParser>};
    return &descriptor;
}
