export module LLIR.Builder.DataWrapper;
import LLIR.API;
import LLIR.Builder.Data;
import AST.Tree;
import DFA.Collection;
import DFA.TokenMachineDFA;
import dstd;
import std;

export namespace LLIR {
    class BuilderDataWrapper {
    public:
        std::size_t &variable_count;
        bool &isToken;
        bool &insideLoop;
        bool &addSpaceSkip;
        bool &isFirst;
        int &tokensOnly;
        stdu::vector<std::string> &fullname;
        stdu::vector<Variable> &vars;
        stdu::vector<std::pair<std::string, Variable>> &key_vars;
        stdu::vector<Variable> &unnamed_datablock_units;
        BuilderData::SymbolFollow &symbol_follow;
        bool &has_symbol_follow;
        AST::Tree &tree;
        DFA::Collection<DFA::TokenMachineDFA> &dfas;
        BuilderDataWrapper(LLIR::BuilderData &data) : BuilderDataWrapper(
            data.variable_count, data.isToken, data.insideLoop,
            data.addSpaceSkip, data.isFirst, data.tokensOnly,
            data.fullname, data.vars, data.key_vars,
            data.unnamed_datablock_units,data.symbol_follow, data.has_symbol_follow,
            data.tree, data.dfas
        ) {}
        BuilderDataWrapper(
            std::size_t &variable_count,
            bool &isToken,
            bool &insideLoop,
            bool &addSpaceSkip,
            bool &isFirst,
            int &tokensOnly,
            stdu::vector<std::string> &fullname,
            stdu::vector<Variable> &vars,
            stdu::vector<std::pair<std::string, Variable>> &key_vars,
            stdu::vector<Variable> &unnamed_datablock_units,
            stdu::vector<std::pair<stdu::vector<std::string>, std::set<stdu::vector<std::string>>>> &symbol_follow,
            bool &has_symbol_follow,
            AST::Tree &tree,
            DFA::Collection<DFA::TokenMachineDFA> &dfas
        ) :
            variable_count(variable_count),
            isToken(isToken),
            insideLoop(insideLoop),
            addSpaceSkip(addSpaceSkip),
            isFirst(isFirst),
            tokensOnly(tokensOnly),
            fullname(fullname),
            vars(vars),
            key_vars(key_vars),
            unnamed_datablock_units(unnamed_datablock_units),
            symbol_follow(symbol_follow),
            has_symbol_follow(has_symbol_follow),
            tree(tree),
            dfas(dfas)
        {}
    };
}