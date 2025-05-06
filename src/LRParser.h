#pragma once
#include <Parser.h>
#include <corelib.h>
#include <fstream>
#include <iostream>
#include <tree.h>
class LRParser {
public:
    enum class Action_type {
        SHIFT, REDUCE, ACCEPT, DFA_RESOLVE, ERROR 
    };
    struct Action {
        Action_type type;
        size_t state;
    };

    struct LR0Core {
        rule_other lhs;
        std::vector<rule_other> rhs;
        size_t dot_pos;
    
        // This is important for set/hash/set comparison
        bool operator==(const LR0Core other) const {
            return lhs == other.lhs &&
                   rhs == other.rhs &&
                   dot_pos == other.dot_pos;
        }
    
        bool operator<(const LR0Core &other) const {
            return std::tie(lhs, rhs, dot_pos) < std::tie(other.lhs, other.rhs, other.dot_pos);
        }
    };
    struct LR1Core : public LR0Core {
        mutable std::set<std::vector<std::string>> lookahead;
    };
    struct Conflict {
        std::vector<LR1Core> item;
        Action* place = nullptr;
        std::vector<Action> conflicts;
        size_t state;
    };
        
    using ActionTable = std::unordered_map<size_t, std::unordered_map<std::vector<std::string>, Action>>;
    using GotoTable = std::unordered_map<size_t, std::unordered_map<std::vector<std::string>, size_t>>;
    using ItemSet = std::vector<std::vector<rule_other>>;
    using InitialItemSet = std::unordered_map<std::vector<std::string>, std::vector<std::vector<rule_other>>>;
    using CanonicalItem = std::set<LR1Core>;
    using CanonicalItemSet = std::vector<CanonicalItem>;

    using First = std::unordered_map<std::vector<std::string>, std::set<std::vector<std::string>>>;
    using Follow = First;
    using Rules_part = std::pair<std::vector<std::string>, std::pair<size_t, std::vector<rule_other>>>;
    using Rules = std::vector<Rules_part>;
    using Priority = std::unordered_map<std::vector<std::string>, size_t>;
    using Conflicts = std::vector<Conflict>;
protected:
    Tree *tree;
    ActionTable action_table;
    GotoTable goto_table;
    Tree::UsePlaceTable use_places;

    InitialItemSet initial_item_set;
    CanonicalItemSet canonical_item_set;

    First first;
    Follow follow;

    Rules rules;

    Priority priority;
    Conflicts conflicts;
    void transform_helper(Parser::Tree &tree, std::vector<Parser::Rule> &rules, std::vector<std::string> &fullname, std::unordered_map<std::vector<std::string>, std::pair<char, rule_other>> &replacements);
    void transform(Parser::Tree &tree, std::vector<std::string> &fullname, std::unordered_map<std::vector<std::string>, std::pair<char, rule_other>> &replacements);
    void getPriorityTree(const std::vector<rule_other> *rule, std::unordered_set<std::vector<std::string>> &visited, size_t depth);
    void getPriorityTree();
    void addAugmentedRule();
    void construct_initial_item_set(Parser::Tree &tree, InitialItemSet &initial_item_set, std::vector<std::string> &fullname);
    auto construct_initial_item_set() -> InitialItemSet;
    void constructFirstSet(const std::vector<std::vector<rule_other>>& options, const std::vector<std::string> &nonterminal, bool &changed);
    void constructFirstSet();
    void constructFollowSet();
    void compute_cci_lookahead(const std::vector<rule_other> &rhs_group, const std::vector<std::string> &lhs_name, LR1Core &new_item);
    void create_item_collection(CanonicalItem &closure, const ItemSet &item, const std::vector<std::string> &lhs_name);
    auto construct_cannonical_collections_of_items() -> CanonicalItemSet;
    auto find_goto_state(const CanonicalItem &item_set, const rule_other &symbol) -> size_t;
    auto find_rules_index(const LR1Core &rule) -> size_t;
    void resolveCertainConflict(const Conflict &conflict);
    void resolveConflictsStatically();
    // debug
    void debug(Parser::Tree &tree, std::vector<std::string> &fullname);
    void formatFirstOrFollowSet(std::ostringstream &oss, First &set);
    void formatRulesTable(std::ostringstream& oss);
    void formatCanonicalItemSet(std::ostringstream &oss);
    auto formatActionTable() const -> std::string;
    auto formatGotoTable() const -> std::string;
    // transform rules to approaritate form for LR parser
    void transform();
    // build action and goto table
    void prepare();
    void buildTable();
    virtual void build();
    LRParser(Tree *tree, bool build_immediately = true) : tree(tree) {
        if (build_immediately) {
            transform();
            build();
        }

    }
public:
    LRParser(Tree *tree) : tree(tree) {
        transform();
        build();
    }
    LRParser(Tree &tree) : tree(&tree) {
        transform();
        build();
    }
    // get data functions
    virtual bool isELR() const;
    auto getActionTable() const -> const ActionTable&;
    auto getGotoTable() const -> const GotoTable&;
    auto getRulesTable() const -> const Rules&; 
    static auto ActionTypeToString(const Action_type &type) -> std::string;
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
    template<>
    struct hash<LRParser::LR0Core> {
        size_t operator()(const LRParser::LR0Core& core) const noexcept {
            size_t seed = 0;
            
            // Hash lhs
            hash<rule_other> hasher;
            seed ^= hasher(core.lhs) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
            
            // Hash rhs vector
            for (const auto& rule : core.rhs) {
                seed ^= hasher(rule) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
            }
            
            // Hash dot position
            seed ^= hash<size_t>{}(core.dot_pos) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
            
            return seed;
        }
    };
}
namespace std {
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