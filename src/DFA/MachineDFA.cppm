export module DFA.MachineDFA;

import NFA;
import DFA.API;
import DFA.Base;
import DFA.SortedDFA;
import DFA.States;
import AST.Tree;
import hash;
import dstd;
import std;
export namespace DFA {
    class MachineDFA : Base {
        const AST::Tree &ast;
        SortedDFA &sorted_dfa;
        States<SortedState> states;

        void partitionState(std::size_t state_id);
    public:
        MachineDFA(const AST::Tree &ast, SortedDFA &sorted_dfa) : ast(ast), states(nullptr), sorted_dfa(sorted_dfa) {};
        MachineDFA(const AST::Tree &ast, SortedDFA &sorted_dfa, const DfaEmptyStateMap &dfa_empty_state_map, const DfaIndexToEmptyStateMap &dfa_index_to_empty_state_map)
        : ast(ast), states(nullptr), sorted_dfa(sorted_dfa), Base(dfa_empty_state_map, dfa_index_to_empty_state_map) {};
        MachineDFA(const AST::Tree &ast, const NFA &nfa, SortedDFA &sorted_dfa) : ast(ast), states(&nfa), sorted_dfa(sorted_dfa) {};
        MachineDFA(const AST::Tree &ast, const NFA &nfa, SortedDFA &sorted_dfa, const DfaEmptyStateMap &dfa_empty_state_map, const DfaIndexToEmptyStateMap &dfa_index_to_empty_state_map)
        : ast(ast), states(&nfa), sorted_dfa(sorted_dfa), Base(dfa_empty_state_map, dfa_index_to_empty_state_map) {};

        auto build() -> States<SortedState>;;
        auto &get()       { return states; }
        auto &get() const { return states; }

        auto getType(bool isToken, const utype::unordered_map<stdu::vector<std::string>, std::size_t> *dct) const -> DfaType;
    };
}