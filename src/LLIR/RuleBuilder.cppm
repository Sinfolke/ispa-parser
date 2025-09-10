export module LLIR.RuleBuilder;
import LLIR.Builder.DataWrapper;
import LLIR.Builder.Base;
import LLIR.API;
import AST.API;
import AST.Tree;
import DFA.Collection;
import DFA.TokenMachineDFA;
import LLIR.Builder.Data;
import dstd;
import std;

export namespace LLIR {
    class RuleBuilder : BuilderData {
        LLIR::Data data;
        const AST::Rule *rule;
        auto getInclosedMapFromKeyValueBinding() -> LLIR::inclosed_map;
    public:
        RuleBuilder(AST::Tree& ast, const stdu::vector<std::string> &name, const AST::Rule &rule, DFA::Collection<DFA::TokenMachineDFA> &dfas) : BuilderData(ast, &dfas), rule(&rule) {
            fullname = name;
        }
        void build();
        auto createDataBlock(const AST::DataBlock &data_block, bool ro) -> LLIR::DataBlock;
        auto getData() -> LLIR::Data&;
    };
}