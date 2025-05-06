#pragma once
#include <corelib.h>
#include <Parser.h>
#include <internal_types.h>
#include <list>
#include <AST.h>
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
        enum class UniversalRules {
            Rule_name, Rule_group, Rule_data_block, Rule_op, Rule_csequence, Rule_any, Rule_nospace, Rule_escaped, Rule_hex, Rule_bin
        };
        struct UniversalRule {
            UniversalRules name;
            Parser::Rule prefix;
            Parser::Rule quantifier;
            Parser::Rule rule_data;
            Parser::Token token_data;
        };
        struct TreeMapMember {
            Parser::arr_t<UniversalRule> rules;
            Parser::Types::Rule_data_block_data data_block;
            std::vector<std::vector<std::string>> nested_rule_names;
        };

        using ConflictsList = std::vector<Conflict>;
        using use_place_t_part = std::pair<std::vector<std::string>, std::vector<Use_place>>;
        using use_place_table = std::unordered_map<std::vector<std::string>, std::vector<Use_place>>;
        using TreeMap = std::unordered_map<std::vector<std::string>, TreeMapMember>;
    private:
        AST ast;
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

        // bool checkForPointing(const std::vector<std::string> &name, const std::vector<Parser::Rule> &rules, std::unordered_set<std::vector<std::string>> &visited);
        
        // // treeNormalizer
        // void reduceRuleToUniversal(Parser::Types::Rule_data &rule_data, TreeMapMember &member);
        // void buildTreeMapFromRule(Parser::Rule &rule, std::vector<std::string> &fullname);
        // void buildTreeMap(std::vector<Parser::Rule> &modules);
        // void normalizeHelper(Parser::arr_t<UniversalRule> &rules, std::vector<std::string> fullname, std::vector<std::vector<std::string>> &nested_rule_names);
        // // replace dublications functions
        // void getReplacedTree(Parser::Tree &tree, std::vector<Parser::Rule> &rules, const std::vector<std::string> &name, std::vector<std::string> fullname);
        // void replaceDublicationsHelper(Parser::Tree &tree, std::vector<std::string> fullname, bool global);
        // void removeEmptyRule(Parser::Tree &tree);
        // // inline tokens functions
        // void accumulateInlineNamesAndRemove(Parser::Tree& tree, std::unordered_map<std::vector<std::string>, Parser::Rule> &map, std::vector<std::string> nested);
        // void inlineTokensInTable( std::unordered_map<std::vector<std::string>, Parser::Rule> &map);
        // void inline_Rule_rule(std::vector<Parser::Rule> &rules, const std::unordered_map<std::vector<std::string>, Parser::Rule> &map, std::vector<std::string> nested);
        // void inlineTokensHelper(Parser::Tree &tree, const std::unordered_map<std::vector<std::string>, Parser::Rule> &map, std::vector<std::string> nested);
        // void inlineTokensHelper(Parser::Tree &tree);
        // literals to tokens functions
        
        // sort by priority functions
        bool sortPriority(TreeAPI::String &first, TreeAPI::String &second);
        bool sortPriority(TreeAPI::RuleMemberBin &first, TreeAPI::RuleMemberBin second);
        bool sortPriority(TreeAPI::RuleMemberHex &first, TreeAPI::RuleMemberHex &second);
        bool sortPriority(TreeAPI::RuleMemberName &first, TreeAPI::RuleMemberName &second);
        bool sortPriority(TreeAPI::RuleMemberCsequence &first, TreeAPI::RuleMemberCsequence &second);
        bool sortPriority(TreeAPI::RuleMemberGroup &first, TreeAPI::RuleMemberGroup &second);
        bool sortPriority(TreeAPI::RuleMemberOp &first, TreeAPI::RuleMemberOp &second);
        bool sortPriority(TreeAPI::RuleMember &first, TreeAPI::RuleMember &second);        
        void sortByPriority(std::vector<TreeAPI::RuleMember>& members);

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
        Tree(const AST &ast, bool rawAssign = false) : ast(ast) {
            if (!rawAssign)
                constructor();
        }
        static auto singleRuleToToken(const Parser::Rule &input, size_t &count) -> Parser::Rule;
        static auto make_rule() -> Parser::Rule;
        static auto make_rule(Parser::Rules name) -> Parser::Rule;
        static auto make_rule(Parser::Rules name, std::any data) -> Parser::Rule;
        static auto make_token() -> Parser::Token;
        static auto make_token(Parser::Tokens name) -> Parser::Token;
        static auto make_token(Parser::Tokens name, std::any data) -> Parser::Token;
        bool compare_rule_matching(const Parser::Rule &first, const Parser::Rule &second, std::unordered_set<std::pair<std::vector<std::string>, std::vector<std::string>>> &visited);
        bool compare_rule(const Parser::Rule &first, const Parser::Rule &second);
        bool compare_rules(const std::vector<Parser::Rule> &first, const std::vector<Parser::Rule> &second);
        bool compare_token_with_rules(const Parser::Tree &first, const Parser::Tree &second);
        auto find_token_in_rule(const Parser::Tree &token_rule, const Parser::Tree &rules) -> std::vector<int>;
        static auto find_token_in_tree(Parser::Tree &tree, std::vector<std::string> names, size_t pos = 0) -> Parser::Rule*;
        auto find_token_in_tree(std::vector<std::string> names, size_t pos = 0) -> Parser::Rule*;

        auto getTreeMap() -> TreeMap&;

        void removeEmptyRule();
        void inlineSingleGroups();
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
