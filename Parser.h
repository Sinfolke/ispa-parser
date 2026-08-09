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
		NAME,
		AUTO_2,
		cll_LOGICAL_AND,
		AUTO_0,
		LINEAR_COMMENT,
		cll_COMPARE_OP,
		AUTO_5,
		cll_ASSIGNMENT_OP,
		MINUS,
		AUTO_4,
		SPACEMODE,
		STRING,
		DIVIDE,
		DOT,
		AUTO_11,
		QUESTION_MARK,
		MODULO,
		cll_LOGICAL_NOT,
		rule_CSEQUENCE,
		NUMBER,
		AUTO_30,
		cll_LOGICAL_OR,
		rule_OP,
		AUTO_9,
		rule_CSEQUENCE_SYMBOL,
		AT,
		rule_CSEQUENCE_DIAPASON,
		AUTO_1,
		rule_CSEQUENCE_ESCAPE,
		MULTIPLE,
		AUTO_7,
		BOOLEAN,
		rule_NOSPACE,
		rule_BIN,
		AUTO_6,
		__WHITESPACE,
		AUTO_12,
		AUTO_17,
		AUTO_14,
		AUTO_10,
		rule_HEX,
		AUTO_16,
		AUTO_19,
		AUTO_28,
		AUTO_27,
		AUTO_15,
		AUTO_18,
		rule_ESCAPED,
		AUTO_20,
		ID,
		AUTO_22,
		PLUS,
		AUTO_21,
		AUTO_8,
		cll_LOGICAL_OP,
		AUTO_3,
		AUTO_13,
		AUTO_23,
		AUTO_24,
		AUTO_25,
		AUTO_26,
		AUTO_29,
	};
	enum class Rules {
		NONE,
		_use,
		cll_function_body_call,
		rule_data_block,
		cll_function_call,
		cll_expr,
		cll_expr_term,
		cll_expr_logical,
		cll__var,
		rule_value,
		cll_stmt,
		object,
		cll_loop_while,
		cll_loop_for,
		cll__variable,
		cll_templ,
		rule_nested_rule,
		rvalue,
		rule_member,
		array,
		_use_unit,
		moduleImport_from_import_list,
		cll_expr_arithmetic,
		rule,
		main,
		cll_type,
		rule_data_block_templated_datablock,
		rule_group,
		rule_name,
		cll_expr_value,
		cll_function_body_decl,
		rule_data_block_regular_datablock_key,
		rule_data_block_regular_datablock,
		moduleDeclaration,
		cll__if,
		rule_quantifier,
		cll,
		moduleImport,
		cll_expr_group,
		moduleImport_from,
		cll_expr_compare,
		cll_method_call,
		cll_function_arguments,
		rule_keyvalue,
		cll_function_parameters,
	};
	namespace FlatTypes {
		struct cll_expr;
		struct cll_expr_term;
		struct cll__var;
		struct cll_function_call;
		struct cll_expr_compare;
		struct cll_stmt;
		struct cll_type;
		struct rvalue;
		struct rule_member;
		struct main;
		struct _use_unit;
		struct rule;
		struct cll_expr_arithmetic;
		struct cll_expr_value;
		struct AUTO_2 {
			 char value;
		};
		struct cll_LOGICAL_AND {
		};
		struct AUTO_0 {
			 char value;
		};
		struct LINEAR_COMMENT {
		};
		struct cll_COMPARE_OP {
			 std::string value;
		};
		struct AUTO_5 {
			 char value;
		};
		struct cll_ASSIGNMENT_OP {
			 std::string value;
		};
		struct MINUS {
		};
		struct AUTO_4 {
			 char value;
		};
		struct SPACEMODE {
			 std::string value;
		};
		struct STRING {
			 std::string value;
		};
		struct DIVIDE {
		};
		struct DOT {
		};
		struct AUTO_11 {
			 char value;
		};
		struct QUESTION_MARK {
		};
		struct MODULO {
		};
		struct cll_LOGICAL_NOT {
		};
		struct NUMBER {
			 std::string sign;
			 std::string main;
			 std::string dec;
		};
		struct AUTO_30 {
			 char value;
		};
		struct cll_LOGICAL_OR {
		};
		struct rule_OP {
		};
		struct AUTO_9 {
			 char value;
		};
		struct rule_CSEQUENCE_SYMBOL {
			 char value;
		};
		struct AT {
		};
		struct AUTO_1 {
			 char value;
		};
		struct rule_CSEQUENCE_ESCAPE {
			 char value;
		};
		struct MULTIPLE {
		};
		struct AUTO_7 {
			 char value;
		};
		struct BOOLEAN {
			 std::string value;
		};
		struct rule_NOSPACE {
		};
		struct rule_BIN {
			 std::string value;
		};
		struct AUTO_6 {
			 char value;
		};
		struct __WHITESPACE {
		};
		struct AUTO_12 {
			 char value;
		};
		struct AUTO_17 {
			 char value;
		};
		struct AUTO_14 {
			 char value;
		};
		struct AUTO_10 {
			 char value;
		};
		struct rule_HEX {
			 std::string value;
		};
		struct AUTO_16 {
			 char value;
		};
		struct AUTO_19 {
			 char value;
		};
		struct AUTO_28 {
			 char value;
		};
		struct AUTO_27 {
			 char value;
		};
		struct AUTO_15 {
			 char value;
		};
		struct AUTO_18 {
			 char value;
		};
		struct rule_ESCAPED {
			 char value;
		};
		struct AUTO_20 {
			 char value;
		};
		struct ID {
			 std::string value;
		};
		struct AUTO_22 {
			 char value;
		};
		struct PLUS {
		};
		struct AUTO_21 {
			 char value;
		};
		struct AUTO_8 {
			 char value;
		};
		struct AUTO_3 {
			 char value;
		};
		struct AUTO_13 {
			 char value;
		};
		struct AUTO_23 {
			 char value;
		};
		struct AUTO_24 {
			 char value;
		};
		struct AUTO_25 {
			 char value;
		};
		struct AUTO_26 {
			 char value;
		};
		struct AUTO_29 {
			 char value;
		};
		struct cll_LOGICAL_OP {
			 std::variant<std::monostate, ::ISPA_STD::Node<Tokens, cll_LOGICAL_AND>, ::ISPA_STD::Node<Tokens, cll_LOGICAL_OR>> value;
		};
		struct rule_CSEQUENCE_DIAPASON {
			 ::ISPA_STD::MatchResult<Tokens, rule_CSEQUENCE_SYMBOL> begin;
			 ::ISPA_STD::MatchResult<Tokens, rule_CSEQUENCE_SYMBOL> end;
		};
		struct rule_name {
			 ::ISPA_STD::Node<Tokens, AUTO_6> is_nested;
			 ::ISPA_STD::Node<Tokens, ID> name;
			 std::vector<::ISPA_STD::Node<Tokens, ID>> nested_name;
		};
		struct rule_value {
			 ::ISPA_STD::Node<Tokens, ID> value;
		};
		struct NAME {
			 ::ISPA_STD::Node<Tokens, ID> value;
		};
		struct rule_data_block_templated_datablock {
			 ::ISPA_STD::Node<Tokens, ID> first_name;
			 std::vector<::ISPA_STD::Node<Tokens, ID>> second_name;
		};
		struct moduleImport_from_import_list {
			 ::ISPA_STD::Node<Tokens, ID> first;
			 std::vector<::ISPA_STD::Node<Tokens, ID>> sequence;
		};
		struct moduleDeclaration {
			 ::ISPA_STD::Node<Tokens, ID> name;
			 ::ISPA_STD::Node<Tokens, ID> base;
		};
		struct rule_keyvalue {
			 ::ISPA_STD::Node<Tokens, ID> value;
		};
		struct cll_function_parameters {
			 ::ISPA_STD::Node<Tokens, ID> first;
			 std::vector<::ISPA_STD::Node<Tokens, ID>> second;
		};
		struct rule_quantifier {
			 std::variant<std::monostate, ::ISPA_STD::Node<Tokens, MULTIPLE>, ::ISPA_STD::Node<Tokens, PLUS>, ::ISPA_STD::Node<Tokens, QUESTION_MARK>> value;
		};
		struct rule_CSEQUENCE {
			 char _not;
			 std::vector<std::variant<std::monostate, ::ISPA_STD::Node<Tokens, rule_CSEQUENCE_SYMBOL>, ::ISPA_STD::Node<Tokens, rule_CSEQUENCE_DIAPASON>, ::ISPA_STD::Node<Tokens, rule_CSEQUENCE_ESCAPE>>> val;
		};
		struct moduleImport_from {
			 std::variant<std::monostate, ::ISPA_STD::Node<Rules, moduleImport_from_import_list>, ::ISPA_STD::Node<Tokens, MULTIPLE>> what;
			 ::ISPA_STD::Node<Tokens, ID> from;
		};
		struct cll_function_body_decl {
			 ::ISPA_STD::Node<Rules, cll_function_parameters> value;
		};
		struct moduleImport {
			 std::variant<std::monostate, ::ISPA_STD::Node<Rules, moduleImport_from>, ::ISPA_STD::Node<Tokens, ID>> value;
		};
		struct _use {
			 ::ISPA_STD::MatchResult<Rules, std::unique_ptr<_use_unit>> first;
			 std::vector<::ISPA_STD::MatchResult<Rules, std::unique_ptr<_use_unit>>> second;
		};
		struct cll_method_call {
			 ::ISPA_STD::Node<Tokens, ID> name;
			 ::ISPA_STD::MatchResult<Rules, std::unique_ptr<cll_function_call>> body;
		};
		struct cll_expr_group {
			 ::ISPA_STD::Node<Rules, std::unique_ptr<cll_expr>> value;
		};
		struct object {
			 std::variant<std::monostate, ::ISPA_STD::Node<Tokens, NUMBER>, ::ISPA_STD::Node<Tokens, ID>> key;
			 ::ISPA_STD::MatchResult<Rules, std::unique_ptr<cll_expr>> value;
			 std::variant<std::monostate, ::ISPA_STD::Node<Tokens, NUMBER>, ::ISPA_STD::Node<Tokens, ID>> keys;
			 std::vector<::ISPA_STD::MatchResult<Rules, std::unique_ptr<cll_expr>>> values;
		};
		struct cll_expr_logical {
			 ::ISPA_STD::MatchResult<Rules, std::unique_ptr<cll_expr_compare>> left;
			 std::vector<::ISPA_STD::Node<Tokens, cll_LOGICAL_OP>> op;
			 std::vector<::ISPA_STD::MatchResult<Rules, std::unique_ptr<cll_expr_compare>>> right;
		};
		struct cll_function_arguments {
			 ::ISPA_STD::MatchResult<Rules, std::unique_ptr<cll_expr>> first;
			 std::vector<::ISPA_STD::MatchResult<Rules, std::unique_ptr<cll_expr>>> second;
		};
		struct cll_loop_while {
			 ::ISPA_STD::MatchResult<Rules, std::unique_ptr<cll_expr>> expr;
			 ::ISPA_STD::MatchResult<Rules, std::unique_ptr<cll_stmt>> stmt;
		};
		struct array {
			 std::vector<::ISPA_STD::MatchResult<Rules, std::unique_ptr<cll_expr>>> value;
		};
		struct rule_group {
			 std::vector<::ISPA_STD::MatchResult<Rules, std::unique_ptr<rule_member>>> value;
		};
		struct cll__if {
			 ::ISPA_STD::MatchResult<Rules, std::unique_ptr<cll_expr>> expr;
			 ::ISPA_STD::MatchResult<Rules, std::unique_ptr<cll_stmt>> stmt;
		};
		struct rule_nested_rule {
			 ::ISPA_STD::Node<Rules, std::unique_ptr<rule>> value;
		};
		struct cll__variable {
			 std::variant<std::monostate, ::ISPA_STD::Node<Tokens, AUTO_30>, ::ISPA_STD::Node<Tokens, AUTO_29>> pre;
			 ::ISPA_STD::Node<Tokens, ID> name;
			 ::ISPA_STD::MatchResult<Rules, std::unique_ptr<cll_expr>> brace_expression;
			 std::variant<std::monostate, ::ISPA_STD::Node<Tokens, AUTO_30>, ::ISPA_STD::Node<Tokens, AUTO_29>> pos;
		};
		struct rule_data_block_regular_datablock_key {
			 ::ISPA_STD::Node<Tokens, ID> name;
			 ::ISPA_STD::MatchResult<Rules, std::unique_ptr<cll_expr>> dt;
		};
		struct cll_loop_for {
			 std::variant<std::monostate, ::ISPA_STD::Node<Rules, std::unique_ptr<cll__var>>, ::ISPA_STD::Node<Rules, std::unique_ptr<cll_expr>>> decl;
			 ::ISPA_STD::MatchResult<Rules, std::unique_ptr<cll_expr>> cond;
			 ::ISPA_STD::MatchResult<Rules, std::unique_ptr<cll_expr>> end;
			 ::ISPA_STD::MatchResult<Rules, std::unique_ptr<cll_stmt>> stmt;
		};
		struct cll_templ {
			 ::ISPA_STD::MatchResult<Rules, std::unique_ptr<cll_type>> first;
			 std::vector<::ISPA_STD::MatchResult<Rules, std::unique_ptr<cll_type>>> second;
		};
		struct cll_function_body_call {
			 ::ISPA_STD::Node<Rules, cll_function_arguments> value;
		};
		struct rule_data_block_regular_datablock {
			 std::variant<std::monostate, ::ISPA_STD::Node<Rules, rule_data_block_regular_datablock_key>, ::ISPA_STD::Node<Rules, std::unique_ptr<cll_expr>>> value;
		};
		struct cll {
			 std::variant<std::monostate, ::ISPA_STD::Node<Rules, std::unique_ptr<cll_expr>>, ::ISPA_STD::Node<Rules, cll__if>, ::ISPA_STD::Node<Rules, cll_loop_for>, ::ISPA_STD::Node<Rules, std::unique_ptr<cll__var>>, ::ISPA_STD::Node<Rules, cll_loop_while>> value;
		};
		struct rule_data_block {
			 std::variant<std::monostate, ::ISPA_STD::Node<Rules, rule_data_block_templated_datablock>, ::ISPA_STD::Node<Rules, rule_data_block_regular_datablock>> value;
		};
		struct cll_function_call {
			 ::ISPA_STD::Node<Tokens, ID> name;
			 ::ISPA_STD::MatchResult<Rules, cll_function_body_call> body;
		};
		struct cll_expr {
			 ::ISPA_STD::Node<Rules, cll_expr_logical> value;
		};
		struct cll_expr_term {
			 ::ISPA_STD::MatchResult<Rules, std::unique_ptr<cll_expr_value>> first;
			 std::variant<std::monostate, ::ISPA_STD::Node<Tokens, MULTIPLE>, ::ISPA_STD::Node<Tokens, MODULO>, ::ISPA_STD::Node<Tokens, DIVIDE>> operators;
			 std::vector<::ISPA_STD::MatchResult<Rules, std::unique_ptr<cll_expr_value>>> sequence;
		};
		struct cll__var {
			 ::ISPA_STD::MatchResult<Rules, std::unique_ptr<cll_type>> type;
			 ::ISPA_STD::Node<Tokens, ID> id;
			 ::ISPA_STD::Node<Tokens, cll_ASSIGNMENT_OP> op;
			 ::ISPA_STD::MatchResult<Rules, std::unique_ptr<cll_expr>> value;
		};
		struct cll_stmt {
			 std::vector<::ISPA_STD::MatchResult<Rules, std::unique_ptr<rule_member>>> value;
		};
		struct rvalue {
			 std::variant<std::monostate, ::ISPA_STD::Node<Tokens, AT>, ::ISPA_STD::Node<Rules, object>, ::ISPA_STD::Node<Tokens, STRING>, ::ISPA_STD::Node<Tokens, NUMBER>, ::ISPA_STD::Node<Rules, array>, ::ISPA_STD::Node<Tokens, ID>, ::ISPA_STD::Node<Tokens, BOOLEAN>> value;
		};
		struct rule_member {
			 std::variant<std::monostate, ::ISPA_STD::Node<Rules, rule_value>, ::ISPA_STD::Node<Rules, rule_keyvalue>> prefix;
			 std::variant<std::monostate, ::ISPA_STD::Node<Rules, rule_name>, ::ISPA_STD::Node<Tokens, DOT>, ::ISPA_STD::Node<Tokens, rule_HEX>, ::ISPA_STD::Node<Tokens, rule_ESCAPED>, ::ISPA_STD::Node<Tokens, STRING>, ::ISPA_STD::Node<Tokens, rule_CSEQUENCE>, ::ISPA_STD::Node<Rules, cll>, ::ISPA_STD::Node<Tokens, LINEAR_COMMENT>, ::ISPA_STD::Node<Tokens, rule_OP>, ::ISPA_STD::Node<Tokens, rule_BIN>, ::ISPA_STD::Node<Rules, rule_group>, ::ISPA_STD::Node<Tokens, rule_NOSPACE>> val;
			 ::ISPA_STD::MatchResult<Rules, rule_quantifier> quantifier;
		};
		struct _use_unit {
			 ::ISPA_STD::Node<Tokens, ID> name;
			 ::ISPA_STD::MatchResult<Rules, std::unique_ptr<rvalue>> value;
		};
		struct cll_expr_arithmetic {
			 ::ISPA_STD::MatchResult<Rules, std::unique_ptr<cll_expr_term>> first;
			 std::variant<std::monostate, ::ISPA_STD::Node<Tokens, PLUS>, ::ISPA_STD::Node<Tokens, MINUS>> operators;
			 std::vector<::ISPA_STD::MatchResult<Rules, std::unique_ptr<cll_expr_term>>> sequence;
		};
		struct rule {
			 ::ISPA_STD::Node<Tokens, ID> name;
			 std::vector<::ISPA_STD::MatchResult<Rules, std::unique_ptr<rule_member>>> rule;
			 ::ISPA_STD::MatchResult<Rules, rule_data_block> data_block;
			 std::vector<::ISPA_STD::MatchResult<Rules, rule_nested_rule>> nested_rules;
		};
		struct main {
			 std::variant<std::monostate, ::ISPA_STD::Node<Rules, std::unique_ptr<rule>>, ::ISPA_STD::Node<Rules, _use>, ::ISPA_STD::Node<Tokens, NAME>, ::ISPA_STD::Node<Tokens, SPACEMODE>> value;
		};
		struct cll_type {
			 ::ISPA_STD::Node<Tokens, AUTO_13> type;
			 ::ISPA_STD::MatchResult<Rules, cll_templ> templ;
		};
		struct cll_expr_value {
			 std::variant<std::monostate, ::ISPA_STD::Node<Rules, std::unique_ptr<cll_function_call>>, ::ISPA_STD::Node<Rules, cll_method_call>, ::ISPA_STD::Node<Rules, cll_expr_group>, ::ISPA_STD::Node<Rules, std::unique_ptr<rvalue>>, ::ISPA_STD::Node<Rules, cll__variable>> value;
		};
		struct cll_expr_compare {
			 ::ISPA_STD::MatchResult<Rules, std::unique_ptr<cll_expr_arithmetic>> first;
			 std::vector<::ISPA_STD::Node<Tokens, cll_COMPARE_OP>> operators;
			 std::vector<::ISPA_STD::MatchResult<Rules, std::unique_ptr<cll_expr_arithmetic>>> sequence;
		};
	}
	namespace Types {
		using AT = FlatTypes::AT;
		using AUTO_0 = FlatTypes::AUTO_0;
		using AUTO_1 = FlatTypes::AUTO_1;
		using AUTO_10 = FlatTypes::AUTO_10;
		using AUTO_11 = FlatTypes::AUTO_11;
		using AUTO_12 = FlatTypes::AUTO_12;
		using AUTO_13 = FlatTypes::AUTO_13;
		using AUTO_14 = FlatTypes::AUTO_14;
		using AUTO_15 = FlatTypes::AUTO_15;
		using AUTO_16 = FlatTypes::AUTO_16;
		using AUTO_17 = FlatTypes::AUTO_17;
		using AUTO_18 = FlatTypes::AUTO_18;
		using AUTO_19 = FlatTypes::AUTO_19;
		using AUTO_2 = FlatTypes::AUTO_2;
		using AUTO_20 = FlatTypes::AUTO_20;
		using AUTO_21 = FlatTypes::AUTO_21;
		using AUTO_22 = FlatTypes::AUTO_22;
		using AUTO_23 = FlatTypes::AUTO_23;
		using AUTO_24 = FlatTypes::AUTO_24;
		using AUTO_25 = FlatTypes::AUTO_25;
		using AUTO_26 = FlatTypes::AUTO_26;
		using AUTO_27 = FlatTypes::AUTO_27;
		using AUTO_28 = FlatTypes::AUTO_28;
		using AUTO_29 = FlatTypes::AUTO_29;
		using AUTO_3 = FlatTypes::AUTO_3;
		using AUTO_30 = FlatTypes::AUTO_30;
		using AUTO_4 = FlatTypes::AUTO_4;
		using AUTO_5 = FlatTypes::AUTO_5;
		using AUTO_6 = FlatTypes::AUTO_6;
		using AUTO_7 = FlatTypes::AUTO_7;
		using AUTO_8 = FlatTypes::AUTO_8;
		using AUTO_9 = FlatTypes::AUTO_9;
		using BOOLEAN = FlatTypes::BOOLEAN;
		using DIVIDE = FlatTypes::DIVIDE;
		using DOT = FlatTypes::DOT;
		using ID = FlatTypes::ID;
		using LINEAR_COMMENT = FlatTypes::LINEAR_COMMENT;
		using MINUS = FlatTypes::MINUS;
		using MODULO = FlatTypes::MODULO;
		using MULTIPLE = FlatTypes::MULTIPLE;
		using NAME = FlatTypes::NAME;
		using NUMBER = FlatTypes::NUMBER;
		using PLUS = FlatTypes::PLUS;
		using QUESTION_MARK = FlatTypes::QUESTION_MARK;
		using SPACEMODE = FlatTypes::SPACEMODE;
		using STRING = FlatTypes::STRING;
		using __WHITESPACE = FlatTypes::__WHITESPACE;
		struct _use : FlatTypes::_use {
			using unit = FlatTypes::_use_unit;
		};
		using array = FlatTypes::array;
		struct cll : FlatTypes::cll {
			using ASSIGNMENT_OP = FlatTypes::cll_ASSIGNMENT_OP;
			using COMPARE_OP = FlatTypes::cll_COMPARE_OP;
			using LOGICAL_AND = FlatTypes::cll_LOGICAL_AND;
			using LOGICAL_NOT = FlatTypes::cll_LOGICAL_NOT;
			using LOGICAL_OP = FlatTypes::cll_LOGICAL_OP;
			using LOGICAL_OR = FlatTypes::cll_LOGICAL_OR;
			using _if = FlatTypes::cll__if;
			using _var = FlatTypes::cll__var;
			using _variable = FlatTypes::cll__variable;
			struct expr : FlatTypes::cll_expr {
				using arithmetic = FlatTypes::cll_expr_arithmetic;
				using compare = FlatTypes::cll_expr_compare;
				using group = FlatTypes::cll_expr_group;
				using logical = FlatTypes::cll_expr_logical;
				using term = FlatTypes::cll_expr_term;
				using value = FlatTypes::cll_expr_value;
			};
			using function_arguments = FlatTypes::cll_function_arguments;
			using function_body_call = FlatTypes::cll_function_body_call;
			using function_body_decl = FlatTypes::cll_function_body_decl;
			using function_call = FlatTypes::cll_function_call;
			using function_parameters = FlatTypes::cll_function_parameters;
			using loop_for = FlatTypes::cll_loop_for;
			using loop_while = FlatTypes::cll_loop_while;
			using method_call = FlatTypes::cll_method_call;
			using stmt = FlatTypes::cll_stmt;
			using templ = FlatTypes::cll_templ;
			using type = FlatTypes::cll_type;
		};
		using main = FlatTypes::main;
		using moduleDeclaration = FlatTypes::moduleDeclaration;
		struct moduleImport : FlatTypes::moduleImport {
			struct from : FlatTypes::moduleImport_from {
				using import_list = FlatTypes::moduleImport_from_import_list;
			};
		};
		using object = FlatTypes::object;
		struct rule : FlatTypes::rule {
			using BIN = FlatTypes::rule_BIN;
			struct CSEQUENCE : FlatTypes::rule_CSEQUENCE {
				using DIAPASON = FlatTypes::rule_CSEQUENCE_DIAPASON;
				using ESCAPE = FlatTypes::rule_CSEQUENCE_ESCAPE;
				using SYMBOL = FlatTypes::rule_CSEQUENCE_SYMBOL;
			};
			using ESCAPED = FlatTypes::rule_ESCAPED;
			using HEX = FlatTypes::rule_HEX;
			using NOSPACE = FlatTypes::rule_NOSPACE;
			using OP = FlatTypes::rule_OP;
			struct data_block : FlatTypes::rule_data_block {
				struct regular_datablock : FlatTypes::rule_data_block_regular_datablock {
					using key = FlatTypes::rule_data_block_regular_datablock_key;
				};
				using templated_datablock = FlatTypes::rule_data_block_templated_datablock;
			};
			using group = FlatTypes::rule_group;
			using keyvalue = FlatTypes::rule_keyvalue;
			using member = FlatTypes::rule_member;
			using name = FlatTypes::rule_name;
			using nested_rule = FlatTypes::rule_nested_rule;
			using quantifier = FlatTypes::rule_quantifier;
			using value = FlatTypes::rule_value;
		};
		using rvalue = FlatTypes::rvalue;
	}
	using Token = std::variant<std::monostate, Types::NAME, Types::AUTO_2, Types::cll::LOGICAL_AND, Types::AUTO_0, Types::LINEAR_COMMENT, Types::cll::COMPARE_OP, Types::AUTO_5, Types::cll::ASSIGNMENT_OP, Types::MINUS, Types::AUTO_4, Types::SPACEMODE, Types::STRING, Types::DIVIDE, Types::DOT, Types::AUTO_11, Types::QUESTION_MARK, Types::MODULO, Types::cll::LOGICAL_NOT, Types::rule::CSEQUENCE, Types::NUMBER, Types::AUTO_30, Types::cll::LOGICAL_OR, Types::rule::OP, Types::AUTO_9, Types::rule::CSEQUENCE::SYMBOL, Types::AT, Types::rule::CSEQUENCE::DIAPASON, Types::AUTO_1, Types::rule::CSEQUENCE::ESCAPE, Types::MULTIPLE, Types::AUTO_7, Types::BOOLEAN, Types::rule::NOSPACE, Types::rule::BIN, Types::AUTO_6, Types::__WHITESPACE, Types::AUTO_12, Types::AUTO_17, Types::AUTO_14, Types::AUTO_10, Types::rule::HEX, Types::AUTO_16, Types::AUTO_19, Types::AUTO_28, Types::AUTO_27, Types::AUTO_15, Types::AUTO_18, Types::rule::ESCAPED, Types::AUTO_20, Types::ID, Types::AUTO_22, Types::PLUS, Types::AUTO_21, Types::AUTO_8, Types::cll::LOGICAL_OP, Types::AUTO_3, Types::AUTO_13, Types::AUTO_23, Types::AUTO_24, Types::AUTO_25, Types::AUTO_26, Types::AUTO_29>;
	class Lexer : public ::ISPA_STD::Lexer_base<Tokens, Token> {
		static ::ISPA_STD::DFAAPI::CharToClass<256> char_class_table;
		static ::ISPA_STD::DFAAPI::Table<260, 61> dfa_table;
		 bool init_done;
		auto init() -> void override;
	public: 
		auto makeToken(const char*& pos) -> Token override{
			return token = ::ISPA_STD::DFA::decide(dfa_table_1, pos, &Parser::PANIC_MODE);
		}
	};
}
#endif // PARSER_H
