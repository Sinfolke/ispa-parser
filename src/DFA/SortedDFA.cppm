export module DFA.SortedDFA;

import AST.Tree;
import NFA;
import DFA.API;
import DFA.MinDFA;
import DFA.States;
import DFA.Base;
import logging;
import hash;
import dstd;
import std;

export namespace DFA {
    class SortedDFA : public Base {
        const AST::Tree &ast;
        MinDFA &min_dfa;
        States<SortedState> states;
    public:
        void sort();
        SortedDFA(const AST::Tree &ast, MinDFA &min_dfa) : ast(ast), states(nullptr), min_dfa(min_dfa), Base(min_dfa.getEmptyState()) {};
        SortedDFA(const AST::Tree &ast, MinDFA &min_dfa, const DfaEmptyStateMap &dfa_empty_state_map, const DfaIndexToEmptyStateMap &dfa_index_to_empty_state_map)
        : ast(ast), states(nullptr), min_dfa(min_dfa), Base(dfa_empty_state_map, dfa_index_to_empty_state_map) {};
        SortedDFA(const AST::Tree &ast, const NFA &nfa, MinDFA &min_dfa) : ast(ast), states(&nfa), min_dfa(min_dfa), Base(min_dfa.getEmptyState()) {};
        SortedDFA(const AST::Tree &ast, const NFA &nfa, MinDFA &min_dfa, const DfaEmptyStateMap &dfa_empty_state_map, const DfaIndexToEmptyStateMap &dfa_index_to_empty_state_map)
        : ast(ast), states(&nfa), min_dfa(min_dfa), Base(dfa_empty_state_map, dfa_index_to_empty_state_map) {};

        auto &get()       { return states; }
        auto &get() const { return states; }

        auto getType(bool isToken, const utype::unordered_map<stdu::vector<std::string>, std::size_t> *dct) const -> DfaType;

        auto clear() -> void;
    };
}
