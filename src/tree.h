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
        struct Use_place {
            size_t index;
            std::vector<std::string> name; 
        };
        using ConflictsList = std::vector<Conflict>;
        using use_place_t_part = std::pair<std::vector<std::string>, std::vector<Use_place>>;
        using use_place_table = std::unordered_map<std::vector<std::string>, std::vector<Use_place>>;
    private:
        Parser::Tree tree;
        size_t token_count = 0;
        // production management
        bool compare_string_rule(const Parser::Rule &first, const Parser::Rule &second);
        bool compare_hex_rule(const Parser::Rule &first, const Parser::Rule &second);
        bool compare_bin_rule(const Parser::Rule &first, const Parser::Rule &second);
        bool compare_accessor_rule(const Parser::Rule &first, const Parser::Rule &second);
        bool compare_accessor_internal(const Parser::Rule &first, const Parser::Rule &second);
        bool compare_accessor_internal(const std::vector<Parser::Rule> &first, const std::vector<Parser::Rule> &second);
        bool compare_booolean_rule(const Parser::Rule &first, const Parser::Rule &second);
        bool compare_array_rule(const Parser::Rule &first, const Parser::Rule &second);
        bool compare_object_rule(const Parser::Rule &first, const Parser::Rule &second);
        bool compare_number_rule(const Parser::Rule &first, const Parser::Rule &second);
        bool compare_id_rule(const Parser::Rule &first, const Parser::Rule &second);
        bool compare_op_rule(const Parser::Rule &first, const Parser::Rule &second);
        bool compare_other_rule(const Parser::Rule &first, const Parser::Rule &second);
        bool compare_escape_rule(const Parser::Rule &first, const Parser::Rule &second);
        bool compare_csequence_rule(const Parser::Rule &first, const Parser::Rule &second);
        bool compare_csequence_internal_dt(const Parser::Rule &first, const Parser::Rule &second);
        bool compare_csequence_diapason_rule(const Parser::Rule &first, const Parser::Rule &second);
        bool compare_csequence_symbol_rule(const Parser::Rule &first, const Parser::Rule &second);
        bool compare_csequence_escape_rule(const Parser::Rule &first, const Parser::Rule &second);
        bool compare_group_rule(const Parser::Rule &first, const Parser::Rule &second);
        bool compare_cll_rule(const Parser::Rule &first, const Parser::Rule &second);
        bool compare_cll_function_call(const Parser::Rule &first, const Parser::Rule &second);
        bool compare_cll_function_body(const Parser::Rule &first, const Parser::Rule &second);
        bool compare_cll_function_arguments(const Parser::Rule &first, const Parser::Rule &second);
        bool compare_any_data_rule(const Parser::Rule &first, const Parser::Rule &second);
        bool compare_method_call_rule(const Parser::Rule &first, const Parser::Rule &second);
        bool compareStringViewRule(const Parser::Rule &first, const Parser::Rule &second);
        bool compareStringRule(const Parser::Rule &first, const Parser::Rule &second);

        bool checkForPointing(const std::vector<std::string> &name, const std::vector<Parser::Rule> &rules, std::unordered_set<std::vector<std::string>> &visited);
        
        // treeNormalizer
        void normalizeHelper(std::vector<Parser::Rule> &rules, std::vector<std::string> fullname, std::vector<std::pair<std::string, std::vector<std::string>>> &nested_rule_names);
        void getNestedNames(std::vector<Parser::Rule> &nested_rules, std::vector<std::pair<std::string, std::vector<std::string>>> &nested_rule_names, std::vector<std::string> &fullname);
        void normalizeRule(Parser::Rule &member, std::vector<std::string> &fullname, std::vector<std::pair<std::string, std::vector<std::string>>> &nested_rule_names);
        void normalizeTreeHelper(Parser::Tree &tree, std::vector<std::string> &fullname, std::vector<std::pair<std::string, std::vector<std::string>>> &nested_rule_names);
        // replace dublications functions
        void getReplacedTree(Parser::Tree &tree, std::vector<Parser::Rule> &rules, const std::vector<std::string> &name, std::vector<std::string> fullname);
        void replaceDublicationsHelper(Parser::Tree &tree, std::vector<std::string> fullname, bool global);
        void removeEmptyRule(Parser::Tree &tree);
        // inline tokens functions
        void accumulateInlineNamesAndRemove(Parser::Tree& tree, std::unordered_map<std::vector<std::string>, Parser::Rule> &map, std::vector<std::string> nested);
        void inlineTokensInTable( std::unordered_map<std::vector<std::string>, Parser::Rule> &map);
        void inline_Rule_rule(std::vector<Parser::Rule> &rules, const std::unordered_map<std::vector<std::string>, Parser::Rule> &map, std::vector<std::string> nested);
        void inlineTokensHelper(Parser::Tree &tree, const std::unordered_map<std::vector<std::string>, Parser::Rule> &map, std::vector<std::string> nested);
        void inlineTokensHelper(Parser::Tree &tree);
        // literals to tokens functions
        auto getNewRuleAndToken(const Parser::Rule &val, const Parser::Rule &qualifier, std::vector<std::pair<Parser::Rule, Parser::Rule>> &generated) -> std::pair<Parser::Rule, Parser::Rule>;
        bool checkRuleEscaped(const Parser::Rule &rule);
        void getTokensFromRule_rule(Parser::Tree &tree, std::vector<Parser::Rule>& rule, std::vector<std::pair<Parser::Rule, Parser::Rule>> &generated, bool is_not_rule_rule = false);
        auto getTokensFromRule(Parser::Rule &member, std::vector<std::pair<Parser::Rule, Parser::Rule>> &generated) -> Parser::Tree;
        void literalsToTokenHelper(Parser::Tree& tree, Parser::Tree &treeInsert, std::vector<std::pair<Parser::Rule, Parser::Rule>> &generated);
        // sort by priority functions
        bool sortPriority(const Parser::Rule &first, const Parser::Rule &second);
        void sortByPriorityHelper(std::vector<Parser::Rule> &rules);
        void sortByPriority(Parser::Tree &tree);

        // other functions
        void getTokenAndRuleNamesHelper(const Parser::Tree &tree, std::vector<std::vector<std::string>> &tokens, std::vector<std::vector<std::string>> &rules, std::unordered_set<std::vector<std::string>> &seen, std::vector<std::string> &fullname);   
        auto get_use_data(const Parser::Rule &use) -> use_prop_t;
        void accamulateUsePlaces(std::vector<Parser::Rule>& rules, use_place_table &use_places, std::vector<std::string> &fullname);
        void getTokensForLexer(Parser::Tree &tree, use_place_table &use_places, std::vector<Parser::Rule> &rule_op, std::vector<std::string> &fullname);
        void getUsePlacesTableHelper(Parser::Tree &tree, use_place_table &use_places, std::vector<std::string> &fullname);
        auto getFirstSet(const Parser::Rule &rule) -> std::vector<Parser::Rule>;
        void getConflictsTableForRule(const std::vector<Parser::Rule> &rules, ConflictsList &table);
        void resolveConflictsHelper(const std::vector<Parser::Rule> &rules);
        void resolveConflicts(Parser::Tree &tree);
        void constructor() {
            normalize();                       // normalize tree
            sortByPriority();                 // sorts elements to get which should be placed on top. This ensures proper matching
            literalsToToken();                // get tokens from literals (e.g from string, hex or binary). This ensure proper tokenization process
            addSpaceToken();
            replaceDublications();            // replace dublicated tokens (e.g when token content is found somewhere else, replace it to token)
            inlineTokens();                   // inline tokens to make sure that every token is used only once
        }
    public:
        Tree(Parser::Tree &&tree, bool rawAssign = false) : tree(std::move(tree)) {
            if (!rawAssign)
                constructor();
        }
        Tree(Parser::Tree &tree, bool rawAssign = false) : tree(tree) {
            if (!rawAssign)
                constructor();
        }
        static auto getValueFromGroup(const Parser::Rule &rule) -> std::vector<Parser::Rule>;
        static auto getValueFromGroup(const Parser::Rule &rule, std::any &variable) -> std::vector<Parser::Rule>;
        static auto getValueFromRule_rule(const Parser::Rule &rule) -> Parser::Rule;
        static auto getValueFromRule_rule(const Parser::Rule &rule, Parser::Rule &quantifier) -> Parser::Rule;
        static auto singleRuleToToken(const Parser::Rule &input, size_t &count) -> Parser::Rule;
        static auto make_rule() -> Parser::Rule;
        static auto make_rule(Parser::Rules name) -> Parser::Rule;
        static auto make_rule(Parser::Rules name, std::any data) -> Parser::Rule;
        bool compare_rule_matching(const Parser::Rule &first, const Parser::Rule &second, std::unordered_set<std::pair<std::vector<std::string>, std::vector<std::string>>> &visited);
        bool compare_rule(const Parser::Rule &first, const Parser::Rule &second);
        bool compare_rules(const std::vector<Parser::Rule> &first, const std::vector<Parser::Rule> &second);
        bool compare_token_with_rules(const Parser::Tree &first, const Parser::Tree &second);
        auto find_token_in_rule(const Parser::Tree &token_rule, const Parser::Tree &rules) -> std::vector<int>;
        static auto find_token_in_tree(Parser::Tree &tree, std::vector<std::string> names, size_t pos = 0) -> Parser::Rule*;
        auto find_token_in_tree(std::vector<std::string> names, size_t pos = 0) -> Parser::Rule*;

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
        auto getTokenAndRuleNames() -> std::pair<std::vector<std::vector<std::string>>, std::vector<std::vector<std::string>>>;
        auto accamulate_use_data_to_map() -> use_prop_t;
        auto getUsePlacesTable() -> use_place_table;
        auto get_data_blocks(const LLIR &ir) -> std::pair<data_block_t, data_block_t>;
        auto getCodeForLexer(use_place_table use_places) -> lexer_code;
        void resolveConflicts();
};
