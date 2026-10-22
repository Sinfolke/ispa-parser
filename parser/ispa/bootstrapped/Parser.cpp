#include "Parser.h"

#include <ispastdlib.hpp>

auto Parser::TokensToString(std::size_t id) -> const char* {
	switch (id) {
		case Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id: {
			return TokensStr::modules::rule::regular::nested_rule::NUMBER_SIGN::id;
			break;
		}
		case Tokens::__WS::id: {
			return TokensStr::__WS::id;
			break;
		}
		case Tokens::modules::common::name::FULL_STOP::id: {
			return TokensStr::modules::common::name::FULL_STOP::id;
			break;
		}
		case Tokens::modules::common::template_params::LESS_THAN_SIGN::id: {
			return TokensStr::modules::common::template_params::LESS_THAN_SIGN::id;
			break;
		}
		case Tokens::modules::forward_declaration::cls::class_method::METHOD::id: {
			return TokensStr::modules::forward_declaration::cls::class_method::METHOD::id;
			break;
		}
		case Tokens::GREATER_THAN_SIGN::id: {
			return TokensStr::GREATER_THAN_SIGN::id;
			break;
		}
		case Tokens::modules::fail_block::fail_block::FAIL::id: {
			return TokensStr::modules::fail_block::fail_block::FAIL::id;
			break;
		}
		case Tokens::modules::grammar::modifier::RIGHT_SQUARE_BRACKET::id: {
			return TokensStr::modules::grammar::modifier::RIGHT_SQUARE_BRACKET::id;
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
		case Tokens::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS::id: {
			return TokensStr::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS::id;
			break;
		}
		case Tokens::modules::rule::advanced::advanced_rule::regular_match::unpack::AUTO::id: {
			return TokensStr::modules::rule::advanced::advanced_rule::regular_match::unpack::AUTO::id;
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
		case Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id: {
			return TokensStr::modules::rule::regular::value::alternative::VERTICAL_LINE::id;
			break;
		}
		case Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id: {
			return TokensStr::modules::rule::regular::value::shared_counter_registration::AUTO::id;
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
		case Tokens::modules::rule::regular::value::NOSPACE::id: {
			return TokensStr::modules::rule::regular::value::NOSPACE::id;
			break;
		}
		case Tokens::modules::rule::regular::value::SPACE::id: {
			return TokensStr::modules::rule::regular::value::SPACE::id;
			break;
		}
		case Tokens::modules::rule::regular::value::CGROUP::id: {
			return TokensStr::modules::rule::regular::value::CGROUP::id;
			break;
		}
		case Tokens::LEFT_CURLY_BRACKET::id: {
			return TokensStr::LEFT_CURLY_BRACKET::id;
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
		case Tokens::RIGHT_CURLY_BRACKET::id: {
			return TokensStr::RIGHT_CURLY_BRACKET::id;
			break;
		}
		case Tokens::modules::rule::regular::value::QUANTIFIER::id: {
			return TokensStr::modules::rule::regular::value::QUANTIFIER::id;
			break;
		}
		case Tokens::modules::common::ID::id: {
			return TokensStr::modules::common::ID::id;
			break;
		}
		case Tokens::SEMICOLON::id: {
			return TokensStr::SEMICOLON::id;
			break;
		}
		case Tokens::modules::forward_declaration::cls::class_property::PROPERTY::id: {
			return TokensStr::modules::forward_declaration::cls::class_property::PROPERTY::id;
			break;
		}
		case Tokens::modules::forward_declaration::fun::FN::id: {
			return TokensStr::modules::forward_declaration::fun::FN::id;
			break;
		}
		case Tokens::modules::forward_declaration::cls::CLASS::id: {
			return TokensStr::modules::forward_declaration::cls::CLASS::id;
			break;
		}
		case Tokens::modules::rule::regular::value::STRING::id: {
			return TokensStr::modules::rule::regular::value::STRING::id;
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
		case Tokens::__ISPA_EXTERNAL_56::id: {
			return TokensStr::__ISPA_EXTERNAL_56::id;
			break;
		}
		case Tokens::__ISPA_EXTERNAL_54::id: {
			return TokensStr::__ISPA_EXTERNAL_54::id;
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
		case Rules::modules::rule::regular::value::counter::bounded::id: {
			return RulesStr::modules::rule::regular::value::counter::bounded::id;
			break;
		}
		case Rules::modules::rule::regular::value::shared_counter_registration::id: {
			return RulesStr::modules::rule::regular::value::shared_counter_registration::id;
			break;
		}
		case Rules::modules::rule::regular::value::counter::quantified::id: {
			return RulesStr::modules::rule::regular::value::counter::quantified::id;
			break;
		}
		case Rules::modules::rule::regular::value::alternative::id: {
			return RulesStr::modules::rule::regular::value::alternative::id;
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
		case Rules::modules::rule::regular::value::mul_capture::id: {
			return RulesStr::modules::rule::regular::value::mul_capture::id;
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
		case Rules::modules::rule::regular::value::counter::id: {
			return RulesStr::modules::rule::regular::value::counter::id;
			break;
		}
		case Rules::modules::rule::regular::value::var_capture::id: {
			return RulesStr::modules::rule::regular::value::var_capture::id;
			break;
		}
		case Rules::modules::__external::python::symbol_1::id: {
			return RulesStr::modules::__external::python::symbol_1::id;
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
		case Rules::modules::rule::regular::value::dyn::id: {
			return RulesStr::modules::rule::regular::value::dyn::id;
			break;
		}
		case Rules::modules::common::param::id: {
			return RulesStr::modules::common::param::id;
			break;
		}
		case Rules::modules::grammar::modifier::id: {
			return RulesStr::modules::grammar::modifier::id;
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
		case Rules::modules::forward_declaration::fun::id: {
			return RulesStr::modules::forward_declaration::fun::id;
			break;
		}
		case Rules::modules::rule::advanced::advanced_rule::dep_decl::id: {
			return RulesStr::modules::rule::advanced::advanced_rule::dep_decl::id;
			break;
		}
		case Rules::modules::forward_declaration::fun_forward::id: {
			return RulesStr::modules::forward_declaration::fun_forward::id;
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
		case Rules::modules::forward_declaration::cls::class_property::id: {
			return RulesStr::modules::forward_declaration::cls::class_property::id;
			break;
		}
		case Rules::modules::rule::advanced::advanced_rule::regular_match::id: {
			return RulesStr::modules::rule::advanced::advanced_rule::regular_match::id;
			break;
		}
		case Rules::modules::forward_declaration::cls::class_method::id: {
			return RulesStr::modules::forward_declaration::cls::class_method::id;
			break;
		}
		case Rules::modules::forward_declaration::fwd::id: {
			return RulesStr::modules::forward_declaration::fwd::id;
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
		case Rules::modules::common::template_params::id: {
			return RulesStr::modules::common::template_params::id;
			break;
		}
		case Rules::modules::forward_declaration::cls::id: {
			return RulesStr::modules::forward_declaration::cls::id;
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
		case Rules::modules::common::expr::id: {
			return RulesStr::modules::common::expr::id;
			break;
		}
		case Rules::modules::rule::regular::f_binding::id: {
			return RulesStr::modules::rule::regular::f_binding::id;
			break;
		}
		case Rules::modules::__external::python::symbol_0::id: {
			return RulesStr::modules::__external::python::symbol_0::id;
			break;
		}
	}
	throw "Invalid Rules ID";
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
auto Parser::FlatTypes::modules_common_name_FULL_STOP::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_common_name_FULL_STOP", true);
}
auto Parser::FlatTypes::modules_common_name_FULL_STOP::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::modules_common_name_FULL_STOP::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_common_name_FULL_STOP {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, modules_common_name_FULL_STOP value) -> std::ostream & {
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
auto Parser::FlatTypes::modules_forward_declaration_cls_class_method_METHOD::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_forward_declaration_cls_class_method_METHOD", true);
}
auto Parser::FlatTypes::modules_forward_declaration_cls_class_method_METHOD::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::modules_forward_declaration_cls_class_method_METHOD::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_forward_declaration_cls_class_method_METHOD {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, modules_forward_declaration_cls_class_method_METHOD value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::modules_forward_declaration::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_forward_declaration", true);
}
auto Parser::FlatTypes::modules_forward_declaration::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::modules_forward_declaration::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_forward_declaration {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, modules_forward_declaration value) -> std::ostream & {
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
auto Parser::FlatTypes::modules_rule_advanced_advanced_rule_regular_match_unpack_AUTO::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_rule_advanced_advanced_rule_regular_match_unpack_AUTO", true);
}
auto Parser::FlatTypes::modules_rule_advanced_advanced_rule_regular_match_unpack_AUTO::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::modules_rule_advanced_advanced_rule_regular_match_unpack_AUTO::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_rule_advanced_advanced_rule_regular_match_unpack_AUTO {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, modules_rule_advanced_advanced_rule_regular_match_unpack_AUTO value) -> std::ostream & {
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
auto Parser::FlatTypes::modules_forward_declaration_cls_class_property_PROPERTY::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_forward_declaration_cls_class_property_PROPERTY", true);
}
auto Parser::FlatTypes::modules_forward_declaration_cls_class_property_PROPERTY::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::modules_forward_declaration_cls_class_property_PROPERTY::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_forward_declaration_cls_class_property_PROPERTY {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, modules_forward_declaration_cls_class_property_PROPERTY value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::modules_forward_declaration_fun_FN::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_forward_declaration_fun_FN", true);
}
auto Parser::FlatTypes::modules_forward_declaration_fun_FN::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::modules_forward_declaration_fun_FN::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_forward_declaration_fun_FN {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, modules_forward_declaration_fun_FN value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::modules_forward_declaration_cls_CLASS::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_forward_declaration_cls_CLASS", true);
}
auto Parser::FlatTypes::modules_forward_declaration_cls_CLASS::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::modules_forward_declaration_cls_CLASS::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_forward_declaration_cls_CLASS {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, modules_forward_declaration_cls_CLASS value) -> std::ostream & {
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
auto Parser::FlatTypes::modules___external::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules___external", true);
}
auto Parser::FlatTypes::modules___external::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::modules___external::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules___external {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, modules___external value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::modules___external_python::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules___external_python", true);
}
auto Parser::FlatTypes::modules___external_python::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::modules___external_python::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules___external_python {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, modules___external_python value) -> std::ostream & {
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
auto Parser::FlatTypes::modules_forward_declaration_cls_class_property::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_forward_declaration_cls_class_property", false);
	printer.up(false);
	printer.node("name", false);
	printer.up(true);
	name.print(printer);
	printer.down();
	printer.node("type", true);
	printer.up(false);
	type.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::modules_forward_declaration_cls_class_property::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::modules_forward_declaration_cls_class_property::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_forward_declaration_cls_class_property {", "name = ", name.to_string(), ", ", "type = ", type.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, modules_forward_declaration_cls_class_property value) -> std::ostream & {
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
auto Parser::FlatTypes::modules_forward_declaration_fun_forward::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_forward_declaration_fun_forward", false);
	printer.up(false);
	printer.node("name", false);
	printer.up(true);
	name.print(printer);
	printer.down();
	printer.subtree("param_names", param_names, false);
	printer.subtree("param_types", param_types, true);
	printer.down();
}
auto Parser::FlatTypes::modules_forward_declaration_fun_forward::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::modules_forward_declaration_fun_forward::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_forward_declaration_fun_forward {", "name = ", name.to_string(), ", ", "param_names = ", param_names, ", ", "param_types = ", param_types, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, modules_forward_declaration_fun_forward value) -> std::ostream & {
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
auto Parser::FlatTypes::modules_rule_advanced_advanced_rule_regular_match::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_rule_advanced_advanced_rule_regular_match", false);
	printer.up(false);
	printer.subtree("patterns", patterns, false);
	printer.node("assign_names", true);
	printer.up(false);
	assign_names.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::modules_rule_advanced_advanced_rule_regular_match::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::modules_rule_advanced_advanced_rule_regular_match::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_rule_advanced_advanced_rule_regular_match {", "patterns = ", patterns, ", ", "assign_names = ", assign_names.to_string(), "}");
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
auto Parser::FlatTypes::modules_forward_declaration_cls_class_method::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_forward_declaration_cls_class_method", false);
	printer.up(false);
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::modules_forward_declaration_cls_class_method::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::modules_forward_declaration_cls_class_method::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_forward_declaration_cls_class_method {", "value = ", value.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, modules_forward_declaration_cls_class_method value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::modules_forward_declaration_fun::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_forward_declaration_fun", false);
	printer.up(false);
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::modules_forward_declaration_fun::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::modules_forward_declaration_fun::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_forward_declaration_fun {", "value = ", value.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, modules_forward_declaration_fun value) -> std::ostream & {
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
auto Parser::FlatTypes::modules_forward_declaration_cls::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_forward_declaration_cls", false);
	printer.up(false);
	printer.node("name", false);
	printer.up(true);
	name.print(printer);
	printer.down();
	printer.node_with_value("decls", decls, true);
	printer.down();
}
auto Parser::FlatTypes::modules_forward_declaration_cls::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::modules_forward_declaration_cls::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_forward_declaration_cls {", "name = ", name.to_string(), ", ", "decls = ", decls, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, modules_forward_declaration_cls value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::modules_rule_regular_value_counter_quantified::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_rule_regular_value_counter_quantified", false);
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
auto Parser::FlatTypes::modules_rule_regular_value_counter_quantified::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::modules_rule_regular_value_counter_quantified::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_rule_regular_value_counter_quantified {", "quantifier = ", quantifier.to_string(), ", ", "repetitions = ", repetitions.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, modules_rule_regular_value_counter_quantified value) -> std::ostream & {
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
auto Parser::FlatTypes::modules_forward_declaration_fwd::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_forward_declaration_fwd", false);
	printer.up(false);
	printer.node_with_value("value", value, true);
	printer.down();
}
auto Parser::FlatTypes::modules_forward_declaration_fwd::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::modules_forward_declaration_fwd::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_forward_declaration_fwd {", "value = ", value, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, modules_forward_declaration_fwd value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::modules_rule_regular_value_counter::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_rule_regular_value_counter", false);
	printer.up(false);
	printer.node_with_value("value", value, true);
	printer.down();
}
auto Parser::FlatTypes::modules_rule_regular_value_counter::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::modules_rule_regular_value_counter::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_rule_regular_value_counter {", "value = ", value, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, modules_rule_regular_value_counter value) -> std::ostream & {
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
auto Parser::Lexer::clone() const -> std::shared_ptr<::ISPA_STD::Lexer_base<Token>> {
	return std::make_shared<Lexer>(*this);
}
auto Parser::Lexer::hasExternalRules() const -> bool {
	return true;
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
			if (captures.is_set(9)) {
				value = captures.character(9);
			} else {
				if (captures.is_set(8)) {
					value = captures.character(8);
				} else {
					if (captures.is_set(10)) {
						value = captures.character(10);
					}
				}
			}
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::modules::rule::regular::value::QUANTIFIER::id, Types::modules::rule::regular::value::QUANTIFIER{value}));
			break;
		}
		case 8: {
			char value;
			if (captures.is_set(9)) {
				value = captures.character(9);
			} else {
				if (captures.is_set(8)) {
					value = captures.character(8);
				} else {
					if (captures.is_set(10)) {
						value = captures.character(10);
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
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::modules::common::name::FULL_STOP::id, Types::modules::common::name::FULL_STOP{}));
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
			if (captures.is_set(9)) {
				value = captures.character(9);
			} else {
				if (captures.is_set(8)) {
					value = captures.character(8);
				} else {
					if (captures.is_set(10)) {
						value = captures.character(10);
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
			std::string value = captures.text(3);
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
			std::string value = captures.text(0);
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::modules::rule::regular::value::STRING::id, Types::modules::rule::regular::value::STRING{value}));
			break;
		}
		case 25: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::modules::grammar::modifier::AUTO::id, Types::modules::grammar::modifier::AUTO{}));
			break;
		}
		case 26: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::modules::rule::advanced::advanced_rule::regular_match::unpack::AUTO::id, Types::modules::rule::advanced::advanced_rule::regular_match::unpack::AUTO{}));
			break;
		}
		case 27: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id, Types::modules::rule::regular::value::shared_counter_registration::AUTO{}));
			break;
		}
		case 28: {
			std::string value = captures.text(3);
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::modules::common::ID::id, Types::modules::common::ID{value}));
			break;
		}
		case 29: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::modules::rule::regular::value::SPACE::id, Types::modules::rule::regular::value::SPACE{}));
			break;
		}
		case 30: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::modules::forward_declaration::fun::FN::id, Types::modules::forward_declaration::fun::FN{}));
			break;
		}
		case 31: {
			std::string floating = captures.text(2);
			std::string full = captures.text(1);
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::modules::common::NUMBER::id, Types::modules::common::NUMBER{full, floating}));
			break;
		}
		case 32: {
			std::string v = captures.text(12);
			char negative = captures.character(11);
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::modules::rule::regular::value::CGROUP::id, Types::modules::rule::regular::value::CGROUP{negative, v}));
			break;
		}
		case 33: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::modules::rule::regular::value::NOSPACE::id, Types::modules::rule::regular::value::NOSPACE{}));
			break;
		}
		case 34: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::modules::fail_block::fail_block::FAIL::id, Types::modules::fail_block::fail_block::FAIL{}));
			break;
		}
		case 35: {
			std::string value;
			if (captures.is_set(5)) {
				value = captures.text(5);
			} else {
				if (captures.is_set(4)) {
					value = captures.text(4);
				} else {
					if (captures.is_set(7)) {
						value = captures.text(7);
					} else {
						if (captures.is_set(6)) {
							value = captures.text(6);
						}
					}
				}
			}
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::modules::grammar::modifier::MOD::id, Types::modules::grammar::modifier::MOD{value}));
			break;
		}
		case 36: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::modules::forward_declaration::cls::CLASS::id, Types::modules::forward_declaration::cls::CLASS{}));
			break;
		}
		case 37: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id, Types::modules::rule::advanced::advanced_rule::regular_match::MATCH{}));
			break;
		}
		case 38: {
			std::string value;
			if (captures.is_set(5)) {
				value = captures.text(5);
			} else {
				if (captures.is_set(4)) {
					value = captures.text(4);
				} else {
					if (captures.is_set(7)) {
						value = captures.text(7);
					} else {
						if (captures.is_set(6)) {
							value = captures.text(6);
						}
					}
				}
			}
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::modules::grammar::modifier::MOD::id, Types::modules::grammar::modifier::MOD{value}));
			break;
		}
		case 39: {
			std::string value;
			if (captures.is_set(5)) {
				value = captures.text(5);
			} else {
				if (captures.is_set(4)) {
					value = captures.text(4);
				} else {
					if (captures.is_set(7)) {
						value = captures.text(7);
					} else {
						if (captures.is_set(6)) {
							value = captures.text(6);
						}
					}
				}
			}
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::modules::grammar::modifier::MOD::id, Types::modules::grammar::modifier::MOD{value}));
			break;
		}
		case 40: {
			std::string value;
			if (captures.is_set(5)) {
				value = captures.text(5);
			} else {
				if (captures.is_set(4)) {
					value = captures.text(4);
				} else {
					if (captures.is_set(7)) {
						value = captures.text(7);
					} else {
						if (captures.is_set(6)) {
							value = captures.text(6);
						}
					}
				}
			}
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::modules::grammar::modifier::MOD::id, Types::modules::grammar::modifier::MOD{value}));
			break;
		}
		case 41: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::modules::forward_declaration::cls::class_method::METHOD::id, Types::modules::forward_declaration::cls::class_method::METHOD{}));
			break;
		}
		case 42: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS::id, Types::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS{}));
			break;
		}
		case 43: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::modules::forward_declaration::cls::class_property::PROPERTY::id, Types::modules::forward_declaration::cls::class_property::PROPERTY{}));
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
::ISPA_STD::DFA::API::CharToClass Parser::Lexer::char_class_table = {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 0, 15, 16, 16, 16, 16, 16, 16, 16, 16, 16, 17, 18, 19, 20, 21, 22, 23, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 25, 26, 27, 28, 24, 0, 29, 30, 31, 32, 33, 34, 35, 36, 37, 24, 38, 39, 40, 41, 42, 43, 24, 44, 45, 46, 24, 24, 24, 47, 48, 24, 49, 50, 51, 0, 0, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52};
::ISPA_STD::DFA::API::Table<106, 53> Parser::Lexer::dfa_table = {{{::ISPA_STD::DFA::API::null_state, 1, 2, 3, 4, 5, 6, 2, 7, 8, 117, 116, 11, 12, 13, 115, 115, 15, 16, 17, 18, 19, 118, 21, 106, 23, 24, 25, ::ISPA_STD::DFA::API::null_state, 106, 106, 110, 109, 108, 107, 114, 106, 113, 106, 106, 119, 106, 106, 112, 106, 111, 106, 106, 106, 35, 36, 37, ::ISPA_STD::DFA::API::null_state}, {250, 1, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250}, {120, 120, 122, 120, 120, 120, 120, 40, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 121, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, ::ISPA_STD::DFA::API::null_state}, {251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 42, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251}, {252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252}, {253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253}, {254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254}, {255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255}, {256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256}, {123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123}, {124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124}, {259, 259, 259, 259, 259, 259, 259, 259, 259, 259, 259, 259, 259, 259, 259, 259, 259, 259, 259, 259, 259, 259, 259, 259, 259, 259, 259, 259, 259, 259, 259, 259, 259, 259, 259, 259, 259, 259, 259, 259, 259, 259, 259, 259, 259, 259, 259, 259, 259, 259, 259, 259, 259}, {::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, 43, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state}, {260, 260, 260, 260, 260, 260, 260, 260, 260, 260, 260, 260, 260, 260, 260, 260, 260, 260, 260, 260, 260, 260, 260, 260, 260, 260, 260, 260, 260, 260, 260, 260, 260, 260, 260, 260, 260, 260, 260, 260, 260, 260, 260, 260, 260, 260, 260, 260, 260, 260, 260, 260, 260}, {125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 126, 14, 14, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125}, {262, 262, 262, 262, 262, 262, 262, 262, 262, 262, 262, 262, 262, 262, 262, 262, 262, 262, 262, 262, 262, 262, 262, 262, 262, 262, 262, 262, 262, 262, 262, 262, 262, 262, 262, 262, 262, 262, 262, 262, 262, 262, 262, 262, 262, 262, 262, 262, 262, 262, 262, 262, 262}, {263, 263, 263, 263, 263, 263, 263, 263, 263, 263, 263, 263, 263, 263, 263, 263, 263, 263, 263, 263, 263, 263, 263, 263, 263, 263, 263, 263, 263, 263, 263, 263, 263, 263, 263, 263, 263, 263, 263, 263, 263, 263, 263, 263, 263, 263, 263, 263, 263, 263, 263, 263, 263}, {264, 264, 264, 264, 264, 264, 264, 264, 264, 264, 264, 264, 264, 264, 264, 264, 264, 264, 264, 264, 264, 264, 264, 264, 264, 264, 264, 264, 264, 264, 264, 264, 264, 264, 264, 264, 264, 264, 264, 264, 264, 264, 264, 264, 264, 264, 264, 264, 264, 264, 264, 264, 264}, {265, 265, 265, 265, 265, 265, 265, 265, 265, 265, 265, 265, 265, 265, 265, 265, 265, 265, 265, 265, 265, 45, 265, 265, 265, 265, 265, 265, 265, 265, 265, 265, 265, 265, 265, 265, 265, 265, 265, 265, 265, 265, 265, 265, 265, 265, 265, 265, 265, 265, 265, 265, 265}, {266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266}, {127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127}, {268, 268, 268, 268, 268, 268, 268, 268, 268, 268, 268, 268, 268, 268, 268, 268, 268, 268, 268, 268, 268, 268, 268, 268, 268, 268, 268, 268, 268, 268, 268, 268, 268, 268, 268, 268, 268, 268, 268, 268, 268, 268, 268, 268, 268, 268, 268, 268, 268, 268, 268, 268, 268}, {128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 46, 46, 128, 128, 128, 128, 128, 128, 128, 46, 128, 128, 128, 128, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 128, 128, 128, 128}, {129, 129, 129, 129, 129, 129, 129, 129, 129, 129, 129, 129, 129, 129, 129, 129, 129, 129, 129, 129, 129, 129, 129, 129, 129, 129, 131, ::ISPA_STD::DFA::API::null_state, 130, 129, 129, 129, 129, 129, 129, 129, 129, 129, 129, 129, 129, 129, 129, 129, 129, 129, 129, 129, 129, 129, 129, 129, ::ISPA_STD::DFA::API::null_state}, {::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, 50, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state}, {270, 270, 270, 270, 270, 270, 270, 270, 270, 270, 270, 270, 270, 270, 270, 270, 270, 270, 270, 270, 270, 270, 270, 270, 270, 270, 270, 270, 270, 270, 270, 270, 270, 270, 270, 270, 270, 270, 270, 270, 270, 270, 270, 270, 270, 270, 270, 270, 270, 270, 270, 270, 270}, {133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 134, 134, 133, 133, 133, 133, 133, 133, 133, 134, 133, 133, 133, 133, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 51, 134, 134, 134, 134, 134, 134, 134, 134, 134, 133, 133, 133, 133}, {136, 136, 136, 136, 136, 136, 136, 136, 136, 136, 136, 136, 136, 136, 136, 134, 134, 136, 136, 136, 136, 136, 136, 136, 134, 136, 136, 136, 136, 134, 134, 134, 134, 52, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 136, 136, 136, 136}, {138, 138, 138, 138, 138, 138, 138, 138, 138, 138, 138, 138, 138, 138, 138, 134, 134, 138, 138, 138, 138, 138, 138, 138, 134, 138, 138, 138, 138, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 53, 134, 138, 138, 138, 138}, {140, 140, 140, 140, 140, 140, 140, 140, 140, 140, 140, 140, 140, 140, 140, 134, 134, 140, 140, 140, 140, 140, 140, 140, 134, 140, 140, 140, 140, 54, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 55, 134, 134, 134, 134, 134, 134, 134, 140, 140, 140, 140}, {142, 142, 142, 142, 142, 142, 142, 142, 142, 142, 142, 142, 142, 142, 142, 134, 134, 142, 142, 142, 142, 142, 142, 142, 134, 142, 142, 142, 142, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 56, 134, 134, 134, 134, 134, 134, 134, 134, 134, 142, 142, 142, 142}, {144, 144, 144, 144, 144, 144, 144, 144, 144, 144, 144, 144, 144, 144, 144, 134, 134, 144, 144, 144, 144, 144, 144, 144, 134, 144, 144, 144, 144, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 57, 134, 134, 134, 134, 134, 134, 134, 144, 144, 144, 144}, {146, 146, 146, 146, 146, 146, 146, 146, 146, 146, 146, 146, 146, 146, 146, 134, 134, 146, 146, 146, 146, 146, 146, 146, 134, 146, 146, 146, 146, 58, 134, 134, 134, 59, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 146, 146, 146, 146}, {148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 134, 134, 148, 148, 148, 148, 148, 148, 148, 134, 148, 148, 148, 148, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 60, 134, 134, 134, 134, 148, 148, 148, 148}, {150, 150, 150, 150, 150, 150, 150, 150, 150, 150, 150, 150, 150, 150, 150, 134, 134, 150, 150, 150, 150, 150, 150, 150, 134, 150, 150, 150, 150, 134, 134, 134, 134, 134, 134, 134, 134, 134, 61, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 150, 150, 150, 150}, {271, 271, 271, 271, 271, 271, 271, 271, 271, 271, 271, 271, 271, 271, 271, 271, 271, 271, 271, 271, 271, 271, 271, 271, 271, 271, 271, 271, 271, 271, 271, 271, 271, 271, 271, 271, 271, 271, 271, 271, 271, 271, 271, 271, 271, 271, 271, 271, 271, 271, 271, 271, 271}, {272, 272, 272, 272, 272, 272, 272, 272, 272, 272, 272, 272, 272, 272, 272, 272, 272, 272, 272, 272, 272, 272, 272, 272, 272, 272, 272, 272, 272, 272, 272, 272, 272, 272, 272, 272, 272, 272, 272, 272, 272, 272, 272, 272, 272, 272, 272, 272, 272, 272, 272, 272, 272}, {273, 273, 273, 273, 273, 273, 273, 273, 273, 273, 273, 273, 273, 273, 273, 273, 273, 273, 273, 273, 273, 273, 273, 273, 273, 273, 273, 273, 273, 273, 273, 273, 273, 273, 273, 273, 273, 273, 273, 273, 273, 273, 273, 273, 273, 273, 273, 273, 273, 273, 273, 273, 273}, {38, 38, 152, 38, 38, 38, 38, 151, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 41, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, ::ISPA_STD::DFA::API::null_state}, {153, 153, 158, 153, 153, 153, 153, 156, 153, 153, 153, 153, 153, 153, 153, 153, 153, 153, 153, 153, 153, 153, 153, 153, 153, 153, 154, 153, 153, 153, 153, 153, 153, 153, 153, 153, 153, 153, 153, 153, 153, 153, 153, 153, 153, 153, 153, 153, 153, 153, 153, 153, 274}, {274, 274, 274, 274, 274, 274, 274, 274, 274, 274, 274, 274, 274, 274, 274, 274, 274, 274, 274, 274, 274, 274, 274, 274, 274, 274, 274, 274, 274, 274, 274, 274, 274, 274, 274, 274, 274, 274, 274, 274, 274, 274, 274, 274, 274, 274, 274, 274, 274, 274, 274, 274, 274}, {::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, 38, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state}, {275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275}, {276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276}, {::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, 159, 159, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state}, {277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277}, {160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 46, 46, 160, 160, 160, 160, 160, 160, 160, 46, 160, 160, 160, 160, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 160, 160, 160, 160}, {47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 48, 161, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, ::ISPA_STD::DFA::API::null_state}, {::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, 47, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state}, {162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 163, 161, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, ::ISPA_STD::DFA::API::null_state}, {279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 67, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279}, {165, 165, 165, 165, 165, 165, 165, 165, 165, 165, 165, 165, 165, 165, 165, 134, 134, 165, 165, 165, 165, 165, 165, 165, 134, 165, 165, 165, 165, 68, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 165, 165, 165, 165}, {167, 167, 167, 167, 167, 167, 167, 167, 167, 167, 167, 167, 167, 167, 167, 134, 134, 167, 167, 167, 167, 167, 167, 167, 134, 167, 167, 167, 167, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 69, 134, 134, 134, 134, 134, 167, 167, 167, 167}, {169, 169, 169, 169, 169, 169, 169, 169, 169, 169, 169, 169, 169, 169, 169, 134, 134, 169, 169, 169, 169, 169, 169, 169, 134, 169, 169, 169, 169, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 70, 134, 134, 169, 169, 169, 169}, {171, 171, 171, 171, 171, 171, 171, 171, 171, 171, 171, 171, 171, 171, 171, 134, 134, 171, 171, 171, 171, 171, 171, 171, 134, 171, 171, 171, 171, 134, 134, 134, 134, 134, 134, 134, 134, 71, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 171, 171, 171, 171}, {280, 280, 280, 280, 280, 280, 280, 280, 280, 280, 280, 280, 280, 280, 280, 134, 134, 280, 280, 280, 280, 280, 280, 280, 134, 280, 280, 280, 280, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 280, 280, 280, 280}, {173, 173, 173, 173, 173, 173, 173, 173, 173, 173, 173, 173, 173, 173, 173, 134, 134, 173, 173, 173, 173, 173, 173, 173, 134, 173, 173, 173, 173, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 72, 134, 134, 134, 134, 134, 134, 173, 173, 173, 173}, {175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 134, 134, 175, 175, 175, 175, 175, 175, 175, 134, 175, 175, 175, 175, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 73, 134, 134, 134, 134, 134, 134, 134, 134, 134, 175, 175, 175, 175}, {177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 134, 134, 177, 177, 177, 177, 177, 177, 177, 134, 177, 177, 177, 177, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 74, 134, 134, 177, 177, 177, 177}, {179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 134, 134, 179, 179, 179, 179, 179, 179, 179, 134, 179, 179, 179, 179, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 75, 134, 134, 179, 179, 179, 179}, {181, 181, 181, 181, 181, 181, 181, 181, 181, 181, 181, 181, 181, 181, 181, 134, 134, 181, 181, 181, 181, 181, 181, 181, 134, 181, 181, 181, 181, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 76, 134, 134, 134, 134, 134, 134, 181, 181, 181, 181}, {183, 183, 183, 183, 183, 183, 183, 183, 183, 183, 183, 183, 183, 183, 183, 134, 134, 183, 183, 183, 183, 183, 183, 183, 134, 183, 183, 183, 183, 134, 134, 134, 134, 134, 134, 134, 134, 77, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 183, 183, 183, 183}, {38, 38, 152, 38, 38, 38, 38, 151, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 41, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 274}, {184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 63, 63, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184}, {282, 282, 282, 282, 282, 282, 282, 282, 282, 282, 282, 282, 282, 282, 282, 282, 282, 282, 282, 282, 282, 282, 282, 282, 282, 282, 282, 282, 282, 282, 282, 282, 282, 282, 282, 282, 282, 282, 282, 282, 282, 282, 282, 282, 282, 282, 282, 282, 282, 282, 282, 282, 282}, {65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 66, 185, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, ::ISPA_STD::DFA::API::null_state}, {::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, 65, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state}, {283, 283, 283, 283, 283, 283, 283, 283, 283, 283, 283, 283, 283, 283, 283, 283, 283, 283, 283, 283, 283, 283, 283, 283, 283, 283, 283, 283, 283, 283, 283, 283, 283, 283, 283, 283, 283, 283, 283, 283, 283, 283, 283, 283, 283, 283, 283, 283, 283, 283, 283, 283, 283}, {187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 134, 134, 187, 187, 187, 187, 187, 187, 187, 134, 187, 187, 187, 187, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 79, 134, 134, 134, 187, 187, 187, 187}, {189, 189, 189, 189, 189, 189, 189, 189, 189, 189, 189, 189, 189, 189, 189, 134, 134, 189, 189, 189, 189, 189, 189, 189, 134, 189, 189, 189, 189, 134, 134, 134, 134, 80, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 189, 189, 189, 189}, {191, 191, 191, 191, 191, 191, 191, 191, 191, 191, 191, 191, 191, 191, 191, 134, 134, 191, 191, 191, 191, 191, 191, 191, 134, 191, 191, 191, 191, 134, 134, 134, 134, 81, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 191, 191, 191, 191}, {193, 193, 193, 193, 193, 193, 193, 193, 193, 193, 193, 193, 193, 193, 193, 134, 134, 193, 193, 193, 193, 193, 193, 193, 134, 193, 193, 193, 193, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 82, 134, 134, 134, 134, 134, 134, 134, 134, 134, 193, 193, 193, 193}, {195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 134, 134, 195, 195, 195, 195, 195, 195, 195, 134, 195, 195, 195, 195, 134, 83, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 195, 195, 195, 195}, {197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 134, 134, 197, 197, 197, 197, 197, 197, 197, 134, 197, 197, 197, 197, 134, 134, 134, 134, 134, 134, 134, 134, 84, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 197, 197, 197, 197}, {199, 199, 199, 199, 199, 199, 199, 199, 199, 199, 199, 199, 199, 199, 199, 134, 134, 199, 199, 199, 199, 199, 199, 199, 134, 199, 199, 199, 199, 134, 134, 85, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 199, 199, 199, 199}, {201, 201, 201, 201, 201, 201, 201, 201, 201, 201, 201, 201, 201, 201, 201, 134, 134, 201, 201, 201, 201, 201, 201, 201, 134, 201, 201, 201, 201, 134, 134, 134, 134, 134, 134, 134, 86, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 201, 201, 201, 201}, {203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 134, 134, 203, 203, 203, 203, 203, 203, 203, 134, 203, 203, 203, 203, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 87, 134, 134, 134, 134, 134, 203, 203, 203, 203}, {205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 134, 134, 205, 205, 205, 205, 205, 205, 205, 134, 205, 205, 205, 205, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 88, 134, 134, 134, 134, 134, 205, 205, 205, 205}, {207, 207, 207, 207, 207, 207, 207, 207, 207, 207, 207, 207, 207, 207, 207, 207, 207, 207, 207, 207, 207, 207, 207, 207, 207, 207, 207, 207, 207, 207, 207, 207, 207, 207, 207, 207, 207, 207, 207, 207, 207, 207, 207, 207, 207, 207, 207, 207, 207, 207, 207, 207, 207}, {209, 209, 209, 209, 209, 209, 209, 209, 209, 209, 209, 209, 209, 209, 209, 134, 134, 209, 209, 209, 209, 209, 209, 209, 134, 209, 209, 209, 209, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 89, 134, 134, 134, 209, 209, 209, 209}, {211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 134, 134, 211, 211, 211, 211, 211, 211, 211, 134, 211, 211, 211, 211, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 90, 134, 134, 134, 134, 134, 134, 134, 211, 211, 211, 211}, {213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 134, 134, 213, 213, 213, 213, 213, 213, 213, 134, 213, 213, 213, 213, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 91, 134, 134, 134, 134, 213, 213, 213, 213}, {284, 284, 284, 284, 284, 284, 284, 284, 284, 284, 284, 284, 284, 284, 284, 134, 134, 284, 284, 284, 284, 284, 284, 284, 134, 284, 284, 284, 284, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 284, 284, 284, 284}, {215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 134, 134, 215, 215, 215, 215, 215, 215, 215, 134, 215, 215, 215, 215, 92, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 215, 215, 215, 215}, {217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 134, 134, 217, 217, 217, 217, 217, 217, 217, 134, 217, 217, 217, 217, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 93, 134, 134, 134, 134, 134, 134, 134, 217, 217, 217, 217}, {219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 134, 134, 219, 219, 219, 219, 219, 219, 219, 134, 219, 219, 219, 219, 134, 134, 134, 134, 134, 134, 134, 94, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 219, 219, 219, 219}, {221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 134, 134, 221, 221, 221, 221, 221, 221, 221, 134, 221, 221, 221, 221, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 95, 134, 134, 134, 134, 134, 134, 221, 221, 221, 221}, {223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 134, 134, 223, 223, 223, 223, 223, 223, 223, 134, 223, 223, 223, 223, 134, 134, 134, 134, 96, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 223, 223, 223, 223}, {225, 225, 225, 225, 225, 225, 225, 225, 225, 225, 225, 225, 225, 225, 225, 134, 134, 225, 225, 225, 225, 225, 225, 225, 134, 225, 225, 225, 225, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 225, 225, 225, 225}, {286, 286, 286, 286, 286, 286, 286, 286, 286, 286, 286, 286, 286, 286, 286, 134, 134, 286, 286, 286, 286, 286, 286, 286, 134, 286, 286, 286, 286, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 286, 286, 286, 286}, {227, 227, 227, 227, 227, 227, 227, 227, 227, 227, 227, 227, 227, 227, 227, 134, 134, 227, 227, 227, 227, 227, 227, 227, 134, 227, 227, 227, 227, 134, 134, 134, 97, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 227, 227, 227, 227}, {229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 134, 134, 229, 229, 229, 229, 229, 229, 229, 134, 229, 229, 229, 229, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 98, 134, 134, 134, 134, 134, 134, 134, 229, 229, 229, 229}, {231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 134, 134, 231, 231, 231, 231, 231, 231, 231, 134, 231, 231, 231, 231, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 99, 134, 134, 134, 134, 134, 134, 134, 134, 134, 231, 231, 231, 231}, {233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 134, 134, 233, 233, 233, 233, 233, 233, 233, 134, 233, 233, 233, 233, 134, 134, 134, 134, 100, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 233, 233, 233, 233}, {287, 287, 287, 287, 287, 287, 287, 287, 287, 287, 287, 287, 287, 287, 287, 134, 134, 287, 287, 287, 287, 287, 287, 287, 134, 287, 287, 287, 287, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 287, 287, 287, 287}, {235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 134, 134, 235, 235, 235, 235, 235, 235, 235, 134, 235, 235, 235, 235, 134, 134, 134, 101, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 235, 235, 235, 235}, {237, 237, 237, 237, 237, 237, 237, 237, 237, 237, 237, 237, 237, 237, 237, 134, 134, 237, 237, 237, 237, 237, 237, 237, 134, 237, 237, 237, 237, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 102, 134, 134, 134, 134, 237, 237, 237, 237}, {239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 134, 134, 239, 239, 239, 239, 239, 239, 239, 134, 239, 239, 239, 239, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 103, 134, 134, 134, 239, 239, 239, 239}, {241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 134, 134, 241, 241, 241, 241, 241, 241, 241, 134, 241, 241, 241, 241, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 241, 241, 241, 241}, {243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 134, 134, 243, 243, 243, 243, 243, 243, 243, 134, 243, 243, 243, 243, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 243, 243, 243, 243}, {245, 245, 245, 245, 245, 245, 245, 245, 245, 245, 245, 245, 245, 245, 245, 134, 134, 245, 245, 245, 245, 245, 245, 245, 134, 245, 245, 245, 245, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 245, 245, 245, 245}, {291, 291, 291, 291, 291, 291, 291, 291, 291, 291, 291, 291, 291, 291, 291, 134, 134, 291, 291, 291, 291, 291, 291, 291, 134, 291, 291, 291, 291, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 291, 291, 291, 291}, {247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 134, 134, 247, 247, 247, 247, 247, 247, 247, 134, 247, 247, 247, 247, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 104, 134, 134, 247, 247, 247, 247}, {292, 292, 292, 292, 292, 292, 292, 292, 292, 292, 292, 292, 292, 292, 292, 134, 134, 292, 292, 292, 292, 292, 292, 292, 134, 292, 292, 292, 292, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 292, 292, 292, 292}, {249, 249, 249, 249, 249, 249, 249, 249, 249, 249, 249, 249, 249, 249, 249, 134, 134, 249, 249, 249, 249, 249, 249, 249, 134, 249, 249, 249, 249, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 105, 249, 249, 249, 249}, {293, 293, 293, 293, 293, 293, 293, 293, 293, 293, 293, 293, 293, 293, 293, 134, 134, 293, 293, 293, 293, 293, 293, 293, 134, 293, 293, 293, 293, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 293, 293, 293, 293}}};
::ISPA_STD::DFA::API::Table<144, 4> Parser::Lexer::action_table = {{{1, 6, ::ISPA_STD::DFA::API::null_state, 22}, {1, 26, ::ISPA_STD::DFA::API::null_state, 29}, {1, 26, ::ISPA_STD::DFA::API::null_state, 28}, {1, 26, ::ISPA_STD::DFA::API::null_state, 27}, {1, 26, ::ISPA_STD::DFA::API::null_state, 26}, {1, 26, ::ISPA_STD::DFA::API::null_state, 34}, {1, 26, ::ISPA_STD::DFA::API::null_state, 33}, {1, 26, ::ISPA_STD::DFA::API::null_state, 31}, {1, 26, ::ISPA_STD::DFA::API::null_state, 30}, {1, 2, ::ISPA_STD::DFA::API::null_state, 14}, {1, 16, ::ISPA_STD::DFA::API::null_state, 10}, {1, 18, ::ISPA_STD::DFA::API::null_state, 9}, {1, 20, ::ISPA_STD::DFA::API::null_state, 20}, {1, 26, ::ISPA_STD::DFA::API::null_state, 32}, {1, 0, ::ISPA_STD::DFA::API::null_state, 38}, {1, 0, ::ISPA_STD::DFA::API::null_state, 41}, {1, 26, ::ISPA_STD::DFA::API::null_state, 39}, {1, 19, ::ISPA_STD::DFA::API::null_state, 257}, {1, 17, ::ISPA_STD::DFA::API::null_state, 258}, {1, 3, ::ISPA_STD::DFA::API::null_state, 261}, {1, 3, ::ISPA_STD::DFA::API::null_state, 44}, {1, 21, ::ISPA_STD::DFA::API::null_state, 267}, {1, 7, ::ISPA_STD::DFA::API::null_state, 269}, {1, 24, ::ISPA_STD::DFA::API::null_state, 47}, {1, 24, ::ISPA_STD::DFA::API::null_state, 49}, {1, 24, ::ISPA_STD::DFA::API::null_state, 48}, {3, 6, 26, 269}, {1, 7, ::ISPA_STD::DFA::API::null_state, 132}, {3, 6, 26, 46}, {3, 6, 26, 269}, {1, 7, ::ISPA_STD::DFA::API::null_state, 135}, {3, 6, 26, 269}, {1, 7, ::ISPA_STD::DFA::API::null_state, 137}, {3, 6, 26, 269}, {1, 7, ::ISPA_STD::DFA::API::null_state, 139}, {3, 6, 26, 269}, {1, 7, ::ISPA_STD::DFA::API::null_state, 141}, {3, 6, 26, 269}, {1, 7, ::ISPA_STD::DFA::API::null_state, 143}, {3, 6, 26, 269}, {1, 7, ::ISPA_STD::DFA::API::null_state, 145}, {3, 6, 26, 269}, {1, 7, ::ISPA_STD::DFA::API::null_state, 147}, {3, 6, 26, 269}, {1, 7, ::ISPA_STD::DFA::API::null_state, 149}, {1, 1, ::ISPA_STD::DFA::API::null_state, 40}, {1, 1, ::ISPA_STD::DFA::API::null_state, 62}, {3, 0, 26, 38}, {3, 0, 26, 41}, {3, 0, 26, 40}, {1, 1, ::ISPA_STD::DFA::API::null_state, 155}, {3, 0, 26, 62}, {1, 1, ::ISPA_STD::DFA::API::null_state, 157}, {1, 4, ::ISPA_STD::DFA::API::null_state, 63}, {1, 7, ::ISPA_STD::DFA::API::null_state, 278}, {1, 25, ::ISPA_STD::DFA::API::null_state, 64}, {1, 23, ::ISPA_STD::DFA::API::null_state, 65}, {1, 23, ::ISPA_STD::DFA::API::null_state, 66}, {3, 6, 26, 278}, {1, 7, ::ISPA_STD::DFA::API::null_state, 164}, {3, 6, 26, 278}, {1, 7, ::ISPA_STD::DFA::API::null_state, 166}, {3, 6, 26, 278}, {1, 7, ::ISPA_STD::DFA::API::null_state, 168}, {3, 6, 26, 278}, {1, 7, ::ISPA_STD::DFA::API::null_state, 170}, {3, 6, 26, 278}, {1, 7, ::ISPA_STD::DFA::API::null_state, 172}, {3, 6, 26, 278}, {1, 7, ::ISPA_STD::DFA::API::null_state, 174}, {3, 6, 26, 278}, {1, 7, ::ISPA_STD::DFA::API::null_state, 176}, {3, 6, 26, 278}, {1, 7, ::ISPA_STD::DFA::API::null_state, 178}, {3, 6, 26, 278}, {1, 7, ::ISPA_STD::DFA::API::null_state, 180}, {3, 6, 26, 278}, {1, 7, ::ISPA_STD::DFA::API::null_state, 182}, {1, 5, ::ISPA_STD::DFA::API::null_state, 281}, {1, 25, ::ISPA_STD::DFA::API::null_state, 78}, {3, 6, 26, 278}, {1, 7, ::ISPA_STD::DFA::API::null_state, 186}, {3, 6, 26, 278}, {1, 7, ::ISPA_STD::DFA::API::null_state, 188}, {3, 6, 26, 278}, {1, 7, ::ISPA_STD::DFA::API::null_state, 190}, {3, 6, 26, 278}, {1, 7, ::ISPA_STD::DFA::API::null_state, 192}, {3, 6, 26, 278}, {1, 7, ::ISPA_STD::DFA::API::null_state, 194}, {3, 6, 26, 278}, {1, 7, ::ISPA_STD::DFA::API::null_state, 196}, {3, 6, 26, 278}, {1, 7, ::ISPA_STD::DFA::API::null_state, 198}, {3, 6, 26, 278}, {1, 7, ::ISPA_STD::DFA::API::null_state, 200}, {3, 6, 26, 278}, {1, 7, ::ISPA_STD::DFA::API::null_state, 202}, {3, 6, 26, 278}, {1, 7, ::ISPA_STD::DFA::API::null_state, 204}, {3, 24, 23, 282}, {3, 22, 24, 206}, {3, 6, 26, 278}, {1, 7, ::ISPA_STD::DFA::API::null_state, 208}, {3, 6, 26, 278}, {1, 7, ::ISPA_STD::DFA::API::null_state, 210}, {3, 6, 26, 278}, {1, 7, ::ISPA_STD::DFA::API::null_state, 212}, {3, 6, 26, 278}, {1, 7, ::ISPA_STD::DFA::API::null_state, 214}, {3, 6, 26, 278}, {1, 7, ::ISPA_STD::DFA::API::null_state, 216}, {3, 6, 26, 278}, {1, 7, ::ISPA_STD::DFA::API::null_state, 218}, {3, 6, 26, 278}, {1, 7, ::ISPA_STD::DFA::API::null_state, 220}, {3, 6, 26, 278}, {1, 7, ::ISPA_STD::DFA::API::null_state, 222}, {3, 12, 26, 285}, {1, 13, ::ISPA_STD::DFA::API::null_state, 224}, {3, 6, 26, 278}, {1, 7, ::ISPA_STD::DFA::API::null_state, 226}, {3, 6, 26, 278}, {1, 7, ::ISPA_STD::DFA::API::null_state, 228}, {3, 6, 26, 278}, {1, 7, ::ISPA_STD::DFA::API::null_state, 230}, {3, 6, 26, 278}, {1, 7, ::ISPA_STD::DFA::API::null_state, 232}, {3, 6, 26, 278}, {1, 7, ::ISPA_STD::DFA::API::null_state, 234}, {3, 6, 26, 278}, {1, 7, ::ISPA_STD::DFA::API::null_state, 236}, {3, 6, 26, 278}, {1, 7, ::ISPA_STD::DFA::API::null_state, 238}, {3, 10, 26, 288}, {1, 11, ::ISPA_STD::DFA::API::null_state, 240}, {3, 8, 26, 289}, {1, 9, ::ISPA_STD::DFA::API::null_state, 242}, {3, 14, 26, 290}, {1, 15, ::ISPA_STD::DFA::API::null_state, 244}, {3, 6, 26, 278}, {1, 7, ::ISPA_STD::DFA::API::null_state, 246}, {3, 6, 26, 278}, {1, 7, ::ISPA_STD::DFA::API::null_state, 248}}};
std::array<::ISPA_STD::DFA::API::DFADebug, 1> Parser::Lexer::debug_array = {::ISPA_STD::DFA::API::DFADebug {"<Undefined>", "", 0, -1, -1, -1, 0, 1, '\000'}};
std::unordered_map<long long, std::unordered_map<long long, long long>> Parser::Lexer::debug_index = { { 0, { { 1, 0 }, { 2, 0 }, { 3, 0 }, { 4, 0 }, { 5, 0 }, { 6, 0 }, { 7, 0 }, { 8, 0 }, { 9, 0 }, { 12, 0 }, { 13, 0 }, { 14, 0 }, { 17, 0 }, { 18, 0 }, { 19, 0 }, { 20, 0 }, { 21, 0 }, { 23, 0 }, { 25, 0 }, { 26, 0 }, { 27, 0 }, { 49, 0 }, { 50, 0 }, { 51, 0 } } }, { 1, { { 1, 0 } } }, { 2, { { 7, 0 } } }, { 3, { { 25, 0 } } }, { 12, { { 21, 0 } } }, { 14, { { 15, 0 }, { 16, 0 } } }, { 18, { { 21, 0 } } }, { 22, { { 15, 0 }, { 16, 0 }, { 24, 0 }, { 29, 0 }, { 30, 0 }, { 31, 0 }, { 32, 0 }, { 33, 0 }, { 34, 0 }, { 35, 0 }, { 36, 0 }, { 37, 0 }, { 38, 0 }, { 39, 0 }, { 40, 0 }, { 41, 0 }, { 42, 0 }, { 43, 0 }, { 44, 0 }, { 45, 0 }, { 46, 0 }, { 47, 0 }, { 48, 0 } } }, { 24, { { 45, 0 } } }, { 26, { { 39, 0 } } }, { 27, { { 33, 0 } } }, { 28, { { 47, 0 } } }, { 29, { { 29, 0 }, { 41, 0 } } }, { 30, { { 39, 0 } } }, { 31, { { 41, 0 } } }, { 32, { { 29, 0 }, { 33, 0 } } }, { 33, { { 44, 0 } } }, { 34, { { 38, 0 } } }, { 38, { { 0, 0 }, { 1, 0 }, { 3, 0 }, { 4, 0 }, { 5, 0 }, { 6, 0 }, { 8, 0 }, { 9, 0 }, { 10, 0 }, { 11, 0 }, { 12, 0 }, { 13, 0 }, { 14, 0 }, { 15, 0 }, { 16, 0 }, { 17, 0 }, { 18, 0 }, { 19, 0 }, { 20, 0 }, { 21, 0 }, { 22, 0 }, { 23, 0 }, { 24, 0 }, { 25, 0 }, { 26, 0 }, { 27, 0 }, { 28, 0 }, { 29, 0 }, { 30, 0 }, { 31, 0 }, { 32, 0 }, { 33, 0 }, { 34, 0 }, { 35, 0 }, { 36, 0 }, { 37, 0 }, { 38, 0 }, { 39, 0 }, { 40, 0 }, { 41, 0 }, { 42, 0 }, { 43, 0 }, { 44, 0 }, { 45, 0 }, { 46, 0 }, { 47, 0 }, { 48, 0 }, { 49, 0 }, { 50, 0 }, { 51, 0 } } }, { 41, { { 10, 0 } } }, { 46, { { 15, 0 }, { 16, 0 }, { 24, 0 }, { 29, 0 }, { 30, 0 }, { 31, 0 }, { 32, 0 }, { 33, 0 }, { 34, 0 }, { 35, 0 }, { 36, 0 }, { 37, 0 }, { 38, 0 }, { 39, 0 }, { 40, 0 }, { 41, 0 }, { 42, 0 }, { 43, 0 }, { 44, 0 }, { 45, 0 }, { 46, 0 }, { 47, 0 }, { 48, 0 } } }, { 47, { { 0, 0 }, { 1, 0 }, { 2, 0 }, { 3, 0 }, { 4, 0 }, { 5, 0 }, { 6, 0 }, { 7, 0 }, { 8, 0 }, { 9, 0 }, { 10, 0 }, { 11, 0 }, { 12, 0 }, { 13, 0 }, { 14, 0 }, { 15, 0 }, { 16, 0 }, { 17, 0 }, { 18, 0 }, { 19, 0 }, { 20, 0 }, { 21, 0 }, { 22, 0 }, { 23, 0 }, { 24, 0 }, { 25, 0 }, { 26, 0 }, { 28, 0 }, { 29, 0 }, { 30, 0 }, { 31, 0 }, { 32, 0 }, { 33, 0 }, { 34, 0 }, { 35, 0 }, { 36, 0 }, { 37, 0 }, { 38, 0 }, { 39, 0 }, { 40, 0 }, { 41, 0 }, { 42, 0 }, { 43, 0 }, { 44, 0 }, { 45, 0 }, { 46, 0 }, { 47, 0 }, { 48, 0 }, { 49, 0 }, { 50, 0 }, { 51, 0 } } }, { 48, { { 10, 0 } } }, { 50, { { 15, 0 } } }, { 51, { { 29, 0 } } }, { 52, { { 43, 0 } } }, { 53, { { 46, 0 } } }, { 54, { { 37, 0 } } }, { 56, { { 42, 0 } } }, { 57, { { 39, 0 } } }, { 58, { { 46, 0 } } }, { 59, { { 46, 0 } } }, { 60, { { 42, 0 } } }, { 61, { { 37, 0 } } }, { 62, { { 0, 0 }, { 1, 0 }, { 3, 0 }, { 4, 0 }, { 5, 0 }, { 6, 0 }, { 8, 0 }, { 9, 0 }, { 10, 0 }, { 11, 0 }, { 12, 0 }, { 13, 0 }, { 14, 0 }, { 15, 0 }, { 16, 0 }, { 17, 0 }, { 18, 0 }, { 19, 0 }, { 20, 0 }, { 21, 0 }, { 22, 0 }, { 23, 0 }, { 24, 0 }, { 25, 0 }, { 26, 0 }, { 27, 0 }, { 28, 0 }, { 29, 0 }, { 30, 0 }, { 31, 0 }, { 32, 0 }, { 33, 0 }, { 34, 0 }, { 35, 0 }, { 36, 0 }, { 37, 0 }, { 38, 0 }, { 39, 0 }, { 40, 0 }, { 41, 0 }, { 42, 0 }, { 43, 0 }, { 44, 0 }, { 45, 0 }, { 46, 0 }, { 47, 0 }, { 48, 0 }, { 49, 0 }, { 50, 0 }, { 51, 0 } } }, { 63, { { 15, 0 }, { 16, 0 } } }, { 65, { { 0, 0 }, { 1, 0 }, { 2, 0 }, { 3, 0 }, { 4, 0 }, { 5, 0 }, { 6, 0 }, { 7, 0 }, { 8, 0 }, { 9, 0 }, { 10, 0 }, { 11, 0 }, { 12, 0 }, { 13, 0 }, { 14, 0 }, { 15, 0 }, { 16, 0 }, { 17, 0 }, { 18, 0 }, { 19, 0 }, { 20, 0 }, { 21, 0 }, { 22, 0 }, { 23, 0 }, { 24, 0 }, { 25, 0 }, { 26, 0 }, { 28, 0 }, { 29, 0 }, { 30, 0 }, { 31, 0 }, { 32, 0 }, { 33, 0 }, { 34, 0 }, { 35, 0 }, { 36, 0 }, { 37, 0 }, { 38, 0 }, { 39, 0 }, { 40, 0 }, { 41, 0 }, { 42, 0 }, { 43, 0 }, { 44, 0 }, { 45, 0 }, { 46, 0 }, { 47, 0 }, { 48, 0 }, { 49, 0 }, { 50, 0 }, { 51, 0 } } }, { 66, { { 10, 0 } } }, { 68, { { 45, 0 } } }, { 69, { { 33, 0 } } }, { 70, { { 33, 0 } } }, { 71, { { 39, 0 } } }, { 72, { { 30, 0 } } }, { 73, { { 37, 0 } } }, { 74, { { 31, 0 } } }, { 75, { { 36, 0 } } }, { 76, { { 43, 0 } } }, { 77, { { 43, 0 } } }, { 79, { { 45, 0 } } }, { 80, { { 41, 0 } } }, { 81, { { 44, 0 } } }, { 83, { { 29, 0 } } }, { 84, { { 41, 0 } } }, { 85, { { 36, 0 } } }, { 86, { { 42, 0 } } }, { 87, { { 33, 0 } } }, { 90, { { 32, 0 } } }, { 91, { { 41, 0 } } }, { 92, { { 39, 0 } } }, { 93, { { 33, 0 } } }, { 95, { { 32, 0 } } }, { 96, { { 44, 0 } } }, { 97, { { 45, 0 } } }, { 102, { { 46, 0 } } }, { 104, { { 48, 0 } } } };
template<typename IT, class> auto Parser::Parser::main(IT pos) -> ::ISPA_STD::MatchResult<Types::main, IT> {
	::ISPA_STD::Node<Types::modules::main::main> value_modules_main_main;
	auto recovery_scope = recovery_frame("main");
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COLON::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::fail_block::fail_block::FAIL::id, Tokens::modules::forward_declaration::cls::CLASS::id, Tokens::modules::forward_declaration::cls::class_method::METHOD::id, Tokens::modules::forward_declaration::cls::class_property::PROPERTY::id, Tokens::modules::forward_declaration::fun::FN::id, Tokens::modules::grammar::modifier::AUTO::id, Tokens::modules::grammar::modifier::MOD::id, Tokens::modules::grammar::modifier::RIGHT_SQUARE_BRACKET::id, Tokens::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::unpack::AUTO::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>>("modules::main::main", "modules::main::main");
		value_modules_main_main = required<Types::modules::main::main>(pos, [this](auto cursor) { return this->modulesMainMain(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id, Tokens::modules::fail_block::fail_block::FAIL::id, Tokens::modules::grammar::modifier::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COLON::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::fail_block::fail_block::FAIL::id, Tokens::modules::forward_declaration::cls::CLASS::id, Tokens::modules::forward_declaration::cls::class_method::METHOD::id, Tokens::modules::forward_declaration::cls::class_property::PROPERTY::id, Tokens::modules::forward_declaration::fun::FN::id, Tokens::modules::grammar::modifier::AUTO::id, Tokens::modules::grammar::modifier::MOD::id, Tokens::modules::grammar::modifier::RIGHT_SQUARE_BRACKET::id, Tokens::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::unpack::AUTO::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("main", "modules::main::main"));
	}
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
template<typename IT, class> auto Parser::Parser::modulesRuleRegularValueCounterBounded(IT pos) -> ::ISPA_STD::MatchResult<Types::modules::rule::regular::value::counter::bounded, IT> {
	::ISPA_STD::Node<Types::EQUALS_SIGN> value_EQUALS_SIGN;
	std::variant<std::monostate, ::ISPA_STD::Node<Types::modules::common::NUMBER>, ::ISPA_STD::Node<Types::modules::common::ID>, ::ISPA_STD::Node<Types::modules::common::expr>> choice0;
	bool matched0;
	::ISPA_STD::Node<Types::modules::common::NUMBER> value_modules_common_NUMBER;
	::ISPA_STD::Node<Types::modules::common::ID> value_modules_common_ID;
	::ISPA_STD::Node<Types::modules::common::expr> value_modules_common_expr;
	auto recovery_scope = recovery_frame("modules::rule::regular::value::counter::bounded");
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::EQUALS_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id>>("EQUALS_SIGN", "EQUALS_SIGN", "__WS", "<group>");
		value_EQUALS_SIGN = required<Types::EQUALS_SIGN>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::EQUALS_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::EQUALS_SIGN::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id>, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::rule::regular::value::counter::bounded", "EQUALS_SIGN"));
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id>>("__WS", "__WS", "<group>");
		skip_spaces<Types::__WS>(pos);
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id>>("<group>", "<group>");
		// grammar `@  ( modules::common::NUMBER |  modules::common::ID |  modules::common::expr)`: choice; alternative selected by LL(1) lookahead
		matched0 = false;
		auto la0_1 = pos;
		std::size_t external_choice_0_1 = 0;
		if (::ISPA_STD::external_starts<::PyRawParser::Exports::ExpressionBlock>(la0_1)) {
			if (external_choice_0_1) {
				throw std::runtime_error("Ambiguous external parser alternatives");
			}
			external_choice_0_1 = 1;
		}
		if ((*la0_1).kind() == Tokens::modules::common::ID::id) {
			if (external_choice_0_1) {
				throw std::runtime_error("Ambiguous external parser alternatives");
			}
			external_choice_0_1 = 2;
		}
		if ((*la0_1).kind() == Tokens::modules::common::NUMBER::id) {
			if (external_choice_0_1) {
				throw std::runtime_error("Ambiguous external parser alternatives");
			}
			external_choice_0_1 = 3;
		}
		switch (external_choice_0_1) {
			case 1: {
				value_modules_common_expr = required<Types::modules::common::expr>(la0_1, [this](auto cursor) { return this->modulesCommonExpr(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value::counter::bounded", "<group>"));
				choice0 = value_modules_common_expr;
				matched0 = true;
				break;
			}
			case 2: {
				value_modules_common_ID = required<Types::modules::common::ID>(la0_1, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value::counter::bounded", "<group>"));
				choice0 = value_modules_common_ID;
				matched0 = true;
				break;
			}
			case 3: {
				value_modules_common_NUMBER = required<Types::modules::common::NUMBER>(la0_1, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value::counter::bounded", "<group>"));
				choice0 = value_modules_common_NUMBER;
				matched0 = true;
				break;
			}
		}
		pos = la0_1;
		if (!matched0) {
			switch (recover_choice<ISPA_STD::Recovery::Tokens<Tokens::modules::common::NUMBER::id>, ISPA_STD::Recovery::Tokens<Tokens::modules::common::NUMBER::id>, ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Tokens<Tokens::__ISPA_EXTERNAL_54::id>, ISPA_STD::Recovery::Tokens<Tokens::__ISPA_EXTERNAL_54::id>>(pos, "modules::rule::regular::value::counter::bounded", "modules::common::NUMBER, modules::common::ID, __ISPA_EXTERNAL_54")) {
				case 0: {
					value_modules_common_NUMBER = required<Types::modules::common::NUMBER>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value::counter::bounded", "<group>"));
					choice0 = value_modules_common_NUMBER;
					matched0 = true;
					break;
				}
				case 1: {
					value_modules_common_ID = required<Types::modules::common::ID>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value::counter::bounded", "<group>"));
					choice0 = value_modules_common_ID;
					matched0 = true;
					break;
				}
				case 2: {
					value_modules_common_expr = required<Types::modules::common::expr>(pos, [this](auto cursor) { return this->modulesCommonExpr(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value::counter::bounded", "<group>"));
					choice0 = value_modules_common_expr;
					matched0 = true;
					break;
				}
			}
		}
		if (!matched0) {
			return {};
		}
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
template<typename IT, class> auto Parser::Parser::modulesRuleRegularValueShared_counter_registration(IT pos) -> ::ISPA_STD::MatchResult<Types::modules::rule::regular::value::shared_counter_registration, IT> {
	::ISPA_STD::Node<Types::modules::rule::regular::value::shared_counter_registration::AUTO> value_modules_rule_regular_value_shared_counter_registration_AUTO;
	::ISPA_STD::Node<Types::modules::common::ID> value_modules_common_ID;
	auto recovery_scope = recovery_frame("modules::rule::regular::value::shared_counter_registration");
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id>>("modules::rule::regular::value::shared_counter_registration::AUTO", "modules::rule::regular::value::shared_counter_registration::AUTO", "__WS", "modules::common::ID");
		value_modules_rule_regular_value_shared_counter_registration_AUTO = required<Types::modules::rule::regular::value::shared_counter_registration::AUTO>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::rule::regular::value::shared_counter_registration", "modules::rule::regular::value::shared_counter_registration::AUTO"));
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id>>("__WS", "__WS", "modules::common::ID");
		skip_spaces<Types::__WS>(pos);
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id>>("modules::common::ID", "modules::common::ID");
		value_modules_common_ID = required<Types::modules::common::ID>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::rule::regular::value::shared_counter_registration", "modules::common::ID"));
	}
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
template<typename IT, class> auto Parser::Parser::modulesRuleRegularValueCounterQuantified(IT pos) -> ::ISPA_STD::MatchResult<Types::modules::rule::regular::value::counter::quantified, IT> {
	::ISPA_STD::Node<Types::modules::rule::regular::value::QUANTIFIER> value_modules_rule_regular_value_QUANTIFIER;
	::ISPA_STD::Node<Types::modules::rule::regular::value::counter::bounded> value_modules_rule_regular_value_counter_bounded;
	auto recovery_scope = recovery_frame("modules::rule::regular::value::counter::quantified");
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::modules::rule::regular::value::QUANTIFIER::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::EQUALS_SIGN::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id>>("modules::rule::regular::value::QUANTIFIER", "modules::rule::regular::value::QUANTIFIER", "__WS", "modules::rule::regular::value::counter::bounded");
		value_modules_rule_regular_value_QUANTIFIER = required<Types::modules::rule::regular::value::QUANTIFIER>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::modules::rule::regular::value::QUANTIFIER::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::EQUALS_SIGN::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::rule::regular::value::QUANTIFIER::id>, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::rule::regular::value::counter::quantified", "modules::rule::regular::value::QUANTIFIER"));
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::EQUALS_SIGN::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id>>("__WS", "__WS", "modules::rule::regular::value::counter::bounded");
		skip_spaces<Types::__WS>(pos);
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::EQUALS_SIGN::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id>>("modules::rule::regular::value::counter::bounded", "modules::rule::regular::value::counter::bounded");
		value_modules_rule_regular_value_counter_bounded = optional<Types::modules::rule::regular::value::counter::bounded>(pos, [this](auto cursor) { return this->modulesRuleRegularValueCounterBounded(cursor); });
	}
	Types::modules::rule::regular::value::counter::quantified result;
	::ISPA_STD::assign_compatible(result.quantifier, value_modules_rule_regular_value_QUANTIFIER);
	::ISPA_STD::assign_compatible(result.repetitions, value_modules_rule_regular_value_counter_bounded);
	::ISPA_STD::MatchResult<Types::modules::rule::regular::value::counter::quantified, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::modulesRuleRegularValueCounterQuantified<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::modules::rule::regular::value::counter::quantified, ::Parser::Lexer::iterator>;
template auto Parser::Parser::modulesRuleRegularValueCounterQuantified<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::modules::rule::regular::value::counter::quantified, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::modulesRuleRegularValueAlternative(IT pos) -> ::ISPA_STD::MatchResult<Types::modules::rule::regular::value::alternative, IT> {
	::ISPA_STD::Node<Types::modules::rule::regular::value::alternative::VERTICAL_LINE> value_modules_rule_regular_value_alternative_VERTICAL_LINE;
	::ISPA_STD::Node<Types::modules::rule::regular::value::pattern> value_modules_rule_regular_value_pattern;
	auto recovery_scope = recovery_frame("modules::rule::regular::value::alternative");
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>>("modules::rule::regular::value::alternative::VERTICAL_LINE", "modules::rule::regular::value::alternative::VERTICAL_LINE", "__WS", "modules::rule::regular::value::pattern");
		value_modules_rule_regular_value_alternative_VERTICAL_LINE = required<Types::modules::rule::regular::value::alternative::VERTICAL_LINE>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id>, ISPA_STD::Recovery::Tokens<Tokens::LEFT_PARENTHESIS::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::rule::regular::value::alternative", "modules::rule::regular::value::alternative::VERTICAL_LINE"));
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>>("__WS", "__WS", "modules::rule::regular::value::pattern");
		skip_spaces<Types::__WS>(pos);
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>>("modules::rule::regular::value::pattern", "modules::rule::regular::value::pattern");
		value_modules_rule_regular_value_pattern = required<Types::modules::rule::regular::value::pattern>(pos, [this](auto cursor) { return this->modulesRuleRegularValuePattern(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::LEFT_PARENTHESIS::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value::alternative", "modules::rule::regular::value::pattern"));
	}
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
template<typename IT, class> auto Parser::Parser::modulesRuleRegularValueDynDyn_expr(IT pos) -> ::ISPA_STD::MatchResult<Types::modules::rule::regular::value::dyn::dyn_expr, IT> {
	::ISPA_STD::Node<Types::LEFT_CURLY_BRACKET> value_LEFT_CURLY_BRACKET;
	::ISPA_STD::Node<Types::modules::common::expr> value_modules_common_expr;
	::ISPA_STD::Node<Types::RIGHT_CURLY_BRACKET> value_RIGHT_CURLY_BRACKET;
	auto recovery_scope = recovery_frame("modules::rule::regular::value::dyn::dyn_expr");
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::LEFT_CURLY_BRACKET::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::__ISPA_EXTERNAL_54::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id>>("LEFT_CURLY_BRACKET", "LEFT_CURLY_BRACKET", "__WS", "modules::common::expr", "__WS", "RIGHT_CURLY_BRACKET");
		value_LEFT_CURLY_BRACKET = required<Types::LEFT_CURLY_BRACKET>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::LEFT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::__ISPA_EXTERNAL_54::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::LEFT_CURLY_BRACKET::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::__ISPA_EXTERNAL_54::id>, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::rule::regular::value::dyn::dyn_expr", "LEFT_CURLY_BRACKET"));
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::__ISPA_EXTERNAL_54::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id>>("__WS", "__WS", "modules::common::expr", "__WS", "RIGHT_CURLY_BRACKET");
		skip_spaces<Types::__WS>(pos);
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::__ISPA_EXTERNAL_54::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id>>("modules::common::expr", "modules::common::expr", "__WS", "RIGHT_CURLY_BRACKET");
		value_modules_common_expr = required<Types::modules::common::expr>(pos, [this](auto cursor) { return this->modulesCommonExpr(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::__ISPA_EXTERNAL_54::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id, Tokens::__ISPA_EXTERNAL_54::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value::dyn::dyn_expr", "modules::common::expr"));
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id>>("__WS", "__WS", "RIGHT_CURLY_BRACKET");
		skip_spaces<Types::__WS>(pos);
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id>>("RIGHT_CURLY_BRACKET", "RIGHT_CURLY_BRACKET");
		value_RIGHT_CURLY_BRACKET = required<Types::RIGHT_CURLY_BRACKET>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::rule::regular::value::dyn::dyn_expr", "RIGHT_CURLY_BRACKET"));
	}
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
	auto recovery_scope = recovery_frame("modules::rule::regular::value::group");
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::LEFT_PARENTHESIS::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_PARENTHESIS::id>>("LEFT_PARENTHESIS", "LEFT_PARENTHESIS", "__WS", "modules::rule::regular::value", "__WS", "RIGHT_PARENTHESIS");
		value_LEFT_PARENTHESIS = required<Types::LEFT_PARENTHESIS>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::LEFT_PARENTHESIS::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::rule::regular::value::group", "LEFT_PARENTHESIS"));
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_PARENTHESIS::id>>("__WS", "__WS", "modules::rule::regular::value", "__WS", "RIGHT_PARENTHESIS");
		skip_spaces<Types::__WS>(pos);
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_PARENTHESIS::id>>("modules::rule::regular::value", "modules::rule::regular::value", "__WS", "RIGHT_PARENTHESIS");
		value_list_modules_rule_regular_value = range<Types::modules::rule::regular::value, Types::__WS>(pos, [this](auto cursor) { return this->modulesRuleRegularValue(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_PARENTHESIS::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value::group", "modules::rule::regular::value"));
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_PARENTHESIS::id>>("__WS", "__WS", "RIGHT_PARENTHESIS");
		skip_spaces<Types::__WS>(pos);
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::RIGHT_PARENTHESIS::id>>("RIGHT_PARENTHESIS", "RIGHT_PARENTHESIS");
		value_RIGHT_PARENTHESIS = required<Types::RIGHT_PARENTHESIS>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::RIGHT_PARENTHESIS::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_PARENTHESIS::id>, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::rule::regular::value::group", "RIGHT_PARENTHESIS"));
	}
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
template<typename IT, class> auto Parser::Parser::modulesRuleRegularValueMul_capture(IT pos) -> ::ISPA_STD::MatchResult<Types::modules::rule::regular::value::mul_capture, IT> {
	std::variant<std::monostate, ::ISPA_STD::Node<Types::COMMERCIAL_AT>, ::ISPA_STD::Node<Types::PERCENT_SIGN>> choice0;
	bool matched0;
	::ISPA_STD::Node<Types::COMMERCIAL_AT> value_COMMERCIAL_AT;
	::ISPA_STD::Node<Types::PERCENT_SIGN> value_PERCENT_SIGN;
	::ISPA_STD::Node<Types::EQUALS_SIGN> value_EQUALS_SIGN;
	::ISPA_STD::Node<Types::LEFT_PARENTHESIS> value_LEFT_PARENTHESIS;
	std::vector<::ISPA_STD::Node<Types::modules::rule::regular::value::one_capture>> value_list_modules_rule_regular_value_one_capture;
	::ISPA_STD::Node<Types::RIGHT_PARENTHESIS> value_RIGHT_PARENTHESIS;
	auto recovery_scope = recovery_frame("modules::rule::regular::value::mul_capture");
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::COMMERCIAL_AT::id, Tokens::PERCENT_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::EQUALS_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::LEFT_PARENTHESIS::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_PARENTHESIS::id>>("<group>", "<group>", "__WS", "EQUALS_SIGN", "__WS", "LEFT_PARENTHESIS", "__WS", "modules::rule::regular::value::one_capture", "__WS", "RIGHT_PARENTHESIS");
		// grammar `@  ( COMMERCIAL_AT |  PERCENT_SIGN)`: choice; alternative selected by LL(1) lookahead
		matched0 = false;
		auto la0_1 = pos;
		switch ((*la0_1).kind()) {
			case Tokens::COMMERCIAL_AT::id: {
				value_COMMERCIAL_AT = required<Types::COMMERCIAL_AT>(la0_1, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::COMMERCIAL_AT::id, Tokens::PERCENT_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::EQUALS_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value::mul_capture", "<group>"));
				choice0 = value_COMMERCIAL_AT;
				matched0 = true;
				break;
			}
			case Tokens::PERCENT_SIGN::id: {
				value_PERCENT_SIGN = required<Types::PERCENT_SIGN>(la0_1, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::COMMERCIAL_AT::id, Tokens::PERCENT_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::EQUALS_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value::mul_capture", "<group>"));
				choice0 = value_PERCENT_SIGN;
				matched0 = true;
				break;
			}
		}
		pos = la0_1;
		if (!matched0) {
			switch (recover_choice<ISPA_STD::Recovery::Tokens<Tokens::COMMERCIAL_AT::id>, ISPA_STD::Recovery::Tokens<Tokens::COMMERCIAL_AT::id>, ISPA_STD::Recovery::Tokens<Tokens::PERCENT_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::PERCENT_SIGN::id>>(pos, "modules::rule::regular::value::mul_capture", "COMMERCIAL_AT, PERCENT_SIGN")) {
				case 0: {
					value_COMMERCIAL_AT = required<Types::COMMERCIAL_AT>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::COMMERCIAL_AT::id, Tokens::PERCENT_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::EQUALS_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value::mul_capture", "<group>"));
					choice0 = value_COMMERCIAL_AT;
					matched0 = true;
					break;
				}
				case 1: {
					value_PERCENT_SIGN = required<Types::PERCENT_SIGN>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::COMMERCIAL_AT::id, Tokens::PERCENT_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::EQUALS_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value::mul_capture", "<group>"));
					choice0 = value_PERCENT_SIGN;
					matched0 = true;
					break;
				}
			}
		}
		if (!matched0) {
			return {};
		}
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::EQUALS_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::LEFT_PARENTHESIS::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_PARENTHESIS::id>>("__WS", "__WS", "EQUALS_SIGN", "__WS", "LEFT_PARENTHESIS", "__WS", "modules::rule::regular::value::one_capture", "__WS", "RIGHT_PARENTHESIS");
		skip_spaces<Types::__WS>(pos);
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::EQUALS_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::LEFT_PARENTHESIS::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_PARENTHESIS::id>>("EQUALS_SIGN", "EQUALS_SIGN", "__WS", "LEFT_PARENTHESIS", "__WS", "modules::rule::regular::value::one_capture", "__WS", "RIGHT_PARENTHESIS");
		value_EQUALS_SIGN = required<Types::EQUALS_SIGN>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::EQUALS_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::LEFT_PARENTHESIS::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::rule::regular::value::mul_capture", "EQUALS_SIGN"));
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::LEFT_PARENTHESIS::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_PARENTHESIS::id>>("__WS", "__WS", "LEFT_PARENTHESIS", "__WS", "modules::rule::regular::value::one_capture", "__WS", "RIGHT_PARENTHESIS");
		skip_spaces<Types::__WS>(pos);
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::LEFT_PARENTHESIS::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_PARENTHESIS::id>>("LEFT_PARENTHESIS", "LEFT_PARENTHESIS", "__WS", "modules::rule::regular::value::one_capture", "__WS", "RIGHT_PARENTHESIS");
		value_LEFT_PARENTHESIS = required<Types::LEFT_PARENTHESIS>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::LEFT_PARENTHESIS::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::rule::regular::value::mul_capture", "LEFT_PARENTHESIS"));
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_PARENTHESIS::id>>("__WS", "__WS", "modules::rule::regular::value::one_capture", "__WS", "RIGHT_PARENTHESIS");
		skip_spaces<Types::__WS>(pos);
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_PARENTHESIS::id>>("modules::rule::regular::value::one_capture", "modules::rule::regular::value::one_capture", "__WS", "RIGHT_PARENTHESIS");
		value_list_modules_rule_regular_value_one_capture = range<Types::modules::rule::regular::value::one_capture, Types::__WS>(pos, [this](auto cursor) { return this->modulesRuleRegularValueOne_capture(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_PARENTHESIS::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value::mul_capture", "modules::rule::regular::value::one_capture"));
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_PARENTHESIS::id>>("__WS", "__WS", "RIGHT_PARENTHESIS");
		skip_spaces<Types::__WS>(pos);
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::RIGHT_PARENTHESIS::id>>("RIGHT_PARENTHESIS", "RIGHT_PARENTHESIS");
		value_RIGHT_PARENTHESIS = required<Types::RIGHT_PARENTHESIS>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::RIGHT_PARENTHESIS::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_PARENTHESIS::id>, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::rule::regular::value::mul_capture", "RIGHT_PARENTHESIS"));
	}
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
	auto recovery_scope = recovery_frame("modules::rule::regular::value::pattern");
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>>("<group>", "<group>");
		// grammar `@  ( modules::common::name |  modules::rule::regular::value::group |  modules::rule::regular::value::dyn |  modules::rule::regular::value::STRING |  modules::rule::regular::value::CGROUP |  modules::rule::regular::value::ANY |  modules::rule::regular::value::SPACE |  modules::rule::regular::value::NOSPACE)`: choice; alternative selected by LL(1) lookahead
		matched0 = false;
		auto la0_1 = pos;
		switch ((*la0_1).kind()) {
			case Tokens::LEFT_PARENTHESIS::id: {
				value_modules_rule_regular_value_group = required<Types::modules::rule::regular::value::group>(la0_1, [this](auto cursor) { return this->modulesRuleRegularValueGroup(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::LEFT_PARENTHESIS::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value::pattern", "<group>"));
				choice0 = value_modules_rule_regular_value_group;
				matched0 = true;
				break;
			}
			case Tokens::modules::common::ID::id: {
				value_modules_common_name = required<Types::modules::common::name>(la0_1, [this](auto cursor) { return this->modulesCommonName(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::LEFT_PARENTHESIS::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value::pattern", "<group>"));
				choice0 = value_modules_common_name;
				matched0 = true;
				break;
			}
			case Tokens::modules::rule::regular::value::ANY::id: {
				value_modules_rule_regular_value_ANY = required<Types::modules::rule::regular::value::ANY>(la0_1, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::LEFT_PARENTHESIS::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value::pattern", "<group>"));
				choice0 = value_modules_rule_regular_value_ANY;
				matched0 = true;
				break;
			}
			case Tokens::modules::rule::regular::value::CGROUP::id: {
				value_modules_rule_regular_value_CGROUP = required<Types::modules::rule::regular::value::CGROUP>(la0_1, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::LEFT_PARENTHESIS::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value::pattern", "<group>"));
				choice0 = value_modules_rule_regular_value_CGROUP;
				matched0 = true;
				break;
			}
			case Tokens::modules::rule::regular::value::NOSPACE::id: {
				value_modules_rule_regular_value_NOSPACE = required<Types::modules::rule::regular::value::NOSPACE>(la0_1, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::LEFT_PARENTHESIS::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value::pattern", "<group>"));
				choice0 = value_modules_rule_regular_value_NOSPACE;
				matched0 = true;
				break;
			}
			case Tokens::modules::rule::regular::value::SPACE::id: {
				value_modules_rule_regular_value_SPACE = required<Types::modules::rule::regular::value::SPACE>(la0_1, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::LEFT_PARENTHESIS::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value::pattern", "<group>"));
				choice0 = value_modules_rule_regular_value_SPACE;
				matched0 = true;
				break;
			}
			case Tokens::modules::rule::regular::value::STRING::id: {
				value_modules_rule_regular_value_STRING = required<Types::modules::rule::regular::value::STRING>(la0_1, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::LEFT_PARENTHESIS::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value::pattern", "<group>"));
				choice0 = value_modules_rule_regular_value_STRING;
				matched0 = true;
				break;
			}
			case Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id: {
				value_modules_rule_regular_value_dyn = required<Types::modules::rule::regular::value::dyn>(la0_1, [this](auto cursor) { return this->modulesRuleRegularValueDyn(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::LEFT_PARENTHESIS::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value::pattern", "<group>"));
				choice0 = value_modules_rule_regular_value_dyn;
				matched0 = true;
				break;
			}
		}
		pos = la0_1;
		if (!matched0) {
			switch (recover_choice<ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Tokens<Tokens::COMMA::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_PARENTHESIS::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::modules::common::ID::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::LEFT_PARENTHESIS::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::LEFT_CURLY_BRACKET::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::modules::rule::regular::value::STRING::id>, ISPA_STD::Recovery::Tokens<Tokens::modules::rule::regular::value::STRING::id>, ISPA_STD::Recovery::Tokens<Tokens::modules::rule::regular::value::CGROUP::id>, ISPA_STD::Recovery::Tokens<Tokens::modules::rule::regular::value::CGROUP::id>, ISPA_STD::Recovery::Tokens<Tokens::modules::rule::regular::value::ANY::id>, ISPA_STD::Recovery::Tokens<Tokens::modules::rule::regular::value::ANY::id>, ISPA_STD::Recovery::Tokens<Tokens::modules::rule::regular::value::SPACE::id>, ISPA_STD::Recovery::Tokens<Tokens::modules::rule::regular::value::SPACE::id>, ISPA_STD::Recovery::Tokens<Tokens::modules::rule::regular::value::NOSPACE::id>, ISPA_STD::Recovery::Tokens<Tokens::modules::rule::regular::value::NOSPACE::id>>(pos, "modules::rule::regular::value::pattern", "modules::common::ID, LEFT_PARENTHESIS, modules::rule::regular::value::dyn::DOLLAR_SIGN, modules::rule::regular::value::STRING, modules::rule::regular::value::CGROUP, modules::rule::regular::value::ANY, modules::rule::regular::value::SPACE, modules::rule::regular::value::NOSPACE")) {
				case 0: {
					value_modules_common_name = required<Types::modules::common::name>(pos, [this](auto cursor) { return this->modulesCommonName(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::LEFT_PARENTHESIS::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value::pattern", "<group>"));
					choice0 = value_modules_common_name;
					matched0 = true;
					break;
				}
				case 1: {
					value_modules_rule_regular_value_group = required<Types::modules::rule::regular::value::group>(pos, [this](auto cursor) { return this->modulesRuleRegularValueGroup(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::LEFT_PARENTHESIS::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value::pattern", "<group>"));
					choice0 = value_modules_rule_regular_value_group;
					matched0 = true;
					break;
				}
				case 2: {
					value_modules_rule_regular_value_dyn = required<Types::modules::rule::regular::value::dyn>(pos, [this](auto cursor) { return this->modulesRuleRegularValueDyn(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::LEFT_PARENTHESIS::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value::pattern", "<group>"));
					choice0 = value_modules_rule_regular_value_dyn;
					matched0 = true;
					break;
				}
				case 3: {
					value_modules_rule_regular_value_STRING = required<Types::modules::rule::regular::value::STRING>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::LEFT_PARENTHESIS::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value::pattern", "<group>"));
					choice0 = value_modules_rule_regular_value_STRING;
					matched0 = true;
					break;
				}
				case 4: {
					value_modules_rule_regular_value_CGROUP = required<Types::modules::rule::regular::value::CGROUP>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::LEFT_PARENTHESIS::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value::pattern", "<group>"));
					choice0 = value_modules_rule_regular_value_CGROUP;
					matched0 = true;
					break;
				}
				case 5: {
					value_modules_rule_regular_value_ANY = required<Types::modules::rule::regular::value::ANY>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::LEFT_PARENTHESIS::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value::pattern", "<group>"));
					choice0 = value_modules_rule_regular_value_ANY;
					matched0 = true;
					break;
				}
				case 6: {
					value_modules_rule_regular_value_SPACE = required<Types::modules::rule::regular::value::SPACE>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::LEFT_PARENTHESIS::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value::pattern", "<group>"));
					choice0 = value_modules_rule_regular_value_SPACE;
					matched0 = true;
					break;
				}
				case 7: {
					value_modules_rule_regular_value_NOSPACE = required<Types::modules::rule::regular::value::NOSPACE>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::LEFT_PARENTHESIS::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value::pattern", "<group>"));
					choice0 = value_modules_rule_regular_value_NOSPACE;
					matched0 = true;
					break;
				}
			}
		}
		if (!matched0) {
			return {};
		}
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
	auto recovery_scope = recovery_frame("modules::rule::regular::value::fail_capture");
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::PERCENT_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::COMMA::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_PARENTHESIS::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::modules::common::ID::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id>>("PERCENT_SIGN", "PERCENT_SIGN", "modules::common::name");
		value_PERCENT_SIGN = required<Types::PERCENT_SIGN>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::PERCENT_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::LEFT_PARENTHESIS::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::LEFT_PARENTHESIS::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::COMMA::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::modules::common::ID::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id>, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::rule::regular::value::fail_capture", "PERCENT_SIGN"));
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::COMMA::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_PARENTHESIS::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::modules::common::ID::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id>>("modules::common::name", "modules::common::name");
		value_modules_common_name = optional<Types::modules::common::name>(pos, [this](auto cursor) { return this->modulesCommonName(cursor); });
	}
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
	auto recovery_scope = recovery_frame("modules::rule::regular::value::ast_capture");
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::COMMERCIAL_AT::id>, ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id>>("COMMERCIAL_AT", "COMMERCIAL_AT", "modules::common::ID");
		value_COMMERCIAL_AT = required<Types::COMMERCIAL_AT>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::COMMERCIAL_AT::id>, ISPA_STD::Recovery::Tokens<Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::COMMERCIAL_AT::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::rule::regular::value::ast_capture", "COMMERCIAL_AT"));
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id>>("modules::common::ID", "modules::common::ID");
		value_modules_common_ID = optional<Types::modules::common::ID>(pos);
	}
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
template<typename IT, class> auto Parser::Parser::modulesRuleRegularValueCounter(IT pos) -> ::ISPA_STD::MatchResult<Types::modules::rule::regular::value::counter, IT> {
	std::variant<std::monostate, ::ISPA_STD::Node<Types::modules::rule::regular::value::counter::bounded>, ::ISPA_STD::Node<Types::modules::rule::regular::value::counter::quantified>> choice0;
	bool matched0;
	::ISPA_STD::Node<Types::modules::rule::regular::value::counter::bounded> value_modules_rule_regular_value_counter_bounded;
	::ISPA_STD::Node<Types::modules::rule::regular::value::counter::quantified> value_modules_rule_regular_value_counter_quantified;
	auto recovery_scope = recovery_frame("modules::rule::regular::value::counter");
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::EQUALS_SIGN::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::rule::regular::value::QUANTIFIER::id>>("<group>", "<group>");
		// grammar `@  ( modules::rule::regular::value::counter::bounded |  modules::rule::regular::value::counter::quantified)`: choice; alternative selected by LL(1) lookahead
		matched0 = false;
		auto la0_1 = pos;
		switch ((*la0_1).kind()) {
			case Tokens::EQUALS_SIGN::id: {
				value_modules_rule_regular_value_counter_bounded = required<Types::modules::rule::regular::value::counter::bounded>(la0_1, [this](auto cursor) { return this->modulesRuleRegularValueCounterBounded(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::EQUALS_SIGN::id, Tokens::modules::rule::regular::value::QUANTIFIER::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::EQUALS_SIGN::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::rule::regular::value::QUANTIFIER::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value::counter", "<group>"));
				choice0 = value_modules_rule_regular_value_counter_bounded;
				matched0 = true;
				break;
			}
			case Tokens::modules::rule::regular::value::QUANTIFIER::id: {
				value_modules_rule_regular_value_counter_quantified = required<Types::modules::rule::regular::value::counter::quantified>(la0_1, [this](auto cursor) { return this->modulesRuleRegularValueCounterQuantified(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::EQUALS_SIGN::id, Tokens::modules::rule::regular::value::QUANTIFIER::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::EQUALS_SIGN::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::rule::regular::value::QUANTIFIER::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value::counter", "<group>"));
				choice0 = value_modules_rule_regular_value_counter_quantified;
				matched0 = true;
				break;
			}
		}
		pos = la0_1;
		if (!matched0) {
			switch (recover_choice<ISPA_STD::Recovery::Tokens<Tokens::EQUALS_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::EQUALS_SIGN::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id>, ISPA_STD::Recovery::Tokens<Tokens::modules::rule::regular::value::QUANTIFIER::id>, ISPA_STD::Recovery::Tokens<Tokens::EQUALS_SIGN::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::rule::regular::value::QUANTIFIER::id>>(pos, "modules::rule::regular::value::counter", "EQUALS_SIGN, modules::rule::regular::value::QUANTIFIER")) {
				case 0: {
					value_modules_rule_regular_value_counter_bounded = required<Types::modules::rule::regular::value::counter::bounded>(pos, [this](auto cursor) { return this->modulesRuleRegularValueCounterBounded(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::EQUALS_SIGN::id, Tokens::modules::rule::regular::value::QUANTIFIER::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::EQUALS_SIGN::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::rule::regular::value::QUANTIFIER::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value::counter", "<group>"));
					choice0 = value_modules_rule_regular_value_counter_bounded;
					matched0 = true;
					break;
				}
				case 1: {
					value_modules_rule_regular_value_counter_quantified = required<Types::modules::rule::regular::value::counter::quantified>(pos, [this](auto cursor) { return this->modulesRuleRegularValueCounterQuantified(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::EQUALS_SIGN::id, Tokens::modules::rule::regular::value::QUANTIFIER::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::EQUALS_SIGN::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::rule::regular::value::QUANTIFIER::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value::counter", "<group>"));
					choice0 = value_modules_rule_regular_value_counter_quantified;
					matched0 = true;
					break;
				}
			}
		}
		if (!matched0) {
			return {};
		}
	}
	Types::modules::rule::regular::value::counter result;
	::ISPA_STD::assign_compatible(result.value, choice0);
	::ISPA_STD::MatchResult<Types::modules::rule::regular::value::counter, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::modulesRuleRegularValueCounter<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::modules::rule::regular::value::counter, ::Parser::Lexer::iterator>;
template auto Parser::Parser::modulesRuleRegularValueCounter<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::modules::rule::regular::value::counter, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::modulesRuleRegularValueVar_capture(IT pos) -> ::ISPA_STD::MatchResult<Types::modules::rule::regular::value::var_capture, IT> {
	::ISPA_STD::Node<Types::AMPERSAND> value_AMPERSAND;
	::ISPA_STD::Node<Types::modules::common::ID> value_modules_common_ID;
	auto recovery_scope = recovery_frame("modules::rule::regular::value::var_capture");
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id>>("AMPERSAND", "AMPERSAND", "__WS", "modules::common::ID");
		value_AMPERSAND = required<Types::AMPERSAND>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id>, ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Tokens<Tokens::COMMERCIAL_AT::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::rule::regular::value::var_capture", "AMPERSAND"));
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id>>("__WS", "__WS", "modules::common::ID");
		skip_spaces<Types::__WS>(pos);
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id>>("modules::common::ID", "modules::common::ID");
		value_modules_common_ID = required<Types::modules::common::ID>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Tokens<Tokens::COMMERCIAL_AT::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::COMMERCIAL_AT::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::rule::regular::value::var_capture", "modules::common::ID"));
	}
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
template<typename IT, class> auto Parser::Parser::modules__externalPythonSymbol_1(IT pos) -> ::ISPA_STD::MatchResult<Types::modules::__external::python::symbol_1, IT> {
	return ::ISPA_STD::external_match<::PyRawParser::Exports::StatementsBlock>(pos);
}
template auto Parser::Parser::modules__externalPythonSymbol_1<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::modules::__external::python::symbol_1, ::Parser::Lexer::iterator>;
template auto Parser::Parser::modules__externalPythonSymbol_1<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::modules::__external::python::symbol_1, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::modulesRuleRegularAstFull(IT pos) -> ::ISPA_STD::MatchResult<Types::modules::rule::regular::ast::full, IT> {
	::ISPA_STD::Node<Types::AMPERSAND> value_AMPERSAND;
	::ISPA_STD::Node<Types::LEFT_CURLY_BRACKET> value_LEFT_CURLY_BRACKET;
	std::vector<::ISPA_STD::Node<Types::modules::rule::regular::ast::full::part>> value_list_modules_rule_regular_ast_full_part;
	::ISPA_STD::Node<Types::RIGHT_CURLY_BRACKET> value_RIGHT_CURLY_BRACKET;
	auto recovery_scope = recovery_frame("modules::rule::regular::ast::full");
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::LEFT_CURLY_BRACKET::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::COLON::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id>>("AMPERSAND", "AMPERSAND", "__WS", "LEFT_CURLY_BRACKET", "__WS", "modules::rule::regular::ast::full::part", "__WS", "RIGHT_CURLY_BRACKET");
		value_AMPERSAND = required<Types::AMPERSAND>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id>, ISPA_STD::Recovery::Tokens<Tokens::LEFT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::PERCENT_SIGN::id, Tokens::SEMICOLON::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COLON::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::rule::regular::ast::full", "AMPERSAND"));
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::LEFT_CURLY_BRACKET::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::COLON::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id>>("__WS", "__WS", "LEFT_CURLY_BRACKET", "__WS", "modules::rule::regular::ast::full::part", "__WS", "RIGHT_CURLY_BRACKET");
		skip_spaces<Types::__WS>(pos);
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::LEFT_CURLY_BRACKET::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::COLON::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id>>("LEFT_CURLY_BRACKET", "LEFT_CURLY_BRACKET", "__WS", "modules::rule::regular::ast::full::part", "__WS", "RIGHT_CURLY_BRACKET");
		value_LEFT_CURLY_BRACKET = required<Types::LEFT_CURLY_BRACKET>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::LEFT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Tokens<Tokens::PERCENT_SIGN::id, Tokens::SEMICOLON::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::COLON::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::rule::regular::ast::full", "LEFT_CURLY_BRACKET"));
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::COLON::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id>>("__WS", "__WS", "modules::rule::regular::ast::full::part", "__WS", "RIGHT_CURLY_BRACKET");
		skip_spaces<Types::__WS>(pos);
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::COLON::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id>>("modules::rule::regular::ast::full::part", "modules::rule::regular::ast::full::part", "__WS", "RIGHT_CURLY_BRACKET");
		value_list_modules_rule_regular_ast_full_part = range<Types::modules::rule::regular::ast::full::part, Types::__WS>(pos, [this](auto cursor) { return this->modulesRuleRegularAstFullPart(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::PERCENT_SIGN::id, Tokens::SEMICOLON::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::COLON::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::ast::full", "modules::rule::regular::ast::full::part"));
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id>>("__WS", "__WS", "RIGHT_CURLY_BRACKET");
		skip_spaces<Types::__WS>(pos);
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id>>("RIGHT_CURLY_BRACKET", "RIGHT_CURLY_BRACKET");
		value_RIGHT_CURLY_BRACKET = required<Types::RIGHT_CURLY_BRACKET>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::PERCENT_SIGN::id, Tokens::SEMICOLON::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::PERCENT_SIGN::id, Tokens::SEMICOLON::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::rule::regular::ast::full", "RIGHT_CURLY_BRACKET"));
	}
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
	auto recovery_scope = recovery_frame("modules::rule::regular::value::one_capture");
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::COMMERCIAL_AT::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::COMMA::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::modules::common::ID::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::EQUALS_SIGN::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::rule::regular::value::QUANTIFIER::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>>("modules::rule::regular::value::var_capture", "modules::rule::regular::value::var_capture", "__WS", "modules::rule::regular::value::ast_capture", "__WS", "modules::rule::regular::value::fail_capture", "__WS", "modules::rule::regular::value::pattern", "__WS", "modules::rule::regular::value::alternative", "__WS", "modules::rule::regular::value::counter", "__WS", "modules::rule::regular::value::shared_counter_registration");
		value_modules_rule_regular_value_var_capture = optional<Types::modules::rule::regular::value::var_capture>(pos, [this](auto cursor) { return this->modulesRuleRegularValueVar_capture(cursor); });
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::COMMERCIAL_AT::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::COMMA::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::modules::common::ID::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::EQUALS_SIGN::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::rule::regular::value::QUANTIFIER::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>>("__WS", "__WS", "modules::rule::regular::value::ast_capture", "__WS", "modules::rule::regular::value::fail_capture", "__WS", "modules::rule::regular::value::pattern", "__WS", "modules::rule::regular::value::alternative", "__WS", "modules::rule::regular::value::counter", "__WS", "modules::rule::regular::value::shared_counter_registration");
		skip_spaces<Types::__WS>(pos);
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::COMMERCIAL_AT::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::COMMA::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::modules::common::ID::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::EQUALS_SIGN::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::rule::regular::value::QUANTIFIER::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>>("modules::rule::regular::value::ast_capture", "modules::rule::regular::value::ast_capture", "__WS", "modules::rule::regular::value::fail_capture", "__WS", "modules::rule::regular::value::pattern", "__WS", "modules::rule::regular::value::alternative", "__WS", "modules::rule::regular::value::counter", "__WS", "modules::rule::regular::value::shared_counter_registration");
		value_modules_rule_regular_value_ast_capture = optional<Types::modules::rule::regular::value::ast_capture>(pos, [this](auto cursor) { return this->modulesRuleRegularValueAst_capture(cursor); });
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::COMMA::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::modules::common::ID::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::EQUALS_SIGN::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::rule::regular::value::QUANTIFIER::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>>("__WS", "__WS", "modules::rule::regular::value::fail_capture", "__WS", "modules::rule::regular::value::pattern", "__WS", "modules::rule::regular::value::alternative", "__WS", "modules::rule::regular::value::counter", "__WS", "modules::rule::regular::value::shared_counter_registration");
		skip_spaces<Types::__WS>(pos);
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::COMMA::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::modules::common::ID::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::EQUALS_SIGN::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::rule::regular::value::QUANTIFIER::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>>("modules::rule::regular::value::fail_capture", "modules::rule::regular::value::fail_capture", "__WS", "modules::rule::regular::value::pattern", "__WS", "modules::rule::regular::value::alternative", "__WS", "modules::rule::regular::value::counter", "__WS", "modules::rule::regular::value::shared_counter_registration");
		value_modules_rule_regular_value_fail_capture = optional<Types::modules::rule::regular::value::fail_capture>(pos, [this](auto cursor) { return this->modulesRuleRegularValueFail_capture(cursor); });
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::EQUALS_SIGN::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::rule::regular::value::QUANTIFIER::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>>("__WS", "__WS", "modules::rule::regular::value::pattern", "__WS", "modules::rule::regular::value::alternative", "__WS", "modules::rule::regular::value::counter", "__WS", "modules::rule::regular::value::shared_counter_registration");
		skip_spaces<Types::__WS>(pos);
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::EQUALS_SIGN::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::rule::regular::value::QUANTIFIER::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>>("modules::rule::regular::value::pattern", "modules::rule::regular::value::pattern", "__WS", "modules::rule::regular::value::alternative", "__WS", "modules::rule::regular::value::counter", "__WS", "modules::rule::regular::value::shared_counter_registration");
		value_modules_rule_regular_value_pattern = required<Types::modules::rule::regular::value::pattern>(pos, [this](auto cursor) { return this->modulesRuleRegularValuePattern(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::LEFT_PARENTHESIS::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value::one_capture", "modules::rule::regular::value::pattern"));
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::EQUALS_SIGN::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::rule::regular::value::QUANTIFIER::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>>("__WS", "__WS", "modules::rule::regular::value::alternative", "__WS", "modules::rule::regular::value::counter", "__WS", "modules::rule::regular::value::shared_counter_registration");
		skip_spaces<Types::__WS>(pos);
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::EQUALS_SIGN::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::rule::regular::value::QUANTIFIER::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>>("modules::rule::regular::value::alternative", "modules::rule::regular::value::alternative", "__WS", "modules::rule::regular::value::counter", "__WS", "modules::rule::regular::value::shared_counter_registration");
		value_list_modules_rule_regular_value_alternative = range_optional<Types::modules::rule::regular::value::alternative, Types::__WS>(pos, [this](auto cursor) { return this->modulesRuleRegularValueAlternative(cursor); });
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::EQUALS_SIGN::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::rule::regular::value::QUANTIFIER::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>>("__WS", "__WS", "modules::rule::regular::value::counter", "__WS", "modules::rule::regular::value::shared_counter_registration");
		skip_spaces<Types::__WS>(pos);
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::EQUALS_SIGN::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::rule::regular::value::QUANTIFIER::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>>("modules::rule::regular::value::counter", "modules::rule::regular::value::counter", "__WS", "modules::rule::regular::value::shared_counter_registration");
		value_modules_rule_regular_value_counter = optional<Types::modules::rule::regular::value::counter>(pos, [this](auto cursor) { return this->modulesRuleRegularValueCounter(cursor); });
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>>("__WS", "__WS", "modules::rule::regular::value::shared_counter_registration");
		skip_spaces<Types::__WS>(pos);
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>>("modules::rule::regular::value::shared_counter_registration", "modules::rule::regular::value::shared_counter_registration");
		value_modules_rule_regular_value_shared_counter_registration = optional<Types::modules::rule::regular::value::shared_counter_registration>(pos, [this](auto cursor) { return this->modulesRuleRegularValueShared_counter_registration(cursor); });
	}
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
	auto recovery_scope = recovery_frame("modules::rule::regular::ast::abbr");
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::COMMERCIAL_AT::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::LEFT_CURLY_BRACKET::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::COMMA::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id>>("COMMERCIAL_AT", "COMMERCIAL_AT", "__WS", "LEFT_CURLY_BRACKET", "__WS", "modules::common::ID", "__WS", "<group>", "__WS", "RIGHT_CURLY_BRACKET");
		value_COMMERCIAL_AT = required<Types::COMMERCIAL_AT>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::COMMERCIAL_AT::id>, ISPA_STD::Recovery::Tokens<Tokens::LEFT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::PERCENT_SIGN::id, Tokens::SEMICOLON::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::rule::regular::ast::abbr", "COMMERCIAL_AT"));
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::LEFT_CURLY_BRACKET::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::COMMA::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id>>("__WS", "__WS", "LEFT_CURLY_BRACKET", "__WS", "modules::common::ID", "__WS", "<group>", "__WS", "RIGHT_CURLY_BRACKET");
		skip_spaces<Types::__WS>(pos);
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::LEFT_CURLY_BRACKET::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::COMMA::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id>>("LEFT_CURLY_BRACKET", "LEFT_CURLY_BRACKET", "__WS", "modules::common::ID", "__WS", "<group>", "__WS", "RIGHT_CURLY_BRACKET");
		value_LEFT_CURLY_BRACKET = required<Types::LEFT_CURLY_BRACKET>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::LEFT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Tokens<Tokens::PERCENT_SIGN::id, Tokens::SEMICOLON::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::COMMA::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::rule::regular::ast::abbr", "LEFT_CURLY_BRACKET"));
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::COMMA::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id>>("__WS", "__WS", "modules::common::ID", "__WS", "<group>", "__WS", "RIGHT_CURLY_BRACKET");
		skip_spaces<Types::__WS>(pos);
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::COMMA::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id>>("modules::common::ID", "modules::common::ID", "__WS", "<group>", "__WS", "RIGHT_CURLY_BRACKET");
		value_modules_common_ID = required<Types::modules::common::ID>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Tokens<Tokens::COMMA::id, Tokens::RIGHT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::PERCENT_SIGN::id, Tokens::SEMICOLON::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::COMMA::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::rule::regular::ast::abbr", "modules::common::ID"));
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::COMMA::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id>>("__WS", "__WS", "<group>", "__WS", "RIGHT_CURLY_BRACKET");
		skip_spaces<Types::__WS>(pos);
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::COMMA::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id>>("<group>", "<group>", "__WS", "RIGHT_CURLY_BRACKET");
		// grammar ` ( COMMA  __WS?; @  modules::common::ID)*;`: repeat while lookahead is in FIRST
		while (((*pos).kind() == Tokens::COMMA::id)) {
			value_COMMA = required<Types::COMMA>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::COMMA::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::PERCENT_SIGN::id, Tokens::SEMICOLON::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::COMMA::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::ast::abbr", "<group>"));
			skip_spaces<Types::__WS>(pos);
			value_modules_common_ID_1 = required<Types::modules::common::ID>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::COMMA::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::PERCENT_SIGN::id, Tokens::SEMICOLON::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::COMMA::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::ast::abbr", "<group>"));
			group0 = std::make_pair(value_COMMA, value_modules_common_ID_1);
			group_list1.push_back(group0);
			capture_list2.push_back(value_modules_common_ID_1);
			skip_spaces<Types::__WS>(pos);
		}
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id>>("__WS", "__WS", "RIGHT_CURLY_BRACKET");
		skip_spaces<Types::__WS>(pos);
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id>>("RIGHT_CURLY_BRACKET", "RIGHT_CURLY_BRACKET");
		value_RIGHT_CURLY_BRACKET = required<Types::RIGHT_CURLY_BRACKET>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::PERCENT_SIGN::id, Tokens::SEMICOLON::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::PERCENT_SIGN::id, Tokens::SEMICOLON::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::rule::regular::ast::abbr", "RIGHT_CURLY_BRACKET"));
	}
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
	auto recovery_scope = recovery_frame("modules::rule::regular::ast::full::part");
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::COLON::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::__ISPA_EXTERNAL_54::id>>("modules::common::ID", "modules::common::ID", "__WS", "COLON", "__WS", "modules::common::expr");
		value_modules_common_ID = required<Types::modules::common::ID>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Tokens<Tokens::COLON::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Tokens<Tokens::COLON::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::rule::regular::ast::full::part", "modules::common::ID"));
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::COLON::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::__ISPA_EXTERNAL_54::id>>("__WS", "__WS", "COLON", "__WS", "modules::common::expr");
		skip_spaces<Types::__WS>(pos);
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::COLON::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::__ISPA_EXTERNAL_54::id>>("COLON", "COLON", "__WS", "modules::common::expr");
		value_COLON = required<Types::COLON>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::COLON::id>, ISPA_STD::Recovery::Tokens<Tokens::__ISPA_EXTERNAL_54::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Tokens<Tokens::COLON::id, Tokens::__ISPA_EXTERNAL_54::id>, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::rule::regular::ast::full::part", "COLON"));
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::__ISPA_EXTERNAL_54::id>>("__WS", "__WS", "modules::common::expr");
		skip_spaces<Types::__WS>(pos);
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::__ISPA_EXTERNAL_54::id>>("modules::common::expr", "modules::common::expr");
		value_modules_common_expr = required<Types::modules::common::expr>(pos, [this](auto cursor) { return this->modulesCommonExpr(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::__ISPA_EXTERNAL_54::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Tokens<Tokens::__ISPA_EXTERNAL_54::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::ast::full::part", "modules::common::expr"));
	}
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
	::ISPA_STD::Node<Types::modules::rule::advanced::advanced_rule::regular_match::unpack::AUTO> value_modules_rule_advanced_advanced_rule_regular_match_unpack_AUTO;
	std::vector<::ISPA_STD::Node<Types::modules::common::ID>> value_list_modules_common_ID;
	auto recovery_scope = recovery_frame("modules::rule::advanced::advanced_rule::regular_match::unpack");
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::modules::rule::advanced::advanced_rule::regular_match::unpack::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id>>("modules::rule::advanced::advanced_rule::regular_match::unpack::AUTO", "modules::rule::advanced::advanced_rule::regular_match::unpack::AUTO", "__WS", "modules::common::ID");
		value_modules_rule_advanced_advanced_rule_regular_match_unpack_AUTO = required<Types::modules::rule::advanced::advanced_rule::regular_match::unpack::AUTO>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::modules::rule::advanced::advanced_rule::regular_match::unpack::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id>, ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::unpack::AUTO::id>, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::rule::advanced::advanced_rule::regular_match::unpack", "modules::rule::advanced::advanced_rule::regular_match::unpack::AUTO"));
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id>>("__WS", "__WS", "modules::common::ID");
		skip_spaces<Types::__WS>(pos);
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id>>("modules::common::ID", "modules::common::ID");
		value_list_modules_common_ID = range<Types::modules::common::ID, Types::__WS>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id>, ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::rule::advanced::advanced_rule::regular_match::unpack", "modules::common::ID"));
	}
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
	auto recovery_scope = recovery_frame("modules::rule::regular::ast");
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COLON::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id>>("<group>", "<group>");
		// grammar `@  ( modules::rule::regular::ast::abbr |  modules::rule::regular::ast::full |  modules::rule::regular::ast::single_value)`: choice; alternative selected by LL(1) lookahead
		matched0 = false;
		auto la0_1 = pos;
		switch ((*la0_1).kind()) {
			case Tokens::AMPERSAND::id: {
				value_modules_rule_regular_ast_full = required<Types::modules::rule::regular::ast::full>(la0_1, [this](auto cursor) { return this->modulesRuleRegularAstFull(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::PERCENT_SIGN::id, Tokens::SEMICOLON::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::PERCENT_SIGN::id, Tokens::SEMICOLON::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COLON::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::ast", "<group>"));
				choice0 = value_modules_rule_regular_ast_full;
				matched0 = true;
				break;
			}
			case Tokens::COMMERCIAL_AT::id: {
				value_modules_rule_regular_ast_abbr = required<Types::modules::rule::regular::ast::abbr>(la0_1, [this](auto cursor) { return this->modulesRuleRegularAstAbbr(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::PERCENT_SIGN::id, Tokens::SEMICOLON::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::PERCENT_SIGN::id, Tokens::SEMICOLON::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COLON::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::ast", "<group>"));
				choice0 = value_modules_rule_regular_ast_abbr;
				matched0 = true;
				break;
			}
			case Tokens::LEFT_CURLY_BRACKET::id: {
				value_modules_rule_regular_ast_single_value = required<Types::modules::rule::regular::ast::single_value>(la0_1, [this](auto cursor) { return this->modulesRuleRegularAstSingle_value(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::PERCENT_SIGN::id, Tokens::SEMICOLON::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::PERCENT_SIGN::id, Tokens::SEMICOLON::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COLON::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::ast", "<group>"));
				choice0 = value_modules_rule_regular_ast_single_value;
				matched0 = true;
				break;
			}
		}
		pos = la0_1;
		if (!matched0) {
			switch (recover_choice<ISPA_STD::Recovery::Tokens<Tokens::COMMERCIAL_AT::id>, ISPA_STD::Recovery::Tokens<Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COLON::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Tokens<Tokens::LEFT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::__ISPA_EXTERNAL_54::id>>(pos, "modules::rule::regular::ast", "COMMERCIAL_AT, AMPERSAND, LEFT_CURLY_BRACKET")) {
				case 0: {
					value_modules_rule_regular_ast_abbr = required<Types::modules::rule::regular::ast::abbr>(pos, [this](auto cursor) { return this->modulesRuleRegularAstAbbr(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::PERCENT_SIGN::id, Tokens::SEMICOLON::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::PERCENT_SIGN::id, Tokens::SEMICOLON::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COLON::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::ast", "<group>"));
					choice0 = value_modules_rule_regular_ast_abbr;
					matched0 = true;
					break;
				}
				case 1: {
					value_modules_rule_regular_ast_full = required<Types::modules::rule::regular::ast::full>(pos, [this](auto cursor) { return this->modulesRuleRegularAstFull(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::PERCENT_SIGN::id, Tokens::SEMICOLON::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::PERCENT_SIGN::id, Tokens::SEMICOLON::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COLON::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::ast", "<group>"));
					choice0 = value_modules_rule_regular_ast_full;
					matched0 = true;
					break;
				}
				case 2: {
					value_modules_rule_regular_ast_single_value = required<Types::modules::rule::regular::ast::single_value>(pos, [this](auto cursor) { return this->modulesRuleRegularAstSingle_value(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::PERCENT_SIGN::id, Tokens::SEMICOLON::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::PERCENT_SIGN::id, Tokens::SEMICOLON::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COLON::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::ast", "<group>"));
					choice0 = value_modules_rule_regular_ast_single_value;
					matched0 = true;
					break;
				}
			}
		}
		if (!matched0) {
			return {};
		}
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
	auto recovery_scope = recovery_frame("modules::rule::regular::regular_rule");
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::COLON::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COLON::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::COMMA::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COLON::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::forward_declaration::cls::CLASS::id, Tokens::modules::forward_declaration::cls::class_method::METHOD::id, Tokens::modules::forward_declaration::cls::class_property::PROPERTY::id, Tokens::modules::forward_declaration::fun::FN::id, Tokens::modules::grammar::modifier::AUTO::id, Tokens::modules::grammar::modifier::MOD::id, Tokens::modules::grammar::modifier::RIGHT_SQUARE_BRACKET::id, Tokens::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::unpack::AUTO::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::SEMICOLON::id>>("COLON", "COLON", "__WS", "modules::rule::regular::value", "__WS", "modules::rule::regular::ast", "__WS", "modules::rule::regular::f_binding", "__WS", "modules::rule::regular::nested_rule", "__WS", "SEMICOLON");
		value_COLON = required<Types::COLON>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::COLON::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::fail_block::fail_block::FAIL::id, Tokens::modules::grammar::modifier::AUTO::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COLON::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::forward_declaration::cls::CLASS::id, Tokens::modules::forward_declaration::cls::class_method::METHOD::id, Tokens::modules::forward_declaration::cls::class_property::PROPERTY::id, Tokens::modules::forward_declaration::fun::FN::id, Tokens::modules::grammar::modifier::AUTO::id, Tokens::modules::grammar::modifier::MOD::id, Tokens::modules::grammar::modifier::RIGHT_SQUARE_BRACKET::id, Tokens::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::unpack::AUTO::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::rule::regular::regular_rule", "COLON"));
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COLON::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::COMMA::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COLON::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::forward_declaration::cls::CLASS::id, Tokens::modules::forward_declaration::cls::class_method::METHOD::id, Tokens::modules::forward_declaration::cls::class_property::PROPERTY::id, Tokens::modules::forward_declaration::fun::FN::id, Tokens::modules::grammar::modifier::AUTO::id, Tokens::modules::grammar::modifier::MOD::id, Tokens::modules::grammar::modifier::RIGHT_SQUARE_BRACKET::id, Tokens::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::unpack::AUTO::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::SEMICOLON::id>>("__WS", "__WS", "modules::rule::regular::value", "__WS", "modules::rule::regular::ast", "__WS", "modules::rule::regular::f_binding", "__WS", "modules::rule::regular::nested_rule", "__WS", "SEMICOLON");
		skip_spaces<Types::__WS>(pos);
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COLON::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::COMMA::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COLON::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::forward_declaration::cls::CLASS::id, Tokens::modules::forward_declaration::cls::class_method::METHOD::id, Tokens::modules::forward_declaration::cls::class_property::PROPERTY::id, Tokens::modules::forward_declaration::fun::FN::id, Tokens::modules::grammar::modifier::AUTO::id, Tokens::modules::grammar::modifier::MOD::id, Tokens::modules::grammar::modifier::RIGHT_SQUARE_BRACKET::id, Tokens::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::unpack::AUTO::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::SEMICOLON::id>>("modules::rule::regular::value", "modules::rule::regular::value", "__WS", "modules::rule::regular::ast", "__WS", "modules::rule::regular::f_binding", "__WS", "modules::rule::regular::nested_rule", "__WS", "SEMICOLON");
		value_list_modules_rule_regular_value = range<Types::modules::rule::regular::value, Types::__WS>(pos, [this](auto cursor) { return this->modulesRuleRegularValue(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::PERCENT_SIGN::id, Tokens::SEMICOLON::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::fail_block::fail_block::FAIL::id, Tokens::modules::grammar::modifier::AUTO::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COLON::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::forward_declaration::cls::CLASS::id, Tokens::modules::forward_declaration::cls::class_method::METHOD::id, Tokens::modules::forward_declaration::cls::class_property::PROPERTY::id, Tokens::modules::forward_declaration::fun::FN::id, Tokens::modules::grammar::modifier::AUTO::id, Tokens::modules::grammar::modifier::MOD::id, Tokens::modules::grammar::modifier::RIGHT_SQUARE_BRACKET::id, Tokens::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::unpack::AUTO::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::regular_rule", "modules::rule::regular::value"));
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COLON::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::COMMA::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COLON::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::forward_declaration::cls::CLASS::id, Tokens::modules::forward_declaration::cls::class_method::METHOD::id, Tokens::modules::forward_declaration::cls::class_property::PROPERTY::id, Tokens::modules::forward_declaration::fun::FN::id, Tokens::modules::grammar::modifier::AUTO::id, Tokens::modules::grammar::modifier::MOD::id, Tokens::modules::grammar::modifier::RIGHT_SQUARE_BRACKET::id, Tokens::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::unpack::AUTO::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::SEMICOLON::id>>("__WS", "__WS", "modules::rule::regular::ast", "__WS", "modules::rule::regular::f_binding", "__WS", "modules::rule::regular::nested_rule", "__WS", "SEMICOLON");
		skip_spaces<Types::__WS>(pos);
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COLON::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::COMMA::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COLON::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::forward_declaration::cls::CLASS::id, Tokens::modules::forward_declaration::cls::class_method::METHOD::id, Tokens::modules::forward_declaration::cls::class_property::PROPERTY::id, Tokens::modules::forward_declaration::fun::FN::id, Tokens::modules::grammar::modifier::AUTO::id, Tokens::modules::grammar::modifier::MOD::id, Tokens::modules::grammar::modifier::RIGHT_SQUARE_BRACKET::id, Tokens::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::unpack::AUTO::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::SEMICOLON::id>>("modules::rule::regular::ast", "modules::rule::regular::ast", "__WS", "modules::rule::regular::f_binding", "__WS", "modules::rule::regular::nested_rule", "__WS", "SEMICOLON");
		value_modules_rule_regular_ast = optional<Types::modules::rule::regular::ast>(pos, [this](auto cursor) { return this->modulesRuleRegularAst(cursor); });
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::COMMA::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COLON::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::forward_declaration::cls::CLASS::id, Tokens::modules::forward_declaration::cls::class_method::METHOD::id, Tokens::modules::forward_declaration::cls::class_property::PROPERTY::id, Tokens::modules::forward_declaration::fun::FN::id, Tokens::modules::grammar::modifier::AUTO::id, Tokens::modules::grammar::modifier::MOD::id, Tokens::modules::grammar::modifier::RIGHT_SQUARE_BRACKET::id, Tokens::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::unpack::AUTO::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::SEMICOLON::id>>("__WS", "__WS", "modules::rule::regular::f_binding", "__WS", "modules::rule::regular::nested_rule", "__WS", "SEMICOLON");
		skip_spaces<Types::__WS>(pos);
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::COMMA::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COLON::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::forward_declaration::cls::CLASS::id, Tokens::modules::forward_declaration::cls::class_method::METHOD::id, Tokens::modules::forward_declaration::cls::class_property::PROPERTY::id, Tokens::modules::forward_declaration::fun::FN::id, Tokens::modules::grammar::modifier::AUTO::id, Tokens::modules::grammar::modifier::MOD::id, Tokens::modules::grammar::modifier::RIGHT_SQUARE_BRACKET::id, Tokens::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::unpack::AUTO::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::SEMICOLON::id>>("modules::rule::regular::f_binding", "modules::rule::regular::f_binding", "__WS", "modules::rule::regular::nested_rule", "__WS", "SEMICOLON");
		value_modules_rule_regular_f_binding = optional<Types::modules::rule::regular::f_binding>(pos, [this](auto cursor) { return this->modulesRuleRegularF_binding(cursor); });
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COLON::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::forward_declaration::cls::CLASS::id, Tokens::modules::forward_declaration::cls::class_method::METHOD::id, Tokens::modules::forward_declaration::cls::class_property::PROPERTY::id, Tokens::modules::forward_declaration::fun::FN::id, Tokens::modules::grammar::modifier::AUTO::id, Tokens::modules::grammar::modifier::MOD::id, Tokens::modules::grammar::modifier::RIGHT_SQUARE_BRACKET::id, Tokens::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::unpack::AUTO::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::SEMICOLON::id>>("__WS", "__WS", "modules::rule::regular::nested_rule", "__WS", "SEMICOLON");
		skip_spaces<Types::__WS>(pos);
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COLON::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::forward_declaration::cls::CLASS::id, Tokens::modules::forward_declaration::cls::class_method::METHOD::id, Tokens::modules::forward_declaration::cls::class_property::PROPERTY::id, Tokens::modules::forward_declaration::fun::FN::id, Tokens::modules::grammar::modifier::AUTO::id, Tokens::modules::grammar::modifier::MOD::id, Tokens::modules::grammar::modifier::RIGHT_SQUARE_BRACKET::id, Tokens::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::unpack::AUTO::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::SEMICOLON::id>>("modules::rule::regular::nested_rule", "modules::rule::regular::nested_rule", "__WS", "SEMICOLON");
		value_list_modules_rule_regular_nested_rule = range_optional<Types::modules::rule::regular::nested_rule, Types::__WS>(pos, [this](auto cursor) { return this->modulesRuleRegularNested_rule(cursor); });
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::SEMICOLON::id>>("__WS", "__WS", "SEMICOLON");
		skip_spaces<Types::__WS>(pos);
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::SEMICOLON::id>>("SEMICOLON", "SEMICOLON");
		value_SEMICOLON = required<Types::SEMICOLON>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::SEMICOLON::id>, ISPA_STD::Recovery::Tokens<Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::fail_block::fail_block::FAIL::id, Tokens::modules::grammar::modifier::AUTO::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::fail_block::fail_block::FAIL::id, Tokens::modules::grammar::modifier::AUTO::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::SEMICOLON::id>, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::rule::regular::regular_rule", "SEMICOLON"));
	}
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
template<typename IT, class> auto Parser::Parser::modulesRuleRegularValueDyn(IT pos) -> ::ISPA_STD::MatchResult<Types::modules::rule::regular::value::dyn, IT> {
	::ISPA_STD::Node<Types::modules::rule::regular::value::dyn::DOLLAR_SIGN> value_modules_rule_regular_value_dyn_DOLLAR_SIGN;
	std::variant<std::monostate, ::ISPA_STD::Node<Types::modules::rule::regular::value::dyn::dyn_expr>, ::ISPA_STD::Node<Types::modules::common::ID>> choice0;
	bool matched0;
	::ISPA_STD::Node<Types::modules::rule::regular::value::dyn::dyn_expr> value_modules_rule_regular_value_dyn_dyn_expr;
	::ISPA_STD::Node<Types::modules::common::ID> value_modules_common_ID;
	auto recovery_scope = recovery_frame("modules::rule::regular::value::dyn");
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::LEFT_CURLY_BRACKET::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id>>("modules::rule::regular::value::dyn::DOLLAR_SIGN", "modules::rule::regular::value::dyn::DOLLAR_SIGN", "__WS", "<group>");
		value_modules_rule_regular_value_dyn_DOLLAR_SIGN = required<Types::modules::rule::regular::value::dyn::DOLLAR_SIGN>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::LEFT_CURLY_BRACKET::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::LEFT_CURLY_BRACKET::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::rule::regular::value::dyn", "modules::rule::regular::value::dyn::DOLLAR_SIGN"));
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::LEFT_CURLY_BRACKET::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id>>("__WS", "__WS", "<group>");
		skip_spaces<Types::__WS>(pos);
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::LEFT_CURLY_BRACKET::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id>>("<group>", "<group>");
		// grammar `@  ( modules::rule::regular::value::dyn::dyn_expr |  modules::common::ID)`: choice; alternative selected by LL(1) lookahead
		matched0 = false;
		auto la0_1 = pos;
		switch ((*la0_1).kind()) {
			case Tokens::LEFT_CURLY_BRACKET::id: {
				value_modules_rule_regular_value_dyn_dyn_expr = required<Types::modules::rule::regular::value::dyn::dyn_expr>(la0_1, [this](auto cursor) { return this->modulesRuleRegularValueDynDyn_expr(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::LEFT_CURLY_BRACKET::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::LEFT_CURLY_BRACKET::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value::dyn", "<group>"));
				choice0 = value_modules_rule_regular_value_dyn_dyn_expr;
				matched0 = true;
				break;
			}
			case Tokens::modules::common::ID::id: {
				value_modules_common_ID = required<Types::modules::common::ID>(la0_1, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::LEFT_CURLY_BRACKET::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::LEFT_CURLY_BRACKET::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value::dyn", "<group>"));
				choice0 = value_modules_common_ID;
				matched0 = true;
				break;
			}
		}
		pos = la0_1;
		if (!matched0) {
			switch (recover_choice<ISPA_STD::Recovery::Tokens<Tokens::LEFT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::LEFT_CURLY_BRACKET::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::__ISPA_EXTERNAL_54::id>, ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id>>(pos, "modules::rule::regular::value::dyn", "LEFT_CURLY_BRACKET, modules::common::ID")) {
				case 0: {
					value_modules_rule_regular_value_dyn_dyn_expr = required<Types::modules::rule::regular::value::dyn::dyn_expr>(pos, [this](auto cursor) { return this->modulesRuleRegularValueDynDyn_expr(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::LEFT_CURLY_BRACKET::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::LEFT_CURLY_BRACKET::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value::dyn", "<group>"));
					choice0 = value_modules_rule_regular_value_dyn_dyn_expr;
					matched0 = true;
					break;
				}
				case 1: {
					value_modules_common_ID = required<Types::modules::common::ID>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::LEFT_CURLY_BRACKET::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::LEFT_CURLY_BRACKET::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value::dyn", "<group>"));
					choice0 = value_modules_common_ID;
					matched0 = true;
					break;
				}
			}
		}
		if (!matched0) {
			return {};
		}
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
template<typename IT, class> auto Parser::Parser::modulesCommonParam(IT pos) -> ::ISPA_STD::MatchResult<Types::modules::common::param, IT> {
	::ISPA_STD::Node<Types::modules::common::ID> value_modules_common_ID;
	::ISPA_STD::Node<Types::COMMA> value_COMMA;
	::ISPA_STD::Node<Types::modules::common::ID> value_modules_common_ID_1;
	std::pair<::ISPA_STD::Node<Types::COMMA>, ::ISPA_STD::Node<Types::modules::common::ID>> group0;
	std::vector<std::pair<::ISPA_STD::Node<Types::COMMA>, ::ISPA_STD::Node<Types::modules::common::ID>>> group_list1;
	std::vector<::ISPA_STD::Node<Types::modules::common::ID>> capture_list2;
	auto recovery_scope = recovery_frame("modules::common::param");
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::COMMA::id, Tokens::modules::common::ID::id>>("modules::common::ID", "modules::common::ID", "__WS", "<group>");
		value_modules_common_ID = required<Types::modules::common::ID>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Tokens<Tokens::COMMA::id, Tokens::GREATER_THAN_SIGN::id, Tokens::RIGHT_PARENTHESIS::id>, ISPA_STD::Recovery::Tokens<Tokens::GREATER_THAN_SIGN::id, Tokens::RIGHT_PARENTHESIS::id>, ISPA_STD::Recovery::Tokens<Tokens::COMMA::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::common::param", "modules::common::ID"));
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::COMMA::id, Tokens::modules::common::ID::id>>("__WS", "__WS", "<group>");
		skip_spaces<Types::__WS>(pos);
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::COMMA::id, Tokens::modules::common::ID::id>>("<group>", "<group>");
		// grammar ` ( COMMA  __WS?; @  modules::common::ID)*;`: repeat while lookahead is in FIRST
		while (((*pos).kind() == Tokens::COMMA::id)) {
			value_COMMA = required<Types::COMMA>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::COMMA::id>, ISPA_STD::Recovery::Tokens<Tokens::GREATER_THAN_SIGN::id, Tokens::RIGHT_PARENTHESIS::id>, ISPA_STD::Recovery::Tokens<Tokens::GREATER_THAN_SIGN::id, Tokens::RIGHT_PARENTHESIS::id>, ISPA_STD::Recovery::Tokens<Tokens::COMMA::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::common::param", "<group>"));
			skip_spaces<Types::__WS>(pos);
			value_modules_common_ID_1 = required<Types::modules::common::ID>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::COMMA::id>, ISPA_STD::Recovery::Tokens<Tokens::GREATER_THAN_SIGN::id, Tokens::RIGHT_PARENTHESIS::id>, ISPA_STD::Recovery::Tokens<Tokens::GREATER_THAN_SIGN::id, Tokens::RIGHT_PARENTHESIS::id>, ISPA_STD::Recovery::Tokens<Tokens::COMMA::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::common::param", "<group>"));
			group0 = std::make_pair(value_COMMA, value_modules_common_ID_1);
			group_list1.push_back(group0);
			capture_list2.push_back(value_modules_common_ID_1);
			skip_spaces<Types::__WS>(pos);
		}
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
template<typename IT, class> auto Parser::Parser::modulesGrammarModifier(IT pos) -> ::ISPA_STD::MatchResult<Types::modules::grammar::modifier, IT> {
	::ISPA_STD::Node<Types::modules::grammar::modifier::AUTO> value_modules_grammar_modifier_AUTO;
	::ISPA_STD::Node<Types::modules::grammar::modifier::MOD> value_modules_grammar_modifier_MOD;
	::ISPA_STD::Node<Types::modules::grammar::modifier::RIGHT_SQUARE_BRACKET> value_modules_grammar_modifier_RIGHT_SQUARE_BRACKET;
	auto recovery_scope = recovery_frame("modules::grammar::modifier");
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::modules::grammar::modifier::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::modules::grammar::modifier::MOD::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::modules::grammar::modifier::RIGHT_SQUARE_BRACKET::id>>("modules::grammar::modifier::AUTO", "modules::grammar::modifier::AUTO", "__WS", "modules::grammar::modifier::MOD", "__WS", "modules::grammar::modifier::RIGHT_SQUARE_BRACKET");
		value_modules_grammar_modifier_AUTO = required<Types::modules::grammar::modifier::AUTO>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::modules::grammar::modifier::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::modules::grammar::modifier::MOD::id>, ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id, Tokens::modules::grammar::modifier::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::modules::grammar::modifier::AUTO::id, Tokens::modules::grammar::modifier::MOD::id, Tokens::modules::grammar::modifier::RIGHT_SQUARE_BRACKET::id>, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::grammar::modifier", "modules::grammar::modifier::AUTO"));
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::modules::grammar::modifier::MOD::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::modules::grammar::modifier::RIGHT_SQUARE_BRACKET::id>>("__WS", "__WS", "modules::grammar::modifier::MOD", "__WS", "modules::grammar::modifier::RIGHT_SQUARE_BRACKET");
		skip_spaces<Types::__WS>(pos);
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::modules::grammar::modifier::MOD::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::modules::grammar::modifier::RIGHT_SQUARE_BRACKET::id>>("modules::grammar::modifier::MOD", "modules::grammar::modifier::MOD", "__WS", "modules::grammar::modifier::RIGHT_SQUARE_BRACKET");
		value_modules_grammar_modifier_MOD = required<Types::modules::grammar::modifier::MOD>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::modules::grammar::modifier::MOD::id>, ISPA_STD::Recovery::Tokens<Tokens::modules::grammar::modifier::RIGHT_SQUARE_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id, Tokens::modules::grammar::modifier::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::modules::grammar::modifier::MOD::id, Tokens::modules::grammar::modifier::RIGHT_SQUARE_BRACKET::id>, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::grammar::modifier", "modules::grammar::modifier::MOD"));
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::modules::grammar::modifier::RIGHT_SQUARE_BRACKET::id>>("__WS", "__WS", "modules::grammar::modifier::RIGHT_SQUARE_BRACKET");
		skip_spaces<Types::__WS>(pos);
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::modules::grammar::modifier::RIGHT_SQUARE_BRACKET::id>>("modules::grammar::modifier::RIGHT_SQUARE_BRACKET", "modules::grammar::modifier::RIGHT_SQUARE_BRACKET");
		value_modules_grammar_modifier_RIGHT_SQUARE_BRACKET = required<Types::modules::grammar::modifier::RIGHT_SQUARE_BRACKET>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::modules::grammar::modifier::RIGHT_SQUARE_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id, Tokens::modules::grammar::modifier::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id, Tokens::modules::grammar::modifier::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::modules::grammar::modifier::RIGHT_SQUARE_BRACKET::id>, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::grammar::modifier", "modules::grammar::modifier::RIGHT_SQUARE_BRACKET"));
	}
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
template<typename IT, class> auto Parser::Parser::modulesRuleRegularValue(IT pos) -> ::ISPA_STD::MatchResult<Types::modules::rule::regular::value, IT> {
	std::variant<std::monostate, ::ISPA_STD::Node<Types::modules::rule::regular::value::one_capture>, ::ISPA_STD::Node<Types::modules::rule::regular::value::mul_capture>> choice0;
	bool matched0;
	::ISPA_STD::Node<Types::modules::rule::regular::value::one_capture> value_modules_rule_regular_value_one_capture;
	::ISPA_STD::Node<Types::modules::rule::regular::value::mul_capture> value_modules_rule_regular_value_mul_capture;
	auto recovery_scope = recovery_frame("modules::rule::regular::value");
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>>("<group>", "<group>");
		// grammar `@  ( modules::rule::regular::value::one_capture |  modules::rule::regular::value::mul_capture)`: choice; alternative selected by LL(2) lookahead
		matched0 = false;
		auto la0_1 = pos;
		switch ((*la0_1).kind()) {
			case Tokens::AMPERSAND::id: {
				value_modules_rule_regular_value_one_capture = required<Types::modules::rule::regular::value::one_capture>(la0_1, [this](auto cursor) { return this->modulesRuleRegularValueOne_capture(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value", "<group>"));
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
						value_modules_rule_regular_value_mul_capture = required<Types::modules::rule::regular::value::mul_capture>(la0_2, [this](auto cursor) { return this->modulesRuleRegularValueMul_capture(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value", "<group>"));
						choice0 = value_modules_rule_regular_value_mul_capture;
						matched0 = true;
						break;
					}
					case Tokens::LEFT_PARENTHESIS::id: {
						la0_2 = la0_1;
						value_modules_rule_regular_value_one_capture = required<Types::modules::rule::regular::value::one_capture>(la0_2, [this](auto cursor) { return this->modulesRuleRegularValueOne_capture(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value", "<group>"));
						choice0 = value_modules_rule_regular_value_one_capture;
						matched0 = true;
						break;
					}
					case Tokens::PERCENT_SIGN::id: {
						la0_2 = la0_1;
						value_modules_rule_regular_value_one_capture = required<Types::modules::rule::regular::value::one_capture>(la0_2, [this](auto cursor) { return this->modulesRuleRegularValueOne_capture(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value", "<group>"));
						choice0 = value_modules_rule_regular_value_one_capture;
						matched0 = true;
						break;
					}
					case Tokens::modules::common::ID::id: {
						la0_2 = la0_1;
						value_modules_rule_regular_value_one_capture = required<Types::modules::rule::regular::value::one_capture>(la0_2, [this](auto cursor) { return this->modulesRuleRegularValueOne_capture(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value", "<group>"));
						choice0 = value_modules_rule_regular_value_one_capture;
						matched0 = true;
						break;
					}
					case Tokens::modules::rule::regular::value::ANY::id: {
						la0_2 = la0_1;
						value_modules_rule_regular_value_one_capture = required<Types::modules::rule::regular::value::one_capture>(la0_2, [this](auto cursor) { return this->modulesRuleRegularValueOne_capture(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value", "<group>"));
						choice0 = value_modules_rule_regular_value_one_capture;
						matched0 = true;
						break;
					}
					case Tokens::modules::rule::regular::value::CGROUP::id: {
						la0_2 = la0_1;
						value_modules_rule_regular_value_one_capture = required<Types::modules::rule::regular::value::one_capture>(la0_2, [this](auto cursor) { return this->modulesRuleRegularValueOne_capture(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value", "<group>"));
						choice0 = value_modules_rule_regular_value_one_capture;
						matched0 = true;
						break;
					}
					case Tokens::modules::rule::regular::value::NOSPACE::id: {
						la0_2 = la0_1;
						value_modules_rule_regular_value_one_capture = required<Types::modules::rule::regular::value::one_capture>(la0_2, [this](auto cursor) { return this->modulesRuleRegularValueOne_capture(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value", "<group>"));
						choice0 = value_modules_rule_regular_value_one_capture;
						matched0 = true;
						break;
					}
					case Tokens::modules::rule::regular::value::SPACE::id: {
						la0_2 = la0_1;
						value_modules_rule_regular_value_one_capture = required<Types::modules::rule::regular::value::one_capture>(la0_2, [this](auto cursor) { return this->modulesRuleRegularValueOne_capture(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value", "<group>"));
						choice0 = value_modules_rule_regular_value_one_capture;
						matched0 = true;
						break;
					}
					case Tokens::modules::rule::regular::value::STRING::id: {
						la0_2 = la0_1;
						value_modules_rule_regular_value_one_capture = required<Types::modules::rule::regular::value::one_capture>(la0_2, [this](auto cursor) { return this->modulesRuleRegularValueOne_capture(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value", "<group>"));
						choice0 = value_modules_rule_regular_value_one_capture;
						matched0 = true;
						break;
					}
					case Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id: {
						la0_2 = la0_1;
						value_modules_rule_regular_value_one_capture = required<Types::modules::rule::regular::value::one_capture>(la0_2, [this](auto cursor) { return this->modulesRuleRegularValueOne_capture(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value", "<group>"));
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
				value_modules_rule_regular_value_one_capture = required<Types::modules::rule::regular::value::one_capture>(la0_1, [this](auto cursor) { return this->modulesRuleRegularValueOne_capture(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value", "<group>"));
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
						value_modules_rule_regular_value_mul_capture = required<Types::modules::rule::regular::value::mul_capture>(la0_2, [this](auto cursor) { return this->modulesRuleRegularValueMul_capture(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value", "<group>"));
						choice0 = value_modules_rule_regular_value_mul_capture;
						matched0 = true;
						break;
					}
					case Tokens::LEFT_PARENTHESIS::id: {
						la0_2 = la0_1;
						value_modules_rule_regular_value_one_capture = required<Types::modules::rule::regular::value::one_capture>(la0_2, [this](auto cursor) { return this->modulesRuleRegularValueOne_capture(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value", "<group>"));
						choice0 = value_modules_rule_regular_value_one_capture;
						matched0 = true;
						break;
					}
					case Tokens::modules::common::ID::id: {
						la0_2 = la0_1;
						value_modules_rule_regular_value_one_capture = required<Types::modules::rule::regular::value::one_capture>(la0_2, [this](auto cursor) { return this->modulesRuleRegularValueOne_capture(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value", "<group>"));
						choice0 = value_modules_rule_regular_value_one_capture;
						matched0 = true;
						break;
					}
					case Tokens::modules::rule::regular::value::ANY::id: {
						la0_2 = la0_1;
						value_modules_rule_regular_value_one_capture = required<Types::modules::rule::regular::value::one_capture>(la0_2, [this](auto cursor) { return this->modulesRuleRegularValueOne_capture(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value", "<group>"));
						choice0 = value_modules_rule_regular_value_one_capture;
						matched0 = true;
						break;
					}
					case Tokens::modules::rule::regular::value::CGROUP::id: {
						la0_2 = la0_1;
						value_modules_rule_regular_value_one_capture = required<Types::modules::rule::regular::value::one_capture>(la0_2, [this](auto cursor) { return this->modulesRuleRegularValueOne_capture(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value", "<group>"));
						choice0 = value_modules_rule_regular_value_one_capture;
						matched0 = true;
						break;
					}
					case Tokens::modules::rule::regular::value::NOSPACE::id: {
						la0_2 = la0_1;
						value_modules_rule_regular_value_one_capture = required<Types::modules::rule::regular::value::one_capture>(la0_2, [this](auto cursor) { return this->modulesRuleRegularValueOne_capture(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value", "<group>"));
						choice0 = value_modules_rule_regular_value_one_capture;
						matched0 = true;
						break;
					}
					case Tokens::modules::rule::regular::value::SPACE::id: {
						la0_2 = la0_1;
						value_modules_rule_regular_value_one_capture = required<Types::modules::rule::regular::value::one_capture>(la0_2, [this](auto cursor) { return this->modulesRuleRegularValueOne_capture(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value", "<group>"));
						choice0 = value_modules_rule_regular_value_one_capture;
						matched0 = true;
						break;
					}
					case Tokens::modules::rule::regular::value::STRING::id: {
						la0_2 = la0_1;
						value_modules_rule_regular_value_one_capture = required<Types::modules::rule::regular::value::one_capture>(la0_2, [this](auto cursor) { return this->modulesRuleRegularValueOne_capture(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value", "<group>"));
						choice0 = value_modules_rule_regular_value_one_capture;
						matched0 = true;
						break;
					}
					case Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id: {
						la0_2 = la0_1;
						value_modules_rule_regular_value_one_capture = required<Types::modules::rule::regular::value::one_capture>(la0_2, [this](auto cursor) { return this->modulesRuleRegularValueOne_capture(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value", "<group>"));
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
				value_modules_rule_regular_value_one_capture = required<Types::modules::rule::regular::value::one_capture>(la0_1, [this](auto cursor) { return this->modulesRuleRegularValueOne_capture(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value", "<group>"));
				choice0 = value_modules_rule_regular_value_one_capture;
				matched0 = true;
				break;
			}
			case Tokens::modules::rule::regular::value::ANY::id: {
				value_modules_rule_regular_value_one_capture = required<Types::modules::rule::regular::value::one_capture>(la0_1, [this](auto cursor) { return this->modulesRuleRegularValueOne_capture(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value", "<group>"));
				choice0 = value_modules_rule_regular_value_one_capture;
				matched0 = true;
				break;
			}
			case Tokens::modules::rule::regular::value::CGROUP::id: {
				value_modules_rule_regular_value_one_capture = required<Types::modules::rule::regular::value::one_capture>(la0_1, [this](auto cursor) { return this->modulesRuleRegularValueOne_capture(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value", "<group>"));
				choice0 = value_modules_rule_regular_value_one_capture;
				matched0 = true;
				break;
			}
			case Tokens::modules::rule::regular::value::NOSPACE::id: {
				value_modules_rule_regular_value_one_capture = required<Types::modules::rule::regular::value::one_capture>(la0_1, [this](auto cursor) { return this->modulesRuleRegularValueOne_capture(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value", "<group>"));
				choice0 = value_modules_rule_regular_value_one_capture;
				matched0 = true;
				break;
			}
			case Tokens::modules::rule::regular::value::SPACE::id: {
				value_modules_rule_regular_value_one_capture = required<Types::modules::rule::regular::value::one_capture>(la0_1, [this](auto cursor) { return this->modulesRuleRegularValueOne_capture(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value", "<group>"));
				choice0 = value_modules_rule_regular_value_one_capture;
				matched0 = true;
				break;
			}
			case Tokens::modules::rule::regular::value::STRING::id: {
				value_modules_rule_regular_value_one_capture = required<Types::modules::rule::regular::value::one_capture>(la0_1, [this](auto cursor) { return this->modulesRuleRegularValueOne_capture(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value", "<group>"));
				choice0 = value_modules_rule_regular_value_one_capture;
				matched0 = true;
				break;
			}
			case Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id: {
				value_modules_rule_regular_value_one_capture = required<Types::modules::rule::regular::value::one_capture>(la0_1, [this](auto cursor) { return this->modulesRuleRegularValueOne_capture(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value", "<group>"));
				choice0 = value_modules_rule_regular_value_one_capture;
				matched0 = true;
				break;
			}
		}
		pos = la0_1;
		if (!matched0) {
			switch (recover_choice<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::COMMERCIAL_AT::id, Tokens::PERCENT_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>>(pos, "modules::rule::regular::value", "AMPERSAND, COMMERCIAL_AT, LEFT_PARENTHESIS, PERCENT_SIGN, modules::common::ID, modules::rule::regular::value::ANY, modules::rule::regular::value::CGROUP, modules::rule::regular::value::NOSPACE, modules::rule::regular::value::SPACE, modules::rule::regular::value::STRING, modules::rule::regular::value::dyn::DOLLAR_SIGN, COMMERCIAL_AT, PERCENT_SIGN")) {
				case 0: {
					value_modules_rule_regular_value_one_capture = required<Types::modules::rule::regular::value::one_capture>(pos, [this](auto cursor) { return this->modulesRuleRegularValueOne_capture(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value", "<group>"));
					choice0 = value_modules_rule_regular_value_one_capture;
					matched0 = true;
					break;
				}
				case 1: {
					value_modules_rule_regular_value_mul_capture = required<Types::modules::rule::regular::value::mul_capture>(pos, [this](auto cursor) { return this->modulesRuleRegularValueMul_capture(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::value", "<group>"));
					choice0 = value_modules_rule_regular_value_mul_capture;
					matched0 = true;
					break;
				}
			}
		}
		if (!matched0) {
			return {};
		}
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
	auto recovery_scope = recovery_frame("modules::grammar::grammar");
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::modules::grammar::modifier::AUTO::id, Tokens::modules::grammar::modifier::MOD::id, Tokens::modules::grammar::modifier::RIGHT_SQUARE_BRACKET::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::COMMA::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_PARENTHESIS::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::modules::common::ID::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COLON::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::forward_declaration::cls::CLASS::id, Tokens::modules::forward_declaration::cls::class_method::METHOD::id, Tokens::modules::forward_declaration::cls::class_property::PROPERTY::id, Tokens::modules::forward_declaration::fun::FN::id, Tokens::modules::grammar::modifier::AUTO::id, Tokens::modules::grammar::modifier::MOD::id, Tokens::modules::grammar::modifier::RIGHT_SQUARE_BRACKET::id, Tokens::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::unpack::AUTO::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>>("modules::grammar::modifier", "modules::grammar::modifier", "__WS", "modules::common::name", "__WS", "<group>");
		value_list_modules_grammar_modifier = range_optional<Types::modules::grammar::modifier, Types::__WS>(pos, [this](auto cursor) { return this->modulesGrammarModifier(cursor); });
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::COMMA::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_PARENTHESIS::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::modules::common::ID::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COLON::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::forward_declaration::cls::CLASS::id, Tokens::modules::forward_declaration::cls::class_method::METHOD::id, Tokens::modules::forward_declaration::cls::class_property::PROPERTY::id, Tokens::modules::forward_declaration::fun::FN::id, Tokens::modules::grammar::modifier::AUTO::id, Tokens::modules::grammar::modifier::MOD::id, Tokens::modules::grammar::modifier::RIGHT_SQUARE_BRACKET::id, Tokens::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::unpack::AUTO::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>>("__WS", "__WS", "modules::common::name", "__WS", "<group>");
		skip_spaces<Types::__WS>(pos);
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::COMMA::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_PARENTHESIS::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::modules::common::ID::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COLON::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::forward_declaration::cls::CLASS::id, Tokens::modules::forward_declaration::cls::class_method::METHOD::id, Tokens::modules::forward_declaration::cls::class_property::PROPERTY::id, Tokens::modules::forward_declaration::fun::FN::id, Tokens::modules::grammar::modifier::AUTO::id, Tokens::modules::grammar::modifier::MOD::id, Tokens::modules::grammar::modifier::RIGHT_SQUARE_BRACKET::id, Tokens::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::unpack::AUTO::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>>("modules::common::name", "modules::common::name", "__WS", "<group>");
		value_modules_common_name = required<Types::modules::common::name>(pos, [this](auto cursor) { return this->modulesCommonName(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Tokens<Tokens::COLON::id, Tokens::LEFT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::fail_block::fail_block::FAIL::id, Tokens::modules::grammar::modifier::AUTO::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COLON::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::forward_declaration::cls::CLASS::id, Tokens::modules::forward_declaration::cls::class_method::METHOD::id, Tokens::modules::forward_declaration::cls::class_property::PROPERTY::id, Tokens::modules::forward_declaration::fun::FN::id, Tokens::modules::grammar::modifier::AUTO::id, Tokens::modules::grammar::modifier::MOD::id, Tokens::modules::grammar::modifier::RIGHT_SQUARE_BRACKET::id, Tokens::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::unpack::AUTO::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::grammar::grammar", "modules::common::name"));
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COLON::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::forward_declaration::cls::CLASS::id, Tokens::modules::forward_declaration::cls::class_method::METHOD::id, Tokens::modules::forward_declaration::cls::class_property::PROPERTY::id, Tokens::modules::forward_declaration::fun::FN::id, Tokens::modules::grammar::modifier::AUTO::id, Tokens::modules::grammar::modifier::MOD::id, Tokens::modules::grammar::modifier::RIGHT_SQUARE_BRACKET::id, Tokens::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::unpack::AUTO::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>>("__WS", "__WS", "<group>");
		skip_spaces<Types::__WS>(pos);
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COLON::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::forward_declaration::cls::CLASS::id, Tokens::modules::forward_declaration::cls::class_method::METHOD::id, Tokens::modules::forward_declaration::cls::class_property::PROPERTY::id, Tokens::modules::forward_declaration::fun::FN::id, Tokens::modules::grammar::modifier::AUTO::id, Tokens::modules::grammar::modifier::MOD::id, Tokens::modules::grammar::modifier::RIGHT_SQUARE_BRACKET::id, Tokens::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::unpack::AUTO::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>>("<group>", "<group>");
		// grammar `@  ( modules::rule::regular::regular_rule |  modules::rule::advanced::advanced_rule)`: choice; alternative selected by LL(1) lookahead
		matched0 = false;
		auto la0_1 = pos;
		switch ((*la0_1).kind()) {
			case Tokens::COLON::id: {
				value_modules_rule_regular_regular_rule = required<Types::modules::rule::regular::regular_rule>(la0_1, [this](auto cursor) { return this->modulesRuleRegularRegular_rule(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::COLON::id, Tokens::LEFT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::fail_block::fail_block::FAIL::id, Tokens::modules::grammar::modifier::AUTO::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::fail_block::fail_block::FAIL::id, Tokens::modules::grammar::modifier::AUTO::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COLON::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::forward_declaration::cls::CLASS::id, Tokens::modules::forward_declaration::cls::class_method::METHOD::id, Tokens::modules::forward_declaration::cls::class_property::PROPERTY::id, Tokens::modules::forward_declaration::fun::FN::id, Tokens::modules::grammar::modifier::AUTO::id, Tokens::modules::grammar::modifier::MOD::id, Tokens::modules::grammar::modifier::RIGHT_SQUARE_BRACKET::id, Tokens::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::unpack::AUTO::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::grammar::grammar", "<group>"));
				choice0 = value_modules_rule_regular_regular_rule;
				matched0 = true;
				break;
			}
			case Tokens::LEFT_CURLY_BRACKET::id: {
				value_modules_rule_advanced_advanced_rule = required<Types::modules::rule::advanced::advanced_rule>(la0_1, [this](auto cursor) { return this->modulesRuleAdvancedAdvanced_rule(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::COLON::id, Tokens::LEFT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::fail_block::fail_block::FAIL::id, Tokens::modules::grammar::modifier::AUTO::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::fail_block::fail_block::FAIL::id, Tokens::modules::grammar::modifier::AUTO::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COLON::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::forward_declaration::cls::CLASS::id, Tokens::modules::forward_declaration::cls::class_method::METHOD::id, Tokens::modules::forward_declaration::cls::class_property::PROPERTY::id, Tokens::modules::forward_declaration::fun::FN::id, Tokens::modules::grammar::modifier::AUTO::id, Tokens::modules::grammar::modifier::MOD::id, Tokens::modules::grammar::modifier::RIGHT_SQUARE_BRACKET::id, Tokens::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::unpack::AUTO::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::grammar::grammar", "<group>"));
				choice0 = value_modules_rule_advanced_advanced_rule;
				matched0 = true;
				break;
			}
		}
		pos = la0_1;
		if (!matched0) {
			switch (recover_choice<ISPA_STD::Recovery::Tokens<Tokens::COLON::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COLON::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::forward_declaration::cls::CLASS::id, Tokens::modules::forward_declaration::cls::class_method::METHOD::id, Tokens::modules::forward_declaration::cls::class_property::PROPERTY::id, Tokens::modules::forward_declaration::fun::FN::id, Tokens::modules::grammar::modifier::AUTO::id, Tokens::modules::grammar::modifier::MOD::id, Tokens::modules::grammar::modifier::RIGHT_SQUARE_BRACKET::id, Tokens::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::unpack::AUTO::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::LEFT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COLON::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::forward_declaration::cls::CLASS::id, Tokens::modules::forward_declaration::cls::class_method::METHOD::id, Tokens::modules::forward_declaration::cls::class_property::PROPERTY::id, Tokens::modules::forward_declaration::fun::FN::id, Tokens::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::unpack::AUTO::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>>(pos, "modules::grammar::grammar", "COLON, LEFT_CURLY_BRACKET")) {
				case 0: {
					value_modules_rule_regular_regular_rule = required<Types::modules::rule::regular::regular_rule>(pos, [this](auto cursor) { return this->modulesRuleRegularRegular_rule(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::COLON::id, Tokens::LEFT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::fail_block::fail_block::FAIL::id, Tokens::modules::grammar::modifier::AUTO::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::fail_block::fail_block::FAIL::id, Tokens::modules::grammar::modifier::AUTO::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COLON::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::forward_declaration::cls::CLASS::id, Tokens::modules::forward_declaration::cls::class_method::METHOD::id, Tokens::modules::forward_declaration::cls::class_property::PROPERTY::id, Tokens::modules::forward_declaration::fun::FN::id, Tokens::modules::grammar::modifier::AUTO::id, Tokens::modules::grammar::modifier::MOD::id, Tokens::modules::grammar::modifier::RIGHT_SQUARE_BRACKET::id, Tokens::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::unpack::AUTO::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::grammar::grammar", "<group>"));
					choice0 = value_modules_rule_regular_regular_rule;
					matched0 = true;
					break;
				}
				case 1: {
					value_modules_rule_advanced_advanced_rule = required<Types::modules::rule::advanced::advanced_rule>(pos, [this](auto cursor) { return this->modulesRuleAdvancedAdvanced_rule(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::COLON::id, Tokens::LEFT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::fail_block::fail_block::FAIL::id, Tokens::modules::grammar::modifier::AUTO::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::fail_block::fail_block::FAIL::id, Tokens::modules::grammar::modifier::AUTO::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COLON::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::forward_declaration::cls::CLASS::id, Tokens::modules::forward_declaration::cls::class_method::METHOD::id, Tokens::modules::forward_declaration::cls::class_property::PROPERTY::id, Tokens::modules::forward_declaration::fun::FN::id, Tokens::modules::grammar::modifier::AUTO::id, Tokens::modules::grammar::modifier::MOD::id, Tokens::modules::grammar::modifier::RIGHT_SQUARE_BRACKET::id, Tokens::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::unpack::AUTO::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::grammar::grammar", "<group>"));
					choice0 = value_modules_rule_advanced_advanced_rule;
					matched0 = true;
					break;
				}
			}
		}
		if (!matched0) {
			return {};
		}
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
template<typename IT, class> auto Parser::Parser::modulesForward_declarationFun(IT pos) -> ::ISPA_STD::MatchResult<Types::modules::forward_declaration::fun, IT> {
	::ISPA_STD::Node<Types::modules::forward_declaration::fun::FN> value_modules_forward_declaration_fun_FN;
	::ISPA_STD::Node<Types::modules::forward_declaration::fun_forward> value_modules_forward_declaration_fun_forward;
	auto recovery_scope = recovery_frame("modules::forward_declaration::fun");
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::modules::forward_declaration::fun::FN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::COLON::id, Tokens::COMMA::id, Tokens::LEFT_PARENTHESIS::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::modules::common::ID::id>>("modules::forward_declaration::fun::FN", "modules::forward_declaration::fun::FN", "__WS", "modules::forward_declaration::fun_forward");
		value_modules_forward_declaration_fun_FN = required<Types::modules::forward_declaration::fun::FN>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::modules::forward_declaration::fun::FN::id>, ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id>, ISPA_STD::Recovery::Tokens<Tokens::COLON::id, Tokens::COMMA::id, Tokens::LEFT_PARENTHESIS::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::modules::common::ID::id, Tokens::modules::forward_declaration::fun::FN::id>, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::forward_declaration::fun", "modules::forward_declaration::fun::FN"));
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::COLON::id, Tokens::COMMA::id, Tokens::LEFT_PARENTHESIS::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::modules::common::ID::id>>("__WS", "__WS", "modules::forward_declaration::fun_forward");
		skip_spaces<Types::__WS>(pos);
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::COLON::id, Tokens::COMMA::id, Tokens::LEFT_PARENTHESIS::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::modules::common::ID::id>>("modules::forward_declaration::fun_forward", "modules::forward_declaration::fun_forward");
		value_modules_forward_declaration_fun_forward = required<Types::modules::forward_declaration::fun_forward>(pos, [this](auto cursor) { return this->modulesForward_declarationFun_forward(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id>, ISPA_STD::Recovery::Tokens<Tokens::COLON::id, Tokens::COMMA::id, Tokens::LEFT_PARENTHESIS::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::forward_declaration::fun", "modules::forward_declaration::fun_forward"));
	}
	Types::modules::forward_declaration::fun result;
	::ISPA_STD::assign_compatible(result.value, value_modules_forward_declaration_fun_forward);
	::ISPA_STD::MatchResult<Types::modules::forward_declaration::fun, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::modulesForward_declarationFun<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::modules::forward_declaration::fun, ::Parser::Lexer::iterator>;
template auto Parser::Parser::modulesForward_declarationFun<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::modules::forward_declaration::fun, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::modulesRuleAdvancedAdvanced_ruleDep_decl(IT pos) -> ::ISPA_STD::MatchResult<Types::modules::rule::advanced::advanced_rule::dep_decl, IT> {
	::ISPA_STD::Node<Types::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS> value_modules_rule_advanced_advanced_rule_dep_decl_DEPENDS;
	::ISPA_STD::Node<Types::modules::forward_declaration::fwd> value_modules_forward_declaration_fwd;
	auto recovery_scope = recovery_frame("modules::rule::advanced::advanced_rule::dep_decl");
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::COLON::id, Tokens::COMMA::id, Tokens::LEFT_PARENTHESIS::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::modules::common::ID::id, Tokens::modules::forward_declaration::cls::CLASS::id, Tokens::modules::forward_declaration::cls::class_method::METHOD::id, Tokens::modules::forward_declaration::cls::class_property::PROPERTY::id, Tokens::modules::forward_declaration::fun::FN::id>>("modules::rule::advanced::advanced_rule::dep_decl::DEPENDS", "modules::rule::advanced::advanced_rule::dep_decl::DEPENDS", "__WS", "modules::forward_declaration::fwd");
		value_modules_rule_advanced_advanced_rule_dep_decl_DEPENDS = required<Types::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS::id>, ISPA_STD::Recovery::Tokens<Tokens::modules::forward_declaration::cls::CLASS::id, Tokens::modules::forward_declaration::fun::FN::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id>, ISPA_STD::Recovery::Tokens<Tokens::COLON::id, Tokens::COMMA::id, Tokens::LEFT_PARENTHESIS::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::modules::common::ID::id, Tokens::modules::forward_declaration::cls::CLASS::id, Tokens::modules::forward_declaration::cls::class_method::METHOD::id, Tokens::modules::forward_declaration::cls::class_property::PROPERTY::id, Tokens::modules::forward_declaration::fun::FN::id, Tokens::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS::id>, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::rule::advanced::advanced_rule::dep_decl", "modules::rule::advanced::advanced_rule::dep_decl::DEPENDS"));
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::COLON::id, Tokens::COMMA::id, Tokens::LEFT_PARENTHESIS::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::modules::common::ID::id, Tokens::modules::forward_declaration::cls::CLASS::id, Tokens::modules::forward_declaration::cls::class_method::METHOD::id, Tokens::modules::forward_declaration::cls::class_property::PROPERTY::id, Tokens::modules::forward_declaration::fun::FN::id>>("__WS", "__WS", "modules::forward_declaration::fwd");
		skip_spaces<Types::__WS>(pos);
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::COLON::id, Tokens::COMMA::id, Tokens::LEFT_PARENTHESIS::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::modules::common::ID::id, Tokens::modules::forward_declaration::cls::CLASS::id, Tokens::modules::forward_declaration::cls::class_method::METHOD::id, Tokens::modules::forward_declaration::cls::class_property::PROPERTY::id, Tokens::modules::forward_declaration::fun::FN::id>>("modules::forward_declaration::fwd", "modules::forward_declaration::fwd");
		value_modules_forward_declaration_fwd = required<Types::modules::forward_declaration::fwd>(pos, [this](auto cursor) { return this->modulesForward_declarationFwd(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::modules::forward_declaration::cls::CLASS::id, Tokens::modules::forward_declaration::fun::FN::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id>, ISPA_STD::Recovery::Tokens<Tokens::COLON::id, Tokens::COMMA::id, Tokens::LEFT_PARENTHESIS::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::modules::common::ID::id, Tokens::modules::forward_declaration::cls::CLASS::id, Tokens::modules::forward_declaration::cls::class_method::METHOD::id, Tokens::modules::forward_declaration::cls::class_property::PROPERTY::id, Tokens::modules::forward_declaration::fun::FN::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::advanced::advanced_rule::dep_decl", "modules::forward_declaration::fwd"));
	}
	Types::modules::rule::advanced::advanced_rule::dep_decl result;
	::ISPA_STD::assign_compatible(result.value, value_modules_forward_declaration_fwd);
	::ISPA_STD::MatchResult<Types::modules::rule::advanced::advanced_rule::dep_decl, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::modulesRuleAdvancedAdvanced_ruleDep_decl<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::modules::rule::advanced::advanced_rule::dep_decl, ::Parser::Lexer::iterator>;
template auto Parser::Parser::modulesRuleAdvancedAdvanced_ruleDep_decl<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::modules::rule::advanced::advanced_rule::dep_decl, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::modulesForward_declarationFun_forward(IT pos) -> ::ISPA_STD::MatchResult<Types::modules::forward_declaration::fun_forward, IT> {
	::ISPA_STD::Node<Types::modules::common::ID> value_modules_common_ID;
	::ISPA_STD::Node<Types::LEFT_PARENTHESIS> value_LEFT_PARENTHESIS;
	::ISPA_STD::Node<Types::modules::common::ID> value_modules_common_ID_1;
	::ISPA_STD::Node<Types::COLON> value_COLON;
	::ISPA_STD::Node<Types::modules::common::ID> value_modules_common_ID_2;
	::ISPA_STD::Node<Types::COMMA> value_COMMA;
	std::tuple<::ISPA_STD::Node<Types::modules::common::ID>, ::ISPA_STD::Node<Types::COLON>, ::ISPA_STD::Node<Types::modules::common::ID>, ::ISPA_STD::Node<Types::COMMA>> group0;
	std::vector<std::tuple<::ISPA_STD::Node<Types::modules::common::ID>, ::ISPA_STD::Node<Types::COLON>, ::ISPA_STD::Node<Types::modules::common::ID>, ::ISPA_STD::Node<Types::COMMA>>> group_list1;
	std::vector<::ISPA_STD::Node<Types::modules::common::ID>> capture_list2;
	std::vector<::ISPA_STD::Node<Types::modules::common::ID>> capture_list3;
	::ISPA_STD::Node<Types::RIGHT_PARENTHESIS> value_RIGHT_PARENTHESIS;
	auto recovery_scope = recovery_frame("modules::forward_declaration::fun_forward");
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::LEFT_PARENTHESIS::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::COLON::id, Tokens::COMMA::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_PARENTHESIS::id>>("modules::common::ID", "modules::common::ID", "__WS", "LEFT_PARENTHESIS", "__WS", "<group>", "__WS", "RIGHT_PARENTHESIS");
		value_modules_common_ID = required<Types::modules::common::ID>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Tokens<Tokens::LEFT_PARENTHESIS::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id>, ISPA_STD::Recovery::Tokens<Tokens::COLON::id, Tokens::COMMA::id, Tokens::LEFT_PARENTHESIS::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::forward_declaration::fun_forward", "modules::common::ID"));
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::LEFT_PARENTHESIS::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::COLON::id, Tokens::COMMA::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_PARENTHESIS::id>>("__WS", "__WS", "LEFT_PARENTHESIS", "__WS", "<group>", "__WS", "RIGHT_PARENTHESIS");
		skip_spaces<Types::__WS>(pos);
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::LEFT_PARENTHESIS::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::COLON::id, Tokens::COMMA::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_PARENTHESIS::id>>("LEFT_PARENTHESIS", "LEFT_PARENTHESIS", "__WS", "<group>", "__WS", "RIGHT_PARENTHESIS");
		value_LEFT_PARENTHESIS = required<Types::LEFT_PARENTHESIS>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::LEFT_PARENTHESIS::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_PARENTHESIS::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id>, ISPA_STD::Recovery::Tokens<Tokens::COLON::id, Tokens::COMMA::id, Tokens::LEFT_PARENTHESIS::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::forward_declaration::fun_forward", "LEFT_PARENTHESIS"));
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::COLON::id, Tokens::COMMA::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_PARENTHESIS::id>>("__WS", "__WS", "<group>", "__WS", "RIGHT_PARENTHESIS");
		skip_spaces<Types::__WS>(pos);
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::COLON::id, Tokens::COMMA::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_PARENTHESIS::id>>("<group>", "<group>", "__WS", "RIGHT_PARENTHESIS");
		// grammar ` (@  modules::common::ID  __WS?;  COLON  __WS?; @  modules::common::ID  __WS?;  COMMA)*;`: repeat while lookahead is in FIRST
		while (((*pos).kind() == Tokens::modules::common::ID::id)) {
			value_modules_common_ID_1 = required<Types::modules::common::ID>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_PARENTHESIS::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id>, ISPA_STD::Recovery::Tokens<Tokens::COLON::id, Tokens::COMMA::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::forward_declaration::fun_forward", "<group>"));
			skip_spaces<Types::__WS>(pos);
			value_COLON = required<Types::COLON>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_PARENTHESIS::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id>, ISPA_STD::Recovery::Tokens<Tokens::COLON::id, Tokens::COMMA::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::forward_declaration::fun_forward", "<group>"));
			skip_spaces<Types::__WS>(pos);
			value_modules_common_ID_2 = required<Types::modules::common::ID>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_PARENTHESIS::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id>, ISPA_STD::Recovery::Tokens<Tokens::COLON::id, Tokens::COMMA::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::forward_declaration::fun_forward", "<group>"));
			skip_spaces<Types::__WS>(pos);
			value_COMMA = required<Types::COMMA>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_PARENTHESIS::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id>, ISPA_STD::Recovery::Tokens<Tokens::COLON::id, Tokens::COMMA::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::forward_declaration::fun_forward", "<group>"));
			group0 = std::make_tuple(value_modules_common_ID_1, value_COLON, value_modules_common_ID_2, value_COMMA);
			group_list1.push_back(group0);
			capture_list2.push_back(value_modules_common_ID_1);
			capture_list3.push_back(value_modules_common_ID_2);
			skip_spaces<Types::__WS>(pos);
		}
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_PARENTHESIS::id>>("__WS", "__WS", "RIGHT_PARENTHESIS");
		skip_spaces<Types::__WS>(pos);
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::RIGHT_PARENTHESIS::id>>("RIGHT_PARENTHESIS", "RIGHT_PARENTHESIS");
		value_RIGHT_PARENTHESIS = required<Types::RIGHT_PARENTHESIS>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::RIGHT_PARENTHESIS::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_PARENTHESIS::id>, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::forward_declaration::fun_forward", "RIGHT_PARENTHESIS"));
	}
	Types::modules::forward_declaration::fun_forward result;
	::ISPA_STD::assign_compatible(result.name, value_modules_common_ID);
	::ISPA_STD::assign_compatible(result.param_names, capture_list2);
	::ISPA_STD::assign_compatible(result.param_types, capture_list3);
	::ISPA_STD::MatchResult<Types::modules::forward_declaration::fun_forward, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::modulesForward_declarationFun_forward<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::modules::forward_declaration::fun_forward, ::Parser::Lexer::iterator>;
template auto Parser::Parser::modulesForward_declarationFun_forward<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::modules::forward_declaration::fun_forward, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::modulesCommonParams(IT pos) -> ::ISPA_STD::MatchResult<Types::modules::common::params, IT> {
	::ISPA_STD::Node<Types::GREATER_THAN_SIGN> value_GREATER_THAN_SIGN;
	::ISPA_STD::Node<Types::LEFT_PARENTHESIS> value_LEFT_PARENTHESIS;
	::ISPA_STD::Node<Types::modules::common::param> value_modules_common_param;
	::ISPA_STD::Node<Types::RIGHT_PARENTHESIS> value_RIGHT_PARENTHESIS;
	auto recovery_scope = recovery_frame("modules::common::params");
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::GREATER_THAN_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::LEFT_PARENTHESIS::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::COMMA::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_PARENTHESIS::id>>("GREATER_THAN_SIGN", "GREATER_THAN_SIGN", "__WS", "LEFT_PARENTHESIS", "__WS", "modules::common::param", "__WS", "RIGHT_PARENTHESIS");
		value_GREATER_THAN_SIGN = required<Types::GREATER_THAN_SIGN>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::GREATER_THAN_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::LEFT_PARENTHESIS::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COLON::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::COMMA::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_PARENTHESIS::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::common::params", "GREATER_THAN_SIGN"));
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::LEFT_PARENTHESIS::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::COMMA::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_PARENTHESIS::id>>("__WS", "__WS", "LEFT_PARENTHESIS", "__WS", "modules::common::param", "__WS", "RIGHT_PARENTHESIS");
		skip_spaces<Types::__WS>(pos);
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::LEFT_PARENTHESIS::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::COMMA::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_PARENTHESIS::id>>("LEFT_PARENTHESIS", "LEFT_PARENTHESIS", "__WS", "modules::common::param", "__WS", "RIGHT_PARENTHESIS");
		value_LEFT_PARENTHESIS = required<Types::LEFT_PARENTHESIS>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::LEFT_PARENTHESIS::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_PARENTHESIS::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COLON::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::COMMA::id, Tokens::LEFT_PARENTHESIS::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::common::params", "LEFT_PARENTHESIS"));
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::COMMA::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_PARENTHESIS::id>>("__WS", "__WS", "modules::common::param", "__WS", "RIGHT_PARENTHESIS");
		skip_spaces<Types::__WS>(pos);
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::COMMA::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_PARENTHESIS::id>>("modules::common::param", "modules::common::param", "__WS", "RIGHT_PARENTHESIS");
		value_modules_common_param = optional<Types::modules::common::param>(pos, [this](auto cursor) { return this->modulesCommonParam(cursor); });
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_PARENTHESIS::id>>("__WS", "__WS", "RIGHT_PARENTHESIS");
		skip_spaces<Types::__WS>(pos);
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::RIGHT_PARENTHESIS::id>>("RIGHT_PARENTHESIS", "RIGHT_PARENTHESIS");
		value_RIGHT_PARENTHESIS = required<Types::RIGHT_PARENTHESIS>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::RIGHT_PARENTHESIS::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COLON::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COLON::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_PARENTHESIS::id>, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::common::params", "RIGHT_PARENTHESIS"));
	}
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
	auto recovery_scope = recovery_frame("modules::rule::regular::ast::single_value");
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::LEFT_CURLY_BRACKET::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::COMMERCIAL_AT::id, Tokens::__ISPA_EXTERNAL_54::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id>>("LEFT_CURLY_BRACKET", "LEFT_CURLY_BRACKET", "__WS", "<group>", "__WS", "RIGHT_CURLY_BRACKET");
		value_LEFT_CURLY_BRACKET = required<Types::LEFT_CURLY_BRACKET>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::LEFT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::COMMERCIAL_AT::id, Tokens::__ISPA_EXTERNAL_54::id>, ISPA_STD::Recovery::Tokens<Tokens::PERCENT_SIGN::id, Tokens::SEMICOLON::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::__ISPA_EXTERNAL_54::id>, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::rule::regular::ast::single_value", "LEFT_CURLY_BRACKET"));
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::COMMERCIAL_AT::id, Tokens::__ISPA_EXTERNAL_54::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id>>("__WS", "__WS", "<group>", "__WS", "RIGHT_CURLY_BRACKET");
		skip_spaces<Types::__WS>(pos);
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::COMMERCIAL_AT::id, Tokens::__ISPA_EXTERNAL_54::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id>>("<group>", "<group>", "__WS", "RIGHT_CURLY_BRACKET");
		// grammar `@  ( modules::common::expr |  COMMERCIAL_AT)`: choice; alternative selected by LL(1) lookahead
		matched0 = false;
		auto la0_1 = pos;
		std::size_t external_choice_0_1 = 0;
		if ((*la0_1).kind() == Tokens::COMMERCIAL_AT::id) {
			if (external_choice_0_1) {
				throw std::runtime_error("Ambiguous external parser alternatives");
			}
			external_choice_0_1 = 1;
		}
		if (::ISPA_STD::external_starts<::PyRawParser::Exports::ExpressionBlock>(la0_1)) {
			if (external_choice_0_1) {
				throw std::runtime_error("Ambiguous external parser alternatives");
			}
			external_choice_0_1 = 2;
		}
		switch (external_choice_0_1) {
			case 1: {
				value_COMMERCIAL_AT = required<Types::COMMERCIAL_AT>(la0_1, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::COMMERCIAL_AT::id, Tokens::__ISPA_EXTERNAL_54::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::PERCENT_SIGN::id, Tokens::SEMICOLON::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::COMMERCIAL_AT::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::__ISPA_EXTERNAL_54::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::ast::single_value", "<group>"));
				choice0 = value_COMMERCIAL_AT;
				matched0 = true;
				break;
			}
			case 2: {
				value_modules_common_expr = required<Types::modules::common::expr>(la0_1, [this](auto cursor) { return this->modulesCommonExpr(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::COMMERCIAL_AT::id, Tokens::__ISPA_EXTERNAL_54::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::PERCENT_SIGN::id, Tokens::SEMICOLON::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::COMMERCIAL_AT::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::__ISPA_EXTERNAL_54::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::ast::single_value", "<group>"));
				choice0 = value_modules_common_expr;
				matched0 = true;
				break;
			}
		}
		pos = la0_1;
		if (!matched0) {
			switch (recover_choice<ISPA_STD::Recovery::Tokens<Tokens::__ISPA_EXTERNAL_54::id>, ISPA_STD::Recovery::Tokens<Tokens::__ISPA_EXTERNAL_54::id>, ISPA_STD::Recovery::Tokens<Tokens::COMMERCIAL_AT::id>, ISPA_STD::Recovery::Tokens<Tokens::COMMERCIAL_AT::id>>(pos, "modules::rule::regular::ast::single_value", "__ISPA_EXTERNAL_54, COMMERCIAL_AT")) {
				case 0: {
					value_modules_common_expr = required<Types::modules::common::expr>(pos, [this](auto cursor) { return this->modulesCommonExpr(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::COMMERCIAL_AT::id, Tokens::__ISPA_EXTERNAL_54::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::PERCENT_SIGN::id, Tokens::SEMICOLON::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::COMMERCIAL_AT::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::__ISPA_EXTERNAL_54::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::ast::single_value", "<group>"));
					choice0 = value_modules_common_expr;
					matched0 = true;
					break;
				}
				case 1: {
					value_COMMERCIAL_AT = required<Types::COMMERCIAL_AT>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::COMMERCIAL_AT::id, Tokens::__ISPA_EXTERNAL_54::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::PERCENT_SIGN::id, Tokens::SEMICOLON::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::COMMERCIAL_AT::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::__ISPA_EXTERNAL_54::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::ast::single_value", "<group>"));
					choice0 = value_COMMERCIAL_AT;
					matched0 = true;
					break;
				}
			}
		}
		if (!matched0) {
			return {};
		}
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id>>("__WS", "__WS", "RIGHT_CURLY_BRACKET");
		skip_spaces<Types::__WS>(pos);
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id>>("RIGHT_CURLY_BRACKET", "RIGHT_CURLY_BRACKET");
		value_RIGHT_CURLY_BRACKET = required<Types::RIGHT_CURLY_BRACKET>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::PERCENT_SIGN::id, Tokens::SEMICOLON::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::PERCENT_SIGN::id, Tokens::SEMICOLON::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::rule::regular::ast::single_value", "RIGHT_CURLY_BRACKET"));
	}
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
template<typename IT, class> auto Parser::Parser::modulesForward_declarationClsClass_property(IT pos) -> ::ISPA_STD::MatchResult<Types::modules::forward_declaration::cls::class_property, IT> {
	::ISPA_STD::Node<Types::modules::forward_declaration::cls::class_property::PROPERTY> value_modules_forward_declaration_cls_class_property_PROPERTY;
	::ISPA_STD::Node<Types::modules::common::ID> value_modules_common_ID;
	::ISPA_STD::Node<Types::COLON> value_COLON;
	::ISPA_STD::Node<Types::modules::common::ID> value_modules_common_ID_1;
	auto recovery_scope = recovery_frame("modules::forward_declaration::cls::class_property");
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::modules::forward_declaration::cls::class_property::PROPERTY::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::COLON::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id>>("modules::forward_declaration::cls::class_property::PROPERTY", "modules::forward_declaration::cls::class_property::PROPERTY", "__WS", "modules::common::ID", "__WS", "COLON", "__WS", "modules::common::ID");
		value_modules_forward_declaration_cls_class_property_PROPERTY = required<Types::modules::forward_declaration::cls::class_property::PROPERTY>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::modules::forward_declaration::cls::class_property::PROPERTY::id>, ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id>, ISPA_STD::Recovery::Tokens<Tokens::COLON::id, Tokens::modules::common::ID::id, Tokens::modules::forward_declaration::cls::class_property::PROPERTY::id>, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::forward_declaration::cls::class_property", "modules::forward_declaration::cls::class_property::PROPERTY"));
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::COLON::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id>>("__WS", "__WS", "modules::common::ID", "__WS", "COLON", "__WS", "modules::common::ID");
		skip_spaces<Types::__WS>(pos);
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::COLON::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id>>("modules::common::ID", "modules::common::ID", "__WS", "COLON", "__WS", "modules::common::ID");
		value_modules_common_ID = required<Types::modules::common::ID>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Tokens<Tokens::COLON::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id>, ISPA_STD::Recovery::Tokens<Tokens::COLON::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::forward_declaration::cls::class_property", "modules::common::ID"));
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::COLON::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id>>("__WS", "__WS", "COLON", "__WS", "modules::common::ID");
		skip_spaces<Types::__WS>(pos);
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::COLON::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id>>("COLON", "COLON", "__WS", "modules::common::ID");
		value_COLON = required<Types::COLON>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::COLON::id>, ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id>, ISPA_STD::Recovery::Tokens<Tokens::COLON::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::forward_declaration::cls::class_property", "COLON"));
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id>>("__WS", "__WS", "modules::common::ID");
		skip_spaces<Types::__WS>(pos);
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id>>("modules::common::ID", "modules::common::ID");
		value_modules_common_ID_1 = required<Types::modules::common::ID>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id>, ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::forward_declaration::cls::class_property", "modules::common::ID"));
	}
	Types::modules::forward_declaration::cls::class_property result;
	::ISPA_STD::assign_compatible(result.name, value_modules_common_ID);
	::ISPA_STD::assign_compatible(result.type, value_modules_common_ID_1);
	::ISPA_STD::MatchResult<Types::modules::forward_declaration::cls::class_property, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::modulesForward_declarationClsClass_property<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::modules::forward_declaration::cls::class_property, ::Parser::Lexer::iterator>;
template auto Parser::Parser::modulesForward_declarationClsClass_property<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::modules::forward_declaration::cls::class_property, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::modulesRuleAdvancedAdvanced_ruleRegular_match(IT pos) -> ::ISPA_STD::MatchResult<Types::modules::rule::advanced::advanced_rule::regular_match, IT> {
	::ISPA_STD::Node<Types::modules::rule::advanced::advanced_rule::regular_match::MATCH> value_modules_rule_advanced_advanced_rule_regular_match_MATCH;
	std::vector<::ISPA_STD::Node<Types::modules::rule::regular::value>> value_list_modules_rule_regular_value;
	::ISPA_STD::Node<Types::SEMICOLON> value_SEMICOLON;
	::ISPA_STD::Node<Types::modules::rule::advanced::advanced_rule::regular_match::unpack> value_modules_rule_advanced_advanced_rule_regular_match_unpack;
	auto recovery_scope = recovery_frame("modules::rule::advanced::advanced_rule::regular_match");
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::SEMICOLON::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::unpack::AUTO::id>>("modules::rule::advanced::advanced_rule::regular_match::MATCH", "modules::rule::advanced::advanced_rule::regular_match::MATCH", "__WS", "modules::rule::regular::value", "__WS", "SEMICOLON", "__WS", "modules::rule::advanced::advanced_rule::regular_match::unpack");
		value_modules_rule_advanced_advanced_rule_regular_match_MATCH = required<Types::modules::rule::advanced::advanced_rule::regular_match::MATCH>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::unpack::AUTO::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::rule::advanced::advanced_rule::regular_match", "modules::rule::advanced::advanced_rule::regular_match::MATCH"));
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::SEMICOLON::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::unpack::AUTO::id>>("__WS", "__WS", "modules::rule::regular::value", "__WS", "SEMICOLON", "__WS", "modules::rule::advanced::advanced_rule::regular_match::unpack");
		skip_spaces<Types::__WS>(pos);
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::SEMICOLON::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::unpack::AUTO::id>>("modules::rule::regular::value", "modules::rule::regular::value", "__WS", "SEMICOLON", "__WS", "modules::rule::advanced::advanced_rule::regular_match::unpack");
		value_list_modules_rule_regular_value = range<Types::modules::rule::regular::value, Types::__WS>(pos, [this](auto cursor) { return this->modulesRuleRegularValue(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::SEMICOLON::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::unpack::AUTO::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::advanced::advanced_rule::regular_match", "modules::rule::regular::value"));
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::SEMICOLON::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::unpack::AUTO::id>>("__WS", "__WS", "SEMICOLON", "__WS", "modules::rule::advanced::advanced_rule::regular_match::unpack");
		skip_spaces<Types::__WS>(pos);
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::SEMICOLON::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::unpack::AUTO::id>>("SEMICOLON", "SEMICOLON", "__WS", "modules::rule::advanced::advanced_rule::regular_match::unpack");
		value_SEMICOLON = required<Types::SEMICOLON>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::SEMICOLON::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::unpack::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id>, ISPA_STD::Recovery::Tokens<Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::unpack::AUTO::id>, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::rule::advanced::advanced_rule::regular_match", "SEMICOLON"));
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::unpack::AUTO::id>>("__WS", "__WS", "modules::rule::advanced::advanced_rule::regular_match::unpack");
		skip_spaces<Types::__WS>(pos);
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::unpack::AUTO::id>>("modules::rule::advanced::advanced_rule::regular_match::unpack", "modules::rule::advanced::advanced_rule::regular_match::unpack");
		value_modules_rule_advanced_advanced_rule_regular_match_unpack = optional<Types::modules::rule::advanced::advanced_rule::regular_match::unpack>(pos, [this](auto cursor) { return this->modulesRuleAdvancedAdvanced_ruleRegular_matchUnpack(cursor); });
	}
	Types::modules::rule::advanced::advanced_rule::regular_match result;
	::ISPA_STD::assign_compatible(result.patterns, value_list_modules_rule_regular_value);
	::ISPA_STD::assign_compatible(result.assign_names, value_modules_rule_advanced_advanced_rule_regular_match_unpack);
	::ISPA_STD::MatchResult<Types::modules::rule::advanced::advanced_rule::regular_match, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::modulesRuleAdvancedAdvanced_ruleRegular_match<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::modules::rule::advanced::advanced_rule::regular_match, ::Parser::Lexer::iterator>;
template auto Parser::Parser::modulesRuleAdvancedAdvanced_ruleRegular_match<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::modules::rule::advanced::advanced_rule::regular_match, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::modulesForward_declarationClsClass_method(IT pos) -> ::ISPA_STD::MatchResult<Types::modules::forward_declaration::cls::class_method, IT> {
	::ISPA_STD::Node<Types::modules::forward_declaration::cls::class_method::METHOD> value_modules_forward_declaration_cls_class_method_METHOD;
	::ISPA_STD::Node<Types::modules::forward_declaration::fun_forward> value_modules_forward_declaration_fun_forward;
	auto recovery_scope = recovery_frame("modules::forward_declaration::cls::class_method");
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::modules::forward_declaration::cls::class_method::METHOD::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::COLON::id, Tokens::COMMA::id, Tokens::LEFT_PARENTHESIS::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::modules::common::ID::id>>("modules::forward_declaration::cls::class_method::METHOD", "modules::forward_declaration::cls::class_method::METHOD", "__WS", "modules::forward_declaration::fun_forward");
		value_modules_forward_declaration_cls_class_method_METHOD = required<Types::modules::forward_declaration::cls::class_method::METHOD>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::modules::forward_declaration::cls::class_method::METHOD::id>, ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id>, ISPA_STD::Recovery::Tokens<Tokens::COLON::id, Tokens::COMMA::id, Tokens::LEFT_PARENTHESIS::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::modules::common::ID::id, Tokens::modules::forward_declaration::cls::class_method::METHOD::id>, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::forward_declaration::cls::class_method", "modules::forward_declaration::cls::class_method::METHOD"));
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::COLON::id, Tokens::COMMA::id, Tokens::LEFT_PARENTHESIS::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::modules::common::ID::id>>("__WS", "__WS", "modules::forward_declaration::fun_forward");
		skip_spaces<Types::__WS>(pos);
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::COLON::id, Tokens::COMMA::id, Tokens::LEFT_PARENTHESIS::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::modules::common::ID::id>>("modules::forward_declaration::fun_forward", "modules::forward_declaration::fun_forward");
		value_modules_forward_declaration_fun_forward = required<Types::modules::forward_declaration::fun_forward>(pos, [this](auto cursor) { return this->modulesForward_declarationFun_forward(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id>, ISPA_STD::Recovery::Tokens<Tokens::COLON::id, Tokens::COMMA::id, Tokens::LEFT_PARENTHESIS::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::forward_declaration::cls::class_method", "modules::forward_declaration::fun_forward"));
	}
	Types::modules::forward_declaration::cls::class_method result;
	::ISPA_STD::assign_compatible(result.value, value_modules_forward_declaration_fun_forward);
	::ISPA_STD::MatchResult<Types::modules::forward_declaration::cls::class_method, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::modulesForward_declarationClsClass_method<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::modules::forward_declaration::cls::class_method, ::Parser::Lexer::iterator>;
template auto Parser::Parser::modulesForward_declarationClsClass_method<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::modules::forward_declaration::cls::class_method, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::modulesForward_declarationFwd(IT pos) -> ::ISPA_STD::MatchResult<Types::modules::forward_declaration::fwd, IT> {
	std::variant<std::monostate, ::ISPA_STD::Node<Types::modules::forward_declaration::cls>, ::ISPA_STD::Node<Types::modules::forward_declaration::fun>> choice0;
	bool matched0;
	::ISPA_STD::Node<Types::modules::forward_declaration::cls> value_modules_forward_declaration_cls;
	::ISPA_STD::Node<Types::modules::forward_declaration::fun> value_modules_forward_declaration_fun;
	auto recovery_scope = recovery_frame("modules::forward_declaration::fwd");
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::COLON::id, Tokens::COMMA::id, Tokens::LEFT_PARENTHESIS::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::modules::common::ID::id, Tokens::modules::forward_declaration::cls::CLASS::id, Tokens::modules::forward_declaration::cls::class_method::METHOD::id, Tokens::modules::forward_declaration::cls::class_property::PROPERTY::id, Tokens::modules::forward_declaration::fun::FN::id>>("<group>", "<group>");
		// grammar `@  ( modules::forward_declaration::cls |  modules::forward_declaration::fun)`: choice; alternative selected by LL(1) lookahead
		matched0 = false;
		auto la0_1 = pos;
		switch ((*la0_1).kind()) {
			case Tokens::modules::forward_declaration::cls::CLASS::id: {
				value_modules_forward_declaration_cls = required<Types::modules::forward_declaration::cls>(la0_1, [this](auto cursor) { return this->modulesForward_declarationCls(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::modules::forward_declaration::cls::CLASS::id, Tokens::modules::forward_declaration::fun::FN::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id>, ISPA_STD::Recovery::Tokens<Tokens::COLON::id, Tokens::COMMA::id, Tokens::LEFT_PARENTHESIS::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::modules::common::ID::id, Tokens::modules::forward_declaration::cls::CLASS::id, Tokens::modules::forward_declaration::cls::class_method::METHOD::id, Tokens::modules::forward_declaration::cls::class_property::PROPERTY::id, Tokens::modules::forward_declaration::fun::FN::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::forward_declaration::fwd", "<group>"));
				choice0 = value_modules_forward_declaration_cls;
				matched0 = true;
				break;
			}
			case Tokens::modules::forward_declaration::fun::FN::id: {
				value_modules_forward_declaration_fun = required<Types::modules::forward_declaration::fun>(la0_1, [this](auto cursor) { return this->modulesForward_declarationFun(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::modules::forward_declaration::cls::CLASS::id, Tokens::modules::forward_declaration::fun::FN::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id>, ISPA_STD::Recovery::Tokens<Tokens::COLON::id, Tokens::COMMA::id, Tokens::LEFT_PARENTHESIS::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::modules::common::ID::id, Tokens::modules::forward_declaration::cls::CLASS::id, Tokens::modules::forward_declaration::cls::class_method::METHOD::id, Tokens::modules::forward_declaration::cls::class_property::PROPERTY::id, Tokens::modules::forward_declaration::fun::FN::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::forward_declaration::fwd", "<group>"));
				choice0 = value_modules_forward_declaration_fun;
				matched0 = true;
				break;
			}
		}
		pos = la0_1;
		if (!matched0) {
			switch (recover_choice<ISPA_STD::Recovery::Tokens<Tokens::modules::forward_declaration::cls::CLASS::id>, ISPA_STD::Recovery::Tokens<Tokens::COLON::id, Tokens::COMMA::id, Tokens::LEFT_PARENTHESIS::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::modules::common::ID::id, Tokens::modules::forward_declaration::cls::CLASS::id, Tokens::modules::forward_declaration::cls::class_method::METHOD::id, Tokens::modules::forward_declaration::cls::class_property::PROPERTY::id>, ISPA_STD::Recovery::Tokens<Tokens::modules::forward_declaration::fun::FN::id>, ISPA_STD::Recovery::Tokens<Tokens::COLON::id, Tokens::COMMA::id, Tokens::LEFT_PARENTHESIS::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::modules::common::ID::id, Tokens::modules::forward_declaration::fun::FN::id>>(pos, "modules::forward_declaration::fwd", "modules::forward_declaration::cls::CLASS, modules::forward_declaration::fun::FN")) {
				case 0: {
					value_modules_forward_declaration_cls = required<Types::modules::forward_declaration::cls>(pos, [this](auto cursor) { return this->modulesForward_declarationCls(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::modules::forward_declaration::cls::CLASS::id, Tokens::modules::forward_declaration::fun::FN::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id>, ISPA_STD::Recovery::Tokens<Tokens::COLON::id, Tokens::COMMA::id, Tokens::LEFT_PARENTHESIS::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::modules::common::ID::id, Tokens::modules::forward_declaration::cls::CLASS::id, Tokens::modules::forward_declaration::cls::class_method::METHOD::id, Tokens::modules::forward_declaration::cls::class_property::PROPERTY::id, Tokens::modules::forward_declaration::fun::FN::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::forward_declaration::fwd", "<group>"));
					choice0 = value_modules_forward_declaration_cls;
					matched0 = true;
					break;
				}
				case 1: {
					value_modules_forward_declaration_fun = required<Types::modules::forward_declaration::fun>(pos, [this](auto cursor) { return this->modulesForward_declarationFun(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::modules::forward_declaration::cls::CLASS::id, Tokens::modules::forward_declaration::fun::FN::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id>, ISPA_STD::Recovery::Tokens<Tokens::COLON::id, Tokens::COMMA::id, Tokens::LEFT_PARENTHESIS::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::modules::common::ID::id, Tokens::modules::forward_declaration::cls::CLASS::id, Tokens::modules::forward_declaration::cls::class_method::METHOD::id, Tokens::modules::forward_declaration::cls::class_property::PROPERTY::id, Tokens::modules::forward_declaration::fun::FN::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::forward_declaration::fwd", "<group>"));
					choice0 = value_modules_forward_declaration_fun;
					matched0 = true;
					break;
				}
			}
		}
		if (!matched0) {
			return {};
		}
	}
	Types::modules::forward_declaration::fwd result;
	::ISPA_STD::assign_compatible(result.value, choice0);
	::ISPA_STD::MatchResult<Types::modules::forward_declaration::fwd, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::modulesForward_declarationFwd<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::modules::forward_declaration::fwd, ::Parser::Lexer::iterator>;
template auto Parser::Parser::modulesForward_declarationFwd<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::modules::forward_declaration::fwd, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::modulesRuleAdvancedAdvanced_rule(IT pos) -> ::ISPA_STD::MatchResult<Types::modules::rule::advanced::advanced_rule, IT> {
	::ISPA_STD::Node<Types::LEFT_CURLY_BRACKET> value_LEFT_CURLY_BRACKET;
	std::vector<::ISPA_STD::Node<Types::modules::rule::advanced::advanced_rule::dep_decl>> value_list_modules_rule_advanced_advanced_rule_dep_decl;
	std::variant<std::monostate, ::ISPA_STD::Node<Types::modules::rule::advanced::advanced_rule::regular_match>, ::ISPA_STD::Node<Types::modules::common::stmt>> choice0;
	bool matched0;
	::ISPA_STD::Node<Types::modules::rule::advanced::advanced_rule::regular_match> value_modules_rule_advanced_advanced_rule_regular_match;
	::ISPA_STD::Node<Types::modules::common::stmt> value_modules_common_stmt;
	std::vector<std::variant<std::monostate, ::ISPA_STD::Node<Types::modules::rule::advanced::advanced_rule::regular_match>, ::ISPA_STD::Node<Types::modules::common::stmt>>> group_list1;
	::ISPA_STD::Node<Types::RIGHT_CURLY_BRACKET> value_RIGHT_CURLY_BRACKET;
	auto recovery_scope = recovery_frame("modules::rule::advanced::advanced_rule");
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::LEFT_CURLY_BRACKET::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::COLON::id, Tokens::COMMA::id, Tokens::LEFT_PARENTHESIS::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::modules::common::ID::id, Tokens::modules::forward_declaration::cls::CLASS::id, Tokens::modules::forward_declaration::cls::class_method::METHOD::id, Tokens::modules::forward_declaration::cls::class_property::PROPERTY::id, Tokens::modules::forward_declaration::fun::FN::id, Tokens::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::unpack::AUTO::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id>>("LEFT_CURLY_BRACKET", "LEFT_CURLY_BRACKET", "__WS", "modules::rule::advanced::advanced_rule::dep_decl", "__WS", "<group>", "__WS", "RIGHT_CURLY_BRACKET");
		value_LEFT_CURLY_BRACKET = required<Types::LEFT_CURLY_BRACKET>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::LEFT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id>, ISPA_STD::Recovery::Tokens<Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::fail_block::fail_block::FAIL::id, Tokens::modules::grammar::modifier::AUTO::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COLON::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::forward_declaration::cls::CLASS::id, Tokens::modules::forward_declaration::cls::class_method::METHOD::id, Tokens::modules::forward_declaration::cls::class_property::PROPERTY::id, Tokens::modules::forward_declaration::fun::FN::id, Tokens::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::unpack::AUTO::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::rule::advanced::advanced_rule", "LEFT_CURLY_BRACKET"));
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::COLON::id, Tokens::COMMA::id, Tokens::LEFT_PARENTHESIS::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::modules::common::ID::id, Tokens::modules::forward_declaration::cls::CLASS::id, Tokens::modules::forward_declaration::cls::class_method::METHOD::id, Tokens::modules::forward_declaration::cls::class_property::PROPERTY::id, Tokens::modules::forward_declaration::fun::FN::id, Tokens::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::unpack::AUTO::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id>>("__WS", "__WS", "modules::rule::advanced::advanced_rule::dep_decl", "__WS", "<group>", "__WS", "RIGHT_CURLY_BRACKET");
		skip_spaces<Types::__WS>(pos);
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::COLON::id, Tokens::COMMA::id, Tokens::LEFT_PARENTHESIS::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::modules::common::ID::id, Tokens::modules::forward_declaration::cls::CLASS::id, Tokens::modules::forward_declaration::cls::class_method::METHOD::id, Tokens::modules::forward_declaration::cls::class_property::PROPERTY::id, Tokens::modules::forward_declaration::fun::FN::id, Tokens::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::unpack::AUTO::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id>>("modules::rule::advanced::advanced_rule::dep_decl", "modules::rule::advanced::advanced_rule::dep_decl", "__WS", "<group>", "__WS", "RIGHT_CURLY_BRACKET");
		value_list_modules_rule_advanced_advanced_rule_dep_decl = range_optional<Types::modules::rule::advanced::advanced_rule::dep_decl, Types::__WS>(pos, [this](auto cursor) { return this->modulesRuleAdvancedAdvanced_ruleDep_decl(cursor); });
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::unpack::AUTO::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id>>("__WS", "__WS", "<group>", "__WS", "RIGHT_CURLY_BRACKET");
		skip_spaces<Types::__WS>(pos);
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::unpack::AUTO::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id>>("<group>", "<group>", "__WS", "RIGHT_CURLY_BRACKET");
		// grammar `@  ( ( modules::rule::advanced::advanced_rule::regular_match |  modules::common::stmt))*;`: repeat while lookahead is in FIRST
		while ((::ISPA_STD::external_starts<::PyRawParser::Exports::StatementsBlock>(pos) || (*pos).kind() == Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id)) {
			// grammar ` ( modules::rule::advanced::advanced_rule::regular_match |  modules::common::stmt)`: choice; alternative selected by LL(1) lookahead
			matched0 = false;
			auto la0_1 = pos;
			std::size_t external_choice_0_1 = 0;
			if (::ISPA_STD::external_starts<::PyRawParser::Exports::StatementsBlock>(la0_1)) {
				if (external_choice_0_1) {
					throw std::runtime_error("Ambiguous external parser alternatives");
				}
				external_choice_0_1 = 1;
			}
			if ((*la0_1).kind() == Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id) {
				if (external_choice_0_1) {
					throw std::runtime_error("Ambiguous external parser alternatives");
				}
				external_choice_0_1 = 2;
			}
			switch (external_choice_0_1) {
				case 1: {
					value_modules_common_stmt = required<Types::modules::common::stmt>(la0_1, [this](auto cursor) { return this->modulesCommonStmt(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::fail_block::fail_block::FAIL::id, Tokens::modules::grammar::modifier::AUTO::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::unpack::AUTO::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::advanced::advanced_rule", "<group>"));
					choice0 = value_modules_common_stmt;
					matched0 = true;
					break;
				}
				case 2: {
					value_modules_rule_advanced_advanced_rule_regular_match = required<Types::modules::rule::advanced::advanced_rule::regular_match>(la0_1, [this](auto cursor) { return this->modulesRuleAdvancedAdvanced_ruleRegular_match(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::fail_block::fail_block::FAIL::id, Tokens::modules::grammar::modifier::AUTO::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::unpack::AUTO::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::advanced::advanced_rule", "<group>"));
					choice0 = value_modules_rule_advanced_advanced_rule_regular_match;
					matched0 = true;
					break;
				}
			}
			pos = la0_1;
			if (!matched0) {
				switch (recover_choice<ISPA_STD::Recovery::Tokens<Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::unpack::AUTO::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::__ISPA_EXTERNAL_56::id>, ISPA_STD::Recovery::Tokens<Tokens::__ISPA_EXTERNAL_56::id>>(pos, "modules::rule::advanced::advanced_rule", "modules::rule::advanced::advanced_rule::regular_match::MATCH, __ISPA_EXTERNAL_56")) {
					case 0: {
						value_modules_rule_advanced_advanced_rule_regular_match = required<Types::modules::rule::advanced::advanced_rule::regular_match>(pos, [this](auto cursor) { return this->modulesRuleAdvancedAdvanced_ruleRegular_match(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::fail_block::fail_block::FAIL::id, Tokens::modules::grammar::modifier::AUTO::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::unpack::AUTO::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::advanced::advanced_rule", "<group>"));
						choice0 = value_modules_rule_advanced_advanced_rule_regular_match;
						matched0 = true;
						break;
					}
					case 1: {
						value_modules_common_stmt = required<Types::modules::common::stmt>(pos, [this](auto cursor) { return this->modulesCommonStmt(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::fail_block::fail_block::FAIL::id, Tokens::modules::grammar::modifier::AUTO::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::unpack::AUTO::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::advanced::advanced_rule", "<group>"));
						choice0 = value_modules_common_stmt;
						matched0 = true;
						break;
					}
				}
			}
			if (!matched0) {
				return {};
			}
			group_list1.push_back(choice0);
		}
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id>>("__WS", "__WS", "RIGHT_CURLY_BRACKET");
		skip_spaces<Types::__WS>(pos);
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id>>("RIGHT_CURLY_BRACKET", "RIGHT_CURLY_BRACKET");
		value_RIGHT_CURLY_BRACKET = required<Types::RIGHT_CURLY_BRACKET>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::fail_block::fail_block::FAIL::id, Tokens::modules::grammar::modifier::AUTO::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::fail_block::fail_block::FAIL::id, Tokens::modules::grammar::modifier::AUTO::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::rule::advanced::advanced_rule", "RIGHT_CURLY_BRACKET"));
	}
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
	auto recovery_scope = recovery_frame("modules::fail_block::fail_block");
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::modules::fail_block::fail_block::FAIL::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::COMMA::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_PARENTHESIS::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::modules::common::ID::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::__ISPA_EXTERNAL_56::id>>("modules::fail_block::fail_block::FAIL", "modules::fail_block::fail_block::FAIL", "__WS", "modules::common::name", "__WS", "modules::common::stmt");
		value_modules_fail_block_fail_block_FAIL = required<Types::modules::fail_block::fail_block::FAIL>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::modules::fail_block::fail_block::FAIL::id>, ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id, Tokens::modules::fail_block::fail_block::FAIL::id, Tokens::modules::grammar::modifier::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::COMMA::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_PARENTHESIS::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::common::ID::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::fail_block::fail_block::FAIL::id>, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::fail_block::fail_block", "modules::fail_block::fail_block::FAIL"));
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::COMMA::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_PARENTHESIS::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::modules::common::ID::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::__ISPA_EXTERNAL_56::id>>("__WS", "__WS", "modules::common::name", "__WS", "modules::common::stmt");
		skip_spaces<Types::__WS>(pos);
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::COMMA::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_PARENTHESIS::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::modules::common::ID::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::__ISPA_EXTERNAL_56::id>>("modules::common::name", "modules::common::name", "__WS", "modules::common::stmt");
		value_modules_common_name = required<Types::modules::common::name>(pos, [this](auto cursor) { return this->modulesCommonName(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Tokens<Tokens::__ISPA_EXTERNAL_56::id>, ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id, Tokens::modules::fail_block::fail_block::FAIL::id, Tokens::modules::grammar::modifier::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::COMMA::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_PARENTHESIS::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::common::ID::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::fail_block::fail_block", "modules::common::name"));
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::__ISPA_EXTERNAL_56::id>>("__WS", "__WS", "modules::common::stmt");
		skip_spaces<Types::__WS>(pos);
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::__ISPA_EXTERNAL_56::id>>("modules::common::stmt", "modules::common::stmt");
		value_modules_common_stmt = required<Types::modules::common::stmt>(pos, [this](auto cursor) { return this->modulesCommonStmt(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::__ISPA_EXTERNAL_56::id>, ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id, Tokens::modules::fail_block::fail_block::FAIL::id, Tokens::modules::grammar::modifier::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id, Tokens::modules::fail_block::fail_block::FAIL::id, Tokens::modules::grammar::modifier::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::__ISPA_EXTERNAL_56::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::fail_block::fail_block", "modules::common::stmt"));
	}
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
template<typename IT, class> auto Parser::Parser::modulesCommonTemplate_params(IT pos) -> ::ISPA_STD::MatchResult<Types::modules::common::template_params, IT> {
	::ISPA_STD::Node<Types::modules::common::template_params::LESS_THAN_SIGN> value_modules_common_template_params_LESS_THAN_SIGN;
	::ISPA_STD::Node<Types::modules::common::param> value_modules_common_param;
	::ISPA_STD::Node<Types::GREATER_THAN_SIGN> value_GREATER_THAN_SIGN;
	auto recovery_scope = recovery_frame("modules::common::template_params");
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::modules::common::template_params::LESS_THAN_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::COMMA::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::GREATER_THAN_SIGN::id>>("modules::common::template_params::LESS_THAN_SIGN", "modules::common::template_params::LESS_THAN_SIGN", "__WS", "modules::common::param", "__WS", "GREATER_THAN_SIGN");
		value_modules_common_template_params_LESS_THAN_SIGN = required<Types::modules::common::template_params::LESS_THAN_SIGN>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::modules::common::template_params::LESS_THAN_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::GREATER_THAN_SIGN::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COLON::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::COMMA::id, Tokens::GREATER_THAN_SIGN::id, Tokens::modules::common::ID::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id>, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::common::template_params", "modules::common::template_params::LESS_THAN_SIGN"));
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::COMMA::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::GREATER_THAN_SIGN::id>>("__WS", "__WS", "modules::common::param", "__WS", "GREATER_THAN_SIGN");
		skip_spaces<Types::__WS>(pos);
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::COMMA::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::GREATER_THAN_SIGN::id>>("modules::common::param", "modules::common::param", "__WS", "GREATER_THAN_SIGN");
		value_modules_common_param = optional<Types::modules::common::param>(pos, [this](auto cursor) { return this->modulesCommonParam(cursor); });
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::GREATER_THAN_SIGN::id>>("__WS", "__WS", "GREATER_THAN_SIGN");
		skip_spaces<Types::__WS>(pos);
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::GREATER_THAN_SIGN::id>>("GREATER_THAN_SIGN", "GREATER_THAN_SIGN");
		value_GREATER_THAN_SIGN = required<Types::GREATER_THAN_SIGN>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::GREATER_THAN_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COLON::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COLON::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::GREATER_THAN_SIGN::id>, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::common::template_params", "GREATER_THAN_SIGN"));
	}
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
template<typename IT, class> auto Parser::Parser::modulesForward_declarationCls(IT pos) -> ::ISPA_STD::MatchResult<Types::modules::forward_declaration::cls, IT> {
	::ISPA_STD::Node<Types::modules::forward_declaration::cls::CLASS> value_modules_forward_declaration_cls_CLASS;
	::ISPA_STD::Node<Types::modules::common::ID> value_modules_common_ID;
	::ISPA_STD::Node<Types::COLON> value_COLON;
	std::variant<std::monostate, ::ISPA_STD::Node<Types::modules::forward_declaration::cls::class_method>, ::ISPA_STD::Node<Types::modules::forward_declaration::cls::class_property>> choice0;
	bool matched0;
	::ISPA_STD::Node<Types::modules::forward_declaration::cls::class_method> value_modules_forward_declaration_cls_class_method;
	::ISPA_STD::Node<Types::modules::forward_declaration::cls::class_property> value_modules_forward_declaration_cls_class_property;
	auto recovery_scope = recovery_frame("modules::forward_declaration::cls");
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::modules::forward_declaration::cls::CLASS::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::COLON::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::COLON::id, Tokens::COMMA::id, Tokens::LEFT_PARENTHESIS::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::modules::common::ID::id, Tokens::modules::forward_declaration::cls::class_method::METHOD::id, Tokens::modules::forward_declaration::cls::class_property::PROPERTY::id>>("modules::forward_declaration::cls::CLASS", "modules::forward_declaration::cls::CLASS", "__WS", "modules::common::ID", "__WS", "COLON", "__WS", "<group>");
		value_modules_forward_declaration_cls_CLASS = required<Types::modules::forward_declaration::cls::CLASS>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::modules::forward_declaration::cls::CLASS::id>, ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id>, ISPA_STD::Recovery::Tokens<Tokens::COLON::id, Tokens::COMMA::id, Tokens::LEFT_PARENTHESIS::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::modules::common::ID::id, Tokens::modules::forward_declaration::cls::CLASS::id, Tokens::modules::forward_declaration::cls::class_method::METHOD::id, Tokens::modules::forward_declaration::cls::class_property::PROPERTY::id>, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::forward_declaration::cls", "modules::forward_declaration::cls::CLASS"));
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::COLON::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::COLON::id, Tokens::COMMA::id, Tokens::LEFT_PARENTHESIS::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::modules::common::ID::id, Tokens::modules::forward_declaration::cls::class_method::METHOD::id, Tokens::modules::forward_declaration::cls::class_property::PROPERTY::id>>("__WS", "__WS", "modules::common::ID", "__WS", "COLON", "__WS", "<group>");
		skip_spaces<Types::__WS>(pos);
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::COLON::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::COLON::id, Tokens::COMMA::id, Tokens::LEFT_PARENTHESIS::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::modules::common::ID::id, Tokens::modules::forward_declaration::cls::class_method::METHOD::id, Tokens::modules::forward_declaration::cls::class_property::PROPERTY::id>>("modules::common::ID", "modules::common::ID", "__WS", "COLON", "__WS", "<group>");
		value_modules_common_ID = required<Types::modules::common::ID>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Tokens<Tokens::COLON::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id>, ISPA_STD::Recovery::Tokens<Tokens::COLON::id, Tokens::COMMA::id, Tokens::LEFT_PARENTHESIS::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::modules::common::ID::id, Tokens::modules::forward_declaration::cls::class_method::METHOD::id, Tokens::modules::forward_declaration::cls::class_property::PROPERTY::id>, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::forward_declaration::cls", "modules::common::ID"));
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::COLON::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::COLON::id, Tokens::COMMA::id, Tokens::LEFT_PARENTHESIS::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::modules::common::ID::id, Tokens::modules::forward_declaration::cls::class_method::METHOD::id, Tokens::modules::forward_declaration::cls::class_property::PROPERTY::id>>("__WS", "__WS", "COLON", "__WS", "<group>");
		skip_spaces<Types::__WS>(pos);
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::COLON::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::COLON::id, Tokens::COMMA::id, Tokens::LEFT_PARENTHESIS::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::modules::common::ID::id, Tokens::modules::forward_declaration::cls::class_method::METHOD::id, Tokens::modules::forward_declaration::cls::class_property::PROPERTY::id>>("COLON", "COLON", "__WS", "<group>");
		value_COLON = required<Types::COLON>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::COLON::id>, ISPA_STD::Recovery::Tokens<Tokens::modules::forward_declaration::cls::class_method::METHOD::id, Tokens::modules::forward_declaration::cls::class_property::PROPERTY::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id>, ISPA_STD::Recovery::Tokens<Tokens::COLON::id, Tokens::COMMA::id, Tokens::LEFT_PARENTHESIS::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::modules::common::ID::id, Tokens::modules::forward_declaration::cls::class_method::METHOD::id, Tokens::modules::forward_declaration::cls::class_property::PROPERTY::id>, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::forward_declaration::cls", "COLON"));
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::COLON::id, Tokens::COMMA::id, Tokens::LEFT_PARENTHESIS::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::modules::common::ID::id, Tokens::modules::forward_declaration::cls::class_method::METHOD::id, Tokens::modules::forward_declaration::cls::class_property::PROPERTY::id>>("__WS", "__WS", "<group>");
		skip_spaces<Types::__WS>(pos);
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::COLON::id, Tokens::COMMA::id, Tokens::LEFT_PARENTHESIS::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::modules::common::ID::id, Tokens::modules::forward_declaration::cls::class_method::METHOD::id, Tokens::modules::forward_declaration::cls::class_property::PROPERTY::id>>("<group>", "<group>");
		// grammar `@  ( modules::forward_declaration::cls::class_method |  modules::forward_declaration::cls::class_property)`: choice; alternative selected by LL(1) lookahead
		matched0 = false;
		auto la0_1 = pos;
		switch ((*la0_1).kind()) {
			case Tokens::modules::forward_declaration::cls::class_method::METHOD::id: {
				value_modules_forward_declaration_cls_class_method = required<Types::modules::forward_declaration::cls::class_method>(la0_1, [this](auto cursor) { return this->modulesForward_declarationClsClass_method(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::modules::forward_declaration::cls::class_method::METHOD::id, Tokens::modules::forward_declaration::cls::class_property::PROPERTY::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id>, ISPA_STD::Recovery::Tokens<Tokens::COLON::id, Tokens::COMMA::id, Tokens::LEFT_PARENTHESIS::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::modules::common::ID::id, Tokens::modules::forward_declaration::cls::class_method::METHOD::id, Tokens::modules::forward_declaration::cls::class_property::PROPERTY::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::forward_declaration::cls", "<group>"));
				choice0 = value_modules_forward_declaration_cls_class_method;
				matched0 = true;
				break;
			}
			case Tokens::modules::forward_declaration::cls::class_property::PROPERTY::id: {
				value_modules_forward_declaration_cls_class_property = required<Types::modules::forward_declaration::cls::class_property>(la0_1, [this](auto cursor) { return this->modulesForward_declarationClsClass_property(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::modules::forward_declaration::cls::class_method::METHOD::id, Tokens::modules::forward_declaration::cls::class_property::PROPERTY::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id>, ISPA_STD::Recovery::Tokens<Tokens::COLON::id, Tokens::COMMA::id, Tokens::LEFT_PARENTHESIS::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::modules::common::ID::id, Tokens::modules::forward_declaration::cls::class_method::METHOD::id, Tokens::modules::forward_declaration::cls::class_property::PROPERTY::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::forward_declaration::cls", "<group>"));
				choice0 = value_modules_forward_declaration_cls_class_property;
				matched0 = true;
				break;
			}
		}
		pos = la0_1;
		if (!matched0) {
			switch (recover_choice<ISPA_STD::Recovery::Tokens<Tokens::modules::forward_declaration::cls::class_method::METHOD::id>, ISPA_STD::Recovery::Tokens<Tokens::COLON::id, Tokens::COMMA::id, Tokens::LEFT_PARENTHESIS::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::modules::common::ID::id, Tokens::modules::forward_declaration::cls::class_method::METHOD::id>, ISPA_STD::Recovery::Tokens<Tokens::modules::forward_declaration::cls::class_property::PROPERTY::id>, ISPA_STD::Recovery::Tokens<Tokens::COLON::id, Tokens::modules::common::ID::id, Tokens::modules::forward_declaration::cls::class_property::PROPERTY::id>>(pos, "modules::forward_declaration::cls", "modules::forward_declaration::cls::class_method::METHOD, modules::forward_declaration::cls::class_property::PROPERTY")) {
				case 0: {
					value_modules_forward_declaration_cls_class_method = required<Types::modules::forward_declaration::cls::class_method>(pos, [this](auto cursor) { return this->modulesForward_declarationClsClass_method(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::modules::forward_declaration::cls::class_method::METHOD::id, Tokens::modules::forward_declaration::cls::class_property::PROPERTY::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id>, ISPA_STD::Recovery::Tokens<Tokens::COLON::id, Tokens::COMMA::id, Tokens::LEFT_PARENTHESIS::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::modules::common::ID::id, Tokens::modules::forward_declaration::cls::class_method::METHOD::id, Tokens::modules::forward_declaration::cls::class_property::PROPERTY::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::forward_declaration::cls", "<group>"));
					choice0 = value_modules_forward_declaration_cls_class_method;
					matched0 = true;
					break;
				}
				case 1: {
					value_modules_forward_declaration_cls_class_property = required<Types::modules::forward_declaration::cls::class_property>(pos, [this](auto cursor) { return this->modulesForward_declarationClsClass_property(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::modules::forward_declaration::cls::class_method::METHOD::id, Tokens::modules::forward_declaration::cls::class_property::PROPERTY::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id>, ISPA_STD::Recovery::Tokens<Tokens::COLON::id, Tokens::COMMA::id, Tokens::LEFT_PARENTHESIS::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::modules::common::ID::id, Tokens::modules::forward_declaration::cls::class_method::METHOD::id, Tokens::modules::forward_declaration::cls::class_property::PROPERTY::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::forward_declaration::cls", "<group>"));
					choice0 = value_modules_forward_declaration_cls_class_property;
					matched0 = true;
					break;
				}
			}
		}
		if (!matched0) {
			return {};
		}
	}
	Types::modules::forward_declaration::cls result;
	::ISPA_STD::assign_compatible(result.name, value_modules_common_ID);
	::ISPA_STD::assign_compatible(result.decls, choice0);
	::ISPA_STD::MatchResult<Types::modules::forward_declaration::cls, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::modulesForward_declarationCls<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::modules::forward_declaration::cls, ::Parser::Lexer::iterator>;
template auto Parser::Parser::modulesForward_declarationCls<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::modules::forward_declaration::cls, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::modulesMainMain(IT pos) -> ::ISPA_STD::MatchResult<Types::modules::main::main, IT> {
	std::variant<std::monostate, ::ISPA_STD::Node<Types::modules::grammar::grammar>, ::ISPA_STD::Node<Types::modules::fail_block::fail_block>> choice0;
	bool matched0;
	::ISPA_STD::Node<Types::modules::grammar::grammar> value_modules_grammar_grammar;
	::ISPA_STD::Node<Types::modules::fail_block::fail_block> value_modules_fail_block_fail_block;
	std::vector<std::variant<std::monostate, ::ISPA_STD::Node<Types::modules::grammar::grammar>, ::ISPA_STD::Node<Types::modules::fail_block::fail_block>>> group_list1;
	auto recovery_scope = recovery_frame("modules::main::main");
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COLON::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::fail_block::fail_block::FAIL::id, Tokens::modules::forward_declaration::cls::CLASS::id, Tokens::modules::forward_declaration::cls::class_method::METHOD::id, Tokens::modules::forward_declaration::cls::class_property::PROPERTY::id, Tokens::modules::forward_declaration::fun::FN::id, Tokens::modules::grammar::modifier::AUTO::id, Tokens::modules::grammar::modifier::MOD::id, Tokens::modules::grammar::modifier::RIGHT_SQUARE_BRACKET::id, Tokens::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::unpack::AUTO::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>>("<group>", "<group>");
		// grammar `@  ( ( modules::grammar::grammar |  modules::fail_block::fail_block))*;`: repeat while lookahead is in FIRST
		while (((*pos).kind() == Tokens::modules::common::ID::id || (*pos).kind() == Tokens::modules::fail_block::fail_block::FAIL::id || (*pos).kind() == Tokens::modules::grammar::modifier::AUTO::id)) {
			// grammar ` ( modules::grammar::grammar |  modules::fail_block::fail_block)`: choice; alternative selected by LL(1) lookahead
			matched0 = false;
			auto la0_1 = pos;
			switch ((*la0_1).kind()) {
				case Tokens::modules::common::ID::id: {
					value_modules_grammar_grammar = required<Types::modules::grammar::grammar>(la0_1, [this](auto cursor) { return this->modulesGrammarGrammar(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id, Tokens::modules::fail_block::fail_block::FAIL::id, Tokens::modules::grammar::modifier::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COLON::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::fail_block::fail_block::FAIL::id, Tokens::modules::forward_declaration::cls::CLASS::id, Tokens::modules::forward_declaration::cls::class_method::METHOD::id, Tokens::modules::forward_declaration::cls::class_property::PROPERTY::id, Tokens::modules::forward_declaration::fun::FN::id, Tokens::modules::grammar::modifier::AUTO::id, Tokens::modules::grammar::modifier::MOD::id, Tokens::modules::grammar::modifier::RIGHT_SQUARE_BRACKET::id, Tokens::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::unpack::AUTO::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::main::main", "<group>"));
					choice0 = value_modules_grammar_grammar;
					matched0 = true;
					break;
				}
				case Tokens::modules::fail_block::fail_block::FAIL::id: {
					value_modules_fail_block_fail_block = required<Types::modules::fail_block::fail_block>(la0_1, [this](auto cursor) { return this->modulesFail_blockFail_block(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id, Tokens::modules::fail_block::fail_block::FAIL::id, Tokens::modules::grammar::modifier::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COLON::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::fail_block::fail_block::FAIL::id, Tokens::modules::forward_declaration::cls::CLASS::id, Tokens::modules::forward_declaration::cls::class_method::METHOD::id, Tokens::modules::forward_declaration::cls::class_property::PROPERTY::id, Tokens::modules::forward_declaration::fun::FN::id, Tokens::modules::grammar::modifier::AUTO::id, Tokens::modules::grammar::modifier::MOD::id, Tokens::modules::grammar::modifier::RIGHT_SQUARE_BRACKET::id, Tokens::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::unpack::AUTO::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::main::main", "<group>"));
					choice0 = value_modules_fail_block_fail_block;
					matched0 = true;
					break;
				}
				case Tokens::modules::grammar::modifier::AUTO::id: {
					value_modules_grammar_grammar = required<Types::modules::grammar::grammar>(la0_1, [this](auto cursor) { return this->modulesGrammarGrammar(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id, Tokens::modules::fail_block::fail_block::FAIL::id, Tokens::modules::grammar::modifier::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COLON::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::fail_block::fail_block::FAIL::id, Tokens::modules::forward_declaration::cls::CLASS::id, Tokens::modules::forward_declaration::cls::class_method::METHOD::id, Tokens::modules::forward_declaration::cls::class_property::PROPERTY::id, Tokens::modules::forward_declaration::fun::FN::id, Tokens::modules::grammar::modifier::AUTO::id, Tokens::modules::grammar::modifier::MOD::id, Tokens::modules::grammar::modifier::RIGHT_SQUARE_BRACKET::id, Tokens::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::unpack::AUTO::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::main::main", "<group>"));
					choice0 = value_modules_grammar_grammar;
					matched0 = true;
					break;
				}
			}
			pos = la0_1;
			if (!matched0) {
				switch (recover_choice<ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id, Tokens::modules::grammar::modifier::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COLON::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::forward_declaration::cls::CLASS::id, Tokens::modules::forward_declaration::cls::class_method::METHOD::id, Tokens::modules::forward_declaration::cls::class_property::PROPERTY::id, Tokens::modules::forward_declaration::fun::FN::id, Tokens::modules::grammar::modifier::AUTO::id, Tokens::modules::grammar::modifier::MOD::id, Tokens::modules::grammar::modifier::RIGHT_SQUARE_BRACKET::id, Tokens::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::unpack::AUTO::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::modules::fail_block::fail_block::FAIL::id>, ISPA_STD::Recovery::Tokens<Tokens::COMMA::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_PARENTHESIS::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::common::ID::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::fail_block::fail_block::FAIL::id>>(pos, "modules::main::main", "modules::common::ID, modules::grammar::modifier::AUTO, modules::fail_block::fail_block::FAIL")) {
					case 0: {
						value_modules_grammar_grammar = required<Types::modules::grammar::grammar>(pos, [this](auto cursor) { return this->modulesGrammarGrammar(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id, Tokens::modules::fail_block::fail_block::FAIL::id, Tokens::modules::grammar::modifier::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COLON::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::fail_block::fail_block::FAIL::id, Tokens::modules::forward_declaration::cls::CLASS::id, Tokens::modules::forward_declaration::cls::class_method::METHOD::id, Tokens::modules::forward_declaration::cls::class_property::PROPERTY::id, Tokens::modules::forward_declaration::fun::FN::id, Tokens::modules::grammar::modifier::AUTO::id, Tokens::modules::grammar::modifier::MOD::id, Tokens::modules::grammar::modifier::RIGHT_SQUARE_BRACKET::id, Tokens::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::unpack::AUTO::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::main::main", "<group>"));
						choice0 = value_modules_grammar_grammar;
						matched0 = true;
						break;
					}
					case 1: {
						value_modules_fail_block_fail_block = required<Types::modules::fail_block::fail_block>(pos, [this](auto cursor) { return this->modulesFail_blockFail_block(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id, Tokens::modules::fail_block::fail_block::FAIL::id, Tokens::modules::grammar::modifier::AUTO::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COLON::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::fail_block::fail_block::FAIL::id, Tokens::modules::forward_declaration::cls::CLASS::id, Tokens::modules::forward_declaration::cls::class_method::METHOD::id, Tokens::modules::forward_declaration::cls::class_property::PROPERTY::id, Tokens::modules::forward_declaration::fun::FN::id, Tokens::modules::grammar::modifier::AUTO::id, Tokens::modules::grammar::modifier::MOD::id, Tokens::modules::grammar::modifier::RIGHT_SQUARE_BRACKET::id, Tokens::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::unpack::AUTO::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::main::main", "<group>"));
						choice0 = value_modules_fail_block_fail_block;
						matched0 = true;
						break;
					}
				}
			}
			if (!matched0) {
				return {};
			}
			group_list1.push_back(choice0);
			skip_spaces<Types::__WS>(pos);
		}
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
	::ISPA_STD::Node<Types::modules::common::name::FULL_STOP> value_modules_common_name_FULL_STOP;
	::ISPA_STD::Node<Types::modules::common::ID> value_modules_common_ID_1;
	std::pair<::ISPA_STD::Node<Types::modules::common::name::FULL_STOP>, ::ISPA_STD::Node<Types::modules::common::ID>> group0;
	std::vector<std::pair<::ISPA_STD::Node<Types::modules::common::name::FULL_STOP>, ::ISPA_STD::Node<Types::modules::common::ID>>> group_list1;
	std::vector<::ISPA_STD::Node<Types::modules::common::ID>> capture_list2;
	::ISPA_STD::Node<Types::modules::common::template_params> value_modules_common_template_params;
	::ISPA_STD::Node<Types::modules::common::params> value_modules_common_params;
	auto recovery_scope = recovery_frame("modules::common::name");
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id, Tokens::modules::common::name::FULL_STOP::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::COMMA::id, Tokens::GREATER_THAN_SIGN::id, Tokens::modules::common::ID::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::COMMA::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_PARENTHESIS::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::modules::common::ID::id>>("modules::common::ID", "modules::common::ID", "__WS", "<group>", "__WS", "modules::common::template_params", "__WS", "modules::common::params");
		value_modules_common_ID = required<Types::modules::common::ID>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COLON::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::common::ID::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COLON::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::COMMA::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_PARENTHESIS::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::modules::common::ID::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id>, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::common::name", "modules::common::ID"));
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id, Tokens::modules::common::name::FULL_STOP::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::COMMA::id, Tokens::GREATER_THAN_SIGN::id, Tokens::modules::common::ID::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::COMMA::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_PARENTHESIS::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::modules::common::ID::id>>("__WS", "__WS", "<group>", "__WS", "modules::common::template_params", "__WS", "modules::common::params");
		skip_spaces<Types::__WS>(pos);
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id, Tokens::modules::common::name::FULL_STOP::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::COMMA::id, Tokens::GREATER_THAN_SIGN::id, Tokens::modules::common::ID::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::COMMA::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_PARENTHESIS::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::modules::common::ID::id>>("<group>", "<group>", "__WS", "modules::common::template_params", "__WS", "modules::common::params");
		// grammar ` ( modules::common::name::FULL_STOP  __WS?; @  modules::common::ID)*;`: repeat while lookahead is in FIRST
		while (((*pos).kind() == Tokens::modules::common::name::FULL_STOP::id)) {
			value_modules_common_name_FULL_STOP = required<Types::modules::common::name::FULL_STOP>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::modules::common::name::FULL_STOP::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COLON::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::common::ID::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COLON::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::COMMA::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_PARENTHESIS::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::modules::common::ID::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::common::name", "<group>"));
			skip_spaces<Types::__WS>(pos);
			value_modules_common_ID_1 = required<Types::modules::common::ID>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::modules::common::name::FULL_STOP::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COLON::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::common::ID::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COLON::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::COMMA::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_PARENTHESIS::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::modules::common::ID::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::common::name", "<group>"));
			group0 = std::make_pair(value_modules_common_name_FULL_STOP, value_modules_common_ID_1);
			group_list1.push_back(group0);
			capture_list2.push_back(value_modules_common_ID_1);
			skip_spaces<Types::__WS>(pos);
		}
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::COMMA::id, Tokens::GREATER_THAN_SIGN::id, Tokens::modules::common::ID::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::COMMA::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_PARENTHESIS::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::modules::common::ID::id>>("__WS", "__WS", "modules::common::template_params", "__WS", "modules::common::params");
		skip_spaces<Types::__WS>(pos);
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::COMMA::id, Tokens::GREATER_THAN_SIGN::id, Tokens::modules::common::ID::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::COMMA::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_PARENTHESIS::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::modules::common::ID::id>>("modules::common::template_params", "modules::common::template_params", "__WS", "modules::common::params");
		value_modules_common_template_params = optional<Types::modules::common::template_params>(pos, [this](auto cursor) { return this->modulesCommonTemplate_params(cursor); });
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::COMMA::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_PARENTHESIS::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::modules::common::ID::id>>("__WS", "__WS", "modules::common::params");
		skip_spaces<Types::__WS>(pos);
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::COMMA::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_PARENTHESIS::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::modules::common::ID::id>>("modules::common::params", "modules::common::params");
		value_modules_common_params = optional<Types::modules::common::params>(pos, [this](auto cursor) { return this->modulesCommonParams(cursor); });
	}
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
	auto recovery_scope = recovery_frame("modules::rule::regular::nested_rule");
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COLON::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::forward_declaration::cls::CLASS::id, Tokens::modules::forward_declaration::cls::class_method::METHOD::id, Tokens::modules::forward_declaration::cls::class_property::PROPERTY::id, Tokens::modules::forward_declaration::fun::FN::id, Tokens::modules::grammar::modifier::AUTO::id, Tokens::modules::grammar::modifier::MOD::id, Tokens::modules::grammar::modifier::RIGHT_SQUARE_BRACKET::id, Tokens::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::unpack::AUTO::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>>("modules::rule::regular::nested_rule::NUMBER_SIGN", "modules::rule::regular::nested_rule::NUMBER_SIGN", "modules::grammar::grammar");
		value_modules_rule_regular_nested_rule_NUMBER_SIGN = required<Types::modules::rule::regular::nested_rule::NUMBER_SIGN>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id, Tokens::modules::grammar::modifier::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::SEMICOLON::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COLON::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::forward_declaration::cls::CLASS::id, Tokens::modules::forward_declaration::cls::class_method::METHOD::id, Tokens::modules::forward_declaration::cls::class_property::PROPERTY::id, Tokens::modules::forward_declaration::fun::FN::id, Tokens::modules::grammar::modifier::AUTO::id, Tokens::modules::grammar::modifier::MOD::id, Tokens::modules::grammar::modifier::RIGHT_SQUARE_BRACKET::id, Tokens::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::unpack::AUTO::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::rule::regular::nested_rule", "modules::rule::regular::nested_rule::NUMBER_SIGN"));
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COLON::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::forward_declaration::cls::CLASS::id, Tokens::modules::forward_declaration::cls::class_method::METHOD::id, Tokens::modules::forward_declaration::cls::class_property::PROPERTY::id, Tokens::modules::forward_declaration::fun::FN::id, Tokens::modules::grammar::modifier::AUTO::id, Tokens::modules::grammar::modifier::MOD::id, Tokens::modules::grammar::modifier::RIGHT_SQUARE_BRACKET::id, Tokens::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::unpack::AUTO::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>>("modules::grammar::grammar", "modules::grammar::grammar");
		value_modules_grammar_grammar = required<Types::modules::grammar::grammar>(pos, [this](auto cursor) { return this->modulesGrammarGrammar(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id, Tokens::modules::grammar::modifier::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::SEMICOLON::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::SEMICOLON::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COLON::id, Tokens::COMMA::id, Tokens::COMMERCIAL_AT::id, Tokens::EQUALS_SIGN::id, Tokens::GREATER_THAN_SIGN::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::__ISPA_EXTERNAL_54::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::common::ID::id, Tokens::modules::common::NUMBER::id, Tokens::modules::common::name::FULL_STOP::id, Tokens::modules::common::template_params::LESS_THAN_SIGN::id, Tokens::modules::forward_declaration::cls::CLASS::id, Tokens::modules::forward_declaration::cls::class_method::METHOD::id, Tokens::modules::forward_declaration::cls::class_property::PROPERTY::id, Tokens::modules::forward_declaration::fun::FN::id, Tokens::modules::grammar::modifier::AUTO::id, Tokens::modules::grammar::modifier::MOD::id, Tokens::modules::grammar::modifier::RIGHT_SQUARE_BRACKET::id, Tokens::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::unpack::AUTO::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::QUANTIFIER::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::nested_rule", "modules::grammar::grammar"));
	}
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
	::ISPA_STD::Node<Types::modules::__external::python::symbol_1> value_modules___external_python_symbol_1;
	auto recovery_scope = recovery_frame("modules::common::stmt");
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::__ISPA_EXTERNAL_56::id>>("modules::__external::python::symbol_1", "modules::__external::python::symbol_1");
		value_modules___external_python_symbol_1 = required<Types::modules::__external::python::symbol_1>(pos, [this](auto cursor) { return this->modules__externalPythonSymbol_1(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::__ISPA_EXTERNAL_56::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::common::ID::id, Tokens::modules::fail_block::fail_block::FAIL::id, Tokens::modules::grammar::modifier::AUTO::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id, Tokens::__ISPA_EXTERNAL_56::id, Tokens::modules::common::ID::id, Tokens::modules::fail_block::fail_block::FAIL::id, Tokens::modules::grammar::modifier::AUTO::id, Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id>, ISPA_STD::Recovery::Tokens<Tokens::__ISPA_EXTERNAL_56::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::common::stmt", "modules::__external::python::symbol_1"));
	}
	Types::modules::common::stmt result;
	::ISPA_STD::assign_compatible(result.value, value_modules___external_python_symbol_1);
	::ISPA_STD::MatchResult<Types::modules::common::stmt, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::modulesCommonStmt<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::modules::common::stmt, ::Parser::Lexer::iterator>;
template auto Parser::Parser::modulesCommonStmt<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::modules::common::stmt, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::modulesCommonExpr(IT pos) -> ::ISPA_STD::MatchResult<Types::modules::common::expr, IT> {
	::ISPA_STD::Node<Types::modules::__external::python::symbol_0> value_modules___external_python_symbol_0;
	auto recovery_scope = recovery_frame("modules::common::expr");
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::__ISPA_EXTERNAL_54::id>>("modules::__external::python::symbol_0", "modules::__external::python::symbol_0");
		value_modules___external_python_symbol_0 = required<Types::modules::__external::python::symbol_0>(pos, [this](auto cursor) { return this->modules__externalPythonSymbol_0(cursor); }, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::__ISPA_EXTERNAL_54::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::AMPERSAND::id, Tokens::COMMERCIAL_AT::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::LEFT_PARENTHESIS::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::RIGHT_PARENTHESIS::id, Tokens::SEMICOLON::id, Tokens::modules::common::ID::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id, Tokens::modules::rule::regular::value::ANY::id, Tokens::modules::rule::regular::value::CGROUP::id, Tokens::modules::rule::regular::value::NOSPACE::id, Tokens::modules::rule::regular::value::SPACE::id, Tokens::modules::rule::regular::value::STRING::id, Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id, Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id>, ISPA_STD::Recovery::Tokens<Tokens::__ISPA_EXTERNAL_54::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::common::expr", "modules::__external::python::symbol_0"));
	}
	Types::modules::common::expr result;
	::ISPA_STD::assign_compatible(result.value, value_modules___external_python_symbol_0);
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
	auto recovery_scope = recovery_frame("modules::rule::regular::f_binding");
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::PERCENT_SIGN::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::LEFT_CURLY_BRACKET::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::COMMA::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id>>("PERCENT_SIGN", "PERCENT_SIGN", "__WS", "LEFT_CURLY_BRACKET", "__WS", "modules::common::ID", "__WS", "<group>", "__WS", "RIGHT_CURLY_BRACKET");
		value_PERCENT_SIGN = required<Types::PERCENT_SIGN>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::PERCENT_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::LEFT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::SEMICOLON::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::COMMA::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::PERCENT_SIGN::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::rule::regular::f_binding", "PERCENT_SIGN"));
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::LEFT_CURLY_BRACKET::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::COMMA::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id>>("__WS", "__WS", "LEFT_CURLY_BRACKET", "__WS", "modules::common::ID", "__WS", "<group>", "__WS", "RIGHT_CURLY_BRACKET");
		skip_spaces<Types::__WS>(pos);
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::LEFT_CURLY_BRACKET::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::COMMA::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id>>("LEFT_CURLY_BRACKET", "LEFT_CURLY_BRACKET", "__WS", "modules::common::ID", "__WS", "<group>", "__WS", "RIGHT_CURLY_BRACKET");
		value_LEFT_CURLY_BRACKET = required<Types::LEFT_CURLY_BRACKET>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::LEFT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Tokens<Tokens::SEMICOLON::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::COMMA::id, Tokens::LEFT_CURLY_BRACKET::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::rule::regular::f_binding", "LEFT_CURLY_BRACKET"));
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::COMMA::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id>>("__WS", "__WS", "modules::common::ID", "__WS", "<group>", "__WS", "RIGHT_CURLY_BRACKET");
		skip_spaces<Types::__WS>(pos);
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::COMMA::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id>>("modules::common::ID", "modules::common::ID", "__WS", "<group>", "__WS", "RIGHT_CURLY_BRACKET");
		value_modules_common_ID = required<Types::modules::common::ID>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Tokens<Tokens::COMMA::id, Tokens::RIGHT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::SEMICOLON::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::COMMA::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::rule::regular::f_binding", "modules::common::ID"));
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::COMMA::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id>>("__WS", "__WS", "<group>", "__WS", "RIGHT_CURLY_BRACKET");
		skip_spaces<Types::__WS>(pos);
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::COMMA::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id>>("<group>", "<group>", "__WS", "RIGHT_CURLY_BRACKET");
		// grammar ` ( COMMA  __WS?; @  modules::common::ID)*;`: repeat while lookahead is in FIRST
		while (((*pos).kind() == Tokens::COMMA::id)) {
			value_COMMA = required<Types::COMMA>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::COMMA::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::SEMICOLON::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::COMMA::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::f_binding", "<group>"));
			skip_spaces<Types::__WS>(pos);
			value_modules_common_ID_1 = required<Types::modules::common::ID>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::COMMA::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::SEMICOLON::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::COMMA::id, Tokens::RIGHT_CURLY_BRACKET::id, Tokens::modules::common::ID::id>, ISPA_STD::Recovery::Policy<false, true, false, 32>>("modules::rule::regular::f_binding", "<group>"));
			group0 = std::make_pair(value_COMMA, value_modules_common_ID_1);
			group_list1.push_back(group0);
			capture_list2.push_back(value_modules_common_ID_1);
			skip_spaces<Types::__WS>(pos);
		}
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id>>("__WS", "__WS", "RIGHT_CURLY_BRACKET");
		skip_spaces<Types::__WS>(pos);
	}
	if (!unwinding()) {
		recovery_at<ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id>>("RIGHT_CURLY_BRACKET", "RIGHT_CURLY_BRACKET");
		value_RIGHT_CURLY_BRACKET = required<Types::RIGHT_CURLY_BRACKET>(pos, ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Tokens<Tokens::SEMICOLON::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::SEMICOLON::id, Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id>, ISPA_STD::Recovery::Tokens<Tokens::RIGHT_CURLY_BRACKET::id>, ISPA_STD::Recovery::Policy<true, true, true, 32>>("modules::rule::regular::f_binding", "RIGHT_CURLY_BRACKET"));
	}
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
template<typename IT, class> auto Parser::Parser::modules__externalPythonSymbol_0(IT pos) -> ::ISPA_STD::MatchResult<Types::modules::__external::python::symbol_0, IT> {
	return ::ISPA_STD::external_match<::PyRawParser::Exports::ExpressionBlock>(pos);
}
template auto Parser::Parser::modules__externalPythonSymbol_0<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::modules::__external::python::symbol_0, ::Parser::Lexer::iterator>;
template auto Parser::Parser::modules__externalPythonSymbol_0<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::modules::__external::python::symbol_0, ::Parser::Lexer::lazy_iterator>;
auto Parser::Parser::parseFromTokens() -> void {
	tree = main(Lexer::iterator(lexer)).node.data();
}
auto Parser::Parser::lazyParse() -> void {
	Lexer lexer;
	tree = main(Lexer::lazy_iterator(lexer, text)).node.data();
}

#include "Parser.h"

bool Parser::Exports::symbol_0::starts(const char* origin, const char* start) {
if (!start) return false;
if (!*start) return true;
Lexer lexer; lexer.setInput(origin); const char* p = start;
auto token = lexer.makeToken(p);
while (!token.empty() && token.kind() == Tokens::__WS::id && *p) token = lexer.makeToken(p);
return (!token.empty() && (false || token.kind() == Tokens::modules::common::ID::id || token.kind() == Tokens::modules::fail_block::fail_block::FAIL::id || token.kind() == Tokens::modules::grammar::modifier::AUTO::id)) || true;
}
ISPA_STD::ExternalResult<Parser::Exports::symbol_0::node_type> Parser::Exports::symbol_0::parse(const char* origin, const char* start) {
symbol_0 parser; Lexer lexer; lexer.setExternalBoundary(); Lexer::lazy_iterator it(lexer, origin, start);
parser.template skip_spaces<Types::__WS>(it);
auto node = parser.template optional<node_type>(it, [&parser](auto cursor) { return parser.modulesMainMain(cursor); });
if (node.empty()) return {};
if (!parser.getErrors().empty()) throw std::runtime_error(parser.getErrors().front().message);
const char* end = it.sourcePosition();
return {true, ISPA_STD::external_node(origin, start, end, std::move(node)), end};
}

bool Parser::Exports::symbol_1::starts(const char* origin, const char* start) {
if (!start) return false;
if (!*start) return false;
Lexer lexer; lexer.setInput(origin); const char* p = start;
auto token = lexer.makeToken(p);
while (!token.empty() && token.kind() == Tokens::__WS::id && *p) token = lexer.makeToken(p);
return (!token.empty() && (false || token.kind() == Tokens::LEFT_CURLY_BRACKET::id));
}
ISPA_STD::ExternalResult<Parser::Exports::symbol_1::node_type> Parser::Exports::symbol_1::parse(const char* origin, const char* start) {
symbol_1 parser; Lexer lexer; lexer.setExternalBoundary(); Lexer::lazy_iterator it(lexer, origin, start);
parser.template skip_spaces<Types::__WS>(it);
auto node = parser.template optional<node_type>(it, [&parser](auto cursor) { return parser.modulesRuleAdvancedAdvanced_rule(cursor); });
if (node.empty()) return {};
if (!parser.getErrors().empty()) throw std::runtime_error(parser.getErrors().front().message);
const char* end = it.sourcePosition();
return {true, ISPA_STD::external_node(origin, start, end, std::move(node)), end};
}

bool Parser::Exports::symbol_2::starts(const char* origin, const char* start) {
if (!start) return false;
if (!*start) return false;
Lexer lexer; lexer.setInput(origin); const char* p = start;
auto token = lexer.makeToken(p);
while (!token.empty() && token.kind() == Tokens::__WS::id && *p) token = lexer.makeToken(p);
return (!token.empty() && (false || token.kind() == Tokens::modules::rule::advanced::advanced_rule::dep_decl::DEPENDS::id));
}
ISPA_STD::ExternalResult<Parser::Exports::symbol_2::node_type> Parser::Exports::symbol_2::parse(const char* origin, const char* start) {
symbol_2 parser; Lexer lexer; lexer.setExternalBoundary(); Lexer::lazy_iterator it(lexer, origin, start);
parser.template skip_spaces<Types::__WS>(it);
auto node = parser.template optional<node_type>(it, [&parser](auto cursor) { return parser.modulesRuleAdvancedAdvanced_ruleDep_decl(cursor); });
if (node.empty()) return {};
if (!parser.getErrors().empty()) throw std::runtime_error(parser.getErrors().front().message);
const char* end = it.sourcePosition();
return {true, ISPA_STD::external_node(origin, start, end, std::move(node)), end};
}

bool Parser::Exports::symbol_3::starts(const char* origin, const char* start) {
if (!start) return false;
if (!*start) return false;
Lexer lexer; lexer.setInput(origin); const char* p = start;
auto token = lexer.makeToken(p);
while (!token.empty() && token.kind() == Tokens::__WS::id && *p) token = lexer.makeToken(p);
return (!token.empty() && (false || token.kind() == Tokens::modules::rule::advanced::advanced_rule::regular_match::MATCH::id));
}
ISPA_STD::ExternalResult<Parser::Exports::symbol_3::node_type> Parser::Exports::symbol_3::parse(const char* origin, const char* start) {
symbol_3 parser; Lexer lexer; lexer.setExternalBoundary(); Lexer::lazy_iterator it(lexer, origin, start);
parser.template skip_spaces<Types::__WS>(it);
auto node = parser.template optional<node_type>(it, [&parser](auto cursor) { return parser.modulesRuleAdvancedAdvanced_ruleRegular_match(cursor); });
if (node.empty()) return {};
if (!parser.getErrors().empty()) throw std::runtime_error(parser.getErrors().front().message);
const char* end = it.sourcePosition();
return {true, ISPA_STD::external_node(origin, start, end, std::move(node)), end};
}

bool Parser::Exports::symbol_4::starts(const char* origin, const char* start) {
if (!start) return false;
if (!*start) return false;
Lexer lexer; lexer.setInput(origin); const char* p = start;
auto token = lexer.makeToken(p);
while (!token.empty() && token.kind() == Tokens::__WS::id && *p) token = lexer.makeToken(p);
return (!token.empty() && (false || token.kind() == Tokens::modules::rule::advanced::advanced_rule::regular_match::unpack::AUTO::id));
}
ISPA_STD::ExternalResult<Parser::Exports::symbol_4::node_type> Parser::Exports::symbol_4::parse(const char* origin, const char* start) {
symbol_4 parser; Lexer lexer; lexer.setExternalBoundary(); Lexer::lazy_iterator it(lexer, origin, start);
parser.template skip_spaces<Types::__WS>(it);
auto node = parser.template optional<node_type>(it, [&parser](auto cursor) { return parser.modulesRuleAdvancedAdvanced_ruleRegular_matchUnpack(cursor); });
if (node.empty()) return {};
if (!parser.getErrors().empty()) throw std::runtime_error(parser.getErrors().front().message);
const char* end = it.sourcePosition();
return {true, ISPA_STD::external_node(origin, start, end, std::move(node)), end};
}

bool Parser::Exports::symbol_5::starts(const char* origin, const char* start) {
if (!start) return false;
if (!*start) return false;
Lexer lexer; lexer.setInput(origin); const char* p = start;
auto token = lexer.makeToken(p);
while (!token.empty() && token.kind() == Tokens::__WS::id && *p) token = lexer.makeToken(p);
return (!token.empty() && (false || token.kind() == Tokens::modules::common::ID::id));
}
ISPA_STD::ExternalResult<Parser::Exports::symbol_5::node_type> Parser::Exports::symbol_5::parse(const char* origin, const char* start) {
symbol_5 parser; Lexer lexer; lexer.setExternalBoundary(); Lexer::lazy_iterator it(lexer, origin, start);
parser.template skip_spaces<Types::__WS>(it);
auto node = parser.template optional<node_type>(it);
if (node.empty()) return {};
if (!parser.getErrors().empty()) throw std::runtime_error(parser.getErrors().front().message);
const char* end = it.sourcePosition();
return {true, ISPA_STD::external_node(origin, start, end, std::move(node)), end};
}

bool Parser::Exports::symbol_6::starts(const char* origin, const char* start) {
if (!start) return false;
if (!*start) return false;
Lexer lexer; lexer.setInput(origin); const char* p = start;
auto token = lexer.makeToken(p);
while (!token.empty() && token.kind() == Tokens::__WS::id && *p) token = lexer.makeToken(p);
return (!token.empty() && (false || token.kind() == Tokens::modules::common::NUMBER::id));
}
ISPA_STD::ExternalResult<Parser::Exports::symbol_6::node_type> Parser::Exports::symbol_6::parse(const char* origin, const char* start) {
symbol_6 parser; Lexer lexer; lexer.setExternalBoundary(); Lexer::lazy_iterator it(lexer, origin, start);
parser.template skip_spaces<Types::__WS>(it);
auto node = parser.template optional<node_type>(it);
if (node.empty()) return {};
if (!parser.getErrors().empty()) throw std::runtime_error(parser.getErrors().front().message);
const char* end = it.sourcePosition();
return {true, ISPA_STD::external_node(origin, start, end, std::move(node)), end};
}

bool Parser::Exports::symbol_7::starts(const char* origin, const char* start) {
if (!start) return false;
if (!*start) return false;
Lexer lexer; lexer.setInput(origin); const char* p = start;
auto token = lexer.makeToken(p);
while (!token.empty() && token.kind() == Tokens::__WS::id && *p) token = lexer.makeToken(p);
return (!token.empty() && (false)) || ::PyRawParser::Exports::ExpressionBlock::starts(origin, start);
}
ISPA_STD::ExternalResult<Parser::Exports::symbol_7::node_type> Parser::Exports::symbol_7::parse(const char* origin, const char* start) {
symbol_7 parser; Lexer lexer; lexer.setExternalBoundary(); Lexer::lazy_iterator it(lexer, origin, start);
parser.template skip_spaces<Types::__WS>(it);
auto node = parser.template optional<node_type>(it, [&parser](auto cursor) { return parser.modulesCommonExpr(cursor); });
if (node.empty()) return {};
if (!parser.getErrors().empty()) throw std::runtime_error(parser.getErrors().front().message);
const char* end = it.sourcePosition();
return {true, ISPA_STD::external_node(origin, start, end, std::move(node)), end};
}

bool Parser::Exports::symbol_8::starts(const char* origin, const char* start) {
if (!start) return false;
if (!*start) return false;
Lexer lexer; lexer.setInput(origin); const char* p = start;
auto token = lexer.makeToken(p);
while (!token.empty() && token.kind() == Tokens::__WS::id && *p) token = lexer.makeToken(p);
return (!token.empty() && (false || token.kind() == Tokens::modules::common::ID::id));
}
ISPA_STD::ExternalResult<Parser::Exports::symbol_8::node_type> Parser::Exports::symbol_8::parse(const char* origin, const char* start) {
symbol_8 parser; Lexer lexer; lexer.setExternalBoundary(); Lexer::lazy_iterator it(lexer, origin, start);
parser.template skip_spaces<Types::__WS>(it);
auto node = parser.template optional<node_type>(it, [&parser](auto cursor) { return parser.modulesCommonName(cursor); });
if (node.empty()) return {};
if (!parser.getErrors().empty()) throw std::runtime_error(parser.getErrors().front().message);
const char* end = it.sourcePosition();
return {true, ISPA_STD::external_node(origin, start, end, std::move(node)), end};
}

bool Parser::Exports::symbol_9::starts(const char* origin, const char* start) {
if (!start) return false;
if (!*start) return false;
Lexer lexer; lexer.setInput(origin); const char* p = start;
auto token = lexer.makeToken(p);
while (!token.empty() && token.kind() == Tokens::__WS::id && *p) token = lexer.makeToken(p);
return (!token.empty() && (false || token.kind() == Tokens::modules::common::ID::id));
}
ISPA_STD::ExternalResult<Parser::Exports::symbol_9::node_type> Parser::Exports::symbol_9::parse(const char* origin, const char* start) {
symbol_9 parser; Lexer lexer; lexer.setExternalBoundary(); Lexer::lazy_iterator it(lexer, origin, start);
parser.template skip_spaces<Types::__WS>(it);
auto node = parser.template optional<node_type>(it, [&parser](auto cursor) { return parser.modulesCommonParam(cursor); });
if (node.empty()) return {};
if (!parser.getErrors().empty()) throw std::runtime_error(parser.getErrors().front().message);
const char* end = it.sourcePosition();
return {true, ISPA_STD::external_node(origin, start, end, std::move(node)), end};
}

bool Parser::Exports::symbol_10::starts(const char* origin, const char* start) {
if (!start) return false;
if (!*start) return false;
Lexer lexer; lexer.setInput(origin); const char* p = start;
auto token = lexer.makeToken(p);
while (!token.empty() && token.kind() == Tokens::__WS::id && *p) token = lexer.makeToken(p);
return (!token.empty() && (false || token.kind() == Tokens::GREATER_THAN_SIGN::id));
}
ISPA_STD::ExternalResult<Parser::Exports::symbol_10::node_type> Parser::Exports::symbol_10::parse(const char* origin, const char* start) {
symbol_10 parser; Lexer lexer; lexer.setExternalBoundary(); Lexer::lazy_iterator it(lexer, origin, start);
parser.template skip_spaces<Types::__WS>(it);
auto node = parser.template optional<node_type>(it, [&parser](auto cursor) { return parser.modulesCommonParams(cursor); });
if (node.empty()) return {};
if (!parser.getErrors().empty()) throw std::runtime_error(parser.getErrors().front().message);
const char* end = it.sourcePosition();
return {true, ISPA_STD::external_node(origin, start, end, std::move(node)), end};
}

bool Parser::Exports::symbol_11::starts(const char* origin, const char* start) {
if (!start) return false;
if (!*start) return false;
Lexer lexer; lexer.setInput(origin); const char* p = start;
auto token = lexer.makeToken(p);
while (!token.empty() && token.kind() == Tokens::__WS::id && *p) token = lexer.makeToken(p);
return (!token.empty() && (false)) || ::PyRawParser::Exports::StatementsBlock::starts(origin, start);
}
ISPA_STD::ExternalResult<Parser::Exports::symbol_11::node_type> Parser::Exports::symbol_11::parse(const char* origin, const char* start) {
symbol_11 parser; Lexer lexer; lexer.setExternalBoundary(); Lexer::lazy_iterator it(lexer, origin, start);
parser.template skip_spaces<Types::__WS>(it);
auto node = parser.template optional<node_type>(it, [&parser](auto cursor) { return parser.modulesCommonStmt(cursor); });
if (node.empty()) return {};
if (!parser.getErrors().empty()) throw std::runtime_error(parser.getErrors().front().message);
const char* end = it.sourcePosition();
return {true, ISPA_STD::external_node(origin, start, end, std::move(node)), end};
}

bool Parser::Exports::symbol_12::starts(const char* origin, const char* start) {
if (!start) return false;
if (!*start) return false;
Lexer lexer; lexer.setInput(origin); const char* p = start;
auto token = lexer.makeToken(p);
while (!token.empty() && token.kind() == Tokens::__WS::id && *p) token = lexer.makeToken(p);
return (!token.empty() && (false || token.kind() == Tokens::modules::common::template_params::LESS_THAN_SIGN::id));
}
ISPA_STD::ExternalResult<Parser::Exports::symbol_12::node_type> Parser::Exports::symbol_12::parse(const char* origin, const char* start) {
symbol_12 parser; Lexer lexer; lexer.setExternalBoundary(); Lexer::lazy_iterator it(lexer, origin, start);
parser.template skip_spaces<Types::__WS>(it);
auto node = parser.template optional<node_type>(it, [&parser](auto cursor) { return parser.modulesCommonTemplate_params(cursor); });
if (node.empty()) return {};
if (!parser.getErrors().empty()) throw std::runtime_error(parser.getErrors().front().message);
const char* end = it.sourcePosition();
return {true, ISPA_STD::external_node(origin, start, end, std::move(node)), end};
}

bool Parser::Exports::symbol_13::starts(const char* origin, const char* start) {
if (!start) return false;
if (!*start) return false;
Lexer lexer; lexer.setInput(origin); const char* p = start;
auto token = lexer.makeToken(p);
while (!token.empty() && token.kind() == Tokens::__WS::id && *p) token = lexer.makeToken(p);
return (!token.empty() && (false || token.kind() == Tokens::modules::fail_block::fail_block::FAIL::id));
}
ISPA_STD::ExternalResult<Parser::Exports::symbol_13::node_type> Parser::Exports::symbol_13::parse(const char* origin, const char* start) {
symbol_13 parser; Lexer lexer; lexer.setExternalBoundary(); Lexer::lazy_iterator it(lexer, origin, start);
parser.template skip_spaces<Types::__WS>(it);
auto node = parser.template optional<node_type>(it, [&parser](auto cursor) { return parser.modulesFail_blockFail_block(cursor); });
if (node.empty()) return {};
if (!parser.getErrors().empty()) throw std::runtime_error(parser.getErrors().front().message);
const char* end = it.sourcePosition();
return {true, ISPA_STD::external_node(origin, start, end, std::move(node)), end};
}

bool Parser::Exports::symbol_14::starts(const char* origin, const char* start) {
if (!start) return false;
if (!*start) return false;
Lexer lexer; lexer.setInput(origin); const char* p = start;
auto token = lexer.makeToken(p);
while (!token.empty() && token.kind() == Tokens::__WS::id && *p) token = lexer.makeToken(p);
return (!token.empty() && (false || token.kind() == Tokens::modules::forward_declaration::cls::CLASS::id));
}
ISPA_STD::ExternalResult<Parser::Exports::symbol_14::node_type> Parser::Exports::symbol_14::parse(const char* origin, const char* start) {
symbol_14 parser; Lexer lexer; lexer.setExternalBoundary(); Lexer::lazy_iterator it(lexer, origin, start);
parser.template skip_spaces<Types::__WS>(it);
auto node = parser.template optional<node_type>(it, [&parser](auto cursor) { return parser.modulesForward_declarationCls(cursor); });
if (node.empty()) return {};
if (!parser.getErrors().empty()) throw std::runtime_error(parser.getErrors().front().message);
const char* end = it.sourcePosition();
return {true, ISPA_STD::external_node(origin, start, end, std::move(node)), end};
}

bool Parser::Exports::symbol_15::starts(const char* origin, const char* start) {
if (!start) return false;
if (!*start) return false;
Lexer lexer; lexer.setInput(origin); const char* p = start;
auto token = lexer.makeToken(p);
while (!token.empty() && token.kind() == Tokens::__WS::id && *p) token = lexer.makeToken(p);
return (!token.empty() && (false || token.kind() == Tokens::modules::forward_declaration::cls::class_method::METHOD::id));
}
ISPA_STD::ExternalResult<Parser::Exports::symbol_15::node_type> Parser::Exports::symbol_15::parse(const char* origin, const char* start) {
symbol_15 parser; Lexer lexer; lexer.setExternalBoundary(); Lexer::lazy_iterator it(lexer, origin, start);
parser.template skip_spaces<Types::__WS>(it);
auto node = parser.template optional<node_type>(it, [&parser](auto cursor) { return parser.modulesForward_declarationClsClass_method(cursor); });
if (node.empty()) return {};
if (!parser.getErrors().empty()) throw std::runtime_error(parser.getErrors().front().message);
const char* end = it.sourcePosition();
return {true, ISPA_STD::external_node(origin, start, end, std::move(node)), end};
}

bool Parser::Exports::symbol_16::starts(const char* origin, const char* start) {
if (!start) return false;
if (!*start) return false;
Lexer lexer; lexer.setInput(origin); const char* p = start;
auto token = lexer.makeToken(p);
while (!token.empty() && token.kind() == Tokens::__WS::id && *p) token = lexer.makeToken(p);
return (!token.empty() && (false || token.kind() == Tokens::modules::forward_declaration::cls::class_property::PROPERTY::id));
}
ISPA_STD::ExternalResult<Parser::Exports::symbol_16::node_type> Parser::Exports::symbol_16::parse(const char* origin, const char* start) {
symbol_16 parser; Lexer lexer; lexer.setExternalBoundary(); Lexer::lazy_iterator it(lexer, origin, start);
parser.template skip_spaces<Types::__WS>(it);
auto node = parser.template optional<node_type>(it, [&parser](auto cursor) { return parser.modulesForward_declarationClsClass_property(cursor); });
if (node.empty()) return {};
if (!parser.getErrors().empty()) throw std::runtime_error(parser.getErrors().front().message);
const char* end = it.sourcePosition();
return {true, ISPA_STD::external_node(origin, start, end, std::move(node)), end};
}

bool Parser::Exports::symbol_17::starts(const char* origin, const char* start) {
if (!start) return false;
if (!*start) return false;
Lexer lexer; lexer.setInput(origin); const char* p = start;
auto token = lexer.makeToken(p);
while (!token.empty() && token.kind() == Tokens::__WS::id && *p) token = lexer.makeToken(p);
return (!token.empty() && (false || token.kind() == Tokens::modules::forward_declaration::fun::FN::id));
}
ISPA_STD::ExternalResult<Parser::Exports::symbol_17::node_type> Parser::Exports::symbol_17::parse(const char* origin, const char* start) {
symbol_17 parser; Lexer lexer; lexer.setExternalBoundary(); Lexer::lazy_iterator it(lexer, origin, start);
parser.template skip_spaces<Types::__WS>(it);
auto node = parser.template optional<node_type>(it, [&parser](auto cursor) { return parser.modulesForward_declarationFun(cursor); });
if (node.empty()) return {};
if (!parser.getErrors().empty()) throw std::runtime_error(parser.getErrors().front().message);
const char* end = it.sourcePosition();
return {true, ISPA_STD::external_node(origin, start, end, std::move(node)), end};
}

bool Parser::Exports::symbol_18::starts(const char* origin, const char* start) {
if (!start) return false;
if (!*start) return false;
Lexer lexer; lexer.setInput(origin); const char* p = start;
auto token = lexer.makeToken(p);
while (!token.empty() && token.kind() == Tokens::__WS::id && *p) token = lexer.makeToken(p);
return (!token.empty() && (false || token.kind() == Tokens::modules::common::ID::id));
}
ISPA_STD::ExternalResult<Parser::Exports::symbol_18::node_type> Parser::Exports::symbol_18::parse(const char* origin, const char* start) {
symbol_18 parser; Lexer lexer; lexer.setExternalBoundary(); Lexer::lazy_iterator it(lexer, origin, start);
parser.template skip_spaces<Types::__WS>(it);
auto node = parser.template optional<node_type>(it, [&parser](auto cursor) { return parser.modulesForward_declarationFun_forward(cursor); });
if (node.empty()) return {};
if (!parser.getErrors().empty()) throw std::runtime_error(parser.getErrors().front().message);
const char* end = it.sourcePosition();
return {true, ISPA_STD::external_node(origin, start, end, std::move(node)), end};
}

bool Parser::Exports::symbol_19::starts(const char* origin, const char* start) {
if (!start) return false;
if (!*start) return false;
Lexer lexer; lexer.setInput(origin); const char* p = start;
auto token = lexer.makeToken(p);
while (!token.empty() && token.kind() == Tokens::__WS::id && *p) token = lexer.makeToken(p);
return (!token.empty() && (false || token.kind() == Tokens::modules::forward_declaration::cls::CLASS::id || token.kind() == Tokens::modules::forward_declaration::fun::FN::id));
}
ISPA_STD::ExternalResult<Parser::Exports::symbol_19::node_type> Parser::Exports::symbol_19::parse(const char* origin, const char* start) {
symbol_19 parser; Lexer lexer; lexer.setExternalBoundary(); Lexer::lazy_iterator it(lexer, origin, start);
parser.template skip_spaces<Types::__WS>(it);
auto node = parser.template optional<node_type>(it, [&parser](auto cursor) { return parser.modulesForward_declarationFwd(cursor); });
if (node.empty()) return {};
if (!parser.getErrors().empty()) throw std::runtime_error(parser.getErrors().front().message);
const char* end = it.sourcePosition();
return {true, ISPA_STD::external_node(origin, start, end, std::move(node)), end};
}

bool Parser::Exports::symbol_20::starts(const char* origin, const char* start) {
if (!start) return false;
if (!*start) return false;
Lexer lexer; lexer.setInput(origin); const char* p = start;
auto token = lexer.makeToken(p);
while (!token.empty() && token.kind() == Tokens::__WS::id && *p) token = lexer.makeToken(p);
return (!token.empty() && (false || token.kind() == Tokens::modules::common::ID::id || token.kind() == Tokens::modules::grammar::modifier::AUTO::id));
}
ISPA_STD::ExternalResult<Parser::Exports::symbol_20::node_type> Parser::Exports::symbol_20::parse(const char* origin, const char* start) {
symbol_20 parser; Lexer lexer; lexer.setExternalBoundary(); Lexer::lazy_iterator it(lexer, origin, start);
parser.template skip_spaces<Types::__WS>(it);
auto node = parser.template optional<node_type>(it, [&parser](auto cursor) { return parser.modulesGrammarGrammar(cursor); });
if (node.empty()) return {};
if (!parser.getErrors().empty()) throw std::runtime_error(parser.getErrors().front().message);
const char* end = it.sourcePosition();
return {true, ISPA_STD::external_node(origin, start, end, std::move(node)), end};
}

bool Parser::Exports::symbol_21::starts(const char* origin, const char* start) {
if (!start) return false;
if (!*start) return false;
Lexer lexer; lexer.setInput(origin); const char* p = start;
auto token = lexer.makeToken(p);
while (!token.empty() && token.kind() == Tokens::__WS::id && *p) token = lexer.makeToken(p);
return (!token.empty() && (false || token.kind() == Tokens::modules::grammar::modifier::AUTO::id));
}
ISPA_STD::ExternalResult<Parser::Exports::symbol_21::node_type> Parser::Exports::symbol_21::parse(const char* origin, const char* start) {
symbol_21 parser; Lexer lexer; lexer.setExternalBoundary(); Lexer::lazy_iterator it(lexer, origin, start);
parser.template skip_spaces<Types::__WS>(it);
auto node = parser.template optional<node_type>(it, [&parser](auto cursor) { return parser.modulesGrammarModifier(cursor); });
if (node.empty()) return {};
if (!parser.getErrors().empty()) throw std::runtime_error(parser.getErrors().front().message);
const char* end = it.sourcePosition();
return {true, ISPA_STD::external_node(origin, start, end, std::move(node)), end};
}

bool Parser::Exports::symbol_22::starts(const char* origin, const char* start) {
if (!start) return false;
if (!*start) return false;
Lexer lexer; lexer.setInput(origin); const char* p = start;
auto token = lexer.makeToken(p);
while (!token.empty() && token.kind() == Tokens::__WS::id && *p) token = lexer.makeToken(p);
return (!token.empty() && (false || token.kind() == Tokens::modules::grammar::modifier::MOD::id));
}
ISPA_STD::ExternalResult<Parser::Exports::symbol_22::node_type> Parser::Exports::symbol_22::parse(const char* origin, const char* start) {
symbol_22 parser; Lexer lexer; lexer.setExternalBoundary(); Lexer::lazy_iterator it(lexer, origin, start);
parser.template skip_spaces<Types::__WS>(it);
auto node = parser.template optional<node_type>(it);
if (node.empty()) return {};
if (!parser.getErrors().empty()) throw std::runtime_error(parser.getErrors().front().message);
const char* end = it.sourcePosition();
return {true, ISPA_STD::external_node(origin, start, end, std::move(node)), end};
}

bool Parser::Exports::symbol_23::starts(const char* origin, const char* start) {
if (!start) return false;
if (!*start) return false;
Lexer lexer; lexer.setInput(origin); const char* p = start;
auto token = lexer.makeToken(p);
while (!token.empty() && token.kind() == Tokens::__WS::id && *p) token = lexer.makeToken(p);
return (!token.empty() && (false || token.kind() == Tokens::AMPERSAND::id || token.kind() == Tokens::COMMERCIAL_AT::id || token.kind() == Tokens::LEFT_CURLY_BRACKET::id));
}
ISPA_STD::ExternalResult<Parser::Exports::symbol_23::node_type> Parser::Exports::symbol_23::parse(const char* origin, const char* start) {
symbol_23 parser; Lexer lexer; lexer.setExternalBoundary(); Lexer::lazy_iterator it(lexer, origin, start);
parser.template skip_spaces<Types::__WS>(it);
auto node = parser.template optional<node_type>(it, [&parser](auto cursor) { return parser.modulesRuleRegularAst(cursor); });
if (node.empty()) return {};
if (!parser.getErrors().empty()) throw std::runtime_error(parser.getErrors().front().message);
const char* end = it.sourcePosition();
return {true, ISPA_STD::external_node(origin, start, end, std::move(node)), end};
}

bool Parser::Exports::symbol_24::starts(const char* origin, const char* start) {
if (!start) return false;
if (!*start) return false;
Lexer lexer; lexer.setInput(origin); const char* p = start;
auto token = lexer.makeToken(p);
while (!token.empty() && token.kind() == Tokens::__WS::id && *p) token = lexer.makeToken(p);
return (!token.empty() && (false || token.kind() == Tokens::COMMERCIAL_AT::id));
}
ISPA_STD::ExternalResult<Parser::Exports::symbol_24::node_type> Parser::Exports::symbol_24::parse(const char* origin, const char* start) {
symbol_24 parser; Lexer lexer; lexer.setExternalBoundary(); Lexer::lazy_iterator it(lexer, origin, start);
parser.template skip_spaces<Types::__WS>(it);
auto node = parser.template optional<node_type>(it, [&parser](auto cursor) { return parser.modulesRuleRegularAstAbbr(cursor); });
if (node.empty()) return {};
if (!parser.getErrors().empty()) throw std::runtime_error(parser.getErrors().front().message);
const char* end = it.sourcePosition();
return {true, ISPA_STD::external_node(origin, start, end, std::move(node)), end};
}

bool Parser::Exports::symbol_25::starts(const char* origin, const char* start) {
if (!start) return false;
if (!*start) return false;
Lexer lexer; lexer.setInput(origin); const char* p = start;
auto token = lexer.makeToken(p);
while (!token.empty() && token.kind() == Tokens::__WS::id && *p) token = lexer.makeToken(p);
return (!token.empty() && (false || token.kind() == Tokens::AMPERSAND::id));
}
ISPA_STD::ExternalResult<Parser::Exports::symbol_25::node_type> Parser::Exports::symbol_25::parse(const char* origin, const char* start) {
symbol_25 parser; Lexer lexer; lexer.setExternalBoundary(); Lexer::lazy_iterator it(lexer, origin, start);
parser.template skip_spaces<Types::__WS>(it);
auto node = parser.template optional<node_type>(it, [&parser](auto cursor) { return parser.modulesRuleRegularAstFull(cursor); });
if (node.empty()) return {};
if (!parser.getErrors().empty()) throw std::runtime_error(parser.getErrors().front().message);
const char* end = it.sourcePosition();
return {true, ISPA_STD::external_node(origin, start, end, std::move(node)), end};
}

bool Parser::Exports::symbol_26::starts(const char* origin, const char* start) {
if (!start) return false;
if (!*start) return false;
Lexer lexer; lexer.setInput(origin); const char* p = start;
auto token = lexer.makeToken(p);
while (!token.empty() && token.kind() == Tokens::__WS::id && *p) token = lexer.makeToken(p);
return (!token.empty() && (false || token.kind() == Tokens::modules::common::ID::id));
}
ISPA_STD::ExternalResult<Parser::Exports::symbol_26::node_type> Parser::Exports::symbol_26::parse(const char* origin, const char* start) {
symbol_26 parser; Lexer lexer; lexer.setExternalBoundary(); Lexer::lazy_iterator it(lexer, origin, start);
parser.template skip_spaces<Types::__WS>(it);
auto node = parser.template optional<node_type>(it, [&parser](auto cursor) { return parser.modulesRuleRegularAstFullPart(cursor); });
if (node.empty()) return {};
if (!parser.getErrors().empty()) throw std::runtime_error(parser.getErrors().front().message);
const char* end = it.sourcePosition();
return {true, ISPA_STD::external_node(origin, start, end, std::move(node)), end};
}

bool Parser::Exports::symbol_27::starts(const char* origin, const char* start) {
if (!start) return false;
if (!*start) return false;
Lexer lexer; lexer.setInput(origin); const char* p = start;
auto token = lexer.makeToken(p);
while (!token.empty() && token.kind() == Tokens::__WS::id && *p) token = lexer.makeToken(p);
return (!token.empty() && (false || token.kind() == Tokens::LEFT_CURLY_BRACKET::id));
}
ISPA_STD::ExternalResult<Parser::Exports::symbol_27::node_type> Parser::Exports::symbol_27::parse(const char* origin, const char* start) {
symbol_27 parser; Lexer lexer; lexer.setExternalBoundary(); Lexer::lazy_iterator it(lexer, origin, start);
parser.template skip_spaces<Types::__WS>(it);
auto node = parser.template optional<node_type>(it, [&parser](auto cursor) { return parser.modulesRuleRegularAstSingle_value(cursor); });
if (node.empty()) return {};
if (!parser.getErrors().empty()) throw std::runtime_error(parser.getErrors().front().message);
const char* end = it.sourcePosition();
return {true, ISPA_STD::external_node(origin, start, end, std::move(node)), end};
}

bool Parser::Exports::symbol_28::starts(const char* origin, const char* start) {
if (!start) return false;
if (!*start) return false;
Lexer lexer; lexer.setInput(origin); const char* p = start;
auto token = lexer.makeToken(p);
while (!token.empty() && token.kind() == Tokens::__WS::id && *p) token = lexer.makeToken(p);
return (!token.empty() && (false || token.kind() == Tokens::PERCENT_SIGN::id));
}
ISPA_STD::ExternalResult<Parser::Exports::symbol_28::node_type> Parser::Exports::symbol_28::parse(const char* origin, const char* start) {
symbol_28 parser; Lexer lexer; lexer.setExternalBoundary(); Lexer::lazy_iterator it(lexer, origin, start);
parser.template skip_spaces<Types::__WS>(it);
auto node = parser.template optional<node_type>(it, [&parser](auto cursor) { return parser.modulesRuleRegularF_binding(cursor); });
if (node.empty()) return {};
if (!parser.getErrors().empty()) throw std::runtime_error(parser.getErrors().front().message);
const char* end = it.sourcePosition();
return {true, ISPA_STD::external_node(origin, start, end, std::move(node)), end};
}

bool Parser::Exports::symbol_29::starts(const char* origin, const char* start) {
if (!start) return false;
if (!*start) return false;
Lexer lexer; lexer.setInput(origin); const char* p = start;
auto token = lexer.makeToken(p);
while (!token.empty() && token.kind() == Tokens::__WS::id && *p) token = lexer.makeToken(p);
return (!token.empty() && (false || token.kind() == Tokens::modules::rule::regular::nested_rule::NUMBER_SIGN::id));
}
ISPA_STD::ExternalResult<Parser::Exports::symbol_29::node_type> Parser::Exports::symbol_29::parse(const char* origin, const char* start) {
symbol_29 parser; Lexer lexer; lexer.setExternalBoundary(); Lexer::lazy_iterator it(lexer, origin, start);
parser.template skip_spaces<Types::__WS>(it);
auto node = parser.template optional<node_type>(it, [&parser](auto cursor) { return parser.modulesRuleRegularNested_rule(cursor); });
if (node.empty()) return {};
if (!parser.getErrors().empty()) throw std::runtime_error(parser.getErrors().front().message);
const char* end = it.sourcePosition();
return {true, ISPA_STD::external_node(origin, start, end, std::move(node)), end};
}

bool Parser::Exports::symbol_30::starts(const char* origin, const char* start) {
if (!start) return false;
if (!*start) return false;
Lexer lexer; lexer.setInput(origin); const char* p = start;
auto token = lexer.makeToken(p);
while (!token.empty() && token.kind() == Tokens::__WS::id && *p) token = lexer.makeToken(p);
return (!token.empty() && (false || token.kind() == Tokens::COLON::id));
}
ISPA_STD::ExternalResult<Parser::Exports::symbol_30::node_type> Parser::Exports::symbol_30::parse(const char* origin, const char* start) {
symbol_30 parser; Lexer lexer; lexer.setExternalBoundary(); Lexer::lazy_iterator it(lexer, origin, start);
parser.template skip_spaces<Types::__WS>(it);
auto node = parser.template optional<node_type>(it, [&parser](auto cursor) { return parser.modulesRuleRegularRegular_rule(cursor); });
if (node.empty()) return {};
if (!parser.getErrors().empty()) throw std::runtime_error(parser.getErrors().front().message);
const char* end = it.sourcePosition();
return {true, ISPA_STD::external_node(origin, start, end, std::move(node)), end};
}

bool Parser::Exports::symbol_31::starts(const char* origin, const char* start) {
if (!start) return false;
if (!*start) return false;
Lexer lexer; lexer.setInput(origin); const char* p = start;
auto token = lexer.makeToken(p);
while (!token.empty() && token.kind() == Tokens::__WS::id && *p) token = lexer.makeToken(p);
return (!token.empty() && (false || token.kind() == Tokens::AMPERSAND::id || token.kind() == Tokens::COMMERCIAL_AT::id || token.kind() == Tokens::LEFT_PARENTHESIS::id || token.kind() == Tokens::PERCENT_SIGN::id || token.kind() == Tokens::modules::common::ID::id || token.kind() == Tokens::modules::rule::regular::value::ANY::id || token.kind() == Tokens::modules::rule::regular::value::CGROUP::id || token.kind() == Tokens::modules::rule::regular::value::NOSPACE::id || token.kind() == Tokens::modules::rule::regular::value::SPACE::id || token.kind() == Tokens::modules::rule::regular::value::STRING::id || token.kind() == Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id));
}
ISPA_STD::ExternalResult<Parser::Exports::symbol_31::node_type> Parser::Exports::symbol_31::parse(const char* origin, const char* start) {
symbol_31 parser; Lexer lexer; lexer.setExternalBoundary(); Lexer::lazy_iterator it(lexer, origin, start);
parser.template skip_spaces<Types::__WS>(it);
auto node = parser.template optional<node_type>(it, [&parser](auto cursor) { return parser.modulesRuleRegularValue(cursor); });
if (node.empty()) return {};
if (!parser.getErrors().empty()) throw std::runtime_error(parser.getErrors().front().message);
const char* end = it.sourcePosition();
return {true, ISPA_STD::external_node(origin, start, end, std::move(node)), end};
}

bool Parser::Exports::symbol_32::starts(const char* origin, const char* start) {
if (!start) return false;
if (!*start) return false;
Lexer lexer; lexer.setInput(origin); const char* p = start;
auto token = lexer.makeToken(p);
while (!token.empty() && token.kind() == Tokens::__WS::id && *p) token = lexer.makeToken(p);
return (!token.empty() && (false || token.kind() == Tokens::modules::rule::regular::value::ANY::id));
}
ISPA_STD::ExternalResult<Parser::Exports::symbol_32::node_type> Parser::Exports::symbol_32::parse(const char* origin, const char* start) {
symbol_32 parser; Lexer lexer; lexer.setExternalBoundary(); Lexer::lazy_iterator it(lexer, origin, start);
parser.template skip_spaces<Types::__WS>(it);
auto node = parser.template optional<node_type>(it);
if (node.empty()) return {};
if (!parser.getErrors().empty()) throw std::runtime_error(parser.getErrors().front().message);
const char* end = it.sourcePosition();
return {true, ISPA_STD::external_node(origin, start, end, std::move(node)), end};
}

bool Parser::Exports::symbol_33::starts(const char* origin, const char* start) {
if (!start) return false;
if (!*start) return false;
Lexer lexer; lexer.setInput(origin); const char* p = start;
auto token = lexer.makeToken(p);
while (!token.empty() && token.kind() == Tokens::__WS::id && *p) token = lexer.makeToken(p);
return (!token.empty() && (false || token.kind() == Tokens::modules::rule::regular::value::CGROUP::id));
}
ISPA_STD::ExternalResult<Parser::Exports::symbol_33::node_type> Parser::Exports::symbol_33::parse(const char* origin, const char* start) {
symbol_33 parser; Lexer lexer; lexer.setExternalBoundary(); Lexer::lazy_iterator it(lexer, origin, start);
parser.template skip_spaces<Types::__WS>(it);
auto node = parser.template optional<node_type>(it);
if (node.empty()) return {};
if (!parser.getErrors().empty()) throw std::runtime_error(parser.getErrors().front().message);
const char* end = it.sourcePosition();
return {true, ISPA_STD::external_node(origin, start, end, std::move(node)), end};
}

bool Parser::Exports::symbol_34::starts(const char* origin, const char* start) {
if (!start) return false;
if (!*start) return false;
Lexer lexer; lexer.setInput(origin); const char* p = start;
auto token = lexer.makeToken(p);
while (!token.empty() && token.kind() == Tokens::__WS::id && *p) token = lexer.makeToken(p);
return (!token.empty() && (false || token.kind() == Tokens::modules::rule::regular::value::NOSPACE::id));
}
ISPA_STD::ExternalResult<Parser::Exports::symbol_34::node_type> Parser::Exports::symbol_34::parse(const char* origin, const char* start) {
symbol_34 parser; Lexer lexer; lexer.setExternalBoundary(); Lexer::lazy_iterator it(lexer, origin, start);
parser.template skip_spaces<Types::__WS>(it);
auto node = parser.template optional<node_type>(it);
if (node.empty()) return {};
if (!parser.getErrors().empty()) throw std::runtime_error(parser.getErrors().front().message);
const char* end = it.sourcePosition();
return {true, ISPA_STD::external_node(origin, start, end, std::move(node)), end};
}

bool Parser::Exports::symbol_35::starts(const char* origin, const char* start) {
if (!start) return false;
if (!*start) return false;
Lexer lexer; lexer.setInput(origin); const char* p = start;
auto token = lexer.makeToken(p);
while (!token.empty() && token.kind() == Tokens::__WS::id && *p) token = lexer.makeToken(p);
return (!token.empty() && (false || token.kind() == Tokens::modules::rule::regular::value::QUANTIFIER::id));
}
ISPA_STD::ExternalResult<Parser::Exports::symbol_35::node_type> Parser::Exports::symbol_35::parse(const char* origin, const char* start) {
symbol_35 parser; Lexer lexer; lexer.setExternalBoundary(); Lexer::lazy_iterator it(lexer, origin, start);
parser.template skip_spaces<Types::__WS>(it);
auto node = parser.template optional<node_type>(it);
if (node.empty()) return {};
if (!parser.getErrors().empty()) throw std::runtime_error(parser.getErrors().front().message);
const char* end = it.sourcePosition();
return {true, ISPA_STD::external_node(origin, start, end, std::move(node)), end};
}

bool Parser::Exports::symbol_36::starts(const char* origin, const char* start) {
if (!start) return false;
if (!*start) return false;
Lexer lexer; lexer.setInput(origin); const char* p = start;
auto token = lexer.makeToken(p);
while (!token.empty() && token.kind() == Tokens::__WS::id && *p) token = lexer.makeToken(p);
return (!token.empty() && (false || token.kind() == Tokens::modules::rule::regular::value::SPACE::id));
}
ISPA_STD::ExternalResult<Parser::Exports::symbol_36::node_type> Parser::Exports::symbol_36::parse(const char* origin, const char* start) {
symbol_36 parser; Lexer lexer; lexer.setExternalBoundary(); Lexer::lazy_iterator it(lexer, origin, start);
parser.template skip_spaces<Types::__WS>(it);
auto node = parser.template optional<node_type>(it);
if (node.empty()) return {};
if (!parser.getErrors().empty()) throw std::runtime_error(parser.getErrors().front().message);
const char* end = it.sourcePosition();
return {true, ISPA_STD::external_node(origin, start, end, std::move(node)), end};
}

bool Parser::Exports::symbol_37::starts(const char* origin, const char* start) {
if (!start) return false;
if (!*start) return false;
Lexer lexer; lexer.setInput(origin); const char* p = start;
auto token = lexer.makeToken(p);
while (!token.empty() && token.kind() == Tokens::__WS::id && *p) token = lexer.makeToken(p);
return (!token.empty() && (false || token.kind() == Tokens::modules::rule::regular::value::STRING::id));
}
ISPA_STD::ExternalResult<Parser::Exports::symbol_37::node_type> Parser::Exports::symbol_37::parse(const char* origin, const char* start) {
symbol_37 parser; Lexer lexer; lexer.setExternalBoundary(); Lexer::lazy_iterator it(lexer, origin, start);
parser.template skip_spaces<Types::__WS>(it);
auto node = parser.template optional<node_type>(it);
if (node.empty()) return {};
if (!parser.getErrors().empty()) throw std::runtime_error(parser.getErrors().front().message);
const char* end = it.sourcePosition();
return {true, ISPA_STD::external_node(origin, start, end, std::move(node)), end};
}

bool Parser::Exports::symbol_38::starts(const char* origin, const char* start) {
if (!start) return false;
if (!*start) return false;
Lexer lexer; lexer.setInput(origin); const char* p = start;
auto token = lexer.makeToken(p);
while (!token.empty() && token.kind() == Tokens::__WS::id && *p) token = lexer.makeToken(p);
return (!token.empty() && (false || token.kind() == Tokens::modules::rule::regular::value::alternative::VERTICAL_LINE::id));
}
ISPA_STD::ExternalResult<Parser::Exports::symbol_38::node_type> Parser::Exports::symbol_38::parse(const char* origin, const char* start) {
symbol_38 parser; Lexer lexer; lexer.setExternalBoundary(); Lexer::lazy_iterator it(lexer, origin, start);
parser.template skip_spaces<Types::__WS>(it);
auto node = parser.template optional<node_type>(it, [&parser](auto cursor) { return parser.modulesRuleRegularValueAlternative(cursor); });
if (node.empty()) return {};
if (!parser.getErrors().empty()) throw std::runtime_error(parser.getErrors().front().message);
const char* end = it.sourcePosition();
return {true, ISPA_STD::external_node(origin, start, end, std::move(node)), end};
}

bool Parser::Exports::symbol_39::starts(const char* origin, const char* start) {
if (!start) return false;
if (!*start) return false;
Lexer lexer; lexer.setInput(origin); const char* p = start;
auto token = lexer.makeToken(p);
while (!token.empty() && token.kind() == Tokens::__WS::id && *p) token = lexer.makeToken(p);
return (!token.empty() && (false || token.kind() == Tokens::COMMERCIAL_AT::id));
}
ISPA_STD::ExternalResult<Parser::Exports::symbol_39::node_type> Parser::Exports::symbol_39::parse(const char* origin, const char* start) {
symbol_39 parser; Lexer lexer; lexer.setExternalBoundary(); Lexer::lazy_iterator it(lexer, origin, start);
parser.template skip_spaces<Types::__WS>(it);
auto node = parser.template optional<node_type>(it, [&parser](auto cursor) { return parser.modulesRuleRegularValueAst_capture(cursor); });
if (node.empty()) return {};
if (!parser.getErrors().empty()) throw std::runtime_error(parser.getErrors().front().message);
const char* end = it.sourcePosition();
return {true, ISPA_STD::external_node(origin, start, end, std::move(node)), end};
}

bool Parser::Exports::symbol_40::starts(const char* origin, const char* start) {
if (!start) return false;
if (!*start) return false;
Lexer lexer; lexer.setInput(origin); const char* p = start;
auto token = lexer.makeToken(p);
while (!token.empty() && token.kind() == Tokens::__WS::id && *p) token = lexer.makeToken(p);
return (!token.empty() && (false || token.kind() == Tokens::EQUALS_SIGN::id || token.kind() == Tokens::modules::rule::regular::value::QUANTIFIER::id));
}
ISPA_STD::ExternalResult<Parser::Exports::symbol_40::node_type> Parser::Exports::symbol_40::parse(const char* origin, const char* start) {
symbol_40 parser; Lexer lexer; lexer.setExternalBoundary(); Lexer::lazy_iterator it(lexer, origin, start);
parser.template skip_spaces<Types::__WS>(it);
auto node = parser.template optional<node_type>(it, [&parser](auto cursor) { return parser.modulesRuleRegularValueCounter(cursor); });
if (node.empty()) return {};
if (!parser.getErrors().empty()) throw std::runtime_error(parser.getErrors().front().message);
const char* end = it.sourcePosition();
return {true, ISPA_STD::external_node(origin, start, end, std::move(node)), end};
}

bool Parser::Exports::symbol_41::starts(const char* origin, const char* start) {
if (!start) return false;
if (!*start) return false;
Lexer lexer; lexer.setInput(origin); const char* p = start;
auto token = lexer.makeToken(p);
while (!token.empty() && token.kind() == Tokens::__WS::id && *p) token = lexer.makeToken(p);
return (!token.empty() && (false || token.kind() == Tokens::EQUALS_SIGN::id));
}
ISPA_STD::ExternalResult<Parser::Exports::symbol_41::node_type> Parser::Exports::symbol_41::parse(const char* origin, const char* start) {
symbol_41 parser; Lexer lexer; lexer.setExternalBoundary(); Lexer::lazy_iterator it(lexer, origin, start);
parser.template skip_spaces<Types::__WS>(it);
auto node = parser.template optional<node_type>(it, [&parser](auto cursor) { return parser.modulesRuleRegularValueCounterBounded(cursor); });
if (node.empty()) return {};
if (!parser.getErrors().empty()) throw std::runtime_error(parser.getErrors().front().message);
const char* end = it.sourcePosition();
return {true, ISPA_STD::external_node(origin, start, end, std::move(node)), end};
}

bool Parser::Exports::symbol_42::starts(const char* origin, const char* start) {
if (!start) return false;
if (!*start) return false;
Lexer lexer; lexer.setInput(origin); const char* p = start;
auto token = lexer.makeToken(p);
while (!token.empty() && token.kind() == Tokens::__WS::id && *p) token = lexer.makeToken(p);
return (!token.empty() && (false || token.kind() == Tokens::modules::rule::regular::value::QUANTIFIER::id));
}
ISPA_STD::ExternalResult<Parser::Exports::symbol_42::node_type> Parser::Exports::symbol_42::parse(const char* origin, const char* start) {
symbol_42 parser; Lexer lexer; lexer.setExternalBoundary(); Lexer::lazy_iterator it(lexer, origin, start);
parser.template skip_spaces<Types::__WS>(it);
auto node = parser.template optional<node_type>(it, [&parser](auto cursor) { return parser.modulesRuleRegularValueCounterQuantified(cursor); });
if (node.empty()) return {};
if (!parser.getErrors().empty()) throw std::runtime_error(parser.getErrors().front().message);
const char* end = it.sourcePosition();
return {true, ISPA_STD::external_node(origin, start, end, std::move(node)), end};
}

bool Parser::Exports::symbol_43::starts(const char* origin, const char* start) {
if (!start) return false;
if (!*start) return false;
Lexer lexer; lexer.setInput(origin); const char* p = start;
auto token = lexer.makeToken(p);
while (!token.empty() && token.kind() == Tokens::__WS::id && *p) token = lexer.makeToken(p);
return (!token.empty() && (false || token.kind() == Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id));
}
ISPA_STD::ExternalResult<Parser::Exports::symbol_43::node_type> Parser::Exports::symbol_43::parse(const char* origin, const char* start) {
symbol_43 parser; Lexer lexer; lexer.setExternalBoundary(); Lexer::lazy_iterator it(lexer, origin, start);
parser.template skip_spaces<Types::__WS>(it);
auto node = parser.template optional<node_type>(it, [&parser](auto cursor) { return parser.modulesRuleRegularValueDyn(cursor); });
if (node.empty()) return {};
if (!parser.getErrors().empty()) throw std::runtime_error(parser.getErrors().front().message);
const char* end = it.sourcePosition();
return {true, ISPA_STD::external_node(origin, start, end, std::move(node)), end};
}

bool Parser::Exports::symbol_44::starts(const char* origin, const char* start) {
if (!start) return false;
if (!*start) return false;
Lexer lexer; lexer.setInput(origin); const char* p = start;
auto token = lexer.makeToken(p);
while (!token.empty() && token.kind() == Tokens::__WS::id && *p) token = lexer.makeToken(p);
return (!token.empty() && (false || token.kind() == Tokens::LEFT_CURLY_BRACKET::id));
}
ISPA_STD::ExternalResult<Parser::Exports::symbol_44::node_type> Parser::Exports::symbol_44::parse(const char* origin, const char* start) {
symbol_44 parser; Lexer lexer; lexer.setExternalBoundary(); Lexer::lazy_iterator it(lexer, origin, start);
parser.template skip_spaces<Types::__WS>(it);
auto node = parser.template optional<node_type>(it, [&parser](auto cursor) { return parser.modulesRuleRegularValueDynDyn_expr(cursor); });
if (node.empty()) return {};
if (!parser.getErrors().empty()) throw std::runtime_error(parser.getErrors().front().message);
const char* end = it.sourcePosition();
return {true, ISPA_STD::external_node(origin, start, end, std::move(node)), end};
}

bool Parser::Exports::symbol_45::starts(const char* origin, const char* start) {
if (!start) return false;
if (!*start) return false;
Lexer lexer; lexer.setInput(origin); const char* p = start;
auto token = lexer.makeToken(p);
while (!token.empty() && token.kind() == Tokens::__WS::id && *p) token = lexer.makeToken(p);
return (!token.empty() && (false || token.kind() == Tokens::PERCENT_SIGN::id));
}
ISPA_STD::ExternalResult<Parser::Exports::symbol_45::node_type> Parser::Exports::symbol_45::parse(const char* origin, const char* start) {
symbol_45 parser; Lexer lexer; lexer.setExternalBoundary(); Lexer::lazy_iterator it(lexer, origin, start);
parser.template skip_spaces<Types::__WS>(it);
auto node = parser.template optional<node_type>(it, [&parser](auto cursor) { return parser.modulesRuleRegularValueFail_capture(cursor); });
if (node.empty()) return {};
if (!parser.getErrors().empty()) throw std::runtime_error(parser.getErrors().front().message);
const char* end = it.sourcePosition();
return {true, ISPA_STD::external_node(origin, start, end, std::move(node)), end};
}

bool Parser::Exports::symbol_46::starts(const char* origin, const char* start) {
if (!start) return false;
if (!*start) return false;
Lexer lexer; lexer.setInput(origin); const char* p = start;
auto token = lexer.makeToken(p);
while (!token.empty() && token.kind() == Tokens::__WS::id && *p) token = lexer.makeToken(p);
return (!token.empty() && (false || token.kind() == Tokens::LEFT_PARENTHESIS::id));
}
ISPA_STD::ExternalResult<Parser::Exports::symbol_46::node_type> Parser::Exports::symbol_46::parse(const char* origin, const char* start) {
symbol_46 parser; Lexer lexer; lexer.setExternalBoundary(); Lexer::lazy_iterator it(lexer, origin, start);
parser.template skip_spaces<Types::__WS>(it);
auto node = parser.template optional<node_type>(it, [&parser](auto cursor) { return parser.modulesRuleRegularValueGroup(cursor); });
if (node.empty()) return {};
if (!parser.getErrors().empty()) throw std::runtime_error(parser.getErrors().front().message);
const char* end = it.sourcePosition();
return {true, ISPA_STD::external_node(origin, start, end, std::move(node)), end};
}

bool Parser::Exports::symbol_47::starts(const char* origin, const char* start) {
if (!start) return false;
if (!*start) return false;
Lexer lexer; lexer.setInput(origin); const char* p = start;
auto token = lexer.makeToken(p);
while (!token.empty() && token.kind() == Tokens::__WS::id && *p) token = lexer.makeToken(p);
return (!token.empty() && (false || token.kind() == Tokens::COMMERCIAL_AT::id || token.kind() == Tokens::PERCENT_SIGN::id));
}
ISPA_STD::ExternalResult<Parser::Exports::symbol_47::node_type> Parser::Exports::symbol_47::parse(const char* origin, const char* start) {
symbol_47 parser; Lexer lexer; lexer.setExternalBoundary(); Lexer::lazy_iterator it(lexer, origin, start);
parser.template skip_spaces<Types::__WS>(it);
auto node = parser.template optional<node_type>(it, [&parser](auto cursor) { return parser.modulesRuleRegularValueMul_capture(cursor); });
if (node.empty()) return {};
if (!parser.getErrors().empty()) throw std::runtime_error(parser.getErrors().front().message);
const char* end = it.sourcePosition();
return {true, ISPA_STD::external_node(origin, start, end, std::move(node)), end};
}

bool Parser::Exports::symbol_48::starts(const char* origin, const char* start) {
if (!start) return false;
if (!*start) return false;
Lexer lexer; lexer.setInput(origin); const char* p = start;
auto token = lexer.makeToken(p);
while (!token.empty() && token.kind() == Tokens::__WS::id && *p) token = lexer.makeToken(p);
return (!token.empty() && (false || token.kind() == Tokens::AMPERSAND::id || token.kind() == Tokens::COMMERCIAL_AT::id || token.kind() == Tokens::LEFT_PARENTHESIS::id || token.kind() == Tokens::PERCENT_SIGN::id || token.kind() == Tokens::modules::common::ID::id || token.kind() == Tokens::modules::rule::regular::value::ANY::id || token.kind() == Tokens::modules::rule::regular::value::CGROUP::id || token.kind() == Tokens::modules::rule::regular::value::NOSPACE::id || token.kind() == Tokens::modules::rule::regular::value::SPACE::id || token.kind() == Tokens::modules::rule::regular::value::STRING::id || token.kind() == Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id));
}
ISPA_STD::ExternalResult<Parser::Exports::symbol_48::node_type> Parser::Exports::symbol_48::parse(const char* origin, const char* start) {
symbol_48 parser; Lexer lexer; lexer.setExternalBoundary(); Lexer::lazy_iterator it(lexer, origin, start);
parser.template skip_spaces<Types::__WS>(it);
auto node = parser.template optional<node_type>(it, [&parser](auto cursor) { return parser.modulesRuleRegularValueOne_capture(cursor); });
if (node.empty()) return {};
if (!parser.getErrors().empty()) throw std::runtime_error(parser.getErrors().front().message);
const char* end = it.sourcePosition();
return {true, ISPA_STD::external_node(origin, start, end, std::move(node)), end};
}

bool Parser::Exports::symbol_49::starts(const char* origin, const char* start) {
if (!start) return false;
if (!*start) return false;
Lexer lexer; lexer.setInput(origin); const char* p = start;
auto token = lexer.makeToken(p);
while (!token.empty() && token.kind() == Tokens::__WS::id && *p) token = lexer.makeToken(p);
return (!token.empty() && (false || token.kind() == Tokens::LEFT_PARENTHESIS::id || token.kind() == Tokens::modules::common::ID::id || token.kind() == Tokens::modules::rule::regular::value::ANY::id || token.kind() == Tokens::modules::rule::regular::value::CGROUP::id || token.kind() == Tokens::modules::rule::regular::value::NOSPACE::id || token.kind() == Tokens::modules::rule::regular::value::SPACE::id || token.kind() == Tokens::modules::rule::regular::value::STRING::id || token.kind() == Tokens::modules::rule::regular::value::dyn::DOLLAR_SIGN::id));
}
ISPA_STD::ExternalResult<Parser::Exports::symbol_49::node_type> Parser::Exports::symbol_49::parse(const char* origin, const char* start) {
symbol_49 parser; Lexer lexer; lexer.setExternalBoundary(); Lexer::lazy_iterator it(lexer, origin, start);
parser.template skip_spaces<Types::__WS>(it);
auto node = parser.template optional<node_type>(it, [&parser](auto cursor) { return parser.modulesRuleRegularValuePattern(cursor); });
if (node.empty()) return {};
if (!parser.getErrors().empty()) throw std::runtime_error(parser.getErrors().front().message);
const char* end = it.sourcePosition();
return {true, ISPA_STD::external_node(origin, start, end, std::move(node)), end};
}

bool Parser::Exports::symbol_50::starts(const char* origin, const char* start) {
if (!start) return false;
if (!*start) return false;
Lexer lexer; lexer.setInput(origin); const char* p = start;
auto token = lexer.makeToken(p);
while (!token.empty() && token.kind() == Tokens::__WS::id && *p) token = lexer.makeToken(p);
return (!token.empty() && (false || token.kind() == Tokens::modules::rule::regular::value::shared_counter_registration::AUTO::id));
}
ISPA_STD::ExternalResult<Parser::Exports::symbol_50::node_type> Parser::Exports::symbol_50::parse(const char* origin, const char* start) {
symbol_50 parser; Lexer lexer; lexer.setExternalBoundary(); Lexer::lazy_iterator it(lexer, origin, start);
parser.template skip_spaces<Types::__WS>(it);
auto node = parser.template optional<node_type>(it, [&parser](auto cursor) { return parser.modulesRuleRegularValueShared_counter_registration(cursor); });
if (node.empty()) return {};
if (!parser.getErrors().empty()) throw std::runtime_error(parser.getErrors().front().message);
const char* end = it.sourcePosition();
return {true, ISPA_STD::external_node(origin, start, end, std::move(node)), end};
}

bool Parser::Exports::symbol_51::starts(const char* origin, const char* start) {
if (!start) return false;
if (!*start) return false;
Lexer lexer; lexer.setInput(origin); const char* p = start;
auto token = lexer.makeToken(p);
while (!token.empty() && token.kind() == Tokens::__WS::id && *p) token = lexer.makeToken(p);
return (!token.empty() && (false || token.kind() == Tokens::AMPERSAND::id));
}
ISPA_STD::ExternalResult<Parser::Exports::symbol_51::node_type> Parser::Exports::symbol_51::parse(const char* origin, const char* start) {
symbol_51 parser; Lexer lexer; lexer.setExternalBoundary(); Lexer::lazy_iterator it(lexer, origin, start);
parser.template skip_spaces<Types::__WS>(it);
auto node = parser.template optional<node_type>(it, [&parser](auto cursor) { return parser.modulesRuleRegularValueVar_capture(cursor); });
if (node.empty()) return {};
if (!parser.getErrors().empty()) throw std::runtime_error(parser.getErrors().front().message);
const char* end = it.sourcePosition();
return {true, ISPA_STD::external_node(origin, start, end, std::move(node)), end};
}
