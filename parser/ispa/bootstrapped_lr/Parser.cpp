#include "Parser.h"

#include <ispastdlib/dfa_api.hpp>
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
auto Parser::FlatTypes::advanced_rule___grp4::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("advanced_rule___grp4", true);
}
auto Parser::FlatTypes::advanced_rule___grp4::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::advanced_rule___grp4::to_string() const -> std::string {
	return ::ISPA_STD::concat("advanced_rule___grp4 {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, advanced_rule___grp4 value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::advanced_rule___grp4___rop0::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("advanced_rule___grp4___rop0", true);
}
auto Parser::FlatTypes::advanced_rule___grp4___rop0::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::advanced_rule___grp4___rop0::to_string() const -> std::string {
	return ::ISPA_STD::concat("advanced_rule___grp4___rop0 {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, advanced_rule___grp4___rop0 value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::advanced_rule___grp4___tail::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("advanced_rule___grp4___tail", true);
}
auto Parser::FlatTypes::advanced_rule___grp4___tail::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::advanced_rule___grp4___tail::to_string() const -> std::string {
	return ::ISPA_STD::concat("advanced_rule___grp4___tail {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, advanced_rule___grp4___tail value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::advanced_rule___q2::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("advanced_rule___q2", true);
}
auto Parser::FlatTypes::advanced_rule___q2::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::advanced_rule___q2::to_string() const -> std::string {
	return ::ISPA_STD::concat("advanced_rule___q2 {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, advanced_rule___q2 value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::advanced_rule___q2___tail::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("advanced_rule___q2___tail", true);
}
auto Parser::FlatTypes::advanced_rule___q2___tail::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::advanced_rule___q2___tail::to_string() const -> std::string {
	return ::ISPA_STD::concat("advanced_rule___q2___tail {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, advanced_rule___q2___tail value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::advanced_rule_regular_match___q2::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("advanced_rule_regular_match___q2", true);
}
auto Parser::FlatTypes::advanced_rule_regular_match___q2::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::advanced_rule_regular_match___q2::to_string() const -> std::string {
	return ::ISPA_STD::concat("advanced_rule_regular_match___q2 {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, advanced_rule_regular_match___q2 value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::advanced_rule_regular_match___q2___tail::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("advanced_rule_regular_match___q2___tail", true);
}
auto Parser::FlatTypes::advanced_rule_regular_match___q2___tail::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::advanced_rule_regular_match___q2___tail::to_string() const -> std::string {
	return ::ISPA_STD::concat("advanced_rule_regular_match___q2___tail {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, advanced_rule_regular_match___q2___tail value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::advanced_rule_regular_match___rop4::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("advanced_rule_regular_match___rop4", true);
}
auto Parser::FlatTypes::advanced_rule_regular_match___rop4::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::advanced_rule_regular_match___rop4::to_string() const -> std::string {
	return ::ISPA_STD::concat("advanced_rule_regular_match___rop4 {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, advanced_rule_regular_match___rop4 value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::advanced_rule_regular_match_unpack___q2::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("advanced_rule_regular_match_unpack___q2", true);
}
auto Parser::FlatTypes::advanced_rule_regular_match_unpack___q2::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::advanced_rule_regular_match_unpack___q2::to_string() const -> std::string {
	return ::ISPA_STD::concat("advanced_rule_regular_match_unpack___q2 {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, advanced_rule_regular_match_unpack___q2 value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::advanced_rule_regular_match_unpack___q2___tail::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("advanced_rule_regular_match_unpack___q2___tail", true);
}
auto Parser::FlatTypes::advanced_rule_regular_match_unpack___q2___tail::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::advanced_rule_regular_match_unpack___q2___tail::to_string() const -> std::string {
	return ::ISPA_STD::concat("advanced_rule_regular_match_unpack___q2___tail {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, advanced_rule_regular_match_unpack___q2___tail value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::grammar___q0::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("grammar___q0", true);
}
auto Parser::FlatTypes::grammar___q0::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::grammar___q0::to_string() const -> std::string {
	return ::ISPA_STD::concat("grammar___q0 {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, grammar___q0 value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::grammar___q0___tail::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("grammar___q0___tail", true);
}
auto Parser::FlatTypes::grammar___q0___tail::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::grammar___q0___tail::to_string() const -> std::string {
	return ::ISPA_STD::concat("grammar___q0___tail {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, grammar___q0___tail value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::grammar___rop4::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("grammar___rop4", true);
}
auto Parser::FlatTypes::grammar___rop4::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::grammar___rop4::to_string() const -> std::string {
	return ::ISPA_STD::concat("grammar___rop4 {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, grammar___rop4 value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::main___grp0::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("main___grp0", true);
}
auto Parser::FlatTypes::main___grp0::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::main___grp0::to_string() const -> std::string {
	return ::ISPA_STD::concat("main___grp0 {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, main___grp0 value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::main___grp0___rop0::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("main___grp0___rop0", true);
}
auto Parser::FlatTypes::main___grp0___rop0::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::main___grp0___rop0::to_string() const -> std::string {
	return ::ISPA_STD::concat("main___grp0___rop0 {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, main___grp0___rop0 value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::main___grp0___tail::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("main___grp0___tail", true);
}
auto Parser::FlatTypes::main___grp0___tail::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::main___grp0___tail::to_string() const -> std::string {
	return ::ISPA_STD::concat("main___grp0___tail {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, main___grp0___tail value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::name___grp2::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("name___grp2", true);
}
auto Parser::FlatTypes::name___grp2::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::name___grp2::to_string() const -> std::string {
	return ::ISPA_STD::concat("name___grp2 {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, name___grp2 value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::name___grp2___tail::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("name___grp2___tail", true);
}
auto Parser::FlatTypes::name___grp2___tail::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::name___grp2___tail::to_string() const -> std::string {
	return ::ISPA_STD::concat("name___grp2___tail {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, name___grp2___tail value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::name___q4::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("name___q4", true);
}
auto Parser::FlatTypes::name___q4::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::name___q4::to_string() const -> std::string {
	return ::ISPA_STD::concat("name___q4 {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, name___q4 value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::name___q6::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("name___q6", true);
}
auto Parser::FlatTypes::name___q6::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::name___q6::to_string() const -> std::string {
	return ::ISPA_STD::concat("name___q6 {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, name___q6 value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::param___grp2::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("param___grp2", true);
}
auto Parser::FlatTypes::param___grp2::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::param___grp2::to_string() const -> std::string {
	return ::ISPA_STD::concat("param___grp2 {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, param___grp2 value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::param___grp2___tail::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("param___grp2___tail", true);
}
auto Parser::FlatTypes::param___grp2___tail::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::param___grp2___tail::to_string() const -> std::string {
	return ::ISPA_STD::concat("param___grp2___tail {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, param___grp2___tail value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::params___q2::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("params___q2", true);
}
auto Parser::FlatTypes::params___q2::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::params___q2::to_string() const -> std::string {
	return ::ISPA_STD::concat("params___q2 {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, params___q2 value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::rule___q2::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("rule___q2", true);
}
auto Parser::FlatTypes::rule___q2::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::rule___q2::to_string() const -> std::string {
	return ::ISPA_STD::concat("rule___q2 {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, rule___q2 value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::rule___q2___tail::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("rule___q2___tail", true);
}
auto Parser::FlatTypes::rule___q2___tail::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::rule___q2___tail::to_string() const -> std::string {
	return ::ISPA_STD::concat("rule___q2___tail {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, rule___q2___tail value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::rule___q4::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("rule___q4", true);
}
auto Parser::FlatTypes::rule___q4::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::rule___q4::to_string() const -> std::string {
	return ::ISPA_STD::concat("rule___q4 {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, rule___q4 value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::rule___q6::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("rule___q6", true);
}
auto Parser::FlatTypes::rule___q6::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::rule___q6::to_string() const -> std::string {
	return ::ISPA_STD::concat("rule___q6 {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, rule___q6 value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::rule___q8::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("rule___q8", true);
}
auto Parser::FlatTypes::rule___q8::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::rule___q8::to_string() const -> std::string {
	return ::ISPA_STD::concat("rule___q8 {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, rule___q8 value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::rule___q8___tail::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("rule___q8___tail", true);
}
auto Parser::FlatTypes::rule___q8___tail::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::rule___q8___tail::to_string() const -> std::string {
	return ::ISPA_STD::concat("rule___q8___tail {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, rule___q8___tail value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::rule_ast_abbr___grp6::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("rule_ast_abbr___grp6", true);
}
auto Parser::FlatTypes::rule_ast_abbr___grp6::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::rule_ast_abbr___grp6::to_string() const -> std::string {
	return ::ISPA_STD::concat("rule_ast_abbr___grp6 {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, rule_ast_abbr___grp6 value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::rule_ast_abbr___grp6___tail::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("rule_ast_abbr___grp6___tail", true);
}
auto Parser::FlatTypes::rule_ast_abbr___grp6___tail::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::rule_ast_abbr___grp6___tail::to_string() const -> std::string {
	return ::ISPA_STD::concat("rule_ast_abbr___grp6___tail {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, rule_ast_abbr___grp6___tail value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::rule_ast_full___q4::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("rule_ast_full___q4", true);
}
auto Parser::FlatTypes::rule_ast_full___q4::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::rule_ast_full___q4::to_string() const -> std::string {
	return ::ISPA_STD::concat("rule_ast_full___q4 {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, rule_ast_full___q4 value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::rule_ast_full___q4___tail::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("rule_ast_full___q4___tail", true);
}
auto Parser::FlatTypes::rule_ast_full___q4___tail::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::rule_ast_full___q4___tail::to_string() const -> std::string {
	return ::ISPA_STD::concat("rule_ast_full___q4___tail {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, rule_ast_full___q4___tail value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::rule_ast_single_value___rop2::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("rule_ast_single_value___rop2", true);
}
auto Parser::FlatTypes::rule_ast_single_value___rop2::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::rule_ast_single_value___rop2::to_string() const -> std::string {
	return ::ISPA_STD::concat("rule_ast_single_value___rop2 {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, rule_ast_single_value___rop2 value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::rule_f_binding___grp6::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("rule_f_binding___grp6", true);
}
auto Parser::FlatTypes::rule_f_binding___grp6::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::rule_f_binding___grp6::to_string() const -> std::string {
	return ::ISPA_STD::concat("rule_f_binding___grp6 {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, rule_f_binding___grp6 value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::rule_f_binding___grp6___tail::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("rule_f_binding___grp6___tail", true);
}
auto Parser::FlatTypes::rule_f_binding___grp6___tail::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::rule_f_binding___grp6___tail::to_string() const -> std::string {
	return ::ISPA_STD::concat("rule_f_binding___grp6___tail {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, rule_f_binding___grp6___tail value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::rule_value_ast_capture___q1::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("rule_value_ast_capture___q1", true);
}
auto Parser::FlatTypes::rule_value_ast_capture___q1::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::rule_value_ast_capture___q1::to_string() const -> std::string {
	return ::ISPA_STD::concat("rule_value_ast_capture___q1 {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, rule_value_ast_capture___q1 value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::rule_value_counter___q2::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("rule_value_counter___q2", true);
}
auto Parser::FlatTypes::rule_value_counter___q2::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::rule_value_counter___q2::to_string() const -> std::string {
	return ::ISPA_STD::concat("rule_value_counter___q2 {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, rule_value_counter___q2 value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::rule_value_counter_bounded___rop2::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("rule_value_counter_bounded___rop2", true);
}
auto Parser::FlatTypes::rule_value_counter_bounded___rop2::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::rule_value_counter_bounded___rop2::to_string() const -> std::string {
	return ::ISPA_STD::concat("rule_value_counter_bounded___rop2 {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, rule_value_counter_bounded___rop2 value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::rule_value_dyn___rop2::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("rule_value_dyn___rop2", true);
}
auto Parser::FlatTypes::rule_value_dyn___rop2::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::rule_value_dyn___rop2::to_string() const -> std::string {
	return ::ISPA_STD::concat("rule_value_dyn___rop2 {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, rule_value_dyn___rop2 value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::rule_value_fail_capture___q1::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("rule_value_fail_capture___q1", true);
}
auto Parser::FlatTypes::rule_value_fail_capture___q1::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::rule_value_fail_capture___q1::to_string() const -> std::string {
	return ::ISPA_STD::concat("rule_value_fail_capture___q1 {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, rule_value_fail_capture___q1 value) -> std::ostream & {
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
auto Parser::FlatTypes::rule_value_group___q2::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("rule_value_group___q2", true);
}
auto Parser::FlatTypes::rule_value_group___q2::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::rule_value_group___q2::to_string() const -> std::string {
	return ::ISPA_STD::concat("rule_value_group___q2 {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, rule_value_group___q2 value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::rule_value_group___q2___tail::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("rule_value_group___q2___tail", true);
}
auto Parser::FlatTypes::rule_value_group___q2___tail::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::rule_value_group___q2___tail::to_string() const -> std::string {
	return ::ISPA_STD::concat("rule_value_group___q2___tail {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, rule_value_group___q2___tail value) -> std::ostream & {
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
auto Parser::FlatTypes::rule_value_mul_capture___q6::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("rule_value_mul_capture___q6", true);
}
auto Parser::FlatTypes::rule_value_mul_capture___q6::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::rule_value_mul_capture___q6::to_string() const -> std::string {
	return ::ISPA_STD::concat("rule_value_mul_capture___q6 {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, rule_value_mul_capture___q6 value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::rule_value_mul_capture___q6___tail::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("rule_value_mul_capture___q6___tail", true);
}
auto Parser::FlatTypes::rule_value_mul_capture___q6___tail::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::rule_value_mul_capture___q6___tail::to_string() const -> std::string {
	return ::ISPA_STD::concat("rule_value_mul_capture___q6___tail {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, rule_value_mul_capture___q6___tail value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::rule_value_mul_capture___rop0::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("rule_value_mul_capture___rop0", true);
}
auto Parser::FlatTypes::rule_value_mul_capture___rop0::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::rule_value_mul_capture___rop0::to_string() const -> std::string {
	return ::ISPA_STD::concat("rule_value_mul_capture___rop0 {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, rule_value_mul_capture___rop0 value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::rule_value_one_capture___q0::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("rule_value_one_capture___q0", true);
}
auto Parser::FlatTypes::rule_value_one_capture___q0::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::rule_value_one_capture___q0::to_string() const -> std::string {
	return ::ISPA_STD::concat("rule_value_one_capture___q0 {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, rule_value_one_capture___q0 value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::rule_value_one_capture___q10::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("rule_value_one_capture___q10", true);
}
auto Parser::FlatTypes::rule_value_one_capture___q10::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::rule_value_one_capture___q10::to_string() const -> std::string {
	return ::ISPA_STD::concat("rule_value_one_capture___q10 {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, rule_value_one_capture___q10 value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::rule_value_one_capture___q12::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("rule_value_one_capture___q12", true);
}
auto Parser::FlatTypes::rule_value_one_capture___q12::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::rule_value_one_capture___q12::to_string() const -> std::string {
	return ::ISPA_STD::concat("rule_value_one_capture___q12 {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, rule_value_one_capture___q12 value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::rule_value_one_capture___q2::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("rule_value_one_capture___q2", true);
}
auto Parser::FlatTypes::rule_value_one_capture___q2::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::rule_value_one_capture___q2::to_string() const -> std::string {
	return ::ISPA_STD::concat("rule_value_one_capture___q2 {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, rule_value_one_capture___q2 value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::rule_value_one_capture___q4::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("rule_value_one_capture___q4", true);
}
auto Parser::FlatTypes::rule_value_one_capture___q4::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::rule_value_one_capture___q4::to_string() const -> std::string {
	return ::ISPA_STD::concat("rule_value_one_capture___q4 {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, rule_value_one_capture___q4 value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::rule_value_one_capture___q8::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("rule_value_one_capture___q8", true);
}
auto Parser::FlatTypes::rule_value_one_capture___q8::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::rule_value_one_capture___q8::to_string() const -> std::string {
	return ::ISPA_STD::concat("rule_value_one_capture___q8 {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, rule_value_one_capture___q8 value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::rule_value_one_capture___q8___tail::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("rule_value_one_capture___q8___tail", true);
}
auto Parser::FlatTypes::rule_value_one_capture___q8___tail::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::rule_value_one_capture___q8___tail::to_string() const -> std::string {
	return ::ISPA_STD::concat("rule_value_one_capture___q8___tail {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, rule_value_one_capture___q8___tail value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::template_params___q2::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("template_params___q2", true);
}
auto Parser::FlatTypes::template_params___q2::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::template_params___q2::to_string() const -> std::string {
	return ::ISPA_STD::concat("template_params___q2 {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, template_params___q2 value) -> std::ostream & {
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
			if (captures.is_set(5)) {
				value = captures.character(5);
			} else {
				if (captures.is_set(4)) {
					value = captures.character(4);
				} else {
					if (captures.is_set(6)) {
						value = captures.character(6);
					}
				}
			}
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::rule::value::QUANTIFIER::id, Types::rule::value::QUANTIFIER{value}));
			break;
		}
		case 8: {
			char value;
			if (captures.is_set(5)) {
				value = captures.character(5);
			} else {
				if (captures.is_set(4)) {
					value = captures.character(4);
				} else {
					if (captures.is_set(6)) {
						value = captures.character(6);
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
			if (captures.is_set(5)) {
				value = captures.character(5);
			} else {
				if (captures.is_set(4)) {
					value = captures.character(4);
				} else {
					if (captures.is_set(6)) {
						value = captures.character(6);
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
::ISPA_STD::DFA::API::Table<104, 4> Parser::Lexer::action_table = {{{1, 0, ::ISPA_STD::DFA::API::null_state, 22}, {1, 26, ::ISPA_STD::DFA::API::null_state, 28}, {1, 26, ::ISPA_STD::DFA::API::null_state, 27}, {1, 26, ::ISPA_STD::DFA::API::null_state, 26}, {1, 26, ::ISPA_STD::DFA::API::null_state, 32}, {1, 26, ::ISPA_STD::DFA::API::null_state, 31}, {1, 26, ::ISPA_STD::DFA::API::null_state, 29}, {1, 14, ::ISPA_STD::DFA::API::null_state, 14}, {1, 8, ::ISPA_STD::DFA::API::null_state, 10}, {1, 10, ::ISPA_STD::DFA::API::null_state, 9}, {1, 12, ::ISPA_STD::DFA::API::null_state, 20}, {1, 26, ::ISPA_STD::DFA::API::null_state, 30}, {1, 24, ::ISPA_STD::DFA::API::null_state, 36}, {1, 24, ::ISPA_STD::DFA::API::null_state, 39}, {1, 26, ::ISPA_STD::DFA::API::null_state, 37}, {1, 11, ::ISPA_STD::DFA::API::null_state, 197}, {1, 9, ::ISPA_STD::DFA::API::null_state, 198}, {1, 15, ::ISPA_STD::DFA::API::null_state, 201}, {1, 15, ::ISPA_STD::DFA::API::null_state, 42}, {1, 13, ::ISPA_STD::DFA::API::null_state, 207}, {1, 1, ::ISPA_STD::DFA::API::null_state, 209}, {1, 6, ::ISPA_STD::DFA::API::null_state, 45}, {1, 6, ::ISPA_STD::DFA::API::null_state, 47}, {1, 6, ::ISPA_STD::DFA::API::null_state, 46}, {3, 0, 26, 209}, {1, 1, ::ISPA_STD::DFA::API::null_state, 110}, {3, 0, 26, 44}, {3, 0, 26, 209}, {1, 1, ::ISPA_STD::DFA::API::null_state, 113}, {3, 0, 26, 209}, {1, 1, ::ISPA_STD::DFA::API::null_state, 115}, {3, 0, 26, 209}, {1, 1, ::ISPA_STD::DFA::API::null_state, 117}, {3, 0, 26, 209}, {1, 1, ::ISPA_STD::DFA::API::null_state, 119}, {3, 0, 26, 209}, {1, 1, ::ISPA_STD::DFA::API::null_state, 121}, {3, 0, 26, 209}, {1, 1, ::ISPA_STD::DFA::API::null_state, 123}, {1, 25, ::ISPA_STD::DFA::API::null_state, 38}, {1, 25, ::ISPA_STD::DFA::API::null_state, 56}, {3, 24, 26, 36}, {3, 24, 26, 39}, {3, 24, 26, 38}, {1, 25, ::ISPA_STD::DFA::API::null_state, 129}, {3, 24, 26, 56}, {1, 25, ::ISPA_STD::DFA::API::null_state, 131}, {1, 16, ::ISPA_STD::DFA::API::null_state, 57}, {1, 1, ::ISPA_STD::DFA::API::null_state, 218}, {1, 7, ::ISPA_STD::DFA::API::null_state, 58}, {1, 5, ::ISPA_STD::DFA::API::null_state, 59}, {1, 5, ::ISPA_STD::DFA::API::null_state, 60}, {3, 0, 26, 218}, {1, 1, ::ISPA_STD::DFA::API::null_state, 138}, {3, 0, 26, 218}, {1, 1, ::ISPA_STD::DFA::API::null_state, 140}, {3, 0, 26, 218}, {1, 1, ::ISPA_STD::DFA::API::null_state, 142}, {3, 0, 26, 218}, {1, 1, ::ISPA_STD::DFA::API::null_state, 144}, {3, 0, 26, 218}, {1, 1, ::ISPA_STD::DFA::API::null_state, 146}, {1, 2, ::ISPA_STD::DFA::API::null_state, 67}, {3, 0, 26, 218}, {1, 1, ::ISPA_STD::DFA::API::null_state, 149}, {1, 17, ::ISPA_STD::DFA::API::null_state, 220}, {1, 7, ::ISPA_STD::DFA::API::null_state, 69}, {3, 0, 26, 218}, {1, 1, ::ISPA_STD::DFA::API::null_state, 153}, {3, 0, 26, 218}, {1, 1, ::ISPA_STD::DFA::API::null_state, 155}, {3, 0, 26, 218}, {1, 1, ::ISPA_STD::DFA::API::null_state, 157}, {3, 0, 26, 218}, {1, 1, ::ISPA_STD::DFA::API::null_state, 159}, {3, 0, 26, 218}, {1, 1, ::ISPA_STD::DFA::API::null_state, 161}, {3, 0, 26, 218}, {1, 1, ::ISPA_STD::DFA::API::null_state, 163}, {3, 6, 5, 221}, {3, 4, 6, 165}, {3, 0, 26, 218}, {1, 1, ::ISPA_STD::DFA::API::null_state, 167}, {3, 0, 26, 218}, {1, 1, ::ISPA_STD::DFA::API::null_state, 169}, {3, 0, 26, 218}, {1, 1, ::ISPA_STD::DFA::API::null_state, 171}, {3, 0, 26, 218}, {1, 1, ::ISPA_STD::DFA::API::null_state, 173}, {1, 3, ::ISPA_STD::DFA::API::null_state, 81}, {3, 20, 26, 224}, {1, 21, ::ISPA_STD::DFA::API::null_state, 176}, {3, 0, 26, 218}, {1, 1, ::ISPA_STD::DFA::API::null_state, 178}, {3, 0, 26, 218}, {1, 1, ::ISPA_STD::DFA::API::null_state, 180}, {3, 0, 26, 218}, {1, 1, ::ISPA_STD::DFA::API::null_state, 182}, {3, 0, 26, 218}, {1, 1, ::ISPA_STD::DFA::API::null_state, 184}, {3, 18, 26, 227}, {1, 19, ::ISPA_STD::DFA::API::null_state, 186}, {3, 22, 26, 228}, {1, 23, ::ISPA_STD::DFA::API::null_state, 188}}};
std::array<::ISPA_STD::DFA::API::DFADebug, 1> Parser::Lexer::debug_array = {::ISPA_STD::DFA::API::DFADebug {"<Undefined>", "", 0, -1, -1, -1, 0, 1, '\000'}};
std::unordered_map<long long, std::unordered_map<long long, long long>> Parser::Lexer::debug_index = { { 0, { { 1, 0 }, { 2, 0 }, { 3, 0 }, { 4, 0 }, { 5, 0 }, { 6, 0 }, { 7, 0 }, { 8, 0 }, { 9, 0 }, { 12, 0 }, { 13, 0 }, { 14, 0 }, { 17, 0 }, { 18, 0 }, { 19, 0 }, { 20, 0 }, { 21, 0 }, { 23, 0 }, { 25, 0 }, { 26, 0 }, { 27, 0 }, { 46, 0 }, { 47, 0 }, { 48, 0 } } }, { 1, { { 1, 0 } } }, { 2, { { 7, 0 } } }, { 3, { { 25, 0 } } }, { 12, { { 21, 0 } } }, { 14, { { 15, 0 }, { 16, 0 } } }, { 18, { { 21, 0 } } }, { 22, { { 15, 0 }, { 16, 0 }, { 24, 0 }, { 29, 0 }, { 30, 0 }, { 31, 0 }, { 32, 0 }, { 33, 0 }, { 34, 0 }, { 35, 0 }, { 36, 0 }, { 37, 0 }, { 38, 0 }, { 39, 0 }, { 40, 0 }, { 41, 0 }, { 42, 0 }, { 43, 0 }, { 44, 0 }, { 45, 0 } } }, { 24, { { 42, 0 } } }, { 26, { { 32, 0 } } }, { 27, { { 44, 0 } } }, { 28, { { 29, 0 } } }, { 29, { { 39, 0 } } }, { 30, { { 29, 0 } } }, { 31, { { 46, 0 } } }, { 32, { { 36, 0 } } }, { 36, { { 0, 0 }, { 1, 0 }, { 3, 0 }, { 4, 0 }, { 5, 0 }, { 6, 0 }, { 8, 0 }, { 9, 0 }, { 10, 0 }, { 11, 0 }, { 12, 0 }, { 13, 0 }, { 14, 0 }, { 15, 0 }, { 16, 0 }, { 17, 0 }, { 18, 0 }, { 19, 0 }, { 20, 0 }, { 21, 0 }, { 22, 0 }, { 23, 0 }, { 24, 0 }, { 25, 0 }, { 26, 0 }, { 27, 0 }, { 28, 0 }, { 29, 0 }, { 30, 0 }, { 31, 0 }, { 32, 0 }, { 33, 0 }, { 34, 0 }, { 35, 0 }, { 36, 0 }, { 37, 0 }, { 38, 0 }, { 39, 0 }, { 40, 0 }, { 41, 0 }, { 42, 0 }, { 43, 0 }, { 44, 0 }, { 45, 0 }, { 46, 0 }, { 47, 0 }, { 48, 0 } } }, { 39, { { 0, 0 }, { 1, 0 }, { 2, 0 }, { 3, 0 }, { 4, 0 }, { 5, 0 }, { 6, 0 }, { 7, 0 }, { 8, 0 }, { 9, 0 }, { 10, 0 }, { 11, 0 }, { 12, 0 }, { 13, 0 }, { 14, 0 }, { 15, 0 }, { 16, 0 }, { 17, 0 }, { 18, 0 }, { 19, 0 }, { 20, 0 }, { 21, 0 }, { 22, 0 }, { 23, 0 }, { 24, 0 }, { 25, 0 }, { 26, 0 }, { 27, 0 }, { 28, 0 }, { 29, 0 }, { 30, 0 }, { 31, 0 }, { 32, 0 }, { 33, 0 }, { 34, 0 }, { 35, 0 }, { 36, 0 }, { 37, 0 }, { 38, 0 }, { 39, 0 }, { 40, 0 }, { 41, 0 }, { 42, 0 }, { 43, 0 }, { 44, 0 }, { 45, 0 }, { 46, 0 }, { 47, 0 }, { 48, 0 } } }, { 44, { { 15, 0 }, { 16, 0 }, { 24, 0 }, { 29, 0 }, { 30, 0 }, { 31, 0 }, { 32, 0 }, { 33, 0 }, { 34, 0 }, { 35, 0 }, { 36, 0 }, { 37, 0 }, { 38, 0 }, { 39, 0 }, { 40, 0 }, { 41, 0 }, { 42, 0 }, { 43, 0 }, { 44, 0 }, { 45, 0 } } }, { 45, { { 0, 0 }, { 1, 0 }, { 2, 0 }, { 3, 0 }, { 4, 0 }, { 5, 0 }, { 6, 0 }, { 7, 0 }, { 8, 0 }, { 9, 0 }, { 10, 0 }, { 11, 0 }, { 12, 0 }, { 13, 0 }, { 14, 0 }, { 15, 0 }, { 16, 0 }, { 17, 0 }, { 18, 0 }, { 19, 0 }, { 20, 0 }, { 21, 0 }, { 22, 0 }, { 23, 0 }, { 24, 0 }, { 25, 0 }, { 26, 0 }, { 28, 0 }, { 29, 0 }, { 30, 0 }, { 31, 0 }, { 32, 0 }, { 33, 0 }, { 34, 0 }, { 35, 0 }, { 36, 0 }, { 37, 0 }, { 38, 0 }, { 39, 0 }, { 40, 0 }, { 41, 0 }, { 42, 0 }, { 43, 0 }, { 44, 0 }, { 45, 0 }, { 46, 0 }, { 47, 0 }, { 48, 0 } } }, { 46, { { 0, 0 }, { 1, 0 }, { 2, 0 }, { 3, 0 }, { 4, 0 }, { 5, 0 }, { 6, 0 }, { 7, 0 }, { 8, 0 }, { 9, 0 }, { 10, 0 }, { 11, 0 }, { 12, 0 }, { 13, 0 }, { 14, 0 }, { 15, 0 }, { 16, 0 }, { 17, 0 }, { 18, 0 }, { 19, 0 }, { 20, 0 }, { 21, 0 }, { 22, 0 }, { 23, 0 }, { 24, 0 }, { 25, 0 }, { 26, 0 }, { 27, 0 }, { 28, 0 }, { 29, 0 }, { 30, 0 }, { 31, 0 }, { 32, 0 }, { 33, 0 }, { 34, 0 }, { 35, 0 }, { 36, 0 }, { 37, 0 }, { 38, 0 }, { 39, 0 }, { 40, 0 }, { 41, 0 }, { 42, 0 }, { 43, 0 }, { 44, 0 }, { 45, 0 }, { 46, 0 }, { 47, 0 }, { 48, 0 } } }, { 48, { { 15, 0 } } }, { 49, { { 40, 0 } } }, { 50, { { 43, 0 } } }, { 51, { { 35, 0 } } }, { 52, { { 37, 0 } } }, { 53, { { 43, 0 } } }, { 55, { { 35, 0 } } }, { 56, { { 0, 0 }, { 1, 0 }, { 3, 0 }, { 4, 0 }, { 5, 0 }, { 6, 0 }, { 8, 0 }, { 9, 0 }, { 10, 0 }, { 11, 0 }, { 12, 0 }, { 13, 0 }, { 14, 0 }, { 15, 0 }, { 16, 0 }, { 17, 0 }, { 18, 0 }, { 19, 0 }, { 20, 0 }, { 21, 0 }, { 22, 0 }, { 23, 0 }, { 24, 0 }, { 25, 0 }, { 26, 0 }, { 27, 0 }, { 28, 0 }, { 29, 0 }, { 30, 0 }, { 31, 0 }, { 32, 0 }, { 33, 0 }, { 34, 0 }, { 35, 0 }, { 36, 0 }, { 37, 0 }, { 38, 0 }, { 39, 0 }, { 40, 0 }, { 41, 0 }, { 42, 0 }, { 43, 0 }, { 44, 0 }, { 45, 0 }, { 46, 0 }, { 47, 0 }, { 48, 0 } } }, { 57, { { 15, 0 }, { 16, 0 } } }, { 59, { { 0, 0 }, { 1, 0 }, { 2, 0 }, { 3, 0 }, { 4, 0 }, { 5, 0 }, { 6, 0 }, { 7, 0 }, { 8, 0 }, { 9, 0 }, { 10, 0 }, { 11, 0 }, { 12, 0 }, { 13, 0 }, { 14, 0 }, { 15, 0 }, { 16, 0 }, { 17, 0 }, { 18, 0 }, { 19, 0 }, { 20, 0 }, { 21, 0 }, { 22, 0 }, { 23, 0 }, { 24, 0 }, { 25, 0 }, { 26, 0 }, { 28, 0 }, { 29, 0 }, { 30, 0 }, { 31, 0 }, { 32, 0 }, { 33, 0 }, { 34, 0 }, { 35, 0 }, { 36, 0 }, { 37, 0 }, { 38, 0 }, { 39, 0 }, { 40, 0 }, { 41, 0 }, { 42, 0 }, { 43, 0 }, { 44, 0 }, { 45, 0 }, { 46, 0 }, { 47, 0 }, { 48, 0 } } }, { 60, { { 0, 0 }, { 1, 0 }, { 2, 0 }, { 3, 0 }, { 4, 0 }, { 5, 0 }, { 6, 0 }, { 7, 0 }, { 8, 0 }, { 9, 0 }, { 10, 0 }, { 11, 0 }, { 12, 0 }, { 13, 0 }, { 14, 0 }, { 15, 0 }, { 16, 0 }, { 17, 0 }, { 18, 0 }, { 19, 0 }, { 20, 0 }, { 21, 0 }, { 22, 0 }, { 23, 0 }, { 24, 0 }, { 25, 0 }, { 26, 0 }, { 27, 0 }, { 28, 0 }, { 29, 0 }, { 30, 0 }, { 31, 0 }, { 32, 0 }, { 33, 0 }, { 34, 0 }, { 35, 0 }, { 36, 0 }, { 37, 0 }, { 38, 0 }, { 39, 0 }, { 40, 0 }, { 41, 0 }, { 42, 0 }, { 43, 0 }, { 44, 0 }, { 45, 0 }, { 46, 0 }, { 47, 0 }, { 48, 0 } } }, { 62, { { 32, 0 } } }, { 63, { { 32, 0 } } }, { 64, { { 37, 0 } } }, { 65, { { 35, 0 } } }, { 66, { { 30, 0 } } }, { 67, { { 45, 0 } } }, { 68, { { 40, 0 } } }, { 70, { { 39, 0 } } }, { 71, { { 41, 0 } } }, { 73, { { 39, 0 } } }, { 74, { { 34, 0 } } }, { 77, { { 31, 0 } } }, { 78, { { 39, 0 } } }, { 79, { { 32, 0 } } }, { 82, { { 42, 0 } } } };
auto Parser::Parser::lr_k() -> std::size_t {
	return 2;
}
auto Parser::Parser::lr_is_space(const Token& token) -> bool {
	return token.kind() == Tokens::__WS::id;
}
auto Parser::Parser::lr_space(std::size_t rule, std::size_t gap) -> bool {
	if (rule == 0 && gap == 1) {
		return true;
	}
	if (rule == 0 && gap == 2) {
		return true;
	}
	if (rule == 0 && gap == 3) {
		return true;
	}
	if (rule == 6 && gap == 0) {
		return true;
	}
	if (rule == 10 && gap == 0) {
		return true;
	}
	if (rule == 11 && gap == 1) {
		return true;
	}
	if (rule == 12 && gap == 1) {
		return true;
	}
	if (rule == 13 && gap == 1) {
		return true;
	}
	if (rule == 13 && gap == 2) {
		return true;
	}
	if (rule == 16 && gap == 0) {
		return true;
	}
	if (rule == 19 && gap == 1) {
		return true;
	}
	if (rule == 22 && gap == 0) {
		return true;
	}
	if (rule == 23 && gap == 1) {
		return true;
	}
	if (rule == 23 && gap == 2) {
		return true;
	}
	if (rule == 25 && gap == 1) {
		return true;
	}
	if (rule == 25 && gap == 2) {
		return true;
	}
	if (rule == 26 && gap == 1) {
		return true;
	}
	if (rule == 26 && gap == 2) {
		return true;
	}
	if (rule == 27 && gap == 1) {
		return true;
	}
	if (rule == 27 && gap == 2) {
		return true;
	}
	if (rule == 31 && gap == 0) {
		return true;
	}
	if (rule == 34 && gap == 1) {
		return true;
	}
	if (rule == 34 && gap == 2) {
		return true;
	}
	if (rule == 41 && gap == 0) {
		return true;
	}
	if (rule == 42 && gap == 1) {
		return true;
	}
	if (rule == 42 && gap == 2) {
		return true;
	}
	if (rule == 42 && gap == 3) {
		return true;
	}
	if (rule == 44 && gap == 1) {
		return true;
	}
	if (rule == 46 && gap == 0) {
		return true;
	}
	if (rule == 46 && gap == 1) {
		return true;
	}
	if (rule == 51 && gap == 1) {
		return true;
	}
	if (rule == 53 && gap == 1) {
		return true;
	}
	if (rule == 55 && gap == 0) {
		return true;
	}
	if (rule == 55 && gap == 1) {
		return true;
	}
	if (rule == 56 && gap == 1) {
		return true;
	}
	if (rule == 56 && gap == 2) {
		return true;
	}
	if (rule == 59 && gap == 1) {
		return true;
	}
	if (rule == 59 && gap == 2) {
		return true;
	}
	if (rule == 59 && gap == 3) {
		return true;
	}
	if (rule == 59 && gap == 4) {
		return true;
	}
	if (rule == 59 && gap == 5) {
		return true;
	}
	if (rule == 62 && gap == 0) {
		return true;
	}
	if (rule == 70 && gap == 0) {
		return true;
	}
	if (rule == 74 && gap == 1) {
		return true;
	}
	if (rule == 74 && gap == 2) {
		return true;
	}
	if (rule == 74 && gap == 3) {
		return true;
	}
	if (rule == 74 && gap == 4) {
		return true;
	}
	if (rule == 76 && gap == 1) {
		return true;
	}
	if (rule == 78 && gap == 0) {
		return true;
	}
	if (rule == 78 && gap == 1) {
		return true;
	}
	if (rule == 79 && gap == 1) {
		return true;
	}
	if (rule == 79 && gap == 2) {
		return true;
	}
	if (rule == 79 && gap == 3) {
		return true;
	}
	if (rule == 82 && gap == 0) {
		return true;
	}
	if (rule == 83 && gap == 1) {
		return true;
	}
	if (rule == 83 && gap == 2) {
		return true;
	}
	if (rule == 84 && gap == 1) {
		return true;
	}
	if (rule == 84 && gap == 2) {
		return true;
	}
	if (rule == 87 && gap == 1) {
		return true;
	}
	if (rule == 87 && gap == 2) {
		return true;
	}
	if (rule == 87 && gap == 3) {
		return true;
	}
	if (rule == 87 && gap == 4) {
		return true;
	}
	if (rule == 89 && gap == 1) {
		return true;
	}
	if (rule == 91 && gap == 0) {
		return true;
	}
	if (rule == 91 && gap == 1) {
		return true;
	}
	if (rule == 95 && gap == 1) {
		return true;
	}
	if (rule == 99 && gap == 1) {
		return true;
	}
	if (rule == 102 && gap == 1) {
		return true;
	}
	if (rule == 106 && gap == 1) {
		return true;
	}
	if (rule == 109 && gap == 1) {
		return true;
	}
	if (rule == 109 && gap == 2) {
		return true;
	}
	if (rule == 113 && gap == 1) {
		return true;
	}
	if (rule == 113 && gap == 2) {
		return true;
	}
	if (rule == 116 && gap == 0) {
		return true;
	}
	if (rule == 117 && gap == 1) {
		return true;
	}
	if (rule == 117 && gap == 2) {
		return true;
	}
	if (rule == 117 && gap == 3) {
		return true;
	}
	if (rule == 117 && gap == 4) {
		return true;
	}
	if (rule == 120 && gap == 0) {
		return true;
	}
	if (rule == 123 && gap == 1) {
		return true;
	}
	if (rule == 123 && gap == 2) {
		return true;
	}
	if (rule == 123 && gap == 3) {
		return true;
	}
	if (rule == 123 && gap == 4) {
		return true;
	}
	if (rule == 123 && gap == 5) {
		return true;
	}
	if (rule == 123 && gap == 6) {
		return true;
	}
	if (rule == 137 && gap == 0) {
		return true;
	}
	if (rule == 146 && gap == 1) {
		return true;
	}
	if (rule == 147 && gap == 1) {
		return true;
	}
	if (rule == 149 && gap == 1) {
		return true;
	}
	if (rule == 149 && gap == 2) {
		return true;
	}
	return false;
}
auto Parser::Parser::lr_action(std::size_t state, const std::vector<std::size_t>& window) -> long long {
	if (state == 0 && window.at(0) == static_cast<std::size_t>(-1)) {
		return -37;
	}
	if (state == 0 && window.at(0) == Tokens::FAIL::id) {
		return 2;
	}
	if (state == 0 && window.at(0) == Tokens::ID::id) {
		return -29;
	}
	if (state == 0 && window.at(0) == Tokens::grammar::modifier::AUTO::id) {
		return 7;
	}
	if (state == 1 && window.at(0) == Tokens::ID::id) {
		return 11;
	}
	if (state == 2 && window.at(0) == static_cast<std::size_t>(-1)) {
		return -40;
	}
	if (state == 2 && window.at(0) == Tokens::FAIL::id) {
		return -40;
	}
	if (state == 2 && window.at(0) == Tokens::ID::id) {
		return -40;
	}
	if (state == 2 && window.at(0) == Tokens::grammar::modifier::AUTO::id) {
		return -40;
	}
	if (state == 3 && window.at(0) == static_cast<std::size_t>(-1)) {
		return -39;
	}
	if (state == 3 && window.at(0) == Tokens::FAIL::id) {
		return -39;
	}
	if (state == 3 && window.at(0) == Tokens::ID::id) {
		return -39;
	}
	if (state == 3 && window.at(0) == Tokens::grammar::modifier::AUTO::id) {
		return -39;
	}
	if (state == 4 && window.at(0) == Tokens::ID::id) {
		return 11;
	}
	if (state == 5 && window.at(0) == Tokens::ID::id) {
		return -31;
	}
	if (state == 5 && window.at(0) == Tokens::grammar::modifier::AUTO::id) {
		return 7;
	}
	if (state == 6 && window.at(0) == Tokens::grammar::modifier::MOD::id) {
		return 16;
	}
	if (state == 7 && window.at(0) == static_cast<std::size_t>(-1)) {
		return 0;
	}
	if (state == 8 && window.at(0) == static_cast<std::size_t>(-1)) {
		return -36;
	}
	if (state == 9 && window.at(0) == static_cast<std::size_t>(-1)) {
		return -41;
	}
	if (state == 9 && window.at(0) == Tokens::FAIL::id) {
		return 2;
	}
	if (state == 9 && window.at(0) == Tokens::ID::id) {
		return -29;
	}
	if (state == 9 && window.at(0) == Tokens::grammar::modifier::AUTO::id) {
		return 7;
	}
	if (state == 10 && window.at(0) == Tokens::AMPERSAND::id) {
		return -44;
	}
	if (state == 10 && window.at(0) == Tokens::COLON::id) {
		return -44;
	}
	if (state == 10 && window.at(0) == Tokens::COMMERCIAL_AT::id) {
		return -44;
	}
	if (state == 10 && window.at(0) == Tokens::ID::id) {
		return -44;
	}
	if (state == 10 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -44;
	}
	if (state == 10 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -44;
	}
	if (state == 10 && window.at(0) == Tokens::PERCENT_SIGN::id) {
		return -44;
	}
	if (state == 10 && window.at(0) == Tokens::PY_RAW::id) {
		return -44;
	}
	if (state == 10 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -44;
	}
	if (state == 10 && window.at(0) == Tokens::SEMICOLON::id) {
		return -44;
	}
	if (state == 10 && window.at(0) == Tokens::rule::nested_rule::NUMBER_SIGN::id) {
		return -44;
	}
	if (state == 10 && window.at(0) == Tokens::rule::value::ANY::id) {
		return -44;
	}
	if (state == 10 && window.at(0) == Tokens::rule::value::CGROUP::id) {
		return -44;
	}
	if (state == 10 && window.at(0) == Tokens::rule::value::NOSPACE::id) {
		return -44;
	}
	if (state == 10 && window.at(0) == Tokens::rule::value::QUANTIFIER::id) {
		return -44;
	}
	if (state == 10 && window.at(0) == Tokens::rule::value::SPACE::id) {
		return -44;
	}
	if (state == 10 && window.at(0) == Tokens::rule::value::STRING::id) {
		return -44;
	}
	if (state == 10 && window.at(0) == Tokens::rule::value::alternative::VERTICAL_LINE::id) {
		return -44;
	}
	if (state == 10 && window.at(0) == Tokens::rule::value::dyn::DOLLAR_SIGN::id) {
		return -44;
	}
	if (state == 10 && window.at(0) == Tokens::rule::value::shared_counter_registration::AUTO::id) {
		return -44;
	}
	if (state == 10 && window.at(0) == Tokens::template_params::LESS_THAN_SIGN::id) {
		return -44;
	}
	if (state == 11 && window.at(0) == Tokens::PY_RAW::id) {
		return 21;
	}
	if (state == 12 && window.at(0) == Tokens::COLON::id) {
		return 23;
	}
	if (state == 12 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return 24;
	}
	if (state == 13 && window.at(0) == Tokens::ID::id) {
		return -30;
	}
	if (state == 14 && window.at(0) == Tokens::ID::id) {
		return -31;
	}
	if (state == 14 && window.at(0) == Tokens::grammar::modifier::AUTO::id) {
		return 7;
	}
	if (state == 15 && window.at(0) == Tokens::grammar::modifier::RIGHT_SQUARE_BRACKET::id) {
		return 29;
	}
	if (state == 16 && window.at(0) == static_cast<std::size_t>(-1)) {
		return -41;
	}
	if (state == 16 && window.at(0) == Tokens::FAIL::id) {
		return 2;
	}
	if (state == 16 && window.at(0) == Tokens::ID::id) {
		return -29;
	}
	if (state == 16 && window.at(0) == Tokens::grammar::modifier::AUTO::id) {
		return 7;
	}
	if (state == 17 && window.at(0) == static_cast<std::size_t>(-1)) {
		return -38;
	}
	if (state == 18 && window.at(0) == Tokens::ID::id) {
		return 31;
	}
	if (state == 19 && window.at(0) == Tokens::AMPERSAND::id) {
		return -48;
	}
	if (state == 19 && window.at(0) == Tokens::AUTO::id) {
		return -48;
	}
	if (state == 19 && window.at(0) == Tokens::COLON::id) {
		return -48;
	}
	if (state == 19 && window.at(0) == Tokens::COMMERCIAL_AT::id) {
		return -48;
	}
	if (state == 19 && window.at(0) == Tokens::ID::id) {
		return -48;
	}
	if (state == 19 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -48;
	}
	if (state == 19 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -48;
	}
	if (state == 19 && window.at(0) == Tokens::PERCENT_SIGN::id) {
		return -48;
	}
	if (state == 19 && window.at(0) == Tokens::PY_RAW::id) {
		return -48;
	}
	if (state == 19 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -48;
	}
	if (state == 19 && window.at(0) == Tokens::SEMICOLON::id) {
		return -48;
	}
	if (state == 19 && window.at(0) == Tokens::rule::nested_rule::NUMBER_SIGN::id) {
		return -48;
	}
	if (state == 19 && window.at(0) == Tokens::rule::value::ANY::id) {
		return -48;
	}
	if (state == 19 && window.at(0) == Tokens::rule::value::CGROUP::id) {
		return -48;
	}
	if (state == 19 && window.at(0) == Tokens::rule::value::NOSPACE::id) {
		return -48;
	}
	if (state == 19 && window.at(0) == Tokens::rule::value::QUANTIFIER::id) {
		return -48;
	}
	if (state == 19 && window.at(0) == Tokens::rule::value::SPACE::id) {
		return -48;
	}
	if (state == 19 && window.at(0) == Tokens::rule::value::STRING::id) {
		return -48;
	}
	if (state == 19 && window.at(0) == Tokens::rule::value::alternative::VERTICAL_LINE::id) {
		return -48;
	}
	if (state == 19 && window.at(0) == Tokens::rule::value::dyn::DOLLAR_SIGN::id) {
		return -48;
	}
	if (state == 19 && window.at(0) == Tokens::rule::value::shared_counter_registration::AUTO::id) {
		return -48;
	}
	if (state == 19 && window.at(0) == Tokens::template_params::LESS_THAN_SIGN::id) {
		return 34;
	}
	if (state == 20 && window.at(0) == static_cast<std::size_t>(-1)) {
		return -149;
	}
	if (state == 20 && window.at(0) == Tokens::FAIL::id) {
		return -149;
	}
	if (state == 20 && window.at(0) == Tokens::ID::id) {
		return -149;
	}
	if (state == 20 && window.at(0) == Tokens::PY_RAW::id) {
		return -149;
	}
	if (state == 20 && window.at(0) == Tokens::RIGHT_CURLY_BRACKET::id) {
		return -149;
	}
	if (state == 20 && window.at(0) == Tokens::advanced_rule::regular_match::MATCH::id) {
		return -149;
	}
	if (state == 20 && window.at(0) == Tokens::grammar::modifier::AUTO::id) {
		return -149;
	}
	if (state == 21 && window.at(0) == static_cast<std::size_t>(-1)) {
		return -26;
	}
	if (state == 21 && window.at(0) == Tokens::FAIL::id) {
		return -26;
	}
	if (state == 21 && window.at(0) == Tokens::ID::id) {
		return -26;
	}
	if (state == 21 && window.at(0) == Tokens::grammar::modifier::AUTO::id) {
		return -26;
	}
	if (state == 22 && window.at(0) == Tokens::AMPERSAND::id) {
		return 35;
	}
	if (state == 22 && window.at(0) == Tokens::ID::id) {
		return -125;
	}
	if (state == 22 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -125;
	}
	if (state == 22 && window.at(0) == Tokens::rule::value::ANY::id) {
		return -125;
	}
	if (state == 22 && window.at(0) == Tokens::rule::value::CGROUP::id) {
		return -125;
	}
	if (state == 22 && window.at(0) == Tokens::rule::value::NOSPACE::id) {
		return -125;
	}
	if (state == 22 && window.at(0) == Tokens::rule::value::SPACE::id) {
		return -125;
	}
	if (state == 22 && window.at(0) == Tokens::rule::value::STRING::id) {
		return -125;
	}
	if (state == 22 && window.at(0) == Tokens::rule::value::dyn::DOLLAR_SIGN::id) {
		return -125;
	}
	if (state == 23 && window.at(0) == Tokens::PY_RAW::id) {
		return -8;
	}
	if (state == 23 && window.at(0) == Tokens::RIGHT_CURLY_BRACKET::id) {
		return -8;
	}
	if (state == 23 && window.at(0) == Tokens::advanced_rule::dep_decl::DEPENDS::id) {
		return 47;
	}
	if (state == 23 && window.at(0) == Tokens::advanced_rule::regular_match::MATCH::id) {
		return -8;
	}
	if (state == 24 && window.at(0) == static_cast<std::size_t>(-1)) {
		return -34;
	}
	if (state == 24 && window.at(0) == Tokens::FAIL::id) {
		return -34;
	}
	if (state == 24 && window.at(0) == Tokens::ID::id) {
		return -34;
	}
	if (state == 24 && window.at(0) == Tokens::SEMICOLON::id) {
		return -34;
	}
	if (state == 24 && window.at(0) == Tokens::grammar::modifier::AUTO::id) {
		return -34;
	}
	if (state == 24 && window.at(0) == Tokens::rule::nested_rule::NUMBER_SIGN::id) {
		return -34;
	}
	if (state == 25 && window.at(0) == static_cast<std::size_t>(-1)) {
		return -28;
	}
	if (state == 25 && window.at(0) == Tokens::FAIL::id) {
		return -28;
	}
	if (state == 25 && window.at(0) == Tokens::ID::id) {
		return -28;
	}
	if (state == 25 && window.at(0) == Tokens::SEMICOLON::id) {
		return -28;
	}
	if (state == 25 && window.at(0) == Tokens::grammar::modifier::AUTO::id) {
		return -28;
	}
	if (state == 25 && window.at(0) == Tokens::rule::nested_rule::NUMBER_SIGN::id) {
		return -28;
	}
	if (state == 26 && window.at(0) == static_cast<std::size_t>(-1)) {
		return -33;
	}
	if (state == 26 && window.at(0) == Tokens::FAIL::id) {
		return -33;
	}
	if (state == 26 && window.at(0) == Tokens::ID::id) {
		return -33;
	}
	if (state == 26 && window.at(0) == Tokens::SEMICOLON::id) {
		return -33;
	}
	if (state == 26 && window.at(0) == Tokens::grammar::modifier::AUTO::id) {
		return -33;
	}
	if (state == 26 && window.at(0) == Tokens::rule::nested_rule::NUMBER_SIGN::id) {
		return -33;
	}
	if (state == 27 && window.at(0) == Tokens::ID::id) {
		return -32;
	}
	if (state == 28 && window.at(0) == Tokens::ID::id) {
		return -35;
	}
	if (state == 28 && window.at(0) == Tokens::grammar::modifier::AUTO::id) {
		return -35;
	}
	if (state == 29 && window.at(0) == static_cast<std::size_t>(-1)) {
		return -42;
	}
	if (state == 30 && window.at(0) == Tokens::AMPERSAND::id) {
		return -46;
	}
	if (state == 30 && window.at(0) == Tokens::COLON::id) {
		return -46;
	}
	if (state == 30 && window.at(0) == Tokens::COMMERCIAL_AT::id) {
		return -46;
	}
	if (state == 30 && window.at(0) == Tokens::ID::id) {
		return -46;
	}
	if (state == 30 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -46;
	}
	if (state == 30 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -46;
	}
	if (state == 30 && window.at(0) == Tokens::PERCENT_SIGN::id) {
		return -46;
	}
	if (state == 30 && window.at(0) == Tokens::PY_RAW::id) {
		return -46;
	}
	if (state == 30 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -46;
	}
	if (state == 30 && window.at(0) == Tokens::SEMICOLON::id) {
		return -46;
	}
	if (state == 30 && window.at(0) == Tokens::rule::nested_rule::NUMBER_SIGN::id) {
		return -46;
	}
	if (state == 30 && window.at(0) == Tokens::rule::value::ANY::id) {
		return -46;
	}
	if (state == 30 && window.at(0) == Tokens::rule::value::CGROUP::id) {
		return -46;
	}
	if (state == 30 && window.at(0) == Tokens::rule::value::NOSPACE::id) {
		return -46;
	}
	if (state == 30 && window.at(0) == Tokens::rule::value::QUANTIFIER::id) {
		return -46;
	}
	if (state == 30 && window.at(0) == Tokens::rule::value::SPACE::id) {
		return -46;
	}
	if (state == 30 && window.at(0) == Tokens::rule::value::STRING::id) {
		return -46;
	}
	if (state == 30 && window.at(0) == Tokens::rule::value::alternative::VERTICAL_LINE::id) {
		return -46;
	}
	if (state == 30 && window.at(0) == Tokens::rule::value::dyn::DOLLAR_SIGN::id) {
		return -46;
	}
	if (state == 30 && window.at(0) == Tokens::rule::value::shared_counter_registration::AUTO::id) {
		return -46;
	}
	if (state == 30 && window.at(0) == Tokens::template_params::LESS_THAN_SIGN::id) {
		return -46;
	}
	if (state == 31 && window.at(0) == Tokens::AMPERSAND::id) {
		return -50;
	}
	if (state == 31 && window.at(0) == Tokens::AUTO::id) {
		return -50;
	}
	if (state == 31 && window.at(0) == Tokens::COLON::id) {
		return -50;
	}
	if (state == 31 && window.at(0) == Tokens::COMMERCIAL_AT::id) {
		return -50;
	}
	if (state == 31 && window.at(0) == Tokens::ID::id) {
		return -50;
	}
	if (state == 31 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -50;
	}
	if (state == 31 && window.at(0) == Tokens::PERCENT_SIGN::id) {
		return -50;
	}
	if (state == 31 && window.at(0) == Tokens::PY_RAW::id) {
		return -50;
	}
	if (state == 31 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -50;
	}
	if (state == 31 && window.at(0) == Tokens::SEMICOLON::id) {
		return -50;
	}
	if (state == 31 && window.at(0) == Tokens::rule::nested_rule::NUMBER_SIGN::id) {
		return -50;
	}
	if (state == 31 && window.at(0) == Tokens::rule::value::ANY::id) {
		return -50;
	}
	if (state == 31 && window.at(0) == Tokens::rule::value::CGROUP::id) {
		return -50;
	}
	if (state == 31 && window.at(0) == Tokens::rule::value::NOSPACE::id) {
		return -50;
	}
	if (state == 31 && window.at(0) == Tokens::rule::value::QUANTIFIER::id) {
		return -50;
	}
	if (state == 31 && window.at(0) == Tokens::rule::value::SPACE::id) {
		return -50;
	}
	if (state == 31 && window.at(0) == Tokens::rule::value::STRING::id) {
		return -50;
	}
	if (state == 31 && window.at(0) == Tokens::rule::value::alternative::VERTICAL_LINE::id) {
		return -50;
	}
	if (state == 31 && window.at(0) == Tokens::rule::value::dyn::DOLLAR_SIGN::id) {
		return -50;
	}
	if (state == 31 && window.at(0) == Tokens::rule::value::shared_counter_registration::AUTO::id) {
		return -50;
	}
	if (state == 32 && window.at(0) == Tokens::AMPERSAND::id) {
		return -49;
	}
	if (state == 32 && window.at(0) == Tokens::AUTO::id) {
		return -49;
	}
	if (state == 32 && window.at(0) == Tokens::COLON::id) {
		return -49;
	}
	if (state == 32 && window.at(0) == Tokens::COMMERCIAL_AT::id) {
		return -49;
	}
	if (state == 32 && window.at(0) == Tokens::ID::id) {
		return -49;
	}
	if (state == 32 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -49;
	}
	if (state == 32 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -49;
	}
	if (state == 32 && window.at(0) == Tokens::PERCENT_SIGN::id) {
		return -49;
	}
	if (state == 32 && window.at(0) == Tokens::PY_RAW::id) {
		return -49;
	}
	if (state == 32 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -49;
	}
	if (state == 32 && window.at(0) == Tokens::SEMICOLON::id) {
		return -49;
	}
	if (state == 32 && window.at(0) == Tokens::rule::nested_rule::NUMBER_SIGN::id) {
		return -49;
	}
	if (state == 32 && window.at(0) == Tokens::rule::value::ANY::id) {
		return -49;
	}
	if (state == 32 && window.at(0) == Tokens::rule::value::CGROUP::id) {
		return -49;
	}
	if (state == 32 && window.at(0) == Tokens::rule::value::NOSPACE::id) {
		return -49;
	}
	if (state == 32 && window.at(0) == Tokens::rule::value::QUANTIFIER::id) {
		return -49;
	}
	if (state == 32 && window.at(0) == Tokens::rule::value::SPACE::id) {
		return -49;
	}
	if (state == 32 && window.at(0) == Tokens::rule::value::STRING::id) {
		return -49;
	}
	if (state == 32 && window.at(0) == Tokens::rule::value::alternative::VERTICAL_LINE::id) {
		return -49;
	}
	if (state == 32 && window.at(0) == Tokens::rule::value::dyn::DOLLAR_SIGN::id) {
		return -49;
	}
	if (state == 32 && window.at(0) == Tokens::rule::value::shared_counter_registration::AUTO::id) {
		return -49;
	}
	if (state == 33 && window.at(0) == Tokens::ID::id) {
		return 53;
	}
	if (state == 33 && window.at(0) == Tokens::template_params::GREATER_THAN_SIGN::id) {
		return -151;
	}
	if (state == 34 && window.at(0) == Tokens::ID::id) {
		return 56;
	}
	if (state == 35 && window.at(0) == Tokens::EQUALS_SIGN::id) {
		return -122;
	}
	if (state == 36 && window.at(0) == Tokens::EQUALS_SIGN::id) {
		return -123;
	}
	if (state == 37 && window.at(0) == Tokens::AMPERSAND::id) {
		return 57;
	}
	if (state == 37 && window.at(0) == Tokens::COMMERCIAL_AT::id) {
		return 58;
	}
	if (state == 37 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return 59;
	}
	if (state == 37 && window.at(0) == Tokens::PERCENT_SIGN::id) {
		return -64;
	}
	if (state == 37 && window.at(0) == Tokens::SEMICOLON::id) {
		return -64;
	}
	if (state == 37 && window.at(0) == Tokens::rule::nested_rule::NUMBER_SIGN::id) {
		return -64;
	}
	if (state == 38 && window.at(0) == Tokens::ID::id) {
		return -125;
	}
	if (state == 38 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -62;
	}
	if (state == 38 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -125;
	}
	if (state == 38 && window.at(0) == Tokens::SEMICOLON::id) {
		return -62;
	}
	if (state == 38 && window.at(0) == Tokens::rule::nested_rule::NUMBER_SIGN::id) {
		return -62;
	}
	if (state == 38 && window.at(0) == Tokens::rule::value::ANY::id) {
		return -125;
	}
	if (state == 38 && window.at(0) == Tokens::rule::value::CGROUP::id) {
		return -125;
	}
	if (state == 38 && window.at(0) == Tokens::rule::value::NOSPACE::id) {
		return -125;
	}
	if (state == 38 && window.at(0) == Tokens::rule::value::SPACE::id) {
		return -125;
	}
	if (state == 38 && window.at(0) == Tokens::rule::value::STRING::id) {
		return -125;
	}
	if (state == 38 && window.at(0) == Tokens::rule::value::dyn::DOLLAR_SIGN::id) {
		return -125;
	}
	if (state == 39 && window.at(0) == Tokens::AMPERSAND::id) {
		return -95;
	}
	if (state == 39 && window.at(0) == Tokens::AUTO::id) {
		return -95;
	}
	if (state == 39 && window.at(0) == Tokens::COMMERCIAL_AT::id) {
		return -95;
	}
	if (state == 39 && window.at(0) == Tokens::ID::id) {
		return -95;
	}
	if (state == 39 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -95;
	}
	if (state == 39 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -95;
	}
	if (state == 39 && window.at(0) == Tokens::PERCENT_SIGN::id) {
		return -95;
	}
	if (state == 39 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -95;
	}
	if (state == 39 && window.at(0) == Tokens::SEMICOLON::id) {
		return -95;
	}
	if (state == 39 && window.at(0) == Tokens::rule::nested_rule::NUMBER_SIGN::id) {
		return -95;
	}
	if (state == 39 && window.at(0) == Tokens::rule::value::ANY::id) {
		return -95;
	}
	if (state == 39 && window.at(0) == Tokens::rule::value::CGROUP::id) {
		return -95;
	}
	if (state == 39 && window.at(0) == Tokens::rule::value::NOSPACE::id) {
		return -95;
	}
	if (state == 39 && window.at(0) == Tokens::rule::value::SPACE::id) {
		return -95;
	}
	if (state == 39 && window.at(0) == Tokens::rule::value::STRING::id) {
		return -95;
	}
	if (state == 39 && window.at(0) == Tokens::rule::value::dyn::DOLLAR_SIGN::id) {
		return -95;
	}
	if (state == 40 && window.at(0) == Tokens::EQUALS_SIGN::id) {
		return 67;
	}
	if (state == 41 && window.at(0) == Tokens::AMPERSAND::id) {
		return -94;
	}
	if (state == 41 && window.at(0) == Tokens::AUTO::id) {
		return -94;
	}
	if (state == 41 && window.at(0) == Tokens::COMMERCIAL_AT::id) {
		return -94;
	}
	if (state == 41 && window.at(0) == Tokens::ID::id) {
		return -94;
	}
	if (state == 41 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -94;
	}
	if (state == 41 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -94;
	}
	if (state == 41 && window.at(0) == Tokens::PERCENT_SIGN::id) {
		return -94;
	}
	if (state == 41 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -94;
	}
	if (state == 41 && window.at(0) == Tokens::SEMICOLON::id) {
		return -94;
	}
	if (state == 41 && window.at(0) == Tokens::rule::nested_rule::NUMBER_SIGN::id) {
		return -94;
	}
	if (state == 41 && window.at(0) == Tokens::rule::value::ANY::id) {
		return -94;
	}
	if (state == 41 && window.at(0) == Tokens::rule::value::CGROUP::id) {
		return -94;
	}
	if (state == 41 && window.at(0) == Tokens::rule::value::NOSPACE::id) {
		return -94;
	}
	if (state == 41 && window.at(0) == Tokens::rule::value::SPACE::id) {
		return -94;
	}
	if (state == 41 && window.at(0) == Tokens::rule::value::STRING::id) {
		return -94;
	}
	if (state == 41 && window.at(0) == Tokens::rule::value::dyn::DOLLAR_SIGN::id) {
		return -94;
	}
	if (state == 42 && window.at(0) == Tokens::COMMERCIAL_AT::id) {
		return 68;
	}
	if (state == 42 && window.at(0) == Tokens::ID::id) {
		return -131;
	}
	if (state == 42 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -131;
	}
	if (state == 42 && window.at(0) == Tokens::PERCENT_SIGN::id) {
		return -131;
	}
	if (state == 42 && window.at(0) == Tokens::rule::value::ANY::id) {
		return -131;
	}
	if (state == 42 && window.at(0) == Tokens::rule::value::CGROUP::id) {
		return -131;
	}
	if (state == 42 && window.at(0) == Tokens::rule::value::NOSPACE::id) {
		return -131;
	}
	if (state == 42 && window.at(0) == Tokens::rule::value::SPACE::id) {
		return -131;
	}
	if (state == 42 && window.at(0) == Tokens::rule::value::STRING::id) {
		return -131;
	}
	if (state == 42 && window.at(0) == Tokens::rule::value::dyn::DOLLAR_SIGN::id) {
		return -131;
	}
	if (state == 43 && window.at(0) == Tokens::COMMERCIAL_AT::id) {
		return -126;
	}
	if (state == 43 && window.at(0) == Tokens::ID::id) {
		return -126;
	}
	if (state == 43 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -126;
	}
	if (state == 43 && window.at(0) == Tokens::PERCENT_SIGN::id) {
		return -126;
	}
	if (state == 43 && window.at(0) == Tokens::rule::value::ANY::id) {
		return -126;
	}
	if (state == 43 && window.at(0) == Tokens::rule::value::CGROUP::id) {
		return -126;
	}
	if (state == 43 && window.at(0) == Tokens::rule::value::NOSPACE::id) {
		return -126;
	}
	if (state == 43 && window.at(0) == Tokens::rule::value::SPACE::id) {
		return -126;
	}
	if (state == 43 && window.at(0) == Tokens::rule::value::STRING::id) {
		return -126;
	}
	if (state == 43 && window.at(0) == Tokens::rule::value::dyn::DOLLAR_SIGN::id) {
		return -126;
	}
	if (state == 44 && window.at(0) == Tokens::PY_RAW::id) {
		return 21;
	}
	if (state == 44 && window.at(0) == Tokens::RIGHT_CURLY_BRACKET::id) {
		return -2;
	}
	if (state == 44 && window.at(0) == Tokens::advanced_rule::regular_match::MATCH::id) {
		return 74;
	}
	if (state == 45 && window.at(0) == Tokens::PY_RAW::id) {
		return -10;
	}
	if (state == 45 && window.at(0) == Tokens::RIGHT_CURLY_BRACKET::id) {
		return -10;
	}
	if (state == 45 && window.at(0) == Tokens::advanced_rule::dep_decl::DEPENDS::id) {
		return 47;
	}
	if (state == 45 && window.at(0) == Tokens::advanced_rule::regular_match::MATCH::id) {
		return -10;
	}
	if (state == 46 && window.at(0) == Tokens::AUTO::id) {
		return 78;
	}
	if (state == 47 && window.at(0) == Tokens::ID::id) {
		return 80;
	}
	if (state == 48 && window.at(0) == Tokens::AMPERSAND::id) {
		return -45;
	}
	if (state == 48 && window.at(0) == Tokens::AUTO::id) {
		return -45;
	}
	if (state == 48 && window.at(0) == Tokens::COLON::id) {
		return -45;
	}
	if (state == 48 && window.at(0) == Tokens::COMMERCIAL_AT::id) {
		return -45;
	}
	if (state == 48 && window.at(0) == Tokens::ID::id) {
		return -45;
	}
	if (state == 48 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -45;
	}
	if (state == 48 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -45;
	}
	if (state == 48 && window.at(0) == Tokens::PERCENT_SIGN::id) {
		return -45;
	}
	if (state == 48 && window.at(0) == Tokens::PY_RAW::id) {
		return -45;
	}
	if (state == 48 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -45;
	}
	if (state == 48 && window.at(0) == Tokens::SEMICOLON::id) {
		return -45;
	}
	if (state == 48 && window.at(0) == Tokens::rule::nested_rule::NUMBER_SIGN::id) {
		return -45;
	}
	if (state == 48 && window.at(0) == Tokens::rule::value::ANY::id) {
		return -45;
	}
	if (state == 48 && window.at(0) == Tokens::rule::value::CGROUP::id) {
		return -45;
	}
	if (state == 48 && window.at(0) == Tokens::rule::value::NOSPACE::id) {
		return -45;
	}
	if (state == 48 && window.at(0) == Tokens::rule::value::QUANTIFIER::id) {
		return -45;
	}
	if (state == 48 && window.at(0) == Tokens::rule::value::SPACE::id) {
		return -45;
	}
	if (state == 48 && window.at(0) == Tokens::rule::value::STRING::id) {
		return -45;
	}
	if (state == 48 && window.at(0) == Tokens::rule::value::alternative::VERTICAL_LINE::id) {
		return -45;
	}
	if (state == 48 && window.at(0) == Tokens::rule::value::dyn::DOLLAR_SIGN::id) {
		return -45;
	}
	if (state == 48 && window.at(0) == Tokens::rule::value::shared_counter_registration::AUTO::id) {
		return -45;
	}
	if (state == 48 && window.at(0) == Tokens::template_params::LESS_THAN_SIGN::id) {
		return -45;
	}
	if (state == 49 && window.at(0) == Tokens::ID::id) {
		return 53;
	}
	if (state == 49 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -58;
	}
	if (state == 50 && window.at(0) == Tokens::AMPERSAND::id) {
		return -43;
	}
	if (state == 50 && window.at(0) == Tokens::AUTO::id) {
		return -43;
	}
	if (state == 50 && window.at(0) == Tokens::COLON::id) {
		return -43;
	}
	if (state == 50 && window.at(0) == Tokens::COMMERCIAL_AT::id) {
		return -43;
	}
	if (state == 50 && window.at(0) == Tokens::ID::id) {
		return -43;
	}
	if (state == 50 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -43;
	}
	if (state == 50 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -43;
	}
	if (state == 50 && window.at(0) == Tokens::PERCENT_SIGN::id) {
		return -43;
	}
	if (state == 50 && window.at(0) == Tokens::PY_RAW::id) {
		return -43;
	}
	if (state == 50 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -43;
	}
	if (state == 50 && window.at(0) == Tokens::SEMICOLON::id) {
		return -43;
	}
	if (state == 50 && window.at(0) == Tokens::rule::nested_rule::NUMBER_SIGN::id) {
		return -43;
	}
	if (state == 50 && window.at(0) == Tokens::rule::value::ANY::id) {
		return -43;
	}
	if (state == 50 && window.at(0) == Tokens::rule::value::CGROUP::id) {
		return -43;
	}
	if (state == 50 && window.at(0) == Tokens::rule::value::NOSPACE::id) {
		return -43;
	}
	if (state == 50 && window.at(0) == Tokens::rule::value::QUANTIFIER::id) {
		return -43;
	}
	if (state == 50 && window.at(0) == Tokens::rule::value::SPACE::id) {
		return -43;
	}
	if (state == 50 && window.at(0) == Tokens::rule::value::STRING::id) {
		return -43;
	}
	if (state == 50 && window.at(0) == Tokens::rule::value::alternative::VERTICAL_LINE::id) {
		return -43;
	}
	if (state == 50 && window.at(0) == Tokens::rule::value::dyn::DOLLAR_SIGN::id) {
		return -43;
	}
	if (state == 50 && window.at(0) == Tokens::rule::value::shared_counter_registration::AUTO::id) {
		return -43;
	}
	if (state == 51 && window.at(0) == Tokens::AMPERSAND::id) {
		return -51;
	}
	if (state == 51 && window.at(0) == Tokens::AUTO::id) {
		return -51;
	}
	if (state == 51 && window.at(0) == Tokens::COLON::id) {
		return -51;
	}
	if (state == 51 && window.at(0) == Tokens::COMMERCIAL_AT::id) {
		return -51;
	}
	if (state == 51 && window.at(0) == Tokens::ID::id) {
		return -51;
	}
	if (state == 51 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -51;
	}
	if (state == 51 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -51;
	}
	if (state == 51 && window.at(0) == Tokens::PERCENT_SIGN::id) {
		return -51;
	}
	if (state == 51 && window.at(0) == Tokens::PY_RAW::id) {
		return -51;
	}
	if (state == 51 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -51;
	}
	if (state == 51 && window.at(0) == Tokens::SEMICOLON::id) {
		return -51;
	}
	if (state == 51 && window.at(0) == Tokens::rule::nested_rule::NUMBER_SIGN::id) {
		return -51;
	}
	if (state == 51 && window.at(0) == Tokens::rule::value::ANY::id) {
		return -51;
	}
	if (state == 51 && window.at(0) == Tokens::rule::value::CGROUP::id) {
		return -51;
	}
	if (state == 51 && window.at(0) == Tokens::rule::value::NOSPACE::id) {
		return -51;
	}
	if (state == 51 && window.at(0) == Tokens::rule::value::QUANTIFIER::id) {
		return -51;
	}
	if (state == 51 && window.at(0) == Tokens::rule::value::SPACE::id) {
		return -51;
	}
	if (state == 51 && window.at(0) == Tokens::rule::value::STRING::id) {
		return -51;
	}
	if (state == 51 && window.at(0) == Tokens::rule::value::alternative::VERTICAL_LINE::id) {
		return -51;
	}
	if (state == 51 && window.at(0) == Tokens::rule::value::dyn::DOLLAR_SIGN::id) {
		return -51;
	}
	if (state == 51 && window.at(0) == Tokens::rule::value::shared_counter_registration::AUTO::id) {
		return -51;
	}
	if (state == 52 && window.at(0) == Tokens::COMMA::id) {
		return 83;
	}
	if (state == 52 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -53;
	}
	if (state == 52 && window.at(0) == Tokens::template_params::GREATER_THAN_SIGN::id) {
		return -53;
	}
	if (state == 53 && window.at(0) == Tokens::template_params::GREATER_THAN_SIGN::id) {
		return -152;
	}
	if (state == 54 && window.at(0) == Tokens::template_params::GREATER_THAN_SIGN::id) {
		return 85;
	}
	if (state == 55 && window.at(0) == Tokens::COMMERCIAL_AT::id) {
		return -148;
	}
	if (state == 55 && window.at(0) == Tokens::ID::id) {
		return -148;
	}
	if (state == 55 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -148;
	}
	if (state == 55 && window.at(0) == Tokens::PERCENT_SIGN::id) {
		return -148;
	}
	if (state == 55 && window.at(0) == Tokens::rule::value::ANY::id) {
		return -148;
	}
	if (state == 55 && window.at(0) == Tokens::rule::value::CGROUP::id) {
		return -148;
	}
	if (state == 55 && window.at(0) == Tokens::rule::value::NOSPACE::id) {
		return -148;
	}
	if (state == 55 && window.at(0) == Tokens::rule::value::SPACE::id) {
		return -148;
	}
	if (state == 55 && window.at(0) == Tokens::rule::value::STRING::id) {
		return -148;
	}
	if (state == 55 && window.at(0) == Tokens::rule::value::dyn::DOLLAR_SIGN::id) {
		return -148;
	}
	if (state == 56 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return 86;
	}
	if (state == 57 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return 87;
	}
	if (state == 58 && window.at(0) == Tokens::COMMERCIAL_AT::id) {
		return 88;
	}
	if (state == 58 && window.at(0) == Tokens::PY_RAW::id) {
		return 89;
	}
	if (state == 59 && window.at(0) == Tokens::PERCENT_SIGN::id) {
		return 92;
	}
	if (state == 59 && window.at(0) == Tokens::SEMICOLON::id) {
		return -66;
	}
	if (state == 59 && window.at(0) == Tokens::rule::nested_rule::NUMBER_SIGN::id) {
		return -66;
	}
	if (state == 60 && window.at(0) == Tokens::PERCENT_SIGN::id) {
		return -65;
	}
	if (state == 60 && window.at(0) == Tokens::SEMICOLON::id) {
		return -65;
	}
	if (state == 60 && window.at(0) == Tokens::rule::nested_rule::NUMBER_SIGN::id) {
		return -65;
	}
	if (state == 61 && window.at(0) == Tokens::PERCENT_SIGN::id) {
		return -72;
	}
	if (state == 61 && window.at(0) == Tokens::SEMICOLON::id) {
		return -72;
	}
	if (state == 61 && window.at(0) == Tokens::rule::nested_rule::NUMBER_SIGN::id) {
		return -72;
	}
	if (state == 62 && window.at(0) == Tokens::PERCENT_SIGN::id) {
		return -73;
	}
	if (state == 62 && window.at(0) == Tokens::SEMICOLON::id) {
		return -73;
	}
	if (state == 62 && window.at(0) == Tokens::rule::nested_rule::NUMBER_SIGN::id) {
		return -73;
	}
	if (state == 63 && window.at(0) == Tokens::PERCENT_SIGN::id) {
		return -74;
	}
	if (state == 63 && window.at(0) == Tokens::SEMICOLON::id) {
		return -74;
	}
	if (state == 63 && window.at(0) == Tokens::rule::nested_rule::NUMBER_SIGN::id) {
		return -74;
	}
	if (state == 64 && window.at(0) == Tokens::AMPERSAND::id) {
		return -61;
	}
	if (state == 64 && window.at(0) == Tokens::COMMERCIAL_AT::id) {
		return -61;
	}
	if (state == 64 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -61;
	}
	if (state == 64 && window.at(0) == Tokens::PERCENT_SIGN::id) {
		return -61;
	}
	if (state == 64 && window.at(0) == Tokens::SEMICOLON::id) {
		return -61;
	}
	if (state == 64 && window.at(0) == Tokens::rule::nested_rule::NUMBER_SIGN::id) {
		return -61;
	}
	if (state == 65 && window.at(0) == Tokens::ID::id) {
		return -125;
	}
	if (state == 65 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -62;
	}
	if (state == 65 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -125;
	}
	if (state == 65 && window.at(0) == Tokens::SEMICOLON::id) {
		return -62;
	}
	if (state == 65 && window.at(0) == Tokens::rule::nested_rule::NUMBER_SIGN::id) {
		return -62;
	}
	if (state == 65 && window.at(0) == Tokens::rule::value::ANY::id) {
		return -125;
	}
	if (state == 65 && window.at(0) == Tokens::rule::value::CGROUP::id) {
		return -125;
	}
	if (state == 65 && window.at(0) == Tokens::rule::value::NOSPACE::id) {
		return -125;
	}
	if (state == 65 && window.at(0) == Tokens::rule::value::SPACE::id) {
		return -125;
	}
	if (state == 65 && window.at(0) == Tokens::rule::value::STRING::id) {
		return -125;
	}
	if (state == 65 && window.at(0) == Tokens::rule::value::dyn::DOLLAR_SIGN::id) {
		return -125;
	}
	if (state == 66 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return 96;
	}
	if (state == 67 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -98;
	}
	if (state == 67 && window.at(0) == Tokens::PERCENT_SIGN::id) {
		return -98;
	}
	if (state == 67 && window.at(0) == Tokens::rule::value::ANY::id) {
		return -98;
	}
	if (state == 67 && window.at(0) == Tokens::rule::value::CGROUP::id) {
		return -98;
	}
	if (state == 67 && window.at(0) == Tokens::rule::value::NOSPACE::id) {
		return -98;
	}
	if (state == 67 && window.at(0) == Tokens::rule::value::SPACE::id) {
		return -98;
	}
	if (state == 67 && window.at(0) == Tokens::rule::value::STRING::id) {
		return -98;
	}
	if (state == 67 && window.at(0) == Tokens::rule::value::dyn::DOLLAR_SIGN::id) {
		return -98;
	}
	if (state == 68 && window.at(0) == Tokens::ID::id) {
		return -132;
	}
	if (state == 68 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -132;
	}
	if (state == 68 && window.at(0) == Tokens::PERCENT_SIGN::id) {
		return -132;
	}
	if (state == 68 && window.at(0) == Tokens::rule::value::ANY::id) {
		return -132;
	}
	if (state == 68 && window.at(0) == Tokens::rule::value::CGROUP::id) {
		return -132;
	}
	if (state == 68 && window.at(0) == Tokens::rule::value::NOSPACE::id) {
		return -132;
	}
	if (state == 68 && window.at(0) == Tokens::rule::value::SPACE::id) {
		return -132;
	}
	if (state == 68 && window.at(0) == Tokens::rule::value::STRING::id) {
		return -132;
	}
	if (state == 68 && window.at(0) == Tokens::rule::value::dyn::DOLLAR_SIGN::id) {
		return -132;
	}
	if (state == 69 && window.at(0) == Tokens::ID::id) {
		return -133;
	}
	if (state == 69 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -133;
	}
	if (state == 69 && window.at(0) == Tokens::PERCENT_SIGN::id) {
		return 99;
	}
	if (state == 69 && window.at(0) == Tokens::rule::value::ANY::id) {
		return -133;
	}
	if (state == 69 && window.at(0) == Tokens::rule::value::CGROUP::id) {
		return -133;
	}
	if (state == 69 && window.at(0) == Tokens::rule::value::NOSPACE::id) {
		return -133;
	}
	if (state == 69 && window.at(0) == Tokens::rule::value::SPACE::id) {
		return -133;
	}
	if (state == 69 && window.at(0) == Tokens::rule::value::STRING::id) {
		return -133;
	}
	if (state == 69 && window.at(0) == Tokens::rule::value::dyn::DOLLAR_SIGN::id) {
		return -133;
	}
	if (state == 70 && window.at(0) == Tokens::RIGHT_CURLY_BRACKET::id) {
		return 102;
	}
	if (state == 71 && window.at(0) == Tokens::PY_RAW::id) {
		return 21;
	}
	if (state == 71 && window.at(0) == Tokens::RIGHT_CURLY_BRACKET::id) {
		return -6;
	}
	if (state == 71 && window.at(0) == Tokens::advanced_rule::regular_match::MATCH::id) {
		return 74;
	}
	if (state == 72 && window.at(0) == Tokens::PY_RAW::id) {
		return -4;
	}
	if (state == 72 && window.at(0) == Tokens::RIGHT_CURLY_BRACKET::id) {
		return -4;
	}
	if (state == 72 && window.at(0) == Tokens::advanced_rule::regular_match::MATCH::id) {
		return -4;
	}
	if (state == 73 && window.at(0) == Tokens::AMPERSAND::id) {
		return 35;
	}
	if (state == 73 && window.at(0) == Tokens::ID::id) {
		return -125;
	}
	if (state == 73 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -125;
	}
	if (state == 73 && window.at(0) == Tokens::rule::value::ANY::id) {
		return -125;
	}
	if (state == 73 && window.at(0) == Tokens::rule::value::CGROUP::id) {
		return -125;
	}
	if (state == 73 && window.at(0) == Tokens::rule::value::NOSPACE::id) {
		return -125;
	}
	if (state == 73 && window.at(0) == Tokens::rule::value::SPACE::id) {
		return -125;
	}
	if (state == 73 && window.at(0) == Tokens::rule::value::STRING::id) {
		return -125;
	}
	if (state == 73 && window.at(0) == Tokens::rule::value::dyn::DOLLAR_SIGN::id) {
		return -125;
	}
	if (state == 74 && window.at(0) == Tokens::PY_RAW::id) {
		return -5;
	}
	if (state == 74 && window.at(0) == Tokens::RIGHT_CURLY_BRACKET::id) {
		return -5;
	}
	if (state == 74 && window.at(0) == Tokens::advanced_rule::regular_match::MATCH::id) {
		return -5;
	}
	if (state == 75 && window.at(0) == Tokens::PY_RAW::id) {
		return -9;
	}
	if (state == 75 && window.at(0) == Tokens::RIGHT_CURLY_BRACKET::id) {
		return -9;
	}
	if (state == 75 && window.at(0) == Tokens::advanced_rule::regular_match::MATCH::id) {
		return -9;
	}
	if (state == 76 && window.at(0) == Tokens::PY_RAW::id) {
		return -10;
	}
	if (state == 76 && window.at(0) == Tokens::RIGHT_CURLY_BRACKET::id) {
		return -10;
	}
	if (state == 76 && window.at(0) == Tokens::advanced_rule::dep_decl::DEPENDS::id) {
		return 47;
	}
	if (state == 76 && window.at(0) == Tokens::advanced_rule::regular_match::MATCH::id) {
		return -10;
	}
	if (state == 77 && window.at(0) == Tokens::ID::id) {
		return 108;
	}
	if (state == 78 && window.at(0) == Tokens::PY_RAW::id) {
		return -12;
	}
	if (state == 78 && window.at(0) == Tokens::RIGHT_CURLY_BRACKET::id) {
		return -12;
	}
	if (state == 78 && window.at(0) == Tokens::advanced_rule::dep_decl::DEPENDS::id) {
		return -12;
	}
	if (state == 78 && window.at(0) == Tokens::advanced_rule::regular_match::MATCH::id) {
		return -12;
	}
	if (state == 79 && window.at(0) == Tokens::AMPERSAND::id) {
		return -46;
	}
	if (state == 79 && window.at(0) == Tokens::COLON::id) {
		return -46;
	}
	if (state == 79 && window.at(0) == Tokens::COMMERCIAL_AT::id) {
		return -46;
	}
	if (state == 79 && window.at(0) == Tokens::ID::id) {
		return -46;
	}
	if (state == 79 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -46;
	}
	if (state == 79 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -46;
	}
	if (state == 79 && window.at(0) == Tokens::PERCENT_SIGN::id) {
		return -46;
	}
	if (state == 79 && window.at(0) == Tokens::PY_RAW::id) {
		return -46;
	}
	if (state == 79 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -46;
	}
	if (state == 79 && window.at(0) == Tokens::SEMICOLON::id) {
		return -46;
	}
	if (state == 79 && window.at(0) == Tokens::rule::nested_rule::NUMBER_SIGN::id) {
		return -46;
	}
	if (state == 79 && window.at(0) == Tokens::rule::value::ANY::id) {
		return -46;
	}
	if (state == 79 && window.at(0) == Tokens::rule::value::CGROUP::id) {
		return -46;
	}
	if (state == 79 && window.at(0) == Tokens::rule::value::NOSPACE::id) {
		return -46;
	}
	if (state == 79 && window.at(0) == Tokens::rule::value::QUANTIFIER::id) {
		return -46;
	}
	if (state == 79 && window.at(0) == Tokens::rule::value::SPACE::id) {
		return -46;
	}
	if (state == 79 && window.at(0) == Tokens::rule::value::STRING::id) {
		return -46;
	}
	if (state == 79 && window.at(0) == Tokens::rule::value::alternative::VERTICAL_LINE::id) {
		return -46;
	}
	if (state == 79 && window.at(0) == Tokens::rule::value::dyn::DOLLAR_SIGN::id) {
		return -46;
	}
	if (state == 79 && window.at(0) == Tokens::rule::value::shared_counter_registration::AUTO::id) {
		return -46;
	}
	if (state == 79 && window.at(0) == Tokens::template_params::LESS_THAN_SIGN::id) {
		return -46;
	}
	if (state == 80 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -59;
	}
	if (state == 81 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return 110;
	}
	if (state == 82 && window.at(0) == Tokens::ID::id) {
		return 111;
	}
	if (state == 83 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -52;
	}
	if (state == 83 && window.at(0) == Tokens::template_params::GREATER_THAN_SIGN::id) {
		return -52;
	}
	if (state == 84 && window.at(0) == Tokens::AMPERSAND::id) {
		return -150;
	}
	if (state == 84 && window.at(0) == Tokens::AUTO::id) {
		return -150;
	}
	if (state == 84 && window.at(0) == Tokens::COLON::id) {
		return -150;
	}
	if (state == 84 && window.at(0) == Tokens::COMMERCIAL_AT::id) {
		return -150;
	}
	if (state == 84 && window.at(0) == Tokens::ID::id) {
		return -150;
	}
	if (state == 84 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -150;
	}
	if (state == 84 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -150;
	}
	if (state == 84 && window.at(0) == Tokens::PERCENT_SIGN::id) {
		return -150;
	}
	if (state == 84 && window.at(0) == Tokens::PY_RAW::id) {
		return -150;
	}
	if (state == 84 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -150;
	}
	if (state == 84 && window.at(0) == Tokens::SEMICOLON::id) {
		return -150;
	}
	if (state == 84 && window.at(0) == Tokens::rule::nested_rule::NUMBER_SIGN::id) {
		return -150;
	}
	if (state == 84 && window.at(0) == Tokens::rule::value::ANY::id) {
		return -150;
	}
	if (state == 84 && window.at(0) == Tokens::rule::value::CGROUP::id) {
		return -150;
	}
	if (state == 84 && window.at(0) == Tokens::rule::value::NOSPACE::id) {
		return -150;
	}
	if (state == 84 && window.at(0) == Tokens::rule::value::QUANTIFIER::id) {
		return -150;
	}
	if (state == 84 && window.at(0) == Tokens::rule::value::SPACE::id) {
		return -150;
	}
	if (state == 84 && window.at(0) == Tokens::rule::value::STRING::id) {
		return -150;
	}
	if (state == 84 && window.at(0) == Tokens::rule::value::alternative::VERTICAL_LINE::id) {
		return -150;
	}
	if (state == 84 && window.at(0) == Tokens::rule::value::dyn::DOLLAR_SIGN::id) {
		return -150;
	}
	if (state == 84 && window.at(0) == Tokens::rule::value::shared_counter_registration::AUTO::id) {
		return -150;
	}
	if (state == 85 && window.at(0) == Tokens::ID::id) {
		return 112;
	}
	if (state == 86 && window.at(0) == Tokens::ID::id) {
		return 115;
	}
	if (state == 87 && window.at(0) == Tokens::RIGHT_CURLY_BRACKET::id) {
		return -87;
	}
	if (state == 88 && window.at(0) == Tokens::AMPERSAND::id) {
		return -25;
	}
	if (state == 88 && window.at(0) == Tokens::AUTO::id) {
		return -25;
	}
	if (state == 88 && window.at(0) == Tokens::COMMERCIAL_AT::id) {
		return -25;
	}
	if (state == 88 && window.at(0) == Tokens::ID::id) {
		return -25;
	}
	if (state == 88 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -25;
	}
	if (state == 88 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -25;
	}
	if (state == 88 && window.at(0) == Tokens::PERCENT_SIGN::id) {
		return -25;
	}
	if (state == 88 && window.at(0) == Tokens::RIGHT_CURLY_BRACKET::id) {
		return -25;
	}
	if (state == 88 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -25;
	}
	if (state == 88 && window.at(0) == Tokens::SEMICOLON::id) {
		return -25;
	}
	if (state == 88 && window.at(0) == Tokens::rule::nested_rule::NUMBER_SIGN::id) {
		return -25;
	}
	if (state == 88 && window.at(0) == Tokens::rule::value::ANY::id) {
		return -25;
	}
	if (state == 88 && window.at(0) == Tokens::rule::value::CGROUP::id) {
		return -25;
	}
	if (state == 88 && window.at(0) == Tokens::rule::value::NOSPACE::id) {
		return -25;
	}
	if (state == 88 && window.at(0) == Tokens::rule::value::SPACE::id) {
		return -25;
	}
	if (state == 88 && window.at(0) == Tokens::rule::value::STRING::id) {
		return -25;
	}
	if (state == 88 && window.at(0) == Tokens::rule::value::dyn::DOLLAR_SIGN::id) {
		return -25;
	}
	if (state == 88 && window.at(0) == Tokens::rule::value::shared_counter_registration::AUTO::id) {
		return -25;
	}
	if (state == 89 && window.at(0) == Tokens::RIGHT_CURLY_BRACKET::id) {
		return -86;
	}
	if (state == 90 && window.at(0) == Tokens::RIGHT_CURLY_BRACKET::id) {
		return 116;
	}
	if (state == 91 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return 117;
	}
	if (state == 92 && window.at(0) == Tokens::SEMICOLON::id) {
		return -68;
	}
	if (state == 92 && window.at(0) == Tokens::rule::nested_rule::NUMBER_SIGN::id) {
		return 120;
	}
	if (state == 93 && window.at(0) == Tokens::SEMICOLON::id) {
		return -67;
	}
	if (state == 93 && window.at(0) == Tokens::rule::nested_rule::NUMBER_SIGN::id) {
		return -67;
	}
	if (state == 94 && window.at(0) == Tokens::AMPERSAND::id) {
		return -63;
	}
	if (state == 94 && window.at(0) == Tokens::COMMERCIAL_AT::id) {
		return -63;
	}
	if (state == 94 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -63;
	}
	if (state == 94 && window.at(0) == Tokens::PERCENT_SIGN::id) {
		return -63;
	}
	if (state == 94 && window.at(0) == Tokens::SEMICOLON::id) {
		return -63;
	}
	if (state == 94 && window.at(0) == Tokens::rule::nested_rule::NUMBER_SIGN::id) {
		return -63;
	}
	if (state == 95 && window.at(0) == Tokens::AMPERSAND::id) {
		return 35;
	}
	if (state == 95 && window.at(0) == Tokens::COMMERCIAL_AT::id) {
		return -125;
	}
	if (state == 95 && window.at(0) == Tokens::ID::id) {
		return -125;
	}
	if (state == 95 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -125;
	}
	if (state == 95 && window.at(0) == Tokens::PERCENT_SIGN::id) {
		return -125;
	}
	if (state == 95 && window.at(0) == Tokens::rule::value::ANY::id) {
		return -125;
	}
	if (state == 95 && window.at(0) == Tokens::rule::value::CGROUP::id) {
		return -125;
	}
	if (state == 95 && window.at(0) == Tokens::rule::value::NOSPACE::id) {
		return -125;
	}
	if (state == 95 && window.at(0) == Tokens::rule::value::SPACE::id) {
		return -125;
	}
	if (state == 95 && window.at(0) == Tokens::rule::value::STRING::id) {
		return -125;
	}
	if (state == 95 && window.at(0) == Tokens::rule::value::dyn::DOLLAR_SIGN::id) {
		return -125;
	}
	if (state == 96 && window.at(0) == Tokens::ID::id) {
		return -99;
	}
	if (state == 96 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -99;
	}
	if (state == 96 && window.at(0) == Tokens::PERCENT_SIGN::id) {
		return -99;
	}
	if (state == 96 && window.at(0) == Tokens::rule::value::ANY::id) {
		return -99;
	}
	if (state == 96 && window.at(0) == Tokens::rule::value::CGROUP::id) {
		return -99;
	}
	if (state == 96 && window.at(0) == Tokens::rule::value::NOSPACE::id) {
		return -99;
	}
	if (state == 96 && window.at(0) == Tokens::rule::value::SPACE::id) {
		return -99;
	}
	if (state == 96 && window.at(0) == Tokens::rule::value::STRING::id) {
		return -99;
	}
	if (state == 96 && window.at(0) == Tokens::rule::value::dyn::DOLLAR_SIGN::id) {
		return -99;
	}
	if (state == 97 && window.at(0) == Tokens::ID::id) {
		return -97;
	}
	if (state == 97 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -97;
	}
	if (state == 97 && window.at(0) == Tokens::PERCENT_SIGN::id) {
		return -97;
	}
	if (state == 97 && window.at(0) == Tokens::rule::value::ANY::id) {
		return -97;
	}
	if (state == 97 && window.at(0) == Tokens::rule::value::CGROUP::id) {
		return -97;
	}
	if (state == 97 && window.at(0) == Tokens::rule::value::NOSPACE::id) {
		return -97;
	}
	if (state == 97 && window.at(0) == Tokens::rule::value::SPACE::id) {
		return -97;
	}
	if (state == 97 && window.at(0) == Tokens::rule::value::STRING::id) {
		return -97;
	}
	if (state == 97 && window.at(0) == Tokens::rule::value::dyn::DOLLAR_SIGN::id) {
		return -97;
	}
	if (state == 98 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -112;
	}
	if (state == 98 && window.at(0) == Tokens::rule::value::ANY::id) {
		return -112;
	}
	if (state == 98 && window.at(0) == Tokens::rule::value::CGROUP::id) {
		return -112;
	}
	if (state == 98 && window.at(0) == Tokens::rule::value::NOSPACE::id) {
		return -112;
	}
	if (state == 98 && window.at(0) == Tokens::rule::value::SPACE::id) {
		return -112;
	}
	if (state == 98 && window.at(0) == Tokens::rule::value::STRING::id) {
		return -112;
	}
	if (state == 98 && window.at(0) == Tokens::rule::value::dyn::DOLLAR_SIGN::id) {
		return -112;
	}
	if (state == 99 && window.at(0) == Tokens::ID::id) {
		return -134;
	}
	if (state == 99 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -134;
	}
	if (state == 99 && window.at(0) == Tokens::rule::value::ANY::id) {
		return -134;
	}
	if (state == 99 && window.at(0) == Tokens::rule::value::CGROUP::id) {
		return -134;
	}
	if (state == 99 && window.at(0) == Tokens::rule::value::NOSPACE::id) {
		return -134;
	}
	if (state == 99 && window.at(0) == Tokens::rule::value::SPACE::id) {
		return -134;
	}
	if (state == 99 && window.at(0) == Tokens::rule::value::STRING::id) {
		return -134;
	}
	if (state == 99 && window.at(0) == Tokens::rule::value::dyn::DOLLAR_SIGN::id) {
		return -134;
	}
	if (state == 100 && window.at(0) == Tokens::ID::id) {
		return 11;
	}
	if (state == 100 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return 125;
	}
	if (state == 100 && window.at(0) == Tokens::rule::value::ANY::id) {
		return 127;
	}
	if (state == 100 && window.at(0) == Tokens::rule::value::CGROUP::id) {
		return 128;
	}
	if (state == 100 && window.at(0) == Tokens::rule::value::NOSPACE::id) {
		return 129;
	}
	if (state == 100 && window.at(0) == Tokens::rule::value::SPACE::id) {
		return 130;
	}
	if (state == 100 && window.at(0) == Tokens::rule::value::STRING::id) {
		return 131;
	}
	if (state == 100 && window.at(0) == Tokens::rule::value::dyn::DOLLAR_SIGN::id) {
		return 133;
	}
	if (state == 101 && window.at(0) == static_cast<std::size_t>(-1)) {
		return -1;
	}
	if (state == 101 && window.at(0) == Tokens::FAIL::id) {
		return -1;
	}
	if (state == 101 && window.at(0) == Tokens::ID::id) {
		return -1;
	}
	if (state == 101 && window.at(0) == Tokens::SEMICOLON::id) {
		return -1;
	}
	if (state == 101 && window.at(0) == Tokens::grammar::modifier::AUTO::id) {
		return -1;
	}
	if (state == 101 && window.at(0) == Tokens::rule::nested_rule::NUMBER_SIGN::id) {
		return -1;
	}
	if (state == 102 && window.at(0) == Tokens::PY_RAW::id) {
		return 21;
	}
	if (state == 102 && window.at(0) == Tokens::RIGHT_CURLY_BRACKET::id) {
		return -6;
	}
	if (state == 102 && window.at(0) == Tokens::advanced_rule::regular_match::MATCH::id) {
		return 74;
	}
	if (state == 103 && window.at(0) == Tokens::RIGHT_CURLY_BRACKET::id) {
		return -3;
	}
	if (state == 104 && window.at(0) == Tokens::AUTO::id) {
		return 137;
	}
	if (state == 104 && window.at(0) == Tokens::SEMICOLON::id) {
		return 138;
	}
	if (state == 105 && window.at(0) == Tokens::AMPERSAND::id) {
		return 35;
	}
	if (state == 105 && window.at(0) == Tokens::AUTO::id) {
		return -16;
	}
	if (state == 105 && window.at(0) == Tokens::ID::id) {
		return -125;
	}
	if (state == 105 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -125;
	}
	if (state == 105 && window.at(0) == Tokens::SEMICOLON::id) {
		return -16;
	}
	if (state == 105 && window.at(0) == Tokens::rule::value::ANY::id) {
		return -125;
	}
	if (state == 105 && window.at(0) == Tokens::rule::value::CGROUP::id) {
		return -125;
	}
	if (state == 105 && window.at(0) == Tokens::rule::value::NOSPACE::id) {
		return -125;
	}
	if (state == 105 && window.at(0) == Tokens::rule::value::SPACE::id) {
		return -125;
	}
	if (state == 105 && window.at(0) == Tokens::rule::value::STRING::id) {
		return -125;
	}
	if (state == 105 && window.at(0) == Tokens::rule::value::dyn::DOLLAR_SIGN::id) {
		return -125;
	}
	if (state == 106 && window.at(0) == Tokens::PY_RAW::id) {
		return -11;
	}
	if (state == 106 && window.at(0) == Tokens::RIGHT_CURLY_BRACKET::id) {
		return -11;
	}
	if (state == 106 && window.at(0) == Tokens::advanced_rule::regular_match::MATCH::id) {
		return -11;
	}
	if (state == 107 && window.at(0) == Tokens::AUTO::id) {
		return 143;
	}
	if (state == 108 && window.at(0) == Tokens::AMPERSAND::id) {
		return -47;
	}
	if (state == 108 && window.at(0) == Tokens::AUTO::id) {
		return -47;
	}
	if (state == 108 && window.at(0) == Tokens::COLON::id) {
		return -47;
	}
	if (state == 108 && window.at(0) == Tokens::COMMERCIAL_AT::id) {
		return -47;
	}
	if (state == 108 && window.at(0) == Tokens::ID::id) {
		return -47;
	}
	if (state == 108 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -47;
	}
	if (state == 108 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -47;
	}
	if (state == 108 && window.at(0) == Tokens::PERCENT_SIGN::id) {
		return -47;
	}
	if (state == 108 && window.at(0) == Tokens::PY_RAW::id) {
		return -47;
	}
	if (state == 108 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -47;
	}
	if (state == 108 && window.at(0) == Tokens::SEMICOLON::id) {
		return -47;
	}
	if (state == 108 && window.at(0) == Tokens::rule::nested_rule::NUMBER_SIGN::id) {
		return -47;
	}
	if (state == 108 && window.at(0) == Tokens::rule::value::ANY::id) {
		return -47;
	}
	if (state == 108 && window.at(0) == Tokens::rule::value::CGROUP::id) {
		return -47;
	}
	if (state == 108 && window.at(0) == Tokens::rule::value::NOSPACE::id) {
		return -47;
	}
	if (state == 108 && window.at(0) == Tokens::rule::value::QUANTIFIER::id) {
		return -47;
	}
	if (state == 108 && window.at(0) == Tokens::rule::value::SPACE::id) {
		return -47;
	}
	if (state == 108 && window.at(0) == Tokens::rule::value::STRING::id) {
		return -47;
	}
	if (state == 108 && window.at(0) == Tokens::rule::value::alternative::VERTICAL_LINE::id) {
		return -47;
	}
	if (state == 108 && window.at(0) == Tokens::rule::value::dyn::DOLLAR_SIGN::id) {
		return -47;
	}
	if (state == 108 && window.at(0) == Tokens::rule::value::shared_counter_registration::AUTO::id) {
		return -47;
	}
	if (state == 108 && window.at(0) == Tokens::template_params::LESS_THAN_SIGN::id) {
		return -47;
	}
	if (state == 109 && window.at(0) == Tokens::AMPERSAND::id) {
		return -57;
	}
	if (state == 109 && window.at(0) == Tokens::AUTO::id) {
		return -57;
	}
	if (state == 109 && window.at(0) == Tokens::COLON::id) {
		return -57;
	}
	if (state == 109 && window.at(0) == Tokens::COMMERCIAL_AT::id) {
		return -57;
	}
	if (state == 109 && window.at(0) == Tokens::ID::id) {
		return -57;
	}
	if (state == 109 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -57;
	}
	if (state == 109 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -57;
	}
	if (state == 109 && window.at(0) == Tokens::PERCENT_SIGN::id) {
		return -57;
	}
	if (state == 109 && window.at(0) == Tokens::PY_RAW::id) {
		return -57;
	}
	if (state == 109 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -57;
	}
	if (state == 109 && window.at(0) == Tokens::SEMICOLON::id) {
		return -57;
	}
	if (state == 109 && window.at(0) == Tokens::rule::nested_rule::NUMBER_SIGN::id) {
		return -57;
	}
	if (state == 109 && window.at(0) == Tokens::rule::value::ANY::id) {
		return -57;
	}
	if (state == 109 && window.at(0) == Tokens::rule::value::CGROUP::id) {
		return -57;
	}
	if (state == 109 && window.at(0) == Tokens::rule::value::NOSPACE::id) {
		return -57;
	}
	if (state == 109 && window.at(0) == Tokens::rule::value::QUANTIFIER::id) {
		return -57;
	}
	if (state == 109 && window.at(0) == Tokens::rule::value::SPACE::id) {
		return -57;
	}
	if (state == 109 && window.at(0) == Tokens::rule::value::STRING::id) {
		return -57;
	}
	if (state == 109 && window.at(0) == Tokens::rule::value::alternative::VERTICAL_LINE::id) {
		return -57;
	}
	if (state == 109 && window.at(0) == Tokens::rule::value::dyn::DOLLAR_SIGN::id) {
		return -57;
	}
	if (state == 109 && window.at(0) == Tokens::rule::value::shared_counter_registration::AUTO::id) {
		return -57;
	}
	if (state == 110 && window.at(0) == Tokens::COMMA::id) {
		return 144;
	}
	if (state == 110 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -55;
	}
	if (state == 110 && window.at(0) == Tokens::template_params::GREATER_THAN_SIGN::id) {
		return -55;
	}
	if (state == 111 && window.at(0) == Tokens::COLON::id) {
		return 146;
	}
	if (state == 112 && window.at(0) == Tokens::RIGHT_CURLY_BRACKET::id) {
		return 147;
	}
	if (state == 113 && window.at(0) == Tokens::ID::id) {
		return 112;
	}
	if (state == 113 && window.at(0) == Tokens::RIGHT_CURLY_BRACKET::id) {
		return -82;
	}
	if (state == 114 && window.at(0) == Tokens::COMMA::id) {
		return 150;
	}
	if (state == 114 && window.at(0) == Tokens::RIGHT_CURLY_BRACKET::id) {
		return -76;
	}
	if (state == 115 && window.at(0) == Tokens::PERCENT_SIGN::id) {
		return -85;
	}
	if (state == 115 && window.at(0) == Tokens::SEMICOLON::id) {
		return -85;
	}
	if (state == 115 && window.at(0) == Tokens::rule::nested_rule::NUMBER_SIGN::id) {
		return -85;
	}
	if (state == 116 && window.at(0) == Tokens::ID::id) {
		return 152;
	}
	if (state == 117 && window.at(0) == Tokens::SEMICOLON::id) {
		return 153;
	}
	if (state == 118 && window.at(0) == Tokens::SEMICOLON::id) {
		return -70;
	}
	if (state == 118 && window.at(0) == Tokens::rule::nested_rule::NUMBER_SIGN::id) {
		return 120;
	}
	if (state == 119 && window.at(0) == Tokens::ID::id) {
		return -29;
	}
	if (state == 119 && window.at(0) == Tokens::grammar::modifier::AUTO::id) {
		return 7;
	}
	if (state == 120 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return 157;
	}
	if (state == 121 && window.at(0) == Tokens::AMPERSAND::id) {
		return 35;
	}
	if (state == 121 && window.at(0) == Tokens::COMMERCIAL_AT::id) {
		return -125;
	}
	if (state == 121 && window.at(0) == Tokens::ID::id) {
		return -125;
	}
	if (state == 121 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -125;
	}
	if (state == 121 && window.at(0) == Tokens::PERCENT_SIGN::id) {
		return -125;
	}
	if (state == 121 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -120;
	}
	if (state == 121 && window.at(0) == Tokens::rule::value::ANY::id) {
		return -125;
	}
	if (state == 121 && window.at(0) == Tokens::rule::value::CGROUP::id) {
		return -125;
	}
	if (state == 121 && window.at(0) == Tokens::rule::value::NOSPACE::id) {
		return -125;
	}
	if (state == 121 && window.at(0) == Tokens::rule::value::SPACE::id) {
		return -125;
	}
	if (state == 121 && window.at(0) == Tokens::rule::value::STRING::id) {
		return -125;
	}
	if (state == 121 && window.at(0) == Tokens::rule::value::dyn::DOLLAR_SIGN::id) {
		return -125;
	}
	if (state == 122 && window.at(0) == Tokens::ID::id) {
		return -113;
	}
	if (state == 122 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -113;
	}
	if (state == 122 && window.at(0) == Tokens::rule::value::ANY::id) {
		return -113;
	}
	if (state == 122 && window.at(0) == Tokens::rule::value::CGROUP::id) {
		return -113;
	}
	if (state == 122 && window.at(0) == Tokens::rule::value::NOSPACE::id) {
		return -113;
	}
	if (state == 122 && window.at(0) == Tokens::rule::value::SPACE::id) {
		return -113;
	}
	if (state == 122 && window.at(0) == Tokens::rule::value::STRING::id) {
		return -113;
	}
	if (state == 122 && window.at(0) == Tokens::rule::value::dyn::DOLLAR_SIGN::id) {
		return -113;
	}
	if (state == 123 && window.at(0) == Tokens::ID::id) {
		return -111;
	}
	if (state == 123 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -111;
	}
	if (state == 123 && window.at(0) == Tokens::rule::value::ANY::id) {
		return -111;
	}
	if (state == 123 && window.at(0) == Tokens::rule::value::CGROUP::id) {
		return -111;
	}
	if (state == 123 && window.at(0) == Tokens::rule::value::NOSPACE::id) {
		return -111;
	}
	if (state == 123 && window.at(0) == Tokens::rule::value::SPACE::id) {
		return -111;
	}
	if (state == 123 && window.at(0) == Tokens::rule::value::STRING::id) {
		return -111;
	}
	if (state == 123 && window.at(0) == Tokens::rule::value::dyn::DOLLAR_SIGN::id) {
		return -111;
	}
	if (state == 124 && window.at(0) == Tokens::AMPERSAND::id) {
		return 35;
	}
	if (state == 124 && window.at(0) == Tokens::ID::id) {
		return -125;
	}
	if (state == 124 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -125;
	}
	if (state == 124 && window.at(0) == Tokens::rule::value::ANY::id) {
		return -125;
	}
	if (state == 124 && window.at(0) == Tokens::rule::value::CGROUP::id) {
		return -125;
	}
	if (state == 124 && window.at(0) == Tokens::rule::value::NOSPACE::id) {
		return -125;
	}
	if (state == 124 && window.at(0) == Tokens::rule::value::SPACE::id) {
		return -125;
	}
	if (state == 124 && window.at(0) == Tokens::rule::value::STRING::id) {
		return -125;
	}
	if (state == 124 && window.at(0) == Tokens::rule::value::dyn::DOLLAR_SIGN::id) {
		return -125;
	}
	if (state == 125 && window.at(0) == Tokens::AMPERSAND::id) {
		return -139;
	}
	if (state == 125 && window.at(0) == Tokens::AUTO::id) {
		return -139;
	}
	if (state == 125 && window.at(0) == Tokens::COMMERCIAL_AT::id) {
		return -139;
	}
	if (state == 125 && window.at(0) == Tokens::ID::id) {
		return -139;
	}
	if (state == 125 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -139;
	}
	if (state == 125 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -139;
	}
	if (state == 125 && window.at(0) == Tokens::PERCENT_SIGN::id) {
		return -139;
	}
	if (state == 125 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -139;
	}
	if (state == 125 && window.at(0) == Tokens::SEMICOLON::id) {
		return -139;
	}
	if (state == 125 && window.at(0) == Tokens::rule::nested_rule::NUMBER_SIGN::id) {
		return -139;
	}
	if (state == 125 && window.at(0) == Tokens::rule::value::ANY::id) {
		return -139;
	}
	if (state == 125 && window.at(0) == Tokens::rule::value::CGROUP::id) {
		return -139;
	}
	if (state == 125 && window.at(0) == Tokens::rule::value::NOSPACE::id) {
		return -139;
	}
	if (state == 125 && window.at(0) == Tokens::rule::value::QUANTIFIER::id) {
		return -139;
	}
	if (state == 125 && window.at(0) == Tokens::rule::value::SPACE::id) {
		return -139;
	}
	if (state == 125 && window.at(0) == Tokens::rule::value::STRING::id) {
		return -139;
	}
	if (state == 125 && window.at(0) == Tokens::rule::value::alternative::VERTICAL_LINE::id) {
		return -139;
	}
	if (state == 125 && window.at(0) == Tokens::rule::value::dyn::DOLLAR_SIGN::id) {
		return -139;
	}
	if (state == 125 && window.at(0) == Tokens::rule::value::shared_counter_registration::AUTO::id) {
		return -139;
	}
	if (state == 126 && window.at(0) == Tokens::AMPERSAND::id) {
		return -144;
	}
	if (state == 126 && window.at(0) == Tokens::AUTO::id) {
		return -144;
	}
	if (state == 126 && window.at(0) == Tokens::COMMERCIAL_AT::id) {
		return -144;
	}
	if (state == 126 && window.at(0) == Tokens::ID::id) {
		return -144;
	}
	if (state == 126 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -144;
	}
	if (state == 126 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -144;
	}
	if (state == 126 && window.at(0) == Tokens::PERCENT_SIGN::id) {
		return -144;
	}
	if (state == 126 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -144;
	}
	if (state == 126 && window.at(0) == Tokens::SEMICOLON::id) {
		return -144;
	}
	if (state == 126 && window.at(0) == Tokens::rule::nested_rule::NUMBER_SIGN::id) {
		return -144;
	}
	if (state == 126 && window.at(0) == Tokens::rule::value::ANY::id) {
		return -144;
	}
	if (state == 126 && window.at(0) == Tokens::rule::value::CGROUP::id) {
		return -144;
	}
	if (state == 126 && window.at(0) == Tokens::rule::value::NOSPACE::id) {
		return -144;
	}
	if (state == 126 && window.at(0) == Tokens::rule::value::QUANTIFIER::id) {
		return -144;
	}
	if (state == 126 && window.at(0) == Tokens::rule::value::SPACE::id) {
		return -144;
	}
	if (state == 126 && window.at(0) == Tokens::rule::value::STRING::id) {
		return -144;
	}
	if (state == 126 && window.at(0) == Tokens::rule::value::alternative::VERTICAL_LINE::id) {
		return -144;
	}
	if (state == 126 && window.at(0) == Tokens::rule::value::dyn::DOLLAR_SIGN::id) {
		return -144;
	}
	if (state == 126 && window.at(0) == Tokens::rule::value::shared_counter_registration::AUTO::id) {
		return -144;
	}
	if (state == 127 && window.at(0) == Tokens::AMPERSAND::id) {
		return -143;
	}
	if (state == 127 && window.at(0) == Tokens::AUTO::id) {
		return -143;
	}
	if (state == 127 && window.at(0) == Tokens::COMMERCIAL_AT::id) {
		return -143;
	}
	if (state == 127 && window.at(0) == Tokens::ID::id) {
		return -143;
	}
	if (state == 127 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -143;
	}
	if (state == 127 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -143;
	}
	if (state == 127 && window.at(0) == Tokens::PERCENT_SIGN::id) {
		return -143;
	}
	if (state == 127 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -143;
	}
	if (state == 127 && window.at(0) == Tokens::SEMICOLON::id) {
		return -143;
	}
	if (state == 127 && window.at(0) == Tokens::rule::nested_rule::NUMBER_SIGN::id) {
		return -143;
	}
	if (state == 127 && window.at(0) == Tokens::rule::value::ANY::id) {
		return -143;
	}
	if (state == 127 && window.at(0) == Tokens::rule::value::CGROUP::id) {
		return -143;
	}
	if (state == 127 && window.at(0) == Tokens::rule::value::NOSPACE::id) {
		return -143;
	}
	if (state == 127 && window.at(0) == Tokens::rule::value::QUANTIFIER::id) {
		return -143;
	}
	if (state == 127 && window.at(0) == Tokens::rule::value::SPACE::id) {
		return -143;
	}
	if (state == 127 && window.at(0) == Tokens::rule::value::STRING::id) {
		return -143;
	}
	if (state == 127 && window.at(0) == Tokens::rule::value::alternative::VERTICAL_LINE::id) {
		return -143;
	}
	if (state == 127 && window.at(0) == Tokens::rule::value::dyn::DOLLAR_SIGN::id) {
		return -143;
	}
	if (state == 127 && window.at(0) == Tokens::rule::value::shared_counter_registration::AUTO::id) {
		return -143;
	}
	if (state == 128 && window.at(0) == Tokens::AMPERSAND::id) {
		return -146;
	}
	if (state == 128 && window.at(0) == Tokens::AUTO::id) {
		return -146;
	}
	if (state == 128 && window.at(0) == Tokens::COMMERCIAL_AT::id) {
		return -146;
	}
	if (state == 128 && window.at(0) == Tokens::ID::id) {
		return -146;
	}
	if (state == 128 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -146;
	}
	if (state == 128 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -146;
	}
	if (state == 128 && window.at(0) == Tokens::PERCENT_SIGN::id) {
		return -146;
	}
	if (state == 128 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -146;
	}
	if (state == 128 && window.at(0) == Tokens::SEMICOLON::id) {
		return -146;
	}
	if (state == 128 && window.at(0) == Tokens::rule::nested_rule::NUMBER_SIGN::id) {
		return -146;
	}
	if (state == 128 && window.at(0) == Tokens::rule::value::ANY::id) {
		return -146;
	}
	if (state == 128 && window.at(0) == Tokens::rule::value::CGROUP::id) {
		return -146;
	}
	if (state == 128 && window.at(0) == Tokens::rule::value::NOSPACE::id) {
		return -146;
	}
	if (state == 128 && window.at(0) == Tokens::rule::value::QUANTIFIER::id) {
		return -146;
	}
	if (state == 128 && window.at(0) == Tokens::rule::value::SPACE::id) {
		return -146;
	}
	if (state == 128 && window.at(0) == Tokens::rule::value::STRING::id) {
		return -146;
	}
	if (state == 128 && window.at(0) == Tokens::rule::value::alternative::VERTICAL_LINE::id) {
		return -146;
	}
	if (state == 128 && window.at(0) == Tokens::rule::value::dyn::DOLLAR_SIGN::id) {
		return -146;
	}
	if (state == 128 && window.at(0) == Tokens::rule::value::shared_counter_registration::AUTO::id) {
		return -146;
	}
	if (state == 129 && window.at(0) == Tokens::AMPERSAND::id) {
		return -145;
	}
	if (state == 129 && window.at(0) == Tokens::AUTO::id) {
		return -145;
	}
	if (state == 129 && window.at(0) == Tokens::COMMERCIAL_AT::id) {
		return -145;
	}
	if (state == 129 && window.at(0) == Tokens::ID::id) {
		return -145;
	}
	if (state == 129 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -145;
	}
	if (state == 129 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -145;
	}
	if (state == 129 && window.at(0) == Tokens::PERCENT_SIGN::id) {
		return -145;
	}
	if (state == 129 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -145;
	}
	if (state == 129 && window.at(0) == Tokens::SEMICOLON::id) {
		return -145;
	}
	if (state == 129 && window.at(0) == Tokens::rule::nested_rule::NUMBER_SIGN::id) {
		return -145;
	}
	if (state == 129 && window.at(0) == Tokens::rule::value::ANY::id) {
		return -145;
	}
	if (state == 129 && window.at(0) == Tokens::rule::value::CGROUP::id) {
		return -145;
	}
	if (state == 129 && window.at(0) == Tokens::rule::value::NOSPACE::id) {
		return -145;
	}
	if (state == 129 && window.at(0) == Tokens::rule::value::QUANTIFIER::id) {
		return -145;
	}
	if (state == 129 && window.at(0) == Tokens::rule::value::SPACE::id) {
		return -145;
	}
	if (state == 129 && window.at(0) == Tokens::rule::value::STRING::id) {
		return -145;
	}
	if (state == 129 && window.at(0) == Tokens::rule::value::alternative::VERTICAL_LINE::id) {
		return -145;
	}
	if (state == 129 && window.at(0) == Tokens::rule::value::dyn::DOLLAR_SIGN::id) {
		return -145;
	}
	if (state == 129 && window.at(0) == Tokens::rule::value::shared_counter_registration::AUTO::id) {
		return -145;
	}
	if (state == 130 && window.at(0) == Tokens::AMPERSAND::id) {
		return -142;
	}
	if (state == 130 && window.at(0) == Tokens::AUTO::id) {
		return -142;
	}
	if (state == 130 && window.at(0) == Tokens::COMMERCIAL_AT::id) {
		return -142;
	}
	if (state == 130 && window.at(0) == Tokens::ID::id) {
		return -142;
	}
	if (state == 130 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -142;
	}
	if (state == 130 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -142;
	}
	if (state == 130 && window.at(0) == Tokens::PERCENT_SIGN::id) {
		return -142;
	}
	if (state == 130 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -142;
	}
	if (state == 130 && window.at(0) == Tokens::SEMICOLON::id) {
		return -142;
	}
	if (state == 130 && window.at(0) == Tokens::rule::nested_rule::NUMBER_SIGN::id) {
		return -142;
	}
	if (state == 130 && window.at(0) == Tokens::rule::value::ANY::id) {
		return -142;
	}
	if (state == 130 && window.at(0) == Tokens::rule::value::CGROUP::id) {
		return -142;
	}
	if (state == 130 && window.at(0) == Tokens::rule::value::NOSPACE::id) {
		return -142;
	}
	if (state == 130 && window.at(0) == Tokens::rule::value::QUANTIFIER::id) {
		return -142;
	}
	if (state == 130 && window.at(0) == Tokens::rule::value::SPACE::id) {
		return -142;
	}
	if (state == 130 && window.at(0) == Tokens::rule::value::STRING::id) {
		return -142;
	}
	if (state == 130 && window.at(0) == Tokens::rule::value::alternative::VERTICAL_LINE::id) {
		return -142;
	}
	if (state == 130 && window.at(0) == Tokens::rule::value::dyn::DOLLAR_SIGN::id) {
		return -142;
	}
	if (state == 130 && window.at(0) == Tokens::rule::value::shared_counter_registration::AUTO::id) {
		return -142;
	}
	if (state == 131 && window.at(0) == Tokens::AMPERSAND::id) {
		return -141;
	}
	if (state == 131 && window.at(0) == Tokens::AUTO::id) {
		return -141;
	}
	if (state == 131 && window.at(0) == Tokens::COMMERCIAL_AT::id) {
		return -141;
	}
	if (state == 131 && window.at(0) == Tokens::ID::id) {
		return -141;
	}
	if (state == 131 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -141;
	}
	if (state == 131 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -141;
	}
	if (state == 131 && window.at(0) == Tokens::PERCENT_SIGN::id) {
		return -141;
	}
	if (state == 131 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -141;
	}
	if (state == 131 && window.at(0) == Tokens::SEMICOLON::id) {
		return -141;
	}
	if (state == 131 && window.at(0) == Tokens::rule::nested_rule::NUMBER_SIGN::id) {
		return -141;
	}
	if (state == 131 && window.at(0) == Tokens::rule::value::ANY::id) {
		return -141;
	}
	if (state == 131 && window.at(0) == Tokens::rule::value::CGROUP::id) {
		return -141;
	}
	if (state == 131 && window.at(0) == Tokens::rule::value::NOSPACE::id) {
		return -141;
	}
	if (state == 131 && window.at(0) == Tokens::rule::value::QUANTIFIER::id) {
		return -141;
	}
	if (state == 131 && window.at(0) == Tokens::rule::value::SPACE::id) {
		return -141;
	}
	if (state == 131 && window.at(0) == Tokens::rule::value::STRING::id) {
		return -141;
	}
	if (state == 131 && window.at(0) == Tokens::rule::value::alternative::VERTICAL_LINE::id) {
		return -141;
	}
	if (state == 131 && window.at(0) == Tokens::rule::value::dyn::DOLLAR_SIGN::id) {
		return -141;
	}
	if (state == 131 && window.at(0) == Tokens::rule::value::shared_counter_registration::AUTO::id) {
		return -141;
	}
	if (state == 132 && window.at(0) == Tokens::ID::id) {
		return 162;
	}
	if (state == 132 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return 163;
	}
	if (state == 133 && window.at(0) == Tokens::AMPERSAND::id) {
		return -140;
	}
	if (state == 133 && window.at(0) == Tokens::AUTO::id) {
		return -140;
	}
	if (state == 133 && window.at(0) == Tokens::COMMERCIAL_AT::id) {
		return -140;
	}
	if (state == 133 && window.at(0) == Tokens::ID::id) {
		return -140;
	}
	if (state == 133 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -140;
	}
	if (state == 133 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -140;
	}
	if (state == 133 && window.at(0) == Tokens::PERCENT_SIGN::id) {
		return -140;
	}
	if (state == 133 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -140;
	}
	if (state == 133 && window.at(0) == Tokens::SEMICOLON::id) {
		return -140;
	}
	if (state == 133 && window.at(0) == Tokens::rule::nested_rule::NUMBER_SIGN::id) {
		return -140;
	}
	if (state == 133 && window.at(0) == Tokens::rule::value::ANY::id) {
		return -140;
	}
	if (state == 133 && window.at(0) == Tokens::rule::value::CGROUP::id) {
		return -140;
	}
	if (state == 133 && window.at(0) == Tokens::rule::value::NOSPACE::id) {
		return -140;
	}
	if (state == 133 && window.at(0) == Tokens::rule::value::QUANTIFIER::id) {
		return -140;
	}
	if (state == 133 && window.at(0) == Tokens::rule::value::SPACE::id) {
		return -140;
	}
	if (state == 133 && window.at(0) == Tokens::rule::value::STRING::id) {
		return -140;
	}
	if (state == 133 && window.at(0) == Tokens::rule::value::alternative::VERTICAL_LINE::id) {
		return -140;
	}
	if (state == 133 && window.at(0) == Tokens::rule::value::dyn::DOLLAR_SIGN::id) {
		return -140;
	}
	if (state == 133 && window.at(0) == Tokens::rule::value::shared_counter_registration::AUTO::id) {
		return -140;
	}
	if (state == 134 && window.at(0) == Tokens::AMPERSAND::id) {
		return -135;
	}
	if (state == 134 && window.at(0) == Tokens::AUTO::id) {
		return -135;
	}
	if (state == 134 && window.at(0) == Tokens::COMMERCIAL_AT::id) {
		return -135;
	}
	if (state == 134 && window.at(0) == Tokens::ID::id) {
		return -135;
	}
	if (state == 134 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -135;
	}
	if (state == 134 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -135;
	}
	if (state == 134 && window.at(0) == Tokens::PERCENT_SIGN::id) {
		return -135;
	}
	if (state == 134 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -135;
	}
	if (state == 134 && window.at(0) == Tokens::SEMICOLON::id) {
		return -135;
	}
	if (state == 134 && window.at(0) == Tokens::rule::nested_rule::NUMBER_SIGN::id) {
		return -135;
	}
	if (state == 134 && window.at(0) == Tokens::rule::value::ANY::id) {
		return -135;
	}
	if (state == 134 && window.at(0) == Tokens::rule::value::CGROUP::id) {
		return -135;
	}
	if (state == 134 && window.at(0) == Tokens::rule::value::NOSPACE::id) {
		return -135;
	}
	if (state == 134 && window.at(0) == Tokens::rule::value::QUANTIFIER::id) {
		return -135;
	}
	if (state == 134 && window.at(0) == Tokens::rule::value::SPACE::id) {
		return -135;
	}
	if (state == 134 && window.at(0) == Tokens::rule::value::STRING::id) {
		return -135;
	}
	if (state == 134 && window.at(0) == Tokens::rule::value::alternative::VERTICAL_LINE::id) {
		return 167;
	}
	if (state == 134 && window.at(0) == Tokens::rule::value::dyn::DOLLAR_SIGN::id) {
		return -135;
	}
	if (state == 134 && window.at(0) == Tokens::rule::value::shared_counter_registration::AUTO::id) {
		return -135;
	}
	if (state == 135 && window.at(0) == Tokens::RIGHT_CURLY_BRACKET::id) {
		return -7;
	}
	if (state == 136 && window.at(0) == Tokens::ID::id) {
		return 169;
	}
	if (state == 137 && window.at(0) == Tokens::PY_RAW::id) {
		return -19;
	}
	if (state == 137 && window.at(0) == Tokens::RIGHT_CURLY_BRACKET::id) {
		return -19;
	}
	if (state == 137 && window.at(0) == Tokens::advanced_rule::regular_match::MATCH::id) {
		return -19;
	}
	if (state == 138 && window.at(0) == Tokens::PY_RAW::id) {
		return -14;
	}
	if (state == 138 && window.at(0) == Tokens::RIGHT_CURLY_BRACKET::id) {
		return -14;
	}
	if (state == 138 && window.at(0) == Tokens::advanced_rule::regular_match::MATCH::id) {
		return -14;
	}
	if (state == 139 && window.at(0) == Tokens::PY_RAW::id) {
		return -18;
	}
	if (state == 139 && window.at(0) == Tokens::RIGHT_CURLY_BRACKET::id) {
		return -18;
	}
	if (state == 139 && window.at(0) == Tokens::advanced_rule::regular_match::MATCH::id) {
		return -18;
	}
	if (state == 140 && window.at(0) == Tokens::AUTO::id) {
		return -15;
	}
	if (state == 140 && window.at(0) == Tokens::SEMICOLON::id) {
		return -15;
	}
	if (state == 141 && window.at(0) == Tokens::AMPERSAND::id) {
		return 35;
	}
	if (state == 141 && window.at(0) == Tokens::AUTO::id) {
		return -16;
	}
	if (state == 141 && window.at(0) == Tokens::ID::id) {
		return -125;
	}
	if (state == 141 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -125;
	}
	if (state == 141 && window.at(0) == Tokens::SEMICOLON::id) {
		return -16;
	}
	if (state == 141 && window.at(0) == Tokens::rule::value::ANY::id) {
		return -125;
	}
	if (state == 141 && window.at(0) == Tokens::rule::value::CGROUP::id) {
		return -125;
	}
	if (state == 141 && window.at(0) == Tokens::rule::value::NOSPACE::id) {
		return -125;
	}
	if (state == 141 && window.at(0) == Tokens::rule::value::SPACE::id) {
		return -125;
	}
	if (state == 141 && window.at(0) == Tokens::rule::value::STRING::id) {
		return -125;
	}
	if (state == 141 && window.at(0) == Tokens::rule::value::dyn::DOLLAR_SIGN::id) {
		return -125;
	}
	if (state == 142 && window.at(0) == Tokens::PY_RAW::id) {
		return -27;
	}
	if (state == 142 && window.at(0) == Tokens::RIGHT_CURLY_BRACKET::id) {
		return -27;
	}
	if (state == 142 && window.at(0) == Tokens::advanced_rule::dep_decl::DEPENDS::id) {
		return -27;
	}
	if (state == 142 && window.at(0) == Tokens::advanced_rule::regular_match::MATCH::id) {
		return -27;
	}
	if (state == 143 && window.at(0) == Tokens::ID::id) {
		return 172;
	}
	if (state == 144 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -54;
	}
	if (state == 144 && window.at(0) == Tokens::template_params::GREATER_THAN_SIGN::id) {
		return -54;
	}
	if (state == 145 && window.at(0) == Tokens::PY_RAW::id) {
		return 89;
	}
	if (state == 146 && window.at(0) == Tokens::PERCENT_SIGN::id) {
		return -80;
	}
	if (state == 146 && window.at(0) == Tokens::SEMICOLON::id) {
		return -80;
	}
	if (state == 146 && window.at(0) == Tokens::rule::nested_rule::NUMBER_SIGN::id) {
		return -80;
	}
	if (state == 147 && window.at(0) == Tokens::RIGHT_CURLY_BRACKET::id) {
		return -81;
	}
	if (state == 148 && window.at(0) == Tokens::ID::id) {
		return 112;
	}
	if (state == 148 && window.at(0) == Tokens::RIGHT_CURLY_BRACKET::id) {
		return -82;
	}
	if (state == 149 && window.at(0) == Tokens::ID::id) {
		return 175;
	}
	if (state == 150 && window.at(0) == Tokens::RIGHT_CURLY_BRACKET::id) {
		return 176;
	}
	if (state == 151 && window.at(0) == Tokens::COMMA::id) {
		return 177;
	}
	if (state == 151 && window.at(0) == Tokens::RIGHT_CURLY_BRACKET::id) {
		return -89;
	}
	if (state == 152 && window.at(0) == static_cast<std::size_t>(-1)) {
		return -60;
	}
	if (state == 152 && window.at(0) == Tokens::FAIL::id) {
		return -60;
	}
	if (state == 152 && window.at(0) == Tokens::ID::id) {
		return -60;
	}
	if (state == 152 && window.at(0) == Tokens::SEMICOLON::id) {
		return -60;
	}
	if (state == 152 && window.at(0) == Tokens::grammar::modifier::AUTO::id) {
		return -60;
	}
	if (state == 152 && window.at(0) == Tokens::rule::nested_rule::NUMBER_SIGN::id) {
		return -60;
	}
	if (state == 153 && window.at(0) == Tokens::SEMICOLON::id) {
		return -69;
	}
	if (state == 154 && window.at(0) == Tokens::SEMICOLON::id) {
		return -70;
	}
	if (state == 154 && window.at(0) == Tokens::rule::nested_rule::NUMBER_SIGN::id) {
		return 120;
	}
	if (state == 155 && window.at(0) == Tokens::SEMICOLON::id) {
		return -93;
	}
	if (state == 155 && window.at(0) == Tokens::rule::nested_rule::NUMBER_SIGN::id) {
		return -93;
	}
	if (state == 156 && window.at(0) == Tokens::AMPERSAND::id) {
		return -118;
	}
	if (state == 156 && window.at(0) == Tokens::AUTO::id) {
		return -118;
	}
	if (state == 156 && window.at(0) == Tokens::COMMERCIAL_AT::id) {
		return -118;
	}
	if (state == 156 && window.at(0) == Tokens::ID::id) {
		return -118;
	}
	if (state == 156 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -118;
	}
	if (state == 156 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -118;
	}
	if (state == 156 && window.at(0) == Tokens::PERCENT_SIGN::id) {
		return -118;
	}
	if (state == 156 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -118;
	}
	if (state == 156 && window.at(0) == Tokens::SEMICOLON::id) {
		return -118;
	}
	if (state == 156 && window.at(0) == Tokens::rule::nested_rule::NUMBER_SIGN::id) {
		return -118;
	}
	if (state == 156 && window.at(0) == Tokens::rule::value::ANY::id) {
		return -118;
	}
	if (state == 156 && window.at(0) == Tokens::rule::value::CGROUP::id) {
		return -118;
	}
	if (state == 156 && window.at(0) == Tokens::rule::value::NOSPACE::id) {
		return -118;
	}
	if (state == 156 && window.at(0) == Tokens::rule::value::SPACE::id) {
		return -118;
	}
	if (state == 156 && window.at(0) == Tokens::rule::value::STRING::id) {
		return -118;
	}
	if (state == 156 && window.at(0) == Tokens::rule::value::dyn::DOLLAR_SIGN::id) {
		return -118;
	}
	if (state == 157 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -119;
	}
	if (state == 158 && window.at(0) == Tokens::AMPERSAND::id) {
		return 35;
	}
	if (state == 158 && window.at(0) == Tokens::COMMERCIAL_AT::id) {
		return -125;
	}
	if (state == 158 && window.at(0) == Tokens::ID::id) {
		return -125;
	}
	if (state == 158 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -125;
	}
	if (state == 158 && window.at(0) == Tokens::PERCENT_SIGN::id) {
		return -125;
	}
	if (state == 158 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -120;
	}
	if (state == 158 && window.at(0) == Tokens::rule::value::ANY::id) {
		return -125;
	}
	if (state == 158 && window.at(0) == Tokens::rule::value::CGROUP::id) {
		return -125;
	}
	if (state == 158 && window.at(0) == Tokens::rule::value::NOSPACE::id) {
		return -125;
	}
	if (state == 158 && window.at(0) == Tokens::rule::value::SPACE::id) {
		return -125;
	}
	if (state == 158 && window.at(0) == Tokens::rule::value::STRING::id) {
		return -125;
	}
	if (state == 158 && window.at(0) == Tokens::rule::value::dyn::DOLLAR_SIGN::id) {
		return -125;
	}
	if (state == 159 && window.at(0) == Tokens::AMPERSAND::id) {
		return 35;
	}
	if (state == 159 && window.at(0) == Tokens::ID::id) {
		return -125;
	}
	if (state == 159 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -125;
	}
	if (state == 159 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -116;
	}
	if (state == 159 && window.at(0) == Tokens::rule::value::ANY::id) {
		return -125;
	}
	if (state == 159 && window.at(0) == Tokens::rule::value::CGROUP::id) {
		return -125;
	}
	if (state == 159 && window.at(0) == Tokens::rule::value::NOSPACE::id) {
		return -125;
	}
	if (state == 159 && window.at(0) == Tokens::rule::value::SPACE::id) {
		return -125;
	}
	if (state == 159 && window.at(0) == Tokens::rule::value::STRING::id) {
		return -125;
	}
	if (state == 159 && window.at(0) == Tokens::rule::value::dyn::DOLLAR_SIGN::id) {
		return -125;
	}
	if (state == 160 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return 183;
	}
	if (state == 161 && window.at(0) == Tokens::AMPERSAND::id) {
		return -109;
	}
	if (state == 161 && window.at(0) == Tokens::AUTO::id) {
		return -109;
	}
	if (state == 161 && window.at(0) == Tokens::COMMERCIAL_AT::id) {
		return -109;
	}
	if (state == 161 && window.at(0) == Tokens::ID::id) {
		return -109;
	}
	if (state == 161 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -109;
	}
	if (state == 161 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -109;
	}
	if (state == 161 && window.at(0) == Tokens::PERCENT_SIGN::id) {
		return -109;
	}
	if (state == 161 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -109;
	}
	if (state == 161 && window.at(0) == Tokens::SEMICOLON::id) {
		return -109;
	}
	if (state == 161 && window.at(0) == Tokens::rule::nested_rule::NUMBER_SIGN::id) {
		return -109;
	}
	if (state == 161 && window.at(0) == Tokens::rule::value::ANY::id) {
		return -109;
	}
	if (state == 161 && window.at(0) == Tokens::rule::value::CGROUP::id) {
		return -109;
	}
	if (state == 161 && window.at(0) == Tokens::rule::value::NOSPACE::id) {
		return -109;
	}
	if (state == 161 && window.at(0) == Tokens::rule::value::QUANTIFIER::id) {
		return -109;
	}
	if (state == 161 && window.at(0) == Tokens::rule::value::SPACE::id) {
		return -109;
	}
	if (state == 161 && window.at(0) == Tokens::rule::value::STRING::id) {
		return -109;
	}
	if (state == 161 && window.at(0) == Tokens::rule::value::alternative::VERTICAL_LINE::id) {
		return -109;
	}
	if (state == 161 && window.at(0) == Tokens::rule::value::dyn::DOLLAR_SIGN::id) {
		return -109;
	}
	if (state == 161 && window.at(0) == Tokens::rule::value::shared_counter_registration::AUTO::id) {
		return -109;
	}
	if (state == 162 && window.at(0) == Tokens::PY_RAW::id) {
		return 89;
	}
	if (state == 163 && window.at(0) == Tokens::AMPERSAND::id) {
		return -107;
	}
	if (state == 163 && window.at(0) == Tokens::AUTO::id) {
		return -107;
	}
	if (state == 163 && window.at(0) == Tokens::COMMERCIAL_AT::id) {
		return -107;
	}
	if (state == 163 && window.at(0) == Tokens::ID::id) {
		return -107;
	}
	if (state == 163 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -107;
	}
	if (state == 163 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -107;
	}
	if (state == 163 && window.at(0) == Tokens::PERCENT_SIGN::id) {
		return -107;
	}
	if (state == 163 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -107;
	}
	if (state == 163 && window.at(0) == Tokens::SEMICOLON::id) {
		return -107;
	}
	if (state == 163 && window.at(0) == Tokens::rule::nested_rule::NUMBER_SIGN::id) {
		return -107;
	}
	if (state == 163 && window.at(0) == Tokens::rule::value::ANY::id) {
		return -107;
	}
	if (state == 163 && window.at(0) == Tokens::rule::value::CGROUP::id) {
		return -107;
	}
	if (state == 163 && window.at(0) == Tokens::rule::value::NOSPACE::id) {
		return -107;
	}
	if (state == 163 && window.at(0) == Tokens::rule::value::QUANTIFIER::id) {
		return -107;
	}
	if (state == 163 && window.at(0) == Tokens::rule::value::SPACE::id) {
		return -107;
	}
	if (state == 163 && window.at(0) == Tokens::rule::value::STRING::id) {
		return -107;
	}
	if (state == 163 && window.at(0) == Tokens::rule::value::alternative::VERTICAL_LINE::id) {
		return -107;
	}
	if (state == 163 && window.at(0) == Tokens::rule::value::dyn::DOLLAR_SIGN::id) {
		return -107;
	}
	if (state == 163 && window.at(0) == Tokens::rule::value::shared_counter_registration::AUTO::id) {
		return -107;
	}
	if (state == 164 && window.at(0) == Tokens::AMPERSAND::id) {
		return -108;
	}
	if (state == 164 && window.at(0) == Tokens::AUTO::id) {
		return -108;
	}
	if (state == 164 && window.at(0) == Tokens::COMMERCIAL_AT::id) {
		return -108;
	}
	if (state == 164 && window.at(0) == Tokens::ID::id) {
		return -108;
	}
	if (state == 164 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -108;
	}
	if (state == 164 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -108;
	}
	if (state == 164 && window.at(0) == Tokens::PERCENT_SIGN::id) {
		return -108;
	}
	if (state == 164 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -108;
	}
	if (state == 164 && window.at(0) == Tokens::SEMICOLON::id) {
		return -108;
	}
	if (state == 164 && window.at(0) == Tokens::rule::nested_rule::NUMBER_SIGN::id) {
		return -108;
	}
	if (state == 164 && window.at(0) == Tokens::rule::value::ANY::id) {
		return -108;
	}
	if (state == 164 && window.at(0) == Tokens::rule::value::CGROUP::id) {
		return -108;
	}
	if (state == 164 && window.at(0) == Tokens::rule::value::NOSPACE::id) {
		return -108;
	}
	if (state == 164 && window.at(0) == Tokens::rule::value::QUANTIFIER::id) {
		return -108;
	}
	if (state == 164 && window.at(0) == Tokens::rule::value::SPACE::id) {
		return -108;
	}
	if (state == 164 && window.at(0) == Tokens::rule::value::STRING::id) {
		return -108;
	}
	if (state == 164 && window.at(0) == Tokens::rule::value::alternative::VERTICAL_LINE::id) {
		return -108;
	}
	if (state == 164 && window.at(0) == Tokens::rule::value::dyn::DOLLAR_SIGN::id) {
		return -108;
	}
	if (state == 164 && window.at(0) == Tokens::rule::value::shared_counter_registration::AUTO::id) {
		return -108;
	}
	if (state == 165 && window.at(0) == Tokens::AMPERSAND::id) {
		return -137;
	}
	if (state == 165 && window.at(0) == Tokens::AUTO::id) {
		return -137;
	}
	if (state == 165 && window.at(0) == Tokens::COMMERCIAL_AT::id) {
		return -137;
	}
	if (state == 165 && window.at(0) == Tokens::ID::id) {
		return -137;
	}
	if (state == 165 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -137;
	}
	if (state == 165 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -137;
	}
	if (state == 165 && window.at(0) == Tokens::PERCENT_SIGN::id) {
		return -137;
	}
	if (state == 165 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -137;
	}
	if (state == 165 && window.at(0) == Tokens::SEMICOLON::id) {
		return -137;
	}
	if (state == 165 && window.at(0) == Tokens::rule::nested_rule::NUMBER_SIGN::id) {
		return -137;
	}
	if (state == 165 && window.at(0) == Tokens::rule::value::ANY::id) {
		return -137;
	}
	if (state == 165 && window.at(0) == Tokens::rule::value::CGROUP::id) {
		return -137;
	}
	if (state == 165 && window.at(0) == Tokens::rule::value::NOSPACE::id) {
		return -137;
	}
	if (state == 165 && window.at(0) == Tokens::rule::value::QUANTIFIER::id) {
		return -137;
	}
	if (state == 165 && window.at(0) == Tokens::rule::value::SPACE::id) {
		return -137;
	}
	if (state == 165 && window.at(0) == Tokens::rule::value::STRING::id) {
		return -137;
	}
	if (state == 165 && window.at(0) == Tokens::rule::value::alternative::VERTICAL_LINE::id) {
		return 167;
	}
	if (state == 165 && window.at(0) == Tokens::rule::value::dyn::DOLLAR_SIGN::id) {
		return -137;
	}
	if (state == 165 && window.at(0) == Tokens::rule::value::shared_counter_registration::AUTO::id) {
		return -137;
	}
	if (state == 166 && window.at(0) == Tokens::ID::id) {
		return 11;
	}
	if (state == 166 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return 125;
	}
	if (state == 166 && window.at(0) == Tokens::rule::value::ANY::id) {
		return 127;
	}
	if (state == 166 && window.at(0) == Tokens::rule::value::CGROUP::id) {
		return 128;
	}
	if (state == 166 && window.at(0) == Tokens::rule::value::NOSPACE::id) {
		return 129;
	}
	if (state == 166 && window.at(0) == Tokens::rule::value::SPACE::id) {
		return 130;
	}
	if (state == 166 && window.at(0) == Tokens::rule::value::STRING::id) {
		return 131;
	}
	if (state == 166 && window.at(0) == Tokens::rule::value::dyn::DOLLAR_SIGN::id) {
		return 133;
	}
	if (state == 167 && window.at(0) == Tokens::AMPERSAND::id) {
		return -127;
	}
	if (state == 167 && window.at(0) == Tokens::AUTO::id) {
		return -127;
	}
	if (state == 167 && window.at(0) == Tokens::COMMERCIAL_AT::id) {
		return -127;
	}
	if (state == 167 && window.at(0) == Tokens::ID::id) {
		return -127;
	}
	if (state == 167 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -127;
	}
	if (state == 167 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -127;
	}
	if (state == 167 && window.at(0) == Tokens::PERCENT_SIGN::id) {
		return -127;
	}
	if (state == 167 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -127;
	}
	if (state == 167 && window.at(0) == Tokens::SEMICOLON::id) {
		return -127;
	}
	if (state == 167 && window.at(0) == Tokens::rule::nested_rule::NUMBER_SIGN::id) {
		return -127;
	}
	if (state == 167 && window.at(0) == Tokens::rule::value::ANY::id) {
		return -127;
	}
	if (state == 167 && window.at(0) == Tokens::rule::value::CGROUP::id) {
		return -127;
	}
	if (state == 167 && window.at(0) == Tokens::rule::value::NOSPACE::id) {
		return -127;
	}
	if (state == 167 && window.at(0) == Tokens::rule::value::QUANTIFIER::id) {
		return 188;
	}
	if (state == 167 && window.at(0) == Tokens::rule::value::SPACE::id) {
		return -127;
	}
	if (state == 167 && window.at(0) == Tokens::rule::value::STRING::id) {
		return -127;
	}
	if (state == 167 && window.at(0) == Tokens::rule::value::dyn::DOLLAR_SIGN::id) {
		return -127;
	}
	if (state == 167 && window.at(0) == Tokens::rule::value::shared_counter_registration::AUTO::id) {
		return -127;
	}
	if (state == 168 && window.at(0) == Tokens::ID::id) {
		return 191;
	}
	if (state == 168 && window.at(0) == Tokens::PY_RAW::id) {
		return -22;
	}
	if (state == 168 && window.at(0) == Tokens::RIGHT_CURLY_BRACKET::id) {
		return -22;
	}
	if (state == 168 && window.at(0) == Tokens::advanced_rule::regular_match::MATCH::id) {
		return -22;
	}
	if (state == 169 && window.at(0) == Tokens::PY_RAW::id) {
		return -20;
	}
	if (state == 169 && window.at(0) == Tokens::RIGHT_CURLY_BRACKET::id) {
		return -20;
	}
	if (state == 169 && window.at(0) == Tokens::advanced_rule::regular_match::MATCH::id) {
		return -20;
	}
	if (state == 170 && window.at(0) == Tokens::AUTO::id) {
		return -17;
	}
	if (state == 170 && window.at(0) == Tokens::SEMICOLON::id) {
		return -17;
	}
	if (state == 171 && window.at(0) == Tokens::COMMA::id) {
		return 144;
	}
	if (state == 171 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -55;
	}
	if (state == 171 && window.at(0) == Tokens::template_params::GREATER_THAN_SIGN::id) {
		return -55;
	}
	if (state == 172 && window.at(0) == Tokens::ID::id) {
		return -84;
	}
	if (state == 172 && window.at(0) == Tokens::RIGHT_CURLY_BRACKET::id) {
		return -84;
	}
	if (state == 173 && window.at(0) == Tokens::RIGHT_CURLY_BRACKET::id) {
		return -83;
	}
	if (state == 174 && window.at(0) == Tokens::COMMA::id) {
		return 194;
	}
	if (state == 174 && window.at(0) == Tokens::RIGHT_CURLY_BRACKET::id) {
		return -78;
	}
	if (state == 175 && window.at(0) == Tokens::PERCENT_SIGN::id) {
		return -75;
	}
	if (state == 175 && window.at(0) == Tokens::SEMICOLON::id) {
		return -75;
	}
	if (state == 175 && window.at(0) == Tokens::rule::nested_rule::NUMBER_SIGN::id) {
		return -75;
	}
	if (state == 176 && window.at(0) == Tokens::ID::id) {
		return 196;
	}
	if (state == 177 && window.at(0) == Tokens::RIGHT_CURLY_BRACKET::id) {
		return 197;
	}
	if (state == 178 && window.at(0) == Tokens::SEMICOLON::id) {
		return -71;
	}
	if (state == 179 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -121;
	}
	if (state == 180 && window.at(0) == Tokens::AMPERSAND::id) {
		return 35;
	}
	if (state == 180 && window.at(0) == Tokens::ID::id) {
		return -125;
	}
	if (state == 180 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -125;
	}
	if (state == 180 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -116;
	}
	if (state == 180 && window.at(0) == Tokens::rule::value::ANY::id) {
		return -125;
	}
	if (state == 180 && window.at(0) == Tokens::rule::value::CGROUP::id) {
		return -125;
	}
	if (state == 180 && window.at(0) == Tokens::rule::value::NOSPACE::id) {
		return -125;
	}
	if (state == 180 && window.at(0) == Tokens::rule::value::SPACE::id) {
		return -125;
	}
	if (state == 180 && window.at(0) == Tokens::rule::value::STRING::id) {
		return -125;
	}
	if (state == 180 && window.at(0) == Tokens::rule::value::dyn::DOLLAR_SIGN::id) {
		return -125;
	}
	if (state == 181 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -115;
	}
	if (state == 182 && window.at(0) == Tokens::AMPERSAND::id) {
		return -114;
	}
	if (state == 182 && window.at(0) == Tokens::AUTO::id) {
		return -114;
	}
	if (state == 182 && window.at(0) == Tokens::COMMERCIAL_AT::id) {
		return -114;
	}
	if (state == 182 && window.at(0) == Tokens::ID::id) {
		return -114;
	}
	if (state == 182 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -114;
	}
	if (state == 182 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -114;
	}
	if (state == 182 && window.at(0) == Tokens::PERCENT_SIGN::id) {
		return -114;
	}
	if (state == 182 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -114;
	}
	if (state == 182 && window.at(0) == Tokens::SEMICOLON::id) {
		return -114;
	}
	if (state == 182 && window.at(0) == Tokens::rule::nested_rule::NUMBER_SIGN::id) {
		return -114;
	}
	if (state == 182 && window.at(0) == Tokens::rule::value::ANY::id) {
		return -114;
	}
	if (state == 182 && window.at(0) == Tokens::rule::value::CGROUP::id) {
		return -114;
	}
	if (state == 182 && window.at(0) == Tokens::rule::value::NOSPACE::id) {
		return -114;
	}
	if (state == 182 && window.at(0) == Tokens::rule::value::QUANTIFIER::id) {
		return -114;
	}
	if (state == 182 && window.at(0) == Tokens::rule::value::SPACE::id) {
		return -114;
	}
	if (state == 182 && window.at(0) == Tokens::rule::value::STRING::id) {
		return -114;
	}
	if (state == 182 && window.at(0) == Tokens::rule::value::alternative::VERTICAL_LINE::id) {
		return -114;
	}
	if (state == 182 && window.at(0) == Tokens::rule::value::dyn::DOLLAR_SIGN::id) {
		return -114;
	}
	if (state == 182 && window.at(0) == Tokens::rule::value::shared_counter_registration::AUTO::id) {
		return -114;
	}
	if (state == 183 && window.at(0) == Tokens::RIGHT_CURLY_BRACKET::id) {
		return 199;
	}
	if (state == 184 && window.at(0) == Tokens::AMPERSAND::id) {
		return -137;
	}
	if (state == 184 && window.at(0) == Tokens::AUTO::id) {
		return -137;
	}
	if (state == 184 && window.at(0) == Tokens::COMMERCIAL_AT::id) {
		return -137;
	}
	if (state == 184 && window.at(0) == Tokens::ID::id) {
		return -137;
	}
	if (state == 184 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -137;
	}
	if (state == 184 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -137;
	}
	if (state == 184 && window.at(0) == Tokens::PERCENT_SIGN::id) {
		return -137;
	}
	if (state == 184 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -137;
	}
	if (state == 184 && window.at(0) == Tokens::SEMICOLON::id) {
		return -137;
	}
	if (state == 184 && window.at(0) == Tokens::rule::nested_rule::NUMBER_SIGN::id) {
		return -137;
	}
	if (state == 184 && window.at(0) == Tokens::rule::value::ANY::id) {
		return -137;
	}
	if (state == 184 && window.at(0) == Tokens::rule::value::CGROUP::id) {
		return -137;
	}
	if (state == 184 && window.at(0) == Tokens::rule::value::NOSPACE::id) {
		return -137;
	}
	if (state == 184 && window.at(0) == Tokens::rule::value::QUANTIFIER::id) {
		return -137;
	}
	if (state == 184 && window.at(0) == Tokens::rule::value::SPACE::id) {
		return -137;
	}
	if (state == 184 && window.at(0) == Tokens::rule::value::STRING::id) {
		return -137;
	}
	if (state == 184 && window.at(0) == Tokens::rule::value::alternative::VERTICAL_LINE::id) {
		return 167;
	}
	if (state == 184 && window.at(0) == Tokens::rule::value::dyn::DOLLAR_SIGN::id) {
		return -137;
	}
	if (state == 184 && window.at(0) == Tokens::rule::value::shared_counter_registration::AUTO::id) {
		return -137;
	}
	if (state == 185 && window.at(0) == Tokens::AMPERSAND::id) {
		return -136;
	}
	if (state == 185 && window.at(0) == Tokens::AUTO::id) {
		return -136;
	}
	if (state == 185 && window.at(0) == Tokens::COMMERCIAL_AT::id) {
		return -136;
	}
	if (state == 185 && window.at(0) == Tokens::ID::id) {
		return -136;
	}
	if (state == 185 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -136;
	}
	if (state == 185 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -136;
	}
	if (state == 185 && window.at(0) == Tokens::PERCENT_SIGN::id) {
		return -136;
	}
	if (state == 185 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -136;
	}
	if (state == 185 && window.at(0) == Tokens::SEMICOLON::id) {
		return -136;
	}
	if (state == 185 && window.at(0) == Tokens::rule::nested_rule::NUMBER_SIGN::id) {
		return -136;
	}
	if (state == 185 && window.at(0) == Tokens::rule::value::ANY::id) {
		return -136;
	}
	if (state == 185 && window.at(0) == Tokens::rule::value::CGROUP::id) {
		return -136;
	}
	if (state == 185 && window.at(0) == Tokens::rule::value::NOSPACE::id) {
		return -136;
	}
	if (state == 185 && window.at(0) == Tokens::rule::value::QUANTIFIER::id) {
		return -136;
	}
	if (state == 185 && window.at(0) == Tokens::rule::value::SPACE::id) {
		return -136;
	}
	if (state == 185 && window.at(0) == Tokens::rule::value::STRING::id) {
		return -136;
	}
	if (state == 185 && window.at(0) == Tokens::rule::value::dyn::DOLLAR_SIGN::id) {
		return -136;
	}
	if (state == 185 && window.at(0) == Tokens::rule::value::shared_counter_registration::AUTO::id) {
		return -136;
	}
	if (state == 186 && window.at(0) == Tokens::AMPERSAND::id) {
		return -96;
	}
	if (state == 186 && window.at(0) == Tokens::AUTO::id) {
		return -96;
	}
	if (state == 186 && window.at(0) == Tokens::COMMERCIAL_AT::id) {
		return -96;
	}
	if (state == 186 && window.at(0) == Tokens::ID::id) {
		return -96;
	}
	if (state == 186 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -96;
	}
	if (state == 186 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -96;
	}
	if (state == 186 && window.at(0) == Tokens::PERCENT_SIGN::id) {
		return -96;
	}
	if (state == 186 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -96;
	}
	if (state == 186 && window.at(0) == Tokens::SEMICOLON::id) {
		return -96;
	}
	if (state == 186 && window.at(0) == Tokens::rule::nested_rule::NUMBER_SIGN::id) {
		return -96;
	}
	if (state == 186 && window.at(0) == Tokens::rule::value::ANY::id) {
		return -96;
	}
	if (state == 186 && window.at(0) == Tokens::rule::value::CGROUP::id) {
		return -96;
	}
	if (state == 186 && window.at(0) == Tokens::rule::value::NOSPACE::id) {
		return -96;
	}
	if (state == 186 && window.at(0) == Tokens::rule::value::QUANTIFIER::id) {
		return -96;
	}
	if (state == 186 && window.at(0) == Tokens::rule::value::SPACE::id) {
		return -96;
	}
	if (state == 186 && window.at(0) == Tokens::rule::value::STRING::id) {
		return -96;
	}
	if (state == 186 && window.at(0) == Tokens::rule::value::alternative::VERTICAL_LINE::id) {
		return -96;
	}
	if (state == 186 && window.at(0) == Tokens::rule::value::dyn::DOLLAR_SIGN::id) {
		return -96;
	}
	if (state == 186 && window.at(0) == Tokens::rule::value::shared_counter_registration::AUTO::id) {
		return -96;
	}
	if (state == 187 && window.at(0) == Tokens::AMPERSAND::id) {
		return -101;
	}
	if (state == 187 && window.at(0) == Tokens::AUTO::id) {
		return -101;
	}
	if (state == 187 && window.at(0) == Tokens::COMMERCIAL_AT::id) {
		return -101;
	}
	if (state == 187 && window.at(0) == Tokens::EQUALS_SIGN::id) {
		return 201;
	}
	if (state == 187 && window.at(0) == Tokens::ID::id) {
		return -101;
	}
	if (state == 187 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -101;
	}
	if (state == 187 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -101;
	}
	if (state == 187 && window.at(0) == Tokens::PERCENT_SIGN::id) {
		return -101;
	}
	if (state == 187 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -101;
	}
	if (state == 187 && window.at(0) == Tokens::SEMICOLON::id) {
		return -101;
	}
	if (state == 187 && window.at(0) == Tokens::rule::nested_rule::NUMBER_SIGN::id) {
		return -101;
	}
	if (state == 187 && window.at(0) == Tokens::rule::value::ANY::id) {
		return -101;
	}
	if (state == 187 && window.at(0) == Tokens::rule::value::CGROUP::id) {
		return -101;
	}
	if (state == 187 && window.at(0) == Tokens::rule::value::NOSPACE::id) {
		return -101;
	}
	if (state == 187 && window.at(0) == Tokens::rule::value::SPACE::id) {
		return -101;
	}
	if (state == 187 && window.at(0) == Tokens::rule::value::STRING::id) {
		return -101;
	}
	if (state == 187 && window.at(0) == Tokens::rule::value::dyn::DOLLAR_SIGN::id) {
		return -101;
	}
	if (state == 187 && window.at(0) == Tokens::rule::value::shared_counter_registration::AUTO::id) {
		return -101;
	}
	if (state == 188 && window.at(0) == Tokens::AMPERSAND::id) {
		return -128;
	}
	if (state == 188 && window.at(0) == Tokens::AUTO::id) {
		return -128;
	}
	if (state == 188 && window.at(0) == Tokens::COMMERCIAL_AT::id) {
		return -128;
	}
	if (state == 188 && window.at(0) == Tokens::ID::id) {
		return -128;
	}
	if (state == 188 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -128;
	}
	if (state == 188 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -128;
	}
	if (state == 188 && window.at(0) == Tokens::PERCENT_SIGN::id) {
		return -128;
	}
	if (state == 188 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -128;
	}
	if (state == 188 && window.at(0) == Tokens::SEMICOLON::id) {
		return -128;
	}
	if (state == 188 && window.at(0) == Tokens::rule::nested_rule::NUMBER_SIGN::id) {
		return -128;
	}
	if (state == 188 && window.at(0) == Tokens::rule::value::ANY::id) {
		return -128;
	}
	if (state == 188 && window.at(0) == Tokens::rule::value::CGROUP::id) {
		return -128;
	}
	if (state == 188 && window.at(0) == Tokens::rule::value::NOSPACE::id) {
		return -128;
	}
	if (state == 188 && window.at(0) == Tokens::rule::value::SPACE::id) {
		return -128;
	}
	if (state == 188 && window.at(0) == Tokens::rule::value::STRING::id) {
		return -128;
	}
	if (state == 188 && window.at(0) == Tokens::rule::value::dyn::DOLLAR_SIGN::id) {
		return -128;
	}
	if (state == 188 && window.at(0) == Tokens::rule::value::shared_counter_registration::AUTO::id) {
		return -128;
	}
	if (state == 189 && window.at(0) == Tokens::AMPERSAND::id) {
		return -129;
	}
	if (state == 189 && window.at(0) == Tokens::AUTO::id) {
		return -129;
	}
	if (state == 189 && window.at(0) == Tokens::COMMERCIAL_AT::id) {
		return -129;
	}
	if (state == 189 && window.at(0) == Tokens::ID::id) {
		return -129;
	}
	if (state == 189 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -129;
	}
	if (state == 189 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -129;
	}
	if (state == 189 && window.at(0) == Tokens::PERCENT_SIGN::id) {
		return -129;
	}
	if (state == 189 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -129;
	}
	if (state == 189 && window.at(0) == Tokens::SEMICOLON::id) {
		return -129;
	}
	if (state == 189 && window.at(0) == Tokens::rule::nested_rule::NUMBER_SIGN::id) {
		return -129;
	}
	if (state == 189 && window.at(0) == Tokens::rule::value::ANY::id) {
		return -129;
	}
	if (state == 189 && window.at(0) == Tokens::rule::value::CGROUP::id) {
		return -129;
	}
	if (state == 189 && window.at(0) == Tokens::rule::value::NOSPACE::id) {
		return -129;
	}
	if (state == 189 && window.at(0) == Tokens::rule::value::SPACE::id) {
		return -129;
	}
	if (state == 189 && window.at(0) == Tokens::rule::value::STRING::id) {
		return -129;
	}
	if (state == 189 && window.at(0) == Tokens::rule::value::dyn::DOLLAR_SIGN::id) {
		return -129;
	}
	if (state == 189 && window.at(0) == Tokens::rule::value::shared_counter_registration::AUTO::id) {
		return 206;
	}
	if (state == 190 && window.at(0) == Tokens::ID::id) {
		return 191;
	}
	if (state == 190 && window.at(0) == Tokens::PY_RAW::id) {
		return -22;
	}
	if (state == 190 && window.at(0) == Tokens::RIGHT_CURLY_BRACKET::id) {
		return -22;
	}
	if (state == 190 && window.at(0) == Tokens::advanced_rule::regular_match::MATCH::id) {
		return -22;
	}
	if (state == 191 && window.at(0) == Tokens::PY_RAW::id) {
		return -21;
	}
	if (state == 191 && window.at(0) == Tokens::RIGHT_CURLY_BRACKET::id) {
		return -21;
	}
	if (state == 191 && window.at(0) == Tokens::advanced_rule::regular_match::MATCH::id) {
		return -21;
	}
	if (state == 192 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -56;
	}
	if (state == 192 && window.at(0) == Tokens::template_params::GREATER_THAN_SIGN::id) {
		return -56;
	}
	if (state == 193 && window.at(0) == Tokens::ID::id) {
		return 208;
	}
	if (state == 194 && window.at(0) == Tokens::RIGHT_CURLY_BRACKET::id) {
		return -77;
	}
	if (state == 195 && window.at(0) == Tokens::COMMA::id) {
		return 209;
	}
	if (state == 195 && window.at(0) == Tokens::RIGHT_CURLY_BRACKET::id) {
		return -91;
	}
	if (state == 196 && window.at(0) == Tokens::SEMICOLON::id) {
		return -88;
	}
	if (state == 196 && window.at(0) == Tokens::rule::nested_rule::NUMBER_SIGN::id) {
		return -88;
	}
	if (state == 197 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -117;
	}
	if (state == 198 && window.at(0) == Tokens::AMPERSAND::id) {
		return -110;
	}
	if (state == 198 && window.at(0) == Tokens::AUTO::id) {
		return -110;
	}
	if (state == 198 && window.at(0) == Tokens::COMMERCIAL_AT::id) {
		return -110;
	}
	if (state == 198 && window.at(0) == Tokens::ID::id) {
		return -110;
	}
	if (state == 198 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -110;
	}
	if (state == 198 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -110;
	}
	if (state == 198 && window.at(0) == Tokens::PERCENT_SIGN::id) {
		return -110;
	}
	if (state == 198 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -110;
	}
	if (state == 198 && window.at(0) == Tokens::SEMICOLON::id) {
		return -110;
	}
	if (state == 198 && window.at(0) == Tokens::rule::nested_rule::NUMBER_SIGN::id) {
		return -110;
	}
	if (state == 198 && window.at(0) == Tokens::rule::value::ANY::id) {
		return -110;
	}
	if (state == 198 && window.at(0) == Tokens::rule::value::CGROUP::id) {
		return -110;
	}
	if (state == 198 && window.at(0) == Tokens::rule::value::NOSPACE::id) {
		return -110;
	}
	if (state == 198 && window.at(0) == Tokens::rule::value::QUANTIFIER::id) {
		return -110;
	}
	if (state == 198 && window.at(0) == Tokens::rule::value::SPACE::id) {
		return -110;
	}
	if (state == 198 && window.at(0) == Tokens::rule::value::STRING::id) {
		return -110;
	}
	if (state == 198 && window.at(0) == Tokens::rule::value::alternative::VERTICAL_LINE::id) {
		return -110;
	}
	if (state == 198 && window.at(0) == Tokens::rule::value::dyn::DOLLAR_SIGN::id) {
		return -110;
	}
	if (state == 198 && window.at(0) == Tokens::rule::value::shared_counter_registration::AUTO::id) {
		return -110;
	}
	if (state == 199 && window.at(0) == Tokens::AMPERSAND::id) {
		return -138;
	}
	if (state == 199 && window.at(0) == Tokens::AUTO::id) {
		return -138;
	}
	if (state == 199 && window.at(0) == Tokens::COMMERCIAL_AT::id) {
		return -138;
	}
	if (state == 199 && window.at(0) == Tokens::ID::id) {
		return -138;
	}
	if (state == 199 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -138;
	}
	if (state == 199 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -138;
	}
	if (state == 199 && window.at(0) == Tokens::PERCENT_SIGN::id) {
		return -138;
	}
	if (state == 199 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -138;
	}
	if (state == 199 && window.at(0) == Tokens::SEMICOLON::id) {
		return -138;
	}
	if (state == 199 && window.at(0) == Tokens::rule::nested_rule::NUMBER_SIGN::id) {
		return -138;
	}
	if (state == 199 && window.at(0) == Tokens::rule::value::ANY::id) {
		return -138;
	}
	if (state == 199 && window.at(0) == Tokens::rule::value::CGROUP::id) {
		return -138;
	}
	if (state == 199 && window.at(0) == Tokens::rule::value::NOSPACE::id) {
		return -138;
	}
	if (state == 199 && window.at(0) == Tokens::rule::value::QUANTIFIER::id) {
		return -138;
	}
	if (state == 199 && window.at(0) == Tokens::rule::value::SPACE::id) {
		return -138;
	}
	if (state == 199 && window.at(0) == Tokens::rule::value::STRING::id) {
		return -138;
	}
	if (state == 199 && window.at(0) == Tokens::rule::value::dyn::DOLLAR_SIGN::id) {
		return -138;
	}
	if (state == 199 && window.at(0) == Tokens::rule::value::shared_counter_registration::AUTO::id) {
		return -138;
	}
	if (state == 200 && window.at(0) == Tokens::ID::id) {
		return 211;
	}
	if (state == 200 && window.at(0) == Tokens::NUMBER::id) {
		return 212;
	}
	if (state == 200 && window.at(0) == Tokens::PY_RAW::id) {
		return 89;
	}
	if (state == 201 && window.at(0) == Tokens::AMPERSAND::id) {
		return -100;
	}
	if (state == 201 && window.at(0) == Tokens::AUTO::id) {
		return -100;
	}
	if (state == 201 && window.at(0) == Tokens::COMMERCIAL_AT::id) {
		return -100;
	}
	if (state == 201 && window.at(0) == Tokens::ID::id) {
		return -100;
	}
	if (state == 201 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -100;
	}
	if (state == 201 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -100;
	}
	if (state == 201 && window.at(0) == Tokens::PERCENT_SIGN::id) {
		return -100;
	}
	if (state == 201 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -100;
	}
	if (state == 201 && window.at(0) == Tokens::SEMICOLON::id) {
		return -100;
	}
	if (state == 201 && window.at(0) == Tokens::rule::nested_rule::NUMBER_SIGN::id) {
		return -100;
	}
	if (state == 201 && window.at(0) == Tokens::rule::value::ANY::id) {
		return -100;
	}
	if (state == 201 && window.at(0) == Tokens::rule::value::CGROUP::id) {
		return -100;
	}
	if (state == 201 && window.at(0) == Tokens::rule::value::NOSPACE::id) {
		return -100;
	}
	if (state == 201 && window.at(0) == Tokens::rule::value::SPACE::id) {
		return -100;
	}
	if (state == 201 && window.at(0) == Tokens::rule::value::STRING::id) {
		return -100;
	}
	if (state == 201 && window.at(0) == Tokens::rule::value::dyn::DOLLAR_SIGN::id) {
		return -100;
	}
	if (state == 201 && window.at(0) == Tokens::rule::value::shared_counter_registration::AUTO::id) {
		return -100;
	}
	if (state == 202 && window.at(0) == Tokens::AMPERSAND::id) {
		return -102;
	}
	if (state == 202 && window.at(0) == Tokens::AUTO::id) {
		return -102;
	}
	if (state == 202 && window.at(0) == Tokens::COMMERCIAL_AT::id) {
		return -102;
	}
	if (state == 202 && window.at(0) == Tokens::ID::id) {
		return -102;
	}
	if (state == 202 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -102;
	}
	if (state == 202 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -102;
	}
	if (state == 202 && window.at(0) == Tokens::PERCENT_SIGN::id) {
		return -102;
	}
	if (state == 202 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -102;
	}
	if (state == 202 && window.at(0) == Tokens::SEMICOLON::id) {
		return -102;
	}
	if (state == 202 && window.at(0) == Tokens::rule::nested_rule::NUMBER_SIGN::id) {
		return -102;
	}
	if (state == 202 && window.at(0) == Tokens::rule::value::ANY::id) {
		return -102;
	}
	if (state == 202 && window.at(0) == Tokens::rule::value::CGROUP::id) {
		return -102;
	}
	if (state == 202 && window.at(0) == Tokens::rule::value::NOSPACE::id) {
		return -102;
	}
	if (state == 202 && window.at(0) == Tokens::rule::value::SPACE::id) {
		return -102;
	}
	if (state == 202 && window.at(0) == Tokens::rule::value::STRING::id) {
		return -102;
	}
	if (state == 202 && window.at(0) == Tokens::rule::value::dyn::DOLLAR_SIGN::id) {
		return -102;
	}
	if (state == 202 && window.at(0) == Tokens::rule::value::shared_counter_registration::AUTO::id) {
		return -102;
	}
	if (state == 203 && window.at(0) == Tokens::AMPERSAND::id) {
		return -124;
	}
	if (state == 203 && window.at(0) == Tokens::AUTO::id) {
		return -124;
	}
	if (state == 203 && window.at(0) == Tokens::COMMERCIAL_AT::id) {
		return -124;
	}
	if (state == 203 && window.at(0) == Tokens::ID::id) {
		return -124;
	}
	if (state == 203 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -124;
	}
	if (state == 203 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -124;
	}
	if (state == 203 && window.at(0) == Tokens::PERCENT_SIGN::id) {
		return -124;
	}
	if (state == 203 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -124;
	}
	if (state == 203 && window.at(0) == Tokens::SEMICOLON::id) {
		return -124;
	}
	if (state == 203 && window.at(0) == Tokens::rule::nested_rule::NUMBER_SIGN::id) {
		return -124;
	}
	if (state == 203 && window.at(0) == Tokens::rule::value::ANY::id) {
		return -124;
	}
	if (state == 203 && window.at(0) == Tokens::rule::value::CGROUP::id) {
		return -124;
	}
	if (state == 203 && window.at(0) == Tokens::rule::value::NOSPACE::id) {
		return -124;
	}
	if (state == 203 && window.at(0) == Tokens::rule::value::SPACE::id) {
		return -124;
	}
	if (state == 203 && window.at(0) == Tokens::rule::value::STRING::id) {
		return -124;
	}
	if (state == 203 && window.at(0) == Tokens::rule::value::dyn::DOLLAR_SIGN::id) {
		return -124;
	}
	if (state == 204 && window.at(0) == Tokens::AMPERSAND::id) {
		return -130;
	}
	if (state == 204 && window.at(0) == Tokens::AUTO::id) {
		return -130;
	}
	if (state == 204 && window.at(0) == Tokens::COMMERCIAL_AT::id) {
		return -130;
	}
	if (state == 204 && window.at(0) == Tokens::ID::id) {
		return -130;
	}
	if (state == 204 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -130;
	}
	if (state == 204 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -130;
	}
	if (state == 204 && window.at(0) == Tokens::PERCENT_SIGN::id) {
		return -130;
	}
	if (state == 204 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -130;
	}
	if (state == 204 && window.at(0) == Tokens::SEMICOLON::id) {
		return -130;
	}
	if (state == 204 && window.at(0) == Tokens::rule::nested_rule::NUMBER_SIGN::id) {
		return -130;
	}
	if (state == 204 && window.at(0) == Tokens::rule::value::ANY::id) {
		return -130;
	}
	if (state == 204 && window.at(0) == Tokens::rule::value::CGROUP::id) {
		return -130;
	}
	if (state == 204 && window.at(0) == Tokens::rule::value::NOSPACE::id) {
		return -130;
	}
	if (state == 204 && window.at(0) == Tokens::rule::value::SPACE::id) {
		return -130;
	}
	if (state == 204 && window.at(0) == Tokens::rule::value::STRING::id) {
		return -130;
	}
	if (state == 204 && window.at(0) == Tokens::rule::value::dyn::DOLLAR_SIGN::id) {
		return -130;
	}
	if (state == 205 && window.at(0) == Tokens::ID::id) {
		return 215;
	}
	if (state == 206 && window.at(0) == Tokens::PY_RAW::id) {
		return -23;
	}
	if (state == 206 && window.at(0) == Tokens::RIGHT_CURLY_BRACKET::id) {
		return -23;
	}
	if (state == 206 && window.at(0) == Tokens::advanced_rule::regular_match::MATCH::id) {
		return -23;
	}
	if (state == 207 && window.at(0) == Tokens::COMMA::id) {
		return 194;
	}
	if (state == 207 && window.at(0) == Tokens::RIGHT_CURLY_BRACKET::id) {
		return -78;
	}
	if (state == 208 && window.at(0) == Tokens::ID::id) {
		return 217;
	}
	if (state == 209 && window.at(0) == Tokens::RIGHT_CURLY_BRACKET::id) {
		return -90;
	}
	if (state == 210 && window.at(0) == Tokens::AMPERSAND::id) {
		return -105;
	}
	if (state == 210 && window.at(0) == Tokens::AUTO::id) {
		return -105;
	}
	if (state == 210 && window.at(0) == Tokens::COMMERCIAL_AT::id) {
		return -105;
	}
	if (state == 210 && window.at(0) == Tokens::ID::id) {
		return -105;
	}
	if (state == 210 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -105;
	}
	if (state == 210 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -105;
	}
	if (state == 210 && window.at(0) == Tokens::PERCENT_SIGN::id) {
		return -105;
	}
	if (state == 210 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -105;
	}
	if (state == 210 && window.at(0) == Tokens::SEMICOLON::id) {
		return -105;
	}
	if (state == 210 && window.at(0) == Tokens::rule::nested_rule::NUMBER_SIGN::id) {
		return -105;
	}
	if (state == 210 && window.at(0) == Tokens::rule::value::ANY::id) {
		return -105;
	}
	if (state == 210 && window.at(0) == Tokens::rule::value::CGROUP::id) {
		return -105;
	}
	if (state == 210 && window.at(0) == Tokens::rule::value::NOSPACE::id) {
		return -105;
	}
	if (state == 210 && window.at(0) == Tokens::rule::value::SPACE::id) {
		return -105;
	}
	if (state == 210 && window.at(0) == Tokens::rule::value::STRING::id) {
		return -105;
	}
	if (state == 210 && window.at(0) == Tokens::rule::value::dyn::DOLLAR_SIGN::id) {
		return -105;
	}
	if (state == 210 && window.at(0) == Tokens::rule::value::shared_counter_registration::AUTO::id) {
		return -105;
	}
	if (state == 211 && window.at(0) == Tokens::AMPERSAND::id) {
		return -104;
	}
	if (state == 211 && window.at(0) == Tokens::AUTO::id) {
		return -104;
	}
	if (state == 211 && window.at(0) == Tokens::COMMERCIAL_AT::id) {
		return -104;
	}
	if (state == 211 && window.at(0) == Tokens::ID::id) {
		return -104;
	}
	if (state == 211 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -104;
	}
	if (state == 211 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -104;
	}
	if (state == 211 && window.at(0) == Tokens::PERCENT_SIGN::id) {
		return -104;
	}
	if (state == 211 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -104;
	}
	if (state == 211 && window.at(0) == Tokens::SEMICOLON::id) {
		return -104;
	}
	if (state == 211 && window.at(0) == Tokens::rule::nested_rule::NUMBER_SIGN::id) {
		return -104;
	}
	if (state == 211 && window.at(0) == Tokens::rule::value::ANY::id) {
		return -104;
	}
	if (state == 211 && window.at(0) == Tokens::rule::value::CGROUP::id) {
		return -104;
	}
	if (state == 211 && window.at(0) == Tokens::rule::value::NOSPACE::id) {
		return -104;
	}
	if (state == 211 && window.at(0) == Tokens::rule::value::SPACE::id) {
		return -104;
	}
	if (state == 211 && window.at(0) == Tokens::rule::value::STRING::id) {
		return -104;
	}
	if (state == 211 && window.at(0) == Tokens::rule::value::dyn::DOLLAR_SIGN::id) {
		return -104;
	}
	if (state == 211 && window.at(0) == Tokens::rule::value::shared_counter_registration::AUTO::id) {
		return -104;
	}
	if (state == 212 && window.at(0) == Tokens::AMPERSAND::id) {
		return -106;
	}
	if (state == 212 && window.at(0) == Tokens::AUTO::id) {
		return -106;
	}
	if (state == 212 && window.at(0) == Tokens::COMMERCIAL_AT::id) {
		return -106;
	}
	if (state == 212 && window.at(0) == Tokens::ID::id) {
		return -106;
	}
	if (state == 212 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -106;
	}
	if (state == 212 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -106;
	}
	if (state == 212 && window.at(0) == Tokens::PERCENT_SIGN::id) {
		return -106;
	}
	if (state == 212 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -106;
	}
	if (state == 212 && window.at(0) == Tokens::SEMICOLON::id) {
		return -106;
	}
	if (state == 212 && window.at(0) == Tokens::rule::nested_rule::NUMBER_SIGN::id) {
		return -106;
	}
	if (state == 212 && window.at(0) == Tokens::rule::value::ANY::id) {
		return -106;
	}
	if (state == 212 && window.at(0) == Tokens::rule::value::CGROUP::id) {
		return -106;
	}
	if (state == 212 && window.at(0) == Tokens::rule::value::NOSPACE::id) {
		return -106;
	}
	if (state == 212 && window.at(0) == Tokens::rule::value::SPACE::id) {
		return -106;
	}
	if (state == 212 && window.at(0) == Tokens::rule::value::STRING::id) {
		return -106;
	}
	if (state == 212 && window.at(0) == Tokens::rule::value::dyn::DOLLAR_SIGN::id) {
		return -106;
	}
	if (state == 212 && window.at(0) == Tokens::rule::value::shared_counter_registration::AUTO::id) {
		return -106;
	}
	if (state == 213 && window.at(0) == Tokens::AMPERSAND::id) {
		return -103;
	}
	if (state == 213 && window.at(0) == Tokens::AUTO::id) {
		return -103;
	}
	if (state == 213 && window.at(0) == Tokens::COMMERCIAL_AT::id) {
		return -103;
	}
	if (state == 213 && window.at(0) == Tokens::ID::id) {
		return -103;
	}
	if (state == 213 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -103;
	}
	if (state == 213 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -103;
	}
	if (state == 213 && window.at(0) == Tokens::PERCENT_SIGN::id) {
		return -103;
	}
	if (state == 213 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -103;
	}
	if (state == 213 && window.at(0) == Tokens::SEMICOLON::id) {
		return -103;
	}
	if (state == 213 && window.at(0) == Tokens::rule::nested_rule::NUMBER_SIGN::id) {
		return -103;
	}
	if (state == 213 && window.at(0) == Tokens::rule::value::ANY::id) {
		return -103;
	}
	if (state == 213 && window.at(0) == Tokens::rule::value::CGROUP::id) {
		return -103;
	}
	if (state == 213 && window.at(0) == Tokens::rule::value::NOSPACE::id) {
		return -103;
	}
	if (state == 213 && window.at(0) == Tokens::rule::value::SPACE::id) {
		return -103;
	}
	if (state == 213 && window.at(0) == Tokens::rule::value::STRING::id) {
		return -103;
	}
	if (state == 213 && window.at(0) == Tokens::rule::value::dyn::DOLLAR_SIGN::id) {
		return -103;
	}
	if (state == 213 && window.at(0) == Tokens::rule::value::shared_counter_registration::AUTO::id) {
		return -103;
	}
	if (state == 214 && window.at(0) == Tokens::AMPERSAND::id) {
		return -147;
	}
	if (state == 214 && window.at(0) == Tokens::AUTO::id) {
		return -147;
	}
	if (state == 214 && window.at(0) == Tokens::COMMERCIAL_AT::id) {
		return -147;
	}
	if (state == 214 && window.at(0) == Tokens::ID::id) {
		return -147;
	}
	if (state == 214 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -147;
	}
	if (state == 214 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -147;
	}
	if (state == 214 && window.at(0) == Tokens::PERCENT_SIGN::id) {
		return -147;
	}
	if (state == 214 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -147;
	}
	if (state == 214 && window.at(0) == Tokens::SEMICOLON::id) {
		return -147;
	}
	if (state == 214 && window.at(0) == Tokens::rule::nested_rule::NUMBER_SIGN::id) {
		return -147;
	}
	if (state == 214 && window.at(0) == Tokens::rule::value::ANY::id) {
		return -147;
	}
	if (state == 214 && window.at(0) == Tokens::rule::value::CGROUP::id) {
		return -147;
	}
	if (state == 214 && window.at(0) == Tokens::rule::value::NOSPACE::id) {
		return -147;
	}
	if (state == 214 && window.at(0) == Tokens::rule::value::SPACE::id) {
		return -147;
	}
	if (state == 214 && window.at(0) == Tokens::rule::value::STRING::id) {
		return -147;
	}
	if (state == 214 && window.at(0) == Tokens::rule::value::dyn::DOLLAR_SIGN::id) {
		return -147;
	}
	if (state == 215 && window.at(0) == Tokens::RIGHT_CURLY_BRACKET::id) {
		return -79;
	}
	if (state == 216 && window.at(0) == Tokens::COMMA::id) {
		return 209;
	}
	if (state == 216 && window.at(0) == Tokens::RIGHT_CURLY_BRACKET::id) {
		return -91;
	}
	if (state == 217 && window.at(0) == Tokens::RIGHT_CURLY_BRACKET::id) {
		return -92;
	}
	if (state == 10 && window.at(0) == Tokens::AUTO::id) {
		return 9223372036854775807;
	}
	if (state == 22 && window.at(0) == Tokens::COMMERCIAL_AT::id && window.at(1) == Tokens::EQUALS_SIGN::id) {
		return 36;
	}
	if (state == 22 && window.at(0) == Tokens::COMMERCIAL_AT::id && window.at(1) == Tokens::ID::id) {
		return -125;
	}
	if (state == 22 && window.at(0) == Tokens::COMMERCIAL_AT::id && window.at(1) == Tokens::LEFT_PARENTHESIS::id) {
		return -125;
	}
	if (state == 22 && window.at(0) == Tokens::COMMERCIAL_AT::id && window.at(1) == Tokens::PERCENT_SIGN::id) {
		return -125;
	}
	if (state == 22 && window.at(0) == Tokens::COMMERCIAL_AT::id && window.at(1) == Tokens::rule::value::ANY::id) {
		return -125;
	}
	if (state == 22 && window.at(0) == Tokens::COMMERCIAL_AT::id && window.at(1) == Tokens::rule::value::CGROUP::id) {
		return -125;
	}
	if (state == 22 && window.at(0) == Tokens::COMMERCIAL_AT::id && window.at(1) == Tokens::rule::value::NOSPACE::id) {
		return -125;
	}
	if (state == 22 && window.at(0) == Tokens::COMMERCIAL_AT::id && window.at(1) == Tokens::rule::value::SPACE::id) {
		return -125;
	}
	if (state == 22 && window.at(0) == Tokens::COMMERCIAL_AT::id && window.at(1) == Tokens::rule::value::STRING::id) {
		return -125;
	}
	if (state == 22 && window.at(0) == Tokens::COMMERCIAL_AT::id && window.at(1) == Tokens::rule::value::dyn::DOLLAR_SIGN::id) {
		return -125;
	}
	if (state == 22 && window.at(0) == Tokens::PERCENT_SIGN::id && window.at(1) == Tokens::EQUALS_SIGN::id) {
		return 37;
	}
	if (state == 22 && window.at(0) == Tokens::PERCENT_SIGN::id && window.at(1) == Tokens::ID::id) {
		return -125;
	}
	if (state == 22 && window.at(0) == Tokens::PERCENT_SIGN::id && window.at(1) == Tokens::LEFT_PARENTHESIS::id) {
		return -125;
	}
	if (state == 22 && window.at(0) == Tokens::PERCENT_SIGN::id && window.at(1) == Tokens::rule::value::ANY::id) {
		return -125;
	}
	if (state == 22 && window.at(0) == Tokens::PERCENT_SIGN::id && window.at(1) == Tokens::rule::value::CGROUP::id) {
		return -125;
	}
	if (state == 22 && window.at(0) == Tokens::PERCENT_SIGN::id && window.at(1) == Tokens::rule::value::NOSPACE::id) {
		return -125;
	}
	if (state == 22 && window.at(0) == Tokens::PERCENT_SIGN::id && window.at(1) == Tokens::rule::value::SPACE::id) {
		return -125;
	}
	if (state == 22 && window.at(0) == Tokens::PERCENT_SIGN::id && window.at(1) == Tokens::rule::value::STRING::id) {
		return -125;
	}
	if (state == 22 && window.at(0) == Tokens::PERCENT_SIGN::id && window.at(1) == Tokens::rule::value::dyn::DOLLAR_SIGN::id) {
		return -125;
	}
	if (state == 30 && window.at(0) == Tokens::AUTO::id) {
		return 9223372036854775807;
	}
	if (state == 31 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return 9223372036854775807;
	}
	if (state == 38 && window.at(0) == Tokens::AMPERSAND::id && window.at(1) == Tokens::ID::id) {
		return 35;
	}
	if (state == 38 && window.at(0) == Tokens::AMPERSAND::id && window.at(1) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -62;
	}
	if (state == 38 && window.at(0) == Tokens::COMMERCIAL_AT::id && window.at(1) == Tokens::EQUALS_SIGN::id) {
		return 36;
	}
	if (state == 38 && window.at(0) == Tokens::COMMERCIAL_AT::id && window.at(1) == Tokens::ID::id) {
		return -125;
	}
	if (state == 38 && window.at(0) == Tokens::COMMERCIAL_AT::id && window.at(1) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -62;
	}
	if (state == 38 && window.at(0) == Tokens::COMMERCIAL_AT::id && window.at(1) == Tokens::LEFT_PARENTHESIS::id) {
		return -125;
	}
	if (state == 38 && window.at(0) == Tokens::COMMERCIAL_AT::id && window.at(1) == Tokens::PERCENT_SIGN::id) {
		return -125;
	}
	if (state == 38 && window.at(0) == Tokens::COMMERCIAL_AT::id && window.at(1) == Tokens::rule::value::ANY::id) {
		return -125;
	}
	if (state == 38 && window.at(0) == Tokens::COMMERCIAL_AT::id && window.at(1) == Tokens::rule::value::CGROUP::id) {
		return -125;
	}
	if (state == 38 && window.at(0) == Tokens::COMMERCIAL_AT::id && window.at(1) == Tokens::rule::value::NOSPACE::id) {
		return -125;
	}
	if (state == 38 && window.at(0) == Tokens::COMMERCIAL_AT::id && window.at(1) == Tokens::rule::value::SPACE::id) {
		return -125;
	}
	if (state == 38 && window.at(0) == Tokens::COMMERCIAL_AT::id && window.at(1) == Tokens::rule::value::STRING::id) {
		return -125;
	}
	if (state == 38 && window.at(0) == Tokens::COMMERCIAL_AT::id && window.at(1) == Tokens::rule::value::dyn::DOLLAR_SIGN::id) {
		return -125;
	}
	if (state == 38 && window.at(0) == Tokens::PERCENT_SIGN::id && window.at(1) == Tokens::EQUALS_SIGN::id) {
		return 37;
	}
	if (state == 38 && window.at(0) == Tokens::PERCENT_SIGN::id && window.at(1) == Tokens::ID::id) {
		return -125;
	}
	if (state == 38 && window.at(0) == Tokens::PERCENT_SIGN::id && window.at(1) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -62;
	}
	if (state == 38 && window.at(0) == Tokens::PERCENT_SIGN::id && window.at(1) == Tokens::LEFT_PARENTHESIS::id) {
		return -125;
	}
	if (state == 38 && window.at(0) == Tokens::PERCENT_SIGN::id && window.at(1) == Tokens::rule::value::ANY::id) {
		return -125;
	}
	if (state == 38 && window.at(0) == Tokens::PERCENT_SIGN::id && window.at(1) == Tokens::rule::value::CGROUP::id) {
		return -125;
	}
	if (state == 38 && window.at(0) == Tokens::PERCENT_SIGN::id && window.at(1) == Tokens::rule::value::NOSPACE::id) {
		return -125;
	}
	if (state == 38 && window.at(0) == Tokens::PERCENT_SIGN::id && window.at(1) == Tokens::rule::value::SPACE::id) {
		return -125;
	}
	if (state == 38 && window.at(0) == Tokens::PERCENT_SIGN::id && window.at(1) == Tokens::rule::value::STRING::id) {
		return -125;
	}
	if (state == 38 && window.at(0) == Tokens::PERCENT_SIGN::id && window.at(1) == Tokens::rule::value::dyn::DOLLAR_SIGN::id) {
		return -125;
	}
	if (state == 65 && window.at(0) == Tokens::AMPERSAND::id && window.at(1) == Tokens::ID::id) {
		return 35;
	}
	if (state == 65 && window.at(0) == Tokens::AMPERSAND::id && window.at(1) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -62;
	}
	if (state == 65 && window.at(0) == Tokens::COMMERCIAL_AT::id && window.at(1) == Tokens::EQUALS_SIGN::id) {
		return 36;
	}
	if (state == 65 && window.at(0) == Tokens::COMMERCIAL_AT::id && window.at(1) == Tokens::ID::id) {
		return -125;
	}
	if (state == 65 && window.at(0) == Tokens::COMMERCIAL_AT::id && window.at(1) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -62;
	}
	if (state == 65 && window.at(0) == Tokens::COMMERCIAL_AT::id && window.at(1) == Tokens::LEFT_PARENTHESIS::id) {
		return -125;
	}
	if (state == 65 && window.at(0) == Tokens::COMMERCIAL_AT::id && window.at(1) == Tokens::PERCENT_SIGN::id) {
		return -125;
	}
	if (state == 65 && window.at(0) == Tokens::COMMERCIAL_AT::id && window.at(1) == Tokens::rule::value::ANY::id) {
		return -125;
	}
	if (state == 65 && window.at(0) == Tokens::COMMERCIAL_AT::id && window.at(1) == Tokens::rule::value::CGROUP::id) {
		return -125;
	}
	if (state == 65 && window.at(0) == Tokens::COMMERCIAL_AT::id && window.at(1) == Tokens::rule::value::NOSPACE::id) {
		return -125;
	}
	if (state == 65 && window.at(0) == Tokens::COMMERCIAL_AT::id && window.at(1) == Tokens::rule::value::SPACE::id) {
		return -125;
	}
	if (state == 65 && window.at(0) == Tokens::COMMERCIAL_AT::id && window.at(1) == Tokens::rule::value::STRING::id) {
		return -125;
	}
	if (state == 65 && window.at(0) == Tokens::COMMERCIAL_AT::id && window.at(1) == Tokens::rule::value::dyn::DOLLAR_SIGN::id) {
		return -125;
	}
	if (state == 65 && window.at(0) == Tokens::PERCENT_SIGN::id && window.at(1) == Tokens::EQUALS_SIGN::id) {
		return 37;
	}
	if (state == 65 && window.at(0) == Tokens::PERCENT_SIGN::id && window.at(1) == Tokens::ID::id) {
		return -125;
	}
	if (state == 65 && window.at(0) == Tokens::PERCENT_SIGN::id && window.at(1) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -62;
	}
	if (state == 65 && window.at(0) == Tokens::PERCENT_SIGN::id && window.at(1) == Tokens::LEFT_PARENTHESIS::id) {
		return -125;
	}
	if (state == 65 && window.at(0) == Tokens::PERCENT_SIGN::id && window.at(1) == Tokens::rule::value::ANY::id) {
		return -125;
	}
	if (state == 65 && window.at(0) == Tokens::PERCENT_SIGN::id && window.at(1) == Tokens::rule::value::CGROUP::id) {
		return -125;
	}
	if (state == 65 && window.at(0) == Tokens::PERCENT_SIGN::id && window.at(1) == Tokens::rule::value::NOSPACE::id) {
		return -125;
	}
	if (state == 65 && window.at(0) == Tokens::PERCENT_SIGN::id && window.at(1) == Tokens::rule::value::SPACE::id) {
		return -125;
	}
	if (state == 65 && window.at(0) == Tokens::PERCENT_SIGN::id && window.at(1) == Tokens::rule::value::STRING::id) {
		return -125;
	}
	if (state == 65 && window.at(0) == Tokens::PERCENT_SIGN::id && window.at(1) == Tokens::rule::value::dyn::DOLLAR_SIGN::id) {
		return -125;
	}
	if (state == 67 && window.at(0) == Tokens::ID::id) {
		return 9223372036854775807;
	}
	if (state == 73 && window.at(0) == Tokens::COMMERCIAL_AT::id && window.at(1) == Tokens::EQUALS_SIGN::id) {
		return 36;
	}
	if (state == 73 && window.at(0) == Tokens::COMMERCIAL_AT::id && window.at(1) == Tokens::ID::id) {
		return -125;
	}
	if (state == 73 && window.at(0) == Tokens::COMMERCIAL_AT::id && window.at(1) == Tokens::LEFT_PARENTHESIS::id) {
		return -125;
	}
	if (state == 73 && window.at(0) == Tokens::COMMERCIAL_AT::id && window.at(1) == Tokens::PERCENT_SIGN::id) {
		return -125;
	}
	if (state == 73 && window.at(0) == Tokens::COMMERCIAL_AT::id && window.at(1) == Tokens::rule::value::ANY::id) {
		return -125;
	}
	if (state == 73 && window.at(0) == Tokens::COMMERCIAL_AT::id && window.at(1) == Tokens::rule::value::CGROUP::id) {
		return -125;
	}
	if (state == 73 && window.at(0) == Tokens::COMMERCIAL_AT::id && window.at(1) == Tokens::rule::value::NOSPACE::id) {
		return -125;
	}
	if (state == 73 && window.at(0) == Tokens::COMMERCIAL_AT::id && window.at(1) == Tokens::rule::value::SPACE::id) {
		return -125;
	}
	if (state == 73 && window.at(0) == Tokens::COMMERCIAL_AT::id && window.at(1) == Tokens::rule::value::STRING::id) {
		return -125;
	}
	if (state == 73 && window.at(0) == Tokens::COMMERCIAL_AT::id && window.at(1) == Tokens::rule::value::dyn::DOLLAR_SIGN::id) {
		return -125;
	}
	if (state == 73 && window.at(0) == Tokens::PERCENT_SIGN::id && window.at(1) == Tokens::EQUALS_SIGN::id) {
		return 37;
	}
	if (state == 73 && window.at(0) == Tokens::PERCENT_SIGN::id && window.at(1) == Tokens::ID::id) {
		return -125;
	}
	if (state == 73 && window.at(0) == Tokens::PERCENT_SIGN::id && window.at(1) == Tokens::LEFT_PARENTHESIS::id) {
		return -125;
	}
	if (state == 73 && window.at(0) == Tokens::PERCENT_SIGN::id && window.at(1) == Tokens::rule::value::ANY::id) {
		return -125;
	}
	if (state == 73 && window.at(0) == Tokens::PERCENT_SIGN::id && window.at(1) == Tokens::rule::value::CGROUP::id) {
		return -125;
	}
	if (state == 73 && window.at(0) == Tokens::PERCENT_SIGN::id && window.at(1) == Tokens::rule::value::NOSPACE::id) {
		return -125;
	}
	if (state == 73 && window.at(0) == Tokens::PERCENT_SIGN::id && window.at(1) == Tokens::rule::value::SPACE::id) {
		return -125;
	}
	if (state == 73 && window.at(0) == Tokens::PERCENT_SIGN::id && window.at(1) == Tokens::rule::value::STRING::id) {
		return -125;
	}
	if (state == 73 && window.at(0) == Tokens::PERCENT_SIGN::id && window.at(1) == Tokens::rule::value::dyn::DOLLAR_SIGN::id) {
		return -125;
	}
	if (state == 79 && window.at(0) == Tokens::AUTO::id) {
		return 9223372036854775807;
	}
	if (state == 98 && window.at(0) == Tokens::ID::id) {
		return 9223372036854775807;
	}
	if (state == 105 && window.at(0) == Tokens::COMMERCIAL_AT::id && window.at(1) == Tokens::EQUALS_SIGN::id) {
		return 36;
	}
	if (state == 105 && window.at(0) == Tokens::COMMERCIAL_AT::id && window.at(1) == Tokens::ID::id) {
		return -125;
	}
	if (state == 105 && window.at(0) == Tokens::COMMERCIAL_AT::id && window.at(1) == Tokens::LEFT_PARENTHESIS::id) {
		return -125;
	}
	if (state == 105 && window.at(0) == Tokens::COMMERCIAL_AT::id && window.at(1) == Tokens::PERCENT_SIGN::id) {
		return -125;
	}
	if (state == 105 && window.at(0) == Tokens::COMMERCIAL_AT::id && window.at(1) == Tokens::rule::value::ANY::id) {
		return -125;
	}
	if (state == 105 && window.at(0) == Tokens::COMMERCIAL_AT::id && window.at(1) == Tokens::rule::value::CGROUP::id) {
		return -125;
	}
	if (state == 105 && window.at(0) == Tokens::COMMERCIAL_AT::id && window.at(1) == Tokens::rule::value::NOSPACE::id) {
		return -125;
	}
	if (state == 105 && window.at(0) == Tokens::COMMERCIAL_AT::id && window.at(1) == Tokens::rule::value::SPACE::id) {
		return -125;
	}
	if (state == 105 && window.at(0) == Tokens::COMMERCIAL_AT::id && window.at(1) == Tokens::rule::value::STRING::id) {
		return -125;
	}
	if (state == 105 && window.at(0) == Tokens::COMMERCIAL_AT::id && window.at(1) == Tokens::rule::value::dyn::DOLLAR_SIGN::id) {
		return -125;
	}
	if (state == 105 && window.at(0) == Tokens::PERCENT_SIGN::id && window.at(1) == Tokens::EQUALS_SIGN::id) {
		return 37;
	}
	if (state == 105 && window.at(0) == Tokens::PERCENT_SIGN::id && window.at(1) == Tokens::ID::id) {
		return -125;
	}
	if (state == 105 && window.at(0) == Tokens::PERCENT_SIGN::id && window.at(1) == Tokens::LEFT_PARENTHESIS::id) {
		return -125;
	}
	if (state == 105 && window.at(0) == Tokens::PERCENT_SIGN::id && window.at(1) == Tokens::rule::value::ANY::id) {
		return -125;
	}
	if (state == 105 && window.at(0) == Tokens::PERCENT_SIGN::id && window.at(1) == Tokens::rule::value::CGROUP::id) {
		return -125;
	}
	if (state == 105 && window.at(0) == Tokens::PERCENT_SIGN::id && window.at(1) == Tokens::rule::value::NOSPACE::id) {
		return -125;
	}
	if (state == 105 && window.at(0) == Tokens::PERCENT_SIGN::id && window.at(1) == Tokens::rule::value::SPACE::id) {
		return -125;
	}
	if (state == 105 && window.at(0) == Tokens::PERCENT_SIGN::id && window.at(1) == Tokens::rule::value::STRING::id) {
		return -125;
	}
	if (state == 105 && window.at(0) == Tokens::PERCENT_SIGN::id && window.at(1) == Tokens::rule::value::dyn::DOLLAR_SIGN::id) {
		return -125;
	}
	if (state == 124 && window.at(0) == Tokens::COMMERCIAL_AT::id && window.at(1) == Tokens::EQUALS_SIGN::id) {
		return 36;
	}
	if (state == 124 && window.at(0) == Tokens::COMMERCIAL_AT::id && window.at(1) == Tokens::ID::id) {
		return -125;
	}
	if (state == 124 && window.at(0) == Tokens::COMMERCIAL_AT::id && window.at(1) == Tokens::LEFT_PARENTHESIS::id) {
		return -125;
	}
	if (state == 124 && window.at(0) == Tokens::COMMERCIAL_AT::id && window.at(1) == Tokens::PERCENT_SIGN::id) {
		return -125;
	}
	if (state == 124 && window.at(0) == Tokens::COMMERCIAL_AT::id && window.at(1) == Tokens::rule::value::ANY::id) {
		return -125;
	}
	if (state == 124 && window.at(0) == Tokens::COMMERCIAL_AT::id && window.at(1) == Tokens::rule::value::CGROUP::id) {
		return -125;
	}
	if (state == 124 && window.at(0) == Tokens::COMMERCIAL_AT::id && window.at(1) == Tokens::rule::value::NOSPACE::id) {
		return -125;
	}
	if (state == 124 && window.at(0) == Tokens::COMMERCIAL_AT::id && window.at(1) == Tokens::rule::value::SPACE::id) {
		return -125;
	}
	if (state == 124 && window.at(0) == Tokens::COMMERCIAL_AT::id && window.at(1) == Tokens::rule::value::STRING::id) {
		return -125;
	}
	if (state == 124 && window.at(0) == Tokens::COMMERCIAL_AT::id && window.at(1) == Tokens::rule::value::dyn::DOLLAR_SIGN::id) {
		return -125;
	}
	if (state == 124 && window.at(0) == Tokens::PERCENT_SIGN::id && window.at(1) == Tokens::EQUALS_SIGN::id) {
		return 37;
	}
	if (state == 124 && window.at(0) == Tokens::PERCENT_SIGN::id && window.at(1) == Tokens::ID::id) {
		return -125;
	}
	if (state == 124 && window.at(0) == Tokens::PERCENT_SIGN::id && window.at(1) == Tokens::LEFT_PARENTHESIS::id) {
		return -125;
	}
	if (state == 124 && window.at(0) == Tokens::PERCENT_SIGN::id && window.at(1) == Tokens::rule::value::ANY::id) {
		return -125;
	}
	if (state == 124 && window.at(0) == Tokens::PERCENT_SIGN::id && window.at(1) == Tokens::rule::value::CGROUP::id) {
		return -125;
	}
	if (state == 124 && window.at(0) == Tokens::PERCENT_SIGN::id && window.at(1) == Tokens::rule::value::NOSPACE::id) {
		return -125;
	}
	if (state == 124 && window.at(0) == Tokens::PERCENT_SIGN::id && window.at(1) == Tokens::rule::value::SPACE::id) {
		return -125;
	}
	if (state == 124 && window.at(0) == Tokens::PERCENT_SIGN::id && window.at(1) == Tokens::rule::value::STRING::id) {
		return -125;
	}
	if (state == 124 && window.at(0) == Tokens::PERCENT_SIGN::id && window.at(1) == Tokens::rule::value::dyn::DOLLAR_SIGN::id) {
		return -125;
	}
	if (state == 141 && window.at(0) == Tokens::COMMERCIAL_AT::id && window.at(1) == Tokens::EQUALS_SIGN::id) {
		return 36;
	}
	if (state == 141 && window.at(0) == Tokens::COMMERCIAL_AT::id && window.at(1) == Tokens::ID::id) {
		return -125;
	}
	if (state == 141 && window.at(0) == Tokens::COMMERCIAL_AT::id && window.at(1) == Tokens::LEFT_PARENTHESIS::id) {
		return -125;
	}
	if (state == 141 && window.at(0) == Tokens::COMMERCIAL_AT::id && window.at(1) == Tokens::PERCENT_SIGN::id) {
		return -125;
	}
	if (state == 141 && window.at(0) == Tokens::COMMERCIAL_AT::id && window.at(1) == Tokens::rule::value::ANY::id) {
		return -125;
	}
	if (state == 141 && window.at(0) == Tokens::COMMERCIAL_AT::id && window.at(1) == Tokens::rule::value::CGROUP::id) {
		return -125;
	}
	if (state == 141 && window.at(0) == Tokens::COMMERCIAL_AT::id && window.at(1) == Tokens::rule::value::NOSPACE::id) {
		return -125;
	}
	if (state == 141 && window.at(0) == Tokens::COMMERCIAL_AT::id && window.at(1) == Tokens::rule::value::SPACE::id) {
		return -125;
	}
	if (state == 141 && window.at(0) == Tokens::COMMERCIAL_AT::id && window.at(1) == Tokens::rule::value::STRING::id) {
		return -125;
	}
	if (state == 141 && window.at(0) == Tokens::COMMERCIAL_AT::id && window.at(1) == Tokens::rule::value::dyn::DOLLAR_SIGN::id) {
		return -125;
	}
	if (state == 141 && window.at(0) == Tokens::PERCENT_SIGN::id && window.at(1) == Tokens::EQUALS_SIGN::id) {
		return 37;
	}
	if (state == 141 && window.at(0) == Tokens::PERCENT_SIGN::id && window.at(1) == Tokens::ID::id) {
		return -125;
	}
	if (state == 141 && window.at(0) == Tokens::PERCENT_SIGN::id && window.at(1) == Tokens::LEFT_PARENTHESIS::id) {
		return -125;
	}
	if (state == 141 && window.at(0) == Tokens::PERCENT_SIGN::id && window.at(1) == Tokens::rule::value::ANY::id) {
		return -125;
	}
	if (state == 141 && window.at(0) == Tokens::PERCENT_SIGN::id && window.at(1) == Tokens::rule::value::CGROUP::id) {
		return -125;
	}
	if (state == 141 && window.at(0) == Tokens::PERCENT_SIGN::id && window.at(1) == Tokens::rule::value::NOSPACE::id) {
		return -125;
	}
	if (state == 141 && window.at(0) == Tokens::PERCENT_SIGN::id && window.at(1) == Tokens::rule::value::SPACE::id) {
		return -125;
	}
	if (state == 141 && window.at(0) == Tokens::PERCENT_SIGN::id && window.at(1) == Tokens::rule::value::STRING::id) {
		return -125;
	}
	if (state == 141 && window.at(0) == Tokens::PERCENT_SIGN::id && window.at(1) == Tokens::rule::value::dyn::DOLLAR_SIGN::id) {
		return -125;
	}
	if (state == 159 && window.at(0) == Tokens::COMMERCIAL_AT::id && window.at(1) == Tokens::EQUALS_SIGN::id) {
		return 36;
	}
	if (state == 159 && window.at(0) == Tokens::COMMERCIAL_AT::id && window.at(1) == Tokens::ID::id) {
		return -125;
	}
	if (state == 159 && window.at(0) == Tokens::COMMERCIAL_AT::id && window.at(1) == Tokens::LEFT_PARENTHESIS::id) {
		return -125;
	}
	if (state == 159 && window.at(0) == Tokens::COMMERCIAL_AT::id && window.at(1) == Tokens::PERCENT_SIGN::id) {
		return -125;
	}
	if (state == 159 && window.at(0) == Tokens::COMMERCIAL_AT::id && window.at(1) == Tokens::rule::value::ANY::id) {
		return -125;
	}
	if (state == 159 && window.at(0) == Tokens::COMMERCIAL_AT::id && window.at(1) == Tokens::rule::value::CGROUP::id) {
		return -125;
	}
	if (state == 159 && window.at(0) == Tokens::COMMERCIAL_AT::id && window.at(1) == Tokens::rule::value::NOSPACE::id) {
		return -125;
	}
	if (state == 159 && window.at(0) == Tokens::COMMERCIAL_AT::id && window.at(1) == Tokens::rule::value::SPACE::id) {
		return -125;
	}
	if (state == 159 && window.at(0) == Tokens::COMMERCIAL_AT::id && window.at(1) == Tokens::rule::value::STRING::id) {
		return -125;
	}
	if (state == 159 && window.at(0) == Tokens::COMMERCIAL_AT::id && window.at(1) == Tokens::rule::value::dyn::DOLLAR_SIGN::id) {
		return -125;
	}
	if (state == 159 && window.at(0) == Tokens::PERCENT_SIGN::id && window.at(1) == Tokens::EQUALS_SIGN::id) {
		return 37;
	}
	if (state == 159 && window.at(0) == Tokens::PERCENT_SIGN::id && window.at(1) == Tokens::ID::id) {
		return -125;
	}
	if (state == 159 && window.at(0) == Tokens::PERCENT_SIGN::id && window.at(1) == Tokens::LEFT_PARENTHESIS::id) {
		return -125;
	}
	if (state == 159 && window.at(0) == Tokens::PERCENT_SIGN::id && window.at(1) == Tokens::rule::value::ANY::id) {
		return -125;
	}
	if (state == 159 && window.at(0) == Tokens::PERCENT_SIGN::id && window.at(1) == Tokens::rule::value::CGROUP::id) {
		return -125;
	}
	if (state == 159 && window.at(0) == Tokens::PERCENT_SIGN::id && window.at(1) == Tokens::rule::value::NOSPACE::id) {
		return -125;
	}
	if (state == 159 && window.at(0) == Tokens::PERCENT_SIGN::id && window.at(1) == Tokens::rule::value::SPACE::id) {
		return -125;
	}
	if (state == 159 && window.at(0) == Tokens::PERCENT_SIGN::id && window.at(1) == Tokens::rule::value::STRING::id) {
		return -125;
	}
	if (state == 159 && window.at(0) == Tokens::PERCENT_SIGN::id && window.at(1) == Tokens::rule::value::dyn::DOLLAR_SIGN::id) {
		return -125;
	}
	if (state == 180 && window.at(0) == Tokens::COMMERCIAL_AT::id && window.at(1) == Tokens::EQUALS_SIGN::id) {
		return 36;
	}
	if (state == 180 && window.at(0) == Tokens::COMMERCIAL_AT::id && window.at(1) == Tokens::ID::id) {
		return -125;
	}
	if (state == 180 && window.at(0) == Tokens::COMMERCIAL_AT::id && window.at(1) == Tokens::LEFT_PARENTHESIS::id) {
		return -125;
	}
	if (state == 180 && window.at(0) == Tokens::COMMERCIAL_AT::id && window.at(1) == Tokens::PERCENT_SIGN::id) {
		return -125;
	}
	if (state == 180 && window.at(0) == Tokens::COMMERCIAL_AT::id && window.at(1) == Tokens::rule::value::ANY::id) {
		return -125;
	}
	if (state == 180 && window.at(0) == Tokens::COMMERCIAL_AT::id && window.at(1) == Tokens::rule::value::CGROUP::id) {
		return -125;
	}
	if (state == 180 && window.at(0) == Tokens::COMMERCIAL_AT::id && window.at(1) == Tokens::rule::value::NOSPACE::id) {
		return -125;
	}
	if (state == 180 && window.at(0) == Tokens::COMMERCIAL_AT::id && window.at(1) == Tokens::rule::value::SPACE::id) {
		return -125;
	}
	if (state == 180 && window.at(0) == Tokens::COMMERCIAL_AT::id && window.at(1) == Tokens::rule::value::STRING::id) {
		return -125;
	}
	if (state == 180 && window.at(0) == Tokens::COMMERCIAL_AT::id && window.at(1) == Tokens::rule::value::dyn::DOLLAR_SIGN::id) {
		return -125;
	}
	if (state == 180 && window.at(0) == Tokens::PERCENT_SIGN::id && window.at(1) == Tokens::EQUALS_SIGN::id) {
		return 37;
	}
	if (state == 180 && window.at(0) == Tokens::PERCENT_SIGN::id && window.at(1) == Tokens::ID::id) {
		return -125;
	}
	if (state == 180 && window.at(0) == Tokens::PERCENT_SIGN::id && window.at(1) == Tokens::LEFT_PARENTHESIS::id) {
		return -125;
	}
	if (state == 180 && window.at(0) == Tokens::PERCENT_SIGN::id && window.at(1) == Tokens::rule::value::ANY::id) {
		return -125;
	}
	if (state == 180 && window.at(0) == Tokens::PERCENT_SIGN::id && window.at(1) == Tokens::rule::value::CGROUP::id) {
		return -125;
	}
	if (state == 180 && window.at(0) == Tokens::PERCENT_SIGN::id && window.at(1) == Tokens::rule::value::NOSPACE::id) {
		return -125;
	}
	if (state == 180 && window.at(0) == Tokens::PERCENT_SIGN::id && window.at(1) == Tokens::rule::value::SPACE::id) {
		return -125;
	}
	if (state == 180 && window.at(0) == Tokens::PERCENT_SIGN::id && window.at(1) == Tokens::rule::value::STRING::id) {
		return -125;
	}
	if (state == 180 && window.at(0) == Tokens::PERCENT_SIGN::id && window.at(1) == Tokens::rule::value::dyn::DOLLAR_SIGN::id) {
		return -125;
	}
	return -9223372036854775807;
}
auto Parser::Parser::lr_conflict(std::size_t state, const std::vector<std::size_t>& window) -> std::vector<long long> {
	if (state == 10 && window.at(0) == Tokens::AUTO::id) {
		return {-44, 19};
	}
	if (state == 30 && window.at(0) == Tokens::AUTO::id) {
		return {-46, 48};
	}
	if (state == 31 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return {-50, 50};
	}
	if (state == 67 && window.at(0) == Tokens::ID::id) {
		return {-98, 97};
	}
	if (state == 79 && window.at(0) == Tokens::AUTO::id) {
		return {-46, 48};
	}
	if (state == 98 && window.at(0) == Tokens::ID::id) {
		return {11, -112};
	}
	return {};
}
auto Parser::Parser::lr_rule_label(std::size_t rule) -> std::string {
	if (rule == 0) {
		return "advanced_rule (production 0) at parser/ispa/grammar/adv_rule.isc";
	}
	if (rule == 1) {
		return "advanced_rule (production 1) at parser/ispa/grammar/adv_rule.isc";
	}
	if (rule == 2) {
		return "advanced_rule (production 2) at parser/ispa/grammar/adv_rule.isc";
	}
	if (rule == 3) {
		return "advanced_rule (production 3) at parser/ispa/grammar/adv_rule.isc";
	}
	if (rule == 4) {
		return "advanced_rule (production 4) at parser/ispa/grammar/adv_rule.isc";
	}
	if (rule == 5) {
		return "advanced_rule (production 5) at parser/ispa/grammar/adv_rule.isc";
	}
	if (rule == 6) {
		return "advanced_rule (production 6) at parser/ispa/grammar/adv_rule.isc";
	}
	if (rule == 7) {
		return "advanced_rule (production 7) at parser/ispa/grammar/adv_rule.isc";
	}
	if (rule == 8) {
		return "advanced_rule (production 8) at parser/ispa/grammar/adv_rule.isc";
	}
	if (rule == 9) {
		return "advanced_rule (production 9) at parser/ispa/grammar/adv_rule.isc";
	}
	if (rule == 10) {
		return "advanced_rule (production 10) at parser/ispa/grammar/adv_rule.isc";
	}
	if (rule == 11) {
		return "advanced_rule::dep_decl (production 11) at parser/ispa/grammar/adv_rule.isc";
	}
	if (rule == 12) {
		return "advanced_rule::fail_call (production 12) at parser/ispa/grammar/adv_rule.isc";
	}
	if (rule == 13) {
		return "advanced_rule::regular_match (production 13) at parser/ispa/grammar/adv_rule.isc";
	}
	if (rule == 14) {
		return "advanced_rule::regular_match (production 14) at parser/ispa/grammar/adv_rule.isc";
	}
	if (rule == 15) {
		return "advanced_rule::regular_match (production 15) at parser/ispa/grammar/adv_rule.isc";
	}
	if (rule == 16) {
		return "advanced_rule::regular_match (production 16) at parser/ispa/grammar/adv_rule.isc";
	}
	if (rule == 17) {
		return "advanced_rule::regular_match (production 17) at parser/ispa/grammar/adv_rule.isc";
	}
	if (rule == 18) {
		return "advanced_rule::regular_match (production 18) at parser/ispa/grammar/adv_rule.isc";
	}
	if (rule == 19) {
		return "advanced_rule::regular_match::unpack (production 19) at parser/ispa/grammar/adv_rule.isc";
	}
	if (rule == 20) {
		return "advanced_rule::regular_match::unpack (production 20) at parser/ispa/grammar/adv_rule.isc";
	}
	if (rule == 21) {
		return "advanced_rule::regular_match::unpack (production 21) at parser/ispa/grammar/adv_rule.isc";
	}
	if (rule == 22) {
		return "advanced_rule::regular_match::unpack (production 22) at parser/ispa/grammar/adv_rule.isc";
	}
	if (rule == 23) {
		return "explicit_expr (production 23) at parser/ispa/grammar/common.isc";
	}
	if (rule == 24) {
		return "expr (production 24) at parser/ispa/grammar/common.isc";
	}
	if (rule == 25) {
		return "fail_block (production 25) at parser/ispa/grammar/fail_block.isc";
	}
	if (rule == 26) {
		return "forward_declaration (production 26) at parser/ispa/grammar/common.isc";
	}
	if (rule == 27) {
		return "grammar (production 27) at parser/ispa/grammar/entry.isc";
	}
	if (rule == 28) {
		return "grammar (production 28) at parser/ispa/grammar/entry.isc";
	}
	if (rule == 29) {
		return "grammar (production 29) at parser/ispa/grammar/entry.isc";
	}
	if (rule == 30) {
		return "grammar (production 30) at parser/ispa/grammar/entry.isc";
	}
	if (rule == 31) {
		return "grammar (production 31) at parser/ispa/grammar/entry.isc";
	}
	if (rule == 32) {
		return "grammar (production 32) at parser/ispa/grammar/entry.isc";
	}
	if (rule == 33) {
		return "grammar (production 33) at parser/ispa/grammar/entry.isc";
	}
	if (rule == 34) {
		return "grammar::modifier (production 34) at parser/ispa/grammar/entry.isc";
	}
	if (rule == 35) {
		return "main (production 35) at parser/ispa/grammar/entry.isc";
	}
	if (rule == 36) {
		return "main (production 36) at parser/ispa/grammar/entry.isc";
	}
	if (rule == 37) {
		return "main (production 37) at parser/ispa/grammar/entry.isc";
	}
	if (rule == 38) {
		return "main (production 38) at parser/ispa/grammar/entry.isc";
	}
	if (rule == 39) {
		return "main (production 39) at parser/ispa/grammar/entry.isc";
	}
	if (rule == 40) {
		return "main (production 40) at parser/ispa/grammar/entry.isc";
	}
	if (rule == 41) {
		return "main (production 41) at parser/ispa/grammar/entry.isc";
	}
	if (rule == 42) {
		return "name (production 42) at parser/ispa/grammar/common.isc";
	}
	if (rule == 43) {
		return "name (production 43) at parser/ispa/grammar/common.isc";
	}
	if (rule == 44) {
		return "name (production 44) at parser/ispa/grammar/common.isc";
	}
	if (rule == 45) {
		return "name (production 45) at parser/ispa/grammar/common.isc";
	}
	if (rule == 46) {
		return "name (production 46) at parser/ispa/grammar/common.isc";
	}
	if (rule == 47) {
		return "name (production 47) at parser/ispa/grammar/common.isc";
	}
	if (rule == 48) {
		return "name (production 48) at parser/ispa/grammar/common.isc";
	}
	if (rule == 49) {
		return "name (production 49) at parser/ispa/grammar/common.isc";
	}
	if (rule == 50) {
		return "name (production 50) at parser/ispa/grammar/common.isc";
	}
	if (rule == 51) {
		return "param (production 51) at parser/ispa/grammar/common.isc";
	}
	if (rule == 52) {
		return "param (production 52) at parser/ispa/grammar/common.isc";
	}
	if (rule == 53) {
		return "param (production 53) at parser/ispa/grammar/common.isc";
	}
	if (rule == 54) {
		return "param (production 54) at parser/ispa/grammar/common.isc";
	}
	if (rule == 55) {
		return "param (production 55) at parser/ispa/grammar/common.isc";
	}
	if (rule == 56) {
		return "params (production 56) at parser/ispa/grammar/common.isc";
	}
	if (rule == 57) {
		return "params (production 57) at parser/ispa/grammar/common.isc";
	}
	if (rule == 58) {
		return "params (production 58) at parser/ispa/grammar/common.isc";
	}
	if (rule == 59) {
		return "rule (production 59) at parser/ispa/grammar/rule.isc";
	}
	if (rule == 60) {
		return "rule (production 60) at parser/ispa/grammar/rule.isc";
	}
	if (rule == 61) {
		return "rule (production 61) at parser/ispa/grammar/rule.isc";
	}
	if (rule == 62) {
		return "rule (production 62) at parser/ispa/grammar/rule.isc";
	}
	if (rule == 63) {
		return "rule (production 63) at parser/ispa/grammar/rule.isc";
	}
	if (rule == 64) {
		return "rule (production 64) at parser/ispa/grammar/rule.isc";
	}
	if (rule == 65) {
		return "rule (production 65) at parser/ispa/grammar/rule.isc";
	}
	if (rule == 66) {
		return "rule (production 66) at parser/ispa/grammar/rule.isc";
	}
	if (rule == 67) {
		return "rule (production 67) at parser/ispa/grammar/rule.isc";
	}
	if (rule == 68) {
		return "rule (production 68) at parser/ispa/grammar/rule.isc";
	}
	if (rule == 69) {
		return "rule (production 69) at parser/ispa/grammar/rule.isc";
	}
	if (rule == 70) {
		return "rule (production 70) at parser/ispa/grammar/rule.isc";
	}
	if (rule == 71) {
		return "rule::ast (production 71) at parser/ispa/grammar/rule.isc";
	}
	if (rule == 72) {
		return "rule::ast (production 72) at parser/ispa/grammar/rule.isc";
	}
	if (rule == 73) {
		return "rule::ast (production 73) at parser/ispa/grammar/rule.isc";
	}
	if (rule == 74) {
		return "rule::ast::abbr (production 74) at parser/ispa/grammar/rule.isc";
	}
	if (rule == 75) {
		return "rule::ast::abbr (production 75) at parser/ispa/grammar/rule.isc";
	}
	if (rule == 76) {
		return "rule::ast::abbr (production 76) at parser/ispa/grammar/rule.isc";
	}
	if (rule == 77) {
		return "rule::ast::abbr (production 77) at parser/ispa/grammar/rule.isc";
	}
	if (rule == 78) {
		return "rule::ast::abbr (production 78) at parser/ispa/grammar/rule.isc";
	}
	if (rule == 79) {
		return "rule::ast::full (production 79) at parser/ispa/grammar/rule.isc";
	}
	if (rule == 80) {
		return "rule::ast::full (production 80) at parser/ispa/grammar/rule.isc";
	}
	if (rule == 81) {
		return "rule::ast::full (production 81) at parser/ispa/grammar/rule.isc";
	}
	if (rule == 82) {
		return "rule::ast::full (production 82) at parser/ispa/grammar/rule.isc";
	}
	if (rule == 83) {
		return "rule::ast::full::part (production 83) at parser/ispa/grammar/rule.isc";
	}
	if (rule == 84) {
		return "rule::ast::single_value (production 84) at parser/ispa/grammar/rule.isc";
	}
	if (rule == 85) {
		return "rule::ast::single_value (production 85) at parser/ispa/grammar/rule.isc";
	}
	if (rule == 86) {
		return "rule::ast::single_value (production 86) at parser/ispa/grammar/rule.isc";
	}
	if (rule == 87) {
		return "rule::f_binding (production 87) at parser/ispa/grammar/rule.isc";
	}
	if (rule == 88) {
		return "rule::f_binding (production 88) at parser/ispa/grammar/rule.isc";
	}
	if (rule == 89) {
		return "rule::f_binding (production 89) at parser/ispa/grammar/rule.isc";
	}
	if (rule == 90) {
		return "rule::f_binding (production 90) at parser/ispa/grammar/rule.isc";
	}
	if (rule == 91) {
		return "rule::f_binding (production 91) at parser/ispa/grammar/rule.isc";
	}
	if (rule == 92) {
		return "rule::nested_rule (production 92) at parser/ispa/grammar/rule.isc";
	}
	if (rule == 93) {
		return "rule::value (production 93) at parser/ispa/grammar/rule.isc";
	}
	if (rule == 94) {
		return "rule::value (production 94) at parser/ispa/grammar/rule.isc";
	}
	if (rule == 95) {
		return "rule::value::alternative (production 95) at parser/ispa/grammar/rule.isc";
	}
	if (rule == 96) {
		return "rule::value::ast_capture (production 96) at parser/ispa/grammar/rule.isc";
	}
	if (rule == 97) {
		return "rule::value::ast_capture (production 97) at parser/ispa/grammar/rule.isc";
	}
	if (rule == 98) {
		return "rule::value::ast_capture (production 98) at parser/ispa/grammar/rule.isc";
	}
	if (rule == 99) {
		return "rule::value::counter (production 99) at parser/ispa/grammar/rule.isc";
	}
	if (rule == 100) {
		return "rule::value::counter (production 100) at parser/ispa/grammar/rule.isc";
	}
	if (rule == 101) {
		return "rule::value::counter (production 101) at parser/ispa/grammar/rule.isc";
	}
	if (rule == 102) {
		return "rule::value::counter::bounded (production 102) at parser/ispa/grammar/rule.isc";
	}
	if (rule == 103) {
		return "rule::value::counter::bounded (production 103) at parser/ispa/grammar/rule.isc";
	}
	if (rule == 104) {
		return "rule::value::counter::bounded (production 104) at parser/ispa/grammar/rule.isc";
	}
	if (rule == 105) {
		return "rule::value::counter::bounded (production 105) at parser/ispa/grammar/rule.isc";
	}
	if (rule == 106) {
		return "rule::value::dyn (production 106) at parser/ispa/grammar/rule.isc";
	}
	if (rule == 107) {
		return "rule::value::dyn (production 107) at parser/ispa/grammar/rule.isc";
	}
	if (rule == 108) {
		return "rule::value::dyn (production 108) at parser/ispa/grammar/rule.isc";
	}
	if (rule == 109) {
		return "rule::value::dyn::dyn_expr (production 109) at parser/ispa/grammar/rule.isc";
	}
	if (rule == 110) {
		return "rule::value::fail_capture (production 110) at parser/ispa/grammar/rule.isc";
	}
	if (rule == 111) {
		return "rule::value::fail_capture (production 111) at parser/ispa/grammar/rule.isc";
	}
	if (rule == 112) {
		return "rule::value::fail_capture (production 112) at parser/ispa/grammar/rule.isc";
	}
	if (rule == 113) {
		return "rule::value::group (production 113) at parser/ispa/grammar/rule.isc";
	}
	if (rule == 114) {
		return "rule::value::group (production 114) at parser/ispa/grammar/rule.isc";
	}
	if (rule == 115) {
		return "rule::value::group (production 115) at parser/ispa/grammar/rule.isc";
	}
	if (rule == 116) {
		return "rule::value::group (production 116) at parser/ispa/grammar/rule.isc";
	}
	if (rule == 117) {
		return "rule::value::mul_capture (production 117) at parser/ispa/grammar/rule.isc";
	}
	if (rule == 118) {
		return "rule::value::mul_capture (production 118) at parser/ispa/grammar/rule.isc";
	}
	if (rule == 119) {
		return "rule::value::mul_capture (production 119) at parser/ispa/grammar/rule.isc";
	}
	if (rule == 120) {
		return "rule::value::mul_capture (production 120) at parser/ispa/grammar/rule.isc";
	}
	if (rule == 121) {
		return "rule::value::mul_capture (production 121) at parser/ispa/grammar/rule.isc";
	}
	if (rule == 122) {
		return "rule::value::mul_capture (production 122) at parser/ispa/grammar/rule.isc";
	}
	if (rule == 123) {
		return "rule::value::one_capture (production 123) at parser/ispa/grammar/rule.isc";
	}
	if (rule == 124) {
		return "rule::value::one_capture (production 124) at parser/ispa/grammar/rule.isc";
	}
	if (rule == 125) {
		return "rule::value::one_capture (production 125) at parser/ispa/grammar/rule.isc";
	}
	if (rule == 126) {
		return "rule::value::one_capture (production 126) at parser/ispa/grammar/rule.isc";
	}
	if (rule == 127) {
		return "rule::value::one_capture (production 127) at parser/ispa/grammar/rule.isc";
	}
	if (rule == 128) {
		return "rule::value::one_capture (production 128) at parser/ispa/grammar/rule.isc";
	}
	if (rule == 129) {
		return "rule::value::one_capture (production 129) at parser/ispa/grammar/rule.isc";
	}
	if (rule == 130) {
		return "rule::value::one_capture (production 130) at parser/ispa/grammar/rule.isc";
	}
	if (rule == 131) {
		return "rule::value::one_capture (production 131) at parser/ispa/grammar/rule.isc";
	}
	if (rule == 132) {
		return "rule::value::one_capture (production 132) at parser/ispa/grammar/rule.isc";
	}
	if (rule == 133) {
		return "rule::value::one_capture (production 133) at parser/ispa/grammar/rule.isc";
	}
	if (rule == 134) {
		return "rule::value::one_capture (production 134) at parser/ispa/grammar/rule.isc";
	}
	if (rule == 135) {
		return "rule::value::one_capture (production 135) at parser/ispa/grammar/rule.isc";
	}
	if (rule == 136) {
		return "rule::value::one_capture (production 136) at parser/ispa/grammar/rule.isc";
	}
	if (rule == 137) {
		return "rule::value::one_capture (production 137) at parser/ispa/grammar/rule.isc";
	}
	if (rule == 138) {
		return "rule::value::pattern (production 138) at parser/ispa/grammar/rule.isc";
	}
	if (rule == 139) {
		return "rule::value::pattern (production 139) at parser/ispa/grammar/rule.isc";
	}
	if (rule == 140) {
		return "rule::value::pattern (production 140) at parser/ispa/grammar/rule.isc";
	}
	if (rule == 141) {
		return "rule::value::pattern (production 141) at parser/ispa/grammar/rule.isc";
	}
	if (rule == 142) {
		return "rule::value::pattern (production 142) at parser/ispa/grammar/rule.isc";
	}
	if (rule == 143) {
		return "rule::value::pattern (production 143) at parser/ispa/grammar/rule.isc";
	}
	if (rule == 144) {
		return "rule::value::pattern (production 144) at parser/ispa/grammar/rule.isc";
	}
	if (rule == 145) {
		return "rule::value::pattern (production 145) at parser/ispa/grammar/rule.isc";
	}
	if (rule == 146) {
		return "rule::value::shared_counter_registration (production 146) at parser/ispa/grammar/rule.isc";
	}
	if (rule == 147) {
		return "rule::value::var_capture (production 147) at parser/ispa/grammar/rule.isc";
	}
	if (rule == 148) {
		return "stmt (production 148) at parser/ispa/grammar/common.isc";
	}
	if (rule == 149) {
		return "template_params (production 149) at parser/ispa/grammar/common.isc";
	}
	if (rule == 150) {
		return "template_params (production 150) at parser/ispa/grammar/common.isc";
	}
	if (rule == 151) {
		return "template_params (production 151) at parser/ispa/grammar/common.isc";
	}
	throw std::runtime_error("Invalid LR table entry or unexpected token");
}
auto Parser::Parser::lr_goto(std::size_t state, std::size_t lhs) -> std::size_t {
	if (state == 200 && lhs == 67) {
		return 213;
	}
	if (state == 200 && lhs == 17) {
		return 212;
	}
	if (state == 190 && lhs == 15) {
		return 206;
	}
	if (state == 187 && lhs == 66) {
		return 202;
	}
	if (state == 187 && lhs == 65) {
		return 201;
	}
	if (state == 184 && lhs == 87) {
		return 199;
	}
	if (state == 184 && lhs == 61) {
		return 184;
	}
	if (state == 180 && lhs == 90) {
		return 43;
	}
	if (state == 180 && lhs == 81) {
		return 42;
	}
	if (state == 180 && lhs == 79) {
		return 40;
	}
	if (state == 180 && lhs == 60) {
		return 180;
	}
	if (state == 180 && lhs == 80) {
		return 41;
	}
	if (state == 180 && lhs == 76) {
		return 39;
	}
	if (state == 180 && lhs == 75) {
		return 197;
	}
	if (state == 174 && lhs == 49) {
		return 194;
	}
	if (state == 171 && lhs == 36) {
		return 192;
	}
	if (state == 167 && lhs == 82) {
		return 189;
	}
	if (state == 167 && lhs == 64) {
		return 188;
	}
	if (state == 165 && lhs == 87) {
		return 185;
	}
	if (state == 165 && lhs == 61) {
		return 184;
	}
	if (state == 159 && lhs == 90) {
		return 43;
	}
	if (state == 159 && lhs == 81) {
		return 42;
	}
	if (state == 159 && lhs == 79) {
		return 40;
	}
	if (state == 159 && lhs == 60) {
		return 180;
	}
	if (state == 159 && lhs == 80) {
		return 41;
	}
	if (state == 159 && lhs == 76) {
		return 39;
	}
	if (state == 159 && lhs == 75) {
		return 181;
	}
	if (state == 158 && lhs == 81) {
		return 42;
	}
	if (state == 158 && lhs == 80) {
		return 158;
	}
	if (state == 158 && lhs == 90) {
		return 43;
	}
	if (state == 158 && lhs == 78) {
		return 179;
	}
	if (state == 154 && lhs == 59) {
		return 154;
	}
	if (state == 154 && lhs == 45) {
		return 178;
	}
	if (state == 151 && lhs == 57) {
		return 177;
	}
	if (state == 148 && lhs == 53) {
		return 148;
	}
	if (state == 148 && lhs == 52) {
		return 173;
	}
	if (state == 145 && lhs == 17) {
		return 172;
	}
	if (state == 136 && lhs == 14) {
		return 169;
	}
	if (state == 132 && lhs == 70) {
		return 164;
	}
	if (state == 132 && lhs == 69) {
		return 163;
	}
	if (state == 124 && lhs == 90) {
		return 43;
	}
	if (state == 124 && lhs == 81) {
		return 42;
	}
	if (state == 124 && lhs == 79) {
		return 40;
	}
	if (state == 124 && lhs == 60) {
		return 159;
	}
	if (state == 124 && lhs == 80) {
		return 41;
	}
	if (state == 124 && lhs == 76) {
		return 39;
	}
	if (state == 124 && lhs == 74) {
		return 160;
	}
	if (state == 121 && lhs == 81) {
		return 42;
	}
	if (state == 121 && lhs == 80) {
		return 158;
	}
	if (state == 121 && lhs == 90) {
		return 43;
	}
	if (state == 121 && lhs == 78) {
		return 157;
	}
	if (state == 216 && lhs == 58) {
		return 217;
	}
	if (state == 22 && lhs == 90) {
		return 43;
	}
	if (state == 22 && lhs == 81) {
		return 42;
	}
	if (state == 22 && lhs == 79) {
		return 40;
	}
	if (state == 22 && lhs == 60) {
		return 38;
	}
	if (state == 22 && lhs == 80) {
		return 41;
	}
	if (state == 22 && lhs == 76) {
		return 39;
	}
	if (state == 22 && lhs == 40) {
		return 37;
	}
	if (state == 119 && lhs == 24) {
		return 5;
	}
	if (state == 119 && lhs == 21) {
		return 4;
	}
	if (state == 119 && lhs == 20) {
		return 155;
	}
	if (state == 5 && lhs == 24) {
		return 14;
	}
	if (state == 5 && lhs == 22) {
		return 13;
	}
	if (state == 102 && lhs == 9) {
		return 72;
	}
	if (state == 102 && lhs == 91) {
		return 74;
	}
	if (state == 102 && lhs == 4) {
		return 135;
	}
	if (state == 102 && lhs == 3) {
		return 102;
	}
	if (state == 100 && lhs == 88) {
		return 134;
	}
	if (state == 100 && lhs == 68) {
		return 131;
	}
	if (state == 100 && lhs == 73) {
		return 133;
	}
	if (state == 100 && lhs == 29) {
		return 125;
	}
	if (state == 79 && lhs == 31) {
		return 108;
	}
	if (state == 76 && lhs == 7) {
		return 76;
	}
	if (state == 76 && lhs == 6) {
		return 106;
	}
	if (state == 73 && lhs == 90) {
		return 43;
	}
	if (state == 73 && lhs == 81) {
		return 42;
	}
	if (state == 73 && lhs == 79) {
		return 40;
	}
	if (state == 73 && lhs == 60) {
		return 105;
	}
	if (state == 73 && lhs == 80) {
		return 41;
	}
	if (state == 73 && lhs == 76) {
		return 39;
	}
	if (state == 73 && lhs == 10) {
		return 104;
	}
	if (state == 118 && lhs == 59) {
		return 154;
	}
	if (state == 118 && lhs == 45) {
		return 153;
	}
	if (state == 168 && lhs == 15) {
		return 191;
	}
	if (state == 71 && lhs == 9) {
		return 72;
	}
	if (state == 71 && lhs == 91) {
		return 74;
	}
	if (state == 71 && lhs == 4) {
		return 103;
	}
	if (state == 71 && lhs == 3) {
		return 102;
	}
	if (state == 114 && lhs == 48) {
		return 150;
	}
	if (state == 67 && lhs == 63) {
		return 97;
	}
	if (state == 162 && lhs == 17) {
		return 183;
	}
	if (state == 65 && lhs == 90) {
		return 43;
	}
	if (state == 65 && lhs == 81) {
		return 42;
	}
	if (state == 65 && lhs == 79) {
		return 40;
	}
	if (state == 65 && lhs == 60) {
		return 65;
	}
	if (state == 65 && lhs == 80) {
		return 41;
	}
	if (state == 65 && lhs == 76) {
		return 39;
	}
	if (state == 65 && lhs == 41) {
		return 94;
	}
	if (state == 49 && lhs == 38) {
		return 81;
	}
	if (state == 49 && lhs == 34) {
		return 80;
	}
	if (state == 141 && lhs == 90) {
		return 43;
	}
	if (state == 141 && lhs == 81) {
		return 42;
	}
	if (state == 141 && lhs == 79) {
		return 40;
	}
	if (state == 141 && lhs == 60) {
		return 141;
	}
	if (state == 141 && lhs == 80) {
		return 41;
	}
	if (state == 141 && lhs == 76) {
		return 39;
	}
	if (state == 141 && lhs == 11) {
		return 170;
	}
	if (state == 44 && lhs == 91) {
		return 74;
	}
	if (state == 44 && lhs == 9) {
		return 72;
	}
	if (state == 44 && lhs == 3) {
		return 71;
	}
	if (state == 44 && lhs == 2) {
		return 70;
	}
	if (state == 85 && lhs == 53) {
		return 113;
	}
	if (state == 85 && lhs == 51) {
		return 112;
	}
	if (state == 38 && lhs == 90) {
		return 43;
	}
	if (state == 38 && lhs == 81) {
		return 42;
	}
	if (state == 38 && lhs == 79) {
		return 40;
	}
	if (state == 38 && lhs == 60) {
		return 65;
	}
	if (state == 38 && lhs == 80) {
		return 41;
	}
	if (state == 38 && lhs == 76) {
		return 39;
	}
	if (state == 38 && lhs == 41) {
		return 64;
	}
	if (state == 31 && lhs == 37) {
		return 51;
	}
	if (state == 31 && lhs == 33) {
		return 50;
	}
	if (state == 30 && lhs == 31) {
		return 48;
	}
	if (state == 189 && lhs == 89) {
		return 204;
	}
	if (state == 189 && lhs == 83) {
		return 203;
	}
	if (state == 92 && lhs == 59) {
		return 118;
	}
	if (state == 92 && lhs == 44) {
		return 117;
	}
	if (state == 45 && lhs == 7) {
		return 76;
	}
	if (state == 45 && lhs == 6) {
		return 75;
	}
	if (state == 166 && lhs == 88) {
		return 186;
	}
	if (state == 166 && lhs == 68) {
		return 131;
	}
	if (state == 166 && lhs == 73) {
		return 133;
	}
	if (state == 166 && lhs == 29) {
		return 125;
	}
	if (state == 69 && lhs == 85) {
		return 100;
	}
	if (state == 69 && lhs == 71) {
		return 99;
	}
	if (state == 42 && lhs == 84) {
		return 69;
	}
	if (state == 42 && lhs == 62) {
		return 68;
	}
	if (state == 16 && lhs == 28) {
		return 29;
	}
	if (state == 16 && lhs == 24) {
		return 5;
	}
	if (state == 16 && lhs == 18) {
		return 2;
	}
	if (state == 16 && lhs == 21) {
		return 4;
	}
	if (state == 16 && lhs == 20) {
		return 3;
	}
	if (state == 16 && lhs == 27) {
		return 16;
	}
	if (state == 113 && lhs == 53) {
		return 148;
	}
	if (state == 113 && lhs == 52) {
		return 147;
	}
	if (state == 19 && lhs == 92) {
		return 32;
	}
	if (state == 19 && lhs == 32) {
		return 31;
	}
	if (state == 134 && lhs == 86) {
		return 167;
	}
	if (state == 134 && lhs == 61) {
		return 165;
	}
	if (state == 37 && lhs == 50) {
		return 62;
	}
	if (state == 37 && lhs == 47) {
		return 61;
	}
	if (state == 37 && lhs == 46) {
		return 60;
	}
	if (state == 37 && lhs == 54) {
		return 63;
	}
	if (state == 37 && lhs == 42) {
		return 59;
	}
	if (state == 14 && lhs == 24) {
		return 14;
	}
	if (state == 14 && lhs == 22) {
		return 27;
	}
	if (state == 33 && lhs == 93) {
		return 54;
	}
	if (state == 33 && lhs == 34) {
		return 53;
	}
	if (state == 104 && lhs == 13) {
		return 139;
	}
	if (state == 104 && lhs == 12) {
		return 138;
	}
	if (state == 10 && lhs == 30) {
		return 19;
	}
	if (state == 9 && lhs == 28) {
		return 17;
	}
	if (state == 9 && lhs == 24) {
		return 5;
	}
	if (state == 9 && lhs == 18) {
		return 2;
	}
	if (state == 9 && lhs == 21) {
		return 4;
	}
	if (state == 9 && lhs == 20) {
		return 3;
	}
	if (state == 9 && lhs == 27) {
		return 16;
	}
	if (state == 195 && lhs == 58) {
		return 209;
	}
	if (state == 1 && lhs == 29) {
		return 11;
	}
	if (state == 98 && lhs == 72) {
		return 123;
	}
	if (state == 98 && lhs == 29) {
		return 122;
	}
	if (state == 4 && lhs == 29) {
		return 12;
	}
	if (state == 59 && lhs == 56) {
		return 93;
	}
	if (state == 59 && lhs == 43) {
		return 92;
	}
	if (state == 12 && lhs == 39) {
		return 26;
	}
	if (state == 12 && lhs == 23) {
		return 25;
	}
	if (state == 12 && lhs == 1) {
		return 24;
	}
	if (state == 95 && lhs == 90) {
		return 43;
	}
	if (state == 95 && lhs == 81) {
		return 42;
	}
	if (state == 95 && lhs == 80) {
		return 121;
	}
	if (state == 95 && lhs == 77) {
		return 120;
	}
	if (state == 207 && lhs == 49) {
		return 215;
	}
	if (state == 110 && lhs == 36) {
		return 144;
	}
	if (state == 52 && lhs == 35) {
		return 83;
	}
	if (state == 105 && lhs == 90) {
		return 43;
	}
	if (state == 105 && lhs == 81) {
		return 42;
	}
	if (state == 105 && lhs == 79) {
		return 40;
	}
	if (state == 105 && lhs == 60) {
		return 141;
	}
	if (state == 105 && lhs == 80) {
		return 41;
	}
	if (state == 105 && lhs == 76) {
		return 39;
	}
	if (state == 105 && lhs == 11) {
		return 140;
	}
	if (state == 58 && lhs == 55) {
		return 90;
	}
	if (state == 58 && lhs == 17) {
		return 89;
	}
	if (state == 11 && lhs == 91) {
		return 21;
	}
	if (state == 46 && lhs == 19) {
		return 78;
	}
	if (state == 23 && lhs == 7) {
		return 45;
	}
	if (state == 23 && lhs == 5) {
		return 44;
	}
	if (state == 0 && lhs == 24) {
		return 5;
	}
	if (state == 0 && lhs == 18) {
		return 2;
	}
	if (state == 0 && lhs == 21) {
		return 4;
	}
	if (state == 0 && lhs == 27) {
		return 9;
	}
	if (state == 0 && lhs == 26) {
		return 8;
	}
	if (state == 0 && lhs == 25) {
		return 7;
	}
	if (state == 0 && lhs == 20) {
		return 3;
	}
	throw std::runtime_error("Invalid LR table entry or unexpected token");
}
auto Parser::Parser::lr_length(std::size_t rule) -> std::size_t {
	if (rule == 0) {
		return 4;
	}
	if (rule == 1) {
		return 0;
	}
	if (rule == 2) {
		return 2;
	}
	if (rule == 3) {
		return 1;
	}
	if (rule == 4) {
		return 1;
	}
	if (rule == 5) {
		return 0;
	}
	if (rule == 6) {
		return 2;
	}
	if (rule == 7) {
		return 0;
	}
	if (rule == 8) {
		return 2;
	}
	if (rule == 9) {
		return 0;
	}
	if (rule == 10) {
		return 2;
	}
	if (rule == 11) {
		return 2;
	}
	if (rule == 12) {
		return 2;
	}
	if (rule == 13) {
		return 3;
	}
	if (rule == 14) {
		return 2;
	}
	if (rule == 15) {
		return 0;
	}
	if (rule == 16) {
		return 2;
	}
	if (rule == 17) {
		return 1;
	}
	if (rule == 18) {
		return 1;
	}
	if (rule == 19) {
		return 2;
	}
	if (rule == 20) {
		return 2;
	}
	if (rule == 21) {
		return 0;
	}
	if (rule == 22) {
		return 2;
	}
	if (rule == 23) {
		return 3;
	}
	if (rule == 24) {
		return 1;
	}
	if (rule == 25) {
		return 3;
	}
	if (rule == 26) {
		return 3;
	}
	if (rule == 27) {
		return 3;
	}
	if (rule == 28) {
		return 0;
	}
	if (rule == 29) {
		return 2;
	}
	if (rule == 30) {
		return 0;
	}
	if (rule == 31) {
		return 2;
	}
	if (rule == 32) {
		return 1;
	}
	if (rule == 33) {
		return 1;
	}
	if (rule == 34) {
		return 3;
	}
	if (rule == 35) {
		return 1;
	}
	if (rule == 36) {
		return 0;
	}
	if (rule == 37) {
		return 2;
	}
	if (rule == 38) {
		return 1;
	}
	if (rule == 39) {
		return 1;
	}
	if (rule == 40) {
		return 0;
	}
	if (rule == 41) {
		return 2;
	}
	if (rule == 42) {
		return 4;
	}
	if (rule == 43) {
		return 0;
	}
	if (rule == 44) {
		return 3;
	}
	if (rule == 45) {
		return 0;
	}
	if (rule == 46) {
		return 3;
	}
	if (rule == 47) {
		return 0;
	}
	if (rule == 48) {
		return 1;
	}
	if (rule == 49) {
		return 0;
	}
	if (rule == 50) {
		return 1;
	}
	if (rule == 51) {
		return 2;
	}
	if (rule == 52) {
		return 0;
	}
	if (rule == 53) {
		return 3;
	}
	if (rule == 54) {
		return 0;
	}
	if (rule == 55) {
		return 3;
	}
	if (rule == 56) {
		return 3;
	}
	if (rule == 57) {
		return 0;
	}
	if (rule == 58) {
		return 1;
	}
	if (rule == 59) {
		return 6;
	}
	if (rule == 60) {
		return 2;
	}
	if (rule == 61) {
		return 0;
	}
	if (rule == 62) {
		return 2;
	}
	if (rule == 63) {
		return 0;
	}
	if (rule == 64) {
		return 1;
	}
	if (rule == 65) {
		return 0;
	}
	if (rule == 66) {
		return 1;
	}
	if (rule == 67) {
		return 0;
	}
	if (rule == 68) {
		return 2;
	}
	if (rule == 69) {
		return 0;
	}
	if (rule == 70) {
		return 2;
	}
	if (rule == 71) {
		return 1;
	}
	if (rule == 72) {
		return 1;
	}
	if (rule == 73) {
		return 1;
	}
	if (rule == 74) {
		return 5;
	}
	if (rule == 75) {
		return 0;
	}
	if (rule == 76) {
		return 3;
	}
	if (rule == 77) {
		return 0;
	}
	if (rule == 78) {
		return 3;
	}
	if (rule == 79) {
		return 4;
	}
	if (rule == 80) {
		return 2;
	}
	if (rule == 81) {
		return 0;
	}
	if (rule == 82) {
		return 2;
	}
	if (rule == 83) {
		return 3;
	}
	if (rule == 84) {
		return 3;
	}
	if (rule == 85) {
		return 1;
	}
	if (rule == 86) {
		return 1;
	}
	if (rule == 87) {
		return 5;
	}
	if (rule == 88) {
		return 0;
	}
	if (rule == 89) {
		return 3;
	}
	if (rule == 90) {
		return 0;
	}
	if (rule == 91) {
		return 3;
	}
	if (rule == 92) {
		return 2;
	}
	if (rule == 93) {
		return 1;
	}
	if (rule == 94) {
		return 1;
	}
	if (rule == 95) {
		return 2;
	}
	if (rule == 96) {
		return 2;
	}
	if (rule == 97) {
		return 0;
	}
	if (rule == 98) {
		return 1;
	}
	if (rule == 99) {
		return 2;
	}
	if (rule == 100) {
		return 0;
	}
	if (rule == 101) {
		return 1;
	}
	if (rule == 102) {
		return 2;
	}
	if (rule == 103) {
		return 1;
	}
	if (rule == 104) {
		return 1;
	}
	if (rule == 105) {
		return 1;
	}
	if (rule == 106) {
		return 2;
	}
	if (rule == 107) {
		return 1;
	}
	if (rule == 108) {
		return 1;
	}
	if (rule == 109) {
		return 3;
	}
	if (rule == 110) {
		return 2;
	}
	if (rule == 111) {
		return 0;
	}
	if (rule == 112) {
		return 1;
	}
	if (rule == 113) {
		return 3;
	}
	if (rule == 114) {
		return 2;
	}
	if (rule == 115) {
		return 0;
	}
	if (rule == 116) {
		return 2;
	}
	if (rule == 117) {
		return 5;
	}
	if (rule == 118) {
		return 2;
	}
	if (rule == 119) {
		return 0;
	}
	if (rule == 120) {
		return 2;
	}
	if (rule == 121) {
		return 1;
	}
	if (rule == 122) {
		return 1;
	}
	if (rule == 123) {
		return 7;
	}
	if (rule == 124) {
		return 0;
	}
	if (rule == 125) {
		return 1;
	}
	if (rule == 126) {
		return 0;
	}
	if (rule == 127) {
		return 1;
	}
	if (rule == 128) {
		return 0;
	}
	if (rule == 129) {
		return 1;
	}
	if (rule == 130) {
		return 0;
	}
	if (rule == 131) {
		return 1;
	}
	if (rule == 132) {
		return 0;
	}
	if (rule == 133) {
		return 1;
	}
	if (rule == 134) {
		return 0;
	}
	if (rule == 135) {
		return 2;
	}
	if (rule == 136) {
		return 0;
	}
	if (rule == 137) {
		return 2;
	}
	if (rule == 138) {
		return 1;
	}
	if (rule == 139) {
		return 1;
	}
	if (rule == 140) {
		return 1;
	}
	if (rule == 141) {
		return 1;
	}
	if (rule == 142) {
		return 1;
	}
	if (rule == 143) {
		return 1;
	}
	if (rule == 144) {
		return 1;
	}
	if (rule == 145) {
		return 1;
	}
	if (rule == 146) {
		return 2;
	}
	if (rule == 147) {
		return 2;
	}
	if (rule == 148) {
		return 1;
	}
	if (rule == 149) {
		return 3;
	}
	if (rule == 150) {
		return 0;
	}
	if (rule == 151) {
		return 1;
	}
	throw std::runtime_error("Invalid LR table entry or unexpected token");
}
auto Parser::Parser::lr_lhs(std::size_t rule) -> std::size_t {
	if (rule == 0) {
		return 1;
	}
	if (rule == 1) {
		return 2;
	}
	if (rule == 2) {
		return 2;
	}
	if (rule == 3) {
		return 3;
	}
	if (rule == 4) {
		return 3;
	}
	if (rule == 5) {
		return 4;
	}
	if (rule == 6) {
		return 4;
	}
	if (rule == 7) {
		return 5;
	}
	if (rule == 8) {
		return 5;
	}
	if (rule == 9) {
		return 6;
	}
	if (rule == 10) {
		return 6;
	}
	if (rule == 11) {
		return 7;
	}
	if (rule == 12) {
		return 8;
	}
	if (rule == 13) {
		return 9;
	}
	if (rule == 14) {
		return 10;
	}
	if (rule == 15) {
		return 11;
	}
	if (rule == 16) {
		return 11;
	}
	if (rule == 17) {
		return 12;
	}
	if (rule == 18) {
		return 12;
	}
	if (rule == 19) {
		return 13;
	}
	if (rule == 20) {
		return 14;
	}
	if (rule == 21) {
		return 15;
	}
	if (rule == 22) {
		return 15;
	}
	if (rule == 23) {
		return 16;
	}
	if (rule == 24) {
		return 17;
	}
	if (rule == 25) {
		return 18;
	}
	if (rule == 26) {
		return 19;
	}
	if (rule == 27) {
		return 20;
	}
	if (rule == 28) {
		return 21;
	}
	if (rule == 29) {
		return 21;
	}
	if (rule == 30) {
		return 22;
	}
	if (rule == 31) {
		return 22;
	}
	if (rule == 32) {
		return 23;
	}
	if (rule == 33) {
		return 23;
	}
	if (rule == 34) {
		return 24;
	}
	if (rule == 35) {
		return 25;
	}
	if (rule == 36) {
		return 26;
	}
	if (rule == 37) {
		return 26;
	}
	if (rule == 38) {
		return 27;
	}
	if (rule == 39) {
		return 27;
	}
	if (rule == 40) {
		return 28;
	}
	if (rule == 41) {
		return 28;
	}
	if (rule == 42) {
		return 29;
	}
	if (rule == 43) {
		return 30;
	}
	if (rule == 44) {
		return 30;
	}
	if (rule == 45) {
		return 31;
	}
	if (rule == 46) {
		return 31;
	}
	if (rule == 47) {
		return 32;
	}
	if (rule == 48) {
		return 32;
	}
	if (rule == 49) {
		return 33;
	}
	if (rule == 50) {
		return 33;
	}
	if (rule == 51) {
		return 34;
	}
	if (rule == 52) {
		return 35;
	}
	if (rule == 53) {
		return 35;
	}
	if (rule == 54) {
		return 36;
	}
	if (rule == 55) {
		return 36;
	}
	if (rule == 56) {
		return 37;
	}
	if (rule == 57) {
		return 38;
	}
	if (rule == 58) {
		return 38;
	}
	if (rule == 59) {
		return 39;
	}
	if (rule == 60) {
		return 40;
	}
	if (rule == 61) {
		return 41;
	}
	if (rule == 62) {
		return 41;
	}
	if (rule == 63) {
		return 42;
	}
	if (rule == 64) {
		return 42;
	}
	if (rule == 65) {
		return 43;
	}
	if (rule == 66) {
		return 43;
	}
	if (rule == 67) {
		return 44;
	}
	if (rule == 68) {
		return 44;
	}
	if (rule == 69) {
		return 45;
	}
	if (rule == 70) {
		return 45;
	}
	if (rule == 71) {
		return 46;
	}
	if (rule == 72) {
		return 46;
	}
	if (rule == 73) {
		return 46;
	}
	if (rule == 74) {
		return 47;
	}
	if (rule == 75) {
		return 48;
	}
	if (rule == 76) {
		return 48;
	}
	if (rule == 77) {
		return 49;
	}
	if (rule == 78) {
		return 49;
	}
	if (rule == 79) {
		return 50;
	}
	if (rule == 80) {
		return 51;
	}
	if (rule == 81) {
		return 52;
	}
	if (rule == 82) {
		return 52;
	}
	if (rule == 83) {
		return 53;
	}
	if (rule == 84) {
		return 54;
	}
	if (rule == 85) {
		return 55;
	}
	if (rule == 86) {
		return 55;
	}
	if (rule == 87) {
		return 56;
	}
	if (rule == 88) {
		return 57;
	}
	if (rule == 89) {
		return 57;
	}
	if (rule == 90) {
		return 58;
	}
	if (rule == 91) {
		return 58;
	}
	if (rule == 92) {
		return 59;
	}
	if (rule == 93) {
		return 60;
	}
	if (rule == 94) {
		return 60;
	}
	if (rule == 95) {
		return 61;
	}
	if (rule == 96) {
		return 62;
	}
	if (rule == 97) {
		return 63;
	}
	if (rule == 98) {
		return 63;
	}
	if (rule == 99) {
		return 64;
	}
	if (rule == 100) {
		return 65;
	}
	if (rule == 101) {
		return 65;
	}
	if (rule == 102) {
		return 66;
	}
	if (rule == 103) {
		return 67;
	}
	if (rule == 104) {
		return 67;
	}
	if (rule == 105) {
		return 67;
	}
	if (rule == 106) {
		return 68;
	}
	if (rule == 107) {
		return 69;
	}
	if (rule == 108) {
		return 69;
	}
	if (rule == 109) {
		return 70;
	}
	if (rule == 110) {
		return 71;
	}
	if (rule == 111) {
		return 72;
	}
	if (rule == 112) {
		return 72;
	}
	if (rule == 113) {
		return 73;
	}
	if (rule == 114) {
		return 74;
	}
	if (rule == 115) {
		return 75;
	}
	if (rule == 116) {
		return 75;
	}
	if (rule == 117) {
		return 76;
	}
	if (rule == 118) {
		return 77;
	}
	if (rule == 119) {
		return 78;
	}
	if (rule == 120) {
		return 78;
	}
	if (rule == 121) {
		return 79;
	}
	if (rule == 122) {
		return 79;
	}
	if (rule == 123) {
		return 80;
	}
	if (rule == 124) {
		return 81;
	}
	if (rule == 125) {
		return 81;
	}
	if (rule == 126) {
		return 82;
	}
	if (rule == 127) {
		return 82;
	}
	if (rule == 128) {
		return 83;
	}
	if (rule == 129) {
		return 83;
	}
	if (rule == 130) {
		return 84;
	}
	if (rule == 131) {
		return 84;
	}
	if (rule == 132) {
		return 85;
	}
	if (rule == 133) {
		return 85;
	}
	if (rule == 134) {
		return 86;
	}
	if (rule == 135) {
		return 86;
	}
	if (rule == 136) {
		return 87;
	}
	if (rule == 137) {
		return 87;
	}
	if (rule == 138) {
		return 88;
	}
	if (rule == 139) {
		return 88;
	}
	if (rule == 140) {
		return 88;
	}
	if (rule == 141) {
		return 88;
	}
	if (rule == 142) {
		return 88;
	}
	if (rule == 143) {
		return 88;
	}
	if (rule == 144) {
		return 88;
	}
	if (rule == 145) {
		return 88;
	}
	if (rule == 146) {
		return 89;
	}
	if (rule == 147) {
		return 90;
	}
	if (rule == 148) {
		return 91;
	}
	if (rule == 149) {
		return 92;
	}
	if (rule == 150) {
		return 93;
	}
	if (rule == 151) {
		return 93;
	}
	throw std::runtime_error("Invalid LR table entry or unexpected token");
}
auto Parser::Parser::lr_reduce(std::size_t rule, const std::vector<std::any>& values) -> std::any {
	if (rule == 0) {
		Types::advanced_rule result;
		lr_capture_assign(result.dep, values, 1, static_cast<std::size_t>(-1));
		lr_capture_assign(result.body, values, 2, static_cast<std::size_t>(-1));
		return lr_node<Types::advanced_rule>(result);
	}
	if (rule == 1) {
		return lr_pack(values, {}, {}, {}, 1, true);
	}
	if (rule == 2) {
		return lr_pack(values, {0, 1}, {0, 0}, {0, 1}, 1, true);
	}
	if (rule == 3) {
		return lr_pack(values, {0}, {0}, {0}, 1, false);
	}
	if (rule == 4) {
		return lr_pack(values, {0}, {0}, {0}, 1, false);
	}
	if (rule == 5) {
		return lr_pack(values, {}, {}, {}, 1, true);
	}
	if (rule == 6) {
		return lr_pack(values, {0, 1}, {0, 0}, {0, 1}, 1, true);
	}
	if (rule == 7) {
		return lr_pack(values, {}, {}, {}, 1, true);
	}
	if (rule == 8) {
		return lr_pack(values, {0, 1}, {0, 0}, {0, 1}, 1, true);
	}
	if (rule == 9) {
		return lr_pack(values, {}, {}, {}, 1, true);
	}
	if (rule == 10) {
		return lr_pack(values, {0, 1}, {0, 0}, {0, 1}, 1, true);
	}
	if (rule == 11) {
		Types::advanced_rule::dep_decl result;
		lr_capture_assign(result.value, values, 1, static_cast<std::size_t>(-1));
		return lr_node<Types::advanced_rule::dep_decl>(result);
	}
	if (rule == 12) {
		Types::advanced_rule::fail_call result;
		lr_capture_assign(result.value, values, 1, static_cast<std::size_t>(-1));
		return lr_node<Types::advanced_rule::fail_call>(result);
	}
	if (rule == 13) {
		Types::advanced_rule::regular_match result;
		lr_capture_assign(result.patterns, values, 1, static_cast<std::size_t>(-1));
		lr_capture_assign(result.assign_names, values, 2, static_cast<std::size_t>(-1));
		return lr_node<Types::advanced_rule::regular_match>(result);
	}
	if (rule == 14) {
		return lr_pack(values, {0, 1}, {0, 0}, {0, 1}, 1, true);
	}
	if (rule == 15) {
		return lr_pack(values, {}, {}, {}, 1, true);
	}
	if (rule == 16) {
		return lr_pack(values, {0, 1}, {0, 0}, {0, 1}, 1, true);
	}
	if (rule == 17) {
		return lr_pack(values, {0}, {0}, {0}, 1, false);
	}
	if (rule == 18) {
		return lr_pack(values, {0}, {0}, {0}, 1, false);
	}
	if (rule == 19) {
		Types::advanced_rule::regular_match::unpack result;
		lr_capture_assign(result.value, values, 1, static_cast<std::size_t>(-1));
		return lr_node<Types::advanced_rule::regular_match::unpack>(result);
	}
	if (rule == 20) {
		return lr_pack(values, {0, 1}, {0, 0}, {0, 1}, 1, true);
	}
	if (rule == 21) {
		return lr_pack(values, {}, {}, {}, 1, true);
	}
	if (rule == 22) {
		return lr_pack(values, {0, 1}, {0, 0}, {0, 1}, 1, true);
	}
	if (rule == 23) {
		Types::explicit_expr result;
		lr_capture_assign(result.value, values, 1, static_cast<std::size_t>(-1));
		return lr_node<Types::explicit_expr>(result);
	}
	if (rule == 24) {
		Types::expr result;
		lr_capture_assign(result.value, values, 0, static_cast<std::size_t>(-1));
		return lr_node<Types::expr>(result);
	}
	if (rule == 25) {
		Types::fail_block result;
		lr_capture_assign(result.name, values, 1, static_cast<std::size_t>(-1));
		lr_capture_assign(result.val, values, 2, static_cast<std::size_t>(-1));
		return lr_node<Types::fail_block>(result);
	}
	if (rule == 26) {
		Types::forward_declaration result;
		lr_capture_assign(result.value, values, 1, static_cast<std::size_t>(-1));
		return lr_node<Types::forward_declaration>(result);
	}
	if (rule == 27) {
		Types::grammar result;
		lr_capture_assign(result.mod, values, 0, static_cast<std::size_t>(-1));
		lr_capture_assign(result.name, values, 1, static_cast<std::size_t>(-1));
		lr_capture_assign(result.entry, values, 2, static_cast<std::size_t>(-1));
		return lr_node<Types::grammar>(result);
	}
	if (rule == 28) {
		return lr_pack(values, {}, {}, {}, 1, true);
	}
	if (rule == 29) {
		return lr_pack(values, {0, 1}, {0, 0}, {0, 1}, 1, true);
	}
	if (rule == 30) {
		return lr_pack(values, {}, {}, {}, 1, true);
	}
	if (rule == 31) {
		return lr_pack(values, {0, 1}, {0, 0}, {0, 1}, 1, true);
	}
	if (rule == 32) {
		return lr_pack(values, {0}, {0}, {0}, 1, false);
	}
	if (rule == 33) {
		return lr_pack(values, {0}, {0}, {0}, 1, false);
	}
	if (rule == 34) {
		Types::grammar::modifier result;
		lr_capture_assign(result.value, values, 1, static_cast<std::size_t>(-1));
		return lr_node<Types::grammar::modifier>(result);
	}
	if (rule == 35) {
		Types::main result;
		lr_capture_assign(result.value, values, 0, static_cast<std::size_t>(-1));
		return lr_node<Types::main>(result);
	}
	if (rule == 36) {
		return lr_pack(values, {}, {}, {}, 1, true);
	}
	if (rule == 37) {
		return lr_pack(values, {0, 1}, {0, 0}, {0, 1}, 1, true);
	}
	if (rule == 38) {
		return lr_pack(values, {0}, {0}, {0}, 1, false);
	}
	if (rule == 39) {
		return lr_pack(values, {0}, {0}, {0}, 1, false);
	}
	if (rule == 40) {
		return lr_pack(values, {}, {}, {}, 1, true);
	}
	if (rule == 41) {
		return lr_pack(values, {0, 1}, {0, 0}, {0, 1}, 1, true);
	}
	if (rule == 42) {
		Types::name result;
		lr_capture_assign(result.primary, values, 0, static_cast<std::size_t>(-1));
		lr_capture_assign(result.nested, values, 1, static_cast<std::size_t>(0));
		lr_capture_assign(result.temp_params, values, 2, static_cast<std::size_t>(-1));
		lr_capture_assign(result.param, values, 3, static_cast<std::size_t>(-1));
		return lr_node<Types::name>(result);
	}
	if (rule == 43) {
		return lr_pack(values, {}, {}, {}, 1, true);
	}
	if (rule == 44) {
		return lr_pack(values, {1, 2}, {0, 0}, {0, 1}, 1, true);
	}
	if (rule == 45) {
		return lr_pack(values, {}, {}, {}, 1, true);
	}
	if (rule == 46) {
		return lr_pack(values, {1, 2}, {0, 0}, {0, 1}, 1, true);
	}
	if (rule == 47) {
		return lr_pack(values, {}, {}, {}, 1, false);
	}
	if (rule == 48) {
		return lr_pack(values, {0}, {0}, {0}, 1, false);
	}
	if (rule == 49) {
		return lr_pack(values, {}, {}, {}, 1, false);
	}
	if (rule == 50) {
		return lr_pack(values, {0}, {0}, {0}, 1, false);
	}
	if (rule == 51) {
		Types::param result;
		lr_capture_assign(result.first_p, values, 0, static_cast<std::size_t>(-1));
		lr_capture_assign(result.following_p, values, 1, static_cast<std::size_t>(0));
		return lr_node<Types::param>(result);
	}
	if (rule == 52) {
		return lr_pack(values, {}, {}, {}, 1, true);
	}
	if (rule == 53) {
		return lr_pack(values, {1, 2}, {0, 0}, {0, 1}, 1, true);
	}
	if (rule == 54) {
		return lr_pack(values, {}, {}, {}, 1, true);
	}
	if (rule == 55) {
		return lr_pack(values, {1, 2}, {0, 0}, {0, 1}, 1, true);
	}
	if (rule == 56) {
		Types::params result;
		lr_capture_assign(result.value, values, 1, static_cast<std::size_t>(-1));
		return lr_node<Types::params>(result);
	}
	if (rule == 57) {
		return lr_pack(values, {}, {}, {}, 1, false);
	}
	if (rule == 58) {
		return lr_pack(values, {0}, {0}, {0}, 1, false);
	}
	if (rule == 59) {
		Types::rule result;
		lr_capture_assign(result.v, values, 1, static_cast<std::size_t>(-1));
		lr_capture_assign(result.ast_pointer, values, 2, static_cast<std::size_t>(-1));
		lr_capture_assign(result.fail_pointer, values, 3, static_cast<std::size_t>(-1));
		lr_capture_assign(result.nested, values, 4, static_cast<std::size_t>(-1));
		return lr_node<Types::rule>(result);
	}
	if (rule == 60) {
		return lr_pack(values, {0, 1}, {0, 0}, {0, 1}, 1, true);
	}
	if (rule == 61) {
		return lr_pack(values, {}, {}, {}, 1, true);
	}
	if (rule == 62) {
		return lr_pack(values, {0, 1}, {0, 0}, {0, 1}, 1, true);
	}
	if (rule == 63) {
		return lr_pack(values, {}, {}, {}, 1, false);
	}
	if (rule == 64) {
		return lr_pack(values, {0}, {0}, {0}, 1, false);
	}
	if (rule == 65) {
		return lr_pack(values, {}, {}, {}, 1, false);
	}
	if (rule == 66) {
		return lr_pack(values, {0}, {0}, {0}, 1, false);
	}
	if (rule == 67) {
		return lr_pack(values, {}, {}, {}, 1, true);
	}
	if (rule == 68) {
		return lr_pack(values, {0, 1}, {0, 0}, {0, 1}, 1, true);
	}
	if (rule == 69) {
		return lr_pack(values, {}, {}, {}, 1, true);
	}
	if (rule == 70) {
		return lr_pack(values, {0, 1}, {0, 0}, {0, 1}, 1, true);
	}
	if (rule == 71) {
		Types::rule::ast result;
		lr_capture_assign(result.value, values, 0, static_cast<std::size_t>(-1));
		return lr_node<Types::rule::ast>(result);
	}
	if (rule == 72) {
		Types::rule::ast result;
		lr_capture_assign(result.value, values, 0, static_cast<std::size_t>(-1));
		return lr_node<Types::rule::ast>(result);
	}
	if (rule == 73) {
		Types::rule::ast result;
		lr_capture_assign(result.value, values, 0, static_cast<std::size_t>(-1));
		return lr_node<Types::rule::ast>(result);
	}
	if (rule == 74) {
		Types::rule::ast::abbr result;
		lr_capture_assign(result.f, values, 2, static_cast<std::size_t>(-1));
		lr_capture_assign(result.seq, values, 3, static_cast<std::size_t>(0));
		return lr_node<Types::rule::ast::abbr>(result);
	}
	if (rule == 75) {
		return lr_pack(values, {}, {}, {}, 1, true);
	}
	if (rule == 76) {
		return lr_pack(values, {1, 2}, {0, 0}, {0, 1}, 1, true);
	}
	if (rule == 77) {
		return lr_pack(values, {}, {}, {}, 1, true);
	}
	if (rule == 78) {
		return lr_pack(values, {1, 2}, {0, 0}, {0, 1}, 1, true);
	}
	if (rule == 79) {
		Types::rule::ast::full result;
		lr_capture_assign(result.value, values, 2, static_cast<std::size_t>(-1));
		return lr_node<Types::rule::ast::full>(result);
	}
	if (rule == 80) {
		return lr_pack(values, {0, 1}, {0, 0}, {0, 1}, 1, true);
	}
	if (rule == 81) {
		return lr_pack(values, {}, {}, {}, 1, true);
	}
	if (rule == 82) {
		return lr_pack(values, {0, 1}, {0, 0}, {0, 1}, 1, true);
	}
	if (rule == 83) {
		Types::rule::ast::full::part result;
		lr_capture_assign(result.key, values, 0, static_cast<std::size_t>(-1));
		lr_capture_assign(result.e, values, 2, static_cast<std::size_t>(-1));
		return lr_node<Types::rule::ast::full::part>(result);
	}
	if (rule == 84) {
		Types::rule::ast::single_value result;
		lr_capture_assign(result.value, values, 1, static_cast<std::size_t>(-1));
		return lr_node<Types::rule::ast::single_value>(result);
	}
	if (rule == 85) {
		return lr_pack(values, {0}, {0}, {0}, 1, false);
	}
	if (rule == 86) {
		return lr_pack(values, {0}, {0}, {0}, 1, false);
	}
	if (rule == 87) {
		Types::rule::f_binding result;
		lr_capture_assign(result.f, values, 2, static_cast<std::size_t>(-1));
		lr_capture_assign(result.seq, values, 3, static_cast<std::size_t>(0));
		return lr_node<Types::rule::f_binding>(result);
	}
	if (rule == 88) {
		return lr_pack(values, {}, {}, {}, 1, true);
	}
	if (rule == 89) {
		return lr_pack(values, {1, 2}, {0, 0}, {0, 1}, 1, true);
	}
	if (rule == 90) {
		return lr_pack(values, {}, {}, {}, 1, true);
	}
	if (rule == 91) {
		return lr_pack(values, {1, 2}, {0, 0}, {0, 1}, 1, true);
	}
	if (rule == 92) {
		Types::rule::nested_rule result;
		lr_capture_assign(result.value, values, 1, static_cast<std::size_t>(-1));
		return lr_node<Types::rule::nested_rule>(result);
	}
	if (rule == 93) {
		Types::rule::value result;
		lr_capture_assign(result.value, values, 0, static_cast<std::size_t>(-1));
		return lr_node<Types::rule::value>(result);
	}
	if (rule == 94) {
		Types::rule::value result;
		lr_capture_assign(result.value, values, 0, static_cast<std::size_t>(-1));
		return lr_node<Types::rule::value>(result);
	}
	if (rule == 95) {
		Types::rule::value::alternative result;
		lr_capture_assign(result.value, values, 1, static_cast<std::size_t>(-1));
		return lr_node<Types::rule::value::alternative>(result);
	}
	if (rule == 96) {
		Types::rule::value::ast_capture result;
		lr_capture_assign(result.value, values, 1, static_cast<std::size_t>(-1));
		return lr_node<Types::rule::value::ast_capture>(result);
	}
	if (rule == 97) {
		return lr_pack(values, {}, {}, {}, 1, false);
	}
	if (rule == 98) {
		return lr_pack(values, {0}, {0}, {0}, 1, false);
	}
	if (rule == 99) {
		Types::rule::value::counter result;
		lr_capture_assign(result.quantifier, values, 0, static_cast<std::size_t>(-1));
		lr_capture_assign(result.repetitions, values, 1, static_cast<std::size_t>(-1));
		return lr_node<Types::rule::value::counter>(result);
	}
	if (rule == 100) {
		return lr_pack(values, {}, {}, {}, 1, false);
	}
	if (rule == 101) {
		return lr_pack(values, {0}, {0}, {0}, 1, false);
	}
	if (rule == 102) {
		Types::rule::value::counter::bounded result;
		lr_capture_assign(result.value, values, 1, static_cast<std::size_t>(-1));
		return lr_node<Types::rule::value::counter::bounded>(result);
	}
	if (rule == 103) {
		return lr_pack(values, {0}, {0}, {0}, 1, false);
	}
	if (rule == 104) {
		return lr_pack(values, {0}, {0}, {0}, 1, false);
	}
	if (rule == 105) {
		return lr_pack(values, {0}, {0}, {0}, 1, false);
	}
	if (rule == 106) {
		Types::rule::value::dyn result;
		lr_capture_assign(result.value, values, 1, static_cast<std::size_t>(-1));
		return lr_node<Types::rule::value::dyn>(result);
	}
	if (rule == 107) {
		return lr_pack(values, {0}, {0}, {0}, 1, false);
	}
	if (rule == 108) {
		return lr_pack(values, {0}, {0}, {0}, 1, false);
	}
	if (rule == 109) {
		Types::rule::value::dyn::dyn_expr result;
		lr_capture_assign(result.value, values, 1, static_cast<std::size_t>(-1));
		return lr_node<Types::rule::value::dyn::dyn_expr>(result);
	}
	if (rule == 110) {
		Types::rule::value::fail_capture result;
		lr_capture_assign(result.value, values, 1, static_cast<std::size_t>(-1));
		return lr_node<Types::rule::value::fail_capture>(result);
	}
	if (rule == 111) {
		return lr_pack(values, {}, {}, {}, 1, false);
	}
	if (rule == 112) {
		return lr_pack(values, {0}, {0}, {0}, 1, false);
	}
	if (rule == 113) {
		Types::rule::value::group result;
		lr_capture_assign(result.value, values, 1, static_cast<std::size_t>(-1));
		return lr_node<Types::rule::value::group>(result);
	}
	if (rule == 114) {
		return lr_pack(values, {0, 1}, {0, 0}, {0, 1}, 1, true);
	}
	if (rule == 115) {
		return lr_pack(values, {}, {}, {}, 1, true);
	}
	if (rule == 116) {
		return lr_pack(values, {0, 1}, {0, 0}, {0, 1}, 1, true);
	}
	if (rule == 117) {
		Types::rule::value::mul_capture result;
		lr_capture_assign(result.type, values, 0, static_cast<std::size_t>(-1));
		lr_capture_assign(result.cap, values, 3, static_cast<std::size_t>(-1));
		return lr_node<Types::rule::value::mul_capture>(result);
	}
	if (rule == 118) {
		return lr_pack(values, {0, 1}, {0, 0}, {0, 1}, 1, true);
	}
	if (rule == 119) {
		return lr_pack(values, {}, {}, {}, 1, true);
	}
	if (rule == 120) {
		return lr_pack(values, {0, 1}, {0, 0}, {0, 1}, 1, true);
	}
	if (rule == 121) {
		return lr_pack(values, {0}, {0}, {0}, 1, false);
	}
	if (rule == 122) {
		return lr_pack(values, {0}, {0}, {0}, 1, false);
	}
	if (rule == 123) {
		Types::rule::value::one_capture result;
		lr_capture_assign(result.v_cap, values, 0, static_cast<std::size_t>(-1));
		lr_capture_assign(result.ast_cap, values, 1, static_cast<std::size_t>(-1));
		lr_capture_assign(result.fail_cap, values, 2, static_cast<std::size_t>(-1));
		lr_capture_assign(result.val, values, 3, static_cast<std::size_t>(-1));
		lr_capture_assign(result.alts, values, 4, static_cast<std::size_t>(-1));
		lr_capture_assign(result.quantifier, values, 5, static_cast<std::size_t>(-1));
		lr_capture_assign(result.registration, values, 6, static_cast<std::size_t>(-1));
		return lr_node<Types::rule::value::one_capture>(result);
	}
	if (rule == 124) {
		return lr_pack(values, {}, {}, {}, 1, false);
	}
	if (rule == 125) {
		return lr_pack(values, {0}, {0}, {0}, 1, false);
	}
	if (rule == 126) {
		return lr_pack(values, {}, {}, {}, 1, false);
	}
	if (rule == 127) {
		return lr_pack(values, {0}, {0}, {0}, 1, false);
	}
	if (rule == 128) {
		return lr_pack(values, {}, {}, {}, 1, false);
	}
	if (rule == 129) {
		return lr_pack(values, {0}, {0}, {0}, 1, false);
	}
	if (rule == 130) {
		return lr_pack(values, {}, {}, {}, 1, false);
	}
	if (rule == 131) {
		return lr_pack(values, {0}, {0}, {0}, 1, false);
	}
	if (rule == 132) {
		return lr_pack(values, {}, {}, {}, 1, false);
	}
	if (rule == 133) {
		return lr_pack(values, {0}, {0}, {0}, 1, false);
	}
	if (rule == 134) {
		return lr_pack(values, {}, {}, {}, 1, true);
	}
	if (rule == 135) {
		return lr_pack(values, {0, 1}, {0, 0}, {0, 1}, 1, true);
	}
	if (rule == 136) {
		return lr_pack(values, {}, {}, {}, 1, true);
	}
	if (rule == 137) {
		return lr_pack(values, {0, 1}, {0, 0}, {0, 1}, 1, true);
	}
	if (rule == 138) {
		Types::rule::value::pattern result;
		lr_capture_assign(result.value, values, 0, static_cast<std::size_t>(-1));
		return lr_node<Types::rule::value::pattern>(result);
	}
	if (rule == 139) {
		Types::rule::value::pattern result;
		lr_capture_assign(result.value, values, 0, static_cast<std::size_t>(-1));
		return lr_node<Types::rule::value::pattern>(result);
	}
	if (rule == 140) {
		Types::rule::value::pattern result;
		lr_capture_assign(result.value, values, 0, static_cast<std::size_t>(-1));
		return lr_node<Types::rule::value::pattern>(result);
	}
	if (rule == 141) {
		Types::rule::value::pattern result;
		lr_capture_assign(result.value, values, 0, static_cast<std::size_t>(-1));
		return lr_node<Types::rule::value::pattern>(result);
	}
	if (rule == 142) {
		Types::rule::value::pattern result;
		lr_capture_assign(result.value, values, 0, static_cast<std::size_t>(-1));
		return lr_node<Types::rule::value::pattern>(result);
	}
	if (rule == 143) {
		Types::rule::value::pattern result;
		lr_capture_assign(result.value, values, 0, static_cast<std::size_t>(-1));
		return lr_node<Types::rule::value::pattern>(result);
	}
	if (rule == 144) {
		Types::rule::value::pattern result;
		lr_capture_assign(result.value, values, 0, static_cast<std::size_t>(-1));
		return lr_node<Types::rule::value::pattern>(result);
	}
	if (rule == 145) {
		Types::rule::value::pattern result;
		lr_capture_assign(result.value, values, 0, static_cast<std::size_t>(-1));
		return lr_node<Types::rule::value::pattern>(result);
	}
	if (rule == 146) {
		Types::rule::value::shared_counter_registration result;
		lr_capture_assign(result.value, values, 1, static_cast<std::size_t>(-1));
		return lr_node<Types::rule::value::shared_counter_registration>(result);
	}
	if (rule == 147) {
		Types::rule::value::var_capture result;
		lr_capture_assign(result.value, values, 1, static_cast<std::size_t>(-1));
		return lr_node<Types::rule::value::var_capture>(result);
	}
	if (rule == 148) {
		Types::stmt result;
		lr_capture_assign(result.value, values, 0, static_cast<std::size_t>(-1));
		return lr_node<Types::stmt>(result);
	}
	if (rule == 149) {
		Types::template_params result;
		lr_capture_assign(result.value, values, 1, static_cast<std::size_t>(-1));
		return lr_node<Types::template_params>(result);
	}
	if (rule == 150) {
		return lr_pack(values, {}, {}, {}, 1, false);
	}
	if (rule == 151) {
		return lr_pack(values, {0}, {0}, {0}, 1, false);
	}
	throw std::runtime_error("Invalid LR table entry or unexpected token");
}
auto Parser::Parser::lr_shift(const Token& token) -> std::any {
	if (token.kind() == Tokens::__WS::id) {
		return lr_token(token.template to_node<Types::__WS>());
	}
	if (token.kind() == Tokens::advanced_rule::dep_decl::DEPENDS::id) {
		return lr_token(token.template to_node<Types::advanced_rule::dep_decl::DEPENDS>());
	}
	if (token.kind() == Tokens::AUTO::id) {
		return lr_token(token.template to_node<Types::AUTO>());
	}
	if (token.kind() == Tokens::FAIL::id) {
		return lr_token(token.template to_node<Types::FAIL>());
	}
	if (token.kind() == Tokens::SEMICOLON::id) {
		return lr_token(token.template to_node<Types::SEMICOLON>());
	}
	if (token.kind() == Tokens::COLON::id) {
		return lr_token(token.template to_node<Types::COLON>());
	}
	if (token.kind() == Tokens::EQUALS_SIGN::id) {
		return lr_token(token.template to_node<Types::EQUALS_SIGN>());
	}
	if (token.kind() == Tokens::AMPERSAND::id) {
		return lr_token(token.template to_node<Types::AMPERSAND>());
	}
	if (token.kind() == Tokens::PERCENT_SIGN::id) {
		return lr_token(token.template to_node<Types::PERCENT_SIGN>());
	}
	if (token.kind() == Tokens::rule::nested_rule::NUMBER_SIGN::id) {
		return lr_token(token.template to_node<Types::rule::nested_rule::NUMBER_SIGN>());
	}
	if (token.kind() == Tokens::LEFT_CURLY_BRACKET::id) {
		return lr_token(token.template to_node<Types::LEFT_CURLY_BRACKET>());
	}
	if (token.kind() == Tokens::rule::value::shared_counter_registration::AUTO::id) {
		return lr_token(token.template to_node<Types::rule::value::shared_counter_registration::AUTO>());
	}
	if (token.kind() == Tokens::COMMERCIAL_AT::id) {
		return lr_token(token.template to_node<Types::COMMERCIAL_AT>());
	}
	if (token.kind() == Tokens::rule::value::QUANTIFIER::id) {
		return lr_token(token.template to_node<Types::rule::value::QUANTIFIER>());
	}
	if (token.kind() == Tokens::rule::value::NOSPACE::id) {
		return lr_token(token.template to_node<Types::rule::value::NOSPACE>());
	}
	if (token.kind() == Tokens::rule::value::ANY::id) {
		return lr_token(token.template to_node<Types::rule::value::ANY>());
	}
	if (token.kind() == Tokens::template_params::LESS_THAN_SIGN::id) {
		return lr_token(token.template to_node<Types::template_params::LESS_THAN_SIGN>());
	}
	if (token.kind() == Tokens::rule::value::STRING::id) {
		return lr_token(token.template to_node<Types::rule::value::STRING>());
	}
	if (token.kind() == Tokens::grammar::modifier::AUTO::id) {
		return lr_token(token.template to_node<Types::grammar::modifier::AUTO>());
	}
	if (token.kind() == Tokens::grammar::modifier::MOD::id) {
		return lr_token(token.template to_node<Types::grammar::modifier::MOD>());
	}
	if (token.kind() == Tokens::rule::value::SPACE::id) {
		return lr_token(token.template to_node<Types::rule::value::SPACE>());
	}
	if (token.kind() == Tokens::template_params::GREATER_THAN_SIGN::id) {
		return lr_token(token.template to_node<Types::template_params::GREATER_THAN_SIGN>());
	}
	if (token.kind() == Tokens::rule::value::alternative::VERTICAL_LINE::id) {
		return lr_token(token.template to_node<Types::rule::value::alternative::VERTICAL_LINE>());
	}
	if (token.kind() == Tokens::grammar::modifier::RIGHT_SQUARE_BRACKET::id) {
		return lr_token(token.template to_node<Types::grammar::modifier::RIGHT_SQUARE_BRACKET>());
	}
	if (token.kind() == Tokens::rule::value::dyn::DOLLAR_SIGN::id) {
		return lr_token(token.template to_node<Types::rule::value::dyn::DOLLAR_SIGN>());
	}
	if (token.kind() == Tokens::advanced_rule::regular_match::MATCH::id) {
		return lr_token(token.template to_node<Types::advanced_rule::regular_match::MATCH>());
	}
	if (token.kind() == Tokens::COMMA::id) {
		return lr_token(token.template to_node<Types::COMMA>());
	}
	if (token.kind() == Tokens::RIGHT_PARENTHESIS::id) {
		return lr_token(token.template to_node<Types::RIGHT_PARENTHESIS>());
	}
	if (token.kind() == Tokens::LEFT_PARENTHESIS::id) {
		return lr_token(token.template to_node<Types::LEFT_PARENTHESIS>());
	}
	if (token.kind() == Tokens::RIGHT_CURLY_BRACKET::id) {
		return lr_token(token.template to_node<Types::RIGHT_CURLY_BRACKET>());
	}
	if (token.kind() == Tokens::NUMBER::id) {
		return lr_token(token.template to_node<Types::NUMBER>());
	}
	if (token.kind() == Tokens::PY_RAW::id) {
		return lr_token(token.template to_node<Types::PY_RAW>());
	}
	if (token.kind() == Tokens::ID::id) {
		return lr_token(token.template to_node<Types::ID>());
	}
	if (token.kind() == Tokens::rule::value::CGROUP::id) {
		return lr_token(token.template to_node<Types::rule::value::CGROUP>());
	}
	throw std::runtime_error("Invalid LR table entry or unexpected token");
}
template<typename IT, class> auto Parser::Parser::main(IT pos) -> ::ISPA_STD::MatchResult<Types::main, IT> {
	return lr_parse_generalized<Parser>(pos);
}
template auto Parser::Parser::main<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::main, ::Parser::Lexer::iterator>;
template auto Parser::Parser::main<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::main, ::Parser::Lexer::lazy_iterator>;
auto Parser::Parser::parseFromTokens() -> void {
	tree = main(Lexer::iterator(lexer)).node.data();
}
auto Parser::Parser::lazyParse() -> void {
	Lexer lexer;
	tree = main(Lexer::lazy_iterator(lexer, text)).node.data();
}
