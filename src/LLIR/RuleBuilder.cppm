export module LLIR.RuleBuilder;
import LLIR.Builder.DataWrapper;
import LLIR.Builder.Base;
import LangAPI;
import LLIR.API;
import AST.API;
import AST.Tree;
import LLIR.Builder.Data;
import DFA;
import dstd;
import std;

export namespace LLIR {
    class RuleBuilder : BuilderData {
        Production data;
        const AST::Rule *rule;
        auto getInclosedMapFromKeyValueBinding() -> LLIR::inclosed_map;
    public:
        RuleBuilder(AST::Tree& ast, const stdu::vector<std::string> &name, const AST::Rule &rule, stdu::vector<DFA::DFA> *dfas) : BuilderData(ast, dfas), rule(&rule) {
            fullname = name;
        }
        void build();
        auto createDataBlock(const AST::DataBlock &data_block) -> LLIR::DataBlock;
        auto getData() -> Production&;
    };
}