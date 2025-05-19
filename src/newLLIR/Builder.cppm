export module LLIRBuilder;
import LLIR;
import AST;
import std;
import std.compat;
namespace LLIR {
    export class Builder {
        size_t variable_count = 0;
        bool isToken = false;
        bool insideLoop = false;
        bool addSpaceSkip = false;
        bool isFirst = true;
        int tokensOnly = -1;
        std::vector<std::string> fullname;
        std::vector<LLIR::variable> vars;
        std::vector<LLIR::member> members;
        std::vector<LLIR::ConvertionResult> success_vars;
        std::vector<std::pair<std::string, LLIR::variable>> key_vars;
        std::vector<LLIR::variable> unnamed_datablock_units;
        AST *tree;
    public:
        Builder(AST &tree) : tree(&tree) {
            //LLIRBuilder() {}
        }
    };
}