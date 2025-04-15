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
    using ItemSet = std::vector<std::vector<rule_other>>;
    using InitialItemSet = std::unordered_map<std::vector<std::string>, std::vector<std::vector<rule_other>>, VectorHash>;
    struct CanonicalEl {
        rule_other lhs;
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
    using First = std::unordered_map<std::vector<std::string>, std::set<std::vector<std::string>>, VectorHash>;
    using Follow = First;
private:
    Tree *tree;
    ActionTable action_table;
    GotoTable goto_table;

    InitialItemSet initial_item_set;
    CanonicalItemSet canonical_item_set;

    First first;
    Follow follow;
    size_t rule_index = 0;

    void transform_helper(Parser::Tree &tree, std::vector<Parser::Rule> &rules, std::vector<std::string> &fullname, std::unordered_map<std::vector<std::string>, std::pair<char, rule_other>, VectorHash> &replacements);
    void transform(Parser::Tree &tree, std::vector<std::string> &fullname, std::unordered_map<std::vector<std::string>, std::pair<char, rule_other>, VectorHash> &replacements);

    void addAugmentedRule();
    void get_item_set(const Parser::Rule &rule, std::vector<rule_other> &item_set);
    void construct_initial_item_set(Parser::Tree &tree, InitialItemSet &initial_item_set, std::vector<std::string> &fullname);
    auto construct_initial_item_set() -> InitialItemSet;
    auto constructFirstSet(const std::vector<std::vector<rule_other>>& options, std::set<std::vector<std::string>> &visited) -> std::set<std::vector<std::string>>;
    void constructFirstSet();
    void constructFollowSet();
    void create_item_collection(CanonicalItem &closure, const ItemSet &item, const std::vector<std::string> &lhs_name);
    auto construct_cannonical_collections_of_items() -> CanonicalItemSet;
    auto find_goto_state(const CanonicalItem &item_set, const rule_other &symbol) -> size_t;
    // debug
    void formatFirstOrFollowSet(std::ostringstream &oss, First &set);
    void formatCanonicalItemSet(std::ostringstream &oss);
    auto formatActionTable() const -> std::string;
    auto formatGotoTable() const -> std::string;
public:
    LRParser(Tree *tree) : tree(tree) {}
    LRParser(Tree &tree) : tree(&tree) {}

    // transform rules to approaritate form for LR parser
    void transform();
    // build action and goto table
    void build();
        // debug

    // Method to print both Action and Goto tables into a single file
    void printTables(const std::string& filename);
    // print cannonical collection
    void printCanonicalCollection(const std::string &fileName);

    void printFirstSet(const std::string &fileName);
    void printFollowSet(const std::string &fileName);
};
