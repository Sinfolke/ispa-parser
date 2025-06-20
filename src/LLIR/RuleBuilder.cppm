export module LLIR.RuleBuilder;
import LLIR.Builder.DataWrapper;
import LLIR.Builder.Base;
import LLIR.API;
import AST.API;
import AST.Tree;
import DFA;
import LLIR.Builder.Data;
import dstd;
import std;
import std.compat;
export namespace LLIR {
    class RuleBuilder : private BuilderData {
        LLIR::Data data;
        const AST::Rule *rule;
        void build();
        auto createDataBlock(const AST::DataBlock &data_block) -> LLIR::DataBlock;
        auto getInclosedMapFromKeyValueBinding() -> LLIR::inclosed_map;
    public:
        RuleBuilder(AST::Tree& ast, const stdu::vector<std::string> &name, const AST::Rule &rule, stdu::vector<DFA> &dfas) : BuilderData(ast, &dfas), rule(&rule) {
            fullname = name;
            build();
        }
        auto getData() -> LLIR::Data&;
    };
}