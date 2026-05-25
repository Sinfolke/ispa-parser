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
			 std::variant<::ISPA_STD::Node<Tokens, cll_LOGICAL_AND>, ::ISPA_STD::Node<Tokens, cll_LOGICAL_OR>> value;
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
			 std::variant<::ISPA_STD::Node<Tokens, MULTIPLE>, ::ISPA_STD::Node<Tokens, PLUS>, ::ISPA_STD::Node<Tokens, QUESTION_MARK>> value;
		};
		struct rule_CSEQUENCE {
			 char _not;
			 std::vector<std::variant<::ISPA_STD::Node<Tokens, rule_CSEQUENCE_SYMBOL>, ::ISPA_STD::Node<Tokens, rule_CSEQUENCE_DIAPASON>, ::ISPA_STD::Node<Tokens, rule_CSEQUENCE_ESCAPE>>> val;
		};
		struct moduleImport_from {
			 std::variant<::ISPA_STD::Node<Rules, moduleImport_from_import_list>, ::ISPA_STD::Node<Tokens, MULTIPLE>> what;
			 ::ISPA_STD::Node<Tokens, ID> from;
		};
		struct cll_function_body_decl {
			 ::ISPA_STD::Node<Rules, cll_function_parameters> value;
		};
		struct moduleImport {
			 std::variant<::ISPA_STD::Node<Rules, moduleImport_from>, ::ISPA_STD::Node<Tokens, ID>> value;
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
			 std::variant<::ISPA_STD::Node<Tokens, NUMBER>, ::ISPA_STD::Node<Tokens, ID>> key;
			 ::ISPA_STD::MatchResult<Rules, std::unique_ptr<cll_expr>> value;
			 std::variant<::ISPA_STD::Node<Tokens, NUMBER>, ::ISPA_STD::Node<Tokens, ID>> keys;
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
			 std::variant<::ISPA_STD::Node<Tokens, AUTO_30>, ::ISPA_STD::Node<Tokens, AUTO_29>> pre;
			 ::ISPA_STD::Node<Tokens, ID> name;
			 ::ISPA_STD::MatchResult<Rules, std::unique_ptr<cll_expr>> brace_expression;
			 std::variant<::ISPA_STD::Node<Tokens, AUTO_30>, ::ISPA_STD::Node<Tokens, AUTO_29>> pos;
		};
		struct rule_data_block_regular_datablock_key {
			 ::ISPA_STD::Node<Tokens, ID> name;
			 ::ISPA_STD::MatchResult<Rules, std::unique_ptr<cll_expr>> dt;
		};
		struct cll_loop_for {
			 std::variant<::ISPA_STD::Node<Rules, std::unique_ptr<cll__var>>, ::ISPA_STD::Node<Rules, std::unique_ptr<cll_expr>>> decl;
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
			 std::variant<::ISPA_STD::Node<Rules, rule_data_block_regular_datablock_key>, ::ISPA_STD::Node<Rules, std::unique_ptr<cll_expr>>> value;
		};
		struct cll {
			 std::variant<::ISPA_STD::Node<Rules, cll__if>, ::ISPA_STD::Node<Rules, cll_loop_for>, ::ISPA_STD::Node<Rules, std::unique_ptr<cll__var>>, ::ISPA_STD::Node<Rules, std::unique_ptr<cll_expr>>, ::ISPA_STD::Node<Rules, cll_loop_while>> value;
		};
		struct rule_data_block {
			 std::variant<::ISPA_STD::Node<Rules, rule_data_block_templated_datablock>, ::ISPA_STD::Node<Rules, rule_data_block_regular_datablock>> value;
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
			 std::variant<::ISPA_STD::Node<Tokens, MODULO>, ::ISPA_STD::Node<Tokens, MULTIPLE>, ::ISPA_STD::Node<Tokens, DIVIDE>> operators;
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
			 std::variant<::ISPA_STD::Node<Tokens, ID>, ::ISPA_STD::Node<Tokens, BOOLEAN>, ::ISPA_STD::Node<Tokens, STRING>, ::ISPA_STD::Node<Tokens, AT>, ::ISPA_STD::Node<Tokens, NUMBER>, ::ISPA_STD::Node<Rules, object>, ::ISPA_STD::Node<Rules, array>> value;
		};
		struct rule_member {
			 std::variant<::ISPA_STD::Node<Rules, rule_value>, ::ISPA_STD::Node<Rules, rule_keyvalue>> prefix;
			 std::variant<::ISPA_STD::Node<Rules, rule_name>, ::ISPA_STD::Node<Tokens, STRING>, ::ISPA_STD::Node<Tokens, rule_HEX>, ::ISPA_STD::Node<Tokens, DOT>, ::ISPA_STD::Node<Tokens, rule_CSEQUENCE>, ::ISPA_STD::Node<Tokens, rule_BIN>, ::ISPA_STD::Node<Tokens, rule_OP>, ::ISPA_STD::Node<Rules, cll>, ::ISPA_STD::Node<Tokens, rule_ESCAPED>, ::ISPA_STD::Node<Rules, rule_group>, ::ISPA_STD::Node<Tokens, LINEAR_COMMENT>, ::ISPA_STD::Node<Tokens, rule_NOSPACE>> val;
			 ::ISPA_STD::MatchResult<Rules, rule_quantifier> quantifier;
		};
		struct _use_unit {
			 ::ISPA_STD::Node<Tokens, ID> name;
			 ::ISPA_STD::MatchResult<Rules, std::unique_ptr<rvalue>> value;
		};
		struct cll_expr_arithmetic {
			 ::ISPA_STD::MatchResult<Rules, std::unique_ptr<cll_expr_term>> first;
			 std::variant<::ISPA_STD::Node<Tokens, PLUS>, ::ISPA_STD::Node<Tokens, MINUS>> operators;
			 std::vector<::ISPA_STD::MatchResult<Rules, std::unique_ptr<cll_expr_term>>> sequence;
		};
		struct rule {
			 ::ISPA_STD::Node<Tokens, ID> name;
			 std::vector<::ISPA_STD::MatchResult<Rules, std::unique_ptr<rule_member>>> rule;
			 ::ISPA_STD::MatchResult<Rules, rule_data_block> data_block;
			 std::vector<::ISPA_STD::MatchResult<Rules, rule_nested_rule>> nested_rules;
		};
		struct main {
			 std::variant<::ISPA_STD::Node<Rules, std::unique_ptr<rule>>, ::ISPA_STD::Node<Rules, _use>, ::ISPA_STD::Node<Tokens, NAME>, ::ISPA_STD::Node<Tokens, SPACEMODE>> value;
		};
		struct cll_type {
			 ::ISPA_STD::Node<Tokens, AUTO_13> type;
			 ::ISPA_STD::MatchResult<Rules, cll_templ> templ;
		};
		struct cll_expr_value {
			 std::variant<::ISPA_STD::Node<Rules, std::unique_ptr<rvalue>>, ::ISPA_STD::Node<Rules, std::unique_ptr<cll_function_call>>, ::ISPA_STD::Node<Rules, cll_method_call>, ::ISPA_STD::Node<Rules, cll_expr_group>, ::ISPA_STD::Node<Rules, cll__variable>> value;
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
	using Token = std::variant<Types::NAME, Types::AUTO_2, Types::cll::LOGICAL_AND, Types::AUTO_0, Types::LINEAR_COMMENT, Types::cll::COMPARE_OP, Types::AUTO_5, Types::cll::ASSIGNMENT_OP, Types::MINUS, Types::AUTO_4, Types::SPACEMODE, Types::STRING, Types::DIVIDE, Types::DOT, Types::AUTO_11, Types::QUESTION_MARK, Types::MODULO, Types::cll::LOGICAL_NOT, Types::rule::CSEQUENCE, Types::NUMBER, Types::AUTO_30, Types::cll::LOGICAL_OR, Types::rule::OP, Types::AUTO_9, Types::rule::CSEQUENCE::SYMBOL, Types::AT, Types::rule::CSEQUENCE::DIAPASON, Types::AUTO_1, Types::rule::CSEQUENCE::ESCAPE, Types::MULTIPLE, Types::AUTO_7, Types::BOOLEAN, Types::rule::NOSPACE, Types::rule::BIN, Types::AUTO_6, Types::__WHITESPACE, Types::AUTO_12, Types::AUTO_17, Types::AUTO_14, Types::AUTO_10, Types::rule::HEX, Types::AUTO_16, Types::AUTO_19, Types::AUTO_28, Types::AUTO_27, Types::AUTO_15, Types::AUTO_18, Types::rule::ESCAPED, Types::AUTO_20, Types::ID, Types::AUTO_22, Types::PLUS, Types::AUTO_21, Types::AUTO_8, Types::cll::LOGICAL_OP, Types::AUTO_3, Types::AUTO_13, Types::AUTO_23, Types::AUTO_24, Types::AUTO_25, Types::AUTO_26, Types::AUTO_29>;
	class Lexer : public ::ISPA_STD::Lexer_base<Tokens, Token> {
		static ::ISPA_STD::DFAAPI::CharState dfa_state_0;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_1;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_2;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_3;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_4;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_5;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_6;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_7;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_8;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_9;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_10;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_11;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_12;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_13;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_14;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_15;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_16;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_17;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_18;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_19;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_20;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_21;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_22;
		static ::ISPA_STD::DFAAPI::CharTableState<Tokens, Token, 2> dfa_state_23;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_24;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_25;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_26;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_27;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_28;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_29;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_30;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_31;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_32;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_33;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_34;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_35;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_36;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_37;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_38;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_39;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_40;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_41;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_42;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_43;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_44;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_45;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_46;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_47;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_48;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_49;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_50;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_51;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_52;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_53;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_54;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_55;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_56;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_57;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_58;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_59;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_60;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_61;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_62;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_63;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_64;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_65;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_66;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_67;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_68;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_69;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_70;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_71;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_72;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_73;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_74;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_75;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_76;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_77;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_78;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_79;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_80;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_81;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_82;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_83;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_84;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_85;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_86;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_87;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_88;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_89;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_90;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_91;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_92;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_93;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_94;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_95;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_96;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_97;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_98;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_99;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_100;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_101;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_102;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_103;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_104;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_105;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_106;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_107;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_108;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_109;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_110;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_111;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_112;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_113;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_114;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_115;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_116;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_117;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_118;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_119;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_120;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_121;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_122;
		static ::ISPA_STD::DFAAPI::MultiTableState<Tokens, Token, 3> dfa_state_123;
		static ::ISPA_STD::DFAAPI::MultiTableState<Tokens, Token, 3> dfa_state_124;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_125;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_126;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_127;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_128;
		static ::ISPA_STD::DFAAPI::CharTableState<Tokens, Token, 1> dfa_state_129;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_130;
		static ::ISPA_STD::DFAAPI::CharTableState<Tokens, Token, 1> dfa_state_131;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_132;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_133;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_134;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_135;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_136;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_137;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_138;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_139;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_140;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_141;
		static ::ISPA_STD::DFAAPI::CharTableState<Tokens, Token, 2> dfa_state_142;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_143;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_144;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_145;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_146;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_147;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_148;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_149;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_150;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_151;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_152;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_153;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_154;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_155;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_156;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_157;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_158;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_159;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_160;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_161;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_162;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_163;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_164;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_165;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_166;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_167;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_168;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_169;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_170;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_171;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_172;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_173;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_174;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_175;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_176;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_177;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_178;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_179;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_180;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_181;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_182;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_183;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_184;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_185;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_186;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_187;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_188;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_189;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_190;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_191;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_192;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_193;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_194;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_195;
		static ::ISPA_STD::DFAAPI::CharTableState<Tokens, Token, 1> dfa_state_196;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_197;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_198;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_199;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_200;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_201;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_202;
		static ::ISPA_STD::DFAAPI::CharTableState<Tokens, Token, 2> dfa_state_203;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_204;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_205;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_206;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_207;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_208;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_209;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_210;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_211;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_212;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_213;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_214;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_215;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_216;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_217;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_218;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_219;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_220;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_221;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_222;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_223;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_224;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_225;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_226;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_227;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_228;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_229;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_230;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_231;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_232;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_233;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_234;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_235;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_236;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_237;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_238;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_239;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_240;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_241;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_242;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_243;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_244;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_245;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_246;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_247;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_248;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_249;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_250;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_251;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_252;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_253;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_254;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_255;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_256;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_257;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_258;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_259;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_260;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_261;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_262;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_263;
		static ::ISPA_STD::DFAAPI::CharTableState<Tokens, Token, 2> dfa_state_264;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_265;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_266;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 8> dfa_table_0;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 2> dfa_table_1;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 2> dfa_table_2;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 8> dfa_table_3;
		static ::ISPA_STD::DFAAPI::MultiTable<Tokens, Token, 4> dfa_table_4;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 4> dfa_table_5;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 5> dfa_table_6;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 4> dfa_table_7;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 2> dfa_table_8;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 2> dfa_table_9;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 8> dfa_table_10;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 13> dfa_table_11;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 2> dfa_table_12;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 14> dfa_table_13;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 2> dfa_table_14;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 11> dfa_table_15;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 8> dfa_table_16;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 2> dfa_table_17;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 2> dfa_table_18;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 9> dfa_table_19;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 9> dfa_table_20;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 9> dfa_table_21;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 2> dfa_table_22;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 2> dfa_table_23;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 4> dfa_table_24;
		static ::ISPA_STD::DFAAPI::MultiTable<Tokens, Token, 8> dfa_table_25;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 3> dfa_table_26;
		static ::ISPA_STD::DFAAPI::MultiTable<Tokens, Token, 4> dfa_table_27;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 2> dfa_table_28;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 5> dfa_table_29;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 2> dfa_table_30;
		static ::ISPA_STD::DFAAPI::MultiTable<Tokens, Token, 10> dfa_table_31;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 4> dfa_table_32;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 5> dfa_table_33;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 8> dfa_table_34;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 17> dfa_table_35;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 12> dfa_table_36;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 10> dfa_table_37;
		static ::ISPA_STD::DFAAPI::MultiTable<Tokens, Token, 13> dfa_table_38;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 4> dfa_table_39;
		static ::ISPA_STD::DFAAPI::MultiTable<Tokens, Token, 10> dfa_table_40;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 4> dfa_table_41;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 5> dfa_table_42;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 29> dfa_table_43;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 12> dfa_table_44;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 8> dfa_table_45;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 8> dfa_table_46;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 9> dfa_table_47;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 2> dfa_table_48;
		static ::ISPA_STD::DFAAPI::MultiTable<Tokens, Token, 4> dfa_table_49;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 4> dfa_table_50;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 5> dfa_table_51;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 2> dfa_table_52;
	};
}
#endif // PARSER_H
