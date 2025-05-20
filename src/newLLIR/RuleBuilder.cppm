export module LLIRRuleBuilder;
import LLIRBuilderData;
import LLIRBuilderBase;
import LLIR;
import TreeAPI;
import AST;
import std;
import std.compat;
export namespace LLIR {
    class RuleBuilder {
        size_t variable_count = 0;
        bool isToken = false;
        bool insideLoop = false;
        bool addSpaceSkip = false;
        bool isFirst = true;
        int tokensOnly = -1;
        std::vector<std::string> fullname;
        std::vector<LLIR::variable> vars;
        std::vector<LLIR::member> members;
        std::vector<LLIR::ConvertionResult> success_vars;
        std::vector<std::pair<std::string, LLIR::variable>> key_vars;
        std::vector<LLIR::variable> unnamed_datablock_units;
        AST *tree;
        LLIR::Data data;
        const TreeAPI::Rule *rule;
        const std::vector<std::string> *name;
        void build();
        auto getBuilderData() -> BuilderData;
        auto createDataBlock(const TreeAPI::DataBlock &data_block) -> LLIR::DataBlock;
        auto getInclosedMapFromKeyValueBinding() -> LLIR::inclosed_map;
    public:
        RuleBuilder(const std::vector<std::string> &name, const TreeAPI::Rule &rule) : name(&name), rule(&rule) {
            build();
        }
        auto getData() -> LLIR::Data;
    };
}