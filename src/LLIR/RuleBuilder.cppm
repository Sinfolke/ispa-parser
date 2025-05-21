export module LLIRRuleBuilder;
import LLIRBuilderDataWrapper;
import LLIRBuilderBase;
import LLIR;
import TreeAPI;
import AST;
import LLIRBuilderData;
import std;
import std.compat;
export namespace LLIR {
    class RuleBuilder : private BuilderData {
        LLIR::Data data;
        const TreeAPI::Rule *rule;
        const std::vector<std::string> *name;
        void build();
        auto createDataBlock(const TreeAPI::DataBlock &data_block) -> LLIR::DataBlock;
        auto getInclosedMapFromKeyValueBinding() -> LLIR::inclosed_map;
    public:
        RuleBuilder(AST& ast, const std::vector<std::string> &name, const TreeAPI::Rule &rule) : BuilderData(ast), name(&name), rule(&rule) {
            build();
        }
        auto getData() -> LLIR::Data;
    };
}