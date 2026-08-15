export module DFA;

import NFA;

import DFA.API;
import DFA.States;
import DFA.closure;

import LangAPI;


import hash;
import logging;
import corelib;
import cpuf.op;
import dstd;
import std; // Added for std::variant

export namespace DFA {
    // -------------------------------------

    struct ClassifiedDFA {
        CharClassTable table;
        States<State<ClassTransitions>> states = {nullptr};

        friend auto operator<<(std::ostream& os, const ClassifiedDFA& dfa) -> std::ostream&;
    };

    class DFA {
        States<SingleState> states;
        NFA &nfa;
        stdu::vector<NFA::ActionState> lr_table;
        stdu::vector<NFA::SemanticState> semantic_table;
        auto sameAcceptBinding(const SingleState &a,const SingleState &b) -> bool;
        auto initialClass(const SingleState &s) -> std::size_t;
        auto refinementKey(const SingleState &s, const std::unordered_map<std::size_t, std::size_t> &partition_of) -> std::vector<TransitionKeyExt>;
        void optimizeRegistersAndLRTable();
        void optimizeSemanticTable();
        auto clear() -> void;
        auto getType() const -> DfaType;
        auto check_dfa() -> void;

    public:
        DFA(NFA *nfa) : nfa(*nfa), states(nfa) {}
        auto build() -> const States<SingleState>&;
        auto minimize() -> States<SingleState>;
        auto classify() -> ClassifiedDFA;
        auto &get() { return states; }
        auto &get() const { return states; }
        auto &getLR() { return lr_table; }
        auto &getLR() const { return lr_table; }
        auto &getSemantic() { return semantic_table; }
        auto &getSemantic() const { return semantic_table; }
    };

    auto operator<<(std::ostream& os, const DFA& dfa) -> std::ostream&;
    auto operator<<(std::ostream& os, const ClassifiedDFA& dfa) -> std::ostream&;
}