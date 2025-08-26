export module DFA.MinDFA;

import DFA.SDFA;
import DFA.API;
import DFA.Base;
import std;
export namespace DFA {
    /*
     * Minimal DFA. On this stage the DFA is minimized
     * Next step after SDFA
     */
    class MinDFA : public Base {
        SDFA sdfa;
        static void accumulateTerminalStates(SDFA &sdfa, std::size_t i, std::unordered_set<std::size_t> &terminals, std::unordered_set<std::size_t> &visited);
        static void WalkDfaToGetUnreachableStates(SDFA &sdfa, std::size_t i, std::unordered_set<std::size_t> &reachable);
        void removeDublicateStates();
        void switchToSingleState();
        void terminateEarly();
        void removeUnreachableStates();
        void removeSelfLoop();
    public:
        static void removeDublicateStates(SDFA &sdfa);
        static void switchToSingleState(SDFA &sdfa);
        static void terminateEarly(SDFA &sdfa);
        static void removeUnreachableStates(SDFA &sdfa);
        static void removeSelfLoop(SDFA &sdfa);
        static void minimize(SDFA &sdfa);
        void minimize();
        MinDFA(SDFA &sdfa, const DfaEmptyStateMap &dfa_empty_state_map, const DfaIndexToEmptyStateMap &dfa_index_to_empty_state_map) : sdfa(sdfa), Base(dfa_empty_state_map, dfa_index_to_empty_state_map) {};
    };
}