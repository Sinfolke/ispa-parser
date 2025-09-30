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
}
#endif // PARSER_H
