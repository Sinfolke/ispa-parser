export module LLIRBuilderData;
import LLIR;
import AST;
import TreeAPI;
import std;
import std.compat;
namespace LLIR {
    export class BuilderData {
    public:
        size_t variable_count = 0;
        bool isToken = false;
        bool insideLoop = false;
        bool addSpaceSkip = false;
        bool isFirst = true;
        int tokensOnly = -1;
        std::vector<std::string> fullname;
        std::vector<LLIR::variable> vars;
        std::vector<std::pair<std::string, LLIR::variable>> key_vars;
        std::vector<LLIR::variable> unnamed_datablock_units;
        std::vector<std::pair<std::vector<std::string>, std::set<std::vector<std::string>>>> symbol_follow;
        bool has_symbol_follow = true;
        AST *tree;
        BuilderData(AST &tree) : tree(&tree) {}
    };
}