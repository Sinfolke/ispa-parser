export module DFA.CharMachineDFA;

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
    class CharMachineDFA : public Base {
        const AST::Tree &ast;
        SortedDFA &sorted_dfa;
        States<CharMachineState> states;

        void partitionState(std::size_t state_id);
    public:
        using StatesType = decltype(states);
        using StateType = CharMachineState;
        CharMachineDFA(const AST::Tree &ast, SortedDFA &sorted_dfa_) : Base(sorted_dfa_.getEmptyState()), ast(ast), states(nullptr), sorted_dfa(sorted_dfa_) {};
        CharMachineDFA(const AST::Tree &ast, SortedDFA &sorted_dfa_, const DfaEmptyStateMap &dfa_empty_state_map, const DfaIndexToEmptyStateMap &dfa_index_to_empty_state_map)
        : ast(ast), states(nullptr), sorted_dfa(sorted_dfa_), Base(dfa_empty_state_map, dfa_index_to_empty_state_map) {};
        CharMachineDFA(const AST::Tree &ast, const NFA &nfa, SortedDFA &sorted_dfa_) : Base(sorted_dfa_.getEmptyState()), ast(ast), states(&nfa), sorted_dfa(sorted_dfa_) {};
        CharMachineDFA(const AST::Tree &ast, const NFA &nfa, SortedDFA &sorted_dfa_, const DfaEmptyStateMap &dfa_empty_state_map, const DfaIndexToEmptyStateMap &dfa_index_to_empty_state_map)
        : ast(ast), states(&nfa), sorted_dfa(sorted_dfa_), Base(dfa_empty_state_map, dfa_index_to_empty_state_map) {};

        auto build() -> const States<CharMachineState>&;
        auto &get()       { return states; }
        auto &get() const { return states; }

        auto getType() const -> DfaType;

        auto clear() -> void;

    };
    auto operator<<(std::ostream &os, const CharMachineDFA &dfa) -> std::ostream&;
}
