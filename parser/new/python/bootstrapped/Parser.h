#pragma once

#include <ispastdlib.hpp>

namespace Parser {
	enum class Tokens {
		NONE,
		GLOBAL,
		ELIF,
		ASSERT,
		COMMENT,
		PASS,
		
		DEF,
		FINALLY,
		WHILE,
		WITH,
		MATMUL_ASSIGN,
		ASYNC,
		
		CONTINUE,
		RAISE,
		NONLOCAL,
		TILDE,
		LSHIFT_ASSIGN,
		BREAK,
		
		PERCENT_ASSIGN,
		PLUS_ASSIGN,
		STAR_ASSIGN,
		INDENT,
		DEL,
		IS,
		
		IN,
		ELSE,
		IF,
		NOT,
		ASSIGN,
		MATMUL,
		
		COMMA,
		RPAREN,
		SEMICOLON,
		NEWLINE,
		RBRACE,
		STRING,
		
		FLOOR_DIV,
		TRUE,
		SLASH_ASSIGN,
		TRY,
		POWER_ASSIGN,
		POWER,
		
		PIPE,
		__WS,
		FOR,
		COLON,
		EXCEPT,
		NONE_V,
		
		DEDENT,
		NE,
		LT,
		LE,
		STAR,
		SLASH,
		
		LBRACKET,
		GT,
		PLUS,
		LSHIFT,
		GE,
		IMPORT,
		
		FLOOR_DIV_ASSIGN,
		FALSE,
		EQ,
		CARET,
		AND,
		NUMBER,
		
		AS,
		MINUS_ASSIGN,
		LPAREN,
		ID,
		AMP,
		AMP_ASSIGN,
		
		CLASS,
		MINUS,
		DOT,
		CARET_ASSIGN,
		RSHIFT_ASSIGN,
		PERCENT,
		
		ARROW,
		OR,
		PIPE_ASSIGN,
		RSHIFT,
		RETURN,
		FROM,
		
		LBRACE,
		RBRACKET,
	};
} // namespace Parser
namespace Parser {
	enum class Rules {
		NONE,
		annotated_assignment,
		assert_stmt,
		assignment_op,
		assignment_suffix,
		assignment_tail,
		
		assignment_target,
		assignment_value,
		atom,
		attribute_suffix,
		bitand_tail,
		bitor_tail,
		
		bitwise_and,
		bitwise_or,
		bitwise_xor,
		bitxor_tail,
		block,
		break_stmt,
		
		call_arg,
		call_arg_tail,
		call_args,
		call_suffix,
		class_bases,
		class_def,
		
		class_header,
		compare_op,
		compare_tail,
		comparison,
		compound_stmt,
		conditional_tail,
		
		conjunction,
		continue_stmt,
		decorated_def,
		decorator,
		decorators,
		def_header,
		
		del_stmt,
		dict_expr,
		dict_item,
		dict_item_tail,
		dict_items,
		disjunction,
		
		dotted_as_name,
		dotted_as_names,
		dotted_name,
		elif_clause,
		else_clause,
		except_alias,
		
		except_clause,
		except_handlers,
		expr,
		expr_list,
		expr_list_tail,
		expr_stmt,
		
		factor,
		finally_clause,
		for_stmt,
		for_targets,
		function_def,
		function_header,
		
		global_stmt,
		if_stmt,
		import_alias,
		import_from,
		import_name,
		import_name_item,
		
		import_names,
		import_stmt,
		import_targets,
		indented_block,
		index_suffix,
		inversion,
		
		is_op,
		keyword_arg,
		list_expr,
		main,
		nonlocal_stmt,
		not_in,
		
		not_inversion,
		or_tail,
		parameter,
		parameter_annotation,
		parameter_default,
		parameters,
		
		parenthesized_content,
		parenthesized_expr,
		parenthesized_imports,
		pass_stmt,
		postfix,
		power,
		
		power_tail,
		primary,
		raise_from,
		raise_stmt,
		relative_module,
		return_annotation,
		
		return_stmt,
		shift_expr,
		shift_tail,
		simple_stmt,
		simple_stmts,
		statement,
		
		sum,
		sum_tail,
		term,
		term_tail,
		try_stmt,
		try_tail,
		
		tuple_elements,
		tuple_suffix,
		unary_expr,
		while_stmt,
		with_as,
		with_item,
		
		with_items,
		with_stmt,
	};
} // namespace Parser
namespace Parser::FlatTypes { struct GLOBAL; }
namespace Parser::FlatTypes { struct ELIF; }
namespace Parser::FlatTypes { struct ASSERT; }
namespace Parser::FlatTypes { struct COMMENT; }
namespace Parser::FlatTypes { struct PASS; }
namespace Parser::FlatTypes { struct DEF; }
namespace Parser::FlatTypes { struct FINALLY; }
namespace Parser::FlatTypes { struct WHILE; }
namespace Parser::FlatTypes { struct WITH; }
namespace Parser::FlatTypes { struct MATMUL_ASSIGN; }
namespace Parser::FlatTypes { struct ASYNC; }
namespace Parser::FlatTypes { struct CONTINUE; }
namespace Parser::FlatTypes { struct RAISE; }
namespace Parser::FlatTypes { struct NONLOCAL; }
namespace Parser::FlatTypes { struct TILDE; }
namespace Parser::FlatTypes { struct LSHIFT_ASSIGN; }
namespace Parser::FlatTypes { struct BREAK; }
namespace Parser::FlatTypes { struct PERCENT_ASSIGN; }
namespace Parser::FlatTypes { struct PLUS_ASSIGN; }
namespace Parser::FlatTypes { struct STAR_ASSIGN; }
namespace Parser::FlatTypes { struct INDENT; }
namespace Parser::FlatTypes { struct DEL; }
namespace Parser::FlatTypes { struct IS; }
namespace Parser::FlatTypes { struct IN; }
namespace Parser::FlatTypes { struct ELSE; }
namespace Parser::FlatTypes { struct IF; }
namespace Parser::FlatTypes { struct NOT; }
namespace Parser::FlatTypes { struct ASSIGN; }
namespace Parser::FlatTypes { struct MATMUL; }
namespace Parser::FlatTypes { struct COMMA; }
namespace Parser::FlatTypes { struct RPAREN; }
namespace Parser::FlatTypes { struct SEMICOLON; }
namespace Parser::FlatTypes { struct NEWLINE; }
namespace Parser::FlatTypes { struct RBRACE; }
namespace Parser::FlatTypes { struct STRING; }
namespace Parser::FlatTypes { struct FLOOR_DIV; }
namespace Parser::FlatTypes { struct TRUE; }
namespace Parser::FlatTypes { struct SLASH_ASSIGN; }
namespace Parser::FlatTypes { struct TRY; }
namespace Parser::FlatTypes { struct POWER_ASSIGN; }
namespace Parser::FlatTypes { struct POWER; }
namespace Parser::FlatTypes { struct PIPE; }
namespace Parser::FlatTypes { struct __WS; }
namespace Parser::FlatTypes { struct FOR; }
namespace Parser::FlatTypes { struct COLON; }
namespace Parser::FlatTypes { struct EXCEPT; }
namespace Parser::FlatTypes { struct NONE_V; }
namespace Parser::FlatTypes { struct DEDENT; }
namespace Parser::FlatTypes { struct NE; }
namespace Parser::FlatTypes { struct LT; }
namespace Parser::FlatTypes { struct LE; }
namespace Parser::FlatTypes { struct STAR; }
namespace Parser::FlatTypes { struct SLASH; }
namespace Parser::FlatTypes { struct LBRACKET; }
namespace Parser::FlatTypes { struct GT; }
namespace Parser::FlatTypes { struct PLUS; }
namespace Parser::FlatTypes { struct LSHIFT; }
namespace Parser::FlatTypes { struct GE; }
namespace Parser::FlatTypes { struct IMPORT; }
namespace Parser::FlatTypes { struct FLOOR_DIV_ASSIGN; }
namespace Parser::FlatTypes { struct FALSE; }
namespace Parser::FlatTypes { struct EQ; }
namespace Parser::FlatTypes { struct CARET; }
namespace Parser::FlatTypes { struct AND; }
namespace Parser::FlatTypes { struct NUMBER; }
namespace Parser::FlatTypes { struct AS; }
namespace Parser::FlatTypes { struct MINUS_ASSIGN; }
namespace Parser::FlatTypes { struct LPAREN; }
namespace Parser::FlatTypes { struct ID; }
namespace Parser::FlatTypes { struct AMP; }
namespace Parser::FlatTypes { struct AMP_ASSIGN; }
namespace Parser::FlatTypes { struct CLASS; }
namespace Parser::FlatTypes { struct MINUS; }
namespace Parser::FlatTypes { struct DOT; }
namespace Parser::FlatTypes { struct CARET_ASSIGN; }
namespace Parser::FlatTypes { struct RSHIFT_ASSIGN; }
namespace Parser::FlatTypes { struct PERCENT; }
namespace Parser::FlatTypes { struct ARROW; }
namespace Parser::FlatTypes { struct OR; }
namespace Parser::FlatTypes { struct PIPE_ASSIGN; }
namespace Parser::FlatTypes { struct RSHIFT; }
namespace Parser::FlatTypes { struct RETURN; }
namespace Parser::FlatTypes { struct FROM; }
namespace Parser::FlatTypes { struct LBRACE; }
namespace Parser::FlatTypes { struct RBRACKET; }
namespace Parser::FlatTypes { struct annotated_assignment; }
namespace Parser::FlatTypes { struct assert_stmt; }
namespace Parser::FlatTypes { struct assignment_op; }
namespace Parser::FlatTypes { struct assignment_suffix; }
namespace Parser::FlatTypes { struct assignment_tail; }
namespace Parser::FlatTypes { struct assignment_target; }
namespace Parser::FlatTypes { struct assignment_value; }
namespace Parser::FlatTypes { struct atom; }
namespace Parser::FlatTypes { struct attribute_suffix; }
namespace Parser::FlatTypes { struct bitand_tail; }
namespace Parser::FlatTypes { struct bitor_tail; }
namespace Parser::FlatTypes { struct bitwise_and; }
namespace Parser::FlatTypes { struct bitwise_or; }
namespace Parser::FlatTypes { struct bitwise_xor; }
namespace Parser::FlatTypes { struct bitxor_tail; }
namespace Parser::FlatTypes { struct block; }
namespace Parser::FlatTypes { struct break_stmt; }
namespace Parser::FlatTypes { struct call_arg; }
namespace Parser::FlatTypes { struct call_arg_tail; }
namespace Parser::FlatTypes { struct call_args; }
namespace Parser::FlatTypes { struct call_suffix; }
namespace Parser::FlatTypes { struct class_bases; }
namespace Parser::FlatTypes { struct class_def; }
namespace Parser::FlatTypes { struct class_header; }
namespace Parser::FlatTypes { struct compare_op; }
namespace Parser::FlatTypes { struct compare_tail; }
namespace Parser::FlatTypes { struct comparison; }
namespace Parser::FlatTypes { struct compound_stmt; }
namespace Parser::FlatTypes { struct conditional_tail; }
namespace Parser::FlatTypes { struct conjunction; }
namespace Parser::FlatTypes { struct continue_stmt; }
namespace Parser::FlatTypes { struct decorated_def; }
namespace Parser::FlatTypes { struct decorator; }
namespace Parser::FlatTypes { struct decorators; }
namespace Parser::FlatTypes { struct def_header; }
namespace Parser::FlatTypes { struct del_stmt; }
namespace Parser::FlatTypes { struct dict_expr; }
namespace Parser::FlatTypes { struct dict_item; }
namespace Parser::FlatTypes { struct dict_item_tail; }
namespace Parser::FlatTypes { struct dict_items; }
namespace Parser::FlatTypes { struct disjunction; }
namespace Parser::FlatTypes { struct dotted_as_name; }
namespace Parser::FlatTypes { struct dotted_as_names; }
namespace Parser::FlatTypes { struct dotted_name; }
namespace Parser::FlatTypes { struct elif_clause; }
namespace Parser::FlatTypes { struct else_clause; }
namespace Parser::FlatTypes { struct except_alias; }
namespace Parser::FlatTypes { struct except_clause; }
namespace Parser::FlatTypes { struct except_handlers; }
namespace Parser::FlatTypes { struct expr; }
namespace Parser::FlatTypes { struct expr_list; }
namespace Parser::FlatTypes { struct expr_list_tail; }
namespace Parser::FlatTypes { struct expr_stmt; }
namespace Parser::FlatTypes { struct factor; }
namespace Parser::FlatTypes { struct finally_clause; }
namespace Parser::FlatTypes { struct for_stmt; }
namespace Parser::FlatTypes { struct for_targets; }
namespace Parser::FlatTypes { struct function_def; }
namespace Parser::FlatTypes { struct function_header; }
namespace Parser::FlatTypes { struct global_stmt; }
namespace Parser::FlatTypes { struct if_stmt; }
namespace Parser::FlatTypes { struct import_alias; }
namespace Parser::FlatTypes { struct import_from; }
namespace Parser::FlatTypes { struct import_name; }
namespace Parser::FlatTypes { struct import_name_item; }
namespace Parser::FlatTypes { struct import_names; }
namespace Parser::FlatTypes { struct import_stmt; }
namespace Parser::FlatTypes { struct import_targets; }
namespace Parser::FlatTypes { struct indented_block; }
namespace Parser::FlatTypes { struct index_suffix; }
namespace Parser::FlatTypes { struct inversion; }
namespace Parser::FlatTypes { struct is_op; }
namespace Parser::FlatTypes { struct keyword_arg; }
namespace Parser::FlatTypes { struct list_expr; }
namespace Parser::FlatTypes { struct main; }
namespace Parser::FlatTypes { struct nonlocal_stmt; }
namespace Parser::FlatTypes { struct not_in; }
namespace Parser::FlatTypes { struct not_inversion; }
namespace Parser::FlatTypes { struct or_tail; }
namespace Parser::FlatTypes { struct parameter; }
namespace Parser::FlatTypes { struct parameter_annotation; }
namespace Parser::FlatTypes { struct parameter_default; }
namespace Parser::FlatTypes { struct parameters; }
namespace Parser::FlatTypes { struct parenthesized_content; }
namespace Parser::FlatTypes { struct parenthesized_expr; }
namespace Parser::FlatTypes { struct parenthesized_imports; }
namespace Parser::FlatTypes { struct pass_stmt; }
namespace Parser::FlatTypes { struct postfix; }
namespace Parser::FlatTypes { struct power; }
namespace Parser::FlatTypes { struct power_tail; }
namespace Parser::FlatTypes { struct primary; }
namespace Parser::FlatTypes { struct raise_from; }
namespace Parser::FlatTypes { struct raise_stmt; }
namespace Parser::FlatTypes { struct relative_module; }
namespace Parser::FlatTypes { struct return_annotation; }
namespace Parser::FlatTypes { struct return_stmt; }
namespace Parser::FlatTypes { struct shift_expr; }
namespace Parser::FlatTypes { struct shift_tail; }
namespace Parser::FlatTypes { struct simple_stmt; }
namespace Parser::FlatTypes { struct simple_stmts; }
namespace Parser::FlatTypes { struct statement; }
namespace Parser::FlatTypes { struct sum; }
namespace Parser::FlatTypes { struct sum_tail; }
namespace Parser::FlatTypes { struct term; }
namespace Parser::FlatTypes { struct term_tail; }
namespace Parser::FlatTypes { struct try_stmt; }
namespace Parser::FlatTypes { struct try_tail; }
namespace Parser::FlatTypes { struct tuple_elements; }
namespace Parser::FlatTypes { struct tuple_suffix; }
namespace Parser::FlatTypes { struct unary_expr; }
namespace Parser::FlatTypes { struct while_stmt; }
namespace Parser::FlatTypes { struct with_as; }
namespace Parser::FlatTypes { struct with_item; }
namespace Parser::FlatTypes { struct with_items; }
namespace Parser::FlatTypes { struct with_stmt; }
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, GLOBAL value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct GLOBAL {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, ELIF value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct ELIF {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, ASSERT value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct ASSERT {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, COMMENT value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct COMMENT {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, PASS value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct PASS {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, DEF value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct DEF {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, FINALLY value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct FINALLY {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, WHILE value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct WHILE {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, WITH value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct WITH {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, MATMUL_ASSIGN value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct MATMUL_ASSIGN {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, ASYNC value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct ASYNC {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, CONTINUE value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct CONTINUE {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, RAISE value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct RAISE {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, NONLOCAL value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct NONLOCAL {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, TILDE value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct TILDE {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, LSHIFT_ASSIGN value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct LSHIFT_ASSIGN {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, BREAK value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct BREAK {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, PERCENT_ASSIGN value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct PERCENT_ASSIGN {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, PLUS_ASSIGN value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct PLUS_ASSIGN {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, STAR_ASSIGN value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct STAR_ASSIGN {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, INDENT value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct INDENT {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, DEL value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct DEL {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, IS value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct IS {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, IN value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct IN {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, ELSE value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct ELSE {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, IF value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct IF {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, NOT value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct NOT {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, ASSIGN value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct ASSIGN {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, MATMUL value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct MATMUL {
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
		auto operator<<(std::ostream & os, RPAREN value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct RPAREN {
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
		auto operator<<(std::ostream & os, NEWLINE value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct NEWLINE {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, RBRACE value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct RBRACE {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, STRING value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct STRING {
			std::string value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, FLOOR_DIV value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct FLOOR_DIV {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, TRUE value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct TRUE {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, SLASH_ASSIGN value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct SLASH_ASSIGN {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, TRY value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct TRY {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, POWER_ASSIGN value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct POWER_ASSIGN {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, POWER value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct POWER {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, PIPE value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct PIPE {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
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
		auto operator<<(std::ostream & os, FOR value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct FOR {
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
		auto operator<<(std::ostream & os, EXCEPT value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct EXCEPT {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, NONE_V value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct NONE_V {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, DEDENT value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct DEDENT {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, NE value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct NE {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, LT value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct LT {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, LE value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct LE {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, STAR value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct STAR {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, SLASH value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct SLASH {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, LBRACKET value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct LBRACKET {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, GT value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct GT {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, PLUS value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct PLUS {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, LSHIFT value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct LSHIFT {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, GE value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct GE {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, IMPORT value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct IMPORT {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, FLOOR_DIV_ASSIGN value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct FLOOR_DIV_ASSIGN {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, FALSE value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct FALSE {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, EQ value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct EQ {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, CARET value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct CARET {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, AND value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct AND {
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
		auto operator<<(std::ostream & os, AS value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct AS {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, MINUS_ASSIGN value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct MINUS_ASSIGN {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, LPAREN value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct LPAREN {
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
		auto operator<<(std::ostream & os, AMP value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct AMP {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, AMP_ASSIGN value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct AMP_ASSIGN {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, CLASS value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct CLASS {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, MINUS value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct MINUS {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, DOT value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct DOT {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, CARET_ASSIGN value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct CARET_ASSIGN {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, RSHIFT_ASSIGN value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct RSHIFT_ASSIGN {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, PERCENT value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct PERCENT {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, ARROW value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct ARROW {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, OR value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct OR {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, PIPE_ASSIGN value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct PIPE_ASSIGN {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, RSHIFT value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct RSHIFT {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, RETURN value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct RETURN {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, FROM value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct FROM {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, LBRACE value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct LBRACE {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, RBRACKET value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct RBRACKET {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, bitand_tail value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct bitand_tail {
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::shift_expr>> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, bitor_tail value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct bitor_tail {
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::bitwise_xor>> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, bitwise_and value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct bitwise_and {
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::shift_expr>> first;
			std::vector<::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::bitand_tail>>> rest;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, bitwise_or value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct bitwise_or {
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::bitwise_xor>> first;
			std::vector<::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::bitor_tail>>> rest;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, bitwise_xor value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct bitwise_xor {
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::bitwise_and>> first;
			std::vector<::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::bitxor_tail>>> rest;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, bitxor_tail value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct bitxor_tail {
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::bitwise_and>> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, break_stmt value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct break_stmt {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, call_arg value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct call_arg {
			std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::expr>>, ::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::keyword_arg>>> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, call_arg_tail value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct call_arg_tail {
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::call_arg>> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, call_args value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct call_args {
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::call_arg>> first;
			std::vector<::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::call_arg_tail>>> rest;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, call_suffix value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct call_suffix {
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::call_args>> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, comparison value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct comparison {
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::bitwise_or>> first;
			std::vector<::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::compare_tail>>> rest;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, compound_stmt value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct compound_stmt {
			std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::decorated_def>>, ::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::try_stmt>>, ::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::for_stmt>>, ::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::while_stmt>>, ::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::with_stmt>>, ::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::if_stmt>>> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, conditional_tail value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct conditional_tail {
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::disjunction>> condition;
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::expr>> otherwise;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, conjunction value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct conjunction {
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::inversion>> first;
			std::vector<::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::inversion>>> rest;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, continue_stmt value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct continue_stmt {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, def_header value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct def_header {
			std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::class_header>>, ::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::function_header>>> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, dict_expr value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct dict_expr {
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::dict_items>> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, dict_item value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct dict_item {
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::expr>> key;
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::expr>> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, dict_item_tail value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct dict_item_tail {
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::dict_item>> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, dict_items value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct dict_items {
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::dict_item>> first;
			std::vector<::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::dict_item_tail>>> rest;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, disjunction value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct disjunction {
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::conjunction>> first;
			std::vector<::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::or_tail>>> rest;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, else_clause value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct else_clause {
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::block>> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, except_handlers value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct except_handlers {
			std::vector<::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::except_clause>>> handlers;
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::else_clause>> otherwise;
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::finally_clause>> finalizer;
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
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::disjunction>> value;
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::conditional_tail>> conditional;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, expr_list value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct expr_list {
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::expr>> first;
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::expr_list_tail>> rest;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, expr_list_tail value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct expr_list_tail {
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::expr>> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, factor value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct factor {
			std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::power>>, ::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::unary_expr>>> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, finally_clause value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct finally_clause {
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::block>> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, indented_block value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct indented_block {
			std::vector<::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::statement>>> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, index_suffix value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct index_suffix {
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::expr>> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, inversion value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct inversion {
			std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::comparison>>, ::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::not_inversion>>> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, is_op value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct is_op {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, list_expr value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct list_expr {
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::expr_list>> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, not_in value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct not_in {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, not_inversion value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct not_inversion {
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::inversion>> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, or_tail value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct or_tail {
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::conjunction>> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, parenthesized_content value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct parenthesized_content {
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::expr>> first;
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::tuple_suffix>> rest;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, parenthesized_expr value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct parenthesized_expr {
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::parenthesized_content>> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, pass_stmt value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct pass_stmt {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, power value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct power {
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::primary>> base;
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::power_tail>> exponent;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, power_tail value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct power_tail {
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::factor>> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, primary value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct primary {
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::atom>> base;
			std::vector<::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::postfix>>> suffixes;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, shift_expr value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct shift_expr {
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::sum>> first;
			std::vector<::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::shift_tail>>> rest;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, sum value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct sum {
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::term>> first;
			std::vector<::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::sum_tail>>> rest;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, term value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct term {
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::factor>> first;
			std::vector<::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::term_tail>>> rest;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, try_stmt value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct try_stmt {
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::block>> body;
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::try_tail>> handlers;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, try_tail value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct try_tail {
			std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::finally_clause>>, ::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::except_handlers>>> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, tuple_elements value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct tuple_elements {
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::expr>> first;
			std::vector<::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::expr>>> rest;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, tuple_suffix value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct tuple_suffix {
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::tuple_elements>> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, atom value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct atom {
			std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::list_expr>>, ::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::NONE_V>, ::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::FALSE>, ::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::TRUE>, ::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::dict_expr>>, ::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::parenthesized_expr>>, ::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::NUMBER>, ::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::STRING>, ::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::ID>> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, attribute_suffix value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct attribute_suffix {
			::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::ID> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, dotted_name value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct dotted_name {
			::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::ID> first;
			::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::ID> rest;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, except_alias value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct except_alias {
			::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::ID> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, global_stmt value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct global_stmt {
			::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::ID> first;
			::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::ID> rest;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, import_alias value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct import_alias {
			::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::ID> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, keyword_arg value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct keyword_arg {
			::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::ID> name;
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::expr>> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, nonlocal_stmt value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct nonlocal_stmt {
			::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::ID> first;
			::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::ID> rest;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, sum_tail value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct sum_tail {
			std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::MINUS>, ::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::PLUS>> op;
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::term>> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, unary_expr value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct unary_expr {
			std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::TILDE>, ::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::MINUS>, ::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::PLUS>> op;
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::factor>> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, term_tail value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct term_tail {
			std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::PERCENT>, ::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::SLASH>, ::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::STAR>, ::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::MATMUL>, ::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::FLOOR_DIV>> op;
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::factor>> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, assignment_op value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct assignment_op {
			std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::RSHIFT_ASSIGN>, ::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::CARET_ASSIGN>, ::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::AMP_ASSIGN>, ::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::POWER_ASSIGN>, ::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::FLOOR_DIV_ASSIGN>, ::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::SLASH_ASSIGN>, ::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::PIPE_ASSIGN>, ::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::MATMUL_ASSIGN>, ::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::MINUS_ASSIGN>, ::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::PERCENT_ASSIGN>, ::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::ASSIGN>, ::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::LSHIFT_ASSIGN>, ::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::STAR_ASSIGN>, ::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::PLUS_ASSIGN>> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, shift_tail value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct shift_tail {
			std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::RSHIFT>, ::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::LSHIFT>> op;
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::sum>> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, class_bases value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct class_bases {
			::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::call_args> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, annotated_assignment value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct annotated_assignment {
			::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::expr> annotation;
			::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::expr> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, assert_stmt value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct assert_stmt {
			::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::expr> condition;
			::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::expr> message;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, elif_clause value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct elif_clause {
			::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::expr> condition;
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::block>> body;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, if_stmt value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct if_stmt {
			::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::expr> condition;
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::block>> body;
			std::vector<::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::elif_clause>>> elifs;
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::else_clause>> otherwise;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, parameter_annotation value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct parameter_annotation {
			::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::expr> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, parameter_default value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct parameter_default {
			::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::expr> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, raise_from value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct raise_from {
			::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::expr> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, return_annotation value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct return_annotation {
			::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::expr> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, return_stmt value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct return_stmt {
			::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::expr> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, while_stmt value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct while_stmt {
			::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::expr> condition;
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::block>> body;
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::else_clause>> otherwise;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, compare_op value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct compare_op {
			std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::is_op>, ::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::not_in>, ::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::GT>, ::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::IN>, ::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::GE>, ::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::LT>, ::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::LE>, ::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::NE>, ::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::EQ>> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, decorator value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct decorator {
			::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::primary> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, assignment_suffix value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct assignment_suffix {
			std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::index_suffix>, ::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::attribute_suffix>> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, postfix value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct postfix {
			std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::index_suffix>>, ::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::call_suffix>>, ::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::attribute_suffix>> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, relative_module value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct relative_module {
			std::vector<::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::DOT>> relative;
			::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::dotted_name> name;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, except_clause value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct except_clause {
			::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::expr> exception;
			::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::except_alias> alias;
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::block>> body;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, dotted_as_name value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct dotted_as_name {
			::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::dotted_name> name;
			::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::import_alias> alias;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, import_name_item value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct import_name_item {
			::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::ID> name;
			::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::import_alias> alias;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, assignment_tail value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct assignment_tail {
			::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::assignment_op> op;
			::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::expr> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, class_header value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct class_header {
			::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::ID> name;
			::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::class_bases> bases;
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::block>> body;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, parameter value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct parameter {
			::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::ID> name;
			::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::parameter_annotation> annotation;
			::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::parameter_default> def;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, raise_stmt value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct raise_stmt {
			::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::expr> exception;
			::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::raise_from> cause;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, compare_tail value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct compare_tail {
			::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::compare_op> op;
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::bitwise_or>> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, decorators value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct decorators {
			std::vector<::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::decorator>> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, assignment_target value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct assignment_target {
			::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::ID> name;
			std::vector<::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::assignment_suffix>> suffixes;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, dotted_as_names value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct dotted_as_names {
			::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::dotted_as_name> first;
			::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::dotted_as_name> rest;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, import_names value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct import_names {
			::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::import_name_item> first;
			::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::import_name_item> rest;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, assignment_value value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct assignment_value {
			std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::annotated_assignment>, ::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::assignment_tail>> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, parameters value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct parameters {
			::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::parameter> first;
			::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::parameter> rest;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, class_def value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct class_def {
			::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::decorators> decorators;
			::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::class_header> definition;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, decorated_def value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct decorated_def {
			::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::decorators> decorators;
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::def_header>> definition;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, del_stmt value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct del_stmt {
			::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::assignment_target> first;
			::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::assignment_target> rest;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, for_targets value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct for_targets {
			::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::assignment_target> first;
			::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::assignment_target> rest;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, with_as value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct with_as {
			::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::assignment_target> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, import_name value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct import_name {
			::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::dotted_as_names> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, parenthesized_imports value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct parenthesized_imports {
			::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::import_names> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, expr_stmt value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct expr_stmt {
			::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::expr> target;
			::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::assignment_value> assignment;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, function_header value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct function_header {
			::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::ASYNC> async;
			::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::ID> name;
			::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::parameters> params;
			::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::return_annotation> returns;
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::block>> body;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, for_stmt value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct for_stmt {
			::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::ASYNC> async;
			::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::for_targets> targets;
			::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::expr> iterable;
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::block>> body;
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::else_clause>> otherwise;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, with_item value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct with_item {
			::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::expr> context;
			::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::with_as> target;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, import_targets value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct import_targets {
			std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::import_names>, ::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::parenthesized_imports>, ::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::STAR>> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, function_def value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct function_def {
			::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::decorators> decorators;
			::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::function_header> definition;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, with_items value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct with_items {
			::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::with_item> first;
			::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::with_item> rest;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, import_from value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct import_from {
			::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::relative_module> module;
			::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::import_targets> names;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, with_stmt value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct with_stmt {
			::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::ASYNC> async;
			::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::with_items> items;
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::block>> body;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, import_stmt value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct import_stmt {
			std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::import_from>, ::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::import_name>> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, simple_stmt value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct simple_stmt {
			std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::expr_stmt>, ::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::import_stmt>, ::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::continue_stmt>, ::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::assert_stmt>, ::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::break_stmt>, ::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::nonlocal_stmt>, ::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::pass_stmt>, ::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::global_stmt>, ::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::return_stmt>, ::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::del_stmt>, ::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::raise_stmt>> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, simple_stmts value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct simple_stmts {
			::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::simple_stmt> first;
			::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::simple_stmt> rest;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, block value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct block {
			std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::simple_stmts>, ::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::indented_block>>> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, statement value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct statement {
			std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::simple_stmts>, ::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::compound_stmt>>> value;
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
			std::vector<::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::statement>> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace Types {
		using GLOBAL = ::Parser::FlatTypes::GLOBAL;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using ELIF = ::Parser::FlatTypes::ELIF;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using ASSERT = ::Parser::FlatTypes::ASSERT;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using COMMENT = ::Parser::FlatTypes::COMMENT;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using PASS = ::Parser::FlatTypes::PASS;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using DEF = ::Parser::FlatTypes::DEF;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using FINALLY = ::Parser::FlatTypes::FINALLY;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using WHILE = ::Parser::FlatTypes::WHILE;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using WITH = ::Parser::FlatTypes::WITH;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using MATMUL_ASSIGN = ::Parser::FlatTypes::MATMUL_ASSIGN;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using ASYNC = ::Parser::FlatTypes::ASYNC;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using CONTINUE = ::Parser::FlatTypes::CONTINUE;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using RAISE = ::Parser::FlatTypes::RAISE;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using NONLOCAL = ::Parser::FlatTypes::NONLOCAL;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using TILDE = ::Parser::FlatTypes::TILDE;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using LSHIFT_ASSIGN = ::Parser::FlatTypes::LSHIFT_ASSIGN;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using BREAK = ::Parser::FlatTypes::BREAK;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using PERCENT_ASSIGN = ::Parser::FlatTypes::PERCENT_ASSIGN;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using PLUS_ASSIGN = ::Parser::FlatTypes::PLUS_ASSIGN;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using STAR_ASSIGN = ::Parser::FlatTypes::STAR_ASSIGN;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using INDENT = ::Parser::FlatTypes::INDENT;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using DEL = ::Parser::FlatTypes::DEL;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using IS = ::Parser::FlatTypes::IS;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using IN = ::Parser::FlatTypes::IN;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using ELSE = ::Parser::FlatTypes::ELSE;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using IF = ::Parser::FlatTypes::IF;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using NOT = ::Parser::FlatTypes::NOT;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using ASSIGN = ::Parser::FlatTypes::ASSIGN;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using MATMUL = ::Parser::FlatTypes::MATMUL;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using COMMA = ::Parser::FlatTypes::COMMA;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using RPAREN = ::Parser::FlatTypes::RPAREN;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using SEMICOLON = ::Parser::FlatTypes::SEMICOLON;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using NEWLINE = ::Parser::FlatTypes::NEWLINE;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using RBRACE = ::Parser::FlatTypes::RBRACE;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using STRING = ::Parser::FlatTypes::STRING;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using FLOOR_DIV = ::Parser::FlatTypes::FLOOR_DIV;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using TRUE = ::Parser::FlatTypes::TRUE;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using SLASH_ASSIGN = ::Parser::FlatTypes::SLASH_ASSIGN;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using TRY = ::Parser::FlatTypes::TRY;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using POWER_ASSIGN = ::Parser::FlatTypes::POWER_ASSIGN;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using POWER = ::Parser::FlatTypes::POWER;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using PIPE = ::Parser::FlatTypes::PIPE;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using __WS = ::Parser::FlatTypes::__WS;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using FOR = ::Parser::FlatTypes::FOR;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using COLON = ::Parser::FlatTypes::COLON;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using EXCEPT = ::Parser::FlatTypes::EXCEPT;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using NONE_V = ::Parser::FlatTypes::NONE_V;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using DEDENT = ::Parser::FlatTypes::DEDENT;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using NE = ::Parser::FlatTypes::NE;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using LT = ::Parser::FlatTypes::LT;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using LE = ::Parser::FlatTypes::LE;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using STAR = ::Parser::FlatTypes::STAR;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using SLASH = ::Parser::FlatTypes::SLASH;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using LBRACKET = ::Parser::FlatTypes::LBRACKET;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using GT = ::Parser::FlatTypes::GT;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using PLUS = ::Parser::FlatTypes::PLUS;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using LSHIFT = ::Parser::FlatTypes::LSHIFT;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using GE = ::Parser::FlatTypes::GE;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using IMPORT = ::Parser::FlatTypes::IMPORT;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using FLOOR_DIV_ASSIGN = ::Parser::FlatTypes::FLOOR_DIV_ASSIGN;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using FALSE = ::Parser::FlatTypes::FALSE;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using EQ = ::Parser::FlatTypes::EQ;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using CARET = ::Parser::FlatTypes::CARET;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using AND = ::Parser::FlatTypes::AND;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using NUMBER = ::Parser::FlatTypes::NUMBER;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using AS = ::Parser::FlatTypes::AS;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using MINUS_ASSIGN = ::Parser::FlatTypes::MINUS_ASSIGN;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using LPAREN = ::Parser::FlatTypes::LPAREN;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using ID = ::Parser::FlatTypes::ID;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using AMP = ::Parser::FlatTypes::AMP;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using AMP_ASSIGN = ::Parser::FlatTypes::AMP_ASSIGN;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using CLASS = ::Parser::FlatTypes::CLASS;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using MINUS = ::Parser::FlatTypes::MINUS;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using DOT = ::Parser::FlatTypes::DOT;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using CARET_ASSIGN = ::Parser::FlatTypes::CARET_ASSIGN;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using RSHIFT_ASSIGN = ::Parser::FlatTypes::RSHIFT_ASSIGN;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using PERCENT = ::Parser::FlatTypes::PERCENT;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using ARROW = ::Parser::FlatTypes::ARROW;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using OR = ::Parser::FlatTypes::OR;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using PIPE_ASSIGN = ::Parser::FlatTypes::PIPE_ASSIGN;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using RSHIFT = ::Parser::FlatTypes::RSHIFT;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using RETURN = ::Parser::FlatTypes::RETURN;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using FROM = ::Parser::FlatTypes::FROM;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using LBRACE = ::Parser::FlatTypes::LBRACE;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using RBRACKET = ::Parser::FlatTypes::RBRACKET;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using annotated_assignment = ::Parser::FlatTypes::annotated_assignment;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using assert_stmt = ::Parser::FlatTypes::assert_stmt;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using assignment_op = ::Parser::FlatTypes::assignment_op;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using assignment_suffix = ::Parser::FlatTypes::assignment_suffix;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using assignment_tail = ::Parser::FlatTypes::assignment_tail;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using assignment_target = ::Parser::FlatTypes::assignment_target;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using assignment_value = ::Parser::FlatTypes::assignment_value;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using atom = ::Parser::FlatTypes::atom;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using attribute_suffix = ::Parser::FlatTypes::attribute_suffix;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using bitand_tail = ::Parser::FlatTypes::bitand_tail;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using bitor_tail = ::Parser::FlatTypes::bitor_tail;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using bitwise_and = ::Parser::FlatTypes::bitwise_and;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using bitwise_or = ::Parser::FlatTypes::bitwise_or;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using bitwise_xor = ::Parser::FlatTypes::bitwise_xor;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using bitxor_tail = ::Parser::FlatTypes::bitxor_tail;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using block = ::Parser::FlatTypes::block;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using break_stmt = ::Parser::FlatTypes::break_stmt;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using call_arg = ::Parser::FlatTypes::call_arg;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using call_arg_tail = ::Parser::FlatTypes::call_arg_tail;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using call_args = ::Parser::FlatTypes::call_args;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using call_suffix = ::Parser::FlatTypes::call_suffix;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using class_bases = ::Parser::FlatTypes::class_bases;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using class_def = ::Parser::FlatTypes::class_def;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using class_header = ::Parser::FlatTypes::class_header;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using compare_op = ::Parser::FlatTypes::compare_op;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using compare_tail = ::Parser::FlatTypes::compare_tail;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using comparison = ::Parser::FlatTypes::comparison;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using compound_stmt = ::Parser::FlatTypes::compound_stmt;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using conditional_tail = ::Parser::FlatTypes::conditional_tail;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using conjunction = ::Parser::FlatTypes::conjunction;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using continue_stmt = ::Parser::FlatTypes::continue_stmt;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using decorated_def = ::Parser::FlatTypes::decorated_def;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using decorator = ::Parser::FlatTypes::decorator;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using decorators = ::Parser::FlatTypes::decorators;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using def_header = ::Parser::FlatTypes::def_header;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using del_stmt = ::Parser::FlatTypes::del_stmt;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using dict_expr = ::Parser::FlatTypes::dict_expr;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using dict_item = ::Parser::FlatTypes::dict_item;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using dict_item_tail = ::Parser::FlatTypes::dict_item_tail;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using dict_items = ::Parser::FlatTypes::dict_items;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using disjunction = ::Parser::FlatTypes::disjunction;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using dotted_as_name = ::Parser::FlatTypes::dotted_as_name;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using dotted_as_names = ::Parser::FlatTypes::dotted_as_names;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using dotted_name = ::Parser::FlatTypes::dotted_name;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using elif_clause = ::Parser::FlatTypes::elif_clause;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using else_clause = ::Parser::FlatTypes::else_clause;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using except_alias = ::Parser::FlatTypes::except_alias;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using except_clause = ::Parser::FlatTypes::except_clause;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using except_handlers = ::Parser::FlatTypes::except_handlers;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using expr = ::Parser::FlatTypes::expr;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using expr_list = ::Parser::FlatTypes::expr_list;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using expr_list_tail = ::Parser::FlatTypes::expr_list_tail;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using expr_stmt = ::Parser::FlatTypes::expr_stmt;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using factor = ::Parser::FlatTypes::factor;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using finally_clause = ::Parser::FlatTypes::finally_clause;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using for_stmt = ::Parser::FlatTypes::for_stmt;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using for_targets = ::Parser::FlatTypes::for_targets;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using function_def = ::Parser::FlatTypes::function_def;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using function_header = ::Parser::FlatTypes::function_header;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using global_stmt = ::Parser::FlatTypes::global_stmt;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using if_stmt = ::Parser::FlatTypes::if_stmt;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using import_alias = ::Parser::FlatTypes::import_alias;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using import_from = ::Parser::FlatTypes::import_from;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using import_name = ::Parser::FlatTypes::import_name;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using import_name_item = ::Parser::FlatTypes::import_name_item;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using import_names = ::Parser::FlatTypes::import_names;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using import_stmt = ::Parser::FlatTypes::import_stmt;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using import_targets = ::Parser::FlatTypes::import_targets;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using indented_block = ::Parser::FlatTypes::indented_block;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using index_suffix = ::Parser::FlatTypes::index_suffix;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using inversion = ::Parser::FlatTypes::inversion;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using is_op = ::Parser::FlatTypes::is_op;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using keyword_arg = ::Parser::FlatTypes::keyword_arg;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using list_expr = ::Parser::FlatTypes::list_expr;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using main = ::Parser::FlatTypes::main;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using nonlocal_stmt = ::Parser::FlatTypes::nonlocal_stmt;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using not_in = ::Parser::FlatTypes::not_in;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using not_inversion = ::Parser::FlatTypes::not_inversion;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using or_tail = ::Parser::FlatTypes::or_tail;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using parameter = ::Parser::FlatTypes::parameter;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using parameter_annotation = ::Parser::FlatTypes::parameter_annotation;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using parameter_default = ::Parser::FlatTypes::parameter_default;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using parameters = ::Parser::FlatTypes::parameters;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using parenthesized_content = ::Parser::FlatTypes::parenthesized_content;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using parenthesized_expr = ::Parser::FlatTypes::parenthesized_expr;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using parenthesized_imports = ::Parser::FlatTypes::parenthesized_imports;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using pass_stmt = ::Parser::FlatTypes::pass_stmt;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using postfix = ::Parser::FlatTypes::postfix;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using power = ::Parser::FlatTypes::power;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using power_tail = ::Parser::FlatTypes::power_tail;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using primary = ::Parser::FlatTypes::primary;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using raise_from = ::Parser::FlatTypes::raise_from;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using raise_stmt = ::Parser::FlatTypes::raise_stmt;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using relative_module = ::Parser::FlatTypes::relative_module;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using return_annotation = ::Parser::FlatTypes::return_annotation;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using return_stmt = ::Parser::FlatTypes::return_stmt;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using shift_expr = ::Parser::FlatTypes::shift_expr;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using shift_tail = ::Parser::FlatTypes::shift_tail;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using simple_stmt = ::Parser::FlatTypes::simple_stmt;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using simple_stmts = ::Parser::FlatTypes::simple_stmts;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using statement = ::Parser::FlatTypes::statement;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using sum = ::Parser::FlatTypes::sum;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using sum_tail = ::Parser::FlatTypes::sum_tail;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using term = ::Parser::FlatTypes::term;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using term_tail = ::Parser::FlatTypes::term_tail;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using try_stmt = ::Parser::FlatTypes::try_stmt;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using try_tail = ::Parser::FlatTypes::try_tail;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using tuple_elements = ::Parser::FlatTypes::tuple_elements;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using tuple_suffix = ::Parser::FlatTypes::tuple_suffix;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using unary_expr = ::Parser::FlatTypes::unary_expr;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using while_stmt = ::Parser::FlatTypes::while_stmt;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using with_as = ::Parser::FlatTypes::with_as;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using with_item = ::Parser::FlatTypes::with_item;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using with_items = ::Parser::FlatTypes::with_items;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using with_stmt = ::Parser::FlatTypes::with_stmt;
	} // namespace Types
} // namespace Parser
namespace Parser {
	using Token = ::ISPA_STD::RawToken<::Parser::Tokens, Types::GLOBAL, Types::ELIF, Types::ASSERT, Types::COMMENT, Types::PASS, Types::DEF, Types::FINALLY, Types::WHILE, Types::WITH, Types::MATMUL_ASSIGN, Types::ASYNC, Types::CONTINUE, Types::RAISE, Types::NONLOCAL, Types::TILDE, Types::LSHIFT_ASSIGN, Types::BREAK, Types::PERCENT_ASSIGN, Types::PLUS_ASSIGN, Types::STAR_ASSIGN, Types::INDENT, Types::DEL, Types::IS, Types::IN, Types::ELSE, Types::IF, Types::NOT, Types::ASSIGN, Types::MATMUL, Types::COMMA, Types::RPAREN, Types::SEMICOLON, Types::NEWLINE, Types::RBRACE, Types::STRING, Types::FLOOR_DIV, Types::TRUE, Types::SLASH_ASSIGN, Types::TRY, Types::POWER_ASSIGN, Types::POWER, Types::PIPE, Types::__WS, Types::FOR, Types::COLON, Types::EXCEPT, Types::NONE_V, Types::DEDENT, Types::NE, Types::LT, Types::LE, Types::STAR, Types::SLASH, Types::LBRACKET, Types::GT, Types::PLUS, Types::LSHIFT, Types::GE, Types::IMPORT, Types::FLOOR_DIV_ASSIGN, Types::FALSE, Types::EQ, Types::CARET, Types::AND, Types::NUMBER, Types::AS, Types::MINUS_ASSIGN, Types::LPAREN, Types::ID, Types::AMP, Types::AMP_ASSIGN, Types::CLASS, Types::MINUS, Types::DOT, Types::CARET_ASSIGN, Types::RSHIFT_ASSIGN, Types::PERCENT, Types::ARROW, Types::OR, Types::PIPE_ASSIGN, Types::RSHIFT, Types::RETURN, Types::FROM, Types::LBRACE, Types::RBRACKET>;
} // namespace Parser
namespace Parser {
	class Lexer : public ::ISPA_STD::Lexer_base<::Parser::Tokens, Token> {
		static ::ISPA_STD::DFA::API::CharToClass char_class_table;
		static ::ISPA_STD::DFA::API::Table<175, 56> dfa_table;
		static ::ISPA_STD::DFA::API::Table<234, 4> action_table;
		static auto semantic_action_exec(long long state, const ::ISPA_STD::DFA::API::Captures& captures, long long start_pos, const char* start, long long length, long long line) -> std::pair<long long, Token>;
		bool init_done = false;
		auto init() -> void override;
		::ISPA_STD::DFA::API::TdfaLayout<11, 8> tdfa_registers;
		static std::array<::ISPA_STD::DFA::API::DFADebug, 1> debug_array;
		static std::unordered_map<long long, std::unordered_map<long long, long long>> debug_index;
	public:
		auto makeToken(const char*& pos) -> Token override;
	};
} // namespace Parser
namespace Parser {
	class Parser : public ::ISPA_STD::LLParser_base<::Parser::Tokens, ::Parser::Rules, Types::main, Token> {
	protected:
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto annotated_assignment(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::annotated_assignment, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto assert_stmt(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::assert_stmt, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto assignment_op(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::assignment_op, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto assignment_suffix(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::assignment_suffix, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto assignment_tail(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::assignment_tail, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto assignment_target(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::assignment_target, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto assignment_value(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::assignment_value, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto atom(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::atom, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto attribute_suffix(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::attribute_suffix, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto bitand_tail(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::bitand_tail, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto bitor_tail(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::bitor_tail, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto bitwise_and(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::bitwise_and, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto bitwise_or(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::bitwise_or, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto bitwise_xor(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::bitwise_xor, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto bitxor_tail(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::bitxor_tail, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto block(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::block, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto break_stmt(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::break_stmt, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto call_arg(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::call_arg, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto call_arg_tail(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::call_arg_tail, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto call_args(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::call_args, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto call_suffix(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::call_suffix, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto class_bases(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::class_bases, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto class_def(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::class_def, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto class_header(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::class_header, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto compare_op(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::compare_op, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto compare_tail(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::compare_tail, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto comparison(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::comparison, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto compound_stmt(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::compound_stmt, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto conditional_tail(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::conditional_tail, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto conjunction(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::conjunction, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto continue_stmt(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::continue_stmt, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto decorated_def(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::decorated_def, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto decorator(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::decorator, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto decorators(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::decorators, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto def_header(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::def_header, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto del_stmt(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::del_stmt, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto dict_expr(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::dict_expr, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto dict_item(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::dict_item, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto dict_item_tail(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::dict_item_tail, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto dict_items(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::dict_items, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto disjunction(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::disjunction, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto dotted_as_name(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::dotted_as_name, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto dotted_as_names(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::dotted_as_names, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto dotted_name(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::dotted_name, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto elif_clause(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::elif_clause, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto else_clause(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::else_clause, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto except_alias(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::except_alias, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto except_clause(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::except_clause, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto except_handlers(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::except_handlers, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto expr(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::expr, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto expr_list(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::expr_list, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto expr_list_tail(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::expr_list_tail, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto expr_stmt(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::expr_stmt, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto factor(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::factor, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto finally_clause(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::finally_clause, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto for_stmt(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::for_stmt, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto for_targets(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::for_targets, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto function_def(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::function_def, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto function_header(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::function_header, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto global_stmt(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::global_stmt, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto if_stmt(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::if_stmt, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto import_alias(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::import_alias, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto import_from(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::import_from, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto import_name(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::import_name, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto import_name_item(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::import_name_item, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto import_names(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::import_names, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto import_stmt(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::import_stmt, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto import_targets(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::import_targets, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto indented_block(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::indented_block, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto index_suffix(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::index_suffix, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto inversion(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::inversion, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto is_op(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::is_op, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto keyword_arg(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::keyword_arg, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto list_expr(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::list_expr, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto main(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::main, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto nonlocal_stmt(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::nonlocal_stmt, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto not_in(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::not_in, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto not_inversion(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::not_inversion, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto or_tail(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::or_tail, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto parameter(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::parameter, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto parameter_annotation(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::parameter_annotation, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto parameter_default(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::parameter_default, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto parameters(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::parameters, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto parenthesized_content(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::parenthesized_content, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto parenthesized_expr(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::parenthesized_expr, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto parenthesized_imports(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::parenthesized_imports, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto pass_stmt(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::pass_stmt, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto postfix(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::postfix, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto power(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::power, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto power_tail(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::power_tail, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto primary(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::primary, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto raise_from(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::raise_from, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto raise_stmt(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::raise_stmt, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto relative_module(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::relative_module, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto return_annotation(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::return_annotation, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto return_stmt(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::return_stmt, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto shift_expr(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::shift_expr, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto shift_tail(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::shift_tail, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto simple_stmt(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::simple_stmt, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto simple_stmts(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::simple_stmts, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto statement(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::statement, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto sum(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::sum, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto sum_tail(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::sum_tail, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto term(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::term, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto term_tail(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::term_tail, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto try_stmt(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::try_stmt, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto try_tail(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::try_tail, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto tuple_elements(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::tuple_elements, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto tuple_suffix(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::tuple_suffix, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto unary_expr(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::unary_expr, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto while_stmt(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::while_stmt, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto with_as(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::with_as, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto with_item(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::with_item, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto with_items(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::with_items, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto with_stmt(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::with_stmt, IT>;
	public:
		auto parseFromTokens() -> void override;
		auto lazyParse() -> void override;
	};
} // namespace Parser
