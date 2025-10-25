export module DFA.API;

import NFA;
import AST.Tree;
import hash;
import boost;
import logging;
import dstd;
import std;

export namespace DFA {
    inline constexpr auto NULL_STATE = std::numeric_limits<std::size_t>::max();
    enum class DfaType {
        Char, Token, Multi, NONE
    };
    struct TransitionValue {
        std::size_t next;
        bool new_cst_node = false;
        bool new_member = false;
        bool close_cst_node = false;
        std::size_t new_group = NULL_STATE;
        std::size_t group_close = NULL_STATE;
        std::size_t accept_index = NULL_STATE;
        bool consume = true;
        bool optional = false;
        bool last = false;
        bool operator==(const TransitionValue &other) const = default;
    private:
        friend struct ::uhash;
        auto members() const {
            return std::tie(next, new_cst_node, new_member, close_cst_node, new_group, group_close, accept_index);
        }
    };
    struct MultiTransitionValue {
        TransitionValue value;
        std::size_t dfa_merge_conflict = NULL_STATE;
        bool operator==(const MultiTransitionValue &second) const = default;
    private:
        friend struct ::uhash;
        auto members() const {
            return std::tie(value, dfa_merge_conflict);
        }
    };
    template<typename Transition>
    struct State {
        std::unordered_set<std::size_t> nfa_states; // the NFA states this DFA state represents
        Transition transitions;
        std::size_t else_goto = 0;
        std::size_t else_goto_accept = NULL_STATE;
        stdu::vector<std::string> rule_name;
        NFA::DataBlock dtb;
        bool operator==(const State &other) const = default;
    private:
        friend struct ::uhash;
        auto members() const {
            return std::tie(nfa_states, transitions, else_goto, else_goto_accept, rule_name, dtb);
        }
    };

    class Comparator {
        const AST::Tree &tree;
        auto compareNameWithCharacter(const stdu::vector<std::string> &name, const char c) const -> bool;
        auto compareNameWithName(const stdu::vector<std::string> &first_name, const stdu::vector<std::string> &second_name) const -> bool;
    public:
        Comparator(const AST::Tree &tree) : tree(tree) {}

        auto operator()(const NFA::TransitionKey &a, const NFA::TransitionKey &b) const -> bool;
        auto operator()(const std::pair<NFA::TransitionKey, TransitionValue> &a, const std::pair<NFA::TransitionKey, TransitionValue> &b) const -> bool;
    };
    using FullCharTable = std::array<TransitionValue, std::numeric_limits<unsigned char>::max() + 1>;

    using Transitions = utype::unordered_map<NFA::TransitionKey, TransitionValue>;
    using MultiTransitions = utype::unordered_map<NFA::TransitionKey, stdu::vector<MultiTransitionValue>>;
    using SortedTransitions = stdu::vector<std::pair<NFA::TransitionKey, TransitionValue>>;
    using MultiState = State<MultiTransitions>;
    using SingleState = State<Transitions>;
    using CharMachineStateVariant = std::variant<FullCharTable, SortedTransitions>;
    using CharMachineState = State<CharMachineStateVariant>;
    using SortedState = State<SortedTransitions>;
    using SeenSymbol = utype::unordered_map<NFA::TransitionKey, utype::unordered_set<std::unordered_set<std::size_t>>>;
    using WalkedState = utype::unordered_map<std::size_t, std::size_t>;
    using DfaEmptyStateMap = std::unordered_map<std::size_t, std::size_t>;
    using DfaIndexToEmptyStateMap = std::unordered_map<std::size_t, std::size_t>;

    using StateSet = stdu::vector<std::size_t>;
}
