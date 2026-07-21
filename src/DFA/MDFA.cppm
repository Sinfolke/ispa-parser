export module DFA.MDFA;

import NFA;
import DFA.API;
import DFA.States;
import DFA.Base;
import hash;
import dstd;
import std;

export namespace DFA {
    /*
     * MultiState DFA - A DFA uses MultiState under the hood. That means it may have several different next states under one transition.
     * A this is the next step after NFA building
     */
    class MDFA : public Base {
        const NFA& nfa;
        States<MultiState> states;
        bool allow_accept_index = true;
    public:
        MDFA(const NFA &nfa, bool allow_accept_index = true) : nfa(nfa), states(&nfa), allow_accept_index(allow_accept_index) {}
        MDFA(const NFA &nfa, const DfaEmptyStateMap &dfa_empty_state_map, const DfaIndexToEmptyStateMap &dfa_index_to_empty_state_map, bool allow_accept_index = true)
        : nfa(nfa), states(&nfa), Base(dfa_empty_state_map, dfa_index_to_empty_state_map), allow_accept_index(allow_accept_index) {}
        auto build() -> const States<MultiState>&;

        auto &get()                     const { return states; }
        auto &get()                           { return states; }

        auto clear() -> void;

        auto getType() const -> DfaType;
        auto check_dfa() -> void override;
        friend auto operator<<(std::ostream &os, const MDFA &dfa) -> std::ostream&;
    };
}
