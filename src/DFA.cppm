export module DFA;
import hash;
import NFA;
import dstd;
import std;
import std.compat;
export class DFA {
public:
    struct transition_value;
    using Transitions = utype::unordered_map<stdu::vector<std::string>, stdu::vector<transition_value>>;
    struct transition_value {
        size_t next;
        size_t accept_index = NFA::NO_ACCEPT;
        bool operator==(const transition_value &other) const = default;
    };
    struct state {
        utype::unordered_set<size_t> nfa_states; // the NFA states this DFA state represents
        Transitions transitions;
        size_t else_goto = 0;
        size_t else_goto_accept = NFA::NO_ACCEPT;
        bool operator==(const state &other) const = default;
    };
    using SeenSymbol = utype::unordered_map<stdu::vector<std::string>, utype::unordered_set<std::unordered_set<size_t>>>;
    using WalkedState = utype::unordered_set<size_t>;
private:
    const NFA *nfa;
    stdu::vector<state> states;
    auto epsilonClosure(const stdu::vector<size_t>& state_indices) const -> stdu::vector<size_t>;
    auto move(const stdu::vector<size_t> &states, const stdu::vector<std::string> &symbol) const -> std::vector<size_t>;
    void walkDfaToTerminate(size_t i);
    void removeDublicateStates();
    auto findEmptyState() -> size_t;
    bool leadToEmptyState(size_t current);
    void unrollMultiTransition(const stdu::vector<std::string> &symbol, stdu::vector<transition_value> &val, SeenSymbol &seen, WalkedState &walked_state);
    void unrollMultiTransitionPaths();
    void terminateEarly();
public:
    DFA(const NFA &nfa) : nfa(&nfa) {}
    DFA(const stdu::vector<state> &already_build_states) : states(already_build_states) {}
    void build();

    auto &getStates() const { return states; }
};
// Print a single state
export std::ostream& operator<<(std::ostream& os, const DFA::state& s);
// Print all states in the vector
export std::ostream& operator<<(std::ostream& os, const DFA& states);