#ifndef PARSER_H
#define PARSER_H
#include <string>
#include <vector>
#include <array>
#include <string>
#include <variant>
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
		struct AUTO_2 {
		public: 
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
		struct rule_CSEQUENCE {
			char _not;
			Undef val;
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
		struct moduleImport {
			std::variant<::ISPA_STD::Node<Rules, moduleImport_from>, ::ISPA_STD::Node<Tokens, ID>> value;
		};
		struct cll_function_arguments {
			::ISPA_STD::MatchResult<Rules, cll_expr> first;
			std::vector<::ISPA_STD::Node<Rules, cll_expr>> second;
		};
		struct cll_stmt {
			std::vector<::ISPA_STD::Node<Rules, rule_member>> value;
		};
		struct rule_data_block_regular_datablock {
			std::variant<::ISPA_STD::Node<Rules, rule_data_block_regular_datablock_key>, ::ISPA_STD::Node<Rules, cll_expr>> value;
		};
		struct cll__if {
			::ISPA_STD::MatchResult<Rules, cll_expr> expr;
			::ISPA_STD::MatchResult<Rules, cll_stmt> stmt;
		};
		struct cll_expr_value {
			std::variant<::ISPA_STD::Node<Rules, rvalue>, ::ISPA_STD::Node<Rules, cll_function_call>, ::ISPA_STD::Node<Rules, cll_method_call>, ::ISPA_STD::Node<Rules, cll_expr_group>, ::ISPA_STD::Node<Rules, cll__variable>> value;
		};
		struct cll_expr_compare {
			::ISPA_STD::MatchResult<Rules, cll_expr_arithmetic> first;
			std::vector<::ISPA_STD::Node<Tokens, cll_COMPARE_OP>> operators;
			std::vector<::ISPA_STD::Node<Rules, cll_expr_arithmetic>> sequence;
		};
		struct rule_group {
			std::vector<::ISPA_STD::Node<Rules, rule_member>> value;
		};
		struct rule_member {
			Undef prefix;
			::ISPA_STD::MatchResult<Rules, rule_quantifier> quantifier;
			std::variant<::ISPA_STD::Node<Rules, rule_name>, ::ISPA_STD::Node<Tokens, STRING>, ::ISPA_STD::Node<Tokens, rule_HEX>, ::ISPA_STD::Node<Tokens, DOT>, ::ISPA_STD::Node<Tokens, rule_CSEQUENCE>, ::ISPA_STD::Node<Tokens, rule_BIN>, ::ISPA_STD::Node<Tokens, rule_OP>, ::ISPA_STD::Node<Rules, cll>, ::ISPA_STD::Node<Tokens, rule_ESCAPED>, ::ISPA_STD::Node<Rules, rule_group>, ::ISPA_STD::Node<Tokens, LINEAR_COMMENT>, ::ISPA_STD::Node<Tokens, rule_NOSPACE>> val;
		};
		struct main {
			std::variant<::ISPA_STD::Node<Rules, rule>, ::ISPA_STD::Node<Rules, _use>, ::ISPA_STD::Node<Tokens, NAME>, ::ISPA_STD::Node<Tokens, SPACEMODE>> value;
		};
		struct _use_unit {
			::ISPA_STD::Node<Tokens, ID> name;
			::ISPA_STD::MatchResult<Rules, rvalue> value;
		};
		struct rvalue {
			std::variant<::ISPA_STD::Node<Tokens, ID>, ::ISPA_STD::Node<Tokens, BOOLEAN>, ::ISPA_STD::Node<Tokens, STRING>, ::ISPA_STD::Node<Tokens, AT>, ::ISPA_STD::Node<Tokens, NUMBER>, ::ISPA_STD::Node<Rules, object>, ::ISPA_STD::Node<Rules, array>> value;
		};
		struct array {
			std::vector<::ISPA_STD::Node<Rules, cll_expr>> value;
		};
		struct rule_nested_rule {
			::ISPA_STD::Node<Rules, rule> value;
		};
		struct cll__variable {
			Undef pre;
			::ISPA_STD::MatchResult<Rules, cll_expr> brace_expression;
			Undef pos;
			::ISPA_STD::Node<Tokens, ID> name;
		};
		struct cll_loop_for {
			Undef decl;
			::ISPA_STD::MatchResult<Rules, cll_expr> end;
			::ISPA_STD::MatchResult<Rules, cll_expr> cond;
			::ISPA_STD::MatchResult<Rules, cll_stmt> stmt;
		};
		struct cll_loop_while {
			::ISPA_STD::MatchResult<Rules, cll_expr> expr;
			::ISPA_STD::MatchResult<Rules, cll_stmt> stmt;
		};
		struct rule {
			::ISPA_STD::Node<Tokens, ID> name;
			::ISPA_STD::MatchResult<Rules, rule_data_block> data_block;
			std::vector<::ISPA_STD::Node<Rules, rule_member>> rule;
			std::vector<::ISPA_STD::Node<Rules, rule_nested_rule>> nested_rules;
		};
		struct cll__var {
			::ISPA_STD::Node<Tokens, cll_TYPE> type;
			::ISPA_STD::Node<Tokens, ID> id;
			::ISPA_STD::Node<Tokens, cll_ASSIGNMENT_OP> op;
			::ISPA_STD::MatchResult<Rules, cll_expr> value;
		};
		struct cll_expr_logical {
			::ISPA_STD::MatchResult<Rules, cll_expr_compare> left;
			std::vector<::ISPA_STD::Node<Tokens, cll_LOGICAL_OP>> op;
			std::vector<::ISPA_STD::Node<Rules, cll_expr_compare>> right;
		};
		struct cll_expr_term {
			::ISPA_STD::MatchResult<Rules, cll_expr_value> first;
			std::variant<::ISPA_STD::Node<Tokens, MODULO>, ::ISPA_STD::Node<Tokens, MULTIPLE>, ::ISPA_STD::Node<Tokens, DIVIDE>> operators;
			std::vector<::ISPA_STD::Node<Rules, cll_expr_value>> sequence;
		};
		struct cll_expr {
			::ISPA_STD::Node<Rules, cll_expr_logical> value;
		};
		struct rule_data_block {
			std::variant<::ISPA_STD::Node<Rules, rule_data_block_templated_datablock>, ::ISPA_STD::Node<Rules, rule_data_block_regular_datablock>> value;
		};
		struct cll_expr_group {
			::ISPA_STD::Node<Rules, cll_expr> value;
		};
		struct cll_function_body_call {
			::ISPA_STD::Node<Rules, cll_function_arguments> value;
		};
		struct rule_data_block_regular_datablock_key {
			::ISPA_STD::Node<Tokens, ID> name;
			::ISPA_STD::MatchResult<Rules, cll_expr> dt;
		};
		struct cll_method_call {
			::ISPA_STD::Node<Tokens, ID> name;
			::ISPA_STD::MatchResult<Rules, cll_function_call> body;
		};
		struct _use {
			::ISPA_STD::MatchResult<Rules, _use_unit> first;
			std::vector<::ISPA_STD::Node<Rules, _use_unit>> second;
		};
		struct cll {
			std::variant<::ISPA_STD::Node<Rules, cll__if>, ::ISPA_STD::Node<Rules, cll_loop_for>, ::ISPA_STD::Node<Rules, cll__var>, ::ISPA_STD::Node<Rules, cll_expr>, ::ISPA_STD::Node<Rules, cll_loop_while>> value;
		};
		struct cll_expr_arithmetic {
			::ISPA_STD::MatchResult<Rules, cll_expr_term> first;
			std::variant<::ISPA_STD::Node<Tokens, PLUS>, ::ISPA_STD::Node<Tokens, MINUS>> operators;
			std::vector<::ISPA_STD::Node<Rules, cll_expr_term>> sequence;
		};
		struct cll_TEMPLATE {
			::ISPA_STD::MatchResult<Tokens, cll_TYPE> first;
			std::vector<::ISPA_STD::Node<Tokens, cll_TYPE>> second;
		};
		struct object {
			std::variant<::ISPA_STD::Node<Tokens, NUMBER>, ::ISPA_STD::Node<Tokens, ID>> key;
			::ISPA_STD::MatchResult<Rules, cll_expr> value;
			std::variant<::ISPA_STD::Node<Tokens, NUMBER>, ::ISPA_STD::Node<Tokens, ID>> keys;
			std::vector<::ISPA_STD::Node<Rules, cll_expr>> values;
		};
		struct cll_function_call {
			::ISPA_STD::Node<Tokens, ID> name;
			::ISPA_STD::MatchResult<Rules, cll_function_body_call> body;
		};
		struct cll_TYPE {
			char type;
			::ISPA_STD::MatchResult<Tokens, cll_TEMPLATE> templ;
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
		struct _use : public FlatTypes::_use {
			using unit = FlatTypes::_use;
		};
		using array = FlatTypes::array;
		struct cll : public FlatTypes::cll {
			using LOGICAL_AND = FlatTypes::cll;
			using COMPARE_OP = FlatTypes::cll;
			using LOGICAL_OR = FlatTypes::cll;
			using LOGICAL_NOT = FlatTypes::cll;
			using ASSIGNMENT_OP = FlatTypes::cll;
			using LOGICAL_OP = FlatTypes::cll;
			using function_parameters = FlatTypes::cll;
			using function_body_decl = FlatTypes::cll;
			using function_arguments = FlatTypes::cll;
			using stmt = FlatTypes::cll;
			using _if = FlatTypes::cll;
			using _variable = FlatTypes::cll;
			using loop_for = FlatTypes::cll;
			using loop_while = FlatTypes::cll;
			using _var = FlatTypes::cll;
			struct expr : public FlatTypes::cll {
				using arithmetic = FlatTypes::cll;
				using compare = FlatTypes::cll;
				using group = FlatTypes::cll;
				using logical = FlatTypes::cll;
				using term = FlatTypes::cll;
				using value = FlatTypes::cll;
			};
			using function_body_call = FlatTypes::cll;
			using method_call = FlatTypes::cll;
			using TEMPLATE = FlatTypes::cll;
			using function_call = FlatTypes::cll;
			using TYPE = FlatTypes::cll;
		};
		using main = FlatTypes::main;
		using moduleDeclaration = FlatTypes::moduleDeclaration;
		struct moduleImport : public FlatTypes::moduleImport {
			struct from : public FlatTypes::moduleImport {
				using import_list = FlatTypes::moduleImport;
			};
		};
		using object = FlatTypes::object;
		struct rule : public FlatTypes::rule {
			using OP = FlatTypes::rule;
			struct CSEQUENCE : public FlatTypes::rule {
				using DIAPASON = FlatTypes::rule;
				using ESCAPE = FlatTypes::rule;
				using SYMBOL = FlatTypes::rule;
			};
			using NOSPACE = FlatTypes::rule;
			using BIN = FlatTypes::rule;
			using HEX = FlatTypes::rule;
			using ESCAPED = FlatTypes::rule;
			using value = FlatTypes::rule;
			using name = FlatTypes::rule;
			using keyvalue = FlatTypes::rule;
			using quantifier = FlatTypes::rule;
			using group = FlatTypes::rule;
			using member = FlatTypes::rule;
			using nested_rule = FlatTypes::rule;
			struct data_block : public FlatTypes::rule {
				struct regular_datablock : public FlatTypes::rule {
					using key = FlatTypes::rule;
				};
				using templated_datablock = FlatTypes::rule;
			};
		};
		using rvalue = FlatTypes::rvalue;
	}
}
#endif // PARSER_H
