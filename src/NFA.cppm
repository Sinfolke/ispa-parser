export module NFA;
import AST.API;
import AST.Tree;
import hash;
import dstd;
import std.compat;
export class NFA {
public:
    static constexpr auto NO_ACCEPT = std::numeric_limits<size_t>::max();
    static constexpr auto NO_ANY = std::numeric_limits<size_t>::max();
    static constexpr auto NO_STATE_RANGE = std::numeric_limits<size_t>::max();
    static constexpr auto NO_EPSILON = std::numeric_limits<size_t>::max();
    using TransitionKey = std::variant<stdu::vector<std::string>, char>;
    struct state {
        utype::unordered_map<TransitionKey, size_t> transitions;
        size_t accept_index = NO_ACCEPT;
        std::set<size_t> epsilon_transitions;
        bool is_starting_state = false;
        size_t any = NO_ANY;
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
    stdu::vector<size_t> add_space_skip_places;
    bool no_add_space_skip_next = false;
    utype::unordered_set<stdu::vector<std::string>> processing;
    utype::unordered_map<stdu::vector<std::string>, StateRange> fragment_cache;
    size_t accept_index = 0;
    size_t nested_count = 0;
    bool is_char_table = false;
    bool first = true;
    bool isWhitespaceToken = false;
    std::unordered_map<size_t, size_t> accept_map;
    void handleTerminal(const AST::RuleMember &member, const stdu::vector<std::string> &name, const size_t &start, const size_t &end, bool &isEntry);
    void handleNonTermnal(const AST::RuleMember &member, const stdu::vector<std::string> &name, const size_t &start, const size_t &end, bool isEntry);
    void handleGroup(const AST::RuleMember &member, const stdu::vector<AST::RuleMember> &group, const size_t &start, const size_t &end, bool isEntry);
    void handleString(const AST::RuleMember &member, const std::string &str, const size_t &start, const size_t &end, bool isEntry);
    void handleCsequence(const AST::RuleMember &member, const AST::RuleMemberCsequence &csequence, const size_t &start, const size_t &end, bool isEntry);
    auto buildStateFragment(const AST::RuleMember &member, bool isEntry) -> StateRange;
    auto investigateHasNext(size_t place, char c, std::unordered_set<size_t> &visited) -> bool;
    auto investigateHasNext(size_t place, const stdu::vector<std::string> &name, std::unordered_set<size_t> &visited) -> bool;
    void addSpaceSkip();
    void AccessMapVisitState(size_t index, size_t accept_index, std::unordered_set<size_t>& visited);
    void buildAcceptMap();
public:
    NFA(const AST::Tree &tree, const stdu::vector<AST::RuleMember> &rules, bool isWhitespaceToken) : tree(&tree), rules(&rules), isWhitespaceToken(isWhitespaceToken) {}
    NFA(const AST::Tree &tree, const AST::RuleMember &member, bool isWhitespaceToken) : tree(&tree), member(&member), isWhitespaceToken(isWhitespaceToken) {}
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