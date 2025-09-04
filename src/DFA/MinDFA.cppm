export module DFA.MinDFA;

import NFA;
import DFA.SDFA;
import DFA.API;
import DFA.Base;
import DFA.States;
import hash;
import dstd;
import std;
export namespace DFA {
    /*
     * Minimal DFA. On this stage the DFA is minimized
     * Next step after SDFA
     */
    class MinDFA : public Base {
        SDFA sdfa;
        States<SingleState> states;
        static void accumulateTerminalStates(SDFA &sdfa, std::size_t i, std::unordered_set<std::size_t> &terminals, std::unordered_set<std::size_t> &visited);
        static void WalkDfaToGetUnreachableStates(SDFA &sdfa, std::size_t i, std::unordered_set<std::size_t> &reachable);
        void removeDublicateStates();
        void terminateEarly();
        void removeUnreachableStates();
        void removeSelfLoop();
    public:
        static void removeDublicateStates(SDFA &sdfa);
        static void terminateEarly(SDFA &sdfa);
        static void removeUnreachableStates(SDFA &sdfa);
        static void removeSelfLoop(SDFA &sdfa);
        static void minimize(SDFA &sdfa);
        void minimize();
        MinDFA(SDFA &sdfa) : sdfa(sdfa), states(nullptr), Base(sdfa.getEmptyState()) {};
        MinDFA(SDFA &sdfa, const DfaEmptyStateMap &dfa_empty_state_map, const DfaIndexToEmptyStateMap &dfa_index_to_empty_state_map) : sdfa(sdfa), states(nullptr), Base(dfa_empty_state_map, dfa_index_to_empty_state_map) {};
        MinDFA(const NFA &nfa, SDFA &sdfa) : sdfa(sdfa), states(&nfa), Base(sdfa.getEmptyState()) {};
        MinDFA(const NFA &nfa, SDFA &sdfa, const DfaEmptyStateMap &dfa_empty_state_map, const DfaIndexToEmptyStateMap &dfa_index_to_empty_state_map) : sdfa(sdfa), states(&nfa), Base(dfa_empty_state_map, dfa_index_to_empty_state_map) {};

        auto &get() { return states; }
        auto &get() const { return states; }

        auto getType(bool isToken, const utype::unordered_map<stdu::vector<std::string>, std::size_t> *dct) const -> DfaType;

        auto clear() -> void;
    };
}