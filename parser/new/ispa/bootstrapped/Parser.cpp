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
auto Parser::FlatTypes::rule_value_counter_bounded_EQUALS_SIGN::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("rule_value_counter_bounded_EQUALS_SIGN", true);
}
auto Parser::FlatTypes::rule_value_counter_bounded_EQUALS_SIGN::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::rule_value_counter_bounded_EQUALS_SIGN::to_string() const -> std::string {
	return ::ISPA_STD::concat("rule_value_counter_bounded_EQUALS_SIGN {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, rule_value_counter_bounded_EQUALS_SIGN value) -> std::ostream & {
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
	printer.subtree("value", value, true);
	printer.down();
}
auto Parser::FlatTypes::rule_ast_abbr::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::rule_ast_abbr::to_string() const -> std::string {
	return ::ISPA_STD::concat("rule_ast_abbr {", "value = ", value, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, rule_ast_abbr value) -> std::ostream & {
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
auto Parser::FlatTypes::rule_value::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("rule_value", false);
	printer.up(false);
	printer.node("v_cap", false);
	printer.up(true);
	v_cap.print(printer);
	printer.down();
	printer.node("ast_cap", false);
	printer.up(true);
	ast_cap.print(printer);
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
auto Parser::FlatTypes::rule_value::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::rule_value::to_string() const -> std::string {
	return ::ISPA_STD::concat("rule_value {", "v_cap = ", v_cap.to_string(), ", ", "ast_cap = ", ast_cap.to_string(), ", ", "val = ", val.to_string(), ", ", "alts = ", alts, ", ", "quantifier = ", quantifier.to_string(), ", ", "registration = ", registration.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, rule_value value) -> std::ostream & {
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
auto Parser::FlatTypes::rule::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("rule", false);
	printer.up(false);
	printer.subtree("v", v, false);
	printer.node("data", false);
	printer.up(true);
	data.print(printer);
	printer.down();
	printer.subtree("nested", nested, true);
	printer.down();
}
auto Parser::FlatTypes::rule::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::rule::to_string() const -> std::string {
	return ::ISPA_STD::concat("rule {", "v = ", v, ", ", "data = ", data.to_string(), ", ", "nested = ", nested, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, rule value) -> std::ostream & {
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
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::__WS, Types::__WS{}));
			break;
		}
		case 1: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::rule_nested_rule_NUMBER_SIGN, Types::rule::nested_rule::NUMBER_SIGN{}));
			break;
		}
		case 2: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::rule_value_dyn_DOLLAR_SIGN, Types::rule::value::dyn::DOLLAR_SIGN{}));
			break;
		}
		case 3: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::AMPERSAND, Types::AMPERSAND{}));
			break;
		}
		case 4: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::LEFT_PARENTHESIS, Types::LEFT_PARENTHESIS{}));
			break;
		}
		case 5: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::RIGHT_PARENTHESIS, Types::RIGHT_PARENTHESIS{}));
			break;
		}
		case 6: {
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
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::rule_value_QUANTIFIER, Types::rule::value::QUANTIFIER{value}));
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
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::rule_value_QUANTIFIER, Types::rule::value::QUANTIFIER{value}));
			break;
		}
		case 8: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::COMMA, Types::COMMA{}));
			break;
		}
		case 9: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::rule_value_ANY, Types::rule::value::ANY{}));
			break;
		}
		case 10: {
			std::string floating = captures.text(12);
			std::string full = captures.text(11);
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::NUMBER, Types::NUMBER{full, floating}));
			break;
		}
		case 11: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::COLON, Types::COLON{}));
			break;
		}
		case 12: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::SEMICOLON, Types::SEMICOLON{}));
			break;
		}
		case 13: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::template_params_LESS_THAN_SIGN, Types::template_params::LESS_THAN_SIGN{}));
			break;
		}
		case 14: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::rule_value_counter_bounded_EQUALS_SIGN, Types::rule::value::counter::bounded::EQUALS_SIGN{}));
			break;
		}
		case 15: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::template_params_GREATER_THAN_SIGN, Types::template_params::GREATER_THAN_SIGN{}));
			break;
		}
		case 16: {
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
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::rule_value_QUANTIFIER, Types::rule::value::QUANTIFIER{value}));
			break;
		}
		case 17: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::COMMERCIAL_AT, Types::COMMERCIAL_AT{}));
			break;
		}
		case 18: {
			std::string value = captures.text(0);
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::ID, Types::ID{value}));
			break;
		}
		case 19: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::grammar_modifier_RIGHT_SQUARE_BRACKET, Types::grammar::modifier::RIGHT_SQUARE_BRACKET{}));
			break;
		}
		case 20: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::LEFT_CURLY_BRACKET, Types::LEFT_CURLY_BRACKET{}));
			break;
		}
		case 21: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::rule_value_alternative_VERTICAL_LINE, Types::rule::value::alternative::VERTICAL_LINE{}));
			break;
		}
		case 22: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::RIGHT_CURLY_BRACKET, Types::RIGHT_CURLY_BRACKET{}));
			break;
		}
		case 23: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::grammar_modifier_AUTO, Types::grammar::modifier::AUTO{}));
			break;
		}
		case 24: {
			std::string value = captures.text(10);
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::rule_value_STRING, Types::rule::value::STRING{value}));
			break;
		}
		case 25: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::AUTO, Types::AUTO{}));
			break;
		}
		case 26: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::rule_value_shared_counter_registration_AUTO, Types::rule::value::shared_counter_registration::AUTO{}));
			break;
		}
		case 27: {
			std::string value = captures.text(0);
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::ID, Types::ID{value}));
			break;
		}
		case 28: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::rule_value_SPACE, Types::rule::value::SPACE{}));
			break;
		}
		case 29: {
			std::string floating = captures.text(12);
			std::string full = captures.text(11);
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::NUMBER, Types::NUMBER{full, floating}));
			break;
		}
		case 30: {
			char negative = captures.character(2);
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::rule_value_CGROUP, Types::rule::value::CGROUP{negative}));
			break;
		}
		case 31: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::rule_value_NOSPACE, Types::rule::value::NOSPACE{}));
			break;
		}
		case 32: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::FAIL, Types::FAIL{}));
			break;
		}
		case 33: {
			std::string value;
			if (captures.is_set(7)) {
				value = captures.text(7);
			} else {
				if (captures.is_set(9)) {
					value = captures.text(9);
				} else {
					if (captures.is_set(8)) {
						value = captures.text(8);
					}
				}
			}
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::grammar_modifier_MOD, Types::grammar::modifier::MOD{value}));
			break;
		}
		case 34: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::advanced_rule_regular_match_MATCH, Types::advanced_rule::regular_match::MATCH{}));
			break;
		}
		case 35: {
			std::string value = captures.text(1);
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::PY_RAW, Types::PY_RAW{value}));
			break;
		}
		case 36: {
			std::string value;
			if (captures.is_set(7)) {
				value = captures.text(7);
			} else {
				if (captures.is_set(9)) {
					value = captures.text(9);
				} else {
					if (captures.is_set(8)) {
						value = captures.text(8);
					}
				}
			}
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::grammar_modifier_MOD, Types::grammar::modifier::MOD{value}));
			break;
		}
		case 37: {
			std::string value;
			if (captures.is_set(7)) {
				value = captures.text(7);
			} else {
				if (captures.is_set(9)) {
					value = captures.text(9);
				} else {
					if (captures.is_set(8)) {
						value = captures.text(8);
					}
				}
			}
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::grammar_modifier_MOD, Types::grammar::modifier::MOD{value}));
			break;
		}
		case 38: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::advanced_rule_dep_decl_DEPENDS, Types::advanced_rule::dep_decl::DEPENDS{}));
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
::ISPA_STD::DFA::API::CharToClass Parser::Lexer::char_class_table = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128};
::ISPA_STD::DFA::API::Table<83, 129> Parser::Lexer::dfa_table = {{{::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, 1, 1, 1, 1, 1, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, 1, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, 2, 3, ::ISPA_STD::DFA::API::null_state, 4, 5, 6, 7, 138, 137, 10, 11, 12, ::ISPA_STD::DFA::API::null_state, 136, 135, 134, 133, 132, 131, 130, 129, 146, 145, 14, 15, 16, 17, 18, 139, 20, 128, 127, 126, 125, 124, 123, 100, 98, 96, 93, 90, 87, 85, 83, 147, 122, 121, 120, 119, 118, 117, 116, 115, 114, 113, 112, 22, 23, 24, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, 111, 94, 91, 88, 86, 84, 110, 109, 108, 142, 141, 144, 143, 140, 107, 106, 105, 104, 103, 102, 101, 99, 97, 95, 92, 89, 32, 33, 34, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state}, {677, 677, 677, 677, 677, 677, 677, 677, 677, 1, 1, 1, 1, 1, 677, 677, 677, 677, 677, 677, 677, 677, 677, 677, 677, 677, 677, 677, 677, 677, 677, 677, 1, 677, 677, 677, 677, 677, 677, 677, 677, 677, 677, 677, 677, 677, 677, 677, 677, 677, 677, 677, 677, 677, 677, 677, 677, 677, 677, 677, 677, 677, 677, 677, 677, 677, 677, 677, 677, 677, 677, 677, 677, 677, 677, 677, 677, 677, 677, 677, 677, 677, 677, 677, 677, 677, 677, 677, 677, 677, 677, 677, 677, 677, 677, 677, 677, 677, 677, 677, 677, 677, 677, 677, 677, 677, 677, 677, 677, 677, 677, 677, 677, 677, 677, 677, 677, 677, 677, 677, 677, 677, 677, 677, 677, 677, 677, 677, 677}, {678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 35, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678, 678}, {679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679, 679}, {680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680}, {274, 273, 272, 271, 270, 269, 268, 267, 266, 265, 264, 263, 262, 261, 260, 259, 258, 257, 256, 255, 254, 253, 252, 251, 250, 249, 248, 247, 246, 245, 244, 243, 242, 241, 240, 239, 238, 237, 236, 37, 235, 234, 233, 232, 231, 230, 229, 228, 227, 226, 225, 224, 223, 222, 221, 220, 219, 218, 217, 216, 215, 214, 213, 212, 211, 210, 209, 208, 207, 206, 205, 204, 203, 202, 201, 200, 199, 198, 197, 196, 195, 194, 193, 192, 191, 190, 189, 188, 187, 186, 185, 184, 183, 182, 181, 180, 179, 178, 177, 176, 175, 174, 173, 172, 171, 170, 169, 168, 167, 166, 165, 164, 163, 162, 161, 160, 159, 158, 157, 156, 155, 154, 153, 152, 151, 150, 149, 148, ::ISPA_STD::DFA::API::null_state}, {681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681}, {682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682, 682}, {275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275, 275}, {276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276}, {685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685, 685}, {::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, 39, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state}, {686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686}, {277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 278, 277, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277, 277}, {688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688, 688}, {689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689, 689}, {690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690, 690}, {691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 41, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691}, {692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692, 692}, {279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279}, {694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694, 694}, {280, 280, 280, 280, 280, 280, 280, 280, 280, 280, 280, 280, 280, 280, 280, 280, 280, 280, 280, 280, 280, 280, 280, 280, 280, 280, 280, 280, 280, 280, 280, 280, 280, 280, 280, 280, 280, 280, 280, 280, 280, 280, 280, 280, 280, 280, 280, 280, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 280, 280, 280, 280, 280, 280, 280, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 280, 280, 280, 280, 42, 280, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 280, 280, 280, 280, 280, 280}, {397, 403, 405, 396, 401, 399, 394, 393, 392, 406, 391, 390, 389, 388, 387, 386, 385, 384, 383, 382, 381, 380, 379, 378, 377, 376, 375, 374, 373, 285, 282, 372, 371, 370, 369, 368, 367, 366, 365, 364, 363, 362, 361, 360, 359, 358, 357, 407, 356, 355, 354, 353, 352, 351, 350, 349, 348, 347, 346, 345, 344, 343, 342, 341, 340, 339, 338, 337, 336, 335, 334, 333, 332, 331, 330, 329, 328, 327, 326, 286, 283, 325, 324, 323, 322, 321, 320, 319, 318, 317, 316, 315, 314, ::ISPA_STD::DFA::API::null_state, 313, 312, 311, 398, 402, 404, 395, 400, 310, 309, 308, 307, 306, 305, 304, 303, 302, 301, 300, 299, 298, 297, 296, 295, 294, 293, 292, 291, 290, 289, 288, 287, 284, 281, ::ISPA_STD::DFA::API::null_state}, {::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, 46, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state}, {696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696, 696}, {409, 409, 409, 409, 409, 409, 409, 409, 409, 409, 409, 409, 409, 409, 409, 409, 409, 409, 409, 409, 409, 409, 409, 409, 409, 409, 409, 409, 409, 409, 409, 409, 409, 409, 409, 409, 409, 409, 409, 409, 409, 409, 409, 409, 409, 409, 409, 409, 467, 470, 462, 461, 458, 455, 453, 452, 450, 448, 409, 409, 409, 409, 409, 409, 409, 427, 424, 422, 420, 418, 416, 471, 469, 466, 464, 465, 457, 454, 446, 445, 444, 443, 442, 441, 440, 439, 434, 432, 430, 428, 425, 409, 409, 409, 409, 468, 409, 463, 460, 459, 456, 47, 451, 449, 447, 438, 437, 436, 435, 433, 431, 429, 426, 423, 421, 419, 417, 415, 414, 413, 412, 411, 410, 409, 409, 409, 409, 409, 409}, {473, 473, 473, 473, 473, 473, 473, 473, 473, 473, 473, 473, 473, 473, 473, 473, 473, 473, 473, 473, 473, 473, 473, 473, 473, 473, 473, 473, 473, 473, 473, 473, 473, 473, 473, 473, 473, 473, 473, 473, 473, 473, 473, 473, 473, 473, 473, 473, 467, 470, 462, 461, 458, 455, 453, 452, 450, 448, 473, 473, 473, 473, 473, 473, 473, 427, 424, 422, 420, 418, 416, 471, 469, 466, 464, 465, 457, 454, 446, 445, 444, 443, 442, 441, 440, 439, 434, 432, 430, 428, 425, 473, 473, 473, 473, 468, 473, 463, 460, 459, 456, 474, 451, 449, 447, 438, 437, 436, 435, 433, 431, 429, 426, 423, 421, 419, 417, 415, 414, 413, 48, 411, 410, 473, 473, 473, 473, 473, 473}, {476, 476, 476, 476, 476, 476, 476, 476, 476, 476, 476, 476, 476, 476, 476, 476, 476, 476, 476, 476, 476, 476, 476, 476, 476, 476, 476, 476, 476, 476, 476, 476, 476, 476, 476, 476, 476, 476, 476, 476, 476, 476, 476, 476, 476, 476, 476, 476, 467, 470, 462, 461, 458, 455, 453, 452, 450, 448, 476, 476, 476, 476, 476, 476, 476, 427, 424, 422, 420, 418, 416, 471, 469, 466, 464, 465, 457, 454, 446, 445, 444, 443, 442, 441, 440, 439, 434, 432, 430, 428, 425, 476, 476, 476, 476, 468, 476, 49, 460, 459, 456, 474, 451, 449, 447, 438, 437, 436, 435, 433, 431, 429, 426, 423, 421, 419, 417, 415, 414, 413, 412, 411, 410, 476, 476, 476, 476, 476, 476}, {478, 478, 478, 478, 478, 478, 478, 478, 478, 478, 478, 478, 478, 478, 478, 478, 478, 478, 478, 478, 478, 478, 478, 478, 478, 478, 478, 478, 478, 478, 478, 478, 478, 478, 478, 478, 478, 478, 478, 478, 478, 478, 478, 478, 478, 478, 478, 478, 467, 470, 462, 461, 458, 455, 453, 452, 450, 448, 478, 478, 478, 478, 478, 478, 478, 427, 424, 422, 420, 418, 416, 471, 469, 466, 464, 465, 457, 454, 446, 445, 444, 443, 442, 441, 440, 439, 434, 432, 430, 428, 425, 478, 478, 478, 478, 468, 478, 463, 460, 459, 456, 474, 451, 449, 447, 438, 437, 436, 435, 433, 50, 429, 426, 423, 421, 419, 417, 415, 414, 413, 412, 411, 410, 478, 478, 478, 478, 478, 478}, {480, 480, 480, 480, 480, 480, 480, 480, 480, 480, 480, 480, 480, 480, 480, 480, 480, 480, 480, 480, 480, 480, 480, 480, 480, 480, 480, 480, 480, 480, 480, 480, 480, 480, 480, 480, 480, 480, 480, 480, 480, 480, 480, 480, 480, 480, 480, 480, 467, 470, 462, 461, 458, 455, 453, 452, 450, 448, 480, 480, 480, 480, 480, 480, 480, 427, 424, 422, 420, 418, 416, 471, 469, 466, 464, 465, 457, 454, 446, 445, 444, 443, 442, 441, 440, 439, 434, 432, 430, 428, 425, 480, 480, 480, 480, 468, 480, 51, 460, 459, 456, 474, 451, 449, 447, 438, 437, 436, 435, 433, 431, 429, 426, 423, 421, 419, 417, 415, 414, 413, 412, 411, 410, 480, 480, 480, 480, 480, 480}, {482, 482, 482, 482, 482, 482, 482, 482, 482, 482, 482, 482, 482, 482, 482, 482, 482, 482, 482, 482, 482, 482, 482, 482, 482, 482, 482, 482, 482, 482, 482, 482, 482, 482, 482, 482, 482, 482, 482, 482, 482, 482, 482, 482, 482, 482, 482, 482, 467, 470, 462, 461, 458, 455, 453, 452, 450, 448, 482, 482, 482, 482, 482, 482, 482, 427, 424, 422, 420, 418, 416, 471, 469, 466, 464, 465, 457, 454, 446, 445, 444, 443, 442, 441, 440, 439, 434, 432, 430, 428, 425, 482, 482, 482, 482, 468, 482, 463, 460, 459, 456, 474, 451, 449, 447, 438, 437, 436, 435, 433, 431, 429, 426, 423, 421, 419, 417, 415, 414, 413, 412, 411, 410, 52, 482, 482, 482, 482, 482}, {484, 484, 484, 484, 484, 484, 484, 484, 484, 484, 484, 484, 484, 484, 484, 484, 484, 484, 484, 484, 484, 484, 484, 484, 484, 484, 484, 484, 484, 484, 484, 484, 484, 484, 484, 484, 484, 484, 484, 484, 484, 484, 484, 484, 484, 484, 484, 484, 467, 470, 462, 461, 458, 455, 453, 452, 450, 448, 484, 484, 484, 484, 484, 484, 484, 427, 424, 422, 420, 418, 416, 471, 469, 466, 464, 465, 457, 454, 446, 445, 444, 443, 442, 441, 440, 439, 434, 432, 430, 428, 425, 484, 484, 484, 484, 468, 484, 463, 460, 459, 456, 474, 451, 449, 447, 438, 437, 53, 435, 433, 431, 429, 426, 423, 421, 419, 417, 415, 414, 413, 412, 411, 410, 484, 484, 484, 484, 484, 484}, {697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697, 697}, {698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698, 698}, {699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699, 699}, {700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700}, {36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 485, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 38, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, ::ISPA_STD::DFA::API::null_state}, {701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701, 701}, {36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, ::ISPA_STD::DFA::API::null_state}, {702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702, 702}, {::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, 495, 494, 493, 492, 491, 490, 489, 488, 487, 486, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state}, {703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703, 703}, {496, 496, 496, 496, 496, 496, 496, 496, 496, 496, 496, 496, 496, 496, 496, 496, 496, 496, 496, 496, 496, 496, 496, 496, 496, 496, 496, 496, 496, 496, 496, 496, 496, 496, 496, 496, 496, 496, 496, 496, 496, 496, 496, 496, 496, 496, 496, 496, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 496, 496, 496, 496, 496, 496, 496, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 496, 496, 496, 496, 42, 496, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 496, 496, 496, 496, 496, 496}, {43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 44, 497, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, ::ISPA_STD::DFA::API::null_state}, {43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, ::ISPA_STD::DFA::API::null_state}, {624, 623, 622, 621, 620, 619, 618, 617, 616, 615, 614, 613, 612, 611, 610, 609, 608, 607, 606, 605, 604, 603, 602, 601, 600, 599, 598, 597, 596, 595, 594, 593, 592, 591, 590, 589, 588, 587, 586, 585, 584, 583, 582, 581, 580, 579, 578, 577, 576, 575, 574, 573, 572, 571, 570, 569, 568, 567, 566, 565, 564, 563, 562, 561, 560, 559, 558, 557, 556, 555, 554, 553, 552, 551, 550, 549, 548, 547, 546, 545, 544, 543, 542, 541, 540, 539, 538, 537, 536, 535, 534, 533, 532, 497, 531, 530, 529, 528, 527, 526, 525, 524, 523, 522, 521, 520, 519, 518, 517, 516, 515, 514, 513, 512, 511, 510, 509, 508, 507, 506, 505, 504, 503, 502, 501, 500, 499, 498, ::ISPA_STD::DFA::API::null_state}, {705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 58, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705, 705}, {626, 626, 626, 626, 626, 626, 626, 626, 626, 626, 626, 626, 626, 626, 626, 626, 626, 626, 626, 626, 626, 626, 626, 626, 626, 626, 626, 626, 626, 626, 626, 626, 626, 626, 626, 626, 626, 626, 626, 626, 626, 626, 626, 626, 626, 626, 626, 626, 467, 470, 462, 461, 458, 455, 453, 452, 450, 448, 626, 626, 626, 626, 626, 626, 626, 427, 424, 422, 420, 418, 416, 471, 469, 466, 464, 465, 457, 454, 446, 445, 444, 443, 442, 441, 440, 439, 434, 432, 430, 428, 425, 626, 626, 626, 626, 468, 626, 463, 460, 459, 456, 474, 451, 449, 447, 438, 437, 436, 435, 433, 431, 429, 59, 423, 421, 419, 417, 415, 414, 413, 412, 411, 410, 626, 626, 626, 626, 626, 626}, {628, 628, 628, 628, 628, 628, 628, 628, 628, 628, 628, 628, 628, 628, 628, 628, 628, 628, 628, 628, 628, 628, 628, 628, 628, 628, 628, 628, 628, 628, 628, 628, 628, 628, 628, 628, 628, 628, 628, 628, 628, 628, 628, 628, 628, 628, 628, 628, 467, 470, 462, 461, 458, 455, 453, 452, 450, 448, 628, 628, 628, 628, 628, 628, 628, 427, 424, 422, 420, 418, 416, 471, 469, 466, 464, 465, 457, 454, 446, 445, 444, 443, 442, 441, 440, 439, 434, 432, 430, 428, 425, 628, 628, 628, 628, 468, 628, 463, 460, 459, 456, 474, 451, 449, 447, 438, 437, 436, 435, 433, 431, 429, 426, 423, 421, 419, 60, 415, 414, 413, 412, 411, 410, 628, 628, 628, 628, 628, 628}, {630, 630, 630, 630, 630, 630, 630, 630, 630, 630, 630, 630, 630, 630, 630, 630, 630, 630, 630, 630, 630, 630, 630, 630, 630, 630, 630, 630, 630, 630, 630, 630, 630, 630, 630, 630, 630, 630, 630, 630, 630, 630, 630, 630, 630, 630, 630, 630, 467, 470, 462, 461, 458, 455, 453, 452, 450, 448, 630, 630, 630, 630, 630, 630, 630, 427, 424, 422, 420, 418, 416, 471, 469, 466, 464, 465, 457, 454, 446, 445, 444, 443, 442, 441, 440, 439, 434, 432, 430, 428, 425, 630, 630, 630, 630, 468, 630, 463, 460, 459, 456, 474, 451, 449, 447, 61, 437, 436, 435, 433, 431, 429, 426, 423, 421, 419, 417, 415, 414, 413, 412, 411, 410, 630, 630, 630, 630, 630, 630}, {632, 632, 632, 632, 632, 632, 632, 632, 632, 632, 632, 632, 632, 632, 632, 632, 632, 632, 632, 632, 632, 632, 632, 632, 632, 632, 632, 632, 632, 632, 632, 632, 632, 632, 632, 632, 632, 632, 632, 632, 632, 632, 632, 632, 632, 632, 632, 632, 467, 470, 462, 461, 458, 455, 453, 452, 450, 448, 632, 632, 632, 632, 632, 632, 632, 427, 424, 422, 420, 418, 416, 471, 469, 466, 464, 465, 457, 454, 446, 445, 444, 443, 442, 441, 440, 439, 434, 432, 430, 428, 425, 632, 632, 632, 632, 468, 632, 463, 460, 459, 456, 474, 451, 449, 447, 438, 437, 436, 62, 433, 431, 429, 426, 423, 421, 419, 417, 415, 414, 413, 412, 411, 410, 632, 632, 632, 632, 632, 632}, {634, 634, 634, 634, 634, 634, 634, 634, 634, 634, 634, 634, 634, 634, 634, 634, 634, 634, 634, 634, 634, 634, 634, 634, 634, 634, 634, 634, 634, 634, 634, 634, 634, 634, 634, 634, 634, 634, 634, 634, 634, 634, 634, 634, 634, 634, 634, 634, 467, 470, 462, 461, 458, 455, 453, 452, 450, 448, 634, 634, 634, 634, 634, 634, 634, 427, 424, 422, 420, 418, 416, 471, 469, 466, 464, 465, 457, 454, 446, 445, 444, 443, 442, 441, 440, 439, 434, 432, 430, 428, 425, 634, 634, 634, 634, 468, 634, 463, 460, 459, 456, 474, 451, 449, 447, 438, 437, 436, 435, 433, 431, 429, 426, 423, 421, 419, 63, 415, 414, 413, 412, 411, 410, 634, 634, 634, 634, 634, 634}, {::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, 635, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state}, {637, 637, 637, 637, 637, 637, 637, 637, 637, 637, 637, 637, 637, 637, 637, 637, 637, 637, 637, 637, 637, 637, 637, 637, 637, 637, 637, 637, 637, 637, 637, 637, 637, 637, 637, 637, 637, 637, 637, 637, 637, 637, 637, 637, 637, 637, 637, 637, 467, 470, 462, 461, 458, 455, 453, 452, 450, 448, 637, 637, 637, 637, 637, 637, 637, 427, 424, 422, 420, 418, 416, 471, 469, 466, 464, 465, 457, 454, 446, 445, 444, 443, 442, 441, 440, 439, 434, 432, 430, 428, 425, 637, 637, 637, 637, 468, 637, 463, 460, 459, 456, 474, 451, 449, 447, 65, 437, 436, 435, 433, 431, 429, 426, 423, 421, 419, 417, 415, 414, 413, 412, 411, 410, 637, 637, 637, 637, 637, 637}, {638, 638, 638, 638, 638, 638, 638, 638, 638, 638, 638, 638, 638, 638, 638, 638, 638, 638, 638, 638, 638, 638, 638, 638, 638, 638, 638, 638, 638, 638, 638, 638, 638, 638, 638, 638, 638, 638, 638, 638, 638, 638, 638, 638, 638, 638, 638, 638, 54, 54, 54, 54, 54, 54, 54, 54, 54, 54, 638, 638, 638, 638, 638, 638, 638, 638, 638, 638, 638, 638, 638, 638, 638, 638, 638, 638, 638, 638, 638, 638, 638, 638, 638, 638, 638, 638, 638, 638, 638, 638, 638, 638, 638, 638, 638, 638, 638, 638, 638, 638, 638, 638, 638, 638, 638, 638, 638, 638, 638, 638, 638, 638, 638, 638, 638, 638, 638, 638, 638, 638, 638, 638, 638, 638, 638, 638, 638, 638, 638}, {707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707, 707}, {56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 57, 639, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, ::ISPA_STD::DFA::API::null_state}, {56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, ::ISPA_STD::DFA::API::null_state}, {708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708, 708}, {641, 641, 641, 641, 641, 641, 641, 641, 641, 641, 641, 641, 641, 641, 641, 641, 641, 641, 641, 641, 641, 641, 641, 641, 641, 641, 641, 641, 641, 641, 641, 641, 641, 641, 641, 641, 641, 641, 641, 641, 641, 641, 641, 641, 641, 641, 641, 641, 467, 470, 462, 461, 458, 455, 453, 452, 450, 448, 641, 641, 641, 641, 641, 641, 641, 427, 424, 422, 420, 418, 416, 471, 469, 466, 464, 465, 457, 454, 446, 445, 444, 443, 442, 441, 440, 439, 434, 432, 430, 428, 425, 641, 641, 641, 641, 468, 641, 463, 460, 459, 456, 67, 451, 449, 447, 438, 437, 436, 435, 433, 431, 429, 426, 423, 421, 419, 417, 415, 414, 413, 412, 411, 410, 641, 641, 641, 641, 641, 641}, {643, 643, 643, 643, 643, 643, 643, 643, 643, 643, 643, 643, 643, 643, 643, 643, 643, 643, 643, 643, 643, 643, 643, 643, 643, 643, 643, 643, 643, 643, 643, 643, 643, 643, 643, 643, 643, 643, 643, 643, 643, 643, 643, 643, 643, 643, 643, 643, 467, 470, 462, 461, 458, 455, 453, 452, 450, 448, 643, 643, 643, 643, 643, 643, 643, 427, 424, 422, 420, 418, 416, 471, 469, 466, 464, 465, 457, 454, 446, 445, 444, 443, 442, 441, 440, 439, 434, 432, 430, 428, 425, 643, 643, 643, 643, 468, 643, 463, 460, 459, 456, 68, 451, 449, 447, 438, 437, 436, 435, 433, 431, 429, 426, 423, 421, 419, 417, 415, 414, 413, 412, 411, 410, 643, 643, 643, 643, 643, 643}, {645, 645, 645, 645, 645, 645, 645, 645, 645, 645, 645, 645, 645, 645, 645, 645, 645, 645, 645, 645, 645, 645, 645, 645, 645, 645, 645, 645, 645, 645, 645, 645, 645, 645, 645, 645, 645, 645, 645, 645, 645, 645, 645, 645, 645, 645, 645, 645, 467, 470, 462, 461, 458, 455, 453, 452, 450, 448, 645, 645, 645, 645, 645, 645, 645, 427, 424, 422, 420, 418, 416, 471, 469, 466, 464, 465, 457, 454, 446, 445, 444, 443, 442, 441, 440, 439, 434, 432, 430, 428, 425, 645, 645, 645, 645, 468, 645, 463, 460, 459, 456, 474, 451, 449, 447, 438, 437, 436, 69, 433, 431, 429, 426, 423, 421, 419, 417, 415, 414, 413, 412, 411, 410, 645, 645, 645, 645, 645, 645}, {647, 647, 647, 647, 647, 647, 647, 647, 647, 647, 647, 647, 647, 647, 647, 647, 647, 647, 647, 647, 647, 647, 647, 647, 647, 647, 647, 647, 647, 647, 647, 647, 647, 647, 647, 647, 647, 647, 647, 647, 647, 647, 647, 647, 647, 647, 647, 647, 467, 470, 462, 461, 458, 455, 453, 452, 450, 448, 647, 647, 647, 647, 647, 647, 647, 427, 424, 422, 420, 418, 416, 471, 469, 466, 464, 465, 457, 454, 446, 445, 444, 443, 442, 441, 440, 439, 434, 432, 430, 428, 425, 647, 647, 647, 647, 468, 647, 463, 460, 459, 456, 474, 451, 449, 447, 70, 437, 436, 435, 433, 431, 429, 426, 423, 421, 419, 417, 415, 414, 413, 412, 411, 410, 647, 647, 647, 647, 647, 647}, {649, 649, 649, 649, 649, 649, 649, 649, 649, 649, 649, 649, 649, 649, 649, 649, 649, 649, 649, 649, 649, 649, 649, 649, 649, 649, 649, 649, 649, 649, 649, 649, 649, 649, 649, 649, 649, 649, 649, 649, 649, 649, 649, 649, 649, 649, 649, 649, 467, 470, 462, 461, 458, 455, 453, 452, 450, 448, 649, 649, 649, 649, 649, 649, 649, 427, 424, 422, 420, 418, 416, 471, 469, 466, 464, 465, 457, 454, 446, 445, 444, 443, 442, 441, 440, 439, 434, 432, 430, 428, 425, 649, 649, 649, 649, 468, 649, 463, 460, 71, 456, 474, 451, 449, 447, 438, 437, 436, 435, 433, 431, 429, 426, 423, 421, 419, 417, 415, 414, 413, 412, 411, 410, 649, 649, 649, 649, 649, 649}, {::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, 72, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state}, {651, 651, 651, 651, 651, 651, 651, 651, 651, 651, 651, 651, 651, 651, 651, 651, 651, 651, 651, 651, 651, 651, 651, 651, 651, 651, 651, 651, 651, 651, 651, 651, 651, 651, 651, 651, 651, 651, 651, 651, 651, 651, 651, 651, 651, 651, 651, 651, 467, 470, 462, 461, 458, 455, 453, 452, 450, 448, 651, 651, 651, 651, 651, 651, 651, 427, 424, 422, 420, 418, 416, 471, 469, 466, 464, 465, 457, 454, 446, 445, 444, 443, 442, 441, 440, 439, 434, 432, 430, 428, 425, 651, 651, 651, 651, 468, 651, 463, 460, 459, 456, 474, 451, 449, 447, 438, 437, 436, 435, 433, 431, 429, 73, 423, 421, 419, 417, 415, 414, 413, 412, 411, 410, 651, 651, 651, 651, 651, 651}, {653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653, 653}, {655, 655, 655, 655, 655, 655, 655, 655, 655, 655, 655, 655, 655, 655, 655, 655, 655, 655, 655, 655, 655, 655, 655, 655, 655, 655, 655, 655, 655, 655, 655, 655, 655, 655, 655, 655, 655, 655, 655, 655, 655, 655, 655, 655, 655, 655, 655, 655, 467, 470, 462, 461, 458, 455, 453, 452, 450, 448, 655, 655, 655, 655, 655, 655, 655, 427, 424, 422, 420, 418, 416, 471, 469, 466, 464, 465, 457, 454, 446, 445, 444, 443, 442, 441, 440, 439, 434, 432, 430, 428, 425, 655, 655, 655, 655, 468, 655, 463, 460, 459, 456, 474, 451, 449, 447, 438, 437, 436, 435, 433, 74, 429, 426, 423, 421, 419, 417, 415, 414, 413, 412, 411, 410, 655, 655, 655, 655, 655, 655}, {657, 657, 657, 657, 657, 657, 657, 657, 657, 657, 657, 657, 657, 657, 657, 657, 657, 657, 657, 657, 657, 657, 657, 657, 657, 657, 657, 657, 657, 657, 657, 657, 657, 657, 657, 657, 657, 657, 657, 657, 657, 657, 657, 657, 657, 657, 657, 657, 467, 470, 462, 461, 458, 455, 453, 452, 450, 448, 657, 657, 657, 657, 657, 657, 657, 427, 424, 422, 420, 418, 416, 471, 469, 466, 464, 465, 457, 454, 446, 445, 444, 443, 442, 441, 440, 439, 434, 432, 430, 428, 425, 657, 657, 657, 657, 468, 657, 463, 460, 459, 456, 474, 451, 449, 447, 438, 437, 436, 435, 433, 431, 429, 426, 423, 75, 419, 417, 415, 414, 413, 412, 411, 410, 657, 657, 657, 657, 657, 657}, {709, 709, 709, 709, 709, 709, 709, 709, 709, 709, 709, 709, 709, 709, 709, 709, 709, 709, 709, 709, 709, 709, 709, 709, 709, 709, 709, 709, 709, 709, 709, 709, 709, 709, 709, 709, 709, 709, 709, 709, 709, 709, 709, 709, 709, 709, 709, 709, 467, 470, 462, 461, 458, 455, 453, 452, 450, 448, 709, 709, 709, 709, 709, 709, 709, 427, 424, 422, 420, 418, 416, 471, 469, 466, 464, 465, 457, 454, 446, 445, 444, 443, 442, 441, 440, 439, 434, 432, 430, 428, 425, 709, 709, 709, 709, 468, 709, 463, 460, 459, 456, 474, 451, 449, 447, 438, 437, 436, 435, 433, 431, 429, 426, 423, 421, 419, 417, 415, 414, 413, 412, 411, 410, 709, 709, 709, 709, 709, 709}, {659, 659, 659, 659, 659, 659, 659, 659, 659, 659, 659, 659, 659, 659, 659, 659, 659, 659, 659, 659, 659, 659, 659, 659, 659, 659, 659, 659, 659, 659, 659, 659, 659, 659, 659, 659, 659, 659, 659, 659, 659, 659, 659, 659, 659, 659, 659, 659, 467, 470, 462, 461, 458, 455, 453, 452, 450, 448, 659, 659, 659, 659, 659, 659, 659, 427, 424, 422, 420, 418, 416, 471, 469, 466, 464, 465, 457, 454, 446, 445, 444, 443, 442, 441, 440, 439, 434, 432, 430, 428, 425, 659, 659, 659, 659, 468, 659, 463, 460, 459, 456, 474, 451, 449, 447, 438, 437, 436, 435, 433, 76, 429, 426, 423, 421, 419, 417, 415, 414, 413, 412, 411, 410, 659, 659, 659, 659, 659, 659}, {661, 661, 661, 661, 661, 661, 661, 661, 661, 661, 661, 661, 661, 661, 661, 661, 661, 661, 661, 661, 661, 661, 661, 661, 661, 661, 661, 661, 661, 661, 661, 661, 661, 661, 661, 661, 661, 661, 661, 661, 661, 661, 661, 661, 661, 661, 661, 661, 467, 470, 462, 461, 458, 455, 453, 452, 450, 448, 661, 661, 661, 661, 661, 661, 661, 427, 424, 422, 420, 418, 416, 471, 469, 466, 464, 465, 457, 454, 446, 445, 444, 443, 442, 441, 440, 439, 434, 432, 430, 428, 425, 661, 661, 661, 661, 468, 661, 463, 460, 459, 456, 474, 451, 449, 77, 438, 437, 436, 435, 433, 431, 429, 426, 423, 421, 419, 417, 415, 414, 413, 412, 411, 410, 661, 661, 661, 661, 661, 661}, {::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, 662, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state}, {664, 664, 664, 664, 664, 664, 664, 664, 664, 664, 664, 664, 664, 664, 664, 664, 664, 664, 664, 664, 664, 664, 664, 664, 664, 664, 664, 664, 664, 664, 664, 664, 664, 664, 664, 664, 664, 664, 664, 664, 664, 664, 664, 664, 664, 664, 664, 664, 467, 470, 462, 461, 458, 455, 453, 452, 450, 448, 664, 664, 664, 664, 664, 664, 664, 427, 424, 422, 420, 418, 416, 471, 469, 466, 464, 465, 457, 454, 446, 445, 444, 443, 442, 441, 440, 439, 434, 432, 430, 428, 425, 664, 664, 664, 664, 468, 664, 463, 460, 459, 456, 474, 451, 449, 447, 438, 437, 436, 435, 433, 431, 429, 426, 423, 421, 419, 417, 415, 414, 413, 412, 411, 410, 664, 664, 664, 664, 664, 664}, {666, 666, 666, 666, 666, 666, 666, 666, 666, 666, 666, 666, 666, 666, 666, 666, 666, 666, 666, 666, 666, 666, 666, 666, 666, 666, 666, 666, 666, 666, 666, 666, 666, 666, 666, 666, 666, 666, 666, 666, 666, 666, 666, 666, 666, 666, 666, 666, 467, 470, 462, 461, 458, 455, 453, 452, 450, 448, 666, 666, 666, 666, 666, 666, 666, 427, 424, 422, 420, 418, 416, 471, 469, 466, 464, 465, 457, 454, 446, 445, 444, 443, 442, 441, 440, 439, 434, 432, 430, 428, 425, 666, 666, 666, 666, 468, 666, 463, 460, 459, 79, 474, 451, 449, 447, 438, 437, 436, 435, 433, 431, 429, 426, 423, 421, 419, 417, 415, 414, 413, 412, 411, 410, 666, 666, 666, 666, 666, 666}, {668, 668, 668, 668, 668, 668, 668, 668, 668, 668, 668, 668, 668, 668, 668, 668, 668, 668, 668, 668, 668, 668, 668, 668, 668, 668, 668, 668, 668, 668, 668, 668, 668, 668, 668, 668, 668, 668, 668, 668, 668, 668, 668, 668, 668, 668, 668, 668, 467, 470, 462, 461, 458, 455, 453, 452, 450, 448, 668, 668, 668, 668, 668, 668, 668, 427, 424, 422, 420, 418, 416, 471, 469, 466, 464, 465, 457, 454, 446, 445, 444, 443, 442, 441, 440, 439, 434, 432, 430, 428, 425, 668, 668, 668, 668, 468, 668, 463, 460, 459, 456, 474, 451, 449, 447, 438, 437, 436, 435, 433, 80, 429, 426, 423, 421, 419, 417, 415, 414, 413, 412, 411, 410, 668, 668, 668, 668, 668, 668}, {670, 670, 670, 670, 670, 670, 670, 670, 670, 670, 670, 670, 670, 670, 670, 670, 670, 670, 670, 670, 670, 670, 670, 670, 670, 670, 670, 670, 670, 670, 670, 670, 670, 670, 670, 670, 670, 670, 670, 670, 670, 670, 670, 670, 670, 670, 670, 670, 467, 470, 462, 461, 458, 455, 453, 452, 450, 448, 670, 670, 670, 670, 670, 670, 670, 427, 424, 422, 420, 418, 416, 471, 469, 466, 464, 465, 457, 454, 446, 445, 444, 443, 442, 441, 440, 439, 434, 432, 430, 428, 425, 670, 670, 670, 670, 468, 670, 463, 460, 459, 456, 81, 451, 449, 447, 438, 437, 436, 435, 433, 431, 429, 426, 423, 421, 419, 417, 415, 414, 413, 412, 411, 410, 670, 670, 670, 670, 670, 670}, {711, 711, 711, 711, 711, 711, 711, 711, 711, 711, 711, 711, 711, 711, 711, 711, 711, 711, 711, 711, 711, 711, 711, 711, 711, 711, 711, 711, 711, 711, 711, 711, 711, 711, 711, 711, 711, 711, 711, 711, 711, 711, 711, 711, 711, 711, 711, 711, 467, 470, 462, 461, 458, 455, 453, 452, 450, 448, 711, 711, 711, 711, 711, 711, 711, 427, 424, 422, 420, 418, 416, 471, 469, 466, 464, 465, 457, 454, 446, 445, 444, 443, 442, 441, 440, 439, 434, 432, 430, 428, 425, 711, 711, 711, 711, 468, 711, 463, 460, 459, 456, 474, 451, 449, 447, 438, 437, 436, 435, 433, 431, 429, 426, 423, 421, 419, 417, 415, 414, 413, 412, 411, 410, 711, 711, 711, 711, 711, 711}, {712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712, 712}, {672, 672, 672, 672, 672, 672, 672, 672, 672, 672, 672, 672, 672, 672, 672, 672, 672, 672, 672, 672, 672, 672, 672, 672, 672, 672, 672, 672, 672, 672, 672, 672, 672, 672, 672, 672, 672, 672, 672, 672, 672, 672, 672, 672, 672, 672, 672, 672, 467, 470, 462, 461, 458, 455, 453, 452, 450, 448, 672, 672, 672, 672, 672, 672, 672, 427, 424, 422, 420, 418, 416, 471, 469, 466, 464, 465, 457, 454, 446, 445, 444, 443, 442, 441, 440, 439, 434, 432, 430, 428, 425, 672, 672, 672, 672, 468, 672, 463, 460, 459, 456, 474, 451, 449, 447, 438, 437, 436, 435, 433, 431, 429, 426, 423, 421, 82, 417, 415, 414, 413, 412, 411, 410, 672, 672, 672, 672, 672, 672}, {674, 674, 674, 674, 674, 674, 674, 674, 674, 674, 674, 674, 674, 674, 674, 674, 674, 674, 674, 674, 674, 674, 674, 674, 674, 674, 674, 674, 674, 674, 674, 674, 674, 674, 674, 674, 674, 674, 674, 674, 674, 674, 674, 674, 674, 674, 674, 674, 467, 470, 462, 461, 458, 455, 453, 452, 450, 448, 674, 674, 674, 674, 674, 674, 674, 427, 424, 422, 420, 418, 416, 471, 469, 466, 464, 465, 457, 454, 446, 445, 444, 443, 442, 441, 440, 439, 434, 432, 430, 428, 425, 674, 674, 674, 674, 468, 674, 463, 460, 459, 456, 474, 451, 449, 447, 438, 437, 436, 435, 433, 431, 429, 426, 423, 421, 419, 417, 415, 414, 413, 412, 411, 410, 674, 674, 674, 674, 674, 674}, {676, 676, 676, 676, 676, 676, 676, 676, 676, 676, 676, 676, 676, 676, 676, 676, 676, 676, 676, 676, 676, 676, 676, 676, 676, 676, 676, 676, 676, 676, 676, 676, 676, 676, 676, 676, 676, 676, 676, 676, 676, 676, 676, 676, 676, 676, 676, 676, 467, 470, 462, 461, 458, 455, 453, 452, 450, 448, 676, 676, 676, 676, 676, 676, 676, 427, 424, 422, 420, 418, 416, 471, 469, 466, 464, 465, 457, 454, 446, 445, 444, 443, 442, 441, 440, 439, 434, 432, 430, 428, 425, 676, 676, 676, 676, 468, 676, 463, 460, 459, 456, 474, 451, 449, 447, 438, 437, 436, 435, 433, 431, 429, 426, 423, 421, 419, 417, 415, 414, 413, 412, 411, 410, 676, 676, 676, 676, 676, 676}, {715, 715, 715, 715, 715, 715, 715, 715, 715, 715, 715, 715, 715, 715, 715, 715, 715, 715, 715, 715, 715, 715, 715, 715, 715, 715, 715, 715, 715, 715, 715, 715, 715, 715, 715, 715, 715, 715, 715, 715, 715, 715, 715, 715, 715, 715, 715, 715, 467, 470, 462, 461, 458, 455, 453, 452, 450, 448, 715, 715, 715, 715, 715, 715, 715, 427, 424, 422, 420, 418, 416, 471, 469, 466, 464, 465, 457, 454, 446, 445, 444, 443, 442, 441, 440, 439, 434, 432, 430, 428, 425, 715, 715, 715, 715, 468, 715, 463, 460, 459, 456, 474, 451, 449, 447, 438, 437, 436, 435, 433, 431, 429, 426, 423, 421, 419, 417, 415, 414, 413, 412, 411, 410, 715, 715, 715, 715, 715, 715}}};
::ISPA_STD::DFA::API::Table<594, 4> Parser::Lexer::action_table = {{{1, 0, ::ISPA_STD::DFA::API::null_state, 21}, {1, 26, ::ISPA_STD::DFA::API::null_state, 27}, {1, 0, ::ISPA_STD::DFA::API::null_state, 21}, {1, 26, ::ISPA_STD::DFA::API::null_state, 26}, {1, 0, ::ISPA_STD::DFA::API::null_state, 21}, {1, 26, ::ISPA_STD::DFA::API::null_state, 25}, {1, 0, ::ISPA_STD::DFA::API::null_state, 21}, {1, 0, ::ISPA_STD::DFA::API::null_state, 21}, {1, 0, ::ISPA_STD::DFA::API::null_state, 21}, {1, 0, ::ISPA_STD::DFA::API::null_state, 21}, {1, 0, ::ISPA_STD::DFA::API::null_state, 21}, {1, 0, ::ISPA_STD::DFA::API::null_state, 21}, {1, 0, ::ISPA_STD::DFA::API::null_state, 21}, {1, 0, ::ISPA_STD::DFA::API::null_state, 21}, {1, 0, ::ISPA_STD::DFA::API::null_state, 21}, {1, 0, ::ISPA_STD::DFA::API::null_state, 21}, {1, 0, ::ISPA_STD::DFA::API::null_state, 21}, {1, 0, ::ISPA_STD::DFA::API::null_state, 21}, {1, 0, ::ISPA_STD::DFA::API::null_state, 21}, {1, 0, ::ISPA_STD::DFA::API::null_state, 21}, {1, 26, ::ISPA_STD::DFA::API::null_state, 31}, {1, 0, ::ISPA_STD::DFA::API::null_state, 21}, {1, 0, ::ISPA_STD::DFA::API::null_state, 21}, {1, 26, ::ISPA_STD::DFA::API::null_state, 30}, {1, 0, ::ISPA_STD::DFA::API::null_state, 21}, {1, 26, ::ISPA_STD::DFA::API::null_state, 28}, {1, 0, ::ISPA_STD::DFA::API::null_state, 21}, {1, 0, ::ISPA_STD::DFA::API::null_state, 21}, {1, 0, ::ISPA_STD::DFA::API::null_state, 21}, {1, 0, ::ISPA_STD::DFA::API::null_state, 21}, {1, 0, ::ISPA_STD::DFA::API::null_state, 21}, {1, 0, ::ISPA_STD::DFA::API::null_state, 21}, {1, 0, ::ISPA_STD::DFA::API::null_state, 21}, {1, 0, ::ISPA_STD::DFA::API::null_state, 21}, {1, 0, ::ISPA_STD::DFA::API::null_state, 21}, {1, 0, ::ISPA_STD::DFA::API::null_state, 21}, {1, 0, ::ISPA_STD::DFA::API::null_state, 21}, {1, 0, ::ISPA_STD::DFA::API::null_state, 21}, {1, 0, ::ISPA_STD::DFA::API::null_state, 21}, {1, 0, ::ISPA_STD::DFA::API::null_state, 21}, {1, 0, ::ISPA_STD::DFA::API::null_state, 21}, {1, 0, ::ISPA_STD::DFA::API::null_state, 21}, {1, 0, ::ISPA_STD::DFA::API::null_state, 21}, {1, 0, ::ISPA_STD::DFA::API::null_state, 21}, {1, 0, ::ISPA_STD::DFA::API::null_state, 21}, {1, 0, ::ISPA_STD::DFA::API::null_state, 21}, {1, 22, ::ISPA_STD::DFA::API::null_state, 13}, {1, 22, ::ISPA_STD::DFA::API::null_state, 13}, {1, 22, ::ISPA_STD::DFA::API::null_state, 13}, {1, 22, ::ISPA_STD::DFA::API::null_state, 13}, {1, 22, ::ISPA_STD::DFA::API::null_state, 13}, {1, 22, ::ISPA_STD::DFA::API::null_state, 13}, {1, 22, ::ISPA_STD::DFA::API::null_state, 13}, {1, 22, ::ISPA_STD::DFA::API::null_state, 13}, {1, 12, ::ISPA_STD::DFA::API::null_state, 9}, {1, 8, ::ISPA_STD::DFA::API::null_state, 8}, {1, 10, ::ISPA_STD::DFA::API::null_state, 19}, {1, 0, ::ISPA_STD::DFA::API::null_state, 21}, {1, 0, ::ISPA_STD::DFA::API::null_state, 21}, {1, 0, ::ISPA_STD::DFA::API::null_state, 21}, {1, 26, ::ISPA_STD::DFA::API::null_state, 29}, {1, 0, ::ISPA_STD::DFA::API::null_state, 21}, {1, 22, ::ISPA_STD::DFA::API::null_state, 13}, {1, 22, ::ISPA_STD::DFA::API::null_state, 13}, {1, 0, ::ISPA_STD::DFA::API::null_state, 21}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 38}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 20, ::ISPA_STD::DFA::API::null_state, 36}, {1, 9, ::ISPA_STD::DFA::API::null_state, 683}, {1, 13, ::ISPA_STD::DFA::API::null_state, 684}, {1, 23, ::ISPA_STD::DFA::API::null_state, 687}, {1, 23, ::ISPA_STD::DFA::API::null_state, 40}, {1, 11, ::ISPA_STD::DFA::API::null_state, 693}, {1, 1, ::ISPA_STD::DFA::API::null_state, 695}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 45}, {1, 6, ::ISPA_STD::DFA::API::null_state, 44}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {3, 0, 26, 695}, {1, 1, ::ISPA_STD::DFA::API::null_state, 408}, {3, 0, 26, 42}, {3, 0, 26, 42}, {3, 0, 26, 42}, {3, 0, 26, 42}, {3, 0, 26, 42}, {3, 0, 26, 42}, {3, 0, 26, 42}, {3, 0, 26, 42}, {3, 0, 26, 42}, {3, 0, 26, 42}, {3, 0, 26, 42}, {3, 0, 26, 42}, {3, 0, 26, 42}, {3, 0, 26, 42}, {3, 0, 26, 42}, {3, 0, 26, 42}, {3, 0, 26, 42}, {3, 0, 26, 42}, {3, 0, 26, 42}, {3, 0, 26, 42}, {3, 0, 26, 42}, {3, 0, 26, 42}, {3, 0, 26, 42}, {3, 0, 26, 42}, {3, 0, 26, 42}, {3, 0, 26, 42}, {3, 0, 26, 42}, {3, 0, 26, 42}, {3, 0, 26, 42}, {3, 0, 26, 42}, {3, 0, 26, 42}, {3, 0, 26, 42}, {3, 0, 26, 42}, {3, 0, 26, 42}, {3, 0, 26, 42}, {3, 0, 26, 42}, {3, 0, 26, 42}, {3, 0, 26, 42}, {3, 0, 26, 42}, {3, 0, 26, 42}, {3, 0, 26, 42}, {3, 0, 26, 42}, {3, 0, 26, 42}, {3, 0, 26, 42}, {3, 0, 26, 42}, {3, 0, 26, 42}, {3, 0, 26, 42}, {3, 0, 26, 42}, {3, 0, 26, 42}, {3, 0, 26, 42}, {3, 0, 26, 42}, {3, 0, 26, 42}, {3, 0, 26, 42}, {3, 0, 26, 42}, {3, 0, 26, 42}, {3, 0, 26, 42}, {3, 0, 26, 42}, {3, 0, 26, 42}, {3, 0, 26, 42}, {3, 0, 26, 42}, {3, 0, 26, 42}, {3, 0, 26, 42}, {3, 0, 26, 695}, {1, 1, ::ISPA_STD::DFA::API::null_state, 472}, {3, 0, 26, 42}, {3, 0, 26, 695}, {1, 1, ::ISPA_STD::DFA::API::null_state, 475}, {3, 0, 26, 695}, {1, 1, ::ISPA_STD::DFA::API::null_state, 477}, {3, 0, 26, 695}, {1, 1, ::ISPA_STD::DFA::API::null_state, 479}, {3, 0, 26, 695}, {1, 1, ::ISPA_STD::DFA::API::null_state, 481}, {3, 0, 26, 695}, {1, 1, ::ISPA_STD::DFA::API::null_state, 483}, {1, 21, ::ISPA_STD::DFA::API::null_state, 37}, {1, 24, ::ISPA_STD::DFA::API::null_state, 54}, {1, 24, ::ISPA_STD::DFA::API::null_state, 54}, {1, 24, ::ISPA_STD::DFA::API::null_state, 54}, {1, 24, ::ISPA_STD::DFA::API::null_state, 54}, {1, 24, ::ISPA_STD::DFA::API::null_state, 54}, {1, 24, ::ISPA_STD::DFA::API::null_state, 54}, {1, 24, ::ISPA_STD::DFA::API::null_state, 54}, {1, 24, ::ISPA_STD::DFA::API::null_state, 54}, {1, 24, ::ISPA_STD::DFA::API::null_state, 54}, {1, 24, ::ISPA_STD::DFA::API::null_state, 54}, {1, 1, ::ISPA_STD::DFA::API::null_state, 704}, {1, 7, ::ISPA_STD::DFA::API::null_state, 55}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 57}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {1, 5, ::ISPA_STD::DFA::API::null_state, 56}, {3, 0, 26, 704}, {1, 1, ::ISPA_STD::DFA::API::null_state, 625}, {3, 0, 26, 704}, {1, 1, ::ISPA_STD::DFA::API::null_state, 627}, {3, 0, 26, 704}, {1, 1, ::ISPA_STD::DFA::API::null_state, 629}, {3, 0, 26, 704}, {1, 1, ::ISPA_STD::DFA::API::null_state, 631}, {3, 0, 26, 704}, {1, 1, ::ISPA_STD::DFA::API::null_state, 633}, {1, 2, ::ISPA_STD::DFA::API::null_state, 64}, {3, 0, 26, 704}, {1, 1, ::ISPA_STD::DFA::API::null_state, 636}, {1, 25, ::ISPA_STD::DFA::API::null_state, 706}, {1, 7, ::ISPA_STD::DFA::API::null_state, 66}, {3, 0, 26, 704}, {1, 1, ::ISPA_STD::DFA::API::null_state, 640}, {3, 0, 26, 704}, {1, 1, ::ISPA_STD::DFA::API::null_state, 642}, {3, 0, 26, 704}, {1, 1, ::ISPA_STD::DFA::API::null_state, 644}, {3, 0, 26, 704}, {1, 1, ::ISPA_STD::DFA::API::null_state, 646}, {3, 0, 26, 704}, {1, 1, ::ISPA_STD::DFA::API::null_state, 648}, {3, 0, 26, 704}, {1, 1, ::ISPA_STD::DFA::API::null_state, 650}, {3, 6, 5, 707}, {3, 4, 6, 652}, {3, 0, 26, 704}, {1, 1, ::ISPA_STD::DFA::API::null_state, 654}, {3, 0, 26, 704}, {1, 1, ::ISPA_STD::DFA::API::null_state, 656}, {3, 0, 26, 704}, {1, 1, ::ISPA_STD::DFA::API::null_state, 658}, {3, 0, 26, 704}, {1, 1, ::ISPA_STD::DFA::API::null_state, 660}, {1, 3, ::ISPA_STD::DFA::API::null_state, 78}, {3, 16, 26, 710}, {1, 17, ::ISPA_STD::DFA::API::null_state, 663}, {3, 0, 26, 704}, {1, 1, ::ISPA_STD::DFA::API::null_state, 665}, {3, 0, 26, 704}, {1, 1, ::ISPA_STD::DFA::API::null_state, 667}, {3, 0, 26, 704}, {1, 1, ::ISPA_STD::DFA::API::null_state, 669}, {3, 0, 26, 704}, {1, 1, ::ISPA_STD::DFA::API::null_state, 671}, {3, 14, 26, 713}, {1, 15, ::ISPA_STD::DFA::API::null_state, 673}, {3, 18, 26, 714}, {1, 19, ::ISPA_STD::DFA::API::null_state, 675}}};
std::array<::ISPA_STD::DFA::API::DFADebug, 654> Parser::Lexer::debug_array = {::ISPA_STD::DFA::API::DFADebug {"[ \\t\\n\\r\\v\\f]", "__WS", 0, -1, 0, 103, 0, 1, '\t'}, ::ISPA_STD::DFA::API::DFADebug {"[ \\t\\n\\r\\v\\f]", "__WS", 0, -1, 0, 103, 0, 1, '\n'}, ::ISPA_STD::DFA::API::DFADebug {"[ \\t\\n\\r\\v\\f]", "__WS", 0, -1, 0, 103, 0, 1, '\x0B'}, ::ISPA_STD::DFA::API::DFADebug {"[ \\t\\n\\r\\v\\f]", "__WS", 0, -1, 0, 103, 0, 1, '\x0C'}, ::ISPA_STD::DFA::API::DFADebug {"[ \\t\\n\\r\\v\\f]", "__WS", 0, -1, 0, 103, 0, 1, '\r'}, ::ISPA_STD::DFA::API::DFADebug {"[ \\t\\n\\r\\v\\f]", "__WS", 0, -1, 0, 103, 0, 1, ' '}, ::ISPA_STD::DFA::API::DFADebug {"#", "rule.nested_rule.NUMBER_SIGN", 0, -1, -1, 50, 0, 1, '#'}, ::ISPA_STD::DFA::API::DFADebug {"$", "rule.value.dyn.DOLLAR_SIGN", 0, -1, -1, 110, 0, 1, '$'}, ::ISPA_STD::DFA::API::DFADebug {"&", "AMPERSAND", 0, -1, -1, 116, 0, 1, '&'}, ::ISPA_STD::DFA::API::DFADebug {"'", "rule.value.STRING", 0, -1, -1, 81, 0, 1, '\''}, ::ISPA_STD::DFA::API::DFADebug {"(", "LEFT_PARENTHESIS", 0, -1, -1, 11, 0, 1, '('}, ::ISPA_STD::DFA::API::DFADebug {")", "RIGHT_PARENTHESIS", 0, -1, -1, 13, 0, 1, ')'}, ::ISPA_STD::DFA::API::DFADebug {",", "COMMA", 0, -1, -1, 24, 0, 1, ','}, ::ISPA_STD::DFA::API::DFADebug {"->", "AUTO", 0, -1, -1, 87, 0, 2, '-'}, ::ISPA_STD::DFA::API::DFADebug {".", "rule.value.ANY", 0, -1, -1, 9, 0, 1, '.'}, ::ISPA_STD::DFA::API::DFADebug {":", "COLON", 0, -1, -1, 45, 0, 1, ':'}, ::ISPA_STD::DFA::API::DFADebug {";", "SEMICOLON", 0, -1, -1, 77, 0, 1, ';'}, ::ISPA_STD::DFA::API::DFADebug {"<", "template_params.LESS_THAN_SIGN", 0, -1, -1, 41, 0, 1, '<'}, ::ISPA_STD::DFA::API::DFADebug {"=", "rule.value.counter.bounded.EQUALS_SIGN", 0, -1, -1, 90, 0, 1, '='}, ::ISPA_STD::DFA::API::DFADebug {">", "template_params.GREATER_THAN_SIGN", 0, -1, -1, 79, 0, 1, '>'}, ::ISPA_STD::DFA::API::DFADebug {"@", "COMMERCIAL_AT", 0, -1, -1, 75, 0, 1, '@'}, ::ISPA_STD::DFA::API::DFADebug {"[", "rule.value.CGROUP", 0, -1, -1, 15, 0, 1, '['}, ::ISPA_STD::DFA::API::DFADebug {"\\s", "rule.value.SPACE", 0, -1, -1, 100, 0, 2, '\\'}, ::ISPA_STD::DFA::API::DFADebug {"]", "grammar.modifier.RIGHT_SQUARE_BRACKET", 0, -1, -1, 43, 0, 1, ']'}, ::ISPA_STD::DFA::API::DFADebug {"{", "LEFT_CURLY_BRACKET", 0, -1, -1, 52, 0, 1, '{'}, ::ISPA_STD::DFA::API::DFADebug {"|", "rule.value.alternative.VERTICAL_LINE", 0, -1, -1, 35, 0, 1, '|'}, ::ISPA_STD::DFA::API::DFADebug {"}", "RIGHT_CURLY_BRACKET", 0, -1, -1, 22, 0, 1, '}'}, ::ISPA_STD::DFA::API::DFADebug {"#[", "grammar.modifier.AUTO", 0, -1, -1, 33, 1, 2, '['}, ::ISPA_STD::DFA::API::DFADebug {"'", "rule.value.STRING", 2, -1, -1, 84, 0, 1, '\''}, ::ISPA_STD::DFA::API::DFADebug {"->", "AUTO", 0, -1, -1, 88, 1, 2, '>'}, ::ISPA_STD::DFA::API::DFADebug {"[0-9]", "NUMBER", 0, -1, 2, 112, 0, 1, '0'}, ::ISPA_STD::DFA::API::DFADebug {"[0-9]", "NUMBER", 0, -1, 2, 112, 0, 1, '1'}, ::ISPA_STD::DFA::API::DFADebug {"[0-9]", "NUMBER", 0, -1, 2, 112, 0, 1, '2'}, ::ISPA_STD::DFA::API::DFADebug {"[0-9]", "NUMBER", 0, -1, 2, 112, 0, 1, '3'}, ::ISPA_STD::DFA::API::DFADebug {"[0-9]", "NUMBER", 0, -1, 2, 112, 0, 1, '4'}, ::ISPA_STD::DFA::API::DFADebug {"[0-9]", "NUMBER", 0, -1, 2, 112, 0, 1, '5'}, ::ISPA_STD::DFA::API::DFADebug {"[0-9]", "NUMBER", 0, -1, 2, 112, 0, 1, '6'}, ::ISPA_STD::DFA::API::DFADebug {"[0-9]", "NUMBER", 0, -1, 2, 112, 0, 1, '7'}, ::ISPA_STD::DFA::API::DFADebug {"[0-9]", "NUMBER", 0, -1, 2, 112, 0, 1, '8'}, ::ISPA_STD::DFA::API::DFADebug {"[0-9]", "NUMBER", 0, -1, 2, 112, 0, 1, '9'}, ::ISPA_STD::DFA::API::DFADebug {"=>", "rule.value.shared_counter_registration.AUTO", 0, -1, -1, 48, 1, 2, '>'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, '0'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, '1'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, '2'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, '3'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, '4'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, '5'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, '6'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, '7'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, '8'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, '9'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 'A'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 'B'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 'C'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 'D'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 'E'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 'F'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 'G'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 'H'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 'I'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 'J'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 'K'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 'L'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 'M'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 'N'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 'O'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 'P'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 'Q'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 'R'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 'S'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 'T'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 'U'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 'V'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 'W'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 'X'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 'Y'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 'Z'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, '_'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 'a'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 'b'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 'c'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 'd'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 'e'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 'f'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 'g'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 'h'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 'i'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 'j'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 'k'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 'l'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 'm'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 'n'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 'o'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 'p'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 'q'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 'r'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 's'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 't'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 'u'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 'v'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 'w'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 'x'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 'y'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 'z'}, ::ISPA_STD::DFA::API::DFADebug {"\\s", "rule.value.SPACE", 0, -1, -1, 101, 1, 2, 's'}, ::ISPA_STD::DFA::API::DFADebug {"depends", "advanced_rule.dep_decl.DEPENDS", 0, -1, -1, 93, 1, 7, 'e'}, ::ISPA_STD::DFA::API::DFADebug {"extern", "grammar.modifier.MOD", 0, -1, -1, 55, 1, 6, 'x'}, ::ISPA_STD::DFA::API::DFADebug {"fail", "FAIL", 0, -1, -1, 106, 1, 4, 'a'}, ::ISPA_STD::DFA::API::DFADebug {"inline", "grammar.modifier.MOD", 0, -1, -1, 65, 1, 6, 'n'}, ::ISPA_STD::DFA::API::DFADebug {"match", "advanced_rule.regular_match.MATCH", 0, -1, -1, 27, 1, 5, 'a'}, ::ISPA_STD::DFA::API::DFADebug {"p{", "PY_RAW", 0, -1, -1, 4, 1, 2, '{'}, ::ISPA_STD::DFA::API::DFADebug {"skip", "grammar.modifier.MOD", 0, -1, -1, 61, 1, 4, 'k'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, '\000'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, '\x01'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, '\x02'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, '\x03'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, '\x04'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, '\x05'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, '\x06'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, '\x07'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, '\x08'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, '\t'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, '\n'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, '\x0B'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, '\x0C'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, '\r'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, '\x0E'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, '\x0F'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, '\x10'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, '\x11'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, '\x12'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, '\x13'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, '\x14'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, '\x15'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, '\x16'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, '\x17'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, '\x18'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, '\x19'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, '\x1A'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, '\x1B'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, '\x1C'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, '\x1D'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, '\x1E'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, '\x1F'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, ' '}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, '!'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, '"'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, '#'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, '$'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, '%'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, '&'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, '('}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, ')'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, '*'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, '+'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, ','}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, '-'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, '.'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, '/'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, '0'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, '1'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, '2'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, '3'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, '4'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, '5'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, '6'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, '7'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, '8'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, '9'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, ':'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, ';'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, '<'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, '='}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, '>'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, '?'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, '@'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, 'A'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, 'B'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, 'C'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, 'D'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, 'E'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, 'F'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, 'G'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, 'H'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, 'I'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, 'J'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, 'K'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, 'L'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, 'M'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, 'N'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, 'O'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, 'P'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, 'Q'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, 'R'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, 'S'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, 'T'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, 'U'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, 'V'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, 'W'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, 'X'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, 'Y'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, 'Z'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, '['}, ::ISPA_STD::DFA::API::DFADebug {"\\", "rule.value.STRING", 1, -1, 2, 82, 0, 1, '\\'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, ']'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, '^'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, '_'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, '`'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, 'a'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, 'b'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, 'c'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, 'd'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, 'e'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, 'f'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, 'g'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, 'h'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, 'i'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, 'j'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, 'k'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, 'l'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, 'm'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, 'n'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, 'o'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, 'p'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, 'q'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, 'r'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, 's'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, 't'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, 'u'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, 'v'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, 'w'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, 'x'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, 'y'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, 'z'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, '{'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, '|'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, '}'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, '~'}, ::ISPA_STD::DFA::API::DFADebug {"['\\\\]", "rule.value.STRING", 1, -1, 3, 84, 0, 1, '\x7F'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, '\000'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, '\x01'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, '\x02'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, '\x03'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, '\x04'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, '\x05'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, '\x06'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, '\x07'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, '\x08'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, '\t'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, '\n'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, '\x0B'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, '\x0C'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, '\r'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, '\x0E'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, '\x0F'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, '\x10'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, '\x11'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, '\x12'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, '\x13'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, '\x14'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, '\x15'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, '\x16'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, '\x17'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, '\x18'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, '\x19'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, '\x1A'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, '\x1B'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, '\x1C'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, '\x1D'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, '\x1E'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, '\x1F'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, ' '}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, '!'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, '"'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, '#'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, '$'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, '%'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, '&'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, '\''}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, '('}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, ')'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, '*'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, '+'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, ','}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, '-'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, '.'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, '/'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, '0'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, '1'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, '2'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, '3'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, '4'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, '5'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, '6'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, '7'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, '8'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, '9'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, ':'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, ';'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, '<'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, '='}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, '>'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, '?'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, '@'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, 'A'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, 'B'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, 'C'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, 'D'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, 'E'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, 'F'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, 'G'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, 'H'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, 'I'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, 'J'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, 'K'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, 'L'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, 'M'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, 'N'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, 'O'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, 'P'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, 'Q'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, 'R'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, 'S'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, 'T'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, 'U'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, 'V'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, 'W'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, 'X'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, 'Y'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, 'Z'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, '['}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, '\\'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, ']'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, '^'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, '_'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, '`'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, 'a'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, 'b'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, 'c'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, 'd'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, 'e'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, 'f'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, 'g'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, 'h'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, 'i'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, 'j'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, 'k'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, 'l'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, 'm'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, 'n'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, 'o'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, 'p'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, 'q'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, 'r'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, 's'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, 't'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, 'u'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, 'v'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, 'w'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, 'x'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, 'y'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, 'z'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, '{'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, '|'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, '}'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, '~'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.STRING", 1, -1, 1, 83, 0, 1, '\x7F'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, '\000'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, '\x01'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, '\x02'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, '\x03'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, '\x04'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, '\x05'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, '\x06'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, '\x07'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, '\x08'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, '\t'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, '\n'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, '\x0B'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, '\x0C'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, '\r'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, '\x0E'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, '\x0F'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, '\x10'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, '\x11'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, '\x12'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, '\x13'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, '\x14'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, '\x15'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, '\x16'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, '\x17'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, '\x18'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, '\x19'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, '\x1A'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, '\x1B'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, '\x1C'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, '\x1D'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, '\x1E'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, '\x1F'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, ' '}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, '!'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, '"'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, '#'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, '$'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, '%'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, '&'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, '\''}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, '('}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, ')'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, '*'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, '+'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, ','}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, '-'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, '.'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, '/'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, '0'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, '1'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, '2'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, '3'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, '4'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, '5'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, '6'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, '7'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, '8'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, '9'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, ':'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, ';'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, '<'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, '='}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, '>'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, '?'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, '@'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, 'A'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, 'B'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, 'C'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, 'D'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, 'E'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, 'F'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, 'G'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, 'H'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, 'I'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, 'J'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, 'K'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, 'L'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, 'M'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, 'N'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, 'O'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, 'P'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, 'Q'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, 'R'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, 'S'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, 'T'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, 'U'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, 'V'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, 'W'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, 'X'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, 'Y'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, 'Z'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, '['}, ::ISPA_STD::DFA::API::DFADebug {"\\", "rule.value.CGROUP", 2, -1, 3, 18, 0, 1, '\\'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, '^'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, '_'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, '`'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, 'a'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, 'b'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, 'c'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, 'd'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, 'e'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, 'f'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, 'g'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, 'h'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, 'i'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, 'j'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, 'k'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, 'l'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, 'm'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, 'n'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, 'o'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, 'p'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, 'q'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, 'r'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, 's'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, 't'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, 'u'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, 'v'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, 'w'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, 'x'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, 'y'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, 'z'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, '{'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, '|'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, '}'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, '~'}, ::ISPA_STD::DFA::API::DFADebug {"[\\\\\\]]", "rule.value.CGROUP", 2, -1, 1, 17, 0, 1, '\x7F'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, '\000'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, '\x01'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, '\x02'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, '\x03'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, '\x04'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, '\x05'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, '\x06'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, '\x07'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, '\x08'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, '\t'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, '\n'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, '\x0B'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, '\x0C'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, '\r'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, '\x0E'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, '\x0F'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, '\x10'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, '\x11'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, '\x12'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, '\x13'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, '\x14'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, '\x15'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, '\x16'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, '\x17'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, '\x18'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, '\x19'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, '\x1A'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, '\x1B'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, '\x1C'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, '\x1D'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, '\x1E'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, '\x1F'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, ' '}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, '!'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, '"'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, '#'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, '$'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, '%'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, '&'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, '\''}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, '('}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, ')'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, '*'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, '+'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, ','}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, '-'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, '.'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, '/'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, '0'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, '1'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, '2'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, '3'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, '4'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, '5'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, '6'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, '7'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, '8'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, '9'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, ':'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, ';'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, '<'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, '='}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, '>'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, '?'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, '@'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, 'A'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, 'B'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, 'C'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, 'D'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, 'E'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, 'F'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, 'G'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, 'H'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, 'I'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, 'J'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, 'K'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, 'L'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, 'M'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, 'N'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, 'O'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, 'P'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, 'Q'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, 'R'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, 'S'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, 'T'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, 'U'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, 'V'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, 'W'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, 'X'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, 'Y'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, 'Z'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, '['}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, '\\'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, ']'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, '^'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, '_'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, '`'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, 'a'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, 'b'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, 'c'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, 'd'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, 'e'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, 'f'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, 'g'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, 'h'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, 'i'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, 'j'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, 'k'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, 'l'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, 'm'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, 'n'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, 'o'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, 'p'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, 'q'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, 'r'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, 's'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, 't'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, 'u'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, 'v'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, 'w'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, 'x'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, 'y'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, 'z'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, '{'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, '|'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, '}'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, '~'}, ::ISPA_STD::DFA::API::DFADebug {" .", "rule.value.CGROUP", 2, -1, 2, 20, 0, 1, '\x7F'}, ::ISPA_STD::DFA::API::DFADebug {"\\s0", "rule.value.NOSPACE", 0, -1, -1, 73, 2, 3, '0'}, ::ISPA_STD::DFA::API::DFADebug {"depends", "advanced_rule.dep_decl.DEPENDS", 0, -1, -1, 94, 2, 7, 'p'}, ::ISPA_STD::DFA::API::DFADebug {"extern", "grammar.modifier.MOD", 0, -1, -1, 56, 2, 6, 't'}, ::ISPA_STD::DFA::API::DFADebug {"fail", "FAIL", 0, -1, -1, 107, 2, 4, 'i'}, ::ISPA_STD::DFA::API::DFADebug {"inline", "grammar.modifier.MOD", 0, -1, -1, 66, 2, 6, 'l'}, ::ISPA_STD::DFA::API::DFADebug {"match", "advanced_rule.regular_match.MATCH", 0, -1, -1, 28, 2, 5, 't'}, ::ISPA_STD::DFA::API::DFADebug {"skip", "grammar.modifier.MOD", 0, -1, -1, 62, 2, 4, 'i'}, ::ISPA_STD::DFA::API::DFADebug {"[0-9]", "NUMBER", 1, -1, 0, 114, 0, 1, '0'}, ::ISPA_STD::DFA::API::DFADebug {"[0-9]", "NUMBER", 1, -1, 0, 114, 0, 1, '1'}, ::ISPA_STD::DFA::API::DFADebug {"[0-9]", "NUMBER", 1, -1, 0, 114, 0, 1, '2'}, ::ISPA_STD::DFA::API::DFADebug {"[0-9]", "NUMBER", 1, -1, 0, 114, 0, 1, '3'}, ::ISPA_STD::DFA::API::DFADebug {"[0-9]", "NUMBER", 1, -1, 0, 114, 0, 1, '4'}, ::ISPA_STD::DFA::API::DFADebug {"[0-9]", "NUMBER", 1, -1, 0, 114, 0, 1, '5'}, ::ISPA_STD::DFA::API::DFADebug {"[0-9]", "NUMBER", 1, -1, 0, 114, 0, 1, '6'}, ::ISPA_STD::DFA::API::DFADebug {"[0-9]", "NUMBER", 1, -1, 0, 114, 0, 1, '7'}, ::ISPA_STD::DFA::API::DFADebug {"[0-9]", "NUMBER", 1, -1, 0, 114, 0, 1, '8'}, ::ISPA_STD::DFA::API::DFADebug {"[0-9]", "NUMBER", 1, -1, 0, 114, 0, 1, '9'}, ::ISPA_STD::DFA::API::DFADebug {"depends", "advanced_rule.dep_decl.DEPENDS", 0, -1, -1, 95, 3, 7, 'e'}, ::ISPA_STD::DFA::API::DFADebug {"extern", "grammar.modifier.MOD", 0, -1, -1, 57, 3, 6, 'e'}, ::ISPA_STD::DFA::API::DFADebug {"fail", "FAIL", 0, -1, -1, 108, 3, 4, 'l'}, ::ISPA_STD::DFA::API::DFADebug {"inline", "grammar.modifier.MOD", 0, -1, -1, 67, 3, 6, 'i'}, ::ISPA_STD::DFA::API::DFADebug {"match", "advanced_rule.regular_match.MATCH", 0, -1, -1, 29, 3, 5, 'c'}, ::ISPA_STD::DFA::API::DFADebug {"py", "PY_RAW", 1, -1, -1, 6, 1, 2, 'y'}, ::ISPA_STD::DFA::API::DFADebug {"skip", "grammar.modifier.MOD", 0, -1, -1, 63, 3, 4, 'p'}, ::ISPA_STD::DFA::API::DFADebug {"depends", "advanced_rule.dep_decl.DEPENDS", 0, -1, -1, 96, 4, 7, 'n'}, ::ISPA_STD::DFA::API::DFADebug {"extern", "grammar.modifier.MOD", 0, -1, -1, 58, 4, 6, 'r'}, ::ISPA_STD::DFA::API::DFADebug {"inline", "grammar.modifier.MOD", 0, -1, -1, 68, 4, 6, 'n'}, ::ISPA_STD::DFA::API::DFADebug {"match", "advanced_rule.regular_match.MATCH", 0, -1, -1, 30, 4, 5, 'h'}, ::ISPA_STD::DFA::API::DFADebug {"depends", "advanced_rule.dep_decl.DEPENDS", 0, -1, -1, 97, 5, 7, 'd'}, ::ISPA_STD::DFA::API::DFADebug {"extern", "grammar.modifier.MOD", 0, -1, -1, 59, 5, 6, 'n'}, ::ISPA_STD::DFA::API::DFADebug {"inline", "grammar.modifier.MOD", 0, -1, -1, 69, 5, 6, 'e'}, ::ISPA_STD::DFA::API::DFADebug {"depends", "advanced_rule.dep_decl.DEPENDS", 0, -1, -1, 98, 6, 7, 's'}};
std::unordered_map<long long, std::unordered_map<long long, long long>> Parser::Lexer::debug_index = { { 0, { { 9, 0 }, { 10, 1 }, { 11, 2 }, { 12, 3 }, { 13, 4 }, { 32, 5 }, { 35, 6 }, { 36, 7 }, { 38, 8 }, { 39, 9 }, { 40, 10 }, { 41, 11 }, { 44, 12 }, { 45, 13 }, { 46, 14 }, { 58, 15 }, { 59, 16 }, { 60, 17 }, { 61, 18 }, { 62, 19 }, { 64, 20 }, { 91, 21 }, { 92, 22 }, { 93, 23 }, { 123, 24 }, { 124, 25 }, { 125, 26 } } }, { 1, { { 9, 0 }, { 10, 1 }, { 11, 2 }, { 12, 3 }, { 13, 4 }, { 32, 5 } } }, { 2, { { 91, 27 } } }, { 5, { { 39, 28 } } }, { 11, { { 62, 29 } } }, { 13, { { 48, 30 }, { 49, 31 }, { 50, 32 }, { 51, 33 }, { 52, 34 }, { 53, 35 }, { 54, 36 }, { 55, 37 }, { 56, 38 }, { 57, 39 } } }, { 17, { { 62, 40 } } }, { 21, { { 48, 41 }, { 49, 42 }, { 50, 43 }, { 51, 44 }, { 52, 45 }, { 53, 46 }, { 54, 47 }, { 55, 48 }, { 56, 49 }, { 57, 50 }, { 65, 51 }, { 66, 52 }, { 67, 53 }, { 68, 54 }, { 69, 55 }, { 70, 56 }, { 71, 57 }, { 72, 58 }, { 73, 59 }, { 74, 60 }, { 75, 61 }, { 76, 62 }, { 77, 63 }, { 78, 64 }, { 79, 65 }, { 80, 66 }, { 81, 67 }, { 82, 68 }, { 83, 69 }, { 84, 70 }, { 85, 71 }, { 86, 72 }, { 87, 73 }, { 88, 74 }, { 89, 75 }, { 90, 76 }, { 95, 77 }, { 97, 78 }, { 98, 79 }, { 99, 80 }, { 100, 81 }, { 101, 82 }, { 102, 83 }, { 103, 84 }, { 104, 85 }, { 105, 86 }, { 106, 87 }, { 107, 88 }, { 108, 89 }, { 109, 90 }, { 110, 91 }, { 111, 92 }, { 112, 93 }, { 113, 94 }, { 114, 95 }, { 115, 96 }, { 116, 97 }, { 117, 98 }, { 118, 99 }, { 119, 100 }, { 120, 101 }, { 121, 102 }, { 122, 103 } } }, { 23, { { 115, 104 } } }, { 25, { { 101, 105 } } }, { 26, { { 120, 106 } } }, { 27, { { 97, 107 } } }, { 28, { { 110, 108 } } }, { 29, { { 97, 109 } } }, { 30, { { 123, 110 } } }, { 31, { { 107, 111 } } }, { 36, { { 0, 112 }, { 1, 113 }, { 2, 114 }, { 3, 115 }, { 4, 116 }, { 5, 117 }, { 6, 118 }, { 7, 119 }, { 8, 120 }, { 9, 121 }, { 10, 122 }, { 11, 123 }, { 12, 124 }, { 13, 125 }, { 14, 126 }, { 15, 127 }, { 16, 128 }, { 17, 129 }, { 18, 130 }, { 19, 131 }, { 20, 132 }, { 21, 133 }, { 22, 134 }, { 23, 135 }, { 24, 136 }, { 25, 137 }, { 26, 138 }, { 27, 139 }, { 28, 140 }, { 29, 141 }, { 30, 142 }, { 31, 143 }, { 32, 144 }, { 33, 145 }, { 34, 146 }, { 35, 147 }, { 36, 148 }, { 37, 149 }, { 38, 150 }, { 40, 151 }, { 41, 152 }, { 42, 153 }, { 43, 154 }, { 44, 155 }, { 45, 156 }, { 46, 157 }, { 47, 158 }, { 48, 159 }, { 49, 160 }, { 50, 161 }, { 51, 162 }, { 52, 163 }, { 53, 164 }, { 54, 165 }, { 55, 166 }, { 56, 167 }, { 57, 168 }, { 58, 169 }, { 59, 170 }, { 60, 171 }, { 61, 172 }, { 62, 173 }, { 63, 174 }, { 64, 175 }, { 65, 176 }, { 66, 177 }, { 67, 178 }, { 68, 179 }, { 69, 180 }, { 70, 181 }, { 71, 182 }, { 72, 183 }, { 73, 184 }, { 74, 185 }, { 75, 186 }, { 76, 187 }, { 77, 188 }, { 78, 189 }, { 79, 190 }, { 80, 191 }, { 81, 192 }, { 82, 193 }, { 83, 194 }, { 84, 195 }, { 85, 196 }, { 86, 197 }, { 87, 198 }, { 88, 199 }, { 89, 200 }, { 90, 201 }, { 91, 202 }, { 92, 203 }, { 93, 204 }, { 94, 205 }, { 95, 206 }, { 96, 207 }, { 97, 208 }, { 98, 209 }, { 99, 210 }, { 100, 211 }, { 101, 212 }, { 102, 213 }, { 103, 214 }, { 104, 215 }, { 105, 216 }, { 106, 217 }, { 107, 218 }, { 108, 219 }, { 109, 220 }, { 110, 221 }, { 111, 222 }, { 112, 223 }, { 113, 224 }, { 114, 225 }, { 115, 226 }, { 116, 227 }, { 117, 228 }, { 118, 229 }, { 119, 230 }, { 120, 231 }, { 121, 232 }, { 122, 233 }, { 123, 234 }, { 124, 235 }, { 125, 236 }, { 126, 237 }, { 127, 238 } } }, { 38, { { 0, 239 }, { 1, 240 }, { 2, 241 }, { 3, 242 }, { 4, 243 }, { 5, 244 }, { 6, 245 }, { 7, 246 }, { 8, 247 }, { 9, 248 }, { 10, 249 }, { 11, 250 }, { 12, 251 }, { 13, 252 }, { 14, 253 }, { 15, 254 }, { 16, 255 }, { 17, 256 }, { 18, 257 }, { 19, 258 }, { 20, 259 }, { 21, 260 }, { 22, 261 }, { 23, 262 }, { 24, 263 }, { 25, 264 }, { 26, 265 }, { 27, 266 }, { 28, 267 }, { 29, 268 }, { 30, 269 }, { 31, 270 }, { 32, 271 }, { 33, 272 }, { 34, 273 }, { 35, 274 }, { 36, 275 }, { 37, 276 }, { 38, 277 }, { 39, 278 }, { 40, 279 }, { 41, 280 }, { 42, 281 }, { 43, 282 }, { 44, 283 }, { 45, 284 }, { 46, 285 }, { 47, 286 }, { 48, 287 }, { 49, 288 }, { 50, 289 }, { 51, 290 }, { 52, 291 }, { 53, 292 }, { 54, 293 }, { 55, 294 }, { 56, 295 }, { 57, 296 }, { 58, 297 }, { 59, 298 }, { 60, 299 }, { 61, 300 }, { 62, 301 }, { 63, 302 }, { 64, 303 }, { 65, 304 }, { 66, 305 }, { 67, 306 }, { 68, 307 }, { 69, 308 }, { 70, 309 }, { 71, 310 }, { 72, 311 }, { 73, 312 }, { 74, 313 }, { 75, 314 }, { 76, 315 }, { 77, 316 }, { 78, 317 }, { 79, 318 }, { 80, 319 }, { 81, 320 }, { 82, 321 }, { 83, 322 }, { 84, 323 }, { 85, 324 }, { 86, 325 }, { 87, 326 }, { 88, 327 }, { 89, 328 }, { 90, 329 }, { 91, 330 }, { 92, 331 }, { 93, 332 }, { 94, 333 }, { 95, 334 }, { 96, 335 }, { 97, 336 }, { 98, 337 }, { 99, 338 }, { 100, 339 }, { 101, 340 }, { 102, 341 }, { 103, 342 }, { 104, 343 }, { 105, 344 }, { 106, 345 }, { 107, 346 }, { 108, 347 }, { 109, 348 }, { 110, 349 }, { 111, 350 }, { 112, 351 }, { 113, 352 }, { 114, 353 }, { 115, 354 }, { 116, 355 }, { 117, 356 }, { 118, 357 }, { 119, 358 }, { 120, 359 }, { 121, 360 }, { 122, 361 }, { 123, 362 }, { 124, 363 }, { 125, 364 }, { 126, 365 }, { 127, 366 } } }, { 42, { { 48, 41 }, { 49, 42 }, { 50, 43 }, { 51, 44 }, { 52, 45 }, { 53, 46 }, { 54, 47 }, { 55, 48 }, { 56, 49 }, { 57, 50 }, { 65, 51 }, { 66, 52 }, { 67, 53 }, { 68, 54 }, { 69, 55 }, { 70, 56 }, { 71, 57 }, { 72, 58 }, { 73, 59 }, { 74, 60 }, { 75, 61 }, { 76, 62 }, { 77, 63 }, { 78, 64 }, { 79, 65 }, { 80, 66 }, { 81, 67 }, { 82, 68 }, { 83, 69 }, { 84, 70 }, { 85, 71 }, { 86, 72 }, { 87, 73 }, { 88, 74 }, { 89, 75 }, { 90, 76 }, { 95, 77 }, { 97, 78 }, { 98, 79 }, { 99, 80 }, { 100, 81 }, { 101, 82 }, { 102, 83 }, { 103, 84 }, { 104, 85 }, { 105, 86 }, { 106, 87 }, { 107, 88 }, { 108, 89 }, { 109, 90 }, { 110, 91 }, { 111, 92 }, { 112, 93 }, { 113, 94 }, { 114, 95 }, { 115, 96 }, { 116, 97 }, { 117, 98 }, { 118, 99 }, { 119, 100 }, { 120, 101 }, { 121, 102 }, { 122, 103 } } }, { 43, { { 0, 367 }, { 1, 368 }, { 2, 369 }, { 3, 370 }, { 4, 371 }, { 5, 372 }, { 6, 373 }, { 7, 374 }, { 8, 375 }, { 9, 376 }, { 10, 377 }, { 11, 378 }, { 12, 379 }, { 13, 380 }, { 14, 381 }, { 15, 382 }, { 16, 383 }, { 17, 384 }, { 18, 385 }, { 19, 386 }, { 20, 387 }, { 21, 388 }, { 22, 389 }, { 23, 390 }, { 24, 391 }, { 25, 392 }, { 26, 393 }, { 27, 394 }, { 28, 395 }, { 29, 396 }, { 30, 397 }, { 31, 398 }, { 32, 399 }, { 33, 400 }, { 34, 401 }, { 35, 402 }, { 36, 403 }, { 37, 404 }, { 38, 405 }, { 39, 406 }, { 40, 407 }, { 41, 408 }, { 42, 409 }, { 43, 410 }, { 44, 411 }, { 45, 412 }, { 46, 413 }, { 47, 414 }, { 48, 415 }, { 49, 416 }, { 50, 417 }, { 51, 418 }, { 52, 419 }, { 53, 420 }, { 54, 421 }, { 55, 422 }, { 56, 423 }, { 57, 424 }, { 58, 425 }, { 59, 426 }, { 60, 427 }, { 61, 428 }, { 62, 429 }, { 63, 430 }, { 64, 431 }, { 65, 432 }, { 66, 433 }, { 67, 434 }, { 68, 435 }, { 69, 436 }, { 70, 437 }, { 71, 438 }, { 72, 439 }, { 73, 440 }, { 74, 441 }, { 75, 442 }, { 76, 443 }, { 77, 444 }, { 78, 445 }, { 79, 446 }, { 80, 447 }, { 81, 448 }, { 82, 449 }, { 83, 450 }, { 84, 451 }, { 85, 452 }, { 86, 453 }, { 87, 454 }, { 88, 455 }, { 89, 456 }, { 90, 457 }, { 91, 458 }, { 92, 459 }, { 94, 460 }, { 95, 461 }, { 96, 462 }, { 97, 463 }, { 98, 464 }, { 99, 465 }, { 100, 466 }, { 101, 467 }, { 102, 468 }, { 103, 469 }, { 104, 470 }, { 105, 471 }, { 106, 472 }, { 107, 473 }, { 108, 474 }, { 109, 475 }, { 110, 476 }, { 111, 477 }, { 112, 478 }, { 113, 479 }, { 114, 480 }, { 115, 481 }, { 116, 482 }, { 117, 483 }, { 118, 484 }, { 119, 485 }, { 120, 486 }, { 121, 487 }, { 122, 488 }, { 123, 489 }, { 124, 490 }, { 125, 491 }, { 126, 492 }, { 127, 493 } } }, { 44, { { 0, 494 }, { 1, 495 }, { 2, 496 }, { 3, 497 }, { 4, 498 }, { 5, 499 }, { 6, 500 }, { 7, 501 }, { 8, 502 }, { 9, 503 }, { 10, 504 }, { 11, 505 }, { 12, 506 }, { 13, 507 }, { 14, 508 }, { 15, 509 }, { 16, 510 }, { 17, 511 }, { 18, 512 }, { 19, 513 }, { 20, 514 }, { 21, 515 }, { 22, 516 }, { 23, 517 }, { 24, 518 }, { 25, 519 }, { 26, 520 }, { 27, 521 }, { 28, 522 }, { 29, 523 }, { 30, 524 }, { 31, 525 }, { 32, 526 }, { 33, 527 }, { 34, 528 }, { 35, 529 }, { 36, 530 }, { 37, 531 }, { 38, 532 }, { 39, 533 }, { 40, 534 }, { 41, 535 }, { 42, 536 }, { 43, 537 }, { 44, 538 }, { 45, 539 }, { 46, 540 }, { 47, 541 }, { 48, 542 }, { 49, 543 }, { 50, 544 }, { 51, 545 }, { 52, 546 }, { 53, 547 }, { 54, 548 }, { 55, 549 }, { 56, 550 }, { 57, 551 }, { 58, 552 }, { 59, 553 }, { 60, 554 }, { 61, 555 }, { 62, 556 }, { 63, 557 }, { 64, 558 }, { 65, 559 }, { 66, 560 }, { 67, 561 }, { 68, 562 }, { 69, 563 }, { 70, 564 }, { 71, 565 }, { 72, 566 }, { 73, 567 }, { 74, 568 }, { 75, 569 }, { 76, 570 }, { 77, 571 }, { 78, 572 }, { 79, 573 }, { 80, 574 }, { 81, 575 }, { 82, 576 }, { 83, 577 }, { 84, 578 }, { 85, 579 }, { 86, 580 }, { 87, 581 }, { 88, 582 }, { 89, 583 }, { 90, 584 }, { 91, 585 }, { 92, 586 }, { 93, 587 }, { 94, 588 }, { 95, 589 }, { 96, 590 }, { 97, 591 }, { 98, 592 }, { 99, 593 }, { 100, 594 }, { 101, 595 }, { 102, 596 }, { 103, 597 }, { 104, 598 }, { 105, 599 }, { 106, 600 }, { 107, 601 }, { 108, 602 }, { 109, 603 }, { 110, 604 }, { 111, 605 }, { 112, 606 }, { 113, 607 }, { 114, 608 }, { 115, 609 }, { 116, 610 }, { 117, 611 }, { 118, 612 }, { 119, 613 }, { 120, 614 }, { 121, 615 }, { 122, 616 }, { 123, 617 }, { 124, 618 }, { 125, 619 }, { 126, 620 }, { 127, 621 } } }, { 46, { { 48, 622 } } }, { 47, { { 112, 623 } } }, { 48, { { 116, 624 } } }, { 49, { { 105, 625 } } }, { 50, { { 108, 626 } } }, { 51, { { 116, 627 } } }, { 53, { { 105, 628 } } }, { 54, { { 48, 629 }, { 49, 630 }, { 50, 631 }, { 51, 632 }, { 52, 633 }, { 53, 634 }, { 54, 635 }, { 55, 636 }, { 56, 637 }, { 57, 638 } } }, { 56, { { 0, 367 }, { 1, 368 }, { 2, 369 }, { 3, 370 }, { 4, 371 }, { 5, 372 }, { 6, 373 }, { 7, 374 }, { 8, 375 }, { 9, 376 }, { 10, 377 }, { 11, 378 }, { 12, 379 }, { 13, 380 }, { 14, 381 }, { 15, 382 }, { 16, 383 }, { 17, 384 }, { 18, 385 }, { 19, 386 }, { 20, 387 }, { 21, 388 }, { 22, 389 }, { 23, 390 }, { 24, 391 }, { 25, 392 }, { 26, 393 }, { 27, 394 }, { 28, 395 }, { 29, 396 }, { 30, 397 }, { 31, 398 }, { 32, 399 }, { 33, 400 }, { 34, 401 }, { 35, 402 }, { 36, 403 }, { 37, 404 }, { 38, 405 }, { 39, 406 }, { 40, 407 }, { 41, 408 }, { 42, 409 }, { 43, 410 }, { 44, 411 }, { 45, 412 }, { 46, 413 }, { 47, 414 }, { 48, 415 }, { 49, 416 }, { 50, 417 }, { 51, 418 }, { 52, 419 }, { 53, 420 }, { 54, 421 }, { 55, 422 }, { 56, 423 }, { 57, 424 }, { 58, 425 }, { 59, 426 }, { 60, 427 }, { 61, 428 }, { 62, 429 }, { 63, 430 }, { 64, 431 }, { 65, 432 }, { 66, 433 }, { 67, 434 }, { 68, 435 }, { 69, 436 }, { 70, 437 }, { 71, 438 }, { 72, 439 }, { 73, 440 }, { 74, 441 }, { 75, 442 }, { 76, 443 }, { 77, 444 }, { 78, 445 }, { 79, 446 }, { 80, 447 }, { 81, 448 }, { 82, 449 }, { 83, 450 }, { 84, 451 }, { 85, 452 }, { 86, 453 }, { 87, 454 }, { 88, 455 }, { 89, 456 }, { 90, 457 }, { 91, 458 }, { 92, 459 }, { 94, 460 }, { 95, 461 }, { 96, 462 }, { 97, 463 }, { 98, 464 }, { 99, 465 }, { 100, 466 }, { 101, 467 }, { 102, 468 }, { 103, 469 }, { 104, 470 }, { 105, 471 }, { 106, 472 }, { 107, 473 }, { 108, 474 }, { 109, 475 }, { 110, 476 }, { 111, 477 }, { 112, 478 }, { 113, 479 }, { 114, 480 }, { 115, 481 }, { 116, 482 }, { 117, 483 }, { 118, 484 }, { 119, 485 }, { 120, 486 }, { 121, 487 }, { 122, 488 }, { 123, 489 }, { 124, 490 }, { 125, 491 }, { 126, 492 }, { 127, 493 } } }, { 57, { { 0, 494 }, { 1, 495 }, { 2, 496 }, { 3, 497 }, { 4, 498 }, { 5, 499 }, { 6, 500 }, { 7, 501 }, { 8, 502 }, { 9, 503 }, { 10, 504 }, { 11, 505 }, { 12, 506 }, { 13, 507 }, { 14, 508 }, { 15, 509 }, { 16, 510 }, { 17, 511 }, { 18, 512 }, { 19, 513 }, { 20, 514 }, { 21, 515 }, { 22, 516 }, { 23, 517 }, { 24, 518 }, { 25, 519 }, { 26, 520 }, { 27, 521 }, { 28, 522 }, { 29, 523 }, { 30, 524 }, { 31, 525 }, { 32, 526 }, { 33, 527 }, { 34, 528 }, { 35, 529 }, { 36, 530 }, { 37, 531 }, { 38, 532 }, { 39, 533 }, { 40, 534 }, { 41, 535 }, { 42, 536 }, { 43, 537 }, { 44, 538 }, { 45, 539 }, { 46, 540 }, { 47, 541 }, { 48, 542 }, { 49, 543 }, { 50, 544 }, { 51, 545 }, { 52, 546 }, { 53, 547 }, { 54, 548 }, { 55, 549 }, { 56, 550 }, { 57, 551 }, { 58, 552 }, { 59, 553 }, { 60, 554 }, { 61, 555 }, { 62, 556 }, { 63, 557 }, { 64, 558 }, { 65, 559 }, { 66, 560 }, { 67, 561 }, { 68, 562 }, { 69, 563 }, { 70, 564 }, { 71, 565 }, { 72, 566 }, { 73, 567 }, { 74, 568 }, { 75, 569 }, { 76, 570 }, { 77, 571 }, { 78, 572 }, { 79, 573 }, { 80, 574 }, { 81, 575 }, { 82, 576 }, { 83, 577 }, { 84, 578 }, { 85, 579 }, { 86, 580 }, { 87, 581 }, { 88, 582 }, { 89, 583 }, { 90, 584 }, { 91, 585 }, { 92, 586 }, { 93, 587 }, { 94, 588 }, { 95, 589 }, { 96, 590 }, { 97, 591 }, { 98, 592 }, { 99, 593 }, { 100, 594 }, { 101, 595 }, { 102, 596 }, { 103, 597 }, { 104, 598 }, { 105, 599 }, { 106, 600 }, { 107, 601 }, { 108, 602 }, { 109, 603 }, { 110, 604 }, { 111, 605 }, { 112, 606 }, { 113, 607 }, { 114, 608 }, { 115, 609 }, { 116, 610 }, { 117, 611 }, { 118, 612 }, { 119, 613 }, { 120, 614 }, { 121, 615 }, { 122, 616 }, { 123, 617 }, { 124, 618 }, { 125, 619 }, { 126, 620 }, { 127, 621 } } }, { 59, { { 101, 639 } } }, { 60, { { 101, 640 } } }, { 61, { { 108, 641 } } }, { 62, { { 105, 642 } } }, { 63, { { 99, 643 } } }, { 64, { { 121, 644 } } }, { 65, { { 112, 645 } } }, { 67, { { 110, 646 } } }, { 68, { { 114, 647 } } }, { 70, { { 110, 648 } } }, { 71, { { 104, 649 } } }, { 74, { { 100, 650 } } }, { 75, { { 110, 651 } } }, { 76, { { 101, 652 } } }, { 79, { { 115, 653 } } } };
template<typename IT, class> auto Parser::Parser::advanced_rule(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::advanced_rule, IT> {
	::ISPA_STD::Node<::Parser::Tokens, Types::LEFT_CURLY_BRACKET> LEFT_CURLY_BRACKET_0;
	bool success_1;
	::ISPA_STD::MatchResult<Rules, Types::advanced_rule::dep_decl, IT> advanced_rule_dep_decl_5;
	bool success_6;
	::ISPA_STD::Node<::Parser::Rules, Types::advanced_rule::dep_decl> element_7;
	std::vector<::ISPA_STD::Node<::Parser::Rules, Types::advanced_rule::dep_decl>> shadow_8;
	std::vector<::ISPA_STD::Node<::Parser::Rules, Types::advanced_rule::dep_decl>> uvar_4;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	bool success_16;
	std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Rules, Types::stmt>, ::ISPA_STD::Node<::Parser::Rules, Types::advanced_rule::regular_match>> group_12;
	bool success_14;
	std::vector<std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Rules, Types::stmt>, ::ISPA_STD::Node<::Parser::Rules, Types::advanced_rule::regular_match>>> shadow_27;
	std::vector<std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Rules, Types::stmt>, ::ISPA_STD::Node<::Parser::Rules, Types::advanced_rule::regular_match>>> uvar_13;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_10;
	bool success_11;
	std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Rules, Types::stmt>, ::ISPA_STD::Node<::Parser::Rules, Types::advanced_rule::regular_match>> _15;
	::ISPA_STD::MatchResult<Rules, Types::stmt, IT> stmt_18;
	bool success_19;
	::ISPA_STD::Node<::Parser::Rules, Types::stmt> element_20;
	std::vector<::ISPA_STD::Node<::Parser::Rules, Types::stmt>> shadow_21;
	::ISPA_STD::Node<::Parser::Rules, Types::stmt> uvar_17;
	::ISPA_STD::MatchResult<Rules, Types::advanced_rule::regular_match, IT> advanced_rule_regular_match_23;
	bool success_24;
	::ISPA_STD::Node<::Parser::Rules, Types::advanced_rule::regular_match> element_25;
	std::vector<::ISPA_STD::Node<::Parser::Rules, Types::advanced_rule::regular_match>> shadow_26;
	::ISPA_STD::Node<::Parser::Rules, Types::advanced_rule::regular_match> uvar_22;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_30;
	bool success_31;
	::ISPA_STD::Node<::Parser::Tokens, Types::RIGHT_CURLY_BRACKET> RIGHT_CURLY_BRACKET_32;
	bool success_33;
	success_1 = false;
	if (!(((*pos)).template holds<Types::LEFT_CURLY_BRACKET>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  LEFT_CURLY_BRACKET");
		return {};
	}
	LEFT_CURLY_BRACKET_0 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::LEFT_CURLY_BRACKET>>();
	success_1 = true;
	pos++;
	success_6 = false;
	// grammar `@  advanced_rule::dep_decl*;`: repeat named rule; collect every matched value
	while (true) {
		auto repeat_ws_9 = pos;
		success_3 = false;
		if (((*repeat_ws_9)).template holds<Types::__WS>()) {
			__WS_2 = ((*repeat_ws_9)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
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
			__WS_10 = ((*repeat_ws_29)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
			success_11 = true;
			repeat_ws_29++;
		}
		skip_spaces<Types::__WS>(repeat_ws_29);
		// grammar ` ( advanced_rule::regular_match |  stmt)`: choice; reset match status before selecting an alternative
		success_16 = false;
		auto lookahead_pos_1 = repeat_ws_29;
		switch (static_cast<Tokens>((*lookahead_pos_1).kind())) {
			case Tokens::PY_RAW: {
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
			case Tokens::advanced_rule_regular_match_MATCH: {
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
		__WS_30 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_31 = true;
		pos++;
	}
	success_33 = false;
	if (!(((*pos)).template holds<Types::RIGHT_CURLY_BRACKET>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  RIGHT_CURLY_BRACKET");
		return {};
	}
	RIGHT_CURLY_BRACKET_32 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::RIGHT_CURLY_BRACKET>>();
	success_33 = true;
	pos++;
	Types::advanced_rule result;
	::ISPA_STD::assign_compatible(result.dep, uvar_4);
	::ISPA_STD::assign_compatible(result.body, uvar_13);
	::ISPA_STD::MatchResult<Rules, Types::advanced_rule, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::advanced_rule<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::advanced_rule, ::Parser::Lexer::iterator>;
template auto Parser::Parser::advanced_rule<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::advanced_rule, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::advanced_rule_dep_decl(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::advanced_rule::dep_decl, IT> {
	::ISPA_STD::Node<::Parser::Tokens, Types::advanced_rule::dep_decl::DEPENDS> advanced_rule_dep_decl_DEPENDS_0;
	bool success_1;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::MatchResult<Rules, Types::forward_declaration, IT> forward_declaration_4;
	bool success_5;
	success_1 = false;
	if (!(((*pos)).template holds<Types::advanced_rule::dep_decl::DEPENDS>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  advanced_rule::dep_decl::DEPENDS");
		return {};
	}
	advanced_rule_dep_decl_DEPENDS_0 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::advanced_rule::dep_decl::DEPENDS>>();
	success_1 = true;
	pos++;
	success_3 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_2 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
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
	::ISPA_STD::MatchResult<Rules, Types::advanced_rule::dep_decl, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::advanced_rule_dep_decl<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::advanced_rule::dep_decl, ::Parser::Lexer::iterator>;
template auto Parser::Parser::advanced_rule_dep_decl<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::advanced_rule::dep_decl, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::advanced_rule_fail_call(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::advanced_rule::fail_call, IT> {
	::ISPA_STD::Node<::Parser::Tokens, Types::FAIL> FAIL_0;
	bool success_1;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::MatchResult<Rules, Types::name, IT> name_4;
	bool success_5;
	success_1 = false;
	if (!(((*pos)).template holds<Types::FAIL>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  FAIL");
		return {};
	}
	FAIL_0 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::FAIL>>();
	success_1 = true;
	pos++;
	success_3 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_2 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
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
	::ISPA_STD::MatchResult<Rules, Types::advanced_rule::fail_call, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::advanced_rule_fail_call<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::advanced_rule::fail_call, ::Parser::Lexer::iterator>;
template auto Parser::Parser::advanced_rule_fail_call<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::advanced_rule::fail_call, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::advanced_rule_regular_match(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::advanced_rule::regular_match, IT> {
	::ISPA_STD::Node<::Parser::Tokens, Types::advanced_rule::regular_match::MATCH> advanced_rule_regular_match_MATCH_0;
	bool success_1;
	::ISPA_STD::MatchResult<Rules, Types::rule::value, IT> rule_value_5;
	bool success_6;
	::ISPA_STD::Node<::Parser::Rules, Types::rule::value> element_7;
	std::vector<::ISPA_STD::Node<::Parser::Rules, Types::rule::value>> shadow_8;
	std::vector<::ISPA_STD::Node<::Parser::Rules, Types::rule::value>> uvar_4;
	bool success_9;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_11;
	bool success_12;
	std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Tokens, Types::SEMICOLON>, ::ISPA_STD::Node<::Parser::Rules, Types::advanced_rule::regular_match::unpack>> _13;
	bool success_14;
	::ISPA_STD::MatchResult<Rules, Types::advanced_rule::regular_match::unpack, IT> advanced_rule_regular_match_unpack_15;
	bool success_16;
	::ISPA_STD::Node<::Parser::Tokens, Types::SEMICOLON> SEMICOLON_17;
	bool success_18;
	success_1 = false;
	if (!(((*pos)).template holds<Types::advanced_rule::regular_match::MATCH>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  advanced_rule::regular_match::MATCH");
		return {};
	}
	advanced_rule_regular_match_MATCH_0 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::advanced_rule::regular_match::MATCH>>();
	success_1 = true;
	pos++;
	success_6 = false;
	// grammar `@  rule::value+;`: repeat named rule; collect every matched value
	success_9 = false;
	while (true) {
		auto repeat_ws_10 = pos;
		success_3 = false;
		if (((*repeat_ws_10)).template holds<Types::__WS>()) {
			__WS_2 = ((*repeat_ws_10)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
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
		__WS_11 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_12 = true;
		pos++;
	}
	success_14 = false;
	// grammar `@  ( advanced_rule::regular_match::unpack |  SEMICOLON)`: choice; reset match status before selecting an alternative
	success_14 = false;
	auto lookahead_pos_1 = pos;
	switch (static_cast<Tokens>((*lookahead_pos_1).kind())) {
		case Tokens::AUTO: {
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
		case Tokens::SEMICOLON: {
			lookahead_pos_1 = lookahead_pos_1;
			success_18 = false;
			if (!(((*lookahead_pos_1)).template holds<Types::SEMICOLON>())) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  SEMICOLON");
				return {};
			}
			SEMICOLON_17 = ((*lookahead_pos_1)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::SEMICOLON>>();
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
	::ISPA_STD::MatchResult<Rules, Types::advanced_rule::regular_match, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::advanced_rule_regular_match<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::advanced_rule::regular_match, ::Parser::Lexer::iterator>;
template auto Parser::Parser::advanced_rule_regular_match<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::advanced_rule::regular_match, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::advanced_rule_regular_match_unpack(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::advanced_rule::regular_match::unpack, IT> {
	::ISPA_STD::Node<::Parser::Tokens, Types::AUTO> AUTO_0;
	bool success_1;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::Node<::Parser::Tokens, Types::ID> ID_5;
	bool success_6;
	std::vector<::ISPA_STD::Node<::Parser::Tokens, Types::ID>> uvar_4;
	std::vector<::ISPA_STD::Node<::Parser::Tokens, Types::ID>> shadow_7;
	bool success_8;
	success_1 = false;
	if (!(((*pos)).template holds<Types::AUTO>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  AUTO");
		return {};
	}
	AUTO_0 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::AUTO>>();
	success_1 = true;
	pos++;
	success_3 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_2 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_3 = true;
		pos++;
	}
	success_6 = false;
	success_8 = false;
	while (((*pos)).template holds<Types::ID>()) {
		ID_5 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::ID>>();
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
	::ISPA_STD::MatchResult<Rules, Types::advanced_rule::regular_match::unpack, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::advanced_rule_regular_match_unpack<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::advanced_rule::regular_match::unpack, ::Parser::Lexer::iterator>;
template auto Parser::Parser::advanced_rule_regular_match_unpack<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::advanced_rule::regular_match::unpack, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::explicit_expr(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::explicit_expr, IT> {
	::ISPA_STD::Node<::Parser::Tokens, Types::LEFT_PARENTHESIS> LEFT_PARENTHESIS_0;
	bool success_1;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::MatchResult<Rules, Types::expr, IT> expr_4;
	bool success_5;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_6;
	bool success_7;
	::ISPA_STD::Node<::Parser::Tokens, Types::RIGHT_PARENTHESIS> RIGHT_PARENTHESIS_8;
	bool success_9;
	success_1 = false;
	if (!(((*pos)).template holds<Types::LEFT_PARENTHESIS>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  LEFT_PARENTHESIS");
		return {};
	}
	LEFT_PARENTHESIS_0 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::LEFT_PARENTHESIS>>();
	success_1 = true;
	pos++;
	success_3 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_2 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
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
		__WS_6 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_7 = true;
		pos++;
	}
	success_9 = false;
	if (!(((*pos)).template holds<Types::RIGHT_PARENTHESIS>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  RIGHT_PARENTHESIS");
		return {};
	}
	RIGHT_PARENTHESIS_8 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::RIGHT_PARENTHESIS>>();
	success_9 = true;
	pos++;
	Types::explicit_expr result;
	::ISPA_STD::assign_compatible(result.value, expr_4.node);
	::ISPA_STD::MatchResult<Rules, Types::explicit_expr, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::explicit_expr<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::explicit_expr, ::Parser::Lexer::iterator>;
template auto Parser::Parser::explicit_expr<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::explicit_expr, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::expr(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::expr, IT> {
	::ISPA_STD::Node<::Parser::Tokens, Types::PY_RAW> PY_RAW_0;
	bool success_1;
	success_1 = false;
	if (!(((*pos)).template holds<Types::PY_RAW>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar: @  PY_RAW");
		return {};
	}
	PY_RAW_0 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::PY_RAW>>();
	success_1 = true;
	pos++;
	Types::expr result;
	::ISPA_STD::assign_compatible(result.value, PY_RAW_0);
	::ISPA_STD::MatchResult<Rules, Types::expr, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::expr<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::expr, ::Parser::Lexer::iterator>;
template auto Parser::Parser::expr<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::expr, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::fail_block(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::fail_block, IT> {
	::ISPA_STD::Node<::Parser::Tokens, Types::FAIL> FAIL_0;
	bool success_1;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::MatchResult<Rules, Types::name, IT> name_4;
	bool success_5;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_6;
	bool success_7;
	::ISPA_STD::MatchResult<Rules, Types::stmt, IT> stmt_8;
	bool success_9;
	success_1 = false;
	if (!(((*pos)).template holds<Types::FAIL>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  FAIL");
		return {};
	}
	FAIL_0 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::FAIL>>();
	success_1 = true;
	pos++;
	success_3 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_2 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
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
		__WS_6 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
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
	::ISPA_STD::MatchResult<Rules, Types::fail_block, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::fail_block<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::fail_block, ::Parser::Lexer::iterator>;
template auto Parser::Parser::fail_block<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::fail_block, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::forward_declaration(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::forward_declaration, IT> {
	::ISPA_STD::Node<::Parser::Tokens, Types::AUTO> AUTO_0;
	bool success_1;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::Node<::Parser::Tokens, Types::ID> ID_4;
	bool success_5;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_6;
	bool success_7;
	::ISPA_STD::Node<::Parser::Tokens, Types::AUTO> AUTO_8;
	bool success_9;
	success_1 = false;
	if (!(((*pos)).template holds<Types::AUTO>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  AUTO");
		return {};
	}
	AUTO_0 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::AUTO>>();
	success_1 = true;
	pos++;
	success_3 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_2 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_3 = true;
		pos++;
	}
	success_5 = false;
	if (!(((*pos)).template holds<Types::ID>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar: @  ID");
		return {};
	}
	ID_4 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::ID>>();
	success_5 = true;
	pos++;
	success_7 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_6 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_7 = true;
		pos++;
	}
	success_9 = false;
	if (!(((*pos)).template holds<Types::AUTO>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  AUTO");
		return {};
	}
	AUTO_8 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::AUTO>>();
	success_9 = true;
	pos++;
	Types::forward_declaration result;
	::ISPA_STD::assign_compatible(result.value, ID_4);
	::ISPA_STD::MatchResult<Rules, Types::forward_declaration, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::forward_declaration<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::forward_declaration, ::Parser::Lexer::iterator>;
template auto Parser::Parser::forward_declaration<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::forward_declaration, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::grammar(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::grammar, IT> {
	::ISPA_STD::MatchResult<Rules, Types::grammar::modifier, IT> grammar_modifier_1;
	bool success_2;
	::ISPA_STD::Node<::Parser::Rules, Types::grammar::modifier> element_3;
	std::vector<::ISPA_STD::Node<::Parser::Rules, Types::grammar::modifier>> shadow_4;
	std::vector<::ISPA_STD::Node<::Parser::Rules, Types::grammar::modifier>> uvar_0;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_5;
	bool success_6;
	::ISPA_STD::MatchResult<Rules, Types::name, IT> name_7;
	bool success_8;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_9;
	bool success_10;
	std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Rules, Types::advanced_rule>, ::ISPA_STD::Node<::Parser::Rules, Types::rule>> _11;
	bool success_12;
	::ISPA_STD::MatchResult<Rules, Types::rule, IT> rule_13;
	bool success_14;
	::ISPA_STD::MatchResult<Rules, Types::advanced_rule, IT> advanced_rule_15;
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
		__WS_5 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
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
		__WS_9 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_10 = true;
		pos++;
	}
	success_12 = false;
	// grammar `@  ( rule |  advanced_rule)`: choice; reset match status before selecting an alternative
	success_12 = false;
	auto lookahead_pos_1 = pos;
	switch (static_cast<Tokens>((*lookahead_pos_1).kind())) {
		case Tokens::COLON: {
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
		case Tokens::LEFT_CURLY_BRACKET: {
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
	::ISPA_STD::MatchResult<Rules, Types::grammar, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::grammar<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::grammar, ::Parser::Lexer::iterator>;
template auto Parser::Parser::grammar<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::grammar, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::grammar_modifier(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::grammar::modifier, IT> {
	::ISPA_STD::Node<::Parser::Tokens, Types::grammar::modifier::AUTO> grammar_modifier_AUTO_0;
	bool success_1;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::Node<::Parser::Tokens, Types::grammar::modifier::MOD> grammar_modifier_MOD_4;
	bool success_5;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_6;
	bool success_7;
	::ISPA_STD::Node<::Parser::Tokens, Types::grammar::modifier::RIGHT_SQUARE_BRACKET> grammar_modifier_RIGHT_SQUARE_BRACKET_8;
	bool success_9;
	success_1 = false;
	if (!(((*pos)).template holds<Types::grammar::modifier::AUTO>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  grammar::modifier::AUTO");
		return {};
	}
	grammar_modifier_AUTO_0 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::grammar::modifier::AUTO>>();
	success_1 = true;
	pos++;
	success_3 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_2 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_3 = true;
		pos++;
	}
	success_5 = false;
	if (!(((*pos)).template holds<Types::grammar::modifier::MOD>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar: @  grammar::modifier::MOD");
		return {};
	}
	grammar_modifier_MOD_4 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::grammar::modifier::MOD>>();
	success_5 = true;
	pos++;
	success_7 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_6 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_7 = true;
		pos++;
	}
	success_9 = false;
	if (!(((*pos)).template holds<Types::grammar::modifier::RIGHT_SQUARE_BRACKET>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  grammar::modifier::RIGHT_SQUARE_BRACKET");
		return {};
	}
	grammar_modifier_RIGHT_SQUARE_BRACKET_8 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::grammar::modifier::RIGHT_SQUARE_BRACKET>>();
	success_9 = true;
	pos++;
	Types::grammar::modifier result;
	::ISPA_STD::assign_compatible(result.value, grammar_modifier_MOD_4);
	::ISPA_STD::MatchResult<Rules, Types::grammar::modifier, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::grammar_modifier<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::grammar::modifier, ::Parser::Lexer::iterator>;
template auto Parser::Parser::grammar_modifier<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::grammar::modifier, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::main(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::main, IT> {
	bool success_4;
	std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Rules, Types::fail_block>, ::ISPA_STD::Node<::Parser::Rules, Types::grammar>> group_0;
	bool success_2;
	std::vector<std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Rules, Types::fail_block>, ::ISPA_STD::Node<::Parser::Rules, Types::grammar>>> shadow_20;
	std::vector<std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Rules, Types::fail_block>, ::ISPA_STD::Node<::Parser::Rules, Types::grammar>>> uvar_1;
	std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Rules, Types::fail_block>, ::ISPA_STD::Node<::Parser::Rules, Types::grammar>> _3;
	::ISPA_STD::MatchResult<Rules, Types::fail_block, IT> fail_block_6;
	bool success_7;
	::ISPA_STD::Node<::Parser::Rules, Types::fail_block> element_8;
	std::vector<::ISPA_STD::Node<::Parser::Rules, Types::fail_block>> shadow_9;
	::ISPA_STD::Node<::Parser::Rules, Types::fail_block> uvar_5;
	::ISPA_STD::MatchResult<Rules, Types::grammar, IT> grammar_11;
	bool success_12;
	::ISPA_STD::Node<::Parser::Rules, Types::grammar> element_13;
	std::vector<::ISPA_STD::Node<::Parser::Rules, Types::grammar>> shadow_14;
	::ISPA_STD::Node<::Parser::Rules, Types::grammar> uvar_10;
	::ISPA_STD::MatchResult<Rules, Types::grammar, IT> grammar_16;
	bool success_17;
	::ISPA_STD::Node<::Parser::Rules, Types::grammar> element_18;
	std::vector<::ISPA_STD::Node<::Parser::Rules, Types::grammar>> shadow_19;
	::ISPA_STD::Node<::Parser::Rules, Types::grammar> uvar_15;
	success_2 = false;
	auto begin_21 = pos;
	while (true) {
		skip_spaces<Types::__WS>(begin_21);
		// grammar ` ( grammar |  fail_block)`: choice; reset match status before selecting an alternative
		success_4 = false;
		auto lookahead_pos_1 = begin_21;
		switch (static_cast<Tokens>((*lookahead_pos_1).kind())) {
			case Tokens::FAIL: {
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
			case Tokens::ID: {
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
			case Tokens::grammar_modifier_AUTO: {
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
	::ISPA_STD::MatchResult<Rules, Types::main, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::main<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::main, ::Parser::Lexer::iterator>;
template auto Parser::Parser::main<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::main, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::name(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::name, IT> {
	::ISPA_STD::Node<::Parser::Tokens, Types::ID> ID_0;
	bool success_1;
	bool success_17;
	bool success_9;
	std::vector<::ISPA_STD::Node<::Parser::Tokens, Types::AUTO>> shadow_19;
	std::vector<::ISPA_STD::Node<::Parser::Tokens, Types::ID>> shadow_20;
	std::tuple<::ISPA_STD::Node<::Parser::Tokens, Types::AUTO>, ::ISPA_STD::Node<::Parser::Tokens, Types::__WS>, ::ISPA_STD::Node<::Parser::Tokens, Types::ID>> group_4;
	bool success_6;
	std::vector<std::tuple<::ISPA_STD::Node<::Parser::Tokens, Types::AUTO>, ::ISPA_STD::Node<::Parser::Tokens, Types::__WS>, ::ISPA_STD::Node<::Parser::Tokens, Types::ID>>> shadow_21;
	std::vector<std::tuple<::ISPA_STD::Node<::Parser::Tokens, Types::AUTO>, ::ISPA_STD::Node<::Parser::Tokens, Types::__WS>, ::ISPA_STD::Node<::Parser::Tokens, Types::ID>>> uvar_5;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::Node<::Parser::Tokens, Types::AUTO> AUTO_8;
	::ISPA_STD::Node<::Parser::Tokens, Types::AUTO> uvar_7;
	std::vector<::ISPA_STD::Node<::Parser::Tokens, Types::AUTO>> shadow_10;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_12;
	bool success_13;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> uvar_11;
	std::vector<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>> shadow_14;
	::ISPA_STD::Node<::Parser::Tokens, Types::ID> ID_16;
	::ISPA_STD::Node<::Parser::Tokens, Types::ID> uvar_15;
	std::vector<::ISPA_STD::Node<::Parser::Tokens, Types::ID>> shadow_18;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_24;
	bool success_25;
	::ISPA_STD::MatchResult<Rules, Types::template_params, IT> template_params_26;
	bool success_27;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_28;
	bool success_29;
	::ISPA_STD::MatchResult<Rules, Types::params, IT> params_30;
	bool success_31;
	success_1 = false;
	if (!(((*pos)).template holds<Types::ID>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar: @  ID");
		return {};
	}
	ID_0 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::ID>>();
	success_1 = true;
	pos++;
	success_6 = false;
	auto begin_22 = pos;
	while (true) {
		auto repeat_ws_23 = begin_22;
		success_3 = false;
		if (((*repeat_ws_23)).template holds<Types::__WS>()) {
			__WS_2 = ((*repeat_ws_23)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
			success_3 = true;
			repeat_ws_23++;
		}
		if (!(((*repeat_ws_23)).template holds<Types::AUTO>())) {
			// speculative match failed (diagnostic suppressed):  AUTO
			break;
		}
		AUTO_8 = ((*repeat_ws_23)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::AUTO>>();
		success_9 = true;
		repeat_ws_23++;
		shadow_10.push_back(AUTO_8);
		uvar_7 = AUTO_8;
		success_13 = false;
		if (((*repeat_ws_23)).template holds<Types::__WS>()) {
			__WS_12 = ((*repeat_ws_23)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
			success_13 = true;
			repeat_ws_23++;
			shadow_14.push_back(__WS_12);
			uvar_11 = __WS_12;
		}
		if (!(((*repeat_ws_23)).template holds<Types::ID>())) {
			// speculative match failed (diagnostic suppressed): @  ID
			break;
		}
		ID_16 = ((*repeat_ws_23)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::ID>>();
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
		__WS_24 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
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
		__WS_28 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
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
	::ISPA_STD::MatchResult<Rules, Types::name, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::name<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::name, ::Parser::Lexer::iterator>;
template auto Parser::Parser::name<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::name, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::param(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::param, IT> {
	::ISPA_STD::Node<::Parser::Tokens, Types::ID> ID_0;
	bool success_1;
	bool success_17;
	bool success_9;
	std::vector<::ISPA_STD::Node<::Parser::Tokens, Types::COMMA>> shadow_19;
	std::vector<::ISPA_STD::Node<::Parser::Tokens, Types::ID>> shadow_20;
	std::tuple<::ISPA_STD::Node<::Parser::Tokens, Types::COMMA>, ::ISPA_STD::Node<::Parser::Tokens, Types::__WS>, ::ISPA_STD::Node<::Parser::Tokens, Types::ID>> group_4;
	bool success_6;
	std::vector<std::tuple<::ISPA_STD::Node<::Parser::Tokens, Types::COMMA>, ::ISPA_STD::Node<::Parser::Tokens, Types::__WS>, ::ISPA_STD::Node<::Parser::Tokens, Types::ID>>> shadow_21;
	std::vector<std::tuple<::ISPA_STD::Node<::Parser::Tokens, Types::COMMA>, ::ISPA_STD::Node<::Parser::Tokens, Types::__WS>, ::ISPA_STD::Node<::Parser::Tokens, Types::ID>>> uvar_5;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::Node<::Parser::Tokens, Types::COMMA> COMMA_8;
	::ISPA_STD::Node<::Parser::Tokens, Types::COMMA> uvar_7;
	std::vector<::ISPA_STD::Node<::Parser::Tokens, Types::COMMA>> shadow_10;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_12;
	bool success_13;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> uvar_11;
	std::vector<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>> shadow_14;
	::ISPA_STD::Node<::Parser::Tokens, Types::ID> ID_16;
	::ISPA_STD::Node<::Parser::Tokens, Types::ID> uvar_15;
	std::vector<::ISPA_STD::Node<::Parser::Tokens, Types::ID>> shadow_18;
	success_1 = false;
	if (!(((*pos)).template holds<Types::ID>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar: @  ID");
		return {};
	}
	ID_0 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::ID>>();
	success_1 = true;
	pos++;
	success_6 = false;
	auto begin_22 = pos;
	while (true) {
		auto repeat_ws_23 = begin_22;
		success_3 = false;
		if (((*repeat_ws_23)).template holds<Types::__WS>()) {
			__WS_2 = ((*repeat_ws_23)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
			success_3 = true;
			repeat_ws_23++;
		}
		if (!(((*repeat_ws_23)).template holds<Types::COMMA>())) {
			// speculative match failed (diagnostic suppressed):  COMMA
			break;
		}
		COMMA_8 = ((*repeat_ws_23)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::COMMA>>();
		success_9 = true;
		repeat_ws_23++;
		shadow_10.push_back(COMMA_8);
		uvar_7 = COMMA_8;
		success_13 = false;
		if (((*repeat_ws_23)).template holds<Types::__WS>()) {
			__WS_12 = ((*repeat_ws_23)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
			success_13 = true;
			repeat_ws_23++;
			shadow_14.push_back(__WS_12);
			uvar_11 = __WS_12;
		}
		if (!(((*repeat_ws_23)).template holds<Types::ID>())) {
			// speculative match failed (diagnostic suppressed): @  ID
			break;
		}
		ID_16 = ((*repeat_ws_23)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::ID>>();
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
	::ISPA_STD::MatchResult<Rules, Types::param, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::param<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::param, ::Parser::Lexer::iterator>;
template auto Parser::Parser::param<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::param, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::params(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::params, IT> {
	::ISPA_STD::Node<::Parser::Tokens, Types::LEFT_PARENTHESIS> LEFT_PARENTHESIS_0;
	bool success_1;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::MatchResult<Rules, Types::param, IT> param_4;
	bool success_5;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_6;
	bool success_7;
	::ISPA_STD::Node<::Parser::Tokens, Types::RIGHT_PARENTHESIS> RIGHT_PARENTHESIS_8;
	bool success_9;
	success_1 = false;
	if (!(((*pos)).template holds<Types::LEFT_PARENTHESIS>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  LEFT_PARENTHESIS");
		return {};
	}
	LEFT_PARENTHESIS_0 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::LEFT_PARENTHESIS>>();
	success_1 = true;
	pos++;
	success_3 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_2 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
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
		__WS_6 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_7 = true;
		pos++;
	}
	success_9 = false;
	if (!(((*pos)).template holds<Types::RIGHT_PARENTHESIS>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  RIGHT_PARENTHESIS");
		return {};
	}
	RIGHT_PARENTHESIS_8 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::RIGHT_PARENTHESIS>>();
	success_9 = true;
	pos++;
	Types::params result;
	::ISPA_STD::assign_compatible(result.value, param_4.node);
	::ISPA_STD::MatchResult<Rules, Types::params, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::params<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::params, ::Parser::Lexer::iterator>;
template auto Parser::Parser::params<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::params, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::rule(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::rule, IT> {
	::ISPA_STD::Node<::Parser::Tokens, Types::COLON> COLON_0;
	bool success_1;
	::ISPA_STD::MatchResult<Rules, Types::rule::value, IT> rule_value_5;
	bool success_6;
	::ISPA_STD::Node<::Parser::Rules, Types::rule::value> element_7;
	std::vector<::ISPA_STD::Node<::Parser::Rules, Types::rule::value>> shadow_8;
	std::vector<::ISPA_STD::Node<::Parser::Rules, Types::rule::value>> uvar_4;
	bool success_9;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_11;
	bool success_12;
	::ISPA_STD::MatchResult<Rules, Types::rule::ast, IT> rule_ast_13;
	bool success_14;
	::ISPA_STD::MatchResult<Rules, Types::rule::nested_rule, IT> rule_nested_rule_18;
	bool success_19;
	::ISPA_STD::Node<::Parser::Rules, Types::rule::nested_rule> element_20;
	std::vector<::ISPA_STD::Node<::Parser::Rules, Types::rule::nested_rule>> shadow_21;
	std::vector<::ISPA_STD::Node<::Parser::Rules, Types::rule::nested_rule>> uvar_17;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_15;
	bool success_16;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_23;
	bool success_24;
	::ISPA_STD::Node<::Parser::Tokens, Types::SEMICOLON> SEMICOLON_25;
	bool success_26;
	success_1 = false;
	if (!(((*pos)).template holds<Types::COLON>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  COLON");
		return {};
	}
	COLON_0 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::COLON>>();
	success_1 = true;
	pos++;
	success_6 = false;
	// grammar `@  rule::value+;`: repeat named rule; collect every matched value
	success_9 = false;
	while (true) {
		auto repeat_ws_10 = pos;
		success_3 = false;
		if (((*repeat_ws_10)).template holds<Types::__WS>()) {
			__WS_2 = ((*repeat_ws_10)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
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
		__WS_11 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_12 = true;
		pos++;
	}
	success_14 = false;
	rule_ast_13 = rule_ast(pos);
	if (rule_ast_13.status) {
		success_14 = true;
		pos = rule_ast_13.it;
	}
	success_19 = false;
	// grammar `@  rule::nested_rule*;`: repeat named rule; collect every matched value
	while (true) {
		auto repeat_ws_22 = pos;
		success_16 = false;
		if (((*repeat_ws_22)).template holds<Types::__WS>()) {
			__WS_15 = ((*repeat_ws_22)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
			success_16 = true;
			repeat_ws_22++;
		}
		rule_nested_rule_18 = rule_nested_rule(repeat_ws_22);
		if (!(rule_nested_rule_18.status)) {
			break;
		}
		success_19 = true;
		repeat_ws_22 = rule_nested_rule_18.it;
		element_20 = rule_nested_rule_18.node;
		shadow_21.push_back(element_20);
		pos = repeat_ws_22;
	}
	::ISPA_STD::assign_compatible(uvar_17, shadow_21);
	success_24 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_23 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_24 = true;
		pos++;
	}
	success_26 = false;
	if (!(((*pos)).template holds<Types::SEMICOLON>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  SEMICOLON");
		return {};
	}
	SEMICOLON_25 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::SEMICOLON>>();
	success_26 = true;
	pos++;
	Types::rule result;
	::ISPA_STD::assign_compatible(result.v, uvar_4);
	::ISPA_STD::assign_compatible(result.data, rule_ast_13);
	::ISPA_STD::assign_compatible(result.nested, uvar_17);
	::ISPA_STD::MatchResult<Rules, Types::rule, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::rule<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::rule, ::Parser::Lexer::iterator>;
template auto Parser::Parser::rule<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::rule, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::rule_ast(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::rule::ast, IT> {
	std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Rules, Types::rule::ast::single_value>, ::ISPA_STD::Node<::Parser::Rules, Types::rule::ast::full>, ::ISPA_STD::Node<::Parser::Rules, Types::rule::ast::abbr>> _0;
	bool success_1;
	::ISPA_STD::MatchResult<Rules, Types::rule::ast::full, IT> rule_ast_full_2;
	bool success_3;
	::ISPA_STD::MatchResult<Rules, Types::rule::ast::abbr, IT> rule_ast_abbr_4;
	bool success_5;
	::ISPA_STD::MatchResult<Rules, Types::rule::ast::single_value, IT> rule_ast_single_value_6;
	bool success_7;
	success_1 = false;
	// grammar `@  ( rule::ast::abbr |  rule::ast::full |  rule::ast::single_value)`: choice; reset match status before selecting an alternative
	success_1 = false;
	auto lookahead_pos_1 = pos;
	switch (static_cast<Tokens>((*lookahead_pos_1).kind())) {
		case Tokens::AMPERSAND: {
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
		case Tokens::COMMERCIAL_AT: {
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
		case Tokens::LEFT_CURLY_BRACKET: {
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
	::ISPA_STD::MatchResult<Rules, Types::rule::ast, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::rule_ast<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::rule::ast, ::Parser::Lexer::iterator>;
template auto Parser::Parser::rule_ast<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::rule::ast, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::rule_ast_abbr(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::rule::ast::abbr, IT> {
	::ISPA_STD::Node<::Parser::Tokens, Types::COMMERCIAL_AT> COMMERCIAL_AT_0;
	bool success_1;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::Node<::Parser::Tokens, Types::LEFT_CURLY_BRACKET> LEFT_CURLY_BRACKET_4;
	bool success_5;
	bool success_13;
	std::vector<::ISPA_STD::Node<::Parser::Tokens, Types::ID>> shadow_23;
	std::vector<::ISPA_STD::Node<::Parser::Tokens, Types::COMMA>> shadow_24;
	std::tuple<::ISPA_STD::Node<::Parser::Tokens, Types::ID>, ::ISPA_STD::Node<::Parser::Tokens, Types::__WS>, ::ISPA_STD::Node<::Parser::Tokens, Types::COMMA>> group_8;
	bool success_10;
	std::vector<std::tuple<::ISPA_STD::Node<::Parser::Tokens, Types::ID>, ::ISPA_STD::Node<::Parser::Tokens, Types::__WS>, ::ISPA_STD::Node<::Parser::Tokens, Types::COMMA>>> shadow_25;
	std::vector<std::tuple<::ISPA_STD::Node<::Parser::Tokens, Types::ID>, ::ISPA_STD::Node<::Parser::Tokens, Types::__WS>, ::ISPA_STD::Node<::Parser::Tokens, Types::COMMA>>> uvar_9;
	bool success_27;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_6;
	bool success_7;
	::ISPA_STD::Node<::Parser::Tokens, Types::ID> ID_12;
	::ISPA_STD::Node<::Parser::Tokens, Types::ID> uvar_11;
	std::vector<::ISPA_STD::Node<::Parser::Tokens, Types::ID>> shadow_14;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_16;
	bool success_17;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> uvar_15;
	std::vector<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>> shadow_18;
	::ISPA_STD::Node<::Parser::Tokens, Types::COMMA> COMMA_20;
	bool success_21;
	::ISPA_STD::Node<::Parser::Tokens, Types::COMMA> uvar_19;
	std::vector<::ISPA_STD::Node<::Parser::Tokens, Types::COMMA>> shadow_22;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_29;
	bool success_30;
	::ISPA_STD::Node<::Parser::Tokens, Types::RIGHT_CURLY_BRACKET> RIGHT_CURLY_BRACKET_31;
	bool success_32;
	success_1 = false;
	if (!(((*pos)).template holds<Types::COMMERCIAL_AT>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  COMMERCIAL_AT");
		return {};
	}
	COMMERCIAL_AT_0 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::COMMERCIAL_AT>>();
	success_1 = true;
	pos++;
	success_3 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_2 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_3 = true;
		pos++;
	}
	success_5 = false;
	if (!(((*pos)).template holds<Types::LEFT_CURLY_BRACKET>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  LEFT_CURLY_BRACKET");
		return {};
	}
	LEFT_CURLY_BRACKET_4 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::LEFT_CURLY_BRACKET>>();
	success_5 = true;
	pos++;
	success_10 = false;
	auto begin_26 = pos;
	success_27 = false;
	while (true) {
		auto repeat_ws_28 = begin_26;
		success_7 = false;
		if (((*repeat_ws_28)).template holds<Types::__WS>()) {
			__WS_6 = ((*repeat_ws_28)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
			success_7 = true;
			repeat_ws_28++;
		}
		if (!(((*repeat_ws_28)).template holds<Types::ID>())) {
			// speculative match failed (diagnostic suppressed): @  ID
			break;
		}
		ID_12 = ((*repeat_ws_28)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::ID>>();
		success_13 = true;
		repeat_ws_28++;
		shadow_14.push_back(ID_12);
		uvar_11 = ID_12;
		success_17 = false;
		if (((*repeat_ws_28)).template holds<Types::__WS>()) {
			__WS_16 = ((*repeat_ws_28)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
			success_17 = true;
			repeat_ws_28++;
			shadow_18.push_back(__WS_16);
			uvar_15 = __WS_16;
		}
		success_21 = false;
		if (((*repeat_ws_28)).template holds<Types::COMMA>()) {
			COMMA_20 = ((*repeat_ws_28)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::COMMA>>();
			success_21 = true;
			repeat_ws_28++;
			shadow_22.push_back(COMMA_20);
			uvar_19 = COMMA_20;
		}
		if (success_13) {
			group_8 = std::make_tuple(ID_12, __WS_16, COMMA_20);
			shadow_25.push_back(group_8);
			shadow_23.push_back(ID_12);
			shadow_24.push_back(COMMA_20);
		}
		success_27 = true;
		begin_26 = repeat_ws_28;
	}
	if (!success_27) {
		return {};
	}
	success_10 = true;
	::ISPA_STD::assign_compatible(uvar_9, shadow_25);
	pos = begin_26;
	success_30 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_29 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_30 = true;
		pos++;
	}
	success_32 = false;
	if (!(((*pos)).template holds<Types::RIGHT_CURLY_BRACKET>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  RIGHT_CURLY_BRACKET");
		return {};
	}
	RIGHT_CURLY_BRACKET_31 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::RIGHT_CURLY_BRACKET>>();
	success_32 = true;
	pos++;
	Types::rule::ast::abbr result;
	::ISPA_STD::assign_compatible(result.value, shadow_23);
	::ISPA_STD::MatchResult<Rules, Types::rule::ast::abbr, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::rule_ast_abbr<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::rule::ast::abbr, ::Parser::Lexer::iterator>;
template auto Parser::Parser::rule_ast_abbr<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::rule::ast::abbr, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::rule_ast_full(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::rule::ast::full, IT> {
	::ISPA_STD::Node<::Parser::Tokens, Types::AMPERSAND> AMPERSAND_0;
	bool success_1;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::Node<::Parser::Tokens, Types::LEFT_CURLY_BRACKET> LEFT_CURLY_BRACKET_4;
	bool success_5;
	::ISPA_STD::MatchResult<Rules, Types::rule::ast::full::part, IT> rule_ast_full_part_9;
	bool success_10;
	::ISPA_STD::Node<::Parser::Rules, Types::rule::ast::full::part> element_11;
	std::vector<::ISPA_STD::Node<::Parser::Rules, Types::rule::ast::full::part>> shadow_12;
	std::vector<::ISPA_STD::Node<::Parser::Rules, Types::rule::ast::full::part>> uvar_8;
	bool success_13;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_6;
	bool success_7;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_15;
	bool success_16;
	::ISPA_STD::Node<::Parser::Tokens, Types::RIGHT_CURLY_BRACKET> RIGHT_CURLY_BRACKET_17;
	bool success_18;
	success_1 = false;
	if (!(((*pos)).template holds<Types::AMPERSAND>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  AMPERSAND");
		return {};
	}
	AMPERSAND_0 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::AMPERSAND>>();
	success_1 = true;
	pos++;
	success_3 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_2 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_3 = true;
		pos++;
	}
	success_5 = false;
	if (!(((*pos)).template holds<Types::LEFT_CURLY_BRACKET>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  LEFT_CURLY_BRACKET");
		return {};
	}
	LEFT_CURLY_BRACKET_4 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::LEFT_CURLY_BRACKET>>();
	success_5 = true;
	pos++;
	success_10 = false;
	// grammar `@  rule::ast::full::part+;`: repeat named rule; collect every matched value
	success_13 = false;
	while (true) {
		auto repeat_ws_14 = pos;
		success_7 = false;
		if (((*repeat_ws_14)).template holds<Types::__WS>()) {
			__WS_6 = ((*repeat_ws_14)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
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
		__WS_15 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_16 = true;
		pos++;
	}
	success_18 = false;
	if (!(((*pos)).template holds<Types::RIGHT_CURLY_BRACKET>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  RIGHT_CURLY_BRACKET");
		return {};
	}
	RIGHT_CURLY_BRACKET_17 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::RIGHT_CURLY_BRACKET>>();
	success_18 = true;
	pos++;
	Types::rule::ast::full result;
	::ISPA_STD::assign_compatible(result.value, uvar_8);
	::ISPA_STD::MatchResult<Rules, Types::rule::ast::full, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::rule_ast_full<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::rule::ast::full, ::Parser::Lexer::iterator>;
template auto Parser::Parser::rule_ast_full<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::rule::ast::full, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::rule_ast_full_part(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::rule::ast::full::part, IT> {
	::ISPA_STD::Node<::Parser::Tokens, Types::ID> ID_0;
	bool success_1;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::Node<::Parser::Tokens, Types::COLON> COLON_4;
	bool success_5;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_6;
	bool success_7;
	::ISPA_STD::MatchResult<Rules, Types::expr, IT> expr_8;
	bool success_9;
	success_1 = false;
	if (!(((*pos)).template holds<Types::ID>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar: @  ID");
		return {};
	}
	ID_0 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::ID>>();
	success_1 = true;
	pos++;
	success_3 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_2 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_3 = true;
		pos++;
	}
	success_5 = false;
	if (!(((*pos)).template holds<Types::COLON>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  COLON");
		return {};
	}
	COLON_4 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::COLON>>();
	success_5 = true;
	pos++;
	success_7 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_6 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
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
	::ISPA_STD::MatchResult<Rules, Types::rule::ast::full::part, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::rule_ast_full_part<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::rule::ast::full::part, ::Parser::Lexer::iterator>;
template auto Parser::Parser::rule_ast_full_part<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::rule::ast::full::part, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::rule_ast_single_value(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::rule::ast::single_value, IT> {
	::ISPA_STD::Node<::Parser::Tokens, Types::LEFT_CURLY_BRACKET> LEFT_CURLY_BRACKET_0;
	bool success_1;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Tokens, Types::COMMERCIAL_AT>, ::ISPA_STD::Node<::Parser::Rules, Types::expr>> _4;
	bool success_5;
	::ISPA_STD::Node<::Parser::Tokens, Types::COMMERCIAL_AT> COMMERCIAL_AT_6;
	bool success_7;
	::ISPA_STD::MatchResult<Rules, Types::expr, IT> expr_8;
	bool success_9;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_10;
	bool success_11;
	::ISPA_STD::Node<::Parser::Tokens, Types::RIGHT_CURLY_BRACKET> RIGHT_CURLY_BRACKET_12;
	bool success_13;
	success_1 = false;
	if (!(((*pos)).template holds<Types::LEFT_CURLY_BRACKET>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  LEFT_CURLY_BRACKET");
		return {};
	}
	LEFT_CURLY_BRACKET_0 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::LEFT_CURLY_BRACKET>>();
	success_1 = true;
	pos++;
	success_3 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_2 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_3 = true;
		pos++;
	}
	success_5 = false;
	// grammar `@  ( expr |  COMMERCIAL_AT)`: choice; reset match status before selecting an alternative
	success_5 = false;
	auto lookahead_pos_1 = pos;
	switch (static_cast<Tokens>((*lookahead_pos_1).kind())) {
		case Tokens::COMMERCIAL_AT: {
			lookahead_pos_1 = lookahead_pos_1;
			success_7 = false;
			if (!(((*lookahead_pos_1)).template holds<Types::COMMERCIAL_AT>())) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  COMMERCIAL_AT");
				return {};
			}
			COMMERCIAL_AT_6 = ((*lookahead_pos_1)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::COMMERCIAL_AT>>();
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
		case Tokens::PY_RAW: {
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
		__WS_10 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_11 = true;
		pos++;
	}
	success_13 = false;
	if (!(((*pos)).template holds<Types::RIGHT_CURLY_BRACKET>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  RIGHT_CURLY_BRACKET");
		return {};
	}
	RIGHT_CURLY_BRACKET_12 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::RIGHT_CURLY_BRACKET>>();
	success_13 = true;
	pos++;
	Types::rule::ast::single_value result;
	::ISPA_STD::assign_compatible(result.value, _4);
	::ISPA_STD::MatchResult<Rules, Types::rule::ast::single_value, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::rule_ast_single_value<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::rule::ast::single_value, ::Parser::Lexer::iterator>;
template auto Parser::Parser::rule_ast_single_value<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::rule::ast::single_value, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::rule_nested_rule(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::rule::nested_rule, IT> {
	::ISPA_STD::Node<::Parser::Tokens, Types::rule::nested_rule::NUMBER_SIGN> rule_nested_rule_NUMBER_SIGN_0;
	bool success_1;
	::ISPA_STD::MatchResult<Rules, Types::grammar, IT> grammar_2;
	bool success_3;
	success_1 = false;
	if (!(((*pos)).template holds<Types::rule::nested_rule::NUMBER_SIGN>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  rule::nested_rule::NUMBER_SIGN");
		return {};
	}
	rule_nested_rule_NUMBER_SIGN_0 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::rule::nested_rule::NUMBER_SIGN>>();
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
	::ISPA_STD::MatchResult<Rules, Types::rule::nested_rule, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::rule_nested_rule<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::rule::nested_rule, ::Parser::Lexer::iterator>;
template auto Parser::Parser::rule_nested_rule<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::rule::nested_rule, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::rule_value(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::rule::value, IT> {
	::ISPA_STD::MatchResult<Rules, Types::rule::value::var_capture, IT> rule_value_var_capture_0;
	bool success_1;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::MatchResult<Rules, Types::rule::value::ast_capture, IT> rule_value_ast_capture_4;
	bool success_5;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_6;
	bool success_7;
	::ISPA_STD::MatchResult<Rules, Types::rule::value::pattern, IT> rule_value_pattern_8;
	bool success_9;
	::ISPA_STD::MatchResult<Rules, Types::rule::value::alternative, IT> rule_value_alternative_13;
	bool success_14;
	::ISPA_STD::Node<::Parser::Rules, Types::rule::value::alternative> element_15;
	std::vector<::ISPA_STD::Node<::Parser::Rules, Types::rule::value::alternative>> shadow_16;
	std::vector<::ISPA_STD::Node<::Parser::Rules, Types::rule::value::alternative>> uvar_12;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_10;
	bool success_11;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_18;
	bool success_19;
	::ISPA_STD::MatchResult<Rules, Types::rule::value::counter, IT> rule_value_counter_20;
	bool success_21;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_22;
	bool success_23;
	::ISPA_STD::MatchResult<Rules, Types::rule::value::shared_counter_registration, IT> rule_value_shared_counter_registration_24;
	bool success_25;
	success_1 = false;
	rule_value_var_capture_0 = rule_value_var_capture(pos);
	if (rule_value_var_capture_0.status) {
		success_1 = true;
		pos = rule_value_var_capture_0.it;
	}
	success_3 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_2 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
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
		__WS_6 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_7 = true;
		pos++;
	}
	success_9 = false;
	rule_value_pattern_8 = rule_value_pattern(pos);
	if (!(rule_value_pattern_8.status)) {
		raise_error(*pos, "ISPA match failure: required named rule did not match | grammar: @  rule::value::pattern");
		return {};
	}
	success_9 = true;
	pos = rule_value_pattern_8.it;
	success_14 = false;
	// grammar `@  rule::value::alternative*;`: repeat named rule; collect every matched value
	while (true) {
		auto repeat_ws_17 = pos;
		success_11 = false;
		if (((*repeat_ws_17)).template holds<Types::__WS>()) {
			__WS_10 = ((*repeat_ws_17)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
			success_11 = true;
			repeat_ws_17++;
		}
		rule_value_alternative_13 = rule_value_alternative(repeat_ws_17);
		if (!(rule_value_alternative_13.status)) {
			break;
		}
		success_14 = true;
		repeat_ws_17 = rule_value_alternative_13.it;
		element_15 = rule_value_alternative_13.node;
		shadow_16.push_back(element_15);
		pos = repeat_ws_17;
	}
	::ISPA_STD::assign_compatible(uvar_12, shadow_16);
	success_19 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_18 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_19 = true;
		pos++;
	}
	success_21 = false;
	rule_value_counter_20 = rule_value_counter(pos);
	if (rule_value_counter_20.status) {
		success_21 = true;
		pos = rule_value_counter_20.it;
	}
	success_23 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_22 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_23 = true;
		pos++;
	}
	success_25 = false;
	rule_value_shared_counter_registration_24 = rule_value_shared_counter_registration(pos);
	if (rule_value_shared_counter_registration_24.status) {
		success_25 = true;
		pos = rule_value_shared_counter_registration_24.it;
	}
	Types::rule::value result;
	::ISPA_STD::assign_compatible(result.v_cap, rule_value_var_capture_0);
	::ISPA_STD::assign_compatible(result.ast_cap, rule_value_ast_capture_4);
	::ISPA_STD::assign_compatible(result.val, rule_value_pattern_8);
	::ISPA_STD::assign_compatible(result.alts, uvar_12);
	::ISPA_STD::assign_compatible(result.quantifier, rule_value_counter_20);
	::ISPA_STD::assign_compatible(result.registration, rule_value_shared_counter_registration_24);
	::ISPA_STD::MatchResult<Rules, Types::rule::value, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::rule_value<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::rule::value, ::Parser::Lexer::iterator>;
template auto Parser::Parser::rule_value<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::rule::value, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::rule_value_alternative(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::rule::value::alternative, IT> {
	::ISPA_STD::Node<::Parser::Tokens, Types::rule::value::alternative::VERTICAL_LINE> rule_value_alternative_VERTICAL_LINE_0;
	bool success_1;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::MatchResult<Rules, Types::rule::value::pattern, IT> rule_value_pattern_4;
	bool success_5;
	success_1 = false;
	if (!(((*pos)).template holds<Types::rule::value::alternative::VERTICAL_LINE>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  rule::value::alternative::VERTICAL_LINE");
		return {};
	}
	rule_value_alternative_VERTICAL_LINE_0 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::rule::value::alternative::VERTICAL_LINE>>();
	success_1 = true;
	pos++;
	success_3 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_2 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
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
	::ISPA_STD::MatchResult<Rules, Types::rule::value::alternative, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::rule_value_alternative<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::rule::value::alternative, ::Parser::Lexer::iterator>;
template auto Parser::Parser::rule_value_alternative<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::rule::value::alternative, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::rule_value_ast_capture(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::rule::value::ast_capture, IT> {
	::ISPA_STD::Node<::Parser::Tokens, Types::COMMERCIAL_AT> COMMERCIAL_AT_0;
	bool success_1;
	::ISPA_STD::Node<::Parser::Tokens, Types::ID> ID_2;
	bool success_3;
	success_1 = false;
	if (!(((*pos)).template holds<Types::COMMERCIAL_AT>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  COMMERCIAL_AT");
		return {};
	}
	COMMERCIAL_AT_0 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::COMMERCIAL_AT>>();
	success_1 = true;
	pos++;
	success_3 = false;
	if (((*pos)).template holds<Types::ID>()) {
		ID_2 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::ID>>();
		success_3 = true;
		pos++;
	}
	Types::rule::value::ast_capture result;
	::ISPA_STD::assign_compatible(result.value, ID_2);
	::ISPA_STD::MatchResult<Rules, Types::rule::value::ast_capture, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::rule_value_ast_capture<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::rule::value::ast_capture, ::Parser::Lexer::iterator>;
template auto Parser::Parser::rule_value_ast_capture<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::rule::value::ast_capture, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::rule_value_counter(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::rule::value::counter, IT> {
	::ISPA_STD::Node<::Parser::Tokens, Types::rule::value::QUANTIFIER> rule_value_QUANTIFIER_0;
	bool success_1;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::MatchResult<Rules, Types::rule::value::counter::bounded, IT> rule_value_counter_bounded_4;
	bool success_5;
	success_1 = false;
	if (!(((*pos)).template holds<Types::rule::value::QUANTIFIER>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar: @  rule::value::QUANTIFIER");
		return {};
	}
	rule_value_QUANTIFIER_0 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::rule::value::QUANTIFIER>>();
	success_1 = true;
	pos++;
	success_3 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_2 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
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
	::ISPA_STD::MatchResult<Rules, Types::rule::value::counter, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::rule_value_counter<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::rule::value::counter, ::Parser::Lexer::iterator>;
template auto Parser::Parser::rule_value_counter<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::rule::value::counter, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::rule_value_counter_bounded(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::rule::value::counter::bounded, IT> {
	::ISPA_STD::Node<::Parser::Tokens, Types::rule::value::counter::bounded::EQUALS_SIGN> rule_value_counter_bounded_EQUALS_SIGN_0;
	bool success_1;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Rules, Types::expr>, ::ISPA_STD::Node<::Parser::Tokens, Types::ID>, ::ISPA_STD::Node<::Parser::Tokens, Types::NUMBER>> _4;
	bool success_5;
	::ISPA_STD::Node<::Parser::Tokens, Types::ID> ID_6;
	bool success_7;
	::ISPA_STD::Node<::Parser::Tokens, Types::NUMBER> NUMBER_8;
	bool success_9;
	::ISPA_STD::MatchResult<Rules, Types::expr, IT> expr_10;
	bool success_11;
	success_1 = false;
	if (!(((*pos)).template holds<Types::rule::value::counter::bounded::EQUALS_SIGN>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  rule::value::counter::bounded::EQUALS_SIGN");
		return {};
	}
	rule_value_counter_bounded_EQUALS_SIGN_0 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::rule::value::counter::bounded::EQUALS_SIGN>>();
	success_1 = true;
	pos++;
	success_3 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_2 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_3 = true;
		pos++;
	}
	success_5 = false;
	// grammar `@  ( NUMBER |  ID |  expr)`: choice; reset match status before selecting an alternative
	success_5 = false;
	auto lookahead_pos_1 = pos;
	switch (static_cast<Tokens>((*lookahead_pos_1).kind())) {
		case Tokens::ID: {
			lookahead_pos_1 = lookahead_pos_1;
			success_7 = false;
			if (!(((*lookahead_pos_1)).template holds<Types::ID>())) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  ID");
				return {};
			}
			ID_6 = ((*lookahead_pos_1)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::ID>>();
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
		case Tokens::NUMBER: {
			lookahead_pos_1 = lookahead_pos_1;
			success_9 = false;
			if (!(((*lookahead_pos_1)).template holds<Types::NUMBER>())) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  NUMBER");
				return {};
			}
			NUMBER_8 = ((*lookahead_pos_1)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::NUMBER>>();
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
		case Tokens::PY_RAW: {
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
	::ISPA_STD::MatchResult<Rules, Types::rule::value::counter::bounded, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::rule_value_counter_bounded<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::rule::value::counter::bounded, ::Parser::Lexer::iterator>;
template auto Parser::Parser::rule_value_counter_bounded<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::rule::value::counter::bounded, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::rule_value_dyn(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::rule::value::dyn, IT> {
	::ISPA_STD::Node<::Parser::Tokens, Types::rule::value::dyn::DOLLAR_SIGN> rule_value_dyn_DOLLAR_SIGN_0;
	bool success_1;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Tokens, Types::ID>, ::ISPA_STD::Node<::Parser::Rules, Types::rule::value::dyn::dyn_expr>> _4;
	bool success_5;
	::ISPA_STD::Node<::Parser::Tokens, Types::ID> ID_6;
	bool success_7;
	::ISPA_STD::MatchResult<Rules, Types::rule::value::dyn::dyn_expr, IT> rule_value_dyn_dyn_expr_8;
	bool success_9;
	success_1 = false;
	if (!(((*pos)).template holds<Types::rule::value::dyn::DOLLAR_SIGN>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  rule::value::dyn::DOLLAR_SIGN");
		return {};
	}
	rule_value_dyn_DOLLAR_SIGN_0 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::rule::value::dyn::DOLLAR_SIGN>>();
	success_1 = true;
	pos++;
	success_3 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_2 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_3 = true;
		pos++;
	}
	success_5 = false;
	// grammar `@  ( rule::value::dyn::dyn_expr |  ID)`: choice; reset match status before selecting an alternative
	success_5 = false;
	auto lookahead_pos_1 = pos;
	switch (static_cast<Tokens>((*lookahead_pos_1).kind())) {
		case Tokens::ID: {
			lookahead_pos_1 = lookahead_pos_1;
			success_7 = false;
			if (!(((*lookahead_pos_1)).template holds<Types::ID>())) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  ID");
				return {};
			}
			ID_6 = ((*lookahead_pos_1)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::ID>>();
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
		case Tokens::LEFT_CURLY_BRACKET: {
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
	::ISPA_STD::MatchResult<Rules, Types::rule::value::dyn, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::rule_value_dyn<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::rule::value::dyn, ::Parser::Lexer::iterator>;
template auto Parser::Parser::rule_value_dyn<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::rule::value::dyn, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::rule_value_dyn_dyn_expr(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::rule::value::dyn::dyn_expr, IT> {
	::ISPA_STD::Node<::Parser::Tokens, Types::LEFT_CURLY_BRACKET> LEFT_CURLY_BRACKET_0;
	bool success_1;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::MatchResult<Rules, Types::expr, IT> expr_4;
	bool success_5;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_6;
	bool success_7;
	::ISPA_STD::Node<::Parser::Tokens, Types::RIGHT_CURLY_BRACKET> RIGHT_CURLY_BRACKET_8;
	bool success_9;
	success_1 = false;
	if (!(((*pos)).template holds<Types::LEFT_CURLY_BRACKET>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  LEFT_CURLY_BRACKET");
		return {};
	}
	LEFT_CURLY_BRACKET_0 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::LEFT_CURLY_BRACKET>>();
	success_1 = true;
	pos++;
	success_3 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_2 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
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
		__WS_6 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_7 = true;
		pos++;
	}
	success_9 = false;
	if (!(((*pos)).template holds<Types::RIGHT_CURLY_BRACKET>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  RIGHT_CURLY_BRACKET");
		return {};
	}
	RIGHT_CURLY_BRACKET_8 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::RIGHT_CURLY_BRACKET>>();
	success_9 = true;
	pos++;
	Types::rule::value::dyn::dyn_expr result;
	::ISPA_STD::assign_compatible(result.value, expr_4.node);
	::ISPA_STD::MatchResult<Rules, Types::rule::value::dyn::dyn_expr, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::rule_value_dyn_dyn_expr<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::rule::value::dyn::dyn_expr, ::Parser::Lexer::iterator>;
template auto Parser::Parser::rule_value_dyn_dyn_expr<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::rule::value::dyn::dyn_expr, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::rule_value_group(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::rule::value::group, IT> {
	::ISPA_STD::Node<::Parser::Tokens, Types::LEFT_PARENTHESIS> LEFT_PARENTHESIS_0;
	bool success_1;
	::ISPA_STD::MatchResult<Rules, Types::rule::value, IT> rule_value_5;
	bool success_6;
	::ISPA_STD::Node<::Parser::Rules, Types::rule::value> element_7;
	std::vector<::ISPA_STD::Node<::Parser::Rules, Types::rule::value>> shadow_8;
	std::vector<::ISPA_STD::Node<::Parser::Rules, Types::rule::value>> uvar_4;
	bool success_9;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_11;
	bool success_12;
	::ISPA_STD::Node<::Parser::Tokens, Types::RIGHT_PARENTHESIS> RIGHT_PARENTHESIS_13;
	bool success_14;
	success_1 = false;
	if (!(((*pos)).template holds<Types::LEFT_PARENTHESIS>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  LEFT_PARENTHESIS");
		return {};
	}
	LEFT_PARENTHESIS_0 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::LEFT_PARENTHESIS>>();
	success_1 = true;
	pos++;
	success_6 = false;
	// grammar `@  rule::value+;`: repeat named rule; collect every matched value
	success_9 = false;
	while (true) {
		auto repeat_ws_10 = pos;
		success_3 = false;
		if (((*repeat_ws_10)).template holds<Types::__WS>()) {
			__WS_2 = ((*repeat_ws_10)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
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
		__WS_11 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_12 = true;
		pos++;
	}
	success_14 = false;
	if (!(((*pos)).template holds<Types::RIGHT_PARENTHESIS>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  RIGHT_PARENTHESIS");
		return {};
	}
	RIGHT_PARENTHESIS_13 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::RIGHT_PARENTHESIS>>();
	success_14 = true;
	pos++;
	Types::rule::value::group result;
	::ISPA_STD::assign_compatible(result.value, uvar_4);
	::ISPA_STD::MatchResult<Rules, Types::rule::value::group, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::rule_value_group<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::rule::value::group, ::Parser::Lexer::iterator>;
template auto Parser::Parser::rule_value_group<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::rule::value::group, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::rule_value_pattern(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::rule::value::pattern, IT> {
	std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Tokens, Types::rule::value::SPACE>, ::ISPA_STD::Node<::Parser::Tokens, Types::rule::value::CGROUP>, ::ISPA_STD::Node<::Parser::Tokens, Types::rule::value::STRING>, ::ISPA_STD::Node<::Parser::Rules, Types::rule::value::dyn>, ::ISPA_STD::Node<::Parser::Tokens, Types::rule::value::NOSPACE>, ::ISPA_STD::Node<::Parser::Rules, Types::rule::value::group>, ::ISPA_STD::Node<::Parser::Tokens, Types::rule::value::ANY>, ::ISPA_STD::Node<::Parser::Rules, Types::name>> _0;
	bool success_1;
	::ISPA_STD::MatchResult<Rules, Types::name, IT> name_2;
	bool success_3;
	::ISPA_STD::MatchResult<Rules, Types::rule::value::group, IT> rule_value_group_4;
	bool success_5;
	::ISPA_STD::Node<::Parser::Tokens, Types::rule::value::ANY> rule_value_ANY_6;
	bool success_7;
	::ISPA_STD::Node<::Parser::Tokens, Types::rule::value::CGROUP> rule_value_CGROUP_8;
	bool success_9;
	::ISPA_STD::Node<::Parser::Tokens, Types::rule::value::NOSPACE> rule_value_NOSPACE_10;
	bool success_11;
	::ISPA_STD::Node<::Parser::Tokens, Types::rule::value::SPACE> rule_value_SPACE_12;
	bool success_13;
	::ISPA_STD::Node<::Parser::Tokens, Types::rule::value::STRING> rule_value_STRING_14;
	bool success_15;
	::ISPA_STD::MatchResult<Rules, Types::rule::value::dyn, IT> rule_value_dyn_16;
	bool success_17;
	success_1 = false;
	// grammar `@  ( name |  rule::value::group |  rule::value::dyn |  rule::value::STRING |  rule::value::CGROUP |  rule::value::ANY |  rule::value::SPACE |  rule::value::NOSPACE)`: choice; reset match status before selecting an alternative
	success_1 = false;
	auto lookahead_pos_1 = pos;
	switch (static_cast<Tokens>((*lookahead_pos_1).kind())) {
		case Tokens::ID: {
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
		case Tokens::LEFT_PARENTHESIS: {
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
		case Tokens::rule_value_ANY: {
			lookahead_pos_1 = lookahead_pos_1;
			success_7 = false;
			if (!(((*lookahead_pos_1)).template holds<Types::rule::value::ANY>())) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  rule::value::ANY");
				return {};
			}
			rule_value_ANY_6 = ((*lookahead_pos_1)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::rule::value::ANY>>();
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
		case Tokens::rule_value_CGROUP: {
			lookahead_pos_1 = lookahead_pos_1;
			success_9 = false;
			if (!(((*lookahead_pos_1)).template holds<Types::rule::value::CGROUP>())) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  rule::value::CGROUP");
				return {};
			}
			rule_value_CGROUP_8 = ((*lookahead_pos_1)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::rule::value::CGROUP>>();
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
		case Tokens::rule_value_NOSPACE: {
			lookahead_pos_1 = lookahead_pos_1;
			success_11 = false;
			if (!(((*lookahead_pos_1)).template holds<Types::rule::value::NOSPACE>())) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  rule::value::NOSPACE");
				return {};
			}
			rule_value_NOSPACE_10 = ((*lookahead_pos_1)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::rule::value::NOSPACE>>();
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
		case Tokens::rule_value_SPACE: {
			lookahead_pos_1 = lookahead_pos_1;
			success_13 = false;
			if (!(((*lookahead_pos_1)).template holds<Types::rule::value::SPACE>())) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  rule::value::SPACE");
				return {};
			}
			rule_value_SPACE_12 = ((*lookahead_pos_1)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::rule::value::SPACE>>();
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
		case Tokens::rule_value_STRING: {
			lookahead_pos_1 = lookahead_pos_1;
			success_15 = false;
			if (!(((*lookahead_pos_1)).template holds<Types::rule::value::STRING>())) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  rule::value::STRING");
				return {};
			}
			rule_value_STRING_14 = ((*lookahead_pos_1)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::rule::value::STRING>>();
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
		case Tokens::rule_value_dyn_DOLLAR_SIGN: {
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
	::ISPA_STD::MatchResult<Rules, Types::rule::value::pattern, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::rule_value_pattern<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::rule::value::pattern, ::Parser::Lexer::iterator>;
template auto Parser::Parser::rule_value_pattern<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::rule::value::pattern, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::rule_value_shared_counter_registration(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::rule::value::shared_counter_registration, IT> {
	::ISPA_STD::Node<::Parser::Tokens, Types::rule::value::shared_counter_registration::AUTO> rule_value_shared_counter_registration_AUTO_0;
	bool success_1;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::Node<::Parser::Tokens, Types::ID> ID_4;
	bool success_5;
	success_1 = false;
	if (!(((*pos)).template holds<Types::rule::value::shared_counter_registration::AUTO>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  rule::value::shared_counter_registration::AUTO");
		return {};
	}
	rule_value_shared_counter_registration_AUTO_0 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::rule::value::shared_counter_registration::AUTO>>();
	success_1 = true;
	pos++;
	success_3 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_2 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_3 = true;
		pos++;
	}
	success_5 = false;
	if (!(((*pos)).template holds<Types::ID>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar: @  ID");
		return {};
	}
	ID_4 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::ID>>();
	success_5 = true;
	pos++;
	Types::rule::value::shared_counter_registration result;
	::ISPA_STD::assign_compatible(result.value, ID_4);
	::ISPA_STD::MatchResult<Rules, Types::rule::value::shared_counter_registration, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::rule_value_shared_counter_registration<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::rule::value::shared_counter_registration, ::Parser::Lexer::iterator>;
template auto Parser::Parser::rule_value_shared_counter_registration<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::rule::value::shared_counter_registration, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::rule_value_var_capture(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::rule::value::var_capture, IT> {
	::ISPA_STD::Node<::Parser::Tokens, Types::AMPERSAND> AMPERSAND_0;
	bool success_1;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::Node<::Parser::Tokens, Types::ID> ID_4;
	bool success_5;
	success_1 = false;
	if (!(((*pos)).template holds<Types::AMPERSAND>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  AMPERSAND");
		return {};
	}
	AMPERSAND_0 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::AMPERSAND>>();
	success_1 = true;
	pos++;
	success_3 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_2 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_3 = true;
		pos++;
	}
	success_5 = false;
	if (!(((*pos)).template holds<Types::ID>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar: @  ID");
		return {};
	}
	ID_4 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::ID>>();
	success_5 = true;
	pos++;
	Types::rule::value::var_capture result;
	::ISPA_STD::assign_compatible(result.value, ID_4);
	::ISPA_STD::MatchResult<Rules, Types::rule::value::var_capture, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::rule_value_var_capture<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::rule::value::var_capture, ::Parser::Lexer::iterator>;
template auto Parser::Parser::rule_value_var_capture<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::rule::value::var_capture, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::stmt(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::stmt, IT> {
	::ISPA_STD::Node<::Parser::Tokens, Types::PY_RAW> PY_RAW_0;
	bool success_1;
	success_1 = false;
	if (!(((*pos)).template holds<Types::PY_RAW>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar: @  PY_RAW");
		return {};
	}
	PY_RAW_0 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::PY_RAW>>();
	success_1 = true;
	pos++;
	Types::stmt result;
	::ISPA_STD::assign_compatible(result.value, PY_RAW_0);
	::ISPA_STD::MatchResult<Rules, Types::stmt, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::stmt<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::stmt, ::Parser::Lexer::iterator>;
template auto Parser::Parser::stmt<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::stmt, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::template_params(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::template_params, IT> {
	::ISPA_STD::Node<::Parser::Tokens, Types::template_params::LESS_THAN_SIGN> template_params_LESS_THAN_SIGN_0;
	bool success_1;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::MatchResult<Rules, Types::param, IT> param_4;
	bool success_5;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_6;
	bool success_7;
	::ISPA_STD::Node<::Parser::Tokens, Types::template_params::GREATER_THAN_SIGN> template_params_GREATER_THAN_SIGN_8;
	bool success_9;
	success_1 = false;
	if (!(((*pos)).template holds<Types::template_params::LESS_THAN_SIGN>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  template_params::LESS_THAN_SIGN");
		return {};
	}
	template_params_LESS_THAN_SIGN_0 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::template_params::LESS_THAN_SIGN>>();
	success_1 = true;
	pos++;
	success_3 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_2 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
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
		__WS_6 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_7 = true;
		pos++;
	}
	success_9 = false;
	if (!(((*pos)).template holds<Types::template_params::GREATER_THAN_SIGN>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  template_params::GREATER_THAN_SIGN");
		return {};
	}
	template_params_GREATER_THAN_SIGN_8 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::template_params::GREATER_THAN_SIGN>>();
	success_9 = true;
	pos++;
	Types::template_params result;
	::ISPA_STD::assign_compatible(result.value, param_4.node);
	::ISPA_STD::MatchResult<Rules, Types::template_params, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::template_params<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::template_params, ::Parser::Lexer::iterator>;
template auto Parser::Parser::template_params<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::template_params, ::Parser::Lexer::lazy_iterator>;
auto Parser::Parser::parseFromTokens() -> void {
	tree = main(Lexer::iterator(lexer)).node.data();
}
auto Parser::Parser::lazyParse() -> void {
	Lexer lexer;
	tree = main(Lexer::lazy_iterator(lexer, text)).node.data();
}
