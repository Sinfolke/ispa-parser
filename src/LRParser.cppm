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
        bool operator==(const LR0Core other) const {
            return lhs == other.lhs &&
                   rhs == other.rhs &&
                   dot_pos == other.dot_pos;
        }

    };

    struct LR1Core : public LR0Core {
        mutable std::set<std::vector<std::string>> lookahead;
    };
    struct LR0CoreHash {
        std::size_t operator()(const LRParser::LR0Core& core) const {
            std::size_t seed = 0;
            for (const auto& elem : core.lhs) {
                hash_combine(seed, std::hash<std::string>{}(elem));
            }
            hash_combine(seed, std::hash<TreeAPI::Rule>{}(core.rhs));
            hash_combine(seed, std::hash<size_t>{}(core.dot_pos));
            return seed;
        }
    };

    struct LR1CoreHash {
        std::size_t operator()(const LRParser::LR1Core& core) const noexcept {
            size_t seed = LR0CoreHash{}(core);  // reuse LR0Core hash

            std::hash<std::vector<std::string>> vec_hasher;
            for (const auto& la_set : core.lookahead) {
                seed ^= vec_hasher(la_set) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
            }

            return seed;
        }
    };
    struct Conflict {
        std::vector<LR1Core> item;
        Action* place = nullptr;
        std::vector<Action> conflicts;
        size_t state;
    };
    using InitialItemSet = std::unordered_map<std::vector<std::string>, std::vector<TreeAPI::Rule>>;
    using ActionTable = std::unordered_map<size_t, std::unordered_map<std::vector<std::string>, Action>>;
    using GotoTable = std::unordered_map<size_t, std::unordered_map<std::vector<std::string>, size_t>>;
    using ItemSet = std::vector<TreeAPI::Rule>;
    using CanonicalItem = std::unordered_set<LR1Core, LR1CoreHash>;
    using CanonicalItemSet = std::vector<CanonicalItem>;

    using First = std::unordered_map<std::vector<std::string>, std::set<std::vector<std::string>>>;
    using Follow = First;
    using Rules_part = std::pair<std::vector<std::string>, std::pair<size_t, std::vector<TreeAPI::RuleMember>>>;
    using Rules = std::vector<Rules_part>;
    using Priority = std::unordered_map<std::vector<std::string>, size_t>;
    using Conflicts = std::vector<Conflict>;

    struct CanonicalItemHash {
        std::size_t operator()(const CanonicalItem& item) const noexcept {
            std::size_t seed = item.size();
            LR1CoreHash core_hash;  // assumes this is a functor like std::hash<LR1Core>
            for (const auto& elem : item) {
                seed ^= core_hash(elem) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
            }
            return seed;
        }
    };
protected:
    AST *tree;
    ActionTable action_table;
    GotoTable goto_table;
    std::unordered_map<std::vector<std::string>, std::vector<std::vector<std::string>>> use_places;

    InitialItemSet initial_item_set;
    CanonicalItemSet canonical_item_set;

    First first;
    Follow follow;

    Rules rules;

    Priority priority;
    Conflicts conflicts;
    void createInitialItemSet();
    void transform_helper(std::vector<TreeAPI::RuleMember> members, const std::vector<std::string> &fullname, std::unordered_map<std::vector<std::string>, std::pair<char, std::vector<std::string>>> &replacements);
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
    auto getActionTableAsRow() const -> std::vector<std::unordered_map<std::vector<std::string>, LRParser::Action>>;
    auto getGotoTableAsRow() const -> std::vector<std::unordered_map<std::vector<std::string>, size_t>>;
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
namespace std {

    // Hash specialization for TreeAPI::LR0Core
    template <>
    struct hash<LRParser::LR0Core> {
        std::size_t operator()(const LRParser::LR0Core& core) const {
            std::size_t seed = 0;
            // Hash the lhs vector (std::vector<std::string>)
            for (const auto& elem : core.lhs) {
                hash_combine(seed, std::hash<std::string>{}(elem));
            }
            
            // Hash the rhs (which is a TreeAPI::Rule)
            hash_combine(seed, std::hash<TreeAPI::Rule>{}(core.rhs));
            
            // Hash the dot_pos size_t value
            hash_combine(seed, std::hash<size_t>{}(core.dot_pos));
            
            return seed;
        }
    };
    template<>
    struct hash<LRParser::LR1Core> {
        size_t operator()(const LRParser::LR1Core& core) const noexcept {
            // Start with hash of LR0Core base
            size_t seed = hash<LRParser::LR0Core>{}(core);
            
            // Hash each lookahead set
            hash<vector<string>> vec_hasher;
            for (const auto& la_set : core.lookahead) {
                seed ^= vec_hasher(la_set) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
            }
            
            return seed;
        }
    };
}