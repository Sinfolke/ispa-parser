#pragma once

#include <ispastdlib.hpp>

namespace Parser {
	enum class Tokens {
		NONE,
		__WS,
		AUTO,
		AMPERSAND,
		FAIL,
		advanced_rule_dep_decl_DEPENDS,
		
		rule_value_counter_bounded_EQUALS_SIGN,
		SEMICOLON,
		COLON,
		rule_nested_rule_NUMBER_SIGN,
		LEFT_CURLY_BRACKET,
		rule_value_shared_counter_registration_AUTO,
		
		COMMERCIAL_AT,
		rule_value_QUANTIFIER,
		rule_value_NOSPACE,
		template_params_LESS_THAN_SIGN,
		rule_value_STRING,
		grammar_modifier_AUTO,
		
		grammar_modifier_MOD,
		rule_value_SPACE,
		template_params_GREATER_THAN_SIGN,
		rule_value_alternative_VERTICAL_LINE,
		grammar_modifier_RIGHT_SQUARE_BRACKET,
		rule_value_dyn_DOLLAR_SIGN,
		
		advanced_rule_regular_match_MATCH,
		COMMA,
		RIGHT_PARENTHESIS,
		LEFT_PARENTHESIS,
		RIGHT_CURLY_BRACKET,
		NUMBER,
		
		rule_value_ANY,
		PY_RAW,
		ID,
		rule_value_CGROUP,
	};
} // namespace Parser
namespace Parser {
	enum class Rules {
		NONE,
		advanced_rule,
		advanced_rule_dep_decl,
		advanced_rule_fail_call,
		advanced_rule_regular_match,
		advanced_rule_regular_match_unpack,
		
		explicit_expr,
		expr,
		fail_block,
		forward_declaration,
		grammar,
		grammar_modifier,
		
		main,
		name,
		param,
		params,
		rule,
		rule_ast,
		
		rule_ast_abbr,
		rule_ast_full,
		rule_ast_full_part,
		rule_ast_single_value,
		rule_nested_rule,
		rule_value,
		
		rule_value_alternative,
		rule_value_ast_capture,
		rule_value_counter,
		rule_value_counter_bounded,
		rule_value_dyn,
		rule_value_dyn_dyn_expr,
		
		rule_value_group,
		rule_value_pattern,
		rule_value_shared_counter_registration,
		rule_value_var_capture,
		stmt,
		template_params,
	};
} // namespace Parser
namespace Parser::FlatTypes { struct __WS; }
namespace Parser::FlatTypes { struct AUTO; }
namespace Parser::FlatTypes { struct AMPERSAND; }
namespace Parser::FlatTypes { struct FAIL; }
namespace Parser::FlatTypes { struct advanced_rule_dep_decl_DEPENDS; }
namespace Parser::FlatTypes { struct advanced_rule; }
namespace Parser::FlatTypes { struct advanced_rule_dep_decl; }
namespace Parser::FlatTypes { struct rule_value_counter_bounded_EQUALS_SIGN; }
namespace Parser::FlatTypes { struct rule; }
namespace Parser::FlatTypes { struct rule_value; }
namespace Parser::FlatTypes { struct rule_value_counter; }
namespace Parser::FlatTypes { struct rule_value_counter_bounded; }
namespace Parser::FlatTypes { struct SEMICOLON; }
namespace Parser::FlatTypes { struct COLON; }
namespace Parser::FlatTypes { struct rule_nested_rule_NUMBER_SIGN; }
namespace Parser::FlatTypes { struct rule_nested_rule; }
namespace Parser::FlatTypes { struct LEFT_CURLY_BRACKET; }
namespace Parser::FlatTypes { struct rule_value_shared_counter_registration_AUTO; }
namespace Parser::FlatTypes { struct rule_value_shared_counter_registration; }
namespace Parser::FlatTypes { struct COMMERCIAL_AT; }
namespace Parser::FlatTypes { struct rule_value_QUANTIFIER; }
namespace Parser::FlatTypes { struct rule_value_NOSPACE; }
namespace Parser::FlatTypes { struct template_params_LESS_THAN_SIGN; }
namespace Parser::FlatTypes { struct template_params; }
namespace Parser::FlatTypes { struct rule_value_STRING; }
namespace Parser::FlatTypes { struct grammar_modifier_AUTO; }
namespace Parser::FlatTypes { struct grammar; }
namespace Parser::FlatTypes { struct grammar_modifier; }
namespace Parser::FlatTypes { struct grammar_modifier_MOD; }
namespace Parser::FlatTypes { struct rule_value_SPACE; }
namespace Parser::FlatTypes { struct template_params_GREATER_THAN_SIGN; }
namespace Parser::FlatTypes { struct rule_value_alternative_VERTICAL_LINE; }
namespace Parser::FlatTypes { struct rule_value_alternative; }
namespace Parser::FlatTypes { struct grammar_modifier_RIGHT_SQUARE_BRACKET; }
namespace Parser::FlatTypes { struct rule_value_dyn_DOLLAR_SIGN; }
namespace Parser::FlatTypes { struct rule_value_dyn; }
namespace Parser::FlatTypes { struct advanced_rule_regular_match_MATCH; }
namespace Parser::FlatTypes { struct advanced_rule_regular_match; }
namespace Parser::FlatTypes { struct COMMA; }
namespace Parser::FlatTypes { struct RIGHT_PARENTHESIS; }
namespace Parser::FlatTypes { struct LEFT_PARENTHESIS; }
namespace Parser::FlatTypes { struct RIGHT_CURLY_BRACKET; }
namespace Parser::FlatTypes { struct NUMBER; }
namespace Parser::FlatTypes { struct rule_value_ANY; }
namespace Parser::FlatTypes { struct PY_RAW; }
namespace Parser::FlatTypes { struct ID; }
namespace Parser::FlatTypes { struct rule_value_CGROUP; }
namespace Parser::FlatTypes { struct advanced_rule_fail_call; }
namespace Parser::FlatTypes { struct advanced_rule_regular_match_unpack; }
namespace Parser::FlatTypes { struct explicit_expr; }
namespace Parser::FlatTypes { struct expr; }
namespace Parser::FlatTypes { struct fail_block; }
namespace Parser::FlatTypes { struct forward_declaration; }
namespace Parser::FlatTypes { struct main; }
namespace Parser::FlatTypes { struct name; }
namespace Parser::FlatTypes { struct param; }
namespace Parser::FlatTypes { struct params; }
namespace Parser::FlatTypes { struct rule_ast; }
namespace Parser::FlatTypes { struct rule_ast_abbr; }
namespace Parser::FlatTypes { struct rule_ast_full; }
namespace Parser::FlatTypes { struct rule_ast_full_part; }
namespace Parser::FlatTypes { struct rule_ast_single_value; }
namespace Parser::FlatTypes { struct rule_value_ast_capture; }
namespace Parser::FlatTypes { struct rule_value_dyn_dyn_expr; }
namespace Parser::FlatTypes { struct rule_value_group; }
namespace Parser::FlatTypes { struct rule_value_pattern; }
namespace Parser::FlatTypes { struct rule_value_var_capture; }
namespace Parser::FlatTypes { struct stmt; }
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, __WS value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct __WS {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, AUTO value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct AUTO {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, AMPERSAND value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct AMPERSAND {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, FAIL value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct FAIL {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, advanced_rule_dep_decl_DEPENDS value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct advanced_rule_dep_decl_DEPENDS {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, rule_value_counter_bounded_EQUALS_SIGN value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct rule_value_counter_bounded_EQUALS_SIGN {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, SEMICOLON value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct SEMICOLON {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, COLON value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct COLON {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, rule_nested_rule_NUMBER_SIGN value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct rule_nested_rule_NUMBER_SIGN {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, rule_nested_rule value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct rule_nested_rule {
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::grammar>> value;
			using NUMBER_SIGN = ::Parser::FlatTypes::rule_nested_rule_NUMBER_SIGN;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, LEFT_CURLY_BRACKET value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct LEFT_CURLY_BRACKET {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, rule_value_shared_counter_registration_AUTO value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct rule_value_shared_counter_registration_AUTO {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, COMMERCIAL_AT value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct COMMERCIAL_AT {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, rule_value_QUANTIFIER value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct rule_value_QUANTIFIER {
			char value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, rule_value_NOSPACE value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct rule_value_NOSPACE {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, template_params_LESS_THAN_SIGN value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct template_params_LESS_THAN_SIGN {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, rule_value_STRING value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct rule_value_STRING {
			std::string value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, grammar_modifier_AUTO value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct grammar_modifier_AUTO {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, grammar_modifier_MOD value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct grammar_modifier_MOD {
			std::string value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, rule_value_SPACE value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct rule_value_SPACE {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, template_params_GREATER_THAN_SIGN value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct template_params_GREATER_THAN_SIGN {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, rule_value_alternative_VERTICAL_LINE value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct rule_value_alternative_VERTICAL_LINE {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, rule_value_alternative value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct rule_value_alternative {
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::rule_value_pattern>> value;
			using VERTICAL_LINE = ::Parser::FlatTypes::rule_value_alternative_VERTICAL_LINE;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, grammar_modifier_RIGHT_SQUARE_BRACKET value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct grammar_modifier_RIGHT_SQUARE_BRACKET {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, rule_value_dyn_DOLLAR_SIGN value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct rule_value_dyn_DOLLAR_SIGN {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, advanced_rule_regular_match_MATCH value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct advanced_rule_regular_match_MATCH {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, COMMA value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct COMMA {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, RIGHT_PARENTHESIS value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct RIGHT_PARENTHESIS {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, LEFT_PARENTHESIS value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct LEFT_PARENTHESIS {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, RIGHT_CURLY_BRACKET value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct RIGHT_CURLY_BRACKET {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, NUMBER value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct NUMBER {
			std::string full;
			std::string floating;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, rule_value_ANY value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct rule_value_ANY {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, PY_RAW value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct PY_RAW {
			std::string value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, ID value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct ID {
			std::string value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, rule_value_CGROUP value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct rule_value_CGROUP {
			char negative;
			std::string v;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, rule_value_group value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct rule_value_group {
			std::vector<::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::rule_value>>> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, grammar_modifier value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct grammar_modifier {
			::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::grammar_modifier_MOD> value;
			using AUTO = ::Parser::FlatTypes::grammar_modifier_AUTO;
			using MOD = ::Parser::FlatTypes::grammar_modifier_MOD;
			using RIGHT_SQUARE_BRACKET = ::Parser::FlatTypes::grammar_modifier_RIGHT_SQUARE_BRACKET;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, expr value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct expr {
			::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::PY_RAW> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, stmt value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct stmt {
			::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::PY_RAW> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, rule_value_shared_counter_registration value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct rule_value_shared_counter_registration {
			::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::ID> value;
			using AUTO = ::Parser::FlatTypes::rule_value_shared_counter_registration_AUTO;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, advanced_rule_regular_match_unpack value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct advanced_rule_regular_match_unpack {
			std::vector<::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::ID>> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, forward_declaration value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct forward_declaration {
			::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::ID> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, param value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct param {
			::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::ID> first_p;
			std::vector<::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::ID>> following_p;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, rule_ast_abbr value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct rule_ast_abbr {
			std::vector<::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::ID>> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, rule_value_ast_capture value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct rule_value_ast_capture {
			::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::ID> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, rule_value_var_capture value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct rule_value_var_capture {
			::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::ID> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, rule_value_counter_bounded value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct rule_value_counter_bounded {
			std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::expr>, ::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::ID>, ::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::NUMBER>> value;
			using EQUALS_SIGN = ::Parser::FlatTypes::rule_value_counter_bounded_EQUALS_SIGN;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, explicit_expr value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct explicit_expr {
			::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::expr> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, rule_ast_full_part value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct rule_ast_full_part {
			::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::ID> key;
			::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::expr> e;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, rule_ast_single_value value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct rule_ast_single_value {
			std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::COMMERCIAL_AT>, ::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::expr>> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, rule_value_dyn_dyn_expr value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct rule_value_dyn_dyn_expr {
			::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::expr> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, advanced_rule_dep_decl value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct advanced_rule_dep_decl {
			::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::forward_declaration> value;
			using DEPENDS = ::Parser::FlatTypes::advanced_rule_dep_decl_DEPENDS;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, template_params value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct template_params {
			::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::param> value;
			using LESS_THAN_SIGN = ::Parser::FlatTypes::template_params_LESS_THAN_SIGN;
			using GREATER_THAN_SIGN = ::Parser::FlatTypes::template_params_GREATER_THAN_SIGN;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, params value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct params {
			::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::param> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, rule_value_counter value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct rule_value_counter {
			::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::rule_value_QUANTIFIER> quantifier;
			::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::rule_value_counter_bounded> repetitions;
			using bounded = ::Parser::FlatTypes::rule_value_counter_bounded;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, rule_ast_full value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct rule_ast_full {
			std::vector<::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::rule_ast_full_part>> value;
			using part = ::Parser::FlatTypes::rule_ast_full_part;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, rule_value_dyn value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct rule_value_dyn {
			std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::ID>, ::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::rule_value_dyn_dyn_expr>> value;
			using DOLLAR_SIGN = ::Parser::FlatTypes::rule_value_dyn_DOLLAR_SIGN;
			using dyn_expr = ::Parser::FlatTypes::rule_value_dyn_dyn_expr;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, name value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct name {
			::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::ID> primary;
			std::vector<::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::ID>> nested;
			::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::template_params> temp_params;
			::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::params> param;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, rule_value value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct rule_value {
			::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::rule_value_var_capture> v_cap;
			::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::rule_value_ast_capture> ast_cap;
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::rule_value_pattern>> val;
			std::vector<::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::rule_value_alternative>>> alts;
			::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::rule_value_counter> quantifier;
			::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::rule_value_shared_counter_registration> registration;
			using counter = ::Parser::FlatTypes::rule_value_counter;
			using shared_counter_registration = ::Parser::FlatTypes::rule_value_shared_counter_registration;
			using QUANTIFIER = ::Parser::FlatTypes::rule_value_QUANTIFIER;
			using NOSPACE = ::Parser::FlatTypes::rule_value_NOSPACE;
			using STRING = ::Parser::FlatTypes::rule_value_STRING;
			using SPACE = ::Parser::FlatTypes::rule_value_SPACE;
			using alternative = ::Parser::FlatTypes::rule_value_alternative;
			using dyn = ::Parser::FlatTypes::rule_value_dyn;
			using ANY = ::Parser::FlatTypes::rule_value_ANY;
			using CGROUP = ::Parser::FlatTypes::rule_value_CGROUP;
			using ast_capture = ::Parser::FlatTypes::rule_value_ast_capture;
			using group = ::Parser::FlatTypes::rule_value_group;
			using pattern = ::Parser::FlatTypes::rule_value_pattern;
			using var_capture = ::Parser::FlatTypes::rule_value_var_capture;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, rule_ast value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct rule_ast {
			std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::rule_ast_single_value>, ::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::rule_ast_full>, ::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::rule_ast_abbr>> value;
			using abbr = ::Parser::FlatTypes::rule_ast_abbr;
			using full = ::Parser::FlatTypes::rule_ast_full;
			using single_value = ::Parser::FlatTypes::rule_ast_single_value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, advanced_rule_fail_call value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct advanced_rule_fail_call {
			::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::name> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, fail_block value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct fail_block {
			::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::name> name;
			::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::stmt> val;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, rule_value_pattern value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct rule_value_pattern {
			std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::rule_value_SPACE>, ::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::rule_value_CGROUP>, ::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::rule_value_STRING>, ::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::rule_value_dyn>, ::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::rule_value_NOSPACE>, ::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::rule_value_group>>, ::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::rule_value_ANY>, ::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::name>> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, advanced_rule_regular_match value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct advanced_rule_regular_match {
			std::vector<::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::rule_value>> patterns;
			std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::SEMICOLON>, ::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::advanced_rule_regular_match_unpack>> assign_names;
			using MATCH = ::Parser::FlatTypes::advanced_rule_regular_match_MATCH;
			using unpack = ::Parser::FlatTypes::advanced_rule_regular_match_unpack;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, rule value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct rule {
			std::vector<::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::rule_value>> v;
			::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::rule_ast> data;
			std::vector<::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::rule_nested_rule>>> nested;
			using value = ::Parser::FlatTypes::rule_value;
			using nested_rule = ::Parser::FlatTypes::rule_nested_rule;
			using ast = ::Parser::FlatTypes::rule_ast;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, advanced_rule value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct advanced_rule {
			std::vector<::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::advanced_rule_dep_decl>> dep;
			std::vector<std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::stmt>, ::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::advanced_rule_regular_match>>> body;
			using dep_decl = ::Parser::FlatTypes::advanced_rule_dep_decl;
			using regular_match = ::Parser::FlatTypes::advanced_rule_regular_match;
			using fail_call = ::Parser::FlatTypes::advanced_rule_fail_call;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, grammar value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct grammar {
			std::vector<::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::grammar_modifier>> mod;
			::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::name> name;
			std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::advanced_rule>, ::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::rule>>> entry;
			using modifier = ::Parser::FlatTypes::grammar_modifier;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, main value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct main {
			std::vector<std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::fail_block>, ::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::grammar>>> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace Types {
		using __WS = ::Parser::FlatTypes::__WS;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using AUTO = ::Parser::FlatTypes::AUTO;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using AMPERSAND = ::Parser::FlatTypes::AMPERSAND;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using FAIL = ::Parser::FlatTypes::FAIL;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using advanced_rule = ::Parser::FlatTypes::advanced_rule;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using rule = ::Parser::FlatTypes::rule;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using SEMICOLON = ::Parser::FlatTypes::SEMICOLON;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using COLON = ::Parser::FlatTypes::COLON;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using LEFT_CURLY_BRACKET = ::Parser::FlatTypes::LEFT_CURLY_BRACKET;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using COMMERCIAL_AT = ::Parser::FlatTypes::COMMERCIAL_AT;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using template_params = ::Parser::FlatTypes::template_params;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using grammar = ::Parser::FlatTypes::grammar;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using COMMA = ::Parser::FlatTypes::COMMA;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using RIGHT_PARENTHESIS = ::Parser::FlatTypes::RIGHT_PARENTHESIS;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using LEFT_PARENTHESIS = ::Parser::FlatTypes::LEFT_PARENTHESIS;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using RIGHT_CURLY_BRACKET = ::Parser::FlatTypes::RIGHT_CURLY_BRACKET;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using NUMBER = ::Parser::FlatTypes::NUMBER;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using PY_RAW = ::Parser::FlatTypes::PY_RAW;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using ID = ::Parser::FlatTypes::ID;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using explicit_expr = ::Parser::FlatTypes::explicit_expr;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using expr = ::Parser::FlatTypes::expr;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using fail_block = ::Parser::FlatTypes::fail_block;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using forward_declaration = ::Parser::FlatTypes::forward_declaration;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using main = ::Parser::FlatTypes::main;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using name = ::Parser::FlatTypes::name;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using param = ::Parser::FlatTypes::param;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using params = ::Parser::FlatTypes::params;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using stmt = ::Parser::FlatTypes::stmt;
	} // namespace Types
} // namespace Parser
namespace Parser {
	using Token = ::ISPA_STD::RawToken<::Parser::Tokens, Types::__WS, Types::AUTO, Types::AMPERSAND, Types::FAIL, Types::advanced_rule::dep_decl::DEPENDS, Types::rule::value::counter::bounded::EQUALS_SIGN, Types::SEMICOLON, Types::COLON, Types::rule::nested_rule::NUMBER_SIGN, Types::LEFT_CURLY_BRACKET, Types::rule::value::shared_counter_registration::AUTO, Types::COMMERCIAL_AT, Types::rule::value::QUANTIFIER, Types::rule::value::NOSPACE, Types::template_params::LESS_THAN_SIGN, Types::rule::value::STRING, Types::grammar::modifier::AUTO, Types::grammar::modifier::MOD, Types::rule::value::SPACE, Types::template_params::GREATER_THAN_SIGN, Types::rule::value::alternative::VERTICAL_LINE, Types::grammar::modifier::RIGHT_SQUARE_BRACKET, Types::rule::value::dyn::DOLLAR_SIGN, Types::advanced_rule::regular_match::MATCH, Types::COMMA, Types::RIGHT_PARENTHESIS, Types::LEFT_PARENTHESIS, Types::RIGHT_CURLY_BRACKET, Types::NUMBER, Types::rule::value::ANY, Types::PY_RAW, Types::ID, Types::rule::value::CGROUP>;
} // namespace Parser
namespace Parser {
	class Lexer : public ::ISPA_STD::Lexer_base<::Parser::Tokens, Token> {
		static ::ISPA_STD::DFA::API::CharToClass char_class_table;
		static ::ISPA_STD::DFA::API::Table<83, 129> dfa_table;
		static ::ISPA_STD::DFA::API::Table<594, 4> action_table;
		static auto semantic_action_exec(long long state, const ::ISPA_STD::DFA::API::Captures& captures, long long start_pos, const char* start, long long length, long long line) -> std::pair<long long, Token>;
		bool init_done = false;
		auto init() -> void override;
		::ISPA_STD::DFA::API::TdfaLayout<27, 26> tdfa_registers;
		static std::array<::ISPA_STD::DFA::API::DFADebug, 654> debug_array;
		static std::unordered_map<long long, std::unordered_map<long long, long long>> debug_index;
	public:
		auto makeToken(const char*& pos) -> Token override;
	};
} // namespace Parser
namespace Parser {
	class Parser : public ::ISPA_STD::LLParser_base<::Parser::Tokens, ::Parser::Rules, Types::main, Token> {
	protected:
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto advanced_rule(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::advanced_rule, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto advanced_rule_dep_decl(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::advanced_rule::dep_decl, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto advanced_rule_fail_call(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::advanced_rule::fail_call, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto advanced_rule_regular_match(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::advanced_rule::regular_match, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto advanced_rule_regular_match_unpack(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::advanced_rule::regular_match::unpack, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto explicit_expr(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::explicit_expr, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto expr(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::expr, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto fail_block(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::fail_block, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto forward_declaration(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::forward_declaration, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto grammar(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::grammar, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto grammar_modifier(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::grammar::modifier, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto main(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::main, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto name(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::name, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto param(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::param, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto params(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::params, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto rule(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::rule, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto rule_ast(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::rule::ast, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto rule_ast_abbr(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::rule::ast::abbr, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto rule_ast_full(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::rule::ast::full, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto rule_ast_full_part(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::rule::ast::full::part, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto rule_ast_single_value(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::rule::ast::single_value, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto rule_nested_rule(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::rule::nested_rule, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto rule_value(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::rule::value, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto rule_value_alternative(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::rule::value::alternative, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto rule_value_ast_capture(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::rule::value::ast_capture, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto rule_value_counter(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::rule::value::counter, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto rule_value_counter_bounded(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::rule::value::counter::bounded, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto rule_value_dyn(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::rule::value::dyn, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto rule_value_dyn_dyn_expr(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::rule::value::dyn::dyn_expr, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto rule_value_group(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::rule::value::group, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto rule_value_pattern(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::rule::value::pattern, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto rule_value_shared_counter_registration(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::rule::value::shared_counter_registration, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto rule_value_var_capture(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::rule::value::var_capture, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto stmt(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::stmt, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto template_params(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::template_params, IT>;
	public:
		auto parseFromTokens() -> void override;
		auto lazyParse() -> void override;
	};
} // namespace Parser
