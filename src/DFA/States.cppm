export module DFA.States;

import DFA.API;
import NFA;
import dstd;
import std;

export namespace DFA {
    template<typename State>
    class States {
        const NFA *nfa;
        stdu::vector<State> states;
        auto leadToEmptyState(std::size_t current, std::unordered_set<std::size_t> &visited) const -> std::size_t;
        auto leadToEmptyStateDfa(const std::size_t current, std::unordered_set<std::size_t> &visited) -> std::size_t;
    public:
        States(const NFA *nfa) : nfa(nfa) {}
        States(const NFA *nfa, stdu::vector<State> states) : nfa(nfa), states(states) {}

        auto leadToEmptyState(std::size_t current) const -> std::size_t;
        auto leadToEmptyStateDfa(const std::size_t current) -> std::size_t;
        auto canBeEndState(const std::size_t current) -> std::size_t;
        auto includesWhitespace(const State &state) const -> bool;
        auto isTerminateState(const State &state) const -> bool;

        auto &get() const { return states; }
        auto &get()       { return states; }

        auto makeNew() -> std::size_t;
        auto empty() const -> bool;
        auto size() const -> std::size_t;
        auto clear() -> void;

        auto begin() const { return states.begin(); }
        auto end()   const { return states.end();   }

        auto &operator[](const std::size_t index) { return states.at(index); }
    };
}
