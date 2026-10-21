#include "Parser.h"

#include <ispastdlib.hpp>

auto Parser::TokensToString(std::size_t id) -> const char* {
	switch (id) {
		case Tokens::__WS::id: {
			return TokensStr::__WS::id;
			break;
		}
		case Tokens::advanced_rule::dep_decl::DEPENDS::id: {
			return TokensStr::advanced_rule::dep_decl::DEPENDS::id;
			break;
		}
		case Tokens::AUTO::id: {
			return TokensStr::AUTO::id;
			break;
		}
		case Tokens::FAIL::id: {
			return TokensStr::FAIL::id;
			break;
		}
		case Tokens::SEMICOLON::id: {
			return TokensStr::SEMICOLON::id;
			break;
		}
		case Tokens::COLON::id: {
			return TokensStr::COLON::id;
			break;
		}
		case Tokens::EQUALS_SIGN::id: {
			return TokensStr::EQUALS_SIGN::id;
			break;
		}
		case Tokens::AMPERSAND::id: {
			return TokensStr::AMPERSAND::id;
			break;
		}
		case Tokens::PERCENT_SIGN::id: {
			return TokensStr::PERCENT_SIGN::id;
			break;
		}
		case Tokens::rule::nested_rule::NUMBER_SIGN::id: {
			return TokensStr::rule::nested_rule::NUMBER_SIGN::id;
			break;
		}
		case Tokens::LEFT_CURLY_BRACKET::id: {
			return TokensStr::LEFT_CURLY_BRACKET::id;
			break;
		}
		case Tokens::rule::value::shared_counter_registration::AUTO::id: {
			return TokensStr::rule::value::shared_counter_registration::AUTO::id;
			break;
		}
		case Tokens::COMMERCIAL_AT::id: {
			return TokensStr::COMMERCIAL_AT::id;
			break;
		}
		case Tokens::rule::value::QUANTIFIER::id: {
			return TokensStr::rule::value::QUANTIFIER::id;
			break;
		}
		case Tokens::rule::value::NOSPACE::id: {
			return TokensStr::rule::value::NOSPACE::id;
			break;
		}
		case Tokens::rule::value::ANY::id: {
			return TokensStr::rule::value::ANY::id;
			break;
		}
		case Tokens::template_params::LESS_THAN_SIGN::id: {
			return TokensStr::template_params::LESS_THAN_SIGN::id;
			break;
		}
		case Tokens::rule::value::STRING::id: {
			return TokensStr::rule::value::STRING::id;
			break;
		}
		case Tokens::grammar::modifier::AUTO::id: {
			return TokensStr::grammar::modifier::AUTO::id;
			break;
		}
		case Tokens::grammar::modifier::MOD::id: {
			return TokensStr::grammar::modifier::MOD::id;
			break;
		}
		case Tokens::rule::value::SPACE::id: {
			return TokensStr::rule::value::SPACE::id;
			break;
		}
		case Tokens::rule::value::alternative::VERTICAL_LINE::id: {
			return TokensStr::rule::value::alternative::VERTICAL_LINE::id;
			break;
		}
		case Tokens::grammar::modifier::RIGHT_SQUARE_BRACKET::id: {
			return TokensStr::grammar::modifier::RIGHT_SQUARE_BRACKET::id;
			break;
		}
		case Tokens::rule::value::dyn::DOLLAR_SIGN::id: {
			return TokensStr::rule::value::dyn::DOLLAR_SIGN::id;
			break;
		}
		case Tokens::advanced_rule::regular_match::MATCH::id: {
			return TokensStr::advanced_rule::regular_match::MATCH::id;
			break;
		}
		case Tokens::COMMA::id: {
			return TokensStr::COMMA::id;
			break;
		}
		case Tokens::RIGHT_PARENTHESIS::id: {
			return TokensStr::RIGHT_PARENTHESIS::id;
			break;
		}
		case Tokens::LEFT_PARENTHESIS::id: {
			return TokensStr::LEFT_PARENTHESIS::id;
			break;
		}
		case Tokens::RIGHT_CURLY_BRACKET::id: {
			return TokensStr::RIGHT_CURLY_BRACKET::id;
			break;
		}
		case Tokens::NUMBER::id: {
			return TokensStr::NUMBER::id;
			break;
		}
		case Tokens::GREATER_THAN_SIGN::id: {
			return TokensStr::GREATER_THAN_SIGN::id;
			break;
		}
		case Tokens::PY_RAW::id: {
			return TokensStr::PY_RAW::id;
			break;
		}
		case Tokens::ID::id: {
			return TokensStr::ID::id;
			break;
		}
		case Tokens::rule::value::CGROUP::id: {
			return TokensStr::rule::value::CGROUP::id;
			break;
		}
	}
	throw "Invalid Tokens ID";
}
auto Parser::RulesToString(std::size_t id) -> const char* {
	switch (id) {
		case Rules::rule::nested_rule::id: {
			return RulesStr::rule::nested_rule::id;
			break;
		}
		case Rules::rule::value::counter::id: {
			return RulesStr::rule::value::counter::id;
			break;
		}
		case Rules::rule::value::dyn::dyn_expr::id: {
			return RulesStr::rule::value::dyn::dyn_expr::id;
			break;
		}
		case Rules::rule::value::dyn::id: {
			return RulesStr::rule::value::dyn::id;
			break;
		}
		case Rules::rule::value::mul_capture::id: {
			return RulesStr::rule::value::mul_capture::id;
			break;
		}
		case Rules::rule::ast::id: {
			return RulesStr::rule::ast::id;
			break;
		}
		case Rules::rule::value::ast_capture::id: {
			return RulesStr::rule::value::ast_capture::id;
			break;
		}
		case Rules::rule::f_binding::id: {
			return RulesStr::rule::f_binding::id;
			break;
		}
		case Rules::rule::value::group::id: {
			return RulesStr::rule::value::group::id;
			break;
		}
		case Rules::rule::value::fail_capture::id: {
			return RulesStr::rule::value::fail_capture::id;
			break;
		}
		case Rules::rule::ast::full::part::id: {
			return RulesStr::rule::ast::full::part::id;
			break;
		}
		case Rules::expr::id: {
			return RulesStr::expr::id;
			break;
		}
		case Rules::rule::value::one_capture::id: {
			return RulesStr::rule::value::one_capture::id;
			break;
		}
		case Rules::rule::id: {
			return RulesStr::rule::id;
			break;
		}
		case Rules::grammar::modifier::id: {
			return RulesStr::grammar::modifier::id;
			break;
		}
		case Rules::grammar::id: {
			return RulesStr::grammar::id;
			break;
		}
		case Rules::rule::value::id: {
			return RulesStr::rule::value::id;
			break;
		}
		case Rules::rule::value::counter::bounded::id: {
			return RulesStr::rule::value::counter::bounded::id;
			break;
		}
		case Rules::param::id: {
			return RulesStr::param::id;
			break;
		}
		case Rules::rule::value::pattern::id: {
			return RulesStr::rule::value::pattern::id;
			break;
		}
		case Rules::template_params::id: {
			return RulesStr::template_params::id;
			break;
		}
		case Rules::fail_block::id: {
			return RulesStr::fail_block::id;
			break;
		}
		case Rules::rule::ast::abbr::id: {
			return RulesStr::rule::ast::abbr::id;
			break;
		}
		case Rules::params::id: {
			return RulesStr::params::id;
			break;
		}
		case Rules::rule::value::alternative::id: {
			return RulesStr::rule::value::alternative::id;
			break;
		}
		case Rules::rule::ast::full::id: {
			return RulesStr::rule::ast::full::id;
			break;
		}
		case Rules::forward_declaration::id: {
			return RulesStr::forward_declaration::id;
			break;
		}
		case Rules::name::id: {
			return RulesStr::name::id;
			break;
		}
		case Rules::stmt::id: {
			return RulesStr::stmt::id;
			break;
		}
		case Rules::advanced_rule::fail_call::id: {
			return RulesStr::advanced_rule::fail_call::id;
			break;
		}
		case Rules::rule::ast::single_value::id: {
			return RulesStr::rule::ast::single_value::id;
			break;
		}
		case Rules::advanced_rule::dep_decl::id: {
			return RulesStr::advanced_rule::dep_decl::id;
			break;
		}
		case Rules::rule::value::shared_counter_registration::id: {
			return RulesStr::rule::value::shared_counter_registration::id;
			break;
		}
		case Rules::explicit_expr::id: {
			return RulesStr::explicit_expr::id;
			break;
		}
		case Rules::rule::value::var_capture::id: {
			return RulesStr::rule::value::var_capture::id;
			break;
		}
		case Rules::main::id: {
			return RulesStr::main::id;
			break;
		}
		case Rules::advanced_rule::id: {
			return RulesStr::advanced_rule::id;
			break;
		}
		case Rules::advanced_rule::regular_match::unpack::id: {
			return RulesStr::advanced_rule::regular_match::unpack::id;
			break;
		}
		case Rules::advanced_rule::regular_match::id: {
			return RulesStr::advanced_rule::regular_match::id;
			break;
		}
	}
	throw "Invalid Rules ID";
}
auto Parser::FlatTypes::__WS::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("__WS", true);
}
auto Parser::FlatTypes::__WS::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::__WS::to_string() const -> std::string {
	return ::ISPA_STD::concat("__WS {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, __WS value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::advanced_rule_dep_decl_DEPENDS::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("advanced_rule_dep_decl_DEPENDS", true);
}
auto Parser::FlatTypes::advanced_rule_dep_decl_DEPENDS::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::advanced_rule_dep_decl_DEPENDS::to_string() const -> std::string {
	return ::ISPA_STD::concat("advanced_rule_dep_decl_DEPENDS {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, advanced_rule_dep_decl_DEPENDS value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::AUTO::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("AUTO", true);
}
auto Parser::FlatTypes::AUTO::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::AUTO::to_string() const -> std::string {
	return ::ISPA_STD::concat("AUTO {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, AUTO value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::FAIL::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("FAIL", true);
}
auto Parser::FlatTypes::FAIL::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::FAIL::to_string() const -> std::string {
	return ::ISPA_STD::concat("FAIL {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, FAIL value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::SEMICOLON::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("SEMICOLON", true);
}
auto Parser::FlatTypes::SEMICOLON::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::SEMICOLON::to_string() const -> std::string {
	return ::ISPA_STD::concat("SEMICOLON {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, SEMICOLON value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::COLON::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("COLON", true);
}
auto Parser::FlatTypes::COLON::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::COLON::to_string() const -> std::string {
	return ::ISPA_STD::concat("COLON {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, COLON value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::EQUALS_SIGN::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("EQUALS_SIGN", true);
}
auto Parser::FlatTypes::EQUALS_SIGN::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::EQUALS_SIGN::to_string() const -> std::string {
	return ::ISPA_STD::concat("EQUALS_SIGN {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, EQUALS_SIGN value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::AMPERSAND::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("AMPERSAND", true);
}
auto Parser::FlatTypes::AMPERSAND::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::AMPERSAND::to_string() const -> std::string {
	return ::ISPA_STD::concat("AMPERSAND {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, AMPERSAND value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::PERCENT_SIGN::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("PERCENT_SIGN", true);
}
auto Parser::FlatTypes::PERCENT_SIGN::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::PERCENT_SIGN::to_string() const -> std::string {
	return ::ISPA_STD::concat("PERCENT_SIGN {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, PERCENT_SIGN value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::rule_nested_rule_NUMBER_SIGN::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("rule_nested_rule_NUMBER_SIGN", true);
}
auto Parser::FlatTypes::rule_nested_rule_NUMBER_SIGN::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::rule_nested_rule_NUMBER_SIGN::to_string() const -> std::string {
	return ::ISPA_STD::concat("rule_nested_rule_NUMBER_SIGN {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, rule_nested_rule_NUMBER_SIGN value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::rule_nested_rule::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("rule_nested_rule", false);
	printer.up(false);
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::rule_nested_rule::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::rule_nested_rule::to_string() const -> std::string {
	return ::ISPA_STD::concat("rule_nested_rule {", "value = ", value.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, rule_nested_rule value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::LEFT_CURLY_BRACKET::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("LEFT_CURLY_BRACKET", true);
}
auto Parser::FlatTypes::LEFT_CURLY_BRACKET::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::LEFT_CURLY_BRACKET::to_string() const -> std::string {
	return ::ISPA_STD::concat("LEFT_CURLY_BRACKET {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, LEFT_CURLY_BRACKET value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::rule_value_shared_counter_registration_AUTO::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("rule_value_shared_counter_registration_AUTO", true);
}
auto Parser::FlatTypes::rule_value_shared_counter_registration_AUTO::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::rule_value_shared_counter_registration_AUTO::to_string() const -> std::string {
	return ::ISPA_STD::concat("rule_value_shared_counter_registration_AUTO {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, rule_value_shared_counter_registration_AUTO value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::rule_value::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("rule_value", false);
	printer.up(false);
	printer.node_with_value("value", value, true);
	printer.down();
}
auto Parser::FlatTypes::rule_value::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::rule_value::to_string() const -> std::string {
	return ::ISPA_STD::concat("rule_value {", "value = ", value, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, rule_value value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::COMMERCIAL_AT::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("COMMERCIAL_AT", true);
}
auto Parser::FlatTypes::COMMERCIAL_AT::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::COMMERCIAL_AT::to_string() const -> std::string {
	return ::ISPA_STD::concat("COMMERCIAL_AT {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, COMMERCIAL_AT value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::rule_value_QUANTIFIER::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("rule_value_QUANTIFIER", false);
	printer.up(false);
	printer.node_with_value("value", value, true);
	printer.down();
}
auto Parser::FlatTypes::rule_value_QUANTIFIER::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::rule_value_QUANTIFIER::to_string() const -> std::string {
	return ::ISPA_STD::concat("rule_value_QUANTIFIER {", "value = ", value, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, rule_value_QUANTIFIER value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::rule_value_NOSPACE::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("rule_value_NOSPACE", true);
}
auto Parser::FlatTypes::rule_value_NOSPACE::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::rule_value_NOSPACE::to_string() const -> std::string {
	return ::ISPA_STD::concat("rule_value_NOSPACE {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, rule_value_NOSPACE value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::rule_value_ANY::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("rule_value_ANY", true);
}
auto Parser::FlatTypes::rule_value_ANY::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::rule_value_ANY::to_string() const -> std::string {
	return ::ISPA_STD::concat("rule_value_ANY {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, rule_value_ANY value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::template_params_LESS_THAN_SIGN::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("template_params_LESS_THAN_SIGN", true);
}
auto Parser::FlatTypes::template_params_LESS_THAN_SIGN::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::template_params_LESS_THAN_SIGN::to_string() const -> std::string {
	return ::ISPA_STD::concat("template_params_LESS_THAN_SIGN {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, template_params_LESS_THAN_SIGN value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::rule_value_STRING::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("rule_value_STRING", false);
	printer.up(false);
	printer.node_with_value("value", value, true);
	printer.down();
}
auto Parser::FlatTypes::rule_value_STRING::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::rule_value_STRING::to_string() const -> std::string {
	return ::ISPA_STD::concat("rule_value_STRING {", "value = ", value, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, rule_value_STRING value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::grammar_modifier_AUTO::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("grammar_modifier_AUTO", true);
}
auto Parser::FlatTypes::grammar_modifier_AUTO::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::grammar_modifier_AUTO::to_string() const -> std::string {
	return ::ISPA_STD::concat("grammar_modifier_AUTO {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, grammar_modifier_AUTO value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::grammar_modifier_MOD::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("grammar_modifier_MOD", false);
	printer.up(false);
	printer.node_with_value("value", value, true);
	printer.down();
}
auto Parser::FlatTypes::grammar_modifier_MOD::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::grammar_modifier_MOD::to_string() const -> std::string {
	return ::ISPA_STD::concat("grammar_modifier_MOD {", "value = ", value, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, grammar_modifier_MOD value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::rule_value_SPACE::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("rule_value_SPACE", true);
}
auto Parser::FlatTypes::rule_value_SPACE::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::rule_value_SPACE::to_string() const -> std::string {
	return ::ISPA_STD::concat("rule_value_SPACE {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, rule_value_SPACE value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::rule_value_alternative_VERTICAL_LINE::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("rule_value_alternative_VERTICAL_LINE", true);
}
auto Parser::FlatTypes::rule_value_alternative_VERTICAL_LINE::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::rule_value_alternative_VERTICAL_LINE::to_string() const -> std::string {
	return ::ISPA_STD::concat("rule_value_alternative_VERTICAL_LINE {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, rule_value_alternative_VERTICAL_LINE value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::rule_value_alternative::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("rule_value_alternative", false);
	printer.up(false);
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::rule_value_alternative::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::rule_value_alternative::to_string() const -> std::string {
	return ::ISPA_STD::concat("rule_value_alternative {", "value = ", value.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, rule_value_alternative value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::grammar_modifier_RIGHT_SQUARE_BRACKET::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("grammar_modifier_RIGHT_SQUARE_BRACKET", true);
}
auto Parser::FlatTypes::grammar_modifier_RIGHT_SQUARE_BRACKET::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::grammar_modifier_RIGHT_SQUARE_BRACKET::to_string() const -> std::string {
	return ::ISPA_STD::concat("grammar_modifier_RIGHT_SQUARE_BRACKET {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, grammar_modifier_RIGHT_SQUARE_BRACKET value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::rule_value_dyn_DOLLAR_SIGN::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("rule_value_dyn_DOLLAR_SIGN", true);
}
auto Parser::FlatTypes::rule_value_dyn_DOLLAR_SIGN::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::rule_value_dyn_DOLLAR_SIGN::to_string() const -> std::string {
	return ::ISPA_STD::concat("rule_value_dyn_DOLLAR_SIGN {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, rule_value_dyn_DOLLAR_SIGN value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::advanced_rule_regular_match_MATCH::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("advanced_rule_regular_match_MATCH", true);
}
auto Parser::FlatTypes::advanced_rule_regular_match_MATCH::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::advanced_rule_regular_match_MATCH::to_string() const -> std::string {
	return ::ISPA_STD::concat("advanced_rule_regular_match_MATCH {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, advanced_rule_regular_match_MATCH value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::COMMA::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("COMMA", true);
}
auto Parser::FlatTypes::COMMA::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::COMMA::to_string() const -> std::string {
	return ::ISPA_STD::concat("COMMA {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, COMMA value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::RIGHT_PARENTHESIS::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("RIGHT_PARENTHESIS", true);
}
auto Parser::FlatTypes::RIGHT_PARENTHESIS::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::RIGHT_PARENTHESIS::to_string() const -> std::string {
	return ::ISPA_STD::concat("RIGHT_PARENTHESIS {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, RIGHT_PARENTHESIS value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::LEFT_PARENTHESIS::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("LEFT_PARENTHESIS", true);
}
auto Parser::FlatTypes::LEFT_PARENTHESIS::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::LEFT_PARENTHESIS::to_string() const -> std::string {
	return ::ISPA_STD::concat("LEFT_PARENTHESIS {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, LEFT_PARENTHESIS value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::RIGHT_CURLY_BRACKET::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("RIGHT_CURLY_BRACKET", true);
}
auto Parser::FlatTypes::RIGHT_CURLY_BRACKET::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::RIGHT_CURLY_BRACKET::to_string() const -> std::string {
	return ::ISPA_STD::concat("RIGHT_CURLY_BRACKET {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, RIGHT_CURLY_BRACKET value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::NUMBER::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("NUMBER", false);
	printer.up(false);
	printer.node_with_value("full", full, false);
	printer.node_with_value("floating", floating, true);
	printer.down();
}
auto Parser::FlatTypes::NUMBER::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::NUMBER::to_string() const -> std::string {
	return ::ISPA_STD::concat("NUMBER {", "full = ", full, ", ", "floating = ", floating, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, NUMBER value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::GREATER_THAN_SIGN::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("GREATER_THAN_SIGN", true);
}
auto Parser::FlatTypes::GREATER_THAN_SIGN::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::GREATER_THAN_SIGN::to_string() const -> std::string {
	return ::ISPA_STD::concat("GREATER_THAN_SIGN {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, GREATER_THAN_SIGN value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::PY_RAW::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("PY_RAW", false);
	printer.up(false);
	printer.node_with_value("value", value, true);
	printer.down();
}
auto Parser::FlatTypes::PY_RAW::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::PY_RAW::to_string() const -> std::string {
	return ::ISPA_STD::concat("PY_RAW {", "value = ", value, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, PY_RAW value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::ID::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("ID", false);
	printer.up(false);
	printer.node_with_value("value", value, true);
	printer.down();
}
auto Parser::FlatTypes::ID::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::ID::to_string() const -> std::string {
	return ::ISPA_STD::concat("ID {", "value = ", value, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, ID value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::rule_value_CGROUP::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("rule_value_CGROUP", false);
	printer.up(false);
	printer.node_with_value("negative", negative, false);
	printer.node_with_value("v", v, true);
	printer.down();
}
auto Parser::FlatTypes::rule_value_CGROUP::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::rule_value_CGROUP::to_string() const -> std::string {
	return ::ISPA_STD::concat("rule_value_CGROUP {", "negative = ", negative, ", ", "v = ", v, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, rule_value_CGROUP value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::rule_value_group::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("rule_value_group", false);
	printer.up(false);
	printer.subtree("value", value, true);
	printer.down();
}
auto Parser::FlatTypes::rule_value_group::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::rule_value_group::to_string() const -> std::string {
	return ::ISPA_STD::concat("rule_value_group {", "value = ", value, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, rule_value_group value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::forward_declaration::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("forward_declaration", true);
}
auto Parser::FlatTypes::forward_declaration::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::forward_declaration::to_string() const -> std::string {
	return ::ISPA_STD::concat("forward_declaration {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, forward_declaration value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::rule_value_mul_capture::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("rule_value_mul_capture", false);
	printer.up(false);
	printer.node_with_value("type", type, false);
	printer.subtree("cap", cap, true);
	printer.down();
}
auto Parser::FlatTypes::rule_value_mul_capture::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::rule_value_mul_capture::to_string() const -> std::string {
	return ::ISPA_STD::concat("rule_value_mul_capture {", "type = ", type, ", ", "cap = ", cap, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, rule_value_mul_capture value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::grammar_modifier::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("grammar_modifier", false);
	printer.up(false);
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::grammar_modifier::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::grammar_modifier::to_string() const -> std::string {
	return ::ISPA_STD::concat("grammar_modifier {", "value = ", value.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, grammar_modifier value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::expr::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("expr", false);
	printer.up(false);
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::expr::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::expr::to_string() const -> std::string {
	return ::ISPA_STD::concat("expr {", "value = ", value.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, expr value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::stmt::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("stmt", false);
	printer.up(false);
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::stmt::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::stmt::to_string() const -> std::string {
	return ::ISPA_STD::concat("stmt {", "value = ", value.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, stmt value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::rule_value_shared_counter_registration::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("rule_value_shared_counter_registration", false);
	printer.up(false);
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::rule_value_shared_counter_registration::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::rule_value_shared_counter_registration::to_string() const -> std::string {
	return ::ISPA_STD::concat("rule_value_shared_counter_registration {", "value = ", value.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, rule_value_shared_counter_registration value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::rule_value_ast_capture::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("rule_value_ast_capture", false);
	printer.up(false);
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::rule_value_ast_capture::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::rule_value_ast_capture::to_string() const -> std::string {
	return ::ISPA_STD::concat("rule_value_ast_capture {", "value = ", value.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, rule_value_ast_capture value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::rule_f_binding::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("rule_f_binding", false);
	printer.up(false);
	printer.node("f", false);
	printer.up(true);
	f.print(printer);
	printer.down();
	printer.subtree("seq", seq, true);
	printer.down();
}
auto Parser::FlatTypes::rule_f_binding::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::rule_f_binding::to_string() const -> std::string {
	return ::ISPA_STD::concat("rule_f_binding {", "f = ", f.to_string(), ", ", "seq = ", seq, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, rule_f_binding value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::param::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("param", false);
	printer.up(false);
	printer.node("first_p", false);
	printer.up(true);
	first_p.print(printer);
	printer.down();
	printer.subtree("following_p", following_p, true);
	printer.down();
}
auto Parser::FlatTypes::param::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::param::to_string() const -> std::string {
	return ::ISPA_STD::concat("param {", "first_p = ", first_p.to_string(), ", ", "following_p = ", following_p, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, param value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::rule_ast_abbr::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("rule_ast_abbr", false);
	printer.up(false);
	printer.node("f", false);
	printer.up(true);
	f.print(printer);
	printer.down();
	printer.subtree("seq", seq, true);
	printer.down();
}
auto Parser::FlatTypes::rule_ast_abbr::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::rule_ast_abbr::to_string() const -> std::string {
	return ::ISPA_STD::concat("rule_ast_abbr {", "f = ", f.to_string(), ", ", "seq = ", seq, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, rule_ast_abbr value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::rule_value_var_capture::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("rule_value_var_capture", false);
	printer.up(false);
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::rule_value_var_capture::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::rule_value_var_capture::to_string() const -> std::string {
	return ::ISPA_STD::concat("rule_value_var_capture {", "value = ", value.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, rule_value_var_capture value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::advanced_rule_regular_match_unpack::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("advanced_rule_regular_match_unpack", false);
	printer.up(false);
	printer.subtree("value", value, true);
	printer.down();
}
auto Parser::FlatTypes::advanced_rule_regular_match_unpack::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::advanced_rule_regular_match_unpack::to_string() const -> std::string {
	return ::ISPA_STD::concat("advanced_rule_regular_match_unpack {", "value = ", value, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, advanced_rule_regular_match_unpack value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::advanced_rule_dep_decl::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("advanced_rule_dep_decl", false);
	printer.up(false);
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::advanced_rule_dep_decl::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::advanced_rule_dep_decl::to_string() const -> std::string {
	return ::ISPA_STD::concat("advanced_rule_dep_decl {", "value = ", value.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, advanced_rule_dep_decl value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::rule_value_dyn_dyn_expr::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("rule_value_dyn_dyn_expr", false);
	printer.up(false);
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::rule_value_dyn_dyn_expr::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::rule_value_dyn_dyn_expr::to_string() const -> std::string {
	return ::ISPA_STD::concat("rule_value_dyn_dyn_expr {", "value = ", value.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, rule_value_dyn_dyn_expr value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::rule_ast_full_part::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("rule_ast_full_part", false);
	printer.up(false);
	printer.node("key", false);
	printer.up(true);
	key.print(printer);
	printer.down();
	printer.node("e", true);
	printer.up(false);
	e.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::rule_ast_full_part::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::rule_ast_full_part::to_string() const -> std::string {
	return ::ISPA_STD::concat("rule_ast_full_part {", "key = ", key.to_string(), ", ", "e = ", e.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, rule_ast_full_part value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::rule_value_counter_bounded::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("rule_value_counter_bounded", false);
	printer.up(false);
	printer.node_with_value("value", value, true);
	printer.down();
}
auto Parser::FlatTypes::rule_value_counter_bounded::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::rule_value_counter_bounded::to_string() const -> std::string {
	return ::ISPA_STD::concat("rule_value_counter_bounded {", "value = ", value, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, rule_value_counter_bounded value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::rule_ast_single_value::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("rule_ast_single_value", false);
	printer.up(false);
	printer.node_with_value("value", value, true);
	printer.down();
}
auto Parser::FlatTypes::rule_ast_single_value::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::rule_ast_single_value::to_string() const -> std::string {
	return ::ISPA_STD::concat("rule_ast_single_value {", "value = ", value, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, rule_ast_single_value value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::explicit_expr::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("explicit_expr", false);
	printer.up(false);
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::explicit_expr::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::explicit_expr::to_string() const -> std::string {
	return ::ISPA_STD::concat("explicit_expr {", "value = ", value.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, explicit_expr value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::template_params::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("template_params", false);
	printer.up(false);
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::template_params::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::template_params::to_string() const -> std::string {
	return ::ISPA_STD::concat("template_params {", "value = ", value.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, template_params value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::params::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("params", false);
	printer.up(false);
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::params::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::params::to_string() const -> std::string {
	return ::ISPA_STD::concat("params {", "value = ", value.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, params value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::advanced_rule_regular_match::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("advanced_rule_regular_match", false);
	printer.up(false);
	printer.subtree("patterns", patterns, false);
	printer.node_with_value("assign_names", assign_names, true);
	printer.down();
}
auto Parser::FlatTypes::advanced_rule_regular_match::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::advanced_rule_regular_match::to_string() const -> std::string {
	return ::ISPA_STD::concat("advanced_rule_regular_match {", "patterns = ", patterns, ", ", "assign_names = ", assign_names, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, advanced_rule_regular_match value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::rule_value_dyn::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("rule_value_dyn", false);
	printer.up(false);
	printer.node_with_value("value", value, true);
	printer.down();
}
auto Parser::FlatTypes::rule_value_dyn::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::rule_value_dyn::to_string() const -> std::string {
	return ::ISPA_STD::concat("rule_value_dyn {", "value = ", value, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, rule_value_dyn value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::rule_ast_full::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("rule_ast_full", false);
	printer.up(false);
	printer.subtree("value", value, true);
	printer.down();
}
auto Parser::FlatTypes::rule_ast_full::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::rule_ast_full::to_string() const -> std::string {
	return ::ISPA_STD::concat("rule_ast_full {", "value = ", value, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, rule_ast_full value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::rule_value_counter::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("rule_value_counter", false);
	printer.up(false);
	printer.node("quantifier", false);
	printer.up(true);
	quantifier.print(printer);
	printer.down();
	printer.node("repetitions", true);
	printer.up(false);
	repetitions.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::rule_value_counter::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::rule_value_counter::to_string() const -> std::string {
	return ::ISPA_STD::concat("rule_value_counter {", "quantifier = ", quantifier.to_string(), ", ", "repetitions = ", repetitions.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, rule_value_counter value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::name::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("name", false);
	printer.up(false);
	printer.node("primary", false);
	printer.up(true);
	primary.print(printer);
	printer.down();
	printer.subtree("nested", nested, false);
	printer.node("temp_params", false);
	printer.up(true);
	temp_params.print(printer);
	printer.down();
	printer.node("param", true);
	printer.up(false);
	param.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::name::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::name::to_string() const -> std::string {
	return ::ISPA_STD::concat("name {", "primary = ", primary.to_string(), ", ", "nested = ", nested, ", ", "temp_params = ", temp_params.to_string(), ", ", "param = ", param.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, name value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::advanced_rule::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("advanced_rule", false);
	printer.up(false);
	printer.subtree("dep", dep, false);
	printer.node_with_value("body", body, true);
	printer.down();
}
auto Parser::FlatTypes::advanced_rule::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::advanced_rule::to_string() const -> std::string {
	return ::ISPA_STD::concat("advanced_rule {", "dep = ", dep, ", ", "body = ", body, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, advanced_rule value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::rule_ast::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("rule_ast", false);
	printer.up(false);
	printer.node_with_value("value", value, true);
	printer.down();
}
auto Parser::FlatTypes::rule_ast::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::rule_ast::to_string() const -> std::string {
	return ::ISPA_STD::concat("rule_ast {", "value = ", value, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, rule_ast value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::rule_value_fail_capture::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("rule_value_fail_capture", false);
	printer.up(false);
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::rule_value_fail_capture::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::rule_value_fail_capture::to_string() const -> std::string {
	return ::ISPA_STD::concat("rule_value_fail_capture {", "value = ", value.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, rule_value_fail_capture value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::rule_value_pattern::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("rule_value_pattern", false);
	printer.up(false);
	printer.node_with_value("value", value, true);
	printer.down();
}
auto Parser::FlatTypes::rule_value_pattern::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::rule_value_pattern::to_string() const -> std::string {
	return ::ISPA_STD::concat("rule_value_pattern {", "value = ", value, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, rule_value_pattern value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::fail_block::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("fail_block", false);
	printer.up(false);
	printer.node("name", false);
	printer.up(true);
	name.print(printer);
	printer.down();
	printer.node("val", true);
	printer.up(false);
	val.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::fail_block::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::fail_block::to_string() const -> std::string {
	return ::ISPA_STD::concat("fail_block {", "name = ", name.to_string(), ", ", "val = ", val.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, fail_block value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::advanced_rule_fail_call::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("advanced_rule_fail_call", false);
	printer.up(false);
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::advanced_rule_fail_call::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::advanced_rule_fail_call::to_string() const -> std::string {
	return ::ISPA_STD::concat("advanced_rule_fail_call {", "value = ", value.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, advanced_rule_fail_call value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::grammar::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("grammar", false);
	printer.up(false);
	printer.subtree("mod", mod, false);
	printer.node("name", false);
	printer.up(true);
	name.print(printer);
	printer.down();
	printer.node_with_value("entry", entry, true);
	printer.down();
}
auto Parser::FlatTypes::grammar::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::grammar::to_string() const -> std::string {
	return ::ISPA_STD::concat("grammar {", "mod = ", mod, ", ", "name = ", name.to_string(), ", ", "entry = ", entry, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, grammar value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::rule::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("rule", false);
	printer.up(false);
	printer.subtree("v", v, false);
	printer.node("ast_pointer", false);
	printer.up(true);
	ast_pointer.print(printer);
	printer.down();
	printer.node("fail_pointer", false);
	printer.up(true);
	fail_pointer.print(printer);
	printer.down();
	printer.subtree("nested", nested, true);
	printer.down();
}
auto Parser::FlatTypes::rule::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::rule::to_string() const -> std::string {
	return ::ISPA_STD::concat("rule {", "v = ", v, ", ", "ast_pointer = ", ast_pointer.to_string(), ", ", "fail_pointer = ", fail_pointer.to_string(), ", ", "nested = ", nested, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, rule value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::rule_value_one_capture::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("rule_value_one_capture", false);
	printer.up(false);
	printer.node("v_cap", false);
	printer.up(true);
	v_cap.print(printer);
	printer.down();
	printer.node("ast_cap", false);
	printer.up(true);
	ast_cap.print(printer);
	printer.down();
	printer.node("fail_cap", false);
	printer.up(true);
	fail_cap.print(printer);
	printer.down();
	printer.node("val", false);
	printer.up(true);
	val.print(printer);
	printer.down();
	printer.subtree("alts", alts, false);
	printer.node("quantifier", false);
	printer.up(true);
	quantifier.print(printer);
	printer.down();
	printer.node("registration", true);
	printer.up(false);
	registration.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::rule_value_one_capture::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::rule_value_one_capture::to_string() const -> std::string {
	return ::ISPA_STD::concat("rule_value_one_capture {", "v_cap = ", v_cap.to_string(), ", ", "ast_cap = ", ast_cap.to_string(), ", ", "fail_cap = ", fail_cap.to_string(), ", ", "val = ", val.to_string(), ", ", "alts = ", alts, ", ", "quantifier = ", quantifier.to_string(), ", ", "registration = ", registration.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, rule_value_one_capture value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::main::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("main", false);
	printer.up(false);
	printer.node_with_value("value", value, true);
	printer.down();
}
auto Parser::FlatTypes::main::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::main::to_string() const -> std::string {
	return ::ISPA_STD::concat("main {", "value = ", value, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, main value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::Lexer::semantic_action_exec(long long state, const ::ISPA_STD::DFA::API::Captures& captures, long long start_pos, const char* start, long long length, long long line) -> std::pair<long long, Token> {
	switch (state) {
		case 0: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::__WS::id, Types::__WS{}));
			break;
		}
		case 1: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::rule::nested_rule::NUMBER_SIGN::id, Types::rule::nested_rule::NUMBER_SIGN{}));
			break;
		}
		case 2: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::rule::value::dyn::DOLLAR_SIGN::id, Types::rule::value::dyn::DOLLAR_SIGN{}));
			break;
		}
		case 3: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::PERCENT_SIGN::id, Types::PERCENT_SIGN{}));
			break;
		}
		case 4: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::AMPERSAND::id, Types::AMPERSAND{}));
			break;
		}
		case 5: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::LEFT_PARENTHESIS::id, Types::LEFT_PARENTHESIS{}));
			break;
		}
		case 6: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::RIGHT_PARENTHESIS::id, Types::RIGHT_PARENTHESIS{}));
			break;
		}
		case 7: {
			char value;
			if (captures.is_set(4)) {
				value = captures.character(4);
			} else {
				if (captures.is_set(6)) {
					value = captures.character(6);
				} else {
					if (captures.is_set(5)) {
						value = captures.character(5);
					}
				}
			}
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::rule::value::QUANTIFIER::id, Types::rule::value::QUANTIFIER{value}));
			break;
		}
		case 8: {
			char value;
			if (captures.is_set(4)) {
				value = captures.character(4);
			} else {
				if (captures.is_set(6)) {
					value = captures.character(6);
				} else {
					if (captures.is_set(5)) {
						value = captures.character(5);
					}
				}
			}
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::rule::value::QUANTIFIER::id, Types::rule::value::QUANTIFIER{value}));
			break;
		}
		case 9: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::COMMA::id, Types::COMMA{}));
			break;
		}
		case 10: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::rule::value::ANY::id, Types::rule::value::ANY{}));
			break;
		}
		case 11: {
			std::string floating = captures.text(8);
			std::string full = captures.text(7);
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::NUMBER::id, Types::NUMBER{full, floating}));
			break;
		}
		case 12: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::COLON::id, Types::COLON{}));
			break;
		}
		case 13: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::SEMICOLON::id, Types::SEMICOLON{}));
			break;
		}
		case 14: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::template_params::LESS_THAN_SIGN::id, Types::template_params::LESS_THAN_SIGN{}));
			break;
		}
		case 15: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::EQUALS_SIGN::id, Types::EQUALS_SIGN{}));
			break;
		}
		case 16: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::GREATER_THAN_SIGN::id, Types::GREATER_THAN_SIGN{}));
			break;
		}
		case 17: {
			char value;
			if (captures.is_set(4)) {
				value = captures.character(4);
			} else {
				if (captures.is_set(6)) {
					value = captures.character(6);
				} else {
					if (captures.is_set(5)) {
						value = captures.character(5);
					}
				}
			}
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::rule::value::QUANTIFIER::id, Types::rule::value::QUANTIFIER{value}));
			break;
		}
		case 18: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::COMMERCIAL_AT::id, Types::COMMERCIAL_AT{}));
			break;
		}
		case 19: {
			std::string value = captures.text(0);
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::ID::id, Types::ID{value}));
			break;
		}
		case 20: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::grammar::modifier::RIGHT_SQUARE_BRACKET::id, Types::grammar::modifier::RIGHT_SQUARE_BRACKET{}));
			break;
		}
		case 21: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::LEFT_CURLY_BRACKET::id, Types::LEFT_CURLY_BRACKET{}));
			break;
		}
		case 22: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::rule::value::alternative::VERTICAL_LINE::id, Types::rule::value::alternative::VERTICAL_LINE{}));
			break;
		}
		case 23: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::RIGHT_CURLY_BRACKET::id, Types::RIGHT_CURLY_BRACKET{}));
			break;
		}
		case 24: {
			std::string value = captures.text(12);
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::rule::value::STRING::id, Types::rule::value::STRING{value}));
			break;
		}
		case 25: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::grammar::modifier::AUTO::id, Types::grammar::modifier::AUTO{}));
			break;
		}
		case 26: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::AUTO::id, Types::AUTO{}));
			break;
		}
		case 27: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::rule::value::shared_counter_registration::AUTO::id, Types::rule::value::shared_counter_registration::AUTO{}));
			break;
		}
		case 28: {
			std::string value = captures.text(0);
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::ID::id, Types::ID{value}));
			break;
		}
		case 29: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::rule::value::SPACE::id, Types::rule::value::SPACE{}));
			break;
		}
		case 30: {
			std::string floating = captures.text(8);
			std::string full = captures.text(7);
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::NUMBER::id, Types::NUMBER{full, floating}));
			break;
		}
		case 31: {
			std::string v = captures.text(3);
			char negative = captures.character(2);
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::rule::value::CGROUP::id, Types::rule::value::CGROUP{negative, v}));
			break;
		}
		case 32: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::rule::value::NOSPACE::id, Types::rule::value::NOSPACE{}));
			break;
		}
		case 33: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::FAIL::id, Types::FAIL{}));
			break;
		}
		case 34: {
			std::string value;
			if (captures.is_set(9)) {
				value = captures.text(9);
			} else {
				if (captures.is_set(11)) {
					value = captures.text(11);
				} else {
					if (captures.is_set(10)) {
						value = captures.text(10);
					}
				}
			}
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::grammar::modifier::MOD::id, Types::grammar::modifier::MOD{value}));
			break;
		}
		case 35: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::advanced_rule::regular_match::MATCH::id, Types::advanced_rule::regular_match::MATCH{}));
			break;
		}
		case 36: {
			std::string value = captures.text(1);
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::PY_RAW::id, Types::PY_RAW{value}));
			break;
		}
		case 37: {
			std::string value;
			if (captures.is_set(9)) {
				value = captures.text(9);
			} else {
				if (captures.is_set(11)) {
					value = captures.text(11);
				} else {
					if (captures.is_set(10)) {
						value = captures.text(10);
					}
				}
			}
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::grammar::modifier::MOD::id, Types::grammar::modifier::MOD{value}));
			break;
		}
		case 38: {
			std::string value;
			if (captures.is_set(9)) {
				value = captures.text(9);
			} else {
				if (captures.is_set(11)) {
					value = captures.text(11);
				} else {
					if (captures.is_set(10)) {
						value = captures.text(10);
					}
				}
			}
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::grammar::modifier::MOD::id, Types::grammar::modifier::MOD{value}));
			break;
		}
		case 39: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::advanced_rule::dep_decl::DEPENDS::id, Types::advanced_rule::dep_decl::DEPENDS{}));
			break;
		}
	}
	throw std::runtime_error("Out of bound semantic action");
}
auto Parser::Lexer::init() -> void {
	return ;
}
auto Parser::Lexer::makeToken(const char*& pos) -> Token {
	return lookup(dfa_table, char_class_table, action_table, tdfa_registers, semantic_action_exec, debug_array, debug_index, pos);
}
::ISPA_STD::DFA::API::CharToClass Parser::Lexer::char_class_table = {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 0, 15, 16, 16, 16, 16, 16, 16, 16, 16, 16, 17, 18, 19, 20, 21, 22, 23, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 25, 26, 27, 28, 24, 0, 29, 24, 30, 31, 32, 33, 24, 34, 35, 24, 36, 37, 38, 39, 24, 40, 24, 41, 42, 43, 24, 24, 24, 44, 45, 24, 46, 47, 48, 0, 0, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49};
::ISPA_STD::DFA::API::Table<86, 50> Parser::Lexer::dfa_table = {{{::ISPA_STD::DFA::API::null_state, 1, 2, 3, 4, 5, 6, 2, 7, 8, 95, 94, 11, 12, 13, 93, 93, 15, 16, 17, 18, 19, 96, 21, 86, 23, 24, 25, ::ISPA_STD::DFA::API::null_state, 86, 86, 89, 88, 87, 86, 92, 86, 86, 97, 86, 91, 86, 90, 86, 86, 86, 33, 34, 35, ::ISPA_STD::DFA::API::null_state}, {190, 1, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190}, {98, 98, 100, 98, 98, 98, 98, 38, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 99, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, ::ISPA_STD::DFA::API::null_state}, {191, 191, 191, 191, 191, 191, 191, 191, 191, 191, 191, 191, 191, 191, 191, 191, 191, 191, 191, 191, 191, 191, 191, 191, 191, 40, 191, 191, 191, 191, 191, 191, 191, 191, 191, 191, 191, 191, 191, 191, 191, 191, 191, 191, 191, 191, 191, 191, 191, 191}, {192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192}, {193, 193, 193, 193, 193, 193, 193, 193, 193, 193, 193, 193, 193, 193, 193, 193, 193, 193, 193, 193, 193, 193, 193, 193, 193, 193, 193, 193, 193, 193, 193, 193, 193, 193, 193, 193, 193, 193, 193, 193, 193, 193, 193, 193, 193, 193, 193, 193, 193, 193}, {194, 194, 194, 194, 194, 194, 194, 194, 194, 194, 194, 194, 194, 194, 194, 194, 194, 194, 194, 194, 194, 194, 194, 194, 194, 194, 194, 194, 194, 194, 194, 194, 194, 194, 194, 194, 194, 194, 194, 194, 194, 194, 194, 194, 194, 194, 194, 194, 194, 194}, {195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195}, {196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196}, {101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101}, {102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102}, {199, 199, 199, 199, 199, 199, 199, 199, 199, 199, 199, 199, 199, 199, 199, 199, 199, 199, 199, 199, 199, 199, 199, 199, 199, 199, 199, 199, 199, 199, 199, 199, 199, 199, 199, 199, 199, 199, 199, 199, 199, 199, 199, 199, 199, 199, 199, 199, 199, 199}, {::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, 41, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state}, {200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200}, {103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 104, 14, 14, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103}, {202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202}, {203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203}, {204, 204, 204, 204, 204, 204, 204, 204, 204, 204, 204, 204, 204, 204, 204, 204, 204, 204, 204, 204, 204, 204, 204, 204, 204, 204, 204, 204, 204, 204, 204, 204, 204, 204, 204, 204, 204, 204, 204, 204, 204, 204, 204, 204, 204, 204, 204, 204, 204, 204}, {205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 43, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205}, {206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206}, {105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105}, {208, 208, 208, 208, 208, 208, 208, 208, 208, 208, 208, 208, 208, 208, 208, 208, 208, 208, 208, 208, 208, 208, 208, 208, 208, 208, 208, 208, 208, 208, 208, 208, 208, 208, 208, 208, 208, 208, 208, 208, 208, 208, 208, 208, 208, 208, 208, 208, 208, 208}, {106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 44, 44, 106, 106, 106, 106, 106, 106, 106, 44, 106, 106, 106, 106, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 106, 106, 106, 106}, {107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 109, ::ISPA_STD::DFA::API::null_state, 108, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, ::ISPA_STD::DFA::API::null_state}, {::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, 48, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state}, {210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210}, {111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 112, 112, 111, 111, 111, 111, 111, 111, 111, 112, 111, 111, 111, 111, 112, 112, 112, 49, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 111, 111, 111, 111}, {114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 112, 112, 114, 114, 114, 114, 114, 114, 114, 112, 114, 114, 114, 114, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 50, 112, 114, 114, 114, 114}, {116, 116, 116, 116, 116, 116, 116, 116, 116, 116, 116, 116, 116, 116, 116, 112, 112, 116, 116, 116, 116, 116, 116, 116, 112, 116, 116, 116, 116, 51, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 116, 116, 116, 116}, {118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 112, 112, 118, 118, 118, 118, 118, 118, 118, 112, 118, 118, 118, 118, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 52, 112, 112, 112, 112, 112, 112, 118, 118, 118, 118}, {120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 112, 112, 120, 120, 120, 120, 120, 120, 120, 112, 120, 120, 120, 120, 53, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 120, 120, 120, 120}, {122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 112, 112, 122, 122, 122, 122, 122, 122, 122, 112, 122, 122, 122, 122, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 54, 122, 122, 122}, {124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 112, 112, 124, 124, 124, 124, 124, 124, 124, 112, 124, 124, 124, 124, 112, 112, 112, 112, 112, 112, 112, 55, 112, 112, 112, 112, 112, 112, 112, 112, 112, 124, 124, 124, 124}, {211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211}, {212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212}, {213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213}, {36, 36, 126, 36, 36, 36, 36, 125, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 39, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, ::ISPA_STD::DFA::API::null_state}, {127, 127, 132, 127, 127, 127, 127, 130, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 128, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 214}, {214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214}, {36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, ::ISPA_STD::DFA::API::null_state}, {215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215}, {216, 216, 216, 216, 216, 216, 216, 216, 216, 216, 216, 216, 216, 216, 216, 216, 216, 216, 216, 216, 216, 216, 216, 216, 216, 216, 216, 216, 216, 216, 216, 216, 216, 216, 216, 216, 216, 216, 216, 216, 216, 216, 216, 216, 216, 216, 216, 216, 216, 216}, {::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, 133, 133, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state}, {217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217}, {134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 44, 44, 134, 134, 134, 134, 134, 134, 134, 44, 134, 134, 134, 134, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 134, 134, 134, 134}, {45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 46, 135, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, ::ISPA_STD::DFA::API::null_state}, {45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, ::ISPA_STD::DFA::API::null_state}, {136, 136, 136, 136, 136, 136, 136, 136, 136, 136, 136, 136, 136, 136, 136, 136, 136, 136, 136, 136, 136, 136, 136, 136, 136, 136, 137, 135, 136, 136, 136, 136, 136, 136, 136, 136, 136, 136, 136, 136, 136, 136, 136, 136, 136, 136, 136, 136, 136, ::ISPA_STD::DFA::API::null_state}, {219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 61, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219}, {139, 139, 139, 139, 139, 139, 139, 139, 139, 139, 139, 139, 139, 139, 139, 112, 112, 139, 139, 139, 139, 139, 139, 139, 112, 139, 139, 139, 139, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 62, 112, 112, 112, 112, 112, 139, 139, 139, 139}, {141, 141, 141, 141, 141, 141, 141, 141, 141, 141, 141, 141, 141, 141, 141, 112, 112, 141, 141, 141, 141, 141, 141, 141, 112, 141, 141, 141, 141, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 63, 112, 112, 141, 141, 141, 141}, {143, 143, 143, 143, 143, 143, 143, 143, 143, 143, 143, 143, 143, 143, 143, 112, 112, 143, 143, 143, 143, 143, 143, 143, 112, 143, 143, 143, 143, 112, 112, 112, 112, 112, 112, 64, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 143, 143, 143, 143}, {145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 112, 112, 145, 145, 145, 145, 145, 145, 145, 112, 145, 145, 145, 145, 112, 112, 112, 112, 112, 112, 112, 112, 65, 112, 112, 112, 112, 112, 112, 112, 112, 145, 145, 145, 145}, {147, 147, 147, 147, 147, 147, 147, 147, 147, 147, 147, 147, 147, 147, 147, 112, 112, 147, 147, 147, 147, 147, 147, 147, 112, 147, 147, 147, 147, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 66, 112, 112, 147, 147, 147, 147}, {::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, 148, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state}, {150, 150, 150, 150, 150, 150, 150, 150, 150, 150, 150, 150, 150, 150, 150, 112, 112, 150, 150, 150, 150, 150, 150, 150, 112, 150, 150, 150, 150, 112, 112, 112, 112, 112, 112, 68, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 150, 150, 150, 150}, {36, 36, 126, 36, 36, 36, 36, 125, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 39, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 214}, {151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 57, 57, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151}, {221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221}, {59, 59, 59, 59, 59, 59, 59, 59, 59, 59, 59, 59, 59, 59, 59, 59, 59, 59, 59, 59, 59, 59, 59, 59, 59, 59, 60, 152, 59, 59, 59, 59, 59, 59, 59, 59, 59, 59, 59, 59, 59, 59, 59, 59, 59, 59, 59, 59, 59, ::ISPA_STD::DFA::API::null_state}, {59, 59, 59, 59, 59, 59, 59, 59, 59, 59, 59, 59, 59, 59, 59, 59, 59, 59, 59, 59, 59, 59, 59, 59, 59, 59, 59, 59, 59, 59, 59, 59, 59, 59, 59, 59, 59, 59, 59, 59, 59, 59, 59, 59, 59, 59, 59, 59, 59, ::ISPA_STD::DFA::API::null_state}, {222, 222, 222, 222, 222, 222, 222, 222, 222, 222, 222, 222, 222, 222, 222, 222, 222, 222, 222, 222, 222, 222, 222, 222, 222, 222, 222, 222, 222, 222, 222, 222, 222, 222, 222, 222, 222, 222, 222, 222, 222, 222, 222, 222, 222, 222, 222, 222, 222, 222}, {154, 154, 154, 154, 154, 154, 154, 154, 154, 154, 154, 154, 154, 154, 154, 112, 112, 154, 154, 154, 154, 154, 154, 154, 112, 154, 154, 154, 154, 112, 112, 112, 70, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 154, 154, 154, 154}, {156, 156, 156, 156, 156, 156, 156, 156, 156, 156, 156, 156, 156, 156, 156, 112, 112, 156, 156, 156, 156, 156, 156, 156, 112, 156, 156, 156, 156, 112, 112, 112, 71, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 156, 156, 156, 156}, {158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 112, 112, 158, 158, 158, 158, 158, 158, 158, 112, 158, 158, 158, 158, 112, 112, 112, 112, 112, 112, 112, 112, 72, 112, 112, 112, 112, 112, 112, 112, 112, 158, 158, 158, 158}, {160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 112, 112, 160, 160, 160, 160, 160, 160, 160, 112, 160, 160, 160, 160, 112, 112, 112, 112, 112, 112, 73, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 160, 160, 160, 160}, {162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 112, 112, 162, 162, 162, 162, 162, 162, 162, 112, 162, 162, 162, 162, 112, 74, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 162, 162, 162, 162}, {::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, 75, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state}, {164, 164, 164, 164, 164, 164, 164, 164, 164, 164, 164, 164, 164, 164, 164, 112, 112, 164, 164, 164, 164, 164, 164, 164, 112, 164, 164, 164, 164, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 76, 112, 112, 112, 112, 112, 164, 164, 164, 164}, {166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166}, {168, 168, 168, 168, 168, 168, 168, 168, 168, 168, 168, 168, 168, 168, 168, 112, 112, 168, 168, 168, 168, 168, 168, 168, 112, 168, 168, 168, 168, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 77, 112, 112, 112, 112, 112, 112, 168, 168, 168, 168}, {170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 112, 112, 170, 170, 170, 170, 170, 170, 170, 112, 170, 170, 170, 170, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 78, 112, 112, 112, 112, 170, 170, 170, 170}, {223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 112, 112, 223, 223, 223, 223, 223, 223, 223, 112, 223, 223, 223, 223, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 223, 223, 223, 223}, {172, 172, 172, 172, 172, 172, 172, 172, 172, 172, 172, 172, 172, 172, 172, 112, 112, 172, 172, 172, 172, 172, 172, 172, 112, 172, 172, 172, 172, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 79, 112, 112, 112, 112, 112, 112, 172, 172, 172, 172}, {174, 174, 174, 174, 174, 174, 174, 174, 174, 174, 174, 174, 174, 174, 174, 112, 112, 174, 174, 174, 174, 174, 174, 174, 112, 174, 174, 174, 174, 112, 112, 112, 112, 112, 80, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 174, 174, 174, 174}, {::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, 175, ::ISPA_STD::DFA::API::null_state}, {177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 112, 112, 177, 177, 177, 177, 177, 177, 177, 112, 177, 177, 177, 177, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 177, 177, 177, 177}, {179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 112, 112, 179, 179, 179, 179, 179, 179, 179, 112, 179, 179, 179, 179, 112, 112, 82, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 179, 179, 179, 179}, {181, 181, 181, 181, 181, 181, 181, 181, 181, 181, 181, 181, 181, 181, 181, 112, 112, 181, 181, 181, 181, 181, 181, 181, 112, 181, 181, 181, 181, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 83, 112, 112, 112, 112, 112, 112, 181, 181, 181, 181}, {183, 183, 183, 183, 183, 183, 183, 183, 183, 183, 183, 183, 183, 183, 183, 112, 112, 183, 183, 183, 183, 183, 183, 183, 112, 183, 183, 183, 183, 112, 112, 112, 84, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 183, 183, 183, 183}, {225, 225, 225, 225, 225, 225, 225, 225, 225, 225, 225, 225, 225, 225, 225, 112, 112, 225, 225, 225, 225, 225, 225, 225, 112, 225, 225, 225, 225, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 225, 225, 225, 225}, {226, 226, 226, 226, 226, 226, 226, 226, 226, 226, 226, 226, 226, 226, 226, 226, 226, 226, 226, 226, 226, 226, 226, 226, 226, 226, 226, 226, 226, 226, 226, 226, 226, 226, 226, 226, 226, 226, 226, 226, 226, 226, 226, 226, 226, 226, 226, 226, 226, 226}, {185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 112, 112, 185, 185, 185, 185, 185, 185, 185, 112, 185, 185, 185, 185, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 85, 112, 112, 112, 185, 185, 185, 185}, {187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 112, 112, 187, 187, 187, 187, 187, 187, 187, 112, 187, 187, 187, 187, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 187, 187, 187, 187}, {189, 189, 189, 189, 189, 189, 189, 189, 189, 189, 189, 189, 189, 189, 189, 112, 112, 189, 189, 189, 189, 189, 189, 189, 112, 189, 189, 189, 189, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 189, 189, 189, 189}, {229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 112, 112, 229, 229, 229, 229, 229, 229, 229, 112, 229, 229, 229, 229, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 229, 229, 229, 229}}};
::ISPA_STD::DFA::API::Table<104, 4> Parser::Lexer::action_table = {{{1, 0, ::ISPA_STD::DFA::API::null_state, 22}, {1, 26, ::ISPA_STD::DFA::API::null_state, 28}, {1, 26, ::ISPA_STD::DFA::API::null_state, 27}, {1, 26, ::ISPA_STD::DFA::API::null_state, 26}, {1, 26, ::ISPA_STD::DFA::API::null_state, 32}, {1, 26, ::ISPA_STD::DFA::API::null_state, 31}, {1, 26, ::ISPA_STD::DFA::API::null_state, 29}, {1, 14, ::ISPA_STD::DFA::API::null_state, 14}, {1, 12, ::ISPA_STD::DFA::API::null_state, 10}, {1, 8, ::ISPA_STD::DFA::API::null_state, 9}, {1, 10, ::ISPA_STD::DFA::API::null_state, 20}, {1, 26, ::ISPA_STD::DFA::API::null_state, 30}, {1, 24, ::ISPA_STD::DFA::API::null_state, 36}, {1, 24, ::ISPA_STD::DFA::API::null_state, 39}, {1, 26, ::ISPA_STD::DFA::API::null_state, 37}, {1, 9, ::ISPA_STD::DFA::API::null_state, 197}, {1, 13, ::ISPA_STD::DFA::API::null_state, 198}, {1, 15, ::ISPA_STD::DFA::API::null_state, 201}, {1, 15, ::ISPA_STD::DFA::API::null_state, 42}, {1, 11, ::ISPA_STD::DFA::API::null_state, 207}, {1, 1, ::ISPA_STD::DFA::API::null_state, 209}, {1, 6, ::ISPA_STD::DFA::API::null_state, 45}, {1, 6, ::ISPA_STD::DFA::API::null_state, 47}, {1, 6, ::ISPA_STD::DFA::API::null_state, 46}, {3, 0, 26, 209}, {1, 1, ::ISPA_STD::DFA::API::null_state, 110}, {3, 0, 26, 44}, {3, 0, 26, 209}, {1, 1, ::ISPA_STD::DFA::API::null_state, 113}, {3, 0, 26, 209}, {1, 1, ::ISPA_STD::DFA::API::null_state, 115}, {3, 0, 26, 209}, {1, 1, ::ISPA_STD::DFA::API::null_state, 117}, {3, 0, 26, 209}, {1, 1, ::ISPA_STD::DFA::API::null_state, 119}, {3, 0, 26, 209}, {1, 1, ::ISPA_STD::DFA::API::null_state, 121}, {3, 0, 26, 209}, {1, 1, ::ISPA_STD::DFA::API::null_state, 123}, {1, 25, ::ISPA_STD::DFA::API::null_state, 38}, {1, 25, ::ISPA_STD::DFA::API::null_state, 56}, {3, 24, 26, 36}, {3, 24, 26, 39}, {3, 24, 26, 38}, {1, 25, ::ISPA_STD::DFA::API::null_state, 129}, {3, 24, 26, 56}, {1, 25, ::ISPA_STD::DFA::API::null_state, 131}, {1, 16, ::ISPA_STD::DFA::API::null_state, 57}, {1, 1, ::ISPA_STD::DFA::API::null_state, 218}, {1, 7, ::ISPA_STD::DFA::API::null_state, 58}, {1, 5, ::ISPA_STD::DFA::API::null_state, 59}, {1, 5, ::ISPA_STD::DFA::API::null_state, 60}, {3, 0, 26, 218}, {1, 1, ::ISPA_STD::DFA::API::null_state, 138}, {3, 0, 26, 218}, {1, 1, ::ISPA_STD::DFA::API::null_state, 140}, {3, 0, 26, 218}, {1, 1, ::ISPA_STD::DFA::API::null_state, 142}, {3, 0, 26, 218}, {1, 1, ::ISPA_STD::DFA::API::null_state, 144}, {3, 0, 26, 218}, {1, 1, ::ISPA_STD::DFA::API::null_state, 146}, {1, 2, ::ISPA_STD::DFA::API::null_state, 67}, {3, 0, 26, 218}, {1, 1, ::ISPA_STD::DFA::API::null_state, 149}, {1, 17, ::ISPA_STD::DFA::API::null_state, 220}, {1, 7, ::ISPA_STD::DFA::API::null_state, 69}, {3, 0, 26, 218}, {1, 1, ::ISPA_STD::DFA::API::null_state, 153}, {3, 0, 26, 218}, {1, 1, ::ISPA_STD::DFA::API::null_state, 155}, {3, 0, 26, 218}, {1, 1, ::ISPA_STD::DFA::API::null_state, 157}, {3, 0, 26, 218}, {1, 1, ::ISPA_STD::DFA::API::null_state, 159}, {3, 0, 26, 218}, {1, 1, ::ISPA_STD::DFA::API::null_state, 161}, {3, 0, 26, 218}, {1, 1, ::ISPA_STD::DFA::API::null_state, 163}, {3, 6, 5, 221}, {3, 4, 6, 165}, {3, 0, 26, 218}, {1, 1, ::ISPA_STD::DFA::API::null_state, 167}, {3, 0, 26, 218}, {1, 1, ::ISPA_STD::DFA::API::null_state, 169}, {3, 0, 26, 218}, {1, 1, ::ISPA_STD::DFA::API::null_state, 171}, {3, 0, 26, 218}, {1, 1, ::ISPA_STD::DFA::API::null_state, 173}, {1, 3, ::ISPA_STD::DFA::API::null_state, 81}, {3, 20, 26, 224}, {1, 21, ::ISPA_STD::DFA::API::null_state, 176}, {3, 0, 26, 218}, {1, 1, ::ISPA_STD::DFA::API::null_state, 178}, {3, 0, 26, 218}, {1, 1, ::ISPA_STD::DFA::API::null_state, 180}, {3, 0, 26, 218}, {1, 1, ::ISPA_STD::DFA::API::null_state, 182}, {3, 0, 26, 218}, {1, 1, ::ISPA_STD::DFA::API::null_state, 184}, {3, 18, 26, 227}, {1, 19, ::ISPA_STD::DFA::API::null_state, 186}, {3, 22, 26, 228}, {1, 23, ::ISPA_STD::DFA::API::null_state, 188}}};
std::array<::ISPA_STD::DFA::API::DFADebug, 1> Parser::Lexer::debug_array = {::ISPA_STD::DFA::API::DFADebug {"<Undefined>", "", 0, -1, -1, -1, 0, 1, '\000'}};
std::unordered_map<long long, std::unordered_map<long long, long long>> Parser::Lexer::debug_index = { { 0, { { 1, 0 }, { 2, 0 }, { 3, 0 }, { 4, 0 }, { 5, 0 }, { 6, 0 }, { 7, 0 }, { 8, 0 }, { 9, 0 }, { 12, 0 }, { 13, 0 }, { 14, 0 }, { 17, 0 }, { 18, 0 }, { 19, 0 }, { 20, 0 }, { 21, 0 }, { 23, 0 }, { 25, 0 }, { 26, 0 }, { 27, 0 }, { 46, 0 }, { 47, 0 }, { 48, 0 } } }, { 1, { { 1, 0 } } }, { 2, { { 7, 0 } } }, { 3, { { 25, 0 } } }, { 12, { { 21, 0 } } }, { 14, { { 15, 0 }, { 16, 0 } } }, { 18, { { 21, 0 } } }, { 22, { { 15, 0 }, { 16, 0 }, { 24, 0 }, { 29, 0 }, { 30, 0 }, { 31, 0 }, { 32, 0 }, { 33, 0 }, { 34, 0 }, { 35, 0 }, { 36, 0 }, { 37, 0 }, { 38, 0 }, { 39, 0 }, { 40, 0 }, { 41, 0 }, { 42, 0 }, { 43, 0 }, { 44, 0 }, { 45, 0 } } }, { 24, { { 42, 0 } } }, { 26, { { 32, 0 } } }, { 27, { { 44, 0 } } }, { 28, { { 29, 0 } } }, { 29, { { 39, 0 } } }, { 30, { { 29, 0 } } }, { 31, { { 46, 0 } } }, { 32, { { 36, 0 } } }, { 36, { { 0, 0 }, { 1, 0 }, { 3, 0 }, { 4, 0 }, { 5, 0 }, { 6, 0 }, { 8, 0 }, { 9, 0 }, { 10, 0 }, { 11, 0 }, { 12, 0 }, { 13, 0 }, { 14, 0 }, { 15, 0 }, { 16, 0 }, { 17, 0 }, { 18, 0 }, { 19, 0 }, { 20, 0 }, { 21, 0 }, { 22, 0 }, { 23, 0 }, { 24, 0 }, { 25, 0 }, { 26, 0 }, { 27, 0 }, { 28, 0 }, { 29, 0 }, { 30, 0 }, { 31, 0 }, { 32, 0 }, { 33, 0 }, { 34, 0 }, { 35, 0 }, { 36, 0 }, { 37, 0 }, { 38, 0 }, { 39, 0 }, { 40, 0 }, { 41, 0 }, { 42, 0 }, { 43, 0 }, { 44, 0 }, { 45, 0 }, { 46, 0 }, { 47, 0 }, { 48, 0 } } }, { 39, { { 0, 0 }, { 1, 0 }, { 2, 0 }, { 3, 0 }, { 4, 0 }, { 5, 0 }, { 6, 0 }, { 7, 0 }, { 8, 0 }, { 9, 0 }, { 10, 0 }, { 11, 0 }, { 12, 0 }, { 13, 0 }, { 14, 0 }, { 15, 0 }, { 16, 0 }, { 17, 0 }, { 18, 0 }, { 19, 0 }, { 20, 0 }, { 21, 0 }, { 22, 0 }, { 23, 0 }, { 24, 0 }, { 25, 0 }, { 26, 0 }, { 27, 0 }, { 28, 0 }, { 29, 0 }, { 30, 0 }, { 31, 0 }, { 32, 0 }, { 33, 0 }, { 34, 0 }, { 35, 0 }, { 36, 0 }, { 37, 0 }, { 38, 0 }, { 39, 0 }, { 40, 0 }, { 41, 0 }, { 42, 0 }, { 43, 0 }, { 44, 0 }, { 45, 0 }, { 46, 0 }, { 47, 0 }, { 48, 0 } } }, { 44, { { 15, 0 }, { 16, 0 }, { 24, 0 }, { 29, 0 }, { 30, 0 }, { 31, 0 }, { 32, 0 }, { 33, 0 }, { 34, 0 }, { 35, 0 }, { 36, 0 }, { 37, 0 }, { 38, 0 }, { 39, 0 }, { 40, 0 }, { 41, 0 }, { 42, 0 }, { 43, 0 }, { 44, 0 }, { 45, 0 } } }, { 45, { { 0, 0 }, { 1, 0 }, { 2, 0 }, { 3, 0 }, { 4, 0 }, { 5, 0 }, { 6, 0 }, { 7, 0 }, { 8, 0 }, { 9, 0 }, { 10, 0 }, { 11, 0 }, { 12, 0 }, { 13, 0 }, { 14, 0 }, { 15, 0 }, { 16, 0 }, { 17, 0 }, { 18, 0 }, { 19, 0 }, { 20, 0 }, { 21, 0 }, { 22, 0 }, { 23, 0 }, { 24, 0 }, { 25, 0 }, { 26, 0 }, { 28, 0 }, { 29, 0 }, { 30, 0 }, { 31, 0 }, { 32, 0 }, { 33, 0 }, { 34, 0 }, { 35, 0 }, { 36, 0 }, { 37, 0 }, { 38, 0 }, { 39, 0 }, { 40, 0 }, { 41, 0 }, { 42, 0 }, { 43, 0 }, { 44, 0 }, { 45, 0 }, { 46, 0 }, { 47, 0 }, { 48, 0 } } }, { 46, { { 0, 0 }, { 1, 0 }, { 2, 0 }, { 3, 0 }, { 4, 0 }, { 5, 0 }, { 6, 0 }, { 7, 0 }, { 8, 0 }, { 9, 0 }, { 10, 0 }, { 11, 0 }, { 12, 0 }, { 13, 0 }, { 14, 0 }, { 15, 0 }, { 16, 0 }, { 17, 0 }, { 18, 0 }, { 19, 0 }, { 20, 0 }, { 21, 0 }, { 22, 0 }, { 23, 0 }, { 24, 0 }, { 25, 0 }, { 26, 0 }, { 27, 0 }, { 28, 0 }, { 29, 0 }, { 30, 0 }, { 31, 0 }, { 32, 0 }, { 33, 0 }, { 34, 0 }, { 35, 0 }, { 36, 0 }, { 37, 0 }, { 38, 0 }, { 39, 0 }, { 40, 0 }, { 41, 0 }, { 42, 0 }, { 43, 0 }, { 44, 0 }, { 45, 0 }, { 46, 0 }, { 47, 0 }, { 48, 0 } } }, { 48, { { 15, 0 } } }, { 49, { { 40, 0 } } }, { 50, { { 43, 0 } } }, { 51, { { 35, 0 } } }, { 52, { { 37, 0 } } }, { 53, { { 43, 0 } } }, { 55, { { 35, 0 } } }, { 56, { { 0, 0 }, { 1, 0 }, { 3, 0 }, { 4, 0 }, { 5, 0 }, { 6, 0 }, { 8, 0 }, { 9, 0 }, { 10, 0 }, { 11, 0 }, { 12, 0 }, { 13, 0 }, { 14, 0 }, { 15, 0 }, { 16, 0 }, { 17, 0 }, { 18, 0 }, { 19, 0 }, { 20, 0 }, { 21, 0 }, { 22, 0 }, { 23, 0 }, { 24, 0 }, { 25, 0 }, { 26, 0 }, { 27, 0 }, { 28, 0 }, { 29, 0 }, { 30, 0 }, { 31, 0 }, { 32, 0 }, { 33, 0 }, { 34, 0 }, { 35, 0 }, { 36, 0 }, { 37, 0 }, { 38, 0 }, { 39, 0 }, { 40, 0 }, { 41, 0 }, { 42, 0 }, { 43, 0 }, { 44, 0 }, { 45, 0 }, { 46, 0 }, { 47, 0 }, { 48, 0 } } }, { 57, { { 15, 0 }, { 16, 0 } } }, { 59, { { 0, 0 }, { 1, 0 }, { 2, 0 }, { 3, 0 }, { 4, 0 }, { 5, 0 }, { 6, 0 }, { 7, 0 }, { 8, 0 }, { 9, 0 }, { 10, 0 }, { 11, 0 }, { 12, 0 }, { 13, 0 }, { 14, 0 }, { 15, 0 }, { 16, 0 }, { 17, 0 }, { 18, 0 }, { 19, 0 }, { 20, 0 }, { 21, 0 }, { 22, 0 }, { 23, 0 }, { 24, 0 }, { 25, 0 }, { 26, 0 }, { 28, 0 }, { 29, 0 }, { 30, 0 }, { 31, 0 }, { 32, 0 }, { 33, 0 }, { 34, 0 }, { 35, 0 }, { 36, 0 }, { 37, 0 }, { 38, 0 }, { 39, 0 }, { 40, 0 }, { 41, 0 }, { 42, 0 }, { 43, 0 }, { 44, 0 }, { 45, 0 }, { 46, 0 }, { 47, 0 }, { 48, 0 } } }, { 60, { { 0, 0 }, { 1, 0 }, { 2, 0 }, { 3, 0 }, { 4, 0 }, { 5, 0 }, { 6, 0 }, { 7, 0 }, { 8, 0 }, { 9, 0 }, { 10, 0 }, { 11, 0 }, { 12, 0 }, { 13, 0 }, { 14, 0 }, { 15, 0 }, { 16, 0 }, { 17, 0 }, { 18, 0 }, { 19, 0 }, { 20, 0 }, { 21, 0 }, { 22, 0 }, { 23, 0 }, { 24, 0 }, { 25, 0 }, { 26, 0 }, { 27, 0 }, { 28, 0 }, { 29, 0 }, { 30, 0 }, { 31, 0 }, { 32, 0 }, { 33, 0 }, { 34, 0 }, { 35, 0 }, { 36, 0 }, { 37, 0 }, { 38, 0 }, { 39, 0 }, { 40, 0 }, { 41, 0 }, { 42, 0 }, { 43, 0 }, { 44, 0 }, { 45, 0 }, { 46, 0 }, { 47, 0 }, { 48, 0 } } }, { 62, { { 32, 0 } } }, { 63, { { 32, 0 } } }, { 64, { { 37, 0 } } }, { 65, { { 35, 0 } } }, { 66, { { 30, 0 } } }, { 67, { { 45, 0 } } }, { 68, { { 40, 0 } } }, { 70, { { 39, 0 } } }, { 71, { { 41, 0 } } }, { 73, { { 39, 0 } } }, { 74, { { 34, 0 } } }, { 77, { { 31, 0 } } }, { 78, { { 39, 0 } } }, { 79, { { 32, 0 } } }, { 82, { { 42, 0 } } } };
template<typename IT, class> auto Parser::Parser::ruleNested_rule(IT pos) -> ::ISPA_STD::MatchResult<Types::rule::nested_rule, IT> {
	::ISPA_STD::Node<Types::rule::nested_rule::NUMBER_SIGN> value_rule_nested_rule_NUMBER_SIGN;
	::ISPA_STD::Node<Types::grammar> value_grammar;
	value_rule_nested_rule_NUMBER_SIGN = required<Types::rule::nested_rule::NUMBER_SIGN>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::rule::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::ID::id, Tokens::grammar::modifier::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("rule::nested_rule", "rule::nested_rule::NUMBER_SIGN"));
	value_grammar = required<Types::grammar>(pos, [this](auto cursor) { return this->grammar(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::ID::id, Tokens::grammar::modifier::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("rule::nested_rule", "grammar"));
	Types::rule::nested_rule result;
	::ISPA_STD::assign_compatible(result.value, value_grammar);
	::ISPA_STD::MatchResult<Types::rule::nested_rule, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::ruleNested_rule<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::rule::nested_rule, ::Parser::Lexer::iterator>;
template auto Parser::Parser::ruleNested_rule<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::rule::nested_rule, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::ruleValueCounter(IT pos) -> ::ISPA_STD::MatchResult<Types::rule::value::counter, IT> {
	::ISPA_STD::Node<Types::rule::value::QUANTIFIER> value_rule_value_QUANTIFIER;
	::ISPA_STD::Node<Types::rule::value::counter::bounded> value_rule_value_counter_bounded;
	value_rule_value_QUANTIFIER = required<Types::rule::value::QUANTIFIER>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::rule::value::QUANTIFIER::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id, Tokens::rule::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id, Tokens::rule::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("rule::value::counter", "rule::value::QUANTIFIER"));
	skip_spaces<Types::__WS>(pos);
	value_rule_value_counter_bounded = optional<Types::rule::value::counter::bounded>(pos, [this](auto cursor) { return this->ruleValueCounterBounded(cursor); });
	Types::rule::value::counter result;
	::ISPA_STD::assign_compatible(result.quantifier, value_rule_value_QUANTIFIER);
	::ISPA_STD::assign_compatible(result.repetitions, value_rule_value_counter_bounded);
	::ISPA_STD::MatchResult<Types::rule::value::counter, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::ruleValueCounter<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::rule::value::counter, ::Parser::Lexer::iterator>;
template auto Parser::Parser::ruleValueCounter<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::rule::value::counter, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::ruleValueDynDyn_expr(IT pos) -> ::ISPA_STD::MatchResult<Types::rule::value::dyn::dyn_expr, IT> {
	::ISPA_STD::Node<Types::LEFT_CURLY_BRACKET> value_LEFT_CURLY_BRACKET;
	::ISPA_STD::Node<Types::expr> value_expr;
	::ISPA_STD::Node<Types::RIGHT_CURLY_BRACKET> value_RIGHT_CURLY_BRACKET;
	value_LEFT_CURLY_BRACKET = required<Types::LEFT_CURLY_BRACKET>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::LEFT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::PY_RAW::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::QUANTIFIER::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::alternative::VERTICAL_LINE::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id, Tokens::rule::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("rule::value::dyn::dyn_expr", "LEFT_CURLY_BRACKET"));
	skip_spaces<Types::__WS>(pos);
	value_expr = required<Types::expr>(pos, [this](auto cursor) { return this->expr(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::PY_RAW::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::QUANTIFIER::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::alternative::VERTICAL_LINE::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id, Tokens::rule::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("rule::value::dyn::dyn_expr", "expr"));
	skip_spaces<Types::__WS>(pos);
	value_RIGHT_CURLY_BRACKET = required<Types::RIGHT_CURLY_BRACKET>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::QUANTIFIER::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::alternative::VERTICAL_LINE::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id, Tokens::rule::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::QUANTIFIER::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::alternative::VERTICAL_LINE::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id, Tokens::rule::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("rule::value::dyn::dyn_expr", "RIGHT_CURLY_BRACKET"));
	Types::rule::value::dyn::dyn_expr result;
	::ISPA_STD::assign_compatible(result.value, value_expr);
	::ISPA_STD::MatchResult<Types::rule::value::dyn::dyn_expr, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::ruleValueDynDyn_expr<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::rule::value::dyn::dyn_expr, ::Parser::Lexer::iterator>;
template auto Parser::Parser::ruleValueDynDyn_expr<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::rule::value::dyn::dyn_expr, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::ruleValueDyn(IT pos) -> ::ISPA_STD::MatchResult<Types::rule::value::dyn, IT> {
	::ISPA_STD::Node<Types::rule::value::dyn::DOLLAR_SIGN> value_rule_value_dyn_DOLLAR_SIGN;
	std::variant<std::monostate, ::ISPA_STD::Node<Types::rule::value::dyn::dyn_expr>, ::ISPA_STD::Node<Types::ID>> choice0;
	bool matched0;
	::ISPA_STD::Node<Types::rule::value::dyn::dyn_expr> value_rule_value_dyn_dyn_expr;
	::ISPA_STD::Node<Types::ID> value_ID;
	value_rule_value_dyn_DOLLAR_SIGN = required<Types::rule::value::dyn::DOLLAR_SIGN>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::QUANTIFIER::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::alternative::VERTICAL_LINE::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id, Tokens::rule::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("rule::value::dyn", "rule::value::dyn::DOLLAR_SIGN"));
	skip_spaces<Types::__WS>(pos);
	// grammar `@  ( rule::value::dyn::dyn_expr |  ID)`: choice; alternative selected by LL(1) lookahead
	matched0 = false;
	auto la0_1 = pos;
	switch ((*la0_1).kind()) {
		case Tokens::ID::id: {
			value_ID = required<Types::ID>(la0_1, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::QUANTIFIER::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::alternative::VERTICAL_LINE::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id, Tokens::rule::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::QUANTIFIER::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::alternative::VERTICAL_LINE::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id, Tokens::rule::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("rule::value::dyn", "<group>"));
			choice0 = value_ID;
			matched0 = true;
			break;
		}
		case Tokens::LEFT_CURLY_BRACKET::id: {
			value_rule_value_dyn_dyn_expr = required<Types::rule::value::dyn::dyn_expr>(la0_1, [this](auto cursor) { return this->ruleValueDynDyn_expr(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::QUANTIFIER::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::alternative::VERTICAL_LINE::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id, Tokens::rule::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::QUANTIFIER::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::alternative::VERTICAL_LINE::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id, Tokens::rule::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("rule::value::dyn", "<group>"));
			choice0 = value_rule_value_dyn_dyn_expr;
			matched0 = true;
			break;
		}
	}
	pos = la0_1;
	if (!matched0) {
		raise_error(*pos, "ISPA match failure: expected one of: LEFT_CURLY_BRACKET, ID");
		return {};
	}
	Types::rule::value::dyn result;
	::ISPA_STD::assign_compatible(result.value, choice0);
	::ISPA_STD::MatchResult<Types::rule::value::dyn, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::ruleValueDyn<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::rule::value::dyn, ::Parser::Lexer::iterator>;
template auto Parser::Parser::ruleValueDyn<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::rule::value::dyn, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::ruleValueMul_capture(IT pos) -> ::ISPA_STD::MatchResult<Types::rule::value::mul_capture, IT> {
	std::variant<std::monostate, ::ISPA_STD::Node<Types::COMMERCIAL_AT>, ::ISPA_STD::Node<Types::PERCENT_SIGN>> choice0;
	bool matched0;
	::ISPA_STD::Node<Types::COMMERCIAL_AT> value_COMMERCIAL_AT;
	::ISPA_STD::Node<Types::PERCENT_SIGN> value_PERCENT_SIGN;
	::ISPA_STD::Node<Types::EQUALS_SIGN> value_EQUALS_SIGN;
	::ISPA_STD::Node<Types::LEFT_PARENTHESIS> value_LEFT_PARENTHESIS;
	std::vector<::ISPA_STD::Node<Types::rule::value::one_capture>> value_list_rule_value_one_capture;
	::ISPA_STD::Node<Types::RIGHT_PARENTHESIS> value_RIGHT_PARENTHESIS;
	// grammar `@  ( COMMERCIAL_AT |  PERCENT_SIGN)`: choice; alternative selected by LL(1) lookahead
	matched0 = false;
	auto la0_1 = pos;
	switch ((*la0_1).kind()) {
		case Tokens::COMMERCIAL_AT::id: {
			value_COMMERCIAL_AT = required<Types::COMMERCIAL_AT>(la0_1, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::COMMERCIAL_AT::id, Tokens::PERCENT_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::EQUALS_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("rule::value::mul_capture", "<group>"));
			choice0 = value_COMMERCIAL_AT;
			matched0 = true;
			break;
		}
		case Tokens::PERCENT_SIGN::id: {
			value_PERCENT_SIGN = required<Types::PERCENT_SIGN>(la0_1, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::COMMERCIAL_AT::id, Tokens::PERCENT_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::EQUALS_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("rule::value::mul_capture", "<group>"));
			choice0 = value_PERCENT_SIGN;
			matched0 = true;
			break;
		}
	}
	pos = la0_1;
	if (!matched0) {
		raise_error(*pos, "ISPA match failure: expected one of: COMMERCIAL_AT, PERCENT_SIGN");
		return {};
	}
	skip_spaces<Types::__WS>(pos);
	value_EQUALS_SIGN = required<Types::EQUALS_SIGN>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::EQUALS_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::LEFT_PARENTHESIS::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("rule::value::mul_capture", "EQUALS_SIGN"));
	skip_spaces<Types::__WS>(pos);
	value_LEFT_PARENTHESIS = required<Types::LEFT_PARENTHESIS>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::LEFT_PARENTHESIS::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("rule::value::mul_capture", "LEFT_PARENTHESIS"));
	skip_spaces<Types::__WS>(pos);
	value_list_rule_value_one_capture = range<Types::rule::value::one_capture, Types::__WS>(pos, [this](auto cursor) { return this->ruleValueOne_capture(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_PARENTHESIS::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("rule::value::mul_capture", "rule::value::one_capture"));
	skip_spaces<Types::__WS>(pos);
	value_RIGHT_PARENTHESIS = required<Types::RIGHT_PARENTHESIS>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::RIGHT_PARENTHESIS::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("rule::value::mul_capture", "RIGHT_PARENTHESIS"));
	Types::rule::value::mul_capture result;
	::ISPA_STD::assign_compatible(result.type, choice0);
	::ISPA_STD::assign_compatible(result.cap, value_list_rule_value_one_capture);
	::ISPA_STD::MatchResult<Types::rule::value::mul_capture, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::ruleValueMul_capture<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::rule::value::mul_capture, ::Parser::Lexer::iterator>;
template auto Parser::Parser::ruleValueMul_capture<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::rule::value::mul_capture, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::ruleAst(IT pos) -> ::ISPA_STD::MatchResult<Types::rule::ast, IT> {
	std::variant<std::monostate, ::ISPA_STD::Node<Types::rule::ast::abbr>, ::ISPA_STD::Node<Types::rule::ast::full>, ::ISPA_STD::Node<Types::rule::ast::single_value>> choice0;
	bool matched0;
	::ISPA_STD::Node<Types::rule::ast::abbr> value_rule_ast_abbr;
	::ISPA_STD::Node<Types::rule::ast::full> value_rule_ast_full;
	::ISPA_STD::Node<Types::rule::ast::single_value> value_rule_ast_single_value;
	// grammar `@  ( rule::ast::abbr |  rule::ast::full |  rule::ast::single_value)`: choice; alternative selected by LL(1) lookahead
	matched0 = false;
	auto la0_1 = pos;
	switch ((*la0_1).kind()) {
		case Tokens::AMPERSAND::id: {
			value_rule_ast_full = required<Types::rule::ast::full>(la0_1, [this](auto cursor) { return this->ruleAstFull(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::PERCENT_SIGN::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::PERCENT_SIGN::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("rule::ast", "<group>"));
			choice0 = value_rule_ast_full;
			matched0 = true;
			break;
		}
		case Tokens::COMMERCIAL_AT::id: {
			value_rule_ast_abbr = required<Types::rule::ast::abbr>(la0_1, [this](auto cursor) { return this->ruleAstAbbr(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::PERCENT_SIGN::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::PERCENT_SIGN::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("rule::ast", "<group>"));
			choice0 = value_rule_ast_abbr;
			matched0 = true;
			break;
		}
		case Tokens::LEFT_CURLY_BRACKET::id: {
			value_rule_ast_single_value = required<Types::rule::ast::single_value>(la0_1, [this](auto cursor) { return this->ruleAstSingle_value(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::PERCENT_SIGN::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::PERCENT_SIGN::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("rule::ast", "<group>"));
			choice0 = value_rule_ast_single_value;
			matched0 = true;
			break;
		}
	}
	pos = la0_1;
	if (!matched0) {
		raise_error(*pos, "ISPA match failure: expected one of: COMMERCIAL_AT, AMPERSAND, LEFT_CURLY_BRACKET");
		return {};
	}
	Types::rule::ast result;
	::ISPA_STD::assign_compatible(result.value, choice0);
	::ISPA_STD::MatchResult<Types::rule::ast, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::ruleAst<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::rule::ast, ::Parser::Lexer::iterator>;
template auto Parser::Parser::ruleAst<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::rule::ast, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::ruleValueAst_capture(IT pos) -> ::ISPA_STD::MatchResult<Types::rule::value::ast_capture, IT> {
	::ISPA_STD::Node<Types::COMMERCIAL_AT> value_COMMERCIAL_AT;
	::ISPA_STD::Node<Types::ID> value_ID;
	value_COMMERCIAL_AT = required<Types::COMMERCIAL_AT>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::COMMERCIAL_AT::id>, ISPA_STD::Recovery::Tokens<Tokens::ID::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::ID::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("rule::value::ast_capture", "COMMERCIAL_AT"));
	value_ID = optional<Types::ID>(pos);
	Types::rule::value::ast_capture result;
	::ISPA_STD::assign_compatible(result.value, value_ID);
	::ISPA_STD::MatchResult<Types::rule::value::ast_capture, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::ruleValueAst_capture<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::rule::value::ast_capture, ::Parser::Lexer::iterator>;
template auto Parser::Parser::ruleValueAst_capture<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::rule::value::ast_capture, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::ruleF_binding(IT pos) -> ::ISPA_STD::MatchResult<Types::rule::f_binding, IT> {
	::ISPA_STD::Node<Types::PERCENT_SIGN> value_PERCENT_SIGN;
	::ISPA_STD::Node<Types::LEFT_CURLY_BRACKET> value_LEFT_CURLY_BRACKET;
	::ISPA_STD::Node<Types::ID> value_ID;
	::ISPA_STD::Node<Types::COMMA> value_COMMA;
	::ISPA_STD::Node<Types::ID> value_ID_1;
	std::pair<::ISPA_STD::Node<Types::COMMA>, ::ISPA_STD::Node<Types::ID>> group0;
	std::vector<std::pair<::ISPA_STD::Node<Types::COMMA>, ::ISPA_STD::Node<Types::ID>>> group_list1;
	std::vector<::ISPA_STD::Node<Types::ID>> capture_list2;
	::ISPA_STD::Node<Types::RIGHT_CURLY_BRACKET> value_RIGHT_CURLY_BRACKET;
	value_PERCENT_SIGN = required<Types::PERCENT_SIGN>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::PERCENT_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::LEFT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("rule::f_binding", "PERCENT_SIGN"));
	skip_spaces<Types::__WS>(pos);
	value_LEFT_CURLY_BRACKET = required<Types::LEFT_CURLY_BRACKET>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::LEFT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::ID::id>, ISPA_STD::Recovery::Tokens<Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("rule::f_binding", "LEFT_CURLY_BRACKET"));
	skip_spaces<Types::__WS>(pos);
	value_ID = required<Types::ID>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::ID::id>, ISPA_STD::Recovery::Tokens<Tokens::COMMA::id, Tokens::RIGHT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("rule::f_binding", "ID"));
	skip_spaces<Types::__WS>(pos);
	// grammar ` ( COMMA  __WS?; @  ID)*;`: repeat while lookahead is in FIRST
	while (((*pos).kind() == Tokens::COMMA::id)) {
		value_COMMA = required<Types::COMMA>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::COMMA::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("rule::f_binding", "<group>"));
		skip_spaces<Types::__WS>(pos);
		value_ID_1 = required<Types::ID>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::COMMA::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("rule::f_binding", "<group>"));
		group0 = std::make_pair(value_COMMA, value_ID_1);
		group_list1.push_back(group0);
		capture_list2.push_back(value_ID_1);
		skip_spaces<Types::__WS>(pos);
	}
	skip_spaces<Types::__WS>(pos);
	value_RIGHT_CURLY_BRACKET = required<Types::RIGHT_CURLY_BRACKET>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("rule::f_binding", "RIGHT_CURLY_BRACKET"));
	Types::rule::f_binding result;
	::ISPA_STD::assign_compatible(result.f, value_ID);
	::ISPA_STD::assign_compatible(result.seq, capture_list2);
	::ISPA_STD::MatchResult<Types::rule::f_binding, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::ruleF_binding<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::rule::f_binding, ::Parser::Lexer::iterator>;
template auto Parser::Parser::ruleF_binding<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::rule::f_binding, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::ruleValueGroup(IT pos) -> ::ISPA_STD::MatchResult<Types::rule::value::group, IT> {
	::ISPA_STD::Node<Types::LEFT_PARENTHESIS> value_LEFT_PARENTHESIS;
	std::vector<::ISPA_STD::Node<Types::rule::value>> value_list_rule_value;
	::ISPA_STD::Node<Types::RIGHT_PARENTHESIS> value_RIGHT_PARENTHESIS;
	value_LEFT_PARENTHESIS = required<Types::LEFT_PARENTHESIS>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::LEFT_PARENTHESIS::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::QUANTIFIER::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::alternative::VERTICAL_LINE::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id, Tokens::rule::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("rule::value::group", "LEFT_PARENTHESIS"));
	skip_spaces<Types::__WS>(pos);
	value_list_rule_value = range<Types::rule::value, Types::__WS>(pos, [this](auto cursor) { return this->ruleValue(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_PARENTHESIS::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::QUANTIFIER::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::alternative::VERTICAL_LINE::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id, Tokens::rule::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("rule::value::group", "rule::value"));
	skip_spaces<Types::__WS>(pos);
	value_RIGHT_PARENTHESIS = required<Types::RIGHT_PARENTHESIS>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::RIGHT_PARENTHESIS::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::QUANTIFIER::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::alternative::VERTICAL_LINE::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id, Tokens::rule::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::QUANTIFIER::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::alternative::VERTICAL_LINE::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id, Tokens::rule::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("rule::value::group", "RIGHT_PARENTHESIS"));
	Types::rule::value::group result;
	::ISPA_STD::assign_compatible(result.value, value_list_rule_value);
	::ISPA_STD::MatchResult<Types::rule::value::group, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::ruleValueGroup<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::rule::value::group, ::Parser::Lexer::iterator>;
template auto Parser::Parser::ruleValueGroup<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::rule::value::group, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::ruleValueFail_capture(IT pos) -> ::ISPA_STD::MatchResult<Types::rule::value::fail_capture, IT> {
	::ISPA_STD::Node<Types::PERCENT_SIGN> value_PERCENT_SIGN;
	::ISPA_STD::Node<Types::name> value_name;
	value_PERCENT_SIGN = required<Types::PERCENT_SIGN>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::PERCENT_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::ID::id, Tokens::LEFT_PARENTHESIS::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::ID::id, Tokens::LEFT_PARENTHESIS::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("rule::value::fail_capture", "PERCENT_SIGN"));
	value_name = optional<Types::name>(pos, [this](auto cursor) { return this->name(cursor); });
	Types::rule::value::fail_capture result;
	::ISPA_STD::assign_compatible(result.value, value_name);
	::ISPA_STD::MatchResult<Types::rule::value::fail_capture, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::ruleValueFail_capture<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::rule::value::fail_capture, ::Parser::Lexer::iterator>;
template auto Parser::Parser::ruleValueFail_capture<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::rule::value::fail_capture, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::ruleAstFullPart(IT pos) -> ::ISPA_STD::MatchResult<Types::rule::ast::full::part, IT> {
	::ISPA_STD::Node<Types::ID> value_ID;
	::ISPA_STD::Node<Types::COLON> value_COLON;
	::ISPA_STD::Node<Types::expr> value_expr;
	value_ID = required<Types::ID>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::ID::id>, ISPA_STD::Recovery::Tokens<Tokens::COLON::id>, ISPA_STD::Recovery::Tokens<Tokens::ID::id, Tokens::RIGHT_CURLY_BRACKET::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("rule::ast::full::part", "ID"));
	skip_spaces<Types::__WS>(pos);
	value_COLON = required<Types::COLON>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::COLON::id>, ISPA_STD::Recovery::Tokens<Tokens::PY_RAW::id>, ISPA_STD::Recovery::Tokens<Tokens::ID::id, Tokens::RIGHT_CURLY_BRACKET::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("rule::ast::full::part", "COLON"));
	skip_spaces<Types::__WS>(pos);
	value_expr = required<Types::expr>(pos, [this](auto cursor) { return this->expr(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::PY_RAW::id>, ISPA_STD::Recovery::Tokens<Tokens::ID::id, Tokens::RIGHT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::ID::id, Tokens::RIGHT_CURLY_BRACKET::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("rule::ast::full::part", "expr"));
	Types::rule::ast::full::part result;
	::ISPA_STD::assign_compatible(result.key, value_ID);
	::ISPA_STD::assign_compatible(result.e, value_expr);
	::ISPA_STD::MatchResult<Types::rule::ast::full::part, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::ruleAstFullPart<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::rule::ast::full::part, ::Parser::Lexer::iterator>;
template auto Parser::Parser::ruleAstFullPart<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::rule::ast::full::part, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::expr(IT pos) -> ::ISPA_STD::MatchResult<Types::expr, IT> {
	::ISPA_STD::Node<Types::PY_RAW> value_PY_RAW;
	value_PY_RAW = required<Types::PY_RAW>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::PY_RAW::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id, Tokens::rule::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id, Tokens::rule::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("expr", "PY_RAW"));
	Types::expr result;
	::ISPA_STD::assign_compatible(result.value, value_PY_RAW);
	::ISPA_STD::MatchResult<Types::expr, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::expr<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::expr, ::Parser::Lexer::iterator>;
template auto Parser::Parser::expr<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::expr, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::ruleValueOne_capture(IT pos) -> ::ISPA_STD::MatchResult<Types::rule::value::one_capture, IT> {
	::ISPA_STD::Node<Types::rule::value::var_capture> value_rule_value_var_capture;
	::ISPA_STD::Node<Types::rule::value::ast_capture> value_rule_value_ast_capture;
	::ISPA_STD::Node<Types::rule::value::fail_capture> value_rule_value_fail_capture;
	::ISPA_STD::Node<Types::rule::value::pattern> value_rule_value_pattern;
	std::vector<::ISPA_STD::Node<Types::rule::value::alternative>> value_list_rule_value_alternative;
	::ISPA_STD::Node<Types::rule::value::counter> value_rule_value_counter;
	::ISPA_STD::Node<Types::rule::value::shared_counter_registration> value_rule_value_shared_counter_registration;
	value_rule_value_var_capture = optional<Types::rule::value::var_capture>(pos, [this](auto cursor) { return this->ruleValueVar_capture(cursor); });
	skip_spaces<Types::__WS>(pos);
	value_rule_value_ast_capture = optional<Types::rule::value::ast_capture>(pos, [this](auto cursor) { return this->ruleValueAst_capture(cursor); });
	skip_spaces<Types::__WS>(pos);
	value_rule_value_fail_capture = optional<Types::rule::value::fail_capture>(pos, [this](auto cursor) { return this->ruleValueFail_capture(cursor); });
	skip_spaces<Types::__WS>(pos);
	value_rule_value_pattern = required<Types::rule::value::pattern>(pos, [this](auto cursor) { return this->ruleValuePattern(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::ID::id, Tokens::LEFT_PARENTHESIS::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::QUANTIFIER::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::alternative::VERTICAL_LINE::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id, Tokens::rule::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("rule::value::one_capture", "rule::value::pattern"));
	skip_spaces<Types::__WS>(pos);
	value_list_rule_value_alternative = range_optional<Types::rule::value::alternative, Types::__WS>(pos, [this](auto cursor) { return this->ruleValueAlternative(cursor); });
	skip_spaces<Types::__WS>(pos);
	value_rule_value_counter = optional<Types::rule::value::counter>(pos, [this](auto cursor) { return this->ruleValueCounter(cursor); });
	skip_spaces<Types::__WS>(pos);
	value_rule_value_shared_counter_registration = optional<Types::rule::value::shared_counter_registration>(pos, [this](auto cursor) { return this->ruleValueShared_counter_registration(cursor); });
	Types::rule::value::one_capture result;
	::ISPA_STD::assign_compatible(result.v_cap, value_rule_value_var_capture);
	::ISPA_STD::assign_compatible(result.ast_cap, value_rule_value_ast_capture);
	::ISPA_STD::assign_compatible(result.fail_cap, value_rule_value_fail_capture);
	::ISPA_STD::assign_compatible(result.val, value_rule_value_pattern);
	::ISPA_STD::assign_compatible(result.alts, value_list_rule_value_alternative);
	::ISPA_STD::assign_compatible(result.quantifier, value_rule_value_counter);
	::ISPA_STD::assign_compatible(result.registration, value_rule_value_shared_counter_registration);
	::ISPA_STD::MatchResult<Types::rule::value::one_capture, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::ruleValueOne_capture<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::rule::value::one_capture, ::Parser::Lexer::iterator>;
template auto Parser::Parser::ruleValueOne_capture<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::rule::value::one_capture, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::rule(IT pos) -> ::ISPA_STD::MatchResult<Types::rule, IT> {
	::ISPA_STD::Node<Types::COLON> value_COLON;
	std::vector<::ISPA_STD::Node<Types::rule::value>> value_list_rule_value;
	::ISPA_STD::Node<Types::rule::ast> value_rule_ast;
	::ISPA_STD::Node<Types::rule::f_binding> value_rule_f_binding;
	std::vector<::ISPA_STD::Node<Types::rule::nested_rule>> value_list_rule_nested_rule;
	::ISPA_STD::Node<Types::SEMICOLON> value_SEMICOLON;
	value_COLON = required<Types::COLON>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::COLON::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::FAIL::id, Tokens::ID::id, Tokens::SEMICOLON::id, Tokens::grammar::modifier::AUTO::id, Tokens::rule::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("rule", "COLON"));
	skip_spaces<Types::__WS>(pos);
	value_list_rule_value = range<Types::rule::value, Types::__WS>(pos, [this](auto cursor) { return this->ruleValue(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::PERCENT_SIGN::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::FAIL::id, Tokens::ID::id, Tokens::SEMICOLON::id, Tokens::grammar::modifier::AUTO::id, Tokens::rule::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("rule", "rule::value"));
	skip_spaces<Types::__WS>(pos);
	value_rule_ast = optional<Types::rule::ast>(pos, [this](auto cursor) { return this->ruleAst(cursor); });
	skip_spaces<Types::__WS>(pos);
	value_rule_f_binding = optional<Types::rule::f_binding>(pos, [this](auto cursor) { return this->ruleF_binding(cursor); });
	skip_spaces<Types::__WS>(pos);
	value_list_rule_nested_rule = range_optional<Types::rule::nested_rule, Types::__WS>(pos, [this](auto cursor) { return this->ruleNested_rule(cursor); });
	skip_spaces<Types::__WS>(pos);
	value_SEMICOLON = required<Types::SEMICOLON>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::SEMICOLON::id>, ISPA_STD::Recovery::Tokens<Tokens::FAIL::id, Tokens::ID::id, Tokens::SEMICOLON::id, Tokens::grammar::modifier::AUTO::id, Tokens::rule::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::FAIL::id, Tokens::ID::id, Tokens::SEMICOLON::id, Tokens::grammar::modifier::AUTO::id, Tokens::rule::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("rule", "SEMICOLON"));
	Types::rule result;
	::ISPA_STD::assign_compatible(result.v, value_list_rule_value);
	::ISPA_STD::assign_compatible(result.ast_pointer, value_rule_ast);
	::ISPA_STD::assign_compatible(result.fail_pointer, value_rule_f_binding);
	::ISPA_STD::assign_compatible(result.nested, value_list_rule_nested_rule);
	::ISPA_STD::MatchResult<Types::rule, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::rule<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::rule, ::Parser::Lexer::iterator>;
template auto Parser::Parser::rule<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::rule, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::grammarModifier(IT pos) -> ::ISPA_STD::MatchResult<Types::grammar::modifier, IT> {
	::ISPA_STD::Node<Types::grammar::modifier::AUTO> value_grammar_modifier_AUTO;
	::ISPA_STD::Node<Types::grammar::modifier::MOD> value_grammar_modifier_MOD;
	::ISPA_STD::Node<Types::grammar::modifier::RIGHT_SQUARE_BRACKET> value_grammar_modifier_RIGHT_SQUARE_BRACKET;
	value_grammar_modifier_AUTO = required<Types::grammar::modifier::AUTO>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::grammar::modifier::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::grammar::modifier::MOD::id>, ISPA_STD::Recovery::Tokens<Tokens::ID::id, Tokens::grammar::modifier::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("grammar::modifier", "grammar::modifier::AUTO"));
	skip_spaces<Types::__WS>(pos);
	value_grammar_modifier_MOD = required<Types::grammar::modifier::MOD>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::grammar::modifier::MOD::id>, ISPA_STD::Recovery::Tokens<Tokens::grammar::modifier::RIGHT_SQUARE_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::ID::id, Tokens::grammar::modifier::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("grammar::modifier", "grammar::modifier::MOD"));
	skip_spaces<Types::__WS>(pos);
	value_grammar_modifier_RIGHT_SQUARE_BRACKET = required<Types::grammar::modifier::RIGHT_SQUARE_BRACKET>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::grammar::modifier::RIGHT_SQUARE_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::ID::id, Tokens::grammar::modifier::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::ID::id, Tokens::grammar::modifier::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("grammar::modifier", "grammar::modifier::RIGHT_SQUARE_BRACKET"));
	Types::grammar::modifier result;
	::ISPA_STD::assign_compatible(result.value, value_grammar_modifier_MOD);
	::ISPA_STD::MatchResult<Types::grammar::modifier, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::grammarModifier<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::grammar::modifier, ::Parser::Lexer::iterator>;
template auto Parser::Parser::grammarModifier<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::grammar::modifier, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::grammar(IT pos) -> ::ISPA_STD::MatchResult<Types::grammar, IT> {
	std::vector<::ISPA_STD::Node<Types::grammar::modifier>> value_list_grammar_modifier;
	::ISPA_STD::Node<Types::name> value_name;
	std::variant<std::monostate, ::ISPA_STD::Node<Types::rule>, ::ISPA_STD::Node<Types::advanced_rule>> choice0;
	bool matched0;
	::ISPA_STD::Node<Types::rule> value_rule;
	::ISPA_STD::Node<Types::advanced_rule> value_advanced_rule;
	value_list_grammar_modifier = range_optional<Types::grammar::modifier, Types::__WS>(pos, [this](auto cursor) { return this->grammarModifier(cursor); });
	skip_spaces<Types::__WS>(pos);
	value_name = required<Types::name>(pos, [this](auto cursor) { return this->name(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::ID::id>, ISPA_STD::Recovery::Tokens<Tokens::COLON::id, Tokens::LEFT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::FAIL::id, Tokens::ID::id, Tokens::SEMICOLON::id, Tokens::grammar::modifier::AUTO::id, Tokens::rule::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("grammar", "name"));
	skip_spaces<Types::__WS>(pos);
	// grammar `@  ( rule |  advanced_rule)`: choice; alternative selected by LL(1) lookahead
	matched0 = false;
	auto la0_1 = pos;
	switch ((*la0_1).kind()) {
		case Tokens::COLON::id: {
			value_rule = required<Types::rule>(la0_1, [this](auto cursor) { return this->rule(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::COLON::id, Tokens::LEFT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::FAIL::id, Tokens::ID::id, Tokens::SEMICOLON::id, Tokens::grammar::modifier::AUTO::id, Tokens::rule::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::FAIL::id, Tokens::ID::id, Tokens::SEMICOLON::id, Tokens::grammar::modifier::AUTO::id, Tokens::rule::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("grammar", "<group>"));
			choice0 = value_rule;
			matched0 = true;
			break;
		}
		case Tokens::LEFT_CURLY_BRACKET::id: {
			value_advanced_rule = required<Types::advanced_rule>(la0_1, [this](auto cursor) { return this->advanced_rule(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::COLON::id, Tokens::LEFT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::FAIL::id, Tokens::ID::id, Tokens::SEMICOLON::id, Tokens::grammar::modifier::AUTO::id, Tokens::rule::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::FAIL::id, Tokens::ID::id, Tokens::SEMICOLON::id, Tokens::grammar::modifier::AUTO::id, Tokens::rule::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("grammar", "<group>"));
			choice0 = value_advanced_rule;
			matched0 = true;
			break;
		}
	}
	pos = la0_1;
	if (!matched0) {
		raise_error(*pos, "ISPA match failure: expected one of: COLON, LEFT_CURLY_BRACKET");
		return {};
	}
	Types::grammar result;
	::ISPA_STD::assign_compatible(result.mod, value_list_grammar_modifier);
	::ISPA_STD::assign_compatible(result.name, value_name);
	::ISPA_STD::assign_compatible(result.entry, choice0);
	::ISPA_STD::MatchResult<Types::grammar, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::grammar<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::grammar, ::Parser::Lexer::iterator>;
template auto Parser::Parser::grammar<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::grammar, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::ruleValue(IT pos) -> ::ISPA_STD::MatchResult<Types::rule::value, IT> {
	std::variant<std::monostate, ::ISPA_STD::Node<Types::rule::value::one_capture>, ::ISPA_STD::Node<Types::rule::value::mul_capture>> choice0;
	bool matched0;
	::ISPA_STD::Node<Types::rule::value::one_capture> value_rule_value_one_capture;
	::ISPA_STD::Node<Types::rule::value::mul_capture> value_rule_value_mul_capture;
	// grammar `@  ( rule::value::one_capture |  rule::value::mul_capture)`: choice; alternative selected by LL(2) lookahead
	matched0 = false;
	auto la0_1 = pos;
	switch ((*la0_1).kind()) {
		case Tokens::AMPERSAND::id: {
			value_rule_value_one_capture = required<Types::rule::value::one_capture>(la0_1, [this](auto cursor) { return this->ruleValueOne_capture(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("rule::value", "<group>"));
			choice0 = value_rule_value_one_capture;
			matched0 = true;
			break;
		}
		case Tokens::COMMERCIAL_AT::id: {
			auto la0_2 = la0_1;
			++la0_2;
			skip_spaces<Types::__WS>(la0_2);
			switch ((*la0_2).kind()) {
				case Tokens::EQUALS_SIGN::id: {
					la0_2 = la0_1;
					value_rule_value_mul_capture = required<Types::rule::value::mul_capture>(la0_2, [this](auto cursor) { return this->ruleValueMul_capture(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("rule::value", "<group>"));
					choice0 = value_rule_value_mul_capture;
					matched0 = true;
					break;
				}
				case Tokens::ID::id: {
					la0_2 = la0_1;
					value_rule_value_one_capture = required<Types::rule::value::one_capture>(la0_2, [this](auto cursor) { return this->ruleValueOne_capture(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("rule::value", "<group>"));
					choice0 = value_rule_value_one_capture;
					matched0 = true;
					break;
				}
				case Tokens::LEFT_PARENTHESIS::id: {
					la0_2 = la0_1;
					value_rule_value_one_capture = required<Types::rule::value::one_capture>(la0_2, [this](auto cursor) { return this->ruleValueOne_capture(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("rule::value", "<group>"));
					choice0 = value_rule_value_one_capture;
					matched0 = true;
					break;
				}
				case Tokens::PERCENT_SIGN::id: {
					la0_2 = la0_1;
					value_rule_value_one_capture = required<Types::rule::value::one_capture>(la0_2, [this](auto cursor) { return this->ruleValueOne_capture(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("rule::value", "<group>"));
					choice0 = value_rule_value_one_capture;
					matched0 = true;
					break;
				}
				case Tokens::rule::value::ANY::id: {
					la0_2 = la0_1;
					value_rule_value_one_capture = required<Types::rule::value::one_capture>(la0_2, [this](auto cursor) { return this->ruleValueOne_capture(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("rule::value", "<group>"));
					choice0 = value_rule_value_one_capture;
					matched0 = true;
					break;
				}
				case Tokens::rule::value::CGROUP::id: {
					la0_2 = la0_1;
					value_rule_value_one_capture = required<Types::rule::value::one_capture>(la0_2, [this](auto cursor) { return this->ruleValueOne_capture(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("rule::value", "<group>"));
					choice0 = value_rule_value_one_capture;
					matched0 = true;
					break;
				}
				case Tokens::rule::value::NOSPACE::id: {
					la0_2 = la0_1;
					value_rule_value_one_capture = required<Types::rule::value::one_capture>(la0_2, [this](auto cursor) { return this->ruleValueOne_capture(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("rule::value", "<group>"));
					choice0 = value_rule_value_one_capture;
					matched0 = true;
					break;
				}
				case Tokens::rule::value::SPACE::id: {
					la0_2 = la0_1;
					value_rule_value_one_capture = required<Types::rule::value::one_capture>(la0_2, [this](auto cursor) { return this->ruleValueOne_capture(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("rule::value", "<group>"));
					choice0 = value_rule_value_one_capture;
					matched0 = true;
					break;
				}
				case Tokens::rule::value::STRING::id: {
					la0_2 = la0_1;
					value_rule_value_one_capture = required<Types::rule::value::one_capture>(la0_2, [this](auto cursor) { return this->ruleValueOne_capture(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("rule::value", "<group>"));
					choice0 = value_rule_value_one_capture;
					matched0 = true;
					break;
				}
				case Tokens::rule::value::dyn::DOLLAR_SIGN::id: {
					la0_2 = la0_1;
					value_rule_value_one_capture = required<Types::rule::value::one_capture>(la0_2, [this](auto cursor) { return this->ruleValueOne_capture(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("rule::value", "<group>"));
					choice0 = value_rule_value_one_capture;
					matched0 = true;
					break;
				}
			}
			if (!matched0) {
				la0_2 = la0_1;
			}
			la0_1 = la0_2;
			break;
		}
		case Tokens::ID::id: {
			value_rule_value_one_capture = required<Types::rule::value::one_capture>(la0_1, [this](auto cursor) { return this->ruleValueOne_capture(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("rule::value", "<group>"));
			choice0 = value_rule_value_one_capture;
			matched0 = true;
			break;
		}
		case Tokens::LEFT_PARENTHESIS::id: {
			value_rule_value_one_capture = required<Types::rule::value::one_capture>(la0_1, [this](auto cursor) { return this->ruleValueOne_capture(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("rule::value", "<group>"));
			choice0 = value_rule_value_one_capture;
			matched0 = true;
			break;
		}
		case Tokens::PERCENT_SIGN::id: {
			auto la0_2 = la0_1;
			++la0_2;
			skip_spaces<Types::__WS>(la0_2);
			switch ((*la0_2).kind()) {
				case Tokens::EQUALS_SIGN::id: {
					la0_2 = la0_1;
					value_rule_value_mul_capture = required<Types::rule::value::mul_capture>(la0_2, [this](auto cursor) { return this->ruleValueMul_capture(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("rule::value", "<group>"));
					choice0 = value_rule_value_mul_capture;
					matched0 = true;
					break;
				}
				case Tokens::ID::id: {
					la0_2 = la0_1;
					value_rule_value_one_capture = required<Types::rule::value::one_capture>(la0_2, [this](auto cursor) { return this->ruleValueOne_capture(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("rule::value", "<group>"));
					choice0 = value_rule_value_one_capture;
					matched0 = true;
					break;
				}
				case Tokens::LEFT_PARENTHESIS::id: {
					la0_2 = la0_1;
					value_rule_value_one_capture = required<Types::rule::value::one_capture>(la0_2, [this](auto cursor) { return this->ruleValueOne_capture(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("rule::value", "<group>"));
					choice0 = value_rule_value_one_capture;
					matched0 = true;
					break;
				}
				case Tokens::rule::value::ANY::id: {
					la0_2 = la0_1;
					value_rule_value_one_capture = required<Types::rule::value::one_capture>(la0_2, [this](auto cursor) { return this->ruleValueOne_capture(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("rule::value", "<group>"));
					choice0 = value_rule_value_one_capture;
					matched0 = true;
					break;
				}
				case Tokens::rule::value::CGROUP::id: {
					la0_2 = la0_1;
					value_rule_value_one_capture = required<Types::rule::value::one_capture>(la0_2, [this](auto cursor) { return this->ruleValueOne_capture(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("rule::value", "<group>"));
					choice0 = value_rule_value_one_capture;
					matched0 = true;
					break;
				}
				case Tokens::rule::value::NOSPACE::id: {
					la0_2 = la0_1;
					value_rule_value_one_capture = required<Types::rule::value::one_capture>(la0_2, [this](auto cursor) { return this->ruleValueOne_capture(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("rule::value", "<group>"));
					choice0 = value_rule_value_one_capture;
					matched0 = true;
					break;
				}
				case Tokens::rule::value::SPACE::id: {
					la0_2 = la0_1;
					value_rule_value_one_capture = required<Types::rule::value::one_capture>(la0_2, [this](auto cursor) { return this->ruleValueOne_capture(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("rule::value", "<group>"));
					choice0 = value_rule_value_one_capture;
					matched0 = true;
					break;
				}
				case Tokens::rule::value::STRING::id: {
					la0_2 = la0_1;
					value_rule_value_one_capture = required<Types::rule::value::one_capture>(la0_2, [this](auto cursor) { return this->ruleValueOne_capture(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("rule::value", "<group>"));
					choice0 = value_rule_value_one_capture;
					matched0 = true;
					break;
				}
				case Tokens::rule::value::dyn::DOLLAR_SIGN::id: {
					la0_2 = la0_1;
					value_rule_value_one_capture = required<Types::rule::value::one_capture>(la0_2, [this](auto cursor) { return this->ruleValueOne_capture(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("rule::value", "<group>"));
					choice0 = value_rule_value_one_capture;
					matched0 = true;
					break;
				}
			}
			if (!matched0) {
				la0_2 = la0_1;
			}
			la0_1 = la0_2;
			break;
		}
		case Tokens::rule::value::ANY::id: {
			value_rule_value_one_capture = required<Types::rule::value::one_capture>(la0_1, [this](auto cursor) { return this->ruleValueOne_capture(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("rule::value", "<group>"));
			choice0 = value_rule_value_one_capture;
			matched0 = true;
			break;
		}
		case Tokens::rule::value::CGROUP::id: {
			value_rule_value_one_capture = required<Types::rule::value::one_capture>(la0_1, [this](auto cursor) { return this->ruleValueOne_capture(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("rule::value", "<group>"));
			choice0 = value_rule_value_one_capture;
			matched0 = true;
			break;
		}
		case Tokens::rule::value::NOSPACE::id: {
			value_rule_value_one_capture = required<Types::rule::value::one_capture>(la0_1, [this](auto cursor) { return this->ruleValueOne_capture(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("rule::value", "<group>"));
			choice0 = value_rule_value_one_capture;
			matched0 = true;
			break;
		}
		case Tokens::rule::value::SPACE::id: {
			value_rule_value_one_capture = required<Types::rule::value::one_capture>(la0_1, [this](auto cursor) { return this->ruleValueOne_capture(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("rule::value", "<group>"));
			choice0 = value_rule_value_one_capture;
			matched0 = true;
			break;
		}
		case Tokens::rule::value::STRING::id: {
			value_rule_value_one_capture = required<Types::rule::value::one_capture>(la0_1, [this](auto cursor) { return this->ruleValueOne_capture(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("rule::value", "<group>"));
			choice0 = value_rule_value_one_capture;
			matched0 = true;
			break;
		}
		case Tokens::rule::value::dyn::DOLLAR_SIGN::id: {
			value_rule_value_one_capture = required<Types::rule::value::one_capture>(la0_1, [this](auto cursor) { return this->ruleValueOne_capture(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("rule::value", "<group>"));
			choice0 = value_rule_value_one_capture;
			matched0 = true;
			break;
		}
	}
	pos = la0_1;
	if (!matched0) {
		raise_error(*pos, "ISPA match failure: expected one of: AMPERSAND, COMMERCIAL_AT, ID, LEFT_PARENTHESIS, PERCENT_SIGN, rule.value.ANY, rule.value.CGROUP, rule.value.NOSPACE, rule.value.SPACE, rule.value.STRING, rule.value.dyn.DOLLAR_SIGN");
		return {};
	}
	Types::rule::value result;
	::ISPA_STD::assign_compatible(result.value, choice0);
	::ISPA_STD::MatchResult<Types::rule::value, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::ruleValue<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::rule::value, ::Parser::Lexer::iterator>;
template auto Parser::Parser::ruleValue<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::rule::value, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::ruleValueCounterBounded(IT pos) -> ::ISPA_STD::MatchResult<Types::rule::value::counter::bounded, IT> {
	::ISPA_STD::Node<Types::EQUALS_SIGN> value_EQUALS_SIGN;
	std::variant<std::monostate, ::ISPA_STD::Node<Types::NUMBER>, ::ISPA_STD::Node<Types::ID>, ::ISPA_STD::Node<Types::expr>> choice0;
	bool matched0;
	::ISPA_STD::Node<Types::NUMBER> value_NUMBER;
	::ISPA_STD::Node<Types::ID> value_ID;
	::ISPA_STD::Node<Types::expr> value_expr;
	value_EQUALS_SIGN = required<Types::EQUALS_SIGN>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::EQUALS_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::ID::id, Tokens::NUMBER::id, Tokens::PY_RAW::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id, Tokens::rule::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("rule::value::counter::bounded", "EQUALS_SIGN"));
	skip_spaces<Types::__WS>(pos);
	// grammar `@  ( NUMBER |  ID |  expr)`: choice; alternative selected by LL(1) lookahead
	matched0 = false;
	auto la0_1 = pos;
	switch ((*la0_1).kind()) {
		case Tokens::ID::id: {
			value_ID = required<Types::ID>(la0_1, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::ID::id, Tokens::NUMBER::id, Tokens::PY_RAW::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id, Tokens::rule::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id, Tokens::rule::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("rule::value::counter::bounded", "<group>"));
			choice0 = value_ID;
			matched0 = true;
			break;
		}
		case Tokens::NUMBER::id: {
			value_NUMBER = required<Types::NUMBER>(la0_1, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::ID::id, Tokens::NUMBER::id, Tokens::PY_RAW::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id, Tokens::rule::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id, Tokens::rule::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("rule::value::counter::bounded", "<group>"));
			choice0 = value_NUMBER;
			matched0 = true;
			break;
		}
		case Tokens::PY_RAW::id: {
			value_expr = required<Types::expr>(la0_1, [this](auto cursor) { return this->expr(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::ID::id, Tokens::NUMBER::id, Tokens::PY_RAW::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id, Tokens::rule::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id, Tokens::rule::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("rule::value::counter::bounded", "<group>"));
			choice0 = value_expr;
			matched0 = true;
			break;
		}
	}
	pos = la0_1;
	if (!matched0) {
		raise_error(*pos, "ISPA match failure: expected one of: NUMBER, ID, PY_RAW");
		return {};
	}
	Types::rule::value::counter::bounded result;
	::ISPA_STD::assign_compatible(result.value, choice0);
	::ISPA_STD::MatchResult<Types::rule::value::counter::bounded, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::ruleValueCounterBounded<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::rule::value::counter::bounded, ::Parser::Lexer::iterator>;
template auto Parser::Parser::ruleValueCounterBounded<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::rule::value::counter::bounded, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::param(IT pos) -> ::ISPA_STD::MatchResult<Types::param, IT> {
	::ISPA_STD::Node<Types::ID> value_ID;
	::ISPA_STD::Node<Types::COMMA> value_COMMA;
	::ISPA_STD::Node<Types::ID> value_ID_1;
	std::pair<::ISPA_STD::Node<Types::COMMA>, ::ISPA_STD::Node<Types::ID>> group0;
	std::vector<std::pair<::ISPA_STD::Node<Types::COMMA>, ::ISPA_STD::Node<Types::ID>>> group_list1;
	std::vector<::ISPA_STD::Node<Types::ID>> capture_list2;
	value_ID = required<Types::ID>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::ID::id>, ISPA_STD::Recovery::Tokens<Tokens::COMMA::id, Tokens::GREATER_THAN_SIGN::id, Tokens::RIGHT_PARENTHESIS::id>, ISPA_STD::Recovery::Tokens<Tokens::GREATER_THAN_SIGN::id, Tokens::RIGHT_PARENTHESIS::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("param", "ID"));
	skip_spaces<Types::__WS>(pos);
	// grammar ` ( COMMA  __WS?; @  ID)*;`: repeat while lookahead is in FIRST
	while (((*pos).kind() == Tokens::COMMA::id)) {
		value_COMMA = required<Types::COMMA>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::COMMA::id>, ISPA_STD::Recovery::Tokens<Tokens::GREATER_THAN_SIGN::id, Tokens::RIGHT_PARENTHESIS::id>, ISPA_STD::Recovery::Tokens<Tokens::GREATER_THAN_SIGN::id, Tokens::RIGHT_PARENTHESIS::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("param", "<group>"));
		skip_spaces<Types::__WS>(pos);
		value_ID_1 = required<Types::ID>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::COMMA::id>, ISPA_STD::Recovery::Tokens<Tokens::GREATER_THAN_SIGN::id, Tokens::RIGHT_PARENTHESIS::id>, ISPA_STD::Recovery::Tokens<Tokens::GREATER_THAN_SIGN::id, Tokens::RIGHT_PARENTHESIS::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("param", "<group>"));
		group0 = std::make_pair(value_COMMA, value_ID_1);
		group_list1.push_back(group0);
		capture_list2.push_back(value_ID_1);
		skip_spaces<Types::__WS>(pos);
	}
	Types::param result;
	::ISPA_STD::assign_compatible(result.first_p, value_ID);
	::ISPA_STD::assign_compatible(result.following_p, capture_list2);
	::ISPA_STD::MatchResult<Types::param, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::param<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::param, ::Parser::Lexer::iterator>;
template auto Parser::Parser::param<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::param, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::ruleValuePattern(IT pos) -> ::ISPA_STD::MatchResult<Types::rule::value::pattern, IT> {
	std::variant<std::monostate, ::ISPA_STD::Node<Types::name>, ::ISPA_STD::Node<Types::rule::value::group>, ::ISPA_STD::Node<Types::rule::value::dyn>, ::ISPA_STD::Node<Types::rule::value::STRING>, ::ISPA_STD::Node<Types::rule::value::CGROUP>, ::ISPA_STD::Node<Types::rule::value::ANY>, ::ISPA_STD::Node<Types::rule::value::SPACE>, ::ISPA_STD::Node<Types::rule::value::NOSPACE>> choice0;
	bool matched0;
	::ISPA_STD::Node<Types::name> value_name;
	::ISPA_STD::Node<Types::rule::value::group> value_rule_value_group;
	::ISPA_STD::Node<Types::rule::value::dyn> value_rule_value_dyn;
	::ISPA_STD::Node<Types::rule::value::STRING> value_rule_value_STRING;
	::ISPA_STD::Node<Types::rule::value::CGROUP> value_rule_value_CGROUP;
	::ISPA_STD::Node<Types::rule::value::ANY> value_rule_value_ANY;
	::ISPA_STD::Node<Types::rule::value::SPACE> value_rule_value_SPACE;
	::ISPA_STD::Node<Types::rule::value::NOSPACE> value_rule_value_NOSPACE;
	// grammar `@  ( name |  rule::value::group |  rule::value::dyn |  rule::value::STRING |  rule::value::CGROUP |  rule::value::ANY |  rule::value::SPACE |  rule::value::NOSPACE)`: choice; alternative selected by LL(1) lookahead
	matched0 = false;
	auto la0_1 = pos;
	switch ((*la0_1).kind()) {
		case Tokens::ID::id: {
			value_name = required<Types::name>(la0_1, [this](auto cursor) { return this->name(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::ID::id, Tokens::LEFT_PARENTHESIS::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::QUANTIFIER::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::alternative::VERTICAL_LINE::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id, Tokens::rule::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::QUANTIFIER::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::alternative::VERTICAL_LINE::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id, Tokens::rule::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("rule::value::pattern", "<group>"));
			choice0 = value_name;
			matched0 = true;
			break;
		}
		case Tokens::LEFT_PARENTHESIS::id: {
			value_rule_value_group = required<Types::rule::value::group>(la0_1, [this](auto cursor) { return this->ruleValueGroup(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::ID::id, Tokens::LEFT_PARENTHESIS::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::QUANTIFIER::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::alternative::VERTICAL_LINE::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id, Tokens::rule::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::QUANTIFIER::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::alternative::VERTICAL_LINE::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id, Tokens::rule::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("rule::value::pattern", "<group>"));
			choice0 = value_rule_value_group;
			matched0 = true;
			break;
		}
		case Tokens::rule::value::ANY::id: {
			value_rule_value_ANY = required<Types::rule::value::ANY>(la0_1, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::ID::id, Tokens::LEFT_PARENTHESIS::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::QUANTIFIER::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::alternative::VERTICAL_LINE::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id, Tokens::rule::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::QUANTIFIER::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::alternative::VERTICAL_LINE::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id, Tokens::rule::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("rule::value::pattern", "<group>"));
			choice0 = value_rule_value_ANY;
			matched0 = true;
			break;
		}
		case Tokens::rule::value::CGROUP::id: {
			value_rule_value_CGROUP = required<Types::rule::value::CGROUP>(la0_1, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::ID::id, Tokens::LEFT_PARENTHESIS::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::QUANTIFIER::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::alternative::VERTICAL_LINE::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id, Tokens::rule::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::QUANTIFIER::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::alternative::VERTICAL_LINE::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id, Tokens::rule::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("rule::value::pattern", "<group>"));
			choice0 = value_rule_value_CGROUP;
			matched0 = true;
			break;
		}
		case Tokens::rule::value::NOSPACE::id: {
			value_rule_value_NOSPACE = required<Types::rule::value::NOSPACE>(la0_1, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::ID::id, Tokens::LEFT_PARENTHESIS::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::QUANTIFIER::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::alternative::VERTICAL_LINE::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id, Tokens::rule::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::QUANTIFIER::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::alternative::VERTICAL_LINE::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id, Tokens::rule::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("rule::value::pattern", "<group>"));
			choice0 = value_rule_value_NOSPACE;
			matched0 = true;
			break;
		}
		case Tokens::rule::value::SPACE::id: {
			value_rule_value_SPACE = required<Types::rule::value::SPACE>(la0_1, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::ID::id, Tokens::LEFT_PARENTHESIS::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::QUANTIFIER::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::alternative::VERTICAL_LINE::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id, Tokens::rule::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::QUANTIFIER::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::alternative::VERTICAL_LINE::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id, Tokens::rule::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("rule::value::pattern", "<group>"));
			choice0 = value_rule_value_SPACE;
			matched0 = true;
			break;
		}
		case Tokens::rule::value::STRING::id: {
			value_rule_value_STRING = required<Types::rule::value::STRING>(la0_1, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::ID::id, Tokens::LEFT_PARENTHESIS::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::QUANTIFIER::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::alternative::VERTICAL_LINE::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id, Tokens::rule::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::QUANTIFIER::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::alternative::VERTICAL_LINE::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id, Tokens::rule::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("rule::value::pattern", "<group>"));
			choice0 = value_rule_value_STRING;
			matched0 = true;
			break;
		}
		case Tokens::rule::value::dyn::DOLLAR_SIGN::id: {
			value_rule_value_dyn = required<Types::rule::value::dyn>(la0_1, [this](auto cursor) { return this->ruleValueDyn(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::ID::id, Tokens::LEFT_PARENTHESIS::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::QUANTIFIER::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::alternative::VERTICAL_LINE::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id, Tokens::rule::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::QUANTIFIER::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::alternative::VERTICAL_LINE::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id, Tokens::rule::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("rule::value::pattern", "<group>"));
			choice0 = value_rule_value_dyn;
			matched0 = true;
			break;
		}
	}
	pos = la0_1;
	if (!matched0) {
		raise_error(*pos, "ISPA match failure: expected one of: ID, LEFT_PARENTHESIS, rule.value.dyn.DOLLAR_SIGN, rule.value.STRING, rule.value.CGROUP, rule.value.ANY, rule.value.SPACE, rule.value.NOSPACE");
		return {};
	}
	Types::rule::value::pattern result;
	::ISPA_STD::assign_compatible(result.value, choice0);
	::ISPA_STD::MatchResult<Types::rule::value::pattern, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::ruleValuePattern<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::rule::value::pattern, ::Parser::Lexer::iterator>;
template auto Parser::Parser::ruleValuePattern<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::rule::value::pattern, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::template_params(IT pos) -> ::ISPA_STD::MatchResult<Types::template_params, IT> {
	::ISPA_STD::Node<Types::template_params::LESS_THAN_SIGN> value_template_params_LESS_THAN_SIGN;
	::ISPA_STD::Node<Types::param> value_param;
	::ISPA_STD::Node<Types::GREATER_THAN_SIGN> value_GREATER_THAN_SIGN;
	value_template_params_LESS_THAN_SIGN = required<Types::template_params::LESS_THAN_SIGN>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::template_params::LESS_THAN_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::GREATER_THAN_SIGN::id, Tokens::ID::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COLON::id, Tokens::COMMERCIAL_AT::id, Tokens::GREATER_THAN_SIGN::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::PY_RAW::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::QUANTIFIER::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::alternative::VERTICAL_LINE::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id, Tokens::rule::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("template_params", "template_params::LESS_THAN_SIGN"));
	skip_spaces<Types::__WS>(pos);
	value_param = optional<Types::param>(pos, [this](auto cursor) { return this->param(cursor); });
	skip_spaces<Types::__WS>(pos);
	value_GREATER_THAN_SIGN = required<Types::GREATER_THAN_SIGN>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::GREATER_THAN_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COLON::id, Tokens::COMMERCIAL_AT::id, Tokens::GREATER_THAN_SIGN::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::PY_RAW::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::QUANTIFIER::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::alternative::VERTICAL_LINE::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id, Tokens::rule::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COLON::id, Tokens::COMMERCIAL_AT::id, Tokens::GREATER_THAN_SIGN::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::PY_RAW::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::QUANTIFIER::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::alternative::VERTICAL_LINE::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id, Tokens::rule::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("template_params", "GREATER_THAN_SIGN"));
	Types::template_params result;
	::ISPA_STD::assign_compatible(result.value, value_param);
	::ISPA_STD::MatchResult<Types::template_params, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::template_params<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::template_params, ::Parser::Lexer::iterator>;
template auto Parser::Parser::template_params<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::template_params, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::fail_block(IT pos) -> ::ISPA_STD::MatchResult<Types::fail_block, IT> {
	::ISPA_STD::Node<Types::FAIL> value_FAIL;
	::ISPA_STD::Node<Types::name> value_name;
	::ISPA_STD::Node<Types::stmt> value_stmt;
	value_FAIL = required<Types::FAIL>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::FAIL::id>, ISPA_STD::Recovery::Tokens<Tokens::ID::id>, ISPA_STD::Recovery::Tokens<Tokens::FAIL::id, Tokens::ID::id, Tokens::grammar::modifier::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("fail_block", "FAIL"));
	skip_spaces<Types::__WS>(pos);
	value_name = required<Types::name>(pos, [this](auto cursor) { return this->name(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::ID::id>, ISPA_STD::Recovery::Tokens<Tokens::PY_RAW::id>, ISPA_STD::Recovery::Tokens<Tokens::FAIL::id, Tokens::ID::id, Tokens::grammar::modifier::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("fail_block", "name"));
	skip_spaces<Types::__WS>(pos);
	value_stmt = required<Types::stmt>(pos, [this](auto cursor) { return this->stmt(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::PY_RAW::id>, ISPA_STD::Recovery::Tokens<Tokens::FAIL::id, Tokens::ID::id, Tokens::grammar::modifier::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::FAIL::id, Tokens::ID::id, Tokens::grammar::modifier::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("fail_block", "stmt"));
	Types::fail_block result;
	::ISPA_STD::assign_compatible(result.name, value_name);
	::ISPA_STD::assign_compatible(result.val, value_stmt);
	::ISPA_STD::MatchResult<Types::fail_block, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::fail_block<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::fail_block, ::Parser::Lexer::iterator>;
template auto Parser::Parser::fail_block<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::fail_block, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::ruleAstAbbr(IT pos) -> ::ISPA_STD::MatchResult<Types::rule::ast::abbr, IT> {
	::ISPA_STD::Node<Types::COMMERCIAL_AT> value_COMMERCIAL_AT;
	::ISPA_STD::Node<Types::LEFT_CURLY_BRACKET> value_LEFT_CURLY_BRACKET;
	::ISPA_STD::Node<Types::ID> value_ID;
	::ISPA_STD::Node<Types::COMMA> value_COMMA;
	::ISPA_STD::Node<Types::ID> value_ID_1;
	std::pair<::ISPA_STD::Node<Types::COMMA>, ::ISPA_STD::Node<Types::ID>> group0;
	std::vector<std::pair<::ISPA_STD::Node<Types::COMMA>, ::ISPA_STD::Node<Types::ID>>> group_list1;
	std::vector<::ISPA_STD::Node<Types::ID>> capture_list2;
	::ISPA_STD::Node<Types::RIGHT_CURLY_BRACKET> value_RIGHT_CURLY_BRACKET;
	value_COMMERCIAL_AT = required<Types::COMMERCIAL_AT>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::COMMERCIAL_AT::id>, ISPA_STD::Recovery::Tokens<Tokens::LEFT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::PERCENT_SIGN::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("rule::ast::abbr", "COMMERCIAL_AT"));
	skip_spaces<Types::__WS>(pos);
	value_LEFT_CURLY_BRACKET = required<Types::LEFT_CURLY_BRACKET>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::LEFT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::ID::id>, ISPA_STD::Recovery::Tokens<Tokens::PERCENT_SIGN::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("rule::ast::abbr", "LEFT_CURLY_BRACKET"));
	skip_spaces<Types::__WS>(pos);
	value_ID = required<Types::ID>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::ID::id>, ISPA_STD::Recovery::Tokens<Tokens::COMMA::id, Tokens::RIGHT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::PERCENT_SIGN::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("rule::ast::abbr", "ID"));
	skip_spaces<Types::__WS>(pos);
	// grammar ` ( COMMA  __WS?; @  ID)*;`: repeat while lookahead is in FIRST
	while (((*pos).kind() == Tokens::COMMA::id)) {
		value_COMMA = required<Types::COMMA>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::COMMA::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::PERCENT_SIGN::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("rule::ast::abbr", "<group>"));
		skip_spaces<Types::__WS>(pos);
		value_ID_1 = required<Types::ID>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::COMMA::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::PERCENT_SIGN::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("rule::ast::abbr", "<group>"));
		group0 = std::make_pair(value_COMMA, value_ID_1);
		group_list1.push_back(group0);
		capture_list2.push_back(value_ID_1);
		skip_spaces<Types::__WS>(pos);
	}
	skip_spaces<Types::__WS>(pos);
	value_RIGHT_CURLY_BRACKET = required<Types::RIGHT_CURLY_BRACKET>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::PERCENT_SIGN::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::PERCENT_SIGN::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("rule::ast::abbr", "RIGHT_CURLY_BRACKET"));
	Types::rule::ast::abbr result;
	::ISPA_STD::assign_compatible(result.f, value_ID);
	::ISPA_STD::assign_compatible(result.seq, capture_list2);
	::ISPA_STD::MatchResult<Types::rule::ast::abbr, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::ruleAstAbbr<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::rule::ast::abbr, ::Parser::Lexer::iterator>;
template auto Parser::Parser::ruleAstAbbr<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::rule::ast::abbr, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::params(IT pos) -> ::ISPA_STD::MatchResult<Types::params, IT> {
	::ISPA_STD::Node<Types::GREATER_THAN_SIGN> value_GREATER_THAN_SIGN;
	::ISPA_STD::Node<Types::LEFT_PARENTHESIS> value_LEFT_PARENTHESIS;
	::ISPA_STD::Node<Types::param> value_param;
	::ISPA_STD::Node<Types::RIGHT_PARENTHESIS> value_RIGHT_PARENTHESIS;
	value_GREATER_THAN_SIGN = required<Types::GREATER_THAN_SIGN>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::GREATER_THAN_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::LEFT_PARENTHESIS::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COLON::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::PY_RAW::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::QUANTIFIER::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::alternative::VERTICAL_LINE::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id, Tokens::rule::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("params", "GREATER_THAN_SIGN"));
	skip_spaces<Types::__WS>(pos);
	value_LEFT_PARENTHESIS = required<Types::LEFT_PARENTHESIS>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::LEFT_PARENTHESIS::id>, ISPA_STD::Recovery::Tokens<Tokens::ID::id, Tokens::RIGHT_PARENTHESIS::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COLON::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::PY_RAW::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::QUANTIFIER::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::alternative::VERTICAL_LINE::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id, Tokens::rule::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("params", "LEFT_PARENTHESIS"));
	skip_spaces<Types::__WS>(pos);
	value_param = optional<Types::param>(pos, [this](auto cursor) { return this->param(cursor); });
	skip_spaces<Types::__WS>(pos);
	value_RIGHT_PARENTHESIS = required<Types::RIGHT_PARENTHESIS>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::RIGHT_PARENTHESIS::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COLON::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::PY_RAW::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::QUANTIFIER::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::alternative::VERTICAL_LINE::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id, Tokens::rule::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COLON::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::PY_RAW::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::QUANTIFIER::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::alternative::VERTICAL_LINE::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id, Tokens::rule::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("params", "RIGHT_PARENTHESIS"));
	Types::params result;
	::ISPA_STD::assign_compatible(result.value, value_param);
	::ISPA_STD::MatchResult<Types::params, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::params<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::params, ::Parser::Lexer::iterator>;
template auto Parser::Parser::params<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::params, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::ruleValueAlternative(IT pos) -> ::ISPA_STD::MatchResult<Types::rule::value::alternative, IT> {
	::ISPA_STD::Node<Types::rule::value::alternative::VERTICAL_LINE> value_rule_value_alternative_VERTICAL_LINE;
	::ISPA_STD::Node<Types::rule::value::pattern> value_rule_value_pattern;
	value_rule_value_alternative_VERTICAL_LINE = required<Types::rule::value::alternative::VERTICAL_LINE>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::rule::value::alternative::VERTICAL_LINE::id>, ISPA_STD::Recovery::Tokens<Tokens::ID::id, Tokens::LEFT_PARENTHESIS::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::QUANTIFIER::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::alternative::VERTICAL_LINE::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id, Tokens::rule::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("rule::value::alternative", "rule::value::alternative::VERTICAL_LINE"));
	skip_spaces<Types::__WS>(pos);
	value_rule_value_pattern = required<Types::rule::value::pattern>(pos, [this](auto cursor) { return this->ruleValuePattern(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::ID::id, Tokens::LEFT_PARENTHESIS::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::QUANTIFIER::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::alternative::VERTICAL_LINE::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id, Tokens::rule::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::QUANTIFIER::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::alternative::VERTICAL_LINE::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id, Tokens::rule::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("rule::value::alternative", "rule::value::pattern"));
	Types::rule::value::alternative result;
	::ISPA_STD::assign_compatible(result.value, value_rule_value_pattern);
	::ISPA_STD::MatchResult<Types::rule::value::alternative, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::ruleValueAlternative<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::rule::value::alternative, ::Parser::Lexer::iterator>;
template auto Parser::Parser::ruleValueAlternative<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::rule::value::alternative, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::ruleAstFull(IT pos) -> ::ISPA_STD::MatchResult<Types::rule::ast::full, IT> {
	::ISPA_STD::Node<Types::AMPERSAND> value_AMPERSAND;
	::ISPA_STD::Node<Types::LEFT_CURLY_BRACKET> value_LEFT_CURLY_BRACKET;
	std::vector<::ISPA_STD::Node<Types::rule::ast::full::part>> value_list_rule_ast_full_part;
	::ISPA_STD::Node<Types::RIGHT_CURLY_BRACKET> value_RIGHT_CURLY_BRACKET;
	value_AMPERSAND = required<Types::AMPERSAND>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id>, ISPA_STD::Recovery::Tokens<Tokens::LEFT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::PERCENT_SIGN::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("rule::ast::full", "AMPERSAND"));
	skip_spaces<Types::__WS>(pos);
	value_LEFT_CURLY_BRACKET = required<Types::LEFT_CURLY_BRACKET>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::LEFT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::ID::id>, ISPA_STD::Recovery::Tokens<Tokens::PERCENT_SIGN::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("rule::ast::full", "LEFT_CURLY_BRACKET"));
	skip_spaces<Types::__WS>(pos);
	value_list_rule_ast_full_part = range<Types::rule::ast::full::part, Types::__WS>(pos, [this](auto cursor) { return this->ruleAstFullPart(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::ID::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::PERCENT_SIGN::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("rule::ast::full", "rule::ast::full::part"));
	skip_spaces<Types::__WS>(pos);
	value_RIGHT_CURLY_BRACKET = required<Types::RIGHT_CURLY_BRACKET>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::PERCENT_SIGN::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::PERCENT_SIGN::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("rule::ast::full", "RIGHT_CURLY_BRACKET"));
	Types::rule::ast::full result;
	::ISPA_STD::assign_compatible(result.value, value_list_rule_ast_full_part);
	::ISPA_STD::MatchResult<Types::rule::ast::full, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::ruleAstFull<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::rule::ast::full, ::Parser::Lexer::iterator>;
template auto Parser::Parser::ruleAstFull<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::rule::ast::full, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::forward_declaration(IT pos) -> ::ISPA_STD::MatchResult<Types::forward_declaration, IT> {
	::ISPA_STD::Node<Types::PY_RAW> value_PY_RAW;
	value_PY_RAW = required<Types::PY_RAW>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::PY_RAW::id>, ISPA_STD::Recovery::Tokens<Tokens::PY_RAW::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::advanced_rule::dep_decl::DEPENDS::id, Tokens::advanced_rule::regular_match::MATCH::id>, ISPA_STD::Recovery::Tokens<Tokens::PY_RAW::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::advanced_rule::dep_decl::DEPENDS::id, Tokens::advanced_rule::regular_match::MATCH::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("forward_declaration", "PY_RAW"));
	Types::forward_declaration result;
	::ISPA_STD::MatchResult<Types::forward_declaration, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::forward_declaration<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::forward_declaration, ::Parser::Lexer::iterator>;
template auto Parser::Parser::forward_declaration<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::forward_declaration, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::name(IT pos) -> ::ISPA_STD::MatchResult<Types::name, IT> {
	::ISPA_STD::Node<Types::ID> value_ID;
	::ISPA_STD::Node<Types::AUTO> value_AUTO;
	::ISPA_STD::Node<Types::ID> value_ID_1;
	std::pair<::ISPA_STD::Node<Types::AUTO>, ::ISPA_STD::Node<Types::ID>> group0;
	std::vector<std::pair<::ISPA_STD::Node<Types::AUTO>, ::ISPA_STD::Node<Types::ID>>> group_list1;
	std::vector<::ISPA_STD::Node<Types::ID>> capture_list2;
	::ISPA_STD::Node<Types::template_params> value_template_params;
	::ISPA_STD::Node<Types::params> value_params;
	value_ID = required<Types::ID>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::ID::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COLON::id, Tokens::COMMERCIAL_AT::id, Tokens::GREATER_THAN_SIGN::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::PY_RAW::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::QUANTIFIER::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::alternative::VERTICAL_LINE::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id, Tokens::rule::value::shared_counter_registration::AUTO::id, Tokens::template_params::LESS_THAN_SIGN::id, ISPA_STD::Recovery::EndOfInput>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COLON::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::PY_RAW::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::QUANTIFIER::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::alternative::VERTICAL_LINE::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id, Tokens::rule::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("name", "ID"));
	skip_spaces<Types::__WS>(pos);
	// grammar ` ( AUTO  __WS?; @  ID)*;`: repeat while lookahead is in FIRST
	while (((*pos).kind() == Tokens::AUTO::id)) {
		value_AUTO = required<Types::AUTO>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COLON::id, Tokens::COMMERCIAL_AT::id, Tokens::GREATER_THAN_SIGN::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::PY_RAW::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::QUANTIFIER::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::alternative::VERTICAL_LINE::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id, Tokens::rule::value::shared_counter_registration::AUTO::id, Tokens::template_params::LESS_THAN_SIGN::id, ISPA_STD::Recovery::EndOfInput>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COLON::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::PY_RAW::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::QUANTIFIER::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::alternative::VERTICAL_LINE::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id, Tokens::rule::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("name", "<group>"));
		skip_spaces<Types::__WS>(pos);
		value_ID_1 = required<Types::ID>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COLON::id, Tokens::COMMERCIAL_AT::id, Tokens::GREATER_THAN_SIGN::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::PY_RAW::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::QUANTIFIER::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::alternative::VERTICAL_LINE::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id, Tokens::rule::value::shared_counter_registration::AUTO::id, Tokens::template_params::LESS_THAN_SIGN::id, ISPA_STD::Recovery::EndOfInput>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COLON::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::PY_RAW::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::QUANTIFIER::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::alternative::VERTICAL_LINE::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id, Tokens::rule::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("name", "<group>"));
		group0 = std::make_pair(value_AUTO, value_ID_1);
		group_list1.push_back(group0);
		capture_list2.push_back(value_ID_1);
		skip_spaces<Types::__WS>(pos);
	}
	skip_spaces<Types::__WS>(pos);
	value_template_params = optional<Types::template_params>(pos, [this](auto cursor) { return this->template_params(cursor); });
	skip_spaces<Types::__WS>(pos);
	value_params = optional<Types::params>(pos, [this](auto cursor) { return this->params(cursor); });
	Types::name result;
	::ISPA_STD::assign_compatible(result.primary, value_ID);
	::ISPA_STD::assign_compatible(result.nested, capture_list2);
	::ISPA_STD::assign_compatible(result.temp_params, value_template_params);
	::ISPA_STD::assign_compatible(result.param, value_params);
	::ISPA_STD::MatchResult<Types::name, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::name<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::name, ::Parser::Lexer::iterator>;
template auto Parser::Parser::name<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::name, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::stmt(IT pos) -> ::ISPA_STD::MatchResult<Types::stmt, IT> {
	::ISPA_STD::Node<Types::PY_RAW> value_PY_RAW;
	value_PY_RAW = required<Types::PY_RAW>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::PY_RAW::id>, ISPA_STD::Recovery::Tokens<Tokens::FAIL::id, Tokens::ID::id, Tokens::PY_RAW::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::advanced_rule::regular_match::MATCH::id, Tokens::grammar::modifier::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::FAIL::id, Tokens::ID::id, Tokens::PY_RAW::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::advanced_rule::regular_match::MATCH::id, Tokens::grammar::modifier::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("stmt", "PY_RAW"));
	Types::stmt result;
	::ISPA_STD::assign_compatible(result.value, value_PY_RAW);
	::ISPA_STD::MatchResult<Types::stmt, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::stmt<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::stmt, ::Parser::Lexer::iterator>;
template auto Parser::Parser::stmt<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::stmt, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::advanced_ruleFail_call(IT pos) -> ::ISPA_STD::MatchResult<Types::advanced_rule::fail_call, IT> {
	::ISPA_STD::Node<Types::FAIL> value_FAIL;
	::ISPA_STD::Node<Types::name> value_name;
	value_FAIL = required<Types::FAIL>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::FAIL::id>, ISPA_STD::Recovery::Tokens<Tokens::ID::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("advanced_rule::fail_call", "FAIL"));
	skip_spaces<Types::__WS>(pos);
	value_name = required<Types::name>(pos, [this](auto cursor) { return this->name(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::ID::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("advanced_rule::fail_call", "name"));
	Types::advanced_rule::fail_call result;
	::ISPA_STD::assign_compatible(result.value, value_name);
	::ISPA_STD::MatchResult<Types::advanced_rule::fail_call, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::advanced_ruleFail_call<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::advanced_rule::fail_call, ::Parser::Lexer::iterator>;
template auto Parser::Parser::advanced_ruleFail_call<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::advanced_rule::fail_call, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::ruleAstSingle_value(IT pos) -> ::ISPA_STD::MatchResult<Types::rule::ast::single_value, IT> {
	::ISPA_STD::Node<Types::LEFT_CURLY_BRACKET> value_LEFT_CURLY_BRACKET;
	std::variant<std::monostate, ::ISPA_STD::Node<Types::expr>, ::ISPA_STD::Node<Types::COMMERCIAL_AT>> choice0;
	bool matched0;
	::ISPA_STD::Node<Types::expr> value_expr;
	::ISPA_STD::Node<Types::COMMERCIAL_AT> value_COMMERCIAL_AT;
	::ISPA_STD::Node<Types::RIGHT_CURLY_BRACKET> value_RIGHT_CURLY_BRACKET;
	value_LEFT_CURLY_BRACKET = required<Types::LEFT_CURLY_BRACKET>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::LEFT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::COMMERCIAL_AT::id, Tokens::PY_RAW::id>, ISPA_STD::Recovery::Tokens<Tokens::PERCENT_SIGN::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("rule::ast::single_value", "LEFT_CURLY_BRACKET"));
	skip_spaces<Types::__WS>(pos);
	// grammar `@  ( expr |  COMMERCIAL_AT)`: choice; alternative selected by LL(1) lookahead
	matched0 = false;
	auto la0_1 = pos;
	switch ((*la0_1).kind()) {
		case Tokens::COMMERCIAL_AT::id: {
			value_COMMERCIAL_AT = required<Types::COMMERCIAL_AT>(la0_1, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::COMMERCIAL_AT::id, Tokens::PY_RAW::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::PERCENT_SIGN::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("rule::ast::single_value", "<group>"));
			choice0 = value_COMMERCIAL_AT;
			matched0 = true;
			break;
		}
		case Tokens::PY_RAW::id: {
			value_expr = required<Types::expr>(la0_1, [this](auto cursor) { return this->expr(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::COMMERCIAL_AT::id, Tokens::PY_RAW::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::PERCENT_SIGN::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("rule::ast::single_value", "<group>"));
			choice0 = value_expr;
			matched0 = true;
			break;
		}
	}
	pos = la0_1;
	if (!matched0) {
		raise_error(*pos, "ISPA match failure: expected one of: PY_RAW, COMMERCIAL_AT");
		return {};
	}
	skip_spaces<Types::__WS>(pos);
	value_RIGHT_CURLY_BRACKET = required<Types::RIGHT_CURLY_BRACKET>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::PERCENT_SIGN::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::PERCENT_SIGN::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("rule::ast::single_value", "RIGHT_CURLY_BRACKET"));
	Types::rule::ast::single_value result;
	::ISPA_STD::assign_compatible(result.value, choice0);
	::ISPA_STD::MatchResult<Types::rule::ast::single_value, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::ruleAstSingle_value<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::rule::ast::single_value, ::Parser::Lexer::iterator>;
template auto Parser::Parser::ruleAstSingle_value<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::rule::ast::single_value, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::advanced_ruleDep_decl(IT pos) -> ::ISPA_STD::MatchResult<Types::advanced_rule::dep_decl, IT> {
	::ISPA_STD::Node<Types::advanced_rule::dep_decl::DEPENDS> value_advanced_rule_dep_decl_DEPENDS;
	::ISPA_STD::Node<Types::forward_declaration> value_forward_declaration;
	value_advanced_rule_dep_decl_DEPENDS = required<Types::advanced_rule::dep_decl::DEPENDS>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::advanced_rule::dep_decl::DEPENDS::id>, ISPA_STD::Recovery::Tokens<Tokens::PY_RAW::id>, ISPA_STD::Recovery::Tokens<Tokens::PY_RAW::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::advanced_rule::dep_decl::DEPENDS::id, Tokens::advanced_rule::regular_match::MATCH::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("advanced_rule::dep_decl", "advanced_rule::dep_decl::DEPENDS"));
	skip_spaces<Types::__WS>(pos);
	value_forward_declaration = required<Types::forward_declaration>(pos, [this](auto cursor) { return this->forward_declaration(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::PY_RAW::id>, ISPA_STD::Recovery::Tokens<Tokens::PY_RAW::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::advanced_rule::dep_decl::DEPENDS::id, Tokens::advanced_rule::regular_match::MATCH::id>, ISPA_STD::Recovery::Tokens<Tokens::PY_RAW::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::advanced_rule::dep_decl::DEPENDS::id, Tokens::advanced_rule::regular_match::MATCH::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("advanced_rule::dep_decl", "forward_declaration"));
	Types::advanced_rule::dep_decl result;
	::ISPA_STD::assign_compatible(result.value, value_forward_declaration);
	::ISPA_STD::MatchResult<Types::advanced_rule::dep_decl, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::advanced_ruleDep_decl<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::advanced_rule::dep_decl, ::Parser::Lexer::iterator>;
template auto Parser::Parser::advanced_ruleDep_decl<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::advanced_rule::dep_decl, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::ruleValueShared_counter_registration(IT pos) -> ::ISPA_STD::MatchResult<Types::rule::value::shared_counter_registration, IT> {
	::ISPA_STD::Node<Types::rule::value::shared_counter_registration::AUTO> value_rule_value_shared_counter_registration_AUTO;
	::ISPA_STD::Node<Types::ID> value_ID;
	value_rule_value_shared_counter_registration_AUTO = required<Types::rule::value::shared_counter_registration::AUTO>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::rule::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::ID::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("rule::value::shared_counter_registration", "rule::value::shared_counter_registration::AUTO"));
	skip_spaces<Types::__WS>(pos);
	value_ID = required<Types::ID>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::ID::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::rule::nested_rule::NUMBER_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("rule::value::shared_counter_registration", "ID"));
	Types::rule::value::shared_counter_registration result;
	::ISPA_STD::assign_compatible(result.value, value_ID);
	::ISPA_STD::MatchResult<Types::rule::value::shared_counter_registration, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::ruleValueShared_counter_registration<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::rule::value::shared_counter_registration, ::Parser::Lexer::iterator>;
template auto Parser::Parser::ruleValueShared_counter_registration<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::rule::value::shared_counter_registration, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::explicit_expr(IT pos) -> ::ISPA_STD::MatchResult<Types::explicit_expr, IT> {
	::ISPA_STD::Node<Types::LEFT_PARENTHESIS> value_LEFT_PARENTHESIS;
	::ISPA_STD::Node<Types::expr> value_expr;
	::ISPA_STD::Node<Types::RIGHT_PARENTHESIS> value_RIGHT_PARENTHESIS;
	value_LEFT_PARENTHESIS = required<Types::LEFT_PARENTHESIS>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::LEFT_PARENTHESIS::id>, ISPA_STD::Recovery::Tokens<Tokens::PY_RAW::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("explicit_expr", "LEFT_PARENTHESIS"));
	skip_spaces<Types::__WS>(pos);
	value_expr = required<Types::expr>(pos, [this](auto cursor) { return this->expr(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::PY_RAW::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_PARENTHESIS::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("explicit_expr", "expr"));
	skip_spaces<Types::__WS>(pos);
	value_RIGHT_PARENTHESIS = required<Types::RIGHT_PARENTHESIS>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::RIGHT_PARENTHESIS::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("explicit_expr", "RIGHT_PARENTHESIS"));
	Types::explicit_expr result;
	::ISPA_STD::assign_compatible(result.value, value_expr);
	::ISPA_STD::MatchResult<Types::explicit_expr, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::explicit_expr<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::explicit_expr, ::Parser::Lexer::iterator>;
template auto Parser::Parser::explicit_expr<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::explicit_expr, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::ruleValueVar_capture(IT pos) -> ::ISPA_STD::MatchResult<Types::rule::value::var_capture, IT> {
	::ISPA_STD::Node<Types::AMPERSAND> value_AMPERSAND;
	::ISPA_STD::Node<Types::ID> value_ID;
	value_AMPERSAND = required<Types::AMPERSAND>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id>, ISPA_STD::Recovery::Tokens<Tokens::ID::id>, ISPA_STD::Recovery::Tokens<Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("rule::value::var_capture", "AMPERSAND"));
	skip_spaces<Types::__WS>(pos);
	value_ID = required<Types::ID>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::ID::id>, ISPA_STD::Recovery::Tokens<Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("rule::value::var_capture", "ID"));
	Types::rule::value::var_capture result;
	::ISPA_STD::assign_compatible(result.value, value_ID);
	::ISPA_STD::MatchResult<Types::rule::value::var_capture, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::ruleValueVar_capture<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::rule::value::var_capture, ::Parser::Lexer::iterator>;
template auto Parser::Parser::ruleValueVar_capture<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::rule::value::var_capture, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::main(IT pos) -> ::ISPA_STD::MatchResult<Types::main, IT> {
	std::variant<std::monostate, ::ISPA_STD::Node<Types::grammar>, ::ISPA_STD::Node<Types::fail_block>> choice0;
	bool matched0;
	::ISPA_STD::Node<Types::grammar> value_grammar;
	::ISPA_STD::Node<Types::fail_block> value_fail_block;
	std::vector<std::variant<std::monostate, ::ISPA_STD::Node<Types::grammar>, ::ISPA_STD::Node<Types::fail_block>>> group_list1;
	// grammar `@  ( ( grammar |  fail_block))*;`: repeat while lookahead is in FIRST
	while (((*pos).kind() == Tokens::FAIL::id || (*pos).kind() == Tokens::ID::id || (*pos).kind() == Tokens::grammar::modifier::AUTO::id)) {
		// grammar ` ( grammar |  fail_block)`: choice; alternative selected by LL(1) lookahead
		matched0 = false;
		auto la0_1 = pos;
		switch ((*la0_1).kind()) {
			case Tokens::FAIL::id: {
				value_fail_block = required<Types::fail_block>(la0_1, [this](auto cursor) { return this->fail_block(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::FAIL::id, Tokens::ID::id, Tokens::grammar::modifier::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("main", "<group>"));
				choice0 = value_fail_block;
				matched0 = true;
				break;
			}
			case Tokens::ID::id: {
				value_grammar = required<Types::grammar>(la0_1, [this](auto cursor) { return this->grammar(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::FAIL::id, Tokens::ID::id, Tokens::grammar::modifier::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("main", "<group>"));
				choice0 = value_grammar;
				matched0 = true;
				break;
			}
			case Tokens::grammar::modifier::AUTO::id: {
				value_grammar = required<Types::grammar>(la0_1, [this](auto cursor) { return this->grammar(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::FAIL::id, Tokens::ID::id, Tokens::grammar::modifier::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("main", "<group>"));
				choice0 = value_grammar;
				matched0 = true;
				break;
			}
		}
		pos = la0_1;
		if (!matched0) {
			raise_error(*pos, "ISPA match failure: expected one of: ID, grammar.modifier.AUTO, FAIL");
			return {};
		}
		group_list1.push_back(choice0);
		skip_spaces<Types::__WS>(pos);
	}
	Types::main result;
	::ISPA_STD::assign_compatible(result.value, group_list1);
	::ISPA_STD::MatchResult<Types::main, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::main<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::main, ::Parser::Lexer::iterator>;
template auto Parser::Parser::main<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::main, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::advanced_rule(IT pos) -> ::ISPA_STD::MatchResult<Types::advanced_rule, IT> {
	::ISPA_STD::Node<Types::LEFT_CURLY_BRACKET> value_LEFT_CURLY_BRACKET;
	std::vector<::ISPA_STD::Node<Types::advanced_rule::dep_decl>> value_list_advanced_rule_dep_decl;
	std::variant<std::monostate, ::ISPA_STD::Node<Types::advanced_rule::regular_match>, ::ISPA_STD::Node<Types::stmt>> choice0;
	bool matched0;
	::ISPA_STD::Node<Types::advanced_rule::regular_match> value_advanced_rule_regular_match;
	::ISPA_STD::Node<Types::stmt> value_stmt;
	std::vector<std::variant<std::monostate, ::ISPA_STD::Node<Types::advanced_rule::regular_match>, ::ISPA_STD::Node<Types::stmt>>> group_list1;
	::ISPA_STD::Node<Types::RIGHT_CURLY_BRACKET> value_RIGHT_CURLY_BRACKET;
	value_LEFT_CURLY_BRACKET = required<Types::LEFT_CURLY_BRACKET>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::LEFT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::PY_RAW::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::advanced_rule::dep_decl::DEPENDS::id, Tokens::advanced_rule::regular_match::MATCH::id>, ISPA_STD::Recovery::Tokens<Tokens::FAIL::id, Tokens::ID::id, Tokens::SEMICOLON::id, Tokens::grammar::modifier::AUTO::id, Tokens::rule::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("advanced_rule", "LEFT_CURLY_BRACKET"));
	skip_spaces<Types::__WS>(pos);
	value_list_advanced_rule_dep_decl = range_optional<Types::advanced_rule::dep_decl, Types::__WS>(pos, [this](auto cursor) { return this->advanced_ruleDep_decl(cursor); });
	skip_spaces<Types::__WS>(pos);
	// grammar `@  ( ( advanced_rule::regular_match |  stmt))*;`: repeat while lookahead is in FIRST
	while (((*pos).kind() == Tokens::PY_RAW::id || (*pos).kind() == Tokens::advanced_rule::regular_match::MATCH::id)) {
		// grammar ` ( advanced_rule::regular_match |  stmt)`: choice; alternative selected by LL(1) lookahead
		matched0 = false;
		auto la0_1 = pos;
		switch ((*la0_1).kind()) {
			case Tokens::PY_RAW::id: {
				value_stmt = required<Types::stmt>(la0_1, [this](auto cursor) { return this->stmt(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::PY_RAW::id, Tokens::advanced_rule::regular_match::MATCH::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::FAIL::id, Tokens::ID::id, Tokens::SEMICOLON::id, Tokens::grammar::modifier::AUTO::id, Tokens::rule::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("advanced_rule", "<group>"));
				choice0 = value_stmt;
				matched0 = true;
				break;
			}
			case Tokens::advanced_rule::regular_match::MATCH::id: {
				value_advanced_rule_regular_match = required<Types::advanced_rule::regular_match>(la0_1, [this](auto cursor) { return this->advanced_ruleRegular_match(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::PY_RAW::id, Tokens::advanced_rule::regular_match::MATCH::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::FAIL::id, Tokens::ID::id, Tokens::SEMICOLON::id, Tokens::grammar::modifier::AUTO::id, Tokens::rule::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("advanced_rule", "<group>"));
				choice0 = value_advanced_rule_regular_match;
				matched0 = true;
				break;
			}
		}
		pos = la0_1;
		if (!matched0) {
			raise_error(*pos, "ISPA match failure: expected one of: advanced_rule.regular_match.MATCH, PY_RAW");
			return {};
		}
		group_list1.push_back(choice0);
		skip_spaces<Types::__WS>(pos);
	}
	skip_spaces<Types::__WS>(pos);
	value_RIGHT_CURLY_BRACKET = required<Types::RIGHT_CURLY_BRACKET>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::FAIL::id, Tokens::ID::id, Tokens::SEMICOLON::id, Tokens::grammar::modifier::AUTO::id, Tokens::rule::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::FAIL::id, Tokens::ID::id, Tokens::SEMICOLON::id, Tokens::grammar::modifier::AUTO::id, Tokens::rule::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("advanced_rule", "RIGHT_CURLY_BRACKET"));
	Types::advanced_rule result;
	::ISPA_STD::assign_compatible(result.dep, value_list_advanced_rule_dep_decl);
	::ISPA_STD::assign_compatible(result.body, group_list1);
	::ISPA_STD::MatchResult<Types::advanced_rule, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::advanced_rule<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::advanced_rule, ::Parser::Lexer::iterator>;
template auto Parser::Parser::advanced_rule<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::advanced_rule, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::advanced_ruleRegular_matchUnpack(IT pos) -> ::ISPA_STD::MatchResult<Types::advanced_rule::regular_match::unpack, IT> {
	::ISPA_STD::Node<Types::AUTO> value_AUTO;
	std::vector<::ISPA_STD::Node<Types::ID>> value_list_ID;
	value_AUTO = required<Types::AUTO>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::ID::id>, ISPA_STD::Recovery::Tokens<Tokens::PY_RAW::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::advanced_rule::regular_match::MATCH::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("advanced_rule::regular_match::unpack", "AUTO"));
	skip_spaces<Types::__WS>(pos);
	value_list_ID = range<Types::ID, Types::__WS>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::ID::id>, ISPA_STD::Recovery::Tokens<Tokens::PY_RAW::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::advanced_rule::regular_match::MATCH::id>, ISPA_STD::Recovery::Tokens<Tokens::PY_RAW::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::advanced_rule::regular_match::MATCH::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("advanced_rule::regular_match::unpack", "ID"));
	Types::advanced_rule::regular_match::unpack result;
	::ISPA_STD::assign_compatible(result.value, value_list_ID);
	::ISPA_STD::MatchResult<Types::advanced_rule::regular_match::unpack, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::advanced_ruleRegular_matchUnpack<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::advanced_rule::regular_match::unpack, ::Parser::Lexer::iterator>;
template auto Parser::Parser::advanced_ruleRegular_matchUnpack<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::advanced_rule::regular_match::unpack, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::advanced_ruleRegular_match(IT pos) -> ::ISPA_STD::MatchResult<Types::advanced_rule::regular_match, IT> {
	::ISPA_STD::Node<Types::advanced_rule::regular_match::MATCH> value_advanced_rule_regular_match_MATCH;
	std::vector<::ISPA_STD::Node<Types::rule::value>> value_list_rule_value;
	std::variant<std::monostate, ::ISPA_STD::Node<Types::advanced_rule::regular_match::unpack>, ::ISPA_STD::Node<Types::SEMICOLON>> choice0;
	bool matched0;
	::ISPA_STD::Node<Types::advanced_rule::regular_match::unpack> value_advanced_rule_regular_match_unpack;
	::ISPA_STD::Node<Types::SEMICOLON> value_SEMICOLON;
	value_advanced_rule_regular_match_MATCH = required<Types::advanced_rule::regular_match::MATCH>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::advanced_rule::regular_match::MATCH::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::PY_RAW::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::advanced_rule::regular_match::MATCH::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("advanced_rule::regular_match", "advanced_rule::regular_match::MATCH"));
	skip_spaces<Types::__WS>(pos);
	value_list_rule_value = range<Types::rule::value, Types::__WS>(pos, [this](auto cursor) { return this->ruleValue(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::ID::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::rule::value::ANY::id, Tokens::rule::value::CGROUP::id, Tokens::rule::value::NOSPACE::id, Tokens::rule::value::SPACE::id, Tokens::rule::value::STRING::id, Tokens::rule::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AUTO::id, Tokens::SEMICOLON::id>, ISPA_STD::Recovery::Tokens<Tokens::PY_RAW::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::advanced_rule::regular_match::MATCH::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("advanced_rule::regular_match", "rule::value"));
	skip_spaces<Types::__WS>(pos);
	// grammar `@  ( advanced_rule::regular_match::unpack |  SEMICOLON)`: choice; alternative selected by LL(1) lookahead
	matched0 = false;
	auto la0_1 = pos;
	switch ((*la0_1).kind()) {
		case Tokens::AUTO::id: {
			value_advanced_rule_regular_match_unpack = required<Types::advanced_rule::regular_match::unpack>(la0_1, [this](auto cursor) { return this->advanced_ruleRegular_matchUnpack(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AUTO::id, Tokens::SEMICOLON::id>, ISPA_STD::Recovery::Tokens<Tokens::PY_RAW::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::advanced_rule::regular_match::MATCH::id>, ISPA_STD::Recovery::Tokens<Tokens::PY_RAW::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::advanced_rule::regular_match::MATCH::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("advanced_rule::regular_match", "<group>"));
			choice0 = value_advanced_rule_regular_match_unpack;
			matched0 = true;
			break;
		}
		case Tokens::SEMICOLON::id: {
			value_SEMICOLON = required<Types::SEMICOLON>(la0_1, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AUTO::id, Tokens::SEMICOLON::id>, ISPA_STD::Recovery::Tokens<Tokens::PY_RAW::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::advanced_rule::regular_match::MATCH::id>, ISPA_STD::Recovery::Tokens<Tokens::PY_RAW::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::advanced_rule::regular_match::MATCH::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("advanced_rule::regular_match", "<group>"));
			choice0 = value_SEMICOLON;
			matched0 = true;
			break;
		}
	}
	pos = la0_1;
	if (!matched0) {
		raise_error(*pos, "ISPA match failure: expected one of: AUTO, SEMICOLON");
		return {};
	}
	Types::advanced_rule::regular_match result;
	::ISPA_STD::assign_compatible(result.patterns, value_list_rule_value);
	::ISPA_STD::assign_compatible(result.assign_names, choice0);
	::ISPA_STD::MatchResult<Types::advanced_rule::regular_match, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::advanced_ruleRegular_match<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::advanced_rule::regular_match, ::Parser::Lexer::iterator>;
template auto Parser::Parser::advanced_ruleRegular_match<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::advanced_rule::regular_match, ::Parser::Lexer::lazy_iterator>;
auto Parser::Parser::parseFromTokens() -> void {
	tree = main(Lexer::iterator(lexer)).node.data();
}
auto Parser::Parser::lazyParse() -> void {
	Lexer lexer;
	tree = main(Lexer::lazy_iterator(lexer, text)).node.data();
}
