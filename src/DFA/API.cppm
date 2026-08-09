export module DFA.API;

import NFA;
import AST.Tree;
import hash;
import logging;
import dstd;
import std;

export namespace DFA {
    inline constexpr auto NULL_STATE = std::numeric_limits<std::size_t>::max();
    enum class DfaType {
        Char, Token, Multi, NONE
    };
    struct TransitionValue {
        std::size_t next = NULL_STATE;
        NFA::TableType table_type = NFA::TableType::DFA;
        std::size_t accept_index = NULL_STATE;
        bool operator==(const TransitionValue &other) const = default;
    private:
        friend struct ::uhash;
        auto members() const {
            return std::tie(next, accept_index);
        }
    };

    struct TransitionKeyExt {
        NFA::TransitionKey symbol;
        NFA::TableType table_type;
        // NOTE: was `lr_action_index` + `actions` (vector<NFA::LRAction>). TransitionValue
        // no longer carries either -- it only has next/table_type/accept_index. accept_index
        // is what actually needs to participate in DFA-state refinement (two transitions to
        // the same partition with different sentinel-encoded accept_index are NOT equivalent),
        // so this field replaces lr_action_index. `actions` had no remaining data source and
        // was dropped. If per-transition LR actions come back to TransitionValue, extend this.
        std::size_t accept_index;
        std::size_t target_partition;

        bool operator<(const TransitionKeyExt &other) const {
            return std::tie(symbol, table_type, accept_index, target_partition) <
                   std::tie(other.symbol, other.table_type, other.accept_index, other.target_partition);
        }

        bool operator==(const TransitionKeyExt &other) const {
            return std::tie(symbol, table_type, accept_index, target_partition) ==
                   std::tie(other.symbol, other.table_type, other.accept_index, other.target_partition);
        }

    private:
        friend struct ::uhash;
        auto members() const {
            return std::tie(symbol, table_type, accept_index, target_partition);
        }
    };
    template<typename Transition>
    struct State {
        std::unordered_set<std::size_t> nfa_states;
        Transition transitions;
        std::optional<NFA::TokenBinding> accept_binding = std::nullopt;
        bool operator==(const State &other) const = default;
    private:
        friend struct ::uhash;
        auto members() const {
            return std::tie(nfa_states, transitions);
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

    // --- New Target Architecture Types ---
    struct LRTarget {
        std::size_t lr_state_id;
        std::size_t reduce_rule_id;
    };

    struct ActionTarget {
        std::size_t action_id;
    };

    struct DFATarget {
        std::size_t dfa_state_id;
    };

    // Unified Transition Target for pure DFA runtime
    using TransitionTarget = std::variant<DFATarget, LRTarget, ActionTarget>;

    // Mapper for output code generation
    class StateOffsetMapper {
    public:
        StateOffsetMapper(std::size_t dfa_count, std::size_t lr_count, std::size_t action_count)
            : dfa_size_(dfa_count), lr_size_(lr_count), action_size_(action_count) {}

        [[nodiscard]] std::size_t resolve(const TransitionTarget& target) const {
            return std::visit([this](auto&& arg) -> std::size_t {
                using T = std::decay_t<decltype(arg)>;
                if constexpr (std::is_same_v<T, DFATarget>) {
                    return arg.dfa_state_id;
                } else if constexpr (std::is_same_v<T, LRTarget>) {
                    return dfa_size_ + arg.lr_state_id;
                } else if constexpr (std::is_same_v<T, ActionTarget>) {
                    return dfa_size_ + lr_size_ + arg.action_id;
                }
            }, target);
        }

    private:
        std::size_t dfa_size_;
        std::size_t lr_size_;
        std::size_t action_size_;
    };
    using FullCharTable = std::array<TransitionValue, std::numeric_limits<unsigned char>::max() + 1>;

    using Transitions = utype::unordered_map<NFA::TransitionKey, std::variant<DFATarget, LRTarget, ActionTarget>>;
    using SortedTransitions = stdu::vector<std::pair<NFA::TransitionKey, TransitionValue>>;
    using SingleState = State<Transitions>;
    using CharMachineStateVariant = std::variant<FullCharTable, SortedTransitions>;
    using CharMachineState = State<CharMachineStateVariant>;
    using SortedState = State<SortedTransitions>;
    using SeenSymbol = utype::unordered_map<stdu::vector<std::size_t>, std::size_t>;
    using WalkedState = utype::unordered_map<std::size_t, std::size_t>;
    using DfaEmptyStateMap = std::unordered_map<std::size_t, std::size_t>;
    using DfaIndexToEmptyStateMap = std::unordered_map<std::size_t, std::size_t>;

    using StateSet = stdu::vector<std::size_t>;

    // One shared table: maps every possible input byte to its equivalence
    // class id. Computed once per DFA, used by every state's ClassTransitions.
    struct CharClassTable {
        std::array<std::size_t, 256> char_to_class{};
        std::size_t num_classes = 0;
    };

    // Per-state transition array, indexed by class id instead of by raw
    // char. Size == CharClassTable::num_classes, not 256.
    using ClassTransitions = std::vector<TransitionValue>;

}
