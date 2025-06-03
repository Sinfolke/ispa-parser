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
        std::set<size_t> epsilon_transitions;
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
    utype::unordered_set<stdu::vector<std::string>> processing;
    size_t accept_index = 0;
    size_t nested_count = 0;
    std::unordered_map<size_t, size_t> accept_map;
    void handleTerminal(const AST::RuleMember &member, const stdu::vector<std::string> &name, const size_t &start, const size_t &end, bool &isEntry);
    void handleNonTermnal(const AST::RuleMember &member, const stdu::vector<std::string> &name, const size_t &start, const size_t &end, bool isEntry);
    void handleGroup(const AST::RuleMember &member, const stdu::vector<AST::RuleMember> &group, const size_t &start, const size_t &end, bool isEntry);
    auto buildStateFragment(const AST::RuleMember &member, bool isEntry) -> StateRange;
    void removeDeadStates();
    void AccessMapVisitState(size_t index, size_t accept_index, std::unordered_set<size_t>& visited);
    void buildAcceptMap();
public:
    NFA(const AST::Tree &tree, const stdu::vector<AST::RuleMember> &rules) : tree(&tree), rules(&rules) {}
    NFA(const AST::Tree &tree, const AST::RuleMember &member) : tree(&tree), member(&member) {}
    void build();
    auto& getStates() const {
        return states;
    }
    auto &getAcceptMap() const {
        return accept_map;
    }
};
export std::ostream& operator<<(std::ostream& os, const std::vector<std::string>& vec);
// Print a single state
export std::ostream& operator<<(std::ostream& os, const NFA::state& s);

// Print all states in the vector
export std::ostream& operator<<(std::ostream& os, const NFA& states);