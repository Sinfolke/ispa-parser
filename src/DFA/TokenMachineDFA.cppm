export module DFA.TokenMachineDFA;

import NFA;

import DFA.API;
import DFA.Base;
import DFA.SDFA;
import DFA.States;

import AST.Tree;

import hash;

import dstd;
import std;

export namespace DFA {
    class TokenMachineDFA : Base {
        const AST::Tree &ast;
        SDFA &sdfa;
        States<SingleState> states;

        void partitionState(std::size_t state_id);
    public:
        using StatesType = decltype(states);
        TokenMachineDFA(const AST::Tree &ast, SDFA &sorted_dfa) : ast(ast), states(nullptr), sdfa(sorted_dfa), Base(sorted_dfa.getEmptyState()) {};
        TokenMachineDFA(const AST::Tree &ast, SDFA &sorted_dfa, const DfaEmptyStateMap &dfa_empty_state_map, const DfaIndexToEmptyStateMap &dfa_index_to_empty_state_map)
        : ast(ast), states(nullptr), sdfa(sorted_dfa), Base(dfa_empty_state_map, dfa_index_to_empty_state_map) {};
        TokenMachineDFA(const AST::Tree &ast, const NFA &nfa, SDFA &sorted_dfa) : ast(ast), states(&nfa), sdfa(sorted_dfa), Base(sorted_dfa.getEmptyState()) {};
        TokenMachineDFA(const AST::Tree &ast, const NFA &nfa, SDFA &sorted_dfa, const DfaEmptyStateMap &dfa_empty_state_map, const DfaIndexToEmptyStateMap &dfa_index_to_empty_state_map)
        : ast(ast), states(&nfa), sdfa(sorted_dfa), Base(dfa_empty_state_map, dfa_index_to_empty_state_map) {};

        auto build() -> const States<SingleState>&;
        auto &get()       { return states; }
        auto &get() const { return states; }

        auto getType(bool isToken, const utype::unordered_map<stdu::vector<std::string>, std::size_t> *dct) const -> DfaType;

        auto clear() -> void;
    };
}