#include "Parser.h"

#include <ispastdlib/variant_io.hpp>
#include <ispastdlib/dfa_api.hpp>
#include <ispastdlib/assign.hpp>
#include <ispastdlib/to_string.hpp>

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
auto Parser::FlatTypes::template_params_GREATER_THAN_SIGN::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("template_params_GREATER_THAN_SIGN", true);
}
auto Parser::FlatTypes::template_params_GREATER_THAN_SIGN::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::template_params_GREATER_THAN_SIGN::to_string() const -> std::string {
	return ::ISPA_STD::concat("template_params_GREATER_THAN_SIGN {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, template_params_GREATER_THAN_SIGN value) -> std::ostream & {
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
auto Parser::FlatTypes::forward_declaration::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("forward_declaration", false);
	printer.up(false);
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::forward_declaration::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::forward_declaration::to_string() const -> std::string {
	return ::ISPA_STD::concat("forward_declaration {", "value = ", value.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, forward_declaration value) -> std::ostream & {
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
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::template_params::GREATER_THAN_SIGN::id, Types::template_params::GREATER_THAN_SIGN{}));
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
			if (captures.is_set(10)) {
				value = captures.text(10);
			} else {
				if (captures.is_set(11)) {
					value = captures.text(11);
				} else {
					if (captures.is_set(9)) {
						value = captures.text(9);
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
			if (captures.is_set(10)) {
				value = captures.text(10);
			} else {
				if (captures.is_set(11)) {
					value = captures.text(11);
				} else {
					if (captures.is_set(9)) {
						value = captures.text(9);
					}
				}
			}
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::grammar::modifier::MOD::id, Types::grammar::modifier::MOD{value}));
			break;
		}
		case 38: {
			std::string value;
			if (captures.is_set(10)) {
				value = captures.text(10);
			} else {
				if (captures.is_set(11)) {
					value = captures.text(11);
				} else {
					if (captures.is_set(9)) {
						value = captures.text(9);
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
::ISPA_STD::DFA::API::Table<104, 4> Parser::Lexer::action_table = {{{1, 0, ::ISPA_STD::DFA::API::null_state, 22}, {1, 26, ::ISPA_STD::DFA::API::null_state, 28}, {1, 26, ::ISPA_STD::DFA::API::null_state, 27}, {1, 26, ::ISPA_STD::DFA::API::null_state, 26}, {1, 26, ::ISPA_STD::DFA::API::null_state, 32}, {1, 26, ::ISPA_STD::DFA::API::null_state, 31}, {1, 26, ::ISPA_STD::DFA::API::null_state, 29}, {1, 14, ::ISPA_STD::DFA::API::null_state, 14}, {1, 12, ::ISPA_STD::DFA::API::null_state, 10}, {1, 8, ::ISPA_STD::DFA::API::null_state, 9}, {1, 10, ::ISPA_STD::DFA::API::null_state, 20}, {1, 26, ::ISPA_STD::DFA::API::null_state, 30}, {1, 24, ::ISPA_STD::DFA::API::null_state, 36}, {1, 24, ::ISPA_STD::DFA::API::null_state, 39}, {1, 26, ::ISPA_STD::DFA::API::null_state, 37}, {1, 9, ::ISPA_STD::DFA::API::null_state, 197}, {1, 13, ::ISPA_STD::DFA::API::null_state, 198}, {1, 15, ::ISPA_STD::DFA::API::null_state, 201}, {1, 15, ::ISPA_STD::DFA::API::null_state, 42}, {1, 11, ::ISPA_STD::DFA::API::null_state, 207}, {1, 1, ::ISPA_STD::DFA::API::null_state, 209}, {1, 6, ::ISPA_STD::DFA::API::null_state, 45}, {1, 6, ::ISPA_STD::DFA::API::null_state, 47}, {1, 6, ::ISPA_STD::DFA::API::null_state, 46}, {3, 0, 26, 209}, {1, 1, ::ISPA_STD::DFA::API::null_state, 110}, {3, 0, 26, 44}, {3, 0, 26, 209}, {1, 1, ::ISPA_STD::DFA::API::null_state, 113}, {3, 0, 26, 209}, {1, 1, ::ISPA_STD::DFA::API::null_state, 115}, {3, 0, 26, 209}, {1, 1, ::ISPA_STD::DFA::API::null_state, 117}, {3, 0, 26, 209}, {1, 1, ::ISPA_STD::DFA::API::null_state, 119}, {3, 0, 26, 209}, {1, 1, ::ISPA_STD::DFA::API::null_state, 121}, {3, 0, 26, 209}, {1, 1, ::ISPA_STD::DFA::API::null_state, 123}, {1, 25, ::ISPA_STD::DFA::API::null_state, 38}, {1, 25, ::ISPA_STD::DFA::API::null_state, 56}, {3, 24, 26, 36}, {3, 24, 26, 39}, {3, 24, 26, 38}, {1, 25, ::ISPA_STD::DFA::API::null_state, 129}, {3, 24, 26, 56}, {1, 25, ::ISPA_STD::DFA::API::null_state, 131}, {1, 16, ::ISPA_STD::DFA::API::null_state, 57}, {1, 1, ::ISPA_STD::DFA::API::null_state, 218}, {1, 7, ::ISPA_STD::DFA::API::null_state, 58}, {1, 5, ::ISPA_STD::DFA::API::null_state, 59}, {1, 5, ::ISPA_STD::DFA::API::null_state, 60}, {3, 0, 26, 218}, {1, 1, ::ISPA_STD::DFA::API::null_state, 138}, {3, 0, 26, 218}, {1, 1, ::ISPA_STD::DFA::API::null_state, 140}, {3, 0, 26, 218}, {1, 1, ::ISPA_STD::DFA::API::null_state, 142}, {3, 0, 26, 218}, {1, 1, ::ISPA_STD::DFA::API::null_state, 144}, {3, 0, 26, 218}, {1, 1, ::ISPA_STD::DFA::API::null_state, 146}, {1, 2, ::ISPA_STD::DFA::API::null_state, 67}, {3, 0, 26, 218}, {1, 1, ::ISPA_STD::DFA::API::null_state, 149}, {1, 17, ::ISPA_STD::DFA::API::null_state, 220}, {1, 7, ::ISPA_STD::DFA::API::null_state, 69}, {3, 0, 26, 218}, {1, 1, ::ISPA_STD::DFA::API::null_state, 153}, {3, 0, 26, 218}, {1, 1, ::ISPA_STD::DFA::API::null_state, 155}, {3, 0, 26, 218}, {1, 1, ::ISPA_STD::DFA::API::null_state, 157}, {3, 0, 26, 218}, {1, 1, ::ISPA_STD::DFA::API::null_state, 159}, {3, 0, 26, 218}, {1, 1, ::ISPA_STD::DFA::API::null_state, 161}, {3, 0, 26, 218}, {1, 1, ::ISPA_STD::DFA::API::null_state, 163}, {3, 6, 5, 221}, {3, 4, 6, 165}, {3, 0, 26, 218}, {1, 1, ::ISPA_STD::DFA::API::null_state, 167}, {3, 0, 26, 218}, {1, 1, ::ISPA_STD::DFA::API::null_state, 169}, {3, 0, 26, 218}, {1, 1, ::ISPA_STD::DFA::API::null_state, 171}, {3, 0, 26, 218}, {1, 1, ::ISPA_STD::DFA::API::null_state, 173}, {1, 3, ::ISPA_STD::DFA::API::null_state, 81}, {3, 18, 26, 224}, {1, 19, ::ISPA_STD::DFA::API::null_state, 176}, {3, 0, 26, 218}, {1, 1, ::ISPA_STD::DFA::API::null_state, 178}, {3, 0, 26, 218}, {1, 1, ::ISPA_STD::DFA::API::null_state, 180}, {3, 0, 26, 218}, {1, 1, ::ISPA_STD::DFA::API::null_state, 182}, {3, 0, 26, 218}, {1, 1, ::ISPA_STD::DFA::API::null_state, 184}, {3, 20, 26, 227}, {1, 21, ::ISPA_STD::DFA::API::null_state, 186}, {3, 22, 26, 228}, {1, 23, ::ISPA_STD::DFA::API::null_state, 188}}};
std::array<::ISPA_STD::DFA::API::DFADebug, 1> Parser::Lexer::debug_array = {::ISPA_STD::DFA::API::DFADebug {"<Undefined>", "", 0, -1, -1, -1, 0, 1, '\000'}};
std::unordered_map<long long, std::unordered_map<long long, long long>> Parser::Lexer::debug_index = { { 0, { { 1, 0 }, { 2, 0 }, { 3, 0 }, { 4, 0 }, { 5, 0 }, { 6, 0 }, { 7, 0 }, { 8, 0 }, { 9, 0 }, { 12, 0 }, { 13, 0 }, { 14, 0 }, { 17, 0 }, { 18, 0 }, { 19, 0 }, { 20, 0 }, { 21, 0 }, { 23, 0 }, { 25, 0 }, { 26, 0 }, { 27, 0 }, { 46, 0 }, { 47, 0 }, { 48, 0 } } }, { 1, { { 1, 0 } } }, { 2, { { 7, 0 } } }, { 3, { { 25, 0 } } }, { 12, { { 21, 0 } } }, { 14, { { 15, 0 }, { 16, 0 } } }, { 18, { { 21, 0 } } }, { 22, { { 15, 0 }, { 16, 0 }, { 24, 0 }, { 29, 0 }, { 30, 0 }, { 31, 0 }, { 32, 0 }, { 33, 0 }, { 34, 0 }, { 35, 0 }, { 36, 0 }, { 37, 0 }, { 38, 0 }, { 39, 0 }, { 40, 0 }, { 41, 0 }, { 42, 0 }, { 43, 0 }, { 44, 0 }, { 45, 0 } } }, { 24, { { 42, 0 } } }, { 26, { { 32, 0 } } }, { 27, { { 44, 0 } } }, { 28, { { 29, 0 } } }, { 29, { { 39, 0 } } }, { 30, { { 29, 0 } } }, { 31, { { 46, 0 } } }, { 32, { { 36, 0 } } }, { 36, { { 0, 0 }, { 1, 0 }, { 3, 0 }, { 4, 0 }, { 5, 0 }, { 6, 0 }, { 8, 0 }, { 9, 0 }, { 10, 0 }, { 11, 0 }, { 12, 0 }, { 13, 0 }, { 14, 0 }, { 15, 0 }, { 16, 0 }, { 17, 0 }, { 18, 0 }, { 19, 0 }, { 20, 0 }, { 21, 0 }, { 22, 0 }, { 23, 0 }, { 24, 0 }, { 25, 0 }, { 26, 0 }, { 27, 0 }, { 28, 0 }, { 29, 0 }, { 30, 0 }, { 31, 0 }, { 32, 0 }, { 33, 0 }, { 34, 0 }, { 35, 0 }, { 36, 0 }, { 37, 0 }, { 38, 0 }, { 39, 0 }, { 40, 0 }, { 41, 0 }, { 42, 0 }, { 43, 0 }, { 44, 0 }, { 45, 0 }, { 46, 0 }, { 47, 0 }, { 48, 0 } } }, { 39, { { 0, 0 }, { 1, 0 }, { 2, 0 }, { 3, 0 }, { 4, 0 }, { 5, 0 }, { 6, 0 }, { 7, 0 }, { 8, 0 }, { 9, 0 }, { 10, 0 }, { 11, 0 }, { 12, 0 }, { 13, 0 }, { 14, 0 }, { 15, 0 }, { 16, 0 }, { 17, 0 }, { 18, 0 }, { 19, 0 }, { 20, 0 }, { 21, 0 }, { 22, 0 }, { 23, 0 }, { 24, 0 }, { 25, 0 }, { 26, 0 }, { 27, 0 }, { 28, 0 }, { 29, 0 }, { 30, 0 }, { 31, 0 }, { 32, 0 }, { 33, 0 }, { 34, 0 }, { 35, 0 }, { 36, 0 }, { 37, 0 }, { 38, 0 }, { 39, 0 }, { 40, 0 }, { 41, 0 }, { 42, 0 }, { 43, 0 }, { 44, 0 }, { 45, 0 }, { 46, 0 }, { 47, 0 }, { 48, 0 } } }, { 44, { { 15, 0 }, { 16, 0 }, { 24, 0 }, { 29, 0 }, { 30, 0 }, { 31, 0 }, { 32, 0 }, { 33, 0 }, { 34, 0 }, { 35, 0 }, { 36, 0 }, { 37, 0 }, { 38, 0 }, { 39, 0 }, { 40, 0 }, { 41, 0 }, { 42, 0 }, { 43, 0 }, { 44, 0 }, { 45, 0 } } }, { 45, { { 0, 0 }, { 1, 0 }, { 2, 0 }, { 3, 0 }, { 4, 0 }, { 5, 0 }, { 6, 0 }, { 7, 0 }, { 8, 0 }, { 9, 0 }, { 10, 0 }, { 11, 0 }, { 12, 0 }, { 13, 0 }, { 14, 0 }, { 15, 0 }, { 16, 0 }, { 17, 0 }, { 18, 0 }, { 19, 0 }, { 20, 0 }, { 21, 0 }, { 22, 0 }, { 23, 0 }, { 24, 0 }, { 25, 0 }, { 26, 0 }, { 28, 0 }, { 29, 0 }, { 30, 0 }, { 31, 0 }, { 32, 0 }, { 33, 0 }, { 34, 0 }, { 35, 0 }, { 36, 0 }, { 37, 0 }, { 38, 0 }, { 39, 0 }, { 40, 0 }, { 41, 0 }, { 42, 0 }, { 43, 0 }, { 44, 0 }, { 45, 0 }, { 46, 0 }, { 47, 0 }, { 48, 0 } } }, { 46, { { 0, 0 }, { 1, 0 }, { 2, 0 }, { 3, 0 }, { 4, 0 }, { 5, 0 }, { 6, 0 }, { 7, 0 }, { 8, 0 }, { 9, 0 }, { 10, 0 }, { 11, 0 }, { 12, 0 }, { 13, 0 }, { 14, 0 }, { 15, 0 }, { 16, 0 }, { 17, 0 }, { 18, 0 }, { 19, 0 }, { 20, 0 }, { 21, 0 }, { 22, 0 }, { 23, 0 }, { 24, 0 }, { 25, 0 }, { 26, 0 }, { 27, 0 }, { 28, 0 }, { 29, 0 }, { 30, 0 }, { 31, 0 }, { 32, 0 }, { 33, 0 }, { 34, 0 }, { 35, 0 }, { 36, 0 }, { 37, 0 }, { 38, 0 }, { 39, 0 }, { 40, 0 }, { 41, 0 }, { 42, 0 }, { 43, 0 }, { 44, 0 }, { 45, 0 }, { 46, 0 }, { 47, 0 }, { 48, 0 } } }, { 48, { { 15, 0 } } }, { 49, { { 40, 0 } } }, { 50, { { 43, 0 } } }, { 51, { { 35, 0 } } }, { 52, { { 37, 0 } } }, { 53, { { 43, 0 } } }, { 55, { { 35, 0 } } }, { 56, { { 0, 0 }, { 1, 0 }, { 3, 0 }, { 4, 0 }, { 5, 0 }, { 6, 0 }, { 8, 0 }, { 9, 0 }, { 10, 0 }, { 11, 0 }, { 12, 0 }, { 13, 0 }, { 14, 0 }, { 15, 0 }, { 16, 0 }, { 17, 0 }, { 18, 0 }, { 19, 0 }, { 20, 0 }, { 21, 0 }, { 22, 0 }, { 23, 0 }, { 24, 0 }, { 25, 0 }, { 26, 0 }, { 27, 0 }, { 28, 0 }, { 29, 0 }, { 30, 0 }, { 31, 0 }, { 32, 0 }, { 33, 0 }, { 34, 0 }, { 35, 0 }, { 36, 0 }, { 37, 0 }, { 38, 0 }, { 39, 0 }, { 40, 0 }, { 41, 0 }, { 42, 0 }, { 43, 0 }, { 44, 0 }, { 45, 0 }, { 46, 0 }, { 47, 0 }, { 48, 0 } } }, { 57, { { 15, 0 }, { 16, 0 } } }, { 59, { { 0, 0 }, { 1, 0 }, { 2, 0 }, { 3, 0 }, { 4, 0 }, { 5, 0 }, { 6, 0 }, { 7, 0 }, { 8, 0 }, { 9, 0 }, { 10, 0 }, { 11, 0 }, { 12, 0 }, { 13, 0 }, { 14, 0 }, { 15, 0 }, { 16, 0 }, { 17, 0 }, { 18, 0 }, { 19, 0 }, { 20, 0 }, { 21, 0 }, { 22, 0 }, { 23, 0 }, { 24, 0 }, { 25, 0 }, { 26, 0 }, { 28, 0 }, { 29, 0 }, { 30, 0 }, { 31, 0 }, { 32, 0 }, { 33, 0 }, { 34, 0 }, { 35, 0 }, { 36, 0 }, { 37, 0 }, { 38, 0 }, { 39, 0 }, { 40, 0 }, { 41, 0 }, { 42, 0 }, { 43, 0 }, { 44, 0 }, { 45, 0 }, { 46, 0 }, { 47, 0 }, { 48, 0 } } }, { 60, { { 0, 0 }, { 1, 0 }, { 2, 0 }, { 3, 0 }, { 4, 0 }, { 5, 0 }, { 6, 0 }, { 7, 0 }, { 8, 0 }, { 9, 0 }, { 10, 0 }, { 11, 0 }, { 12, 0 }, { 13, 0 }, { 14, 0 }, { 15, 0 }, { 16, 0 }, { 17, 0 }, { 18, 0 }, { 19, 0 }, { 20, 0 }, { 21, 0 }, { 22, 0 }, { 23, 0 }, { 24, 0 }, { 25, 0 }, { 26, 0 }, { 27, 0 }, { 28, 0 }, { 29, 0 }, { 30, 0 }, { 31, 0 }, { 32, 0 }, { 33, 0 }, { 34, 0 }, { 35, 0 }, { 36, 0 }, { 37, 0 }, { 38, 0 }, { 39, 0 }, { 40, 0 }, { 41, 0 }, { 42, 0 }, { 43, 0 }, { 44, 0 }, { 45, 0 }, { 46, 0 }, { 47, 0 }, { 48, 0 } } }, { 62, { { 32, 0 } } }, { 63, { { 32, 0 } } }, { 64, { { 37, 0 } } }, { 65, { { 35, 0 } } }, { 66, { { 30, 0 } } }, { 67, { { 45, 0 } } }, { 68, { { 40, 0 } } }, { 70, { { 39, 0 } } }, { 71, { { 41, 0 } } }, { 73, { { 39, 0 } } }, { 74, { { 34, 0 } } }, { 77, { { 31, 0 } } }, { 78, { { 39, 0 } } }, { 79, { { 32, 0 } } }, { 82, { { 42, 0 } } } };
template<typename IT, class> auto Parser::Parser::advanced_rule(IT pos) -> ::ISPA_STD::MatchResult<Types::advanced_rule, IT> {
	::ISPA_STD::Node<Types::LEFT_CURLY_BRACKET> LEFT_CURLY_BRACKET_0;
	bool success_1;
	::ISPA_STD::MatchResult<Types::advanced_rule::dep_decl, IT> advanced_rule_dep_decl_5;
	bool success_6;
	::ISPA_STD::Node<Types::advanced_rule::dep_decl> element_7;
	std::vector<::ISPA_STD::Node<Types::advanced_rule::dep_decl>> shadow_8;
	std::vector<::ISPA_STD::Node<Types::advanced_rule::dep_decl>> uvar_4;
	::ISPA_STD::Node<Types::__WS> __WS_2;
	bool success_3;
	bool success_16;
	std::variant<std::monostate, ::ISPA_STD::Node<Types::stmt>, ::ISPA_STD::Node<Types::advanced_rule::regular_match>> group_12;
	bool success_14;
	std::vector<std::variant<std::monostate, ::ISPA_STD::Node<Types::stmt>, ::ISPA_STD::Node<Types::advanced_rule::regular_match>>> shadow_27;
	std::vector<std::variant<std::monostate, ::ISPA_STD::Node<Types::stmt>, ::ISPA_STD::Node<Types::advanced_rule::regular_match>>> uvar_13;
	::ISPA_STD::Node<Types::__WS> __WS_10;
	bool success_11;
	std::variant<std::monostate, ::ISPA_STD::Node<Types::stmt>, ::ISPA_STD::Node<Types::advanced_rule::regular_match>> _15;
	::ISPA_STD::MatchResult<Types::stmt, IT> stmt_18;
	bool success_19;
	::ISPA_STD::Node<Types::stmt> element_20;
	std::vector<::ISPA_STD::Node<Types::stmt>> shadow_21;
	::ISPA_STD::Node<Types::stmt> uvar_17;
	::ISPA_STD::MatchResult<Types::advanced_rule::regular_match, IT> advanced_rule_regular_match_23;
	bool success_24;
	::ISPA_STD::Node<Types::advanced_rule::regular_match> element_25;
	std::vector<::ISPA_STD::Node<Types::advanced_rule::regular_match>> shadow_26;
	::ISPA_STD::Node<Types::advanced_rule::regular_match> uvar_22;
	::ISPA_STD::Node<Types::__WS> __WS_30;
	bool success_31;
	::ISPA_STD::Node<Types::RIGHT_CURLY_BRACKET> RIGHT_CURLY_BRACKET_32;
	bool success_33;
	success_1 = false;
	if (!(((*pos)).template holds<Types::LEFT_CURLY_BRACKET>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  LEFT_CURLY_BRACKET");
		return {};
	}
	LEFT_CURLY_BRACKET_0 = ((*pos)).template to_node<::ISPA_STD::Node<Types::LEFT_CURLY_BRACKET>>();
	success_1 = true;
	pos++;
	success_6 = false;
	// grammar `@  advanced_rule::dep_decl*;`: repeat named rule; collect every matched value
	while (true) {
		auto repeat_ws_9 = pos;
		success_3 = false;
		if (((*repeat_ws_9)).template holds<Types::__WS>()) {
			__WS_2 = ((*repeat_ws_9)).template to_node<::ISPA_STD::Node<Types::__WS>>();
			success_3 = true;
			repeat_ws_9++;
		}
		advanced_rule_dep_decl_5 = advanced_rule_dep_decl(repeat_ws_9);
		if (!(advanced_rule_dep_decl_5.status)) {
			break;
		}
		success_6 = true;
		repeat_ws_9 = advanced_rule_dep_decl_5.it;
		element_7 = advanced_rule_dep_decl_5.node;
		shadow_8.push_back(element_7);
		pos = repeat_ws_9;
	}
	::ISPA_STD::assign_compatible(uvar_4, shadow_8);
	success_14 = false;
	auto begin_28 = pos;
	while (true) {
		auto repeat_ws_29 = begin_28;
		success_11 = false;
		if (((*repeat_ws_29)).template holds<Types::__WS>()) {
			__WS_10 = ((*repeat_ws_29)).template to_node<::ISPA_STD::Node<Types::__WS>>();
			success_11 = true;
			repeat_ws_29++;
		}
		skip_spaces<Types::__WS>(repeat_ws_29);
		// grammar ` ( advanced_rule::regular_match |  stmt)`: choice; reset match status before selecting an alternative
		success_16 = false;
		auto lookahead_pos_1 = repeat_ws_29;
		switch ((*lookahead_pos_1).kind()) {
			case Tokens::PY_RAW::id: {
				lookahead_pos_1 = lookahead_pos_1;
				success_19 = false;
				stmt_18 = stmt(lookahead_pos_1);
				if (!(stmt_18.status)) {
					// speculative match failed (diagnostic suppressed):  stmt
					break;
				}
				success_19 = true;
				lookahead_pos_1 = stmt_18.it;
				element_20 = stmt_18.node;
				shadow_21.push_back(element_20);
				if (!success_19) {
					// speculative match failed (diagnostic suppressed):  stmt
					break;
				}
				_15 = stmt_18.node;
				success_16 = true;
				break;
			}
			case Tokens::advanced_rule::regular_match::MATCH::id: {
				lookahead_pos_1 = lookahead_pos_1;
				success_24 = false;
				advanced_rule_regular_match_23 = advanced_rule_regular_match(lookahead_pos_1);
				if (!(advanced_rule_regular_match_23.status)) {
					// speculative match failed (diagnostic suppressed):  advanced_rule::regular_match
					break;
				}
				success_24 = true;
				lookahead_pos_1 = advanced_rule_regular_match_23.it;
				element_25 = advanced_rule_regular_match_23.node;
				shadow_26.push_back(element_25);
				if (!success_24) {
					// speculative match failed (diagnostic suppressed):  advanced_rule::regular_match
					break;
				}
				_15 = advanced_rule_regular_match_23.node;
				success_16 = true;
				break;
			}
		}
		repeat_ws_29 = lookahead_pos_1;
		if (!success_16) {
			// speculative match failed (diagnostic suppressed):  ( advanced_rule::regular_match |  stmt)
			break;
		}
		if (success_16) {
			group_12 = _15;
			shadow_27.push_back(group_12);
		}
		begin_28 = repeat_ws_29;
	}
	success_14 = true;
	::ISPA_STD::assign_compatible(uvar_13, shadow_27);
	pos = begin_28;
	success_31 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_30 = ((*pos)).template to_node<::ISPA_STD::Node<Types::__WS>>();
		success_31 = true;
		pos++;
	}
	success_33 = false;
	if (!(((*pos)).template holds<Types::RIGHT_CURLY_BRACKET>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  RIGHT_CURLY_BRACKET");
		return {};
	}
	RIGHT_CURLY_BRACKET_32 = ((*pos)).template to_node<::ISPA_STD::Node<Types::RIGHT_CURLY_BRACKET>>();
	success_33 = true;
	pos++;
	Types::advanced_rule result;
	::ISPA_STD::assign_compatible(result.dep, uvar_4);
	::ISPA_STD::assign_compatible(result.body, uvar_13);
	::ISPA_STD::MatchResult<Types::advanced_rule, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::advanced_rule<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::advanced_rule, ::Parser::Lexer::iterator>;
template auto Parser::Parser::advanced_rule<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::advanced_rule, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::advanced_rule_dep_decl(IT pos) -> ::ISPA_STD::MatchResult<Types::advanced_rule::dep_decl, IT> {
	::ISPA_STD::Node<Types::advanced_rule::dep_decl::DEPENDS> advanced_rule_dep_decl_DEPENDS_0;
	bool success_1;
	::ISPA_STD::Node<Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::MatchResult<Types::forward_declaration, IT> forward_declaration_4;
	bool success_5;
	success_1 = false;
	if (!(((*pos)).template holds<Types::advanced_rule::dep_decl::DEPENDS>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  advanced_rule::dep_decl::DEPENDS");
		return {};
	}
	advanced_rule_dep_decl_DEPENDS_0 = ((*pos)).template to_node<::ISPA_STD::Node<Types::advanced_rule::dep_decl::DEPENDS>>();
	success_1 = true;
	pos++;
	success_3 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_2 = ((*pos)).template to_node<::ISPA_STD::Node<Types::__WS>>();
		success_3 = true;
		pos++;
	}
	success_5 = false;
	forward_declaration_4 = forward_declaration(pos);
	if (!(forward_declaration_4.status)) {
		raise_error(*pos, "ISPA match failure: required named rule did not match | grammar: @  forward_declaration");
		return {};
	}
	success_5 = true;
	pos = forward_declaration_4.it;
	Types::advanced_rule::dep_decl result;
	::ISPA_STD::assign_compatible(result.value, forward_declaration_4.node);
	::ISPA_STD::MatchResult<Types::advanced_rule::dep_decl, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::advanced_rule_dep_decl<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::advanced_rule::dep_decl, ::Parser::Lexer::iterator>;
template auto Parser::Parser::advanced_rule_dep_decl<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::advanced_rule::dep_decl, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::advanced_rule_fail_call(IT pos) -> ::ISPA_STD::MatchResult<Types::advanced_rule::fail_call, IT> {
	::ISPA_STD::Node<Types::FAIL> FAIL_0;
	bool success_1;
	::ISPA_STD::Node<Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::MatchResult<Types::name, IT> name_4;
	bool success_5;
	success_1 = false;
	if (!(((*pos)).template holds<Types::FAIL>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  FAIL");
		return {};
	}
	FAIL_0 = ((*pos)).template to_node<::ISPA_STD::Node<Types::FAIL>>();
	success_1 = true;
	pos++;
	success_3 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_2 = ((*pos)).template to_node<::ISPA_STD::Node<Types::__WS>>();
		success_3 = true;
		pos++;
	}
	success_5 = false;
	name_4 = name(pos);
	if (!(name_4.status)) {
		raise_error(*pos, "ISPA match failure: required named rule did not match | grammar: @  name");
		return {};
	}
	success_5 = true;
	pos = name_4.it;
	Types::advanced_rule::fail_call result;
	::ISPA_STD::assign_compatible(result.value, name_4.node);
	::ISPA_STD::MatchResult<Types::advanced_rule::fail_call, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::advanced_rule_fail_call<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::advanced_rule::fail_call, ::Parser::Lexer::iterator>;
template auto Parser::Parser::advanced_rule_fail_call<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::advanced_rule::fail_call, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::advanced_rule_regular_match(IT pos) -> ::ISPA_STD::MatchResult<Types::advanced_rule::regular_match, IT> {
	::ISPA_STD::Node<Types::advanced_rule::regular_match::MATCH> advanced_rule_regular_match_MATCH_0;
	bool success_1;
	::ISPA_STD::MatchResult<Types::rule::value, IT> rule_value_5;
	bool success_6;
	::ISPA_STD::Node<Types::rule::value> element_7;
	std::vector<::ISPA_STD::Node<Types::rule::value>> shadow_8;
	std::vector<::ISPA_STD::Node<Types::rule::value>> uvar_4;
	bool success_9;
	::ISPA_STD::Node<Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::Node<Types::__WS> __WS_11;
	bool success_12;
	std::variant<std::monostate, ::ISPA_STD::Node<Types::SEMICOLON>, ::ISPA_STD::Node<Types::advanced_rule::regular_match::unpack>> _13;
	bool success_14;
	::ISPA_STD::MatchResult<Types::advanced_rule::regular_match::unpack, IT> advanced_rule_regular_match_unpack_15;
	bool success_16;
	::ISPA_STD::Node<Types::SEMICOLON> SEMICOLON_17;
	bool success_18;
	success_1 = false;
	if (!(((*pos)).template holds<Types::advanced_rule::regular_match::MATCH>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  advanced_rule::regular_match::MATCH");
		return {};
	}
	advanced_rule_regular_match_MATCH_0 = ((*pos)).template to_node<::ISPA_STD::Node<Types::advanced_rule::regular_match::MATCH>>();
	success_1 = true;
	pos++;
	success_6 = false;
	// grammar `@  rule::value+;`: repeat named rule; collect every matched value
	success_9 = false;
	while (true) {
		auto repeat_ws_10 = pos;
		success_3 = false;
		if (((*repeat_ws_10)).template holds<Types::__WS>()) {
			__WS_2 = ((*repeat_ws_10)).template to_node<::ISPA_STD::Node<Types::__WS>>();
			success_3 = true;
			repeat_ws_10++;
		}
		rule_value_5 = rule_value(repeat_ws_10);
		if (!(rule_value_5.status)) {
			break;
		}
		success_6 = true;
		repeat_ws_10 = rule_value_5.it;
		element_7 = rule_value_5.node;
		shadow_8.push_back(element_7);
		success_9 = true;
		pos = repeat_ws_10;
	}
	if (!success_9) {
		return {};
	}
	::ISPA_STD::assign_compatible(uvar_4, shadow_8);
	success_12 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_11 = ((*pos)).template to_node<::ISPA_STD::Node<Types::__WS>>();
		success_12 = true;
		pos++;
	}
	success_14 = false;
	// grammar `@  ( advanced_rule::regular_match::unpack |  SEMICOLON)`: choice; reset match status before selecting an alternative
	success_14 = false;
	auto lookahead_pos_1 = pos;
	switch ((*lookahead_pos_1).kind()) {
		case Tokens::AUTO::id: {
			lookahead_pos_1 = lookahead_pos_1;
			success_16 = false;
			advanced_rule_regular_match_unpack_15 = advanced_rule_regular_match_unpack(lookahead_pos_1);
			if (!(advanced_rule_regular_match_unpack_15.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  advanced_rule::regular_match::unpack");
				return {};
			}
			success_16 = true;
			lookahead_pos_1 = advanced_rule_regular_match_unpack_15.it;
			if (!success_16) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  advanced_rule::regular_match::unpack");
				return {};
			}
			_13 = advanced_rule_regular_match_unpack_15.node;
			success_14 = true;
			break;
		}
		case Tokens::SEMICOLON::id: {
			lookahead_pos_1 = lookahead_pos_1;
			success_18 = false;
			if (!(((*lookahead_pos_1)).template holds<Types::SEMICOLON>())) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  SEMICOLON");
				return {};
			}
			SEMICOLON_17 = ((*lookahead_pos_1)).template to_node<::ISPA_STD::Node<Types::SEMICOLON>>();
			success_18 = true;
			lookahead_pos_1++;
			if (!success_18) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  SEMICOLON");
				return {};
			}
			_13 = SEMICOLON_17;
			success_14 = true;
			break;
		}
	}
	pos = lookahead_pos_1;
	if (!success_14) {
		raise_error(*pos, "ISPA match failure: no LL(k) alternative matched | grammar: @  ( advanced_rule::regular_match::unpack |  SEMICOLON)");
		return {};
	}
	Types::advanced_rule::regular_match result;
	::ISPA_STD::assign_compatible(result.patterns, uvar_4);
	::ISPA_STD::assign_compatible(result.assign_names, _13);
	::ISPA_STD::MatchResult<Types::advanced_rule::regular_match, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::advanced_rule_regular_match<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::advanced_rule::regular_match, ::Parser::Lexer::iterator>;
template auto Parser::Parser::advanced_rule_regular_match<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::advanced_rule::regular_match, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::advanced_rule_regular_match_unpack(IT pos) -> ::ISPA_STD::MatchResult<Types::advanced_rule::regular_match::unpack, IT> {
	::ISPA_STD::Node<Types::AUTO> AUTO_0;
	bool success_1;
	::ISPA_STD::Node<Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::Node<Types::ID> ID_5;
	bool success_6;
	std::vector<::ISPA_STD::Node<Types::ID>> uvar_4;
	std::vector<::ISPA_STD::Node<Types::ID>> shadow_7;
	bool success_8;
	success_1 = false;
	if (!(((*pos)).template holds<Types::AUTO>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  AUTO");
		return {};
	}
	AUTO_0 = ((*pos)).template to_node<::ISPA_STD::Node<Types::AUTO>>();
	success_1 = true;
	pos++;
	success_3 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_2 = ((*pos)).template to_node<::ISPA_STD::Node<Types::__WS>>();
		success_3 = true;
		pos++;
	}
	success_6 = false;
	success_8 = false;
	while (((*pos)).template holds<Types::ID>()) {
		ID_5 = ((*pos)).template to_node<::ISPA_STD::Node<Types::ID>>();
		success_6 = true;
		pos++;
		shadow_7.push_back(ID_5);
		success_8 = true;
	}
	if (!success_8) {
		return {};
	}
	// grammar `@  ID+;`: repeat token; export all matched elements
	::ISPA_STD::assign_compatible(uvar_4, shadow_7);
	Types::advanced_rule::regular_match::unpack result;
	::ISPA_STD::assign_compatible(result.value, uvar_4);
	::ISPA_STD::MatchResult<Types::advanced_rule::regular_match::unpack, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::advanced_rule_regular_match_unpack<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::advanced_rule::regular_match::unpack, ::Parser::Lexer::iterator>;
template auto Parser::Parser::advanced_rule_regular_match_unpack<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::advanced_rule::regular_match::unpack, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::explicit_expr(IT pos) -> ::ISPA_STD::MatchResult<Types::explicit_expr, IT> {
	::ISPA_STD::Node<Types::LEFT_PARENTHESIS> LEFT_PARENTHESIS_0;
	bool success_1;
	::ISPA_STD::Node<Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::MatchResult<Types::expr, IT> expr_4;
	bool success_5;
	::ISPA_STD::Node<Types::__WS> __WS_6;
	bool success_7;
	::ISPA_STD::Node<Types::RIGHT_PARENTHESIS> RIGHT_PARENTHESIS_8;
	bool success_9;
	success_1 = false;
	if (!(((*pos)).template holds<Types::LEFT_PARENTHESIS>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  LEFT_PARENTHESIS");
		return {};
	}
	LEFT_PARENTHESIS_0 = ((*pos)).template to_node<::ISPA_STD::Node<Types::LEFT_PARENTHESIS>>();
	success_1 = true;
	pos++;
	success_3 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_2 = ((*pos)).template to_node<::ISPA_STD::Node<Types::__WS>>();
		success_3 = true;
		pos++;
	}
	success_5 = false;
	expr_4 = expr(pos);
	if (!(expr_4.status)) {
		raise_error(*pos, "ISPA match failure: required named rule did not match | grammar: @  expr");
		return {};
	}
	success_5 = true;
	pos = expr_4.it;
	success_7 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_6 = ((*pos)).template to_node<::ISPA_STD::Node<Types::__WS>>();
		success_7 = true;
		pos++;
	}
	success_9 = false;
	if (!(((*pos)).template holds<Types::RIGHT_PARENTHESIS>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  RIGHT_PARENTHESIS");
		return {};
	}
	RIGHT_PARENTHESIS_8 = ((*pos)).template to_node<::ISPA_STD::Node<Types::RIGHT_PARENTHESIS>>();
	success_9 = true;
	pos++;
	Types::explicit_expr result;
	::ISPA_STD::assign_compatible(result.value, expr_4.node);
	::ISPA_STD::MatchResult<Types::explicit_expr, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::explicit_expr<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::explicit_expr, ::Parser::Lexer::iterator>;
template auto Parser::Parser::explicit_expr<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::explicit_expr, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::expr(IT pos) -> ::ISPA_STD::MatchResult<Types::expr, IT> {
	::ISPA_STD::Node<Types::PY_RAW> PY_RAW_0;
	bool success_1;
	success_1 = false;
	if (!(((*pos)).template holds<Types::PY_RAW>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar: @  PY_RAW");
		return {};
	}
	PY_RAW_0 = ((*pos)).template to_node<::ISPA_STD::Node<Types::PY_RAW>>();
	success_1 = true;
	pos++;
	Types::expr result;
	::ISPA_STD::assign_compatible(result.value, PY_RAW_0);
	::ISPA_STD::MatchResult<Types::expr, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::expr<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::expr, ::Parser::Lexer::iterator>;
template auto Parser::Parser::expr<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::expr, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::fail_block(IT pos) -> ::ISPA_STD::MatchResult<Types::fail_block, IT> {
	::ISPA_STD::Node<Types::FAIL> FAIL_0;
	bool success_1;
	::ISPA_STD::Node<Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::MatchResult<Types::name, IT> name_4;
	bool success_5;
	::ISPA_STD::Node<Types::__WS> __WS_6;
	bool success_7;
	::ISPA_STD::MatchResult<Types::stmt, IT> stmt_8;
	bool success_9;
	success_1 = false;
	if (!(((*pos)).template holds<Types::FAIL>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  FAIL");
		return {};
	}
	FAIL_0 = ((*pos)).template to_node<::ISPA_STD::Node<Types::FAIL>>();
	success_1 = true;
	pos++;
	success_3 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_2 = ((*pos)).template to_node<::ISPA_STD::Node<Types::__WS>>();
		success_3 = true;
		pos++;
	}
	success_5 = false;
	name_4 = name(pos);
	if (!(name_4.status)) {
		raise_error(*pos, "ISPA match failure: required named rule did not match | grammar: @  name");
		return {};
	}
	success_5 = true;
	pos = name_4.it;
	success_7 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_6 = ((*pos)).template to_node<::ISPA_STD::Node<Types::__WS>>();
		success_7 = true;
		pos++;
	}
	success_9 = false;
	stmt_8 = stmt(pos);
	if (!(stmt_8.status)) {
		raise_error(*pos, "ISPA match failure: required named rule did not match | grammar: @  stmt");
		return {};
	}
	success_9 = true;
	pos = stmt_8.it;
	Types::fail_block result;
	::ISPA_STD::assign_compatible(result.name, name_4);
	::ISPA_STD::assign_compatible(result.val, stmt_8);
	::ISPA_STD::MatchResult<Types::fail_block, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::fail_block<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::fail_block, ::Parser::Lexer::iterator>;
template auto Parser::Parser::fail_block<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::fail_block, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::forward_declaration(IT pos) -> ::ISPA_STD::MatchResult<Types::forward_declaration, IT> {
	::ISPA_STD::Node<Types::AUTO> AUTO_0;
	bool success_1;
	::ISPA_STD::Node<Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::Node<Types::ID> ID_4;
	bool success_5;
	::ISPA_STD::Node<Types::__WS> __WS_6;
	bool success_7;
	::ISPA_STD::Node<Types::AUTO> AUTO_8;
	bool success_9;
	success_1 = false;
	if (!(((*pos)).template holds<Types::AUTO>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  AUTO");
		return {};
	}
	AUTO_0 = ((*pos)).template to_node<::ISPA_STD::Node<Types::AUTO>>();
	success_1 = true;
	pos++;
	success_3 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_2 = ((*pos)).template to_node<::ISPA_STD::Node<Types::__WS>>();
		success_3 = true;
		pos++;
	}
	success_5 = false;
	if (!(((*pos)).template holds<Types::ID>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar: @  ID");
		return {};
	}
	ID_4 = ((*pos)).template to_node<::ISPA_STD::Node<Types::ID>>();
	success_5 = true;
	pos++;
	success_7 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_6 = ((*pos)).template to_node<::ISPA_STD::Node<Types::__WS>>();
		success_7 = true;
		pos++;
	}
	success_9 = false;
	if (!(((*pos)).template holds<Types::AUTO>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  AUTO");
		return {};
	}
	AUTO_8 = ((*pos)).template to_node<::ISPA_STD::Node<Types::AUTO>>();
	success_9 = true;
	pos++;
	Types::forward_declaration result;
	::ISPA_STD::assign_compatible(result.value, ID_4);
	::ISPA_STD::MatchResult<Types::forward_declaration, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::forward_declaration<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::forward_declaration, ::Parser::Lexer::iterator>;
template auto Parser::Parser::forward_declaration<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::forward_declaration, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::grammar(IT pos) -> ::ISPA_STD::MatchResult<Types::grammar, IT> {
	::ISPA_STD::MatchResult<Types::grammar::modifier, IT> grammar_modifier_1;
	bool success_2;
	::ISPA_STD::Node<Types::grammar::modifier> element_3;
	std::vector<::ISPA_STD::Node<Types::grammar::modifier>> shadow_4;
	std::vector<::ISPA_STD::Node<Types::grammar::modifier>> uvar_0;
	::ISPA_STD::Node<Types::__WS> __WS_5;
	bool success_6;
	::ISPA_STD::MatchResult<Types::name, IT> name_7;
	bool success_8;
	::ISPA_STD::Node<Types::__WS> __WS_9;
	bool success_10;
	std::variant<std::monostate, ::ISPA_STD::Node<Types::advanced_rule>, ::ISPA_STD::Node<Types::rule>> _11;
	bool success_12;
	::ISPA_STD::MatchResult<Types::rule, IT> rule_13;
	bool success_14;
	::ISPA_STD::MatchResult<Types::advanced_rule, IT> advanced_rule_15;
	bool success_16;
	success_2 = false;
	// grammar `@  grammar::modifier*;`: repeat named rule; collect every matched value
	while (true) {
		grammar_modifier_1 = grammar_modifier(pos);
		if (!(grammar_modifier_1.status)) {
			break;
		}
		success_2 = true;
		pos = grammar_modifier_1.it;
		element_3 = grammar_modifier_1.node;
		shadow_4.push_back(element_3);
	}
	::ISPA_STD::assign_compatible(uvar_0, shadow_4);
	success_6 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_5 = ((*pos)).template to_node<::ISPA_STD::Node<Types::__WS>>();
		success_6 = true;
		pos++;
	}
	success_8 = false;
	name_7 = name(pos);
	if (!(name_7.status)) {
		raise_error(*pos, "ISPA match failure: required named rule did not match | grammar: @  name");
		return {};
	}
	success_8 = true;
	pos = name_7.it;
	success_10 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_9 = ((*pos)).template to_node<::ISPA_STD::Node<Types::__WS>>();
		success_10 = true;
		pos++;
	}
	success_12 = false;
	// grammar `@  ( rule |  advanced_rule)`: choice; reset match status before selecting an alternative
	success_12 = false;
	auto lookahead_pos_1 = pos;
	switch ((*lookahead_pos_1).kind()) {
		case Tokens::COLON::id: {
			lookahead_pos_1 = lookahead_pos_1;
			success_14 = false;
			rule_13 = rule(lookahead_pos_1);
			if (!(rule_13.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  rule");
				return {};
			}
			success_14 = true;
			lookahead_pos_1 = rule_13.it;
			if (!success_14) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  rule");
				return {};
			}
			_11 = rule_13.node;
			success_12 = true;
			break;
		}
		case Tokens::LEFT_CURLY_BRACKET::id: {
			lookahead_pos_1 = lookahead_pos_1;
			success_16 = false;
			advanced_rule_15 = advanced_rule(lookahead_pos_1);
			if (!(advanced_rule_15.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  advanced_rule");
				return {};
			}
			success_16 = true;
			lookahead_pos_1 = advanced_rule_15.it;
			if (!success_16) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  advanced_rule");
				return {};
			}
			_11 = advanced_rule_15.node;
			success_12 = true;
			break;
		}
	}
	pos = lookahead_pos_1;
	if (!success_12) {
		raise_error(*pos, "ISPA match failure: no LL(k) alternative matched | grammar: @  ( rule |  advanced_rule)");
		return {};
	}
	Types::grammar result;
	::ISPA_STD::assign_compatible(result.mod, uvar_0);
	::ISPA_STD::assign_compatible(result.name, name_7);
	::ISPA_STD::assign_compatible(result.entry, _11);
	::ISPA_STD::MatchResult<Types::grammar, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::grammar<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::grammar, ::Parser::Lexer::iterator>;
template auto Parser::Parser::grammar<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::grammar, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::grammar_modifier(IT pos) -> ::ISPA_STD::MatchResult<Types::grammar::modifier, IT> {
	::ISPA_STD::Node<Types::grammar::modifier::AUTO> grammar_modifier_AUTO_0;
	bool success_1;
	::ISPA_STD::Node<Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::Node<Types::grammar::modifier::MOD> grammar_modifier_MOD_4;
	bool success_5;
	::ISPA_STD::Node<Types::__WS> __WS_6;
	bool success_7;
	::ISPA_STD::Node<Types::grammar::modifier::RIGHT_SQUARE_BRACKET> grammar_modifier_RIGHT_SQUARE_BRACKET_8;
	bool success_9;
	success_1 = false;
	if (!(((*pos)).template holds<Types::grammar::modifier::AUTO>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  grammar::modifier::AUTO");
		return {};
	}
	grammar_modifier_AUTO_0 = ((*pos)).template to_node<::ISPA_STD::Node<Types::grammar::modifier::AUTO>>();
	success_1 = true;
	pos++;
	success_3 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_2 = ((*pos)).template to_node<::ISPA_STD::Node<Types::__WS>>();
		success_3 = true;
		pos++;
	}
	success_5 = false;
	if (!(((*pos)).template holds<Types::grammar::modifier::MOD>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar: @  grammar::modifier::MOD");
		return {};
	}
	grammar_modifier_MOD_4 = ((*pos)).template to_node<::ISPA_STD::Node<Types::grammar::modifier::MOD>>();
	success_5 = true;
	pos++;
	success_7 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_6 = ((*pos)).template to_node<::ISPA_STD::Node<Types::__WS>>();
		success_7 = true;
		pos++;
	}
	success_9 = false;
	if (!(((*pos)).template holds<Types::grammar::modifier::RIGHT_SQUARE_BRACKET>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  grammar::modifier::RIGHT_SQUARE_BRACKET");
		return {};
	}
	grammar_modifier_RIGHT_SQUARE_BRACKET_8 = ((*pos)).template to_node<::ISPA_STD::Node<Types::grammar::modifier::RIGHT_SQUARE_BRACKET>>();
	success_9 = true;
	pos++;
	Types::grammar::modifier result;
	::ISPA_STD::assign_compatible(result.value, grammar_modifier_MOD_4);
	::ISPA_STD::MatchResult<Types::grammar::modifier, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::grammar_modifier<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::grammar::modifier, ::Parser::Lexer::iterator>;
template auto Parser::Parser::grammar_modifier<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::grammar::modifier, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::main(IT pos) -> ::ISPA_STD::MatchResult<Types::main, IT> {
	bool success_4;
	std::variant<std::monostate, ::ISPA_STD::Node<Types::fail_block>, ::ISPA_STD::Node<Types::grammar>> group_0;
	bool success_2;
	std::vector<std::variant<std::monostate, ::ISPA_STD::Node<Types::fail_block>, ::ISPA_STD::Node<Types::grammar>>> shadow_20;
	std::vector<std::variant<std::monostate, ::ISPA_STD::Node<Types::fail_block>, ::ISPA_STD::Node<Types::grammar>>> uvar_1;
	std::variant<std::monostate, ::ISPA_STD::Node<Types::fail_block>, ::ISPA_STD::Node<Types::grammar>> _3;
	::ISPA_STD::MatchResult<Types::fail_block, IT> fail_block_6;
	bool success_7;
	::ISPA_STD::Node<Types::fail_block> element_8;
	std::vector<::ISPA_STD::Node<Types::fail_block>> shadow_9;
	::ISPA_STD::Node<Types::fail_block> uvar_5;
	::ISPA_STD::MatchResult<Types::grammar, IT> grammar_11;
	bool success_12;
	::ISPA_STD::Node<Types::grammar> element_13;
	std::vector<::ISPA_STD::Node<Types::grammar>> shadow_14;
	::ISPA_STD::Node<Types::grammar> uvar_10;
	::ISPA_STD::MatchResult<Types::grammar, IT> grammar_16;
	bool success_17;
	::ISPA_STD::Node<Types::grammar> element_18;
	std::vector<::ISPA_STD::Node<Types::grammar>> shadow_19;
	::ISPA_STD::Node<Types::grammar> uvar_15;
	success_2 = false;
	auto begin_21 = pos;
	while (true) {
		skip_spaces<Types::__WS>(begin_21);
		// grammar ` ( grammar |  fail_block)`: choice; reset match status before selecting an alternative
		success_4 = false;
		auto lookahead_pos_1 = begin_21;
		switch ((*lookahead_pos_1).kind()) {
			case Tokens::FAIL::id: {
				lookahead_pos_1 = lookahead_pos_1;
				success_7 = false;
				fail_block_6 = fail_block(lookahead_pos_1);
				if (!(fail_block_6.status)) {
					// speculative match failed (diagnostic suppressed):  fail_block
					break;
				}
				success_7 = true;
				lookahead_pos_1 = fail_block_6.it;
				element_8 = fail_block_6.node;
				shadow_9.push_back(element_8);
				if (!success_7) {
					// speculative match failed (diagnostic suppressed):  fail_block
					break;
				}
				_3 = fail_block_6.node;
				success_4 = true;
				break;
			}
			case Tokens::ID::id: {
				lookahead_pos_1 = lookahead_pos_1;
				success_12 = false;
				grammar_11 = grammar(lookahead_pos_1);
				if (!(grammar_11.status)) {
					// speculative match failed (diagnostic suppressed):  grammar
					break;
				}
				success_12 = true;
				lookahead_pos_1 = grammar_11.it;
				element_13 = grammar_11.node;
				shadow_14.push_back(element_13);
				if (!success_12) {
					// speculative match failed (diagnostic suppressed):  grammar
					break;
				}
				_3 = grammar_11.node;
				success_4 = true;
				break;
			}
			case Tokens::grammar::modifier::AUTO::id: {
				lookahead_pos_1 = lookahead_pos_1;
				success_17 = false;
				grammar_16 = grammar(lookahead_pos_1);
				if (!(grammar_16.status)) {
					// speculative match failed (diagnostic suppressed):  grammar
					break;
				}
				success_17 = true;
				lookahead_pos_1 = grammar_16.it;
				element_18 = grammar_16.node;
				shadow_19.push_back(element_18);
				if (!success_17) {
					// speculative match failed (diagnostic suppressed):  grammar
					break;
				}
				_3 = grammar_16.node;
				success_4 = true;
				break;
			}
		}
		begin_21 = lookahead_pos_1;
		if (!success_4) {
			// speculative match failed (diagnostic suppressed):  ( grammar |  fail_block)
			break;
		}
		if (success_4) {
			group_0 = _3;
			shadow_20.push_back(group_0);
		}
	}
	success_2 = true;
	::ISPA_STD::assign_compatible(uvar_1, shadow_20);
	pos = begin_21;
	Types::main result;
	::ISPA_STD::assign_compatible(result.value, uvar_1);
	::ISPA_STD::MatchResult<Types::main, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::main<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::main, ::Parser::Lexer::iterator>;
template auto Parser::Parser::main<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::main, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::name(IT pos) -> ::ISPA_STD::MatchResult<Types::name, IT> {
	::ISPA_STD::Node<Types::ID> ID_0;
	bool success_1;
	bool success_17;
	bool success_9;
	std::vector<::ISPA_STD::Node<Types::AUTO>> shadow_19;
	std::vector<::ISPA_STD::Node<Types::ID>> shadow_20;
	std::tuple<::ISPA_STD::Node<Types::AUTO>, ::ISPA_STD::Node<Types::__WS>, ::ISPA_STD::Node<Types::ID>> group_4;
	bool success_6;
	std::vector<std::tuple<::ISPA_STD::Node<Types::AUTO>, ::ISPA_STD::Node<Types::__WS>, ::ISPA_STD::Node<Types::ID>>> shadow_21;
	std::vector<std::tuple<::ISPA_STD::Node<Types::AUTO>, ::ISPA_STD::Node<Types::__WS>, ::ISPA_STD::Node<Types::ID>>> uvar_5;
	::ISPA_STD::Node<Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::Node<Types::AUTO> AUTO_8;
	::ISPA_STD::Node<Types::AUTO> uvar_7;
	std::vector<::ISPA_STD::Node<Types::AUTO>> shadow_10;
	::ISPA_STD::Node<Types::__WS> __WS_12;
	bool success_13;
	::ISPA_STD::Node<Types::__WS> uvar_11;
	std::vector<::ISPA_STD::Node<Types::__WS>> shadow_14;
	::ISPA_STD::Node<Types::ID> ID_16;
	::ISPA_STD::Node<Types::ID> uvar_15;
	std::vector<::ISPA_STD::Node<Types::ID>> shadow_18;
	::ISPA_STD::Node<Types::__WS> __WS_24;
	bool success_25;
	::ISPA_STD::MatchResult<Types::template_params, IT> template_params_26;
	bool success_27;
	::ISPA_STD::Node<Types::__WS> __WS_28;
	bool success_29;
	::ISPA_STD::MatchResult<Types::params, IT> params_30;
	bool success_31;
	success_1 = false;
	if (!(((*pos)).template holds<Types::ID>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar: @  ID");
		return {};
	}
	ID_0 = ((*pos)).template to_node<::ISPA_STD::Node<Types::ID>>();
	success_1 = true;
	pos++;
	success_6 = false;
	auto begin_22 = pos;
	while (true) {
		auto repeat_ws_23 = begin_22;
		success_3 = false;
		if (((*repeat_ws_23)).template holds<Types::__WS>()) {
			__WS_2 = ((*repeat_ws_23)).template to_node<::ISPA_STD::Node<Types::__WS>>();
			success_3 = true;
			repeat_ws_23++;
		}
		if (!(((*repeat_ws_23)).template holds<Types::AUTO>())) {
			// speculative match failed (diagnostic suppressed):  AUTO
			break;
		}
		AUTO_8 = ((*repeat_ws_23)).template to_node<::ISPA_STD::Node<Types::AUTO>>();
		success_9 = true;
		repeat_ws_23++;
		shadow_10.push_back(AUTO_8);
		uvar_7 = AUTO_8;
		success_13 = false;
		if (((*repeat_ws_23)).template holds<Types::__WS>()) {
			__WS_12 = ((*repeat_ws_23)).template to_node<::ISPA_STD::Node<Types::__WS>>();
			success_13 = true;
			repeat_ws_23++;
			shadow_14.push_back(__WS_12);
			uvar_11 = __WS_12;
		}
		if (!(((*repeat_ws_23)).template holds<Types::ID>())) {
			// speculative match failed (diagnostic suppressed): @  ID
			break;
		}
		ID_16 = ((*repeat_ws_23)).template to_node<::ISPA_STD::Node<Types::ID>>();
		success_17 = true;
		repeat_ws_23++;
		shadow_18.push_back(ID_16);
		uvar_15 = ID_16;
		if (success_9 && success_17) {
			group_4 = std::make_tuple(AUTO_8, __WS_12, ID_16);
			shadow_21.push_back(group_4);
			shadow_19.push_back(AUTO_8);
			shadow_20.push_back(ID_16);
		}
		begin_22 = repeat_ws_23;
	}
	success_6 = true;
	::ISPA_STD::assign_compatible(uvar_5, shadow_21);
	pos = begin_22;
	success_25 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_24 = ((*pos)).template to_node<::ISPA_STD::Node<Types::__WS>>();
		success_25 = true;
		pos++;
	}
	success_27 = false;
	template_params_26 = template_params(pos);
	if (template_params_26.status) {
		success_27 = true;
		pos = template_params_26.it;
	}
	success_29 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_28 = ((*pos)).template to_node<::ISPA_STD::Node<Types::__WS>>();
		success_29 = true;
		pos++;
	}
	success_31 = false;
	params_30 = params(pos);
	if (params_30.status) {
		success_31 = true;
		pos = params_30.it;
	}
	Types::name result;
	::ISPA_STD::assign_compatible(result.primary, ID_0);
	::ISPA_STD::assign_compatible(result.nested, shadow_20);
	::ISPA_STD::assign_compatible(result.temp_params, template_params_26);
	::ISPA_STD::assign_compatible(result.param, params_30);
	::ISPA_STD::MatchResult<Types::name, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::name<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::name, ::Parser::Lexer::iterator>;
template auto Parser::Parser::name<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::name, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::param(IT pos) -> ::ISPA_STD::MatchResult<Types::param, IT> {
	::ISPA_STD::Node<Types::ID> ID_0;
	bool success_1;
	bool success_17;
	bool success_9;
	std::vector<::ISPA_STD::Node<Types::COMMA>> shadow_19;
	std::vector<::ISPA_STD::Node<Types::ID>> shadow_20;
	std::tuple<::ISPA_STD::Node<Types::COMMA>, ::ISPA_STD::Node<Types::__WS>, ::ISPA_STD::Node<Types::ID>> group_4;
	bool success_6;
	std::vector<std::tuple<::ISPA_STD::Node<Types::COMMA>, ::ISPA_STD::Node<Types::__WS>, ::ISPA_STD::Node<Types::ID>>> shadow_21;
	std::vector<std::tuple<::ISPA_STD::Node<Types::COMMA>, ::ISPA_STD::Node<Types::__WS>, ::ISPA_STD::Node<Types::ID>>> uvar_5;
	::ISPA_STD::Node<Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::Node<Types::COMMA> COMMA_8;
	::ISPA_STD::Node<Types::COMMA> uvar_7;
	std::vector<::ISPA_STD::Node<Types::COMMA>> shadow_10;
	::ISPA_STD::Node<Types::__WS> __WS_12;
	bool success_13;
	::ISPA_STD::Node<Types::__WS> uvar_11;
	std::vector<::ISPA_STD::Node<Types::__WS>> shadow_14;
	::ISPA_STD::Node<Types::ID> ID_16;
	::ISPA_STD::Node<Types::ID> uvar_15;
	std::vector<::ISPA_STD::Node<Types::ID>> shadow_18;
	success_1 = false;
	if (!(((*pos)).template holds<Types::ID>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar: @  ID");
		return {};
	}
	ID_0 = ((*pos)).template to_node<::ISPA_STD::Node<Types::ID>>();
	success_1 = true;
	pos++;
	success_6 = false;
	auto begin_22 = pos;
	while (true) {
		auto repeat_ws_23 = begin_22;
		success_3 = false;
		if (((*repeat_ws_23)).template holds<Types::__WS>()) {
			__WS_2 = ((*repeat_ws_23)).template to_node<::ISPA_STD::Node<Types::__WS>>();
			success_3 = true;
			repeat_ws_23++;
		}
		if (!(((*repeat_ws_23)).template holds<Types::COMMA>())) {
			// speculative match failed (diagnostic suppressed):  COMMA
			break;
		}
		COMMA_8 = ((*repeat_ws_23)).template to_node<::ISPA_STD::Node<Types::COMMA>>();
		success_9 = true;
		repeat_ws_23++;
		shadow_10.push_back(COMMA_8);
		uvar_7 = COMMA_8;
		success_13 = false;
		if (((*repeat_ws_23)).template holds<Types::__WS>()) {
			__WS_12 = ((*repeat_ws_23)).template to_node<::ISPA_STD::Node<Types::__WS>>();
			success_13 = true;
			repeat_ws_23++;
			shadow_14.push_back(__WS_12);
			uvar_11 = __WS_12;
		}
		if (!(((*repeat_ws_23)).template holds<Types::ID>())) {
			// speculative match failed (diagnostic suppressed): @  ID
			break;
		}
		ID_16 = ((*repeat_ws_23)).template to_node<::ISPA_STD::Node<Types::ID>>();
		success_17 = true;
		repeat_ws_23++;
		shadow_18.push_back(ID_16);
		uvar_15 = ID_16;
		if (success_9 && success_17) {
			group_4 = std::make_tuple(COMMA_8, __WS_12, ID_16);
			shadow_21.push_back(group_4);
			shadow_19.push_back(COMMA_8);
			shadow_20.push_back(ID_16);
		}
		begin_22 = repeat_ws_23;
	}
	success_6 = true;
	::ISPA_STD::assign_compatible(uvar_5, shadow_21);
	pos = begin_22;
	Types::param result;
	::ISPA_STD::assign_compatible(result.first_p, ID_0);
	::ISPA_STD::assign_compatible(result.following_p, shadow_20);
	::ISPA_STD::MatchResult<Types::param, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::param<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::param, ::Parser::Lexer::iterator>;
template auto Parser::Parser::param<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::param, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::params(IT pos) -> ::ISPA_STD::MatchResult<Types::params, IT> {
	::ISPA_STD::Node<Types::LEFT_PARENTHESIS> LEFT_PARENTHESIS_0;
	bool success_1;
	::ISPA_STD::Node<Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::MatchResult<Types::param, IT> param_4;
	bool success_5;
	::ISPA_STD::Node<Types::__WS> __WS_6;
	bool success_7;
	::ISPA_STD::Node<Types::RIGHT_PARENTHESIS> RIGHT_PARENTHESIS_8;
	bool success_9;
	success_1 = false;
	if (!(((*pos)).template holds<Types::LEFT_PARENTHESIS>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  LEFT_PARENTHESIS");
		return {};
	}
	LEFT_PARENTHESIS_0 = ((*pos)).template to_node<::ISPA_STD::Node<Types::LEFT_PARENTHESIS>>();
	success_1 = true;
	pos++;
	success_3 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_2 = ((*pos)).template to_node<::ISPA_STD::Node<Types::__WS>>();
		success_3 = true;
		pos++;
	}
	success_5 = false;
	param_4 = param(pos);
	if (param_4.status) {
		success_5 = true;
		pos = param_4.it;
	}
	success_7 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_6 = ((*pos)).template to_node<::ISPA_STD::Node<Types::__WS>>();
		success_7 = true;
		pos++;
	}
	success_9 = false;
	if (!(((*pos)).template holds<Types::RIGHT_PARENTHESIS>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  RIGHT_PARENTHESIS");
		return {};
	}
	RIGHT_PARENTHESIS_8 = ((*pos)).template to_node<::ISPA_STD::Node<Types::RIGHT_PARENTHESIS>>();
	success_9 = true;
	pos++;
	Types::params result;
	::ISPA_STD::assign_compatible(result.value, param_4.node);
	::ISPA_STD::MatchResult<Types::params, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::params<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::params, ::Parser::Lexer::iterator>;
template auto Parser::Parser::params<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::params, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::rule(IT pos) -> ::ISPA_STD::MatchResult<Types::rule, IT> {
	::ISPA_STD::Node<Types::COLON> COLON_0;
	bool success_1;
	::ISPA_STD::MatchResult<Types::rule::value, IT> rule_value_5;
	bool success_6;
	::ISPA_STD::Node<Types::rule::value> element_7;
	std::vector<::ISPA_STD::Node<Types::rule::value>> shadow_8;
	std::vector<::ISPA_STD::Node<Types::rule::value>> uvar_4;
	bool success_9;
	::ISPA_STD::Node<Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::Node<Types::__WS> __WS_11;
	bool success_12;
	::ISPA_STD::MatchResult<Types::rule::ast, IT> rule_ast_13;
	bool success_14;
	::ISPA_STD::Node<Types::__WS> __WS_15;
	bool success_16;
	::ISPA_STD::MatchResult<Types::rule::f_binding, IT> rule_f_binding_17;
	bool success_18;
	::ISPA_STD::MatchResult<Types::rule::nested_rule, IT> rule_nested_rule_22;
	bool success_23;
	::ISPA_STD::Node<Types::rule::nested_rule> element_24;
	std::vector<::ISPA_STD::Node<Types::rule::nested_rule>> shadow_25;
	std::vector<::ISPA_STD::Node<Types::rule::nested_rule>> uvar_21;
	::ISPA_STD::Node<Types::__WS> __WS_19;
	bool success_20;
	::ISPA_STD::Node<Types::__WS> __WS_27;
	bool success_28;
	::ISPA_STD::Node<Types::SEMICOLON> SEMICOLON_29;
	bool success_30;
	success_1 = false;
	if (!(((*pos)).template holds<Types::COLON>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  COLON");
		return {};
	}
	COLON_0 = ((*pos)).template to_node<::ISPA_STD::Node<Types::COLON>>();
	success_1 = true;
	pos++;
	success_6 = false;
	// grammar `@  rule::value+;`: repeat named rule; collect every matched value
	success_9 = false;
	while (true) {
		auto repeat_ws_10 = pos;
		success_3 = false;
		if (((*repeat_ws_10)).template holds<Types::__WS>()) {
			__WS_2 = ((*repeat_ws_10)).template to_node<::ISPA_STD::Node<Types::__WS>>();
			success_3 = true;
			repeat_ws_10++;
		}
		rule_value_5 = rule_value(repeat_ws_10);
		if (!(rule_value_5.status)) {
			break;
		}
		success_6 = true;
		repeat_ws_10 = rule_value_5.it;
		element_7 = rule_value_5.node;
		shadow_8.push_back(element_7);
		success_9 = true;
		pos = repeat_ws_10;
	}
	if (!success_9) {
		return {};
	}
	::ISPA_STD::assign_compatible(uvar_4, shadow_8);
	success_12 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_11 = ((*pos)).template to_node<::ISPA_STD::Node<Types::__WS>>();
		success_12 = true;
		pos++;
	}
	success_14 = false;
	rule_ast_13 = rule_ast(pos);
	if (rule_ast_13.status) {
		success_14 = true;
		pos = rule_ast_13.it;
	}
	success_16 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_15 = ((*pos)).template to_node<::ISPA_STD::Node<Types::__WS>>();
		success_16 = true;
		pos++;
	}
	success_18 = false;
	rule_f_binding_17 = rule_f_binding(pos);
	if (rule_f_binding_17.status) {
		success_18 = true;
		pos = rule_f_binding_17.it;
	}
	success_23 = false;
	// grammar `@  rule::nested_rule*;`: repeat named rule; collect every matched value
	while (true) {
		auto repeat_ws_26 = pos;
		success_20 = false;
		if (((*repeat_ws_26)).template holds<Types::__WS>()) {
			__WS_19 = ((*repeat_ws_26)).template to_node<::ISPA_STD::Node<Types::__WS>>();
			success_20 = true;
			repeat_ws_26++;
		}
		rule_nested_rule_22 = rule_nested_rule(repeat_ws_26);
		if (!(rule_nested_rule_22.status)) {
			break;
		}
		success_23 = true;
		repeat_ws_26 = rule_nested_rule_22.it;
		element_24 = rule_nested_rule_22.node;
		shadow_25.push_back(element_24);
		pos = repeat_ws_26;
	}
	::ISPA_STD::assign_compatible(uvar_21, shadow_25);
	success_28 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_27 = ((*pos)).template to_node<::ISPA_STD::Node<Types::__WS>>();
		success_28 = true;
		pos++;
	}
	success_30 = false;
	if (!(((*pos)).template holds<Types::SEMICOLON>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  SEMICOLON");
		return {};
	}
	SEMICOLON_29 = ((*pos)).template to_node<::ISPA_STD::Node<Types::SEMICOLON>>();
	success_30 = true;
	pos++;
	Types::rule result;
	::ISPA_STD::assign_compatible(result.v, uvar_4);
	::ISPA_STD::assign_compatible(result.ast_pointer, rule_ast_13);
	::ISPA_STD::assign_compatible(result.fail_pointer, rule_f_binding_17);
	::ISPA_STD::assign_compatible(result.nested, uvar_21);
	::ISPA_STD::MatchResult<Types::rule, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::rule<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::rule, ::Parser::Lexer::iterator>;
template auto Parser::Parser::rule<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::rule, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::rule_ast(IT pos) -> ::ISPA_STD::MatchResult<Types::rule::ast, IT> {
	std::variant<std::monostate, ::ISPA_STD::Node<Types::rule::ast::single_value>, ::ISPA_STD::Node<Types::rule::ast::full>, ::ISPA_STD::Node<Types::rule::ast::abbr>> _0;
	bool success_1;
	::ISPA_STD::MatchResult<Types::rule::ast::full, IT> rule_ast_full_2;
	bool success_3;
	::ISPA_STD::MatchResult<Types::rule::ast::abbr, IT> rule_ast_abbr_4;
	bool success_5;
	::ISPA_STD::MatchResult<Types::rule::ast::single_value, IT> rule_ast_single_value_6;
	bool success_7;
	success_1 = false;
	// grammar `@  ( rule::ast::abbr |  rule::ast::full |  rule::ast::single_value)`: choice; reset match status before selecting an alternative
	success_1 = false;
	auto lookahead_pos_1 = pos;
	switch ((*lookahead_pos_1).kind()) {
		case Tokens::AMPERSAND::id: {
			lookahead_pos_1 = lookahead_pos_1;
			success_3 = false;
			rule_ast_full_2 = rule_ast_full(lookahead_pos_1);
			if (!(rule_ast_full_2.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  rule::ast::full");
				return {};
			}
			success_3 = true;
			lookahead_pos_1 = rule_ast_full_2.it;
			if (!success_3) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  rule::ast::full");
				return {};
			}
			_0 = rule_ast_full_2.node;
			success_1 = true;
			break;
		}
		case Tokens::COMMERCIAL_AT::id: {
			lookahead_pos_1 = lookahead_pos_1;
			success_5 = false;
			rule_ast_abbr_4 = rule_ast_abbr(lookahead_pos_1);
			if (!(rule_ast_abbr_4.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  rule::ast::abbr");
				return {};
			}
			success_5 = true;
			lookahead_pos_1 = rule_ast_abbr_4.it;
			if (!success_5) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  rule::ast::abbr");
				return {};
			}
			_0 = rule_ast_abbr_4.node;
			success_1 = true;
			break;
		}
		case Tokens::LEFT_CURLY_BRACKET::id: {
			lookahead_pos_1 = lookahead_pos_1;
			success_7 = false;
			rule_ast_single_value_6 = rule_ast_single_value(lookahead_pos_1);
			if (!(rule_ast_single_value_6.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  rule::ast::single_value");
				return {};
			}
			success_7 = true;
			lookahead_pos_1 = rule_ast_single_value_6.it;
			if (!success_7) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  rule::ast::single_value");
				return {};
			}
			_0 = rule_ast_single_value_6.node;
			success_1 = true;
			break;
		}
	}
	pos = lookahead_pos_1;
	if (!success_1) {
		raise_error(*pos, "ISPA match failure: no LL(k) alternative matched | grammar: @  ( rule::ast::abbr |  rule::ast::full |  rule::ast::single_value)");
		return {};
	}
	Types::rule::ast result;
	::ISPA_STD::assign_compatible(result.value, _0);
	::ISPA_STD::MatchResult<Types::rule::ast, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::rule_ast<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::rule::ast, ::Parser::Lexer::iterator>;
template auto Parser::Parser::rule_ast<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::rule::ast, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::rule_ast_abbr(IT pos) -> ::ISPA_STD::MatchResult<Types::rule::ast::abbr, IT> {
	::ISPA_STD::Node<Types::COMMERCIAL_AT> COMMERCIAL_AT_0;
	bool success_1;
	::ISPA_STD::Node<Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::Node<Types::LEFT_CURLY_BRACKET> LEFT_CURLY_BRACKET_4;
	bool success_5;
	::ISPA_STD::Node<Types::__WS> __WS_6;
	bool success_7;
	::ISPA_STD::Node<Types::ID> ID_8;
	bool success_9;
	bool success_25;
	bool success_17;
	std::vector<::ISPA_STD::Node<Types::COMMA>> shadow_27;
	std::vector<::ISPA_STD::Node<Types::ID>> shadow_28;
	std::tuple<::ISPA_STD::Node<Types::COMMA>, ::ISPA_STD::Node<Types::__WS>, ::ISPA_STD::Node<Types::ID>> group_12;
	bool success_14;
	std::vector<std::tuple<::ISPA_STD::Node<Types::COMMA>, ::ISPA_STD::Node<Types::__WS>, ::ISPA_STD::Node<Types::ID>>> shadow_29;
	std::vector<std::tuple<::ISPA_STD::Node<Types::COMMA>, ::ISPA_STD::Node<Types::__WS>, ::ISPA_STD::Node<Types::ID>>> uvar_13;
	::ISPA_STD::Node<Types::__WS> __WS_10;
	bool success_11;
	::ISPA_STD::Node<Types::COMMA> COMMA_16;
	::ISPA_STD::Node<Types::COMMA> uvar_15;
	std::vector<::ISPA_STD::Node<Types::COMMA>> shadow_18;
	::ISPA_STD::Node<Types::__WS> __WS_20;
	bool success_21;
	::ISPA_STD::Node<Types::__WS> uvar_19;
	std::vector<::ISPA_STD::Node<Types::__WS>> shadow_22;
	::ISPA_STD::Node<Types::ID> ID_24;
	::ISPA_STD::Node<Types::ID> uvar_23;
	std::vector<::ISPA_STD::Node<Types::ID>> shadow_26;
	::ISPA_STD::Node<Types::__WS> __WS_32;
	bool success_33;
	::ISPA_STD::Node<Types::RIGHT_CURLY_BRACKET> RIGHT_CURLY_BRACKET_34;
	bool success_35;
	success_1 = false;
	if (!(((*pos)).template holds<Types::COMMERCIAL_AT>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  COMMERCIAL_AT");
		return {};
	}
	COMMERCIAL_AT_0 = ((*pos)).template to_node<::ISPA_STD::Node<Types::COMMERCIAL_AT>>();
	success_1 = true;
	pos++;
	success_3 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_2 = ((*pos)).template to_node<::ISPA_STD::Node<Types::__WS>>();
		success_3 = true;
		pos++;
	}
	success_5 = false;
	if (!(((*pos)).template holds<Types::LEFT_CURLY_BRACKET>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  LEFT_CURLY_BRACKET");
		return {};
	}
	LEFT_CURLY_BRACKET_4 = ((*pos)).template to_node<::ISPA_STD::Node<Types::LEFT_CURLY_BRACKET>>();
	success_5 = true;
	pos++;
	success_7 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_6 = ((*pos)).template to_node<::ISPA_STD::Node<Types::__WS>>();
		success_7 = true;
		pos++;
	}
	success_9 = false;
	if (!(((*pos)).template holds<Types::ID>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar: @  ID");
		return {};
	}
	ID_8 = ((*pos)).template to_node<::ISPA_STD::Node<Types::ID>>();
	success_9 = true;
	pos++;
	success_14 = false;
	auto begin_30 = pos;
	while (true) {
		auto repeat_ws_31 = begin_30;
		success_11 = false;
		if (((*repeat_ws_31)).template holds<Types::__WS>()) {
			__WS_10 = ((*repeat_ws_31)).template to_node<::ISPA_STD::Node<Types::__WS>>();
			success_11 = true;
			repeat_ws_31++;
		}
		if (!(((*repeat_ws_31)).template holds<Types::COMMA>())) {
			// speculative match failed (diagnostic suppressed):  COMMA
			break;
		}
		COMMA_16 = ((*repeat_ws_31)).template to_node<::ISPA_STD::Node<Types::COMMA>>();
		success_17 = true;
		repeat_ws_31++;
		shadow_18.push_back(COMMA_16);
		uvar_15 = COMMA_16;
		success_21 = false;
		if (((*repeat_ws_31)).template holds<Types::__WS>()) {
			__WS_20 = ((*repeat_ws_31)).template to_node<::ISPA_STD::Node<Types::__WS>>();
			success_21 = true;
			repeat_ws_31++;
			shadow_22.push_back(__WS_20);
			uvar_19 = __WS_20;
		}
		if (!(((*repeat_ws_31)).template holds<Types::ID>())) {
			// speculative match failed (diagnostic suppressed): @  ID
			break;
		}
		ID_24 = ((*repeat_ws_31)).template to_node<::ISPA_STD::Node<Types::ID>>();
		success_25 = true;
		repeat_ws_31++;
		shadow_26.push_back(ID_24);
		uvar_23 = ID_24;
		if (success_17 && success_25) {
			group_12 = std::make_tuple(COMMA_16, __WS_20, ID_24);
			shadow_29.push_back(group_12);
			shadow_27.push_back(COMMA_16);
			shadow_28.push_back(ID_24);
		}
		begin_30 = repeat_ws_31;
	}
	success_14 = true;
	::ISPA_STD::assign_compatible(uvar_13, shadow_29);
	pos = begin_30;
	success_33 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_32 = ((*pos)).template to_node<::ISPA_STD::Node<Types::__WS>>();
		success_33 = true;
		pos++;
	}
	success_35 = false;
	if (!(((*pos)).template holds<Types::RIGHT_CURLY_BRACKET>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  RIGHT_CURLY_BRACKET");
		return {};
	}
	RIGHT_CURLY_BRACKET_34 = ((*pos)).template to_node<::ISPA_STD::Node<Types::RIGHT_CURLY_BRACKET>>();
	success_35 = true;
	pos++;
	Types::rule::ast::abbr result;
	::ISPA_STD::assign_compatible(result.f, ID_8);
	::ISPA_STD::assign_compatible(result.seq, shadow_28);
	::ISPA_STD::MatchResult<Types::rule::ast::abbr, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::rule_ast_abbr<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::rule::ast::abbr, ::Parser::Lexer::iterator>;
template auto Parser::Parser::rule_ast_abbr<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::rule::ast::abbr, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::rule_ast_full(IT pos) -> ::ISPA_STD::MatchResult<Types::rule::ast::full, IT> {
	::ISPA_STD::Node<Types::AMPERSAND> AMPERSAND_0;
	bool success_1;
	::ISPA_STD::Node<Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::Node<Types::LEFT_CURLY_BRACKET> LEFT_CURLY_BRACKET_4;
	bool success_5;
	::ISPA_STD::MatchResult<Types::rule::ast::full::part, IT> rule_ast_full_part_9;
	bool success_10;
	::ISPA_STD::Node<Types::rule::ast::full::part> element_11;
	std::vector<::ISPA_STD::Node<Types::rule::ast::full::part>> shadow_12;
	std::vector<::ISPA_STD::Node<Types::rule::ast::full::part>> uvar_8;
	bool success_13;
	::ISPA_STD::Node<Types::__WS> __WS_6;
	bool success_7;
	::ISPA_STD::Node<Types::__WS> __WS_15;
	bool success_16;
	::ISPA_STD::Node<Types::RIGHT_CURLY_BRACKET> RIGHT_CURLY_BRACKET_17;
	bool success_18;
	success_1 = false;
	if (!(((*pos)).template holds<Types::AMPERSAND>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  AMPERSAND");
		return {};
	}
	AMPERSAND_0 = ((*pos)).template to_node<::ISPA_STD::Node<Types::AMPERSAND>>();
	success_1 = true;
	pos++;
	success_3 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_2 = ((*pos)).template to_node<::ISPA_STD::Node<Types::__WS>>();
		success_3 = true;
		pos++;
	}
	success_5 = false;
	if (!(((*pos)).template holds<Types::LEFT_CURLY_BRACKET>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  LEFT_CURLY_BRACKET");
		return {};
	}
	LEFT_CURLY_BRACKET_4 = ((*pos)).template to_node<::ISPA_STD::Node<Types::LEFT_CURLY_BRACKET>>();
	success_5 = true;
	pos++;
	success_10 = false;
	// grammar `@  rule::ast::full::part+;`: repeat named rule; collect every matched value
	success_13 = false;
	while (true) {
		auto repeat_ws_14 = pos;
		success_7 = false;
		if (((*repeat_ws_14)).template holds<Types::__WS>()) {
			__WS_6 = ((*repeat_ws_14)).template to_node<::ISPA_STD::Node<Types::__WS>>();
			success_7 = true;
			repeat_ws_14++;
		}
		rule_ast_full_part_9 = rule_ast_full_part(repeat_ws_14);
		if (!(rule_ast_full_part_9.status)) {
			break;
		}
		success_10 = true;
		repeat_ws_14 = rule_ast_full_part_9.it;
		element_11 = rule_ast_full_part_9.node;
		shadow_12.push_back(element_11);
		success_13 = true;
		pos = repeat_ws_14;
	}
	if (!success_13) {
		return {};
	}
	::ISPA_STD::assign_compatible(uvar_8, shadow_12);
	success_16 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_15 = ((*pos)).template to_node<::ISPA_STD::Node<Types::__WS>>();
		success_16 = true;
		pos++;
	}
	success_18 = false;
	if (!(((*pos)).template holds<Types::RIGHT_CURLY_BRACKET>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  RIGHT_CURLY_BRACKET");
		return {};
	}
	RIGHT_CURLY_BRACKET_17 = ((*pos)).template to_node<::ISPA_STD::Node<Types::RIGHT_CURLY_BRACKET>>();
	success_18 = true;
	pos++;
	Types::rule::ast::full result;
	::ISPA_STD::assign_compatible(result.value, uvar_8);
	::ISPA_STD::MatchResult<Types::rule::ast::full, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::rule_ast_full<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::rule::ast::full, ::Parser::Lexer::iterator>;
template auto Parser::Parser::rule_ast_full<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::rule::ast::full, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::rule_ast_full_part(IT pos) -> ::ISPA_STD::MatchResult<Types::rule::ast::full::part, IT> {
	::ISPA_STD::Node<Types::ID> ID_0;
	bool success_1;
	::ISPA_STD::Node<Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::Node<Types::COLON> COLON_4;
	bool success_5;
	::ISPA_STD::Node<Types::__WS> __WS_6;
	bool success_7;
	::ISPA_STD::MatchResult<Types::expr, IT> expr_8;
	bool success_9;
	success_1 = false;
	if (!(((*pos)).template holds<Types::ID>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar: @  ID");
		return {};
	}
	ID_0 = ((*pos)).template to_node<::ISPA_STD::Node<Types::ID>>();
	success_1 = true;
	pos++;
	success_3 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_2 = ((*pos)).template to_node<::ISPA_STD::Node<Types::__WS>>();
		success_3 = true;
		pos++;
	}
	success_5 = false;
	if (!(((*pos)).template holds<Types::COLON>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  COLON");
		return {};
	}
	COLON_4 = ((*pos)).template to_node<::ISPA_STD::Node<Types::COLON>>();
	success_5 = true;
	pos++;
	success_7 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_6 = ((*pos)).template to_node<::ISPA_STD::Node<Types::__WS>>();
		success_7 = true;
		pos++;
	}
	success_9 = false;
	expr_8 = expr(pos);
	if (!(expr_8.status)) {
		raise_error(*pos, "ISPA match failure: required named rule did not match | grammar: @  expr");
		return {};
	}
	success_9 = true;
	pos = expr_8.it;
	Types::rule::ast::full::part result;
	::ISPA_STD::assign_compatible(result.key, ID_0);
	::ISPA_STD::assign_compatible(result.e, expr_8);
	::ISPA_STD::MatchResult<Types::rule::ast::full::part, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::rule_ast_full_part<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::rule::ast::full::part, ::Parser::Lexer::iterator>;
template auto Parser::Parser::rule_ast_full_part<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::rule::ast::full::part, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::rule_ast_single_value(IT pos) -> ::ISPA_STD::MatchResult<Types::rule::ast::single_value, IT> {
	::ISPA_STD::Node<Types::LEFT_CURLY_BRACKET> LEFT_CURLY_BRACKET_0;
	bool success_1;
	::ISPA_STD::Node<Types::__WS> __WS_2;
	bool success_3;
	std::variant<std::monostate, ::ISPA_STD::Node<Types::COMMERCIAL_AT>, ::ISPA_STD::Node<Types::expr>> _4;
	bool success_5;
	::ISPA_STD::Node<Types::COMMERCIAL_AT> COMMERCIAL_AT_6;
	bool success_7;
	::ISPA_STD::MatchResult<Types::expr, IT> expr_8;
	bool success_9;
	::ISPA_STD::Node<Types::__WS> __WS_10;
	bool success_11;
	::ISPA_STD::Node<Types::RIGHT_CURLY_BRACKET> RIGHT_CURLY_BRACKET_12;
	bool success_13;
	success_1 = false;
	if (!(((*pos)).template holds<Types::LEFT_CURLY_BRACKET>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  LEFT_CURLY_BRACKET");
		return {};
	}
	LEFT_CURLY_BRACKET_0 = ((*pos)).template to_node<::ISPA_STD::Node<Types::LEFT_CURLY_BRACKET>>();
	success_1 = true;
	pos++;
	success_3 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_2 = ((*pos)).template to_node<::ISPA_STD::Node<Types::__WS>>();
		success_3 = true;
		pos++;
	}
	success_5 = false;
	// grammar `@  ( expr |  COMMERCIAL_AT)`: choice; reset match status before selecting an alternative
	success_5 = false;
	auto lookahead_pos_1 = pos;
	switch ((*lookahead_pos_1).kind()) {
		case Tokens::COMMERCIAL_AT::id: {
			lookahead_pos_1 = lookahead_pos_1;
			success_7 = false;
			if (!(((*lookahead_pos_1)).template holds<Types::COMMERCIAL_AT>())) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  COMMERCIAL_AT");
				return {};
			}
			COMMERCIAL_AT_6 = ((*lookahead_pos_1)).template to_node<::ISPA_STD::Node<Types::COMMERCIAL_AT>>();
			success_7 = true;
			lookahead_pos_1++;
			if (!success_7) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  COMMERCIAL_AT");
				return {};
			}
			_4 = COMMERCIAL_AT_6;
			success_5 = true;
			break;
		}
		case Tokens::PY_RAW::id: {
			lookahead_pos_1 = lookahead_pos_1;
			success_9 = false;
			expr_8 = expr(lookahead_pos_1);
			if (!(expr_8.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  expr");
				return {};
			}
			success_9 = true;
			lookahead_pos_1 = expr_8.it;
			if (!success_9) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  expr");
				return {};
			}
			_4 = expr_8.node;
			success_5 = true;
			break;
		}
	}
	pos = lookahead_pos_1;
	if (!success_5) {
		raise_error(*pos, "ISPA match failure: no LL(k) alternative matched | grammar: @  ( expr |  COMMERCIAL_AT)");
		return {};
	}
	success_11 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_10 = ((*pos)).template to_node<::ISPA_STD::Node<Types::__WS>>();
		success_11 = true;
		pos++;
	}
	success_13 = false;
	if (!(((*pos)).template holds<Types::RIGHT_CURLY_BRACKET>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  RIGHT_CURLY_BRACKET");
		return {};
	}
	RIGHT_CURLY_BRACKET_12 = ((*pos)).template to_node<::ISPA_STD::Node<Types::RIGHT_CURLY_BRACKET>>();
	success_13 = true;
	pos++;
	Types::rule::ast::single_value result;
	::ISPA_STD::assign_compatible(result.value, _4);
	::ISPA_STD::MatchResult<Types::rule::ast::single_value, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::rule_ast_single_value<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::rule::ast::single_value, ::Parser::Lexer::iterator>;
template auto Parser::Parser::rule_ast_single_value<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::rule::ast::single_value, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::rule_f_binding(IT pos) -> ::ISPA_STD::MatchResult<Types::rule::f_binding, IT> {
	::ISPA_STD::Node<Types::PERCENT_SIGN> PERCENT_SIGN_0;
	bool success_1;
	::ISPA_STD::Node<Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::Node<Types::LEFT_CURLY_BRACKET> LEFT_CURLY_BRACKET_4;
	bool success_5;
	::ISPA_STD::Node<Types::__WS> __WS_6;
	bool success_7;
	::ISPA_STD::Node<Types::ID> ID_8;
	bool success_9;
	bool success_25;
	bool success_17;
	std::vector<::ISPA_STD::Node<Types::COMMA>> shadow_27;
	std::vector<::ISPA_STD::Node<Types::ID>> shadow_28;
	std::tuple<::ISPA_STD::Node<Types::COMMA>, ::ISPA_STD::Node<Types::__WS>, ::ISPA_STD::Node<Types::ID>> group_12;
	bool success_14;
	std::vector<std::tuple<::ISPA_STD::Node<Types::COMMA>, ::ISPA_STD::Node<Types::__WS>, ::ISPA_STD::Node<Types::ID>>> shadow_29;
	std::vector<std::tuple<::ISPA_STD::Node<Types::COMMA>, ::ISPA_STD::Node<Types::__WS>, ::ISPA_STD::Node<Types::ID>>> uvar_13;
	::ISPA_STD::Node<Types::__WS> __WS_10;
	bool success_11;
	::ISPA_STD::Node<Types::COMMA> COMMA_16;
	::ISPA_STD::Node<Types::COMMA> uvar_15;
	std::vector<::ISPA_STD::Node<Types::COMMA>> shadow_18;
	::ISPA_STD::Node<Types::__WS> __WS_20;
	bool success_21;
	::ISPA_STD::Node<Types::__WS> uvar_19;
	std::vector<::ISPA_STD::Node<Types::__WS>> shadow_22;
	::ISPA_STD::Node<Types::ID> ID_24;
	::ISPA_STD::Node<Types::ID> uvar_23;
	std::vector<::ISPA_STD::Node<Types::ID>> shadow_26;
	::ISPA_STD::Node<Types::__WS> __WS_32;
	bool success_33;
	::ISPA_STD::Node<Types::RIGHT_CURLY_BRACKET> RIGHT_CURLY_BRACKET_34;
	bool success_35;
	success_1 = false;
	if (!(((*pos)).template holds<Types::PERCENT_SIGN>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  PERCENT_SIGN");
		return {};
	}
	PERCENT_SIGN_0 = ((*pos)).template to_node<::ISPA_STD::Node<Types::PERCENT_SIGN>>();
	success_1 = true;
	pos++;
	success_3 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_2 = ((*pos)).template to_node<::ISPA_STD::Node<Types::__WS>>();
		success_3 = true;
		pos++;
	}
	success_5 = false;
	if (!(((*pos)).template holds<Types::LEFT_CURLY_BRACKET>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  LEFT_CURLY_BRACKET");
		return {};
	}
	LEFT_CURLY_BRACKET_4 = ((*pos)).template to_node<::ISPA_STD::Node<Types::LEFT_CURLY_BRACKET>>();
	success_5 = true;
	pos++;
	success_7 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_6 = ((*pos)).template to_node<::ISPA_STD::Node<Types::__WS>>();
		success_7 = true;
		pos++;
	}
	success_9 = false;
	if (!(((*pos)).template holds<Types::ID>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar: @  ID");
		return {};
	}
	ID_8 = ((*pos)).template to_node<::ISPA_STD::Node<Types::ID>>();
	success_9 = true;
	pos++;
	success_14 = false;
	auto begin_30 = pos;
	while (true) {
		auto repeat_ws_31 = begin_30;
		success_11 = false;
		if (((*repeat_ws_31)).template holds<Types::__WS>()) {
			__WS_10 = ((*repeat_ws_31)).template to_node<::ISPA_STD::Node<Types::__WS>>();
			success_11 = true;
			repeat_ws_31++;
		}
		if (!(((*repeat_ws_31)).template holds<Types::COMMA>())) {
			// speculative match failed (diagnostic suppressed):  COMMA
			break;
		}
		COMMA_16 = ((*repeat_ws_31)).template to_node<::ISPA_STD::Node<Types::COMMA>>();
		success_17 = true;
		repeat_ws_31++;
		shadow_18.push_back(COMMA_16);
		uvar_15 = COMMA_16;
		success_21 = false;
		if (((*repeat_ws_31)).template holds<Types::__WS>()) {
			__WS_20 = ((*repeat_ws_31)).template to_node<::ISPA_STD::Node<Types::__WS>>();
			success_21 = true;
			repeat_ws_31++;
			shadow_22.push_back(__WS_20);
			uvar_19 = __WS_20;
		}
		if (!(((*repeat_ws_31)).template holds<Types::ID>())) {
			// speculative match failed (diagnostic suppressed): @  ID
			break;
		}
		ID_24 = ((*repeat_ws_31)).template to_node<::ISPA_STD::Node<Types::ID>>();
		success_25 = true;
		repeat_ws_31++;
		shadow_26.push_back(ID_24);
		uvar_23 = ID_24;
		if (success_17 && success_25) {
			group_12 = std::make_tuple(COMMA_16, __WS_20, ID_24);
			shadow_29.push_back(group_12);
			shadow_27.push_back(COMMA_16);
			shadow_28.push_back(ID_24);
		}
		begin_30 = repeat_ws_31;
	}
	success_14 = true;
	::ISPA_STD::assign_compatible(uvar_13, shadow_29);
	pos = begin_30;
	success_33 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_32 = ((*pos)).template to_node<::ISPA_STD::Node<Types::__WS>>();
		success_33 = true;
		pos++;
	}
	success_35 = false;
	if (!(((*pos)).template holds<Types::RIGHT_CURLY_BRACKET>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  RIGHT_CURLY_BRACKET");
		return {};
	}
	RIGHT_CURLY_BRACKET_34 = ((*pos)).template to_node<::ISPA_STD::Node<Types::RIGHT_CURLY_BRACKET>>();
	success_35 = true;
	pos++;
	Types::rule::f_binding result;
	::ISPA_STD::assign_compatible(result.f, ID_8);
	::ISPA_STD::assign_compatible(result.seq, shadow_28);
	::ISPA_STD::MatchResult<Types::rule::f_binding, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::rule_f_binding<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::rule::f_binding, ::Parser::Lexer::iterator>;
template auto Parser::Parser::rule_f_binding<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::rule::f_binding, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::rule_nested_rule(IT pos) -> ::ISPA_STD::MatchResult<Types::rule::nested_rule, IT> {
	::ISPA_STD::Node<Types::rule::nested_rule::NUMBER_SIGN> rule_nested_rule_NUMBER_SIGN_0;
	bool success_1;
	::ISPA_STD::MatchResult<Types::grammar, IT> grammar_2;
	bool success_3;
	success_1 = false;
	if (!(((*pos)).template holds<Types::rule::nested_rule::NUMBER_SIGN>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  rule::nested_rule::NUMBER_SIGN");
		return {};
	}
	rule_nested_rule_NUMBER_SIGN_0 = ((*pos)).template to_node<::ISPA_STD::Node<Types::rule::nested_rule::NUMBER_SIGN>>();
	success_1 = true;
	pos++;
	success_3 = false;
	grammar_2 = grammar(pos);
	if (!(grammar_2.status)) {
		raise_error(*pos, "ISPA match failure: required named rule did not match | grammar: @  grammar");
		return {};
	}
	success_3 = true;
	pos = grammar_2.it;
	Types::rule::nested_rule result;
	::ISPA_STD::assign_compatible(result.value, grammar_2.node);
	::ISPA_STD::MatchResult<Types::rule::nested_rule, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::rule_nested_rule<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::rule::nested_rule, ::Parser::Lexer::iterator>;
template auto Parser::Parser::rule_nested_rule<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::rule::nested_rule, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::rule_value(IT pos) -> ::ISPA_STD::MatchResult<Types::rule::value, IT> {
	std::variant<std::monostate, ::ISPA_STD::Node<Types::rule::value::mul_capture>, ::ISPA_STD::Node<Types::rule::value::one_capture>> _0;
	bool success_1;
	::ISPA_STD::MatchResult<Types::rule::value::one_capture, IT> rule_value_one_capture_2;
	bool success_3;
	::ISPA_STD::MatchResult<Types::rule::value::mul_capture, IT> rule_value_mul_capture_4;
	bool success_5;
	::ISPA_STD::MatchResult<Types::rule::value::one_capture, IT> rule_value_one_capture_6;
	bool success_7;
	::ISPA_STD::MatchResult<Types::rule::value::one_capture, IT> rule_value_one_capture_8;
	bool success_9;
	::ISPA_STD::MatchResult<Types::rule::value::one_capture, IT> rule_value_one_capture_10;
	bool success_11;
	::ISPA_STD::MatchResult<Types::rule::value::one_capture, IT> rule_value_one_capture_12;
	bool success_13;
	::ISPA_STD::MatchResult<Types::rule::value::one_capture, IT> rule_value_one_capture_14;
	bool success_15;
	::ISPA_STD::MatchResult<Types::rule::value::one_capture, IT> rule_value_one_capture_16;
	bool success_17;
	::ISPA_STD::MatchResult<Types::rule::value::one_capture, IT> rule_value_one_capture_18;
	bool success_19;
	::ISPA_STD::MatchResult<Types::rule::value::one_capture, IT> rule_value_one_capture_20;
	bool success_21;
	::ISPA_STD::MatchResult<Types::rule::value::one_capture, IT> rule_value_one_capture_22;
	bool success_23;
	::ISPA_STD::MatchResult<Types::rule::value::one_capture, IT> rule_value_one_capture_24;
	bool success_25;
	::ISPA_STD::MatchResult<Types::rule::value::one_capture, IT> rule_value_one_capture_26;
	bool success_27;
	::ISPA_STD::MatchResult<Types::rule::value::mul_capture, IT> rule_value_mul_capture_28;
	bool success_29;
	::ISPA_STD::MatchResult<Types::rule::value::one_capture, IT> rule_value_one_capture_30;
	bool success_31;
	::ISPA_STD::MatchResult<Types::rule::value::one_capture, IT> rule_value_one_capture_32;
	bool success_33;
	::ISPA_STD::MatchResult<Types::rule::value::one_capture, IT> rule_value_one_capture_34;
	bool success_35;
	::ISPA_STD::MatchResult<Types::rule::value::one_capture, IT> rule_value_one_capture_36;
	bool success_37;
	::ISPA_STD::MatchResult<Types::rule::value::one_capture, IT> rule_value_one_capture_38;
	bool success_39;
	::ISPA_STD::MatchResult<Types::rule::value::one_capture, IT> rule_value_one_capture_40;
	bool success_41;
	::ISPA_STD::MatchResult<Types::rule::value::one_capture, IT> rule_value_one_capture_42;
	bool success_43;
	::ISPA_STD::MatchResult<Types::rule::value::one_capture, IT> rule_value_one_capture_44;
	bool success_45;
	::ISPA_STD::MatchResult<Types::rule::value::one_capture, IT> rule_value_one_capture_46;
	bool success_47;
	::ISPA_STD::MatchResult<Types::rule::value::one_capture, IT> rule_value_one_capture_48;
	bool success_49;
	::ISPA_STD::MatchResult<Types::rule::value::one_capture, IT> rule_value_one_capture_50;
	bool success_51;
	::ISPA_STD::MatchResult<Types::rule::value::one_capture, IT> rule_value_one_capture_52;
	bool success_53;
	::ISPA_STD::MatchResult<Types::rule::value::one_capture, IT> rule_value_one_capture_54;
	bool success_55;
	::ISPA_STD::MatchResult<Types::rule::value::one_capture, IT> rule_value_one_capture_56;
	bool success_57;
	success_1 = false;
	// grammar `@  ( rule::value::one_capture |  rule::value::mul_capture)`: choice; reset match status before selecting an alternative
	success_1 = false;
	auto lookahead_pos_1 = pos;
	switch ((*lookahead_pos_1).kind()) {
		case Tokens::AMPERSAND::id: {
			lookahead_pos_1 = lookahead_pos_1;
			success_3 = false;
			rule_value_one_capture_2 = rule_value_one_capture(lookahead_pos_1);
			if (!(rule_value_one_capture_2.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  rule::value::one_capture");
				return {};
			}
			success_3 = true;
			lookahead_pos_1 = rule_value_one_capture_2.it;
			if (!success_3) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  rule::value::one_capture");
				return {};
			}
			_0 = rule_value_one_capture_2.node;
			success_1 = true;
			break;
		}
		case Tokens::COMMERCIAL_AT::id: {
			auto lookahead_pos_2 = lookahead_pos_1;
			++lookahead_pos_2;
			skip_spaces<Types::__WS>(lookahead_pos_2);
			switch ((*lookahead_pos_2).kind()) {
				case Tokens::EQUALS_SIGN::id: {
					lookahead_pos_2 = lookahead_pos_1;
					success_5 = false;
					rule_value_mul_capture_4 = rule_value_mul_capture(lookahead_pos_2);
					if (!(rule_value_mul_capture_4.status)) {
						raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  rule::value::mul_capture");
						return {};
					}
					success_5 = true;
					lookahead_pos_2 = rule_value_mul_capture_4.it;
					if (!success_5) {
						raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  rule::value::mul_capture");
						return {};
					}
					_0 = rule_value_mul_capture_4.node;
					success_1 = true;
					break;
				}
				case Tokens::ID::id: {
					lookahead_pos_2 = lookahead_pos_1;
					success_7 = false;
					rule_value_one_capture_6 = rule_value_one_capture(lookahead_pos_2);
					if (!(rule_value_one_capture_6.status)) {
						raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  rule::value::one_capture");
						return {};
					}
					success_7 = true;
					lookahead_pos_2 = rule_value_one_capture_6.it;
					if (!success_7) {
						raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  rule::value::one_capture");
						return {};
					}
					_0 = rule_value_one_capture_6.node;
					success_1 = true;
					break;
				}
				case Tokens::LEFT_PARENTHESIS::id: {
					lookahead_pos_2 = lookahead_pos_1;
					success_9 = false;
					rule_value_one_capture_8 = rule_value_one_capture(lookahead_pos_2);
					if (!(rule_value_one_capture_8.status)) {
						raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  rule::value::one_capture");
						return {};
					}
					success_9 = true;
					lookahead_pos_2 = rule_value_one_capture_8.it;
					if (!success_9) {
						raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  rule::value::one_capture");
						return {};
					}
					_0 = rule_value_one_capture_8.node;
					success_1 = true;
					break;
				}
				case Tokens::PERCENT_SIGN::id: {
					lookahead_pos_2 = lookahead_pos_1;
					success_11 = false;
					rule_value_one_capture_10 = rule_value_one_capture(lookahead_pos_2);
					if (!(rule_value_one_capture_10.status)) {
						raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  rule::value::one_capture");
						return {};
					}
					success_11 = true;
					lookahead_pos_2 = rule_value_one_capture_10.it;
					if (!success_11) {
						raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  rule::value::one_capture");
						return {};
					}
					_0 = rule_value_one_capture_10.node;
					success_1 = true;
					break;
				}
				case Tokens::rule::value::ANY::id: {
					lookahead_pos_2 = lookahead_pos_1;
					success_13 = false;
					rule_value_one_capture_12 = rule_value_one_capture(lookahead_pos_2);
					if (!(rule_value_one_capture_12.status)) {
						raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  rule::value::one_capture");
						return {};
					}
					success_13 = true;
					lookahead_pos_2 = rule_value_one_capture_12.it;
					if (!success_13) {
						raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  rule::value::one_capture");
						return {};
					}
					_0 = rule_value_one_capture_12.node;
					success_1 = true;
					break;
				}
				case Tokens::rule::value::CGROUP::id: {
					lookahead_pos_2 = lookahead_pos_1;
					success_15 = false;
					rule_value_one_capture_14 = rule_value_one_capture(lookahead_pos_2);
					if (!(rule_value_one_capture_14.status)) {
						raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  rule::value::one_capture");
						return {};
					}
					success_15 = true;
					lookahead_pos_2 = rule_value_one_capture_14.it;
					if (!success_15) {
						raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  rule::value::one_capture");
						return {};
					}
					_0 = rule_value_one_capture_14.node;
					success_1 = true;
					break;
				}
				case Tokens::rule::value::NOSPACE::id: {
					lookahead_pos_2 = lookahead_pos_1;
					success_17 = false;
					rule_value_one_capture_16 = rule_value_one_capture(lookahead_pos_2);
					if (!(rule_value_one_capture_16.status)) {
						raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  rule::value::one_capture");
						return {};
					}
					success_17 = true;
					lookahead_pos_2 = rule_value_one_capture_16.it;
					if (!success_17) {
						raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  rule::value::one_capture");
						return {};
					}
					_0 = rule_value_one_capture_16.node;
					success_1 = true;
					break;
				}
				case Tokens::rule::value::SPACE::id: {
					lookahead_pos_2 = lookahead_pos_1;
					success_19 = false;
					rule_value_one_capture_18 = rule_value_one_capture(lookahead_pos_2);
					if (!(rule_value_one_capture_18.status)) {
						raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  rule::value::one_capture");
						return {};
					}
					success_19 = true;
					lookahead_pos_2 = rule_value_one_capture_18.it;
					if (!success_19) {
						raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  rule::value::one_capture");
						return {};
					}
					_0 = rule_value_one_capture_18.node;
					success_1 = true;
					break;
				}
				case Tokens::rule::value::STRING::id: {
					lookahead_pos_2 = lookahead_pos_1;
					success_21 = false;
					rule_value_one_capture_20 = rule_value_one_capture(lookahead_pos_2);
					if (!(rule_value_one_capture_20.status)) {
						raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  rule::value::one_capture");
						return {};
					}
					success_21 = true;
					lookahead_pos_2 = rule_value_one_capture_20.it;
					if (!success_21) {
						raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  rule::value::one_capture");
						return {};
					}
					_0 = rule_value_one_capture_20.node;
					success_1 = true;
					break;
				}
				case Tokens::rule::value::dyn::DOLLAR_SIGN::id: {
					lookahead_pos_2 = lookahead_pos_1;
					success_23 = false;
					rule_value_one_capture_22 = rule_value_one_capture(lookahead_pos_2);
					if (!(rule_value_one_capture_22.status)) {
						raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  rule::value::one_capture");
						return {};
					}
					success_23 = true;
					lookahead_pos_2 = rule_value_one_capture_22.it;
					if (!success_23) {
						raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  rule::value::one_capture");
						return {};
					}
					_0 = rule_value_one_capture_22.node;
					success_1 = true;
					break;
				}
			}
			if (!success_1) {
				lookahead_pos_2 = lookahead_pos_1;
			}
			lookahead_pos_1 = lookahead_pos_2;
			break;
		}
		case Tokens::ID::id: {
			lookahead_pos_1 = lookahead_pos_1;
			success_25 = false;
			rule_value_one_capture_24 = rule_value_one_capture(lookahead_pos_1);
			if (!(rule_value_one_capture_24.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  rule::value::one_capture");
				return {};
			}
			success_25 = true;
			lookahead_pos_1 = rule_value_one_capture_24.it;
			if (!success_25) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  rule::value::one_capture");
				return {};
			}
			_0 = rule_value_one_capture_24.node;
			success_1 = true;
			break;
		}
		case Tokens::LEFT_PARENTHESIS::id: {
			lookahead_pos_1 = lookahead_pos_1;
			success_27 = false;
			rule_value_one_capture_26 = rule_value_one_capture(lookahead_pos_1);
			if (!(rule_value_one_capture_26.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  rule::value::one_capture");
				return {};
			}
			success_27 = true;
			lookahead_pos_1 = rule_value_one_capture_26.it;
			if (!success_27) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  rule::value::one_capture");
				return {};
			}
			_0 = rule_value_one_capture_26.node;
			success_1 = true;
			break;
		}
		case Tokens::PERCENT_SIGN::id: {
			auto lookahead_pos_2 = lookahead_pos_1;
			++lookahead_pos_2;
			skip_spaces<Types::__WS>(lookahead_pos_2);
			switch ((*lookahead_pos_2).kind()) {
				case Tokens::EQUALS_SIGN::id: {
					lookahead_pos_2 = lookahead_pos_1;
					success_29 = false;
					rule_value_mul_capture_28 = rule_value_mul_capture(lookahead_pos_2);
					if (!(rule_value_mul_capture_28.status)) {
						raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  rule::value::mul_capture");
						return {};
					}
					success_29 = true;
					lookahead_pos_2 = rule_value_mul_capture_28.it;
					if (!success_29) {
						raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  rule::value::mul_capture");
						return {};
					}
					_0 = rule_value_mul_capture_28.node;
					success_1 = true;
					break;
				}
				case Tokens::ID::id: {
					lookahead_pos_2 = lookahead_pos_1;
					success_31 = false;
					rule_value_one_capture_30 = rule_value_one_capture(lookahead_pos_2);
					if (!(rule_value_one_capture_30.status)) {
						raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  rule::value::one_capture");
						return {};
					}
					success_31 = true;
					lookahead_pos_2 = rule_value_one_capture_30.it;
					if (!success_31) {
						raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  rule::value::one_capture");
						return {};
					}
					_0 = rule_value_one_capture_30.node;
					success_1 = true;
					break;
				}
				case Tokens::LEFT_PARENTHESIS::id: {
					lookahead_pos_2 = lookahead_pos_1;
					success_33 = false;
					rule_value_one_capture_32 = rule_value_one_capture(lookahead_pos_2);
					if (!(rule_value_one_capture_32.status)) {
						raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  rule::value::one_capture");
						return {};
					}
					success_33 = true;
					lookahead_pos_2 = rule_value_one_capture_32.it;
					if (!success_33) {
						raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  rule::value::one_capture");
						return {};
					}
					_0 = rule_value_one_capture_32.node;
					success_1 = true;
					break;
				}
				case Tokens::rule::value::ANY::id: {
					lookahead_pos_2 = lookahead_pos_1;
					success_35 = false;
					rule_value_one_capture_34 = rule_value_one_capture(lookahead_pos_2);
					if (!(rule_value_one_capture_34.status)) {
						raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  rule::value::one_capture");
						return {};
					}
					success_35 = true;
					lookahead_pos_2 = rule_value_one_capture_34.it;
					if (!success_35) {
						raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  rule::value::one_capture");
						return {};
					}
					_0 = rule_value_one_capture_34.node;
					success_1 = true;
					break;
				}
				case Tokens::rule::value::CGROUP::id: {
					lookahead_pos_2 = lookahead_pos_1;
					success_37 = false;
					rule_value_one_capture_36 = rule_value_one_capture(lookahead_pos_2);
					if (!(rule_value_one_capture_36.status)) {
						raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  rule::value::one_capture");
						return {};
					}
					success_37 = true;
					lookahead_pos_2 = rule_value_one_capture_36.it;
					if (!success_37) {
						raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  rule::value::one_capture");
						return {};
					}
					_0 = rule_value_one_capture_36.node;
					success_1 = true;
					break;
				}
				case Tokens::rule::value::NOSPACE::id: {
					lookahead_pos_2 = lookahead_pos_1;
					success_39 = false;
					rule_value_one_capture_38 = rule_value_one_capture(lookahead_pos_2);
					if (!(rule_value_one_capture_38.status)) {
						raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  rule::value::one_capture");
						return {};
					}
					success_39 = true;
					lookahead_pos_2 = rule_value_one_capture_38.it;
					if (!success_39) {
						raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  rule::value::one_capture");
						return {};
					}
					_0 = rule_value_one_capture_38.node;
					success_1 = true;
					break;
				}
				case Tokens::rule::value::SPACE::id: {
					lookahead_pos_2 = lookahead_pos_1;
					success_41 = false;
					rule_value_one_capture_40 = rule_value_one_capture(lookahead_pos_2);
					if (!(rule_value_one_capture_40.status)) {
						raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  rule::value::one_capture");
						return {};
					}
					success_41 = true;
					lookahead_pos_2 = rule_value_one_capture_40.it;
					if (!success_41) {
						raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  rule::value::one_capture");
						return {};
					}
					_0 = rule_value_one_capture_40.node;
					success_1 = true;
					break;
				}
				case Tokens::rule::value::STRING::id: {
					lookahead_pos_2 = lookahead_pos_1;
					success_43 = false;
					rule_value_one_capture_42 = rule_value_one_capture(lookahead_pos_2);
					if (!(rule_value_one_capture_42.status)) {
						raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  rule::value::one_capture");
						return {};
					}
					success_43 = true;
					lookahead_pos_2 = rule_value_one_capture_42.it;
					if (!success_43) {
						raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  rule::value::one_capture");
						return {};
					}
					_0 = rule_value_one_capture_42.node;
					success_1 = true;
					break;
				}
				case Tokens::rule::value::dyn::DOLLAR_SIGN::id: {
					lookahead_pos_2 = lookahead_pos_1;
					success_45 = false;
					rule_value_one_capture_44 = rule_value_one_capture(lookahead_pos_2);
					if (!(rule_value_one_capture_44.status)) {
						raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  rule::value::one_capture");
						return {};
					}
					success_45 = true;
					lookahead_pos_2 = rule_value_one_capture_44.it;
					if (!success_45) {
						raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  rule::value::one_capture");
						return {};
					}
					_0 = rule_value_one_capture_44.node;
					success_1 = true;
					break;
				}
			}
			if (!success_1) {
				lookahead_pos_2 = lookahead_pos_1;
			}
			lookahead_pos_1 = lookahead_pos_2;
			break;
		}
		case Tokens::rule::value::ANY::id: {
			lookahead_pos_1 = lookahead_pos_1;
			success_47 = false;
			rule_value_one_capture_46 = rule_value_one_capture(lookahead_pos_1);
			if (!(rule_value_one_capture_46.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  rule::value::one_capture");
				return {};
			}
			success_47 = true;
			lookahead_pos_1 = rule_value_one_capture_46.it;
			if (!success_47) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  rule::value::one_capture");
				return {};
			}
			_0 = rule_value_one_capture_46.node;
			success_1 = true;
			break;
		}
		case Tokens::rule::value::CGROUP::id: {
			lookahead_pos_1 = lookahead_pos_1;
			success_49 = false;
			rule_value_one_capture_48 = rule_value_one_capture(lookahead_pos_1);
			if (!(rule_value_one_capture_48.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  rule::value::one_capture");
				return {};
			}
			success_49 = true;
			lookahead_pos_1 = rule_value_one_capture_48.it;
			if (!success_49) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  rule::value::one_capture");
				return {};
			}
			_0 = rule_value_one_capture_48.node;
			success_1 = true;
			break;
		}
		case Tokens::rule::value::NOSPACE::id: {
			lookahead_pos_1 = lookahead_pos_1;
			success_51 = false;
			rule_value_one_capture_50 = rule_value_one_capture(lookahead_pos_1);
			if (!(rule_value_one_capture_50.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  rule::value::one_capture");
				return {};
			}
			success_51 = true;
			lookahead_pos_1 = rule_value_one_capture_50.it;
			if (!success_51) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  rule::value::one_capture");
				return {};
			}
			_0 = rule_value_one_capture_50.node;
			success_1 = true;
			break;
		}
		case Tokens::rule::value::SPACE::id: {
			lookahead_pos_1 = lookahead_pos_1;
			success_53 = false;
			rule_value_one_capture_52 = rule_value_one_capture(lookahead_pos_1);
			if (!(rule_value_one_capture_52.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  rule::value::one_capture");
				return {};
			}
			success_53 = true;
			lookahead_pos_1 = rule_value_one_capture_52.it;
			if (!success_53) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  rule::value::one_capture");
				return {};
			}
			_0 = rule_value_one_capture_52.node;
			success_1 = true;
			break;
		}
		case Tokens::rule::value::STRING::id: {
			lookahead_pos_1 = lookahead_pos_1;
			success_55 = false;
			rule_value_one_capture_54 = rule_value_one_capture(lookahead_pos_1);
			if (!(rule_value_one_capture_54.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  rule::value::one_capture");
				return {};
			}
			success_55 = true;
			lookahead_pos_1 = rule_value_one_capture_54.it;
			if (!success_55) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  rule::value::one_capture");
				return {};
			}
			_0 = rule_value_one_capture_54.node;
			success_1 = true;
			break;
		}
		case Tokens::rule::value::dyn::DOLLAR_SIGN::id: {
			lookahead_pos_1 = lookahead_pos_1;
			success_57 = false;
			rule_value_one_capture_56 = rule_value_one_capture(lookahead_pos_1);
			if (!(rule_value_one_capture_56.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  rule::value::one_capture");
				return {};
			}
			success_57 = true;
			lookahead_pos_1 = rule_value_one_capture_56.it;
			if (!success_57) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  rule::value::one_capture");
				return {};
			}
			_0 = rule_value_one_capture_56.node;
			success_1 = true;
			break;
		}
	}
	pos = lookahead_pos_1;
	if (!success_1) {
		raise_error(*pos, "ISPA match failure: no LL(k) alternative matched | grammar: @  ( rule::value::one_capture |  rule::value::mul_capture)");
		return {};
	}
	Types::rule::value result;
	::ISPA_STD::assign_compatible(result.value, _0);
	::ISPA_STD::MatchResult<Types::rule::value, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::rule_value<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::rule::value, ::Parser::Lexer::iterator>;
template auto Parser::Parser::rule_value<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::rule::value, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::rule_value_alternative(IT pos) -> ::ISPA_STD::MatchResult<Types::rule::value::alternative, IT> {
	::ISPA_STD::Node<Types::rule::value::alternative::VERTICAL_LINE> rule_value_alternative_VERTICAL_LINE_0;
	bool success_1;
	::ISPA_STD::Node<Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::MatchResult<Types::rule::value::pattern, IT> rule_value_pattern_4;
	bool success_5;
	success_1 = false;
	if (!(((*pos)).template holds<Types::rule::value::alternative::VERTICAL_LINE>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  rule::value::alternative::VERTICAL_LINE");
		return {};
	}
	rule_value_alternative_VERTICAL_LINE_0 = ((*pos)).template to_node<::ISPA_STD::Node<Types::rule::value::alternative::VERTICAL_LINE>>();
	success_1 = true;
	pos++;
	success_3 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_2 = ((*pos)).template to_node<::ISPA_STD::Node<Types::__WS>>();
		success_3 = true;
		pos++;
	}
	success_5 = false;
	rule_value_pattern_4 = rule_value_pattern(pos);
	if (!(rule_value_pattern_4.status)) {
		raise_error(*pos, "ISPA match failure: required named rule did not match | grammar: @  rule::value::pattern");
		return {};
	}
	success_5 = true;
	pos = rule_value_pattern_4.it;
	Types::rule::value::alternative result;
	::ISPA_STD::assign_compatible(result.value, rule_value_pattern_4.node);
	::ISPA_STD::MatchResult<Types::rule::value::alternative, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::rule_value_alternative<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::rule::value::alternative, ::Parser::Lexer::iterator>;
template auto Parser::Parser::rule_value_alternative<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::rule::value::alternative, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::rule_value_ast_capture(IT pos) -> ::ISPA_STD::MatchResult<Types::rule::value::ast_capture, IT> {
	::ISPA_STD::Node<Types::COMMERCIAL_AT> COMMERCIAL_AT_0;
	bool success_1;
	::ISPA_STD::Node<Types::ID> ID_2;
	bool success_3;
	success_1 = false;
	if (!(((*pos)).template holds<Types::COMMERCIAL_AT>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  COMMERCIAL_AT");
		return {};
	}
	COMMERCIAL_AT_0 = ((*pos)).template to_node<::ISPA_STD::Node<Types::COMMERCIAL_AT>>();
	success_1 = true;
	pos++;
	success_3 = false;
	if (((*pos)).template holds<Types::ID>()) {
		ID_2 = ((*pos)).template to_node<::ISPA_STD::Node<Types::ID>>();
		success_3 = true;
		pos++;
	}
	Types::rule::value::ast_capture result;
	::ISPA_STD::assign_compatible(result.value, ID_2);
	::ISPA_STD::MatchResult<Types::rule::value::ast_capture, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::rule_value_ast_capture<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::rule::value::ast_capture, ::Parser::Lexer::iterator>;
template auto Parser::Parser::rule_value_ast_capture<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::rule::value::ast_capture, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::rule_value_counter(IT pos) -> ::ISPA_STD::MatchResult<Types::rule::value::counter, IT> {
	::ISPA_STD::Node<Types::rule::value::QUANTIFIER> rule_value_QUANTIFIER_0;
	bool success_1;
	::ISPA_STD::Node<Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::MatchResult<Types::rule::value::counter::bounded, IT> rule_value_counter_bounded_4;
	bool success_5;
	success_1 = false;
	if (!(((*pos)).template holds<Types::rule::value::QUANTIFIER>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar: @  rule::value::QUANTIFIER");
		return {};
	}
	rule_value_QUANTIFIER_0 = ((*pos)).template to_node<::ISPA_STD::Node<Types::rule::value::QUANTIFIER>>();
	success_1 = true;
	pos++;
	success_3 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_2 = ((*pos)).template to_node<::ISPA_STD::Node<Types::__WS>>();
		success_3 = true;
		pos++;
	}
	success_5 = false;
	rule_value_counter_bounded_4 = rule_value_counter_bounded(pos);
	if (rule_value_counter_bounded_4.status) {
		success_5 = true;
		pos = rule_value_counter_bounded_4.it;
	}
	Types::rule::value::counter result;
	::ISPA_STD::assign_compatible(result.quantifier, rule_value_QUANTIFIER_0);
	::ISPA_STD::assign_compatible(result.repetitions, rule_value_counter_bounded_4);
	::ISPA_STD::MatchResult<Types::rule::value::counter, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::rule_value_counter<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::rule::value::counter, ::Parser::Lexer::iterator>;
template auto Parser::Parser::rule_value_counter<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::rule::value::counter, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::rule_value_counter_bounded(IT pos) -> ::ISPA_STD::MatchResult<Types::rule::value::counter::bounded, IT> {
	::ISPA_STD::Node<Types::EQUALS_SIGN> EQUALS_SIGN_0;
	bool success_1;
	::ISPA_STD::Node<Types::__WS> __WS_2;
	bool success_3;
	std::variant<std::monostate, ::ISPA_STD::Node<Types::expr>, ::ISPA_STD::Node<Types::ID>, ::ISPA_STD::Node<Types::NUMBER>> _4;
	bool success_5;
	::ISPA_STD::Node<Types::ID> ID_6;
	bool success_7;
	::ISPA_STD::Node<Types::NUMBER> NUMBER_8;
	bool success_9;
	::ISPA_STD::MatchResult<Types::expr, IT> expr_10;
	bool success_11;
	success_1 = false;
	if (!(((*pos)).template holds<Types::EQUALS_SIGN>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  EQUALS_SIGN");
		return {};
	}
	EQUALS_SIGN_0 = ((*pos)).template to_node<::ISPA_STD::Node<Types::EQUALS_SIGN>>();
	success_1 = true;
	pos++;
	success_3 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_2 = ((*pos)).template to_node<::ISPA_STD::Node<Types::__WS>>();
		success_3 = true;
		pos++;
	}
	success_5 = false;
	// grammar `@  ( NUMBER |  ID |  expr)`: choice; reset match status before selecting an alternative
	success_5 = false;
	auto lookahead_pos_1 = pos;
	switch ((*lookahead_pos_1).kind()) {
		case Tokens::ID::id: {
			lookahead_pos_1 = lookahead_pos_1;
			success_7 = false;
			if (!(((*lookahead_pos_1)).template holds<Types::ID>())) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  ID");
				return {};
			}
			ID_6 = ((*lookahead_pos_1)).template to_node<::ISPA_STD::Node<Types::ID>>();
			success_7 = true;
			lookahead_pos_1++;
			if (!success_7) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  ID");
				return {};
			}
			_4 = ID_6;
			success_5 = true;
			break;
		}
		case Tokens::NUMBER::id: {
			lookahead_pos_1 = lookahead_pos_1;
			success_9 = false;
			if (!(((*lookahead_pos_1)).template holds<Types::NUMBER>())) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  NUMBER");
				return {};
			}
			NUMBER_8 = ((*lookahead_pos_1)).template to_node<::ISPA_STD::Node<Types::NUMBER>>();
			success_9 = true;
			lookahead_pos_1++;
			if (!success_9) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  NUMBER");
				return {};
			}
			_4 = NUMBER_8;
			success_5 = true;
			break;
		}
		case Tokens::PY_RAW::id: {
			lookahead_pos_1 = lookahead_pos_1;
			success_11 = false;
			expr_10 = expr(lookahead_pos_1);
			if (!(expr_10.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  expr");
				return {};
			}
			success_11 = true;
			lookahead_pos_1 = expr_10.it;
			if (!success_11) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  expr");
				return {};
			}
			_4 = expr_10.node;
			success_5 = true;
			break;
		}
	}
	pos = lookahead_pos_1;
	if (!success_5) {
		raise_error(*pos, "ISPA match failure: no LL(k) alternative matched | grammar: @  ( NUMBER |  ID |  expr)");
		return {};
	}
	Types::rule::value::counter::bounded result;
	::ISPA_STD::assign_compatible(result.value, _4);
	::ISPA_STD::MatchResult<Types::rule::value::counter::bounded, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::rule_value_counter_bounded<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::rule::value::counter::bounded, ::Parser::Lexer::iterator>;
template auto Parser::Parser::rule_value_counter_bounded<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::rule::value::counter::bounded, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::rule_value_dyn(IT pos) -> ::ISPA_STD::MatchResult<Types::rule::value::dyn, IT> {
	::ISPA_STD::Node<Types::rule::value::dyn::DOLLAR_SIGN> rule_value_dyn_DOLLAR_SIGN_0;
	bool success_1;
	::ISPA_STD::Node<Types::__WS> __WS_2;
	bool success_3;
	std::variant<std::monostate, ::ISPA_STD::Node<Types::ID>, ::ISPA_STD::Node<Types::rule::value::dyn::dyn_expr>> _4;
	bool success_5;
	::ISPA_STD::Node<Types::ID> ID_6;
	bool success_7;
	::ISPA_STD::MatchResult<Types::rule::value::dyn::dyn_expr, IT> rule_value_dyn_dyn_expr_8;
	bool success_9;
	success_1 = false;
	if (!(((*pos)).template holds<Types::rule::value::dyn::DOLLAR_SIGN>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  rule::value::dyn::DOLLAR_SIGN");
		return {};
	}
	rule_value_dyn_DOLLAR_SIGN_0 = ((*pos)).template to_node<::ISPA_STD::Node<Types::rule::value::dyn::DOLLAR_SIGN>>();
	success_1 = true;
	pos++;
	success_3 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_2 = ((*pos)).template to_node<::ISPA_STD::Node<Types::__WS>>();
		success_3 = true;
		pos++;
	}
	success_5 = false;
	// grammar `@  ( rule::value::dyn::dyn_expr |  ID)`: choice; reset match status before selecting an alternative
	success_5 = false;
	auto lookahead_pos_1 = pos;
	switch ((*lookahead_pos_1).kind()) {
		case Tokens::ID::id: {
			lookahead_pos_1 = lookahead_pos_1;
			success_7 = false;
			if (!(((*lookahead_pos_1)).template holds<Types::ID>())) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  ID");
				return {};
			}
			ID_6 = ((*lookahead_pos_1)).template to_node<::ISPA_STD::Node<Types::ID>>();
			success_7 = true;
			lookahead_pos_1++;
			if (!success_7) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  ID");
				return {};
			}
			_4 = ID_6;
			success_5 = true;
			break;
		}
		case Tokens::LEFT_CURLY_BRACKET::id: {
			lookahead_pos_1 = lookahead_pos_1;
			success_9 = false;
			rule_value_dyn_dyn_expr_8 = rule_value_dyn_dyn_expr(lookahead_pos_1);
			if (!(rule_value_dyn_dyn_expr_8.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  rule::value::dyn::dyn_expr");
				return {};
			}
			success_9 = true;
			lookahead_pos_1 = rule_value_dyn_dyn_expr_8.it;
			if (!success_9) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  rule::value::dyn::dyn_expr");
				return {};
			}
			_4 = rule_value_dyn_dyn_expr_8.node;
			success_5 = true;
			break;
		}
	}
	pos = lookahead_pos_1;
	if (!success_5) {
		raise_error(*pos, "ISPA match failure: no LL(k) alternative matched | grammar: @  ( rule::value::dyn::dyn_expr |  ID)");
		return {};
	}
	Types::rule::value::dyn result;
	::ISPA_STD::assign_compatible(result.value, _4);
	::ISPA_STD::MatchResult<Types::rule::value::dyn, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::rule_value_dyn<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::rule::value::dyn, ::Parser::Lexer::iterator>;
template auto Parser::Parser::rule_value_dyn<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::rule::value::dyn, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::rule_value_dyn_dyn_expr(IT pos) -> ::ISPA_STD::MatchResult<Types::rule::value::dyn::dyn_expr, IT> {
	::ISPA_STD::Node<Types::LEFT_CURLY_BRACKET> LEFT_CURLY_BRACKET_0;
	bool success_1;
	::ISPA_STD::Node<Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::MatchResult<Types::expr, IT> expr_4;
	bool success_5;
	::ISPA_STD::Node<Types::__WS> __WS_6;
	bool success_7;
	::ISPA_STD::Node<Types::RIGHT_CURLY_BRACKET> RIGHT_CURLY_BRACKET_8;
	bool success_9;
	success_1 = false;
	if (!(((*pos)).template holds<Types::LEFT_CURLY_BRACKET>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  LEFT_CURLY_BRACKET");
		return {};
	}
	LEFT_CURLY_BRACKET_0 = ((*pos)).template to_node<::ISPA_STD::Node<Types::LEFT_CURLY_BRACKET>>();
	success_1 = true;
	pos++;
	success_3 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_2 = ((*pos)).template to_node<::ISPA_STD::Node<Types::__WS>>();
		success_3 = true;
		pos++;
	}
	success_5 = false;
	expr_4 = expr(pos);
	if (!(expr_4.status)) {
		raise_error(*pos, "ISPA match failure: required named rule did not match | grammar: @  expr");
		return {};
	}
	success_5 = true;
	pos = expr_4.it;
	success_7 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_6 = ((*pos)).template to_node<::ISPA_STD::Node<Types::__WS>>();
		success_7 = true;
		pos++;
	}
	success_9 = false;
	if (!(((*pos)).template holds<Types::RIGHT_CURLY_BRACKET>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  RIGHT_CURLY_BRACKET");
		return {};
	}
	RIGHT_CURLY_BRACKET_8 = ((*pos)).template to_node<::ISPA_STD::Node<Types::RIGHT_CURLY_BRACKET>>();
	success_9 = true;
	pos++;
	Types::rule::value::dyn::dyn_expr result;
	::ISPA_STD::assign_compatible(result.value, expr_4.node);
	::ISPA_STD::MatchResult<Types::rule::value::dyn::dyn_expr, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::rule_value_dyn_dyn_expr<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::rule::value::dyn::dyn_expr, ::Parser::Lexer::iterator>;
template auto Parser::Parser::rule_value_dyn_dyn_expr<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::rule::value::dyn::dyn_expr, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::rule_value_fail_capture(IT pos) -> ::ISPA_STD::MatchResult<Types::rule::value::fail_capture, IT> {
	::ISPA_STD::Node<Types::PERCENT_SIGN> PERCENT_SIGN_0;
	bool success_1;
	::ISPA_STD::MatchResult<Types::name, IT> name_2;
	bool success_3;
	success_1 = false;
	if (!(((*pos)).template holds<Types::PERCENT_SIGN>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  PERCENT_SIGN");
		return {};
	}
	PERCENT_SIGN_0 = ((*pos)).template to_node<::ISPA_STD::Node<Types::PERCENT_SIGN>>();
	success_1 = true;
	pos++;
	success_3 = false;
	name_2 = name(pos);
	if (name_2.status) {
		success_3 = true;
		pos = name_2.it;
	}
	Types::rule::value::fail_capture result;
	::ISPA_STD::assign_compatible(result.value, name_2.node);
	::ISPA_STD::MatchResult<Types::rule::value::fail_capture, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::rule_value_fail_capture<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::rule::value::fail_capture, ::Parser::Lexer::iterator>;
template auto Parser::Parser::rule_value_fail_capture<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::rule::value::fail_capture, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::rule_value_group(IT pos) -> ::ISPA_STD::MatchResult<Types::rule::value::group, IT> {
	::ISPA_STD::Node<Types::LEFT_PARENTHESIS> LEFT_PARENTHESIS_0;
	bool success_1;
	::ISPA_STD::MatchResult<Types::rule::value, IT> rule_value_5;
	bool success_6;
	::ISPA_STD::Node<Types::rule::value> element_7;
	std::vector<::ISPA_STD::Node<Types::rule::value>> shadow_8;
	std::vector<::ISPA_STD::Node<Types::rule::value>> uvar_4;
	bool success_9;
	::ISPA_STD::Node<Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::Node<Types::__WS> __WS_11;
	bool success_12;
	::ISPA_STD::Node<Types::RIGHT_PARENTHESIS> RIGHT_PARENTHESIS_13;
	bool success_14;
	success_1 = false;
	if (!(((*pos)).template holds<Types::LEFT_PARENTHESIS>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  LEFT_PARENTHESIS");
		return {};
	}
	LEFT_PARENTHESIS_0 = ((*pos)).template to_node<::ISPA_STD::Node<Types::LEFT_PARENTHESIS>>();
	success_1 = true;
	pos++;
	success_6 = false;
	// grammar `@  rule::value+;`: repeat named rule; collect every matched value
	success_9 = false;
	while (true) {
		auto repeat_ws_10 = pos;
		success_3 = false;
		if (((*repeat_ws_10)).template holds<Types::__WS>()) {
			__WS_2 = ((*repeat_ws_10)).template to_node<::ISPA_STD::Node<Types::__WS>>();
			success_3 = true;
			repeat_ws_10++;
		}
		rule_value_5 = rule_value(repeat_ws_10);
		if (!(rule_value_5.status)) {
			break;
		}
		success_6 = true;
		repeat_ws_10 = rule_value_5.it;
		element_7 = rule_value_5.node;
		shadow_8.push_back(element_7);
		success_9 = true;
		pos = repeat_ws_10;
	}
	if (!success_9) {
		return {};
	}
	::ISPA_STD::assign_compatible(uvar_4, shadow_8);
	success_12 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_11 = ((*pos)).template to_node<::ISPA_STD::Node<Types::__WS>>();
		success_12 = true;
		pos++;
	}
	success_14 = false;
	if (!(((*pos)).template holds<Types::RIGHT_PARENTHESIS>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  RIGHT_PARENTHESIS");
		return {};
	}
	RIGHT_PARENTHESIS_13 = ((*pos)).template to_node<::ISPA_STD::Node<Types::RIGHT_PARENTHESIS>>();
	success_14 = true;
	pos++;
	Types::rule::value::group result;
	::ISPA_STD::assign_compatible(result.value, uvar_4);
	::ISPA_STD::MatchResult<Types::rule::value::group, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::rule_value_group<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::rule::value::group, ::Parser::Lexer::iterator>;
template auto Parser::Parser::rule_value_group<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::rule::value::group, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::rule_value_mul_capture(IT pos) -> ::ISPA_STD::MatchResult<Types::rule::value::mul_capture, IT> {
	std::variant<std::monostate, ::ISPA_STD::Node<Types::PERCENT_SIGN>, ::ISPA_STD::Node<Types::COMMERCIAL_AT>> _0;
	bool success_1;
	::ISPA_STD::Node<Types::COMMERCIAL_AT> COMMERCIAL_AT_2;
	bool success_3;
	::ISPA_STD::Node<Types::PERCENT_SIGN> PERCENT_SIGN_4;
	bool success_5;
	::ISPA_STD::Node<Types::__WS> __WS_6;
	bool success_7;
	::ISPA_STD::Node<Types::EQUALS_SIGN> EQUALS_SIGN_8;
	bool success_9;
	::ISPA_STD::Node<Types::__WS> __WS_10;
	bool success_11;
	::ISPA_STD::Node<Types::LEFT_PARENTHESIS> LEFT_PARENTHESIS_12;
	bool success_13;
	::ISPA_STD::MatchResult<Types::rule::value::one_capture, IT> rule_value_one_capture_17;
	bool success_18;
	::ISPA_STD::Node<Types::rule::value::one_capture> element_19;
	std::vector<::ISPA_STD::Node<Types::rule::value::one_capture>> shadow_20;
	std::vector<::ISPA_STD::Node<Types::rule::value::one_capture>> uvar_16;
	bool success_21;
	::ISPA_STD::Node<Types::__WS> __WS_14;
	bool success_15;
	::ISPA_STD::Node<Types::__WS> __WS_23;
	bool success_24;
	::ISPA_STD::Node<Types::RIGHT_PARENTHESIS> RIGHT_PARENTHESIS_25;
	bool success_26;
	success_1 = false;
	// grammar `@  ( COMMERCIAL_AT |  PERCENT_SIGN)`: choice; reset match status before selecting an alternative
	success_1 = false;
	auto lookahead_pos_1 = pos;
	switch ((*lookahead_pos_1).kind()) {
		case Tokens::COMMERCIAL_AT::id: {
			lookahead_pos_1 = lookahead_pos_1;
			success_3 = false;
			if (!(((*lookahead_pos_1)).template holds<Types::COMMERCIAL_AT>())) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  COMMERCIAL_AT");
				return {};
			}
			COMMERCIAL_AT_2 = ((*lookahead_pos_1)).template to_node<::ISPA_STD::Node<Types::COMMERCIAL_AT>>();
			success_3 = true;
			lookahead_pos_1++;
			if (!success_3) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  COMMERCIAL_AT");
				return {};
			}
			_0 = COMMERCIAL_AT_2;
			success_1 = true;
			break;
		}
		case Tokens::PERCENT_SIGN::id: {
			lookahead_pos_1 = lookahead_pos_1;
			success_5 = false;
			if (!(((*lookahead_pos_1)).template holds<Types::PERCENT_SIGN>())) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  PERCENT_SIGN");
				return {};
			}
			PERCENT_SIGN_4 = ((*lookahead_pos_1)).template to_node<::ISPA_STD::Node<Types::PERCENT_SIGN>>();
			success_5 = true;
			lookahead_pos_1++;
			if (!success_5) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  PERCENT_SIGN");
				return {};
			}
			_0 = PERCENT_SIGN_4;
			success_1 = true;
			break;
		}
	}
	pos = lookahead_pos_1;
	if (!success_1) {
		raise_error(*pos, "ISPA match failure: no LL(k) alternative matched | grammar: @  ( COMMERCIAL_AT |  PERCENT_SIGN)");
		return {};
	}
	success_7 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_6 = ((*pos)).template to_node<::ISPA_STD::Node<Types::__WS>>();
		success_7 = true;
		pos++;
	}
	success_9 = false;
	if (!(((*pos)).template holds<Types::EQUALS_SIGN>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  EQUALS_SIGN");
		return {};
	}
	EQUALS_SIGN_8 = ((*pos)).template to_node<::ISPA_STD::Node<Types::EQUALS_SIGN>>();
	success_9 = true;
	pos++;
	success_11 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_10 = ((*pos)).template to_node<::ISPA_STD::Node<Types::__WS>>();
		success_11 = true;
		pos++;
	}
	success_13 = false;
	if (!(((*pos)).template holds<Types::LEFT_PARENTHESIS>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  LEFT_PARENTHESIS");
		return {};
	}
	LEFT_PARENTHESIS_12 = ((*pos)).template to_node<::ISPA_STD::Node<Types::LEFT_PARENTHESIS>>();
	success_13 = true;
	pos++;
	success_18 = false;
	// grammar `@  rule::value::one_capture+;`: repeat named rule; collect every matched value
	success_21 = false;
	while (true) {
		auto repeat_ws_22 = pos;
		success_15 = false;
		if (((*repeat_ws_22)).template holds<Types::__WS>()) {
			__WS_14 = ((*repeat_ws_22)).template to_node<::ISPA_STD::Node<Types::__WS>>();
			success_15 = true;
			repeat_ws_22++;
		}
		rule_value_one_capture_17 = rule_value_one_capture(repeat_ws_22);
		if (!(rule_value_one_capture_17.status)) {
			break;
		}
		success_18 = true;
		repeat_ws_22 = rule_value_one_capture_17.it;
		element_19 = rule_value_one_capture_17.node;
		shadow_20.push_back(element_19);
		success_21 = true;
		pos = repeat_ws_22;
	}
	if (!success_21) {
		return {};
	}
	::ISPA_STD::assign_compatible(uvar_16, shadow_20);
	success_24 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_23 = ((*pos)).template to_node<::ISPA_STD::Node<Types::__WS>>();
		success_24 = true;
		pos++;
	}
	success_26 = false;
	if (!(((*pos)).template holds<Types::RIGHT_PARENTHESIS>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  RIGHT_PARENTHESIS");
		return {};
	}
	RIGHT_PARENTHESIS_25 = ((*pos)).template to_node<::ISPA_STD::Node<Types::RIGHT_PARENTHESIS>>();
	success_26 = true;
	pos++;
	Types::rule::value::mul_capture result;
	::ISPA_STD::assign_compatible(result.type, _0);
	::ISPA_STD::assign_compatible(result.cap, uvar_16);
	::ISPA_STD::MatchResult<Types::rule::value::mul_capture, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::rule_value_mul_capture<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::rule::value::mul_capture, ::Parser::Lexer::iterator>;
template auto Parser::Parser::rule_value_mul_capture<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::rule::value::mul_capture, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::rule_value_one_capture(IT pos) -> ::ISPA_STD::MatchResult<Types::rule::value::one_capture, IT> {
	::ISPA_STD::MatchResult<Types::rule::value::var_capture, IT> rule_value_var_capture_0;
	bool success_1;
	::ISPA_STD::Node<Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::MatchResult<Types::rule::value::ast_capture, IT> rule_value_ast_capture_4;
	bool success_5;
	::ISPA_STD::Node<Types::__WS> __WS_6;
	bool success_7;
	::ISPA_STD::MatchResult<Types::rule::value::fail_capture, IT> rule_value_fail_capture_8;
	bool success_9;
	::ISPA_STD::Node<Types::__WS> __WS_10;
	bool success_11;
	::ISPA_STD::MatchResult<Types::rule::value::pattern, IT> rule_value_pattern_12;
	bool success_13;
	::ISPA_STD::MatchResult<Types::rule::value::alternative, IT> rule_value_alternative_17;
	bool success_18;
	::ISPA_STD::Node<Types::rule::value::alternative> element_19;
	std::vector<::ISPA_STD::Node<Types::rule::value::alternative>> shadow_20;
	std::vector<::ISPA_STD::Node<Types::rule::value::alternative>> uvar_16;
	::ISPA_STD::Node<Types::__WS> __WS_14;
	bool success_15;
	::ISPA_STD::Node<Types::__WS> __WS_22;
	bool success_23;
	::ISPA_STD::MatchResult<Types::rule::value::counter, IT> rule_value_counter_24;
	bool success_25;
	::ISPA_STD::Node<Types::__WS> __WS_26;
	bool success_27;
	::ISPA_STD::MatchResult<Types::rule::value::shared_counter_registration, IT> rule_value_shared_counter_registration_28;
	bool success_29;
	success_1 = false;
	rule_value_var_capture_0 = rule_value_var_capture(pos);
	if (rule_value_var_capture_0.status) {
		success_1 = true;
		pos = rule_value_var_capture_0.it;
	}
	success_3 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_2 = ((*pos)).template to_node<::ISPA_STD::Node<Types::__WS>>();
		success_3 = true;
		pos++;
	}
	success_5 = false;
	rule_value_ast_capture_4 = rule_value_ast_capture(pos);
	if (rule_value_ast_capture_4.status) {
		success_5 = true;
		pos = rule_value_ast_capture_4.it;
	}
	success_7 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_6 = ((*pos)).template to_node<::ISPA_STD::Node<Types::__WS>>();
		success_7 = true;
		pos++;
	}
	success_9 = false;
	rule_value_fail_capture_8 = rule_value_fail_capture(pos);
	if (rule_value_fail_capture_8.status) {
		success_9 = true;
		pos = rule_value_fail_capture_8.it;
	}
	success_11 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_10 = ((*pos)).template to_node<::ISPA_STD::Node<Types::__WS>>();
		success_11 = true;
		pos++;
	}
	success_13 = false;
	rule_value_pattern_12 = rule_value_pattern(pos);
	if (!(rule_value_pattern_12.status)) {
		raise_error(*pos, "ISPA match failure: required named rule did not match | grammar: @  rule::value::pattern");
		return {};
	}
	success_13 = true;
	pos = rule_value_pattern_12.it;
	success_18 = false;
	// grammar `@  rule::value::alternative*;`: repeat named rule; collect every matched value
	while (true) {
		auto repeat_ws_21 = pos;
		success_15 = false;
		if (((*repeat_ws_21)).template holds<Types::__WS>()) {
			__WS_14 = ((*repeat_ws_21)).template to_node<::ISPA_STD::Node<Types::__WS>>();
			success_15 = true;
			repeat_ws_21++;
		}
		rule_value_alternative_17 = rule_value_alternative(repeat_ws_21);
		if (!(rule_value_alternative_17.status)) {
			break;
		}
		success_18 = true;
		repeat_ws_21 = rule_value_alternative_17.it;
		element_19 = rule_value_alternative_17.node;
		shadow_20.push_back(element_19);
		pos = repeat_ws_21;
	}
	::ISPA_STD::assign_compatible(uvar_16, shadow_20);
	success_23 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_22 = ((*pos)).template to_node<::ISPA_STD::Node<Types::__WS>>();
		success_23 = true;
		pos++;
	}
	success_25 = false;
	rule_value_counter_24 = rule_value_counter(pos);
	if (rule_value_counter_24.status) {
		success_25 = true;
		pos = rule_value_counter_24.it;
	}
	success_27 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_26 = ((*pos)).template to_node<::ISPA_STD::Node<Types::__WS>>();
		success_27 = true;
		pos++;
	}
	success_29 = false;
	rule_value_shared_counter_registration_28 = rule_value_shared_counter_registration(pos);
	if (rule_value_shared_counter_registration_28.status) {
		success_29 = true;
		pos = rule_value_shared_counter_registration_28.it;
	}
	Types::rule::value::one_capture result;
	::ISPA_STD::assign_compatible(result.v_cap, rule_value_var_capture_0);
	::ISPA_STD::assign_compatible(result.ast_cap, rule_value_ast_capture_4);
	::ISPA_STD::assign_compatible(result.fail_cap, rule_value_fail_capture_8);
	::ISPA_STD::assign_compatible(result.val, rule_value_pattern_12);
	::ISPA_STD::assign_compatible(result.alts, uvar_16);
	::ISPA_STD::assign_compatible(result.quantifier, rule_value_counter_24);
	::ISPA_STD::assign_compatible(result.registration, rule_value_shared_counter_registration_28);
	::ISPA_STD::MatchResult<Types::rule::value::one_capture, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::rule_value_one_capture<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::rule::value::one_capture, ::Parser::Lexer::iterator>;
template auto Parser::Parser::rule_value_one_capture<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::rule::value::one_capture, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::rule_value_pattern(IT pos) -> ::ISPA_STD::MatchResult<Types::rule::value::pattern, IT> {
	std::variant<std::monostate, ::ISPA_STD::Node<Types::rule::value::SPACE>, ::ISPA_STD::Node<Types::rule::value::CGROUP>, ::ISPA_STD::Node<Types::rule::value::STRING>, ::ISPA_STD::Node<Types::rule::value::dyn>, ::ISPA_STD::Node<Types::rule::value::NOSPACE>, ::ISPA_STD::Node<Types::rule::value::group>, ::ISPA_STD::Node<Types::rule::value::ANY>, ::ISPA_STD::Node<Types::name>> _0;
	bool success_1;
	::ISPA_STD::MatchResult<Types::name, IT> name_2;
	bool success_3;
	::ISPA_STD::MatchResult<Types::rule::value::group, IT> rule_value_group_4;
	bool success_5;
	::ISPA_STD::Node<Types::rule::value::ANY> rule_value_ANY_6;
	bool success_7;
	::ISPA_STD::Node<Types::rule::value::CGROUP> rule_value_CGROUP_8;
	bool success_9;
	::ISPA_STD::Node<Types::rule::value::NOSPACE> rule_value_NOSPACE_10;
	bool success_11;
	::ISPA_STD::Node<Types::rule::value::SPACE> rule_value_SPACE_12;
	bool success_13;
	::ISPA_STD::Node<Types::rule::value::STRING> rule_value_STRING_14;
	bool success_15;
	::ISPA_STD::MatchResult<Types::rule::value::dyn, IT> rule_value_dyn_16;
	bool success_17;
	success_1 = false;
	// grammar `@  ( name |  rule::value::group |  rule::value::dyn |  rule::value::STRING |  rule::value::CGROUP |  rule::value::ANY |  rule::value::SPACE |  rule::value::NOSPACE)`: choice; reset match status before selecting an alternative
	success_1 = false;
	auto lookahead_pos_1 = pos;
	switch ((*lookahead_pos_1).kind()) {
		case Tokens::ID::id: {
			lookahead_pos_1 = lookahead_pos_1;
			success_3 = false;
			name_2 = name(lookahead_pos_1);
			if (!(name_2.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  name");
				return {};
			}
			success_3 = true;
			lookahead_pos_1 = name_2.it;
			if (!success_3) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  name");
				return {};
			}
			_0 = name_2.node;
			success_1 = true;
			break;
		}
		case Tokens::LEFT_PARENTHESIS::id: {
			lookahead_pos_1 = lookahead_pos_1;
			success_5 = false;
			rule_value_group_4 = rule_value_group(lookahead_pos_1);
			if (!(rule_value_group_4.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  rule::value::group");
				return {};
			}
			success_5 = true;
			lookahead_pos_1 = rule_value_group_4.it;
			if (!success_5) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  rule::value::group");
				return {};
			}
			_0 = rule_value_group_4.node;
			success_1 = true;
			break;
		}
		case Tokens::rule::value::ANY::id: {
			lookahead_pos_1 = lookahead_pos_1;
			success_7 = false;
			if (!(((*lookahead_pos_1)).template holds<Types::rule::value::ANY>())) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  rule::value::ANY");
				return {};
			}
			rule_value_ANY_6 = ((*lookahead_pos_1)).template to_node<::ISPA_STD::Node<Types::rule::value::ANY>>();
			success_7 = true;
			lookahead_pos_1++;
			if (!success_7) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  rule::value::ANY");
				return {};
			}
			_0 = rule_value_ANY_6;
			success_1 = true;
			break;
		}
		case Tokens::rule::value::CGROUP::id: {
			lookahead_pos_1 = lookahead_pos_1;
			success_9 = false;
			if (!(((*lookahead_pos_1)).template holds<Types::rule::value::CGROUP>())) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  rule::value::CGROUP");
				return {};
			}
			rule_value_CGROUP_8 = ((*lookahead_pos_1)).template to_node<::ISPA_STD::Node<Types::rule::value::CGROUP>>();
			success_9 = true;
			lookahead_pos_1++;
			if (!success_9) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  rule::value::CGROUP");
				return {};
			}
			_0 = rule_value_CGROUP_8;
			success_1 = true;
			break;
		}
		case Tokens::rule::value::NOSPACE::id: {
			lookahead_pos_1 = lookahead_pos_1;
			success_11 = false;
			if (!(((*lookahead_pos_1)).template holds<Types::rule::value::NOSPACE>())) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  rule::value::NOSPACE");
				return {};
			}
			rule_value_NOSPACE_10 = ((*lookahead_pos_1)).template to_node<::ISPA_STD::Node<Types::rule::value::NOSPACE>>();
			success_11 = true;
			lookahead_pos_1++;
			if (!success_11) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  rule::value::NOSPACE");
				return {};
			}
			_0 = rule_value_NOSPACE_10;
			success_1 = true;
			break;
		}
		case Tokens::rule::value::SPACE::id: {
			lookahead_pos_1 = lookahead_pos_1;
			success_13 = false;
			if (!(((*lookahead_pos_1)).template holds<Types::rule::value::SPACE>())) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  rule::value::SPACE");
				return {};
			}
			rule_value_SPACE_12 = ((*lookahead_pos_1)).template to_node<::ISPA_STD::Node<Types::rule::value::SPACE>>();
			success_13 = true;
			lookahead_pos_1++;
			if (!success_13) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  rule::value::SPACE");
				return {};
			}
			_0 = rule_value_SPACE_12;
			success_1 = true;
			break;
		}
		case Tokens::rule::value::STRING::id: {
			lookahead_pos_1 = lookahead_pos_1;
			success_15 = false;
			if (!(((*lookahead_pos_1)).template holds<Types::rule::value::STRING>())) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  rule::value::STRING");
				return {};
			}
			rule_value_STRING_14 = ((*lookahead_pos_1)).template to_node<::ISPA_STD::Node<Types::rule::value::STRING>>();
			success_15 = true;
			lookahead_pos_1++;
			if (!success_15) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  rule::value::STRING");
				return {};
			}
			_0 = rule_value_STRING_14;
			success_1 = true;
			break;
		}
		case Tokens::rule::value::dyn::DOLLAR_SIGN::id: {
			lookahead_pos_1 = lookahead_pos_1;
			success_17 = false;
			rule_value_dyn_16 = rule_value_dyn(lookahead_pos_1);
			if (!(rule_value_dyn_16.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  rule::value::dyn");
				return {};
			}
			success_17 = true;
			lookahead_pos_1 = rule_value_dyn_16.it;
			if (!success_17) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  rule::value::dyn");
				return {};
			}
			_0 = rule_value_dyn_16.node;
			success_1 = true;
			break;
		}
	}
	pos = lookahead_pos_1;
	if (!success_1) {
		raise_error(*pos, "ISPA match failure: no LL(k) alternative matched | grammar: @  ( name |  rule::value::group |  rule::value::dyn |  rule::value::STRING |  rule::value::CGROUP |  rule::value::ANY |  rule::value::SPACE |  rule::value::NOSPACE)");
		return {};
	}
	Types::rule::value::pattern result;
	::ISPA_STD::assign_compatible(result.value, _0);
	::ISPA_STD::MatchResult<Types::rule::value::pattern, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::rule_value_pattern<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::rule::value::pattern, ::Parser::Lexer::iterator>;
template auto Parser::Parser::rule_value_pattern<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::rule::value::pattern, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::rule_value_shared_counter_registration(IT pos) -> ::ISPA_STD::MatchResult<Types::rule::value::shared_counter_registration, IT> {
	::ISPA_STD::Node<Types::rule::value::shared_counter_registration::AUTO> rule_value_shared_counter_registration_AUTO_0;
	bool success_1;
	::ISPA_STD::Node<Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::Node<Types::ID> ID_4;
	bool success_5;
	success_1 = false;
	if (!(((*pos)).template holds<Types::rule::value::shared_counter_registration::AUTO>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  rule::value::shared_counter_registration::AUTO");
		return {};
	}
	rule_value_shared_counter_registration_AUTO_0 = ((*pos)).template to_node<::ISPA_STD::Node<Types::rule::value::shared_counter_registration::AUTO>>();
	success_1 = true;
	pos++;
	success_3 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_2 = ((*pos)).template to_node<::ISPA_STD::Node<Types::__WS>>();
		success_3 = true;
		pos++;
	}
	success_5 = false;
	if (!(((*pos)).template holds<Types::ID>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar: @  ID");
		return {};
	}
	ID_4 = ((*pos)).template to_node<::ISPA_STD::Node<Types::ID>>();
	success_5 = true;
	pos++;
	Types::rule::value::shared_counter_registration result;
	::ISPA_STD::assign_compatible(result.value, ID_4);
	::ISPA_STD::MatchResult<Types::rule::value::shared_counter_registration, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::rule_value_shared_counter_registration<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::rule::value::shared_counter_registration, ::Parser::Lexer::iterator>;
template auto Parser::Parser::rule_value_shared_counter_registration<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::rule::value::shared_counter_registration, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::rule_value_var_capture(IT pos) -> ::ISPA_STD::MatchResult<Types::rule::value::var_capture, IT> {
	::ISPA_STD::Node<Types::AMPERSAND> AMPERSAND_0;
	bool success_1;
	::ISPA_STD::Node<Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::Node<Types::ID> ID_4;
	bool success_5;
	success_1 = false;
	if (!(((*pos)).template holds<Types::AMPERSAND>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  AMPERSAND");
		return {};
	}
	AMPERSAND_0 = ((*pos)).template to_node<::ISPA_STD::Node<Types::AMPERSAND>>();
	success_1 = true;
	pos++;
	success_3 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_2 = ((*pos)).template to_node<::ISPA_STD::Node<Types::__WS>>();
		success_3 = true;
		pos++;
	}
	success_5 = false;
	if (!(((*pos)).template holds<Types::ID>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar: @  ID");
		return {};
	}
	ID_4 = ((*pos)).template to_node<::ISPA_STD::Node<Types::ID>>();
	success_5 = true;
	pos++;
	Types::rule::value::var_capture result;
	::ISPA_STD::assign_compatible(result.value, ID_4);
	::ISPA_STD::MatchResult<Types::rule::value::var_capture, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::rule_value_var_capture<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::rule::value::var_capture, ::Parser::Lexer::iterator>;
template auto Parser::Parser::rule_value_var_capture<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::rule::value::var_capture, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::stmt(IT pos) -> ::ISPA_STD::MatchResult<Types::stmt, IT> {
	::ISPA_STD::Node<Types::PY_RAW> PY_RAW_0;
	bool success_1;
	success_1 = false;
	if (!(((*pos)).template holds<Types::PY_RAW>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar: @  PY_RAW");
		return {};
	}
	PY_RAW_0 = ((*pos)).template to_node<::ISPA_STD::Node<Types::PY_RAW>>();
	success_1 = true;
	pos++;
	Types::stmt result;
	::ISPA_STD::assign_compatible(result.value, PY_RAW_0);
	::ISPA_STD::MatchResult<Types::stmt, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::stmt<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::stmt, ::Parser::Lexer::iterator>;
template auto Parser::Parser::stmt<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::stmt, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::template_params(IT pos) -> ::ISPA_STD::MatchResult<Types::template_params, IT> {
	::ISPA_STD::Node<Types::template_params::LESS_THAN_SIGN> template_params_LESS_THAN_SIGN_0;
	bool success_1;
	::ISPA_STD::Node<Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::MatchResult<Types::param, IT> param_4;
	bool success_5;
	::ISPA_STD::Node<Types::__WS> __WS_6;
	bool success_7;
	::ISPA_STD::Node<Types::template_params::GREATER_THAN_SIGN> template_params_GREATER_THAN_SIGN_8;
	bool success_9;
	success_1 = false;
	if (!(((*pos)).template holds<Types::template_params::LESS_THAN_SIGN>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  template_params::LESS_THAN_SIGN");
		return {};
	}
	template_params_LESS_THAN_SIGN_0 = ((*pos)).template to_node<::ISPA_STD::Node<Types::template_params::LESS_THAN_SIGN>>();
	success_1 = true;
	pos++;
	success_3 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_2 = ((*pos)).template to_node<::ISPA_STD::Node<Types::__WS>>();
		success_3 = true;
		pos++;
	}
	success_5 = false;
	param_4 = param(pos);
	if (param_4.status) {
		success_5 = true;
		pos = param_4.it;
	}
	success_7 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_6 = ((*pos)).template to_node<::ISPA_STD::Node<Types::__WS>>();
		success_7 = true;
		pos++;
	}
	success_9 = false;
	if (!(((*pos)).template holds<Types::template_params::GREATER_THAN_SIGN>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  template_params::GREATER_THAN_SIGN");
		return {};
	}
	template_params_GREATER_THAN_SIGN_8 = ((*pos)).template to_node<::ISPA_STD::Node<Types::template_params::GREATER_THAN_SIGN>>();
	success_9 = true;
	pos++;
	Types::template_params result;
	::ISPA_STD::assign_compatible(result.value, param_4.node);
	::ISPA_STD::MatchResult<Types::template_params, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::template_params<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::template_params, ::Parser::Lexer::iterator>;
template auto Parser::Parser::template_params<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::template_params, ::Parser::Lexer::lazy_iterator>;
auto Parser::Parser::parseFromTokens() -> void {
	tree = main(Lexer::iterator(lexer)).node.data();
}
auto Parser::Parser::lazyParse() -> void {
	Lexer lexer;
	tree = main(Lexer::lazy_iterator(lexer, text)).node.data();
}
