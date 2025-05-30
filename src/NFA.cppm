export module NFA;
import AST.API;
import AST.Tree;
import hash;
import dstd;
import std.compat;
export class NFA {
public:
    static constexpr auto NO_ACCEPT = std::numeric_limits<size_t>::max();
    static constexpr auto NO_STATE_RANGE = std::numeric_limits<size_t>::max();
    struct state {
        utype::unordered_map<stdu::vector<std::string>, size_t> transitions;
        size_t accept_index = NO_ACCEPT;
        bool is_starting_state = false;
        stdu::vector<size_t> epsilon_transitions;
    };
    struct StateRange {
        size_t start;
        size_t end;
        bool valid() const {
            return start != NO_STATE_RANGE && end != NO_STATE_RANGE;
        }
        bool invalid() const {
            return !valid();
        }
    };
private:
    const AST::Tree *tree;
    const stdu::vector<AST::RuleMember> *rules = nullptr;
    const AST::RuleMember *member = nullptr;
    stdu::vector<state> states;
    size_t accept_index = 0;
    size_t nested_count = 0;
    auto buildStateFragment(const AST::RuleMember &member, bool isEntry) -> StateRange;
public:
    NFA(const AST::Tree &tree, const stdu::vector<AST::RuleMember> &rules) : tree(&tree), rules(&rules) {}
    NFA(const AST::Tree &tree, const AST::RuleMember &member) : tree(&tree), member(&member) {}
    void build();
    auto getStates() const {
        return states;
    }
};
export std::ostream& operator<<(std::ostream& os, const std::vector<std::string>& vec);
// Print a single state
export std::ostream& operator<<(std::ostream& os, const NFA::state& s);

// Print all states in the vector
export std::ostream& operator<<(std::ostream& os, const NFA& states);