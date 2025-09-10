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
        std::size_t *variable_count = nullptr;
        bool *isToken = nullptr;
        bool *insideLoop = nullptr;
        bool *addSpaceSkip = nullptr;
        bool *isFirst = nullptr;
        int *tokensOnly = nullptr;
        stdu::vector<std::string> *fullname = nullptr;
        stdu::vector<variable> *vars = nullptr;
        stdu::vector<std::pair<std::string, variable>> *key_vars = nullptr;
        stdu::vector<variable> *unnamed_datablock_units = nullptr;
        BuilderData::SymbolFollow *symbol_follow = nullptr;
        bool *has_symbol_follow = nullptr;
        AST::Tree *tree = nullptr;
        DFA::Collection<DFA::TokenMachineDFA> *dfas = nullptr;
        auto initializationCheck() -> bool;
        explicit BuilderDataWrapper(LLIR::BuilderData &data)
            : variable_count(&data.variable_count),
        isToken(&data.isToken),
        insideLoop(&data.insideLoop),
        addSpaceSkip(&data.addSpaceSkip),
        isFirst(&data.isFirst),
        tokensOnly(&data.tokensOnly),
        fullname(&data.fullname),
        vars(&data.vars),
        key_vars(&data.key_vars),
        unnamed_datablock_units(&data.unnamed_datablock_units),
        symbol_follow(&data.symbol_follow),
        has_symbol_follow(&data.has_symbol_follow),
        tree(data.tree),
        dfas(data.dfas)
        {}
        BuilderDataWrapper(
            std::size_t &variable_count,
            bool &isToken,
            bool &insideLoop,
            bool &addSpaceSkip,
            bool &isFirst,
            int &tokensOnly,
            stdu::vector<std::string> &fullname,
            stdu::vector<variable> &vars,
            stdu::vector<std::pair<std::string, variable>> &key_vars,
            stdu::vector<variable> &unnamed_datablock_units,
            stdu::vector<std::pair<stdu::vector<std::string>, std::set<stdu::vector<std::string>>>> &symbol_follow,
            bool &has_symbol_follow,
            AST::Tree *tree,
            DFA::Collection<DFA::TokenMachineDFA> *dfas
        ) :
            variable_count(&variable_count),
            isToken(&isToken),
            insideLoop(&insideLoop),
            addSpaceSkip(&addSpaceSkip),
            isFirst(&isFirst),
            tokensOnly(&tokensOnly),
            fullname(&fullname),
            vars(&vars),
            key_vars(&key_vars),
            unnamed_datablock_units(&unnamed_datablock_units),
            symbol_follow(&symbol_follow),
            has_symbol_follow(&has_symbol_follow),
            tree(tree),
            dfas(dfas)
        {}
    };
}