export module DFA.closure;

import NFA;

import hash;
import dstd;
import std;

export namespace DFA {
    class Closure {
        const NFA &nfa;
        const stdu::vector<std::size_t> &current;
        const NFA::TransitionKey *symbol = nullptr;
        stdu::vector<std::size_t> closure;
        void epsilonClosure();
        void move();
        friend struct ::uhash;
        auto members() {
            return std::tie(closure);
        }
    public:
        Closure(const NFA &nfa, const stdu::vector<std::size_t> &current);
        Closure(const NFA &nfa, const stdu::vector<std::size_t> &current, const NFA::TransitionKey &symbol);

        auto begin() const { return closure.begin(); }
        auto end() const { return closure.end(); }
        auto rbegin() const { return closure.rbegin(); }
        auto rend() const { return closure.rend(); }

        auto get()       { return closure; };
        auto get() const { return closure; };
        auto empty() const { return closure.empty(); };

        auto operator==(const Closure &other) const {
            return closure == other.closure;
        }
    };
}
