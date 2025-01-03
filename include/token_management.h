#include <parser.h>
#include <internal_types.h>
#include <forward_list>
namespace Tokens {
    Parser::Rule singleRuleToToken(Parser::Rule input);
    Parser::Rule make_rule();
    Parser::Rule make_rule(Parser::Rules name);
    Parser::Rule make_rule(Parser::Rules name, std::any data);
    bool compare_rule(Parser::Rule first, Parser::Rule second);
    bool compare_string_rule(Parser::Rule first, Parser::Rule second);
    bool compare_hex_rule(Parser::Rule first, Parser::Rule second);
    bool compare_bin_rule(Parser::Rule first, Parser::Rule second);
    bool compare_accessor_rule(Parser::Rule first, Parser::Rule second);
    bool compare_accessor_internal(Parser::Rule first, Parser::Rule second);
    bool compare_accessor_internal(arr_t<Parser::Rule> first, arr_t<Parser::Rule> second);
    bool compare_number_rules(Parser::Rule first, Parser::Rule second);
    bool compare_id_rule(Parser::Rule first, Parser::Rule second);
    bool compare_op_rule(Parser::Rule first, Parser::Rule second);
    bool compare_other_rule(Parser::Rule first, Parser::Rule second);
    bool compare_other_nested_name(arr_t<Parser::Rule> nested_name1, arr_t<Parser::Rule> nested_name2);
    bool compare_escape_rule(Parser::Rule first, Parser::Rule second);
    bool compare_csequence_rule(Parser::Rule first, Parser::Rule second);
    bool compare_csequence_internal_dt(Parser::Rule first, Parser::Rule second);
    bool compare_csequence_diapason_rule(Parser::Rule first, Parser::Rule second);
    bool compare_csequence_symbol_rule(Parser::Rule first, Parser::Rule second);
    bool compare_csequence_escape_rule(Parser::Rule first, Parser::Rule second);
    bool compareStringViewRule(Parser::Rule first, Parser::Rule second);
    bool compareStringRule(Parser::Rule first, Parser::Rule second);
    // compares the token with rules and 
    std::forward_list<int> compare_rules(Parser::Tree token_rule, Parser::Tree rules);
}