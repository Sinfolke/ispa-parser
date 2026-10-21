#include "Parser.h"

#include <ispastdlib.hpp>

auto Parser::TokensToString(std::size_t id) -> const char* {
	switch (id) {
		case Tokens::__WS::id: {
			return TokensStr::__WS::id;
			break;
		}
		case Tokens::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS::id: {
			return TokensStr::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS::id;
			break;
		}
		case Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id: {
			return TokensStr::modules::rule::regular::nested_rule::NUMBER_SIGN::id;
			break;
		}
		case Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id: {
			return TokensStr::modules::rule::regular::value::alternative::VERTICAL_LINE::id;
			break;
		}
		case Tokens::modules::common::template_params::LESS_THAN_SIGN::id: {
			return TokensStr::modules::common::template_params::LESS_THAN_SIGN::id;
			break;
		}
		case Tokens::modules::grammar::modifier::AUTO::id: {
			return TokensStr::modules::grammar::modifier::AUTO::id;
			break;
		}
		case Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id: {
			return TokensStr::modules::rule::regular::value::dyn::DOLLAR_SIGN::id;
			break;
		}
		case Tokens::modules::grammar::modifier::RIGHT_SQUARE_BRACKET::id: {
			return TokensStr::modules::grammar::modifier::RIGHT_SQUARE_BRACKET::id;
			break;
		}
		case Tokens::modules::fail_block::fail_block::FAIL::id: {
			return TokensStr::modules::fail_block::fail_block::FAIL::id;
			break;
		}
		case Tokens::SEMICOLON::id: {
			return TokensStr::SEMICOLON::id;
			break;
		}
		case Tokens::GREATER_THAN_SIGN::id: {
			return TokensStr::GREATER_THAN_SIGN::id;
			break;
		}
		case Tokens::PERCENT_SIGN::id: {
			return TokensStr::PERCENT_SIGN::id;
			break;
		}
		case Tokens::AMPERSAND::id: {
			return TokensStr::AMPERSAND::id;
			break;
		}
		case Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id: {
			return TokensStr::modules::rule::regular::value::shared_counter_registration::AUTO::id;
			break;
		}
		case Tokens::modules::rule::regular::value::QUANTIFIER::id: {
			return TokensStr::modules::rule::regular::value::QUANTIFIER::id;
			break;
		}
		case Tokens::modules::rule::regular::value::NOSPACE::id: {
			return TokensStr::modules::rule::regular::value::NOSPACE::id;
			break;
		}
		case Tokens::modules::rule::regular::value::SPACE::id: {
			return TokensStr::modules::rule::regular::value::SPACE::id;
			break;
		}
		case Tokens::AUTO::id: {
			return TokensStr::AUTO::id;
			break;
		}
		case Tokens::LEFT_CURLY_BRACKET::id: {
			return TokensStr::LEFT_CURLY_BRACKET::id;
			break;
		}
		case Tokens::RIGHT_CURLY_BRACKET::id: {
			return TokensStr::RIGHT_CURLY_BRACKET::id;
			break;
		}
		case Tokens::modules::grammar::modifier::MOD::id: {
			return TokensStr::modules::grammar::modifier::MOD::id;
			break;
		}
		case Tokens::COMMERCIAL_AT::id: {
			return TokensStr::COMMERCIAL_AT::id;
			break;
		}
		case Tokens::modules::rule::regular::value::STRING::id: {
			return TokensStr::modules::rule::regular::value::STRING::id;
			break;
		}
		case Tokens::modules::rule::regular::value::CGROUP::id: {
			return TokensStr::modules::rule::regular::value::CGROUP::id;
			break;
		}
		case Tokens::modules::common::PY_RAW::id: {
			return TokensStr::modules::common::PY_RAW::id;
			break;
		}
		case Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id: {
			return TokensStr::modules::rule::advanced::advanced_rule::regular_match::MATCH::id;
			break;
		}
		case Tokens::modules::rule::regular::value::ANY::id: {
			return TokensStr::modules::rule::regular::value::ANY::id;
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
		case Tokens::modules::common::NUMBER::id: {
			return TokensStr::modules::common::NUMBER::id;
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
		case Tokens::modules::common::ID::id: {
			return TokensStr::modules::common::ID::id;
			break;
		}
	}
	throw "Invalid Tokens ID";
}
auto Parser::RulesToString(std::size_t id) -> const char* {
	switch (id) {
		case Rules::main::id: {
			return RulesStr::main::id;
			break;
		}
		case Rules::modules::rule::regular::value::shared_counter_registration::id: {
			return RulesStr::modules::rule::regular::value::shared_counter_registration::id;
			break;
		}
		case Rules::modules::rule::regular::value::counter::bounded::id: {
			return RulesStr::modules::rule::regular::value::counter::bounded::id;
			break;
		}
		case Rules::modules::rule::regular::value::var_capture::id: {
			return RulesStr::modules::rule::regular::value::var_capture::id;
			break;
		}
		case Rules::modules::rule::regular::value::counter::id: {
			return RulesStr::modules::rule::regular::value::counter::id;
			break;
		}
		case Rules::modules::common::params::id: {
			return RulesStr::modules::common::params::id;
			break;
		}
		case Rules::modules::rule::regular::ast::single_value::id: {
			return RulesStr::modules::rule::regular::ast::single_value::id;
			break;
		}
		case Rules::modules::rule::regular::value::dyn::dyn_expr::id: {
			return RulesStr::modules::rule::regular::value::dyn::dyn_expr::id;
			break;
		}
		case Rules::modules::rule::regular::value::group::id: {
			return RulesStr::modules::rule::regular::value::group::id;
			break;
		}
		case Rules::modules::rule::regular::value::pattern::id: {
			return RulesStr::modules::rule::regular::value::pattern::id;
			break;
		}
		case Rules::modules::rule::regular::value::fail_capture::id: {
			return RulesStr::modules::rule::regular::value::fail_capture::id;
			break;
		}
		case Rules::modules::rule::regular::value::ast_capture::id: {
			return RulesStr::modules::rule::regular::value::ast_capture::id;
			break;
		}
		case Rules::modules::rule::regular::ast::full::id: {
			return RulesStr::modules::rule::regular::ast::full::id;
			break;
		}
		case Rules::modules::rule::regular::value::one_capture::id: {
			return RulesStr::modules::rule::regular::value::one_capture::id;
			break;
		}
		case Rules::modules::rule::regular::ast::abbr::id: {
			return RulesStr::modules::rule::regular::ast::abbr::id;
			break;
		}
		case Rules::modules::rule::regular::ast::full::part::id: {
			return RulesStr::modules::rule::regular::ast::full::part::id;
			break;
		}
		case Rules::modules::rule::advanced::advanced_rule::regular_match::unpack::id: {
			return RulesStr::modules::rule::advanced::advanced_rule::regular_match::unpack::id;
			break;
		}
		case Rules::modules::rule::regular::ast::id: {
			return RulesStr::modules::rule::regular::ast::id;
			break;
		}
		case Rules::modules::rule::regular::regular_rule::id: {
			return RulesStr::modules::rule::regular::regular_rule::id;
			break;
		}
		case Rules::modules::rule::regular::value::id: {
			return RulesStr::modules::rule::regular::value::id;
			break;
		}
		case Rules::modules::grammar::grammar::id: {
			return RulesStr::modules::grammar::grammar::id;
			break;
		}
		case Rules::modules::rule::advanced::advanced_rule::id: {
			return RulesStr::modules::rule::advanced::advanced_rule::id;
			break;
		}
		case Rules::modules::fail_block::fail_block::id: {
			return RulesStr::modules::fail_block::fail_block::id;
			break;
		}
		case Rules::modules::rule::regular::value::dyn::id: {
			return RulesStr::modules::rule::regular::value::dyn::id;
			break;
		}
		case Rules::modules::grammar::modifier::id: {
			return RulesStr::modules::grammar::modifier::id;
			break;
		}
		case Rules::modules::common::param::id: {
			return RulesStr::modules::common::param::id;
			break;
		}
		case Rules::modules::common::template_params::id: {
			return RulesStr::modules::common::template_params::id;
			break;
		}
		case Rules::modules::rule::regular::value::alternative::id: {
			return RulesStr::modules::rule::regular::value::alternative::id;
			break;
		}
		case Rules::modules::rule::advanced::advanced_rule::regular_match::id: {
			return RulesStr::modules::rule::advanced::advanced_rule::regular_match::id;
			break;
		}
		case Rules::modules::main::main::id: {
			return RulesStr::modules::main::main::id;
			break;
		}
		case Rules::modules::common::name::id: {
			return RulesStr::modules::common::name::id;
			break;
		}
		case Rules::modules::rule::regular::nested_rule::id: {
			return RulesStr::modules::rule::regular::nested_rule::id;
			break;
		}
		case Rules::modules::common::stmt::id: {
			return RulesStr::modules::common::stmt::id;
			break;
		}
		case Rules::modules::rule::regular::value::mul_capture::id: {
			return RulesStr::modules::rule::regular::value::mul_capture::id;
			break;
		}
		case Rules::modules::common::expr::id: {
			return RulesStr::modules::common::expr::id;
			break;
		}
		case Rules::modules::rule::regular::f_binding::id: {
			return RulesStr::modules::rule::regular::f_binding::id;
			break;
		}
		case Rules::modules::common::forward_declaration::id: {
			return RulesStr::modules::common::forward_declaration::id;
			break;
		}
		case Rules::modules::rule::advanced::advanced_rule::dep_decl::id: {
			return RulesStr::modules::rule::advanced::advanced_rule::dep_decl::id;
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
auto Parser::FlatTypes::modules_rule_advanced_advanced_rule_dep_decl_DEPENDS::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_rule_advanced_advanced_rule_dep_decl_DEPENDS", true);
}
auto Parser::FlatTypes::modules_rule_advanced_advanced_rule_dep_decl_DEPENDS::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::modules_rule_advanced_advanced_rule_dep_decl_DEPENDS::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_rule_advanced_advanced_rule_dep_decl_DEPENDS {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, modules_rule_advanced_advanced_rule_dep_decl_DEPENDS value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::modules::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules", true);
}
auto Parser::FlatTypes::modules::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::modules::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, modules value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::modules_rule::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_rule", true);
}
auto Parser::FlatTypes::modules_rule::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::modules_rule::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_rule {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, modules_rule value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::modules_rule_advanced::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_rule_advanced", true);
}
auto Parser::FlatTypes::modules_rule_advanced::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::modules_rule_advanced::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_rule_advanced {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, modules_rule_advanced value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::modules_rule_regular_nested_rule_NUMBER_SIGN::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_rule_regular_nested_rule_NUMBER_SIGN", true);
}
auto Parser::FlatTypes::modules_rule_regular_nested_rule_NUMBER_SIGN::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::modules_rule_regular_nested_rule_NUMBER_SIGN::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_rule_regular_nested_rule_NUMBER_SIGN {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, modules_rule_regular_nested_rule_NUMBER_SIGN value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::modules_rule_regular::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_rule_regular", true);
}
auto Parser::FlatTypes::modules_rule_regular::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::modules_rule_regular::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_rule_regular {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, modules_rule_regular value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::modules_rule_regular_nested_rule::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_rule_regular_nested_rule", false);
	printer.up(false);
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::modules_rule_regular_nested_rule::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::modules_rule_regular_nested_rule::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_rule_regular_nested_rule {", "value = ", value.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, modules_rule_regular_nested_rule value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::modules_rule_regular_value_alternative_VERTICAL_LINE::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_rule_regular_value_alternative_VERTICAL_LINE", true);
}
auto Parser::FlatTypes::modules_rule_regular_value_alternative_VERTICAL_LINE::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::modules_rule_regular_value_alternative_VERTICAL_LINE::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_rule_regular_value_alternative_VERTICAL_LINE {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, modules_rule_regular_value_alternative_VERTICAL_LINE value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::modules_rule_regular_value::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_rule_regular_value", false);
	printer.up(false);
	printer.node_with_value("value", value, true);
	printer.down();
}
auto Parser::FlatTypes::modules_rule_regular_value::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::modules_rule_regular_value::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_rule_regular_value {", "value = ", value, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, modules_rule_regular_value value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::modules_rule_regular_value_alternative::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_rule_regular_value_alternative", false);
	printer.up(false);
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::modules_rule_regular_value_alternative::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::modules_rule_regular_value_alternative::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_rule_regular_value_alternative {", "value = ", value.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, modules_rule_regular_value_alternative value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::modules_common_template_params_LESS_THAN_SIGN::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_common_template_params_LESS_THAN_SIGN", true);
}
auto Parser::FlatTypes::modules_common_template_params_LESS_THAN_SIGN::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::modules_common_template_params_LESS_THAN_SIGN::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_common_template_params_LESS_THAN_SIGN {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, modules_common_template_params_LESS_THAN_SIGN value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::modules_common::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_common", true);
}
auto Parser::FlatTypes::modules_common::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::modules_common::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_common {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, modules_common value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::modules_grammar_modifier_AUTO::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_grammar_modifier_AUTO", true);
}
auto Parser::FlatTypes::modules_grammar_modifier_AUTO::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::modules_grammar_modifier_AUTO::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_grammar_modifier_AUTO {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, modules_grammar_modifier_AUTO value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::modules_grammar::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_grammar", true);
}
auto Parser::FlatTypes::modules_grammar::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::modules_grammar::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_grammar {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, modules_grammar value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::modules_rule_regular_value_dyn_DOLLAR_SIGN::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_rule_regular_value_dyn_DOLLAR_SIGN", true);
}
auto Parser::FlatTypes::modules_rule_regular_value_dyn_DOLLAR_SIGN::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::modules_rule_regular_value_dyn_DOLLAR_SIGN::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_rule_regular_value_dyn_DOLLAR_SIGN {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, modules_rule_regular_value_dyn_DOLLAR_SIGN value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::modules_grammar_modifier_RIGHT_SQUARE_BRACKET::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_grammar_modifier_RIGHT_SQUARE_BRACKET", true);
}
auto Parser::FlatTypes::modules_grammar_modifier_RIGHT_SQUARE_BRACKET::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::modules_grammar_modifier_RIGHT_SQUARE_BRACKET::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_grammar_modifier_RIGHT_SQUARE_BRACKET {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, modules_grammar_modifier_RIGHT_SQUARE_BRACKET value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::modules_fail_block_fail_block_FAIL::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_fail_block_fail_block_FAIL", true);
}
auto Parser::FlatTypes::modules_fail_block_fail_block_FAIL::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::modules_fail_block_fail_block_FAIL::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_fail_block_fail_block_FAIL {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, modules_fail_block_fail_block_FAIL value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::modules_fail_block::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_fail_block", true);
}
auto Parser::FlatTypes::modules_fail_block::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::modules_fail_block::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_fail_block {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, modules_fail_block value) -> std::ostream & {
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
auto Parser::FlatTypes::modules_rule_regular_value_shared_counter_registration_AUTO::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_rule_regular_value_shared_counter_registration_AUTO", true);
}
auto Parser::FlatTypes::modules_rule_regular_value_shared_counter_registration_AUTO::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::modules_rule_regular_value_shared_counter_registration_AUTO::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_rule_regular_value_shared_counter_registration_AUTO {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, modules_rule_regular_value_shared_counter_registration_AUTO value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::modules_rule_regular_value_QUANTIFIER::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_rule_regular_value_QUANTIFIER", false);
	printer.up(false);
	printer.node_with_value("value", value, true);
	printer.down();
}
auto Parser::FlatTypes::modules_rule_regular_value_QUANTIFIER::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::modules_rule_regular_value_QUANTIFIER::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_rule_regular_value_QUANTIFIER {", "value = ", value, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, modules_rule_regular_value_QUANTIFIER value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::modules_rule_regular_value_NOSPACE::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_rule_regular_value_NOSPACE", true);
}
auto Parser::FlatTypes::modules_rule_regular_value_NOSPACE::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::modules_rule_regular_value_NOSPACE::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_rule_regular_value_NOSPACE {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, modules_rule_regular_value_NOSPACE value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::modules_rule_regular_value_SPACE::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_rule_regular_value_SPACE", true);
}
auto Parser::FlatTypes::modules_rule_regular_value_SPACE::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::modules_rule_regular_value_SPACE::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_rule_regular_value_SPACE {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, modules_rule_regular_value_SPACE value) -> std::ostream & {
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
auto Parser::FlatTypes::modules_grammar_modifier_MOD::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_grammar_modifier_MOD", false);
	printer.up(false);
	printer.node_with_value("value", value, true);
	printer.down();
}
auto Parser::FlatTypes::modules_grammar_modifier_MOD::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::modules_grammar_modifier_MOD::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_grammar_modifier_MOD {", "value = ", value, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, modules_grammar_modifier_MOD value) -> std::ostream & {
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
auto Parser::FlatTypes::modules_rule_regular_value_STRING::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_rule_regular_value_STRING", false);
	printer.up(false);
	printer.node_with_value("value", value, true);
	printer.down();
}
auto Parser::FlatTypes::modules_rule_regular_value_STRING::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::modules_rule_regular_value_STRING::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_rule_regular_value_STRING {", "value = ", value, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, modules_rule_regular_value_STRING value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::modules_rule_regular_value_CGROUP::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_rule_regular_value_CGROUP", false);
	printer.up(false);
	printer.node_with_value("negative", negative, false);
	printer.node_with_value("v", v, true);
	printer.down();
}
auto Parser::FlatTypes::modules_rule_regular_value_CGROUP::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::modules_rule_regular_value_CGROUP::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_rule_regular_value_CGROUP {", "negative = ", negative, ", ", "v = ", v, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, modules_rule_regular_value_CGROUP value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::modules_common_PY_RAW::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_common_PY_RAW", false);
	printer.up(false);
	printer.node_with_value("value", value, true);
	printer.down();
}
auto Parser::FlatTypes::modules_common_PY_RAW::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::modules_common_PY_RAW::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_common_PY_RAW {", "value = ", value, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, modules_common_PY_RAW value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::modules_rule_advanced_advanced_rule_regular_match_MATCH::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_rule_advanced_advanced_rule_regular_match_MATCH", true);
}
auto Parser::FlatTypes::modules_rule_advanced_advanced_rule_regular_match_MATCH::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::modules_rule_advanced_advanced_rule_regular_match_MATCH::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_rule_advanced_advanced_rule_regular_match_MATCH {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, modules_rule_advanced_advanced_rule_regular_match_MATCH value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::modules_rule_regular_value_ANY::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_rule_regular_value_ANY", true);
}
auto Parser::FlatTypes::modules_rule_regular_value_ANY::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::modules_rule_regular_value_ANY::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_rule_regular_value_ANY {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, modules_rule_regular_value_ANY value) -> std::ostream & {
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
auto Parser::FlatTypes::modules_common_NUMBER::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_common_NUMBER", false);
	printer.up(false);
	printer.node_with_value("full", full, false);
	printer.node_with_value("floating", floating, true);
	printer.down();
}
auto Parser::FlatTypes::modules_common_NUMBER::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::modules_common_NUMBER::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_common_NUMBER {", "full = ", full, ", ", "floating = ", floating, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, modules_common_NUMBER value) -> std::ostream & {
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
auto Parser::FlatTypes::modules_common_ID::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_common_ID", false);
	printer.up(false);
	printer.node_with_value("value", value, true);
	printer.down();
}
auto Parser::FlatTypes::modules_common_ID::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::modules_common_ID::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_common_ID {", "value = ", value, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, modules_common_ID value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::modules_rule_regular_value_group::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_rule_regular_value_group", false);
	printer.up(false);
	printer.subtree("value", value, true);
	printer.down();
}
auto Parser::FlatTypes::modules_rule_regular_value_group::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::modules_rule_regular_value_group::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_rule_regular_value_group {", "value = ", value, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, modules_rule_regular_value_group value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::modules_main::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_main", true);
}
auto Parser::FlatTypes::modules_main::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::modules_main::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_main {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, modules_main value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::modules_common_forward_declaration::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_common_forward_declaration", true);
}
auto Parser::FlatTypes::modules_common_forward_declaration::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::modules_common_forward_declaration::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_common_forward_declaration {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, modules_common_forward_declaration value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::modules_grammar_modifier::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_grammar_modifier", false);
	printer.up(false);
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::modules_grammar_modifier::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::modules_grammar_modifier::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_grammar_modifier {", "value = ", value.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, modules_grammar_modifier value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::modules_rule_regular_value_mul_capture::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_rule_regular_value_mul_capture", false);
	printer.up(false);
	printer.node_with_value("type", type, false);
	printer.subtree("cap", cap, true);
	printer.down();
}
auto Parser::FlatTypes::modules_rule_regular_value_mul_capture::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::modules_rule_regular_value_mul_capture::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_rule_regular_value_mul_capture {", "type = ", type, ", ", "cap = ", cap, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, modules_rule_regular_value_mul_capture value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::modules_common_stmt::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_common_stmt", false);
	printer.up(false);
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::modules_common_stmt::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::modules_common_stmt::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_common_stmt {", "value = ", value.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, modules_common_stmt value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::modules_common_expr::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_common_expr", false);
	printer.up(false);
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::modules_common_expr::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::modules_common_expr::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_common_expr {", "value = ", value.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, modules_common_expr value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::modules_rule_regular_value_shared_counter_registration::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_rule_regular_value_shared_counter_registration", false);
	printer.up(false);
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::modules_rule_regular_value_shared_counter_registration::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::modules_rule_regular_value_shared_counter_registration::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_rule_regular_value_shared_counter_registration {", "value = ", value.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, modules_rule_regular_value_shared_counter_registration value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::modules_rule_regular_value_var_capture::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_rule_regular_value_var_capture", false);
	printer.up(false);
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::modules_rule_regular_value_var_capture::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::modules_rule_regular_value_var_capture::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_rule_regular_value_var_capture {", "value = ", value.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, modules_rule_regular_value_var_capture value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::modules_rule_regular_value_ast_capture::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_rule_regular_value_ast_capture", false);
	printer.up(false);
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::modules_rule_regular_value_ast_capture::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::modules_rule_regular_value_ast_capture::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_rule_regular_value_ast_capture {", "value = ", value.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, modules_rule_regular_value_ast_capture value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::modules_rule_regular_ast_abbr::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_rule_regular_ast_abbr", false);
	printer.up(false);
	printer.node("f", false);
	printer.up(true);
	f.print(printer);
	printer.down();
	printer.subtree("seq", seq, true);
	printer.down();
}
auto Parser::FlatTypes::modules_rule_regular_ast_abbr::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::modules_rule_regular_ast_abbr::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_rule_regular_ast_abbr {", "f = ", f.to_string(), ", ", "seq = ", seq, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, modules_rule_regular_ast_abbr value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::modules_rule_advanced_advanced_rule_regular_match_unpack::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_rule_advanced_advanced_rule_regular_match_unpack", false);
	printer.up(false);
	printer.subtree("value", value, true);
	printer.down();
}
auto Parser::FlatTypes::modules_rule_advanced_advanced_rule_regular_match_unpack::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::modules_rule_advanced_advanced_rule_regular_match_unpack::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_rule_advanced_advanced_rule_regular_match_unpack {", "value = ", value, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, modules_rule_advanced_advanced_rule_regular_match_unpack value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::modules_common_param::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_common_param", false);
	printer.up(false);
	printer.node("first_p", false);
	printer.up(true);
	first_p.print(printer);
	printer.down();
	printer.subtree("following_p", following_p, true);
	printer.down();
}
auto Parser::FlatTypes::modules_common_param::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::modules_common_param::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_common_param {", "first_p = ", first_p.to_string(), ", ", "following_p = ", following_p, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, modules_common_param value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::modules_rule_regular_f_binding::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_rule_regular_f_binding", false);
	printer.up(false);
	printer.node("f", false);
	printer.up(true);
	f.print(printer);
	printer.down();
	printer.subtree("seq", seq, true);
	printer.down();
}
auto Parser::FlatTypes::modules_rule_regular_f_binding::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::modules_rule_regular_f_binding::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_rule_regular_f_binding {", "f = ", f.to_string(), ", ", "seq = ", seq, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, modules_rule_regular_f_binding value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::modules_rule_advanced_advanced_rule_dep_decl::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_rule_advanced_advanced_rule_dep_decl", false);
	printer.up(false);
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::modules_rule_advanced_advanced_rule_dep_decl::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::modules_rule_advanced_advanced_rule_dep_decl::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_rule_advanced_advanced_rule_dep_decl {", "value = ", value.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, modules_rule_advanced_advanced_rule_dep_decl value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::modules_rule_regular_value_counter_bounded::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_rule_regular_value_counter_bounded", false);
	printer.up(false);
	printer.node_with_value("value", value, true);
	printer.down();
}
auto Parser::FlatTypes::modules_rule_regular_value_counter_bounded::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::modules_rule_regular_value_counter_bounded::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_rule_regular_value_counter_bounded {", "value = ", value, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, modules_rule_regular_value_counter_bounded value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::modules_rule_regular_ast_single_value::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_rule_regular_ast_single_value", false);
	printer.up(false);
	printer.node_with_value("value", value, true);
	printer.down();
}
auto Parser::FlatTypes::modules_rule_regular_ast_single_value::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::modules_rule_regular_ast_single_value::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_rule_regular_ast_single_value {", "value = ", value, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, modules_rule_regular_ast_single_value value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::modules_rule_regular_value_dyn_dyn_expr::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_rule_regular_value_dyn_dyn_expr", false);
	printer.up(false);
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::modules_rule_regular_value_dyn_dyn_expr::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::modules_rule_regular_value_dyn_dyn_expr::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_rule_regular_value_dyn_dyn_expr {", "value = ", value.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, modules_rule_regular_value_dyn_dyn_expr value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::modules_rule_regular_ast_full_part::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_rule_regular_ast_full_part", false);
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
auto Parser::FlatTypes::modules_rule_regular_ast_full_part::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::modules_rule_regular_ast_full_part::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_rule_regular_ast_full_part {", "key = ", key.to_string(), ", ", "e = ", e.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, modules_rule_regular_ast_full_part value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::modules_rule_advanced_advanced_rule_regular_match::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_rule_advanced_advanced_rule_regular_match", false);
	printer.up(false);
	printer.subtree("patterns", patterns, false);
	printer.node_with_value("assign_names", assign_names, true);
	printer.down();
}
auto Parser::FlatTypes::modules_rule_advanced_advanced_rule_regular_match::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::modules_rule_advanced_advanced_rule_regular_match::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_rule_advanced_advanced_rule_regular_match {", "patterns = ", patterns, ", ", "assign_names = ", assign_names, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, modules_rule_advanced_advanced_rule_regular_match value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::modules_common_template_params::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_common_template_params", false);
	printer.up(false);
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::modules_common_template_params::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::modules_common_template_params::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_common_template_params {", "value = ", value.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, modules_common_template_params value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::modules_common_params::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_common_params", false);
	printer.up(false);
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::modules_common_params::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::modules_common_params::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_common_params {", "value = ", value.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, modules_common_params value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::modules_rule_regular_value_counter::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_rule_regular_value_counter", false);
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
auto Parser::FlatTypes::modules_rule_regular_value_counter::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::modules_rule_regular_value_counter::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_rule_regular_value_counter {", "quantifier = ", quantifier.to_string(), ", ", "repetitions = ", repetitions.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, modules_rule_regular_value_counter value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::modules_rule_regular_value_dyn::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_rule_regular_value_dyn", false);
	printer.up(false);
	printer.node_with_value("value", value, true);
	printer.down();
}
auto Parser::FlatTypes::modules_rule_regular_value_dyn::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::modules_rule_regular_value_dyn::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_rule_regular_value_dyn {", "value = ", value, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, modules_rule_regular_value_dyn value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::modules_rule_regular_ast_full::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_rule_regular_ast_full", false);
	printer.up(false);
	printer.subtree("value", value, true);
	printer.down();
}
auto Parser::FlatTypes::modules_rule_regular_ast_full::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::modules_rule_regular_ast_full::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_rule_regular_ast_full {", "value = ", value, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, modules_rule_regular_ast_full value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::modules_rule_advanced_advanced_rule::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_rule_advanced_advanced_rule", false);
	printer.up(false);
	printer.subtree("dep", dep, false);
	printer.node_with_value("body", body, true);
	printer.down();
}
auto Parser::FlatTypes::modules_rule_advanced_advanced_rule::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::modules_rule_advanced_advanced_rule::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_rule_advanced_advanced_rule {", "dep = ", dep, ", ", "body = ", body, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, modules_rule_advanced_advanced_rule value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::modules_common_name::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_common_name", false);
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
auto Parser::FlatTypes::modules_common_name::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::modules_common_name::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_common_name {", "primary = ", primary.to_string(), ", ", "nested = ", nested, ", ", "temp_params = ", temp_params.to_string(), ", ", "param = ", param.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, modules_common_name value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::modules_rule_regular_ast::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_rule_regular_ast", false);
	printer.up(false);
	printer.node_with_value("value", value, true);
	printer.down();
}
auto Parser::FlatTypes::modules_rule_regular_ast::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::modules_rule_regular_ast::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_rule_regular_ast {", "value = ", value, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, modules_rule_regular_ast value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::modules_fail_block_fail_block::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_fail_block_fail_block", false);
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
auto Parser::FlatTypes::modules_fail_block_fail_block::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::modules_fail_block_fail_block::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_fail_block_fail_block {", "name = ", name.to_string(), ", ", "val = ", val.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, modules_fail_block_fail_block value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::modules_rule_regular_value_pattern::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_rule_regular_value_pattern", false);
	printer.up(false);
	printer.node_with_value("value", value, true);
	printer.down();
}
auto Parser::FlatTypes::modules_rule_regular_value_pattern::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::modules_rule_regular_value_pattern::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_rule_regular_value_pattern {", "value = ", value, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, modules_rule_regular_value_pattern value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::modules_rule_regular_value_fail_capture::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_rule_regular_value_fail_capture", false);
	printer.up(false);
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::modules_rule_regular_value_fail_capture::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::modules_rule_regular_value_fail_capture::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_rule_regular_value_fail_capture {", "value = ", value.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, modules_rule_regular_value_fail_capture value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::modules_grammar_grammar::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_grammar_grammar", false);
	printer.up(false);
	printer.subtree("mod", mod, false);
	printer.node("name", false);
	printer.up(true);
	name.print(printer);
	printer.down();
	printer.node_with_value("entry", entry, true);
	printer.down();
}
auto Parser::FlatTypes::modules_grammar_grammar::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::modules_grammar_grammar::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_grammar_grammar {", "mod = ", mod, ", ", "name = ", name.to_string(), ", ", "entry = ", entry, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, modules_grammar_grammar value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::modules_rule_regular_regular_rule::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_rule_regular_regular_rule", false);
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
auto Parser::FlatTypes::modules_rule_regular_regular_rule::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::modules_rule_regular_regular_rule::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_rule_regular_regular_rule {", "v = ", v, ", ", "ast_pointer = ", ast_pointer.to_string(), ", ", "fail_pointer = ", fail_pointer.to_string(), ", ", "nested = ", nested, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, modules_rule_regular_regular_rule value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::modules_rule_regular_value_one_capture::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_rule_regular_value_one_capture", false);
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
auto Parser::FlatTypes::modules_rule_regular_value_one_capture::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::modules_rule_regular_value_one_capture::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_rule_regular_value_one_capture {", "v_cap = ", v_cap.to_string(), ", ", "ast_cap = ", ast_cap.to_string(), ", ", "fail_cap = ", fail_cap.to_string(), ", ", "val = ", val.to_string(), ", ", "alts = ", alts, ", ", "quantifier = ", quantifier.to_string(), ", ", "registration = ", registration.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, modules_rule_regular_value_one_capture value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::modules_main_main::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_main_main", false);
	printer.up(false);
	printer.node_with_value("value", value, true);
	printer.down();
}
auto Parser::FlatTypes::modules_main_main::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::modules_main_main::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_main_main {", "value = ", value, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, modules_main_main value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::main::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("main", false);
	printer.up(false);
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::main::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::main::to_string() const -> std::string {
	return ::ISPA_STD::concat("main {", "value = ", value.to_string(), "}");
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
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Types::modules::rule::regular::nested_rule::NUMBER_SIGN{}));
			break;
		}
		case 2: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Types::modules::rule::regular::value::dyn::DOLLAR_SIGN{}));
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
			if (captures.is_set(10)) {
				value = captures.character(10);
			} else {
				if (captures.is_set(9)) {
					value = captures.character(9);
				} else {
					if (captures.is_set(11)) {
						value = captures.character(11);
					}
				}
			}
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::modules::rule::regular::value::QUANTIFIER::id, Types::modules::rule::regular::value::QUANTIFIER{value}));
			break;
		}
		case 8: {
			char value;
			if (captures.is_set(10)) {
				value = captures.character(10);
			} else {
				if (captures.is_set(9)) {
					value = captures.character(9);
				} else {
					if (captures.is_set(11)) {
						value = captures.character(11);
					}
				}
			}
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::modules::rule::regular::value::QUANTIFIER::id, Types::modules::rule::regular::value::QUANTIFIER{value}));
			break;
		}
		case 9: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::COMMA::id, Types::COMMA{}));
			break;
		}
		case 10: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::modules::rule::regular::value::ANY::id, Types::modules::rule::regular::value::ANY{}));
			break;
		}
		case 11: {
			std::string floating = captures.text(2);
			std::string full = captures.text(1);
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::modules::common::NUMBER::id, Types::modules::common::NUMBER{full, floating}));
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
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Types::modules::common::template_params::LESS_THAN_SIGN{}));
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
			if (captures.is_set(10)) {
				value = captures.character(10);
			} else {
				if (captures.is_set(9)) {
					value = captures.character(9);
				} else {
					if (captures.is_set(11)) {
						value = captures.character(11);
					}
				}
			}
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::modules::rule::regular::value::QUANTIFIER::id, Types::modules::rule::regular::value::QUANTIFIER{value}));
			break;
		}
		case 18: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::COMMERCIAL_AT::id, Types::COMMERCIAL_AT{}));
			break;
		}
		case 19: {
			std::string value = captures.text(0);
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::modules::common::ID::id, Types::modules::common::ID{value}));
			break;
		}
		case 20: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::modules::grammar::modifier::RIGHT_SQUARE_BRACKET::id, Types::modules::grammar::modifier::RIGHT_SQUARE_BRACKET{}));
			break;
		}
		case 21: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::LEFT_CURLY_BRACKET::id, Types::LEFT_CURLY_BRACKET{}));
			break;
		}
		case 22: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Types::modules::rule::regular::value::alternative::VERTICAL_LINE{}));
			break;
		}
		case 23: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::RIGHT_CURLY_BRACKET::id, Types::RIGHT_CURLY_BRACKET{}));
			break;
		}
		case 24: {
			std::string value = captures.text(12);
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::modules::rule::regular::value::STRING::id, Types::modules::rule::regular::value::STRING{value}));
			break;
		}
		case 25: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::modules::grammar::modifier::AUTO::id, Types::modules::grammar::modifier::AUTO{}));
			break;
		}
		case 26: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::AUTO::id, Types::AUTO{}));
			break;
		}
		case 27: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id, Types::modules::rule::regular::value::shared_counter_registration::AUTO{}));
			break;
		}
		case 28: {
			std::string value = captures.text(0);
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::modules::common::ID::id, Types::modules::common::ID{value}));
			break;
		}
		case 29: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::modules::rule::regular::value::SPACE::id, Types::modules::rule::regular::value::SPACE{}));
			break;
		}
		case 30: {
			std::string floating = captures.text(2);
			std::string full = captures.text(1);
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::modules::common::NUMBER::id, Types::modules::common::NUMBER{full, floating}));
			break;
		}
		case 31: {
			std::string v = captures.text(5);
			char negative = captures.character(4);
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::modules::rule::regular::value::CGROUP::id, Types::modules::rule::regular::value::CGROUP{negative, v}));
			break;
		}
		case 32: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::modules::rule::regular::value::NOSPACE::id, Types::modules::rule::regular::value::NOSPACE{}));
			break;
		}
		case 33: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::modules::fail_block::fail_block::FAIL::id, Types::modules::fail_block::fail_block::FAIL{}));
			break;
		}
		case 34: {
			std::string value;
			if (captures.is_set(6)) {
				value = captures.text(6);
			} else {
				if (captures.is_set(8)) {
					value = captures.text(8);
				} else {
					if (captures.is_set(7)) {
						value = captures.text(7);
					}
				}
			}
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::modules::grammar::modifier::MOD::id, Types::modules::grammar::modifier::MOD{value}));
			break;
		}
		case 35: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id, Types::modules::rule::advanced::advanced_rule::regular_match::MATCH{}));
			break;
		}
		case 36: {
			std::string value = captures.text(3);
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::modules::common::PY_RAW::id, Types::modules::common::PY_RAW{value}));
			break;
		}
		case 37: {
			std::string value;
			if (captures.is_set(6)) {
				value = captures.text(6);
			} else {
				if (captures.is_set(8)) {
					value = captures.text(8);
				} else {
					if (captures.is_set(7)) {
						value = captures.text(7);
					}
				}
			}
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::modules::grammar::modifier::MOD::id, Types::modules::grammar::modifier::MOD{value}));
			break;
		}
		case 38: {
			std::string value;
			if (captures.is_set(6)) {
				value = captures.text(6);
			} else {
				if (captures.is_set(8)) {
					value = captures.text(8);
				} else {
					if (captures.is_set(7)) {
						value = captures.text(7);
					}
				}
			}
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::modules::grammar::modifier::MOD::id, Types::modules::grammar::modifier::MOD{value}));
			break;
		}
		case 39: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS::id, Types::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS{}));
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
::ISPA_STD::DFA::API::Table<104, 4> Parser::Lexer::action_table = {{{1, 0, ::ISPA_STD::DFA::API::null_state, 22}, {1, 26, ::ISPA_STD::DFA::API::null_state, 28}, {1, 26, ::ISPA_STD::DFA::API::null_state, 27}, {1, 26, ::ISPA_STD::DFA::API::null_state, 26}, {1, 26, ::ISPA_STD::DFA::API::null_state, 32}, {1, 26, ::ISPA_STD::DFA::API::null_state, 31}, {1, 26, ::ISPA_STD::DFA::API::null_state, 29}, {1, 2, ::ISPA_STD::DFA::API::null_state, 14}, {1, 18, ::ISPA_STD::DFA::API::null_state, 10}, {1, 20, ::ISPA_STD::DFA::API::null_state, 9}, {1, 22, ::ISPA_STD::DFA::API::null_state, 20}, {1, 26, ::ISPA_STD::DFA::API::null_state, 30}, {1, 24, ::ISPA_STD::DFA::API::null_state, 36}, {1, 24, ::ISPA_STD::DFA::API::null_state, 39}, {1, 26, ::ISPA_STD::DFA::API::null_state, 37}, {1, 21, ::ISPA_STD::DFA::API::null_state, 197}, {1, 19, ::ISPA_STD::DFA::API::null_state, 198}, {1, 3, ::ISPA_STD::DFA::API::null_state, 201}, {1, 3, ::ISPA_STD::DFA::API::null_state, 42}, {1, 23, ::ISPA_STD::DFA::API::null_state, 207}, {1, 1, ::ISPA_STD::DFA::API::null_state, 209}, {1, 10, ::ISPA_STD::DFA::API::null_state, 45}, {1, 10, ::ISPA_STD::DFA::API::null_state, 47}, {1, 10, ::ISPA_STD::DFA::API::null_state, 46}, {3, 0, 26, 209}, {1, 1, ::ISPA_STD::DFA::API::null_state, 110}, {3, 0, 26, 44}, {3, 0, 26, 209}, {1, 1, ::ISPA_STD::DFA::API::null_state, 113}, {3, 0, 26, 209}, {1, 1, ::ISPA_STD::DFA::API::null_state, 115}, {3, 0, 26, 209}, {1, 1, ::ISPA_STD::DFA::API::null_state, 117}, {3, 0, 26, 209}, {1, 1, ::ISPA_STD::DFA::API::null_state, 119}, {3, 0, 26, 209}, {1, 1, ::ISPA_STD::DFA::API::null_state, 121}, {3, 0, 26, 209}, {1, 1, ::ISPA_STD::DFA::API::null_state, 123}, {1, 25, ::ISPA_STD::DFA::API::null_state, 38}, {1, 25, ::ISPA_STD::DFA::API::null_state, 56}, {3, 24, 26, 36}, {3, 24, 26, 39}, {3, 24, 26, 38}, {1, 25, ::ISPA_STD::DFA::API::null_state, 129}, {3, 24, 26, 56}, {1, 25, ::ISPA_STD::DFA::API::null_state, 131}, {1, 4, ::ISPA_STD::DFA::API::null_state, 57}, {1, 1, ::ISPA_STD::DFA::API::null_state, 218}, {1, 11, ::ISPA_STD::DFA::API::null_state, 58}, {1, 9, ::ISPA_STD::DFA::API::null_state, 59}, {1, 9, ::ISPA_STD::DFA::API::null_state, 60}, {3, 0, 26, 218}, {1, 1, ::ISPA_STD::DFA::API::null_state, 138}, {3, 0, 26, 218}, {1, 1, ::ISPA_STD::DFA::API::null_state, 140}, {3, 0, 26, 218}, {1, 1, ::ISPA_STD::DFA::API::null_state, 142}, {3, 0, 26, 218}, {1, 1, ::ISPA_STD::DFA::API::null_state, 144}, {3, 0, 26, 218}, {1, 1, ::ISPA_STD::DFA::API::null_state, 146}, {1, 6, ::ISPA_STD::DFA::API::null_state, 67}, {3, 0, 26, 218}, {1, 1, ::ISPA_STD::DFA::API::null_state, 149}, {1, 5, ::ISPA_STD::DFA::API::null_state, 220}, {1, 11, ::ISPA_STD::DFA::API::null_state, 69}, {3, 0, 26, 218}, {1, 1, ::ISPA_STD::DFA::API::null_state, 153}, {3, 0, 26, 218}, {1, 1, ::ISPA_STD::DFA::API::null_state, 155}, {3, 0, 26, 218}, {1, 1, ::ISPA_STD::DFA::API::null_state, 157}, {3, 0, 26, 218}, {1, 1, ::ISPA_STD::DFA::API::null_state, 159}, {3, 0, 26, 218}, {1, 1, ::ISPA_STD::DFA::API::null_state, 161}, {3, 0, 26, 218}, {1, 1, ::ISPA_STD::DFA::API::null_state, 163}, {3, 10, 9, 221}, {3, 8, 10, 165}, {3, 0, 26, 218}, {1, 1, ::ISPA_STD::DFA::API::null_state, 167}, {3, 0, 26, 218}, {1, 1, ::ISPA_STD::DFA::API::null_state, 169}, {3, 0, 26, 218}, {1, 1, ::ISPA_STD::DFA::API::null_state, 171}, {3, 0, 26, 218}, {1, 1, ::ISPA_STD::DFA::API::null_state, 173}, {1, 7, ::ISPA_STD::DFA::API::null_state, 81}, {3, 14, 26, 224}, {1, 15, ::ISPA_STD::DFA::API::null_state, 176}, {3, 0, 26, 218}, {1, 1, ::ISPA_STD::DFA::API::null_state, 178}, {3, 0, 26, 218}, {1, 1, ::ISPA_STD::DFA::API::null_state, 180}, {3, 0, 26, 218}, {1, 1, ::ISPA_STD::DFA::API::null_state, 182}, {3, 0, 26, 218}, {1, 1, ::ISPA_STD::DFA::API::null_state, 184}, {3, 12, 26, 227}, {1, 13, ::ISPA_STD::DFA::API::null_state, 186}, {3, 16, 26, 228}, {1, 17, ::ISPA_STD::DFA::API::null_state, 188}}};
std::array<::ISPA_STD::DFA::API::DFADebug, 1> Parser::Lexer::debug_array = {::ISPA_STD::DFA::API::DFADebug {"<Undefined>", "", 0, -1, -1, -1, 0, 1, '\000'}};
std::unordered_map<long long, std::unordered_map<long long, long long>> Parser::Lexer::debug_index = { { 0, { { 1, 0 }, { 2, 0 }, { 3, 0 }, { 4, 0 }, { 5, 0 }, { 6, 0 }, { 7, 0 }, { 8, 0 }, { 9, 0 }, { 12, 0 }, { 13, 0 }, { 14, 0 }, { 17, 0 }, { 18, 0 }, { 19, 0 }, { 20, 0 }, { 21, 0 }, { 23, 0 }, { 25, 0 }, { 26, 0 }, { 27, 0 }, { 46, 0 }, { 47, 0 }, { 48, 0 } } }, { 1, { { 1, 0 } } }, { 2, { { 7, 0 } } }, { 3, { { 25, 0 } } }, { 12, { { 21, 0 } } }, { 14, { { 15, 0 }, { 16, 0 } } }, { 18, { { 21, 0 } } }, { 22, { { 15, 0 }, { 16, 0 }, { 24, 0 }, { 29, 0 }, { 30, 0 }, { 31, 0 }, { 32, 0 }, { 33, 0 }, { 34, 0 }, { 35, 0 }, { 36, 0 }, { 37, 0 }, { 38, 0 }, { 39, 0 }, { 40, 0 }, { 41, 0 }, { 42, 0 }, { 43, 0 }, { 44, 0 }, { 45, 0 } } }, { 24, { { 42, 0 } } }, { 26, { { 32, 0 } } }, { 27, { { 44, 0 } } }, { 28, { { 29, 0 } } }, { 29, { { 39, 0 } } }, { 30, { { 29, 0 } } }, { 31, { { 46, 0 } } }, { 32, { { 36, 0 } } }, { 36, { { 0, 0 }, { 1, 0 }, { 3, 0 }, { 4, 0 }, { 5, 0 }, { 6, 0 }, { 8, 0 }, { 9, 0 }, { 10, 0 }, { 11, 0 }, { 12, 0 }, { 13, 0 }, { 14, 0 }, { 15, 0 }, { 16, 0 }, { 17, 0 }, { 18, 0 }, { 19, 0 }, { 20, 0 }, { 21, 0 }, { 22, 0 }, { 23, 0 }, { 24, 0 }, { 25, 0 }, { 26, 0 }, { 27, 0 }, { 28, 0 }, { 29, 0 }, { 30, 0 }, { 31, 0 }, { 32, 0 }, { 33, 0 }, { 34, 0 }, { 35, 0 }, { 36, 0 }, { 37, 0 }, { 38, 0 }, { 39, 0 }, { 40, 0 }, { 41, 0 }, { 42, 0 }, { 43, 0 }, { 44, 0 }, { 45, 0 }, { 46, 0 }, { 47, 0 }, { 48, 0 } } }, { 39, { { 0, 0 }, { 1, 0 }, { 2, 0 }, { 3, 0 }, { 4, 0 }, { 5, 0 }, { 6, 0 }, { 7, 0 }, { 8, 0 }, { 9, 0 }, { 10, 0 }, { 11, 0 }, { 12, 0 }, { 13, 0 }, { 14, 0 }, { 15, 0 }, { 16, 0 }, { 17, 0 }, { 18, 0 }, { 19, 0 }, { 20, 0 }, { 21, 0 }, { 22, 0 }, { 23, 0 }, { 24, 0 }, { 25, 0 }, { 26, 0 }, { 27, 0 }, { 28, 0 }, { 29, 0 }, { 30, 0 }, { 31, 0 }, { 32, 0 }, { 33, 0 }, { 34, 0 }, { 35, 0 }, { 36, 0 }, { 37, 0 }, { 38, 0 }, { 39, 0 }, { 40, 0 }, { 41, 0 }, { 42, 0 }, { 43, 0 }, { 44, 0 }, { 45, 0 }, { 46, 0 }, { 47, 0 }, { 48, 0 } } }, { 44, { { 15, 0 }, { 16, 0 }, { 24, 0 }, { 29, 0 }, { 30, 0 }, { 31, 0 }, { 32, 0 }, { 33, 0 }, { 34, 0 }, { 35, 0 }, { 36, 0 }, { 37, 0 }, { 38, 0 }, { 39, 0 }, { 40, 0 }, { 41, 0 }, { 42, 0 }, { 43, 0 }, { 44, 0 }, { 45, 0 } } }, { 45, { { 0, 0 }, { 1, 0 }, { 2, 0 }, { 3, 0 }, { 4, 0 }, { 5, 0 }, { 6, 0 }, { 7, 0 }, { 8, 0 }, { 9, 0 }, { 10, 0 }, { 11, 0 }, { 12, 0 }, { 13, 0 }, { 14, 0 }, { 15, 0 }, { 16, 0 }, { 17, 0 }, { 18, 0 }, { 19, 0 }, { 20, 0 }, { 21, 0 }, { 22, 0 }, { 23, 0 }, { 24, 0 }, { 25, 0 }, { 26, 0 }, { 28, 0 }, { 29, 0 }, { 30, 0 }, { 31, 0 }, { 32, 0 }, { 33, 0 }, { 34, 0 }, { 35, 0 }, { 36, 0 }, { 37, 0 }, { 38, 0 }, { 39, 0 }, { 40, 0 }, { 41, 0 }, { 42, 0 }, { 43, 0 }, { 44, 0 }, { 45, 0 }, { 46, 0 }, { 47, 0 }, { 48, 0 } } }, { 46, { { 0, 0 }, { 1, 0 }, { 2, 0 }, { 3, 0 }, { 4, 0 }, { 5, 0 }, { 6, 0 }, { 7, 0 }, { 8, 0 }, { 9, 0 }, { 10, 0 }, { 11, 0 }, { 12, 0 }, { 13, 0 }, { 14, 0 }, { 15, 0 }, { 16, 0 }, { 17, 0 }, { 18, 0 }, { 19, 0 }, { 20, 0 }, { 21, 0 }, { 22, 0 }, { 23, 0 }, { 24, 0 }, { 25, 0 }, { 26, 0 }, { 27, 0 }, { 28, 0 }, { 29, 0 }, { 30, 0 }, { 31, 0 }, { 32, 0 }, { 33, 0 }, { 34, 0 }, { 35, 0 }, { 36, 0 }, { 37, 0 }, { 38, 0 }, { 39, 0 }, { 40, 0 }, { 41, 0 }, { 42, 0 }, { 43, 0 }, { 44, 0 }, { 45, 0 }, { 46, 0 }, { 47, 0 }, { 48, 0 } } }, { 48, { { 15, 0 } } }, { 49, { { 40, 0 } } }, { 50, { { 43, 0 } } }, { 51, { { 35, 0 } } }, { 52, { { 37, 0 } } }, { 53, { { 43, 0 } } }, { 55, { { 35, 0 } } }, { 56, { { 0, 0 }, { 1, 0 }, { 3, 0 }, { 4, 0 }, { 5, 0 }, { 6, 0 }, { 8, 0 }, { 9, 0 }, { 10, 0 }, { 11, 0 }, { 12, 0 }, { 13, 0 }, { 14, 0 }, { 15, 0 }, { 16, 0 }, { 17, 0 }, { 18, 0 }, { 19, 0 }, { 20, 0 }, { 21, 0 }, { 22, 0 }, { 23, 0 }, { 24, 0 }, { 25, 0 }, { 26, 0 }, { 27, 0 }, { 28, 0 }, { 29, 0 }, { 30, 0 }, { 31, 0 }, { 32, 0 }, { 33, 0 }, { 34, 0 }, { 35, 0 }, { 36, 0 }, { 37, 0 }, { 38, 0 }, { 39, 0 }, { 40, 0 }, { 41, 0 }, { 42, 0 }, { 43, 0 }, { 44, 0 }, { 45, 0 }, { 46, 0 }, { 47, 0 }, { 48, 0 } } }, { 57, { { 15, 0 }, { 16, 0 } } }, { 59, { { 0, 0 }, { 1, 0 }, { 2, 0 }, { 3, 0 }, { 4, 0 }, { 5, 0 }, { 6, 0 }, { 7, 0 }, { 8, 0 }, { 9, 0 }, { 10, 0 }, { 11, 0 }, { 12, 0 }, { 13, 0 }, { 14, 0 }, { 15, 0 }, { 16, 0 }, { 17, 0 }, { 18, 0 }, { 19, 0 }, { 20, 0 }, { 21, 0 }, { 22, 0 }, { 23, 0 }, { 24, 0 }, { 25, 0 }, { 26, 0 }, { 28, 0 }, { 29, 0 }, { 30, 0 }, { 31, 0 }, { 32, 0 }, { 33, 0 }, { 34, 0 }, { 35, 0 }, { 36, 0 }, { 37, 0 }, { 38, 0 }, { 39, 0 }, { 40, 0 }, { 41, 0 }, { 42, 0 }, { 43, 0 }, { 44, 0 }, { 45, 0 }, { 46, 0 }, { 47, 0 }, { 48, 0 } } }, { 60, { { 0, 0 }, { 1, 0 }, { 2, 0 }, { 3, 0 }, { 4, 0 }, { 5, 0 }, { 6, 0 }, { 7, 0 }, { 8, 0 }, { 9, 0 }, { 10, 0 }, { 11, 0 }, { 12, 0 }, { 13, 0 }, { 14, 0 }, { 15, 0 }, { 16, 0 }, { 17, 0 }, { 18, 0 }, { 19, 0 }, { 20, 0 }, { 21, 0 }, { 22, 0 }, { 23, 0 }, { 24, 0 }, { 25, 0 }, { 26, 0 }, { 27, 0 }, { 28, 0 }, { 29, 0 }, { 30, 0 }, { 31, 0 }, { 32, 0 }, { 33, 0 }, { 34, 0 }, { 35, 0 }, { 36, 0 }, { 37, 0 }, { 38, 0 }, { 39, 0 }, { 40, 0 }, { 41, 0 }, { 42, 0 }, { 43, 0 }, { 44, 0 }, { 45, 0 }, { 46, 0 }, { 47, 0 }, { 48, 0 } } }, { 62, { { 32, 0 } } }, { 63, { { 32, 0 } } }, { 64, { { 37, 0 } } }, { 65, { { 35, 0 } } }, { 66, { { 30, 0 } } }, { 67, { { 45, 0 } } }, { 68, { { 40, 0 } } }, { 70, { { 39, 0 } } }, { 71, { { 41, 0 } } }, { 73, { { 39, 0 } } }, { 74, { { 34, 0 } } }, { 77, { { 31, 0 } } }, { 78, { { 39, 0 } } }, { 79, { { 32, 0 } } }, { 82, { { 42, 0 } } } };
template<typename IT, class> auto Parser::Parser::main(IT pos) -> ::ISPA_STD::MatchResult<Types::main, IT> {
	::ISPA_STD::Node<Types::modules::main::main> value_modules_main_main;
	value_modules_main_main = required<Types::modules::main::main>(pos, [this](auto cursor) { return this->modulesMainMain(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id, Tokens::modules::fail_block::fail_block::FAIL::id, Tokens::modules::grammar::modifier::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("main", "modules::main::main"));
	Types::main result;
	::ISPA_STD::assign_compatible(result.value, value_modules_main_main);
	::ISPA_STD::MatchResult<Types::main, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::main<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::main, ::Parser::Lexer::iterator>;
template auto Parser::Parser::main<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::main, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::modulesRuleRegularValueShared_counter_registration(IT pos) -> ::ISPA_STD::MatchResult<Types::modules::rule::regular::value::shared_counter_registration, IT> {
	::ISPA_STD::Node<Types::modules::rule::regular::value::shared_counter_registration::AUTO> value_modules_rule_regular_value_shared_counter_registration_AUTO;
	::ISPA_STD::Node<Types::modules::common::ID> value_modules_common_ID;
	value_modules_rule_regular_value_shared_counter_registration_AUTO = required<Types::modules::rule::regular::value::shared_counter_registration::AUTO>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::rule::regular::value::shared_counter_registration", "modules::rule::regular::value::shared_counter_registration::AUTO"));
	skip_spaces<Types::__WS>(pos);
	value_modules_common_ID = required<Types::modules::common::ID>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::rule::regular::value::shared_counter_registration", "modules::common::ID"));
	Types::modules::rule::regular::value::shared_counter_registration result;
	::ISPA_STD::assign_compatible(result.value, value_modules_common_ID);
	::ISPA_STD::MatchResult<Types::modules::rule::regular::value::shared_counter_registration, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::modulesRuleRegularValueShared_counter_registration<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::modules::rule::regular::value::shared_counter_registration, ::Parser::Lexer::iterator>;
template auto Parser::Parser::modulesRuleRegularValueShared_counter_registration<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::modules::rule::regular::value::shared_counter_registration, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::modulesRuleRegularValueCounterBounded(IT pos) -> ::ISPA_STD::MatchResult<Types::modules::rule::regular::value::counter::bounded, IT> {
	::ISPA_STD::Node<Types::EQUALS_SIGN> value_EQUALS_SIGN;
	std::variant<std::monostate, ::ISPA_STD::Node<Types::modules::common::NUMBER>, ::ISPA_STD::Node<Types::modules::common::ID>, ::ISPA_STD::Node<Types::modules::common::expr>> choice0;
	bool matched0;
	::ISPA_STD::Node<Types::modules::common::NUMBER> value_modules_common_NUMBER;
	::ISPA_STD::Node<Types::modules::common::ID> value_modules_common_ID;
	::ISPA_STD::Node<Types::modules::common::expr> value_modules_common_expr;
	value_EQUALS_SIGN = required<Types::EQUALS_SIGN>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::EQUALS_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::PY_RAW::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::rule::regular::value::counter::bounded", "EQUALS_SIGN"));
	skip_spaces<Types::__WS>(pos);
	// grammar `@  ( modules::common::NUMBER |  modules::common::ID |  modules::common::expr)`: choice; alternative selected by LL(1) lookahead
	matched0 = false;
	auto la0_1 = pos;
	switch ((*la0_1).kind()) {
		case Tokens::modules::common::ID::id: {
			value_modules_common_ID = required<Types::modules::common::ID>(la0_1, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::PY_RAW::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value::counter::bounded", "<group>"));
			choice0 = value_modules_common_ID;
			matched0 = true;
			break;
		}
		case Tokens::modules::common::NUMBER::id: {
			value_modules_common_NUMBER = required<Types::modules::common::NUMBER>(la0_1, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::PY_RAW::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value::counter::bounded", "<group>"));
			choice0 = value_modules_common_NUMBER;
			matched0 = true;
			break;
		}
		case Tokens::modules::common::PY_RAW::id: {
			value_modules_common_expr = required<Types::modules::common::expr>(la0_1, [this](auto cursor) { return this->modulesCommonExpr(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::PY_RAW::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value::counter::bounded", "<group>"));
			choice0 = value_modules_common_expr;
			matched0 = true;
			break;
		}
	}
	pos = la0_1;
	if (!matched0) {
		raise_error(*pos, "ISPA match failure: expected one of: modules.common.NUMBER, modules.common.ID, modules.common.PY_RAW");
		return {};
	}
	Types::modules::rule::regular::value::counter::bounded result;
	::ISPA_STD::assign_compatible(result.value, choice0);
	::ISPA_STD::MatchResult<Types::modules::rule::regular::value::counter::bounded, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::modulesRuleRegularValueCounterBounded<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::modules::rule::regular::value::counter::bounded, ::Parser::Lexer::iterator>;
template auto Parser::Parser::modulesRuleRegularValueCounterBounded<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::modules::rule::regular::value::counter::bounded, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::modulesRuleRegularValueVar_capture(IT pos) -> ::ISPA_STD::MatchResult<Types::modules::rule::regular::value::var_capture, IT> {
	::ISPA_STD::Node<Types::AMPERSAND> value_AMPERSAND;
	::ISPA_STD::Node<Types::modules::common::ID> value_modules_common_ID;
	value_AMPERSAND = required<Types::AMPERSAND>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id>, ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Tokens<Tokens::COMMERCIAL_AT::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::rule::regular::value::var_capture", "AMPERSAND"));
	skip_spaces<Types::__WS>(pos);
	value_modules_common_ID = required<Types::modules::common::ID>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Tokens<Tokens::COMMERCIAL_AT::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::COMMERCIAL_AT::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::rule::regular::value::var_capture", "modules::common::ID"));
	Types::modules::rule::regular::value::var_capture result;
	::ISPA_STD::assign_compatible(result.value, value_modules_common_ID);
	::ISPA_STD::MatchResult<Types::modules::rule::regular::value::var_capture, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::modulesRuleRegularValueVar_capture<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::modules::rule::regular::value::var_capture, ::Parser::Lexer::iterator>;
template auto Parser::Parser::modulesRuleRegularValueVar_capture<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::modules::rule::regular::value::var_capture, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::modulesRuleRegularValueCounter(IT pos) -> ::ISPA_STD::MatchResult<Types::modules::rule::regular::value::counter, IT> {
	::ISPA_STD::Node<Types::modules::rule::regular::value::QUANTIFIER> value_modules_rule_regular_value_QUANTIFIER;
	::ISPA_STD::Node<Types::modules::rule::regular::value::counter::bounded> value_modules_rule_regular_value_counter_bounded;
	value_modules_rule_regular_value_QUANTIFIER = required<Types::modules::rule::regular::value::QUANTIFIER>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::modules::rule::regular::value::QUANTIFIER::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::rule::regular::value::counter", "modules::rule::regular::value::QUANTIFIER"));
	skip_spaces<Types::__WS>(pos);
	value_modules_rule_regular_value_counter_bounded = optional<Types::modules::rule::regular::value::counter::bounded>(pos, [this](auto cursor) { return this->modulesRuleRegularValueCounterBounded(cursor); });
	Types::modules::rule::regular::value::counter result;
	::ISPA_STD::assign_compatible(result.quantifier, value_modules_rule_regular_value_QUANTIFIER);
	::ISPA_STD::assign_compatible(result.repetitions, value_modules_rule_regular_value_counter_bounded);
	::ISPA_STD::MatchResult<Types::modules::rule::regular::value::counter, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::modulesRuleRegularValueCounter<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::modules::rule::regular::value::counter, ::Parser::Lexer::iterator>;
template auto Parser::Parser::modulesRuleRegularValueCounter<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::modules::rule::regular::value::counter, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::modulesCommonParams(IT pos) -> ::ISPA_STD::MatchResult<Types::modules::common::params, IT> {
	::ISPA_STD::Node<Types::GREATER_THAN_SIGN> value_GREATER_THAN_SIGN;
	::ISPA_STD::Node<Types::LEFT_PARENTHESIS> value_LEFT_PARENTHESIS;
	::ISPA_STD::Node<Types::modules::common::param> value_modules_common_param;
	::ISPA_STD::Node<Types::RIGHT_PARENTHESIS> value_RIGHT_PARENTHESIS;
	value_GREATER_THAN_SIGN = required<Types::GREATER_THAN_SIGN>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::GREATER_THAN_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::LEFT_PARENTHESIS::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COLON::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::common::PY_RAW::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::common::params", "GREATER_THAN_SIGN"));
	skip_spaces<Types::__WS>(pos);
	value_LEFT_PARENTHESIS = required<Types::LEFT_PARENTHESIS>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::LEFT_PARENTHESIS::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_PARENTHESIS::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COLON::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::common::PY_RAW::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::common::params", "LEFT_PARENTHESIS"));
	skip_spaces<Types::__WS>(pos);
	value_modules_common_param = optional<Types::modules::common::param>(pos, [this](auto cursor) { return this->modulesCommonParam(cursor); });
	skip_spaces<Types::__WS>(pos);
	value_RIGHT_PARENTHESIS = required<Types::RIGHT_PARENTHESIS>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::RIGHT_PARENTHESIS::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COLON::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::common::PY_RAW::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COLON::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::common::PY_RAW::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::common::params", "RIGHT_PARENTHESIS"));
	Types::modules::common::params result;
	::ISPA_STD::assign_compatible(result.value, value_modules_common_param);
	::ISPA_STD::MatchResult<Types::modules::common::params, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::modulesCommonParams<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::modules::common::params, ::Parser::Lexer::iterator>;
template auto Parser::Parser::modulesCommonParams<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::modules::common::params, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::modulesRuleRegularAstSingle_value(IT pos) -> ::ISPA_STD::MatchResult<Types::modules::rule::regular::ast::single_value, IT> {
	::ISPA_STD::Node<Types::LEFT_CURLY_BRACKET> value_LEFT_CURLY_BRACKET;
	std::variant<std::monostate, ::ISPA_STD::Node<Types::modules::common::expr>, ::ISPA_STD::Node<Types::COMMERCIAL_AT>> choice0;
	bool matched0;
	::ISPA_STD::Node<Types::modules::common::expr> value_modules_common_expr;
	::ISPA_STD::Node<Types::COMMERCIAL_AT> value_COMMERCIAL_AT;
	::ISPA_STD::Node<Types::RIGHT_CURLY_BRACKET> value_RIGHT_CURLY_BRACKET;
	value_LEFT_CURLY_BRACKET = required<Types::LEFT_CURLY_BRACKET>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::LEFT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::COMMERCIAL_AT::id, Tokens::modules::common::PY_RAW::id>, ISPA_STD::Recovery::Tokens<Tokens::PERCENT_SIGN::id, Tokens::SEMICOLON::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::rule::regular::ast::single_value", "LEFT_CURLY_BRACKET"));
	skip_spaces<Types::__WS>(pos);
	// grammar `@  ( modules::common::expr |  COMMERCIAL_AT)`: choice; alternative selected by LL(1) lookahead
	matched0 = false;
	auto la0_1 = pos;
	switch ((*la0_1).kind()) {
		case Tokens::COMMERCIAL_AT::id: {
			value_COMMERCIAL_AT = required<Types::COMMERCIAL_AT>(la0_1, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::COMMERCIAL_AT::id, Tokens::modules::common::PY_RAW::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::PERCENT_SIGN::id, Tokens::SEMICOLON::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::ast::single_value", "<group>"));
			choice0 = value_COMMERCIAL_AT;
			matched0 = true;
			break;
		}
		case Tokens::modules::common::PY_RAW::id: {
			value_modules_common_expr = required<Types::modules::common::expr>(la0_1, [this](auto cursor) { return this->modulesCommonExpr(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::COMMERCIAL_AT::id, Tokens::modules::common::PY_RAW::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::PERCENT_SIGN::id, Tokens::SEMICOLON::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::ast::single_value", "<group>"));
			choice0 = value_modules_common_expr;
			matched0 = true;
			break;
		}
	}
	pos = la0_1;
	if (!matched0) {
		raise_error(*pos, "ISPA match failure: expected one of: modules.common.PY_RAW, COMMERCIAL_AT");
		return {};
	}
	skip_spaces<Types::__WS>(pos);
	value_RIGHT_CURLY_BRACKET = required<Types::RIGHT_CURLY_BRACKET>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::PERCENT_SIGN::id, Tokens::SEMICOLON::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::PERCENT_SIGN::id, Tokens::SEMICOLON::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::rule::regular::ast::single_value", "RIGHT_CURLY_BRACKET"));
	Types::modules::rule::regular::ast::single_value result;
	::ISPA_STD::assign_compatible(result.value, choice0);
	::ISPA_STD::MatchResult<Types::modules::rule::regular::ast::single_value, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::modulesRuleRegularAstSingle_value<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::modules::rule::regular::ast::single_value, ::Parser::Lexer::iterator>;
template auto Parser::Parser::modulesRuleRegularAstSingle_value<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::modules::rule::regular::ast::single_value, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::modulesRuleRegularValueDynDyn_expr(IT pos) -> ::ISPA_STD::MatchResult<Types::modules::rule::regular::value::dyn::dyn_expr, IT> {
	::ISPA_STD::Node<Types::LEFT_CURLY_BRACKET> value_LEFT_CURLY_BRACKET;
	::ISPA_STD::Node<Types::modules::common::expr> value_modules_common_expr;
	::ISPA_STD::Node<Types::RIGHT_CURLY_BRACKET> value_RIGHT_CURLY_BRACKET;
	value_LEFT_CURLY_BRACKET = required<Types::LEFT_CURLY_BRACKET>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::LEFT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::modules::common::PY_RAW::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::rule::regular::value::dyn::dyn_expr", "LEFT_CURLY_BRACKET"));
	skip_spaces<Types::__WS>(pos);
	value_modules_common_expr = required<Types::modules::common::expr>(pos, [this](auto cursor) { return this->modulesCommonExpr(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::modules::common::PY_RAW::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value::dyn::dyn_expr", "modules::common::expr"));
	skip_spaces<Types::__WS>(pos);
	value_RIGHT_CURLY_BRACKET = required<Types::RIGHT_CURLY_BRACKET>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::rule::regular::value::dyn::dyn_expr", "RIGHT_CURLY_BRACKET"));
	Types::modules::rule::regular::value::dyn::dyn_expr result;
	::ISPA_STD::assign_compatible(result.value, value_modules_common_expr);
	::ISPA_STD::MatchResult<Types::modules::rule::regular::value::dyn::dyn_expr, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::modulesRuleRegularValueDynDyn_expr<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::modules::rule::regular::value::dyn::dyn_expr, ::Parser::Lexer::iterator>;
template auto Parser::Parser::modulesRuleRegularValueDynDyn_expr<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::modules::rule::regular::value::dyn::dyn_expr, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::modulesRuleRegularValueGroup(IT pos) -> ::ISPA_STD::MatchResult<Types::modules::rule::regular::value::group, IT> {
	::ISPA_STD::Node<Types::LEFT_PARENTHESIS> value_LEFT_PARENTHESIS;
	std::vector<::ISPA_STD::Node<Types::modules::rule::regular::value>> value_list_modules_rule_regular_value;
	::ISPA_STD::Node<Types::RIGHT_PARENTHESIS> value_RIGHT_PARENTHESIS;
	value_LEFT_PARENTHESIS = required<Types::LEFT_PARENTHESIS>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::LEFT_PARENTHESIS::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::rule::regular::value::group", "LEFT_PARENTHESIS"));
	skip_spaces<Types::__WS>(pos);
	value_list_modules_rule_regular_value = range<Types::modules::rule::regular::value, Types::__WS>(pos, [this](auto cursor) { return this->modulesRuleRegularValue(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_PARENTHESIS::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value::group", "modules::rule::regular::value"));
	skip_spaces<Types::__WS>(pos);
	value_RIGHT_PARENTHESIS = required<Types::RIGHT_PARENTHESIS>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::RIGHT_PARENTHESIS::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::rule::regular::value::group", "RIGHT_PARENTHESIS"));
	Types::modules::rule::regular::value::group result;
	::ISPA_STD::assign_compatible(result.value, value_list_modules_rule_regular_value);
	::ISPA_STD::MatchResult<Types::modules::rule::regular::value::group, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::modulesRuleRegularValueGroup<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::modules::rule::regular::value::group, ::Parser::Lexer::iterator>;
template auto Parser::Parser::modulesRuleRegularValueGroup<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::modules::rule::regular::value::group, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::modulesRuleRegularValuePattern(IT pos) -> ::ISPA_STD::MatchResult<Types::modules::rule::regular::value::pattern, IT> {
	std::variant<std::monostate, ::ISPA_STD::Node<Types::modules::common::name>, ::ISPA_STD::Node<Types::modules::rule::regular::value::group>, ::ISPA_STD::Node<Types::modules::rule::regular::value::dyn>, ::ISPA_STD::Node<Types::modules::rule::regular::value::STRING>, ::ISPA_STD::Node<Types::modules::rule::regular::value::CGROUP>, ::ISPA_STD::Node<Types::modules::rule::regular::value::ANY>, ::ISPA_STD::Node<Types::modules::rule::regular::value::SPACE>, ::ISPA_STD::Node<Types::modules::rule::regular::value::NOSPACE>> choice0;
	bool matched0;
	::ISPA_STD::Node<Types::modules::common::name> value_modules_common_name;
	::ISPA_STD::Node<Types::modules::rule::regular::value::group> value_modules_rule_regular_value_group;
	::ISPA_STD::Node<Types::modules::rule::regular::value::dyn> value_modules_rule_regular_value_dyn;
	::ISPA_STD::Node<Types::modules::rule::regular::value::STRING> value_modules_rule_regular_value_STRING;
	::ISPA_STD::Node<Types::modules::rule::regular::value::CGROUP> value_modules_rule_regular_value_CGROUP;
	::ISPA_STD::Node<Types::modules::rule::regular::value::ANY> value_modules_rule_regular_value_ANY;
	::ISPA_STD::Node<Types::modules::rule::regular::value::SPACE> value_modules_rule_regular_value_SPACE;
	::ISPA_STD::Node<Types::modules::rule::regular::value::NOSPACE> value_modules_rule_regular_value_NOSPACE;
	// grammar `@  ( modules::common::name |  modules::rule::regular::value::group |  modules::rule::regular::value::dyn |  modules::rule::regular::value::STRING |  modules::rule::regular::value::CGROUP |  modules::rule::regular::value::ANY |  modules::rule::regular::value::SPACE |  modules::rule::regular::value::NOSPACE)`: choice; alternative selected by LL(1) lookahead
	matched0 = false;
	auto la0_1 = pos;
	switch ((*la0_1).kind()) {
		case Tokens::LEFT_PARENTHESIS::id: {
			value_modules_rule_regular_value_group = required<Types::modules::rule::regular::value::group>(la0_1, [this](auto cursor) { return this->modulesRuleRegularValueGroup(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::LEFT_PARENTHESIS::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value::pattern", "<group>"));
			choice0 = value_modules_rule_regular_value_group;
			matched0 = true;
			break;
		}
		case Tokens::modules::common::ID::id: {
			value_modules_common_name = required<Types::modules::common::name>(la0_1, [this](auto cursor) { return this->modulesCommonName(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::LEFT_PARENTHESIS::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value::pattern", "<group>"));
			choice0 = value_modules_common_name;
			matched0 = true;
			break;
		}
		case Tokens::modules::rule::regular::value::ANY::id: {
			value_modules_rule_regular_value_ANY = required<Types::modules::rule::regular::value::ANY>(la0_1, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::LEFT_PARENTHESIS::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value::pattern", "<group>"));
			choice0 = value_modules_rule_regular_value_ANY;
			matched0 = true;
			break;
		}
		case Tokens::modules::rule::regular::value::CGROUP::id: {
			value_modules_rule_regular_value_CGROUP = required<Types::modules::rule::regular::value::CGROUP>(la0_1, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::LEFT_PARENTHESIS::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value::pattern", "<group>"));
			choice0 = value_modules_rule_regular_value_CGROUP;
			matched0 = true;
			break;
		}
		case Tokens::modules::rule::regular::value::NOSPACE::id: {
			value_modules_rule_regular_value_NOSPACE = required<Types::modules::rule::regular::value::NOSPACE>(la0_1, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::LEFT_PARENTHESIS::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value::pattern", "<group>"));
			choice0 = value_modules_rule_regular_value_NOSPACE;
			matched0 = true;
			break;
		}
		case Tokens::modules::rule::regular::value::SPACE::id: {
			value_modules_rule_regular_value_SPACE = required<Types::modules::rule::regular::value::SPACE>(la0_1, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::LEFT_PARENTHESIS::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value::pattern", "<group>"));
			choice0 = value_modules_rule_regular_value_SPACE;
			matched0 = true;
			break;
		}
		case Tokens::modules::rule::regular::value::STRING::id: {
			value_modules_rule_regular_value_STRING = required<Types::modules::rule::regular::value::STRING>(la0_1, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::LEFT_PARENTHESIS::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value::pattern", "<group>"));
			choice0 = value_modules_rule_regular_value_STRING;
			matched0 = true;
			break;
		}
		case Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id: {
			value_modules_rule_regular_value_dyn = required<Types::modules::rule::regular::value::dyn>(la0_1, [this](auto cursor) { return this->modulesRuleRegularValueDyn(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::LEFT_PARENTHESIS::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value::pattern", "<group>"));
			choice0 = value_modules_rule_regular_value_dyn;
			matched0 = true;
			break;
		}
	}
	pos = la0_1;
	if (!matched0) {
		raise_error(*pos, "ISPA match failure: expected one of: modules.common.ID, LEFT_PARENTHESIS, modules.rule.regular.value.dyn.DOLLAR_SIGN, modules.rule.regular.value.STRING, modules.rule.regular.value.CGROUP, modules.rule.regular.value.ANY, modules.rule.regular.value.SPACE, modules.rule.regular.value.NOSPACE");
		return {};
	}
	Types::modules::rule::regular::value::pattern result;
	::ISPA_STD::assign_compatible(result.value, choice0);
	::ISPA_STD::MatchResult<Types::modules::rule::regular::value::pattern, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::modulesRuleRegularValuePattern<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::modules::rule::regular::value::pattern, ::Parser::Lexer::iterator>;
template auto Parser::Parser::modulesRuleRegularValuePattern<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::modules::rule::regular::value::pattern, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::modulesRuleRegularValueFail_capture(IT pos) -> ::ISPA_STD::MatchResult<Types::modules::rule::regular::value::fail_capture, IT> {
	::ISPA_STD::Node<Types::PERCENT_SIGN> value_PERCENT_SIGN;
	::ISPA_STD::Node<Types::modules::common::name> value_modules_common_name;
	value_PERCENT_SIGN = required<Types::PERCENT_SIGN>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::PERCENT_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::LEFT_PARENTHESIS::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::LEFT_PARENTHESIS::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::rule::regular::value::fail_capture", "PERCENT_SIGN"));
	value_modules_common_name = optional<Types::modules::common::name>(pos, [this](auto cursor) { return this->modulesCommonName(cursor); });
	Types::modules::rule::regular::value::fail_capture result;
	::ISPA_STD::assign_compatible(result.value, value_modules_common_name);
	::ISPA_STD::MatchResult<Types::modules::rule::regular::value::fail_capture, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::modulesRuleRegularValueFail_capture<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::modules::rule::regular::value::fail_capture, ::Parser::Lexer::iterator>;
template auto Parser::Parser::modulesRuleRegularValueFail_capture<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::modules::rule::regular::value::fail_capture, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::modulesRuleRegularValueAst_capture(IT pos) -> ::ISPA_STD::MatchResult<Types::modules::rule::regular::value::ast_capture, IT> {
	::ISPA_STD::Node<Types::COMMERCIAL_AT> value_COMMERCIAL_AT;
	::ISPA_STD::Node<Types::modules::common::ID> value_modules_common_ID;
	value_COMMERCIAL_AT = required<Types::COMMERCIAL_AT>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::COMMERCIAL_AT::id>, ISPA_STD::Recovery::Tokens<Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::rule::regular::value::ast_capture", "COMMERCIAL_AT"));
	value_modules_common_ID = optional<Types::modules::common::ID>(pos);
	Types::modules::rule::regular::value::ast_capture result;
	::ISPA_STD::assign_compatible(result.value, value_modules_common_ID);
	::ISPA_STD::MatchResult<Types::modules::rule::regular::value::ast_capture, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::modulesRuleRegularValueAst_capture<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::modules::rule::regular::value::ast_capture, ::Parser::Lexer::iterator>;
template auto Parser::Parser::modulesRuleRegularValueAst_capture<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::modules::rule::regular::value::ast_capture, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::modulesRuleRegularAstFull(IT pos) -> ::ISPA_STD::MatchResult<Types::modules::rule::regular::ast::full, IT> {
	::ISPA_STD::Node<Types::AMPERSAND> value_AMPERSAND;
	::ISPA_STD::Node<Types::LEFT_CURLY_BRACKET> value_LEFT_CURLY_BRACKET;
	std::vector<::ISPA_STD::Node<Types::modules::rule::regular::ast::full::part>> value_list_modules_rule_regular_ast_full_part;
	::ISPA_STD::Node<Types::RIGHT_CURLY_BRACKET> value_RIGHT_CURLY_BRACKET;
	value_AMPERSAND = required<Types::AMPERSAND>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id>, ISPA_STD::Recovery::Tokens<Tokens::LEFT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::PERCENT_SIGN::id, Tokens::SEMICOLON::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::rule::regular::ast::full", "AMPERSAND"));
	skip_spaces<Types::__WS>(pos);
	value_LEFT_CURLY_BRACKET = required<Types::LEFT_CURLY_BRACKET>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::LEFT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Tokens<Tokens::PERCENT_SIGN::id, Tokens::SEMICOLON::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::rule::regular::ast::full", "LEFT_CURLY_BRACKET"));
	skip_spaces<Types::__WS>(pos);
	value_list_modules_rule_regular_ast_full_part = range<Types::modules::rule::regular::ast::full::part, Types::__WS>(pos, [this](auto cursor) { return this->modulesRuleRegularAstFullPart(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::PERCENT_SIGN::id, Tokens::SEMICOLON::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::ast::full", "modules::rule::regular::ast::full::part"));
	skip_spaces<Types::__WS>(pos);
	value_RIGHT_CURLY_BRACKET = required<Types::RIGHT_CURLY_BRACKET>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::PERCENT_SIGN::id, Tokens::SEMICOLON::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::PERCENT_SIGN::id, Tokens::SEMICOLON::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::rule::regular::ast::full", "RIGHT_CURLY_BRACKET"));
	Types::modules::rule::regular::ast::full result;
	::ISPA_STD::assign_compatible(result.value, value_list_modules_rule_regular_ast_full_part);
	::ISPA_STD::MatchResult<Types::modules::rule::regular::ast::full, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::modulesRuleRegularAstFull<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::modules::rule::regular::ast::full, ::Parser::Lexer::iterator>;
template auto Parser::Parser::modulesRuleRegularAstFull<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::modules::rule::regular::ast::full, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::modulesRuleRegularValueOne_capture(IT pos) -> ::ISPA_STD::MatchResult<Types::modules::rule::regular::value::one_capture, IT> {
	::ISPA_STD::Node<Types::modules::rule::regular::value::var_capture> value_modules_rule_regular_value_var_capture;
	::ISPA_STD::Node<Types::modules::rule::regular::value::ast_capture> value_modules_rule_regular_value_ast_capture;
	::ISPA_STD::Node<Types::modules::rule::regular::value::fail_capture> value_modules_rule_regular_value_fail_capture;
	::ISPA_STD::Node<Types::modules::rule::regular::value::pattern> value_modules_rule_regular_value_pattern;
	std::vector<::ISPA_STD::Node<Types::modules::rule::regular::value::alternative>> value_list_modules_rule_regular_value_alternative;
	::ISPA_STD::Node<Types::modules::rule::regular::value::counter> value_modules_rule_regular_value_counter;
	::ISPA_STD::Node<Types::modules::rule::regular::value::shared_counter_registration> value_modules_rule_regular_value_shared_counter_registration;
	value_modules_rule_regular_value_var_capture = optional<Types::modules::rule::regular::value::var_capture>(pos, [this](auto cursor) { return this->modulesRuleRegularValueVar_capture(cursor); });
	skip_spaces<Types::__WS>(pos);
	value_modules_rule_regular_value_ast_capture = optional<Types::modules::rule::regular::value::ast_capture>(pos, [this](auto cursor) { return this->modulesRuleRegularValueAst_capture(cursor); });
	skip_spaces<Types::__WS>(pos);
	value_modules_rule_regular_value_fail_capture = optional<Types::modules::rule::regular::value::fail_capture>(pos, [this](auto cursor) { return this->modulesRuleRegularValueFail_capture(cursor); });
	skip_spaces<Types::__WS>(pos);
	value_modules_rule_regular_value_pattern = required<Types::modules::rule::regular::value::pattern>(pos, [this](auto cursor) { return this->modulesRuleRegularValuePattern(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::LEFT_PARENTHESIS::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value::one_capture", "modules::rule::regular::value::pattern"));
	skip_spaces<Types::__WS>(pos);
	value_list_modules_rule_regular_value_alternative = range_optional<Types::modules::rule::regular::value::alternative, Types::__WS>(pos, [this](auto cursor) { return this->modulesRuleRegularValueAlternative(cursor); });
	skip_spaces<Types::__WS>(pos);
	value_modules_rule_regular_value_counter = optional<Types::modules::rule::regular::value::counter>(pos, [this](auto cursor) { return this->modulesRuleRegularValueCounter(cursor); });
	skip_spaces<Types::__WS>(pos);
	value_modules_rule_regular_value_shared_counter_registration = optional<Types::modules::rule::regular::value::shared_counter_registration>(pos, [this](auto cursor) { return this->modulesRuleRegularValueShared_counter_registration(cursor); });
	Types::modules::rule::regular::value::one_capture result;
	::ISPA_STD::assign_compatible(result.v_cap, value_modules_rule_regular_value_var_capture);
	::ISPA_STD::assign_compatible(result.ast_cap, value_modules_rule_regular_value_ast_capture);
	::ISPA_STD::assign_compatible(result.fail_cap, value_modules_rule_regular_value_fail_capture);
	::ISPA_STD::assign_compatible(result.val, value_modules_rule_regular_value_pattern);
	::ISPA_STD::assign_compatible(result.alts, value_list_modules_rule_regular_value_alternative);
	::ISPA_STD::assign_compatible(result.quantifier, value_modules_rule_regular_value_counter);
	::ISPA_STD::assign_compatible(result.registration, value_modules_rule_regular_value_shared_counter_registration);
	::ISPA_STD::MatchResult<Types::modules::rule::regular::value::one_capture, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::modulesRuleRegularValueOne_capture<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::modules::rule::regular::value::one_capture, ::Parser::Lexer::iterator>;
template auto Parser::Parser::modulesRuleRegularValueOne_capture<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::modules::rule::regular::value::one_capture, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::modulesRuleRegularAstAbbr(IT pos) -> ::ISPA_STD::MatchResult<Types::modules::rule::regular::ast::abbr, IT> {
	::ISPA_STD::Node<Types::COMMERCIAL_AT> value_COMMERCIAL_AT;
	::ISPA_STD::Node<Types::LEFT_CURLY_BRACKET> value_LEFT_CURLY_BRACKET;
	::ISPA_STD::Node<Types::modules::common::ID> value_modules_common_ID;
	::ISPA_STD::Node<Types::COMMA> value_COMMA;
	::ISPA_STD::Node<Types::modules::common::ID> value_modules_common_ID_1;
	std::pair<::ISPA_STD::Node<Types::COMMA>, ::ISPA_STD::Node<Types::modules::common::ID>> group0;
	std::vector<std::pair<::ISPA_STD::Node<Types::COMMA>, ::ISPA_STD::Node<Types::modules::common::ID>>> group_list1;
	std::vector<::ISPA_STD::Node<Types::modules::common::ID>> capture_list2;
	::ISPA_STD::Node<Types::RIGHT_CURLY_BRACKET> value_RIGHT_CURLY_BRACKET;
	value_COMMERCIAL_AT = required<Types::COMMERCIAL_AT>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::COMMERCIAL_AT::id>, ISPA_STD::Recovery::Tokens<Tokens::LEFT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::PERCENT_SIGN::id, Tokens::SEMICOLON::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::rule::regular::ast::abbr", "COMMERCIAL_AT"));
	skip_spaces<Types::__WS>(pos);
	value_LEFT_CURLY_BRACKET = required<Types::LEFT_CURLY_BRACKET>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::LEFT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Tokens<Tokens::PERCENT_SIGN::id, Tokens::SEMICOLON::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::rule::regular::ast::abbr", "LEFT_CURLY_BRACKET"));
	skip_spaces<Types::__WS>(pos);
	value_modules_common_ID = required<Types::modules::common::ID>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Tokens<Tokens::COMMA::id, Tokens::RIGHT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::PERCENT_SIGN::id, Tokens::SEMICOLON::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::rule::regular::ast::abbr", "modules::common::ID"));
	skip_spaces<Types::__WS>(pos);
	// grammar ` ( COMMA  __WS?; @  modules::common::ID)*;`: repeat while lookahead is in FIRST
	while (((*pos).kind() == Tokens::COMMA::id)) {
		value_COMMA = required<Types::COMMA>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::COMMA::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::PERCENT_SIGN::id, Tokens::SEMICOLON::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::ast::abbr", "<group>"));
		skip_spaces<Types::__WS>(pos);
		value_modules_common_ID_1 = required<Types::modules::common::ID>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::COMMA::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::PERCENT_SIGN::id, Tokens::SEMICOLON::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::ast::abbr", "<group>"));
		group0 = std::make_pair(value_COMMA, value_modules_common_ID_1);
		group_list1.push_back(group0);
		capture_list2.push_back(value_modules_common_ID_1);
		skip_spaces<Types::__WS>(pos);
	}
	skip_spaces<Types::__WS>(pos);
	value_RIGHT_CURLY_BRACKET = required<Types::RIGHT_CURLY_BRACKET>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::PERCENT_SIGN::id, Tokens::SEMICOLON::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::PERCENT_SIGN::id, Tokens::SEMICOLON::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::rule::regular::ast::abbr", "RIGHT_CURLY_BRACKET"));
	Types::modules::rule::regular::ast::abbr result;
	::ISPA_STD::assign_compatible(result.f, value_modules_common_ID);
	::ISPA_STD::assign_compatible(result.seq, capture_list2);
	::ISPA_STD::MatchResult<Types::modules::rule::regular::ast::abbr, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::modulesRuleRegularAstAbbr<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::modules::rule::regular::ast::abbr, ::Parser::Lexer::iterator>;
template auto Parser::Parser::modulesRuleRegularAstAbbr<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::modules::rule::regular::ast::abbr, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::modulesRuleRegularAstFullPart(IT pos) -> ::ISPA_STD::MatchResult<Types::modules::rule::regular::ast::full::part, IT> {
	::ISPA_STD::Node<Types::modules::common::ID> value_modules_common_ID;
	::ISPA_STD::Node<Types::COLON> value_COLON;
	::ISPA_STD::Node<Types::modules::common::expr> value_modules_common_expr;
	value_modules_common_ID = required<Types::modules::common::ID>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Tokens<Tokens::COLON::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::rule::regular::ast::full::part", "modules::common::ID"));
	skip_spaces<Types::__WS>(pos);
	value_COLON = required<Types::COLON>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::COLON::id>, ISPA_STD::Recovery::Tokens<Tokens::modules::common::PY_RAW::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::rule::regular::ast::full::part", "COLON"));
	skip_spaces<Types::__WS>(pos);
	value_modules_common_expr = required<Types::modules::common::expr>(pos, [this](auto cursor) { return this->modulesCommonExpr(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::modules::common::PY_RAW::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::ast::full::part", "modules::common::expr"));
	Types::modules::rule::regular::ast::full::part result;
	::ISPA_STD::assign_compatible(result.key, value_modules_common_ID);
	::ISPA_STD::assign_compatible(result.e, value_modules_common_expr);
	::ISPA_STD::MatchResult<Types::modules::rule::regular::ast::full::part, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::modulesRuleRegularAstFullPart<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::modules::rule::regular::ast::full::part, ::Parser::Lexer::iterator>;
template auto Parser::Parser::modulesRuleRegularAstFullPart<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::modules::rule::regular::ast::full::part, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::modulesRuleAdvancedAdvanced_ruleRegular_matchUnpack(IT pos) -> ::ISPA_STD::MatchResult<Types::modules::rule::advanced::advanced_rule::regular_match::unpack, IT> {
	::ISPA_STD::Node<Types::AUTO> value_AUTO;
	std::vector<::ISPA_STD::Node<Types::modules::common::ID>> value_list_modules_common_ID;
	value_AUTO = required<Types::AUTO>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id, Tokens::modules::common::PY_RAW::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::rule::advanced::advanced_rule::regular_match::unpack", "AUTO"));
	skip_spaces<Types::__WS>(pos);
	value_list_modules_common_ID = range<Types::modules::common::ID, Types::__WS>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id, Tokens::modules::common::PY_RAW::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id, Tokens::modules::common::PY_RAW::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::rule::advanced::advanced_rule::regular_match::unpack", "modules::common::ID"));
	Types::modules::rule::advanced::advanced_rule::regular_match::unpack result;
	::ISPA_STD::assign_compatible(result.value, value_list_modules_common_ID);
	::ISPA_STD::MatchResult<Types::modules::rule::advanced::advanced_rule::regular_match::unpack, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::modulesRuleAdvancedAdvanced_ruleRegular_matchUnpack<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::modules::rule::advanced::advanced_rule::regular_match::unpack, ::Parser::Lexer::iterator>;
template auto Parser::Parser::modulesRuleAdvancedAdvanced_ruleRegular_matchUnpack<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::modules::rule::advanced::advanced_rule::regular_match::unpack, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::modulesRuleRegularAst(IT pos) -> ::ISPA_STD::MatchResult<Types::modules::rule::regular::ast, IT> {
	std::variant<std::monostate, ::ISPA_STD::Node<Types::modules::rule::regular::ast::abbr>, ::ISPA_STD::Node<Types::modules::rule::regular::ast::full>, ::ISPA_STD::Node<Types::modules::rule::regular::ast::single_value>> choice0;
	bool matched0;
	::ISPA_STD::Node<Types::modules::rule::regular::ast::abbr> value_modules_rule_regular_ast_abbr;
	::ISPA_STD::Node<Types::modules::rule::regular::ast::full> value_modules_rule_regular_ast_full;
	::ISPA_STD::Node<Types::modules::rule::regular::ast::single_value> value_modules_rule_regular_ast_single_value;
	// grammar `@  ( modules::rule::regular::ast::abbr |  modules::rule::regular::ast::full |  modules::rule::regular::ast::single_value)`: choice; alternative selected by LL(1) lookahead
	matched0 = false;
	auto la0_1 = pos;
	switch ((*la0_1).kind()) {
		case Tokens::AMPERSAND::id: {
			value_modules_rule_regular_ast_full = required<Types::modules::rule::regular::ast::full>(la0_1, [this](auto cursor) { return this->modulesRuleRegularAstFull(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::PERCENT_SIGN::id, Tokens::SEMICOLON::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::PERCENT_SIGN::id, Tokens::SEMICOLON::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::ast", "<group>"));
			choice0 = value_modules_rule_regular_ast_full;
			matched0 = true;
			break;
		}
		case Tokens::COMMERCIAL_AT::id: {
			value_modules_rule_regular_ast_abbr = required<Types::modules::rule::regular::ast::abbr>(la0_1, [this](auto cursor) { return this->modulesRuleRegularAstAbbr(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::PERCENT_SIGN::id, Tokens::SEMICOLON::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::PERCENT_SIGN::id, Tokens::SEMICOLON::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::ast", "<group>"));
			choice0 = value_modules_rule_regular_ast_abbr;
			matched0 = true;
			break;
		}
		case Tokens::LEFT_CURLY_BRACKET::id: {
			value_modules_rule_regular_ast_single_value = required<Types::modules::rule::regular::ast::single_value>(la0_1, [this](auto cursor) { return this->modulesRuleRegularAstSingle_value(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::PERCENT_SIGN::id, Tokens::SEMICOLON::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::PERCENT_SIGN::id, Tokens::SEMICOLON::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::ast", "<group>"));
			choice0 = value_modules_rule_regular_ast_single_value;
			matched0 = true;
			break;
		}
	}
	pos = la0_1;
	if (!matched0) {
		raise_error(*pos, "ISPA match failure: expected one of: COMMERCIAL_AT, AMPERSAND, LEFT_CURLY_BRACKET");
		return {};
	}
	Types::modules::rule::regular::ast result;
	::ISPA_STD::assign_compatible(result.value, choice0);
	::ISPA_STD::MatchResult<Types::modules::rule::regular::ast, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::modulesRuleRegularAst<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::modules::rule::regular::ast, ::Parser::Lexer::iterator>;
template auto Parser::Parser::modulesRuleRegularAst<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::modules::rule::regular::ast, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::modulesRuleRegularRegular_rule(IT pos) -> ::ISPA_STD::MatchResult<Types::modules::rule::regular::regular_rule, IT> {
	::ISPA_STD::Node<Types::COLON> value_COLON;
	std::vector<::ISPA_STD::Node<Types::modules::rule::regular::value>> value_list_modules_rule_regular_value;
	::ISPA_STD::Node<Types::modules::rule::regular::ast> value_modules_rule_regular_ast;
	::ISPA_STD::Node<Types::modules::rule::regular::f_binding> value_modules_rule_regular_f_binding;
	std::vector<::ISPA_STD::Node<Types::modules::rule::regular::nested_rule>> value_list_modules_rule_regular_nested_rule;
	::ISPA_STD::Node<Types::SEMICOLON> value_SEMICOLON;
	value_COLON = required<Types::COLON>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::COLON::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::fail_block::fail_block::FAIL::id, Tokens::modules::grammar::modifier::AUTO::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::rule::regular::regular_rule", "COLON"));
	skip_spaces<Types::__WS>(pos);
	value_list_modules_rule_regular_value = range<Types::modules::rule::regular::value, Types::__WS>(pos, [this](auto cursor) { return this->modulesRuleRegularValue(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::PERCENT_SIGN::id, Tokens::SEMICOLON::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::fail_block::fail_block::FAIL::id, Tokens::modules::grammar::modifier::AUTO::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::regular_rule", "modules::rule::regular::value"));
	skip_spaces<Types::__WS>(pos);
	value_modules_rule_regular_ast = optional<Types::modules::rule::regular::ast>(pos, [this](auto cursor) { return this->modulesRuleRegularAst(cursor); });
	skip_spaces<Types::__WS>(pos);
	value_modules_rule_regular_f_binding = optional<Types::modules::rule::regular::f_binding>(pos, [this](auto cursor) { return this->modulesRuleRegularF_binding(cursor); });
	skip_spaces<Types::__WS>(pos);
	value_list_modules_rule_regular_nested_rule = range_optional<Types::modules::rule::regular::nested_rule, Types::__WS>(pos, [this](auto cursor) { return this->modulesRuleRegularNested_rule(cursor); });
	skip_spaces<Types::__WS>(pos);
	value_SEMICOLON = required<Types::SEMICOLON>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::SEMICOLON::id>, ISPA_STD::Recovery::Tokens<Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::fail_block::fail_block::FAIL::id, Tokens::modules::grammar::modifier::AUTO::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::fail_block::fail_block::FAIL::id, Tokens::modules::grammar::modifier::AUTO::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::rule::regular::regular_rule", "SEMICOLON"));
	Types::modules::rule::regular::regular_rule result;
	::ISPA_STD::assign_compatible(result.v, value_list_modules_rule_regular_value);
	::ISPA_STD::assign_compatible(result.ast_pointer, value_modules_rule_regular_ast);
	::ISPA_STD::assign_compatible(result.fail_pointer, value_modules_rule_regular_f_binding);
	::ISPA_STD::assign_compatible(result.nested, value_list_modules_rule_regular_nested_rule);
	::ISPA_STD::MatchResult<Types::modules::rule::regular::regular_rule, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::modulesRuleRegularRegular_rule<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::modules::rule::regular::regular_rule, ::Parser::Lexer::iterator>;
template auto Parser::Parser::modulesRuleRegularRegular_rule<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::modules::rule::regular::regular_rule, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::modulesRuleRegularValue(IT pos) -> ::ISPA_STD::MatchResult<Types::modules::rule::regular::value, IT> {
	std::variant<std::monostate, ::ISPA_STD::Node<Types::modules::rule::regular::value::one_capture>, ::ISPA_STD::Node<Types::modules::rule::regular::value::mul_capture>> choice0;
	bool matched0;
	::ISPA_STD::Node<Types::modules::rule::regular::value::one_capture> value_modules_rule_regular_value_one_capture;
	::ISPA_STD::Node<Types::modules::rule::regular::value::mul_capture> value_modules_rule_regular_value_mul_capture;
	// grammar `@  ( modules::rule::regular::value::one_capture |  modules::rule::regular::value::mul_capture)`: choice; alternative selected by LL(2) lookahead
	matched0 = false;
	auto la0_1 = pos;
	switch ((*la0_1).kind()) {
		case Tokens::AMPERSAND::id: {
			value_modules_rule_regular_value_one_capture = required<Types::modules::rule::regular::value::one_capture>(la0_1, [this](auto cursor) { return this->modulesRuleRegularValueOne_capture(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value", "<group>"));
			choice0 = value_modules_rule_regular_value_one_capture;
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
					value_modules_rule_regular_value_mul_capture = required<Types::modules::rule::regular::value::mul_capture>(la0_2, [this](auto cursor) { return this->modulesRuleRegularValueMul_capture(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value", "<group>"));
					choice0 = value_modules_rule_regular_value_mul_capture;
					matched0 = true;
					break;
				}
				case Tokens::LEFT_PARENTHESIS::id: {
					la0_2 = la0_1;
					value_modules_rule_regular_value_one_capture = required<Types::modules::rule::regular::value::one_capture>(la0_2, [this](auto cursor) { return this->modulesRuleRegularValueOne_capture(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value", "<group>"));
					choice0 = value_modules_rule_regular_value_one_capture;
					matched0 = true;
					break;
				}
				case Tokens::PERCENT_SIGN::id: {
					la0_2 = la0_1;
					value_modules_rule_regular_value_one_capture = required<Types::modules::rule::regular::value::one_capture>(la0_2, [this](auto cursor) { return this->modulesRuleRegularValueOne_capture(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value", "<group>"));
					choice0 = value_modules_rule_regular_value_one_capture;
					matched0 = true;
					break;
				}
				case Tokens::modules::common::ID::id: {
					la0_2 = la0_1;
					value_modules_rule_regular_value_one_capture = required<Types::modules::rule::regular::value::one_capture>(la0_2, [this](auto cursor) { return this->modulesRuleRegularValueOne_capture(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value", "<group>"));
					choice0 = value_modules_rule_regular_value_one_capture;
					matched0 = true;
					break;
				}
				case Tokens::modules::rule::regular::value::ANY::id: {
					la0_2 = la0_1;
					value_modules_rule_regular_value_one_capture = required<Types::modules::rule::regular::value::one_capture>(la0_2, [this](auto cursor) { return this->modulesRuleRegularValueOne_capture(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value", "<group>"));
					choice0 = value_modules_rule_regular_value_one_capture;
					matched0 = true;
					break;
				}
				case Tokens::modules::rule::regular::value::CGROUP::id: {
					la0_2 = la0_1;
					value_modules_rule_regular_value_one_capture = required<Types::modules::rule::regular::value::one_capture>(la0_2, [this](auto cursor) { return this->modulesRuleRegularValueOne_capture(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value", "<group>"));
					choice0 = value_modules_rule_regular_value_one_capture;
					matched0 = true;
					break;
				}
				case Tokens::modules::rule::regular::value::NOSPACE::id: {
					la0_2 = la0_1;
					value_modules_rule_regular_value_one_capture = required<Types::modules::rule::regular::value::one_capture>(la0_2, [this](auto cursor) { return this->modulesRuleRegularValueOne_capture(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value", "<group>"));
					choice0 = value_modules_rule_regular_value_one_capture;
					matched0 = true;
					break;
				}
				case Tokens::modules::rule::regular::value::SPACE::id: {
					la0_2 = la0_1;
					value_modules_rule_regular_value_one_capture = required<Types::modules::rule::regular::value::one_capture>(la0_2, [this](auto cursor) { return this->modulesRuleRegularValueOne_capture(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value", "<group>"));
					choice0 = value_modules_rule_regular_value_one_capture;
					matched0 = true;
					break;
				}
				case Tokens::modules::rule::regular::value::STRING::id: {
					la0_2 = la0_1;
					value_modules_rule_regular_value_one_capture = required<Types::modules::rule::regular::value::one_capture>(la0_2, [this](auto cursor) { return this->modulesRuleRegularValueOne_capture(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value", "<group>"));
					choice0 = value_modules_rule_regular_value_one_capture;
					matched0 = true;
					break;
				}
				case Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id: {
					la0_2 = la0_1;
					value_modules_rule_regular_value_one_capture = required<Types::modules::rule::regular::value::one_capture>(la0_2, [this](auto cursor) { return this->modulesRuleRegularValueOne_capture(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value", "<group>"));
					choice0 = value_modules_rule_regular_value_one_capture;
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
		case Tokens::LEFT_PARENTHESIS::id: {
			value_modules_rule_regular_value_one_capture = required<Types::modules::rule::regular::value::one_capture>(la0_1, [this](auto cursor) { return this->modulesRuleRegularValueOne_capture(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value", "<group>"));
			choice0 = value_modules_rule_regular_value_one_capture;
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
					value_modules_rule_regular_value_mul_capture = required<Types::modules::rule::regular::value::mul_capture>(la0_2, [this](auto cursor) { return this->modulesRuleRegularValueMul_capture(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value", "<group>"));
					choice0 = value_modules_rule_regular_value_mul_capture;
					matched0 = true;
					break;
				}
				case Tokens::LEFT_PARENTHESIS::id: {
					la0_2 = la0_1;
					value_modules_rule_regular_value_one_capture = required<Types::modules::rule::regular::value::one_capture>(la0_2, [this](auto cursor) { return this->modulesRuleRegularValueOne_capture(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value", "<group>"));
					choice0 = value_modules_rule_regular_value_one_capture;
					matched0 = true;
					break;
				}
				case Tokens::modules::common::ID::id: {
					la0_2 = la0_1;
					value_modules_rule_regular_value_one_capture = required<Types::modules::rule::regular::value::one_capture>(la0_2, [this](auto cursor) { return this->modulesRuleRegularValueOne_capture(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value", "<group>"));
					choice0 = value_modules_rule_regular_value_one_capture;
					matched0 = true;
					break;
				}
				case Tokens::modules::rule::regular::value::ANY::id: {
					la0_2 = la0_1;
					value_modules_rule_regular_value_one_capture = required<Types::modules::rule::regular::value::one_capture>(la0_2, [this](auto cursor) { return this->modulesRuleRegularValueOne_capture(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value", "<group>"));
					choice0 = value_modules_rule_regular_value_one_capture;
					matched0 = true;
					break;
				}
				case Tokens::modules::rule::regular::value::CGROUP::id: {
					la0_2 = la0_1;
					value_modules_rule_regular_value_one_capture = required<Types::modules::rule::regular::value::one_capture>(la0_2, [this](auto cursor) { return this->modulesRuleRegularValueOne_capture(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value", "<group>"));
					choice0 = value_modules_rule_regular_value_one_capture;
					matched0 = true;
					break;
				}
				case Tokens::modules::rule::regular::value::NOSPACE::id: {
					la0_2 = la0_1;
					value_modules_rule_regular_value_one_capture = required<Types::modules::rule::regular::value::one_capture>(la0_2, [this](auto cursor) { return this->modulesRuleRegularValueOne_capture(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value", "<group>"));
					choice0 = value_modules_rule_regular_value_one_capture;
					matched0 = true;
					break;
				}
				case Tokens::modules::rule::regular::value::SPACE::id: {
					la0_2 = la0_1;
					value_modules_rule_regular_value_one_capture = required<Types::modules::rule::regular::value::one_capture>(la0_2, [this](auto cursor) { return this->modulesRuleRegularValueOne_capture(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value", "<group>"));
					choice0 = value_modules_rule_regular_value_one_capture;
					matched0 = true;
					break;
				}
				case Tokens::modules::rule::regular::value::STRING::id: {
					la0_2 = la0_1;
					value_modules_rule_regular_value_one_capture = required<Types::modules::rule::regular::value::one_capture>(la0_2, [this](auto cursor) { return this->modulesRuleRegularValueOne_capture(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value", "<group>"));
					choice0 = value_modules_rule_regular_value_one_capture;
					matched0 = true;
					break;
				}
				case Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id: {
					la0_2 = la0_1;
					value_modules_rule_regular_value_one_capture = required<Types::modules::rule::regular::value::one_capture>(la0_2, [this](auto cursor) { return this->modulesRuleRegularValueOne_capture(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value", "<group>"));
					choice0 = value_modules_rule_regular_value_one_capture;
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
		case Tokens::modules::common::ID::id: {
			value_modules_rule_regular_value_one_capture = required<Types::modules::rule::regular::value::one_capture>(la0_1, [this](auto cursor) { return this->modulesRuleRegularValueOne_capture(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value", "<group>"));
			choice0 = value_modules_rule_regular_value_one_capture;
			matched0 = true;
			break;
		}
		case Tokens::modules::rule::regular::value::ANY::id: {
			value_modules_rule_regular_value_one_capture = required<Types::modules::rule::regular::value::one_capture>(la0_1, [this](auto cursor) { return this->modulesRuleRegularValueOne_capture(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value", "<group>"));
			choice0 = value_modules_rule_regular_value_one_capture;
			matched0 = true;
			break;
		}
		case Tokens::modules::rule::regular::value::CGROUP::id: {
			value_modules_rule_regular_value_one_capture = required<Types::modules::rule::regular::value::one_capture>(la0_1, [this](auto cursor) { return this->modulesRuleRegularValueOne_capture(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value", "<group>"));
			choice0 = value_modules_rule_regular_value_one_capture;
			matched0 = true;
			break;
		}
		case Tokens::modules::rule::regular::value::NOSPACE::id: {
			value_modules_rule_regular_value_one_capture = required<Types::modules::rule::regular::value::one_capture>(la0_1, [this](auto cursor) { return this->modulesRuleRegularValueOne_capture(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value", "<group>"));
			choice0 = value_modules_rule_regular_value_one_capture;
			matched0 = true;
			break;
		}
		case Tokens::modules::rule::regular::value::SPACE::id: {
			value_modules_rule_regular_value_one_capture = required<Types::modules::rule::regular::value::one_capture>(la0_1, [this](auto cursor) { return this->modulesRuleRegularValueOne_capture(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value", "<group>"));
			choice0 = value_modules_rule_regular_value_one_capture;
			matched0 = true;
			break;
		}
		case Tokens::modules::rule::regular::value::STRING::id: {
			value_modules_rule_regular_value_one_capture = required<Types::modules::rule::regular::value::one_capture>(la0_1, [this](auto cursor) { return this->modulesRuleRegularValueOne_capture(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value", "<group>"));
			choice0 = value_modules_rule_regular_value_one_capture;
			matched0 = true;
			break;
		}
		case Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id: {
			value_modules_rule_regular_value_one_capture = required<Types::modules::rule::regular::value::one_capture>(la0_1, [this](auto cursor) { return this->modulesRuleRegularValueOne_capture(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value", "<group>"));
			choice0 = value_modules_rule_regular_value_one_capture;
			matched0 = true;
			break;
		}
	}
	pos = la0_1;
	if (!matched0) {
		raise_error(*pos, "ISPA match failure: expected one of: AMPERSAND, COMMERCIAL_AT, LEFT_PARENTHESIS, PERCENT_SIGN, modules.common.ID, modules.rule.regular.value.ANY, modules.rule.regular.value.CGROUP, modules.rule.regular.value.NOSPACE, modules.rule.regular.value.SPACE, modules.rule.regular.value.STRING, modules.rule.regular.value.dyn.DOLLAR_SIGN");
		return {};
	}
	Types::modules::rule::regular::value result;
	::ISPA_STD::assign_compatible(result.value, choice0);
	::ISPA_STD::MatchResult<Types::modules::rule::regular::value, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::modulesRuleRegularValue<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::modules::rule::regular::value, ::Parser::Lexer::iterator>;
template auto Parser::Parser::modulesRuleRegularValue<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::modules::rule::regular::value, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::modulesGrammarGrammar(IT pos) -> ::ISPA_STD::MatchResult<Types::modules::grammar::grammar, IT> {
	std::vector<::ISPA_STD::Node<Types::modules::grammar::modifier>> value_list_modules_grammar_modifier;
	::ISPA_STD::Node<Types::modules::common::name> value_modules_common_name;
	std::variant<std::monostate, ::ISPA_STD::Node<Types::modules::rule::regular::regular_rule>, ::ISPA_STD::Node<Types::modules::rule::advanced::advanced_rule>> choice0;
	bool matched0;
	::ISPA_STD::Node<Types::modules::rule::regular::regular_rule> value_modules_rule_regular_regular_rule;
	::ISPA_STD::Node<Types::modules::rule::advanced::advanced_rule> value_modules_rule_advanced_advanced_rule;
	value_list_modules_grammar_modifier = range_optional<Types::modules::grammar::modifier, Types::__WS>(pos, [this](auto cursor) { return this->modulesGrammarModifier(cursor); });
	skip_spaces<Types::__WS>(pos);
	value_modules_common_name = required<Types::modules::common::name>(pos, [this](auto cursor) { return this->modulesCommonName(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Tokens<Tokens::COLON::id, Tokens::LEFT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::fail_block::fail_block::FAIL::id, Tokens::modules::grammar::modifier::AUTO::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::grammar::grammar", "modules::common::name"));
	skip_spaces<Types::__WS>(pos);
	// grammar `@  ( modules::rule::regular::regular_rule |  modules::rule::advanced::advanced_rule)`: choice; alternative selected by LL(1) lookahead
	matched0 = false;
	auto la0_1 = pos;
	switch ((*la0_1).kind()) {
		case Tokens::COLON::id: {
			value_modules_rule_regular_regular_rule = required<Types::modules::rule::regular::regular_rule>(la0_1, [this](auto cursor) { return this->modulesRuleRegularRegular_rule(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::COLON::id, Tokens::LEFT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::fail_block::fail_block::FAIL::id, Tokens::modules::grammar::modifier::AUTO::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::fail_block::fail_block::FAIL::id, Tokens::modules::grammar::modifier::AUTO::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::grammar::grammar", "<group>"));
			choice0 = value_modules_rule_regular_regular_rule;
			matched0 = true;
			break;
		}
		case Tokens::LEFT_CURLY_BRACKET::id: {
			value_modules_rule_advanced_advanced_rule = required<Types::modules::rule::advanced::advanced_rule>(la0_1, [this](auto cursor) { return this->modulesRuleAdvancedAdvanced_rule(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::COLON::id, Tokens::LEFT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::fail_block::fail_block::FAIL::id, Tokens::modules::grammar::modifier::AUTO::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::fail_block::fail_block::FAIL::id, Tokens::modules::grammar::modifier::AUTO::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::grammar::grammar", "<group>"));
			choice0 = value_modules_rule_advanced_advanced_rule;
			matched0 = true;
			break;
		}
	}
	pos = la0_1;
	if (!matched0) {
		raise_error(*pos, "ISPA match failure: expected one of: COLON, LEFT_CURLY_BRACKET");
		return {};
	}
	Types::modules::grammar::grammar result;
	::ISPA_STD::assign_compatible(result.mod, value_list_modules_grammar_modifier);
	::ISPA_STD::assign_compatible(result.name, value_modules_common_name);
	::ISPA_STD::assign_compatible(result.entry, choice0);
	::ISPA_STD::MatchResult<Types::modules::grammar::grammar, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::modulesGrammarGrammar<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::modules::grammar::grammar, ::Parser::Lexer::iterator>;
template auto Parser::Parser::modulesGrammarGrammar<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::modules::grammar::grammar, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::modulesRuleAdvancedAdvanced_rule(IT pos) -> ::ISPA_STD::MatchResult<Types::modules::rule::advanced::advanced_rule, IT> {
	::ISPA_STD::Node<Types::LEFT_CURLY_BRACKET> value_LEFT_CURLY_BRACKET;
	std::vector<::ISPA_STD::Node<Types::modules::rule::advanced::advanced_rule::dep_decl>> value_list_modules_rule_advanced_advanced_rule_dep_decl;
	std::variant<std::monostate, ::ISPA_STD::Node<Types::modules::rule::advanced::advanced_rule::regular_match>, ::ISPA_STD::Node<Types::modules::common::stmt>> choice0;
	bool matched0;
	::ISPA_STD::Node<Types::modules::rule::advanced::advanced_rule::regular_match> value_modules_rule_advanced_advanced_rule_regular_match;
	::ISPA_STD::Node<Types::modules::common::stmt> value_modules_common_stmt;
	std::vector<std::variant<std::monostate, ::ISPA_STD::Node<Types::modules::rule::advanced::advanced_rule::regular_match>, ::ISPA_STD::Node<Types::modules::common::stmt>>> group_list1;
	::ISPA_STD::Node<Types::RIGHT_CURLY_BRACKET> value_RIGHT_CURLY_BRACKET;
	value_LEFT_CURLY_BRACKET = required<Types::LEFT_CURLY_BRACKET>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::LEFT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id, Tokens::modules::common::PY_RAW::id, Tokens::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id>, ISPA_STD::Recovery::Tokens<Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::fail_block::fail_block::FAIL::id, Tokens::modules::grammar::modifier::AUTO::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::rule::advanced::advanced_rule", "LEFT_CURLY_BRACKET"));
	skip_spaces<Types::__WS>(pos);
	value_list_modules_rule_advanced_advanced_rule_dep_decl = range_optional<Types::modules::rule::advanced::advanced_rule::dep_decl, Types::__WS>(pos, [this](auto cursor) { return this->modulesRuleAdvancedAdvanced_ruleDep_decl(cursor); });
	skip_spaces<Types::__WS>(pos);
	// grammar `@  ( ( modules::rule::advanced::advanced_rule::regular_match |  modules::common::stmt))*;`: repeat while lookahead is in FIRST
	while (((*pos).kind() == Tokens::modules::common::PY_RAW::id || (*pos).kind() == Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id)) {
		// grammar ` ( modules::rule::advanced::advanced_rule::regular_match |  modules::common::stmt)`: choice; alternative selected by LL(1) lookahead
		matched0 = false;
		auto la0_1 = pos;
		switch ((*la0_1).kind()) {
			case Tokens::modules::common::PY_RAW::id: {
				value_modules_common_stmt = required<Types::modules::common::stmt>(la0_1, [this](auto cursor) { return this->modulesCommonStmt(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::modules::common::PY_RAW::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::fail_block::fail_block::FAIL::id, Tokens::modules::grammar::modifier::AUTO::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::advanced::advanced_rule", "<group>"));
				choice0 = value_modules_common_stmt;
				matched0 = true;
				break;
			}
			case Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id: {
				value_modules_rule_advanced_advanced_rule_regular_match = required<Types::modules::rule::advanced::advanced_rule::regular_match>(la0_1, [this](auto cursor) { return this->modulesRuleAdvancedAdvanced_ruleRegular_match(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::modules::common::PY_RAW::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::fail_block::fail_block::FAIL::id, Tokens::modules::grammar::modifier::AUTO::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::advanced::advanced_rule", "<group>"));
				choice0 = value_modules_rule_advanced_advanced_rule_regular_match;
				matched0 = true;
				break;
			}
		}
		pos = la0_1;
		if (!matched0) {
			raise_error(*pos, "ISPA match failure: expected one of: modules.rule.advanced.advanced_rule.regular_match.MATCH, modules.common.PY_RAW");
			return {};
		}
		group_list1.push_back(choice0);
		skip_spaces<Types::__WS>(pos);
	}
	skip_spaces<Types::__WS>(pos);
	value_RIGHT_CURLY_BRACKET = required<Types::RIGHT_CURLY_BRACKET>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::fail_block::fail_block::FAIL::id, Tokens::modules::grammar::modifier::AUTO::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::fail_block::fail_block::FAIL::id, Tokens::modules::grammar::modifier::AUTO::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::rule::advanced::advanced_rule", "RIGHT_CURLY_BRACKET"));
	Types::modules::rule::advanced::advanced_rule result;
	::ISPA_STD::assign_compatible(result.dep, value_list_modules_rule_advanced_advanced_rule_dep_decl);
	::ISPA_STD::assign_compatible(result.body, group_list1);
	::ISPA_STD::MatchResult<Types::modules::rule::advanced::advanced_rule, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::modulesRuleAdvancedAdvanced_rule<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::modules::rule::advanced::advanced_rule, ::Parser::Lexer::iterator>;
template auto Parser::Parser::modulesRuleAdvancedAdvanced_rule<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::modules::rule::advanced::advanced_rule, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::modulesFail_blockFail_block(IT pos) -> ::ISPA_STD::MatchResult<Types::modules::fail_block::fail_block, IT> {
	::ISPA_STD::Node<Types::modules::fail_block::fail_block::FAIL> value_modules_fail_block_fail_block_FAIL;
	::ISPA_STD::Node<Types::modules::common::name> value_modules_common_name;
	::ISPA_STD::Node<Types::modules::common::stmt> value_modules_common_stmt;
	value_modules_fail_block_fail_block_FAIL = required<Types::modules::fail_block::fail_block::FAIL>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::modules::fail_block::fail_block::FAIL::id>, ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id, Tokens::modules::fail_block::fail_block::FAIL::id, Tokens::modules::grammar::modifier::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::fail_block::fail_block", "modules::fail_block::fail_block::FAIL"));
	skip_spaces<Types::__WS>(pos);
	value_modules_common_name = required<Types::modules::common::name>(pos, [this](auto cursor) { return this->modulesCommonName(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Tokens<Tokens::modules::common::PY_RAW::id>, ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id, Tokens::modules::fail_block::fail_block::FAIL::id, Tokens::modules::grammar::modifier::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::fail_block::fail_block", "modules::common::name"));
	skip_spaces<Types::__WS>(pos);
	value_modules_common_stmt = required<Types::modules::common::stmt>(pos, [this](auto cursor) { return this->modulesCommonStmt(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::modules::common::PY_RAW::id>, ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id, Tokens::modules::fail_block::fail_block::FAIL::id, Tokens::modules::grammar::modifier::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id, Tokens::modules::fail_block::fail_block::FAIL::id, Tokens::modules::grammar::modifier::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::fail_block::fail_block", "modules::common::stmt"));
	Types::modules::fail_block::fail_block result;
	::ISPA_STD::assign_compatible(result.name, value_modules_common_name);
	::ISPA_STD::assign_compatible(result.val, value_modules_common_stmt);
	::ISPA_STD::MatchResult<Types::modules::fail_block::fail_block, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::modulesFail_blockFail_block<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::modules::fail_block::fail_block, ::Parser::Lexer::iterator>;
template auto Parser::Parser::modulesFail_blockFail_block<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::modules::fail_block::fail_block, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::modulesRuleRegularValueDyn(IT pos) -> ::ISPA_STD::MatchResult<Types::modules::rule::regular::value::dyn, IT> {
	::ISPA_STD::Node<Types::modules::rule::regular::value::dyn::DOLLAR_SIGN> value_modules_rule_regular_value_dyn_DOLLAR_SIGN;
	std::variant<std::monostate, ::ISPA_STD::Node<Types::modules::rule::regular::value::dyn::dyn_expr>, ::ISPA_STD::Node<Types::modules::common::ID>> choice0;
	bool matched0;
	::ISPA_STD::Node<Types::modules::rule::regular::value::dyn::dyn_expr> value_modules_rule_regular_value_dyn_dyn_expr;
	::ISPA_STD::Node<Types::modules::common::ID> value_modules_common_ID;
	value_modules_rule_regular_value_dyn_DOLLAR_SIGN = required<Types::modules::rule::regular::value::dyn::DOLLAR_SIGN>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::LEFT_CURLY_BRACKET::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::rule::regular::value::dyn", "modules::rule::regular::value::dyn::DOLLAR_SIGN"));
	skip_spaces<Types::__WS>(pos);
	// grammar `@  ( modules::rule::regular::value::dyn::dyn_expr |  modules::common::ID)`: choice; alternative selected by LL(1) lookahead
	matched0 = false;
	auto la0_1 = pos;
	switch ((*la0_1).kind()) {
		case Tokens::LEFT_CURLY_BRACKET::id: {
			value_modules_rule_regular_value_dyn_dyn_expr = required<Types::modules::rule::regular::value::dyn::dyn_expr>(la0_1, [this](auto cursor) { return this->modulesRuleRegularValueDynDyn_expr(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::LEFT_CURLY_BRACKET::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value::dyn", "<group>"));
			choice0 = value_modules_rule_regular_value_dyn_dyn_expr;
			matched0 = true;
			break;
		}
		case Tokens::modules::common::ID::id: {
			value_modules_common_ID = required<Types::modules::common::ID>(la0_1, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::LEFT_CURLY_BRACKET::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value::dyn", "<group>"));
			choice0 = value_modules_common_ID;
			matched0 = true;
			break;
		}
	}
	pos = la0_1;
	if (!matched0) {
		raise_error(*pos, "ISPA match failure: expected one of: LEFT_CURLY_BRACKET, modules.common.ID");
		return {};
	}
	Types::modules::rule::regular::value::dyn result;
	::ISPA_STD::assign_compatible(result.value, choice0);
	::ISPA_STD::MatchResult<Types::modules::rule::regular::value::dyn, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::modulesRuleRegularValueDyn<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::modules::rule::regular::value::dyn, ::Parser::Lexer::iterator>;
template auto Parser::Parser::modulesRuleRegularValueDyn<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::modules::rule::regular::value::dyn, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::modulesGrammarModifier(IT pos) -> ::ISPA_STD::MatchResult<Types::modules::grammar::modifier, IT> {
	::ISPA_STD::Node<Types::modules::grammar::modifier::AUTO> value_modules_grammar_modifier_AUTO;
	::ISPA_STD::Node<Types::modules::grammar::modifier::MOD> value_modules_grammar_modifier_MOD;
	::ISPA_STD::Node<Types::modules::grammar::modifier::RIGHT_SQUARE_BRACKET> value_modules_grammar_modifier_RIGHT_SQUARE_BRACKET;
	value_modules_grammar_modifier_AUTO = required<Types::modules::grammar::modifier::AUTO>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::modules::grammar::modifier::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::modules::grammar::modifier::MOD::id>, ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id, Tokens::modules::grammar::modifier::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::grammar::modifier", "modules::grammar::modifier::AUTO"));
	skip_spaces<Types::__WS>(pos);
	value_modules_grammar_modifier_MOD = required<Types::modules::grammar::modifier::MOD>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::modules::grammar::modifier::MOD::id>, ISPA_STD::Recovery::Tokens<Tokens::modules::grammar::modifier::RIGHT_SQUARE_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id, Tokens::modules::grammar::modifier::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::grammar::modifier", "modules::grammar::modifier::MOD"));
	skip_spaces<Types::__WS>(pos);
	value_modules_grammar_modifier_RIGHT_SQUARE_BRACKET = required<Types::modules::grammar::modifier::RIGHT_SQUARE_BRACKET>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::modules::grammar::modifier::RIGHT_SQUARE_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id, Tokens::modules::grammar::modifier::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id, Tokens::modules::grammar::modifier::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::grammar::modifier", "modules::grammar::modifier::RIGHT_SQUARE_BRACKET"));
	Types::modules::grammar::modifier result;
	::ISPA_STD::assign_compatible(result.value, value_modules_grammar_modifier_MOD);
	::ISPA_STD::MatchResult<Types::modules::grammar::modifier, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::modulesGrammarModifier<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::modules::grammar::modifier, ::Parser::Lexer::iterator>;
template auto Parser::Parser::modulesGrammarModifier<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::modules::grammar::modifier, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::modulesCommonParam(IT pos) -> ::ISPA_STD::MatchResult<Types::modules::common::param, IT> {
	::ISPA_STD::Node<Types::modules::common::ID> value_modules_common_ID;
	::ISPA_STD::Node<Types::COMMA> value_COMMA;
	::ISPA_STD::Node<Types::modules::common::ID> value_modules_common_ID_1;
	std::pair<::ISPA_STD::Node<Types::COMMA>, ::ISPA_STD::Node<Types::modules::common::ID>> group0;
	std::vector<std::pair<::ISPA_STD::Node<Types::COMMA>, ::ISPA_STD::Node<Types::modules::common::ID>>> group_list1;
	std::vector<::ISPA_STD::Node<Types::modules::common::ID>> capture_list2;
	value_modules_common_ID = required<Types::modules::common::ID>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Tokens<Tokens::COMMA::id, Tokens::GREATER_THAN_SIGN::id, Tokens::RIGHT_PARENTHESIS::id>, ISPA_STD::Recovery::Tokens<Tokens::GREATER_THAN_SIGN::id, Tokens::RIGHT_PARENTHESIS::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::common::param", "modules::common::ID"));
	skip_spaces<Types::__WS>(pos);
	// grammar ` ( COMMA  __WS?; @  modules::common::ID)*;`: repeat while lookahead is in FIRST
	while (((*pos).kind() == Tokens::COMMA::id)) {
		value_COMMA = required<Types::COMMA>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::COMMA::id>, ISPA_STD::Recovery::Tokens<Tokens::GREATER_THAN_SIGN::id, Tokens::RIGHT_PARENTHESIS::id>, ISPA_STD::Recovery::Tokens<Tokens::GREATER_THAN_SIGN::id, Tokens::RIGHT_PARENTHESIS::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::common::param", "<group>"));
		skip_spaces<Types::__WS>(pos);
		value_modules_common_ID_1 = required<Types::modules::common::ID>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::COMMA::id>, ISPA_STD::Recovery::Tokens<Tokens::GREATER_THAN_SIGN::id, Tokens::RIGHT_PARENTHESIS::id>, ISPA_STD::Recovery::Tokens<Tokens::GREATER_THAN_SIGN::id, Tokens::RIGHT_PARENTHESIS::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::common::param", "<group>"));
		group0 = std::make_pair(value_COMMA, value_modules_common_ID_1);
		group_list1.push_back(group0);
		capture_list2.push_back(value_modules_common_ID_1);
		skip_spaces<Types::__WS>(pos);
	}
	Types::modules::common::param result;
	::ISPA_STD::assign_compatible(result.first_p, value_modules_common_ID);
	::ISPA_STD::assign_compatible(result.following_p, capture_list2);
	::ISPA_STD::MatchResult<Types::modules::common::param, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::modulesCommonParam<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::modules::common::param, ::Parser::Lexer::iterator>;
template auto Parser::Parser::modulesCommonParam<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::modules::common::param, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::modulesCommonTemplate_params(IT pos) -> ::ISPA_STD::MatchResult<Types::modules::common::template_params, IT> {
	::ISPA_STD::Node<Types::modules::common::template_params::LESS_THAN_SIGN> value_modules_common_template_params_LESS_THAN_SIGN;
	::ISPA_STD::Node<Types::modules::common::param> value_modules_common_param;
	::ISPA_STD::Node<Types::GREATER_THAN_SIGN> value_GREATER_THAN_SIGN;
	value_modules_common_template_params_LESS_THAN_SIGN = required<Types::modules::common::template_params::LESS_THAN_SIGN>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::modules::common::template_params::LESS_THAN_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::GREATER_THAN_SIGN::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COLON::id, Tokens::COMMERCIAL_AT::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::common::PY_RAW::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::common::template_params", "modules::common::template_params::LESS_THAN_SIGN"));
	skip_spaces<Types::__WS>(pos);
	value_modules_common_param = optional<Types::modules::common::param>(pos, [this](auto cursor) { return this->modulesCommonParam(cursor); });
	skip_spaces<Types::__WS>(pos);
	value_GREATER_THAN_SIGN = required<Types::GREATER_THAN_SIGN>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::GREATER_THAN_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COLON::id, Tokens::COMMERCIAL_AT::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::common::PY_RAW::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COLON::id, Tokens::COMMERCIAL_AT::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::common::PY_RAW::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::common::template_params", "GREATER_THAN_SIGN"));
	Types::modules::common::template_params result;
	::ISPA_STD::assign_compatible(result.value, value_modules_common_param);
	::ISPA_STD::MatchResult<Types::modules::common::template_params, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::modulesCommonTemplate_params<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::modules::common::template_params, ::Parser::Lexer::iterator>;
template auto Parser::Parser::modulesCommonTemplate_params<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::modules::common::template_params, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::modulesRuleRegularValueAlternative(IT pos) -> ::ISPA_STD::MatchResult<Types::modules::rule::regular::value::alternative, IT> {
	::ISPA_STD::Node<Types::modules::rule::regular::value::alternative::VERTICAL_LINE> value_modules_rule_regular_value_alternative_VERTICAL_LINE;
	::ISPA_STD::Node<Types::modules::rule::regular::value::pattern> value_modules_rule_regular_value_pattern;
	value_modules_rule_regular_value_alternative_VERTICAL_LINE = required<Types::modules::rule::regular::value::alternative::VERTICAL_LINE>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id>, ISPA_STD::Recovery::Tokens<Tokens::LEFT_PARENTHESIS::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::rule::regular::value::alternative", "modules::rule::regular::value::alternative::VERTICAL_LINE"));
	skip_spaces<Types::__WS>(pos);
	value_modules_rule_regular_value_pattern = required<Types::modules::rule::regular::value::pattern>(pos, [this](auto cursor) { return this->modulesRuleRegularValuePattern(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::LEFT_PARENTHESIS::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value::alternative", "modules::rule::regular::value::pattern"));
	Types::modules::rule::regular::value::alternative result;
	::ISPA_STD::assign_compatible(result.value, value_modules_rule_regular_value_pattern);
	::ISPA_STD::MatchResult<Types::modules::rule::regular::value::alternative, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::modulesRuleRegularValueAlternative<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::modules::rule::regular::value::alternative, ::Parser::Lexer::iterator>;
template auto Parser::Parser::modulesRuleRegularValueAlternative<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::modules::rule::regular::value::alternative, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::modulesRuleAdvancedAdvanced_ruleRegular_match(IT pos) -> ::ISPA_STD::MatchResult<Types::modules::rule::advanced::advanced_rule::regular_match, IT> {
	::ISPA_STD::Node<Types::modules::rule::advanced::advanced_rule::regular_match::MATCH> value_modules_rule_advanced_advanced_rule_regular_match_MATCH;
	std::vector<::ISPA_STD::Node<Types::modules::rule::regular::value>> value_list_modules_rule_regular_value;
	std::variant<std::monostate, ::ISPA_STD::Node<Types::modules::rule::advanced::advanced_rule::regular_match::unpack>, ::ISPA_STD::Node<Types::SEMICOLON>> choice0;
	bool matched0;
	::ISPA_STD::Node<Types::modules::rule::advanced::advanced_rule::regular_match::unpack> value_modules_rule_advanced_advanced_rule_regular_match_unpack;
	::ISPA_STD::Node<Types::SEMICOLON> value_SEMICOLON;
	value_modules_rule_advanced_advanced_rule_regular_match_MATCH = required<Types::modules::rule::advanced::advanced_rule::regular_match::MATCH>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id, Tokens::modules::common::PY_RAW::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::rule::advanced::advanced_rule::regular_match", "modules::rule::advanced::advanced_rule::regular_match::MATCH"));
	skip_spaces<Types::__WS>(pos);
	value_list_modules_rule_regular_value = range<Types::modules::rule::regular::value, Types::__WS>(pos, [this](auto cursor) { return this->modulesRuleRegularValue(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AUTO::id, Tokens::SEMICOLON::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id, Tokens::modules::common::PY_RAW::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::advanced::advanced_rule::regular_match", "modules::rule::regular::value"));
	skip_spaces<Types::__WS>(pos);
	// grammar `@  ( modules::rule::advanced::advanced_rule::regular_match::unpack |  SEMICOLON)`: choice; alternative selected by LL(1) lookahead
	matched0 = false;
	auto la0_1 = pos;
	switch ((*la0_1).kind()) {
		case Tokens::AUTO::id: {
			value_modules_rule_advanced_advanced_rule_regular_match_unpack = required<Types::modules::rule::advanced::advanced_rule::regular_match::unpack>(la0_1, [this](auto cursor) { return this->modulesRuleAdvancedAdvanced_ruleRegular_matchUnpack(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AUTO::id, Tokens::SEMICOLON::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id, Tokens::modules::common::PY_RAW::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id, Tokens::modules::common::PY_RAW::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::advanced::advanced_rule::regular_match", "<group>"));
			choice0 = value_modules_rule_advanced_advanced_rule_regular_match_unpack;
			matched0 = true;
			break;
		}
		case Tokens::SEMICOLON::id: {
			value_SEMICOLON = required<Types::SEMICOLON>(la0_1, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AUTO::id, Tokens::SEMICOLON::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id, Tokens::modules::common::PY_RAW::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id, Tokens::modules::common::PY_RAW::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::advanced::advanced_rule::regular_match", "<group>"));
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
	Types::modules::rule::advanced::advanced_rule::regular_match result;
	::ISPA_STD::assign_compatible(result.patterns, value_list_modules_rule_regular_value);
	::ISPA_STD::assign_compatible(result.assign_names, choice0);
	::ISPA_STD::MatchResult<Types::modules::rule::advanced::advanced_rule::regular_match, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::modulesRuleAdvancedAdvanced_ruleRegular_match<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::modules::rule::advanced::advanced_rule::regular_match, ::Parser::Lexer::iterator>;
template auto Parser::Parser::modulesRuleAdvancedAdvanced_ruleRegular_match<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::modules::rule::advanced::advanced_rule::regular_match, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::modulesMainMain(IT pos) -> ::ISPA_STD::MatchResult<Types::modules::main::main, IT> {
	std::variant<std::monostate, ::ISPA_STD::Node<Types::modules::grammar::grammar>, ::ISPA_STD::Node<Types::modules::fail_block::fail_block>> choice0;
	bool matched0;
	::ISPA_STD::Node<Types::modules::grammar::grammar> value_modules_grammar_grammar;
	::ISPA_STD::Node<Types::modules::fail_block::fail_block> value_modules_fail_block_fail_block;
	std::vector<std::variant<std::monostate, ::ISPA_STD::Node<Types::modules::grammar::grammar>, ::ISPA_STD::Node<Types::modules::fail_block::fail_block>>> group_list1;
	// grammar `@  ( ( modules::grammar::grammar |  modules::fail_block::fail_block))*;`: repeat while lookahead is in FIRST
	while (((*pos).kind() == Tokens::modules::common::ID::id || (*pos).kind() == Tokens::modules::fail_block::fail_block::FAIL::id || (*pos).kind() == Tokens::modules::grammar::modifier::AUTO::id)) {
		// grammar ` ( modules::grammar::grammar |  modules::fail_block::fail_block)`: choice; alternative selected by LL(1) lookahead
		matched0 = false;
		auto la0_1 = pos;
		switch ((*la0_1).kind()) {
			case Tokens::modules::common::ID::id: {
				value_modules_grammar_grammar = required<Types::modules::grammar::grammar>(la0_1, [this](auto cursor) { return this->modulesGrammarGrammar(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id, Tokens::modules::fail_block::fail_block::FAIL::id, Tokens::modules::grammar::modifier::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::main::main", "<group>"));
				choice0 = value_modules_grammar_grammar;
				matched0 = true;
				break;
			}
			case Tokens::modules::fail_block::fail_block::FAIL::id: {
				value_modules_fail_block_fail_block = required<Types::modules::fail_block::fail_block>(la0_1, [this](auto cursor) { return this->modulesFail_blockFail_block(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id, Tokens::modules::fail_block::fail_block::FAIL::id, Tokens::modules::grammar::modifier::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::main::main", "<group>"));
				choice0 = value_modules_fail_block_fail_block;
				matched0 = true;
				break;
			}
			case Tokens::modules::grammar::modifier::AUTO::id: {
				value_modules_grammar_grammar = required<Types::modules::grammar::grammar>(la0_1, [this](auto cursor) { return this->modulesGrammarGrammar(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id, Tokens::modules::fail_block::fail_block::FAIL::id, Tokens::modules::grammar::modifier::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::main::main", "<group>"));
				choice0 = value_modules_grammar_grammar;
				matched0 = true;
				break;
			}
		}
		pos = la0_1;
		if (!matched0) {
			raise_error(*pos, "ISPA match failure: expected one of: modules.common.ID, modules.grammar.modifier.AUTO, modules.fail_block.fail_block.FAIL");
			return {};
		}
		group_list1.push_back(choice0);
		skip_spaces<Types::__WS>(pos);
	}
	Types::modules::main::main result;
	::ISPA_STD::assign_compatible(result.value, group_list1);
	::ISPA_STD::MatchResult<Types::modules::main::main, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::modulesMainMain<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::modules::main::main, ::Parser::Lexer::iterator>;
template auto Parser::Parser::modulesMainMain<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::modules::main::main, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::modulesCommonName(IT pos) -> ::ISPA_STD::MatchResult<Types::modules::common::name, IT> {
	::ISPA_STD::Node<Types::modules::common::ID> value_modules_common_ID;
	::ISPA_STD::Node<Types::AUTO> value_AUTO;
	::ISPA_STD::Node<Types::modules::common::ID> value_modules_common_ID_1;
	std::pair<::ISPA_STD::Node<Types::AUTO>, ::ISPA_STD::Node<Types::modules::common::ID>> group0;
	std::vector<std::pair<::ISPA_STD::Node<Types::AUTO>, ::ISPA_STD::Node<Types::modules::common::ID>>> group_list1;
	std::vector<::ISPA_STD::Node<Types::modules::common::ID>> capture_list2;
	::ISPA_STD::Node<Types::modules::common::template_params> value_modules_common_template_params;
	::ISPA_STD::Node<Types::modules::common::params> value_modules_common_params;
	value_modules_common_ID = required<Types::modules::common::ID>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COLON::id, Tokens::COMMERCIAL_AT::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::common::PY_RAW::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COLON::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::common::PY_RAW::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::common::name", "modules::common::ID"));
	skip_spaces<Types::__WS>(pos);
	// grammar ` ( AUTO  __WS?; @  modules::common::ID)*;`: repeat while lookahead is in FIRST
	while (((*pos).kind() == Tokens::AUTO::id)) {
		value_AUTO = required<Types::AUTO>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COLON::id, Tokens::COMMERCIAL_AT::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::common::PY_RAW::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COLON::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::common::PY_RAW::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::common::name", "<group>"));
		skip_spaces<Types::__WS>(pos);
		value_modules_common_ID_1 = required<Types::modules::common::ID>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COLON::id, Tokens::COMMERCIAL_AT::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::common::PY_RAW::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COLON::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::common::PY_RAW::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::common::name", "<group>"));
		group0 = std::make_pair(value_AUTO, value_modules_common_ID_1);
		group_list1.push_back(group0);
		capture_list2.push_back(value_modules_common_ID_1);
		skip_spaces<Types::__WS>(pos);
	}
	skip_spaces<Types::__WS>(pos);
	value_modules_common_template_params = optional<Types::modules::common::template_params>(pos, [this](auto cursor) { return this->modulesCommonTemplate_params(cursor); });
	skip_spaces<Types::__WS>(pos);
	value_modules_common_params = optional<Types::modules::common::params>(pos, [this](auto cursor) { return this->modulesCommonParams(cursor); });
	Types::modules::common::name result;
	::ISPA_STD::assign_compatible(result.primary, value_modules_common_ID);
	::ISPA_STD::assign_compatible(result.nested, capture_list2);
	::ISPA_STD::assign_compatible(result.temp_params, value_modules_common_template_params);
	::ISPA_STD::assign_compatible(result.param, value_modules_common_params);
	::ISPA_STD::MatchResult<Types::modules::common::name, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::modulesCommonName<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::modules::common::name, ::Parser::Lexer::iterator>;
template auto Parser::Parser::modulesCommonName<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::modules::common::name, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::modulesRuleRegularNested_rule(IT pos) -> ::ISPA_STD::MatchResult<Types::modules::rule::regular::nested_rule, IT> {
	::ISPA_STD::Node<Types::modules::rule::regular::nested_rule::NUMBER_SIGN> value_modules_rule_regular_nested_rule_NUMBER_SIGN;
	::ISPA_STD::Node<Types::modules::grammar::grammar> value_modules_grammar_grammar;
	value_modules_rule_regular_nested_rule_NUMBER_SIGN = required<Types::modules::rule::regular::nested_rule::NUMBER_SIGN>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id, Tokens::modules::grammar::modifier::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::SEMICOLON::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::rule::regular::nested_rule", "modules::rule::regular::nested_rule::NUMBER_SIGN"));
	value_modules_grammar_grammar = required<Types::modules::grammar::grammar>(pos, [this](auto cursor) { return this->modulesGrammarGrammar(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id, Tokens::modules::grammar::modifier::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::SEMICOLON::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::SEMICOLON::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::nested_rule", "modules::grammar::grammar"));
	Types::modules::rule::regular::nested_rule result;
	::ISPA_STD::assign_compatible(result.value, value_modules_grammar_grammar);
	::ISPA_STD::MatchResult<Types::modules::rule::regular::nested_rule, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::modulesRuleRegularNested_rule<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::modules::rule::regular::nested_rule, ::Parser::Lexer::iterator>;
template auto Parser::Parser::modulesRuleRegularNested_rule<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::modules::rule::regular::nested_rule, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::modulesCommonStmt(IT pos) -> ::ISPA_STD::MatchResult<Types::modules::common::stmt, IT> {
	::ISPA_STD::Node<Types::modules::common::PY_RAW> value_modules_common_PY_RAW;
	value_modules_common_PY_RAW = required<Types::modules::common::PY_RAW>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::modules::common::PY_RAW::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id, Tokens::modules::common::ID::id, Tokens::modules::common::PY_RAW::id, Tokens::modules::fail_block::fail_block::FAIL::id, Tokens::modules::grammar::modifier::AUTO::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id, Tokens::modules::common::ID::id, Tokens::modules::common::PY_RAW::id, Tokens::modules::fail_block::fail_block::FAIL::id, Tokens::modules::grammar::modifier::AUTO::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::common::stmt", "modules::common::PY_RAW"));
	Types::modules::common::stmt result;
	::ISPA_STD::assign_compatible(result.value, value_modules_common_PY_RAW);
	::ISPA_STD::MatchResult<Types::modules::common::stmt, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::modulesCommonStmt<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::modules::common::stmt, ::Parser::Lexer::iterator>;
template auto Parser::Parser::modulesCommonStmt<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::modules::common::stmt, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::modulesRuleRegularValueMul_capture(IT pos) -> ::ISPA_STD::MatchResult<Types::modules::rule::regular::value::mul_capture, IT> {
	std::variant<std::monostate, ::ISPA_STD::Node<Types::COMMERCIAL_AT>, ::ISPA_STD::Node<Types::PERCENT_SIGN>> choice0;
	bool matched0;
	::ISPA_STD::Node<Types::COMMERCIAL_AT> value_COMMERCIAL_AT;
	::ISPA_STD::Node<Types::PERCENT_SIGN> value_PERCENT_SIGN;
	::ISPA_STD::Node<Types::EQUALS_SIGN> value_EQUALS_SIGN;
	::ISPA_STD::Node<Types::LEFT_PARENTHESIS> value_LEFT_PARENTHESIS;
	std::vector<::ISPA_STD::Node<Types::modules::rule::regular::value::one_capture>> value_list_modules_rule_regular_value_one_capture;
	::ISPA_STD::Node<Types::RIGHT_PARENTHESIS> value_RIGHT_PARENTHESIS;
	// grammar `@  ( COMMERCIAL_AT |  PERCENT_SIGN)`: choice; alternative selected by LL(1) lookahead
	matched0 = false;
	auto la0_1 = pos;
	switch ((*la0_1).kind()) {
		case Tokens::COMMERCIAL_AT::id: {
			value_COMMERCIAL_AT = required<Types::COMMERCIAL_AT>(la0_1, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::COMMERCIAL_AT::id, Tokens::PERCENT_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::EQUALS_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value::mul_capture", "<group>"));
			choice0 = value_COMMERCIAL_AT;
			matched0 = true;
			break;
		}
		case Tokens::PERCENT_SIGN::id: {
			value_PERCENT_SIGN = required<Types::PERCENT_SIGN>(la0_1, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::COMMERCIAL_AT::id, Tokens::PERCENT_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::EQUALS_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value::mul_capture", "<group>"));
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
	value_EQUALS_SIGN = required<Types::EQUALS_SIGN>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::EQUALS_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::LEFT_PARENTHESIS::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::rule::regular::value::mul_capture", "EQUALS_SIGN"));
	skip_spaces<Types::__WS>(pos);
	value_LEFT_PARENTHESIS = required<Types::LEFT_PARENTHESIS>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::LEFT_PARENTHESIS::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::rule::regular::value::mul_capture", "LEFT_PARENTHESIS"));
	skip_spaces<Types::__WS>(pos);
	value_list_modules_rule_regular_value_one_capture = range<Types::modules::rule::regular::value::one_capture, Types::__WS>(pos, [this](auto cursor) { return this->modulesRuleRegularValueOne_capture(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_PARENTHESIS::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value::mul_capture", "modules::rule::regular::value::one_capture"));
	skip_spaces<Types::__WS>(pos);
	value_RIGHT_PARENTHESIS = required<Types::RIGHT_PARENTHESIS>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::RIGHT_PARENTHESIS::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::rule::regular::value::mul_capture", "RIGHT_PARENTHESIS"));
	Types::modules::rule::regular::value::mul_capture result;
	::ISPA_STD::assign_compatible(result.type, choice0);
	::ISPA_STD::assign_compatible(result.cap, value_list_modules_rule_regular_value_one_capture);
	::ISPA_STD::MatchResult<Types::modules::rule::regular::value::mul_capture, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::modulesRuleRegularValueMul_capture<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::modules::rule::regular::value::mul_capture, ::Parser::Lexer::iterator>;
template auto Parser::Parser::modulesRuleRegularValueMul_capture<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::modules::rule::regular::value::mul_capture, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::modulesCommonExpr(IT pos) -> ::ISPA_STD::MatchResult<Types::modules::common::expr, IT> {
	::ISPA_STD::Node<Types::modules::common::PY_RAW> value_modules_common_PY_RAW;
	value_modules_common_PY_RAW = required<Types::modules::common::PY_RAW>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::modules::common::PY_RAW::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::AUTO::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::common::expr", "modules::common::PY_RAW"));
	Types::modules::common::expr result;
	::ISPA_STD::assign_compatible(result.value, value_modules_common_PY_RAW);
	::ISPA_STD::MatchResult<Types::modules::common::expr, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::modulesCommonExpr<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::modules::common::expr, ::Parser::Lexer::iterator>;
template auto Parser::Parser::modulesCommonExpr<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::modules::common::expr, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::modulesRuleRegularF_binding(IT pos) -> ::ISPA_STD::MatchResult<Types::modules::rule::regular::f_binding, IT> {
	::ISPA_STD::Node<Types::PERCENT_SIGN> value_PERCENT_SIGN;
	::ISPA_STD::Node<Types::LEFT_CURLY_BRACKET> value_LEFT_CURLY_BRACKET;
	::ISPA_STD::Node<Types::modules::common::ID> value_modules_common_ID;
	::ISPA_STD::Node<Types::COMMA> value_COMMA;
	::ISPA_STD::Node<Types::modules::common::ID> value_modules_common_ID_1;
	std::pair<::ISPA_STD::Node<Types::COMMA>, ::ISPA_STD::Node<Types::modules::common::ID>> group0;
	std::vector<std::pair<::ISPA_STD::Node<Types::COMMA>, ::ISPA_STD::Node<Types::modules::common::ID>>> group_list1;
	std::vector<::ISPA_STD::Node<Types::modules::common::ID>> capture_list2;
	::ISPA_STD::Node<Types::RIGHT_CURLY_BRACKET> value_RIGHT_CURLY_BRACKET;
	value_PERCENT_SIGN = required<Types::PERCENT_SIGN>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::PERCENT_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::LEFT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::SEMICOLON::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::rule::regular::f_binding", "PERCENT_SIGN"));
	skip_spaces<Types::__WS>(pos);
	value_LEFT_CURLY_BRACKET = required<Types::LEFT_CURLY_BRACKET>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::LEFT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Tokens<Tokens::SEMICOLON::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::rule::regular::f_binding", "LEFT_CURLY_BRACKET"));
	skip_spaces<Types::__WS>(pos);
	value_modules_common_ID = required<Types::modules::common::ID>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Tokens<Tokens::COMMA::id, Tokens::RIGHT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::SEMICOLON::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::rule::regular::f_binding", "modules::common::ID"));
	skip_spaces<Types::__WS>(pos);
	// grammar ` ( COMMA  __WS?; @  modules::common::ID)*;`: repeat while lookahead is in FIRST
	while (((*pos).kind() == Tokens::COMMA::id)) {
		value_COMMA = required<Types::COMMA>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::COMMA::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::SEMICOLON::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::f_binding", "<group>"));
		skip_spaces<Types::__WS>(pos);
		value_modules_common_ID_1 = required<Types::modules::common::ID>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::COMMA::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::SEMICOLON::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::f_binding", "<group>"));
		group0 = std::make_pair(value_COMMA, value_modules_common_ID_1);
		group_list1.push_back(group0);
		capture_list2.push_back(value_modules_common_ID_1);
		skip_spaces<Types::__WS>(pos);
	}
	skip_spaces<Types::__WS>(pos);
	value_RIGHT_CURLY_BRACKET = required<Types::RIGHT_CURLY_BRACKET>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::SEMICOLON::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::SEMICOLON::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::rule::regular::f_binding", "RIGHT_CURLY_BRACKET"));
	Types::modules::rule::regular::f_binding result;
	::ISPA_STD::assign_compatible(result.f, value_modules_common_ID);
	::ISPA_STD::assign_compatible(result.seq, capture_list2);
	::ISPA_STD::MatchResult<Types::modules::rule::regular::f_binding, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::modulesRuleRegularF_binding<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::modules::rule::regular::f_binding, ::Parser::Lexer::iterator>;
template auto Parser::Parser::modulesRuleRegularF_binding<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::modules::rule::regular::f_binding, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::modulesCommonForward_declaration(IT pos) -> ::ISPA_STD::MatchResult<Types::modules::common::forward_declaration, IT> {
	::ISPA_STD::Node<Types::modules::common::PY_RAW> value_modules_common_PY_RAW;
	value_modules_common_PY_RAW = required<Types::modules::common::PY_RAW>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::modules::common::PY_RAW::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id, Tokens::modules::common::PY_RAW::id, Tokens::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id, Tokens::modules::common::PY_RAW::id, Tokens::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::common::forward_declaration", "modules::common::PY_RAW"));
	Types::modules::common::forward_declaration result;
	::ISPA_STD::MatchResult<Types::modules::common::forward_declaration, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::modulesCommonForward_declaration<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::modules::common::forward_declaration, ::Parser::Lexer::iterator>;
template auto Parser::Parser::modulesCommonForward_declaration<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::modules::common::forward_declaration, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::modulesRuleAdvancedAdvanced_ruleDep_decl(IT pos) -> ::ISPA_STD::MatchResult<Types::modules::rule::advanced::advanced_rule::dep_decl, IT> {
	::ISPA_STD::Node<Types::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS> value_modules_rule_advanced_advanced_rule_dep_decl_DEPENDS;
	::ISPA_STD::Node<Types::modules::common::forward_declaration> value_modules_common_forward_declaration;
	value_modules_rule_advanced_advanced_rule_dep_decl_DEPENDS = required<Types::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS::id>, ISPA_STD::Recovery::Tokens<Tokens::modules::common::PY_RAW::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id, Tokens::modules::common::PY_RAW::id, Tokens::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::rule::advanced::advanced_rule::dep_decl", "modules::rule::advanced::advanced_rule::dep_decl::DEPENDS"));
	skip_spaces<Types::__WS>(pos);
	value_modules_common_forward_declaration = required<Types::modules::common::forward_declaration>(pos, [this](auto cursor) { return this->modulesCommonForward_declaration(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::modules::common::PY_RAW::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id, Tokens::modules::common::PY_RAW::id, Tokens::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id, Tokens::modules::common::PY_RAW::id, Tokens::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::advanced::advanced_rule::dep_decl", "modules::common::forward_declaration"));
	Types::modules::rule::advanced::advanced_rule::dep_decl result;
	::ISPA_STD::assign_compatible(result.value, value_modules_common_forward_declaration);
	::ISPA_STD::MatchResult<Types::modules::rule::advanced::advanced_rule::dep_decl, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::modulesRuleAdvancedAdvanced_ruleDep_decl<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::modules::rule::advanced::advanced_rule::dep_decl, ::Parser::Lexer::iterator>;
template auto Parser::Parser::modulesRuleAdvancedAdvanced_ruleDep_decl<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::modules::rule::advanced::advanced_rule::dep_decl, ::Parser::Lexer::lazy_iterator>;
auto Parser::Parser::parseFromTokens() -> void {
	tree = main(Lexer::iterator(lexer)).node.data();
}
auto Parser::Parser::lazyParse() -> void {
	Lexer lexer;
	tree = main(Lexer::lazy_iterator(lexer, text)).node.data();
}
