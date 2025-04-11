#pragma once
#include <parser.h>
#include <internal_types.h>
#include <list>
namespace Tokens {
    Parser::Rule singleRuleToToken(const Parser::Rule &input);
    Parser::Rule make_rule();
    Parser::Rule make_rule(Parser::Rules name);
    Parser::Rule make_rule(Parser::Rules name, std::any data);
    bool compare_rule(const Parser::Rule &first, const Parser::Rule &second);
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
    bool compare_method_call_rule(const Parser::Rule &first, const Parser::Rule &second);
    bool compare_cll_rule(const Parser::Rule &first, const Parser::Rule &second);
    bool compare_cll_function_call(const Parser::Rule &first, const Parser::Rule &second);
    bool compare_cll_function_body(const Parser::Rule &first, const Parser::Rule &second);
    bool compare_cll_function_arguments(const Parser::Rule &first, const Parser::Rule &second);
    bool compare_any_data_rule(const Parser::Rule &first, const Parser::Rule &second);
    bool compare_method_call_rule(const Parser::Rule &first, const Parser::Rule &second);
    bool compareStringViewRule(const Parser::Rule &first, const Parser::Rule &second);
    bool compareStringRule(const Parser::Rule &first, const Parser::Rule &second);
    // compares the token with rules and 
    bool compare_rules(const std::vector<Parser::Rule> &first, const std::vector<Parser::Rule> &second);
    bool compare_token_with_rules(const Parser::Tree &first, const Parser::Tree &second);
    std::vector<int> find_token_in_rule(const Parser::Tree &token_rule, const Parser::Tree &rules);
    Parser::Rule* find_token_in_tree(Parser::Tree &tree, std::vector<std::string> names, size_t pos = 0);
}