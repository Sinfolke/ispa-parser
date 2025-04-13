#include <parser.h>
#include <internal_types.h>
#include <corelib.h>
#include <token_management.h>
#include <fstream>
#include <iostream>
#include <tree.h>
class LRParser {
public:
    enum class Action_type {
        SHIFT, REDUCE, ACCEPT, ERROR 
    };

    struct Action {
        Action_type type;
        size_t state;
    };

    using ActionTable = std::unordered_map<size_t, std::unordered_map<std::string, Action>>;
    using GotoTable = std::unordered_map<size_t, std::unordered_map<std::string, size_t>>;
    using ItemSet = std::pair<std::vector<std::string>, std::vector<std::vector<rule_other>>>;
    using InitialItemSet = std::vector<ItemSet>;
    struct CanonicalEl {
        std::vector<std::string> lhs;
        std::vector<rule_other> rhs;
        size_t dot_pos;
        size_t rule_index;
    
        // This is important for set/hash/set comparison
        bool operator==(const CanonicalEl other) const {
            return lhs == other.lhs &&
                   rhs == other.rhs &&
                   dot_pos == other.dot_pos;
        }
    
        bool operator<(const CanonicalEl &other) const {
            return std::tie(lhs, rhs, dot_pos) < std::tie(other.lhs, other.rhs, other.dot_pos);
        }
    };
    using CanonicalItem = std::vector<CanonicalEl>;
    using CanonicalItemSet = std::vector<CanonicalItem>;
    using First = std::unordered_map<std::string, std::vector<std::vector<std::string>>>;
    using Follow = std::unordered_map<std::string, std::vector<std::string>>;
private:
    Tree *tree;
    ActionTable action_table;
    GotoTable goto_table;

    InitialItemSet initial_item_set;
    CanonicalItemSet canonical_item_set;

    First first;
    Follow follow;
    size_t rule_index = 0;
    void addAugmentedRule();
    void get_item_set(const Parser::Rule &rule, std::vector<rule_other> &item_set);
    void construct_initial_item_set(Parser::Tree &tree, InitialItemSet &initial_item_set, std::vector<std::string> &fullname);
    auto construct_initial_item_set() -> InitialItemSet;
    std::vector<std::vector<std::string>> constructFirstSet(const std::vector<Parser::Rule>& rules, size_t pos = 0);
    void constructFirstSet(Parser::Tree &tree, std::vector<std::string> &fullname);
    void constructFirstSet();
    void constructFollowSet(std::vector<std::string> &name, const std::vector<Parser::Rule>& rules);
    void constructFollowSet(Parser::Tree &tree, std::vector<std::string> &fullname, std::vector<std::string> &nonterminals);
    void constructFollowSet(std::vector<std::string> &nonterminals);
    void create_item_collection(CanonicalItem &closure, const ItemSet &item);
    auto construct_cannonical_collections_of_items() -> CanonicalItemSet;
    size_t find_goto_state(const CanonicalItem &item_set, const rule_other &symbol);
    // debug
    void formatCanonicalItemSet(std::ostringstream &oss);
    auto formatActionTable() const -> std::string;
    auto formatGotoTable() const -> std::string;
public:
    LRParser(Tree *tree) : tree(tree) {}
    LRParser(Tree &tree) : tree(&tree) {}

    auto begin() -> Parser::Tree::iterator;
    auto end() -> Parser::Tree::iterator;
    void build();
        // debug

    // Method to print both Action and Goto tables into a single file
    void printTables(const std::string& filename);
    // print cannonical collection
    void printCanonicalCollection(const std::string &fileName);
};
