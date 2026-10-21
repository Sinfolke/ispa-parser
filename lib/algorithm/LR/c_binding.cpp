import Algorithm.API;
import Algorithm.LRAdapter;
import LRParser;

extern "C" {
    auto LRParser_create(AST::Tree *tree, std::size_t k) -> LRBase* {
        return new LRParser(tree, k);
    }
    auto LRParser_finish(LRBase *parser) -> void {
        delete parser;
    }
}
extern "C" auto ispa_algorithm_v1() -> const Algorithm::Descriptor* {
    static const Algorithm::Descriptor descriptor{Algorithm::interface_version, "LR", 2, Algorithm::buildLR<LRParser>};
    return &descriptor;
}
