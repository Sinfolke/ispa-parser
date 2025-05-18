module;
#include <string>
#include <vector>
export module LLIRBuilderData;
import LLIR;
import ASTPass;
export namespace LLIR {
    class BuilderData {
    protected:
        size_t *variable_count = nullptr;
        bool *isToken = nullptr;
        bool *insideLoop = nullptr;
        bool *addSpaceSkip = nullptr;
        bool *isFirst = nullptr;
        int *tokensOnly = nullptr;
        std::vector<std::string> *fullname = nullptr;
        std::vector<variable> *vars = nullptr;
        Nodes *members = nullptr;
        std::vector<ConvertionResult> *success_vars = nullptr;
        std::vector<std::pair<std::string, variable>> *key_vars = nullptr;
        std::vector<variable> *unnamed_datablock_units = nullptr;
        ASTPass *tree = nullptr;
    public:
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
            std::vector<ConvertionResult> &success_vars,
            std::vector<std::pair<std::string, variable>> &key_vars,
            std::vector<variable> &unnamed_datablock_units,
            ASTPass *tree
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
            success_vars(&success_vars),
            key_vars(&key_vars),
            unnamed_datablock_units(&unnamed_datablock_units),
            tree(tree)
        {}
    };
}