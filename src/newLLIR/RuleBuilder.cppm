export module LLIRRuleBuilder;
import LLIRBuilderData;
import LLIRBuilderBase;
import LLIR;
import TreeAPI;
import std;
export namespace LLIR {
    class RuleBuilder {
        LLIR::BuilderData &builderData;
        LLIR::Data data;
        const TreeAPI::Rule *rule;
        const std::vector<std::string> *name;
        void build();
        auto createDataBlock(const TreeAPI::DataBlock &data_block) -> LLIR::DataBlock;
        auto getInclosedMapFromKeyValueBinding() -> LLIR::inclosed_map;
    public:
        RuleBuilder(LLIR::BuilderData &data, const std::vector<std::string> &name, const TreeAPI::Rule &rule) : builderData(data), name(&name), rule(&rule) {
            build();
        }
    };
}