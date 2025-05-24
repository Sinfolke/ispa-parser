export module LLIRBuilderDataWrapper;
import LLIR;
import LLIRBuilderData;
import AST;
import types;
import std;
import std.compat;
export namespace LLIR {
    class BuilderDataWrapper {
    public:
        size_t *variable_count = nullptr;
        bool *isToken = nullptr;
        bool *insideLoop = nullptr;
        bool *addSpaceSkip = nullptr;
        bool *isFirst = nullptr;
        int *tokensOnly = nullptr;
        vector<std::string> *fullname = nullptr;
        vector<variable> *vars = nullptr;
        vector<std::pair<std::string, variable>> *key_vars = nullptr;
        vector<variable> *unnamed_datablock_units = nullptr;
        BuilderData::SymbolFollow *symbol_follow = nullptr;
        bool *has_symbol_follow = nullptr;
        AST *tree = nullptr;

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
        tree(data.tree)
        {}
        BuilderDataWrapper(
            size_t &variable_count,
            bool &isToken,
            bool &insideLoop,
            bool &addSpaceSkip,
            bool &isFirst,
            int &tokensOnly,
            vector<std::string> &fullname,
            vector<variable> &vars,
            vector<std::pair<std::string, variable>> &key_vars,
            vector<variable> &unnamed_datablock_units,
            vector<std::pair<vector<std::string>, std::set<vector<std::string>>>> &symbol_follow,
            bool &has_symbol_follow,
            AST *tree
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
            tree(tree)
        {}
    };
}