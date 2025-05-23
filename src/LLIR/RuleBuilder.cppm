export module LLIRRuleBuilder;
import LLIRBuilderDataWrapper;
import LLIRBuilderBase;
import LLIR;
import TreeAPI;
import AST;
import LLIRBuilderData;
import types;
import std;
import std.compat;
export namespace LLIR {
    class RuleBuilder : private BuilderData {
        LLIR::Data data;
        const TreeAPI::Rule *rule;
        void build();
        auto createDataBlock(const TreeAPI::DataBlock &data_block) -> LLIR::DataBlock;
        auto getInclosedMapFromKeyValueBinding() -> LLIR::inclosed_map;
    public:
        RuleBuilder(AST& ast, const vector<std::string> &name, const TreeAPI::Rule &rule) : BuilderData(ast), rule(&rule) {
            fullname = name;
            build();
        }
        auto getData() -> LLIR::Data;
    };
}