export module LRParser;
import corelib;
import AST;
import hash;
import TreeAPI;
import types;
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
        vector<std::string> lhs;
        TreeAPI::Rule rhs;
        size_t dot_pos;
    
        // This is important for set/hash/set comparison
        bool operator==(const LR0Core &other) const {
            return lhs == other.lhs &&
                   rhs == other.rhs &&
                   dot_pos == other.dot_pos;
        }
    private:
        friend struct ::uhash;
        auto members() const  {
            return std::tie(lhs, rhs, dot_pos);
        }
    };

    struct LR1Core {
        vector<std::string> lhs;
        TreeAPI::Rule rhs;
        size_t dot_pos;
        mutable utype::unordered_set<vector<std::string>> lookahead;
        virtual bool operator==(const LR1Core &other) const {
            return lhs == other.lhs &&
                   rhs == other.rhs &&
                   dot_pos == other.dot_pos &&
                   lookahead == other.lookahead;
            ;
        }
    private:
        friend struct ::uhash;
        auto members() const  {
            return std::tie(lhs, rhs, dot_pos, lookahead);
        }
    };
    struct Conflict {
        vector<LR1Core> item;
        Action* place = nullptr;
        vector<Action> conflicts;
        size_t state;
    };
    using ActionTable = utype::unordered_map<size_t, utype::unordered_map<vector<std::string>, Action>>;
    using GotoTable = utype::unordered_map<size_t, utype::unordered_map<vector<std::string>, size_t>>;
    using ItemSet = vector<TreeAPI::Rule>;
    using CanonicalItem = utype::unordered_set<LR1Core>;
    using CanonicalItemSet = vector<CanonicalItem>;

    using Rules_part = std::pair<vector<std::string>, std::pair<size_t, vector<TreeAPI::RuleMember>>>;
    using Rules = vector<Rules_part>;
    using Priority = utype::unordered_map<vector<std::string>, size_t>;
    using Conflicts = vector<Conflict>;
protected:
    AST *tree;
    ActionTable action_table;
    GotoTable goto_table;
    utype::unordered_map<vector<std::string>, vector<vector<std::string>>> use_places;

    CanonicalItemSet canonical_item_set;

    Rules rules;

    Priority priority;
    Conflicts conflicts;
    // void getPriorityTree(const vector<vector<std::string>> *rule, std::unordered_set<vector<std::string>> &visited, size_t depth);
    // void getPriorityTree();
    void addAugmentedRule();
    // void construct_initial_item_set(Parser::Tree &tree, InitialItemSet &initial_item_set, vector<std::string> &fullname);
    // auto construct_initial_item_set() -> InitialItemSet;
    void compute_cci_lookahead(const TreeAPI::Rule &rhs_group, const vector<std::string> &lhs_name, LR1Core &new_item);
    void create_item_collection(CanonicalItem &closure, const ItemSet &item, const vector<std::string> &lhs_name);
    auto construct_cannonical_collections_of_items() -> CanonicalItemSet;
    auto find_goto_state(const CanonicalItem &item_set, const vector<std::string> &symbol) -> size_t;
    auto find_rules_index(const LR1Core &rule) -> size_t;
    void resolveCertainConflict(const Conflict &conflict);
    void resolveConflictsStatically();
    // debug
    void formatFirstOrFollowSet(std::ostringstream &oss, AST::First &set);
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
            build();
        }

    }
public:
    LRParser(AST *tree) : tree(tree) {
        build();
    }
    LRParser(AST &tree) : tree(&tree) {
        build();
    }
    // get data functions
    virtual bool isELR() const;    
    static auto ActionTypeToString(const Action_type &type) -> std::string;

    auto getActionTable() const -> const ActionTable&;
    auto getGotoTable() const -> const GotoTable&;
    auto getRulesTable() const -> const Rules&; 
    auto getActionTableAsRow() const -> vector<utype::unordered_map<vector<std::string>, LRParser::Action>>;
    auto getGotoTableAsRow() const -> vector<utype::unordered_map<vector<std::string>, size_t>>;
    // helper functions
    auto getMaxStatesCount() const -> size_t;

    // debug
    // Method to print both Action and Goto tables into a single file
    void printTables(const std::string& filename);
    // print cannonical collection
    void printCanonicalCollection(const std::string &fileName);
};