export module DFA.Base;

import NFA;
import DFA.API;
import DFA.States;
import hash;
import dstd;
import std;

namespace DFA {
    export class Base {
    protected:
        DfaEmptyStateMap dfa_empty_state_map_;
        DfaIndexToEmptyStateMap dfa_index_to_empty_state_map_;
        std::size_t empty_state = NULL_STATE;
        bool merged = false;

        template<typename StateType>
        auto getType(const States<StateType> &states, bool isToken, const utype::unordered_map<stdu::vector<std::string>, std::size_t> *dct) const -> DfaType;
    public:
        Base() = default;
        Base(std::size_t empty_state) : empty_state(empty_state) {}
        Base(const DfaEmptyStateMap &dfa_empty_state_map, const DfaIndexToEmptyStateMap &dfa_index_to_empty_state_map) : dfa_empty_state_map_(dfa_empty_state_map), dfa_index_to_empty_state_map_(dfa_index_to_empty_state_map), merged(true) {};
        Base(const DfaEmptyStateMap &dfa_empty_state_map, const DfaIndexToEmptyStateMap &dfa_index_to_empty_state_map, std::size_t empty_state)
        : dfa_empty_state_map_(dfa_empty_state_map), dfa_index_to_empty_state_map_(dfa_index_to_empty_state_map), empty_state(empty_state), merged(true) {}
        virtual ~Base() = default;
        auto &getEmptyStateMap()        const { return dfa_empty_state_map_; }
        auto &getEmptyStateMap()              { return dfa_empty_state_map_; }
        auto &getIndexToEmptyStateMap() const { return dfa_index_to_empty_state_map_; }
        auto &getIndexToEmptyStateMap()       { return dfa_index_to_empty_state_map_; }

        auto getEmptyState(std::size_t stateIndex) -> std::size_t;
        auto getEmptyState() -> std::size_t&;
        auto getEmptyStateByDfaId(std::size_t dfaIndex) -> std::size_t;
        auto isMerged() -> bool;

        static auto getTransitionKeyType(const NFA::TransitionKey &transition_key, bool isToken) -> DfaType;
        template<typename Transitions>
        static auto getStateType(const Transitions &transitions, const utype::unordered_map<stdu::vector<std::string>, std::size_t> *dct, bool isToken) -> DfaType;

    };
}
