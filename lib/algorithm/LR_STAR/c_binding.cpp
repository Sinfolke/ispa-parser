import Algorithm.API;
import Algorithm.LRAdapter;
import LR_STARParser;

extern "C" {
    auto LR_STARParser_create(AST::Tree *tree, std::size_t k) -> LRBase* {
        return new LR_STARParser(tree, k);
    }
    auto LR_STARParser_finish(LRBase *parser) -> void {
        delete parser;
    }
}
extern "C" auto ispa_algorithm_v1() -> const Algorithm::Descriptor* {
    static const Algorithm::Descriptor descriptor{Algorithm::interface_version, "LR_STAR", 1, Algorithm::buildLR<LR_STARParser>};
    return &descriptor;
}
