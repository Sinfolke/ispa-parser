export module NFA;
import AST.API;
import AST.Tree;
import LangAPI;
import hash;
import dstd;

export class NFA {
public:
    static constexpr auto NULL_STATE = std::numeric_limits<std::size_t>::max();
    using TransitionKey = std::variant<stdu::vector<std::string>, char>;

    enum class StoreCstNode {
        CST_NODE, CST_GROUP, CST_CONDITION
    };
    enum class TableType {
        DFA, Action, Semantic
    };
    enum class Action {
        UNDEF, BEGIN, END, PUSH
    };
    enum class SemanticAction {
        UNDEF, REDUCE
    };

    struct TokenBinding {
        std::size_t token_id = NULL_STATE;
        std::optional<std::size_t> target_semantic_state = std::nullopt;
        std::optional<std::size_t> reduce_rule_id = std::nullopt;
        bool is_unique_representation = false;

        auto operator==(const TokenBinding &other) const -> bool = default;
    private:
        friend struct ::uhash;
        auto members() const {
            return std::tie(token_id, target_semantic_state, reduce_rule_id, is_unique_representation);
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
        TableType table_type = TableType::Action;
        auto operator==(const TransitionValue &other) const -> bool = default;
    private:
        friend struct ::uhash;
        auto members() const {
            return std::tie(next, table_type);
        }
    };

    // Flat entry of the Action table (table 2). `variable` names the capture register
    // this BEGIN/END/PUSH operates on. `DFA_next_state` is left unresolved (NULL_STATE)
    // here - it's filled in later by the DFA layer once subset construction has assigned
    // final state numbers.
    struct ActionState {
        Action action = Action::UNDEF;
        LangAPI::Variable variable{};
        std::size_t DFA_next_state = NULL_STATE;
        auto operator==(const ActionState &other) const -> bool = default;
    private:
        friend struct ::uhash;
        auto members() const {
            return std::tie(action, variable, DFA_next_state);
        }
    };
    using TemplatedDataBlock = utype::unordered_map<std::string, TemplatedDataBlockValue>;
    using DataBlock = std::variant<std::monostate, TemplatedDataBlock, TemplatedDataBlockValue>;
    using ActionTable = stdu::vector<ActionState>;
    using SemanticTable = stdu::vector<LangAPI::Statements>;

    struct state {
        utype::unordered_map<TransitionKey, stdu::vector<TransitionValue>> transitions;
        stdu::vector<char> skip_chars;

        // Replaced raw accept_index with the new detailed binding
        std::optional<TokenBinding> accept_binding = std::nullopt;

        utype::unordered_set<TransitionValue> epsilon_transitions;
        std::size_t any = NULL_STATE;
        stdu::vector<std::string> rule_name;
        DataBlock dtb;
        bool optional = false;
        bool last = false;
        // Set on synthetic BEGIN/END/PUSH states; indexes into NFA::getActionTable().
        std::size_t action_index = NULL_STATE;
        auto operator==(const state &other) const -> bool = default;
    private:
        friend struct ::uhash;
        auto members() const {
            return std::tie(transitions, skip_chars, accept_binding, epsilon_transitions, any, rule_name, dtb, optional, last, action_index);
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
    ActionTable action_table;
    SemanticTable semantic_table;

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
    // Marks `state_id` as an accept state for `member`, and, if the token isn't a
    // unique/literal representation, pushes a REDUCE entry into the Semantic table.
    void markAccept(std::size_t state_id, const AST::RuleMember &member);
    void acceptMapVisitState(std::size_t index, std::optional<TokenBinding> current_binding, std::unordered_set<std::size_t>& visited);
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
    void build(bool addStoreActions = true);
    void buildAcceptMap();
    auto getRegistersCount() { return registers_count; }
    auto& getStates() { return states; }
    auto& getStates() const { return states; }
    auto& getActionTable() { return action_table; }
    auto& getActionTable() const { return action_table; }
    auto& getSemanticTable() { return semantic_table; }
    auto& getSemanticTable() const { return semantic_table; }
    auto &getAcceptMap() const { return accept_map; }
    auto &isCharNfa() const { return is_char_table; }
    auto &getName() const { return name_; }
    auto &getDtb() const { return nfadtb; }
};

export std::ostream& operator<<(std::ostream& os, const NFA::state& s);
export std::ostream& operator<<(std::ostream& os, const NFA& states);