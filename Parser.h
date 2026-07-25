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
			 std::variant<std::monostate, ::ISPA_STD::Node<Rules, cll_loop_for>, ::ISPA_STD::Node<Rules, std::unique_ptr<cll__var>>, ::ISPA_STD::Node<Rules, std::unique_ptr<cll_expr>>, ::ISPA_STD::Node<Rules, cll__if>, ::ISPA_STD::Node<Rules, cll_loop_while>> value;
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
			 std::variant<std::monostate, ::ISPA_STD::Node<Tokens, MODULO>, ::ISPA_STD::Node<Tokens, MULTIPLE>, ::ISPA_STD::Node<Tokens, DIVIDE>> operators;
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
			 std::variant<std::monostate, ::ISPA_STD::Node<Tokens, NUMBER>, ::ISPA_STD::Node<Tokens, ID>, ::ISPA_STD::Node<Tokens, AT>, ::ISPA_STD::Node<Tokens, STRING>, ::ISPA_STD::Node<Rules, array>, ::ISPA_STD::Node<Rules, object>, ::ISPA_STD::Node<Tokens, BOOLEAN>> value;
		};
		struct rule_member {
			 std::variant<std::monostate, ::ISPA_STD::Node<Rules, rule_value>, ::ISPA_STD::Node<Rules, rule_keyvalue>> prefix;
			 std::variant<std::monostate, ::ISPA_STD::Node<Tokens, LINEAR_COMMENT>, ::ISPA_STD::Node<Tokens, STRING>, ::ISPA_STD::Node<Rules, rule_name>, ::ISPA_STD::Node<Rules, rule_group>, ::ISPA_STD::Node<Tokens, DOT>, ::ISPA_STD::Node<Tokens, rule_CSEQUENCE>, ::ISPA_STD::Node<Rules, cll>, ::ISPA_STD::Node<Tokens, rule_ESCAPED>, ::ISPA_STD::Node<Tokens, rule_HEX>, ::ISPA_STD::Node<Tokens, rule_OP>, ::ISPA_STD::Node<Tokens, rule_BIN>, ::ISPA_STD::Node<Tokens, rule_NOSPACE>> val;
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
			 std::variant<std::monostate, ::ISPA_STD::Node<Rules, std::unique_ptr<rvalue>>, ::ISPA_STD::Node<Rules, cll_method_call>, ::ISPA_STD::Node<Rules, cll_expr_group>, ::ISPA_STD::Node<Rules, std::unique_ptr<cll_function_call>>, ::ISPA_STD::Node<Rules, cll__variable>> value;
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
		static ::ISPA_STD::DFAAPI::CharState dfa_state_0;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_1;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_2;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_3;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_4;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_5;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_6;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_7;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_8;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_9;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_10;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_11;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_12;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_13;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_14;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_15;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_16;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_17;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_18;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_19;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_20;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_21;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_22;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_23;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_24;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_25;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_26;
		static ::ISPA_STD::DFAAPI::CharTableState<Tokens, Token, 1> dfa_state_27;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_28;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_29;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_30;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_31;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_32;
		static ::ISPA_STD::DFAAPI::CharTableState<Tokens, Token, 1> dfa_state_33;
		static ::ISPA_STD::DFAAPI::CharTableState<Tokens, Token, 2> dfa_state_34;
		static ::ISPA_STD::DFAAPI::CharTableState<Tokens, Token, 2> dfa_state_35;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_36;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_37;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_38;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_39;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_40;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_41;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_42;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_43;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_44;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_45;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_46;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_47;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_48;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_49;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_50;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_51;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_52;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_53;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_54;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_55;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_56;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_57;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_58;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_59;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_60;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_61;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_62;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_63;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_64;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_65;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_66;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_67;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_68;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_69;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_70;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_71;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_72;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_73;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_74;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_75;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_76;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_77;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_78;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_79;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_80;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_81;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_82;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_83;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_84;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_85;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_86;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_87;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_88;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_89;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_90;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_91;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_92;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_93;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_94;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_95;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_96;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_97;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_98;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_99;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_100;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_101;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_102;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_103;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_104;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_105;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_106;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_107;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_108;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_109;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_110;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_111;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_112;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_113;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_114;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_115;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_116;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_117;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_118;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_119;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_120;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_121;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_122;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_123;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_124;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_125;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_126;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_127;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_128;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_129;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_130;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_131;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_132;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_133;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_134;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_135;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_136;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_137;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_138;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_139;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_140;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_141;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_142;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_143;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_144;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_145;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_146;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_147;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_148;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_149;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_150;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_151;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_152;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_153;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_154;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_155;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_156;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_157;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_158;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_159;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_160;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_161;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_162;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_163;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_164;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_165;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_166;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_167;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_168;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_169;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_170;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_171;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_172;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_173;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_174;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_175;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_176;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_177;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_178;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_179;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_180;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_181;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_182;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_183;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_184;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_185;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_186;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_187;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_188;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_189;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_190;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_191;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_192;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_193;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_194;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_195;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_196;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_197;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_198;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_199;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_200;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_201;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_202;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_203;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_204;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_205;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_206;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_207;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_208;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_209;
		static ::ISPA_STD::DFAAPI::MultiTableState<Tokens, Token, 2> dfa_state_210;
		static ::ISPA_STD::DFAAPI::MultiTableState<Tokens, Token, 2> dfa_state_211;
		static ::ISPA_STD::DFAAPI::CharTableState<Tokens, Token, 1> dfa_state_212;
		static ::ISPA_STD::DFAAPI::MultiTableState<Tokens, Token, 3> dfa_state_213;
		static ::ISPA_STD::DFAAPI::CharTableState<Tokens, Token, 1> dfa_state_214;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_215;
		static ::ISPA_STD::DFAAPI::CharTableState<Tokens, Token, 1> dfa_state_216;
		static ::ISPA_STD::DFAAPI::MultiTableState<Tokens, Token, 2> dfa_state_217;
		static ::ISPA_STD::DFAAPI::MultiTableState<Tokens, Token, 2> dfa_state_218;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_219;
		static ::ISPA_STD::DFAAPI::CharTableState<Tokens, Token, 1> dfa_state_220;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_221;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_222;
		static ::ISPA_STD::DFAAPI::CharTableState<Tokens, Token, 1> dfa_state_223;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_224;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_225;
		static ::ISPA_STD::DFAAPI::MultiTableState<Tokens, Token, 2> dfa_state_226;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_227;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_228;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_229;
		static ::ISPA_STD::DFAAPI::MultiTableState<Tokens, Token, 2> dfa_state_230;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_231;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_232;
		static ::ISPA_STD::DFAAPI::MultiTableState<Tokens, Token, 2> dfa_state_233;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_234;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_235;
		static ::ISPA_STD::DFAAPI::CharTableState<Tokens, Token, 1> dfa_state_236;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_237;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_238;
		static ::ISPA_STD::DFAAPI::CharTableState<Tokens, Token, 1> dfa_state_239;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_240;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_241;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_242;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_243;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_244;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_245;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_246;
		static ::ISPA_STD::DFAAPI::CharTableState<Tokens, Token, 1> dfa_state_247;
		static ::ISPA_STD::DFAAPI::CharTableState<Tokens, Token, 1> dfa_state_248;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_249;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_250;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_251;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_252;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_253;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_254;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_255;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_256;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_257;
		static ::ISPA_STD::DFAAPI::CharTableState<Tokens, Token, 2> dfa_state_258;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_259;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_260;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_261;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_262;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_263;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_264;
		static ::ISPA_STD::DFAAPI::CharTableState<Tokens, Token, 2> dfa_state_265;
		static ::ISPA_STD::DFAAPI::CharTableState<Tokens, Token, 2> dfa_state_266;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_267;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_268;
		static ::ISPA_STD::DFAAPI::CharTableState<Tokens, Token, 2> dfa_state_269;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_270;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_271;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_272;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_273;
		static ::ISPA_STD::DFAAPI::CharTableState<Tokens, Token, 2> dfa_state_274;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_275;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_276;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_277;
		static ::ISPA_STD::DFAAPI::CharTableState<Tokens, Token, 2> dfa_state_278;
		static ::ISPA_STD::DFAAPI::CharTableState<Tokens, Token, 2> dfa_state_279;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_280;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_281;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_282;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_283;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_284;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_285;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_286;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_287;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_288;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_289;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_290;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_291;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_292;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_293;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_294;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_295;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_296;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_297;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_298;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_299;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_300;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_301;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_302;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_303;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_304;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_305;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_306;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_307;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_308;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_309;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_310;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_311;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_312;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_313;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_314;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_315;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_316;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_317;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_318;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_319;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_320;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_321;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_322;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_323;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_324;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_325;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_326;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_327;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_328;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_329;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_330;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_331;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_332;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_333;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_334;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_335;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_336;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_337;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_338;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_339;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_340;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_341;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_342;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_343;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_344;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_345;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_346;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_347;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_348;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_349;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_350;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_351;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_352;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_353;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_354;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_355;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_356;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_357;
		static ::ISPA_STD::DFAAPI::CharTableState<Tokens, Token, 1> dfa_state_358;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_359;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_360;
		static ::ISPA_STD::DFAAPI::CharTableState<Tokens, Token, 1> dfa_state_361;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_362;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_363;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_364;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_365;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_366;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_367;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_368;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_369;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_370;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_371;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_372;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_373;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_374;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_375;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_376;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_377;
		static ::ISPA_STD::DFAAPI::CharTableState<Tokens, Token, 2> dfa_state_378;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_379;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_380;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_381;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_382;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_383;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_384;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_385;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_386;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_387;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_388;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_389;
		static ::ISPA_STD::DFAAPI::CharTableState<Tokens, Token, 2> dfa_state_390;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_391;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_392;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_393;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_394;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_395;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_396;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_397;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_398;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_399;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_400;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_401;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_402;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_403;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_404;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_405;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_406;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_407;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_408;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_409;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_410;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_411;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_412;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_413;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_414;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_415;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_416;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_417;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_418;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_419;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_420;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_421;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_422;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_423;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_424;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_425;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_426;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_427;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_428;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_429;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_430;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_431;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_432;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_433;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_434;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_435;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_436;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_437;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_438;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_439;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_440;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_441;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_442;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_443;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_444;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_445;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_446;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_447;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_448;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_449;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_450;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_451;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_452;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_453;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_454;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_455;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_456;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_457;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_458;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_459;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_460;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_461;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_462;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_463;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_464;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_465;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_466;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_467;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_468;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_469;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_470;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_471;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_472;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_473;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_474;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_475;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_476;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_477;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_478;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_479;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_480;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_481;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_482;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_483;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_484;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_485;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_486;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_487;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_488;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_489;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_490;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_491;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_492;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_493;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_494;
		static ::ISPA_STD::DFAAPI::CharTableState<Tokens, Token, 2> dfa_state_495;
		static ::ISPA_STD::DFAAPI::CharTableState<Tokens, Token, 2> dfa_state_496;
		static ::ISPA_STD::DFAAPI::CharTableState<Tokens, Token, 2> dfa_state_497;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_498;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_499;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_500;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_501;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_502;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_503;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_504;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_505;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_506;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_507;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_508;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_509;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_510;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_511;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_512;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 7> dfa_table_0;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 2> dfa_table_1;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 2> dfa_table_2;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 16> dfa_table_3;
		static ::ISPA_STD::DFAAPI::MultiTable<Tokens, Token, 9> dfa_table_4;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 6> dfa_table_5;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 7> dfa_table_6;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 7> dfa_table_7;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 2> dfa_table_8;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 2> dfa_table_9;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 16> dfa_table_10;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 30> dfa_table_11;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 2> dfa_table_12;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 32> dfa_table_13;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 2> dfa_table_14;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 20> dfa_table_15;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 10> dfa_table_16;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 2> dfa_table_17;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 2> dfa_table_18;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 7> dfa_table_19;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 7> dfa_table_20;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 7> dfa_table_21;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 2> dfa_table_22;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 2> dfa_table_23;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 6> dfa_table_24;
		static ::ISPA_STD::DFAAPI::MultiTable<Tokens, Token, 34> dfa_table_25;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 3> dfa_table_26;
		static ::ISPA_STD::DFAAPI::MultiTable<Tokens, Token, 5> dfa_table_27;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 2> dfa_table_28;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 5> dfa_table_29;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 2> dfa_table_30;
		static ::ISPA_STD::DFAAPI::MultiTable<Tokens, Token, 24> dfa_table_31;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 6> dfa_table_32;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 7> dfa_table_33;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 12> dfa_table_34;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 17> dfa_table_35;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 15> dfa_table_36;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 14> dfa_table_37;
		static ::ISPA_STD::DFAAPI::MultiTable<Tokens, Token, 23> dfa_table_38;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 6> dfa_table_39;
		static ::ISPA_STD::DFAAPI::MultiTable<Tokens, Token, 13> dfa_table_40;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 6> dfa_table_41;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 7> dfa_table_42;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 38> dfa_table_43;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 15> dfa_table_44;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 11> dfa_table_45;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 7> dfa_table_46;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 13> dfa_table_47;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 2> dfa_table_48;
		static ::ISPA_STD::DFAAPI::MultiTable<Tokens, Token, 18> dfa_table_49;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 6> dfa_table_50;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 7> dfa_table_51;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 2> dfa_table_52;
		static ::ISPA_STD::FCDTTable<Tokens, Token> fcdt_table;
	public: 
		auto makeToken(const char*& pos) -> Token override		{
			return fcdt_lookup(fcdt_table, pos);
		}
	};
	class Parser : public ::ISPA_STD::LLParser_base<Tokens, Rules, Types::main, Token> {
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_0;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_1;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_2;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_3;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_4;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_5;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_6;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_7;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_8;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_9;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_10;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_11;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_12;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_13;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_14;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_15;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_16;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_17;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_18;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_19;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_20;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_21;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_22;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_23;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_24;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_25;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_26;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_27;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_28;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_29;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_30;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_31;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_32;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_33;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_34;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_35;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_36;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_37;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_38;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_39;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_40;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_41;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_42;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_43;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_44;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_45;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_46;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_47;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_48;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_49;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_50;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_51;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_52;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_53;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_54;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_55;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_56;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_57;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_58;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_59;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_60;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_61;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_62;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_63;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_64;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_65;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_66;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_67;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_68;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_69;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_70;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_71;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_72;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_73;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_74;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_75;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_76;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_77;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_78;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_79;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_80;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_81;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_82;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_83;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_84;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_85;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_86;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_87;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_88;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_89;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_90;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_91;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_92;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_93;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_94;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_95;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_96;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_97;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_98;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_99;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_100;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_101;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_102;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_103;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_104;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_105;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_106;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_107;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_108;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_109;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_110;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_111;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_112;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_113;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_114;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_115;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_116;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_117;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_118;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_119;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_120;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_121;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_122;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_123;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_124;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_125;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_126;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_127;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_128;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_129;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_130;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_131;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_132;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_133;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_134;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_135;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_136;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_137;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_138;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_139;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_140;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_141;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_142;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_143;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_144;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_145;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_146;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_147;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_148;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_149;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_150;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_151;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_152;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_153;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_154;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_155;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_156;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_157;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_158;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_159;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_160;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_161;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_162;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_163;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_164;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_165;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_166;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_167;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_168;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_169;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_170;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_171;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_172;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_173;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_174;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_175;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_176;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_177;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_178;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_179;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_180;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_181;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_182;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_183;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_184;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_185;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_186;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_187;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_188;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_189;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_190;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_191;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_192;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_193;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_194;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_195;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_196;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_197;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_198;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_199;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_200;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_201;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_202;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_203;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_204;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_205;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_206;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_207;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_208;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_209;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_210;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_211;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_212;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_213;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_214;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_215;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_216;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_217;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_218;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_219;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_220;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_221;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_222;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_223;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_224;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_225;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_226;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_227;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_228;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_229;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_230;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_231;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_232;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_233;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_234;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_235;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_236;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_237;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_238;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_239;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_240;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_241;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_242;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_243;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_244;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_245;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_246;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_247;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_248;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_249;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_250;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_251;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_252;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_253;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_254;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_255;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_256;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_257;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_258;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_259;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_260;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_261;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_262;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_263;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_264;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_265;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_266;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_267;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_268;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_269;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_270;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_271;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_272;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_273;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_274;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_275;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_276;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_277;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_278;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_279;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_280;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_281;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_282;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_283;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_284;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_285;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_286;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_287;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_288;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_289;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_290;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_291;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_292;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_293;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_294;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_295;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_296;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_297;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_298;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_299;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_300;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_301;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_302;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_303;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_304;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_305;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_306;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_307;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_308;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_309;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_310;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_311;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_312;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_313;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_314;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_315;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_316;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_317;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_318;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_319;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_320;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_321;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_322;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_323;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_324;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_325;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_326;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_327;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_328;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_329;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_330;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_331;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_332;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_333;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_334;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_335;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_336;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_337;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_338;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_339;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_340;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_341;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_342;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_343;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_344;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_345;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_346;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_347;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_348;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_349;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_350;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_351;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_352;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_353;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_354;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_355;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_356;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_357;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_358;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_359;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_360;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_361;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_362;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_363;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_364;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_365;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_366;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_367;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_368;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_369;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_370;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_371;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_372;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_373;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_374;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_375;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_376;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_377;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_378;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_379;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_380;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_381;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_382;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_383;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_384;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_385;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_386;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_387;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_388;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_389;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_390;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_391;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_392;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_393;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_394;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_395;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_396;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_397;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_398;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_399;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_400;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_401;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_402;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_403;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_404;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_405;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_406;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_407;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_408;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_409;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_410;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_411;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_412;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_413;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_414;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_415;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_416;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_417;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_418;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_419;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_420;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_421;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_422;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_423;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_424;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_425;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_426;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_427;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_428;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_429;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_430;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_431;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_432;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_433;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_434;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_435;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_436;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_437;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_438;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_439;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_440;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_441;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_442;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_443;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_444;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_445;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_446;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_447;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_448;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_449;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_450;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_451;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_452;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_453;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_454;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_455;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_456;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_457;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_458;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_459;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_460;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_461;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_462;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_463;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_464;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_465;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_466;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_467;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_468;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_469;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_470;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_471;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_472;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_473;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_474;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_475;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_476;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_477;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_478;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_479;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_480;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_481;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_482;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_483;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_484;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_485;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_486;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_487;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_488;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_489;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_490;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_491;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_492;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_493;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_494;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_495;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_496;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_497;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_498;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_499;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_500;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_501;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_502;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_503;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_504;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_505;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_506;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_507;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_508;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_509;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_510;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_511;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_512;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_513;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_514;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_515;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_516;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_517;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_518;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_519;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_520;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_521;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_522;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_523;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_524;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_525;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_526;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_527;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_528;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_529;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_530;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_531;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_532;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_533;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_534;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_535;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_536;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_537;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_538;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_539;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_540;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_541;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_542;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_543;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_544;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_545;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_546;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_547;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_548;
		static ::ISPA_STD::DFAAPI::TokenTableState<Tokens, 62> dfa_state_549;
		static ::ISPA_STD::DFAAPI::TokenTable<Tokens, 48> dfa_table_0;
		static ::ISPA_STD::DFAAPI::TokenTable<Tokens, 4> dfa_table_1;
		static ::ISPA_STD::DFAAPI::TokenTable<Tokens, 5> dfa_table_2;
		static ::ISPA_STD::DFAAPI::TokenTable<Tokens, 3> dfa_table_3;
		static ::ISPA_STD::DFAAPI::TokenTable<Tokens, 7> dfa_table_4;
		static ::ISPA_STD::DFAAPI::TokenTable<Tokens, 158> dfa_table_5;
		static ::ISPA_STD::DFAAPI::TokenTable<Tokens, 7> dfa_table_6;
		static ::ISPA_STD::DFAAPI::TokenTable<Tokens, 10> dfa_table_7;
		static ::ISPA_STD::DFAAPI::TokenTable<Tokens, 54> dfa_table_8;
		static ::ISPA_STD::DFAAPI::TokenTable<Tokens, 3> dfa_table_9;
		static ::ISPA_STD::DFAAPI::TokenTable<Tokens, 3> dfa_table_10;
		static ::ISPA_STD::DFAAPI::TokenTable<Tokens, 3> dfa_table_11;
		static ::ISPA_STD::DFAAPI::TokenTable<Tokens, 3> dfa_table_12;
		static ::ISPA_STD::DFAAPI::TokenTable<Tokens, 5> dfa_table_13;
		static ::ISPA_STD::DFAAPI::TokenTable<Tokens, 57> dfa_table_14;
		static ::ISPA_STD::DFAAPI::TokenTable<Tokens, 4> dfa_table_15;
		static ::ISPA_STD::DFAAPI::TokenTable<Tokens, 171> dfa_table_16;
		static ::ISPA_STD::DFAAPI::TokenTable<Tokens, 3> dfa_table_17;
		static ::ISPA_STD::DFAAPI::TokenTable<Tokens, 3> dfa_table_18;
		template<typename IT>
		auto cll_expr_value(IT pos) -> Types::cll::expr::value		{
			std::variant<std::monostate, ::ISPA_STD::Node<Rules, Types::rvalue>, ::ISPA_STD::Node<Rules, Types::cll::method_call>, ::ISPA_STD::Node<Rules, Types::cll::expr::group>, ::ISPA_STD::Node<Rules, Types::cll::function_call>, ::ISPA_STD::Node<Rules, Types::cll::_variable>> _0;
			bool success_1;
			int dfa_lookup_result_2;
			success_1 = true;
			dfa_lookup_result_2 = ::ISPA_STD::DFA::decide(dfa_table_0, pos, &Parser::PANIC_MODE);
			switch (dfa_lookup_result_2) {
				case 0: {
					_0 = cll__variable(pos);
					break;
				}
				case 1: {
					_0 = cll_expr_group(pos);
					break;
				}
				case 2: {
					_0 = cll_method_call(pos);
					break;
				}
				case 3: {
					_0 = cll_function_call(pos);
					break;
				}
				case 4: {
					_0 = rvalue(pos);
					break;
				}
			}
			skip_spaces(pos);
			Types::cll::expr::value result;
			result.value = _0;
			return result;
		}
		template<typename IT>
		auto cll_function_arguments(IT pos) -> Types::cll::function_arguments		{
			::ISPA_STD::MatchResult<Rules, Types::cll::expr> cll_expr_0;
			bool success_1;
			bool success_8;
			bool success_5;
			bool success_3;
			::ISPA_STD::Node<Tokens, Types::AUTO_2> AUTO_2_4;
			std::vector<::ISPA_STD::Node<Tokens, Types::AUTO_2>> shadow_6;
			::ISPA_STD::MatchResult<Rules, Types::cll::expr> cll_expr_7;
			std::vector<::ISPA_STD::MatchResult<Rules, Types::cll::expr>> shadow_9;
			success_1 = false;
			cll_expr_0 = cll_expr(pos);
			if (!(cll_expr_0.status)) {
				return ;
			}
			success_1 = true;
			pos++;
			skip_spaces(pos);
			success_3 = false;
			auto begin_10 = pos;
			while (true) {
				if (!(*begin_10 == Tokens::AUTO_2)) {
					[Error];
					break;
				}
				AUTO_2_4 = *begin_10;
				success_5 = true;
				begin_10++;
				shadow_6.push_back(AUTO_2_4);
				skip_spaces(begin_10);
				cll_expr_7 = cll_expr(begin_10);
				if (!(cll_expr_7.status)) {
					break;
				}
				success_8 = true;
				begin_10++;
				shadow_9.push_back(cll_expr_7);
			}
			if (success_5 && success_8) {
				success_3 = true;
				pos = begin_10;
			}
			skip_spaces(pos);
			Types::cll::function_arguments result;
			result.first = cll_expr_0;
			result.second = shadow_9;
			return result;
		}
		template<typename IT>
		auto cll_method_call(IT pos) -> Types::cll::method_call		{
			::ISPA_STD::Node<Tokens, Types::ID> ID_0;
			bool success_1;
			::ISPA_STD::Node<Tokens, Types::DOT> DOT_2;
			bool success_3;
			::ISPA_STD::MatchResult<Rules, Types::cll::function_call> cll_function_call_4;
			bool success_5;
			success_1 = false;
			if (!(*pos == Tokens::ID)) {
				return ;
			}
			ID_0 = *pos;
			success_1 = true;
			pos++;
			skip_spaces(pos);
			success_3 = false;
			if (!(*pos == Tokens::DOT)) {
				[Error];
				return ;
			}
			DOT_2 = *pos;
			success_3 = true;
			pos++;
			skip_spaces(pos);
			success_5 = false;
			cll_function_call_4 = cll_function_call(pos);
			if (!(cll_function_call_4.status)) {
				return ;
			}
			success_5 = true;
			pos++;
			skip_spaces(pos);
			Types::cll::method_call result;
			result.name = ID_0;
			result.body = cll_function_call_4;
			return result;
		}
		template<typename IT>
		auto moduleImport_from(IT pos) -> Types::moduleImport::from		{
			std::variant<std::monostate, ::ISPA_STD::Node<Rules, Types::moduleImport::from::import_list>, ::ISPA_STD::Node<Tokens, Types::MULTIPLE>> _0;
			bool success_1;
			int dfa_lookup_result_2;
			::ISPA_STD::Node<Tokens, Types::AUTO_9> AUTO_9_3;
			bool success_4;
			::ISPA_STD::Node<Tokens, Types::ID> ID_5;
			bool success_6;
			success_1 = true;
			dfa_lookup_result_2 = ::ISPA_STD::DFA::decide(dfa_table_1, pos, &Parser::PANIC_MODE);
			switch (dfa_lookup_result_2) {
				case 0: {
					_0 = *pos;
					break;
				}
				case 1: {
					_0 = moduleImport_from_import_list(pos);
					break;
				}
			}
			skip_spaces(pos);
			success_4 = false;
			if (!(*pos == Tokens::AUTO_9)) {
				[Error];
				return ;
			}
			AUTO_9_3 = *pos;
			success_4 = true;
			pos++;
			skip_spaces(pos);
			success_6 = false;
			if (!(*pos == Tokens::ID)) {
				[Error];
				return ;
			}
			ID_5 = *pos;
			success_6 = true;
			pos++;
			skip_spaces(pos);
			Types::moduleImport::from result;
			result.what = _0;
			result.from = ID_5;
			return result;
		}
		template<typename IT>
		auto cll_function_parameters(IT pos) -> Types::cll::function_parameters		{
			::ISPA_STD::Node<Tokens, Types::ID> ID_0;
			bool success_1;
			bool success_8;
			bool success_5;
			bool success_3;
			::ISPA_STD::Node<Tokens, Types::AUTO_2> AUTO_2_4;
			std::vector<::ISPA_STD::Node<Tokens, Types::AUTO_2>> shadow_6;
			::ISPA_STD::Node<Tokens, Types::ID> ID_7;
			std::vector<::ISPA_STD::Node<Tokens, Types::ID>> shadow_9;
			success_1 = false;
			if (!(*pos == Tokens::ID)) {
				return ;
			}
			ID_0 = *pos;
			success_1 = true;
			pos++;
			skip_spaces(pos);
			success_3 = false;
			auto begin_10 = pos;
			while (true) {
				if (!(*begin_10 == Tokens::AUTO_2)) {
					[Error];
					break;
				}
				AUTO_2_4 = *begin_10;
				success_5 = true;
				begin_10++;
				shadow_6.push_back(AUTO_2_4);
				skip_spaces(begin_10);
				if (!(*begin_10 == Tokens::ID)) {
					[Error];
					break;
				}
				ID_7 = *begin_10;
				success_8 = true;
				begin_10++;
				shadow_9.push_back(ID_7);
			}
			if (success_5 && success_8) {
				success_3 = true;
				pos = begin_10;
			}
			skip_spaces(pos);
			Types::cll::function_parameters result;
			result.first = ID_0;
			result.second = shadow_9;
			return result;
		}
		template<typename IT>
		auto rule_quantifier(IT pos) -> Types::rule::quantifier		{
			std::variant<std::monostate, ::ISPA_STD::Node<Tokens, Types::MULTIPLE>, ::ISPA_STD::Node<Tokens, Types::PLUS>, ::ISPA_STD::Node<Tokens, Types::QUESTION_MARK>> _0;
			bool success_1;
			int dfa_lookup_result_2;
			success_1 = true;
			dfa_lookup_result_2 = ::ISPA_STD::DFA::decide(dfa_table_2, pos, &Parser::PANIC_MODE);
			switch (dfa_lookup_result_2) {
				case 0: {
					_0 = *pos;
					break;
				}
				case 1: {
					_0 = *pos;
					break;
				}
				case 2: {
					_0 = *pos;
					break;
				}
			}
			skip_spaces(pos);
			Types::rule::quantifier result;
			result.value = _0;
			return result;
		}
		template<typename IT>
		auto rule_data_block_regular_datablock_key(IT pos) -> Types::rule::data_block::regular_datablock::key		{
			::ISPA_STD::Node<Tokens, Types::ID> ID_0;
			bool success_1;
			::ISPA_STD::Node<Tokens, Types::AUTO_0> AUTO_0_2;
			bool success_3;
			::ISPA_STD::MatchResult<Rules, Types::cll::expr> cll_expr_4;
			bool success_5;
			success_1 = false;
			if (!(*pos == Tokens::ID)) {
				return ;
			}
			ID_0 = *pos;
			success_1 = true;
			pos++;
			skip_spaces(pos);
			success_3 = false;
			if (!(*pos == Tokens::AUTO_0)) {
				[Error];
				return ;
			}
			AUTO_0_2 = *pos;
			success_3 = true;
			pos++;
			skip_spaces(pos);
			success_5 = false;
			cll_expr_4 = cll_expr(pos);
			if (!(cll_expr_4.status)) {
				return ;
			}
			success_5 = true;
			pos++;
			skip_spaces(pos);
			Types::rule::data_block::regular_datablock::key result;
			result.name = ID_0;
			result.dt = cll_expr_4;
			return result;
		}
		template<typename IT>
		auto rule_data_block_templated_datablock(IT pos) -> Types::rule::data_block::templated_datablock		{
			::ISPA_STD::Node<Tokens, Types::AT> AT_0;
			bool success_1;
			::ISPA_STD::Node<Tokens, Types::AUTO_1> AUTO_1_2;
			bool success_3;
			bool success_14;
			bool success_11;
			bool success_7;
			bool success_5;
			::ISPA_STD::Node<Tokens, Types::ID> ID_6;
			bool success_9;
			::ISPA_STD::Node<Tokens, Types::AUTO_2> AUTO_2_10;
			std::vector<::ISPA_STD::Node<Tokens, Types::AUTO_2>> shadow_12;
			::ISPA_STD::Node<Tokens, Types::ID> ID_13;
			std::vector<::ISPA_STD::Node<Tokens, Types::ID>> shadow_15;
			::ISPA_STD::Node<Tokens, Types::AUTO_3> AUTO_3_18;
			bool success_19;
			success_1 = false;
			if (!(*pos == Tokens::AT)) {
				return ;
			}
			AT_0 = *pos;
			success_1 = true;
			pos++;
			skip_spaces(pos);
			success_3 = false;
			if (!(*pos == Tokens::AUTO_1)) {
				[Error];
				return ;
			}
			AUTO_1_2 = *pos;
			success_3 = true;
			pos++;
			skip_spaces(pos);
			success_5 = false;
			auto begin_17 = pos;
			while (true) {
				if (!(*begin_17 == Tokens::ID)) {
					[Error];
					break;
				}
				ID_6 = *begin_17;
				success_7 = true;
				begin_17++;
				skip_spaces(begin_17);
				success_9 = false;
				auto begin_16 = begin_17;
				while (true) {
					if (!(*begin_16 == Tokens::AUTO_2)) {
						[Error];
						break;
					}
					AUTO_2_10 = *begin_16;
					success_11 = true;
					begin_16++;
					shadow_12.push_back(AUTO_2_10);
					skip_spaces(begin_16);
					if (!(*begin_16 == Tokens::ID)) {
						[Error];
						break;
					}
					ID_13 = *begin_16;
					success_14 = true;
					begin_16++;
					shadow_15.push_back(ID_13);
				}
				if (success_11 && success_14) {
					success_9 = true;
					begin_17 = begin_16;
				}
			}
			if (success_7 && success_11 && success_14) {
				success_5 = true;
				pos = begin_17;
			}
			skip_spaces(pos);
			success_19 = false;
			if (!(*pos == Tokens::AUTO_3)) {
				[Error];
				return ;
			}
			AUTO_3_18 = *pos;
			success_19 = true;
			pos++;
			skip_spaces(pos);
			Types::rule::data_block::templated_datablock result;
			result.first_name = ID_6;
			result.second_name = shadow_15;
			return result;
		}
		template<typename IT>
		auto rule_data_block_regular_datablock(IT pos) -> Types::rule::data_block::regular_datablock		{
			::ISPA_STD::Node<Tokens, Types::AUTO_1> AUTO_1_0;
			bool success_1;
			std::variant<std::monostate, ::ISPA_STD::Node<Rules, Types::rule::data_block::regular_datablock::key>, ::ISPA_STD::Node<Rules, Types::cll::expr>> _2;
			bool success_3;
			int dfa_lookup_result_4;
			::ISPA_STD::Node<Tokens, Types::AUTO_3> AUTO_3_5;
			bool success_6;
			success_1 = false;
			if (!(*pos == Tokens::AUTO_1)) {
				return ;
			}
			AUTO_1_0 = *pos;
			success_1 = true;
			pos++;
			skip_spaces(pos);
			success_3 = true;
			dfa_lookup_result_4 = ::ISPA_STD::DFA::decide(dfa_table_3, pos, &Parser::PANIC_MODE);
			switch (dfa_lookup_result_4) {
				case 0: {
					_2 = cll_expr(pos);
					break;
				}
				case 1: {
					_2 = rule_data_block_regular_datablock_key(pos);
					break;
				}
			}
			skip_spaces(pos);
			success_6 = false;
			if (!(*pos == Tokens::AUTO_3)) {
				[Error];
				return ;
			}
			AUTO_3_5 = *pos;
			success_6 = true;
			pos++;
			skip_spaces(pos);
			Types::rule::data_block::regular_datablock result;
			result.value = _2;
			return result;
		}
		template<typename IT>
		auto cll_function_body_decl(IT pos) -> Types::cll::function_body_decl		{
			::ISPA_STD::Node<Tokens, Types::AUTO_4> AUTO_4_0;
			bool success_1;
			::ISPA_STD::MatchResult<Rules, Types::cll::function_parameters> cll_function_parameters_2;
			bool success_3;
			::ISPA_STD::Node<Tokens, Types::AUTO_5> AUTO_5_4;
			bool success_5;
			success_1 = false;
			if (!(*pos == Tokens::AUTO_4)) {
				return ;
			}
			AUTO_4_0 = *pos;
			success_1 = true;
			pos++;
			skip_spaces(pos);
			success_3 = false;
			cll_function_parameters_2 = cll_function_parameters(pos);
			if (!(cll_function_parameters_2.status)) {
				return ;
			}
			success_3 = true;
			pos++;
			skip_spaces(pos);
			success_5 = false;
			if (!(*pos == Tokens::AUTO_5)) {
				[Error];
				return ;
			}
			AUTO_5_4 = *pos;
			success_5 = true;
			pos++;
			skip_spaces(pos);
			Types::cll::function_body_decl result;
			result.value = cll_function_parameters_2;
			return result;
		}
		template<typename IT>
		auto rule_group(IT pos) -> Types::rule::group		{
			::ISPA_STD::Node<Tokens, Types::AUTO_4> AUTO_4_0;
			bool success_1;
			::ISPA_STD::MatchResult<Rules, Types::rule::member> rule_member_2;
			bool success_3;
			std::vector<::ISPA_STD::MatchResult<Rules, Types::rule::member>> shadow_4;
			::ISPA_STD::Node<Tokens, Types::AUTO_5> AUTO_5_5;
			bool success_6;
			success_1 = false;
			if (!(*pos == Tokens::AUTO_4)) {
				return ;
			}
			AUTO_4_0 = *pos;
			success_1 = true;
			pos++;
			skip_spaces(pos);
			while (rule_member_2.status) {
				success_3 = false;
				rule_member_2 = rule_member(pos);
				rule_member_2 = rule_member(pos);
				shadow_4.push_back(rule_member_2);
			}
			skip_spaces(pos);
			success_6 = false;
			if (!(*pos == Tokens::AUTO_5)) {
				[Error];
				return ;
			}
			AUTO_5_5 = *pos;
			success_6 = true;
			pos++;
			skip_spaces(pos);
			Types::rule::group result;
			result.value = shadow_4;
			return result;
		}
		template<typename IT>
		auto rule_name(IT pos) -> Types::rule::name		{
			::ISPA_STD::Node<Tokens, Types::AUTO_6> AUTO_6_0;
			bool success_1;
			::ISPA_STD::Node<Tokens, Types::ID> ID_2;
			bool success_3;
			bool success_10;
			bool success_7;
			bool success_5;
			::ISPA_STD::Node<Tokens, Types::DOT> DOT_6;
			std::vector<::ISPA_STD::Node<Tokens, Types::DOT>> shadow_8;
			::ISPA_STD::Node<Tokens, Types::ID> ID_9;
			std::vector<::ISPA_STD::Node<Tokens, Types::ID>> shadow_11;
			if (*pos == Tokens::AUTO_6) {
				success_1 = false;
			}
			skip_spaces(pos);
			success_3 = false;
			if (!(*pos == Tokens::ID)) {
				[Error];
				return ;
			}
			ID_2 = *pos;
			success_3 = true;
			pos++;
			skip_spaces(pos);
			success_5 = false;
			auto begin_12 = pos;
			while (true) {
				if (!(*begin_12 == Tokens::DOT)) {
					[Error];
					break;
				}
				DOT_6 = *begin_12;
				success_7 = true;
				begin_12++;
				shadow_8.push_back(DOT_6);
				skip_spaces(begin_12);
				if (!(*begin_12 == Tokens::ID)) {
					[Error];
					break;
				}
				ID_9 = *begin_12;
				success_10 = true;
				begin_12++;
				shadow_11.push_back(ID_9);
			}
			if (success_7 && success_10) {
				success_5 = true;
				pos = begin_12;
			}
			skip_spaces(pos);
			Types::rule::name result;
			result.is_nested = AUTO_6_0;
			result.name = ID_2;
			result.nested_name = shadow_11;
			return result;
		}
		template<typename IT>
		auto rule_keyvalue(IT pos) -> Types::rule::keyvalue		{
			::ISPA_STD::Node<Tokens, Types::AT> AT_0;
			bool success_1;
			bool success_5;
			bool success_3;
			::ISPA_STD::Node<Tokens, Types::ID> ID_4;
			success_1 = false;
			if (!(*pos == Tokens::AT)) {
				return ;
			}
			AT_0 = *pos;
			success_1 = true;
			pos++;
			skip_spaces(pos);
			success_3 = false;
			auto begin_6 = pos;
			while (true) {
				if (!(*begin_6 == Tokens::ID)) {
					[Error];
					break;
				}
				ID_4 = *begin_6;
				success_5 = true;
				begin_6++;
			}
			if (success_5) {
				success_3 = true;
				pos = begin_6;
			}
			skip_spaces(pos);
			Types::rule::keyvalue result;
			result.value = ID_4;
			return result;
		}
		template<typename IT>
		auto rule_member(IT pos) -> Types::rule::member		{
			bool success_3;
			std::variant<std::monostate, ::ISPA_STD::Node<Rules, Types::rule::value>, ::ISPA_STD::Node<Rules, Types::rule::keyvalue>> group_0;
			bool success_1;
			std::variant<std::monostate, ::ISPA_STD::Node<Rules, Types::rule::value>, ::ISPA_STD::Node<Rules, Types::rule::keyvalue>> _2;
			int dfa_lookup_result_4;
			std::variant<std::monostate, ::ISPA_STD::Node<Tokens, Types::LINEAR_COMMENT>, ::ISPA_STD::Node<Tokens, Types::STRING>, ::ISPA_STD::Node<Rules, Types::rule::name>, ::ISPA_STD::Node<Rules, Types::rule::group>, ::ISPA_STD::Node<Tokens, Types::DOT>, ::ISPA_STD::Node<Tokens, Types::rule::CSEQUENCE>, ::ISPA_STD::Node<Rules, Types::cll>, ::ISPA_STD::Node<Tokens, Types::rule::ESCAPED>, ::ISPA_STD::Node<Tokens, Types::rule::HEX>, ::ISPA_STD::Node<Tokens, Types::rule::OP>, ::ISPA_STD::Node<Tokens, Types::rule::BIN>, ::ISPA_STD::Node<Tokens, Types::rule::NOSPACE>> _6;
			bool success_7;
			int dfa_lookup_result_8;
			::ISPA_STD::MatchResult<Rules, Types::rule::quantifier> rule_quantifier_9;
			bool success_10;
			group_0 = _2;
			success_1 = false;
			auto begin_5 = pos;
			while (true) {
				dfa_lookup_result_4 = ::ISPA_STD::DFA::decide(dfa_table_4, pos, &Parser::PANIC_MODE);
				switch (dfa_lookup_result_4) {
					case 0: {
						_2 = rule_keyvalue(begin_5);
						break;
					}
					case 1: {
						_2 = rule_value(begin_5);
						break;
					}
				}
			}
			if (success_3) {
				success_1 = true;
				pos = begin_5;
			}
			skip_spaces(pos);
			success_7 = true;
			dfa_lookup_result_8 = ::ISPA_STD::DFA::decide(dfa_table_5, pos, &Parser::PANIC_MODE);
			switch (dfa_lookup_result_8) {
				case 0: {
					_6 = *pos;
					break;
				}
				case 1: {
					_6 = *pos;
					break;
				}
				case 2: {
					_6 = *pos;
					break;
				}
				case 3: {
					_6 = *pos;
					break;
				}
				case 4: {
					_6 = *pos;
					break;
				}
				case 5: {
					_6 = *pos;
					break;
				}
				case 6: {
					_6 = *pos;
					break;
				}
				case 7: {
					_6 = *pos;
					break;
				}
				case 8: {
					_6 = rule_group(pos);
					break;
				}
				case 9: {
					_6 = *pos;
					break;
				}
				case 10: {
					_6 = cll(pos);
					break;
				}
				case 11: {
					_6 = rule_name(pos);
					break;
				}
			}
			skip_spaces(pos);
			if (rule_quantifier_9.status) {
				success_10 = false;
				rule_quantifier_9 = rule_quantifier(pos);
			}
			skip_spaces(pos);
			Types::rule::member result;
			result.prefix = group_0;
			result.val = _6;
			result.quantifier = rule_quantifier_9;
			return result;
		}
		template<typename IT>
		auto rule(IT pos) -> Types::rule		{
			::ISPA_STD::Node<Tokens, Types::ID> ID_0;
			bool success_1;
			::ISPA_STD::Node<Tokens, Types::AUTO_7> AUTO_7_2;
			bool success_3;
			bool success_7;
			::ISPA_STD::MatchResult<Rules, Types::rule::member> rule_member_4;
			bool success_5;
			std::vector<::ISPA_STD::MatchResult<Rules, Types::rule::member>> shadow_6;
			::ISPA_STD::MatchResult<Rules, Types::rule::data_block> rule_data_block_8;
			bool success_9;
			::ISPA_STD::MatchResult<Rules, Types::rule::nested_rule> rule_nested_rule_10;
			bool success_11;
			std::vector<::ISPA_STD::MatchResult<Rules, Types::rule::nested_rule>> shadow_12;
			::ISPA_STD::Node<Tokens, Types::AUTO_8> AUTO_8_13;
			bool success_14;
			success_1 = false;
			if (!(*pos == Tokens::ID)) {
				return ;
			}
			ID_0 = *pos;
			success_1 = true;
			pos++;
			skip_spaces(pos);
			success_3 = false;
			if (!(*pos == Tokens::AUTO_7)) {
				[Error];
				return ;
			}
			AUTO_7_2 = *pos;
			success_3 = true;
			pos++;
			skip_spaces(pos);
			success_7 = false;
			while (rule_member_4.status) {
				success_5 = false;
				rule_member_4 = rule_member(pos);
				rule_member_4 = rule_member(pos);
				shadow_6.push_back(rule_member_4);
				success_7 = true;
			}
			if (!success_7) {
				[Error];
				return ;
			}
			skip_spaces(pos);
			if (rule_data_block_8.status) {
				success_9 = false;
				rule_data_block_8 = rule_data_block(pos);
			}
			skip_spaces(pos);
			while (rule_nested_rule_10.status) {
				success_11 = false;
				rule_nested_rule_10 = rule_nested_rule(pos);
				rule_nested_rule_10 = rule_nested_rule(pos);
				shadow_12.push_back(rule_nested_rule_10);
			}
			skip_spaces(pos);
			success_14 = false;
			if (!(*pos == Tokens::AUTO_8)) {
				[Error];
				return ;
			}
			AUTO_8_13 = *pos;
			success_14 = true;
			pos++;
			skip_spaces(pos);
			Types::rule result;
			result.name = ID_0;
			result.rule = shadow_6;
			result.data_block = rule_data_block_8;
			result.nested_rules = shadow_12;
			return result;
		}
		template<typename IT>
		auto _use_unit(IT pos) -> Types::_use::unit		{
			::ISPA_STD::Node<Tokens, Types::ID> ID_0;
			bool success_1;
			::ISPA_STD::MatchResult<Rules, Types::rvalue> rvalue_2;
			bool success_3;
			success_1 = false;
			if (!(*pos == Tokens::ID)) {
				return ;
			}
			ID_0 = *pos;
			success_1 = true;
			pos++;
			skip_spaces(pos);
			if (rvalue_2.status) {
				success_3 = false;
				rvalue_2 = rvalue(pos);
			}
			skip_spaces(pos);
			Types::_use::unit result;
			result.name = ID_0;
			result.value = rvalue_2;
			return result;
		}
		template<typename IT>
		auto main(IT pos) -> Types::main		{
			bool success_3;
			std::variant<std::monostate, ::ISPA_STD::Node<Rules, Types::rule>, ::ISPA_STD::Node<Rules, Types::_use>, ::ISPA_STD::Node<Tokens, Types::NAME>, ::ISPA_STD::Node<Tokens, Types::SPACEMODE>> group_0;
			bool success_1;
			bool success_7;
			std::variant<std::monostate, ::ISPA_STD::Node<Rules, Types::rule>, ::ISPA_STD::Node<Rules, Types::_use>, ::ISPA_STD::Node<Tokens, Types::NAME>, ::ISPA_STD::Node<Tokens, Types::SPACEMODE>> _2;
			int dfa_lookup_result_4;
			std::vector<std::variant<std::monostate, ::ISPA_STD::Node<Rules, Types::rule>, ::ISPA_STD::Node<Rules, Types::_use>, ::ISPA_STD::Node<Tokens, Types::NAME>, ::ISPA_STD::Node<Tokens, Types::SPACEMODE>>> shadow_6;
			group_0 = _2;
			success_1 = false;
			auto begin_5 = pos;
			success_7 = false;
			while (true) {
				dfa_lookup_result_4 = ::ISPA_STD::DFA::decide(dfa_table_6, pos, &Parser::PANIC_MODE);
				switch (dfa_lookup_result_4) {
					case 0: {
						_2 = *begin_5;
						break;
					}
					case 1: {
						_2 = *begin_5;
						break;
					}
					case 2: {
						_2 = _use(begin_5);
						break;
					}
					case 3: {
						_2 = rule(begin_5);
						break;
					}
				}
				success_7 = true;
			}
			if (!success_7) {
				[Error];
				return ;
			}
			if (success_3) {
				success_1 = true;
				pos = begin_5;
				shadow_6.push_back(group_0);
			}
			skip_spaces(pos);
			Types::main result;
			result.value = _2;
			return result;
		}
		template<typename IT>
		auto moduleImport_from_import_list(IT pos) -> Types::moduleImport::from::import_list		{
			::ISPA_STD::Node<Tokens, Types::ID> ID_0;
			bool success_1;
			bool success_8;
			bool success_5;
			bool success_3;
			::ISPA_STD::Node<Tokens, Types::AUTO_2> AUTO_2_4;
			std::vector<::ISPA_STD::Node<Tokens, Types::AUTO_2>> shadow_6;
			::ISPA_STD::Node<Tokens, Types::ID> ID_7;
			std::vector<::ISPA_STD::Node<Tokens, Types::ID>> shadow_9;
			success_1 = false;
			if (!(*pos == Tokens::ID)) {
				return ;
			}
			ID_0 = *pos;
			success_1 = true;
			pos++;
			skip_spaces(pos);
			success_3 = false;
			auto begin_10 = pos;
			while (true) {
				if (!(*begin_10 == Tokens::AUTO_2)) {
					[Error];
					break;
				}
				AUTO_2_4 = *begin_10;
				success_5 = true;
				begin_10++;
				shadow_6.push_back(AUTO_2_4);
				skip_spaces(begin_10);
				if (!(*begin_10 == Tokens::ID)) {
					[Error];
					break;
				}
				ID_7 = *begin_10;
				success_8 = true;
				begin_10++;
				shadow_9.push_back(ID_7);
			}
			if (success_5 && success_8) {
				success_3 = true;
				pos = begin_10;
			}
			skip_spaces(pos);
			Types::moduleImport::from::import_list result;
			result.first = ID_0;
			result.sequence = shadow_9;
			return result;
		}
		template<typename IT>
		auto cll_type(IT pos) -> Types::cll::type		{
			std::variant<std::monostate, ::ISPA_STD::Node<Tokens, Types::AUTO_14>, Undef, ::ISPA_STD::Node<Tokens, Types::AUTO_11>, ::ISPA_STD::Node<Tokens, Types::AUTO_12>, ::ISPA_STD::Node<Tokens, Types::AUTO_10>> _0;
			bool success_1;
			int dfa_lookup_result_2;
			success_1 = true;
			dfa_lookup_result_2 = ::ISPA_STD::DFA::decide(dfa_table_7, pos, &Parser::PANIC_MODE);
			switch (dfa_lookup_result_2) {
				case 0: {
					_0 = *pos;
					break;
				}
				case 1: {
					_0 = *pos;
					break;
				}
				case 2: {
					_0 = *pos;
					break;
				}
				case 3: {
					bool success_4 = false;
					auto begin_9 = pos;
					if (success_6 && success_8) {
						success_4 = true;
						pos = begin_9;
					}
					skip_spaces(pos);
					break;
				}
				case 4: {
					_0 = *pos;
					break;
				}
				case 5: {
					bool success_11 = false;
					auto begin_16 = pos;
					if (success_13 && success_15) {
						success_11 = true;
						pos = begin_16;
					}
					skip_spaces(pos);
					break;
				}
			}
			skip_spaces(pos);
			Types::cll::type result;
			result.type = AUTO_13_5;
			result.templ = cll_templ_7;
			return result;
		}
		template<typename IT>
		auto cll_expr_compare(IT pos) -> Types::cll::expr::compare		{
			::ISPA_STD::MatchResult<Rules, Types::cll::expr::arithmetic> cll_expr_arithmetic_0;
			bool success_1;
			bool success_8;
			bool success_5;
			bool success_3;
			::ISPA_STD::Node<Tokens, Types::cll::COMPARE_OP> cll_COMPARE_OP_4;
			std::vector<::ISPA_STD::Node<Tokens, Types::cll::COMPARE_OP>> shadow_6;
			::ISPA_STD::MatchResult<Rules, Types::cll::expr::arithmetic> cll_expr_arithmetic_7;
			std::vector<::ISPA_STD::MatchResult<Rules, Types::cll::expr::arithmetic>> shadow_9;
			success_1 = false;
			cll_expr_arithmetic_0 = cll_expr_arithmetic(pos);
			if (!(cll_expr_arithmetic_0.status)) {
				return ;
			}
			success_1 = true;
			pos++;
			skip_spaces(pos);
			success_3 = false;
			auto begin_10 = pos;
			while (true) {
				if (!(*begin_10 == Tokens::cll::COMPARE_OP)) {
					[Error];
					break;
				}
				cll_COMPARE_OP_4 = *begin_10;
				success_5 = true;
				begin_10++;
				shadow_6.push_back(cll_COMPARE_OP_4);
				skip_spaces(begin_10);
				cll_expr_arithmetic_7 = cll_expr_arithmetic(begin_10);
				if (!(cll_expr_arithmetic_7.status)) {
					break;
				}
				success_8 = true;
				begin_10++;
				shadow_9.push_back(cll_expr_arithmetic_7);
			}
			if (success_5 && success_8) {
				success_3 = true;
				pos = begin_10;
			}
			skip_spaces(pos);
			Types::cll::expr::compare result;
			result.first = cll_expr_arithmetic_0;
			result.operators = shadow_6;
			result.sequence = shadow_9;
			return result;
		}
		template<typename IT>
		auto moduleDeclaration(IT pos) -> Types::moduleDeclaration		{
			::ISPA_STD::Node<Tokens, Types::AUTO_16> AUTO_16_0;
			bool success_1;
			::ISPA_STD::Node<Tokens, Types::ID> ID_2;
			bool success_3;
			bool success_9;
			bool success_7;
			bool success_5;
			::ISPA_STD::Node<Tokens, Types::AUTO_17> AUTO_17_6;
			::ISPA_STD::Node<Tokens, Types::ID> ID_8;
			::ISPA_STD::Node<Tokens, Types::AUTO_8> AUTO_8_11;
			bool success_12;
			success_1 = false;
			if (!(*pos == Tokens::AUTO_16)) {
				return ;
			}
			AUTO_16_0 = *pos;
			success_1 = true;
			pos++;
			skip_spaces(pos);
			success_3 = false;
			if (!(*pos == Tokens::ID)) {
				[Error];
				return ;
			}
			ID_2 = *pos;
			success_3 = true;
			pos++;
			skip_spaces(pos);
			success_5 = false;
			auto begin_10 = pos;
			while (true) {
				if (!(*begin_10 == Tokens::AUTO_17)) {
					[Error];
					break;
				}
				AUTO_17_6 = *begin_10;
				success_7 = true;
				begin_10++;
				skip_spaces(begin_10);
				if (!(*begin_10 == Tokens::ID)) {
					[Error];
					break;
				}
				ID_8 = *begin_10;
				success_9 = true;
				begin_10++;
			}
			if (success_7 && success_9) {
				success_5 = true;
				pos = begin_10;
			}
			skip_spaces(pos);
			success_12 = false;
			if (!(*pos == Tokens::AUTO_8)) {
				[Error];
				return ;
			}
			AUTO_8_11 = *pos;
			success_12 = true;
			pos++;
			skip_spaces(pos);
			Types::moduleDeclaration result;
			result.name = ID_2;
			result.base = ID_8;
			return result;
		}
		template<typename IT>
		auto cll_expr_group(IT pos) -> Types::cll::expr::group		{
			::ISPA_STD::Node<Tokens, Types::AUTO_4> AUTO_4_0;
			bool success_1;
			::ISPA_STD::MatchResult<Rules, Types::cll::expr> cll_expr_2;
			bool success_3;
			::ISPA_STD::Node<Tokens, Types::AUTO_5> AUTO_5_4;
			bool success_5;
			success_1 = false;
			if (!(*pos == Tokens::AUTO_4)) {
				return ;
			}
			AUTO_4_0 = *pos;
			success_1 = true;
			pos++;
			skip_spaces(pos);
			success_3 = false;
			cll_expr_2 = cll_expr(pos);
			if (!(cll_expr_2.status)) {
				return ;
			}
			success_3 = true;
			pos++;
			skip_spaces(pos);
			success_5 = false;
			if (!(*pos == Tokens::AUTO_5)) {
				[Error];
				return ;
			}
			AUTO_5_4 = *pos;
			success_5 = true;
			pos++;
			skip_spaces(pos);
			Types::cll::expr::group result;
			result.value = cll_expr_2;
			return result;
		}
		template<typename IT>
		auto array(IT pos) -> Types::array		{
			::ISPA_STD::Node<Tokens, Types::AUTO_18> AUTO_18_0;
			bool success_1;
			bool success_10;
			bool success_7;
			bool success_3;
			bool success_5;
			::ISPA_STD::MatchResult<Rules, Types::cll::expr> cll_expr_6;
			std::vector<::ISPA_STD::MatchResult<Rules, Types::cll::expr>> shadow_8;
			::ISPA_STD::Node<Tokens, Types::AUTO_2> AUTO_2_9;
			std::vector<::ISPA_STD::Node<Tokens, Types::AUTO_2>> shadow_11;
			::ISPA_STD::Node<Tokens, Types::AUTO_19> AUTO_19_14;
			bool success_15;
			success_1 = false;
			if (!(*pos == Tokens::AUTO_18)) {
				return ;
			}
			AUTO_18_0 = *pos;
			success_1 = true;
			pos++;
			skip_spaces(pos);
			success_3 = false;
			auto begin_13 = pos;
			while (true) {
				success_5 = false;
				auto begin_12 = begin_13;
				while (true) {
					cll_expr_6 = cll_expr(begin_12);
					if (!(cll_expr_6.status)) {
						break;
					}
					success_7 = true;
					begin_12++;
					shadow_8.push_back(cll_expr_6);
					skip_spaces(begin_12);
					if (!(*begin_12 == Tokens::AUTO_2)) {
						[Error];
						break;
					}
					AUTO_2_9 = *begin_12;
					success_10 = true;
					begin_12++;
					shadow_11.push_back(AUTO_2_9);
				}
				if (success_7 && success_10) {
					success_5 = true;
					begin_13 = begin_12;
				}
			}
			if (success_7 && success_10) {
				success_3 = true;
				pos = begin_13;
			}
			skip_spaces(pos);
			success_15 = false;
			if (!(*pos == Tokens::AUTO_19)) {
				[Error];
				return ;
			}
			AUTO_19_14 = *pos;
			success_15 = true;
			pos++;
			skip_spaces(pos);
			Types::array result;
			result.value = shadow_8;
			return result;
		}
		template<typename IT>
		auto rvalue(IT pos) -> Types::rvalue		{
			std::variant<std::monostate, ::ISPA_STD::Node<Tokens, Types::NUMBER>, ::ISPA_STD::Node<Tokens, Types::ID>, ::ISPA_STD::Node<Tokens, Types::AT>, ::ISPA_STD::Node<Tokens, Types::STRING>, ::ISPA_STD::Node<Rules, Types::array>, ::ISPA_STD::Node<Rules, Types::object>, ::ISPA_STD::Node<Tokens, Types::BOOLEAN>> _0;
			bool success_1;
			int dfa_lookup_result_2;
			success_1 = true;
			dfa_lookup_result_2 = ::ISPA_STD::DFA::decide(dfa_table_8, pos, &Parser::PANIC_MODE);
			switch (dfa_lookup_result_2) {
				case 0: {
					_0 = *pos;
					break;
				}
				case 1: {
					_0 = object(pos);
					break;
				}
				case 2: {
					_0 = array(pos);
					break;
				}
				case 3: {
					_0 = *pos;
					break;
				}
				case 4: {
					_0 = *pos;
					break;
				}
				case 5: {
					_0 = *pos;
					break;
				}
				case 6: {
					_0 = *pos;
					break;
				}
			}
			skip_spaces(pos);
			Types::rvalue result;
			result.value = _0;
			return result;
		}
		template<typename IT>
		auto cll__variable(IT pos) -> Types::cll::_variable		{
			bool success_3;
			std::variant<std::monostate, ::ISPA_STD::Node<Tokens, Types::AUTO_30>, ::ISPA_STD::Node<Tokens, Types::AUTO_29>> group_0;
			bool success_1;
			std::variant<std::monostate, ::ISPA_STD::Node<Tokens, Types::AUTO_30>, ::ISPA_STD::Node<Tokens, Types::AUTO_29>> _2;
			int dfa_lookup_result_4;
			::ISPA_STD::Node<Tokens, Types::ID> ID_6;
			bool success_7;
			bool success_15;
			bool success_13;
			bool success_11;
			bool success_9;
			::ISPA_STD::Node<Tokens, Types::AUTO_18> AUTO_18_10;
			::ISPA_STD::MatchResult<Rules, Types::cll::expr> cll_expr_12;
			::ISPA_STD::Node<Tokens, Types::AUTO_19> AUTO_19_14;
			bool success_20;
			std::variant<std::monostate, ::ISPA_STD::Node<Tokens, Types::AUTO_30>, ::ISPA_STD::Node<Tokens, Types::AUTO_29>> group_17;
			bool success_18;
			std::variant<std::monostate, ::ISPA_STD::Node<Tokens, Types::AUTO_30>, ::ISPA_STD::Node<Tokens, Types::AUTO_29>> _19;
			int dfa_lookup_result_21;
			group_0 = _2;
			success_1 = false;
			auto begin_5 = pos;
			while (true) {
				dfa_lookup_result_4 = ::ISPA_STD::DFA::decide(dfa_table_9, pos, &Parser::PANIC_MODE);
				switch (dfa_lookup_result_4) {
					case 0: {
						_2 = *begin_5;
						break;
					}
					case 1: {
						_2 = *begin_5;
						break;
					}
				}
			}
			if (success_3) {
				success_1 = true;
				pos = begin_5;
			}
			skip_spaces(pos);
			success_7 = false;
			if (!(*pos == Tokens::ID)) {
				[Error];
				return ;
			}
			ID_6 = *pos;
			success_7 = true;
			pos++;
			skip_spaces(pos);
			success_9 = false;
			auto begin_16 = pos;
			while (true) {
				if (!(*begin_16 == Tokens::AUTO_18)) {
					[Error];
					break;
				}
				AUTO_18_10 = *begin_16;
				success_11 = true;
				begin_16++;
				skip_spaces(begin_16);
				cll_expr_12 = cll_expr(begin_16);
				if (!(cll_expr_12.status)) {
					break;
				}
				success_13 = true;
				begin_16++;
				skip_spaces(begin_16);
				if (!(*begin_16 == Tokens::AUTO_19)) {
					[Error];
					break;
				}
				AUTO_19_14 = *begin_16;
				success_15 = true;
				begin_16++;
			}
			if (success_11 && success_13 && success_15) {
				success_9 = true;
				pos = begin_16;
			}
			skip_spaces(pos);
			group_17 = _19;
			success_18 = false;
			auto begin_22 = pos;
			while (true) {
				dfa_lookup_result_21 = ::ISPA_STD::DFA::decide(dfa_table_10, pos, &Parser::PANIC_MODE);
				switch (dfa_lookup_result_21) {
					case 0: {
						_19 = *begin_22;
						break;
					}
					case 1: {
						_19 = *begin_22;
						break;
					}
				}
			}
			if (success_20) {
				success_18 = true;
				pos = begin_22;
			}
			skip_spaces(pos);
			Types::cll::_variable result;
			result.pre = group_0;
			result.name = ID_6;
			result.brace_expression = cll_expr_12;
			result.pos = group_17;
			return result;
		}
		template<typename IT>
		auto object(IT pos) -> Types::object		{
			::ISPA_STD::Node<Tokens, Types::AUTO_1> AUTO_1_0;
			bool success_1;
			bool success_27;
			bool success_23;
			bool success_20;
			bool success_17;
			bool success_14;
			bool success_10;
			bool success_8;
			bool success_5;
			bool success_3;
			std::variant<std::monostate, ::ISPA_STD::Node<Tokens, Types::NUMBER>, ::ISPA_STD::Node<Tokens, Types::ID>> _4;
			int dfa_lookup_result_6;
			::ISPA_STD::Node<Tokens, Types::AUTO_7> AUTO_7_7;
			::ISPA_STD::MatchResult<Rules, Types::cll::expr> cll_expr_9;
			bool success_12;
			::ISPA_STD::Node<Tokens, Types::AUTO_2> AUTO_2_13;
			std::vector<::ISPA_STD::Node<Tokens, Types::AUTO_2>> shadow_15;
			std::variant<std::monostate, ::ISPA_STD::Node<Tokens, Types::NUMBER>, ::ISPA_STD::Node<Tokens, Types::ID>> _16;
			int dfa_lookup_result_18;
			::ISPA_STD::Node<Tokens, Types::AUTO_7> AUTO_7_19;
			std::vector<::ISPA_STD::Node<Tokens, Types::AUTO_7>> shadow_21;
			::ISPA_STD::MatchResult<Rules, Types::cll::expr> cll_expr_22;
			std::vector<::ISPA_STD::MatchResult<Rules, Types::cll::expr>> shadow_24;
			::ISPA_STD::Node<Tokens, Types::AUTO_8> AUTO_8_26;
			::ISPA_STD::Node<Tokens, Types::AUTO_3> AUTO_3_29;
			bool success_30;
			success_1 = false;
			if (!(*pos == Tokens::AUTO_1)) {
				return ;
			}
			AUTO_1_0 = *pos;
			success_1 = true;
			pos++;
			skip_spaces(pos);
			success_3 = false;
			auto begin_28 = pos;
			while (true) {
				dfa_lookup_result_6 = ::ISPA_STD::DFA::decide(dfa_table_11, pos, &Parser::PANIC_MODE);
				switch (dfa_lookup_result_6) {
					case 0: {
						_4 = *begin_28;
						break;
					}
					case 1: {
						_4 = *begin_28;
						break;
					}
				}
				skip_spaces(begin_28);
				if (!(*begin_28 == Tokens::AUTO_7)) {
					[Error];
					break;
				}
				AUTO_7_7 = *begin_28;
				success_8 = true;
				begin_28++;
				skip_spaces(begin_28);
				cll_expr_9 = cll_expr(begin_28);
				if (!(cll_expr_9.status)) {
					break;
				}
				success_10 = true;
				begin_28++;
				skip_spaces(begin_28);
				success_12 = false;
				auto begin_25 = begin_28;
				while (true) {
					if (!(*begin_25 == Tokens::AUTO_2)) {
						[Error];
						break;
					}
					AUTO_2_13 = *begin_25;
					success_14 = true;
					begin_25++;
					shadow_15.push_back(AUTO_2_13);
					skip_spaces(begin_25);
					dfa_lookup_result_18 = ::ISPA_STD::DFA::decide(dfa_table_12, pos, &Parser::PANIC_MODE);
					switch (dfa_lookup_result_18) {
						case 0: {
							_16 = *begin_25;
							break;
						}
						case 1: {
							_16 = *begin_25;
							break;
						}
					}
					skip_spaces(begin_25);
					if (!(*begin_25 == Tokens::AUTO_7)) {
						[Error];
						break;
					}
					AUTO_7_19 = *begin_25;
					success_20 = true;
					begin_25++;
					shadow_21.push_back(AUTO_7_19);
					skip_spaces(begin_25);
					cll_expr_22 = cll_expr(begin_25);
					if (!(cll_expr_22.status)) {
						break;
					}
					success_23 = true;
					begin_25++;
					shadow_24.push_back(cll_expr_22);
				}
				if (success_14 && success_17 && success_20 && success_23) {
					success_12 = true;
					begin_28 = begin_25;
				}
				skip_spaces(begin_28);
				if (!(*begin_28 == Tokens::AUTO_8)) {
					[Error];
					break;
				}
				AUTO_8_26 = *begin_28;
				success_27 = true;
				begin_28++;
			}
			if (success_5 && success_8 && success_10 && success_14 && success_17 && success_20 && success_23 && success_27) {
				success_3 = true;
				pos = begin_28;
			}
			skip_spaces(pos);
			success_30 = false;
			if (!(*pos == Tokens::AUTO_3)) {
				[Error];
				return ;
			}
			AUTO_3_29 = *pos;
			success_30 = true;
			pos++;
			skip_spaces(pos);
			Types::object result;
			result.key = _4;
			result.value = cll_expr_9;
			result.keys = _16;
			result.values = shadow_24;
			return result;
		}
		template<typename IT>
		auto cll_stmt(IT pos) -> Types::cll::stmt		{
			::ISPA_STD::Node<Tokens, Types::AUTO_1> AUTO_1_0;
			bool success_1;
			::ISPA_STD::MatchResult<Rules, Types::rule::member> rule_member_2;
			bool success_3;
			std::vector<::ISPA_STD::MatchResult<Rules, Types::rule::member>> shadow_4;
			::ISPA_STD::Node<Tokens, Types::AUTO_3> AUTO_3_5;
			bool success_6;
			success_1 = false;
			if (!(*pos == Tokens::AUTO_1)) {
				return ;
			}
			AUTO_1_0 = *pos;
			success_1 = true;
			pos++;
			skip_spaces(pos);
			while (rule_member_2.status) {
				success_3 = false;
				rule_member_2 = rule_member(pos);
				rule_member_2 = rule_member(pos);
				shadow_4.push_back(rule_member_2);
			}
			skip_spaces(pos);
			success_6 = false;
			if (!(*pos == Tokens::AUTO_3)) {
				[Error];
				return ;
			}
			AUTO_3_5 = *pos;
			success_6 = true;
			pos++;
			skip_spaces(pos);
			Types::cll::stmt result;
			result.value = shadow_4;
			return result;
		}
		template<typename IT>
		auto cll__var(IT pos) -> Types::cll::_var		{
			::ISPA_STD::MatchResult<Rules, Types::cll::type> cll_type_0;
			bool success_1;
			::ISPA_STD::Node<Tokens, Types::ID> ID_2;
			bool success_3;
			bool success_9;
			bool success_7;
			bool success_5;
			::ISPA_STD::Node<Tokens, Types::cll::ASSIGNMENT_OP> cll_ASSIGNMENT_OP_6;
			::ISPA_STD::MatchResult<Rules, Types::cll::expr> cll_expr_8;
			if (cll_type_0.status) {
				success_1 = false;
				cll_type_0 = cll_type(pos);
			}
			skip_spaces(pos);
			success_3 = false;
			if (!(*pos == Tokens::ID)) {
				[Error];
				return ;
			}
			ID_2 = *pos;
			success_3 = true;
			pos++;
			skip_spaces(pos);
			success_5 = false;
			auto begin_10 = pos;
			while (true) {
				if (!(*begin_10 == Tokens::cll::ASSIGNMENT_OP)) {
					[Error];
					break;
				}
				cll_ASSIGNMENT_OP_6 = *begin_10;
				success_7 = true;
				begin_10++;
				skip_spaces(begin_10);
				cll_expr_8 = cll_expr(begin_10);
				if (!(cll_expr_8.status)) {
					break;
				}
				success_9 = true;
				begin_10++;
			}
			if (success_7 && success_9) {
				success_5 = true;
				pos = begin_10;
			}
			skip_spaces(pos);
			Types::cll::_var result;
			result.type = cll_type_0;
			result.id = ID_2;
			result.op = cll_ASSIGNMENT_OP_6;
			result.value = cll_expr_8;
			return result;
		}
		template<typename IT>
		auto cll_expr_logical(IT pos) -> Types::cll::expr::logical		{
			::ISPA_STD::MatchResult<Rules, Types::cll::expr::compare> cll_expr_compare_0;
			bool success_1;
			bool success_8;
			bool success_5;
			bool success_3;
			::ISPA_STD::Node<Tokens, Types::cll::LOGICAL_OP> cll_LOGICAL_OP_4;
			std::vector<::ISPA_STD::Node<Tokens, Types::cll::LOGICAL_OP>> shadow_6;
			::ISPA_STD::MatchResult<Rules, Types::cll::expr::compare> cll_expr_compare_7;
			std::vector<::ISPA_STD::MatchResult<Rules, Types::cll::expr::compare>> shadow_9;
			success_1 = false;
			cll_expr_compare_0 = cll_expr_compare(pos);
			if (!(cll_expr_compare_0.status)) {
				return ;
			}
			success_1 = true;
			pos++;
			skip_spaces(pos);
			success_3 = false;
			auto begin_10 = pos;
			while (true) {
				if (!(*begin_10 == Tokens::cll::LOGICAL_OP)) {
					[Error];
					break;
				}
				cll_LOGICAL_OP_4 = *begin_10;
				success_5 = true;
				begin_10++;
				shadow_6.push_back(cll_LOGICAL_OP_4);
				skip_spaces(begin_10);
				cll_expr_compare_7 = cll_expr_compare(begin_10);
				if (!(cll_expr_compare_7.status)) {
					break;
				}
				success_8 = true;
				begin_10++;
				shadow_9.push_back(cll_expr_compare_7);
			}
			if (success_5 && success_8) {
				success_3 = true;
				pos = begin_10;
			}
			skip_spaces(pos);
			Types::cll::expr::logical result;
			result.left = cll_expr_compare_0;
			result.op = shadow_6;
			result.right = shadow_9;
			return result;
		}
		template<typename IT>
		auto cll_expr_term(IT pos) -> Types::cll::expr::term		{
			::ISPA_STD::MatchResult<Rules, Types::cll::expr::value> cll_expr_value_0;
			bool success_1;
			bool success_8;
			bool success_5;
			bool success_3;
			std::variant<std::monostate, ::ISPA_STD::Node<Tokens, Types::MODULO>, ::ISPA_STD::Node<Tokens, Types::MULTIPLE>, ::ISPA_STD::Node<Tokens, Types::DIVIDE>> _4;
			int dfa_lookup_result_6;
			::ISPA_STD::MatchResult<Rules, Types::cll::expr::value> cll_expr_value_7;
			std::vector<::ISPA_STD::MatchResult<Rules, Types::cll::expr::value>> shadow_9;
			success_1 = false;
			cll_expr_value_0 = cll_expr_value(pos);
			if (!(cll_expr_value_0.status)) {
				return ;
			}
			success_1 = true;
			pos++;
			skip_spaces(pos);
			success_3 = false;
			auto begin_10 = pos;
			while (true) {
				dfa_lookup_result_6 = ::ISPA_STD::DFA::decide(dfa_table_13, pos, &Parser::PANIC_MODE);
				switch (dfa_lookup_result_6) {
					case 0: {
						_4 = *begin_10;
						break;
					}
					case 1: {
						_4 = *begin_10;
						break;
					}
					case 2: {
						_4 = *begin_10;
						break;
					}
				}
				skip_spaces(begin_10);
				cll_expr_value_7 = cll_expr_value(begin_10);
				if (!(cll_expr_value_7.status)) {
					break;
				}
				success_8 = true;
				begin_10++;
				shadow_9.push_back(cll_expr_value_7);
			}
			if (success_5 && success_8) {
				success_3 = true;
				pos = begin_10;
			}
			skip_spaces(pos);
			Types::cll::expr::term result;
			result.first = cll_expr_value_0;
			result.operators = _4;
			result.sequence = shadow_9;
			return result;
		}
		template<typename IT>
		auto cll_expr(IT pos) -> Types::cll::expr		{
			::ISPA_STD::MatchResult<Rules, Types::cll::expr::logical> cll_expr_logical_0;
			bool success_1;
			success_1 = false;
			cll_expr_logical_0 = cll_expr_logical(pos);
			if (!(cll_expr_logical_0.status)) {
				return ;
			}
			success_1 = true;
			pos++;
			skip_spaces(pos);
			Types::cll::expr result;
			result.value = cll_expr_logical_0;
			return result;
		}
		template<typename IT>
		auto cll_function_call(IT pos) -> Types::cll::function_call		{
			::ISPA_STD::Node<Tokens, Types::ID> ID_0;
			bool success_1;
			::ISPA_STD::MatchResult<Rules, Types::cll::function_body_call> cll_function_body_call_2;
			bool success_3;
			success_1 = false;
			if (!(*pos == Tokens::ID)) {
				return ;
			}
			ID_0 = *pos;
			success_1 = true;
			pos++;
			skip_spaces(pos);
			success_3 = false;
			cll_function_body_call_2 = cll_function_body_call(pos);
			if (!(cll_function_body_call_2.status)) {
				return ;
			}
			success_3 = true;
			pos++;
			skip_spaces(pos);
			Types::cll::function_call result;
			result.name = ID_0;
			result.body = cll_function_body_call_2;
			return result;
		}
		template<typename IT>
		auto rule_value(IT pos) -> Types::rule::value		{
			::ISPA_STD::Node<Tokens, Types::AUTO_20> AUTO_20_0;
			bool success_1;
			::ISPA_STD::Node<Tokens, Types::ID> ID_2;
			bool success_3;
			success_1 = false;
			if (!(*pos == Tokens::AUTO_20)) {
				return ;
			}
			AUTO_20_0 = *pos;
			success_1 = true;
			pos++;
			skip_spaces(pos);
			success_3 = false;
			if (!(*pos == Tokens::ID)) {
				[Error];
				return ;
			}
			ID_2 = *pos;
			success_3 = true;
			pos++;
			skip_spaces(pos);
			Types::rule::value result;
			result.value = ID_2;
			return result;
		}
		template<typename IT>
		auto rule_data_block(IT pos) -> Types::rule::data_block		{
			std::variant<std::monostate, ::ISPA_STD::Node<Rules, Types::rule::data_block::templated_datablock>, ::ISPA_STD::Node<Rules, Types::rule::data_block::regular_datablock>> _0;
			bool success_1;
			int dfa_lookup_result_2;
			success_1 = true;
			dfa_lookup_result_2 = ::ISPA_STD::DFA::decide(dfa_table_14, pos, &Parser::PANIC_MODE);
			switch (dfa_lookup_result_2) {
				case 0: {
					_0 = rule_data_block_regular_datablock(pos);
					break;
				}
				case 1: {
					_0 = rule_data_block_templated_datablock(pos);
					break;
				}
			}
			skip_spaces(pos);
			Types::rule::data_block result;
			result.value = _0;
			return result;
		}
		template<typename IT>
		auto moduleImport(IT pos) -> Types::moduleImport		{
			::ISPA_STD::Node<Tokens, Types::AUTO_21> AUTO_21_0;
			bool success_1;
			std::variant<std::monostate, ::ISPA_STD::Node<Rules, Types::moduleImport::from>, ::ISPA_STD::Node<Tokens, Types::ID>> _2;
			bool success_3;
			int dfa_lookup_result_4;
			success_1 = false;
			if (!(*pos == Tokens::AUTO_21)) {
				return ;
			}
			AUTO_21_0 = *pos;
			success_1 = true;
			pos++;
			skip_spaces(pos);
			success_3 = true;
			dfa_lookup_result_4 = ::ISPA_STD::DFA::decide(dfa_table_15, pos, &Parser::PANIC_MODE);
			switch (dfa_lookup_result_4) {
				case 0: {
					_2 = *pos;
					break;
				}
				case 1: {
					_2 = moduleImport_from(pos);
					break;
				}
			}
			skip_spaces(pos);
			Types::moduleImport result;
			result.value = _2;
			return result;
		}
		template<typename IT>
		auto cll(IT pos) -> Types::cll		{
			::ISPA_STD::Node<Tokens, Types::AUTO_22> AUTO_22_0;
			bool success_1;
			std::variant<std::monostate, ::ISPA_STD::Node<Rules, Types::cll::loop_for>, ::ISPA_STD::Node<Rules, Types::cll::_var>, ::ISPA_STD::Node<Rules, Types::cll::expr>, ::ISPA_STD::Node<Rules, Types::cll::_if>, ::ISPA_STD::Node<Rules, Types::cll::loop_while>> _2;
			bool success_3;
			int dfa_lookup_result_4;
			::ISPA_STD::Node<Tokens, Types::AUTO_8> AUTO_8_5;
			bool success_6;
			success_1 = false;
			if (!(*pos == Tokens::AUTO_22)) {
				return ;
			}
			AUTO_22_0 = *pos;
			success_1 = true;
			pos++;
			skip_spaces(pos);
			success_3 = true;
			dfa_lookup_result_4 = ::ISPA_STD::DFA::decide(dfa_table_16, pos, &Parser::PANIC_MODE);
			switch (dfa_lookup_result_4) {
				case 0: {
					_2 = cll_loop_while(pos);
					break;
				}
				case 1: {
					_2 = cll__var(pos);
					break;
				}
				case 2: {
					_2 = cll_loop_for(pos);
					break;
				}
				case 3: {
					_2 = cll__if(pos);
					break;
				}
				case 4: {
					_2 = cll_expr(pos);
					break;
				}
			}
			skip_spaces(pos);
			success_6 = false;
			if (!(*pos == Tokens::AUTO_8)) {
				[Error];
				return ;
			}
			AUTO_8_5 = *pos;
			success_6 = true;
			pos++;
			skip_spaces(pos);
			Types::cll result;
			result.value = _2;
			return result;
		}
		template<typename IT>
		auto rule_nested_rule(IT pos) -> Types::rule::nested_rule		{
			::ISPA_STD::Node<Tokens, Types::AUTO_6> AUTO_6_0;
			bool success_1;
			::ISPA_STD::MatchResult<Rules, Types::rule> rule_2;
			bool success_3;
			success_1 = false;
			if (!(*pos == Tokens::AUTO_6)) {
				return ;
			}
			AUTO_6_0 = *pos;
			success_1 = true;
			pos++;
			skip_spaces(pos);
			success_3 = false;
			rule_2 = rule(pos);
			if (!(rule_2.status)) {
				return ;
			}
			success_3 = true;
			pos++;
			skip_spaces(pos);
			Types::rule::nested_rule result;
			result.value = rule_2;
			return result;
		}
		template<typename IT>
		auto cll_function_body_call(IT pos) -> Types::cll::function_body_call		{
			::ISPA_STD::Node<Tokens, Types::AUTO_4> AUTO_4_0;
			bool success_1;
			::ISPA_STD::MatchResult<Rules, Types::cll::function_arguments> cll_function_arguments_2;
			bool success_3;
			::ISPA_STD::Node<Tokens, Types::AUTO_5> AUTO_5_4;
			bool success_5;
			success_1 = false;
			if (!(*pos == Tokens::AUTO_4)) {
				return ;
			}
			AUTO_4_0 = *pos;
			success_1 = true;
			pos++;
			skip_spaces(pos);
			success_3 = false;
			cll_function_arguments_2 = cll_function_arguments(pos);
			if (!(cll_function_arguments_2.status)) {
				return ;
			}
			success_3 = true;
			pos++;
			skip_spaces(pos);
			success_5 = false;
			if (!(*pos == Tokens::AUTO_5)) {
				[Error];
				return ;
			}
			AUTO_5_4 = *pos;
			success_5 = true;
			pos++;
			skip_spaces(pos);
			Types::cll::function_body_call result;
			result.value = cll_function_arguments_2;
			return result;
		}
		template<typename IT>
		auto cll_expr_arithmetic(IT pos) -> Types::cll::expr::arithmetic		{
			::ISPA_STD::MatchResult<Rules, Types::cll::expr::term> cll_expr_term_0;
			bool success_1;
			bool success_8;
			bool success_5;
			bool success_3;
			std::variant<std::monostate, ::ISPA_STD::Node<Tokens, Types::PLUS>, ::ISPA_STD::Node<Tokens, Types::MINUS>> _4;
			int dfa_lookup_result_6;
			::ISPA_STD::MatchResult<Rules, Types::cll::expr::term> cll_expr_term_7;
			std::vector<::ISPA_STD::MatchResult<Rules, Types::cll::expr::term>> shadow_9;
			success_1 = false;
			cll_expr_term_0 = cll_expr_term(pos);
			if (!(cll_expr_term_0.status)) {
				return ;
			}
			success_1 = true;
			pos++;
			skip_spaces(pos);
			success_3 = false;
			auto begin_10 = pos;
			while (true) {
				dfa_lookup_result_6 = ::ISPA_STD::DFA::decide(dfa_table_17, pos, &Parser::PANIC_MODE);
				switch (dfa_lookup_result_6) {
					case 0: {
						_4 = *begin_10;
						break;
					}
					case 1: {
						_4 = *begin_10;
						break;
					}
				}
				skip_spaces(begin_10);
				cll_expr_term_7 = cll_expr_term(begin_10);
				if (!(cll_expr_term_7.status)) {
					break;
				}
				success_8 = true;
				begin_10++;
				shadow_9.push_back(cll_expr_term_7);
			}
			if (success_5 && success_8) {
				success_3 = true;
				pos = begin_10;
			}
			skip_spaces(pos);
			Types::cll::expr::arithmetic result;
			result.first = cll_expr_term_0;
			result.operators = _4;
			result.sequence = shadow_9;
			return result;
		}
		template<typename IT>
		auto cll__if(IT pos) -> Types::cll::_if		{
			::ISPA_STD::Node<Tokens, Types::AUTO_23> AUTO_23_0;
			bool success_1;
			::ISPA_STD::MatchResult<Rules, Types::cll::expr> cll_expr_2;
			bool success_3;
			::ISPA_STD::MatchResult<Rules, Types::cll::stmt> cll_stmt_4;
			bool success_5;
			success_1 = false;
			if (!(*pos == Tokens::AUTO_23)) {
				return ;
			}
			AUTO_23_0 = *pos;
			success_1 = true;
			pos++;
			skip_spaces(pos);
			success_3 = false;
			cll_expr_2 = cll_expr(pos);
			if (!(cll_expr_2.status)) {
				return ;
			}
			success_3 = true;
			pos++;
			skip_spaces(pos);
			success_5 = false;
			cll_stmt_4 = cll_stmt(pos);
			if (!(cll_stmt_4.status)) {
				return ;
			}
			success_5 = true;
			pos++;
			skip_spaces(pos);
			Types::cll::_if result;
			result.expr = cll_expr_2;
			result.stmt = cll_stmt_4;
			return result;
		}
		template<typename IT>
		auto _use(IT pos) -> Types::_use		{
			::ISPA_STD::Node<Tokens, Types::AUTO_24> AUTO_24_0;
			bool success_1;
			::ISPA_STD::MatchResult<Rules, Types::_use::unit> _use_unit_2;
			bool success_3;
			bool success_10;
			bool success_7;
			bool success_5;
			::ISPA_STD::Node<Tokens, Types::AUTO_2> AUTO_2_6;
			std::vector<::ISPA_STD::Node<Tokens, Types::AUTO_2>> shadow_8;
			::ISPA_STD::MatchResult<Rules, Types::_use::unit> _use_unit_9;
			std::vector<::ISPA_STD::MatchResult<Rules, Types::_use::unit>> shadow_11;
			::ISPA_STD::Node<Tokens, Types::AUTO_8> AUTO_8_13;
			bool success_14;
			success_1 = false;
			if (!(*pos == Tokens::AUTO_24)) {
				return ;
			}
			AUTO_24_0 = *pos;
			success_1 = true;
			pos++;
			skip_spaces(pos);
			success_3 = false;
			_use_unit_2 = _use_unit(pos);
			if (!(_use_unit_2.status)) {
				return ;
			}
			success_3 = true;
			pos++;
			skip_spaces(pos);
			success_5 = false;
			auto begin_12 = pos;
			while (true) {
				if (!(*begin_12 == Tokens::AUTO_2)) {
					[Error];
					break;
				}
				AUTO_2_6 = *begin_12;
				success_7 = true;
				begin_12++;
				shadow_8.push_back(AUTO_2_6);
				skip_spaces(begin_12);
				_use_unit_9 = _use_unit(begin_12);
				if (!(_use_unit_9.status)) {
					break;
				}
				success_10 = true;
				begin_12++;
				shadow_11.push_back(_use_unit_9);
			}
			if (success_7 && success_10) {
				success_5 = true;
				pos = begin_12;
			}
			skip_spaces(pos);
			success_14 = false;
			if (!(*pos == Tokens::AUTO_8)) {
				[Error];
				return ;
			}
			AUTO_8_13 = *pos;
			success_14 = true;
			pos++;
			skip_spaces(pos);
			Types::_use result;
			result.first = _use_unit_2;
			result.second = shadow_11;
			return result;
		}
		template<typename IT>
		auto cll_templ(IT pos) -> Types::cll::templ		{
			::ISPA_STD::Node<Tokens, Types::AUTO_25> AUTO_25_0;
			bool success_1;
			::ISPA_STD::MatchResult<Rules, Types::cll::type> cll_type_2;
			bool success_3;
			bool success_10;
			bool success_7;
			bool success_5;
			::ISPA_STD::Node<Tokens, Types::AUTO_2> AUTO_2_6;
			std::vector<::ISPA_STD::Node<Tokens, Types::AUTO_2>> shadow_8;
			::ISPA_STD::MatchResult<Rules, Types::cll::type> cll_type_9;
			std::vector<::ISPA_STD::MatchResult<Rules, Types::cll::type>> shadow_11;
			::ISPA_STD::Node<Tokens, Types::AUTO_26> AUTO_26_13;
			bool success_14;
			success_1 = false;
			if (!(*pos == Tokens::AUTO_25)) {
				return ;
			}
			AUTO_25_0 = *pos;
			success_1 = true;
			pos++;
			skip_spaces(pos);
			success_3 = false;
			cll_type_2 = cll_type(pos);
			if (!(cll_type_2.status)) {
				return ;
			}
			success_3 = true;
			pos++;
			skip_spaces(pos);
			success_5 = false;
			auto begin_12 = pos;
			while (true) {
				if (!(*begin_12 == Tokens::AUTO_2)) {
					[Error];
					break;
				}
				AUTO_2_6 = *begin_12;
				success_7 = true;
				begin_12++;
				shadow_8.push_back(AUTO_2_6);
				skip_spaces(begin_12);
				cll_type_9 = cll_type(begin_12);
				if (!(cll_type_9.status)) {
					break;
				}
				success_10 = true;
				begin_12++;
				shadow_11.push_back(cll_type_9);
			}
			if (success_7 && success_10) {
				success_5 = true;
				pos = begin_12;
			}
			skip_spaces(pos);
			success_14 = false;
			if (!(*pos == Tokens::AUTO_26)) {
				[Error];
				return ;
			}
			AUTO_26_13 = *pos;
			success_14 = true;
			pos++;
			skip_spaces(pos);
			Types::cll::templ result;
			result.first = cll_type_2;
			result.second = shadow_11;
			return result;
		}
		template<typename IT>
		auto cll_loop_for(IT pos) -> Types::cll::loop_for		{
			::ISPA_STD::Node<Tokens, Types::AUTO_27> AUTO_27_0;
			bool success_1;
			::ISPA_STD::Node<Tokens, Types::AUTO_4> AUTO_4_2;
			bool success_3;
			bool success_7;
			std::variant<std::monostate, ::ISPA_STD::Node<Rules, Types::cll::_var>, ::ISPA_STD::Node<Rules, Types::cll::expr>> group_4;
			bool success_5;
			std::variant<std::monostate, ::ISPA_STD::Node<Rules, Types::cll::_var>, ::ISPA_STD::Node<Rules, Types::cll::expr>> _6;
			int dfa_lookup_result_8;
			::ISPA_STD::Node<Tokens, Types::AUTO_8> AUTO_8_10;
			bool success_11;
			::ISPA_STD::MatchResult<Rules, Types::cll::expr> cll_expr_12;
			bool success_13;
			::ISPA_STD::Node<Tokens, Types::AUTO_8> AUTO_8_14;
			bool success_15;
			::ISPA_STD::MatchResult<Rules, Types::cll::expr> cll_expr_16;
			bool success_17;
			::ISPA_STD::Node<Tokens, Types::AUTO_5> AUTO_5_18;
			bool success_19;
			::ISPA_STD::MatchResult<Rules, Types::cll::stmt> cll_stmt_20;
			bool success_21;
			success_1 = false;
			if (!(*pos == Tokens::AUTO_27)) {
				return ;
			}
			AUTO_27_0 = *pos;
			success_1 = true;
			pos++;
			skip_spaces(pos);
			success_3 = false;
			if (!(*pos == Tokens::AUTO_4)) {
				[Error];
				return ;
			}
			AUTO_4_2 = *pos;
			success_3 = true;
			pos++;
			skip_spaces(pos);
			group_4 = _6;
			success_5 = false;
			auto begin_9 = pos;
			while (true) {
				dfa_lookup_result_8 = ::ISPA_STD::DFA::decide(dfa_table_18, pos, &Parser::PANIC_MODE);
				switch (dfa_lookup_result_8) {
					case 0: {
						_6 = cll_expr(begin_9);
						break;
					}
					case 1: {
						_6 = cll__var(begin_9);
						break;
					}
				}
			}
			if (success_7) {
				success_5 = true;
				pos = begin_9;
			}
			skip_spaces(pos);
			success_11 = false;
			if (!(*pos == Tokens::AUTO_8)) {
				[Error];
				return ;
			}
			AUTO_8_10 = *pos;
			success_11 = true;
			pos++;
			skip_spaces(pos);
			if (cll_expr_12.status) {
				success_13 = false;
				cll_expr_12 = cll_expr(pos);
			}
			skip_spaces(pos);
			success_15 = false;
			if (!(*pos == Tokens::AUTO_8)) {
				[Error];
				return ;
			}
			AUTO_8_14 = *pos;
			success_15 = true;
			pos++;
			skip_spaces(pos);
			if (cll_expr_16.status) {
				success_17 = false;
				cll_expr_16 = cll_expr(pos);
			}
			skip_spaces(pos);
			success_19 = false;
			if (!(*pos == Tokens::AUTO_5)) {
				[Error];
				return ;
			}
			AUTO_5_18 = *pos;
			success_19 = true;
			pos++;
			skip_spaces(pos);
			success_21 = false;
			cll_stmt_20 = cll_stmt(pos);
			if (!(cll_stmt_20.status)) {
				return ;
			}
			success_21 = true;
			pos++;
			skip_spaces(pos);
			Types::cll::loop_for result;
			result.decl = group_4;
			result.cond = cll_expr_12;
			result.end = cll_expr_16;
			result.stmt = cll_stmt_20;
			return result;
		}
		template<typename IT>
		auto cll_loop_while(IT pos) -> Types::cll::loop_while		{
			::ISPA_STD::Node<Tokens, Types::AUTO_28> AUTO_28_0;
			bool success_1;
			::ISPA_STD::MatchResult<Rules, Types::cll::expr> cll_expr_2;
			bool success_3;
			::ISPA_STD::MatchResult<Rules, Types::cll::stmt> cll_stmt_4;
			bool success_5;
			success_1 = false;
			if (!(*pos == Tokens::AUTO_28)) {
				return ;
			}
			AUTO_28_0 = *pos;
			success_1 = true;
			pos++;
			skip_spaces(pos);
			success_3 = false;
			cll_expr_2 = cll_expr(pos);
			if (!(cll_expr_2.status)) {
				return ;
			}
			success_3 = true;
			pos++;
			skip_spaces(pos);
			success_5 = false;
			cll_stmt_4 = cll_stmt(pos);
			if (!(cll_stmt_4.status)) {
				return ;
			}
			success_5 = true;
			pos++;
			skip_spaces(pos);
			Types::cll::loop_while result;
			result.expr = cll_expr_2;
			result.stmt = cll_stmt_4;
			return result;
		}
	};
}
#endif // PARSER_H
