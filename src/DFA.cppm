export module DFA;
import hash;
import NFA;
import AST.API;
import AST.Tree;
import Dump;
import ispastdlibcpp;
import dstd;
import std;

export class DFA {
public:
    enum class DfaType {
        Char, Token, CallableToken, Multi, NONE
    };
    struct TransitionValue {
        std::size_t next;
        bool new_cst_node = false;
        bool new_member = false;
        bool close_cst_node = false;
        std::size_t new_group = NFA::NULL_STATE;
        std::size_t group_close = NFA::NULL_STATE;
        std::size_t accept_index = NFA::NULL_STATE;
        bool operator==(const TransitionValue &other) const = default;
    private:
        friend struct uhash;
        auto members() const {
            return std::tie(next, new_cst_node, new_member, close_cst_node, new_group, group_close, accept_index);
        }
    };
    struct MultiTransitionValue {
        TransitionValue value;
        std::size_t dfa_merge_conflict = NFA::NULL_STATE;
        bool operator==(const MultiTransitionValue &second) const = default;
    private:
        friend struct uhash;
        auto members() const {
            return std::tie(value, dfa_merge_conflict);
        }
    };
    template<typename Transition>
    struct State {
        utype::unordered_set<std::size_t> nfa_states; // the NFA states this DFA state represents
        Transition transitions;
        std::size_t else_goto = 0;
        std::size_t any_goto = 0;
        std::size_t else_goto_accept = NFA::NULL_STATE;
        stdu::vector<std::string> rule_name;
        NFA::DataBlock dtb;
        bool operator==(const State &other) const = default;
    private:
        friend struct uhash;
        auto members() const {
            return std::tie(nfa_states, transitions, else_goto, any_goto, else_goto_accept, rule_name, dtb);
        }
    };

    using Transitions = utype::unordered_map<NFA::TransitionKey, TransitionValue>;
    using MultiTransitions = utype::unordered_map<NFA::TransitionKey, stdu::vector<MultiTransitionValue>>;

    using MultiState = State<MultiTransitions>;
    using SingleState = State<Transitions>;
    using SeenSymbol = utype::unordered_map<NFA::TransitionKey, utype::unordered_set<std::unordered_set<std::size_t>>>;
    using WalkedState = utype::unordered_set<std::size_t>;
    using DfaEmptyStateMap = std::unordered_map<std::size_t, std::size_t>;
    using DfaIndexToEmptyStateMap = std::unordered_map<std::size_t, std::size_t>;
private:
    const NFA *nfa = nullptr;
    const stdu::vector<NFA> *mergable_nfas = nullptr;
    stdu::vector<MultiState> mstates;
    stdu::vector<SingleState> states;
    DfaEmptyStateMap dfa_empty_state_map;
    DfaIndexToEmptyStateMap dfa_index_to_empty_state_map;
    std::size_t empty_state = NFA::NULL_STATE;
    auto epsilonClosure(const stdu::vector<std::size_t>& state_indices) const -> stdu::vector<std::size_t>;
    auto move(const stdu::vector<std::size_t> &states, const NFA::TransitionKey &symbol) const -> stdu::vector<std::size_t>;
    auto leadToEmptyState(std::size_t current, std::unordered_set<std::size_t> &visited) const -> std::size_t;
    auto leadToEmptyState(std::size_t current) const -> std::size_t;
    auto leadToEmptyStateDfa(const std::size_t current, std::unordered_set<std::size_t> &visited) -> std::size_t;
    auto leadToEmptyStateDfa(const std::size_t current) -> std::size_t;
    bool includesWhitespace(const MultiState &state) const;
    bool isTerminateState(const MultiState &state) const;
    void removeDublicateStates();
    void unrollMultiTransition(std::size_t state_id, const NFA::TransitionKey &symbol, stdu::vector<MultiTransitionValue> &val, SeenSymbol &seen, WalkedState &walked_state);
    void unrollMultiTransitionPaths();
    void switchToSingleState();
    void accumulateTerminalStates(std::size_t i, std::unordered_set<std::size_t> &terminals, std::unordered_set<std::size_t> &visited);
    void terminateEarly();
    void WalkDfaToGetUnreachableStates(std::size_t i, std::unordered_set<std::size_t> &reachable);
    void removeUnreachableStates();
    void removeSelfLoop();
    void buildDfaIndexToEmptyStateMap(stdu::vector<DFA> &dfas);
    void buildDfaEmptyStateMap(stdu::vector<DFA> &dfas);
    static auto mergeTwoDFA(DFA &first, const DFA &second, std::size_t index);
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
    auto getMaxTransitionCount() const -> std::size_t;

    auto getType(bool isToken, const utype::unordered_map<stdu::vector<std::string>, std::size_t> *dct) const -> DfaType;
    static auto getStateType(const Transitions &transitions, const utype::unordered_map<stdu::vector<std::string>, std::size_t> *dct, bool isToken) -> DfaType;
    static auto getTransitionKeyType(const NFA::TransitionKey &transition_key, bool isToken) -> DfaType;
};

// Print a single state
export std::ostream& operator<<(std::ostream& os, const DFA::MultiState& s);
// Print all states in the vector
export std::ostream& operator<<(std::ostream& os, const DFA& states);

// Outside the struct
std::ostream &operator<<(std::ostream &os, const DFA::TransitionValue &tv) {
    return os << "(" << tv.next << ", " << tv.accept_index << ")";
}
