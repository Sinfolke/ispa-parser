module;
#include <vector>
#include <string>
#include <tree.h>
export module LLIRBuilder;
import LLIR;
export class LLIRBuilder {
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
    Tree *tree;
public:
    LLIRBuilder(Tree *tree) : tree(tree) {}
};