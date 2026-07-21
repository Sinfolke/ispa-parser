export module DFA.Base;

import LangAPI;
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
        auto getType(const States<StateType> &states) const -> DfaType;
    public:
        Base() = default;
        Base(std::size_t empty_state, bool merged = false) : empty_state(empty_state), merged(merged) {}
        Base(const DfaEmptyStateMap &dfa_empty_state_map, const DfaIndexToEmptyStateMap &dfa_index_to_empty_state_map, bool merged = false) : dfa_empty_state_map_(dfa_empty_state_map), dfa_index_to_empty_state_map_(dfa_index_to_empty_state_map), merged(merged) {};
        Base(const DfaEmptyStateMap &dfa_empty_state_map, const DfaIndexToEmptyStateMap &dfa_index_to_empty_state_map, std::size_t empty_state, bool merged = false)
        : dfa_empty_state_map_(dfa_empty_state_map), dfa_index_to_empty_state_map_(dfa_index_to_empty_state_map), empty_state(empty_state), merged(merged) {}
        virtual ~Base() = default;
        auto &getEmptyStateMap()        const { return dfa_empty_state_map_; }
        auto &getEmptyStateMap()              { return dfa_empty_state_map_; }
        auto &getIndexToEmptyStateMap() const { return dfa_index_to_empty_state_map_; }
        auto &getIndexToEmptyStateMap()       { return dfa_index_to_empty_state_map_; }

        auto getEmptyState(std::size_t stateIndex) const -> std::size_t;
        auto getEmptyStateIF(std::size_t stateIndex) const -> std::size_t;
        auto getEmptyState() -> std::size_t&;
        auto hasOneEmptyState() -> bool;
        auto getEmptyStateByDfaId(std::size_t dfaIndex) -> std::size_t;
        auto isMerged() -> bool;
        static auto getTransitionKeyType(const NFA::TransitionKey &transition_key) -> DfaType;
        template<typename Transitions>
        static auto getStateType(const Transitions &transitions) -> DfaType;

        template<typename DfaType>
        auto getDfaNames(const DfaType &dfa) -> stdu::vector<std::pair<stdu::vector<std::string>, NFA::DataBlock>> {
            utype::unordered_set<std::pair<stdu::vector<std::string>, NFA::DataBlock>> names;
            for (const auto &state : dfa.get()) {
                names.insert(std::make_pair(state.rule_name, state.dtb));
            };
            return {names.begin(), names.end()};
        }
        virtual auto check_dfa() -> void {};
    };
}
