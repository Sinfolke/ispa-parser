#pragma once
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
    
    using ActionTable = std::unordered_map<size_t, std::unordered_map<std::vector<std::string>, Action, VectorHash>>;
    using GotoTable = std::unordered_map<size_t, std::unordered_map<std::vector<std::string>, size_t, VectorHash>>;
    using ItemSet = std::vector<std::vector<rule_other>>;
    using InitialItemSet = std::unordered_map<std::vector<std::string>, std::vector<std::vector<rule_other>>, VectorHash>;
    struct CanonicalEl {
        rule_other lhs;
        std::vector<rule_other> rhs;
        size_t dot_pos;
        size_t rule_index;
        std::set<std::vector<std::string>> lookahead;
    
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
    using Rules_part = std::pair<std::vector<std::string>, std::pair<size_t, std::vector<rule_other>>>;
    using Rules = std::vector<Rules_part>;
private:
    Tree *tree;
    ActionTable action_table;
    GotoTable goto_table;
    Tree::use_place_t use_places;

    InitialItemSet initial_item_set;
    CanonicalItemSet canonical_item_set;

    First first;
    Follow follow;

    Rules rules;
    size_t rule_index = 0;
    void getTerminalNames(Parser::Tree &tree, std::vector<std::vector<std::string>> &names, std::vector<std::string> &fullname) const;
    void getNonTerminalNames(Parser::Tree &tree, std::vector<std::vector<std::string>> &names, std::vector<std::string> &fullname) const;
    void transform_helper(Parser::Tree &tree, std::vector<Parser::Rule> &rules, std::vector<std::string> &fullname, std::unordered_map<std::vector<std::string>, std::pair<char, rule_other>, VectorHash> &replacements);
    void transform(Parser::Tree &tree, std::vector<std::string> &fullname, std::unordered_map<std::vector<std::string>, std::pair<char, rule_other>, VectorHash> &replacements);

    void addAugmentedRule();
    void get_item_set(const Parser::Rule &rule, std::vector<rule_other> &item_set);
    void construct_initial_item_set(Parser::Tree &tree, InitialItemSet &initial_item_set, std::vector<std::string> &fullname);
    auto construct_initial_item_set() -> InitialItemSet;
    void constructFirstSet(const std::vector<std::vector<rule_other>>& options, const std::vector<std::string> &nonterminal, bool &changed);
    void constructFirstSet();
    void constructFollowSet();
    void compute_cci_lookahead(const std::vector<rule_other> &rhs_group, const std::vector<std::string> &lhs_name, CanonicalEl &new_item);
    void create_item_collection(CanonicalItem &closure, const ItemSet &item, const std::vector<std::string> &lhs_name);
    auto construct_cannonical_collections_of_items() -> CanonicalItemSet;
    auto find_goto_state(const CanonicalItem &item_set, const rule_other &symbol) -> size_t;
    auto find_rules_index(const CanonicalEl &rule) -> size_t;
    // debug
    void debug(Parser::Tree &tree, std::vector<std::string> &fullname);
    void formatFirstOrFollowSet(std::ostringstream &oss, First &set);
    void formatRulesTable(std::ostringstream& oss);
    void formatCanonicalItemSet(std::ostringstream &oss);
    auto formatActionTable() const -> std::string;
    auto formatGotoTable() const -> std::string;
public:
    LRParser(Tree *tree) : tree(tree) {}
    LRParser(Tree &tree) : tree(&tree) {}
    // get data functions

    auto getActionTable() const -> const ActionTable&;
    auto getGotoTable() const -> const GotoTable&;
    auto getRulesTable() const -> const Rules&; 
    static auto ActionTypeToString(const Action_type &type) -> std::string;
    auto getActionTableAsRow() const -> std::vector<std::unordered_map<std::vector<std::string>, LRParser::Action, VectorHash>>;
    auto getGotoTableAsRow() const -> std::vector<std::unordered_map<std::vector<std::string>, size_t, VectorHash>>;
    // helper functions
    auto getMaxStatesCount() const -> size_t;
    auto getTerminalNames() const -> std::vector<std::vector<std::string>>;
    auto getNonTerminalNames() const ->  std::vector<std::vector<std::string>>;
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
