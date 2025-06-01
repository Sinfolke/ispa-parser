export module DFA;
import hash;
import NFA;
import dstd;
import std;
import std.compat;
export class DFA {
public:
    struct state {
        utype::unordered_set<size_t> nfa_states; // the NFA states this DFA state represents
        utype::unordered_map<stdu::vector<std::string>, size_t> transitions;
        size_t accept_index = NFA::NO_ACCEPT;
    };
private:
    const stdu::vector<NFA::state> *nfa_states;
    stdu::vector<state> states;
    auto epsilonClosure(const std::set<size_t>& state_indices) -> std::set<size_t>;
    auto move(const std::set<size_t> &states, const stdu::vector<std::string> &symbol) -> std::set<size_t>;
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