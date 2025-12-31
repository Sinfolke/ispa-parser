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
		NAME,
		AUTO_2,
		cll_LOGICAL_AND,
		cll_TYPE,
		cll_COMPARE_OP,
		DIVIDE,
		DOT,
		AUTO_11,
		rule_CSEQUENCE_DIAPASON,
		AT,
		cll_LOGICAL_OR,
		AUTO_9,
		rule_OP,
		QUESTION_MARK,
		MINUS,
		MODULO,
		cll_LOGICAL_NOT,
		rule_CSEQUENCE,
		NUMBER,
		cll_LOGICAL_OP,
		AUTO_3,
		AUTO_13,
		AUTO_18,
		rule_CSEQUENCE_ESCAPE,
		AUTO_1,
		SPACEMODE,
		MULTIPLE,
		AUTO_7,
		BOOLEAN,
		rule_NOSPACE,
		rule_BIN,
		AUTO_10,
		rule_HEX,
		AUTO_16,
		AUTO_19,
		rule_ESCAPED,
		AUTO_0,
		LINEAR_COMMENT,
		AUTO_5,
		cll_ASSIGNMENT_OP,
		AUTO_20,
		cll_TEMPLATE,
		AUTO_12,
		__WHITESPACE,
		AUTO_15,
		AUTO_4,
		AUTO_14,
		AUTO_17,
		ID,
		AUTO_22,
		STRING,
		rule_CSEQUENCE_SYMBOL,
		PLUS,
		AUTO_21,
		AUTO_8,
		AUTO_6,
	};
	enum class Rules {
		_use,
		rule_data_block_regular_datablock_key,
		cll_function_body_call,
		rule_data_block,
		cll_function_call,
		cll_expr,
		cll_expr_term,
		cll_expr_logical,
		cll__var,
		cll_loop_while,
		cll_loop_for,
		cll__variable,
		rule_nested_rule,
		rvalue,
		_use_unit,
		moduleImport_from_import_list,
		cll_expr_arithmetic,
		rule,
		main,
		array,
		rule_member,
		rule_data_block_templated_datablock,
		rule_group,
		cll_expr_value,
		cll_function_body_decl,
		rule_name,
		rule_data_block_regular_datablock,
		moduleImport,
		cll_expr_group,
		cll,
		moduleDeclaration,
		cll__if,
		rule_quantifier,
		moduleImport_from,
		rule_value,
		object,
		cll_stmt,
		cll_expr_compare,
		cll_method_call,
		cll_function_arguments,
		rule_keyvalue,
		cll_function_parameters,
	};
	namespace FlatTypes {
		struct cll__var;
		struct cll_expr_arithmetic;
		struct rule;
		struct cll_expr;
		struct cll_TYPE;
		struct cll_expr_term;
		struct _use_unit;
		struct rule_member;
		struct main;
		struct rvalue;
		struct cll_function_call;
		struct cll_stmt;
		struct cll_expr_compare;
		struct cll_expr_value;
		struct AUTO_2 {
			 char value;
		};
		struct cll_LOGICAL_AND {
		};
		struct cll_COMPARE_OP {
			 std::string value;
		};
		struct DIVIDE {
		};
		struct DOT {
		};
		struct AUTO_11 {
			 char value;
		};
		struct AT {
		};
		struct cll_LOGICAL_OR {
		};
		struct AUTO_9 {
			 char value;
		};
		struct rule_OP {
		};
		struct QUESTION_MARK {
		};
		struct MINUS {
		};
		struct MODULO {
		};
		struct cll_LOGICAL_NOT {
		};
		struct NUMBER {
			 std::string sign;
			 std::string dec;
			 std::string main;
		};
		struct AUTO_3 {
			 char value;
		};
		struct AUTO_13 {
			 char value;
		};
		struct AUTO_18 {
			 char value;
		};
		struct rule_CSEQUENCE_ESCAPE {
			 char value;
		};
		struct AUTO_1 {
			 char value;
		};
		struct SPACEMODE {
			 std::string value;
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
		struct rule_ESCAPED {
			 char value;
		};
		struct AUTO_0 {
			 char value;
		};
		struct LINEAR_COMMENT {
		};
		struct AUTO_5 {
			 char value;
		};
		struct cll_ASSIGNMENT_OP {
			 std::string value;
		};
		struct AUTO_20 {
			 char value;
		};
		struct AUTO_12 {
			 char value;
		};
		struct __WHITESPACE {
		};
		struct AUTO_15 {
			 char value;
		};
		struct AUTO_4 {
			 char value;
		};
		struct AUTO_14 {
			 char value;
		};
		struct AUTO_17 {
			 char value;
		};
		struct ID {
			 std::string value;
		};
		struct AUTO_22 {
			 char value;
		};
		struct STRING {
			 std::string value;
		};
		struct rule_CSEQUENCE_SYMBOL {
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
		struct AUTO_6 {
			 char value;
		};
		struct cll_LOGICAL_OP {
			 std::variant<::ISPA_STD::Node<Tokens, cll_LOGICAL_AND>, ::ISPA_STD::Node<Tokens, cll_LOGICAL_OR>> value;
		};
		struct NAME {
			 ::ISPA_STD::Node<Tokens, ID> value;
		};
		struct rule_data_block_templated_datablock {
			 ::ISPA_STD::Node<Tokens, ID> first_name;
			 std::vector<::ISPA_STD::Node<Tokens, ID>> second_name;
		};
		struct rule_value {
			 ::ISPA_STD::Node<Tokens, ID> value;
		};
		struct rule_name {
			 ::ISPA_STD::Node<Tokens, AUTO_5> is_nested;
			 ::ISPA_STD::Node<Tokens, ID> name;
			 std::vector<::ISPA_STD::Node<Tokens, ID>> nested_name;
		};
		struct cll_function_parameters {
			 ::ISPA_STD::Node<Tokens, ID> first;
			 std::vector<::ISPA_STD::Node<Tokens, ID>> second;
		};
		struct rule_keyvalue {
			 ::ISPA_STD::Node<Tokens, ID> value;
		};
		struct moduleDeclaration {
			 ::ISPA_STD::Node<Tokens, ID> name;
			 ::ISPA_STD::Node<Tokens, ID> base;
		};
		struct moduleImport_from_import_list {
			 ::ISPA_STD::Node<Tokens, ID> first;
			 std::vector<::ISPA_STD::Node<Tokens, ID>> sequence;
		};
		struct rule_CSEQUENCE_DIAPASON {
			 ::ISPA_STD::MatchResult<Tokens, rule_CSEQUENCE_SYMBOL> begin;
			 ::ISPA_STD::MatchResult<Tokens, rule_CSEQUENCE_SYMBOL> end;
		};
		struct rule_quantifier {
			 std::variant<::ISPA_STD::Node<Tokens, MULTIPLE>, ::ISPA_STD::Node<Tokens, PLUS>, ::ISPA_STD::Node<Tokens, QUESTION_MARK>> value;
		};
		struct cll_function_body_decl {
			 ::ISPA_STD::Node<Rules, cll_function_parameters> value;
		};
		struct moduleImport_from {
			 std::variant<::ISPA_STD::Node<Rules, moduleImport_from_import_list>, ::ISPA_STD::Node<Tokens, MULTIPLE>> what;
			 ::ISPA_STD::Node<Tokens, ID> from;
		};
		struct rule_CSEQUENCE {
			 char _not;
			 std::vector<std::variant<::ISPA_STD::Node<Tokens, rule_CSEQUENCE_SYMBOL>, ::ISPA_STD::Node<Tokens, rule_CSEQUENCE_DIAPASON>, ::ISPA_STD::Node<Tokens, rule_CSEQUENCE_ESCAPE>>> val;
		};
		struct moduleImport {
			 std::variant<::ISPA_STD::Node<Rules, moduleImport_from>, ::ISPA_STD::Node<Tokens, ID>> value;
		};
		struct cll_TEMPLATE {
			 ::ISPA_STD::MatchResult<Tokens, std::shared_ptr<cll_TYPE>> first;
			 std::vector<::ISPA_STD::MatchResult<Tokens, std::shared_ptr<cll_TYPE>>> second;
		};
		struct _use {
			 ::ISPA_STD::MatchResult<Rules, std::shared_ptr<_use_unit>> first;
			 std::vector<::ISPA_STD::MatchResult<Rules, std::shared_ptr<_use_unit>>> second;
		};
		struct cll_method_call {
			 ::ISPA_STD::Node<Tokens, ID> name;
			 ::ISPA_STD::MatchResult<Rules, std::shared_ptr<cll_function_call>> body;
		};
		struct cll_expr_group {
			 ::ISPA_STD::Node<Rules, std::shared_ptr<cll_expr>> value;
		};
		struct rule_data_block_regular_datablock_key {
			 ::ISPA_STD::Node<Tokens, ID> name;
			 ::ISPA_STD::MatchResult<Rules, std::shared_ptr<cll_expr>> dt;
		};
		struct rule_nested_rule {
			 ::ISPA_STD::Node<Rules, std::shared_ptr<rule>> value;
		};
		struct cll__variable {
			 std::variant<::ISPA_STD::Node<Tokens, AUTO_21>, ::ISPA_STD::Node<Tokens, AUTO_20>> pre;
			 ::ISPA_STD::MatchResult<Rules, std::shared_ptr<cll_expr>> brace_expression;
			 std::variant<::ISPA_STD::Node<Tokens, AUTO_21>, ::ISPA_STD::Node<Tokens, AUTO_20>> pos;
			 ::ISPA_STD::Node<Tokens, ID> name;
		};
		struct cll_loop_while {
			 ::ISPA_STD::MatchResult<Rules, std::shared_ptr<cll_expr>> expr;
			 ::ISPA_STD::MatchResult<Rules, std::shared_ptr<cll_stmt>> stmt;
		};
		struct array {
			 std::vector<::ISPA_STD::MatchResult<Rules, std::shared_ptr<cll_expr>>> value;
		};
		struct cll_loop_for {
			 std::variant<::ISPA_STD::Node<Rules, std::shared_ptr<cll__var>>, ::ISPA_STD::Node<Rules, std::shared_ptr<cll_expr>>> decl;
			 ::ISPA_STD::MatchResult<Rules, std::shared_ptr<cll_expr>> end;
			 ::ISPA_STD::MatchResult<Rules, std::shared_ptr<cll_expr>> cond;
			 ::ISPA_STD::MatchResult<Rules, std::shared_ptr<cll_stmt>> stmt;
		};
		struct object {
			 std::variant<::ISPA_STD::Node<Tokens, NUMBER>, ::ISPA_STD::Node<Tokens, ID>> key;
			 ::ISPA_STD::MatchResult<Rules, std::shared_ptr<cll_expr>> value;
			 std::variant<::ISPA_STD::Node<Tokens, NUMBER>, ::ISPA_STD::Node<Tokens, ID>> keys;
			 std::vector<::ISPA_STD::MatchResult<Rules, std::shared_ptr<cll_expr>>> values;
		};
		struct cll_expr_logical {
			 ::ISPA_STD::MatchResult<Rules, std::shared_ptr<cll_expr_compare>> left;
			 std::vector<::ISPA_STD::Node<Tokens, cll_LOGICAL_OP>> op;
			 std::vector<::ISPA_STD::MatchResult<Rules, std::shared_ptr<cll_expr_compare>>> right;
		};
		struct rule_group {
			 std::vector<::ISPA_STD::MatchResult<Rules, std::shared_ptr<rule_member>>> value;
		};
		struct cll__if {
			 ::ISPA_STD::MatchResult<Rules, std::shared_ptr<cll_expr>> expr;
			 ::ISPA_STD::MatchResult<Rules, std::shared_ptr<cll_stmt>> stmt;
		};
		struct cll_function_arguments {
			 ::ISPA_STD::MatchResult<Rules, std::shared_ptr<cll_expr>> first;
			 std::vector<::ISPA_STD::MatchResult<Rules, std::shared_ptr<cll_expr>>> second;
		};
		struct rule_data_block_regular_datablock {
			 std::variant<::ISPA_STD::Node<Rules, rule_data_block_regular_datablock_key>, ::ISPA_STD::Node<Rules, std::shared_ptr<cll_expr>>> value;
		};
		struct cll {
			 std::variant<::ISPA_STD::Node<Rules, cll__if>, ::ISPA_STD::Node<Rules, cll_loop_for>, ::ISPA_STD::Node<Rules, std::shared_ptr<cll__var>>, ::ISPA_STD::Node<Rules, std::shared_ptr<cll_expr>>, ::ISPA_STD::Node<Rules, cll_loop_while>> value;
		};
		struct cll_function_body_call {
			 ::ISPA_STD::Node<Rules, cll_function_arguments> value;
		};
		struct rule_data_block {
			 std::variant<::ISPA_STD::Node<Rules, rule_data_block_templated_datablock>, ::ISPA_STD::Node<Rules, rule_data_block_regular_datablock>> value;
		};
		struct cll_TYPE {
			 char type;
			 ::ISPA_STD::MatchResult<Tokens, cll_TEMPLATE> templ;
		};
		struct cll_function_call {
			 ::ISPA_STD::Node<Tokens, ID> name;
			 ::ISPA_STD::MatchResult<Rules, cll_function_body_call> body;
		};
		struct cll_expr {
			 ::ISPA_STD::Node<Rules, cll_expr_logical> value;
		};
		struct cll_expr_term {
			 ::ISPA_STD::MatchResult<Rules, std::shared_ptr<cll_expr_value>> first;
			 std::variant<::ISPA_STD::Node<Tokens, MODULO>, ::ISPA_STD::Node<Tokens, MULTIPLE>, ::ISPA_STD::Node<Tokens, DIVIDE>> operators;
			 std::vector<::ISPA_STD::MatchResult<Rules, std::shared_ptr<cll_expr_value>>> sequence;
		};
		struct cll__var {
			 ::ISPA_STD::Node<Tokens, std::shared_ptr<cll_TYPE>> type;
			 ::ISPA_STD::Node<Tokens, ID> id;
			 ::ISPA_STD::Node<Tokens, cll_ASSIGNMENT_OP> op;
			 ::ISPA_STD::MatchResult<Rules, std::shared_ptr<cll_expr>> value;
		};
		struct rvalue {
			 std::variant<::ISPA_STD::Node<Tokens, ID>, ::ISPA_STD::Node<Tokens, BOOLEAN>, ::ISPA_STD::Node<Tokens, STRING>, ::ISPA_STD::Node<Tokens, AT>, ::ISPA_STD::Node<Tokens, NUMBER>, ::ISPA_STD::Node<Rules, object>, ::ISPA_STD::Node<Rules, array>> value;
		};
		struct _use_unit {
			 ::ISPA_STD::Node<Tokens, ID> name;
			 ::ISPA_STD::MatchResult<Rules, std::shared_ptr<rvalue>> value;
		};
		struct cll_expr_arithmetic {
			 ::ISPA_STD::MatchResult<Rules, std::shared_ptr<cll_expr_term>> first;
			 std::variant<::ISPA_STD::Node<Tokens, PLUS>, ::ISPA_STD::Node<Tokens, MINUS>> operators;
			 std::vector<::ISPA_STD::MatchResult<Rules, std::shared_ptr<cll_expr_term>>> sequence;
		};
		struct rule {
			 ::ISPA_STD::Node<Tokens, ID> name;
			 ::ISPA_STD::MatchResult<Rules, rule_data_block> data_block;
			 std::vector<::ISPA_STD::MatchResult<Rules, std::shared_ptr<rule_member>>> rule;
			 std::vector<::ISPA_STD::MatchResult<Rules, rule_nested_rule>> nested_rules;
		};
		struct main {
			 std::variant<::ISPA_STD::Node<Rules, std::shared_ptr<rule>>, ::ISPA_STD::Node<Rules, _use>, ::ISPA_STD::Node<Tokens, NAME>, ::ISPA_STD::Node<Tokens, SPACEMODE>> value;
		};
		struct rule_member {
			 std::variant<::ISPA_STD::Node<Rules, rule_value>, ::ISPA_STD::Node<Rules, rule_keyvalue>> prefix;
			 ::ISPA_STD::MatchResult<Rules, rule_quantifier> quantifier;
			 std::variant<::ISPA_STD::Node<Rules, rule_name>, ::ISPA_STD::Node<Tokens, STRING>, ::ISPA_STD::Node<Tokens, rule_HEX>, ::ISPA_STD::Node<Tokens, DOT>, ::ISPA_STD::Node<Tokens, rule_CSEQUENCE>, ::ISPA_STD::Node<Tokens, rule_BIN>, ::ISPA_STD::Node<Tokens, rule_OP>, ::ISPA_STD::Node<Rules, cll>, ::ISPA_STD::Node<Tokens, rule_ESCAPED>, ::ISPA_STD::Node<Rules, rule_group>, ::ISPA_STD::Node<Tokens, LINEAR_COMMENT>, ::ISPA_STD::Node<Tokens, rule_NOSPACE>> val;
		};
		struct cll_expr_value {
			 std::variant<::ISPA_STD::Node<Rules, std::shared_ptr<rvalue>>, ::ISPA_STD::Node<Rules, std::shared_ptr<cll_function_call>>, ::ISPA_STD::Node<Rules, cll_method_call>, ::ISPA_STD::Node<Rules, cll_expr_group>, ::ISPA_STD::Node<Rules, cll__variable>> value;
		};
		struct cll_stmt {
			 std::vector<::ISPA_STD::MatchResult<Rules, std::shared_ptr<rule_member>>> value;
		};
		struct cll_expr_compare {
			 ::ISPA_STD::MatchResult<Rules, std::shared_ptr<cll_expr_arithmetic>> first;
			 std::vector<::ISPA_STD::Node<Tokens, cll_COMPARE_OP>> operators;
			 std::vector<::ISPA_STD::MatchResult<Rules, std::shared_ptr<cll_expr_arithmetic>>> sequence;
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
		using AUTO_3 = FlatTypes::AUTO_3;
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
			using TEMPLATE = FlatTypes::cll_TEMPLATE;
			using TYPE = FlatTypes::cll_TYPE;
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
	class Lexer : public ::ISPA_STD::Lexer_base<Tokens> {
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_0;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_1;
		static ::ISPA_STD::DFAAPI::CharEmptyState<Tokens, Types::cll::COMPARE_OP> dfa_state_2;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_3;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_4;
		static ::ISPA_STD::DFAAPI::MultiTableState<Tokens, Types::cll::COMPARE_OP, 0, ::ISPA_STD::DFAAPI::MultiTableTransition<Tokens, Types::cll::COMPARE_OP>> dfa_state_5;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_6;
		static ::ISPA_STD::DFAAPI::MultiTableState<Tokens, Types::cll::COMPARE_OP, 0, ::ISPA_STD::DFAAPI::MultiTableTransition<Tokens, Types::cll::COMPARE_OP>> dfa_state_7;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_8;
		static ::ISPA_STD::DFAAPI::CharEmptyState<Tokens, Types::AUTO_5> dfa_state_9;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_10;
		static ::ISPA_STD::DFAAPI::CharEmptyState<Tokens, Types::AUTO_11> dfa_state_11;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_12;
		static ::ISPA_STD::DFAAPI::CharEmptyState<Tokens, Types::MODULO> dfa_state_13;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_14;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_15;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_16;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_17;
		static ::ISPA_STD::DFAAPI::CharEmptyState<Tokens, Types::cll::ASSIGNMENT_OP> dfa_state_18;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_19;
		static ::ISPA_STD::DFAAPI::MultiTableState<Tokens, Types::AUTO_14, 1, ::ISPA_STD::DFAAPI::MultiTableTransition<Tokens, Types::AUTO_14>> dfa_state_20;
		static ::ISPA_STD::DFAAPI::MultiTableEmptyState<Tokens, Types::AUTO_14> dfa_state_21;
		static ::ISPA_STD::DFAAPI::MultiTableEmptyState<Tokens, Types::cll::LOGICAL_OP> dfa_state_22;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_23;
		static ::ISPA_STD::DFAAPI::MultiTableState<Tokens, Types::AUTO_14, 1, ::ISPA_STD::DFAAPI::MultiTableTransition<Tokens, Types::AUTO_14>> dfa_state_24;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_25;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_26;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_27;
		static ::ISPA_STD::DFAAPI::CharEmptyState<Tokens, Types::cll::LOGICAL_OR> dfa_state_28;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_29;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_30;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_31;
		static ::ISPA_STD::DFAAPI::CharEmptyState<Tokens, Types::cll::LOGICAL_AND> dfa_state_32;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_33;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_34;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_35;
		static ::ISPA_STD::DFAAPI::CharEmptyState<Tokens, Types::STRING> dfa_state_36;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_37;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_38;
		static ::ISPA_STD::DFAAPI::CharEmptyState<Tokens, Types::AUTO_3> dfa_state_39;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_40;
		static ::ISPA_STD::DFAAPI::CharEmptyState<Tokens, Types::AUTO_4> dfa_state_41;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_42;
		static ::ISPA_STD::DFAAPI::CharEmptyState<Tokens, Types::MULTIPLE> dfa_state_43;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_44;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_45;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_46;
		static ::ISPA_STD::DFAAPI::CharEmptyState<Tokens, Types::AUTO_21> dfa_state_47;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_48;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_49;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_50;
		static ::ISPA_STD::DFAAPI::CharEmptyState<Tokens, Types::NUMBER> dfa_state_51;
		static ::ISPA_STD::DFAAPI::CharEmptyState<Tokens, Types::PLUS> dfa_state_52;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_53;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_54;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_55;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_56;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_57;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_58;
		static ::ISPA_STD::DFAAPI::CharEmptyState<Tokens, Types::AUTO_1> dfa_state_59;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_60;
		static ::ISPA_STD::DFAAPI::CharEmptyState<Tokens, Types::AUTO_20> dfa_state_61;
		static ::ISPA_STD::DFAAPI::CharEmptyState<Tokens, Types::AUTO_10> dfa_state_62;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_63;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_64;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_65;
		static ::ISPA_STD::DFAAPI::CharEmptyState<Tokens, Types::MINUS> dfa_state_66;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_67;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_68;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_69;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_70;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_71;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_72;
		static ::ISPA_STD::DFAAPI::CharEmptyState<Tokens, Types::DOT> dfa_state_73;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_74;
		static ::ISPA_STD::DFAAPI::CharEmptyState<Tokens, Types::DIVIDE> dfa_state_75;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_76;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_77;
		static ::ISPA_STD::DFAAPI::CharEmptyState<Tokens, Types::LINEAR_COMMENT> dfa_state_78;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_79;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_80;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_81;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_82;
		static ::ISPA_STD::DFAAPI::CharEmptyState<Tokens, Types::rule::BIN> dfa_state_83;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_84;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_85;
		static ::ISPA_STD::DFAAPI::CharEmptyState<Tokens, Types::rule::HEX> dfa_state_86;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_87;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_88;
		static ::ISPA_STD::DFAAPI::CharEmptyState<Tokens, Types::AUTO_6> dfa_state_89;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_90;
		static ::ISPA_STD::DFAAPI::CharEmptyState<Tokens, Types::AUTO_7> dfa_state_91;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_92;
		static ::ISPA_STD::DFAAPI::CharEmptyState<Tokens, Types::AUTO_17> dfa_state_93;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_94;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_95;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_96;
		static ::ISPA_STD::DFAAPI::MultiTableState<Tokens, Types::AUTO_17, 0, ::ISPA_STD::DFAAPI::MultiTableTransition<Tokens, Types::AUTO_17>> dfa_state_97;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_98;
		static ::ISPA_STD::DFAAPI::MultiTableState<Tokens, Types::AUTO_17, 0, ::ISPA_STD::DFAAPI::MultiTableTransition<Tokens, Types::AUTO_17>> dfa_state_99;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_100;
		static ::ISPA_STD::DFAAPI::CharEmptyState<Tokens, Types::QUESTION_MARK> dfa_state_101;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_102;
		static ::ISPA_STD::DFAAPI::CharEmptyState<Tokens, Types::AT> dfa_state_103;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_104;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_105;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_106;
		static ::ISPA_STD::DFAAPI::CharEmptyState<Tokens, Types::ID> dfa_state_107;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_108;
		static ::ISPA_STD::DFAAPI::MultiTableEmptyState<Tokens, Types::rule::CSEQUENCE> dfa_state_109;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_110;
		static ::ISPA_STD::DFAAPI::MultiTableEmptyState<Tokens, Types::AUTO_12> dfa_state_111;
		static ::ISPA_STD::DFAAPI::MultiTableState<Tokens, Types::rule::CSEQUENCE, 1, ::ISPA_STD::DFAAPI::MultiTableTransition<Tokens, Types::rule::CSEQUENCE>> dfa_state_112;
		static ::ISPA_STD::DFAAPI::MultiTableState<Tokens, Types::rule::CSEQUENCE, 3, ::ISPA_STD::DFAAPI::MultiTableTransition<Tokens, Types::rule::CSEQUENCE>> dfa_state_113;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_114;
		static ::ISPA_STD::DFAAPI::MultiTableState<Tokens, Types::rule::CSEQUENCE, 1, ::ISPA_STD::DFAAPI::MultiTableTransition<Tokens, Types::rule::CSEQUENCE>> dfa_state_115;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_116;
		static ::ISPA_STD::DFAAPI::MultiTableState<Tokens, Types::rule::CSEQUENCE, 1, ::ISPA_STD::DFAAPI::MultiTableTransition<Tokens, Types::rule::CSEQUENCE>> dfa_state_117;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_118;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_119;
		static ::ISPA_STD::DFAAPI::CharEmptyState<Tokens, Types::rule::CSEQUENCE::ESCAPE> dfa_state_120;
		static ::ISPA_STD::DFAAPI::MultiTableState<Tokens, Types::rule::CSEQUENCE::DIAPASON, 1, ::ISPA_STD::DFAAPI::MultiTableTransition<Tokens, Types::rule::CSEQUENCE::DIAPASON>> dfa_state_121;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_122;
		static ::ISPA_STD::DFAAPI::MultiTableState<Tokens, Types::rule::CSEQUENCE::DIAPASON, 1, ::ISPA_STD::DFAAPI::MultiTableTransition<Tokens, Types::rule::CSEQUENCE::DIAPASON>> dfa_state_123;
		static ::ISPA_STD::DFAAPI::MultiTableEmptyState<Tokens, Types::rule::CSEQUENCE::DIAPASON, Types::rule::CSEQUENCE> dfa_state_124;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_125;
		static ::ISPA_STD::DFAAPI::CharEmptyState<Tokens, Types::rule::CSEQUENCE::SYMBOL> dfa_state_126;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_127;
		static ::ISPA_STD::DFAAPI::CharEmptyState<Tokens, Types::rule::ESCAPED> dfa_state_128;
		static ::ISPA_STD::DFAAPI::CharEmptyState<Tokens, Types::rule::NOSPACE> dfa_state_129;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_130;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_131;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_132;
		static ::ISPA_STD::DFAAPI::CharEmptyState<Tokens, Types::AUTO_13> dfa_state_133;
		static ::ISPA_STD::DFAAPI::MultiTableState<Tokens, Types::ID, 2, ::ISPA_STD::DFAAPI::MultiTableTransition<Tokens, Types::ID>> dfa_state_134;
		static ::ISPA_STD::DFAAPI::MultiTableEmptyState<Tokens, Types::cll::TYPE> dfa_state_135;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_136;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_137;
		static ::ISPA_STD::DFAAPI::MultiTableState<Tokens, Types::ID, 1, ::ISPA_STD::DFAAPI::MultiTableTransition<Tokens, Types::ID>> dfa_state_138;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_139;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_140;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_141;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_142;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_143;
		static ::ISPA_STD::DFAAPI::MultiTableState<Tokens, Types::ID, 0, ::ISPA_STD::DFAAPI::MultiTableTransition<Tokens, Types::ID>> dfa_state_144;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_145;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_146;
		static ::ISPA_STD::DFAAPI::MultiTableState<Tokens, Types::ID, 1, ::ISPA_STD::DFAAPI::MultiTableTransition<Tokens, Types::ID>> dfa_state_147;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_148;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_149;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_150;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_151;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_152;
		static ::ISPA_STD::DFAAPI::MultiTableState<Tokens, Types::cll::TEMPLATE, 1, ::ISPA_STD::DFAAPI::MultiTableTransition<Tokens, Types::cll::TEMPLATE>> dfa_state_153;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_154;
		static ::ISPA_STD::DFAAPI::MultiTableEmptyState<Tokens, Types::cll::TEMPLATE, Types::ID> dfa_state_155;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_156;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_157;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_158;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_159;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_160;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_161;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_162;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_163;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_164;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_165;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_166;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_167;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_168;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_169;
		static ::ISPA_STD::DFAAPI::CharEmptyState<Tokens, Types::AUTO_18> dfa_state_170;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_171;
		static ::ISPA_STD::DFAAPI::CharEmptyState<Tokens, Types::AUTO_8> dfa_state_172;
		static ::ISPA_STD::DFAAPI::CharEmptyState<Tokens, Types::BOOLEAN> dfa_state_173;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_174;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_175;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_176;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_177;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_178;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_179;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_180;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_181;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_182;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_183;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_184;
		static ::ISPA_STD::DFAAPI::CharEmptyState<Tokens, Types::AUTO_16> dfa_state_185;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_186;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_187;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_188;
		static ::ISPA_STD::DFAAPI::CharEmptyState<Tokens, Types::AUTO_15> dfa_state_189;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_190;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_191;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_192;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_193;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_194;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_195;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_196;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_197;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_198;
		static ::ISPA_STD::DFAAPI::CharEmptyState<Tokens, Types::AUTO_9> dfa_state_199;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_200;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_201;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_202;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_203;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_204;
		static ::ISPA_STD::DFAAPI::MultiTableState<Tokens, Types::NAME, 1, ::ISPA_STD::DFAAPI::MultiTableTransition<Tokens, Types::NAME>> dfa_state_205;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_206;
		static ::ISPA_STD::DFAAPI::MultiTableEmptyState<Tokens, Types::NAME> dfa_state_207;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_208;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_209;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_210;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_211;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_212;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_213;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_214;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_215;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_216;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_217;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_218;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_219;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_220;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_221;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_222;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_223;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_224;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_225;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_226;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_227;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_228;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_229;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_230;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_231;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_232;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_233;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_234;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_235;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_236;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_237;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_238;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_239;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_240;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_241;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_242;
		static ::ISPA_STD::DFAAPI::MultiTableEmptyState<Tokens, Types::SPACEMODE, Types::cll::TEMPLATE> dfa_state_243;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_244;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_245;
		static ::ISPA_STD::DFAAPI::MultiTableState<Tokens, Types::ID, 1, ::ISPA_STD::DFAAPI::MultiTableTransition<Tokens, Types::ID>> dfa_state_246;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_247;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_248;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_249;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_250;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_251;
		static ::ISPA_STD::DFAAPI::MultiTableState<Tokens, Types::ID, 0, ::ISPA_STD::DFAAPI::MultiTableTransition<Tokens, Types::ID>> dfa_state_252;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_253;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_254;
		static ::ISPA_STD::DFAAPI::MultiTableState<Tokens, Types::ID, 1, ::ISPA_STD::DFAAPI::MultiTableTransition<Tokens, Types::ID>> dfa_state_255;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_256;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_257;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_258;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_259;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_260;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_261;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_262;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_263;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_264;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_265;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_266;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_267;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_268;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_269;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_270;
		static ::ISPA_STD::DFAAPI::CharEmptyState<Tokens, Types::AUTO_22> dfa_state_271;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_272;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_273;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_274;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_275;
		static ::ISPA_STD::DFAAPI::MultiTableState<Tokens, Types::AUTO_22, 0, ::ISPA_STD::DFAAPI::MultiTableTransition<Tokens, Types::AUTO_22>> dfa_state_276;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_277;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_278;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_279;
		static ::ISPA_STD::DFAAPI::CharEmptyState<Tokens, Types::AUTO_19> dfa_state_280;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_281;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_282;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_283;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_284;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_285;
		static ::ISPA_STD::DFAAPI::CharEmptyState<Tokens, Types::AUTO_0> dfa_state_286;
		static ::ISPA_STD::DFAAPI::MultiTableState<Tokens, Types::rule::OP, 1, ::ISPA_STD::DFAAPI::MultiTableTransition<Tokens, Types::rule::OP>> dfa_state_287;
		static ::ISPA_STD::DFAAPI::MultiTableEmptyState<Tokens, Types::rule::OP> dfa_state_288;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_289;
		static ::ISPA_STD::DFAAPI::MultiTableState<Tokens, Types::rule::OP, 1, ::ISPA_STD::DFAAPI::MultiTableTransition<Tokens, Types::rule::OP>> dfa_state_290;
		static ::ISPA_STD::DFAAPI::CharState<256> dfa_state_291;
		static ::ISPA_STD::DFAAPI::CharEmptyState<Tokens, Types::AUTO_2> dfa_state_292;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, std::any, 8> dfa_table_0;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, std::any, 2> dfa_table_1;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, std::any, 2> dfa_table_2;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, std::any, 8> dfa_table_3;
		static ::ISPA_STD::DFAAPI::MultiTable<Tokens, std::any, 5> dfa_table_4;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, std::any, 4> dfa_table_5;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, std::any, 5> dfa_table_6;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, std::any, 4> dfa_table_7;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, std::any, 2> dfa_table_8;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, std::any, 2> dfa_table_9;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, std::any, 8> dfa_table_10;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, std::any, 13> dfa_table_11;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, std::any, 2> dfa_table_12;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, std::any, 14> dfa_table_13;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, std::any, 2> dfa_table_14;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, std::any, 11> dfa_table_15;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, std::any, 8> dfa_table_16;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, std::any, 2> dfa_table_17;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, std::any, 2> dfa_table_18;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, std::any, 9> dfa_table_19;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, std::any, 2> dfa_table_20;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, std::any, 2> dfa_table_21;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, std::any, 4> dfa_table_22;
		static ::ISPA_STD::DFAAPI::MultiTable<Tokens, std::any, 10> dfa_table_23;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, std::any, 3> dfa_table_24;
		static ::ISPA_STD::DFAAPI::MultiTable<Tokens, std::any, 4, ::ISPA_STD::DFAAPI::MultiTableTransition<Tokens, Types::rule::CSEQUENCE>> dfa_table_25;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, std::any, 2> dfa_table_26;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, std::any, 5> dfa_table_27;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, std::any, 2> dfa_table_28;
		static ::ISPA_STD::DFAAPI::MultiTable<Tokens, std::any, 23, ::ISPA_STD::DFAAPI::MultiTableTransition<Tokens, ::ISPA_STD::DFAAPI::MultiTableTransition<Tokens, Types::ID>>, ::ISPA_STD::DFAAPI::MultiTableTransition<Tokens, >> dfa_table_29;
		static ::ISPA_STD::DFAAPI::MultiTable<Tokens, std::any, 5, ::ISPA_STD::DFAAPI::MultiTableTransition<Tokens, ::ISPA_STD::DFAAPI::MultiTableTransition<Tokens, Types::cll::TEMPLATE>>> dfa_table_30;
		static ::ISPA_STD::DFAAPI::MultiTable<Tokens, std::any, 5, ::ISPA_STD::DFAAPI::MultiTableTransition<Tokens, ::ISPA_STD::DFAAPI::MultiTableTransition<Tokens, Types::cll::TEMPLATE>>> dfa_table_31;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, std::any, 4> dfa_table_32;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, std::any, 5> dfa_table_33;
		static ::ISPA_STD::DFAAPI::MultiTable<Tokens, std::any, 21, ::ISPA_STD::DFAAPI::MultiTableTransition<Tokens, ::ISPA_STD::DFAAPI::MultiTableTransition<Tokens, Types::ID>>> dfa_table_34;
		static ::ISPA_STD::DFAAPI::MultiTable<Tokens, std::any, 5, ::ISPA_STD::DFAAPI::MultiTableTransition<Tokens, ::ISPA_STD::DFAAPI::MultiTableTransition<Tokens, Types::cll::TEMPLATE>>> dfa_table_35;
		static ::ISPA_STD::DFAAPI::MultiTable<Tokens, std::any, 5, ::ISPA_STD::DFAAPI::MultiTableTransition<Tokens, ::ISPA_STD::DFAAPI::MultiTableTransition<Tokens, Types::cll::TEMPLATE>>> dfa_table_36;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, std::any, 17> dfa_table_37;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, std::any, 12> dfa_table_38;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, std::any, 10> dfa_table_39;
		static ::ISPA_STD::DFAAPI::MultiTable<Tokens, std::any, 26> dfa_table_40;
		static ::ISPA_STD::DFAAPI::MultiTable<Tokens, std::any, 5, ::ISPA_STD::DFAAPI::MultiTableTransition<Tokens, ::ISPA_STD::DFAAPI::MultiTableTransition<Tokens, Types::cll::TEMPLATE>>> dfa_table_41;
		static ::ISPA_STD::DFAAPI::MultiTable<Tokens, std::any, 5, ::ISPA_STD::DFAAPI::MultiTableTransition<Tokens, ::ISPA_STD::DFAAPI::MultiTableTransition<Tokens, Types::cll::TEMPLATE>>> dfa_table_42;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, std::any, 4> dfa_table_43;
		static ::ISPA_STD::DFAAPI::MultiTable<Tokens, std::any, 47, ::ISPA_STD::DFAAPI::MultiTableTransition<Tokens, Types::cll::TEMPLATE>> dfa_table_44;
		static ::ISPA_STD::DFAAPI::MultiTable<Tokens, std::any, 5, ::ISPA_STD::DFAAPI::MultiTableTransition<Tokens, ::ISPA_STD::DFAAPI::MultiTableTransition<Tokens, Types::cll::TEMPLATE>>> dfa_table_45;
		static ::ISPA_STD::DFAAPI::MultiTable<Tokens, std::any, 5, ::ISPA_STD::DFAAPI::MultiTableTransition<Tokens, Types::ID>> dfa_table_46;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, std::any, 12> dfa_table_47;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, std::any, 8> dfa_table_48;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, std::any, 9> dfa_table_49;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, std::any, 2> dfa_table_50;
		static ::ISPA_STD::DFAAPI::MultiTable<Tokens, std::any, 5> dfa_table_51;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, std::any, 4> dfa_table_52;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, std::any, 5> dfa_table_53;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, std::any, 2> dfa_table_54;
	};
	class Parser : public ::ISPA_STD::Parser_base<Tokens, Rules> {
	public: 
		template<typename Iterator>
		auto cll_expr_value(Iterator pos)
		{
			std::variant<::ISPA_STD::Node<Rules, rvalue>, ::ISPA_STD::Node<Rules, cll::function_call>, ::ISPA_STD::Node<Rules, cll::method_call>, ::ISPA_STD::Node<Rules, cll::expr::group>, ::ISPA_STD::Node<Rules, cll::_variable>> _0;
			bool success_1;
			int dfa_lookup_result_2;
			success_1 = true;
			dfa_lookup_result_2 = ISPA_STD::DFA<Tokens>::decide(dfa_span_0, pos, &ISPA_STD::LLParser_base<Tokens, Rules>::PANIC_MODE);
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
		}
		template<typename Iterator>
		auto cll_function_arguments(Iterator pos)
		{
			::ISPA_STD::MatchResult<Rules, cll::expr> _0;
			bool success_1;
			bool success_8;
			bool success_5;
			bool success_3;
			::ISPA_STD::Node<Tokens, AUTO_1> _4;
			std::vector<::ISPA_STD::Node<Tokens, AUTO_1>> shadow_6;
			::ISPA_STD::MatchResult<Rules, cll::expr> _7;
			std::vector<::ISPA_STD::MatchResult<Rules, cll::expr>> shadow_9;
			success_1 = false;
			_0 = cll_expr(pos);
			if (!(_0.status)) {
				return ;
			}
			success_1 = true;
			pos++;
			skip_spaces(pos);
			success_3 = false;
			auto begin_10 = pos;
			while (true) {
				if (!(*begin_10 == Tokens::AUTO_1)) {
					[Error];
					break;
				}
				_4 = *begin_10;
				success_5 = true;
				begin_10++;
				shadow_6.push_back(_4);
				skip_spaces(begin_10);
				_7 = cll_expr(begin_10);
				if (!(_7.status)) {
					break;
				}
				success_8 = true;
				begin_10++;
				shadow_9.push_back(_7);
			}
			if (success_5 && success_8) {
				success_3 = true;
				pos = begin_10;
			}
			skip_spaces(pos);
		}
		template<typename Iterator>
		auto cll_method_call(Iterator pos)
		{
			::ISPA_STD::Node<Tokens, ID> _0;
			bool success_1;
			::ISPA_STD::Node<Tokens, DOT> _2;
			bool success_3;
			::ISPA_STD::MatchResult<Rules, cll::function_call> _4;
			bool success_5;
			success_1 = false;
			if (!(*pos == Tokens::ID)) {
				return ;
			}
			_0 = *pos;
			success_1 = true;
			pos++;
			skip_spaces(pos);
			success_3 = false;
			if (!(*pos == Tokens::DOT)) {
				[Error];
				return ;
			}
			_2 = *pos;
			success_3 = true;
			pos++;
			skip_spaces(pos);
			success_5 = false;
			_4 = cll_function_call(pos);
			if (!(_4.status)) {
				return ;
			}
			success_5 = true;
			pos++;
			skip_spaces(pos);
		}
		template<typename Iterator>
		auto moduleImport_from(Iterator pos)
		{
			std::variant<::ISPA_STD::Node<Rules, moduleImport::from::import_list>, ::ISPA_STD::Node<Tokens, MULTIPLE>> _0;
			bool success_1;
			int dfa_lookup_result_2;
			::ISPA_STD::Node<Tokens, AUTO_8> _3;
			bool success_4;
			::ISPA_STD::Node<Tokens, ID> _5;
			bool success_6;
			success_1 = true;
			dfa_lookup_result_2 = ISPA_STD::DFA<Tokens>::decide(dfa_span_1, pos, &ISPA_STD::LLParser_base<Tokens, Rules>::PANIC_MODE);
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
			if (!(*pos == Tokens::AUTO_8)) {
				[Error];
				return ;
			}
			_3 = *pos;
			success_4 = true;
			pos++;
			skip_spaces(pos);
			success_6 = false;
			if (!(*pos == Tokens::ID)) {
				[Error];
				return ;
			}
			_5 = *pos;
			success_6 = true;
			pos++;
			skip_spaces(pos);
		}
		template<typename Iterator>
		auto cll_function_parameters(Iterator pos)
		{
			::ISPA_STD::Node<Tokens, ID> _0;
			bool success_1;
			bool success_8;
			bool success_5;
			bool success_3;
			::ISPA_STD::Node<Tokens, AUTO_1> _4;
			std::vector<::ISPA_STD::Node<Tokens, AUTO_1>> shadow_6;
			::ISPA_STD::Node<Tokens, ID> _7;
			std::vector<::ISPA_STD::Node<Tokens, ID>> shadow_9;
			success_1 = false;
			if (!(*pos == Tokens::ID)) {
				return ;
			}
			_0 = *pos;
			success_1 = true;
			pos++;
			skip_spaces(pos);
			success_3 = false;
			auto begin_10 = pos;
			while (true) {
				if (!(*begin_10 == Tokens::AUTO_1)) {
					[Error];
					break;
				}
				_4 = *begin_10;
				success_5 = true;
				begin_10++;
				shadow_6.push_back(_4);
				skip_spaces(begin_10);
				if (!(*begin_10 == Tokens::ID)) {
					[Error];
					break;
				}
				_7 = *begin_10;
				success_8 = true;
				begin_10++;
				shadow_9.push_back(_7);
			}
			if (success_5 && success_8) {
				success_3 = true;
				pos = begin_10;
			}
			skip_spaces(pos);
		}
		template<typename Iterator>
		auto rule_quantifier(Iterator pos)
		{
			std::variant<::ISPA_STD::Node<Tokens, MULTIPLE>, ::ISPA_STD::Node<Tokens, PLUS>, ::ISPA_STD::Node<Tokens, QUESTION_MARK>> _0;
			bool success_1;
			int dfa_lookup_result_2;
			success_1 = true;
			dfa_lookup_result_2 = ISPA_STD::DFA<Tokens>::decide(dfa_span_2, pos, &ISPA_STD::LLParser_base<Tokens, Rules>::PANIC_MODE);
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
		}
		template<typename Iterator>
		auto rule_data_block_templated_datablock(Iterator pos)
		{
			::ISPA_STD::Node<Tokens, AT> _0;
			bool success_1;
			::ISPA_STD::Node<Tokens, AUTO_0> _2;
			bool success_3;
			bool success_14;
			bool success_11;
			bool success_7;
			bool success_5;
			::ISPA_STD::Node<Tokens, ID> _6;
			bool success_9;
			::ISPA_STD::Node<Tokens, AUTO_1> _10;
			std::vector<::ISPA_STD::Node<Tokens, AUTO_1>> shadow_12;
			::ISPA_STD::Node<Tokens, ID> _13;
			std::vector<::ISPA_STD::Node<Tokens, ID>> shadow_15;
			::ISPA_STD::Node<Tokens, AUTO_2> _18;
			bool success_19;
			success_1 = false;
			if (!(*pos == Tokens::AT)) {
				return ;
			}
			_0 = *pos;
			success_1 = true;
			pos++;
			skip_spaces(pos);
			success_3 = false;
			if (!(*pos == Tokens::AUTO_0)) {
				[Error];
				return ;
			}
			_2 = *pos;
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
				_6 = *begin_17;
				success_7 = true;
				begin_17++;
				skip_spaces(begin_17);
				success_9 = false;
				auto begin_16 = begin_17;
				while (true) {
					if (!(*begin_16 == Tokens::AUTO_1)) {
						[Error];
						break;
					}
					_10 = *begin_16;
					success_11 = true;
					begin_16++;
					shadow_12.push_back(_10);
					skip_spaces(begin_16);
					if (!(*begin_16 == Tokens::ID)) {
						[Error];
						break;
					}
					_13 = *begin_16;
					success_14 = true;
					begin_16++;
					shadow_15.push_back(_13);
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
			if (!(*pos == Tokens::AUTO_2)) {
				[Error];
				return ;
			}
			_18 = *pos;
			success_19 = true;
			pos++;
			skip_spaces(pos);
		}
		template<typename Iterator>
		auto rule_data_block_regular_datablock(Iterator pos)
		{
			::ISPA_STD::Node<Tokens, AUTO_0> _0;
			bool success_1;
			std::variant<::ISPA_STD::Node<Rules, rule::data_block::regular_datablock::key>, ::ISPA_STD::Node<Rules, cll::expr>> _2;
			bool success_3;
			int dfa_lookup_result_4;
			::ISPA_STD::Node<Tokens, AUTO_2> _5;
			bool success_6;
			success_1 = false;
			if (!(*pos == Tokens::AUTO_0)) {
				return ;
			}
			_0 = *pos;
			success_1 = true;
			pos++;
			skip_spaces(pos);
			success_3 = true;
			dfa_lookup_result_4 = ISPA_STD::DFA<Tokens>::decide(dfa_span_3, pos, &ISPA_STD::LLParser_base<Tokens, Rules>::PANIC_MODE);
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
			if (!(*pos == Tokens::AUTO_2)) {
				[Error];
				return ;
			}
			_5 = *pos;
			success_6 = true;
			pos++;
			skip_spaces(pos);
		}
		template<typename Iterator>
		auto cll_function_body_decl(Iterator pos)
		{
			::ISPA_STD::Node<Tokens, AUTO_3> _0;
			bool success_1;
			::ISPA_STD::MatchResult<Rules, cll::function_parameters> _2;
			bool success_3;
			::ISPA_STD::Node<Tokens, AUTO_4> _4;
			bool success_5;
			success_1 = false;
			if (!(*pos == Tokens::AUTO_3)) {
				return ;
			}
			_0 = *pos;
			success_1 = true;
			pos++;
			skip_spaces(pos);
			success_3 = false;
			_2 = cll_function_parameters(pos);
			if (!(_2.status)) {
				return ;
			}
			success_3 = true;
			pos++;
			skip_spaces(pos);
			success_5 = false;
			if (!(*pos == Tokens::AUTO_4)) {
				[Error];
				return ;
			}
			_4 = *pos;
			success_5 = true;
			pos++;
			skip_spaces(pos);
		}
		template<typename Iterator>
		auto rule_group(Iterator pos)
		{
			::ISPA_STD::Node<Tokens, AUTO_3> _0;
			bool success_1;
			::ISPA_STD::MatchResult<Rules, rule::member> _2;
			bool success_3;
			std::vector<::ISPA_STD::MatchResult<Rules, rule::member>> shadow_4;
			::ISPA_STD::Node<Tokens, AUTO_4> _5;
			bool success_6;
			success_1 = false;
			if (!(*pos == Tokens::AUTO_3)) {
				return ;
			}
			_0 = *pos;
			success_1 = true;
			pos++;
			skip_spaces(pos);
			while (_2.status) {
				success_3 = false;
				_2 = rule_member(pos);
				_2 = rule_member(pos);
				shadow_4.push_back(_2);
			}
			skip_spaces(pos);
			success_6 = false;
			if (!(*pos == Tokens::AUTO_4)) {
				[Error];
				return ;
			}
			_5 = *pos;
			success_6 = true;
			pos++;
			skip_spaces(pos);
		}
		template<typename Iterator>
		auto rule_name(Iterator pos)
		{
			::ISPA_STD::Node<Tokens, AUTO_5> _0;
			bool success_1;
			::ISPA_STD::Node<Tokens, ID> _2;
			bool success_3;
			bool success_10;
			bool success_7;
			bool success_5;
			::ISPA_STD::Node<Tokens, DOT> _6;
			std::vector<::ISPA_STD::Node<Tokens, DOT>> shadow_8;
			::ISPA_STD::Node<Tokens, ID> _9;
			std::vector<::ISPA_STD::Node<Tokens, ID>> shadow_11;
			if (*pos == Tokens::AUTO_5) {
				success_1 = false;
			}
			skip_spaces(pos);
			success_3 = false;
			if (!(*pos == Tokens::ID)) {
				[Error];
				return ;
			}
			_2 = *pos;
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
				_6 = *begin_12;
				success_7 = true;
				begin_12++;
				shadow_8.push_back(_6);
				skip_spaces(begin_12);
				if (!(*begin_12 == Tokens::ID)) {
					[Error];
					break;
				}
				_9 = *begin_12;
				success_10 = true;
				begin_12++;
				shadow_11.push_back(_9);
			}
			if (success_7 && success_10) {
				success_5 = true;
				pos = begin_12;
			}
			skip_spaces(pos);
		}
		template<typename Iterator>
		auto rule_keyvalue(Iterator pos)
		{
			::ISPA_STD::Node<Tokens, AT> _0;
			bool success_1;
			bool success_5;
			bool success_3;
			::ISPA_STD::Node<Tokens, ID> _4;
			success_1 = false;
			if (!(*pos == Tokens::AT)) {
				return ;
			}
			_0 = *pos;
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
				_4 = *begin_6;
				success_5 = true;
				begin_6++;
			}
			if (success_5) {
				success_3 = true;
				pos = begin_6;
			}
			skip_spaces(pos);
		}
		template<typename Iterator>
		auto rule_member(Iterator pos)
		{
			bool success_3;
			std::variant<::ISPA_STD::Node<Rules, rule::value>, ::ISPA_STD::Node<Rules, rule::keyvalue>> _0;
			bool success_1;
			std::variant<::ISPA_STD::Node<Rules, rule::value>, ::ISPA_STD::Node<Rules, rule::keyvalue>> _2;
			int dfa_lookup_result_4;
			std::variant<::ISPA_STD::Node<Rules, rule::name>, ::ISPA_STD::Node<Tokens, STRING>, ::ISPA_STD::Node<Tokens, rule::HEX>, ::ISPA_STD::Node<Tokens, DOT>, ::ISPA_STD::Node<Tokens, rule::CSEQUENCE>, ::ISPA_STD::Node<Tokens, rule::BIN>, ::ISPA_STD::Node<Tokens, rule::OP>, ::ISPA_STD::Node<Rules, cll>, ::ISPA_STD::Node<Tokens, rule::ESCAPED>, ::ISPA_STD::Node<Rules, rule::group>, ::ISPA_STD::Node<Tokens, LINEAR_COMMENT>, ::ISPA_STD::Node<Tokens, rule::NOSPACE>> _6;
			bool success_7;
			int dfa_lookup_result_8;
			::ISPA_STD::MatchResult<Rules, rule::quantifier> _9;
			bool success_10;
			_0 = _2;
			success_1 = false;
			auto begin_5 = pos;
			while (true) {
				dfa_lookup_result_4 = ISPA_STD::DFA<Tokens>::decide(dfa_span_4, pos, &ISPA_STD::LLParser_base<Tokens, Rules>::PANIC_MODE);
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
			dfa_lookup_result_8 = ISPA_STD::DFA<Tokens>::decide(dfa_span_5, pos, &ISPA_STD::LLParser_base<Tokens, Rules>::PANIC_MODE);
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
			if (_9.status) {
				success_10 = false;
				_9 = rule_quantifier(pos);
			}
			skip_spaces(pos);
		}
		template<typename Iterator>
		auto rule(Iterator pos)
		{
			::ISPA_STD::Node<Tokens, ID> _0;
			bool success_1;
			::ISPA_STD::Node<Tokens, AUTO_6> _2;
			bool success_3;
			bool success_7;
			::ISPA_STD::MatchResult<Rules, rule::member> _4;
			bool success_5;
			std::vector<::ISPA_STD::MatchResult<Rules, rule::member>> shadow_6;
			::ISPA_STD::MatchResult<Rules, rule::data_block> _8;
			bool success_9;
			::ISPA_STD::MatchResult<Rules, rule::nested_rule> _10;
			bool success_11;
			std::vector<::ISPA_STD::MatchResult<Rules, rule::nested_rule>> shadow_12;
			::ISPA_STD::Node<Tokens, AUTO_7> _13;
			bool success_14;
			success_1 = false;
			if (!(*pos == Tokens::ID)) {
				return ;
			}
			_0 = *pos;
			success_1 = true;
			pos++;
			skip_spaces(pos);
			success_3 = false;
			if (!(*pos == Tokens::AUTO_6)) {
				[Error];
				return ;
			}
			_2 = *pos;
			success_3 = true;
			pos++;
			skip_spaces(pos);
			success_7 = false;
			while (_4.status) {
				success_5 = false;
				_4 = rule_member(pos);
				_4 = rule_member(pos);
				shadow_6.push_back(_4);
				success_7 = true;
			}
			if (!success_7) {
				[Error];
				return ;
			}
			skip_spaces(pos);
			if (_8.status) {
				success_9 = false;
				_8 = rule_data_block(pos);
			}
			skip_spaces(pos);
			while (_10.status) {
				success_11 = false;
				_10 = rule_nested_rule(pos);
				_10 = rule_nested_rule(pos);
				shadow_12.push_back(_10);
			}
			skip_spaces(pos);
			success_14 = false;
			if (!(*pos == Tokens::AUTO_7)) {
				[Error];
				return ;
			}
			_13 = *pos;
			success_14 = true;
			pos++;
			skip_spaces(pos);
		}
		template<typename Iterator>
		auto _use_unit(Iterator pos)
		{
			::ISPA_STD::Node<Tokens, ID> _0;
			bool success_1;
			::ISPA_STD::MatchResult<Rules, rvalue> _2;
			bool success_3;
			success_1 = false;
			if (!(*pos == Tokens::ID)) {
				return ;
			}
			_0 = *pos;
			success_1 = true;
			pos++;
			skip_spaces(pos);
			if (_2.status) {
				success_3 = false;
				_2 = rvalue(pos);
			}
			skip_spaces(pos);
		}
		template<typename Iterator>
		auto main(Iterator pos)
		{
			bool success_3;
			std::variant<::ISPA_STD::Node<Rules, rule>, ::ISPA_STD::Node<Rules, _use>, ::ISPA_STD::Node<Tokens, NAME>, ::ISPA_STD::Node<Tokens, SPACEMODE>> _0;
			bool success_1;
			bool success_7;
			std::variant<::ISPA_STD::Node<Rules, rule>, ::ISPA_STD::Node<Rules, _use>, ::ISPA_STD::Node<Tokens, NAME>, ::ISPA_STD::Node<Tokens, SPACEMODE>> _2;
			int dfa_lookup_result_4;
			std::vector<std::variant<::ISPA_STD::Node<Rules, rule>, ::ISPA_STD::Node<Rules, _use>, ::ISPA_STD::Node<Tokens, NAME>, ::ISPA_STD::Node<Tokens, SPACEMODE>>> shadow_6;
			_0 = _2;
			success_1 = false;
			auto begin_5 = pos;
			success_7 = false;
			while (true) {
				dfa_lookup_result_4 = ISPA_STD::DFA<Tokens>::decide(dfa_span_6, pos, &ISPA_STD::LLParser_base<Tokens, Rules>::PANIC_MODE);
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
				shadow_6.push_back(_0);
			}
			skip_spaces(pos);
		}
		template<typename Iterator>
		auto moduleImport_from_import_list(Iterator pos)
		{
			::ISPA_STD::Node<Tokens, ID> _0;
			bool success_1;
			bool success_8;
			bool success_5;
			bool success_3;
			::ISPA_STD::Node<Tokens, AUTO_1> _4;
			std::vector<::ISPA_STD::Node<Tokens, AUTO_1>> shadow_6;
			::ISPA_STD::Node<Tokens, ID> _7;
			std::vector<::ISPA_STD::Node<Tokens, ID>> shadow_9;
			success_1 = false;
			if (!(*pos == Tokens::ID)) {
				return ;
			}
			_0 = *pos;
			success_1 = true;
			pos++;
			skip_spaces(pos);
			success_3 = false;
			auto begin_10 = pos;
			while (true) {
				if (!(*begin_10 == Tokens::AUTO_1)) {
					[Error];
					break;
				}
				_4 = *begin_10;
				success_5 = true;
				begin_10++;
				shadow_6.push_back(_4);
				skip_spaces(begin_10);
				if (!(*begin_10 == Tokens::ID)) {
					[Error];
					break;
				}
				_7 = *begin_10;
				success_8 = true;
				begin_10++;
				shadow_9.push_back(_7);
			}
			if (success_5 && success_8) {
				success_3 = true;
				pos = begin_10;
			}
			skip_spaces(pos);
		}
		template<typename Iterator>
		auto cll_expr_compare(Iterator pos)
		{
			::ISPA_STD::MatchResult<Rules, cll::expr::arithmetic> _0;
			bool success_1;
			bool success_8;
			bool success_5;
			bool success_3;
			::ISPA_STD::Node<Tokens, cll::COMPARE_OP> _4;
			std::vector<::ISPA_STD::Node<Tokens, cll::COMPARE_OP>> shadow_6;
			::ISPA_STD::MatchResult<Rules, cll::expr::arithmetic> _7;
			std::vector<::ISPA_STD::MatchResult<Rules, cll::expr::arithmetic>> shadow_9;
			success_1 = false;
			_0 = cll_expr_arithmetic(pos);
			if (!(_0.status)) {
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
				_4 = *begin_10;
				success_5 = true;
				begin_10++;
				shadow_6.push_back(_4);
				skip_spaces(begin_10);
				_7 = cll_expr_arithmetic(begin_10);
				if (!(_7.status)) {
					break;
				}
				success_8 = true;
				begin_10++;
				shadow_9.push_back(_7);
			}
			if (success_5 && success_8) {
				success_3 = true;
				pos = begin_10;
			}
			skip_spaces(pos);
		}
		template<typename Iterator>
		auto moduleDeclaration(Iterator pos)
		{
			::ISPA_STD::Node<Tokens, AUTO_9> _0;
			bool success_1;
			::ISPA_STD::Node<Tokens, ID> _2;
			bool success_3;
			bool success_9;
			bool success_7;
			bool success_5;
			::ISPA_STD::Node<Tokens, AUTO_10> _6;
			::ISPA_STD::Node<Tokens, ID> _8;
			::ISPA_STD::Node<Tokens, AUTO_7> _11;
			bool success_12;
			success_1 = false;
			if (!(*pos == Tokens::AUTO_9)) {
				return ;
			}
			_0 = *pos;
			success_1 = true;
			pos++;
			skip_spaces(pos);
			success_3 = false;
			if (!(*pos == Tokens::ID)) {
				[Error];
				return ;
			}
			_2 = *pos;
			success_3 = true;
			pos++;
			skip_spaces(pos);
			success_5 = false;
			auto begin_10 = pos;
			while (true) {
				if (!(*begin_10 == Tokens::AUTO_10)) {
					[Error];
					break;
				}
				_6 = *begin_10;
				success_7 = true;
				begin_10++;
				skip_spaces(begin_10);
				if (!(*begin_10 == Tokens::ID)) {
					[Error];
					break;
				}
				_8 = *begin_10;
				success_9 = true;
				begin_10++;
			}
			if (success_7 && success_9) {
				success_5 = true;
				pos = begin_10;
			}
			skip_spaces(pos);
			success_12 = false;
			if (!(*pos == Tokens::AUTO_7)) {
				[Error];
				return ;
			}
			_11 = *pos;
			success_12 = true;
			pos++;
			skip_spaces(pos);
		}
		template<typename Iterator>
		auto cll_stmt(Iterator pos)
		{
			::ISPA_STD::Node<Tokens, AUTO_0> _0;
			bool success_1;
			::ISPA_STD::MatchResult<Rules, rule::member> _2;
			bool success_3;
			std::vector<::ISPA_STD::MatchResult<Rules, rule::member>> shadow_4;
			::ISPA_STD::Node<Tokens, AUTO_2> _5;
			bool success_6;
			success_1 = false;
			if (!(*pos == Tokens::AUTO_0)) {
				return ;
			}
			_0 = *pos;
			success_1 = true;
			pos++;
			skip_spaces(pos);
			while (_2.status) {
				success_3 = false;
				_2 = rule_member(pos);
				_2 = rule_member(pos);
				shadow_4.push_back(_2);
			}
			skip_spaces(pos);
			success_6 = false;
			if (!(*pos == Tokens::AUTO_2)) {
				[Error];
				return ;
			}
			_5 = *pos;
			success_6 = true;
			pos++;
			skip_spaces(pos);
		}
		template<typename Iterator>
		auto cll(Iterator pos)
		{
			::ISPA_STD::Node<Tokens, AUTO_11> _0;
			bool success_1;
			std::variant<::ISPA_STD::Node<Rules, cll::_if>, ::ISPA_STD::Node<Rules, cll::loop_for>, ::ISPA_STD::Node<Rules, cll::_var>, ::ISPA_STD::Node<Rules, cll::expr>, ::ISPA_STD::Node<Rules, cll::loop_while>> _2;
			bool success_3;
			int dfa_lookup_result_4;
			::ISPA_STD::Node<Tokens, AUTO_7> _5;
			bool success_6;
			success_1 = false;
			if (!(*pos == Tokens::AUTO_11)) {
				return ;
			}
			_0 = *pos;
			success_1 = true;
			pos++;
			skip_spaces(pos);
			success_3 = true;
			dfa_lookup_result_4 = ISPA_STD::DFA<Tokens>::decide(dfa_span_7, pos, &ISPA_STD::LLParser_base<Tokens, Rules>::PANIC_MODE);
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
			if (!(*pos == Tokens::AUTO_7)) {
				[Error];
				return ;
			}
			_5 = *pos;
			success_6 = true;
			pos++;
			skip_spaces(pos);
		}
		template<typename Iterator>
		auto cll_expr_group(Iterator pos)
		{
			::ISPA_STD::Node<Tokens, AUTO_3> _0;
			bool success_1;
			::ISPA_STD::MatchResult<Rules, cll::expr> _2;
			bool success_3;
			::ISPA_STD::Node<Tokens, AUTO_4> _4;
			bool success_5;
			success_1 = false;
			if (!(*pos == Tokens::AUTO_3)) {
				return ;
			}
			_0 = *pos;
			success_1 = true;
			pos++;
			skip_spaces(pos);
			success_3 = false;
			_2 = cll_expr(pos);
			if (!(_2.status)) {
				return ;
			}
			success_3 = true;
			pos++;
			skip_spaces(pos);
			success_5 = false;
			if (!(*pos == Tokens::AUTO_4)) {
				[Error];
				return ;
			}
			_4 = *pos;
			success_5 = true;
			pos++;
			skip_spaces(pos);
		}
		template<typename Iterator>
		auto rvalue(Iterator pos)
		{
			std::variant<::ISPA_STD::Node<Tokens, ID>, ::ISPA_STD::Node<Tokens, BOOLEAN>, ::ISPA_STD::Node<Tokens, STRING>, ::ISPA_STD::Node<Tokens, AT>, ::ISPA_STD::Node<Tokens, NUMBER>, ::ISPA_STD::Node<Rules, object>, ::ISPA_STD::Node<Rules, array>> _0;
			bool success_1;
			int dfa_lookup_result_2;
			success_1 = true;
			dfa_lookup_result_2 = ISPA_STD::DFA<Tokens>::decide(dfa_span_8, pos, &ISPA_STD::LLParser_base<Tokens, Rules>::PANIC_MODE);
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
		}
		template<typename Iterator>
		auto array(Iterator pos)
		{
			::ISPA_STD::Node<Tokens, AUTO_12> _0;
			bool success_1;
			bool success_10;
			bool success_7;
			bool success_3;
			bool success_5;
			::ISPA_STD::MatchResult<Rules, cll::expr> _6;
			std::vector<::ISPA_STD::MatchResult<Rules, cll::expr>> shadow_8;
			::ISPA_STD::Node<Tokens, AUTO_1> _9;
			std::vector<::ISPA_STD::Node<Tokens, AUTO_1>> shadow_11;
			::ISPA_STD::Node<Tokens, AUTO_13> _14;
			bool success_15;
			success_1 = false;
			if (!(*pos == Tokens::AUTO_12)) {
				return ;
			}
			_0 = *pos;
			success_1 = true;
			pos++;
			skip_spaces(pos);
			success_3 = false;
			auto begin_13 = pos;
			while (true) {
				success_5 = false;
				auto begin_12 = begin_13;
				while (true) {
					_6 = cll_expr(begin_12);
					if (!(_6.status)) {
						break;
					}
					success_7 = true;
					begin_12++;
					shadow_8.push_back(_6);
					skip_spaces(begin_12);
					if (!(*begin_12 == Tokens::AUTO_1)) {
						[Error];
						break;
					}
					_9 = *begin_12;
					success_10 = true;
					begin_12++;
					shadow_11.push_back(_9);
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
			if (!(*pos == Tokens::AUTO_13)) {
				[Error];
				return ;
			}
			_14 = *pos;
			success_15 = true;
			pos++;
			skip_spaces(pos);
		}
		template<typename Iterator>
		auto cll__variable(Iterator pos)
		{
			bool success_3;
			std::variant<::ISPA_STD::Node<Tokens, AUTO_21>, ::ISPA_STD::Node<Tokens, AUTO_20>> _0;
			bool success_1;
			std::variant<::ISPA_STD::Node<Tokens, AUTO_21>, ::ISPA_STD::Node<Tokens, AUTO_20>> _2;
			int dfa_lookup_result_4;
			::ISPA_STD::Node<Tokens, ID> _6;
			bool success_7;
			bool success_15;
			bool success_13;
			bool success_11;
			bool success_9;
			::ISPA_STD::Node<Tokens, AUTO_12> _10;
			::ISPA_STD::MatchResult<Rules, cll::expr> _12;
			::ISPA_STD::Node<Tokens, AUTO_13> _14;
			bool success_20;
			std::variant<::ISPA_STD::Node<Tokens, AUTO_21>, ::ISPA_STD::Node<Tokens, AUTO_20>> _17;
			bool success_18;
			std::variant<::ISPA_STD::Node<Tokens, AUTO_21>, ::ISPA_STD::Node<Tokens, AUTO_20>> _19;
			int dfa_lookup_result_21;
			_0 = _2;
			success_1 = false;
			auto begin_5 = pos;
			while (true) {
				dfa_lookup_result_4 = ISPA_STD::DFA<Tokens>::decide(dfa_span_9, pos, &ISPA_STD::LLParser_base<Tokens, Rules>::PANIC_MODE);
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
			_6 = *pos;
			success_7 = true;
			pos++;
			skip_spaces(pos);
			success_9 = false;
			auto begin_16 = pos;
			while (true) {
				if (!(*begin_16 == Tokens::AUTO_12)) {
					[Error];
					break;
				}
				_10 = *begin_16;
				success_11 = true;
				begin_16++;
				skip_spaces(begin_16);
				_12 = cll_expr(begin_16);
				if (!(_12.status)) {
					break;
				}
				success_13 = true;
				begin_16++;
				skip_spaces(begin_16);
				if (!(*begin_16 == Tokens::AUTO_13)) {
					[Error];
					break;
				}
				_14 = *begin_16;
				success_15 = true;
				begin_16++;
			}
			if (success_11 && success_13 && success_15) {
				success_9 = true;
				pos = begin_16;
			}
			skip_spaces(pos);
			_17 = _19;
			success_18 = false;
			auto begin_22 = pos;
			while (true) {
				dfa_lookup_result_21 = ISPA_STD::DFA<Tokens>::decide(dfa_span_10, pos, &ISPA_STD::LLParser_base<Tokens, Rules>::PANIC_MODE);
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
		}
		template<typename Iterator>
		auto object(Iterator pos)
		{
			::ISPA_STD::Node<Tokens, AUTO_0> _0;
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
			std::variant<::ISPA_STD::Node<Tokens, NUMBER>, ::ISPA_STD::Node<Tokens, ID>> _4;
			int dfa_lookup_result_6;
			::ISPA_STD::Node<Tokens, AUTO_6> _7;
			::ISPA_STD::MatchResult<Rules, cll::expr> _9;
			bool success_12;
			::ISPA_STD::Node<Tokens, AUTO_1> _13;
			std::vector<::ISPA_STD::Node<Tokens, AUTO_1>> shadow_15;
			std::variant<::ISPA_STD::Node<Tokens, NUMBER>, ::ISPA_STD::Node<Tokens, ID>> _16;
			int dfa_lookup_result_18;
			::ISPA_STD::Node<Tokens, AUTO_6> _19;
			std::vector<::ISPA_STD::Node<Tokens, AUTO_6>> shadow_21;
			::ISPA_STD::MatchResult<Rules, cll::expr> _22;
			std::vector<::ISPA_STD::MatchResult<Rules, cll::expr>> shadow_24;
			::ISPA_STD::Node<Tokens, AUTO_7> _26;
			::ISPA_STD::Node<Tokens, AUTO_2> _29;
			bool success_30;
			success_1 = false;
			if (!(*pos == Tokens::AUTO_0)) {
				return ;
			}
			_0 = *pos;
			success_1 = true;
			pos++;
			skip_spaces(pos);
			success_3 = false;
			auto begin_28 = pos;
			while (true) {
				dfa_lookup_result_6 = ISPA_STD::DFA<Tokens>::decide(dfa_span_11, pos, &ISPA_STD::LLParser_base<Tokens, Rules>::PANIC_MODE);
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
				if (!(*begin_28 == Tokens::AUTO_6)) {
					[Error];
					break;
				}
				_7 = *begin_28;
				success_8 = true;
				begin_28++;
				skip_spaces(begin_28);
				_9 = cll_expr(begin_28);
				if (!(_9.status)) {
					break;
				}
				success_10 = true;
				begin_28++;
				skip_spaces(begin_28);
				success_12 = false;
				auto begin_25 = begin_28;
				while (true) {
					if (!(*begin_25 == Tokens::AUTO_1)) {
						[Error];
						break;
					}
					_13 = *begin_25;
					success_14 = true;
					begin_25++;
					shadow_15.push_back(_13);
					skip_spaces(begin_25);
					dfa_lookup_result_18 = ISPA_STD::DFA<Tokens>::decide(dfa_span_12, pos, &ISPA_STD::LLParser_base<Tokens, Rules>::PANIC_MODE);
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
					if (!(*begin_25 == Tokens::AUTO_6)) {
						[Error];
						break;
					}
					_19 = *begin_25;
					success_20 = true;
					begin_25++;
					shadow_21.push_back(_19);
					skip_spaces(begin_25);
					_22 = cll_expr(begin_25);
					if (!(_22.status)) {
						break;
					}
					success_23 = true;
					begin_25++;
					shadow_24.push_back(_22);
				}
				if (success_14 && success_17 && success_20 && success_23) {
					success_12 = true;
					begin_28 = begin_25;
				}
				skip_spaces(begin_28);
				if (!(*begin_28 == Tokens::AUTO_7)) {
					[Error];
					break;
				}
				_26 = *begin_28;
				success_27 = true;
				begin_28++;
			}
			if (success_5 && success_8 && success_10 && success_14 && success_17 && success_20 && success_23 && success_27) {
				success_3 = true;
				pos = begin_28;
			}
			skip_spaces(pos);
			success_30 = false;
			if (!(*pos == Tokens::AUTO_2)) {
				[Error];
				return ;
			}
			_29 = *pos;
			success_30 = true;
			pos++;
			skip_spaces(pos);
		}
		template<typename Iterator>
		auto cll__var(Iterator pos)
		{
			::ISPA_STD::Node<Tokens, cll::TYPE> _0;
			bool success_1;
			::ISPA_STD::Node<Tokens, ID> _2;
			bool success_3;
			bool success_9;
			bool success_7;
			bool success_5;
			::ISPA_STD::Node<Tokens, cll::ASSIGNMENT_OP> _6;
			::ISPA_STD::MatchResult<Rules, cll::expr> _8;
			if (*pos == Tokens::cll::TYPE) {
				success_1 = false;
			}
			skip_spaces(pos);
			success_3 = false;
			if (!(*pos == Tokens::ID)) {
				[Error];
				return ;
			}
			_2 = *pos;
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
				_6 = *begin_10;
				success_7 = true;
				begin_10++;
				skip_spaces(begin_10);
				_8 = cll_expr(begin_10);
				if (!(_8.status)) {
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
		}
		template<typename Iterator>
		auto cll_expr_logical(Iterator pos)
		{
			::ISPA_STD::MatchResult<Rules, cll::expr::compare> _0;
			bool success_1;
			bool success_8;
			bool success_5;
			bool success_3;
			::ISPA_STD::Node<Tokens, cll::LOGICAL_OP> _4;
			std::vector<::ISPA_STD::Node<Tokens, cll::LOGICAL_OP>> shadow_6;
			::ISPA_STD::MatchResult<Rules, cll::expr::compare> _7;
			std::vector<::ISPA_STD::MatchResult<Rules, cll::expr::compare>> shadow_9;
			success_1 = false;
			_0 = cll_expr_compare(pos);
			if (!(_0.status)) {
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
				_4 = *begin_10;
				success_5 = true;
				begin_10++;
				shadow_6.push_back(_4);
				skip_spaces(begin_10);
				_7 = cll_expr_compare(begin_10);
				if (!(_7.status)) {
					break;
				}
				success_8 = true;
				begin_10++;
				shadow_9.push_back(_7);
			}
			if (success_5 && success_8) {
				success_3 = true;
				pos = begin_10;
			}
			skip_spaces(pos);
		}
		template<typename Iterator>
		auto cll_expr_term(Iterator pos)
		{
			::ISPA_STD::MatchResult<Rules, cll::expr::value> _0;
			bool success_1;
			bool success_8;
			bool success_5;
			bool success_3;
			std::variant<::ISPA_STD::Node<Tokens, MODULO>, ::ISPA_STD::Node<Tokens, MULTIPLE>, ::ISPA_STD::Node<Tokens, DIVIDE>> _4;
			int dfa_lookup_result_6;
			::ISPA_STD::MatchResult<Rules, cll::expr::value> _7;
			std::vector<::ISPA_STD::MatchResult<Rules, cll::expr::value>> shadow_9;
			success_1 = false;
			_0 = cll_expr_value(pos);
			if (!(_0.status)) {
				return ;
			}
			success_1 = true;
			pos++;
			skip_spaces(pos);
			success_3 = false;
			auto begin_10 = pos;
			while (true) {
				dfa_lookup_result_6 = ISPA_STD::DFA<Tokens>::decide(dfa_span_13, pos, &ISPA_STD::LLParser_base<Tokens, Rules>::PANIC_MODE);
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
				_7 = cll_expr_value(begin_10);
				if (!(_7.status)) {
					break;
				}
				success_8 = true;
				begin_10++;
				shadow_9.push_back(_7);
			}
			if (success_5 && success_8) {
				success_3 = true;
				pos = begin_10;
			}
			skip_spaces(pos);
		}
		template<typename Iterator>
		auto cll_expr(Iterator pos)
		{
			::ISPA_STD::MatchResult<Rules, cll::expr::logical> _0;
			bool success_1;
			success_1 = false;
			_0 = cll_expr_logical(pos);
			if (!(_0.status)) {
				return ;
			}
			success_1 = true;
			pos++;
			skip_spaces(pos);
		}
		template<typename Iterator>
		auto cll_function_call(Iterator pos)
		{
			::ISPA_STD::Node<Tokens, ID> _0;
			bool success_1;
			::ISPA_STD::MatchResult<Rules, cll::function_body_call> _2;
			bool success_3;
			success_1 = false;
			if (!(*pos == Tokens::ID)) {
				return ;
			}
			_0 = *pos;
			success_1 = true;
			pos++;
			skip_spaces(pos);
			success_3 = false;
			_2 = cll_function_body_call(pos);
			if (!(_2.status)) {
				return ;
			}
			success_3 = true;
			pos++;
			skip_spaces(pos);
		}
		template<typename Iterator>
		auto rule_value(Iterator pos)
		{
			::ISPA_STD::Node<Tokens, AUTO_14> _0;
			bool success_1;
			::ISPA_STD::Node<Tokens, ID> _2;
			bool success_3;
			success_1 = false;
			if (!(*pos == Tokens::AUTO_14)) {
				return ;
			}
			_0 = *pos;
			success_1 = true;
			pos++;
			skip_spaces(pos);
			success_3 = false;
			if (!(*pos == Tokens::ID)) {
				[Error];
				return ;
			}
			_2 = *pos;
			success_3 = true;
			pos++;
			skip_spaces(pos);
		}
		template<typename Iterator>
		auto rule_data_block(Iterator pos)
		{
			std::variant<::ISPA_STD::Node<Rules, rule::data_block::templated_datablock>, ::ISPA_STD::Node<Rules, rule::data_block::regular_datablock>> _0;
			bool success_1;
			int dfa_lookup_result_2;
			success_1 = true;
			dfa_lookup_result_2 = ISPA_STD::DFA<Tokens>::decide(dfa_span_14, pos, &ISPA_STD::LLParser_base<Tokens, Rules>::PANIC_MODE);
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
		}
		template<typename Iterator>
		auto moduleImport(Iterator pos)
		{
			::ISPA_STD::Node<Tokens, AUTO_15> _0;
			bool success_1;
			std::variant<::ISPA_STD::Node<Rules, moduleImport::from>, ::ISPA_STD::Node<Tokens, ID>> _2;
			bool success_3;
			int dfa_lookup_result_4;
			success_1 = false;
			if (!(*pos == Tokens::AUTO_15)) {
				return ;
			}
			_0 = *pos;
			success_1 = true;
			pos++;
			skip_spaces(pos);
			success_3 = true;
			dfa_lookup_result_4 = ISPA_STD::DFA<Tokens>::decide(dfa_span_15, pos, &ISPA_STD::LLParser_base<Tokens, Rules>::PANIC_MODE);
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
		}
		template<typename Iterator>
		auto rule_nested_rule(Iterator pos)
		{
			::ISPA_STD::Node<Tokens, AUTO_5> _0;
			bool success_1;
			::ISPA_STD::MatchResult<Rules, rule> _2;
			bool success_3;
			success_1 = false;
			if (!(*pos == Tokens::AUTO_5)) {
				return ;
			}
			_0 = *pos;
			success_1 = true;
			pos++;
			skip_spaces(pos);
			success_3 = false;
			_2 = rule(pos);
			if (!(_2.status)) {
				return ;
			}
			success_3 = true;
			pos++;
			skip_spaces(pos);
		}
		template<typename Iterator>
		auto cll_function_body_call(Iterator pos)
		{
			::ISPA_STD::Node<Tokens, AUTO_3> _0;
			bool success_1;
			::ISPA_STD::MatchResult<Rules, cll::function_arguments> _2;
			bool success_3;
			::ISPA_STD::Node<Tokens, AUTO_4> _4;
			bool success_5;
			success_1 = false;
			if (!(*pos == Tokens::AUTO_3)) {
				return ;
			}
			_0 = *pos;
			success_1 = true;
			pos++;
			skip_spaces(pos);
			success_3 = false;
			_2 = cll_function_arguments(pos);
			if (!(_2.status)) {
				return ;
			}
			success_3 = true;
			pos++;
			skip_spaces(pos);
			success_5 = false;
			if (!(*pos == Tokens::AUTO_4)) {
				[Error];
				return ;
			}
			_4 = *pos;
			success_5 = true;
			pos++;
			skip_spaces(pos);
		}
		template<typename Iterator>
		auto cll_expr_arithmetic(Iterator pos)
		{
			::ISPA_STD::MatchResult<Rules, cll::expr::term> _0;
			bool success_1;
			bool success_8;
			bool success_5;
			bool success_3;
			std::variant<::ISPA_STD::Node<Tokens, PLUS>, ::ISPA_STD::Node<Tokens, MINUS>> _4;
			int dfa_lookup_result_6;
			::ISPA_STD::MatchResult<Rules, cll::expr::term> _7;
			std::vector<::ISPA_STD::MatchResult<Rules, cll::expr::term>> shadow_9;
			success_1 = false;
			_0 = cll_expr_term(pos);
			if (!(_0.status)) {
				return ;
			}
			success_1 = true;
			pos++;
			skip_spaces(pos);
			success_3 = false;
			auto begin_10 = pos;
			while (true) {
				dfa_lookup_result_6 = ISPA_STD::DFA<Tokens>::decide(dfa_span_16, pos, &ISPA_STD::LLParser_base<Tokens, Rules>::PANIC_MODE);
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
				_7 = cll_expr_term(begin_10);
				if (!(_7.status)) {
					break;
				}
				success_8 = true;
				begin_10++;
				shadow_9.push_back(_7);
			}
			if (success_5 && success_8) {
				success_3 = true;
				pos = begin_10;
			}
			skip_spaces(pos);
		}
		template<typename Iterator>
		auto cll__if(Iterator pos)
		{
			::ISPA_STD::Node<Tokens, AUTO_16> _0;
			bool success_1;
			::ISPA_STD::MatchResult<Rules, cll::expr> _2;
			bool success_3;
			::ISPA_STD::MatchResult<Rules, cll::stmt> _4;
			bool success_5;
			success_1 = false;
			if (!(*pos == Tokens::AUTO_16)) {
				return ;
			}
			_0 = *pos;
			success_1 = true;
			pos++;
			skip_spaces(pos);
			success_3 = false;
			_2 = cll_expr(pos);
			if (!(_2.status)) {
				return ;
			}
			success_3 = true;
			pos++;
			skip_spaces(pos);
			success_5 = false;
			_4 = cll_stmt(pos);
			if (!(_4.status)) {
				return ;
			}
			success_5 = true;
			pos++;
			skip_spaces(pos);
		}
		template<typename Iterator>
		auto rule_data_block_regular_datablock_key(Iterator pos)
		{
			::ISPA_STD::Node<Tokens, ID> _0;
			bool success_1;
			::ISPA_STD::Node<Tokens, AUTO_17> _2;
			bool success_3;
			::ISPA_STD::MatchResult<Rules, cll::expr> _4;
			bool success_5;
			success_1 = false;
			if (!(*pos == Tokens::ID)) {
				return ;
			}
			_0 = *pos;
			success_1 = true;
			pos++;
			skip_spaces(pos);
			success_3 = false;
			if (!(*pos == Tokens::AUTO_17)) {
				[Error];
				return ;
			}
			_2 = *pos;
			success_3 = true;
			pos++;
			skip_spaces(pos);
			success_5 = false;
			_4 = cll_expr(pos);
			if (!(_4.status)) {
				return ;
			}
			success_5 = true;
			pos++;
			skip_spaces(pos);
		}
		template<typename Iterator>
		auto cll_loop_for(Iterator pos)
		{
			::ISPA_STD::Node<Tokens, AUTO_18> _0;
			bool success_1;
			::ISPA_STD::Node<Tokens, AUTO_3> _2;
			bool success_3;
			bool success_7;
			std::variant<::ISPA_STD::Node<Rules, cll::_var>, ::ISPA_STD::Node<Rules, cll::expr>> _4;
			bool success_5;
			std::variant<::ISPA_STD::Node<Rules, cll::_var>, ::ISPA_STD::Node<Rules, cll::expr>> _6;
			int dfa_lookup_result_8;
			::ISPA_STD::Node<Tokens, AUTO_7> _10;
			bool success_11;
			::ISPA_STD::MatchResult<Rules, cll::expr> _12;
			bool success_13;
			::ISPA_STD::Node<Tokens, AUTO_7> _14;
			bool success_15;
			::ISPA_STD::MatchResult<Rules, cll::expr> _16;
			bool success_17;
			::ISPA_STD::Node<Tokens, AUTO_4> _18;
			bool success_19;
			::ISPA_STD::MatchResult<Rules, cll::stmt> _20;
			bool success_21;
			success_1 = false;
			if (!(*pos == Tokens::AUTO_18)) {
				return ;
			}
			_0 = *pos;
			success_1 = true;
			pos++;
			skip_spaces(pos);
			success_3 = false;
			if (!(*pos == Tokens::AUTO_3)) {
				[Error];
				return ;
			}
			_2 = *pos;
			success_3 = true;
			pos++;
			skip_spaces(pos);
			_4 = _6;
			success_5 = false;
			auto begin_9 = pos;
			while (true) {
				dfa_lookup_result_8 = ISPA_STD::DFA<Tokens>::decide(dfa_span_17, pos, &ISPA_STD::LLParser_base<Tokens, Rules>::PANIC_MODE);
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
			if (!(*pos == Tokens::AUTO_7)) {
				[Error];
				return ;
			}
			_10 = *pos;
			success_11 = true;
			pos++;
			skip_spaces(pos);
			if (_12.status) {
				success_13 = false;
				_12 = cll_expr(pos);
			}
			skip_spaces(pos);
			success_15 = false;
			if (!(*pos == Tokens::AUTO_7)) {
				[Error];
				return ;
			}
			_14 = *pos;
			success_15 = true;
			pos++;
			skip_spaces(pos);
			if (_16.status) {
				success_17 = false;
				_16 = cll_expr(pos);
			}
			skip_spaces(pos);
			success_19 = false;
			if (!(*pos == Tokens::AUTO_4)) {
				[Error];
				return ;
			}
			_18 = *pos;
			success_19 = true;
			pos++;
			skip_spaces(pos);
			success_21 = false;
			_20 = cll_stmt(pos);
			if (!(_20.status)) {
				return ;
			}
			success_21 = true;
			pos++;
			skip_spaces(pos);
		}
		template<typename Iterator>
		auto cll_loop_while(Iterator pos)
		{
			::ISPA_STD::Node<Tokens, AUTO_19> _0;
			bool success_1;
			::ISPA_STD::MatchResult<Rules, cll::expr> _2;
			bool success_3;
			::ISPA_STD::MatchResult<Rules, cll::stmt> _4;
			bool success_5;
			success_1 = false;
			if (!(*pos == Tokens::AUTO_19)) {
				return ;
			}
			_0 = *pos;
			success_1 = true;
			pos++;
			skip_spaces(pos);
			success_3 = false;
			_2 = cll_expr(pos);
			if (!(_2.status)) {
				return ;
			}
			success_3 = true;
			pos++;
			skip_spaces(pos);
			success_5 = false;
			_4 = cll_stmt(pos);
			if (!(_4.status)) {
				return ;
			}
			success_5 = true;
			pos++;
			skip_spaces(pos);
		}
		template<typename Iterator>
		auto _use(Iterator pos)
		{
			::ISPA_STD::Node<Tokens, AUTO_22> _0;
			bool success_1;
			::ISPA_STD::MatchResult<Rules, _use::unit> _2;
			bool success_3;
			bool success_10;
			bool success_7;
			bool success_5;
			::ISPA_STD::Node<Tokens, AUTO_1> _6;
			std::vector<::ISPA_STD::Node<Tokens, AUTO_1>> shadow_8;
			::ISPA_STD::MatchResult<Rules, _use::unit> _9;
			std::vector<::ISPA_STD::MatchResult<Rules, _use::unit>> shadow_11;
			::ISPA_STD::Node<Tokens, AUTO_7> _13;
			bool success_14;
			success_1 = false;
			if (!(*pos == Tokens::AUTO_22)) {
				return ;
			}
			_0 = *pos;
			success_1 = true;
			pos++;
			skip_spaces(pos);
			success_3 = false;
			_2 = _use_unit(pos);
			if (!(_2.status)) {
				return ;
			}
			success_3 = true;
			pos++;
			skip_spaces(pos);
			success_5 = false;
			auto begin_12 = pos;
			while (true) {
				if (!(*begin_12 == Tokens::AUTO_1)) {
					[Error];
					break;
				}
				_6 = *begin_12;
				success_7 = true;
				begin_12++;
				shadow_8.push_back(_6);
				skip_spaces(begin_12);
				_9 = _use_unit(begin_12);
				if (!(_9.status)) {
					break;
				}
				success_10 = true;
				begin_12++;
				shadow_11.push_back(_9);
			}
			if (success_7 && success_10) {
				success_5 = true;
				pos = begin_12;
			}
			skip_spaces(pos);
			success_14 = false;
			if (!(*pos == Tokens::AUTO_7)) {
				[Error];
				return ;
			}
			_13 = *pos;
			success_14 = true;
			pos++;
			skip_spaces(pos);
		}
	};
}
#endif // PARSER_H
