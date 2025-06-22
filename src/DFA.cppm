export module DFA;
import hash;
import NFA;
import AST.API;
import AST.Tree;
import Dump;
import dstd;
import std;
import std.compat;
export class DFA {
public:
    enum class DfaType {
        Char, Token, CallableToken, Multi, NONE
    };
    struct TransitionValue {
        std::size_t next;
        std::size_t accept_index = NFA::NO_ACCEPT;
        bool operator==(const TransitionValue &other) const = default;
    private:
        friend struct uhash;
        auto members() const {
            return std::tie(next, accept_index);
        }
    };
    template<typename Transition>
    struct State {
        utype::unordered_set<std::size_t> nfa_states; // the NFA states this DFA state represents
        Transition transitions;
        std::size_t else_goto = 0;
        std::size_t else_goto_accept = NFA::NO_ACCEPT;
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
    using SeenSymbol = utype::unordered_map<NFA::TransitionKey, utype::unordered_set<std::unordered_set<std::size_t>>>;
    using WalkedState = utype::unordered_set<std::size_t>;
private:
    const NFA *nfa;
    const stdu::vector<NFA> *mergable_nfas = nullptr;
    stdu::vector<MultiState> mstates;
    stdu::vector<SingleState> states;
    auto epsilonClosure(const stdu::vector<std::size_t>& state_indices) const -> stdu::vector<std::size_t>;
    auto move(const stdu::vector<std::size_t> &states, const NFA::TransitionKey &symbol) const -> stdu::vector<std::size_t>;
    auto findEmptyState() const -> std::size_t;
    bool leadToEmptyState(std::size_t current) const;
    bool includesWhitespace(const MultiState &state) const;
    bool isTerminateState(const MultiState &state) const;
    void removeDublicateStates();
    void unrollMultiTransition(const NFA::TransitionKey &symbol, stdu::vector<TransitionValue> &val, SeenSymbol &seen, WalkedState &walked_state);
    void unrollMultiTransitionPaths();
    void switchToSingleState();
    void accumulateTerminalStates(std::size_t i, std::unordered_set<std::size_t> &terminals, std::unordered_set<std::size_t> &visited);
    void terminateEarly();
    void WalkDfaToGetUnreachableStates(std::size_t i, std::unordered_set<std::size_t> &reachable);
    void removeUnreachableStates();
    void removeSelfLoop();
    static auto mergeTwoDFA(DFA &first, const DFA &second);
    auto mergeDFAS(stdu::vector<DFA> &dfas) -> DFA;
public:
    DFA(const NFA &nfa) : nfa(&nfa) {}
    DFA(const stdu::vector<NFA> &mergable_nfa) : mergable_nfas(&mergable_nfa) {}
    DFA(const stdu::vector<SingleState> &already_build_states) : states(already_build_states) {}
    void build(bool switchToSingleState = true);
    void buildWMerge();
    auto &getStates() { return states; }
    auto &getMultiStates() { return mstates; }
    auto &getStates() const { return states; }
    auto &getMultiStates() const { return mstates; }
    auto getType(bool isToken) const -> DfaType;
    auto getTypeStr(bool isToken) const -> std::string;
    auto getSpanTypeStr(bool isToken) const -> std::string;
    auto getTransitionType(bool isToken) const -> std::string;
    static auto getTransitionType(const NFA::TransitionKey &transition_key, bool isToken) -> DfaType;
    static auto getTransitionTypeStr(const NFA::TransitionKey &transition_key, bool isToken) -> std::string;

    auto getStateType(bool isToken) const -> std::string;
    static auto getStateType(const Transitions &transitions, bool isToken) -> DfaType;
    static auto getStateTypeStr(const Transitions &transitions, bool isToken) -> std::string;
    auto getMaxTransitionCount() const -> std::size_t;
};

// Print a single state
export std::ostream& operator<<(std::ostream& os, const DFA::MultiState& s);
// Print all states in the vector
export std::ostream& operator<<(std::ostream& os, const DFA& states);

// Outside the struct
std::ostream &operator<<(std::ostream &os, const DFA::TransitionValue &tv) {
    return os << "(" << tv.next << ", " << tv.accept_index << ")";
}
