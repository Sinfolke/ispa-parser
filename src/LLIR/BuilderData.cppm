export module LLIRBuilderData;
import LLIR;
import AST;
import TreeAPI;
import types;
import std;
import std.compat;
namespace LLIR {
    export class BuilderData {
    public:
        using SymbolFollow = vector<std::pair<vector<std::string>, std::set<vector<std::string>>>>;
        size_t variable_count = 0;
        bool isToken = false;
        bool insideLoop = false;
        bool addSpaceSkip = false;
        bool isFirst = true;
        int tokensOnly = -1;
        vector<std::string> fullname;
        vector<LLIR::variable> vars;
        vector<std::pair<std::string, LLIR::variable>> key_vars;
        vector<LLIR::variable> unnamed_datablock_units;
        SymbolFollow symbol_follow;
        bool has_symbol_follow = true;
        AST *tree;
        BuilderData(AST &tree) : tree(&tree) {}
    };
}