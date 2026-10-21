module;
#include <output/Parser.h>
export module UAST;
export import UAST.PyAST;
import std;

// The UAST *is* the ISPA-generated parser tree (Parser::FlatTypes); nothing is
// copied. These aliases only give the structs their short, stable UAST names, so
// the rest of the code base does not depend on the generator's namespaces.
//
// A UAST::Node<T> is the generated ::ISPA_STD::Node<T>: it carries the offset,
// length, line and column of the match (see positionOf) but not the file name.
//
// Python actions (`expr` / `stmt`) stay as raw text here; AST.Builder parses them
// into the typed UAST::py tree through UAST.Python when it needs them.
export namespace UAST {
template<class T> using Node = ::ISPA_STD::Node<T>;

template<class T> SourcePosition positionOf(const Node<T>& node, const std::string& file = {}) {
    return {file, node.startpos(), node.length(), node.line(), node.column()};
}

// Generic, lossless view of a raw parser tree (node kinds, named fields, sequence
// and variant structure, scalar values, absent nodes, positions). Used by
// describe() and, in UAST.Python, as the intermediate form the typed Python AST is
// built from.
struct PythonNode {
    std::string kind, field, scalar;
    SourcePosition position;
    bool absent = false;
    std::vector<PythonNode> children;

    auto members() { return std::tie(kind, field, scalar, position, absent, children); }
    auto members() const { return std::tie(kind, field, scalar, position, absent, children); }
    bool operator==(const PythonNode& other) const { return members() == other.members(); }
    bool operator<(const PythonNode& other) const { return members() < other.members(); }
};

using __WS = ::Parser::FlatTypes::__WS;
using advanced_rule_dep_decl_DEPENDS = ::Parser::FlatTypes::advanced_rule_dep_decl_DEPENDS;
using AUTO = ::Parser::FlatTypes::AUTO;
using FAIL = ::Parser::FlatTypes::FAIL;
using SEMICOLON = ::Parser::FlatTypes::SEMICOLON;
using COLON = ::Parser::FlatTypes::COLON;
using EQUALS_SIGN = ::Parser::FlatTypes::EQUALS_SIGN;
using AMPERSAND = ::Parser::FlatTypes::AMPERSAND;
using PERCENT_SIGN = ::Parser::FlatTypes::PERCENT_SIGN;
using rule_nested_rule_NUMBER_SIGN = ::Parser::FlatTypes::rule_nested_rule_NUMBER_SIGN;
using rule_nested_rule = ::Parser::FlatTypes::rule_nested_rule;
using LEFT_CURLY_BRACKET = ::Parser::FlatTypes::LEFT_CURLY_BRACKET;
using rule_value_shared_counter_registration_AUTO = ::Parser::FlatTypes::rule_value_shared_counter_registration_AUTO;
using rule_value = ::Parser::FlatTypes::rule_value;
using COMMERCIAL_AT = ::Parser::FlatTypes::COMMERCIAL_AT;
using rule_value_QUANTIFIER = ::Parser::FlatTypes::rule_value_QUANTIFIER;
using rule_value_NOSPACE = ::Parser::FlatTypes::rule_value_NOSPACE;
using rule_value_ANY = ::Parser::FlatTypes::rule_value_ANY;
using template_params_LESS_THAN_SIGN = ::Parser::FlatTypes::template_params_LESS_THAN_SIGN;
using rule_value_STRING = ::Parser::FlatTypes::rule_value_STRING;
using grammar_modifier_AUTO = ::Parser::FlatTypes::grammar_modifier_AUTO;
using grammar_modifier_MOD = ::Parser::FlatTypes::grammar_modifier_MOD;
using rule_value_SPACE = ::Parser::FlatTypes::rule_value_SPACE;
using template_params_GREATER_THAN_SIGN = ::Parser::FlatTypes::GREATER_THAN_SIGN;
using rule_value_alternative_VERTICAL_LINE = ::Parser::FlatTypes::rule_value_alternative_VERTICAL_LINE;
using rule_value_alternative = ::Parser::FlatTypes::rule_value_alternative;
using grammar_modifier_RIGHT_SQUARE_BRACKET = ::Parser::FlatTypes::grammar_modifier_RIGHT_SQUARE_BRACKET;
using rule_value_dyn_DOLLAR_SIGN = ::Parser::FlatTypes::rule_value_dyn_DOLLAR_SIGN;
using advanced_rule_regular_match_MATCH = ::Parser::FlatTypes::advanced_rule_regular_match_MATCH;
using COMMA = ::Parser::FlatTypes::COMMA;
using RIGHT_PARENTHESIS = ::Parser::FlatTypes::RIGHT_PARENTHESIS;
using LEFT_PARENTHESIS = ::Parser::FlatTypes::LEFT_PARENTHESIS;
using RIGHT_CURLY_BRACKET = ::Parser::FlatTypes::RIGHT_CURLY_BRACKET;
using NUMBER = ::Parser::FlatTypes::NUMBER;
using PY_RAW = ::Parser::FlatTypes::PY_RAW;
using ID = ::Parser::FlatTypes::ID;
using rule_value_CGROUP = ::Parser::FlatTypes::rule_value_CGROUP;
using rule_value_group = ::Parser::FlatTypes::rule_value_group;
using rule_value_mul_capture = ::Parser::FlatTypes::rule_value_mul_capture;
using grammar_modifier = ::Parser::FlatTypes::grammar_modifier;
using expr = ::Parser::FlatTypes::expr;
using stmt = ::Parser::FlatTypes::stmt;
using rule_value_shared_counter_registration = ::Parser::FlatTypes::rule_value_shared_counter_registration;
using advanced_rule_regular_match_unpack = ::Parser::FlatTypes::advanced_rule_regular_match_unpack;
using forward_declaration = ::Parser::FlatTypes::forward_declaration;
using param = ::Parser::FlatTypes::param;
using rule_ast_abbr = ::Parser::FlatTypes::rule_ast_abbr;
using rule_f_binding = ::Parser::FlatTypes::rule_f_binding;
using rule_value_ast_capture = ::Parser::FlatTypes::rule_value_ast_capture;
using rule_value_var_capture = ::Parser::FlatTypes::rule_value_var_capture;
using explicit_expr = ::Parser::FlatTypes::explicit_expr;
using rule_ast_full_part = ::Parser::FlatTypes::rule_ast_full_part;
using rule_ast_single_value = ::Parser::FlatTypes::rule_ast_single_value;
using rule_value_counter_bounded = ::Parser::FlatTypes::rule_value_counter_bounded;
using rule_value_dyn_dyn_expr = ::Parser::FlatTypes::rule_value_dyn_dyn_expr;
using advanced_rule_regular_match = ::Parser::FlatTypes::advanced_rule_regular_match;
using advanced_rule_dep_decl = ::Parser::FlatTypes::advanced_rule_dep_decl;
using template_params = ::Parser::FlatTypes::template_params;
using params = ::Parser::FlatTypes::params;
using rule_ast_full = ::Parser::FlatTypes::rule_ast_full;
using rule_value_counter = ::Parser::FlatTypes::rule_value_counter;
using rule_value_dyn = ::Parser::FlatTypes::rule_value_dyn;
using advanced_rule = ::Parser::FlatTypes::advanced_rule;
using name = ::Parser::FlatTypes::name;
using rule_ast = ::Parser::FlatTypes::rule_ast;
using grammar = ::Parser::FlatTypes::grammar;
using advanced_rule_fail_call = ::Parser::FlatTypes::advanced_rule_fail_call;
using fail_block = ::Parser::FlatTypes::fail_block;
using rule_value_fail_capture = ::Parser::FlatTypes::rule_value_fail_capture;
using rule_value_pattern = ::Parser::FlatTypes::rule_value_pattern;
using rule = ::Parser::FlatTypes::rule;
using main = ::Parser::FlatTypes::main;
using rule_value_one_capture = ::Parser::FlatTypes::rule_value_one_capture;
}
