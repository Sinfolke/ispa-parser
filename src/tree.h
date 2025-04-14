#pragma once
#include <corelib.h>
#include <parser.h>
#include <internal_types.h>
#include <list>
#include <IR/IR.h>
class Tree {
    public:
        struct Conflict {
            std::vector<Parser::Rule>* lhs_rule;
            std::vector<Parser::Rule>* rhs_rule;
            std::vector<Parser::Rule>::iterator lhs_it;
            std::vector<Parser::Rule>::iterator rhs_it;
        };
        using ConflictsList = std::vector<Conflict>;
    private:
        Parser::Tree tree;
        size_t token_count = 0;
        // treeNormalizer
        void normalizeHelper(std::vector<Parser::Rule> &rules, std::vector<std::string> fullname, std::vector<std::pair<std::string, std::vector<std::string>>> &nested_rule_names);
        void getNestedNames(std::vector<Parser::Rule> &nested_rules, std::vector<std::pair<std::string, std::vector<std::string>>> &nested_rule_names, std::vector<std::string> &fullname);
        void normalizeRule(Parser::Rule &member, std::vector<std::string> &fullname, std::vector<std::pair<std::string, std::vector<std::string>>> &nested_rule_names);
        void normalizeTreeHelper(Parser::Tree &tree, std::vector<std::string> &fullname, std::vector<std::pair<std::string, std::vector<std::string>>> &nested_rule_names);
        // replace dublications functions
        void getReplacedTree(std::vector<Parser::Rule>& rules, std::string name);
        void replaceDublicationsHelper(Parser::Tree &tree);
        void removeEmptyRule(Parser::Tree &tree);
        // inline tokens functions
        void accumulateInlineNamesAndRemove(Parser::Tree& tree, std::vector<std::vector<std::string>>& table_key, std::vector<Parser::Rule>& table_value, std::vector<std::string> nested);
        Parser::Rule find_key_in_table_by_name(const std::vector<std::vector<std::string>>& table_key,  const std::vector<Parser::Rule>& table_value, const std::vector<std::string>& name);
        void inlineTokensInTable(std::vector<std::vector<std::string>> &table_key, std::vector<Parser::Rule> &table_value);
        void inline_Rule_rule(std::vector<Parser::Rule> &rules, const std::vector<std::vector<std::string>> &table_key, const std::vector<Parser::Rule> &table_value, std::vector<std::string> nested);
        void inlineTokensHelper(Parser::Tree &tree, const std::vector<std::vector<std::string>> &table_key, const std::vector<Parser::Rule> &table_value, std::vector<std::string> nested);
        void inlineTokensHelper(Parser::Tree &tree);
        // literals to tokens functions
        std::pair<Parser::Rule, Parser::Rule> getNewRuleAndToken(const Parser::Rule &val, const Parser::Rule &qualifier);
        bool checkRuleEscaped(const Parser::Rule &rule);
        void getTokensFromRule_rule(Parser::Tree &tree, std::vector<Parser::Rule>& rule, bool is_not_rule_rule = false);
        Parser::Tree getTokensFromRule(Parser::Rule &member);
        void literalsToTokenHelper(Parser::Tree& tree, Parser::Tree &treeInsert);
        // sort by priority functions
        bool processGroup_helper(Parser::Tree &tree, const std::vector<Parser::Rule>& group, const Parser::Rule &second);
        bool sortPriority(Parser::Rule first, Parser::Rule second);
        void sortByPriorityHelper(std::vector<Parser::Rule> &rules);
        void sortByPriority(Parser::Tree &tree);

        // other functions
        std::pair<std::vector<std::string>, std::vector<std::string>> getTokenAndRuleNamesHelper(const Parser::Tree &tree, std::string nested_name);
        use_prop_t get_use_data(const Parser::Rule &use);
        void accamulateUsePlaces(std::vector<Parser::Rule>& rules, use_place_t &use_places, std::vector<std::string> &fullname);
        std::vector<Parser::Rule>* getRuleOtherRules(const Parser::Rule &rule);
        void getUsePlacesTableHelper(Parser::Tree &tree, use_place_t &use_places, std::vector<std::string> &fullname);
        void getConflictsTableForRule(const std::vector<Parser::Rule> &rules, ConflictsList &table);
        void resolveConflictsHelper(const std::vector<Parser::Rule> &rules);
        void resolveConflicts(Parser::Tree &tree);
    public:
        Tree(Parser::Tree &&tree) : tree(std::move(tree)) {}
        Tree(Parser::Tree &tree) : tree(tree) {}
        auto getRawTree() -> Parser::Tree&;

        auto begin() -> Parser::Tree::iterator;
        auto end() -> Parser::Tree::iterator;
        void removeEmptyRule();
        void normalize();
        void replaceDublications();
        void inlineTokens();
        void literalsToToken();
        void sortByPriority();
        void addSpaceToken();
        auto getTokenAndRuleNames() -> std::pair<std::vector<std::string>, std::vector<std::string>>;
        auto accamulate_use_data_to_map() -> use_prop_t;
        auto getUsePlacesTable() -> use_place_t;
        auto get_data_blocks(const LLIR &ir) -> std::pair<data_block_t, data_block_t>;
        auto getCodeForLexer(use_place_t use_places, const LLIR &ir) -> lexer_code;
        void resolveConflicts();
};
