#include "Parser.h"

#include <ispastdlib/variant_io.hpp>
#include <ispastdlib/dfa_api.hpp>
#include <ispastdlib/assign.hpp>
#include <ispastdlib/to_string.hpp>

auto Parser::FlatTypes::GLOBAL::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("GLOBAL", true);
}
auto Parser::FlatTypes::GLOBAL::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::GLOBAL::to_string() const -> std::string {
	return ::ISPA_STD::concat("GLOBAL {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, GLOBAL value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::ELIF::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("ELIF", true);
}
auto Parser::FlatTypes::ELIF::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::ELIF::to_string() const -> std::string {
	return ::ISPA_STD::concat("ELIF {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, ELIF value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::ASSERT::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("ASSERT", true);
}
auto Parser::FlatTypes::ASSERT::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::ASSERT::to_string() const -> std::string {
	return ::ISPA_STD::concat("ASSERT {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, ASSERT value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::COMMENT::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("COMMENT", true);
}
auto Parser::FlatTypes::COMMENT::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::COMMENT::to_string() const -> std::string {
	return ::ISPA_STD::concat("COMMENT {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, COMMENT value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::PASS::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("PASS", true);
}
auto Parser::FlatTypes::PASS::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::PASS::to_string() const -> std::string {
	return ::ISPA_STD::concat("PASS {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, PASS value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::DEF::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("DEF", true);
}
auto Parser::FlatTypes::DEF::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::DEF::to_string() const -> std::string {
	return ::ISPA_STD::concat("DEF {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, DEF value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::FINALLY::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("FINALLY", true);
}
auto Parser::FlatTypes::FINALLY::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::FINALLY::to_string() const -> std::string {
	return ::ISPA_STD::concat("FINALLY {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, FINALLY value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::WHILE::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("WHILE", true);
}
auto Parser::FlatTypes::WHILE::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::WHILE::to_string() const -> std::string {
	return ::ISPA_STD::concat("WHILE {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, WHILE value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::WITH::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("WITH", true);
}
auto Parser::FlatTypes::WITH::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::WITH::to_string() const -> std::string {
	return ::ISPA_STD::concat("WITH {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, WITH value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::MATMUL_ASSIGN::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("MATMUL_ASSIGN", true);
}
auto Parser::FlatTypes::MATMUL_ASSIGN::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::MATMUL_ASSIGN::to_string() const -> std::string {
	return ::ISPA_STD::concat("MATMUL_ASSIGN {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, MATMUL_ASSIGN value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::ASYNC::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("ASYNC", true);
}
auto Parser::FlatTypes::ASYNC::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::ASYNC::to_string() const -> std::string {
	return ::ISPA_STD::concat("ASYNC {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, ASYNC value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::CONTINUE::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("CONTINUE", true);
}
auto Parser::FlatTypes::CONTINUE::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::CONTINUE::to_string() const -> std::string {
	return ::ISPA_STD::concat("CONTINUE {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, CONTINUE value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::RAISE::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("RAISE", true);
}
auto Parser::FlatTypes::RAISE::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::RAISE::to_string() const -> std::string {
	return ::ISPA_STD::concat("RAISE {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, RAISE value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::NONLOCAL::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("NONLOCAL", true);
}
auto Parser::FlatTypes::NONLOCAL::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::NONLOCAL::to_string() const -> std::string {
	return ::ISPA_STD::concat("NONLOCAL {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, NONLOCAL value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::TILDE::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("TILDE", true);
}
auto Parser::FlatTypes::TILDE::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::TILDE::to_string() const -> std::string {
	return ::ISPA_STD::concat("TILDE {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, TILDE value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::LSHIFT_ASSIGN::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("LSHIFT_ASSIGN", true);
}
auto Parser::FlatTypes::LSHIFT_ASSIGN::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::LSHIFT_ASSIGN::to_string() const -> std::string {
	return ::ISPA_STD::concat("LSHIFT_ASSIGN {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, LSHIFT_ASSIGN value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::BREAK::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("BREAK", true);
}
auto Parser::FlatTypes::BREAK::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::BREAK::to_string() const -> std::string {
	return ::ISPA_STD::concat("BREAK {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, BREAK value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::PERCENT_ASSIGN::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("PERCENT_ASSIGN", true);
}
auto Parser::FlatTypes::PERCENT_ASSIGN::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::PERCENT_ASSIGN::to_string() const -> std::string {
	return ::ISPA_STD::concat("PERCENT_ASSIGN {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, PERCENT_ASSIGN value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::PLUS_ASSIGN::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("PLUS_ASSIGN", true);
}
auto Parser::FlatTypes::PLUS_ASSIGN::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::PLUS_ASSIGN::to_string() const -> std::string {
	return ::ISPA_STD::concat("PLUS_ASSIGN {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, PLUS_ASSIGN value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::STAR_ASSIGN::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("STAR_ASSIGN", true);
}
auto Parser::FlatTypes::STAR_ASSIGN::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::STAR_ASSIGN::to_string() const -> std::string {
	return ::ISPA_STD::concat("STAR_ASSIGN {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, STAR_ASSIGN value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::INDENT::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("INDENT", true);
}
auto Parser::FlatTypes::INDENT::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::INDENT::to_string() const -> std::string {
	return ::ISPA_STD::concat("INDENT {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, INDENT value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::DEL::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("DEL", true);
}
auto Parser::FlatTypes::DEL::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::DEL::to_string() const -> std::string {
	return ::ISPA_STD::concat("DEL {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, DEL value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::IS::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("IS", true);
}
auto Parser::FlatTypes::IS::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::IS::to_string() const -> std::string {
	return ::ISPA_STD::concat("IS {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, IS value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::IN::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("IN", true);
}
auto Parser::FlatTypes::IN::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::IN::to_string() const -> std::string {
	return ::ISPA_STD::concat("IN {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, IN value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::ELSE::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("ELSE", true);
}
auto Parser::FlatTypes::ELSE::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::ELSE::to_string() const -> std::string {
	return ::ISPA_STD::concat("ELSE {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, ELSE value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::IF::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("IF", true);
}
auto Parser::FlatTypes::IF::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::IF::to_string() const -> std::string {
	return ::ISPA_STD::concat("IF {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, IF value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::NOT::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("NOT", true);
}
auto Parser::FlatTypes::NOT::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::NOT::to_string() const -> std::string {
	return ::ISPA_STD::concat("NOT {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, NOT value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::ASSIGN::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("ASSIGN", true);
}
auto Parser::FlatTypes::ASSIGN::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::ASSIGN::to_string() const -> std::string {
	return ::ISPA_STD::concat("ASSIGN {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, ASSIGN value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::MATMUL::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("MATMUL", true);
}
auto Parser::FlatTypes::MATMUL::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::MATMUL::to_string() const -> std::string {
	return ::ISPA_STD::concat("MATMUL {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, MATMUL value) -> std::ostream & {
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
auto Parser::FlatTypes::RPAREN::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("RPAREN", true);
}
auto Parser::FlatTypes::RPAREN::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::RPAREN::to_string() const -> std::string {
	return ::ISPA_STD::concat("RPAREN {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, RPAREN value) -> std::ostream & {
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
auto Parser::FlatTypes::NEWLINE::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("NEWLINE", true);
}
auto Parser::FlatTypes::NEWLINE::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::NEWLINE::to_string() const -> std::string {
	return ::ISPA_STD::concat("NEWLINE {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, NEWLINE value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::RBRACE::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("RBRACE", true);
}
auto Parser::FlatTypes::RBRACE::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::RBRACE::to_string() const -> std::string {
	return ::ISPA_STD::concat("RBRACE {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, RBRACE value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::STRING::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("STRING", false);
	printer.up(false);
	printer.node_with_value("value", value, true);
	printer.down();
}
auto Parser::FlatTypes::STRING::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::STRING::to_string() const -> std::string {
	return ::ISPA_STD::concat("STRING {", "value = ", value, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, STRING value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::FLOOR_DIV::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("FLOOR_DIV", true);
}
auto Parser::FlatTypes::FLOOR_DIV::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::FLOOR_DIV::to_string() const -> std::string {
	return ::ISPA_STD::concat("FLOOR_DIV {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, FLOOR_DIV value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::TRUE::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("TRUE", true);
}
auto Parser::FlatTypes::TRUE::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::TRUE::to_string() const -> std::string {
	return ::ISPA_STD::concat("TRUE {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, TRUE value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::SLASH_ASSIGN::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("SLASH_ASSIGN", true);
}
auto Parser::FlatTypes::SLASH_ASSIGN::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::SLASH_ASSIGN::to_string() const -> std::string {
	return ::ISPA_STD::concat("SLASH_ASSIGN {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, SLASH_ASSIGN value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::TRY::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("TRY", true);
}
auto Parser::FlatTypes::TRY::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::TRY::to_string() const -> std::string {
	return ::ISPA_STD::concat("TRY {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, TRY value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::POWER_ASSIGN::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("POWER_ASSIGN", true);
}
auto Parser::FlatTypes::POWER_ASSIGN::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::POWER_ASSIGN::to_string() const -> std::string {
	return ::ISPA_STD::concat("POWER_ASSIGN {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, POWER_ASSIGN value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::POWER::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("POWER", true);
}
auto Parser::FlatTypes::POWER::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::POWER::to_string() const -> std::string {
	return ::ISPA_STD::concat("POWER {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, POWER value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::PIPE::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("PIPE", true);
}
auto Parser::FlatTypes::PIPE::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::PIPE::to_string() const -> std::string {
	return ::ISPA_STD::concat("PIPE {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, PIPE value) -> std::ostream & {
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
auto Parser::FlatTypes::FOR::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("FOR", true);
}
auto Parser::FlatTypes::FOR::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::FOR::to_string() const -> std::string {
	return ::ISPA_STD::concat("FOR {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, FOR value) -> std::ostream & {
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
auto Parser::FlatTypes::EXCEPT::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("EXCEPT", true);
}
auto Parser::FlatTypes::EXCEPT::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::EXCEPT::to_string() const -> std::string {
	return ::ISPA_STD::concat("EXCEPT {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, EXCEPT value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::NONE_V::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("NONE_V", true);
}
auto Parser::FlatTypes::NONE_V::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::NONE_V::to_string() const -> std::string {
	return ::ISPA_STD::concat("NONE_V {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, NONE_V value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::DEDENT::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("DEDENT", true);
}
auto Parser::FlatTypes::DEDENT::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::DEDENT::to_string() const -> std::string {
	return ::ISPA_STD::concat("DEDENT {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, DEDENT value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::NE::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("NE", true);
}
auto Parser::FlatTypes::NE::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::NE::to_string() const -> std::string {
	return ::ISPA_STD::concat("NE {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, NE value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::LT::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("LT", true);
}
auto Parser::FlatTypes::LT::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::LT::to_string() const -> std::string {
	return ::ISPA_STD::concat("LT {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, LT value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::LE::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("LE", true);
}
auto Parser::FlatTypes::LE::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::LE::to_string() const -> std::string {
	return ::ISPA_STD::concat("LE {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, LE value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::STAR::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("STAR", true);
}
auto Parser::FlatTypes::STAR::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::STAR::to_string() const -> std::string {
	return ::ISPA_STD::concat("STAR {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, STAR value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::SLASH::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("SLASH", true);
}
auto Parser::FlatTypes::SLASH::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::SLASH::to_string() const -> std::string {
	return ::ISPA_STD::concat("SLASH {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, SLASH value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::LBRACKET::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("LBRACKET", true);
}
auto Parser::FlatTypes::LBRACKET::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::LBRACKET::to_string() const -> std::string {
	return ::ISPA_STD::concat("LBRACKET {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, LBRACKET value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::GT::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("GT", true);
}
auto Parser::FlatTypes::GT::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::GT::to_string() const -> std::string {
	return ::ISPA_STD::concat("GT {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, GT value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::PLUS::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("PLUS", true);
}
auto Parser::FlatTypes::PLUS::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::PLUS::to_string() const -> std::string {
	return ::ISPA_STD::concat("PLUS {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, PLUS value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::LSHIFT::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("LSHIFT", true);
}
auto Parser::FlatTypes::LSHIFT::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::LSHIFT::to_string() const -> std::string {
	return ::ISPA_STD::concat("LSHIFT {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, LSHIFT value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::GE::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("GE", true);
}
auto Parser::FlatTypes::GE::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::GE::to_string() const -> std::string {
	return ::ISPA_STD::concat("GE {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, GE value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::IMPORT::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("IMPORT", true);
}
auto Parser::FlatTypes::IMPORT::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::IMPORT::to_string() const -> std::string {
	return ::ISPA_STD::concat("IMPORT {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, IMPORT value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::FLOOR_DIV_ASSIGN::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("FLOOR_DIV_ASSIGN", true);
}
auto Parser::FlatTypes::FLOOR_DIV_ASSIGN::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::FLOOR_DIV_ASSIGN::to_string() const -> std::string {
	return ::ISPA_STD::concat("FLOOR_DIV_ASSIGN {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, FLOOR_DIV_ASSIGN value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::FALSE::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("FALSE", true);
}
auto Parser::FlatTypes::FALSE::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::FALSE::to_string() const -> std::string {
	return ::ISPA_STD::concat("FALSE {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, FALSE value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::EQ::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("EQ", true);
}
auto Parser::FlatTypes::EQ::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::EQ::to_string() const -> std::string {
	return ::ISPA_STD::concat("EQ {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, EQ value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::CARET::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("CARET", true);
}
auto Parser::FlatTypes::CARET::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::CARET::to_string() const -> std::string {
	return ::ISPA_STD::concat("CARET {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, CARET value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::AND::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("AND", true);
}
auto Parser::FlatTypes::AND::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::AND::to_string() const -> std::string {
	return ::ISPA_STD::concat("AND {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, AND value) -> std::ostream & {
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
auto Parser::FlatTypes::AS::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("AS", true);
}
auto Parser::FlatTypes::AS::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::AS::to_string() const -> std::string {
	return ::ISPA_STD::concat("AS {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, AS value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::MINUS_ASSIGN::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("MINUS_ASSIGN", true);
}
auto Parser::FlatTypes::MINUS_ASSIGN::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::MINUS_ASSIGN::to_string() const -> std::string {
	return ::ISPA_STD::concat("MINUS_ASSIGN {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, MINUS_ASSIGN value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::LPAREN::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("LPAREN", true);
}
auto Parser::FlatTypes::LPAREN::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::LPAREN::to_string() const -> std::string {
	return ::ISPA_STD::concat("LPAREN {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, LPAREN value) -> std::ostream & {
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
auto Parser::FlatTypes::AMP::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("AMP", true);
}
auto Parser::FlatTypes::AMP::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::AMP::to_string() const -> std::string {
	return ::ISPA_STD::concat("AMP {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, AMP value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::AMP_ASSIGN::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("AMP_ASSIGN", true);
}
auto Parser::FlatTypes::AMP_ASSIGN::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::AMP_ASSIGN::to_string() const -> std::string {
	return ::ISPA_STD::concat("AMP_ASSIGN {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, AMP_ASSIGN value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::CLASS::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("CLASS", true);
}
auto Parser::FlatTypes::CLASS::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::CLASS::to_string() const -> std::string {
	return ::ISPA_STD::concat("CLASS {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, CLASS value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::MINUS::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("MINUS", true);
}
auto Parser::FlatTypes::MINUS::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::MINUS::to_string() const -> std::string {
	return ::ISPA_STD::concat("MINUS {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, MINUS value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::DOT::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("DOT", true);
}
auto Parser::FlatTypes::DOT::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::DOT::to_string() const -> std::string {
	return ::ISPA_STD::concat("DOT {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, DOT value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::CARET_ASSIGN::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("CARET_ASSIGN", true);
}
auto Parser::FlatTypes::CARET_ASSIGN::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::CARET_ASSIGN::to_string() const -> std::string {
	return ::ISPA_STD::concat("CARET_ASSIGN {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, CARET_ASSIGN value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::RSHIFT_ASSIGN::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("RSHIFT_ASSIGN", true);
}
auto Parser::FlatTypes::RSHIFT_ASSIGN::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::RSHIFT_ASSIGN::to_string() const -> std::string {
	return ::ISPA_STD::concat("RSHIFT_ASSIGN {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, RSHIFT_ASSIGN value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::PERCENT::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("PERCENT", true);
}
auto Parser::FlatTypes::PERCENT::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::PERCENT::to_string() const -> std::string {
	return ::ISPA_STD::concat("PERCENT {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, PERCENT value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::ARROW::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("ARROW", true);
}
auto Parser::FlatTypes::ARROW::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::ARROW::to_string() const -> std::string {
	return ::ISPA_STD::concat("ARROW {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, ARROW value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::OR::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("OR", true);
}
auto Parser::FlatTypes::OR::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::OR::to_string() const -> std::string {
	return ::ISPA_STD::concat("OR {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, OR value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::PIPE_ASSIGN::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("PIPE_ASSIGN", true);
}
auto Parser::FlatTypes::PIPE_ASSIGN::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::PIPE_ASSIGN::to_string() const -> std::string {
	return ::ISPA_STD::concat("PIPE_ASSIGN {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, PIPE_ASSIGN value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::RSHIFT::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("RSHIFT", true);
}
auto Parser::FlatTypes::RSHIFT::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::RSHIFT::to_string() const -> std::string {
	return ::ISPA_STD::concat("RSHIFT {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, RSHIFT value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::RETURN::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("RETURN", true);
}
auto Parser::FlatTypes::RETURN::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::RETURN::to_string() const -> std::string {
	return ::ISPA_STD::concat("RETURN {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, RETURN value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::FROM::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("FROM", true);
}
auto Parser::FlatTypes::FROM::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::FROM::to_string() const -> std::string {
	return ::ISPA_STD::concat("FROM {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, FROM value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::LBRACE::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("LBRACE", true);
}
auto Parser::FlatTypes::LBRACE::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::LBRACE::to_string() const -> std::string {
	return ::ISPA_STD::concat("LBRACE {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, LBRACE value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::RBRACKET::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("RBRACKET", true);
}
auto Parser::FlatTypes::RBRACKET::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::RBRACKET::to_string() const -> std::string {
	return ::ISPA_STD::concat("RBRACKET {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, RBRACKET value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::bitand_tail::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("bitand_tail", false);
	printer.up(false);
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::bitand_tail::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::bitand_tail::to_string() const -> std::string {
	return ::ISPA_STD::concat("bitand_tail {", "value = ", value.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, bitand_tail value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::bitor_tail::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("bitor_tail", false);
	printer.up(false);
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::bitor_tail::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::bitor_tail::to_string() const -> std::string {
	return ::ISPA_STD::concat("bitor_tail {", "value = ", value.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, bitor_tail value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::bitwise_and::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("bitwise_and", false);
	printer.up(false);
	printer.node("first", false);
	printer.up(true);
	first.print(printer);
	printer.down();
	printer.subtree("rest", rest, true);
	printer.down();
}
auto Parser::FlatTypes::bitwise_and::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::bitwise_and::to_string() const -> std::string {
	return ::ISPA_STD::concat("bitwise_and {", "first = ", first.to_string(), ", ", "rest = ", rest, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, bitwise_and value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::bitwise_or::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("bitwise_or", false);
	printer.up(false);
	printer.node("first", false);
	printer.up(true);
	first.print(printer);
	printer.down();
	printer.subtree("rest", rest, true);
	printer.down();
}
auto Parser::FlatTypes::bitwise_or::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::bitwise_or::to_string() const -> std::string {
	return ::ISPA_STD::concat("bitwise_or {", "first = ", first.to_string(), ", ", "rest = ", rest, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, bitwise_or value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::bitwise_xor::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("bitwise_xor", false);
	printer.up(false);
	printer.node("first", false);
	printer.up(true);
	first.print(printer);
	printer.down();
	printer.subtree("rest", rest, true);
	printer.down();
}
auto Parser::FlatTypes::bitwise_xor::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::bitwise_xor::to_string() const -> std::string {
	return ::ISPA_STD::concat("bitwise_xor {", "first = ", first.to_string(), ", ", "rest = ", rest, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, bitwise_xor value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::bitxor_tail::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("bitxor_tail", false);
	printer.up(false);
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::bitxor_tail::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::bitxor_tail::to_string() const -> std::string {
	return ::ISPA_STD::concat("bitxor_tail {", "value = ", value.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, bitxor_tail value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::break_stmt::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("break_stmt", true);
}
auto Parser::FlatTypes::break_stmt::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::break_stmt::to_string() const -> std::string {
	return ::ISPA_STD::concat("break_stmt {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, break_stmt value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::call_arg::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("call_arg", false);
	printer.up(false);
	printer.node_with_value("value", value, true);
	printer.down();
}
auto Parser::FlatTypes::call_arg::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::call_arg::to_string() const -> std::string {
	return ::ISPA_STD::concat("call_arg {", "value = ", value, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, call_arg value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::call_arg_tail::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("call_arg_tail", false);
	printer.up(false);
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::call_arg_tail::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::call_arg_tail::to_string() const -> std::string {
	return ::ISPA_STD::concat("call_arg_tail {", "value = ", value.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, call_arg_tail value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::call_args::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("call_args", false);
	printer.up(false);
	printer.node("first", false);
	printer.up(true);
	first.print(printer);
	printer.down();
	printer.subtree("rest", rest, true);
	printer.down();
}
auto Parser::FlatTypes::call_args::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::call_args::to_string() const -> std::string {
	return ::ISPA_STD::concat("call_args {", "first = ", first.to_string(), ", ", "rest = ", rest, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, call_args value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::call_suffix::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("call_suffix", false);
	printer.up(false);
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::call_suffix::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::call_suffix::to_string() const -> std::string {
	return ::ISPA_STD::concat("call_suffix {", "value = ", value.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, call_suffix value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::comparison::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("comparison", false);
	printer.up(false);
	printer.node("first", false);
	printer.up(true);
	first.print(printer);
	printer.down();
	printer.subtree("rest", rest, true);
	printer.down();
}
auto Parser::FlatTypes::comparison::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::comparison::to_string() const -> std::string {
	return ::ISPA_STD::concat("comparison {", "first = ", first.to_string(), ", ", "rest = ", rest, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, comparison value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::compound_stmt::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("compound_stmt", false);
	printer.up(false);
	printer.node_with_value("value", value, true);
	printer.down();
}
auto Parser::FlatTypes::compound_stmt::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::compound_stmt::to_string() const -> std::string {
	return ::ISPA_STD::concat("compound_stmt {", "value = ", value, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, compound_stmt value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::conditional_tail::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("conditional_tail", false);
	printer.up(false);
	printer.node("condition", false);
	printer.up(true);
	condition.print(printer);
	printer.down();
	printer.node("otherwise", true);
	printer.up(false);
	otherwise.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::conditional_tail::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::conditional_tail::to_string() const -> std::string {
	return ::ISPA_STD::concat("conditional_tail {", "condition = ", condition.to_string(), ", ", "otherwise = ", otherwise.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, conditional_tail value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::conjunction::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("conjunction", false);
	printer.up(false);
	printer.node("first", false);
	printer.up(true);
	first.print(printer);
	printer.down();
	printer.subtree("rest", rest, true);
	printer.down();
}
auto Parser::FlatTypes::conjunction::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::conjunction::to_string() const -> std::string {
	return ::ISPA_STD::concat("conjunction {", "first = ", first.to_string(), ", ", "rest = ", rest, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, conjunction value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::continue_stmt::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("continue_stmt", true);
}
auto Parser::FlatTypes::continue_stmt::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::continue_stmt::to_string() const -> std::string {
	return ::ISPA_STD::concat("continue_stmt {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, continue_stmt value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::def_header::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("def_header", false);
	printer.up(false);
	printer.node_with_value("value", value, true);
	printer.down();
}
auto Parser::FlatTypes::def_header::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::def_header::to_string() const -> std::string {
	return ::ISPA_STD::concat("def_header {", "value = ", value, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, def_header value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::dict_expr::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("dict_expr", false);
	printer.up(false);
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::dict_expr::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::dict_expr::to_string() const -> std::string {
	return ::ISPA_STD::concat("dict_expr {", "value = ", value.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, dict_expr value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::dict_item::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("dict_item", false);
	printer.up(false);
	printer.node("key", false);
	printer.up(true);
	key.print(printer);
	printer.down();
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::dict_item::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::dict_item::to_string() const -> std::string {
	return ::ISPA_STD::concat("dict_item {", "key = ", key.to_string(), ", ", "value = ", value.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, dict_item value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::dict_item_tail::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("dict_item_tail", false);
	printer.up(false);
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::dict_item_tail::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::dict_item_tail::to_string() const -> std::string {
	return ::ISPA_STD::concat("dict_item_tail {", "value = ", value.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, dict_item_tail value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::dict_items::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("dict_items", false);
	printer.up(false);
	printer.node("first", false);
	printer.up(true);
	first.print(printer);
	printer.down();
	printer.subtree("rest", rest, true);
	printer.down();
}
auto Parser::FlatTypes::dict_items::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::dict_items::to_string() const -> std::string {
	return ::ISPA_STD::concat("dict_items {", "first = ", first.to_string(), ", ", "rest = ", rest, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, dict_items value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::disjunction::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("disjunction", false);
	printer.up(false);
	printer.node("first", false);
	printer.up(true);
	first.print(printer);
	printer.down();
	printer.subtree("rest", rest, true);
	printer.down();
}
auto Parser::FlatTypes::disjunction::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::disjunction::to_string() const -> std::string {
	return ::ISPA_STD::concat("disjunction {", "first = ", first.to_string(), ", ", "rest = ", rest, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, disjunction value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::else_clause::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("else_clause", false);
	printer.up(false);
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::else_clause::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::else_clause::to_string() const -> std::string {
	return ::ISPA_STD::concat("else_clause {", "value = ", value.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, else_clause value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::except_handlers::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("except_handlers", false);
	printer.up(false);
	printer.subtree("handlers", handlers, false);
	printer.node("otherwise", false);
	printer.up(true);
	otherwise.print(printer);
	printer.down();
	printer.node("finalizer", true);
	printer.up(false);
	finalizer.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::except_handlers::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::except_handlers::to_string() const -> std::string {
	return ::ISPA_STD::concat("except_handlers {", "handlers = ", handlers, ", ", "otherwise = ", otherwise.to_string(), ", ", "finalizer = ", finalizer.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, except_handlers value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::expr::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("expr", false);
	printer.up(false);
	printer.node("value", false);
	printer.up(true);
	value.print(printer);
	printer.down();
	printer.node("conditional", true);
	printer.up(false);
	conditional.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::expr::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::expr::to_string() const -> std::string {
	return ::ISPA_STD::concat("expr {", "value = ", value.to_string(), ", ", "conditional = ", conditional.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, expr value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::expr_list::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("expr_list", false);
	printer.up(false);
	printer.node("first", false);
	printer.up(true);
	first.print(printer);
	printer.down();
	printer.node("rest", true);
	printer.up(false);
	rest.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::expr_list::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::expr_list::to_string() const -> std::string {
	return ::ISPA_STD::concat("expr_list {", "first = ", first.to_string(), ", ", "rest = ", rest.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, expr_list value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::expr_list_tail::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("expr_list_tail", false);
	printer.up(false);
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::expr_list_tail::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::expr_list_tail::to_string() const -> std::string {
	return ::ISPA_STD::concat("expr_list_tail {", "value = ", value.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, expr_list_tail value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::factor::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("factor", false);
	printer.up(false);
	printer.node_with_value("value", value, true);
	printer.down();
}
auto Parser::FlatTypes::factor::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::factor::to_string() const -> std::string {
	return ::ISPA_STD::concat("factor {", "value = ", value, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, factor value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::finally_clause::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("finally_clause", false);
	printer.up(false);
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::finally_clause::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::finally_clause::to_string() const -> std::string {
	return ::ISPA_STD::concat("finally_clause {", "value = ", value.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, finally_clause value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::indented_block::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("indented_block", false);
	printer.up(false);
	printer.subtree("value", value, true);
	printer.down();
}
auto Parser::FlatTypes::indented_block::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::indented_block::to_string() const -> std::string {
	return ::ISPA_STD::concat("indented_block {", "value = ", value, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, indented_block value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::index_suffix::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("index_suffix", false);
	printer.up(false);
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::index_suffix::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::index_suffix::to_string() const -> std::string {
	return ::ISPA_STD::concat("index_suffix {", "value = ", value.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, index_suffix value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::inversion::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("inversion", false);
	printer.up(false);
	printer.node_with_value("value", value, true);
	printer.down();
}
auto Parser::FlatTypes::inversion::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::inversion::to_string() const -> std::string {
	return ::ISPA_STD::concat("inversion {", "value = ", value, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, inversion value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::is_op::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("is_op", true);
}
auto Parser::FlatTypes::is_op::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::is_op::to_string() const -> std::string {
	return ::ISPA_STD::concat("is_op {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, is_op value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::list_expr::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("list_expr", false);
	printer.up(false);
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::list_expr::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::list_expr::to_string() const -> std::string {
	return ::ISPA_STD::concat("list_expr {", "value = ", value.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, list_expr value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::not_in::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("not_in", true);
}
auto Parser::FlatTypes::not_in::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::not_in::to_string() const -> std::string {
	return ::ISPA_STD::concat("not_in {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, not_in value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::not_inversion::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("not_inversion", false);
	printer.up(false);
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::not_inversion::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::not_inversion::to_string() const -> std::string {
	return ::ISPA_STD::concat("not_inversion {", "value = ", value.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, not_inversion value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::or_tail::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("or_tail", false);
	printer.up(false);
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::or_tail::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::or_tail::to_string() const -> std::string {
	return ::ISPA_STD::concat("or_tail {", "value = ", value.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, or_tail value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::parenthesized_content::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("parenthesized_content", false);
	printer.up(false);
	printer.node("first", false);
	printer.up(true);
	first.print(printer);
	printer.down();
	printer.node("rest", true);
	printer.up(false);
	rest.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::parenthesized_content::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::parenthesized_content::to_string() const -> std::string {
	return ::ISPA_STD::concat("parenthesized_content {", "first = ", first.to_string(), ", ", "rest = ", rest.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, parenthesized_content value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::parenthesized_expr::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("parenthesized_expr", false);
	printer.up(false);
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::parenthesized_expr::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::parenthesized_expr::to_string() const -> std::string {
	return ::ISPA_STD::concat("parenthesized_expr {", "value = ", value.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, parenthesized_expr value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::pass_stmt::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("pass_stmt", true);
}
auto Parser::FlatTypes::pass_stmt::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::pass_stmt::to_string() const -> std::string {
	return ::ISPA_STD::concat("pass_stmt {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, pass_stmt value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::power::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("power", false);
	printer.up(false);
	printer.node("base", false);
	printer.up(true);
	base.print(printer);
	printer.down();
	printer.node("exponent", true);
	printer.up(false);
	exponent.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::power::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::power::to_string() const -> std::string {
	return ::ISPA_STD::concat("power {", "base = ", base.to_string(), ", ", "exponent = ", exponent.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, power value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::power_tail::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("power_tail", false);
	printer.up(false);
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::power_tail::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::power_tail::to_string() const -> std::string {
	return ::ISPA_STD::concat("power_tail {", "value = ", value.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, power_tail value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::primary::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("primary", false);
	printer.up(false);
	printer.node("base", false);
	printer.up(true);
	base.print(printer);
	printer.down();
	printer.subtree("suffixes", suffixes, true);
	printer.down();
}
auto Parser::FlatTypes::primary::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::primary::to_string() const -> std::string {
	return ::ISPA_STD::concat("primary {", "base = ", base.to_string(), ", ", "suffixes = ", suffixes, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, primary value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::shift_expr::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("shift_expr", false);
	printer.up(false);
	printer.node("first", false);
	printer.up(true);
	first.print(printer);
	printer.down();
	printer.subtree("rest", rest, true);
	printer.down();
}
auto Parser::FlatTypes::shift_expr::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::shift_expr::to_string() const -> std::string {
	return ::ISPA_STD::concat("shift_expr {", "first = ", first.to_string(), ", ", "rest = ", rest, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, shift_expr value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::sum::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("sum", false);
	printer.up(false);
	printer.node("first", false);
	printer.up(true);
	first.print(printer);
	printer.down();
	printer.subtree("rest", rest, true);
	printer.down();
}
auto Parser::FlatTypes::sum::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::sum::to_string() const -> std::string {
	return ::ISPA_STD::concat("sum {", "first = ", first.to_string(), ", ", "rest = ", rest, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, sum value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::term::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("term", false);
	printer.up(false);
	printer.node("first", false);
	printer.up(true);
	first.print(printer);
	printer.down();
	printer.subtree("rest", rest, true);
	printer.down();
}
auto Parser::FlatTypes::term::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::term::to_string() const -> std::string {
	return ::ISPA_STD::concat("term {", "first = ", first.to_string(), ", ", "rest = ", rest, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, term value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::try_stmt::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("try_stmt", false);
	printer.up(false);
	printer.node("body", false);
	printer.up(true);
	body.print(printer);
	printer.down();
	printer.node("handlers", true);
	printer.up(false);
	handlers.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::try_stmt::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::try_stmt::to_string() const -> std::string {
	return ::ISPA_STD::concat("try_stmt {", "body = ", body.to_string(), ", ", "handlers = ", handlers.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, try_stmt value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::try_tail::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("try_tail", false);
	printer.up(false);
	printer.node_with_value("value", value, true);
	printer.down();
}
auto Parser::FlatTypes::try_tail::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::try_tail::to_string() const -> std::string {
	return ::ISPA_STD::concat("try_tail {", "value = ", value, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, try_tail value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::tuple_elements::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("tuple_elements", false);
	printer.up(false);
	printer.node("first", false);
	printer.up(true);
	first.print(printer);
	printer.down();
	printer.subtree("rest", rest, true);
	printer.down();
}
auto Parser::FlatTypes::tuple_elements::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::tuple_elements::to_string() const -> std::string {
	return ::ISPA_STD::concat("tuple_elements {", "first = ", first.to_string(), ", ", "rest = ", rest, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, tuple_elements value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::tuple_suffix::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("tuple_suffix", false);
	printer.up(false);
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::tuple_suffix::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::tuple_suffix::to_string() const -> std::string {
	return ::ISPA_STD::concat("tuple_suffix {", "value = ", value.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, tuple_suffix value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::atom::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("atom", false);
	printer.up(false);
	printer.node_with_value("value", value, true);
	printer.down();
}
auto Parser::FlatTypes::atom::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::atom::to_string() const -> std::string {
	return ::ISPA_STD::concat("atom {", "value = ", value, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, atom value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::attribute_suffix::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("attribute_suffix", false);
	printer.up(false);
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::attribute_suffix::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::attribute_suffix::to_string() const -> std::string {
	return ::ISPA_STD::concat("attribute_suffix {", "value = ", value.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, attribute_suffix value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::dotted_name::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("dotted_name", false);
	printer.up(false);
	printer.node("first", false);
	printer.up(true);
	first.print(printer);
	printer.down();
	printer.node("rest", true);
	printer.up(false);
	rest.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::dotted_name::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::dotted_name::to_string() const -> std::string {
	return ::ISPA_STD::concat("dotted_name {", "first = ", first.to_string(), ", ", "rest = ", rest.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, dotted_name value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::except_alias::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("except_alias", false);
	printer.up(false);
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::except_alias::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::except_alias::to_string() const -> std::string {
	return ::ISPA_STD::concat("except_alias {", "value = ", value.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, except_alias value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::global_stmt::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("global_stmt", false);
	printer.up(false);
	printer.node("first", false);
	printer.up(true);
	first.print(printer);
	printer.down();
	printer.node("rest", true);
	printer.up(false);
	rest.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::global_stmt::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::global_stmt::to_string() const -> std::string {
	return ::ISPA_STD::concat("global_stmt {", "first = ", first.to_string(), ", ", "rest = ", rest.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, global_stmt value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::import_alias::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("import_alias", false);
	printer.up(false);
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::import_alias::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::import_alias::to_string() const -> std::string {
	return ::ISPA_STD::concat("import_alias {", "value = ", value.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, import_alias value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::keyword_arg::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("keyword_arg", false);
	printer.up(false);
	printer.node("name", false);
	printer.up(true);
	name.print(printer);
	printer.down();
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::keyword_arg::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::keyword_arg::to_string() const -> std::string {
	return ::ISPA_STD::concat("keyword_arg {", "name = ", name.to_string(), ", ", "value = ", value.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, keyword_arg value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::nonlocal_stmt::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("nonlocal_stmt", false);
	printer.up(false);
	printer.node("first", false);
	printer.up(true);
	first.print(printer);
	printer.down();
	printer.node("rest", true);
	printer.up(false);
	rest.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::nonlocal_stmt::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::nonlocal_stmt::to_string() const -> std::string {
	return ::ISPA_STD::concat("nonlocal_stmt {", "first = ", first.to_string(), ", ", "rest = ", rest.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, nonlocal_stmt value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::sum_tail::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("sum_tail", false);
	printer.up(false);
	printer.node_with_value("op", op, false);
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::sum_tail::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::sum_tail::to_string() const -> std::string {
	return ::ISPA_STD::concat("sum_tail {", "op = ", op, ", ", "value = ", value.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, sum_tail value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::unary_expr::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("unary_expr", false);
	printer.up(false);
	printer.node_with_value("op", op, false);
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::unary_expr::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::unary_expr::to_string() const -> std::string {
	return ::ISPA_STD::concat("unary_expr {", "op = ", op, ", ", "value = ", value.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, unary_expr value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::term_tail::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("term_tail", false);
	printer.up(false);
	printer.node_with_value("op", op, false);
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::term_tail::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::term_tail::to_string() const -> std::string {
	return ::ISPA_STD::concat("term_tail {", "op = ", op, ", ", "value = ", value.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, term_tail value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::assignment_op::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("assignment_op", false);
	printer.up(false);
	printer.node_with_value("value", value, true);
	printer.down();
}
auto Parser::FlatTypes::assignment_op::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::assignment_op::to_string() const -> std::string {
	return ::ISPA_STD::concat("assignment_op {", "value = ", value, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, assignment_op value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::shift_tail::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("shift_tail", false);
	printer.up(false);
	printer.node_with_value("op", op, false);
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::shift_tail::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::shift_tail::to_string() const -> std::string {
	return ::ISPA_STD::concat("shift_tail {", "op = ", op, ", ", "value = ", value.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, shift_tail value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::class_bases::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("class_bases", false);
	printer.up(false);
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::class_bases::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::class_bases::to_string() const -> std::string {
	return ::ISPA_STD::concat("class_bases {", "value = ", value.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, class_bases value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::annotated_assignment::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("annotated_assignment", false);
	printer.up(false);
	printer.node("annotation", false);
	printer.up(true);
	annotation.print(printer);
	printer.down();
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::annotated_assignment::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::annotated_assignment::to_string() const -> std::string {
	return ::ISPA_STD::concat("annotated_assignment {", "annotation = ", annotation.to_string(), ", ", "value = ", value.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, annotated_assignment value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::assert_stmt::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("assert_stmt", false);
	printer.up(false);
	printer.node("condition", false);
	printer.up(true);
	condition.print(printer);
	printer.down();
	printer.node("message", true);
	printer.up(false);
	message.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::assert_stmt::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::assert_stmt::to_string() const -> std::string {
	return ::ISPA_STD::concat("assert_stmt {", "condition = ", condition.to_string(), ", ", "message = ", message.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, assert_stmt value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::elif_clause::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("elif_clause", false);
	printer.up(false);
	printer.node("condition", false);
	printer.up(true);
	condition.print(printer);
	printer.down();
	printer.node("body", true);
	printer.up(false);
	body.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::elif_clause::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::elif_clause::to_string() const -> std::string {
	return ::ISPA_STD::concat("elif_clause {", "condition = ", condition.to_string(), ", ", "body = ", body.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, elif_clause value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::if_stmt::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("if_stmt", false);
	printer.up(false);
	printer.node("condition", false);
	printer.up(true);
	condition.print(printer);
	printer.down();
	printer.node("body", false);
	printer.up(true);
	body.print(printer);
	printer.down();
	printer.subtree("elifs", elifs, false);
	printer.node("otherwise", true);
	printer.up(false);
	otherwise.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::if_stmt::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::if_stmt::to_string() const -> std::string {
	return ::ISPA_STD::concat("if_stmt {", "condition = ", condition.to_string(), ", ", "body = ", body.to_string(), ", ", "elifs = ", elifs, ", ", "otherwise = ", otherwise.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, if_stmt value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::parameter_annotation::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("parameter_annotation", false);
	printer.up(false);
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::parameter_annotation::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::parameter_annotation::to_string() const -> std::string {
	return ::ISPA_STD::concat("parameter_annotation {", "value = ", value.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, parameter_annotation value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::parameter_default::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("parameter_default", false);
	printer.up(false);
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::parameter_default::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::parameter_default::to_string() const -> std::string {
	return ::ISPA_STD::concat("parameter_default {", "value = ", value.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, parameter_default value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::raise_from::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("raise_from", false);
	printer.up(false);
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::raise_from::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::raise_from::to_string() const -> std::string {
	return ::ISPA_STD::concat("raise_from {", "value = ", value.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, raise_from value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::return_annotation::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("return_annotation", false);
	printer.up(false);
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::return_annotation::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::return_annotation::to_string() const -> std::string {
	return ::ISPA_STD::concat("return_annotation {", "value = ", value.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, return_annotation value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::return_stmt::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("return_stmt", false);
	printer.up(false);
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::return_stmt::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::return_stmt::to_string() const -> std::string {
	return ::ISPA_STD::concat("return_stmt {", "value = ", value.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, return_stmt value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::while_stmt::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("while_stmt", false);
	printer.up(false);
	printer.node("condition", false);
	printer.up(true);
	condition.print(printer);
	printer.down();
	printer.node("body", false);
	printer.up(true);
	body.print(printer);
	printer.down();
	printer.node("otherwise", true);
	printer.up(false);
	otherwise.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::while_stmt::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::while_stmt::to_string() const -> std::string {
	return ::ISPA_STD::concat("while_stmt {", "condition = ", condition.to_string(), ", ", "body = ", body.to_string(), ", ", "otherwise = ", otherwise.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, while_stmt value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::compare_op::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("compare_op", false);
	printer.up(false);
	printer.node_with_value("value", value, true);
	printer.down();
}
auto Parser::FlatTypes::compare_op::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::compare_op::to_string() const -> std::string {
	return ::ISPA_STD::concat("compare_op {", "value = ", value, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, compare_op value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::decorator::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("decorator", false);
	printer.up(false);
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::decorator::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::decorator::to_string() const -> std::string {
	return ::ISPA_STD::concat("decorator {", "value = ", value.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, decorator value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::assignment_suffix::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("assignment_suffix", false);
	printer.up(false);
	printer.node_with_value("value", value, true);
	printer.down();
}
auto Parser::FlatTypes::assignment_suffix::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::assignment_suffix::to_string() const -> std::string {
	return ::ISPA_STD::concat("assignment_suffix {", "value = ", value, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, assignment_suffix value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::postfix::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("postfix", false);
	printer.up(false);
	printer.node_with_value("value", value, true);
	printer.down();
}
auto Parser::FlatTypes::postfix::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::postfix::to_string() const -> std::string {
	return ::ISPA_STD::concat("postfix {", "value = ", value, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, postfix value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::relative_module::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("relative_module", false);
	printer.up(false);
	printer.subtree("relative", relative, false);
	printer.node("name", true);
	printer.up(false);
	name.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::relative_module::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::relative_module::to_string() const -> std::string {
	return ::ISPA_STD::concat("relative_module {", "relative = ", relative, ", ", "name = ", name.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, relative_module value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::except_clause::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("except_clause", false);
	printer.up(false);
	printer.node("exception", false);
	printer.up(true);
	exception.print(printer);
	printer.down();
	printer.node("alias", false);
	printer.up(true);
	alias.print(printer);
	printer.down();
	printer.node("body", true);
	printer.up(false);
	body.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::except_clause::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::except_clause::to_string() const -> std::string {
	return ::ISPA_STD::concat("except_clause {", "exception = ", exception.to_string(), ", ", "alias = ", alias.to_string(), ", ", "body = ", body.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, except_clause value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::dotted_as_name::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("dotted_as_name", false);
	printer.up(false);
	printer.node("name", false);
	printer.up(true);
	name.print(printer);
	printer.down();
	printer.node("alias", true);
	printer.up(false);
	alias.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::dotted_as_name::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::dotted_as_name::to_string() const -> std::string {
	return ::ISPA_STD::concat("dotted_as_name {", "name = ", name.to_string(), ", ", "alias = ", alias.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, dotted_as_name value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::import_name_item::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("import_name_item", false);
	printer.up(false);
	printer.node("name", false);
	printer.up(true);
	name.print(printer);
	printer.down();
	printer.node("alias", true);
	printer.up(false);
	alias.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::import_name_item::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::import_name_item::to_string() const -> std::string {
	return ::ISPA_STD::concat("import_name_item {", "name = ", name.to_string(), ", ", "alias = ", alias.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, import_name_item value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::assignment_tail::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("assignment_tail", false);
	printer.up(false);
	printer.node("op", false);
	printer.up(true);
	op.print(printer);
	printer.down();
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::assignment_tail::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::assignment_tail::to_string() const -> std::string {
	return ::ISPA_STD::concat("assignment_tail {", "op = ", op.to_string(), ", ", "value = ", value.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, assignment_tail value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::class_header::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("class_header", false);
	printer.up(false);
	printer.node("name", false);
	printer.up(true);
	name.print(printer);
	printer.down();
	printer.node("bases", false);
	printer.up(true);
	bases.print(printer);
	printer.down();
	printer.node("body", true);
	printer.up(false);
	body.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::class_header::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::class_header::to_string() const -> std::string {
	return ::ISPA_STD::concat("class_header {", "name = ", name.to_string(), ", ", "bases = ", bases.to_string(), ", ", "body = ", body.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, class_header value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::parameter::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("parameter", false);
	printer.up(false);
	printer.node("name", false);
	printer.up(true);
	name.print(printer);
	printer.down();
	printer.node("annotation", false);
	printer.up(true);
	annotation.print(printer);
	printer.down();
	printer.node("def", true);
	printer.up(false);
	def.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::parameter::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::parameter::to_string() const -> std::string {
	return ::ISPA_STD::concat("parameter {", "name = ", name.to_string(), ", ", "annotation = ", annotation.to_string(), ", ", "def = ", def.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, parameter value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::raise_stmt::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("raise_stmt", false);
	printer.up(false);
	printer.node("exception", false);
	printer.up(true);
	exception.print(printer);
	printer.down();
	printer.node("cause", true);
	printer.up(false);
	cause.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::raise_stmt::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::raise_stmt::to_string() const -> std::string {
	return ::ISPA_STD::concat("raise_stmt {", "exception = ", exception.to_string(), ", ", "cause = ", cause.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, raise_stmt value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::compare_tail::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("compare_tail", false);
	printer.up(false);
	printer.node("op", false);
	printer.up(true);
	op.print(printer);
	printer.down();
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::compare_tail::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::compare_tail::to_string() const -> std::string {
	return ::ISPA_STD::concat("compare_tail {", "op = ", op.to_string(), ", ", "value = ", value.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, compare_tail value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::decorators::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("decorators", false);
	printer.up(false);
	printer.subtree("value", value, true);
	printer.down();
}
auto Parser::FlatTypes::decorators::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::decorators::to_string() const -> std::string {
	return ::ISPA_STD::concat("decorators {", "value = ", value, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, decorators value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::assignment_target::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("assignment_target", false);
	printer.up(false);
	printer.node("name", false);
	printer.up(true);
	name.print(printer);
	printer.down();
	printer.subtree("suffixes", suffixes, true);
	printer.down();
}
auto Parser::FlatTypes::assignment_target::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::assignment_target::to_string() const -> std::string {
	return ::ISPA_STD::concat("assignment_target {", "name = ", name.to_string(), ", ", "suffixes = ", suffixes, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, assignment_target value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::dotted_as_names::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("dotted_as_names", false);
	printer.up(false);
	printer.node("first", false);
	printer.up(true);
	first.print(printer);
	printer.down();
	printer.node("rest", true);
	printer.up(false);
	rest.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::dotted_as_names::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::dotted_as_names::to_string() const -> std::string {
	return ::ISPA_STD::concat("dotted_as_names {", "first = ", first.to_string(), ", ", "rest = ", rest.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, dotted_as_names value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::import_names::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("import_names", false);
	printer.up(false);
	printer.node("first", false);
	printer.up(true);
	first.print(printer);
	printer.down();
	printer.node("rest", true);
	printer.up(false);
	rest.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::import_names::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::import_names::to_string() const -> std::string {
	return ::ISPA_STD::concat("import_names {", "first = ", first.to_string(), ", ", "rest = ", rest.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, import_names value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::assignment_value::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("assignment_value", false);
	printer.up(false);
	printer.node_with_value("value", value, true);
	printer.down();
}
auto Parser::FlatTypes::assignment_value::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::assignment_value::to_string() const -> std::string {
	return ::ISPA_STD::concat("assignment_value {", "value = ", value, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, assignment_value value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::parameters::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("parameters", false);
	printer.up(false);
	printer.node("first", false);
	printer.up(true);
	first.print(printer);
	printer.down();
	printer.node("rest", true);
	printer.up(false);
	rest.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::parameters::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::parameters::to_string() const -> std::string {
	return ::ISPA_STD::concat("parameters {", "first = ", first.to_string(), ", ", "rest = ", rest.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, parameters value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::class_def::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("class_def", false);
	printer.up(false);
	printer.node("decorators", false);
	printer.up(true);
	decorators.print(printer);
	printer.down();
	printer.node("definition", true);
	printer.up(false);
	definition.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::class_def::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::class_def::to_string() const -> std::string {
	return ::ISPA_STD::concat("class_def {", "decorators = ", decorators.to_string(), ", ", "definition = ", definition.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, class_def value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::decorated_def::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("decorated_def", false);
	printer.up(false);
	printer.node("decorators", false);
	printer.up(true);
	decorators.print(printer);
	printer.down();
	printer.node("definition", true);
	printer.up(false);
	definition.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::decorated_def::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::decorated_def::to_string() const -> std::string {
	return ::ISPA_STD::concat("decorated_def {", "decorators = ", decorators.to_string(), ", ", "definition = ", definition.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, decorated_def value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::del_stmt::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("del_stmt", false);
	printer.up(false);
	printer.node("first", false);
	printer.up(true);
	first.print(printer);
	printer.down();
	printer.node("rest", true);
	printer.up(false);
	rest.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::del_stmt::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::del_stmt::to_string() const -> std::string {
	return ::ISPA_STD::concat("del_stmt {", "first = ", first.to_string(), ", ", "rest = ", rest.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, del_stmt value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::for_targets::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("for_targets", false);
	printer.up(false);
	printer.node("first", false);
	printer.up(true);
	first.print(printer);
	printer.down();
	printer.node("rest", true);
	printer.up(false);
	rest.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::for_targets::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::for_targets::to_string() const -> std::string {
	return ::ISPA_STD::concat("for_targets {", "first = ", first.to_string(), ", ", "rest = ", rest.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, for_targets value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::with_as::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("with_as", false);
	printer.up(false);
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::with_as::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::with_as::to_string() const -> std::string {
	return ::ISPA_STD::concat("with_as {", "value = ", value.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, with_as value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::import_name::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("import_name", false);
	printer.up(false);
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::import_name::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::import_name::to_string() const -> std::string {
	return ::ISPA_STD::concat("import_name {", "value = ", value.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, import_name value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::parenthesized_imports::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("parenthesized_imports", false);
	printer.up(false);
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::parenthesized_imports::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::parenthesized_imports::to_string() const -> std::string {
	return ::ISPA_STD::concat("parenthesized_imports {", "value = ", value.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, parenthesized_imports value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::expr_stmt::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("expr_stmt", false);
	printer.up(false);
	printer.node("target", false);
	printer.up(true);
	target.print(printer);
	printer.down();
	printer.node("assignment", true);
	printer.up(false);
	assignment.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::expr_stmt::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::expr_stmt::to_string() const -> std::string {
	return ::ISPA_STD::concat("expr_stmt {", "target = ", target.to_string(), ", ", "assignment = ", assignment.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, expr_stmt value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::function_header::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("function_header", false);
	printer.up(false);
	printer.node("async", false);
	printer.up(true);
	async.print(printer);
	printer.down();
	printer.node("name", false);
	printer.up(true);
	name.print(printer);
	printer.down();
	printer.node("params", false);
	printer.up(true);
	params.print(printer);
	printer.down();
	printer.node("returns", false);
	printer.up(true);
	returns.print(printer);
	printer.down();
	printer.node("body", true);
	printer.up(false);
	body.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::function_header::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::function_header::to_string() const -> std::string {
	return ::ISPA_STD::concat("function_header {", "async = ", async.to_string(), ", ", "name = ", name.to_string(), ", ", "params = ", params.to_string(), ", ", "returns = ", returns.to_string(), ", ", "body = ", body.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, function_header value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::for_stmt::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("for_stmt", false);
	printer.up(false);
	printer.node("async", false);
	printer.up(true);
	async.print(printer);
	printer.down();
	printer.node("targets", false);
	printer.up(true);
	targets.print(printer);
	printer.down();
	printer.node("iterable", false);
	printer.up(true);
	iterable.print(printer);
	printer.down();
	printer.node("body", false);
	printer.up(true);
	body.print(printer);
	printer.down();
	printer.node("otherwise", true);
	printer.up(false);
	otherwise.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::for_stmt::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::for_stmt::to_string() const -> std::string {
	return ::ISPA_STD::concat("for_stmt {", "async = ", async.to_string(), ", ", "targets = ", targets.to_string(), ", ", "iterable = ", iterable.to_string(), ", ", "body = ", body.to_string(), ", ", "otherwise = ", otherwise.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, for_stmt value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::with_item::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("with_item", false);
	printer.up(false);
	printer.node("context", false);
	printer.up(true);
	context.print(printer);
	printer.down();
	printer.node("target", true);
	printer.up(false);
	target.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::with_item::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::with_item::to_string() const -> std::string {
	return ::ISPA_STD::concat("with_item {", "context = ", context.to_string(), ", ", "target = ", target.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, with_item value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::import_targets::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("import_targets", false);
	printer.up(false);
	printer.node_with_value("value", value, true);
	printer.down();
}
auto Parser::FlatTypes::import_targets::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::import_targets::to_string() const -> std::string {
	return ::ISPA_STD::concat("import_targets {", "value = ", value, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, import_targets value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::function_def::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("function_def", false);
	printer.up(false);
	printer.node("decorators", false);
	printer.up(true);
	decorators.print(printer);
	printer.down();
	printer.node("definition", true);
	printer.up(false);
	definition.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::function_def::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::function_def::to_string() const -> std::string {
	return ::ISPA_STD::concat("function_def {", "decorators = ", decorators.to_string(), ", ", "definition = ", definition.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, function_def value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::with_items::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("with_items", false);
	printer.up(false);
	printer.node("first", false);
	printer.up(true);
	first.print(printer);
	printer.down();
	printer.node("rest", true);
	printer.up(false);
	rest.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::with_items::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::with_items::to_string() const -> std::string {
	return ::ISPA_STD::concat("with_items {", "first = ", first.to_string(), ", ", "rest = ", rest.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, with_items value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::import_from::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("import_from", false);
	printer.up(false);
	printer.node("module", false);
	printer.up(true);
	module.print(printer);
	printer.down();
	printer.node("names", true);
	printer.up(false);
	names.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::import_from::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::import_from::to_string() const -> std::string {
	return ::ISPA_STD::concat("import_from {", "module = ", module.to_string(), ", ", "names = ", names.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, import_from value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::with_stmt::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("with_stmt", false);
	printer.up(false);
	printer.node("async", false);
	printer.up(true);
	async.print(printer);
	printer.down();
	printer.node("items", false);
	printer.up(true);
	items.print(printer);
	printer.down();
	printer.node("body", true);
	printer.up(false);
	body.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::with_stmt::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::with_stmt::to_string() const -> std::string {
	return ::ISPA_STD::concat("with_stmt {", "async = ", async.to_string(), ", ", "items = ", items.to_string(), ", ", "body = ", body.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, with_stmt value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::import_stmt::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("import_stmt", false);
	printer.up(false);
	printer.node_with_value("value", value, true);
	printer.down();
}
auto Parser::FlatTypes::import_stmt::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::import_stmt::to_string() const -> std::string {
	return ::ISPA_STD::concat("import_stmt {", "value = ", value, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, import_stmt value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::simple_stmt::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("simple_stmt", false);
	printer.up(false);
	printer.node_with_value("value", value, true);
	printer.down();
}
auto Parser::FlatTypes::simple_stmt::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::simple_stmt::to_string() const -> std::string {
	return ::ISPA_STD::concat("simple_stmt {", "value = ", value, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, simple_stmt value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::simple_stmts::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("simple_stmts", false);
	printer.up(false);
	printer.node("first", false);
	printer.up(true);
	first.print(printer);
	printer.down();
	printer.node("rest", true);
	printer.up(false);
	rest.print(printer);
	printer.down();
	printer.down();
}
auto Parser::FlatTypes::simple_stmts::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::simple_stmts::to_string() const -> std::string {
	return ::ISPA_STD::concat("simple_stmts {", "first = ", first.to_string(), ", ", "rest = ", rest.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, simple_stmts value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::block::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("block", false);
	printer.up(false);
	printer.node_with_value("value", value, true);
	printer.down();
}
auto Parser::FlatTypes::block::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::block::to_string() const -> std::string {
	return ::ISPA_STD::concat("block {", "value = ", value, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, block value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::statement::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("statement", false);
	printer.up(false);
	printer.node_with_value("value", value, true);
	printer.down();
}
auto Parser::FlatTypes::statement::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto Parser::FlatTypes::statement::to_string() const -> std::string {
	return ::ISPA_STD::concat("statement {", "value = ", value, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream & os, statement value) -> std::ostream & {
	value.print(os);
	return os;
}
auto Parser::FlatTypes::main::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("main", false);
	printer.up(false);
	printer.subtree("value", value, true);
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
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::DEDENT, Types::DEDENT{}));
			break;
		}
		case 1: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::__WS, Types::__WS{}));
			break;
		}
		case 2: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::NEWLINE, Types::NEWLINE{}));
			break;
		}
		case 3: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::COMMENT, Types::COMMENT{}));
			break;
		}
		case 4: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::PERCENT, Types::PERCENT{}));
			break;
		}
		case 5: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::AMP, Types::AMP{}));
			break;
		}
		case 6: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::LPAREN, Types::LPAREN{}));
			break;
		}
		case 7: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::RPAREN, Types::RPAREN{}));
			break;
		}
		case 8: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::STAR, Types::STAR{}));
			break;
		}
		case 9: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::PLUS, Types::PLUS{}));
			break;
		}
		case 10: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::COMMA, Types::COMMA{}));
			break;
		}
		case 11: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::MINUS, Types::MINUS{}));
			break;
		}
		case 12: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::DOT, Types::DOT{}));
			break;
		}
		case 13: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::SLASH, Types::SLASH{}));
			break;
		}
		case 14: {
			std::string floating = captures.text(2);
			std::string full = captures.text(1);
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::NUMBER, Types::NUMBER{full, floating}));
			break;
		}
		case 15: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::COLON, Types::COLON{}));
			break;
		}
		case 16: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::SEMICOLON, Types::SEMICOLON{}));
			break;
		}
		case 17: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::LT, Types::LT{}));
			break;
		}
		case 18: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::ASSIGN, Types::ASSIGN{}));
			break;
		}
		case 19: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::GT, Types::GT{}));
			break;
		}
		case 20: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::MATMUL, Types::MATMUL{}));
			break;
		}
		case 21: {
			std::string value = captures.text(0);
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::ID, Types::ID{value}));
			break;
		}
		case 22: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::LBRACKET, Types::LBRACKET{}));
			break;
		}
		case 23: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::RBRACKET, Types::RBRACKET{}));
			break;
		}
		case 24: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::CARET, Types::CARET{}));
			break;
		}
		case 25: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::LBRACE, Types::LBRACE{}));
			break;
		}
		case 26: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::PIPE, Types::PIPE{}));
			break;
		}
		case 27: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::RBRACE, Types::RBRACE{}));
			break;
		}
		case 28: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::TILDE, Types::TILDE{}));
			break;
		}
		case 29: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::NE, Types::NE{}));
			break;
		}
		case 30: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::COMMENT, Types::COMMENT{}));
			break;
		}
		case 31: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::PERCENT_ASSIGN, Types::PERCENT_ASSIGN{}));
			break;
		}
		case 32: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::AMP_ASSIGN, Types::AMP_ASSIGN{}));
			break;
		}
		case 33: {
			std::string value = captures.text(3);
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::STRING, Types::STRING{value}));
			break;
		}
		case 34: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::POWER, Types::POWER{}));
			break;
		}
		case 35: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::STAR_ASSIGN, Types::STAR_ASSIGN{}));
			break;
		}
		case 36: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::PLUS_ASSIGN, Types::PLUS_ASSIGN{}));
			break;
		}
		case 37: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::MINUS_ASSIGN, Types::MINUS_ASSIGN{}));
			break;
		}
		case 38: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::ARROW, Types::ARROW{}));
			break;
		}
		case 39: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::FLOOR_DIV, Types::FLOOR_DIV{}));
			break;
		}
		case 40: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::SLASH_ASSIGN, Types::SLASH_ASSIGN{}));
			break;
		}
		case 41: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::LSHIFT, Types::LSHIFT{}));
			break;
		}
		case 42: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::LE, Types::LE{}));
			break;
		}
		case 43: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::EQ, Types::EQ{}));
			break;
		}
		case 44: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::GE, Types::GE{}));
			break;
		}
		case 45: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::RSHIFT, Types::RSHIFT{}));
			break;
		}
		case 46: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::MATMUL_ASSIGN, Types::MATMUL_ASSIGN{}));
			break;
		}
		case 47: {
			std::string value = captures.text(0);
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::ID, Types::ID{value}));
			break;
		}
		case 48: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::CARET_ASSIGN, Types::CARET_ASSIGN{}));
			break;
		}
		case 49: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::AS, Types::AS{}));
			break;
		}
		case 50: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::IF, Types::IF{}));
			break;
		}
		case 51: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::IN, Types::IN{}));
			break;
		}
		case 52: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::IS, Types::IS{}));
			break;
		}
		case 53: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::OR, Types::OR{}));
			break;
		}
		case 54: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::PIPE_ASSIGN, Types::PIPE_ASSIGN{}));
			break;
		}
		case 55: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::POWER_ASSIGN, Types::POWER_ASSIGN{}));
			break;
		}
		case 56: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::FLOOR_DIV_ASSIGN, Types::FLOOR_DIV_ASSIGN{}));
			break;
		}
		case 57: {
			std::string floating = captures.text(2);
			std::string full = captures.text(1);
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::NUMBER, Types::NUMBER{full, floating}));
			break;
		}
		case 58: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::LSHIFT_ASSIGN, Types::LSHIFT_ASSIGN{}));
			break;
		}
		case 59: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::RSHIFT_ASSIGN, Types::RSHIFT_ASSIGN{}));
			break;
		}
		case 60: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::AND, Types::AND{}));
			break;
		}
		case 61: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::DEF, Types::DEF{}));
			break;
		}
		case 62: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::DEL, Types::DEL{}));
			break;
		}
		case 63: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::FOR, Types::FOR{}));
			break;
		}
		case 64: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::NOT, Types::NOT{}));
			break;
		}
		case 65: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::TRY, Types::TRY{}));
			break;
		}
		case 66: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::NONE_V, Types::NONE_V{}));
			break;
		}
		case 67: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::TRUE, Types::TRUE{}));
			break;
		}
		case 68: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::ELIF, Types::ELIF{}));
			break;
		}
		case 69: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::ELSE, Types::ELSE{}));
			break;
		}
		case 70: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::FROM, Types::FROM{}));
			break;
		}
		case 71: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::PASS, Types::PASS{}));
			break;
		}
		case 72: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::WITH, Types::WITH{}));
			break;
		}
		case 73: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::FALSE, Types::FALSE{}));
			break;
		}
		case 74: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::ASYNC, Types::ASYNC{}));
			break;
		}
		case 75: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::BREAK, Types::BREAK{}));
			break;
		}
		case 76: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::CLASS, Types::CLASS{}));
			break;
		}
		case 77: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::RAISE, Types::RAISE{}));
			break;
		}
		case 78: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::WHILE, Types::WHILE{}));
			break;
		}
		case 79: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::ASSERT, Types::ASSERT{}));
			break;
		}
		case 80: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::EXCEPT, Types::EXCEPT{}));
			break;
		}
		case 81: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::GLOBAL, Types::GLOBAL{}));
			break;
		}
		case 82: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::IMPORT, Types::IMPORT{}));
			break;
		}
		case 83: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::RETURN, Types::RETURN{}));
			break;
		}
		case 84: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::FINALLY, Types::FINALLY{}));
			break;
		}
		case 85: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::CONTINUE, Types::CONTINUE{}));
			break;
		}
		case 86: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::NONLOCAL, Types::NONLOCAL{}));
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
::ISPA_STD::DFA::API::CharToClass Parser::Lexer::char_class_table = {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 1, 1, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 4, 0, 5, 0, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 18, 19, 20, 21, 22, 0, 23, 24, 24, 24, 24, 24, 25, 24, 24, 24, 24, 24, 24, 24, 26, 24, 24, 24, 24, 24, 27, 24, 24, 24, 24, 24, 24, 28, 0, 29, 30, 24, 0, 31, 32, 33, 34, 35, 36, 37, 38, 39, 24, 40, 41, 42, 43, 44, 45, 24, 46, 47, 48, 49, 24, 50, 51, 52, 24, 53, 54, 55, 56, 0, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57};
::ISPA_STD::DFA::API::Table<178, 58> Parser::Lexer::dfa_table = {{{380, 1, 2, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 195, 17, 18, 19, 20, 21, 22, 178, 194, 180, 193, 27, 28, 29, 192, 191, 184, 183, 182, 181, 179, 178, 190, 178, 178, 178, 196, 189, 188, 187, 178, 186, 178, 185, 178, 178, 44, 45, 46, 47, 380}, {381, 1, 1, 1, 381, 381, 381, 381, 381, 381, 381, 381, 381, 381, 381, 381, 381, 381, 381, 381, 381, 381, 381, 381, 381, 381, 381, 381, 381, 381, 381, 381, 381, 381, 381, 381, 381, 381, 381, 381, 381, 381, 381, 381, 381, 381, 381, 381, 381, 381, 381, 381, 381, 381, 381, 381, 381, 381}, {382, 1, 2, 2, 382, 382, 382, 382, 382, 382, 382, 382, 382, 382, 382, 382, 382, 382, 382, 382, 382, 382, 382, 382, 382, 382, 382, 382, 382, 382, 382, 382, 382, 382, 382, 382, 382, 382, 382, 382, 382, 382, 382, 382, 382, 382, 382, 382, 382, 382, 382, 382, 382, 382, 382, 382, 382, 382}, {::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, 48, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state}, {49, 49, 383, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 383}, {384, 384, 384, 384, 384, 384, 384, 384, 384, 384, 384, 384, 384, 384, 384, 384, 384, 384, 384, 384, 384, 50, 384, 384, 384, 384, 384, 384, 384, 384, 384, 384, 384, 384, 384, 384, 384, 384, 384, 384, 384, 384, 384, 384, 384, 384, 384, 384, 384, 384, 384, 384, 384, 384, 384, 384, 384, 384}, {385, 385, 385, 385, 385, 385, 385, 385, 385, 385, 385, 385, 385, 385, 385, 385, 385, 385, 385, 385, 385, 51, 385, 385, 385, 385, 385, 385, 385, 385, 385, 385, 385, 385, 385, 385, 385, 385, 385, 385, 385, 385, 385, 385, 385, 385, 385, 385, 385, 385, 385, 385, 385, 385, 385, 385, 385, 385}, {197, 197, 197, 197, 197, 197, 197, 197, 53, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, ::ISPA_STD::DFA::API::null_state}, {386, 386, 386, 386, 386, 386, 386, 386, 386, 386, 386, 386, 386, 386, 386, 386, 386, 386, 386, 386, 386, 386, 386, 386, 386, 386, 386, 386, 386, 386, 386, 386, 386, 386, 386, 386, 386, 386, 386, 386, 386, 386, 386, 386, 386, 386, 386, 386, 386, 386, 386, 386, 386, 386, 386, 386, 386, 386}, {387, 387, 387, 387, 387, 387, 387, 387, 387, 387, 387, 387, 387, 387, 387, 387, 387, 387, 387, 387, 387, 387, 387, 387, 387, 387, 387, 387, 387, 387, 387, 387, 387, 387, 387, 387, 387, 387, 387, 387, 387, 387, 387, 387, 387, 387, 387, 387, 387, 387, 387, 387, 387, 387, 387, 387, 387, 387}, {388, 388, 388, 388, 388, 388, 388, 388, 388, 388, 388, 54, 388, 388, 388, 388, 388, 388, 388, 388, 388, 55, 388, 388, 388, 388, 388, 388, 388, 388, 388, 388, 388, 388, 388, 388, 388, 388, 388, 388, 388, 388, 388, 388, 388, 388, 388, 388, 388, 388, 388, 388, 388, 388, 388, 388, 388, 388}, {389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 56, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389}, {390, 390, 390, 390, 390, 390, 390, 390, 390, 390, 390, 390, 390, 390, 390, 390, 390, 390, 390, 390, 390, 390, 390, 390, 390, 390, 390, 390, 390, 390, 390, 390, 390, 390, 390, 390, 390, 390, 390, 390, 390, 390, 390, 390, 390, 390, 390, 390, 390, 390, 390, 390, 390, 390, 390, 390, 390, 390}, {391, 391, 391, 391, 391, 391, 391, 391, 391, 391, 391, 391, 391, 391, 391, 391, 391, 391, 391, 391, 391, 57, 58, 391, 391, 391, 391, 391, 391, 391, 391, 391, 391, 391, 391, 391, 391, 391, 391, 391, 391, 391, 391, 391, 391, 391, 391, 391, 391, 391, 391, 391, 391, 391, 391, 391, 391, 391}, {392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392}, {393, 393, 393, 393, 393, 393, 393, 393, 393, 393, 393, 393, 393, 393, 393, 393, 59, 393, 393, 393, 393, 60, 393, 393, 393, 393, 393, 393, 393, 393, 393, 393, 393, 393, 393, 393, 393, 393, 393, 393, 393, 393, 393, 393, 393, 393, 393, 393, 393, 393, 393, 393, 393, 393, 393, 393, 393, 393}, {198, 198, 198, 198, 198, 198, 198, 198, 198, 198, 198, 198, 198, 198, 198, 199, 198, 16, 198, 198, 198, 198, 198, 198, 198, 198, 198, 198, 198, 198, 198, 198, 198, 198, 198, 198, 198, 198, 198, 198, 198, 198, 198, 198, 198, 198, 198, 198, 198, 198, 198, 198, 198, 198, 198, 198, 198, 198}, {395, 395, 395, 395, 395, 395, 395, 395, 395, 395, 395, 395, 395, 395, 395, 395, 395, 395, 395, 395, 395, 395, 395, 395, 395, 395, 395, 395, 395, 395, 395, 395, 395, 395, 395, 395, 395, 395, 395, 395, 395, 395, 395, 395, 395, 395, 395, 395, 395, 395, 395, 395, 395, 395, 395, 395, 395, 395}, {396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396}, {397, 397, 397, 397, 397, 397, 397, 397, 397, 397, 397, 397, 397, 397, 397, 397, 397, 397, 397, 397, 62, 63, 397, 397, 397, 397, 397, 397, 397, 397, 397, 397, 397, 397, 397, 397, 397, 397, 397, 397, 397, 397, 397, 397, 397, 397, 397, 397, 397, 397, 397, 397, 397, 397, 397, 397, 397, 397}, {398, 398, 398, 398, 398, 398, 398, 398, 398, 398, 398, 398, 398, 398, 398, 398, 398, 398, 398, 398, 398, 64, 398, 398, 398, 398, 398, 398, 398, 398, 398, 398, 398, 398, 398, 398, 398, 398, 398, 398, 398, 398, 398, 398, 398, 398, 398, 398, 398, 398, 398, 398, 398, 398, 398, 398, 398, 398}, {399, 399, 399, 399, 399, 399, 399, 399, 399, 399, 399, 399, 399, 399, 399, 399, 399, 399, 399, 399, 399, 65, 66, 399, 399, 399, 399, 399, 399, 399, 399, 399, 399, 399, 399, 399, 399, 399, 399, 399, 399, 399, 399, 399, 399, 399, 399, 399, 399, 399, 399, 399, 399, 399, 399, 399, 399, 399}, {400, 400, 400, 400, 400, 400, 400, 400, 400, 400, 400, 400, 400, 400, 400, 400, 400, 400, 400, 400, 400, 67, 400, 400, 400, 400, 400, 400, 400, 400, 400, 400, 400, 400, 400, 400, 400, 400, 400, 400, 400, 400, 400, 400, 400, 400, 400, 400, 400, 400, 400, 400, 400, 400, 400, 400, 400, 400}, {200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 68, 200, 200, 200, 200, 200, 200, 68, 68, 68, 68, 200, 200, 200, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 200, 200, 200, 200, 200}, {202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 203, 202, 202, 202, 202, 202, 202, 203, 203, 203, 203, 202, 202, 202, 69, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 202, 202, 202, 202, 202}, {205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 203, 205, 205, 205, 205, 205, 205, 203, 203, 203, 203, 205, 205, 205, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 70, 203, 203, 203, 203, 203, 203, 203, 203, 205, 205, 205, 205, 205}, {207, 207, 207, 207, 207, 207, 207, 207, 207, 207, 207, 207, 207, 207, 207, 207, 207, 203, 207, 207, 207, 207, 207, 207, 203, 203, 203, 203, 207, 207, 207, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 71, 203, 203, 203, 203, 203, 203, 207, 207, 207, 207, 207}, {402, 402, 402, 402, 402, 402, 402, 402, 402, 402, 402, 402, 402, 402, 402, 402, 402, 402, 402, 402, 402, 402, 402, 402, 402, 402, 402, 402, 402, 402, 402, 402, 402, 402, 402, 402, 402, 402, 402, 402, 402, 402, 402, 402, 402, 402, 402, 402, 402, 402, 402, 402, 402, 402, 402, 402, 402, 402}, {403, 403, 403, 403, 403, 403, 403, 403, 403, 403, 403, 403, 403, 403, 403, 403, 403, 403, 403, 403, 403, 403, 403, 403, 403, 403, 403, 403, 403, 403, 403, 403, 403, 403, 403, 403, 403, 403, 403, 403, 403, 403, 403, 403, 403, 403, 403, 403, 403, 403, 403, 403, 403, 403, 403, 403, 403, 403}, {404, 404, 404, 404, 404, 404, 404, 404, 404, 404, 404, 404, 404, 404, 404, 404, 404, 404, 404, 404, 404, 72, 404, 404, 404, 404, 404, 404, 404, 404, 404, 404, 404, 404, 404, 404, 404, 404, 404, 404, 404, 404, 404, 404, 404, 404, 404, 404, 404, 404, 404, 404, 404, 404, 404, 404, 404, 404}, {209, 209, 209, 209, 209, 209, 209, 209, 209, 209, 209, 209, 209, 209, 209, 209, 209, 203, 209, 209, 209, 209, 209, 209, 203, 203, 203, 203, 209, 209, 209, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 73, 203, 203, 203, 74, 203, 203, 203, 203, 203, 209, 209, 209, 209, 209}, {211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 203, 211, 211, 211, 211, 211, 211, 203, 203, 203, 203, 211, 211, 211, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 75, 203, 203, 203, 203, 203, 203, 211, 211, 211, 211, 211}, {213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 203, 213, 213, 213, 213, 213, 213, 203, 203, 203, 203, 213, 213, 213, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 76, 203, 203, 77, 203, 203, 203, 203, 203, 203, 203, 203, 213, 213, 213, 213, 213}, {215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 203, 215, 215, 215, 215, 215, 215, 203, 203, 203, 203, 215, 215, 215, 203, 203, 203, 203, 78, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 215, 215, 215, 215, 215}, {217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 203, 217, 217, 217, 217, 217, 217, 203, 203, 203, 203, 217, 217, 217, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 79, 203, 203, 203, 203, 203, 203, 203, 203, 203, 80, 203, 217, 217, 217, 217, 217}, {219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 203, 219, 219, 219, 219, 219, 219, 203, 203, 203, 203, 219, 219, 219, 203, 203, 203, 203, 203, 203, 203, 203, 81, 203, 203, 203, 203, 82, 203, 83, 203, 203, 203, 203, 203, 203, 219, 219, 219, 219, 219}, {221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 203, 221, 221, 221, 221, 221, 221, 203, 203, 203, 203, 221, 221, 221, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 84, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 221, 221, 221, 221, 221}, {223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 203, 223, 223, 223, 223, 223, 223, 203, 203, 203, 203, 223, 223, 223, 203, 203, 203, 203, 203, 85, 203, 203, 203, 203, 203, 86, 87, 203, 203, 203, 88, 203, 203, 203, 203, 203, 223, 223, 223, 223, 223}, {225, 225, 225, 225, 225, 225, 225, 225, 225, 225, 225, 225, 225, 225, 225, 225, 225, 203, 225, 225, 225, 225, 225, 225, 203, 203, 203, 203, 225, 225, 225, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 89, 203, 203, 203, 203, 203, 203, 203, 203, 225, 225, 225, 225, 225}, {227, 227, 227, 227, 227, 227, 227, 227, 227, 227, 227, 227, 227, 227, 227, 227, 227, 203, 227, 227, 227, 227, 227, 227, 203, 203, 203, 203, 227, 227, 227, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 90, 203, 203, 203, 203, 203, 203, 227, 227, 227, 227, 227}, {229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 203, 229, 229, 229, 229, 229, 229, 203, 203, 203, 203, 229, 229, 229, 91, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 229, 229, 229, 229, 229}, {231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 203, 231, 231, 231, 231, 231, 231, 203, 203, 203, 203, 231, 231, 231, 92, 203, 203, 203, 93, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 231, 231, 231, 231, 231}, {233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 203, 233, 233, 233, 233, 233, 233, 203, 203, 203, 203, 233, 233, 233, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 94, 203, 203, 203, 203, 203, 203, 233, 233, 233, 233, 233}, {235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 203, 235, 235, 235, 235, 235, 235, 203, 203, 203, 203, 235, 235, 235, 203, 203, 203, 203, 203, 203, 203, 95, 96, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 235, 235, 235, 235, 235}, {405, 405, 405, 405, 405, 405, 405, 405, 405, 405, 405, 405, 405, 405, 405, 405, 405, 405, 405, 405, 405, 405, 405, 405, 405, 405, 405, 405, 405, 405, 405, 405, 405, 405, 405, 405, 405, 405, 405, 405, 405, 405, 405, 405, 405, 405, 405, 405, 405, 405, 405, 405, 405, 405, 405, 405, 405, 405}, {406, 406, 406, 406, 406, 406, 406, 406, 406, 406, 406, 406, 406, 406, 406, 406, 406, 406, 406, 406, 406, 97, 406, 406, 406, 406, 406, 406, 406, 406, 406, 406, 406, 406, 406, 406, 406, 406, 406, 406, 406, 406, 406, 406, 406, 406, 406, 406, 406, 406, 406, 406, 406, 406, 406, 406, 406, 406}, {407, 407, 407, 407, 407, 407, 407, 407, 407, 407, 407, 407, 407, 407, 407, 407, 407, 407, 407, 407, 407, 407, 407, 407, 407, 407, 407, 407, 407, 407, 407, 407, 407, 407, 407, 407, 407, 407, 407, 407, 407, 407, 407, 407, 407, 407, 407, 407, 407, 407, 407, 407, 407, 407, 407, 407, 407, 407}, {408, 408, 408, 408, 408, 408, 408, 408, 408, 408, 408, 408, 408, 408, 408, 408, 408, 408, 408, 408, 408, 408, 408, 408, 408, 408, 408, 408, 408, 408, 408, 408, 408, 408, 408, 408, 408, 408, 408, 408, 408, 408, 408, 408, 408, 408, 408, 408, 408, 408, 408, 408, 408, 408, 408, 408, 408, 408}, {409, 409, 409, 409, 409, 409, 409, 409, 409, 409, 409, 409, 409, 409, 409, 409, 409, 409, 409, 409, 409, 409, 409, 409, 409, 409, 409, 409, 409, 409, 409, 409, 409, 409, 409, 409, 409, 409, 409, 409, 409, 409, 409, 409, 409, 409, 409, 409, 409, 409, 409, 409, 409, 409, 409, 409, 409, 409}, {49, 49, 410, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 410}, {411, 411, 411, 411, 411, 411, 411, 411, 411, 411, 411, 411, 411, 411, 411, 411, 411, 411, 411, 411, 411, 411, 411, 411, 411, 411, 411, 411, 411, 411, 411, 411, 411, 411, 411, 411, 411, 411, 411, 411, 411, 411, 411, 411, 411, 411, 411, 411, 411, 411, 411, 411, 411, 411, 411, 411, 411, 411}, {412, 412, 412, 412, 412, 412, 412, 412, 412, 412, 412, 412, 412, 412, 412, 412, 412, 412, 412, 412, 412, 412, 412, 412, 412, 412, 412, 412, 412, 412, 412, 412, 412, 412, 412, 412, 412, 412, 412, 412, 412, 412, 412, 412, 412, 412, 412, 412, 412, 412, 412, 412, 412, 412, 412, 412, 412, 412}, {52, 52, 52, 52, 52, 52, 52, 52, 236, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, ::ISPA_STD::DFA::API::null_state}, {413, 413, 413, 413, 413, 413, 413, 413, 413, 413, 413, 413, 413, 413, 413, 413, 413, 413, 413, 413, 413, 413, 413, 413, 413, 413, 413, 413, 413, 413, 413, 413, 413, 413, 413, 413, 413, 413, 413, 413, 413, 413, 413, 413, 413, 413, 413, 413, 413, 413, 413, 413, 413, 413, 413, 413, 413, 413}, {414, 414, 414, 414, 414, 414, 414, 414, 414, 414, 414, 414, 414, 414, 414, 414, 414, 414, 414, 414, 414, 98, 414, 414, 414, 414, 414, 414, 414, 414, 414, 414, 414, 414, 414, 414, 414, 414, 414, 414, 414, 414, 414, 414, 414, 414, 414, 414, 414, 414, 414, 414, 414, 414, 414, 414, 414, 414}, {415, 415, 415, 415, 415, 415, 415, 415, 415, 415, 415, 415, 415, 415, 415, 415, 415, 415, 415, 415, 415, 415, 415, 415, 415, 415, 415, 415, 415, 415, 415, 415, 415, 415, 415, 415, 415, 415, 415, 415, 415, 415, 415, 415, 415, 415, 415, 415, 415, 415, 415, 415, 415, 415, 415, 415, 415, 415}, {416, 416, 416, 416, 416, 416, 416, 416, 416, 416, 416, 416, 416, 416, 416, 416, 416, 416, 416, 416, 416, 416, 416, 416, 416, 416, 416, 416, 416, 416, 416, 416, 416, 416, 416, 416, 416, 416, 416, 416, 416, 416, 416, 416, 416, 416, 416, 416, 416, 416, 416, 416, 416, 416, 416, 416, 416, 416}, {417, 417, 417, 417, 417, 417, 417, 417, 417, 417, 417, 417, 417, 417, 417, 417, 417, 417, 417, 417, 417, 417, 417, 417, 417, 417, 417, 417, 417, 417, 417, 417, 417, 417, 417, 417, 417, 417, 417, 417, 417, 417, 417, 417, 417, 417, 417, 417, 417, 417, 417, 417, 417, 417, 417, 417, 417, 417}, {418, 418, 418, 418, 418, 418, 418, 418, 418, 418, 418, 418, 418, 418, 418, 418, 418, 418, 418, 418, 418, 418, 418, 418, 418, 418, 418, 418, 418, 418, 418, 418, 418, 418, 418, 418, 418, 418, 418, 418, 418, 418, 418, 418, 418, 418, 418, 418, 418, 418, 418, 418, 418, 418, 418, 418, 418, 418}, {419, 419, 419, 419, 419, 419, 419, 419, 419, 419, 419, 419, 419, 419, 419, 419, 419, 419, 419, 419, 419, 99, 419, 419, 419, 419, 419, 419, 419, 419, 419, 419, 419, 419, 419, 419, 419, 419, 419, 419, 419, 419, 419, 419, 419, 419, 419, 419, 419, 419, 419, 419, 419, 419, 419, 419, 419, 419}, {420, 420, 420, 420, 420, 420, 420, 420, 420, 420, 420, 420, 420, 420, 420, 420, 420, 420, 420, 420, 420, 420, 420, 420, 420, 420, 420, 420, 420, 420, 420, 420, 420, 420, 420, 420, 420, 420, 420, 420, 420, 420, 420, 420, 420, 420, 420, 420, 420, 420, 420, 420, 420, 420, 420, 420, 420, 420}, {::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, 237, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state}, {421, 421, 421, 421, 421, 421, 421, 421, 421, 421, 421, 421, 421, 421, 421, 421, 421, 421, 421, 421, 421, 101, 421, 421, 421, 421, 421, 421, 421, 421, 421, 421, 421, 421, 421, 421, 421, 421, 421, 421, 421, 421, 421, 421, 421, 421, 421, 421, 421, 421, 421, 421, 421, 421, 421, 421, 421, 421}, {422, 422, 422, 422, 422, 422, 422, 422, 422, 422, 422, 422, 422, 422, 422, 422, 422, 422, 422, 422, 422, 422, 422, 422, 422, 422, 422, 422, 422, 422, 422, 422, 422, 422, 422, 422, 422, 422, 422, 422, 422, 422, 422, 422, 422, 422, 422, 422, 422, 422, 422, 422, 422, 422, 422, 422, 422, 422}, {423, 423, 423, 423, 423, 423, 423, 423, 423, 423, 423, 423, 423, 423, 423, 423, 423, 423, 423, 423, 423, 423, 423, 423, 423, 423, 423, 423, 423, 423, 423, 423, 423, 423, 423, 423, 423, 423, 423, 423, 423, 423, 423, 423, 423, 423, 423, 423, 423, 423, 423, 423, 423, 423, 423, 423, 423, 423}, {424, 424, 424, 424, 424, 424, 424, 424, 424, 424, 424, 424, 424, 424, 424, 424, 424, 424, 424, 424, 424, 424, 424, 424, 424, 424, 424, 424, 424, 424, 424, 424, 424, 424, 424, 424, 424, 424, 424, 424, 424, 424, 424, 424, 424, 424, 424, 424, 424, 424, 424, 424, 424, 424, 424, 424, 424, 424}, {425, 425, 425, 425, 425, 425, 425, 425, 425, 425, 425, 425, 425, 425, 425, 425, 425, 425, 425, 425, 425, 102, 425, 425, 425, 425, 425, 425, 425, 425, 425, 425, 425, 425, 425, 425, 425, 425, 425, 425, 425, 425, 425, 425, 425, 425, 425, 425, 425, 425, 425, 425, 425, 425, 425, 425, 425, 425}, {426, 426, 426, 426, 426, 426, 426, 426, 426, 426, 426, 426, 426, 426, 426, 426, 426, 426, 426, 426, 426, 426, 426, 426, 426, 426, 426, 426, 426, 426, 426, 426, 426, 426, 426, 426, 426, 426, 426, 426, 426, 426, 426, 426, 426, 426, 426, 426, 426, 426, 426, 426, 426, 426, 426, 426, 426, 426}, {238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 68, 238, 238, 238, 238, 238, 238, 68, 68, 68, 68, 238, 238, 238, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 238, 238, 238, 238, 238}, {240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 203, 240, 240, 240, 240, 240, 240, 203, 203, 203, 203, 240, 240, 240, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 103, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 240, 240, 240, 240, 240}, {242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 203, 242, 242, 242, 242, 242, 242, 203, 203, 203, 203, 242, 242, 242, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 104, 203, 203, 203, 203, 203, 203, 203, 203, 203, 242, 242, 242, 242, 242}, {244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 203, 244, 244, 244, 244, 244, 244, 203, 203, 203, 203, 244, 244, 244, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 105, 203, 203, 203, 244, 244, 244, 244, 244}, {428, 428, 428, 428, 428, 428, 428, 428, 428, 428, 428, 428, 428, 428, 428, 428, 428, 428, 428, 428, 428, 428, 428, 428, 428, 428, 428, 428, 428, 428, 428, 428, 428, 428, 428, 428, 428, 428, 428, 428, 428, 428, 428, 428, 428, 428, 428, 428, 428, 428, 428, 428, 428, 428, 428, 428, 428, 428}, {246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 203, 246, 246, 246, 246, 246, 246, 203, 203, 203, 203, 246, 246, 246, 203, 203, 203, 106, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 246, 246, 246, 246, 246}, {429, 429, 429, 429, 429, 429, 429, 429, 429, 429, 429, 429, 429, 429, 429, 429, 429, 203, 429, 429, 429, 429, 429, 429, 203, 203, 203, 203, 429, 429, 429, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 107, 203, 203, 203, 203, 108, 429, 429, 429, 429, 429}, {248, 248, 248, 248, 248, 248, 248, 248, 248, 248, 248, 248, 248, 248, 248, 248, 248, 203, 248, 248, 248, 248, 248, 248, 203, 203, 203, 203, 248, 248, 248, 203, 203, 203, 203, 109, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 248, 248, 248, 248, 248}, {250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 203, 250, 250, 250, 250, 250, 250, 203, 203, 203, 203, 250, 250, 250, 110, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 250, 250, 250, 250, 250}, {252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 203, 252, 252, 252, 252, 252, 252, 203, 203, 203, 203, 252, 252, 252, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 111, 203, 203, 203, 203, 203, 203, 203, 203, 203, 252, 252, 252, 252, 252}, {254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 203, 254, 254, 254, 254, 254, 254, 203, 203, 203, 203, 254, 254, 254, 203, 203, 203, 203, 203, 112, 203, 203, 203, 203, 113, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 254, 254, 254, 254, 254}, {256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 203, 256, 256, 256, 256, 256, 256, 203, 203, 203, 203, 256, 256, 256, 203, 203, 203, 203, 203, 203, 203, 203, 114, 203, 203, 203, 203, 203, 203, 203, 115, 203, 203, 203, 203, 203, 256, 256, 256, 256, 256}, {258, 258, 258, 258, 258, 258, 258, 258, 258, 258, 258, 258, 258, 258, 258, 258, 258, 203, 258, 258, 258, 258, 258, 258, 203, 203, 203, 203, 258, 258, 258, 203, 203, 116, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 258, 258, 258, 258, 258}, {260, 260, 260, 260, 260, 260, 260, 260, 260, 260, 260, 260, 260, 260, 260, 260, 260, 203, 260, 260, 260, 260, 260, 260, 203, 203, 203, 203, 260, 260, 260, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 117, 203, 203, 203, 203, 203, 203, 203, 203, 203, 260, 260, 260, 260, 260}, {262, 262, 262, 262, 262, 262, 262, 262, 262, 262, 262, 262, 262, 262, 262, 262, 262, 203, 262, 262, 262, 262, 262, 262, 203, 203, 203, 203, 262, 262, 262, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 118, 203, 203, 203, 203, 203, 203, 262, 262, 262, 262, 262}, {264, 264, 264, 264, 264, 264, 264, 264, 264, 264, 264, 264, 264, 264, 264, 264, 264, 203, 264, 264, 264, 264, 264, 264, 203, 203, 203, 203, 264, 264, 264, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 119, 203, 203, 203, 203, 203, 203, 203, 203, 264, 264, 264, 264, 264}, {266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 266, 203, 266, 266, 266, 266, 266, 266, 203, 203, 203, 203, 266, 266, 266, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 120, 203, 203, 203, 203, 203, 203, 203, 203, 266, 266, 266, 266, 266}, {430, 430, 430, 430, 430, 430, 430, 430, 430, 430, 430, 430, 430, 430, 430, 430, 430, 203, 430, 430, 430, 430, 430, 430, 203, 203, 203, 203, 430, 430, 430, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 430, 430, 430, 430, 430}, {268, 268, 268, 268, 268, 268, 268, 268, 268, 268, 268, 268, 268, 268, 268, 268, 268, 203, 268, 268, 268, 268, 268, 268, 203, 203, 203, 203, 268, 268, 268, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 121, 203, 203, 203, 203, 203, 203, 203, 268, 268, 268, 268, 268}, {431, 431, 431, 431, 431, 431, 431, 431, 431, 431, 431, 431, 431, 431, 431, 431, 431, 203, 431, 431, 431, 431, 431, 431, 203, 203, 203, 203, 431, 431, 431, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 431, 431, 431, 431, 431}, {432, 432, 432, 432, 432, 432, 432, 432, 432, 432, 432, 432, 432, 432, 432, 432, 432, 203, 432, 432, 432, 432, 432, 432, 203, 203, 203, 203, 432, 432, 432, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 432, 432, 432, 432, 432}, {270, 270, 270, 270, 270, 270, 270, 270, 270, 270, 270, 270, 270, 270, 270, 270, 270, 203, 270, 270, 270, 270, 270, 270, 203, 203, 203, 203, 270, 270, 270, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 122, 203, 203, 203, 203, 123, 203, 203, 203, 203, 270, 270, 270, 270, 270}, {433, 433, 433, 433, 433, 433, 433, 433, 433, 433, 433, 433, 433, 433, 433, 433, 433, 203, 433, 433, 433, 433, 433, 433, 203, 203, 203, 203, 433, 433, 433, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 433, 433, 433, 433, 433}, {272, 272, 272, 272, 272, 272, 272, 272, 272, 272, 272, 272, 272, 272, 272, 272, 272, 203, 272, 272, 272, 272, 272, 272, 203, 203, 203, 203, 272, 272, 272, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 124, 203, 203, 203, 203, 203, 272, 272, 272, 272, 272}, {274, 274, 274, 274, 274, 274, 274, 274, 274, 274, 274, 274, 274, 274, 274, 274, 274, 203, 274, 274, 274, 274, 274, 274, 203, 203, 203, 203, 274, 274, 274, 203, 203, 203, 203, 203, 203, 203, 203, 125, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 274, 274, 274, 274, 274}, {276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 276, 203, 276, 276, 276, 276, 276, 276, 203, 203, 203, 203, 276, 276, 276, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 126, 203, 203, 203, 203, 276, 276, 276, 276, 276}, {278, 278, 278, 278, 278, 278, 278, 278, 278, 278, 278, 278, 278, 278, 278, 278, 278, 203, 278, 278, 278, 278, 278, 278, 203, 203, 203, 203, 278, 278, 278, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 127, 278, 278, 278, 278, 278}, {280, 280, 280, 280, 280, 280, 280, 280, 280, 280, 280, 280, 280, 280, 280, 280, 280, 203, 280, 280, 280, 280, 280, 280, 203, 203, 203, 203, 280, 280, 280, 203, 203, 203, 203, 203, 203, 203, 203, 128, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 280, 280, 280, 280, 280}, {282, 282, 282, 282, 282, 282, 282, 282, 282, 282, 282, 282, 282, 282, 282, 282, 282, 203, 282, 282, 282, 282, 282, 282, 203, 203, 203, 203, 282, 282, 282, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 129, 203, 203, 203, 203, 282, 282, 282, 282, 282}, {434, 434, 434, 434, 434, 434, 434, 434, 434, 434, 434, 434, 434, 434, 434, 434, 434, 434, 434, 434, 434, 434, 434, 434, 434, 434, 434, 434, 434, 434, 434, 434, 434, 434, 434, 434, 434, 434, 434, 434, 434, 434, 434, 434, 434, 434, 434, 434, 434, 434, 434, 434, 434, 434, 434, 434, 434, 434}, {435, 435, 435, 435, 435, 435, 435, 435, 435, 435, 435, 435, 435, 435, 435, 435, 435, 435, 435, 435, 435, 435, 435, 435, 435, 435, 435, 435, 435, 435, 435, 435, 435, 435, 435, 435, 435, 435, 435, 435, 435, 435, 435, 435, 435, 435, 435, 435, 435, 435, 435, 435, 435, 435, 435, 435, 435, 435}, {436, 436, 436, 436, 436, 436, 436, 436, 436, 436, 436, 436, 436, 436, 436, 436, 436, 436, 436, 436, 436, 436, 436, 436, 436, 436, 436, 436, 436, 436, 436, 436, 436, 436, 436, 436, 436, 436, 436, 436, 436, 436, 436, 436, 436, 436, 436, 436, 436, 436, 436, 436, 436, 436, 436, 436, 436, 436}, {283, 283, 283, 283, 283, 283, 283, 283, 283, 283, 283, 283, 283, 283, 283, 283, 283, 100, 283, 283, 283, 283, 283, 283, 283, 283, 283, 283, 283, 283, 283, 283, 283, 283, 283, 283, 283, 283, 283, 283, 283, 283, 283, 283, 283, 283, 283, 283, 283, 283, 283, 283, 283, 283, 283, 283, 283, 283}, {438, 438, 438, 438, 438, 438, 438, 438, 438, 438, 438, 438, 438, 438, 438, 438, 438, 438, 438, 438, 438, 438, 438, 438, 438, 438, 438, 438, 438, 438, 438, 438, 438, 438, 438, 438, 438, 438, 438, 438, 438, 438, 438, 438, 438, 438, 438, 438, 438, 438, 438, 438, 438, 438, 438, 438, 438, 438}, {439, 439, 439, 439, 439, 439, 439, 439, 439, 439, 439, 439, 439, 439, 439, 439, 439, 439, 439, 439, 439, 439, 439, 439, 439, 439, 439, 439, 439, 439, 439, 439, 439, 439, 439, 439, 439, 439, 439, 439, 439, 439, 439, 439, 439, 439, 439, 439, 439, 439, 439, 439, 439, 439, 439, 439, 439, 439}, {285, 285, 285, 285, 285, 285, 285, 285, 285, 285, 285, 285, 285, 285, 285, 285, 285, 203, 285, 285, 285, 285, 285, 285, 203, 203, 203, 203, 285, 285, 285, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 130, 203, 203, 203, 203, 203, 285, 285, 285, 285, 285}, {287, 287, 287, 287, 287, 287, 287, 287, 287, 287, 287, 287, 287, 287, 287, 287, 287, 203, 287, 287, 287, 287, 287, 287, 203, 203, 203, 203, 287, 287, 287, 203, 203, 203, 203, 131, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 287, 287, 287, 287, 287}, {289, 289, 289, 289, 289, 289, 289, 289, 289, 289, 289, 289, 289, 289, 289, 289, 289, 203, 289, 289, 289, 289, 289, 289, 203, 203, 203, 203, 289, 289, 289, 203, 203, 203, 203, 132, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 289, 289, 289, 289, 289}, {440, 440, 440, 440, 440, 440, 440, 440, 440, 440, 440, 440, 440, 440, 440, 440, 440, 203, 440, 440, 440, 440, 440, 440, 203, 203, 203, 203, 440, 440, 440, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 440, 440, 440, 440, 440}, {291, 291, 291, 291, 291, 291, 291, 291, 291, 291, 291, 291, 291, 291, 291, 291, 291, 203, 291, 291, 291, 291, 291, 291, 203, 203, 203, 203, 291, 291, 291, 203, 203, 203, 203, 133, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 291, 291, 291, 291, 291}, {293, 293, 293, 293, 293, 293, 293, 293, 293, 293, 293, 293, 293, 293, 293, 293, 293, 203, 293, 293, 293, 293, 293, 293, 203, 203, 203, 203, 293, 293, 293, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 134, 203, 203, 203, 203, 203, 203, 203, 203, 203, 293, 293, 293, 293, 293}, {295, 295, 295, 295, 295, 295, 295, 295, 295, 295, 295, 295, 295, 295, 295, 295, 295, 203, 295, 295, 295, 295, 295, 295, 203, 203, 203, 203, 295, 295, 295, 135, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 295, 295, 295, 295, 295}, {297, 297, 297, 297, 297, 297, 297, 297, 297, 297, 297, 297, 297, 297, 297, 297, 297, 203, 297, 297, 297, 297, 297, 297, 203, 203, 203, 203, 297, 297, 297, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 136, 203, 203, 203, 203, 203, 297, 297, 297, 297, 297}, {299, 299, 299, 299, 299, 299, 299, 299, 299, 299, 299, 299, 299, 299, 299, 299, 299, 203, 299, 299, 299, 299, 299, 299, 203, 203, 203, 203, 299, 299, 299, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 137, 203, 203, 203, 203, 299, 299, 299, 299, 299}, {441, 441, 441, 441, 441, 441, 441, 441, 441, 441, 441, 441, 441, 441, 441, 441, 441, 203, 441, 441, 441, 441, 441, 441, 203, 203, 203, 203, 441, 441, 441, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 441, 441, 441, 441, 441}, {442, 442, 442, 442, 442, 442, 442, 442, 442, 442, 442, 442, 442, 442, 442, 442, 442, 203, 442, 442, 442, 442, 442, 442, 203, 203, 203, 203, 442, 442, 442, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 442, 442, 442, 442, 442}, {301, 301, 301, 301, 301, 301, 301, 301, 301, 301, 301, 301, 301, 301, 301, 301, 301, 203, 301, 301, 301, 301, 301, 301, 203, 203, 203, 203, 301, 301, 301, 203, 203, 203, 203, 203, 138, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 301, 301, 301, 301, 301}, {303, 303, 303, 303, 303, 303, 303, 303, 303, 303, 303, 303, 303, 303, 303, 303, 303, 203, 303, 303, 303, 303, 303, 303, 203, 203, 203, 203, 303, 303, 303, 203, 203, 203, 203, 139, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 303, 303, 303, 303, 303}, {305, 305, 305, 305, 305, 305, 305, 305, 305, 305, 305, 305, 305, 305, 305, 305, 305, 203, 305, 305, 305, 305, 305, 305, 203, 203, 203, 203, 305, 305, 305, 203, 203, 203, 203, 140, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 305, 305, 305, 305, 305}, {307, 307, 307, 307, 307, 307, 307, 307, 307, 307, 307, 307, 307, 307, 307, 307, 307, 203, 307, 307, 307, 307, 307, 307, 203, 203, 203, 203, 307, 307, 307, 141, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 307, 307, 307, 307, 307}, {443, 443, 443, 443, 443, 443, 443, 443, 443, 443, 443, 443, 443, 443, 443, 443, 443, 203, 443, 443, 443, 443, 443, 443, 203, 203, 203, 203, 443, 443, 443, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 443, 443, 443, 443, 443}, {309, 309, 309, 309, 309, 309, 309, 309, 309, 309, 309, 309, 309, 309, 309, 309, 309, 203, 309, 309, 309, 309, 309, 309, 203, 203, 203, 203, 309, 309, 309, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 142, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 309, 309, 309, 309, 309}, {311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 311, 203, 311, 311, 311, 311, 311, 311, 203, 203, 203, 203, 311, 311, 311, 203, 143, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 311, 311, 311, 311, 311}, {313, 313, 313, 313, 313, 313, 313, 313, 313, 313, 313, 313, 313, 313, 313, 313, 313, 203, 313, 313, 313, 313, 313, 313, 203, 203, 203, 203, 313, 313, 313, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 144, 203, 203, 203, 203, 203, 203, 203, 203, 313, 313, 313, 313, 313}, {315, 315, 315, 315, 315, 315, 315, 315, 315, 315, 315, 315, 315, 315, 315, 315, 315, 203, 315, 315, 315, 315, 315, 315, 203, 203, 203, 203, 315, 315, 315, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 145, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 315, 315, 315, 315, 315}, {444, 444, 444, 444, 444, 444, 444, 444, 444, 444, 444, 444, 444, 444, 444, 444, 444, 203, 444, 444, 444, 444, 444, 444, 203, 203, 203, 203, 444, 444, 444, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 444, 444, 444, 444, 444}, {317, 317, 317, 317, 317, 317, 317, 317, 317, 317, 317, 317, 317, 317, 317, 317, 317, 203, 317, 317, 317, 317, 317, 317, 203, 203, 203, 203, 317, 317, 317, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 146, 203, 203, 203, 203, 203, 317, 317, 317, 317, 317}, {319, 319, 319, 319, 319, 319, 319, 319, 319, 319, 319, 319, 319, 319, 319, 319, 319, 203, 319, 319, 319, 319, 319, 319, 203, 203, 203, 203, 319, 319, 319, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 147, 203, 203, 203, 203, 203, 319, 319, 319, 319, 319}, {321, 321, 321, 321, 321, 321, 321, 321, 321, 321, 321, 321, 321, 321, 321, 321, 321, 203, 321, 321, 321, 321, 321, 321, 203, 203, 203, 203, 321, 321, 321, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 148, 203, 203, 203, 321, 321, 321, 321, 321}, {445, 445, 445, 445, 445, 445, 445, 445, 445, 445, 445, 445, 445, 445, 445, 445, 445, 203, 445, 445, 445, 445, 445, 445, 203, 203, 203, 203, 445, 445, 445, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 445, 445, 445, 445, 445}, {323, 323, 323, 323, 323, 323, 323, 323, 323, 323, 323, 323, 323, 323, 323, 323, 323, 203, 323, 323, 323, 323, 323, 323, 203, 203, 203, 203, 323, 323, 323, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 149, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 323, 323, 323, 323, 323}, {325, 325, 325, 325, 325, 325, 325, 325, 325, 325, 325, 325, 325, 325, 325, 325, 325, 203, 325, 325, 325, 325, 325, 325, 203, 203, 203, 203, 325, 325, 325, 203, 203, 203, 203, 203, 203, 203, 150, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 325, 325, 325, 325, 325}, {327, 327, 327, 327, 327, 327, 327, 327, 327, 327, 327, 327, 327, 327, 327, 327, 327, 203, 327, 327, 327, 327, 327, 327, 203, 203, 203, 203, 327, 327, 327, 203, 203, 203, 203, 151, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 327, 327, 327, 327, 327}, {446, 446, 446, 446, 446, 446, 446, 446, 446, 446, 446, 446, 446, 446, 446, 446, 446, 203, 446, 446, 446, 446, 446, 446, 203, 203, 203, 203, 446, 446, 446, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 446, 446, 446, 446, 446}, {447, 447, 447, 447, 447, 447, 447, 447, 447, 447, 447, 447, 447, 447, 447, 447, 447, 203, 447, 447, 447, 447, 447, 447, 203, 203, 203, 203, 447, 447, 447, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 447, 447, 447, 447, 447}, {329, 329, 329, 329, 329, 329, 329, 329, 329, 329, 329, 329, 329, 329, 329, 329, 329, 203, 329, 329, 329, 329, 329, 329, 203, 203, 203, 203, 329, 329, 329, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 152, 203, 203, 203, 203, 203, 203, 329, 329, 329, 329, 329}, {331, 331, 331, 331, 331, 331, 331, 331, 331, 331, 331, 331, 331, 331, 331, 331, 331, 203, 331, 331, 331, 331, 331, 331, 203, 203, 203, 203, 331, 331, 331, 203, 203, 153, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 331, 331, 331, 331, 331}, {333, 333, 333, 333, 333, 333, 333, 333, 333, 333, 333, 333, 333, 333, 333, 333, 333, 203, 333, 333, 333, 333, 333, 333, 203, 203, 203, 203, 333, 333, 333, 203, 203, 203, 203, 203, 203, 203, 203, 203, 154, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 333, 333, 333, 333, 333}, {335, 335, 335, 335, 335, 335, 335, 335, 335, 335, 335, 335, 335, 335, 335, 335, 335, 203, 335, 335, 335, 335, 335, 335, 203, 203, 203, 203, 335, 335, 335, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 155, 203, 203, 203, 203, 203, 335, 335, 335, 335, 335}, {337, 337, 337, 337, 337, 337, 337, 337, 337, 337, 337, 337, 337, 337, 337, 337, 337, 203, 337, 337, 337, 337, 337, 337, 203, 203, 203, 203, 337, 337, 337, 203, 203, 203, 203, 203, 203, 203, 203, 156, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 337, 337, 337, 337, 337}, {448, 448, 448, 448, 448, 448, 448, 448, 448, 448, 448, 448, 448, 448, 448, 448, 448, 203, 448, 448, 448, 448, 448, 448, 203, 203, 203, 203, 448, 448, 448, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 448, 448, 448, 448, 448}, {449, 449, 449, 449, 449, 449, 449, 449, 449, 449, 449, 449, 449, 449, 449, 449, 449, 203, 449, 449, 449, 449, 449, 449, 203, 203, 203, 203, 449, 449, 449, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 449, 449, 449, 449, 449}, {339, 339, 339, 339, 339, 339, 339, 339, 339, 339, 339, 339, 339, 339, 339, 339, 339, 203, 339, 339, 339, 339, 339, 339, 203, 203, 203, 203, 339, 339, 339, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 157, 203, 203, 203, 203, 203, 203, 203, 339, 339, 339, 339, 339}, {341, 341, 341, 341, 341, 341, 341, 341, 341, 341, 341, 341, 341, 341, 341, 341, 341, 203, 341, 341, 341, 341, 341, 341, 203, 203, 203, 203, 341, 341, 341, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 158, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 341, 341, 341, 341, 341}, {450, 450, 450, 450, 450, 450, 450, 450, 450, 450, 450, 450, 450, 450, 450, 450, 450, 203, 450, 450, 450, 450, 450, 450, 203, 203, 203, 203, 450, 450, 450, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 450, 450, 450, 450, 450}, {343, 343, 343, 343, 343, 343, 343, 343, 343, 343, 343, 343, 343, 343, 343, 343, 343, 203, 343, 343, 343, 343, 343, 343, 203, 203, 203, 203, 343, 343, 343, 159, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 343, 343, 343, 343, 343}, {345, 345, 345, 345, 345, 345, 345, 345, 345, 345, 345, 345, 345, 345, 345, 345, 345, 203, 345, 345, 345, 345, 345, 345, 203, 203, 203, 203, 345, 345, 345, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 160, 203, 203, 203, 203, 203, 203, 345, 345, 345, 345, 345}, {347, 347, 347, 347, 347, 347, 347, 347, 347, 347, 347, 347, 347, 347, 347, 347, 347, 203, 347, 347, 347, 347, 347, 347, 203, 203, 203, 203, 347, 347, 347, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 161, 203, 203, 203, 203, 203, 203, 203, 203, 347, 347, 347, 347, 347}, {451, 451, 451, 451, 451, 451, 451, 451, 451, 451, 451, 451, 451, 451, 451, 451, 451, 203, 451, 451, 451, 451, 451, 451, 203, 203, 203, 203, 451, 451, 451, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 451, 451, 451, 451, 451}, {349, 349, 349, 349, 349, 349, 349, 349, 349, 349, 349, 349, 349, 349, 349, 349, 349, 203, 349, 349, 349, 349, 349, 349, 203, 203, 203, 203, 349, 349, 349, 203, 203, 203, 203, 162, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 349, 349, 349, 349, 349}, {351, 351, 351, 351, 351, 351, 351, 351, 351, 351, 351, 351, 351, 351, 351, 351, 351, 203, 351, 351, 351, 351, 351, 351, 203, 203, 203, 203, 351, 351, 351, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 163, 203, 203, 203, 203, 203, 203, 351, 351, 351, 351, 351}, {353, 353, 353, 353, 353, 353, 353, 353, 353, 353, 353, 353, 353, 353, 353, 353, 353, 203, 353, 353, 353, 353, 353, 353, 203, 203, 203, 203, 353, 353, 353, 203, 203, 203, 203, 164, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 353, 353, 353, 353, 353}, {452, 452, 452, 452, 452, 452, 452, 452, 452, 452, 452, 452, 452, 452, 452, 452, 452, 203, 452, 452, 452, 452, 452, 452, 203, 203, 203, 203, 452, 452, 452, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 452, 452, 452, 452, 452}, {453, 453, 453, 453, 453, 453, 453, 453, 453, 453, 453, 453, 453, 453, 453, 453, 453, 203, 453, 453, 453, 453, 453, 453, 203, 203, 203, 203, 453, 453, 453, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 453, 453, 453, 453, 453}, {355, 355, 355, 355, 355, 355, 355, 355, 355, 355, 355, 355, 355, 355, 355, 355, 355, 203, 355, 355, 355, 355, 355, 355, 203, 203, 203, 203, 355, 355, 355, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 165, 203, 203, 203, 203, 355, 355, 355, 355, 355}, {454, 454, 454, 454, 454, 454, 454, 454, 454, 454, 454, 454, 454, 454, 454, 454, 454, 203, 454, 454, 454, 454, 454, 454, 203, 203, 203, 203, 454, 454, 454, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 454, 454, 454, 454, 454}, {455, 455, 455, 455, 455, 455, 455, 455, 455, 455, 455, 455, 455, 455, 455, 455, 455, 203, 455, 455, 455, 455, 455, 455, 203, 203, 203, 203, 455, 455, 455, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 455, 455, 455, 455, 455}, {456, 456, 456, 456, 456, 456, 456, 456, 456, 456, 456, 456, 456, 456, 456, 456, 456, 203, 456, 456, 456, 456, 456, 456, 203, 203, 203, 203, 456, 456, 456, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 456, 456, 456, 456, 456}, {357, 357, 357, 357, 357, 357, 357, 357, 357, 357, 357, 357, 357, 357, 357, 357, 357, 203, 357, 357, 357, 357, 357, 357, 203, 203, 203, 203, 357, 357, 357, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 166, 203, 203, 203, 203, 203, 203, 203, 203, 203, 357, 357, 357, 357, 357}, {359, 359, 359, 359, 359, 359, 359, 359, 359, 359, 359, 359, 359, 359, 359, 359, 359, 203, 359, 359, 359, 359, 359, 359, 203, 203, 203, 203, 359, 359, 359, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 167, 203, 203, 203, 203, 359, 359, 359, 359, 359}, {361, 361, 361, 361, 361, 361, 361, 361, 361, 361, 361, 361, 361, 361, 361, 361, 361, 203, 361, 361, 361, 361, 361, 361, 203, 203, 203, 203, 361, 361, 361, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 168, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 361, 361, 361, 361, 361}, {363, 363, 363, 363, 363, 363, 363, 363, 363, 363, 363, 363, 363, 363, 363, 363, 363, 203, 363, 363, 363, 363, 363, 363, 203, 203, 203, 203, 363, 363, 363, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 169, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 363, 363, 363, 363, 363}, {365, 365, 365, 365, 365, 365, 365, 365, 365, 365, 365, 365, 365, 365, 365, 365, 365, 203, 365, 365, 365, 365, 365, 365, 203, 203, 203, 203, 365, 365, 365, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 170, 203, 203, 203, 203, 365, 365, 365, 365, 365}, {367, 367, 367, 367, 367, 367, 367, 367, 367, 367, 367, 367, 367, 367, 367, 367, 367, 203, 367, 367, 367, 367, 367, 367, 203, 203, 203, 203, 367, 367, 367, 203, 203, 171, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 367, 367, 367, 367, 367}, {457, 457, 457, 457, 457, 457, 457, 457, 457, 457, 457, 457, 457, 457, 457, 457, 457, 203, 457, 457, 457, 457, 457, 457, 203, 203, 203, 203, 457, 457, 457, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 457, 457, 457, 457, 457}, {369, 369, 369, 369, 369, 369, 369, 369, 369, 369, 369, 369, 369, 369, 369, 369, 369, 203, 369, 369, 369, 369, 369, 369, 203, 203, 203, 203, 369, 369, 369, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 172, 203, 203, 203, 203, 203, 203, 203, 203, 203, 369, 369, 369, 369, 369}, {458, 458, 458, 458, 458, 458, 458, 458, 458, 458, 458, 458, 458, 458, 458, 458, 458, 203, 458, 458, 458, 458, 458, 458, 203, 203, 203, 203, 458, 458, 458, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 458, 458, 458, 458, 458}, {459, 459, 459, 459, 459, 459, 459, 459, 459, 459, 459, 459, 459, 459, 459, 459, 459, 203, 459, 459, 459, 459, 459, 459, 203, 203, 203, 203, 459, 459, 459, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 459, 459, 459, 459, 459}, {371, 371, 371, 371, 371, 371, 371, 371, 371, 371, 371, 371, 371, 371, 371, 371, 371, 203, 371, 371, 371, 371, 371, 371, 203, 203, 203, 203, 371, 371, 371, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 173, 203, 203, 203, 371, 371, 371, 371, 371}, {460, 460, 460, 460, 460, 460, 460, 460, 460, 460, 460, 460, 460, 460, 460, 460, 460, 203, 460, 460, 460, 460, 460, 460, 203, 203, 203, 203, 460, 460, 460, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 460, 460, 460, 460, 460}, {373, 373, 373, 373, 373, 373, 373, 373, 373, 373, 373, 373, 373, 373, 373, 373, 373, 203, 373, 373, 373, 373, 373, 373, 203, 203, 203, 203, 373, 373, 373, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 174, 373, 373, 373, 373, 373}, {461, 461, 461, 461, 461, 461, 461, 461, 461, 461, 461, 461, 461, 461, 461, 461, 461, 203, 461, 461, 461, 461, 461, 461, 203, 203, 203, 203, 461, 461, 461, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 461, 461, 461, 461, 461}, {462, 462, 462, 462, 462, 462, 462, 462, 462, 462, 462, 462, 462, 462, 462, 462, 462, 203, 462, 462, 462, 462, 462, 462, 203, 203, 203, 203, 462, 462, 462, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 462, 462, 462, 462, 462}, {375, 375, 375, 375, 375, 375, 375, 375, 375, 375, 375, 375, 375, 375, 375, 375, 375, 203, 375, 375, 375, 375, 375, 375, 203, 203, 203, 203, 375, 375, 375, 175, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 375, 375, 375, 375, 375}, {463, 463, 463, 463, 463, 463, 463, 463, 463, 463, 463, 463, 463, 463, 463, 463, 463, 203, 463, 463, 463, 463, 463, 463, 203, 203, 203, 203, 463, 463, 463, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 463, 463, 463, 463, 463}, {377, 377, 377, 377, 377, 377, 377, 377, 377, 377, 377, 377, 377, 377, 377, 377, 377, 203, 377, 377, 377, 377, 377, 377, 203, 203, 203, 203, 377, 377, 377, 203, 203, 203, 203, 176, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 377, 377, 377, 377, 377}, {464, 464, 464, 464, 464, 464, 464, 464, 464, 464, 464, 464, 464, 464, 464, 464, 464, 203, 464, 464, 464, 464, 464, 464, 203, 203, 203, 203, 464, 464, 464, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 464, 464, 464, 464, 464}, {379, 379, 379, 379, 379, 379, 379, 379, 379, 379, 379, 379, 379, 379, 379, 379, 379, 203, 379, 379, 379, 379, 379, 379, 203, 203, 203, 203, 379, 379, 379, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 177, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 379, 379, 379, 379, 379}, {465, 465, 465, 465, 465, 465, 465, 465, 465, 465, 465, 465, 465, 465, 465, 465, 465, 203, 465, 465, 465, 465, 465, 465, 203, 203, 203, 203, 465, 465, 465, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 465, 465, 465, 465, 465}, {466, 466, 466, 466, 466, 466, 466, 466, 466, 466, 466, 466, 466, 466, 466, 466, 466, 203, 466, 466, 466, 466, 466, 466, 203, 203, 203, 203, 466, 466, 466, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 466, 466, 466, 466, 466}}};
::ISPA_STD::DFA::API::Table<202, 4> Parser::Lexer::action_table = {{{1, 0, ::ISPA_STD::DFA::API::null_state, 23}, {1, 8, ::ISPA_STD::DFA::API::null_state, 36}, {1, 8, ::ISPA_STD::DFA::API::null_state, 25}, {1, 8, ::ISPA_STD::DFA::API::null_state, 35}, {1, 8, ::ISPA_STD::DFA::API::null_state, 34}, {1, 8, ::ISPA_STD::DFA::API::null_state, 33}, {1, 8, ::ISPA_STD::DFA::API::null_state, 32}, {1, 8, ::ISPA_STD::DFA::API::null_state, 43}, {1, 8, ::ISPA_STD::DFA::API::null_state, 42}, {1, 8, ::ISPA_STD::DFA::API::null_state, 41}, {1, 8, ::ISPA_STD::DFA::API::null_state, 40}, {1, 8, ::ISPA_STD::DFA::API::null_state, 39}, {1, 8, ::ISPA_STD::DFA::API::null_state, 37}, {1, 8, ::ISPA_STD::DFA::API::null_state, 31}, {1, 8, ::ISPA_STD::DFA::API::null_state, 30}, {1, 8, ::ISPA_STD::DFA::API::null_state, 26}, {1, 8, ::ISPA_STD::DFA::API::null_state, 24}, {1, 2, ::ISPA_STD::DFA::API::null_state, 16}, {1, 8, ::ISPA_STD::DFA::API::null_state, 38}, {1, 6, ::ISPA_STD::DFA::API::null_state, 52}, {1, 3, ::ISPA_STD::DFA::API::null_state, 394}, {1, 3, ::ISPA_STD::DFA::API::null_state, 61}, {1, 1, ::ISPA_STD::DFA::API::null_state, 401}, {3, 0, 8, 401}, {1, 1, ::ISPA_STD::DFA::API::null_state, 201}, {3, 0, 8, 68}, {3, 0, 8, 401}, {1, 1, ::ISPA_STD::DFA::API::null_state, 204}, {3, 0, 8, 401}, {1, 1, ::ISPA_STD::DFA::API::null_state, 206}, {3, 0, 8, 401}, {1, 1, ::ISPA_STD::DFA::API::null_state, 208}, {3, 0, 8, 401}, {1, 1, ::ISPA_STD::DFA::API::null_state, 210}, {3, 0, 8, 401}, {1, 1, ::ISPA_STD::DFA::API::null_state, 212}, {3, 0, 8, 401}, {1, 1, ::ISPA_STD::DFA::API::null_state, 214}, {3, 0, 8, 401}, {1, 1, ::ISPA_STD::DFA::API::null_state, 216}, {3, 0, 8, 401}, {1, 1, ::ISPA_STD::DFA::API::null_state, 218}, {3, 0, 8, 401}, {1, 1, ::ISPA_STD::DFA::API::null_state, 220}, {3, 0, 8, 401}, {1, 1, ::ISPA_STD::DFA::API::null_state, 222}, {3, 0, 8, 401}, {1, 1, ::ISPA_STD::DFA::API::null_state, 224}, {3, 0, 8, 401}, {1, 1, ::ISPA_STD::DFA::API::null_state, 226}, {3, 0, 8, 401}, {1, 1, ::ISPA_STD::DFA::API::null_state, 228}, {3, 0, 8, 401}, {1, 1, ::ISPA_STD::DFA::API::null_state, 230}, {3, 0, 8, 401}, {1, 1, ::ISPA_STD::DFA::API::null_state, 232}, {3, 0, 8, 401}, {1, 1, ::ISPA_STD::DFA::API::null_state, 234}, {1, 7, ::ISPA_STD::DFA::API::null_state, 53}, {1, 4, ::ISPA_STD::DFA::API::null_state, 100}, {1, 1, ::ISPA_STD::DFA::API::null_state, 427}, {3, 0, 8, 427}, {1, 1, ::ISPA_STD::DFA::API::null_state, 239}, {3, 0, 8, 427}, {1, 1, ::ISPA_STD::DFA::API::null_state, 241}, {3, 0, 8, 427}, {1, 1, ::ISPA_STD::DFA::API::null_state, 243}, {3, 0, 8, 427}, {1, 1, ::ISPA_STD::DFA::API::null_state, 245}, {3, 0, 8, 427}, {1, 1, ::ISPA_STD::DFA::API::null_state, 247}, {3, 0, 8, 427}, {1, 1, ::ISPA_STD::DFA::API::null_state, 249}, {3, 0, 8, 427}, {1, 1, ::ISPA_STD::DFA::API::null_state, 251}, {3, 0, 8, 427}, {1, 1, ::ISPA_STD::DFA::API::null_state, 253}, {3, 0, 8, 427}, {1, 1, ::ISPA_STD::DFA::API::null_state, 255}, {3, 0, 8, 427}, {1, 1, ::ISPA_STD::DFA::API::null_state, 257}, {3, 0, 8, 427}, {1, 1, ::ISPA_STD::DFA::API::null_state, 259}, {3, 0, 8, 427}, {1, 1, ::ISPA_STD::DFA::API::null_state, 261}, {3, 0, 8, 427}, {1, 1, ::ISPA_STD::DFA::API::null_state, 263}, {3, 0, 8, 427}, {1, 1, ::ISPA_STD::DFA::API::null_state, 265}, {3, 0, 8, 427}, {1, 1, ::ISPA_STD::DFA::API::null_state, 267}, {3, 0, 8, 427}, {1, 1, ::ISPA_STD::DFA::API::null_state, 269}, {3, 0, 8, 427}, {1, 1, ::ISPA_STD::DFA::API::null_state, 271}, {3, 0, 8, 427}, {1, 1, ::ISPA_STD::DFA::API::null_state, 273}, {3, 0, 8, 427}, {1, 1, ::ISPA_STD::DFA::API::null_state, 275}, {3, 0, 8, 427}, {1, 1, ::ISPA_STD::DFA::API::null_state, 277}, {3, 0, 8, 427}, {1, 1, ::ISPA_STD::DFA::API::null_state, 279}, {3, 0, 8, 427}, {1, 1, ::ISPA_STD::DFA::API::null_state, 281}, {1, 5, ::ISPA_STD::DFA::API::null_state, 437}, {3, 0, 8, 427}, {1, 1, ::ISPA_STD::DFA::API::null_state, 284}, {3, 0, 8, 427}, {1, 1, ::ISPA_STD::DFA::API::null_state, 286}, {3, 0, 8, 427}, {1, 1, ::ISPA_STD::DFA::API::null_state, 288}, {3, 0, 8, 427}, {1, 1, ::ISPA_STD::DFA::API::null_state, 290}, {3, 0, 8, 427}, {1, 1, ::ISPA_STD::DFA::API::null_state, 292}, {3, 0, 8, 427}, {1, 1, ::ISPA_STD::DFA::API::null_state, 294}, {3, 0, 8, 427}, {1, 1, ::ISPA_STD::DFA::API::null_state, 296}, {3, 0, 8, 427}, {1, 1, ::ISPA_STD::DFA::API::null_state, 298}, {3, 0, 8, 427}, {1, 1, ::ISPA_STD::DFA::API::null_state, 300}, {3, 0, 8, 427}, {1, 1, ::ISPA_STD::DFA::API::null_state, 302}, {3, 0, 8, 427}, {1, 1, ::ISPA_STD::DFA::API::null_state, 304}, {3, 0, 8, 427}, {1, 1, ::ISPA_STD::DFA::API::null_state, 306}, {3, 0, 8, 427}, {1, 1, ::ISPA_STD::DFA::API::null_state, 308}, {3, 0, 8, 427}, {1, 1, ::ISPA_STD::DFA::API::null_state, 310}, {3, 0, 8, 427}, {1, 1, ::ISPA_STD::DFA::API::null_state, 312}, {3, 0, 8, 427}, {1, 1, ::ISPA_STD::DFA::API::null_state, 314}, {3, 0, 8, 427}, {1, 1, ::ISPA_STD::DFA::API::null_state, 316}, {3, 0, 8, 427}, {1, 1, ::ISPA_STD::DFA::API::null_state, 318}, {3, 0, 8, 427}, {1, 1, ::ISPA_STD::DFA::API::null_state, 320}, {3, 0, 8, 427}, {1, 1, ::ISPA_STD::DFA::API::null_state, 322}, {3, 0, 8, 427}, {1, 1, ::ISPA_STD::DFA::API::null_state, 324}, {3, 0, 8, 427}, {1, 1, ::ISPA_STD::DFA::API::null_state, 326}, {3, 0, 8, 427}, {1, 1, ::ISPA_STD::DFA::API::null_state, 328}, {3, 0, 8, 427}, {1, 1, ::ISPA_STD::DFA::API::null_state, 330}, {3, 0, 8, 427}, {1, 1, ::ISPA_STD::DFA::API::null_state, 332}, {3, 0, 8, 427}, {1, 1, ::ISPA_STD::DFA::API::null_state, 334}, {3, 0, 8, 427}, {1, 1, ::ISPA_STD::DFA::API::null_state, 336}, {3, 0, 8, 427}, {1, 1, ::ISPA_STD::DFA::API::null_state, 338}, {3, 0, 8, 427}, {1, 1, ::ISPA_STD::DFA::API::null_state, 340}, {3, 0, 8, 427}, {1, 1, ::ISPA_STD::DFA::API::null_state, 342}, {3, 0, 8, 427}, {1, 1, ::ISPA_STD::DFA::API::null_state, 344}, {3, 0, 8, 427}, {1, 1, ::ISPA_STD::DFA::API::null_state, 346}, {3, 0, 8, 427}, {1, 1, ::ISPA_STD::DFA::API::null_state, 348}, {3, 0, 8, 427}, {1, 1, ::ISPA_STD::DFA::API::null_state, 350}, {3, 0, 8, 427}, {1, 1, ::ISPA_STD::DFA::API::null_state, 352}, {3, 0, 8, 427}, {1, 1, ::ISPA_STD::DFA::API::null_state, 354}, {3, 0, 8, 427}, {1, 1, ::ISPA_STD::DFA::API::null_state, 356}, {3, 0, 8, 427}, {1, 1, ::ISPA_STD::DFA::API::null_state, 358}, {3, 0, 8, 427}, {1, 1, ::ISPA_STD::DFA::API::null_state, 360}, {3, 0, 8, 427}, {1, 1, ::ISPA_STD::DFA::API::null_state, 362}, {3, 0, 8, 427}, {1, 1, ::ISPA_STD::DFA::API::null_state, 364}, {3, 0, 8, 427}, {1, 1, ::ISPA_STD::DFA::API::null_state, 366}, {3, 0, 8, 427}, {1, 1, ::ISPA_STD::DFA::API::null_state, 368}, {3, 0, 8, 427}, {1, 1, ::ISPA_STD::DFA::API::null_state, 370}, {3, 0, 8, 427}, {1, 1, ::ISPA_STD::DFA::API::null_state, 372}, {3, 0, 8, 427}, {1, 1, ::ISPA_STD::DFA::API::null_state, 374}, {3, 0, 8, 427}, {1, 1, ::ISPA_STD::DFA::API::null_state, 376}, {3, 0, 8, 427}, {1, 1, ::ISPA_STD::DFA::API::null_state, 378}}};
std::array<::ISPA_STD::DFA::API::DFADebug, 1> Parser::Lexer::debug_array = {::ISPA_STD::DFA::API::DFADebug {"<Undefined>", "", 0, -1, -1, -1, 0, 1, '\000'}};
std::unordered_map<long long, std::unordered_map<long long, long long>> Parser::Lexer::debug_index = { { 0, { { 1, 0 }, { 2, 0 }, { 3, 0 }, { 4, 0 }, { 5, 0 }, { 6, 0 }, { 7, 0 }, { 8, 0 }, { 9, 0 }, { 10, 0 }, { 11, 0 }, { 12, 0 }, { 13, 0 }, { 14, 0 }, { 15, 0 }, { 16, 0 }, { 18, 0 }, { 19, 0 }, { 20, 0 }, { 21, 0 }, { 22, 0 }, { 23, 0 }, { 28, 0 }, { 29, 0 }, { 30, 0 }, { 53, 0 }, { 54, 0 }, { 55, 0 }, { 56, 0 } } }, { 1, { { 1, 0 }, { 2, 0 }, { 3, 0 } } }, { 2, { { 1, 0 }, { 2, 0 }, { 3, 0 } } }, { 3, { { 21, 0 } } }, { 4, { { 0, 0 }, { 1, 0 }, { 3, 0 }, { 4, 0 }, { 5, 0 }, { 6, 0 }, { 7, 0 }, { 8, 0 }, { 9, 0 }, { 10, 0 }, { 11, 0 }, { 12, 0 }, { 13, 0 }, { 14, 0 }, { 15, 0 }, { 16, 0 }, { 17, 0 }, { 18, 0 }, { 19, 0 }, { 20, 0 }, { 21, 0 }, { 22, 0 }, { 23, 0 }, { 24, 0 }, { 25, 0 }, { 26, 0 }, { 27, 0 }, { 28, 0 }, { 29, 0 }, { 30, 0 }, { 31, 0 }, { 32, 0 }, { 33, 0 }, { 34, 0 }, { 35, 0 }, { 36, 0 }, { 37, 0 }, { 38, 0 }, { 39, 0 }, { 40, 0 }, { 41, 0 }, { 42, 0 }, { 43, 0 }, { 44, 0 }, { 45, 0 }, { 46, 0 }, { 47, 0 }, { 48, 0 }, { 49, 0 }, { 50, 0 }, { 51, 0 }, { 52, 0 }, { 53, 0 }, { 54, 0 }, { 55, 0 }, { 56, 0 } } }, { 5, { { 21, 0 } } }, { 6, { { 21, 0 } } }, { 7, { { 8, 0 } } }, { 10, { { 11, 0 }, { 21, 0 } } }, { 11, { { 21, 0 } } }, { 13, { { 21, 0 }, { 22, 0 } } }, { 15, { { 16, 0 }, { 21, 0 } } }, { 16, { { 17, 0 } } }, { 19, { { 20, 0 }, { 21, 0 } } }, { 20, { { 21, 0 } } }, { 21, { { 21, 0 }, { 22, 0 } } }, { 22, { { 21, 0 } } }, { 23, { { 17, 0 }, { 24, 0 }, { 25, 0 }, { 26, 0 }, { 27, 0 }, { 31, 0 }, { 32, 0 }, { 33, 0 }, { 34, 0 }, { 35, 0 }, { 36, 0 }, { 37, 0 }, { 38, 0 }, { 39, 0 }, { 40, 0 }, { 41, 0 }, { 42, 0 }, { 43, 0 }, { 44, 0 }, { 45, 0 }, { 46, 0 }, { 47, 0 }, { 48, 0 }, { 49, 0 }, { 50, 0 }, { 51, 0 }, { 52, 0 } } }, { 24, { { 31, 0 } } }, { 25, { { 44, 0 } } }, { 26, { { 46, 0 } } }, { 29, { { 21, 0 } } }, { 30, { { 43, 0 }, { 47, 0 } } }, { 31, { { 46, 0 } } }, { 32, { { 41, 0 }, { 44, 0 } } }, { 33, { { 35, 0 } } }, { 34, { { 41, 0 }, { 51, 0 } } }, { 35, { { 39, 0 }, { 44, 0 }, { 46, 0 } } }, { 36, { { 41, 0 } } }, { 37, { { 36, 0 }, { 42, 0 }, { 43, 0 }, { 47, 0 } } }, { 38, { { 44, 0 } } }, { 39, { { 46, 0 } } }, { 40, { { 31, 0 } } }, { 41, { { 31, 0 }, { 35, 0 } } }, { 42, { { 46, 0 } } }, { 43, { { 38, 0 }, { 39, 0 } } }, { 45, { { 21, 0 } } }, { 49, { { 0, 0 }, { 1, 0 }, { 3, 0 }, { 4, 0 }, { 5, 0 }, { 6, 0 }, { 7, 0 }, { 8, 0 }, { 9, 0 }, { 10, 0 }, { 11, 0 }, { 12, 0 }, { 13, 0 }, { 14, 0 }, { 15, 0 }, { 16, 0 }, { 17, 0 }, { 18, 0 }, { 19, 0 }, { 20, 0 }, { 21, 0 }, { 22, 0 }, { 23, 0 }, { 24, 0 }, { 25, 0 }, { 26, 0 }, { 27, 0 }, { 28, 0 }, { 29, 0 }, { 30, 0 }, { 31, 0 }, { 32, 0 }, { 33, 0 }, { 34, 0 }, { 35, 0 }, { 36, 0 }, { 37, 0 }, { 38, 0 }, { 39, 0 }, { 40, 0 }, { 41, 0 }, { 42, 0 }, { 43, 0 }, { 44, 0 }, { 45, 0 }, { 46, 0 }, { 47, 0 }, { 48, 0 }, { 49, 0 }, { 50, 0 }, { 51, 0 }, { 52, 0 }, { 53, 0 }, { 54, 0 }, { 55, 0 }, { 56, 0 } } }, { 52, { { 0, 0 }, { 1, 0 }, { 2, 0 }, { 3, 0 }, { 4, 0 }, { 5, 0 }, { 6, 0 }, { 7, 0 }, { 9, 0 }, { 10, 0 }, { 11, 0 }, { 12, 0 }, { 13, 0 }, { 14, 0 }, { 15, 0 }, { 16, 0 }, { 17, 0 }, { 18, 0 }, { 19, 0 }, { 20, 0 }, { 21, 0 }, { 22, 0 }, { 23, 0 }, { 24, 0 }, { 25, 0 }, { 26, 0 }, { 27, 0 }, { 28, 0 }, { 29, 0 }, { 30, 0 }, { 31, 0 }, { 32, 0 }, { 33, 0 }, { 34, 0 }, { 35, 0 }, { 36, 0 }, { 37, 0 }, { 38, 0 }, { 39, 0 }, { 40, 0 }, { 41, 0 }, { 42, 0 }, { 43, 0 }, { 44, 0 }, { 45, 0 }, { 46, 0 }, { 47, 0 }, { 48, 0 }, { 49, 0 }, { 50, 0 }, { 51, 0 }, { 52, 0 }, { 53, 0 }, { 54, 0 }, { 55, 0 }, { 56, 0 } } }, { 54, { { 21, 0 } } }, { 59, { { 21, 0 } } }, { 62, { { 21, 0 } } }, { 66, { { 21, 0 } } }, { 68, { { 17, 0 }, { 24, 0 }, { 25, 0 }, { 26, 0 }, { 27, 0 }, { 31, 0 }, { 32, 0 }, { 33, 0 }, { 34, 0 }, { 35, 0 }, { 36, 0 }, { 37, 0 }, { 38, 0 }, { 39, 0 }, { 40, 0 }, { 41, 0 }, { 42, 0 }, { 43, 0 }, { 44, 0 }, { 45, 0 }, { 46, 0 }, { 47, 0 }, { 48, 0 }, { 49, 0 }, { 50, 0 }, { 51, 0 }, { 52, 0 } } }, { 69, { { 41, 0 } } }, { 70, { { 43, 0 } } }, { 71, { { 49, 0 } } }, { 73, { { 34, 0 } } }, { 74, { { 47, 0 }, { 52, 0 } } }, { 75, { { 35, 0 } } }, { 76, { { 31, 0 } } }, { 77, { { 43, 0 } } }, { 78, { { 36, 0 }, { 41, 0 } } }, { 79, { { 39, 0 }, { 47, 0 } } }, { 80, { { 33, 0 } } }, { 81, { { 43, 0 } } }, { 82, { { 46, 0 } } }, { 83, { { 44, 0 } } }, { 84, { { 44, 0 } } }, { 86, { { 45, 0 } } }, { 89, { { 43, 0 }, { 48, 0 } } }, { 91, { { 47, 0 } } }, { 92, { { 39, 0 } } }, { 93, { { 48, 0 } } }, { 94, { { 52, 0 } } }, { 95, { { 39, 0 } } }, { 96, { { 48, 0 } } }, { 100, { { 17, 0 } } }, { 103, { { 47, 0 } } }, { 104, { { 35, 0 } } }, { 105, { { 35, 0 } } }, { 107, { { 35, 0 } } }, { 108, { { 43, 0 } } }, { 109, { { 31, 0 } } }, { 110, { { 47, 0 } } }, { 111, { { 48, 0 } } }, { 114, { { 36, 0 } } }, { 115, { { 35, 0 } } }, { 116, { { 35, 0 } } }, { 117, { { 31, 0 } } }, { 119, { { 42, 0 } } }, { 120, { { 32, 0 } } }, { 121, { { 44, 0 } } }, { 122, { { 41, 0 } } }, { 124, { { 47, 0 } } }, { 125, { { 47, 0 } } }, { 126, { { 49, 0 } } }, { 128, { { 41, 0 } } }, { 129, { { 38, 0 } } }, { 130, { { 35, 0 } } }, { 133, { { 46, 0 } } }, { 134, { { 33, 0 } } }, { 135, { { 40, 0 } } }, { 136, { { 47, 0 } } }, { 137, { { 39, 0 } } }, { 140, { { 45, 0 } } }, { 141, { { 41, 0 } } }, { 143, { { 31, 0 } } }, { 144, { { 46, 0 } } }, { 145, { { 44, 0 } } }, { 147, { { 35, 0 } } }, { 148, { { 46, 0 } } }, { 149, { { 35, 0 } } }, { 152, { { 48, 0 } } }, { 156, { { 43, 0 } } }, { 157, { { 48, 0 } } }, { 158, { { 41, 0 } } }, { 159, { { 41, 0 } } }, { 160, { { 48, 0 } } }, { 161, { { 33, 0 } } }, { 163, { { 43, 0 } } }, { 166, { { 49, 0 } } }, { 168, { { 52, 0 } } }, { 171, { { 31, 0 } } }, { 173, { { 35, 0 } } }, { 175, { { 41, 0 } } } };
template<typename IT, class> auto Parser::Parser::annotated_assignment(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::annotated_assignment, IT> {
	::ISPA_STD::Node<::Parser::Tokens, Types::COLON> COLON_0;
	bool success_1;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::MatchResult<Rules, Types::expr, IT> expr_4;
	bool success_5;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_6;
	bool success_7;
	bool success_16;
	bool success_12;
	std::tuple<::ISPA_STD::Node<::Parser::Tokens, Types::ASSIGN>, ::ISPA_STD::Node<::Parser::Tokens, Types::__WS>, ::ISPA_STD::Node<::Parser::Rules, Types::expr>> group_8;
	bool success_10;
	std::tuple<::ISPA_STD::Node<::Parser::Tokens, Types::ASSIGN>, ::ISPA_STD::Node<::Parser::Tokens, Types::__WS>, ::ISPA_STD::Node<::Parser::Rules, Types::expr>> uvar_9;
	::ISPA_STD::Node<::Parser::Tokens, Types::ASSIGN> ASSIGN_11;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_13;
	bool success_14;
	::ISPA_STD::MatchResult<Rules, Types::expr, IT> expr_15;
	::ISPA_STD::Node<::Parser::Rules, Types::expr> tuple_elem_17;
	success_1 = false;
	if (!(((*pos)).template holds<Types::COLON>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  COLON");
		return {};
	}
	COLON_0 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::COLON>>();
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
	success_10 = false;
	auto begin_18 = pos;
	success_12 = false;
	success_14 = false;
	success_16 = false;
	// grammar `@  ( ASSIGN  __WS?; @  expr)?;`: optional group; try at most once
	while (true) {
		// grammar `@  ( ASSIGN  __WS?; @  expr)?;`: optional body; failed alternative leaves this group
		if (!(((*begin_18)).template holds<Types::ASSIGN>())) {
			// speculative match failed (diagnostic suppressed):  ASSIGN
			break;
		}
		ASSIGN_11 = ((*begin_18)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::ASSIGN>>();
		success_12 = true;
		begin_18++;
		success_14 = false;
		if (((*begin_18)).template holds<Types::__WS>()) {
			__WS_13 = ((*begin_18)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
			success_14 = true;
			begin_18++;
		}
		expr_15 = expr(begin_18);
		if (!(expr_15.status)) {
			// speculative match failed (diagnostic suppressed): @  expr
			break;
		}
		success_16 = true;
		begin_18 = expr_15.it;
		break;
	}
	if (success_12 && success_16) {
		tuple_elem_17 = expr_15.node;
		group_8 = std::make_tuple(ASSIGN_11, __WS_13, tuple_elem_17);
		success_10 = true;
		::ISPA_STD::assign_compatible(uvar_9, group_8);
	}
	// grammar `@  ( ASSIGN  __WS?; @  expr)?;`: optional group end; release saved position
	pos = begin_18;
	Types::annotated_assignment result;
	::ISPA_STD::assign_compatible(result.annotation, expr_4);
	::ISPA_STD::assign_compatible(result.value, expr_15);
	::ISPA_STD::MatchResult<Rules, Types::annotated_assignment, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::annotated_assignment<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::annotated_assignment, ::Parser::Lexer::iterator>;
template auto Parser::Parser::annotated_assignment<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::annotated_assignment, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::assert_stmt(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::assert_stmt, IT> {
	::ISPA_STD::Node<::Parser::Tokens, Types::ASSERT> ASSERT_0;
	bool success_1;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::MatchResult<Rules, Types::expr, IT> expr_4;
	bool success_5;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_6;
	bool success_7;
	bool success_16;
	bool success_12;
	std::tuple<::ISPA_STD::Node<::Parser::Tokens, Types::COMMA>, ::ISPA_STD::Node<::Parser::Tokens, Types::__WS>, ::ISPA_STD::Node<::Parser::Rules, Types::expr>> group_8;
	bool success_10;
	std::tuple<::ISPA_STD::Node<::Parser::Tokens, Types::COMMA>, ::ISPA_STD::Node<::Parser::Tokens, Types::__WS>, ::ISPA_STD::Node<::Parser::Rules, Types::expr>> uvar_9;
	::ISPA_STD::Node<::Parser::Tokens, Types::COMMA> COMMA_11;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_13;
	bool success_14;
	::ISPA_STD::MatchResult<Rules, Types::expr, IT> expr_15;
	::ISPA_STD::Node<::Parser::Rules, Types::expr> tuple_elem_17;
	success_1 = false;
	if (!(((*pos)).template holds<Types::ASSERT>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  ASSERT");
		return {};
	}
	ASSERT_0 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::ASSERT>>();
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
	success_10 = false;
	auto begin_18 = pos;
	success_12 = false;
	success_14 = false;
	success_16 = false;
	// grammar `@  ( COMMA  __WS?; @  expr)?;`: optional group; try at most once
	while (true) {
		// grammar `@  ( COMMA  __WS?; @  expr)?;`: optional body; failed alternative leaves this group
		if (!(((*begin_18)).template holds<Types::COMMA>())) {
			// speculative match failed (diagnostic suppressed):  COMMA
			break;
		}
		COMMA_11 = ((*begin_18)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::COMMA>>();
		success_12 = true;
		begin_18++;
		success_14 = false;
		if (((*begin_18)).template holds<Types::__WS>()) {
			__WS_13 = ((*begin_18)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
			success_14 = true;
			begin_18++;
		}
		expr_15 = expr(begin_18);
		if (!(expr_15.status)) {
			// speculative match failed (diagnostic suppressed): @  expr
			break;
		}
		success_16 = true;
		begin_18 = expr_15.it;
		break;
	}
	if (success_12 && success_16) {
		tuple_elem_17 = expr_15.node;
		group_8 = std::make_tuple(COMMA_11, __WS_13, tuple_elem_17);
		success_10 = true;
		::ISPA_STD::assign_compatible(uvar_9, group_8);
	}
	// grammar `@  ( COMMA  __WS?; @  expr)?;`: optional group end; release saved position
	pos = begin_18;
	Types::assert_stmt result;
	::ISPA_STD::assign_compatible(result.condition, expr_4);
	::ISPA_STD::assign_compatible(result.message, expr_15);
	::ISPA_STD::MatchResult<Rules, Types::assert_stmt, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::assert_stmt<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::assert_stmt, ::Parser::Lexer::iterator>;
template auto Parser::Parser::assert_stmt<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::assert_stmt, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::assignment_op(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::assignment_op, IT> {
	std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Tokens, Types::RSHIFT_ASSIGN>, ::ISPA_STD::Node<::Parser::Tokens, Types::CARET_ASSIGN>, ::ISPA_STD::Node<::Parser::Tokens, Types::AMP_ASSIGN>, ::ISPA_STD::Node<::Parser::Tokens, Types::POWER_ASSIGN>, ::ISPA_STD::Node<::Parser::Tokens, Types::FLOOR_DIV_ASSIGN>, ::ISPA_STD::Node<::Parser::Tokens, Types::SLASH_ASSIGN>, ::ISPA_STD::Node<::Parser::Tokens, Types::PIPE_ASSIGN>, ::ISPA_STD::Node<::Parser::Tokens, Types::MATMUL_ASSIGN>, ::ISPA_STD::Node<::Parser::Tokens, Types::MINUS_ASSIGN>, ::ISPA_STD::Node<::Parser::Tokens, Types::PERCENT_ASSIGN>, ::ISPA_STD::Node<::Parser::Tokens, Types::ASSIGN>, ::ISPA_STD::Node<::Parser::Tokens, Types::LSHIFT_ASSIGN>, ::ISPA_STD::Node<::Parser::Tokens, Types::STAR_ASSIGN>, ::ISPA_STD::Node<::Parser::Tokens, Types::PLUS_ASSIGN>> _0;
	bool success_1;
	::ISPA_STD::Node<::Parser::Tokens, Types::AMP_ASSIGN> AMP_ASSIGN_2;
	bool success_3;
	::ISPA_STD::Node<::Parser::Tokens, Types::ASSIGN> ASSIGN_4;
	bool success_5;
	::ISPA_STD::Node<::Parser::Tokens, Types::CARET_ASSIGN> CARET_ASSIGN_6;
	bool success_7;
	::ISPA_STD::Node<::Parser::Tokens, Types::FLOOR_DIV_ASSIGN> FLOOR_DIV_ASSIGN_8;
	bool success_9;
	::ISPA_STD::Node<::Parser::Tokens, Types::LSHIFT_ASSIGN> LSHIFT_ASSIGN_10;
	bool success_11;
	::ISPA_STD::Node<::Parser::Tokens, Types::MATMUL_ASSIGN> MATMUL_ASSIGN_12;
	bool success_13;
	::ISPA_STD::Node<::Parser::Tokens, Types::MINUS_ASSIGN> MINUS_ASSIGN_14;
	bool success_15;
	::ISPA_STD::Node<::Parser::Tokens, Types::PERCENT_ASSIGN> PERCENT_ASSIGN_16;
	bool success_17;
	::ISPA_STD::Node<::Parser::Tokens, Types::PIPE_ASSIGN> PIPE_ASSIGN_18;
	bool success_19;
	::ISPA_STD::Node<::Parser::Tokens, Types::PLUS_ASSIGN> PLUS_ASSIGN_20;
	bool success_21;
	::ISPA_STD::Node<::Parser::Tokens, Types::POWER_ASSIGN> POWER_ASSIGN_22;
	bool success_23;
	::ISPA_STD::Node<::Parser::Tokens, Types::RSHIFT_ASSIGN> RSHIFT_ASSIGN_24;
	bool success_25;
	::ISPA_STD::Node<::Parser::Tokens, Types::SLASH_ASSIGN> SLASH_ASSIGN_26;
	bool success_27;
	::ISPA_STD::Node<::Parser::Tokens, Types::STAR_ASSIGN> STAR_ASSIGN_28;
	bool success_29;
	success_1 = false;
	// grammar `@  ( ASSIGN |  PLUS_ASSIGN |  MINUS_ASSIGN |  STAR_ASSIGN |  MATMUL_ASSIGN |  SLASH_ASSIGN |  FLOOR_DIV_ASSIGN |  PERCENT_ASSIGN |  POWER_ASSIGN |  AMP_ASSIGN |  PIPE_ASSIGN |  CARET_ASSIGN |  LSHIFT_ASSIGN |  RSHIFT_ASSIGN)`: choice; reset match status before selecting an alternative
	success_1 = false;
	auto lookahead_pos_1 = pos;
	switch (static_cast<Tokens>((*lookahead_pos_1).kind())) {
		case Tokens::AMP_ASSIGN: {
			lookahead_pos_1 = lookahead_pos_1;
			success_3 = false;
			if (!(((*lookahead_pos_1)).template holds<Types::AMP_ASSIGN>())) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  AMP_ASSIGN");
				return {};
			}
			AMP_ASSIGN_2 = ((*lookahead_pos_1)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::AMP_ASSIGN>>();
			success_3 = true;
			lookahead_pos_1++;
			if (!success_3) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  AMP_ASSIGN");
				return {};
			}
			_0 = AMP_ASSIGN_2;
			success_1 = true;
			break;
		}
		case Tokens::ASSIGN: {
			lookahead_pos_1 = lookahead_pos_1;
			success_5 = false;
			if (!(((*lookahead_pos_1)).template holds<Types::ASSIGN>())) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  ASSIGN");
				return {};
			}
			ASSIGN_4 = ((*lookahead_pos_1)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::ASSIGN>>();
			success_5 = true;
			lookahead_pos_1++;
			if (!success_5) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  ASSIGN");
				return {};
			}
			_0 = ASSIGN_4;
			success_1 = true;
			break;
		}
		case Tokens::CARET_ASSIGN: {
			lookahead_pos_1 = lookahead_pos_1;
			success_7 = false;
			if (!(((*lookahead_pos_1)).template holds<Types::CARET_ASSIGN>())) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  CARET_ASSIGN");
				return {};
			}
			CARET_ASSIGN_6 = ((*lookahead_pos_1)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::CARET_ASSIGN>>();
			success_7 = true;
			lookahead_pos_1++;
			if (!success_7) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  CARET_ASSIGN");
				return {};
			}
			_0 = CARET_ASSIGN_6;
			success_1 = true;
			break;
		}
		case Tokens::FLOOR_DIV_ASSIGN: {
			lookahead_pos_1 = lookahead_pos_1;
			success_9 = false;
			if (!(((*lookahead_pos_1)).template holds<Types::FLOOR_DIV_ASSIGN>())) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  FLOOR_DIV_ASSIGN");
				return {};
			}
			FLOOR_DIV_ASSIGN_8 = ((*lookahead_pos_1)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::FLOOR_DIV_ASSIGN>>();
			success_9 = true;
			lookahead_pos_1++;
			if (!success_9) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  FLOOR_DIV_ASSIGN");
				return {};
			}
			_0 = FLOOR_DIV_ASSIGN_8;
			success_1 = true;
			break;
		}
		case Tokens::LSHIFT_ASSIGN: {
			lookahead_pos_1 = lookahead_pos_1;
			success_11 = false;
			if (!(((*lookahead_pos_1)).template holds<Types::LSHIFT_ASSIGN>())) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  LSHIFT_ASSIGN");
				return {};
			}
			LSHIFT_ASSIGN_10 = ((*lookahead_pos_1)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::LSHIFT_ASSIGN>>();
			success_11 = true;
			lookahead_pos_1++;
			if (!success_11) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  LSHIFT_ASSIGN");
				return {};
			}
			_0 = LSHIFT_ASSIGN_10;
			success_1 = true;
			break;
		}
		case Tokens::MATMUL_ASSIGN: {
			lookahead_pos_1 = lookahead_pos_1;
			success_13 = false;
			if (!(((*lookahead_pos_1)).template holds<Types::MATMUL_ASSIGN>())) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  MATMUL_ASSIGN");
				return {};
			}
			MATMUL_ASSIGN_12 = ((*lookahead_pos_1)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::MATMUL_ASSIGN>>();
			success_13 = true;
			lookahead_pos_1++;
			if (!success_13) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  MATMUL_ASSIGN");
				return {};
			}
			_0 = MATMUL_ASSIGN_12;
			success_1 = true;
			break;
		}
		case Tokens::MINUS_ASSIGN: {
			lookahead_pos_1 = lookahead_pos_1;
			success_15 = false;
			if (!(((*lookahead_pos_1)).template holds<Types::MINUS_ASSIGN>())) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  MINUS_ASSIGN");
				return {};
			}
			MINUS_ASSIGN_14 = ((*lookahead_pos_1)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::MINUS_ASSIGN>>();
			success_15 = true;
			lookahead_pos_1++;
			if (!success_15) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  MINUS_ASSIGN");
				return {};
			}
			_0 = MINUS_ASSIGN_14;
			success_1 = true;
			break;
		}
		case Tokens::PERCENT_ASSIGN: {
			lookahead_pos_1 = lookahead_pos_1;
			success_17 = false;
			if (!(((*lookahead_pos_1)).template holds<Types::PERCENT_ASSIGN>())) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  PERCENT_ASSIGN");
				return {};
			}
			PERCENT_ASSIGN_16 = ((*lookahead_pos_1)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::PERCENT_ASSIGN>>();
			success_17 = true;
			lookahead_pos_1++;
			if (!success_17) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  PERCENT_ASSIGN");
				return {};
			}
			_0 = PERCENT_ASSIGN_16;
			success_1 = true;
			break;
		}
		case Tokens::PIPE_ASSIGN: {
			lookahead_pos_1 = lookahead_pos_1;
			success_19 = false;
			if (!(((*lookahead_pos_1)).template holds<Types::PIPE_ASSIGN>())) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  PIPE_ASSIGN");
				return {};
			}
			PIPE_ASSIGN_18 = ((*lookahead_pos_1)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::PIPE_ASSIGN>>();
			success_19 = true;
			lookahead_pos_1++;
			if (!success_19) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  PIPE_ASSIGN");
				return {};
			}
			_0 = PIPE_ASSIGN_18;
			success_1 = true;
			break;
		}
		case Tokens::PLUS_ASSIGN: {
			lookahead_pos_1 = lookahead_pos_1;
			success_21 = false;
			if (!(((*lookahead_pos_1)).template holds<Types::PLUS_ASSIGN>())) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  PLUS_ASSIGN");
				return {};
			}
			PLUS_ASSIGN_20 = ((*lookahead_pos_1)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::PLUS_ASSIGN>>();
			success_21 = true;
			lookahead_pos_1++;
			if (!success_21) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  PLUS_ASSIGN");
				return {};
			}
			_0 = PLUS_ASSIGN_20;
			success_1 = true;
			break;
		}
		case Tokens::POWER_ASSIGN: {
			lookahead_pos_1 = lookahead_pos_1;
			success_23 = false;
			if (!(((*lookahead_pos_1)).template holds<Types::POWER_ASSIGN>())) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  POWER_ASSIGN");
				return {};
			}
			POWER_ASSIGN_22 = ((*lookahead_pos_1)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::POWER_ASSIGN>>();
			success_23 = true;
			lookahead_pos_1++;
			if (!success_23) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  POWER_ASSIGN");
				return {};
			}
			_0 = POWER_ASSIGN_22;
			success_1 = true;
			break;
		}
		case Tokens::RSHIFT_ASSIGN: {
			lookahead_pos_1 = lookahead_pos_1;
			success_25 = false;
			if (!(((*lookahead_pos_1)).template holds<Types::RSHIFT_ASSIGN>())) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  RSHIFT_ASSIGN");
				return {};
			}
			RSHIFT_ASSIGN_24 = ((*lookahead_pos_1)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::RSHIFT_ASSIGN>>();
			success_25 = true;
			lookahead_pos_1++;
			if (!success_25) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  RSHIFT_ASSIGN");
				return {};
			}
			_0 = RSHIFT_ASSIGN_24;
			success_1 = true;
			break;
		}
		case Tokens::SLASH_ASSIGN: {
			lookahead_pos_1 = lookahead_pos_1;
			success_27 = false;
			if (!(((*lookahead_pos_1)).template holds<Types::SLASH_ASSIGN>())) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  SLASH_ASSIGN");
				return {};
			}
			SLASH_ASSIGN_26 = ((*lookahead_pos_1)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::SLASH_ASSIGN>>();
			success_27 = true;
			lookahead_pos_1++;
			if (!success_27) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  SLASH_ASSIGN");
				return {};
			}
			_0 = SLASH_ASSIGN_26;
			success_1 = true;
			break;
		}
		case Tokens::STAR_ASSIGN: {
			lookahead_pos_1 = lookahead_pos_1;
			success_29 = false;
			if (!(((*lookahead_pos_1)).template holds<Types::STAR_ASSIGN>())) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  STAR_ASSIGN");
				return {};
			}
			STAR_ASSIGN_28 = ((*lookahead_pos_1)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::STAR_ASSIGN>>();
			success_29 = true;
			lookahead_pos_1++;
			if (!success_29) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  STAR_ASSIGN");
				return {};
			}
			_0 = STAR_ASSIGN_28;
			success_1 = true;
			break;
		}
	}
	pos = lookahead_pos_1;
	if (!success_1) {
		raise_error(*pos, "ISPA match failure: no LL(k) alternative matched | grammar: @  ( ASSIGN |  PLUS_ASSIGN |  MINUS_ASSIGN |  STAR_ASSIGN |  MATMUL_ASSIGN |  SLASH_ASSIGN |  FLOOR_DIV_ASSIGN |  PERCENT_ASSIGN |  POWER_ASSIGN |  AMP_ASSIGN |  PIPE_ASSIGN |  CARET_ASSIGN |  LSHIFT_ASSIGN |  RSHIFT_ASSIGN)");
		return {};
	}
	Types::assignment_op result;
	::ISPA_STD::assign_compatible(result.value, _0);
	::ISPA_STD::MatchResult<Rules, Types::assignment_op, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::assignment_op<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::assignment_op, ::Parser::Lexer::iterator>;
template auto Parser::Parser::assignment_op<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::assignment_op, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::assignment_suffix(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::assignment_suffix, IT> {
	std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Rules, Types::index_suffix>, ::ISPA_STD::Node<::Parser::Rules, Types::attribute_suffix>> _0;
	bool success_1;
	::ISPA_STD::MatchResult<Rules, Types::attribute_suffix, IT> attribute_suffix_2;
	bool success_3;
	::ISPA_STD::MatchResult<Rules, Types::index_suffix, IT> index_suffix_4;
	bool success_5;
	success_1 = false;
	// grammar `@  ( attribute_suffix |  index_suffix)`: choice; reset match status before selecting an alternative
	success_1 = false;
	auto lookahead_pos_1 = pos;
	switch (static_cast<Tokens>((*lookahead_pos_1).kind())) {
		case Tokens::DOT: {
			lookahead_pos_1 = lookahead_pos_1;
			success_3 = false;
			attribute_suffix_2 = attribute_suffix(lookahead_pos_1);
			if (!(attribute_suffix_2.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  attribute_suffix");
				return {};
			}
			success_3 = true;
			lookahead_pos_1 = attribute_suffix_2.it;
			if (!success_3) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  attribute_suffix");
				return {};
			}
			_0 = attribute_suffix_2.node;
			success_1 = true;
			break;
		}
		case Tokens::LBRACKET: {
			lookahead_pos_1 = lookahead_pos_1;
			success_5 = false;
			index_suffix_4 = index_suffix(lookahead_pos_1);
			if (!(index_suffix_4.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  index_suffix");
				return {};
			}
			success_5 = true;
			lookahead_pos_1 = index_suffix_4.it;
			if (!success_5) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  index_suffix");
				return {};
			}
			_0 = index_suffix_4.node;
			success_1 = true;
			break;
		}
	}
	pos = lookahead_pos_1;
	if (!success_1) {
		raise_error(*pos, "ISPA match failure: no LL(k) alternative matched | grammar: @  ( attribute_suffix |  index_suffix)");
		return {};
	}
	Types::assignment_suffix result;
	::ISPA_STD::assign_compatible(result.value, _0);
	::ISPA_STD::MatchResult<Rules, Types::assignment_suffix, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::assignment_suffix<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::assignment_suffix, ::Parser::Lexer::iterator>;
template auto Parser::Parser::assignment_suffix<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::assignment_suffix, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::assignment_tail(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::assignment_tail, IT> {
	::ISPA_STD::MatchResult<Rules, Types::assignment_op, IT> assignment_op_0;
	bool success_1;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::MatchResult<Rules, Types::expr, IT> expr_4;
	bool success_5;
	success_1 = false;
	assignment_op_0 = assignment_op(pos);
	if (!(assignment_op_0.status)) {
		raise_error(*pos, "ISPA match failure: required named rule did not match | grammar: @  assignment_op");
		return {};
	}
	success_1 = true;
	pos = assignment_op_0.it;
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
	Types::assignment_tail result;
	::ISPA_STD::assign_compatible(result.op, assignment_op_0);
	::ISPA_STD::assign_compatible(result.value, expr_4);
	::ISPA_STD::MatchResult<Rules, Types::assignment_tail, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::assignment_tail<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::assignment_tail, ::Parser::Lexer::iterator>;
template auto Parser::Parser::assignment_tail<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::assignment_tail, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::assignment_target(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::assignment_target, IT> {
	::ISPA_STD::Node<::Parser::Tokens, Types::ID> ID_0;
	bool success_1;
	::ISPA_STD::MatchResult<Rules, Types::assignment_suffix, IT> assignment_suffix_5;
	bool success_6;
	::ISPA_STD::Node<::Parser::Rules, Types::assignment_suffix> element_7;
	std::vector<::ISPA_STD::Node<::Parser::Rules, Types::assignment_suffix>> shadow_8;
	std::vector<::ISPA_STD::Node<::Parser::Rules, Types::assignment_suffix>> uvar_4;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	success_1 = false;
	if (!(((*pos)).template holds<Types::ID>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar: @  ID");
		return {};
	}
	ID_0 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::ID>>();
	success_1 = true;
	pos++;
	success_6 = false;
	// grammar `@  assignment_suffix*;`: repeat named rule; collect every matched value
	while (true) {
		auto repeat_ws_9 = pos;
		success_3 = false;
		if (((*repeat_ws_9)).template holds<Types::__WS>()) {
			__WS_2 = ((*repeat_ws_9)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
			success_3 = true;
			repeat_ws_9++;
		}
		assignment_suffix_5 = assignment_suffix(repeat_ws_9);
		if (!(assignment_suffix_5.status)) {
			break;
		}
		success_6 = true;
		repeat_ws_9 = assignment_suffix_5.it;
		element_7 = assignment_suffix_5.node;
		shadow_8.push_back(element_7);
		pos = repeat_ws_9;
	}
	::ISPA_STD::assign_compatible(uvar_4, shadow_8);
	Types::assignment_target result;
	::ISPA_STD::assign_compatible(result.name, ID_0);
	::ISPA_STD::assign_compatible(result.suffixes, uvar_4);
	::ISPA_STD::MatchResult<Rules, Types::assignment_target, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::assignment_target<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::assignment_target, ::Parser::Lexer::iterator>;
template auto Parser::Parser::assignment_target<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::assignment_target, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::assignment_value(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::assignment_value, IT> {
	std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Rules, Types::annotated_assignment>, ::ISPA_STD::Node<::Parser::Rules, Types::assignment_tail>> _0;
	bool success_1;
	::ISPA_STD::MatchResult<Rules, Types::assignment_tail, IT> assignment_tail_2;
	bool success_3;
	::ISPA_STD::MatchResult<Rules, Types::assignment_tail, IT> assignment_tail_4;
	bool success_5;
	::ISPA_STD::MatchResult<Rules, Types::assignment_tail, IT> assignment_tail_6;
	bool success_7;
	::ISPA_STD::MatchResult<Rules, Types::annotated_assignment, IT> annotated_assignment_8;
	bool success_9;
	::ISPA_STD::MatchResult<Rules, Types::assignment_tail, IT> assignment_tail_10;
	bool success_11;
	::ISPA_STD::MatchResult<Rules, Types::assignment_tail, IT> assignment_tail_12;
	bool success_13;
	::ISPA_STD::MatchResult<Rules, Types::assignment_tail, IT> assignment_tail_14;
	bool success_15;
	::ISPA_STD::MatchResult<Rules, Types::assignment_tail, IT> assignment_tail_16;
	bool success_17;
	::ISPA_STD::MatchResult<Rules, Types::assignment_tail, IT> assignment_tail_18;
	bool success_19;
	::ISPA_STD::MatchResult<Rules, Types::assignment_tail, IT> assignment_tail_20;
	bool success_21;
	::ISPA_STD::MatchResult<Rules, Types::assignment_tail, IT> assignment_tail_22;
	bool success_23;
	::ISPA_STD::MatchResult<Rules, Types::assignment_tail, IT> assignment_tail_24;
	bool success_25;
	::ISPA_STD::MatchResult<Rules, Types::assignment_tail, IT> assignment_tail_26;
	bool success_27;
	::ISPA_STD::MatchResult<Rules, Types::assignment_tail, IT> assignment_tail_28;
	bool success_29;
	::ISPA_STD::MatchResult<Rules, Types::assignment_tail, IT> assignment_tail_30;
	bool success_31;
	success_1 = false;
	// grammar `@  ( assignment_tail |  annotated_assignment)`: choice; reset match status before selecting an alternative
	success_1 = false;
	auto lookahead_pos_1 = pos;
	switch (static_cast<Tokens>((*lookahead_pos_1).kind())) {
		case Tokens::AMP_ASSIGN: {
			lookahead_pos_1 = lookahead_pos_1;
			success_3 = false;
			assignment_tail_2 = assignment_tail(lookahead_pos_1);
			if (!(assignment_tail_2.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  assignment_tail");
				return {};
			}
			success_3 = true;
			lookahead_pos_1 = assignment_tail_2.it;
			if (!success_3) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  assignment_tail");
				return {};
			}
			_0 = assignment_tail_2.node;
			success_1 = true;
			break;
		}
		case Tokens::ASSIGN: {
			lookahead_pos_1 = lookahead_pos_1;
			success_5 = false;
			assignment_tail_4 = assignment_tail(lookahead_pos_1);
			if (!(assignment_tail_4.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  assignment_tail");
				return {};
			}
			success_5 = true;
			lookahead_pos_1 = assignment_tail_4.it;
			if (!success_5) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  assignment_tail");
				return {};
			}
			_0 = assignment_tail_4.node;
			success_1 = true;
			break;
		}
		case Tokens::CARET_ASSIGN: {
			lookahead_pos_1 = lookahead_pos_1;
			success_7 = false;
			assignment_tail_6 = assignment_tail(lookahead_pos_1);
			if (!(assignment_tail_6.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  assignment_tail");
				return {};
			}
			success_7 = true;
			lookahead_pos_1 = assignment_tail_6.it;
			if (!success_7) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  assignment_tail");
				return {};
			}
			_0 = assignment_tail_6.node;
			success_1 = true;
			break;
		}
		case Tokens::COLON: {
			lookahead_pos_1 = lookahead_pos_1;
			success_9 = false;
			annotated_assignment_8 = annotated_assignment(lookahead_pos_1);
			if (!(annotated_assignment_8.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  annotated_assignment");
				return {};
			}
			success_9 = true;
			lookahead_pos_1 = annotated_assignment_8.it;
			if (!success_9) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  annotated_assignment");
				return {};
			}
			_0 = annotated_assignment_8.node;
			success_1 = true;
			break;
		}
		case Tokens::FLOOR_DIV_ASSIGN: {
			lookahead_pos_1 = lookahead_pos_1;
			success_11 = false;
			assignment_tail_10 = assignment_tail(lookahead_pos_1);
			if (!(assignment_tail_10.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  assignment_tail");
				return {};
			}
			success_11 = true;
			lookahead_pos_1 = assignment_tail_10.it;
			if (!success_11) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  assignment_tail");
				return {};
			}
			_0 = assignment_tail_10.node;
			success_1 = true;
			break;
		}
		case Tokens::LSHIFT_ASSIGN: {
			lookahead_pos_1 = lookahead_pos_1;
			success_13 = false;
			assignment_tail_12 = assignment_tail(lookahead_pos_1);
			if (!(assignment_tail_12.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  assignment_tail");
				return {};
			}
			success_13 = true;
			lookahead_pos_1 = assignment_tail_12.it;
			if (!success_13) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  assignment_tail");
				return {};
			}
			_0 = assignment_tail_12.node;
			success_1 = true;
			break;
		}
		case Tokens::MATMUL_ASSIGN: {
			lookahead_pos_1 = lookahead_pos_1;
			success_15 = false;
			assignment_tail_14 = assignment_tail(lookahead_pos_1);
			if (!(assignment_tail_14.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  assignment_tail");
				return {};
			}
			success_15 = true;
			lookahead_pos_1 = assignment_tail_14.it;
			if (!success_15) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  assignment_tail");
				return {};
			}
			_0 = assignment_tail_14.node;
			success_1 = true;
			break;
		}
		case Tokens::MINUS_ASSIGN: {
			lookahead_pos_1 = lookahead_pos_1;
			success_17 = false;
			assignment_tail_16 = assignment_tail(lookahead_pos_1);
			if (!(assignment_tail_16.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  assignment_tail");
				return {};
			}
			success_17 = true;
			lookahead_pos_1 = assignment_tail_16.it;
			if (!success_17) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  assignment_tail");
				return {};
			}
			_0 = assignment_tail_16.node;
			success_1 = true;
			break;
		}
		case Tokens::PERCENT_ASSIGN: {
			lookahead_pos_1 = lookahead_pos_1;
			success_19 = false;
			assignment_tail_18 = assignment_tail(lookahead_pos_1);
			if (!(assignment_tail_18.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  assignment_tail");
				return {};
			}
			success_19 = true;
			lookahead_pos_1 = assignment_tail_18.it;
			if (!success_19) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  assignment_tail");
				return {};
			}
			_0 = assignment_tail_18.node;
			success_1 = true;
			break;
		}
		case Tokens::PIPE_ASSIGN: {
			lookahead_pos_1 = lookahead_pos_1;
			success_21 = false;
			assignment_tail_20 = assignment_tail(lookahead_pos_1);
			if (!(assignment_tail_20.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  assignment_tail");
				return {};
			}
			success_21 = true;
			lookahead_pos_1 = assignment_tail_20.it;
			if (!success_21) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  assignment_tail");
				return {};
			}
			_0 = assignment_tail_20.node;
			success_1 = true;
			break;
		}
		case Tokens::PLUS_ASSIGN: {
			lookahead_pos_1 = lookahead_pos_1;
			success_23 = false;
			assignment_tail_22 = assignment_tail(lookahead_pos_1);
			if (!(assignment_tail_22.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  assignment_tail");
				return {};
			}
			success_23 = true;
			lookahead_pos_1 = assignment_tail_22.it;
			if (!success_23) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  assignment_tail");
				return {};
			}
			_0 = assignment_tail_22.node;
			success_1 = true;
			break;
		}
		case Tokens::POWER_ASSIGN: {
			lookahead_pos_1 = lookahead_pos_1;
			success_25 = false;
			assignment_tail_24 = assignment_tail(lookahead_pos_1);
			if (!(assignment_tail_24.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  assignment_tail");
				return {};
			}
			success_25 = true;
			lookahead_pos_1 = assignment_tail_24.it;
			if (!success_25) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  assignment_tail");
				return {};
			}
			_0 = assignment_tail_24.node;
			success_1 = true;
			break;
		}
		case Tokens::RSHIFT_ASSIGN: {
			lookahead_pos_1 = lookahead_pos_1;
			success_27 = false;
			assignment_tail_26 = assignment_tail(lookahead_pos_1);
			if (!(assignment_tail_26.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  assignment_tail");
				return {};
			}
			success_27 = true;
			lookahead_pos_1 = assignment_tail_26.it;
			if (!success_27) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  assignment_tail");
				return {};
			}
			_0 = assignment_tail_26.node;
			success_1 = true;
			break;
		}
		case Tokens::SLASH_ASSIGN: {
			lookahead_pos_1 = lookahead_pos_1;
			success_29 = false;
			assignment_tail_28 = assignment_tail(lookahead_pos_1);
			if (!(assignment_tail_28.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  assignment_tail");
				return {};
			}
			success_29 = true;
			lookahead_pos_1 = assignment_tail_28.it;
			if (!success_29) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  assignment_tail");
				return {};
			}
			_0 = assignment_tail_28.node;
			success_1 = true;
			break;
		}
		case Tokens::STAR_ASSIGN: {
			lookahead_pos_1 = lookahead_pos_1;
			success_31 = false;
			assignment_tail_30 = assignment_tail(lookahead_pos_1);
			if (!(assignment_tail_30.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  assignment_tail");
				return {};
			}
			success_31 = true;
			lookahead_pos_1 = assignment_tail_30.it;
			if (!success_31) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  assignment_tail");
				return {};
			}
			_0 = assignment_tail_30.node;
			success_1 = true;
			break;
		}
	}
	pos = lookahead_pos_1;
	if (!success_1) {
		raise_error(*pos, "ISPA match failure: no LL(k) alternative matched | grammar: @  ( assignment_tail |  annotated_assignment)");
		return {};
	}
	Types::assignment_value result;
	::ISPA_STD::assign_compatible(result.value, _0);
	::ISPA_STD::MatchResult<Rules, Types::assignment_value, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::assignment_value<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::assignment_value, ::Parser::Lexer::iterator>;
template auto Parser::Parser::assignment_value<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::assignment_value, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::atom(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::atom, IT> {
	std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Rules, Types::list_expr>, ::ISPA_STD::Node<::Parser::Tokens, Types::NONE_V>, ::ISPA_STD::Node<::Parser::Tokens, Types::FALSE>, ::ISPA_STD::Node<::Parser::Tokens, Types::TRUE>, ::ISPA_STD::Node<::Parser::Rules, Types::dict_expr>, ::ISPA_STD::Node<::Parser::Rules, Types::parenthesized_expr>, ::ISPA_STD::Node<::Parser::Tokens, Types::NUMBER>, ::ISPA_STD::Node<::Parser::Tokens, Types::STRING>, ::ISPA_STD::Node<::Parser::Tokens, Types::ID>> _0;
	bool success_1;
	::ISPA_STD::Node<::Parser::Tokens, Types::FALSE> FALSE_2;
	bool success_3;
	::ISPA_STD::Node<::Parser::Tokens, Types::ID> ID_4;
	bool success_5;
	::ISPA_STD::MatchResult<Rules, Types::dict_expr, IT> dict_expr_6;
	bool success_7;
	::ISPA_STD::MatchResult<Rules, Types::list_expr, IT> list_expr_8;
	bool success_9;
	::ISPA_STD::MatchResult<Rules, Types::parenthesized_expr, IT> parenthesized_expr_10;
	bool success_11;
	::ISPA_STD::Node<::Parser::Tokens, Types::NONE_V> NONE_V_12;
	bool success_13;
	::ISPA_STD::Node<::Parser::Tokens, Types::NUMBER> NUMBER_14;
	bool success_15;
	::ISPA_STD::Node<::Parser::Tokens, Types::STRING> STRING_16;
	bool success_17;
	::ISPA_STD::Node<::Parser::Tokens, Types::TRUE> TRUE_18;
	bool success_19;
	success_1 = false;
	// grammar `@  ( ID |  NUMBER |  STRING |  TRUE |  FALSE |  NONE_V |  parenthesized_expr |  list_expr |  dict_expr)`: choice; reset match status before selecting an alternative
	success_1 = false;
	auto lookahead_pos_1 = pos;
	switch (static_cast<Tokens>((*lookahead_pos_1).kind())) {
		case Tokens::FALSE: {
			lookahead_pos_1 = lookahead_pos_1;
			success_3 = false;
			if (!(((*lookahead_pos_1)).template holds<Types::FALSE>())) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  FALSE");
				return {};
			}
			FALSE_2 = ((*lookahead_pos_1)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::FALSE>>();
			success_3 = true;
			lookahead_pos_1++;
			if (!success_3) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  FALSE");
				return {};
			}
			_0 = FALSE_2;
			success_1 = true;
			break;
		}
		case Tokens::ID: {
			lookahead_pos_1 = lookahead_pos_1;
			success_5 = false;
			if (!(((*lookahead_pos_1)).template holds<Types::ID>())) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  ID");
				return {};
			}
			ID_4 = ((*lookahead_pos_1)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::ID>>();
			success_5 = true;
			lookahead_pos_1++;
			if (!success_5) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  ID");
				return {};
			}
			_0 = ID_4;
			success_1 = true;
			break;
		}
		case Tokens::LBRACE: {
			lookahead_pos_1 = lookahead_pos_1;
			success_7 = false;
			dict_expr_6 = dict_expr(lookahead_pos_1);
			if (!(dict_expr_6.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  dict_expr");
				return {};
			}
			success_7 = true;
			lookahead_pos_1 = dict_expr_6.it;
			if (!success_7) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  dict_expr");
				return {};
			}
			_0 = dict_expr_6.node;
			success_1 = true;
			break;
		}
		case Tokens::LBRACKET: {
			lookahead_pos_1 = lookahead_pos_1;
			success_9 = false;
			list_expr_8 = list_expr(lookahead_pos_1);
			if (!(list_expr_8.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  list_expr");
				return {};
			}
			success_9 = true;
			lookahead_pos_1 = list_expr_8.it;
			if (!success_9) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  list_expr");
				return {};
			}
			_0 = list_expr_8.node;
			success_1 = true;
			break;
		}
		case Tokens::LPAREN: {
			lookahead_pos_1 = lookahead_pos_1;
			success_11 = false;
			parenthesized_expr_10 = parenthesized_expr(lookahead_pos_1);
			if (!(parenthesized_expr_10.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  parenthesized_expr");
				return {};
			}
			success_11 = true;
			lookahead_pos_1 = parenthesized_expr_10.it;
			if (!success_11) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  parenthesized_expr");
				return {};
			}
			_0 = parenthesized_expr_10.node;
			success_1 = true;
			break;
		}
		case Tokens::NONE_V: {
			lookahead_pos_1 = lookahead_pos_1;
			success_13 = false;
			if (!(((*lookahead_pos_1)).template holds<Types::NONE_V>())) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  NONE_V");
				return {};
			}
			NONE_V_12 = ((*lookahead_pos_1)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::NONE_V>>();
			success_13 = true;
			lookahead_pos_1++;
			if (!success_13) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  NONE_V");
				return {};
			}
			_0 = NONE_V_12;
			success_1 = true;
			break;
		}
		case Tokens::NUMBER: {
			lookahead_pos_1 = lookahead_pos_1;
			success_15 = false;
			if (!(((*lookahead_pos_1)).template holds<Types::NUMBER>())) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  NUMBER");
				return {};
			}
			NUMBER_14 = ((*lookahead_pos_1)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::NUMBER>>();
			success_15 = true;
			lookahead_pos_1++;
			if (!success_15) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  NUMBER");
				return {};
			}
			_0 = NUMBER_14;
			success_1 = true;
			break;
		}
		case Tokens::STRING: {
			lookahead_pos_1 = lookahead_pos_1;
			success_17 = false;
			if (!(((*lookahead_pos_1)).template holds<Types::STRING>())) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  STRING");
				return {};
			}
			STRING_16 = ((*lookahead_pos_1)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::STRING>>();
			success_17 = true;
			lookahead_pos_1++;
			if (!success_17) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  STRING");
				return {};
			}
			_0 = STRING_16;
			success_1 = true;
			break;
		}
		case Tokens::TRUE: {
			lookahead_pos_1 = lookahead_pos_1;
			success_19 = false;
			if (!(((*lookahead_pos_1)).template holds<Types::TRUE>())) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  TRUE");
				return {};
			}
			TRUE_18 = ((*lookahead_pos_1)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::TRUE>>();
			success_19 = true;
			lookahead_pos_1++;
			if (!success_19) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  TRUE");
				return {};
			}
			_0 = TRUE_18;
			success_1 = true;
			break;
		}
	}
	pos = lookahead_pos_1;
	if (!success_1) {
		raise_error(*pos, "ISPA match failure: no LL(k) alternative matched | grammar: @  ( ID |  NUMBER |  STRING |  TRUE |  FALSE |  NONE_V |  parenthesized_expr |  list_expr |  dict_expr)");
		return {};
	}
	Types::atom result;
	::ISPA_STD::assign_compatible(result.value, _0);
	::ISPA_STD::MatchResult<Rules, Types::atom, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::atom<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::atom, ::Parser::Lexer::iterator>;
template auto Parser::Parser::atom<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::atom, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::attribute_suffix(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::attribute_suffix, IT> {
	::ISPA_STD::Node<::Parser::Tokens, Types::DOT> DOT_0;
	bool success_1;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::Node<::Parser::Tokens, Types::ID> ID_4;
	bool success_5;
	success_1 = false;
	if (!(((*pos)).template holds<Types::DOT>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  DOT");
		return {};
	}
	DOT_0 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::DOT>>();
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
	Types::attribute_suffix result;
	::ISPA_STD::assign_compatible(result.value, ID_4);
	::ISPA_STD::MatchResult<Rules, Types::attribute_suffix, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::attribute_suffix<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::attribute_suffix, ::Parser::Lexer::iterator>;
template auto Parser::Parser::attribute_suffix<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::attribute_suffix, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::bitand_tail(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::bitand_tail, IT> {
	::ISPA_STD::Node<::Parser::Tokens, Types::AMP> AMP_0;
	bool success_1;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::MatchResult<Rules, Types::shift_expr, IT> shift_expr_4;
	bool success_5;
	success_1 = false;
	if (!(((*pos)).template holds<Types::AMP>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  AMP");
		return {};
	}
	AMP_0 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::AMP>>();
	success_1 = true;
	pos++;
	success_3 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_2 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_3 = true;
		pos++;
	}
	success_5 = false;
	shift_expr_4 = shift_expr(pos);
	if (!(shift_expr_4.status)) {
		raise_error(*pos, "ISPA match failure: required named rule did not match | grammar: @  shift_expr");
		return {};
	}
	success_5 = true;
	pos = shift_expr_4.it;
	Types::bitand_tail result;
	::ISPA_STD::assign_compatible(result.value, shift_expr_4.node);
	::ISPA_STD::MatchResult<Rules, Types::bitand_tail, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::bitand_tail<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::bitand_tail, ::Parser::Lexer::iterator>;
template auto Parser::Parser::bitand_tail<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::bitand_tail, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::bitor_tail(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::bitor_tail, IT> {
	::ISPA_STD::Node<::Parser::Tokens, Types::PIPE> PIPE_0;
	bool success_1;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::MatchResult<Rules, Types::bitwise_xor, IT> bitwise_xor_4;
	bool success_5;
	success_1 = false;
	if (!(((*pos)).template holds<Types::PIPE>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  PIPE");
		return {};
	}
	PIPE_0 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::PIPE>>();
	success_1 = true;
	pos++;
	success_3 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_2 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_3 = true;
		pos++;
	}
	success_5 = false;
	bitwise_xor_4 = bitwise_xor(pos);
	if (!(bitwise_xor_4.status)) {
		raise_error(*pos, "ISPA match failure: required named rule did not match | grammar: @  bitwise_xor");
		return {};
	}
	success_5 = true;
	pos = bitwise_xor_4.it;
	Types::bitor_tail result;
	::ISPA_STD::assign_compatible(result.value, bitwise_xor_4.node);
	::ISPA_STD::MatchResult<Rules, Types::bitor_tail, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::bitor_tail<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::bitor_tail, ::Parser::Lexer::iterator>;
template auto Parser::Parser::bitor_tail<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::bitor_tail, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::bitwise_and(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::bitwise_and, IT> {
	::ISPA_STD::MatchResult<Rules, Types::shift_expr, IT> shift_expr_0;
	bool success_1;
	::ISPA_STD::MatchResult<Rules, Types::bitand_tail, IT> bitand_tail_5;
	bool success_6;
	::ISPA_STD::Node<::Parser::Rules, Types::bitand_tail> element_7;
	std::vector<::ISPA_STD::Node<::Parser::Rules, Types::bitand_tail>> shadow_8;
	std::vector<::ISPA_STD::Node<::Parser::Rules, Types::bitand_tail>> uvar_4;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	success_1 = false;
	shift_expr_0 = shift_expr(pos);
	if (!(shift_expr_0.status)) {
		raise_error(*pos, "ISPA match failure: required named rule did not match | grammar: @  shift_expr");
		return {};
	}
	success_1 = true;
	pos = shift_expr_0.it;
	success_6 = false;
	// grammar `@  bitand_tail*;`: repeat named rule; collect every matched value
	while (true) {
		auto repeat_ws_9 = pos;
		success_3 = false;
		if (((*repeat_ws_9)).template holds<Types::__WS>()) {
			__WS_2 = ((*repeat_ws_9)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
			success_3 = true;
			repeat_ws_9++;
		}
		bitand_tail_5 = bitand_tail(repeat_ws_9);
		if (!(bitand_tail_5.status)) {
			break;
		}
		success_6 = true;
		repeat_ws_9 = bitand_tail_5.it;
		element_7 = bitand_tail_5.node;
		shadow_8.push_back(element_7);
		pos = repeat_ws_9;
	}
	::ISPA_STD::assign_compatible(uvar_4, shadow_8);
	Types::bitwise_and result;
	::ISPA_STD::assign_compatible(result.first, shift_expr_0);
	::ISPA_STD::assign_compatible(result.rest, uvar_4);
	::ISPA_STD::MatchResult<Rules, Types::bitwise_and, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::bitwise_and<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::bitwise_and, ::Parser::Lexer::iterator>;
template auto Parser::Parser::bitwise_and<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::bitwise_and, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::bitwise_or(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::bitwise_or, IT> {
	::ISPA_STD::MatchResult<Rules, Types::bitwise_xor, IT> bitwise_xor_0;
	bool success_1;
	::ISPA_STD::MatchResult<Rules, Types::bitor_tail, IT> bitor_tail_5;
	bool success_6;
	::ISPA_STD::Node<::Parser::Rules, Types::bitor_tail> element_7;
	std::vector<::ISPA_STD::Node<::Parser::Rules, Types::bitor_tail>> shadow_8;
	std::vector<::ISPA_STD::Node<::Parser::Rules, Types::bitor_tail>> uvar_4;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	success_1 = false;
	bitwise_xor_0 = bitwise_xor(pos);
	if (!(bitwise_xor_0.status)) {
		raise_error(*pos, "ISPA match failure: required named rule did not match | grammar: @  bitwise_xor");
		return {};
	}
	success_1 = true;
	pos = bitwise_xor_0.it;
	success_6 = false;
	// grammar `@  bitor_tail*;`: repeat named rule; collect every matched value
	while (true) {
		auto repeat_ws_9 = pos;
		success_3 = false;
		if (((*repeat_ws_9)).template holds<Types::__WS>()) {
			__WS_2 = ((*repeat_ws_9)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
			success_3 = true;
			repeat_ws_9++;
		}
		bitor_tail_5 = bitor_tail(repeat_ws_9);
		if (!(bitor_tail_5.status)) {
			break;
		}
		success_6 = true;
		repeat_ws_9 = bitor_tail_5.it;
		element_7 = bitor_tail_5.node;
		shadow_8.push_back(element_7);
		pos = repeat_ws_9;
	}
	::ISPA_STD::assign_compatible(uvar_4, shadow_8);
	Types::bitwise_or result;
	::ISPA_STD::assign_compatible(result.first, bitwise_xor_0);
	::ISPA_STD::assign_compatible(result.rest, uvar_4);
	::ISPA_STD::MatchResult<Rules, Types::bitwise_or, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::bitwise_or<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::bitwise_or, ::Parser::Lexer::iterator>;
template auto Parser::Parser::bitwise_or<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::bitwise_or, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::bitwise_xor(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::bitwise_xor, IT> {
	::ISPA_STD::MatchResult<Rules, Types::bitwise_and, IT> bitwise_and_0;
	bool success_1;
	::ISPA_STD::MatchResult<Rules, Types::bitxor_tail, IT> bitxor_tail_5;
	bool success_6;
	::ISPA_STD::Node<::Parser::Rules, Types::bitxor_tail> element_7;
	std::vector<::ISPA_STD::Node<::Parser::Rules, Types::bitxor_tail>> shadow_8;
	std::vector<::ISPA_STD::Node<::Parser::Rules, Types::bitxor_tail>> uvar_4;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	success_1 = false;
	bitwise_and_0 = bitwise_and(pos);
	if (!(bitwise_and_0.status)) {
		raise_error(*pos, "ISPA match failure: required named rule did not match | grammar: @  bitwise_and");
		return {};
	}
	success_1 = true;
	pos = bitwise_and_0.it;
	success_6 = false;
	// grammar `@  bitxor_tail*;`: repeat named rule; collect every matched value
	while (true) {
		auto repeat_ws_9 = pos;
		success_3 = false;
		if (((*repeat_ws_9)).template holds<Types::__WS>()) {
			__WS_2 = ((*repeat_ws_9)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
			success_3 = true;
			repeat_ws_9++;
		}
		bitxor_tail_5 = bitxor_tail(repeat_ws_9);
		if (!(bitxor_tail_5.status)) {
			break;
		}
		success_6 = true;
		repeat_ws_9 = bitxor_tail_5.it;
		element_7 = bitxor_tail_5.node;
		shadow_8.push_back(element_7);
		pos = repeat_ws_9;
	}
	::ISPA_STD::assign_compatible(uvar_4, shadow_8);
	Types::bitwise_xor result;
	::ISPA_STD::assign_compatible(result.first, bitwise_and_0);
	::ISPA_STD::assign_compatible(result.rest, uvar_4);
	::ISPA_STD::MatchResult<Rules, Types::bitwise_xor, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::bitwise_xor<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::bitwise_xor, ::Parser::Lexer::iterator>;
template auto Parser::Parser::bitwise_xor<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::bitwise_xor, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::bitxor_tail(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::bitxor_tail, IT> {
	::ISPA_STD::Node<::Parser::Tokens, Types::CARET> CARET_0;
	bool success_1;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::MatchResult<Rules, Types::bitwise_and, IT> bitwise_and_4;
	bool success_5;
	success_1 = false;
	if (!(((*pos)).template holds<Types::CARET>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  CARET");
		return {};
	}
	CARET_0 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::CARET>>();
	success_1 = true;
	pos++;
	success_3 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_2 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_3 = true;
		pos++;
	}
	success_5 = false;
	bitwise_and_4 = bitwise_and(pos);
	if (!(bitwise_and_4.status)) {
		raise_error(*pos, "ISPA match failure: required named rule did not match | grammar: @  bitwise_and");
		return {};
	}
	success_5 = true;
	pos = bitwise_and_4.it;
	Types::bitxor_tail result;
	::ISPA_STD::assign_compatible(result.value, bitwise_and_4.node);
	::ISPA_STD::MatchResult<Rules, Types::bitxor_tail, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::bitxor_tail<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::bitxor_tail, ::Parser::Lexer::iterator>;
template auto Parser::Parser::bitxor_tail<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::bitxor_tail, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::block(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::block, IT> {
	std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Rules, Types::simple_stmts>, ::ISPA_STD::Node<::Parser::Rules, Types::indented_block>> _0;
	bool success_1;
	::ISPA_STD::MatchResult<Rules, Types::simple_stmts, IT> simple_stmts_2;
	bool success_3;
	::ISPA_STD::MatchResult<Rules, Types::simple_stmts, IT> simple_stmts_4;
	bool success_5;
	::ISPA_STD::MatchResult<Rules, Types::simple_stmts, IT> simple_stmts_6;
	bool success_7;
	::ISPA_STD::MatchResult<Rules, Types::simple_stmts, IT> simple_stmts_8;
	bool success_9;
	::ISPA_STD::MatchResult<Rules, Types::simple_stmts, IT> simple_stmts_10;
	bool success_11;
	::ISPA_STD::MatchResult<Rules, Types::simple_stmts, IT> simple_stmts_12;
	bool success_13;
	::ISPA_STD::MatchResult<Rules, Types::simple_stmts, IT> simple_stmts_14;
	bool success_15;
	::ISPA_STD::MatchResult<Rules, Types::simple_stmts, IT> simple_stmts_16;
	bool success_17;
	::ISPA_STD::MatchResult<Rules, Types::simple_stmts, IT> simple_stmts_18;
	bool success_19;
	::ISPA_STD::MatchResult<Rules, Types::simple_stmts, IT> simple_stmts_20;
	bool success_21;
	::ISPA_STD::MatchResult<Rules, Types::simple_stmts, IT> simple_stmts_22;
	bool success_23;
	::ISPA_STD::MatchResult<Rules, Types::simple_stmts, IT> simple_stmts_24;
	bool success_25;
	::ISPA_STD::MatchResult<Rules, Types::simple_stmts, IT> simple_stmts_26;
	bool success_27;
	::ISPA_STD::MatchResult<Rules, Types::indented_block, IT> indented_block_28;
	bool success_29;
	::ISPA_STD::MatchResult<Rules, Types::simple_stmts, IT> simple_stmts_30;
	bool success_31;
	::ISPA_STD::MatchResult<Rules, Types::simple_stmts, IT> simple_stmts_32;
	bool success_33;
	::ISPA_STD::MatchResult<Rules, Types::simple_stmts, IT> simple_stmts_34;
	bool success_35;
	::ISPA_STD::MatchResult<Rules, Types::simple_stmts, IT> simple_stmts_36;
	bool success_37;
	::ISPA_STD::MatchResult<Rules, Types::simple_stmts, IT> simple_stmts_38;
	bool success_39;
	::ISPA_STD::MatchResult<Rules, Types::simple_stmts, IT> simple_stmts_40;
	bool success_41;
	::ISPA_STD::MatchResult<Rules, Types::simple_stmts, IT> simple_stmts_42;
	bool success_43;
	::ISPA_STD::MatchResult<Rules, Types::simple_stmts, IT> simple_stmts_44;
	bool success_45;
	::ISPA_STD::MatchResult<Rules, Types::simple_stmts, IT> simple_stmts_46;
	bool success_47;
	::ISPA_STD::MatchResult<Rules, Types::simple_stmts, IT> simple_stmts_48;
	bool success_49;
	::ISPA_STD::MatchResult<Rules, Types::simple_stmts, IT> simple_stmts_50;
	bool success_51;
	success_1 = false;
	// grammar `@  ( indented_block |  simple_stmts)`: choice; reset match status before selecting an alternative
	success_1 = false;
	auto lookahead_pos_1 = pos;
	switch (static_cast<Tokens>((*lookahead_pos_1).kind())) {
		case Tokens::ASSERT: {
			lookahead_pos_1 = lookahead_pos_1;
			success_3 = false;
			simple_stmts_2 = simple_stmts(lookahead_pos_1);
			if (!(simple_stmts_2.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  simple_stmts");
				return {};
			}
			success_3 = true;
			lookahead_pos_1 = simple_stmts_2.it;
			if (!success_3) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  simple_stmts");
				return {};
			}
			_0 = simple_stmts_2.node;
			success_1 = true;
			break;
		}
		case Tokens::BREAK: {
			lookahead_pos_1 = lookahead_pos_1;
			success_5 = false;
			simple_stmts_4 = simple_stmts(lookahead_pos_1);
			if (!(simple_stmts_4.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  simple_stmts");
				return {};
			}
			success_5 = true;
			lookahead_pos_1 = simple_stmts_4.it;
			if (!success_5) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  simple_stmts");
				return {};
			}
			_0 = simple_stmts_4.node;
			success_1 = true;
			break;
		}
		case Tokens::CONTINUE: {
			lookahead_pos_1 = lookahead_pos_1;
			success_7 = false;
			simple_stmts_6 = simple_stmts(lookahead_pos_1);
			if (!(simple_stmts_6.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  simple_stmts");
				return {};
			}
			success_7 = true;
			lookahead_pos_1 = simple_stmts_6.it;
			if (!success_7) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  simple_stmts");
				return {};
			}
			_0 = simple_stmts_6.node;
			success_1 = true;
			break;
		}
		case Tokens::DEL: {
			lookahead_pos_1 = lookahead_pos_1;
			success_9 = false;
			simple_stmts_8 = simple_stmts(lookahead_pos_1);
			if (!(simple_stmts_8.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  simple_stmts");
				return {};
			}
			success_9 = true;
			lookahead_pos_1 = simple_stmts_8.it;
			if (!success_9) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  simple_stmts");
				return {};
			}
			_0 = simple_stmts_8.node;
			success_1 = true;
			break;
		}
		case Tokens::FALSE: {
			lookahead_pos_1 = lookahead_pos_1;
			success_11 = false;
			simple_stmts_10 = simple_stmts(lookahead_pos_1);
			if (!(simple_stmts_10.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  simple_stmts");
				return {};
			}
			success_11 = true;
			lookahead_pos_1 = simple_stmts_10.it;
			if (!success_11) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  simple_stmts");
				return {};
			}
			_0 = simple_stmts_10.node;
			success_1 = true;
			break;
		}
		case Tokens::FROM: {
			lookahead_pos_1 = lookahead_pos_1;
			success_13 = false;
			simple_stmts_12 = simple_stmts(lookahead_pos_1);
			if (!(simple_stmts_12.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  simple_stmts");
				return {};
			}
			success_13 = true;
			lookahead_pos_1 = simple_stmts_12.it;
			if (!success_13) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  simple_stmts");
				return {};
			}
			_0 = simple_stmts_12.node;
			success_1 = true;
			break;
		}
		case Tokens::GLOBAL: {
			lookahead_pos_1 = lookahead_pos_1;
			success_15 = false;
			simple_stmts_14 = simple_stmts(lookahead_pos_1);
			if (!(simple_stmts_14.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  simple_stmts");
				return {};
			}
			success_15 = true;
			lookahead_pos_1 = simple_stmts_14.it;
			if (!success_15) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  simple_stmts");
				return {};
			}
			_0 = simple_stmts_14.node;
			success_1 = true;
			break;
		}
		case Tokens::ID: {
			lookahead_pos_1 = lookahead_pos_1;
			success_17 = false;
			simple_stmts_16 = simple_stmts(lookahead_pos_1);
			if (!(simple_stmts_16.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  simple_stmts");
				return {};
			}
			success_17 = true;
			lookahead_pos_1 = simple_stmts_16.it;
			if (!success_17) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  simple_stmts");
				return {};
			}
			_0 = simple_stmts_16.node;
			success_1 = true;
			break;
		}
		case Tokens::IMPORT: {
			lookahead_pos_1 = lookahead_pos_1;
			success_19 = false;
			simple_stmts_18 = simple_stmts(lookahead_pos_1);
			if (!(simple_stmts_18.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  simple_stmts");
				return {};
			}
			success_19 = true;
			lookahead_pos_1 = simple_stmts_18.it;
			if (!success_19) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  simple_stmts");
				return {};
			}
			_0 = simple_stmts_18.node;
			success_1 = true;
			break;
		}
		case Tokens::LBRACE: {
			lookahead_pos_1 = lookahead_pos_1;
			success_21 = false;
			simple_stmts_20 = simple_stmts(lookahead_pos_1);
			if (!(simple_stmts_20.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  simple_stmts");
				return {};
			}
			success_21 = true;
			lookahead_pos_1 = simple_stmts_20.it;
			if (!success_21) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  simple_stmts");
				return {};
			}
			_0 = simple_stmts_20.node;
			success_1 = true;
			break;
		}
		case Tokens::LBRACKET: {
			lookahead_pos_1 = lookahead_pos_1;
			success_23 = false;
			simple_stmts_22 = simple_stmts(lookahead_pos_1);
			if (!(simple_stmts_22.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  simple_stmts");
				return {};
			}
			success_23 = true;
			lookahead_pos_1 = simple_stmts_22.it;
			if (!success_23) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  simple_stmts");
				return {};
			}
			_0 = simple_stmts_22.node;
			success_1 = true;
			break;
		}
		case Tokens::LPAREN: {
			lookahead_pos_1 = lookahead_pos_1;
			success_25 = false;
			simple_stmts_24 = simple_stmts(lookahead_pos_1);
			if (!(simple_stmts_24.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  simple_stmts");
				return {};
			}
			success_25 = true;
			lookahead_pos_1 = simple_stmts_24.it;
			if (!success_25) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  simple_stmts");
				return {};
			}
			_0 = simple_stmts_24.node;
			success_1 = true;
			break;
		}
		case Tokens::MINUS: {
			lookahead_pos_1 = lookahead_pos_1;
			success_27 = false;
			simple_stmts_26 = simple_stmts(lookahead_pos_1);
			if (!(simple_stmts_26.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  simple_stmts");
				return {};
			}
			success_27 = true;
			lookahead_pos_1 = simple_stmts_26.it;
			if (!success_27) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  simple_stmts");
				return {};
			}
			_0 = simple_stmts_26.node;
			success_1 = true;
			break;
		}
		case Tokens::NEWLINE: {
			lookahead_pos_1 = lookahead_pos_1;
			success_29 = false;
			indented_block_28 = indented_block(lookahead_pos_1);
			if (!(indented_block_28.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  indented_block");
				return {};
			}
			success_29 = true;
			lookahead_pos_1 = indented_block_28.it;
			if (!success_29) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  indented_block");
				return {};
			}
			_0 = indented_block_28.node;
			success_1 = true;
			break;
		}
		case Tokens::NONE_V: {
			lookahead_pos_1 = lookahead_pos_1;
			success_31 = false;
			simple_stmts_30 = simple_stmts(lookahead_pos_1);
			if (!(simple_stmts_30.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  simple_stmts");
				return {};
			}
			success_31 = true;
			lookahead_pos_1 = simple_stmts_30.it;
			if (!success_31) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  simple_stmts");
				return {};
			}
			_0 = simple_stmts_30.node;
			success_1 = true;
			break;
		}
		case Tokens::NONLOCAL: {
			lookahead_pos_1 = lookahead_pos_1;
			success_33 = false;
			simple_stmts_32 = simple_stmts(lookahead_pos_1);
			if (!(simple_stmts_32.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  simple_stmts");
				return {};
			}
			success_33 = true;
			lookahead_pos_1 = simple_stmts_32.it;
			if (!success_33) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  simple_stmts");
				return {};
			}
			_0 = simple_stmts_32.node;
			success_1 = true;
			break;
		}
		case Tokens::NOT: {
			lookahead_pos_1 = lookahead_pos_1;
			success_35 = false;
			simple_stmts_34 = simple_stmts(lookahead_pos_1);
			if (!(simple_stmts_34.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  simple_stmts");
				return {};
			}
			success_35 = true;
			lookahead_pos_1 = simple_stmts_34.it;
			if (!success_35) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  simple_stmts");
				return {};
			}
			_0 = simple_stmts_34.node;
			success_1 = true;
			break;
		}
		case Tokens::NUMBER: {
			lookahead_pos_1 = lookahead_pos_1;
			success_37 = false;
			simple_stmts_36 = simple_stmts(lookahead_pos_1);
			if (!(simple_stmts_36.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  simple_stmts");
				return {};
			}
			success_37 = true;
			lookahead_pos_1 = simple_stmts_36.it;
			if (!success_37) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  simple_stmts");
				return {};
			}
			_0 = simple_stmts_36.node;
			success_1 = true;
			break;
		}
		case Tokens::PASS: {
			lookahead_pos_1 = lookahead_pos_1;
			success_39 = false;
			simple_stmts_38 = simple_stmts(lookahead_pos_1);
			if (!(simple_stmts_38.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  simple_stmts");
				return {};
			}
			success_39 = true;
			lookahead_pos_1 = simple_stmts_38.it;
			if (!success_39) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  simple_stmts");
				return {};
			}
			_0 = simple_stmts_38.node;
			success_1 = true;
			break;
		}
		case Tokens::PLUS: {
			lookahead_pos_1 = lookahead_pos_1;
			success_41 = false;
			simple_stmts_40 = simple_stmts(lookahead_pos_1);
			if (!(simple_stmts_40.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  simple_stmts");
				return {};
			}
			success_41 = true;
			lookahead_pos_1 = simple_stmts_40.it;
			if (!success_41) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  simple_stmts");
				return {};
			}
			_0 = simple_stmts_40.node;
			success_1 = true;
			break;
		}
		case Tokens::RAISE: {
			lookahead_pos_1 = lookahead_pos_1;
			success_43 = false;
			simple_stmts_42 = simple_stmts(lookahead_pos_1);
			if (!(simple_stmts_42.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  simple_stmts");
				return {};
			}
			success_43 = true;
			lookahead_pos_1 = simple_stmts_42.it;
			if (!success_43) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  simple_stmts");
				return {};
			}
			_0 = simple_stmts_42.node;
			success_1 = true;
			break;
		}
		case Tokens::RETURN: {
			lookahead_pos_1 = lookahead_pos_1;
			success_45 = false;
			simple_stmts_44 = simple_stmts(lookahead_pos_1);
			if (!(simple_stmts_44.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  simple_stmts");
				return {};
			}
			success_45 = true;
			lookahead_pos_1 = simple_stmts_44.it;
			if (!success_45) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  simple_stmts");
				return {};
			}
			_0 = simple_stmts_44.node;
			success_1 = true;
			break;
		}
		case Tokens::STRING: {
			lookahead_pos_1 = lookahead_pos_1;
			success_47 = false;
			simple_stmts_46 = simple_stmts(lookahead_pos_1);
			if (!(simple_stmts_46.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  simple_stmts");
				return {};
			}
			success_47 = true;
			lookahead_pos_1 = simple_stmts_46.it;
			if (!success_47) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  simple_stmts");
				return {};
			}
			_0 = simple_stmts_46.node;
			success_1 = true;
			break;
		}
		case Tokens::TILDE: {
			lookahead_pos_1 = lookahead_pos_1;
			success_49 = false;
			simple_stmts_48 = simple_stmts(lookahead_pos_1);
			if (!(simple_stmts_48.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  simple_stmts");
				return {};
			}
			success_49 = true;
			lookahead_pos_1 = simple_stmts_48.it;
			if (!success_49) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  simple_stmts");
				return {};
			}
			_0 = simple_stmts_48.node;
			success_1 = true;
			break;
		}
		case Tokens::TRUE: {
			lookahead_pos_1 = lookahead_pos_1;
			success_51 = false;
			simple_stmts_50 = simple_stmts(lookahead_pos_1);
			if (!(simple_stmts_50.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  simple_stmts");
				return {};
			}
			success_51 = true;
			lookahead_pos_1 = simple_stmts_50.it;
			if (!success_51) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  simple_stmts");
				return {};
			}
			_0 = simple_stmts_50.node;
			success_1 = true;
			break;
		}
	}
	pos = lookahead_pos_1;
	if (!success_1) {
		raise_error(*pos, "ISPA match failure: no LL(k) alternative matched | grammar: @  ( indented_block |  simple_stmts)");
		return {};
	}
	Types::block result;
	::ISPA_STD::assign_compatible(result.value, _0);
	::ISPA_STD::MatchResult<Rules, Types::block, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::block<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::block, ::Parser::Lexer::iterator>;
template auto Parser::Parser::block<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::block, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::break_stmt(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::break_stmt, IT> {
	::ISPA_STD::Node<::Parser::Tokens, Types::BREAK> BREAK_0;
	bool success_1;
	success_1 = false;
	if (!(((*pos)).template holds<Types::BREAK>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  BREAK");
		return {};
	}
	BREAK_0 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::BREAK>>();
	success_1 = true;
	pos++;
	Types::break_stmt result;
	::ISPA_STD::MatchResult<Rules, Types::break_stmt, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::break_stmt<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::break_stmt, ::Parser::Lexer::iterator>;
template auto Parser::Parser::break_stmt<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::break_stmt, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::call_arg(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::call_arg, IT> {
	std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Rules, Types::expr>, ::ISPA_STD::Node<::Parser::Rules, Types::keyword_arg>> _0;
	bool success_1;
	::ISPA_STD::MatchResult<Rules, Types::expr, IT> expr_2;
	bool success_3;
	::ISPA_STD::MatchResult<Rules, Types::expr, IT> expr_4;
	bool success_5;
	::ISPA_STD::MatchResult<Rules, Types::expr, IT> expr_6;
	bool success_7;
	::ISPA_STD::MatchResult<Rules, Types::keyword_arg, IT> keyword_arg_8;
	bool success_9;
	::ISPA_STD::MatchResult<Rules, Types::expr, IT> expr_10;
	bool success_11;
	::ISPA_STD::MatchResult<Rules, Types::expr, IT> expr_12;
	bool success_13;
	::ISPA_STD::MatchResult<Rules, Types::expr, IT> expr_14;
	bool success_15;
	::ISPA_STD::MatchResult<Rules, Types::expr, IT> expr_16;
	bool success_17;
	::ISPA_STD::MatchResult<Rules, Types::expr, IT> expr_18;
	bool success_19;
	::ISPA_STD::MatchResult<Rules, Types::expr, IT> expr_20;
	bool success_21;
	::ISPA_STD::MatchResult<Rules, Types::expr, IT> expr_22;
	bool success_23;
	::ISPA_STD::MatchResult<Rules, Types::expr, IT> expr_24;
	bool success_25;
	::ISPA_STD::MatchResult<Rules, Types::expr, IT> expr_26;
	bool success_27;
	::ISPA_STD::MatchResult<Rules, Types::expr, IT> expr_28;
	bool success_29;
	::ISPA_STD::MatchResult<Rules, Types::expr, IT> expr_30;
	bool success_31;
	::ISPA_STD::MatchResult<Rules, Types::expr, IT> expr_32;
	bool success_33;
	::ISPA_STD::MatchResult<Rules, Types::expr, IT> expr_34;
	bool success_35;
	::ISPA_STD::MatchResult<Rules, Types::expr, IT> expr_36;
	bool success_37;
	::ISPA_STD::MatchResult<Rules, Types::expr, IT> expr_38;
	bool success_39;
	::ISPA_STD::MatchResult<Rules, Types::expr, IT> expr_40;
	bool success_41;
	::ISPA_STD::MatchResult<Rules, Types::expr, IT> expr_42;
	bool success_43;
	::ISPA_STD::MatchResult<Rules, Types::expr, IT> expr_44;
	bool success_45;
	::ISPA_STD::MatchResult<Rules, Types::expr, IT> expr_46;
	bool success_47;
	::ISPA_STD::MatchResult<Rules, Types::expr, IT> expr_48;
	bool success_49;
	::ISPA_STD::MatchResult<Rules, Types::expr, IT> expr_50;
	bool success_51;
	::ISPA_STD::MatchResult<Rules, Types::expr, IT> expr_52;
	bool success_53;
	::ISPA_STD::MatchResult<Rules, Types::expr, IT> expr_54;
	bool success_55;
	::ISPA_STD::MatchResult<Rules, Types::expr, IT> expr_56;
	bool success_57;
	::ISPA_STD::MatchResult<Rules, Types::expr, IT> expr_58;
	bool success_59;
	::ISPA_STD::MatchResult<Rules, Types::expr, IT> expr_60;
	bool success_61;
	::ISPA_STD::MatchResult<Rules, Types::expr, IT> expr_62;
	bool success_63;
	::ISPA_STD::MatchResult<Rules, Types::expr, IT> expr_64;
	bool success_65;
	::ISPA_STD::MatchResult<Rules, Types::expr, IT> expr_66;
	bool success_67;
	::ISPA_STD::MatchResult<Rules, Types::expr, IT> expr_68;
	bool success_69;
	::ISPA_STD::MatchResult<Rules, Types::expr, IT> expr_70;
	bool success_71;
	::ISPA_STD::MatchResult<Rules, Types::expr, IT> expr_72;
	bool success_73;
	::ISPA_STD::MatchResult<Rules, Types::expr, IT> expr_74;
	bool success_75;
	::ISPA_STD::MatchResult<Rules, Types::expr, IT> expr_76;
	bool success_77;
	::ISPA_STD::MatchResult<Rules, Types::expr, IT> expr_78;
	bool success_79;
	::ISPA_STD::MatchResult<Rules, Types::expr, IT> expr_80;
	bool success_81;
	::ISPA_STD::MatchResult<Rules, Types::expr, IT> expr_82;
	bool success_83;
	::ISPA_STD::MatchResult<Rules, Types::expr, IT> expr_84;
	bool success_85;
	::ISPA_STD::MatchResult<Rules, Types::expr, IT> expr_86;
	bool success_87;
	success_1 = false;
	// grammar `@  ( keyword_arg |  expr)`: choice; reset match status before selecting an alternative
	success_1 = false;
	auto lookahead_pos_1 = pos;
	switch (static_cast<Tokens>((*lookahead_pos_1).kind())) {
		case Tokens::FALSE: {
			lookahead_pos_1 = lookahead_pos_1;
			success_3 = false;
			expr_2 = expr(lookahead_pos_1);
			if (!(expr_2.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  expr");
				return {};
			}
			success_3 = true;
			lookahead_pos_1 = expr_2.it;
			if (!success_3) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  expr");
				return {};
			}
			_0 = expr_2.node;
			success_1 = true;
			break;
		}
		case Tokens::ID: {
			auto lookahead_pos_2 = lookahead_pos_1;
			++lookahead_pos_2;
			skip_spaces<Types::__WS>(lookahead_pos_2);
			switch (static_cast<Tokens>((*lookahead_pos_2).kind())) {
				case Tokens::AMP: {
					lookahead_pos_2 = lookahead_pos_1;
					success_5 = false;
					expr_4 = expr(lookahead_pos_2);
					if (!(expr_4.status)) {
						raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  expr");
						return {};
					}
					success_5 = true;
					lookahead_pos_2 = expr_4.it;
					if (!success_5) {
						raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  expr");
						return {};
					}
					_0 = expr_4.node;
					success_1 = true;
					break;
				}
				case Tokens::AND: {
					lookahead_pos_2 = lookahead_pos_1;
					success_7 = false;
					expr_6 = expr(lookahead_pos_2);
					if (!(expr_6.status)) {
						raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  expr");
						return {};
					}
					success_7 = true;
					lookahead_pos_2 = expr_6.it;
					if (!success_7) {
						raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  expr");
						return {};
					}
					_0 = expr_6.node;
					success_1 = true;
					break;
				}
				case Tokens::ASSIGN: {
					lookahead_pos_2 = lookahead_pos_1;
					success_9 = false;
					keyword_arg_8 = keyword_arg(lookahead_pos_2);
					if (!(keyword_arg_8.status)) {
						raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  keyword_arg");
						return {};
					}
					success_9 = true;
					lookahead_pos_2 = keyword_arg_8.it;
					if (!success_9) {
						raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  keyword_arg");
						return {};
					}
					_0 = keyword_arg_8.node;
					success_1 = true;
					break;
				}
				case Tokens::CARET: {
					lookahead_pos_2 = lookahead_pos_1;
					success_11 = false;
					expr_10 = expr(lookahead_pos_2);
					if (!(expr_10.status)) {
						raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  expr");
						return {};
					}
					success_11 = true;
					lookahead_pos_2 = expr_10.it;
					if (!success_11) {
						raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  expr");
						return {};
					}
					_0 = expr_10.node;
					success_1 = true;
					break;
				}
				case Tokens::COMMA: {
					lookahead_pos_2 = lookahead_pos_1;
					success_13 = false;
					expr_12 = expr(lookahead_pos_2);
					if (!(expr_12.status)) {
						raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  expr");
						return {};
					}
					success_13 = true;
					lookahead_pos_2 = expr_12.it;
					if (!success_13) {
						raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  expr");
						return {};
					}
					_0 = expr_12.node;
					success_1 = true;
					break;
				}
				case Tokens::DOT: {
					lookahead_pos_2 = lookahead_pos_1;
					success_15 = false;
					expr_14 = expr(lookahead_pos_2);
					if (!(expr_14.status)) {
						raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  expr");
						return {};
					}
					success_15 = true;
					lookahead_pos_2 = expr_14.it;
					if (!success_15) {
						raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  expr");
						return {};
					}
					_0 = expr_14.node;
					success_1 = true;
					break;
				}
				case Tokens::EQ: {
					lookahead_pos_2 = lookahead_pos_1;
					success_17 = false;
					expr_16 = expr(lookahead_pos_2);
					if (!(expr_16.status)) {
						raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  expr");
						return {};
					}
					success_17 = true;
					lookahead_pos_2 = expr_16.it;
					if (!success_17) {
						raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  expr");
						return {};
					}
					_0 = expr_16.node;
					success_1 = true;
					break;
				}
				case Tokens::FLOOR_DIV: {
					lookahead_pos_2 = lookahead_pos_1;
					success_19 = false;
					expr_18 = expr(lookahead_pos_2);
					if (!(expr_18.status)) {
						raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  expr");
						return {};
					}
					success_19 = true;
					lookahead_pos_2 = expr_18.it;
					if (!success_19) {
						raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  expr");
						return {};
					}
					_0 = expr_18.node;
					success_1 = true;
					break;
				}
				case Tokens::GE: {
					lookahead_pos_2 = lookahead_pos_1;
					success_21 = false;
					expr_20 = expr(lookahead_pos_2);
					if (!(expr_20.status)) {
						raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  expr");
						return {};
					}
					success_21 = true;
					lookahead_pos_2 = expr_20.it;
					if (!success_21) {
						raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  expr");
						return {};
					}
					_0 = expr_20.node;
					success_1 = true;
					break;
				}
				case Tokens::GT: {
					lookahead_pos_2 = lookahead_pos_1;
					success_23 = false;
					expr_22 = expr(lookahead_pos_2);
					if (!(expr_22.status)) {
						raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  expr");
						return {};
					}
					success_23 = true;
					lookahead_pos_2 = expr_22.it;
					if (!success_23) {
						raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  expr");
						return {};
					}
					_0 = expr_22.node;
					success_1 = true;
					break;
				}
				case Tokens::IF: {
					lookahead_pos_2 = lookahead_pos_1;
					success_25 = false;
					expr_24 = expr(lookahead_pos_2);
					if (!(expr_24.status)) {
						raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  expr");
						return {};
					}
					success_25 = true;
					lookahead_pos_2 = expr_24.it;
					if (!success_25) {
						raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  expr");
						return {};
					}
					_0 = expr_24.node;
					success_1 = true;
					break;
				}
				case Tokens::IN: {
					lookahead_pos_2 = lookahead_pos_1;
					success_27 = false;
					expr_26 = expr(lookahead_pos_2);
					if (!(expr_26.status)) {
						raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  expr");
						return {};
					}
					success_27 = true;
					lookahead_pos_2 = expr_26.it;
					if (!success_27) {
						raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  expr");
						return {};
					}
					_0 = expr_26.node;
					success_1 = true;
					break;
				}
				case Tokens::IS: {
					lookahead_pos_2 = lookahead_pos_1;
					success_29 = false;
					expr_28 = expr(lookahead_pos_2);
					if (!(expr_28.status)) {
						raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  expr");
						return {};
					}
					success_29 = true;
					lookahead_pos_2 = expr_28.it;
					if (!success_29) {
						raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  expr");
						return {};
					}
					_0 = expr_28.node;
					success_1 = true;
					break;
				}
				case Tokens::LBRACKET: {
					lookahead_pos_2 = lookahead_pos_1;
					success_31 = false;
					expr_30 = expr(lookahead_pos_2);
					if (!(expr_30.status)) {
						raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  expr");
						return {};
					}
					success_31 = true;
					lookahead_pos_2 = expr_30.it;
					if (!success_31) {
						raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  expr");
						return {};
					}
					_0 = expr_30.node;
					success_1 = true;
					break;
				}
				case Tokens::LE: {
					lookahead_pos_2 = lookahead_pos_1;
					success_33 = false;
					expr_32 = expr(lookahead_pos_2);
					if (!(expr_32.status)) {
						raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  expr");
						return {};
					}
					success_33 = true;
					lookahead_pos_2 = expr_32.it;
					if (!success_33) {
						raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  expr");
						return {};
					}
					_0 = expr_32.node;
					success_1 = true;
					break;
				}
				case Tokens::LPAREN: {
					lookahead_pos_2 = lookahead_pos_1;
					success_35 = false;
					expr_34 = expr(lookahead_pos_2);
					if (!(expr_34.status)) {
						raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  expr");
						return {};
					}
					success_35 = true;
					lookahead_pos_2 = expr_34.it;
					if (!success_35) {
						raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  expr");
						return {};
					}
					_0 = expr_34.node;
					success_1 = true;
					break;
				}
				case Tokens::LSHIFT: {
					lookahead_pos_2 = lookahead_pos_1;
					success_37 = false;
					expr_36 = expr(lookahead_pos_2);
					if (!(expr_36.status)) {
						raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  expr");
						return {};
					}
					success_37 = true;
					lookahead_pos_2 = expr_36.it;
					if (!success_37) {
						raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  expr");
						return {};
					}
					_0 = expr_36.node;
					success_1 = true;
					break;
				}
				case Tokens::LT: {
					lookahead_pos_2 = lookahead_pos_1;
					success_39 = false;
					expr_38 = expr(lookahead_pos_2);
					if (!(expr_38.status)) {
						raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  expr");
						return {};
					}
					success_39 = true;
					lookahead_pos_2 = expr_38.it;
					if (!success_39) {
						raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  expr");
						return {};
					}
					_0 = expr_38.node;
					success_1 = true;
					break;
				}
				case Tokens::MATMUL: {
					lookahead_pos_2 = lookahead_pos_1;
					success_41 = false;
					expr_40 = expr(lookahead_pos_2);
					if (!(expr_40.status)) {
						raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  expr");
						return {};
					}
					success_41 = true;
					lookahead_pos_2 = expr_40.it;
					if (!success_41) {
						raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  expr");
						return {};
					}
					_0 = expr_40.node;
					success_1 = true;
					break;
				}
				case Tokens::MINUS: {
					lookahead_pos_2 = lookahead_pos_1;
					success_43 = false;
					expr_42 = expr(lookahead_pos_2);
					if (!(expr_42.status)) {
						raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  expr");
						return {};
					}
					success_43 = true;
					lookahead_pos_2 = expr_42.it;
					if (!success_43) {
						raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  expr");
						return {};
					}
					_0 = expr_42.node;
					success_1 = true;
					break;
				}
				case Tokens::NE: {
					lookahead_pos_2 = lookahead_pos_1;
					success_45 = false;
					expr_44 = expr(lookahead_pos_2);
					if (!(expr_44.status)) {
						raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  expr");
						return {};
					}
					success_45 = true;
					lookahead_pos_2 = expr_44.it;
					if (!success_45) {
						raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  expr");
						return {};
					}
					_0 = expr_44.node;
					success_1 = true;
					break;
				}
				case Tokens::NOT: {
					lookahead_pos_2 = lookahead_pos_1;
					success_47 = false;
					expr_46 = expr(lookahead_pos_2);
					if (!(expr_46.status)) {
						raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  expr");
						return {};
					}
					success_47 = true;
					lookahead_pos_2 = expr_46.it;
					if (!success_47) {
						raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  expr");
						return {};
					}
					_0 = expr_46.node;
					success_1 = true;
					break;
				}
				case Tokens::OR: {
					lookahead_pos_2 = lookahead_pos_1;
					success_49 = false;
					expr_48 = expr(lookahead_pos_2);
					if (!(expr_48.status)) {
						raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  expr");
						return {};
					}
					success_49 = true;
					lookahead_pos_2 = expr_48.it;
					if (!success_49) {
						raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  expr");
						return {};
					}
					_0 = expr_48.node;
					success_1 = true;
					break;
				}
				case Tokens::PERCENT: {
					lookahead_pos_2 = lookahead_pos_1;
					success_51 = false;
					expr_50 = expr(lookahead_pos_2);
					if (!(expr_50.status)) {
						raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  expr");
						return {};
					}
					success_51 = true;
					lookahead_pos_2 = expr_50.it;
					if (!success_51) {
						raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  expr");
						return {};
					}
					_0 = expr_50.node;
					success_1 = true;
					break;
				}
				case Tokens::PIPE: {
					lookahead_pos_2 = lookahead_pos_1;
					success_53 = false;
					expr_52 = expr(lookahead_pos_2);
					if (!(expr_52.status)) {
						raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  expr");
						return {};
					}
					success_53 = true;
					lookahead_pos_2 = expr_52.it;
					if (!success_53) {
						raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  expr");
						return {};
					}
					_0 = expr_52.node;
					success_1 = true;
					break;
				}
				case Tokens::PLUS: {
					lookahead_pos_2 = lookahead_pos_1;
					success_55 = false;
					expr_54 = expr(lookahead_pos_2);
					if (!(expr_54.status)) {
						raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  expr");
						return {};
					}
					success_55 = true;
					lookahead_pos_2 = expr_54.it;
					if (!success_55) {
						raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  expr");
						return {};
					}
					_0 = expr_54.node;
					success_1 = true;
					break;
				}
				case Tokens::POWER: {
					lookahead_pos_2 = lookahead_pos_1;
					success_57 = false;
					expr_56 = expr(lookahead_pos_2);
					if (!(expr_56.status)) {
						raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  expr");
						return {};
					}
					success_57 = true;
					lookahead_pos_2 = expr_56.it;
					if (!success_57) {
						raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  expr");
						return {};
					}
					_0 = expr_56.node;
					success_1 = true;
					break;
				}
				case Tokens::RPAREN: {
					lookahead_pos_2 = lookahead_pos_1;
					success_59 = false;
					expr_58 = expr(lookahead_pos_2);
					if (!(expr_58.status)) {
						raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  expr");
						return {};
					}
					success_59 = true;
					lookahead_pos_2 = expr_58.it;
					if (!success_59) {
						raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  expr");
						return {};
					}
					_0 = expr_58.node;
					success_1 = true;
					break;
				}
				case Tokens::RSHIFT: {
					lookahead_pos_2 = lookahead_pos_1;
					success_61 = false;
					expr_60 = expr(lookahead_pos_2);
					if (!(expr_60.status)) {
						raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  expr");
						return {};
					}
					success_61 = true;
					lookahead_pos_2 = expr_60.it;
					if (!success_61) {
						raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  expr");
						return {};
					}
					_0 = expr_60.node;
					success_1 = true;
					break;
				}
				case Tokens::SLASH: {
					lookahead_pos_2 = lookahead_pos_1;
					success_63 = false;
					expr_62 = expr(lookahead_pos_2);
					if (!(expr_62.status)) {
						raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  expr");
						return {};
					}
					success_63 = true;
					lookahead_pos_2 = expr_62.it;
					if (!success_63) {
						raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  expr");
						return {};
					}
					_0 = expr_62.node;
					success_1 = true;
					break;
				}
				case Tokens::STAR: {
					lookahead_pos_2 = lookahead_pos_1;
					success_65 = false;
					expr_64 = expr(lookahead_pos_2);
					if (!(expr_64.status)) {
						raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  expr");
						return {};
					}
					success_65 = true;
					lookahead_pos_2 = expr_64.it;
					if (!success_65) {
						raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  expr");
						return {};
					}
					_0 = expr_64.node;
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
		case Tokens::LBRACE: {
			lookahead_pos_1 = lookahead_pos_1;
			success_67 = false;
			expr_66 = expr(lookahead_pos_1);
			if (!(expr_66.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  expr");
				return {};
			}
			success_67 = true;
			lookahead_pos_1 = expr_66.it;
			if (!success_67) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  expr");
				return {};
			}
			_0 = expr_66.node;
			success_1 = true;
			break;
		}
		case Tokens::LBRACKET: {
			lookahead_pos_1 = lookahead_pos_1;
			success_69 = false;
			expr_68 = expr(lookahead_pos_1);
			if (!(expr_68.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  expr");
				return {};
			}
			success_69 = true;
			lookahead_pos_1 = expr_68.it;
			if (!success_69) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  expr");
				return {};
			}
			_0 = expr_68.node;
			success_1 = true;
			break;
		}
		case Tokens::LPAREN: {
			lookahead_pos_1 = lookahead_pos_1;
			success_71 = false;
			expr_70 = expr(lookahead_pos_1);
			if (!(expr_70.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  expr");
				return {};
			}
			success_71 = true;
			lookahead_pos_1 = expr_70.it;
			if (!success_71) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  expr");
				return {};
			}
			_0 = expr_70.node;
			success_1 = true;
			break;
		}
		case Tokens::MINUS: {
			lookahead_pos_1 = lookahead_pos_1;
			success_73 = false;
			expr_72 = expr(lookahead_pos_1);
			if (!(expr_72.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  expr");
				return {};
			}
			success_73 = true;
			lookahead_pos_1 = expr_72.it;
			if (!success_73) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  expr");
				return {};
			}
			_0 = expr_72.node;
			success_1 = true;
			break;
		}
		case Tokens::NONE_V: {
			lookahead_pos_1 = lookahead_pos_1;
			success_75 = false;
			expr_74 = expr(lookahead_pos_1);
			if (!(expr_74.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  expr");
				return {};
			}
			success_75 = true;
			lookahead_pos_1 = expr_74.it;
			if (!success_75) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  expr");
				return {};
			}
			_0 = expr_74.node;
			success_1 = true;
			break;
		}
		case Tokens::NOT: {
			lookahead_pos_1 = lookahead_pos_1;
			success_77 = false;
			expr_76 = expr(lookahead_pos_1);
			if (!(expr_76.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  expr");
				return {};
			}
			success_77 = true;
			lookahead_pos_1 = expr_76.it;
			if (!success_77) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  expr");
				return {};
			}
			_0 = expr_76.node;
			success_1 = true;
			break;
		}
		case Tokens::NUMBER: {
			lookahead_pos_1 = lookahead_pos_1;
			success_79 = false;
			expr_78 = expr(lookahead_pos_1);
			if (!(expr_78.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  expr");
				return {};
			}
			success_79 = true;
			lookahead_pos_1 = expr_78.it;
			if (!success_79) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  expr");
				return {};
			}
			_0 = expr_78.node;
			success_1 = true;
			break;
		}
		case Tokens::PLUS: {
			lookahead_pos_1 = lookahead_pos_1;
			success_81 = false;
			expr_80 = expr(lookahead_pos_1);
			if (!(expr_80.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  expr");
				return {};
			}
			success_81 = true;
			lookahead_pos_1 = expr_80.it;
			if (!success_81) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  expr");
				return {};
			}
			_0 = expr_80.node;
			success_1 = true;
			break;
		}
		case Tokens::STRING: {
			lookahead_pos_1 = lookahead_pos_1;
			success_83 = false;
			expr_82 = expr(lookahead_pos_1);
			if (!(expr_82.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  expr");
				return {};
			}
			success_83 = true;
			lookahead_pos_1 = expr_82.it;
			if (!success_83) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  expr");
				return {};
			}
			_0 = expr_82.node;
			success_1 = true;
			break;
		}
		case Tokens::TILDE: {
			lookahead_pos_1 = lookahead_pos_1;
			success_85 = false;
			expr_84 = expr(lookahead_pos_1);
			if (!(expr_84.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  expr");
				return {};
			}
			success_85 = true;
			lookahead_pos_1 = expr_84.it;
			if (!success_85) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  expr");
				return {};
			}
			_0 = expr_84.node;
			success_1 = true;
			break;
		}
		case Tokens::TRUE: {
			lookahead_pos_1 = lookahead_pos_1;
			success_87 = false;
			expr_86 = expr(lookahead_pos_1);
			if (!(expr_86.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  expr");
				return {};
			}
			success_87 = true;
			lookahead_pos_1 = expr_86.it;
			if (!success_87) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  expr");
				return {};
			}
			_0 = expr_86.node;
			success_1 = true;
			break;
		}
	}
	pos = lookahead_pos_1;
	if (!success_1) {
		raise_error(*pos, "ISPA match failure: no LL(k) alternative matched | grammar: @  ( keyword_arg |  expr)");
		return {};
	}
	Types::call_arg result;
	::ISPA_STD::assign_compatible(result.value, _0);
	::ISPA_STD::MatchResult<Rules, Types::call_arg, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::call_arg<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::call_arg, ::Parser::Lexer::iterator>;
template auto Parser::Parser::call_arg<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::call_arg, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::call_arg_tail(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::call_arg_tail, IT> {
	::ISPA_STD::Node<::Parser::Tokens, Types::COMMA> COMMA_0;
	bool success_1;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::MatchResult<Rules, Types::call_arg, IT> call_arg_4;
	bool success_5;
	success_1 = false;
	if (!(((*pos)).template holds<Types::COMMA>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  COMMA");
		return {};
	}
	COMMA_0 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::COMMA>>();
	success_1 = true;
	pos++;
	success_3 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_2 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_3 = true;
		pos++;
	}
	success_5 = false;
	call_arg_4 = call_arg(pos);
	if (!(call_arg_4.status)) {
		raise_error(*pos, "ISPA match failure: required named rule did not match | grammar: @  call_arg");
		return {};
	}
	success_5 = true;
	pos = call_arg_4.it;
	Types::call_arg_tail result;
	::ISPA_STD::assign_compatible(result.value, call_arg_4.node);
	::ISPA_STD::MatchResult<Rules, Types::call_arg_tail, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::call_arg_tail<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::call_arg_tail, ::Parser::Lexer::iterator>;
template auto Parser::Parser::call_arg_tail<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::call_arg_tail, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::call_args(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::call_args, IT> {
	::ISPA_STD::MatchResult<Rules, Types::call_arg, IT> call_arg_0;
	bool success_1;
	::ISPA_STD::MatchResult<Rules, Types::call_arg_tail, IT> call_arg_tail_5;
	bool success_6;
	::ISPA_STD::Node<::Parser::Rules, Types::call_arg_tail> element_7;
	std::vector<::ISPA_STD::Node<::Parser::Rules, Types::call_arg_tail>> shadow_8;
	std::vector<::ISPA_STD::Node<::Parser::Rules, Types::call_arg_tail>> uvar_4;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_10;
	bool success_11;
	::ISPA_STD::Node<::Parser::Tokens, Types::COMMA> COMMA_12;
	bool success_13;
	success_1 = false;
	call_arg_0 = call_arg(pos);
	if (!(call_arg_0.status)) {
		raise_error(*pos, "ISPA match failure: required named rule did not match | grammar: @  call_arg");
		return {};
	}
	success_1 = true;
	pos = call_arg_0.it;
	success_6 = false;
	// grammar `@  call_arg_tail*;`: repeat named rule; collect every matched value
	while (true) {
		auto repeat_ws_9 = pos;
		success_3 = false;
		if (((*repeat_ws_9)).template holds<Types::__WS>()) {
			__WS_2 = ((*repeat_ws_9)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
			success_3 = true;
			repeat_ws_9++;
		}
		call_arg_tail_5 = call_arg_tail(repeat_ws_9);
		if (!(call_arg_tail_5.status)) {
			break;
		}
		success_6 = true;
		repeat_ws_9 = call_arg_tail_5.it;
		element_7 = call_arg_tail_5.node;
		shadow_8.push_back(element_7);
		pos = repeat_ws_9;
	}
	::ISPA_STD::assign_compatible(uvar_4, shadow_8);
	success_11 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_10 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_11 = true;
		pos++;
	}
	success_13 = false;
	if (((*pos)).template holds<Types::COMMA>()) {
		COMMA_12 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::COMMA>>();
		success_13 = true;
		pos++;
	}
	Types::call_args result;
	::ISPA_STD::assign_compatible(result.first, call_arg_0);
	::ISPA_STD::assign_compatible(result.rest, uvar_4);
	::ISPA_STD::MatchResult<Rules, Types::call_args, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::call_args<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::call_args, ::Parser::Lexer::iterator>;
template auto Parser::Parser::call_args<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::call_args, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::call_suffix(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::call_suffix, IT> {
	::ISPA_STD::Node<::Parser::Tokens, Types::LPAREN> LPAREN_0;
	bool success_1;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::MatchResult<Rules, Types::call_args, IT> call_args_4;
	bool success_5;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_6;
	bool success_7;
	::ISPA_STD::Node<::Parser::Tokens, Types::RPAREN> RPAREN_8;
	bool success_9;
	success_1 = false;
	if (!(((*pos)).template holds<Types::LPAREN>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  LPAREN");
		return {};
	}
	LPAREN_0 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::LPAREN>>();
	success_1 = true;
	pos++;
	success_3 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_2 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_3 = true;
		pos++;
	}
	success_5 = false;
	call_args_4 = call_args(pos);
	if (call_args_4.status) {
		success_5 = true;
		pos = call_args_4.it;
	}
	success_7 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_6 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_7 = true;
		pos++;
	}
	success_9 = false;
	if (!(((*pos)).template holds<Types::RPAREN>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  RPAREN");
		return {};
	}
	RPAREN_8 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::RPAREN>>();
	success_9 = true;
	pos++;
	Types::call_suffix result;
	::ISPA_STD::assign_compatible(result.value, call_args_4.node);
	::ISPA_STD::MatchResult<Rules, Types::call_suffix, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::call_suffix<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::call_suffix, ::Parser::Lexer::iterator>;
template auto Parser::Parser::call_suffix<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::call_suffix, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::class_bases(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::class_bases, IT> {
	::ISPA_STD::Node<::Parser::Tokens, Types::LPAREN> LPAREN_0;
	bool success_1;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::MatchResult<Rules, Types::call_args, IT> call_args_4;
	bool success_5;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_6;
	bool success_7;
	::ISPA_STD::Node<::Parser::Tokens, Types::RPAREN> RPAREN_8;
	bool success_9;
	success_1 = false;
	if (!(((*pos)).template holds<Types::LPAREN>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  LPAREN");
		return {};
	}
	LPAREN_0 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::LPAREN>>();
	success_1 = true;
	pos++;
	success_3 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_2 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_3 = true;
		pos++;
	}
	success_5 = false;
	call_args_4 = call_args(pos);
	if (call_args_4.status) {
		success_5 = true;
		pos = call_args_4.it;
	}
	success_7 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_6 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_7 = true;
		pos++;
	}
	success_9 = false;
	if (!(((*pos)).template holds<Types::RPAREN>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  RPAREN");
		return {};
	}
	RPAREN_8 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::RPAREN>>();
	success_9 = true;
	pos++;
	Types::class_bases result;
	::ISPA_STD::assign_compatible(result.value, call_args_4.node);
	::ISPA_STD::MatchResult<Rules, Types::class_bases, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::class_bases<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::class_bases, ::Parser::Lexer::iterator>;
template auto Parser::Parser::class_bases<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::class_bases, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::class_def(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::class_def, IT> {
	::ISPA_STD::MatchResult<Rules, Types::decorators, IT> decorators_0;
	bool success_1;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::MatchResult<Rules, Types::class_header, IT> class_header_4;
	bool success_5;
	success_1 = false;
	decorators_0 = decorators(pos);
	if (decorators_0.status) {
		success_1 = true;
		pos = decorators_0.it;
	}
	success_3 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_2 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_3 = true;
		pos++;
	}
	success_5 = false;
	class_header_4 = class_header(pos);
	if (!(class_header_4.status)) {
		raise_error(*pos, "ISPA match failure: required named rule did not match | grammar: @  class_header");
		return {};
	}
	success_5 = true;
	pos = class_header_4.it;
	Types::class_def result;
	::ISPA_STD::assign_compatible(result.decorators, decorators_0);
	::ISPA_STD::assign_compatible(result.definition, class_header_4);
	::ISPA_STD::MatchResult<Rules, Types::class_def, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::class_def<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::class_def, ::Parser::Lexer::iterator>;
template auto Parser::Parser::class_def<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::class_def, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::class_header(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::class_header, IT> {
	::ISPA_STD::Node<::Parser::Tokens, Types::CLASS> CLASS_0;
	bool success_1;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::Node<::Parser::Tokens, Types::ID> ID_4;
	bool success_5;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_6;
	bool success_7;
	::ISPA_STD::MatchResult<Rules, Types::class_bases, IT> class_bases_8;
	bool success_9;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_10;
	bool success_11;
	::ISPA_STD::Node<::Parser::Tokens, Types::COLON> COLON_12;
	bool success_13;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_14;
	bool success_15;
	::ISPA_STD::MatchResult<Rules, Types::block, IT> block_16;
	bool success_17;
	success_1 = false;
	if (!(((*pos)).template holds<Types::CLASS>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  CLASS");
		return {};
	}
	CLASS_0 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::CLASS>>();
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
	class_bases_8 = class_bases(pos);
	if (class_bases_8.status) {
		success_9 = true;
		pos = class_bases_8.it;
	}
	success_11 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_10 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_11 = true;
		pos++;
	}
	success_13 = false;
	if (!(((*pos)).template holds<Types::COLON>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  COLON");
		return {};
	}
	COLON_12 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::COLON>>();
	success_13 = true;
	pos++;
	success_15 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_14 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_15 = true;
		pos++;
	}
	success_17 = false;
	block_16 = block(pos);
	if (!(block_16.status)) {
		raise_error(*pos, "ISPA match failure: required named rule did not match | grammar: @  block");
		return {};
	}
	success_17 = true;
	pos = block_16.it;
	Types::class_header result;
	::ISPA_STD::assign_compatible(result.name, ID_4);
	::ISPA_STD::assign_compatible(result.bases, class_bases_8);
	::ISPA_STD::assign_compatible(result.body, block_16);
	::ISPA_STD::MatchResult<Rules, Types::class_header, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::class_header<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::class_header, ::Parser::Lexer::iterator>;
template auto Parser::Parser::class_header<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::class_header, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::compare_op(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::compare_op, IT> {
	std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Rules, Types::is_op>, ::ISPA_STD::Node<::Parser::Rules, Types::not_in>, ::ISPA_STD::Node<::Parser::Tokens, Types::GT>, ::ISPA_STD::Node<::Parser::Tokens, Types::IN>, ::ISPA_STD::Node<::Parser::Tokens, Types::GE>, ::ISPA_STD::Node<::Parser::Tokens, Types::LT>, ::ISPA_STD::Node<::Parser::Tokens, Types::LE>, ::ISPA_STD::Node<::Parser::Tokens, Types::NE>, ::ISPA_STD::Node<::Parser::Tokens, Types::EQ>> _0;
	bool success_1;
	::ISPA_STD::Node<::Parser::Tokens, Types::EQ> EQ_2;
	bool success_3;
	::ISPA_STD::Node<::Parser::Tokens, Types::GE> GE_4;
	bool success_5;
	::ISPA_STD::Node<::Parser::Tokens, Types::GT> GT_6;
	bool success_7;
	::ISPA_STD::Node<::Parser::Tokens, Types::IN> IN_8;
	bool success_9;
	::ISPA_STD::MatchResult<Rules, Types::is_op, IT> is_op_10;
	bool success_11;
	::ISPA_STD::Node<::Parser::Tokens, Types::LE> LE_12;
	bool success_13;
	::ISPA_STD::Node<::Parser::Tokens, Types::LT> LT_14;
	bool success_15;
	::ISPA_STD::Node<::Parser::Tokens, Types::NE> NE_16;
	bool success_17;
	::ISPA_STD::MatchResult<Rules, Types::not_in, IT> not_in_18;
	bool success_19;
	success_1 = false;
	// grammar `@  ( EQ |  NE |  LE |  LT |  GE |  GT |  not_in |  IN |  is_op)`: choice; reset match status before selecting an alternative
	success_1 = false;
	auto lookahead_pos_1 = pos;
	switch (static_cast<Tokens>((*lookahead_pos_1).kind())) {
		case Tokens::EQ: {
			lookahead_pos_1 = lookahead_pos_1;
			success_3 = false;
			if (!(((*lookahead_pos_1)).template holds<Types::EQ>())) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  EQ");
				return {};
			}
			EQ_2 = ((*lookahead_pos_1)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::EQ>>();
			success_3 = true;
			lookahead_pos_1++;
			if (!success_3) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  EQ");
				return {};
			}
			_0 = EQ_2;
			success_1 = true;
			break;
		}
		case Tokens::GE: {
			lookahead_pos_1 = lookahead_pos_1;
			success_5 = false;
			if (!(((*lookahead_pos_1)).template holds<Types::GE>())) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  GE");
				return {};
			}
			GE_4 = ((*lookahead_pos_1)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::GE>>();
			success_5 = true;
			lookahead_pos_1++;
			if (!success_5) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  GE");
				return {};
			}
			_0 = GE_4;
			success_1 = true;
			break;
		}
		case Tokens::GT: {
			lookahead_pos_1 = lookahead_pos_1;
			success_7 = false;
			if (!(((*lookahead_pos_1)).template holds<Types::GT>())) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  GT");
				return {};
			}
			GT_6 = ((*lookahead_pos_1)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::GT>>();
			success_7 = true;
			lookahead_pos_1++;
			if (!success_7) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  GT");
				return {};
			}
			_0 = GT_6;
			success_1 = true;
			break;
		}
		case Tokens::IN: {
			lookahead_pos_1 = lookahead_pos_1;
			success_9 = false;
			if (!(((*lookahead_pos_1)).template holds<Types::IN>())) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  IN");
				return {};
			}
			IN_8 = ((*lookahead_pos_1)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::IN>>();
			success_9 = true;
			lookahead_pos_1++;
			if (!success_9) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  IN");
				return {};
			}
			_0 = IN_8;
			success_1 = true;
			break;
		}
		case Tokens::IS: {
			lookahead_pos_1 = lookahead_pos_1;
			success_11 = false;
			is_op_10 = is_op(lookahead_pos_1);
			if (!(is_op_10.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  is_op");
				return {};
			}
			success_11 = true;
			lookahead_pos_1 = is_op_10.it;
			if (!success_11) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  is_op");
				return {};
			}
			_0 = is_op_10.node;
			success_1 = true;
			break;
		}
		case Tokens::LE: {
			lookahead_pos_1 = lookahead_pos_1;
			success_13 = false;
			if (!(((*lookahead_pos_1)).template holds<Types::LE>())) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  LE");
				return {};
			}
			LE_12 = ((*lookahead_pos_1)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::LE>>();
			success_13 = true;
			lookahead_pos_1++;
			if (!success_13) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  LE");
				return {};
			}
			_0 = LE_12;
			success_1 = true;
			break;
		}
		case Tokens::LT: {
			lookahead_pos_1 = lookahead_pos_1;
			success_15 = false;
			if (!(((*lookahead_pos_1)).template holds<Types::LT>())) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  LT");
				return {};
			}
			LT_14 = ((*lookahead_pos_1)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::LT>>();
			success_15 = true;
			lookahead_pos_1++;
			if (!success_15) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  LT");
				return {};
			}
			_0 = LT_14;
			success_1 = true;
			break;
		}
		case Tokens::NE: {
			lookahead_pos_1 = lookahead_pos_1;
			success_17 = false;
			if (!(((*lookahead_pos_1)).template holds<Types::NE>())) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  NE");
				return {};
			}
			NE_16 = ((*lookahead_pos_1)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::NE>>();
			success_17 = true;
			lookahead_pos_1++;
			if (!success_17) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  NE");
				return {};
			}
			_0 = NE_16;
			success_1 = true;
			break;
		}
		case Tokens::NOT: {
			lookahead_pos_1 = lookahead_pos_1;
			success_19 = false;
			not_in_18 = not_in(lookahead_pos_1);
			if (!(not_in_18.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  not_in");
				return {};
			}
			success_19 = true;
			lookahead_pos_1 = not_in_18.it;
			if (!success_19) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  not_in");
				return {};
			}
			_0 = not_in_18.node;
			success_1 = true;
			break;
		}
	}
	pos = lookahead_pos_1;
	if (!success_1) {
		raise_error(*pos, "ISPA match failure: no LL(k) alternative matched | grammar: @  ( EQ |  NE |  LE |  LT |  GE |  GT |  not_in |  IN |  is_op)");
		return {};
	}
	Types::compare_op result;
	::ISPA_STD::assign_compatible(result.value, _0);
	::ISPA_STD::MatchResult<Rules, Types::compare_op, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::compare_op<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::compare_op, ::Parser::Lexer::iterator>;
template auto Parser::Parser::compare_op<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::compare_op, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::compare_tail(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::compare_tail, IT> {
	::ISPA_STD::MatchResult<Rules, Types::compare_op, IT> compare_op_0;
	bool success_1;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::MatchResult<Rules, Types::bitwise_or, IT> bitwise_or_4;
	bool success_5;
	success_1 = false;
	compare_op_0 = compare_op(pos);
	if (!(compare_op_0.status)) {
		raise_error(*pos, "ISPA match failure: required named rule did not match | grammar: @  compare_op");
		return {};
	}
	success_1 = true;
	pos = compare_op_0.it;
	success_3 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_2 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_3 = true;
		pos++;
	}
	success_5 = false;
	bitwise_or_4 = bitwise_or(pos);
	if (!(bitwise_or_4.status)) {
		raise_error(*pos, "ISPA match failure: required named rule did not match | grammar: @  bitwise_or");
		return {};
	}
	success_5 = true;
	pos = bitwise_or_4.it;
	Types::compare_tail result;
	::ISPA_STD::assign_compatible(result.op, compare_op_0);
	::ISPA_STD::assign_compatible(result.value, bitwise_or_4);
	::ISPA_STD::MatchResult<Rules, Types::compare_tail, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::compare_tail<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::compare_tail, ::Parser::Lexer::iterator>;
template auto Parser::Parser::compare_tail<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::compare_tail, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::comparison(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::comparison, IT> {
	::ISPA_STD::MatchResult<Rules, Types::bitwise_or, IT> bitwise_or_0;
	bool success_1;
	::ISPA_STD::MatchResult<Rules, Types::compare_tail, IT> compare_tail_5;
	bool success_6;
	::ISPA_STD::Node<::Parser::Rules, Types::compare_tail> element_7;
	std::vector<::ISPA_STD::Node<::Parser::Rules, Types::compare_tail>> shadow_8;
	std::vector<::ISPA_STD::Node<::Parser::Rules, Types::compare_tail>> uvar_4;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	success_1 = false;
	bitwise_or_0 = bitwise_or(pos);
	if (!(bitwise_or_0.status)) {
		raise_error(*pos, "ISPA match failure: required named rule did not match | grammar: @  bitwise_or");
		return {};
	}
	success_1 = true;
	pos = bitwise_or_0.it;
	success_6 = false;
	// grammar `@  compare_tail*;`: repeat named rule; collect every matched value
	while (true) {
		auto repeat_ws_9 = pos;
		success_3 = false;
		if (((*repeat_ws_9)).template holds<Types::__WS>()) {
			__WS_2 = ((*repeat_ws_9)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
			success_3 = true;
			repeat_ws_9++;
		}
		compare_tail_5 = compare_tail(repeat_ws_9);
		if (!(compare_tail_5.status)) {
			break;
		}
		success_6 = true;
		repeat_ws_9 = compare_tail_5.it;
		element_7 = compare_tail_5.node;
		shadow_8.push_back(element_7);
		pos = repeat_ws_9;
	}
	::ISPA_STD::assign_compatible(uvar_4, shadow_8);
	Types::comparison result;
	::ISPA_STD::assign_compatible(result.first, bitwise_or_0);
	::ISPA_STD::assign_compatible(result.rest, uvar_4);
	::ISPA_STD::MatchResult<Rules, Types::comparison, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::comparison<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::comparison, ::Parser::Lexer::iterator>;
template auto Parser::Parser::comparison<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::comparison, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::compound_stmt(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::compound_stmt, IT> {
	std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Rules, Types::decorated_def>, ::ISPA_STD::Node<::Parser::Rules, Types::try_stmt>, ::ISPA_STD::Node<::Parser::Rules, Types::for_stmt>, ::ISPA_STD::Node<::Parser::Rules, Types::while_stmt>, ::ISPA_STD::Node<::Parser::Rules, Types::with_stmt>, ::ISPA_STD::Node<::Parser::Rules, Types::if_stmt>> _0;
	bool success_1;
	::ISPA_STD::MatchResult<Rules, Types::decorated_def, IT> decorated_def_2;
	bool success_3;
	::ISPA_STD::MatchResult<Rules, Types::for_stmt, IT> for_stmt_4;
	bool success_5;
	::ISPA_STD::MatchResult<Rules, Types::with_stmt, IT> with_stmt_6;
	bool success_7;
	::ISPA_STD::MatchResult<Rules, Types::decorated_def, IT> decorated_def_8;
	bool success_9;
	::ISPA_STD::MatchResult<Rules, Types::decorated_def, IT> decorated_def_10;
	bool success_11;
	::ISPA_STD::MatchResult<Rules, Types::for_stmt, IT> for_stmt_12;
	bool success_13;
	::ISPA_STD::MatchResult<Rules, Types::if_stmt, IT> if_stmt_14;
	bool success_15;
	::ISPA_STD::MatchResult<Rules, Types::decorated_def, IT> decorated_def_16;
	bool success_17;
	::ISPA_STD::MatchResult<Rules, Types::try_stmt, IT> try_stmt_18;
	bool success_19;
	::ISPA_STD::MatchResult<Rules, Types::while_stmt, IT> while_stmt_20;
	bool success_21;
	::ISPA_STD::MatchResult<Rules, Types::with_stmt, IT> with_stmt_22;
	bool success_23;
	success_1 = false;
	// grammar `@  ( if_stmt |  while_stmt |  for_stmt |  with_stmt |  try_stmt |  decorated_def)`: choice; reset match status before selecting an alternative
	success_1 = false;
	auto lookahead_pos_1 = pos;
	switch (static_cast<Tokens>((*lookahead_pos_1).kind())) {
		case Tokens::ASYNC: {
			auto lookahead_pos_2 = lookahead_pos_1;
			++lookahead_pos_2;
			skip_spaces<Types::__WS>(lookahead_pos_2);
			switch (static_cast<Tokens>((*lookahead_pos_2).kind())) {
				case Tokens::DEF: {
					lookahead_pos_2 = lookahead_pos_1;
					success_3 = false;
					decorated_def_2 = decorated_def(lookahead_pos_2);
					if (!(decorated_def_2.status)) {
						raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  decorated_def");
						return {};
					}
					success_3 = true;
					lookahead_pos_2 = decorated_def_2.it;
					if (!success_3) {
						raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  decorated_def");
						return {};
					}
					_0 = decorated_def_2.node;
					success_1 = true;
					break;
				}
				case Tokens::FOR: {
					lookahead_pos_2 = lookahead_pos_1;
					success_5 = false;
					for_stmt_4 = for_stmt(lookahead_pos_2);
					if (!(for_stmt_4.status)) {
						raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  for_stmt");
						return {};
					}
					success_5 = true;
					lookahead_pos_2 = for_stmt_4.it;
					if (!success_5) {
						raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  for_stmt");
						return {};
					}
					_0 = for_stmt_4.node;
					success_1 = true;
					break;
				}
				case Tokens::WITH: {
					lookahead_pos_2 = lookahead_pos_1;
					success_7 = false;
					with_stmt_6 = with_stmt(lookahead_pos_2);
					if (!(with_stmt_6.status)) {
						raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  with_stmt");
						return {};
					}
					success_7 = true;
					lookahead_pos_2 = with_stmt_6.it;
					if (!success_7) {
						raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  with_stmt");
						return {};
					}
					_0 = with_stmt_6.node;
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
		case Tokens::CLASS: {
			lookahead_pos_1 = lookahead_pos_1;
			success_9 = false;
			decorated_def_8 = decorated_def(lookahead_pos_1);
			if (!(decorated_def_8.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  decorated_def");
				return {};
			}
			success_9 = true;
			lookahead_pos_1 = decorated_def_8.it;
			if (!success_9) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  decorated_def");
				return {};
			}
			_0 = decorated_def_8.node;
			success_1 = true;
			break;
		}
		case Tokens::DEF: {
			lookahead_pos_1 = lookahead_pos_1;
			success_11 = false;
			decorated_def_10 = decorated_def(lookahead_pos_1);
			if (!(decorated_def_10.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  decorated_def");
				return {};
			}
			success_11 = true;
			lookahead_pos_1 = decorated_def_10.it;
			if (!success_11) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  decorated_def");
				return {};
			}
			_0 = decorated_def_10.node;
			success_1 = true;
			break;
		}
		case Tokens::FOR: {
			lookahead_pos_1 = lookahead_pos_1;
			success_13 = false;
			for_stmt_12 = for_stmt(lookahead_pos_1);
			if (!(for_stmt_12.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  for_stmt");
				return {};
			}
			success_13 = true;
			lookahead_pos_1 = for_stmt_12.it;
			if (!success_13) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  for_stmt");
				return {};
			}
			_0 = for_stmt_12.node;
			success_1 = true;
			break;
		}
		case Tokens::IF: {
			lookahead_pos_1 = lookahead_pos_1;
			success_15 = false;
			if_stmt_14 = if_stmt(lookahead_pos_1);
			if (!(if_stmt_14.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  if_stmt");
				return {};
			}
			success_15 = true;
			lookahead_pos_1 = if_stmt_14.it;
			if (!success_15) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  if_stmt");
				return {};
			}
			_0 = if_stmt_14.node;
			success_1 = true;
			break;
		}
		case Tokens::MATMUL: {
			lookahead_pos_1 = lookahead_pos_1;
			success_17 = false;
			decorated_def_16 = decorated_def(lookahead_pos_1);
			if (!(decorated_def_16.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  decorated_def");
				return {};
			}
			success_17 = true;
			lookahead_pos_1 = decorated_def_16.it;
			if (!success_17) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  decorated_def");
				return {};
			}
			_0 = decorated_def_16.node;
			success_1 = true;
			break;
		}
		case Tokens::TRY: {
			lookahead_pos_1 = lookahead_pos_1;
			success_19 = false;
			try_stmt_18 = try_stmt(lookahead_pos_1);
			if (!(try_stmt_18.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  try_stmt");
				return {};
			}
			success_19 = true;
			lookahead_pos_1 = try_stmt_18.it;
			if (!success_19) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  try_stmt");
				return {};
			}
			_0 = try_stmt_18.node;
			success_1 = true;
			break;
		}
		case Tokens::WHILE: {
			lookahead_pos_1 = lookahead_pos_1;
			success_21 = false;
			while_stmt_20 = while_stmt(lookahead_pos_1);
			if (!(while_stmt_20.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  while_stmt");
				return {};
			}
			success_21 = true;
			lookahead_pos_1 = while_stmt_20.it;
			if (!success_21) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  while_stmt");
				return {};
			}
			_0 = while_stmt_20.node;
			success_1 = true;
			break;
		}
		case Tokens::WITH: {
			lookahead_pos_1 = lookahead_pos_1;
			success_23 = false;
			with_stmt_22 = with_stmt(lookahead_pos_1);
			if (!(with_stmt_22.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  with_stmt");
				return {};
			}
			success_23 = true;
			lookahead_pos_1 = with_stmt_22.it;
			if (!success_23) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  with_stmt");
				return {};
			}
			_0 = with_stmt_22.node;
			success_1 = true;
			break;
		}
	}
	pos = lookahead_pos_1;
	if (!success_1) {
		raise_error(*pos, "ISPA match failure: no LL(k) alternative matched | grammar: @  ( if_stmt |  while_stmt |  for_stmt |  with_stmt |  try_stmt |  decorated_def)");
		return {};
	}
	Types::compound_stmt result;
	::ISPA_STD::assign_compatible(result.value, _0);
	::ISPA_STD::MatchResult<Rules, Types::compound_stmt, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::compound_stmt<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::compound_stmt, ::Parser::Lexer::iterator>;
template auto Parser::Parser::compound_stmt<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::compound_stmt, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::conditional_tail(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::conditional_tail, IT> {
	::ISPA_STD::Node<::Parser::Tokens, Types::IF> IF_0;
	bool success_1;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::MatchResult<Rules, Types::disjunction, IT> disjunction_4;
	bool success_5;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_6;
	bool success_7;
	::ISPA_STD::Node<::Parser::Tokens, Types::ELSE> ELSE_8;
	bool success_9;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_10;
	bool success_11;
	::ISPA_STD::MatchResult<Rules, Types::expr, IT> expr_12;
	bool success_13;
	success_1 = false;
	if (!(((*pos)).template holds<Types::IF>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  IF");
		return {};
	}
	IF_0 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::IF>>();
	success_1 = true;
	pos++;
	success_3 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_2 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_3 = true;
		pos++;
	}
	success_5 = false;
	disjunction_4 = disjunction(pos);
	if (!(disjunction_4.status)) {
		raise_error(*pos, "ISPA match failure: required named rule did not match | grammar: @  disjunction");
		return {};
	}
	success_5 = true;
	pos = disjunction_4.it;
	success_7 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_6 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_7 = true;
		pos++;
	}
	success_9 = false;
	if (!(((*pos)).template holds<Types::ELSE>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  ELSE");
		return {};
	}
	ELSE_8 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::ELSE>>();
	success_9 = true;
	pos++;
	success_11 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_10 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_11 = true;
		pos++;
	}
	success_13 = false;
	expr_12 = expr(pos);
	if (!(expr_12.status)) {
		raise_error(*pos, "ISPA match failure: required named rule did not match | grammar: @  expr");
		return {};
	}
	success_13 = true;
	pos = expr_12.it;
	Types::conditional_tail result;
	::ISPA_STD::assign_compatible(result.condition, disjunction_4);
	::ISPA_STD::assign_compatible(result.otherwise, expr_12);
	::ISPA_STD::MatchResult<Rules, Types::conditional_tail, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::conditional_tail<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::conditional_tail, ::Parser::Lexer::iterator>;
template auto Parser::Parser::conditional_tail<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::conditional_tail, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::conjunction(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::conjunction, IT> {
	::ISPA_STD::MatchResult<Rules, Types::inversion, IT> inversion_0;
	bool success_1;
	bool success_17;
	bool success_9;
	std::vector<::ISPA_STD::Node<::Parser::Tokens, Types::AND>> shadow_20;
	::ISPA_STD::Node<::Parser::Rules, Types::inversion> group_capture_21;
	std::vector<::ISPA_STD::Node<::Parser::Rules, Types::inversion>> shadow_22;
	std::tuple<::ISPA_STD::Node<::Parser::Tokens, Types::AND>, ::ISPA_STD::Node<::Parser::Tokens, Types::__WS>, ::ISPA_STD::Node<::Parser::Rules, Types::inversion>> group_4;
	bool success_6;
	std::vector<std::tuple<::ISPA_STD::Node<::Parser::Tokens, Types::AND>, ::ISPA_STD::Node<::Parser::Tokens, Types::__WS>, ::ISPA_STD::Node<::Parser::Rules, Types::inversion>>> shadow_24;
	std::vector<std::tuple<::ISPA_STD::Node<::Parser::Tokens, Types::AND>, ::ISPA_STD::Node<::Parser::Tokens, Types::__WS>, ::ISPA_STD::Node<::Parser::Rules, Types::inversion>>> uvar_5;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::Node<::Parser::Tokens, Types::AND> AND_8;
	::ISPA_STD::Node<::Parser::Tokens, Types::AND> uvar_7;
	std::vector<::ISPA_STD::Node<::Parser::Tokens, Types::AND>> shadow_10;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_12;
	bool success_13;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> uvar_11;
	std::vector<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>> shadow_14;
	::ISPA_STD::MatchResult<Rules, Types::inversion, IT> inversion_16;
	::ISPA_STD::Node<::Parser::Rules, Types::inversion> element_18;
	std::vector<::ISPA_STD::Node<::Parser::Rules, Types::inversion>> shadow_19;
	::ISPA_STD::Node<::Parser::Rules, Types::inversion> uvar_15;
	::ISPA_STD::Node<::Parser::Rules, Types::inversion> tuple_elem_23;
	success_1 = false;
	inversion_0 = inversion(pos);
	if (!(inversion_0.status)) {
		raise_error(*pos, "ISPA match failure: required named rule did not match | grammar: @  inversion");
		return {};
	}
	success_1 = true;
	pos = inversion_0.it;
	success_6 = false;
	auto begin_25 = pos;
	while (true) {
		auto repeat_ws_26 = begin_25;
		success_3 = false;
		if (((*repeat_ws_26)).template holds<Types::__WS>()) {
			__WS_2 = ((*repeat_ws_26)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
			success_3 = true;
			repeat_ws_26++;
		}
		if (!(((*repeat_ws_26)).template holds<Types::AND>())) {
			// speculative match failed (diagnostic suppressed):  AND
			break;
		}
		AND_8 = ((*repeat_ws_26)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::AND>>();
		success_9 = true;
		repeat_ws_26++;
		shadow_10.push_back(AND_8);
		uvar_7 = AND_8;
		success_13 = false;
		if (((*repeat_ws_26)).template holds<Types::__WS>()) {
			__WS_12 = ((*repeat_ws_26)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
			success_13 = true;
			repeat_ws_26++;
			shadow_14.push_back(__WS_12);
			uvar_11 = __WS_12;
		}
		inversion_16 = inversion(repeat_ws_26);
		if (!(inversion_16.status)) {
			// speculative match failed (diagnostic suppressed): @  inversion
			break;
		}
		success_17 = true;
		repeat_ws_26 = inversion_16.it;
		element_18 = inversion_16.node;
		shadow_19.push_back(element_18);
		if (success_9 && success_17) {
			tuple_elem_23 = inversion_16.node;
			group_4 = std::make_tuple(AND_8, __WS_12, tuple_elem_23);
			shadow_24.push_back(group_4);
			shadow_20.push_back(AND_8);
			group_capture_21 = inversion_16.node;
			shadow_22.push_back(group_capture_21);
		}
		begin_25 = repeat_ws_26;
	}
	success_6 = true;
	::ISPA_STD::assign_compatible(uvar_5, shadow_24);
	pos = begin_25;
	Types::conjunction result;
	::ISPA_STD::assign_compatible(result.first, inversion_0);
	::ISPA_STD::assign_compatible(result.rest, shadow_22);
	::ISPA_STD::MatchResult<Rules, Types::conjunction, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::conjunction<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::conjunction, ::Parser::Lexer::iterator>;
template auto Parser::Parser::conjunction<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::conjunction, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::continue_stmt(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::continue_stmt, IT> {
	::ISPA_STD::Node<::Parser::Tokens, Types::CONTINUE> CONTINUE_0;
	bool success_1;
	success_1 = false;
	if (!(((*pos)).template holds<Types::CONTINUE>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  CONTINUE");
		return {};
	}
	CONTINUE_0 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::CONTINUE>>();
	success_1 = true;
	pos++;
	Types::continue_stmt result;
	::ISPA_STD::MatchResult<Rules, Types::continue_stmt, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::continue_stmt<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::continue_stmt, ::Parser::Lexer::iterator>;
template auto Parser::Parser::continue_stmt<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::continue_stmt, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::decorated_def(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::decorated_def, IT> {
	::ISPA_STD::MatchResult<Rules, Types::decorators, IT> decorators_0;
	bool success_1;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::MatchResult<Rules, Types::def_header, IT> def_header_4;
	bool success_5;
	success_1 = false;
	decorators_0 = decorators(pos);
	if (decorators_0.status) {
		success_1 = true;
		pos = decorators_0.it;
	}
	success_3 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_2 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_3 = true;
		pos++;
	}
	success_5 = false;
	def_header_4 = def_header(pos);
	if (!(def_header_4.status)) {
		raise_error(*pos, "ISPA match failure: required named rule did not match | grammar: @  def_header");
		return {};
	}
	success_5 = true;
	pos = def_header_4.it;
	Types::decorated_def result;
	::ISPA_STD::assign_compatible(result.decorators, decorators_0);
	::ISPA_STD::assign_compatible(result.definition, def_header_4);
	::ISPA_STD::MatchResult<Rules, Types::decorated_def, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::decorated_def<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::decorated_def, ::Parser::Lexer::iterator>;
template auto Parser::Parser::decorated_def<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::decorated_def, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::decorator(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::decorator, IT> {
	::ISPA_STD::Node<::Parser::Tokens, Types::MATMUL> MATMUL_0;
	bool success_1;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::MatchResult<Rules, Types::primary, IT> primary_4;
	bool success_5;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_6;
	bool success_7;
	::ISPA_STD::Node<::Parser::Tokens, Types::NEWLINE> NEWLINE_8;
	bool success_9;
	success_1 = false;
	if (!(((*pos)).template holds<Types::MATMUL>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  MATMUL");
		return {};
	}
	MATMUL_0 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::MATMUL>>();
	success_1 = true;
	pos++;
	success_3 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_2 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_3 = true;
		pos++;
	}
	success_5 = false;
	primary_4 = primary(pos);
	if (!(primary_4.status)) {
		raise_error(*pos, "ISPA match failure: required named rule did not match | grammar: @  primary");
		return {};
	}
	success_5 = true;
	pos = primary_4.it;
	success_7 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_6 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_7 = true;
		pos++;
	}
	success_9 = false;
	if (!(((*pos)).template holds<Types::NEWLINE>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  NEWLINE");
		return {};
	}
	NEWLINE_8 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::NEWLINE>>();
	success_9 = true;
	pos++;
	Types::decorator result;
	::ISPA_STD::assign_compatible(result.value, primary_4.node);
	::ISPA_STD::MatchResult<Rules, Types::decorator, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::decorator<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::decorator, ::Parser::Lexer::iterator>;
template auto Parser::Parser::decorator<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::decorator, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::decorators(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::decorators, IT> {
	::ISPA_STD::MatchResult<Rules, Types::decorator, IT> decorator_1;
	bool success_2;
	::ISPA_STD::Node<::Parser::Rules, Types::decorator> element_3;
	std::vector<::ISPA_STD::Node<::Parser::Rules, Types::decorator>> shadow_4;
	std::vector<::ISPA_STD::Node<::Parser::Rules, Types::decorator>> uvar_0;
	bool success_5;
	success_2 = false;
	// grammar `@  decorator+;`: repeat named rule; collect every matched value
	success_5 = false;
	while (true) {
		decorator_1 = decorator(pos);
		if (!(decorator_1.status)) {
			break;
		}
		success_2 = true;
		pos = decorator_1.it;
		element_3 = decorator_1.node;
		shadow_4.push_back(element_3);
		success_5 = true;
	}
	if (!success_5) {
		return {};
	}
	::ISPA_STD::assign_compatible(uvar_0, shadow_4);
	Types::decorators result;
	::ISPA_STD::assign_compatible(result.value, uvar_0);
	::ISPA_STD::MatchResult<Rules, Types::decorators, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::decorators<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::decorators, ::Parser::Lexer::iterator>;
template auto Parser::Parser::decorators<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::decorators, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::def_header(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::def_header, IT> {
	std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Rules, Types::class_header>, ::ISPA_STD::Node<::Parser::Rules, Types::function_header>> _0;
	bool success_1;
	::ISPA_STD::MatchResult<Rules, Types::function_header, IT> function_header_2;
	bool success_3;
	::ISPA_STD::MatchResult<Rules, Types::class_header, IT> class_header_4;
	bool success_5;
	::ISPA_STD::MatchResult<Rules, Types::function_header, IT> function_header_6;
	bool success_7;
	success_1 = false;
	// grammar `@  ( function_header |  class_header)`: choice; reset match status before selecting an alternative
	success_1 = false;
	auto lookahead_pos_1 = pos;
	switch (static_cast<Tokens>((*lookahead_pos_1).kind())) {
		case Tokens::ASYNC: {
			lookahead_pos_1 = lookahead_pos_1;
			success_3 = false;
			function_header_2 = function_header(lookahead_pos_1);
			if (!(function_header_2.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  function_header");
				return {};
			}
			success_3 = true;
			lookahead_pos_1 = function_header_2.it;
			if (!success_3) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  function_header");
				return {};
			}
			_0 = function_header_2.node;
			success_1 = true;
			break;
		}
		case Tokens::CLASS: {
			lookahead_pos_1 = lookahead_pos_1;
			success_5 = false;
			class_header_4 = class_header(lookahead_pos_1);
			if (!(class_header_4.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  class_header");
				return {};
			}
			success_5 = true;
			lookahead_pos_1 = class_header_4.it;
			if (!success_5) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  class_header");
				return {};
			}
			_0 = class_header_4.node;
			success_1 = true;
			break;
		}
		case Tokens::DEF: {
			lookahead_pos_1 = lookahead_pos_1;
			success_7 = false;
			function_header_6 = function_header(lookahead_pos_1);
			if (!(function_header_6.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  function_header");
				return {};
			}
			success_7 = true;
			lookahead_pos_1 = function_header_6.it;
			if (!success_7) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  function_header");
				return {};
			}
			_0 = function_header_6.node;
			success_1 = true;
			break;
		}
	}
	pos = lookahead_pos_1;
	if (!success_1) {
		raise_error(*pos, "ISPA match failure: no LL(k) alternative matched | grammar: @  ( function_header |  class_header)");
		return {};
	}
	Types::def_header result;
	::ISPA_STD::assign_compatible(result.value, _0);
	::ISPA_STD::MatchResult<Rules, Types::def_header, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::def_header<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::def_header, ::Parser::Lexer::iterator>;
template auto Parser::Parser::def_header<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::def_header, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::del_stmt(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::del_stmt, IT> {
	::ISPA_STD::Node<::Parser::Tokens, Types::DEL> DEL_0;
	bool success_1;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::MatchResult<Rules, Types::assignment_target, IT> assignment_target_4;
	bool success_5;
	bool success_21;
	bool success_13;
	std::tuple<::ISPA_STD::Node<::Parser::Tokens, Types::COMMA>, ::ISPA_STD::Node<::Parser::Tokens, Types::__WS>, ::ISPA_STD::Node<::Parser::Rules, Types::assignment_target>> group_8;
	bool success_10;
	std::vector<std::tuple<::ISPA_STD::Node<::Parser::Tokens, Types::COMMA>, ::ISPA_STD::Node<::Parser::Tokens, Types::__WS>, ::ISPA_STD::Node<::Parser::Rules, Types::assignment_target>>> shadow_25;
	std::vector<std::tuple<::ISPA_STD::Node<::Parser::Tokens, Types::COMMA>, ::ISPA_STD::Node<::Parser::Tokens, Types::__WS>, ::ISPA_STD::Node<::Parser::Rules, Types::assignment_target>>> uvar_9;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_6;
	bool success_7;
	::ISPA_STD::Node<::Parser::Tokens, Types::COMMA> COMMA_12;
	::ISPA_STD::Node<::Parser::Tokens, Types::COMMA> uvar_11;
	std::vector<::ISPA_STD::Node<::Parser::Tokens, Types::COMMA>> shadow_14;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_16;
	bool success_17;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> uvar_15;
	std::vector<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>> shadow_18;
	::ISPA_STD::MatchResult<Rules, Types::assignment_target, IT> assignment_target_20;
	::ISPA_STD::Node<::Parser::Rules, Types::assignment_target> element_22;
	std::vector<::ISPA_STD::Node<::Parser::Rules, Types::assignment_target>> shadow_23;
	::ISPA_STD::Node<::Parser::Rules, Types::assignment_target> uvar_19;
	::ISPA_STD::Node<::Parser::Rules, Types::assignment_target> tuple_elem_24;
	success_1 = false;
	if (!(((*pos)).template holds<Types::DEL>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  DEL");
		return {};
	}
	DEL_0 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::DEL>>();
	success_1 = true;
	pos++;
	success_3 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_2 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_3 = true;
		pos++;
	}
	success_5 = false;
	assignment_target_4 = assignment_target(pos);
	if (!(assignment_target_4.status)) {
		raise_error(*pos, "ISPA match failure: required named rule did not match | grammar: @  assignment_target");
		return {};
	}
	success_5 = true;
	pos = assignment_target_4.it;
	success_10 = false;
	auto begin_26 = pos;
	while (true) {
		auto repeat_ws_27 = begin_26;
		success_7 = false;
		if (((*repeat_ws_27)).template holds<Types::__WS>()) {
			__WS_6 = ((*repeat_ws_27)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
			success_7 = true;
			repeat_ws_27++;
		}
		if (!(((*repeat_ws_27)).template holds<Types::COMMA>())) {
			// speculative match failed (diagnostic suppressed):  COMMA
			break;
		}
		COMMA_12 = ((*repeat_ws_27)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::COMMA>>();
		success_13 = true;
		repeat_ws_27++;
		shadow_14.push_back(COMMA_12);
		uvar_11 = COMMA_12;
		success_17 = false;
		if (((*repeat_ws_27)).template holds<Types::__WS>()) {
			__WS_16 = ((*repeat_ws_27)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
			success_17 = true;
			repeat_ws_27++;
			shadow_18.push_back(__WS_16);
			uvar_15 = __WS_16;
		}
		assignment_target_20 = assignment_target(repeat_ws_27);
		if (!(assignment_target_20.status)) {
			// speculative match failed (diagnostic suppressed): @  assignment_target
			break;
		}
		success_21 = true;
		repeat_ws_27 = assignment_target_20.it;
		element_22 = assignment_target_20.node;
		shadow_23.push_back(element_22);
		if (success_13 && success_21) {
			tuple_elem_24 = assignment_target_20.node;
			group_8 = std::make_tuple(COMMA_12, __WS_16, tuple_elem_24);
			shadow_25.push_back(group_8);
		}
		begin_26 = repeat_ws_27;
	}
	success_10 = true;
	::ISPA_STD::assign_compatible(uvar_9, shadow_25);
	pos = begin_26;
	Types::del_stmt result;
	::ISPA_STD::assign_compatible(result.first, assignment_target_4);
	::ISPA_STD::assign_compatible(result.rest, uvar_19);
	::ISPA_STD::MatchResult<Rules, Types::del_stmt, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::del_stmt<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::del_stmt, ::Parser::Lexer::iterator>;
template auto Parser::Parser::del_stmt<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::del_stmt, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::dict_expr(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::dict_expr, IT> {
	::ISPA_STD::Node<::Parser::Tokens, Types::LBRACE> LBRACE_0;
	bool success_1;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::MatchResult<Rules, Types::dict_items, IT> dict_items_4;
	bool success_5;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_6;
	bool success_7;
	::ISPA_STD::Node<::Parser::Tokens, Types::RBRACE> RBRACE_8;
	bool success_9;
	success_1 = false;
	if (!(((*pos)).template holds<Types::LBRACE>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  LBRACE");
		return {};
	}
	LBRACE_0 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::LBRACE>>();
	success_1 = true;
	pos++;
	success_3 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_2 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_3 = true;
		pos++;
	}
	success_5 = false;
	dict_items_4 = dict_items(pos);
	if (dict_items_4.status) {
		success_5 = true;
		pos = dict_items_4.it;
	}
	success_7 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_6 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_7 = true;
		pos++;
	}
	success_9 = false;
	if (!(((*pos)).template holds<Types::RBRACE>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  RBRACE");
		return {};
	}
	RBRACE_8 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::RBRACE>>();
	success_9 = true;
	pos++;
	Types::dict_expr result;
	::ISPA_STD::assign_compatible(result.value, dict_items_4.node);
	::ISPA_STD::MatchResult<Rules, Types::dict_expr, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::dict_expr<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::dict_expr, ::Parser::Lexer::iterator>;
template auto Parser::Parser::dict_expr<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::dict_expr, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::dict_item(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::dict_item, IT> {
	::ISPA_STD::MatchResult<Rules, Types::expr, IT> expr_0;
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
	expr_0 = expr(pos);
	if (!(expr_0.status)) {
		raise_error(*pos, "ISPA match failure: required named rule did not match | grammar: @  expr");
		return {};
	}
	success_1 = true;
	pos = expr_0.it;
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
	Types::dict_item result;
	::ISPA_STD::assign_compatible(result.key, expr_0);
	::ISPA_STD::assign_compatible(result.value, expr_8);
	::ISPA_STD::MatchResult<Rules, Types::dict_item, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::dict_item<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::dict_item, ::Parser::Lexer::iterator>;
template auto Parser::Parser::dict_item<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::dict_item, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::dict_item_tail(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::dict_item_tail, IT> {
	::ISPA_STD::Node<::Parser::Tokens, Types::COMMA> COMMA_0;
	bool success_1;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::MatchResult<Rules, Types::dict_item, IT> dict_item_4;
	bool success_5;
	success_1 = false;
	if (!(((*pos)).template holds<Types::COMMA>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  COMMA");
		return {};
	}
	COMMA_0 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::COMMA>>();
	success_1 = true;
	pos++;
	success_3 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_2 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_3 = true;
		pos++;
	}
	success_5 = false;
	dict_item_4 = dict_item(pos);
	if (!(dict_item_4.status)) {
		raise_error(*pos, "ISPA match failure: required named rule did not match | grammar: @  dict_item");
		return {};
	}
	success_5 = true;
	pos = dict_item_4.it;
	Types::dict_item_tail result;
	::ISPA_STD::assign_compatible(result.value, dict_item_4.node);
	::ISPA_STD::MatchResult<Rules, Types::dict_item_tail, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::dict_item_tail<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::dict_item_tail, ::Parser::Lexer::iterator>;
template auto Parser::Parser::dict_item_tail<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::dict_item_tail, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::dict_items(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::dict_items, IT> {
	::ISPA_STD::MatchResult<Rules, Types::dict_item, IT> dict_item_0;
	bool success_1;
	::ISPA_STD::MatchResult<Rules, Types::dict_item_tail, IT> dict_item_tail_5;
	bool success_6;
	::ISPA_STD::Node<::Parser::Rules, Types::dict_item_tail> element_7;
	std::vector<::ISPA_STD::Node<::Parser::Rules, Types::dict_item_tail>> shadow_8;
	std::vector<::ISPA_STD::Node<::Parser::Rules, Types::dict_item_tail>> uvar_4;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_10;
	bool success_11;
	::ISPA_STD::Node<::Parser::Tokens, Types::COMMA> COMMA_12;
	bool success_13;
	success_1 = false;
	dict_item_0 = dict_item(pos);
	if (!(dict_item_0.status)) {
		raise_error(*pos, "ISPA match failure: required named rule did not match | grammar: @  dict_item");
		return {};
	}
	success_1 = true;
	pos = dict_item_0.it;
	success_6 = false;
	// grammar `@  dict_item_tail*;`: repeat named rule; collect every matched value
	while (true) {
		auto repeat_ws_9 = pos;
		success_3 = false;
		if (((*repeat_ws_9)).template holds<Types::__WS>()) {
			__WS_2 = ((*repeat_ws_9)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
			success_3 = true;
			repeat_ws_9++;
		}
		dict_item_tail_5 = dict_item_tail(repeat_ws_9);
		if (!(dict_item_tail_5.status)) {
			break;
		}
		success_6 = true;
		repeat_ws_9 = dict_item_tail_5.it;
		element_7 = dict_item_tail_5.node;
		shadow_8.push_back(element_7);
		pos = repeat_ws_9;
	}
	::ISPA_STD::assign_compatible(uvar_4, shadow_8);
	success_11 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_10 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_11 = true;
		pos++;
	}
	success_13 = false;
	if (((*pos)).template holds<Types::COMMA>()) {
		COMMA_12 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::COMMA>>();
		success_13 = true;
		pos++;
	}
	Types::dict_items result;
	::ISPA_STD::assign_compatible(result.first, dict_item_0);
	::ISPA_STD::assign_compatible(result.rest, uvar_4);
	::ISPA_STD::MatchResult<Rules, Types::dict_items, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::dict_items<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::dict_items, ::Parser::Lexer::iterator>;
template auto Parser::Parser::dict_items<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::dict_items, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::disjunction(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::disjunction, IT> {
	::ISPA_STD::MatchResult<Rules, Types::conjunction, IT> conjunction_0;
	bool success_1;
	::ISPA_STD::MatchResult<Rules, Types::or_tail, IT> or_tail_5;
	bool success_6;
	::ISPA_STD::Node<::Parser::Rules, Types::or_tail> element_7;
	std::vector<::ISPA_STD::Node<::Parser::Rules, Types::or_tail>> shadow_8;
	std::vector<::ISPA_STD::Node<::Parser::Rules, Types::or_tail>> uvar_4;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	success_1 = false;
	conjunction_0 = conjunction(pos);
	if (!(conjunction_0.status)) {
		raise_error(*pos, "ISPA match failure: required named rule did not match | grammar: @  conjunction");
		return {};
	}
	success_1 = true;
	pos = conjunction_0.it;
	success_6 = false;
	// grammar `@  or_tail*;`: repeat named rule; collect every matched value
	while (true) {
		auto repeat_ws_9 = pos;
		success_3 = false;
		if (((*repeat_ws_9)).template holds<Types::__WS>()) {
			__WS_2 = ((*repeat_ws_9)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
			success_3 = true;
			repeat_ws_9++;
		}
		or_tail_5 = or_tail(repeat_ws_9);
		if (!(or_tail_5.status)) {
			break;
		}
		success_6 = true;
		repeat_ws_9 = or_tail_5.it;
		element_7 = or_tail_5.node;
		shadow_8.push_back(element_7);
		pos = repeat_ws_9;
	}
	::ISPA_STD::assign_compatible(uvar_4, shadow_8);
	Types::disjunction result;
	::ISPA_STD::assign_compatible(result.first, conjunction_0);
	::ISPA_STD::assign_compatible(result.rest, uvar_4);
	::ISPA_STD::MatchResult<Rules, Types::disjunction, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::disjunction<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::disjunction, ::Parser::Lexer::iterator>;
template auto Parser::Parser::disjunction<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::disjunction, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::dotted_as_name(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::dotted_as_name, IT> {
	::ISPA_STD::MatchResult<Rules, Types::dotted_name, IT> dotted_name_0;
	bool success_1;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::MatchResult<Rules, Types::import_alias, IT> import_alias_4;
	bool success_5;
	success_1 = false;
	dotted_name_0 = dotted_name(pos);
	if (!(dotted_name_0.status)) {
		raise_error(*pos, "ISPA match failure: required named rule did not match | grammar: @  dotted_name");
		return {};
	}
	success_1 = true;
	pos = dotted_name_0.it;
	success_3 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_2 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_3 = true;
		pos++;
	}
	success_5 = false;
	import_alias_4 = import_alias(pos);
	if (import_alias_4.status) {
		success_5 = true;
		pos = import_alias_4.it;
	}
	Types::dotted_as_name result;
	::ISPA_STD::assign_compatible(result.name, dotted_name_0);
	::ISPA_STD::assign_compatible(result.alias, import_alias_4);
	::ISPA_STD::MatchResult<Rules, Types::dotted_as_name, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::dotted_as_name<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::dotted_as_name, ::Parser::Lexer::iterator>;
template auto Parser::Parser::dotted_as_name<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::dotted_as_name, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::dotted_as_names(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::dotted_as_names, IT> {
	::ISPA_STD::MatchResult<Rules, Types::dotted_as_name, IT> dotted_as_name_0;
	bool success_1;
	bool success_17;
	bool success_9;
	std::tuple<::ISPA_STD::Node<::Parser::Tokens, Types::COMMA>, ::ISPA_STD::Node<::Parser::Tokens, Types::__WS>, ::ISPA_STD::Node<::Parser::Rules, Types::dotted_as_name>> group_4;
	bool success_6;
	std::vector<std::tuple<::ISPA_STD::Node<::Parser::Tokens, Types::COMMA>, ::ISPA_STD::Node<::Parser::Tokens, Types::__WS>, ::ISPA_STD::Node<::Parser::Rules, Types::dotted_as_name>>> shadow_21;
	std::vector<std::tuple<::ISPA_STD::Node<::Parser::Tokens, Types::COMMA>, ::ISPA_STD::Node<::Parser::Tokens, Types::__WS>, ::ISPA_STD::Node<::Parser::Rules, Types::dotted_as_name>>> uvar_5;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::Node<::Parser::Tokens, Types::COMMA> COMMA_8;
	::ISPA_STD::Node<::Parser::Tokens, Types::COMMA> uvar_7;
	std::vector<::ISPA_STD::Node<::Parser::Tokens, Types::COMMA>> shadow_10;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_12;
	bool success_13;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> uvar_11;
	std::vector<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>> shadow_14;
	::ISPA_STD::MatchResult<Rules, Types::dotted_as_name, IT> dotted_as_name_16;
	::ISPA_STD::Node<::Parser::Rules, Types::dotted_as_name> element_18;
	std::vector<::ISPA_STD::Node<::Parser::Rules, Types::dotted_as_name>> shadow_19;
	::ISPA_STD::Node<::Parser::Rules, Types::dotted_as_name> uvar_15;
	::ISPA_STD::Node<::Parser::Rules, Types::dotted_as_name> tuple_elem_20;
	success_1 = false;
	dotted_as_name_0 = dotted_as_name(pos);
	if (!(dotted_as_name_0.status)) {
		raise_error(*pos, "ISPA match failure: required named rule did not match | grammar: @  dotted_as_name");
		return {};
	}
	success_1 = true;
	pos = dotted_as_name_0.it;
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
		dotted_as_name_16 = dotted_as_name(repeat_ws_23);
		if (!(dotted_as_name_16.status)) {
			// speculative match failed (diagnostic suppressed): @  dotted_as_name
			break;
		}
		success_17 = true;
		repeat_ws_23 = dotted_as_name_16.it;
		element_18 = dotted_as_name_16.node;
		shadow_19.push_back(element_18);
		if (success_9 && success_17) {
			tuple_elem_20 = dotted_as_name_16.node;
			group_4 = std::make_tuple(COMMA_8, __WS_12, tuple_elem_20);
			shadow_21.push_back(group_4);
		}
		begin_22 = repeat_ws_23;
	}
	success_6 = true;
	::ISPA_STD::assign_compatible(uvar_5, shadow_21);
	pos = begin_22;
	Types::dotted_as_names result;
	::ISPA_STD::assign_compatible(result.first, dotted_as_name_0);
	::ISPA_STD::assign_compatible(result.rest, uvar_15);
	::ISPA_STD::MatchResult<Rules, Types::dotted_as_names, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::dotted_as_names<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::dotted_as_names, ::Parser::Lexer::iterator>;
template auto Parser::Parser::dotted_as_names<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::dotted_as_names, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::dotted_name(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::dotted_name, IT> {
	::ISPA_STD::Node<::Parser::Tokens, Types::ID> ID_0;
	bool success_1;
	bool success_17;
	bool success_9;
	std::tuple<::ISPA_STD::Node<::Parser::Tokens, Types::DOT>, ::ISPA_STD::Node<::Parser::Tokens, Types::__WS>, ::ISPA_STD::Node<::Parser::Tokens, Types::ID>> group_4;
	bool success_6;
	std::vector<std::tuple<::ISPA_STD::Node<::Parser::Tokens, Types::DOT>, ::ISPA_STD::Node<::Parser::Tokens, Types::__WS>, ::ISPA_STD::Node<::Parser::Tokens, Types::ID>>> shadow_19;
	std::vector<std::tuple<::ISPA_STD::Node<::Parser::Tokens, Types::DOT>, ::ISPA_STD::Node<::Parser::Tokens, Types::__WS>, ::ISPA_STD::Node<::Parser::Tokens, Types::ID>>> uvar_5;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::Node<::Parser::Tokens, Types::DOT> DOT_8;
	::ISPA_STD::Node<::Parser::Tokens, Types::DOT> uvar_7;
	std::vector<::ISPA_STD::Node<::Parser::Tokens, Types::DOT>> shadow_10;
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
	auto begin_20 = pos;
	while (true) {
		auto repeat_ws_21 = begin_20;
		success_3 = false;
		if (((*repeat_ws_21)).template holds<Types::__WS>()) {
			__WS_2 = ((*repeat_ws_21)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
			success_3 = true;
			repeat_ws_21++;
		}
		if (!(((*repeat_ws_21)).template holds<Types::DOT>())) {
			// speculative match failed (diagnostic suppressed):  DOT
			break;
		}
		DOT_8 = ((*repeat_ws_21)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::DOT>>();
		success_9 = true;
		repeat_ws_21++;
		shadow_10.push_back(DOT_8);
		uvar_7 = DOT_8;
		success_13 = false;
		if (((*repeat_ws_21)).template holds<Types::__WS>()) {
			__WS_12 = ((*repeat_ws_21)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
			success_13 = true;
			repeat_ws_21++;
			shadow_14.push_back(__WS_12);
			uvar_11 = __WS_12;
		}
		if (!(((*repeat_ws_21)).template holds<Types::ID>())) {
			// speculative match failed (diagnostic suppressed): @  ID
			break;
		}
		ID_16 = ((*repeat_ws_21)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::ID>>();
		success_17 = true;
		repeat_ws_21++;
		shadow_18.push_back(ID_16);
		uvar_15 = ID_16;
		if (success_9 && success_17) {
			group_4 = std::make_tuple(DOT_8, __WS_12, ID_16);
			shadow_19.push_back(group_4);
		}
		begin_20 = repeat_ws_21;
	}
	success_6 = true;
	::ISPA_STD::assign_compatible(uvar_5, shadow_19);
	pos = begin_20;
	Types::dotted_name result;
	::ISPA_STD::assign_compatible(result.first, ID_0);
	::ISPA_STD::assign_compatible(result.rest, uvar_15);
	::ISPA_STD::MatchResult<Rules, Types::dotted_name, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::dotted_name<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::dotted_name, ::Parser::Lexer::iterator>;
template auto Parser::Parser::dotted_name<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::dotted_name, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::elif_clause(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::elif_clause, IT> {
	::ISPA_STD::Node<::Parser::Tokens, Types::ELIF> ELIF_0;
	bool success_1;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::MatchResult<Rules, Types::expr, IT> expr_4;
	bool success_5;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_6;
	bool success_7;
	::ISPA_STD::Node<::Parser::Tokens, Types::COLON> COLON_8;
	bool success_9;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_10;
	bool success_11;
	::ISPA_STD::MatchResult<Rules, Types::block, IT> block_12;
	bool success_13;
	success_1 = false;
	if (!(((*pos)).template holds<Types::ELIF>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  ELIF");
		return {};
	}
	ELIF_0 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::ELIF>>();
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
	if (!(((*pos)).template holds<Types::COLON>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  COLON");
		return {};
	}
	COLON_8 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::COLON>>();
	success_9 = true;
	pos++;
	success_11 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_10 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_11 = true;
		pos++;
	}
	success_13 = false;
	block_12 = block(pos);
	if (!(block_12.status)) {
		raise_error(*pos, "ISPA match failure: required named rule did not match | grammar: @  block");
		return {};
	}
	success_13 = true;
	pos = block_12.it;
	Types::elif_clause result;
	::ISPA_STD::assign_compatible(result.condition, expr_4);
	::ISPA_STD::assign_compatible(result.body, block_12);
	::ISPA_STD::MatchResult<Rules, Types::elif_clause, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::elif_clause<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::elif_clause, ::Parser::Lexer::iterator>;
template auto Parser::Parser::elif_clause<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::elif_clause, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::else_clause(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::else_clause, IT> {
	::ISPA_STD::Node<::Parser::Tokens, Types::ELSE> ELSE_0;
	bool success_1;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::Node<::Parser::Tokens, Types::COLON> COLON_4;
	bool success_5;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_6;
	bool success_7;
	::ISPA_STD::MatchResult<Rules, Types::block, IT> block_8;
	bool success_9;
	success_1 = false;
	if (!(((*pos)).template holds<Types::ELSE>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  ELSE");
		return {};
	}
	ELSE_0 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::ELSE>>();
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
	block_8 = block(pos);
	if (!(block_8.status)) {
		raise_error(*pos, "ISPA match failure: required named rule did not match | grammar: @  block");
		return {};
	}
	success_9 = true;
	pos = block_8.it;
	Types::else_clause result;
	::ISPA_STD::assign_compatible(result.value, block_8.node);
	::ISPA_STD::MatchResult<Rules, Types::else_clause, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::else_clause<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::else_clause, ::Parser::Lexer::iterator>;
template auto Parser::Parser::else_clause<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::else_clause, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::except_alias(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::except_alias, IT> {
	::ISPA_STD::Node<::Parser::Tokens, Types::AS> AS_0;
	bool success_1;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::Node<::Parser::Tokens, Types::ID> ID_4;
	bool success_5;
	success_1 = false;
	if (!(((*pos)).template holds<Types::AS>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  AS");
		return {};
	}
	AS_0 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::AS>>();
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
	Types::except_alias result;
	::ISPA_STD::assign_compatible(result.value, ID_4);
	::ISPA_STD::MatchResult<Rules, Types::except_alias, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::except_alias<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::except_alias, ::Parser::Lexer::iterator>;
template auto Parser::Parser::except_alias<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::except_alias, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::except_clause(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::except_clause, IT> {
	::ISPA_STD::Node<::Parser::Tokens, Types::EXCEPT> EXCEPT_0;
	bool success_1;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::MatchResult<Rules, Types::expr, IT> expr_4;
	bool success_5;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_6;
	bool success_7;
	::ISPA_STD::MatchResult<Rules, Types::except_alias, IT> except_alias_8;
	bool success_9;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_10;
	bool success_11;
	::ISPA_STD::Node<::Parser::Tokens, Types::COLON> COLON_12;
	bool success_13;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_14;
	bool success_15;
	::ISPA_STD::MatchResult<Rules, Types::block, IT> block_16;
	bool success_17;
	success_1 = false;
	if (!(((*pos)).template holds<Types::EXCEPT>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  EXCEPT");
		return {};
	}
	EXCEPT_0 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::EXCEPT>>();
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
	if (expr_4.status) {
		success_5 = true;
		pos = expr_4.it;
	}
	success_7 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_6 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_7 = true;
		pos++;
	}
	success_9 = false;
	except_alias_8 = except_alias(pos);
	if (except_alias_8.status) {
		success_9 = true;
		pos = except_alias_8.it;
	}
	success_11 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_10 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_11 = true;
		pos++;
	}
	success_13 = false;
	if (!(((*pos)).template holds<Types::COLON>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  COLON");
		return {};
	}
	COLON_12 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::COLON>>();
	success_13 = true;
	pos++;
	success_15 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_14 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_15 = true;
		pos++;
	}
	success_17 = false;
	block_16 = block(pos);
	if (!(block_16.status)) {
		raise_error(*pos, "ISPA match failure: required named rule did not match | grammar: @  block");
		return {};
	}
	success_17 = true;
	pos = block_16.it;
	Types::except_clause result;
	::ISPA_STD::assign_compatible(result.exception, expr_4);
	::ISPA_STD::assign_compatible(result.alias, except_alias_8);
	::ISPA_STD::assign_compatible(result.body, block_16);
	::ISPA_STD::MatchResult<Rules, Types::except_clause, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::except_clause<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::except_clause, ::Parser::Lexer::iterator>;
template auto Parser::Parser::except_clause<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::except_clause, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::except_handlers(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::except_handlers, IT> {
	::ISPA_STD::MatchResult<Rules, Types::except_clause, IT> except_clause_1;
	bool success_2;
	::ISPA_STD::Node<::Parser::Rules, Types::except_clause> element_3;
	std::vector<::ISPA_STD::Node<::Parser::Rules, Types::except_clause>> shadow_4;
	std::vector<::ISPA_STD::Node<::Parser::Rules, Types::except_clause>> uvar_0;
	bool success_5;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_6;
	bool success_7;
	::ISPA_STD::MatchResult<Rules, Types::else_clause, IT> else_clause_8;
	bool success_9;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_10;
	bool success_11;
	::ISPA_STD::MatchResult<Rules, Types::finally_clause, IT> finally_clause_12;
	bool success_13;
	success_2 = false;
	// grammar `@  except_clause+;`: repeat named rule; collect every matched value
	success_5 = false;
	while (true) {
		except_clause_1 = except_clause(pos);
		if (!(except_clause_1.status)) {
			break;
		}
		success_2 = true;
		pos = except_clause_1.it;
		element_3 = except_clause_1.node;
		shadow_4.push_back(element_3);
		success_5 = true;
	}
	if (!success_5) {
		return {};
	}
	::ISPA_STD::assign_compatible(uvar_0, shadow_4);
	success_7 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_6 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_7 = true;
		pos++;
	}
	success_9 = false;
	else_clause_8 = else_clause(pos);
	if (else_clause_8.status) {
		success_9 = true;
		pos = else_clause_8.it;
	}
	success_11 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_10 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_11 = true;
		pos++;
	}
	success_13 = false;
	finally_clause_12 = finally_clause(pos);
	if (finally_clause_12.status) {
		success_13 = true;
		pos = finally_clause_12.it;
	}
	Types::except_handlers result;
	::ISPA_STD::assign_compatible(result.handlers, uvar_0);
	::ISPA_STD::assign_compatible(result.otherwise, else_clause_8);
	::ISPA_STD::assign_compatible(result.finalizer, finally_clause_12);
	::ISPA_STD::MatchResult<Rules, Types::except_handlers, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::except_handlers<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::except_handlers, ::Parser::Lexer::iterator>;
template auto Parser::Parser::except_handlers<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::except_handlers, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::expr(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::expr, IT> {
	::ISPA_STD::MatchResult<Rules, Types::disjunction, IT> disjunction_0;
	bool success_1;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::MatchResult<Rules, Types::conditional_tail, IT> conditional_tail_4;
	bool success_5;
	success_1 = false;
	disjunction_0 = disjunction(pos);
	if (!(disjunction_0.status)) {
		raise_error(*pos, "ISPA match failure: required named rule did not match | grammar: @  disjunction");
		return {};
	}
	success_1 = true;
	pos = disjunction_0.it;
	success_3 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_2 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_3 = true;
		pos++;
	}
	success_5 = false;
	conditional_tail_4 = conditional_tail(pos);
	if (conditional_tail_4.status) {
		success_5 = true;
		pos = conditional_tail_4.it;
	}
	Types::expr result;
	::ISPA_STD::assign_compatible(result.value, disjunction_0);
	::ISPA_STD::assign_compatible(result.conditional, conditional_tail_4);
	::ISPA_STD::MatchResult<Rules, Types::expr, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::expr<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::expr, ::Parser::Lexer::iterator>;
template auto Parser::Parser::expr<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::expr, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::expr_list(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::expr_list, IT> {
	::ISPA_STD::MatchResult<Rules, Types::expr, IT> expr_0;
	bool success_1;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::MatchResult<Rules, Types::expr_list_tail, IT> expr_list_tail_4;
	bool success_5;
	success_1 = false;
	expr_0 = expr(pos);
	if (!(expr_0.status)) {
		raise_error(*pos, "ISPA match failure: required named rule did not match | grammar: @  expr");
		return {};
	}
	success_1 = true;
	pos = expr_0.it;
	success_3 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_2 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_3 = true;
		pos++;
	}
	success_5 = false;
	expr_list_tail_4 = expr_list_tail(pos);
	if (expr_list_tail_4.status) {
		success_5 = true;
		pos = expr_list_tail_4.it;
	}
	Types::expr_list result;
	::ISPA_STD::assign_compatible(result.first, expr_0);
	::ISPA_STD::assign_compatible(result.rest, expr_list_tail_4);
	::ISPA_STD::MatchResult<Rules, Types::expr_list, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::expr_list<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::expr_list, ::Parser::Lexer::iterator>;
template auto Parser::Parser::expr_list<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::expr_list, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::expr_list_tail(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::expr_list_tail, IT> {
	bool success_13;
	bool success_5;
	std::tuple<::ISPA_STD::Node<::Parser::Tokens, Types::COMMA>, ::ISPA_STD::Node<::Parser::Tokens, Types::__WS>, ::ISPA_STD::Node<::Parser::Rules, Types::expr>> group_0;
	bool success_2;
	std::vector<std::tuple<::ISPA_STD::Node<::Parser::Tokens, Types::COMMA>, ::ISPA_STD::Node<::Parser::Tokens, Types::__WS>, ::ISPA_STD::Node<::Parser::Rules, Types::expr>>> shadow_17;
	std::vector<std::tuple<::ISPA_STD::Node<::Parser::Tokens, Types::COMMA>, ::ISPA_STD::Node<::Parser::Tokens, Types::__WS>, ::ISPA_STD::Node<::Parser::Rules, Types::expr>>> uvar_1;
	::ISPA_STD::Node<::Parser::Tokens, Types::COMMA> COMMA_4;
	::ISPA_STD::Node<::Parser::Tokens, Types::COMMA> uvar_3;
	std::vector<::ISPA_STD::Node<::Parser::Tokens, Types::COMMA>> shadow_6;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_8;
	bool success_9;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> uvar_7;
	std::vector<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>> shadow_10;
	::ISPA_STD::MatchResult<Rules, Types::expr, IT> expr_12;
	::ISPA_STD::Node<::Parser::Rules, Types::expr> element_14;
	std::vector<::ISPA_STD::Node<::Parser::Rules, Types::expr>> shadow_15;
	::ISPA_STD::Node<::Parser::Rules, Types::expr> uvar_11;
	::ISPA_STD::Node<::Parser::Rules, Types::expr> tuple_elem_16;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_19;
	bool success_20;
	::ISPA_STD::Node<::Parser::Tokens, Types::COMMA> COMMA_21;
	bool success_22;
	success_2 = false;
	auto begin_18 = pos;
	while (true) {
		if (!(((*begin_18)).template holds<Types::COMMA>())) {
			// speculative match failed (diagnostic suppressed):  COMMA
			break;
		}
		COMMA_4 = ((*begin_18)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::COMMA>>();
		success_5 = true;
		begin_18++;
		shadow_6.push_back(COMMA_4);
		uvar_3 = COMMA_4;
		success_9 = false;
		if (((*begin_18)).template holds<Types::__WS>()) {
			__WS_8 = ((*begin_18)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
			success_9 = true;
			begin_18++;
			shadow_10.push_back(__WS_8);
			uvar_7 = __WS_8;
		}
		expr_12 = expr(begin_18);
		if (!(expr_12.status)) {
			// speculative match failed (diagnostic suppressed): @  expr
			break;
		}
		success_13 = true;
		begin_18 = expr_12.it;
		element_14 = expr_12.node;
		shadow_15.push_back(element_14);
		if (success_5 && success_13) {
			tuple_elem_16 = expr_12.node;
			group_0 = std::make_tuple(COMMA_4, __WS_8, tuple_elem_16);
			shadow_17.push_back(group_0);
		}
	}
	success_2 = true;
	::ISPA_STD::assign_compatible(uvar_1, shadow_17);
	pos = begin_18;
	success_20 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_19 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_20 = true;
		pos++;
	}
	success_22 = false;
	if (((*pos)).template holds<Types::COMMA>()) {
		COMMA_21 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::COMMA>>();
		success_22 = true;
		pos++;
	}
	Types::expr_list_tail result;
	::ISPA_STD::assign_compatible(result.value, uvar_11);
	::ISPA_STD::MatchResult<Rules, Types::expr_list_tail, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::expr_list_tail<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::expr_list_tail, ::Parser::Lexer::iterator>;
template auto Parser::Parser::expr_list_tail<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::expr_list_tail, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::expr_stmt(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::expr_stmt, IT> {
	::ISPA_STD::MatchResult<Rules, Types::expr, IT> expr_0;
	bool success_1;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::MatchResult<Rules, Types::assignment_value, IT> assignment_value_4;
	bool success_5;
	success_1 = false;
	expr_0 = expr(pos);
	if (!(expr_0.status)) {
		raise_error(*pos, "ISPA match failure: required named rule did not match | grammar: @  expr");
		return {};
	}
	success_1 = true;
	pos = expr_0.it;
	success_3 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_2 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_3 = true;
		pos++;
	}
	success_5 = false;
	assignment_value_4 = assignment_value(pos);
	if (assignment_value_4.status) {
		success_5 = true;
		pos = assignment_value_4.it;
	}
	Types::expr_stmt result;
	::ISPA_STD::assign_compatible(result.target, expr_0);
	::ISPA_STD::assign_compatible(result.assignment, assignment_value_4);
	::ISPA_STD::MatchResult<Rules, Types::expr_stmt, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::expr_stmt<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::expr_stmt, ::Parser::Lexer::iterator>;
template auto Parser::Parser::expr_stmt<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::expr_stmt, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::factor(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::factor, IT> {
	std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Rules, Types::power>, ::ISPA_STD::Node<::Parser::Rules, Types::unary_expr>> _0;
	bool success_1;
	::ISPA_STD::MatchResult<Rules, Types::power, IT> power_2;
	bool success_3;
	::ISPA_STD::MatchResult<Rules, Types::power, IT> power_4;
	bool success_5;
	::ISPA_STD::MatchResult<Rules, Types::power, IT> power_6;
	bool success_7;
	::ISPA_STD::MatchResult<Rules, Types::power, IT> power_8;
	bool success_9;
	::ISPA_STD::MatchResult<Rules, Types::power, IT> power_10;
	bool success_11;
	::ISPA_STD::MatchResult<Rules, Types::unary_expr, IT> unary_expr_12;
	bool success_13;
	::ISPA_STD::MatchResult<Rules, Types::power, IT> power_14;
	bool success_15;
	::ISPA_STD::MatchResult<Rules, Types::power, IT> power_16;
	bool success_17;
	::ISPA_STD::MatchResult<Rules, Types::unary_expr, IT> unary_expr_18;
	bool success_19;
	::ISPA_STD::MatchResult<Rules, Types::power, IT> power_20;
	bool success_21;
	::ISPA_STD::MatchResult<Rules, Types::unary_expr, IT> unary_expr_22;
	bool success_23;
	::ISPA_STD::MatchResult<Rules, Types::power, IT> power_24;
	bool success_25;
	success_1 = false;
	// grammar `@  ( unary_expr |  power)`: choice; reset match status before selecting an alternative
	success_1 = false;
	auto lookahead_pos_1 = pos;
	switch (static_cast<Tokens>((*lookahead_pos_1).kind())) {
		case Tokens::FALSE: {
			lookahead_pos_1 = lookahead_pos_1;
			success_3 = false;
			power_2 = power(lookahead_pos_1);
			if (!(power_2.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  power");
				return {};
			}
			success_3 = true;
			lookahead_pos_1 = power_2.it;
			if (!success_3) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  power");
				return {};
			}
			_0 = power_2.node;
			success_1 = true;
			break;
		}
		case Tokens::ID: {
			lookahead_pos_1 = lookahead_pos_1;
			success_5 = false;
			power_4 = power(lookahead_pos_1);
			if (!(power_4.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  power");
				return {};
			}
			success_5 = true;
			lookahead_pos_1 = power_4.it;
			if (!success_5) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  power");
				return {};
			}
			_0 = power_4.node;
			success_1 = true;
			break;
		}
		case Tokens::LBRACE: {
			lookahead_pos_1 = lookahead_pos_1;
			success_7 = false;
			power_6 = power(lookahead_pos_1);
			if (!(power_6.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  power");
				return {};
			}
			success_7 = true;
			lookahead_pos_1 = power_6.it;
			if (!success_7) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  power");
				return {};
			}
			_0 = power_6.node;
			success_1 = true;
			break;
		}
		case Tokens::LBRACKET: {
			lookahead_pos_1 = lookahead_pos_1;
			success_9 = false;
			power_8 = power(lookahead_pos_1);
			if (!(power_8.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  power");
				return {};
			}
			success_9 = true;
			lookahead_pos_1 = power_8.it;
			if (!success_9) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  power");
				return {};
			}
			_0 = power_8.node;
			success_1 = true;
			break;
		}
		case Tokens::LPAREN: {
			lookahead_pos_1 = lookahead_pos_1;
			success_11 = false;
			power_10 = power(lookahead_pos_1);
			if (!(power_10.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  power");
				return {};
			}
			success_11 = true;
			lookahead_pos_1 = power_10.it;
			if (!success_11) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  power");
				return {};
			}
			_0 = power_10.node;
			success_1 = true;
			break;
		}
		case Tokens::MINUS: {
			lookahead_pos_1 = lookahead_pos_1;
			success_13 = false;
			unary_expr_12 = unary_expr(lookahead_pos_1);
			if (!(unary_expr_12.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  unary_expr");
				return {};
			}
			success_13 = true;
			lookahead_pos_1 = unary_expr_12.it;
			if (!success_13) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  unary_expr");
				return {};
			}
			_0 = unary_expr_12.node;
			success_1 = true;
			break;
		}
		case Tokens::NONE_V: {
			lookahead_pos_1 = lookahead_pos_1;
			success_15 = false;
			power_14 = power(lookahead_pos_1);
			if (!(power_14.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  power");
				return {};
			}
			success_15 = true;
			lookahead_pos_1 = power_14.it;
			if (!success_15) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  power");
				return {};
			}
			_0 = power_14.node;
			success_1 = true;
			break;
		}
		case Tokens::NUMBER: {
			lookahead_pos_1 = lookahead_pos_1;
			success_17 = false;
			power_16 = power(lookahead_pos_1);
			if (!(power_16.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  power");
				return {};
			}
			success_17 = true;
			lookahead_pos_1 = power_16.it;
			if (!success_17) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  power");
				return {};
			}
			_0 = power_16.node;
			success_1 = true;
			break;
		}
		case Tokens::PLUS: {
			lookahead_pos_1 = lookahead_pos_1;
			success_19 = false;
			unary_expr_18 = unary_expr(lookahead_pos_1);
			if (!(unary_expr_18.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  unary_expr");
				return {};
			}
			success_19 = true;
			lookahead_pos_1 = unary_expr_18.it;
			if (!success_19) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  unary_expr");
				return {};
			}
			_0 = unary_expr_18.node;
			success_1 = true;
			break;
		}
		case Tokens::STRING: {
			lookahead_pos_1 = lookahead_pos_1;
			success_21 = false;
			power_20 = power(lookahead_pos_1);
			if (!(power_20.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  power");
				return {};
			}
			success_21 = true;
			lookahead_pos_1 = power_20.it;
			if (!success_21) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  power");
				return {};
			}
			_0 = power_20.node;
			success_1 = true;
			break;
		}
		case Tokens::TILDE: {
			lookahead_pos_1 = lookahead_pos_1;
			success_23 = false;
			unary_expr_22 = unary_expr(lookahead_pos_1);
			if (!(unary_expr_22.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  unary_expr");
				return {};
			}
			success_23 = true;
			lookahead_pos_1 = unary_expr_22.it;
			if (!success_23) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  unary_expr");
				return {};
			}
			_0 = unary_expr_22.node;
			success_1 = true;
			break;
		}
		case Tokens::TRUE: {
			lookahead_pos_1 = lookahead_pos_1;
			success_25 = false;
			power_24 = power(lookahead_pos_1);
			if (!(power_24.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  power");
				return {};
			}
			success_25 = true;
			lookahead_pos_1 = power_24.it;
			if (!success_25) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  power");
				return {};
			}
			_0 = power_24.node;
			success_1 = true;
			break;
		}
	}
	pos = lookahead_pos_1;
	if (!success_1) {
		raise_error(*pos, "ISPA match failure: no LL(k) alternative matched | grammar: @  ( unary_expr |  power)");
		return {};
	}
	Types::factor result;
	::ISPA_STD::assign_compatible(result.value, _0);
	::ISPA_STD::MatchResult<Rules, Types::factor, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::factor<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::factor, ::Parser::Lexer::iterator>;
template auto Parser::Parser::factor<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::factor, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::finally_clause(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::finally_clause, IT> {
	::ISPA_STD::Node<::Parser::Tokens, Types::FINALLY> FINALLY_0;
	bool success_1;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::Node<::Parser::Tokens, Types::COLON> COLON_4;
	bool success_5;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_6;
	bool success_7;
	::ISPA_STD::MatchResult<Rules, Types::block, IT> block_8;
	bool success_9;
	success_1 = false;
	if (!(((*pos)).template holds<Types::FINALLY>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  FINALLY");
		return {};
	}
	FINALLY_0 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::FINALLY>>();
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
	block_8 = block(pos);
	if (!(block_8.status)) {
		raise_error(*pos, "ISPA match failure: required named rule did not match | grammar: @  block");
		return {};
	}
	success_9 = true;
	pos = block_8.it;
	Types::finally_clause result;
	::ISPA_STD::assign_compatible(result.value, block_8.node);
	::ISPA_STD::MatchResult<Rules, Types::finally_clause, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::finally_clause<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::finally_clause, ::Parser::Lexer::iterator>;
template auto Parser::Parser::finally_clause<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::finally_clause, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::for_stmt(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::for_stmt, IT> {
	::ISPA_STD::Node<::Parser::Tokens, Types::ASYNC> ASYNC_0;
	bool success_1;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::Node<::Parser::Tokens, Types::FOR> FOR_4;
	bool success_5;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_6;
	bool success_7;
	::ISPA_STD::MatchResult<Rules, Types::for_targets, IT> for_targets_8;
	bool success_9;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_10;
	bool success_11;
	::ISPA_STD::Node<::Parser::Tokens, Types::IN> IN_12;
	bool success_13;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_14;
	bool success_15;
	::ISPA_STD::MatchResult<Rules, Types::expr, IT> expr_16;
	bool success_17;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_18;
	bool success_19;
	::ISPA_STD::Node<::Parser::Tokens, Types::COLON> COLON_20;
	bool success_21;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_22;
	bool success_23;
	::ISPA_STD::MatchResult<Rules, Types::block, IT> block_24;
	bool success_25;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_26;
	bool success_27;
	::ISPA_STD::MatchResult<Rules, Types::else_clause, IT> else_clause_28;
	bool success_29;
	success_1 = false;
	if (((*pos)).template holds<Types::ASYNC>()) {
		ASYNC_0 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::ASYNC>>();
		success_1 = true;
		pos++;
	}
	success_3 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_2 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_3 = true;
		pos++;
	}
	success_5 = false;
	if (!(((*pos)).template holds<Types::FOR>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  FOR");
		return {};
	}
	FOR_4 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::FOR>>();
	success_5 = true;
	pos++;
	success_7 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_6 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_7 = true;
		pos++;
	}
	success_9 = false;
	for_targets_8 = for_targets(pos);
	if (!(for_targets_8.status)) {
		raise_error(*pos, "ISPA match failure: required named rule did not match | grammar: @  for_targets");
		return {};
	}
	success_9 = true;
	pos = for_targets_8.it;
	success_11 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_10 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_11 = true;
		pos++;
	}
	success_13 = false;
	if (!(((*pos)).template holds<Types::IN>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  IN");
		return {};
	}
	IN_12 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::IN>>();
	success_13 = true;
	pos++;
	success_15 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_14 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_15 = true;
		pos++;
	}
	success_17 = false;
	expr_16 = expr(pos);
	if (!(expr_16.status)) {
		raise_error(*pos, "ISPA match failure: required named rule did not match | grammar: @  expr");
		return {};
	}
	success_17 = true;
	pos = expr_16.it;
	success_19 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_18 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_19 = true;
		pos++;
	}
	success_21 = false;
	if (!(((*pos)).template holds<Types::COLON>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  COLON");
		return {};
	}
	COLON_20 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::COLON>>();
	success_21 = true;
	pos++;
	success_23 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_22 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_23 = true;
		pos++;
	}
	success_25 = false;
	block_24 = block(pos);
	if (!(block_24.status)) {
		raise_error(*pos, "ISPA match failure: required named rule did not match | grammar: @  block");
		return {};
	}
	success_25 = true;
	pos = block_24.it;
	success_27 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_26 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_27 = true;
		pos++;
	}
	success_29 = false;
	else_clause_28 = else_clause(pos);
	if (else_clause_28.status) {
		success_29 = true;
		pos = else_clause_28.it;
	}
	Types::for_stmt result;
	::ISPA_STD::assign_compatible(result.async, ASYNC_0);
	::ISPA_STD::assign_compatible(result.targets, for_targets_8);
	::ISPA_STD::assign_compatible(result.iterable, expr_16);
	::ISPA_STD::assign_compatible(result.body, block_24);
	::ISPA_STD::assign_compatible(result.otherwise, else_clause_28);
	::ISPA_STD::MatchResult<Rules, Types::for_stmt, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::for_stmt<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::for_stmt, ::Parser::Lexer::iterator>;
template auto Parser::Parser::for_stmt<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::for_stmt, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::for_targets(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::for_targets, IT> {
	::ISPA_STD::MatchResult<Rules, Types::assignment_target, IT> assignment_target_0;
	bool success_1;
	bool success_17;
	bool success_9;
	std::tuple<::ISPA_STD::Node<::Parser::Tokens, Types::COMMA>, ::ISPA_STD::Node<::Parser::Tokens, Types::__WS>, ::ISPA_STD::Node<::Parser::Rules, Types::assignment_target>> group_4;
	bool success_6;
	std::vector<std::tuple<::ISPA_STD::Node<::Parser::Tokens, Types::COMMA>, ::ISPA_STD::Node<::Parser::Tokens, Types::__WS>, ::ISPA_STD::Node<::Parser::Rules, Types::assignment_target>>> shadow_21;
	std::vector<std::tuple<::ISPA_STD::Node<::Parser::Tokens, Types::COMMA>, ::ISPA_STD::Node<::Parser::Tokens, Types::__WS>, ::ISPA_STD::Node<::Parser::Rules, Types::assignment_target>>> uvar_5;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::Node<::Parser::Tokens, Types::COMMA> COMMA_8;
	::ISPA_STD::Node<::Parser::Tokens, Types::COMMA> uvar_7;
	std::vector<::ISPA_STD::Node<::Parser::Tokens, Types::COMMA>> shadow_10;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_12;
	bool success_13;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> uvar_11;
	std::vector<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>> shadow_14;
	::ISPA_STD::MatchResult<Rules, Types::assignment_target, IT> assignment_target_16;
	::ISPA_STD::Node<::Parser::Rules, Types::assignment_target> element_18;
	std::vector<::ISPA_STD::Node<::Parser::Rules, Types::assignment_target>> shadow_19;
	::ISPA_STD::Node<::Parser::Rules, Types::assignment_target> uvar_15;
	::ISPA_STD::Node<::Parser::Rules, Types::assignment_target> tuple_elem_20;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_24;
	bool success_25;
	::ISPA_STD::Node<::Parser::Tokens, Types::COMMA> COMMA_26;
	bool success_27;
	success_1 = false;
	assignment_target_0 = assignment_target(pos);
	if (!(assignment_target_0.status)) {
		raise_error(*pos, "ISPA match failure: required named rule did not match | grammar: @  assignment_target");
		return {};
	}
	success_1 = true;
	pos = assignment_target_0.it;
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
		assignment_target_16 = assignment_target(repeat_ws_23);
		if (!(assignment_target_16.status)) {
			// speculative match failed (diagnostic suppressed): @  assignment_target
			break;
		}
		success_17 = true;
		repeat_ws_23 = assignment_target_16.it;
		element_18 = assignment_target_16.node;
		shadow_19.push_back(element_18);
		if (success_9 && success_17) {
			tuple_elem_20 = assignment_target_16.node;
			group_4 = std::make_tuple(COMMA_8, __WS_12, tuple_elem_20);
			shadow_21.push_back(group_4);
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
	if (((*pos)).template holds<Types::COMMA>()) {
		COMMA_26 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::COMMA>>();
		success_27 = true;
		pos++;
	}
	Types::for_targets result;
	::ISPA_STD::assign_compatible(result.first, assignment_target_0);
	::ISPA_STD::assign_compatible(result.rest, uvar_15);
	::ISPA_STD::MatchResult<Rules, Types::for_targets, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::for_targets<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::for_targets, ::Parser::Lexer::iterator>;
template auto Parser::Parser::for_targets<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::for_targets, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::function_def(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::function_def, IT> {
	::ISPA_STD::MatchResult<Rules, Types::decorators, IT> decorators_0;
	bool success_1;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::MatchResult<Rules, Types::function_header, IT> function_header_4;
	bool success_5;
	success_1 = false;
	decorators_0 = decorators(pos);
	if (decorators_0.status) {
		success_1 = true;
		pos = decorators_0.it;
	}
	success_3 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_2 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_3 = true;
		pos++;
	}
	success_5 = false;
	function_header_4 = function_header(pos);
	if (!(function_header_4.status)) {
		raise_error(*pos, "ISPA match failure: required named rule did not match | grammar: @  function_header");
		return {};
	}
	success_5 = true;
	pos = function_header_4.it;
	Types::function_def result;
	::ISPA_STD::assign_compatible(result.decorators, decorators_0);
	::ISPA_STD::assign_compatible(result.definition, function_header_4);
	::ISPA_STD::MatchResult<Rules, Types::function_def, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::function_def<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::function_def, ::Parser::Lexer::iterator>;
template auto Parser::Parser::function_def<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::function_def, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::function_header(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::function_header, IT> {
	::ISPA_STD::Node<::Parser::Tokens, Types::ASYNC> ASYNC_0;
	bool success_1;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::Node<::Parser::Tokens, Types::DEF> DEF_4;
	bool success_5;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_6;
	bool success_7;
	::ISPA_STD::Node<::Parser::Tokens, Types::ID> ID_8;
	bool success_9;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_10;
	bool success_11;
	::ISPA_STD::Node<::Parser::Tokens, Types::LPAREN> LPAREN_12;
	bool success_13;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_14;
	bool success_15;
	::ISPA_STD::MatchResult<Rules, Types::parameters, IT> parameters_16;
	bool success_17;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_18;
	bool success_19;
	::ISPA_STD::Node<::Parser::Tokens, Types::RPAREN> RPAREN_20;
	bool success_21;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_22;
	bool success_23;
	::ISPA_STD::MatchResult<Rules, Types::return_annotation, IT> return_annotation_24;
	bool success_25;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_26;
	bool success_27;
	::ISPA_STD::Node<::Parser::Tokens, Types::COLON> COLON_28;
	bool success_29;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_30;
	bool success_31;
	::ISPA_STD::MatchResult<Rules, Types::block, IT> block_32;
	bool success_33;
	success_1 = false;
	if (((*pos)).template holds<Types::ASYNC>()) {
		ASYNC_0 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::ASYNC>>();
		success_1 = true;
		pos++;
	}
	success_3 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_2 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_3 = true;
		pos++;
	}
	success_5 = false;
	if (!(((*pos)).template holds<Types::DEF>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  DEF");
		return {};
	}
	DEF_4 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::DEF>>();
	success_5 = true;
	pos++;
	success_7 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_6 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_7 = true;
		pos++;
	}
	success_9 = false;
	if (!(((*pos)).template holds<Types::ID>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar: @  ID");
		return {};
	}
	ID_8 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::ID>>();
	success_9 = true;
	pos++;
	success_11 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_10 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_11 = true;
		pos++;
	}
	success_13 = false;
	if (!(((*pos)).template holds<Types::LPAREN>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  LPAREN");
		return {};
	}
	LPAREN_12 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::LPAREN>>();
	success_13 = true;
	pos++;
	success_15 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_14 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_15 = true;
		pos++;
	}
	success_17 = false;
	parameters_16 = parameters(pos);
	if (parameters_16.status) {
		success_17 = true;
		pos = parameters_16.it;
	}
	success_19 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_18 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_19 = true;
		pos++;
	}
	success_21 = false;
	if (!(((*pos)).template holds<Types::RPAREN>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  RPAREN");
		return {};
	}
	RPAREN_20 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::RPAREN>>();
	success_21 = true;
	pos++;
	success_23 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_22 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_23 = true;
		pos++;
	}
	success_25 = false;
	return_annotation_24 = return_annotation(pos);
	if (return_annotation_24.status) {
		success_25 = true;
		pos = return_annotation_24.it;
	}
	success_27 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_26 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_27 = true;
		pos++;
	}
	success_29 = false;
	if (!(((*pos)).template holds<Types::COLON>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  COLON");
		return {};
	}
	COLON_28 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::COLON>>();
	success_29 = true;
	pos++;
	success_31 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_30 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_31 = true;
		pos++;
	}
	success_33 = false;
	block_32 = block(pos);
	if (!(block_32.status)) {
		raise_error(*pos, "ISPA match failure: required named rule did not match | grammar: @  block");
		return {};
	}
	success_33 = true;
	pos = block_32.it;
	Types::function_header result;
	::ISPA_STD::assign_compatible(result.async, ASYNC_0);
	::ISPA_STD::assign_compatible(result.name, ID_8);
	::ISPA_STD::assign_compatible(result.params, parameters_16);
	::ISPA_STD::assign_compatible(result.returns, return_annotation_24);
	::ISPA_STD::assign_compatible(result.body, block_32);
	::ISPA_STD::MatchResult<Rules, Types::function_header, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::function_header<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::function_header, ::Parser::Lexer::iterator>;
template auto Parser::Parser::function_header<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::function_header, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::global_stmt(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::global_stmt, IT> {
	::ISPA_STD::Node<::Parser::Tokens, Types::GLOBAL> GLOBAL_0;
	bool success_1;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::Node<::Parser::Tokens, Types::ID> ID_4;
	bool success_5;
	bool success_21;
	bool success_13;
	std::tuple<::ISPA_STD::Node<::Parser::Tokens, Types::COMMA>, ::ISPA_STD::Node<::Parser::Tokens, Types::__WS>, ::ISPA_STD::Node<::Parser::Tokens, Types::ID>> group_8;
	bool success_10;
	std::vector<std::tuple<::ISPA_STD::Node<::Parser::Tokens, Types::COMMA>, ::ISPA_STD::Node<::Parser::Tokens, Types::__WS>, ::ISPA_STD::Node<::Parser::Tokens, Types::ID>>> shadow_23;
	std::vector<std::tuple<::ISPA_STD::Node<::Parser::Tokens, Types::COMMA>, ::ISPA_STD::Node<::Parser::Tokens, Types::__WS>, ::ISPA_STD::Node<::Parser::Tokens, Types::ID>>> uvar_9;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_6;
	bool success_7;
	::ISPA_STD::Node<::Parser::Tokens, Types::COMMA> COMMA_12;
	::ISPA_STD::Node<::Parser::Tokens, Types::COMMA> uvar_11;
	std::vector<::ISPA_STD::Node<::Parser::Tokens, Types::COMMA>> shadow_14;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_16;
	bool success_17;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> uvar_15;
	std::vector<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>> shadow_18;
	::ISPA_STD::Node<::Parser::Tokens, Types::ID> ID_20;
	::ISPA_STD::Node<::Parser::Tokens, Types::ID> uvar_19;
	std::vector<::ISPA_STD::Node<::Parser::Tokens, Types::ID>> shadow_22;
	success_1 = false;
	if (!(((*pos)).template holds<Types::GLOBAL>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  GLOBAL");
		return {};
	}
	GLOBAL_0 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::GLOBAL>>();
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
	success_10 = false;
	auto begin_24 = pos;
	while (true) {
		auto repeat_ws_25 = begin_24;
		success_7 = false;
		if (((*repeat_ws_25)).template holds<Types::__WS>()) {
			__WS_6 = ((*repeat_ws_25)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
			success_7 = true;
			repeat_ws_25++;
		}
		if (!(((*repeat_ws_25)).template holds<Types::COMMA>())) {
			// speculative match failed (diagnostic suppressed):  COMMA
			break;
		}
		COMMA_12 = ((*repeat_ws_25)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::COMMA>>();
		success_13 = true;
		repeat_ws_25++;
		shadow_14.push_back(COMMA_12);
		uvar_11 = COMMA_12;
		success_17 = false;
		if (((*repeat_ws_25)).template holds<Types::__WS>()) {
			__WS_16 = ((*repeat_ws_25)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
			success_17 = true;
			repeat_ws_25++;
			shadow_18.push_back(__WS_16);
			uvar_15 = __WS_16;
		}
		if (!(((*repeat_ws_25)).template holds<Types::ID>())) {
			// speculative match failed (diagnostic suppressed): @  ID
			break;
		}
		ID_20 = ((*repeat_ws_25)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::ID>>();
		success_21 = true;
		repeat_ws_25++;
		shadow_22.push_back(ID_20);
		uvar_19 = ID_20;
		if (success_13 && success_21) {
			group_8 = std::make_tuple(COMMA_12, __WS_16, ID_20);
			shadow_23.push_back(group_8);
		}
		begin_24 = repeat_ws_25;
	}
	success_10 = true;
	::ISPA_STD::assign_compatible(uvar_9, shadow_23);
	pos = begin_24;
	Types::global_stmt result;
	::ISPA_STD::assign_compatible(result.first, ID_4);
	::ISPA_STD::assign_compatible(result.rest, uvar_19);
	::ISPA_STD::MatchResult<Rules, Types::global_stmt, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::global_stmt<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::global_stmt, ::Parser::Lexer::iterator>;
template auto Parser::Parser::global_stmt<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::global_stmt, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::if_stmt(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::if_stmt, IT> {
	::ISPA_STD::Node<::Parser::Tokens, Types::IF> IF_0;
	bool success_1;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::MatchResult<Rules, Types::expr, IT> expr_4;
	bool success_5;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_6;
	bool success_7;
	::ISPA_STD::Node<::Parser::Tokens, Types::COLON> COLON_8;
	bool success_9;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_10;
	bool success_11;
	::ISPA_STD::MatchResult<Rules, Types::block, IT> block_12;
	bool success_13;
	::ISPA_STD::MatchResult<Rules, Types::elif_clause, IT> elif_clause_17;
	bool success_18;
	::ISPA_STD::Node<::Parser::Rules, Types::elif_clause> element_19;
	std::vector<::ISPA_STD::Node<::Parser::Rules, Types::elif_clause>> shadow_20;
	std::vector<::ISPA_STD::Node<::Parser::Rules, Types::elif_clause>> uvar_16;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_14;
	bool success_15;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_22;
	bool success_23;
	::ISPA_STD::MatchResult<Rules, Types::else_clause, IT> else_clause_24;
	bool success_25;
	success_1 = false;
	if (!(((*pos)).template holds<Types::IF>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  IF");
		return {};
	}
	IF_0 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::IF>>();
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
	if (!(((*pos)).template holds<Types::COLON>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  COLON");
		return {};
	}
	COLON_8 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::COLON>>();
	success_9 = true;
	pos++;
	success_11 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_10 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_11 = true;
		pos++;
	}
	success_13 = false;
	block_12 = block(pos);
	if (!(block_12.status)) {
		raise_error(*pos, "ISPA match failure: required named rule did not match | grammar: @  block");
		return {};
	}
	success_13 = true;
	pos = block_12.it;
	success_18 = false;
	// grammar `@  elif_clause*;`: repeat named rule; collect every matched value
	while (true) {
		auto repeat_ws_21 = pos;
		success_15 = false;
		if (((*repeat_ws_21)).template holds<Types::__WS>()) {
			__WS_14 = ((*repeat_ws_21)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
			success_15 = true;
			repeat_ws_21++;
		}
		elif_clause_17 = elif_clause(repeat_ws_21);
		if (!(elif_clause_17.status)) {
			break;
		}
		success_18 = true;
		repeat_ws_21 = elif_clause_17.it;
		element_19 = elif_clause_17.node;
		shadow_20.push_back(element_19);
		pos = repeat_ws_21;
	}
	::ISPA_STD::assign_compatible(uvar_16, shadow_20);
	success_23 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_22 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_23 = true;
		pos++;
	}
	success_25 = false;
	else_clause_24 = else_clause(pos);
	if (else_clause_24.status) {
		success_25 = true;
		pos = else_clause_24.it;
	}
	Types::if_stmt result;
	::ISPA_STD::assign_compatible(result.condition, expr_4);
	::ISPA_STD::assign_compatible(result.body, block_12);
	::ISPA_STD::assign_compatible(result.elifs, uvar_16);
	::ISPA_STD::assign_compatible(result.otherwise, else_clause_24);
	::ISPA_STD::MatchResult<Rules, Types::if_stmt, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::if_stmt<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::if_stmt, ::Parser::Lexer::iterator>;
template auto Parser::Parser::if_stmt<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::if_stmt, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::import_alias(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::import_alias, IT> {
	::ISPA_STD::Node<::Parser::Tokens, Types::AS> AS_0;
	bool success_1;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::Node<::Parser::Tokens, Types::ID> ID_4;
	bool success_5;
	success_1 = false;
	if (!(((*pos)).template holds<Types::AS>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  AS");
		return {};
	}
	AS_0 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::AS>>();
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
	Types::import_alias result;
	::ISPA_STD::assign_compatible(result.value, ID_4);
	::ISPA_STD::MatchResult<Rules, Types::import_alias, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::import_alias<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::import_alias, ::Parser::Lexer::iterator>;
template auto Parser::Parser::import_alias<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::import_alias, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::import_from(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::import_from, IT> {
	::ISPA_STD::Node<::Parser::Tokens, Types::FROM> FROM_0;
	bool success_1;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::MatchResult<Rules, Types::relative_module, IT> relative_module_4;
	bool success_5;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_6;
	bool success_7;
	::ISPA_STD::Node<::Parser::Tokens, Types::IMPORT> IMPORT_8;
	bool success_9;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_10;
	bool success_11;
	::ISPA_STD::MatchResult<Rules, Types::import_targets, IT> import_targets_12;
	bool success_13;
	success_1 = false;
	if (!(((*pos)).template holds<Types::FROM>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  FROM");
		return {};
	}
	FROM_0 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::FROM>>();
	success_1 = true;
	pos++;
	success_3 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_2 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_3 = true;
		pos++;
	}
	success_5 = false;
	relative_module_4 = relative_module(pos);
	if (!(relative_module_4.status)) {
		raise_error(*pos, "ISPA match failure: required named rule did not match | grammar: @  relative_module");
		return {};
	}
	success_5 = true;
	pos = relative_module_4.it;
	success_7 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_6 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_7 = true;
		pos++;
	}
	success_9 = false;
	if (!(((*pos)).template holds<Types::IMPORT>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  IMPORT");
		return {};
	}
	IMPORT_8 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::IMPORT>>();
	success_9 = true;
	pos++;
	success_11 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_10 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_11 = true;
		pos++;
	}
	success_13 = false;
	import_targets_12 = import_targets(pos);
	if (!(import_targets_12.status)) {
		raise_error(*pos, "ISPA match failure: required named rule did not match | grammar: @  import_targets");
		return {};
	}
	success_13 = true;
	pos = import_targets_12.it;
	Types::import_from result;
	::ISPA_STD::assign_compatible(result.module, relative_module_4);
	::ISPA_STD::assign_compatible(result.names, import_targets_12);
	::ISPA_STD::MatchResult<Rules, Types::import_from, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::import_from<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::import_from, ::Parser::Lexer::iterator>;
template auto Parser::Parser::import_from<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::import_from, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::import_name(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::import_name, IT> {
	::ISPA_STD::Node<::Parser::Tokens, Types::IMPORT> IMPORT_0;
	bool success_1;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::MatchResult<Rules, Types::dotted_as_names, IT> dotted_as_names_4;
	bool success_5;
	success_1 = false;
	if (!(((*pos)).template holds<Types::IMPORT>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  IMPORT");
		return {};
	}
	IMPORT_0 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::IMPORT>>();
	success_1 = true;
	pos++;
	success_3 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_2 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_3 = true;
		pos++;
	}
	success_5 = false;
	dotted_as_names_4 = dotted_as_names(pos);
	if (!(dotted_as_names_4.status)) {
		raise_error(*pos, "ISPA match failure: required named rule did not match | grammar: @  dotted_as_names");
		return {};
	}
	success_5 = true;
	pos = dotted_as_names_4.it;
	Types::import_name result;
	::ISPA_STD::assign_compatible(result.value, dotted_as_names_4.node);
	::ISPA_STD::MatchResult<Rules, Types::import_name, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::import_name<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::import_name, ::Parser::Lexer::iterator>;
template auto Parser::Parser::import_name<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::import_name, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::import_name_item(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::import_name_item, IT> {
	::ISPA_STD::Node<::Parser::Tokens, Types::ID> ID_0;
	bool success_1;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::MatchResult<Rules, Types::import_alias, IT> import_alias_4;
	bool success_5;
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
	import_alias_4 = import_alias(pos);
	if (import_alias_4.status) {
		success_5 = true;
		pos = import_alias_4.it;
	}
	Types::import_name_item result;
	::ISPA_STD::assign_compatible(result.name, ID_0);
	::ISPA_STD::assign_compatible(result.alias, import_alias_4);
	::ISPA_STD::MatchResult<Rules, Types::import_name_item, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::import_name_item<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::import_name_item, ::Parser::Lexer::iterator>;
template auto Parser::Parser::import_name_item<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::import_name_item, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::import_names(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::import_names, IT> {
	::ISPA_STD::MatchResult<Rules, Types::import_name_item, IT> import_name_item_0;
	bool success_1;
	bool success_17;
	bool success_9;
	std::tuple<::ISPA_STD::Node<::Parser::Tokens, Types::COMMA>, ::ISPA_STD::Node<::Parser::Tokens, Types::__WS>, ::ISPA_STD::Node<::Parser::Rules, Types::import_name_item>> group_4;
	bool success_6;
	std::vector<std::tuple<::ISPA_STD::Node<::Parser::Tokens, Types::COMMA>, ::ISPA_STD::Node<::Parser::Tokens, Types::__WS>, ::ISPA_STD::Node<::Parser::Rules, Types::import_name_item>>> shadow_21;
	std::vector<std::tuple<::ISPA_STD::Node<::Parser::Tokens, Types::COMMA>, ::ISPA_STD::Node<::Parser::Tokens, Types::__WS>, ::ISPA_STD::Node<::Parser::Rules, Types::import_name_item>>> uvar_5;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::Node<::Parser::Tokens, Types::COMMA> COMMA_8;
	::ISPA_STD::Node<::Parser::Tokens, Types::COMMA> uvar_7;
	std::vector<::ISPA_STD::Node<::Parser::Tokens, Types::COMMA>> shadow_10;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_12;
	bool success_13;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> uvar_11;
	std::vector<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>> shadow_14;
	::ISPA_STD::MatchResult<Rules, Types::import_name_item, IT> import_name_item_16;
	::ISPA_STD::Node<::Parser::Rules, Types::import_name_item> element_18;
	std::vector<::ISPA_STD::Node<::Parser::Rules, Types::import_name_item>> shadow_19;
	::ISPA_STD::Node<::Parser::Rules, Types::import_name_item> uvar_15;
	::ISPA_STD::Node<::Parser::Rules, Types::import_name_item> tuple_elem_20;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_24;
	bool success_25;
	::ISPA_STD::Node<::Parser::Tokens, Types::COMMA> COMMA_26;
	bool success_27;
	success_1 = false;
	import_name_item_0 = import_name_item(pos);
	if (!(import_name_item_0.status)) {
		raise_error(*pos, "ISPA match failure: required named rule did not match | grammar: @  import_name_item");
		return {};
	}
	success_1 = true;
	pos = import_name_item_0.it;
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
		import_name_item_16 = import_name_item(repeat_ws_23);
		if (!(import_name_item_16.status)) {
			// speculative match failed (diagnostic suppressed): @  import_name_item
			break;
		}
		success_17 = true;
		repeat_ws_23 = import_name_item_16.it;
		element_18 = import_name_item_16.node;
		shadow_19.push_back(element_18);
		if (success_9 && success_17) {
			tuple_elem_20 = import_name_item_16.node;
			group_4 = std::make_tuple(COMMA_8, __WS_12, tuple_elem_20);
			shadow_21.push_back(group_4);
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
	if (((*pos)).template holds<Types::COMMA>()) {
		COMMA_26 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::COMMA>>();
		success_27 = true;
		pos++;
	}
	Types::import_names result;
	::ISPA_STD::assign_compatible(result.first, import_name_item_0);
	::ISPA_STD::assign_compatible(result.rest, uvar_15);
	::ISPA_STD::MatchResult<Rules, Types::import_names, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::import_names<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::import_names, ::Parser::Lexer::iterator>;
template auto Parser::Parser::import_names<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::import_names, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::import_stmt(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::import_stmt, IT> {
	std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Rules, Types::import_from>, ::ISPA_STD::Node<::Parser::Rules, Types::import_name>> _0;
	bool success_1;
	::ISPA_STD::MatchResult<Rules, Types::import_from, IT> import_from_2;
	bool success_3;
	::ISPA_STD::MatchResult<Rules, Types::import_name, IT> import_name_4;
	bool success_5;
	success_1 = false;
	// grammar `@  ( import_name |  import_from)`: choice; reset match status before selecting an alternative
	success_1 = false;
	auto lookahead_pos_1 = pos;
	switch (static_cast<Tokens>((*lookahead_pos_1).kind())) {
		case Tokens::FROM: {
			lookahead_pos_1 = lookahead_pos_1;
			success_3 = false;
			import_from_2 = import_from(lookahead_pos_1);
			if (!(import_from_2.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  import_from");
				return {};
			}
			success_3 = true;
			lookahead_pos_1 = import_from_2.it;
			if (!success_3) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  import_from");
				return {};
			}
			_0 = import_from_2.node;
			success_1 = true;
			break;
		}
		case Tokens::IMPORT: {
			lookahead_pos_1 = lookahead_pos_1;
			success_5 = false;
			import_name_4 = import_name(lookahead_pos_1);
			if (!(import_name_4.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  import_name");
				return {};
			}
			success_5 = true;
			lookahead_pos_1 = import_name_4.it;
			if (!success_5) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  import_name");
				return {};
			}
			_0 = import_name_4.node;
			success_1 = true;
			break;
		}
	}
	pos = lookahead_pos_1;
	if (!success_1) {
		raise_error(*pos, "ISPA match failure: no LL(k) alternative matched | grammar: @  ( import_name |  import_from)");
		return {};
	}
	Types::import_stmt result;
	::ISPA_STD::assign_compatible(result.value, _0);
	::ISPA_STD::MatchResult<Rules, Types::import_stmt, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::import_stmt<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::import_stmt, ::Parser::Lexer::iterator>;
template auto Parser::Parser::import_stmt<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::import_stmt, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::import_targets(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::import_targets, IT> {
	std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Rules, Types::import_names>, ::ISPA_STD::Node<::Parser::Rules, Types::parenthesized_imports>, ::ISPA_STD::Node<::Parser::Tokens, Types::STAR>> _0;
	bool success_1;
	::ISPA_STD::MatchResult<Rules, Types::import_names, IT> import_names_2;
	bool success_3;
	::ISPA_STD::MatchResult<Rules, Types::parenthesized_imports, IT> parenthesized_imports_4;
	bool success_5;
	::ISPA_STD::Node<::Parser::Tokens, Types::STAR> STAR_6;
	bool success_7;
	success_1 = false;
	// grammar `@  ( STAR |  parenthesized_imports |  import_names)`: choice; reset match status before selecting an alternative
	success_1 = false;
	auto lookahead_pos_1 = pos;
	switch (static_cast<Tokens>((*lookahead_pos_1).kind())) {
		case Tokens::ID: {
			lookahead_pos_1 = lookahead_pos_1;
			success_3 = false;
			import_names_2 = import_names(lookahead_pos_1);
			if (!(import_names_2.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  import_names");
				return {};
			}
			success_3 = true;
			lookahead_pos_1 = import_names_2.it;
			if (!success_3) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  import_names");
				return {};
			}
			_0 = import_names_2.node;
			success_1 = true;
			break;
		}
		case Tokens::LPAREN: {
			lookahead_pos_1 = lookahead_pos_1;
			success_5 = false;
			parenthesized_imports_4 = parenthesized_imports(lookahead_pos_1);
			if (!(parenthesized_imports_4.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  parenthesized_imports");
				return {};
			}
			success_5 = true;
			lookahead_pos_1 = parenthesized_imports_4.it;
			if (!success_5) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  parenthesized_imports");
				return {};
			}
			_0 = parenthesized_imports_4.node;
			success_1 = true;
			break;
		}
		case Tokens::STAR: {
			lookahead_pos_1 = lookahead_pos_1;
			success_7 = false;
			if (!(((*lookahead_pos_1)).template holds<Types::STAR>())) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  STAR");
				return {};
			}
			STAR_6 = ((*lookahead_pos_1)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::STAR>>();
			success_7 = true;
			lookahead_pos_1++;
			if (!success_7) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  STAR");
				return {};
			}
			_0 = STAR_6;
			success_1 = true;
			break;
		}
	}
	pos = lookahead_pos_1;
	if (!success_1) {
		raise_error(*pos, "ISPA match failure: no LL(k) alternative matched | grammar: @  ( STAR |  parenthesized_imports |  import_names)");
		return {};
	}
	Types::import_targets result;
	::ISPA_STD::assign_compatible(result.value, _0);
	::ISPA_STD::MatchResult<Rules, Types::import_targets, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::import_targets<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::import_targets, ::Parser::Lexer::iterator>;
template auto Parser::Parser::import_targets<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::import_targets, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::indented_block(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::indented_block, IT> {
	::ISPA_STD::Node<::Parser::Tokens, Types::NEWLINE> NEWLINE_0;
	bool success_1;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::Node<::Parser::Tokens, Types::INDENT> INDENT_4;
	bool success_5;
	::ISPA_STD::MatchResult<Rules, Types::statement, IT> statement_9;
	bool success_10;
	::ISPA_STD::Node<::Parser::Rules, Types::statement> element_11;
	std::vector<::ISPA_STD::Node<::Parser::Rules, Types::statement>> shadow_12;
	std::vector<::ISPA_STD::Node<::Parser::Rules, Types::statement>> uvar_8;
	bool success_13;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_6;
	bool success_7;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_15;
	bool success_16;
	::ISPA_STD::Node<::Parser::Tokens, Types::DEDENT> DEDENT_17;
	bool success_18;
	success_1 = false;
	if (!(((*pos)).template holds<Types::NEWLINE>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  NEWLINE");
		return {};
	}
	NEWLINE_0 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::NEWLINE>>();
	success_1 = true;
	pos++;
	success_3 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_2 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_3 = true;
		pos++;
	}
	success_5 = false;
	if (!(((*pos)).template holds<Types::INDENT>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  INDENT");
		return {};
	}
	INDENT_4 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::INDENT>>();
	success_5 = true;
	pos++;
	success_10 = false;
	// grammar `@  statement+;`: repeat named rule; collect every matched value
	success_13 = false;
	while (true) {
		auto repeat_ws_14 = pos;
		success_7 = false;
		if (((*repeat_ws_14)).template holds<Types::__WS>()) {
			__WS_6 = ((*repeat_ws_14)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
			success_7 = true;
			repeat_ws_14++;
		}
		statement_9 = statement(repeat_ws_14);
		if (!(statement_9.status)) {
			break;
		}
		success_10 = true;
		repeat_ws_14 = statement_9.it;
		element_11 = statement_9.node;
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
	if (!(((*pos)).template holds<Types::DEDENT>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  DEDENT");
		return {};
	}
	DEDENT_17 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::DEDENT>>();
	success_18 = true;
	pos++;
	Types::indented_block result;
	::ISPA_STD::assign_compatible(result.value, uvar_8);
	::ISPA_STD::MatchResult<Rules, Types::indented_block, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::indented_block<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::indented_block, ::Parser::Lexer::iterator>;
template auto Parser::Parser::indented_block<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::indented_block, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::index_suffix(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::index_suffix, IT> {
	::ISPA_STD::Node<::Parser::Tokens, Types::LBRACKET> LBRACKET_0;
	bool success_1;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::MatchResult<Rules, Types::expr, IT> expr_4;
	bool success_5;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_6;
	bool success_7;
	::ISPA_STD::Node<::Parser::Tokens, Types::RBRACKET> RBRACKET_8;
	bool success_9;
	success_1 = false;
	if (!(((*pos)).template holds<Types::LBRACKET>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  LBRACKET");
		return {};
	}
	LBRACKET_0 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::LBRACKET>>();
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
	if (!(((*pos)).template holds<Types::RBRACKET>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  RBRACKET");
		return {};
	}
	RBRACKET_8 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::RBRACKET>>();
	success_9 = true;
	pos++;
	Types::index_suffix result;
	::ISPA_STD::assign_compatible(result.value, expr_4.node);
	::ISPA_STD::MatchResult<Rules, Types::index_suffix, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::index_suffix<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::index_suffix, ::Parser::Lexer::iterator>;
template auto Parser::Parser::index_suffix<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::index_suffix, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::inversion(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::inversion, IT> {
	std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Rules, Types::comparison>, ::ISPA_STD::Node<::Parser::Rules, Types::not_inversion>> _0;
	bool success_1;
	::ISPA_STD::MatchResult<Rules, Types::comparison, IT> comparison_2;
	bool success_3;
	::ISPA_STD::MatchResult<Rules, Types::comparison, IT> comparison_4;
	bool success_5;
	::ISPA_STD::MatchResult<Rules, Types::comparison, IT> comparison_6;
	bool success_7;
	::ISPA_STD::MatchResult<Rules, Types::comparison, IT> comparison_8;
	bool success_9;
	::ISPA_STD::MatchResult<Rules, Types::comparison, IT> comparison_10;
	bool success_11;
	::ISPA_STD::MatchResult<Rules, Types::comparison, IT> comparison_12;
	bool success_13;
	::ISPA_STD::MatchResult<Rules, Types::comparison, IT> comparison_14;
	bool success_15;
	::ISPA_STD::MatchResult<Rules, Types::not_inversion, IT> not_inversion_16;
	bool success_17;
	::ISPA_STD::MatchResult<Rules, Types::comparison, IT> comparison_18;
	bool success_19;
	::ISPA_STD::MatchResult<Rules, Types::comparison, IT> comparison_20;
	bool success_21;
	::ISPA_STD::MatchResult<Rules, Types::comparison, IT> comparison_22;
	bool success_23;
	::ISPA_STD::MatchResult<Rules, Types::comparison, IT> comparison_24;
	bool success_25;
	::ISPA_STD::MatchResult<Rules, Types::comparison, IT> comparison_26;
	bool success_27;
	success_1 = false;
	// grammar `@  ( not_inversion |  comparison)`: choice; reset match status before selecting an alternative
	success_1 = false;
	auto lookahead_pos_1 = pos;
	switch (static_cast<Tokens>((*lookahead_pos_1).kind())) {
		case Tokens::FALSE: {
			lookahead_pos_1 = lookahead_pos_1;
			success_3 = false;
			comparison_2 = comparison(lookahead_pos_1);
			if (!(comparison_2.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  comparison");
				return {};
			}
			success_3 = true;
			lookahead_pos_1 = comparison_2.it;
			if (!success_3) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  comparison");
				return {};
			}
			_0 = comparison_2.node;
			success_1 = true;
			break;
		}
		case Tokens::ID: {
			lookahead_pos_1 = lookahead_pos_1;
			success_5 = false;
			comparison_4 = comparison(lookahead_pos_1);
			if (!(comparison_4.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  comparison");
				return {};
			}
			success_5 = true;
			lookahead_pos_1 = comparison_4.it;
			if (!success_5) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  comparison");
				return {};
			}
			_0 = comparison_4.node;
			success_1 = true;
			break;
		}
		case Tokens::LBRACE: {
			lookahead_pos_1 = lookahead_pos_1;
			success_7 = false;
			comparison_6 = comparison(lookahead_pos_1);
			if (!(comparison_6.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  comparison");
				return {};
			}
			success_7 = true;
			lookahead_pos_1 = comparison_6.it;
			if (!success_7) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  comparison");
				return {};
			}
			_0 = comparison_6.node;
			success_1 = true;
			break;
		}
		case Tokens::LBRACKET: {
			lookahead_pos_1 = lookahead_pos_1;
			success_9 = false;
			comparison_8 = comparison(lookahead_pos_1);
			if (!(comparison_8.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  comparison");
				return {};
			}
			success_9 = true;
			lookahead_pos_1 = comparison_8.it;
			if (!success_9) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  comparison");
				return {};
			}
			_0 = comparison_8.node;
			success_1 = true;
			break;
		}
		case Tokens::LPAREN: {
			lookahead_pos_1 = lookahead_pos_1;
			success_11 = false;
			comparison_10 = comparison(lookahead_pos_1);
			if (!(comparison_10.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  comparison");
				return {};
			}
			success_11 = true;
			lookahead_pos_1 = comparison_10.it;
			if (!success_11) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  comparison");
				return {};
			}
			_0 = comparison_10.node;
			success_1 = true;
			break;
		}
		case Tokens::MINUS: {
			lookahead_pos_1 = lookahead_pos_1;
			success_13 = false;
			comparison_12 = comparison(lookahead_pos_1);
			if (!(comparison_12.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  comparison");
				return {};
			}
			success_13 = true;
			lookahead_pos_1 = comparison_12.it;
			if (!success_13) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  comparison");
				return {};
			}
			_0 = comparison_12.node;
			success_1 = true;
			break;
		}
		case Tokens::NONE_V: {
			lookahead_pos_1 = lookahead_pos_1;
			success_15 = false;
			comparison_14 = comparison(lookahead_pos_1);
			if (!(comparison_14.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  comparison");
				return {};
			}
			success_15 = true;
			lookahead_pos_1 = comparison_14.it;
			if (!success_15) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  comparison");
				return {};
			}
			_0 = comparison_14.node;
			success_1 = true;
			break;
		}
		case Tokens::NOT: {
			lookahead_pos_1 = lookahead_pos_1;
			success_17 = false;
			not_inversion_16 = not_inversion(lookahead_pos_1);
			if (!(not_inversion_16.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  not_inversion");
				return {};
			}
			success_17 = true;
			lookahead_pos_1 = not_inversion_16.it;
			if (!success_17) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  not_inversion");
				return {};
			}
			_0 = not_inversion_16.node;
			success_1 = true;
			break;
		}
		case Tokens::NUMBER: {
			lookahead_pos_1 = lookahead_pos_1;
			success_19 = false;
			comparison_18 = comparison(lookahead_pos_1);
			if (!(comparison_18.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  comparison");
				return {};
			}
			success_19 = true;
			lookahead_pos_1 = comparison_18.it;
			if (!success_19) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  comparison");
				return {};
			}
			_0 = comparison_18.node;
			success_1 = true;
			break;
		}
		case Tokens::PLUS: {
			lookahead_pos_1 = lookahead_pos_1;
			success_21 = false;
			comparison_20 = comparison(lookahead_pos_1);
			if (!(comparison_20.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  comparison");
				return {};
			}
			success_21 = true;
			lookahead_pos_1 = comparison_20.it;
			if (!success_21) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  comparison");
				return {};
			}
			_0 = comparison_20.node;
			success_1 = true;
			break;
		}
		case Tokens::STRING: {
			lookahead_pos_1 = lookahead_pos_1;
			success_23 = false;
			comparison_22 = comparison(lookahead_pos_1);
			if (!(comparison_22.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  comparison");
				return {};
			}
			success_23 = true;
			lookahead_pos_1 = comparison_22.it;
			if (!success_23) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  comparison");
				return {};
			}
			_0 = comparison_22.node;
			success_1 = true;
			break;
		}
		case Tokens::TILDE: {
			lookahead_pos_1 = lookahead_pos_1;
			success_25 = false;
			comparison_24 = comparison(lookahead_pos_1);
			if (!(comparison_24.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  comparison");
				return {};
			}
			success_25 = true;
			lookahead_pos_1 = comparison_24.it;
			if (!success_25) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  comparison");
				return {};
			}
			_0 = comparison_24.node;
			success_1 = true;
			break;
		}
		case Tokens::TRUE: {
			lookahead_pos_1 = lookahead_pos_1;
			success_27 = false;
			comparison_26 = comparison(lookahead_pos_1);
			if (!(comparison_26.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  comparison");
				return {};
			}
			success_27 = true;
			lookahead_pos_1 = comparison_26.it;
			if (!success_27) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  comparison");
				return {};
			}
			_0 = comparison_26.node;
			success_1 = true;
			break;
		}
	}
	pos = lookahead_pos_1;
	if (!success_1) {
		raise_error(*pos, "ISPA match failure: no LL(k) alternative matched | grammar: @  ( not_inversion |  comparison)");
		return {};
	}
	Types::inversion result;
	::ISPA_STD::assign_compatible(result.value, _0);
	::ISPA_STD::MatchResult<Rules, Types::inversion, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::inversion<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::inversion, ::Parser::Lexer::iterator>;
template auto Parser::Parser::inversion<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::inversion, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::is_op(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::is_op, IT> {
	::ISPA_STD::Node<::Parser::Tokens, Types::IS> IS_0;
	bool success_1;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::Node<::Parser::Tokens, Types::NOT> NOT_4;
	bool success_5;
	success_1 = false;
	if (!(((*pos)).template holds<Types::IS>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  IS");
		return {};
	}
	IS_0 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::IS>>();
	success_1 = true;
	pos++;
	success_3 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_2 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_3 = true;
		pos++;
	}
	success_5 = false;
	if (((*pos)).template holds<Types::NOT>()) {
		NOT_4 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::NOT>>();
		success_5 = true;
		pos++;
	}
	Types::is_op result;
	::ISPA_STD::MatchResult<Rules, Types::is_op, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::is_op<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::is_op, ::Parser::Lexer::iterator>;
template auto Parser::Parser::is_op<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::is_op, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::keyword_arg(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::keyword_arg, IT> {
	::ISPA_STD::Node<::Parser::Tokens, Types::ID> ID_0;
	bool success_1;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::Node<::Parser::Tokens, Types::ASSIGN> ASSIGN_4;
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
	if (!(((*pos)).template holds<Types::ASSIGN>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  ASSIGN");
		return {};
	}
	ASSIGN_4 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::ASSIGN>>();
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
	Types::keyword_arg result;
	::ISPA_STD::assign_compatible(result.name, ID_0);
	::ISPA_STD::assign_compatible(result.value, expr_8);
	::ISPA_STD::MatchResult<Rules, Types::keyword_arg, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::keyword_arg<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::keyword_arg, ::Parser::Lexer::iterator>;
template auto Parser::Parser::keyword_arg<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::keyword_arg, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::list_expr(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::list_expr, IT> {
	::ISPA_STD::Node<::Parser::Tokens, Types::LBRACKET> LBRACKET_0;
	bool success_1;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::MatchResult<Rules, Types::expr_list, IT> expr_list_4;
	bool success_5;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_6;
	bool success_7;
	::ISPA_STD::Node<::Parser::Tokens, Types::RBRACKET> RBRACKET_8;
	bool success_9;
	success_1 = false;
	if (!(((*pos)).template holds<Types::LBRACKET>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  LBRACKET");
		return {};
	}
	LBRACKET_0 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::LBRACKET>>();
	success_1 = true;
	pos++;
	success_3 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_2 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_3 = true;
		pos++;
	}
	success_5 = false;
	expr_list_4 = expr_list(pos);
	if (expr_list_4.status) {
		success_5 = true;
		pos = expr_list_4.it;
	}
	success_7 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_6 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_7 = true;
		pos++;
	}
	success_9 = false;
	if (!(((*pos)).template holds<Types::RBRACKET>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  RBRACKET");
		return {};
	}
	RBRACKET_8 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::RBRACKET>>();
	success_9 = true;
	pos++;
	Types::list_expr result;
	::ISPA_STD::assign_compatible(result.value, expr_list_4.node);
	::ISPA_STD::MatchResult<Rules, Types::list_expr, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::list_expr<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::list_expr, ::Parser::Lexer::iterator>;
template auto Parser::Parser::list_expr<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::list_expr, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::main(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::main, IT> {
	::ISPA_STD::MatchResult<Rules, Types::statement, IT> statement_1;
	bool success_2;
	::ISPA_STD::Node<::Parser::Rules, Types::statement> element_3;
	std::vector<::ISPA_STD::Node<::Parser::Rules, Types::statement>> shadow_4;
	std::vector<::ISPA_STD::Node<::Parser::Rules, Types::statement>> uvar_0;
	success_2 = false;
	// grammar `@  statement*;`: repeat named rule; collect every matched value
	while (true) {
		statement_1 = statement(pos);
		if (!(statement_1.status)) {
			break;
		}
		success_2 = true;
		pos = statement_1.it;
		element_3 = statement_1.node;
		shadow_4.push_back(element_3);
	}
	::ISPA_STD::assign_compatible(uvar_0, shadow_4);
	Types::main result;
	::ISPA_STD::assign_compatible(result.value, uvar_0);
	::ISPA_STD::MatchResult<Rules, Types::main, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::main<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::main, ::Parser::Lexer::iterator>;
template auto Parser::Parser::main<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::main, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::nonlocal_stmt(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::nonlocal_stmt, IT> {
	::ISPA_STD::Node<::Parser::Tokens, Types::NONLOCAL> NONLOCAL_0;
	bool success_1;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::Node<::Parser::Tokens, Types::ID> ID_4;
	bool success_5;
	bool success_21;
	bool success_13;
	std::tuple<::ISPA_STD::Node<::Parser::Tokens, Types::COMMA>, ::ISPA_STD::Node<::Parser::Tokens, Types::__WS>, ::ISPA_STD::Node<::Parser::Tokens, Types::ID>> group_8;
	bool success_10;
	std::vector<std::tuple<::ISPA_STD::Node<::Parser::Tokens, Types::COMMA>, ::ISPA_STD::Node<::Parser::Tokens, Types::__WS>, ::ISPA_STD::Node<::Parser::Tokens, Types::ID>>> shadow_23;
	std::vector<std::tuple<::ISPA_STD::Node<::Parser::Tokens, Types::COMMA>, ::ISPA_STD::Node<::Parser::Tokens, Types::__WS>, ::ISPA_STD::Node<::Parser::Tokens, Types::ID>>> uvar_9;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_6;
	bool success_7;
	::ISPA_STD::Node<::Parser::Tokens, Types::COMMA> COMMA_12;
	::ISPA_STD::Node<::Parser::Tokens, Types::COMMA> uvar_11;
	std::vector<::ISPA_STD::Node<::Parser::Tokens, Types::COMMA>> shadow_14;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_16;
	bool success_17;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> uvar_15;
	std::vector<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>> shadow_18;
	::ISPA_STD::Node<::Parser::Tokens, Types::ID> ID_20;
	::ISPA_STD::Node<::Parser::Tokens, Types::ID> uvar_19;
	std::vector<::ISPA_STD::Node<::Parser::Tokens, Types::ID>> shadow_22;
	success_1 = false;
	if (!(((*pos)).template holds<Types::NONLOCAL>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  NONLOCAL");
		return {};
	}
	NONLOCAL_0 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::NONLOCAL>>();
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
	success_10 = false;
	auto begin_24 = pos;
	while (true) {
		auto repeat_ws_25 = begin_24;
		success_7 = false;
		if (((*repeat_ws_25)).template holds<Types::__WS>()) {
			__WS_6 = ((*repeat_ws_25)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
			success_7 = true;
			repeat_ws_25++;
		}
		if (!(((*repeat_ws_25)).template holds<Types::COMMA>())) {
			// speculative match failed (diagnostic suppressed):  COMMA
			break;
		}
		COMMA_12 = ((*repeat_ws_25)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::COMMA>>();
		success_13 = true;
		repeat_ws_25++;
		shadow_14.push_back(COMMA_12);
		uvar_11 = COMMA_12;
		success_17 = false;
		if (((*repeat_ws_25)).template holds<Types::__WS>()) {
			__WS_16 = ((*repeat_ws_25)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
			success_17 = true;
			repeat_ws_25++;
			shadow_18.push_back(__WS_16);
			uvar_15 = __WS_16;
		}
		if (!(((*repeat_ws_25)).template holds<Types::ID>())) {
			// speculative match failed (diagnostic suppressed): @  ID
			break;
		}
		ID_20 = ((*repeat_ws_25)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::ID>>();
		success_21 = true;
		repeat_ws_25++;
		shadow_22.push_back(ID_20);
		uvar_19 = ID_20;
		if (success_13 && success_21) {
			group_8 = std::make_tuple(COMMA_12, __WS_16, ID_20);
			shadow_23.push_back(group_8);
		}
		begin_24 = repeat_ws_25;
	}
	success_10 = true;
	::ISPA_STD::assign_compatible(uvar_9, shadow_23);
	pos = begin_24;
	Types::nonlocal_stmt result;
	::ISPA_STD::assign_compatible(result.first, ID_4);
	::ISPA_STD::assign_compatible(result.rest, uvar_19);
	::ISPA_STD::MatchResult<Rules, Types::nonlocal_stmt, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::nonlocal_stmt<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::nonlocal_stmt, ::Parser::Lexer::iterator>;
template auto Parser::Parser::nonlocal_stmt<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::nonlocal_stmt, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::not_in(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::not_in, IT> {
	::ISPA_STD::Node<::Parser::Tokens, Types::NOT> NOT_0;
	bool success_1;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::Node<::Parser::Tokens, Types::IN> IN_4;
	bool success_5;
	success_1 = false;
	if (!(((*pos)).template holds<Types::NOT>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  NOT");
		return {};
	}
	NOT_0 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::NOT>>();
	success_1 = true;
	pos++;
	success_3 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_2 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_3 = true;
		pos++;
	}
	success_5 = false;
	if (!(((*pos)).template holds<Types::IN>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  IN");
		return {};
	}
	IN_4 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::IN>>();
	success_5 = true;
	pos++;
	Types::not_in result;
	::ISPA_STD::MatchResult<Rules, Types::not_in, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::not_in<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::not_in, ::Parser::Lexer::iterator>;
template auto Parser::Parser::not_in<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::not_in, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::not_inversion(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::not_inversion, IT> {
	::ISPA_STD::Node<::Parser::Tokens, Types::NOT> NOT_0;
	bool success_1;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::MatchResult<Rules, Types::inversion, IT> inversion_4;
	bool success_5;
	success_1 = false;
	if (!(((*pos)).template holds<Types::NOT>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  NOT");
		return {};
	}
	NOT_0 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::NOT>>();
	success_1 = true;
	pos++;
	success_3 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_2 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_3 = true;
		pos++;
	}
	success_5 = false;
	inversion_4 = inversion(pos);
	if (!(inversion_4.status)) {
		raise_error(*pos, "ISPA match failure: required named rule did not match | grammar: @  inversion");
		return {};
	}
	success_5 = true;
	pos = inversion_4.it;
	Types::not_inversion result;
	::ISPA_STD::assign_compatible(result.value, inversion_4.node);
	::ISPA_STD::MatchResult<Rules, Types::not_inversion, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::not_inversion<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::not_inversion, ::Parser::Lexer::iterator>;
template auto Parser::Parser::not_inversion<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::not_inversion, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::or_tail(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::or_tail, IT> {
	::ISPA_STD::Node<::Parser::Tokens, Types::OR> OR_0;
	bool success_1;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::MatchResult<Rules, Types::conjunction, IT> conjunction_4;
	bool success_5;
	success_1 = false;
	if (!(((*pos)).template holds<Types::OR>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  OR");
		return {};
	}
	OR_0 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::OR>>();
	success_1 = true;
	pos++;
	success_3 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_2 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_3 = true;
		pos++;
	}
	success_5 = false;
	conjunction_4 = conjunction(pos);
	if (!(conjunction_4.status)) {
		raise_error(*pos, "ISPA match failure: required named rule did not match | grammar: @  conjunction");
		return {};
	}
	success_5 = true;
	pos = conjunction_4.it;
	Types::or_tail result;
	::ISPA_STD::assign_compatible(result.value, conjunction_4.node);
	::ISPA_STD::MatchResult<Rules, Types::or_tail, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::or_tail<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::or_tail, ::Parser::Lexer::iterator>;
template auto Parser::Parser::or_tail<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::or_tail, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::parameter(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::parameter, IT> {
	::ISPA_STD::Node<::Parser::Tokens, Types::ID> ID_0;
	bool success_1;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::MatchResult<Rules, Types::parameter_annotation, IT> parameter_annotation_4;
	bool success_5;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_6;
	bool success_7;
	::ISPA_STD::MatchResult<Rules, Types::parameter_default, IT> parameter_default_8;
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
	parameter_annotation_4 = parameter_annotation(pos);
	if (parameter_annotation_4.status) {
		success_5 = true;
		pos = parameter_annotation_4.it;
	}
	success_7 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_6 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_7 = true;
		pos++;
	}
	success_9 = false;
	parameter_default_8 = parameter_default(pos);
	if (parameter_default_8.status) {
		success_9 = true;
		pos = parameter_default_8.it;
	}
	Types::parameter result;
	::ISPA_STD::assign_compatible(result.name, ID_0);
	::ISPA_STD::assign_compatible(result.annotation, parameter_annotation_4);
	::ISPA_STD::assign_compatible(result.def, parameter_default_8);
	::ISPA_STD::MatchResult<Rules, Types::parameter, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::parameter<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::parameter, ::Parser::Lexer::iterator>;
template auto Parser::Parser::parameter<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::parameter, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::parameter_annotation(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::parameter_annotation, IT> {
	::ISPA_STD::Node<::Parser::Tokens, Types::COLON> COLON_0;
	bool success_1;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::MatchResult<Rules, Types::expr, IT> expr_4;
	bool success_5;
	success_1 = false;
	if (!(((*pos)).template holds<Types::COLON>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  COLON");
		return {};
	}
	COLON_0 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::COLON>>();
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
	Types::parameter_annotation result;
	::ISPA_STD::assign_compatible(result.value, expr_4.node);
	::ISPA_STD::MatchResult<Rules, Types::parameter_annotation, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::parameter_annotation<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::parameter_annotation, ::Parser::Lexer::iterator>;
template auto Parser::Parser::parameter_annotation<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::parameter_annotation, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::parameter_default(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::parameter_default, IT> {
	::ISPA_STD::Node<::Parser::Tokens, Types::ASSIGN> ASSIGN_0;
	bool success_1;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::MatchResult<Rules, Types::expr, IT> expr_4;
	bool success_5;
	success_1 = false;
	if (!(((*pos)).template holds<Types::ASSIGN>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  ASSIGN");
		return {};
	}
	ASSIGN_0 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::ASSIGN>>();
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
	Types::parameter_default result;
	::ISPA_STD::assign_compatible(result.value, expr_4.node);
	::ISPA_STD::MatchResult<Rules, Types::parameter_default, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::parameter_default<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::parameter_default, ::Parser::Lexer::iterator>;
template auto Parser::Parser::parameter_default<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::parameter_default, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::parameters(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::parameters, IT> {
	::ISPA_STD::MatchResult<Rules, Types::parameter, IT> parameter_0;
	bool success_1;
	bool success_17;
	bool success_9;
	std::tuple<::ISPA_STD::Node<::Parser::Tokens, Types::COMMA>, ::ISPA_STD::Node<::Parser::Tokens, Types::__WS>, ::ISPA_STD::Node<::Parser::Rules, Types::parameter>> group_4;
	bool success_6;
	std::vector<std::tuple<::ISPA_STD::Node<::Parser::Tokens, Types::COMMA>, ::ISPA_STD::Node<::Parser::Tokens, Types::__WS>, ::ISPA_STD::Node<::Parser::Rules, Types::parameter>>> shadow_21;
	std::vector<std::tuple<::ISPA_STD::Node<::Parser::Tokens, Types::COMMA>, ::ISPA_STD::Node<::Parser::Tokens, Types::__WS>, ::ISPA_STD::Node<::Parser::Rules, Types::parameter>>> uvar_5;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::Node<::Parser::Tokens, Types::COMMA> COMMA_8;
	::ISPA_STD::Node<::Parser::Tokens, Types::COMMA> uvar_7;
	std::vector<::ISPA_STD::Node<::Parser::Tokens, Types::COMMA>> shadow_10;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_12;
	bool success_13;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> uvar_11;
	std::vector<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>> shadow_14;
	::ISPA_STD::MatchResult<Rules, Types::parameter, IT> parameter_16;
	::ISPA_STD::Node<::Parser::Rules, Types::parameter> element_18;
	std::vector<::ISPA_STD::Node<::Parser::Rules, Types::parameter>> shadow_19;
	::ISPA_STD::Node<::Parser::Rules, Types::parameter> uvar_15;
	::ISPA_STD::Node<::Parser::Rules, Types::parameter> tuple_elem_20;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_24;
	bool success_25;
	::ISPA_STD::Node<::Parser::Tokens, Types::COMMA> COMMA_26;
	bool success_27;
	success_1 = false;
	parameter_0 = parameter(pos);
	if (!(parameter_0.status)) {
		raise_error(*pos, "ISPA match failure: required named rule did not match | grammar: @  parameter");
		return {};
	}
	success_1 = true;
	pos = parameter_0.it;
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
		parameter_16 = parameter(repeat_ws_23);
		if (!(parameter_16.status)) {
			// speculative match failed (diagnostic suppressed): @  parameter
			break;
		}
		success_17 = true;
		repeat_ws_23 = parameter_16.it;
		element_18 = parameter_16.node;
		shadow_19.push_back(element_18);
		if (success_9 && success_17) {
			tuple_elem_20 = parameter_16.node;
			group_4 = std::make_tuple(COMMA_8, __WS_12, tuple_elem_20);
			shadow_21.push_back(group_4);
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
	if (((*pos)).template holds<Types::COMMA>()) {
		COMMA_26 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::COMMA>>();
		success_27 = true;
		pos++;
	}
	Types::parameters result;
	::ISPA_STD::assign_compatible(result.first, parameter_0);
	::ISPA_STD::assign_compatible(result.rest, uvar_15);
	::ISPA_STD::MatchResult<Rules, Types::parameters, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::parameters<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::parameters, ::Parser::Lexer::iterator>;
template auto Parser::Parser::parameters<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::parameters, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::parenthesized_content(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::parenthesized_content, IT> {
	::ISPA_STD::MatchResult<Rules, Types::expr, IT> expr_0;
	bool success_1;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::MatchResult<Rules, Types::tuple_suffix, IT> tuple_suffix_4;
	bool success_5;
	success_1 = false;
	expr_0 = expr(pos);
	if (!(expr_0.status)) {
		raise_error(*pos, "ISPA match failure: required named rule did not match | grammar: @  expr");
		return {};
	}
	success_1 = true;
	pos = expr_0.it;
	success_3 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_2 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_3 = true;
		pos++;
	}
	success_5 = false;
	tuple_suffix_4 = tuple_suffix(pos);
	if (tuple_suffix_4.status) {
		success_5 = true;
		pos = tuple_suffix_4.it;
	}
	Types::parenthesized_content result;
	::ISPA_STD::assign_compatible(result.first, expr_0);
	::ISPA_STD::assign_compatible(result.rest, tuple_suffix_4);
	::ISPA_STD::MatchResult<Rules, Types::parenthesized_content, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::parenthesized_content<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::parenthesized_content, ::Parser::Lexer::iterator>;
template auto Parser::Parser::parenthesized_content<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::parenthesized_content, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::parenthesized_expr(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::parenthesized_expr, IT> {
	::ISPA_STD::Node<::Parser::Tokens, Types::LPAREN> LPAREN_0;
	bool success_1;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::MatchResult<Rules, Types::parenthesized_content, IT> parenthesized_content_4;
	bool success_5;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_6;
	bool success_7;
	::ISPA_STD::Node<::Parser::Tokens, Types::RPAREN> RPAREN_8;
	bool success_9;
	success_1 = false;
	if (!(((*pos)).template holds<Types::LPAREN>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  LPAREN");
		return {};
	}
	LPAREN_0 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::LPAREN>>();
	success_1 = true;
	pos++;
	success_3 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_2 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_3 = true;
		pos++;
	}
	success_5 = false;
	parenthesized_content_4 = parenthesized_content(pos);
	if (parenthesized_content_4.status) {
		success_5 = true;
		pos = parenthesized_content_4.it;
	}
	success_7 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_6 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_7 = true;
		pos++;
	}
	success_9 = false;
	if (!(((*pos)).template holds<Types::RPAREN>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  RPAREN");
		return {};
	}
	RPAREN_8 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::RPAREN>>();
	success_9 = true;
	pos++;
	Types::parenthesized_expr result;
	::ISPA_STD::assign_compatible(result.value, parenthesized_content_4.node);
	::ISPA_STD::MatchResult<Rules, Types::parenthesized_expr, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::parenthesized_expr<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::parenthesized_expr, ::Parser::Lexer::iterator>;
template auto Parser::Parser::parenthesized_expr<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::parenthesized_expr, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::parenthesized_imports(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::parenthesized_imports, IT> {
	::ISPA_STD::Node<::Parser::Tokens, Types::LPAREN> LPAREN_0;
	bool success_1;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::MatchResult<Rules, Types::import_names, IT> import_names_4;
	bool success_5;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_6;
	bool success_7;
	::ISPA_STD::Node<::Parser::Tokens, Types::RPAREN> RPAREN_8;
	bool success_9;
	success_1 = false;
	if (!(((*pos)).template holds<Types::LPAREN>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  LPAREN");
		return {};
	}
	LPAREN_0 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::LPAREN>>();
	success_1 = true;
	pos++;
	success_3 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_2 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_3 = true;
		pos++;
	}
	success_5 = false;
	import_names_4 = import_names(pos);
	if (!(import_names_4.status)) {
		raise_error(*pos, "ISPA match failure: required named rule did not match | grammar: @  import_names");
		return {};
	}
	success_5 = true;
	pos = import_names_4.it;
	success_7 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_6 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_7 = true;
		pos++;
	}
	success_9 = false;
	if (!(((*pos)).template holds<Types::RPAREN>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  RPAREN");
		return {};
	}
	RPAREN_8 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::RPAREN>>();
	success_9 = true;
	pos++;
	Types::parenthesized_imports result;
	::ISPA_STD::assign_compatible(result.value, import_names_4.node);
	::ISPA_STD::MatchResult<Rules, Types::parenthesized_imports, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::parenthesized_imports<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::parenthesized_imports, ::Parser::Lexer::iterator>;
template auto Parser::Parser::parenthesized_imports<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::parenthesized_imports, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::pass_stmt(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::pass_stmt, IT> {
	::ISPA_STD::Node<::Parser::Tokens, Types::PASS> PASS_0;
	bool success_1;
	success_1 = false;
	if (!(((*pos)).template holds<Types::PASS>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  PASS");
		return {};
	}
	PASS_0 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::PASS>>();
	success_1 = true;
	pos++;
	Types::pass_stmt result;
	::ISPA_STD::MatchResult<Rules, Types::pass_stmt, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::pass_stmt<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::pass_stmt, ::Parser::Lexer::iterator>;
template auto Parser::Parser::pass_stmt<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::pass_stmt, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::postfix(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::postfix, IT> {
	std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Rules, Types::index_suffix>, ::ISPA_STD::Node<::Parser::Rules, Types::call_suffix>, ::ISPA_STD::Node<::Parser::Rules, Types::attribute_suffix>> _0;
	bool success_1;
	::ISPA_STD::MatchResult<Rules, Types::attribute_suffix, IT> attribute_suffix_2;
	bool success_3;
	::ISPA_STD::MatchResult<Rules, Types::index_suffix, IT> index_suffix_4;
	bool success_5;
	::ISPA_STD::MatchResult<Rules, Types::call_suffix, IT> call_suffix_6;
	bool success_7;
	success_1 = false;
	// grammar `@  ( attribute_suffix |  call_suffix |  index_suffix)`: choice; reset match status before selecting an alternative
	success_1 = false;
	auto lookahead_pos_1 = pos;
	switch (static_cast<Tokens>((*lookahead_pos_1).kind())) {
		case Tokens::DOT: {
			lookahead_pos_1 = lookahead_pos_1;
			success_3 = false;
			attribute_suffix_2 = attribute_suffix(lookahead_pos_1);
			if (!(attribute_suffix_2.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  attribute_suffix");
				return {};
			}
			success_3 = true;
			lookahead_pos_1 = attribute_suffix_2.it;
			if (!success_3) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  attribute_suffix");
				return {};
			}
			_0 = attribute_suffix_2.node;
			success_1 = true;
			break;
		}
		case Tokens::LBRACKET: {
			lookahead_pos_1 = lookahead_pos_1;
			success_5 = false;
			index_suffix_4 = index_suffix(lookahead_pos_1);
			if (!(index_suffix_4.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  index_suffix");
				return {};
			}
			success_5 = true;
			lookahead_pos_1 = index_suffix_4.it;
			if (!success_5) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  index_suffix");
				return {};
			}
			_0 = index_suffix_4.node;
			success_1 = true;
			break;
		}
		case Tokens::LPAREN: {
			lookahead_pos_1 = lookahead_pos_1;
			success_7 = false;
			call_suffix_6 = call_suffix(lookahead_pos_1);
			if (!(call_suffix_6.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  call_suffix");
				return {};
			}
			success_7 = true;
			lookahead_pos_1 = call_suffix_6.it;
			if (!success_7) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  call_suffix");
				return {};
			}
			_0 = call_suffix_6.node;
			success_1 = true;
			break;
		}
	}
	pos = lookahead_pos_1;
	if (!success_1) {
		raise_error(*pos, "ISPA match failure: no LL(k) alternative matched | grammar: @  ( attribute_suffix |  call_suffix |  index_suffix)");
		return {};
	}
	Types::postfix result;
	::ISPA_STD::assign_compatible(result.value, _0);
	::ISPA_STD::MatchResult<Rules, Types::postfix, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::postfix<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::postfix, ::Parser::Lexer::iterator>;
template auto Parser::Parser::postfix<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::postfix, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::power(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::power, IT> {
	::ISPA_STD::MatchResult<Rules, Types::primary, IT> primary_0;
	bool success_1;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::MatchResult<Rules, Types::power_tail, IT> power_tail_4;
	bool success_5;
	success_1 = false;
	primary_0 = primary(pos);
	if (!(primary_0.status)) {
		raise_error(*pos, "ISPA match failure: required named rule did not match | grammar: @  primary");
		return {};
	}
	success_1 = true;
	pos = primary_0.it;
	success_3 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_2 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_3 = true;
		pos++;
	}
	success_5 = false;
	power_tail_4 = power_tail(pos);
	if (power_tail_4.status) {
		success_5 = true;
		pos = power_tail_4.it;
	}
	Types::power result;
	::ISPA_STD::assign_compatible(result.base, primary_0);
	::ISPA_STD::assign_compatible(result.exponent, power_tail_4);
	::ISPA_STD::MatchResult<Rules, Types::power, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::power<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::power, ::Parser::Lexer::iterator>;
template auto Parser::Parser::power<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::power, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::power_tail(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::power_tail, IT> {
	::ISPA_STD::Node<::Parser::Tokens, Types::POWER> POWER_0;
	bool success_1;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::MatchResult<Rules, Types::factor, IT> factor_4;
	bool success_5;
	success_1 = false;
	if (!(((*pos)).template holds<Types::POWER>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  POWER");
		return {};
	}
	POWER_0 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::POWER>>();
	success_1 = true;
	pos++;
	success_3 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_2 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_3 = true;
		pos++;
	}
	success_5 = false;
	factor_4 = factor(pos);
	if (!(factor_4.status)) {
		raise_error(*pos, "ISPA match failure: required named rule did not match | grammar: @  factor");
		return {};
	}
	success_5 = true;
	pos = factor_4.it;
	Types::power_tail result;
	::ISPA_STD::assign_compatible(result.value, factor_4.node);
	::ISPA_STD::MatchResult<Rules, Types::power_tail, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::power_tail<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::power_tail, ::Parser::Lexer::iterator>;
template auto Parser::Parser::power_tail<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::power_tail, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::primary(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::primary, IT> {
	::ISPA_STD::MatchResult<Rules, Types::atom, IT> atom_0;
	bool success_1;
	::ISPA_STD::MatchResult<Rules, Types::postfix, IT> postfix_5;
	bool success_6;
	::ISPA_STD::Node<::Parser::Rules, Types::postfix> element_7;
	std::vector<::ISPA_STD::Node<::Parser::Rules, Types::postfix>> shadow_8;
	std::vector<::ISPA_STD::Node<::Parser::Rules, Types::postfix>> uvar_4;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	success_1 = false;
	atom_0 = atom(pos);
	if (!(atom_0.status)) {
		raise_error(*pos, "ISPA match failure: required named rule did not match | grammar: @  atom");
		return {};
	}
	success_1 = true;
	pos = atom_0.it;
	success_6 = false;
	// grammar `@  postfix*;`: repeat named rule; collect every matched value
	while (true) {
		auto repeat_ws_9 = pos;
		success_3 = false;
		if (((*repeat_ws_9)).template holds<Types::__WS>()) {
			__WS_2 = ((*repeat_ws_9)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
			success_3 = true;
			repeat_ws_9++;
		}
		postfix_5 = postfix(repeat_ws_9);
		if (!(postfix_5.status)) {
			break;
		}
		success_6 = true;
		repeat_ws_9 = postfix_5.it;
		element_7 = postfix_5.node;
		shadow_8.push_back(element_7);
		pos = repeat_ws_9;
	}
	::ISPA_STD::assign_compatible(uvar_4, shadow_8);
	Types::primary result;
	::ISPA_STD::assign_compatible(result.base, atom_0);
	::ISPA_STD::assign_compatible(result.suffixes, uvar_4);
	::ISPA_STD::MatchResult<Rules, Types::primary, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::primary<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::primary, ::Parser::Lexer::iterator>;
template auto Parser::Parser::primary<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::primary, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::raise_from(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::raise_from, IT> {
	::ISPA_STD::Node<::Parser::Tokens, Types::FROM> FROM_0;
	bool success_1;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::MatchResult<Rules, Types::expr, IT> expr_4;
	bool success_5;
	success_1 = false;
	if (!(((*pos)).template holds<Types::FROM>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  FROM");
		return {};
	}
	FROM_0 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::FROM>>();
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
	Types::raise_from result;
	::ISPA_STD::assign_compatible(result.value, expr_4.node);
	::ISPA_STD::MatchResult<Rules, Types::raise_from, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::raise_from<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::raise_from, ::Parser::Lexer::iterator>;
template auto Parser::Parser::raise_from<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::raise_from, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::raise_stmt(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::raise_stmt, IT> {
	::ISPA_STD::Node<::Parser::Tokens, Types::RAISE> RAISE_0;
	bool success_1;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::MatchResult<Rules, Types::expr, IT> expr_4;
	bool success_5;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_6;
	bool success_7;
	::ISPA_STD::MatchResult<Rules, Types::raise_from, IT> raise_from_8;
	bool success_9;
	success_1 = false;
	if (!(((*pos)).template holds<Types::RAISE>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  RAISE");
		return {};
	}
	RAISE_0 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::RAISE>>();
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
	if (expr_4.status) {
		success_5 = true;
		pos = expr_4.it;
	}
	success_7 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_6 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_7 = true;
		pos++;
	}
	success_9 = false;
	raise_from_8 = raise_from(pos);
	if (raise_from_8.status) {
		success_9 = true;
		pos = raise_from_8.it;
	}
	Types::raise_stmt result;
	::ISPA_STD::assign_compatible(result.exception, expr_4);
	::ISPA_STD::assign_compatible(result.cause, raise_from_8);
	::ISPA_STD::MatchResult<Rules, Types::raise_stmt, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::raise_stmt<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::raise_stmt, ::Parser::Lexer::iterator>;
template auto Parser::Parser::raise_stmt<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::raise_stmt, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::relative_module(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::relative_module, IT> {
	::ISPA_STD::Node<::Parser::Tokens, Types::DOT> DOT_1;
	bool success_2;
	std::vector<::ISPA_STD::Node<::Parser::Tokens, Types::DOT>> uvar_0;
	std::vector<::ISPA_STD::Node<::Parser::Tokens, Types::DOT>> shadow_3;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_4;
	bool success_5;
	::ISPA_STD::MatchResult<Rules, Types::dotted_name, IT> dotted_name_6;
	bool success_7;
	success_2 = false;
	while (((*pos)).template holds<Types::DOT>()) {
		DOT_1 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::DOT>>();
		success_2 = true;
		pos++;
		shadow_3.push_back(DOT_1);
	}
	// grammar `@  DOT*;`: repeat token; export all matched elements
	::ISPA_STD::assign_compatible(uvar_0, shadow_3);
	success_5 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_4 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_5 = true;
		pos++;
	}
	success_7 = false;
	dotted_name_6 = dotted_name(pos);
	if (dotted_name_6.status) {
		success_7 = true;
		pos = dotted_name_6.it;
	}
	Types::relative_module result;
	::ISPA_STD::assign_compatible(result.relative, uvar_0);
	::ISPA_STD::assign_compatible(result.name, dotted_name_6);
	::ISPA_STD::MatchResult<Rules, Types::relative_module, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::relative_module<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::relative_module, ::Parser::Lexer::iterator>;
template auto Parser::Parser::relative_module<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::relative_module, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::return_annotation(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::return_annotation, IT> {
	::ISPA_STD::Node<::Parser::Tokens, Types::ARROW> ARROW_0;
	bool success_1;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::MatchResult<Rules, Types::expr, IT> expr_4;
	bool success_5;
	success_1 = false;
	if (!(((*pos)).template holds<Types::ARROW>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  ARROW");
		return {};
	}
	ARROW_0 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::ARROW>>();
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
	Types::return_annotation result;
	::ISPA_STD::assign_compatible(result.value, expr_4.node);
	::ISPA_STD::MatchResult<Rules, Types::return_annotation, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::return_annotation<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::return_annotation, ::Parser::Lexer::iterator>;
template auto Parser::Parser::return_annotation<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::return_annotation, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::return_stmt(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::return_stmt, IT> {
	::ISPA_STD::Node<::Parser::Tokens, Types::RETURN> RETURN_0;
	bool success_1;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::MatchResult<Rules, Types::expr, IT> expr_4;
	bool success_5;
	success_1 = false;
	if (!(((*pos)).template holds<Types::RETURN>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  RETURN");
		return {};
	}
	RETURN_0 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::RETURN>>();
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
	if (expr_4.status) {
		success_5 = true;
		pos = expr_4.it;
	}
	Types::return_stmt result;
	::ISPA_STD::assign_compatible(result.value, expr_4.node);
	::ISPA_STD::MatchResult<Rules, Types::return_stmt, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::return_stmt<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::return_stmt, ::Parser::Lexer::iterator>;
template auto Parser::Parser::return_stmt<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::return_stmt, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::shift_expr(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::shift_expr, IT> {
	::ISPA_STD::MatchResult<Rules, Types::sum, IT> sum_0;
	bool success_1;
	::ISPA_STD::MatchResult<Rules, Types::shift_tail, IT> shift_tail_5;
	bool success_6;
	::ISPA_STD::Node<::Parser::Rules, Types::shift_tail> element_7;
	std::vector<::ISPA_STD::Node<::Parser::Rules, Types::shift_tail>> shadow_8;
	std::vector<::ISPA_STD::Node<::Parser::Rules, Types::shift_tail>> uvar_4;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	success_1 = false;
	sum_0 = sum(pos);
	if (!(sum_0.status)) {
		raise_error(*pos, "ISPA match failure: required named rule did not match | grammar: @  sum");
		return {};
	}
	success_1 = true;
	pos = sum_0.it;
	success_6 = false;
	// grammar `@  shift_tail*;`: repeat named rule; collect every matched value
	while (true) {
		auto repeat_ws_9 = pos;
		success_3 = false;
		if (((*repeat_ws_9)).template holds<Types::__WS>()) {
			__WS_2 = ((*repeat_ws_9)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
			success_3 = true;
			repeat_ws_9++;
		}
		shift_tail_5 = shift_tail(repeat_ws_9);
		if (!(shift_tail_5.status)) {
			break;
		}
		success_6 = true;
		repeat_ws_9 = shift_tail_5.it;
		element_7 = shift_tail_5.node;
		shadow_8.push_back(element_7);
		pos = repeat_ws_9;
	}
	::ISPA_STD::assign_compatible(uvar_4, shadow_8);
	Types::shift_expr result;
	::ISPA_STD::assign_compatible(result.first, sum_0);
	::ISPA_STD::assign_compatible(result.rest, uvar_4);
	::ISPA_STD::MatchResult<Rules, Types::shift_expr, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::shift_expr<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::shift_expr, ::Parser::Lexer::iterator>;
template auto Parser::Parser::shift_expr<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::shift_expr, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::shift_tail(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::shift_tail, IT> {
	std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Tokens, Types::RSHIFT>, ::ISPA_STD::Node<::Parser::Tokens, Types::LSHIFT>> _0;
	bool success_1;
	::ISPA_STD::Node<::Parser::Tokens, Types::LSHIFT> LSHIFT_2;
	bool success_3;
	::ISPA_STD::Node<::Parser::Tokens, Types::RSHIFT> RSHIFT_4;
	bool success_5;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_6;
	bool success_7;
	::ISPA_STD::MatchResult<Rules, Types::sum, IT> sum_8;
	bool success_9;
	success_1 = false;
	// grammar `@  ( LSHIFT |  RSHIFT)`: choice; reset match status before selecting an alternative
	success_1 = false;
	auto lookahead_pos_1 = pos;
	switch (static_cast<Tokens>((*lookahead_pos_1).kind())) {
		case Tokens::LSHIFT: {
			lookahead_pos_1 = lookahead_pos_1;
			success_3 = false;
			if (!(((*lookahead_pos_1)).template holds<Types::LSHIFT>())) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  LSHIFT");
				return {};
			}
			LSHIFT_2 = ((*lookahead_pos_1)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::LSHIFT>>();
			success_3 = true;
			lookahead_pos_1++;
			if (!success_3) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  LSHIFT");
				return {};
			}
			_0 = LSHIFT_2;
			success_1 = true;
			break;
		}
		case Tokens::RSHIFT: {
			lookahead_pos_1 = lookahead_pos_1;
			success_5 = false;
			if (!(((*lookahead_pos_1)).template holds<Types::RSHIFT>())) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  RSHIFT");
				return {};
			}
			RSHIFT_4 = ((*lookahead_pos_1)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::RSHIFT>>();
			success_5 = true;
			lookahead_pos_1++;
			if (!success_5) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  RSHIFT");
				return {};
			}
			_0 = RSHIFT_4;
			success_1 = true;
			break;
		}
	}
	pos = lookahead_pos_1;
	if (!success_1) {
		raise_error(*pos, "ISPA match failure: no LL(k) alternative matched | grammar: @  ( LSHIFT |  RSHIFT)");
		return {};
	}
	success_7 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_6 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_7 = true;
		pos++;
	}
	success_9 = false;
	sum_8 = sum(pos);
	if (!(sum_8.status)) {
		raise_error(*pos, "ISPA match failure: required named rule did not match | grammar: @  sum");
		return {};
	}
	success_9 = true;
	pos = sum_8.it;
	Types::shift_tail result;
	::ISPA_STD::assign_compatible(result.op, _0);
	::ISPA_STD::assign_compatible(result.value, sum_8);
	::ISPA_STD::MatchResult<Rules, Types::shift_tail, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::shift_tail<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::shift_tail, ::Parser::Lexer::iterator>;
template auto Parser::Parser::shift_tail<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::shift_tail, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::simple_stmt(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::simple_stmt, IT> {
	std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Rules, Types::expr_stmt>, ::ISPA_STD::Node<::Parser::Rules, Types::import_stmt>, ::ISPA_STD::Node<::Parser::Rules, Types::continue_stmt>, ::ISPA_STD::Node<::Parser::Rules, Types::assert_stmt>, ::ISPA_STD::Node<::Parser::Rules, Types::break_stmt>, ::ISPA_STD::Node<::Parser::Rules, Types::nonlocal_stmt>, ::ISPA_STD::Node<::Parser::Rules, Types::pass_stmt>, ::ISPA_STD::Node<::Parser::Rules, Types::global_stmt>, ::ISPA_STD::Node<::Parser::Rules, Types::return_stmt>, ::ISPA_STD::Node<::Parser::Rules, Types::del_stmt>, ::ISPA_STD::Node<::Parser::Rules, Types::raise_stmt>> _0;
	bool success_1;
	::ISPA_STD::MatchResult<Rules, Types::assert_stmt, IT> assert_stmt_2;
	bool success_3;
	::ISPA_STD::MatchResult<Rules, Types::break_stmt, IT> break_stmt_4;
	bool success_5;
	::ISPA_STD::MatchResult<Rules, Types::continue_stmt, IT> continue_stmt_6;
	bool success_7;
	::ISPA_STD::MatchResult<Rules, Types::del_stmt, IT> del_stmt_8;
	bool success_9;
	::ISPA_STD::MatchResult<Rules, Types::expr_stmt, IT> expr_stmt_10;
	bool success_11;
	::ISPA_STD::MatchResult<Rules, Types::import_stmt, IT> import_stmt_12;
	bool success_13;
	::ISPA_STD::MatchResult<Rules, Types::global_stmt, IT> global_stmt_14;
	bool success_15;
	::ISPA_STD::MatchResult<Rules, Types::expr_stmt, IT> expr_stmt_16;
	bool success_17;
	::ISPA_STD::MatchResult<Rules, Types::import_stmt, IT> import_stmt_18;
	bool success_19;
	::ISPA_STD::MatchResult<Rules, Types::expr_stmt, IT> expr_stmt_20;
	bool success_21;
	::ISPA_STD::MatchResult<Rules, Types::expr_stmt, IT> expr_stmt_22;
	bool success_23;
	::ISPA_STD::MatchResult<Rules, Types::expr_stmt, IT> expr_stmt_24;
	bool success_25;
	::ISPA_STD::MatchResult<Rules, Types::expr_stmt, IT> expr_stmt_26;
	bool success_27;
	::ISPA_STD::MatchResult<Rules, Types::expr_stmt, IT> expr_stmt_28;
	bool success_29;
	::ISPA_STD::MatchResult<Rules, Types::nonlocal_stmt, IT> nonlocal_stmt_30;
	bool success_31;
	::ISPA_STD::MatchResult<Rules, Types::expr_stmt, IT> expr_stmt_32;
	bool success_33;
	::ISPA_STD::MatchResult<Rules, Types::expr_stmt, IT> expr_stmt_34;
	bool success_35;
	::ISPA_STD::MatchResult<Rules, Types::pass_stmt, IT> pass_stmt_36;
	bool success_37;
	::ISPA_STD::MatchResult<Rules, Types::expr_stmt, IT> expr_stmt_38;
	bool success_39;
	::ISPA_STD::MatchResult<Rules, Types::raise_stmt, IT> raise_stmt_40;
	bool success_41;
	::ISPA_STD::MatchResult<Rules, Types::return_stmt, IT> return_stmt_42;
	bool success_43;
	::ISPA_STD::MatchResult<Rules, Types::expr_stmt, IT> expr_stmt_44;
	bool success_45;
	::ISPA_STD::MatchResult<Rules, Types::expr_stmt, IT> expr_stmt_46;
	bool success_47;
	::ISPA_STD::MatchResult<Rules, Types::expr_stmt, IT> expr_stmt_48;
	bool success_49;
	success_1 = false;
	// grammar `@  ( return_stmt |  raise_stmt |  del_stmt |  pass_stmt |  break_stmt |  continue_stmt |  assert_stmt |  global_stmt |  nonlocal_stmt |  import_stmt |  expr_stmt)`: choice; reset match status before selecting an alternative
	success_1 = false;
	auto lookahead_pos_1 = pos;
	switch (static_cast<Tokens>((*lookahead_pos_1).kind())) {
		case Tokens::ASSERT: {
			lookahead_pos_1 = lookahead_pos_1;
			success_3 = false;
			assert_stmt_2 = assert_stmt(lookahead_pos_1);
			if (!(assert_stmt_2.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  assert_stmt");
				return {};
			}
			success_3 = true;
			lookahead_pos_1 = assert_stmt_2.it;
			if (!success_3) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  assert_stmt");
				return {};
			}
			_0 = assert_stmt_2.node;
			success_1 = true;
			break;
		}
		case Tokens::BREAK: {
			lookahead_pos_1 = lookahead_pos_1;
			success_5 = false;
			break_stmt_4 = break_stmt(lookahead_pos_1);
			if (!(break_stmt_4.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  break_stmt");
				return {};
			}
			success_5 = true;
			lookahead_pos_1 = break_stmt_4.it;
			if (!success_5) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  break_stmt");
				return {};
			}
			_0 = break_stmt_4.node;
			success_1 = true;
			break;
		}
		case Tokens::CONTINUE: {
			lookahead_pos_1 = lookahead_pos_1;
			success_7 = false;
			continue_stmt_6 = continue_stmt(lookahead_pos_1);
			if (!(continue_stmt_6.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  continue_stmt");
				return {};
			}
			success_7 = true;
			lookahead_pos_1 = continue_stmt_6.it;
			if (!success_7) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  continue_stmt");
				return {};
			}
			_0 = continue_stmt_6.node;
			success_1 = true;
			break;
		}
		case Tokens::DEL: {
			lookahead_pos_1 = lookahead_pos_1;
			success_9 = false;
			del_stmt_8 = del_stmt(lookahead_pos_1);
			if (!(del_stmt_8.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  del_stmt");
				return {};
			}
			success_9 = true;
			lookahead_pos_1 = del_stmt_8.it;
			if (!success_9) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  del_stmt");
				return {};
			}
			_0 = del_stmt_8.node;
			success_1 = true;
			break;
		}
		case Tokens::FALSE: {
			lookahead_pos_1 = lookahead_pos_1;
			success_11 = false;
			expr_stmt_10 = expr_stmt(lookahead_pos_1);
			if (!(expr_stmt_10.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  expr_stmt");
				return {};
			}
			success_11 = true;
			lookahead_pos_1 = expr_stmt_10.it;
			if (!success_11) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  expr_stmt");
				return {};
			}
			_0 = expr_stmt_10.node;
			success_1 = true;
			break;
		}
		case Tokens::FROM: {
			lookahead_pos_1 = lookahead_pos_1;
			success_13 = false;
			import_stmt_12 = import_stmt(lookahead_pos_1);
			if (!(import_stmt_12.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  import_stmt");
				return {};
			}
			success_13 = true;
			lookahead_pos_1 = import_stmt_12.it;
			if (!success_13) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  import_stmt");
				return {};
			}
			_0 = import_stmt_12.node;
			success_1 = true;
			break;
		}
		case Tokens::GLOBAL: {
			lookahead_pos_1 = lookahead_pos_1;
			success_15 = false;
			global_stmt_14 = global_stmt(lookahead_pos_1);
			if (!(global_stmt_14.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  global_stmt");
				return {};
			}
			success_15 = true;
			lookahead_pos_1 = global_stmt_14.it;
			if (!success_15) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  global_stmt");
				return {};
			}
			_0 = global_stmt_14.node;
			success_1 = true;
			break;
		}
		case Tokens::ID: {
			lookahead_pos_1 = lookahead_pos_1;
			success_17 = false;
			expr_stmt_16 = expr_stmt(lookahead_pos_1);
			if (!(expr_stmt_16.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  expr_stmt");
				return {};
			}
			success_17 = true;
			lookahead_pos_1 = expr_stmt_16.it;
			if (!success_17) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  expr_stmt");
				return {};
			}
			_0 = expr_stmt_16.node;
			success_1 = true;
			break;
		}
		case Tokens::IMPORT: {
			lookahead_pos_1 = lookahead_pos_1;
			success_19 = false;
			import_stmt_18 = import_stmt(lookahead_pos_1);
			if (!(import_stmt_18.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  import_stmt");
				return {};
			}
			success_19 = true;
			lookahead_pos_1 = import_stmt_18.it;
			if (!success_19) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  import_stmt");
				return {};
			}
			_0 = import_stmt_18.node;
			success_1 = true;
			break;
		}
		case Tokens::LBRACE: {
			lookahead_pos_1 = lookahead_pos_1;
			success_21 = false;
			expr_stmt_20 = expr_stmt(lookahead_pos_1);
			if (!(expr_stmt_20.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  expr_stmt");
				return {};
			}
			success_21 = true;
			lookahead_pos_1 = expr_stmt_20.it;
			if (!success_21) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  expr_stmt");
				return {};
			}
			_0 = expr_stmt_20.node;
			success_1 = true;
			break;
		}
		case Tokens::LBRACKET: {
			lookahead_pos_1 = lookahead_pos_1;
			success_23 = false;
			expr_stmt_22 = expr_stmt(lookahead_pos_1);
			if (!(expr_stmt_22.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  expr_stmt");
				return {};
			}
			success_23 = true;
			lookahead_pos_1 = expr_stmt_22.it;
			if (!success_23) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  expr_stmt");
				return {};
			}
			_0 = expr_stmt_22.node;
			success_1 = true;
			break;
		}
		case Tokens::LPAREN: {
			lookahead_pos_1 = lookahead_pos_1;
			success_25 = false;
			expr_stmt_24 = expr_stmt(lookahead_pos_1);
			if (!(expr_stmt_24.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  expr_stmt");
				return {};
			}
			success_25 = true;
			lookahead_pos_1 = expr_stmt_24.it;
			if (!success_25) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  expr_stmt");
				return {};
			}
			_0 = expr_stmt_24.node;
			success_1 = true;
			break;
		}
		case Tokens::MINUS: {
			lookahead_pos_1 = lookahead_pos_1;
			success_27 = false;
			expr_stmt_26 = expr_stmt(lookahead_pos_1);
			if (!(expr_stmt_26.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  expr_stmt");
				return {};
			}
			success_27 = true;
			lookahead_pos_1 = expr_stmt_26.it;
			if (!success_27) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  expr_stmt");
				return {};
			}
			_0 = expr_stmt_26.node;
			success_1 = true;
			break;
		}
		case Tokens::NONE_V: {
			lookahead_pos_1 = lookahead_pos_1;
			success_29 = false;
			expr_stmt_28 = expr_stmt(lookahead_pos_1);
			if (!(expr_stmt_28.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  expr_stmt");
				return {};
			}
			success_29 = true;
			lookahead_pos_1 = expr_stmt_28.it;
			if (!success_29) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  expr_stmt");
				return {};
			}
			_0 = expr_stmt_28.node;
			success_1 = true;
			break;
		}
		case Tokens::NONLOCAL: {
			lookahead_pos_1 = lookahead_pos_1;
			success_31 = false;
			nonlocal_stmt_30 = nonlocal_stmt(lookahead_pos_1);
			if (!(nonlocal_stmt_30.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  nonlocal_stmt");
				return {};
			}
			success_31 = true;
			lookahead_pos_1 = nonlocal_stmt_30.it;
			if (!success_31) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  nonlocal_stmt");
				return {};
			}
			_0 = nonlocal_stmt_30.node;
			success_1 = true;
			break;
		}
		case Tokens::NOT: {
			lookahead_pos_1 = lookahead_pos_1;
			success_33 = false;
			expr_stmt_32 = expr_stmt(lookahead_pos_1);
			if (!(expr_stmt_32.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  expr_stmt");
				return {};
			}
			success_33 = true;
			lookahead_pos_1 = expr_stmt_32.it;
			if (!success_33) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  expr_stmt");
				return {};
			}
			_0 = expr_stmt_32.node;
			success_1 = true;
			break;
		}
		case Tokens::NUMBER: {
			lookahead_pos_1 = lookahead_pos_1;
			success_35 = false;
			expr_stmt_34 = expr_stmt(lookahead_pos_1);
			if (!(expr_stmt_34.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  expr_stmt");
				return {};
			}
			success_35 = true;
			lookahead_pos_1 = expr_stmt_34.it;
			if (!success_35) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  expr_stmt");
				return {};
			}
			_0 = expr_stmt_34.node;
			success_1 = true;
			break;
		}
		case Tokens::PASS: {
			lookahead_pos_1 = lookahead_pos_1;
			success_37 = false;
			pass_stmt_36 = pass_stmt(lookahead_pos_1);
			if (!(pass_stmt_36.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  pass_stmt");
				return {};
			}
			success_37 = true;
			lookahead_pos_1 = pass_stmt_36.it;
			if (!success_37) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  pass_stmt");
				return {};
			}
			_0 = pass_stmt_36.node;
			success_1 = true;
			break;
		}
		case Tokens::PLUS: {
			lookahead_pos_1 = lookahead_pos_1;
			success_39 = false;
			expr_stmt_38 = expr_stmt(lookahead_pos_1);
			if (!(expr_stmt_38.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  expr_stmt");
				return {};
			}
			success_39 = true;
			lookahead_pos_1 = expr_stmt_38.it;
			if (!success_39) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  expr_stmt");
				return {};
			}
			_0 = expr_stmt_38.node;
			success_1 = true;
			break;
		}
		case Tokens::RAISE: {
			lookahead_pos_1 = lookahead_pos_1;
			success_41 = false;
			raise_stmt_40 = raise_stmt(lookahead_pos_1);
			if (!(raise_stmt_40.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  raise_stmt");
				return {};
			}
			success_41 = true;
			lookahead_pos_1 = raise_stmt_40.it;
			if (!success_41) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  raise_stmt");
				return {};
			}
			_0 = raise_stmt_40.node;
			success_1 = true;
			break;
		}
		case Tokens::RETURN: {
			lookahead_pos_1 = lookahead_pos_1;
			success_43 = false;
			return_stmt_42 = return_stmt(lookahead_pos_1);
			if (!(return_stmt_42.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  return_stmt");
				return {};
			}
			success_43 = true;
			lookahead_pos_1 = return_stmt_42.it;
			if (!success_43) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  return_stmt");
				return {};
			}
			_0 = return_stmt_42.node;
			success_1 = true;
			break;
		}
		case Tokens::STRING: {
			lookahead_pos_1 = lookahead_pos_1;
			success_45 = false;
			expr_stmt_44 = expr_stmt(lookahead_pos_1);
			if (!(expr_stmt_44.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  expr_stmt");
				return {};
			}
			success_45 = true;
			lookahead_pos_1 = expr_stmt_44.it;
			if (!success_45) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  expr_stmt");
				return {};
			}
			_0 = expr_stmt_44.node;
			success_1 = true;
			break;
		}
		case Tokens::TILDE: {
			lookahead_pos_1 = lookahead_pos_1;
			success_47 = false;
			expr_stmt_46 = expr_stmt(lookahead_pos_1);
			if (!(expr_stmt_46.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  expr_stmt");
				return {};
			}
			success_47 = true;
			lookahead_pos_1 = expr_stmt_46.it;
			if (!success_47) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  expr_stmt");
				return {};
			}
			_0 = expr_stmt_46.node;
			success_1 = true;
			break;
		}
		case Tokens::TRUE: {
			lookahead_pos_1 = lookahead_pos_1;
			success_49 = false;
			expr_stmt_48 = expr_stmt(lookahead_pos_1);
			if (!(expr_stmt_48.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  expr_stmt");
				return {};
			}
			success_49 = true;
			lookahead_pos_1 = expr_stmt_48.it;
			if (!success_49) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  expr_stmt");
				return {};
			}
			_0 = expr_stmt_48.node;
			success_1 = true;
			break;
		}
	}
	pos = lookahead_pos_1;
	if (!success_1) {
		raise_error(*pos, "ISPA match failure: no LL(k) alternative matched | grammar: @  ( return_stmt |  raise_stmt |  del_stmt |  pass_stmt |  break_stmt |  continue_stmt |  assert_stmt |  global_stmt |  nonlocal_stmt |  import_stmt |  expr_stmt)");
		return {};
	}
	Types::simple_stmt result;
	::ISPA_STD::assign_compatible(result.value, _0);
	::ISPA_STD::MatchResult<Rules, Types::simple_stmt, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::simple_stmt<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::simple_stmt, ::Parser::Lexer::iterator>;
template auto Parser::Parser::simple_stmt<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::simple_stmt, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::simple_stmts(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::simple_stmts, IT> {
	::ISPA_STD::MatchResult<Rules, Types::simple_stmt, IT> simple_stmt_0;
	bool success_1;
	bool success_17;
	bool success_9;
	std::tuple<::ISPA_STD::Node<::Parser::Tokens, Types::SEMICOLON>, ::ISPA_STD::Node<::Parser::Tokens, Types::__WS>, ::ISPA_STD::Node<::Parser::Rules, Types::simple_stmt>> group_4;
	bool success_6;
	std::vector<std::tuple<::ISPA_STD::Node<::Parser::Tokens, Types::SEMICOLON>, ::ISPA_STD::Node<::Parser::Tokens, Types::__WS>, ::ISPA_STD::Node<::Parser::Rules, Types::simple_stmt>>> shadow_21;
	std::vector<std::tuple<::ISPA_STD::Node<::Parser::Tokens, Types::SEMICOLON>, ::ISPA_STD::Node<::Parser::Tokens, Types::__WS>, ::ISPA_STD::Node<::Parser::Rules, Types::simple_stmt>>> uvar_5;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::Node<::Parser::Tokens, Types::SEMICOLON> SEMICOLON_8;
	::ISPA_STD::Node<::Parser::Tokens, Types::SEMICOLON> uvar_7;
	std::vector<::ISPA_STD::Node<::Parser::Tokens, Types::SEMICOLON>> shadow_10;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_12;
	bool success_13;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> uvar_11;
	std::vector<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>> shadow_14;
	::ISPA_STD::MatchResult<Rules, Types::simple_stmt, IT> simple_stmt_16;
	::ISPA_STD::Node<::Parser::Rules, Types::simple_stmt> element_18;
	std::vector<::ISPA_STD::Node<::Parser::Rules, Types::simple_stmt>> shadow_19;
	::ISPA_STD::Node<::Parser::Rules, Types::simple_stmt> uvar_15;
	::ISPA_STD::Node<::Parser::Rules, Types::simple_stmt> tuple_elem_20;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_24;
	bool success_25;
	::ISPA_STD::Node<::Parser::Tokens, Types::SEMICOLON> SEMICOLON_26;
	bool success_27;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_28;
	bool success_29;
	::ISPA_STD::Node<::Parser::Tokens, Types::NEWLINE> NEWLINE_30;
	bool success_31;
	success_1 = false;
	simple_stmt_0 = simple_stmt(pos);
	if (!(simple_stmt_0.status)) {
		raise_error(*pos, "ISPA match failure: required named rule did not match | grammar: @  simple_stmt");
		return {};
	}
	success_1 = true;
	pos = simple_stmt_0.it;
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
		if (!(((*repeat_ws_23)).template holds<Types::SEMICOLON>())) {
			// speculative match failed (diagnostic suppressed):  SEMICOLON
			break;
		}
		SEMICOLON_8 = ((*repeat_ws_23)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::SEMICOLON>>();
		success_9 = true;
		repeat_ws_23++;
		shadow_10.push_back(SEMICOLON_8);
		uvar_7 = SEMICOLON_8;
		success_13 = false;
		if (((*repeat_ws_23)).template holds<Types::__WS>()) {
			__WS_12 = ((*repeat_ws_23)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
			success_13 = true;
			repeat_ws_23++;
			shadow_14.push_back(__WS_12);
			uvar_11 = __WS_12;
		}
		simple_stmt_16 = simple_stmt(repeat_ws_23);
		if (!(simple_stmt_16.status)) {
			// speculative match failed (diagnostic suppressed): @  simple_stmt
			break;
		}
		success_17 = true;
		repeat_ws_23 = simple_stmt_16.it;
		element_18 = simple_stmt_16.node;
		shadow_19.push_back(element_18);
		if (success_9 && success_17) {
			tuple_elem_20 = simple_stmt_16.node;
			group_4 = std::make_tuple(SEMICOLON_8, __WS_12, tuple_elem_20);
			shadow_21.push_back(group_4);
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
	if (((*pos)).template holds<Types::SEMICOLON>()) {
		SEMICOLON_26 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::SEMICOLON>>();
		success_27 = true;
		pos++;
	}
	success_29 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_28 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_29 = true;
		pos++;
	}
	success_31 = false;
	if (!(((*pos)).template holds<Types::NEWLINE>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  NEWLINE");
		return {};
	}
	NEWLINE_30 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::NEWLINE>>();
	success_31 = true;
	pos++;
	Types::simple_stmts result;
	::ISPA_STD::assign_compatible(result.first, simple_stmt_0);
	::ISPA_STD::assign_compatible(result.rest, uvar_15);
	::ISPA_STD::MatchResult<Rules, Types::simple_stmts, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::simple_stmts<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::simple_stmts, ::Parser::Lexer::iterator>;
template auto Parser::Parser::simple_stmts<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::simple_stmts, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::statement(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::statement, IT> {
	std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Rules, Types::simple_stmts>, ::ISPA_STD::Node<::Parser::Rules, Types::compound_stmt>> _0;
	bool success_1;
	::ISPA_STD::MatchResult<Rules, Types::simple_stmts, IT> simple_stmts_2;
	bool success_3;
	::ISPA_STD::MatchResult<Rules, Types::compound_stmt, IT> compound_stmt_4;
	bool success_5;
	::ISPA_STD::MatchResult<Rules, Types::simple_stmts, IT> simple_stmts_6;
	bool success_7;
	::ISPA_STD::MatchResult<Rules, Types::compound_stmt, IT> compound_stmt_8;
	bool success_9;
	::ISPA_STD::MatchResult<Rules, Types::simple_stmts, IT> simple_stmts_10;
	bool success_11;
	::ISPA_STD::MatchResult<Rules, Types::compound_stmt, IT> compound_stmt_12;
	bool success_13;
	::ISPA_STD::MatchResult<Rules, Types::simple_stmts, IT> simple_stmts_14;
	bool success_15;
	::ISPA_STD::MatchResult<Rules, Types::simple_stmts, IT> simple_stmts_16;
	bool success_17;
	::ISPA_STD::MatchResult<Rules, Types::compound_stmt, IT> compound_stmt_18;
	bool success_19;
	::ISPA_STD::MatchResult<Rules, Types::simple_stmts, IT> simple_stmts_20;
	bool success_21;
	::ISPA_STD::MatchResult<Rules, Types::simple_stmts, IT> simple_stmts_22;
	bool success_23;
	::ISPA_STD::MatchResult<Rules, Types::simple_stmts, IT> simple_stmts_24;
	bool success_25;
	::ISPA_STD::MatchResult<Rules, Types::compound_stmt, IT> compound_stmt_26;
	bool success_27;
	::ISPA_STD::MatchResult<Rules, Types::simple_stmts, IT> simple_stmts_28;
	bool success_29;
	::ISPA_STD::MatchResult<Rules, Types::simple_stmts, IT> simple_stmts_30;
	bool success_31;
	::ISPA_STD::MatchResult<Rules, Types::simple_stmts, IT> simple_stmts_32;
	bool success_33;
	::ISPA_STD::MatchResult<Rules, Types::simple_stmts, IT> simple_stmts_34;
	bool success_35;
	::ISPA_STD::MatchResult<Rules, Types::compound_stmt, IT> compound_stmt_36;
	bool success_37;
	::ISPA_STD::MatchResult<Rules, Types::simple_stmts, IT> simple_stmts_38;
	bool success_39;
	::ISPA_STD::MatchResult<Rules, Types::simple_stmts, IT> simple_stmts_40;
	bool success_41;
	::ISPA_STD::MatchResult<Rules, Types::simple_stmts, IT> simple_stmts_42;
	bool success_43;
	::ISPA_STD::MatchResult<Rules, Types::simple_stmts, IT> simple_stmts_44;
	bool success_45;
	::ISPA_STD::MatchResult<Rules, Types::simple_stmts, IT> simple_stmts_46;
	bool success_47;
	::ISPA_STD::MatchResult<Rules, Types::simple_stmts, IT> simple_stmts_48;
	bool success_49;
	::ISPA_STD::MatchResult<Rules, Types::simple_stmts, IT> simple_stmts_50;
	bool success_51;
	::ISPA_STD::MatchResult<Rules, Types::simple_stmts, IT> simple_stmts_52;
	bool success_53;
	::ISPA_STD::MatchResult<Rules, Types::simple_stmts, IT> simple_stmts_54;
	bool success_55;
	::ISPA_STD::MatchResult<Rules, Types::simple_stmts, IT> simple_stmts_56;
	bool success_57;
	::ISPA_STD::MatchResult<Rules, Types::simple_stmts, IT> simple_stmts_58;
	bool success_59;
	::ISPA_STD::MatchResult<Rules, Types::simple_stmts, IT> simple_stmts_60;
	bool success_61;
	::ISPA_STD::MatchResult<Rules, Types::compound_stmt, IT> compound_stmt_62;
	bool success_63;
	::ISPA_STD::MatchResult<Rules, Types::compound_stmt, IT> compound_stmt_64;
	bool success_65;
	::ISPA_STD::MatchResult<Rules, Types::compound_stmt, IT> compound_stmt_66;
	bool success_67;
	success_1 = false;
	// grammar `@  ( compound_stmt |  simple_stmts)`: choice; reset match status before selecting an alternative
	success_1 = false;
	auto lookahead_pos_1 = pos;
	switch (static_cast<Tokens>((*lookahead_pos_1).kind())) {
		case Tokens::ASSERT: {
			lookahead_pos_1 = lookahead_pos_1;
			success_3 = false;
			simple_stmts_2 = simple_stmts(lookahead_pos_1);
			if (!(simple_stmts_2.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  simple_stmts");
				return {};
			}
			success_3 = true;
			lookahead_pos_1 = simple_stmts_2.it;
			if (!success_3) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  simple_stmts");
				return {};
			}
			_0 = simple_stmts_2.node;
			success_1 = true;
			break;
		}
		case Tokens::ASYNC: {
			lookahead_pos_1 = lookahead_pos_1;
			success_5 = false;
			compound_stmt_4 = compound_stmt(lookahead_pos_1);
			if (!(compound_stmt_4.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  compound_stmt");
				return {};
			}
			success_5 = true;
			lookahead_pos_1 = compound_stmt_4.it;
			if (!success_5) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  compound_stmt");
				return {};
			}
			_0 = compound_stmt_4.node;
			success_1 = true;
			break;
		}
		case Tokens::BREAK: {
			lookahead_pos_1 = lookahead_pos_1;
			success_7 = false;
			simple_stmts_6 = simple_stmts(lookahead_pos_1);
			if (!(simple_stmts_6.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  simple_stmts");
				return {};
			}
			success_7 = true;
			lookahead_pos_1 = simple_stmts_6.it;
			if (!success_7) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  simple_stmts");
				return {};
			}
			_0 = simple_stmts_6.node;
			success_1 = true;
			break;
		}
		case Tokens::CLASS: {
			lookahead_pos_1 = lookahead_pos_1;
			success_9 = false;
			compound_stmt_8 = compound_stmt(lookahead_pos_1);
			if (!(compound_stmt_8.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  compound_stmt");
				return {};
			}
			success_9 = true;
			lookahead_pos_1 = compound_stmt_8.it;
			if (!success_9) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  compound_stmt");
				return {};
			}
			_0 = compound_stmt_8.node;
			success_1 = true;
			break;
		}
		case Tokens::CONTINUE: {
			lookahead_pos_1 = lookahead_pos_1;
			success_11 = false;
			simple_stmts_10 = simple_stmts(lookahead_pos_1);
			if (!(simple_stmts_10.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  simple_stmts");
				return {};
			}
			success_11 = true;
			lookahead_pos_1 = simple_stmts_10.it;
			if (!success_11) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  simple_stmts");
				return {};
			}
			_0 = simple_stmts_10.node;
			success_1 = true;
			break;
		}
		case Tokens::DEF: {
			lookahead_pos_1 = lookahead_pos_1;
			success_13 = false;
			compound_stmt_12 = compound_stmt(lookahead_pos_1);
			if (!(compound_stmt_12.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  compound_stmt");
				return {};
			}
			success_13 = true;
			lookahead_pos_1 = compound_stmt_12.it;
			if (!success_13) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  compound_stmt");
				return {};
			}
			_0 = compound_stmt_12.node;
			success_1 = true;
			break;
		}
		case Tokens::DEL: {
			lookahead_pos_1 = lookahead_pos_1;
			success_15 = false;
			simple_stmts_14 = simple_stmts(lookahead_pos_1);
			if (!(simple_stmts_14.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  simple_stmts");
				return {};
			}
			success_15 = true;
			lookahead_pos_1 = simple_stmts_14.it;
			if (!success_15) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  simple_stmts");
				return {};
			}
			_0 = simple_stmts_14.node;
			success_1 = true;
			break;
		}
		case Tokens::FALSE: {
			lookahead_pos_1 = lookahead_pos_1;
			success_17 = false;
			simple_stmts_16 = simple_stmts(lookahead_pos_1);
			if (!(simple_stmts_16.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  simple_stmts");
				return {};
			}
			success_17 = true;
			lookahead_pos_1 = simple_stmts_16.it;
			if (!success_17) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  simple_stmts");
				return {};
			}
			_0 = simple_stmts_16.node;
			success_1 = true;
			break;
		}
		case Tokens::FOR: {
			lookahead_pos_1 = lookahead_pos_1;
			success_19 = false;
			compound_stmt_18 = compound_stmt(lookahead_pos_1);
			if (!(compound_stmt_18.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  compound_stmt");
				return {};
			}
			success_19 = true;
			lookahead_pos_1 = compound_stmt_18.it;
			if (!success_19) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  compound_stmt");
				return {};
			}
			_0 = compound_stmt_18.node;
			success_1 = true;
			break;
		}
		case Tokens::FROM: {
			lookahead_pos_1 = lookahead_pos_1;
			success_21 = false;
			simple_stmts_20 = simple_stmts(lookahead_pos_1);
			if (!(simple_stmts_20.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  simple_stmts");
				return {};
			}
			success_21 = true;
			lookahead_pos_1 = simple_stmts_20.it;
			if (!success_21) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  simple_stmts");
				return {};
			}
			_0 = simple_stmts_20.node;
			success_1 = true;
			break;
		}
		case Tokens::GLOBAL: {
			lookahead_pos_1 = lookahead_pos_1;
			success_23 = false;
			simple_stmts_22 = simple_stmts(lookahead_pos_1);
			if (!(simple_stmts_22.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  simple_stmts");
				return {};
			}
			success_23 = true;
			lookahead_pos_1 = simple_stmts_22.it;
			if (!success_23) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  simple_stmts");
				return {};
			}
			_0 = simple_stmts_22.node;
			success_1 = true;
			break;
		}
		case Tokens::ID: {
			lookahead_pos_1 = lookahead_pos_1;
			success_25 = false;
			simple_stmts_24 = simple_stmts(lookahead_pos_1);
			if (!(simple_stmts_24.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  simple_stmts");
				return {};
			}
			success_25 = true;
			lookahead_pos_1 = simple_stmts_24.it;
			if (!success_25) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  simple_stmts");
				return {};
			}
			_0 = simple_stmts_24.node;
			success_1 = true;
			break;
		}
		case Tokens::IF: {
			lookahead_pos_1 = lookahead_pos_1;
			success_27 = false;
			compound_stmt_26 = compound_stmt(lookahead_pos_1);
			if (!(compound_stmt_26.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  compound_stmt");
				return {};
			}
			success_27 = true;
			lookahead_pos_1 = compound_stmt_26.it;
			if (!success_27) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  compound_stmt");
				return {};
			}
			_0 = compound_stmt_26.node;
			success_1 = true;
			break;
		}
		case Tokens::IMPORT: {
			lookahead_pos_1 = lookahead_pos_1;
			success_29 = false;
			simple_stmts_28 = simple_stmts(lookahead_pos_1);
			if (!(simple_stmts_28.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  simple_stmts");
				return {};
			}
			success_29 = true;
			lookahead_pos_1 = simple_stmts_28.it;
			if (!success_29) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  simple_stmts");
				return {};
			}
			_0 = simple_stmts_28.node;
			success_1 = true;
			break;
		}
		case Tokens::LBRACE: {
			lookahead_pos_1 = lookahead_pos_1;
			success_31 = false;
			simple_stmts_30 = simple_stmts(lookahead_pos_1);
			if (!(simple_stmts_30.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  simple_stmts");
				return {};
			}
			success_31 = true;
			lookahead_pos_1 = simple_stmts_30.it;
			if (!success_31) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  simple_stmts");
				return {};
			}
			_0 = simple_stmts_30.node;
			success_1 = true;
			break;
		}
		case Tokens::LBRACKET: {
			lookahead_pos_1 = lookahead_pos_1;
			success_33 = false;
			simple_stmts_32 = simple_stmts(lookahead_pos_1);
			if (!(simple_stmts_32.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  simple_stmts");
				return {};
			}
			success_33 = true;
			lookahead_pos_1 = simple_stmts_32.it;
			if (!success_33) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  simple_stmts");
				return {};
			}
			_0 = simple_stmts_32.node;
			success_1 = true;
			break;
		}
		case Tokens::LPAREN: {
			lookahead_pos_1 = lookahead_pos_1;
			success_35 = false;
			simple_stmts_34 = simple_stmts(lookahead_pos_1);
			if (!(simple_stmts_34.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  simple_stmts");
				return {};
			}
			success_35 = true;
			lookahead_pos_1 = simple_stmts_34.it;
			if (!success_35) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  simple_stmts");
				return {};
			}
			_0 = simple_stmts_34.node;
			success_1 = true;
			break;
		}
		case Tokens::MATMUL: {
			lookahead_pos_1 = lookahead_pos_1;
			success_37 = false;
			compound_stmt_36 = compound_stmt(lookahead_pos_1);
			if (!(compound_stmt_36.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  compound_stmt");
				return {};
			}
			success_37 = true;
			lookahead_pos_1 = compound_stmt_36.it;
			if (!success_37) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  compound_stmt");
				return {};
			}
			_0 = compound_stmt_36.node;
			success_1 = true;
			break;
		}
		case Tokens::MINUS: {
			lookahead_pos_1 = lookahead_pos_1;
			success_39 = false;
			simple_stmts_38 = simple_stmts(lookahead_pos_1);
			if (!(simple_stmts_38.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  simple_stmts");
				return {};
			}
			success_39 = true;
			lookahead_pos_1 = simple_stmts_38.it;
			if (!success_39) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  simple_stmts");
				return {};
			}
			_0 = simple_stmts_38.node;
			success_1 = true;
			break;
		}
		case Tokens::NONE_V: {
			lookahead_pos_1 = lookahead_pos_1;
			success_41 = false;
			simple_stmts_40 = simple_stmts(lookahead_pos_1);
			if (!(simple_stmts_40.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  simple_stmts");
				return {};
			}
			success_41 = true;
			lookahead_pos_1 = simple_stmts_40.it;
			if (!success_41) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  simple_stmts");
				return {};
			}
			_0 = simple_stmts_40.node;
			success_1 = true;
			break;
		}
		case Tokens::NONLOCAL: {
			lookahead_pos_1 = lookahead_pos_1;
			success_43 = false;
			simple_stmts_42 = simple_stmts(lookahead_pos_1);
			if (!(simple_stmts_42.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  simple_stmts");
				return {};
			}
			success_43 = true;
			lookahead_pos_1 = simple_stmts_42.it;
			if (!success_43) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  simple_stmts");
				return {};
			}
			_0 = simple_stmts_42.node;
			success_1 = true;
			break;
		}
		case Tokens::NOT: {
			lookahead_pos_1 = lookahead_pos_1;
			success_45 = false;
			simple_stmts_44 = simple_stmts(lookahead_pos_1);
			if (!(simple_stmts_44.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  simple_stmts");
				return {};
			}
			success_45 = true;
			lookahead_pos_1 = simple_stmts_44.it;
			if (!success_45) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  simple_stmts");
				return {};
			}
			_0 = simple_stmts_44.node;
			success_1 = true;
			break;
		}
		case Tokens::NUMBER: {
			lookahead_pos_1 = lookahead_pos_1;
			success_47 = false;
			simple_stmts_46 = simple_stmts(lookahead_pos_1);
			if (!(simple_stmts_46.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  simple_stmts");
				return {};
			}
			success_47 = true;
			lookahead_pos_1 = simple_stmts_46.it;
			if (!success_47) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  simple_stmts");
				return {};
			}
			_0 = simple_stmts_46.node;
			success_1 = true;
			break;
		}
		case Tokens::PASS: {
			lookahead_pos_1 = lookahead_pos_1;
			success_49 = false;
			simple_stmts_48 = simple_stmts(lookahead_pos_1);
			if (!(simple_stmts_48.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  simple_stmts");
				return {};
			}
			success_49 = true;
			lookahead_pos_1 = simple_stmts_48.it;
			if (!success_49) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  simple_stmts");
				return {};
			}
			_0 = simple_stmts_48.node;
			success_1 = true;
			break;
		}
		case Tokens::PLUS: {
			lookahead_pos_1 = lookahead_pos_1;
			success_51 = false;
			simple_stmts_50 = simple_stmts(lookahead_pos_1);
			if (!(simple_stmts_50.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  simple_stmts");
				return {};
			}
			success_51 = true;
			lookahead_pos_1 = simple_stmts_50.it;
			if (!success_51) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  simple_stmts");
				return {};
			}
			_0 = simple_stmts_50.node;
			success_1 = true;
			break;
		}
		case Tokens::RAISE: {
			lookahead_pos_1 = lookahead_pos_1;
			success_53 = false;
			simple_stmts_52 = simple_stmts(lookahead_pos_1);
			if (!(simple_stmts_52.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  simple_stmts");
				return {};
			}
			success_53 = true;
			lookahead_pos_1 = simple_stmts_52.it;
			if (!success_53) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  simple_stmts");
				return {};
			}
			_0 = simple_stmts_52.node;
			success_1 = true;
			break;
		}
		case Tokens::RETURN: {
			lookahead_pos_1 = lookahead_pos_1;
			success_55 = false;
			simple_stmts_54 = simple_stmts(lookahead_pos_1);
			if (!(simple_stmts_54.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  simple_stmts");
				return {};
			}
			success_55 = true;
			lookahead_pos_1 = simple_stmts_54.it;
			if (!success_55) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  simple_stmts");
				return {};
			}
			_0 = simple_stmts_54.node;
			success_1 = true;
			break;
		}
		case Tokens::STRING: {
			lookahead_pos_1 = lookahead_pos_1;
			success_57 = false;
			simple_stmts_56 = simple_stmts(lookahead_pos_1);
			if (!(simple_stmts_56.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  simple_stmts");
				return {};
			}
			success_57 = true;
			lookahead_pos_1 = simple_stmts_56.it;
			if (!success_57) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  simple_stmts");
				return {};
			}
			_0 = simple_stmts_56.node;
			success_1 = true;
			break;
		}
		case Tokens::TILDE: {
			lookahead_pos_1 = lookahead_pos_1;
			success_59 = false;
			simple_stmts_58 = simple_stmts(lookahead_pos_1);
			if (!(simple_stmts_58.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  simple_stmts");
				return {};
			}
			success_59 = true;
			lookahead_pos_1 = simple_stmts_58.it;
			if (!success_59) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  simple_stmts");
				return {};
			}
			_0 = simple_stmts_58.node;
			success_1 = true;
			break;
		}
		case Tokens::TRUE: {
			lookahead_pos_1 = lookahead_pos_1;
			success_61 = false;
			simple_stmts_60 = simple_stmts(lookahead_pos_1);
			if (!(simple_stmts_60.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  simple_stmts");
				return {};
			}
			success_61 = true;
			lookahead_pos_1 = simple_stmts_60.it;
			if (!success_61) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  simple_stmts");
				return {};
			}
			_0 = simple_stmts_60.node;
			success_1 = true;
			break;
		}
		case Tokens::TRY: {
			lookahead_pos_1 = lookahead_pos_1;
			success_63 = false;
			compound_stmt_62 = compound_stmt(lookahead_pos_1);
			if (!(compound_stmt_62.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  compound_stmt");
				return {};
			}
			success_63 = true;
			lookahead_pos_1 = compound_stmt_62.it;
			if (!success_63) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  compound_stmt");
				return {};
			}
			_0 = compound_stmt_62.node;
			success_1 = true;
			break;
		}
		case Tokens::WHILE: {
			lookahead_pos_1 = lookahead_pos_1;
			success_65 = false;
			compound_stmt_64 = compound_stmt(lookahead_pos_1);
			if (!(compound_stmt_64.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  compound_stmt");
				return {};
			}
			success_65 = true;
			lookahead_pos_1 = compound_stmt_64.it;
			if (!success_65) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  compound_stmt");
				return {};
			}
			_0 = compound_stmt_64.node;
			success_1 = true;
			break;
		}
		case Tokens::WITH: {
			lookahead_pos_1 = lookahead_pos_1;
			success_67 = false;
			compound_stmt_66 = compound_stmt(lookahead_pos_1);
			if (!(compound_stmt_66.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  compound_stmt");
				return {};
			}
			success_67 = true;
			lookahead_pos_1 = compound_stmt_66.it;
			if (!success_67) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  compound_stmt");
				return {};
			}
			_0 = compound_stmt_66.node;
			success_1 = true;
			break;
		}
	}
	pos = lookahead_pos_1;
	if (!success_1) {
		raise_error(*pos, "ISPA match failure: no LL(k) alternative matched | grammar: @  ( compound_stmt |  simple_stmts)");
		return {};
	}
	Types::statement result;
	::ISPA_STD::assign_compatible(result.value, _0);
	::ISPA_STD::MatchResult<Rules, Types::statement, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::statement<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::statement, ::Parser::Lexer::iterator>;
template auto Parser::Parser::statement<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::statement, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::sum(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::sum, IT> {
	::ISPA_STD::MatchResult<Rules, Types::term, IT> term_0;
	bool success_1;
	::ISPA_STD::MatchResult<Rules, Types::sum_tail, IT> sum_tail_5;
	bool success_6;
	::ISPA_STD::Node<::Parser::Rules, Types::sum_tail> element_7;
	std::vector<::ISPA_STD::Node<::Parser::Rules, Types::sum_tail>> shadow_8;
	std::vector<::ISPA_STD::Node<::Parser::Rules, Types::sum_tail>> uvar_4;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	success_1 = false;
	term_0 = term(pos);
	if (!(term_0.status)) {
		raise_error(*pos, "ISPA match failure: required named rule did not match | grammar: @  term");
		return {};
	}
	success_1 = true;
	pos = term_0.it;
	success_6 = false;
	// grammar `@  sum_tail*;`: repeat named rule; collect every matched value
	while (true) {
		auto repeat_ws_9 = pos;
		success_3 = false;
		if (((*repeat_ws_9)).template holds<Types::__WS>()) {
			__WS_2 = ((*repeat_ws_9)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
			success_3 = true;
			repeat_ws_9++;
		}
		sum_tail_5 = sum_tail(repeat_ws_9);
		if (!(sum_tail_5.status)) {
			break;
		}
		success_6 = true;
		repeat_ws_9 = sum_tail_5.it;
		element_7 = sum_tail_5.node;
		shadow_8.push_back(element_7);
		pos = repeat_ws_9;
	}
	::ISPA_STD::assign_compatible(uvar_4, shadow_8);
	Types::sum result;
	::ISPA_STD::assign_compatible(result.first, term_0);
	::ISPA_STD::assign_compatible(result.rest, uvar_4);
	::ISPA_STD::MatchResult<Rules, Types::sum, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::sum<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::sum, ::Parser::Lexer::iterator>;
template auto Parser::Parser::sum<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::sum, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::sum_tail(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::sum_tail, IT> {
	std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Tokens, Types::MINUS>, ::ISPA_STD::Node<::Parser::Tokens, Types::PLUS>> _0;
	bool success_1;
	::ISPA_STD::Node<::Parser::Tokens, Types::MINUS> MINUS_2;
	bool success_3;
	::ISPA_STD::Node<::Parser::Tokens, Types::PLUS> PLUS_4;
	bool success_5;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_6;
	bool success_7;
	::ISPA_STD::MatchResult<Rules, Types::term, IT> term_8;
	bool success_9;
	success_1 = false;
	// grammar `@  ( PLUS |  MINUS)`: choice; reset match status before selecting an alternative
	success_1 = false;
	auto lookahead_pos_1 = pos;
	switch (static_cast<Tokens>((*lookahead_pos_1).kind())) {
		case Tokens::MINUS: {
			lookahead_pos_1 = lookahead_pos_1;
			success_3 = false;
			if (!(((*lookahead_pos_1)).template holds<Types::MINUS>())) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  MINUS");
				return {};
			}
			MINUS_2 = ((*lookahead_pos_1)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::MINUS>>();
			success_3 = true;
			lookahead_pos_1++;
			if (!success_3) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  MINUS");
				return {};
			}
			_0 = MINUS_2;
			success_1 = true;
			break;
		}
		case Tokens::PLUS: {
			lookahead_pos_1 = lookahead_pos_1;
			success_5 = false;
			if (!(((*lookahead_pos_1)).template holds<Types::PLUS>())) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  PLUS");
				return {};
			}
			PLUS_4 = ((*lookahead_pos_1)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::PLUS>>();
			success_5 = true;
			lookahead_pos_1++;
			if (!success_5) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  PLUS");
				return {};
			}
			_0 = PLUS_4;
			success_1 = true;
			break;
		}
	}
	pos = lookahead_pos_1;
	if (!success_1) {
		raise_error(*pos, "ISPA match failure: no LL(k) alternative matched | grammar: @  ( PLUS |  MINUS)");
		return {};
	}
	success_7 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_6 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_7 = true;
		pos++;
	}
	success_9 = false;
	term_8 = term(pos);
	if (!(term_8.status)) {
		raise_error(*pos, "ISPA match failure: required named rule did not match | grammar: @  term");
		return {};
	}
	success_9 = true;
	pos = term_8.it;
	Types::sum_tail result;
	::ISPA_STD::assign_compatible(result.op, _0);
	::ISPA_STD::assign_compatible(result.value, term_8);
	::ISPA_STD::MatchResult<Rules, Types::sum_tail, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::sum_tail<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::sum_tail, ::Parser::Lexer::iterator>;
template auto Parser::Parser::sum_tail<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::sum_tail, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::term(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::term, IT> {
	::ISPA_STD::MatchResult<Rules, Types::factor, IT> factor_0;
	bool success_1;
	::ISPA_STD::MatchResult<Rules, Types::term_tail, IT> term_tail_5;
	bool success_6;
	::ISPA_STD::Node<::Parser::Rules, Types::term_tail> element_7;
	std::vector<::ISPA_STD::Node<::Parser::Rules, Types::term_tail>> shadow_8;
	std::vector<::ISPA_STD::Node<::Parser::Rules, Types::term_tail>> uvar_4;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	success_1 = false;
	factor_0 = factor(pos);
	if (!(factor_0.status)) {
		raise_error(*pos, "ISPA match failure: required named rule did not match | grammar: @  factor");
		return {};
	}
	success_1 = true;
	pos = factor_0.it;
	success_6 = false;
	// grammar `@  term_tail*;`: repeat named rule; collect every matched value
	while (true) {
		auto repeat_ws_9 = pos;
		success_3 = false;
		if (((*repeat_ws_9)).template holds<Types::__WS>()) {
			__WS_2 = ((*repeat_ws_9)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
			success_3 = true;
			repeat_ws_9++;
		}
		term_tail_5 = term_tail(repeat_ws_9);
		if (!(term_tail_5.status)) {
			break;
		}
		success_6 = true;
		repeat_ws_9 = term_tail_5.it;
		element_7 = term_tail_5.node;
		shadow_8.push_back(element_7);
		pos = repeat_ws_9;
	}
	::ISPA_STD::assign_compatible(uvar_4, shadow_8);
	Types::term result;
	::ISPA_STD::assign_compatible(result.first, factor_0);
	::ISPA_STD::assign_compatible(result.rest, uvar_4);
	::ISPA_STD::MatchResult<Rules, Types::term, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::term<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::term, ::Parser::Lexer::iterator>;
template auto Parser::Parser::term<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::term, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::term_tail(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::term_tail, IT> {
	std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Tokens, Types::PERCENT>, ::ISPA_STD::Node<::Parser::Tokens, Types::SLASH>, ::ISPA_STD::Node<::Parser::Tokens, Types::STAR>, ::ISPA_STD::Node<::Parser::Tokens, Types::MATMUL>, ::ISPA_STD::Node<::Parser::Tokens, Types::FLOOR_DIV>> _0;
	bool success_1;
	::ISPA_STD::Node<::Parser::Tokens, Types::FLOOR_DIV> FLOOR_DIV_2;
	bool success_3;
	::ISPA_STD::Node<::Parser::Tokens, Types::MATMUL> MATMUL_4;
	bool success_5;
	::ISPA_STD::Node<::Parser::Tokens, Types::PERCENT> PERCENT_6;
	bool success_7;
	::ISPA_STD::Node<::Parser::Tokens, Types::SLASH> SLASH_8;
	bool success_9;
	::ISPA_STD::Node<::Parser::Tokens, Types::STAR> STAR_10;
	bool success_11;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_12;
	bool success_13;
	::ISPA_STD::MatchResult<Rules, Types::factor, IT> factor_14;
	bool success_15;
	success_1 = false;
	// grammar `@  ( FLOOR_DIV |  STAR |  SLASH |  PERCENT |  MATMUL)`: choice; reset match status before selecting an alternative
	success_1 = false;
	auto lookahead_pos_1 = pos;
	switch (static_cast<Tokens>((*lookahead_pos_1).kind())) {
		case Tokens::FLOOR_DIV: {
			lookahead_pos_1 = lookahead_pos_1;
			success_3 = false;
			if (!(((*lookahead_pos_1)).template holds<Types::FLOOR_DIV>())) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  FLOOR_DIV");
				return {};
			}
			FLOOR_DIV_2 = ((*lookahead_pos_1)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::FLOOR_DIV>>();
			success_3 = true;
			lookahead_pos_1++;
			if (!success_3) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  FLOOR_DIV");
				return {};
			}
			_0 = FLOOR_DIV_2;
			success_1 = true;
			break;
		}
		case Tokens::MATMUL: {
			lookahead_pos_1 = lookahead_pos_1;
			success_5 = false;
			if (!(((*lookahead_pos_1)).template holds<Types::MATMUL>())) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  MATMUL");
				return {};
			}
			MATMUL_4 = ((*lookahead_pos_1)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::MATMUL>>();
			success_5 = true;
			lookahead_pos_1++;
			if (!success_5) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  MATMUL");
				return {};
			}
			_0 = MATMUL_4;
			success_1 = true;
			break;
		}
		case Tokens::PERCENT: {
			lookahead_pos_1 = lookahead_pos_1;
			success_7 = false;
			if (!(((*lookahead_pos_1)).template holds<Types::PERCENT>())) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  PERCENT");
				return {};
			}
			PERCENT_6 = ((*lookahead_pos_1)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::PERCENT>>();
			success_7 = true;
			lookahead_pos_1++;
			if (!success_7) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  PERCENT");
				return {};
			}
			_0 = PERCENT_6;
			success_1 = true;
			break;
		}
		case Tokens::SLASH: {
			lookahead_pos_1 = lookahead_pos_1;
			success_9 = false;
			if (!(((*lookahead_pos_1)).template holds<Types::SLASH>())) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  SLASH");
				return {};
			}
			SLASH_8 = ((*lookahead_pos_1)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::SLASH>>();
			success_9 = true;
			lookahead_pos_1++;
			if (!success_9) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  SLASH");
				return {};
			}
			_0 = SLASH_8;
			success_1 = true;
			break;
		}
		case Tokens::STAR: {
			lookahead_pos_1 = lookahead_pos_1;
			success_11 = false;
			if (!(((*lookahead_pos_1)).template holds<Types::STAR>())) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  STAR");
				return {};
			}
			STAR_10 = ((*lookahead_pos_1)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::STAR>>();
			success_11 = true;
			lookahead_pos_1++;
			if (!success_11) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  STAR");
				return {};
			}
			_0 = STAR_10;
			success_1 = true;
			break;
		}
	}
	pos = lookahead_pos_1;
	if (!success_1) {
		raise_error(*pos, "ISPA match failure: no LL(k) alternative matched | grammar: @  ( FLOOR_DIV |  STAR |  SLASH |  PERCENT |  MATMUL)");
		return {};
	}
	success_13 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_12 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_13 = true;
		pos++;
	}
	success_15 = false;
	factor_14 = factor(pos);
	if (!(factor_14.status)) {
		raise_error(*pos, "ISPA match failure: required named rule did not match | grammar: @  factor");
		return {};
	}
	success_15 = true;
	pos = factor_14.it;
	Types::term_tail result;
	::ISPA_STD::assign_compatible(result.op, _0);
	::ISPA_STD::assign_compatible(result.value, factor_14);
	::ISPA_STD::MatchResult<Rules, Types::term_tail, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::term_tail<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::term_tail, ::Parser::Lexer::iterator>;
template auto Parser::Parser::term_tail<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::term_tail, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::try_stmt(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::try_stmt, IT> {
	::ISPA_STD::Node<::Parser::Tokens, Types::TRY> TRY_0;
	bool success_1;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::Node<::Parser::Tokens, Types::COLON> COLON_4;
	bool success_5;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_6;
	bool success_7;
	::ISPA_STD::MatchResult<Rules, Types::block, IT> block_8;
	bool success_9;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_10;
	bool success_11;
	::ISPA_STD::MatchResult<Rules, Types::try_tail, IT> try_tail_12;
	bool success_13;
	success_1 = false;
	if (!(((*pos)).template holds<Types::TRY>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  TRY");
		return {};
	}
	TRY_0 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::TRY>>();
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
	block_8 = block(pos);
	if (!(block_8.status)) {
		raise_error(*pos, "ISPA match failure: required named rule did not match | grammar: @  block");
		return {};
	}
	success_9 = true;
	pos = block_8.it;
	success_11 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_10 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_11 = true;
		pos++;
	}
	success_13 = false;
	try_tail_12 = try_tail(pos);
	if (!(try_tail_12.status)) {
		raise_error(*pos, "ISPA match failure: required named rule did not match | grammar: @  try_tail");
		return {};
	}
	success_13 = true;
	pos = try_tail_12.it;
	Types::try_stmt result;
	::ISPA_STD::assign_compatible(result.body, block_8);
	::ISPA_STD::assign_compatible(result.handlers, try_tail_12);
	::ISPA_STD::MatchResult<Rules, Types::try_stmt, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::try_stmt<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::try_stmt, ::Parser::Lexer::iterator>;
template auto Parser::Parser::try_stmt<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::try_stmt, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::try_tail(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::try_tail, IT> {
	std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Rules, Types::finally_clause>, ::ISPA_STD::Node<::Parser::Rules, Types::except_handlers>> _0;
	bool success_1;
	::ISPA_STD::MatchResult<Rules, Types::except_handlers, IT> except_handlers_2;
	bool success_3;
	::ISPA_STD::MatchResult<Rules, Types::finally_clause, IT> finally_clause_4;
	bool success_5;
	success_1 = false;
	// grammar `@  ( except_handlers |  finally_clause)`: choice; reset match status before selecting an alternative
	success_1 = false;
	auto lookahead_pos_1 = pos;
	switch (static_cast<Tokens>((*lookahead_pos_1).kind())) {
		case Tokens::EXCEPT: {
			lookahead_pos_1 = lookahead_pos_1;
			success_3 = false;
			except_handlers_2 = except_handlers(lookahead_pos_1);
			if (!(except_handlers_2.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  except_handlers");
				return {};
			}
			success_3 = true;
			lookahead_pos_1 = except_handlers_2.it;
			if (!success_3) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  except_handlers");
				return {};
			}
			_0 = except_handlers_2.node;
			success_1 = true;
			break;
		}
		case Tokens::FINALLY: {
			lookahead_pos_1 = lookahead_pos_1;
			success_5 = false;
			finally_clause_4 = finally_clause(lookahead_pos_1);
			if (!(finally_clause_4.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  finally_clause");
				return {};
			}
			success_5 = true;
			lookahead_pos_1 = finally_clause_4.it;
			if (!success_5) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  finally_clause");
				return {};
			}
			_0 = finally_clause_4.node;
			success_1 = true;
			break;
		}
	}
	pos = lookahead_pos_1;
	if (!success_1) {
		raise_error(*pos, "ISPA match failure: no LL(k) alternative matched | grammar: @  ( except_handlers |  finally_clause)");
		return {};
	}
	Types::try_tail result;
	::ISPA_STD::assign_compatible(result.value, _0);
	::ISPA_STD::MatchResult<Rules, Types::try_tail, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::try_tail<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::try_tail, ::Parser::Lexer::iterator>;
template auto Parser::Parser::try_tail<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::try_tail, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::tuple_elements(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::tuple_elements, IT> {
	::ISPA_STD::MatchResult<Rules, Types::expr, IT> expr_0;
	bool success_1;
	bool success_17;
	bool success_9;
	std::vector<::ISPA_STD::Node<::Parser::Tokens, Types::COMMA>> shadow_20;
	::ISPA_STD::Node<::Parser::Rules, Types::expr> group_capture_21;
	std::vector<::ISPA_STD::Node<::Parser::Rules, Types::expr>> shadow_22;
	std::tuple<::ISPA_STD::Node<::Parser::Tokens, Types::COMMA>, ::ISPA_STD::Node<::Parser::Tokens, Types::__WS>, ::ISPA_STD::Node<::Parser::Rules, Types::expr>> group_4;
	bool success_6;
	std::vector<std::tuple<::ISPA_STD::Node<::Parser::Tokens, Types::COMMA>, ::ISPA_STD::Node<::Parser::Tokens, Types::__WS>, ::ISPA_STD::Node<::Parser::Rules, Types::expr>>> shadow_24;
	std::vector<std::tuple<::ISPA_STD::Node<::Parser::Tokens, Types::COMMA>, ::ISPA_STD::Node<::Parser::Tokens, Types::__WS>, ::ISPA_STD::Node<::Parser::Rules, Types::expr>>> uvar_5;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::Node<::Parser::Tokens, Types::COMMA> COMMA_8;
	::ISPA_STD::Node<::Parser::Tokens, Types::COMMA> uvar_7;
	std::vector<::ISPA_STD::Node<::Parser::Tokens, Types::COMMA>> shadow_10;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_12;
	bool success_13;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> uvar_11;
	std::vector<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>> shadow_14;
	::ISPA_STD::MatchResult<Rules, Types::expr, IT> expr_16;
	::ISPA_STD::Node<::Parser::Rules, Types::expr> element_18;
	std::vector<::ISPA_STD::Node<::Parser::Rules, Types::expr>> shadow_19;
	::ISPA_STD::Node<::Parser::Rules, Types::expr> uvar_15;
	::ISPA_STD::Node<::Parser::Rules, Types::expr> tuple_elem_23;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_27;
	bool success_28;
	::ISPA_STD::Node<::Parser::Tokens, Types::COMMA> COMMA_29;
	bool success_30;
	success_1 = false;
	expr_0 = expr(pos);
	if (!(expr_0.status)) {
		raise_error(*pos, "ISPA match failure: required named rule did not match | grammar: @  expr");
		return {};
	}
	success_1 = true;
	pos = expr_0.it;
	success_6 = false;
	auto begin_25 = pos;
	while (true) {
		auto repeat_ws_26 = begin_25;
		success_3 = false;
		if (((*repeat_ws_26)).template holds<Types::__WS>()) {
			__WS_2 = ((*repeat_ws_26)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
			success_3 = true;
			repeat_ws_26++;
		}
		if (!(((*repeat_ws_26)).template holds<Types::COMMA>())) {
			// speculative match failed (diagnostic suppressed):  COMMA
			break;
		}
		COMMA_8 = ((*repeat_ws_26)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::COMMA>>();
		success_9 = true;
		repeat_ws_26++;
		shadow_10.push_back(COMMA_8);
		uvar_7 = COMMA_8;
		success_13 = false;
		if (((*repeat_ws_26)).template holds<Types::__WS>()) {
			__WS_12 = ((*repeat_ws_26)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
			success_13 = true;
			repeat_ws_26++;
			shadow_14.push_back(__WS_12);
			uvar_11 = __WS_12;
		}
		expr_16 = expr(repeat_ws_26);
		if (!(expr_16.status)) {
			// speculative match failed (diagnostic suppressed): @  expr
			break;
		}
		success_17 = true;
		repeat_ws_26 = expr_16.it;
		element_18 = expr_16.node;
		shadow_19.push_back(element_18);
		if (success_9 && success_17) {
			tuple_elem_23 = expr_16.node;
			group_4 = std::make_tuple(COMMA_8, __WS_12, tuple_elem_23);
			shadow_24.push_back(group_4);
			shadow_20.push_back(COMMA_8);
			group_capture_21 = expr_16.node;
			shadow_22.push_back(group_capture_21);
		}
		begin_25 = repeat_ws_26;
	}
	success_6 = true;
	::ISPA_STD::assign_compatible(uvar_5, shadow_24);
	pos = begin_25;
	success_28 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_27 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_28 = true;
		pos++;
	}
	success_30 = false;
	if (((*pos)).template holds<Types::COMMA>()) {
		COMMA_29 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::COMMA>>();
		success_30 = true;
		pos++;
	}
	Types::tuple_elements result;
	::ISPA_STD::assign_compatible(result.first, expr_0);
	::ISPA_STD::assign_compatible(result.rest, shadow_22);
	::ISPA_STD::MatchResult<Rules, Types::tuple_elements, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::tuple_elements<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::tuple_elements, ::Parser::Lexer::iterator>;
template auto Parser::Parser::tuple_elements<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::tuple_elements, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::tuple_suffix(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::tuple_suffix, IT> {
	::ISPA_STD::Node<::Parser::Tokens, Types::COMMA> COMMA_0;
	bool success_1;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::MatchResult<Rules, Types::tuple_elements, IT> tuple_elements_4;
	bool success_5;
	success_1 = false;
	if (!(((*pos)).template holds<Types::COMMA>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  COMMA");
		return {};
	}
	COMMA_0 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::COMMA>>();
	success_1 = true;
	pos++;
	success_3 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_2 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_3 = true;
		pos++;
	}
	success_5 = false;
	tuple_elements_4 = tuple_elements(pos);
	if (tuple_elements_4.status) {
		success_5 = true;
		pos = tuple_elements_4.it;
	}
	Types::tuple_suffix result;
	::ISPA_STD::assign_compatible(result.value, tuple_elements_4.node);
	::ISPA_STD::MatchResult<Rules, Types::tuple_suffix, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::tuple_suffix<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::tuple_suffix, ::Parser::Lexer::iterator>;
template auto Parser::Parser::tuple_suffix<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::tuple_suffix, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::unary_expr(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::unary_expr, IT> {
	std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Tokens, Types::TILDE>, ::ISPA_STD::Node<::Parser::Tokens, Types::MINUS>, ::ISPA_STD::Node<::Parser::Tokens, Types::PLUS>> _0;
	bool success_1;
	::ISPA_STD::Node<::Parser::Tokens, Types::MINUS> MINUS_2;
	bool success_3;
	::ISPA_STD::Node<::Parser::Tokens, Types::PLUS> PLUS_4;
	bool success_5;
	::ISPA_STD::Node<::Parser::Tokens, Types::TILDE> TILDE_6;
	bool success_7;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_8;
	bool success_9;
	::ISPA_STD::MatchResult<Rules, Types::factor, IT> factor_10;
	bool success_11;
	success_1 = false;
	// grammar `@  ( PLUS |  MINUS |  TILDE)`: choice; reset match status before selecting an alternative
	success_1 = false;
	auto lookahead_pos_1 = pos;
	switch (static_cast<Tokens>((*lookahead_pos_1).kind())) {
		case Tokens::MINUS: {
			lookahead_pos_1 = lookahead_pos_1;
			success_3 = false;
			if (!(((*lookahead_pos_1)).template holds<Types::MINUS>())) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  MINUS");
				return {};
			}
			MINUS_2 = ((*lookahead_pos_1)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::MINUS>>();
			success_3 = true;
			lookahead_pos_1++;
			if (!success_3) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  MINUS");
				return {};
			}
			_0 = MINUS_2;
			success_1 = true;
			break;
		}
		case Tokens::PLUS: {
			lookahead_pos_1 = lookahead_pos_1;
			success_5 = false;
			if (!(((*lookahead_pos_1)).template holds<Types::PLUS>())) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  PLUS");
				return {};
			}
			PLUS_4 = ((*lookahead_pos_1)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::PLUS>>();
			success_5 = true;
			lookahead_pos_1++;
			if (!success_5) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  PLUS");
				return {};
			}
			_0 = PLUS_4;
			success_1 = true;
			break;
		}
		case Tokens::TILDE: {
			lookahead_pos_1 = lookahead_pos_1;
			success_7 = false;
			if (!(((*lookahead_pos_1)).template holds<Types::TILDE>())) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  TILDE");
				return {};
			}
			TILDE_6 = ((*lookahead_pos_1)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::TILDE>>();
			success_7 = true;
			lookahead_pos_1++;
			if (!success_7) {
				raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  TILDE");
				return {};
			}
			_0 = TILDE_6;
			success_1 = true;
			break;
		}
	}
	pos = lookahead_pos_1;
	if (!success_1) {
		raise_error(*pos, "ISPA match failure: no LL(k) alternative matched | grammar: @  ( PLUS |  MINUS |  TILDE)");
		return {};
	}
	success_9 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_8 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_9 = true;
		pos++;
	}
	success_11 = false;
	factor_10 = factor(pos);
	if (!(factor_10.status)) {
		raise_error(*pos, "ISPA match failure: required named rule did not match | grammar: @  factor");
		return {};
	}
	success_11 = true;
	pos = factor_10.it;
	Types::unary_expr result;
	::ISPA_STD::assign_compatible(result.op, _0);
	::ISPA_STD::assign_compatible(result.value, factor_10);
	::ISPA_STD::MatchResult<Rules, Types::unary_expr, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::unary_expr<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::unary_expr, ::Parser::Lexer::iterator>;
template auto Parser::Parser::unary_expr<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::unary_expr, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::while_stmt(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::while_stmt, IT> {
	::ISPA_STD::Node<::Parser::Tokens, Types::WHILE> WHILE_0;
	bool success_1;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::MatchResult<Rules, Types::expr, IT> expr_4;
	bool success_5;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_6;
	bool success_7;
	::ISPA_STD::Node<::Parser::Tokens, Types::COLON> COLON_8;
	bool success_9;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_10;
	bool success_11;
	::ISPA_STD::MatchResult<Rules, Types::block, IT> block_12;
	bool success_13;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_14;
	bool success_15;
	::ISPA_STD::MatchResult<Rules, Types::else_clause, IT> else_clause_16;
	bool success_17;
	success_1 = false;
	if (!(((*pos)).template holds<Types::WHILE>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  WHILE");
		return {};
	}
	WHILE_0 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::WHILE>>();
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
	if (!(((*pos)).template holds<Types::COLON>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  COLON");
		return {};
	}
	COLON_8 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::COLON>>();
	success_9 = true;
	pos++;
	success_11 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_10 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_11 = true;
		pos++;
	}
	success_13 = false;
	block_12 = block(pos);
	if (!(block_12.status)) {
		raise_error(*pos, "ISPA match failure: required named rule did not match | grammar: @  block");
		return {};
	}
	success_13 = true;
	pos = block_12.it;
	success_15 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_14 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_15 = true;
		pos++;
	}
	success_17 = false;
	else_clause_16 = else_clause(pos);
	if (else_clause_16.status) {
		success_17 = true;
		pos = else_clause_16.it;
	}
	Types::while_stmt result;
	::ISPA_STD::assign_compatible(result.condition, expr_4);
	::ISPA_STD::assign_compatible(result.body, block_12);
	::ISPA_STD::assign_compatible(result.otherwise, else_clause_16);
	::ISPA_STD::MatchResult<Rules, Types::while_stmt, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::while_stmt<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::while_stmt, ::Parser::Lexer::iterator>;
template auto Parser::Parser::while_stmt<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::while_stmt, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::with_as(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::with_as, IT> {
	::ISPA_STD::Node<::Parser::Tokens, Types::AS> AS_0;
	bool success_1;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::MatchResult<Rules, Types::assignment_target, IT> assignment_target_4;
	bool success_5;
	success_1 = false;
	if (!(((*pos)).template holds<Types::AS>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  AS");
		return {};
	}
	AS_0 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::AS>>();
	success_1 = true;
	pos++;
	success_3 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_2 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_3 = true;
		pos++;
	}
	success_5 = false;
	assignment_target_4 = assignment_target(pos);
	if (!(assignment_target_4.status)) {
		raise_error(*pos, "ISPA match failure: required named rule did not match | grammar: @  assignment_target");
		return {};
	}
	success_5 = true;
	pos = assignment_target_4.it;
	Types::with_as result;
	::ISPA_STD::assign_compatible(result.value, assignment_target_4.node);
	::ISPA_STD::MatchResult<Rules, Types::with_as, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::with_as<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::with_as, ::Parser::Lexer::iterator>;
template auto Parser::Parser::with_as<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::with_as, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::with_item(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::with_item, IT> {
	::ISPA_STD::MatchResult<Rules, Types::expr, IT> expr_0;
	bool success_1;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::MatchResult<Rules, Types::with_as, IT> with_as_4;
	bool success_5;
	success_1 = false;
	expr_0 = expr(pos);
	if (!(expr_0.status)) {
		raise_error(*pos, "ISPA match failure: required named rule did not match | grammar: @  expr");
		return {};
	}
	success_1 = true;
	pos = expr_0.it;
	success_3 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_2 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_3 = true;
		pos++;
	}
	success_5 = false;
	with_as_4 = with_as(pos);
	if (with_as_4.status) {
		success_5 = true;
		pos = with_as_4.it;
	}
	Types::with_item result;
	::ISPA_STD::assign_compatible(result.context, expr_0);
	::ISPA_STD::assign_compatible(result.target, with_as_4);
	::ISPA_STD::MatchResult<Rules, Types::with_item, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::with_item<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::with_item, ::Parser::Lexer::iterator>;
template auto Parser::Parser::with_item<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::with_item, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::with_items(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::with_items, IT> {
	::ISPA_STD::MatchResult<Rules, Types::with_item, IT> with_item_0;
	bool success_1;
	bool success_17;
	bool success_9;
	std::tuple<::ISPA_STD::Node<::Parser::Tokens, Types::COMMA>, ::ISPA_STD::Node<::Parser::Tokens, Types::__WS>, ::ISPA_STD::Node<::Parser::Rules, Types::with_item>> group_4;
	bool success_6;
	std::vector<std::tuple<::ISPA_STD::Node<::Parser::Tokens, Types::COMMA>, ::ISPA_STD::Node<::Parser::Tokens, Types::__WS>, ::ISPA_STD::Node<::Parser::Rules, Types::with_item>>> shadow_21;
	std::vector<std::tuple<::ISPA_STD::Node<::Parser::Tokens, Types::COMMA>, ::ISPA_STD::Node<::Parser::Tokens, Types::__WS>, ::ISPA_STD::Node<::Parser::Rules, Types::with_item>>> uvar_5;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::Node<::Parser::Tokens, Types::COMMA> COMMA_8;
	::ISPA_STD::Node<::Parser::Tokens, Types::COMMA> uvar_7;
	std::vector<::ISPA_STD::Node<::Parser::Tokens, Types::COMMA>> shadow_10;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_12;
	bool success_13;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> uvar_11;
	std::vector<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>> shadow_14;
	::ISPA_STD::MatchResult<Rules, Types::with_item, IT> with_item_16;
	::ISPA_STD::Node<::Parser::Rules, Types::with_item> element_18;
	std::vector<::ISPA_STD::Node<::Parser::Rules, Types::with_item>> shadow_19;
	::ISPA_STD::Node<::Parser::Rules, Types::with_item> uvar_15;
	::ISPA_STD::Node<::Parser::Rules, Types::with_item> tuple_elem_20;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_24;
	bool success_25;
	::ISPA_STD::Node<::Parser::Tokens, Types::COMMA> COMMA_26;
	bool success_27;
	success_1 = false;
	with_item_0 = with_item(pos);
	if (!(with_item_0.status)) {
		raise_error(*pos, "ISPA match failure: required named rule did not match | grammar: @  with_item");
		return {};
	}
	success_1 = true;
	pos = with_item_0.it;
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
		with_item_16 = with_item(repeat_ws_23);
		if (!(with_item_16.status)) {
			// speculative match failed (diagnostic suppressed): @  with_item
			break;
		}
		success_17 = true;
		repeat_ws_23 = with_item_16.it;
		element_18 = with_item_16.node;
		shadow_19.push_back(element_18);
		if (success_9 && success_17) {
			tuple_elem_20 = with_item_16.node;
			group_4 = std::make_tuple(COMMA_8, __WS_12, tuple_elem_20);
			shadow_21.push_back(group_4);
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
	if (((*pos)).template holds<Types::COMMA>()) {
		COMMA_26 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::COMMA>>();
		success_27 = true;
		pos++;
	}
	Types::with_items result;
	::ISPA_STD::assign_compatible(result.first, with_item_0);
	::ISPA_STD::assign_compatible(result.rest, uvar_15);
	::ISPA_STD::MatchResult<Rules, Types::with_items, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::with_items<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::with_items, ::Parser::Lexer::iterator>;
template auto Parser::Parser::with_items<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::with_items, ::Parser::Lexer::lazy_iterator>;
template<typename IT, class> auto Parser::Parser::with_stmt(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::with_stmt, IT> {
	::ISPA_STD::Node<::Parser::Tokens, Types::ASYNC> ASYNC_0;
	bool success_1;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
	bool success_3;
	::ISPA_STD::Node<::Parser::Tokens, Types::WITH> WITH_4;
	bool success_5;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_6;
	bool success_7;
	::ISPA_STD::MatchResult<Rules, Types::with_items, IT> with_items_8;
	bool success_9;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_10;
	bool success_11;
	::ISPA_STD::Node<::Parser::Tokens, Types::COLON> COLON_12;
	bool success_13;
	::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_14;
	bool success_15;
	::ISPA_STD::MatchResult<Rules, Types::block, IT> block_16;
	bool success_17;
	success_1 = false;
	if (((*pos)).template holds<Types::ASYNC>()) {
		ASYNC_0 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::ASYNC>>();
		success_1 = true;
		pos++;
	}
	success_3 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_2 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_3 = true;
		pos++;
	}
	success_5 = false;
	if (!(((*pos)).template holds<Types::WITH>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  WITH");
		return {};
	}
	WITH_4 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::WITH>>();
	success_5 = true;
	pos++;
	success_7 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_6 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_7 = true;
		pos++;
	}
	success_9 = false;
	with_items_8 = with_items(pos);
	if (!(with_items_8.status)) {
		raise_error(*pos, "ISPA match failure: required named rule did not match | grammar: @  with_items");
		return {};
	}
	success_9 = true;
	pos = with_items_8.it;
	success_11 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_10 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_11 = true;
		pos++;
	}
	success_13 = false;
	if (!(((*pos)).template holds<Types::COLON>())) {
		raise_error(*pos, "ISPA match failure: required token did not match | grammar:  COLON");
		return {};
	}
	COLON_12 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::COLON>>();
	success_13 = true;
	pos++;
	success_15 = false;
	if (((*pos)).template holds<Types::__WS>()) {
		__WS_14 = ((*pos)).template to_node<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>();
		success_15 = true;
		pos++;
	}
	success_17 = false;
	block_16 = block(pos);
	if (!(block_16.status)) {
		raise_error(*pos, "ISPA match failure: required named rule did not match | grammar: @  block");
		return {};
	}
	success_17 = true;
	pos = block_16.it;
	Types::with_stmt result;
	::ISPA_STD::assign_compatible(result.async, ASYNC_0);
	::ISPA_STD::assign_compatible(result.items, with_items_8);
	::ISPA_STD::assign_compatible(result.body, block_16);
	::ISPA_STD::MatchResult<Rules, Types::with_stmt, IT> match_result;
	match_result.status = true;
	match_result.node.set_data(result);
	match_result.it = pos;
	return match_result;
}
template auto Parser::Parser::with_stmt<::Parser::Lexer::iterator>(::Parser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::with_stmt, ::Parser::Lexer::iterator>;
template auto Parser::Parser::with_stmt<::Parser::Lexer::lazy_iterator>(::Parser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Rules, Types::with_stmt, ::Parser::Lexer::lazy_iterator>;
auto Parser::Parser::parseFromTokens() -> void {
	tree = main(Lexer::iterator(lexer)).node.data();
}
auto Parser::Parser::lazyParse() -> void {
	Lexer lexer;
	tree = main(Lexer::lazy_iterator(lexer, text)).node.data();
}
