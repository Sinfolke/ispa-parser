#ifndef PARSER_H
#define PARSER_H
#include <string>
#include <vector>
#include <unordered_map>
#include <array>
#include <string>
#include <variant>
#include <optional>
#include <memory>
#include <ispastdlib.hpp>
namespace Parser {
	enum class Tokens {
		NONE,
		compound_statement_AUTO_0,
		name_AUTO_0,
		fail_block_AUTO_0,
		grammar_modifier_AUTO_1,
		grammar_modifier_AUTO_0,
		forward_declaration_AUTO_0,
		advanced_rule_dep_decl_AUTO_0,
		rule_value_alternative_AUTO_0,
		rule_value_group_AUTO_0,
		rule_value_var_capture_AUTO_0,
		rule_ast_full_part_AUTO_0,
		expr_AUTO_1,
		expr_AUTO_0,
		rule_value_QUANTIFIER,
		rule_value_counter_bounded_AUTO_0,
		rule_value_CGROUP,
		template_params_AUTO_0,
		__WS,
		rule_nested_rule_AUTO_0,
		rule_value_STRING,
		rule_value_ast_capture_AUTO_0,
		advanced_rule_AUTO_0,
		template_params_AUTO_1,
		rule_value_SPACE,
		rule_value_shared_counter_registration_AUTO_0,
		advanced_rule_AUTO_1,
		param_AUTO_0,
		NUMBER,
		advanced_rule_match_AUTO_0,
		ID,
	};
	enum class Rules {
		NONE,
		rule_ast_full,
		forward_declaration,
		rule_nested_rule,
		rule_value_counter,
		advanced_rule_match,
		rule_ast,
		rule_value_ast_capture,
		expr,
		rule_value_counter_bounded,
		rule_value,
		rule_value_var_capture,
		advanced_rule,
		advanced_rule_dep_decl,
		rule_ast_single_value,
		rule_value_group,
		rule_ast_full_part,
		rule_value_alternative,
		rule,
		grammar_modifier,
		grammar,
		rule_value_pattern,
		main,
		fail_block,
		rule_ast_abbr,
		params,
		template_params,
		advanced_rule_match_unpack,
		param,
		name,
		stmt,
		advanced_rule_fail_call,
		explicit_expr,
		rule_value_shared_counter_registration,
		compound_statement,
	};
	namespace FlatTypes {
		struct compound_statement_AUTO_0;
		struct compound_statement;
		struct name_AUTO_0;
		struct name;
		struct fail_block_AUTO_0;
		struct fail_block;
		struct grammar_modifier_AUTO_1;
		struct grammar;
		struct grammar_modifier;
		struct grammar_modifier_AUTO_0;
		struct forward_declaration_AUTO_0;
		struct forward_declaration;
		struct advanced_rule_dep_decl_AUTO_0;
		struct advanced_rule;
		struct advanced_rule_dep_decl;
		struct rule_value_alternative_AUTO_0;
		struct rule;
		struct rule_value;
		struct rule_value_alternative;
		struct rule_value_group_AUTO_0;
		struct rule_value_group;
		struct rule_value_var_capture_AUTO_0;
		struct rule_value_var_capture;
		struct rule_ast_full_part_AUTO_0;
		struct rule_ast;
		struct rule_ast_full;
		struct rule_ast_full_part;
		struct expr_AUTO_1;
		struct expr;
		struct expr_AUTO_0;
		struct rule_value_QUANTIFIER;
		struct rule_value_counter_bounded_AUTO_0;
		struct rule_value_counter;
		struct rule_value_counter_bounded;
		struct rule_value_CGROUP;
		struct template_params_AUTO_0;
		struct template_params;
		struct __WS;
		struct rule_nested_rule_AUTO_0;
		struct rule_nested_rule;
		struct rule_value_STRING;
		struct rule_value_ast_capture_AUTO_0;
		struct rule_value_ast_capture;
		struct advanced_rule_AUTO_0;
		struct template_params_AUTO_1;
		struct rule_value_SPACE;
		struct rule_value_shared_counter_registration_AUTO_0;
		struct rule_value_shared_counter_registration;
		struct advanced_rule_AUTO_1;
		struct param_AUTO_0;
		struct param;
		struct NUMBER;
		struct advanced_rule_match_AUTO_0;
		struct advanced_rule_match;
		struct ID;
		struct rule_ast_single_value;
		struct rule_value_pattern;
		struct main;
		struct rule_ast_abbr;
		struct params;
		struct advanced_rule_match_unpack;
		struct stmt;
		struct advanced_rule_fail_call;
		struct explicit_expr;
	}
	namespace FlatTypes {
		struct compound_statement_AUTO_0 {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const compound_statement_AUTO_0 &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct name_AUTO_0 {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const name_AUTO_0 &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct fail_block_AUTO_0 {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const fail_block_AUTO_0 &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct grammar_modifier_AUTO_1 {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const grammar_modifier_AUTO_1 &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct grammar_modifier_AUTO_0 {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const grammar_modifier_AUTO_0 &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct forward_declaration_AUTO_0 {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const forward_declaration_AUTO_0 &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct advanced_rule_dep_decl_AUTO_0 {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const advanced_rule_dep_decl_AUTO_0 &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct rule_value_alternative_AUTO_0 {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const rule_value_alternative_AUTO_0 &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct rule_value_alternative {
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::rule_value_pattern>> value;
			using AUTO_0 = ::Parser::FlatTypes::rule_value_alternative_AUTO_0;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const rule_value_alternative &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct rule_value_group_AUTO_0 {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const rule_value_group_AUTO_0 &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct rule_value_group {
			std::vector<::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::rule_value>>> value;
			using AUTO_0 = ::Parser::FlatTypes::rule_value_group_AUTO_0;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const rule_value_group &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct rule_value_var_capture_AUTO_0 {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const rule_value_var_capture_AUTO_0 &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct rule_ast_full_part_AUTO_0 {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const rule_ast_full_part_AUTO_0 &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct expr_AUTO_1 {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const expr_AUTO_1 &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct expr_AUTO_0 {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const expr_AUTO_0 &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct rule_value_QUANTIFIER {
			char value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const rule_value_QUANTIFIER &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct rule_value_counter_bounded_AUTO_0 {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const rule_value_counter_bounded_AUTO_0 &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct rule_value_CGROUP {
			std::string value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const rule_value_CGROUP &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct template_params_AUTO_0 {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const template_params_AUTO_0 &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct __WS {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const __WS &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct rule_nested_rule_AUTO_0 {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const rule_nested_rule_AUTO_0 &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct rule_nested_rule {
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::grammar>> value;
			using AUTO_0 = ::Parser::FlatTypes::rule_nested_rule_AUTO_0;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const rule_nested_rule &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct rule_value_STRING {
			std::string value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const rule_value_STRING &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct rule_value_ast_capture_AUTO_0 {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const rule_value_ast_capture_AUTO_0 &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct advanced_rule_AUTO_0 {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const advanced_rule_AUTO_0 &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct template_params_AUTO_1 {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const template_params_AUTO_1 &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct rule_value_SPACE {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const rule_value_SPACE &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct rule_value_shared_counter_registration_AUTO_0 {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const rule_value_shared_counter_registration_AUTO_0 &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct advanced_rule_AUTO_1 {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const advanced_rule_AUTO_1 &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct param_AUTO_0 {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const param_AUTO_0 &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct NUMBER {
			std::string full;
			std::string floating;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const NUMBER &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct advanced_rule_match_AUTO_0 {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const advanced_rule_match_AUTO_0 &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct ID {
			std::string value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const ID &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct compound_statement {
			::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::compound_statement_AUTO_0> value;
			using AUTO_0 = ::Parser::FlatTypes::compound_statement_AUTO_0;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const compound_statement &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct expr {
			::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::expr_AUTO_0> value;
			using AUTO_1 = ::Parser::FlatTypes::expr_AUTO_1;
			using AUTO_0 = ::Parser::FlatTypes::expr_AUTO_0;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const expr &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct grammar_modifier {
			::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::ID> value;
			using AUTO_1 = ::Parser::FlatTypes::grammar_modifier_AUTO_1;
			using AUTO_0 = ::Parser::FlatTypes::grammar_modifier_AUTO_0;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const grammar_modifier &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct forward_declaration {
			::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::ID> value;
			using AUTO_0 = ::Parser::FlatTypes::forward_declaration_AUTO_0;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const forward_declaration &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct rule_value_var_capture {
			::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::ID> value;
			using AUTO_0 = ::Parser::FlatTypes::rule_value_var_capture_AUTO_0;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const rule_value_var_capture &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct rule_value_ast_capture {
			::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::ID> value;
			using AUTO_0 = ::Parser::FlatTypes::rule_value_ast_capture_AUTO_0;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const rule_value_ast_capture &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct rule_value_shared_counter_registration {
			::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::ID> value;
			using AUTO_0 = ::Parser::FlatTypes::rule_value_shared_counter_registration_AUTO_0;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const rule_value_shared_counter_registration &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct param {
			::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::ID> first_p;
			std::vector<::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::ID>> following_p;
			using AUTO_0 = ::Parser::FlatTypes::param_AUTO_0;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const param &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct rule_ast_abbr {
			std::vector<::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::ID>> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const rule_ast_abbr &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct advanced_rule_match_unpack {
			std::vector<::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::ID>> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const advanced_rule_match_unpack &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct stmt {
			::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::ID> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const stmt &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct rule_ast_full_part {
			::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::ID> key;
			::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::expr> e;
			using AUTO_0 = ::Parser::FlatTypes::rule_ast_full_part_AUTO_0;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const rule_ast_full_part &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct rule_ast_single_value {
			::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::expr> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const rule_ast_single_value &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct explicit_expr {
			::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::expr> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const explicit_expr &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct advanced_rule_dep_decl {
			::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::forward_declaration> value;
			using AUTO_0 = ::Parser::FlatTypes::advanced_rule_dep_decl_AUTO_0;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const advanced_rule_dep_decl &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct template_params {
			::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::param> value;
			using AUTO_0 = ::Parser::FlatTypes::template_params_AUTO_0;
			using AUTO_1 = ::Parser::FlatTypes::template_params_AUTO_1;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const template_params &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct params {
			::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::param> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const params &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct rule_ast_full {
			std::vector<::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::rule_ast_full_part>> value;
			using part = ::Parser::FlatTypes::rule_ast_full_part;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const rule_ast_full &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct rule_value_counter_bounded {
			std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::explicit_expr>, ::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::ID>, ::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::NUMBER>> value;
			using AUTO_0 = ::Parser::FlatTypes::rule_value_counter_bounded_AUTO_0;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const rule_value_counter_bounded &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct name {
			::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::ID> primary;
			std::vector<::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::ID>> nested;
			::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::template_params> temp_params;
			::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::params> param;
			using AUTO_0 = ::Parser::FlatTypes::name_AUTO_0;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const name &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct rule_ast {
			std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::rule_ast_single_value>, ::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::rule_ast_full>, ::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::rule_ast_abbr>> value;
			using full = ::Parser::FlatTypes::rule_ast_full;
			using single_value = ::Parser::FlatTypes::rule_ast_single_value;
			using abbr = ::Parser::FlatTypes::rule_ast_abbr;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const rule_ast &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct rule_value_counter {
			::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::rule_value_QUANTIFIER> quantifier;
			::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::rule_value_counter_bounded> repetitions;
			using bounded = ::Parser::FlatTypes::rule_value_counter_bounded;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const rule_value_counter &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct fail_block {
			::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::name> name;
			std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::compound_statement>, ::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::stmt>> val;
			using AUTO_0 = ::Parser::FlatTypes::fail_block_AUTO_0;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const fail_block &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct rule_value_pattern {
			std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::rule_value_CGROUP>, ::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::rule_value_STRING>, ::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::rule_value_SPACE>, ::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::rule_value_group>>, ::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::name>> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const rule_value_pattern &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct advanced_rule_fail_call {
			::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::name> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const advanced_rule_fail_call &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct rule_value {
			::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::rule_value_var_capture> v_cap;
			::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::rule_value_ast_capture> ast_cap;
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::rule_value_pattern>> val;
			std::vector<::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::rule_value_alternative>>> alts;
			::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::rule_value_counter> quantifier;
			::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::rule_value_shared_counter_registration> registration;
			using alternative = ::Parser::FlatTypes::rule_value_alternative;
			using group = ::Parser::FlatTypes::rule_value_group;
			using var_capture = ::Parser::FlatTypes::rule_value_var_capture;
			using QUANTIFIER = ::Parser::FlatTypes::rule_value_QUANTIFIER;
			using counter = ::Parser::FlatTypes::rule_value_counter;
			using CGROUP = ::Parser::FlatTypes::rule_value_CGROUP;
			using STRING = ::Parser::FlatTypes::rule_value_STRING;
			using ast_capture = ::Parser::FlatTypes::rule_value_ast_capture;
			using SPACE = ::Parser::FlatTypes::rule_value_SPACE;
			using shared_counter_registration = ::Parser::FlatTypes::rule_value_shared_counter_registration;
			using pattern = ::Parser::FlatTypes::rule_value_pattern;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const rule_value &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct rule {
			std::vector<::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::rule_value>> v;
			::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::rule_ast> data;
			std::vector<::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::rule_nested_rule>>> nested;
			using value = ::Parser::FlatTypes::rule_value;
			using ast = ::Parser::FlatTypes::rule_ast;
			using nested_rule = ::Parser::FlatTypes::rule_nested_rule;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const rule &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct advanced_rule_match {
			std::vector<::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::rule_value>> patterns;
			std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::advanced_rule_match_AUTO_0>, ::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::advanced_rule_match_unpack>> assign_names;
			using AUTO_0 = ::Parser::FlatTypes::advanced_rule_match_AUTO_0;
			using unpack = ::Parser::FlatTypes::advanced_rule_match_unpack;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const advanced_rule_match &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct advanced_rule {
			std::vector<::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::advanced_rule_dep_decl>> dep;
			std::vector<std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::stmt>, ::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::advanced_rule_match>>> body;
			using dep_decl = ::Parser::FlatTypes::advanced_rule_dep_decl;
			using AUTO_0 = ::Parser::FlatTypes::advanced_rule_AUTO_0;
			using AUTO_1 = ::Parser::FlatTypes::advanced_rule_AUTO_1;
			using match = ::Parser::FlatTypes::advanced_rule_match;
			using fail_call = ::Parser::FlatTypes::advanced_rule_fail_call;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const advanced_rule &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct grammar {
			::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::name> name;
			std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::advanced_rule>, ::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::rule>>> entry;
			using modifier = ::Parser::FlatTypes::grammar_modifier;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const grammar &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct main {
			std::vector<std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::fail_block>, ::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::grammar>>> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const main &value) -> std::ostream&;
	}
	namespace Types {
		using compound_statement = ::Parser::FlatTypes::compound_statement;
		using name = ::Parser::FlatTypes::name;
		using fail_block = ::Parser::FlatTypes::fail_block;
		using grammar = ::Parser::FlatTypes::grammar;
		using forward_declaration = ::Parser::FlatTypes::forward_declaration;
		using advanced_rule = ::Parser::FlatTypes::advanced_rule;
		using rule = ::Parser::FlatTypes::rule;
		using expr = ::Parser::FlatTypes::expr;
		using template_params = ::Parser::FlatTypes::template_params;
		using __WS = ::Parser::FlatTypes::__WS;
		using param = ::Parser::FlatTypes::param;
		using NUMBER = ::Parser::FlatTypes::NUMBER;
		using ID = ::Parser::FlatTypes::ID;
		using main = ::Parser::FlatTypes::main;
		using params = ::Parser::FlatTypes::params;
		using stmt = ::Parser::FlatTypes::stmt;
		using explicit_expr = ::Parser::FlatTypes::explicit_expr;
	}
	using Token = std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Tokens, Types::compound_statement::AUTO_0>, ::ISPA_STD::Node<::Parser::Tokens, Types::name::AUTO_0>, ::ISPA_STD::Node<::Parser::Tokens, Types::fail_block::AUTO_0>, ::ISPA_STD::Node<::Parser::Tokens, Types::grammar::modifier::AUTO_1>, ::ISPA_STD::Node<::Parser::Tokens, Types::grammar::modifier::AUTO_0>, ::ISPA_STD::Node<::Parser::Tokens, Types::forward_declaration::AUTO_0>, ::ISPA_STD::Node<::Parser::Tokens, Types::advanced_rule::dep_decl::AUTO_0>, ::ISPA_STD::Node<::Parser::Tokens, Types::rule::value::alternative::AUTO_0>, ::ISPA_STD::Node<::Parser::Tokens, Types::rule::value::group::AUTO_0>, ::ISPA_STD::Node<::Parser::Tokens, Types::rule::value::var_capture::AUTO_0>, ::ISPA_STD::Node<::Parser::Tokens, Types::rule::ast::full::part::AUTO_0>, ::ISPA_STD::Node<::Parser::Tokens, Types::expr::AUTO_1>, ::ISPA_STD::Node<::Parser::Tokens, Types::expr::AUTO_0>, ::ISPA_STD::Node<::Parser::Tokens, Types::rule::value::QUANTIFIER>, ::ISPA_STD::Node<::Parser::Tokens, Types::rule::value::counter::bounded::AUTO_0>, ::ISPA_STD::Node<::Parser::Tokens, Types::rule::value::CGROUP>, ::ISPA_STD::Node<::Parser::Tokens, Types::template_params::AUTO_0>, ::ISPA_STD::Node<::Parser::Tokens, Types::__WS>, ::ISPA_STD::Node<::Parser::Tokens, Types::rule::nested_rule::AUTO_0>, ::ISPA_STD::Node<::Parser::Tokens, Types::rule::value::STRING>, ::ISPA_STD::Node<::Parser::Tokens, Types::rule::value::ast_capture::AUTO_0>, ::ISPA_STD::Node<::Parser::Tokens, Types::advanced_rule::AUTO_0>, ::ISPA_STD::Node<::Parser::Tokens, Types::template_params::AUTO_1>, ::ISPA_STD::Node<::Parser::Tokens, Types::rule::value::SPACE>, ::ISPA_STD::Node<::Parser::Tokens, Types::rule::value::shared_counter_registration::AUTO_0>, ::ISPA_STD::Node<::Parser::Tokens, Types::advanced_rule::AUTO_1>, ::ISPA_STD::Node<::Parser::Tokens, Types::param::AUTO_0>, ::ISPA_STD::Node<::Parser::Tokens, Types::NUMBER>, ::ISPA_STD::Node<::Parser::Tokens, Types::advanced_rule::match::AUTO_0>, ::ISPA_STD::Node<::Parser::Tokens, Types::ID>>;
	class Lexer : public ::ISPA_STD::Lexer_base<::Parser::Tokens, Token> {
		static ::ISPA_STD::DFA::API::CharToClass char_class_table;
		static ::ISPA_STD::DFA::API::Table<61, 39> dfa_table;
		static ::ISPA_STD::DFA::API::Table<70, 4> action_table;
		static auto semantic_action_exec(long long state, const ::ISPA_STD::DFA::API::Captures& captures, long long start_pos, const char* start, long long length, long long line) -> std::pair<long long, Token>;
		bool init_done;
		auto init() -> void override;
		::ISPA_STD::DFA::API::TdfaLayout<20, 18> tdfa_registers;
		static std::array<::ISPA_STD::DFA::API::DFADebug, 1> debug_array;
		static std::unordered_map<long long, std::unordered_map<long long, long long>> debug_index;
	public: 
		auto makeToken(const char*& pos) -> Token override;
	};
	class Parser : public ::ISPA_STD::LLParser_base<::Parser::Tokens, ::Parser::Rules, Types::main, Token> {
		template<typename IT>
		auto rule_ast_full(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::rule::ast::full, IT>{
			::ISPA_STD::Node<::Parser::Tokens, Types::rule::value::var_capture::AUTO_0> rule_value_var_capture_AUTO_0_0;
			bool success_1;
			::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
			bool success_3;
			::ISPA_STD::Node<::Parser::Tokens, Types::advanced_rule::AUTO_0> advanced_rule_AUTO_0_4;
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
			::ISPA_STD::Node<::Parser::Tokens, Types::advanced_rule::AUTO_1> advanced_rule_AUTO_1_17;
			bool success_18;
			success_1 = false;
			if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::rule::value::var_capture::AUTO_0>>((*pos)))) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  rule::value::var_capture::AUTO_0");
				return {};
			}
			rule_value_var_capture_AUTO_0_0 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::rule::value::var_capture::AUTO_0>>((*pos));
			success_1 = true;
			pos++;
			success_3 = false;
			if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos))) {
				__WS_2 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos));
				success_3 = true;
				pos++;
			}
			success_5 = false;
			if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::advanced_rule::AUTO_0>>((*pos)))) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  advanced_rule::AUTO_0");
				return {};
			}
			advanced_rule_AUTO_0_4 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::advanced_rule::AUTO_0>>((*pos));
			success_5 = true;
			pos++;
			success_10 = false;
			// grammar `@  rule::ast::full::part+;`: repeat named rule; collect every matched value
			success_13 = false;
			while (true) {
				auto repeat_ws_14 = pos;
				success_7 = false;
				if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*repeat_ws_14))) {
					__WS_6 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*repeat_ws_14));
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
			if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos))) {
				__WS_15 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos));
				success_16 = true;
				pos++;
			}
			success_18 = false;
			if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::advanced_rule::AUTO_1>>((*pos)))) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  advanced_rule::AUTO_1");
				return {};
			}
			advanced_rule_AUTO_1_17 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::advanced_rule::AUTO_1>>((*pos));
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
		template<typename IT>
		auto forward_declaration(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::forward_declaration, IT>{
			::ISPA_STD::Node<::Parser::Tokens, Types::forward_declaration::AUTO_0> forward_declaration_AUTO_0_0;
			bool success_1;
			::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
			bool success_3;
			::ISPA_STD::Node<::Parser::Tokens, Types::ID> ID_4;
			bool success_5;
			::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_6;
			bool success_7;
			::ISPA_STD::Node<::Parser::Tokens, Types::forward_declaration::AUTO_0> forward_declaration_AUTO_0_8;
			bool success_9;
			success_1 = false;
			if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::forward_declaration::AUTO_0>>((*pos)))) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  forward_declaration::AUTO_0");
				return {};
			}
			forward_declaration_AUTO_0_0 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::forward_declaration::AUTO_0>>((*pos));
			success_1 = true;
			pos++;
			success_3 = false;
			if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos))) {
				__WS_2 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos));
				success_3 = true;
				pos++;
			}
			success_5 = false;
			if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::ID>>((*pos)))) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar: @  ID");
				return {};
			}
			ID_4 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::ID>>((*pos));
			success_5 = true;
			pos++;
			success_7 = false;
			if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos))) {
				__WS_6 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos));
				success_7 = true;
				pos++;
			}
			success_9 = false;
			if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::forward_declaration::AUTO_0>>((*pos)))) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  forward_declaration::AUTO_0");
				return {};
			}
			forward_declaration_AUTO_0_8 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::forward_declaration::AUTO_0>>((*pos));
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
		template<typename IT>
		auto rule_nested_rule(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::rule::nested_rule, IT>{
			::ISPA_STD::Node<::Parser::Tokens, Types::rule::nested_rule::AUTO_0> rule_nested_rule_AUTO_0_0;
			bool success_1;
			::ISPA_STD::MatchResult<Rules, Types::grammar, IT> grammar_2;
			bool success_3;
			success_1 = false;
			if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::rule::nested_rule::AUTO_0>>((*pos)))) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  rule::nested_rule::AUTO_0");
				return {};
			}
			rule_nested_rule_AUTO_0_0 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::rule::nested_rule::AUTO_0>>((*pos));
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
		template<typename IT>
		auto rule_value_counter(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::rule::value::counter, IT>{
			::ISPA_STD::Node<::Parser::Tokens, Types::rule::value::QUANTIFIER> rule_value_QUANTIFIER_0;
			bool success_1;
			::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
			bool success_3;
			::ISPA_STD::MatchResult<Rules, Types::rule::value::counter::bounded, IT> rule_value_counter_bounded_4;
			bool success_5;
			success_1 = false;
			if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::rule::value::QUANTIFIER>>((*pos)))) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar: @  rule::value::QUANTIFIER");
				return {};
			}
			rule_value_QUANTIFIER_0 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::rule::value::QUANTIFIER>>((*pos));
			success_1 = true;
			pos++;
			success_3 = false;
			if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos))) {
				__WS_2 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos));
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
		template<typename IT>
		auto advanced_rule_match(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::advanced_rule::match, IT>{
			::ISPA_STD::Node<::Parser::Tokens, Types::advanced_rule::match::AUTO_0> advanced_rule_match_AUTO_0_0;
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
			std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Tokens, Types::advanced_rule::match::AUTO_0>, ::ISPA_STD::Node<::Parser::Rules, Types::advanced_rule::match::unpack>> _13;
			bool success_14;
			::ISPA_STD::Node<::Parser::Tokens, Types::advanced_rule::match::AUTO_0> advanced_rule_match_AUTO_0_15;
			bool success_16;
			::ISPA_STD::MatchResult<Rules, Types::advanced_rule::match::unpack, IT> advanced_rule_match_unpack_17;
			bool success_18;
			success_1 = false;
			if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::advanced_rule::match::AUTO_0>>((*pos)))) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  advanced_rule::match::AUTO_0");
				return {};
			}
			advanced_rule_match_AUTO_0_0 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::advanced_rule::match::AUTO_0>>((*pos));
			success_1 = true;
			pos++;
			success_6 = false;
			// grammar `@  rule::value+;`: repeat named rule; collect every matched value
			success_9 = false;
			while (true) {
				auto repeat_ws_10 = pos;
				success_3 = false;
				if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*repeat_ws_10))) {
					__WS_2 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*repeat_ws_10));
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
			if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos))) {
				__WS_11 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos));
				success_12 = true;
				pos++;
			}
			success_14 = false;
			// grammar `@  ( advanced_rule::match::unpack |  advanced_rule::match::AUTO_0)`: choice; reset match status before selecting an alternative
			success_14 = false;
			auto lookahead_pos_1 = pos;
			switch (static_cast<Tokens>((*lookahead_pos_1).index())) {
				case Tokens::advanced_rule_match_AUTO_0: {
					lookahead_pos_1 = lookahead_pos_1;
					success_16 = false;
					if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::advanced_rule::match::AUTO_0>>((*lookahead_pos_1)))) {
						raise_error(*pos, "ISPA match failure: required token did not match | grammar:  advanced_rule::match::AUTO_0");
						return {};
					}
					advanced_rule_match_AUTO_0_15 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::advanced_rule::match::AUTO_0>>((*lookahead_pos_1));
					success_16 = true;
					lookahead_pos_1++;
					if (!success_16) {
						raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  advanced_rule::match::AUTO_0");
						return {};
					}
					_13 = advanced_rule_match_AUTO_0_15;
					success_14 = true;
					break;
				}
				case Tokens::forward_declaration_AUTO_0: {
					lookahead_pos_1 = lookahead_pos_1;
					success_18 = false;
					advanced_rule_match_unpack_17 = advanced_rule_match_unpack(lookahead_pos_1);
					if (!(advanced_rule_match_unpack_17.status)) {
						raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  advanced_rule::match::unpack");
						return {};
					}
					success_18 = true;
					lookahead_pos_1 = advanced_rule_match_unpack_17.it;
					if (!success_18) {
						raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  advanced_rule::match::unpack");
						return {};
					}
					_13 = advanced_rule_match_unpack_17.node;
					success_14 = true;
					break;
				}
			}
			pos = lookahead_pos_1;
			if (!success_14) {
				raise_error(*pos, "ISPA match failure: no LL(k) alternative matched | grammar: @  ( advanced_rule::match::unpack |  advanced_rule::match::AUTO_0)");
				return {};
			}
			Types::advanced_rule::match result;
			::ISPA_STD::assign_compatible(result.patterns, uvar_4);
			::ISPA_STD::assign_compatible(result.assign_names, _13);
			::ISPA_STD::MatchResult<Rules, Types::advanced_rule::match, IT> match_result;
			match_result.status = true;
			match_result.node.set_data(result);
			match_result.it = pos;
			return match_result;
		}
		template<typename IT>
		auto rule_ast(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::rule::ast, IT>{
			std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Rules, Types::rule::ast::single_value>, ::ISPA_STD::Node<::Parser::Rules, Types::rule::ast::full>, ::ISPA_STD::Node<::Parser::Rules, Types::rule::ast::abbr>> _0;
			bool success_1;
			::ISPA_STD::MatchResult<Rules, Types::rule::ast::single_value, IT> rule_ast_single_value_2;
			bool success_3;
			::ISPA_STD::MatchResult<Rules, Types::rule::ast::abbr, IT> rule_ast_abbr_4;
			bool success_5;
			::ISPA_STD::MatchResult<Rules, Types::rule::ast::full, IT> rule_ast_full_6;
			bool success_7;
			success_1 = false;
			// grammar `@  ( rule::ast::abbr |  rule::ast::full |  rule::ast::single_value)`: choice; reset match status before selecting an alternative
			success_1 = false;
			auto lookahead_pos_1 = pos;
			switch (static_cast<Tokens>((*lookahead_pos_1).index())) {
				case Tokens::advanced_rule_AUTO_0: {
					lookahead_pos_1 = lookahead_pos_1;
					success_3 = false;
					rule_ast_single_value_2 = rule_ast_single_value(lookahead_pos_1);
					if (!(rule_ast_single_value_2.status)) {
						raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  rule::ast::single_value");
						return {};
					}
					success_3 = true;
					lookahead_pos_1 = rule_ast_single_value_2.it;
					if (!success_3) {
						raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  rule::ast::single_value");
						return {};
					}
					_0 = rule_ast_single_value_2.node;
					success_1 = true;
					break;
				}
				case Tokens::rule_value_ast_capture_AUTO_0: {
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
				case Tokens::rule_value_var_capture_AUTO_0: {
					lookahead_pos_1 = lookahead_pos_1;
					success_7 = false;
					rule_ast_full_6 = rule_ast_full(lookahead_pos_1);
					if (!(rule_ast_full_6.status)) {
						raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  rule::ast::full");
						return {};
					}
					success_7 = true;
					lookahead_pos_1 = rule_ast_full_6.it;
					if (!success_7) {
						raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  rule::ast::full");
						return {};
					}
					_0 = rule_ast_full_6.node;
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
		template<typename IT>
		auto rule_value_ast_capture(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::rule::value::ast_capture, IT>{
			::ISPA_STD::Node<::Parser::Tokens, Types::rule::value::ast_capture::AUTO_0> rule_value_ast_capture_AUTO_0_0;
			bool success_1;
			::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
			bool success_3;
			bool success_8;
			::ISPA_STD::Node<::Parser::Tokens, Types::ID> group_4;
			bool success_6;
			::ISPA_STD::Node<::Parser::Tokens, Types::ID> uvar_5;
			::ISPA_STD::Node<::Parser::Tokens, Types::ID> ID_7;
			success_1 = false;
			if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::rule::value::ast_capture::AUTO_0>>((*pos)))) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  rule::value::ast_capture::AUTO_0");
				return {};
			}
			rule_value_ast_capture_AUTO_0_0 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::rule::value::ast_capture::AUTO_0>>((*pos));
			success_1 = true;
			pos++;
			success_3 = false;
			if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos))) {
				__WS_2 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos));
				success_3 = true;
				pos++;
			}
			success_6 = false;
			auto begin_9 = pos;
			success_8 = false;
			// grammar ` (@  ID)?;`: optional group; try at most once
			while (true) {
				// grammar ` (@  ID)?;`: optional body; failed alternative leaves this group
				if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::ID>>((*begin_9)))) {
					// speculative match failed (diagnostic suppressed): @  ID
					break;
				}
				ID_7 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::ID>>((*begin_9));
				success_8 = true;
				begin_9++;
				break;
			}
			if (success_8) {
				group_4 = ID_7;
				success_6 = true;
				::ISPA_STD::assign_compatible(uvar_5, group_4);
			}
			// grammar ` (@  ID)?;`: optional group end; release saved position
			pos = begin_9;
			Types::rule::value::ast_capture result;
			::ISPA_STD::assign_compatible(result.value, ID_7);
			::ISPA_STD::MatchResult<Rules, Types::rule::value::ast_capture, IT> match_result;
			match_result.status = true;
			match_result.node.set_data(result);
			match_result.it = pos;
			return match_result;
		}
		template<typename IT>
		auto expr(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::expr, IT>{
			::ISPA_STD::Node<::Parser::Tokens, Types::expr::AUTO_0> expr_AUTO_0_0;
			bool success_1;
			::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
			bool success_3;
			::ISPA_STD::Node<::Parser::Tokens, Types::ID> ID_4;
			bool success_5;
			::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_6;
			bool success_7;
			::ISPA_STD::Node<::Parser::Tokens, Types::expr::AUTO_1> expr_AUTO_1_8;
			bool success_9;
			success_1 = false;
			if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::expr::AUTO_0>>((*pos)))) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar: @  expr::AUTO_0");
				return {};
			}
			expr_AUTO_0_0 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::expr::AUTO_0>>((*pos));
			success_1 = true;
			pos++;
			success_3 = false;
			if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos))) {
				__WS_2 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos));
				success_3 = true;
				pos++;
			}
			success_5 = false;
			if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::ID>>((*pos)))) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  ID");
				return {};
			}
			ID_4 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::ID>>((*pos));
			success_5 = true;
			pos++;
			success_7 = false;
			if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos))) {
				__WS_6 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos));
				success_7 = true;
				pos++;
			}
			success_9 = false;
			if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::expr::AUTO_1>>((*pos)))) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  expr::AUTO_1");
				return {};
			}
			expr_AUTO_1_8 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::expr::AUTO_1>>((*pos));
			success_9 = true;
			pos++;
			Types::expr result;
			::ISPA_STD::assign_compatible(result.value, expr_AUTO_0_0);
			::ISPA_STD::MatchResult<Rules, Types::expr, IT> match_result;
			match_result.status = true;
			match_result.node.set_data(result);
			match_result.it = pos;
			return match_result;
		}
		template<typename IT>
		auto rule_value_counter_bounded(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::rule::value::counter::bounded, IT>{
			::ISPA_STD::Node<::Parser::Tokens, Types::rule::value::counter::bounded::AUTO_0> rule_value_counter_bounded_AUTO_0_0;
			bool success_1;
			::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
			bool success_3;
			std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Rules, Types::explicit_expr>, ::ISPA_STD::Node<::Parser::Tokens, Types::ID>, ::ISPA_STD::Node<::Parser::Tokens, Types::NUMBER>> _4;
			bool success_5;
			::ISPA_STD::Node<::Parser::Tokens, Types::ID> ID_6;
			bool success_7;
			::ISPA_STD::Node<::Parser::Tokens, Types::NUMBER> NUMBER_8;
			bool success_9;
			::ISPA_STD::MatchResult<Rules, Types::explicit_expr, IT> explicit_expr_10;
			bool success_11;
			success_1 = false;
			if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::rule::value::counter::bounded::AUTO_0>>((*pos)))) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  rule::value::counter::bounded::AUTO_0");
				return {};
			}
			rule_value_counter_bounded_AUTO_0_0 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::rule::value::counter::bounded::AUTO_0>>((*pos));
			success_1 = true;
			pos++;
			success_3 = false;
			if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos))) {
				__WS_2 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos));
				success_3 = true;
				pos++;
			}
			success_5 = false;
			// grammar `@  ( NUMBER |  ID |  explicit_expr)`: choice; reset match status before selecting an alternative
			success_5 = false;
			auto lookahead_pos_1 = pos;
			switch (static_cast<Tokens>((*lookahead_pos_1).index())) {
				case Tokens::ID: {
					lookahead_pos_1 = lookahead_pos_1;
					success_7 = false;
					if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::ID>>((*lookahead_pos_1)))) {
						raise_error(*pos, "ISPA match failure: required token did not match | grammar:  ID");
						return {};
					}
					ID_6 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::ID>>((*lookahead_pos_1));
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
					if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::NUMBER>>((*lookahead_pos_1)))) {
						raise_error(*pos, "ISPA match failure: required token did not match | grammar:  NUMBER");
						return {};
					}
					NUMBER_8 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::NUMBER>>((*lookahead_pos_1));
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
				case Tokens::rule_value_group_AUTO_0: {
					lookahead_pos_1 = lookahead_pos_1;
					success_11 = false;
					explicit_expr_10 = explicit_expr(lookahead_pos_1);
					if (!(explicit_expr_10.status)) {
						raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  explicit_expr");
						return {};
					}
					success_11 = true;
					lookahead_pos_1 = explicit_expr_10.it;
					if (!success_11) {
						raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  explicit_expr");
						return {};
					}
					_4 = explicit_expr_10.node;
					success_5 = true;
					break;
				}
			}
			pos = lookahead_pos_1;
			if (!success_5) {
				raise_error(*pos, "ISPA match failure: no LL(k) alternative matched | grammar: @  ( NUMBER |  ID |  explicit_expr)");
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
		template<typename IT>
		auto rule_value(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::rule::value, IT>{
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
			if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos))) {
				__WS_2 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos));
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
			if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos))) {
				__WS_6 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos));
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
				if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*repeat_ws_17))) {
					__WS_10 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*repeat_ws_17));
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
			if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos))) {
				__WS_18 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos));
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
			if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos))) {
				__WS_22 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos));
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
		template<typename IT>
		auto rule_value_var_capture(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::rule::value::var_capture, IT>{
			::ISPA_STD::Node<::Parser::Tokens, Types::rule::value::var_capture::AUTO_0> rule_value_var_capture_AUTO_0_0;
			bool success_1;
			::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
			bool success_3;
			::ISPA_STD::Node<::Parser::Tokens, Types::ID> ID_4;
			bool success_5;
			success_1 = false;
			if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::rule::value::var_capture::AUTO_0>>((*pos)))) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  rule::value::var_capture::AUTO_0");
				return {};
			}
			rule_value_var_capture_AUTO_0_0 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::rule::value::var_capture::AUTO_0>>((*pos));
			success_1 = true;
			pos++;
			success_3 = false;
			if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos))) {
				__WS_2 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos));
				success_3 = true;
				pos++;
			}
			success_5 = false;
			if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::ID>>((*pos)))) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar: @  ID");
				return {};
			}
			ID_4 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::ID>>((*pos));
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
		template<typename IT>
		auto advanced_rule(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::advanced_rule, IT>{
			::ISPA_STD::Node<::Parser::Tokens, Types::advanced_rule::AUTO_0> advanced_rule_AUTO_0_0;
			bool success_1;
			::ISPA_STD::MatchResult<Rules, Types::advanced_rule::dep_decl, IT> advanced_rule_dep_decl_5;
			bool success_6;
			::ISPA_STD::Node<::Parser::Rules, Types::advanced_rule::dep_decl> element_7;
			std::vector<::ISPA_STD::Node<::Parser::Rules, Types::advanced_rule::dep_decl>> shadow_8;
			std::vector<::ISPA_STD::Node<::Parser::Rules, Types::advanced_rule::dep_decl>> uvar_4;
			::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
			bool success_3;
			bool success_16;
			std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Rules, Types::stmt>, ::ISPA_STD::Node<::Parser::Rules, Types::advanced_rule::match>> group_12;
			bool success_14;
			std::vector<std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Rules, Types::stmt>, ::ISPA_STD::Node<::Parser::Rules, Types::advanced_rule::match>>> shadow_27;
			std::vector<std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Rules, Types::stmt>, ::ISPA_STD::Node<::Parser::Rules, Types::advanced_rule::match>>> uvar_13;
			::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_10;
			bool success_11;
			std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Rules, Types::stmt>, ::ISPA_STD::Node<::Parser::Rules, Types::advanced_rule::match>> _15;
			::ISPA_STD::MatchResult<Rules, Types::stmt, IT> stmt_18;
			bool success_19;
			::ISPA_STD::Node<::Parser::Rules, Types::stmt> element_20;
			std::vector<::ISPA_STD::Node<::Parser::Rules, Types::stmt>> shadow_21;
			::ISPA_STD::Node<::Parser::Rules, Types::stmt> uvar_17;
			::ISPA_STD::MatchResult<Rules, Types::advanced_rule::match, IT> advanced_rule_match_23;
			bool success_24;
			::ISPA_STD::Node<::Parser::Rules, Types::advanced_rule::match> element_25;
			std::vector<::ISPA_STD::Node<::Parser::Rules, Types::advanced_rule::match>> shadow_26;
			::ISPA_STD::Node<::Parser::Rules, Types::advanced_rule::match> uvar_22;
			::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_30;
			bool success_31;
			::ISPA_STD::Node<::Parser::Tokens, Types::advanced_rule::AUTO_1> advanced_rule_AUTO_1_32;
			bool success_33;
			success_1 = false;
			if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::advanced_rule::AUTO_0>>((*pos)))) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  advanced_rule::AUTO_0");
				return {};
			}
			advanced_rule_AUTO_0_0 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::advanced_rule::AUTO_0>>((*pos));
			success_1 = true;
			pos++;
			success_6 = false;
			// grammar `@  advanced_rule::dep_decl*;`: repeat named rule; collect every matched value
			while (true) {
				auto repeat_ws_9 = pos;
				success_3 = false;
				if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*repeat_ws_9))) {
					__WS_2 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*repeat_ws_9));
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
				if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*repeat_ws_29))) {
					__WS_10 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*repeat_ws_29));
					success_11 = true;
					repeat_ws_29++;
				}
				skip_spaces<Types::__WS>(repeat_ws_29);
				// grammar ` ( advanced_rule::match |  stmt)`: choice; reset match status before selecting an alternative
				success_16 = false;
				auto lookahead_pos_1 = repeat_ws_29;
				switch (static_cast<Tokens>((*lookahead_pos_1).index())) {
					case Tokens::advanced_rule_AUTO_0: {
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
					case Tokens::advanced_rule_match_AUTO_0: {
						lookahead_pos_1 = lookahead_pos_1;
						success_24 = false;
						advanced_rule_match_23 = advanced_rule_match(lookahead_pos_1);
						if (!(advanced_rule_match_23.status)) {
							// speculative match failed (diagnostic suppressed):  advanced_rule::match
							break;
						}
						success_24 = true;
						lookahead_pos_1 = advanced_rule_match_23.it;
						element_25 = advanced_rule_match_23.node;
						shadow_26.push_back(element_25);
						if (!success_24) {
							// speculative match failed (diagnostic suppressed):  advanced_rule::match
							break;
						}
						_15 = advanced_rule_match_23.node;
						success_16 = true;
						break;
					}
				}
				repeat_ws_29 = lookahead_pos_1;
				if (!success_16) {
					// speculative match failed (diagnostic suppressed):  ( advanced_rule::match |  stmt)
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
			if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos))) {
				__WS_30 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos));
				success_31 = true;
				pos++;
			}
			success_33 = false;
			if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::advanced_rule::AUTO_1>>((*pos)))) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  advanced_rule::AUTO_1");
				return {};
			}
			advanced_rule_AUTO_1_32 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::advanced_rule::AUTO_1>>((*pos));
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
		template<typename IT>
		auto advanced_rule_dep_decl(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::advanced_rule::dep_decl, IT>{
			::ISPA_STD::Node<::Parser::Tokens, Types::advanced_rule::dep_decl::AUTO_0> advanced_rule_dep_decl_AUTO_0_0;
			bool success_1;
			::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
			bool success_3;
			::ISPA_STD::MatchResult<Rules, Types::forward_declaration, IT> forward_declaration_4;
			bool success_5;
			success_1 = false;
			if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::advanced_rule::dep_decl::AUTO_0>>((*pos)))) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  advanced_rule::dep_decl::AUTO_0");
				return {};
			}
			advanced_rule_dep_decl_AUTO_0_0 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::advanced_rule::dep_decl::AUTO_0>>((*pos));
			success_1 = true;
			pos++;
			success_3 = false;
			if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos))) {
				__WS_2 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos));
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
		template<typename IT>
		auto rule_ast_single_value(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::rule::ast::single_value, IT>{
			::ISPA_STD::Node<::Parser::Tokens, Types::advanced_rule::AUTO_0> advanced_rule_AUTO_0_0;
			bool success_1;
			::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
			bool success_3;
			::ISPA_STD::MatchResult<Rules, Types::expr, IT> expr_4;
			bool success_5;
			::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_6;
			bool success_7;
			::ISPA_STD::Node<::Parser::Tokens, Types::advanced_rule::AUTO_1> advanced_rule_AUTO_1_8;
			bool success_9;
			success_1 = false;
			if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::advanced_rule::AUTO_0>>((*pos)))) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  advanced_rule::AUTO_0");
				return {};
			}
			advanced_rule_AUTO_0_0 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::advanced_rule::AUTO_0>>((*pos));
			success_1 = true;
			pos++;
			success_3 = false;
			if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos))) {
				__WS_2 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos));
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
			if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos))) {
				__WS_6 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos));
				success_7 = true;
				pos++;
			}
			success_9 = false;
			if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::advanced_rule::AUTO_1>>((*pos)))) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  advanced_rule::AUTO_1");
				return {};
			}
			advanced_rule_AUTO_1_8 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::advanced_rule::AUTO_1>>((*pos));
			success_9 = true;
			pos++;
			Types::rule::ast::single_value result;
			::ISPA_STD::assign_compatible(result.value, expr_4.node);
			::ISPA_STD::MatchResult<Rules, Types::rule::ast::single_value, IT> match_result;
			match_result.status = true;
			match_result.node.set_data(result);
			match_result.it = pos;
			return match_result;
		}
		template<typename IT>
		auto rule_value_group(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::rule::value::group, IT>{
			::ISPA_STD::Node<::Parser::Tokens, Types::rule::value::group::AUTO_0> rule_value_group_AUTO_0_0;
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
			::ISPA_STD::Node<::Parser::Tokens, Types::expr::AUTO_1> expr_AUTO_1_13;
			bool success_14;
			success_1 = false;
			if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::rule::value::group::AUTO_0>>((*pos)))) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  rule::value::group::AUTO_0");
				return {};
			}
			rule_value_group_AUTO_0_0 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::rule::value::group::AUTO_0>>((*pos));
			success_1 = true;
			pos++;
			success_6 = false;
			// grammar `@  rule::value+;`: repeat named rule; collect every matched value
			success_9 = false;
			while (true) {
				auto repeat_ws_10 = pos;
				success_3 = false;
				if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*repeat_ws_10))) {
					__WS_2 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*repeat_ws_10));
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
			if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos))) {
				__WS_11 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos));
				success_12 = true;
				pos++;
			}
			success_14 = false;
			if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::expr::AUTO_1>>((*pos)))) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  expr::AUTO_1");
				return {};
			}
			expr_AUTO_1_13 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::expr::AUTO_1>>((*pos));
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
		template<typename IT>
		auto rule_ast_full_part(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::rule::ast::full::part, IT>{
			::ISPA_STD::Node<::Parser::Tokens, Types::ID> ID_0;
			bool success_1;
			::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
			bool success_3;
			::ISPA_STD::Node<::Parser::Tokens, Types::rule::ast::full::part::AUTO_0> rule_ast_full_part_AUTO_0_4;
			bool success_5;
			::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_6;
			bool success_7;
			::ISPA_STD::MatchResult<Rules, Types::expr, IT> expr_8;
			bool success_9;
			success_1 = false;
			if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::ID>>((*pos)))) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar: @  ID");
				return {};
			}
			ID_0 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::ID>>((*pos));
			success_1 = true;
			pos++;
			success_3 = false;
			if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos))) {
				__WS_2 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos));
				success_3 = true;
				pos++;
			}
			success_5 = false;
			if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::rule::ast::full::part::AUTO_0>>((*pos)))) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  rule::ast::full::part::AUTO_0");
				return {};
			}
			rule_ast_full_part_AUTO_0_4 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::rule::ast::full::part::AUTO_0>>((*pos));
			success_5 = true;
			pos++;
			success_7 = false;
			if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos))) {
				__WS_6 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos));
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
		template<typename IT>
		auto rule_value_alternative(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::rule::value::alternative, IT>{
			::ISPA_STD::Node<::Parser::Tokens, Types::rule::value::alternative::AUTO_0> rule_value_alternative_AUTO_0_0;
			bool success_1;
			::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
			bool success_3;
			::ISPA_STD::MatchResult<Rules, Types::rule::value::pattern, IT> rule_value_pattern_4;
			bool success_5;
			success_1 = false;
			if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::rule::value::alternative::AUTO_0>>((*pos)))) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  rule::value::alternative::AUTO_0");
				return {};
			}
			rule_value_alternative_AUTO_0_0 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::rule::value::alternative::AUTO_0>>((*pos));
			success_1 = true;
			pos++;
			success_3 = false;
			if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos))) {
				__WS_2 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos));
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
		template<typename IT>
		auto rule(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::rule, IT>{
			::ISPA_STD::Node<::Parser::Tokens, Types::rule::ast::full::part::AUTO_0> rule_ast_full_part_AUTO_0_0;
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
			::ISPA_STD::Node<::Parser::Tokens, Types::advanced_rule::match::AUTO_0> advanced_rule_match_AUTO_0_25;
			bool success_26;
			success_1 = false;
			if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::rule::ast::full::part::AUTO_0>>((*pos)))) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  rule::ast::full::part::AUTO_0");
				return {};
			}
			rule_ast_full_part_AUTO_0_0 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::rule::ast::full::part::AUTO_0>>((*pos));
			success_1 = true;
			pos++;
			success_6 = false;
			// grammar `@  rule::value+;`: repeat named rule; collect every matched value
			success_9 = false;
			while (true) {
				auto repeat_ws_10 = pos;
				success_3 = false;
				if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*repeat_ws_10))) {
					__WS_2 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*repeat_ws_10));
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
			if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos))) {
				__WS_11 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos));
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
				if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*repeat_ws_22))) {
					__WS_15 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*repeat_ws_22));
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
			if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos))) {
				__WS_23 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos));
				success_24 = true;
				pos++;
			}
			success_26 = false;
			if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::advanced_rule::match::AUTO_0>>((*pos)))) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  advanced_rule::match::AUTO_0");
				return {};
			}
			advanced_rule_match_AUTO_0_25 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::advanced_rule::match::AUTO_0>>((*pos));
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
		template<typename IT>
		auto grammar_modifier(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::grammar::modifier, IT>{
			::ISPA_STD::Node<::Parser::Tokens, Types::grammar::modifier::AUTO_0> grammar_modifier_AUTO_0_0;
			bool success_1;
			::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
			bool success_3;
			::ISPA_STD::Node<::Parser::Tokens, Types::ID> ID_4;
			bool success_5;
			::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_6;
			bool success_7;
			::ISPA_STD::Node<::Parser::Tokens, Types::grammar::modifier::AUTO_1> grammar_modifier_AUTO_1_8;
			bool success_9;
			success_1 = false;
			if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::grammar::modifier::AUTO_0>>((*pos)))) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  grammar::modifier::AUTO_0");
				return {};
			}
			grammar_modifier_AUTO_0_0 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::grammar::modifier::AUTO_0>>((*pos));
			success_1 = true;
			pos++;
			success_3 = false;
			if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos))) {
				__WS_2 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos));
				success_3 = true;
				pos++;
			}
			success_5 = false;
			if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::ID>>((*pos)))) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar: @  ID");
				return {};
			}
			ID_4 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::ID>>((*pos));
			success_5 = true;
			pos++;
			success_7 = false;
			if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos))) {
				__WS_6 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos));
				success_7 = true;
				pos++;
			}
			success_9 = false;
			if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::grammar::modifier::AUTO_1>>((*pos)))) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  grammar::modifier::AUTO_1");
				return {};
			}
			grammar_modifier_AUTO_1_8 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::grammar::modifier::AUTO_1>>((*pos));
			success_9 = true;
			pos++;
			Types::grammar::modifier result;
			::ISPA_STD::assign_compatible(result.value, ID_4);
			::ISPA_STD::MatchResult<Rules, Types::grammar::modifier, IT> match_result;
			match_result.status = true;
			match_result.node.set_data(result);
			match_result.it = pos;
			return match_result;
		}
		template<typename IT>
		auto grammar(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::grammar, IT>{
			::ISPA_STD::MatchResult<Rules, Types::name, IT> name_0;
			bool success_1;
			::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
			bool success_3;
			std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Rules, Types::advanced_rule>, ::ISPA_STD::Node<::Parser::Rules, Types::rule>> _4;
			bool success_5;
			::ISPA_STD::MatchResult<Rules, Types::advanced_rule, IT> advanced_rule_6;
			bool success_7;
			::ISPA_STD::MatchResult<Rules, Types::rule, IT> rule_8;
			bool success_9;
			success_1 = false;
			name_0 = name(pos);
			if (!(name_0.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar: @  name");
				return {};
			}
			success_1 = true;
			pos = name_0.it;
			success_3 = false;
			if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos))) {
				__WS_2 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos));
				success_3 = true;
				pos++;
			}
			success_5 = false;
			// grammar `@  ( rule |  advanced_rule)`: choice; reset match status before selecting an alternative
			success_5 = false;
			auto lookahead_pos_1 = pos;
			switch (static_cast<Tokens>((*lookahead_pos_1).index())) {
				case Tokens::advanced_rule_AUTO_0: {
					lookahead_pos_1 = lookahead_pos_1;
					success_7 = false;
					advanced_rule_6 = advanced_rule(lookahead_pos_1);
					if (!(advanced_rule_6.status)) {
						raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  advanced_rule");
						return {};
					}
					success_7 = true;
					lookahead_pos_1 = advanced_rule_6.it;
					if (!success_7) {
						raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  advanced_rule");
						return {};
					}
					_4 = advanced_rule_6.node;
					success_5 = true;
					break;
				}
				case Tokens::rule_ast_full_part_AUTO_0: {
					lookahead_pos_1 = lookahead_pos_1;
					success_9 = false;
					rule_8 = rule(lookahead_pos_1);
					if (!(rule_8.status)) {
						raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  rule");
						return {};
					}
					success_9 = true;
					lookahead_pos_1 = rule_8.it;
					if (!success_9) {
						raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  rule");
						return {};
					}
					_4 = rule_8.node;
					success_5 = true;
					break;
				}
			}
			pos = lookahead_pos_1;
			if (!success_5) {
				raise_error(*pos, "ISPA match failure: no LL(k) alternative matched | grammar: @  ( rule |  advanced_rule)");
				return {};
			}
			Types::grammar result;
			::ISPA_STD::assign_compatible(result.name, name_0);
			::ISPA_STD::assign_compatible(result.entry, _4);
			::ISPA_STD::MatchResult<Rules, Types::grammar, IT> match_result;
			match_result.status = true;
			match_result.node.set_data(result);
			match_result.it = pos;
			return match_result;
		}
		template<typename IT>
		auto rule_value_pattern(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::rule::value::pattern, IT>{
			std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Tokens, Types::rule::value::CGROUP>, ::ISPA_STD::Node<::Parser::Tokens, Types::rule::value::STRING>, ::ISPA_STD::Node<::Parser::Tokens, Types::rule::value::SPACE>, ::ISPA_STD::Node<::Parser::Rules, Types::rule::value::group>, ::ISPA_STD::Node<::Parser::Rules, Types::name>> _0;
			bool success_1;
			::ISPA_STD::MatchResult<Rules, Types::name, IT> name_2;
			bool success_3;
			::ISPA_STD::Node<::Parser::Tokens, Types::rule::value::CGROUP> rule_value_CGROUP_4;
			bool success_5;
			::ISPA_STD::Node<::Parser::Tokens, Types::rule::value::SPACE> rule_value_SPACE_6;
			bool success_7;
			::ISPA_STD::Node<::Parser::Tokens, Types::rule::value::STRING> rule_value_STRING_8;
			bool success_9;
			::ISPA_STD::MatchResult<Rules, Types::rule::value::group, IT> rule_value_group_10;
			bool success_11;
			success_1 = false;
			// grammar `@  ( name |  rule::value::group |  rule::value::STRING |  rule::value::CGROUP |  rule::value::SPACE)`: choice; reset match status before selecting an alternative
			success_1 = false;
			auto lookahead_pos_1 = pos;
			switch (static_cast<Tokens>((*lookahead_pos_1).index())) {
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
				case Tokens::rule_value_CGROUP: {
					lookahead_pos_1 = lookahead_pos_1;
					success_5 = false;
					if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::rule::value::CGROUP>>((*lookahead_pos_1)))) {
						raise_error(*pos, "ISPA match failure: required token did not match | grammar:  rule::value::CGROUP");
						return {};
					}
					rule_value_CGROUP_4 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::rule::value::CGROUP>>((*lookahead_pos_1));
					success_5 = true;
					lookahead_pos_1++;
					if (!success_5) {
						raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  rule::value::CGROUP");
						return {};
					}
					_0 = rule_value_CGROUP_4;
					success_1 = true;
					break;
				}
				case Tokens::rule_value_SPACE: {
					lookahead_pos_1 = lookahead_pos_1;
					success_7 = false;
					if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::rule::value::SPACE>>((*lookahead_pos_1)))) {
						raise_error(*pos, "ISPA match failure: required token did not match | grammar:  rule::value::SPACE");
						return {};
					}
					rule_value_SPACE_6 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::rule::value::SPACE>>((*lookahead_pos_1));
					success_7 = true;
					lookahead_pos_1++;
					if (!success_7) {
						raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  rule::value::SPACE");
						return {};
					}
					_0 = rule_value_SPACE_6;
					success_1 = true;
					break;
				}
				case Tokens::rule_value_STRING: {
					lookahead_pos_1 = lookahead_pos_1;
					success_9 = false;
					if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::rule::value::STRING>>((*lookahead_pos_1)))) {
						raise_error(*pos, "ISPA match failure: required token did not match | grammar:  rule::value::STRING");
						return {};
					}
					rule_value_STRING_8 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::rule::value::STRING>>((*lookahead_pos_1));
					success_9 = true;
					lookahead_pos_1++;
					if (!success_9) {
						raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  rule::value::STRING");
						return {};
					}
					_0 = rule_value_STRING_8;
					success_1 = true;
					break;
				}
				case Tokens::rule_value_group_AUTO_0: {
					lookahead_pos_1 = lookahead_pos_1;
					success_11 = false;
					rule_value_group_10 = rule_value_group(lookahead_pos_1);
					if (!(rule_value_group_10.status)) {
						raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  rule::value::group");
						return {};
					}
					success_11 = true;
					lookahead_pos_1 = rule_value_group_10.it;
					if (!success_11) {
						raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  rule::value::group");
						return {};
					}
					_0 = rule_value_group_10.node;
					success_1 = true;
					break;
				}
			}
			pos = lookahead_pos_1;
			if (!success_1) {
				raise_error(*pos, "ISPA match failure: no LL(k) alternative matched | grammar: @  ( name |  rule::value::group |  rule::value::STRING |  rule::value::CGROUP |  rule::value::SPACE)");
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
		template<typename IT>
		auto main(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::main, IT>{
			bool success_4;
			std::vector<std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Rules, Types::fail_block>, ::ISPA_STD::Node<::Parser::Rules, Types::grammar>>> shadow_15;
			std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Rules, Types::fail_block>, ::ISPA_STD::Node<::Parser::Rules, Types::grammar>> group_0;
			bool success_2;
			std::vector<std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Rules, Types::fail_block>, ::ISPA_STD::Node<::Parser::Rules, Types::grammar>>> shadow_16;
			std::vector<std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Rules, Types::fail_block>, ::ISPA_STD::Node<::Parser::Rules, Types::grammar>>> uvar_1;
			bool success_18;
			std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Rules, Types::fail_block>, ::ISPA_STD::Node<::Parser::Rules, Types::grammar>> _3;
			::ISPA_STD::MatchResult<Rules, Types::grammar, IT> grammar_6;
			bool success_7;
			::ISPA_STD::Node<::Parser::Rules, Types::grammar> element_8;
			std::vector<::ISPA_STD::Node<::Parser::Rules, Types::grammar>> shadow_9;
			::ISPA_STD::Node<::Parser::Rules, Types::grammar> uvar_5;
			::ISPA_STD::MatchResult<Rules, Types::fail_block, IT> fail_block_11;
			bool success_12;
			::ISPA_STD::Node<::Parser::Rules, Types::fail_block> element_13;
			std::vector<::ISPA_STD::Node<::Parser::Rules, Types::fail_block>> shadow_14;
			::ISPA_STD::Node<::Parser::Rules, Types::fail_block> uvar_10;
			success_2 = false;
			auto begin_17 = pos;
			success_18 = false;
			while (true) {
				skip_spaces<Types::__WS>(begin_17);
				// grammar `@  ( grammar |  fail_block)`: choice; reset match status before selecting an alternative
				success_4 = false;
				auto lookahead_pos_1 = begin_17;
				switch (static_cast<Tokens>((*lookahead_pos_1).index())) {
					case Tokens::ID: {
						lookahead_pos_1 = lookahead_pos_1;
						success_7 = false;
						grammar_6 = grammar(lookahead_pos_1);
						if (!(grammar_6.status)) {
							// speculative match failed (diagnostic suppressed):  grammar
							break;
						}
						success_7 = true;
						lookahead_pos_1 = grammar_6.it;
						element_8 = grammar_6.node;
						shadow_9.push_back(element_8);
						if (!success_7) {
							// speculative match failed (diagnostic suppressed):  grammar
							break;
						}
						_3 = grammar_6.node;
						success_4 = true;
						break;
					}
					case Tokens::fail_block_AUTO_0: {
						lookahead_pos_1 = lookahead_pos_1;
						success_12 = false;
						fail_block_11 = fail_block(lookahead_pos_1);
						if (!(fail_block_11.status)) {
							// speculative match failed (diagnostic suppressed):  fail_block
							break;
						}
						success_12 = true;
						lookahead_pos_1 = fail_block_11.it;
						element_13 = fail_block_11.node;
						shadow_14.push_back(element_13);
						if (!success_12) {
							// speculative match failed (diagnostic suppressed):  fail_block
							break;
						}
						_3 = fail_block_11.node;
						success_4 = true;
						break;
					}
				}
				begin_17 = lookahead_pos_1;
				if (!success_4) {
					// speculative match failed (diagnostic suppressed): @  ( grammar |  fail_block)
					break;
				}
				if (success_4) {
					group_0 = _3;
					shadow_16.push_back(group_0);
					shadow_15.push_back(_3);
				}
				success_18 = true;
			}
			if (!success_18) {
				return {};
			}
			success_2 = true;
			::ISPA_STD::assign_compatible(uvar_1, shadow_16);
			pos = begin_17;
			Types::main result;
			::ISPA_STD::assign_compatible(result.value, shadow_15);
			::ISPA_STD::MatchResult<Rules, Types::main, IT> match_result;
			match_result.status = true;
			match_result.node.set_data(result);
			match_result.it = pos;
			return match_result;
		}
		template<typename IT>
		auto fail_block(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::fail_block, IT>{
			::ISPA_STD::Node<::Parser::Tokens, Types::fail_block::AUTO_0> fail_block_AUTO_0_0;
			bool success_1;
			::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
			bool success_3;
			::ISPA_STD::MatchResult<Rules, Types::name, IT> name_4;
			bool success_5;
			::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_6;
			bool success_7;
			std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Rules, Types::compound_statement>, ::ISPA_STD::Node<::Parser::Rules, Types::stmt>> _8;
			bool success_9;
			::ISPA_STD::MatchResult<Rules, Types::stmt, IT> stmt_10;
			bool success_11;
			::ISPA_STD::MatchResult<Rules, Types::compound_statement, IT> compound_statement_12;
			bool success_13;
			success_1 = false;
			if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::fail_block::AUTO_0>>((*pos)))) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  fail_block::AUTO_0");
				return {};
			}
			fail_block_AUTO_0_0 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::fail_block::AUTO_0>>((*pos));
			success_1 = true;
			pos++;
			success_3 = false;
			if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos))) {
				__WS_2 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos));
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
			if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos))) {
				__WS_6 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos));
				success_7 = true;
				pos++;
			}
			success_9 = false;
			// grammar `@  ( stmt |  compound_statement)`: choice; reset match status before selecting an alternative
			success_9 = false;
			auto lookahead_pos_1 = pos;
			switch (static_cast<Tokens>((*lookahead_pos_1).index())) {
				case Tokens::advanced_rule_AUTO_0: {
					lookahead_pos_1 = lookahead_pos_1;
					success_11 = false;
					stmt_10 = stmt(lookahead_pos_1);
					if (!(stmt_10.status)) {
						raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  stmt");
						return {};
					}
					success_11 = true;
					lookahead_pos_1 = stmt_10.it;
					if (!success_11) {
						raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  stmt");
						return {};
					}
					_8 = stmt_10.node;
					success_9 = true;
					break;
				}
				case Tokens::compound_statement_AUTO_0: {
					lookahead_pos_1 = lookahead_pos_1;
					success_13 = false;
					compound_statement_12 = compound_statement(lookahead_pos_1);
					if (!(compound_statement_12.status)) {
						raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  compound_statement");
						return {};
					}
					success_13 = true;
					lookahead_pos_1 = compound_statement_12.it;
					if (!success_13) {
						raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  compound_statement");
						return {};
					}
					_8 = compound_statement_12.node;
					success_9 = true;
					break;
				}
			}
			pos = lookahead_pos_1;
			if (!success_9) {
				raise_error(*pos, "ISPA match failure: no LL(k) alternative matched | grammar: @  ( stmt |  compound_statement)");
				return {};
			}
			Types::fail_block result;
			::ISPA_STD::assign_compatible(result.name, name_4);
			::ISPA_STD::assign_compatible(result.val, _8);
			::ISPA_STD::MatchResult<Rules, Types::fail_block, IT> match_result;
			match_result.status = true;
			match_result.node.set_data(result);
			match_result.it = pos;
			return match_result;
		}
		template<typename IT>
		auto rule_ast_abbr(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::rule::ast::abbr, IT>{
			::ISPA_STD::Node<::Parser::Tokens, Types::rule::value::ast_capture::AUTO_0> rule_value_ast_capture_AUTO_0_0;
			bool success_1;
			::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
			bool success_3;
			::ISPA_STD::Node<::Parser::Tokens, Types::advanced_rule::AUTO_0> advanced_rule_AUTO_0_4;
			bool success_5;
			::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_6;
			bool success_7;
			::ISPA_STD::Node<::Parser::Tokens, Types::ID> ID_9;
			bool success_10;
			std::vector<::ISPA_STD::Node<::Parser::Tokens, Types::ID>> uvar_8;
			std::vector<::ISPA_STD::Node<::Parser::Tokens, Types::ID>> shadow_11;
			bool success_12;
			::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_13;
			bool success_14;
			::ISPA_STD::Node<::Parser::Tokens, Types::advanced_rule::AUTO_1> advanced_rule_AUTO_1_15;
			bool success_16;
			success_1 = false;
			if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::rule::value::ast_capture::AUTO_0>>((*pos)))) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  rule::value::ast_capture::AUTO_0");
				return {};
			}
			rule_value_ast_capture_AUTO_0_0 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::rule::value::ast_capture::AUTO_0>>((*pos));
			success_1 = true;
			pos++;
			success_3 = false;
			if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos))) {
				__WS_2 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos));
				success_3 = true;
				pos++;
			}
			success_5 = false;
			if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::advanced_rule::AUTO_0>>((*pos)))) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  advanced_rule::AUTO_0");
				return {};
			}
			advanced_rule_AUTO_0_4 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::advanced_rule::AUTO_0>>((*pos));
			success_5 = true;
			pos++;
			success_7 = false;
			if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos))) {
				__WS_6 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos));
				success_7 = true;
				pos++;
			}
			success_10 = false;
			success_12 = false;
			while (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::ID>>((*pos))) {
				ID_9 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::ID>>((*pos));
				success_10 = true;
				pos++;
				shadow_11.push_back(ID_9);
				success_12 = true;
			}
			if (!success_12) {
				return {};
			}
			// grammar `@  ID+;`: repeat token; export all matched elements
			::ISPA_STD::assign_compatible(uvar_8, shadow_11);
			success_14 = false;
			if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos))) {
				__WS_13 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos));
				success_14 = true;
				pos++;
			}
			success_16 = false;
			if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::advanced_rule::AUTO_1>>((*pos)))) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  advanced_rule::AUTO_1");
				return {};
			}
			advanced_rule_AUTO_1_15 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::advanced_rule::AUTO_1>>((*pos));
			success_16 = true;
			pos++;
			Types::rule::ast::abbr result;
			::ISPA_STD::assign_compatible(result.value, uvar_8);
			::ISPA_STD::MatchResult<Rules, Types::rule::ast::abbr, IT> match_result;
			match_result.status = true;
			match_result.node.set_data(result);
			match_result.it = pos;
			return match_result;
		}
		template<typename IT>
		auto params(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::params, IT>{
			::ISPA_STD::Node<::Parser::Tokens, Types::rule::value::group::AUTO_0> rule_value_group_AUTO_0_0;
			bool success_1;
			::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
			bool success_3;
			::ISPA_STD::MatchResult<Rules, Types::param, IT> param_4;
			bool success_5;
			::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_6;
			bool success_7;
			::ISPA_STD::Node<::Parser::Tokens, Types::expr::AUTO_1> expr_AUTO_1_8;
			bool success_9;
			success_1 = false;
			if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::rule::value::group::AUTO_0>>((*pos)))) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  rule::value::group::AUTO_0");
				return {};
			}
			rule_value_group_AUTO_0_0 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::rule::value::group::AUTO_0>>((*pos));
			success_1 = true;
			pos++;
			success_3 = false;
			if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos))) {
				__WS_2 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos));
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
			if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos))) {
				__WS_6 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos));
				success_7 = true;
				pos++;
			}
			success_9 = false;
			if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::expr::AUTO_1>>((*pos)))) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  expr::AUTO_1");
				return {};
			}
			expr_AUTO_1_8 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::expr::AUTO_1>>((*pos));
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
		template<typename IT>
		auto template_params(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::template_params, IT>{
			::ISPA_STD::Node<::Parser::Tokens, Types::template_params::AUTO_0> template_params_AUTO_0_0;
			bool success_1;
			::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
			bool success_3;
			::ISPA_STD::MatchResult<Rules, Types::param, IT> param_4;
			bool success_5;
			::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_6;
			bool success_7;
			::ISPA_STD::Node<::Parser::Tokens, Types::template_params::AUTO_1> template_params_AUTO_1_8;
			bool success_9;
			success_1 = false;
			if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::template_params::AUTO_0>>((*pos)))) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  template_params::AUTO_0");
				return {};
			}
			template_params_AUTO_0_0 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::template_params::AUTO_0>>((*pos));
			success_1 = true;
			pos++;
			success_3 = false;
			if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos))) {
				__WS_2 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos));
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
			if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos))) {
				__WS_6 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos));
				success_7 = true;
				pos++;
			}
			success_9 = false;
			if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::template_params::AUTO_1>>((*pos)))) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  template_params::AUTO_1");
				return {};
			}
			template_params_AUTO_1_8 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::template_params::AUTO_1>>((*pos));
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
		template<typename IT>
		auto advanced_rule_match_unpack(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::advanced_rule::match::unpack, IT>{
			::ISPA_STD::Node<::Parser::Tokens, Types::forward_declaration::AUTO_0> forward_declaration_AUTO_0_0;
			bool success_1;
			::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
			bool success_3;
			::ISPA_STD::Node<::Parser::Tokens, Types::ID> ID_5;
			bool success_6;
			std::vector<::ISPA_STD::Node<::Parser::Tokens, Types::ID>> uvar_4;
			std::vector<::ISPA_STD::Node<::Parser::Tokens, Types::ID>> shadow_7;
			bool success_8;
			success_1 = false;
			if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::forward_declaration::AUTO_0>>((*pos)))) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  forward_declaration::AUTO_0");
				return {};
			}
			forward_declaration_AUTO_0_0 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::forward_declaration::AUTO_0>>((*pos));
			success_1 = true;
			pos++;
			success_3 = false;
			if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos))) {
				__WS_2 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos));
				success_3 = true;
				pos++;
			}
			success_6 = false;
			success_8 = false;
			while (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::ID>>((*pos))) {
				ID_5 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::ID>>((*pos));
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
			Types::advanced_rule::match::unpack result;
			::ISPA_STD::assign_compatible(result.value, uvar_4);
			::ISPA_STD::MatchResult<Rules, Types::advanced_rule::match::unpack, IT> match_result;
			match_result.status = true;
			match_result.node.set_data(result);
			match_result.it = pos;
			return match_result;
		}
		template<typename IT>
		auto param(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::param, IT>{
			::ISPA_STD::Node<::Parser::Tokens, Types::ID> ID_0;
			bool success_1;
			bool success_17;
			bool success_9;
			std::vector<::ISPA_STD::Node<::Parser::Tokens, Types::param::AUTO_0>> shadow_19;
			std::vector<::ISPA_STD::Node<::Parser::Tokens, Types::ID>> shadow_20;
			::ISPA_STD::Node<::Parser::Tokens, Types::param::AUTO_0> group_4;
			bool success_6;
			std::vector<::ISPA_STD::Node<::Parser::Tokens, Types::param::AUTO_0>> shadow_21;
			std::vector<::ISPA_STD::Node<::Parser::Tokens, Types::param::AUTO_0>> uvar_5;
			::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
			bool success_3;
			::ISPA_STD::Node<::Parser::Tokens, Types::param::AUTO_0> param_AUTO_0_8;
			::ISPA_STD::Node<::Parser::Tokens, Types::param::AUTO_0> uvar_7;
			std::vector<::ISPA_STD::Node<::Parser::Tokens, Types::param::AUTO_0>> shadow_10;
			::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_12;
			bool success_13;
			::ISPA_STD::Node<::Parser::Tokens, Types::__WS> uvar_11;
			std::vector<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>> shadow_14;
			::ISPA_STD::Node<::Parser::Tokens, Types::ID> ID_16;
			::ISPA_STD::Node<::Parser::Tokens, Types::ID> uvar_15;
			std::vector<::ISPA_STD::Node<::Parser::Tokens, Types::ID>> shadow_18;
			success_1 = false;
			if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::ID>>((*pos)))) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar: @  ID");
				return {};
			}
			ID_0 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::ID>>((*pos));
			success_1 = true;
			pos++;
			success_6 = false;
			auto begin_22 = pos;
			while (true) {
				auto repeat_ws_23 = begin_22;
				success_3 = false;
				if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*repeat_ws_23))) {
					__WS_2 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*repeat_ws_23));
					success_3 = true;
					repeat_ws_23++;
				}
				if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::param::AUTO_0>>((*repeat_ws_23)))) {
					// speculative match failed (diagnostic suppressed):  param::AUTO_0
					break;
				}
				param_AUTO_0_8 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::param::AUTO_0>>((*repeat_ws_23));
				success_9 = true;
				repeat_ws_23++;
				shadow_10.push_back(param_AUTO_0_8);
				uvar_7 = param_AUTO_0_8;
				success_13 = false;
				if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*repeat_ws_23))) {
					__WS_12 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*repeat_ws_23));
					success_13 = true;
					repeat_ws_23++;
					shadow_14.push_back(__WS_12);
					uvar_11 = __WS_12;
				}
				if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::ID>>((*repeat_ws_23)))) {
					// speculative match failed (diagnostic suppressed): @  ID
					break;
				}
				ID_16 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::ID>>((*repeat_ws_23));
				success_17 = true;
				repeat_ws_23++;
				shadow_18.push_back(ID_16);
				uvar_15 = ID_16;
				if (success_9 && success_17) {
					group_4 = param_AUTO_0_8;
					shadow_21.push_back(group_4);
					shadow_19.push_back(param_AUTO_0_8);
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
		template<typename IT>
		auto name(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::name, IT>{
			::ISPA_STD::Node<::Parser::Tokens, Types::ID> ID_0;
			bool success_1;
			bool success_17;
			bool success_9;
			std::vector<::ISPA_STD::Node<::Parser::Tokens, Types::name::AUTO_0>> shadow_19;
			std::vector<::ISPA_STD::Node<::Parser::Tokens, Types::ID>> shadow_20;
			::ISPA_STD::Node<::Parser::Tokens, Types::name::AUTO_0> group_4;
			bool success_6;
			std::vector<::ISPA_STD::Node<::Parser::Tokens, Types::name::AUTO_0>> shadow_21;
			std::vector<::ISPA_STD::Node<::Parser::Tokens, Types::name::AUTO_0>> uvar_5;
			::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
			bool success_3;
			::ISPA_STD::Node<::Parser::Tokens, Types::name::AUTO_0> name_AUTO_0_8;
			::ISPA_STD::Node<::Parser::Tokens, Types::name::AUTO_0> uvar_7;
			std::vector<::ISPA_STD::Node<::Parser::Tokens, Types::name::AUTO_0>> shadow_10;
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
			if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::ID>>((*pos)))) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar: @  ID");
				return {};
			}
			ID_0 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::ID>>((*pos));
			success_1 = true;
			pos++;
			success_6 = false;
			auto begin_22 = pos;
			while (true) {
				auto repeat_ws_23 = begin_22;
				success_3 = false;
				if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*repeat_ws_23))) {
					__WS_2 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*repeat_ws_23));
					success_3 = true;
					repeat_ws_23++;
				}
				if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::name::AUTO_0>>((*repeat_ws_23)))) {
					// speculative match failed (diagnostic suppressed):  name::AUTO_0
					break;
				}
				name_AUTO_0_8 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::name::AUTO_0>>((*repeat_ws_23));
				success_9 = true;
				repeat_ws_23++;
				shadow_10.push_back(name_AUTO_0_8);
				uvar_7 = name_AUTO_0_8;
				success_13 = false;
				if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*repeat_ws_23))) {
					__WS_12 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*repeat_ws_23));
					success_13 = true;
					repeat_ws_23++;
					shadow_14.push_back(__WS_12);
					uvar_11 = __WS_12;
				}
				if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::ID>>((*repeat_ws_23)))) {
					// speculative match failed (diagnostic suppressed): @  ID
					break;
				}
				ID_16 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::ID>>((*repeat_ws_23));
				success_17 = true;
				repeat_ws_23++;
				shadow_18.push_back(ID_16);
				uvar_15 = ID_16;
				if (success_9 && success_17) {
					group_4 = name_AUTO_0_8;
					shadow_21.push_back(group_4);
					shadow_19.push_back(name_AUTO_0_8);
					shadow_20.push_back(ID_16);
				}
				begin_22 = repeat_ws_23;
			}
			success_6 = true;
			::ISPA_STD::assign_compatible(uvar_5, shadow_21);
			pos = begin_22;
			success_25 = false;
			if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos))) {
				__WS_24 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos));
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
			if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos))) {
				__WS_28 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos));
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
		template<typename IT>
		auto stmt(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::stmt, IT>{
			::ISPA_STD::Node<::Parser::Tokens, Types::advanced_rule::AUTO_0> advanced_rule_AUTO_0_0;
			bool success_1;
			::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
			bool success_3;
			::ISPA_STD::Node<::Parser::Tokens, Types::ID> ID_4;
			bool success_5;
			::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_6;
			bool success_7;
			::ISPA_STD::Node<::Parser::Tokens, Types::advanced_rule::AUTO_1> advanced_rule_AUTO_1_8;
			bool success_9;
			success_1 = false;
			if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::advanced_rule::AUTO_0>>((*pos)))) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  advanced_rule::AUTO_0");
				return {};
			}
			advanced_rule_AUTO_0_0 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::advanced_rule::AUTO_0>>((*pos));
			success_1 = true;
			pos++;
			success_3 = false;
			if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos))) {
				__WS_2 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos));
				success_3 = true;
				pos++;
			}
			success_5 = false;
			if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::ID>>((*pos)))) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar: @  ID");
				return {};
			}
			ID_4 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::ID>>((*pos));
			success_5 = true;
			pos++;
			success_7 = false;
			if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos))) {
				__WS_6 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos));
				success_7 = true;
				pos++;
			}
			success_9 = false;
			if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::advanced_rule::AUTO_1>>((*pos)))) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  advanced_rule::AUTO_1");
				return {};
			}
			advanced_rule_AUTO_1_8 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::advanced_rule::AUTO_1>>((*pos));
			success_9 = true;
			pos++;
			Types::stmt result;
			::ISPA_STD::assign_compatible(result.value, ID_4);
			::ISPA_STD::MatchResult<Rules, Types::stmt, IT> match_result;
			match_result.status = true;
			match_result.node.set_data(result);
			match_result.it = pos;
			return match_result;
		}
		template<typename IT>
		auto advanced_rule_fail_call(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::advanced_rule::fail_call, IT>{
			::ISPA_STD::Node<::Parser::Tokens, Types::fail_block::AUTO_0> fail_block_AUTO_0_0;
			bool success_1;
			::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
			bool success_3;
			::ISPA_STD::MatchResult<Rules, Types::name, IT> name_4;
			bool success_5;
			success_1 = false;
			if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::fail_block::AUTO_0>>((*pos)))) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  fail_block::AUTO_0");
				return {};
			}
			fail_block_AUTO_0_0 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::fail_block::AUTO_0>>((*pos));
			success_1 = true;
			pos++;
			success_3 = false;
			if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos))) {
				__WS_2 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos));
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
		template<typename IT>
		auto explicit_expr(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::explicit_expr, IT>{
			::ISPA_STD::Node<::Parser::Tokens, Types::rule::value::group::AUTO_0> rule_value_group_AUTO_0_0;
			bool success_1;
			::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
			bool success_3;
			::ISPA_STD::MatchResult<Rules, Types::expr, IT> expr_4;
			bool success_5;
			::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_6;
			bool success_7;
			::ISPA_STD::Node<::Parser::Tokens, Types::expr::AUTO_1> expr_AUTO_1_8;
			bool success_9;
			success_1 = false;
			if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::rule::value::group::AUTO_0>>((*pos)))) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  rule::value::group::AUTO_0");
				return {};
			}
			rule_value_group_AUTO_0_0 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::rule::value::group::AUTO_0>>((*pos));
			success_1 = true;
			pos++;
			success_3 = false;
			if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos))) {
				__WS_2 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos));
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
			if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos))) {
				__WS_6 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos));
				success_7 = true;
				pos++;
			}
			success_9 = false;
			if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::expr::AUTO_1>>((*pos)))) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  expr::AUTO_1");
				return {};
			}
			expr_AUTO_1_8 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::expr::AUTO_1>>((*pos));
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
		template<typename IT>
		auto rule_value_shared_counter_registration(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::rule::value::shared_counter_registration, IT>{
			::ISPA_STD::Node<::Parser::Tokens, Types::rule::value::shared_counter_registration::AUTO_0> rule_value_shared_counter_registration_AUTO_0_0;
			bool success_1;
			::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
			bool success_3;
			::ISPA_STD::Node<::Parser::Tokens, Types::ID> ID_4;
			bool success_5;
			success_1 = false;
			if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::rule::value::shared_counter_registration::AUTO_0>>((*pos)))) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  rule::value::shared_counter_registration::AUTO_0");
				return {};
			}
			rule_value_shared_counter_registration_AUTO_0_0 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::rule::value::shared_counter_registration::AUTO_0>>((*pos));
			success_1 = true;
			pos++;
			success_3 = false;
			if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos))) {
				__WS_2 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos));
				success_3 = true;
				pos++;
			}
			success_5 = false;
			if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::ID>>((*pos)))) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar: @  ID");
				return {};
			}
			ID_4 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::ID>>((*pos));
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
		template<typename IT>
		auto compound_statement(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::compound_statement, IT>{
			::ISPA_STD::Node<::Parser::Tokens, Types::compound_statement::AUTO_0> compound_statement_AUTO_0_0;
			bool success_1;
			success_1 = false;
			if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::compound_statement::AUTO_0>>((*pos)))) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar: @  compound_statement::AUTO_0");
				return {};
			}
			compound_statement_AUTO_0_0 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::compound_statement::AUTO_0>>((*pos));
			success_1 = true;
			pos++;
			Types::compound_statement result;
			::ISPA_STD::assign_compatible(result.value, compound_statement_AUTO_0_0);
			::ISPA_STD::MatchResult<Rules, Types::compound_statement, IT> match_result;
			match_result.status = true;
			match_result.node.set_data(result);
			match_result.it = pos;
			return match_result;
		}
	public: 
		auto parseFromTokens() -> void override;
		auto lazyParse() -> void override;
	};
}
#endif // PARSER_H
