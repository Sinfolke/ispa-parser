export module DFA.functionality;

import NFA;
import DFA.API;
import DFA.MDFA;
import DFA.CharMachineDFA;
import AST.Tree;
import dstd;
import std;
export namespace DFA {
    auto buildDfaIndexToEmptyStateMap(stdu::vector<MDFA> &dfas) -> DfaIndexToEmptyStateMap;
    auto buildDfaEmptyStateMap(stdu::vector<MDFA> &dfas) -> DfaEmptyStateMap;
    auto mergeTwoDFA(MDFA &first, const MDFA &second, std::size_t index) -> void;
    auto mergeDFAS(stdu::vector<MDFA> &dfas) -> MDFA;
    auto build(const AST::Tree &ast, const NFA &nfa) -> CharMachineDFA;
    auto build(const AST::Tree &ast, const stdu::vector<NFA> &nfa_collection) -> CharMachineDFA;
}