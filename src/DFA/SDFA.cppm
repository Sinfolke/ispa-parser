export module DFA.SDFA;

import NFA;
import DFA.API;
import DFA.States;
import DFA.MDFA;
import DFA.Base;
import hash;
import dstd;
import std;
export namespace DFA {
    /*
     * SingleState DFA. That means it has only one next state for the symbol.
     * The next step after MDFA
     */
    class SDFA : public Base {
        MDFA &mdfa;
        States<SingleState> states;
        void unrollMultiTransition(std::size_t state_id, const NFA::TransitionKey &symbol, stdu::vector<MultiTransitionValue> &val, SeenSymbol &seen, WalkedState &walked_state);
    public:
        SDFA(MDFA &mdfa_) : states(nullptr), mdfa(mdfa_), Base(mdfa_.getEmptyState()) {}
        SDFA(MDFA &mdfa_, DfaEmptyStateMap &empty_state_map, DfaIndexToEmptyStateMap &index_state_map) : states(nullptr), mdfa(mdfa_), Base(empty_state_map, index_state_map){}
        SDFA(NFA &nfa, MDFA &mdfa_) : states(&nfa), mdfa(mdfa_), Base(mdfa_.getEmptyState()) {}
        SDFA(NFA &nfa, MDFA &mdfa_, DfaEmptyStateMap &empty_state_map, DfaIndexToEmptyStateMap &index_state_map) : states(&nfa), mdfa(mdfa_), Base(empty_state_map, index_state_map) {}
        auto build() -> const States<SingleState>&;

        auto &get() const       { return states; }
        auto &get()             { return states; }

        auto clear() -> void;

        auto getType() const -> DfaType;
    };
}