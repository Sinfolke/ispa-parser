#include "DepParser.h"

#include <ispastdlib/variant_io.hpp>
#include <ispastdlib/dfa_api.hpp>
#include <ispastdlib/assign.hpp>
#include <ispastdlib/to_string.hpp>

auto DepParser::FlatTypes::name_template_params_GREATER_THAN_SIGN::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("name_template_params_GREATER_THAN_SIGN", true);
}
auto DepParser::FlatTypes::name_template_params_GREATER_THAN_SIGN::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::name_template_params_GREATER_THAN_SIGN::to_string() const -> std::string {
	return ::ISPA_STD::concat("name_template_params_GREATER_THAN_SIGN {", "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, name_template_params_GREATER_THAN_SIGN value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::name_template_params_LESS_THAN_SIGN::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("name_template_params_LESS_THAN_SIGN", true);
}
auto DepParser::FlatTypes::name_template_params_LESS_THAN_SIGN::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::name_template_params_LESS_THAN_SIGN::to_string() const -> std::string {
	return ::ISPA_STD::concat("name_template_params_LESS_THAN_SIGN {", "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, name_template_params_LESS_THAN_SIGN value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::AUTO::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("AUTO", true);
}
auto DepParser::FlatTypes::AUTO::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::AUTO::to_string() const -> std::string {
	return ::ISPA_STD::concat("AUTO {", "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, AUTO value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::mod_import_import_value_module_import_AS::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("mod_import_import_value_module_import_AS", true);
}
auto DepParser::FlatTypes::mod_import_import_value_module_import_AS::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::mod_import_import_value_module_import_AS::to_string() const -> std::string {
	return ::ISPA_STD::concat("mod_import_import_value_module_import_AS {", "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, mod_import_import_value_module_import_AS value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::SEMICOLON::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("SEMICOLON", true);
}
auto DepParser::FlatTypes::SEMICOLON::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::SEMICOLON::to_string() const -> std::string {
	return ::ISPA_STD::concat("SEMICOLON {", "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, SEMICOLON value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::mod_detach_DETACH::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("mod_detach_DETACH", true);
}
auto DepParser::FlatTypes::mod_detach_DETACH::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::mod_detach_DETACH::to_string() const -> std::string {
	return ::ISPA_STD::concat("mod_detach_DETACH {", "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, mod_detach_DETACH value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::mod_import_import_value_from_import_FROM::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("mod_import_import_value_from_import_FROM", true);
}
auto DepParser::FlatTypes::mod_import_import_value_from_import_FROM::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::mod_import_import_value_from_import_FROM::to_string() const -> std::string {
	return ::ISPA_STD::concat("mod_import_import_value_from_import_FROM {", "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, mod_import_import_value_from_import_FROM value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::mod_import_import_value_from_import_selection_items_RIGHT_CURLY_BRACKET::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("mod_import_import_value_from_import_selection_items_RIGHT_CURLY_BRACKET", true);
}
auto DepParser::FlatTypes::mod_import_import_value_from_import_selection_items_RIGHT_CURLY_BRACKET::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::mod_import_import_value_from_import_selection_items_RIGHT_CURLY_BRACKET::to_string() const -> std::string {
	return ::ISPA_STD::concat("mod_import_import_value_from_import_selection_items_RIGHT_CURLY_BRACKET {", "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, mod_import_import_value_from_import_selection_items_RIGHT_CURLY_BRACKET value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::COMMA::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("COMMA", true);
}
auto DepParser::FlatTypes::COMMA::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::COMMA::to_string() const -> std::string {
	return ::ISPA_STD::concat("COMMA {", "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, COMMA value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::__WS::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("__WS", true);
}
auto DepParser::FlatTypes::__WS::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::__WS::to_string() const -> std::string {
	return ::ISPA_STD::concat("__WS {", "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, __WS value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::mod_import_import_value_from_import_selection_items_LEFT_CURLY_BRACKET::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("mod_import_import_value_from_import_selection_items_LEFT_CURLY_BRACKET", true);
}
auto DepParser::FlatTypes::mod_import_import_value_from_import_selection_items_LEFT_CURLY_BRACKET::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::mod_import_import_value_from_import_selection_items_LEFT_CURLY_BRACKET::to_string() const -> std::string {
	return ::ISPA_STD::concat("mod_import_import_value_from_import_selection_items_LEFT_CURLY_BRACKET {", "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, mod_import_import_value_from_import_selection_items_LEFT_CURLY_BRACKET value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::ID::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("ID", false);
	printer.up(false);
	printer.node_with_value("value", value, true);
	printer.down();
}
auto DepParser::FlatTypes::ID::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::ID::to_string() const -> std::string {
	return ::ISPA_STD::concat("ID {", "value = ", value, "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, ID value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::mod_import_import_value_from_import_selection_ALL::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("mod_import_import_value_from_import_selection_ALL", true);
}
auto DepParser::FlatTypes::mod_import_import_value_from_import_selection_ALL::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::mod_import_import_value_from_import_selection_ALL::to_string() const -> std::string {
	return ::ISPA_STD::concat("mod_import_import_value_from_import_selection_ALL {", "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, mod_import_import_value_from_import_selection_ALL value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::mod_import_IMPORT::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("mod_import_IMPORT", true);
}
auto DepParser::FlatTypes::mod_import_IMPORT::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::mod_import_IMPORT::to_string() const -> std::string {
	return ::ISPA_STD::concat("mod_import_IMPORT {", "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, mod_import_IMPORT value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::module_path::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("module_path", false);
	printer.up(false);
	printer.node("primary", false);
	printer.up(true);
	primary.print(printer);
	printer.down();
	printer.subtree("nested", nested, true);
	printer.down();
}
auto DepParser::FlatTypes::module_path::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::module_path::to_string() const -> std::string {
	return ::ISPA_STD::concat("module_path {", "primary = ", primary.to_string(), ", ", "nested = ", nested, "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, module_path value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::name_param::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("name_param", false);
	printer.up(false);
	printer.node("first_p", false);
	printer.up(true);
	first_p.print(printer);
	printer.down();
	printer.subtree("following_p", following_p, true);
	printer.down();
}
auto DepParser::FlatTypes::name_param::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::name_param::to_string() const -> std::string {
	return ::ISPA_STD::concat("name_param {", "first_p = ", first_p.to_string(), ", ", "following_p = ", following_p, "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, name_param value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::mod_import_import_value_module_import::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("mod_import_import_value_module_import", false);
	printer.up(false);
	printer.node("source", false);
	printer.up(true);
	source.print(printer);
	printer.down();
	printer.node("alias", true);
	printer.up(false);
	alias.print(printer);
	printer.down();
	printer.down();
}
auto DepParser::FlatTypes::mod_import_import_value_module_import::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::mod_import_import_value_module_import::to_string() const -> std::string {
	return ::ISPA_STD::concat("mod_import_import_value_module_import {", "source = ", source.to_string(), ", ", "alias = ", alias.to_string(), "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, mod_import_import_value_module_import value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::mod_detach::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("mod_detach", false);
	printer.up(false);
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto DepParser::FlatTypes::mod_detach::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::mod_detach::to_string() const -> std::string {
	return ::ISPA_STD::concat("mod_detach {", "value = ", value.to_string(), "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, mod_detach value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::mod_import_import_value_from_import_selection_items::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("mod_import_import_value_from_import_selection_items", false);
	printer.up(false);
	printer.node("first", false);
	printer.up(true);
	first.print(printer);
	printer.down();
	printer.subtree("sequence", sequence, true);
	printer.down();
}
auto DepParser::FlatTypes::mod_import_import_value_from_import_selection_items::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::mod_import_import_value_from_import_selection_items::to_string() const -> std::string {
	return ::ISPA_STD::concat("mod_import_import_value_from_import_selection_items {", "first = ", first.to_string(), ", ", "sequence = ", sequence, "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, mod_import_import_value_from_import_selection_items value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::name_template_params::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("name_template_params", false);
	printer.up(false);
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto DepParser::FlatTypes::name_template_params::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::name_template_params::to_string() const -> std::string {
	return ::ISPA_STD::concat("name_template_params {", "value = ", value.to_string(), "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, name_template_params value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::mod_import_import_value_from_import_selection::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("mod_import_import_value_from_import_selection", false);
	printer.up(false);
	printer.node_with_value("value", value, true);
	printer.down();
}
auto DepParser::FlatTypes::mod_import_import_value_from_import_selection::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::mod_import_import_value_from_import_selection::to_string() const -> std::string {
	return ::ISPA_STD::concat("mod_import_import_value_from_import_selection {", "value = ", value, "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, mod_import_import_value_from_import_selection value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::name::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("name", false);
	printer.up(false);
	printer.node("primary", false);
	printer.up(true);
	primary.print(printer);
	printer.down();
	printer.subtree("nested", nested, false);
	printer.node("temp_params", true);
	printer.up(false);
	temp_params.print(printer);
	printer.down();
	printer.down();
}
auto DepParser::FlatTypes::name::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::name::to_string() const -> std::string {
	return ::ISPA_STD::concat("name {", "primary = ", primary.to_string(), ", ", "nested = ", nested, ", ", "temp_params = ", temp_params.to_string(), "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, name value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::mod_import_import_value_from_import::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("mod_import_import_value_from_import", false);
	printer.up(false);
	printer.node("sel", false);
	printer.up(true);
	sel.print(printer);
	printer.down();
	printer.node("source", true);
	printer.up(false);
	source.print(printer);
	printer.down();
	printer.down();
}
auto DepParser::FlatTypes::mod_import_import_value_from_import::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::mod_import_import_value_from_import::to_string() const -> std::string {
	return ::ISPA_STD::concat("mod_import_import_value_from_import {", "sel = ", sel.to_string(), ", ", "source = ", source.to_string(), "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, mod_import_import_value_from_import value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::mod_import_import_value::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("mod_import_import_value", false);
	printer.up(false);
	printer.node_with_value("value", value, true);
	printer.down();
}
auto DepParser::FlatTypes::mod_import_import_value::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::mod_import_import_value::to_string() const -> std::string {
	return ::ISPA_STD::concat("mod_import_import_value {", "value = ", value, "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, mod_import_import_value value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::mod_import::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("mod_import", false);
	printer.up(false);
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto DepParser::FlatTypes::mod_import::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::mod_import::to_string() const -> std::string {
	return ::ISPA_STD::concat("mod_import {", "value = ", value.to_string(), "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, mod_import value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::main::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("main", false);
	printer.up(false);
	printer.node_with_value("value", value, true);
	printer.down();
}
auto DepParser::FlatTypes::main::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::main::to_string() const -> std::string {
	return ::ISPA_STD::concat("main {", "value = ", value, "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, main value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::Lexer::semantic_action_exec(long long state, const ::ISPA_STD::DFA::API::Captures& captures, long long start_pos, const char* start, long long length, long long line) -> std::pair<long long, Token> {
	switch (state) {
		case 0: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::__WS::id, Types::__WS{}));
			break;
		}
		case 1: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::mod_import::import_value::from_import::selection::ALL::id, Types::mod_import::import_value::from_import::selection::ALL{}));
			break;
		}
		case 2: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::COMMA::id, Types::COMMA{}));
			break;
		}
		case 3: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::SEMICOLON::id, Types::SEMICOLON{}));
			break;
		}
		case 4: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::name::template_params::LESS_THAN_SIGN::id, Types::name::template_params::LESS_THAN_SIGN{}));
			break;
		}
		case 5: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::name::template_params::GREATER_THAN_SIGN::id, Types::name::template_params::GREATER_THAN_SIGN{}));
			break;
		}
		case 6: {
			std::string value = captures.text(0);
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::ID::id, Types::ID{value}));
			break;
		}
		case 7: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::mod_import::import_value::from_import::selection::items::LEFT_CURLY_BRACKET::id, Types::mod_import::import_value::from_import::selection::items::LEFT_CURLY_BRACKET{}));
			break;
		}
		case 8: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::mod_import::import_value::from_import::selection::items::RIGHT_CURLY_BRACKET::id, Types::mod_import::import_value::from_import::selection::items::RIGHT_CURLY_BRACKET{}));
			break;
		}
		case 9: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::AUTO::id, Types::AUTO{}));
			break;
		}
		case 10: {
			std::string value = captures.text(0);
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::ID::id, Types::ID{value}));
			break;
		}
		case 11: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::mod_import::import_value::module_import::AS::id, Types::mod_import::import_value::module_import::AS{}));
			break;
		}
		case 12: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::mod_import::import_value::from_import::FROM::id, Types::mod_import::import_value::from_import::FROM{}));
			break;
		}
		case 13: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::mod_detach::DETACH::id, Types::mod_detach::DETACH{}));
			break;
		}
		case 14: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::mod_import::IMPORT::id, Types::mod_import::IMPORT{}));
			break;
		}
	}
	throw std::runtime_error("Out of bound semantic action");
}
auto DepParser::Lexer::init() -> void {
	return ;
}
auto DepParser::Lexer::makeToken(const char*& pos) -> Token {
	return lookup(dfa_table, char_class_table, action_table, tdfa_registers, semantic_action_exec, debug_array, debug_index, pos);
}
::ISPA_STD::DFA::API::CharToClass DepParser::Lexer::char_class_table = {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 3, 4, 0, 0, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 0, 6, 7, 0, 8, 0, 0, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 0, 0, 0, 0, 9, 0, 10, 9, 11, 12, 13, 14, 9, 15, 16, 9, 9, 9, 17, 9, 18, 19, 9, 20, 21, 22, 9, 9, 9, 9, 9, 9, 23, 0, 24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
::ISPA_STD::DFA::API::Table<31, 25> DepParser::Lexer::dfa_table = {{{::ISPA_STD::DFA::API::null_state, 1, 2, 3, 4, ::ISPA_STD::DFA::API::null_state, 5, 6, 7, 31, 33, 31, 34, 31, 32, 31, 35, 31, 31, 31, 31, 31, 31, 13, 14}, {67, 1, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67}, {68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68}, {69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69}, {::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, 15, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state}, {70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70}, {71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71}, {72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72}, {36, 36, 36, 36, 36, 16, 36, 36, 36, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 36, 36}, {38, 38, 38, 38, 38, 39, 38, 38, 38, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 17, 39, 38, 38}, {41, 41, 41, 41, 41, 39, 41, 41, 41, 39, 39, 39, 39, 18, 39, 39, 39, 39, 39, 39, 39, 39, 39, 41, 41}, {43, 43, 43, 43, 43, 39, 43, 43, 43, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 19, 39, 39, 43, 43}, {45, 45, 45, 45, 45, 39, 45, 45, 45, 39, 39, 39, 39, 39, 39, 39, 39, 20, 39, 39, 39, 39, 39, 45, 45}, {74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74}, {75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75}, {76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76}, {46, 46, 46, 46, 46, 16, 46, 46, 46, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 46, 46}, {78, 78, 78, 78, 78, 39, 78, 78, 78, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 78, 78}, {48, 48, 48, 48, 48, 39, 48, 48, 48, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 21, 48, 48}, {50, 50, 50, 50, 50, 39, 50, 50, 50, 39, 39, 39, 39, 39, 39, 39, 39, 39, 22, 39, 39, 39, 39, 50, 50}, {52, 52, 52, 52, 52, 39, 52, 52, 52, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 23, 39, 39, 39, 52, 52}, {54, 54, 54, 54, 54, 39, 54, 54, 54, 39, 24, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 54, 54}, {56, 56, 56, 56, 56, 39, 56, 56, 56, 39, 39, 39, 39, 39, 39, 39, 39, 25, 39, 39, 39, 39, 39, 56, 56}, {58, 58, 58, 58, 58, 39, 58, 58, 58, 39, 39, 39, 39, 39, 39, 39, 39, 39, 26, 39, 39, 39, 39, 58, 58}, {60, 60, 60, 60, 60, 39, 60, 60, 60, 39, 39, 27, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 60, 60}, {79, 79, 79, 79, 79, 39, 79, 79, 79, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 79, 79}, {62, 62, 62, 62, 62, 39, 62, 62, 62, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 28, 39, 39, 62, 62}, {64, 64, 64, 64, 64, 39, 64, 64, 64, 39, 39, 39, 39, 39, 39, 29, 39, 39, 39, 39, 39, 39, 39, 64, 64}, {66, 66, 66, 66, 66, 39, 66, 66, 66, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 30, 66, 66}, {80, 80, 80, 80, 80, 39, 80, 80, 80, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 80, 80}, {81, 81, 81, 81, 81, 39, 81, 81, 81, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 81, 81}}};
::ISPA_STD::DFA::API::Table<36, 4> DepParser::Lexer::action_table = {{{1, 0, ::ISPA_STD::DFA::API::null_state, 8}, {1, 2, ::ISPA_STD::DFA::API::null_state, 11}, {1, 2, ::ISPA_STD::DFA::API::null_state, 9}, {1, 2, ::ISPA_STD::DFA::API::null_state, 10}, {1, 2, ::ISPA_STD::DFA::API::null_state, 12}, {1, 1, ::ISPA_STD::DFA::API::null_state, 73}, {3, 0, 2, 73}, {1, 1, ::ISPA_STD::DFA::API::null_state, 37}, {3, 0, 2, 16}, {3, 0, 2, 73}, {1, 1, ::ISPA_STD::DFA::API::null_state, 40}, {3, 0, 2, 73}, {1, 1, ::ISPA_STD::DFA::API::null_state, 42}, {3, 0, 2, 73}, {1, 1, ::ISPA_STD::DFA::API::null_state, 44}, {1, 1, ::ISPA_STD::DFA::API::null_state, 77}, {3, 0, 2, 77}, {1, 1, ::ISPA_STD::DFA::API::null_state, 47}, {3, 0, 2, 77}, {1, 1, ::ISPA_STD::DFA::API::null_state, 49}, {3, 0, 2, 77}, {1, 1, ::ISPA_STD::DFA::API::null_state, 51}, {3, 0, 2, 77}, {1, 1, ::ISPA_STD::DFA::API::null_state, 53}, {3, 0, 2, 77}, {1, 1, ::ISPA_STD::DFA::API::null_state, 55}, {3, 0, 2, 77}, {1, 1, ::ISPA_STD::DFA::API::null_state, 57}, {3, 0, 2, 77}, {1, 1, ::ISPA_STD::DFA::API::null_state, 59}, {3, 0, 2, 77}, {1, 1, ::ISPA_STD::DFA::API::null_state, 61}, {3, 0, 2, 77}, {1, 1, ::ISPA_STD::DFA::API::null_state, 63}, {3, 0, 2, 77}, {1, 1, ::ISPA_STD::DFA::API::null_state, 65}}};
std::array<::ISPA_STD::DFA::API::DFADebug, 1> DepParser::Lexer::debug_array = {::ISPA_STD::DFA::API::DFADebug {"<Undefined>", "", 0, -1, -1, -1, 0, 1, '\000'}};
std::unordered_map<long long, std::unordered_map<long long, long long>> DepParser::Lexer::debug_index = { { 0, { { 1, 0 }, { 2, 0 }, { 3, 0 }, { 4, 0 }, { 6, 0 }, { 7, 0 }, { 8, 0 }, { 23, 0 }, { 24, 0 } } }, { 1, { { 1, 0 } } }, { 4, { { 8, 0 } } }, { 8, { { 5, 0 }, { 9, 0 }, { 10, 0 }, { 11, 0 }, { 12, 0 }, { 13, 0 }, { 14, 0 }, { 15, 0 }, { 16, 0 }, { 17, 0 }, { 18, 0 }, { 19, 0 }, { 20, 0 }, { 21, 0 }, { 22, 0 } } }, { 9, { { 21, 0 } } }, { 10, { { 13, 0 } } }, { 11, { { 20, 0 } } }, { 12, { { 17, 0 } } }, { 16, { { 5, 0 }, { 9, 0 }, { 10, 0 }, { 11, 0 }, { 12, 0 }, { 13, 0 }, { 14, 0 }, { 15, 0 }, { 16, 0 }, { 17, 0 }, { 18, 0 }, { 19, 0 }, { 20, 0 }, { 21, 0 }, { 22, 0 } } }, { 18, { { 22, 0 } } }, { 19, { { 18, 0 } } }, { 20, { { 19, 0 } } }, { 21, { { 10, 0 } } }, { 22, { { 17, 0 } } }, { 23, { { 18, 0 } } }, { 24, { { 11, 0 } } }, { 26, { { 20, 0 } } }, { 27, { { 15, 0 } } }, { 28, { { 22, 0 } } } };
template<typename IT, class> auto DepParser::Parser::main(IT pos) -> ::ISPA_STD::MatchResult<Types::main, IT> {
	std::variant<std::monostate, ::ISPA_STD::Node<Types::mod_detach>, ::ISPA_STD::Node<Types::mod_import>> _0;
	bool success_1;
	::ISPA_STD::MatchResult<Types::mod_detach, IT> mod_detach_2;
	bool success_3;
	::ISPA_STD::MatchResult<Types::mod_import, IT> mod_import_4;
	bool success_5;
	success_1 = false;
	// grammar `@  ( mod_import |  mod_detach)`: choice; reset match status before selecting an alternative
	success_1 = false;
	auto lookahead_pos_1 = pos;
	switch ((*lookahead_pos_1).kind()) {
		case Tokens::mod_detach::DETACH::id: {
			lookahead_pos_1 = lookahead_pos_1;
			success_3 = false;
			mod_detach_2 = mod_detach(lookahead_pos_1);
			if (!(mod_detach_2.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  mod_detach");
				return {};
			}
			success_3 = true;
			lookahead_pos_1 = mod_detach_2.it;
			if (!success_3) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  mod_detach");
				return {};
			}
			_0 = mod_detach_2.node;
			success_1 = true;
			break;
		}
		case Tokens::mod_import::IMPORT::id: {
			lookahead_pos_1 = lookahead_pos_1;
			success_5 = false;
			mod_import_4 = mod_import(lookahead_pos_1);
			if (!(mod_import_4.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  mod_import");
				return {};
			}
			success_5 = true;
			lookahead_pos_1 = mod_import_4.it;
			if (!success_5) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  mod_import");
				return {};
			}
			_0 = mod_import_4.node;
			success_1 = true;
			break;
		}
	}
	pos = lookahead_pos_1;
	if (!success_1) {
		raise_error(*pos, "ISPA match failure: no LL(k) alternative matched | grammar: @  ( mod_import |  mod_detach)");
		return {};
	}
	Types::main result;
	::ISPA_STD::assign_compatible(result.value, _0);
	::ISPA_STD::MatchResult<Types::main, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto DepParser::Parser::main<::DepParser::Lexer::iterator>(::DepParser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::main, ::DepParser::Lexer::iterator>;
template auto DepParser::Parser::main<::DepParser::Lexer::lazy_iterator>(::DepParser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::main, ::DepParser::Lexer::lazy_iterator>;
template<typename IT, class> auto DepParser::Parser::mod_detach(IT pos) -> ::ISPA_STD::MatchResult<Types::mod_detach, IT> {
	::ISPA_STD::Node<Types::mod_detach::DETACH> mod_detach_DETACH_0;
	bool success_1;
	::ISPA_STD::Node<Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::MatchResult<Types::module_path, IT> module_path_4;
	bool success_5;
	::ISPA_STD::Node<Types::__WS> __WS_6;
	bool success_7;
	::ISPA_STD::Node<Types::SEMICOLON> SEMICOLON_8;
	bool success_9;
	success_1 = false;
	if (!(((*pos)).template holds<Types::mod_detach::DETACH>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  mod_detach::DETACH");
		return {};
	}
	mod_detach_DETACH_0 = ((*pos)).template to_node<::ISPA_STD::Node<Types::mod_detach::DETACH>>();
	success_1 = true;
	pos++;
	success_3 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_2 = ((*pos)).template to_node<::ISPA_STD::Node<Types::__WS>>();
		success_3 = true;
		pos++;
	}
	success_5 = false;
	module_path_4 = module_path(pos);
	if (!(module_path_4.status)) {
		raise_error(*pos, "ISPA match failure: required named rule did not match | grammar: @  module_path");
		return {};
	}
	success_5 = true;
	pos = module_path_4.it;
	success_7 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_6 = ((*pos)).template to_node<::ISPA_STD::Node<Types::__WS>>();
		success_7 = true;
		pos++;
	}
	success_9 = false;
	if (!(((*pos)).template holds<Types::SEMICOLON>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  SEMICOLON");
		return {};
	}
	SEMICOLON_8 = ((*pos)).template to_node<::ISPA_STD::Node<Types::SEMICOLON>>();
	success_9 = true;
	pos++;
	Types::mod_detach result;
	::ISPA_STD::assign_compatible(result.value, module_path_4.node);
	::ISPA_STD::MatchResult<Types::mod_detach, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto DepParser::Parser::mod_detach<::DepParser::Lexer::iterator>(::DepParser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::mod_detach, ::DepParser::Lexer::iterator>;
template auto DepParser::Parser::mod_detach<::DepParser::Lexer::lazy_iterator>(::DepParser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::mod_detach, ::DepParser::Lexer::lazy_iterator>;
template<typename IT, class> auto DepParser::Parser::mod_import(IT pos) -> ::ISPA_STD::MatchResult<Types::mod_import, IT> {
	::ISPA_STD::Node<Types::mod_import::IMPORT> mod_import_IMPORT_0;
	bool success_1;
	::ISPA_STD::Node<Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::MatchResult<Types::mod_import::import_value, IT> mod_import_import_value_4;
	bool success_5;
	::ISPA_STD::Node<Types::__WS> __WS_6;
	bool success_7;
	::ISPA_STD::Node<Types::SEMICOLON> SEMICOLON_8;
	bool success_9;
	success_1 = false;
	if (!(((*pos)).template holds<Types::mod_import::IMPORT>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  mod_import::IMPORT");
		return {};
	}
	mod_import_IMPORT_0 = ((*pos)).template to_node<::ISPA_STD::Node<Types::mod_import::IMPORT>>();
	success_1 = true;
	pos++;
	success_3 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_2 = ((*pos)).template to_node<::ISPA_STD::Node<Types::__WS>>();
		success_3 = true;
		pos++;
	}
	success_5 = false;
	mod_import_import_value_4 = mod_import_import_value(pos);
	if (!(mod_import_import_value_4.status)) {
		raise_error(*pos, "ISPA match failure: required named rule did not match | grammar: @  mod_import::import_value");
		return {};
	}
	success_5 = true;
	pos = mod_import_import_value_4.it;
	success_7 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_6 = ((*pos)).template to_node<::ISPA_STD::Node<Types::__WS>>();
		success_7 = true;
		pos++;
	}
	success_9 = false;
	if (!(((*pos)).template holds<Types::SEMICOLON>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  SEMICOLON");
		return {};
	}
	SEMICOLON_8 = ((*pos)).template to_node<::ISPA_STD::Node<Types::SEMICOLON>>();
	success_9 = true;
	pos++;
	Types::mod_import result;
	::ISPA_STD::assign_compatible(result.value, mod_import_import_value_4.node);
	::ISPA_STD::MatchResult<Types::mod_import, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto DepParser::Parser::mod_import<::DepParser::Lexer::iterator>(::DepParser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::mod_import, ::DepParser::Lexer::iterator>;
template auto DepParser::Parser::mod_import<::DepParser::Lexer::lazy_iterator>(::DepParser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::mod_import, ::DepParser::Lexer::lazy_iterator>;
template<typename IT, class> auto DepParser::Parser::mod_import_import_value(IT pos) -> ::ISPA_STD::MatchResult<Types::mod_import::import_value, IT> {
	std::variant<std::monostate, ::ISPA_STD::Node<Types::mod_import::import_value::from_import>, ::ISPA_STD::Node<Types::mod_import::import_value::module_import>> _0;
	bool success_1;
	::ISPA_STD::MatchResult<Types::mod_import::import_value::module_import, IT> mod_import_import_value_module_import_2;
	bool success_3;
	::ISPA_STD::MatchResult<Types::mod_import::import_value::from_import, IT> mod_import_import_value_from_import_4;
	bool success_5;
	::ISPA_STD::MatchResult<Types::mod_import::import_value::from_import, IT> mod_import_import_value_from_import_6;
	bool success_7;
	success_1 = false;
	// grammar `@  ( mod_import::import_value::module_import |  mod_import::import_value::from_import)`: choice; reset match status before selecting an alternative
	success_1 = false;
	auto lookahead_pos_1 = pos;
	switch ((*lookahead_pos_1).kind()) {
		case Tokens::ID::id: {
			lookahead_pos_1 = lookahead_pos_1;
			success_3 = false;
			mod_import_import_value_module_import_2 = mod_import_import_value_module_import(lookahead_pos_1);
			if (!(mod_import_import_value_module_import_2.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  mod_import::import_value::module_import");
				return {};
			}
			success_3 = true;
			lookahead_pos_1 = mod_import_import_value_module_import_2.it;
			if (!success_3) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  mod_import::import_value::module_import");
				return {};
			}
			_0 = mod_import_import_value_module_import_2.node;
			success_1 = true;
			break;
		}
		case Tokens::mod_import::import_value::from_import::selection::ALL::id: {
			lookahead_pos_1 = lookahead_pos_1;
			success_5 = false;
			mod_import_import_value_from_import_4 = mod_import_import_value_from_import(lookahead_pos_1);
			if (!(mod_import_import_value_from_import_4.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  mod_import::import_value::from_import");
				return {};
			}
			success_5 = true;
			lookahead_pos_1 = mod_import_import_value_from_import_4.it;
			if (!success_5) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  mod_import::import_value::from_import");
				return {};
			}
			_0 = mod_import_import_value_from_import_4.node;
			success_1 = true;
			break;
		}
		case Tokens::mod_import::import_value::from_import::selection::items::LEFT_CURLY_BRACKET::id: {
			lookahead_pos_1 = lookahead_pos_1;
			success_7 = false;
			mod_import_import_value_from_import_6 = mod_import_import_value_from_import(lookahead_pos_1);
			if (!(mod_import_import_value_from_import_6.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  mod_import::import_value::from_import");
				return {};
			}
			success_7 = true;
			lookahead_pos_1 = mod_import_import_value_from_import_6.it;
			if (!success_7) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  mod_import::import_value::from_import");
				return {};
			}
			_0 = mod_import_import_value_from_import_6.node;
			success_1 = true;
			break;
		}
	}
	pos = lookahead_pos_1;
	if (!success_1) {
		raise_error(*pos, "ISPA match failure: no LL(k) alternative matched | grammar: @  ( mod_import::import_value::module_import |  mod_import::import_value::from_import)");
		return {};
	}
	Types::mod_import::import_value result;
	::ISPA_STD::assign_compatible(result.value, _0);
	::ISPA_STD::MatchResult<Types::mod_import::import_value, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto DepParser::Parser::mod_import_import_value<::DepParser::Lexer::iterator>(::DepParser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::mod_import::import_value, ::DepParser::Lexer::iterator>;
template auto DepParser::Parser::mod_import_import_value<::DepParser::Lexer::lazy_iterator>(::DepParser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::mod_import::import_value, ::DepParser::Lexer::lazy_iterator>;
template<typename IT, class> auto DepParser::Parser::mod_import_import_value_from_import(IT pos) -> ::ISPA_STD::MatchResult<Types::mod_import::import_value::from_import, IT> {
	::ISPA_STD::MatchResult<Types::mod_import::import_value::from_import::selection, IT> mod_import_import_value_from_import_selection_0;
	bool success_1;
	::ISPA_STD::Node<Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::Node<Types::mod_import::import_value::from_import::FROM> mod_import_import_value_from_import_FROM_4;
	bool success_5;
	::ISPA_STD::Node<Types::__WS> __WS_6;
	bool success_7;
	::ISPA_STD::MatchResult<Types::module_path, IT> module_path_8;
	bool success_9;
	success_1 = false;
	mod_import_import_value_from_import_selection_0 = mod_import_import_value_from_import_selection(pos);
	if (!(mod_import_import_value_from_import_selection_0.status)) {
		raise_error(*pos, "ISPA match failure: required named rule did not match | grammar: @  mod_import::import_value::from_import::selection");
		return {};
	}
	success_1 = true;
	pos = mod_import_import_value_from_import_selection_0.it;
	success_3 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_2 = ((*pos)).template to_node<::ISPA_STD::Node<Types::__WS>>();
		success_3 = true;
		pos++;
	}
	success_5 = false;
	if (!(((*pos)).template holds<Types::mod_import::import_value::from_import::FROM>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  mod_import::import_value::from_import::FROM");
		return {};
	}
	mod_import_import_value_from_import_FROM_4 = ((*pos)).template to_node<::ISPA_STD::Node<Types::mod_import::import_value::from_import::FROM>>();
	success_5 = true;
	pos++;
	success_7 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_6 = ((*pos)).template to_node<::ISPA_STD::Node<Types::__WS>>();
		success_7 = true;
		pos++;
	}
	success_9 = false;
	module_path_8 = module_path(pos);
	if (!(module_path_8.status)) {
		raise_error(*pos, "ISPA match failure: required named rule did not match | grammar: @  module_path");
		return {};
	}
	success_9 = true;
	pos = module_path_8.it;
	Types::mod_import::import_value::from_import result;
	::ISPA_STD::assign_compatible(result.sel, mod_import_import_value_from_import_selection_0);
	::ISPA_STD::assign_compatible(result.source, module_path_8);
	::ISPA_STD::MatchResult<Types::mod_import::import_value::from_import, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto DepParser::Parser::mod_import_import_value_from_import<::DepParser::Lexer::iterator>(::DepParser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::mod_import::import_value::from_import, ::DepParser::Lexer::iterator>;
template auto DepParser::Parser::mod_import_import_value_from_import<::DepParser::Lexer::lazy_iterator>(::DepParser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::mod_import::import_value::from_import, ::DepParser::Lexer::lazy_iterator>;
template<typename IT, class> auto DepParser::Parser::mod_import_import_value_from_import_selection(IT pos) -> ::ISPA_STD::MatchResult<Types::mod_import::import_value::from_import::selection, IT> {
	std::variant<std::monostate, ::ISPA_STD::Node<Types::mod_import::import_value::from_import::selection::items>, ::ISPA_STD::Node<Types::mod_import::import_value::from_import::selection::ALL>> _0;
	bool success_1;
	::ISPA_STD::Node<Types::mod_import::import_value::from_import::selection::ALL> mod_import_import_value_from_import_selection_ALL_2;
	bool success_3;
	::ISPA_STD::MatchResult<Types::mod_import::import_value::from_import::selection::items, IT> mod_import_import_value_from_import_selection_items_4;
	bool success_5;
	success_1 = false;
	// grammar `@  ( mod_import::import_value::from_import::selection::ALL |  mod_import::import_value::from_import::selection::items)`: choice; reset match status before selecting an alternative
	success_1 = false;
	auto lookahead_pos_1 = pos;
	switch ((*lookahead_pos_1).kind()) {
		case Tokens::mod_import::import_value::from_import::selection::ALL::id: {
			lookahead_pos_1 = lookahead_pos_1;
			success_3 = false;
			if (!(((*lookahead_pos_1)).template holds<Types::mod_import::import_value::from_import::selection::ALL>())) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  mod_import::import_value::from_import::selection::ALL");
				return {};
			}
			mod_import_import_value_from_import_selection_ALL_2 = ((*lookahead_pos_1)).template to_node<::ISPA_STD::Node<Types::mod_import::import_value::from_import::selection::ALL>>();
			success_3 = true;
			lookahead_pos_1++;
			if (!success_3) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  mod_import::import_value::from_import::selection::ALL");
				return {};
			}
			_0 = mod_import_import_value_from_import_selection_ALL_2;
			success_1 = true;
			break;
		}
		case Tokens::mod_import::import_value::from_import::selection::items::LEFT_CURLY_BRACKET::id: {
			lookahead_pos_1 = lookahead_pos_1;
			success_5 = false;
			mod_import_import_value_from_import_selection_items_4 = mod_import_import_value_from_import_selection_items(lookahead_pos_1);
			if (!(mod_import_import_value_from_import_selection_items_4.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  mod_import::import_value::from_import::selection::items");
				return {};
			}
			success_5 = true;
			lookahead_pos_1 = mod_import_import_value_from_import_selection_items_4.it;
			if (!success_5) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  mod_import::import_value::from_import::selection::items");
				return {};
			}
			_0 = mod_import_import_value_from_import_selection_items_4.node;
			success_1 = true;
			break;
		}
	}
	pos = lookahead_pos_1;
	if (!success_1) {
		raise_error(*pos, "ISPA match failure: no LL(k) alternative matched | grammar: @  ( mod_import::import_value::from_import::selection::ALL |  mod_import::import_value::from_import::selection::items)");
		return {};
	}
	Types::mod_import::import_value::from_import::selection result;
	::ISPA_STD::assign_compatible(result.value, _0);
	::ISPA_STD::MatchResult<Types::mod_import::import_value::from_import::selection, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto DepParser::Parser::mod_import_import_value_from_import_selection<::DepParser::Lexer::iterator>(::DepParser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::mod_import::import_value::from_import::selection, ::DepParser::Lexer::iterator>;
template auto DepParser::Parser::mod_import_import_value_from_import_selection<::DepParser::Lexer::lazy_iterator>(::DepParser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::mod_import::import_value::from_import::selection, ::DepParser::Lexer::lazy_iterator>;
template<typename IT, class> auto DepParser::Parser::mod_import_import_value_from_import_selection_items(IT pos) -> ::ISPA_STD::MatchResult<Types::mod_import::import_value::from_import::selection::items, IT> {
	::ISPA_STD::Node<Types::mod_import::import_value::from_import::selection::items::LEFT_CURLY_BRACKET> mod_import_import_value_from_import_selection_items_LEFT_CURLY_BRACKET_0;
	bool success_1;
	::ISPA_STD::Node<Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::MatchResult<Types::module_path, IT> module_path_4;
	bool success_5;
	bool success_21;
	bool success_13;
	std::vector<::ISPA_STD::Node<Types::COMMA>> shadow_24;
	::ISPA_STD::Node<Types::module_path> group_capture_25;
	std::vector<::ISPA_STD::Node<Types::module_path>> shadow_26;
	std::tuple<::ISPA_STD::Node<Types::COMMA>, ::ISPA_STD::Node<Types::__WS>, ::ISPA_STD::Node<Types::module_path>> group_8;
	bool success_10;
	std::vector<std::tuple<::ISPA_STD::Node<Types::COMMA>, ::ISPA_STD::Node<Types::__WS>, ::ISPA_STD::Node<Types::module_path>>> shadow_28;
	std::vector<std::tuple<::ISPA_STD::Node<Types::COMMA>, ::ISPA_STD::Node<Types::__WS>, ::ISPA_STD::Node<Types::module_path>>> uvar_9;
	::ISPA_STD::Node<Types::__WS> __WS_6;
	bool success_7;
	::ISPA_STD::Node<Types::COMMA> COMMA_12;
	::ISPA_STD::Node<Types::COMMA> uvar_11;
	std::vector<::ISPA_STD::Node<Types::COMMA>> shadow_14;
	::ISPA_STD::Node<Types::__WS> __WS_16;
	bool success_17;
	::ISPA_STD::Node<Types::__WS> uvar_15;
	std::vector<::ISPA_STD::Node<Types::__WS>> shadow_18;
	::ISPA_STD::MatchResult<Types::module_path, IT> module_path_20;
	::ISPA_STD::Node<Types::module_path> element_22;
	std::vector<::ISPA_STD::Node<Types::module_path>> shadow_23;
	::ISPA_STD::Node<Types::module_path> uvar_19;
	::ISPA_STD::Node<Types::module_path> tuple_elem_27;
	::ISPA_STD::Node<Types::__WS> __WS_31;
	bool success_32;
	::ISPA_STD::Node<Types::mod_import::import_value::from_import::selection::items::RIGHT_CURLY_BRACKET> mod_import_import_value_from_import_selection_items_RIGHT_CURLY_BRACKET_33;
	bool success_34;
	success_1 = false;
	if (!(((*pos)).template holds<Types::mod_import::import_value::from_import::selection::items::LEFT_CURLY_BRACKET>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  mod_import::import_value::from_import::selection::items::LEFT_CURLY_BRACKET");
		return {};
	}
	mod_import_import_value_from_import_selection_items_LEFT_CURLY_BRACKET_0 = ((*pos)).template to_node<::ISPA_STD::Node<Types::mod_import::import_value::from_import::selection::items::LEFT_CURLY_BRACKET>>();
	success_1 = true;
	pos++;
	success_3 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_2 = ((*pos)).template to_node<::ISPA_STD::Node<Types::__WS>>();
		success_3 = true;
		pos++;
	}
	success_5 = false;
	module_path_4 = module_path(pos);
	if (!(module_path_4.status)) {
		raise_error(*pos, "ISPA match failure: required named rule did not match | grammar: @  module_path");
		return {};
	}
	success_5 = true;
	pos = module_path_4.it;
	success_10 = false;
	auto begin_29 = pos;
	while (true) {
		auto repeat_ws_30 = begin_29;
		success_7 = false;
		if (((*repeat_ws_30)).template holds<Types::__WS>()) {
			__WS_6 = ((*repeat_ws_30)).template to_node<::ISPA_STD::Node<Types::__WS>>();
			success_7 = true;
			repeat_ws_30++;
		}
		if (!(((*repeat_ws_30)).template holds<Types::COMMA>())) {
			// speculative match failed (diagnostic suppressed):  COMMA
			break;
		}
		COMMA_12 = ((*repeat_ws_30)).template to_node<::ISPA_STD::Node<Types::COMMA>>();
		success_13 = true;
		repeat_ws_30++;
		shadow_14.push_back(COMMA_12);
		uvar_11 = COMMA_12;
		success_17 = false;
		if (((*repeat_ws_30)).template holds<Types::__WS>()) {
			__WS_16 = ((*repeat_ws_30)).template to_node<::ISPA_STD::Node<Types::__WS>>();
			success_17 = true;
			repeat_ws_30++;
			shadow_18.push_back(__WS_16);
			uvar_15 = __WS_16;
		}
		module_path_20 = module_path(repeat_ws_30);
		if (!(module_path_20.status)) {
			// speculative match failed (diagnostic suppressed): @  module_path
			break;
		}
		success_21 = true;
		repeat_ws_30 = module_path_20.it;
		element_22 = module_path_20.node;
		shadow_23.push_back(element_22);
		if (success_13 && success_21) {
			tuple_elem_27 = module_path_20.node;
			group_8 = std::make_tuple(COMMA_12, __WS_16, tuple_elem_27);
			shadow_28.push_back(group_8);
			shadow_24.push_back(COMMA_12);
			group_capture_25 = module_path_20.node;
			shadow_26.push_back(group_capture_25);
		}
		begin_29 = repeat_ws_30;
	}
	success_10 = true;
	::ISPA_STD::assign_compatible(uvar_9, shadow_28);
	pos = begin_29;
	success_32 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_31 = ((*pos)).template to_node<::ISPA_STD::Node<Types::__WS>>();
		success_32 = true;
		pos++;
	}
	success_34 = false;
	if (!(((*pos)).template holds<Types::mod_import::import_value::from_import::selection::items::RIGHT_CURLY_BRACKET>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  mod_import::import_value::from_import::selection::items::RIGHT_CURLY_BRACKET");
		return {};
	}
	mod_import_import_value_from_import_selection_items_RIGHT_CURLY_BRACKET_33 = ((*pos)).template to_node<::ISPA_STD::Node<Types::mod_import::import_value::from_import::selection::items::RIGHT_CURLY_BRACKET>>();
	success_34 = true;
	pos++;
	Types::mod_import::import_value::from_import::selection::items result;
	::ISPA_STD::assign_compatible(result.first, module_path_4);
	::ISPA_STD::assign_compatible(result.sequence, shadow_26);
	::ISPA_STD::MatchResult<Types::mod_import::import_value::from_import::selection::items, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto DepParser::Parser::mod_import_import_value_from_import_selection_items<::DepParser::Lexer::iterator>(::DepParser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::mod_import::import_value::from_import::selection::items, ::DepParser::Lexer::iterator>;
template auto DepParser::Parser::mod_import_import_value_from_import_selection_items<::DepParser::Lexer::lazy_iterator>(::DepParser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::mod_import::import_value::from_import::selection::items, ::DepParser::Lexer::lazy_iterator>;
template<typename IT, class> auto DepParser::Parser::mod_import_import_value_module_import(IT pos) -> ::ISPA_STD::MatchResult<Types::mod_import::import_value::module_import, IT> {
	::ISPA_STD::MatchResult<Types::module_path, IT> module_path_0;
	bool success_1;
	::ISPA_STD::Node<Types::__WS> __WS_2;
	bool success_3;
	bool success_12;
	bool success_8;
	std::tuple<::ISPA_STD::Node<Types::mod_import::import_value::module_import::AS>, ::ISPA_STD::Node<Types::__WS>, ::ISPA_STD::Node<Types::ID>> group_4;
	bool success_6;
	std::tuple<::ISPA_STD::Node<Types::mod_import::import_value::module_import::AS>, ::ISPA_STD::Node<Types::__WS>, ::ISPA_STD::Node<Types::ID>> uvar_5;
	::ISPA_STD::Node<Types::mod_import::import_value::module_import::AS> mod_import_import_value_module_import_AS_7;
	::ISPA_STD::Node<Types::__WS> __WS_9;
	bool success_10;
	::ISPA_STD::Node<Types::ID> ID_11;
	success_1 = false;
	module_path_0 = module_path(pos);
	if (!(module_path_0.status)) {
		raise_error(*pos, "ISPA match failure: required named rule did not match | grammar: @  module_path");
		return {};
	}
	success_1 = true;
	pos = module_path_0.it;
	success_3 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_2 = ((*pos)).template to_node<::ISPA_STD::Node<Types::__WS>>();
		success_3 = true;
		pos++;
	}
	success_6 = false;
	auto begin_13 = pos;
	success_8 = false;
	success_10 = false;
	success_12 = false;
	// grammar ` ( mod_import::import_value::module_import::AS  __WS?; @  ID)?;`: optional group; try at most once
	while (true) {
		// grammar ` ( mod_import::import_value::module_import::AS  __WS?; @  ID)?;`: optional body; failed alternative leaves this group
		if (!(((*begin_13)).template holds<Types::mod_import::import_value::module_import::AS>())) {
			// speculative match failed (diagnostic suppressed):  mod_import::import_value::module_import::AS
			break;
		}
		mod_import_import_value_module_import_AS_7 = ((*begin_13)).template to_node<::ISPA_STD::Node<Types::mod_import::import_value::module_import::AS>>();
		success_8 = true;
		begin_13++;
		success_10 = false;
		if (((*begin_13)).template holds<Types::__WS>()) {
			__WS_9 = ((*begin_13)).template to_node<::ISPA_STD::Node<Types::__WS>>();
			success_10 = true;
			begin_13++;
		}
		if (!(((*begin_13)).template holds<Types::ID>())) {
			// speculative match failed (diagnostic suppressed): @  ID
			break;
		}
		ID_11 = ((*begin_13)).template to_node<::ISPA_STD::Node<Types::ID>>();
		success_12 = true;
		begin_13++;
		break;
	}
	if (success_8 && success_12) {
		group_4 = std::make_tuple(mod_import_import_value_module_import_AS_7, __WS_9, ID_11);
		success_6 = true;
		::ISPA_STD::assign_compatible(uvar_5, group_4);
	}
	// grammar ` ( mod_import::import_value::module_import::AS  __WS?; @  ID)?;`: optional group end; release saved position
	pos = begin_13;
	Types::mod_import::import_value::module_import result;
	::ISPA_STD::assign_compatible(result.source, module_path_0);
	::ISPA_STD::assign_compatible(result.alias, ID_11);
	::ISPA_STD::MatchResult<Types::mod_import::import_value::module_import, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto DepParser::Parser::mod_import_import_value_module_import<::DepParser::Lexer::iterator>(::DepParser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::mod_import::import_value::module_import, ::DepParser::Lexer::iterator>;
template auto DepParser::Parser::mod_import_import_value_module_import<::DepParser::Lexer::lazy_iterator>(::DepParser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::mod_import::import_value::module_import, ::DepParser::Lexer::lazy_iterator>;
template<typename IT, class> auto DepParser::Parser::module_path(IT pos) -> ::ISPA_STD::MatchResult<Types::module_path, IT> {
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
	Types::module_path result;
	::ISPA_STD::assign_compatible(result.primary, ID_0);
	::ISPA_STD::assign_compatible(result.nested, shadow_20);
	::ISPA_STD::MatchResult<Types::module_path, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto DepParser::Parser::module_path<::DepParser::Lexer::iterator>(::DepParser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::module_path, ::DepParser::Lexer::iterator>;
template auto DepParser::Parser::module_path<::DepParser::Lexer::lazy_iterator>(::DepParser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::module_path, ::DepParser::Lexer::lazy_iterator>;
template<typename IT, class> auto DepParser::Parser::name(IT pos) -> ::ISPA_STD::MatchResult<Types::name, IT> {
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
	::ISPA_STD::MatchResult<Types::name::template_params, IT> name_template_params_26;
	bool success_27;
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
	name_template_params_26 = name_template_params(pos);
	if (name_template_params_26.status) {
		success_27 = true;
		pos = name_template_params_26.it;
	}
	Types::name result;
	::ISPA_STD::assign_compatible(result.primary, ID_0);
	::ISPA_STD::assign_compatible(result.nested, shadow_20);
	::ISPA_STD::assign_compatible(result.temp_params, name_template_params_26);
	::ISPA_STD::MatchResult<Types::name, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto DepParser::Parser::name<::DepParser::Lexer::iterator>(::DepParser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::name, ::DepParser::Lexer::iterator>;
template auto DepParser::Parser::name<::DepParser::Lexer::lazy_iterator>(::DepParser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::name, ::DepParser::Lexer::lazy_iterator>;
template<typename IT, class> auto DepParser::Parser::name_param(IT pos) -> ::ISPA_STD::MatchResult<Types::name::param, IT> {
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
	Types::name::param result;
	::ISPA_STD::assign_compatible(result.first_p, ID_0);
	::ISPA_STD::assign_compatible(result.following_p, shadow_20);
	::ISPA_STD::MatchResult<Types::name::param, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto DepParser::Parser::name_param<::DepParser::Lexer::iterator>(::DepParser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::name::param, ::DepParser::Lexer::iterator>;
template auto DepParser::Parser::name_param<::DepParser::Lexer::lazy_iterator>(::DepParser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::name::param, ::DepParser::Lexer::lazy_iterator>;
template<typename IT, class> auto DepParser::Parser::name_template_params(IT pos) -> ::ISPA_STD::MatchResult<Types::name::template_params, IT> {
	::ISPA_STD::Node<Types::name::template_params::LESS_THAN_SIGN> name_template_params_LESS_THAN_SIGN_0;
	bool success_1;
	::ISPA_STD::Node<Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::MatchResult<Types::name::param, IT> name_param_4;
	bool success_5;
	::ISPA_STD::Node<Types::__WS> __WS_6;
	bool success_7;
	::ISPA_STD::Node<Types::name::template_params::GREATER_THAN_SIGN> name_template_params_GREATER_THAN_SIGN_8;
	bool success_9;
	success_1 = false;
	if (!(((*pos)).template holds<Types::name::template_params::LESS_THAN_SIGN>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  name::template_params::LESS_THAN_SIGN");
		return {};
	}
	name_template_params_LESS_THAN_SIGN_0 = ((*pos)).template to_node<::ISPA_STD::Node<Types::name::template_params::LESS_THAN_SIGN>>();
	success_1 = true;
	pos++;
	success_3 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_2 = ((*pos)).template to_node<::ISPA_STD::Node<Types::__WS>>();
		success_3 = true;
		pos++;
	}
	success_5 = false;
	name_param_4 = name_param(pos);
	if (name_param_4.status) {
		success_5 = true;
		pos = name_param_4.it;
	}
	success_7 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_6 = ((*pos)).template to_node<::ISPA_STD::Node<Types::__WS>>();
		success_7 = true;
		pos++;
	}
	success_9 = false;
	if (!(((*pos)).template holds<Types::name::template_params::GREATER_THAN_SIGN>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  name::template_params::GREATER_THAN_SIGN");
		return {};
	}
	name_template_params_GREATER_THAN_SIGN_8 = ((*pos)).template to_node<::ISPA_STD::Node<Types::name::template_params::GREATER_THAN_SIGN>>();
	success_9 = true;
	pos++;
	Types::name::template_params result;
	::ISPA_STD::assign_compatible(result.value, name_param_4.node);
	::ISPA_STD::MatchResult<Types::name::template_params, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto DepParser::Parser::name_template_params<::DepParser::Lexer::iterator>(::DepParser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::name::template_params, ::DepParser::Lexer::iterator>;
template auto DepParser::Parser::name_template_params<::DepParser::Lexer::lazy_iterator>(::DepParser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::name::template_params, ::DepParser::Lexer::lazy_iterator>;
auto DepParser::Parser::parseFromTokens() -> void {
	tree = main(Lexer::iterator(lexer)).node.data();
}
auto DepParser::Parser::lazyParse() -> void {
	Lexer lexer;
	tree = main(Lexer::lazy_iterator(lexer, text)).node.data();
}
