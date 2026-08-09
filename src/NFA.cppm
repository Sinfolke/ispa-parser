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
        CST_NODE, CST_GROUP, CST_CONDITION
    };

    // Kept for NFA internal routing, but DFA will use TransitionTarget
    enum class TableType {
        DFA, LR, ACTION
    };

    enum class LRAction {
        UNDEF, BEGIN, END, PUSH, REDUCE, SHIFT, ACCEPT
    };

    // New: Explicit binding for tokens, including REDUCE hooks for unique representations
    struct TokenBinding {
        std::size_t token_id = NULL_STATE;
        std::optional<std::size_t> target_lr_state = std::nullopt;
        std::optional<std::size_t> reduce_rule_id = std::nullopt;
        bool is_unique_representation = false;

        auto operator==(const TokenBinding &other) const -> bool = default;
    private:
        friend struct ::uhash;
        auto members() const {
            return std::tie(token_id, target_lr_state, reduce_rule_id, is_unique_representation);
        }
    };

    struct TemplatedDataBlockValue : uhash {
        StoreCstNode type;
        std::size_t cst_index;
        const AST::RuleMember *AST = nullptr;
        auto operator==(const TemplatedDataBlockValue &other) const -> bool {
            return type == other.type && cst_index == other.cst_index && AST == other.AST;
        }
    private:
        friend struct ::uhash;
        auto members() const {
            return std::tie(type, cst_index, AST);
        }
    };

    // Internal NFA transition used during graph construction
    struct TransitionValue {
        std::size_t next = NULL_STATE;
        TableType table_type = TableType::LR;
        auto operator==(const TransitionValue &other) const -> bool = default;
    private:
        friend struct ::uhash;
        auto members() const {
            return std::tie(next, table_type);
        }
    };

    struct LRState {
        LRAction action = LRAction::UNDEF;
        stdu::vector<std::string> variable;
        std::size_t DFA_next_state = 0;
        std::size_t reduce_rule_index = NULL_STATE;
    private:
        friend struct ::uhash;
        auto members() const {
            return std::tie(action, variable, DFA_next_state, reduce_rule_index);
        }
    };

    using TemplatedDataBlock = utype::unordered_map<std::string, TemplatedDataBlockValue>;
    using DataBlock = std::variant<std::monostate, TemplatedDataBlock, TemplatedDataBlockValue>;
    using ActionTable = utype::unordered_map<TransitionKey, stdu::vector<LRState>>;

    struct state {
        utype::unordered_map<TransitionKey, stdu::vector<TransitionValue>> transitions;
        ActionTable action_table;
        stdu::vector<char> skip_chars;

        // Replaced raw accept_index with the new detailed binding
        std::optional<TokenBinding> accept_binding = std::nullopt;

        utype::unordered_set<TransitionValue> epsilon_transitions;
        std::size_t any = NULL_STATE;
        stdu::vector<std::string> rule_name;
        DataBlock dtb;
        bool optional = false;
        bool last = false;
        std::size_t lr_action_index = NULL_STATE;
        auto operator==(const state &other) const -> bool = default;
    private:
        friend struct ::uhash;
        auto members() const {
            return std::tie(transitions, action_table, skip_chars, accept_binding, epsilon_transitions, any, rule_name, dtb, optional, last, lr_action_index);
        }
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
    DataBlock nfadtb;
    stdu::vector<state> states;
    stdu::vector<std::size_t> add_space_skip_places;
    stdu::vector<std::pair<std::size_t, std::size_t>> group_close_propagate;
    stdu::vector<std::size_t> cst_node_close_propagate;
    bool no_add_space_skip_next = false;
    bool store_entire_group = false;
    utype::unordered_set<stdu::vector<std::string>> processing;
    utype::unordered_map<stdu::vector<std::string>, StateRange> fragment_cache;
    std::size_t *accept_index;
    std::size_t nested_count = 0;
    std::size_t group_count = 0;
    bool is_char_table = false;
    bool first = true;
    bool isWhitespaceToken = false;
    std::unordered_map<std::size_t, TokenBinding> accept_map;
    std::size_t registers_count = 0;
    stdu::vector<LRState> lr_table;

    // Build methods
    auto applyQuantifierAndActions(
        const AST::RuleMember &member,
        std::size_t start,
        std::size_t end,
        StateRange body,
        bool isLastMember,
        bool addStoreActions
    ) -> StateRange;
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
    void generateTemplatedDataBlockFromSingleRule(const AST::RuleMember &mem, TemplatedDataBlock &templated_data_block, std::size_t &prefix_index, std::size_t &index, std::size_t &group_index);
    void generateTemplatedDataBlockFromRules(const stdu::vector<AST::RuleMember> &rules, TemplatedDataBlock &templated_data_block, std::size_t &prefix_index, std::size_t &index, std::size_t &group_index);
    void generateSingleDataBlockFromRules(const stdu::vector<AST::RuleMember> &rules, TemplatedDataBlockValue &single_data_block, bool &isAlreadyConstructed);

    inline void increase_accept_index() { ++(*accept_index); }

public:
    NFA(AST::Tree &tree, const stdu::vector<std::string> &name, const AST::DataBlock *dtb, const stdu::vector<AST::RuleMember> &rules, bool isWhitespaceToken, bool is_char_table, std::size_t *accept_index_ptr) : tree(tree), name_(name), rules(&rules), dtb(dtb), isWhitespaceToken(isWhitespaceToken), is_char_table(is_char_table), accept_index(accept_index_ptr) {}
    NFA(AST::Tree &tree, const stdu::vector<std::string> &name, const AST::DataBlock *dtb, const AST::RuleMember &member, bool isWhitespaceToken, bool is_char_table, std::size_t *accept_index_ptr) : tree(tree), name_(name), member(&member), dtb(dtb), isWhitespaceToken(isWhitespaceToken), is_char_table(is_char_table), accept_index(accept_index_ptr) {}
    NFA(AST::Tree &tree, const stdu::vector<std::string> &name, const AST::Rule &rule, bool isWhitespaceToken, bool is_char_table, std::size_t *accept_index_ptr) : tree(tree), name_(name), rules(&rule.rule_members), dtb(&rule.data_block), isWhitespaceToken(isWhitespaceToken), is_char_table(is_char_table), accept_index(accept_index_ptr) {}
    void build(bool addStoreActions);

    auto& getStates() { return states; }
    auto& getStates() const { return states; }
    auto& getLRTable() { return lr_table; }
    auto& getLRTable() const { return lr_table; }
    auto &getAcceptMap() const { return accept_map; }
    auto &isCharNfa() const { return is_char_table; }
    auto &getName() const { return name_; }
    auto &getDtb() const { return nfadtb; }
};

export std::ostream& operator<<(std::ostream& os, const NFA::state& s);
export std::ostream& operator<<(std::ostream& os, const NFA& states);