#include "DepParser.h"

#include <ispastdlib/to_string.hpp>
#include <ispastdlib/lexer.hpp>

auto DepParser::TokensToString(std::size_t id) -> const char* {
	switch (id) {
		case Tokens::__WS::id: {
			return TokensStr::__WS::id;
			break;
		}
		case Tokens::modules::ispa_dep_scanner::mod_module::MODULE::id: {
			return TokensStr::modules::ispa_dep_scanner::mod_module::MODULE::id;
			break;
		}
		case Tokens::modules::ispa_dep_scanner::mod_detach::DETACH::id: {
			return TokensStr::modules::ispa_dep_scanner::mod_detach::DETACH::id;
			break;
		}
		case Tokens::modules::ispa_dep_scanner::mod_import::import_value::from_import::FROM::id: {
			return TokensStr::modules::ispa_dep_scanner::mod_import::import_value::from_import::FROM::id;
			break;
		}
		case Tokens::AS::id: {
			return TokensStr::AS::id;
			break;
		}
		case Tokens::modules::ispa_dep_scanner::mod_python_import::PY::id: {
			return TokensStr::modules::ispa_dep_scanner::mod_python_import::PY::id;
			break;
		}
		case Tokens::IMPORT::id: {
			return TokensStr::IMPORT::id;
			break;
		}
		case Tokens::RIGHT_CURLY_BRACKET::id: {
			return TokensStr::RIGHT_CURLY_BRACKET::id;
			break;
		}
		case Tokens::modules::ispa_dep_scanner::fail_decl::FAIL::id: {
			return TokensStr::modules::ispa_dep_scanner::fail_decl::FAIL::id;
			break;
		}
		case Tokens::LEFT_CURLY_BRACKET::id: {
			return TokensStr::LEFT_CURLY_BRACKET::id;
			break;
		}
		case Tokens::ASTERISK::id: {
			return TokensStr::ASTERISK::id;
			break;
		}
		case Tokens::COLON::id: {
			return TokensStr::COLON::id;
			break;
		}
		case Tokens::GREATER_THAN_SIGN::id: {
			return TokensStr::GREATER_THAN_SIGN::id;
			break;
		}
		case Tokens::FULL_STOP::id: {
			return TokensStr::FULL_STOP::id;
			break;
		}
		case Tokens::AUTO::id: {
			return TokensStr::AUTO::id;
			break;
		}
		case Tokens::modules::scanner_tokens::OTHER::id: {
			return TokensStr::modules::scanner_tokens::OTHER::id;
			break;
		}
		case Tokens::modules::scanner_tokens::PY_RAW::id: {
			return TokensStr::modules::scanner_tokens::PY_RAW::id;
			break;
		}
		case Tokens::NUMBER_SIGN::id: {
			return TokensStr::NUMBER_SIGN::id;
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
		case Tokens::modules::common::ID::id: {
			return TokensStr::modules::common::ID::id;
			break;
		}
		case Tokens::LESS_THAN_SIGN::id: {
			return TokensStr::LESS_THAN_SIGN::id;
			break;
		}
		case Tokens::modules::scanner_tokens::STRING::id: {
			return TokensStr::modules::scanner_tokens::STRING::id;
			break;
		}
		case Tokens::SEMICOLON::id: {
			return TokensStr::SEMICOLON::id;
			break;
		}
		case Tokens::modules::scanner_tokens::COMMENT::id: {
			return TokensStr::modules::scanner_tokens::COMMENT::id;
			break;
		}
		case Tokens::FEATURE::id: {
			return TokensStr::FEATURE::id;
			break;
		}
		case Tokens::modules::ispa_dep_scanner::mod_import::external_import::EXTERN::id: {
			return TokensStr::modules::ispa_dep_scanner::mod_import::external_import::EXTERN::id;
			break;
		}
		case Tokens::modules::scanner_tokens::CGROUP::id: {
			return TokensStr::modules::scanner_tokens::CGROUP::id;
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
		case Rules::modules::entry::main::id: {
			return RulesStr::modules::entry::main::id;
			break;
		}
		case Rules::modules::entry::main::__grp0::id: {
			return RulesStr::modules::entry::main::__grp0::id;
			break;
		}
		case Rules::modules::entry::main::__grp0::__rop0::id: {
			return RulesStr::modules::entry::main::__grp0::__rop0::id;
			break;
		}
		case Rules::modules::entry::main::__grp0::__tail::id: {
			return RulesStr::modules::entry::main::__grp0::__tail::id;
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
		case Rules::modules::ispa_dep_scanner::declaration::form::id: {
			return RulesStr::modules::ispa_dep_scanner::declaration::form::id;
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
		case Rules::modules::ispa_dep_scanner::mod_detach::detach_value::feature_ref::id: {
			return RulesStr::modules::ispa_dep_scanner::mod_detach::detach_value::feature_ref::id;
			break;
		}
		case Rules::modules::ispa_dep_scanner::mod_import::id: {
			return RulesStr::modules::ispa_dep_scanner::mod_import::id;
			break;
		}
		case Rules::modules::ispa_dep_scanner::mod_import::__q2::id: {
			return RulesStr::modules::ispa_dep_scanner::mod_import::__q2::id;
			break;
		}
		case Rules::modules::ispa_dep_scanner::mod_import::external_import::id: {
			return RulesStr::modules::ispa_dep_scanner::mod_import::external_import::id;
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
		case Rules::modules::ispa_dep_scanner::mod_python_import::id: {
			return RulesStr::modules::ispa_dep_scanner::mod_python_import::id;
			break;
		}
		case Rules::modules::ispa_dep_scanner::mod_python_import::__grp6::id: {
			return RulesStr::modules::ispa_dep_scanner::mod_python_import::__grp6::id;
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
auto DepParser::FlatTypes::modules_ispa_dep_scanner_mod_module_MODULE::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_ispa_dep_scanner_mod_module_MODULE", true);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_mod_module_MODULE::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_mod_module_MODULE::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_ispa_dep_scanner_mod_module_MODULE {", "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_ispa_dep_scanner_mod_module_MODULE value) -> std::ostream & {
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
auto DepParser::FlatTypes::modules_ispa_dep_scanner_mod_detach_DETACH::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_ispa_dep_scanner_mod_detach_DETACH", true);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_mod_detach_DETACH::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_mod_detach_DETACH::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_ispa_dep_scanner_mod_detach_DETACH {", "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_ispa_dep_scanner_mod_detach_DETACH value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_mod_import_import_value_from_import_FROM::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_ispa_dep_scanner_mod_import_import_value_from_import_FROM", true);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_mod_import_import_value_from_import_FROM::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_mod_import_import_value_from_import_FROM::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_ispa_dep_scanner_mod_import_import_value_from_import_FROM {", "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_ispa_dep_scanner_mod_import_import_value_from_import_FROM value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::AS::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("AS", true);
}
auto DepParser::FlatTypes::AS::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::AS::to_string() const -> std::string {
	return ::ISPA_STD::concat("AS {", "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, AS value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_mod_python_import_PY::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_ispa_dep_scanner_mod_python_import_PY", true);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_mod_python_import_PY::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_mod_python_import_PY::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_ispa_dep_scanner_mod_python_import_PY {", "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_ispa_dep_scanner_mod_python_import_PY value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::IMPORT::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("IMPORT", true);
}
auto DepParser::FlatTypes::IMPORT::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::IMPORT::to_string() const -> std::string {
	return ::ISPA_STD::concat("IMPORT {", "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, IMPORT value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::RIGHT_CURLY_BRACKET::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("RIGHT_CURLY_BRACKET", true);
}
auto DepParser::FlatTypes::RIGHT_CURLY_BRACKET::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::RIGHT_CURLY_BRACKET::to_string() const -> std::string {
	return ::ISPA_STD::concat("RIGHT_CURLY_BRACKET {", "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, RIGHT_CURLY_BRACKET value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_fail_decl_FAIL::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_ispa_dep_scanner_fail_decl_FAIL", true);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_fail_decl_FAIL::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_fail_decl_FAIL::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_ispa_dep_scanner_fail_decl_FAIL {", "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_ispa_dep_scanner_fail_decl_FAIL value) -> std::ostream & {
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
auto DepParser::FlatTypes::LEFT_CURLY_BRACKET::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("LEFT_CURLY_BRACKET", true);
}
auto DepParser::FlatTypes::LEFT_CURLY_BRACKET::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::LEFT_CURLY_BRACKET::to_string() const -> std::string {
	return ::ISPA_STD::concat("LEFT_CURLY_BRACKET {", "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, LEFT_CURLY_BRACKET value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::ASTERISK::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("ASTERISK", true);
}
auto DepParser::FlatTypes::ASTERISK::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::ASTERISK::to_string() const -> std::string {
	return ::ISPA_STD::concat("ASTERISK {", "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, ASTERISK value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::COLON::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("COLON", true);
}
auto DepParser::FlatTypes::COLON::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::COLON::to_string() const -> std::string {
	return ::ISPA_STD::concat("COLON {", "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, COLON value) -> std::ostream & {
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
auto DepParser::FlatTypes::FULL_STOP::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("FULL_STOP", true);
}
auto DepParser::FlatTypes::FULL_STOP::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::FULL_STOP::to_string() const -> std::string {
	return ::ISPA_STD::concat("FULL_STOP {", "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, FULL_STOP value) -> std::ostream & {
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
auto DepParser::FlatTypes::modules_scanner_tokens_OTHER::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_scanner_tokens_OTHER", false);
	printer.up(false);
	printer.node_with_value("value", value, true);
	printer.down();
}
auto DepParser::FlatTypes::modules_scanner_tokens_OTHER::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_scanner_tokens_OTHER::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_scanner_tokens_OTHER {", "value = ", value, "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_scanner_tokens_OTHER value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::modules_scanner_tokens::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_scanner_tokens", true);
}
auto DepParser::FlatTypes::modules_scanner_tokens::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_scanner_tokens::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_scanner_tokens {", "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_scanner_tokens value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::modules_scanner_tokens_PY_RAW::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_scanner_tokens_PY_RAW", false);
	printer.up(false);
	printer.node_with_value("value", value, true);
	printer.down();
}
auto DepParser::FlatTypes::modules_scanner_tokens_PY_RAW::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_scanner_tokens_PY_RAW::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_scanner_tokens_PY_RAW {", "value = ", value, "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_scanner_tokens_PY_RAW value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::NUMBER_SIGN::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("NUMBER_SIGN", true);
}
auto DepParser::FlatTypes::NUMBER_SIGN::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::NUMBER_SIGN::to_string() const -> std::string {
	return ::ISPA_STD::concat("NUMBER_SIGN {", "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, NUMBER_SIGN value) -> std::ostream & {
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
auto DepParser::FlatTypes::modules_scanner_tokens_STRING::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_scanner_tokens_STRING", false);
	printer.up(false);
	printer.node_with_value("value", value, true);
	printer.down();
}
auto DepParser::FlatTypes::modules_scanner_tokens_STRING::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_scanner_tokens_STRING::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_scanner_tokens_STRING {", "value = ", value, "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_scanner_tokens_STRING value) -> std::ostream & {
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
auto DepParser::FlatTypes::modules_scanner_tokens_COMMENT::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_scanner_tokens_COMMENT", false);
	printer.up(false);
	printer.node_with_value("value", value, true);
	printer.down();
}
auto DepParser::FlatTypes::modules_scanner_tokens_COMMENT::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_scanner_tokens_COMMENT::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_scanner_tokens_COMMENT {", "value = ", value, "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_scanner_tokens_COMMENT value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::FEATURE::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("FEATURE", true);
}
auto DepParser::FlatTypes::FEATURE::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::FEATURE::to_string() const -> std::string {
	return ::ISPA_STD::concat("FEATURE {", "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, FEATURE value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_mod_import_external_import_EXTERN::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_ispa_dep_scanner_mod_import_external_import_EXTERN", true);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_mod_import_external_import_EXTERN::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_mod_import_external_import_EXTERN::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_ispa_dep_scanner_mod_import_external_import_EXTERN {", "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_ispa_dep_scanner_mod_import_external_import_EXTERN value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::modules_scanner_tokens_CGROUP::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_scanner_tokens_CGROUP", false);
	printer.up(false);
	printer.node_with_value("value", value, true);
	printer.down();
}
auto DepParser::FlatTypes::modules_scanner_tokens_CGROUP::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_scanner_tokens_CGROUP::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_scanner_tokens_CGROUP {", "value = ", value, "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_scanner_tokens_CGROUP value) -> std::ostream & {
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
auto DepParser::FlatTypes::modules_entry::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_entry", true);
}
auto DepParser::FlatTypes::modules_entry::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_entry::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_entry {", "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_entry value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::modules_entry_main___grp0::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_entry_main___grp0", true);
}
auto DepParser::FlatTypes::modules_entry_main___grp0::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_entry_main___grp0::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_entry_main___grp0 {", "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_entry_main___grp0 value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::modules_entry_main___grp0___rop0::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_entry_main___grp0___rop0", true);
}
auto DepParser::FlatTypes::modules_entry_main___grp0___rop0::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_entry_main___grp0___rop0::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_entry_main___grp0___rop0 {", "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_entry_main___grp0___rop0 value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::modules_entry_main___grp0___tail::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_entry_main___grp0___tail", true);
}
auto DepParser::FlatTypes::modules_entry_main___grp0___tail::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_entry_main___grp0___tail::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_entry_main___grp0___tail {", "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_entry_main___grp0___tail value) -> std::ostream & {
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
auto DepParser::FlatTypes::modules_ispa_dep_scanner_mod_import___q2::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_ispa_dep_scanner_mod_import___q2", true);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_mod_import___q2::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_mod_import___q2::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_ispa_dep_scanner_mod_import___q2 {", "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_ispa_dep_scanner_mod_import___q2 value) -> std::ostream & {
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
auto DepParser::FlatTypes::modules_ispa_dep_scanner_mod_python_import___grp6::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_ispa_dep_scanner_mod_python_import___grp6", true);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_mod_python_import___grp6::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_mod_python_import___grp6::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_ispa_dep_scanner_mod_python_import___grp6 {", "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_ispa_dep_scanner_mod_python_import___grp6 value) -> std::ostream & {
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
auto DepParser::FlatTypes::modules_ispa_dep_scanner_mod_import_external_import::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_ispa_dep_scanner_mod_import_external_import", false);
	printer.up(false);
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_mod_import_external_import::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_mod_import_external_import::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_ispa_dep_scanner_mod_import_external_import {", "value = ", value.to_string(), "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_ispa_dep_scanner_mod_import_external_import value) -> std::ostream & {
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
auto DepParser::FlatTypes::modules_ispa_dep_scanner_declaration::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_ispa_dep_scanner_declaration", false);
	printer.up(false);
	printer.subtree("modifiers", modifiers, false);
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_declaration::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_declaration::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_ispa_dep_scanner_declaration {", "modifiers = ", modifiers, ", ", "value = ", value.to_string(), "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_ispa_dep_scanner_declaration value) -> std::ostream & {
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
auto DepParser::FlatTypes::modules_ispa_dep_scanner_mod_python_import::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_ispa_dep_scanner_mod_python_import", false);
	printer.up(false);
	printer.node("begin", false);
	printer.up(true);
	begin.print(printer);
	printer.down();
	printer.node("source", false);
	printer.up(true);
	source.print(printer);
	printer.down();
	printer.node("alias", false);
	printer.up(true);
	alias.print(printer);
	printer.down();
	printer.node("end", true);
	printer.up(false);
	end.print(printer);
	printer.down();
	printer.down();
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_mod_python_import::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_mod_python_import::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_ispa_dep_scanner_mod_python_import {", "begin = ", begin.to_string(), ", ", "source = ", source.to_string(), ", ", "alias = ", alias.to_string(), ", ", "end = ", end.to_string(), "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_ispa_dep_scanner_mod_python_import value) -> std::ostream & {
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
auto DepParser::FlatTypes::modules_ispa_dep_scanner_declaration_form::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_ispa_dep_scanner_declaration_form", false);
	printer.up(false);
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
auto DepParser::FlatTypes::modules_ispa_dep_scanner_declaration_form::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_declaration_form::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_ispa_dep_scanner_declaration_form {", "name = ", name.to_string(), ", ", "body = ", body.to_string(), "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_ispa_dep_scanner_declaration_form value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_source_name::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_ispa_dep_scanner_source_name", false);
	printer.up(false);
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_source_name::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_source_name::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_ispa_dep_scanner_source_name {", "value = ", value.to_string(), "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_ispa_dep_scanner_source_name value) -> std::ostream & {
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
auto DepParser::FlatTypes::modules_ispa_dep_scanner_mod_detach_detach_value_feature_ref::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_ispa_dep_scanner_mod_detach_detach_value_feature_ref", false);
	printer.up(false);
	printer.node("value", true);
	printer.up(false);
	value.print(printer);
	printer.down();
	printer.down();
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_mod_detach_detach_value_feature_ref::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_ispa_dep_scanner_mod_detach_detach_value_feature_ref::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_ispa_dep_scanner_mod_detach_detach_value_feature_ref {", "value = ", value.to_string(), "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_ispa_dep_scanner_mod_detach_detach_value_feature_ref value) -> std::ostream & {
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
	printer.node("external", false);
	printer.up(true);
	external.print(printer);
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
	return ::ISPA_STD::concat("modules_ispa_dep_scanner_mod_import {", "begin = ", begin.to_string(), ", ", "external = ", external.to_string(), ", ", "value = ", value.to_string(), ", ", "end = ", end.to_string(), "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_ispa_dep_scanner_mod_import value) -> std::ostream & {
	value.print(os);
	return os;
}
auto DepParser::FlatTypes::modules_entry_main::write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void {
	printer.node("modules_entry_main", false);
	printer.up(false);
	printer.node_with_value("value", value, true);
	printer.down();
}
auto DepParser::FlatTypes::modules_entry_main::print(std::ostream& os) const -> void {
	::ISPA_STD::ASTPrinter<std::ostream> printer = ::ISPA_STD::ASTPrinter<std::ostream>{os};
	write_to_output(printer);
}
auto DepParser::FlatTypes::modules_entry_main::to_string() const -> std::string {
	return ::ISPA_STD::concat("modules_entry_main {", "value = ", value, "}");
}
auto DepParser::FlatTypes::operator<<(std::ostream & os, modules_entry_main value) -> std::ostream & {
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
auto DepParser::Lexer::clone() const -> std::shared_ptr<::ISPA_STD::Lexer_base<Token>> {
	return std::make_shared<Lexer>(*this);
}
auto DepParser::Lexer::semantic_action_exec(long long state, const ::ISPA_STD::DFA::API::Captures& captures, long long start_pos, const char* start, long long length, long long line) -> std::pair<long long, Token> {
	switch (state) {
		case 0: {
			char value = captures.character(5);
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::modules::scanner_tokens::OTHER::id, Types::modules::scanner_tokens::OTHER{value}));
			break;
		}
		case 1: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::__WS::id, Types::__WS{}));
			break;
		}
		case 2: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::NUMBER_SIGN::id, Types::NUMBER_SIGN{}));
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
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::ASTERISK::id, Types::ASTERISK{}));
			break;
		}
		case 6: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::COMMA::id, Types::COMMA{}));
			break;
		}
		case 7: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::FULL_STOP::id, Types::FULL_STOP{}));
			break;
		}
		case 8: {
			std::string floating = captures.text(7);
			std::string full = captures.text(6);
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::modules::common::NUMBER::id, Types::modules::common::NUMBER{full, floating}));
			break;
		}
		case 9: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::COLON::id, Types::COLON{}));
			break;
		}
		case 10: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::SEMICOLON::id, Types::SEMICOLON{}));
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
			std::string value = captures.text(9);
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::modules::common::ID::id, Types::modules::common::ID{value}));
			break;
		}
		case 14: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::LEFT_CURLY_BRACKET::id, Types::LEFT_CURLY_BRACKET{}));
			break;
		}
		case 15: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::RIGHT_CURLY_BRACKET::id, Types::RIGHT_CURLY_BRACKET{}));
			break;
		}
		case 16: {
			std::string value = captures.text(3);
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::modules::scanner_tokens::STRING::id, Types::modules::scanner_tokens::STRING{value}));
			break;
		}
		case 17: {
			std::string value = captures.text(3);
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::modules::scanner_tokens::STRING::id, Types::modules::scanner_tokens::STRING{value}));
			break;
		}
		case 18: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::AUTO::id, Types::AUTO{}));
			break;
		}
		case 19: {
			std::string value = captures.text(0);
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::modules::scanner_tokens::COMMENT::id, Types::modules::scanner_tokens::COMMENT{value}));
			break;
		}
		case 20: {
			std::string value = captures.text(9);
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::modules::common::ID::id, Types::modules::common::ID{value}));
			break;
		}
		case 21: {
			char value = captures.character(4);
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::modules::scanner_tokens::CGROUP::id, Types::modules::scanner_tokens::CGROUP{value}));
			break;
		}
		case 22: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::AS::id, Types::AS{}));
			break;
		}
		case 23: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::modules::ispa_dep_scanner::mod_python_import::PY::id, Types::modules::ispa_dep_scanner::mod_python_import::PY{}));
			break;
		}
		case 24: {
			std::string value = captures.text(0);
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::modules::scanner_tokens::COMMENT::id, Types::modules::scanner_tokens::COMMENT{value}));
			break;
		}
		case 25: {
			std::string floating = captures.text(7);
			std::string full = captures.text(6);
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::modules::common::NUMBER::id, Types::modules::common::NUMBER{full, floating}));
			break;
		}
		case 26: {
			std::string value = captures.text(8);
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::modules::scanner_tokens::PY_RAW::id, Types::modules::scanner_tokens::PY_RAW{value}));
			break;
		}
		case 27: {
			std::string value = captures.text(0);
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::modules::scanner_tokens::COMMENT::id, Types::modules::scanner_tokens::COMMENT{value}));
			break;
		}
		case 28: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::modules::ispa_dep_scanner::fail_decl::FAIL::id, Types::modules::ispa_dep_scanner::fail_decl::FAIL{}));
			break;
		}
		case 29: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::modules::ispa_dep_scanner::mod_import::import_value::from_import::FROM::id, Types::modules::ispa_dep_scanner::mod_import::import_value::from_import::FROM{}));
			break;
		}
		case 30: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::modules::ispa_dep_scanner::mod_detach::DETACH::id, Types::modules::ispa_dep_scanner::mod_detach::DETACH{}));
			break;
		}
		case 31: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::modules::ispa_dep_scanner::mod_import::external_import::EXTERN::id, Types::modules::ispa_dep_scanner::mod_import::external_import::EXTERN{}));
			break;
		}
		case 32: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::IMPORT::id, Types::IMPORT{}));
			break;
		}
		case 33: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::modules::ispa_dep_scanner::mod_module::MODULE::id, Types::modules::ispa_dep_scanner::mod_module::MODULE{}));
			break;
		}
		case 34: {
			return std::make_pair(::ISPA_STD::DFA::API::null_state, Token::create(start_pos, start, length, line, Tokens::FEATURE::id, Types::FEATURE{}));
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
::ISPA_STD::DFA::API::CharToClass DepParser::Lexer::char_class_table = {0, 1, 1, 1, 1, 1, 1, 1, 1, 2, 3, 2, 2, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 4, 5, 1, 1, 1, 6, 7, 8, 9, 1, 10, 11, 12, 13, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 15, 16, 17, 1, 18, 1, 1, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 20, 21, 22, 1, 19, 1, 23, 19, 24, 25, 26, 27, 19, 28, 29, 19, 19, 30, 31, 32, 33, 34, 19, 35, 36, 37, 38, 19, 19, 39, 40, 19, 41, 1, 42, 1, 1, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43};
::ISPA_STD::DFA::API::Table<82, 44> DepParser::Lexer::dfa_table = {{{::ISPA_STD::DFA::API::null_state, 82, 2, 2, 93, 4, 92, 6, 7, 8, 9, 91, 11, 90, 89, 14, 15, 16, 17, 83, 88, 82, ::ISPA_STD::DFA::API::null_state, 87, 83, 96, 94, 95, 83, 86, 83, 85, 83, 83, 84, 83, 83, 83, 83, 83, 83, 27, 28, ::ISPA_STD::DFA::API::null_state}, {97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97}, {189, 189, 2, 2, 189, 189, 189, 189, 189, 189, 189, 189, 189, 189, 189, 189, 189, 189, 189, 189, 189, 189, 189, 189, 189, 189, 189, 189, 189, 189, 189, 189, 189, 189, 189, 189, 189, 189, 189, 189, 189, 189, 189, 189}, {::ISPA_STD::DFA::API::null_state, 3, 3, 3, 29, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 30, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, ::ISPA_STD::DFA::API::null_state}, {190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190}, {::ISPA_STD::DFA::API::null_state, 5, 5, 5, 5, 5, 31, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 32, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, ::ISPA_STD::DFA::API::null_state}, {191, 191, 191, 191, 191, 191, 191, 191, 191, 191, 191, 191, 191, 191, 191, 191, 191, 191, 191, 191, 191, 191, 191, 191, 191, 191, 191, 191, 191, 191, 191, 191, 191, 191, 191, 191, 191, 191, 191, 191, 191, 191, 191, 191}, {192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192}, {193, 193, 193, 193, 193, 193, 193, 193, 193, 193, 193, 193, 193, 193, 193, 193, 193, 193, 193, 193, 193, 193, 193, 193, 193, 193, 193, 193, 193, 193, 193, 193, 193, 193, 193, 193, 193, 193, 193, 193, 193, 193, 193, 193}, {194, 194, 194, 194, 194, 194, 194, 194, 194, 194, 194, 194, 194, 194, 194, 194, 194, 194, 194, 194, 194, 194, 194, 194, 194, 194, 194, 194, 194, 194, 194, 194, 194, 194, 194, 194, 194, 194, 194, 194, 194, 194, 194, 194}, {99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 33, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99}, {195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195}, {101, 101, 101, 101, 101, 101, 101, 101, 101, 34, 101, 101, 101, 35, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101}, {102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 103, 102, 13, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102}, {197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197, 197}, {198, 198, 198, 198, 198, 198, 198, 198, 198, 198, 198, 198, 198, 198, 198, 198, 198, 198, 198, 198, 198, 198, 198, 198, 198, 198, 198, 198, 198, 198, 198, 198, 198, 198, 198, 198, 198, 198, 198, 198, 198, 198, 198, 198}, {199, 199, 199, 199, 199, 199, 199, 199, 199, 199, 199, 199, 199, 199, 199, 199, 199, 199, 199, 199, 199, 199, 199, 199, 199, 199, 199, 199, 199, 199, 199, 199, 199, 199, 199, 199, 199, 199, 199, 199, 199, 199, 199, 199}, {200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200}, {104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 37, 104, 104, 104, 104, 37, 104, 104, 104, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 104, 104, 104}, {::ISPA_STD::DFA::API::null_state, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 107, 106, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, ::ISPA_STD::DFA::API::null_state}, {109, 109, 109, 109, 109, 109, 109, 109, 109, 109, 109, 109, 109, 109, 110, 109, 109, 109, 109, 110, 109, 109, 109, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 41, 110, 110, 110, 110, 109, 109, 109}, {112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 110, 112, 112, 112, 112, 110, 112, 112, 112, 110, 110, 110, 42, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 112, 112, 112}, {114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 110, 114, 114, 114, 114, 110, 114, 114, 114, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 43, 110, 114, 114, 114}, {116, 116, 116, 116, 116, 116, 116, 116, 116, 116, 116, 116, 116, 116, 110, 116, 116, 116, 116, 110, 116, 116, 116, 44, 110, 110, 45, 110, 110, 110, 110, 110, 110, 110, 110, 46, 110, 110, 110, 110, 110, 116, 116, 116}, {118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 110, 118, 118, 118, 118, 110, 118, 118, 118, 110, 110, 110, 110, 110, 110, 110, 110, 47, 110, 110, 110, 110, 110, 110, 110, 110, 110, 118, 118, 118}, {120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 110, 120, 120, 120, 120, 110, 120, 120, 120, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 48, 110, 110, 110, 110, 110, 110, 110, 120, 120, 120}, {122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 110, 122, 122, 122, 122, 110, 122, 122, 122, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 49, 50, 122, 122}, {202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202}, {203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203}, {123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123}, {::ISPA_STD::DFA::API::null_state, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, ::ISPA_STD::DFA::API::null_state}, {124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124}, {::ISPA_STD::DFA::API::null_state, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, ::ISPA_STD::DFA::API::null_state}, {206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206}, {::ISPA_STD::DFA::API::null_state, 34, 34, 34, 34, 34, 34, 34, 34, 51, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, ::ISPA_STD::DFA::API::null_state}, {126, 52, 52, 126, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 126}, {::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, 127, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state, ::ISPA_STD::DFA::API::null_state}, {128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 37, 128, 128, 128, 128, 37, 128, 128, 128, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 128, 128, 128}, {::ISPA_STD::DFA::API::null_state, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 39, 40, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, ::ISPA_STD::DFA::API::null_state}, {::ISPA_STD::DFA::API::null_state, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, ::ISPA_STD::DFA::API::null_state}, {209, 209, 209, 209, 209, 209, 209, 209, 209, 209, 209, 209, 209, 209, 209, 209, 209, 209, 209, 209, 209, 209, 209, 209, 209, 209, 209, 209, 209, 209, 209, 209, 209, 209, 209, 209, 209, 209, 209, 209, 209, 209, 209, 209}, {210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 110, 210, 210, 210, 210, 110, 210, 210, 210, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 210, 210, 210}, {130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 110, 130, 130, 130, 130, 110, 130, 130, 130, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 54, 110, 110, 110, 130, 130, 130}, {132, 132, 132, 132, 132, 132, 132, 132, 132, 132, 132, 132, 132, 132, 110, 132, 132, 132, 132, 110, 132, 132, 132, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 55, 110, 110, 110, 132, 132, 132}, {134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 110, 134, 134, 134, 134, 110, 134, 134, 134, 110, 110, 110, 110, 110, 110, 56, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 134, 134, 134}, {136, 136, 136, 136, 136, 136, 136, 136, 136, 136, 136, 136, 136, 136, 110, 136, 136, 136, 136, 110, 136, 136, 136, 57, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 136, 136, 136}, {138, 138, 138, 138, 138, 138, 138, 138, 138, 138, 138, 138, 138, 138, 110, 138, 138, 138, 138, 110, 138, 138, 138, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 58, 110, 110, 110, 110, 110, 110, 110, 138, 138, 138}, {140, 140, 140, 140, 140, 140, 140, 140, 140, 140, 140, 140, 140, 140, 110, 140, 140, 140, 140, 110, 140, 140, 140, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 59, 110, 110, 110, 110, 110, 110, 140, 140, 140}, {142, 142, 142, 142, 142, 142, 142, 142, 142, 142, 142, 142, 142, 142, 110, 142, 142, 142, 142, 110, 142, 142, 142, 110, 110, 60, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 142, 142, 142}, {211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 110, 211, 211, 211, 211, 110, 211, 211, 211, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 211, 211, 211}, {143, 143, 143, 143, 143, 143, 143, 143, 143, 143, 143, 143, 143, 143, 143, 143, 143, 143, 143, 143, 143, 143, 143, 143, 143, 143, 143, 143, 143, 143, 143, 143, 143, 143, 143, 143, 143, 143, 143, 143, 143, 143, 144, ::ISPA_STD::DFA::API::null_state}, {::ISPA_STD::DFA::API::null_state, 34, 34, 34, 34, 34, 34, 34, 34, 51, 34, 34, 34, 63, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, ::ISPA_STD::DFA::API::null_state}, {146, 52, 52, 146, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 146}, {147, 147, 147, 147, 147, 147, 147, 147, 147, 147, 147, 147, 147, 147, 53, 147, 147, 147, 147, 147, 147, 147, 147, 147, 147, 147, 147, 147, 147, 147, 147, 147, 147, 147, 147, 147, 147, 147, 147, 147, 147, 147, 147, 147}, {149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 110, 149, 149, 149, 149, 110, 149, 149, 149, 64, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 149, 149, 149}, {151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 110, 151, 151, 151, 151, 110, 151, 151, 151, 110, 110, 110, 65, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 151, 151, 151}, {153, 153, 153, 153, 153, 153, 153, 153, 153, 153, 153, 153, 153, 153, 110, 153, 153, 153, 153, 110, 153, 153, 153, 110, 110, 110, 110, 110, 110, 110, 66, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 153, 153, 153}, {155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 110, 155, 155, 155, 155, 110, 155, 155, 155, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 67, 110, 110, 110, 155, 155, 155}, {157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 110, 157, 157, 157, 157, 110, 157, 157, 157, 110, 110, 110, 110, 110, 110, 110, 110, 68, 110, 110, 110, 110, 110, 110, 110, 110, 110, 157, 157, 157}, {159, 159, 159, 159, 159, 159, 159, 159, 159, 159, 159, 159, 159, 159, 110, 159, 159, 159, 159, 110, 159, 159, 159, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 69, 110, 110, 110, 110, 110, 110, 110, 159, 159, 159}, {161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 110, 161, 161, 161, 161, 110, 161, 161, 161, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 70, 110, 110, 161, 161, 161}, {61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 162, ::ISPA_STD::DFA::API::null_state}, {163, 163, 163, 163, 163, 163, 163, 163, 163, 163, 163, 163, 163, 163, 163, 163, 163, 163, 163, 163, 163, 163, 163, 163, 163, 163, 163, 163, 163, 163, 163, 163, 163, 163, 163, 163, 163, 163, 163, 163, 163, 163, 163, 163}, {165, 165, 165, 165, 165, 165, 165, 165, 165, 165, 165, 165, 165, 165, 165, 165, 165, 165, 165, 165, 165, 165, 165, 165, 165, 165, 165, 165, 165, 165, 165, 165, 165, 165, 165, 165, 165, 165, 165, 165, 165, 165, 165, 165}, {167, 167, 167, 167, 167, 167, 167, 167, 167, 167, 167, 167, 167, 167, 110, 167, 167, 167, 167, 110, 167, 167, 167, 110, 71, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 167, 167, 167}, {169, 169, 169, 169, 169, 169, 169, 169, 169, 169, 169, 169, 169, 169, 110, 169, 169, 169, 169, 110, 169, 169, 169, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 72, 110, 110, 110, 110, 110, 169, 169, 169}, {216, 216, 216, 216, 216, 216, 216, 216, 216, 216, 216, 216, 216, 216, 110, 216, 216, 216, 216, 110, 216, 216, 216, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 216, 216, 216}, {171, 171, 171, 171, 171, 171, 171, 171, 171, 171, 171, 171, 171, 171, 110, 171, 171, 171, 171, 110, 171, 171, 171, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 73, 110, 110, 171, 171, 171}, {217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 110, 217, 217, 217, 217, 110, 217, 217, 217, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 217, 217, 217}, {173, 173, 173, 173, 173, 173, 173, 173, 173, 173, 173, 173, 173, 173, 110, 173, 173, 173, 173, 110, 173, 173, 173, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 74, 110, 110, 110, 110, 110, 173, 173, 173}, {175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 110, 175, 175, 175, 175, 110, 175, 175, 175, 110, 110, 110, 110, 110, 110, 110, 75, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 175, 175, 175}, {177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 110, 177, 177, 177, 177, 110, 177, 177, 177, 110, 110, 110, 110, 110, 76, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 177, 177, 177}, {179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 110, 179, 179, 179, 179, 110, 179, 179, 179, 110, 110, 110, 110, 110, 110, 110, 110, 110, 77, 110, 110, 110, 110, 110, 110, 110, 110, 179, 179, 179}, {181, 181, 181, 181, 181, 181, 181, 181, 181, 181, 181, 181, 181, 181, 110, 181, 181, 181, 181, 110, 181, 181, 181, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 78, 110, 110, 110, 110, 110, 181, 181, 181}, {183, 183, 183, 183, 183, 183, 183, 183, 183, 183, 183, 183, 183, 183, 110, 183, 183, 183, 183, 110, 183, 183, 183, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 79, 110, 110, 110, 183, 183, 183}, {185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 110, 185, 185, 185, 185, 110, 185, 185, 185, 110, 110, 110, 80, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 185, 185, 185}, {218, 218, 218, 218, 218, 218, 218, 218, 218, 218, 218, 218, 218, 218, 110, 218, 218, 218, 218, 110, 218, 218, 218, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 218, 218, 218}, {219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 110, 219, 219, 219, 219, 110, 219, 219, 219, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 219, 219, 219}, {187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 110, 187, 187, 187, 187, 110, 187, 187, 187, 110, 110, 110, 81, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 187, 187, 187}, {220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 110, 220, 220, 220, 220, 110, 220, 220, 220, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 220, 220, 220}, {221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 110, 221, 221, 221, 221, 110, 221, 221, 221, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 221, 221, 221}, {222, 222, 222, 222, 222, 222, 222, 222, 222, 222, 222, 222, 222, 222, 110, 222, 222, 222, 222, 110, 222, 222, 222, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 222, 222, 222}}};
::ISPA_STD::DFA::API::Table<106, 4> DepParser::Lexer::action_table = {{{1, 10, ::ISPA_STD::DFA::API::null_state, 1}, {1, 18, ::ISPA_STD::DFA::API::null_state, 18}, {1, 20, ::ISPA_STD::DFA::API::null_state, 26}, {1, 20, ::ISPA_STD::DFA::API::null_state, 25}, {1, 20, ::ISPA_STD::DFA::API::null_state, 24}, {1, 20, ::ISPA_STD::DFA::API::null_state, 20}, {1, 8, ::ISPA_STD::DFA::API::null_state, 19}, {1, 12, ::ISPA_STD::DFA::API::null_state, 13}, {1, 20, ::ISPA_STD::DFA::API::null_state, 12}, {1, 20, ::ISPA_STD::DFA::API::null_state, 10}, {1, 6, ::ISPA_STD::DFA::API::null_state, 5}, {1, 4, ::ISPA_STD::DFA::API::null_state, 3}, {1, 20, ::ISPA_STD::DFA::API::null_state, 22}, {1, 20, ::ISPA_STD::DFA::API::null_state, 23}, {1, 20, ::ISPA_STD::DFA::API::null_state, 21}, {1, 11, ::ISPA_STD::DFA::API::null_state, 188}, {3, 10, 20, 188}, {1, 11, ::ISPA_STD::DFA::API::null_state, 98}, {3, 10, 20, 188}, {1, 11, ::ISPA_STD::DFA::API::null_state, 100}, {1, 13, ::ISPA_STD::DFA::API::null_state, 196}, {1, 13, ::ISPA_STD::DFA::API::null_state, 36}, {1, 19, ::ISPA_STD::DFA::API::null_state, 201}, {1, 9, ::ISPA_STD::DFA::API::null_state, 38}, {1, 9, ::ISPA_STD::DFA::API::null_state, 40}, {1, 9, ::ISPA_STD::DFA::API::null_state, 39}, {3, 18, 20, 201}, {1, 19, ::ISPA_STD::DFA::API::null_state, 108}, {3, 18, 20, 37}, {3, 18, 20, 201}, {1, 19, ::ISPA_STD::DFA::API::null_state, 111}, {3, 18, 20, 201}, {1, 19, ::ISPA_STD::DFA::API::null_state, 113}, {3, 18, 20, 201}, {1, 19, ::ISPA_STD::DFA::API::null_state, 115}, {3, 18, 20, 201}, {1, 19, ::ISPA_STD::DFA::API::null_state, 117}, {3, 18, 20, 201}, {1, 19, ::ISPA_STD::DFA::API::null_state, 119}, {3, 18, 20, 201}, {1, 19, ::ISPA_STD::DFA::API::null_state, 121}, {1, 5, ::ISPA_STD::DFA::API::null_state, 204}, {1, 7, ::ISPA_STD::DFA::API::null_state, 205}, {3, 2, 20, 207}, {1, 3, ::ISPA_STD::DFA::API::null_state, 125}, {1, 14, ::ISPA_STD::DFA::API::null_state, 53}, {1, 19, ::ISPA_STD::DFA::API::null_state, 208}, {3, 18, 20, 208}, {1, 19, ::ISPA_STD::DFA::API::null_state, 129}, {3, 18, 20, 208}, {1, 19, ::ISPA_STD::DFA::API::null_state, 131}, {3, 18, 20, 208}, {1, 19, ::ISPA_STD::DFA::API::null_state, 133}, {3, 18, 20, 208}, {1, 19, ::ISPA_STD::DFA::API::null_state, 135}, {3, 18, 20, 208}, {1, 19, ::ISPA_STD::DFA::API::null_state, 137}, {3, 18, 20, 208}, {1, 19, ::ISPA_STD::DFA::API::null_state, 139}, {3, 18, 20, 208}, {1, 19, ::ISPA_STD::DFA::API::null_state, 141}, {1, 16, ::ISPA_STD::DFA::API::null_state, 61}, {1, 17, ::ISPA_STD::DFA::API::null_state, 62}, {3, 2, 20, 212}, {1, 3, ::ISPA_STD::DFA::API::null_state, 145}, {1, 15, ::ISPA_STD::DFA::API::null_state, 213}, {3, 18, 20, 208}, {1, 19, ::ISPA_STD::DFA::API::null_state, 148}, {3, 18, 20, 208}, {1, 19, ::ISPA_STD::DFA::API::null_state, 150}, {3, 18, 20, 208}, {1, 19, ::ISPA_STD::DFA::API::null_state, 152}, {3, 18, 20, 208}, {1, 19, ::ISPA_STD::DFA::API::null_state, 154}, {3, 18, 20, 208}, {1, 19, ::ISPA_STD::DFA::API::null_state, 156}, {3, 18, 20, 208}, {1, 19, ::ISPA_STD::DFA::API::null_state, 158}, {3, 18, 20, 208}, {1, 19, ::ISPA_STD::DFA::API::null_state, 160}, {3, 17, 16, 62}, {3, 16, 20, 214}, {3, 0, 20, 215}, {1, 1, ::ISPA_STD::DFA::API::null_state, 164}, {3, 18, 20, 208}, {1, 19, ::ISPA_STD::DFA::API::null_state, 166}, {3, 18, 20, 208}, {1, 19, ::ISPA_STD::DFA::API::null_state, 168}, {3, 18, 20, 208}, {1, 19, ::ISPA_STD::DFA::API::null_state, 170}, {3, 18, 20, 208}, {1, 19, ::ISPA_STD::DFA::API::null_state, 172}, {3, 18, 20, 208}, {1, 19, ::ISPA_STD::DFA::API::null_state, 174}, {3, 18, 20, 208}, {1, 19, ::ISPA_STD::DFA::API::null_state, 176}, {3, 18, 20, 208}, {1, 19, ::ISPA_STD::DFA::API::null_state, 178}, {3, 18, 20, 208}, {1, 19, ::ISPA_STD::DFA::API::null_state, 180}, {3, 18, 20, 208}, {1, 19, ::ISPA_STD::DFA::API::null_state, 182}, {3, 18, 20, 208}, {1, 19, ::ISPA_STD::DFA::API::null_state, 184}, {3, 18, 20, 208}, {1, 19, ::ISPA_STD::DFA::API::null_state, 186}}};
std::array<::ISPA_STD::DFA::API::DFADebug, 1> DepParser::Lexer::debug_array = {::ISPA_STD::DFA::API::DFADebug {"<Undefined>", "", 0, -1, -1, -1, 0, 1, '\000'}};
std::unordered_map<long long, std::unordered_map<long long, long long>> DepParser::Lexer::debug_index = { { 0, { { 2, 0 }, { 3, 0 }, { 5, 0 }, { 7, 0 }, { 8, 0 }, { 9, 0 }, { 10, 0 }, { 12, 0 }, { 15, 0 }, { 16, 0 }, { 17, 0 }, { 18, 0 }, { 41, 0 }, { 42, 0 } } }, { 2, { { 2, 0 }, { 3, 0 } } }, { 3, { { 1, 0 }, { 2, 0 }, { 3, 0 }, { 4, 0 }, { 5, 0 }, { 6, 0 }, { 7, 0 }, { 8, 0 }, { 9, 0 }, { 10, 0 }, { 11, 0 }, { 12, 0 }, { 13, 0 }, { 14, 0 }, { 15, 0 }, { 16, 0 }, { 17, 0 }, { 18, 0 }, { 19, 0 }, { 20, 0 }, { 21, 0 }, { 22, 0 }, { 23, 0 }, { 24, 0 }, { 25, 0 }, { 26, 0 }, { 27, 0 }, { 28, 0 }, { 29, 0 }, { 30, 0 }, { 31, 0 }, { 32, 0 }, { 33, 0 }, { 34, 0 }, { 35, 0 }, { 36, 0 }, { 37, 0 }, { 38, 0 }, { 39, 0 }, { 40, 0 }, { 41, 0 }, { 42, 0 } } }, { 5, { { 1, 0 }, { 2, 0 }, { 3, 0 }, { 4, 0 }, { 5, 0 }, { 6, 0 }, { 7, 0 }, { 8, 0 }, { 9, 0 }, { 10, 0 }, { 11, 0 }, { 12, 0 }, { 13, 0 }, { 14, 0 }, { 15, 0 }, { 16, 0 }, { 17, 0 }, { 18, 0 }, { 19, 0 }, { 20, 0 }, { 21, 0 }, { 22, 0 }, { 23, 0 }, { 24, 0 }, { 25, 0 }, { 26, 0 }, { 27, 0 }, { 28, 0 }, { 29, 0 }, { 30, 0 }, { 31, 0 }, { 32, 0 }, { 33, 0 }, { 34, 0 }, { 35, 0 }, { 36, 0 }, { 37, 0 }, { 38, 0 }, { 39, 0 }, { 40, 0 }, { 41, 0 }, { 42, 0 } } }, { 10, { { 18, 0 } } }, { 12, { { 9, 0 }, { 13, 0 } } }, { 13, { { 14, 0 } } }, { 18, { { 14, 0 }, { 19, 0 }, { 23, 0 }, { 24, 0 }, { 25, 0 }, { 26, 0 }, { 27, 0 }, { 28, 0 }, { 29, 0 }, { 30, 0 }, { 31, 0 }, { 32, 0 }, { 33, 0 }, { 34, 0 }, { 35, 0 }, { 36, 0 }, { 37, 0 }, { 38, 0 }, { 39, 0 }, { 40, 0 } } }, { 20, { { 36, 0 } } }, { 21, { { 26, 0 } } }, { 22, { { 39, 0 } } }, { 23, { { 23, 0 }, { 26, 0 }, { 35, 0 } } }, { 24, { { 31, 0 } } }, { 25, { { 33, 0 } } }, { 26, { { 40, 0 }, { 41, 0 } } }, { 30, { { 1, 0 }, { 2, 0 }, { 3, 0 }, { 4, 0 }, { 5, 0 }, { 6, 0 }, { 7, 0 }, { 8, 0 }, { 9, 0 }, { 10, 0 }, { 11, 0 }, { 12, 0 }, { 13, 0 }, { 14, 0 }, { 15, 0 }, { 16, 0 }, { 17, 0 }, { 18, 0 }, { 19, 0 }, { 20, 0 }, { 21, 0 }, { 22, 0 }, { 23, 0 }, { 24, 0 }, { 25, 0 }, { 26, 0 }, { 27, 0 }, { 28, 0 }, { 29, 0 }, { 30, 0 }, { 31, 0 }, { 32, 0 }, { 33, 0 }, { 34, 0 }, { 35, 0 }, { 36, 0 }, { 37, 0 }, { 38, 0 }, { 39, 0 }, { 40, 0 }, { 41, 0 }, { 42, 0 } } }, { 32, { { 1, 0 }, { 2, 0 }, { 3, 0 }, { 4, 0 }, { 5, 0 }, { 6, 0 }, { 7, 0 }, { 8, 0 }, { 9, 0 }, { 10, 0 }, { 11, 0 }, { 12, 0 }, { 13, 0 }, { 14, 0 }, { 15, 0 }, { 16, 0 }, { 17, 0 }, { 18, 0 }, { 19, 0 }, { 20, 0 }, { 21, 0 }, { 22, 0 }, { 23, 0 }, { 24, 0 }, { 25, 0 }, { 26, 0 }, { 27, 0 }, { 28, 0 }, { 29, 0 }, { 30, 0 }, { 31, 0 }, { 32, 0 }, { 33, 0 }, { 34, 0 }, { 35, 0 }, { 36, 0 }, { 37, 0 }, { 38, 0 }, { 39, 0 }, { 40, 0 }, { 41, 0 }, { 42, 0 } } }, { 34, { { 1, 0 }, { 2, 0 }, { 3, 0 }, { 4, 0 }, { 5, 0 }, { 6, 0 }, { 7, 0 }, { 8, 0 }, { 9, 0 }, { 10, 0 }, { 11, 0 }, { 12, 0 }, { 13, 0 }, { 14, 0 }, { 15, 0 }, { 16, 0 }, { 17, 0 }, { 18, 0 }, { 19, 0 }, { 20, 0 }, { 21, 0 }, { 22, 0 }, { 23, 0 }, { 24, 0 }, { 25, 0 }, { 26, 0 }, { 27, 0 }, { 28, 0 }, { 29, 0 }, { 30, 0 }, { 31, 0 }, { 32, 0 }, { 33, 0 }, { 34, 0 }, { 35, 0 }, { 36, 0 }, { 37, 0 }, { 38, 0 }, { 39, 0 }, { 40, 0 }, { 41, 0 }, { 42, 0 } } }, { 35, { { 1, 0 }, { 2, 0 }, { 4, 0 }, { 5, 0 }, { 6, 0 }, { 7, 0 }, { 8, 0 }, { 9, 0 }, { 10, 0 }, { 11, 0 }, { 12, 0 }, { 13, 0 }, { 14, 0 }, { 15, 0 }, { 16, 0 }, { 17, 0 }, { 18, 0 }, { 19, 0 }, { 20, 0 }, { 21, 0 }, { 22, 0 }, { 23, 0 }, { 24, 0 }, { 25, 0 }, { 26, 0 }, { 27, 0 }, { 28, 0 }, { 29, 0 }, { 30, 0 }, { 31, 0 }, { 32, 0 }, { 33, 0 }, { 34, 0 }, { 35, 0 }, { 36, 0 }, { 37, 0 }, { 38, 0 }, { 39, 0 }, { 40, 0 }, { 41, 0 }, { 42, 0 } } }, { 37, { { 14, 0 }, { 19, 0 }, { 23, 0 }, { 24, 0 }, { 25, 0 }, { 26, 0 }, { 27, 0 }, { 28, 0 }, { 29, 0 }, { 30, 0 }, { 31, 0 }, { 32, 0 }, { 33, 0 }, { 34, 0 }, { 35, 0 }, { 36, 0 }, { 37, 0 }, { 38, 0 }, { 39, 0 }, { 40, 0 } } }, { 38, { { 1, 0 }, { 2, 0 }, { 3, 0 }, { 4, 0 }, { 5, 0 }, { 6, 0 }, { 7, 0 }, { 8, 0 }, { 9, 0 }, { 10, 0 }, { 11, 0 }, { 12, 0 }, { 13, 0 }, { 14, 0 }, { 15, 0 }, { 16, 0 }, { 17, 0 }, { 18, 0 }, { 19, 0 }, { 20, 0 }, { 21, 0 }, { 22, 0 }, { 23, 0 }, { 24, 0 }, { 25, 0 }, { 26, 0 }, { 27, 0 }, { 28, 0 }, { 29, 0 }, { 30, 0 }, { 31, 0 }, { 32, 0 }, { 33, 0 }, { 34, 0 }, { 35, 0 }, { 36, 0 }, { 37, 0 }, { 38, 0 }, { 39, 0 }, { 40, 0 }, { 41, 0 }, { 42, 0 } } }, { 39, { { 1, 0 }, { 2, 0 }, { 3, 0 }, { 4, 0 }, { 5, 0 }, { 6, 0 }, { 7, 0 }, { 8, 0 }, { 9, 0 }, { 10, 0 }, { 11, 0 }, { 12, 0 }, { 13, 0 }, { 14, 0 }, { 15, 0 }, { 16, 0 }, { 17, 0 }, { 18, 0 }, { 19, 0 }, { 20, 0 }, { 21, 0 }, { 22, 0 }, { 23, 0 }, { 24, 0 }, { 25, 0 }, { 26, 0 }, { 27, 0 }, { 28, 0 }, { 29, 0 }, { 30, 0 }, { 31, 0 }, { 32, 0 }, { 33, 0 }, { 34, 0 }, { 35, 0 }, { 36, 0 }, { 37, 0 }, { 38, 0 }, { 39, 0 }, { 40, 0 }, { 41, 0 }, { 42, 0 } } }, { 42, { { 37, 0 } } }, { 43, { { 37, 0 } } }, { 44, { { 29, 0 } } }, { 45, { { 23, 0 } } }, { 46, { { 33, 0 } } }, { 47, { { 34, 0 } } }, { 48, { { 25, 0 } } }, { 51, { { 1, 0 }, { 2, 0 }, { 3, 0 }, { 4, 0 }, { 5, 0 }, { 6, 0 }, { 7, 0 }, { 8, 0 }, { 9, 0 }, { 10, 0 }, { 11, 0 }, { 12, 0 }, { 13, 0 }, { 14, 0 }, { 15, 0 }, { 16, 0 }, { 17, 0 }, { 18, 0 }, { 19, 0 }, { 20, 0 }, { 21, 0 }, { 22, 0 }, { 23, 0 }, { 24, 0 }, { 25, 0 }, { 26, 0 }, { 27, 0 }, { 28, 0 }, { 29, 0 }, { 30, 0 }, { 31, 0 }, { 32, 0 }, { 33, 0 }, { 34, 0 }, { 35, 0 }, { 36, 0 }, { 37, 0 }, { 38, 0 }, { 39, 0 }, { 40, 0 }, { 41, 0 }, { 42, 0 } } }, { 52, { { 1, 0 }, { 2, 0 }, { 4, 0 }, { 5, 0 }, { 6, 0 }, { 7, 0 }, { 8, 0 }, { 9, 0 }, { 10, 0 }, { 11, 0 }, { 12, 0 }, { 13, 0 }, { 14, 0 }, { 15, 0 }, { 16, 0 }, { 17, 0 }, { 18, 0 }, { 19, 0 }, { 20, 0 }, { 21, 0 }, { 22, 0 }, { 23, 0 }, { 24, 0 }, { 25, 0 }, { 26, 0 }, { 27, 0 }, { 28, 0 }, { 29, 0 }, { 30, 0 }, { 31, 0 }, { 32, 0 }, { 33, 0 }, { 34, 0 }, { 35, 0 }, { 36, 0 }, { 37, 0 }, { 38, 0 }, { 39, 0 }, { 40, 0 }, { 41, 0 }, { 42, 0 } } }, { 53, { { 14, 0 } } }, { 54, { { 23, 0 } } }, { 55, { { 26, 0 } } }, { 56, { { 30, 0 } } }, { 57, { { 37, 0 } } }, { 58, { { 31, 0 } } }, { 59, { { 33, 0 } } }, { 60, { { 38, 0 } } }, { 61, { { 0, 0 }, { 1, 0 }, { 2, 0 }, { 3, 0 }, { 4, 0 }, { 5, 0 }, { 6, 0 }, { 7, 0 }, { 8, 0 }, { 9, 0 }, { 10, 0 }, { 11, 0 }, { 12, 0 }, { 13, 0 }, { 14, 0 }, { 15, 0 }, { 16, 0 }, { 17, 0 }, { 18, 0 }, { 19, 0 }, { 20, 0 }, { 21, 0 }, { 22, 0 }, { 23, 0 }, { 24, 0 }, { 25, 0 }, { 26, 0 }, { 27, 0 }, { 28, 0 }, { 29, 0 }, { 30, 0 }, { 31, 0 }, { 32, 0 }, { 33, 0 }, { 34, 0 }, { 35, 0 }, { 36, 0 }, { 37, 0 }, { 38, 0 }, { 39, 0 }, { 40, 0 }, { 41, 0 } } }, { 64, { { 24, 0 } } }, { 65, { { 35, 0 } } }, { 67, { { 38, 0 } } }, { 69, { { 35, 0 } } }, { 70, { { 30, 0 } } }, { 71, { { 28, 0 } } }, { 72, { { 32, 0 } } }, { 73, { { 35, 0 } } }, { 74, { { 37, 0 } } }, { 75, { { 26, 0 } } }, { 78, { { 26, 0 } } } };
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
	if (rule == 33 && gap == 0) {
		return true;
	}
	if (rule == 55 && gap == 1) {
		return true;
	}
	if (rule == 55 && gap == 2) {
		return true;
	}
	if (rule == 59 && gap == 0) {
		return true;
	}
	if (rule == 60 && gap == 1) {
		return true;
	}
	if (rule == 60 && gap == 2) {
		return true;
	}
	if (rule == 64 && gap == 0) {
		return true;
	}
	if (rule == 65 && gap == 1) {
		return true;
	}
	if (rule == 69 && gap == 0) {
		return true;
	}
	if (rule == 70 && gap == 1) {
		return true;
	}
	if (rule == 71 && gap == 1) {
		return true;
	}
	if (rule == 71 && gap == 2) {
		return true;
	}
	if (rule == 72 && gap == 1) {
		return true;
	}
	if (rule == 72 && gap == 2) {
		return true;
	}
	if (rule == 72 && gap == 3) {
		return true;
	}
	if (rule == 72 && gap == 4) {
		return true;
	}
	if (rule == 72 && gap == 5) {
		return true;
	}
	if (rule == 79 && gap == 1) {
		return true;
	}
	if (rule == 79 && gap == 2) {
		return true;
	}
	if (rule == 82 && gap == 1) {
		return true;
	}
	if (rule == 83 && gap == 1) {
		return true;
	}
	if (rule == 83 && gap == 2) {
		return true;
	}
	if (rule == 83 && gap == 3) {
		return true;
	}
	if (rule == 86 && gap == 1) {
		return true;
	}
	if (rule == 89 && gap == 1) {
		return true;
	}
	if (rule == 89 && gap == 2) {
		return true;
	}
	if (rule == 92 && gap == 1) {
		return true;
	}
	if (rule == 92 && gap == 2) {
		return true;
	}
	if (rule == 92 && gap == 3) {
		return true;
	}
	if (rule == 94 && gap == 1) {
		return true;
	}
	if (rule == 96 && gap == 0) {
		return true;
	}
	if (rule == 96 && gap == 1) {
		return true;
	}
	if (rule == 97 && gap == 1) {
		return true;
	}
	if (rule == 99 && gap == 1) {
		return true;
	}
	if (rule == 100 && gap == 1) {
		return true;
	}
	if (rule == 100 && gap == 2) {
		return true;
	}
	if (rule == 100 && gap == 3) {
		return true;
	}
	if (rule == 100 && gap == 4) {
		return true;
	}
	if (rule == 102 && gap == 1) {
		return true;
	}
	if (rule == 105 && gap == 1) {
		return true;
	}
	if (rule == 105 && gap == 2) {
		return true;
	}
	if (rule == 105 && gap == 3) {
		return true;
	}
	if (rule == 105 && gap == 4) {
		return true;
	}
	if (rule == 107 && gap == 1) {
		return true;
	}
	if (rule == 108 && gap == 1) {
		return true;
	}
	if (rule == 109 && gap == 1) {
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
	if (rule == 115 && gap == 1) {
		return true;
	}
	if (rule == 115 && gap == 2) {
		return true;
	}
	if (rule == 119 && gap == 0) {
		return true;
	}
	if (rule == 121 && gap == 1) {
		return true;
	}
	if (rule == 123 && gap == 1) {
		return true;
	}
	if (rule == 125 && gap == 0) {
		return true;
	}
	if (rule == 125 && gap == 1) {
		return true;
	}
	return false;
}
auto DepParser::Parser::lr_action(std::size_t state, const std::vector<std::size_t>& window) -> long long {
	if (state == 0 && window.at(0) == static_cast<std::size_t>(-1)) {
		return -23;
	}
	if (state == 0 && window.at(0) == Tokens::FEATURE::id) {
		return 2;
	}
	if (state == 0 && window.at(0) == Tokens::IMPORT::id) {
		return 3;
	}
	if (state == 0 && window.at(0) == Tokens::NUMBER_SIGN::id) {
		return 4;
	}
	if (state == 0 && window.at(0) == Tokens::modules::common::ID::id) {
		return -67;
	}
	if (state == 0 && window.at(0) == Tokens::modules::ispa_dep_scanner::fail_decl::FAIL::id) {
		return 12;
	}
	if (state == 0 && window.at(0) == Tokens::modules::ispa_dep_scanner::mod_detach::DETACH::id) {
		return 15;
	}
	if (state == 0 && window.at(0) == Tokens::modules::ispa_dep_scanner::mod_module::MODULE::id) {
		return 18;
	}
	if (state == 0 && window.at(0) == Tokens::modules::scanner_tokens::COMMENT::id) {
		return 21;
	}
	if (state == 1 && window.at(0) == Tokens::modules::common::ID::id) {
		return 22;
	}
	if (state == 2 && window.at(0) == Tokens::ASTERISK::id) {
		return -85;
	}
	if (state == 2 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -85;
	}
	if (state == 2 && window.at(0) == Tokens::modules::common::ID::id) {
		return -85;
	}
	if (state == 2 && window.at(0) == Tokens::modules::ispa_dep_scanner::mod_import::external_import::EXTERN::id) {
		return 27;
	}
	if (state == 2 && window.at(0) == Tokens::modules::ispa_dep_scanner::mod_python_import::PY::id) {
		return 28;
	}
	if (state == 3 && window.at(0) == Tokens::modules::scanner_tokens::CGROUP::id) {
		return 29;
	}
	if (state == 4 && window.at(0) == static_cast<std::size_t>(-1)) {
		return 0;
	}
	if (state == 5 && window.at(0) == static_cast<std::size_t>(-1)) {
		return -1;
	}
	if (state == 6 && window.at(0) == static_cast<std::size_t>(-1)) {
		return -22;
	}
	if (state == 7 && window.at(0) == static_cast<std::size_t>(-1)) {
		return -33;
	}
	if (state == 7 && window.at(0) == Tokens::FEATURE::id) {
		return 2;
	}
	if (state == 7 && window.at(0) == Tokens::IMPORT::id) {
		return 3;
	}
	if (state == 7 && window.at(0) == Tokens::NUMBER_SIGN::id) {
		return 4;
	}
	if (state == 7 && window.at(0) == Tokens::modules::common::ID::id) {
		return -67;
	}
	if (state == 7 && window.at(0) == Tokens::modules::ispa_dep_scanner::fail_decl::FAIL::id) {
		return 12;
	}
	if (state == 7 && window.at(0) == Tokens::modules::ispa_dep_scanner::mod_detach::DETACH::id) {
		return 15;
	}
	if (state == 7 && window.at(0) == Tokens::modules::ispa_dep_scanner::mod_module::MODULE::id) {
		return 18;
	}
	if (state == 7 && window.at(0) == Tokens::modules::scanner_tokens::COMMENT::id) {
		return 21;
	}
	if (state == 8 && window.at(0) == static_cast<std::size_t>(-1)) {
		return -30;
	}
	if (state == 8 && window.at(0) == Tokens::FEATURE::id) {
		return -30;
	}
	if (state == 8 && window.at(0) == Tokens::IMPORT::id) {
		return -30;
	}
	if (state == 8 && window.at(0) == Tokens::NUMBER_SIGN::id) {
		return -30;
	}
	if (state == 8 && window.at(0) == Tokens::modules::common::ID::id) {
		return -30;
	}
	if (state == 8 && window.at(0) == Tokens::modules::ispa_dep_scanner::fail_decl::FAIL::id) {
		return -30;
	}
	if (state == 8 && window.at(0) == Tokens::modules::ispa_dep_scanner::mod_detach::DETACH::id) {
		return -30;
	}
	if (state == 8 && window.at(0) == Tokens::modules::ispa_dep_scanner::mod_module::MODULE::id) {
		return -30;
	}
	if (state == 8 && window.at(0) == Tokens::modules::scanner_tokens::COMMENT::id) {
		return -30;
	}
	if (state == 9 && window.at(0) == Tokens::modules::common::ID::id) {
		return 22;
	}
	if (state == 10 && window.at(0) == static_cast<std::size_t>(-1)) {
		return -31;
	}
	if (state == 10 && window.at(0) == Tokens::FEATURE::id) {
		return -31;
	}
	if (state == 10 && window.at(0) == Tokens::IMPORT::id) {
		return -31;
	}
	if (state == 10 && window.at(0) == Tokens::NUMBER_SIGN::id) {
		return -31;
	}
	if (state == 10 && window.at(0) == Tokens::modules::common::ID::id) {
		return -31;
	}
	if (state == 10 && window.at(0) == Tokens::modules::ispa_dep_scanner::fail_decl::FAIL::id) {
		return -31;
	}
	if (state == 10 && window.at(0) == Tokens::modules::ispa_dep_scanner::mod_detach::DETACH::id) {
		return -31;
	}
	if (state == 10 && window.at(0) == Tokens::modules::ispa_dep_scanner::mod_module::MODULE::id) {
		return -31;
	}
	if (state == 10 && window.at(0) == Tokens::modules::scanner_tokens::COMMENT::id) {
		return -31;
	}
	if (state == 11 && window.at(0) == Tokens::modules::common::ID::id) {
		return 22;
	}
	if (state == 12 && window.at(0) == static_cast<std::size_t>(-1)) {
		return -29;
	}
	if (state == 12 && window.at(0) == Tokens::FEATURE::id) {
		return -29;
	}
	if (state == 12 && window.at(0) == Tokens::IMPORT::id) {
		return -29;
	}
	if (state == 12 && window.at(0) == Tokens::NUMBER_SIGN::id) {
		return -29;
	}
	if (state == 12 && window.at(0) == Tokens::modules::common::ID::id) {
		return -29;
	}
	if (state == 12 && window.at(0) == Tokens::modules::ispa_dep_scanner::fail_decl::FAIL::id) {
		return -29;
	}
	if (state == 12 && window.at(0) == Tokens::modules::ispa_dep_scanner::mod_detach::DETACH::id) {
		return -29;
	}
	if (state == 12 && window.at(0) == Tokens::modules::ispa_dep_scanner::mod_module::MODULE::id) {
		return -29;
	}
	if (state == 12 && window.at(0) == Tokens::modules::scanner_tokens::COMMENT::id) {
		return -29;
	}
	if (state == 13 && window.at(0) == static_cast<std::size_t>(-1)) {
		return -28;
	}
	if (state == 13 && window.at(0) == Tokens::FEATURE::id) {
		return -28;
	}
	if (state == 13 && window.at(0) == Tokens::IMPORT::id) {
		return -28;
	}
	if (state == 13 && window.at(0) == Tokens::NUMBER_SIGN::id) {
		return -28;
	}
	if (state == 13 && window.at(0) == Tokens::modules::common::ID::id) {
		return -28;
	}
	if (state == 13 && window.at(0) == Tokens::modules::ispa_dep_scanner::fail_decl::FAIL::id) {
		return -28;
	}
	if (state == 13 && window.at(0) == Tokens::modules::ispa_dep_scanner::mod_detach::DETACH::id) {
		return -28;
	}
	if (state == 13 && window.at(0) == Tokens::modules::ispa_dep_scanner::mod_module::MODULE::id) {
		return -28;
	}
	if (state == 13 && window.at(0) == Tokens::modules::scanner_tokens::COMMENT::id) {
		return -28;
	}
	if (state == 14 && window.at(0) == Tokens::FEATURE::id) {
		return 35;
	}
	if (state == 14 && window.at(0) == Tokens::modules::common::ID::id) {
		return 22;
	}
	if (state == 15 && window.at(0) == static_cast<std::size_t>(-1)) {
		return -27;
	}
	if (state == 15 && window.at(0) == Tokens::FEATURE::id) {
		return -27;
	}
	if (state == 15 && window.at(0) == Tokens::IMPORT::id) {
		return -27;
	}
	if (state == 15 && window.at(0) == Tokens::NUMBER_SIGN::id) {
		return -27;
	}
	if (state == 15 && window.at(0) == Tokens::modules::common::ID::id) {
		return -27;
	}
	if (state == 15 && window.at(0) == Tokens::modules::ispa_dep_scanner::fail_decl::FAIL::id) {
		return -27;
	}
	if (state == 15 && window.at(0) == Tokens::modules::ispa_dep_scanner::mod_detach::DETACH::id) {
		return -27;
	}
	if (state == 15 && window.at(0) == Tokens::modules::ispa_dep_scanner::mod_module::MODULE::id) {
		return -27;
	}
	if (state == 15 && window.at(0) == Tokens::modules::scanner_tokens::COMMENT::id) {
		return -27;
	}
	if (state == 16 && window.at(0) == static_cast<std::size_t>(-1)) {
		return -25;
	}
	if (state == 16 && window.at(0) == Tokens::FEATURE::id) {
		return -25;
	}
	if (state == 16 && window.at(0) == Tokens::IMPORT::id) {
		return -25;
	}
	if (state == 16 && window.at(0) == Tokens::NUMBER_SIGN::id) {
		return -25;
	}
	if (state == 16 && window.at(0) == Tokens::modules::common::ID::id) {
		return -25;
	}
	if (state == 16 && window.at(0) == Tokens::modules::ispa_dep_scanner::fail_decl::FAIL::id) {
		return -25;
	}
	if (state == 16 && window.at(0) == Tokens::modules::ispa_dep_scanner::mod_detach::DETACH::id) {
		return -25;
	}
	if (state == 16 && window.at(0) == Tokens::modules::ispa_dep_scanner::mod_module::MODULE::id) {
		return -25;
	}
	if (state == 16 && window.at(0) == Tokens::modules::scanner_tokens::COMMENT::id) {
		return -25;
	}
	if (state == 17 && window.at(0) == Tokens::modules::common::ID::id) {
		return 39;
	}
	if (state == 18 && window.at(0) == static_cast<std::size_t>(-1)) {
		return -26;
	}
	if (state == 18 && window.at(0) == Tokens::FEATURE::id) {
		return -26;
	}
	if (state == 18 && window.at(0) == Tokens::IMPORT::id) {
		return -26;
	}
	if (state == 18 && window.at(0) == Tokens::NUMBER_SIGN::id) {
		return -26;
	}
	if (state == 18 && window.at(0) == Tokens::modules::common::ID::id) {
		return -26;
	}
	if (state == 18 && window.at(0) == Tokens::modules::ispa_dep_scanner::fail_decl::FAIL::id) {
		return -26;
	}
	if (state == 18 && window.at(0) == Tokens::modules::ispa_dep_scanner::mod_detach::DETACH::id) {
		return -26;
	}
	if (state == 18 && window.at(0) == Tokens::modules::ispa_dep_scanner::mod_module::MODULE::id) {
		return -26;
	}
	if (state == 18 && window.at(0) == Tokens::modules::scanner_tokens::COMMENT::id) {
		return -26;
	}
	if (state == 19 && window.at(0) == Tokens::NUMBER_SIGN::id) {
		return 4;
	}
	if (state == 19 && window.at(0) == Tokens::modules::common::ID::id) {
		return -69;
	}
	if (state == 20 && window.at(0) == static_cast<std::size_t>(-1)) {
		return -32;
	}
	if (state == 20 && window.at(0) == Tokens::FEATURE::id) {
		return -32;
	}
	if (state == 20 && window.at(0) == Tokens::IMPORT::id) {
		return -32;
	}
	if (state == 20 && window.at(0) == Tokens::NUMBER_SIGN::id) {
		return -32;
	}
	if (state == 20 && window.at(0) == Tokens::modules::common::ID::id) {
		return -32;
	}
	if (state == 20 && window.at(0) == Tokens::modules::ispa_dep_scanner::fail_decl::FAIL::id) {
		return -32;
	}
	if (state == 20 && window.at(0) == Tokens::modules::ispa_dep_scanner::mod_detach::DETACH::id) {
		return -32;
	}
	if (state == 20 && window.at(0) == Tokens::modules::ispa_dep_scanner::mod_module::MODULE::id) {
		return -32;
	}
	if (state == 20 && window.at(0) == Tokens::modules::scanner_tokens::COMMENT::id) {
		return -32;
	}
	if (state == 21 && window.at(0) == Tokens::COLON::id) {
		return -3;
	}
	if (state == 21 && window.at(0) == Tokens::COMMA::id) {
		return -3;
	}
	if (state == 21 && window.at(0) == Tokens::FULL_STOP::id) {
		return 43;
	}
	if (state == 21 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -3;
	}
	if (state == 21 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -3;
	}
	if (state == 21 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -3;
	}
	if (state == 21 && window.at(0) == Tokens::RIGHT_CURLY_BRACKET::id) {
		return -3;
	}
	if (state == 21 && window.at(0) == Tokens::SEMICOLON::id) {
		return -3;
	}
	if (state == 22 && window.at(0) == Tokens::COMMA::id) {
		return -121;
	}
	if (state == 22 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -121;
	}
	if (state == 22 && window.at(0) == Tokens::RIGHT_CURLY_BRACKET::id) {
		return -121;
	}
	if (state == 22 && window.at(0) == Tokens::SEMICOLON::id) {
		return -121;
	}
	if (state == 23 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return 45;
	}
	if (state == 24 && window.at(0) == Tokens::ASTERISK::id) {
		return 46;
	}
	if (state == 24 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return 47;
	}
	if (state == 24 && window.at(0) == Tokens::modules::common::ID::id) {
		return 39;
	}
	if (state == 25 && window.at(0) == Tokens::ASTERISK::id) {
		return -86;
	}
	if (state == 25 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -86;
	}
	if (state == 25 && window.at(0) == Tokens::modules::common::ID::id) {
		return -86;
	}
	if (state == 26 && window.at(0) == Tokens::modules::common::ID::id) {
		return 54;
	}
	if (state == 27 && window.at(0) == Tokens::modules::common::ID::id) {
		return 39;
	}
	if (state == 28 && window.at(0) == Tokens::NUMBER_SIGN::id) {
		return -109;
	}
	if (state == 28 && window.at(0) == Tokens::modules::common::ID::id) {
		return -109;
	}
	if (state == 29 && window.at(0) == static_cast<std::size_t>(-1)) {
		return -33;
	}
	if (state == 29 && window.at(0) == Tokens::FEATURE::id) {
		return 2;
	}
	if (state == 29 && window.at(0) == Tokens::IMPORT::id) {
		return 3;
	}
	if (state == 29 && window.at(0) == Tokens::NUMBER_SIGN::id) {
		return 4;
	}
	if (state == 29 && window.at(0) == Tokens::modules::common::ID::id) {
		return -67;
	}
	if (state == 29 && window.at(0) == Tokens::modules::ispa_dep_scanner::fail_decl::FAIL::id) {
		return 12;
	}
	if (state == 29 && window.at(0) == Tokens::modules::ispa_dep_scanner::mod_detach::DETACH::id) {
		return 15;
	}
	if (state == 29 && window.at(0) == Tokens::modules::ispa_dep_scanner::mod_module::MODULE::id) {
		return 18;
	}
	if (state == 29 && window.at(0) == Tokens::modules::scanner_tokens::COMMENT::id) {
		return 21;
	}
	if (state == 30 && window.at(0) == static_cast<std::size_t>(-1)) {
		return -24;
	}
	if (state == 31 && window.at(0) == Tokens::COLON::id) {
		return 57;
	}
	if (state == 31 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return 58;
	}
	if (state == 32 && window.at(0) == static_cast<std::size_t>(-1)) {
		return -66;
	}
	if (state == 32 && window.at(0) == Tokens::ASTERISK::id) {
		return -66;
	}
	if (state == 32 && window.at(0) == Tokens::AUTO::id) {
		return -66;
	}
	if (state == 32 && window.at(0) == Tokens::COLON::id) {
		return -66;
	}
	if (state == 32 && window.at(0) == Tokens::COMMA::id) {
		return -66;
	}
	if (state == 32 && window.at(0) == Tokens::FEATURE::id) {
		return -66;
	}
	if (state == 32 && window.at(0) == Tokens::FULL_STOP::id) {
		return -66;
	}
	if (state == 32 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -66;
	}
	if (state == 32 && window.at(0) == Tokens::IMPORT::id) {
		return -66;
	}
	if (state == 32 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -66;
	}
	if (state == 32 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -66;
	}
	if (state == 32 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -66;
	}
	if (state == 32 && window.at(0) == Tokens::NUMBER_SIGN::id) {
		return -66;
	}
	if (state == 32 && window.at(0) == Tokens::SEMICOLON::id) {
		return -66;
	}
	if (state == 32 && window.at(0) == Tokens::modules::common::ID::id) {
		return -66;
	}
	if (state == 32 && window.at(0) == Tokens::modules::common::NUMBER::id) {
		return -66;
	}
	if (state == 32 && window.at(0) == Tokens::modules::ispa_dep_scanner::fail_decl::FAIL::id) {
		return -66;
	}
	if (state == 32 && window.at(0) == Tokens::modules::ispa_dep_scanner::mod_detach::DETACH::id) {
		return -66;
	}
	if (state == 32 && window.at(0) == Tokens::modules::ispa_dep_scanner::mod_module::MODULE::id) {
		return -66;
	}
	if (state == 32 && window.at(0) == Tokens::modules::scanner_tokens::CGROUP::id) {
		return -66;
	}
	if (state == 32 && window.at(0) == Tokens::modules::scanner_tokens::COMMENT::id) {
		return -66;
	}
	if (state == 32 && window.at(0) == Tokens::modules::scanner_tokens::OTHER::id) {
		return -66;
	}
	if (state == 32 && window.at(0) == Tokens::modules::scanner_tokens::PY_RAW::id) {
		return -66;
	}
	if (state == 32 && window.at(0) == Tokens::modules::scanner_tokens::STRING::id) {
		return -66;
	}
	if (state == 33 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return 58;
	}
	if (state == 34 && window.at(0) == Tokens::modules::common::ID::id) {
		return 22;
	}
	if (state == 35 && window.at(0) == Tokens::SEMICOLON::id) {
		return 64;
	}
	if (state == 36 && window.at(0) == Tokens::SEMICOLON::id) {
		return -81;
	}
	if (state == 37 && window.at(0) == Tokens::SEMICOLON::id) {
		return -82;
	}
	if (state == 38 && window.at(0) == Tokens::AS::id) {
		return -111;
	}
	if (state == 38 && window.at(0) == Tokens::AUTO::id) {
		return -111;
	}
	if (state == 38 && window.at(0) == Tokens::FULL_STOP::id) {
		return 65;
	}
	if (state == 38 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -111;
	}
	if (state == 38 && window.at(0) == Tokens::SEMICOLON::id) {
		return -111;
	}
	if (state == 39 && window.at(0) == Tokens::AUTO::id) {
		return -104;
	}
	if (state == 39 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return 67;
	}
	if (state == 39 && window.at(0) == Tokens::SEMICOLON::id) {
		return -104;
	}
	if (state == 40 && window.at(0) == Tokens::modules::common::ID::id) {
		return -68;
	}
	if (state == 41 && window.at(0) == Tokens::NUMBER_SIGN::id) {
		return 4;
	}
	if (state == 41 && window.at(0) == Tokens::modules::common::ID::id) {
		return -69;
	}
	if (state == 42 && window.at(0) == Tokens::modules::common::ID::id) {
		return 71;
	}
	if (state == 43 && window.at(0) == Tokens::COLON::id) {
		return -7;
	}
	if (state == 43 && window.at(0) == Tokens::COMMA::id) {
		return -7;
	}
	if (state == 43 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -7;
	}
	if (state == 43 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -7;
	}
	if (state == 43 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return 67;
	}
	if (state == 43 && window.at(0) == Tokens::RIGHT_CURLY_BRACKET::id) {
		return -7;
	}
	if (state == 43 && window.at(0) == Tokens::SEMICOLON::id) {
		return -7;
	}
	if (state == 44 && window.at(0) == Tokens::RIGHT_CURLY_BRACKET::id) {
		return -74;
	}
	if (state == 44 && window.at(0) == Tokens::modules::common::ID::id) {
		return 22;
	}
	if (state == 45 && window.at(0) == Tokens::modules::ispa_dep_scanner::mod_import::import_value::from_import::FROM::id) {
		return -91;
	}
	if (state == 46 && window.at(0) == Tokens::modules::common::ID::id) {
		return 22;
	}
	if (state == 47 && window.at(0) == Tokens::SEMICOLON::id) {
		return 78;
	}
	if (state == 48 && window.at(0) == Tokens::SEMICOLON::id) {
		return -89;
	}
	if (state == 49 && window.at(0) == Tokens::modules::ispa_dep_scanner::mod_import::import_value::from_import::FROM::id) {
		return 79;
	}
	if (state == 50 && window.at(0) == Tokens::modules::ispa_dep_scanner::mod_import::import_value::from_import::FROM::id) {
		return -92;
	}
	if (state == 51 && window.at(0) == Tokens::SEMICOLON::id) {
		return -88;
	}
	if (state == 52 && window.at(0) == Tokens::AS::id) {
		return 80;
	}
	if (state == 52 && window.at(0) == Tokens::SEMICOLON::id) {
		return -99;
	}
	if (state == 53 && window.at(0) == Tokens::ASTERISK::id) {
		return -87;
	}
	if (state == 53 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -87;
	}
	if (state == 53 && window.at(0) == Tokens::modules::common::ID::id) {
		return -87;
	}
	if (state == 54 && window.at(0) == Tokens::AS::id) {
		return 82;
	}
	if (state == 54 && window.at(0) == Tokens::SEMICOLON::id) {
		return -107;
	}
	if (state == 55 && window.at(0) == static_cast<std::size_t>(-1)) {
		return -34;
	}
	if (state == 56 && window.at(0) == Tokens::ASTERISK::id) {
		return 84;
	}
	if (state == 56 && window.at(0) == Tokens::AUTO::id) {
		return 85;
	}
	if (state == 56 && window.at(0) == Tokens::COLON::id) {
		return 86;
	}
	if (state == 56 && window.at(0) == Tokens::COMMA::id) {
		return 87;
	}
	if (state == 56 && window.at(0) == Tokens::FULL_STOP::id) {
		return 88;
	}
	if (state == 56 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return 89;
	}
	if (state == 56 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return 58;
	}
	if (state == 56 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return 90;
	}
	if (state == 56 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return 91;
	}
	if (state == 56 && window.at(0) == Tokens::NUMBER_SIGN::id) {
		return 92;
	}
	if (state == 56 && window.at(0) == Tokens::SEMICOLON::id) {
		return -57;
	}
	if (state == 56 && window.at(0) == Tokens::modules::common::ID::id) {
		return 93;
	}
	if (state == 56 && window.at(0) == Tokens::modules::common::NUMBER::id) {
		return 94;
	}
	if (state == 56 && window.at(0) == Tokens::modules::scanner_tokens::CGROUP::id) {
		return 101;
	}
	if (state == 56 && window.at(0) == Tokens::modules::scanner_tokens::COMMENT::id) {
		return 102;
	}
	if (state == 56 && window.at(0) == Tokens::modules::scanner_tokens::OTHER::id) {
		return 103;
	}
	if (state == 56 && window.at(0) == Tokens::modules::scanner_tokens::PY_RAW::id) {
		return 104;
	}
	if (state == 56 && window.at(0) == Tokens::modules::scanner_tokens::STRING::id) {
		return 105;
	}
	if (state == 57 && window.at(0) == Tokens::ASTERISK::id) {
		return 84;
	}
	if (state == 57 && window.at(0) == Tokens::AUTO::id) {
		return 85;
	}
	if (state == 57 && window.at(0) == Tokens::COLON::id) {
		return 86;
	}
	if (state == 57 && window.at(0) == Tokens::COMMA::id) {
		return 87;
	}
	if (state == 57 && window.at(0) == Tokens::FULL_STOP::id) {
		return 88;
	}
	if (state == 57 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return 89;
	}
	if (state == 57 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return 58;
	}
	if (state == 57 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return 90;
	}
	if (state == 57 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return 91;
	}
	if (state == 57 && window.at(0) == Tokens::NUMBER_SIGN::id) {
		return 106;
	}
	if (state == 57 && window.at(0) == Tokens::RIGHT_CURLY_BRACKET::id) {
		return -62;
	}
	if (state == 57 && window.at(0) == Tokens::SEMICOLON::id) {
		return 107;
	}
	if (state == 57 && window.at(0) == Tokens::modules::common::ID::id) {
		return 93;
	}
	if (state == 57 && window.at(0) == Tokens::modules::common::NUMBER::id) {
		return 94;
	}
	if (state == 57 && window.at(0) == Tokens::modules::scanner_tokens::CGROUP::id) {
		return 101;
	}
	if (state == 57 && window.at(0) == Tokens::modules::scanner_tokens::COMMENT::id) {
		return 102;
	}
	if (state == 57 && window.at(0) == Tokens::modules::scanner_tokens::OTHER::id) {
		return 103;
	}
	if (state == 57 && window.at(0) == Tokens::modules::scanner_tokens::PY_RAW::id) {
		return 104;
	}
	if (state == 57 && window.at(0) == Tokens::modules::scanner_tokens::STRING::id) {
		return 105;
	}
	if (state == 58 && window.at(0) == static_cast<std::size_t>(-1)) {
		return -71;
	}
	if (state == 58 && window.at(0) == Tokens::ASTERISK::id) {
		return -71;
	}
	if (state == 58 && window.at(0) == Tokens::AUTO::id) {
		return -71;
	}
	if (state == 58 && window.at(0) == Tokens::COLON::id) {
		return -71;
	}
	if (state == 58 && window.at(0) == Tokens::COMMA::id) {
		return -71;
	}
	if (state == 58 && window.at(0) == Tokens::FEATURE::id) {
		return -71;
	}
	if (state == 58 && window.at(0) == Tokens::FULL_STOP::id) {
		return -71;
	}
	if (state == 58 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -71;
	}
	if (state == 58 && window.at(0) == Tokens::IMPORT::id) {
		return -71;
	}
	if (state == 58 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -71;
	}
	if (state == 58 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -71;
	}
	if (state == 58 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -71;
	}
	if (state == 58 && window.at(0) == Tokens::NUMBER_SIGN::id) {
		return -71;
	}
	if (state == 58 && window.at(0) == Tokens::SEMICOLON::id) {
		return -71;
	}
	if (state == 58 && window.at(0) == Tokens::modules::common::ID::id) {
		return -71;
	}
	if (state == 58 && window.at(0) == Tokens::modules::common::NUMBER::id) {
		return -71;
	}
	if (state == 58 && window.at(0) == Tokens::modules::ispa_dep_scanner::fail_decl::FAIL::id) {
		return -71;
	}
	if (state == 58 && window.at(0) == Tokens::modules::ispa_dep_scanner::mod_detach::DETACH::id) {
		return -71;
	}
	if (state == 58 && window.at(0) == Tokens::modules::ispa_dep_scanner::mod_module::MODULE::id) {
		return -71;
	}
	if (state == 58 && window.at(0) == Tokens::modules::scanner_tokens::CGROUP::id) {
		return -71;
	}
	if (state == 58 && window.at(0) == Tokens::modules::scanner_tokens::COMMENT::id) {
		return -71;
	}
	if (state == 58 && window.at(0) == Tokens::modules::scanner_tokens::OTHER::id) {
		return -71;
	}
	if (state == 58 && window.at(0) == Tokens::modules::scanner_tokens::PY_RAW::id) {
		return -71;
	}
	if (state == 58 && window.at(0) == Tokens::modules::scanner_tokens::STRING::id) {
		return -71;
	}
	if (state == 59 && window.at(0) == static_cast<std::size_t>(-1)) {
		return -54;
	}
	if (state == 59 && window.at(0) == Tokens::ASTERISK::id) {
		return -54;
	}
	if (state == 59 && window.at(0) == Tokens::AUTO::id) {
		return -54;
	}
	if (state == 59 && window.at(0) == Tokens::COLON::id) {
		return -54;
	}
	if (state == 59 && window.at(0) == Tokens::COMMA::id) {
		return -54;
	}
	if (state == 59 && window.at(0) == Tokens::FEATURE::id) {
		return -54;
	}
	if (state == 59 && window.at(0) == Tokens::FULL_STOP::id) {
		return -54;
	}
	if (state == 59 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -54;
	}
	if (state == 59 && window.at(0) == Tokens::IMPORT::id) {
		return -54;
	}
	if (state == 59 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -54;
	}
	if (state == 59 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -54;
	}
	if (state == 59 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -54;
	}
	if (state == 59 && window.at(0) == Tokens::NUMBER_SIGN::id) {
		return -54;
	}
	if (state == 59 && window.at(0) == Tokens::SEMICOLON::id) {
		return -54;
	}
	if (state == 59 && window.at(0) == Tokens::modules::common::ID::id) {
		return -54;
	}
	if (state == 59 && window.at(0) == Tokens::modules::common::NUMBER::id) {
		return -54;
	}
	if (state == 59 && window.at(0) == Tokens::modules::ispa_dep_scanner::fail_decl::FAIL::id) {
		return -54;
	}
	if (state == 59 && window.at(0) == Tokens::modules::ispa_dep_scanner::mod_detach::DETACH::id) {
		return -54;
	}
	if (state == 59 && window.at(0) == Tokens::modules::ispa_dep_scanner::mod_module::MODULE::id) {
		return -54;
	}
	if (state == 59 && window.at(0) == Tokens::modules::scanner_tokens::CGROUP::id) {
		return -54;
	}
	if (state == 59 && window.at(0) == Tokens::modules::scanner_tokens::COMMENT::id) {
		return -54;
	}
	if (state == 59 && window.at(0) == Tokens::modules::scanner_tokens::OTHER::id) {
		return -54;
	}
	if (state == 59 && window.at(0) == Tokens::modules::scanner_tokens::PY_RAW::id) {
		return -54;
	}
	if (state == 59 && window.at(0) == Tokens::modules::scanner_tokens::STRING::id) {
		return -54;
	}
	if (state == 60 && window.at(0) == static_cast<std::size_t>(-1)) {
		return -55;
	}
	if (state == 60 && window.at(0) == Tokens::ASTERISK::id) {
		return -55;
	}
	if (state == 60 && window.at(0) == Tokens::AUTO::id) {
		return -55;
	}
	if (state == 60 && window.at(0) == Tokens::COLON::id) {
		return -55;
	}
	if (state == 60 && window.at(0) == Tokens::COMMA::id) {
		return -55;
	}
	if (state == 60 && window.at(0) == Tokens::FEATURE::id) {
		return -55;
	}
	if (state == 60 && window.at(0) == Tokens::FULL_STOP::id) {
		return -55;
	}
	if (state == 60 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -55;
	}
	if (state == 60 && window.at(0) == Tokens::IMPORT::id) {
		return -55;
	}
	if (state == 60 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -55;
	}
	if (state == 60 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -55;
	}
	if (state == 60 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -55;
	}
	if (state == 60 && window.at(0) == Tokens::NUMBER_SIGN::id) {
		return -55;
	}
	if (state == 60 && window.at(0) == Tokens::SEMICOLON::id) {
		return -55;
	}
	if (state == 60 && window.at(0) == Tokens::modules::common::ID::id) {
		return -55;
	}
	if (state == 60 && window.at(0) == Tokens::modules::common::NUMBER::id) {
		return -55;
	}
	if (state == 60 && window.at(0) == Tokens::modules::ispa_dep_scanner::fail_decl::FAIL::id) {
		return -55;
	}
	if (state == 60 && window.at(0) == Tokens::modules::ispa_dep_scanner::mod_detach::DETACH::id) {
		return -55;
	}
	if (state == 60 && window.at(0) == Tokens::modules::ispa_dep_scanner::mod_module::MODULE::id) {
		return -55;
	}
	if (state == 60 && window.at(0) == Tokens::modules::scanner_tokens::CGROUP::id) {
		return -55;
	}
	if (state == 60 && window.at(0) == Tokens::modules::scanner_tokens::COMMENT::id) {
		return -55;
	}
	if (state == 60 && window.at(0) == Tokens::modules::scanner_tokens::OTHER::id) {
		return -55;
	}
	if (state == 60 && window.at(0) == Tokens::modules::scanner_tokens::PY_RAW::id) {
		return -55;
	}
	if (state == 60 && window.at(0) == Tokens::modules::scanner_tokens::STRING::id) {
		return -55;
	}
	if (state == 61 && window.at(0) == static_cast<std::size_t>(-1)) {
		return -72;
	}
	if (state == 61 && window.at(0) == Tokens::FEATURE::id) {
		return -72;
	}
	if (state == 61 && window.at(0) == Tokens::IMPORT::id) {
		return -72;
	}
	if (state == 61 && window.at(0) == Tokens::NUMBER_SIGN::id) {
		return -72;
	}
	if (state == 61 && window.at(0) == Tokens::modules::common::ID::id) {
		return -72;
	}
	if (state == 61 && window.at(0) == Tokens::modules::ispa_dep_scanner::fail_decl::FAIL::id) {
		return -72;
	}
	if (state == 61 && window.at(0) == Tokens::modules::ispa_dep_scanner::mod_detach::DETACH::id) {
		return -72;
	}
	if (state == 61 && window.at(0) == Tokens::modules::ispa_dep_scanner::mod_module::MODULE::id) {
		return -72;
	}
	if (state == 61 && window.at(0) == Tokens::modules::scanner_tokens::COMMENT::id) {
		return -72;
	}
	if (state == 62 && window.at(0) == Tokens::SEMICOLON::id) {
		return -83;
	}
	if (state == 63 && window.at(0) == static_cast<std::size_t>(-1)) {
		return -80;
	}
	if (state == 63 && window.at(0) == Tokens::FEATURE::id) {
		return -80;
	}
	if (state == 63 && window.at(0) == Tokens::IMPORT::id) {
		return -80;
	}
	if (state == 63 && window.at(0) == Tokens::NUMBER_SIGN::id) {
		return -80;
	}
	if (state == 63 && window.at(0) == Tokens::modules::common::ID::id) {
		return -80;
	}
	if (state == 63 && window.at(0) == Tokens::modules::ispa_dep_scanner::fail_decl::FAIL::id) {
		return -80;
	}
	if (state == 63 && window.at(0) == Tokens::modules::ispa_dep_scanner::mod_detach::DETACH::id) {
		return -80;
	}
	if (state == 63 && window.at(0) == Tokens::modules::ispa_dep_scanner::mod_module::MODULE::id) {
		return -80;
	}
	if (state == 63 && window.at(0) == Tokens::modules::scanner_tokens::COMMENT::id) {
		return -80;
	}
	if (state == 64 && window.at(0) == Tokens::modules::common::ID::id) {
		return 113;
	}
	if (state == 65 && window.at(0) == Tokens::AS::id) {
		return -110;
	}
	if (state == 65 && window.at(0) == Tokens::AUTO::id) {
		return -110;
	}
	if (state == 65 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -110;
	}
	if (state == 65 && window.at(0) == Tokens::SEMICOLON::id) {
		return -110;
	}
	if (state == 66 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -20;
	}
	if (state == 66 && window.at(0) == Tokens::modules::common::ID::id) {
		return 114;
	}
	if (state == 67 && window.at(0) == Tokens::AUTO::id) {
		return -105;
	}
	if (state == 67 && window.at(0) == Tokens::SEMICOLON::id) {
		return -105;
	}
	if (state == 68 && window.at(0) == Tokens::AUTO::id) {
		return 117;
	}
	if (state == 68 && window.at(0) == Tokens::SEMICOLON::id) {
		return -102;
	}
	if (state == 69 && window.at(0) == Tokens::modules::common::ID::id) {
		return -70;
	}
	if (state == 70 && window.at(0) == Tokens::COLON::id) {
		return -5;
	}
	if (state == 70 && window.at(0) == Tokens::COMMA::id) {
		return -5;
	}
	if (state == 70 && window.at(0) == Tokens::FULL_STOP::id) {
		return 119;
	}
	if (state == 70 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -5;
	}
	if (state == 70 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -5;
	}
	if (state == 70 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -5;
	}
	if (state == 70 && window.at(0) == Tokens::RIGHT_CURLY_BRACKET::id) {
		return -5;
	}
	if (state == 70 && window.at(0) == Tokens::SEMICOLON::id) {
		return -5;
	}
	if (state == 71 && window.at(0) == Tokens::COLON::id) {
		return -9;
	}
	if (state == 71 && window.at(0) == Tokens::COMMA::id) {
		return -9;
	}
	if (state == 71 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return 121;
	}
	if (state == 71 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -9;
	}
	if (state == 71 && window.at(0) == Tokens::RIGHT_CURLY_BRACKET::id) {
		return -9;
	}
	if (state == 71 && window.at(0) == Tokens::SEMICOLON::id) {
		return -9;
	}
	if (state == 72 && window.at(0) == Tokens::COLON::id) {
		return -8;
	}
	if (state == 72 && window.at(0) == Tokens::COMMA::id) {
		return -8;
	}
	if (state == 72 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -8;
	}
	if (state == 72 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -8;
	}
	if (state == 72 && window.at(0) == Tokens::RIGHT_CURLY_BRACKET::id) {
		return -8;
	}
	if (state == 72 && window.at(0) == Tokens::SEMICOLON::id) {
		return -8;
	}
	if (state == 73 && window.at(0) == Tokens::RIGHT_CURLY_BRACKET::id) {
		return 124;
	}
	if (state == 74 && window.at(0) == Tokens::COMMA::id) {
		return 125;
	}
	if (state == 74 && window.at(0) == Tokens::RIGHT_CURLY_BRACKET::id) {
		return -123;
	}
	if (state == 75 && window.at(0) == Tokens::RIGHT_CURLY_BRACKET::id) {
		return -75;
	}
	if (state == 76 && window.at(0) == Tokens::COMMA::id) {
		return 127;
	}
	if (state == 76 && window.at(0) == Tokens::RIGHT_CURLY_BRACKET::id) {
		return -94;
	}
	if (state == 77 && window.at(0) == static_cast<std::size_t>(-1)) {
		return -84;
	}
	if (state == 77 && window.at(0) == Tokens::FEATURE::id) {
		return -84;
	}
	if (state == 77 && window.at(0) == Tokens::IMPORT::id) {
		return -84;
	}
	if (state == 77 && window.at(0) == Tokens::NUMBER_SIGN::id) {
		return -84;
	}
	if (state == 77 && window.at(0) == Tokens::modules::common::ID::id) {
		return -84;
	}
	if (state == 77 && window.at(0) == Tokens::modules::ispa_dep_scanner::fail_decl::FAIL::id) {
		return -84;
	}
	if (state == 77 && window.at(0) == Tokens::modules::ispa_dep_scanner::mod_detach::DETACH::id) {
		return -84;
	}
	if (state == 77 && window.at(0) == Tokens::modules::ispa_dep_scanner::mod_module::MODULE::id) {
		return -84;
	}
	if (state == 77 && window.at(0) == Tokens::modules::scanner_tokens::COMMENT::id) {
		return -84;
	}
	if (state == 78 && window.at(0) == Tokens::modules::common::ID::id) {
		return 39;
	}
	if (state == 79 && window.at(0) == Tokens::modules::common::ID::id) {
		return 130;
	}
	if (state == 80 && window.at(0) == Tokens::SEMICOLON::id) {
		return -98;
	}
	if (state == 81 && window.at(0) == Tokens::modules::common::ID::id) {
		return 131;
	}
	if (state == 82 && window.at(0) == Tokens::SEMICOLON::id) {
		return 132;
	}
	if (state == 83 && window.at(0) == Tokens::ASTERISK::id) {
		return -48;
	}
	if (state == 83 && window.at(0) == Tokens::AUTO::id) {
		return -48;
	}
	if (state == 83 && window.at(0) == Tokens::COLON::id) {
		return -48;
	}
	if (state == 83 && window.at(0) == Tokens::COMMA::id) {
		return -48;
	}
	if (state == 83 && window.at(0) == Tokens::FULL_STOP::id) {
		return -48;
	}
	if (state == 83 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -48;
	}
	if (state == 83 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -48;
	}
	if (state == 83 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -48;
	}
	if (state == 83 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -48;
	}
	if (state == 83 && window.at(0) == Tokens::NUMBER_SIGN::id) {
		return -48;
	}
	if (state == 83 && window.at(0) == Tokens::RIGHT_CURLY_BRACKET::id) {
		return -48;
	}
	if (state == 83 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -48;
	}
	if (state == 83 && window.at(0) == Tokens::SEMICOLON::id) {
		return -48;
	}
	if (state == 83 && window.at(0) == Tokens::modules::common::ID::id) {
		return -48;
	}
	if (state == 83 && window.at(0) == Tokens::modules::common::NUMBER::id) {
		return -48;
	}
	if (state == 83 && window.at(0) == Tokens::modules::scanner_tokens::CGROUP::id) {
		return -48;
	}
	if (state == 83 && window.at(0) == Tokens::modules::scanner_tokens::COMMENT::id) {
		return -48;
	}
	if (state == 83 && window.at(0) == Tokens::modules::scanner_tokens::OTHER::id) {
		return -48;
	}
	if (state == 83 && window.at(0) == Tokens::modules::scanner_tokens::PY_RAW::id) {
		return -48;
	}
	if (state == 83 && window.at(0) == Tokens::modules::scanner_tokens::STRING::id) {
		return -48;
	}
	if (state == 84 && window.at(0) == Tokens::ASTERISK::id) {
		return -42;
	}
	if (state == 84 && window.at(0) == Tokens::AUTO::id) {
		return -42;
	}
	if (state == 84 && window.at(0) == Tokens::COLON::id) {
		return -42;
	}
	if (state == 84 && window.at(0) == Tokens::COMMA::id) {
		return -42;
	}
	if (state == 84 && window.at(0) == Tokens::FULL_STOP::id) {
		return -42;
	}
	if (state == 84 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -42;
	}
	if (state == 84 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -42;
	}
	if (state == 84 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -42;
	}
	if (state == 84 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -42;
	}
	if (state == 84 && window.at(0) == Tokens::NUMBER_SIGN::id) {
		return -42;
	}
	if (state == 84 && window.at(0) == Tokens::RIGHT_CURLY_BRACKET::id) {
		return -42;
	}
	if (state == 84 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -42;
	}
	if (state == 84 && window.at(0) == Tokens::SEMICOLON::id) {
		return -42;
	}
	if (state == 84 && window.at(0) == Tokens::modules::common::ID::id) {
		return -42;
	}
	if (state == 84 && window.at(0) == Tokens::modules::common::NUMBER::id) {
		return -42;
	}
	if (state == 84 && window.at(0) == Tokens::modules::scanner_tokens::CGROUP::id) {
		return -42;
	}
	if (state == 84 && window.at(0) == Tokens::modules::scanner_tokens::COMMENT::id) {
		return -42;
	}
	if (state == 84 && window.at(0) == Tokens::modules::scanner_tokens::OTHER::id) {
		return -42;
	}
	if (state == 84 && window.at(0) == Tokens::modules::scanner_tokens::PY_RAW::id) {
		return -42;
	}
	if (state == 84 && window.at(0) == Tokens::modules::scanner_tokens::STRING::id) {
		return -42;
	}
	if (state == 85 && window.at(0) == Tokens::ASTERISK::id) {
		return -47;
	}
	if (state == 85 && window.at(0) == Tokens::AUTO::id) {
		return -47;
	}
	if (state == 85 && window.at(0) == Tokens::COLON::id) {
		return -47;
	}
	if (state == 85 && window.at(0) == Tokens::COMMA::id) {
		return -47;
	}
	if (state == 85 && window.at(0) == Tokens::FULL_STOP::id) {
		return -47;
	}
	if (state == 85 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -47;
	}
	if (state == 85 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -47;
	}
	if (state == 85 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -47;
	}
	if (state == 85 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -47;
	}
	if (state == 85 && window.at(0) == Tokens::NUMBER_SIGN::id) {
		return -47;
	}
	if (state == 85 && window.at(0) == Tokens::RIGHT_CURLY_BRACKET::id) {
		return -47;
	}
	if (state == 85 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -47;
	}
	if (state == 85 && window.at(0) == Tokens::SEMICOLON::id) {
		return -47;
	}
	if (state == 85 && window.at(0) == Tokens::modules::common::ID::id) {
		return -47;
	}
	if (state == 85 && window.at(0) == Tokens::modules::common::NUMBER::id) {
		return -47;
	}
	if (state == 85 && window.at(0) == Tokens::modules::scanner_tokens::CGROUP::id) {
		return -47;
	}
	if (state == 85 && window.at(0) == Tokens::modules::scanner_tokens::COMMENT::id) {
		return -47;
	}
	if (state == 85 && window.at(0) == Tokens::modules::scanner_tokens::OTHER::id) {
		return -47;
	}
	if (state == 85 && window.at(0) == Tokens::modules::scanner_tokens::PY_RAW::id) {
		return -47;
	}
	if (state == 85 && window.at(0) == Tokens::modules::scanner_tokens::STRING::id) {
		return -47;
	}
	if (state == 86 && window.at(0) == Tokens::ASTERISK::id) {
		return -43;
	}
	if (state == 86 && window.at(0) == Tokens::AUTO::id) {
		return -43;
	}
	if (state == 86 && window.at(0) == Tokens::COLON::id) {
		return -43;
	}
	if (state == 86 && window.at(0) == Tokens::COMMA::id) {
		return -43;
	}
	if (state == 86 && window.at(0) == Tokens::FULL_STOP::id) {
		return -43;
	}
	if (state == 86 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -43;
	}
	if (state == 86 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -43;
	}
	if (state == 86 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -43;
	}
	if (state == 86 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -43;
	}
	if (state == 86 && window.at(0) == Tokens::NUMBER_SIGN::id) {
		return -43;
	}
	if (state == 86 && window.at(0) == Tokens::RIGHT_CURLY_BRACKET::id) {
		return -43;
	}
	if (state == 86 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -43;
	}
	if (state == 86 && window.at(0) == Tokens::SEMICOLON::id) {
		return -43;
	}
	if (state == 86 && window.at(0) == Tokens::modules::common::ID::id) {
		return -43;
	}
	if (state == 86 && window.at(0) == Tokens::modules::common::NUMBER::id) {
		return -43;
	}
	if (state == 86 && window.at(0) == Tokens::modules::scanner_tokens::CGROUP::id) {
		return -43;
	}
	if (state == 86 && window.at(0) == Tokens::modules::scanner_tokens::COMMENT::id) {
		return -43;
	}
	if (state == 86 && window.at(0) == Tokens::modules::scanner_tokens::OTHER::id) {
		return -43;
	}
	if (state == 86 && window.at(0) == Tokens::modules::scanner_tokens::PY_RAW::id) {
		return -43;
	}
	if (state == 86 && window.at(0) == Tokens::modules::scanner_tokens::STRING::id) {
		return -43;
	}
	if (state == 87 && window.at(0) == Tokens::ASTERISK::id) {
		return -44;
	}
	if (state == 87 && window.at(0) == Tokens::AUTO::id) {
		return -44;
	}
	if (state == 87 && window.at(0) == Tokens::COLON::id) {
		return -44;
	}
	if (state == 87 && window.at(0) == Tokens::COMMA::id) {
		return -44;
	}
	if (state == 87 && window.at(0) == Tokens::FULL_STOP::id) {
		return -44;
	}
	if (state == 87 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -44;
	}
	if (state == 87 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -44;
	}
	if (state == 87 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -44;
	}
	if (state == 87 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -44;
	}
	if (state == 87 && window.at(0) == Tokens::NUMBER_SIGN::id) {
		return -44;
	}
	if (state == 87 && window.at(0) == Tokens::RIGHT_CURLY_BRACKET::id) {
		return -44;
	}
	if (state == 87 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -44;
	}
	if (state == 87 && window.at(0) == Tokens::SEMICOLON::id) {
		return -44;
	}
	if (state == 87 && window.at(0) == Tokens::modules::common::ID::id) {
		return -44;
	}
	if (state == 87 && window.at(0) == Tokens::modules::common::NUMBER::id) {
		return -44;
	}
	if (state == 87 && window.at(0) == Tokens::modules::scanner_tokens::CGROUP::id) {
		return -44;
	}
	if (state == 87 && window.at(0) == Tokens::modules::scanner_tokens::COMMENT::id) {
		return -44;
	}
	if (state == 87 && window.at(0) == Tokens::modules::scanner_tokens::OTHER::id) {
		return -44;
	}
	if (state == 87 && window.at(0) == Tokens::modules::scanner_tokens::PY_RAW::id) {
		return -44;
	}
	if (state == 87 && window.at(0) == Tokens::modules::scanner_tokens::STRING::id) {
		return -44;
	}
	if (state == 88 && window.at(0) == Tokens::ASTERISK::id) {
		return -46;
	}
	if (state == 88 && window.at(0) == Tokens::AUTO::id) {
		return -46;
	}
	if (state == 88 && window.at(0) == Tokens::COLON::id) {
		return -46;
	}
	if (state == 88 && window.at(0) == Tokens::COMMA::id) {
		return -46;
	}
	if (state == 88 && window.at(0) == Tokens::FULL_STOP::id) {
		return -46;
	}
	if (state == 88 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -46;
	}
	if (state == 88 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -46;
	}
	if (state == 88 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -46;
	}
	if (state == 88 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -46;
	}
	if (state == 88 && window.at(0) == Tokens::NUMBER_SIGN::id) {
		return -46;
	}
	if (state == 88 && window.at(0) == Tokens::RIGHT_CURLY_BRACKET::id) {
		return -46;
	}
	if (state == 88 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -46;
	}
	if (state == 88 && window.at(0) == Tokens::SEMICOLON::id) {
		return -46;
	}
	if (state == 88 && window.at(0) == Tokens::modules::common::ID::id) {
		return -46;
	}
	if (state == 88 && window.at(0) == Tokens::modules::common::NUMBER::id) {
		return -46;
	}
	if (state == 88 && window.at(0) == Tokens::modules::scanner_tokens::CGROUP::id) {
		return -46;
	}
	if (state == 88 && window.at(0) == Tokens::modules::scanner_tokens::COMMENT::id) {
		return -46;
	}
	if (state == 88 && window.at(0) == Tokens::modules::scanner_tokens::OTHER::id) {
		return -46;
	}
	if (state == 88 && window.at(0) == Tokens::modules::scanner_tokens::PY_RAW::id) {
		return -46;
	}
	if (state == 88 && window.at(0) == Tokens::modules::scanner_tokens::STRING::id) {
		return -46;
	}
	if (state == 89 && window.at(0) == Tokens::ASTERISK::id) {
		return 84;
	}
	if (state == 89 && window.at(0) == Tokens::AUTO::id) {
		return 85;
	}
	if (state == 89 && window.at(0) == Tokens::COLON::id) {
		return 86;
	}
	if (state == 89 && window.at(0) == Tokens::COMMA::id) {
		return 87;
	}
	if (state == 89 && window.at(0) == Tokens::FULL_STOP::id) {
		return 88;
	}
	if (state == 89 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return 89;
	}
	if (state == 89 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return 58;
	}
	if (state == 89 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return 90;
	}
	if (state == 89 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return 91;
	}
	if (state == 89 && window.at(0) == Tokens::NUMBER_SIGN::id) {
		return 106;
	}
	if (state == 89 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -117;
	}
	if (state == 89 && window.at(0) == Tokens::SEMICOLON::id) {
		return 107;
	}
	if (state == 89 && window.at(0) == Tokens::modules::common::ID::id) {
		return 93;
	}
	if (state == 89 && window.at(0) == Tokens::modules::common::NUMBER::id) {
		return 94;
	}
	if (state == 89 && window.at(0) == Tokens::modules::scanner_tokens::CGROUP::id) {
		return 101;
	}
	if (state == 89 && window.at(0) == Tokens::modules::scanner_tokens::COMMENT::id) {
		return 102;
	}
	if (state == 89 && window.at(0) == Tokens::modules::scanner_tokens::OTHER::id) {
		return 103;
	}
	if (state == 89 && window.at(0) == Tokens::modules::scanner_tokens::PY_RAW::id) {
		return 104;
	}
	if (state == 89 && window.at(0) == Tokens::modules::scanner_tokens::STRING::id) {
		return 105;
	}
	if (state == 90 && window.at(0) == Tokens::ASTERISK::id) {
		return -45;
	}
	if (state == 90 && window.at(0) == Tokens::AUTO::id) {
		return -45;
	}
	if (state == 90 && window.at(0) == Tokens::COLON::id) {
		return -45;
	}
	if (state == 90 && window.at(0) == Tokens::COMMA::id) {
		return -45;
	}
	if (state == 90 && window.at(0) == Tokens::FULL_STOP::id) {
		return -45;
	}
	if (state == 90 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -45;
	}
	if (state == 90 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -45;
	}
	if (state == 90 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -45;
	}
	if (state == 90 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -45;
	}
	if (state == 90 && window.at(0) == Tokens::NUMBER_SIGN::id) {
		return -45;
	}
	if (state == 90 && window.at(0) == Tokens::RIGHT_CURLY_BRACKET::id) {
		return -45;
	}
	if (state == 90 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -45;
	}
	if (state == 90 && window.at(0) == Tokens::SEMICOLON::id) {
		return -45;
	}
	if (state == 90 && window.at(0) == Tokens::modules::common::ID::id) {
		return -45;
	}
	if (state == 90 && window.at(0) == Tokens::modules::common::NUMBER::id) {
		return -45;
	}
	if (state == 90 && window.at(0) == Tokens::modules::scanner_tokens::CGROUP::id) {
		return -45;
	}
	if (state == 90 && window.at(0) == Tokens::modules::scanner_tokens::COMMENT::id) {
		return -45;
	}
	if (state == 90 && window.at(0) == Tokens::modules::scanner_tokens::OTHER::id) {
		return -45;
	}
	if (state == 90 && window.at(0) == Tokens::modules::scanner_tokens::PY_RAW::id) {
		return -45;
	}
	if (state == 90 && window.at(0) == Tokens::modules::scanner_tokens::STRING::id) {
		return -45;
	}
	if (state == 91 && window.at(0) == Tokens::NUMBER_SIGN::id) {
		return 4;
	}
	if (state == 91 && window.at(0) == Tokens::modules::common::ID::id) {
		return -67;
	}
	if (state == 92 && window.at(0) == Tokens::ASTERISK::id) {
		return -35;
	}
	if (state == 92 && window.at(0) == Tokens::AUTO::id) {
		return -35;
	}
	if (state == 92 && window.at(0) == Tokens::COLON::id) {
		return -35;
	}
	if (state == 92 && window.at(0) == Tokens::COMMA::id) {
		return -35;
	}
	if (state == 92 && window.at(0) == Tokens::FULL_STOP::id) {
		return -35;
	}
	if (state == 92 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -35;
	}
	if (state == 92 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -35;
	}
	if (state == 92 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -35;
	}
	if (state == 92 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -35;
	}
	if (state == 92 && window.at(0) == Tokens::NUMBER_SIGN::id) {
		return -35;
	}
	if (state == 92 && window.at(0) == Tokens::RIGHT_CURLY_BRACKET::id) {
		return -35;
	}
	if (state == 92 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -35;
	}
	if (state == 92 && window.at(0) == Tokens::SEMICOLON::id) {
		return -35;
	}
	if (state == 92 && window.at(0) == Tokens::modules::common::ID::id) {
		return -35;
	}
	if (state == 92 && window.at(0) == Tokens::modules::common::NUMBER::id) {
		return -35;
	}
	if (state == 92 && window.at(0) == Tokens::modules::scanner_tokens::CGROUP::id) {
		return -35;
	}
	if (state == 92 && window.at(0) == Tokens::modules::scanner_tokens::COMMENT::id) {
		return -35;
	}
	if (state == 92 && window.at(0) == Tokens::modules::scanner_tokens::OTHER::id) {
		return -35;
	}
	if (state == 92 && window.at(0) == Tokens::modules::scanner_tokens::PY_RAW::id) {
		return -35;
	}
	if (state == 92 && window.at(0) == Tokens::modules::scanner_tokens::STRING::id) {
		return -35;
	}
	if (state == 93 && window.at(0) == Tokens::ASTERISK::id) {
		return -36;
	}
	if (state == 93 && window.at(0) == Tokens::AUTO::id) {
		return -36;
	}
	if (state == 93 && window.at(0) == Tokens::COLON::id) {
		return -36;
	}
	if (state == 93 && window.at(0) == Tokens::COMMA::id) {
		return -36;
	}
	if (state == 93 && window.at(0) == Tokens::FULL_STOP::id) {
		return -36;
	}
	if (state == 93 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -36;
	}
	if (state == 93 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -36;
	}
	if (state == 93 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -36;
	}
	if (state == 93 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -36;
	}
	if (state == 93 && window.at(0) == Tokens::NUMBER_SIGN::id) {
		return -36;
	}
	if (state == 93 && window.at(0) == Tokens::RIGHT_CURLY_BRACKET::id) {
		return -36;
	}
	if (state == 93 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -36;
	}
	if (state == 93 && window.at(0) == Tokens::SEMICOLON::id) {
		return -36;
	}
	if (state == 93 && window.at(0) == Tokens::modules::common::ID::id) {
		return -36;
	}
	if (state == 93 && window.at(0) == Tokens::modules::common::NUMBER::id) {
		return -36;
	}
	if (state == 93 && window.at(0) == Tokens::modules::scanner_tokens::CGROUP::id) {
		return -36;
	}
	if (state == 93 && window.at(0) == Tokens::modules::scanner_tokens::COMMENT::id) {
		return -36;
	}
	if (state == 93 && window.at(0) == Tokens::modules::scanner_tokens::OTHER::id) {
		return -36;
	}
	if (state == 93 && window.at(0) == Tokens::modules::scanner_tokens::PY_RAW::id) {
		return -36;
	}
	if (state == 93 && window.at(0) == Tokens::modules::scanner_tokens::STRING::id) {
		return -36;
	}
	if (state == 94 && window.at(0) == Tokens::ASTERISK::id) {
		return -79;
	}
	if (state == 94 && window.at(0) == Tokens::AUTO::id) {
		return -79;
	}
	if (state == 94 && window.at(0) == Tokens::COLON::id) {
		return -79;
	}
	if (state == 94 && window.at(0) == Tokens::COMMA::id) {
		return -79;
	}
	if (state == 94 && window.at(0) == Tokens::FULL_STOP::id) {
		return -79;
	}
	if (state == 94 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -79;
	}
	if (state == 94 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -79;
	}
	if (state == 94 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -79;
	}
	if (state == 94 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -79;
	}
	if (state == 94 && window.at(0) == Tokens::NUMBER_SIGN::id) {
		return -79;
	}
	if (state == 94 && window.at(0) == Tokens::SEMICOLON::id) {
		return -79;
	}
	if (state == 94 && window.at(0) == Tokens::modules::common::ID::id) {
		return -79;
	}
	if (state == 94 && window.at(0) == Tokens::modules::common::NUMBER::id) {
		return -79;
	}
	if (state == 94 && window.at(0) == Tokens::modules::scanner_tokens::CGROUP::id) {
		return -79;
	}
	if (state == 94 && window.at(0) == Tokens::modules::scanner_tokens::COMMENT::id) {
		return -79;
	}
	if (state == 94 && window.at(0) == Tokens::modules::scanner_tokens::OTHER::id) {
		return -79;
	}
	if (state == 94 && window.at(0) == Tokens::modules::scanner_tokens::PY_RAW::id) {
		return -79;
	}
	if (state == 94 && window.at(0) == Tokens::modules::scanner_tokens::STRING::id) {
		return -79;
	}
	if (state == 95 && window.at(0) == Tokens::SEMICOLON::id) {
		return 136;
	}
	if (state == 96 && window.at(0) == Tokens::ASTERISK::id) {
		return -78;
	}
	if (state == 96 && window.at(0) == Tokens::AUTO::id) {
		return -78;
	}
	if (state == 96 && window.at(0) == Tokens::COLON::id) {
		return -78;
	}
	if (state == 96 && window.at(0) == Tokens::COMMA::id) {
		return -78;
	}
	if (state == 96 && window.at(0) == Tokens::FULL_STOP::id) {
		return -78;
	}
	if (state == 96 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -78;
	}
	if (state == 96 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -78;
	}
	if (state == 96 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -78;
	}
	if (state == 96 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -78;
	}
	if (state == 96 && window.at(0) == Tokens::NUMBER_SIGN::id) {
		return -78;
	}
	if (state == 96 && window.at(0) == Tokens::SEMICOLON::id) {
		return -78;
	}
	if (state == 96 && window.at(0) == Tokens::modules::common::ID::id) {
		return -78;
	}
	if (state == 96 && window.at(0) == Tokens::modules::common::NUMBER::id) {
		return -78;
	}
	if (state == 96 && window.at(0) == Tokens::modules::scanner_tokens::CGROUP::id) {
		return -78;
	}
	if (state == 96 && window.at(0) == Tokens::modules::scanner_tokens::COMMENT::id) {
		return -78;
	}
	if (state == 96 && window.at(0) == Tokens::modules::scanner_tokens::OTHER::id) {
		return -78;
	}
	if (state == 96 && window.at(0) == Tokens::modules::scanner_tokens::PY_RAW::id) {
		return -78;
	}
	if (state == 96 && window.at(0) == Tokens::modules::scanner_tokens::STRING::id) {
		return -78;
	}
	if (state == 97 && window.at(0) == Tokens::ASTERISK::id) {
		return 84;
	}
	if (state == 97 && window.at(0) == Tokens::AUTO::id) {
		return 85;
	}
	if (state == 97 && window.at(0) == Tokens::COLON::id) {
		return 86;
	}
	if (state == 97 && window.at(0) == Tokens::COMMA::id) {
		return 87;
	}
	if (state == 97 && window.at(0) == Tokens::FULL_STOP::id) {
		return 88;
	}
	if (state == 97 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return 89;
	}
	if (state == 97 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return 58;
	}
	if (state == 97 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return 90;
	}
	if (state == 97 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return 91;
	}
	if (state == 97 && window.at(0) == Tokens::NUMBER_SIGN::id) {
		return 92;
	}
	if (state == 97 && window.at(0) == Tokens::SEMICOLON::id) {
		return -59;
	}
	if (state == 97 && window.at(0) == Tokens::modules::common::ID::id) {
		return 93;
	}
	if (state == 97 && window.at(0) == Tokens::modules::common::NUMBER::id) {
		return 94;
	}
	if (state == 97 && window.at(0) == Tokens::modules::scanner_tokens::CGROUP::id) {
		return 101;
	}
	if (state == 97 && window.at(0) == Tokens::modules::scanner_tokens::COMMENT::id) {
		return 102;
	}
	if (state == 97 && window.at(0) == Tokens::modules::scanner_tokens::OTHER::id) {
		return 103;
	}
	if (state == 97 && window.at(0) == Tokens::modules::scanner_tokens::PY_RAW::id) {
		return 104;
	}
	if (state == 97 && window.at(0) == Tokens::modules::scanner_tokens::STRING::id) {
		return 105;
	}
	if (state == 98 && window.at(0) == Tokens::ASTERISK::id) {
		return -76;
	}
	if (state == 98 && window.at(0) == Tokens::AUTO::id) {
		return -76;
	}
	if (state == 98 && window.at(0) == Tokens::COLON::id) {
		return -76;
	}
	if (state == 98 && window.at(0) == Tokens::COMMA::id) {
		return -76;
	}
	if (state == 98 && window.at(0) == Tokens::FULL_STOP::id) {
		return -76;
	}
	if (state == 98 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -76;
	}
	if (state == 98 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -76;
	}
	if (state == 98 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -76;
	}
	if (state == 98 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -76;
	}
	if (state == 98 && window.at(0) == Tokens::NUMBER_SIGN::id) {
		return -76;
	}
	if (state == 98 && window.at(0) == Tokens::SEMICOLON::id) {
		return -76;
	}
	if (state == 98 && window.at(0) == Tokens::modules::common::ID::id) {
		return -76;
	}
	if (state == 98 && window.at(0) == Tokens::modules::common::NUMBER::id) {
		return -76;
	}
	if (state == 98 && window.at(0) == Tokens::modules::scanner_tokens::CGROUP::id) {
		return -76;
	}
	if (state == 98 && window.at(0) == Tokens::modules::scanner_tokens::COMMENT::id) {
		return -76;
	}
	if (state == 98 && window.at(0) == Tokens::modules::scanner_tokens::OTHER::id) {
		return -76;
	}
	if (state == 98 && window.at(0) == Tokens::modules::scanner_tokens::PY_RAW::id) {
		return -76;
	}
	if (state == 98 && window.at(0) == Tokens::modules::scanner_tokens::STRING::id) {
		return -76;
	}
	if (state == 99 && window.at(0) == Tokens::ASTERISK::id) {
		return -77;
	}
	if (state == 99 && window.at(0) == Tokens::AUTO::id) {
		return -77;
	}
	if (state == 99 && window.at(0) == Tokens::COLON::id) {
		return -77;
	}
	if (state == 99 && window.at(0) == Tokens::COMMA::id) {
		return -77;
	}
	if (state == 99 && window.at(0) == Tokens::FULL_STOP::id) {
		return -77;
	}
	if (state == 99 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -77;
	}
	if (state == 99 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -77;
	}
	if (state == 99 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -77;
	}
	if (state == 99 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -77;
	}
	if (state == 99 && window.at(0) == Tokens::NUMBER_SIGN::id) {
		return -77;
	}
	if (state == 99 && window.at(0) == Tokens::SEMICOLON::id) {
		return -77;
	}
	if (state == 99 && window.at(0) == Tokens::modules::common::ID::id) {
		return -77;
	}
	if (state == 99 && window.at(0) == Tokens::modules::common::NUMBER::id) {
		return -77;
	}
	if (state == 99 && window.at(0) == Tokens::modules::scanner_tokens::CGROUP::id) {
		return -77;
	}
	if (state == 99 && window.at(0) == Tokens::modules::scanner_tokens::COMMENT::id) {
		return -77;
	}
	if (state == 99 && window.at(0) == Tokens::modules::scanner_tokens::OTHER::id) {
		return -77;
	}
	if (state == 99 && window.at(0) == Tokens::modules::scanner_tokens::PY_RAW::id) {
		return -77;
	}
	if (state == 99 && window.at(0) == Tokens::modules::scanner_tokens::STRING::id) {
		return -77;
	}
	if (state == 100 && window.at(0) == Tokens::ASTERISK::id) {
		return -38;
	}
	if (state == 100 && window.at(0) == Tokens::AUTO::id) {
		return -38;
	}
	if (state == 100 && window.at(0) == Tokens::COLON::id) {
		return -38;
	}
	if (state == 100 && window.at(0) == Tokens::COMMA::id) {
		return -38;
	}
	if (state == 100 && window.at(0) == Tokens::FULL_STOP::id) {
		return -38;
	}
	if (state == 100 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -38;
	}
	if (state == 100 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -38;
	}
	if (state == 100 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -38;
	}
	if (state == 100 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -38;
	}
	if (state == 100 && window.at(0) == Tokens::NUMBER_SIGN::id) {
		return -38;
	}
	if (state == 100 && window.at(0) == Tokens::RIGHT_CURLY_BRACKET::id) {
		return -38;
	}
	if (state == 100 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -38;
	}
	if (state == 100 && window.at(0) == Tokens::SEMICOLON::id) {
		return -38;
	}
	if (state == 100 && window.at(0) == Tokens::modules::common::ID::id) {
		return -38;
	}
	if (state == 100 && window.at(0) == Tokens::modules::common::NUMBER::id) {
		return -38;
	}
	if (state == 100 && window.at(0) == Tokens::modules::scanner_tokens::CGROUP::id) {
		return -38;
	}
	if (state == 100 && window.at(0) == Tokens::modules::scanner_tokens::COMMENT::id) {
		return -38;
	}
	if (state == 100 && window.at(0) == Tokens::modules::scanner_tokens::OTHER::id) {
		return -38;
	}
	if (state == 100 && window.at(0) == Tokens::modules::scanner_tokens::PY_RAW::id) {
		return -38;
	}
	if (state == 100 && window.at(0) == Tokens::modules::scanner_tokens::STRING::id) {
		return -38;
	}
	if (state == 101 && window.at(0) == Tokens::ASTERISK::id) {
		return -40;
	}
	if (state == 101 && window.at(0) == Tokens::AUTO::id) {
		return -40;
	}
	if (state == 101 && window.at(0) == Tokens::COLON::id) {
		return -40;
	}
	if (state == 101 && window.at(0) == Tokens::COMMA::id) {
		return -40;
	}
	if (state == 101 && window.at(0) == Tokens::FULL_STOP::id) {
		return -40;
	}
	if (state == 101 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -40;
	}
	if (state == 101 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -40;
	}
	if (state == 101 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -40;
	}
	if (state == 101 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -40;
	}
	if (state == 101 && window.at(0) == Tokens::NUMBER_SIGN::id) {
		return -40;
	}
	if (state == 101 && window.at(0) == Tokens::RIGHT_CURLY_BRACKET::id) {
		return -40;
	}
	if (state == 101 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -40;
	}
	if (state == 101 && window.at(0) == Tokens::SEMICOLON::id) {
		return -40;
	}
	if (state == 101 && window.at(0) == Tokens::modules::common::ID::id) {
		return -40;
	}
	if (state == 101 && window.at(0) == Tokens::modules::common::NUMBER::id) {
		return -40;
	}
	if (state == 101 && window.at(0) == Tokens::modules::scanner_tokens::CGROUP::id) {
		return -40;
	}
	if (state == 101 && window.at(0) == Tokens::modules::scanner_tokens::COMMENT::id) {
		return -40;
	}
	if (state == 101 && window.at(0) == Tokens::modules::scanner_tokens::OTHER::id) {
		return -40;
	}
	if (state == 101 && window.at(0) == Tokens::modules::scanner_tokens::PY_RAW::id) {
		return -40;
	}
	if (state == 101 && window.at(0) == Tokens::modules::scanner_tokens::STRING::id) {
		return -40;
	}
	if (state == 102 && window.at(0) == Tokens::ASTERISK::id) {
		return -41;
	}
	if (state == 102 && window.at(0) == Tokens::AUTO::id) {
		return -41;
	}
	if (state == 102 && window.at(0) == Tokens::COLON::id) {
		return -41;
	}
	if (state == 102 && window.at(0) == Tokens::COMMA::id) {
		return -41;
	}
	if (state == 102 && window.at(0) == Tokens::FULL_STOP::id) {
		return -41;
	}
	if (state == 102 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -41;
	}
	if (state == 102 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -41;
	}
	if (state == 102 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -41;
	}
	if (state == 102 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -41;
	}
	if (state == 102 && window.at(0) == Tokens::NUMBER_SIGN::id) {
		return -41;
	}
	if (state == 102 && window.at(0) == Tokens::RIGHT_CURLY_BRACKET::id) {
		return -41;
	}
	if (state == 102 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -41;
	}
	if (state == 102 && window.at(0) == Tokens::SEMICOLON::id) {
		return -41;
	}
	if (state == 102 && window.at(0) == Tokens::modules::common::ID::id) {
		return -41;
	}
	if (state == 102 && window.at(0) == Tokens::modules::common::NUMBER::id) {
		return -41;
	}
	if (state == 102 && window.at(0) == Tokens::modules::scanner_tokens::CGROUP::id) {
		return -41;
	}
	if (state == 102 && window.at(0) == Tokens::modules::scanner_tokens::COMMENT::id) {
		return -41;
	}
	if (state == 102 && window.at(0) == Tokens::modules::scanner_tokens::OTHER::id) {
		return -41;
	}
	if (state == 102 && window.at(0) == Tokens::modules::scanner_tokens::PY_RAW::id) {
		return -41;
	}
	if (state == 102 && window.at(0) == Tokens::modules::scanner_tokens::STRING::id) {
		return -41;
	}
	if (state == 103 && window.at(0) == Tokens::ASTERISK::id) {
		return -39;
	}
	if (state == 103 && window.at(0) == Tokens::AUTO::id) {
		return -39;
	}
	if (state == 103 && window.at(0) == Tokens::COLON::id) {
		return -39;
	}
	if (state == 103 && window.at(0) == Tokens::COMMA::id) {
		return -39;
	}
	if (state == 103 && window.at(0) == Tokens::FULL_STOP::id) {
		return -39;
	}
	if (state == 103 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -39;
	}
	if (state == 103 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -39;
	}
	if (state == 103 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -39;
	}
	if (state == 103 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -39;
	}
	if (state == 103 && window.at(0) == Tokens::NUMBER_SIGN::id) {
		return -39;
	}
	if (state == 103 && window.at(0) == Tokens::RIGHT_CURLY_BRACKET::id) {
		return -39;
	}
	if (state == 103 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -39;
	}
	if (state == 103 && window.at(0) == Tokens::SEMICOLON::id) {
		return -39;
	}
	if (state == 103 && window.at(0) == Tokens::modules::common::ID::id) {
		return -39;
	}
	if (state == 103 && window.at(0) == Tokens::modules::common::NUMBER::id) {
		return -39;
	}
	if (state == 103 && window.at(0) == Tokens::modules::scanner_tokens::CGROUP::id) {
		return -39;
	}
	if (state == 103 && window.at(0) == Tokens::modules::scanner_tokens::COMMENT::id) {
		return -39;
	}
	if (state == 103 && window.at(0) == Tokens::modules::scanner_tokens::OTHER::id) {
		return -39;
	}
	if (state == 103 && window.at(0) == Tokens::modules::scanner_tokens::PY_RAW::id) {
		return -39;
	}
	if (state == 103 && window.at(0) == Tokens::modules::scanner_tokens::STRING::id) {
		return -39;
	}
	if (state == 104 && window.at(0) == Tokens::ASTERISK::id) {
		return -37;
	}
	if (state == 104 && window.at(0) == Tokens::AUTO::id) {
		return -37;
	}
	if (state == 104 && window.at(0) == Tokens::COLON::id) {
		return -37;
	}
	if (state == 104 && window.at(0) == Tokens::COMMA::id) {
		return -37;
	}
	if (state == 104 && window.at(0) == Tokens::FULL_STOP::id) {
		return -37;
	}
	if (state == 104 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -37;
	}
	if (state == 104 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -37;
	}
	if (state == 104 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -37;
	}
	if (state == 104 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -37;
	}
	if (state == 104 && window.at(0) == Tokens::NUMBER_SIGN::id) {
		return -37;
	}
	if (state == 104 && window.at(0) == Tokens::RIGHT_CURLY_BRACKET::id) {
		return -37;
	}
	if (state == 104 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -37;
	}
	if (state == 104 && window.at(0) == Tokens::SEMICOLON::id) {
		return -37;
	}
	if (state == 104 && window.at(0) == Tokens::modules::common::ID::id) {
		return -37;
	}
	if (state == 104 && window.at(0) == Tokens::modules::common::NUMBER::id) {
		return -37;
	}
	if (state == 104 && window.at(0) == Tokens::modules::scanner_tokens::CGROUP::id) {
		return -37;
	}
	if (state == 104 && window.at(0) == Tokens::modules::scanner_tokens::COMMENT::id) {
		return -37;
	}
	if (state == 104 && window.at(0) == Tokens::modules::scanner_tokens::OTHER::id) {
		return -37;
	}
	if (state == 104 && window.at(0) == Tokens::modules::scanner_tokens::PY_RAW::id) {
		return -37;
	}
	if (state == 104 && window.at(0) == Tokens::modules::scanner_tokens::STRING::id) {
		return -37;
	}
	if (state == 105 && window.at(0) == Tokens::ASTERISK::id) {
		return -53;
	}
	if (state == 105 && window.at(0) == Tokens::AUTO::id) {
		return -53;
	}
	if (state == 105 && window.at(0) == Tokens::COLON::id) {
		return -53;
	}
	if (state == 105 && window.at(0) == Tokens::COMMA::id) {
		return -53;
	}
	if (state == 105 && window.at(0) == Tokens::FULL_STOP::id) {
		return -53;
	}
	if (state == 105 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -53;
	}
	if (state == 105 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -53;
	}
	if (state == 105 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -53;
	}
	if (state == 105 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -53;
	}
	if (state == 105 && window.at(0) == Tokens::NUMBER_SIGN::id) {
		return -53;
	}
	if (state == 105 && window.at(0) == Tokens::RIGHT_CURLY_BRACKET::id) {
		return -53;
	}
	if (state == 105 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -53;
	}
	if (state == 105 && window.at(0) == Tokens::SEMICOLON::id) {
		return -53;
	}
	if (state == 105 && window.at(0) == Tokens::modules::common::ID::id) {
		return -53;
	}
	if (state == 105 && window.at(0) == Tokens::modules::common::NUMBER::id) {
		return -53;
	}
	if (state == 105 && window.at(0) == Tokens::modules::scanner_tokens::CGROUP::id) {
		return -53;
	}
	if (state == 105 && window.at(0) == Tokens::modules::scanner_tokens::COMMENT::id) {
		return -53;
	}
	if (state == 105 && window.at(0) == Tokens::modules::scanner_tokens::OTHER::id) {
		return -53;
	}
	if (state == 105 && window.at(0) == Tokens::modules::scanner_tokens::PY_RAW::id) {
		return -53;
	}
	if (state == 105 && window.at(0) == Tokens::modules::scanner_tokens::STRING::id) {
		return -53;
	}
	if (state == 106 && window.at(0) == Tokens::ASTERISK::id) {
		return -52;
	}
	if (state == 106 && window.at(0) == Tokens::AUTO::id) {
		return -52;
	}
	if (state == 106 && window.at(0) == Tokens::COLON::id) {
		return -52;
	}
	if (state == 106 && window.at(0) == Tokens::COMMA::id) {
		return -52;
	}
	if (state == 106 && window.at(0) == Tokens::FULL_STOP::id) {
		return -52;
	}
	if (state == 106 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -52;
	}
	if (state == 106 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -52;
	}
	if (state == 106 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -52;
	}
	if (state == 106 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -52;
	}
	if (state == 106 && window.at(0) == Tokens::NUMBER_SIGN::id) {
		return -52;
	}
	if (state == 106 && window.at(0) == Tokens::RIGHT_CURLY_BRACKET::id) {
		return -52;
	}
	if (state == 106 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -52;
	}
	if (state == 106 && window.at(0) == Tokens::SEMICOLON::id) {
		return -52;
	}
	if (state == 106 && window.at(0) == Tokens::modules::common::ID::id) {
		return -52;
	}
	if (state == 106 && window.at(0) == Tokens::modules::common::NUMBER::id) {
		return -52;
	}
	if (state == 106 && window.at(0) == Tokens::modules::scanner_tokens::CGROUP::id) {
		return -52;
	}
	if (state == 106 && window.at(0) == Tokens::modules::scanner_tokens::COMMENT::id) {
		return -52;
	}
	if (state == 106 && window.at(0) == Tokens::modules::scanner_tokens::OTHER::id) {
		return -52;
	}
	if (state == 106 && window.at(0) == Tokens::modules::scanner_tokens::PY_RAW::id) {
		return -52;
	}
	if (state == 106 && window.at(0) == Tokens::modules::scanner_tokens::STRING::id) {
		return -52;
	}
	if (state == 107 && window.at(0) == Tokens::ASTERISK::id) {
		return -51;
	}
	if (state == 107 && window.at(0) == Tokens::AUTO::id) {
		return -51;
	}
	if (state == 107 && window.at(0) == Tokens::COLON::id) {
		return -51;
	}
	if (state == 107 && window.at(0) == Tokens::COMMA::id) {
		return -51;
	}
	if (state == 107 && window.at(0) == Tokens::FULL_STOP::id) {
		return -51;
	}
	if (state == 107 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -51;
	}
	if (state == 107 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -51;
	}
	if (state == 107 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -51;
	}
	if (state == 107 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -51;
	}
	if (state == 107 && window.at(0) == Tokens::NUMBER_SIGN::id) {
		return -51;
	}
	if (state == 107 && window.at(0) == Tokens::RIGHT_CURLY_BRACKET::id) {
		return -51;
	}
	if (state == 107 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -51;
	}
	if (state == 107 && window.at(0) == Tokens::SEMICOLON::id) {
		return -51;
	}
	if (state == 107 && window.at(0) == Tokens::modules::common::ID::id) {
		return -51;
	}
	if (state == 107 && window.at(0) == Tokens::modules::common::NUMBER::id) {
		return -51;
	}
	if (state == 107 && window.at(0) == Tokens::modules::scanner_tokens::CGROUP::id) {
		return -51;
	}
	if (state == 107 && window.at(0) == Tokens::modules::scanner_tokens::COMMENT::id) {
		return -51;
	}
	if (state == 107 && window.at(0) == Tokens::modules::scanner_tokens::OTHER::id) {
		return -51;
	}
	if (state == 107 && window.at(0) == Tokens::modules::scanner_tokens::PY_RAW::id) {
		return -51;
	}
	if (state == 107 && window.at(0) == Tokens::modules::scanner_tokens::STRING::id) {
		return -51;
	}
	if (state == 108 && window.at(0) == Tokens::ASTERISK::id) {
		return 84;
	}
	if (state == 108 && window.at(0) == Tokens::AUTO::id) {
		return 85;
	}
	if (state == 108 && window.at(0) == Tokens::COLON::id) {
		return 86;
	}
	if (state == 108 && window.at(0) == Tokens::COMMA::id) {
		return 87;
	}
	if (state == 108 && window.at(0) == Tokens::FULL_STOP::id) {
		return 88;
	}
	if (state == 108 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return 89;
	}
	if (state == 108 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return 58;
	}
	if (state == 108 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return 90;
	}
	if (state == 108 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return 91;
	}
	if (state == 108 && window.at(0) == Tokens::NUMBER_SIGN::id) {
		return 106;
	}
	if (state == 108 && window.at(0) == Tokens::RIGHT_CURLY_BRACKET::id) {
		return -64;
	}
	if (state == 108 && window.at(0) == Tokens::SEMICOLON::id) {
		return 107;
	}
	if (state == 108 && window.at(0) == Tokens::modules::common::ID::id) {
		return 93;
	}
	if (state == 108 && window.at(0) == Tokens::modules::common::NUMBER::id) {
		return 94;
	}
	if (state == 108 && window.at(0) == Tokens::modules::scanner_tokens::CGROUP::id) {
		return 101;
	}
	if (state == 108 && window.at(0) == Tokens::modules::scanner_tokens::COMMENT::id) {
		return 102;
	}
	if (state == 108 && window.at(0) == Tokens::modules::scanner_tokens::OTHER::id) {
		return 103;
	}
	if (state == 108 && window.at(0) == Tokens::modules::scanner_tokens::PY_RAW::id) {
		return 104;
	}
	if (state == 108 && window.at(0) == Tokens::modules::scanner_tokens::STRING::id) {
		return 105;
	}
	if (state == 109 && window.at(0) == Tokens::ASTERISK::id) {
		return -50;
	}
	if (state == 109 && window.at(0) == Tokens::AUTO::id) {
		return -50;
	}
	if (state == 109 && window.at(0) == Tokens::COLON::id) {
		return -50;
	}
	if (state == 109 && window.at(0) == Tokens::COMMA::id) {
		return -50;
	}
	if (state == 109 && window.at(0) == Tokens::FULL_STOP::id) {
		return -50;
	}
	if (state == 109 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -50;
	}
	if (state == 109 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -50;
	}
	if (state == 109 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -50;
	}
	if (state == 109 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -50;
	}
	if (state == 109 && window.at(0) == Tokens::NUMBER_SIGN::id) {
		return -50;
	}
	if (state == 109 && window.at(0) == Tokens::RIGHT_CURLY_BRACKET::id) {
		return -50;
	}
	if (state == 109 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -50;
	}
	if (state == 109 && window.at(0) == Tokens::SEMICOLON::id) {
		return -50;
	}
	if (state == 109 && window.at(0) == Tokens::modules::common::ID::id) {
		return -50;
	}
	if (state == 109 && window.at(0) == Tokens::modules::common::NUMBER::id) {
		return -50;
	}
	if (state == 109 && window.at(0) == Tokens::modules::scanner_tokens::CGROUP::id) {
		return -50;
	}
	if (state == 109 && window.at(0) == Tokens::modules::scanner_tokens::COMMENT::id) {
		return -50;
	}
	if (state == 109 && window.at(0) == Tokens::modules::scanner_tokens::OTHER::id) {
		return -50;
	}
	if (state == 109 && window.at(0) == Tokens::modules::scanner_tokens::PY_RAW::id) {
		return -50;
	}
	if (state == 109 && window.at(0) == Tokens::modules::scanner_tokens::STRING::id) {
		return -50;
	}
	if (state == 110 && window.at(0) == Tokens::RIGHT_CURLY_BRACKET::id) {
		return 141;
	}
	if (state == 111 && window.at(0) == Tokens::ASTERISK::id) {
		return -49;
	}
	if (state == 111 && window.at(0) == Tokens::AUTO::id) {
		return -49;
	}
	if (state == 111 && window.at(0) == Tokens::COLON::id) {
		return -49;
	}
	if (state == 111 && window.at(0) == Tokens::COMMA::id) {
		return -49;
	}
	if (state == 111 && window.at(0) == Tokens::FULL_STOP::id) {
		return -49;
	}
	if (state == 111 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -49;
	}
	if (state == 111 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -49;
	}
	if (state == 111 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -49;
	}
	if (state == 111 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -49;
	}
	if (state == 111 && window.at(0) == Tokens::NUMBER_SIGN::id) {
		return -49;
	}
	if (state == 111 && window.at(0) == Tokens::RIGHT_CURLY_BRACKET::id) {
		return -49;
	}
	if (state == 111 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -49;
	}
	if (state == 111 && window.at(0) == Tokens::SEMICOLON::id) {
		return -49;
	}
	if (state == 111 && window.at(0) == Tokens::modules::common::ID::id) {
		return -49;
	}
	if (state == 111 && window.at(0) == Tokens::modules::common::NUMBER::id) {
		return -49;
	}
	if (state == 111 && window.at(0) == Tokens::modules::scanner_tokens::CGROUP::id) {
		return -49;
	}
	if (state == 111 && window.at(0) == Tokens::modules::scanner_tokens::COMMENT::id) {
		return -49;
	}
	if (state == 111 && window.at(0) == Tokens::modules::scanner_tokens::OTHER::id) {
		return -49;
	}
	if (state == 111 && window.at(0) == Tokens::modules::scanner_tokens::PY_RAW::id) {
		return -49;
	}
	if (state == 111 && window.at(0) == Tokens::modules::scanner_tokens::STRING::id) {
		return -49;
	}
	if (state == 112 && window.at(0) == Tokens::AS::id) {
		return -113;
	}
	if (state == 112 && window.at(0) == Tokens::AUTO::id) {
		return -113;
	}
	if (state == 112 && window.at(0) == Tokens::FULL_STOP::id) {
		return 142;
	}
	if (state == 112 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -113;
	}
	if (state == 112 && window.at(0) == Tokens::SEMICOLON::id) {
		return -113;
	}
	if (state == 113 && window.at(0) == Tokens::COMMA::id) {
		return 144;
	}
	if (state == 113 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -12;
	}
	if (state == 113 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -12;
	}
	if (state == 114 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -21;
	}
	if (state == 115 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return 146;
	}
	if (state == 116 && window.at(0) == Tokens::modules::common::ID::id) {
		return 22;
	}
	if (state == 117 && window.at(0) == Tokens::SEMICOLON::id) {
		return 148;
	}
	if (state == 118 && window.at(0) == Tokens::modules::common::ID::id) {
		return 149;
	}
	if (state == 119 && window.at(0) == Tokens::COLON::id) {
		return -4;
	}
	if (state == 119 && window.at(0) == Tokens::COMMA::id) {
		return -4;
	}
	if (state == 119 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -4;
	}
	if (state == 119 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -4;
	}
	if (state == 119 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -4;
	}
	if (state == 119 && window.at(0) == Tokens::RIGHT_CURLY_BRACKET::id) {
		return -4;
	}
	if (state == 119 && window.at(0) == Tokens::SEMICOLON::id) {
		return -4;
	}
	if (state == 120 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return 150;
	}
	if (state == 121 && window.at(0) == Tokens::COLON::id) {
		return -2;
	}
	if (state == 121 && window.at(0) == Tokens::COMMA::id) {
		return -2;
	}
	if (state == 121 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -2;
	}
	if (state == 121 && window.at(0) == Tokens::RIGHT_CURLY_BRACKET::id) {
		return -2;
	}
	if (state == 121 && window.at(0) == Tokens::SEMICOLON::id) {
		return -2;
	}
	if (state == 122 && window.at(0) == Tokens::COLON::id) {
		return -10;
	}
	if (state == 122 && window.at(0) == Tokens::COMMA::id) {
		return -10;
	}
	if (state == 122 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -10;
	}
	if (state == 122 && window.at(0) == Tokens::RIGHT_CURLY_BRACKET::id) {
		return -10;
	}
	if (state == 122 && window.at(0) == Tokens::SEMICOLON::id) {
		return -10;
	}
	if (state == 123 && window.at(0) == Tokens::SEMICOLON::id) {
		return 151;
	}
	if (state == 124 && window.at(0) == Tokens::modules::common::ID::id) {
		return 22;
	}
	if (state == 125 && window.at(0) == Tokens::RIGHT_CURLY_BRACKET::id) {
		return -122;
	}
	if (state == 126 && window.at(0) == Tokens::modules::common::ID::id) {
		return 22;
	}
	if (state == 127 && window.at(0) == Tokens::RIGHT_CURLY_BRACKET::id) {
		return 154;
	}
	if (state == 128 && window.at(0) == Tokens::SEMICOLON::id) {
		return -90;
	}
	if (state == 129 && window.at(0) == Tokens::SEMICOLON::id) {
		return -100;
	}
	if (state == 130 && window.at(0) == Tokens::SEMICOLON::id) {
		return -108;
	}
	if (state == 131 && window.at(0) == static_cast<std::size_t>(-1)) {
		return -106;
	}
	if (state == 131 && window.at(0) == Tokens::FEATURE::id) {
		return -106;
	}
	if (state == 131 && window.at(0) == Tokens::IMPORT::id) {
		return -106;
	}
	if (state == 131 && window.at(0) == Tokens::NUMBER_SIGN::id) {
		return -106;
	}
	if (state == 131 && window.at(0) == Tokens::modules::common::ID::id) {
		return -106;
	}
	if (state == 131 && window.at(0) == Tokens::modules::ispa_dep_scanner::fail_decl::FAIL::id) {
		return -106;
	}
	if (state == 131 && window.at(0) == Tokens::modules::ispa_dep_scanner::mod_detach::DETACH::id) {
		return -106;
	}
	if (state == 131 && window.at(0) == Tokens::modules::ispa_dep_scanner::mod_module::MODULE::id) {
		return -106;
	}
	if (state == 131 && window.at(0) == Tokens::modules::scanner_tokens::COMMENT::id) {
		return -106;
	}
	if (state == 132 && window.at(0) == Tokens::ASTERISK::id) {
		return 84;
	}
	if (state == 132 && window.at(0) == Tokens::AUTO::id) {
		return 85;
	}
	if (state == 132 && window.at(0) == Tokens::COLON::id) {
		return 86;
	}
	if (state == 132 && window.at(0) == Tokens::COMMA::id) {
		return 87;
	}
	if (state == 132 && window.at(0) == Tokens::FULL_STOP::id) {
		return 88;
	}
	if (state == 132 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return 89;
	}
	if (state == 132 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return 58;
	}
	if (state == 132 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return 90;
	}
	if (state == 132 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return 91;
	}
	if (state == 132 && window.at(0) == Tokens::NUMBER_SIGN::id) {
		return 106;
	}
	if (state == 132 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -119;
	}
	if (state == 132 && window.at(0) == Tokens::SEMICOLON::id) {
		return 107;
	}
	if (state == 132 && window.at(0) == Tokens::modules::common::ID::id) {
		return 93;
	}
	if (state == 132 && window.at(0) == Tokens::modules::common::NUMBER::id) {
		return 94;
	}
	if (state == 132 && window.at(0) == Tokens::modules::scanner_tokens::CGROUP::id) {
		return 101;
	}
	if (state == 132 && window.at(0) == Tokens::modules::scanner_tokens::COMMENT::id) {
		return 102;
	}
	if (state == 132 && window.at(0) == Tokens::modules::scanner_tokens::OTHER::id) {
		return 103;
	}
	if (state == 132 && window.at(0) == Tokens::modules::scanner_tokens::PY_RAW::id) {
		return 104;
	}
	if (state == 132 && window.at(0) == Tokens::modules::scanner_tokens::STRING::id) {
		return 105;
	}
	if (state == 133 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return 157;
	}
	if (state == 134 && window.at(0) == Tokens::ASTERISK::id) {
		return -115;
	}
	if (state == 134 && window.at(0) == Tokens::AUTO::id) {
		return -115;
	}
	if (state == 134 && window.at(0) == Tokens::COLON::id) {
		return -115;
	}
	if (state == 134 && window.at(0) == Tokens::COMMA::id) {
		return -115;
	}
	if (state == 134 && window.at(0) == Tokens::FULL_STOP::id) {
		return -115;
	}
	if (state == 134 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -115;
	}
	if (state == 134 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -115;
	}
	if (state == 134 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -115;
	}
	if (state == 134 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -115;
	}
	if (state == 134 && window.at(0) == Tokens::NUMBER_SIGN::id) {
		return -115;
	}
	if (state == 134 && window.at(0) == Tokens::SEMICOLON::id) {
		return -115;
	}
	if (state == 134 && window.at(0) == Tokens::modules::common::ID::id) {
		return -115;
	}
	if (state == 134 && window.at(0) == Tokens::modules::common::NUMBER::id) {
		return -115;
	}
	if (state == 134 && window.at(0) == Tokens::modules::scanner_tokens::CGROUP::id) {
		return -115;
	}
	if (state == 134 && window.at(0) == Tokens::modules::scanner_tokens::COMMENT::id) {
		return -115;
	}
	if (state == 134 && window.at(0) == Tokens::modules::scanner_tokens::OTHER::id) {
		return -115;
	}
	if (state == 134 && window.at(0) == Tokens::modules::scanner_tokens::PY_RAW::id) {
		return -115;
	}
	if (state == 134 && window.at(0) == Tokens::modules::scanner_tokens::STRING::id) {
		return -115;
	}
	if (state == 135 && window.at(0) == static_cast<std::size_t>(-1)) {
		return -56;
	}
	if (state == 135 && window.at(0) == Tokens::ASTERISK::id) {
		return -56;
	}
	if (state == 135 && window.at(0) == Tokens::AUTO::id) {
		return -56;
	}
	if (state == 135 && window.at(0) == Tokens::COLON::id) {
		return -56;
	}
	if (state == 135 && window.at(0) == Tokens::COMMA::id) {
		return -56;
	}
	if (state == 135 && window.at(0) == Tokens::FEATURE::id) {
		return -56;
	}
	if (state == 135 && window.at(0) == Tokens::FULL_STOP::id) {
		return -56;
	}
	if (state == 135 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -56;
	}
	if (state == 135 && window.at(0) == Tokens::IMPORT::id) {
		return -56;
	}
	if (state == 135 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -56;
	}
	if (state == 135 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -56;
	}
	if (state == 135 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -56;
	}
	if (state == 135 && window.at(0) == Tokens::NUMBER_SIGN::id) {
		return -56;
	}
	if (state == 135 && window.at(0) == Tokens::SEMICOLON::id) {
		return -56;
	}
	if (state == 135 && window.at(0) == Tokens::modules::common::ID::id) {
		return -56;
	}
	if (state == 135 && window.at(0) == Tokens::modules::common::NUMBER::id) {
		return -56;
	}
	if (state == 135 && window.at(0) == Tokens::modules::ispa_dep_scanner::fail_decl::FAIL::id) {
		return -56;
	}
	if (state == 135 && window.at(0) == Tokens::modules::ispa_dep_scanner::mod_detach::DETACH::id) {
		return -56;
	}
	if (state == 135 && window.at(0) == Tokens::modules::ispa_dep_scanner::mod_module::MODULE::id) {
		return -56;
	}
	if (state == 135 && window.at(0) == Tokens::modules::scanner_tokens::CGROUP::id) {
		return -56;
	}
	if (state == 135 && window.at(0) == Tokens::modules::scanner_tokens::COMMENT::id) {
		return -56;
	}
	if (state == 135 && window.at(0) == Tokens::modules::scanner_tokens::OTHER::id) {
		return -56;
	}
	if (state == 135 && window.at(0) == Tokens::modules::scanner_tokens::PY_RAW::id) {
		return -56;
	}
	if (state == 135 && window.at(0) == Tokens::modules::scanner_tokens::STRING::id) {
		return -56;
	}
	if (state == 136 && window.at(0) == Tokens::SEMICOLON::id) {
		return -58;
	}
	if (state == 137 && window.at(0) == Tokens::ASTERISK::id) {
		return 84;
	}
	if (state == 137 && window.at(0) == Tokens::AUTO::id) {
		return 85;
	}
	if (state == 137 && window.at(0) == Tokens::COLON::id) {
		return 86;
	}
	if (state == 137 && window.at(0) == Tokens::COMMA::id) {
		return 87;
	}
	if (state == 137 && window.at(0) == Tokens::FULL_STOP::id) {
		return 88;
	}
	if (state == 137 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return 89;
	}
	if (state == 137 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return 58;
	}
	if (state == 137 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return 90;
	}
	if (state == 137 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return 91;
	}
	if (state == 137 && window.at(0) == Tokens::NUMBER_SIGN::id) {
		return 92;
	}
	if (state == 137 && window.at(0) == Tokens::SEMICOLON::id) {
		return -59;
	}
	if (state == 137 && window.at(0) == Tokens::modules::common::ID::id) {
		return 93;
	}
	if (state == 137 && window.at(0) == Tokens::modules::common::NUMBER::id) {
		return 94;
	}
	if (state == 137 && window.at(0) == Tokens::modules::scanner_tokens::CGROUP::id) {
		return 101;
	}
	if (state == 137 && window.at(0) == Tokens::modules::scanner_tokens::COMMENT::id) {
		return 102;
	}
	if (state == 137 && window.at(0) == Tokens::modules::scanner_tokens::OTHER::id) {
		return 103;
	}
	if (state == 137 && window.at(0) == Tokens::modules::scanner_tokens::PY_RAW::id) {
		return 104;
	}
	if (state == 137 && window.at(0) == Tokens::modules::scanner_tokens::STRING::id) {
		return 105;
	}
	if (state == 138 && window.at(0) == Tokens::ASTERISK::id) {
		return 84;
	}
	if (state == 138 && window.at(0) == Tokens::AUTO::id) {
		return 85;
	}
	if (state == 138 && window.at(0) == Tokens::COLON::id) {
		return 86;
	}
	if (state == 138 && window.at(0) == Tokens::COMMA::id) {
		return 87;
	}
	if (state == 138 && window.at(0) == Tokens::FULL_STOP::id) {
		return 88;
	}
	if (state == 138 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return 89;
	}
	if (state == 138 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return 58;
	}
	if (state == 138 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return 90;
	}
	if (state == 138 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return 91;
	}
	if (state == 138 && window.at(0) == Tokens::NUMBER_SIGN::id) {
		return 106;
	}
	if (state == 138 && window.at(0) == Tokens::RIGHT_CURLY_BRACKET::id) {
		return -64;
	}
	if (state == 138 && window.at(0) == Tokens::SEMICOLON::id) {
		return 107;
	}
	if (state == 138 && window.at(0) == Tokens::modules::common::ID::id) {
		return 93;
	}
	if (state == 138 && window.at(0) == Tokens::modules::common::NUMBER::id) {
		return 94;
	}
	if (state == 138 && window.at(0) == Tokens::modules::scanner_tokens::CGROUP::id) {
		return 101;
	}
	if (state == 138 && window.at(0) == Tokens::modules::scanner_tokens::COMMENT::id) {
		return 102;
	}
	if (state == 138 && window.at(0) == Tokens::modules::scanner_tokens::OTHER::id) {
		return 103;
	}
	if (state == 138 && window.at(0) == Tokens::modules::scanner_tokens::PY_RAW::id) {
		return 104;
	}
	if (state == 138 && window.at(0) == Tokens::modules::scanner_tokens::STRING::id) {
		return 105;
	}
	if (state == 139 && window.at(0) == Tokens::RIGHT_CURLY_BRACKET::id) {
		return -63;
	}
	if (state == 140 && window.at(0) == static_cast<std::size_t>(-1)) {
		return -61;
	}
	if (state == 140 && window.at(0) == Tokens::ASTERISK::id) {
		return -61;
	}
	if (state == 140 && window.at(0) == Tokens::AUTO::id) {
		return -61;
	}
	if (state == 140 && window.at(0) == Tokens::COLON::id) {
		return -61;
	}
	if (state == 140 && window.at(0) == Tokens::COMMA::id) {
		return -61;
	}
	if (state == 140 && window.at(0) == Tokens::FEATURE::id) {
		return -61;
	}
	if (state == 140 && window.at(0) == Tokens::FULL_STOP::id) {
		return -61;
	}
	if (state == 140 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -61;
	}
	if (state == 140 && window.at(0) == Tokens::IMPORT::id) {
		return -61;
	}
	if (state == 140 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -61;
	}
	if (state == 140 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -61;
	}
	if (state == 140 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -61;
	}
	if (state == 140 && window.at(0) == Tokens::NUMBER_SIGN::id) {
		return -61;
	}
	if (state == 140 && window.at(0) == Tokens::RIGHT_CURLY_BRACKET::id) {
		return -61;
	}
	if (state == 140 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -61;
	}
	if (state == 140 && window.at(0) == Tokens::SEMICOLON::id) {
		return -61;
	}
	if (state == 140 && window.at(0) == Tokens::modules::common::ID::id) {
		return -61;
	}
	if (state == 140 && window.at(0) == Tokens::modules::common::NUMBER::id) {
		return -61;
	}
	if (state == 140 && window.at(0) == Tokens::modules::ispa_dep_scanner::fail_decl::FAIL::id) {
		return -61;
	}
	if (state == 140 && window.at(0) == Tokens::modules::ispa_dep_scanner::mod_detach::DETACH::id) {
		return -61;
	}
	if (state == 140 && window.at(0) == Tokens::modules::ispa_dep_scanner::mod_module::MODULE::id) {
		return -61;
	}
	if (state == 140 && window.at(0) == Tokens::modules::scanner_tokens::CGROUP::id) {
		return -61;
	}
	if (state == 140 && window.at(0) == Tokens::modules::scanner_tokens::COMMENT::id) {
		return -61;
	}
	if (state == 140 && window.at(0) == Tokens::modules::scanner_tokens::OTHER::id) {
		return -61;
	}
	if (state == 140 && window.at(0) == Tokens::modules::scanner_tokens::PY_RAW::id) {
		return -61;
	}
	if (state == 140 && window.at(0) == Tokens::modules::scanner_tokens::STRING::id) {
		return -61;
	}
	if (state == 141 && window.at(0) == Tokens::modules::common::ID::id) {
		return 160;
	}
	if (state == 142 && window.at(0) == Tokens::AS::id) {
		return -112;
	}
	if (state == 142 && window.at(0) == Tokens::AUTO::id) {
		return -112;
	}
	if (state == 142 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -112;
	}
	if (state == 142 && window.at(0) == Tokens::SEMICOLON::id) {
		return -112;
	}
	if (state == 143 && window.at(0) == Tokens::modules::common::ID::id) {
		return 161;
	}
	if (state == 144 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -11;
	}
	if (state == 144 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -11;
	}
	if (state == 145 && window.at(0) == Tokens::AUTO::id) {
		return -19;
	}
	if (state == 145 && window.at(0) == Tokens::COLON::id) {
		return -19;
	}
	if (state == 145 && window.at(0) == Tokens::COMMA::id) {
		return -19;
	}
	if (state == 145 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -19;
	}
	if (state == 145 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -19;
	}
	if (state == 145 && window.at(0) == Tokens::RIGHT_CURLY_BRACKET::id) {
		return -19;
	}
	if (state == 145 && window.at(0) == Tokens::SEMICOLON::id) {
		return -19;
	}
	if (state == 146 && window.at(0) == Tokens::SEMICOLON::id) {
		return -103;
	}
	if (state == 147 && window.at(0) == static_cast<std::size_t>(-1)) {
		return -101;
	}
	if (state == 147 && window.at(0) == Tokens::FEATURE::id) {
		return -101;
	}
	if (state == 147 && window.at(0) == Tokens::IMPORT::id) {
		return -101;
	}
	if (state == 147 && window.at(0) == Tokens::NUMBER_SIGN::id) {
		return -101;
	}
	if (state == 147 && window.at(0) == Tokens::modules::common::ID::id) {
		return -101;
	}
	if (state == 147 && window.at(0) == Tokens::modules::ispa_dep_scanner::fail_decl::FAIL::id) {
		return -101;
	}
	if (state == 147 && window.at(0) == Tokens::modules::ispa_dep_scanner::mod_detach::DETACH::id) {
		return -101;
	}
	if (state == 147 && window.at(0) == Tokens::modules::ispa_dep_scanner::mod_module::MODULE::id) {
		return -101;
	}
	if (state == 147 && window.at(0) == Tokens::modules::scanner_tokens::COMMENT::id) {
		return -101;
	}
	if (state == 148 && window.at(0) == Tokens::COLON::id) {
		return -5;
	}
	if (state == 148 && window.at(0) == Tokens::COMMA::id) {
		return -5;
	}
	if (state == 148 && window.at(0) == Tokens::FULL_STOP::id) {
		return 119;
	}
	if (state == 148 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -5;
	}
	if (state == 148 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -5;
	}
	if (state == 148 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -5;
	}
	if (state == 148 && window.at(0) == Tokens::RIGHT_CURLY_BRACKET::id) {
		return -5;
	}
	if (state == 148 && window.at(0) == Tokens::SEMICOLON::id) {
		return -5;
	}
	if (state == 149 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -17;
	}
	if (state == 149 && window.at(0) == Tokens::modules::common::ID::id) {
		return 114;
	}
	if (state == 150 && window.at(0) == static_cast<std::size_t>(-1)) {
		return -73;
	}
	if (state == 150 && window.at(0) == Tokens::FEATURE::id) {
		return -73;
	}
	if (state == 150 && window.at(0) == Tokens::IMPORT::id) {
		return -73;
	}
	if (state == 150 && window.at(0) == Tokens::NUMBER_SIGN::id) {
		return -73;
	}
	if (state == 150 && window.at(0) == Tokens::modules::common::ID::id) {
		return -73;
	}
	if (state == 150 && window.at(0) == Tokens::modules::ispa_dep_scanner::fail_decl::FAIL::id) {
		return -73;
	}
	if (state == 150 && window.at(0) == Tokens::modules::ispa_dep_scanner::mod_detach::DETACH::id) {
		return -73;
	}
	if (state == 150 && window.at(0) == Tokens::modules::ispa_dep_scanner::mod_module::MODULE::id) {
		return -73;
	}
	if (state == 150 && window.at(0) == Tokens::modules::scanner_tokens::COMMENT::id) {
		return -73;
	}
	if (state == 151 && window.at(0) == Tokens::COMMA::id) {
		return 165;
	}
	if (state == 151 && window.at(0) == Tokens::RIGHT_CURLY_BRACKET::id) {
		return -125;
	}
	if (state == 152 && window.at(0) == Tokens::COMMA::id) {
		return 167;
	}
	if (state == 152 && window.at(0) == Tokens::RIGHT_CURLY_BRACKET::id) {
		return -96;
	}
	if (state == 153 && window.at(0) == Tokens::modules::ispa_dep_scanner::mod_import::import_value::from_import::FROM::id) {
		return -93;
	}
	if (state == 154 && window.at(0) == Tokens::ASTERISK::id) {
		return 84;
	}
	if (state == 154 && window.at(0) == Tokens::AUTO::id) {
		return 85;
	}
	if (state == 154 && window.at(0) == Tokens::COLON::id) {
		return 86;
	}
	if (state == 154 && window.at(0) == Tokens::COMMA::id) {
		return 87;
	}
	if (state == 154 && window.at(0) == Tokens::FULL_STOP::id) {
		return 88;
	}
	if (state == 154 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return 89;
	}
	if (state == 154 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return 58;
	}
	if (state == 154 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return 90;
	}
	if (state == 154 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return 91;
	}
	if (state == 154 && window.at(0) == Tokens::NUMBER_SIGN::id) {
		return 106;
	}
	if (state == 154 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -119;
	}
	if (state == 154 && window.at(0) == Tokens::SEMICOLON::id) {
		return 107;
	}
	if (state == 154 && window.at(0) == Tokens::modules::common::ID::id) {
		return 93;
	}
	if (state == 154 && window.at(0) == Tokens::modules::common::NUMBER::id) {
		return 94;
	}
	if (state == 154 && window.at(0) == Tokens::modules::scanner_tokens::CGROUP::id) {
		return 101;
	}
	if (state == 154 && window.at(0) == Tokens::modules::scanner_tokens::COMMENT::id) {
		return 102;
	}
	if (state == 154 && window.at(0) == Tokens::modules::scanner_tokens::OTHER::id) {
		return 103;
	}
	if (state == 154 && window.at(0) == Tokens::modules::scanner_tokens::PY_RAW::id) {
		return 104;
	}
	if (state == 154 && window.at(0) == Tokens::modules::scanner_tokens::STRING::id) {
		return 105;
	}
	if (state == 155 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -118;
	}
	if (state == 156 && window.at(0) == Tokens::ASTERISK::id) {
		return -116;
	}
	if (state == 156 && window.at(0) == Tokens::AUTO::id) {
		return -116;
	}
	if (state == 156 && window.at(0) == Tokens::COLON::id) {
		return -116;
	}
	if (state == 156 && window.at(0) == Tokens::COMMA::id) {
		return -116;
	}
	if (state == 156 && window.at(0) == Tokens::FULL_STOP::id) {
		return -116;
	}
	if (state == 156 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -116;
	}
	if (state == 156 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -116;
	}
	if (state == 156 && window.at(0) == Tokens::LEFT_PARENTHESIS::id) {
		return -116;
	}
	if (state == 156 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -116;
	}
	if (state == 156 && window.at(0) == Tokens::NUMBER_SIGN::id) {
		return -116;
	}
	if (state == 156 && window.at(0) == Tokens::RIGHT_CURLY_BRACKET::id) {
		return -116;
	}
	if (state == 156 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -116;
	}
	if (state == 156 && window.at(0) == Tokens::SEMICOLON::id) {
		return -116;
	}
	if (state == 156 && window.at(0) == Tokens::modules::common::ID::id) {
		return -116;
	}
	if (state == 156 && window.at(0) == Tokens::modules::common::NUMBER::id) {
		return -116;
	}
	if (state == 156 && window.at(0) == Tokens::modules::scanner_tokens::CGROUP::id) {
		return -116;
	}
	if (state == 156 && window.at(0) == Tokens::modules::scanner_tokens::COMMENT::id) {
		return -116;
	}
	if (state == 156 && window.at(0) == Tokens::modules::scanner_tokens::OTHER::id) {
		return -116;
	}
	if (state == 156 && window.at(0) == Tokens::modules::scanner_tokens::PY_RAW::id) {
		return -116;
	}
	if (state == 156 && window.at(0) == Tokens::modules::scanner_tokens::STRING::id) {
		return -116;
	}
	if (state == 157 && window.at(0) == Tokens::SEMICOLON::id) {
		return -60;
	}
	if (state == 158 && window.at(0) == Tokens::RIGHT_CURLY_BRACKET::id) {
		return -65;
	}
	if (state == 159 && window.at(0) == Tokens::AS::id) {
		return -113;
	}
	if (state == 159 && window.at(0) == Tokens::AUTO::id) {
		return -113;
	}
	if (state == 159 && window.at(0) == Tokens::FULL_STOP::id) {
		return 142;
	}
	if (state == 159 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -113;
	}
	if (state == 159 && window.at(0) == Tokens::SEMICOLON::id) {
		return -113;
	}
	if (state == 160 && window.at(0) == Tokens::COMMA::id) {
		return 171;
	}
	if (state == 160 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -14;
	}
	if (state == 160 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -14;
	}
	if (state == 161 && window.at(0) == Tokens::COLON::id) {
		return -6;
	}
	if (state == 161 && window.at(0) == Tokens::COMMA::id) {
		return -6;
	}
	if (state == 161 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -6;
	}
	if (state == 161 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -6;
	}
	if (state == 161 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -6;
	}
	if (state == 161 && window.at(0) == Tokens::RIGHT_CURLY_BRACKET::id) {
		return -6;
	}
	if (state == 161 && window.at(0) == Tokens::SEMICOLON::id) {
		return -6;
	}
	if (state == 162 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -18;
	}
	if (state == 163 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return 173;
	}
	if (state == 164 && window.at(0) == Tokens::modules::common::ID::id) {
		return 22;
	}
	if (state == 165 && window.at(0) == Tokens::RIGHT_CURLY_BRACKET::id) {
		return -124;
	}
	if (state == 166 && window.at(0) == Tokens::modules::common::ID::id) {
		return 22;
	}
	if (state == 167 && window.at(0) == Tokens::RIGHT_CURLY_BRACKET::id) {
		return -95;
	}
	if (state == 168 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -120;
	}
	if (state == 169 && window.at(0) == Tokens::AS::id) {
		return -114;
	}
	if (state == 169 && window.at(0) == Tokens::AUTO::id) {
		return -114;
	}
	if (state == 169 && window.at(0) == Tokens::LESS_THAN_SIGN::id) {
		return -114;
	}
	if (state == 169 && window.at(0) == Tokens::SEMICOLON::id) {
		return -114;
	}
	if (state == 170 && window.at(0) == Tokens::modules::common::ID::id) {
		return 176;
	}
	if (state == 171 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -13;
	}
	if (state == 171 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -13;
	}
	if (state == 172 && window.at(0) == Tokens::COLON::id) {
		return -16;
	}
	if (state == 172 && window.at(0) == Tokens::COMMA::id) {
		return -16;
	}
	if (state == 172 && window.at(0) == Tokens::LEFT_CURLY_BRACKET::id) {
		return -16;
	}
	if (state == 172 && window.at(0) == Tokens::RIGHT_CURLY_BRACKET::id) {
		return -16;
	}
	if (state == 172 && window.at(0) == Tokens::SEMICOLON::id) {
		return -16;
	}
	if (state == 173 && window.at(0) == Tokens::COMMA::id) {
		return 165;
	}
	if (state == 173 && window.at(0) == Tokens::RIGHT_CURLY_BRACKET::id) {
		return -125;
	}
	if (state == 174 && window.at(0) == Tokens::COMMA::id) {
		return 167;
	}
	if (state == 174 && window.at(0) == Tokens::RIGHT_CURLY_BRACKET::id) {
		return -96;
	}
	if (state == 175 && window.at(0) == Tokens::COMMA::id) {
		return 171;
	}
	if (state == 175 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -14;
	}
	if (state == 175 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -14;
	}
	if (state == 176 && window.at(0) == Tokens::RIGHT_CURLY_BRACKET::id) {
		return -126;
	}
	if (state == 177 && window.at(0) == Tokens::RIGHT_CURLY_BRACKET::id) {
		return -97;
	}
	if (state == 178 && window.at(0) == Tokens::GREATER_THAN_SIGN::id) {
		return -15;
	}
	if (state == 178 && window.at(0) == Tokens::RIGHT_PARENTHESIS::id) {
		return -15;
	}
	throw std::runtime_error("Invalid LR table entry or unexpected token");
}
auto DepParser::Parser::lr_goto(std::size_t state, std::size_t lhs) -> std::size_t {
	if (state == 174 && lhs == 46) {
		return 177;
	}
	if (state == 166 && lhs == 62) {
		return 174;
	}
	if (state == 166 && lhs == 2) {
		return 22;
	}
	if (state == 164 && lhs == 62) {
		return 173;
	}
	if (state == 164 && lhs == 2) {
		return 22;
	}
	if (state == 160 && lhs == 9) {
		return 171;
	}
	if (state == 159 && lhs == 57) {
		return 169;
	}
	if (state == 152 && lhs == 46) {
		return 167;
	}
	if (state == 52 && lhs == 48) {
		return 80;
	}
	if (state == 149 && lhs == 11) {
		return 163;
	}
	if (state == 149 && lhs == 7) {
		return 162;
	}
	if (state == 29 && lhs == 54) {
		return 19;
	}
	if (state == 29 && lhs == 52) {
		return 18;
	}
	if (state == 29 && lhs == 49) {
		return 16;
	}
	if (state == 29 && lhs == 35) {
		return 13;
	}
	if (state == 29 && lhs == 32) {
		return 12;
	}
	if (state == 29 && lhs == 31) {
		return 10;
	}
	if (state == 29 && lhs == 28) {
		return 9;
	}
	if (state == 29 && lhs == 16) {
		return 29;
	}
	if (state == 29 && lhs == 27) {
		return 8;
	}
	if (state == 29 && lhs == 38) {
		return 15;
	}
	if (state == 29 && lhs == 17) {
		return 55;
	}
	if (state == 126 && lhs == 62) {
		return 152;
	}
	if (state == 126 && lhs == 2) {
		return 22;
	}
	if (state == 27 && lhs == 55) {
		return 54;
	}
	if (state == 124 && lhs == 62) {
		return 151;
	}
	if (state == 124 && lhs == 2) {
		return 22;
	}
	if (state == 19 && lhs == 54) {
		return 41;
	}
	if (state == 19 && lhs == 29) {
		return 40;
	}
	if (state == 116 && lhs == 62) {
		return 146;
	}
	if (state == 116 && lhs == 2) {
		return 22;
	}
	if (state == 112 && lhs == 57) {
		return 142;
	}
	if (state == 0 && lhs == 52) {
		return 18;
	}
	if (state == 0 && lhs == 38) {
		return 15;
	}
	if (state == 0 && lhs == 49) {
		return 16;
	}
	if (state == 0 && lhs == 35) {
		return 13;
	}
	if (state == 0 && lhs == 32) {
		return 12;
	}
	if (state == 0 && lhs == 31) {
		return 10;
	}
	if (state == 0 && lhs == 28) {
		return 9;
	}
	if (state == 0 && lhs == 16) {
		return 7;
	}
	if (state == 0 && lhs == 27) {
		return 8;
	}
	if (state == 0 && lhs == 54) {
		return 19;
	}
	if (state == 0 && lhs == 15) {
		return 6;
	}
	if (state == 0 && lhs == 14) {
		return 5;
	}
	if (state == 0 && lhs == 1) {
		return 4;
	}
	if (state == 97 && lhs == 59) {
		return 99;
	}
	if (state == 97 && lhs == 58) {
		return 98;
	}
	if (state == 97 && lhs == 34) {
		return 137;
	}
	if (state == 97 && lhs == 24) {
		return 96;
	}
	if (state == 97 && lhs == 23) {
		return 136;
	}
	if (state == 97 && lhs == 18) {
		return 94;
	}
	if (state == 89 && lhs == 59) {
		return 111;
	}
	if (state == 89 && lhs == 24) {
		return 109;
	}
	if (state == 89 && lhs == 19) {
		return 132;
	}
	if (state == 89 && lhs == 60) {
		return 133;
	}
	if (state == 89 && lhs == 18) {
		return 107;
	}
	if (state == 70 && lhs == 4) {
		return 119;
	}
	if (state == 154 && lhs == 61) {
		return 168;
	}
	if (state == 154 && lhs == 59) {
		return 111;
	}
	if (state == 154 && lhs == 24) {
		return 109;
	}
	if (state == 154 && lhs == 19) {
		return 154;
	}
	if (state == 154 && lhs == 18) {
		return 107;
	}
	if (state == 57 && lhs == 59) {
		return 111;
	}
	if (state == 57 && lhs == 24) {
		return 109;
	}
	if (state == 57 && lhs == 25) {
		return 110;
	}
	if (state == 57 && lhs == 19) {
		return 108;
	}
	if (state == 57 && lhs == 18) {
		return 107;
	}
	if (state == 137 && lhs == 59) {
		return 99;
	}
	if (state == 137 && lhs == 58) {
		return 98;
	}
	if (state == 137 && lhs == 34) {
		return 137;
	}
	if (state == 137 && lhs == 24) {
		return 96;
	}
	if (state == 137 && lhs == 23) {
		return 157;
	}
	if (state == 137 && lhs == 18) {
		return 94;
	}
	if (state == 43 && lhs == 12) {
		return 72;
	}
	if (state == 43 && lhs == 5) {
		return 71;
	}
	if (state == 138 && lhs == 59) {
		return 111;
	}
	if (state == 138 && lhs == 24) {
		return 109;
	}
	if (state == 138 && lhs == 19) {
		return 138;
	}
	if (state == 138 && lhs == 26) {
		return 158;
	}
	if (state == 138 && lhs == 18) {
		return 107;
	}
	if (state == 41 && lhs == 54) {
		return 41;
	}
	if (state == 41 && lhs == 29) {
		return 69;
	}
	if (state == 39 && lhs == 51) {
		return 68;
	}
	if (state == 39 && lhs == 12) {
		return 67;
	}
	if (state == 132 && lhs == 61) {
		return 155;
	}
	if (state == 132 && lhs == 59) {
		return 111;
	}
	if (state == 132 && lhs == 24) {
		return 109;
	}
	if (state == 132 && lhs == 19) {
		return 154;
	}
	if (state == 132 && lhs == 18) {
		return 107;
	}
	if (state == 38 && lhs == 56) {
		return 65;
	}
	if (state == 33 && lhs == 24) {
		return 61;
	}
	if (state == 175 && lhs == 9) {
		return 178;
	}
	if (state == 78 && lhs == 55) {
		return 128;
	}
	if (state == 31 && lhs == 24) {
		return 60;
	}
	if (state == 31 && lhs == 21) {
		return 59;
	}
	if (state == 31 && lhs == 20) {
		return 58;
	}
	if (state == 173 && lhs == 65) {
		return 176;
	}
	if (state == 76 && lhs == 45) {
		return 127;
	}
	if (state == 74 && lhs == 64) {
		return 125;
	}
	if (state == 91 && lhs == 28) {
		return 9;
	}
	if (state == 91 && lhs == 54) {
		return 19;
	}
	if (state == 91 && lhs == 27) {
		return 134;
	}
	if (state == 44 && lhs == 63) {
		return 75;
	}
	if (state == 44 && lhs == 62) {
		return 74;
	}
	if (state == 44 && lhs == 33) {
		return 73;
	}
	if (state == 44 && lhs == 2) {
		return 22;
	}
	if (state == 68 && lhs == 50) {
		return 117;
	}
	if (state == 21 && lhs == 3) {
		return 43;
	}
	if (state == 113 && lhs == 8) {
		return 144;
	}
	if (state == 66 && lhs == 13) {
		return 115;
	}
	if (state == 66 && lhs == 7) {
		return 114;
	}
	if (state == 17 && lhs == 55) {
		return 39;
	}
	if (state == 11 && lhs == 62) {
		return 33;
	}
	if (state == 11 && lhs == 2) {
		return 22;
	}
	if (state == 108 && lhs == 59) {
		return 111;
	}
	if (state == 108 && lhs == 24) {
		return 109;
	}
	if (state == 108 && lhs == 19) {
		return 138;
	}
	if (state == 108 && lhs == 26) {
		return 139;
	}
	if (state == 108 && lhs == 18) {
		return 107;
	}
	if (state == 14 && lhs == 62) {
		return 37;
	}
	if (state == 14 && lhs == 37) {
		return 36;
	}
	if (state == 14 && lhs == 36) {
		return 35;
	}
	if (state == 14 && lhs == 2) {
		return 22;
	}
	if (state == 56 && lhs == 59) {
		return 99;
	}
	if (state == 56 && lhs == 58) {
		return 98;
	}
	if (state == 56 && lhs == 34) {
		return 97;
	}
	if (state == 56 && lhs == 24) {
		return 96;
	}
	if (state == 56 && lhs == 22) {
		return 95;
	}
	if (state == 56 && lhs == 18) {
		return 94;
	}
	if (state == 9 && lhs == 30) {
		return 32;
	}
	if (state == 9 && lhs == 2) {
		return 31;
	}
	if (state == 148 && lhs == 4) {
		return 161;
	}
	if (state == 151 && lhs == 65) {
		return 165;
	}
	if (state == 54 && lhs == 53) {
		return 82;
	}
	if (state == 7 && lhs == 54) {
		return 19;
	}
	if (state == 7 && lhs == 52) {
		return 18;
	}
	if (state == 7 && lhs == 49) {
		return 16;
	}
	if (state == 7 && lhs == 35) {
		return 13;
	}
	if (state == 7 && lhs == 32) {
		return 12;
	}
	if (state == 7 && lhs == 31) {
		return 10;
	}
	if (state == 7 && lhs == 28) {
		return 9;
	}
	if (state == 7 && lhs == 16) {
		return 29;
	}
	if (state == 7 && lhs == 27) {
		return 8;
	}
	if (state == 7 && lhs == 38) {
		return 15;
	}
	if (state == 7 && lhs == 17) {
		return 30;
	}
	if (state == 1 && lhs == 62) {
		return 23;
	}
	if (state == 1 && lhs == 2) {
		return 22;
	}
	if (state == 71 && lhs == 10) {
		return 122;
	}
	if (state == 71 && lhs == 6) {
		return 121;
	}
	if (state == 24 && lhs == 42) {
		return 48;
	}
	if (state == 24 && lhs == 44) {
		return 50;
	}
	if (state == 24 && lhs == 43) {
		return 49;
	}
	if (state == 24 && lhs == 47) {
		return 51;
	}
	if (state == 24 && lhs == 55) {
		return 52;
	}
	if (state == 24 && lhs == 41) {
		return 47;
	}
	if (state == 2 && lhs == 40) {
		return 25;
	}
	if (state == 2 && lhs == 39) {
		return 24;
	}
	if (state == 34 && lhs == 62) {
		return 62;
	}
	if (state == 34 && lhs == 2) {
		return 22;
	}
	if (state == 46 && lhs == 62) {
		return 76;
	}
	if (state == 46 && lhs == 2) {
		return 22;
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
		return 0;
	}
	if (rule == 23) {
		return 2;
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
		return 0;
	}
	if (rule == 33) {
		return 2;
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
		return 1;
	}
	if (rule == 43) {
		return 1;
	}
	if (rule == 44) {
		return 1;
	}
	if (rule == 45) {
		return 1;
	}
	if (rule == 46) {
		return 1;
	}
	if (rule == 47) {
		return 1;
	}
	if (rule == 48) {
		return 1;
	}
	if (rule == 49) {
		return 1;
	}
	if (rule == 50) {
		return 1;
	}
	if (rule == 51) {
		return 1;
	}
	if (rule == 52) {
		return 1;
	}
	if (rule == 53) {
		return 1;
	}
	if (rule == 54) {
		return 1;
	}
	if (rule == 55) {
		return 3;
	}
	if (rule == 56) {
		return 0;
	}
	if (rule == 57) {
		return 2;
	}
	if (rule == 58) {
		return 0;
	}
	if (rule == 59) {
		return 2;
	}
	if (rule == 60) {
		return 3;
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
		return 2;
	}
	if (rule == 65) {
		return 2;
	}
	if (rule == 66) {
		return 0;
	}
	if (rule == 67) {
		return 2;
	}
	if (rule == 68) {
		return 0;
	}
	if (rule == 69) {
		return 2;
	}
	if (rule == 70) {
		return 2;
	}
	if (rule == 71) {
		return 3;
	}
	if (rule == 72) {
		return 6;
	}
	if (rule == 73) {
		return 0;
	}
	if (rule == 74) {
		return 1;
	}
	if (rule == 75) {
		return 1;
	}
	if (rule == 76) {
		return 1;
	}
	if (rule == 77) {
		return 1;
	}
	if (rule == 78) {
		return 1;
	}
	if (rule == 79) {
		return 3;
	}
	if (rule == 80) {
		return 1;
	}
	if (rule == 81) {
		return 1;
	}
	if (rule == 82) {
		return 2;
	}
	if (rule == 83) {
		return 4;
	}
	if (rule == 84) {
		return 0;
	}
	if (rule == 85) {
		return 1;
	}
	if (rule == 86) {
		return 2;
	}
	if (rule == 87) {
		return 1;
	}
	if (rule == 88) {
		return 1;
	}
	if (rule == 89) {
		return 3;
	}
	if (rule == 90) {
		return 1;
	}
	if (rule == 91) {
		return 1;
	}
	if (rule == 92) {
		return 4;
	}
	if (rule == 93) {
		return 0;
	}
	if (rule == 94) {
		return 3;
	}
	if (rule == 95) {
		return 0;
	}
	if (rule == 96) {
		return 3;
	}
	if (rule == 97) {
		return 2;
	}
	if (rule == 98) {
		return 0;
	}
	if (rule == 99) {
		return 2;
	}
	if (rule == 100) {
		return 5;
	}
	if (rule == 101) {
		return 0;
	}
	if (rule == 102) {
		return 2;
	}
	if (rule == 103) {
		return 0;
	}
	if (rule == 104) {
		return 1;
	}
	if (rule == 105) {
		return 5;
	}
	if (rule == 106) {
		return 0;
	}
	if (rule == 107) {
		return 2;
	}
	if (rule == 108) {
		return 2;
	}
	if (rule == 109) {
		return 2;
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
		return 3;
	}
	if (rule == 116) {
		return 0;
	}
	if (rule == 117) {
		return 2;
	}
	if (rule == 118) {
		return 0;
	}
	if (rule == 119) {
		return 2;
	}
	if (rule == 120) {
		return 1;
	}
	if (rule == 121) {
		return 2;
	}
	if (rule == 122) {
		return 0;
	}
	if (rule == 123) {
		return 3;
	}
	if (rule == 124) {
		return 0;
	}
	if (rule == 125) {
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
		return 15;
	}
	if (rule == 23) {
		return 15;
	}
	if (rule == 24) {
		return 16;
	}
	if (rule == 25) {
		return 16;
	}
	if (rule == 26) {
		return 16;
	}
	if (rule == 27) {
		return 16;
	}
	if (rule == 28) {
		return 16;
	}
	if (rule == 29) {
		return 16;
	}
	if (rule == 30) {
		return 16;
	}
	if (rule == 31) {
		return 16;
	}
	if (rule == 32) {
		return 17;
	}
	if (rule == 33) {
		return 17;
	}
	if (rule == 34) {
		return 18;
	}
	if (rule == 35) {
		return 18;
	}
	if (rule == 36) {
		return 18;
	}
	if (rule == 37) {
		return 18;
	}
	if (rule == 38) {
		return 18;
	}
	if (rule == 39) {
		return 18;
	}
	if (rule == 40) {
		return 18;
	}
	if (rule == 41) {
		return 18;
	}
	if (rule == 42) {
		return 18;
	}
	if (rule == 43) {
		return 18;
	}
	if (rule == 44) {
		return 18;
	}
	if (rule == 45) {
		return 18;
	}
	if (rule == 46) {
		return 18;
	}
	if (rule == 47) {
		return 18;
	}
	if (rule == 48) {
		return 19;
	}
	if (rule == 49) {
		return 19;
	}
	if (rule == 50) {
		return 19;
	}
	if (rule == 51) {
		return 19;
	}
	if (rule == 52) {
		return 19;
	}
	if (rule == 53) {
		return 20;
	}
	if (rule == 54) {
		return 20;
	}
	if (rule == 55) {
		return 21;
	}
	if (rule == 56) {
		return 22;
	}
	if (rule == 57) {
		return 22;
	}
	if (rule == 58) {
		return 23;
	}
	if (rule == 59) {
		return 23;
	}
	if (rule == 60) {
		return 24;
	}
	if (rule == 61) {
		return 25;
	}
	if (rule == 62) {
		return 25;
	}
	if (rule == 63) {
		return 26;
	}
	if (rule == 64) {
		return 26;
	}
	if (rule == 65) {
		return 27;
	}
	if (rule == 66) {
		return 28;
	}
	if (rule == 67) {
		return 28;
	}
	if (rule == 68) {
		return 29;
	}
	if (rule == 69) {
		return 29;
	}
	if (rule == 70) {
		return 30;
	}
	if (rule == 71) {
		return 31;
	}
	if (rule == 72) {
		return 32;
	}
	if (rule == 73) {
		return 33;
	}
	if (rule == 74) {
		return 33;
	}
	if (rule == 75) {
		return 34;
	}
	if (rule == 76) {
		return 34;
	}
	if (rule == 77) {
		return 34;
	}
	if (rule == 78) {
		return 34;
	}
	if (rule == 79) {
		return 35;
	}
	if (rule == 80) {
		return 36;
	}
	if (rule == 81) {
		return 36;
	}
	if (rule == 82) {
		return 37;
	}
	if (rule == 83) {
		return 38;
	}
	if (rule == 84) {
		return 39;
	}
	if (rule == 85) {
		return 39;
	}
	if (rule == 86) {
		return 40;
	}
	if (rule == 87) {
		return 41;
	}
	if (rule == 88) {
		return 41;
	}
	if (rule == 89) {
		return 42;
	}
	if (rule == 90) {
		return 43;
	}
	if (rule == 91) {
		return 43;
	}
	if (rule == 92) {
		return 44;
	}
	if (rule == 93) {
		return 45;
	}
	if (rule == 94) {
		return 45;
	}
	if (rule == 95) {
		return 46;
	}
	if (rule == 96) {
		return 46;
	}
	if (rule == 97) {
		return 47;
	}
	if (rule == 98) {
		return 48;
	}
	if (rule == 99) {
		return 48;
	}
	if (rule == 100) {
		return 49;
	}
	if (rule == 101) {
		return 50;
	}
	if (rule == 102) {
		return 50;
	}
	if (rule == 103) {
		return 51;
	}
	if (rule == 104) {
		return 51;
	}
	if (rule == 105) {
		return 52;
	}
	if (rule == 106) {
		return 53;
	}
	if (rule == 107) {
		return 53;
	}
	if (rule == 108) {
		return 54;
	}
	if (rule == 109) {
		return 55;
	}
	if (rule == 110) {
		return 56;
	}
	if (rule == 111) {
		return 56;
	}
	if (rule == 112) {
		return 57;
	}
	if (rule == 113) {
		return 57;
	}
	if (rule == 114) {
		return 58;
	}
	if (rule == 115) {
		return 59;
	}
	if (rule == 116) {
		return 60;
	}
	if (rule == 117) {
		return 60;
	}
	if (rule == 118) {
		return 61;
	}
	if (rule == 119) {
		return 61;
	}
	if (rule == 120) {
		return 62;
	}
	if (rule == 121) {
		return 63;
	}
	if (rule == 122) {
		return 64;
	}
	if (rule == 123) {
		return 64;
	}
	if (rule == 124) {
		return 65;
	}
	if (rule == 125) {
		return 65;
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
		Types::modules::entry::main result;
		lr_capture_assign(result.value, values, 0, static_cast<std::size_t>(-1));
		return lr_node<Types::modules::entry::main>(result);
	}
	if (rule == 22) {
		return lr_pack(values, {}, {}, {}, 1, true);
	}
	if (rule == 23) {
		return lr_pack(values, {0, 1}, {0, 0}, {0, 1}, 1, true);
	}
	if (rule == 24) {
		return lr_pack(values, {0}, {0}, {0}, 1, false);
	}
	if (rule == 25) {
		return lr_pack(values, {0}, {0}, {0}, 1, false);
	}
	if (rule == 26) {
		return lr_pack(values, {0}, {0}, {0}, 1, false);
	}
	if (rule == 27) {
		return lr_pack(values, {0}, {0}, {0}, 1, false);
	}
	if (rule == 28) {
		return lr_pack(values, {0}, {0}, {0}, 1, false);
	}
	if (rule == 29) {
		return lr_pack(values, {0}, {0}, {0}, 1, false);
	}
	if (rule == 30) {
		return lr_pack(values, {0}, {0}, {0}, 1, false);
	}
	if (rule == 31) {
		return lr_pack(values, {0}, {0}, {0}, 1, false);
	}
	if (rule == 32) {
		return lr_pack(values, {}, {}, {}, 1, true);
	}
	if (rule == 33) {
		return lr_pack(values, {0, 1}, {0, 0}, {0, 1}, 1, true);
	}
	if (rule == 34) {
		Types::modules::ispa_dep_scanner::atom result;
		return lr_node<Types::modules::ispa_dep_scanner::atom>(result);
	}
	if (rule == 35) {
		Types::modules::ispa_dep_scanner::atom result;
		return lr_node<Types::modules::ispa_dep_scanner::atom>(result);
	}
	if (rule == 36) {
		Types::modules::ispa_dep_scanner::atom result;
		return lr_node<Types::modules::ispa_dep_scanner::atom>(result);
	}
	if (rule == 37) {
		Types::modules::ispa_dep_scanner::atom result;
		return lr_node<Types::modules::ispa_dep_scanner::atom>(result);
	}
	if (rule == 38) {
		Types::modules::ispa_dep_scanner::atom result;
		return lr_node<Types::modules::ispa_dep_scanner::atom>(result);
	}
	if (rule == 39) {
		Types::modules::ispa_dep_scanner::atom result;
		return lr_node<Types::modules::ispa_dep_scanner::atom>(result);
	}
	if (rule == 40) {
		Types::modules::ispa_dep_scanner::atom result;
		return lr_node<Types::modules::ispa_dep_scanner::atom>(result);
	}
	if (rule == 41) {
		Types::modules::ispa_dep_scanner::atom result;
		return lr_node<Types::modules::ispa_dep_scanner::atom>(result);
	}
	if (rule == 42) {
		Types::modules::ispa_dep_scanner::atom result;
		return lr_node<Types::modules::ispa_dep_scanner::atom>(result);
	}
	if (rule == 43) {
		Types::modules::ispa_dep_scanner::atom result;
		return lr_node<Types::modules::ispa_dep_scanner::atom>(result);
	}
	if (rule == 44) {
		Types::modules::ispa_dep_scanner::atom result;
		return lr_node<Types::modules::ispa_dep_scanner::atom>(result);
	}
	if (rule == 45) {
		Types::modules::ispa_dep_scanner::atom result;
		return lr_node<Types::modules::ispa_dep_scanner::atom>(result);
	}
	if (rule == 46) {
		Types::modules::ispa_dep_scanner::atom result;
		return lr_node<Types::modules::ispa_dep_scanner::atom>(result);
	}
	if (rule == 47) {
		Types::modules::ispa_dep_scanner::atom result;
		return lr_node<Types::modules::ispa_dep_scanner::atom>(result);
	}
	if (rule == 48) {
		Types::modules::ispa_dep_scanner::balanced_item result;
		return lr_node<Types::modules::ispa_dep_scanner::balanced_item>(result);
	}
	if (rule == 49) {
		Types::modules::ispa_dep_scanner::balanced_item result;
		return lr_node<Types::modules::ispa_dep_scanner::balanced_item>(result);
	}
	if (rule == 50) {
		Types::modules::ispa_dep_scanner::balanced_item result;
		return lr_node<Types::modules::ispa_dep_scanner::balanced_item>(result);
	}
	if (rule == 51) {
		Types::modules::ispa_dep_scanner::balanced_item result;
		return lr_node<Types::modules::ispa_dep_scanner::balanced_item>(result);
	}
	if (rule == 52) {
		Types::modules::ispa_dep_scanner::balanced_item result;
		return lr_node<Types::modules::ispa_dep_scanner::balanced_item>(result);
	}
	if (rule == 53) {
		Types::modules::ispa_dep_scanner::body result;
		lr_capture_assign(result.value, values, 0, static_cast<std::size_t>(-1));
		return lr_node<Types::modules::ispa_dep_scanner::body>(result);
	}
	if (rule == 54) {
		Types::modules::ispa_dep_scanner::body result;
		lr_capture_assign(result.value, values, 0, static_cast<std::size_t>(-1));
		return lr_node<Types::modules::ispa_dep_scanner::body>(result);
	}
	if (rule == 55) {
		Types::modules::ispa_dep_scanner::body::regular result;
		lr_capture_assign(result.value, values, 1, static_cast<std::size_t>(-1));
		return lr_node<Types::modules::ispa_dep_scanner::body::regular>(result);
	}
	if (rule == 56) {
		return lr_pack(values, {}, {}, {}, 1, true);
	}
	if (rule == 57) {
		return lr_pack(values, {0, 1}, {0, 0}, {0, 1}, 1, true);
	}
	if (rule == 58) {
		return lr_pack(values, {}, {}, {}, 1, true);
	}
	if (rule == 59) {
		return lr_pack(values, {0, 1}, {0, 0}, {0, 1}, 1, true);
	}
	if (rule == 60) {
		Types::modules::ispa_dep_scanner::braces result;
		return lr_node<Types::modules::ispa_dep_scanner::braces>(result);
	}
	if (rule == 61) {
		return lr_pack(values, {}, {}, {}, 1, true);
	}
	if (rule == 62) {
		return lr_pack(values, {0, 1}, {0, 0}, {0, 1}, 1, true);
	}
	if (rule == 63) {
		return lr_pack(values, {}, {}, {}, 1, true);
	}
	if (rule == 64) {
		return lr_pack(values, {0, 1}, {0, 0}, {0, 1}, 1, true);
	}
	if (rule == 65) {
		Types::modules::ispa_dep_scanner::declaration result;
		lr_capture_assign(result.modifiers, values, 0, static_cast<std::size_t>(-1));
		lr_capture_assign(result.value, values, 1, static_cast<std::size_t>(-1));
		return lr_node<Types::modules::ispa_dep_scanner::declaration>(result);
	}
	if (rule == 66) {
		return lr_pack(values, {}, {}, {}, 1, true);
	}
	if (rule == 67) {
		return lr_pack(values, {0, 1}, {0, 0}, {0, 1}, 1, true);
	}
	if (rule == 68) {
		return lr_pack(values, {}, {}, {}, 1, true);
	}
	if (rule == 69) {
		return lr_pack(values, {0, 1}, {0, 0}, {0, 1}, 1, true);
	}
	if (rule == 70) {
		Types::modules::ispa_dep_scanner::declaration::form result;
		lr_capture_assign(result.name, values, 0, static_cast<std::size_t>(-1));
		lr_capture_assign(result.body, values, 1, static_cast<std::size_t>(-1));
		return lr_node<Types::modules::ispa_dep_scanner::declaration::form>(result);
	}
	if (rule == 71) {
		Types::modules::ispa_dep_scanner::fail_decl result;
		return lr_node<Types::modules::ispa_dep_scanner::fail_decl>(result);
	}
	if (rule == 72) {
		Types::modules::ispa_dep_scanner::feature_decl result;
		lr_capture_assign(result.begin, values, 0, static_cast<std::size_t>(-1));
		lr_capture_assign(result.name, values, 1, static_cast<std::size_t>(-1));
		lr_capture_assign(result.symbols, values, 3, static_cast<std::size_t>(-1));
		lr_capture_assign(result.end, values, 5, static_cast<std::size_t>(-1));
		return lr_node<Types::modules::ispa_dep_scanner::feature_decl>(result);
	}
	if (rule == 73) {
		return lr_pack(values, {}, {}, {}, 1, false);
	}
	if (rule == 74) {
		return lr_pack(values, {0}, {0}, {0}, 1, false);
	}
	if (rule == 75) {
		Types::modules::ispa_dep_scanner::member result;
		lr_capture_assign(result.value, values, 0, static_cast<std::size_t>(-1));
		return lr_node<Types::modules::ispa_dep_scanner::member>(result);
	}
	if (rule == 76) {
		Types::modules::ispa_dep_scanner::member result;
		lr_capture_assign(result.value, values, 0, static_cast<std::size_t>(-1));
		return lr_node<Types::modules::ispa_dep_scanner::member>(result);
	}
	if (rule == 77) {
		Types::modules::ispa_dep_scanner::member result;
		lr_capture_assign(result.value, values, 0, static_cast<std::size_t>(-1));
		return lr_node<Types::modules::ispa_dep_scanner::member>(result);
	}
	if (rule == 78) {
		Types::modules::ispa_dep_scanner::member result;
		lr_capture_assign(result.value, values, 0, static_cast<std::size_t>(-1));
		return lr_node<Types::modules::ispa_dep_scanner::member>(result);
	}
	if (rule == 79) {
		Types::modules::ispa_dep_scanner::mod_detach result;
		lr_capture_assign(result.begin, values, 0, static_cast<std::size_t>(-1));
		lr_capture_assign(result.value, values, 1, static_cast<std::size_t>(-1));
		lr_capture_assign(result.end, values, 2, static_cast<std::size_t>(-1));
		return lr_node<Types::modules::ispa_dep_scanner::mod_detach>(result);
	}
	if (rule == 80) {
		Types::modules::ispa_dep_scanner::mod_detach::detach_value result;
		lr_capture_assign(result.value, values, 0, static_cast<std::size_t>(-1));
		return lr_node<Types::modules::ispa_dep_scanner::mod_detach::detach_value>(result);
	}
	if (rule == 81) {
		Types::modules::ispa_dep_scanner::mod_detach::detach_value result;
		lr_capture_assign(result.value, values, 0, static_cast<std::size_t>(-1));
		return lr_node<Types::modules::ispa_dep_scanner::mod_detach::detach_value>(result);
	}
	if (rule == 82) {
		Types::modules::ispa_dep_scanner::mod_detach::detach_value::feature_ref result;
		lr_capture_assign(result.value, values, 1, static_cast<std::size_t>(-1));
		return lr_node<Types::modules::ispa_dep_scanner::mod_detach::detach_value::feature_ref>(result);
	}
	if (rule == 83) {
		Types::modules::ispa_dep_scanner::mod_import result;
		lr_capture_assign(result.begin, values, 0, static_cast<std::size_t>(-1));
		lr_capture_assign(result.external, values, 1, static_cast<std::size_t>(-1));
		lr_capture_assign(result.value, values, 2, static_cast<std::size_t>(-1));
		lr_capture_assign(result.end, values, 3, static_cast<std::size_t>(-1));
		return lr_node<Types::modules::ispa_dep_scanner::mod_import>(result);
	}
	if (rule == 84) {
		return lr_pack(values, {}, {}, {}, 1, false);
	}
	if (rule == 85) {
		return lr_pack(values, {0}, {0}, {0}, 1, false);
	}
	if (rule == 86) {
		Types::modules::ispa_dep_scanner::mod_import::external_import result;
		lr_capture_assign(result.value, values, 1, static_cast<std::size_t>(-1));
		return lr_node<Types::modules::ispa_dep_scanner::mod_import::external_import>(result);
	}
	if (rule == 87) {
		Types::modules::ispa_dep_scanner::mod_import::import_value result;
		lr_capture_assign(result.value, values, 0, static_cast<std::size_t>(-1));
		return lr_node<Types::modules::ispa_dep_scanner::mod_import::import_value>(result);
	}
	if (rule == 88) {
		Types::modules::ispa_dep_scanner::mod_import::import_value result;
		lr_capture_assign(result.value, values, 0, static_cast<std::size_t>(-1));
		return lr_node<Types::modules::ispa_dep_scanner::mod_import::import_value>(result);
	}
	if (rule == 89) {
		Types::modules::ispa_dep_scanner::mod_import::import_value::from_import result;
		lr_capture_assign(result.sel, values, 0, static_cast<std::size_t>(-1));
		lr_capture_assign(result.source, values, 2, static_cast<std::size_t>(-1));
		return lr_node<Types::modules::ispa_dep_scanner::mod_import::import_value::from_import>(result);
	}
	if (rule == 90) {
		Types::modules::ispa_dep_scanner::mod_import::import_value::from_import::selection result;
		lr_capture_assign(result.value, values, 0, static_cast<std::size_t>(-1));
		return lr_node<Types::modules::ispa_dep_scanner::mod_import::import_value::from_import::selection>(result);
	}
	if (rule == 91) {
		Types::modules::ispa_dep_scanner::mod_import::import_value::from_import::selection result;
		lr_capture_assign(result.value, values, 0, static_cast<std::size_t>(-1));
		return lr_node<Types::modules::ispa_dep_scanner::mod_import::import_value::from_import::selection>(result);
	}
	if (rule == 92) {
		Types::modules::ispa_dep_scanner::mod_import::import_value::from_import::selection::items result;
		lr_capture_assign(result.first, values, 1, static_cast<std::size_t>(-1));
		lr_capture_assign(result.sequence, values, 2, static_cast<std::size_t>(0));
		return lr_node<Types::modules::ispa_dep_scanner::mod_import::import_value::from_import::selection::items>(result);
	}
	if (rule == 93) {
		return lr_pack(values, {}, {}, {}, 1, true);
	}
	if (rule == 94) {
		return lr_pack(values, {1, 2}, {0, 0}, {0, 1}, 1, true);
	}
	if (rule == 95) {
		return lr_pack(values, {}, {}, {}, 1, true);
	}
	if (rule == 96) {
		return lr_pack(values, {1, 2}, {0, 0}, {0, 1}, 1, true);
	}
	if (rule == 97) {
		Types::modules::ispa_dep_scanner::mod_import::import_value::module_import result;
		lr_capture_assign(result.source, values, 0, static_cast<std::size_t>(-1));
		lr_capture_assign(result.alias, values, 1, static_cast<std::size_t>(0));
		return lr_node<Types::modules::ispa_dep_scanner::mod_import::import_value::module_import>(result);
	}
	if (rule == 98) {
		return lr_pack(values, {}, {}, {}, 1, false);
	}
	if (rule == 99) {
		return lr_pack(values, {1}, {0}, {0}, 1, false);
	}
	if (rule == 100) {
		Types::modules::ispa_dep_scanner::mod_module result;
		lr_capture_assign(result.begin, values, 0, static_cast<std::size_t>(-1));
		lr_capture_assign(result.name, values, 1, static_cast<std::size_t>(-1));
		lr_capture_assign(result.parameters, values, 2, static_cast<std::size_t>(-1));
		lr_capture_assign(result.entry, values, 3, static_cast<std::size_t>(0));
		lr_capture_assign(result.end, values, 4, static_cast<std::size_t>(-1));
		return lr_node<Types::modules::ispa_dep_scanner::mod_module>(result);
	}
	if (rule == 101) {
		return lr_pack(values, {}, {}, {}, 1, false);
	}
	if (rule == 102) {
		return lr_pack(values, {1}, {0}, {0}, 1, false);
	}
	if (rule == 103) {
		return lr_pack(values, {}, {}, {}, 1, false);
	}
	if (rule == 104) {
		return lr_pack(values, {0}, {0}, {0}, 1, false);
	}
	if (rule == 105) {
		Types::modules::ispa_dep_scanner::mod_python_import result;
		lr_capture_assign(result.begin, values, 0, static_cast<std::size_t>(-1));
		lr_capture_assign(result.source, values, 2, static_cast<std::size_t>(-1));
		lr_capture_assign(result.alias, values, 3, static_cast<std::size_t>(0));
		lr_capture_assign(result.end, values, 4, static_cast<std::size_t>(-1));
		return lr_node<Types::modules::ispa_dep_scanner::mod_python_import>(result);
	}
	if (rule == 106) {
		return lr_pack(values, {}, {}, {}, 1, false);
	}
	if (rule == 107) {
		return lr_pack(values, {1}, {0}, {0}, 1, false);
	}
	if (rule == 108) {
		Types::modules::ispa_dep_scanner::modifier result;
		return lr_node<Types::modules::ispa_dep_scanner::modifier>(result);
	}
	if (rule == 109) {
		Types::modules::ispa_dep_scanner::module_path result;
		lr_capture_assign(result.primary, values, 0, static_cast<std::size_t>(-1));
		lr_capture_assign(result.nested, values, 1, static_cast<std::size_t>(0));
		return lr_node<Types::modules::ispa_dep_scanner::module_path>(result);
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
		Types::modules::ispa_dep_scanner::nested_rule result;
		lr_capture_assign(result.value, values, 1, static_cast<std::size_t>(-1));
		return lr_node<Types::modules::ispa_dep_scanner::nested_rule>(result);
	}
	if (rule == 115) {
		Types::modules::ispa_dep_scanner::parentheses result;
		return lr_node<Types::modules::ispa_dep_scanner::parentheses>(result);
	}
	if (rule == 116) {
		return lr_pack(values, {}, {}, {}, 1, true);
	}
	if (rule == 117) {
		return lr_pack(values, {0, 1}, {0, 0}, {0, 1}, 1, true);
	}
	if (rule == 118) {
		return lr_pack(values, {}, {}, {}, 1, true);
	}
	if (rule == 119) {
		return lr_pack(values, {0, 1}, {0, 0}, {0, 1}, 1, true);
	}
	if (rule == 120) {
		Types::modules::ispa_dep_scanner::source_name result;
		lr_capture_assign(result.value, values, 0, static_cast<std::size_t>(-1));
		return lr_node<Types::modules::ispa_dep_scanner::source_name>(result);
	}
	if (rule == 121) {
		Types::modules::ispa_dep_scanner::symbol_list result;
		lr_capture_assign(result.first, values, 0, static_cast<std::size_t>(-1));
		lr_capture_assign(result.following, values, 1, static_cast<std::size_t>(0));
		return lr_node<Types::modules::ispa_dep_scanner::symbol_list>(result);
	}
	if (rule == 122) {
		return lr_pack(values, {}, {}, {}, 1, true);
	}
	if (rule == 123) {
		return lr_pack(values, {1, 2}, {0, 0}, {0, 1}, 1, true);
	}
	if (rule == 124) {
		return lr_pack(values, {}, {}, {}, 1, true);
	}
	if (rule == 125) {
		return lr_pack(values, {1, 2}, {0, 0}, {0, 1}, 1, true);
	}
	throw std::runtime_error("Invalid LR table entry or unexpected token");
}
auto DepParser::Parser::lr_shift(const Token& token) -> std::any {
	if (token.kind() == Tokens::__WS::id) {
		return lr_token(token.template to_node<Types::__WS>());
	}
	if (token.kind() == Tokens::modules::ispa_dep_scanner::mod_module::MODULE::id) {
		return lr_token(token.template to_node<Types::modules::ispa_dep_scanner::mod_module::MODULE>());
	}
	if (token.kind() == Tokens::modules::ispa_dep_scanner::mod_detach::DETACH::id) {
		return lr_token(token.template to_node<Types::modules::ispa_dep_scanner::mod_detach::DETACH>());
	}
	if (token.kind() == Tokens::modules::ispa_dep_scanner::mod_import::import_value::from_import::FROM::id) {
		return lr_token(token.template to_node<Types::modules::ispa_dep_scanner::mod_import::import_value::from_import::FROM>());
	}
	if (token.kind() == Tokens::AS::id) {
		return lr_token(token.template to_node<Types::AS>());
	}
	if (token.kind() == Tokens::modules::ispa_dep_scanner::mod_python_import::PY::id) {
		return lr_token(token.template to_node<Types::modules::ispa_dep_scanner::mod_python_import::PY>());
	}
	if (token.kind() == Tokens::IMPORT::id) {
		return lr_token(token.template to_node<Types::IMPORT>());
	}
	if (token.kind() == Tokens::RIGHT_CURLY_BRACKET::id) {
		return lr_token(token.template to_node<Types::RIGHT_CURLY_BRACKET>());
	}
	if (token.kind() == Tokens::modules::ispa_dep_scanner::fail_decl::FAIL::id) {
		return lr_token(token.template to_node<Types::modules::ispa_dep_scanner::fail_decl::FAIL>());
	}
	if (token.kind() == Tokens::LEFT_CURLY_BRACKET::id) {
		return lr_token(token.template to_node<Types::LEFT_CURLY_BRACKET>());
	}
	if (token.kind() == Tokens::ASTERISK::id) {
		return lr_token(token.template to_node<Types::ASTERISK>());
	}
	if (token.kind() == Tokens::COLON::id) {
		return lr_token(token.template to_node<Types::COLON>());
	}
	if (token.kind() == Tokens::GREATER_THAN_SIGN::id) {
		return lr_token(token.template to_node<Types::GREATER_THAN_SIGN>());
	}
	if (token.kind() == Tokens::FULL_STOP::id) {
		return lr_token(token.template to_node<Types::FULL_STOP>());
	}
	if (token.kind() == Tokens::AUTO::id) {
		return lr_token(token.template to_node<Types::AUTO>());
	}
	if (token.kind() == Tokens::modules::scanner_tokens::OTHER::id) {
		return lr_token(token.template to_node<Types::modules::scanner_tokens::OTHER>());
	}
	if (token.kind() == Tokens::modules::scanner_tokens::PY_RAW::id) {
		return lr_token(token.template to_node<Types::modules::scanner_tokens::PY_RAW>());
	}
	if (token.kind() == Tokens::NUMBER_SIGN::id) {
		return lr_token(token.template to_node<Types::NUMBER_SIGN>());
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
	if (token.kind() == Tokens::modules::common::ID::id) {
		return lr_token(token.template to_node<Types::modules::common::ID>());
	}
	if (token.kind() == Tokens::LESS_THAN_SIGN::id) {
		return lr_token(token.template to_node<Types::LESS_THAN_SIGN>());
	}
	if (token.kind() == Tokens::modules::scanner_tokens::STRING::id) {
		return lr_token(token.template to_node<Types::modules::scanner_tokens::STRING>());
	}
	if (token.kind() == Tokens::SEMICOLON::id) {
		return lr_token(token.template to_node<Types::SEMICOLON>());
	}
	if (token.kind() == Tokens::modules::scanner_tokens::COMMENT::id) {
		return lr_token(token.template to_node<Types::modules::scanner_tokens::COMMENT>());
	}
	if (token.kind() == Tokens::FEATURE::id) {
		return lr_token(token.template to_node<Types::FEATURE>());
	}
	if (token.kind() == Tokens::modules::ispa_dep_scanner::mod_import::external_import::EXTERN::id) {
		return lr_token(token.template to_node<Types::modules::ispa_dep_scanner::mod_import::external_import::EXTERN>());
	}
	if (token.kind() == Tokens::modules::scanner_tokens::CGROUP::id) {
		return lr_token(token.template to_node<Types::modules::scanner_tokens::CGROUP>());
	}
	throw std::runtime_error("Invalid LR table entry or unexpected token");
}
template<typename IT, class> auto DepParser::Parser::main(IT pos) -> ::ISPA_STD::MatchResult<Types::main, IT> {
	return lr_parse<Parser>(pos);
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
