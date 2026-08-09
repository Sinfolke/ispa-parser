export module DFA.functionality;

import NFA;
import DFA.API;
import DFA;
import AST.Tree;
import dstd;
import std;
export namespace DFA {
    void mergeTwoNFA(NFA &first, NFA &second, std::size_t rule_idx);
    auto mergeNFAS(const stdu::vector<NFA> &nfas) -> NFA;
    auto build(const AST::Tree &ast, const NFA &nfa) -> DFA;
    auto build(const AST::Tree &ast, const stdu::vector<NFA> &nfa_collection) -> ClassifiedDFA;
}