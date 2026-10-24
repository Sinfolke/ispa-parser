export module Algorithm.LRAdapter;
import Algorithm.API;
import AST.BackendGuard;
import LangRepr.Construct;
import LRBase;
import cpuf.printf;
import cpuf.op;
import std;

export namespace Algorithm {
    template<class Parser>
    auto buildLR(const BuildRequest& request, Metadata& metadata) -> Result {
        // Plugin clients may bypass the CLI's backend guard.  Reject semantic
        // constructs before normalization turns actions into epsilon rules;
        // ordinary match-only advanced rules can use the LR productions.
        AST::requireCppSupport(request.tree, false);
        std::shared_ptr<Parser> parser;
        if constexpr (requires { Parser(&request.tree, 1, std::string_view{}); }) {
            const auto found = metadata.cache.find("tables");
            parser = std::make_shared<Parser>(&request.tree, 1,
                found == metadata.cache.end() ? std::string_view{} : std::string_view{found->second});
        } else {
            parser = std::make_shared<Parser>(&request.tree, 1);
        }
        if (!parser->isSupported()) throw std::invalid_argument("LR(*) is not implemented");
        if (request.auto_conflicts) {
            parser->resolveConflicts(request.conflict_lookahead);
            const auto& resolutions = parser->getConflictResolutions();
            const auto dynamic = std::count_if(resolutions.begin(), resolutions.end(),
                [](const auto& r) { return r.lookahead == 0; });
            if (!resolutions.empty())
                cpuf::printf("LR conflicts: {} resolved with lookahead, {} use runtime branching\n",
                    resolutions.size() - dynamic, dynamic);
        }
        metadata.cache = {{"tables", parser->saveCache()}};
        return {std::move(parser), [](void* output, ConversionRequest& request) {
            return LangRepr::Construct::construct(std::move(request.lexer),
                *static_cast<Parser*>(output), request.tree, request.language, request.namespace_name);
        }};
    }
}
