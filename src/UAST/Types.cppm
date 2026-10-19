export module UAST;
import std;

// Owned syntax data. No parser storage, name lookup, or semantic validation.
export namespace UAST {
struct SourcePosition {
    std::string file;
    std::size_t offset = std::string::npos, length = 0, line = 0, column = 0;
};
template<class T> struct Node {
    SourcePosition position;
    bool absent = true;
    T value{};
    bool empty() const { return absent; }
    const T& data() const { return value; }
    T& data() { return value; }
};
// A lossless Python syntax tree: node kinds, named fields, sequence and variant
// structure, scalar values, absent nodes, and positions are all retained.
struct PythonNode {
    std::string kind, field, scalar;
    SourcePosition position;
    bool absent = false;
    std::vector<PythonNode> children;
};
struct __WS;
struct advanced_rule_dep_decl_DEPENDS;
struct AUTO;
struct FAIL;
struct SEMICOLON;
struct COLON;
struct EQUALS_SIGN;
struct AMPERSAND;
struct PERCENT_SIGN;
struct rule_nested_rule_NUMBER_SIGN;
struct rule_nested_rule;
struct LEFT_CURLY_BRACKET;
struct rule_value_shared_counter_registration_AUTO;
struct rule_value;
struct COMMERCIAL_AT;
struct rule_value_QUANTIFIER;
struct rule_value_NOSPACE;
struct rule_value_ANY;
struct template_params_LESS_THAN_SIGN;
struct rule_value_STRING;
struct grammar_modifier_AUTO;
struct grammar_modifier_MOD;
struct rule_value_SPACE;
struct template_params_GREATER_THAN_SIGN;
struct rule_value_alternative_VERTICAL_LINE;
struct rule_value_alternative;
struct grammar_modifier_RIGHT_SQUARE_BRACKET;
struct rule_value_dyn_DOLLAR_SIGN;
struct advanced_rule_regular_match_MATCH;
struct COMMA;
struct RIGHT_PARENTHESIS;
struct LEFT_PARENTHESIS;
struct RIGHT_CURLY_BRACKET;
struct NUMBER;
struct PY_RAW;
struct ID;
struct rule_value_CGROUP;
struct rule_value_group;
struct rule_value_mul_capture;
struct grammar_modifier;
struct expr;
struct stmt;
struct rule_value_shared_counter_registration;
struct advanced_rule_regular_match_unpack;
struct forward_declaration;
struct param;
struct rule_ast_abbr;
struct rule_f_binding;
struct rule_value_ast_capture;
struct rule_value_var_capture;
struct explicit_expr;
struct rule_ast_full_part;
struct rule_ast_single_value;
struct rule_value_counter_bounded;
struct rule_value_dyn_dyn_expr;
struct advanced_rule_regular_match;
struct advanced_rule_dep_decl;
struct template_params;
struct params;
struct rule_ast_full;
struct rule_value_counter;
struct rule_value_dyn;
struct advanced_rule;
struct name;
struct rule_ast;
struct grammar;
struct advanced_rule_fail_call;
struct fail_block;
struct rule_value_fail_capture;
struct rule_value_pattern;
struct rule;
struct main;
struct rule_value_one_capture;
struct __WS {
};
struct advanced_rule_dep_decl_DEPENDS {
};
struct AUTO {
};
struct FAIL {
};
struct SEMICOLON {
};
struct COLON {
};
struct EQUALS_SIGN {
};
struct AMPERSAND {
};
struct PERCENT_SIGN {
};
struct rule_nested_rule_NUMBER_SIGN {
};
struct rule_nested_rule {
    Node<std::shared_ptr<grammar>> value{};
};
struct LEFT_CURLY_BRACKET {
};
struct rule_value_shared_counter_registration_AUTO {
};
struct rule_value {
    std::variant<std::monostate, Node<std::shared_ptr<rule_value_mul_capture>>, Node<std::shared_ptr<rule_value_one_capture>>> value{};
};
struct COMMERCIAL_AT {
};
struct rule_value_QUANTIFIER {
    char value{};
};
struct rule_value_NOSPACE {
};
struct rule_value_ANY {
};
struct template_params_LESS_THAN_SIGN {
};
struct rule_value_STRING {
    std::string value{};
};
struct grammar_modifier_AUTO {
};
struct grammar_modifier_MOD {
    std::string value{};
};
struct rule_value_SPACE {
};
struct template_params_GREATER_THAN_SIGN {
};
struct rule_value_alternative_VERTICAL_LINE {
};
struct rule_value_alternative {
    Node<std::shared_ptr<rule_value_pattern>> value{};
};
struct grammar_modifier_RIGHT_SQUARE_BRACKET {
};
struct rule_value_dyn_DOLLAR_SIGN {
};
struct advanced_rule_regular_match_MATCH {
};
struct COMMA {
};
struct RIGHT_PARENTHESIS {
};
struct LEFT_PARENTHESIS {
};
struct RIGHT_CURLY_BRACKET {
};
struct NUMBER {
    std::string full{};
    std::string floating{};
};
struct PY_RAW {
    std::string value{};
};
struct ID {
    std::string value{};
};
struct rule_value_CGROUP {
    char negative{};
    std::string v{};
};
struct rule_value_group {
    std::vector<Node<std::shared_ptr<rule_value>>> value{};
};
struct rule_value_mul_capture {
    std::variant<std::monostate, Node<PERCENT_SIGN>, Node<COMMERCIAL_AT>> type{};
    std::vector<Node<std::shared_ptr<rule_value_one_capture>>> cap{};
};
struct grammar_modifier {
    Node<grammar_modifier_MOD> value{};
};
struct expr {
    Node<PY_RAW> value{};
    PythonNode python;
};
struct stmt {
    Node<PY_RAW> value{};
    PythonNode python;
};
struct rule_value_shared_counter_registration {
    Node<ID> value{};
};
struct advanced_rule_regular_match_unpack {
    std::vector<Node<ID>> value{};
};
struct forward_declaration {
    Node<ID> value{};
};
struct param {
    Node<ID> first_p{};
    std::vector<Node<ID>> following_p{};
};
struct rule_ast_abbr {
    Node<ID> f{};
    std::vector<Node<ID>> seq{};
};
struct rule_f_binding {
    Node<ID> f{};
    std::vector<Node<ID>> seq{};
};
struct rule_value_ast_capture {
    Node<ID> value{};
};
struct rule_value_var_capture {
    Node<ID> value{};
};
struct explicit_expr {
    Node<expr> value{};
};
struct rule_ast_full_part {
    Node<ID> key{};
    Node<expr> e{};
};
struct rule_ast_single_value {
    std::variant<std::monostate, Node<COMMERCIAL_AT>, Node<expr>> value{};
};
struct rule_value_counter_bounded {
    std::variant<std::monostate, Node<expr>, Node<ID>, Node<NUMBER>> value{};
};
struct rule_value_dyn_dyn_expr {
    Node<expr> value{};
};
struct advanced_rule_regular_match {
    std::vector<Node<rule_value>> patterns{};
    std::variant<std::monostate, Node<SEMICOLON>, Node<advanced_rule_regular_match_unpack>> assign_names{};
};
struct advanced_rule_dep_decl {
    Node<forward_declaration> value{};
};
struct template_params {
    Node<param> value{};
};
struct params {
    Node<param> value{};
};
struct rule_ast_full {
    std::vector<Node<rule_ast_full_part>> value{};
};
struct rule_value_counter {
    Node<rule_value_QUANTIFIER> quantifier{};
    Node<rule_value_counter_bounded> repetitions{};
};
struct rule_value_dyn {
    std::variant<std::monostate, Node<ID>, Node<rule_value_dyn_dyn_expr>> value{};
};
struct advanced_rule {
    std::vector<Node<advanced_rule_dep_decl>> dep{};
    std::vector<std::variant<std::monostate, Node<stmt>, Node<advanced_rule_regular_match>>> body{};
};
struct name {
    Node<ID> primary{};
    std::vector<Node<ID>> nested{};
    Node<template_params> temp_params{};
    Node<params> param{};
};
struct rule_ast {
    std::variant<std::monostate, Node<rule_ast_single_value>, Node<rule_ast_full>, Node<rule_ast_abbr>> value{};
};
struct grammar {
    std::vector<Node<grammar_modifier>> mod{};
    Node<name> name{};
    std::variant<std::monostate, Node<advanced_rule>, Node<std::shared_ptr<rule>>> entry{};
};
struct advanced_rule_fail_call {
    Node<name> value{};
};
struct fail_block {
    Node<name> name{};
    Node<stmt> val{};
};
struct rule_value_fail_capture {
    Node<name> value{};
};
struct rule_value_pattern {
    std::variant<std::monostate, Node<rule_value_SPACE>, Node<rule_value_CGROUP>, Node<rule_value_STRING>, Node<rule_value_dyn>, Node<rule_value_NOSPACE>, Node<std::shared_ptr<rule_value_group>>, Node<rule_value_ANY>, Node<name>> value{};
};
struct rule {
    std::vector<Node<rule_value>> v{};
    Node<rule_ast> ast_pointer{};
    Node<rule_f_binding> fail_pointer{};
    std::vector<Node<std::shared_ptr<rule_nested_rule>>> nested{};
};
struct main {
    std::vector<std::variant<std::monostate, Node<fail_block>, Node<grammar>>> value{};
};
struct rule_value_one_capture {
    Node<rule_value_var_capture> v_cap{};
    Node<rule_value_ast_capture> ast_cap{};
    Node<rule_value_fail_capture> fail_cap{};
    Node<std::shared_ptr<rule_value_pattern>> val{};
    std::vector<Node<std::shared_ptr<rule_value_alternative>>> alts{};
    Node<rule_value_counter> quantifier{};
    Node<rule_value_shared_counter_registration> registration{};
};
}
