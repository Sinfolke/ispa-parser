export module LLIR.Builder.Data;
import LLIR.API;
import AST.Tree;
import AST.API;
import DFA.TokenMachineDFA;
import DFA.Collection;
import dstd;
import std;

namespace LLIR {
    export class BuilderData {
    public:
        using SymbolFollow = stdu::vector<std::pair<stdu::vector<std::string>, std::set<stdu::vector<std::string>>>>;
        std::size_t variable_count = 0;
        bool isToken = false;
        bool insideLoop = false;
        bool addSpaceSkip = false;
        bool isFirst = true;
        int tokensOnly = -1;
        stdu::vector<std::string> fullname;
        stdu::vector<LLIR::variable> vars;
        stdu::vector<std::pair<std::string, LLIR::variable>> key_vars;
        stdu::vector<LLIR::variable> unnamed_datablock_units;
        SymbolFollow symbol_follow;
        bool has_symbol_follow = true;
        AST::Tree *tree;
        DFA::Collection<DFA::TokenMachineDFA> *dfas = nullptr;
        BuilderData(AST::Tree &tree, DFA::Collection<DFA::TokenMachineDFA> *dfas) : tree(&tree), dfas(dfas) {}
    };
}