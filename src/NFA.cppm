export module NFA;
import AST.API;
import AST.Tree;
import hash;
import dstd;

export class NFA {
public:
    static constexpr auto NULL_STATE = std::numeric_limits<std::size_t>::max();
    using TransitionKey = std::variant<stdu::vector<std::string>, char>;
    enum class StoreCstNode {
        CST_NODE, CST_GROUP
    };
    using TemplatedDataBlock = stdu::vector< // vector of key -> value
        std::pair< // key -> value
            std::string, // key name,
            std::pair<
                StoreCstNode, //what to store,
                std::size_t //cst member index | group index
            >
        >
    >;
    using SingleValueDataBlock = StoreCstNode; // cst node index | group index
    using DataBlock = std::variant<std::monostate, TemplatedDataBlock, SingleValueDataBlock>;
    struct TransitionValue {
        std::size_t next;
        bool new_cst_node = false;
        bool new_member = false;
        bool close_cst_node = false;
        std::size_t new_group = NULL_STATE;
        std::size_t group_close = NULL_STATE;
    };
    struct state {
        utype::unordered_map<TransitionKey, TransitionValue> transitions;
        stdu::vector<char> skip_chars;
        std::size_t accept_index = NULL_STATE;
        std::unordered_set<std::size_t> epsilon_transitions;
        std::size_t any = NULL_STATE;
        stdu::vector<std::string> rule_name;
        DataBlock dtb;
        bool optional = false;
        bool last = false;
    };
    struct StateRange {
        std::size_t start;
        std::size_t end;
        bool valid() const {
            return start != NULL_STATE && end != NULL_STATE;
        }
        bool invalid() const {
            return !valid();
        }
    };
private:
    AST::Tree &tree;
    const stdu::vector<AST::RuleMember> *rules = nullptr;
    const AST::RuleMember *member = nullptr;
    const AST::DataBlock *dtb;
    const stdu::vector<std::string> &name_;
    stdu::vector<state> states;
    stdu::vector<std::size_t> add_space_skip_places;
    stdu::vector<std::pair<std::size_t, std::size_t>> group_close_propagate;
    stdu::vector<std::size_t> cst_node_close_propagate;
    bool no_add_space_skip_next = false;
    bool store_entire_group = false;
    utype::unordered_set<stdu::vector<std::string>> processing;
    utype::unordered_map<stdu::vector<std::string>, StateRange> fragment_cache;
    std::size_t accept_index = 0;
    std::size_t nested_count = 0;
    std::size_t group_count = 0;
    bool is_char_table = false;
    bool first = true;
    bool isWhitespaceToken = false;
    std::unordered_map<std::size_t, std::size_t> accept_map;

    // data to build data block
    void handleTerminal(const AST::RuleMember &member, const stdu::vector<std::string> &name, const std::size_t &start, const std::size_t &end, bool &isLastMember, bool addStoreActions);
    void handleNonTermnal(const AST::RuleMember &member, const stdu::vector<std::string> &name, const std::size_t &start, const std::size_t &end, bool isLastMember, bool addStoreActions);
    void handleGroup(const AST::RuleMember &member, const stdu::vector<AST::RuleMember> &group, const std::size_t &start, const std::size_t &end, bool isLastMember, bool addStoreActions);
    void handleString(const AST::RuleMember &member, const std::string &str, const std::size_t &start, const std::size_t &end, bool isLastMember, bool addStoreActions);
    void handleCsequence(const AST::RuleMember &member, const AST::RuleMemberCsequence &csequence, const std::size_t &start, const std::size_t &end, bool isLastMember, bool addStoreActions);
    auto buildStateFragment(const AST::RuleMember &member, bool isLastMember, bool addStoreActions) -> StateRange;
    auto investigateHasNext(std::size_t place, char c, std::unordered_set<std::size_t> &visited) -> bool;
    auto investigateHasNext(std::size_t place, const stdu::vector<std::string> &name, std::unordered_set<std::size_t> &visited) -> bool;
    void addSpaceSkip();
    void acceptMapVisitState(std::size_t index, std::size_t accept_index, std::unordered_set<std::size_t>& visited);
    void buildAcceptMap();
    void getStatesToPropagate(std::size_t state_id, std::unordered_set<std::size_t> &result);
    auto getStatesToPropagate(std::size_t id) -> std::unordered_set<std::size_t>;
    void generateTemplatedDataBlockFromRules(
        const stdu::vector<AST::RuleMember> &rules,
        TemplatedDataBlock &templated_data_block,
        std::size_t &prefix_index,
        std::size_t &index,
        std::size_t &group_index
        );
    void generateSingleDataBlockFromRules(const stdu::vector<AST::RuleMember> &rules, SingleValueDataBlock &single_data_block, bool &isAlreadyConstructed);
public:
    NFA(AST::Tree &tree, const stdu::vector<std::string> &name, const AST::DataBlock *dtb, const stdu::vector<AST::RuleMember> &rules, bool isWhitespaceToken, bool is_char_table) : tree(tree), name_(name), rules(&rules), dtb(dtb), isWhitespaceToken(isWhitespaceToken), is_char_table(is_char_table) {}
    NFA(AST::Tree &tree, const stdu::vector<std::string> &name, const AST::DataBlock *dtb, const AST::RuleMember &member, bool isWhitespaceToken, bool is_char_table) : tree(tree), name_(name), member(&member), dtb(dtb), isWhitespaceToken(isWhitespaceToken), is_char_table(is_char_table) {}
    NFA(AST::Tree &tree, const stdu::vector<std::string> &name, const AST::Rule &rule, bool isWhitespaceToken, bool is_char_table) : tree(tree), name_(name), rules(&rule.rule_members), dtb(&rule.data_block), isWhitespaceToken(isWhitespaceToken), is_char_table(is_char_table) {}
    void build(bool addStoreActions);
    auto& getStates() const {
        return states;
    }
    auto &getAcceptMap() const {
        return accept_map;
    }
    auto &isCharNfa() const {
        return is_char_table;
    }
    auto &name() const {
        return name_;
    }
};
// Print a single state
export std::ostream& operator<<(std::ostream& os, const NFA::state& s);

// Print all states in the vector
export std::ostream& operator<<(std::ostream& os, const NFA& states);