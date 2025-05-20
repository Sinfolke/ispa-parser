export module LLIRBuilderData;
import LLIR;
import AST;
import std;
import std.compat;
export namespace LLIR {
    class BuilderData {
    public:
        size_t *variable_count = nullptr;
        bool *isToken = nullptr;
        bool *insideLoop = nullptr;
        bool *addSpaceSkip = nullptr;
        bool *isFirst = nullptr;
        int *tokensOnly = nullptr;
        std::vector<std::string> *fullname = nullptr;
        std::vector<variable> *vars = nullptr;
        Nodes *members = nullptr;
        std::vector<ConvertionResult> conv_res;
        std::vector<std::pair<std::string, variable>> *key_vars = nullptr;
        std::vector<variable> *unnamed_datablock_units = nullptr;
        AST *tree = nullptr;
        auto initializationCheck() -> bool;
        BuilderData(
            size_t &variable_count,
            bool &isToken,
            bool &insideLoop,
            bool &addSpaceSkip,
            bool &isFirst,
            int &tokensOnly,
            std::vector<std::string> &fullname,
            std::vector<variable> &vars,
            std::vector<member> &members,
            std::vector<std::pair<std::string, variable>> &key_vars,
            std::vector<variable> &unnamed_datablock_units,
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
            members(&members),
            key_vars(&key_vars),
            unnamed_datablock_units(&unnamed_datablock_units),
            tree(tree)
        {}
    };
}