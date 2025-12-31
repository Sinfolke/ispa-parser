export module DFA.functionality;

import NFA;
import DFA.API;
import DFA.MDFA;
import DFA.CharMachineDFA;
import DFA.TokenMachineDFA;
import AST.Tree;
import dstd;
import std;
export namespace DFA {
    auto buildDfaIndexToEmptyStateMap(stdu::vector<MDFA> &dfas) -> DfaIndexToEmptyStateMap;
    auto buildDfaEmptyStateMap(stdu::vector<MDFA> &dfas, const stdu::vector<NFA> &nfas) -> DfaEmptyStateMap;
    auto mergeTwoDFA(MDFA &first, const MDFA &second, std::size_t index) -> void;
    auto mergeDFAS(stdu::vector<MDFA> &dfas) -> MDFA;
    auto build(const AST::Tree &ast, const NFA &nfa) -> TokenMachineDFA;
    auto build(const AST::Tree &ast, const stdu::vector<NFA> &nfa_collection) -> CharMachineDFA;
}