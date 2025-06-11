export module DFA;
import hash;
import NFA;
import AST.API;
import AST.Tree;
import dstd;
import std;
import std.compat;
export class DFA {
public:
    struct TransitionValue {
        size_t next;
        size_t accept_index = NFA::NO_ACCEPT;
        bool operator==(const TransitionValue &other) const = default;
    private:
        friend struct uhash;
        auto members() const {
            return std::tie(next, accept_index);
        }
    };
    template<typename Transition>
    struct State {
        utype::unordered_set<size_t> nfa_states; // the NFA states this DFA state represents
        Transition transitions;
        size_t else_goto = 0;
        size_t else_goto_accept = NFA::NO_ACCEPT;
        bool operator==(const State &other) const = default;
    private:
        friend struct uhash;
        auto members() const {
            return std::tie(nfa_states, transitions, else_goto, else_goto_accept);
        }
    };
    using Transitions = utype::unordered_map<NFA::TransitionKey, TransitionValue>;
    using MultiTransitions = utype::unordered_map<NFA::TransitionKey, stdu::vector<TransitionValue>>;

    using MultiState = State<MultiTransitions>;
    using SingleState = State<Transitions>;
    using SeenSymbol = utype::unordered_map<NFA::TransitionKey, utype::unordered_set<std::unordered_set<size_t>>>;
    using WalkedState = utype::unordered_set<size_t>;
private:
    const NFA *nfa;
    stdu::vector<MultiState> mstates;
    stdu::vector<SingleState> states;
    auto epsilonClosure(const std::vector<size_t>& state_indices) const -> std::vector<size_t>;
    auto move(const std::vector<size_t> &states, const NFA::TransitionKey &symbol) const -> std::vector<size_t>;
    auto findEmptyState() -> size_t;
    bool leadToEmptyState(size_t current);
    bool includesWhitespace(const MultiState &state);
    bool isTerminateState(const MultiState &state);
    void removeDublicateStates();
    void unrollMultiTransition(const NFA::TransitionKey &symbol, stdu::vector<TransitionValue> &val, SeenSymbol &seen, WalkedState &walked_state);
    void unrollMultiTransitionPaths();
    void switchToSingleState();
    void accumulateTerminalStates(size_t i, std::unordered_set<size_t> &terminals, std::unordered_set<size_t> &visited);
    void terminateEarly();
    void WalkDfaToGetUnreachableStates(size_t i, std::unordered_set<size_t> &reachable);
    void removeUnreachableStates();
public:
    DFA(const NFA &nfa) : nfa(&nfa) {}
    DFA(const stdu::vector<SingleState> &already_build_states) : states(already_build_states) {}
    void build();
    auto &getStates() const { return states; }
    auto &getMultiStates() const { return mstates; }
};
export class DFABuilder {
    DFA dfa;
    public:
    DFABuilder(const AST::Tree& ast, const AST::RuleMember &rule) : dfa({}) {
        NFA nfa(ast, rule);
        nfa.build();
        DFA dfa_tmp(nfa);
        dfa_tmp.build();
        dfa = std::move(dfa_tmp);
    }
    DFA& get() {
        return dfa;
    }
};
// Print a single state
export std::ostream& operator<<(std::ostream& os, const DFA::MultiState& s);
// Print all states in the vector
export std::ostream& operator<<(std::ostream& os, const DFA& states);

// Outside the struct
std::ostream &operator<<(std::ostream &os, const DFA::TransitionValue &tv) {
    return os << "(" << tv.next << ", " << tv.accept_index << ")";
}
