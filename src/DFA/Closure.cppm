export module DFA.closure;

import NFA;

import hash;
import dstd;
import std;

export namespace DFA {
    class Closure {
        const NFA &nfa;
        stdu::vector<std::size_t> closure;

        void epsilonClosure(const stdu::vector<std::size_t> &source);
        void move(const stdu::vector<std::size_t> &src, const NFA::TransitionKey &sym);

        friend struct ::uhash;
        auto members() const {
            return std::tie(closure);
        }

    public:
        Closure(const NFA &nfa, const stdu::vector<std::size_t> *current = nullptr);
        Closure(const NFA &nfa, const stdu::vector<std::size_t> &current);
        Closure(const NFA &nfa, const stdu::vector<std::size_t> &current, const NFA::TransitionKey &symbol);

        auto begin() { return closure.begin(); }
        auto end() { return closure.end(); }
        auto begin() const { return closure.begin(); }
        auto end() const { return closure.end(); }
        auto cbegin() const { return closure.cbegin(); }
        auto cend() const { return closure.cend(); }
        auto rbegin() const { return closure.rbegin(); }
        auto rend() const { return closure.rend(); }

        auto &get()       { return closure; }
        const auto &get() const { return closure; }
        auto empty() const { return closure.empty(); }

        auto operator==(const Closure &other) const {
            return closure == other.closure;
        }
    };
}