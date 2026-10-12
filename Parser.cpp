#include "Parser.h"
auto ::Parser::FlatTypes::AUTO_5::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("AUTO_5", true);
}
auto ::Parser::FlatTypes::AUTO_5::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::AUTO_5::to_string () const -> std::string{
	return ::ISPA_STD::concat("AUTO_5 {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const AUTO_5 &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::AUTO_4::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("AUTO_4", true);
}
auto ::Parser::FlatTypes::AUTO_4::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::AUTO_4::to_string () const -> std::string{
	return ::ISPA_STD::concat("AUTO_4 {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const AUTO_4 &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::AUTO_2::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("AUTO_2", true);
}
auto ::Parser::FlatTypes::AUTO_2::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::AUTO_2::to_string () const -> std::string{
	return ::ISPA_STD::concat("AUTO_2 {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const AUTO_2 &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::AUTO_1::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("AUTO_1", true);
}
auto ::Parser::FlatTypes::AUTO_1::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::AUTO_1::to_string () const -> std::string{
	return ::ISPA_STD::concat("AUTO_1 {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const AUTO_1 &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::AUTO_3::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("AUTO_3", true);
}
auto ::Parser::FlatTypes::AUTO_3::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::AUTO_3::to_string () const -> std::string{
	return ::ISPA_STD::concat("AUTO_3 {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const AUTO_3 &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::rule_value_STRING::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("rule_value_STRING", false);
	printer.up(false);
	printer.node_with_value("value", value, true);
	printer.down();
}
auto ::Parser::FlatTypes::rule_value_STRING::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::rule_value_STRING::to_string () const -> std::string{
	return ::ISPA_STD::concat("rule_value_STRING {", "value = ", value, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const rule_value_STRING &value) -> std::ostream&{
	value.print(os);
	return os;
}
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
auto ::Parser::FlatTypes::rule_value_SPACE::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("rule_value_SPACE", true);
}
auto ::Parser::FlatTypes::rule_value_SPACE::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::rule_value_SPACE::to_string () const -> std::string{
	return ::ISPA_STD::concat("rule_value_SPACE {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const rule_value_SPACE &value) -> std::ostream&{
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
auto ::Parser::FlatTypes::AUTO_0::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("AUTO_0", true);
}
auto ::Parser::FlatTypes::AUTO_0::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::AUTO_0::to_string () const -> std::string{
	return ::ISPA_STD::concat("AUTO_0 {", "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const AUTO_0 &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::rule_value_QUANTIFIER::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("rule_value_QUANTIFIER", false);
	printer.up(false);
	printer.node_with_value("value", value, true);
	printer.down();
}
auto ::Parser::FlatTypes::rule_value_QUANTIFIER::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::rule_value_QUANTIFIER::to_string () const -> std::string{
	return ::ISPA_STD::concat("rule_value_QUANTIFIER {", "value = ", value, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const rule_value_QUANTIFIER &value) -> std::ostream&{
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
auto ::Parser::FlatTypes::rule_value_alternative::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("rule_value_alternative", false);
	printer.up(false);
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto ::Parser::FlatTypes::rule_value_alternative::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::rule_value_alternative::to_string () const -> std::string{
	return ::ISPA_STD::concat("rule_value_alternative {", "value = ", value.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const rule_value_alternative &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::rule_value_group::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("rule_value_group", false);
	printer.up(false);
	printer.subtree("value", value, true);
	printer.down();
}
auto ::Parser::FlatTypes::rule_value_group::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::rule_value_group::to_string () const -> std::string{
	return ::ISPA_STD::concat("rule_value_group {", "value = ", value, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const rule_value_group &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::rule_value::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("rule_value", false);
	printer.up(false);
	printer.node("v", false);
	printer.up(true);
	v.print(printer);
	printer.down();
	printer.subtree("alts", alts, false);
	printer.node("quantifier", true);
	printer.up(false);
	quantifier.print(printer);
	printer.down();
	printer.down();
}
auto ::Parser::FlatTypes::rule_value::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::rule_value::to_string () const -> std::string{
	return ::ISPA_STD::concat("rule_value {", "v = ", v.to_string(), ", ", "alts = ", alts, ", ", "quantifier = ", quantifier.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const rule_value &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::rule_value_pattern::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("rule_value_pattern", false);
	printer.up(false);
	printer.node_with_value("value", value, true);
	printer.down();
}
auto ::Parser::FlatTypes::rule_value_pattern::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::rule_value_pattern::to_string () const -> std::string{
	return ::ISPA_STD::concat("rule_value_pattern {", "value = ", value, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const rule_value_pattern &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::rule_capture::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("rule_capture", false);
	printer.up(false);
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto ::Parser::FlatTypes::rule_capture::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::rule_capture::to_string () const -> std::string{
	return ::ISPA_STD::concat("rule_capture {", "value = ", value.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const rule_capture &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::rule::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("rule", false);
	printer.up(false);
	printer.node("name", false);
	printer.up(true);
	name.print(printer);
	printer.down();
	printer.subtree("v", v, true);
	printer.down();
}
auto ::Parser::FlatTypes::rule::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::rule::to_string () const -> std::string{
	return ::ISPA_STD::concat("rule {", "name = ", name.to_string(), ", ", "v = ", v, "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const rule &value) -> std::ostream&{
	value.print(os);
	return os;
}
auto ::Parser::FlatTypes::main::write_to_output (::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void{
	printer.node("main", false);
	printer.up(false);
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto ::Parser::FlatTypes::main::print (std::ostream& os) const -> void{
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto ::Parser::FlatTypes::main::to_string () const -> std::string{
	return ::ISPA_STD::concat("main {", "value = ", value.to_string(), "}");
}
auto Parser::FlatTypes::operator<<(std::ostream &os, const main &value) -> std::ostream&{
	value.print(os);
	return os;
}
::ISPA_STD::DFA::API::CharToClass Parser::Lexer::char_class_table = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128};
::ISPA_STD::DFA::API::Table<21, 129> Parser::Lexer::dfa_table = {{{::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, 1, 1, 1, 1, 1, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, 1, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, 2, 3, 4, 83, 85, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, 66, 65, 64, 63, 62, 61, 59, 80, 78, 81, 8, 9, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, 71, 11, 47, 24, 45, 43, 41, 39, 37, 26, 34, 31, 28, 58, 21, 57, 76, 56, 55, 54, 53, 52, 51, 68, 67, 70, 82, 84, ::ISPA_STD::DFA::API::null_state, 13, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, 35, 32, 29, 60, 22, 79, 77, 50, 49, 73, 74, 75, 69, 72, 48, 46, 23, 44, 42, 40, 38, 36, 25, 33, 30, 27, ::ISPA_STD::DFA::API::null_state, 14, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state}, {232, 232, 232, 232, 232, 232, 232, 232, 232, 1, 1, 1, 1, 1, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 1, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232}, {212, 211, 210, 209, 208, 207, 206, 205, 204, 203, 202, 201, 200, 199, 198, 197, 196, 195, 194, 193, 192, 191, 190, 189, 188, 187, 186, 185, 184, 183, 182, 181, 180, 179, 178, 177, 176, 175, 174, 16, 173, 172, 171, 170, 169, 168, 167, 166, 165, 164, 163, 162, 161, 160, 159, 158, 157, 156, 155, 154, 153, 152, 151, 150, 149, 148, 147, 146, 145, 144, 143, 142, 141, 140, 139, 138, 137, 136, 135, 134, 133, 132, 131, 130, 129, 128, 127, 126, 125, 124, 123, 122, 121, 120, 119, 118, 117, 116, 115, 114, 113, 112, 111, 110, 109, 108, 107, 106, 105, 104, 103, 102, 101, 100, 99, 98, 97, 96, 95, 94, 93, 92, 91, 90, 89, 88, 87, 86, ::ISPA_STD::DFA::API::null_state}, {233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233}, {234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234}, {213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213, 213}, {214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214}, {215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 216, 215, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215}, {238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238}, {239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239}, {217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217}, {241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241}, {218, 218, 218, 218, 218, 218, 218, 218, 218, 218, 218, 218, 218, 218, 218, 218, 218, 218, 218, 218, 218, 218, 218, 218, 218, 218, 218, 218, 218, 218, 218, 218, 218, 218, 218, 218, 218, 218, 218, 218, 218, 218, 218, 218, 218, 218, 218, 218, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 218, 218, 218, 218, 218, 218, 218, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 218, 218, 218, 218, 18, 218, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 218, 218, 218, 218, 218, 218}, {::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, 19, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state}, {243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243}, {15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 219, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, ::ISPA_STD::DFA::API::null_state}, {244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244}, {::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, 229, 228, 227, 226, 225, 224, 223, 222, 221, 220, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state}, {230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 230, 230, 230, 230, 230, 230, 230, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 230, 230, 230, 230, 18, 230, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 230, 230, 230, 230, 230, 230}, {246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246}, {231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231, 231}}};
::ISPA_STD::DFA::API::Table<211, 4> Parser::Lexer::action_table = {{{1, 0, ::ISPA_STD::DFA::API::null_state, 12}, {1, 0, ::ISPA_STD::DFA::API::null_state, 12}, {1, 0, ::ISPA_STD::DFA::API::null_state, 12}, {1, 0, ::ISPA_STD::DFA::API::null_state, 12}, {1, 0, ::ISPA_STD::DFA::API::null_state, 12}, {1, 0, ::ISPA_STD::DFA::API::null_state, 12}, {1, 0, ::ISPA_STD::DFA::API::null_state, 12}, {1, 0, ::ISPA_STD::DFA::API::null_state, 12}, {1, 0, ::ISPA_STD::DFA::API::null_state, 12}, {1, 0, ::ISPA_STD::DFA::API::null_state, 12}, {1, 0, ::ISPA_STD::DFA::API::null_state, 12}, {1, 0, ::ISPA_STD::DFA::API::null_state, 12}, {1, 0, ::ISPA_STD::DFA::API::null_state, 12}, {1, 0, ::ISPA_STD::DFA::API::null_state, 12}, {1, 0, ::ISPA_STD::DFA::API::null_state, 12}, {1, 0, ::ISPA_STD::DFA::API::null_state, 12}, {1, 0, ::ISPA_STD::DFA::API::null_state, 12}, {1, 0, ::ISPA_STD::DFA::API::null_state, 12}, {1, 0, ::ISPA_STD::DFA::API::null_state, 12}, {1, 0, ::ISPA_STD::DFA::API::null_state, 12}, {1, 0, ::ISPA_STD::DFA::API::null_state, 12}, {1, 0, ::ISPA_STD::DFA::API::null_state, 12}, {1, 0, ::ISPA_STD::DFA::API::null_state, 12}, {1, 0, ::ISPA_STD::DFA::API::null_state, 12}, {1, 0, ::ISPA_STD::DFA::API::null_state, 12}, {1, 0, ::ISPA_STD::DFA::API::null_state, 12}, {1, 0, ::ISPA_STD::DFA::API::null_state, 12}, {1, 0, ::ISPA_STD::DFA::API::null_state, 12}, {1, 0, ::ISPA_STD::DFA::API::null_state, 12}, {1, 0, ::ISPA_STD::DFA::API::null_state, 12}, {1, 0, ::ISPA_STD::DFA::API::null_state, 12}, {1, 0, ::ISPA_STD::DFA::API::null_state, 12}, {1, 0, ::ISPA_STD::DFA::API::null_state, 12}, {1, 0, ::ISPA_STD::DFA::API::null_state, 12}, {1, 0, ::ISPA_STD::DFA::API::null_state, 12}, {1, 0, ::ISPA_STD::DFA::API::null_state, 12}, {1, 0, ::ISPA_STD::DFA::API::null_state, 12}, {1, 0, ::ISPA_STD::DFA::API::null_state, 12}, {1, 10, ::ISPA_STD::DFA::API::null_state, 7}, {1, 0, ::ISPA_STD::DFA::API::null_state, 12}, {1, 10, ::ISPA_STD::DFA::API::null_state, 7}, {1, 10, ::ISPA_STD::DFA::API::null_state, 7}, {1, 10, ::ISPA_STD::DFA::API::null_state, 7}, {1, 10, ::ISPA_STD::DFA::API::null_state, 7}, {1, 10, ::ISPA_STD::DFA::API::null_state, 7}, {1, 10, ::ISPA_STD::DFA::API::null_state, 7}, {1, 0, ::ISPA_STD::DFA::API::null_state, 12}, {1, 0, ::ISPA_STD::DFA::API::null_state, 12}, {1, 0, ::ISPA_STD::DFA::API::null_state, 12}, {1, 0, ::ISPA_STD::DFA::API::null_state, 12}, {1, 4, ::ISPA_STD::DFA::API::null_state, 10}, {1, 0, ::ISPA_STD::DFA::API::null_state, 12}, {1, 0, ::ISPA_STD::DFA::API::null_state, 12}, {1, 0, ::ISPA_STD::DFA::API::null_state, 12}, {1, 0, ::ISPA_STD::DFA::API::null_state, 12}, {1, 0, ::ISPA_STD::DFA::API::null_state, 12}, {1, 0, ::ISPA_STD::DFA::API::null_state, 12}, {1, 10, ::ISPA_STD::DFA::API::null_state, 7}, {1, 0, ::ISPA_STD::DFA::API::null_state, 12}, {1, 10, ::ISPA_STD::DFA::API::null_state, 7}, {1, 10, ::ISPA_STD::DFA::API::null_state, 7}, {1, 0, ::ISPA_STD::DFA::API::null_state, 12}, {1, 6, ::ISPA_STD::DFA::API::null_state, 5}, {1, 0, ::ISPA_STD::DFA::API::null_state, 12}, {1, 2, ::ISPA_STD::DFA::API::null_state, 6}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 8, ::ISPA_STD::DFA::API::null_state, 15}, {1, 7, ::ISPA_STD::DFA::API::null_state, 235}, {1, 3, ::ISPA_STD::DFA::API::null_state, 236}, {1, 11, ::ISPA_STD::DFA::API::null_state, 237}, {1, 11, ::ISPA_STD::DFA::API::null_state, 17}, {1, 5, ::ISPA_STD::DFA::API::null_state, 240}, {1, 1, ::ISPA_STD::DFA::API::null_state, 242}, {1, 9, ::ISPA_STD::DFA::API::null_state, 16}, {1, 12, ::ISPA_STD::DFA::API::null_state, 20}, {1, 12, ::ISPA_STD::DFA::API::null_state, 20}, {1, 12, ::ISPA_STD::DFA::API::null_state, 20}, {1, 12, ::ISPA_STD::DFA::API::null_state, 20}, {1, 12, ::ISPA_STD::DFA::API::null_state, 20}, {1, 12, ::ISPA_STD::DFA::API::null_state, 20}, {1, 12, ::ISPA_STD::DFA::API::null_state, 20}, {1, 12, ::ISPA_STD::DFA::API::null_state, 20}, {1, 12, ::ISPA_STD::DFA::API::null_state, 20}, {1, 12, ::ISPA_STD::DFA::API::null_state, 20}, {1, 1, ::ISPA_STD::DFA::API::null_state, 245}, {1, 13, ::ISPA_STD::DFA::API::null_state, 247}}};
auto ::Parser::Lexer::semantic_action_exec (long long state, const ::ISPA_STD::DFA::API::Captures& captures, long long start_pos, const char* start, long long length, long long line) -> std::pair<long long, Token>{
	switch (state) {
		case 0: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, ::ISPA_STD::Node<::Parser::Tokens, Types::__WS>::create(start_pos, start, length, line, Tokens::__WS, Types::__WS{}));
			break;
		}
		case 1: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, ::ISPA_STD::Node<::Parser::Tokens, Types::AUTO_1>::create(start_pos, start, length, line, Tokens::AUTO_1, Types::AUTO_1{}));
			break;
		}
		case 2: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, ::ISPA_STD::Node<::Parser::Tokens, Types::AUTO_2>::create(start_pos, start, length, line, Tokens::AUTO_2, Types::AUTO_2{}));
			break;
		}
		case 3: {
			char value;
			if (captures.is_set(3)) {
				value = captures.character(3);
			} else {
				if (captures.is_set(1)) {
					value = captures.character(1);
				} else {
					if (captures.is_set(2)) {
						value = captures.character(2);
					}
				}
			}
			return std::make_pair(::ISPA_STD::DFA::API::null_state, ::ISPA_STD::Node<::Parser::Tokens, Types::rule::value::QUANTIFIER>::create(start_pos, start, length, line, Tokens::rule_value_QUANTIFIER, Types::rule::value::QUANTIFIER{value}));
			break;
		}
		case 4: {
			char value;
			if (captures.is_set(3)) {
				value = captures.character(3);
			} else {
				if (captures.is_set(1)) {
					value = captures.character(1);
				} else {
					if (captures.is_set(2)) {
						value = captures.character(2);
					}
				}
			}
			return std::make_pair(::ISPA_STD::DFA::API::null_state, ::ISPA_STD::Node<::Parser::Tokens, Types::rule::value::QUANTIFIER>::create(start_pos, start, length, line, Tokens::rule_value_QUANTIFIER, Types::rule::value::QUANTIFIER{value}));
			break;
		}
		case 5: {
			std::string floating = captures.text(6);
			std::string full = captures.text(5);
			return std::make_pair(::ISPA_STD::DFA::API::null_state, ::ISPA_STD::Node<::Parser::Tokens, Types::NUMBER>::create(start_pos, start, length, line, Tokens::NUMBER, Types::NUMBER{full, floating}));
			break;
		}
		case 6: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, ::ISPA_STD::Node<::Parser::Tokens, Types::AUTO_4>::create(start_pos, start, length, line, Tokens::AUTO_4, Types::AUTO_4{}));
			break;
		}
		case 7: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, ::ISPA_STD::Node<::Parser::Tokens, Types::AUTO_5>::create(start_pos, start, length, line, Tokens::AUTO_5, Types::AUTO_5{}));
			break;
		}
		case 8: {
			char value;
			if (captures.is_set(3)) {
				value = captures.character(3);
			} else {
				if (captures.is_set(1)) {
					value = captures.character(1);
				} else {
					if (captures.is_set(2)) {
						value = captures.character(2);
					}
				}
			}
			return std::make_pair(::ISPA_STD::DFA::API::null_state, ::ISPA_STD::Node<::Parser::Tokens, Types::rule::value::QUANTIFIER>::create(start_pos, start, length, line, Tokens::rule_value_QUANTIFIER, Types::rule::value::QUANTIFIER{value}));
			break;
		}
		case 9: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, ::ISPA_STD::Node<::Parser::Tokens, Types::AUTO_3>::create(start_pos, start, length, line, Tokens::AUTO_3, Types::AUTO_3{}));
			break;
		}
		case 10: {
			std::string value = captures.text(0);
			return std::make_pair(::ISPA_STD::DFA::API::null_state, ::ISPA_STD::Node<::Parser::Tokens, Types::ID>::create(start_pos, start, length, line, Tokens::ID, Types::ID{value}));
			break;
		}
		case 11: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, ::ISPA_STD::Node<::Parser::Tokens, Types::AUTO_0>::create(start_pos, start, length, line, Tokens::AUTO_0, Types::AUTO_0{}));
			break;
		}
		case 12: {
			std::string value = captures.text(4);
			return std::make_pair(::ISPA_STD::DFA::API::null_state, ::ISPA_STD::Node<::Parser::Tokens, Types::rule::value::STRING>::create(start_pos, start, length, line, Tokens::rule_value_STRING, Types::rule::value::STRING{value}));
			break;
		}
		case 13: {
			std::string value = captures.text(0);
			return std::make_pair(::ISPA_STD::DFA::API::null_state, ::ISPA_STD::Node<::Parser::Tokens, Types::ID>::create(start_pos, start, length, line, Tokens::ID, Types::ID{value}));
			break;
		}
		case 14: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, ::ISPA_STD::Node<::Parser::Tokens, Types::rule::value::SPACE>::create(start_pos, start, length, line, Tokens::rule_value_SPACE, Types::rule::value::SPACE{}));
			break;
		}
		case 15: {
			std::string floating = captures.text(6);
			std::string full = captures.text(5);
			return std::make_pair(::ISPA_STD::DFA::API::null_state, ::ISPA_STD::Node<::Parser::Tokens, Types::NUMBER>::create(start_pos, start, length, line, Tokens::NUMBER, Types::NUMBER{full, floating}));
			break;
		}
	}
	throw std::runtime_error("Out of bound semantic action");
}
auto ::Parser::Lexer::init () -> void{
	return ;
}
std::array<::ISPA_STD::DFA::API::DFADebug, 226> Parser::Lexer::debug_array = {::ISPA_STD::DFA::API::DFADebug {"[ \\t\\n\\r\\v\\f]", "__WS", 0, -1, 0, 12, 0, 1, '\t'}, ::ISPA_STD::DFA::API::DFADebug {"[ \\t\\n\\r\\v\\f]", "__WS", 0, -1, 0, 12, 0, 1, '\n'}, ::ISPA_STD::DFA::API::DFADebug {"[ \\t\\n\\r\\v\\f]", "__WS", 0, -1, 0, 12, 0, 1, '\x0B'}, ::ISPA_STD::DFA::API::DFADebug {"[ \\t\\n\\r\\v\\f]", "__WS", 0, -1, 0, 12, 0, 1, '\x0C'}, ::ISPA_STD::DFA::API::DFADebug {"[ \\t\\n\\r\\v\\f]", "__WS", 0, -1, 0, 12, 0, 1, '\r'}, ::ISPA_STD::DFA::API::DFADebug {"[ \\t\\n\\r\\v\\f]", "__WS", 0, -1, 0, 12, 0, 1, ' '}, ::ISPA_STD::DFA::API::DFADebug {"'", "rule.value.STRING", 0, -1, -1, 14, 0, 1, '\''}, ::ISPA_STD::DFA::API::DFADebug {"(", "AUTO_1", 0, -1, -1, 20, 0, 1, '('}, ::ISPA_STD::DFA::API::DFADebug {")", "AUTO_2", 0, -1, -1, 22, 0, 1, ')'}, ::ISPA_STD::DFA::API::DFADebug {":", "AUTO_4", 0, -1, -1, 28, 0, 1, ':'}, ::ISPA_STD::DFA::API::DFADebug {";", "AUTO_5", 0, -1, -1, 30, 0, 1, ';'}, ::ISPA_STD::DFA::API::DFADebug {"@", "AUTO_3", 0, -1, -1, 18, 0, 1, '@'}, ::ISPA_STD::DFA::API::DFADebug {"\\s", "rule.value.SPACE", 0, -1, -1, 9, 0, 2, '\\'}, ::ISPA_STD::DFA::API::DFADebug {"|", "AUTO_0", 0, -1, -1, 7, 0, 1, '|'}, ::ISPA_STD::DFA::API::DFADebug {"'", "rule.value.STRING", 2, -1, -1, 16, 0, 1, '\''}, ::ISPA_STD::DFA::API::DFADebug {"[0-9]", "NUMBER", 0, -1, 2, 24, 0, 1, '0'}, ::ISPA_STD::DFA::API::DFADebug {"[0-9]", "NUMBER", 0, -1, 2, 24, 0, 1, '1'}, ::ISPA_STD::DFA::API::DFADebug {"[0-9]", "NUMBER", 0, -1, 2, 24, 0, 1, '2'}, ::ISPA_STD::DFA::API::DFADebug {"[0-9]", "NUMBER", 0, -1, 2, 24, 0, 1, '3'}, ::ISPA_STD::DFA::API::DFADebug {"[0-9]", "NUMBER", 0, -1, 2, 24, 0, 1, '4'}, ::ISPA_STD::DFA::API::DFADebug {"[0-9]", "NUMBER", 0, -1, 2, 24, 0, 1, '5'}, ::ISPA_STD::DFA::API::DFADebug {"[0-9]", "NUMBER", 0, -1, 2, 24, 0, 1, '6'}, ::ISPA_STD::DFA::API::DFADebug {"[0-9]", "NUMBER", 0, -1, 2, 24, 0, 1, '7'}, ::ISPA_STD::DFA::API::DFADebug {"[0-9]", "NUMBER", 0, -1, 2, 24, 0, 1, '8'}, ::ISPA_STD::DFA::API::DFADebug {"[0-9]", "NUMBER", 0, -1, 2, 24, 0, 1, '9'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, '0'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, '1'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, '2'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, '3'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, '4'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, '5'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, '6'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, '7'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, '8'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, '9'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 'A'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 'B'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 'C'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 'D'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 'E'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 'F'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 'G'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 'H'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 'I'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 'J'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 'K'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 'L'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 'M'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 'N'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 'O'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 'P'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 'Q'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 'R'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 'S'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 'T'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 'U'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 'V'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 'W'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 'X'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 'Y'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 'Z'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, '_'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 'a'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 'b'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 'c'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 'd'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 'e'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 'f'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 'g'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 'h'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 'i'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 'j'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 'k'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 'l'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 'm'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 'n'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 'o'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 'p'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 'q'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 'r'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 's'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 't'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 'u'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 'v'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 'w'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 'x'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 'y'}, ::ISPA_STD::DFA::API::DFADebug {"[_a-zA-Z0-9]", "ID", 0, -1, 1, 1, 0, 1, 'z'}, ::ISPA_STD::DFA::API::DFADebug {"\\s", "rule.value.SPACE", 0, -1, -1, 10, 1, 2, 's'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, '\000'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, '\x01'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, '\x02'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, '\x03'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, '\x04'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, '\x05'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, '\x06'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, '\x07'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, '\x08'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, '\t'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, '\n'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, '\x0B'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, '\x0C'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, '\r'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, '\x0E'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, '\x0F'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, '\x10'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, '\x11'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, '\x12'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, '\x13'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, '\x14'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, '\x15'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, '\x16'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, '\x17'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, '\x18'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, '\x19'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, '\x1A'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, '\x1B'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, '\x1C'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, '\x1D'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, '\x1E'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, '\x1F'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, ' '}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, '!'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, '"'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, '#'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, '$'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, '%'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, '&'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, '('}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, ')'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, '*'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, '+'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, ','}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, '-'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, '.'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, '/'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, '0'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, '1'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, '2'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, '3'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, '4'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, '5'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, '6'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, '7'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, '8'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, '9'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, ':'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, ';'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, '<'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, '='}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, '>'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, '?'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, '@'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, 'A'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, 'B'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, 'C'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, 'D'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, 'E'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, 'F'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, 'G'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, 'H'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, 'I'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, 'J'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, 'K'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, 'L'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, 'M'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, 'N'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, 'O'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, 'P'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, 'Q'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, 'R'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, 'S'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, 'T'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, 'U'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, 'V'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, 'W'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, 'X'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, 'Y'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, 'Z'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, '['}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, '\\'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, ']'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, '^'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, '_'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, '`'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, 'a'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, 'b'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, 'c'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, 'd'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, 'e'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, 'f'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, 'g'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, 'h'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, 'i'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, 'j'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, 'k'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, 'l'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, 'm'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, 'n'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, 'o'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, 'p'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, 'q'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, 'r'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, 's'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, 't'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, 'u'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, 'v'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, 'w'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, 'x'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, 'y'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, 'z'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, '{'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, '|'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, '}'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, '~'}, ::ISPA_STD::DFA::API::DFADebug {"[']", "rule.value.STRING", 1, -1, 0, 15, 0, 1, '\x7F'}, ::ISPA_STD::DFA::API::DFADebug {"[0-9]", "NUMBER", 1, -1, 0, 26, 0, 1, '0'}, ::ISPA_STD::DFA::API::DFADebug {"[0-9]", "NUMBER", 1, -1, 0, 26, 0, 1, '1'}, ::ISPA_STD::DFA::API::DFADebug {"[0-9]", "NUMBER", 1, -1, 0, 26, 0, 1, '2'}, ::ISPA_STD::DFA::API::DFADebug {"[0-9]", "NUMBER", 1, -1, 0, 26, 0, 1, '3'}, ::ISPA_STD::DFA::API::DFADebug {"[0-9]", "NUMBER", 1, -1, 0, 26, 0, 1, '4'}, ::ISPA_STD::DFA::API::DFADebug {"[0-9]", "NUMBER", 1, -1, 0, 26, 0, 1, '5'}, ::ISPA_STD::DFA::API::DFADebug {"[0-9]", "NUMBER", 1, -1, 0, 26, 0, 1, '6'}, ::ISPA_STD::DFA::API::DFADebug {"[0-9]", "NUMBER", 1, -1, 0, 26, 0, 1, '7'}, ::ISPA_STD::DFA::API::DFADebug {"[0-9]", "NUMBER", 1, -1, 0, 26, 0, 1, '8'}, ::ISPA_STD::DFA::API::DFADebug {"[0-9]", "NUMBER", 1, -1, 0, 26, 0, 1, '9'}};
std::unordered_map<long long, std::unordered_map<long long, long long>> Parser::Lexer::debug_index = { { 0, { { 9, 0 }, { 10, 1 }, { 11, 2 }, { 12, 3 }, { 13, 4 }, { 32, 5 }, { 39, 6 }, { 40, 7 }, { 41, 8 }, { 58, 9 }, { 59, 10 }, { 64, 11 }, { 92, 12 }, { 124, 13 } } }, { 1, { { 9, 0 }, { 10, 1 }, { 11, 2 }, { 12, 3 }, { 13, 4 }, { 32, 5 } } }, { 2, { { 39, 14 } } }, { 7, { { 48, 15 }, { 49, 16 }, { 50, 17 }, { 51, 18 }, { 52, 19 }, { 53, 20 }, { 54, 21 }, { 55, 22 }, { 56, 23 }, { 57, 24 } } }, { 12, { { 48, 25 }, { 49, 26 }, { 50, 27 }, { 51, 28 }, { 52, 29 }, { 53, 30 }, { 54, 31 }, { 55, 32 }, { 56, 33 }, { 57, 34 }, { 65, 35 }, { 66, 36 }, { 67, 37 }, { 68, 38 }, { 69, 39 }, { 70, 40 }, { 71, 41 }, { 72, 42 }, { 73, 43 }, { 74, 44 }, { 75, 45 }, { 76, 46 }, { 77, 47 }, { 78, 48 }, { 79, 49 }, { 80, 50 }, { 81, 51 }, { 82, 52 }, { 83, 53 }, { 84, 54 }, { 85, 55 }, { 86, 56 }, { 87, 57 }, { 88, 58 }, { 89, 59 }, { 90, 60 }, { 95, 61 }, { 97, 62 }, { 98, 63 }, { 99, 64 }, { 100, 65 }, { 101, 66 }, { 102, 67 }, { 103, 68 }, { 104, 69 }, { 105, 70 }, { 106, 71 }, { 107, 72 }, { 108, 73 }, { 109, 74 }, { 110, 75 }, { 111, 76 }, { 112, 77 }, { 113, 78 }, { 114, 79 }, { 115, 80 }, { 116, 81 }, { 117, 82 }, { 118, 83 }, { 119, 84 }, { 120, 85 }, { 121, 86 }, { 122, 87 } } }, { 13, { { 115, 88 } } }, { 15, { { 0, 89 }, { 1, 90 }, { 2, 91 }, { 3, 92 }, { 4, 93 }, { 5, 94 }, { 6, 95 }, { 7, 96 }, { 8, 97 }, { 9, 98 }, { 10, 99 }, { 11, 100 }, { 12, 101 }, { 13, 102 }, { 14, 103 }, { 15, 104 }, { 16, 105 }, { 17, 106 }, { 18, 107 }, { 19, 108 }, { 20, 109 }, { 21, 110 }, { 22, 111 }, { 23, 112 }, { 24, 113 }, { 25, 114 }, { 26, 115 }, { 27, 116 }, { 28, 117 }, { 29, 118 }, { 30, 119 }, { 31, 120 }, { 32, 121 }, { 33, 122 }, { 34, 123 }, { 35, 124 }, { 36, 125 }, { 37, 126 }, { 38, 127 }, { 40, 128 }, { 41, 129 }, { 42, 130 }, { 43, 131 }, { 44, 132 }, { 45, 133 }, { 46, 134 }, { 47, 135 }, { 48, 136 }, { 49, 137 }, { 50, 138 }, { 51, 139 }, { 52, 140 }, { 53, 141 }, { 54, 142 }, { 55, 143 }, { 56, 144 }, { 57, 145 }, { 58, 146 }, { 59, 147 }, { 60, 148 }, { 61, 149 }, { 62, 150 }, { 63, 151 }, { 64, 152 }, { 65, 153 }, { 66, 154 }, { 67, 155 }, { 68, 156 }, { 69, 157 }, { 70, 158 }, { 71, 159 }, { 72, 160 }, { 73, 161 }, { 74, 162 }, { 75, 163 }, { 76, 164 }, { 77, 165 }, { 78, 166 }, { 79, 167 }, { 80, 168 }, { 81, 169 }, { 82, 170 }, { 83, 171 }, { 84, 172 }, { 85, 173 }, { 86, 174 }, { 87, 175 }, { 88, 176 }, { 89, 177 }, { 90, 178 }, { 91, 179 }, { 92, 180 }, { 93, 181 }, { 94, 182 }, { 95, 183 }, { 96, 184 }, { 97, 185 }, { 98, 186 }, { 99, 187 }, { 100, 188 }, { 101, 189 }, { 102, 190 }, { 103, 191 }, { 104, 192 }, { 105, 193 }, { 106, 194 }, { 107, 195 }, { 108, 196 }, { 109, 197 }, { 110, 198 }, { 111, 199 }, { 112, 200 }, { 113, 201 }, { 114, 202 }, { 115, 203 }, { 116, 204 }, { 117, 205 }, { 118, 206 }, { 119, 207 }, { 120, 208 }, { 121, 209 }, { 122, 210 }, { 123, 211 }, { 124, 212 }, { 125, 213 }, { 126, 214 }, { 127, 215 } } }, { 18, { { 48, 25 }, { 49, 26 }, { 50, 27 }, { 51, 28 }, { 52, 29 }, { 53, 30 }, { 54, 31 }, { 55, 32 }, { 56, 33 }, { 57, 34 }, { 65, 35 }, { 66, 36 }, { 67, 37 }, { 68, 38 }, { 69, 39 }, { 70, 40 }, { 71, 41 }, { 72, 42 }, { 73, 43 }, { 74, 44 }, { 75, 45 }, { 76, 46 }, { 77, 47 }, { 78, 48 }, { 79, 49 }, { 80, 50 }, { 81, 51 }, { 82, 52 }, { 83, 53 }, { 84, 54 }, { 85, 55 }, { 86, 56 }, { 87, 57 }, { 88, 58 }, { 89, 59 }, { 90, 60 }, { 95, 61 }, { 97, 62 }, { 98, 63 }, { 99, 64 }, { 100, 65 }, { 101, 66 }, { 102, 67 }, { 103, 68 }, { 104, 69 }, { 105, 70 }, { 106, 71 }, { 107, 72 }, { 108, 73 }, { 109, 74 }, { 110, 75 }, { 111, 76 }, { 112, 77 }, { 113, 78 }, { 114, 79 }, { 115, 80 }, { 116, 81 }, { 117, 82 }, { 118, 83 }, { 119, 84 }, { 120, 85 }, { 121, 86 }, { 122, 87 } } }, { 20, { { 48, 216 }, { 49, 217 }, { 50, 218 }, { 51, 219 }, { 52, 220 }, { 53, 221 }, { 54, 222 }, { 55, 223 }, { 56, 224 }, { 57, 225 } } } };
auto ::Parser::Lexer::makeToken (const char*& pos) -> Token{
	return lookup(dfa_table, char_class_table, action_table, tdfa_registers, semantic_action_exec, debug_array, debug_index, pos);
}
auto ::Parser::Parser::parseFromTokens () -> void{
	tree = main(Lexer::iterator( * lexer)).node.data();
}
auto ::Parser::Parser::lazyParse () -> void{
	tree = main(Lexer::lazy_iterator( * lexer, text)).node.data();
}
