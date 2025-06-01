export module DFA;
import hash;
import NFA;
import dstd;
import std;
import std.compat;
export class DFA {
public:
    struct transition_value {
        size_t next;
        size_t ACCEPT_STATE = NFA::NO_ACCEPT;
    };
    struct state {
        utype::unordered_set<size_t> nfa_states; // the NFA states this DFA state represents
        utype::unordered_map<stdu::vector<std::string>, transition_value> transitions;
    };
private:
    const stdu::vector<NFA::state> *nfa_states;
    stdu::vector<state> states;
    auto epsilonClosure(const stdu::vector<size_t>& state_indices) const -> stdu::vector<size_t>;
    auto move(const stdu::vector<size_t> &states, const stdu::vector<std::string> &symbol) const -> std::vector<size_t>;
public:
    DFA(const stdu::vector<NFA::state> &states) : nfa_states(&states) {}
    DFA(const NFA &nfa) : nfa_states(&nfa.getStates()) {}
    DFA(const stdu::vector<state> &already_build_states) : states(already_build_states) {}
    void build();

    auto &getStates() const { return states; }
};
// Print a single state
export std::ostream& operator<<(std::ostream& os, const DFA::state& s);
// Print all states in the vector
export std::ostream& operator<<(std::ostream& os, const DFA& states);