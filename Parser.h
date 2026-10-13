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
		__WS,
		SLASH_ASSIGN,
		STAR,
		SLASH,
		RSHIFT_ASSIGN,
		RSHIFT,
		RPAREN,
		RBRACKET,
		RBRACE,
		POWER_ASSIGN,
		POWER,
		PLUS_ASSIGN,
		PLUS,
		PIPE_ASSIGN,
		PIPE,
		NOT,
		NE,
		LT,
		LPAREN,
		LE,
		LBRACKET,
		GT,
		LSHIFT,
		GE,
		FLOOR_DIV_ASSIGN,
		FALSE,
		COMMA,
		NONE_V,
		IS,
		COLON,
		STAR_ASSIGN,
		CARET,
		AND,
		STRING,
		EQ,
		BREAK,
		PASS,
		NUMBER,
		IF,
		MINUS_ASSIGN,
		LSHIFT_ASSIGN,
		ID,
		PERCENT_ASSIGN,
		AMP,
		TILDE,
		ELSE,
		DOT,
		MINUS,
		PERCENT,
		AMP_ASSIGN,
		TRUE,
		FLOOR_DIV,
		OR,
		MATMUL,
		CONTINUE,
		RETURN,
		CARET_ASSIGN,
		IN,
		LBRACE,
		ASSIGN,
	};
	enum class Rules {
		NONE,
		conjunction,
		term_tail,
		parenthesized_expr,
		compare_op,
		expr_list_tail,
		bitwise_xor,
		main,
		assignment_suffix,
		assignment_target,
		dict_item,
		keyword_arg,
		term,
		call_args,
		tuple_elements,
		stmt,
		tuple_suffix,
		call_arg_tail,
		power,
		parenthesized_content,
		primary,
		assignment_tail,
		attribute_suffix,
		bitxor_tail,
		postfix,
		list_expr,
		is_op,
		dict_expr,
		call_suffix,
		shift_expr,
		power_tail,
		inversion,
		sum,
		index_suffix,
		factor,
		return_stmt,
		expr_list,
		bitwise_and,
		compare_tail,
		expr_stmt,
		bitwise_or,
		disjunction,
		sum_tail,
		comparison,
		not_inversion,
		bitor_tail,
		atom,
		not_in,
		shift_tail,
		dict_item_tail,
		unary_expr,
		bitand_tail,
		conditional_tail,
		call_arg,
		or_tail,
		dict_items,
		expr,
	};
	namespace FlatTypes {
		struct __WS;
		struct SLASH_ASSIGN;
		struct STAR;
		struct SLASH;
		struct RSHIFT_ASSIGN;
		struct RSHIFT;
		struct RPAREN;
		struct RBRACKET;
		struct RBRACE;
		struct POWER_ASSIGN;
		struct POWER;
		struct PLUS_ASSIGN;
		struct PLUS;
		struct PIPE_ASSIGN;
		struct PIPE;
		struct NOT;
		struct NE;
		struct LT;
		struct LPAREN;
		struct LE;
		struct LBRACKET;
		struct GT;
		struct LSHIFT;
		struct GE;
		struct FLOOR_DIV_ASSIGN;
		struct FALSE;
		struct COMMA;
		struct NONE_V;
		struct IS;
		struct COLON;
		struct STAR_ASSIGN;
		struct CARET;
		struct AND;
		struct STRING;
		struct EQ;
		struct BREAK;
		struct PASS;
		struct NUMBER;
		struct IF;
		struct MINUS_ASSIGN;
		struct LSHIFT_ASSIGN;
		struct ID;
		struct PERCENT_ASSIGN;
		struct AMP;
		struct TILDE;
		struct ELSE;
		struct DOT;
		struct MINUS;
		struct PERCENT;
		struct AMP_ASSIGN;
		struct TRUE;
		struct FLOOR_DIV;
		struct OR;
		struct MATMUL;
		struct CONTINUE;
		struct RETURN;
		struct CARET_ASSIGN;
		struct IN;
		struct LBRACE;
		struct ASSIGN;
		struct conjunction;
		struct term_tail;
		struct parenthesized_expr;
		struct compare_op;
		struct expr_list_tail;
		struct bitwise_xor;
		struct main;
		struct assignment_suffix;
		struct assignment_target;
		struct dict_item;
		struct keyword_arg;
		struct term;
		struct call_args;
		struct tuple_elements;
		struct stmt;
		struct tuple_suffix;
		struct call_arg_tail;
		struct power;
		struct parenthesized_content;
		struct primary;
		struct assignment_tail;
		struct attribute_suffix;
		struct bitxor_tail;
		struct postfix;
		struct list_expr;
		struct is_op;
		struct dict_expr;
		struct call_suffix;
		struct shift_expr;
		struct power_tail;
		struct inversion;
		struct sum;
		struct index_suffix;
		struct factor;
		struct return_stmt;
		struct expr_list;
		struct bitwise_and;
		struct compare_tail;
		struct expr_stmt;
		struct bitwise_or;
		struct disjunction;
		struct sum_tail;
		struct comparison;
		struct not_inversion;
		struct bitor_tail;
		struct atom;
		struct not_in;
		struct shift_tail;
		struct dict_item_tail;
		struct unary_expr;
		struct bitand_tail;
		struct conditional_tail;
		struct call_arg;
		struct or_tail;
		struct dict_items;
		struct expr;
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
		struct SLASH_ASSIGN {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const SLASH_ASSIGN &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct STAR {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const STAR &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct SLASH {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const SLASH &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct RSHIFT_ASSIGN {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const RSHIFT_ASSIGN &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct RSHIFT {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const RSHIFT &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct RPAREN {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const RPAREN &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct RBRACKET {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const RBRACKET &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct RBRACE {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const RBRACE &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct POWER_ASSIGN {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const POWER_ASSIGN &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct POWER {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const POWER &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct PLUS_ASSIGN {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const PLUS_ASSIGN &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct PLUS {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const PLUS &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct PIPE_ASSIGN {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const PIPE_ASSIGN &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct PIPE {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const PIPE &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct NOT {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const NOT &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct NE {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const NE &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct LT {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const LT &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct LPAREN {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const LPAREN &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct LE {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const LE &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct LBRACKET {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const LBRACKET &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct GT {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const GT &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct LSHIFT {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const LSHIFT &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct GE {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const GE &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct FLOOR_DIV_ASSIGN {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const FLOOR_DIV_ASSIGN &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct FALSE {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const FALSE &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct COMMA {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const COMMA &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct NONE_V {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const NONE_V &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct IS {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const IS &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct COLON {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const COLON &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct STAR_ASSIGN {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const STAR_ASSIGN &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct CARET {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const CARET &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct AND {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const AND &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct STRING {
			std::string value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const STRING &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct EQ {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const EQ &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct BREAK {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const BREAK &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct PASS {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const PASS &value) -> std::ostream&;
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
		struct IF {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const IF &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct MINUS_ASSIGN {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const MINUS_ASSIGN &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct LSHIFT_ASSIGN {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const LSHIFT_ASSIGN &value) -> std::ostream&;
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
		struct PERCENT_ASSIGN {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const PERCENT_ASSIGN &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct AMP {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const AMP &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct TILDE {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const TILDE &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct ELSE {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const ELSE &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct DOT {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const DOT &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct MINUS {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const MINUS &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct PERCENT {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const PERCENT &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct AMP_ASSIGN {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const AMP_ASSIGN &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct TRUE {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const TRUE &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct FLOOR_DIV {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const FLOOR_DIV &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct OR {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const OR &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct MATMUL {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const MATMUL &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct CONTINUE {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const CONTINUE &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct RETURN {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const RETURN &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct CARET_ASSIGN {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const CARET_ASSIGN &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct IN {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const IN &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct LBRACE {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const LBRACE &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct ASSIGN {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const ASSIGN &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct conjunction {
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::inversion>> first;
			std::vector<::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::inversion>>> rest;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const conjunction &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct parenthesized_expr {
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::parenthesized_content>> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const parenthesized_expr &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct expr_list_tail {
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::expr>> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const expr_list_tail &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct bitwise_xor {
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::bitwise_and>> first;
			std::vector<::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::bitxor_tail>>> rest;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const bitwise_xor &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct dict_item {
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::expr>> key;
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::expr>> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const dict_item &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct term {
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::factor>> first;
			std::vector<::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::term_tail>>> rest;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const term &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct call_args {
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::call_arg>> first;
			std::vector<::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::call_arg_tail>>> rest;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const call_args &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct tuple_elements {
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::expr>> first;
			std::vector<::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::expr>>> rest;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const tuple_elements &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct tuple_suffix {
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::tuple_elements>> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const tuple_suffix &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct call_arg_tail {
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::call_arg>> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const call_arg_tail &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct power {
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::primary>> base;
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::power_tail>> exponent;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const power &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct parenthesized_content {
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::expr>> first;
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::tuple_suffix>> rest;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const parenthesized_content &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct primary {
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::atom>> base;
			std::vector<::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::postfix>>> suffixes;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const primary &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct bitxor_tail {
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::bitwise_and>> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const bitxor_tail &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct list_expr {
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::expr_list>> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const list_expr &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct is_op {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const is_op &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct dict_expr {
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::dict_items>> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const dict_expr &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct call_suffix {
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::call_args>> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const call_suffix &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct shift_expr {
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::sum>> first;
			std::vector<::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::shift_tail>>> rest;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const shift_expr &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct power_tail {
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::factor>> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const power_tail &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct inversion {
			std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::comparison>>, ::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::not_inversion>>> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const inversion &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct sum {
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::term>> first;
			std::vector<::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::sum_tail>>> rest;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const sum &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct index_suffix {
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::expr>> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const index_suffix &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct factor {
			std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::power>>, ::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::unary_expr>>> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const factor &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct expr_list {
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::expr>> first;
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::expr_list_tail>> rest;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const expr_list &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct bitwise_and {
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::shift_expr>> first;
			std::vector<::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::bitand_tail>>> rest;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const bitwise_and &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct bitwise_or {
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::bitwise_xor>> first;
			std::vector<::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::bitor_tail>>> rest;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const bitwise_or &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct disjunction {
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::conjunction>> first;
			std::vector<::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::or_tail>>> rest;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const disjunction &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct comparison {
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::bitwise_or>> first;
			std::vector<::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::compare_tail>>> rest;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const comparison &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct not_inversion {
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::inversion>> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const not_inversion &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct bitor_tail {
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::bitwise_xor>> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const bitor_tail &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct not_in {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const not_in &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct dict_item_tail {
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::dict_item>> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const dict_item_tail &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct bitand_tail {
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::shift_expr>> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const bitand_tail &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct conditional_tail {
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::disjunction>> condition;
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::expr>> otherwise;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const conditional_tail &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct call_arg {
			std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::expr>>, ::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::keyword_arg>>> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const call_arg &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct or_tail {
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::conjunction>> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const or_tail &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct dict_items {
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::dict_item>> first;
			std::vector<::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::dict_item_tail>>> rest;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const dict_items &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct expr {
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::disjunction>> value;
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::conditional_tail>> conditional;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const expr &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct shift_tail {
			std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::RSHIFT>, ::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::LSHIFT>> op;
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::sum>> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const shift_tail &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct keyword_arg {
			::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::ID> name;
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::expr>> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const keyword_arg &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct attribute_suffix {
			::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::ID> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const attribute_suffix &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct sum_tail {
			std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::MINUS>, ::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::PLUS>> op;
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::term>> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const sum_tail &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct unary_expr {
			std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::TILDE>, ::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::MINUS>, ::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::PLUS>> op;
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::factor>> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const unary_expr &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct atom {
			std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::parenthesized_expr>>, ::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::NONE_V>, ::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::list_expr>>, ::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::FALSE>, ::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::dict_expr>>, ::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::TRUE>, ::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::NUMBER>, ::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::STRING>, ::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::ID>> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const atom &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct term_tail {
			std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::PERCENT>, ::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::SLASH>, ::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::STAR>, ::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::MATMUL>, ::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::FLOOR_DIV>> op;
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::factor>> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const term_tail &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct compare_op {
			std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::is_op>, ::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::not_in>, ::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::GT>, ::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::IN>, ::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::GE>, ::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::LT>, ::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::LE>, ::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::NE>, ::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::EQ>> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const compare_op &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct assignment_tail {
			std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::RSHIFT_ASSIGN>, ::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::AMP_ASSIGN>, ::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::POWER_ASSIGN>, ::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::FLOOR_DIV_ASSIGN>, ::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::MINUS_ASSIGN>, ::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::CARET_ASSIGN>, ::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::PERCENT_ASSIGN>, ::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::ASSIGN>, ::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::LSHIFT_ASSIGN>, ::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::STAR_ASSIGN>, ::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::PIPE_ASSIGN>, ::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::PLUS_ASSIGN>, ::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::SLASH_ASSIGN>> op;
			::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::expr> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const assignment_tail &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct return_stmt {
			::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::expr> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const return_stmt &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct assignment_suffix {
			std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::index_suffix>, ::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::attribute_suffix>> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const assignment_suffix &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct postfix {
			std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::index_suffix>>, ::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::call_suffix>>, ::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::attribute_suffix>> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const postfix &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct compare_tail {
			::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::compare_op> op;
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::bitwise_or>> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const compare_tail &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct expr_stmt {
			::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::expr> target;
			::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::assignment_tail> assignment;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const expr_stmt &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct assignment_target {
			::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::ID> name;
			std::vector<::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::assignment_suffix>> suffixes;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const assignment_target &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct stmt {
			std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::CONTINUE>, ::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::expr_stmt>, ::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::BREAK>, ::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::PASS>, ::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::return_stmt>> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const stmt &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct main {
			std::vector<::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::stmt>> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const main &value) -> std::ostream&;
	}
	namespace Types {
		using __WS = ::Parser::FlatTypes::__WS;
		using SLASH_ASSIGN = ::Parser::FlatTypes::SLASH_ASSIGN;
		using STAR = ::Parser::FlatTypes::STAR;
		using SLASH = ::Parser::FlatTypes::SLASH;
		using RSHIFT_ASSIGN = ::Parser::FlatTypes::RSHIFT_ASSIGN;
		using RSHIFT = ::Parser::FlatTypes::RSHIFT;
		using RPAREN = ::Parser::FlatTypes::RPAREN;
		using RBRACKET = ::Parser::FlatTypes::RBRACKET;
		using RBRACE = ::Parser::FlatTypes::RBRACE;
		using POWER_ASSIGN = ::Parser::FlatTypes::POWER_ASSIGN;
		using POWER = ::Parser::FlatTypes::POWER;
		using PLUS_ASSIGN = ::Parser::FlatTypes::PLUS_ASSIGN;
		using PLUS = ::Parser::FlatTypes::PLUS;
		using PIPE_ASSIGN = ::Parser::FlatTypes::PIPE_ASSIGN;
		using PIPE = ::Parser::FlatTypes::PIPE;
		using NOT = ::Parser::FlatTypes::NOT;
		using NE = ::Parser::FlatTypes::NE;
		using LT = ::Parser::FlatTypes::LT;
		using LPAREN = ::Parser::FlatTypes::LPAREN;
		using LE = ::Parser::FlatTypes::LE;
		using LBRACKET = ::Parser::FlatTypes::LBRACKET;
		using GT = ::Parser::FlatTypes::GT;
		using LSHIFT = ::Parser::FlatTypes::LSHIFT;
		using GE = ::Parser::FlatTypes::GE;
		using FLOOR_DIV_ASSIGN = ::Parser::FlatTypes::FLOOR_DIV_ASSIGN;
		using FALSE = ::Parser::FlatTypes::FALSE;
		using COMMA = ::Parser::FlatTypes::COMMA;
		using NONE_V = ::Parser::FlatTypes::NONE_V;
		using IS = ::Parser::FlatTypes::IS;
		using COLON = ::Parser::FlatTypes::COLON;
		using STAR_ASSIGN = ::Parser::FlatTypes::STAR_ASSIGN;
		using CARET = ::Parser::FlatTypes::CARET;
		using AND = ::Parser::FlatTypes::AND;
		using STRING = ::Parser::FlatTypes::STRING;
		using EQ = ::Parser::FlatTypes::EQ;
		using BREAK = ::Parser::FlatTypes::BREAK;
		using PASS = ::Parser::FlatTypes::PASS;
		using NUMBER = ::Parser::FlatTypes::NUMBER;
		using IF = ::Parser::FlatTypes::IF;
		using MINUS_ASSIGN = ::Parser::FlatTypes::MINUS_ASSIGN;
		using LSHIFT_ASSIGN = ::Parser::FlatTypes::LSHIFT_ASSIGN;
		using ID = ::Parser::FlatTypes::ID;
		using PERCENT_ASSIGN = ::Parser::FlatTypes::PERCENT_ASSIGN;
		using AMP = ::Parser::FlatTypes::AMP;
		using TILDE = ::Parser::FlatTypes::TILDE;
		using ELSE = ::Parser::FlatTypes::ELSE;
		using DOT = ::Parser::FlatTypes::DOT;
		using MINUS = ::Parser::FlatTypes::MINUS;
		using PERCENT = ::Parser::FlatTypes::PERCENT;
		using AMP_ASSIGN = ::Parser::FlatTypes::AMP_ASSIGN;
		using TRUE = ::Parser::FlatTypes::TRUE;
		using FLOOR_DIV = ::Parser::FlatTypes::FLOOR_DIV;
		using OR = ::Parser::FlatTypes::OR;
		using MATMUL = ::Parser::FlatTypes::MATMUL;
		using CONTINUE = ::Parser::FlatTypes::CONTINUE;
		using RETURN = ::Parser::FlatTypes::RETURN;
		using CARET_ASSIGN = ::Parser::FlatTypes::CARET_ASSIGN;
		using IN = ::Parser::FlatTypes::IN;
		using LBRACE = ::Parser::FlatTypes::LBRACE;
		using ASSIGN = ::Parser::FlatTypes::ASSIGN;
		using conjunction = ::Parser::FlatTypes::conjunction;
		using term_tail = ::Parser::FlatTypes::term_tail;
		using parenthesized_expr = ::Parser::FlatTypes::parenthesized_expr;
		using compare_op = ::Parser::FlatTypes::compare_op;
		using expr_list_tail = ::Parser::FlatTypes::expr_list_tail;
		using bitwise_xor = ::Parser::FlatTypes::bitwise_xor;
		using main = ::Parser::FlatTypes::main;
		using assignment_suffix = ::Parser::FlatTypes::assignment_suffix;
		using assignment_target = ::Parser::FlatTypes::assignment_target;
		using dict_item = ::Parser::FlatTypes::dict_item;
		using keyword_arg = ::Parser::FlatTypes::keyword_arg;
		using term = ::Parser::FlatTypes::term;
		using call_args = ::Parser::FlatTypes::call_args;
		using tuple_elements = ::Parser::FlatTypes::tuple_elements;
		using stmt = ::Parser::FlatTypes::stmt;
		using tuple_suffix = ::Parser::FlatTypes::tuple_suffix;
		using call_arg_tail = ::Parser::FlatTypes::call_arg_tail;
		using power = ::Parser::FlatTypes::power;
		using parenthesized_content = ::Parser::FlatTypes::parenthesized_content;
		using primary = ::Parser::FlatTypes::primary;
		using assignment_tail = ::Parser::FlatTypes::assignment_tail;
		using attribute_suffix = ::Parser::FlatTypes::attribute_suffix;
		using bitxor_tail = ::Parser::FlatTypes::bitxor_tail;
		using postfix = ::Parser::FlatTypes::postfix;
		using list_expr = ::Parser::FlatTypes::list_expr;
		using is_op = ::Parser::FlatTypes::is_op;
		using dict_expr = ::Parser::FlatTypes::dict_expr;
		using call_suffix = ::Parser::FlatTypes::call_suffix;
		using shift_expr = ::Parser::FlatTypes::shift_expr;
		using power_tail = ::Parser::FlatTypes::power_tail;
		using inversion = ::Parser::FlatTypes::inversion;
		using sum = ::Parser::FlatTypes::sum;
		using index_suffix = ::Parser::FlatTypes::index_suffix;
		using factor = ::Parser::FlatTypes::factor;
		using return_stmt = ::Parser::FlatTypes::return_stmt;
		using expr_list = ::Parser::FlatTypes::expr_list;
		using bitwise_and = ::Parser::FlatTypes::bitwise_and;
		using compare_tail = ::Parser::FlatTypes::compare_tail;
		using expr_stmt = ::Parser::FlatTypes::expr_stmt;
		using bitwise_or = ::Parser::FlatTypes::bitwise_or;
		using disjunction = ::Parser::FlatTypes::disjunction;
		using sum_tail = ::Parser::FlatTypes::sum_tail;
		using comparison = ::Parser::FlatTypes::comparison;
		using not_inversion = ::Parser::FlatTypes::not_inversion;
		using bitor_tail = ::Parser::FlatTypes::bitor_tail;
		using atom = ::Parser::FlatTypes::atom;
		using not_in = ::Parser::FlatTypes::not_in;
		using shift_tail = ::Parser::FlatTypes::shift_tail;
		using dict_item_tail = ::Parser::FlatTypes::dict_item_tail;
		using unary_expr = ::Parser::FlatTypes::unary_expr;
		using bitand_tail = ::Parser::FlatTypes::bitand_tail;
		using conditional_tail = ::Parser::FlatTypes::conditional_tail;
		using call_arg = ::Parser::FlatTypes::call_arg;
		using or_tail = ::Parser::FlatTypes::or_tail;
		using dict_items = ::Parser::FlatTypes::dict_items;
		using expr = ::Parser::FlatTypes::expr;
	}
	using Token = std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Tokens, Types::__WS>, ::ISPA_STD::Node<::Parser::Tokens, Types::SLASH_ASSIGN>, ::ISPA_STD::Node<::Parser::Tokens, Types::STAR>, ::ISPA_STD::Node<::Parser::Tokens, Types::SLASH>, ::ISPA_STD::Node<::Parser::Tokens, Types::RSHIFT_ASSIGN>, ::ISPA_STD::Node<::Parser::Tokens, Types::RSHIFT>, ::ISPA_STD::Node<::Parser::Tokens, Types::RPAREN>, ::ISPA_STD::Node<::Parser::Tokens, Types::RBRACKET>, ::ISPA_STD::Node<::Parser::Tokens, Types::RBRACE>, ::ISPA_STD::Node<::Parser::Tokens, Types::POWER_ASSIGN>, ::ISPA_STD::Node<::Parser::Tokens, Types::POWER>, ::ISPA_STD::Node<::Parser::Tokens, Types::PLUS_ASSIGN>, ::ISPA_STD::Node<::Parser::Tokens, Types::PLUS>, ::ISPA_STD::Node<::Parser::Tokens, Types::PIPE_ASSIGN>, ::ISPA_STD::Node<::Parser::Tokens, Types::PIPE>, ::ISPA_STD::Node<::Parser::Tokens, Types::NOT>, ::ISPA_STD::Node<::Parser::Tokens, Types::NE>, ::ISPA_STD::Node<::Parser::Tokens, Types::LT>, ::ISPA_STD::Node<::Parser::Tokens, Types::LPAREN>, ::ISPA_STD::Node<::Parser::Tokens, Types::LE>, ::ISPA_STD::Node<::Parser::Tokens, Types::LBRACKET>, ::ISPA_STD::Node<::Parser::Tokens, Types::GT>, ::ISPA_STD::Node<::Parser::Tokens, Types::LSHIFT>, ::ISPA_STD::Node<::Parser::Tokens, Types::GE>, ::ISPA_STD::Node<::Parser::Tokens, Types::FLOOR_DIV_ASSIGN>, ::ISPA_STD::Node<::Parser::Tokens, Types::FALSE>, ::ISPA_STD::Node<::Parser::Tokens, Types::COMMA>, ::ISPA_STD::Node<::Parser::Tokens, Types::NONE_V>, ::ISPA_STD::Node<::Parser::Tokens, Types::IS>, ::ISPA_STD::Node<::Parser::Tokens, Types::COLON>, ::ISPA_STD::Node<::Parser::Tokens, Types::STAR_ASSIGN>, ::ISPA_STD::Node<::Parser::Tokens, Types::CARET>, ::ISPA_STD::Node<::Parser::Tokens, Types::AND>, ::ISPA_STD::Node<::Parser::Tokens, Types::STRING>, ::ISPA_STD::Node<::Parser::Tokens, Types::EQ>, ::ISPA_STD::Node<::Parser::Tokens, Types::BREAK>, ::ISPA_STD::Node<::Parser::Tokens, Types::PASS>, ::ISPA_STD::Node<::Parser::Tokens, Types::NUMBER>, ::ISPA_STD::Node<::Parser::Tokens, Types::IF>, ::ISPA_STD::Node<::Parser::Tokens, Types::MINUS_ASSIGN>, ::ISPA_STD::Node<::Parser::Tokens, Types::LSHIFT_ASSIGN>, ::ISPA_STD::Node<::Parser::Tokens, Types::ID>, ::ISPA_STD::Node<::Parser::Tokens, Types::PERCENT_ASSIGN>, ::ISPA_STD::Node<::Parser::Tokens, Types::AMP>, ::ISPA_STD::Node<::Parser::Tokens, Types::TILDE>, ::ISPA_STD::Node<::Parser::Tokens, Types::ELSE>, ::ISPA_STD::Node<::Parser::Tokens, Types::DOT>, ::ISPA_STD::Node<::Parser::Tokens, Types::MINUS>, ::ISPA_STD::Node<::Parser::Tokens, Types::PERCENT>, ::ISPA_STD::Node<::Parser::Tokens, Types::AMP_ASSIGN>, ::ISPA_STD::Node<::Parser::Tokens, Types::TRUE>, ::ISPA_STD::Node<::Parser::Tokens, Types::FLOOR_DIV>, ::ISPA_STD::Node<::Parser::Tokens, Types::OR>, ::ISPA_STD::Node<::Parser::Tokens, Types::MATMUL>, ::ISPA_STD::Node<::Parser::Tokens, Types::CONTINUE>, ::ISPA_STD::Node<::Parser::Tokens, Types::RETURN>, ::ISPA_STD::Node<::Parser::Tokens, Types::CARET_ASSIGN>, ::ISPA_STD::Node<::Parser::Tokens, Types::IN>, ::ISPA_STD::Node<::Parser::Tokens, Types::LBRACE>, ::ISPA_STD::Node<::Parser::Tokens, Types::ASSIGN>>;
	class Lexer : public ::ISPA_STD::Lexer_base<::Parser::Tokens, Token> {
		static ::ISPA_STD::DFA::API::CharToClass char_class_table;
		static ::ISPA_STD::DFA::API::Table<105, 49> dfa_table;
		static ::ISPA_STD::DFA::API::Table<99, 4> action_table;
		static auto semantic_action_exec(long long state, const ::ISPA_STD::DFA::API::Captures& captures, long long start_pos, const char* start, long long length, long long line) -> std::pair<long long, Token>;
		bool init_done;
		auto init() -> void override;
		::ISPA_STD::DFA::API::TdfaLayout<9, 8> tdfa_registers;
		static std::array<::ISPA_STD::DFA::API::DFADebug, 1> debug_array;
		static std::unordered_map<long long, std::unordered_map<long long, long long>> debug_index;
	public: 
		auto makeToken(const char*& pos) -> Token override;
	};
	class Parser : public ::ISPA_STD::LLParser_base<::Parser::Tokens, ::Parser::Rules, Types::main, Token> {
		template<typename IT>
		auto conjunction(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::conjunction, IT>{
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
				if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*repeat_ws_26))) {
					__WS_2 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*repeat_ws_26));
					success_3 = true;
					repeat_ws_26++;
				}
				if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::AND>>((*repeat_ws_26)))) {
					// speculative match failed (diagnostic suppressed):  AND
					break;
				}
				AND_8 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::AND>>((*repeat_ws_26));
				success_9 = true;
				repeat_ws_26++;
				shadow_10.push_back(AND_8);
				uvar_7 = AND_8;
				success_13 = false;
				if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*repeat_ws_26))) {
					__WS_12 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*repeat_ws_26));
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
		template<typename IT>
		auto term_tail(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::term_tail, IT>{
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
			switch (static_cast<Tokens>((*lookahead_pos_1).index())) {
				case Tokens::FLOOR_DIV: {
					lookahead_pos_1 = lookahead_pos_1;
					success_3 = false;
					if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::FLOOR_DIV>>((*lookahead_pos_1)))) {
						raise_error(*pos, "ISPA match failure: required token did not match | grammar:  FLOOR_DIV");
						return {};
					}
					FLOOR_DIV_2 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::FLOOR_DIV>>((*lookahead_pos_1));
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
					if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::MATMUL>>((*lookahead_pos_1)))) {
						raise_error(*pos, "ISPA match failure: required token did not match | grammar:  MATMUL");
						return {};
					}
					MATMUL_4 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::MATMUL>>((*lookahead_pos_1));
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
					if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::PERCENT>>((*lookahead_pos_1)))) {
						raise_error(*pos, "ISPA match failure: required token did not match | grammar:  PERCENT");
						return {};
					}
					PERCENT_6 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::PERCENT>>((*lookahead_pos_1));
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
					if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::SLASH>>((*lookahead_pos_1)))) {
						raise_error(*pos, "ISPA match failure: required token did not match | grammar:  SLASH");
						return {};
					}
					SLASH_8 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::SLASH>>((*lookahead_pos_1));
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
					if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::STAR>>((*lookahead_pos_1)))) {
						raise_error(*pos, "ISPA match failure: required token did not match | grammar:  STAR");
						return {};
					}
					STAR_10 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::STAR>>((*lookahead_pos_1));
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
			if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos))) {
				__WS_12 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos));
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
		template<typename IT>
		auto parenthesized_expr(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::parenthesized_expr, IT>{
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
			if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::LPAREN>>((*pos)))) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  LPAREN");
				return {};
			}
			LPAREN_0 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::LPAREN>>((*pos));
			success_1 = true;
			pos++;
			success_3 = false;
			if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos))) {
				__WS_2 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos));
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
			if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos))) {
				__WS_6 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos));
				success_7 = true;
				pos++;
			}
			success_9 = false;
			if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::RPAREN>>((*pos)))) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  RPAREN");
				return {};
			}
			RPAREN_8 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::RPAREN>>((*pos));
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
		template<typename IT>
		auto compare_op(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::compare_op, IT>{
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
			switch (static_cast<Tokens>((*lookahead_pos_1).index())) {
				case Tokens::EQ: {
					lookahead_pos_1 = lookahead_pos_1;
					success_3 = false;
					if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::EQ>>((*lookahead_pos_1)))) {
						raise_error(*pos, "ISPA match failure: required token did not match | grammar:  EQ");
						return {};
					}
					EQ_2 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::EQ>>((*lookahead_pos_1));
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
					if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::GE>>((*lookahead_pos_1)))) {
						raise_error(*pos, "ISPA match failure: required token did not match | grammar:  GE");
						return {};
					}
					GE_4 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::GE>>((*lookahead_pos_1));
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
					if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::GT>>((*lookahead_pos_1)))) {
						raise_error(*pos, "ISPA match failure: required token did not match | grammar:  GT");
						return {};
					}
					GT_6 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::GT>>((*lookahead_pos_1));
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
					if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::IN>>((*lookahead_pos_1)))) {
						raise_error(*pos, "ISPA match failure: required token did not match | grammar:  IN");
						return {};
					}
					IN_8 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::IN>>((*lookahead_pos_1));
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
					if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::LE>>((*lookahead_pos_1)))) {
						raise_error(*pos, "ISPA match failure: required token did not match | grammar:  LE");
						return {};
					}
					LE_12 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::LE>>((*lookahead_pos_1));
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
					if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::LT>>((*lookahead_pos_1)))) {
						raise_error(*pos, "ISPA match failure: required token did not match | grammar:  LT");
						return {};
					}
					LT_14 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::LT>>((*lookahead_pos_1));
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
					if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::NE>>((*lookahead_pos_1)))) {
						raise_error(*pos, "ISPA match failure: required token did not match | grammar:  NE");
						return {};
					}
					NE_16 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::NE>>((*lookahead_pos_1));
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
		template<typename IT>
		auto expr_list_tail(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::expr_list_tail, IT>{
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
				if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::COMMA>>((*begin_18)))) {
					// speculative match failed (diagnostic suppressed):  COMMA
					break;
				}
				COMMA_4 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::COMMA>>((*begin_18));
				success_5 = true;
				begin_18++;
				shadow_6.push_back(COMMA_4);
				uvar_3 = COMMA_4;
				success_9 = false;
				if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*begin_18))) {
					__WS_8 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*begin_18));
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
			if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos))) {
				__WS_19 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos));
				success_20 = true;
				pos++;
			}
			success_22 = false;
			if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::COMMA>>((*pos))) {
				COMMA_21 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::COMMA>>((*pos));
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
		template<typename IT>
		auto bitwise_xor(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::bitwise_xor, IT>{
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
				if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*repeat_ws_9))) {
					__WS_2 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*repeat_ws_9));
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
		template<typename IT>
		auto main(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::main, IT>{
			::ISPA_STD::MatchResult<Rules, Types::stmt, IT> stmt_1;
			bool success_2;
			::ISPA_STD::Node<::Parser::Rules, Types::stmt> element_3;
			std::vector<::ISPA_STD::Node<::Parser::Rules, Types::stmt>> shadow_4;
			std::vector<::ISPA_STD::Node<::Parser::Rules, Types::stmt>> uvar_0;
			success_2 = false;
			// grammar `@  stmt*;`: repeat named rule; collect every matched value
			while (true) {
				stmt_1 = stmt(pos);
				if (!(stmt_1.status)) {
					break;
				}
				success_2 = true;
				pos = stmt_1.it;
				element_3 = stmt_1.node;
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
		template<typename IT>
		auto assignment_suffix(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::assignment_suffix, IT>{
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
			switch (static_cast<Tokens>((*lookahead_pos_1).index())) {
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
		template<typename IT>
		auto assignment_target(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::assignment_target, IT>{
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
			if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::ID>>((*pos)))) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar: @  ID");
				return {};
			}
			ID_0 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::ID>>((*pos));
			success_1 = true;
			pos++;
			success_6 = false;
			// grammar `@  assignment_suffix*;`: repeat named rule; collect every matched value
			while (true) {
				auto repeat_ws_9 = pos;
				success_3 = false;
				if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*repeat_ws_9))) {
					__WS_2 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*repeat_ws_9));
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
		template<typename IT>
		auto dict_item(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::dict_item, IT>{
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
			if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos))) {
				__WS_2 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos));
				success_3 = true;
				pos++;
			}
			success_5 = false;
			if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::COLON>>((*pos)))) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  COLON");
				return {};
			}
			COLON_4 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::COLON>>((*pos));
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
			Types::dict_item result;
			::ISPA_STD::assign_compatible(result.key, expr_0);
			::ISPA_STD::assign_compatible(result.value, expr_8);
			::ISPA_STD::MatchResult<Rules, Types::dict_item, IT> match_result;
			match_result.status = true;
			match_result.node.set_data(result);
			match_result.it = pos;
			return match_result;
		}
		template<typename IT>
		auto keyword_arg(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::keyword_arg, IT>{
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
			if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::ASSIGN>>((*pos)))) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  ASSIGN");
				return {};
			}
			ASSIGN_4 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::ASSIGN>>((*pos));
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
			Types::keyword_arg result;
			::ISPA_STD::assign_compatible(result.name, ID_0);
			::ISPA_STD::assign_compatible(result.value, expr_8);
			::ISPA_STD::MatchResult<Rules, Types::keyword_arg, IT> match_result;
			match_result.status = true;
			match_result.node.set_data(result);
			match_result.it = pos;
			return match_result;
		}
		template<typename IT>
		auto term(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::term, IT>{
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
				if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*repeat_ws_9))) {
					__WS_2 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*repeat_ws_9));
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
		template<typename IT>
		auto call_args(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::call_args, IT>{
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
				if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*repeat_ws_9))) {
					__WS_2 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*repeat_ws_9));
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
			if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos))) {
				__WS_10 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos));
				success_11 = true;
				pos++;
			}
			success_13 = false;
			if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::COMMA>>((*pos))) {
				COMMA_12 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::COMMA>>((*pos));
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
		template<typename IT>
		auto tuple_elements(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::tuple_elements, IT>{
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
				if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*repeat_ws_26))) {
					__WS_2 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*repeat_ws_26));
					success_3 = true;
					repeat_ws_26++;
				}
				if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::COMMA>>((*repeat_ws_26)))) {
					// speculative match failed (diagnostic suppressed):  COMMA
					break;
				}
				COMMA_8 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::COMMA>>((*repeat_ws_26));
				success_9 = true;
				repeat_ws_26++;
				shadow_10.push_back(COMMA_8);
				uvar_7 = COMMA_8;
				success_13 = false;
				if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*repeat_ws_26))) {
					__WS_12 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*repeat_ws_26));
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
			if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos))) {
				__WS_27 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos));
				success_28 = true;
				pos++;
			}
			success_30 = false;
			if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::COMMA>>((*pos))) {
				COMMA_29 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::COMMA>>((*pos));
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
		template<typename IT>
		auto stmt(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::stmt, IT>{
			std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Tokens, Types::CONTINUE>, ::ISPA_STD::Node<::Parser::Rules, Types::expr_stmt>, ::ISPA_STD::Node<::Parser::Tokens, Types::BREAK>, ::ISPA_STD::Node<::Parser::Tokens, Types::PASS>, ::ISPA_STD::Node<::Parser::Rules, Types::return_stmt>> _0;
			bool success_1;
			::ISPA_STD::Node<::Parser::Tokens, Types::BREAK> BREAK_2;
			bool success_3;
			::ISPA_STD::Node<::Parser::Tokens, Types::CONTINUE> CONTINUE_4;
			bool success_5;
			::ISPA_STD::MatchResult<Rules, Types::expr_stmt, IT> expr_stmt_6;
			bool success_7;
			::ISPA_STD::MatchResult<Rules, Types::expr_stmt, IT> expr_stmt_8;
			bool success_9;
			::ISPA_STD::MatchResult<Rules, Types::expr_stmt, IT> expr_stmt_10;
			bool success_11;
			::ISPA_STD::MatchResult<Rules, Types::expr_stmt, IT> expr_stmt_12;
			bool success_13;
			::ISPA_STD::MatchResult<Rules, Types::expr_stmt, IT> expr_stmt_14;
			bool success_15;
			::ISPA_STD::MatchResult<Rules, Types::expr_stmt, IT> expr_stmt_16;
			bool success_17;
			::ISPA_STD::MatchResult<Rules, Types::expr_stmt, IT> expr_stmt_18;
			bool success_19;
			::ISPA_STD::MatchResult<Rules, Types::expr_stmt, IT> expr_stmt_20;
			bool success_21;
			::ISPA_STD::MatchResult<Rules, Types::expr_stmt, IT> expr_stmt_22;
			bool success_23;
			::ISPA_STD::Node<::Parser::Tokens, Types::PASS> PASS_24;
			bool success_25;
			::ISPA_STD::MatchResult<Rules, Types::expr_stmt, IT> expr_stmt_26;
			bool success_27;
			::ISPA_STD::MatchResult<Rules, Types::return_stmt, IT> return_stmt_28;
			bool success_29;
			::ISPA_STD::MatchResult<Rules, Types::expr_stmt, IT> expr_stmt_30;
			bool success_31;
			::ISPA_STD::MatchResult<Rules, Types::expr_stmt, IT> expr_stmt_32;
			bool success_33;
			::ISPA_STD::MatchResult<Rules, Types::expr_stmt, IT> expr_stmt_34;
			bool success_35;
			success_1 = false;
			// grammar `@  ( return_stmt |  PASS |  BREAK |  CONTINUE |  expr_stmt)`: choice; reset match status before selecting an alternative
			success_1 = false;
			auto lookahead_pos_1 = pos;
			switch (static_cast<Tokens>((*lookahead_pos_1).index())) {
				case Tokens::BREAK: {
					lookahead_pos_1 = lookahead_pos_1;
					success_3 = false;
					if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::BREAK>>((*lookahead_pos_1)))) {
						raise_error(*pos, "ISPA match failure: required token did not match | grammar:  BREAK");
						return {};
					}
					BREAK_2 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::BREAK>>((*lookahead_pos_1));
					success_3 = true;
					lookahead_pos_1++;
					if (!success_3) {
						raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  BREAK");
						return {};
					}
					_0 = BREAK_2;
					success_1 = true;
					break;
				}
				case Tokens::CONTINUE: {
					lookahead_pos_1 = lookahead_pos_1;
					success_5 = false;
					if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::CONTINUE>>((*lookahead_pos_1)))) {
						raise_error(*pos, "ISPA match failure: required token did not match | grammar:  CONTINUE");
						return {};
					}
					CONTINUE_4 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::CONTINUE>>((*lookahead_pos_1));
					success_5 = true;
					lookahead_pos_1++;
					if (!success_5) {
						raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  CONTINUE");
						return {};
					}
					_0 = CONTINUE_4;
					success_1 = true;
					break;
				}
				case Tokens::FALSE: {
					lookahead_pos_1 = lookahead_pos_1;
					success_7 = false;
					expr_stmt_6 = expr_stmt(lookahead_pos_1);
					if (!(expr_stmt_6.status)) {
						raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  expr_stmt");
						return {};
					}
					success_7 = true;
					lookahead_pos_1 = expr_stmt_6.it;
					if (!success_7) {
						raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  expr_stmt");
						return {};
					}
					_0 = expr_stmt_6.node;
					success_1 = true;
					break;
				}
				case Tokens::ID: {
					lookahead_pos_1 = lookahead_pos_1;
					success_9 = false;
					expr_stmt_8 = expr_stmt(lookahead_pos_1);
					if (!(expr_stmt_8.status)) {
						raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  expr_stmt");
						return {};
					}
					success_9 = true;
					lookahead_pos_1 = expr_stmt_8.it;
					if (!success_9) {
						raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  expr_stmt");
						return {};
					}
					_0 = expr_stmt_8.node;
					success_1 = true;
					break;
				}
				case Tokens::LBRACE: {
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
				case Tokens::LBRACKET: {
					lookahead_pos_1 = lookahead_pos_1;
					success_13 = false;
					expr_stmt_12 = expr_stmt(lookahead_pos_1);
					if (!(expr_stmt_12.status)) {
						raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  expr_stmt");
						return {};
					}
					success_13 = true;
					lookahead_pos_1 = expr_stmt_12.it;
					if (!success_13) {
						raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  expr_stmt");
						return {};
					}
					_0 = expr_stmt_12.node;
					success_1 = true;
					break;
				}
				case Tokens::LPAREN: {
					lookahead_pos_1 = lookahead_pos_1;
					success_15 = false;
					expr_stmt_14 = expr_stmt(lookahead_pos_1);
					if (!(expr_stmt_14.status)) {
						raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  expr_stmt");
						return {};
					}
					success_15 = true;
					lookahead_pos_1 = expr_stmt_14.it;
					if (!success_15) {
						raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  expr_stmt");
						return {};
					}
					_0 = expr_stmt_14.node;
					success_1 = true;
					break;
				}
				case Tokens::MINUS: {
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
				case Tokens::NONE_V: {
					lookahead_pos_1 = lookahead_pos_1;
					success_19 = false;
					expr_stmt_18 = expr_stmt(lookahead_pos_1);
					if (!(expr_stmt_18.status)) {
						raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  expr_stmt");
						return {};
					}
					success_19 = true;
					lookahead_pos_1 = expr_stmt_18.it;
					if (!success_19) {
						raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  expr_stmt");
						return {};
					}
					_0 = expr_stmt_18.node;
					success_1 = true;
					break;
				}
				case Tokens::NOT: {
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
				case Tokens::NUMBER: {
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
				case Tokens::PASS: {
					lookahead_pos_1 = lookahead_pos_1;
					success_25 = false;
					if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::PASS>>((*lookahead_pos_1)))) {
						raise_error(*pos, "ISPA match failure: required token did not match | grammar:  PASS");
						return {};
					}
					PASS_24 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::PASS>>((*lookahead_pos_1));
					success_25 = true;
					lookahead_pos_1++;
					if (!success_25) {
						raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  PASS");
						return {};
					}
					_0 = PASS_24;
					success_1 = true;
					break;
				}
				case Tokens::PLUS: {
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
				case Tokens::RETURN: {
					lookahead_pos_1 = lookahead_pos_1;
					success_29 = false;
					return_stmt_28 = return_stmt(lookahead_pos_1);
					if (!(return_stmt_28.status)) {
						raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  return_stmt");
						return {};
					}
					success_29 = true;
					lookahead_pos_1 = return_stmt_28.it;
					if (!success_29) {
						raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  return_stmt");
						return {};
					}
					_0 = return_stmt_28.node;
					success_1 = true;
					break;
				}
				case Tokens::STRING: {
					lookahead_pos_1 = lookahead_pos_1;
					success_31 = false;
					expr_stmt_30 = expr_stmt(lookahead_pos_1);
					if (!(expr_stmt_30.status)) {
						raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  expr_stmt");
						return {};
					}
					success_31 = true;
					lookahead_pos_1 = expr_stmt_30.it;
					if (!success_31) {
						raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  expr_stmt");
						return {};
					}
					_0 = expr_stmt_30.node;
					success_1 = true;
					break;
				}
				case Tokens::TILDE: {
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
				case Tokens::TRUE: {
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
			}
			pos = lookahead_pos_1;
			if (!success_1) {
				raise_error(*pos, "ISPA match failure: no LL(k) alternative matched | grammar: @  ( return_stmt |  PASS |  BREAK |  CONTINUE |  expr_stmt)");
				return {};
			}
			Types::stmt result;
			::ISPA_STD::assign_compatible(result.value, _0);
			::ISPA_STD::MatchResult<Rules, Types::stmt, IT> match_result;
			match_result.status = true;
			match_result.node.set_data(result);
			match_result.it = pos;
			return match_result;
		}
		template<typename IT>
		auto tuple_suffix(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::tuple_suffix, IT>{
			::ISPA_STD::Node<::Parser::Tokens, Types::COMMA> COMMA_0;
			bool success_1;
			::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
			bool success_3;
			::ISPA_STD::MatchResult<Rules, Types::tuple_elements, IT> tuple_elements_4;
			bool success_5;
			success_1 = false;
			if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::COMMA>>((*pos)))) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  COMMA");
				return {};
			}
			COMMA_0 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::COMMA>>((*pos));
			success_1 = true;
			pos++;
			success_3 = false;
			if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos))) {
				__WS_2 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos));
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
		template<typename IT>
		auto call_arg_tail(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::call_arg_tail, IT>{
			::ISPA_STD::Node<::Parser::Tokens, Types::COMMA> COMMA_0;
			bool success_1;
			::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
			bool success_3;
			::ISPA_STD::MatchResult<Rules, Types::call_arg, IT> call_arg_4;
			bool success_5;
			success_1 = false;
			if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::COMMA>>((*pos)))) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  COMMA");
				return {};
			}
			COMMA_0 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::COMMA>>((*pos));
			success_1 = true;
			pos++;
			success_3 = false;
			if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos))) {
				__WS_2 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos));
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
		template<typename IT>
		auto power(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::power, IT>{
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
			if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos))) {
				__WS_2 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos));
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
		template<typename IT>
		auto parenthesized_content(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::parenthesized_content, IT>{
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
			if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos))) {
				__WS_2 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos));
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
		template<typename IT>
		auto primary(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::primary, IT>{
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
				if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*repeat_ws_9))) {
					__WS_2 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*repeat_ws_9));
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
		template<typename IT>
		auto assignment_tail(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::assignment_tail, IT>{
			std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Tokens, Types::RSHIFT_ASSIGN>, ::ISPA_STD::Node<::Parser::Tokens, Types::AMP_ASSIGN>, ::ISPA_STD::Node<::Parser::Tokens, Types::POWER_ASSIGN>, ::ISPA_STD::Node<::Parser::Tokens, Types::FLOOR_DIV_ASSIGN>, ::ISPA_STD::Node<::Parser::Tokens, Types::MINUS_ASSIGN>, ::ISPA_STD::Node<::Parser::Tokens, Types::CARET_ASSIGN>, ::ISPA_STD::Node<::Parser::Tokens, Types::PERCENT_ASSIGN>, ::ISPA_STD::Node<::Parser::Tokens, Types::ASSIGN>, ::ISPA_STD::Node<::Parser::Tokens, Types::LSHIFT_ASSIGN>, ::ISPA_STD::Node<::Parser::Tokens, Types::STAR_ASSIGN>, ::ISPA_STD::Node<::Parser::Tokens, Types::PIPE_ASSIGN>, ::ISPA_STD::Node<::Parser::Tokens, Types::PLUS_ASSIGN>, ::ISPA_STD::Node<::Parser::Tokens, Types::SLASH_ASSIGN>> _0;
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
			::ISPA_STD::Node<::Parser::Tokens, Types::MINUS_ASSIGN> MINUS_ASSIGN_12;
			bool success_13;
			::ISPA_STD::Node<::Parser::Tokens, Types::PERCENT_ASSIGN> PERCENT_ASSIGN_14;
			bool success_15;
			::ISPA_STD::Node<::Parser::Tokens, Types::PIPE_ASSIGN> PIPE_ASSIGN_16;
			bool success_17;
			::ISPA_STD::Node<::Parser::Tokens, Types::PLUS_ASSIGN> PLUS_ASSIGN_18;
			bool success_19;
			::ISPA_STD::Node<::Parser::Tokens, Types::POWER_ASSIGN> POWER_ASSIGN_20;
			bool success_21;
			::ISPA_STD::Node<::Parser::Tokens, Types::RSHIFT_ASSIGN> RSHIFT_ASSIGN_22;
			bool success_23;
			::ISPA_STD::Node<::Parser::Tokens, Types::SLASH_ASSIGN> SLASH_ASSIGN_24;
			bool success_25;
			::ISPA_STD::Node<::Parser::Tokens, Types::STAR_ASSIGN> STAR_ASSIGN_26;
			bool success_27;
			::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_28;
			bool success_29;
			::ISPA_STD::MatchResult<Rules, Types::expr, IT> expr_30;
			bool success_31;
			success_1 = false;
			// grammar `@  ( ASSIGN |  PLUS_ASSIGN |  MINUS_ASSIGN |  STAR_ASSIGN |  SLASH_ASSIGN |  FLOOR_DIV_ASSIGN |  PERCENT_ASSIGN |  POWER_ASSIGN |  AMP_ASSIGN |  PIPE_ASSIGN |  CARET_ASSIGN |  LSHIFT_ASSIGN |  RSHIFT_ASSIGN)`: choice; reset match status before selecting an alternative
			success_1 = false;
			auto lookahead_pos_1 = pos;
			switch (static_cast<Tokens>((*lookahead_pos_1).index())) {
				case Tokens::AMP_ASSIGN: {
					lookahead_pos_1 = lookahead_pos_1;
					success_3 = false;
					if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::AMP_ASSIGN>>((*lookahead_pos_1)))) {
						raise_error(*pos, "ISPA match failure: required token did not match | grammar:  AMP_ASSIGN");
						return {};
					}
					AMP_ASSIGN_2 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::AMP_ASSIGN>>((*lookahead_pos_1));
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
					if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::ASSIGN>>((*lookahead_pos_1)))) {
						raise_error(*pos, "ISPA match failure: required token did not match | grammar:  ASSIGN");
						return {};
					}
					ASSIGN_4 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::ASSIGN>>((*lookahead_pos_1));
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
					if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::CARET_ASSIGN>>((*lookahead_pos_1)))) {
						raise_error(*pos, "ISPA match failure: required token did not match | grammar:  CARET_ASSIGN");
						return {};
					}
					CARET_ASSIGN_6 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::CARET_ASSIGN>>((*lookahead_pos_1));
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
					if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::FLOOR_DIV_ASSIGN>>((*lookahead_pos_1)))) {
						raise_error(*pos, "ISPA match failure: required token did not match | grammar:  FLOOR_DIV_ASSIGN");
						return {};
					}
					FLOOR_DIV_ASSIGN_8 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::FLOOR_DIV_ASSIGN>>((*lookahead_pos_1));
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
					if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::LSHIFT_ASSIGN>>((*lookahead_pos_1)))) {
						raise_error(*pos, "ISPA match failure: required token did not match | grammar:  LSHIFT_ASSIGN");
						return {};
					}
					LSHIFT_ASSIGN_10 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::LSHIFT_ASSIGN>>((*lookahead_pos_1));
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
				case Tokens::MINUS_ASSIGN: {
					lookahead_pos_1 = lookahead_pos_1;
					success_13 = false;
					if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::MINUS_ASSIGN>>((*lookahead_pos_1)))) {
						raise_error(*pos, "ISPA match failure: required token did not match | grammar:  MINUS_ASSIGN");
						return {};
					}
					MINUS_ASSIGN_12 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::MINUS_ASSIGN>>((*lookahead_pos_1));
					success_13 = true;
					lookahead_pos_1++;
					if (!success_13) {
						raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  MINUS_ASSIGN");
						return {};
					}
					_0 = MINUS_ASSIGN_12;
					success_1 = true;
					break;
				}
				case Tokens::PERCENT_ASSIGN: {
					lookahead_pos_1 = lookahead_pos_1;
					success_15 = false;
					if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::PERCENT_ASSIGN>>((*lookahead_pos_1)))) {
						raise_error(*pos, "ISPA match failure: required token did not match | grammar:  PERCENT_ASSIGN");
						return {};
					}
					PERCENT_ASSIGN_14 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::PERCENT_ASSIGN>>((*lookahead_pos_1));
					success_15 = true;
					lookahead_pos_1++;
					if (!success_15) {
						raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  PERCENT_ASSIGN");
						return {};
					}
					_0 = PERCENT_ASSIGN_14;
					success_1 = true;
					break;
				}
				case Tokens::PIPE_ASSIGN: {
					lookahead_pos_1 = lookahead_pos_1;
					success_17 = false;
					if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::PIPE_ASSIGN>>((*lookahead_pos_1)))) {
						raise_error(*pos, "ISPA match failure: required token did not match | grammar:  PIPE_ASSIGN");
						return {};
					}
					PIPE_ASSIGN_16 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::PIPE_ASSIGN>>((*lookahead_pos_1));
					success_17 = true;
					lookahead_pos_1++;
					if (!success_17) {
						raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  PIPE_ASSIGN");
						return {};
					}
					_0 = PIPE_ASSIGN_16;
					success_1 = true;
					break;
				}
				case Tokens::PLUS_ASSIGN: {
					lookahead_pos_1 = lookahead_pos_1;
					success_19 = false;
					if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::PLUS_ASSIGN>>((*lookahead_pos_1)))) {
						raise_error(*pos, "ISPA match failure: required token did not match | grammar:  PLUS_ASSIGN");
						return {};
					}
					PLUS_ASSIGN_18 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::PLUS_ASSIGN>>((*lookahead_pos_1));
					success_19 = true;
					lookahead_pos_1++;
					if (!success_19) {
						raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  PLUS_ASSIGN");
						return {};
					}
					_0 = PLUS_ASSIGN_18;
					success_1 = true;
					break;
				}
				case Tokens::POWER_ASSIGN: {
					lookahead_pos_1 = lookahead_pos_1;
					success_21 = false;
					if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::POWER_ASSIGN>>((*lookahead_pos_1)))) {
						raise_error(*pos, "ISPA match failure: required token did not match | grammar:  POWER_ASSIGN");
						return {};
					}
					POWER_ASSIGN_20 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::POWER_ASSIGN>>((*lookahead_pos_1));
					success_21 = true;
					lookahead_pos_1++;
					if (!success_21) {
						raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  POWER_ASSIGN");
						return {};
					}
					_0 = POWER_ASSIGN_20;
					success_1 = true;
					break;
				}
				case Tokens::RSHIFT_ASSIGN: {
					lookahead_pos_1 = lookahead_pos_1;
					success_23 = false;
					if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::RSHIFT_ASSIGN>>((*lookahead_pos_1)))) {
						raise_error(*pos, "ISPA match failure: required token did not match | grammar:  RSHIFT_ASSIGN");
						return {};
					}
					RSHIFT_ASSIGN_22 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::RSHIFT_ASSIGN>>((*lookahead_pos_1));
					success_23 = true;
					lookahead_pos_1++;
					if (!success_23) {
						raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  RSHIFT_ASSIGN");
						return {};
					}
					_0 = RSHIFT_ASSIGN_22;
					success_1 = true;
					break;
				}
				case Tokens::SLASH_ASSIGN: {
					lookahead_pos_1 = lookahead_pos_1;
					success_25 = false;
					if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::SLASH_ASSIGN>>((*lookahead_pos_1)))) {
						raise_error(*pos, "ISPA match failure: required token did not match | grammar:  SLASH_ASSIGN");
						return {};
					}
					SLASH_ASSIGN_24 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::SLASH_ASSIGN>>((*lookahead_pos_1));
					success_25 = true;
					lookahead_pos_1++;
					if (!success_25) {
						raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  SLASH_ASSIGN");
						return {};
					}
					_0 = SLASH_ASSIGN_24;
					success_1 = true;
					break;
				}
				case Tokens::STAR_ASSIGN: {
					lookahead_pos_1 = lookahead_pos_1;
					success_27 = false;
					if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::STAR_ASSIGN>>((*lookahead_pos_1)))) {
						raise_error(*pos, "ISPA match failure: required token did not match | grammar:  STAR_ASSIGN");
						return {};
					}
					STAR_ASSIGN_26 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::STAR_ASSIGN>>((*lookahead_pos_1));
					success_27 = true;
					lookahead_pos_1++;
					if (!success_27) {
						raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  STAR_ASSIGN");
						return {};
					}
					_0 = STAR_ASSIGN_26;
					success_1 = true;
					break;
				}
			}
			pos = lookahead_pos_1;
			if (!success_1) {
				raise_error(*pos, "ISPA match failure: no LL(k) alternative matched | grammar: @  ( ASSIGN |  PLUS_ASSIGN |  MINUS_ASSIGN |  STAR_ASSIGN |  SLASH_ASSIGN |  FLOOR_DIV_ASSIGN |  PERCENT_ASSIGN |  POWER_ASSIGN |  AMP_ASSIGN |  PIPE_ASSIGN |  CARET_ASSIGN |  LSHIFT_ASSIGN |  RSHIFT_ASSIGN)");
				return {};
			}
			success_29 = false;
			if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos))) {
				__WS_28 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos));
				success_29 = true;
				pos++;
			}
			success_31 = false;
			expr_30 = expr(pos);
			if (!(expr_30.status)) {
				raise_error(*pos, "ISPA match failure: required named rule did not match | grammar: @  expr");
				return {};
			}
			success_31 = true;
			pos = expr_30.it;
			Types::assignment_tail result;
			::ISPA_STD::assign_compatible(result.op, _0);
			::ISPA_STD::assign_compatible(result.value, expr_30);
			::ISPA_STD::MatchResult<Rules, Types::assignment_tail, IT> match_result;
			match_result.status = true;
			match_result.node.set_data(result);
			match_result.it = pos;
			return match_result;
		}
		template<typename IT>
		auto attribute_suffix(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::attribute_suffix, IT>{
			::ISPA_STD::Node<::Parser::Tokens, Types::DOT> DOT_0;
			bool success_1;
			::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
			bool success_3;
			::ISPA_STD::Node<::Parser::Tokens, Types::ID> ID_4;
			bool success_5;
			success_1 = false;
			if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::DOT>>((*pos)))) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  DOT");
				return {};
			}
			DOT_0 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::DOT>>((*pos));
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
			Types::attribute_suffix result;
			::ISPA_STD::assign_compatible(result.value, ID_4);
			::ISPA_STD::MatchResult<Rules, Types::attribute_suffix, IT> match_result;
			match_result.status = true;
			match_result.node.set_data(result);
			match_result.it = pos;
			return match_result;
		}
		template<typename IT>
		auto bitxor_tail(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::bitxor_tail, IT>{
			::ISPA_STD::Node<::Parser::Tokens, Types::CARET> CARET_0;
			bool success_1;
			::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
			bool success_3;
			::ISPA_STD::MatchResult<Rules, Types::bitwise_and, IT> bitwise_and_4;
			bool success_5;
			success_1 = false;
			if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::CARET>>((*pos)))) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  CARET");
				return {};
			}
			CARET_0 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::CARET>>((*pos));
			success_1 = true;
			pos++;
			success_3 = false;
			if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos))) {
				__WS_2 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos));
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
		template<typename IT>
		auto postfix(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::postfix, IT>{
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
			switch (static_cast<Tokens>((*lookahead_pos_1).index())) {
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
		template<typename IT>
		auto list_expr(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::list_expr, IT>{
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
			if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::LBRACKET>>((*pos)))) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  LBRACKET");
				return {};
			}
			LBRACKET_0 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::LBRACKET>>((*pos));
			success_1 = true;
			pos++;
			success_3 = false;
			if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos))) {
				__WS_2 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos));
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
			if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos))) {
				__WS_6 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos));
				success_7 = true;
				pos++;
			}
			success_9 = false;
			if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::RBRACKET>>((*pos)))) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  RBRACKET");
				return {};
			}
			RBRACKET_8 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::RBRACKET>>((*pos));
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
		template<typename IT>
		auto is_op(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::is_op, IT>{
			::ISPA_STD::Node<::Parser::Tokens, Types::IS> IS_0;
			bool success_1;
			::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
			bool success_3;
			::ISPA_STD::Node<::Parser::Tokens, Types::NOT> NOT_4;
			bool success_5;
			success_1 = false;
			if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::IS>>((*pos)))) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  IS");
				return {};
			}
			IS_0 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::IS>>((*pos));
			success_1 = true;
			pos++;
			success_3 = false;
			if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos))) {
				__WS_2 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos));
				success_3 = true;
				pos++;
			}
			success_5 = false;
			if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::NOT>>((*pos))) {
				NOT_4 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::NOT>>((*pos));
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
		template<typename IT>
		auto dict_expr(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::dict_expr, IT>{
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
			if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::LBRACE>>((*pos)))) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  LBRACE");
				return {};
			}
			LBRACE_0 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::LBRACE>>((*pos));
			success_1 = true;
			pos++;
			success_3 = false;
			if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos))) {
				__WS_2 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos));
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
			if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos))) {
				__WS_6 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos));
				success_7 = true;
				pos++;
			}
			success_9 = false;
			if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::RBRACE>>((*pos)))) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  RBRACE");
				return {};
			}
			RBRACE_8 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::RBRACE>>((*pos));
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
		template<typename IT>
		auto call_suffix(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::call_suffix, IT>{
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
			if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::LPAREN>>((*pos)))) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  LPAREN");
				return {};
			}
			LPAREN_0 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::LPAREN>>((*pos));
			success_1 = true;
			pos++;
			success_3 = false;
			if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos))) {
				__WS_2 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos));
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
			if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos))) {
				__WS_6 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos));
				success_7 = true;
				pos++;
			}
			success_9 = false;
			if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::RPAREN>>((*pos)))) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  RPAREN");
				return {};
			}
			RPAREN_8 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::RPAREN>>((*pos));
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
		template<typename IT>
		auto shift_expr(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::shift_expr, IT>{
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
				if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*repeat_ws_9))) {
					__WS_2 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*repeat_ws_9));
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
		template<typename IT>
		auto power_tail(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::power_tail, IT>{
			::ISPA_STD::Node<::Parser::Tokens, Types::POWER> POWER_0;
			bool success_1;
			::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
			bool success_3;
			::ISPA_STD::MatchResult<Rules, Types::factor, IT> factor_4;
			bool success_5;
			success_1 = false;
			if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::POWER>>((*pos)))) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  POWER");
				return {};
			}
			POWER_0 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::POWER>>((*pos));
			success_1 = true;
			pos++;
			success_3 = false;
			if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos))) {
				__WS_2 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos));
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
		template<typename IT>
		auto inversion(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::inversion, IT>{
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
			switch (static_cast<Tokens>((*lookahead_pos_1).index())) {
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
		template<typename IT>
		auto sum(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::sum, IT>{
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
				if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*repeat_ws_9))) {
					__WS_2 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*repeat_ws_9));
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
		template<typename IT>
		auto index_suffix(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::index_suffix, IT>{
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
			if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::LBRACKET>>((*pos)))) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  LBRACKET");
				return {};
			}
			LBRACKET_0 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::LBRACKET>>((*pos));
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
			if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::RBRACKET>>((*pos)))) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  RBRACKET");
				return {};
			}
			RBRACKET_8 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::RBRACKET>>((*pos));
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
		template<typename IT>
		auto factor(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::factor, IT>{
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
			switch (static_cast<Tokens>((*lookahead_pos_1).index())) {
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
		template<typename IT>
		auto return_stmt(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::return_stmt, IT>{
			::ISPA_STD::Node<::Parser::Tokens, Types::RETURN> RETURN_0;
			bool success_1;
			::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
			bool success_3;
			::ISPA_STD::MatchResult<Rules, Types::expr, IT> expr_4;
			bool success_5;
			success_1 = false;
			if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::RETURN>>((*pos)))) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  RETURN");
				return {};
			}
			RETURN_0 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::RETURN>>((*pos));
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
		template<typename IT>
		auto expr_list(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::expr_list, IT>{
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
			if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos))) {
				__WS_2 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos));
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
		template<typename IT>
		auto bitwise_and(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::bitwise_and, IT>{
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
				if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*repeat_ws_9))) {
					__WS_2 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*repeat_ws_9));
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
		template<typename IT>
		auto compare_tail(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::compare_tail, IT>{
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
			if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos))) {
				__WS_2 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos));
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
		template<typename IT>
		auto expr_stmt(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::expr_stmt, IT>{
			::ISPA_STD::MatchResult<Rules, Types::expr, IT> expr_0;
			bool success_1;
			::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
			bool success_3;
			::ISPA_STD::MatchResult<Rules, Types::assignment_tail, IT> assignment_tail_4;
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
			if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos))) {
				__WS_2 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos));
				success_3 = true;
				pos++;
			}
			success_5 = false;
			assignment_tail_4 = assignment_tail(pos);
			if (assignment_tail_4.status) {
				success_5 = true;
				pos = assignment_tail_4.it;
			}
			Types::expr_stmt result;
			::ISPA_STD::assign_compatible(result.target, expr_0);
			::ISPA_STD::assign_compatible(result.assignment, assignment_tail_4);
			::ISPA_STD::MatchResult<Rules, Types::expr_stmt, IT> match_result;
			match_result.status = true;
			match_result.node.set_data(result);
			match_result.it = pos;
			return match_result;
		}
		template<typename IT>
		auto bitwise_or(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::bitwise_or, IT>{
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
				if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*repeat_ws_9))) {
					__WS_2 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*repeat_ws_9));
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
		template<typename IT>
		auto disjunction(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::disjunction, IT>{
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
				if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*repeat_ws_9))) {
					__WS_2 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*repeat_ws_9));
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
		template<typename IT>
		auto sum_tail(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::sum_tail, IT>{
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
			switch (static_cast<Tokens>((*lookahead_pos_1).index())) {
				case Tokens::MINUS: {
					lookahead_pos_1 = lookahead_pos_1;
					success_3 = false;
					if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::MINUS>>((*lookahead_pos_1)))) {
						raise_error(*pos, "ISPA match failure: required token did not match | grammar:  MINUS");
						return {};
					}
					MINUS_2 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::MINUS>>((*lookahead_pos_1));
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
					if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::PLUS>>((*lookahead_pos_1)))) {
						raise_error(*pos, "ISPA match failure: required token did not match | grammar:  PLUS");
						return {};
					}
					PLUS_4 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::PLUS>>((*lookahead_pos_1));
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
			if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos))) {
				__WS_6 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos));
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
		template<typename IT>
		auto comparison(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::comparison, IT>{
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
				if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*repeat_ws_9))) {
					__WS_2 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*repeat_ws_9));
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
		template<typename IT>
		auto not_inversion(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::not_inversion, IT>{
			::ISPA_STD::Node<::Parser::Tokens, Types::NOT> NOT_0;
			bool success_1;
			::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
			bool success_3;
			::ISPA_STD::MatchResult<Rules, Types::inversion, IT> inversion_4;
			bool success_5;
			success_1 = false;
			if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::NOT>>((*pos)))) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  NOT");
				return {};
			}
			NOT_0 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::NOT>>((*pos));
			success_1 = true;
			pos++;
			success_3 = false;
			if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos))) {
				__WS_2 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos));
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
		template<typename IT>
		auto bitor_tail(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::bitor_tail, IT>{
			::ISPA_STD::Node<::Parser::Tokens, Types::PIPE> PIPE_0;
			bool success_1;
			::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
			bool success_3;
			::ISPA_STD::MatchResult<Rules, Types::bitwise_xor, IT> bitwise_xor_4;
			bool success_5;
			success_1 = false;
			if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::PIPE>>((*pos)))) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  PIPE");
				return {};
			}
			PIPE_0 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::PIPE>>((*pos));
			success_1 = true;
			pos++;
			success_3 = false;
			if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos))) {
				__WS_2 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos));
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
		template<typename IT>
		auto atom(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::atom, IT>{
			std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Rules, Types::parenthesized_expr>, ::ISPA_STD::Node<::Parser::Tokens, Types::NONE_V>, ::ISPA_STD::Node<::Parser::Rules, Types::list_expr>, ::ISPA_STD::Node<::Parser::Tokens, Types::FALSE>, ::ISPA_STD::Node<::Parser::Rules, Types::dict_expr>, ::ISPA_STD::Node<::Parser::Tokens, Types::TRUE>, ::ISPA_STD::Node<::Parser::Tokens, Types::NUMBER>, ::ISPA_STD::Node<::Parser::Tokens, Types::STRING>, ::ISPA_STD::Node<::Parser::Tokens, Types::ID>> _0;
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
			switch (static_cast<Tokens>((*lookahead_pos_1).index())) {
				case Tokens::FALSE: {
					lookahead_pos_1 = lookahead_pos_1;
					success_3 = false;
					if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::FALSE>>((*lookahead_pos_1)))) {
						raise_error(*pos, "ISPA match failure: required token did not match | grammar:  FALSE");
						return {};
					}
					FALSE_2 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::FALSE>>((*lookahead_pos_1));
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
					if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::ID>>((*lookahead_pos_1)))) {
						raise_error(*pos, "ISPA match failure: required token did not match | grammar:  ID");
						return {};
					}
					ID_4 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::ID>>((*lookahead_pos_1));
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
					if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::NONE_V>>((*lookahead_pos_1)))) {
						raise_error(*pos, "ISPA match failure: required token did not match | grammar:  NONE_V");
						return {};
					}
					NONE_V_12 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::NONE_V>>((*lookahead_pos_1));
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
					if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::NUMBER>>((*lookahead_pos_1)))) {
						raise_error(*pos, "ISPA match failure: required token did not match | grammar:  NUMBER");
						return {};
					}
					NUMBER_14 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::NUMBER>>((*lookahead_pos_1));
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
					if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::STRING>>((*lookahead_pos_1)))) {
						raise_error(*pos, "ISPA match failure: required token did not match | grammar:  STRING");
						return {};
					}
					STRING_16 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::STRING>>((*lookahead_pos_1));
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
					if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::TRUE>>((*lookahead_pos_1)))) {
						raise_error(*pos, "ISPA match failure: required token did not match | grammar:  TRUE");
						return {};
					}
					TRUE_18 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::TRUE>>((*lookahead_pos_1));
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
		template<typename IT>
		auto not_in(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::not_in, IT>{
			::ISPA_STD::Node<::Parser::Tokens, Types::NOT> NOT_0;
			bool success_1;
			::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
			bool success_3;
			::ISPA_STD::Node<::Parser::Tokens, Types::IN> IN_4;
			bool success_5;
			success_1 = false;
			if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::NOT>>((*pos)))) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  NOT");
				return {};
			}
			NOT_0 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::NOT>>((*pos));
			success_1 = true;
			pos++;
			success_3 = false;
			if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos))) {
				__WS_2 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos));
				success_3 = true;
				pos++;
			}
			success_5 = false;
			if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::IN>>((*pos)))) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  IN");
				return {};
			}
			IN_4 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::IN>>((*pos));
			success_5 = true;
			pos++;
			Types::not_in result;
			::ISPA_STD::MatchResult<Rules, Types::not_in, IT> match_result;
			match_result.status = true;
			match_result.node.set_data(result);
			match_result.it = pos;
			return match_result;
		}
		template<typename IT>
		auto shift_tail(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::shift_tail, IT>{
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
			switch (static_cast<Tokens>((*lookahead_pos_1).index())) {
				case Tokens::LSHIFT: {
					lookahead_pos_1 = lookahead_pos_1;
					success_3 = false;
					if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::LSHIFT>>((*lookahead_pos_1)))) {
						raise_error(*pos, "ISPA match failure: required token did not match | grammar:  LSHIFT");
						return {};
					}
					LSHIFT_2 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::LSHIFT>>((*lookahead_pos_1));
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
					if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::RSHIFT>>((*lookahead_pos_1)))) {
						raise_error(*pos, "ISPA match failure: required token did not match | grammar:  RSHIFT");
						return {};
					}
					RSHIFT_4 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::RSHIFT>>((*lookahead_pos_1));
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
			if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos))) {
				__WS_6 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos));
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
		template<typename IT>
		auto dict_item_tail(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::dict_item_tail, IT>{
			::ISPA_STD::Node<::Parser::Tokens, Types::COMMA> COMMA_0;
			bool success_1;
			::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
			bool success_3;
			::ISPA_STD::MatchResult<Rules, Types::dict_item, IT> dict_item_4;
			bool success_5;
			success_1 = false;
			if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::COMMA>>((*pos)))) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  COMMA");
				return {};
			}
			COMMA_0 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::COMMA>>((*pos));
			success_1 = true;
			pos++;
			success_3 = false;
			if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos))) {
				__WS_2 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos));
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
		template<typename IT>
		auto unary_expr(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::unary_expr, IT>{
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
			switch (static_cast<Tokens>((*lookahead_pos_1).index())) {
				case Tokens::MINUS: {
					lookahead_pos_1 = lookahead_pos_1;
					success_3 = false;
					if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::MINUS>>((*lookahead_pos_1)))) {
						raise_error(*pos, "ISPA match failure: required token did not match | grammar:  MINUS");
						return {};
					}
					MINUS_2 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::MINUS>>((*lookahead_pos_1));
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
					if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::PLUS>>((*lookahead_pos_1)))) {
						raise_error(*pos, "ISPA match failure: required token did not match | grammar:  PLUS");
						return {};
					}
					PLUS_4 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::PLUS>>((*lookahead_pos_1));
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
					if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::TILDE>>((*lookahead_pos_1)))) {
						raise_error(*pos, "ISPA match failure: required token did not match | grammar:  TILDE");
						return {};
					}
					TILDE_6 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::TILDE>>((*lookahead_pos_1));
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
			if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos))) {
				__WS_8 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos));
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
		template<typename IT>
		auto bitand_tail(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::bitand_tail, IT>{
			::ISPA_STD::Node<::Parser::Tokens, Types::AMP> AMP_0;
			bool success_1;
			::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
			bool success_3;
			::ISPA_STD::MatchResult<Rules, Types::shift_expr, IT> shift_expr_4;
			bool success_5;
			success_1 = false;
			if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::AMP>>((*pos)))) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  AMP");
				return {};
			}
			AMP_0 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::AMP>>((*pos));
			success_1 = true;
			pos++;
			success_3 = false;
			if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos))) {
				__WS_2 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos));
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
		template<typename IT>
		auto conditional_tail(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::conditional_tail, IT>{
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
			if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::IF>>((*pos)))) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  IF");
				return {};
			}
			IF_0 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::IF>>((*pos));
			success_1 = true;
			pos++;
			success_3 = false;
			if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos))) {
				__WS_2 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos));
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
			if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos))) {
				__WS_6 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos));
				success_7 = true;
				pos++;
			}
			success_9 = false;
			if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::ELSE>>((*pos)))) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  ELSE");
				return {};
			}
			ELSE_8 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::ELSE>>((*pos));
			success_9 = true;
			pos++;
			success_11 = false;
			if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos))) {
				__WS_10 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos));
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
		template<typename IT>
		auto call_arg(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::call_arg, IT>{
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
			::ISPA_STD::MatchResult<Rules, Types::expr, IT> expr_88;
			bool success_89;
			::ISPA_STD::MatchResult<Rules, Types::expr, IT> expr_90;
			bool success_91;
			::ISPA_STD::MatchResult<Rules, Types::expr, IT> expr_92;
			bool success_93;
			::ISPA_STD::MatchResult<Rules, Types::expr, IT> expr_94;
			bool success_95;
			::ISPA_STD::MatchResult<Rules, Types::expr, IT> expr_96;
			bool success_97;
			::ISPA_STD::MatchResult<Rules, Types::expr, IT> expr_98;
			bool success_99;
			::ISPA_STD::MatchResult<Rules, Types::expr, IT> expr_100;
			bool success_101;
			::ISPA_STD::MatchResult<Rules, Types::expr, IT> expr_102;
			bool success_103;
			::ISPA_STD::MatchResult<Rules, Types::expr, IT> expr_104;
			bool success_105;
			::ISPA_STD::MatchResult<Rules, Types::expr, IT> expr_106;
			bool success_107;
			success_1 = false;
			// grammar `@  ( keyword_arg |  expr)`: choice; reset match status before selecting an alternative
			success_1 = false;
			auto lookahead_pos_1 = pos;
			switch (static_cast<Tokens>((*lookahead_pos_1).index())) {
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
					switch (static_cast<Tokens>((*lookahead_pos_2).index())) {
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
						case Tokens::FALSE: {
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
						case Tokens::FLOOR_DIV: {
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
						case Tokens::GE: {
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
						case Tokens::GT: {
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
						case Tokens::ID: {
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
						case Tokens::IF: {
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
						case Tokens::IN: {
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
						case Tokens::IS: {
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
						case Tokens::LBRACE: {
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
						case Tokens::LBRACKET: {
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
						case Tokens::LE: {
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
						case Tokens::LPAREN: {
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
						case Tokens::LSHIFT: {
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
						case Tokens::LT: {
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
						case Tokens::MATMUL: {
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
						case Tokens::MINUS: {
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
						case Tokens::NE: {
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
						case Tokens::NONE_V: {
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
						case Tokens::NOT: {
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
						case Tokens::NUMBER: {
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
						case Tokens::OR: {
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
						case Tokens::PERCENT: {
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
						case Tokens::PIPE: {
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
						case Tokens::PLUS: {
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
						case Tokens::POWER: {
							lookahead_pos_2 = lookahead_pos_1;
							success_67 = false;
							expr_66 = expr(lookahead_pos_2);
							if (!(expr_66.status)) {
								raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  expr");
								return {};
							}
							success_67 = true;
							lookahead_pos_2 = expr_66.it;
							if (!success_67) {
								raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  expr");
								return {};
							}
							_0 = expr_66.node;
							success_1 = true;
							break;
						}
						case Tokens::RBRACE: {
							lookahead_pos_2 = lookahead_pos_1;
							success_69 = false;
							expr_68 = expr(lookahead_pos_2);
							if (!(expr_68.status)) {
								raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  expr");
								return {};
							}
							success_69 = true;
							lookahead_pos_2 = expr_68.it;
							if (!success_69) {
								raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  expr");
								return {};
							}
							_0 = expr_68.node;
							success_1 = true;
							break;
						}
						case Tokens::RBRACKET: {
							lookahead_pos_2 = lookahead_pos_1;
							success_71 = false;
							expr_70 = expr(lookahead_pos_2);
							if (!(expr_70.status)) {
								raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  expr");
								return {};
							}
							success_71 = true;
							lookahead_pos_2 = expr_70.it;
							if (!success_71) {
								raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  expr");
								return {};
							}
							_0 = expr_70.node;
							success_1 = true;
							break;
						}
						case Tokens::RPAREN: {
							lookahead_pos_2 = lookahead_pos_1;
							success_73 = false;
							expr_72 = expr(lookahead_pos_2);
							if (!(expr_72.status)) {
								raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  expr");
								return {};
							}
							success_73 = true;
							lookahead_pos_2 = expr_72.it;
							if (!success_73) {
								raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  expr");
								return {};
							}
							_0 = expr_72.node;
							success_1 = true;
							break;
						}
						case Tokens::RSHIFT: {
							lookahead_pos_2 = lookahead_pos_1;
							success_75 = false;
							expr_74 = expr(lookahead_pos_2);
							if (!(expr_74.status)) {
								raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  expr");
								return {};
							}
							success_75 = true;
							lookahead_pos_2 = expr_74.it;
							if (!success_75) {
								raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  expr");
								return {};
							}
							_0 = expr_74.node;
							success_1 = true;
							break;
						}
						case Tokens::SLASH: {
							lookahead_pos_2 = lookahead_pos_1;
							success_77 = false;
							expr_76 = expr(lookahead_pos_2);
							if (!(expr_76.status)) {
								raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  expr");
								return {};
							}
							success_77 = true;
							lookahead_pos_2 = expr_76.it;
							if (!success_77) {
								raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  expr");
								return {};
							}
							_0 = expr_76.node;
							success_1 = true;
							break;
						}
						case Tokens::STAR: {
							lookahead_pos_2 = lookahead_pos_1;
							success_79 = false;
							expr_78 = expr(lookahead_pos_2);
							if (!(expr_78.status)) {
								raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  expr");
								return {};
							}
							success_79 = true;
							lookahead_pos_2 = expr_78.it;
							if (!success_79) {
								raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  expr");
								return {};
							}
							_0 = expr_78.node;
							success_1 = true;
							break;
						}
						case Tokens::STRING: {
							lookahead_pos_2 = lookahead_pos_1;
							success_81 = false;
							expr_80 = expr(lookahead_pos_2);
							if (!(expr_80.status)) {
								raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  expr");
								return {};
							}
							success_81 = true;
							lookahead_pos_2 = expr_80.it;
							if (!success_81) {
								raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  expr");
								return {};
							}
							_0 = expr_80.node;
							success_1 = true;
							break;
						}
						case Tokens::TILDE: {
							lookahead_pos_2 = lookahead_pos_1;
							success_83 = false;
							expr_82 = expr(lookahead_pos_2);
							if (!(expr_82.status)) {
								raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  expr");
								return {};
							}
							success_83 = true;
							lookahead_pos_2 = expr_82.it;
							if (!success_83) {
								raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  expr");
								return {};
							}
							_0 = expr_82.node;
							success_1 = true;
							break;
						}
						case Tokens::TRUE: {
							lookahead_pos_2 = lookahead_pos_1;
							success_85 = false;
							expr_84 = expr(lookahead_pos_2);
							if (!(expr_84.status)) {
								raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  expr");
								return {};
							}
							success_85 = true;
							lookahead_pos_2 = expr_84.it;
							if (!success_85) {
								raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  expr");
								return {};
							}
							_0 = expr_84.node;
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
				case Tokens::LBRACKET: {
					lookahead_pos_1 = lookahead_pos_1;
					success_89 = false;
					expr_88 = expr(lookahead_pos_1);
					if (!(expr_88.status)) {
						raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  expr");
						return {};
					}
					success_89 = true;
					lookahead_pos_1 = expr_88.it;
					if (!success_89) {
						raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  expr");
						return {};
					}
					_0 = expr_88.node;
					success_1 = true;
					break;
				}
				case Tokens::LPAREN: {
					lookahead_pos_1 = lookahead_pos_1;
					success_91 = false;
					expr_90 = expr(lookahead_pos_1);
					if (!(expr_90.status)) {
						raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  expr");
						return {};
					}
					success_91 = true;
					lookahead_pos_1 = expr_90.it;
					if (!success_91) {
						raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  expr");
						return {};
					}
					_0 = expr_90.node;
					success_1 = true;
					break;
				}
				case Tokens::MINUS: {
					lookahead_pos_1 = lookahead_pos_1;
					success_93 = false;
					expr_92 = expr(lookahead_pos_1);
					if (!(expr_92.status)) {
						raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  expr");
						return {};
					}
					success_93 = true;
					lookahead_pos_1 = expr_92.it;
					if (!success_93) {
						raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  expr");
						return {};
					}
					_0 = expr_92.node;
					success_1 = true;
					break;
				}
				case Tokens::NONE_V: {
					lookahead_pos_1 = lookahead_pos_1;
					success_95 = false;
					expr_94 = expr(lookahead_pos_1);
					if (!(expr_94.status)) {
						raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  expr");
						return {};
					}
					success_95 = true;
					lookahead_pos_1 = expr_94.it;
					if (!success_95) {
						raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  expr");
						return {};
					}
					_0 = expr_94.node;
					success_1 = true;
					break;
				}
				case Tokens::NOT: {
					lookahead_pos_1 = lookahead_pos_1;
					success_97 = false;
					expr_96 = expr(lookahead_pos_1);
					if (!(expr_96.status)) {
						raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  expr");
						return {};
					}
					success_97 = true;
					lookahead_pos_1 = expr_96.it;
					if (!success_97) {
						raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  expr");
						return {};
					}
					_0 = expr_96.node;
					success_1 = true;
					break;
				}
				case Tokens::NUMBER: {
					lookahead_pos_1 = lookahead_pos_1;
					success_99 = false;
					expr_98 = expr(lookahead_pos_1);
					if (!(expr_98.status)) {
						raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  expr");
						return {};
					}
					success_99 = true;
					lookahead_pos_1 = expr_98.it;
					if (!success_99) {
						raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  expr");
						return {};
					}
					_0 = expr_98.node;
					success_1 = true;
					break;
				}
				case Tokens::PLUS: {
					lookahead_pos_1 = lookahead_pos_1;
					success_101 = false;
					expr_100 = expr(lookahead_pos_1);
					if (!(expr_100.status)) {
						raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  expr");
						return {};
					}
					success_101 = true;
					lookahead_pos_1 = expr_100.it;
					if (!success_101) {
						raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  expr");
						return {};
					}
					_0 = expr_100.node;
					success_1 = true;
					break;
				}
				case Tokens::STRING: {
					lookahead_pos_1 = lookahead_pos_1;
					success_103 = false;
					expr_102 = expr(lookahead_pos_1);
					if (!(expr_102.status)) {
						raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  expr");
						return {};
					}
					success_103 = true;
					lookahead_pos_1 = expr_102.it;
					if (!success_103) {
						raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  expr");
						return {};
					}
					_0 = expr_102.node;
					success_1 = true;
					break;
				}
				case Tokens::TILDE: {
					lookahead_pos_1 = lookahead_pos_1;
					success_105 = false;
					expr_104 = expr(lookahead_pos_1);
					if (!(expr_104.status)) {
						raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  expr");
						return {};
					}
					success_105 = true;
					lookahead_pos_1 = expr_104.it;
					if (!success_105) {
						raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  expr");
						return {};
					}
					_0 = expr_104.node;
					success_1 = true;
					break;
				}
				case Tokens::TRUE: {
					lookahead_pos_1 = lookahead_pos_1;
					success_107 = false;
					expr_106 = expr(lookahead_pos_1);
					if (!(expr_106.status)) {
						raise_error(*pos, "ISPA match failure: required named rule did not match | grammar:  expr");
						return {};
					}
					success_107 = true;
					lookahead_pos_1 = expr_106.it;
					if (!success_107) {
						raise_error(*pos, "ISPA match failure: selected LL(k) alternative failed | grammar:  expr");
						return {};
					}
					_0 = expr_106.node;
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
		template<typename IT>
		auto or_tail(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::or_tail, IT>{
			::ISPA_STD::Node<::Parser::Tokens, Types::OR> OR_0;
			bool success_1;
			::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
			bool success_3;
			::ISPA_STD::MatchResult<Rules, Types::conjunction, IT> conjunction_4;
			bool success_5;
			success_1 = false;
			if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::OR>>((*pos)))) {
				raise_error(*pos, "ISPA match failure: required token did not match | grammar:  OR");
				return {};
			}
			OR_0 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::OR>>((*pos));
			success_1 = true;
			pos++;
			success_3 = false;
			if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos))) {
				__WS_2 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos));
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
		template<typename IT>
		auto dict_items(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::dict_items, IT>{
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
				if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*repeat_ws_9))) {
					__WS_2 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*repeat_ws_9));
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
			if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos))) {
				__WS_10 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos));
				success_11 = true;
				pos++;
			}
			success_13 = false;
			if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::COMMA>>((*pos))) {
				COMMA_12 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::COMMA>>((*pos));
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
		template<typename IT>
		auto expr(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::expr, IT>{
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
			if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos))) {
				__WS_2 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos));
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
	public: 
		auto parseFromTokens() -> void override;
		auto lazyParse() -> void override;
	};
}
#endif // PARSER_H
