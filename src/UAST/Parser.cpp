module;
#include <output/Parser.h>
module UAST.Parser;
import std;
import UAST.Python;
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
    if (n.start() && n.startpos() != std::string::npos) {
        out.position.line = out.position.column = 1;
        for (auto p = n.start() - n.startpos(); p < n.start(); ++p) {
            if (*p == '\n') { ++out.position.line; out.position.column = 1; }
            else ++out.position.column;
        }
    }
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
    auto body = out.value.position;
    body.offset += 2; body.column += 2;
    out.python = UAST::parsePython(out.value.data().value, body, true);
    return out;
}
UAST::stmt copy(const Parser::FlatTypes::stmt& v, const std::string& file) {
    UAST::stmt out;
    out.value = copy(v.value, file);
    auto body = out.value.position;
    body.offset += 2; body.column += 2;
    out.python = UAST::parsePython(out.value.data().value, body, false);
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

namespace {
UAST::PythonNode snapshot(const UAST::__WS&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const UAST::advanced_rule_dep_decl_DEPENDS&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const UAST::AUTO&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const UAST::FAIL&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const UAST::SEMICOLON&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const UAST::COLON&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const UAST::EQUALS_SIGN&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const UAST::AMPERSAND&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const UAST::PERCENT_SIGN&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const UAST::rule_nested_rule_NUMBER_SIGN&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const UAST::rule_nested_rule&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const UAST::LEFT_CURLY_BRACKET&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const UAST::rule_value_shared_counter_registration_AUTO&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const UAST::rule_value&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const UAST::COMMERCIAL_AT&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const UAST::rule_value_QUANTIFIER&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const UAST::rule_value_NOSPACE&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const UAST::rule_value_ANY&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const UAST::template_params_LESS_THAN_SIGN&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const UAST::rule_value_STRING&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const UAST::grammar_modifier_AUTO&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const UAST::grammar_modifier_MOD&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const UAST::rule_value_SPACE&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const UAST::template_params_GREATER_THAN_SIGN&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const UAST::rule_value_alternative_VERTICAL_LINE&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const UAST::rule_value_alternative&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const UAST::grammar_modifier_RIGHT_SQUARE_BRACKET&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const UAST::rule_value_dyn_DOLLAR_SIGN&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const UAST::advanced_rule_regular_match_MATCH&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const UAST::COMMA&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const UAST::RIGHT_PARENTHESIS&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const UAST::LEFT_PARENTHESIS&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const UAST::RIGHT_CURLY_BRACKET&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const UAST::NUMBER&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const UAST::PY_RAW&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const UAST::ID&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const UAST::rule_value_CGROUP&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const UAST::rule_value_group&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const UAST::rule_value_mul_capture&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const UAST::grammar_modifier&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const UAST::expr&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const UAST::stmt&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const UAST::rule_value_shared_counter_registration&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const UAST::advanced_rule_regular_match_unpack&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const UAST::forward_declaration&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const UAST::param&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const UAST::rule_ast_abbr&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const UAST::rule_f_binding&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const UAST::rule_value_ast_capture&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const UAST::rule_value_var_capture&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const UAST::explicit_expr&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const UAST::rule_ast_full_part&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const UAST::rule_ast_single_value&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const UAST::rule_value_counter_bounded&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const UAST::rule_value_dyn_dyn_expr&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const UAST::advanced_rule_regular_match&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const UAST::advanced_rule_dep_decl&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const UAST::template_params&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const UAST::params&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const UAST::rule_ast_full&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const UAST::rule_value_counter&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const UAST::rule_value_dyn&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const UAST::advanced_rule&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const UAST::name&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const UAST::rule_ast&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const UAST::grammar&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const UAST::advanced_rule_fail_call&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const UAST::fail_block&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const UAST::rule_value_fail_capture&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const UAST::rule_value_pattern&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const UAST::rule&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const UAST::main&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const UAST::rule_value_one_capture&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(std::monostate, const UAST::SourcePosition& base) { return {"absent", {}, {}, base, true, {}}; }
UAST::PythonNode snapshot(const std::string& v, const UAST::SourcePosition& base) { return {"string", {}, v, base, false, {}}; }
UAST::PythonNode snapshot(char v, const UAST::SourcePosition& base) { return {"char", {}, std::string(1, v), base, false, {}}; }
UAST::PythonNode snapshot(const UAST::CaptureBinding& v, const UAST::SourcePosition& base) {
    return {"CaptureBinding", {}, {}, base, false, {
        {"string", "name", v.name, base, false, {}},
        {"bool", "optional", v.optional ? "true" : "false", base, false, {}},
        {"bool", "list", v.list ? "true" : "false", base, false, {}}
    }};
}
template<class T> UAST::PythonNode snapshot(const std::shared_ptr<T>& p, const UAST::SourcePosition& base) {
    return p ? snapshot(*p, base) : UAST::PythonNode{"pointer", {}, {}, base, true, {}};
}
template<class T> UAST::PythonNode snapshot(const UAST::Node<T>& n, const UAST::SourcePosition&) {
    if (n.empty()) return {"node", {}, {}, n.position, true, {}};
    auto out = snapshot(n.data(), n.position);
    out.position = n.position;
    return out;
}
template<class... T> UAST::PythonNode snapshot(const std::variant<T...>& v, const UAST::SourcePosition& base) {
    return {"variant", {}, std::to_string(v.index()), base, false, {std::visit([&](const auto& n) { return snapshot(n, base); }, v)}};
}
template<class T> UAST::PythonNode snapshot(const std::vector<T>& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"sequence", {}, {}, base, false, {}};
    for (const auto& n : v) out.children.push_back(snapshot(n, base));
    return out;
}
UAST::PythonNode snapshot(const UAST::__WS& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"__WS", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const UAST::advanced_rule_dep_decl_DEPENDS& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"advanced_rule_dep_decl_DEPENDS", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const UAST::AUTO& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"AUTO", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const UAST::FAIL& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"FAIL", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const UAST::SEMICOLON& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"SEMICOLON", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const UAST::COLON& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"COLON", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const UAST::EQUALS_SIGN& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"EQUALS_SIGN", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const UAST::AMPERSAND& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"AMPERSAND", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const UAST::PERCENT_SIGN& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"PERCENT_SIGN", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const UAST::rule_nested_rule_NUMBER_SIGN& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"rule_nested_rule_NUMBER_SIGN", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const UAST::rule_nested_rule& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"rule_nested_rule", {}, {}, base, false, {}};
    { auto child = snapshot(v.value, base); child.field = "value"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const UAST::LEFT_CURLY_BRACKET& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"LEFT_CURLY_BRACKET", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const UAST::rule_value_shared_counter_registration_AUTO& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"rule_value_shared_counter_registration_AUTO", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const UAST::rule_value& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"rule_value", {}, {}, base, false, {}};
    { auto child = snapshot(v.value, base); child.field = "value"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const UAST::COMMERCIAL_AT& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"COMMERCIAL_AT", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const UAST::rule_value_QUANTIFIER& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"rule_value_QUANTIFIER", {}, {}, base, false, {}};
    { auto child = snapshot(v.value, base); child.field = "value"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const UAST::rule_value_NOSPACE& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"rule_value_NOSPACE", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const UAST::rule_value_ANY& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"rule_value_ANY", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const UAST::template_params_LESS_THAN_SIGN& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"template_params_LESS_THAN_SIGN", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const UAST::rule_value_STRING& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"rule_value_STRING", {}, {}, base, false, {}};
    { auto child = snapshot(v.value, base); child.field = "value"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const UAST::grammar_modifier_AUTO& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"grammar_modifier_AUTO", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const UAST::grammar_modifier_MOD& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"grammar_modifier_MOD", {}, {}, base, false, {}};
    { auto child = snapshot(v.value, base); child.field = "value"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const UAST::rule_value_SPACE& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"rule_value_SPACE", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const UAST::template_params_GREATER_THAN_SIGN& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"template_params_GREATER_THAN_SIGN", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const UAST::rule_value_alternative_VERTICAL_LINE& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"rule_value_alternative_VERTICAL_LINE", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const UAST::rule_value_alternative& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"rule_value_alternative", {}, {}, base, false, {}};
    { auto child = snapshot(v.value, base); child.field = "value"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const UAST::grammar_modifier_RIGHT_SQUARE_BRACKET& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"grammar_modifier_RIGHT_SQUARE_BRACKET", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const UAST::rule_value_dyn_DOLLAR_SIGN& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"rule_value_dyn_DOLLAR_SIGN", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const UAST::advanced_rule_regular_match_MATCH& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"advanced_rule_regular_match_MATCH", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const UAST::COMMA& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"COMMA", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const UAST::RIGHT_PARENTHESIS& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"RIGHT_PARENTHESIS", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const UAST::LEFT_PARENTHESIS& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"LEFT_PARENTHESIS", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const UAST::RIGHT_CURLY_BRACKET& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"RIGHT_CURLY_BRACKET", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const UAST::NUMBER& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"NUMBER", {}, {}, base, false, {}};
    { auto child = snapshot(v.full, base); child.field = "full"; out.children.push_back(std::move(child)); }
    { auto child = snapshot(v.floating, base); child.field = "floating"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const UAST::PY_RAW& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"PY_RAW", {}, {}, base, false, {}};
    { auto child = snapshot(v.value, base); child.field = "value"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const UAST::ID& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"ID", {}, {}, base, false, {}};
    { auto child = snapshot(v.value, base); child.field = "value"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const UAST::rule_value_CGROUP& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"rule_value_CGROUP", {}, {}, base, false, {}};
    { auto child = snapshot(v.negative, base); child.field = "negative"; out.children.push_back(std::move(child)); }
    { auto child = snapshot(v.v, base); child.field = "v"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const UAST::rule_value_group& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"rule_value_group", {}, {}, base, false, {}};
    { auto child = snapshot(v.value, base); child.field = "value"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const UAST::rule_value_mul_capture& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"rule_value_mul_capture", {}, {}, base, false, {}};
    { auto child = snapshot(v.type, base); child.field = "type"; out.children.push_back(std::move(child)); }
    { auto child = snapshot(v.cap, base); child.field = "cap"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const UAST::grammar_modifier& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"grammar_modifier", {}, {}, base, false, {}};
    { auto child = snapshot(v.value, base); child.field = "value"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const UAST::expr& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"expr", {}, {}, base, false, {}};
    { auto child = snapshot(v.value, base); child.field = "value"; out.children.push_back(std::move(child)); }
    { auto child = v.python; child.field = "python"; out.children.push_back(std::move(child)); }
    { auto child = snapshot(v.bindings, base); child.field = "bindings"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const UAST::stmt& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"stmt", {}, {}, base, false, {}};
    { auto child = snapshot(v.value, base); child.field = "value"; out.children.push_back(std::move(child)); }
    { auto child = v.python; child.field = "python"; out.children.push_back(std::move(child)); }
    { auto child = snapshot(v.bindings, base); child.field = "bindings"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const UAST::rule_value_shared_counter_registration& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"rule_value_shared_counter_registration", {}, {}, base, false, {}};
    { auto child = snapshot(v.value, base); child.field = "value"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const UAST::advanced_rule_regular_match_unpack& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"advanced_rule_regular_match_unpack", {}, {}, base, false, {}};
    { auto child = snapshot(v.value, base); child.field = "value"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const UAST::forward_declaration& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"forward_declaration", {}, {}, base, false, {}};
    { auto child = snapshot(v.value, base); child.field = "value"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const UAST::param& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"param", {}, {}, base, false, {}};
    { auto child = snapshot(v.first_p, base); child.field = "first_p"; out.children.push_back(std::move(child)); }
    { auto child = snapshot(v.following_p, base); child.field = "following_p"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const UAST::rule_ast_abbr& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"rule_ast_abbr", {}, {}, base, false, {}};
    { auto child = snapshot(v.f, base); child.field = "f"; out.children.push_back(std::move(child)); }
    { auto child = snapshot(v.seq, base); child.field = "seq"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const UAST::rule_f_binding& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"rule_f_binding", {}, {}, base, false, {}};
    { auto child = snapshot(v.f, base); child.field = "f"; out.children.push_back(std::move(child)); }
    { auto child = snapshot(v.seq, base); child.field = "seq"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const UAST::rule_value_ast_capture& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"rule_value_ast_capture", {}, {}, base, false, {}};
    { auto child = snapshot(v.value, base); child.field = "value"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const UAST::rule_value_var_capture& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"rule_value_var_capture", {}, {}, base, false, {}};
    { auto child = snapshot(v.value, base); child.field = "value"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const UAST::explicit_expr& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"explicit_expr", {}, {}, base, false, {}};
    { auto child = snapshot(v.value, base); child.field = "value"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const UAST::rule_ast_full_part& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"rule_ast_full_part", {}, {}, base, false, {}};
    { auto child = snapshot(v.key, base); child.field = "key"; out.children.push_back(std::move(child)); }
    { auto child = snapshot(v.e, base); child.field = "e"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const UAST::rule_ast_single_value& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"rule_ast_single_value", {}, {}, base, false, {}};
    { auto child = snapshot(v.value, base); child.field = "value"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const UAST::rule_value_counter_bounded& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"rule_value_counter_bounded", {}, {}, base, false, {}};
    { auto child = snapshot(v.value, base); child.field = "value"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const UAST::rule_value_dyn_dyn_expr& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"rule_value_dyn_dyn_expr", {}, {}, base, false, {}};
    { auto child = snapshot(v.value, base); child.field = "value"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const UAST::advanced_rule_regular_match& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"advanced_rule_regular_match", {}, {}, base, false, {}};
    { auto child = snapshot(v.patterns, base); child.field = "patterns"; out.children.push_back(std::move(child)); }
    { auto child = snapshot(v.assign_names, base); child.field = "assign_names"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const UAST::advanced_rule_dep_decl& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"advanced_rule_dep_decl", {}, {}, base, false, {}};
    { auto child = snapshot(v.value, base); child.field = "value"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const UAST::template_params& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"template_params", {}, {}, base, false, {}};
    { auto child = snapshot(v.value, base); child.field = "value"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const UAST::params& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"params", {}, {}, base, false, {}};
    { auto child = snapshot(v.value, base); child.field = "value"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const UAST::rule_ast_full& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"rule_ast_full", {}, {}, base, false, {}};
    { auto child = snapshot(v.value, base); child.field = "value"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const UAST::rule_value_counter& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"rule_value_counter", {}, {}, base, false, {}};
    { auto child = snapshot(v.quantifier, base); child.field = "quantifier"; out.children.push_back(std::move(child)); }
    { auto child = snapshot(v.repetitions, base); child.field = "repetitions"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const UAST::rule_value_dyn& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"rule_value_dyn", {}, {}, base, false, {}};
    { auto child = snapshot(v.value, base); child.field = "value"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const UAST::advanced_rule& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"advanced_rule", {}, {}, base, false, {}};
    { auto child = snapshot(v.dep, base); child.field = "dep"; out.children.push_back(std::move(child)); }
    { auto child = snapshot(v.body, base); child.field = "body"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const UAST::name& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"name", {}, {}, base, false, {}};
    { auto child = snapshot(v.primary, base); child.field = "primary"; out.children.push_back(std::move(child)); }
    { auto child = snapshot(v.nested, base); child.field = "nested"; out.children.push_back(std::move(child)); }
    { auto child = snapshot(v.temp_params, base); child.field = "temp_params"; out.children.push_back(std::move(child)); }
    { auto child = snapshot(v.param, base); child.field = "param"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const UAST::rule_ast& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"rule_ast", {}, {}, base, false, {}};
    { auto child = snapshot(v.value, base); child.field = "value"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const UAST::grammar& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"grammar", {}, {}, base, false, {}};
    { auto child = snapshot(v.mod, base); child.field = "mod"; out.children.push_back(std::move(child)); }
    { auto child = snapshot(v.name, base); child.field = "name"; out.children.push_back(std::move(child)); }
    { auto child = snapshot(v.entry, base); child.field = "entry"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const UAST::advanced_rule_fail_call& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"advanced_rule_fail_call", {}, {}, base, false, {}};
    { auto child = snapshot(v.value, base); child.field = "value"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const UAST::fail_block& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"fail_block", {}, {}, base, false, {}};
    { auto child = snapshot(v.name, base); child.field = "name"; out.children.push_back(std::move(child)); }
    { auto child = snapshot(v.val, base); child.field = "val"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const UAST::rule_value_fail_capture& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"rule_value_fail_capture", {}, {}, base, false, {}};
    { auto child = snapshot(v.value, base); child.field = "value"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const UAST::rule_value_pattern& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"rule_value_pattern", {}, {}, base, false, {}};
    { auto child = snapshot(v.value, base); child.field = "value"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const UAST::rule& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"rule", {}, {}, base, false, {}};
    { auto child = snapshot(v.v, base); child.field = "v"; out.children.push_back(std::move(child)); }
    { auto child = snapshot(v.ast_pointer, base); child.field = "ast_pointer"; out.children.push_back(std::move(child)); }
    { auto child = snapshot(v.fail_pointer, base); child.field = "fail_pointer"; out.children.push_back(std::move(child)); }
    { auto child = snapshot(v.nested, base); child.field = "nested"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const UAST::main& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"main", {}, {}, base, false, {}};
    { auto child = snapshot(v.value, base); child.field = "value"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const UAST::rule_value_one_capture& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"rule_value_one_capture", {}, {}, base, false, {}};
    { auto child = snapshot(v.v_cap, base); child.field = "v_cap"; out.children.push_back(std::move(child)); }
    { auto child = snapshot(v.ast_cap, base); child.field = "ast_cap"; out.children.push_back(std::move(child)); }
    { auto child = snapshot(v.fail_cap, base); child.field = "fail_cap"; out.children.push_back(std::move(child)); }
    { auto child = snapshot(v.val, base); child.field = "val"; out.children.push_back(std::move(child)); }
    { auto child = snapshot(v.alts, base); child.field = "alts"; out.children.push_back(std::move(child)); }
    { auto child = snapshot(v.quantifier, base); child.field = "quantifier"; out.children.push_back(std::move(child)); }
    { auto child = snapshot(v.registration, base); child.field = "registration"; out.children.push_back(std::move(child)); }
    return out;
}
}
UAST::PythonNode UAST::describe(const UAST::advanced_rule& value, const UAST::SourcePosition& position) { return snapshot(value, position); }
