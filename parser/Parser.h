#pragma once
#ifndef PARSER
#define PARSER

#include <string>
#include <list>
#include <unordered_map>
#include <iscstdlibc++.h>
#include <fstream>
#include <iterator>

#include <iostream>
#ifndef PARSER_OBJ_TYPE
#define PARSER_OBJ_TYPE std::unordered_map
#endif
#ifndef PARSER_ARR_TYPE
#define PARSER_ARR_TYPE std::vector
#endif
#ifndef PARSER_ANY_TYPE
#define PARSER_ANY_TYPE std::any
#endif
#ifndef PARSER_STR_TYPE
#define PARSER_STR_TYPE std::string
#endif
#ifndef PARSER_NUM_TYPE
#define PARSER_NUM_TYPE double
#endif
#ifndef PARSER_BOOL_TYPE
#define PARSER_BOOL_TYPE bool
#endif
namespace Parser {
	using str_t = PARSER_STR_TYPE;
	using num_t = PARSER_NUM_TYPE;
	using bool_t = PARSER_BOOL_TYPE;
	using any_t = PARSER_ANY_TYPE;
	template<typename T>
	using arr_t = PARSER_ARR_TYPE<T>;
	template<typename Key, typename Value>
	using obj_t = PARSER_OBJ_TYPE<Key, Value>;
	enum class Tokens {
		NONE, __WHITESPACE, AUTO_11, AUTO_7, AUTO_6, AUTO_3, AUTO_2, AUTO_1, AUTO_0, rule_BIN, rule_HEX, AUTO_14, rule_NOSPACE, AUTO_8, rule_CSEQUENCE_ESCAPE, rule_CSEQUENCE_SYMBOL, rule_OP, AUTO_17, cll_COMPARE_OP, AUTO_9, AUTO_5, rule_ESCAPED, cll_OP, AUTO_10, cll_ASSIGNMENT_OP, AUTO_19, cll_TEMPLATE, cll_LOGICAL_NOT, cll_LOGICAL_OP, cll_TYPE, AUTO_12, cll_LOGICAL_OR, STRING, NUMBER, AUTO_16, AUTO_4, BOOLEAN, SPACEMODE, AUTO_13, rule_CSEQUENCE_DIAPASON, cll_LOGICAL_AND, QUESTION_MARK, PLUS, MINUS, DIVIDE, MULTIPLE, MODULO, AT, DOT, ID, AUTO_15, rule_CSEQUENCE, LINEAR_COMMENT, AUTO_18, NAME
	};
	enum class Rules {
		NONE, rule_data_block_templated_datablock, rule_data_block_regular_datablock_key, rule_data_block_regular_datablock, cll_loop_while, cll_method_call, cll_expr_group, cll_expr_logical, cll__var, cll_function_call, cll, cll_expr_compare, cll_expr_arithmetic, cll__if, cll_function_parameters, cll_function_arguments, cll_function_decl, cll__variable, cll_expr, cll_function_body_call, cll_stmt, rule, rule_value, rule_data_block, cll_function_body_decl, rule_name, array, rule_member, cll_expr_value, object, rvalue, cll_expr_term, rule_keyvalue, rule_quantifier, main, _use, cll_loop_for, rule_nested_rule, _use_unit, rule_group
	};
	using Rule = ISPA_STD::Node<Rules>;
	using Rule_res = ISPA_STD::match_result<Rules>;
	using Token = ISPA_STD::Node<Tokens>;
	using Token_res = ISPA_STD::match_result<Tokens>;
	using TokenFlow = ISPA_STD::TokenFlow<Tokens>;
	using RuleSeq = ISPA_STD::Seq<Rules>;
	using TokenSeq = ISPA_STD::Seq<Tokens>;
	constexpr const char* TokensToString(Tokens token) {
		switch (token) {
			case Tokens::NONE: return "NONE";
			case Tokens::__WHITESPACE: return "__WHITESPACE";
			case Tokens::AUTO_11: return "AUTO_11";
			case Tokens::AUTO_7: return "AUTO_7";
			case Tokens::AUTO_6: return "AUTO_6";
			case Tokens::AUTO_3: return "AUTO_3";
			case Tokens::AUTO_2: return "AUTO_2";
			case Tokens::AUTO_1: return "AUTO_1";
			case Tokens::AUTO_0: return "AUTO_0";
			case Tokens::rule_BIN: return "rule_BIN";
			case Tokens::rule_HEX: return "rule_HEX";
			case Tokens::AUTO_14: return "AUTO_14";
			case Tokens::rule_NOSPACE: return "rule_NOSPACE";
			case Tokens::AUTO_8: return "AUTO_8";
			case Tokens::rule_CSEQUENCE_ESCAPE: return "rule_CSEQUENCE_ESCAPE";
			case Tokens::rule_CSEQUENCE_SYMBOL: return "rule_CSEQUENCE_SYMBOL";
			case Tokens::rule_OP: return "rule_OP";
			case Tokens::AUTO_17: return "AUTO_17";
			case Tokens::cll_COMPARE_OP: return "cll_COMPARE_OP";
			case Tokens::AUTO_9: return "AUTO_9";
			case Tokens::AUTO_5: return "AUTO_5";
			case Tokens::rule_ESCAPED: return "rule_ESCAPED";
			case Tokens::cll_OP: return "cll_OP";
			case Tokens::AUTO_10: return "AUTO_10";
			case Tokens::cll_ASSIGNMENT_OP: return "cll_ASSIGNMENT_OP";
			case Tokens::AUTO_19: return "AUTO_19";
			case Tokens::cll_TEMPLATE: return "cll_TEMPLATE";
			case Tokens::cll_LOGICAL_NOT: return "cll_LOGICAL_NOT";
			case Tokens::cll_LOGICAL_OP: return "cll_LOGICAL_OP";
			case Tokens::cll_TYPE: return "cll_TYPE";
			case Tokens::AUTO_12: return "AUTO_12";
			case Tokens::cll_LOGICAL_OR: return "cll_LOGICAL_OR";
			case Tokens::STRING: return "STRING";
			case Tokens::NUMBER: return "NUMBER";
			case Tokens::AUTO_16: return "AUTO_16";
			case Tokens::AUTO_4: return "AUTO_4";
			case Tokens::BOOLEAN: return "BOOLEAN";
			case Tokens::SPACEMODE: return "SPACEMODE";
			case Tokens::AUTO_13: return "AUTO_13";
			case Tokens::rule_CSEQUENCE_DIAPASON: return "rule_CSEQUENCE_DIAPASON";
			case Tokens::cll_LOGICAL_AND: return "cll_LOGICAL_AND";
			case Tokens::QUESTION_MARK: return "QUESTION_MARK";
			case Tokens::PLUS: return "PLUS";
			case Tokens::MINUS: return "MINUS";
			case Tokens::DIVIDE: return "DIVIDE";
			case Tokens::MULTIPLE: return "MULTIPLE";
			case Tokens::MODULO: return "MODULO";
			case Tokens::AT: return "AT";
			case Tokens::DOT: return "DOT";
			case Tokens::ID: return "ID";
			case Tokens::AUTO_15: return "AUTO_15";
			case Tokens::rule_CSEQUENCE: return "rule_CSEQUENCE";
			case Tokens::LINEAR_COMMENT: return "LINEAR_COMMENT";
			case Tokens::AUTO_18: return "AUTO_18";
			case Tokens::NAME: return "NAME";
		}
		return "NONE";
	}
	constexpr const char* RulesToString(Rules rule) {
		switch (rule) {
			case Rules::NONE: return "NONE";
			case Rules::rule_data_block_templated_datablock: return "rule_data_block_templated_datablock";
			case Rules::rule_data_block_regular_datablock_key: return "rule_data_block_regular_datablock_key";
			case Rules::rule_data_block_regular_datablock: return "rule_data_block_regular_datablock";
			case Rules::cll_loop_while: return "cll_loop_while";
			case Rules::cll_method_call: return "cll_method_call";
			case Rules::cll_expr_group: return "cll_expr_group";
			case Rules::cll_expr_logical: return "cll_expr_logical";
			case Rules::cll__var: return "cll__var";
			case Rules::cll_function_call: return "cll_function_call";
			case Rules::cll: return "cll";
			case Rules::cll_expr_compare: return "cll_expr_compare";
			case Rules::cll_expr_arithmetic: return "cll_expr_arithmetic";
			case Rules::cll__if: return "cll__if";
			case Rules::cll_function_parameters: return "cll_function_parameters";
			case Rules::cll_function_arguments: return "cll_function_arguments";
			case Rules::cll_function_decl: return "cll_function_decl";
			case Rules::cll__variable: return "cll__variable";
			case Rules::cll_expr: return "cll_expr";
			case Rules::cll_function_body_call: return "cll_function_body_call";
			case Rules::cll_stmt: return "cll_stmt";
			case Rules::rule: return "rule";
			case Rules::rule_value: return "rule_value";
			case Rules::rule_data_block: return "rule_data_block";
			case Rules::cll_function_body_decl: return "cll_function_body_decl";
			case Rules::rule_name: return "rule_name";
			case Rules::array: return "array";
			case Rules::rule_member: return "rule_member";
			case Rules::cll_expr_value: return "cll_expr_value";
			case Rules::object: return "object";
			case Rules::rvalue: return "rvalue";
			case Rules::cll_expr_term: return "cll_expr_term";
			case Rules::rule_keyvalue: return "rule_keyvalue";
			case Rules::rule_quantifier: return "rule_quantifier";
			case Rules::main: return "main";
			case Rules::_use: return "_use";
			case Rules::cll_loop_for: return "cll_loop_for";
			case Rules::rule_nested_rule: return "rule_nested_rule";
			case Rules::_use_unit: return "_use_unit";
			case Rules::rule_group: return "rule_group";
		}
		return "NONE";
	}
	namespace Types {
		struct rule_CSEQUENCE {
			::Parser::arr_t<::Parser::Token> val;
			char _not;
		};
		using ID = ::Parser::str_t;
		struct rule_CSEQUENCE_DIAPASON {
			::Parser::Token to;
			::Parser::Token from;
		};
		using AUTO_13 = char;
		using SPACEMODE = ::Parser::str_t;
		using AUTO_16 = char;
		struct NUMBER {
			::Parser::str_t dec;
			char main;
			::Parser::str_t sign;
		};
		using AUTO_8 = char;
		using AUTO_18 = ::Parser::str_t;
		using AUTO_14 = char;
		using rule_HEX = ::Parser::str_t;
		using AUTO_2 = char;
		using rule_BIN = ::Parser::str_t;
		using STRING = ::Parser::str_t;
		using AUTO_11 = ::Parser::str_t;
		using AUTO_0 = char;
		using BOOLEAN = ::Parser::str_t;
		using rule_CSEQUENCE_ESCAPE = char;
		using AUTO_4 = ::Parser::str_t;
		using cll_OP = ::Parser::str_t;
		using AUTO_3 = char;
		using AUTO_6 = char;
		using AUTO_7 = char;
		using AUTO_5 = char;
		using cll_ASSIGNMENT_OP = char;
		using AUTO_1 = char;
		using rule_CSEQUENCE_SYMBOL = ::Parser::str_t;
		using AUTO_17 = char;
		using cll_COMPARE_OP = ::Parser::str_t;
		using AUTO_12 = ::Parser::str_t;
		struct cll_TEMPLATE {
			::Parser::arr_t<::Parser::Token> second;
			::Parser::Token first;
		};
		using AUTO_9 = ::Parser::str_t;
		using AUTO_15 = char;
		using rule_ESCAPED = char;
		using AUTO_10 = ::Parser::str_t;
		using NAME = ::Parser::Token;
		using AUTO_19 = ::Parser::str_t;
		struct cll_TYPE {
			::Parser::Token templ;
			::Parser::str_t type;
		};
		using cll_LOGICAL_OP = ::Parser::Token;
		using rule_group = ::Parser::arr_t<::Parser::Rule>;
		struct _use_unit {
			::Parser::Rule value;
			::Parser::Token name;
		};
		using rule_nested_rule = ::Parser::Rule;
		struct _use {
			::Parser::arr_t<::Parser::Rule> second;
			::Parser::Rule first;
		};
		using main = ::Parser::arr_t<::Parser::any_t>;
		using rule_quantifier = ::Parser::Token;
		using rule_keyvalue = ::Parser::Token;
		struct cll_expr_term {
			::Parser::arr_t<::Parser::Rule> sequence;
			::Parser::arr_t<::Parser::Token> operators;
			::Parser::Rule first;
		};
		using rvalue = ::Parser::any_t;
		struct cll_expr_arithmetic {
			::Parser::arr_t<::Parser::Rule> sequence;
			::Parser::arr_t<::Parser::Token> operators;
			::Parser::Rule first;
		};
		struct cll__if {
			::Parser::Rule stmt;
			::Parser::Rule expr;
		};
		struct cll__var {
			::Parser::Rule value;
			::Parser::Token op;
			::Parser::Token id;
			::Parser::Token type;
		};
		struct rule {
			::Parser::arr_t<::Parser::Rule> nested_rules;
			::Parser::Rule data_block;
			::Parser::arr_t<::Parser::Rule> rule;
			::Parser::Token name;
		};
		struct cll_function_call {
			::Parser::Rule body;
			::Parser::Token name;
		};
		struct cll_function_decl {
			::Parser::Rule stmt;
			::Parser::Rule name;
			::Parser::arr_t<::Parser::Token> type;
		};
		using cll_stmt = ::Parser::arr_t<::Parser::Rule>;
		using cll_expr_group = ::Parser::Rule;
		using cll = ::Parser::Rule;
		struct cll_expr_compare {
			::Parser::arr_t<::Parser::Rule> sequence;
			::Parser::arr_t<::Parser::Token> operators;
			::Parser::Rule first;
		};
		struct cll_function_parameters {
			::Parser::arr_t<::Parser::Token> second;
			::Parser::Token first;
		};
		struct cll_function_arguments {
			::Parser::arr_t<::Parser::Rule> second;
			::Parser::Rule first;
		};
		struct cll_loop_while {
			::Parser::Rule stmt;
			::Parser::Rule expr;
		};
		struct cll_method_call {
			::Parser::Rule body;
			::Parser::Token name;
		};
		struct rule_data_block_templated_datablock {
			::Parser::arr_t<::Parser::Token> second_name;
			::Parser::Token first_name;
		};
		using rule_data_block_regular_datablock = ::Parser::any_t;
		struct rule_data_block_regular_datablock_key {
			::Parser::Rule dt;
			::Parser::Token name;
		};
		struct cll__variable {
			::Parser::Token pos;
			::Parser::Rule brace_expression;
			::Parser::Token name;
			::Parser::Token pre;
		};
		using cll_expr = ::Parser::Rule;
		struct cll_loop_for {
			::Parser::Rule stmt;
			::Parser::Rule end;
			::Parser::Rule cond;
			::Parser::Rule decl;
		};
		using cll_function_body_call = ::Parser::Rule;
		using rule_value = ::Parser::Token;
		using rule_data_block = ::Parser::Rule;
		using cll_function_body_decl = ::Parser::Rule;
		struct rule_name {
			::Parser::arr_t<::Parser::Token> nested_name;
			::Parser::Token name;
			::Parser::Token is_nested;
		};
		using array = ::Parser::arr_t<::Parser::Rule>;
		struct rule_member {
			::Parser::Rule quantifier;
			::Parser::any_t val;
			::Parser::Rule prefix;
		};
		struct object {
			::Parser::arr_t<::Parser::Rule> values;
			::Parser::arr_t<::Parser::Token> keys;
			::Parser::Rule value;
			::Parser::Token key;
		};
		struct cll_expr_logical {
			::Parser::arr_t<::Parser::Rule> right;
			::Parser::arr_t<::Parser::Token> op;
			::Parser::Rule left;
		};
		using cll_expr_value = ::Parser::Rule;
	}

	namespace get {
		const ::Parser::Types::rule_CSEQUENCE& rule_CSEQUENCE(const ::Parser::Token &token);
		::Parser::Types::rule_CSEQUENCE& rule_CSEQUENCE(::Parser::Token &token);
		const ::Parser::Types::ID& ID(const ::Parser::Token &token);
		::Parser::Types::ID& ID(::Parser::Token &token);
		const ::Parser::Types::rule_CSEQUENCE_DIAPASON& rule_CSEQUENCE_DIAPASON(const ::Parser::Token &token);
		::Parser::Types::rule_CSEQUENCE_DIAPASON& rule_CSEQUENCE_DIAPASON(::Parser::Token &token);
		const ::Parser::Types::AUTO_13& AUTO_13(const ::Parser::Token &token);
		::Parser::Types::AUTO_13& AUTO_13(::Parser::Token &token);
		const ::Parser::Types::SPACEMODE& SPACEMODE(const ::Parser::Token &token);
		::Parser::Types::SPACEMODE& SPACEMODE(::Parser::Token &token);
		const ::Parser::Types::AUTO_16& AUTO_16(const ::Parser::Token &token);
		::Parser::Types::AUTO_16& AUTO_16(::Parser::Token &token);
		const ::Parser::Types::NUMBER& NUMBER(const ::Parser::Token &token);
		::Parser::Types::NUMBER& NUMBER(::Parser::Token &token);
		const ::Parser::Types::AUTO_8& AUTO_8(const ::Parser::Token &token);
		::Parser::Types::AUTO_8& AUTO_8(::Parser::Token &token);
		const ::Parser::Types::AUTO_18& AUTO_18(const ::Parser::Token &token);
		::Parser::Types::AUTO_18& AUTO_18(::Parser::Token &token);
		const ::Parser::Types::AUTO_14& AUTO_14(const ::Parser::Token &token);
		::Parser::Types::AUTO_14& AUTO_14(::Parser::Token &token);
		const ::Parser::Types::rule_HEX& rule_HEX(const ::Parser::Token &token);
		::Parser::Types::rule_HEX& rule_HEX(::Parser::Token &token);
		const ::Parser::Types::AUTO_2& AUTO_2(const ::Parser::Token &token);
		::Parser::Types::AUTO_2& AUTO_2(::Parser::Token &token);
		const ::Parser::Types::rule_BIN& rule_BIN(const ::Parser::Token &token);
		::Parser::Types::rule_BIN& rule_BIN(::Parser::Token &token);
		const ::Parser::Types::STRING& STRING(const ::Parser::Token &token);
		::Parser::Types::STRING& STRING(::Parser::Token &token);
		const ::Parser::Types::AUTO_11& AUTO_11(const ::Parser::Token &token);
		::Parser::Types::AUTO_11& AUTO_11(::Parser::Token &token);
		const ::Parser::Types::AUTO_0& AUTO_0(const ::Parser::Token &token);
		::Parser::Types::AUTO_0& AUTO_0(::Parser::Token &token);
		const ::Parser::Types::BOOLEAN& BOOLEAN(const ::Parser::Token &token);
		::Parser::Types::BOOLEAN& BOOLEAN(::Parser::Token &token);
		const ::Parser::Types::rule_CSEQUENCE_ESCAPE& rule_CSEQUENCE_ESCAPE(const ::Parser::Token &token);
		::Parser::Types::rule_CSEQUENCE_ESCAPE& rule_CSEQUENCE_ESCAPE(::Parser::Token &token);
		const ::Parser::Types::AUTO_4& AUTO_4(const ::Parser::Token &token);
		::Parser::Types::AUTO_4& AUTO_4(::Parser::Token &token);
		const ::Parser::Types::cll_OP& cll_OP(const ::Parser::Token &token);
		::Parser::Types::cll_OP& cll_OP(::Parser::Token &token);
		const ::Parser::Types::AUTO_3& AUTO_3(const ::Parser::Token &token);
		::Parser::Types::AUTO_3& AUTO_3(::Parser::Token &token);
		const ::Parser::Types::AUTO_6& AUTO_6(const ::Parser::Token &token);
		::Parser::Types::AUTO_6& AUTO_6(::Parser::Token &token);
		const ::Parser::Types::AUTO_7& AUTO_7(const ::Parser::Token &token);
		::Parser::Types::AUTO_7& AUTO_7(::Parser::Token &token);
		const ::Parser::Types::AUTO_5& AUTO_5(const ::Parser::Token &token);
		::Parser::Types::AUTO_5& AUTO_5(::Parser::Token &token);
		const ::Parser::Types::cll_ASSIGNMENT_OP& cll_ASSIGNMENT_OP(const ::Parser::Token &token);
		::Parser::Types::cll_ASSIGNMENT_OP& cll_ASSIGNMENT_OP(::Parser::Token &token);
		const ::Parser::Types::AUTO_1& AUTO_1(const ::Parser::Token &token);
		::Parser::Types::AUTO_1& AUTO_1(::Parser::Token &token);
		const ::Parser::Types::rule_CSEQUENCE_SYMBOL& rule_CSEQUENCE_SYMBOL(const ::Parser::Token &token);
		::Parser::Types::rule_CSEQUENCE_SYMBOL& rule_CSEQUENCE_SYMBOL(::Parser::Token &token);
		const ::Parser::Types::AUTO_17& AUTO_17(const ::Parser::Token &token);
		::Parser::Types::AUTO_17& AUTO_17(::Parser::Token &token);
		const ::Parser::Types::cll_COMPARE_OP& cll_COMPARE_OP(const ::Parser::Token &token);
		::Parser::Types::cll_COMPARE_OP& cll_COMPARE_OP(::Parser::Token &token);
		const ::Parser::Types::AUTO_12& AUTO_12(const ::Parser::Token &token);
		::Parser::Types::AUTO_12& AUTO_12(::Parser::Token &token);
		const ::Parser::Types::cll_TEMPLATE& cll_TEMPLATE(const ::Parser::Token &token);
		::Parser::Types::cll_TEMPLATE& cll_TEMPLATE(::Parser::Token &token);
		const ::Parser::Types::AUTO_9& AUTO_9(const ::Parser::Token &token);
		::Parser::Types::AUTO_9& AUTO_9(::Parser::Token &token);
		const ::Parser::Types::AUTO_15& AUTO_15(const ::Parser::Token &token);
		::Parser::Types::AUTO_15& AUTO_15(::Parser::Token &token);
		const ::Parser::Types::rule_ESCAPED& rule_ESCAPED(const ::Parser::Token &token);
		::Parser::Types::rule_ESCAPED& rule_ESCAPED(::Parser::Token &token);
		const ::Parser::Types::AUTO_10& AUTO_10(const ::Parser::Token &token);
		::Parser::Types::AUTO_10& AUTO_10(::Parser::Token &token);
		const ::Parser::Types::NAME& NAME(const ::Parser::Token &token);
		::Parser::Types::NAME& NAME(::Parser::Token &token);
		const ::Parser::Types::AUTO_19& AUTO_19(const ::Parser::Token &token);
		::Parser::Types::AUTO_19& AUTO_19(::Parser::Token &token);
		const ::Parser::Types::cll_TYPE& cll_TYPE(const ::Parser::Token &token);
		::Parser::Types::cll_TYPE& cll_TYPE(::Parser::Token &token);
		const ::Parser::Types::cll_LOGICAL_OP& cll_LOGICAL_OP(const ::Parser::Token &token);
		::Parser::Types::cll_LOGICAL_OP& cll_LOGICAL_OP(::Parser::Token &token);
		const ::Parser::Types::rule_group& rule_group(const ::Parser::Rule &rule);
		::Parser::Types::rule_group& rule_group(::Parser::Rule &rule);
		const ::Parser::Types::_use_unit& _use_unit(const ::Parser::Rule &rule);
		::Parser::Types::_use_unit& _use_unit(::Parser::Rule &rule);
		const ::Parser::Types::rule_nested_rule& rule_nested_rule(const ::Parser::Rule &rule);
		::Parser::Types::rule_nested_rule& rule_nested_rule(::Parser::Rule &rule);
		const ::Parser::Types::_use& _use(const ::Parser::Rule &rule);
		::Parser::Types::_use& _use(::Parser::Rule &rule);
		const ::Parser::Types::main& main(const ::Parser::Rule &rule);
		::Parser::Types::main& main(::Parser::Rule &rule);
		const ::Parser::Types::rule_quantifier& rule_quantifier(const ::Parser::Rule &rule);
		::Parser::Types::rule_quantifier& rule_quantifier(::Parser::Rule &rule);
		const ::Parser::Types::rule_keyvalue& rule_keyvalue(const ::Parser::Rule &rule);
		::Parser::Types::rule_keyvalue& rule_keyvalue(::Parser::Rule &rule);
		const ::Parser::Types::cll_expr_term& cll_expr_term(const ::Parser::Rule &rule);
		::Parser::Types::cll_expr_term& cll_expr_term(::Parser::Rule &rule);
		const ::Parser::Types::rvalue& rvalue(const ::Parser::Rule &rule);
		::Parser::Types::rvalue& rvalue(::Parser::Rule &rule);
		const ::Parser::Types::cll_expr_arithmetic& cll_expr_arithmetic(const ::Parser::Rule &rule);
		::Parser::Types::cll_expr_arithmetic& cll_expr_arithmetic(::Parser::Rule &rule);
		const ::Parser::Types::cll__if& cll__if(const ::Parser::Rule &rule);
		::Parser::Types::cll__if& cll__if(::Parser::Rule &rule);
		const ::Parser::Types::cll__var& cll__var(const ::Parser::Rule &rule);
		::Parser::Types::cll__var& cll__var(::Parser::Rule &rule);
		const ::Parser::Types::rule& rule(const ::Parser::Rule &rule);
		::Parser::Types::rule& rule(::Parser::Rule &rule);
		const ::Parser::Types::cll_function_call& cll_function_call(const ::Parser::Rule &rule);
		::Parser::Types::cll_function_call& cll_function_call(::Parser::Rule &rule);
		const ::Parser::Types::cll_function_decl& cll_function_decl(const ::Parser::Rule &rule);
		::Parser::Types::cll_function_decl& cll_function_decl(::Parser::Rule &rule);
		const ::Parser::Types::cll_stmt& cll_stmt(const ::Parser::Rule &rule);
		::Parser::Types::cll_stmt& cll_stmt(::Parser::Rule &rule);
		const ::Parser::Types::cll_expr_group& cll_expr_group(const ::Parser::Rule &rule);
		::Parser::Types::cll_expr_group& cll_expr_group(::Parser::Rule &rule);
		const ::Parser::Types::cll& cll(const ::Parser::Rule &rule);
		::Parser::Types::cll& cll(::Parser::Rule &rule);
		const ::Parser::Types::cll_expr_compare& cll_expr_compare(const ::Parser::Rule &rule);
		::Parser::Types::cll_expr_compare& cll_expr_compare(::Parser::Rule &rule);
		const ::Parser::Types::cll_function_parameters& cll_function_parameters(const ::Parser::Rule &rule);
		::Parser::Types::cll_function_parameters& cll_function_parameters(::Parser::Rule &rule);
		const ::Parser::Types::cll_function_arguments& cll_function_arguments(const ::Parser::Rule &rule);
		::Parser::Types::cll_function_arguments& cll_function_arguments(::Parser::Rule &rule);
		const ::Parser::Types::cll_loop_while& cll_loop_while(const ::Parser::Rule &rule);
		::Parser::Types::cll_loop_while& cll_loop_while(::Parser::Rule &rule);
		const ::Parser::Types::cll_method_call& cll_method_call(const ::Parser::Rule &rule);
		::Parser::Types::cll_method_call& cll_method_call(::Parser::Rule &rule);
		const ::Parser::Types::rule_data_block_templated_datablock& rule_data_block_templated_datablock(const ::Parser::Rule &rule);
		::Parser::Types::rule_data_block_templated_datablock& rule_data_block_templated_datablock(::Parser::Rule &rule);
		const ::Parser::Types::rule_data_block_regular_datablock& rule_data_block_regular_datablock(const ::Parser::Rule &rule);
		::Parser::Types::rule_data_block_regular_datablock& rule_data_block_regular_datablock(::Parser::Rule &rule);
		const ::Parser::Types::rule_data_block_regular_datablock_key& rule_data_block_regular_datablock_key(const ::Parser::Rule &rule);
		::Parser::Types::rule_data_block_regular_datablock_key& rule_data_block_regular_datablock_key(::Parser::Rule &rule);
		const ::Parser::Types::cll__variable& cll__variable(const ::Parser::Rule &rule);
		::Parser::Types::cll__variable& cll__variable(::Parser::Rule &rule);
		const ::Parser::Types::cll_expr& cll_expr(const ::Parser::Rule &rule);
		::Parser::Types::cll_expr& cll_expr(::Parser::Rule &rule);
		const ::Parser::Types::cll_loop_for& cll_loop_for(const ::Parser::Rule &rule);
		::Parser::Types::cll_loop_for& cll_loop_for(::Parser::Rule &rule);
		const ::Parser::Types::cll_function_body_call& cll_function_body_call(const ::Parser::Rule &rule);
		::Parser::Types::cll_function_body_call& cll_function_body_call(::Parser::Rule &rule);
		const ::Parser::Types::rule_value& rule_value(const ::Parser::Rule &rule);
		::Parser::Types::rule_value& rule_value(::Parser::Rule &rule);
		const ::Parser::Types::rule_data_block& rule_data_block(const ::Parser::Rule &rule);
		::Parser::Types::rule_data_block& rule_data_block(::Parser::Rule &rule);
		const ::Parser::Types::cll_function_body_decl& cll_function_body_decl(const ::Parser::Rule &rule);
		::Parser::Types::cll_function_body_decl& cll_function_body_decl(::Parser::Rule &rule);
		const ::Parser::Types::rule_name& rule_name(const ::Parser::Rule &rule);
		::Parser::Types::rule_name& rule_name(::Parser::Rule &rule);
		const ::Parser::Types::array& array(const ::Parser::Rule &rule);
		::Parser::Types::array& array(::Parser::Rule &rule);
		const ::Parser::Types::rule_member& rule_member(const ::Parser::Rule &rule);
		::Parser::Types::rule_member& rule_member(::Parser::Rule &rule);
		const ::Parser::Types::object& object(const ::Parser::Rule &rule);
		::Parser::Types::object& object(::Parser::Rule &rule);
		const ::Parser::Types::cll_expr_logical& cll_expr_logical(const ::Parser::Rule &rule);
		::Parser::Types::cll_expr_logical& cll_expr_logical(::Parser::Rule &rule);
		const ::Parser::Types::cll_expr_value& cll_expr_value(const ::Parser::Rule &rule);
		::Parser::Types::cll_expr_value& cll_expr_value(::Parser::Rule &rule);
	}
	class Lexer : public ISPA_STD::Lexer_base<Tokens> {
		public:
			Token makeToken(const char*& pos);

        /**
         * @param os the output stream
         * Print the tokens into an output stream
         */
        void printTokens(std::ostream& os);
        /**
         * @param os the output stream
         * @param token the token to print
         * Prints a single token into an output stream
         */
        static void printToken(std::ostream& os, const Token& token);
		Lexer(const std::string& in) : Lexer_base(in) {}
        Lexer(const char* in) : Lexer_base(in) {}
        Lexer(TokenFlow &tokens) : Lexer_base(tokens) {}
        Lexer() {}
		private:
			Token_res NONE(const char*);
			Token_res __WHITESPACE(const char*);
			Token_res AUTO_11(const char*);
			Token_res AUTO_7(const char*);
			Token_res AUTO_6(const char*);
			Token_res AUTO_3(const char*);
			Token_res AUTO_2(const char*);
			Token_res AUTO_1(const char*);
			Token_res AUTO_0(const char*);
			Token_res rule_BIN(const char*);
			Token_res rule_HEX(const char*);
			Token_res AUTO_14(const char*);
			Token_res rule_NOSPACE(const char*);
			Token_res AUTO_8(const char*);
			Token_res rule_CSEQUENCE_ESCAPE(const char*);
			Token_res rule_CSEQUENCE_SYMBOL(const char*);
			Token_res rule_OP(const char*);
			Token_res AUTO_17(const char*);
			Token_res cll_COMPARE_OP(const char*);
			Token_res AUTO_9(const char*);
			Token_res AUTO_5(const char*);
			Token_res rule_ESCAPED(const char*);
			Token_res cll_OP(const char*);
			Token_res AUTO_10(const char*);
			Token_res cll_ASSIGNMENT_OP(const char*);
			Token_res AUTO_19(const char*);
			Token_res cll_TEMPLATE(const char*);
			Token_res cll_LOGICAL_NOT(const char*);
			Token_res cll_LOGICAL_OP(const char*);
			Token_res cll_TYPE(const char*);
			Token_res AUTO_12(const char*);
			Token_res cll_LOGICAL_OR(const char*);
			Token_res STRING(const char*);
			Token_res NUMBER(const char*);
			Token_res AUTO_16(const char*);
			Token_res AUTO_4(const char*);
			Token_res BOOLEAN(const char*);
			Token_res SPACEMODE(const char*);
			Token_res AUTO_13(const char*);
			Token_res rule_CSEQUENCE_DIAPASON(const char*);
			Token_res cll_LOGICAL_AND(const char*);
			Token_res QUESTION_MARK(const char*);
			Token_res PLUS(const char*);
			Token_res MINUS(const char*);
			Token_res DIVIDE(const char*);
			Token_res MULTIPLE(const char*);
			Token_res MODULO(const char*);
			Token_res AT(const char*);
			Token_res DOT(const char*);
			Token_res ID(const char*);
			Token_res AUTO_15(const char*);
			Token_res rule_CSEQUENCE(const char*);
			Token_res LINEAR_COMMENT(const char*);
			Token_res AUTO_18(const char*);
			Token_res NAME(const char*);
	};
	class Parser : public ISPA_STD::LLParser_base<Tokens, Rules> {
		public:
            /**
             * @param os the output stream
             * Print the ast into output stream
             */
            void printAST(std::ostream& os);
            /**
             * @param os the output stream
             * @param rule the rule to print
             * Prints a single rule into an output stream
             */
            static void printRule(std::ostream &os, const Token &token, size_t &indentLevel, bool addSpaceOnBegin);
            static void printRule(std::ostream &os, const Rule &rule, size_t &indentLevel, bool addSpaceOnBegin);
            static void printRule(std::ostream &os, const std::any& data, size_t &indentLevel, bool addSpaceOnBegin);
		private:			Rule_res getRule(Lexer::lazy_iterator&);
			Rule_res getRule(Lexer::iterator&);
		void parseFromTokens();
		void lazyParse();
		template <class IT>
		::Parser::Rule_res rule_data_block_templated_datablock(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Token _2;
			::Parser::bool_t success_3 = false;
			::Parser::bool_t success_5 = false;
			::Parser::bool_t success_7 = false;
			::Parser::Token _6;
			::Parser::bool_t success_9 = false;
			::Parser::bool_t success_14 = false;
			::Parser::bool_t success_11 = false;
			::Parser::Token _10;
			::Parser::arr_t<::Parser::Token> shadow_12;
			::Parser::Token _13;
			::Parser::arr_t<::Parser::Token> shadow_15;
			::Parser::Token _18;
			::Parser::bool_t success_19 = false;
			success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::AT))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			success_3 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_0))
			{
				reportError(pos, "auto_0 ");
				return {};
			}
			_2 = *pos;
			success_3 = true;
			pos += 1;
			skip_spaces(pos);
			success_5 = false;
			auto begin_17 = pos;
			success_7 = false;
			do
			{
				if (!(begin_17->name() == ::Parser::Tokens::ID))
				{
					reportError(pos, "id ");
					break;
				}
				_6 = *begin_17;
				success_7 = true;
				begin_17 += 1;
				skip_spaces(begin_17);
				success_9 = false;
				auto begin_16 = begin_17;
				success_14 = false;
				success_11 = false;
				while (1)
				{
					if (!(begin_16->name() == ::Parser::Tokens::AUTO_1))
					{
						reportError(pos, "auto_1 ");
						break;
					}
					_10 = *begin_16;
					success_11 = true;
					begin_16 += 1;
					shadow_12.push_back(_10);
					skip_spaces(begin_16);
					if (!(begin_16->name() == ::Parser::Tokens::ID))
					{
						reportError(pos, "id ");
						break;
					}
					_13 = *begin_16;
					success_14 = true;
					begin_16 += 1;
					shadow_15.push_back(_13);
				}
				if (success_11 && success_14)
				{
					success_9 = true;
					begin_17 = begin_16;
				}
			}
			while(0);
			if (success_7)
			{
				success_5 = true;
				pos = begin_17;
			}
			skip_spaces(pos);
			success_19 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_2))
			{
				reportError(pos, "auto_2 ");
				return {};
			}
			_18 = *pos;
			success_19 = true;
			pos += 1;
			::Parser::Types::rule_data_block_templated_datablock data;
			data.second_name = shadow_15;
			data.first_name = _6;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::rule_data_block_templated_datablock, data)};
		}
		template <class IT>
		::Parser::Rule_res rule_data_block_regular_datablock_key(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Token _2;
			::Parser::bool_t success_3 = false;
			::Parser::Rule_res _4;
			::Parser::bool_t success_5 = false;
			success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::ID))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			success_3 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_3))
			{
				reportError(pos, "auto_3 ");
				return {};
			}
			_2 = *pos;
			success_3 = true;
			pos += 1;
			skip_spaces(pos);
			success_5 = false;
			_4 = cll_expr(pos);
			if (!(_4.status))
			{
				reportError(pos, "cll expr ");
				return {};
			}
			success_5 = true;
			pos += _4.node.length();
			::Parser::Types::rule_data_block_regular_datablock_key data;
			data.dt = _4.node;
			data.name = _0;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::rule_data_block_regular_datablock_key, data)};
		}
		template <class IT>
		::Parser::Rule_res rule_data_block_regular_datablock(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::any_t _2;
			::Parser::bool_t success_3 = false;
			::Parser::Rule_res _4;
			::Parser::bool_t success_5 = false;
			::Parser::arr_t<::Parser::Rule> shadow_6;
			::Parser::bool_t success_7 = false;
			::Parser::Rule_res _8;
			::Parser::bool_t success_9 = false;
			::Parser::Token _10;
			::Parser::bool_t success_11 = false;
			success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_0))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			success_3 = false;
			success_5 = false;
			_4 = rule_data_block_regular_datablock_key(pos);
			success_7 = false;
			while (_4.status)
			{
				success_5 = true;
				pos += _4.node.length();
				shadow_6.push_back(_4.node);
				_4 = rule_data_block_regular_datablock_key(pos);
				success_7 = true;
			}
			if (!success_7)
			{
				success_9 = false;
				_8 = cll_expr(pos);
				if (!(_8.status))
				{
					return {};
				}
				else 
				{
					success_9 = true;
					pos += _8.node.length();
					_2 = _8.node;
				}
			}
			else 
			{
				_2 = shadow_6;
			}
			success_3 = true;
			skip_spaces(pos);
			success_11 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_2))
			{
				reportError(pos, "auto_2 ");
				return {};
			}
			_10 = *pos;
			success_11 = true;
			pos += 1;
			::Parser::Types::rule_data_block_regular_datablock data = _2;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::rule_data_block_regular_datablock, data)};
		}
		template <class IT>
		::Parser::Rule_res cll_loop_while(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Rule_res _2;
			::Parser::bool_t success_3 = false;
			::Parser::Rule_res _4;
			::Parser::bool_t success_5 = false;
			success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_4))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			success_3 = false;
			_2 = cll_expr(pos);
			if (!(_2.status))
			{
				reportError(pos, "cll expr ");
				return {};
			}
			success_3 = true;
			pos += _2.node.length();
			skip_spaces(pos);
			success_5 = false;
			_4 = cll_stmt(pos);
			if (!(_4.status))
			{
				reportError(pos, "cll stmt ");
				return {};
			}
			success_5 = true;
			pos += _4.node.length();
			::Parser::Types::cll_loop_while data;
			data.stmt = _4.node;
			data.expr = _2.node;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_loop_while, data)};
		}
		template <class IT>
		::Parser::Rule_res cll_method_call(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Token _2;
			::Parser::bool_t success_3 = false;
			::Parser::Rule_res _4;
			::Parser::bool_t success_5 = false;
			success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::ID))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			success_3 = false;
			if (!(pos->name() == ::Parser::Tokens::DOT))
			{
				reportError(pos, "dot ");
				return {};
			}
			_2 = *pos;
			success_3 = true;
			pos += 1;
			skip_spaces(pos);
			success_5 = false;
			_4 = cll_function_call(pos);
			if (!(_4.status))
			{
				reportError(pos, "cll function_call ");
				return {};
			}
			success_5 = true;
			pos += _4.node.length();
			::Parser::Types::cll_method_call data;
			data.body = _4.node;
			data.name = _0;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_method_call, data)};
		}
		template <class IT>
		::Parser::Rule_res cll_expr_group(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Rule_res _2;
			::Parser::bool_t success_3 = false;
			::Parser::Token _4;
			::Parser::bool_t success_5 = false;
			success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_5))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			success_3 = false;
			_2 = cll_expr(pos);
			if (!(_2.status))
			{
				reportError(pos, "cll expr ");
				return {};
			}
			success_3 = true;
			pos += _2.node.length();
			skip_spaces(pos);
			success_5 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_6))
			{
				reportError(pos, "auto_6 ");
				return {};
			}
			_4 = *pos;
			success_5 = true;
			pos += 1;
			::Parser::Types::cll_expr_group data = _2.node;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_expr_group, data)};
		}
		template <class IT>
		::Parser::Rule_res cll_expr_logical(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Rule_res _0;
			::Parser::bool_t success_1 = false;
			::Parser::bool_t success_3 = false;
			::Parser::bool_t success_8 = false;
			::Parser::bool_t success_5 = false;
			::Parser::Token _4;
			::Parser::arr_t<::Parser::Token> shadow_6;
			::Parser::Rule_res _7;
			::Parser::arr_t<::Parser::Rule> shadow_9;
			success_1 = false;
			_0 = cll_expr_compare(pos);
			if (!(_0.status))
			{
				return {};
			}
			success_1 = true;
			pos += _0.node.length();
			skip_spaces(pos);
			success_3 = false;
			auto begin_10 = pos;
			success_8 = false;
			success_5 = false;
			while (1)
			{
				if (!(begin_10->name() == ::Parser::Tokens::cll_LOGICAL_OP))
				{
					reportError(pos, "cll logical_op ");
					break;
				}
				_4 = *begin_10;
				success_5 = true;
				begin_10 += 1;
				shadow_6.push_back(_4);
				skip_spaces(begin_10);
				_7 = cll_expr_compare(begin_10);
				if (!(_7.status))
				{
					reportError(pos, "cll expr compare ");
					break;
				}
				success_8 = true;
				begin_10 += _7.node.length();
				shadow_9.push_back(_7.node);
			}
			if (success_5 && success_8)
			{
				success_3 = true;
				pos = begin_10;
			}
			::Parser::Types::cll_expr_logical data;
			data.right = shadow_9;
			data.op = shadow_6;
			data.left = _0.node;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_expr_logical, data)};
		}
		template <class IT>
		::Parser::Rule_res cll__var(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Token _2;
			::Parser::bool_t success_3 = false;
			::Parser::bool_t success_5 = false;
			::Parser::bool_t success_9 = false;
			::Parser::bool_t success_7 = false;
			::Parser::Token _6;
			::Parser::Rule_res _8;
			success_1 = false;
			if (pos->name() == ::Parser::Tokens::cll_TYPE)
			{
				_0 = *pos;
				success_1 = true;
				pos += 1;
			}
			skip_spaces(pos);
			success_3 = false;
			if (!(pos->name() == ::Parser::Tokens::ID))
			{
				reportError(pos, "id ");
				return {};
			}
			_2 = *pos;
			success_3 = true;
			pos += 1;
			skip_spaces(pos);
			success_5 = false;
			auto begin_10 = pos;
			success_9 = false;
			success_7 = false;
			do
			{
				if (!(begin_10->name() == ::Parser::Tokens::cll_ASSIGNMENT_OP))
				{
					reportError(pos, "cll assignment_op ");
					break;
				}
				_6 = *begin_10;
				success_7 = true;
				begin_10 += 1;
				skip_spaces(begin_10);
				_8 = cll_expr(begin_10);
				if (!(_8.status))
				{
					reportError(pos, "cll expr ");
					break;
				}
				success_9 = true;
				begin_10 += _8.node.length();
			}
			while(0);
			if (success_7 && success_9)
			{
				success_5 = true;
				pos = begin_10;
			}
			::Parser::Types::cll__var data;
			data.value = _8.node;
			data.op = _6;
			data.id = _2;
			data.type = _0;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll__var, data)};
		}
		template <class IT>
		::Parser::Rule_res cll_function_call(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Rule_res _2;
			::Parser::bool_t success_3 = false;
			success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::ID))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			success_3 = false;
			_2 = cll_function_body_call(pos);
			if (!(_2.status))
			{
				reportError(pos, "cll function_body_call ");
				return {};
			}
			success_3 = true;
			pos += _2.node.length();
			::Parser::Types::cll_function_call data;
			data.body = _2.node;
			data.name = _0;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_function_call, data)};
		}
		template <class IT>
		::Parser::Rule_res cll(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Rule _2;
			::Parser::bool_t success_3 = false;
			::Parser::Rule_res _4;
			::Parser::bool_t success_5 = false;
			::Parser::Rule_res _6;
			::Parser::bool_t success_7 = false;
			::Parser::Rule_res _8;
			::Parser::bool_t success_9 = false;
			::Parser::Rule_res _10;
			::Parser::bool_t success_11 = false;
			::Parser::Rule_res _12;
			::Parser::bool_t success_13 = false;
			::Parser::Token _14;
			::Parser::bool_t success_15 = false;
			success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_7))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			success_3 = false;
			success_5 = false;
			_4 = cll_loop_while(pos);
			if (!(_4.status))
			{
				success_7 = false;
				_6 = cll__var(pos);
				if (!(_6.status))
				{
					success_9 = false;
					_8 = cll_loop_for(pos);
					if (!(_8.status))
					{
						success_11 = false;
						_10 = cll__if(pos);
						if (!(_10.status))
						{
							success_13 = false;
							_12 = cll_expr(pos);
							if (!(_12.status))
							{
								return {};
							}
							else 
							{
								success_13 = true;
								pos += _12.node.length();
								_2 = _12.node;
							}
						}
						else 
						{
							success_11 = true;
							pos += _10.node.length();
							_2 = _10.node;
						}
					}
					else 
					{
						success_9 = true;
						pos += _8.node.length();
						_2 = _8.node;
					}
				}
				else 
				{
					success_7 = true;
					pos += _6.node.length();
					_2 = _6.node;
				}
			}
			else 
			{
				success_5 = true;
				pos += _4.node.length();
				_2 = _4.node;
			}
			success_3 = true;
			skip_spaces(pos);
			success_15 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_8))
			{
				reportError(pos, "auto_8 ");
				return {};
			}
			_14 = *pos;
			success_15 = true;
			pos += 1;
			::Parser::Types::cll data = _2;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll, data)};
		}
		template <class IT>
		::Parser::Rule_res cll_expr_compare(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Rule_res _0;
			::Parser::bool_t success_1 = false;
			::Parser::bool_t success_3 = false;
			::Parser::bool_t success_8 = false;
			::Parser::bool_t success_5 = false;
			::Parser::Token _4;
			::Parser::arr_t<::Parser::Token> shadow_6;
			::Parser::Rule_res _7;
			::Parser::arr_t<::Parser::Rule> shadow_9;
			success_1 = false;
			_0 = cll_expr_arithmetic(pos);
			if (!(_0.status))
			{
				return {};
			}
			success_1 = true;
			pos += _0.node.length();
			skip_spaces(pos);
			success_3 = false;
			auto begin_10 = pos;
			success_8 = false;
			success_5 = false;
			while (1)
			{
				if (!(begin_10->name() == ::Parser::Tokens::cll_COMPARE_OP))
				{
					reportError(pos, "cll compare_op ");
					break;
				}
				_4 = *begin_10;
				success_5 = true;
				begin_10 += 1;
				shadow_6.push_back(_4);
				skip_spaces(begin_10);
				_7 = cll_expr_arithmetic(begin_10);
				if (!(_7.status))
				{
					reportError(pos, "cll expr arithmetic ");
					break;
				}
				success_8 = true;
				begin_10 += _7.node.length();
				shadow_9.push_back(_7.node);
			}
			if (success_5 && success_8)
			{
				success_3 = true;
				pos = begin_10;
			}
			::Parser::Types::cll_expr_compare data;
			data.sequence = shadow_9;
			data.operators = shadow_6;
			data.first = _0.node;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_expr_compare, data)};
		}
		template <class IT>
		::Parser::Rule_res cll_expr_arithmetic(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Rule_res _0;
			::Parser::bool_t success_1 = false;
			::Parser::bool_t success_3 = false;
			::Parser::bool_t success_13 = false;
			::Parser::bool_t success_5 = false;
			::Parser::arr_t<::Parser::Token> _4;
			::Parser::Token _6;
			::Parser::bool_t success_7 = false;
			::Parser::arr_t<::Parser::Token> shadow_8;
			::Parser::Token _9;
			::Parser::bool_t success_10 = false;
			::Parser::arr_t<::Parser::Token> shadow_11;
			::Parser::Rule_res _12;
			::Parser::arr_t<::Parser::Rule> shadow_14;
			success_1 = false;
			_0 = cll_expr_term(pos);
			if (!(_0.status))
			{
				return {};
			}
			success_1 = true;
			pos += _0.node.length();
			skip_spaces(pos);
			success_3 = false;
			auto begin_15 = pos;
			success_13 = false;
			success_5 = false;
			while (1)
			{
				success_7 = false;
				if (!(begin_15->name() == ::Parser::Tokens::MINUS))
				{
					success_10 = false;
					if (!(begin_15->name() == ::Parser::Tokens::PLUS))
					{
						break;
					}
					else 
					{
						_9 = *begin_15;
						success_10 = true;
						begin_15 += 1;
						shadow_11.push_back(_9);
						_4.push_back(_9);
					}
				}
				else 
				{
					_6 = *begin_15;
					success_7 = true;
					begin_15 += 1;
					shadow_8.push_back(_6);
					_4.push_back(_6);
				}
				success_5 = true;
				skip_spaces(begin_15);
				_12 = cll_expr_term(begin_15);
				if (!(_12.status))
				{
					reportError(pos, "cll expr term ");
					break;
				}
				success_13 = true;
				begin_15 += _12.node.length();
				shadow_14.push_back(_12.node);
			}
			if (success_5 && success_13)
			{
				success_3 = true;
				pos = begin_15;
			}
			::Parser::Types::cll_expr_arithmetic data;
			data.sequence = shadow_14;
			data.operators = _4;
			data.first = _0.node;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_expr_arithmetic, data)};
		}
		template <class IT>
		::Parser::Rule_res cll__if(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Rule_res _2;
			::Parser::bool_t success_3 = false;
			::Parser::Rule_res _4;
			::Parser::bool_t success_5 = false;
			success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_9))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			success_3 = false;
			_2 = cll_expr(pos);
			if (!(_2.status))
			{
				reportError(pos, "cll expr ");
				return {};
			}
			success_3 = true;
			pos += _2.node.length();
			skip_spaces(pos);
			success_5 = false;
			_4 = cll_stmt(pos);
			if (!(_4.status))
			{
				reportError(pos, "cll stmt ");
				return {};
			}
			success_5 = true;
			pos += _4.node.length();
			::Parser::Types::cll__if data;
			data.stmt = _4.node;
			data.expr = _2.node;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll__if, data)};
		}
		template <class IT>
		::Parser::Rule_res cll_function_parameters(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::bool_t success_1 = false;
			::Parser::bool_t success_3 = false;
			::Parser::Token _2;
			::Parser::bool_t success_5 = false;
			::Parser::bool_t success_10 = false;
			::Parser::bool_t success_7 = false;
			::Parser::Token _6;
			::Parser::arr_t<::Parser::Token> shadow_8;
			::Parser::Token _9;
			::Parser::arr_t<::Parser::Token> shadow_11;
			success_1 = false;
			auto begin_13 = pos;
			success_3 = false;
			if (!(begin_13->name() == ::Parser::Tokens::ID))
			{
				return {};
			}
			_2 = *begin_13;
			success_3 = true;
			begin_13 += 1;
			skip_spaces(begin_13);
			success_5 = false;
			auto begin_12 = begin_13;
			success_10 = false;
			success_7 = false;
			while (1)
			{
				if (!(begin_12->name() == ::Parser::Tokens::AUTO_1))
				{
					reportError(pos, "auto_1 ");
					break;
				}
				_6 = *begin_12;
				success_7 = true;
				begin_12 += 1;
				shadow_8.push_back(_6);
				skip_spaces(begin_12);
				if (!(begin_12->name() == ::Parser::Tokens::ID))
				{
					reportError(pos, "id ");
					break;
				}
				_9 = *begin_12;
				success_10 = true;
				begin_12 += 1;
				shadow_11.push_back(_9);
			}
			if (success_7 && success_10)
			{
				success_5 = true;
				begin_13 = begin_12;
			}
			if (success_3)
			{
				success_1 = true;
				pos = begin_13;
			}
			::Parser::Types::cll_function_parameters data;
			data.second = shadow_11;
			data.first = _2;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_function_parameters, data)};
		}
		template <class IT>
		::Parser::Rule_res cll_function_arguments(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::bool_t success_1 = false;
			::Parser::bool_t success_3 = false;
			::Parser::Rule_res _2;
			::Parser::bool_t success_5 = false;
			::Parser::bool_t success_10 = false;
			::Parser::bool_t success_7 = false;
			::Parser::Token _6;
			::Parser::arr_t<::Parser::Token> shadow_8;
			::Parser::Rule_res _9;
			::Parser::arr_t<::Parser::Rule> shadow_11;
			success_1 = false;
			auto begin_13 = pos;
			success_3 = false;
			_2 = cll_expr(begin_13);
			if (!(_2.status))
			{
				return {};
			}
			success_3 = true;
			begin_13 += _2.node.length();
			skip_spaces(begin_13);
			success_5 = false;
			auto begin_12 = begin_13;
			success_10 = false;
			success_7 = false;
			while (1)
			{
				if (!(begin_12->name() == ::Parser::Tokens::AUTO_1))
				{
					reportError(pos, "auto_1 ");
					break;
				}
				_6 = *begin_12;
				success_7 = true;
				begin_12 += 1;
				shadow_8.push_back(_6);
				skip_spaces(begin_12);
				_9 = cll_expr(begin_12);
				if (!(_9.status))
				{
					reportError(pos, "cll expr ");
					break;
				}
				success_10 = true;
				begin_12 += _9.node.length();
				shadow_11.push_back(_9.node);
			}
			if (success_7 && success_10)
			{
				success_5 = true;
				begin_13 = begin_12;
			}
			if (success_3)
			{
				success_1 = true;
				pos = begin_13;
			}
			::Parser::Types::cll_function_arguments data;
			data.second = shadow_11;
			data.first = _2.node;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_function_arguments, data)};
		}
		template <class IT>
		::Parser::Rule_res cll_function_decl(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Token _2;
			::Parser::bool_t success_3 = false;
			::Parser::arr_t<::Parser::Token> shadow_4;
			::Parser::bool_t success_5 = false;
			::Parser::Rule_res _6;
			::Parser::bool_t success_7 = false;
			::Parser::Rule_res _8;
			::Parser::bool_t success_9 = false;
			success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_10))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			success_3 = false;
			success_5 = false;
			while (pos->name() == ::Parser::Tokens::ID)
			{
				_2 = *pos;
				success_3 = true;
				pos += 1;
				shadow_4.push_back(_2);
				success_5 = true;
			}
			if (!success_5)
			{
				reportError(pos, "id ");
				return {};
			}
			skip_spaces(pos);
			success_7 = false;
			_6 = cll_function_body_decl(pos);
			if (!(_6.status))
			{
				reportError(pos, "cll function_body_decl ");
				return {};
			}
			success_7 = true;
			pos += _6.node.length();
			skip_spaces(pos);
			success_9 = false;
			_8 = cll_stmt(pos);
			if (_8.status)
			{
				success_9 = true;
				pos += _8.node.length();
			}
			::Parser::Types::cll_function_decl data;
			data.stmt = _8.node;
			data.name = _6.node;
			data.type = shadow_4;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_function_decl, data)};
		}
		template <class IT>
		::Parser::Rule_res cll__variable(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::bool_t success_3 = false;
			::Parser::Token _2;
			::Parser::Token _4;
			::Parser::bool_t success_5 = false;
			::Parser::Token _6;
			::Parser::bool_t success_7 = false;
			::Parser::Token _9;
			::Parser::bool_t success_10 = false;
			::Parser::bool_t success_12 = false;
			::Parser::bool_t success_18 = false;
			::Parser::bool_t success_16 = false;
			::Parser::bool_t success_14 = false;
			::Parser::Token _13;
			::Parser::Rule_res _15;
			::Parser::Token _17;
			::Parser::Token _20;
			::Parser::bool_t success_21 = false;
			::Parser::bool_t success_23 = false;
			::Parser::Token _22;
			::Parser::Token _24;
			::Parser::bool_t success_25 = false;
			::Parser::Token _26;
			::Parser::bool_t success_27 = false;
			success_1 = false;
			auto begin_8 = pos;
			success_3 = false;
			do
			{
				success_5 = false;
				if (!(begin_8->name() == ::Parser::Tokens::AUTO_11))
				{
					success_7 = false;
					if (!(begin_8->name() == ::Parser::Tokens::AUTO_12))
					{
						break;
					}
					else 
					{
						_6 = *begin_8;
						success_7 = true;
						begin_8 += 1;
						_2 = _6;
					}
				}
				else 
				{
					_4 = *begin_8;
					success_5 = true;
					begin_8 += 1;
					_2 = _4;
				}
				success_3 = true;
				_0 = _2;
			}
			while(0);
			if (success_3)
			{
				success_1 = true;
				pos = begin_8;
			}
			skip_spaces(pos);
			success_10 = false;
			if (!(pos->name() == ::Parser::Tokens::ID))
			{
				reportError(pos, "id ");
				return {};
			}
			_9 = *pos;
			success_10 = true;
			pos += 1;
			skip_spaces(pos);
			success_12 = false;
			auto begin_19 = pos;
			success_18 = false;
			success_16 = false;
			success_14 = false;
			do
			{
				if (!(begin_19->name() == ::Parser::Tokens::AUTO_13))
				{
					reportError(pos, "auto_13 ");
					break;
				}
				_13 = *begin_19;
				success_14 = true;
				begin_19 += 1;
				skip_spaces(begin_19);
				_15 = cll_expr(begin_19);
				if (!(_15.status))
				{
					reportError(pos, "cll expr ");
					break;
				}
				success_16 = true;
				begin_19 += _15.node.length();
				skip_spaces(begin_19);
				if (!(begin_19->name() == ::Parser::Tokens::AUTO_14))
				{
					reportError(pos, "auto_14 ");
					break;
				}
				_17 = *begin_19;
				success_18 = true;
				begin_19 += 1;
			}
			while(0);
			if (success_14 && success_16 && success_18)
			{
				success_12 = true;
				pos = begin_19;
			}
			skip_spaces(pos);
			success_21 = false;
			auto begin_28 = pos;
			success_23 = false;
			do
			{
				success_25 = false;
				if (!(begin_28->name() == ::Parser::Tokens::AUTO_11))
				{
					success_27 = false;
					if (!(begin_28->name() == ::Parser::Tokens::AUTO_12))
					{
						break;
					}
					else 
					{
						_26 = *begin_28;
						success_27 = true;
						begin_28 += 1;
						_22 = _26;
					}
				}
				else 
				{
					_24 = *begin_28;
					success_25 = true;
					begin_28 += 1;
					_22 = _24;
				}
				success_23 = true;
				_20 = _22;
			}
			while(0);
			if (success_23)
			{
				success_21 = true;
				pos = begin_28;
			}
			::Parser::Types::cll__variable data;
			data.pos = _20;
			data.brace_expression = _15.node;
			data.name = _9;
			data.pre = _0;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll__variable, data)};
		}
		template <class IT>
		::Parser::Rule_res cll_expr(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Rule_res _0;
			::Parser::bool_t success_1 = false;
			success_1 = false;
			_0 = cll_expr_logical(pos);
			if (!(_0.status))
			{
				return {};
			}
			success_1 = true;
			pos += _0.node.length();
			::Parser::Types::cll_expr data = _0.node;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_expr, data)};
		}
		template <class IT>
		::Parser::Rule_res cll_function_body_call(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Rule_res _2;
			::Parser::bool_t success_3 = false;
			::Parser::Token _4;
			::Parser::bool_t success_5 = false;
			success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_5))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			success_3 = false;
			_2 = cll_function_arguments(pos);
			if (!(_2.status))
			{
				reportError(pos, "cll function_arguments ");
				return {};
			}
			success_3 = true;
			pos += _2.node.length();
			skip_spaces(pos);
			success_5 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_6))
			{
				reportError(pos, "auto_6 ");
				return {};
			}
			_4 = *pos;
			success_5 = true;
			pos += 1;
			::Parser::Types::cll_function_body_call data = _2.node;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_function_body_call, data)};
		}
		template <class IT>
		::Parser::Rule_res cll_stmt(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Rule_res _2;
			::Parser::bool_t success_3 = false;
			::Parser::arr_t<::Parser::Rule> shadow_4;
			::Parser::Token _5;
			::Parser::bool_t success_6 = false;
			success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_0))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			success_3 = false;
			_2 = rule_member(pos);
			while (_2.status)
			{
				success_3 = true;
				pos += _2.node.length();
				shadow_4.push_back(_2.node);
				_2 = rule_member(pos);
			}
			skip_spaces(pos);
			success_6 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_2))
			{
				reportError(pos, "auto_2 ");
				return {};
			}
			_5 = *pos;
			success_6 = true;
			pos += 1;
			::Parser::Types::cll_stmt data = shadow_4;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_stmt, data)};
		}
		template <class IT>
		::Parser::Rule_res rule(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Token _2;
			::Parser::bool_t success_3 = false;
			::Parser::Rule_res _4;
			::Parser::bool_t success_5 = false;
			::Parser::arr_t<::Parser::Rule> shadow_6;
			::Parser::bool_t success_7 = false;
			::Parser::Rule_res _8;
			::Parser::bool_t success_9 = false;
			::Parser::Rule_res _10;
			::Parser::bool_t success_11 = false;
			::Parser::arr_t<::Parser::Rule> shadow_12;
			::Parser::Token _13;
			::Parser::bool_t success_14 = false;
			success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::ID))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			success_3 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_15))
			{
				reportError(pos, "auto_15 ");
				return {};
			}
			_2 = *pos;
			success_3 = true;
			pos += 1;
			skip_spaces(pos);
			success_5 = false;
			_4 = rule_member(pos);
			success_7 = false;
			while (_4.status)
			{
				success_5 = true;
				pos += _4.node.length();
				shadow_6.push_back(_4.node);
				_4 = rule_member(pos);
				success_7 = true;
			}
			if (!success_7)
			{
				reportError(pos, "rule member ");
				return {};
			}
			skip_spaces(pos);
			success_9 = false;
			_8 = rule_data_block(pos);
			if (_8.status)
			{
				success_9 = true;
				pos += _8.node.length();
			}
			skip_spaces(pos);
			success_11 = false;
			_10 = rule_nested_rule(pos);
			while (_10.status)
			{
				success_11 = true;
				pos += _10.node.length();
				shadow_12.push_back(_10.node);
				_10 = rule_nested_rule(pos);
			}
			skip_spaces(pos);
			success_14 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_8))
			{
				reportError(pos, "auto_8 ");
				return {};
			}
			_13 = *pos;
			success_14 = true;
			pos += 1;
			::Parser::Types::rule data;
			data.nested_rules = shadow_12;
			data.data_block = _8.node;
			data.rule = shadow_6;
			data.name = _0;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::rule, data)};
		}
		template <class IT>
		::Parser::Rule_res rule_value(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Token _2;
			::Parser::bool_t success_3 = false;
			success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_16))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			success_3 = false;
			if (!(pos->name() == ::Parser::Tokens::ID))
			{
				reportError(pos, "id ");
				return {};
			}
			_2 = *pos;
			success_3 = true;
			pos += 1;
			::Parser::Types::rule_value data = _2;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::rule_value, data)};
		}
		template <class IT>
		::Parser::Rule_res rule_data_block(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Rule _0;
			::Parser::bool_t success_1 = false;
			::Parser::Rule_res _2;
			::Parser::bool_t success_3 = false;
			::Parser::Rule_res _4;
			::Parser::bool_t success_5 = false;
			success_1 = false;
			success_3 = false;
			_2 = rule_data_block_regular_datablock(pos);
			if (!(_2.status))
			{
				success_5 = false;
				_4 = rule_data_block_templated_datablock(pos);
				if (!(_4.status))
				{
					return {};
				}
				else 
				{
					success_5 = true;
					pos += _4.node.length();
					_0 = _4.node;
				}
			}
			else 
			{
				success_3 = true;
				pos += _2.node.length();
				_0 = _2.node;
			}
			success_1 = true;
			::Parser::Types::rule_data_block data = _0;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::rule_data_block, data)};
		}
		template <class IT>
		::Parser::Rule_res cll_function_body_decl(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Rule_res _2;
			::Parser::bool_t success_3 = false;
			::Parser::Token _4;
			::Parser::bool_t success_5 = false;
			success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_5))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			success_3 = false;
			_2 = cll_function_parameters(pos);
			if (!(_2.status))
			{
				reportError(pos, "cll function_parameters ");
				return {};
			}
			success_3 = true;
			pos += _2.node.length();
			skip_spaces(pos);
			success_5 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_6))
			{
				reportError(pos, "auto_6 ");
				return {};
			}
			_4 = *pos;
			success_5 = true;
			pos += 1;
			::Parser::Types::cll_function_body_decl data = _2.node;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_function_body_decl, data)};
		}
		template <class IT>
		::Parser::Rule_res rule_name(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Token _2;
			::Parser::bool_t success_3 = false;
			::Parser::bool_t success_5 = false;
			::Parser::bool_t success_10 = false;
			::Parser::bool_t success_7 = false;
			::Parser::Token _6;
			::Parser::arr_t<::Parser::Token> shadow_8;
			::Parser::Token _9;
			::Parser::arr_t<::Parser::Token> shadow_11;
			success_1 = false;
			if (pos->name() == ::Parser::Tokens::AUTO_17)
			{
				_0 = *pos;
				success_1 = true;
				pos += 1;
			}
			skip_spaces(pos);
			success_3 = false;
			if (!(pos->name() == ::Parser::Tokens::ID))
			{
				reportError(pos, "id ");
				return {};
			}
			_2 = *pos;
			success_3 = true;
			pos += 1;
			skip_spaces(pos);
			success_5 = false;
			auto begin_12 = pos;
			success_10 = false;
			success_7 = false;
			while (1)
			{
				if (!(begin_12->name() == ::Parser::Tokens::DOT))
				{
					reportError(pos, "dot ");
					break;
				}
				_6 = *begin_12;
				success_7 = true;
				begin_12 += 1;
				shadow_8.push_back(_6);
				skip_spaces(begin_12);
				if (!(begin_12->name() == ::Parser::Tokens::ID))
				{
					reportError(pos, "id ");
					break;
				}
				_9 = *begin_12;
				success_10 = true;
				begin_12 += 1;
				shadow_11.push_back(_9);
			}
			if (success_7 && success_10)
			{
				success_5 = true;
				pos = begin_12;
			}
			::Parser::Types::rule_name data;
			data.nested_name = shadow_11;
			data.name = _2;
			data.is_nested = _0;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::rule_name, data)};
		}
		template <class IT>
		::Parser::Rule_res array(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::bool_t success_3 = false;
			::Parser::bool_t success_5 = false;
			::Parser::bool_t success_10 = false;
			::Parser::bool_t success_7 = false;
			::Parser::Rule_res _6;
			::Parser::arr_t<::Parser::Rule> shadow_8;
			::Parser::Token _9;
			::Parser::arr_t<::Parser::Token> shadow_11;
			::Parser::Token _14;
			::Parser::bool_t success_15 = false;
			success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_13))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			success_3 = false;
			auto begin_13 = pos;
			do
			{
				success_5 = false;
				auto begin_12 = begin_13;
				success_10 = false;
				success_7 = false;
				while (1)
				{
					_6 = cll_expr(begin_12);
					if (!(_6.status))
					{
						reportError(pos, "cll expr ");
						break;
					}
					success_7 = true;
					begin_12 += _6.node.length();
					shadow_8.push_back(_6.node);
					skip_spaces(begin_12);
					if (!(begin_12->name() == ::Parser::Tokens::AUTO_1))
					{
						reportError(pos, "auto_1 ");
						break;
					}
					_9 = *begin_12;
					success_10 = true;
					begin_12 += 1;
					shadow_11.push_back(_9);
				}
				if (success_7 && success_10)
				{
					success_5 = true;
					begin_13 = begin_12;
				}
			}
			while(0);
			success_3 = true;
			pos = begin_13;
			skip_spaces(pos);
			success_15 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_14))
			{
				reportError(pos, "auto_14 ");
				return {};
			}
			_14 = *pos;
			success_15 = true;
			pos += 1;
			::Parser::Types::array data = shadow_8;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::array, data)};
		}
		template <class IT>
		::Parser::Rule_res rule_member(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Rule _0;
			::Parser::bool_t success_1 = false;
			::Parser::bool_t success_3 = false;
			::Parser::Rule _2;
			::Parser::Rule_res _4;
			::Parser::bool_t success_5 = false;
			::Parser::Rule_res _6;
			::Parser::bool_t success_7 = false;
			::Parser::any_t _9;
			::Parser::bool_t success_10 = false;
			::Parser::Token _11;
			::Parser::bool_t success_12 = false;
			::Parser::Token _13;
			::Parser::bool_t success_14 = false;
			::Parser::Token _15;
			::Parser::bool_t success_16 = false;
			::Parser::Token _17;
			::Parser::bool_t success_18 = false;
			::Parser::Token _19;
			::Parser::bool_t success_20 = false;
			::Parser::Token _21;
			::Parser::bool_t success_22 = false;
			::Parser::Token _23;
			::Parser::bool_t success_24 = false;
			::Parser::Token _25;
			::Parser::bool_t success_26 = false;
			::Parser::Token _27;
			::Parser::bool_t success_28 = false;
			::Parser::Rule_res _29;
			::Parser::bool_t success_30 = false;
			::Parser::Rule_res _31;
			::Parser::bool_t success_32 = false;
			::Parser::Rule_res _33;
			::Parser::bool_t success_34 = false;
			::Parser::Rule_res _35;
			::Parser::bool_t success_36 = false;
			success_1 = false;
			auto begin_8 = pos;
			success_3 = false;
			do
			{
				success_5 = false;
				_4 = rule_keyvalue(begin_8);
				if (!(_4.status))
				{
					success_7 = false;
					_6 = rule_value(begin_8);
					if (!(_6.status))
					{
						break;
					}
					else 
					{
						success_7 = true;
						begin_8 += _6.node.length();
						_2 = _6.node;
					}
				}
				else 
				{
					success_5 = true;
					begin_8 += _4.node.length();
					_2 = _4.node;
				}
				success_3 = true;
				_0 = _2;
			}
			while(0);
			if (success_3)
			{
				success_1 = true;
				pos = begin_8;
			}
			skip_spaces(pos);
			success_10 = false;
			success_12 = false;
			if (!(pos->name() == ::Parser::Tokens::rule_NOSPACE))
			{
				success_14 = false;
				if (!(pos->name() == ::Parser::Tokens::rule_ESCAPED))
				{
					success_16 = false;
					if (!(pos->name() == ::Parser::Tokens::STRING))
					{
						success_18 = false;
						if (!(pos->name() == ::Parser::Tokens::rule_HEX))
						{
							success_20 = false;
							if (!(pos->name() == ::Parser::Tokens::rule_BIN))
							{
								success_22 = false;
								if (!(pos->name() == ::Parser::Tokens::LINEAR_COMMENT))
								{
									success_24 = false;
									if (!(pos->name() == ::Parser::Tokens::rule_OP))
									{
										success_26 = false;
										if (!(pos->name() == ::Parser::Tokens::rule_CSEQUENCE))
										{
											success_28 = false;
											if (!(pos->name() == ::Parser::Tokens::DOT))
											{
												success_30 = false;
												_29 = rule_group(pos);
												if (!(_29.status))
												{
													success_32 = false;
													_31 = cll(pos);
													if (!(_31.status))
													{
														success_34 = false;
														_33 = rule_name(pos);
														if (!(_33.status))
														{
															return {};
														}
														else 
														{
															success_34 = true;
															pos += _33.node.length();
															_9 = _33.node;
														}
													}
													else 
													{
														success_32 = true;
														pos += _31.node.length();
														_9 = _31.node;
													}
												}
												else 
												{
													success_30 = true;
													pos += _29.node.length();
													_9 = _29.node;
												}
											}
											else 
											{
												_27 = *pos;
												success_28 = true;
												pos += 1;
												_9 = _27;
											}
										}
										else 
										{
											_25 = *pos;
											success_26 = true;
											pos += 1;
											_9 = _25;
										}
									}
									else 
									{
										_23 = *pos;
										success_24 = true;
										pos += 1;
										_9 = _23;
									}
								}
								else 
								{
									_21 = *pos;
									success_22 = true;
									pos += 1;
									_9 = _21;
								}
							}
							else 
							{
								_19 = *pos;
								success_20 = true;
								pos += 1;
								_9 = _19;
							}
						}
						else 
						{
							_17 = *pos;
							success_18 = true;
							pos += 1;
							_9 = _17;
						}
					}
					else 
					{
						_15 = *pos;
						success_16 = true;
						pos += 1;
						_9 = _15;
					}
				}
				else 
				{
					_13 = *pos;
					success_14 = true;
					pos += 1;
					_9 = _13;
				}
			}
			else 
			{
				_11 = *pos;
				success_12 = true;
				pos += 1;
				_9 = _11;
			}
			success_10 = true;
			skip_spaces(pos);
			success_36 = false;
			_35 = rule_quantifier(pos);
			if (_35.status)
			{
				success_36 = true;
				pos += _35.node.length();
			}
			::Parser::Types::rule_member data;
			data.quantifier = _35.node;
			data.val = _9;
			data.prefix = _0;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::rule_member, data)};
		}
		template <class IT>
		::Parser::Rule_res cll_expr_value(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Rule _0;
			::Parser::bool_t success_1 = false;
			::Parser::Rule_res _2;
			::Parser::bool_t success_3 = false;
			::Parser::Rule_res _4;
			::Parser::bool_t success_5 = false;
			::Parser::Rule_res _6;
			::Parser::bool_t success_7 = false;
			::Parser::Rule_res _8;
			::Parser::bool_t success_9 = false;
			::Parser::Rule_res _10;
			::Parser::bool_t success_11 = false;
			success_1 = false;
			success_3 = false;
			_2 = cll__variable(pos);
			if (!(_2.status))
			{
				success_5 = false;
				_4 = cll_expr_group(pos);
				if (!(_4.status))
				{
					success_7 = false;
					_6 = rvalue(pos);
					if (!(_6.status))
					{
						success_9 = false;
						_8 = cll_method_call(pos);
						if (!(_8.status))
						{
							success_11 = false;
							_10 = cll_function_call(pos);
							if (!(_10.status))
							{
								return {};
							}
							else 
							{
								success_11 = true;
								pos += _10.node.length();
								_0 = _10.node;
							}
						}
						else 
						{
							success_9 = true;
							pos += _8.node.length();
							_0 = _8.node;
						}
					}
					else 
					{
						success_7 = true;
						pos += _6.node.length();
						_0 = _6.node;
					}
				}
				else 
				{
					success_5 = true;
					pos += _4.node.length();
					_0 = _4.node;
				}
			}
			else 
			{
				success_3 = true;
				pos += _2.node.length();
				_0 = _2.node;
			}
			success_1 = true;
			::Parser::Types::cll_expr_value data = _0;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_expr_value, data)};
		}
		template <class IT>
		::Parser::Rule_res object(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::bool_t success_3 = false;
			::Parser::bool_t success_35 = false;
			::Parser::bool_t success_13 = false;
			::Parser::bool_t success_11 = false;
			::Parser::bool_t success_5 = false;
			::Parser::Token _4;
			::Parser::Token _6;
			::Parser::bool_t success_7 = false;
			::Parser::Token _8;
			::Parser::bool_t success_9 = false;
			::Parser::Token _10;
			::Parser::Rule_res _12;
			::Parser::bool_t success_15 = false;
			::Parser::bool_t success_31 = false;
			::Parser::bool_t success_28 = false;
			::Parser::bool_t success_20 = false;
			::Parser::bool_t success_17 = false;
			::Parser::Token _16;
			::Parser::arr_t<::Parser::Token> shadow_18;
			::Parser::arr_t<::Parser::Token> _19;
			::Parser::Token _21;
			::Parser::bool_t success_22 = false;
			::Parser::arr_t<::Parser::Token> shadow_23;
			::Parser::Token _24;
			::Parser::bool_t success_25 = false;
			::Parser::arr_t<::Parser::Token> shadow_26;
			::Parser::Token _27;
			::Parser::arr_t<::Parser::Token> shadow_29;
			::Parser::Rule_res _30;
			::Parser::arr_t<::Parser::Rule> shadow_32;
			::Parser::Token _34;
			::Parser::Token _37;
			::Parser::bool_t success_38 = false;
			success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_0))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			success_3 = false;
			auto begin_36 = pos;
			success_35 = false;
			success_13 = false;
			success_11 = false;
			success_5 = false;
			do
			{
				success_7 = false;
				if (!(begin_36->name() == ::Parser::Tokens::ID))
				{
					success_9 = false;
					if (!(begin_36->name() == ::Parser::Tokens::NUMBER))
					{
						break;
					}
					else 
					{
						_8 = *begin_36;
						success_9 = true;
						begin_36 += 1;
						_4 = _8;
					}
				}
				else 
				{
					_6 = *begin_36;
					success_7 = true;
					begin_36 += 1;
					_4 = _6;
				}
				success_5 = true;
				skip_spaces(begin_36);
				if (!(begin_36->name() == ::Parser::Tokens::AUTO_15))
				{
					reportError(pos, "auto_15 ");
					break;
				}
				_10 = *begin_36;
				success_11 = true;
				begin_36 += 1;
				skip_spaces(begin_36);
				_12 = cll_expr(begin_36);
				if (!(_12.status))
				{
					reportError(pos, "cll expr ");
					break;
				}
				success_13 = true;
				begin_36 += _12.node.length();
				skip_spaces(begin_36);
				success_15 = false;
				auto begin_33 = begin_36;
				success_31 = false;
				success_28 = false;
				success_20 = false;
				success_17 = false;
				while (1)
				{
					if (!(begin_33->name() == ::Parser::Tokens::AUTO_1))
					{
						reportError(pos, "auto_1 ");
						break;
					}
					_16 = *begin_33;
					success_17 = true;
					begin_33 += 1;
					shadow_18.push_back(_16);
					skip_spaces(begin_33);
					success_22 = false;
					if (!(begin_33->name() == ::Parser::Tokens::ID))
					{
						success_25 = false;
						if (!(begin_33->name() == ::Parser::Tokens::NUMBER))
						{
							break;
						}
						else 
						{
							_24 = *begin_33;
							success_25 = true;
							begin_33 += 1;
							shadow_26.push_back(_24);
							_19.push_back(_24);
						}
					}
					else 
					{
						_21 = *begin_33;
						success_22 = true;
						begin_33 += 1;
						shadow_23.push_back(_21);
						_19.push_back(_21);
					}
					success_20 = true;
					skip_spaces(begin_33);
					if (!(begin_33->name() == ::Parser::Tokens::AUTO_15))
					{
						reportError(pos, "auto_15 ");
						break;
					}
					_27 = *begin_33;
					success_28 = true;
					begin_33 += 1;
					shadow_29.push_back(_27);
					skip_spaces(begin_33);
					_30 = cll_expr(begin_33);
					if (!(_30.status))
					{
						reportError(pos, "cll expr ");
						break;
					}
					success_31 = true;
					begin_33 += _30.node.length();
					shadow_32.push_back(_30.node);
				}
				if (success_17 && success_20 && success_28 && success_31)
				{
					success_15 = true;
					begin_36 = begin_33;
				}
				skip_spaces(begin_36);
				if (!(begin_36->name() == ::Parser::Tokens::AUTO_8))
				{
					reportError(pos, "auto_8 ");
					break;
				}
				_34 = *begin_36;
				success_35 = true;
				begin_36 += 1;
			}
			while(0);
			if (success_5 && success_11 && success_13 && success_35)
			{
				success_3 = true;
				pos = begin_36;
			}
			skip_spaces(pos);
			success_38 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_2))
			{
				reportError(pos, "auto_2 ");
				return {};
			}
			_37 = *pos;
			success_38 = true;
			pos += 1;
			::Parser::Types::object data;
			data.values = shadow_32;
			data.keys = _19;
			data.value = _12.node;
			data.key = _4;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::object, data)};
		}
		template <class IT>
		::Parser::Rule_res rvalue(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::any_t _0;
			::Parser::bool_t success_1 = false;
			::Parser::Token _2;
			::Parser::bool_t success_3 = false;
			::Parser::Token _4;
			::Parser::bool_t success_5 = false;
			::Parser::Rule_res _6;
			::Parser::bool_t success_7 = false;
			::Parser::Rule_res _8;
			::Parser::bool_t success_9 = false;
			::Parser::Token _10;
			::Parser::bool_t success_11 = false;
			::Parser::Token _12;
			::Parser::bool_t success_13 = false;
			::Parser::Token _14;
			::Parser::bool_t success_15 = false;
			success_1 = false;
			success_3 = false;
			if (!(pos->name() == ::Parser::Tokens::BOOLEAN))
			{
				success_5 = false;
				if (!(pos->name() == ::Parser::Tokens::STRING))
				{
					success_7 = false;
					_6 = object(pos);
					if (!(_6.status))
					{
						success_9 = false;
						_8 = array(pos);
						if (!(_8.status))
						{
							success_11 = false;
							if (!(pos->name() == ::Parser::Tokens::AT))
							{
								success_13 = false;
								if (!(pos->name() == ::Parser::Tokens::ID))
								{
									success_15 = false;
									if (!(pos->name() == ::Parser::Tokens::NUMBER))
									{
										return {};
									}
									else 
									{
										_14 = *pos;
										success_15 = true;
										pos += 1;
										_0 = _14;
									}
								}
								else 
								{
									_12 = *pos;
									success_13 = true;
									pos += 1;
									_0 = _12;
								}
							}
							else 
							{
								_10 = *pos;
								success_11 = true;
								pos += 1;
								_0 = _10;
							}
						}
						else 
						{
							success_9 = true;
							pos += _8.node.length();
							_0 = _8.node;
						}
					}
					else 
					{
						success_7 = true;
						pos += _6.node.length();
						_0 = _6.node;
					}
				}
				else 
				{
					_4 = *pos;
					success_5 = true;
					pos += 1;
					_0 = _4;
				}
			}
			else 
			{
				_2 = *pos;
				success_3 = true;
				pos += 1;
				_0 = _2;
			}
			success_1 = true;
			::Parser::Types::rvalue data = _0;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::rvalue, data)};
		}
		template <class IT>
		::Parser::Rule_res cll_expr_term(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Rule_res _0;
			::Parser::bool_t success_1 = false;
			::Parser::bool_t success_3 = false;
			::Parser::bool_t success_16 = false;
			::Parser::bool_t success_5 = false;
			::Parser::arr_t<::Parser::Token> _4;
			::Parser::Token _6;
			::Parser::bool_t success_7 = false;
			::Parser::arr_t<::Parser::Token> shadow_8;
			::Parser::Token _9;
			::Parser::bool_t success_10 = false;
			::Parser::arr_t<::Parser::Token> shadow_11;
			::Parser::Token _12;
			::Parser::bool_t success_13 = false;
			::Parser::arr_t<::Parser::Token> shadow_14;
			::Parser::Rule_res _15;
			::Parser::arr_t<::Parser::Rule> shadow_17;
			success_1 = false;
			_0 = cll_expr_value(pos);
			if (!(_0.status))
			{
				return {};
			}
			success_1 = true;
			pos += _0.node.length();
			skip_spaces(pos);
			success_3 = false;
			auto begin_18 = pos;
			success_16 = false;
			success_5 = false;
			while (1)
			{
				success_7 = false;
				if (!(begin_18->name() == ::Parser::Tokens::DIVIDE))
				{
					success_10 = false;
					if (!(begin_18->name() == ::Parser::Tokens::MULTIPLE))
					{
						success_13 = false;
						if (!(begin_18->name() == ::Parser::Tokens::MODULO))
						{
							break;
						}
						else 
						{
							_12 = *begin_18;
							success_13 = true;
							begin_18 += 1;
							shadow_14.push_back(_12);
							_4.push_back(_12);
						}
					}
					else 
					{
						_9 = *begin_18;
						success_10 = true;
						begin_18 += 1;
						shadow_11.push_back(_9);
						_4.push_back(_9);
					}
				}
				else 
				{
					_6 = *begin_18;
					success_7 = true;
					begin_18 += 1;
					shadow_8.push_back(_6);
					_4.push_back(_6);
				}
				success_5 = true;
				skip_spaces(begin_18);
				_15 = cll_expr_value(begin_18);
				if (!(_15.status))
				{
					reportError(pos, "cll expr value ");
					break;
				}
				success_16 = true;
				begin_18 += _15.node.length();
				shadow_17.push_back(_15.node);
			}
			if (success_5 && success_16)
			{
				success_3 = true;
				pos = begin_18;
			}
			::Parser::Types::cll_expr_term data;
			data.sequence = shadow_17;
			data.operators = _4;
			data.first = _0.node;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_expr_term, data)};
		}
		template <class IT>
		::Parser::Rule_res rule_keyvalue(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::bool_t success_3 = false;
			::Parser::bool_t success_5 = false;
			::Parser::Token _4;
			success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::AT))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			success_3 = false;
			auto begin_6 = pos;
			success_5 = false;
			do
			{
				if (!(begin_6->name() == ::Parser::Tokens::ID))
				{
					reportError(pos, "id ");
					break;
				}
				_4 = *begin_6;
				success_5 = true;
				begin_6 += 1;
			}
			while(0);
			if (success_5)
			{
				success_3 = true;
				pos = begin_6;
			}
			::Parser::Types::rule_keyvalue data = _4;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::rule_keyvalue, data)};
		}
		template <class IT>
		::Parser::Rule_res rule_quantifier(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Token _2;
			::Parser::bool_t success_3 = false;
			::Parser::Token _4;
			::Parser::bool_t success_5 = false;
			::Parser::Token _6;
			::Parser::bool_t success_7 = false;
			success_1 = false;
			success_3 = false;
			if (!(pos->name() == ::Parser::Tokens::QUESTION_MARK))
			{
				success_5 = false;
				if (!(pos->name() == ::Parser::Tokens::PLUS))
				{
					success_7 = false;
					if (!(pos->name() == ::Parser::Tokens::MULTIPLE))
					{
						return {};
					}
					else 
					{
						_6 = *pos;
						success_7 = true;
						pos += 1;
						_0 = _6;
					}
				}
				else 
				{
					_4 = *pos;
					success_5 = true;
					pos += 1;
					_0 = _4;
				}
			}
			else 
			{
				_2 = *pos;
				success_3 = true;
				pos += 1;
				_0 = _2;
			}
			success_1 = true;
			::Parser::Types::rule_quantifier data = _0;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::rule_quantifier, data)};
		}
		template <class IT>
		::Parser::Rule_res main(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::bool_t success_1 = false;
			::Parser::bool_t success_3 = false;
			::Parser::bool_t success_16 = false;
			::Parser::arr_t<::Parser::any_t> _2;
			::Parser::Token _4;
			::Parser::bool_t success_5 = false;
			::Parser::arr_t<::Parser::Token> shadow_6;
			::Parser::Token _7;
			::Parser::bool_t success_8 = false;
			::Parser::arr_t<::Parser::Token> shadow_9;
			::Parser::Rule_res _10;
			::Parser::bool_t success_11 = false;
			::Parser::arr_t<::Parser::Rule> shadow_12;
			::Parser::Rule_res _13;
			::Parser::bool_t success_14 = false;
			::Parser::arr_t<::Parser::Rule> shadow_15;
			success_1 = false;
			auto begin_16 = pos;
			success_3 = false;
			success_16 = false;
			while (1)
			{
				success_5 = false;
				if (!(begin_16->name() == ::Parser::Tokens::SPACEMODE))
				{
					success_8 = false;
					if (!(begin_16->name() == ::Parser::Tokens::NAME))
					{
						success_11 = false;
						_10 = _use(begin_16);
						if (!(_10.status))
						{
							success_14 = false;
							_13 = rule(begin_16);
							if (!(_13.status))
							{
								break;
							}
							else 
							{
								success_14 = true;
								begin_16 += _13.node.length();
								shadow_15.push_back(_13.node);
								_2.push_back(_13.node);
							}
						}
						else 
						{
							success_11 = true;
							begin_16 += _10.node.length();
							shadow_12.push_back(_10.node);
							_2.push_back(_10.node);
						}
					}
					else 
					{
						_7 = *begin_16;
						success_8 = true;
						begin_16 += 1;
						shadow_9.push_back(_7);
						_2.push_back(_7);
					}
				}
				else 
				{
					_4 = *begin_16;
					success_5 = true;
					begin_16 += 1;
					shadow_6.push_back(_4);
					_2.push_back(_4);
				}
				success_3 = true;
				success_16 = true;
			}
			if (!success_16)
			{
				reportError(pos, "");
				return {};
			}
			if (success_3)
			{
				success_1 = true;
				pos = begin_16;
			}
			::Parser::Types::main data = _2;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::main, data)};
		}
		template <class IT>
		::Parser::Rule_res _use(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Rule_res _2;
			::Parser::bool_t success_3 = false;
			::Parser::bool_t success_5 = false;
			::Parser::bool_t success_10 = false;
			::Parser::bool_t success_7 = false;
			::Parser::Token _6;
			::Parser::arr_t<::Parser::Token> shadow_8;
			::Parser::Rule_res _9;
			::Parser::arr_t<::Parser::Rule> shadow_11;
			::Parser::Token _13;
			::Parser::bool_t success_14 = false;
			success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_18))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			success_3 = false;
			_2 = _use_unit(pos);
			if (!(_2.status))
			{
				reportError(pos, "_use unit ");
				return {};
			}
			success_3 = true;
			pos += _2.node.length();
			skip_spaces(pos);
			success_5 = false;
			auto begin_12 = pos;
			success_10 = false;
			success_7 = false;
			while (1)
			{
				if (!(begin_12->name() == ::Parser::Tokens::AUTO_1))
				{
					reportError(pos, "auto_1 ");
					break;
				}
				_6 = *begin_12;
				success_7 = true;
				begin_12 += 1;
				shadow_8.push_back(_6);
				skip_spaces(begin_12);
				_9 = _use_unit(begin_12);
				if (!(_9.status))
				{
					reportError(pos, "_use unit ");
					break;
				}
				success_10 = true;
				begin_12 += _9.node.length();
				shadow_11.push_back(_9.node);
			}
			if (success_7 && success_10)
			{
				success_5 = true;
				pos = begin_12;
			}
			skip_spaces(pos);
			success_14 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_8))
			{
				reportError(pos, "auto_8 ");
				return {};
			}
			_13 = *pos;
			success_14 = true;
			pos += 1;
			::Parser::Types::_use data;
			data.second = shadow_11;
			data.first = _2.node;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::_use, data)};
		}
		template <class IT>
		::Parser::Rule_res cll_loop_for(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Token _2;
			::Parser::bool_t success_3 = false;
			::Parser::Rule _4;
			::Parser::bool_t success_5 = false;
			::Parser::bool_t success_7 = false;
			::Parser::Rule _6;
			::Parser::Rule_res _8;
			::Parser::bool_t success_9 = false;
			::Parser::Rule_res _10;
			::Parser::bool_t success_11 = false;
			::Parser::Token _13;
			::Parser::bool_t success_14 = false;
			::Parser::Rule_res _15;
			::Parser::bool_t success_16 = false;
			::Parser::Token _17;
			::Parser::bool_t success_18 = false;
			::Parser::Rule_res _19;
			::Parser::bool_t success_20 = false;
			::Parser::Token _21;
			::Parser::bool_t success_22 = false;
			::Parser::Rule_res _23;
			::Parser::bool_t success_24 = false;
			success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_19))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			success_3 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_5))
			{
				reportError(pos, "auto_5 ");
				return {};
			}
			_2 = *pos;
			success_3 = true;
			pos += 1;
			skip_spaces(pos);
			success_5 = false;
			auto begin_12 = pos;
			success_7 = false;
			do
			{
				success_9 = false;
				_8 = cll__var(begin_12);
				if (!(_8.status))
				{
					success_11 = false;
					_10 = cll_expr(begin_12);
					if (!(_10.status))
					{
						break;
					}
					else 
					{
						success_11 = true;
						begin_12 += _10.node.length();
						_6 = _10.node;
					}
				}
				else 
				{
					success_9 = true;
					begin_12 += _8.node.length();
					_6 = _8.node;
				}
				success_7 = true;
				_4 = _6;
			}
			while(0);
			if (success_7)
			{
				success_5 = true;
				pos = begin_12;
			}
			skip_spaces(pos);
			success_14 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_8))
			{
				reportError(pos, "auto_8 ");
				return {};
			}
			_13 = *pos;
			success_14 = true;
			pos += 1;
			skip_spaces(pos);
			success_16 = false;
			_15 = cll_expr(pos);
			if (_15.status)
			{
				success_16 = true;
				pos += _15.node.length();
			}
			skip_spaces(pos);
			success_18 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_8))
			{
				reportError(pos, "auto_8 ");
				return {};
			}
			_17 = *pos;
			success_18 = true;
			pos += 1;
			skip_spaces(pos);
			success_20 = false;
			_19 = cll_expr(pos);
			if (_19.status)
			{
				success_20 = true;
				pos += _19.node.length();
			}
			skip_spaces(pos);
			success_22 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_6))
			{
				reportError(pos, "auto_6 ");
				return {};
			}
			_21 = *pos;
			success_22 = true;
			pos += 1;
			skip_spaces(pos);
			success_24 = false;
			_23 = cll_stmt(pos);
			if (!(_23.status))
			{
				reportError(pos, "cll stmt ");
				return {};
			}
			success_24 = true;
			pos += _23.node.length();
			::Parser::Types::cll_loop_for data;
			data.stmt = _23.node;
			data.end = _19.node;
			data.cond = _15.node;
			data.decl = _4;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_loop_for, data)};
		}
		template <class IT>
		::Parser::Rule_res rule_nested_rule(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Rule_res _2;
			::Parser::bool_t success_3 = false;
			success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_17))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			success_3 = false;
			_2 = rule(pos);
			if (!(_2.status))
			{
				reportError(pos, "rule ");
				return {};
			}
			success_3 = true;
			pos += _2.node.length();
			::Parser::Types::rule_nested_rule data = _2.node;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::rule_nested_rule, data)};
		}
		template <class IT>
		::Parser::Rule_res _use_unit(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Rule_res _2;
			::Parser::bool_t success_3 = false;
			success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::ID))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			success_3 = false;
			_2 = rvalue(pos);
			if (_2.status)
			{
				success_3 = true;
				pos += _2.node.length();
			}
			::Parser::Types::_use_unit data;
			data.value = _2.node;
			data.name = _0;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::_use_unit, data)};
		}
		template <class IT>
		::Parser::Rule_res rule_group(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Rule_res _2;
			::Parser::bool_t success_3 = false;
			::Parser::arr_t<::Parser::Rule> shadow_4;
			::Parser::Token _5;
			::Parser::bool_t success_6 = false;
			success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_5))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			success_3 = false;
			_2 = rule_member(pos);
			while (_2.status)
			{
				success_3 = true;
				pos += _2.node.length();
				shadow_4.push_back(_2.node);
				_2 = rule_member(pos);
			}
			skip_spaces(pos);
			success_6 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_6))
			{
				reportError(pos, "auto_6 ");
				return {};
			}
			_5 = *pos;
			success_6 = true;
			pos += 1;
			::Parser::Types::rule_group data = shadow_4;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::rule_group, data)};
		}
	};

} // Parser


#endif // PARSER
