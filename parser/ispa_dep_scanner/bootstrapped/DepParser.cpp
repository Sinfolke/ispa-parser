#include "DepParser.h"

#include <ispastdlib/dfa_api.hpp>
#include <ispastdlib/to_string.hpp>

auto DepParser::TokensToString(std::size_t id) -> const char* {
	switch (id) {
		case Tokens::__WS::id: {
			return TokensStr::__WS::id;
			break;
		}
		case Tokens::LESS_THAN_SIGN::id: {
			return TokensStr::LESS_THAN_SIGN::id;
			break;
		}
		case Tokens::AUTO::id: {
			return TokensStr::AUTO::id;
			break;
		}
		case Tokens::modules::ispa_dep_scanner::LBRACE::id: {
			return TokensStr::modules::ispa_dep_scanner::LBRACE::id;
			break;
		}
		case Tokens::modules::ispa_dep_scanner::HASH::id: {
			return TokensStr::modules::ispa_dep_scanner::HASH::id;
			break;
		}
		case Tokens::modules::ispa_dep_scanner::ALL::id: {
			return TokensStr::modules::ispa_dep_scanner::ALL::id;
			break;
		}
		case Tokens::modules::ispa_dep_scanner::COLON::id: {
			return TokensStr::modules::ispa_dep_scanner::COLON::id;
			break;
		}
		case Tokens::modules::ispa_dep_scanner::DOT::id: {
			return TokensStr::modules::ispa_dep_scanner::DOT::id;
			break;
		}
		case Tokens::modules::ispa_dep_scanner::FAIL::id: {
			return TokensStr::modules::ispa_dep_scanner::FAIL::id;
			break;
		}
		case Tokens::modules::ispa_dep_scanner::FROM::id: {
			return TokensStr::modules::ispa_dep_scanner::FROM::id;
			break;
		}
		case Tokens::modules::ispa_dep_scanner::RBRACE::id: {
			return TokensStr::modules::ispa_dep_scanner::RBRACE::id;
			break;
		}
		case Tokens::modules::ispa_dep_scanner::FEATURE::id: {
			return TokensStr::modules::ispa_dep_scanner::FEATURE::id;
			break;
		}
		case Tokens::modules::ispa_dep_scanner::DETACH::id: {
			return TokensStr::modules::ispa_dep_scanner::DETACH::id;
			break;
		}
		case Tokens::modules::ispa_dep_scanner::IMPORT::id: {
			return TokensStr::modules::ispa_dep_scanner::IMPORT::id;
			break;
		}
		case Tokens::modules::ispa_dep_scanner::SEMI::id: {
			return TokensStr::modules::ispa_dep_scanner::SEMI::id;
			break;
		}
		case Tokens::modules::ispa_dep_scanner::COMMENT::id: {
			return TokensStr::modules::ispa_dep_scanner::COMMENT::id;
			break;
		}
		case Tokens::modules::common::PY_RAW::id: {
			return TokensStr::modules::common::PY_RAW::id;
			break;
		}
		case Tokens::modules::ispa_dep_scanner::MODULE::id: {
			return TokensStr::modules::ispa_dep_scanner::MODULE::id;
			break;
		}
		case Tokens::modules::ispa_dep_scanner::STRING::id: {
			return TokensStr::modules::ispa_dep_scanner::STRING::id;
			break;
		}
		case Tokens::GREATER_THAN_SIGN::id: {
			return TokensStr::GREATER_THAN_SIGN::id;
			break;
		}
		case Tokens::modules::ispa_dep_scanner::CGROUP::id: {
			return TokensStr::modules::ispa_dep_scanner::CGROUP::id;
			break;
		}
		case Tokens::modules::common::ID::id: {
			return TokensStr::modules::common::ID::id;
			break;
		}
		case Tokens::modules::ispa_dep_scanner::AS::id: {
			return TokensStr::modules::ispa_dep_scanner::AS::id;
			break;
		}
		case Tokens::modules::ispa_dep_scanner::OTHER::id: {
			return TokensStr::modules::ispa_dep_scanner::OTHER::id;
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
		case Tokens::COMMA::id: {
			return TokensStr::COMMA::id;
			break;
		}
		case Tokens::modules::common::NUMBER::id: {
			return TokensStr::modules::common::NUMBER::id;
			break;
		}
	}
	throw "Invalid Tokens ID";
}
auto DepParser::RulesToString(std::size_t id) -> const char* {
	switch (id) {
		case Rules::main::id: {
			return RulesStr::main::id;
			break;
		}
		case Rules::modules::common::name::id: {
			return RulesStr::modules::common::name::id;
			break;
		}
		case Rules::modules::common::name::__grp2::id: {
			return RulesStr::modules::common::name::__grp2::id;
			break;
		}
		case Rules::modules::common::name::__grp2::__tail::id: {
			return RulesStr::modules::common::name::__grp2::__tail::id;
			break;
		}
		case Rules::modules::common::name::__q4::id: {
			return RulesStr::modules::common::name::__q4::id;
			break;
		}
		case Rules::modules::common::name::__q6::id: {
			return RulesStr::modules::common::name::__q6::id;
			break;
		}
		case Rules::modules::common::param::id: {
			return RulesStr::modules::common::param::id;
			break;
		}
		case Rules::modules::common::param::__grp2::id: {
			return RulesStr::modules::common::param::__grp2::id;
			break;
		}
		case Rules::modules::common::param::__grp2::__tail::id: {
			return RulesStr::modules::common::param::__grp2::__tail::id;
			break;
		}
		case Rules::modules::common::params::id: {
			return RulesStr::modules::common::params::id;
			break;
		}
		case Rules::modules::common::params::__q4::id: {
			return RulesStr::modules::common::params::__q4::id;
			break;
		}
		case Rules::modules::common::template_params::id: {
			return RulesStr::modules::common::template_params::id;
			break;
		}
		case Rules::modules::common::template_params::__q2::id: {
			return RulesStr::modules::common::template_params::__q2::id;
			break;
		}
		case Rules::modules::ispa_dep_scanner::atom::id: {
			return RulesStr::modules::ispa_dep_scanner::atom::id;
			break;
		}
		case Rules::modules::ispa_dep_scanner::balanced_item::id: {
			return RulesStr::modules::ispa_dep_scanner::balanced_item::id;
			break;
		}
		case Rules::modules::ispa_dep_scanner::body::id: {
			return RulesStr::modules::ispa_dep_scanner::body::id;
			break;
		}
		case Rules::modules::ispa_dep_scanner::body::regular::id: {
			return RulesStr::modules::ispa_dep_scanner::body::regular::id;
			break;
		}
		case Rules::modules::ispa_dep_scanner::body::regular::__q2::id: {
			return RulesStr::modules::ispa_dep_scanner::body::regular::__q2::id;
			break;
		}
		case Rules::modules::ispa_dep_scanner::body::regular::__q2::__tail::id: {
			return RulesStr::modules::ispa_dep_scanner::body::regular::__q2::__tail::id;
			break;
		}
		case Rules::modules::ispa_dep_scanner::braces::id: {
			return RulesStr::modules::ispa_dep_scanner::braces::id;
			break;
		}
		case Rules::modules::ispa_dep_scanner::braces::__q2::id: {
			return RulesStr::modules::ispa_dep_scanner::braces::__q2::id;
			break;
		}
		case Rules::modules::ispa_dep_scanner::braces::__q2::__tail::id: {
			return RulesStr::modules::ispa_dep_scanner::braces::__q2::__tail::id;
			break;
		}
		case Rules::modules::ispa_dep_scanner::declaration::id: {
			return RulesStr::modules::ispa_dep_scanner::declaration::id;
			break;
		}
		case Rules::modules::ispa_dep_scanner::declaration::__q0::id: {
			return RulesStr::modules::ispa_dep_scanner::declaration::__q0::id;
			break;
		}
		case Rules::modules::ispa_dep_scanner::declaration::__q0::__tail::id: {
			return RulesStr::modules::ispa_dep_scanner::declaration::__q0::__tail::id;
			break;
		}
		case Rules::modules::ispa_dep_scanner::fail_decl::id: {
			return RulesStr::modules::ispa_dep_scanner::fail_decl::id;
			break;
		}
		case Rules::modules::ispa_dep_scanner::feature_decl::id: {
			return RulesStr::modules::ispa_dep_scanner::feature_decl::id;
			break;
		}
		case Rules::modules::ispa_dep_scanner::feature_decl::__q6::id: {
			return RulesStr::modules::ispa_dep_scanner::feature_decl::__q6::id;
			break;
		}
		case Rules::modules::ispa_dep_scanner::identifier::id: {
			return RulesStr::modules::ispa_dep_scanner::identifier::id;
			break;
		}
		case Rules::modules::ispa_dep_scanner::keyword::id: {
			return RulesStr::modules::ispa_dep_scanner::keyword::id;
			break;
		}
		case Rules::modules::ispa_dep_scanner::keyword_name::id: {
			return RulesStr::modules::ispa_dep_scanner::keyword_name::id;
			break;
		}
		case Rules::modules::ispa_dep_scanner::keyword_name::__grp2::id: {
			return RulesStr::modules::ispa_dep_scanner::keyword_name::__grp2::id;
			break;
		}
		case Rules::modules::ispa_dep_scanner::keyword_name::__q4::id: {
			return RulesStr::modules::ispa_dep_scanner::keyword_name::__q4::id;
			break;
		}
		case Rules::modules::ispa_dep_scanner::keyword_name::__q6::id: {
			return RulesStr::modules::ispa_dep_scanner::keyword_name::__q6::id;
			break;
		}
		case Rules::modules::ispa_dep_scanner::main::id: {
			return RulesStr::modules::ispa_dep_scanner::main::id;
			break;
		}
		case Rules::modules::ispa_dep_scanner::main::__grp0::id: {
			return RulesStr::modules::ispa_dep_scanner::main::__grp0::id;
			break;
		}
		case Rules::modules::ispa_dep_scanner::main::__grp0::__rop0::id: {
			return RulesStr::modules::ispa_dep_scanner::main::__grp0::__rop0::id;
			break;
		}
		case Rules::modules::ispa_dep_scanner::main::__grp0::__tail::id: {
			return RulesStr::modules::ispa_dep_scanner::main::__grp0::__tail::id;
			break;
		}
		case Rules::modules::ispa_dep_scanner::member::id: {
			return RulesStr::modules::ispa_dep_scanner::member::id;
			break;
		}
		case Rules::modules::ispa_dep_scanner::mod_detach::id: {
			return RulesStr::modules::ispa_dep_scanner::mod_detach::id;
			break;
		}
		case Rules::modules::ispa_dep_scanner::mod_detach::detach_value::id: {
			return RulesStr::modules::ispa_dep_scanner::mod_detach::detach_value::id;
			break;
		}
		case Rules::modules::ispa_dep_scanner::mod_detach::detach_value::feature::id: {
			return RulesStr::modules::ispa_dep_scanner::mod_detach::detach_value::feature::id;
			break;
		}
		case Rules::modules::ispa_dep_scanner::mod_import::id: {
			return RulesStr::modules::ispa_dep_scanner::mod_import::id;
			break;
		}
		case Rules::modules::ispa_dep_scanner::mod_import::import_value::id: {
			return RulesStr::modules::ispa_dep_scanner::mod_import::import_value::id;
			break;
		}
		case Rules::modules::ispa_dep_scanner::mod_import::import_value::from_import::id: {
			return RulesStr::modules::ispa_dep_scanner::mod_import::import_value::from_import::id;
			break;
		}
		case Rules::modules::ispa_dep_scanner::mod_import::import_value::from_import::selection::id: {
			return RulesStr::modules::ispa_dep_scanner::mod_import::import_value::from_import::selection::id;
			break;
		}
		case Rules::modules::ispa_dep_scanner::mod_import::import_value::from_import::selection::items::id: {
			return RulesStr::modules::ispa_dep_scanner::mod_import::import_value::from_import::selection::items::id;
			break;
		}
		case Rules::modules::ispa_dep_scanner::mod_import::import_value::from_import::selection::items::__grp4::id: {
			return RulesStr::modules::ispa_dep_scanner::mod_import::import_value::from_import::selection::items::__grp4::id;
			break;
		}
		case Rules::modules::ispa_dep_scanner::mod_import::import_value::from_import::selection::items::__grp4::__tail::id: {
			return RulesStr::modules::ispa_dep_scanner::mod_import::import_value::from_import::selection::items::__grp4::__tail::id;
			break;
		}
		case Rules::modules::ispa_dep_scanner::mod_import::import_value::module_import::id: {
			return RulesStr::modules::ispa_dep_scanner::mod_import::import_value::module_import::id;
			break;
		}
		case Rules::modules::ispa_dep_scanner::mod_import::import_value::module_import::__grp2::id: {
			return RulesStr::modules::ispa_dep_scanner::mod_import::import_value::module_import::__grp2::id;
			break;
		}
		case Rules::modules::ispa_dep_scanner::mod_module::id: {
			return RulesStr::modules::ispa_dep_scanner::mod_module::id;
			break;
		}
		case Rules::modules::ispa_dep_scanner::mod_module::__grp6::id: {
			return RulesStr::modules::ispa_dep_scanner::mod_module::__grp6::id;
			break;
		}
		case Rules::modules::ispa_dep_scanner::mod_module::__q4::id: {
			return RulesStr::modules::ispa_dep_scanner::mod_module::__q4::id;
			break;
		}
		case Rules::modules::ispa_dep_scanner::modifier::id: {
			return RulesStr::modules::ispa_dep_scanner::modifier::id;
			break;
		}
		case Rules::modules::ispa_dep_scanner::module_path::id: {
			return RulesStr::modules::ispa_dep_scanner::module_path::id;
			break;
		}
		case Rules::modules::ispa_dep_scanner::module_path::__grp2::id: {
			return RulesStr::modules::ispa_dep_scanner::module_path::__grp2::id;
			break;
		}
		case Rules::modules::ispa_dep_scanner::module_path::__grp2::__tail::id: {
			return RulesStr::modules::ispa_dep_scanner::module_path::__grp2::__tail::id;
			break;
		}
		case Rules::modules::ispa_dep_scanner::nested_rule::id: {
			return RulesStr::modules::ispa_dep_scanner::nested_rule::id;
			break;
		}
		case Rules::modules::ispa_dep_scanner::parentheses::id: {
			return RulesStr::modules::ispa_dep_scanner::parentheses::id;
			break;
		}
		case Rules::modules::ispa_dep_scanner::parentheses::__q2::id: {
			return RulesStr::modules::ispa_dep_scanner::parentheses::__q2::id;
			break;
		}
		case Rules::modules::ispa_dep_scanner::parentheses::__q2::__tail::id: {
			return RulesStr::modules::ispa_dep_scanner::parentheses::__q2::__tail::id;
			break;
		}
		case Rules::modules::ispa_dep_scanner::source_name::id: {
			return RulesStr::modules::ispa_dep_scanner::source_name::id;
			break;
		}
		case Rules::modules::ispa_dep_scanner::symbol_list::id: {
			return RulesStr::modules::ispa_dep_scanner::symbol_list::id;
			break;
		}
		case Rules::modules::ispa_dep_scanner::symbol_list::__grp2::id: {
			return RulesStr::modules::ispa_dep_scanner::symbol_list::__grp2::id;
			break;
		}
		case Rules::modules::ispa_dep_scanner::symbol_list::__grp2::__tail::id: {
			return RulesStr::modules::ispa_dep_scanner::symbol_list::__grp2::__tail::id;
			break;
		}
	}
	throw "Invalid Rules ID";
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
auto DepParser::FlatTypes::LESS_THAN_SIGN::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("LESS_THAN_SIGN", true);
}
auto DepParser::FlatTypes::LESS_THAN_SIGN::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::LESS_THAN_SIGN::to_string() const -> std::string {
	return ::ISPA_STD::concat("LESS_THAN_SIGN {", "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, LESS_THAN_SIGN value) -> std::ostream & {
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
auto DepParser::FlatTypes::modules_ispa_dep_scanner_LBRACE::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_ispa_dep_scanner_LBRACE", true);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_LBRACE::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_LBRACE::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_ispa_dep_scanner_LBRACE {", "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_ispa_dep_scanner_LBRACE value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::modules::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules", true);
}
auto DepParser::FlatTypes::modules::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules {", "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_ispa_dep_scanner", true);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_ispa_dep_scanner {", "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_ispa_dep_scanner value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_HASH::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_ispa_dep_scanner_HASH", true);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_HASH::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_HASH::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_ispa_dep_scanner_HASH {", "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_ispa_dep_scanner_HASH value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_ALL::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_ispa_dep_scanner_ALL", true);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_ALL::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_ALL::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_ispa_dep_scanner_ALL {", "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_ispa_dep_scanner_ALL value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_COLON::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_ispa_dep_scanner_COLON", true);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_COLON::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_COLON::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_ispa_dep_scanner_COLON {", "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_ispa_dep_scanner_COLON value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_DOT::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_ispa_dep_scanner_DOT", true);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_DOT::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_DOT::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_ispa_dep_scanner_DOT {", "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_ispa_dep_scanner_DOT value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_FAIL::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_ispa_dep_scanner_FAIL", true);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_FAIL::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_FAIL::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_ispa_dep_scanner_FAIL {", "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_ispa_dep_scanner_FAIL value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_FROM::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_ispa_dep_scanner_FROM", true);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_FROM::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_FROM::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_ispa_dep_scanner_FROM {", "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_ispa_dep_scanner_FROM value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_RBRACE::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_ispa_dep_scanner_RBRACE", true);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_RBRACE::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_RBRACE::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_ispa_dep_scanner_RBRACE {", "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_ispa_dep_scanner_RBRACE value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_FEATURE::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_ispa_dep_scanner_FEATURE", true);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_FEATURE::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_FEATURE::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_ispa_dep_scanner_FEATURE {", "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_ispa_dep_scanner_FEATURE value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_DETACH::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_ispa_dep_scanner_DETACH", true);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_DETACH::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_DETACH::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_ispa_dep_scanner_DETACH {", "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_ispa_dep_scanner_DETACH value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_IMPORT::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_ispa_dep_scanner_IMPORT", true);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_IMPORT::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_IMPORT::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_ispa_dep_scanner_IMPORT {", "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_ispa_dep_scanner_IMPORT value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_SEMI::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_ispa_dep_scanner_SEMI", true);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_SEMI::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_SEMI::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_ispa_dep_scanner_SEMI {", "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_ispa_dep_scanner_SEMI value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_COMMENT::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_ispa_dep_scanner_COMMENT", false);
	printer.up(false);
	printer.node_with_value("value", value, true);
	printer.down();
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_COMMENT::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_COMMENT::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_ispa_dep_scanner_COMMENT {", "value = ", value, "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_ispa_dep_scanner_COMMENT value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::modules_common_PY_RAW::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_common_PY_RAW", false);
	printer.up(false);
	printer.node_with_value("value", value, true);
	printer.down();
}
auto DepParser::FlatTypes::modules_common_PY_RAW::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_common_PY_RAW::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_common_PY_RAW {", "value = ", value, "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_common_PY_RAW value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::modules_common::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_common", true);
}
auto DepParser::FlatTypes::modules_common::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_common::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_common {", "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_common value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_MODULE::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_ispa_dep_scanner_MODULE", true);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_MODULE::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_MODULE::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_ispa_dep_scanner_MODULE {", "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_ispa_dep_scanner_MODULE value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_STRING::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_ispa_dep_scanner_STRING", false);
	printer.up(false);
	printer.node_with_value("value", value, true);
	printer.down();
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_STRING::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_STRING::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_ispa_dep_scanner_STRING {", "value = ", value, "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_ispa_dep_scanner_STRING value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::GREATER_THAN_SIGN::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("GREATER_THAN_SIGN", true);
}
auto DepParser::FlatTypes::GREATER_THAN_SIGN::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::GREATER_THAN_SIGN::to_string() const -> std::string {
	return ::ISPA_STD::concat("GREATER_THAN_SIGN {", "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, GREATER_THAN_SIGN value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_CGROUP::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_ispa_dep_scanner_CGROUP", false);
	printer.up(false);
	printer.node_with_value("value", value, true);
	printer.down();
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_CGROUP::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_CGROUP::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_ispa_dep_scanner_CGROUP {", "value = ", value, "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_ispa_dep_scanner_CGROUP value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::modules_common_ID::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_common_ID", false);
	printer.up(false);
	printer.node_with_value("value", value, true);
	printer.down();
}
auto DepParser::FlatTypes::modules_common_ID::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_common_ID::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_common_ID {", "value = ", value, "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_common_ID value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_AS::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_ispa_dep_scanner_AS", true);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_AS::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_AS::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_ispa_dep_scanner_AS {", "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_ispa_dep_scanner_AS value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_OTHER::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_ispa_dep_scanner_OTHER", false);
	printer.up(false);
	printer.node_with_value("value", value, true);
	printer.down();
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_OTHER::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_OTHER::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_ispa_dep_scanner_OTHER {", "value = ", value, "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_ispa_dep_scanner_OTHER value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::RIGHT_PARENTHESIS::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("RIGHT_PARENTHESIS", true);
}
auto DepParser::FlatTypes::RIGHT_PARENTHESIS::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::RIGHT_PARENTHESIS::to_string() const -> std::string {
	return ::ISPA_STD::concat("RIGHT_PARENTHESIS {", "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, RIGHT_PARENTHESIS value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::LEFT_PARENTHESIS::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("LEFT_PARENTHESIS", true);
}
auto DepParser::FlatTypes::LEFT_PARENTHESIS::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::LEFT_PARENTHESIS::to_string() const -> std::string {
	return ::ISPA_STD::concat("LEFT_PARENTHESIS {", "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, LEFT_PARENTHESIS value) -> std::ostream & {
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
auto DepParser::FlatTypes::modules_common_NUMBER::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_common_NUMBER", false);
	printer.up(false);
	printer.node_with_value("full", full, false);
	printer.node_with_value("floating", floating, true);
	printer.down();
}
auto DepParser::FlatTypes::modules_common_NUMBER::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_common_NUMBER::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_common_NUMBER {", "full = ", full, ", ", "floating = ", floating, "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_common_NUMBER value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::modules_common_name___grp2::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_common_name___grp2", true);
}
auto DepParser::FlatTypes::modules_common_name___grp2::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_common_name___grp2::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_common_name___grp2 {", "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_common_name___grp2 value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::modules_common_name___grp2___tail::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_common_name___grp2___tail", true);
}
auto DepParser::FlatTypes::modules_common_name___grp2___tail::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_common_name___grp2___tail::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_common_name___grp2___tail {", "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_common_name___grp2___tail value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::modules_common_name___q4::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_common_name___q4", true);
}
auto DepParser::FlatTypes::modules_common_name___q4::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_common_name___q4::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_common_name___q4 {", "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_common_name___q4 value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::modules_common_name___q6::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_common_name___q6", true);
}
auto DepParser::FlatTypes::modules_common_name___q6::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_common_name___q6::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_common_name___q6 {", "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_common_name___q6 value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::modules_common_param___grp2::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_common_param___grp2", true);
}
auto DepParser::FlatTypes::modules_common_param___grp2::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_common_param___grp2::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_common_param___grp2 {", "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_common_param___grp2 value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::modules_common_param___grp2___tail::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_common_param___grp2___tail", true);
}
auto DepParser::FlatTypes::modules_common_param___grp2___tail::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_common_param___grp2___tail::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_common_param___grp2___tail {", "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_common_param___grp2___tail value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::modules_common_params___q4::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_common_params___q4", true);
}
auto DepParser::FlatTypes::modules_common_params___q4::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_common_params___q4::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_common_params___q4 {", "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_common_params___q4 value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::modules_common_template_params___q2::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_common_template_params___q2", true);
}
auto DepParser::FlatTypes::modules_common_template_params___q2::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_common_template_params___q2::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_common_template_params___q2 {", "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_common_template_params___q2 value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_atom::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_ispa_dep_scanner_atom", true);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_atom::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_atom::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_ispa_dep_scanner_atom {", "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_ispa_dep_scanner_atom value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_balanced_item::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_ispa_dep_scanner_balanced_item", true);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_balanced_item::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_balanced_item::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_ispa_dep_scanner_balanced_item {", "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_ispa_dep_scanner_balanced_item value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_body_regular::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_ispa_dep_scanner_body_regular", false);
	printer.up(false);
	printer.subtree("value", value, true);
	printer.down();
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_body_regular::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_body_regular::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_ispa_dep_scanner_body_regular {", "value = ", value, "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_ispa_dep_scanner_body_regular value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_body_regular___q2::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_ispa_dep_scanner_body_regular___q2", true);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_body_regular___q2::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_body_regular___q2::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_ispa_dep_scanner_body_regular___q2 {", "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_ispa_dep_scanner_body_regular___q2 value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_body_regular___q2___tail::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_ispa_dep_scanner_body_regular___q2___tail", true);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_body_regular___q2___tail::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_body_regular___q2___tail::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_ispa_dep_scanner_body_regular___q2___tail {", "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_ispa_dep_scanner_body_regular___q2___tail value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_braces::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_ispa_dep_scanner_braces", true);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_braces::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_braces::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_ispa_dep_scanner_braces {", "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_ispa_dep_scanner_braces value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_braces___q2::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_ispa_dep_scanner_braces___q2", true);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_braces___q2::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_braces___q2::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_ispa_dep_scanner_braces___q2 {", "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_ispa_dep_scanner_braces___q2 value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_braces___q2___tail::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_ispa_dep_scanner_braces___q2___tail", true);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_braces___q2___tail::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_braces___q2___tail::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_ispa_dep_scanner_braces___q2___tail {", "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_ispa_dep_scanner_braces___q2___tail value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_declaration___q0::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_ispa_dep_scanner_declaration___q0", true);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_declaration___q0::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_declaration___q0::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_ispa_dep_scanner_declaration___q0 {", "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_ispa_dep_scanner_declaration___q0 value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_declaration___q0___tail::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_ispa_dep_scanner_declaration___q0___tail", true);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_declaration___q0___tail::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_declaration___q0___tail::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_ispa_dep_scanner_declaration___q0___tail {", "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_ispa_dep_scanner_declaration___q0___tail value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_fail_decl::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_ispa_dep_scanner_fail_decl", true);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_fail_decl::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_fail_decl::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_ispa_dep_scanner_fail_decl {", "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_ispa_dep_scanner_fail_decl value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_feature_decl___q6::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_ispa_dep_scanner_feature_decl___q6", true);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_feature_decl___q6::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_feature_decl___q6::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_ispa_dep_scanner_feature_decl___q6 {", "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_ispa_dep_scanner_feature_decl___q6 value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_keyword_name___grp2::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_ispa_dep_scanner_keyword_name___grp2", true);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_keyword_name___grp2::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_keyword_name___grp2::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_ispa_dep_scanner_keyword_name___grp2 {", "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_ispa_dep_scanner_keyword_name___grp2 value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_keyword_name___q4::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_ispa_dep_scanner_keyword_name___q4", true);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_keyword_name___q4::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_keyword_name___q4::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_ispa_dep_scanner_keyword_name___q4 {", "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_ispa_dep_scanner_keyword_name___q4 value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_keyword_name___q6::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_ispa_dep_scanner_keyword_name___q6", true);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_keyword_name___q6::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_keyword_name___q6::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_ispa_dep_scanner_keyword_name___q6 {", "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_ispa_dep_scanner_keyword_name___q6 value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_main___grp0::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_ispa_dep_scanner_main___grp0", true);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_main___grp0::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_main___grp0::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_ispa_dep_scanner_main___grp0 {", "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_ispa_dep_scanner_main___grp0 value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_main___grp0___rop0::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_ispa_dep_scanner_main___grp0___rop0", true);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_main___grp0___rop0::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_main___grp0___rop0::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_ispa_dep_scanner_main___grp0___rop0 {", "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_ispa_dep_scanner_main___grp0___rop0 value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_main___grp0___tail::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_ispa_dep_scanner_main___grp0___tail", true);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_main___grp0___tail::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_main___grp0___tail::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_ispa_dep_scanner_main___grp0___tail {", "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_ispa_dep_scanner_main___grp0___tail value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_mod_import_import_value_from_import_selection_items___grp4::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_ispa_dep_scanner_mod_import_import_value_from_import_selection_items___grp4", true);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_mod_import_import_value_from_import_selection_items___grp4::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_mod_import_import_value_from_import_selection_items___grp4::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_ispa_dep_scanner_mod_import_import_value_from_import_selection_items___grp4 {", "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_ispa_dep_scanner_mod_import_import_value_from_import_selection_items___grp4 value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_mod_import_import_value_from_import_selection_items___grp4___tail::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_ispa_dep_scanner_mod_import_import_value_from_import_selection_items___grp4___tail", true);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_mod_import_import_value_from_import_selection_items___grp4___tail::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_mod_import_import_value_from_import_selection_items___grp4___tail::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_ispa_dep_scanner_mod_import_import_value_from_import_selection_items___grp4___tail {", "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_ispa_dep_scanner_mod_import_import_value_from_import_selection_items___grp4___tail value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_mod_import_import_value_module_import___grp2::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_ispa_dep_scanner_mod_import_import_value_module_import___grp2", true);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_mod_import_import_value_module_import___grp2::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_mod_import_import_value_module_import___grp2::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_ispa_dep_scanner_mod_import_import_value_module_import___grp2 {", "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_ispa_dep_scanner_mod_import_import_value_module_import___grp2 value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_mod_module___grp6::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_ispa_dep_scanner_mod_module___grp6", true);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_mod_module___grp6::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_mod_module___grp6::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_ispa_dep_scanner_mod_module___grp6 {", "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_ispa_dep_scanner_mod_module___grp6 value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_mod_module___q4::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_ispa_dep_scanner_mod_module___q4", true);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_mod_module___q4::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_mod_module___q4::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_ispa_dep_scanner_mod_module___q4 {", "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_ispa_dep_scanner_mod_module___q4 value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_modifier::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_ispa_dep_scanner_modifier", true);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_modifier::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_modifier::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_ispa_dep_scanner_modifier {", "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_ispa_dep_scanner_modifier value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_module_path___grp2::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_ispa_dep_scanner_module_path___grp2", true);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_module_path___grp2::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_module_path___grp2::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_ispa_dep_scanner_module_path___grp2 {", "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_ispa_dep_scanner_module_path___grp2 value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_module_path___grp2___tail::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_ispa_dep_scanner_module_path___grp2___tail", true);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_module_path___grp2___tail::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_module_path___grp2___tail::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_ispa_dep_scanner_module_path___grp2___tail {", "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_ispa_dep_scanner_module_path___grp2___tail value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_nested_rule::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_ispa_dep_scanner_nested_rule", false);
	printer.up(false);
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_nested_rule::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_nested_rule::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_ispa_dep_scanner_nested_rule {", "value = ", value.to_string(), "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_ispa_dep_scanner_nested_rule value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_parentheses::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_ispa_dep_scanner_parentheses", true);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_parentheses::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_parentheses::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_ispa_dep_scanner_parentheses {", "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_ispa_dep_scanner_parentheses value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_parentheses___q2::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_ispa_dep_scanner_parentheses___q2", true);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_parentheses___q2::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_parentheses___q2::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_ispa_dep_scanner_parentheses___q2 {", "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_ispa_dep_scanner_parentheses___q2 value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_parentheses___q2___tail::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_ispa_dep_scanner_parentheses___q2___tail", true);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_parentheses___q2___tail::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_parentheses___q2___tail::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_ispa_dep_scanner_parentheses___q2___tail {", "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_ispa_dep_scanner_parentheses___q2___tail value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_symbol_list___grp2::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_ispa_dep_scanner_symbol_list___grp2", true);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_symbol_list___grp2::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_symbol_list___grp2::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_ispa_dep_scanner_symbol_list___grp2 {", "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_ispa_dep_scanner_symbol_list___grp2 value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_symbol_list___grp2___tail::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_ispa_dep_scanner_symbol_list___grp2___tail", true);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_symbol_list___grp2___tail::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_symbol_list___grp2___tail::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_ispa_dep_scanner_symbol_list___grp2___tail {", "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_ispa_dep_scanner_symbol_list___grp2___tail value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::modules_common_param::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_common_param", false);
	printer.up(false);
	printer.node("first_p", false);
	printer.up(true);
	first_p.print(printer);
	printer.down();
	printer.subtree("following_p", following_p, true);
	printer.down();
}
auto DepParser::FlatTypes::modules_common_param::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_common_param::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_common_param {", "first_p = ", first_p.to_string(), ", ", "following_p = ", following_p, "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_common_param value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_identifier::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_ispa_dep_scanner_identifier", false);
	printer.up(false);
	printer.node_with_value("value", value, true);
	printer.down();
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_identifier::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_identifier::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_ispa_dep_scanner_identifier {", "value = ", value, "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_ispa_dep_scanner_identifier value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_keyword::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_ispa_dep_scanner_keyword", false);
	printer.up(false);
	printer.node_with_value("value", value, true);
	printer.down();
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_keyword::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_keyword::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_ispa_dep_scanner_keyword {", "value = ", value, "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_ispa_dep_scanner_keyword value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_body::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_ispa_dep_scanner_body", false);
	printer.up(false);
	printer.node_with_value("value", value, true);
	printer.down();
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_body::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_body::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_ispa_dep_scanner_body {", "value = ", value, "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_ispa_dep_scanner_body value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_member::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_ispa_dep_scanner_member", false);
	printer.up(false);
	printer.node_with_value("value", value, true);
	printer.down();
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_member::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_member::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_ispa_dep_scanner_member {", "value = ", value, "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_ispa_dep_scanner_member value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::modules_common_params::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_common_params", false);
	printer.up(false);
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto DepParser::FlatTypes::modules_common_params::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_common_params::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_common_params {", "value = ", value.to_string(), "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_common_params value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::modules_common_template_params::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_common_template_params", false);
	printer.up(false);
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto DepParser::FlatTypes::modules_common_template_params::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_common_template_params::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_common_template_params {", "value = ", value.to_string(), "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_common_template_params value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_module_path::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_ispa_dep_scanner_module_path", false);
	printer.up(false);
	printer.node("primary", false);
	printer.up(true);
	primary.print(printer);
	printer.down();
	printer.subtree("nested", nested, true);
	printer.down();
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_module_path::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_module_path::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_ispa_dep_scanner_module_path {", "primary = ", primary.to_string(), ", ", "nested = ", nested, "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_ispa_dep_scanner_module_path value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::modules_common_name::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
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
auto DepParser::FlatTypes::modules_common_name::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_common_name::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_common_name {", "primary = ", primary.to_string(), ", ", "nested = ", nested, ", ", "temp_params = ", temp_params.to_string(), ", ", "param = ", param.to_string(), "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_common_name value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_mod_import_import_value_module_import::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_ispa_dep_scanner_mod_import_import_value_module_import", false);
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
auto DepParser::FlatTypes::modules_ispa_dep_scanner_mod_import_import_value_module_import::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_mod_import_import_value_module_import::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_ispa_dep_scanner_mod_import_import_value_module_import {", "source = ", source.to_string(), ", ", "alias = ", alias.to_string(), "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_ispa_dep_scanner_mod_import_import_value_module_import value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_keyword_name::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_ispa_dep_scanner_keyword_name", false);
	printer.up(false);
	printer.node("primary", false);
	printer.up(true);
	primary.print(printer);
	printer.down();
	printer.node("tail", false);
	printer.up(true);
	tail.print(printer);
	printer.down();
	printer.node("templates", false);
	printer.up(true);
	templates.print(printer);
	printer.down();
	printer.node("parameters", true);
	printer.up(false);
	parameters.print(printer);
	printer.down();
	printer.down();
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_keyword_name::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_keyword_name::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_ispa_dep_scanner_keyword_name {", "primary = ", primary.to_string(), ", ", "tail = ", tail.to_string(), ", ", "templates = ", templates.to_string(), ", ", "parameters = ", parameters.to_string(), "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_ispa_dep_scanner_keyword_name value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_source_name::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_ispa_dep_scanner_source_name", false);
	printer.up(false);
	printer.node_with_value("value", value, true);
	printer.down();
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_source_name::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_source_name::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_ispa_dep_scanner_source_name {", "value = ", value, "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_ispa_dep_scanner_source_name value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_declaration::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_ispa_dep_scanner_declaration", false);
	printer.up(false);
	printer.subtree("modifiers", modifiers, false);
	printer.node("name", false);
	printer.up(true);
	name.print(printer);
	printer.down();
	printer.node("body", true);
	printer.up(false);
	body.print(printer);
	printer.down();
	printer.down();
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_declaration::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_declaration::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_ispa_dep_scanner_declaration {", "modifiers = ", modifiers, ", ", "name = ", name.to_string(), ", ", "body = ", body.to_string(), "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_ispa_dep_scanner_declaration value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_mod_detach_detach_value_feature::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_ispa_dep_scanner_mod_detach_detach_value_feature", false);
	printer.up(false);
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_mod_detach_detach_value_feature::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_mod_detach_detach_value_feature::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_ispa_dep_scanner_mod_detach_detach_value_feature {", "value = ", value.to_string(), "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_ispa_dep_scanner_mod_detach_detach_value_feature value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_mod_import_import_value_from_import_selection_items::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_ispa_dep_scanner_mod_import_import_value_from_import_selection_items", false);
	printer.up(false);
	printer.node("first", false);
	printer.up(true);
	first.print(printer);
	printer.down();
	printer.subtree("sequence", sequence, true);
	printer.down();
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_mod_import_import_value_from_import_selection_items::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_mod_import_import_value_from_import_selection_items::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_ispa_dep_scanner_mod_import_import_value_from_import_selection_items {", "first = ", first.to_string(), ", ", "sequence = ", sequence, "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_ispa_dep_scanner_mod_import_import_value_from_import_selection_items value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_mod_module::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_ispa_dep_scanner_mod_module", false);
	printer.up(false);
	printer.node("begin", false);
	printer.up(true);
	begin.print(printer);
	printer.down();
	printer.node("name", false);
	printer.up(true);
	name.print(printer);
	printer.down();
	printer.node("parameters", false);
	printer.up(true);
	parameters.print(printer);
	printer.down();
	printer.node("entry", false);
	printer.up(true);
	entry.print(printer);
	printer.down();
	printer.node("end", true);
	printer.up(false);
	end.print(printer);
	printer.down();
	printer.down();
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_mod_module::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_mod_module::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_ispa_dep_scanner_mod_module {", "begin = ", begin.to_string(), ", ", "name = ", name.to_string(), ", ", "parameters = ", parameters.to_string(), ", ", "entry = ", entry.to_string(), ", ", "end = ", end.to_string(), "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_ispa_dep_scanner_mod_module value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_symbol_list::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_ispa_dep_scanner_symbol_list", false);
	printer.up(false);
	printer.node("first", false);
	printer.up(true);
	first.print(printer);
	printer.down();
	printer.subtree("following", following, true);
	printer.down();
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_symbol_list::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_symbol_list::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_ispa_dep_scanner_symbol_list {", "first = ", first.to_string(), ", ", "following = ", following, "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_ispa_dep_scanner_symbol_list value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_mod_detach_detach_value::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_ispa_dep_scanner_mod_detach_detach_value", false);
	printer.up(false);
	printer.node_with_value("value", value, true);
	printer.down();
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_mod_detach_detach_value::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_mod_detach_detach_value::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_ispa_dep_scanner_mod_detach_detach_value {", "value = ", value, "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_ispa_dep_scanner_mod_detach_detach_value value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_mod_import_import_value_from_import_selection::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_ispa_dep_scanner_mod_import_import_value_from_import_selection", false);
	printer.up(false);
	printer.node_with_value("value", value, true);
	printer.down();
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_mod_import_import_value_from_import_selection::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_mod_import_import_value_from_import_selection::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_ispa_dep_scanner_mod_import_import_value_from_import_selection {", "value = ", value, "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_ispa_dep_scanner_mod_import_import_value_from_import_selection value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_feature_decl::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_ispa_dep_scanner_feature_decl", false);
	printer.up(false);
	printer.node("begin", false);
	printer.up(true);
	begin.print(printer);
	printer.down();
	printer.node("name", false);
	printer.up(true);
	name.print(printer);
	printer.down();
	printer.node("symbols", false);
	printer.up(true);
	symbols.print(printer);
	printer.down();
	printer.node("end", true);
	printer.up(false);
	end.print(printer);
	printer.down();
	printer.down();
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_feature_decl::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_feature_decl::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_ispa_dep_scanner_feature_decl {", "begin = ", begin.to_string(), ", ", "name = ", name.to_string(), ", ", "symbols = ", symbols.to_string(), ", ", "end = ", end.to_string(), "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_ispa_dep_scanner_feature_decl value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_mod_detach::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_ispa_dep_scanner_mod_detach", false);
	printer.up(false);
	printer.node("begin", false);
	printer.up(true);
	begin.print(printer);
	printer.down();
	printer.node("value", false);
	printer.up(true);
	value.print(printer);
	printer.down();
	printer.node("end", true);
	printer.up(false);
	end.print(printer);
	printer.down();
	printer.down();
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_mod_detach::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_mod_detach::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_ispa_dep_scanner_mod_detach {", "begin = ", begin.to_string(), ", ", "value = ", value.to_string(), ", ", "end = ", end.to_string(), "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_ispa_dep_scanner_mod_detach value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_mod_import_import_value_from_import::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_ispa_dep_scanner_mod_import_import_value_from_import", false);
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
auto DepParser::FlatTypes::modules_ispa_dep_scanner_mod_import_import_value_from_import::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_mod_import_import_value_from_import::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_ispa_dep_scanner_mod_import_import_value_from_import {", "sel = ", sel.to_string(), ", ", "source = ", source.to_string(), "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_ispa_dep_scanner_mod_import_import_value_from_import value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_mod_import_import_value::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_ispa_dep_scanner_mod_import_import_value", false);
	printer.up(false);
	printer.node_with_value("value", value, true);
	printer.down();
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_mod_import_import_value::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_mod_import_import_value::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_ispa_dep_scanner_mod_import_import_value {", "value = ", value, "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_ispa_dep_scanner_mod_import_import_value value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_mod_import::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_ispa_dep_scanner_mod_import", false);
	printer.up(false);
	printer.node("begin", false);
	printer.up(true);
	begin.print(printer);
	printer.down();
	printer.node("value", false);
	printer.up(true);
	value.print(printer);
	printer.down();
	printer.node("end", true);
	printer.up(false);
	end.print(printer);
	printer.down();
	printer.down();
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_mod_import::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_mod_import::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_ispa_dep_scanner_mod_import {", "begin = ", begin.to_string(), ", ", "value = ", value.to_string(), ", ", "end = ", end.to_string(), "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_ispa_dep_scanner_mod_import value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_main::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_ispa_dep_scanner_main", false);
	printer.up(false);
	printer.node_with_value("value", value, true);
	printer.down();
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_main::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_main::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_ispa_dep_scanner_main {", "value = ", value, "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_ispa_dep_scanner_main value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::main::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("main", false);
	printer.up(false);
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto DepParser::FlatTypes::main::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::main::to_string() const -> std::string {
	return ::ISPA_STD::concat("main {", "value = ", value.to_string(), "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, main value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::Lexer::semantic_action_exec(long long state, const ::ISPA_STD::DFA::API::Captures& captures, long long start_pos, const char* start, long long length, long long line) -> std::pair<long long, Token> {
	switch (state) {
		case 0: {
			char value = captures.character(0);
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::modules::ispa_dep_scanner::OTHER::id, Types::modules::ispa_dep_scanner::OTHER{value}));
			break;
		}
		case 1: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::__WS::id, Types::__WS{}));
			break;
		}
		case 2: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::modules::ispa_dep_scanner::HASH::id, Types::modules::ispa_dep_scanner::HASH{}));
			break;
		}
		case 3: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::LEFT_PARENTHESIS::id, Types::LEFT_PARENTHESIS{}));
			break;
		}
		case 4: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::RIGHT_PARENTHESIS::id, Types::RIGHT_PARENTHESIS{}));
			break;
		}
		case 5: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::modules::ispa_dep_scanner::ALL::id, Types::modules::ispa_dep_scanner::ALL{}));
			break;
		}
		case 6: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::COMMA::id, Types::COMMA{}));
			break;
		}
		case 7: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::modules::ispa_dep_scanner::DOT::id, Types::modules::ispa_dep_scanner::DOT{}));
			break;
		}
		case 8: {
			std::string floating = captures.text(5);
			std::string full = captures.text(4);
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::modules::common::NUMBER::id, Types::modules::common::NUMBER{full, floating}));
			break;
		}
		case 9: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::modules::ispa_dep_scanner::COLON::id, Types::modules::ispa_dep_scanner::COLON{}));
			break;
		}
		case 10: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::modules::ispa_dep_scanner::SEMI::id, Types::modules::ispa_dep_scanner::SEMI{}));
			break;
		}
		case 11: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::LESS_THAN_SIGN::id, Types::LESS_THAN_SIGN{}));
			break;
		}
		case 12: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::GREATER_THAN_SIGN::id, Types::GREATER_THAN_SIGN{}));
			break;
		}
		case 13: {
			std::string value = captures.text(1);
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::modules::common::ID::id, Types::modules::common::ID{value}));
			break;
		}
		case 14: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::modules::ispa_dep_scanner::LBRACE::id, Types::modules::ispa_dep_scanner::LBRACE{}));
			break;
		}
		case 15: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::modules::ispa_dep_scanner::RBRACE::id, Types::modules::ispa_dep_scanner::RBRACE{}));
			break;
		}
		case 16: {
			std::string value = captures.text(8);
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::modules::ispa_dep_scanner::STRING::id, Types::modules::ispa_dep_scanner::STRING{value}));
			break;
		}
		case 17: {
			std::string value = captures.text(8);
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::modules::ispa_dep_scanner::STRING::id, Types::modules::ispa_dep_scanner::STRING{value}));
			break;
		}
		case 18: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::AUTO::id, Types::AUTO{}));
			break;
		}
		case 19: {
			std::string value = captures.text(6);
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::modules::ispa_dep_scanner::COMMENT::id, Types::modules::ispa_dep_scanner::COMMENT{value}));
			break;
		}
		case 20: {
			std::string value = captures.text(1);
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::modules::common::ID::id, Types::modules::common::ID{value}));
			break;
		}
		case 21: {
			char value = captures.character(2);
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::modules::ispa_dep_scanner::CGROUP::id, Types::modules::ispa_dep_scanner::CGROUP{value}));
			break;
		}
		case 22: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::modules::ispa_dep_scanner::AS::id, Types::modules::ispa_dep_scanner::AS{}));
			break;
		}
		case 23: {
			std::string value = captures.text(6);
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::modules::ispa_dep_scanner::COMMENT::id, Types::modules::ispa_dep_scanner::COMMENT{value}));
			break;
		}
		case 24: {
			std::string floating = captures.text(5);
			std::string full = captures.text(4);
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::modules::common::NUMBER::id, Types::modules::common::NUMBER{full, floating}));
			break;
		}
		case 25: {
			std::string value = captures.text(6);
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::modules::ispa_dep_scanner::COMMENT::id, Types::modules::ispa_dep_scanner::COMMENT{value}));
			break;
		}
		case 26: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::modules::ispa_dep_scanner::FAIL::id, Types::modules::ispa_dep_scanner::FAIL{}));
			break;
		}
		case 27: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::modules::ispa_dep_scanner::FROM::id, Types::modules::ispa_dep_scanner::FROM{}));
			break;
		}
		case 28: {
			std::string value = captures.text(3);
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::modules::common::PY_RAW::id, Types::modules::common::PY_RAW{value}));
			break;
		}
		case 29: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::modules::ispa_dep_scanner::DETACH::id, Types::modules::ispa_dep_scanner::DETACH{}));
			break;
		}
		case 30: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::modules::ispa_dep_scanner::IMPORT::id, Types::modules::ispa_dep_scanner::IMPORT{}));
			break;
		}
		case 31: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::modules::ispa_dep_scanner::MODULE::id, Types::modules::ispa_dep_scanner::MODULE{}));
			break;
		}
		case 32: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::modules::ispa_dep_scanner::FEATURE::id, Types::modules::ispa_dep_scanner::FEATURE{}));
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
::ISPA_STD::DFA::API::CharToClass DepParser::Lexer::char_class_table = {0, 1, 1, 1, 1, 1, 1, 1, 1, 2, 3, 2, 2, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 4, 5, 1, 1, 1, 6, 7, 8, 9, 1, 10, 11, 12, 13, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 15, 16, 17, 1, 18, 1, 1, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 20, 21, 22, 1, 19, 1, 23, 19, 24, 25, 26, 27, 19, 28, 29, 19, 19, 30, 31, 19, 32, 33, 19, 34, 35, 36, 37, 19, 19, 19, 38, 19, 39, 1, 40, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
::ISPA_STD::DFA::API::Table<76, 41> DepParser::Lexer::dfa_table = {{{::ISPA_STD::DFA::API::null_state, 76, 2, 2, 87, 4, 86, 6, 7, 8, 9, 85, 11, 84, 83, 14, 15, 16, 17, 77, 82, 76, ::ISPA_STD::DFA::API::null_state, 81, 77, 89, 77, 88, 77, 80, 77, 79, 77, 78, 77, 77, 77, 77, 77, 26, 27}, {90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90}, {170, 170, 2, 2, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170}, {::ISPA_STD::DFA::API::null_state, 3, 3, 3, 28, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 29, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3}, {171, 171, 171, 171, 171, 171, 171, 171, 171, 171, 171, 171, 171, 171, 171, 171, 171, 171, 171, 171, 171, 171, 171, 171, 171, 171, 171, 171, 171, 171, 171, 171, 171, 171, 171, 171, 171, 171, 171, 171, 171}, {::ISPA_STD::DFA::API::null_state, 5, 5, 5, 5, 5, 30, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 31, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5}, {172, 172, 172, 172, 172, 172, 172, 172, 172, 172, 172, 172, 172, 172, 172, 172, 172, 172, 172, 172, 172, 172, 172, 172, 172, 172, 172, 172, 172, 172, 172, 172, 172, 172, 172, 172, 172, 172, 172, 172, 172}, {173, 173, 173, 173, 173, 173, 173, 173, 173, 173, 173, 173, 173, 173, 173, 173, 173, 173, 173, 173, 173, 173, 173, 173, 173, 173, 173, 173, 173, 173, 173, 173, 173, 173, 173, 173, 173, 173, 173, 173, 173}, {174, 174, 174, 174, 174, 174, 174, 174, 174, 174, 174, 174, 174, 174, 174, 174, 174, 174, 174, 174, 174, 174, 174, 174, 174, 174, 174, 174, 174, 174, 174, 174, 174, 174, 174, 174, 174, 174, 174, 174, 174}, {175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175}, {92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 32, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92}, {176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176}, {94, 94, 94, 94, 94, 94, 94, 94, 94, 33, 94, 94, 94, 34, 94, 94, 94, 94, 94, 94, 94, 94, 94, 94, 94, 94, 94, 94, 94, 94, 94, 94, 94, 94, 94, 94, 94, 94, 94, 94, 94}, {95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 96, 95, 13, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95}, {178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178}, {179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179}, {180, 180, 180, 180, 180, 180, 180, 180, 180, 180, 180, 180, 180, 180, 180, 180, 180, 180, 180, 180, 180, 180, 180, 180, 180, 180, 180, 180, 180, 180, 180, 180, 180, 180, 180, 180, 180, 180, 180, 180, 180}, {181, 181, 181, 181, 181, 181, 181, 181, 181, 181, 181, 181, 181, 181, 181, 181, 181, 181, 181, 181, 181, 181, 181, 181, 181, 181, 181, 181, 181, 181, 181, 181, 181, 181, 181, 181, 181, 181, 181, 181, 181}, {97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 36, 97, 97, 97, 97, 36, 97, 97, 97, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 97, 97}, {::ISPA_STD::DFA::API::null_state, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 100, 99, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98}, {102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 103, 102, 102, 102, 102, 103, 102, 102, 102, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 40, 103, 103, 103, 102, 102}, {105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 103, 105, 105, 105, 105, 103, 105, 105, 105, 103, 103, 103, 41, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 105, 105}, {107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 103, 107, 107, 107, 107, 103, 107, 107, 107, 42, 103, 103, 43, 103, 103, 103, 103, 103, 103, 103, 44, 103, 103, 103, 103, 107, 107}, {109, 109, 109, 109, 109, 109, 109, 109, 109, 109, 109, 109, 109, 109, 103, 109, 109, 109, 109, 103, 109, 109, 109, 103, 103, 103, 103, 103, 103, 103, 103, 45, 103, 103, 103, 103, 103, 103, 103, 109, 109}, {111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 103, 111, 111, 111, 111, 103, 111, 111, 111, 103, 103, 103, 103, 103, 103, 103, 103, 103, 46, 103, 103, 103, 103, 103, 103, 111, 111}, {113, 113, 113, 113, 113, 113, 113, 113, 113, 113, 113, 113, 113, 113, 103, 113, 113, 113, 113, 103, 113, 113, 113, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 47, 113}, {183, 183, 183, 183, 183, 183, 183, 183, 183, 183, 183, 183, 183, 183, 183, 183, 183, 183, 183, 183, 183, 183, 183, 183, 183, 183, 183, 183, 183, 183, 183, 183, 183, 183, 183, 183, 183, 183, 183, 183, 183}, {184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184}, {114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114}, {::ISPA_STD::DFA::API::null_state, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3}, {115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115}, {::ISPA_STD::DFA::API::null_state, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5}, {187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187}, {::ISPA_STD::DFA::API::null_state, 33, 33, 33, 33, 33, 33, 33, 33, 48, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33}, {117, 49, 49, 117, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49}, {::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, 118, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state}, {119, 119, 119, 119, 119, 119, 119, 119, 119, 119, 119, 119, 119, 119, 36, 119, 119, 119, 119, 36, 119, 119, 119, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 119, 119}, {::ISPA_STD::DFA::API::null_state, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 38, 39, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37}, {::ISPA_STD::DFA::API::null_state, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37}, {190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190}, {191, 191, 191, 191, 191, 191, 191, 191, 191, 191, 191, 191, 191, 191, 103, 191, 191, 191, 191, 103, 191, 191, 191, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 191, 191}, {121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 103, 121, 121, 121, 121, 103, 121, 121, 121, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 51, 103, 103, 121, 121}, {123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 103, 123, 123, 123, 123, 103, 123, 123, 123, 103, 103, 103, 103, 103, 103, 52, 103, 103, 103, 103, 103, 103, 103, 103, 103, 123, 123}, {125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 103, 125, 125, 125, 125, 103, 125, 125, 125, 53, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 125, 125}, {127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 103, 127, 127, 127, 127, 103, 127, 127, 127, 103, 103, 103, 103, 103, 103, 103, 103, 103, 54, 103, 103, 103, 103, 103, 103, 127, 127}, {129, 129, 129, 129, 129, 129, 129, 129, 129, 129, 129, 129, 129, 129, 103, 129, 129, 129, 129, 103, 129, 129, 129, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 55, 103, 103, 103, 103, 103, 129, 129}, {131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 103, 131, 131, 131, 131, 103, 131, 131, 131, 103, 103, 56, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 131, 131}, {::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, 132, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state}, {::ISPA_STD::DFA::API::null_state, 33, 33, 33, 33, 33, 33, 33, 33, 48, 33, 33, 33, 58, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33}, {134, 49, 49, 134, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49}, {135, 135, 135, 135, 135, 135, 135, 135, 135, 135, 135, 135, 135, 135, 50, 135, 135, 135, 135, 135, 135, 135, 135, 135, 135, 135, 135, 135, 135, 135, 135, 135, 135, 135, 135, 135, 135, 135, 135, 135, 135}, {137, 137, 137, 137, 137, 137, 137, 137, 137, 137, 137, 137, 137, 137, 103, 137, 137, 137, 137, 103, 137, 137, 137, 59, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 137, 137}, {139, 139, 139, 139, 139, 139, 139, 139, 139, 139, 139, 139, 139, 139, 103, 139, 139, 139, 139, 103, 139, 139, 139, 103, 103, 103, 103, 103, 103, 103, 60, 103, 103, 103, 103, 103, 103, 103, 103, 139, 139}, {141, 141, 141, 141, 141, 141, 141, 141, 141, 141, 141, 141, 141, 141, 103, 141, 141, 141, 141, 103, 141, 141, 141, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 61, 103, 103, 141, 141}, {143, 143, 143, 143, 143, 143, 143, 143, 143, 143, 143, 143, 143, 143, 103, 143, 143, 143, 143, 103, 143, 143, 143, 103, 103, 103, 103, 103, 103, 103, 103, 62, 103, 103, 103, 103, 103, 103, 103, 143, 143}, {145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 103, 145, 145, 145, 145, 103, 145, 145, 145, 103, 103, 103, 103, 103, 103, 103, 103, 103, 63, 103, 103, 103, 103, 103, 103, 145, 145}, {147, 147, 147, 147, 147, 147, 147, 147, 147, 147, 147, 147, 147, 147, 103, 147, 147, 147, 147, 103, 147, 147, 147, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 64, 103, 147, 147}, {::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, 65, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state}, {149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149}, {151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 103, 151, 151, 151, 151, 103, 151, 151, 151, 103, 66, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 151, 151}, {195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 103, 195, 195, 195, 195, 103, 195, 195, 195, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 195, 195}, {153, 153, 153, 153, 153, 153, 153, 153, 153, 153, 153, 153, 153, 153, 103, 153, 153, 153, 153, 103, 153, 153, 153, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 67, 103, 153, 153}, {196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 103, 196, 196, 196, 196, 103, 196, 196, 196, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 196, 196}, {155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 103, 155, 155, 155, 155, 103, 155, 155, 155, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 68, 103, 103, 103, 103, 155, 155}, {157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 103, 157, 157, 157, 157, 103, 157, 157, 157, 103, 103, 103, 103, 103, 103, 103, 69, 103, 103, 103, 103, 103, 103, 103, 103, 157, 157}, {::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, 158}, {160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 103, 160, 160, 160, 160, 103, 160, 160, 160, 103, 103, 103, 103, 103, 71, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 160, 160}, {162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 103, 162, 162, 162, 162, 103, 162, 162, 162, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 72, 103, 103, 103, 103, 162, 162}, {164, 164, 164, 164, 164, 164, 164, 164, 164, 164, 164, 164, 164, 164, 103, 164, 164, 164, 164, 103, 164, 164, 164, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 73, 103, 103, 164, 164}, {166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 103, 166, 166, 166, 166, 103, 166, 166, 166, 103, 103, 103, 74, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 166, 166}, {197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197}, {198, 198, 198, 198, 198, 198, 198, 198, 198, 198, 198, 198, 198, 198, 103, 198, 198, 198, 198, 103, 198, 198, 198, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 198, 198}, {168, 168, 168, 168, 168, 168, 168, 168, 168, 168, 168, 168, 168, 168, 103, 168, 168, 168, 168, 103, 168, 168, 168, 103, 103, 103, 75, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 168, 168}, {199, 199, 199, 199, 199, 199, 199, 199, 199, 199, 199, 199, 199, 199, 103, 199, 199, 199, 199, 103, 199, 199, 199, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 199, 199}, {200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 103, 200, 200, 200, 200, 103, 200, 200, 200, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 200, 200}, {201, 201, 201, 201, 201, 201, 201, 201, 201, 201, 201, 201, 201, 201, 103, 201, 201, 201, 201, 103, 201, 201, 201, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 201, 201}}};
::ISPA_STD::DFA::API::Table<93, 4> DepParser::Lexer::action_table = {{{1, 0, ::ISPA_STD::DFA::API::null_state, 1}, {1, 2, ::ISPA_STD::DFA::API::null_state, 18}, {1, 20, ::ISPA_STD::DFA::API::null_state, 25}, {1, 20, ::ISPA_STD::DFA::API::null_state, 24}, {1, 20, ::ISPA_STD::DFA::API::null_state, 23}, {1, 20, ::ISPA_STD::DFA::API::null_state, 20}, {1, 4, ::ISPA_STD::DFA::API::null_state, 19}, {1, 8, ::ISPA_STD::DFA::API::null_state, 13}, {1, 20, ::ISPA_STD::DFA::API::null_state, 12}, {1, 20, ::ISPA_STD::DFA::API::null_state, 10}, {1, 16, ::ISPA_STD::DFA::API::null_state, 5}, {1, 18, ::ISPA_STD::DFA::API::null_state, 3}, {1, 20, ::ISPA_STD::DFA::API::null_state, 22}, {1, 20, ::ISPA_STD::DFA::API::null_state, 21}, {1, 1, ::ISPA_STD::DFA::API::null_state, 169}, {3, 0, 20, 169}, {1, 1, ::ISPA_STD::DFA::API::null_state, 91}, {3, 0, 20, 169}, {1, 1, ::ISPA_STD::DFA::API::null_state, 93}, {1, 9, ::ISPA_STD::DFA::API::null_state, 177}, {1, 9, ::ISPA_STD::DFA::API::null_state, 35}, {1, 3, ::ISPA_STD::DFA::API::null_state, 182}, {1, 5, ::ISPA_STD::DFA::API::null_state, 37}, {1, 5, ::ISPA_STD::DFA::API::null_state, 39}, {1, 5, ::ISPA_STD::DFA::API::null_state, 38}, {3, 2, 20, 182}, {1, 3, ::ISPA_STD::DFA::API::null_state, 101}, {3, 2, 20, 36}, {3, 2, 20, 182}, {1, 3, ::ISPA_STD::DFA::API::null_state, 104}, {3, 2, 20, 182}, {1, 3, ::ISPA_STD::DFA::API::null_state, 106}, {3, 2, 20, 182}, {1, 3, ::ISPA_STD::DFA::API::null_state, 108}, {3, 2, 20, 182}, {1, 3, ::ISPA_STD::DFA::API::null_state, 110}, {3, 2, 20, 182}, {1, 3, ::ISPA_STD::DFA::API::null_state, 112}, {1, 19, ::ISPA_STD::DFA::API::null_state, 185}, {1, 17, ::ISPA_STD::DFA::API::null_state, 186}, {3, 14, 20, 188}, {1, 15, ::ISPA_STD::DFA::API::null_state, 116}, {1, 10, ::ISPA_STD::DFA::API::null_state, 50}, {1, 3, ::ISPA_STD::DFA::API::null_state, 189}, {3, 2, 20, 189}, {1, 3, ::ISPA_STD::DFA::API::null_state, 120}, {3, 2, 20, 189}, {1, 3, ::ISPA_STD::DFA::API::null_state, 122}, {3, 2, 20, 189}, {1, 3, ::ISPA_STD::DFA::API::null_state, 124}, {3, 2, 20, 189}, {1, 3, ::ISPA_STD::DFA::API::null_state, 126}, {3, 2, 20, 189}, {1, 3, ::ISPA_STD::DFA::API::null_state, 128}, {3, 2, 20, 189}, {1, 3, ::ISPA_STD::DFA::API::null_state, 130}, {1, 6, ::ISPA_STD::DFA::API::null_state, 57}, {3, 14, 20, 192}, {1, 15, ::ISPA_STD::DFA::API::null_state, 133}, {1, 11, ::ISPA_STD::DFA::API::null_state, 193}, {3, 2, 20, 189}, {1, 3, ::ISPA_STD::DFA::API::null_state, 136}, {3, 2, 20, 189}, {1, 3, ::ISPA_STD::DFA::API::null_state, 138}, {3, 2, 20, 189}, {1, 3, ::ISPA_STD::DFA::API::null_state, 140}, {3, 2, 20, 189}, {1, 3, ::ISPA_STD::DFA::API::null_state, 142}, {3, 2, 20, 189}, {1, 3, ::ISPA_STD::DFA::API::null_state, 144}, {3, 2, 20, 189}, {1, 3, ::ISPA_STD::DFA::API::null_state, 146}, {3, 12, 20, 194}, {1, 13, ::ISPA_STD::DFA::API::null_state, 148}, {3, 2, 20, 189}, {1, 3, ::ISPA_STD::DFA::API::null_state, 150}, {3, 2, 20, 189}, {1, 3, ::ISPA_STD::DFA::API::null_state, 152}, {3, 2, 20, 189}, {1, 3, ::ISPA_STD::DFA::API::null_state, 154}, {3, 2, 20, 189}, {1, 3, ::ISPA_STD::DFA::API::null_state, 156}, {1, 7, ::ISPA_STD::DFA::API::null_state, 70}, {3, 2, 20, 189}, {1, 3, ::ISPA_STD::DFA::API::null_state, 159}, {3, 2, 20, 189}, {1, 3, ::ISPA_STD::DFA::API::null_state, 161}, {3, 2, 20, 189}, {1, 3, ::ISPA_STD::DFA::API::null_state, 163}, {3, 2, 20, 189}, {1, 3, ::ISPA_STD::DFA::API::null_state, 165}, {3, 2, 20, 189}, {1, 3, ::ISPA_STD::DFA::API::null_state, 167}}};
std::array<::ISPA_STD::DFA::API::DFADebug, 1> DepParser::Lexer::debug_array = {::ISPA_STD::DFA::API::DFADebug {"<Undefined>", "", 0, -1, -1, -1, 0, 1, '\000'}};
std::unordered_map<long long, std::unordered_map<long long, long long>> DepParser::Lexer::debug_index = { { 0, { { 2, 0 }, { 3, 0 }, { 5, 0 }, { 7, 0 }, { 8, 0 }, { 9, 0 }, { 10, 0 }, { 12, 0 }, { 15, 0 }, { 16, 0 }, { 17, 0 }, { 18, 0 }, { 39, 0 }, { 40, 0 } } }, { 2, { { 2, 0 }, { 3, 0 } } }, { 3, { { 1, 0 }, { 2, 0 }, { 3, 0 }, { 4, 0 }, { 5, 0 }, { 6, 0 }, { 7, 0 }, { 8, 0 }, { 9, 0 }, { 10, 0 }, { 11, 0 }, { 12, 0 }, { 13, 0 }, { 14, 0 }, { 15, 0 }, { 16, 0 }, { 17, 0 }, { 18, 0 }, { 19, 0 }, { 20, 0 }, { 21, 0 }, { 22, 0 }, { 23, 0 }, { 24, 0 }, { 25, 0 }, { 26, 0 }, { 27, 0 }, { 28, 0 }, { 29, 0 }, { 30, 0 }, { 31, 0 }, { 32, 0 }, { 33, 0 }, { 34, 0 }, { 35, 0 }, { 36, 0 }, { 37, 0 }, { 38, 0 }, { 39, 0 }, { 40, 0 } } }, { 5, { { 1, 0 }, { 2, 0 }, { 3, 0 }, { 4, 0 }, { 5, 0 }, { 6, 0 }, { 7, 0 }, { 8, 0 }, { 9, 0 }, { 10, 0 }, { 11, 0 }, { 12, 0 }, { 13, 0 }, { 14, 0 }, { 15, 0 }, { 16, 0 }, { 17, 0 }, { 18, 0 }, { 19, 0 }, { 20, 0 }, { 21, 0 }, { 22, 0 }, { 23, 0 }, { 24, 0 }, { 25, 0 }, { 26, 0 }, { 27, 0 }, { 28, 0 }, { 29, 0 }, { 30, 0 }, { 31, 0 }, { 32, 0 }, { 33, 0 }, { 34, 0 }, { 35, 0 }, { 36, 0 }, { 37, 0 }, { 38, 0 }, { 39, 0 }, { 40, 0 } } }, { 10, { { 18, 0 } } }, { 12, { { 9, 0 }, { 13, 0 } } }, { 13, { { 14, 0 } } }, { 18, { { 14, 0 }, { 19, 0 }, { 23, 0 }, { 24, 0 }, { 25, 0 }, { 26, 0 }, { 27, 0 }, { 28, 0 }, { 29, 0 }, { 30, 0 }, { 31, 0 }, { 32, 0 }, { 33, 0 }, { 34, 0 }, { 35, 0 }, { 36, 0 }, { 37, 0 }, { 38, 0 } } }, { 20, { { 35, 0 } } }, { 21, { { 26, 0 } } }, { 22, { { 23, 0 }, { 26, 0 }, { 34, 0 } } }, { 23, { { 31, 0 } } }, { 24, { { 32, 0 } } }, { 25, { { 39, 0 } } }, { 29, { { 1, 0 }, { 2, 0 }, { 3, 0 }, { 4, 0 }, { 5, 0 }, { 6, 0 }, { 7, 0 }, { 8, 0 }, { 9, 0 }, { 10, 0 }, { 11, 0 }, { 12, 0 }, { 13, 0 }, { 14, 0 }, { 15, 0 }, { 16, 0 }, { 17, 0 }, { 18, 0 }, { 19, 0 }, { 20, 0 }, { 21, 0 }, { 22, 0 }, { 23, 0 }, { 24, 0 }, { 25, 0 }, { 26, 0 }, { 27, 0 }, { 28, 0 }, { 29, 0 }, { 30, 0 }, { 31, 0 }, { 32, 0 }, { 33, 0 }, { 34, 0 }, { 35, 0 }, { 36, 0 }, { 37, 0 }, { 38, 0 }, { 39, 0 }, { 40, 0 } } }, { 31, { { 1, 0 }, { 2, 0 }, { 3, 0 }, { 4, 0 }, { 5, 0 }, { 6, 0 }, { 7, 0 }, { 8, 0 }, { 9, 0 }, { 10, 0 }, { 11, 0 }, { 12, 0 }, { 13, 0 }, { 14, 0 }, { 15, 0 }, { 16, 0 }, { 17, 0 }, { 18, 0 }, { 19, 0 }, { 20, 0 }, { 21, 0 }, { 22, 0 }, { 23, 0 }, { 24, 0 }, { 25, 0 }, { 26, 0 }, { 27, 0 }, { 28, 0 }, { 29, 0 }, { 30, 0 }, { 31, 0 }, { 32, 0 }, { 33, 0 }, { 34, 0 }, { 35, 0 }, { 36, 0 }, { 37, 0 }, { 38, 0 }, { 39, 0 }, { 40, 0 } } }, { 33, { { 1, 0 }, { 2, 0 }, { 3, 0 }, { 4, 0 }, { 5, 0 }, { 6, 0 }, { 7, 0 }, { 8, 0 }, { 9, 0 }, { 10, 0 }, { 11, 0 }, { 12, 0 }, { 13, 0 }, { 14, 0 }, { 15, 0 }, { 16, 0 }, { 17, 0 }, { 18, 0 }, { 19, 0 }, { 20, 0 }, { 21, 0 }, { 22, 0 }, { 23, 0 }, { 24, 0 }, { 25, 0 }, { 26, 0 }, { 27, 0 }, { 28, 0 }, { 29, 0 }, { 30, 0 }, { 31, 0 }, { 32, 0 }, { 33, 0 }, { 34, 0 }, { 35, 0 }, { 36, 0 }, { 37, 0 }, { 38, 0 }, { 39, 0 }, { 40, 0 } } }, { 34, { { 1, 0 }, { 2, 0 }, { 4, 0 }, { 5, 0 }, { 6, 0 }, { 7, 0 }, { 8, 0 }, { 9, 0 }, { 10, 0 }, { 11, 0 }, { 12, 0 }, { 13, 0 }, { 14, 0 }, { 15, 0 }, { 16, 0 }, { 17, 0 }, { 18, 0 }, { 19, 0 }, { 20, 0 }, { 21, 0 }, { 22, 0 }, { 23, 0 }, { 24, 0 }, { 25, 0 }, { 26, 0 }, { 27, 0 }, { 28, 0 }, { 29, 0 }, { 30, 0 }, { 31, 0 }, { 32, 0 }, { 33, 0 }, { 34, 0 }, { 35, 0 }, { 36, 0 }, { 37, 0 }, { 38, 0 }, { 39, 0 }, { 40, 0 } } }, { 36, { { 14, 0 }, { 19, 0 }, { 23, 0 }, { 24, 0 }, { 25, 0 }, { 26, 0 }, { 27, 0 }, { 28, 0 }, { 29, 0 }, { 30, 0 }, { 31, 0 }, { 32, 0 }, { 33, 0 }, { 34, 0 }, { 35, 0 }, { 36, 0 }, { 37, 0 }, { 38, 0 } } }, { 37, { { 1, 0 }, { 2, 0 }, { 3, 0 }, { 4, 0 }, { 5, 0 }, { 6, 0 }, { 7, 0 }, { 8, 0 }, { 9, 0 }, { 10, 0 }, { 11, 0 }, { 12, 0 }, { 13, 0 }, { 14, 0 }, { 15, 0 }, { 16, 0 }, { 17, 0 }, { 18, 0 }, { 19, 0 }, { 20, 0 }, { 21, 0 }, { 22, 0 }, { 23, 0 }, { 24, 0 }, { 25, 0 }, { 26, 0 }, { 27, 0 }, { 28, 0 }, { 29, 0 }, { 30, 0 }, { 31, 0 }, { 32, 0 }, { 33, 0 }, { 34, 0 }, { 35, 0 }, { 36, 0 }, { 37, 0 }, { 38, 0 }, { 39, 0 }, { 40, 0 } } }, { 38, { { 1, 0 }, { 2, 0 }, { 3, 0 }, { 4, 0 }, { 5, 0 }, { 6, 0 }, { 7, 0 }, { 8, 0 }, { 9, 0 }, { 10, 0 }, { 11, 0 }, { 12, 0 }, { 13, 0 }, { 14, 0 }, { 15, 0 }, { 16, 0 }, { 17, 0 }, { 18, 0 }, { 19, 0 }, { 20, 0 }, { 21, 0 }, { 22, 0 }, { 23, 0 }, { 24, 0 }, { 25, 0 }, { 26, 0 }, { 27, 0 }, { 28, 0 }, { 29, 0 }, { 30, 0 }, { 31, 0 }, { 32, 0 }, { 33, 0 }, { 34, 0 }, { 35, 0 }, { 36, 0 }, { 37, 0 }, { 38, 0 }, { 39, 0 }, { 40, 0 } } }, { 41, { { 36, 0 } } }, { 42, { { 29, 0 } } }, { 43, { { 23, 0 } } }, { 44, { { 32, 0 } } }, { 45, { { 33, 0 } } }, { 46, { { 25, 0 } } }, { 48, { { 1, 0 }, { 2, 0 }, { 3, 0 }, { 4, 0 }, { 5, 0 }, { 6, 0 }, { 7, 0 }, { 8, 0 }, { 9, 0 }, { 10, 0 }, { 11, 0 }, { 12, 0 }, { 13, 0 }, { 14, 0 }, { 15, 0 }, { 16, 0 }, { 17, 0 }, { 18, 0 }, { 19, 0 }, { 20, 0 }, { 21, 0 }, { 22, 0 }, { 23, 0 }, { 24, 0 }, { 25, 0 }, { 26, 0 }, { 27, 0 }, { 28, 0 }, { 29, 0 }, { 30, 0 }, { 31, 0 }, { 32, 0 }, { 33, 0 }, { 34, 0 }, { 35, 0 }, { 36, 0 }, { 37, 0 }, { 38, 0 }, { 39, 0 }, { 40, 0 } } }, { 49, { { 1, 0 }, { 2, 0 }, { 4, 0 }, { 5, 0 }, { 6, 0 }, { 7, 0 }, { 8, 0 }, { 9, 0 }, { 10, 0 }, { 11, 0 }, { 12, 0 }, { 13, 0 }, { 14, 0 }, { 15, 0 }, { 16, 0 }, { 17, 0 }, { 18, 0 }, { 19, 0 }, { 20, 0 }, { 21, 0 }, { 22, 0 }, { 23, 0 }, { 24, 0 }, { 25, 0 }, { 26, 0 }, { 27, 0 }, { 28, 0 }, { 29, 0 }, { 30, 0 }, { 31, 0 }, { 32, 0 }, { 33, 0 }, { 34, 0 }, { 35, 0 }, { 36, 0 }, { 37, 0 }, { 38, 0 }, { 39, 0 }, { 40, 0 } } }, { 50, { { 14, 0 } } }, { 51, { { 23, 0 } } }, { 52, { { 30, 0 } } }, { 53, { { 36, 0 } } }, { 54, { { 31, 0 } } }, { 55, { { 32, 0 } } }, { 56, { { 37, 0 } } }, { 57, { { 38, 0 } } }, { 59, { { 24, 0 } } }, { 61, { { 37, 0 } } }, { 63, { { 34, 0 } } }, { 64, { { 30, 0 } } }, { 66, { { 28, 0 } } }, { 67, { { 34, 0 } } }, { 68, { { 36, 0 } } }, { 69, { { 26, 0 } } }, { 72, { { 26, 0 } } } };
auto DepParser::Parser::lr_k() -> std::size_t {
	return 1;
}
auto DepParser::Parser::lr_is_space(const Token& token) -> bool {
	return token.kind() == Tokens::__WS::id;
}
auto DepParser::Parser::lr_space(std::size_t rule, std::size_t gap) -> bool {
	if (rule == 1 && gap == 1) {
		return true;
	}
	if (rule == 1 && gap == 2) {
		return true;
	}
	if (rule == 1 && gap == 3) {
		return true;
	}
	if (rule == 3 && gap == 1) {
		return true;
	}
	if (rule == 5 && gap == 0) {
		return true;
	}
	if (rule == 5 && gap == 1) {
		return true;
	}
	if (rule == 10 && gap == 1) {
		return true;
	}
	if (rule == 12 && gap == 1) {
		return true;
	}
	if (rule == 14 && gap == 0) {
		return true;
	}
	if (rule == 14 && gap == 1) {
		return true;
	}
	if (rule == 15 && gap == 1) {
		return true;
	}
	if (rule == 15 && gap == 2) {
		return true;
	}
	if (rule == 15 && gap == 3) {
		return true;
	}
	if (rule == 18 && gap == 1) {
		return true;
	}
	if (rule == 18 && gap == 2) {
		return true;
	}
	if (rule == 42 && gap == 1) {
		return true;
	}
	if (rule == 42 && gap == 2) {
		return true;
	}
	if (rule == 46 && gap == 0) {
		return true;
	}
	if (rule == 47 && gap == 1) {
		return true;
	}
	if (rule == 47 && gap == 2) {
		return true;
	}
	if (rule == 51 && gap == 0) {
		return true;
	}
	if (rule == 52 && gap == 1) {
		return true;
	}
	if (rule == 52 && gap == 2) {
		return true;
	}
	if (rule == 56 && gap == 0) {
		return true;
	}
	if (rule == 57 && gap == 1) {
		return true;
	}
	if (rule == 57 && gap == 2) {
		return true;
	}
	if (rule == 58 && gap == 1) {
		return true;
	}
	if (rule == 58 && gap == 2) {
		return true;
	}
	if (rule == 58 && gap == 3) {
		return true;
	}
	if (rule == 58 && gap == 4) {
		return true;
	}
	if (rule == 58 && gap == 5) {
		return true;
	}
	if (rule == 76 && gap == 1) {
		return true;
	}
	if (rule == 76 && gap == 2) {
		return true;
	}
	if (rule == 76 && gap == 3) {
		return true;
	}
	if (rule == 78 && gap == 1) {
		return true;
	}
	if (rule == 94 && gap == 0) {
		return true;
	}
	if (rule == 99 && gap == 1) {
		return true;
	}
	if (rule == 99 && gap == 2) {
		return true;
	}
	if (rule == 102 && gap == 1) {
		return true;
	}
	if (rule == 103 && gap == 1) {
		return true;
	}
	if (rule == 103 && gap == 2) {
		return true;
	}
	if (rule == 106 && gap == 1) {
		return true;
	}
	if (rule == 106 && gap == 2) {
		return true;
	}
	if (rule == 109 && gap == 1) {
		return true;
	}
	if (rule == 109 && gap == 2) {
		return true;
	}
	if (rule == 109 && gap == 3) {
		return true;
	}
	if (rule == 111 && gap == 1) {
		return true;
	}
	if (rule == 113 && gap == 0) {
		return true;
	}
	if (rule == 113 && gap == 1) {
		return true;
	}
	if (rule == 114 && gap == 1) {
		return true;
	}
	if (rule == 116 && gap == 1) {
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
	if (rule == 119 && gap == 1) {
		return true;
	}
	if (rule == 122 && gap == 1) {
		return true;
	}
	if (rule == 123 && gap == 1) {
		return true;
	}
	if (rule == 125 && gap == 1) {
		return true;
	}
	if (rule == 127 && gap == 0) {
		return true;
	}
	if (rule == 127 && gap == 1) {
		return true;
	}
	if (rule == 128 && gap == 1) {
		return true;
	}
	if (rule == 129 && gap == 1) {
		return true;
	}
	if (rule == 129 && gap == 2) {
		return true;
	}
	if (rule == 133 && gap == 0) {
		return true;
	}
	if (rule == 136 && gap == 1) {
		return true;
	}
	if (rule == 138 && gap == 1) {
		return true;
	}
	if (rule == 140 && gap == 0) {
		return true;
	}
	if (rule == 140 && gap == 1) {
		return true;
	}
	return false;
}
auto DepParser::Parser::lr_action(std::size_t state, const std::vector<std::size_t>& window) -> long long {
	if (state == 0 && window.at(0) == static_cast<std::size_t>(-1)) {
		return -85;
	}
	if (state == 0 && window.at(0) == Tokens::modules::common::ID::id) {
		return -54;
	}
	if (state == 0 && window.at(0) == Tokens::modules::ispa_dep_scanner::AS::id) {
		return -54;
	}
	if (state == 0 && window.at(0) == Tokens::modules::ispa_dep_scanner::COMMENT::id) {
		return 3;
	}
	if (state == 0 && window.at(0) == Tokens::modules::ispa_dep_scanner::FROM::id) {
		return -54;
	}
	if (state == 0 && window.at(0) == Tokens::modules::ispa_dep_scanner::HASH::id) {
		return 7;
	}
	if (state == 1 && window.at(0) == static_cast<std::size_t>(-1)) {
		return 0;
	}
	if (state == 2 && window.at(0) == static_cast<std::size_t>(-1)) {
		return -93;
	}
	if (state == 2 && window.at(0) == Tokens::modules::common::ID::id) {
		return -93;
	}
	if (state == 2 && window.at(0) == Tokens::modules::ispa_dep_scanner::AS::id) {
		return -93;
	}
	if (state == 2 && window.at(0) == Tokens::modules::ispa_dep_scanner::COMMENT::id) {
		return -93;
	}
	if (state == 2 && window.at(0) == Tokens::modules::ispa_dep_scanner::DETACH::id) {
		return -93;
	}
	if (state == 2 && window.at(0) == Tokens::modules::ispa_dep_scanner::FAIL::id) {
		return -93;
	}
	if (state == 2 && window.at(0) == Tokens::modules::ispa_dep_scanner::FEATURE::id) {
		return -93;
	}
	if (state == 2 && window.at(0) == Tokens::modules::ispa_dep_scanner::FROM::id) {
		return -93;
	}
	if (state == 2 && window.at(0) == Tokens::modules::ispa_dep_scanner::HASH::id) {
		return -93;
	}
	if (state == 2 && window.at(0) == Tokens::modules::ispa_dep_scanner::IMPORT::id) {
		return -93;
	}
	if (state == 2 && window.at(0) == Tokens::modules::ispa_dep_scanner::MODULE::id) {
		return -93;
	}
	if (state == 3 && window.at(0) == Tokens::modules::common::ID::id) {
		return 21;
	}
	if (state == 3 && window.at(0) == Tokens::modules::ispa_dep_scanner::AS::id) {
		return 23;
	}
	if (state == 3 && window.at(0) == Tokens::modules::ispa_dep_scanner::DETACH::id) {
		return 24;
	}
	if (state == 3 && window.at(0) == Tokens::modules::ispa_dep_scanner::FAIL::id) {
		return 25;
	}
	if (state == 3 && window.at(0) == Tokens::modules::ispa_dep_scanner::FEATURE::id) {
		return 26;
	}
	if (state == 3 && window.at(0) == Tokens::modules::ispa_dep_scanner::FROM::id) {
		return 27;
	}
	if (state == 3 && window.at(0) == Tokens::modules::ispa_dep_scanner::IMPORT::id) {
		return 28;
	}
	if (state == 3 && window.at(0) == Tokens::modules::ispa_dep_scanner::MODULE::id) {
		return 29;
	}
	if (state == 4 && window.at(0) == Tokens::modules::common::ID::id) {
		return 21;
	}
	if (state == 4 && window.at(0) == Tokens::modules::ispa_dep_scanner::AS::id) {
		return 23;
	}
	if (state == 4 && window.at(0) == Tokens::modules::ispa_dep_scanner::DETACH::id) {
		return 24;
	}
	if (state == 4 && window.at(0) == Tokens::modules::ispa_dep_scanner::FAIL::id) {
		return 25;
	}
	if (state == 4 && window.at(0) == Tokens::modules::ispa_dep_scanner::FEATURE::id) {
		return 35;
	}
	if (state == 4 && window.at(0) == Tokens::modules::ispa_dep_scanner::FROM::id) {
		return 27;
	}
	if (state == 4 && window.at(0) == Tokens::modules::ispa_dep_scanner::IMPORT::id) {
		return 28;
	}
	if (state == 4 && window.at(0) == Tokens::modules::ispa_dep_scanner::MODULE::id) {
		return 29;
	}
	if (state == 5 && window.at(0) == Tokens::modules::common::ID::id) {
		return 21;
	}
	if (state == 5 && window.at(0) == Tokens::modules::ispa_dep_scanner::AS::id) {
		return 23;
	}
	if (state == 5 && window.at(0) == Tokens::modules::ispa_dep_scanner::DETACH::id) {
		return 24;
	}
	if (state == 5 && window.at(0) == Tokens::modules::ispa_dep_scanner::FAIL::id) {
		return 25;
	}
	if (state == 5 && window.at(0) == Tokens::modules::ispa_dep_scanner::FEATURE::id) {
		return 35;
	}
	if (state == 5 && window.at(0) == Tokens::modules::ispa_dep_scanner::FROM::id) {
		return 27;
	}
	if (state == 5 && window.at(0) == Tokens::modules::ispa_dep_scanner::IMPORT::id) {
		return 28;
	}
	if (state == 5 && window.at(0) == Tokens::modules::ispa_dep_scanner::MODULE::id) {
		return 29;
	}
	if (state == 6 && window.at(0) == Tokens::modules::ispa_dep_scanner::CGROUP::id) {
		return 38;
	}
	if (state == 7 && window.at(0) == Tokens::modules::common::ID::id) {
		return 39;
	}
	if (state == 7 && window.at(0) == Tokens::modules::ispa_dep_scanner::ALL::id) {
		return 40;
	}
	if (state == 7 && window.at(0) == Tokens::modules::ispa_dep_scanner::AS::id) {
		return 41;
	}
	if (state == 7 && window.at(0) == Tokens::modules::ispa_dep_scanner::DETACH::id) {
		return 42;
	}
	if (state == 7 && window.at(0) == Tokens::modules::ispa_dep_scanner::FAIL::id) {
		return 43;
	}
	if (state == 7 && window.at(0) == Tokens::modules::ispa_dep_scanner::FEATURE::id) {
		return 44;
	}
	if (state == 7 && window.at(0) == Tokens::modules::ispa_dep_scanner::FROM::id) {
		return 45;
	}
	if (state == 7 && window.at(0) == Tokens::modules::ispa_dep_scanner::IMPORT::id) {
		return 46;
	}
	if (state == 7 && window.at(0) == Tokens::modules::ispa_dep_scanner::LBRACE::id) {
		return 47;
	}
	if (state == 7 && window.at(0) == Tokens::modules::ispa_dep_scanner::MODULE::id) {
		return 48;
	}
	if (state == 8 && window.at(0) == Tokens::modules::common::ID::id) {
		return 39;
	}
	if (state == 8 && window.at(0) == Tokens::modules::ispa_dep_scanner::AS::id) {
		return 41;
	}
	if (state == 8 && window.at(0) == Tokens::modules::ispa_dep_scanner::DETACH::id) {
		return 42;
	}
	if (state == 8 && window.at(0) == Tokens::modules::ispa_dep_scanner::FAIL::id) {
		return 43;
	}
	if (state == 8 && window.at(0) == Tokens::modules::ispa_dep_scanner::FEATURE::id) {
		return 44;
	}
	if (state == 8 && window.at(0) == Tokens::modules::ispa_dep_scanner::FROM::id) {
		return 45;
	}
	if (state == 8 && window.at(0) == Tokens::modules::ispa_dep_scanner::IMPORT::id) {
		return 46;
	}
	if (state == 8 && window.at(0) == Tokens::modules::ispa_dep_scanner::MODULE::id) {
		return 48;
	}
	if (state == 9 && window.at(0) == static_cast<std::size_t>(-1)) {
		return -91;
	}
	if (state == 9 && window.at(0) == Tokens::modules::common::ID::id) {
		return -91;
	}
	if (state == 9 && window.at(0) == Tokens::modules::ispa_dep_scanner::AS::id) {
		return -91;
	}
	if (state == 9 && window.at(0) == Tokens::modules::ispa_dep_scanner::COMMENT::id) {
		return -91;
	}
	if (state == 9 && window.at(0) == Tokens::modules::ispa_dep_scanner::DETACH::id) {
		return -91;
	}
	if (state == 9 && window.at(0) == Tokens::modules::ispa_dep_scanner::FAIL::id) {
		return -91;
	}
	if (state == 9 && window.at(0) == Tokens::modules::ispa_dep_scanner::FEATURE::id) {
		return -91;
	}
	if (state == 9 && window.at(0) == Tokens::modules::ispa_dep_scanner::FROM::id) {
		return -91;
	}
	if (state == 9 && window.at(0) == Tokens::modules::ispa_dep_scanner::HASH::id) {
		return -91;
	}
	if (state == 9 && window.at(0) == Tokens::modules::ispa_dep_scanner::IMPORT::id) {
		return -91;
	}
	if (state == 9 && window.at(0) == Tokens::modules::ispa_dep_scanner::MODULE::id) {
		return -91;
	}
	if (state == 10 && window.at(0) == Tokens::modules::common::ID::id) {
		return 21;
	}
	if (state == 10 && window.at(0) == Tokens::modules::ispa_dep_scanner::AS::id) {
		return 23;
	}
	if (state == 10 && window.at(0) == Tokens::modules::ispa_dep_scanner::DETACH::id) {
		return 24;
	}
	if (state == 10 && window.at(0) == Tokens::modules::ispa_dep_scanner::FAIL::id) {
		return 25;
	}
	if (state == 10 && window.at(0) == Tokens::modules::ispa_dep_scanner::FEATURE::id) {
		return 35;
	}
	if (state == 10 && window.at(0) == Tokens::modules::ispa_dep_scanner::FROM::id) {
		return 27;
	}
	if (state == 10 && window.at(0) == Tokens::modules::ispa_dep_scanner::IMPORT::id) {
		return 28;
	}
	if (state == 10 && window.at(0) == Tokens::modules::ispa_dep_scanner::MODULE::id) {
		return 29;
	}
	if (state == 11 && window.at(0) == static_cast<std::size_t>(-1)) {
		return -92;
	}
	if (state == 11 && window.at(0) == Tokens::modules::common::ID::id) {
		return -92;
	}
	if (state == 11 && window.at(0) == Tokens::modules::ispa_dep_scanner::AS::id) {
		return -92;
	}
	if (state == 11 && window.at(0) == Tokens::modules::ispa_dep_scanner::COMMENT::id) {
		return -92;
	}
	if (state == 11 && window.at(0) == Tokens::modules::ispa_dep_scanner::DETACH::id) {
		return -92;
	}
	if (state == 11 && window.at(0) == Tokens::modules::ispa_dep_scanner::FAIL::id) {
		return -92;
	}
	if (state == 11 && window.at(0) == Tokens::modules::ispa_dep_scanner::FEATURE::id) {
		return -92;
	}
	if (state == 11 && window.at(0) == Tokens::modules::ispa_dep_scanner::FROM::id) {
		return -92;
	}
	if (state == 11 && window.at(0) == Tokens::modules::ispa_dep_scanner::HASH::id) {
		return -92;
	}
	if (state == 11 && window.at(0) == Tokens::modules::ispa_dep_scanner::IMPORT::id) {
		return -92;
	}
	if (state == 11 && window.at(0) == Tokens::modules::ispa_dep_scanner::MODULE::id) {
		return -92;
	}
	if (state == 12 && window.at(0) == static_cast<std::size_t>(-1)) {
		return -90;
	}
	if (state == 12 && window.at(0) == Tokens::modules::common::ID::id) {
		return -90;
	}
	if (state == 12 && window.at(0) == Tokens::modules::ispa_dep_scanner::AS::id) {
		return -90;
	}
	if (state == 12 && window.at(0) == Tokens::modules::ispa_dep_scanner::COMMENT::id) {
		return -90;
	}
	if (state == 12 && window.at(0) == Tokens::modules::ispa_dep_scanner::DETACH::id) {
		return -90;
	}
	if (state == 12 && window.at(0) == Tokens::modules::ispa_dep_scanner::FAIL::id) {
		return -90;
	}
	if (state == 12 && window.at(0) == Tokens::modules::ispa_dep_scanner::FEATURE::id) {
		return -90;
	}
	if (state == 12 && window.at(0) == Tokens::modules::ispa_dep_scanner::FROM::id) {
		return -90;
	}
	if (state == 12 && window.at(0) == Tokens::modules::ispa_dep_scanner::HASH::id) {
		return -90;
	}
	if (state == 12 && window.at(0) == Tokens::modules::ispa_dep_scanner::IMPORT::id) {
		return -90;
	}
	if (state == 12 && window.at(0) == Tokens::modules::ispa_dep_scanner::MODULE::id) {
		return -90;
	}
	if (state == 13 && window.at(0) == static_cast<std::size_t>(-1)) {
		return -1;
	}
	if (state == 14 && window.at(0) == static_cast<std::size_t>(-1)) {
		return -84;
	}
	if (state == 15 && window.at(0) == static_cast<std::size_t>(-1)) {
		return -94;
	}
	if (state == 15 && window.at(0) == Tokens::modules::common::ID::id) {
		return -54;
	}
	if (state == 15 && window.at(0) == Tokens::modules::ispa_dep_scanner::AS::id) {
		return -54;
	}
	if (state == 15 && window.at(0) == Tokens::modules::ispa_dep_scanner::COMMENT::id) {
		return 3;
	}
	if (state == 15 && window.at(0) == Tokens::modules::ispa_dep_scanner::FROM::id) {
		return -54;
	}
	if (state == 15 && window.at(0) == Tokens::modules::ispa_dep_scanner::HASH::id) {
		return 7;
	}
	if (state == 16 && window.at(0) == static_cast<std::size_t>(-1)) {
		return -89;
	}
	if (state == 16 && window.at(0) == Tokens::modules::common::ID::id) {
		return -89;
	}
	if (state == 16 && window.at(0) == Tokens::modules::ispa_dep_scanner::AS::id) {
		return -89;
	}
	if (state == 16 && window.at(0) == Tokens::modules::ispa_dep_scanner::COMMENT::id) {
		return -89;
	}
	if (state == 16 && window.at(0) == Tokens::modules::ispa_dep_scanner::DETACH::id) {
		return -89;
	}
	if (state == 16 && window.at(0) == Tokens::modules::ispa_dep_scanner::FAIL::id) {
		return -89;
	}
	if (state == 16 && window.at(0) == Tokens::modules::ispa_dep_scanner::FEATURE::id) {
		return -89;
	}
	if (state == 16 && window.at(0) == Tokens::modules::ispa_dep_scanner::FROM::id) {
		return -89;
	}
	if (state == 16 && window.at(0) == Tokens::modules::ispa_dep_scanner::HASH::id) {
		return -89;
	}
	if (state == 16 && window.at(0) == Tokens::modules::ispa_dep_scanner::IMPORT::id) {
		return -89;
	}
	if (state == 16 && window.at(0) == Tokens::modules::ispa_dep_scanner::MODULE::id) {
		return -89;
	}
	if (state == 17 && window.at(0) == static_cast<std::size_t>(-1)) {
		return -88;
	}
	if (state == 17 && window.at(0) == Tokens::modules::common::ID::id) {
		return -88;
	}
	if (state == 17 && window.at(0) == Tokens::modules::ispa_dep_scanner::AS::id) {
		return -88;
	}
	if (state == 17 && window.at(0) == Tokens::modules::ispa_dep_scanner::COMMENT::id) {
		return -88;
	}
	if (state == 17 && window.at(0) == Tokens::modules::ispa_dep_scanner::DETACH::id) {
		return -88;
	}
	if (state == 17 && window.at(0) == Tokens::modules::ispa_dep_scanner::FAIL::id) {
		return -88;
	}
	if (state == 17 && window.at(0) == Tokens::modules::ispa_dep_scanner::FEATURE::id) {
		return -88;
	}
	if (state == 17 && window.at(0) == Tokens::modules::ispa_dep_scanner::FROM::id) {
		return -88;
	}
	if (state == 17 && window.at(0) == Tokens::modules::ispa_dep_scanner::HASH::id) {
		return -88;
	}
	if (state == 17 && window.at(0) == Tokens::modules::ispa_dep_scanner::IMPORT::id) {
		return -88;
	}
	if (state == 17 && window.at(0) == Tokens::modules::ispa_dep_scanner::MODULE::id) {
		return -88;
	}
	if (state == 18 && window.at(0) == static_cast<std::size_t>(-1)) {
		return -87;
	}
	if (state == 18 && window.at(0) == Tokens::modules::common::ID::id) {
		return -87;
	}
	if (state == 18 && window.at(0) == Tokens::modules::ispa_dep_scanner::AS::id) {
		return -87;
	}
	if (state == 18 && window.at(0) == Tokens::modules::ispa_dep_scanner::COMMENT::id) {
		return -87;
	}
	if (state == 18 && window.at(0) == Tokens::modules::ispa_dep_scanner::DETACH::id) {
		return -87;
	}
	if (state == 18 && window.at(0) == Tokens::modules::ispa_dep_scanner::FAIL::id) {
		return -87;
	}
	if (state == 18 && window.at(0) == Tokens::modules::ispa_dep_scanner::FEATURE::id) {
		return -87;
	}
	if (state == 18 && window.at(0) == Tokens::modules::ispa_dep_scanner::FROM::id) {
		return -87;
	}
	if (state == 18 && window.at(0) == Tokens::modules::ispa_dep_scanner::HASH::id) {
		return -87;
	}
	if (state == 18 && window.at(0) == Tokens::modules::ispa_dep_scanner::IMPORT::id) {
		return -87;
	}
	if (state == 18 && window.at(0) == Tokens::modules::ispa_dep_scanner::MODULE::id) {
		return -87;
	}
	if (state == 19 && window.at(0) == Tokens::modules::common::ID::id) {
		return -56;
	}
	if (state == 19 && window.at(0) == Tokens::modules::ispa_dep_scanner::AS::id) {
		return -56;
	}
	if (state == 19 && window.at(0) == Tokens::modules::ispa_dep_scanner::DETACH::id) {
		return -56;
	}
	if (state == 19 && window.at(0) == Tokens::modules::ispa_dep_scanner::FAIL::id) {
		return -56;
	}
	if (state == 19 && window.at(0) == Tokens::modules::ispa_dep_scanner::FEATURE::id) {
		return -56;
	}
	if (state == 19 && window.at(0) == Tokens::modules::ispa_dep_scanner::FROM::id) {
		return -56;
	}
	if (state == 19 && window.at(0) == Tokens::modules::ispa_dep_scanner::HASH::id) {
		return 7;
	}
	if (state == 19 && window.at(0) == Tokens::modules::ispa_dep_scanner::IMPORT::id) {
		return -56;
	}
	if (state == 19 && window.at(0) == Tokens::modules::ispa_dep_scanner::MODULE::id) {
		return -56;
	}
	if (state == 20 && window.at(0) == Tokens::AUTO::id) {
		return 62;
	}
	if (state == 20 && window.at(0) == Tokens::COMMA::id) {
		return -3;
	}
	if (state == 20 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -3;
	}
	if (state == 20 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -3;
	}
	if (state == 20 && window.at(0) == Tokens::modules::common::PY_RAW::id) {
		return -3;
	}
	if (state == 20 && window.at(0) == Tokens::modules::ispa_dep_scanner::COLON::id) {
		return -3;
	}
	if (state == 20 && window.at(0) == Tokens::modules::ispa_dep_scanner::LBRACE::id) {
		return -3;
	}
	if (state == 20 && window.at(0) == Tokens::modules::ispa_dep_scanner::RBRACE::id) {
		return -3;
	}
	if (state == 20 && window.at(0) == Tokens::modules::ispa_dep_scanner::SEMI::id) {
		return -3;
	}
	if (state == 21 && window.at(0) == Tokens::COMMA::id) {
		return -135;
	}
	if (state == 21 && window.at(0) == Tokens::modules::common::PY_RAW::id) {
		return -135;
	}
	if (state == 21 && window.at(0) == Tokens::modules::ispa_dep_scanner::COLON::id) {
		return -135;
	}
	if (state == 21 && window.at(0) == Tokens::modules::ispa_dep_scanner::LBRACE::id) {
		return -135;
	}
	if (state == 21 && window.at(0) == Tokens::modules::ispa_dep_scanner::RBRACE::id) {
		return -135;
	}
	if (state == 21 && window.at(0) == Tokens::modules::ispa_dep_scanner::SEMI::id) {
		return -135;
	}
	if (state == 22 && window.at(0) == Tokens::AUTO::id) {
		return -74;
	}
	if (state == 22 && window.at(0) == Tokens::COMMA::id) {
		return -74;
	}
	if (state == 22 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -74;
	}
	if (state == 22 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -74;
	}
	if (state == 22 && window.at(0) == Tokens::modules::common::PY_RAW::id) {
		return -74;
	}
	if (state == 22 && window.at(0) == Tokens::modules::ispa_dep_scanner::COLON::id) {
		return -74;
	}
	if (state == 22 && window.at(0) == Tokens::modules::ispa_dep_scanner::LBRACE::id) {
		return -74;
	}
	if (state == 22 && window.at(0) == Tokens::modules::ispa_dep_scanner::RBRACE::id) {
		return -74;
	}
	if (state == 22 && window.at(0) == Tokens::modules::ispa_dep_scanner::SEMI::id) {
		return -74;
	}
	if (state == 23 && window.at(0) == Tokens::AUTO::id) {
		return -72;
	}
	if (state == 23 && window.at(0) == Tokens::COMMA::id) {
		return -72;
	}
	if (state == 23 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -72;
	}
	if (state == 23 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -72;
	}
	if (state == 23 && window.at(0) == Tokens::modules::common::PY_RAW::id) {
		return -72;
	}
	if (state == 23 && window.at(0) == Tokens::modules::ispa_dep_scanner::COLON::id) {
		return -72;
	}
	if (state == 23 && window.at(0) == Tokens::modules::ispa_dep_scanner::LBRACE::id) {
		return -72;
	}
	if (state == 23 && window.at(0) == Tokens::modules::ispa_dep_scanner::RBRACE::id) {
		return -72;
	}
	if (state == 23 && window.at(0) == Tokens::modules::ispa_dep_scanner::SEMI::id) {
		return -72;
	}
	if (state == 24 && window.at(0) == Tokens::AUTO::id) {
		return -76;
	}
	if (state == 24 && window.at(0) == Tokens::COMMA::id) {
		return -76;
	}
	if (state == 24 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -76;
	}
	if (state == 24 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -76;
	}
	if (state == 24 && window.at(0) == Tokens::modules::common::PY_RAW::id) {
		return -76;
	}
	if (state == 24 && window.at(0) == Tokens::modules::ispa_dep_scanner::COLON::id) {
		return -76;
	}
	if (state == 24 && window.at(0) == Tokens::modules::ispa_dep_scanner::LBRACE::id) {
		return -76;
	}
	if (state == 24 && window.at(0) == Tokens::modules::ispa_dep_scanner::RBRACE::id) {
		return -76;
	}
	if (state == 24 && window.at(0) == Tokens::modules::ispa_dep_scanner::SEMI::id) {
		return -76;
	}
	if (state == 25 && window.at(0) == Tokens::AUTO::id) {
		return -73;
	}
	if (state == 25 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -73;
	}
	if (state == 25 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -73;
	}
	if (state == 25 && window.at(0) == Tokens::modules::common::ID::id) {
		return 21;
	}
	if (state == 25 && window.at(0) == Tokens::modules::ispa_dep_scanner::AS::id) {
		return 23;
	}
	if (state == 25 && window.at(0) == Tokens::modules::ispa_dep_scanner::DETACH::id) {
		return 24;
	}
	if (state == 25 && window.at(0) == Tokens::modules::ispa_dep_scanner::FAIL::id) {
		return 25;
	}
	if (state == 25 && window.at(0) == Tokens::modules::ispa_dep_scanner::FEATURE::id) {
		return 35;
	}
	if (state == 25 && window.at(0) == Tokens::modules::ispa_dep_scanner::FROM::id) {
		return 27;
	}
	if (state == 25 && window.at(0) == Tokens::modules::ispa_dep_scanner::IMPORT::id) {
		return 28;
	}
	if (state == 25 && window.at(0) == Tokens::modules::ispa_dep_scanner::MODULE::id) {
		return 29;
	}
	if (state == 25 && window.at(0) == Tokens::modules::ispa_dep_scanner::SEMI::id) {
		return -73;
	}
	if (state == 26 && window.at(0) == Tokens::AUTO::id) {
		return -75;
	}
	if (state == 26 && window.at(0) == Tokens::COMMA::id) {
		return -75;
	}
	if (state == 26 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -75;
	}
	if (state == 26 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -75;
	}
	if (state == 26 && window.at(0) == Tokens::modules::common::PY_RAW::id) {
		return -75;
	}
	if (state == 26 && window.at(0) == Tokens::modules::ispa_dep_scanner::COLON::id) {
		return -75;
	}
	if (state == 26 && window.at(0) == Tokens::modules::ispa_dep_scanner::LBRACE::id) {
		return -75;
	}
	if (state == 26 && window.at(0) == Tokens::modules::ispa_dep_scanner::RBRACE::id) {
		return -75;
	}
	if (state == 26 && window.at(0) == Tokens::modules::ispa_dep_scanner::SEMI::id) {
		return -75;
	}
	if (state == 27 && window.at(0) == Tokens::AUTO::id) {
		return -71;
	}
	if (state == 27 && window.at(0) == Tokens::COMMA::id) {
		return -71;
	}
	if (state == 27 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -71;
	}
	if (state == 27 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -71;
	}
	if (state == 27 && window.at(0) == Tokens::modules::common::PY_RAW::id) {
		return -71;
	}
	if (state == 27 && window.at(0) == Tokens::modules::ispa_dep_scanner::COLON::id) {
		return -71;
	}
	if (state == 27 && window.at(0) == Tokens::modules::ispa_dep_scanner::LBRACE::id) {
		return -71;
	}
	if (state == 27 && window.at(0) == Tokens::modules::ispa_dep_scanner::RBRACE::id) {
		return -71;
	}
	if (state == 27 && window.at(0) == Tokens::modules::ispa_dep_scanner::SEMI::id) {
		return -71;
	}
	if (state == 28 && window.at(0) == Tokens::AUTO::id) {
		return -70;
	}
	if (state == 28 && window.at(0) == Tokens::COMMA::id) {
		return -70;
	}
	if (state == 28 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -70;
	}
	if (state == 28 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -70;
	}
	if (state == 28 && window.at(0) == Tokens::modules::common::PY_RAW::id) {
		return -70;
	}
	if (state == 28 && window.at(0) == Tokens::modules::ispa_dep_scanner::COLON::id) {
		return -70;
	}
	if (state == 28 && window.at(0) == Tokens::modules::ispa_dep_scanner::LBRACE::id) {
		return -70;
	}
	if (state == 28 && window.at(0) == Tokens::modules::ispa_dep_scanner::RBRACE::id) {
		return -70;
	}
	if (state == 28 && window.at(0) == Tokens::modules::ispa_dep_scanner::SEMI::id) {
		return -70;
	}
	if (state == 29 && window.at(0) == Tokens::AUTO::id) {
		return 65;
	}
	if (state == 29 && window.at(0) == Tokens::COMMA::id) {
		return -78;
	}
	if (state == 29 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -78;
	}
	if (state == 29 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -78;
	}
	if (state == 29 && window.at(0) == Tokens::modules::common::PY_RAW::id) {
		return -78;
	}
	if (state == 29 && window.at(0) == Tokens::modules::ispa_dep_scanner::COLON::id) {
		return -78;
	}
	if (state == 29 && window.at(0) == Tokens::modules::ispa_dep_scanner::LBRACE::id) {
		return -78;
	}
	if (state == 29 && window.at(0) == Tokens::modules::ispa_dep_scanner::RBRACE::id) {
		return -78;
	}
	if (state == 29 && window.at(0) == Tokens::modules::ispa_dep_scanner::SEMI::id) {
		return -78;
	}
	if (state == 30 && window.at(0) == Tokens::COMMA::id) {
		return -136;
	}
	if (state == 30 && window.at(0) == Tokens::modules::common::PY_RAW::id) {
		return -136;
	}
	if (state == 30 && window.at(0) == Tokens::modules::ispa_dep_scanner::COLON::id) {
		return -136;
	}
	if (state == 30 && window.at(0) == Tokens::modules::ispa_dep_scanner::LBRACE::id) {
		return -136;
	}
	if (state == 30 && window.at(0) == Tokens::modules::ispa_dep_scanner::RBRACE::id) {
		return -136;
	}
	if (state == 30 && window.at(0) == Tokens::modules::ispa_dep_scanner::SEMI::id) {
		return -136;
	}
	if (state == 31 && window.at(0) == Tokens::modules::ispa_dep_scanner::SEMI::id) {
		return 67;
	}
	if (state == 32 && window.at(0) == Tokens::modules::ispa_dep_scanner::SEMI::id) {
		return -101;
	}
	if (state == 33 && window.at(0) == Tokens::modules::ispa_dep_scanner::SEMI::id) {
		return -102;
	}
	if (state == 34 && window.at(0) == Tokens::AUTO::id) {
		return -73;
	}
	if (state == 34 && window.at(0) == Tokens::COMMA::id) {
		return -73;
	}
	if (state == 34 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -73;
	}
	if (state == 34 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -73;
	}
	if (state == 34 && window.at(0) == Tokens::modules::common::PY_RAW::id) {
		return -73;
	}
	if (state == 34 && window.at(0) == Tokens::modules::ispa_dep_scanner::COLON::id) {
		return -73;
	}
	if (state == 34 && window.at(0) == Tokens::modules::ispa_dep_scanner::LBRACE::id) {
		return -73;
	}
	if (state == 34 && window.at(0) == Tokens::modules::ispa_dep_scanner::RBRACE::id) {
		return -73;
	}
	if (state == 34 && window.at(0) == Tokens::modules::ispa_dep_scanner::SEMI::id) {
		return -73;
	}
	if (state == 35 && window.at(0) == Tokens::modules::common::PY_RAW::id) {
		return 68;
	}
	if (state == 36 && window.at(0) == Tokens::modules::ispa_dep_scanner::LBRACE::id) {
		return 69;
	}
	if (state == 37 && window.at(0) == Tokens::modules::common::ID::id) {
		return -123;
	}
	if (state == 37 && window.at(0) == Tokens::modules::ispa_dep_scanner::AS::id) {
		return -123;
	}
	if (state == 37 && window.at(0) == Tokens::modules::ispa_dep_scanner::DETACH::id) {
		return -123;
	}
	if (state == 37 && window.at(0) == Tokens::modules::ispa_dep_scanner::FAIL::id) {
		return -123;
	}
	if (state == 37 && window.at(0) == Tokens::modules::ispa_dep_scanner::FEATURE::id) {
		return -123;
	}
	if (state == 37 && window.at(0) == Tokens::modules::ispa_dep_scanner::FROM::id) {
		return -123;
	}
	if (state == 37 && window.at(0) == Tokens::modules::ispa_dep_scanner::HASH::id) {
		return -123;
	}
	if (state == 37 && window.at(0) == Tokens::modules::ispa_dep_scanner::IMPORT::id) {
		return -123;
	}
	if (state == 37 && window.at(0) == Tokens::modules::ispa_dep_scanner::MODULE::id) {
		return -123;
	}
	if (state == 38 && window.at(0) == Tokens::AUTO::id) {
		return -62;
	}
	if (state == 38 && window.at(0) == Tokens::COMMA::id) {
		return -62;
	}
	if (state == 38 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -62;
	}
	if (state == 38 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -62;
	}
	if (state == 38 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -62;
	}
	if (state == 38 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -62;
	}
	if (state == 38 && window.at(0) == Tokens::modules::common::ID::id) {
		return -62;
	}
	if (state == 38 && window.at(0) == Tokens::modules::common::NUMBER::id) {
		return -62;
	}
	if (state == 38 && window.at(0) == Tokens::modules::common::PY_RAW::id) {
		return -62;
	}
	if (state == 38 && window.at(0) == Tokens::modules::ispa_dep_scanner::ALL::id) {
		return -62;
	}
	if (state == 38 && window.at(0) == Tokens::modules::ispa_dep_scanner::AS::id) {
		return -62;
	}
	if (state == 38 && window.at(0) == Tokens::modules::ispa_dep_scanner::CGROUP::id) {
		return -62;
	}
	if (state == 38 && window.at(0) == Tokens::modules::ispa_dep_scanner::COLON::id) {
		return -62;
	}
	if (state == 38 && window.at(0) == Tokens::modules::ispa_dep_scanner::COMMENT::id) {
		return -62;
	}
	if (state == 38 && window.at(0) == Tokens::modules::ispa_dep_scanner::DETACH::id) {
		return -62;
	}
	if (state == 38 && window.at(0) == Tokens::modules::ispa_dep_scanner::DOT::id) {
		return -62;
	}
	if (state == 38 && window.at(0) == Tokens::modules::ispa_dep_scanner::FAIL::id) {
		return -62;
	}
	if (state == 38 && window.at(0) == Tokens::modules::ispa_dep_scanner::FEATURE::id) {
		return -62;
	}
	if (state == 38 && window.at(0) == Tokens::modules::ispa_dep_scanner::FROM::id) {
		return -62;
	}
	if (state == 38 && window.at(0) == Tokens::modules::ispa_dep_scanner::HASH::id) {
		return -62;
	}
	if (state == 38 && window.at(0) == Tokens::modules::ispa_dep_scanner::IMPORT::id) {
		return -62;
	}
	if (state == 38 && window.at(0) == Tokens::modules::ispa_dep_scanner::LBRACE::id) {
		return -62;
	}
	if (state == 38 && window.at(0) == Tokens::modules::ispa_dep_scanner::MODULE::id) {
		return -62;
	}
	if (state == 38 && window.at(0) == Tokens::modules::ispa_dep_scanner::OTHER::id) {
		return -62;
	}
	if (state == 38 && window.at(0) == Tokens::modules::ispa_dep_scanner::RBRACE::id) {
		return -62;
	}
	if (state == 38 && window.at(0) == Tokens::modules::ispa_dep_scanner::SEMI::id) {
		return -62;
	}
	if (state == 38 && window.at(0) == Tokens::modules::ispa_dep_scanner::STRING::id) {
		return -62;
	}
	if (state == 39 && window.at(0) == Tokens::modules::ispa_dep_scanner::FROM::id) {
		return -108;
	}
	if (state == 40 && window.at(0) == Tokens::AUTO::id) {
		return -67;
	}
	if (state == 40 && window.at(0) == Tokens::COMMA::id) {
		return -67;
	}
	if (state == 40 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -67;
	}
	if (state == 40 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -67;
	}
	if (state == 40 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -67;
	}
	if (state == 40 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -67;
	}
	if (state == 40 && window.at(0) == Tokens::modules::common::ID::id) {
		return -67;
	}
	if (state == 40 && window.at(0) == Tokens::modules::common::NUMBER::id) {
		return -67;
	}
	if (state == 40 && window.at(0) == Tokens::modules::common::PY_RAW::id) {
		return -67;
	}
	if (state == 40 && window.at(0) == Tokens::modules::ispa_dep_scanner::ALL::id) {
		return -67;
	}
	if (state == 40 && window.at(0) == Tokens::modules::ispa_dep_scanner::AS::id) {
		return -67;
	}
	if (state == 40 && window.at(0) == Tokens::modules::ispa_dep_scanner::CGROUP::id) {
		return -67;
	}
	if (state == 40 && window.at(0) == Tokens::modules::ispa_dep_scanner::COLON::id) {
		return -67;
	}
	if (state == 40 && window.at(0) == Tokens::modules::ispa_dep_scanner::COMMENT::id) {
		return -67;
	}
	if (state == 40 && window.at(0) == Tokens::modules::ispa_dep_scanner::DETACH::id) {
		return -67;
	}
	if (state == 40 && window.at(0) == Tokens::modules::ispa_dep_scanner::DOT::id) {
		return -67;
	}
	if (state == 40 && window.at(0) == Tokens::modules::ispa_dep_scanner::FAIL::id) {
		return -67;
	}
	if (state == 40 && window.at(0) == Tokens::modules::ispa_dep_scanner::FEATURE::id) {
		return -67;
	}
	if (state == 40 && window.at(0) == Tokens::modules::ispa_dep_scanner::FROM::id) {
		return -67;
	}
	if (state == 40 && window.at(0) == Tokens::modules::ispa_dep_scanner::HASH::id) {
		return -67;
	}
	if (state == 40 && window.at(0) == Tokens::modules::ispa_dep_scanner::IMPORT::id) {
		return -67;
	}
	if (state == 40 && window.at(0) == Tokens::modules::ispa_dep_scanner::LBRACE::id) {
		return -67;
	}
	if (state == 40 && window.at(0) == Tokens::modules::ispa_dep_scanner::MODULE::id) {
		return -67;
	}
	if (state == 40 && window.at(0) == Tokens::modules::ispa_dep_scanner::OTHER::id) {
		return -67;
	}
	if (state == 40 && window.at(0) == Tokens::modules::ispa_dep_scanner::RBRACE::id) {
		return -67;
	}
	if (state == 40 && window.at(0) == Tokens::modules::ispa_dep_scanner::SEMI::id) {
		return -67;
	}
	if (state == 40 && window.at(0) == Tokens::modules::ispa_dep_scanner::STRING::id) {
		return -67;
	}
	if (state == 41 && window.at(0) == Tokens::AUTO::id) {
		return -65;
	}
	if (state == 41 && window.at(0) == Tokens::COMMA::id) {
		return -65;
	}
	if (state == 41 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -65;
	}
	if (state == 41 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -65;
	}
	if (state == 41 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -65;
	}
	if (state == 41 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -65;
	}
	if (state == 41 && window.at(0) == Tokens::modules::common::ID::id) {
		return -65;
	}
	if (state == 41 && window.at(0) == Tokens::modules::common::NUMBER::id) {
		return -65;
	}
	if (state == 41 && window.at(0) == Tokens::modules::common::PY_RAW::id) {
		return -65;
	}
	if (state == 41 && window.at(0) == Tokens::modules::ispa_dep_scanner::ALL::id) {
		return -65;
	}
	if (state == 41 && window.at(0) == Tokens::modules::ispa_dep_scanner::AS::id) {
		return -65;
	}
	if (state == 41 && window.at(0) == Tokens::modules::ispa_dep_scanner::CGROUP::id) {
		return -65;
	}
	if (state == 41 && window.at(0) == Tokens::modules::ispa_dep_scanner::COLON::id) {
		return -65;
	}
	if (state == 41 && window.at(0) == Tokens::modules::ispa_dep_scanner::COMMENT::id) {
		return -65;
	}
	if (state == 41 && window.at(0) == Tokens::modules::ispa_dep_scanner::DETACH::id) {
		return -65;
	}
	if (state == 41 && window.at(0) == Tokens::modules::ispa_dep_scanner::DOT::id) {
		return -65;
	}
	if (state == 41 && window.at(0) == Tokens::modules::ispa_dep_scanner::FAIL::id) {
		return -65;
	}
	if (state == 41 && window.at(0) == Tokens::modules::ispa_dep_scanner::FEATURE::id) {
		return -65;
	}
	if (state == 41 && window.at(0) == Tokens::modules::ispa_dep_scanner::FROM::id) {
		return -65;
	}
	if (state == 41 && window.at(0) == Tokens::modules::ispa_dep_scanner::HASH::id) {
		return -65;
	}
	if (state == 41 && window.at(0) == Tokens::modules::ispa_dep_scanner::IMPORT::id) {
		return -65;
	}
	if (state == 41 && window.at(0) == Tokens::modules::ispa_dep_scanner::LBRACE::id) {
		return -65;
	}
	if (state == 41 && window.at(0) == Tokens::modules::ispa_dep_scanner::MODULE::id) {
		return -65;
	}
	if (state == 41 && window.at(0) == Tokens::modules::ispa_dep_scanner::OTHER::id) {
		return -65;
	}
	if (state == 41 && window.at(0) == Tokens::modules::ispa_dep_scanner::RBRACE::id) {
		return -65;
	}
	if (state == 41 && window.at(0) == Tokens::modules::ispa_dep_scanner::SEMI::id) {
		return -65;
	}
	if (state == 41 && window.at(0) == Tokens::modules::ispa_dep_scanner::STRING::id) {
		return -65;
	}
	if (state == 42 && window.at(0) == Tokens::AUTO::id) {
		return -69;
	}
	if (state == 42 && window.at(0) == Tokens::COMMA::id) {
		return -69;
	}
	if (state == 42 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -69;
	}
	if (state == 42 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -69;
	}
	if (state == 42 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -69;
	}
	if (state == 42 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -69;
	}
	if (state == 42 && window.at(0) == Tokens::modules::common::ID::id) {
		return -69;
	}
	if (state == 42 && window.at(0) == Tokens::modules::common::NUMBER::id) {
		return -69;
	}
	if (state == 42 && window.at(0) == Tokens::modules::common::PY_RAW::id) {
		return -69;
	}
	if (state == 42 && window.at(0) == Tokens::modules::ispa_dep_scanner::ALL::id) {
		return -69;
	}
	if (state == 42 && window.at(0) == Tokens::modules::ispa_dep_scanner::AS::id) {
		return -69;
	}
	if (state == 42 && window.at(0) == Tokens::modules::ispa_dep_scanner::CGROUP::id) {
		return -69;
	}
	if (state == 42 && window.at(0) == Tokens::modules::ispa_dep_scanner::COLON::id) {
		return -69;
	}
	if (state == 42 && window.at(0) == Tokens::modules::ispa_dep_scanner::COMMENT::id) {
		return -69;
	}
	if (state == 42 && window.at(0) == Tokens::modules::ispa_dep_scanner::DETACH::id) {
		return -69;
	}
	if (state == 42 && window.at(0) == Tokens::modules::ispa_dep_scanner::DOT::id) {
		return -69;
	}
	if (state == 42 && window.at(0) == Tokens::modules::ispa_dep_scanner::FAIL::id) {
		return -69;
	}
	if (state == 42 && window.at(0) == Tokens::modules::ispa_dep_scanner::FEATURE::id) {
		return -69;
	}
	if (state == 42 && window.at(0) == Tokens::modules::ispa_dep_scanner::FROM::id) {
		return -69;
	}
	if (state == 42 && window.at(0) == Tokens::modules::ispa_dep_scanner::HASH::id) {
		return -69;
	}
	if (state == 42 && window.at(0) == Tokens::modules::ispa_dep_scanner::IMPORT::id) {
		return -69;
	}
	if (state == 42 && window.at(0) == Tokens::modules::ispa_dep_scanner::LBRACE::id) {
		return -69;
	}
	if (state == 42 && window.at(0) == Tokens::modules::ispa_dep_scanner::MODULE::id) {
		return -69;
	}
	if (state == 42 && window.at(0) == Tokens::modules::ispa_dep_scanner::OTHER::id) {
		return -69;
	}
	if (state == 42 && window.at(0) == Tokens::modules::ispa_dep_scanner::RBRACE::id) {
		return -69;
	}
	if (state == 42 && window.at(0) == Tokens::modules::ispa_dep_scanner::SEMI::id) {
		return -69;
	}
	if (state == 42 && window.at(0) == Tokens::modules::ispa_dep_scanner::STRING::id) {
		return -69;
	}
	if (state == 43 && window.at(0) == Tokens::AUTO::id) {
		return -66;
	}
	if (state == 43 && window.at(0) == Tokens::COMMA::id) {
		return -66;
	}
	if (state == 43 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -66;
	}
	if (state == 43 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -66;
	}
	if (state == 43 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -66;
	}
	if (state == 43 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -66;
	}
	if (state == 43 && window.at(0) == Tokens::modules::common::ID::id) {
		return -66;
	}
	if (state == 43 && window.at(0) == Tokens::modules::common::NUMBER::id) {
		return -66;
	}
	if (state == 43 && window.at(0) == Tokens::modules::common::PY_RAW::id) {
		return -66;
	}
	if (state == 43 && window.at(0) == Tokens::modules::ispa_dep_scanner::ALL::id) {
		return -66;
	}
	if (state == 43 && window.at(0) == Tokens::modules::ispa_dep_scanner::AS::id) {
		return -66;
	}
	if (state == 43 && window.at(0) == Tokens::modules::ispa_dep_scanner::CGROUP::id) {
		return -66;
	}
	if (state == 43 && window.at(0) == Tokens::modules::ispa_dep_scanner::COLON::id) {
		return -66;
	}
	if (state == 43 && window.at(0) == Tokens::modules::ispa_dep_scanner::COMMENT::id) {
		return -66;
	}
	if (state == 43 && window.at(0) == Tokens::modules::ispa_dep_scanner::DETACH::id) {
		return -66;
	}
	if (state == 43 && window.at(0) == Tokens::modules::ispa_dep_scanner::DOT::id) {
		return -66;
	}
	if (state == 43 && window.at(0) == Tokens::modules::ispa_dep_scanner::FAIL::id) {
		return -66;
	}
	if (state == 43 && window.at(0) == Tokens::modules::ispa_dep_scanner::FEATURE::id) {
		return -66;
	}
	if (state == 43 && window.at(0) == Tokens::modules::ispa_dep_scanner::FROM::id) {
		return -66;
	}
	if (state == 43 && window.at(0) == Tokens::modules::ispa_dep_scanner::HASH::id) {
		return -66;
	}
	if (state == 43 && window.at(0) == Tokens::modules::ispa_dep_scanner::IMPORT::id) {
		return -66;
	}
	if (state == 43 && window.at(0) == Tokens::modules::ispa_dep_scanner::LBRACE::id) {
		return -66;
	}
	if (state == 43 && window.at(0) == Tokens::modules::ispa_dep_scanner::MODULE::id) {
		return -66;
	}
	if (state == 43 && window.at(0) == Tokens::modules::ispa_dep_scanner::OTHER::id) {
		return -66;
	}
	if (state == 43 && window.at(0) == Tokens::modules::ispa_dep_scanner::RBRACE::id) {
		return -66;
	}
	if (state == 43 && window.at(0) == Tokens::modules::ispa_dep_scanner::SEMI::id) {
		return -66;
	}
	if (state == 43 && window.at(0) == Tokens::modules::ispa_dep_scanner::STRING::id) {
		return -66;
	}
	if (state == 44 && window.at(0) == Tokens::AUTO::id) {
		return -68;
	}
	if (state == 44 && window.at(0) == Tokens::COMMA::id) {
		return -68;
	}
	if (state == 44 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -68;
	}
	if (state == 44 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -68;
	}
	if (state == 44 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -68;
	}
	if (state == 44 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -68;
	}
	if (state == 44 && window.at(0) == Tokens::modules::common::ID::id) {
		return -68;
	}
	if (state == 44 && window.at(0) == Tokens::modules::common::NUMBER::id) {
		return -68;
	}
	if (state == 44 && window.at(0) == Tokens::modules::common::PY_RAW::id) {
		return -68;
	}
	if (state == 44 && window.at(0) == Tokens::modules::ispa_dep_scanner::ALL::id) {
		return -68;
	}
	if (state == 44 && window.at(0) == Tokens::modules::ispa_dep_scanner::AS::id) {
		return -68;
	}
	if (state == 44 && window.at(0) == Tokens::modules::ispa_dep_scanner::CGROUP::id) {
		return -68;
	}
	if (state == 44 && window.at(0) == Tokens::modules::ispa_dep_scanner::COLON::id) {
		return -68;
	}
	if (state == 44 && window.at(0) == Tokens::modules::ispa_dep_scanner::COMMENT::id) {
		return -68;
	}
	if (state == 44 && window.at(0) == Tokens::modules::ispa_dep_scanner::DETACH::id) {
		return -68;
	}
	if (state == 44 && window.at(0) == Tokens::modules::ispa_dep_scanner::DOT::id) {
		return -68;
	}
	if (state == 44 && window.at(0) == Tokens::modules::ispa_dep_scanner::FAIL::id) {
		return -68;
	}
	if (state == 44 && window.at(0) == Tokens::modules::ispa_dep_scanner::FEATURE::id) {
		return -68;
	}
	if (state == 44 && window.at(0) == Tokens::modules::ispa_dep_scanner::FROM::id) {
		return -68;
	}
	if (state == 44 && window.at(0) == Tokens::modules::ispa_dep_scanner::HASH::id) {
		return -68;
	}
	if (state == 44 && window.at(0) == Tokens::modules::ispa_dep_scanner::IMPORT::id) {
		return -68;
	}
	if (state == 44 && window.at(0) == Tokens::modules::ispa_dep_scanner::LBRACE::id) {
		return -68;
	}
	if (state == 44 && window.at(0) == Tokens::modules::ispa_dep_scanner::MODULE::id) {
		return -68;
	}
	if (state == 44 && window.at(0) == Tokens::modules::ispa_dep_scanner::OTHER::id) {
		return -68;
	}
	if (state == 44 && window.at(0) == Tokens::modules::ispa_dep_scanner::RBRACE::id) {
		return -68;
	}
	if (state == 44 && window.at(0) == Tokens::modules::ispa_dep_scanner::SEMI::id) {
		return -68;
	}
	if (state == 44 && window.at(0) == Tokens::modules::ispa_dep_scanner::STRING::id) {
		return -68;
	}
	if (state == 45 && window.at(0) == Tokens::AUTO::id) {
		return -64;
	}
	if (state == 45 && window.at(0) == Tokens::COMMA::id) {
		return -64;
	}
	if (state == 45 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -64;
	}
	if (state == 45 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -64;
	}
	if (state == 45 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -64;
	}
	if (state == 45 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -64;
	}
	if (state == 45 && window.at(0) == Tokens::modules::common::ID::id) {
		return -64;
	}
	if (state == 45 && window.at(0) == Tokens::modules::common::NUMBER::id) {
		return -64;
	}
	if (state == 45 && window.at(0) == Tokens::modules::common::PY_RAW::id) {
		return -64;
	}
	if (state == 45 && window.at(0) == Tokens::modules::ispa_dep_scanner::ALL::id) {
		return -64;
	}
	if (state == 45 && window.at(0) == Tokens::modules::ispa_dep_scanner::AS::id) {
		return -64;
	}
	if (state == 45 && window.at(0) == Tokens::modules::ispa_dep_scanner::CGROUP::id) {
		return -64;
	}
	if (state == 45 && window.at(0) == Tokens::modules::ispa_dep_scanner::COLON::id) {
		return -64;
	}
	if (state == 45 && window.at(0) == Tokens::modules::ispa_dep_scanner::COMMENT::id) {
		return -64;
	}
	if (state == 45 && window.at(0) == Tokens::modules::ispa_dep_scanner::DETACH::id) {
		return -64;
	}
	if (state == 45 && window.at(0) == Tokens::modules::ispa_dep_scanner::DOT::id) {
		return -64;
	}
	if (state == 45 && window.at(0) == Tokens::modules::ispa_dep_scanner::FAIL::id) {
		return -64;
	}
	if (state == 45 && window.at(0) == Tokens::modules::ispa_dep_scanner::FEATURE::id) {
		return -64;
	}
	if (state == 45 && window.at(0) == Tokens::modules::ispa_dep_scanner::FROM::id) {
		return -64;
	}
	if (state == 45 && window.at(0) == Tokens::modules::ispa_dep_scanner::HASH::id) {
		return -64;
	}
	if (state == 45 && window.at(0) == Tokens::modules::ispa_dep_scanner::IMPORT::id) {
		return -64;
	}
	if (state == 45 && window.at(0) == Tokens::modules::ispa_dep_scanner::LBRACE::id) {
		return -64;
	}
	if (state == 45 && window.at(0) == Tokens::modules::ispa_dep_scanner::MODULE::id) {
		return -64;
	}
	if (state == 45 && window.at(0) == Tokens::modules::ispa_dep_scanner::OTHER::id) {
		return -64;
	}
	if (state == 45 && window.at(0) == Tokens::modules::ispa_dep_scanner::RBRACE::id) {
		return -64;
	}
	if (state == 45 && window.at(0) == Tokens::modules::ispa_dep_scanner::SEMI::id) {
		return -64;
	}
	if (state == 45 && window.at(0) == Tokens::modules::ispa_dep_scanner::STRING::id) {
		return -64;
	}
	if (state == 46 && window.at(0) == Tokens::modules::common::ID::id) {
		return 21;
	}
	if (state == 46 && window.at(0) == Tokens::modules::ispa_dep_scanner::AS::id) {
		return 23;
	}
	if (state == 46 && window.at(0) == Tokens::modules::ispa_dep_scanner::DETACH::id) {
		return 24;
	}
	if (state == 46 && window.at(0) == Tokens::modules::ispa_dep_scanner::FAIL::id) {
		return 25;
	}
	if (state == 46 && window.at(0) == Tokens::modules::ispa_dep_scanner::FEATURE::id) {
		return 35;
	}
	if (state == 46 && window.at(0) == Tokens::modules::ispa_dep_scanner::FROM::id) {
		return 27;
	}
	if (state == 46 && window.at(0) == Tokens::modules::ispa_dep_scanner::IMPORT::id) {
		return 28;
	}
	if (state == 46 && window.at(0) == Tokens::modules::ispa_dep_scanner::MODULE::id) {
		return 29;
	}
	if (state == 47 && window.at(0) == Tokens::AUTO::id) {
		return -63;
	}
	if (state == 47 && window.at(0) == Tokens::COMMA::id) {
		return -63;
	}
	if (state == 47 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -63;
	}
	if (state == 47 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -63;
	}
	if (state == 47 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -63;
	}
	if (state == 47 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -63;
	}
	if (state == 47 && window.at(0) == Tokens::modules::common::ID::id) {
		return -63;
	}
	if (state == 47 && window.at(0) == Tokens::modules::common::NUMBER::id) {
		return -63;
	}
	if (state == 47 && window.at(0) == Tokens::modules::common::PY_RAW::id) {
		return -63;
	}
	if (state == 47 && window.at(0) == Tokens::modules::ispa_dep_scanner::ALL::id) {
		return -63;
	}
	if (state == 47 && window.at(0) == Tokens::modules::ispa_dep_scanner::AS::id) {
		return -63;
	}
	if (state == 47 && window.at(0) == Tokens::modules::ispa_dep_scanner::CGROUP::id) {
		return -63;
	}
	if (state == 47 && window.at(0) == Tokens::modules::ispa_dep_scanner::COLON::id) {
		return -63;
	}
	if (state == 47 && window.at(0) == Tokens::modules::ispa_dep_scanner::COMMENT::id) {
		return -63;
	}
	if (state == 47 && window.at(0) == Tokens::modules::ispa_dep_scanner::DETACH::id) {
		return -63;
	}
	if (state == 47 && window.at(0) == Tokens::modules::ispa_dep_scanner::DOT::id) {
		return -63;
	}
	if (state == 47 && window.at(0) == Tokens::modules::ispa_dep_scanner::FAIL::id) {
		return -63;
	}
	if (state == 47 && window.at(0) == Tokens::modules::ispa_dep_scanner::FEATURE::id) {
		return -63;
	}
	if (state == 47 && window.at(0) == Tokens::modules::ispa_dep_scanner::FROM::id) {
		return -63;
	}
	if (state == 47 && window.at(0) == Tokens::modules::ispa_dep_scanner::HASH::id) {
		return -63;
	}
	if (state == 47 && window.at(0) == Tokens::modules::ispa_dep_scanner::IMPORT::id) {
		return -63;
	}
	if (state == 47 && window.at(0) == Tokens::modules::ispa_dep_scanner::LBRACE::id) {
		return -63;
	}
	if (state == 47 && window.at(0) == Tokens::modules::ispa_dep_scanner::MODULE::id) {
		return -63;
	}
	if (state == 47 && window.at(0) == Tokens::modules::ispa_dep_scanner::OTHER::id) {
		return -63;
	}
	if (state == 47 && window.at(0) == Tokens::modules::ispa_dep_scanner::RBRACE::id) {
		return -63;
	}
	if (state == 47 && window.at(0) == Tokens::modules::ispa_dep_scanner::SEMI::id) {
		return -63;
	}
	if (state == 47 && window.at(0) == Tokens::modules::ispa_dep_scanner::STRING::id) {
		return -63;
	}
	if (state == 48 && window.at(0) == Tokens::AUTO::id) {
		return -125;
	}
	if (state == 48 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -125;
	}
	if (state == 48 && window.at(0) == Tokens::modules::ispa_dep_scanner::AS::id) {
		return -125;
	}
	if (state == 48 && window.at(0) == Tokens::modules::ispa_dep_scanner::DOT::id) {
		return 71;
	}
	if (state == 48 && window.at(0) == Tokens::modules::ispa_dep_scanner::SEMI::id) {
		return -125;
	}
	if (state == 49 && window.at(0) == Tokens::modules::ispa_dep_scanner::SEMI::id) {
		return 73;
	}
	if (state == 50 && window.at(0) == Tokens::modules::ispa_dep_scanner::SEMI::id) {
		return -106;
	}
	if (state == 51 && window.at(0) == Tokens::modules::ispa_dep_scanner::FROM::id) {
		return 74;
	}
	if (state == 52 && window.at(0) == Tokens::modules::ispa_dep_scanner::FROM::id) {
		return -109;
	}
	if (state == 53 && window.at(0) == Tokens::modules::ispa_dep_scanner::SEMI::id) {
		return -105;
	}
	if (state == 54 && window.at(0) == Tokens::modules::ispa_dep_scanner::AS::id) {
		return 75;
	}
	if (state == 54 && window.at(0) == Tokens::modules::ispa_dep_scanner::SEMI::id) {
		return -116;
	}
	if (state == 55 && window.at(0) == Tokens::AUTO::id) {
		return -121;
	}
	if (state == 55 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return 77;
	}
	if (state == 55 && window.at(0) == Tokens::modules::ispa_dep_scanner::SEMI::id) {
		return -121;
	}
	if (state == 56 && window.at(0) == Tokens::modules::ispa_dep_scanner::COLON::id) {
		return 80;
	}
	if (state == 56 && window.at(0) == Tokens::modules::ispa_dep_scanner::LBRACE::id) {
		return 81;
	}
	if (state == 57 && window.at(0) == static_cast<std::size_t>(-1)) {
		return -94;
	}
	if (state == 57 && window.at(0) == Tokens::modules::common::ID::id) {
		return -54;
	}
	if (state == 57 && window.at(0) == Tokens::modules::ispa_dep_scanner::AS::id) {
		return -54;
	}
	if (state == 57 && window.at(0) == Tokens::modules::ispa_dep_scanner::COMMENT::id) {
		return 3;
	}
	if (state == 57 && window.at(0) == Tokens::modules::ispa_dep_scanner::FROM::id) {
		return -54;
	}
	if (state == 57 && window.at(0) == Tokens::modules::ispa_dep_scanner::HASH::id) {
		return 7;
	}
	if (state == 58 && window.at(0) == static_cast<std::size_t>(-1)) {
		return -86;
	}
	if (state == 59 && window.at(0) == Tokens::modules::common::ID::id) {
		return -55;
	}
	if (state == 59 && window.at(0) == Tokens::modules::ispa_dep_scanner::AS::id) {
		return -55;
	}
	if (state == 59 && window.at(0) == Tokens::modules::ispa_dep_scanner::DETACH::id) {
		return -55;
	}
	if (state == 59 && window.at(0) == Tokens::modules::ispa_dep_scanner::FAIL::id) {
		return -55;
	}
	if (state == 59 && window.at(0) == Tokens::modules::ispa_dep_scanner::FEATURE::id) {
		return -55;
	}
	if (state == 59 && window.at(0) == Tokens::modules::ispa_dep_scanner::FROM::id) {
		return -55;
	}
	if (state == 59 && window.at(0) == Tokens::modules::ispa_dep_scanner::IMPORT::id) {
		return -55;
	}
	if (state == 59 && window.at(0) == Tokens::modules::ispa_dep_scanner::MODULE::id) {
		return -55;
	}
	if (state == 60 && window.at(0) == Tokens::modules::common::ID::id) {
		return -56;
	}
	if (state == 60 && window.at(0) == Tokens::modules::ispa_dep_scanner::AS::id) {
		return -56;
	}
	if (state == 60 && window.at(0) == Tokens::modules::ispa_dep_scanner::DETACH::id) {
		return -56;
	}
	if (state == 60 && window.at(0) == Tokens::modules::ispa_dep_scanner::FAIL::id) {
		return -56;
	}
	if (state == 60 && window.at(0) == Tokens::modules::ispa_dep_scanner::FEATURE::id) {
		return -56;
	}
	if (state == 60 && window.at(0) == Tokens::modules::ispa_dep_scanner::FROM::id) {
		return -56;
	}
	if (state == 60 && window.at(0) == Tokens::modules::ispa_dep_scanner::HASH::id) {
		return 7;
	}
	if (state == 60 && window.at(0) == Tokens::modules::ispa_dep_scanner::IMPORT::id) {
		return -56;
	}
	if (state == 60 && window.at(0) == Tokens::modules::ispa_dep_scanner::MODULE::id) {
		return -56;
	}
	if (state == 61 && window.at(0) == Tokens::modules::common::ID::id) {
		return 87;
	}
	if (state == 62 && window.at(0) == Tokens::COMMA::id) {
		return -7;
	}
	if (state == 62 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -7;
	}
	if (state == 62 && window.at(0) == Tokens::modules::common::PY_RAW::id) {
		return -7;
	}
	if (state == 62 && window.at(0) == Tokens::modules::ispa_dep_scanner::COLON::id) {
		return -7;
	}
	if (state == 62 && window.at(0) == Tokens::modules::ispa_dep_scanner::LBRACE::id) {
		return -7;
	}
	if (state == 62 && window.at(0) == Tokens::modules::ispa_dep_scanner::RBRACE::id) {
		return -7;
	}
	if (state == 62 && window.at(0) == Tokens::modules::ispa_dep_scanner::SEMI::id) {
		return -7;
	}
	if (state == 63 && window.at(0) == Tokens::modules::ispa_dep_scanner::SEMI::id) {
		return -103;
	}
	if (state == 64 && window.at(0) == Tokens::modules::common::ID::id) {
		return 21;
	}
	if (state == 65 && window.at(0) == Tokens::COMMA::id) {
		return -80;
	}
	if (state == 65 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -80;
	}
	if (state == 65 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return 77;
	}
	if (state == 65 && window.at(0) == Tokens::modules::common::PY_RAW::id) {
		return -80;
	}
	if (state == 65 && window.at(0) == Tokens::modules::ispa_dep_scanner::COLON::id) {
		return -80;
	}
	if (state == 65 && window.at(0) == Tokens::modules::ispa_dep_scanner::LBRACE::id) {
		return -80;
	}
	if (state == 65 && window.at(0) == Tokens::modules::ispa_dep_scanner::RBRACE::id) {
		return -80;
	}
	if (state == 65 && window.at(0) == Tokens::modules::ispa_dep_scanner::SEMI::id) {
		return -80;
	}
	if (state == 66 && window.at(0) == static_cast<std::size_t>(-1)) {
		return -100;
	}
	if (state == 66 && window.at(0) == Tokens::modules::common::ID::id) {
		return -100;
	}
	if (state == 66 && window.at(0) == Tokens::modules::ispa_dep_scanner::AS::id) {
		return -100;
	}
	if (state == 66 && window.at(0) == Tokens::modules::ispa_dep_scanner::COMMENT::id) {
		return -100;
	}
	if (state == 66 && window.at(0) == Tokens::modules::ispa_dep_scanner::DETACH::id) {
		return -100;
	}
	if (state == 66 && window.at(0) == Tokens::modules::ispa_dep_scanner::FAIL::id) {
		return -100;
	}
	if (state == 66 && window.at(0) == Tokens::modules::ispa_dep_scanner::FEATURE::id) {
		return -100;
	}
	if (state == 66 && window.at(0) == Tokens::modules::ispa_dep_scanner::FROM::id) {
		return -100;
	}
	if (state == 66 && window.at(0) == Tokens::modules::ispa_dep_scanner::HASH::id) {
		return -100;
	}
	if (state == 66 && window.at(0) == Tokens::modules::ispa_dep_scanner::IMPORT::id) {
		return -100;
	}
	if (state == 66 && window.at(0) == Tokens::modules::ispa_dep_scanner::MODULE::id) {
		return -100;
	}
	if (state == 67 && window.at(0) == static_cast<std::size_t>(-1)) {
		return -58;
	}
	if (state == 67 && window.at(0) == Tokens::modules::common::ID::id) {
		return -58;
	}
	if (state == 67 && window.at(0) == Tokens::modules::ispa_dep_scanner::AS::id) {
		return -58;
	}
	if (state == 67 && window.at(0) == Tokens::modules::ispa_dep_scanner::COMMENT::id) {
		return -58;
	}
	if (state == 67 && window.at(0) == Tokens::modules::ispa_dep_scanner::DETACH::id) {
		return -58;
	}
	if (state == 67 && window.at(0) == Tokens::modules::ispa_dep_scanner::FAIL::id) {
		return -58;
	}
	if (state == 67 && window.at(0) == Tokens::modules::ispa_dep_scanner::FEATURE::id) {
		return -58;
	}
	if (state == 67 && window.at(0) == Tokens::modules::ispa_dep_scanner::FROM::id) {
		return -58;
	}
	if (state == 67 && window.at(0) == Tokens::modules::ispa_dep_scanner::HASH::id) {
		return -58;
	}
	if (state == 67 && window.at(0) == Tokens::modules::ispa_dep_scanner::IMPORT::id) {
		return -58;
	}
	if (state == 67 && window.at(0) == Tokens::modules::ispa_dep_scanner::MODULE::id) {
		return -58;
	}
	if (state == 68 && window.at(0) == Tokens::modules::common::ID::id) {
		return 21;
	}
	if (state == 68 && window.at(0) == Tokens::modules::ispa_dep_scanner::AS::id) {
		return 23;
	}
	if (state == 68 && window.at(0) == Tokens::modules::ispa_dep_scanner::DETACH::id) {
		return 24;
	}
	if (state == 68 && window.at(0) == Tokens::modules::ispa_dep_scanner::FAIL::id) {
		return 25;
	}
	if (state == 68 && window.at(0) == Tokens::modules::ispa_dep_scanner::FEATURE::id) {
		return 35;
	}
	if (state == 68 && window.at(0) == Tokens::modules::ispa_dep_scanner::FROM::id) {
		return 27;
	}
	if (state == 68 && window.at(0) == Tokens::modules::ispa_dep_scanner::IMPORT::id) {
		return 28;
	}
	if (state == 68 && window.at(0) == Tokens::modules::ispa_dep_scanner::MODULE::id) {
		return 29;
	}
	if (state == 68 && window.at(0) == Tokens::modules::ispa_dep_scanner::RBRACE::id) {
		return -60;
	}
	if (state == 69 && window.at(0) == Tokens::COMMA::id) {
		return 96;
	}
	if (state == 69 && window.at(0) == Tokens::modules::ispa_dep_scanner::RBRACE::id) {
		return -111;
	}
	if (state == 70 && window.at(0) == Tokens::modules::common::ID::id) {
		return 39;
	}
	if (state == 70 && window.at(0) == Tokens::modules::ispa_dep_scanner::AS::id) {
		return 41;
	}
	if (state == 70 && window.at(0) == Tokens::modules::ispa_dep_scanner::DETACH::id) {
		return 42;
	}
	if (state == 70 && window.at(0) == Tokens::modules::ispa_dep_scanner::FAIL::id) {
		return 43;
	}
	if (state == 70 && window.at(0) == Tokens::modules::ispa_dep_scanner::FEATURE::id) {
		return 44;
	}
	if (state == 70 && window.at(0) == Tokens::modules::ispa_dep_scanner::FROM::id) {
		return 45;
	}
	if (state == 70 && window.at(0) == Tokens::modules::ispa_dep_scanner::IMPORT::id) {
		return 46;
	}
	if (state == 70 && window.at(0) == Tokens::modules::ispa_dep_scanner::MODULE::id) {
		return 48;
	}
	if (state == 71 && window.at(0) == Tokens::AUTO::id) {
		return -124;
	}
	if (state == 71 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -124;
	}
	if (state == 71 && window.at(0) == Tokens::modules::ispa_dep_scanner::AS::id) {
		return -124;
	}
	if (state == 71 && window.at(0) == Tokens::modules::ispa_dep_scanner::SEMI::id) {
		return -124;
	}
	if (state == 72 && window.at(0) == static_cast<std::size_t>(-1)) {
		return -104;
	}
	if (state == 72 && window.at(0) == Tokens::modules::common::ID::id) {
		return -104;
	}
	if (state == 72 && window.at(0) == Tokens::modules::ispa_dep_scanner::AS::id) {
		return -104;
	}
	if (state == 72 && window.at(0) == Tokens::modules::ispa_dep_scanner::COMMENT::id) {
		return -104;
	}
	if (state == 72 && window.at(0) == Tokens::modules::ispa_dep_scanner::DETACH::id) {
		return -104;
	}
	if (state == 72 && window.at(0) == Tokens::modules::ispa_dep_scanner::FAIL::id) {
		return -104;
	}
	if (state == 72 && window.at(0) == Tokens::modules::ispa_dep_scanner::FEATURE::id) {
		return -104;
	}
	if (state == 72 && window.at(0) == Tokens::modules::ispa_dep_scanner::FROM::id) {
		return -104;
	}
	if (state == 72 && window.at(0) == Tokens::modules::ispa_dep_scanner::HASH::id) {
		return -104;
	}
	if (state == 72 && window.at(0) == Tokens::modules::ispa_dep_scanner::IMPORT::id) {
		return -104;
	}
	if (state == 72 && window.at(0) == Tokens::modules::ispa_dep_scanner::MODULE::id) {
		return -104;
	}
	if (state == 73 && window.at(0) == Tokens::modules::common::ID::id) {
		return 39;
	}
	if (state == 73 && window.at(0) == Tokens::modules::ispa_dep_scanner::AS::id) {
		return 41;
	}
	if (state == 73 && window.at(0) == Tokens::modules::ispa_dep_scanner::DETACH::id) {
		return 42;
	}
	if (state == 73 && window.at(0) == Tokens::modules::ispa_dep_scanner::FAIL::id) {
		return 43;
	}
	if (state == 73 && window.at(0) == Tokens::modules::ispa_dep_scanner::FEATURE::id) {
		return 44;
	}
	if (state == 73 && window.at(0) == Tokens::modules::ispa_dep_scanner::FROM::id) {
		return 45;
	}
	if (state == 73 && window.at(0) == Tokens::modules::ispa_dep_scanner::IMPORT::id) {
		return 46;
	}
	if (state == 73 && window.at(0) == Tokens::modules::ispa_dep_scanner::MODULE::id) {
		return 48;
	}
	if (state == 74 && window.at(0) == Tokens::modules::common::ID::id) {
		return 39;
	}
	if (state == 74 && window.at(0) == Tokens::modules::ispa_dep_scanner::AS::id) {
		return 41;
	}
	if (state == 74 && window.at(0) == Tokens::modules::ispa_dep_scanner::DETACH::id) {
		return 42;
	}
	if (state == 74 && window.at(0) == Tokens::modules::ispa_dep_scanner::FAIL::id) {
		return 43;
	}
	if (state == 74 && window.at(0) == Tokens::modules::ispa_dep_scanner::FEATURE::id) {
		return 44;
	}
	if (state == 74 && window.at(0) == Tokens::modules::ispa_dep_scanner::FROM::id) {
		return 45;
	}
	if (state == 74 && window.at(0) == Tokens::modules::ispa_dep_scanner::IMPORT::id) {
		return 46;
	}
	if (state == 74 && window.at(0) == Tokens::modules::ispa_dep_scanner::MODULE::id) {
		return 48;
	}
	if (state == 75 && window.at(0) == Tokens::modules::ispa_dep_scanner::SEMI::id) {
		return -115;
	}
	if (state == 76 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -20;
	}
	if (state == 76 && window.at(0) == Tokens::modules::common::ID::id) {
		return 101;
	}
	if (state == 77 && window.at(0) == Tokens::AUTO::id) {
		return -122;
	}
	if (state == 77 && window.at(0) == Tokens::modules::ispa_dep_scanner::SEMI::id) {
		return -122;
	}
	if (state == 78 && window.at(0) == Tokens::AUTO::id) {
		return 104;
	}
	if (state == 78 && window.at(0) == Tokens::modules::ispa_dep_scanner::SEMI::id) {
		return -119;
	}
	if (state == 79 && window.at(0) == Tokens::AUTO::id) {
		return 106;
	}
	if (state == 79 && window.at(0) == Tokens::COMMA::id) {
		return 107;
	}
	if (state == 79 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return 108;
	}
	if (state == 79 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return 109;
	}
	if (state == 79 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return 110;
	}
	if (state == 79 && window.at(0) == Tokens::modules::common::ID::id) {
		return 39;
	}
	if (state == 79 && window.at(0) == Tokens::modules::common::NUMBER::id) {
		return 111;
	}
	if (state == 79 && window.at(0) == Tokens::modules::common::PY_RAW::id) {
		return 112;
	}
	if (state == 79 && window.at(0) == Tokens::modules::ispa_dep_scanner::ALL::id) {
		return 113;
	}
	if (state == 79 && window.at(0) == Tokens::modules::ispa_dep_scanner::AS::id) {
		return 41;
	}
	if (state == 79 && window.at(0) == Tokens::modules::ispa_dep_scanner::CGROUP::id) {
		return 114;
	}
	if (state == 79 && window.at(0) == Tokens::modules::ispa_dep_scanner::COLON::id) {
		return 115;
	}
	if (state == 79 && window.at(0) == Tokens::modules::ispa_dep_scanner::COMMENT::id) {
		return 116;
	}
	if (state == 79 && window.at(0) == Tokens::modules::ispa_dep_scanner::DETACH::id) {
		return 42;
	}
	if (state == 79 && window.at(0) == Tokens::modules::ispa_dep_scanner::DOT::id) {
		return 117;
	}
	if (state == 79 && window.at(0) == Tokens::modules::ispa_dep_scanner::FAIL::id) {
		return 43;
	}
	if (state == 79 && window.at(0) == Tokens::modules::ispa_dep_scanner::FEATURE::id) {
		return 44;
	}
	if (state == 79 && window.at(0) == Tokens::modules::ispa_dep_scanner::FROM::id) {
		return 45;
	}
	if (state == 79 && window.at(0) == Tokens::modules::ispa_dep_scanner::HASH::id) {
		return 118;
	}
	if (state == 79 && window.at(0) == Tokens::modules::ispa_dep_scanner::IMPORT::id) {
		return 46;
	}
	if (state == 79 && window.at(0) == Tokens::modules::ispa_dep_scanner::LBRACE::id) {
		return 81;
	}
	if (state == 79 && window.at(0) == Tokens::modules::ispa_dep_scanner::MODULE::id) {
		return 48;
	}
	if (state == 79 && window.at(0) == Tokens::modules::ispa_dep_scanner::OTHER::id) {
		return 119;
	}
	if (state == 79 && window.at(0) == Tokens::modules::ispa_dep_scanner::SEMI::id) {
		return -44;
	}
	if (state == 79 && window.at(0) == Tokens::modules::ispa_dep_scanner::STRING::id) {
		return 120;
	}
	if (state == 80 && window.at(0) == Tokens::AUTO::id) {
		return 106;
	}
	if (state == 80 && window.at(0) == Tokens::COMMA::id) {
		return 107;
	}
	if (state == 80 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return 108;
	}
	if (state == 80 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return 109;
	}
	if (state == 80 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return 110;
	}
	if (state == 80 && window.at(0) == Tokens::modules::common::ID::id) {
		return 39;
	}
	if (state == 80 && window.at(0) == Tokens::modules::common::NUMBER::id) {
		return 111;
	}
	if (state == 80 && window.at(0) == Tokens::modules::common::PY_RAW::id) {
		return 112;
	}
	if (state == 80 && window.at(0) == Tokens::modules::ispa_dep_scanner::ALL::id) {
		return 113;
	}
	if (state == 80 && window.at(0) == Tokens::modules::ispa_dep_scanner::AS::id) {
		return 41;
	}
	if (state == 80 && window.at(0) == Tokens::modules::ispa_dep_scanner::CGROUP::id) {
		return 114;
	}
	if (state == 80 && window.at(0) == Tokens::modules::ispa_dep_scanner::COLON::id) {
		return 115;
	}
	if (state == 80 && window.at(0) == Tokens::modules::ispa_dep_scanner::COMMENT::id) {
		return 116;
	}
	if (state == 80 && window.at(0) == Tokens::modules::ispa_dep_scanner::DETACH::id) {
		return 42;
	}
	if (state == 80 && window.at(0) == Tokens::modules::ispa_dep_scanner::DOT::id) {
		return 117;
	}
	if (state == 80 && window.at(0) == Tokens::modules::ispa_dep_scanner::FAIL::id) {
		return 43;
	}
	if (state == 80 && window.at(0) == Tokens::modules::ispa_dep_scanner::FEATURE::id) {
		return 44;
	}
	if (state == 80 && window.at(0) == Tokens::modules::ispa_dep_scanner::FROM::id) {
		return 45;
	}
	if (state == 80 && window.at(0) == Tokens::modules::ispa_dep_scanner::HASH::id) {
		return 128;
	}
	if (state == 80 && window.at(0) == Tokens::modules::ispa_dep_scanner::IMPORT::id) {
		return 46;
	}
	if (state == 80 && window.at(0) == Tokens::modules::ispa_dep_scanner::LBRACE::id) {
		return 81;
	}
	if (state == 80 && window.at(0) == Tokens::modules::ispa_dep_scanner::MODULE::id) {
		return 48;
	}
	if (state == 80 && window.at(0) == Tokens::modules::ispa_dep_scanner::OTHER::id) {
		return 119;
	}
	if (state == 80 && window.at(0) == Tokens::modules::ispa_dep_scanner::RBRACE::id) {
		return -49;
	}
	if (state == 80 && window.at(0) == Tokens::modules::ispa_dep_scanner::SEMI::id) {
		return 129;
	}
	if (state == 80 && window.at(0) == Tokens::modules::ispa_dep_scanner::STRING::id) {
		return 120;
	}
	if (state == 81 && window.at(0) == static_cast<std::size_t>(-1)) {
		return -53;
	}
	if (state == 81 && window.at(0) == Tokens::AUTO::id) {
		return -53;
	}
	if (state == 81 && window.at(0) == Tokens::COMMA::id) {
		return -53;
	}
	if (state == 81 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -53;
	}
	if (state == 81 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -53;
	}
	if (state == 81 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -53;
	}
	if (state == 81 && window.at(0) == Tokens::modules::common::ID::id) {
		return -53;
	}
	if (state == 81 && window.at(0) == Tokens::modules::common::NUMBER::id) {
		return -53;
	}
	if (state == 81 && window.at(0) == Tokens::modules::common::PY_RAW::id) {
		return -53;
	}
	if (state == 81 && window.at(0) == Tokens::modules::ispa_dep_scanner::ALL::id) {
		return -53;
	}
	if (state == 81 && window.at(0) == Tokens::modules::ispa_dep_scanner::AS::id) {
		return -53;
	}
	if (state == 81 && window.at(0) == Tokens::modules::ispa_dep_scanner::CGROUP::id) {
		return -53;
	}
	if (state == 81 && window.at(0) == Tokens::modules::ispa_dep_scanner::COLON::id) {
		return -53;
	}
	if (state == 81 && window.at(0) == Tokens::modules::ispa_dep_scanner::COMMENT::id) {
		return -53;
	}
	if (state == 81 && window.at(0) == Tokens::modules::ispa_dep_scanner::DETACH::id) {
		return -53;
	}
	if (state == 81 && window.at(0) == Tokens::modules::ispa_dep_scanner::DOT::id) {
		return -53;
	}
	if (state == 81 && window.at(0) == Tokens::modules::ispa_dep_scanner::FAIL::id) {
		return -53;
	}
	if (state == 81 && window.at(0) == Tokens::modules::ispa_dep_scanner::FEATURE::id) {
		return -53;
	}
	if (state == 81 && window.at(0) == Tokens::modules::ispa_dep_scanner::FROM::id) {
		return -53;
	}
	if (state == 81 && window.at(0) == Tokens::modules::ispa_dep_scanner::HASH::id) {
		return -53;
	}
	if (state == 81 && window.at(0) == Tokens::modules::ispa_dep_scanner::IMPORT::id) {
		return -53;
	}
	if (state == 81 && window.at(0) == Tokens::modules::ispa_dep_scanner::LBRACE::id) {
		return -53;
	}
	if (state == 81 && window.at(0) == Tokens::modules::ispa_dep_scanner::MODULE::id) {
		return -53;
	}
	if (state == 81 && window.at(0) == Tokens::modules::ispa_dep_scanner::OTHER::id) {
		return -53;
	}
	if (state == 81 && window.at(0) == Tokens::modules::ispa_dep_scanner::SEMI::id) {
		return -53;
	}
	if (state == 81 && window.at(0) == Tokens::modules::ispa_dep_scanner::STRING::id) {
		return -53;
	}
	if (state == 82 && window.at(0) == static_cast<std::size_t>(-1)) {
		return -41;
	}
	if (state == 82 && window.at(0) == Tokens::AUTO::id) {
		return -41;
	}
	if (state == 82 && window.at(0) == Tokens::COMMA::id) {
		return -41;
	}
	if (state == 82 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -41;
	}
	if (state == 82 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -41;
	}
	if (state == 82 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -41;
	}
	if (state == 82 && window.at(0) == Tokens::modules::common::ID::id) {
		return -41;
	}
	if (state == 82 && window.at(0) == Tokens::modules::common::NUMBER::id) {
		return -41;
	}
	if (state == 82 && window.at(0) == Tokens::modules::common::PY_RAW::id) {
		return -41;
	}
	if (state == 82 && window.at(0) == Tokens::modules::ispa_dep_scanner::ALL::id) {
		return -41;
	}
	if (state == 82 && window.at(0) == Tokens::modules::ispa_dep_scanner::AS::id) {
		return -41;
	}
	if (state == 82 && window.at(0) == Tokens::modules::ispa_dep_scanner::CGROUP::id) {
		return -41;
	}
	if (state == 82 && window.at(0) == Tokens::modules::ispa_dep_scanner::COLON::id) {
		return -41;
	}
	if (state == 82 && window.at(0) == Tokens::modules::ispa_dep_scanner::COMMENT::id) {
		return -41;
	}
	if (state == 82 && window.at(0) == Tokens::modules::ispa_dep_scanner::DETACH::id) {
		return -41;
	}
	if (state == 82 && window.at(0) == Tokens::modules::ispa_dep_scanner::DOT::id) {
		return -41;
	}
	if (state == 82 && window.at(0) == Tokens::modules::ispa_dep_scanner::FAIL::id) {
		return -41;
	}
	if (state == 82 && window.at(0) == Tokens::modules::ispa_dep_scanner::FEATURE::id) {
		return -41;
	}
	if (state == 82 && window.at(0) == Tokens::modules::ispa_dep_scanner::FROM::id) {
		return -41;
	}
	if (state == 82 && window.at(0) == Tokens::modules::ispa_dep_scanner::HASH::id) {
		return -41;
	}
	if (state == 82 && window.at(0) == Tokens::modules::ispa_dep_scanner::IMPORT::id) {
		return -41;
	}
	if (state == 82 && window.at(0) == Tokens::modules::ispa_dep_scanner::LBRACE::id) {
		return -41;
	}
	if (state == 82 && window.at(0) == Tokens::modules::ispa_dep_scanner::MODULE::id) {
		return -41;
	}
	if (state == 82 && window.at(0) == Tokens::modules::ispa_dep_scanner::OTHER::id) {
		return -41;
	}
	if (state == 82 && window.at(0) == Tokens::modules::ispa_dep_scanner::SEMI::id) {
		return -41;
	}
	if (state == 82 && window.at(0) == Tokens::modules::ispa_dep_scanner::STRING::id) {
		return -41;
	}
	if (state == 83 && window.at(0) == static_cast<std::size_t>(-1)) {
		return -42;
	}
	if (state == 83 && window.at(0) == Tokens::AUTO::id) {
		return -42;
	}
	if (state == 83 && window.at(0) == Tokens::COMMA::id) {
		return -42;
	}
	if (state == 83 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -42;
	}
	if (state == 83 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -42;
	}
	if (state == 83 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -42;
	}
	if (state == 83 && window.at(0) == Tokens::modules::common::ID::id) {
		return -42;
	}
	if (state == 83 && window.at(0) == Tokens::modules::common::NUMBER::id) {
		return -42;
	}
	if (state == 83 && window.at(0) == Tokens::modules::common::PY_RAW::id) {
		return -42;
	}
	if (state == 83 && window.at(0) == Tokens::modules::ispa_dep_scanner::ALL::id) {
		return -42;
	}
	if (state == 83 && window.at(0) == Tokens::modules::ispa_dep_scanner::AS::id) {
		return -42;
	}
	if (state == 83 && window.at(0) == Tokens::modules::ispa_dep_scanner::CGROUP::id) {
		return -42;
	}
	if (state == 83 && window.at(0) == Tokens::modules::ispa_dep_scanner::COLON::id) {
		return -42;
	}
	if (state == 83 && window.at(0) == Tokens::modules::ispa_dep_scanner::COMMENT::id) {
		return -42;
	}
	if (state == 83 && window.at(0) == Tokens::modules::ispa_dep_scanner::DETACH::id) {
		return -42;
	}
	if (state == 83 && window.at(0) == Tokens::modules::ispa_dep_scanner::DOT::id) {
		return -42;
	}
	if (state == 83 && window.at(0) == Tokens::modules::ispa_dep_scanner::FAIL::id) {
		return -42;
	}
	if (state == 83 && window.at(0) == Tokens::modules::ispa_dep_scanner::FEATURE::id) {
		return -42;
	}
	if (state == 83 && window.at(0) == Tokens::modules::ispa_dep_scanner::FROM::id) {
		return -42;
	}
	if (state == 83 && window.at(0) == Tokens::modules::ispa_dep_scanner::HASH::id) {
		return -42;
	}
	if (state == 83 && window.at(0) == Tokens::modules::ispa_dep_scanner::IMPORT::id) {
		return -42;
	}
	if (state == 83 && window.at(0) == Tokens::modules::ispa_dep_scanner::LBRACE::id) {
		return -42;
	}
	if (state == 83 && window.at(0) == Tokens::modules::ispa_dep_scanner::MODULE::id) {
		return -42;
	}
	if (state == 83 && window.at(0) == Tokens::modules::ispa_dep_scanner::OTHER::id) {
		return -42;
	}
	if (state == 83 && window.at(0) == Tokens::modules::ispa_dep_scanner::SEMI::id) {
		return -42;
	}
	if (state == 83 && window.at(0) == Tokens::modules::ispa_dep_scanner::STRING::id) {
		return -42;
	}
	if (state == 84 && window.at(0) == static_cast<std::size_t>(-1)) {
		return -95;
	}
	if (state == 85 && window.at(0) == Tokens::modules::common::ID::id) {
		return -57;
	}
	if (state == 85 && window.at(0) == Tokens::modules::ispa_dep_scanner::AS::id) {
		return -57;
	}
	if (state == 85 && window.at(0) == Tokens::modules::ispa_dep_scanner::DETACH::id) {
		return -57;
	}
	if (state == 85 && window.at(0) == Tokens::modules::ispa_dep_scanner::FAIL::id) {
		return -57;
	}
	if (state == 85 && window.at(0) == Tokens::modules::ispa_dep_scanner::FEATURE::id) {
		return -57;
	}
	if (state == 85 && window.at(0) == Tokens::modules::ispa_dep_scanner::FROM::id) {
		return -57;
	}
	if (state == 85 && window.at(0) == Tokens::modules::ispa_dep_scanner::IMPORT::id) {
		return -57;
	}
	if (state == 85 && window.at(0) == Tokens::modules::ispa_dep_scanner::MODULE::id) {
		return -57;
	}
	if (state == 86 && window.at(0) == Tokens::AUTO::id) {
		return 135;
	}
	if (state == 86 && window.at(0) == Tokens::COMMA::id) {
		return -5;
	}
	if (state == 86 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -5;
	}
	if (state == 86 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -5;
	}
	if (state == 86 && window.at(0) == Tokens::modules::common::PY_RAW::id) {
		return -5;
	}
	if (state == 86 && window.at(0) == Tokens::modules::ispa_dep_scanner::COLON::id) {
		return -5;
	}
	if (state == 86 && window.at(0) == Tokens::modules::ispa_dep_scanner::LBRACE::id) {
		return -5;
	}
	if (state == 86 && window.at(0) == Tokens::modules::ispa_dep_scanner::RBRACE::id) {
		return -5;
	}
	if (state == 86 && window.at(0) == Tokens::modules::ispa_dep_scanner::SEMI::id) {
		return -5;
	}
	if (state == 87 && window.at(0) == Tokens::COMMA::id) {
		return -9;
	}
	if (state == 87 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -9;
	}
	if (state == 87 && window.at(0) == Tokens::modules::common::PY_RAW::id) {
		return -9;
	}
	if (state == 87 && window.at(0) == Tokens::modules::ispa_dep_scanner::COLON::id) {
		return -9;
	}
	if (state == 87 && window.at(0) == Tokens::modules::ispa_dep_scanner::LBRACE::id) {
		return -9;
	}
	if (state == 87 && window.at(0) == Tokens::modules::ispa_dep_scanner::RBRACE::id) {
		return -9;
	}
	if (state == 87 && window.at(0) == Tokens::modules::ispa_dep_scanner::SEMI::id) {
		return -9;
	}
	if (state == 88 && window.at(0) == Tokens::COMMA::id) {
		return -8;
	}
	if (state == 88 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -8;
	}
	if (state == 88 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -8;
	}
	if (state == 88 && window.at(0) == Tokens::modules::common::PY_RAW::id) {
		return -8;
	}
	if (state == 88 && window.at(0) == Tokens::modules::ispa_dep_scanner::COLON::id) {
		return -8;
	}
	if (state == 88 && window.at(0) == Tokens::modules::ispa_dep_scanner::LBRACE::id) {
		return -8;
	}
	if (state == 88 && window.at(0) == Tokens::modules::ispa_dep_scanner::RBRACE::id) {
		return -8;
	}
	if (state == 88 && window.at(0) == Tokens::modules::ispa_dep_scanner::SEMI::id) {
		return -8;
	}
	if (state == 89 && window.at(0) == Tokens::COMMA::id) {
		return -79;
	}
	if (state == 89 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -79;
	}
	if (state == 89 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -79;
	}
	if (state == 89 && window.at(0) == Tokens::modules::common::PY_RAW::id) {
		return -79;
	}
	if (state == 89 && window.at(0) == Tokens::modules::ispa_dep_scanner::COLON::id) {
		return -79;
	}
	if (state == 89 && window.at(0) == Tokens::modules::ispa_dep_scanner::LBRACE::id) {
		return -79;
	}
	if (state == 89 && window.at(0) == Tokens::modules::ispa_dep_scanner::RBRACE::id) {
		return -79;
	}
	if (state == 89 && window.at(0) == Tokens::modules::ispa_dep_scanner::SEMI::id) {
		return -79;
	}
	if (state == 90 && window.at(0) == Tokens::COMMA::id) {
		return -81;
	}
	if (state == 90 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -81;
	}
	if (state == 90 && window.at(0) == Tokens::modules::common::PY_RAW::id) {
		return -81;
	}
	if (state == 90 && window.at(0) == Tokens::modules::ispa_dep_scanner::COLON::id) {
		return -81;
	}
	if (state == 90 && window.at(0) == Tokens::modules::ispa_dep_scanner::LBRACE::id) {
		return -81;
	}
	if (state == 90 && window.at(0) == Tokens::modules::ispa_dep_scanner::RBRACE::id) {
		return -81;
	}
	if (state == 90 && window.at(0) == Tokens::modules::ispa_dep_scanner::SEMI::id) {
		return -81;
	}
	if (state == 91 && window.at(0) == Tokens::COMMA::id) {
		return -82;
	}
	if (state == 91 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return 137;
	}
	if (state == 91 && window.at(0) == Tokens::modules::common::PY_RAW::id) {
		return -82;
	}
	if (state == 91 && window.at(0) == Tokens::modules::ispa_dep_scanner::COLON::id) {
		return -82;
	}
	if (state == 91 && window.at(0) == Tokens::modules::ispa_dep_scanner::LBRACE::id) {
		return -82;
	}
	if (state == 91 && window.at(0) == Tokens::modules::ispa_dep_scanner::RBRACE::id) {
		return -82;
	}
	if (state == 91 && window.at(0) == Tokens::modules::ispa_dep_scanner::SEMI::id) {
		return -82;
	}
	if (state == 92 && window.at(0) == Tokens::modules::ispa_dep_scanner::RBRACE::id) {
		return 142;
	}
	if (state == 93 && window.at(0) == Tokens::COMMA::id) {
		return 143;
	}
	if (state == 93 && window.at(0) == Tokens::modules::ispa_dep_scanner::RBRACE::id) {
		return -138;
	}
	if (state == 94 && window.at(0) == Tokens::modules::ispa_dep_scanner::RBRACE::id) {
		return -61;
	}
	if (state == 95 && window.at(0) == Tokens::modules::common::ID::id) {
		return 21;
	}
	if (state == 95 && window.at(0) == Tokens::modules::ispa_dep_scanner::AS::id) {
		return 23;
	}
	if (state == 95 && window.at(0) == Tokens::modules::ispa_dep_scanner::DETACH::id) {
		return 24;
	}
	if (state == 95 && window.at(0) == Tokens::modules::ispa_dep_scanner::FAIL::id) {
		return 25;
	}
	if (state == 95 && window.at(0) == Tokens::modules::ispa_dep_scanner::FEATURE::id) {
		return 35;
	}
	if (state == 95 && window.at(0) == Tokens::modules::ispa_dep_scanner::FROM::id) {
		return 27;
	}
	if (state == 95 && window.at(0) == Tokens::modules::ispa_dep_scanner::IMPORT::id) {
		return 28;
	}
	if (state == 95 && window.at(0) == Tokens::modules::ispa_dep_scanner::MODULE::id) {
		return 29;
	}
	if (state == 96 && window.at(0) == Tokens::modules::ispa_dep_scanner::RBRACE::id) {
		return 146;
	}
	if (state == 97 && window.at(0) == Tokens::AUTO::id) {
		return -127;
	}
	if (state == 97 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -127;
	}
	if (state == 97 && window.at(0) == Tokens::modules::ispa_dep_scanner::AS::id) {
		return -127;
	}
	if (state == 97 && window.at(0) == Tokens::modules::ispa_dep_scanner::DOT::id) {
		return 147;
	}
	if (state == 97 && window.at(0) == Tokens::modules::ispa_dep_scanner::SEMI::id) {
		return -127;
	}
	if (state == 98 && window.at(0) == Tokens::modules::ispa_dep_scanner::SEMI::id) {
		return -107;
	}
	if (state == 99 && window.at(0) == Tokens::modules::ispa_dep_scanner::SEMI::id) {
		return -117;
	}
	if (state == 100 && window.at(0) == Tokens::COMMA::id) {
		return 149;
	}
	if (state == 100 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -12;
	}
	if (state == 100 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -12;
	}
	if (state == 101 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -21;
	}
	if (state == 102 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return 151;
	}
	if (state == 103 && window.at(0) == Tokens::modules::common::ID::id) {
		return 21;
	}
	if (state == 103 && window.at(0) == Tokens::modules::ispa_dep_scanner::AS::id) {
		return 23;
	}
	if (state == 103 && window.at(0) == Tokens::modules::ispa_dep_scanner::DETACH::id) {
		return 24;
	}
	if (state == 103 && window.at(0) == Tokens::modules::ispa_dep_scanner::FAIL::id) {
		return 25;
	}
	if (state == 103 && window.at(0) == Tokens::modules::ispa_dep_scanner::FEATURE::id) {
		return 35;
	}
	if (state == 103 && window.at(0) == Tokens::modules::ispa_dep_scanner::FROM::id) {
		return 27;
	}
	if (state == 103 && window.at(0) == Tokens::modules::ispa_dep_scanner::IMPORT::id) {
		return 28;
	}
	if (state == 103 && window.at(0) == Tokens::modules::ispa_dep_scanner::MODULE::id) {
		return 29;
	}
	if (state == 104 && window.at(0) == Tokens::modules::ispa_dep_scanner::SEMI::id) {
		return 153;
	}
	if (state == 105 && window.at(0) == Tokens::AUTO::id) {
		return -29;
	}
	if (state == 105 && window.at(0) == Tokens::COMMA::id) {
		return -29;
	}
	if (state == 105 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -29;
	}
	if (state == 105 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -29;
	}
	if (state == 105 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -29;
	}
	if (state == 105 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -29;
	}
	if (state == 105 && window.at(0) == Tokens::modules::common::ID::id) {
		return -29;
	}
	if (state == 105 && window.at(0) == Tokens::modules::common::NUMBER::id) {
		return -29;
	}
	if (state == 105 && window.at(0) == Tokens::modules::common::PY_RAW::id) {
		return -29;
	}
	if (state == 105 && window.at(0) == Tokens::modules::ispa_dep_scanner::ALL::id) {
		return -29;
	}
	if (state == 105 && window.at(0) == Tokens::modules::ispa_dep_scanner::AS::id) {
		return -29;
	}
	if (state == 105 && window.at(0) == Tokens::modules::ispa_dep_scanner::CGROUP::id) {
		return -29;
	}
	if (state == 105 && window.at(0) == Tokens::modules::ispa_dep_scanner::COLON::id) {
		return -29;
	}
	if (state == 105 && window.at(0) == Tokens::modules::ispa_dep_scanner::COMMENT::id) {
		return -29;
	}
	if (state == 105 && window.at(0) == Tokens::modules::ispa_dep_scanner::DETACH::id) {
		return -29;
	}
	if (state == 105 && window.at(0) == Tokens::modules::ispa_dep_scanner::DOT::id) {
		return -29;
	}
	if (state == 105 && window.at(0) == Tokens::modules::ispa_dep_scanner::FAIL::id) {
		return -29;
	}
	if (state == 105 && window.at(0) == Tokens::modules::ispa_dep_scanner::FEATURE::id) {
		return -29;
	}
	if (state == 105 && window.at(0) == Tokens::modules::ispa_dep_scanner::FROM::id) {
		return -29;
	}
	if (state == 105 && window.at(0) == Tokens::modules::ispa_dep_scanner::HASH::id) {
		return -29;
	}
	if (state == 105 && window.at(0) == Tokens::modules::ispa_dep_scanner::IMPORT::id) {
		return -29;
	}
	if (state == 105 && window.at(0) == Tokens::modules::ispa_dep_scanner::LBRACE::id) {
		return -29;
	}
	if (state == 105 && window.at(0) == Tokens::modules::ispa_dep_scanner::MODULE::id) {
		return -29;
	}
	if (state == 105 && window.at(0) == Tokens::modules::ispa_dep_scanner::OTHER::id) {
		return -29;
	}
	if (state == 105 && window.at(0) == Tokens::modules::ispa_dep_scanner::RBRACE::id) {
		return -29;
	}
	if (state == 105 && window.at(0) == Tokens::modules::ispa_dep_scanner::SEMI::id) {
		return -29;
	}
	if (state == 105 && window.at(0) == Tokens::modules::ispa_dep_scanner::STRING::id) {
		return -29;
	}
	if (state == 106 && window.at(0) == Tokens::AUTO::id) {
		return -30;
	}
	if (state == 106 && window.at(0) == Tokens::COMMA::id) {
		return -30;
	}
	if (state == 106 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -30;
	}
	if (state == 106 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -30;
	}
	if (state == 106 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -30;
	}
	if (state == 106 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -30;
	}
	if (state == 106 && window.at(0) == Tokens::modules::common::ID::id) {
		return -30;
	}
	if (state == 106 && window.at(0) == Tokens::modules::common::NUMBER::id) {
		return -30;
	}
	if (state == 106 && window.at(0) == Tokens::modules::common::PY_RAW::id) {
		return -30;
	}
	if (state == 106 && window.at(0) == Tokens::modules::ispa_dep_scanner::ALL::id) {
		return -30;
	}
	if (state == 106 && window.at(0) == Tokens::modules::ispa_dep_scanner::AS::id) {
		return -30;
	}
	if (state == 106 && window.at(0) == Tokens::modules::ispa_dep_scanner::CGROUP::id) {
		return -30;
	}
	if (state == 106 && window.at(0) == Tokens::modules::ispa_dep_scanner::COLON::id) {
		return -30;
	}
	if (state == 106 && window.at(0) == Tokens::modules::ispa_dep_scanner::COMMENT::id) {
		return -30;
	}
	if (state == 106 && window.at(0) == Tokens::modules::ispa_dep_scanner::DETACH::id) {
		return -30;
	}
	if (state == 106 && window.at(0) == Tokens::modules::ispa_dep_scanner::DOT::id) {
		return -30;
	}
	if (state == 106 && window.at(0) == Tokens::modules::ispa_dep_scanner::FAIL::id) {
		return -30;
	}
	if (state == 106 && window.at(0) == Tokens::modules::ispa_dep_scanner::FEATURE::id) {
		return -30;
	}
	if (state == 106 && window.at(0) == Tokens::modules::ispa_dep_scanner::FROM::id) {
		return -30;
	}
	if (state == 106 && window.at(0) == Tokens::modules::ispa_dep_scanner::HASH::id) {
		return -30;
	}
	if (state == 106 && window.at(0) == Tokens::modules::ispa_dep_scanner::IMPORT::id) {
		return -30;
	}
	if (state == 106 && window.at(0) == Tokens::modules::ispa_dep_scanner::LBRACE::id) {
		return -30;
	}
	if (state == 106 && window.at(0) == Tokens::modules::ispa_dep_scanner::MODULE::id) {
		return -30;
	}
	if (state == 106 && window.at(0) == Tokens::modules::ispa_dep_scanner::OTHER::id) {
		return -30;
	}
	if (state == 106 && window.at(0) == Tokens::modules::ispa_dep_scanner::RBRACE::id) {
		return -30;
	}
	if (state == 106 && window.at(0) == Tokens::modules::ispa_dep_scanner::SEMI::id) {
		return -30;
	}
	if (state == 106 && window.at(0) == Tokens::modules::ispa_dep_scanner::STRING::id) {
		return -30;
	}
	if (state == 107 && window.at(0) == Tokens::AUTO::id) {
		return -33;
	}
	if (state == 107 && window.at(0) == Tokens::COMMA::id) {
		return -33;
	}
	if (state == 107 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -33;
	}
	if (state == 107 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -33;
	}
	if (state == 107 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -33;
	}
	if (state == 107 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -33;
	}
	if (state == 107 && window.at(0) == Tokens::modules::common::ID::id) {
		return -33;
	}
	if (state == 107 && window.at(0) == Tokens::modules::common::NUMBER::id) {
		return -33;
	}
	if (state == 107 && window.at(0) == Tokens::modules::common::PY_RAW::id) {
		return -33;
	}
	if (state == 107 && window.at(0) == Tokens::modules::ispa_dep_scanner::ALL::id) {
		return -33;
	}
	if (state == 107 && window.at(0) == Tokens::modules::ispa_dep_scanner::AS::id) {
		return -33;
	}
	if (state == 107 && window.at(0) == Tokens::modules::ispa_dep_scanner::CGROUP::id) {
		return -33;
	}
	if (state == 107 && window.at(0) == Tokens::modules::ispa_dep_scanner::COLON::id) {
		return -33;
	}
	if (state == 107 && window.at(0) == Tokens::modules::ispa_dep_scanner::COMMENT::id) {
		return -33;
	}
	if (state == 107 && window.at(0) == Tokens::modules::ispa_dep_scanner::DETACH::id) {
		return -33;
	}
	if (state == 107 && window.at(0) == Tokens::modules::ispa_dep_scanner::DOT::id) {
		return -33;
	}
	if (state == 107 && window.at(0) == Tokens::modules::ispa_dep_scanner::FAIL::id) {
		return -33;
	}
	if (state == 107 && window.at(0) == Tokens::modules::ispa_dep_scanner::FEATURE::id) {
		return -33;
	}
	if (state == 107 && window.at(0) == Tokens::modules::ispa_dep_scanner::FROM::id) {
		return -33;
	}
	if (state == 107 && window.at(0) == Tokens::modules::ispa_dep_scanner::HASH::id) {
		return -33;
	}
	if (state == 107 && window.at(0) == Tokens::modules::ispa_dep_scanner::IMPORT::id) {
		return -33;
	}
	if (state == 107 && window.at(0) == Tokens::modules::ispa_dep_scanner::LBRACE::id) {
		return -33;
	}
	if (state == 107 && window.at(0) == Tokens::modules::ispa_dep_scanner::MODULE::id) {
		return -33;
	}
	if (state == 107 && window.at(0) == Tokens::modules::ispa_dep_scanner::OTHER::id) {
		return -33;
	}
	if (state == 107 && window.at(0) == Tokens::modules::ispa_dep_scanner::RBRACE::id) {
		return -33;
	}
	if (state == 107 && window.at(0) == Tokens::modules::ispa_dep_scanner::SEMI::id) {
		return -33;
	}
	if (state == 107 && window.at(0) == Tokens::modules::ispa_dep_scanner::STRING::id) {
		return -33;
	}
	if (state == 108 && window.at(0) == Tokens::AUTO::id) {
		return 106;
	}
	if (state == 108 && window.at(0) == Tokens::COMMA::id) {
		return 107;
	}
	if (state == 108 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return 108;
	}
	if (state == 108 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return 109;
	}
	if (state == 108 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return 110;
	}
	if (state == 108 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -131;
	}
	if (state == 108 && window.at(0) == Tokens::modules::common::ID::id) {
		return 39;
	}
	if (state == 108 && window.at(0) == Tokens::modules::common::NUMBER::id) {
		return 111;
	}
	if (state == 108 && window.at(0) == Tokens::modules::common::PY_RAW::id) {
		return 112;
	}
	if (state == 108 && window.at(0) == Tokens::modules::ispa_dep_scanner::ALL::id) {
		return 113;
	}
	if (state == 108 && window.at(0) == Tokens::modules::ispa_dep_scanner::AS::id) {
		return 41;
	}
	if (state == 108 && window.at(0) == Tokens::modules::ispa_dep_scanner::CGROUP::id) {
		return 114;
	}
	if (state == 108 && window.at(0) == Tokens::modules::ispa_dep_scanner::COLON::id) {
		return 115;
	}
	if (state == 108 && window.at(0) == Tokens::modules::ispa_dep_scanner::COMMENT::id) {
		return 116;
	}
	if (state == 108 && window.at(0) == Tokens::modules::ispa_dep_scanner::DETACH::id) {
		return 42;
	}
	if (state == 108 && window.at(0) == Tokens::modules::ispa_dep_scanner::DOT::id) {
		return 117;
	}
	if (state == 108 && window.at(0) == Tokens::modules::ispa_dep_scanner::FAIL::id) {
		return 43;
	}
	if (state == 108 && window.at(0) == Tokens::modules::ispa_dep_scanner::FEATURE::id) {
		return 44;
	}
	if (state == 108 && window.at(0) == Tokens::modules::ispa_dep_scanner::FROM::id) {
		return 45;
	}
	if (state == 108 && window.at(0) == Tokens::modules::ispa_dep_scanner::HASH::id) {
		return 128;
	}
	if (state == 108 && window.at(0) == Tokens::modules::ispa_dep_scanner::IMPORT::id) {
		return 46;
	}
	if (state == 108 && window.at(0) == Tokens::modules::ispa_dep_scanner::LBRACE::id) {
		return 81;
	}
	if (state == 108 && window.at(0) == Tokens::modules::ispa_dep_scanner::MODULE::id) {
		return 48;
	}
	if (state == 108 && window.at(0) == Tokens::modules::ispa_dep_scanner::OTHER::id) {
		return 119;
	}
	if (state == 108 && window.at(0) == Tokens::modules::ispa_dep_scanner::SEMI::id) {
		return 129;
	}
	if (state == 108 && window.at(0) == Tokens::modules::ispa_dep_scanner::STRING::id) {
		return 120;
	}
	if (state == 109 && window.at(0) == Tokens::AUTO::id) {
		return -32;
	}
	if (state == 109 && window.at(0) == Tokens::COMMA::id) {
		return -32;
	}
	if (state == 109 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -32;
	}
	if (state == 109 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -32;
	}
	if (state == 109 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -32;
	}
	if (state == 109 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -32;
	}
	if (state == 109 && window.at(0) == Tokens::modules::common::ID::id) {
		return -32;
	}
	if (state == 109 && window.at(0) == Tokens::modules::common::NUMBER::id) {
		return -32;
	}
	if (state == 109 && window.at(0) == Tokens::modules::common::PY_RAW::id) {
		return -32;
	}
	if (state == 109 && window.at(0) == Tokens::modules::ispa_dep_scanner::ALL::id) {
		return -32;
	}
	if (state == 109 && window.at(0) == Tokens::modules::ispa_dep_scanner::AS::id) {
		return -32;
	}
	if (state == 109 && window.at(0) == Tokens::modules::ispa_dep_scanner::CGROUP::id) {
		return -32;
	}
	if (state == 109 && window.at(0) == Tokens::modules::ispa_dep_scanner::COLON::id) {
		return -32;
	}
	if (state == 109 && window.at(0) == Tokens::modules::ispa_dep_scanner::COMMENT::id) {
		return -32;
	}
	if (state == 109 && window.at(0) == Tokens::modules::ispa_dep_scanner::DETACH::id) {
		return -32;
	}
	if (state == 109 && window.at(0) == Tokens::modules::ispa_dep_scanner::DOT::id) {
		return -32;
	}
	if (state == 109 && window.at(0) == Tokens::modules::ispa_dep_scanner::FAIL::id) {
		return -32;
	}
	if (state == 109 && window.at(0) == Tokens::modules::ispa_dep_scanner::FEATURE::id) {
		return -32;
	}
	if (state == 109 && window.at(0) == Tokens::modules::ispa_dep_scanner::FROM::id) {
		return -32;
	}
	if (state == 109 && window.at(0) == Tokens::modules::ispa_dep_scanner::HASH::id) {
		return -32;
	}
	if (state == 109 && window.at(0) == Tokens::modules::ispa_dep_scanner::IMPORT::id) {
		return -32;
	}
	if (state == 109 && window.at(0) == Tokens::modules::ispa_dep_scanner::LBRACE::id) {
		return -32;
	}
	if (state == 109 && window.at(0) == Tokens::modules::ispa_dep_scanner::MODULE::id) {
		return -32;
	}
	if (state == 109 && window.at(0) == Tokens::modules::ispa_dep_scanner::OTHER::id) {
		return -32;
	}
	if (state == 109 && window.at(0) == Tokens::modules::ispa_dep_scanner::RBRACE::id) {
		return -32;
	}
	if (state == 109 && window.at(0) == Tokens::modules::ispa_dep_scanner::SEMI::id) {
		return -32;
	}
	if (state == 109 && window.at(0) == Tokens::modules::ispa_dep_scanner::STRING::id) {
		return -32;
	}
	if (state == 110 && window.at(0) == Tokens::AUTO::id) {
		return -23;
	}
	if (state == 110 && window.at(0) == Tokens::COMMA::id) {
		return -23;
	}
	if (state == 110 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -23;
	}
	if (state == 110 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -23;
	}
	if (state == 110 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -23;
	}
	if (state == 110 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -23;
	}
	if (state == 110 && window.at(0) == Tokens::modules::common::ID::id) {
		return -23;
	}
	if (state == 110 && window.at(0) == Tokens::modules::common::NUMBER::id) {
		return -23;
	}
	if (state == 110 && window.at(0) == Tokens::modules::common::PY_RAW::id) {
		return -23;
	}
	if (state == 110 && window.at(0) == Tokens::modules::ispa_dep_scanner::ALL::id) {
		return -23;
	}
	if (state == 110 && window.at(0) == Tokens::modules::ispa_dep_scanner::AS::id) {
		return -23;
	}
	if (state == 110 && window.at(0) == Tokens::modules::ispa_dep_scanner::CGROUP::id) {
		return -23;
	}
	if (state == 110 && window.at(0) == Tokens::modules::ispa_dep_scanner::COLON::id) {
		return -23;
	}
	if (state == 110 && window.at(0) == Tokens::modules::ispa_dep_scanner::COMMENT::id) {
		return -23;
	}
	if (state == 110 && window.at(0) == Tokens::modules::ispa_dep_scanner::DETACH::id) {
		return -23;
	}
	if (state == 110 && window.at(0) == Tokens::modules::ispa_dep_scanner::DOT::id) {
		return -23;
	}
	if (state == 110 && window.at(0) == Tokens::modules::ispa_dep_scanner::FAIL::id) {
		return -23;
	}
	if (state == 110 && window.at(0) == Tokens::modules::ispa_dep_scanner::FEATURE::id) {
		return -23;
	}
	if (state == 110 && window.at(0) == Tokens::modules::ispa_dep_scanner::FROM::id) {
		return -23;
	}
	if (state == 110 && window.at(0) == Tokens::modules::ispa_dep_scanner::HASH::id) {
		return -23;
	}
	if (state == 110 && window.at(0) == Tokens::modules::ispa_dep_scanner::IMPORT::id) {
		return -23;
	}
	if (state == 110 && window.at(0) == Tokens::modules::ispa_dep_scanner::LBRACE::id) {
		return -23;
	}
	if (state == 110 && window.at(0) == Tokens::modules::ispa_dep_scanner::MODULE::id) {
		return -23;
	}
	if (state == 110 && window.at(0) == Tokens::modules::ispa_dep_scanner::OTHER::id) {
		return -23;
	}
	if (state == 110 && window.at(0) == Tokens::modules::ispa_dep_scanner::RBRACE::id) {
		return -23;
	}
	if (state == 110 && window.at(0) == Tokens::modules::ispa_dep_scanner::SEMI::id) {
		return -23;
	}
	if (state == 110 && window.at(0) == Tokens::modules::ispa_dep_scanner::STRING::id) {
		return -23;
	}
	if (state == 111 && window.at(0) == Tokens::AUTO::id) {
		return -26;
	}
	if (state == 111 && window.at(0) == Tokens::COMMA::id) {
		return -26;
	}
	if (state == 111 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -26;
	}
	if (state == 111 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -26;
	}
	if (state == 111 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -26;
	}
	if (state == 111 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -26;
	}
	if (state == 111 && window.at(0) == Tokens::modules::common::ID::id) {
		return -26;
	}
	if (state == 111 && window.at(0) == Tokens::modules::common::NUMBER::id) {
		return -26;
	}
	if (state == 111 && window.at(0) == Tokens::modules::common::PY_RAW::id) {
		return -26;
	}
	if (state == 111 && window.at(0) == Tokens::modules::ispa_dep_scanner::ALL::id) {
		return -26;
	}
	if (state == 111 && window.at(0) == Tokens::modules::ispa_dep_scanner::AS::id) {
		return -26;
	}
	if (state == 111 && window.at(0) == Tokens::modules::ispa_dep_scanner::CGROUP::id) {
		return -26;
	}
	if (state == 111 && window.at(0) == Tokens::modules::ispa_dep_scanner::COLON::id) {
		return -26;
	}
	if (state == 111 && window.at(0) == Tokens::modules::ispa_dep_scanner::COMMENT::id) {
		return -26;
	}
	if (state == 111 && window.at(0) == Tokens::modules::ispa_dep_scanner::DETACH::id) {
		return -26;
	}
	if (state == 111 && window.at(0) == Tokens::modules::ispa_dep_scanner::DOT::id) {
		return -26;
	}
	if (state == 111 && window.at(0) == Tokens::modules::ispa_dep_scanner::FAIL::id) {
		return -26;
	}
	if (state == 111 && window.at(0) == Tokens::modules::ispa_dep_scanner::FEATURE::id) {
		return -26;
	}
	if (state == 111 && window.at(0) == Tokens::modules::ispa_dep_scanner::FROM::id) {
		return -26;
	}
	if (state == 111 && window.at(0) == Tokens::modules::ispa_dep_scanner::HASH::id) {
		return -26;
	}
	if (state == 111 && window.at(0) == Tokens::modules::ispa_dep_scanner::IMPORT::id) {
		return -26;
	}
	if (state == 111 && window.at(0) == Tokens::modules::ispa_dep_scanner::LBRACE::id) {
		return -26;
	}
	if (state == 111 && window.at(0) == Tokens::modules::ispa_dep_scanner::MODULE::id) {
		return -26;
	}
	if (state == 111 && window.at(0) == Tokens::modules::ispa_dep_scanner::OTHER::id) {
		return -26;
	}
	if (state == 111 && window.at(0) == Tokens::modules::ispa_dep_scanner::RBRACE::id) {
		return -26;
	}
	if (state == 111 && window.at(0) == Tokens::modules::ispa_dep_scanner::SEMI::id) {
		return -26;
	}
	if (state == 111 && window.at(0) == Tokens::modules::ispa_dep_scanner::STRING::id) {
		return -26;
	}
	if (state == 112 && window.at(0) == Tokens::AUTO::id) {
		return -35;
	}
	if (state == 112 && window.at(0) == Tokens::COMMA::id) {
		return -35;
	}
	if (state == 112 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -35;
	}
	if (state == 112 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -35;
	}
	if (state == 112 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -35;
	}
	if (state == 112 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -35;
	}
	if (state == 112 && window.at(0) == Tokens::modules::common::ID::id) {
		return -35;
	}
	if (state == 112 && window.at(0) == Tokens::modules::common::NUMBER::id) {
		return -35;
	}
	if (state == 112 && window.at(0) == Tokens::modules::common::PY_RAW::id) {
		return -35;
	}
	if (state == 112 && window.at(0) == Tokens::modules::ispa_dep_scanner::ALL::id) {
		return -35;
	}
	if (state == 112 && window.at(0) == Tokens::modules::ispa_dep_scanner::AS::id) {
		return -35;
	}
	if (state == 112 && window.at(0) == Tokens::modules::ispa_dep_scanner::CGROUP::id) {
		return -35;
	}
	if (state == 112 && window.at(0) == Tokens::modules::ispa_dep_scanner::COLON::id) {
		return -35;
	}
	if (state == 112 && window.at(0) == Tokens::modules::ispa_dep_scanner::COMMENT::id) {
		return -35;
	}
	if (state == 112 && window.at(0) == Tokens::modules::ispa_dep_scanner::DETACH::id) {
		return -35;
	}
	if (state == 112 && window.at(0) == Tokens::modules::ispa_dep_scanner::DOT::id) {
		return -35;
	}
	if (state == 112 && window.at(0) == Tokens::modules::ispa_dep_scanner::FAIL::id) {
		return -35;
	}
	if (state == 112 && window.at(0) == Tokens::modules::ispa_dep_scanner::FEATURE::id) {
		return -35;
	}
	if (state == 112 && window.at(0) == Tokens::modules::ispa_dep_scanner::FROM::id) {
		return -35;
	}
	if (state == 112 && window.at(0) == Tokens::modules::ispa_dep_scanner::HASH::id) {
		return -35;
	}
	if (state == 112 && window.at(0) == Tokens::modules::ispa_dep_scanner::IMPORT::id) {
		return -35;
	}
	if (state == 112 && window.at(0) == Tokens::modules::ispa_dep_scanner::LBRACE::id) {
		return -35;
	}
	if (state == 112 && window.at(0) == Tokens::modules::ispa_dep_scanner::MODULE::id) {
		return -35;
	}
	if (state == 112 && window.at(0) == Tokens::modules::ispa_dep_scanner::OTHER::id) {
		return -35;
	}
	if (state == 112 && window.at(0) == Tokens::modules::ispa_dep_scanner::RBRACE::id) {
		return -35;
	}
	if (state == 112 && window.at(0) == Tokens::modules::ispa_dep_scanner::SEMI::id) {
		return -35;
	}
	if (state == 112 && window.at(0) == Tokens::modules::ispa_dep_scanner::STRING::id) {
		return -35;
	}
	if (state == 113 && window.at(0) == Tokens::AUTO::id) {
		return -25;
	}
	if (state == 113 && window.at(0) == Tokens::COMMA::id) {
		return -25;
	}
	if (state == 113 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -25;
	}
	if (state == 113 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -25;
	}
	if (state == 113 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -25;
	}
	if (state == 113 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -25;
	}
	if (state == 113 && window.at(0) == Tokens::modules::common::ID::id) {
		return -25;
	}
	if (state == 113 && window.at(0) == Tokens::modules::common::NUMBER::id) {
		return -25;
	}
	if (state == 113 && window.at(0) == Tokens::modules::common::PY_RAW::id) {
		return -25;
	}
	if (state == 113 && window.at(0) == Tokens::modules::ispa_dep_scanner::ALL::id) {
		return -25;
	}
	if (state == 113 && window.at(0) == Tokens::modules::ispa_dep_scanner::AS::id) {
		return -25;
	}
	if (state == 113 && window.at(0) == Tokens::modules::ispa_dep_scanner::CGROUP::id) {
		return -25;
	}
	if (state == 113 && window.at(0) == Tokens::modules::ispa_dep_scanner::COLON::id) {
		return -25;
	}
	if (state == 113 && window.at(0) == Tokens::modules::ispa_dep_scanner::COMMENT::id) {
		return -25;
	}
	if (state == 113 && window.at(0) == Tokens::modules::ispa_dep_scanner::DETACH::id) {
		return -25;
	}
	if (state == 113 && window.at(0) == Tokens::modules::ispa_dep_scanner::DOT::id) {
		return -25;
	}
	if (state == 113 && window.at(0) == Tokens::modules::ispa_dep_scanner::FAIL::id) {
		return -25;
	}
	if (state == 113 && window.at(0) == Tokens::modules::ispa_dep_scanner::FEATURE::id) {
		return -25;
	}
	if (state == 113 && window.at(0) == Tokens::modules::ispa_dep_scanner::FROM::id) {
		return -25;
	}
	if (state == 113 && window.at(0) == Tokens::modules::ispa_dep_scanner::HASH::id) {
		return -25;
	}
	if (state == 113 && window.at(0) == Tokens::modules::ispa_dep_scanner::IMPORT::id) {
		return -25;
	}
	if (state == 113 && window.at(0) == Tokens::modules::ispa_dep_scanner::LBRACE::id) {
		return -25;
	}
	if (state == 113 && window.at(0) == Tokens::modules::ispa_dep_scanner::MODULE::id) {
		return -25;
	}
	if (state == 113 && window.at(0) == Tokens::modules::ispa_dep_scanner::OTHER::id) {
		return -25;
	}
	if (state == 113 && window.at(0) == Tokens::modules::ispa_dep_scanner::RBRACE::id) {
		return -25;
	}
	if (state == 113 && window.at(0) == Tokens::modules::ispa_dep_scanner::SEMI::id) {
		return -25;
	}
	if (state == 113 && window.at(0) == Tokens::modules::ispa_dep_scanner::STRING::id) {
		return -25;
	}
	if (state == 114 && window.at(0) == Tokens::AUTO::id) {
		return -34;
	}
	if (state == 114 && window.at(0) == Tokens::COMMA::id) {
		return -34;
	}
	if (state == 114 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -34;
	}
	if (state == 114 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -34;
	}
	if (state == 114 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -34;
	}
	if (state == 114 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -34;
	}
	if (state == 114 && window.at(0) == Tokens::modules::common::ID::id) {
		return -34;
	}
	if (state == 114 && window.at(0) == Tokens::modules::common::NUMBER::id) {
		return -34;
	}
	if (state == 114 && window.at(0) == Tokens::modules::common::PY_RAW::id) {
		return -34;
	}
	if (state == 114 && window.at(0) == Tokens::modules::ispa_dep_scanner::ALL::id) {
		return -34;
	}
	if (state == 114 && window.at(0) == Tokens::modules::ispa_dep_scanner::AS::id) {
		return -34;
	}
	if (state == 114 && window.at(0) == Tokens::modules::ispa_dep_scanner::CGROUP::id) {
		return -34;
	}
	if (state == 114 && window.at(0) == Tokens::modules::ispa_dep_scanner::COLON::id) {
		return -34;
	}
	if (state == 114 && window.at(0) == Tokens::modules::ispa_dep_scanner::COMMENT::id) {
		return -34;
	}
	if (state == 114 && window.at(0) == Tokens::modules::ispa_dep_scanner::DETACH::id) {
		return -34;
	}
	if (state == 114 && window.at(0) == Tokens::modules::ispa_dep_scanner::DOT::id) {
		return -34;
	}
	if (state == 114 && window.at(0) == Tokens::modules::ispa_dep_scanner::FAIL::id) {
		return -34;
	}
	if (state == 114 && window.at(0) == Tokens::modules::ispa_dep_scanner::FEATURE::id) {
		return -34;
	}
	if (state == 114 && window.at(0) == Tokens::modules::ispa_dep_scanner::FROM::id) {
		return -34;
	}
	if (state == 114 && window.at(0) == Tokens::modules::ispa_dep_scanner::HASH::id) {
		return -34;
	}
	if (state == 114 && window.at(0) == Tokens::modules::ispa_dep_scanner::IMPORT::id) {
		return -34;
	}
	if (state == 114 && window.at(0) == Tokens::modules::ispa_dep_scanner::LBRACE::id) {
		return -34;
	}
	if (state == 114 && window.at(0) == Tokens::modules::ispa_dep_scanner::MODULE::id) {
		return -34;
	}
	if (state == 114 && window.at(0) == Tokens::modules::ispa_dep_scanner::OTHER::id) {
		return -34;
	}
	if (state == 114 && window.at(0) == Tokens::modules::ispa_dep_scanner::RBRACE::id) {
		return -34;
	}
	if (state == 114 && window.at(0) == Tokens::modules::ispa_dep_scanner::SEMI::id) {
		return -34;
	}
	if (state == 114 && window.at(0) == Tokens::modules::ispa_dep_scanner::STRING::id) {
		return -34;
	}
	if (state == 115 && window.at(0) == Tokens::AUTO::id) {
		return -27;
	}
	if (state == 115 && window.at(0) == Tokens::COMMA::id) {
		return -27;
	}
	if (state == 115 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -27;
	}
	if (state == 115 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -27;
	}
	if (state == 115 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -27;
	}
	if (state == 115 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -27;
	}
	if (state == 115 && window.at(0) == Tokens::modules::common::ID::id) {
		return -27;
	}
	if (state == 115 && window.at(0) == Tokens::modules::common::NUMBER::id) {
		return -27;
	}
	if (state == 115 && window.at(0) == Tokens::modules::common::PY_RAW::id) {
		return -27;
	}
	if (state == 115 && window.at(0) == Tokens::modules::ispa_dep_scanner::ALL::id) {
		return -27;
	}
	if (state == 115 && window.at(0) == Tokens::modules::ispa_dep_scanner::AS::id) {
		return -27;
	}
	if (state == 115 && window.at(0) == Tokens::modules::ispa_dep_scanner::CGROUP::id) {
		return -27;
	}
	if (state == 115 && window.at(0) == Tokens::modules::ispa_dep_scanner::COLON::id) {
		return -27;
	}
	if (state == 115 && window.at(0) == Tokens::modules::ispa_dep_scanner::COMMENT::id) {
		return -27;
	}
	if (state == 115 && window.at(0) == Tokens::modules::ispa_dep_scanner::DETACH::id) {
		return -27;
	}
	if (state == 115 && window.at(0) == Tokens::modules::ispa_dep_scanner::DOT::id) {
		return -27;
	}
	if (state == 115 && window.at(0) == Tokens::modules::ispa_dep_scanner::FAIL::id) {
		return -27;
	}
	if (state == 115 && window.at(0) == Tokens::modules::ispa_dep_scanner::FEATURE::id) {
		return -27;
	}
	if (state == 115 && window.at(0) == Tokens::modules::ispa_dep_scanner::FROM::id) {
		return -27;
	}
	if (state == 115 && window.at(0) == Tokens::modules::ispa_dep_scanner::HASH::id) {
		return -27;
	}
	if (state == 115 && window.at(0) == Tokens::modules::ispa_dep_scanner::IMPORT::id) {
		return -27;
	}
	if (state == 115 && window.at(0) == Tokens::modules::ispa_dep_scanner::LBRACE::id) {
		return -27;
	}
	if (state == 115 && window.at(0) == Tokens::modules::ispa_dep_scanner::MODULE::id) {
		return -27;
	}
	if (state == 115 && window.at(0) == Tokens::modules::ispa_dep_scanner::OTHER::id) {
		return -27;
	}
	if (state == 115 && window.at(0) == Tokens::modules::ispa_dep_scanner::RBRACE::id) {
		return -27;
	}
	if (state == 115 && window.at(0) == Tokens::modules::ispa_dep_scanner::SEMI::id) {
		return -27;
	}
	if (state == 115 && window.at(0) == Tokens::modules::ispa_dep_scanner::STRING::id) {
		return -27;
	}
	if (state == 116 && window.at(0) == Tokens::AUTO::id) {
		return -31;
	}
	if (state == 116 && window.at(0) == Tokens::COMMA::id) {
		return -31;
	}
	if (state == 116 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -31;
	}
	if (state == 116 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -31;
	}
	if (state == 116 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -31;
	}
	if (state == 116 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -31;
	}
	if (state == 116 && window.at(0) == Tokens::modules::common::ID::id) {
		return -31;
	}
	if (state == 116 && window.at(0) == Tokens::modules::common::NUMBER::id) {
		return -31;
	}
	if (state == 116 && window.at(0) == Tokens::modules::common::PY_RAW::id) {
		return -31;
	}
	if (state == 116 && window.at(0) == Tokens::modules::ispa_dep_scanner::ALL::id) {
		return -31;
	}
	if (state == 116 && window.at(0) == Tokens::modules::ispa_dep_scanner::AS::id) {
		return -31;
	}
	if (state == 116 && window.at(0) == Tokens::modules::ispa_dep_scanner::CGROUP::id) {
		return -31;
	}
	if (state == 116 && window.at(0) == Tokens::modules::ispa_dep_scanner::COLON::id) {
		return -31;
	}
	if (state == 116 && window.at(0) == Tokens::modules::ispa_dep_scanner::COMMENT::id) {
		return -31;
	}
	if (state == 116 && window.at(0) == Tokens::modules::ispa_dep_scanner::DETACH::id) {
		return -31;
	}
	if (state == 116 && window.at(0) == Tokens::modules::ispa_dep_scanner::DOT::id) {
		return -31;
	}
	if (state == 116 && window.at(0) == Tokens::modules::ispa_dep_scanner::FAIL::id) {
		return -31;
	}
	if (state == 116 && window.at(0) == Tokens::modules::ispa_dep_scanner::FEATURE::id) {
		return -31;
	}
	if (state == 116 && window.at(0) == Tokens::modules::ispa_dep_scanner::FROM::id) {
		return -31;
	}
	if (state == 116 && window.at(0) == Tokens::modules::ispa_dep_scanner::HASH::id) {
		return -31;
	}
	if (state == 116 && window.at(0) == Tokens::modules::ispa_dep_scanner::IMPORT::id) {
		return -31;
	}
	if (state == 116 && window.at(0) == Tokens::modules::ispa_dep_scanner::LBRACE::id) {
		return -31;
	}
	if (state == 116 && window.at(0) == Tokens::modules::ispa_dep_scanner::MODULE::id) {
		return -31;
	}
	if (state == 116 && window.at(0) == Tokens::modules::ispa_dep_scanner::OTHER::id) {
		return -31;
	}
	if (state == 116 && window.at(0) == Tokens::modules::ispa_dep_scanner::RBRACE::id) {
		return -31;
	}
	if (state == 116 && window.at(0) == Tokens::modules::ispa_dep_scanner::SEMI::id) {
		return -31;
	}
	if (state == 116 && window.at(0) == Tokens::modules::ispa_dep_scanner::STRING::id) {
		return -31;
	}
	if (state == 117 && window.at(0) == Tokens::modules::common::ID::id) {
		return -54;
	}
	if (state == 117 && window.at(0) == Tokens::modules::ispa_dep_scanner::AS::id) {
		return -54;
	}
	if (state == 117 && window.at(0) == Tokens::modules::ispa_dep_scanner::DETACH::id) {
		return -54;
	}
	if (state == 117 && window.at(0) == Tokens::modules::ispa_dep_scanner::FAIL::id) {
		return -54;
	}
	if (state == 117 && window.at(0) == Tokens::modules::ispa_dep_scanner::FEATURE::id) {
		return -54;
	}
	if (state == 117 && window.at(0) == Tokens::modules::ispa_dep_scanner::FROM::id) {
		return -54;
	}
	if (state == 117 && window.at(0) == Tokens::modules::ispa_dep_scanner::HASH::id) {
		return 7;
	}
	if (state == 117 && window.at(0) == Tokens::modules::ispa_dep_scanner::IMPORT::id) {
		return -54;
	}
	if (state == 117 && window.at(0) == Tokens::modules::ispa_dep_scanner::MODULE::id) {
		return -54;
	}
	if (state == 118 && window.at(0) == Tokens::AUTO::id) {
		return -28;
	}
	if (state == 118 && window.at(0) == Tokens::COMMA::id) {
		return -28;
	}
	if (state == 118 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -28;
	}
	if (state == 118 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -28;
	}
	if (state == 118 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -28;
	}
	if (state == 118 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -28;
	}
	if (state == 118 && window.at(0) == Tokens::modules::common::ID::id) {
		return -28;
	}
	if (state == 118 && window.at(0) == Tokens::modules::common::NUMBER::id) {
		return -28;
	}
	if (state == 118 && window.at(0) == Tokens::modules::common::PY_RAW::id) {
		return -28;
	}
	if (state == 118 && window.at(0) == Tokens::modules::ispa_dep_scanner::ALL::id) {
		return -28;
	}
	if (state == 118 && window.at(0) == Tokens::modules::ispa_dep_scanner::AS::id) {
		return -28;
	}
	if (state == 118 && window.at(0) == Tokens::modules::ispa_dep_scanner::CGROUP::id) {
		return -28;
	}
	if (state == 118 && window.at(0) == Tokens::modules::ispa_dep_scanner::COLON::id) {
		return -28;
	}
	if (state == 118 && window.at(0) == Tokens::modules::ispa_dep_scanner::COMMENT::id) {
		return -28;
	}
	if (state == 118 && window.at(0) == Tokens::modules::ispa_dep_scanner::DETACH::id) {
		return -28;
	}
	if (state == 118 && window.at(0) == Tokens::modules::ispa_dep_scanner::DOT::id) {
		return -28;
	}
	if (state == 118 && window.at(0) == Tokens::modules::ispa_dep_scanner::FAIL::id) {
		return -28;
	}
	if (state == 118 && window.at(0) == Tokens::modules::ispa_dep_scanner::FEATURE::id) {
		return -28;
	}
	if (state == 118 && window.at(0) == Tokens::modules::ispa_dep_scanner::FROM::id) {
		return -28;
	}
	if (state == 118 && window.at(0) == Tokens::modules::ispa_dep_scanner::HASH::id) {
		return -28;
	}
	if (state == 118 && window.at(0) == Tokens::modules::ispa_dep_scanner::IMPORT::id) {
		return -28;
	}
	if (state == 118 && window.at(0) == Tokens::modules::ispa_dep_scanner::LBRACE::id) {
		return -28;
	}
	if (state == 118 && window.at(0) == Tokens::modules::ispa_dep_scanner::MODULE::id) {
		return -28;
	}
	if (state == 118 && window.at(0) == Tokens::modules::ispa_dep_scanner::OTHER::id) {
		return -28;
	}
	if (state == 118 && window.at(0) == Tokens::modules::ispa_dep_scanner::RBRACE::id) {
		return -28;
	}
	if (state == 118 && window.at(0) == Tokens::modules::ispa_dep_scanner::SEMI::id) {
		return -28;
	}
	if (state == 118 && window.at(0) == Tokens::modules::ispa_dep_scanner::STRING::id) {
		return -28;
	}
	if (state == 119 && window.at(0) == Tokens::AUTO::id) {
		return -24;
	}
	if (state == 119 && window.at(0) == Tokens::COMMA::id) {
		return -24;
	}
	if (state == 119 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -24;
	}
	if (state == 119 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -24;
	}
	if (state == 119 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -24;
	}
	if (state == 119 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -24;
	}
	if (state == 119 && window.at(0) == Tokens::modules::common::ID::id) {
		return -24;
	}
	if (state == 119 && window.at(0) == Tokens::modules::common::NUMBER::id) {
		return -24;
	}
	if (state == 119 && window.at(0) == Tokens::modules::common::PY_RAW::id) {
		return -24;
	}
	if (state == 119 && window.at(0) == Tokens::modules::ispa_dep_scanner::ALL::id) {
		return -24;
	}
	if (state == 119 && window.at(0) == Tokens::modules::ispa_dep_scanner::AS::id) {
		return -24;
	}
	if (state == 119 && window.at(0) == Tokens::modules::ispa_dep_scanner::CGROUP::id) {
		return -24;
	}
	if (state == 119 && window.at(0) == Tokens::modules::ispa_dep_scanner::COLON::id) {
		return -24;
	}
	if (state == 119 && window.at(0) == Tokens::modules::ispa_dep_scanner::COMMENT::id) {
		return -24;
	}
	if (state == 119 && window.at(0) == Tokens::modules::ispa_dep_scanner::DETACH::id) {
		return -24;
	}
	if (state == 119 && window.at(0) == Tokens::modules::ispa_dep_scanner::DOT::id) {
		return -24;
	}
	if (state == 119 && window.at(0) == Tokens::modules::ispa_dep_scanner::FAIL::id) {
		return -24;
	}
	if (state == 119 && window.at(0) == Tokens::modules::ispa_dep_scanner::FEATURE::id) {
		return -24;
	}
	if (state == 119 && window.at(0) == Tokens::modules::ispa_dep_scanner::FROM::id) {
		return -24;
	}
	if (state == 119 && window.at(0) == Tokens::modules::ispa_dep_scanner::HASH::id) {
		return -24;
	}
	if (state == 119 && window.at(0) == Tokens::modules::ispa_dep_scanner::IMPORT::id) {
		return -24;
	}
	if (state == 119 && window.at(0) == Tokens::modules::ispa_dep_scanner::LBRACE::id) {
		return -24;
	}
	if (state == 119 && window.at(0) == Tokens::modules::ispa_dep_scanner::MODULE::id) {
		return -24;
	}
	if (state == 119 && window.at(0) == Tokens::modules::ispa_dep_scanner::OTHER::id) {
		return -24;
	}
	if (state == 119 && window.at(0) == Tokens::modules::ispa_dep_scanner::RBRACE::id) {
		return -24;
	}
	if (state == 119 && window.at(0) == Tokens::modules::ispa_dep_scanner::SEMI::id) {
		return -24;
	}
	if (state == 119 && window.at(0) == Tokens::modules::ispa_dep_scanner::STRING::id) {
		return -24;
	}
	if (state == 120 && window.at(0) == Tokens::AUTO::id) {
		return -99;
	}
	if (state == 120 && window.at(0) == Tokens::COMMA::id) {
		return -99;
	}
	if (state == 120 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -99;
	}
	if (state == 120 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -99;
	}
	if (state == 120 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -99;
	}
	if (state == 120 && window.at(0) == Tokens::modules::common::ID::id) {
		return -99;
	}
	if (state == 120 && window.at(0) == Tokens::modules::common::NUMBER::id) {
		return -99;
	}
	if (state == 120 && window.at(0) == Tokens::modules::common::PY_RAW::id) {
		return -99;
	}
	if (state == 120 && window.at(0) == Tokens::modules::ispa_dep_scanner::ALL::id) {
		return -99;
	}
	if (state == 120 && window.at(0) == Tokens::modules::ispa_dep_scanner::AS::id) {
		return -99;
	}
	if (state == 120 && window.at(0) == Tokens::modules::ispa_dep_scanner::CGROUP::id) {
		return -99;
	}
	if (state == 120 && window.at(0) == Tokens::modules::ispa_dep_scanner::COLON::id) {
		return -99;
	}
	if (state == 120 && window.at(0) == Tokens::modules::ispa_dep_scanner::COMMENT::id) {
		return -99;
	}
	if (state == 120 && window.at(0) == Tokens::modules::ispa_dep_scanner::DETACH::id) {
		return -99;
	}
	if (state == 120 && window.at(0) == Tokens::modules::ispa_dep_scanner::DOT::id) {
		return -99;
	}
	if (state == 120 && window.at(0) == Tokens::modules::ispa_dep_scanner::FAIL::id) {
		return -99;
	}
	if (state == 120 && window.at(0) == Tokens::modules::ispa_dep_scanner::FEATURE::id) {
		return -99;
	}
	if (state == 120 && window.at(0) == Tokens::modules::ispa_dep_scanner::FROM::id) {
		return -99;
	}
	if (state == 120 && window.at(0) == Tokens::modules::ispa_dep_scanner::HASH::id) {
		return -99;
	}
	if (state == 120 && window.at(0) == Tokens::modules::ispa_dep_scanner::IMPORT::id) {
		return -99;
	}
	if (state == 120 && window.at(0) == Tokens::modules::ispa_dep_scanner::LBRACE::id) {
		return -99;
	}
	if (state == 120 && window.at(0) == Tokens::modules::ispa_dep_scanner::MODULE::id) {
		return -99;
	}
	if (state == 120 && window.at(0) == Tokens::modules::ispa_dep_scanner::OTHER::id) {
		return -99;
	}
	if (state == 120 && window.at(0) == Tokens::modules::ispa_dep_scanner::SEMI::id) {
		return -99;
	}
	if (state == 120 && window.at(0) == Tokens::modules::ispa_dep_scanner::STRING::id) {
		return -99;
	}
	if (state == 121 && window.at(0) == Tokens::modules::ispa_dep_scanner::SEMI::id) {
		return 157;
	}
	if (state == 122 && window.at(0) == Tokens::AUTO::id) {
		return -98;
	}
	if (state == 122 && window.at(0) == Tokens::COMMA::id) {
		return -98;
	}
	if (state == 122 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -98;
	}
	if (state == 122 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -98;
	}
	if (state == 122 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -98;
	}
	if (state == 122 && window.at(0) == Tokens::modules::common::ID::id) {
		return -98;
	}
	if (state == 122 && window.at(0) == Tokens::modules::common::NUMBER::id) {
		return -98;
	}
	if (state == 122 && window.at(0) == Tokens::modules::common::PY_RAW::id) {
		return -98;
	}
	if (state == 122 && window.at(0) == Tokens::modules::ispa_dep_scanner::ALL::id) {
		return -98;
	}
	if (state == 122 && window.at(0) == Tokens::modules::ispa_dep_scanner::AS::id) {
		return -98;
	}
	if (state == 122 && window.at(0) == Tokens::modules::ispa_dep_scanner::CGROUP::id) {
		return -98;
	}
	if (state == 122 && window.at(0) == Tokens::modules::ispa_dep_scanner::COLON::id) {
		return -98;
	}
	if (state == 122 && window.at(0) == Tokens::modules::ispa_dep_scanner::COMMENT::id) {
		return -98;
	}
	if (state == 122 && window.at(0) == Tokens::modules::ispa_dep_scanner::DETACH::id) {
		return -98;
	}
	if (state == 122 && window.at(0) == Tokens::modules::ispa_dep_scanner::DOT::id) {
		return -98;
	}
	if (state == 122 && window.at(0) == Tokens::modules::ispa_dep_scanner::FAIL::id) {
		return -98;
	}
	if (state == 122 && window.at(0) == Tokens::modules::ispa_dep_scanner::FEATURE::id) {
		return -98;
	}
	if (state == 122 && window.at(0) == Tokens::modules::ispa_dep_scanner::FROM::id) {
		return -98;
	}
	if (state == 122 && window.at(0) == Tokens::modules::ispa_dep_scanner::HASH::id) {
		return -98;
	}
	if (state == 122 && window.at(0) == Tokens::modules::ispa_dep_scanner::IMPORT::id) {
		return -98;
	}
	if (state == 122 && window.at(0) == Tokens::modules::ispa_dep_scanner::LBRACE::id) {
		return -98;
	}
	if (state == 122 && window.at(0) == Tokens::modules::ispa_dep_scanner::MODULE::id) {
		return -98;
	}
	if (state == 122 && window.at(0) == Tokens::modules::ispa_dep_scanner::OTHER::id) {
		return -98;
	}
	if (state == 122 && window.at(0) == Tokens::modules::ispa_dep_scanner::SEMI::id) {
		return -98;
	}
	if (state == 122 && window.at(0) == Tokens::modules::ispa_dep_scanner::STRING::id) {
		return -98;
	}
	if (state == 123 && window.at(0) == Tokens::AUTO::id) {
		return -22;
	}
	if (state == 123 && window.at(0) == Tokens::COMMA::id) {
		return -22;
	}
	if (state == 123 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -22;
	}
	if (state == 123 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -22;
	}
	if (state == 123 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -22;
	}
	if (state == 123 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -22;
	}
	if (state == 123 && window.at(0) == Tokens::modules::common::ID::id) {
		return -22;
	}
	if (state == 123 && window.at(0) == Tokens::modules::common::NUMBER::id) {
		return -22;
	}
	if (state == 123 && window.at(0) == Tokens::modules::common::PY_RAW::id) {
		return -22;
	}
	if (state == 123 && window.at(0) == Tokens::modules::ispa_dep_scanner::ALL::id) {
		return -22;
	}
	if (state == 123 && window.at(0) == Tokens::modules::ispa_dep_scanner::AS::id) {
		return -22;
	}
	if (state == 123 && window.at(0) == Tokens::modules::ispa_dep_scanner::CGROUP::id) {
		return -22;
	}
	if (state == 123 && window.at(0) == Tokens::modules::ispa_dep_scanner::COLON::id) {
		return -22;
	}
	if (state == 123 && window.at(0) == Tokens::modules::ispa_dep_scanner::COMMENT::id) {
		return -22;
	}
	if (state == 123 && window.at(0) == Tokens::modules::ispa_dep_scanner::DETACH::id) {
		return -22;
	}
	if (state == 123 && window.at(0) == Tokens::modules::ispa_dep_scanner::DOT::id) {
		return -22;
	}
	if (state == 123 && window.at(0) == Tokens::modules::ispa_dep_scanner::FAIL::id) {
		return -22;
	}
	if (state == 123 && window.at(0) == Tokens::modules::ispa_dep_scanner::FEATURE::id) {
		return -22;
	}
	if (state == 123 && window.at(0) == Tokens::modules::ispa_dep_scanner::FROM::id) {
		return -22;
	}
	if (state == 123 && window.at(0) == Tokens::modules::ispa_dep_scanner::HASH::id) {
		return -22;
	}
	if (state == 123 && window.at(0) == Tokens::modules::ispa_dep_scanner::IMPORT::id) {
		return -22;
	}
	if (state == 123 && window.at(0) == Tokens::modules::ispa_dep_scanner::LBRACE::id) {
		return -22;
	}
	if (state == 123 && window.at(0) == Tokens::modules::ispa_dep_scanner::MODULE::id) {
		return -22;
	}
	if (state == 123 && window.at(0) == Tokens::modules::ispa_dep_scanner::OTHER::id) {
		return -22;
	}
	if (state == 123 && window.at(0) == Tokens::modules::ispa_dep_scanner::RBRACE::id) {
		return -22;
	}
	if (state == 123 && window.at(0) == Tokens::modules::ispa_dep_scanner::SEMI::id) {
		return -22;
	}
	if (state == 123 && window.at(0) == Tokens::modules::ispa_dep_scanner::STRING::id) {
		return -22;
	}
	if (state == 124 && window.at(0) == Tokens::AUTO::id) {
		return 106;
	}
	if (state == 124 && window.at(0) == Tokens::COMMA::id) {
		return 107;
	}
	if (state == 124 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return 108;
	}
	if (state == 124 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return 109;
	}
	if (state == 124 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return 110;
	}
	if (state == 124 && window.at(0) == Tokens::modules::common::ID::id) {
		return 39;
	}
	if (state == 124 && window.at(0) == Tokens::modules::common::NUMBER::id) {
		return 111;
	}
	if (state == 124 && window.at(0) == Tokens::modules::common::PY_RAW::id) {
		return 112;
	}
	if (state == 124 && window.at(0) == Tokens::modules::ispa_dep_scanner::ALL::id) {
		return 113;
	}
	if (state == 124 && window.at(0) == Tokens::modules::ispa_dep_scanner::AS::id) {
		return 41;
	}
	if (state == 124 && window.at(0) == Tokens::modules::ispa_dep_scanner::CGROUP::id) {
		return 114;
	}
	if (state == 124 && window.at(0) == Tokens::modules::ispa_dep_scanner::COLON::id) {
		return 115;
	}
	if (state == 124 && window.at(0) == Tokens::modules::ispa_dep_scanner::COMMENT::id) {
		return 116;
	}
	if (state == 124 && window.at(0) == Tokens::modules::ispa_dep_scanner::DETACH::id) {
		return 42;
	}
	if (state == 124 && window.at(0) == Tokens::modules::ispa_dep_scanner::DOT::id) {
		return 117;
	}
	if (state == 124 && window.at(0) == Tokens::modules::ispa_dep_scanner::FAIL::id) {
		return 43;
	}
	if (state == 124 && window.at(0) == Tokens::modules::ispa_dep_scanner::FEATURE::id) {
		return 44;
	}
	if (state == 124 && window.at(0) == Tokens::modules::ispa_dep_scanner::FROM::id) {
		return 45;
	}
	if (state == 124 && window.at(0) == Tokens::modules::ispa_dep_scanner::HASH::id) {
		return 118;
	}
	if (state == 124 && window.at(0) == Tokens::modules::ispa_dep_scanner::IMPORT::id) {
		return 46;
	}
	if (state == 124 && window.at(0) == Tokens::modules::ispa_dep_scanner::LBRACE::id) {
		return 81;
	}
	if (state == 124 && window.at(0) == Tokens::modules::ispa_dep_scanner::MODULE::id) {
		return 48;
	}
	if (state == 124 && window.at(0) == Tokens::modules::ispa_dep_scanner::OTHER::id) {
		return 119;
	}
	if (state == 124 && window.at(0) == Tokens::modules::ispa_dep_scanner::SEMI::id) {
		return -46;
	}
	if (state == 124 && window.at(0) == Tokens::modules::ispa_dep_scanner::STRING::id) {
		return 120;
	}
	if (state == 125 && window.at(0) == Tokens::AUTO::id) {
		return -96;
	}
	if (state == 125 && window.at(0) == Tokens::COMMA::id) {
		return -96;
	}
	if (state == 125 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -96;
	}
	if (state == 125 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -96;
	}
	if (state == 125 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -96;
	}
	if (state == 125 && window.at(0) == Tokens::modules::common::ID::id) {
		return -96;
	}
	if (state == 125 && window.at(0) == Tokens::modules::common::NUMBER::id) {
		return -96;
	}
	if (state == 125 && window.at(0) == Tokens::modules::common::PY_RAW::id) {
		return -96;
	}
	if (state == 125 && window.at(0) == Tokens::modules::ispa_dep_scanner::ALL::id) {
		return -96;
	}
	if (state == 125 && window.at(0) == Tokens::modules::ispa_dep_scanner::AS::id) {
		return -96;
	}
	if (state == 125 && window.at(0) == Tokens::modules::ispa_dep_scanner::CGROUP::id) {
		return -96;
	}
	if (state == 125 && window.at(0) == Tokens::modules::ispa_dep_scanner::COLON::id) {
		return -96;
	}
	if (state == 125 && window.at(0) == Tokens::modules::ispa_dep_scanner::COMMENT::id) {
		return -96;
	}
	if (state == 125 && window.at(0) == Tokens::modules::ispa_dep_scanner::DETACH::id) {
		return -96;
	}
	if (state == 125 && window.at(0) == Tokens::modules::ispa_dep_scanner::DOT::id) {
		return -96;
	}
	if (state == 125 && window.at(0) == Tokens::modules::ispa_dep_scanner::FAIL::id) {
		return -96;
	}
	if (state == 125 && window.at(0) == Tokens::modules::ispa_dep_scanner::FEATURE::id) {
		return -96;
	}
	if (state == 125 && window.at(0) == Tokens::modules::ispa_dep_scanner::FROM::id) {
		return -96;
	}
	if (state == 125 && window.at(0) == Tokens::modules::ispa_dep_scanner::HASH::id) {
		return -96;
	}
	if (state == 125 && window.at(0) == Tokens::modules::ispa_dep_scanner::IMPORT::id) {
		return -96;
	}
	if (state == 125 && window.at(0) == Tokens::modules::ispa_dep_scanner::LBRACE::id) {
		return -96;
	}
	if (state == 125 && window.at(0) == Tokens::modules::ispa_dep_scanner::MODULE::id) {
		return -96;
	}
	if (state == 125 && window.at(0) == Tokens::modules::ispa_dep_scanner::OTHER::id) {
		return -96;
	}
	if (state == 125 && window.at(0) == Tokens::modules::ispa_dep_scanner::SEMI::id) {
		return -96;
	}
	if (state == 125 && window.at(0) == Tokens::modules::ispa_dep_scanner::STRING::id) {
		return -96;
	}
	if (state == 126 && window.at(0) == Tokens::AUTO::id) {
		return -97;
	}
	if (state == 126 && window.at(0) == Tokens::COMMA::id) {
		return -97;
	}
	if (state == 126 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -97;
	}
	if (state == 126 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -97;
	}
	if (state == 126 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -97;
	}
	if (state == 126 && window.at(0) == Tokens::modules::common::ID::id) {
		return -97;
	}
	if (state == 126 && window.at(0) == Tokens::modules::common::NUMBER::id) {
		return -97;
	}
	if (state == 126 && window.at(0) == Tokens::modules::common::PY_RAW::id) {
		return -97;
	}
	if (state == 126 && window.at(0) == Tokens::modules::ispa_dep_scanner::ALL::id) {
		return -97;
	}
	if (state == 126 && window.at(0) == Tokens::modules::ispa_dep_scanner::AS::id) {
		return -97;
	}
	if (state == 126 && window.at(0) == Tokens::modules::ispa_dep_scanner::CGROUP::id) {
		return -97;
	}
	if (state == 126 && window.at(0) == Tokens::modules::ispa_dep_scanner::COLON::id) {
		return -97;
	}
	if (state == 126 && window.at(0) == Tokens::modules::ispa_dep_scanner::COMMENT::id) {
		return -97;
	}
	if (state == 126 && window.at(0) == Tokens::modules::ispa_dep_scanner::DETACH::id) {
		return -97;
	}
	if (state == 126 && window.at(0) == Tokens::modules::ispa_dep_scanner::DOT::id) {
		return -97;
	}
	if (state == 126 && window.at(0) == Tokens::modules::ispa_dep_scanner::FAIL::id) {
		return -97;
	}
	if (state == 126 && window.at(0) == Tokens::modules::ispa_dep_scanner::FEATURE::id) {
		return -97;
	}
	if (state == 126 && window.at(0) == Tokens::modules::ispa_dep_scanner::FROM::id) {
		return -97;
	}
	if (state == 126 && window.at(0) == Tokens::modules::ispa_dep_scanner::HASH::id) {
		return -97;
	}
	if (state == 126 && window.at(0) == Tokens::modules::ispa_dep_scanner::IMPORT::id) {
		return -97;
	}
	if (state == 126 && window.at(0) == Tokens::modules::ispa_dep_scanner::LBRACE::id) {
		return -97;
	}
	if (state == 126 && window.at(0) == Tokens::modules::ispa_dep_scanner::MODULE::id) {
		return -97;
	}
	if (state == 126 && window.at(0) == Tokens::modules::ispa_dep_scanner::OTHER::id) {
		return -97;
	}
	if (state == 126 && window.at(0) == Tokens::modules::ispa_dep_scanner::SEMI::id) {
		return -97;
	}
	if (state == 126 && window.at(0) == Tokens::modules::ispa_dep_scanner::STRING::id) {
		return -97;
	}
	if (state == 127 && window.at(0) == Tokens::AUTO::id) {
		return -40;
	}
	if (state == 127 && window.at(0) == Tokens::COMMA::id) {
		return -40;
	}
	if (state == 127 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -40;
	}
	if (state == 127 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -40;
	}
	if (state == 127 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -40;
	}
	if (state == 127 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -40;
	}
	if (state == 127 && window.at(0) == Tokens::modules::common::ID::id) {
		return -40;
	}
	if (state == 127 && window.at(0) == Tokens::modules::common::NUMBER::id) {
		return -40;
	}
	if (state == 127 && window.at(0) == Tokens::modules::common::PY_RAW::id) {
		return -40;
	}
	if (state == 127 && window.at(0) == Tokens::modules::ispa_dep_scanner::ALL::id) {
		return -40;
	}
	if (state == 127 && window.at(0) == Tokens::modules::ispa_dep_scanner::AS::id) {
		return -40;
	}
	if (state == 127 && window.at(0) == Tokens::modules::ispa_dep_scanner::CGROUP::id) {
		return -40;
	}
	if (state == 127 && window.at(0) == Tokens::modules::ispa_dep_scanner::COLON::id) {
		return -40;
	}
	if (state == 127 && window.at(0) == Tokens::modules::ispa_dep_scanner::COMMENT::id) {
		return -40;
	}
	if (state == 127 && window.at(0) == Tokens::modules::ispa_dep_scanner::DETACH::id) {
		return -40;
	}
	if (state == 127 && window.at(0) == Tokens::modules::ispa_dep_scanner::DOT::id) {
		return -40;
	}
	if (state == 127 && window.at(0) == Tokens::modules::ispa_dep_scanner::FAIL::id) {
		return -40;
	}
	if (state == 127 && window.at(0) == Tokens::modules::ispa_dep_scanner::FEATURE::id) {
		return -40;
	}
	if (state == 127 && window.at(0) == Tokens::modules::ispa_dep_scanner::FROM::id) {
		return -40;
	}
	if (state == 127 && window.at(0) == Tokens::modules::ispa_dep_scanner::HASH::id) {
		return -40;
	}
	if (state == 127 && window.at(0) == Tokens::modules::ispa_dep_scanner::IMPORT::id) {
		return -40;
	}
	if (state == 127 && window.at(0) == Tokens::modules::ispa_dep_scanner::LBRACE::id) {
		return -40;
	}
	if (state == 127 && window.at(0) == Tokens::modules::ispa_dep_scanner::MODULE::id) {
		return -40;
	}
	if (state == 127 && window.at(0) == Tokens::modules::ispa_dep_scanner::OTHER::id) {
		return -40;
	}
	if (state == 127 && window.at(0) == Tokens::modules::ispa_dep_scanner::RBRACE::id) {
		return -40;
	}
	if (state == 127 && window.at(0) == Tokens::modules::ispa_dep_scanner::SEMI::id) {
		return -40;
	}
	if (state == 127 && window.at(0) == Tokens::modules::ispa_dep_scanner::STRING::id) {
		return -40;
	}
	if (state == 128 && window.at(0) == Tokens::AUTO::id) {
		return -39;
	}
	if (state == 128 && window.at(0) == Tokens::COMMA::id) {
		return -39;
	}
	if (state == 128 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -39;
	}
	if (state == 128 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -39;
	}
	if (state == 128 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -39;
	}
	if (state == 128 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -39;
	}
	if (state == 128 && window.at(0) == Tokens::modules::common::ID::id) {
		return -39;
	}
	if (state == 128 && window.at(0) == Tokens::modules::common::NUMBER::id) {
		return -39;
	}
	if (state == 128 && window.at(0) == Tokens::modules::common::PY_RAW::id) {
		return -39;
	}
	if (state == 128 && window.at(0) == Tokens::modules::ispa_dep_scanner::ALL::id) {
		return -39;
	}
	if (state == 128 && window.at(0) == Tokens::modules::ispa_dep_scanner::AS::id) {
		return -39;
	}
	if (state == 128 && window.at(0) == Tokens::modules::ispa_dep_scanner::CGROUP::id) {
		return -39;
	}
	if (state == 128 && window.at(0) == Tokens::modules::ispa_dep_scanner::COLON::id) {
		return -39;
	}
	if (state == 128 && window.at(0) == Tokens::modules::ispa_dep_scanner::COMMENT::id) {
		return -39;
	}
	if (state == 128 && window.at(0) == Tokens::modules::ispa_dep_scanner::DETACH::id) {
		return -39;
	}
	if (state == 128 && window.at(0) == Tokens::modules::ispa_dep_scanner::DOT::id) {
		return -39;
	}
	if (state == 128 && window.at(0) == Tokens::modules::ispa_dep_scanner::FAIL::id) {
		return -39;
	}
	if (state == 128 && window.at(0) == Tokens::modules::ispa_dep_scanner::FEATURE::id) {
		return -39;
	}
	if (state == 128 && window.at(0) == Tokens::modules::ispa_dep_scanner::FROM::id) {
		return -39;
	}
	if (state == 128 && window.at(0) == Tokens::modules::ispa_dep_scanner::HASH::id) {
		return -39;
	}
	if (state == 128 && window.at(0) == Tokens::modules::ispa_dep_scanner::IMPORT::id) {
		return -39;
	}
	if (state == 128 && window.at(0) == Tokens::modules::ispa_dep_scanner::LBRACE::id) {
		return -39;
	}
	if (state == 128 && window.at(0) == Tokens::modules::ispa_dep_scanner::MODULE::id) {
		return -39;
	}
	if (state == 128 && window.at(0) == Tokens::modules::ispa_dep_scanner::OTHER::id) {
		return -39;
	}
	if (state == 128 && window.at(0) == Tokens::modules::ispa_dep_scanner::RBRACE::id) {
		return -39;
	}
	if (state == 128 && window.at(0) == Tokens::modules::ispa_dep_scanner::SEMI::id) {
		return -39;
	}
	if (state == 128 && window.at(0) == Tokens::modules::ispa_dep_scanner::STRING::id) {
		return -39;
	}
	if (state == 129 && window.at(0) == Tokens::AUTO::id) {
		return -38;
	}
	if (state == 129 && window.at(0) == Tokens::COMMA::id) {
		return -38;
	}
	if (state == 129 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -38;
	}
	if (state == 129 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -38;
	}
	if (state == 129 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -38;
	}
	if (state == 129 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -38;
	}
	if (state == 129 && window.at(0) == Tokens::modules::common::ID::id) {
		return -38;
	}
	if (state == 129 && window.at(0) == Tokens::modules::common::NUMBER::id) {
		return -38;
	}
	if (state == 129 && window.at(0) == Tokens::modules::common::PY_RAW::id) {
		return -38;
	}
	if (state == 129 && window.at(0) == Tokens::modules::ispa_dep_scanner::ALL::id) {
		return -38;
	}
	if (state == 129 && window.at(0) == Tokens::modules::ispa_dep_scanner::AS::id) {
		return -38;
	}
	if (state == 129 && window.at(0) == Tokens::modules::ispa_dep_scanner::CGROUP::id) {
		return -38;
	}
	if (state == 129 && window.at(0) == Tokens::modules::ispa_dep_scanner::COLON::id) {
		return -38;
	}
	if (state == 129 && window.at(0) == Tokens::modules::ispa_dep_scanner::COMMENT::id) {
		return -38;
	}
	if (state == 129 && window.at(0) == Tokens::modules::ispa_dep_scanner::DETACH::id) {
		return -38;
	}
	if (state == 129 && window.at(0) == Tokens::modules::ispa_dep_scanner::DOT::id) {
		return -38;
	}
	if (state == 129 && window.at(0) == Tokens::modules::ispa_dep_scanner::FAIL::id) {
		return -38;
	}
	if (state == 129 && window.at(0) == Tokens::modules::ispa_dep_scanner::FEATURE::id) {
		return -38;
	}
	if (state == 129 && window.at(0) == Tokens::modules::ispa_dep_scanner::FROM::id) {
		return -38;
	}
	if (state == 129 && window.at(0) == Tokens::modules::ispa_dep_scanner::HASH::id) {
		return -38;
	}
	if (state == 129 && window.at(0) == Tokens::modules::ispa_dep_scanner::IMPORT::id) {
		return -38;
	}
	if (state == 129 && window.at(0) == Tokens::modules::ispa_dep_scanner::LBRACE::id) {
		return -38;
	}
	if (state == 129 && window.at(0) == Tokens::modules::ispa_dep_scanner::MODULE::id) {
		return -38;
	}
	if (state == 129 && window.at(0) == Tokens::modules::ispa_dep_scanner::OTHER::id) {
		return -38;
	}
	if (state == 129 && window.at(0) == Tokens::modules::ispa_dep_scanner::RBRACE::id) {
		return -38;
	}
	if (state == 129 && window.at(0) == Tokens::modules::ispa_dep_scanner::SEMI::id) {
		return -38;
	}
	if (state == 129 && window.at(0) == Tokens::modules::ispa_dep_scanner::STRING::id) {
		return -38;
	}
	if (state == 130 && window.at(0) == Tokens::AUTO::id) {
		return 106;
	}
	if (state == 130 && window.at(0) == Tokens::COMMA::id) {
		return 107;
	}
	if (state == 130 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return 108;
	}
	if (state == 130 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return 109;
	}
	if (state == 130 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return 110;
	}
	if (state == 130 && window.at(0) == Tokens::modules::common::ID::id) {
		return 39;
	}
	if (state == 130 && window.at(0) == Tokens::modules::common::NUMBER::id) {
		return 111;
	}
	if (state == 130 && window.at(0) == Tokens::modules::common::PY_RAW::id) {
		return 112;
	}
	if (state == 130 && window.at(0) == Tokens::modules::ispa_dep_scanner::ALL::id) {
		return 113;
	}
	if (state == 130 && window.at(0) == Tokens::modules::ispa_dep_scanner::AS::id) {
		return 41;
	}
	if (state == 130 && window.at(0) == Tokens::modules::ispa_dep_scanner::CGROUP::id) {
		return 114;
	}
	if (state == 130 && window.at(0) == Tokens::modules::ispa_dep_scanner::COLON::id) {
		return 115;
	}
	if (state == 130 && window.at(0) == Tokens::modules::ispa_dep_scanner::COMMENT::id) {
		return 116;
	}
	if (state == 130 && window.at(0) == Tokens::modules::ispa_dep_scanner::DETACH::id) {
		return 42;
	}
	if (state == 130 && window.at(0) == Tokens::modules::ispa_dep_scanner::DOT::id) {
		return 117;
	}
	if (state == 130 && window.at(0) == Tokens::modules::ispa_dep_scanner::FAIL::id) {
		return 43;
	}
	if (state == 130 && window.at(0) == Tokens::modules::ispa_dep_scanner::FEATURE::id) {
		return 44;
	}
	if (state == 130 && window.at(0) == Tokens::modules::ispa_dep_scanner::FROM::id) {
		return 45;
	}
	if (state == 130 && window.at(0) == Tokens::modules::ispa_dep_scanner::HASH::id) {
		return 128;
	}
	if (state == 130 && window.at(0) == Tokens::modules::ispa_dep_scanner::IMPORT::id) {
		return 46;
	}
	if (state == 130 && window.at(0) == Tokens::modules::ispa_dep_scanner::LBRACE::id) {
		return 81;
	}
	if (state == 130 && window.at(0) == Tokens::modules::ispa_dep_scanner::MODULE::id) {
		return 48;
	}
	if (state == 130 && window.at(0) == Tokens::modules::ispa_dep_scanner::OTHER::id) {
		return 119;
	}
	if (state == 130 && window.at(0) == Tokens::modules::ispa_dep_scanner::RBRACE::id) {
		return -51;
	}
	if (state == 130 && window.at(0) == Tokens::modules::ispa_dep_scanner::SEMI::id) {
		return 129;
	}
	if (state == 130 && window.at(0) == Tokens::modules::ispa_dep_scanner::STRING::id) {
		return 120;
	}
	if (state == 131 && window.at(0) == Tokens::AUTO::id) {
		return -37;
	}
	if (state == 131 && window.at(0) == Tokens::COMMA::id) {
		return -37;
	}
	if (state == 131 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -37;
	}
	if (state == 131 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -37;
	}
	if (state == 131 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -37;
	}
	if (state == 131 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -37;
	}
	if (state == 131 && window.at(0) == Tokens::modules::common::ID::id) {
		return -37;
	}
	if (state == 131 && window.at(0) == Tokens::modules::common::NUMBER::id) {
		return -37;
	}
	if (state == 131 && window.at(0) == Tokens::modules::common::PY_RAW::id) {
		return -37;
	}
	if (state == 131 && window.at(0) == Tokens::modules::ispa_dep_scanner::ALL::id) {
		return -37;
	}
	if (state == 131 && window.at(0) == Tokens::modules::ispa_dep_scanner::AS::id) {
		return -37;
	}
	if (state == 131 && window.at(0) == Tokens::modules::ispa_dep_scanner::CGROUP::id) {
		return -37;
	}
	if (state == 131 && window.at(0) == Tokens::modules::ispa_dep_scanner::COLON::id) {
		return -37;
	}
	if (state == 131 && window.at(0) == Tokens::modules::ispa_dep_scanner::COMMENT::id) {
		return -37;
	}
	if (state == 131 && window.at(0) == Tokens::modules::ispa_dep_scanner::DETACH::id) {
		return -37;
	}
	if (state == 131 && window.at(0) == Tokens::modules::ispa_dep_scanner::DOT::id) {
		return -37;
	}
	if (state == 131 && window.at(0) == Tokens::modules::ispa_dep_scanner::FAIL::id) {
		return -37;
	}
	if (state == 131 && window.at(0) == Tokens::modules::ispa_dep_scanner::FEATURE::id) {
		return -37;
	}
	if (state == 131 && window.at(0) == Tokens::modules::ispa_dep_scanner::FROM::id) {
		return -37;
	}
	if (state == 131 && window.at(0) == Tokens::modules::ispa_dep_scanner::HASH::id) {
		return -37;
	}
	if (state == 131 && window.at(0) == Tokens::modules::ispa_dep_scanner::IMPORT::id) {
		return -37;
	}
	if (state == 131 && window.at(0) == Tokens::modules::ispa_dep_scanner::LBRACE::id) {
		return -37;
	}
	if (state == 131 && window.at(0) == Tokens::modules::ispa_dep_scanner::MODULE::id) {
		return -37;
	}
	if (state == 131 && window.at(0) == Tokens::modules::ispa_dep_scanner::OTHER::id) {
		return -37;
	}
	if (state == 131 && window.at(0) == Tokens::modules::ispa_dep_scanner::RBRACE::id) {
		return -37;
	}
	if (state == 131 && window.at(0) == Tokens::modules::ispa_dep_scanner::SEMI::id) {
		return -37;
	}
	if (state == 131 && window.at(0) == Tokens::modules::ispa_dep_scanner::STRING::id) {
		return -37;
	}
	if (state == 132 && window.at(0) == Tokens::modules::ispa_dep_scanner::RBRACE::id) {
		return 162;
	}
	if (state == 133 && window.at(0) == Tokens::AUTO::id) {
		return -36;
	}
	if (state == 133 && window.at(0) == Tokens::COMMA::id) {
		return -36;
	}
	if (state == 133 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -36;
	}
	if (state == 133 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -36;
	}
	if (state == 133 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -36;
	}
	if (state == 133 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -36;
	}
	if (state == 133 && window.at(0) == Tokens::modules::common::ID::id) {
		return -36;
	}
	if (state == 133 && window.at(0) == Tokens::modules::common::NUMBER::id) {
		return -36;
	}
	if (state == 133 && window.at(0) == Tokens::modules::common::PY_RAW::id) {
		return -36;
	}
	if (state == 133 && window.at(0) == Tokens::modules::ispa_dep_scanner::ALL::id) {
		return -36;
	}
	if (state == 133 && window.at(0) == Tokens::modules::ispa_dep_scanner::AS::id) {
		return -36;
	}
	if (state == 133 && window.at(0) == Tokens::modules::ispa_dep_scanner::CGROUP::id) {
		return -36;
	}
	if (state == 133 && window.at(0) == Tokens::modules::ispa_dep_scanner::COLON::id) {
		return -36;
	}
	if (state == 133 && window.at(0) == Tokens::modules::ispa_dep_scanner::COMMENT::id) {
		return -36;
	}
	if (state == 133 && window.at(0) == Tokens::modules::ispa_dep_scanner::DETACH::id) {
		return -36;
	}
	if (state == 133 && window.at(0) == Tokens::modules::ispa_dep_scanner::DOT::id) {
		return -36;
	}
	if (state == 133 && window.at(0) == Tokens::modules::ispa_dep_scanner::FAIL::id) {
		return -36;
	}
	if (state == 133 && window.at(0) == Tokens::modules::ispa_dep_scanner::FEATURE::id) {
		return -36;
	}
	if (state == 133 && window.at(0) == Tokens::modules::ispa_dep_scanner::FROM::id) {
		return -36;
	}
	if (state == 133 && window.at(0) == Tokens::modules::ispa_dep_scanner::HASH::id) {
		return -36;
	}
	if (state == 133 && window.at(0) == Tokens::modules::ispa_dep_scanner::IMPORT::id) {
		return -36;
	}
	if (state == 133 && window.at(0) == Tokens::modules::ispa_dep_scanner::LBRACE::id) {
		return -36;
	}
	if (state == 133 && window.at(0) == Tokens::modules::ispa_dep_scanner::MODULE::id) {
		return -36;
	}
	if (state == 133 && window.at(0) == Tokens::modules::ispa_dep_scanner::OTHER::id) {
		return -36;
	}
	if (state == 133 && window.at(0) == Tokens::modules::ispa_dep_scanner::RBRACE::id) {
		return -36;
	}
	if (state == 133 && window.at(0) == Tokens::modules::ispa_dep_scanner::SEMI::id) {
		return -36;
	}
	if (state == 133 && window.at(0) == Tokens::modules::ispa_dep_scanner::STRING::id) {
		return -36;
	}
	if (state == 134 && window.at(0) == Tokens::modules::common::ID::id) {
		return 163;
	}
	if (state == 135 && window.at(0) == Tokens::COMMA::id) {
		return -4;
	}
	if (state == 135 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -4;
	}
	if (state == 135 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -4;
	}
	if (state == 135 && window.at(0) == Tokens::modules::common::PY_RAW::id) {
		return -4;
	}
	if (state == 135 && window.at(0) == Tokens::modules::ispa_dep_scanner::COLON::id) {
		return -4;
	}
	if (state == 135 && window.at(0) == Tokens::modules::ispa_dep_scanner::LBRACE::id) {
		return -4;
	}
	if (state == 135 && window.at(0) == Tokens::modules::ispa_dep_scanner::RBRACE::id) {
		return -4;
	}
	if (state == 135 && window.at(0) == Tokens::modules::ispa_dep_scanner::SEMI::id) {
		return -4;
	}
	if (state == 136 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return 164;
	}
	if (state == 137 && window.at(0) == Tokens::COMMA::id) {
		return -2;
	}
	if (state == 137 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -2;
	}
	if (state == 137 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -2;
	}
	if (state == 137 && window.at(0) == Tokens::modules::common::PY_RAW::id) {
		return -2;
	}
	if (state == 137 && window.at(0) == Tokens::modules::ispa_dep_scanner::COLON::id) {
		return -2;
	}
	if (state == 137 && window.at(0) == Tokens::modules::ispa_dep_scanner::LBRACE::id) {
		return -2;
	}
	if (state == 137 && window.at(0) == Tokens::modules::ispa_dep_scanner::RBRACE::id) {
		return -2;
	}
	if (state == 137 && window.at(0) == Tokens::modules::ispa_dep_scanner::SEMI::id) {
		return -2;
	}
	if (state == 138 && window.at(0) == Tokens::COMMA::id) {
		return -10;
	}
	if (state == 138 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -10;
	}
	if (state == 138 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -10;
	}
	if (state == 138 && window.at(0) == Tokens::modules::common::PY_RAW::id) {
		return -10;
	}
	if (state == 138 && window.at(0) == Tokens::modules::ispa_dep_scanner::COLON::id) {
		return -10;
	}
	if (state == 138 && window.at(0) == Tokens::modules::ispa_dep_scanner::LBRACE::id) {
		return -10;
	}
	if (state == 138 && window.at(0) == Tokens::modules::ispa_dep_scanner::RBRACE::id) {
		return -10;
	}
	if (state == 138 && window.at(0) == Tokens::modules::ispa_dep_scanner::SEMI::id) {
		return -10;
	}
	if (state == 139 && window.at(0) == Tokens::COMMA::id) {
		return -83;
	}
	if (state == 139 && window.at(0) == Tokens::modules::common::PY_RAW::id) {
		return -83;
	}
	if (state == 139 && window.at(0) == Tokens::modules::ispa_dep_scanner::COLON::id) {
		return -83;
	}
	if (state == 139 && window.at(0) == Tokens::modules::ispa_dep_scanner::LBRACE::id) {
		return -83;
	}
	if (state == 139 && window.at(0) == Tokens::modules::ispa_dep_scanner::RBRACE::id) {
		return -83;
	}
	if (state == 139 && window.at(0) == Tokens::modules::ispa_dep_scanner::SEMI::id) {
		return -83;
	}
	if (state == 140 && window.at(0) == Tokens::COMMA::id) {
		return -77;
	}
	if (state == 140 && window.at(0) == Tokens::modules::common::PY_RAW::id) {
		return -77;
	}
	if (state == 140 && window.at(0) == Tokens::modules::ispa_dep_scanner::COLON::id) {
		return -77;
	}
	if (state == 140 && window.at(0) == Tokens::modules::ispa_dep_scanner::LBRACE::id) {
		return -77;
	}
	if (state == 140 && window.at(0) == Tokens::modules::ispa_dep_scanner::RBRACE::id) {
		return -77;
	}
	if (state == 140 && window.at(0) == Tokens::modules::ispa_dep_scanner::SEMI::id) {
		return -77;
	}
	if (state == 141 && window.at(0) == Tokens::modules::ispa_dep_scanner::SEMI::id) {
		return 165;
	}
	if (state == 142 && window.at(0) == Tokens::modules::common::ID::id) {
		return 21;
	}
	if (state == 142 && window.at(0) == Tokens::modules::ispa_dep_scanner::AS::id) {
		return 23;
	}
	if (state == 142 && window.at(0) == Tokens::modules::ispa_dep_scanner::DETACH::id) {
		return 24;
	}
	if (state == 142 && window.at(0) == Tokens::modules::ispa_dep_scanner::FAIL::id) {
		return 25;
	}
	if (state == 142 && window.at(0) == Tokens::modules::ispa_dep_scanner::FEATURE::id) {
		return 35;
	}
	if (state == 142 && window.at(0) == Tokens::modules::ispa_dep_scanner::FROM::id) {
		return 27;
	}
	if (state == 142 && window.at(0) == Tokens::modules::ispa_dep_scanner::IMPORT::id) {
		return 28;
	}
	if (state == 142 && window.at(0) == Tokens::modules::ispa_dep_scanner::MODULE::id) {
		return 29;
	}
	if (state == 143 && window.at(0) == Tokens::modules::ispa_dep_scanner::RBRACE::id) {
		return -137;
	}
	if (state == 144 && window.at(0) == Tokens::COMMA::id) {
		return 167;
	}
	if (state == 144 && window.at(0) == Tokens::modules::ispa_dep_scanner::RBRACE::id) {
		return -113;
	}
	if (state == 145 && window.at(0) == Tokens::modules::ispa_dep_scanner::FROM::id) {
		return -110;
	}
	if (state == 146 && window.at(0) == Tokens::modules::common::ID::id) {
		return 39;
	}
	if (state == 146 && window.at(0) == Tokens::modules::ispa_dep_scanner::AS::id) {
		return 41;
	}
	if (state == 146 && window.at(0) == Tokens::modules::ispa_dep_scanner::DETACH::id) {
		return 42;
	}
	if (state == 146 && window.at(0) == Tokens::modules::ispa_dep_scanner::FAIL::id) {
		return 43;
	}
	if (state == 146 && window.at(0) == Tokens::modules::ispa_dep_scanner::FEATURE::id) {
		return 44;
	}
	if (state == 146 && window.at(0) == Tokens::modules::ispa_dep_scanner::FROM::id) {
		return 45;
	}
	if (state == 146 && window.at(0) == Tokens::modules::ispa_dep_scanner::IMPORT::id) {
		return 46;
	}
	if (state == 146 && window.at(0) == Tokens::modules::ispa_dep_scanner::MODULE::id) {
		return 48;
	}
	if (state == 147 && window.at(0) == Tokens::AUTO::id) {
		return -126;
	}
	if (state == 147 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -126;
	}
	if (state == 147 && window.at(0) == Tokens::modules::ispa_dep_scanner::AS::id) {
		return -126;
	}
	if (state == 147 && window.at(0) == Tokens::modules::ispa_dep_scanner::SEMI::id) {
		return -126;
	}
	if (state == 148 && window.at(0) == Tokens::modules::common::ID::id) {
		return 170;
	}
	if (state == 149 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -11;
	}
	if (state == 149 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -11;
	}
	if (state == 150 && window.at(0) == Tokens::AUTO::id) {
		return -19;
	}
	if (state == 150 && window.at(0) == Tokens::COMMA::id) {
		return -19;
	}
	if (state == 150 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -19;
	}
	if (state == 150 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -19;
	}
	if (state == 150 && window.at(0) == Tokens::modules::common::PY_RAW::id) {
		return -19;
	}
	if (state == 150 && window.at(0) == Tokens::modules::ispa_dep_scanner::COLON::id) {
		return -19;
	}
	if (state == 150 && window.at(0) == Tokens::modules::ispa_dep_scanner::LBRACE::id) {
		return -19;
	}
	if (state == 150 && window.at(0) == Tokens::modules::ispa_dep_scanner::RBRACE::id) {
		return -19;
	}
	if (state == 150 && window.at(0) == Tokens::modules::ispa_dep_scanner::SEMI::id) {
		return -19;
	}
	if (state == 151 && window.at(0) == Tokens::modules::ispa_dep_scanner::SEMI::id) {
		return -120;
	}
	if (state == 152 && window.at(0) == static_cast<std::size_t>(-1)) {
		return -118;
	}
	if (state == 152 && window.at(0) == Tokens::modules::common::ID::id) {
		return -118;
	}
	if (state == 152 && window.at(0) == Tokens::modules::ispa_dep_scanner::AS::id) {
		return -118;
	}
	if (state == 152 && window.at(0) == Tokens::modules::ispa_dep_scanner::COMMENT::id) {
		return -118;
	}
	if (state == 152 && window.at(0) == Tokens::modules::ispa_dep_scanner::DETACH::id) {
		return -118;
	}
	if (state == 152 && window.at(0) == Tokens::modules::ispa_dep_scanner::FAIL::id) {
		return -118;
	}
	if (state == 152 && window.at(0) == Tokens::modules::ispa_dep_scanner::FEATURE::id) {
		return -118;
	}
	if (state == 152 && window.at(0) == Tokens::modules::ispa_dep_scanner::FROM::id) {
		return -118;
	}
	if (state == 152 && window.at(0) == Tokens::modules::ispa_dep_scanner::HASH::id) {
		return -118;
	}
	if (state == 152 && window.at(0) == Tokens::modules::ispa_dep_scanner::IMPORT::id) {
		return -118;
	}
	if (state == 152 && window.at(0) == Tokens::modules::ispa_dep_scanner::MODULE::id) {
		return -118;
	}
	if (state == 153 && window.at(0) == Tokens::AUTO::id) {
		return 106;
	}
	if (state == 153 && window.at(0) == Tokens::COMMA::id) {
		return 107;
	}
	if (state == 153 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return 108;
	}
	if (state == 153 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return 109;
	}
	if (state == 153 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return 110;
	}
	if (state == 153 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -133;
	}
	if (state == 153 && window.at(0) == Tokens::modules::common::ID::id) {
		return 39;
	}
	if (state == 153 && window.at(0) == Tokens::modules::common::NUMBER::id) {
		return 111;
	}
	if (state == 153 && window.at(0) == Tokens::modules::common::PY_RAW::id) {
		return 112;
	}
	if (state == 153 && window.at(0) == Tokens::modules::ispa_dep_scanner::ALL::id) {
		return 113;
	}
	if (state == 153 && window.at(0) == Tokens::modules::ispa_dep_scanner::AS::id) {
		return 41;
	}
	if (state == 153 && window.at(0) == Tokens::modules::ispa_dep_scanner::CGROUP::id) {
		return 114;
	}
	if (state == 153 && window.at(0) == Tokens::modules::ispa_dep_scanner::COLON::id) {
		return 115;
	}
	if (state == 153 && window.at(0) == Tokens::modules::ispa_dep_scanner::COMMENT::id) {
		return 116;
	}
	if (state == 153 && window.at(0) == Tokens::modules::ispa_dep_scanner::DETACH::id) {
		return 42;
	}
	if (state == 153 && window.at(0) == Tokens::modules::ispa_dep_scanner::DOT::id) {
		return 117;
	}
	if (state == 153 && window.at(0) == Tokens::modules::ispa_dep_scanner::FAIL::id) {
		return 43;
	}
	if (state == 153 && window.at(0) == Tokens::modules::ispa_dep_scanner::FEATURE::id) {
		return 44;
	}
	if (state == 153 && window.at(0) == Tokens::modules::ispa_dep_scanner::FROM::id) {
		return 45;
	}
	if (state == 153 && window.at(0) == Tokens::modules::ispa_dep_scanner::HASH::id) {
		return 128;
	}
	if (state == 153 && window.at(0) == Tokens::modules::ispa_dep_scanner::IMPORT::id) {
		return 46;
	}
	if (state == 153 && window.at(0) == Tokens::modules::ispa_dep_scanner::LBRACE::id) {
		return 81;
	}
	if (state == 153 && window.at(0) == Tokens::modules::ispa_dep_scanner::MODULE::id) {
		return 48;
	}
	if (state == 153 && window.at(0) == Tokens::modules::ispa_dep_scanner::OTHER::id) {
		return 119;
	}
	if (state == 153 && window.at(0) == Tokens::modules::ispa_dep_scanner::SEMI::id) {
		return 129;
	}
	if (state == 153 && window.at(0) == Tokens::modules::ispa_dep_scanner::STRING::id) {
		return 120;
	}
	if (state == 154 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return 173;
	}
	if (state == 155 && window.at(0) == Tokens::AUTO::id) {
		return -129;
	}
	if (state == 155 && window.at(0) == Tokens::COMMA::id) {
		return -129;
	}
	if (state == 155 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -129;
	}
	if (state == 155 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -129;
	}
	if (state == 155 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -129;
	}
	if (state == 155 && window.at(0) == Tokens::modules::common::ID::id) {
		return -129;
	}
	if (state == 155 && window.at(0) == Tokens::modules::common::NUMBER::id) {
		return -129;
	}
	if (state == 155 && window.at(0) == Tokens::modules::common::PY_RAW::id) {
		return -129;
	}
	if (state == 155 && window.at(0) == Tokens::modules::ispa_dep_scanner::ALL::id) {
		return -129;
	}
	if (state == 155 && window.at(0) == Tokens::modules::ispa_dep_scanner::AS::id) {
		return -129;
	}
	if (state == 155 && window.at(0) == Tokens::modules::ispa_dep_scanner::CGROUP::id) {
		return -129;
	}
	if (state == 155 && window.at(0) == Tokens::modules::ispa_dep_scanner::COLON::id) {
		return -129;
	}
	if (state == 155 && window.at(0) == Tokens::modules::ispa_dep_scanner::COMMENT::id) {
		return -129;
	}
	if (state == 155 && window.at(0) == Tokens::modules::ispa_dep_scanner::DETACH::id) {
		return -129;
	}
	if (state == 155 && window.at(0) == Tokens::modules::ispa_dep_scanner::DOT::id) {
		return -129;
	}
	if (state == 155 && window.at(0) == Tokens::modules::ispa_dep_scanner::FAIL::id) {
		return -129;
	}
	if (state == 155 && window.at(0) == Tokens::modules::ispa_dep_scanner::FEATURE::id) {
		return -129;
	}
	if (state == 155 && window.at(0) == Tokens::modules::ispa_dep_scanner::FROM::id) {
		return -129;
	}
	if (state == 155 && window.at(0) == Tokens::modules::ispa_dep_scanner::HASH::id) {
		return -129;
	}
	if (state == 155 && window.at(0) == Tokens::modules::ispa_dep_scanner::IMPORT::id) {
		return -129;
	}
	if (state == 155 && window.at(0) == Tokens::modules::ispa_dep_scanner::LBRACE::id) {
		return -129;
	}
	if (state == 155 && window.at(0) == Tokens::modules::ispa_dep_scanner::MODULE::id) {
		return -129;
	}
	if (state == 155 && window.at(0) == Tokens::modules::ispa_dep_scanner::OTHER::id) {
		return -129;
	}
	if (state == 155 && window.at(0) == Tokens::modules::ispa_dep_scanner::SEMI::id) {
		return -129;
	}
	if (state == 155 && window.at(0) == Tokens::modules::ispa_dep_scanner::STRING::id) {
		return -129;
	}
	if (state == 156 && window.at(0) == static_cast<std::size_t>(-1)) {
		return -43;
	}
	if (state == 156 && window.at(0) == Tokens::AUTO::id) {
		return -43;
	}
	if (state == 156 && window.at(0) == Tokens::COMMA::id) {
		return -43;
	}
	if (state == 156 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -43;
	}
	if (state == 156 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -43;
	}
	if (state == 156 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -43;
	}
	if (state == 156 && window.at(0) == Tokens::modules::common::ID::id) {
		return -43;
	}
	if (state == 156 && window.at(0) == Tokens::modules::common::NUMBER::id) {
		return -43;
	}
	if (state == 156 && window.at(0) == Tokens::modules::common::PY_RAW::id) {
		return -43;
	}
	if (state == 156 && window.at(0) == Tokens::modules::ispa_dep_scanner::ALL::id) {
		return -43;
	}
	if (state == 156 && window.at(0) == Tokens::modules::ispa_dep_scanner::AS::id) {
		return -43;
	}
	if (state == 156 && window.at(0) == Tokens::modules::ispa_dep_scanner::CGROUP::id) {
		return -43;
	}
	if (state == 156 && window.at(0) == Tokens::modules::ispa_dep_scanner::COLON::id) {
		return -43;
	}
	if (state == 156 && window.at(0) == Tokens::modules::ispa_dep_scanner::COMMENT::id) {
		return -43;
	}
	if (state == 156 && window.at(0) == Tokens::modules::ispa_dep_scanner::DETACH::id) {
		return -43;
	}
	if (state == 156 && window.at(0) == Tokens::modules::ispa_dep_scanner::DOT::id) {
		return -43;
	}
	if (state == 156 && window.at(0) == Tokens::modules::ispa_dep_scanner::FAIL::id) {
		return -43;
	}
	if (state == 156 && window.at(0) == Tokens::modules::ispa_dep_scanner::FEATURE::id) {
		return -43;
	}
	if (state == 156 && window.at(0) == Tokens::modules::ispa_dep_scanner::FROM::id) {
		return -43;
	}
	if (state == 156 && window.at(0) == Tokens::modules::ispa_dep_scanner::HASH::id) {
		return -43;
	}
	if (state == 156 && window.at(0) == Tokens::modules::ispa_dep_scanner::IMPORT::id) {
		return -43;
	}
	if (state == 156 && window.at(0) == Tokens::modules::ispa_dep_scanner::LBRACE::id) {
		return -43;
	}
	if (state == 156 && window.at(0) == Tokens::modules::ispa_dep_scanner::MODULE::id) {
		return -43;
	}
	if (state == 156 && window.at(0) == Tokens::modules::ispa_dep_scanner::OTHER::id) {
		return -43;
	}
	if (state == 156 && window.at(0) == Tokens::modules::ispa_dep_scanner::SEMI::id) {
		return -43;
	}
	if (state == 156 && window.at(0) == Tokens::modules::ispa_dep_scanner::STRING::id) {
		return -43;
	}
	if (state == 157 && window.at(0) == Tokens::modules::ispa_dep_scanner::SEMI::id) {
		return -45;
	}
	if (state == 158 && window.at(0) == Tokens::AUTO::id) {
		return 106;
	}
	if (state == 158 && window.at(0) == Tokens::COMMA::id) {
		return 107;
	}
	if (state == 158 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return 108;
	}
	if (state == 158 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return 109;
	}
	if (state == 158 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return 110;
	}
	if (state == 158 && window.at(0) == Tokens::modules::common::ID::id) {
		return 39;
	}
	if (state == 158 && window.at(0) == Tokens::modules::common::NUMBER::id) {
		return 111;
	}
	if (state == 158 && window.at(0) == Tokens::modules::common::PY_RAW::id) {
		return 112;
	}
	if (state == 158 && window.at(0) == Tokens::modules::ispa_dep_scanner::ALL::id) {
		return 113;
	}
	if (state == 158 && window.at(0) == Tokens::modules::ispa_dep_scanner::AS::id) {
		return 41;
	}
	if (state == 158 && window.at(0) == Tokens::modules::ispa_dep_scanner::CGROUP::id) {
		return 114;
	}
	if (state == 158 && window.at(0) == Tokens::modules::ispa_dep_scanner::COLON::id) {
		return 115;
	}
	if (state == 158 && window.at(0) == Tokens::modules::ispa_dep_scanner::COMMENT::id) {
		return 116;
	}
	if (state == 158 && window.at(0) == Tokens::modules::ispa_dep_scanner::DETACH::id) {
		return 42;
	}
	if (state == 158 && window.at(0) == Tokens::modules::ispa_dep_scanner::DOT::id) {
		return 117;
	}
	if (state == 158 && window.at(0) == Tokens::modules::ispa_dep_scanner::FAIL::id) {
		return 43;
	}
	if (state == 158 && window.at(0) == Tokens::modules::ispa_dep_scanner::FEATURE::id) {
		return 44;
	}
	if (state == 158 && window.at(0) == Tokens::modules::ispa_dep_scanner::FROM::id) {
		return 45;
	}
	if (state == 158 && window.at(0) == Tokens::modules::ispa_dep_scanner::HASH::id) {
		return 118;
	}
	if (state == 158 && window.at(0) == Tokens::modules::ispa_dep_scanner::IMPORT::id) {
		return 46;
	}
	if (state == 158 && window.at(0) == Tokens::modules::ispa_dep_scanner::LBRACE::id) {
		return 81;
	}
	if (state == 158 && window.at(0) == Tokens::modules::ispa_dep_scanner::MODULE::id) {
		return 48;
	}
	if (state == 158 && window.at(0) == Tokens::modules::ispa_dep_scanner::OTHER::id) {
		return 119;
	}
	if (state == 158 && window.at(0) == Tokens::modules::ispa_dep_scanner::SEMI::id) {
		return -46;
	}
	if (state == 158 && window.at(0) == Tokens::modules::ispa_dep_scanner::STRING::id) {
		return 120;
	}
	if (state == 159 && window.at(0) == Tokens::AUTO::id) {
		return 106;
	}
	if (state == 159 && window.at(0) == Tokens::COMMA::id) {
		return 107;
	}
	if (state == 159 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return 108;
	}
	if (state == 159 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return 109;
	}
	if (state == 159 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return 110;
	}
	if (state == 159 && window.at(0) == Tokens::modules::common::ID::id) {
		return 39;
	}
	if (state == 159 && window.at(0) == Tokens::modules::common::NUMBER::id) {
		return 111;
	}
	if (state == 159 && window.at(0) == Tokens::modules::common::PY_RAW::id) {
		return 112;
	}
	if (state == 159 && window.at(0) == Tokens::modules::ispa_dep_scanner::ALL::id) {
		return 113;
	}
	if (state == 159 && window.at(0) == Tokens::modules::ispa_dep_scanner::AS::id) {
		return 41;
	}
	if (state == 159 && window.at(0) == Tokens::modules::ispa_dep_scanner::CGROUP::id) {
		return 114;
	}
	if (state == 159 && window.at(0) == Tokens::modules::ispa_dep_scanner::COLON::id) {
		return 115;
	}
	if (state == 159 && window.at(0) == Tokens::modules::ispa_dep_scanner::COMMENT::id) {
		return 116;
	}
	if (state == 159 && window.at(0) == Tokens::modules::ispa_dep_scanner::DETACH::id) {
		return 42;
	}
	if (state == 159 && window.at(0) == Tokens::modules::ispa_dep_scanner::DOT::id) {
		return 117;
	}
	if (state == 159 && window.at(0) == Tokens::modules::ispa_dep_scanner::FAIL::id) {
		return 43;
	}
	if (state == 159 && window.at(0) == Tokens::modules::ispa_dep_scanner::FEATURE::id) {
		return 44;
	}
	if (state == 159 && window.at(0) == Tokens::modules::ispa_dep_scanner::FROM::id) {
		return 45;
	}
	if (state == 159 && window.at(0) == Tokens::modules::ispa_dep_scanner::HASH::id) {
		return 128;
	}
	if (state == 159 && window.at(0) == Tokens::modules::ispa_dep_scanner::IMPORT::id) {
		return 46;
	}
	if (state == 159 && window.at(0) == Tokens::modules::ispa_dep_scanner::LBRACE::id) {
		return 81;
	}
	if (state == 159 && window.at(0) == Tokens::modules::ispa_dep_scanner::MODULE::id) {
		return 48;
	}
	if (state == 159 && window.at(0) == Tokens::modules::ispa_dep_scanner::OTHER::id) {
		return 119;
	}
	if (state == 159 && window.at(0) == Tokens::modules::ispa_dep_scanner::RBRACE::id) {
		return -51;
	}
	if (state == 159 && window.at(0) == Tokens::modules::ispa_dep_scanner::SEMI::id) {
		return 129;
	}
	if (state == 159 && window.at(0) == Tokens::modules::ispa_dep_scanner::STRING::id) {
		return 120;
	}
	if (state == 160 && window.at(0) == Tokens::modules::ispa_dep_scanner::RBRACE::id) {
		return -50;
	}
	if (state == 161 && window.at(0) == static_cast<std::size_t>(-1)) {
		return -48;
	}
	if (state == 161 && window.at(0) == Tokens::AUTO::id) {
		return -48;
	}
	if (state == 161 && window.at(0) == Tokens::COMMA::id) {
		return -48;
	}
	if (state == 161 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -48;
	}
	if (state == 161 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -48;
	}
	if (state == 161 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -48;
	}
	if (state == 161 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -48;
	}
	if (state == 161 && window.at(0) == Tokens::modules::common::ID::id) {
		return -48;
	}
	if (state == 161 && window.at(0) == Tokens::modules::common::NUMBER::id) {
		return -48;
	}
	if (state == 161 && window.at(0) == Tokens::modules::common::PY_RAW::id) {
		return -48;
	}
	if (state == 161 && window.at(0) == Tokens::modules::ispa_dep_scanner::ALL::id) {
		return -48;
	}
	if (state == 161 && window.at(0) == Tokens::modules::ispa_dep_scanner::AS::id) {
		return -48;
	}
	if (state == 161 && window.at(0) == Tokens::modules::ispa_dep_scanner::CGROUP::id) {
		return -48;
	}
	if (state == 161 && window.at(0) == Tokens::modules::ispa_dep_scanner::COLON::id) {
		return -48;
	}
	if (state == 161 && window.at(0) == Tokens::modules::ispa_dep_scanner::COMMENT::id) {
		return -48;
	}
	if (state == 161 && window.at(0) == Tokens::modules::ispa_dep_scanner::DETACH::id) {
		return -48;
	}
	if (state == 161 && window.at(0) == Tokens::modules::ispa_dep_scanner::DOT::id) {
		return -48;
	}
	if (state == 161 && window.at(0) == Tokens::modules::ispa_dep_scanner::FAIL::id) {
		return -48;
	}
	if (state == 161 && window.at(0) == Tokens::modules::ispa_dep_scanner::FEATURE::id) {
		return -48;
	}
	if (state == 161 && window.at(0) == Tokens::modules::ispa_dep_scanner::FROM::id) {
		return -48;
	}
	if (state == 161 && window.at(0) == Tokens::modules::ispa_dep_scanner::HASH::id) {
		return -48;
	}
	if (state == 161 && window.at(0) == Tokens::modules::ispa_dep_scanner::IMPORT::id) {
		return -48;
	}
	if (state == 161 && window.at(0) == Tokens::modules::ispa_dep_scanner::LBRACE::id) {
		return -48;
	}
	if (state == 161 && window.at(0) == Tokens::modules::ispa_dep_scanner::MODULE::id) {
		return -48;
	}
	if (state == 161 && window.at(0) == Tokens::modules::ispa_dep_scanner::OTHER::id) {
		return -48;
	}
	if (state == 161 && window.at(0) == Tokens::modules::ispa_dep_scanner::RBRACE::id) {
		return -48;
	}
	if (state == 161 && window.at(0) == Tokens::modules::ispa_dep_scanner::SEMI::id) {
		return -48;
	}
	if (state == 161 && window.at(0) == Tokens::modules::ispa_dep_scanner::STRING::id) {
		return -48;
	}
	if (state == 162 && window.at(0) == Tokens::AUTO::id) {
		return 135;
	}
	if (state == 162 && window.at(0) == Tokens::COMMA::id) {
		return -5;
	}
	if (state == 162 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -5;
	}
	if (state == 162 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -5;
	}
	if (state == 162 && window.at(0) == Tokens::modules::common::PY_RAW::id) {
		return -5;
	}
	if (state == 162 && window.at(0) == Tokens::modules::ispa_dep_scanner::COLON::id) {
		return -5;
	}
	if (state == 162 && window.at(0) == Tokens::modules::ispa_dep_scanner::LBRACE::id) {
		return -5;
	}
	if (state == 162 && window.at(0) == Tokens::modules::ispa_dep_scanner::RBRACE::id) {
		return -5;
	}
	if (state == 162 && window.at(0) == Tokens::modules::ispa_dep_scanner::SEMI::id) {
		return -5;
	}
	if (state == 163 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -17;
	}
	if (state == 163 && window.at(0) == Tokens::modules::common::ID::id) {
		return 101;
	}
	if (state == 164 && window.at(0) == static_cast<std::size_t>(-1)) {
		return -59;
	}
	if (state == 164 && window.at(0) == Tokens::modules::common::ID::id) {
		return -59;
	}
	if (state == 164 && window.at(0) == Tokens::modules::ispa_dep_scanner::AS::id) {
		return -59;
	}
	if (state == 164 && window.at(0) == Tokens::modules::ispa_dep_scanner::COMMENT::id) {
		return -59;
	}
	if (state == 164 && window.at(0) == Tokens::modules::ispa_dep_scanner::DETACH::id) {
		return -59;
	}
	if (state == 164 && window.at(0) == Tokens::modules::ispa_dep_scanner::FAIL::id) {
		return -59;
	}
	if (state == 164 && window.at(0) == Tokens::modules::ispa_dep_scanner::FEATURE::id) {
		return -59;
	}
	if (state == 164 && window.at(0) == Tokens::modules::ispa_dep_scanner::FROM::id) {
		return -59;
	}
	if (state == 164 && window.at(0) == Tokens::modules::ispa_dep_scanner::HASH::id) {
		return -59;
	}
	if (state == 164 && window.at(0) == Tokens::modules::ispa_dep_scanner::IMPORT::id) {
		return -59;
	}
	if (state == 164 && window.at(0) == Tokens::modules::ispa_dep_scanner::MODULE::id) {
		return -59;
	}
	if (state == 165 && window.at(0) == Tokens::COMMA::id) {
		return 179;
	}
	if (state == 165 && window.at(0) == Tokens::modules::ispa_dep_scanner::RBRACE::id) {
		return -140;
	}
	if (state == 166 && window.at(0) == Tokens::modules::common::ID::id) {
		return 21;
	}
	if (state == 166 && window.at(0) == Tokens::modules::ispa_dep_scanner::AS::id) {
		return 23;
	}
	if (state == 166 && window.at(0) == Tokens::modules::ispa_dep_scanner::DETACH::id) {
		return 24;
	}
	if (state == 166 && window.at(0) == Tokens::modules::ispa_dep_scanner::FAIL::id) {
		return 25;
	}
	if (state == 166 && window.at(0) == Tokens::modules::ispa_dep_scanner::FEATURE::id) {
		return 35;
	}
	if (state == 166 && window.at(0) == Tokens::modules::ispa_dep_scanner::FROM::id) {
		return 27;
	}
	if (state == 166 && window.at(0) == Tokens::modules::ispa_dep_scanner::IMPORT::id) {
		return 28;
	}
	if (state == 166 && window.at(0) == Tokens::modules::ispa_dep_scanner::MODULE::id) {
		return 29;
	}
	if (state == 167 && window.at(0) == Tokens::modules::ispa_dep_scanner::RBRACE::id) {
		return -112;
	}
	if (state == 168 && window.at(0) == Tokens::AUTO::id) {
		return -127;
	}
	if (state == 168 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -127;
	}
	if (state == 168 && window.at(0) == Tokens::modules::ispa_dep_scanner::AS::id) {
		return -127;
	}
	if (state == 168 && window.at(0) == Tokens::modules::ispa_dep_scanner::DOT::id) {
		return 147;
	}
	if (state == 168 && window.at(0) == Tokens::modules::ispa_dep_scanner::SEMI::id) {
		return -127;
	}
	if (state == 169 && window.at(0) == Tokens::COMMA::id) {
		return 183;
	}
	if (state == 169 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -14;
	}
	if (state == 169 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -14;
	}
	if (state == 170 && window.at(0) == Tokens::AUTO::id) {
		return 106;
	}
	if (state == 170 && window.at(0) == Tokens::COMMA::id) {
		return 107;
	}
	if (state == 170 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return 108;
	}
	if (state == 170 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return 109;
	}
	if (state == 170 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return 110;
	}
	if (state == 170 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -133;
	}
	if (state == 170 && window.at(0) == Tokens::modules::common::ID::id) {
		return 39;
	}
	if (state == 170 && window.at(0) == Tokens::modules::common::NUMBER::id) {
		return 111;
	}
	if (state == 170 && window.at(0) == Tokens::modules::common::PY_RAW::id) {
		return 112;
	}
	if (state == 170 && window.at(0) == Tokens::modules::ispa_dep_scanner::ALL::id) {
		return 113;
	}
	if (state == 170 && window.at(0) == Tokens::modules::ispa_dep_scanner::AS::id) {
		return 41;
	}
	if (state == 170 && window.at(0) == Tokens::modules::ispa_dep_scanner::CGROUP::id) {
		return 114;
	}
	if (state == 170 && window.at(0) == Tokens::modules::ispa_dep_scanner::COLON::id) {
		return 115;
	}
	if (state == 170 && window.at(0) == Tokens::modules::ispa_dep_scanner::COMMENT::id) {
		return 116;
	}
	if (state == 170 && window.at(0) == Tokens::modules::ispa_dep_scanner::DETACH::id) {
		return 42;
	}
	if (state == 170 && window.at(0) == Tokens::modules::ispa_dep_scanner::DOT::id) {
		return 117;
	}
	if (state == 170 && window.at(0) == Tokens::modules::ispa_dep_scanner::FAIL::id) {
		return 43;
	}
	if (state == 170 && window.at(0) == Tokens::modules::ispa_dep_scanner::FEATURE::id) {
		return 44;
	}
	if (state == 170 && window.at(0) == Tokens::modules::ispa_dep_scanner::FROM::id) {
		return 45;
	}
	if (state == 170 && window.at(0) == Tokens::modules::ispa_dep_scanner::HASH::id) {
		return 128;
	}
	if (state == 170 && window.at(0) == Tokens::modules::ispa_dep_scanner::IMPORT::id) {
		return 46;
	}
	if (state == 170 && window.at(0) == Tokens::modules::ispa_dep_scanner::LBRACE::id) {
		return 81;
	}
	if (state == 170 && window.at(0) == Tokens::modules::ispa_dep_scanner::MODULE::id) {
		return 48;
	}
	if (state == 170 && window.at(0) == Tokens::modules::ispa_dep_scanner::OTHER::id) {
		return 119;
	}
	if (state == 170 && window.at(0) == Tokens::modules::ispa_dep_scanner::SEMI::id) {
		return 129;
	}
	if (state == 170 && window.at(0) == Tokens::modules::ispa_dep_scanner::STRING::id) {
		return 120;
	}
	if (state == 171 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -132;
	}
	if (state == 172 && window.at(0) == Tokens::AUTO::id) {
		return -130;
	}
	if (state == 172 && window.at(0) == Tokens::COMMA::id) {
		return -130;
	}
	if (state == 172 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -130;
	}
	if (state == 172 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -130;
	}
	if (state == 172 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -130;
	}
	if (state == 172 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -130;
	}
	if (state == 172 && window.at(0) == Tokens::modules::common::ID::id) {
		return -130;
	}
	if (state == 172 && window.at(0) == Tokens::modules::common::NUMBER::id) {
		return -130;
	}
	if (state == 172 && window.at(0) == Tokens::modules::common::PY_RAW::id) {
		return -130;
	}
	if (state == 172 && window.at(0) == Tokens::modules::ispa_dep_scanner::ALL::id) {
		return -130;
	}
	if (state == 172 && window.at(0) == Tokens::modules::ispa_dep_scanner::AS::id) {
		return -130;
	}
	if (state == 172 && window.at(0) == Tokens::modules::ispa_dep_scanner::CGROUP::id) {
		return -130;
	}
	if (state == 172 && window.at(0) == Tokens::modules::ispa_dep_scanner::COLON::id) {
		return -130;
	}
	if (state == 172 && window.at(0) == Tokens::modules::ispa_dep_scanner::COMMENT::id) {
		return -130;
	}
	if (state == 172 && window.at(0) == Tokens::modules::ispa_dep_scanner::DETACH::id) {
		return -130;
	}
	if (state == 172 && window.at(0) == Tokens::modules::ispa_dep_scanner::DOT::id) {
		return -130;
	}
	if (state == 172 && window.at(0) == Tokens::modules::ispa_dep_scanner::FAIL::id) {
		return -130;
	}
	if (state == 172 && window.at(0) == Tokens::modules::ispa_dep_scanner::FEATURE::id) {
		return -130;
	}
	if (state == 172 && window.at(0) == Tokens::modules::ispa_dep_scanner::FROM::id) {
		return -130;
	}
	if (state == 172 && window.at(0) == Tokens::modules::ispa_dep_scanner::HASH::id) {
		return -130;
	}
	if (state == 172 && window.at(0) == Tokens::modules::ispa_dep_scanner::IMPORT::id) {
		return -130;
	}
	if (state == 172 && window.at(0) == Tokens::modules::ispa_dep_scanner::LBRACE::id) {
		return -130;
	}
	if (state == 172 && window.at(0) == Tokens::modules::ispa_dep_scanner::MODULE::id) {
		return -130;
	}
	if (state == 172 && window.at(0) == Tokens::modules::ispa_dep_scanner::OTHER::id) {
		return -130;
	}
	if (state == 172 && window.at(0) == Tokens::modules::ispa_dep_scanner::RBRACE::id) {
		return -130;
	}
	if (state == 172 && window.at(0) == Tokens::modules::ispa_dep_scanner::SEMI::id) {
		return -130;
	}
	if (state == 172 && window.at(0) == Tokens::modules::ispa_dep_scanner::STRING::id) {
		return -130;
	}
	if (state == 173 && window.at(0) == Tokens::modules::ispa_dep_scanner::SEMI::id) {
		return -47;
	}
	if (state == 174 && window.at(0) == Tokens::modules::ispa_dep_scanner::RBRACE::id) {
		return -52;
	}
	if (state == 175 && window.at(0) == Tokens::COMMA::id) {
		return -6;
	}
	if (state == 175 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -6;
	}
	if (state == 175 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -6;
	}
	if (state == 175 && window.at(0) == Tokens::modules::common::PY_RAW::id) {
		return -6;
	}
	if (state == 175 && window.at(0) == Tokens::modules::ispa_dep_scanner::COLON::id) {
		return -6;
	}
	if (state == 175 && window.at(0) == Tokens::modules::ispa_dep_scanner::LBRACE::id) {
		return -6;
	}
	if (state == 175 && window.at(0) == Tokens::modules::ispa_dep_scanner::RBRACE::id) {
		return -6;
	}
	if (state == 175 && window.at(0) == Tokens::modules::ispa_dep_scanner::SEMI::id) {
		return -6;
	}
	if (state == 176 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -18;
	}
	if (state == 177 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return 186;
	}
	if (state == 178 && window.at(0) == Tokens::modules::common::ID::id) {
		return 21;
	}
	if (state == 178 && window.at(0) == Tokens::modules::ispa_dep_scanner::AS::id) {
		return 23;
	}
	if (state == 178 && window.at(0) == Tokens::modules::ispa_dep_scanner::DETACH::id) {
		return 24;
	}
	if (state == 178 && window.at(0) == Tokens::modules::ispa_dep_scanner::FAIL::id) {
		return 25;
	}
	if (state == 178 && window.at(0) == Tokens::modules::ispa_dep_scanner::FEATURE::id) {
		return 35;
	}
	if (state == 178 && window.at(0) == Tokens::modules::ispa_dep_scanner::FROM::id) {
		return 27;
	}
	if (state == 178 && window.at(0) == Tokens::modules::ispa_dep_scanner::IMPORT::id) {
		return 28;
	}
	if (state == 178 && window.at(0) == Tokens::modules::ispa_dep_scanner::MODULE::id) {
		return 29;
	}
	if (state == 179 && window.at(0) == Tokens::modules::ispa_dep_scanner::RBRACE::id) {
		return -139;
	}
	if (state == 180 && window.at(0) == Tokens::COMMA::id) {
		return 167;
	}
	if (state == 180 && window.at(0) == Tokens::modules::ispa_dep_scanner::RBRACE::id) {
		return -113;
	}
	if (state == 181 && window.at(0) == Tokens::AUTO::id) {
		return -128;
	}
	if (state == 181 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -128;
	}
	if (state == 181 && window.at(0) == Tokens::modules::ispa_dep_scanner::AS::id) {
		return -128;
	}
	if (state == 181 && window.at(0) == Tokens::modules::ispa_dep_scanner::SEMI::id) {
		return -128;
	}
	if (state == 182 && window.at(0) == Tokens::modules::common::ID::id) {
		return 189;
	}
	if (state == 183 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -13;
	}
	if (state == 183 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -13;
	}
	if (state == 184 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -134;
	}
	if (state == 185 && window.at(0) == Tokens::COMMA::id) {
		return -16;
	}
	if (state == 185 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -16;
	}
	if (state == 185 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -16;
	}
	if (state == 185 && window.at(0) == Tokens::modules::common::PY_RAW::id) {
		return -16;
	}
	if (state == 185 && window.at(0) == Tokens::modules::ispa_dep_scanner::COLON::id) {
		return -16;
	}
	if (state == 185 && window.at(0) == Tokens::modules::ispa_dep_scanner::LBRACE::id) {
		return -16;
	}
	if (state == 185 && window.at(0) == Tokens::modules::ispa_dep_scanner::RBRACE::id) {
		return -16;
	}
	if (state == 185 && window.at(0) == Tokens::modules::ispa_dep_scanner::SEMI::id) {
		return -16;
	}
	if (state == 186 && window.at(0) == Tokens::COMMA::id) {
		return 179;
	}
	if (state == 186 && window.at(0) == Tokens::modules::ispa_dep_scanner::RBRACE::id) {
		return -140;
	}
	if (state == 187 && window.at(0) == Tokens::modules::ispa_dep_scanner::RBRACE::id) {
		return -114;
	}
	if (state == 188 && window.at(0) == Tokens::COMMA::id) {
		return 183;
	}
	if (state == 188 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -14;
	}
	if (state == 188 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -14;
	}
	if (state == 189 && window.at(0) == Tokens::modules::ispa_dep_scanner::RBRACE::id) {
		return -141;
	}
	if (state == 190 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -15;
	}
	if (state == 190 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -15;
	}
	if (state == 0 && window.at(0) == Tokens::modules::ispa_dep_scanner::DETACH::id) {
		return 9223372036854775807;
	}
	if (state == 0 && window.at(0) == Tokens::modules::ispa_dep_scanner::FAIL::id) {
		return 9223372036854775807;
	}
	if (state == 0 && window.at(0) == Tokens::modules::ispa_dep_scanner::FEATURE::id) {
		return 9223372036854775807;
	}
	if (state == 0 && window.at(0) == Tokens::modules::ispa_dep_scanner::IMPORT::id) {
		return 9223372036854775807;
	}
	if (state == 0 && window.at(0) == Tokens::modules::ispa_dep_scanner::MODULE::id) {
		return 9223372036854775807;
	}
	if (state == 15 && window.at(0) == Tokens::modules::ispa_dep_scanner::DETACH::id) {
		return 9223372036854775807;
	}
	if (state == 15 && window.at(0) == Tokens::modules::ispa_dep_scanner::FAIL::id) {
		return 9223372036854775807;
	}
	if (state == 15 && window.at(0) == Tokens::modules::ispa_dep_scanner::FEATURE::id) {
		return 9223372036854775807;
	}
	if (state == 15 && window.at(0) == Tokens::modules::ispa_dep_scanner::IMPORT::id) {
		return 9223372036854775807;
	}
	if (state == 15 && window.at(0) == Tokens::modules::ispa_dep_scanner::MODULE::id) {
		return 9223372036854775807;
	}
	if (state == 57 && window.at(0) == Tokens::modules::ispa_dep_scanner::DETACH::id) {
		return 9223372036854775807;
	}
	if (state == 57 && window.at(0) == Tokens::modules::ispa_dep_scanner::FAIL::id) {
		return 9223372036854775807;
	}
	if (state == 57 && window.at(0) == Tokens::modules::ispa_dep_scanner::FEATURE::id) {
		return 9223372036854775807;
	}
	if (state == 57 && window.at(0) == Tokens::modules::ispa_dep_scanner::IMPORT::id) {
		return 9223372036854775807;
	}
	if (state == 57 && window.at(0) == Tokens::modules::ispa_dep_scanner::MODULE::id) {
		return 9223372036854775807;
	}
	if (state == 62 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return 9223372036854775807;
	}
	if (state == 87 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return 9223372036854775807;
	}
	return -9223372036854775807;
}
auto DepParser::Parser::lr_conflict(std::size_t state, const std::vector<std::size_t>& window) -> std::vector<long long> {
	if (state == 0 && window.at(0) == Tokens::modules::ispa_dep_scanner::DETACH::id) {
		return {-54, 4};
	}
	if (state == 0 && window.at(0) == Tokens::modules::ispa_dep_scanner::FAIL::id) {
		return {-54, 5};
	}
	if (state == 0 && window.at(0) == Tokens::modules::ispa_dep_scanner::FEATURE::id) {
		return {-54, 6};
	}
	if (state == 0 && window.at(0) == Tokens::modules::ispa_dep_scanner::IMPORT::id) {
		return {-54, 8};
	}
	if (state == 0 && window.at(0) == Tokens::modules::ispa_dep_scanner::MODULE::id) {
		return {-54, 9};
	}
	if (state == 15 && window.at(0) == Tokens::modules::ispa_dep_scanner::DETACH::id) {
		return {-54, 4};
	}
	if (state == 15 && window.at(0) == Tokens::modules::ispa_dep_scanner::FAIL::id) {
		return {-54, 5};
	}
	if (state == 15 && window.at(0) == Tokens::modules::ispa_dep_scanner::FEATURE::id) {
		return {-54, 6};
	}
	if (state == 15 && window.at(0) == Tokens::modules::ispa_dep_scanner::IMPORT::id) {
		return {-54, 8};
	}
	if (state == 15 && window.at(0) == Tokens::modules::ispa_dep_scanner::MODULE::id) {
		return {-54, 9};
	}
	if (state == 57 && window.at(0) == Tokens::modules::ispa_dep_scanner::DETACH::id) {
		return {-54, 4};
	}
	if (state == 57 && window.at(0) == Tokens::modules::ispa_dep_scanner::FAIL::id) {
		return {-54, 5};
	}
	if (state == 57 && window.at(0) == Tokens::modules::ispa_dep_scanner::FEATURE::id) {
		return {-54, 6};
	}
	if (state == 57 && window.at(0) == Tokens::modules::ispa_dep_scanner::IMPORT::id) {
		return {-54, 8};
	}
	if (state == 57 && window.at(0) == Tokens::modules::ispa_dep_scanner::MODULE::id) {
		return {-54, 9};
	}
	if (state == 62 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return {-7, 77};
	}
	if (state == 87 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return {-9, 137};
	}
	return {};
}
auto DepParser::Parser::lr_rule_label(std::size_t rule) -> std::string {
	if (rule == 0) {
		return "main (production 0)";
	}
	if (rule == 1) {
		return "modules::common::name (production 1) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa/grammar/common.isc";
	}
	if (rule == 2) {
		return "modules::common::name (production 2) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa/grammar/common.isc";
	}
	if (rule == 3) {
		return "modules::common::name (production 3) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa/grammar/common.isc";
	}
	if (rule == 4) {
		return "modules::common::name (production 4) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa/grammar/common.isc";
	}
	if (rule == 5) {
		return "modules::common::name (production 5) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa/grammar/common.isc";
	}
	if (rule == 6) {
		return "modules::common::name (production 6) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa/grammar/common.isc";
	}
	if (rule == 7) {
		return "modules::common::name (production 7) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa/grammar/common.isc";
	}
	if (rule == 8) {
		return "modules::common::name (production 8) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa/grammar/common.isc";
	}
	if (rule == 9) {
		return "modules::common::name (production 9) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa/grammar/common.isc";
	}
	if (rule == 10) {
		return "modules::common::param (production 10) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa/grammar/common.isc";
	}
	if (rule == 11) {
		return "modules::common::param (production 11) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa/grammar/common.isc";
	}
	if (rule == 12) {
		return "modules::common::param (production 12) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa/grammar/common.isc";
	}
	if (rule == 13) {
		return "modules::common::param (production 13) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa/grammar/common.isc";
	}
	if (rule == 14) {
		return "modules::common::param (production 14) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa/grammar/common.isc";
	}
	if (rule == 15) {
		return "modules::common::params (production 15) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa/grammar/common.isc";
	}
	if (rule == 16) {
		return "modules::common::params (production 16) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa/grammar/common.isc";
	}
	if (rule == 17) {
		return "modules::common::params (production 17) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa/grammar/common.isc";
	}
	if (rule == 18) {
		return "modules::common::template_params (production 18) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa/grammar/common.isc";
	}
	if (rule == 19) {
		return "modules::common::template_params (production 19) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa/grammar/common.isc";
	}
	if (rule == 20) {
		return "modules::common::template_params (production 20) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa/grammar/common.isc";
	}
	if (rule == 21) {
		return "modules::ispa_dep_scanner::atom (production 21) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 22) {
		return "modules::ispa_dep_scanner::atom (production 22) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 23) {
		return "modules::ispa_dep_scanner::atom (production 23) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 24) {
		return "modules::ispa_dep_scanner::atom (production 24) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 25) {
		return "modules::ispa_dep_scanner::atom (production 25) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 26) {
		return "modules::ispa_dep_scanner::atom (production 26) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 27) {
		return "modules::ispa_dep_scanner::atom (production 27) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 28) {
		return "modules::ispa_dep_scanner::atom (production 28) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 29) {
		return "modules::ispa_dep_scanner::atom (production 29) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 30) {
		return "modules::ispa_dep_scanner::atom (production 30) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 31) {
		return "modules::ispa_dep_scanner::atom (production 31) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 32) {
		return "modules::ispa_dep_scanner::atom (production 32) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 33) {
		return "modules::ispa_dep_scanner::atom (production 33) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 34) {
		return "modules::ispa_dep_scanner::atom (production 34) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 35) {
		return "modules::ispa_dep_scanner::balanced_item (production 35) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 36) {
		return "modules::ispa_dep_scanner::balanced_item (production 36) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 37) {
		return "modules::ispa_dep_scanner::balanced_item (production 37) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 38) {
		return "modules::ispa_dep_scanner::balanced_item (production 38) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 39) {
		return "modules::ispa_dep_scanner::balanced_item (production 39) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 40) {
		return "modules::ispa_dep_scanner::body (production 40) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 41) {
		return "modules::ispa_dep_scanner::body (production 41) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 42) {
		return "modules::ispa_dep_scanner::body::regular (production 42) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 43) {
		return "modules::ispa_dep_scanner::body::regular (production 43) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 44) {
		return "modules::ispa_dep_scanner::body::regular (production 44) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 45) {
		return "modules::ispa_dep_scanner::body::regular (production 45) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 46) {
		return "modules::ispa_dep_scanner::body::regular (production 46) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 47) {
		return "modules::ispa_dep_scanner::braces (production 47) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 48) {
		return "modules::ispa_dep_scanner::braces (production 48) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 49) {
		return "modules::ispa_dep_scanner::braces (production 49) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 50) {
		return "modules::ispa_dep_scanner::braces (production 50) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 51) {
		return "modules::ispa_dep_scanner::braces (production 51) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 52) {
		return "modules::ispa_dep_scanner::declaration (production 52) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 53) {
		return "modules::ispa_dep_scanner::declaration (production 53) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 54) {
		return "modules::ispa_dep_scanner::declaration (production 54) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 55) {
		return "modules::ispa_dep_scanner::declaration (production 55) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 56) {
		return "modules::ispa_dep_scanner::declaration (production 56) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 57) {
		return "modules::ispa_dep_scanner::fail_decl (production 57) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 58) {
		return "modules::ispa_dep_scanner::feature_decl (production 58) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 59) {
		return "modules::ispa_dep_scanner::feature_decl (production 59) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 60) {
		return "modules::ispa_dep_scanner::feature_decl (production 60) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 61) {
		return "modules::ispa_dep_scanner::identifier (production 61) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 62) {
		return "modules::ispa_dep_scanner::identifier (production 62) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 63) {
		return "modules::ispa_dep_scanner::identifier (production 63) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 64) {
		return "modules::ispa_dep_scanner::identifier (production 64) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 65) {
		return "modules::ispa_dep_scanner::identifier (production 65) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 66) {
		return "modules::ispa_dep_scanner::identifier (production 66) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 67) {
		return "modules::ispa_dep_scanner::identifier (production 67) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 68) {
		return "modules::ispa_dep_scanner::identifier (production 68) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 69) {
		return "modules::ispa_dep_scanner::keyword (production 69) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 70) {
		return "modules::ispa_dep_scanner::keyword (production 70) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 71) {
		return "modules::ispa_dep_scanner::keyword (production 71) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 72) {
		return "modules::ispa_dep_scanner::keyword (production 72) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 73) {
		return "modules::ispa_dep_scanner::keyword (production 73) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 74) {
		return "modules::ispa_dep_scanner::keyword (production 74) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 75) {
		return "modules::ispa_dep_scanner::keyword (production 75) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 76) {
		return "modules::ispa_dep_scanner::keyword_name (production 76) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 77) {
		return "modules::ispa_dep_scanner::keyword_name (production 77) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 78) {
		return "modules::ispa_dep_scanner::keyword_name (production 78) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 79) {
		return "modules::ispa_dep_scanner::keyword_name (production 79) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 80) {
		return "modules::ispa_dep_scanner::keyword_name (production 80) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 81) {
		return "modules::ispa_dep_scanner::keyword_name (production 81) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 82) {
		return "modules::ispa_dep_scanner::keyword_name (production 82) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 83) {
		return "modules::ispa_dep_scanner::main (production 83) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 84) {
		return "modules::ispa_dep_scanner::main (production 84) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 85) {
		return "modules::ispa_dep_scanner::main (production 85) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 86) {
		return "modules::ispa_dep_scanner::main (production 86) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 87) {
		return "modules::ispa_dep_scanner::main (production 87) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 88) {
		return "modules::ispa_dep_scanner::main (production 88) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 89) {
		return "modules::ispa_dep_scanner::main (production 89) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 90) {
		return "modules::ispa_dep_scanner::main (production 90) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 91) {
		return "modules::ispa_dep_scanner::main (production 91) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 92) {
		return "modules::ispa_dep_scanner::main (production 92) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 93) {
		return "modules::ispa_dep_scanner::main (production 93) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 94) {
		return "modules::ispa_dep_scanner::main (production 94) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 95) {
		return "modules::ispa_dep_scanner::member (production 95) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 96) {
		return "modules::ispa_dep_scanner::member (production 96) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 97) {
		return "modules::ispa_dep_scanner::member (production 97) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 98) {
		return "modules::ispa_dep_scanner::member (production 98) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 99) {
		return "modules::ispa_dep_scanner::mod_detach (production 99) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 100) {
		return "modules::ispa_dep_scanner::mod_detach::detach_value (production 100) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 101) {
		return "modules::ispa_dep_scanner::mod_detach::detach_value (production 101) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 102) {
		return "modules::ispa_dep_scanner::mod_detach::detach_value::feature (production 102) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 103) {
		return "modules::ispa_dep_scanner::mod_import (production 103) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 104) {
		return "modules::ispa_dep_scanner::mod_import::import_value (production 104) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 105) {
		return "modules::ispa_dep_scanner::mod_import::import_value (production 105) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 106) {
		return "modules::ispa_dep_scanner::mod_import::import_value::from_import (production 106) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 107) {
		return "modules::ispa_dep_scanner::mod_import::import_value::from_import::selection (production 107) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 108) {
		return "modules::ispa_dep_scanner::mod_import::import_value::from_import::selection (production 108) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 109) {
		return "modules::ispa_dep_scanner::mod_import::import_value::from_import::selection::items (production 109) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 110) {
		return "modules::ispa_dep_scanner::mod_import::import_value::from_import::selection::items (production 110) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 111) {
		return "modules::ispa_dep_scanner::mod_import::import_value::from_import::selection::items (production 111) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 112) {
		return "modules::ispa_dep_scanner::mod_import::import_value::from_import::selection::items (production 112) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 113) {
		return "modules::ispa_dep_scanner::mod_import::import_value::from_import::selection::items (production 113) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 114) {
		return "modules::ispa_dep_scanner::mod_import::import_value::module_import (production 114) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 115) {
		return "modules::ispa_dep_scanner::mod_import::import_value::module_import (production 115) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 116) {
		return "modules::ispa_dep_scanner::mod_import::import_value::module_import (production 116) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 117) {
		return "modules::ispa_dep_scanner::mod_module (production 117) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 118) {
		return "modules::ispa_dep_scanner::mod_module (production 118) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 119) {
		return "modules::ispa_dep_scanner::mod_module (production 119) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 120) {
		return "modules::ispa_dep_scanner::mod_module (production 120) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 121) {
		return "modules::ispa_dep_scanner::mod_module (production 121) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 122) {
		return "modules::ispa_dep_scanner::modifier (production 122) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 123) {
		return "modules::ispa_dep_scanner::module_path (production 123) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 124) {
		return "modules::ispa_dep_scanner::module_path (production 124) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 125) {
		return "modules::ispa_dep_scanner::module_path (production 125) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 126) {
		return "modules::ispa_dep_scanner::module_path (production 126) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 127) {
		return "modules::ispa_dep_scanner::module_path (production 127) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 128) {
		return "modules::ispa_dep_scanner::nested_rule (production 128) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 129) {
		return "modules::ispa_dep_scanner::parentheses (production 129) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 130) {
		return "modules::ispa_dep_scanner::parentheses (production 130) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 131) {
		return "modules::ispa_dep_scanner::parentheses (production 131) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 132) {
		return "modules::ispa_dep_scanner::parentheses (production 132) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 133) {
		return "modules::ispa_dep_scanner::parentheses (production 133) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 134) {
		return "modules::ispa_dep_scanner::source_name (production 134) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 135) {
		return "modules::ispa_dep_scanner::source_name (production 135) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 136) {
		return "modules::ispa_dep_scanner::symbol_list (production 136) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 137) {
		return "modules::ispa_dep_scanner::symbol_list (production 137) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 138) {
		return "modules::ispa_dep_scanner::symbol_list (production 138) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 139) {
		return "modules::ispa_dep_scanner::symbol_list (production 139) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	if (rule == 140) {
		return "modules::ispa_dep_scanner::symbol_list (production 140) at /mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/ispa_dep_scanner/grammar.isc";
	}
	throw std::runtime_error("Invalid LR table entry or unexpected token");
}
auto DepParser::Parser::lr_goto(std::size_t state, std::size_t lhs) -> std::size_t {
	if (state == 186 && lhs == 66) {
		return 189;
	}
	if (state == 180 && lhs == 49) {
		return 187;
	}
	if (state == 178 && lhs == 63) {
		return 186;
	}
	if (state == 178 && lhs == 31) {
		return 30;
	}
	if (state == 178 && lhs == 30) {
		return 29;
	}
	if (state == 178 && lhs == 2) {
		return 21;
	}
	if (state == 169 && lhs == 9) {
		return 183;
	}
	if (state == 168 && lhs == 58) {
		return 181;
	}
	if (state == 163 && lhs == 11) {
		return 177;
	}
	if (state == 163 && lhs == 7) {
		return 176;
	}
	if (state == 158 && lhs == 60) {
		return 126;
	}
	if (state == 158 && lhs == 59) {
		return 125;
	}
	if (state == 158 && lhs == 29) {
		return 123;
	}
	if (state == 158 && lhs == 39) {
		return 158;
	}
	if (state == 158 && lhs == 20) {
		return 122;
	}
	if (state == 158 && lhs == 19) {
		return 173;
	}
	if (state == 158 && lhs == 14) {
		return 120;
	}
	if (state == 56 && lhs == 20) {
		return 83;
	}
	if (state == 56 && lhs == 17) {
		return 82;
	}
	if (state == 56 && lhs == 16) {
		return 81;
	}
	if (state == 153 && lhs == 60) {
		return 133;
	}
	if (state == 153 && lhs == 20) {
		return 131;
	}
	if (state == 153 && lhs == 29) {
		return 123;
	}
	if (state == 153 && lhs == 62) {
		return 171;
	}
	if (state == 153 && lhs == 15) {
		return 170;
	}
	if (state == 153 && lhs == 14) {
		return 129;
	}
	if (state == 130 && lhs == 60) {
		return 133;
	}
	if (state == 130 && lhs == 20) {
		return 131;
	}
	if (state == 130 && lhs == 29) {
		return 123;
	}
	if (state == 130 && lhs == 15) {
		return 159;
	}
	if (state == 130 && lhs == 22) {
		return 160;
	}
	if (state == 130 && lhs == 14) {
		return 129;
	}
	if (state == 124 && lhs == 60) {
		return 126;
	}
	if (state == 124 && lhs == 59) {
		return 125;
	}
	if (state == 124 && lhs == 29) {
		return 123;
	}
	if (state == 124 && lhs == 39) {
		return 158;
	}
	if (state == 124 && lhs == 20) {
		return 122;
	}
	if (state == 124 && lhs == 19) {
		return 157;
	}
	if (state == 124 && lhs == 14) {
		return 120;
	}
	if (state == 108 && lhs == 60) {
		return 133;
	}
	if (state == 108 && lhs == 20) {
		return 131;
	}
	if (state == 108 && lhs == 29) {
		return 123;
	}
	if (state == 108 && lhs == 61) {
		return 154;
	}
	if (state == 108 && lhs == 15) {
		return 153;
	}
	if (state == 108 && lhs == 14) {
		return 129;
	}
	if (state == 3 && lhs == 31) {
		return 30;
	}
	if (state == 3 && lhs == 63) {
		return 33;
	}
	if (state == 3 && lhs == 30) {
		return 29;
	}
	if (state == 3 && lhs == 42) {
		return 32;
	}
	if (state == 3 && lhs == 41) {
		return 31;
	}
	if (state == 3 && lhs == 2) {
		return 21;
	}
	if (state == 100 && lhs == 8) {
		return 149;
	}
	if (state == 188 && lhs == 9) {
		return 190;
	}
	if (state == 91 && lhs == 34) {
		return 140;
	}
	if (state == 91 && lhs == 10) {
		return 139;
	}
	if (state == 87 && lhs == 10) {
		return 138;
	}
	if (state == 87 && lhs == 6) {
		return 137;
	}
	if (state == 86 && lhs == 4) {
		return 135;
	}
	if (state == 80 && lhs == 60) {
		return 133;
	}
	if (state == 80 && lhs == 20) {
		return 131;
	}
	if (state == 80 && lhs == 29) {
		return 123;
	}
	if (state == 80 && lhs == 21) {
		return 132;
	}
	if (state == 80 && lhs == 15) {
		return 130;
	}
	if (state == 80 && lhs == 14) {
		return 129;
	}
	if (state == 79 && lhs == 60) {
		return 126;
	}
	if (state == 79 && lhs == 59) {
		return 125;
	}
	if (state == 79 && lhs == 29) {
		return 123;
	}
	if (state == 79 && lhs == 39) {
		return 124;
	}
	if (state == 79 && lhs == 20) {
		return 122;
	}
	if (state == 79 && lhs == 18) {
		return 121;
	}
	if (state == 79 && lhs == 14) {
		return 120;
	}
	if (state == 78 && lhs == 53) {
		return 104;
	}
	if (state == 74 && lhs == 29) {
		return 99;
	}
	if (state == 170 && lhs == 60) {
		return 133;
	}
	if (state == 170 && lhs == 20) {
		return 131;
	}
	if (state == 170 && lhs == 29) {
		return 123;
	}
	if (state == 170 && lhs == 62) {
		return 184;
	}
	if (state == 170 && lhs == 15) {
		return 170;
	}
	if (state == 170 && lhs == 14) {
		return 129;
	}
	if (state == 73 && lhs == 56) {
		return 98;
	}
	if (state == 73 && lhs == 29) {
		return 48;
	}
	if (state == 20 && lhs == 3) {
		return 62;
	}
	if (state == 117 && lhs == 24) {
		return 10;
	}
	if (state == 117 && lhs == 55) {
		return 19;
	}
	if (state == 117 && lhs == 23) {
		return 155;
	}
	if (state == 70 && lhs == 29) {
		return 97;
	}
	if (state == 166 && lhs == 63) {
		return 180;
	}
	if (state == 166 && lhs == 31) {
		return 30;
	}
	if (state == 166 && lhs == 30) {
		return 29;
	}
	if (state == 166 && lhs == 2) {
		return 21;
	}
	if (state == 69 && lhs == 48) {
		return 96;
	}
	if (state == 165 && lhs == 66) {
		return 179;
	}
	if (state == 68 && lhs == 31) {
		return 30;
	}
	if (state == 68 && lhs == 64) {
		return 94;
	}
	if (state == 68 && lhs == 30) {
		return 29;
	}
	if (state == 68 && lhs == 63) {
		return 93;
	}
	if (state == 68 && lhs == 28) {
		return 92;
	}
	if (state == 68 && lhs == 2) {
		return 21;
	}
	if (state == 64 && lhs == 2) {
		return 89;
	}
	if (state == 15 && lhs == 55) {
		return 19;
	}
	if (state == 15 && lhs == 43) {
		return 17;
	}
	if (state == 15 && lhs == 52) {
		return 18;
	}
	if (state == 15 && lhs == 40) {
		return 16;
	}
	if (state == 15 && lhs == 37) {
		return 57;
	}
	if (state == 15 && lhs == 26) {
		return 11;
	}
	if (state == 15 && lhs == 38) {
		return 58;
	}
	if (state == 15 && lhs == 27) {
		return 12;
	}
	if (state == 15 && lhs == 24) {
		return 10;
	}
	if (state == 15 && lhs == 23) {
		return 9;
	}
	if (state == 159 && lhs == 60) {
		return 133;
	}
	if (state == 159 && lhs == 20) {
		return 131;
	}
	if (state == 159 && lhs == 29) {
		return 123;
	}
	if (state == 159 && lhs == 15) {
		return 159;
	}
	if (state == 159 && lhs == 22) {
		return 174;
	}
	if (state == 159 && lhs == 14) {
		return 129;
	}
	if (state == 62 && lhs == 12) {
		return 88;
	}
	if (state == 62 && lhs == 5) {
		return 87;
	}
	if (state == 60 && lhs == 55) {
		return 60;
	}
	if (state == 60 && lhs == 25) {
		return 85;
	}
	if (state == 10 && lhs == 63) {
		return 56;
	}
	if (state == 10 && lhs == 31) {
		return 30;
	}
	if (state == 10 && lhs == 30) {
		return 29;
	}
	if (state == 10 && lhs == 2) {
		return 21;
	}
	if (state == 57 && lhs == 55) {
		return 19;
	}
	if (state == 57 && lhs == 43) {
		return 17;
	}
	if (state == 57 && lhs == 52) {
		return 18;
	}
	if (state == 57 && lhs == 40) {
		return 16;
	}
	if (state == 57 && lhs == 37) {
		return 57;
	}
	if (state == 57 && lhs == 26) {
		return 11;
	}
	if (state == 57 && lhs == 38) {
		return 84;
	}
	if (state == 57 && lhs == 27) {
		return 12;
	}
	if (state == 57 && lhs == 24) {
		return 10;
	}
	if (state == 57 && lhs == 23) {
		return 9;
	}
	if (state == 8 && lhs == 56) {
		return 55;
	}
	if (state == 8 && lhs == 29) {
		return 48;
	}
	if (state == 55 && lhs == 54) {
		return 78;
	}
	if (state == 55 && lhs == 12) {
		return 77;
	}
	if (state == 76 && lhs == 13) {
		return 102;
	}
	if (state == 76 && lhs == 7) {
		return 101;
	}
	if (state == 29 && lhs == 32) {
		return 65;
	}
	if (state == 103 && lhs == 63) {
		return 151;
	}
	if (state == 103 && lhs == 31) {
		return 30;
	}
	if (state == 103 && lhs == 30) {
		return 29;
	}
	if (state == 103 && lhs == 2) {
		return 21;
	}
	if (state == 162 && lhs == 4) {
		return 175;
	}
	if (state == 65 && lhs == 33) {
		return 91;
	}
	if (state == 65 && lhs == 12) {
		return 90;
	}
	if (state == 19 && lhs == 55) {
		return 60;
	}
	if (state == 19 && lhs == 25) {
		return 59;
	}
	if (state == 54 && lhs == 51) {
		return 75;
	}
	if (state == 7 && lhs == 50) {
		return 53;
	}
	if (state == 7 && lhs == 45) {
		return 50;
	}
	if (state == 7 && lhs == 47) {
		return 52;
	}
	if (state == 7 && lhs == 46) {
		return 51;
	}
	if (state == 7 && lhs == 56) {
		return 54;
	}
	if (state == 7 && lhs == 44) {
		return 49;
	}
	if (state == 7 && lhs == 29) {
		return 48;
	}
	if (state == 4 && lhs == 63) {
		return 35;
	}
	if (state == 4 && lhs == 31) {
		return 30;
	}
	if (state == 4 && lhs == 30) {
		return 29;
	}
	if (state == 4 && lhs == 2) {
		return 21;
	}
	if (state == 142 && lhs == 63) {
		return 165;
	}
	if (state == 142 && lhs == 31) {
		return 30;
	}
	if (state == 142 && lhs == 30) {
		return 29;
	}
	if (state == 142 && lhs == 2) {
		return 21;
	}
	if (state == 95 && lhs == 63) {
		return 144;
	}
	if (state == 95 && lhs == 31) {
		return 30;
	}
	if (state == 95 && lhs == 30) {
		return 29;
	}
	if (state == 95 && lhs == 2) {
		return 21;
	}
	if (state == 48 && lhs == 57) {
		return 71;
	}
	if (state == 25 && lhs == 63) {
		return 63;
	}
	if (state == 25 && lhs == 31) {
		return 30;
	}
	if (state == 25 && lhs == 30) {
		return 29;
	}
	if (state == 25 && lhs == 2) {
		return 21;
	}
	if (state == 144 && lhs == 49) {
		return 167;
	}
	if (state == 0 && lhs == 55) {
		return 19;
	}
	if (state == 0 && lhs == 43) {
		return 17;
	}
	if (state == 0 && lhs == 52) {
		return 18;
	}
	if (state == 0 && lhs == 40) {
		return 16;
	}
	if (state == 0 && lhs == 37) {
		return 15;
	}
	if (state == 0 && lhs == 36) {
		return 14;
	}
	if (state == 0 && lhs == 26) {
		return 11;
	}
	if (state == 0 && lhs == 27) {
		return 12;
	}
	if (state == 0 && lhs == 24) {
		return 10;
	}
	if (state == 0 && lhs == 35) {
		return 13;
	}
	if (state == 0 && lhs == 23) {
		return 9;
	}
	if (state == 0 && lhs == 1) {
		return 1;
	}
	if (state == 97 && lhs == 58) {
		return 147;
	}
	if (state == 146 && lhs == 29) {
		return 168;
	}
	if (state == 5 && lhs == 63) {
		return 36;
	}
	if (state == 5 && lhs == 31) {
		return 30;
	}
	if (state == 5 && lhs == 30) {
		return 29;
	}
	if (state == 5 && lhs == 2) {
		return 21;
	}
	if (state == 93 && lhs == 65) {
		return 143;
	}
	if (state == 46 && lhs == 63) {
		return 69;
	}
	if (state == 46 && lhs == 31) {
		return 30;
	}
	if (state == 46 && lhs == 30) {
		return 29;
	}
	if (state == 46 && lhs == 2) {
		return 21;
	}
	throw std::runtime_error("Invalid LR table entry or unexpected token");
}
auto DepParser::Parser::lr_length(std::size_t rule) -> std::size_t {
	if (rule == 0) {
		return 1;
	}
	if (rule == 1) {
		return 4;
	}
	if (rule == 2) {
		return 0;
	}
	if (rule == 3) {
		return 3;
	}
	if (rule == 4) {
		return 0;
	}
	if (rule == 5) {
		return 3;
	}
	if (rule == 6) {
		return 0;
	}
	if (rule == 7) {
		return 1;
	}
	if (rule == 8) {
		return 0;
	}
	if (rule == 9) {
		return 1;
	}
	if (rule == 10) {
		return 2;
	}
	if (rule == 11) {
		return 0;
	}
	if (rule == 12) {
		return 3;
	}
	if (rule == 13) {
		return 0;
	}
	if (rule == 14) {
		return 3;
	}
	if (rule == 15) {
		return 4;
	}
	if (rule == 16) {
		return 0;
	}
	if (rule == 17) {
		return 1;
	}
	if (rule == 18) {
		return 3;
	}
	if (rule == 19) {
		return 0;
	}
	if (rule == 20) {
		return 1;
	}
	if (rule == 21) {
		return 1;
	}
	if (rule == 22) {
		return 1;
	}
	if (rule == 23) {
		return 1;
	}
	if (rule == 24) {
		return 1;
	}
	if (rule == 25) {
		return 1;
	}
	if (rule == 26) {
		return 1;
	}
	if (rule == 27) {
		return 1;
	}
	if (rule == 28) {
		return 1;
	}
	if (rule == 29) {
		return 1;
	}
	if (rule == 30) {
		return 1;
	}
	if (rule == 31) {
		return 1;
	}
	if (rule == 32) {
		return 1;
	}
	if (rule == 33) {
		return 1;
	}
	if (rule == 34) {
		return 1;
	}
	if (rule == 35) {
		return 1;
	}
	if (rule == 36) {
		return 1;
	}
	if (rule == 37) {
		return 1;
	}
	if (rule == 38) {
		return 1;
	}
	if (rule == 39) {
		return 1;
	}
	if (rule == 40) {
		return 1;
	}
	if (rule == 41) {
		return 1;
	}
	if (rule == 42) {
		return 3;
	}
	if (rule == 43) {
		return 0;
	}
	if (rule == 44) {
		return 2;
	}
	if (rule == 45) {
		return 0;
	}
	if (rule == 46) {
		return 2;
	}
	if (rule == 47) {
		return 3;
	}
	if (rule == 48) {
		return 0;
	}
	if (rule == 49) {
		return 2;
	}
	if (rule == 50) {
		return 0;
	}
	if (rule == 51) {
		return 2;
	}
	if (rule == 52) {
		return 3;
	}
	if (rule == 53) {
		return 0;
	}
	if (rule == 54) {
		return 2;
	}
	if (rule == 55) {
		return 0;
	}
	if (rule == 56) {
		return 2;
	}
	if (rule == 57) {
		return 3;
	}
	if (rule == 58) {
		return 6;
	}
	if (rule == 59) {
		return 0;
	}
	if (rule == 60) {
		return 1;
	}
	if (rule == 61) {
		return 1;
	}
	if (rule == 62) {
		return 1;
	}
	if (rule == 63) {
		return 1;
	}
	if (rule == 64) {
		return 1;
	}
	if (rule == 65) {
		return 1;
	}
	if (rule == 66) {
		return 1;
	}
	if (rule == 67) {
		return 1;
	}
	if (rule == 68) {
		return 1;
	}
	if (rule == 69) {
		return 1;
	}
	if (rule == 70) {
		return 1;
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
		return 1;
	}
	if (rule == 75) {
		return 1;
	}
	if (rule == 76) {
		return 4;
	}
	if (rule == 77) {
		return 0;
	}
	if (rule == 78) {
		return 2;
	}
	if (rule == 79) {
		return 0;
	}
	if (rule == 80) {
		return 1;
	}
	if (rule == 81) {
		return 0;
	}
	if (rule == 82) {
		return 1;
	}
	if (rule == 83) {
		return 1;
	}
	if (rule == 84) {
		return 0;
	}
	if (rule == 85) {
		return 2;
	}
	if (rule == 86) {
		return 1;
	}
	if (rule == 87) {
		return 1;
	}
	if (rule == 88) {
		return 1;
	}
	if (rule == 89) {
		return 1;
	}
	if (rule == 90) {
		return 1;
	}
	if (rule == 91) {
		return 1;
	}
	if (rule == 92) {
		return 1;
	}
	if (rule == 93) {
		return 0;
	}
	if (rule == 94) {
		return 2;
	}
	if (rule == 95) {
		return 1;
	}
	if (rule == 96) {
		return 1;
	}
	if (rule == 97) {
		return 1;
	}
	if (rule == 98) {
		return 1;
	}
	if (rule == 99) {
		return 3;
	}
	if (rule == 100) {
		return 1;
	}
	if (rule == 101) {
		return 1;
	}
	if (rule == 102) {
		return 2;
	}
	if (rule == 103) {
		return 3;
	}
	if (rule == 104) {
		return 1;
	}
	if (rule == 105) {
		return 1;
	}
	if (rule == 106) {
		return 3;
	}
	if (rule == 107) {
		return 1;
	}
	if (rule == 108) {
		return 1;
	}
	if (rule == 109) {
		return 4;
	}
	if (rule == 110) {
		return 0;
	}
	if (rule == 111) {
		return 3;
	}
	if (rule == 112) {
		return 0;
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
		return 0;
	}
	if (rule == 119) {
		return 2;
	}
	if (rule == 120) {
		return 0;
	}
	if (rule == 121) {
		return 1;
	}
	if (rule == 122) {
		return 2;
	}
	if (rule == 123) {
		return 2;
	}
	if (rule == 124) {
		return 0;
	}
	if (rule == 125) {
		return 3;
	}
	if (rule == 126) {
		return 0;
	}
	if (rule == 127) {
		return 3;
	}
	if (rule == 128) {
		return 2;
	}
	if (rule == 129) {
		return 3;
	}
	if (rule == 130) {
		return 0;
	}
	if (rule == 131) {
		return 2;
	}
	if (rule == 132) {
		return 0;
	}
	if (rule == 133) {
		return 2;
	}
	if (rule == 134) {
		return 1;
	}
	if (rule == 135) {
		return 1;
	}
	if (rule == 136) {
		return 2;
	}
	if (rule == 137) {
		return 0;
	}
	if (rule == 138) {
		return 3;
	}
	if (rule == 139) {
		return 0;
	}
	if (rule == 140) {
		return 3;
	}
	throw std::runtime_error("Invalid LR table entry or unexpected token");
}
auto DepParser::Parser::lr_lhs(std::size_t rule) -> std::size_t {
	if (rule == 0) {
		return 1;
	}
	if (rule == 1) {
		return 2;
	}
	if (rule == 2) {
		return 3;
	}
	if (rule == 3) {
		return 3;
	}
	if (rule == 4) {
		return 4;
	}
	if (rule == 5) {
		return 4;
	}
	if (rule == 6) {
		return 5;
	}
	if (rule == 7) {
		return 5;
	}
	if (rule == 8) {
		return 6;
	}
	if (rule == 9) {
		return 6;
	}
	if (rule == 10) {
		return 7;
	}
	if (rule == 11) {
		return 8;
	}
	if (rule == 12) {
		return 8;
	}
	if (rule == 13) {
		return 9;
	}
	if (rule == 14) {
		return 9;
	}
	if (rule == 15) {
		return 10;
	}
	if (rule == 16) {
		return 11;
	}
	if (rule == 17) {
		return 11;
	}
	if (rule == 18) {
		return 12;
	}
	if (rule == 19) {
		return 13;
	}
	if (rule == 20) {
		return 13;
	}
	if (rule == 21) {
		return 14;
	}
	if (rule == 22) {
		return 14;
	}
	if (rule == 23) {
		return 14;
	}
	if (rule == 24) {
		return 14;
	}
	if (rule == 25) {
		return 14;
	}
	if (rule == 26) {
		return 14;
	}
	if (rule == 27) {
		return 14;
	}
	if (rule == 28) {
		return 14;
	}
	if (rule == 29) {
		return 14;
	}
	if (rule == 30) {
		return 14;
	}
	if (rule == 31) {
		return 14;
	}
	if (rule == 32) {
		return 14;
	}
	if (rule == 33) {
		return 14;
	}
	if (rule == 34) {
		return 14;
	}
	if (rule == 35) {
		return 15;
	}
	if (rule == 36) {
		return 15;
	}
	if (rule == 37) {
		return 15;
	}
	if (rule == 38) {
		return 15;
	}
	if (rule == 39) {
		return 15;
	}
	if (rule == 40) {
		return 16;
	}
	if (rule == 41) {
		return 16;
	}
	if (rule == 42) {
		return 17;
	}
	if (rule == 43) {
		return 18;
	}
	if (rule == 44) {
		return 18;
	}
	if (rule == 45) {
		return 19;
	}
	if (rule == 46) {
		return 19;
	}
	if (rule == 47) {
		return 20;
	}
	if (rule == 48) {
		return 21;
	}
	if (rule == 49) {
		return 21;
	}
	if (rule == 50) {
		return 22;
	}
	if (rule == 51) {
		return 22;
	}
	if (rule == 52) {
		return 23;
	}
	if (rule == 53) {
		return 24;
	}
	if (rule == 54) {
		return 24;
	}
	if (rule == 55) {
		return 25;
	}
	if (rule == 56) {
		return 25;
	}
	if (rule == 57) {
		return 26;
	}
	if (rule == 58) {
		return 27;
	}
	if (rule == 59) {
		return 28;
	}
	if (rule == 60) {
		return 28;
	}
	if (rule == 61) {
		return 29;
	}
	if (rule == 62) {
		return 29;
	}
	if (rule == 63) {
		return 29;
	}
	if (rule == 64) {
		return 29;
	}
	if (rule == 65) {
		return 29;
	}
	if (rule == 66) {
		return 29;
	}
	if (rule == 67) {
		return 29;
	}
	if (rule == 68) {
		return 29;
	}
	if (rule == 69) {
		return 30;
	}
	if (rule == 70) {
		return 30;
	}
	if (rule == 71) {
		return 30;
	}
	if (rule == 72) {
		return 30;
	}
	if (rule == 73) {
		return 30;
	}
	if (rule == 74) {
		return 30;
	}
	if (rule == 75) {
		return 30;
	}
	if (rule == 76) {
		return 31;
	}
	if (rule == 77) {
		return 32;
	}
	if (rule == 78) {
		return 32;
	}
	if (rule == 79) {
		return 33;
	}
	if (rule == 80) {
		return 33;
	}
	if (rule == 81) {
		return 34;
	}
	if (rule == 82) {
		return 34;
	}
	if (rule == 83) {
		return 35;
	}
	if (rule == 84) {
		return 36;
	}
	if (rule == 85) {
		return 36;
	}
	if (rule == 86) {
		return 37;
	}
	if (rule == 87) {
		return 37;
	}
	if (rule == 88) {
		return 37;
	}
	if (rule == 89) {
		return 37;
	}
	if (rule == 90) {
		return 37;
	}
	if (rule == 91) {
		return 37;
	}
	if (rule == 92) {
		return 37;
	}
	if (rule == 93) {
		return 38;
	}
	if (rule == 94) {
		return 38;
	}
	if (rule == 95) {
		return 39;
	}
	if (rule == 96) {
		return 39;
	}
	if (rule == 97) {
		return 39;
	}
	if (rule == 98) {
		return 39;
	}
	if (rule == 99) {
		return 40;
	}
	if (rule == 100) {
		return 41;
	}
	if (rule == 101) {
		return 41;
	}
	if (rule == 102) {
		return 42;
	}
	if (rule == 103) {
		return 43;
	}
	if (rule == 104) {
		return 44;
	}
	if (rule == 105) {
		return 44;
	}
	if (rule == 106) {
		return 45;
	}
	if (rule == 107) {
		return 46;
	}
	if (rule == 108) {
		return 46;
	}
	if (rule == 109) {
		return 47;
	}
	if (rule == 110) {
		return 48;
	}
	if (rule == 111) {
		return 48;
	}
	if (rule == 112) {
		return 49;
	}
	if (rule == 113) {
		return 49;
	}
	if (rule == 114) {
		return 50;
	}
	if (rule == 115) {
		return 51;
	}
	if (rule == 116) {
		return 51;
	}
	if (rule == 117) {
		return 52;
	}
	if (rule == 118) {
		return 53;
	}
	if (rule == 119) {
		return 53;
	}
	if (rule == 120) {
		return 54;
	}
	if (rule == 121) {
		return 54;
	}
	if (rule == 122) {
		return 55;
	}
	if (rule == 123) {
		return 56;
	}
	if (rule == 124) {
		return 57;
	}
	if (rule == 125) {
		return 57;
	}
	if (rule == 126) {
		return 58;
	}
	if (rule == 127) {
		return 58;
	}
	if (rule == 128) {
		return 59;
	}
	if (rule == 129) {
		return 60;
	}
	if (rule == 130) {
		return 61;
	}
	if (rule == 131) {
		return 61;
	}
	if (rule == 132) {
		return 62;
	}
	if (rule == 133) {
		return 62;
	}
	if (rule == 134) {
		return 63;
	}
	if (rule == 135) {
		return 63;
	}
	if (rule == 136) {
		return 64;
	}
	if (rule == 137) {
		return 65;
	}
	if (rule == 138) {
		return 65;
	}
	if (rule == 139) {
		return 66;
	}
	if (rule == 140) {
		return 66;
	}
	throw std::runtime_error("Invalid LR table entry or unexpected token");
}
auto DepParser::Parser::lr_reduce(std::size_t rule, const std::vector<std::any>& values) -> std::any {
	if (rule == 0) {
		Types::main result;
		lr_capture_assign(result.value, values, 0, static_cast<std::size_t>(-1));
		return lr_node<Types::main>(result);
	}
	if (rule == 1) {
		Types::modules::common::name result;
		lr_capture_assign(result.primary, values, 0, static_cast<std::size_t>(-1));
		lr_capture_assign(result.nested, values, 1, static_cast<std::size_t>(0));
		lr_capture_assign(result.temp_params, values, 2, static_cast<std::size_t>(-1));
		lr_capture_assign(result.param, values, 3, static_cast<std::size_t>(-1));
		return lr_node<Types::modules::common::name>(result);
	}
	if (rule == 2) {
		return lr_pack(values, {}, {}, {}, 1, true);
	}
	if (rule == 3) {
		return lr_pack(values, {1, 2}, {0, 0}, {0, 1}, 1, true);
	}
	if (rule == 4) {
		return lr_pack(values, {}, {}, {}, 1, true);
	}
	if (rule == 5) {
		return lr_pack(values, {1, 2}, {0, 0}, {0, 1}, 1, true);
	}
	if (rule == 6) {
		return lr_pack(values, {}, {}, {}, 1, false);
	}
	if (rule == 7) {
		return lr_pack(values, {0}, {0}, {0}, 1, false);
	}
	if (rule == 8) {
		return lr_pack(values, {}, {}, {}, 1, false);
	}
	if (rule == 9) {
		return lr_pack(values, {0}, {0}, {0}, 1, false);
	}
	if (rule == 10) {
		Types::modules::common::param result;
		lr_capture_assign(result.first_p, values, 0, static_cast<std::size_t>(-1));
		lr_capture_assign(result.following_p, values, 1, static_cast<std::size_t>(0));
		return lr_node<Types::modules::common::param>(result);
	}
	if (rule == 11) {
		return lr_pack(values, {}, {}, {}, 1, true);
	}
	if (rule == 12) {
		return lr_pack(values, {1, 2}, {0, 0}, {0, 1}, 1, true);
	}
	if (rule == 13) {
		return lr_pack(values, {}, {}, {}, 1, true);
	}
	if (rule == 14) {
		return lr_pack(values, {1, 2}, {0, 0}, {0, 1}, 1, true);
	}
	if (rule == 15) {
		Types::modules::common::params result;
		lr_capture_assign(result.value, values, 2, static_cast<std::size_t>(-1));
		return lr_node<Types::modules::common::params>(result);
	}
	if (rule == 16) {
		return lr_pack(values, {}, {}, {}, 1, false);
	}
	if (rule == 17) {
		return lr_pack(values, {0}, {0}, {0}, 1, false);
	}
	if (rule == 18) {
		Types::modules::common::template_params result;
		lr_capture_assign(result.value, values, 1, static_cast<std::size_t>(-1));
		return lr_node<Types::modules::common::template_params>(result);
	}
	if (rule == 19) {
		return lr_pack(values, {}, {}, {}, 1, false);
	}
	if (rule == 20) {
		return lr_pack(values, {0}, {0}, {0}, 1, false);
	}
	if (rule == 21) {
		Types::modules::ispa_dep_scanner::atom result;
		return lr_node<Types::modules::ispa_dep_scanner::atom>(result);
	}
	if (rule == 22) {
		Types::modules::ispa_dep_scanner::atom result;
		return lr_node<Types::modules::ispa_dep_scanner::atom>(result);
	}
	if (rule == 23) {
		Types::modules::ispa_dep_scanner::atom result;
		return lr_node<Types::modules::ispa_dep_scanner::atom>(result);
	}
	if (rule == 24) {
		Types::modules::ispa_dep_scanner::atom result;
		return lr_node<Types::modules::ispa_dep_scanner::atom>(result);
	}
	if (rule == 25) {
		Types::modules::ispa_dep_scanner::atom result;
		return lr_node<Types::modules::ispa_dep_scanner::atom>(result);
	}
	if (rule == 26) {
		Types::modules::ispa_dep_scanner::atom result;
		return lr_node<Types::modules::ispa_dep_scanner::atom>(result);
	}
	if (rule == 27) {
		Types::modules::ispa_dep_scanner::atom result;
		return lr_node<Types::modules::ispa_dep_scanner::atom>(result);
	}
	if (rule == 28) {
		Types::modules::ispa_dep_scanner::atom result;
		return lr_node<Types::modules::ispa_dep_scanner::atom>(result);
	}
	if (rule == 29) {
		Types::modules::ispa_dep_scanner::atom result;
		return lr_node<Types::modules::ispa_dep_scanner::atom>(result);
	}
	if (rule == 30) {
		Types::modules::ispa_dep_scanner::atom result;
		return lr_node<Types::modules::ispa_dep_scanner::atom>(result);
	}
	if (rule == 31) {
		Types::modules::ispa_dep_scanner::atom result;
		return lr_node<Types::modules::ispa_dep_scanner::atom>(result);
	}
	if (rule == 32) {
		Types::modules::ispa_dep_scanner::atom result;
		return lr_node<Types::modules::ispa_dep_scanner::atom>(result);
	}
	if (rule == 33) {
		Types::modules::ispa_dep_scanner::atom result;
		return lr_node<Types::modules::ispa_dep_scanner::atom>(result);
	}
	if (rule == 34) {
		Types::modules::ispa_dep_scanner::atom result;
		return lr_node<Types::modules::ispa_dep_scanner::atom>(result);
	}
	if (rule == 35) {
		Types::modules::ispa_dep_scanner::balanced_item result;
		return lr_node<Types::modules::ispa_dep_scanner::balanced_item>(result);
	}
	if (rule == 36) {
		Types::modules::ispa_dep_scanner::balanced_item result;
		return lr_node<Types::modules::ispa_dep_scanner::balanced_item>(result);
	}
	if (rule == 37) {
		Types::modules::ispa_dep_scanner::balanced_item result;
		return lr_node<Types::modules::ispa_dep_scanner::balanced_item>(result);
	}
	if (rule == 38) {
		Types::modules::ispa_dep_scanner::balanced_item result;
		return lr_node<Types::modules::ispa_dep_scanner::balanced_item>(result);
	}
	if (rule == 39) {
		Types::modules::ispa_dep_scanner::balanced_item result;
		return lr_node<Types::modules::ispa_dep_scanner::balanced_item>(result);
	}
	if (rule == 40) {
		Types::modules::ispa_dep_scanner::body result;
		lr_capture_assign(result.value, values, 0, static_cast<std::size_t>(-1));
		return lr_node<Types::modules::ispa_dep_scanner::body>(result);
	}
	if (rule == 41) {
		Types::modules::ispa_dep_scanner::body result;
		lr_capture_assign(result.value, values, 0, static_cast<std::size_t>(-1));
		return lr_node<Types::modules::ispa_dep_scanner::body>(result);
	}
	if (rule == 42) {
		Types::modules::ispa_dep_scanner::body::regular result;
		lr_capture_assign(result.value, values, 1, static_cast<std::size_t>(-1));
		return lr_node<Types::modules::ispa_dep_scanner::body::regular>(result);
	}
	if (rule == 43) {
		return lr_pack(values, {}, {}, {}, 1, true);
	}
	if (rule == 44) {
		return lr_pack(values, {0, 1}, {0, 0}, {0, 1}, 1, true);
	}
	if (rule == 45) {
		return lr_pack(values, {}, {}, {}, 1, true);
	}
	if (rule == 46) {
		return lr_pack(values, {0, 1}, {0, 0}, {0, 1}, 1, true);
	}
	if (rule == 47) {
		Types::modules::ispa_dep_scanner::braces result;
		return lr_node<Types::modules::ispa_dep_scanner::braces>(result);
	}
	if (rule == 48) {
		return lr_pack(values, {}, {}, {}, 1, true);
	}
	if (rule == 49) {
		return lr_pack(values, {0, 1}, {0, 0}, {0, 1}, 1, true);
	}
	if (rule == 50) {
		return lr_pack(values, {}, {}, {}, 1, true);
	}
	if (rule == 51) {
		return lr_pack(values, {0, 1}, {0, 0}, {0, 1}, 1, true);
	}
	if (rule == 52) {
		Types::modules::ispa_dep_scanner::declaration result;
		lr_capture_assign(result.modifiers, values, 0, static_cast<std::size_t>(-1));
		lr_capture_assign(result.name, values, 1, static_cast<std::size_t>(-1));
		lr_capture_assign(result.body, values, 2, static_cast<std::size_t>(-1));
		return lr_node<Types::modules::ispa_dep_scanner::declaration>(result);
	}
	if (rule == 53) {
		return lr_pack(values, {}, {}, {}, 1, true);
	}
	if (rule == 54) {
		return lr_pack(values, {0, 1}, {0, 0}, {0, 1}, 1, true);
	}
	if (rule == 55) {
		return lr_pack(values, {}, {}, {}, 1, true);
	}
	if (rule == 56) {
		return lr_pack(values, {0, 1}, {0, 0}, {0, 1}, 1, true);
	}
	if (rule == 57) {
		Types::modules::ispa_dep_scanner::fail_decl result;
		return lr_node<Types::modules::ispa_dep_scanner::fail_decl>(result);
	}
	if (rule == 58) {
		Types::modules::ispa_dep_scanner::feature_decl result;
		lr_capture_assign(result.begin, values, 0, static_cast<std::size_t>(-1));
		lr_capture_assign(result.name, values, 1, static_cast<std::size_t>(-1));
		lr_capture_assign(result.symbols, values, 3, static_cast<std::size_t>(-1));
		lr_capture_assign(result.end, values, 5, static_cast<std::size_t>(-1));
		return lr_node<Types::modules::ispa_dep_scanner::feature_decl>(result);
	}
	if (rule == 59) {
		return lr_pack(values, {}, {}, {}, 1, false);
	}
	if (rule == 60) {
		return lr_pack(values, {0}, {0}, {0}, 1, false);
	}
	if (rule == 61) {
		Types::modules::ispa_dep_scanner::identifier result;
		lr_capture_assign(result.value, values, 0, static_cast<std::size_t>(-1));
		return lr_node<Types::modules::ispa_dep_scanner::identifier>(result);
	}
	if (rule == 62) {
		Types::modules::ispa_dep_scanner::identifier result;
		lr_capture_assign(result.value, values, 0, static_cast<std::size_t>(-1));
		return lr_node<Types::modules::ispa_dep_scanner::identifier>(result);
	}
	if (rule == 63) {
		Types::modules::ispa_dep_scanner::identifier result;
		lr_capture_assign(result.value, values, 0, static_cast<std::size_t>(-1));
		return lr_node<Types::modules::ispa_dep_scanner::identifier>(result);
	}
	if (rule == 64) {
		Types::modules::ispa_dep_scanner::identifier result;
		lr_capture_assign(result.value, values, 0, static_cast<std::size_t>(-1));
		return lr_node<Types::modules::ispa_dep_scanner::identifier>(result);
	}
	if (rule == 65) {
		Types::modules::ispa_dep_scanner::identifier result;
		lr_capture_assign(result.value, values, 0, static_cast<std::size_t>(-1));
		return lr_node<Types::modules::ispa_dep_scanner::identifier>(result);
	}
	if (rule == 66) {
		Types::modules::ispa_dep_scanner::identifier result;
		lr_capture_assign(result.value, values, 0, static_cast<std::size_t>(-1));
		return lr_node<Types::modules::ispa_dep_scanner::identifier>(result);
	}
	if (rule == 67) {
		Types::modules::ispa_dep_scanner::identifier result;
		lr_capture_assign(result.value, values, 0, static_cast<std::size_t>(-1));
		return lr_node<Types::modules::ispa_dep_scanner::identifier>(result);
	}
	if (rule == 68) {
		Types::modules::ispa_dep_scanner::identifier result;
		lr_capture_assign(result.value, values, 0, static_cast<std::size_t>(-1));
		return lr_node<Types::modules::ispa_dep_scanner::identifier>(result);
	}
	if (rule == 69) {
		Types::modules::ispa_dep_scanner::keyword result;
		lr_capture_assign(result.value, values, 0, static_cast<std::size_t>(-1));
		return lr_node<Types::modules::ispa_dep_scanner::keyword>(result);
	}
	if (rule == 70) {
		Types::modules::ispa_dep_scanner::keyword result;
		lr_capture_assign(result.value, values, 0, static_cast<std::size_t>(-1));
		return lr_node<Types::modules::ispa_dep_scanner::keyword>(result);
	}
	if (rule == 71) {
		Types::modules::ispa_dep_scanner::keyword result;
		lr_capture_assign(result.value, values, 0, static_cast<std::size_t>(-1));
		return lr_node<Types::modules::ispa_dep_scanner::keyword>(result);
	}
	if (rule == 72) {
		Types::modules::ispa_dep_scanner::keyword result;
		lr_capture_assign(result.value, values, 0, static_cast<std::size_t>(-1));
		return lr_node<Types::modules::ispa_dep_scanner::keyword>(result);
	}
	if (rule == 73) {
		Types::modules::ispa_dep_scanner::keyword result;
		lr_capture_assign(result.value, values, 0, static_cast<std::size_t>(-1));
		return lr_node<Types::modules::ispa_dep_scanner::keyword>(result);
	}
	if (rule == 74) {
		Types::modules::ispa_dep_scanner::keyword result;
		lr_capture_assign(result.value, values, 0, static_cast<std::size_t>(-1));
		return lr_node<Types::modules::ispa_dep_scanner::keyword>(result);
	}
	if (rule == 75) {
		Types::modules::ispa_dep_scanner::keyword result;
		lr_capture_assign(result.value, values, 0, static_cast<std::size_t>(-1));
		return lr_node<Types::modules::ispa_dep_scanner::keyword>(result);
	}
	if (rule == 76) {
		Types::modules::ispa_dep_scanner::keyword_name result;
		lr_capture_assign(result.primary, values, 0, static_cast<std::size_t>(-1));
		lr_capture_assign(result.tail, values, 1, static_cast<std::size_t>(0));
		lr_capture_assign(result.templates, values, 2, static_cast<std::size_t>(-1));
		lr_capture_assign(result.parameters, values, 3, static_cast<std::size_t>(-1));
		return lr_node<Types::modules::ispa_dep_scanner::keyword_name>(result);
	}
	if (rule == 77) {
		return lr_pack(values, {}, {}, {}, 1, false);
	}
	if (rule == 78) {
		return lr_pack(values, {1}, {0}, {0}, 1, false);
	}
	if (rule == 79) {
		return lr_pack(values, {}, {}, {}, 1, false);
	}
	if (rule == 80) {
		return lr_pack(values, {0}, {0}, {0}, 1, false);
	}
	if (rule == 81) {
		return lr_pack(values, {}, {}, {}, 1, false);
	}
	if (rule == 82) {
		return lr_pack(values, {0}, {0}, {0}, 1, false);
	}
	if (rule == 83) {
		Types::modules::ispa_dep_scanner::main result;
		lr_capture_assign(result.value, values, 0, static_cast<std::size_t>(-1));
		return lr_node<Types::modules::ispa_dep_scanner::main>(result);
	}
	if (rule == 84) {
		return lr_pack(values, {}, {}, {}, 1, true);
	}
	if (rule == 85) {
		return lr_pack(values, {0, 1}, {0, 0}, {0, 1}, 1, true);
	}
	if (rule == 86) {
		return lr_pack(values, {0}, {0}, {0}, 1, false);
	}
	if (rule == 87) {
		return lr_pack(values, {0}, {0}, {0}, 1, false);
	}
	if (rule == 88) {
		return lr_pack(values, {0}, {0}, {0}, 1, false);
	}
	if (rule == 89) {
		return lr_pack(values, {0}, {0}, {0}, 1, false);
	}
	if (rule == 90) {
		return lr_pack(values, {0}, {0}, {0}, 1, false);
	}
	if (rule == 91) {
		return lr_pack(values, {0}, {0}, {0}, 1, false);
	}
	if (rule == 92) {
		return lr_pack(values, {0}, {0}, {0}, 1, false);
	}
	if (rule == 93) {
		return lr_pack(values, {}, {}, {}, 1, true);
	}
	if (rule == 94) {
		return lr_pack(values, {0, 1}, {0, 0}, {0, 1}, 1, true);
	}
	if (rule == 95) {
		Types::modules::ispa_dep_scanner::member result;
		lr_capture_assign(result.value, values, 0, static_cast<std::size_t>(-1));
		return lr_node<Types::modules::ispa_dep_scanner::member>(result);
	}
	if (rule == 96) {
		Types::modules::ispa_dep_scanner::member result;
		lr_capture_assign(result.value, values, 0, static_cast<std::size_t>(-1));
		return lr_node<Types::modules::ispa_dep_scanner::member>(result);
	}
	if (rule == 97) {
		Types::modules::ispa_dep_scanner::member result;
		lr_capture_assign(result.value, values, 0, static_cast<std::size_t>(-1));
		return lr_node<Types::modules::ispa_dep_scanner::member>(result);
	}
	if (rule == 98) {
		Types::modules::ispa_dep_scanner::member result;
		lr_capture_assign(result.value, values, 0, static_cast<std::size_t>(-1));
		return lr_node<Types::modules::ispa_dep_scanner::member>(result);
	}
	if (rule == 99) {
		Types::modules::ispa_dep_scanner::mod_detach result;
		lr_capture_assign(result.begin, values, 0, static_cast<std::size_t>(-1));
		lr_capture_assign(result.value, values, 1, static_cast<std::size_t>(-1));
		lr_capture_assign(result.end, values, 2, static_cast<std::size_t>(-1));
		return lr_node<Types::modules::ispa_dep_scanner::mod_detach>(result);
	}
	if (rule == 100) {
		Types::modules::ispa_dep_scanner::mod_detach::detach_value result;
		lr_capture_assign(result.value, values, 0, static_cast<std::size_t>(-1));
		return lr_node<Types::modules::ispa_dep_scanner::mod_detach::detach_value>(result);
	}
	if (rule == 101) {
		Types::modules::ispa_dep_scanner::mod_detach::detach_value result;
		lr_capture_assign(result.value, values, 0, static_cast<std::size_t>(-1));
		return lr_node<Types::modules::ispa_dep_scanner::mod_detach::detach_value>(result);
	}
	if (rule == 102) {
		Types::modules::ispa_dep_scanner::mod_detach::detach_value::feature result;
		lr_capture_assign(result.value, values, 1, static_cast<std::size_t>(-1));
		return lr_node<Types::modules::ispa_dep_scanner::mod_detach::detach_value::feature>(result);
	}
	if (rule == 103) {
		Types::modules::ispa_dep_scanner::mod_import result;
		lr_capture_assign(result.begin, values, 0, static_cast<std::size_t>(-1));
		lr_capture_assign(result.value, values, 1, static_cast<std::size_t>(-1));
		lr_capture_assign(result.end, values, 2, static_cast<std::size_t>(-1));
		return lr_node<Types::modules::ispa_dep_scanner::mod_import>(result);
	}
	if (rule == 104) {
		Types::modules::ispa_dep_scanner::mod_import::import_value result;
		lr_capture_assign(result.value, values, 0, static_cast<std::size_t>(-1));
		return lr_node<Types::modules::ispa_dep_scanner::mod_import::import_value>(result);
	}
	if (rule == 105) {
		Types::modules::ispa_dep_scanner::mod_import::import_value result;
		lr_capture_assign(result.value, values, 0, static_cast<std::size_t>(-1));
		return lr_node<Types::modules::ispa_dep_scanner::mod_import::import_value>(result);
	}
	if (rule == 106) {
		Types::modules::ispa_dep_scanner::mod_import::import_value::from_import result;
		lr_capture_assign(result.sel, values, 0, static_cast<std::size_t>(-1));
		lr_capture_assign(result.source, values, 2, static_cast<std::size_t>(-1));
		return lr_node<Types::modules::ispa_dep_scanner::mod_import::import_value::from_import>(result);
	}
	if (rule == 107) {
		Types::modules::ispa_dep_scanner::mod_import::import_value::from_import::selection result;
		lr_capture_assign(result.value, values, 0, static_cast<std::size_t>(-1));
		return lr_node<Types::modules::ispa_dep_scanner::mod_import::import_value::from_import::selection>(result);
	}
	if (rule == 108) {
		Types::modules::ispa_dep_scanner::mod_import::import_value::from_import::selection result;
		lr_capture_assign(result.value, values, 0, static_cast<std::size_t>(-1));
		return lr_node<Types::modules::ispa_dep_scanner::mod_import::import_value::from_import::selection>(result);
	}
	if (rule == 109) {
		Types::modules::ispa_dep_scanner::mod_import::import_value::from_import::selection::items result;
		lr_capture_assign(result.first, values, 1, static_cast<std::size_t>(-1));
		lr_capture_assign(result.sequence, values, 2, static_cast<std::size_t>(0));
		return lr_node<Types::modules::ispa_dep_scanner::mod_import::import_value::from_import::selection::items>(result);
	}
	if (rule == 110) {
		return lr_pack(values, {}, {}, {}, 1, true);
	}
	if (rule == 111) {
		return lr_pack(values, {1, 2}, {0, 0}, {0, 1}, 1, true);
	}
	if (rule == 112) {
		return lr_pack(values, {}, {}, {}, 1, true);
	}
	if (rule == 113) {
		return lr_pack(values, {1, 2}, {0, 0}, {0, 1}, 1, true);
	}
	if (rule == 114) {
		Types::modules::ispa_dep_scanner::mod_import::import_value::module_import result;
		lr_capture_assign(result.source, values, 0, static_cast<std::size_t>(-1));
		lr_capture_assign(result.alias, values, 1, static_cast<std::size_t>(0));
		return lr_node<Types::modules::ispa_dep_scanner::mod_import::import_value::module_import>(result);
	}
	if (rule == 115) {
		return lr_pack(values, {}, {}, {}, 1, false);
	}
	if (rule == 116) {
		return lr_pack(values, {1}, {0}, {0}, 1, false);
	}
	if (rule == 117) {
		Types::modules::ispa_dep_scanner::mod_module result;
		lr_capture_assign(result.begin, values, 0, static_cast<std::size_t>(-1));
		lr_capture_assign(result.name, values, 1, static_cast<std::size_t>(-1));
		lr_capture_assign(result.parameters, values, 2, static_cast<std::size_t>(-1));
		lr_capture_assign(result.entry, values, 3, static_cast<std::size_t>(0));
		lr_capture_assign(result.end, values, 4, static_cast<std::size_t>(-1));
		return lr_node<Types::modules::ispa_dep_scanner::mod_module>(result);
	}
	if (rule == 118) {
		return lr_pack(values, {}, {}, {}, 1, false);
	}
	if (rule == 119) {
		return lr_pack(values, {1}, {0}, {0}, 1, false);
	}
	if (rule == 120) {
		return lr_pack(values, {}, {}, {}, 1, false);
	}
	if (rule == 121) {
		return lr_pack(values, {0}, {0}, {0}, 1, false);
	}
	if (rule == 122) {
		Types::modules::ispa_dep_scanner::modifier result;
		return lr_node<Types::modules::ispa_dep_scanner::modifier>(result);
	}
	if (rule == 123) {
		Types::modules::ispa_dep_scanner::module_path result;
		lr_capture_assign(result.primary, values, 0, static_cast<std::size_t>(-1));
		lr_capture_assign(result.nested, values, 1, static_cast<std::size_t>(0));
		return lr_node<Types::modules::ispa_dep_scanner::module_path>(result);
	}
	if (rule == 124) {
		return lr_pack(values, {}, {}, {}, 1, true);
	}
	if (rule == 125) {
		return lr_pack(values, {1, 2}, {0, 0}, {0, 1}, 1, true);
	}
	if (rule == 126) {
		return lr_pack(values, {}, {}, {}, 1, true);
	}
	if (rule == 127) {
		return lr_pack(values, {1, 2}, {0, 0}, {0, 1}, 1, true);
	}
	if (rule == 128) {
		Types::modules::ispa_dep_scanner::nested_rule result;
		lr_capture_assign(result.value, values, 1, static_cast<std::size_t>(-1));
		return lr_node<Types::modules::ispa_dep_scanner::nested_rule>(result);
	}
	if (rule == 129) {
		Types::modules::ispa_dep_scanner::parentheses result;
		return lr_node<Types::modules::ispa_dep_scanner::parentheses>(result);
	}
	if (rule == 130) {
		return lr_pack(values, {}, {}, {}, 1, true);
	}
	if (rule == 131) {
		return lr_pack(values, {0, 1}, {0, 0}, {0, 1}, 1, true);
	}
	if (rule == 132) {
		return lr_pack(values, {}, {}, {}, 1, true);
	}
	if (rule == 133) {
		return lr_pack(values, {0, 1}, {0, 0}, {0, 1}, 1, true);
	}
	if (rule == 134) {
		Types::modules::ispa_dep_scanner::source_name result;
		lr_capture_assign(result.value, values, 0, static_cast<std::size_t>(-1));
		return lr_node<Types::modules::ispa_dep_scanner::source_name>(result);
	}
	if (rule == 135) {
		Types::modules::ispa_dep_scanner::source_name result;
		lr_capture_assign(result.value, values, 0, static_cast<std::size_t>(-1));
		return lr_node<Types::modules::ispa_dep_scanner::source_name>(result);
	}
	if (rule == 136) {
		Types::modules::ispa_dep_scanner::symbol_list result;
		lr_capture_assign(result.first, values, 0, static_cast<std::size_t>(-1));
		lr_capture_assign(result.following, values, 1, static_cast<std::size_t>(0));
		return lr_node<Types::modules::ispa_dep_scanner::symbol_list>(result);
	}
	if (rule == 137) {
		return lr_pack(values, {}, {}, {}, 1, true);
	}
	if (rule == 138) {
		return lr_pack(values, {1, 2}, {0, 0}, {0, 1}, 1, true);
	}
	if (rule == 139) {
		return lr_pack(values, {}, {}, {}, 1, true);
	}
	if (rule == 140) {
		return lr_pack(values, {1, 2}, {0, 0}, {0, 1}, 1, true);
	}
	throw std::runtime_error("Invalid LR table entry or unexpected token");
}
auto DepParser::Parser::lr_shift(const Token& token) -> std::any {
	if (token.kind() == Tokens::__WS::id) {
		return lr_token(token.template to_node<Types::__WS>());
	}
	if (token.kind() == Tokens::LESS_THAN_SIGN::id) {
		return lr_token(token.template to_node<Types::LESS_THAN_SIGN>());
	}
	if (token.kind() == Tokens::AUTO::id) {
		return lr_token(token.template to_node<Types::AUTO>());
	}
	if (token.kind() == Tokens::modules::ispa_dep_scanner::LBRACE::id) {
		return lr_token(token.template to_node<Types::modules::ispa_dep_scanner::LBRACE>());
	}
	if (token.kind() == Tokens::modules::ispa_dep_scanner::HASH::id) {
		return lr_token(token.template to_node<Types::modules::ispa_dep_scanner::HASH>());
	}
	if (token.kind() == Tokens::modules::ispa_dep_scanner::ALL::id) {
		return lr_token(token.template to_node<Types::modules::ispa_dep_scanner::ALL>());
	}
	if (token.kind() == Tokens::modules::ispa_dep_scanner::COLON::id) {
		return lr_token(token.template to_node<Types::modules::ispa_dep_scanner::COLON>());
	}
	if (token.kind() == Tokens::modules::ispa_dep_scanner::DOT::id) {
		return lr_token(token.template to_node<Types::modules::ispa_dep_scanner::DOT>());
	}
	if (token.kind() == Tokens::modules::ispa_dep_scanner::FAIL::id) {
		return lr_token(token.template to_node<Types::modules::ispa_dep_scanner::FAIL>());
	}
	if (token.kind() == Tokens::modules::ispa_dep_scanner::FROM::id) {
		return lr_token(token.template to_node<Types::modules::ispa_dep_scanner::FROM>());
	}
	if (token.kind() == Tokens::modules::ispa_dep_scanner::RBRACE::id) {
		return lr_token(token.template to_node<Types::modules::ispa_dep_scanner::RBRACE>());
	}
	if (token.kind() == Tokens::modules::ispa_dep_scanner::FEATURE::id) {
		return lr_token(token.template to_node<Types::modules::ispa_dep_scanner::FEATURE>());
	}
	if (token.kind() == Tokens::modules::ispa_dep_scanner::DETACH::id) {
		return lr_token(token.template to_node<Types::modules::ispa_dep_scanner::DETACH>());
	}
	if (token.kind() == Tokens::modules::ispa_dep_scanner::IMPORT::id) {
		return lr_token(token.template to_node<Types::modules::ispa_dep_scanner::IMPORT>());
	}
	if (token.kind() == Tokens::modules::ispa_dep_scanner::SEMI::id) {
		return lr_token(token.template to_node<Types::modules::ispa_dep_scanner::SEMI>());
	}
	if (token.kind() == Tokens::modules::ispa_dep_scanner::COMMENT::id) {
		return lr_token(token.template to_node<Types::modules::ispa_dep_scanner::COMMENT>());
	}
	if (token.kind() == Tokens::modules::common::PY_RAW::id) {
		return lr_token(token.template to_node<Types::modules::common::PY_RAW>());
	}
	if (token.kind() == Tokens::modules::ispa_dep_scanner::MODULE::id) {
		return lr_token(token.template to_node<Types::modules::ispa_dep_scanner::MODULE>());
	}
	if (token.kind() == Tokens::modules::ispa_dep_scanner::STRING::id) {
		return lr_token(token.template to_node<Types::modules::ispa_dep_scanner::STRING>());
	}
	if (token.kind() == Tokens::GREATER_THAN_SIGN::id) {
		return lr_token(token.template to_node<Types::GREATER_THAN_SIGN>());
	}
	if (token.kind() == Tokens::modules::ispa_dep_scanner::CGROUP::id) {
		return lr_token(token.template to_node<Types::modules::ispa_dep_scanner::CGROUP>());
	}
	if (token.kind() == Tokens::modules::common::ID::id) {
		return lr_token(token.template to_node<Types::modules::common::ID>());
	}
	if (token.kind() == Tokens::modules::ispa_dep_scanner::AS::id) {
		return lr_token(token.template to_node<Types::modules::ispa_dep_scanner::AS>());
	}
	if (token.kind() == Tokens::modules::ispa_dep_scanner::OTHER::id) {
		return lr_token(token.template to_node<Types::modules::ispa_dep_scanner::OTHER>());
	}
	if (token.kind() == Tokens::RIGHT_PARENTHESIS::id) {
		return lr_token(token.template to_node<Types::RIGHT_PARENTHESIS>());
	}
	if (token.kind() == Tokens::LEFT_PARENTHESIS::id) {
		return lr_token(token.template to_node<Types::LEFT_PARENTHESIS>());
	}
	if (token.kind() == Tokens::COMMA::id) {
		return lr_token(token.template to_node<Types::COMMA>());
	}
	if (token.kind() == Tokens::modules::common::NUMBER::id) {
		return lr_token(token.template to_node<Types::modules::common::NUMBER>());
	}
	throw std::runtime_error("Invalid LR table entry or unexpected token");
}
template<typename IT, class> auto DepParser::Parser::main(IT pos) -> ::ISPA_STD::MatchResult<Types::main, IT> {
	return lr_parse_generalized<Parser>(pos);
}
template auto DepParser::Parser::main<::DepParser::Lexer::iterator>(::DepParser::Lexer::iterator pos) -> ::ISPA_STD::MatchResult<Types::main, ::DepParser::Lexer::iterator>;
template auto DepParser::Parser::main<::DepParser::Lexer::lazy_iterator>(::DepParser::Lexer::lazy_iterator pos) -> ::ISPA_STD::MatchResult<Types::main, ::DepParser::Lexer::lazy_iterator>;
auto DepParser::Parser::parseFromTokens() -> void {
	tree = main(Lexer::iterator(lexer)).node.data();
}
auto DepParser::Parser::lazyParse() -> void {
	Lexer lexer;
	tree = main(Lexer::lazy_iterator(lexer, text)).node.data();
}
