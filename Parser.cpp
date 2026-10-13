#include "Parser.h"
auto ::Parser::FlatTypes::__WS::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("__WS", true);
}
auto ::Parser::FlatTypes::__WS::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::__WS::to_string () const -> std::string{
	return ::ISPA_STD::concat("__WS {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const __WS &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::SLASH_ASSIGN::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("SLASH_ASSIGN", true);
}
auto ::Parser::FlatTypes::SLASH_ASSIGN::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::SLASH_ASSIGN::to_string () const -> std::string{
	return ::ISPA_STD::concat("SLASH_ASSIGN {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const SLASH_ASSIGN &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::STAR::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("STAR", true);
}
auto ::Parser::FlatTypes::STAR::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::STAR::to_string () const -> std::string{
	return ::ISPA_STD::concat("STAR {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const STAR &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::SLASH::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("SLASH", true);
}
auto ::Parser::FlatTypes::SLASH::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::SLASH::to_string () const -> std::string{
	return ::ISPA_STD::concat("SLASH {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const SLASH &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::RSHIFT_ASSIGN::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("RSHIFT_ASSIGN", true);
}
auto ::Parser::FlatTypes::RSHIFT_ASSIGN::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::RSHIFT_ASSIGN::to_string () const -> std::string{
	return ::ISPA_STD::concat("RSHIFT_ASSIGN {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const RSHIFT_ASSIGN &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::RSHIFT::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("RSHIFT", true);
}
auto ::Parser::FlatTypes::RSHIFT::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::RSHIFT::to_string () const -> std::string{
	return ::ISPA_STD::concat("RSHIFT {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const RSHIFT &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::RPAREN::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("RPAREN", true);
}
auto ::Parser::FlatTypes::RPAREN::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::RPAREN::to_string () const -> std::string{
	return ::ISPA_STD::concat("RPAREN {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const RPAREN &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::RBRACKET::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("RBRACKET", true);
}
auto ::Parser::FlatTypes::RBRACKET::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::RBRACKET::to_string () const -> std::string{
	return ::ISPA_STD::concat("RBRACKET {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const RBRACKET &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::RBRACE::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("RBRACE", true);
}
auto ::Parser::FlatTypes::RBRACE::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::RBRACE::to_string () const -> std::string{
	return ::ISPA_STD::concat("RBRACE {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const RBRACE &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::POWER_ASSIGN::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("POWER_ASSIGN", true);
}
auto ::Parser::FlatTypes::POWER_ASSIGN::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::POWER_ASSIGN::to_string () const -> std::string{
	return ::ISPA_STD::concat("POWER_ASSIGN {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const POWER_ASSIGN &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::POWER::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("POWER", true);
}
auto ::Parser::FlatTypes::POWER::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::POWER::to_string () const -> std::string{
	return ::ISPA_STD::concat("POWER {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const POWER &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::PLUS_ASSIGN::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("PLUS_ASSIGN", true);
}
auto ::Parser::FlatTypes::PLUS_ASSIGN::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::PLUS_ASSIGN::to_string () const -> std::string{
	return ::ISPA_STD::concat("PLUS_ASSIGN {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const PLUS_ASSIGN &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::PLUS::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("PLUS", true);
}
auto ::Parser::FlatTypes::PLUS::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::PLUS::to_string () const -> std::string{
	return ::ISPA_STD::concat("PLUS {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const PLUS &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::PIPE_ASSIGN::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("PIPE_ASSIGN", true);
}
auto ::Parser::FlatTypes::PIPE_ASSIGN::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::PIPE_ASSIGN::to_string () const -> std::string{
	return ::ISPA_STD::concat("PIPE_ASSIGN {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const PIPE_ASSIGN &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::PIPE::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("PIPE", true);
}
auto ::Parser::FlatTypes::PIPE::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::PIPE::to_string () const -> std::string{
	return ::ISPA_STD::concat("PIPE {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const PIPE &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::NOT::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("NOT", true);
}
auto ::Parser::FlatTypes::NOT::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::NOT::to_string () const -> std::string{
	return ::ISPA_STD::concat("NOT {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const NOT &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::NE::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("NE", true);
}
auto ::Parser::FlatTypes::NE::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::NE::to_string () const -> std::string{
	return ::ISPA_STD::concat("NE {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const NE &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::LT::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("LT", true);
}
auto ::Parser::FlatTypes::LT::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::LT::to_string () const -> std::string{
	return ::ISPA_STD::concat("LT {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const LT &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::LPAREN::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("LPAREN", true);
}
auto ::Parser::FlatTypes::LPAREN::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::LPAREN::to_string () const -> std::string{
	return ::ISPA_STD::concat("LPAREN {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const LPAREN &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::LE::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("LE", true);
}
auto ::Parser::FlatTypes::LE::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::LE::to_string () const -> std::string{
	return ::ISPA_STD::concat("LE {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const LE &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::LBRACKET::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("LBRACKET", true);
}
auto ::Parser::FlatTypes::LBRACKET::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::LBRACKET::to_string () const -> std::string{
	return ::ISPA_STD::concat("LBRACKET {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const LBRACKET &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::GT::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("GT", true);
}
auto ::Parser::FlatTypes::GT::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::GT::to_string () const -> std::string{
	return ::ISPA_STD::concat("GT {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const GT &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::LSHIFT::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("LSHIFT", true);
}
auto ::Parser::FlatTypes::LSHIFT::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::LSHIFT::to_string () const -> std::string{
	return ::ISPA_STD::concat("LSHIFT {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const LSHIFT &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::GE::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("GE", true);
}
auto ::Parser::FlatTypes::GE::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::GE::to_string () const -> std::string{
	return ::ISPA_STD::concat("GE {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const GE &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::FLOOR_DIV_ASSIGN::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("FLOOR_DIV_ASSIGN", true);
}
auto ::Parser::FlatTypes::FLOOR_DIV_ASSIGN::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::FLOOR_DIV_ASSIGN::to_string () const -> std::string{
	return ::ISPA_STD::concat("FLOOR_DIV_ASSIGN {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const FLOOR_DIV_ASSIGN &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::FALSE::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("FALSE", true);
}
auto ::Parser::FlatTypes::FALSE::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::FALSE::to_string () const -> std::string{
	return ::ISPA_STD::concat("FALSE {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const FALSE &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::COMMA::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("COMMA", true);
}
auto ::Parser::FlatTypes::COMMA::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::COMMA::to_string () const -> std::string{
	return ::ISPA_STD::concat("COMMA {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const COMMA &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::NONE_V::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("NONE_V", true);
}
auto ::Parser::FlatTypes::NONE_V::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::NONE_V::to_string () const -> std::string{
	return ::ISPA_STD::concat("NONE_V {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const NONE_V &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::IS::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("IS", true);
}
auto ::Parser::FlatTypes::IS::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::IS::to_string () const -> std::string{
	return ::ISPA_STD::concat("IS {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const IS &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::COLON::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("COLON", true);
}
auto ::Parser::FlatTypes::COLON::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::COLON::to_string () const -> std::string{
	return ::ISPA_STD::concat("COLON {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const COLON &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::STAR_ASSIGN::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("STAR_ASSIGN", true);
}
auto ::Parser::FlatTypes::STAR_ASSIGN::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::STAR_ASSIGN::to_string () const -> std::string{
	return ::ISPA_STD::concat("STAR_ASSIGN {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const STAR_ASSIGN &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::CARET::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("CARET", true);
}
auto ::Parser::FlatTypes::CARET::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::CARET::to_string () const -> std::string{
	return ::ISPA_STD::concat("CARET {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const CARET &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::AND::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("AND", true);
}
auto ::Parser::FlatTypes::AND::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::AND::to_string () const -> std::string{
	return ::ISPA_STD::concat("AND {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const AND &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::STRING::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("STRING", false);
	printer.up(false);
	printer.node_with_value("value", value, true);
	printer.down();
}
auto ::Parser::FlatTypes::STRING::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::STRING::to_string () const -> std::string{
	return ::ISPA_STD::concat("STRING {", "value = ", value, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const STRING &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::EQ::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("EQ", true);
}
auto ::Parser::FlatTypes::EQ::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::EQ::to_string () const -> std::string{
	return ::ISPA_STD::concat("EQ {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const EQ &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::BREAK::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("BREAK", true);
}
auto ::Parser::FlatTypes::BREAK::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::BREAK::to_string () const -> std::string{
	return ::ISPA_STD::concat("BREAK {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const BREAK &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::PASS::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("PASS", true);
}
auto ::Parser::FlatTypes::PASS::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::PASS::to_string () const -> std::string{
	return ::ISPA_STD::concat("PASS {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const PASS &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::NUMBER::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("NUMBER", false);
	printer.up(false);
	printer.node_with_value("full", full, false);
	printer.node_with_value("floating", floating, true);
	printer.down();
}
auto ::Parser::FlatTypes::NUMBER::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::NUMBER::to_string () const -> std::string{
	return ::ISPA_STD::concat("NUMBER {", "full = ", full, ", ", "floating = ", floating, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const NUMBER &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::IF::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("IF", true);
}
auto ::Parser::FlatTypes::IF::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::IF::to_string () const -> std::string{
	return ::ISPA_STD::concat("IF {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const IF &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::MINUS_ASSIGN::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("MINUS_ASSIGN", true);
}
auto ::Parser::FlatTypes::MINUS_ASSIGN::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::MINUS_ASSIGN::to_string () const -> std::string{
	return ::ISPA_STD::concat("MINUS_ASSIGN {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const MINUS_ASSIGN &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::LSHIFT_ASSIGN::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("LSHIFT_ASSIGN", true);
}
auto ::Parser::FlatTypes::LSHIFT_ASSIGN::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::LSHIFT_ASSIGN::to_string () const -> std::string{
	return ::ISPA_STD::concat("LSHIFT_ASSIGN {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const LSHIFT_ASSIGN &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::ID::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("ID", false);
	printer.up(false);
	printer.node_with_value("value", value, true);
	printer.down();
}
auto ::Parser::FlatTypes::ID::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::ID::to_string () const -> std::string{
	return ::ISPA_STD::concat("ID {", "value = ", value, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const ID &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::PERCENT_ASSIGN::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("PERCENT_ASSIGN", true);
}
auto ::Parser::FlatTypes::PERCENT_ASSIGN::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::PERCENT_ASSIGN::to_string () const -> std::string{
	return ::ISPA_STD::concat("PERCENT_ASSIGN {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const PERCENT_ASSIGN &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::AMP::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("AMP", true);
}
auto ::Parser::FlatTypes::AMP::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::AMP::to_string () const -> std::string{
	return ::ISPA_STD::concat("AMP {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const AMP &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::TILDE::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("TILDE", true);
}
auto ::Parser::FlatTypes::TILDE::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::TILDE::to_string () const -> std::string{
	return ::ISPA_STD::concat("TILDE {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const TILDE &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::ELSE::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("ELSE", true);
}
auto ::Parser::FlatTypes::ELSE::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::ELSE::to_string () const -> std::string{
	return ::ISPA_STD::concat("ELSE {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const ELSE &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::DOT::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("DOT", true);
}
auto ::Parser::FlatTypes::DOT::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::DOT::to_string () const -> std::string{
	return ::ISPA_STD::concat("DOT {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const DOT &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::MINUS::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("MINUS", true);
}
auto ::Parser::FlatTypes::MINUS::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::MINUS::to_string () const -> std::string{
	return ::ISPA_STD::concat("MINUS {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const MINUS &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::PERCENT::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("PERCENT", true);
}
auto ::Parser::FlatTypes::PERCENT::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::PERCENT::to_string () const -> std::string{
	return ::ISPA_STD::concat("PERCENT {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const PERCENT &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::AMP_ASSIGN::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("AMP_ASSIGN", true);
}
auto ::Parser::FlatTypes::AMP_ASSIGN::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::AMP_ASSIGN::to_string () const -> std::string{
	return ::ISPA_STD::concat("AMP_ASSIGN {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const AMP_ASSIGN &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::TRUE::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("TRUE", true);
}
auto ::Parser::FlatTypes::TRUE::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::TRUE::to_string () const -> std::string{
	return ::ISPA_STD::concat("TRUE {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const TRUE &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::FLOOR_DIV::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("FLOOR_DIV", true);
}
auto ::Parser::FlatTypes::FLOOR_DIV::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::FLOOR_DIV::to_string () const -> std::string{
	return ::ISPA_STD::concat("FLOOR_DIV {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const FLOOR_DIV &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::OR::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("OR", true);
}
auto ::Parser::FlatTypes::OR::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::OR::to_string () const -> std::string{
	return ::ISPA_STD::concat("OR {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const OR &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::MATMUL::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("MATMUL", true);
}
auto ::Parser::FlatTypes::MATMUL::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::MATMUL::to_string () const -> std::string{
	return ::ISPA_STD::concat("MATMUL {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const MATMUL &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::CONTINUE::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("CONTINUE", true);
}
auto ::Parser::FlatTypes::CONTINUE::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::CONTINUE::to_string () const -> std::string{
	return ::ISPA_STD::concat("CONTINUE {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const CONTINUE &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::RETURN::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("RETURN", true);
}
auto ::Parser::FlatTypes::RETURN::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::RETURN::to_string () const -> std::string{
	return ::ISPA_STD::concat("RETURN {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const RETURN &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::CARET_ASSIGN::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("CARET_ASSIGN", true);
}
auto ::Parser::FlatTypes::CARET_ASSIGN::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::CARET_ASSIGN::to_string () const -> std::string{
	return ::ISPA_STD::concat("CARET_ASSIGN {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const CARET_ASSIGN &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::IN::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("IN", true);
}
auto ::Parser::FlatTypes::IN::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::IN::to_string () const -> std::string{
	return ::ISPA_STD::concat("IN {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const IN &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::LBRACE::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("LBRACE", true);
}
auto ::Parser::FlatTypes::LBRACE::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::LBRACE::to_string () const -> std::string{
	return ::ISPA_STD::concat("LBRACE {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const LBRACE &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::ASSIGN::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("ASSIGN", true);
}
auto ::Parser::FlatTypes::ASSIGN::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::ASSIGN::to_string () const -> std::string{
	return ::ISPA_STD::concat("ASSIGN {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const ASSIGN &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::conjunction::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("conjunction", false);
	printer.up(false);
	printer.node("first", false);
	printer.up(true);
	first.print(printer);
	printer.down();
	printer.subtree("rest", rest, true);
	printer.down();
}
auto ::Parser::FlatTypes::conjunction::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::conjunction::to_string () const -> std::string{
	return ::ISPA_STD::concat("conjunction {", "first = ", first.to_string(), ", ", "rest = ", rest, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const conjunction &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::parenthesized_expr::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("parenthesized_expr", false);
	printer.up(false);
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto ::Parser::FlatTypes::parenthesized_expr::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::parenthesized_expr::to_string () const -> std::string{
	return ::ISPA_STD::concat("parenthesized_expr {", "value = ", value.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const parenthesized_expr &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::expr_list_tail::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("expr_list_tail", false);
	printer.up(false);
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto ::Parser::FlatTypes::expr_list_tail::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::expr_list_tail::to_string () const -> std::string{
	return ::ISPA_STD::concat("expr_list_tail {", "value = ", value.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const expr_list_tail &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::bitwise_xor::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("bitwise_xor", false);
	printer.up(false);
	printer.node("first", false);
	printer.up(true);
	first.print(printer);
	printer.down();
	printer.subtree("rest", rest, true);
	printer.down();
}
auto ::Parser::FlatTypes::bitwise_xor::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::bitwise_xor::to_string () const -> std::string{
	return ::ISPA_STD::concat("bitwise_xor {", "first = ", first.to_string(), ", ", "rest = ", rest, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const bitwise_xor &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::dict_item::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
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
auto ::Parser::FlatTypes::dict_item::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::dict_item::to_string () const -> std::string{
	return ::ISPA_STD::concat("dict_item {", "key = ", key.to_string(), ", ", "value = ", value.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const dict_item &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::term::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("term", false);
	printer.up(false);
	printer.node("first", false);
	printer.up(true);
	first.print(printer);
	printer.down();
	printer.subtree("rest", rest, true);
	printer.down();
}
auto ::Parser::FlatTypes::term::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::term::to_string () const -> std::string{
	return ::ISPA_STD::concat("term {", "first = ", first.to_string(), ", ", "rest = ", rest, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const term &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::call_args::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("call_args", false);
	printer.up(false);
	printer.node("first", false);
	printer.up(true);
	first.print(printer);
	printer.down();
	printer.subtree("rest", rest, true);
	printer.down();
}
auto ::Parser::FlatTypes::call_args::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::call_args::to_string () const -> std::string{
	return ::ISPA_STD::concat("call_args {", "first = ", first.to_string(), ", ", "rest = ", rest, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const call_args &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::tuple_elements::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("tuple_elements", false);
	printer.up(false);
	printer.node("first", false);
	printer.up(true);
	first.print(printer);
	printer.down();
	printer.subtree("rest", rest, true);
	printer.down();
}
auto ::Parser::FlatTypes::tuple_elements::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::tuple_elements::to_string () const -> std::string{
	return ::ISPA_STD::concat("tuple_elements {", "first = ", first.to_string(), ", ", "rest = ", rest, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const tuple_elements &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::tuple_suffix::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("tuple_suffix", false);
	printer.up(false);
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto ::Parser::FlatTypes::tuple_suffix::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::tuple_suffix::to_string () const -> std::string{
	return ::ISPA_STD::concat("tuple_suffix {", "value = ", value.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const tuple_suffix &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::call_arg_tail::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("call_arg_tail", false);
	printer.up(false);
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto ::Parser::FlatTypes::call_arg_tail::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::call_arg_tail::to_string () const -> std::string{
	return ::ISPA_STD::concat("call_arg_tail {", "value = ", value.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const call_arg_tail &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::power::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
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
auto ::Parser::FlatTypes::power::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::power::to_string () const -> std::string{
	return ::ISPA_STD::concat("power {", "base = ", base.to_string(), ", ", "exponent = ", exponent.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const power &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::parenthesized_content::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
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
auto ::Parser::FlatTypes::parenthesized_content::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::parenthesized_content::to_string () const -> std::string{
	return ::ISPA_STD::concat("parenthesized_content {", "first = ", first.to_string(), ", ", "rest = ", rest.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const parenthesized_content &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::primary::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("primary", false);
	printer.up(false);
	printer.node("base", false);
	printer.up(true);
	base.print(printer);
	printer.down();
	printer.subtree("suffixes", suffixes, true);
	printer.down();
}
auto ::Parser::FlatTypes::primary::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::primary::to_string () const -> std::string{
	return ::ISPA_STD::concat("primary {", "base = ", base.to_string(), ", ", "suffixes = ", suffixes, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const primary &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::bitxor_tail::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("bitxor_tail", false);
	printer.up(false);
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto ::Parser::FlatTypes::bitxor_tail::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::bitxor_tail::to_string () const -> std::string{
	return ::ISPA_STD::concat("bitxor_tail {", "value = ", value.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const bitxor_tail &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::list_expr::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("list_expr", false);
	printer.up(false);
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto ::Parser::FlatTypes::list_expr::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::list_expr::to_string () const -> std::string{
	return ::ISPA_STD::concat("list_expr {", "value = ", value.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const list_expr &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::is_op::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("is_op", true);
}
auto ::Parser::FlatTypes::is_op::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::is_op::to_string () const -> std::string{
	return ::ISPA_STD::concat("is_op {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const is_op &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::dict_expr::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("dict_expr", false);
	printer.up(false);
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto ::Parser::FlatTypes::dict_expr::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::dict_expr::to_string () const -> std::string{
	return ::ISPA_STD::concat("dict_expr {", "value = ", value.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const dict_expr &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::call_suffix::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("call_suffix", false);
	printer.up(false);
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto ::Parser::FlatTypes::call_suffix::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::call_suffix::to_string () const -> std::string{
	return ::ISPA_STD::concat("call_suffix {", "value = ", value.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const call_suffix &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::shift_expr::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("shift_expr", false);
	printer.up(false);
	printer.node("first", false);
	printer.up(true);
	first.print(printer);
	printer.down();
	printer.subtree("rest", rest, true);
	printer.down();
}
auto ::Parser::FlatTypes::shift_expr::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::shift_expr::to_string () const -> std::string{
	return ::ISPA_STD::concat("shift_expr {", "first = ", first.to_string(), ", ", "rest = ", rest, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const shift_expr &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::power_tail::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("power_tail", false);
	printer.up(false);
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto ::Parser::FlatTypes::power_tail::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::power_tail::to_string () const -> std::string{
	return ::ISPA_STD::concat("power_tail {", "value = ", value.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const power_tail &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::inversion::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("inversion", false);
	printer.up(false);
	printer.node_with_value("value", value, true);
	printer.down();
}
auto ::Parser::FlatTypes::inversion::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::inversion::to_string () const -> std::string{
	return ::ISPA_STD::concat("inversion {", "value = ", value, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const inversion &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::sum::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("sum", false);
	printer.up(false);
	printer.node("first", false);
	printer.up(true);
	first.print(printer);
	printer.down();
	printer.subtree("rest", rest, true);
	printer.down();
}
auto ::Parser::FlatTypes::sum::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::sum::to_string () const -> std::string{
	return ::ISPA_STD::concat("sum {", "first = ", first.to_string(), ", ", "rest = ", rest, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const sum &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::index_suffix::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("index_suffix", false);
	printer.up(false);
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto ::Parser::FlatTypes::index_suffix::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::index_suffix::to_string () const -> std::string{
	return ::ISPA_STD::concat("index_suffix {", "value = ", value.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const index_suffix &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::factor::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("factor", false);
	printer.up(false);
	printer.node_with_value("value", value, true);
	printer.down();
}
auto ::Parser::FlatTypes::factor::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::factor::to_string () const -> std::string{
	return ::ISPA_STD::concat("factor {", "value = ", value, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const factor &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::expr_list::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
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
auto ::Parser::FlatTypes::expr_list::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::expr_list::to_string () const -> std::string{
	return ::ISPA_STD::concat("expr_list {", "first = ", first.to_string(), ", ", "rest = ", rest.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const expr_list &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::bitwise_and::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("bitwise_and", false);
	printer.up(false);
	printer.node("first", false);
	printer.up(true);
	first.print(printer);
	printer.down();
	printer.subtree("rest", rest, true);
	printer.down();
}
auto ::Parser::FlatTypes::bitwise_and::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::bitwise_and::to_string () const -> std::string{
	return ::ISPA_STD::concat("bitwise_and {", "first = ", first.to_string(), ", ", "rest = ", rest, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const bitwise_and &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::bitwise_or::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("bitwise_or", false);
	printer.up(false);
	printer.node("first", false);
	printer.up(true);
	first.print(printer);
	printer.down();
	printer.subtree("rest", rest, true);
	printer.down();
}
auto ::Parser::FlatTypes::bitwise_or::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::bitwise_or::to_string () const -> std::string{
	return ::ISPA_STD::concat("bitwise_or {", "first = ", first.to_string(), ", ", "rest = ", rest, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const bitwise_or &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::disjunction::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("disjunction", false);
	printer.up(false);
	printer.node("first", false);
	printer.up(true);
	first.print(printer);
	printer.down();
	printer.subtree("rest", rest, true);
	printer.down();
}
auto ::Parser::FlatTypes::disjunction::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::disjunction::to_string () const -> std::string{
	return ::ISPA_STD::concat("disjunction {", "first = ", first.to_string(), ", ", "rest = ", rest, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const disjunction &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::comparison::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("comparison", false);
	printer.up(false);
	printer.node("first", false);
	printer.up(true);
	first.print(printer);
	printer.down();
	printer.subtree("rest", rest, true);
	printer.down();
}
auto ::Parser::FlatTypes::comparison::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::comparison::to_string () const -> std::string{
	return ::ISPA_STD::concat("comparison {", "first = ", first.to_string(), ", ", "rest = ", rest, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const comparison &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::not_inversion::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("not_inversion", false);
	printer.up(false);
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto ::Parser::FlatTypes::not_inversion::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::not_inversion::to_string () const -> std::string{
	return ::ISPA_STD::concat("not_inversion {", "value = ", value.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const not_inversion &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::bitor_tail::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("bitor_tail", false);
	printer.up(false);
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto ::Parser::FlatTypes::bitor_tail::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::bitor_tail::to_string () const -> std::string{
	return ::ISPA_STD::concat("bitor_tail {", "value = ", value.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const bitor_tail &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::not_in::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("not_in", true);
}
auto ::Parser::FlatTypes::not_in::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::not_in::to_string () const -> std::string{
	return ::ISPA_STD::concat("not_in {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const not_in &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::dict_item_tail::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("dict_item_tail", false);
	printer.up(false);
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto ::Parser::FlatTypes::dict_item_tail::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::dict_item_tail::to_string () const -> std::string{
	return ::ISPA_STD::concat("dict_item_tail {", "value = ", value.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const dict_item_tail &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::bitand_tail::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("bitand_tail", false);
	printer.up(false);
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto ::Parser::FlatTypes::bitand_tail::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::bitand_tail::to_string () const -> std::string{
	return ::ISPA_STD::concat("bitand_tail {", "value = ", value.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const bitand_tail &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::conditional_tail::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
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
auto ::Parser::FlatTypes::conditional_tail::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::conditional_tail::to_string () const -> std::string{
	return ::ISPA_STD::concat("conditional_tail {", "condition = ", condition.to_string(), ", ", "otherwise = ", otherwise.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const conditional_tail &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::call_arg::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("call_arg", false);
	printer.up(false);
	printer.node_with_value("value", value, true);
	printer.down();
}
auto ::Parser::FlatTypes::call_arg::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::call_arg::to_string () const -> std::string{
	return ::ISPA_STD::concat("call_arg {", "value = ", value, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const call_arg &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::or_tail::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("or_tail", false);
	printer.up(false);
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto ::Parser::FlatTypes::or_tail::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::or_tail::to_string () const -> std::string{
	return ::ISPA_STD::concat("or_tail {", "value = ", value.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const or_tail &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::dict_items::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("dict_items", false);
	printer.up(false);
	printer.node("first", false);
	printer.up(true);
	first.print(printer);
	printer.down();
	printer.subtree("rest", rest, true);
	printer.down();
}
auto ::Parser::FlatTypes::dict_items::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::dict_items::to_string () const -> std::string{
	return ::ISPA_STD::concat("dict_items {", "first = ", first.to_string(), ", ", "rest = ", rest, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const dict_items &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::expr::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
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
auto ::Parser::FlatTypes::expr::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::expr::to_string () const -> std::string{
	return ::ISPA_STD::concat("expr {", "value = ", value.to_string(), ", ", "conditional = ", conditional.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const expr &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::shift_tail::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("shift_tail", false);
	printer.up(false);
	printer.node_with_value("op", op, false);
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto ::Parser::FlatTypes::shift_tail::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::shift_tail::to_string () const -> std::string{
	return ::ISPA_STD::concat("shift_tail {", "op = ", op, ", ", "value = ", value.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const shift_tail &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::keyword_arg::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
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
auto ::Parser::FlatTypes::keyword_arg::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::keyword_arg::to_string () const -> std::string{
	return ::ISPA_STD::concat("keyword_arg {", "name = ", name.to_string(), ", ", "value = ", value.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const keyword_arg &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::attribute_suffix::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("attribute_suffix", false);
	printer.up(false);
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto ::Parser::FlatTypes::attribute_suffix::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::attribute_suffix::to_string () const -> std::string{
	return ::ISPA_STD::concat("attribute_suffix {", "value = ", value.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const attribute_suffix &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::sum_tail::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("sum_tail", false);
	printer.up(false);
	printer.node_with_value("op", op, false);
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto ::Parser::FlatTypes::sum_tail::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::sum_tail::to_string () const -> std::string{
	return ::ISPA_STD::concat("sum_tail {", "op = ", op, ", ", "value = ", value.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const sum_tail &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::unary_expr::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("unary_expr", false);
	printer.up(false);
	printer.node_with_value("op", op, false);
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto ::Parser::FlatTypes::unary_expr::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::unary_expr::to_string () const -> std::string{
	return ::ISPA_STD::concat("unary_expr {", "op = ", op, ", ", "value = ", value.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const unary_expr &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::atom::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("atom", false);
	printer.up(false);
	printer.node_with_value("value", value, true);
	printer.down();
}
auto ::Parser::FlatTypes::atom::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::atom::to_string () const -> std::string{
	return ::ISPA_STD::concat("atom {", "value = ", value, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const atom &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::term_tail::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("term_tail", false);
	printer.up(false);
	printer.node_with_value("op", op, false);
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto ::Parser::FlatTypes::term_tail::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::term_tail::to_string () const -> std::string{
	return ::ISPA_STD::concat("term_tail {", "op = ", op, ", ", "value = ", value.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const term_tail &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::compare_op::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("compare_op", false);
	printer.up(false);
	printer.node_with_value("value", value, true);
	printer.down();
}
auto ::Parser::FlatTypes::compare_op::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::compare_op::to_string () const -> std::string{
	return ::ISPA_STD::concat("compare_op {", "value = ", value, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const compare_op &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::assignment_tail::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("assignment_tail", false);
	printer.up(false);
	printer.node_with_value("op", op, false);
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto ::Parser::FlatTypes::assignment_tail::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::assignment_tail::to_string () const -> std::string{
	return ::ISPA_STD::concat("assignment_tail {", "op = ", op, ", ", "value = ", value.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const assignment_tail &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::return_stmt::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("return_stmt", false);
	printer.up(false);
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto ::Parser::FlatTypes::return_stmt::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::return_stmt::to_string () const -> std::string{
	return ::ISPA_STD::concat("return_stmt {", "value = ", value.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const return_stmt &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::assignment_suffix::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("assignment_suffix", false);
	printer.up(false);
	printer.node_with_value("value", value, true);
	printer.down();
}
auto ::Parser::FlatTypes::assignment_suffix::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::assignment_suffix::to_string () const -> std::string{
	return ::ISPA_STD::concat("assignment_suffix {", "value = ", value, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const assignment_suffix &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::postfix::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("postfix", false);
	printer.up(false);
	printer.node_with_value("value", value, true);
	printer.down();
}
auto ::Parser::FlatTypes::postfix::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::postfix::to_string () const -> std::string{
	return ::ISPA_STD::concat("postfix {", "value = ", value, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const postfix &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::compare_tail::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
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
auto ::Parser::FlatTypes::compare_tail::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::compare_tail::to_string () const -> std::string{
	return ::ISPA_STD::concat("compare_tail {", "op = ", op.to_string(), ", ", "value = ", value.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const compare_tail &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::expr_stmt::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
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
auto ::Parser::FlatTypes::expr_stmt::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::expr_stmt::to_string () const -> std::string{
	return ::ISPA_STD::concat("expr_stmt {", "target = ", target.to_string(), ", ", "assignment = ", assignment.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const expr_stmt &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::assignment_target::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("assignment_target", false);
	printer.up(false);
	printer.node("name", false);
	printer.up(true);
	name.print(printer);
	printer.down();
	printer.subtree("suffixes", suffixes, true);
	printer.down();
}
auto ::Parser::FlatTypes::assignment_target::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::assignment_target::to_string () const -> std::string{
	return ::ISPA_STD::concat("assignment_target {", "name = ", name.to_string(), ", ", "suffixes = ", suffixes, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const assignment_target &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::stmt::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("stmt", false);
	printer.up(false);
	printer.node_with_value("value", value, true);
	printer.down();
}
auto ::Parser::FlatTypes::stmt::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::stmt::to_string () const -> std::string{
	return ::ISPA_STD::concat("stmt {", "value = ", value, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const stmt &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::main::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("main", false);
	printer.up(false);
	printer.subtree("value", value, true);
	printer.down();
}
auto ::Parser::FlatTypes::main::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::main::to_string () const -> std::string{
	return ::ISPA_STD::concat("main {", "value = ", value, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const main &value) -> std::ostream&{
	value.print(os);
	return os;
}
::ISPA_STD::DFA::API::CharToClass Parser::Lexer::char_class_table = {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 0, 0, 0, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 15, 0, 16, 17, 18, 0, 19, 20, 20, 20, 20, 20, 21, 20, 20, 20, 20, 20, 20, 20, 22, 20, 20, 20, 20, 20, 23, 20, 20, 20, 20, 20, 20, 24, 0, 25, 26, 27, 0, 28, 29, 30, 31, 32, 33, 20, 20, 34, 20, 35, 36, 20, 37, 38, 39, 20, 40, 41, 42, 43, 20, 20, 20, 20, 20, 44, 45, 46, 47, 0, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48};
::ISPA_STD::DFA::API::Table<105, 49> Parser::Lexer::dfa_table = {{{::ISPA_STD::DFA::API::null_state, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 117, 15, 16, 17, 18, 19, 105, 116, 106, 115, 24, 25, 26, ::ISPA_STD::DFA::API::null_state, 114, 113, 108, 105, 107, 105, 112, 105, 105, 118, 111, 110, 109, 105, 105, 105, 36, 37, 38, 39, ::ISPA_STD::DFA::API::null_state}, {204, 1, 204, 204, 204, 204, 204, 204, 204, 204, 204, 204, 204, 204, 204, 204, 204, 204, 204, 204, 204, 204, 204, 204, 204, 204, 204, 204, 204, 204, 204, 204, 204, 204, 204, 204, 204, 204, 204, 204, 204, 204, 204, 204, 204, 204, 204, 204, 204}, {::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, 40, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state}, {205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 41, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205}, {206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 42, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206}, {119, 119, 119, 119, 119, 44, 119, 119, 119, 119, 119, 119, 119, 119, 119, 119, 119, 119, 119, 119, 119, 119, 119, 119, 119, 119, 119, 119, 119, 119, 119, 119, 119, 119, 119, 119, 119, 119, 119, 119, 119, 119, 119, 119, 119, 119, 119, 119, ::ISPA_STD::DFA::API::null_state}, {207, 207, 207, 207, 207, 207, 207, 207, 207, 207, 207, 207, 207, 207, 207, 207, 207, 207, 207, 207, 207, 207, 207, 207, 207, 207, 207, 207, 207, 207, 207, 207, 207, 207, 207, 207, 207, 207, 207, 207, 207, 207, 207, 207, 207, 207, 207, 207, 207}, {208, 208, 208, 208, 208, 208, 208, 208, 208, 208, 208, 208, 208, 208, 208, 208, 208, 208, 208, 208, 208, 208, 208, 208, 208, 208, 208, 208, 208, 208, 208, 208, 208, 208, 208, 208, 208, 208, 208, 208, 208, 208, 208, 208, 208, 208, 208, 208, 208}, {209, 209, 209, 209, 209, 209, 209, 209, 45, 209, 209, 209, 209, 209, 209, 209, 209, 46, 209, 209, 209, 209, 209, 209, 209, 209, 209, 209, 209, 209, 209, 209, 209, 209, 209, 209, 209, 209, 209, 209, 209, 209, 209, 209, 209, 209, 209, 209, 209}, {210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 47, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210}, {211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211}, {212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 48, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212}, {213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213}, {214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 49, 214, 214, 214, 50, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214}, {120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 121, 120, 14, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120}, {216, 216, 216, 216, 216, 216, 216, 216, 216, 216, 216, 216, 216, 216, 216, 216, 216, 216, 216, 216, 216, 216, 216, 216, 216, 216, 216, 216, 216, 216, 216, 216, 216, 216, 216, 216, 216, 216, 216, 216, 216, 216, 216, 216, 216, 216, 216, 216, 216}, {217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 52, 53, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217}, {218, 218, 218, 218, 218, 218, 218, 218, 218, 218, 218, 218, 218, 218, 218, 218, 218, 54, 218, 218, 218, 218, 218, 218, 218, 218, 218, 218, 218, 218, 218, 218, 218, 218, 218, 218, 218, 218, 218, 218, 218, 218, 218, 218, 218, 218, 218, 218, 218}, {219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 55, 56, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219}, {220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220}, {122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 57, 122, 122, 122, 122, 122, 57, 57, 57, 57, 122, 122, 122, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 122, 122, 122, 122, 122}, {124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 125, 124, 124, 124, 124, 124, 125, 125, 125, 125, 124, 124, 124, 125, 58, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 124, 124, 124, 124, 124}, {127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 125, 127, 127, 127, 127, 127, 125, 125, 125, 125, 127, 127, 127, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 59, 125, 125, 125, 125, 125, 127, 127, 127, 127, 127}, {129, 129, 129, 129, 129, 129, 129, 129, 129, 129, 129, 129, 129, 129, 125, 129, 129, 129, 129, 129, 125, 125, 125, 125, 129, 129, 129, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 60, 125, 125, 125, 129, 129, 129, 129, 129}, {222, 222, 222, 222, 222, 222, 222, 222, 222, 222, 222, 222, 222, 222, 222, 222, 222, 222, 222, 222, 222, 222, 222, 222, 222, 222, 222, 222, 222, 222, 222, 222, 222, 222, 222, 222, 222, 222, 222, 222, 222, 222, 222, 222, 222, 222, 222, 222, 222}, {223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223}, {224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 61, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224}, {131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 125, 131, 131, 131, 131, 131, 125, 125, 125, 125, 131, 131, 131, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 62, 125, 125, 125, 125, 125, 125, 131, 131, 131, 131, 131}, {133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 125, 133, 133, 133, 133, 133, 125, 125, 125, 125, 133, 133, 133, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 63, 125, 125, 125, 133, 133, 133, 133, 133}, {135, 135, 135, 135, 135, 135, 135, 135, 135, 135, 135, 135, 135, 135, 125, 135, 135, 135, 135, 135, 125, 125, 125, 125, 135, 135, 135, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 64, 125, 125, 125, 125, 125, 135, 135, 135, 135, 135}, {137, 137, 137, 137, 137, 137, 137, 137, 137, 137, 137, 137, 137, 137, 125, 137, 137, 137, 137, 137, 125, 125, 125, 125, 137, 137, 137, 125, 125, 125, 125, 125, 125, 125, 125, 125, 65, 125, 125, 125, 125, 125, 125, 125, 137, 137, 137, 137, 137}, {139, 139, 139, 139, 139, 139, 139, 139, 139, 139, 139, 139, 139, 139, 125, 139, 139, 139, 139, 139, 125, 125, 125, 125, 139, 139, 139, 125, 125, 125, 125, 125, 125, 66, 125, 125, 125, 67, 125, 125, 125, 68, 125, 125, 139, 139, 139, 139, 139}, {141, 141, 141, 141, 141, 141, 141, 141, 141, 141, 141, 141, 141, 141, 125, 141, 141, 141, 141, 141, 125, 125, 125, 125, 141, 141, 141, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 69, 125, 125, 125, 125, 125, 141, 141, 141, 141, 141}, {143, 143, 143, 143, 143, 143, 143, 143, 143, 143, 143, 143, 143, 143, 125, 143, 143, 143, 143, 143, 125, 125, 125, 125, 143, 143, 143, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 70, 125, 125, 125, 143, 143, 143, 143, 143}, {145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 125, 145, 145, 145, 145, 145, 125, 125, 125, 125, 145, 145, 145, 125, 71, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 145, 145, 145, 145, 145}, {147, 147, 147, 147, 147, 147, 147, 147, 147, 147, 147, 147, 147, 147, 125, 147, 147, 147, 147, 147, 125, 125, 125, 125, 147, 147, 147, 125, 125, 125, 125, 125, 72, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 147, 147, 147, 147, 147}, {225, 225, 225, 225, 225, 225, 225, 225, 225, 225, 225, 225, 225, 225, 225, 225, 225, 225, 225, 225, 225, 225, 225, 225, 225, 225, 225, 225, 225, 225, 225, 225, 225, 225, 225, 225, 225, 225, 225, 225, 225, 225, 225, 225, 225, 225, 225, 225, 225}, {226, 226, 226, 226, 226, 226, 226, 226, 226, 226, 226, 226, 226, 226, 226, 226, 226, 73, 226, 226, 226, 226, 226, 226, 226, 226, 226, 226, 226, 226, 226, 226, 226, 226, 226, 226, 226, 226, 226, 226, 226, 226, 226, 226, 226, 226, 226, 226, 226}, {227, 227, 227, 227, 227, 227, 227, 227, 227, 227, 227, 227, 227, 227, 227, 227, 227, 227, 227, 227, 227, 227, 227, 227, 227, 227, 227, 227, 227, 227, 227, 227, 227, 227, 227, 227, 227, 227, 227, 227, 227, 227, 227, 227, 227, 227, 227, 227, 227}, {228, 228, 228, 228, 228, 228, 228, 228, 228, 228, 228, 228, 228, 228, 228, 228, 228, 228, 228, 228, 228, 228, 228, 228, 228, 228, 228, 228, 228, 228, 228, 228, 228, 228, 228, 228, 228, 228, 228, 228, 228, 228, 228, 228, 228, 228, 228, 228, 228}, {229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229}, {230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230}, {231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231}, {43, 43, 43, 43, 43, 148, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, ::ISPA_STD::DFA::API::null_state}, {232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232}, {233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 74, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233}, {234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234}, {235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235, 235}, {236, 236, 236, 236, 236, 236, 236, 236, 236, 236, 236, 236, 236, 236, 236, 236, 236, 236, 236, 236, 236, 236, 236, 236, 236, 236, 236, 236, 236, 236, 236, 236, 236, 236, 236, 236, 236, 236, 236, 236, 236, 236, 236, 236, 236, 236, 236, 236, 236}, {237, 237, 237, 237, 237, 237, 237, 237, 237, 237, 237, 237, 237, 237, 237, 237, 237, 75, 237, 237, 237, 237, 237, 237, 237, 237, 237, 237, 237, 237, 237, 237, 237, 237, 237, 237, 237, 237, 237, 237, 237, 237, 237, 237, 237, 237, 237, 237, 237}, {238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238}, {::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, 149, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state}, {239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 77, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239}, {240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240}, {241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241}, {242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242}, {243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 78, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243}, {150, 150, 150, 150, 150, 150, 150, 150, 150, 150, 150, 150, 150, 150, 57, 150, 150, 150, 150, 150, 57, 57, 57, 57, 150, 150, 150, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 150, 150, 150, 150, 150}, {152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 125, 152, 152, 152, 152, 152, 125, 125, 125, 125, 152, 152, 152, 125, 125, 125, 125, 125, 125, 125, 125, 125, 79, 125, 125, 125, 125, 125, 125, 125, 152, 152, 152, 152, 152}, {154, 154, 154, 154, 154, 154, 154, 154, 154, 154, 154, 154, 154, 154, 125, 154, 154, 154, 154, 154, 125, 125, 125, 125, 154, 154, 154, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 80, 125, 125, 125, 125, 125, 125, 154, 154, 154, 154, 154}, {156, 156, 156, 156, 156, 156, 156, 156, 156, 156, 156, 156, 156, 156, 125, 156, 156, 156, 156, 156, 125, 125, 125, 125, 156, 156, 156, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 81, 156, 156, 156, 156, 156}, {245, 245, 245, 245, 245, 245, 245, 245, 245, 245, 245, 245, 245, 245, 245, 245, 245, 245, 245, 245, 245, 245, 245, 245, 245, 245, 245, 245, 245, 245, 245, 245, 245, 245, 245, 245, 245, 245, 245, 245, 245, 245, 245, 245, 245, 245, 245, 245, 245}, {158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 125, 158, 158, 158, 158, 158, 125, 125, 125, 125, 158, 158, 158, 125, 125, 125, 125, 82, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 158, 158, 158, 158, 158}, {160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 125, 160, 160, 160, 160, 160, 125, 125, 125, 125, 160, 160, 160, 125, 125, 125, 125, 125, 83, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 160, 160, 160, 160, 160}, {162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 125, 162, 162, 162, 162, 162, 125, 125, 125, 125, 162, 162, 162, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 84, 125, 125, 125, 125, 125, 125, 162, 162, 162, 162, 162}, {164, 164, 164, 164, 164, 164, 164, 164, 164, 164, 164, 164, 164, 164, 125, 164, 164, 164, 164, 164, 125, 125, 125, 125, 164, 164, 164, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 85, 125, 125, 164, 164, 164, 164, 164}, {246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 125, 246, 246, 246, 246, 246, 125, 125, 125, 125, 246, 246, 246, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 246, 246, 246, 246, 246}, {247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 125, 247, 247, 247, 247, 247, 125, 125, 125, 125, 247, 247, 247, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 247, 247, 247, 247, 247}, {248, 248, 248, 248, 248, 248, 248, 248, 248, 248, 248, 248, 248, 248, 125, 248, 248, 248, 248, 248, 125, 125, 125, 125, 248, 248, 248, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 248, 248, 248, 248, 248}, {166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 125, 166, 166, 166, 166, 166, 125, 125, 125, 125, 166, 166, 166, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 86, 125, 166, 166, 166, 166, 166}, {249, 249, 249, 249, 249, 249, 249, 249, 249, 249, 249, 249, 249, 249, 125, 249, 249, 249, 249, 249, 125, 125, 125, 125, 249, 249, 249, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 249, 249, 249, 249, 249}, {168, 168, 168, 168, 168, 168, 168, 168, 168, 168, 168, 168, 168, 168, 125, 168, 168, 168, 168, 168, 125, 125, 125, 125, 168, 168, 168, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 87, 125, 125, 168, 168, 168, 168, 168}, {170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 125, 170, 170, 170, 170, 170, 125, 125, 125, 125, 170, 170, 170, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 88, 125, 170, 170, 170, 170, 170}, {250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250}, {251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251}, {252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252}, {171, 171, 171, 171, 171, 171, 171, 171, 171, 171, 171, 171, 171, 171, 76, 171, 171, 171, 171, 171, 171, 171, 171, 171, 171, 171, 171, 171, 171, 171, 171, 171, 171, 171, 171, 171, 171, 171, 171, 171, 171, 171, 171, 171, 171, 171, 171, 171, 171}, {254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254}, {255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255}, {173, 173, 173, 173, 173, 173, 173, 173, 173, 173, 173, 173, 173, 173, 125, 173, 173, 173, 173, 173, 125, 125, 125, 125, 173, 173, 173, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 89, 125, 125, 173, 173, 173, 173, 173}, {175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 125, 175, 175, 175, 175, 175, 125, 125, 125, 125, 175, 175, 175, 125, 125, 125, 125, 125, 90, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 175, 175, 175, 175, 175}, {177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 125, 177, 177, 177, 177, 177, 125, 125, 125, 125, 177, 177, 177, 125, 125, 125, 125, 125, 91, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 177, 177, 177, 177, 177}, {256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 125, 256, 256, 256, 256, 256, 125, 125, 125, 125, 256, 256, 256, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 256, 256, 256, 256, 256}, {179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 125, 179, 179, 179, 179, 179, 125, 125, 125, 125, 179, 179, 179, 125, 92, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 179, 179, 179, 179, 179}, {181, 181, 181, 181, 181, 181, 181, 181, 181, 181, 181, 181, 181, 181, 125, 181, 181, 181, 181, 181, 125, 125, 125, 125, 181, 181, 181, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 93, 125, 181, 181, 181, 181, 181}, {183, 183, 183, 183, 183, 183, 183, 183, 183, 183, 183, 183, 183, 183, 125, 183, 183, 183, 183, 183, 125, 125, 125, 125, 183, 183, 183, 125, 125, 125, 125, 125, 94, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 183, 183, 183, 183, 183}, {257, 257, 257, 257, 257, 257, 257, 257, 257, 257, 257, 257, 257, 257, 125, 257, 257, 257, 257, 257, 125, 125, 125, 125, 257, 257, 257, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 257, 257, 257, 257, 257}, {185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 125, 185, 185, 185, 185, 185, 125, 125, 125, 125, 185, 185, 185, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 95, 125, 125, 185, 185, 185, 185, 185}, {187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 125, 187, 187, 187, 187, 187, 125, 125, 125, 125, 187, 187, 187, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 96, 187, 187, 187, 187, 187}, {189, 189, 189, 189, 189, 189, 189, 189, 189, 189, 189, 189, 189, 189, 125, 189, 189, 189, 189, 189, 125, 125, 125, 125, 189, 189, 189, 125, 125, 125, 125, 125, 97, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 189, 189, 189, 189, 189}, {258, 258, 258, 258, 258, 258, 258, 258, 258, 258, 258, 258, 258, 258, 125, 258, 258, 258, 258, 258, 125, 125, 125, 125, 258, 258, 258, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 258, 258, 258, 258, 258}, {259, 259, 259, 259, 259, 259, 259, 259, 259, 259, 259, 259, 259, 259, 125, 259, 259, 259, 259, 259, 125, 125, 125, 125, 259, 259, 259, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 259, 259, 259, 259, 259}, {191, 191, 191, 191, 191, 191, 191, 191, 191, 191, 191, 191, 191, 191, 125, 191, 191, 191, 191, 191, 125, 125, 125, 125, 191, 191, 191, 125, 125, 125, 125, 125, 125, 125, 125, 98, 125, 125, 125, 125, 125, 125, 125, 125, 191, 191, 191, 191, 191}, {193, 193, 193, 193, 193, 193, 193, 193, 193, 193, 193, 193, 193, 193, 125, 193, 193, 193, 193, 193, 125, 125, 125, 125, 193, 193, 193, 125, 125, 125, 125, 125, 125, 125, 99, 125, 125, 125, 125, 125, 125, 125, 125, 125, 193, 193, 193, 193, 193}, {260, 260, 260, 260, 260, 260, 260, 260, 260, 260, 260, 260, 260, 260, 125, 260, 260, 260, 260, 260, 125, 125, 125, 125, 260, 260, 260, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 260, 260, 260, 260, 260}, {261, 261, 261, 261, 261, 261, 261, 261, 261, 261, 261, 261, 261, 261, 125, 261, 261, 261, 261, 261, 125, 125, 125, 125, 261, 261, 261, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 261, 261, 261, 261, 261}, {195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 125, 195, 195, 195, 195, 195, 125, 125, 125, 125, 195, 195, 195, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 100, 125, 125, 125, 195, 195, 195, 195, 195}, {262, 262, 262, 262, 262, 262, 262, 262, 262, 262, 262, 262, 262, 262, 125, 262, 262, 262, 262, 262, 125, 125, 125, 125, 262, 262, 262, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 262, 262, 262, 262, 262}, {263, 263, 263, 263, 263, 263, 263, 263, 263, 263, 263, 263, 263, 263, 125, 263, 263, 263, 263, 263, 125, 125, 125, 125, 263, 263, 263, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 263, 263, 263, 263, 263}, {197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 125, 197, 197, 197, 197, 197, 125, 125, 125, 125, 197, 197, 197, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 101, 125, 125, 125, 125, 125, 125, 197, 197, 197, 197, 197}, {199, 199, 199, 199, 199, 199, 199, 199, 199, 199, 199, 199, 199, 199, 125, 199, 199, 199, 199, 199, 125, 125, 125, 125, 199, 199, 199, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 102, 125, 125, 125, 125, 125, 125, 199, 199, 199, 199, 199}, {201, 201, 201, 201, 201, 201, 201, 201, 201, 201, 201, 201, 201, 201, 125, 201, 201, 201, 201, 201, 125, 125, 125, 125, 201, 201, 201, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 103, 201, 201, 201, 201, 201}, {264, 264, 264, 264, 264, 264, 264, 264, 264, 264, 264, 264, 264, 264, 125, 264, 264, 264, 264, 264, 125, 125, 125, 125, 264, 264, 264, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 264, 264, 264, 264, 264}, {203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 125, 203, 203, 203, 203, 203, 125, 125, 125, 125, 203, 203, 203, 125, 125, 125, 125, 125, 104, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 203, 203, 203, 203, 203}, {265, 265, 265, 265, 265, 265, 265, 265, 265, 265, 265, 265, 265, 265, 125, 265, 265, 265, 265, 265, 125, 125, 125, 125, 265, 265, 265, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 265, 265, 265, 265, 265}}};
::ISPA_STD::DFA::API::Table<99, 4> Parser::Lexer::action_table = {{{1, 0, ::ISPA_STD::DFA::API::null_state, 20}, {1, 8, ::ISPA_STD::DFA::API::null_state, 22}, {1, 8, ::ISPA_STD::DFA::API::null_state, 30}, {1, 8, ::ISPA_STD::DFA::API::null_state, 29}, {1, 8, ::ISPA_STD::DFA::API::null_state, 35}, {1, 8, ::ISPA_STD::DFA::API::null_state, 34}, {1, 8, ::ISPA_STD::DFA::API::null_state, 33}, {1, 8, ::ISPA_STD::DFA::API::null_state, 31}, {1, 8, ::ISPA_STD::DFA::API::null_state, 28}, {1, 8, ::ISPA_STD::DFA::API::null_state, 27}, {1, 8, ::ISPA_STD::DFA::API::null_state, 23}, {1, 8, ::ISPA_STD::DFA::API::null_state, 21}, {1, 2, ::ISPA_STD::DFA::API::null_state, 14}, {1, 8, ::ISPA_STD::DFA::API::null_state, 32}, {1, 6, ::ISPA_STD::DFA::API::null_state, 43}, {1, 3, ::ISPA_STD::DFA::API::null_state, 215}, {1, 3, ::ISPA_STD::DFA::API::null_state, 51}, {1, 1, ::ISPA_STD::DFA::API::null_state, 221}, {3, 0, 8, 221}, {1, 1, ::ISPA_STD::DFA::API::null_state, 123}, {3, 0, 8, 57}, {3, 0, 8, 221}, {1, 1, ::ISPA_STD::DFA::API::null_state, 126}, {3, 0, 8, 221}, {1, 1, ::ISPA_STD::DFA::API::null_state, 128}, {3, 0, 8, 221}, {1, 1, ::ISPA_STD::DFA::API::null_state, 130}, {3, 0, 8, 221}, {1, 1, ::ISPA_STD::DFA::API::null_state, 132}, {3, 0, 8, 221}, {1, 1, ::ISPA_STD::DFA::API::null_state, 134}, {3, 0, 8, 221}, {1, 1, ::ISPA_STD::DFA::API::null_state, 136}, {3, 0, 8, 221}, {1, 1, ::ISPA_STD::DFA::API::null_state, 138}, {3, 0, 8, 221}, {1, 1, ::ISPA_STD::DFA::API::null_state, 140}, {3, 0, 8, 221}, {1, 1, ::ISPA_STD::DFA::API::null_state, 142}, {3, 0, 8, 221}, {1, 1, ::ISPA_STD::DFA::API::null_state, 144}, {3, 0, 8, 221}, {1, 1, ::ISPA_STD::DFA::API::null_state, 146}, {1, 7, ::ISPA_STD::DFA::API::null_state, 44}, {1, 4, ::ISPA_STD::DFA::API::null_state, 76}, {1, 1, ::ISPA_STD::DFA::API::null_state, 244}, {3, 0, 8, 244}, {1, 1, ::ISPA_STD::DFA::API::null_state, 151}, {3, 0, 8, 244}, {1, 1, ::ISPA_STD::DFA::API::null_state, 153}, {3, 0, 8, 244}, {1, 1, ::ISPA_STD::DFA::API::null_state, 155}, {3, 0, 8, 244}, {1, 1, ::ISPA_STD::DFA::API::null_state, 157}, {3, 0, 8, 244}, {1, 1, ::ISPA_STD::DFA::API::null_state, 159}, {3, 0, 8, 244}, {1, 1, ::ISPA_STD::DFA::API::null_state, 161}, {3, 0, 8, 244}, {1, 1, ::ISPA_STD::DFA::API::null_state, 163}, {3, 0, 8, 244}, {1, 1, ::ISPA_STD::DFA::API::null_state, 165}, {3, 0, 8, 244}, {1, 1, ::ISPA_STD::DFA::API::null_state, 167}, {3, 0, 8, 244}, {1, 1, ::ISPA_STD::DFA::API::null_state, 169}, {1, 5, ::ISPA_STD::DFA::API::null_state, 253}, {3, 0, 8, 244}, {1, 1, ::ISPA_STD::DFA::API::null_state, 172}, {3, 0, 8, 244}, {1, 1, ::ISPA_STD::DFA::API::null_state, 174}, {3, 0, 8, 244}, {1, 1, ::ISPA_STD::DFA::API::null_state, 176}, {3, 0, 8, 244}, {1, 1, ::ISPA_STD::DFA::API::null_state, 178}, {3, 0, 8, 244}, {1, 1, ::ISPA_STD::DFA::API::null_state, 180}, {3, 0, 8, 244}, {1, 1, ::ISPA_STD::DFA::API::null_state, 182}, {3, 0, 8, 244}, {1, 1, ::ISPA_STD::DFA::API::null_state, 184}, {3, 0, 8, 244}, {1, 1, ::ISPA_STD::DFA::API::null_state, 186}, {3, 0, 8, 244}, {1, 1, ::ISPA_STD::DFA::API::null_state, 188}, {3, 0, 8, 244}, {1, 1, ::ISPA_STD::DFA::API::null_state, 190}, {3, 0, 8, 244}, {1, 1, ::ISPA_STD::DFA::API::null_state, 192}, {3, 0, 8, 244}, {1, 1, ::ISPA_STD::DFA::API::null_state, 194}, {3, 0, 8, 244}, {1, 1, ::ISPA_STD::DFA::API::null_state, 196}, {3, 0, 8, 244}, {1, 1, ::ISPA_STD::DFA::API::null_state, 198}, {3, 0, 8, 244}, {1, 1, ::ISPA_STD::DFA::API::null_state, 200}, {3, 0, 8, 244}, {1, 1, ::ISPA_STD::DFA::API::null_state, 202}}};
auto ::Parser::Lexer::semantic_action_exec (long long state, const ::ISPA_STD::DFA::API::Captures& captures, long long start_pos, const char* start, long long length, long long line) -> std::pair<long long, Token>{
	switch (state) {
		case 0: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, ::ISPA_STD::Node<::Parser::Tokens, Types::__WS>::create(start_pos, start, length, line, Tokens::__WS, Types::__WS{}));
			break;
		}
		case 1: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, ::ISPA_STD::Node<::Parser::Tokens, Types::PERCENT>::create(start_pos, start, length, line, Tokens::PERCENT, Types::PERCENT{}));
			break;
		}
		case 2: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, ::ISPA_STD::Node<::Parser::Tokens, Types::AMP>::create(start_pos, start, length, line, Tokens::AMP, Types::AMP{}));
			break;
		}
		case 3: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, ::ISPA_STD::Node<::Parser::Tokens, Types::LPAREN>::create(start_pos, start, length, line, Tokens::LPAREN, Types::LPAREN{}));
			break;
		}
		case 4: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, ::ISPA_STD::Node<::Parser::Tokens, Types::RPAREN>::create(start_pos, start, length, line, Tokens::RPAREN, Types::RPAREN{}));
			break;
		}
		case 5: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, ::ISPA_STD::Node<::Parser::Tokens, Types::STAR>::create(start_pos, start, length, line, Tokens::STAR, Types::STAR{}));
			break;
		}
		case 6: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, ::ISPA_STD::Node<::Parser::Tokens, Types::PLUS>::create(start_pos, start, length, line, Tokens::PLUS, Types::PLUS{}));
			break;
		}
		case 7: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, ::ISPA_STD::Node<::Parser::Tokens, Types::COMMA>::create(start_pos, start, length, line, Tokens::COMMA, Types::COMMA{}));
			break;
		}
		case 8: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, ::ISPA_STD::Node<::Parser::Tokens, Types::MINUS>::create(start_pos, start, length, line, Tokens::MINUS, Types::MINUS{}));
			break;
		}
		case 9: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, ::ISPA_STD::Node<::Parser::Tokens, Types::DOT>::create(start_pos, start, length, line, Tokens::DOT, Types::DOT{}));
			break;
		}
		case 10: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, ::ISPA_STD::Node<::Parser::Tokens, Types::SLASH>::create(start_pos, start, length, line, Tokens::SLASH, Types::SLASH{}));
			break;
		}
		case 11: {
			std::string floating = captures.text(2);
			std::string full = captures.text(1);
			return std::make_pair(::ISPA_STD::DFA::API::null_state, ::ISPA_STD::Node<::Parser::Tokens, Types::NUMBER>::create(start_pos, start, length, line, Tokens::NUMBER, Types::NUMBER{full, floating}));
			break;
		}
		case 12: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, ::ISPA_STD::Node<::Parser::Tokens, Types::COLON>::create(start_pos, start, length, line, Tokens::COLON, Types::COLON{}));
			break;
		}
		case 13: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, ::ISPA_STD::Node<::Parser::Tokens, Types::LT>::create(start_pos, start, length, line, Tokens::LT, Types::LT{}));
			break;
		}
		case 14: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, ::ISPA_STD::Node<::Parser::Tokens, Types::ASSIGN>::create(start_pos, start, length, line, Tokens::ASSIGN, Types::ASSIGN{}));
			break;
		}
		case 15: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, ::ISPA_STD::Node<::Parser::Tokens, Types::GT>::create(start_pos, start, length, line, Tokens::GT, Types::GT{}));
			break;
		}
		case 16: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, ::ISPA_STD::Node<::Parser::Tokens, Types::MATMUL>::create(start_pos, start, length, line, Tokens::MATMUL, Types::MATMUL{}));
			break;
		}
		case 17: {
			std::string value = captures.text(0);
			return std::make_pair(::ISPA_STD::DFA::API::null_state, ::ISPA_STD::Node<::Parser::Tokens, Types::ID>::create(start_pos, start, length, line, Tokens::ID, Types::ID{value}));
			break;
		}
		case 18: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, ::ISPA_STD::Node<::Parser::Tokens, Types::LBRACKET>::create(start_pos, start, length, line, Tokens::LBRACKET, Types::LBRACKET{}));
			break;
		}
		case 19: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, ::ISPA_STD::Node<::Parser::Tokens, Types::RBRACKET>::create(start_pos, start, length, line, Tokens::RBRACKET, Types::RBRACKET{}));
			break;
		}
		case 20: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, ::ISPA_STD::Node<::Parser::Tokens, Types::CARET>::create(start_pos, start, length, line, Tokens::CARET, Types::CARET{}));
			break;
		}
		case 21: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, ::ISPA_STD::Node<::Parser::Tokens, Types::LBRACE>::create(start_pos, start, length, line, Tokens::LBRACE, Types::LBRACE{}));
			break;
		}
		case 22: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, ::ISPA_STD::Node<::Parser::Tokens, Types::PIPE>::create(start_pos, start, length, line, Tokens::PIPE, Types::PIPE{}));
			break;
		}
		case 23: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, ::ISPA_STD::Node<::Parser::Tokens, Types::RBRACE>::create(start_pos, start, length, line, Tokens::RBRACE, Types::RBRACE{}));
			break;
		}
		case 24: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, ::ISPA_STD::Node<::Parser::Tokens, Types::TILDE>::create(start_pos, start, length, line, Tokens::TILDE, Types::TILDE{}));
			break;
		}
		case 25: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, ::ISPA_STD::Node<::Parser::Tokens, Types::NE>::create(start_pos, start, length, line, Tokens::NE, Types::NE{}));
			break;
		}
		case 26: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, ::ISPA_STD::Node<::Parser::Tokens, Types::PERCENT_ASSIGN>::create(start_pos, start, length, line, Tokens::PERCENT_ASSIGN, Types::PERCENT_ASSIGN{}));
			break;
		}
		case 27: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, ::ISPA_STD::Node<::Parser::Tokens, Types::AMP_ASSIGN>::create(start_pos, start, length, line, Tokens::AMP_ASSIGN, Types::AMP_ASSIGN{}));
			break;
		}
		case 28: {
			std::string value = captures.text(3);
			return std::make_pair(::ISPA_STD::DFA::API::null_state, ::ISPA_STD::Node<::Parser::Tokens, Types::STRING>::create(start_pos, start, length, line, Tokens::STRING, Types::STRING{value}));
			break;
		}
		case 29: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, ::ISPA_STD::Node<::Parser::Tokens, Types::POWER>::create(start_pos, start, length, line, Tokens::POWER, Types::POWER{}));
			break;
		}
		case 30: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, ::ISPA_STD::Node<::Parser::Tokens, Types::STAR_ASSIGN>::create(start_pos, start, length, line, Tokens::STAR_ASSIGN, Types::STAR_ASSIGN{}));
			break;
		}
		case 31: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, ::ISPA_STD::Node<::Parser::Tokens, Types::PLUS_ASSIGN>::create(start_pos, start, length, line, Tokens::PLUS_ASSIGN, Types::PLUS_ASSIGN{}));
			break;
		}
		case 32: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, ::ISPA_STD::Node<::Parser::Tokens, Types::MINUS_ASSIGN>::create(start_pos, start, length, line, Tokens::MINUS_ASSIGN, Types::MINUS_ASSIGN{}));
			break;
		}
		case 33: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, ::ISPA_STD::Node<::Parser::Tokens, Types::FLOOR_DIV>::create(start_pos, start, length, line, Tokens::FLOOR_DIV, Types::FLOOR_DIV{}));
			break;
		}
		case 34: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, ::ISPA_STD::Node<::Parser::Tokens, Types::SLASH_ASSIGN>::create(start_pos, start, length, line, Tokens::SLASH_ASSIGN, Types::SLASH_ASSIGN{}));
			break;
		}
		case 35: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, ::ISPA_STD::Node<::Parser::Tokens, Types::LSHIFT>::create(start_pos, start, length, line, Tokens::LSHIFT, Types::LSHIFT{}));
			break;
		}
		case 36: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, ::ISPA_STD::Node<::Parser::Tokens, Types::LE>::create(start_pos, start, length, line, Tokens::LE, Types::LE{}));
			break;
		}
		case 37: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, ::ISPA_STD::Node<::Parser::Tokens, Types::EQ>::create(start_pos, start, length, line, Tokens::EQ, Types::EQ{}));
			break;
		}
		case 38: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, ::ISPA_STD::Node<::Parser::Tokens, Types::GE>::create(start_pos, start, length, line, Tokens::GE, Types::GE{}));
			break;
		}
		case 39: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, ::ISPA_STD::Node<::Parser::Tokens, Types::RSHIFT>::create(start_pos, start, length, line, Tokens::RSHIFT, Types::RSHIFT{}));
			break;
		}
		case 40: {
			std::string value = captures.text(0);
			return std::make_pair(::ISPA_STD::DFA::API::null_state, ::ISPA_STD::Node<::Parser::Tokens, Types::ID>::create(start_pos, start, length, line, Tokens::ID, Types::ID{value}));
			break;
		}
		case 41: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, ::ISPA_STD::Node<::Parser::Tokens, Types::CARET_ASSIGN>::create(start_pos, start, length, line, Tokens::CARET_ASSIGN, Types::CARET_ASSIGN{}));
			break;
		}
		case 42: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, ::ISPA_STD::Node<::Parser::Tokens, Types::IF>::create(start_pos, start, length, line, Tokens::IF, Types::IF{}));
			break;
		}
		case 43: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, ::ISPA_STD::Node<::Parser::Tokens, Types::IN>::create(start_pos, start, length, line, Tokens::IN, Types::IN{}));
			break;
		}
		case 44: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, ::ISPA_STD::Node<::Parser::Tokens, Types::IS>::create(start_pos, start, length, line, Tokens::IS, Types::IS{}));
			break;
		}
		case 45: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, ::ISPA_STD::Node<::Parser::Tokens, Types::OR>::create(start_pos, start, length, line, Tokens::OR, Types::OR{}));
			break;
		}
		case 46: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, ::ISPA_STD::Node<::Parser::Tokens, Types::PIPE_ASSIGN>::create(start_pos, start, length, line, Tokens::PIPE_ASSIGN, Types::PIPE_ASSIGN{}));
			break;
		}
		case 47: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, ::ISPA_STD::Node<::Parser::Tokens, Types::POWER_ASSIGN>::create(start_pos, start, length, line, Tokens::POWER_ASSIGN, Types::POWER_ASSIGN{}));
			break;
		}
		case 48: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, ::ISPA_STD::Node<::Parser::Tokens, Types::FLOOR_DIV_ASSIGN>::create(start_pos, start, length, line, Tokens::FLOOR_DIV_ASSIGN, Types::FLOOR_DIV_ASSIGN{}));
			break;
		}
		case 49: {
			std::string floating = captures.text(2);
			std::string full = captures.text(1);
			return std::make_pair(::ISPA_STD::DFA::API::null_state, ::ISPA_STD::Node<::Parser::Tokens, Types::NUMBER>::create(start_pos, start, length, line, Tokens::NUMBER, Types::NUMBER{full, floating}));
			break;
		}
		case 50: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, ::ISPA_STD::Node<::Parser::Tokens, Types::LSHIFT_ASSIGN>::create(start_pos, start, length, line, Tokens::LSHIFT_ASSIGN, Types::LSHIFT_ASSIGN{}));
			break;
		}
		case 51: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, ::ISPA_STD::Node<::Parser::Tokens, Types::RSHIFT_ASSIGN>::create(start_pos, start, length, line, Tokens::RSHIFT_ASSIGN, Types::RSHIFT_ASSIGN{}));
			break;
		}
		case 52: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, ::ISPA_STD::Node<::Parser::Tokens, Types::AND>::create(start_pos, start, length, line, Tokens::AND, Types::AND{}));
			break;
		}
		case 53: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, ::ISPA_STD::Node<::Parser::Tokens, Types::NOT>::create(start_pos, start, length, line, Tokens::NOT, Types::NOT{}));
			break;
		}
		case 54: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, ::ISPA_STD::Node<::Parser::Tokens, Types::NONE_V>::create(start_pos, start, length, line, Tokens::NONE_V, Types::NONE_V{}));
			break;
		}
		case 55: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, ::ISPA_STD::Node<::Parser::Tokens, Types::TRUE>::create(start_pos, start, length, line, Tokens::TRUE, Types::TRUE{}));
			break;
		}
		case 56: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, ::ISPA_STD::Node<::Parser::Tokens, Types::ELSE>::create(start_pos, start, length, line, Tokens::ELSE, Types::ELSE{}));
			break;
		}
		case 57: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, ::ISPA_STD::Node<::Parser::Tokens, Types::PASS>::create(start_pos, start, length, line, Tokens::PASS, Types::PASS{}));
			break;
		}
		case 58: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, ::ISPA_STD::Node<::Parser::Tokens, Types::FALSE>::create(start_pos, start, length, line, Tokens::FALSE, Types::FALSE{}));
			break;
		}
		case 59: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, ::ISPA_STD::Node<::Parser::Tokens, Types::BREAK>::create(start_pos, start, length, line, Tokens::BREAK, Types::BREAK{}));
			break;
		}
		case 60: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, ::ISPA_STD::Node<::Parser::Tokens, Types::RETURN>::create(start_pos, start, length, line, Tokens::RETURN, Types::RETURN{}));
			break;
		}
		case 61: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, ::ISPA_STD::Node<::Parser::Tokens, Types::CONTINUE>::create(start_pos, start, length, line, Tokens::CONTINUE, Types::CONTINUE{}));
			break;
		}
	}
	throw std::runtime_error("Out of bound semantic action");
}
auto ::Parser::Lexer::init () -> void{
	return ;
}
std::array<::ISPA_STD::DFA::API::DFADebug, 1> Parser::Lexer::debug_array = {::ISPA_STD::DFA::API::DFADebug {"<Undefined>", "", 0, -1, -1, -1, 0, 1, '\000'}};
std::unordered_map<long long, std::unordered_map<long long, long long>> Parser::Lexer::debug_index = { { 0, { { 1, 0 }, { 2, 0 }, { 3, 0 }, { 4, 0 }, { 5, 0 }, { 6, 0 }, { 7, 0 }, { 8, 0 }, { 9, 0 }, { 10, 0 }, { 11, 0 }, { 12, 0 }, { 13, 0 }, { 15, 0 }, { 16, 0 }, { 17, 0 }, { 18, 0 }, { 19, 0 }, { 24, 0 }, { 25, 0 }, { 26, 0 }, { 44, 0 }, { 45, 0 }, { 46, 0 }, { 47, 0 } } }, { 1, { { 1, 0 } } }, { 2, { { 17, 0 } } }, { 3, { { 17, 0 } } }, { 4, { { 17, 0 } } }, { 5, { { 5, 0 } } }, { 8, { { 8, 0 }, { 17, 0 } } }, { 9, { { 17, 0 } } }, { 11, { { 17, 0 } } }, { 13, { { 13, 0 }, { 17, 0 } } }, { 14, { { 14, 0 } } }, { 16, { { 16, 0 }, { 17, 0 } } }, { 17, { { 17, 0 } } }, { 18, { { 17, 0 }, { 18, 0 } } }, { 20, { { 14, 0 }, { 20, 0 }, { 21, 0 }, { 22, 0 }, { 23, 0 }, { 27, 0 }, { 28, 0 }, { 29, 0 }, { 30, 0 }, { 31, 0 }, { 32, 0 }, { 33, 0 }, { 34, 0 }, { 35, 0 }, { 36, 0 }, { 37, 0 }, { 38, 0 }, { 39, 0 }, { 40, 0 }, { 41, 0 }, { 42, 0 }, { 43, 0 } } }, { 21, { { 28, 0 } } }, { 22, { { 38, 0 } } }, { 23, { { 40, 0 } } }, { 26, { { 17, 0 } } }, { 27, { { 37, 0 } } }, { 28, { { 40, 0 } } }, { 29, { { 38, 0 } } }, { 30, { { 36, 0 } } }, { 31, { { 33, 0 }, { 37, 0 }, { 41, 0 } } }, { 32, { { 38, 0 } } }, { 33, { { 40, 0 } } }, { 34, { { 28, 0 } } }, { 35, { { 32, 0 } } }, { 37, { { 17, 0 } } }, { 43, { { 0, 0 }, { 1, 0 }, { 2, 0 }, { 3, 0 }, { 4, 0 }, { 6, 0 }, { 7, 0 }, { 8, 0 }, { 9, 0 }, { 10, 0 }, { 11, 0 }, { 12, 0 }, { 13, 0 }, { 14, 0 }, { 15, 0 }, { 16, 0 }, { 17, 0 }, { 18, 0 }, { 19, 0 }, { 20, 0 }, { 21, 0 }, { 22, 0 }, { 23, 0 }, { 24, 0 }, { 25, 0 }, { 26, 0 }, { 27, 0 }, { 28, 0 }, { 29, 0 }, { 30, 0 }, { 31, 0 }, { 32, 0 }, { 33, 0 }, { 34, 0 }, { 35, 0 }, { 36, 0 }, { 37, 0 }, { 38, 0 }, { 39, 0 }, { 40, 0 }, { 41, 0 }, { 42, 0 }, { 43, 0 }, { 44, 0 }, { 45, 0 }, { 46, 0 }, { 47, 0 } } }, { 45, { { 17, 0 } } }, { 49, { { 17, 0 } } }, { 52, { { 17, 0 } } }, { 56, { { 17, 0 } } }, { 57, { { 14, 0 }, { 20, 0 }, { 21, 0 }, { 22, 0 }, { 23, 0 }, { 27, 0 }, { 28, 0 }, { 29, 0 }, { 30, 0 }, { 31, 0 }, { 32, 0 }, { 33, 0 }, { 34, 0 }, { 35, 0 }, { 36, 0 }, { 37, 0 }, { 38, 0 }, { 39, 0 }, { 40, 0 }, { 41, 0 }, { 42, 0 }, { 43, 0 } } }, { 58, { { 36, 0 } } }, { 59, { { 37, 0 } } }, { 60, { { 43, 0 } } }, { 62, { { 31, 0 } } }, { 63, { { 32, 0 } } }, { 64, { { 37, 0 } } }, { 65, { { 41, 0 } } }, { 69, { { 42, 0 } } }, { 71, { { 41, 0 } } }, { 72, { { 42, 0 } } }, { 76, { { 14, 0 } } }, { 79, { { 41, 0 } } }, { 80, { { 32, 0 } } }, { 81, { { 32, 0 } } }, { 83, { { 28, 0 } } }, { 84, { { 42, 0 } } }, { 85, { { 32, 0 } } }, { 87, { { 41, 0 } } }, { 88, { { 43, 0 } } }, { 89, { { 32, 0 } } }, { 92, { { 35, 0 } } }, { 93, { { 34, 0 } } }, { 96, { { 40, 0 } } }, { 99, { { 37, 0 } } }, { 100, { { 37, 0 } } }, { 101, { { 43, 0 } } }, { 103, { { 32, 0 } } } };
auto ::Parser::Lexer::makeToken (const char*& pos) -> Token{
	return lookup(dfa_table, char_class_table, action_table, tdfa_registers, semantic_action_exec, debug_array, debug_index, pos);
}
auto ::Parser::Parser::parseFromTokens () -> void{
	tree = main(Lexer::iterator( * lexer)).node.data();
}
auto ::Parser::Parser::lazyParse () -> void{
	tree = main(Lexer::lazy_iterator( * lexer, text)).node.data();
}
