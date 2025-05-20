export module LRParser;
import corelib;
import AST;
import hash;
import TreeAPI;
import std;
import std.compat;
export class LRParser {
public:
    enum class Action_type {
        SHIFT, REDUCE, ACCEPT, DFA_RESOLVE, ERR
    };
    struct Action {
        Action_type type;
        size_t state;
    };

    struct LR0Core {
        std::vector<std::string> lhs;
        TreeAPI::Rule rhs;
        size_t dot_pos;
    
        // This is important for set/hash/set comparison
        bool operator==(const LR0Core &other) const {
            return lhs == other.lhs &&
                   rhs == other.rhs &&
                   dot_pos == other.dot_pos;
        }
    private:
        friend struct uhash;
        auto members() const  {
            return std::tie(lhs, rhs, dot_pos);
        }
    };

    struct LR1Core {
        std::vector<std::string> lhs;
        TreeAPI::Rule rhs;
        size_t dot_pos;
        mutable utype::unordered_set<std::vector<std::string>> lookahead;
        virtual bool operator==(const LR1Core &other) const {
            return lhs == other.lhs &&
                   rhs == other.rhs &&
                   dot_pos == other.dot_pos &&
                   lookahead == other.lookahead;
            ;
        }
    private:
        friend struct uhash;
        auto members() const  {
            return std::tie(lhs, rhs, dot_pos, lookahead);
        }
    };
    struct Conflict {
        std::vector<LR1Core> item;
        Action* place = nullptr;
        std::vector<Action> conflicts;
        size_t state;
    };
    using InitialItemSet = utype::unordered_map<std::vector<std::string>, std::vector<TreeAPI::Rule>>;
    using ActionTable = utype::unordered_map<size_t, utype::unordered_map<std::vector<std::string>, Action>>;
    using GotoTable = utype::unordered_map<size_t, utype::unordered_map<std::vector<std::string>, size_t>>;
    using ItemSet = std::vector<TreeAPI::Rule>;
    using CanonicalItem = utype::unordered_set<LR1Core>;
    using CanonicalItemSet = std::vector<CanonicalItem>;

    using First = utype::unordered_map<std::vector<std::string>, std::set<std::vector<std::string>>>;
    using Follow = First;
    using Rules_part = std::pair<std::vector<std::string>, std::pair<size_t, std::vector<TreeAPI::RuleMember>>>;
    using Rules = std::vector<Rules_part>;
    using Priority = utype::unordered_map<std::vector<std::string>, size_t>;
    using Conflicts = std::vector<Conflict>;
protected:
    AST *tree;
    ActionTable action_table;
    GotoTable goto_table;
    utype::unordered_map<std::vector<std::string>, std::vector<std::vector<std::string>>> use_places;

    InitialItemSet initial_item_set;
    CanonicalItemSet canonical_item_set;

    First first;
    Follow follow;

    Rules rules;

    Priority priority;
    Conflicts conflicts;
    void createInitialItemSet();
    void transform_helper(std::vector<TreeAPI::RuleMember> members, const std::vector<std::string> &fullname, utype::unordered_map<std::vector<std::string>, std::pair<char, std::vector<std::string>>> &replacements);
    void transform();
    // void getPriorityTree(const std::vector<std::vector<std::string>> *rule, std::unordered_set<std::vector<std::string>> &visited, size_t depth);
    // void getPriorityTree();
    void addAugmentedRule();
    // void construct_initial_item_set(Parser::Tree &tree, InitialItemSet &initial_item_set, std::vector<std::string> &fullname);
    // auto construct_initial_item_set() -> InitialItemSet;
    void constructFirstSet(const std::vector<TreeAPI::Rule>& options, const std::vector<std::string> &nonterminal, bool &changed);
    void constructFirstSet();
    void constructFollowSet();
    void compute_cci_lookahead(const TreeAPI::Rule &rhs_group, const std::vector<std::string> &lhs_name, LR1Core &new_item);
    void create_item_collection(CanonicalItem &closure, const ItemSet &item, const std::vector<std::string> &lhs_name);
    auto construct_cannonical_collections_of_items() -> CanonicalItemSet;
    auto find_goto_state(const CanonicalItem &item_set, const std::vector<std::string> &symbol) -> size_t;
    auto find_rules_index(const LR1Core &rule) -> size_t;
    void resolveCertainConflict(const Conflict &conflict);
    void resolveConflictsStatically();
    // debug
    void formatFirstOrFollowSet(std::ostringstream &oss, First &set);
    void formatRulesTable(std::ostringstream& oss);
    void formatCanonicalItemSet(std::ostringstream &oss);
    auto formatActionTable() const -> std::string;
    auto formatGotoTable() const -> std::string;
    // build action and goto table
    void prepare();
    void buildTable();
    virtual void build();
    LRParser(AST *tree, bool build_immediately = true) : tree(tree) {
        if (build_immediately) {
            createInitialItemSet();
            transform();
            build();
        }

    }
public:
    LRParser(AST *tree) : tree(tree) {
        createInitialItemSet();
        transform();
        build();
    }
    LRParser(AST &tree) : tree(&tree) {
        createInitialItemSet();
        transform();
        build();
    }
    // get data functions
    virtual bool isELR() const;    
    static auto ActionTypeToString(const Action_type &type) -> std::string;

    auto getActionTable() const -> const ActionTable&;
    auto getGotoTable() const -> const GotoTable&;
    auto getRulesTable() const -> const Rules&; 
    auto getActionTableAsRow() const -> std::vector<utype::unordered_map<std::vector<std::string>, LRParser::Action>>;
    auto getGotoTableAsRow() const -> std::vector<utype::unordered_map<std::vector<std::string>, size_t>>;
    // helper functions
    auto getMaxStatesCount() const -> size_t;

    // debug
    // Method to print both Action and Goto tables into a single file
    void printTables(const std::string& filename);
    // print cannonical collection
    void printCanonicalCollection(const std::string &fileName);

    void printFirstSet(const std::string &fileName);
    void printFollowSet(const std::string &fileName);
};