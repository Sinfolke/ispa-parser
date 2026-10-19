module;
#include <output/Parser.h>
module UAST.Parser;
import std;
namespace {
UAST::__WS copy(const Parser::FlatTypes::__WS&, const std::string&);
UAST::advanced_rule_dep_decl_DEPENDS copy(const Parser::FlatTypes::advanced_rule_dep_decl_DEPENDS&, const std::string&);
UAST::AUTO copy(const Parser::FlatTypes::AUTO&, const std::string&);
UAST::FAIL copy(const Parser::FlatTypes::FAIL&, const std::string&);
UAST::SEMICOLON copy(const Parser::FlatTypes::SEMICOLON&, const std::string&);
UAST::COLON copy(const Parser::FlatTypes::COLON&, const std::string&);
UAST::EQUALS_SIGN copy(const Parser::FlatTypes::EQUALS_SIGN&, const std::string&);
UAST::AMPERSAND copy(const Parser::FlatTypes::AMPERSAND&, const std::string&);
UAST::PERCENT_SIGN copy(const Parser::FlatTypes::PERCENT_SIGN&, const std::string&);
UAST::rule_nested_rule_NUMBER_SIGN copy(const Parser::FlatTypes::rule_nested_rule_NUMBER_SIGN&, const std::string&);
UAST::rule_nested_rule copy(const Parser::FlatTypes::rule_nested_rule&, const std::string&);
UAST::LEFT_CURLY_BRACKET copy(const Parser::FlatTypes::LEFT_CURLY_BRACKET&, const std::string&);
UAST::rule_value_shared_counter_registration_AUTO copy(const Parser::FlatTypes::rule_value_shared_counter_registration_AUTO&, const std::string&);
UAST::rule_value copy(const Parser::FlatTypes::rule_value&, const std::string&);
UAST::COMMERCIAL_AT copy(const Parser::FlatTypes::COMMERCIAL_AT&, const std::string&);
UAST::rule_value_QUANTIFIER copy(const Parser::FlatTypes::rule_value_QUANTIFIER&, const std::string&);
UAST::rule_value_NOSPACE copy(const Parser::FlatTypes::rule_value_NOSPACE&, const std::string&);
UAST::rule_value_ANY copy(const Parser::FlatTypes::rule_value_ANY&, const std::string&);
UAST::template_params_LESS_THAN_SIGN copy(const Parser::FlatTypes::template_params_LESS_THAN_SIGN&, const std::string&);
UAST::rule_value_STRING copy(const Parser::FlatTypes::rule_value_STRING&, const std::string&);
UAST::grammar_modifier_AUTO copy(const Parser::FlatTypes::grammar_modifier_AUTO&, const std::string&);
UAST::grammar_modifier_MOD copy(const Parser::FlatTypes::grammar_modifier_MOD&, const std::string&);
UAST::rule_value_SPACE copy(const Parser::FlatTypes::rule_value_SPACE&, const std::string&);
UAST::template_params_GREATER_THAN_SIGN copy(const Parser::FlatTypes::template_params_GREATER_THAN_SIGN&, const std::string&);
UAST::rule_value_alternative_VERTICAL_LINE copy(const Parser::FlatTypes::rule_value_alternative_VERTICAL_LINE&, const std::string&);
UAST::rule_value_alternative copy(const Parser::FlatTypes::rule_value_alternative&, const std::string&);
UAST::grammar_modifier_RIGHT_SQUARE_BRACKET copy(const Parser::FlatTypes::grammar_modifier_RIGHT_SQUARE_BRACKET&, const std::string&);
UAST::rule_value_dyn_DOLLAR_SIGN copy(const Parser::FlatTypes::rule_value_dyn_DOLLAR_SIGN&, const std::string&);
UAST::advanced_rule_regular_match_MATCH copy(const Parser::FlatTypes::advanced_rule_regular_match_MATCH&, const std::string&);
UAST::COMMA copy(const Parser::FlatTypes::COMMA&, const std::string&);
UAST::RIGHT_PARENTHESIS copy(const Parser::FlatTypes::RIGHT_PARENTHESIS&, const std::string&);
UAST::LEFT_PARENTHESIS copy(const Parser::FlatTypes::LEFT_PARENTHESIS&, const std::string&);
UAST::RIGHT_CURLY_BRACKET copy(const Parser::FlatTypes::RIGHT_CURLY_BRACKET&, const std::string&);
UAST::NUMBER copy(const Parser::FlatTypes::NUMBER&, const std::string&);
UAST::PY_RAW copy(const Parser::FlatTypes::PY_RAW&, const std::string&);
UAST::ID copy(const Parser::FlatTypes::ID&, const std::string&);
UAST::rule_value_CGROUP copy(const Parser::FlatTypes::rule_value_CGROUP&, const std::string&);
UAST::rule_value_group copy(const Parser::FlatTypes::rule_value_group&, const std::string&);
UAST::rule_value_mul_capture copy(const Parser::FlatTypes::rule_value_mul_capture&, const std::string&);
UAST::grammar_modifier copy(const Parser::FlatTypes::grammar_modifier&, const std::string&);
UAST::expr copy(const Parser::FlatTypes::expr&, const std::string&);
UAST::stmt copy(const Parser::FlatTypes::stmt&, const std::string&);
UAST::rule_value_shared_counter_registration copy(const Parser::FlatTypes::rule_value_shared_counter_registration&, const std::string&);
UAST::advanced_rule_regular_match_unpack copy(const Parser::FlatTypes::advanced_rule_regular_match_unpack&, const std::string&);
UAST::forward_declaration copy(const Parser::FlatTypes::forward_declaration&, const std::string&);
UAST::param copy(const Parser::FlatTypes::param&, const std::string&);
UAST::rule_ast_abbr copy(const Parser::FlatTypes::rule_ast_abbr&, const std::string&);
UAST::rule_f_binding copy(const Parser::FlatTypes::rule_f_binding&, const std::string&);
UAST::rule_value_ast_capture copy(const Parser::FlatTypes::rule_value_ast_capture&, const std::string&);
UAST::rule_value_var_capture copy(const Parser::FlatTypes::rule_value_var_capture&, const std::string&);
UAST::explicit_expr copy(const Parser::FlatTypes::explicit_expr&, const std::string&);
UAST::rule_ast_full_part copy(const Parser::FlatTypes::rule_ast_full_part&, const std::string&);
UAST::rule_ast_single_value copy(const Parser::FlatTypes::rule_ast_single_value&, const std::string&);
UAST::rule_value_counter_bounded copy(const Parser::FlatTypes::rule_value_counter_bounded&, const std::string&);
UAST::rule_value_dyn_dyn_expr copy(const Parser::FlatTypes::rule_value_dyn_dyn_expr&, const std::string&);
UAST::advanced_rule_regular_match copy(const Parser::FlatTypes::advanced_rule_regular_match&, const std::string&);
UAST::advanced_rule_dep_decl copy(const Parser::FlatTypes::advanced_rule_dep_decl&, const std::string&);
UAST::template_params copy(const Parser::FlatTypes::template_params&, const std::string&);
UAST::params copy(const Parser::FlatTypes::params&, const std::string&);
UAST::rule_ast_full copy(const Parser::FlatTypes::rule_ast_full&, const std::string&);
UAST::rule_value_counter copy(const Parser::FlatTypes::rule_value_counter&, const std::string&);
UAST::rule_value_dyn copy(const Parser::FlatTypes::rule_value_dyn&, const std::string&);
UAST::advanced_rule copy(const Parser::FlatTypes::advanced_rule&, const std::string&);
UAST::name copy(const Parser::FlatTypes::name&, const std::string&);
UAST::rule_ast copy(const Parser::FlatTypes::rule_ast&, const std::string&);
UAST::grammar copy(const Parser::FlatTypes::grammar&, const std::string&);
UAST::advanced_rule_fail_call copy(const Parser::FlatTypes::advanced_rule_fail_call&, const std::string&);
UAST::fail_block copy(const Parser::FlatTypes::fail_block&, const std::string&);
UAST::rule_value_fail_capture copy(const Parser::FlatTypes::rule_value_fail_capture&, const std::string&);
UAST::rule_value_pattern copy(const Parser::FlatTypes::rule_value_pattern&, const std::string&);
UAST::rule copy(const Parser::FlatTypes::rule&, const std::string&);
UAST::main copy(const Parser::FlatTypes::main&, const std::string&);
UAST::rule_value_one_capture copy(const Parser::FlatTypes::rule_value_one_capture&, const std::string&);
std::monostate copy(std::monostate v, const std::string&) { return v; }
std::string copy(const std::string& v, const std::string&) { return v; }
char copy(char v, const std::string&) { return v; }
template<class T> auto copy(const std::shared_ptr<T>& p, const std::string& file) {
    using R = decltype(copy(*p, file));
    return p ? std::make_shared<R>(copy(*p, file)) : std::shared_ptr<R>{};
}
template<class T> auto copy(const ISPA_STD::Node<T>& n, const std::string& file) {
    using R = decltype(copy(n.data(), file));
    UAST::Node<R> out;
    out.position = {file, n.startpos(), n.length(), n.line(), n.column()};
    out.absent = n.empty();
    if (!n.empty()) out.value = copy(n.data(), file);
    return out;
}
template<class... T> auto copy(const std::variant<T...>& v, const std::string& file) {
    using R = std::variant<decltype(copy(std::declval<T>(), file))...>;
    return std::visit([&](const auto& n) -> R { return copy(n, file); }, v);
}
template<class T> auto copy(const std::vector<T>& v, const std::string& file) {
    std::vector<decltype(copy(std::declval<T>(), file))> out;
    for (const auto& n : v) out.push_back(copy(n, file));
    return out;
}
UAST::__WS copy(const Parser::FlatTypes::__WS& v, const std::string& file) {
    UAST::__WS out;
    return out;
}
UAST::advanced_rule_dep_decl_DEPENDS copy(const Parser::FlatTypes::advanced_rule_dep_decl_DEPENDS& v, const std::string& file) {
    UAST::advanced_rule_dep_decl_DEPENDS out;
    return out;
}
UAST::AUTO copy(const Parser::FlatTypes::AUTO& v, const std::string& file) {
    UAST::AUTO out;
    return out;
}
UAST::FAIL copy(const Parser::FlatTypes::FAIL& v, const std::string& file) {
    UAST::FAIL out;
    return out;
}
UAST::SEMICOLON copy(const Parser::FlatTypes::SEMICOLON& v, const std::string& file) {
    UAST::SEMICOLON out;
    return out;
}
UAST::COLON copy(const Parser::FlatTypes::COLON& v, const std::string& file) {
    UAST::COLON out;
    return out;
}
UAST::EQUALS_SIGN copy(const Parser::FlatTypes::EQUALS_SIGN& v, const std::string& file) {
    UAST::EQUALS_SIGN out;
    return out;
}
UAST::AMPERSAND copy(const Parser::FlatTypes::AMPERSAND& v, const std::string& file) {
    UAST::AMPERSAND out;
    return out;
}
UAST::PERCENT_SIGN copy(const Parser::FlatTypes::PERCENT_SIGN& v, const std::string& file) {
    UAST::PERCENT_SIGN out;
    return out;
}
UAST::rule_nested_rule_NUMBER_SIGN copy(const Parser::FlatTypes::rule_nested_rule_NUMBER_SIGN& v, const std::string& file) {
    UAST::rule_nested_rule_NUMBER_SIGN out;
    return out;
}
UAST::rule_nested_rule copy(const Parser::FlatTypes::rule_nested_rule& v, const std::string& file) {
    UAST::rule_nested_rule out;
    out.value = copy(v.value, file);
    return out;
}
UAST::LEFT_CURLY_BRACKET copy(const Parser::FlatTypes::LEFT_CURLY_BRACKET& v, const std::string& file) {
    UAST::LEFT_CURLY_BRACKET out;
    return out;
}
UAST::rule_value_shared_counter_registration_AUTO copy(const Parser::FlatTypes::rule_value_shared_counter_registration_AUTO& v, const std::string& file) {
    UAST::rule_value_shared_counter_registration_AUTO out;
    return out;
}
UAST::rule_value copy(const Parser::FlatTypes::rule_value& v, const std::string& file) {
    UAST::rule_value out;
    out.value = copy(v.value, file);
    return out;
}
UAST::COMMERCIAL_AT copy(const Parser::FlatTypes::COMMERCIAL_AT& v, const std::string& file) {
    UAST::COMMERCIAL_AT out;
    return out;
}
UAST::rule_value_QUANTIFIER copy(const Parser::FlatTypes::rule_value_QUANTIFIER& v, const std::string& file) {
    UAST::rule_value_QUANTIFIER out;
    out.value = copy(v.value, file);
    return out;
}
UAST::rule_value_NOSPACE copy(const Parser::FlatTypes::rule_value_NOSPACE& v, const std::string& file) {
    UAST::rule_value_NOSPACE out;
    return out;
}
UAST::rule_value_ANY copy(const Parser::FlatTypes::rule_value_ANY& v, const std::string& file) {
    UAST::rule_value_ANY out;
    return out;
}
UAST::template_params_LESS_THAN_SIGN copy(const Parser::FlatTypes::template_params_LESS_THAN_SIGN& v, const std::string& file) {
    UAST::template_params_LESS_THAN_SIGN out;
    return out;
}
UAST::rule_value_STRING copy(const Parser::FlatTypes::rule_value_STRING& v, const std::string& file) {
    UAST::rule_value_STRING out;
    out.value = copy(v.value, file);
    return out;
}
UAST::grammar_modifier_AUTO copy(const Parser::FlatTypes::grammar_modifier_AUTO& v, const std::string& file) {
    UAST::grammar_modifier_AUTO out;
    return out;
}
UAST::grammar_modifier_MOD copy(const Parser::FlatTypes::grammar_modifier_MOD& v, const std::string& file) {
    UAST::grammar_modifier_MOD out;
    out.value = copy(v.value, file);
    return out;
}
UAST::rule_value_SPACE copy(const Parser::FlatTypes::rule_value_SPACE& v, const std::string& file) {
    UAST::rule_value_SPACE out;
    return out;
}
UAST::template_params_GREATER_THAN_SIGN copy(const Parser::FlatTypes::template_params_GREATER_THAN_SIGN& v, const std::string& file) {
    UAST::template_params_GREATER_THAN_SIGN out;
    return out;
}
UAST::rule_value_alternative_VERTICAL_LINE copy(const Parser::FlatTypes::rule_value_alternative_VERTICAL_LINE& v, const std::string& file) {
    UAST::rule_value_alternative_VERTICAL_LINE out;
    return out;
}
UAST::rule_value_alternative copy(const Parser::FlatTypes::rule_value_alternative& v, const std::string& file) {
    UAST::rule_value_alternative out;
    out.value = copy(v.value, file);
    return out;
}
UAST::grammar_modifier_RIGHT_SQUARE_BRACKET copy(const Parser::FlatTypes::grammar_modifier_RIGHT_SQUARE_BRACKET& v, const std::string& file) {
    UAST::grammar_modifier_RIGHT_SQUARE_BRACKET out;
    return out;
}
UAST::rule_value_dyn_DOLLAR_SIGN copy(const Parser::FlatTypes::rule_value_dyn_DOLLAR_SIGN& v, const std::string& file) {
    UAST::rule_value_dyn_DOLLAR_SIGN out;
    return out;
}
UAST::advanced_rule_regular_match_MATCH copy(const Parser::FlatTypes::advanced_rule_regular_match_MATCH& v, const std::string& file) {
    UAST::advanced_rule_regular_match_MATCH out;
    return out;
}
UAST::COMMA copy(const Parser::FlatTypes::COMMA& v, const std::string& file) {
    UAST::COMMA out;
    return out;
}
UAST::RIGHT_PARENTHESIS copy(const Parser::FlatTypes::RIGHT_PARENTHESIS& v, const std::string& file) {
    UAST::RIGHT_PARENTHESIS out;
    return out;
}
UAST::LEFT_PARENTHESIS copy(const Parser::FlatTypes::LEFT_PARENTHESIS& v, const std::string& file) {
    UAST::LEFT_PARENTHESIS out;
    return out;
}
UAST::RIGHT_CURLY_BRACKET copy(const Parser::FlatTypes::RIGHT_CURLY_BRACKET& v, const std::string& file) {
    UAST::RIGHT_CURLY_BRACKET out;
    return out;
}
UAST::NUMBER copy(const Parser::FlatTypes::NUMBER& v, const std::string& file) {
    UAST::NUMBER out;
    out.full = copy(v.full, file);
    out.floating = copy(v.floating, file);
    return out;
}
UAST::PY_RAW copy(const Parser::FlatTypes::PY_RAW& v, const std::string& file) {
    UAST::PY_RAW out;
    out.value = copy(v.value, file);
    return out;
}
UAST::ID copy(const Parser::FlatTypes::ID& v, const std::string& file) {
    UAST::ID out;
    out.value = copy(v.value, file);
    return out;
}
UAST::rule_value_CGROUP copy(const Parser::FlatTypes::rule_value_CGROUP& v, const std::string& file) {
    UAST::rule_value_CGROUP out;
    out.negative = copy(v.negative, file);
    out.v = copy(v.v, file);
    return out;
}
UAST::rule_value_group copy(const Parser::FlatTypes::rule_value_group& v, const std::string& file) {
    UAST::rule_value_group out;
    out.value = copy(v.value, file);
    return out;
}
UAST::rule_value_mul_capture copy(const Parser::FlatTypes::rule_value_mul_capture& v, const std::string& file) {
    UAST::rule_value_mul_capture out;
    out.type = copy(v.type, file);
    out.cap = copy(v.cap, file);
    return out;
}
UAST::grammar_modifier copy(const Parser::FlatTypes::grammar_modifier& v, const std::string& file) {
    UAST::grammar_modifier out;
    out.value = copy(v.value, file);
    return out;
}
UAST::expr copy(const Parser::FlatTypes::expr& v, const std::string& file) {
    UAST::expr out;
    out.value = copy(v.value, file);
    return out;
}
UAST::stmt copy(const Parser::FlatTypes::stmt& v, const std::string& file) {
    UAST::stmt out;
    out.value = copy(v.value, file);
    return out;
}
UAST::rule_value_shared_counter_registration copy(const Parser::FlatTypes::rule_value_shared_counter_registration& v, const std::string& file) {
    UAST::rule_value_shared_counter_registration out;
    out.value = copy(v.value, file);
    return out;
}
UAST::advanced_rule_regular_match_unpack copy(const Parser::FlatTypes::advanced_rule_regular_match_unpack& v, const std::string& file) {
    UAST::advanced_rule_regular_match_unpack out;
    out.value = copy(v.value, file);
    return out;
}
UAST::forward_declaration copy(const Parser::FlatTypes::forward_declaration& v, const std::string& file) {
    UAST::forward_declaration out;
    out.value = copy(v.value, file);
    return out;
}
UAST::param copy(const Parser::FlatTypes::param& v, const std::string& file) {
    UAST::param out;
    out.first_p = copy(v.first_p, file);
    out.following_p = copy(v.following_p, file);
    return out;
}
UAST::rule_ast_abbr copy(const Parser::FlatTypes::rule_ast_abbr& v, const std::string& file) {
    UAST::rule_ast_abbr out;
    out.f = copy(v.f, file);
    out.seq = copy(v.seq, file);
    return out;
}
UAST::rule_f_binding copy(const Parser::FlatTypes::rule_f_binding& v, const std::string& file) {
    UAST::rule_f_binding out;
    out.f = copy(v.f, file);
    out.seq = copy(v.seq, file);
    return out;
}
UAST::rule_value_ast_capture copy(const Parser::FlatTypes::rule_value_ast_capture& v, const std::string& file) {
    UAST::rule_value_ast_capture out;
    out.value = copy(v.value, file);
    return out;
}
UAST::rule_value_var_capture copy(const Parser::FlatTypes::rule_value_var_capture& v, const std::string& file) {
    UAST::rule_value_var_capture out;
    out.value = copy(v.value, file);
    return out;
}
UAST::explicit_expr copy(const Parser::FlatTypes::explicit_expr& v, const std::string& file) {
    UAST::explicit_expr out;
    out.value = copy(v.value, file);
    return out;
}
UAST::rule_ast_full_part copy(const Parser::FlatTypes::rule_ast_full_part& v, const std::string& file) {
    UAST::rule_ast_full_part out;
    out.key = copy(v.key, file);
    out.e = copy(v.e, file);
    return out;
}
UAST::rule_ast_single_value copy(const Parser::FlatTypes::rule_ast_single_value& v, const std::string& file) {
    UAST::rule_ast_single_value out;
    out.value = copy(v.value, file);
    return out;
}
UAST::rule_value_counter_bounded copy(const Parser::FlatTypes::rule_value_counter_bounded& v, const std::string& file) {
    UAST::rule_value_counter_bounded out;
    out.value = copy(v.value, file);
    return out;
}
UAST::rule_value_dyn_dyn_expr copy(const Parser::FlatTypes::rule_value_dyn_dyn_expr& v, const std::string& file) {
    UAST::rule_value_dyn_dyn_expr out;
    out.value = copy(v.value, file);
    return out;
}
UAST::advanced_rule_regular_match copy(const Parser::FlatTypes::advanced_rule_regular_match& v, const std::string& file) {
    UAST::advanced_rule_regular_match out;
    out.patterns = copy(v.patterns, file);
    out.assign_names = copy(v.assign_names, file);
    return out;
}
UAST::advanced_rule_dep_decl copy(const Parser::FlatTypes::advanced_rule_dep_decl& v, const std::string& file) {
    UAST::advanced_rule_dep_decl out;
    out.value = copy(v.value, file);
    return out;
}
UAST::template_params copy(const Parser::FlatTypes::template_params& v, const std::string& file) {
    UAST::template_params out;
    out.value = copy(v.value, file);
    return out;
}
UAST::params copy(const Parser::FlatTypes::params& v, const std::string& file) {
    UAST::params out;
    out.value = copy(v.value, file);
    return out;
}
UAST::rule_ast_full copy(const Parser::FlatTypes::rule_ast_full& v, const std::string& file) {
    UAST::rule_ast_full out;
    out.value = copy(v.value, file);
    return out;
}
UAST::rule_value_counter copy(const Parser::FlatTypes::rule_value_counter& v, const std::string& file) {
    UAST::rule_value_counter out;
    out.quantifier = copy(v.quantifier, file);
    out.repetitions = copy(v.repetitions, file);
    return out;
}
UAST::rule_value_dyn copy(const Parser::FlatTypes::rule_value_dyn& v, const std::string& file) {
    UAST::rule_value_dyn out;
    out.value = copy(v.value, file);
    return out;
}
UAST::advanced_rule copy(const Parser::FlatTypes::advanced_rule& v, const std::string& file) {
    UAST::advanced_rule out;
    out.dep = copy(v.dep, file);
    out.body = copy(v.body, file);
    return out;
}
UAST::name copy(const Parser::FlatTypes::name& v, const std::string& file) {
    UAST::name out;
    out.primary = copy(v.primary, file);
    out.nested = copy(v.nested, file);
    out.temp_params = copy(v.temp_params, file);
    out.param = copy(v.param, file);
    return out;
}
UAST::rule_ast copy(const Parser::FlatTypes::rule_ast& v, const std::string& file) {
    UAST::rule_ast out;
    out.value = copy(v.value, file);
    return out;
}
UAST::grammar copy(const Parser::FlatTypes::grammar& v, const std::string& file) {
    UAST::grammar out;
    out.mod = copy(v.mod, file);
    out.name = copy(v.name, file);
    out.entry = copy(v.entry, file);
    return out;
}
UAST::advanced_rule_fail_call copy(const Parser::FlatTypes::advanced_rule_fail_call& v, const std::string& file) {
    UAST::advanced_rule_fail_call out;
    out.value = copy(v.value, file);
    return out;
}
UAST::fail_block copy(const Parser::FlatTypes::fail_block& v, const std::string& file) {
    UAST::fail_block out;
    out.name = copy(v.name, file);
    out.val = copy(v.val, file);
    return out;
}
UAST::rule_value_fail_capture copy(const Parser::FlatTypes::rule_value_fail_capture& v, const std::string& file) {
    UAST::rule_value_fail_capture out;
    out.value = copy(v.value, file);
    return out;
}
UAST::rule_value_pattern copy(const Parser::FlatTypes::rule_value_pattern& v, const std::string& file) {
    UAST::rule_value_pattern out;
    out.value = copy(v.value, file);
    return out;
}
UAST::rule copy(const Parser::FlatTypes::rule& v, const std::string& file) {
    UAST::rule out;
    out.v = copy(v.v, file);
    out.ast_pointer = copy(v.ast_pointer, file);
    out.fail_pointer = copy(v.fail_pointer, file);
    out.nested = copy(v.nested, file);
    return out;
}
UAST::main copy(const Parser::FlatTypes::main& v, const std::string& file) {
    UAST::main out;
    out.value = copy(v.value, file);
    return out;
}
UAST::rule_value_one_capture copy(const Parser::FlatTypes::rule_value_one_capture& v, const std::string& file) {
    UAST::rule_value_one_capture out;
    out.v_cap = copy(v.v_cap, file);
    out.ast_cap = copy(v.ast_cap, file);
    out.fail_cap = copy(v.fail_cap, file);
    out.val = copy(v.val, file);
    out.alts = copy(v.alts, file);
    out.quantifier = copy(v.quantifier, file);
    out.registration = copy(v.registration, file);
    return out;
}
}
UAST::main UAST::fromParser(const Parser::Types::main& root, const std::string& file) {
    return copy(root, file);
}
