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
    public:
        MDFA(const NFA &nfa) : nfa(nfa), states(&nfa) {}
        MDFA(const NFA &nfa, const DfaEmptyStateMap &dfa_empty_state_map, const DfaIndexToEmptyStateMap &dfa_index_to_empty_state_map)
        : nfa(nfa), states(&nfa), Base(dfa_empty_state_map, dfa_index_to_empty_state_map) {}
        auto build() -> const States<MultiState>&;

        auto &get()                     const { return states; }
        auto &get()                           { return states; }

        auto clear() -> void;

        auto getType(bool isToken, const utype::unordered_map<stdu::vector<std::string>, std::size_t> *dct) const -> DfaType;
    };
}