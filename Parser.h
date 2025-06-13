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
#define PARSER_ARR_TYPE stdu::vector
#endif
#ifndef PARSER_ANY_TYPE
#define PARSER_ANY_TYPE std::any
#endif
#ifndef PARSER_NUM_TYPE
#define PARSER_NUM_TYPE double
#endif
#ifndef PARSER_STR_TYPE
#define PARSER_STR_TYPE std::string
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
		NONE, __WHITESPACE, AUTO_23, AUTO_22, AUTO_21, AUTO_20, AUTO_18, AUTO_17, AUTO_19, AUTO_16, AUTO_15, AUTO_14, AUTO_10, AUTO_8, AUTO_6, rule_BIN, rule_HEX, rule_ESCAPED, rule_NOSPACE, BOOLEAN, AUTO_1, rule_CSEQUENCE_ESCAPE, rule_CSEQUENCE_DIAPASON, rule_CSEQUENCE_SYMBOL, AUTO_9, AUTO_13, AUTO_3, AUTO_7, NUMBER, ID, AUTO_0, rule_OP, LINEAR_COMMENT, cll_LOGICAL_NOT, MODULO, cll_OP, MINUS, PLUS, QUESTION_MARK, rule_CSEQUENCE, MULTIPLE, AT, cll_LOGICAL_OR, AUTO_11, DOT, STRING, SPACEMODE, cll_ASSIGNMENT_OP, cll_COMPARE_OP, AUTO_2, NAME, cll_LOGICAL_AND, AUTO_5, AUTO_12, cll_TEMPLATE, cll_TYPE, AUTO_4, cll_LOGICAL_OP, DIVIDE
	};
	enum class Rules {
		NONE, cll_expr_value, cll_function_arguments, cll_method_call, moduleImport_from, cll_function_parameters, rule_quantifier, rule_data_block_templated_datablock, rule_data_block_regular_datablock, cll_function_body_decl, rule_group, rule_name, rule_keyvalue, rule_member, rule, _use_unit, main, _use, moduleImport_from_import_list, cll_expr_compare, moduleDeclaration, cll_stmt, cll, cll_expr_group, rvalue, array, cll__variable, object, cll__var, cll_expr_logical, cll_expr_term, cll_expr, cll_expr_arithmetic, cll__if, cll_function_decl, cll_function_call, rule_data_block, rule_nested_rule, cll_function_body_call, cll_loop_for, cll_loop_while, rule_data_block_regular_datablock_key, moduleImport, rule_value
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
			case Tokens::AUTO_23: return "AUTO_23";
			case Tokens::AUTO_22: return "AUTO_22";
			case Tokens::AUTO_21: return "AUTO_21";
			case Tokens::AUTO_20: return "AUTO_20";
			case Tokens::AUTO_18: return "AUTO_18";
			case Tokens::AUTO_17: return "AUTO_17";
			case Tokens::AUTO_19: return "AUTO_19";
			case Tokens::AUTO_16: return "AUTO_16";
			case Tokens::AUTO_15: return "AUTO_15";
			case Tokens::AUTO_14: return "AUTO_14";
			case Tokens::AUTO_10: return "AUTO_10";
			case Tokens::AUTO_8: return "AUTO_8";
			case Tokens::AUTO_6: return "AUTO_6";
			case Tokens::rule_BIN: return "rule_BIN";
			case Tokens::rule_HEX: return "rule_HEX";
			case Tokens::rule_ESCAPED: return "rule_ESCAPED";
			case Tokens::rule_NOSPACE: return "rule_NOSPACE";
			case Tokens::BOOLEAN: return "BOOLEAN";
			case Tokens::AUTO_1: return "AUTO_1";
			case Tokens::rule_CSEQUENCE_ESCAPE: return "rule_CSEQUENCE_ESCAPE";
			case Tokens::rule_CSEQUENCE_DIAPASON: return "rule_CSEQUENCE_DIAPASON";
			case Tokens::rule_CSEQUENCE_SYMBOL: return "rule_CSEQUENCE_SYMBOL";
			case Tokens::AUTO_9: return "AUTO_9";
			case Tokens::AUTO_13: return "AUTO_13";
			case Tokens::AUTO_3: return "AUTO_3";
			case Tokens::AUTO_7: return "AUTO_7";
			case Tokens::NUMBER: return "NUMBER";
			case Tokens::ID: return "ID";
			case Tokens::AUTO_0: return "AUTO_0";
			case Tokens::rule_OP: return "rule_OP";
			case Tokens::LINEAR_COMMENT: return "LINEAR_COMMENT";
			case Tokens::cll_LOGICAL_NOT: return "cll_LOGICAL_NOT";
			case Tokens::MODULO: return "MODULO";
			case Tokens::cll_OP: return "cll_OP";
			case Tokens::MINUS: return "MINUS";
			case Tokens::PLUS: return "PLUS";
			case Tokens::QUESTION_MARK: return "QUESTION_MARK";
			case Tokens::rule_CSEQUENCE: return "rule_CSEQUENCE";
			case Tokens::MULTIPLE: return "MULTIPLE";
			case Tokens::AT: return "AT";
			case Tokens::cll_LOGICAL_OR: return "cll_LOGICAL_OR";
			case Tokens::AUTO_11: return "AUTO_11";
			case Tokens::DOT: return "DOT";
			case Tokens::STRING: return "STRING";
			case Tokens::SPACEMODE: return "SPACEMODE";
			case Tokens::cll_ASSIGNMENT_OP: return "cll_ASSIGNMENT_OP";
			case Tokens::cll_COMPARE_OP: return "cll_COMPARE_OP";
			case Tokens::AUTO_2: return "AUTO_2";
			case Tokens::NAME: return "NAME";
			case Tokens::cll_LOGICAL_AND: return "cll_LOGICAL_AND";
			case Tokens::AUTO_5: return "AUTO_5";
			case Tokens::AUTO_12: return "AUTO_12";
			case Tokens::cll_TEMPLATE: return "cll_TEMPLATE";
			case Tokens::cll_TYPE: return "cll_TYPE";
			case Tokens::AUTO_4: return "AUTO_4";
			case Tokens::cll_LOGICAL_OP: return "cll_LOGICAL_OP";
			case Tokens::DIVIDE: return "DIVIDE";
		}
		return "NONE";
	}
	constexpr const char* RulesToString(Rules rule) {
		switch (rule) {
			case Rules::NONE: return "NONE";
			case Rules::cll_expr_value: return "cll_expr_value";
			case Rules::cll_function_arguments: return "cll_function_arguments";
			case Rules::cll_method_call: return "cll_method_call";
			case Rules::moduleImport_from: return "moduleImport_from";
			case Rules::cll_function_parameters: return "cll_function_parameters";
			case Rules::rule_quantifier: return "rule_quantifier";
			case Rules::rule_data_block_templated_datablock: return "rule_data_block_templated_datablock";
			case Rules::rule_data_block_regular_datablock: return "rule_data_block_regular_datablock";
			case Rules::cll_function_body_decl: return "cll_function_body_decl";
			case Rules::rule_group: return "rule_group";
			case Rules::rule_name: return "rule_name";
			case Rules::rule_keyvalue: return "rule_keyvalue";
			case Rules::rule_member: return "rule_member";
			case Rules::rule: return "rule";
			case Rules::_use_unit: return "_use_unit";
			case Rules::main: return "main";
			case Rules::_use: return "_use";
			case Rules::moduleImport_from_import_list: return "moduleImport_from_import_list";
			case Rules::cll_expr_compare: return "cll_expr_compare";
			case Rules::moduleDeclaration: return "moduleDeclaration";
			case Rules::cll_stmt: return "cll_stmt";
			case Rules::cll: return "cll";
			case Rules::cll_expr_group: return "cll_expr_group";
			case Rules::rvalue: return "rvalue";
			case Rules::array: return "array";
			case Rules::cll__variable: return "cll__variable";
			case Rules::object: return "object";
			case Rules::cll__var: return "cll__var";
			case Rules::cll_expr_logical: return "cll_expr_logical";
			case Rules::cll_expr_term: return "cll_expr_term";
			case Rules::cll_expr: return "cll_expr";
			case Rules::cll_expr_arithmetic: return "cll_expr_arithmetic";
			case Rules::cll__if: return "cll__if";
			case Rules::cll_function_decl: return "cll_function_decl";
			case Rules::cll_function_call: return "cll_function_call";
			case Rules::rule_data_block: return "rule_data_block";
			case Rules::rule_nested_rule: return "rule_nested_rule";
			case Rules::cll_function_body_call: return "cll_function_body_call";
			case Rules::cll_loop_for: return "cll_loop_for";
			case Rules::cll_loop_while: return "cll_loop_while";
			case Rules::rule_data_block_regular_datablock_key: return "rule_data_block_regular_datablock_key";
			case Rules::moduleImport: return "moduleImport";
			case Rules::rule_value: return "rule_value";
		}
		return "NONE";
	}
	namespace Types {
		using AUTO_4 = char;
		struct cll_TYPE {
			::Parser::Token templ;
			::Parser::str_t type;
		};
		using NAME = ::Parser::Token;
		using AUTO_2 = char;
		using cll_COMPARE_OP = ::Parser::UNDEF;
		using AUTO_11 = ::Parser::str_t;
		struct rule_CSEQUENCE_DIAPASON {
			::Parser::Token to;
			::Parser::Token from;
		};
		using cll_OP = ::Parser::UNDEF;
		using AUTO_9 = ::Parser::str_t;
		using AUTO_0 = char;
		struct rule_CSEQUENCE {
			::Parser::UNDEF val;
			char _not;
		};
		struct NUMBER {
			::Parser::str_t main;
			::Parser::str_t dec;
			::Parser::str_t sign;
		};
		using cll_LOGICAL_OP = ::Parser::UNDEF;
		using AUTO_3 = char;
		using AUTO_13 = char;
		using AUTO_18 = ::Parser::str_t;
		using rule_CSEQUENCE_ESCAPE = char;
		using AUTO_1 = char;
		using SPACEMODE = ::Parser::UNDEF;
		using AUTO_7 = char;
		using BOOLEAN = ::Parser::str_t;
		using rule_BIN = ::Parser::str_t;
		using AUTO_10 = ::Parser::str_t;
		using rule_HEX = ::Parser::str_t;
		using AUTO_19 = ::Parser::str_t;
		using AUTO_16 = ::Parser::str_t;
		struct cll_TEMPLATE {
			::Parser::arr_t<::Parser::Token> second;
			::Parser::Token first;
		};
		using AUTO_12 = char;
		using AUTO_15 = ::Parser::str_t;
		using AUTO_14 = char;
		using AUTO_17 = ::Parser::str_t;
		using rule_ESCAPED = char;
		using AUTO_5 = char;
		using cll_ASSIGNMENT_OP = char;
		using AUTO_20 = ::Parser::str_t;
		using AUTO_8 = ::Parser::str_t;
		using AUTO_21 = char;
		using STRING = ::Parser::str_t;
		using rule_CSEQUENCE_SYMBOL = ::Parser::UNDEF;
		using AUTO_23 = char;
		using ID = ::Parser::str_t;
		using AUTO_22 = ::Parser::str_t;
		using AUTO_6 = char;
		struct rule_data_block_regular_datablock_key {
			::Parser::Rule dt;
			::Parser::Token name;
		};
		using cll_function_body_call = ::Parser::Rule;
		using rule_data_block = ::Parser::UNDEF;
		struct cll_function_call {
			::Parser::Rule body;
			::Parser::Token name;
		};
		struct cll_function_decl {
			::Parser::Rule stmt;
			::Parser::Rule name;
			::Parser::arr_t<::Parser::Token> type;
		};
		using cll_expr = ::Parser::Rule;
		struct cll_expr_term {
			::Parser::arr_t<::Parser::Rule> sequence;
			::Parser::UNDEF operators;
			::Parser::Rule first;
		};
		struct cll_expr_logical {
			::Parser::arr_t<::Parser::Rule> right;
			::Parser::arr_t<::Parser::Token> op;
			::Parser::Rule left;
		};
		struct cll__var {
			::Parser::Rule value;
			::Parser::Token op;
			::Parser::Token id;
			::Parser::Token type;
		};
		struct cll_loop_while {
			::Parser::Rule stmt;
			::Parser::Rule expr;
		};
		struct cll_loop_for {
			::Parser::Rule stmt;
			::Parser::Rule cond;
			::Parser::Rule end;
			::Parser::UNDEF decl;
		};
		struct cll__variable {
			::Parser::Token name;
			::Parser::UNDEF pos;
			::Parser::Rule brace_expression;
			::Parser::UNDEF pre;
		};
		using rule_nested_rule = ::Parser::Rule;
		using rvalue = ::Parser::UNDEF;
		struct _use_unit {
			::Parser::Rule value;
			::Parser::Token name;
		};
		struct moduleImport_from_import_list {
			::Parser::arr_t<::Parser::Token> sequence;
			::Parser::Token first;
		};
		struct _use {
			::Parser::arr_t<::Parser::Rule> second;
			::Parser::Rule first;
		};
		struct cll_expr_arithmetic {
			::Parser::arr_t<::Parser::Rule> sequence;
			::Parser::UNDEF operators;
			::Parser::Rule first;
		};
		struct rule {
			::Parser::arr_t<::Parser::Rule> nested_rules;
			::Parser::arr_t<::Parser::Rule> rule;
			::Parser::Rule data_block;
			::Parser::Token name;
		};
		using main = ::Parser::UNDEF;
		using array = ::Parser::arr_t<::Parser::Rule>;
		struct rule_member {
			::Parser::UNDEF val;
			::Parser::Rule quantifier;
			::Parser::UNDEF prefix;
		};
		struct rule_data_block_templated_datablock {
			::Parser::arr_t<::Parser::Token> second_name;
			::Parser::Token first_name;
		};
		using rule_group = ::Parser::arr_t<::Parser::Rule>;
		using cll_expr_value = ::Parser::UNDEF;
		using cll_function_body_decl = ::Parser::Rule;
		struct rule_name {
			::Parser::arr_t<::Parser::Token> nested_name;
			::Parser::Token name;
			::Parser::Token is_nested;
		};
		using rule_data_block_regular_datablock = ::Parser::UNDEF;
		using moduleImport = ::Parser::UNDEF;
		using cll_expr_group = ::Parser::Rule;
		using cll = ::Parser::UNDEF;
		struct moduleDeclaration {
			::Parser::Token base;
			::Parser::Token name;
		};
		struct cll__if {
			::Parser::Rule stmt;
			::Parser::Rule expr;
		};
		using rule_quantifier = ::Parser::UNDEF;
		struct moduleImport_from {
			::Parser::Token from;
			::Parser::UNDEF what;
		};
		using rule_value = ::Parser::Token;
		struct object {
			::Parser::arr_t<::Parser::Rule> values;
			::Parser::UNDEF keys;
			::Parser::Rule value;
			::Parser::UNDEF key;
		};
		using cll_stmt = ::Parser::arr_t<::Parser::Rule>;
		struct cll_expr_compare {
			::Parser::arr_t<::Parser::Rule> sequence;
			::Parser::arr_t<::Parser::Token> operators;
			::Parser::Rule first;
		};
		struct cll_method_call {
			::Parser::Rule body;
			::Parser::Token name;
		};
		struct cll_function_arguments {
			::Parser::arr_t<::Parser::Rule> second;
			::Parser::Rule first;
		};
		using rule_keyvalue = ::Parser::Token;
		struct cll_function_parameters {
			::Parser::arr_t<::Parser::Token> second;
			::Parser::Token first;
		};
	}

	namespace get {
		const ::Parser::Types::AUTO_4& AUTO_4(const ::Parser::Token &token);
		::Parser::Types::AUTO_4& AUTO_4(::Parser::Token &token);
		const ::Parser::Types::cll_TYPE& cll_TYPE(const ::Parser::Token &token);
		::Parser::Types::cll_TYPE& cll_TYPE(::Parser::Token &token);
		const ::Parser::Types::NAME& NAME(const ::Parser::Token &token);
		::Parser::Types::NAME& NAME(::Parser::Token &token);
		const ::Parser::Types::AUTO_2& AUTO_2(const ::Parser::Token &token);
		::Parser::Types::AUTO_2& AUTO_2(::Parser::Token &token);
		const ::Parser::Types::cll_COMPARE_OP& cll_COMPARE_OP(const ::Parser::Token &token);
		::Parser::Types::cll_COMPARE_OP& cll_COMPARE_OP(::Parser::Token &token);
		const ::Parser::Types::AUTO_11& AUTO_11(const ::Parser::Token &token);
		::Parser::Types::AUTO_11& AUTO_11(::Parser::Token &token);
		const ::Parser::Types::rule_CSEQUENCE_DIAPASON& rule_CSEQUENCE_DIAPASON(const ::Parser::Token &token);
		::Parser::Types::rule_CSEQUENCE_DIAPASON& rule_CSEQUENCE_DIAPASON(::Parser::Token &token);
		const ::Parser::Types::cll_OP& cll_OP(const ::Parser::Token &token);
		::Parser::Types::cll_OP& cll_OP(::Parser::Token &token);
		const ::Parser::Types::AUTO_9& AUTO_9(const ::Parser::Token &token);
		::Parser::Types::AUTO_9& AUTO_9(::Parser::Token &token);
		const ::Parser::Types::AUTO_0& AUTO_0(const ::Parser::Token &token);
		::Parser::Types::AUTO_0& AUTO_0(::Parser::Token &token);
		const ::Parser::Types::rule_CSEQUENCE& rule_CSEQUENCE(const ::Parser::Token &token);
		::Parser::Types::rule_CSEQUENCE& rule_CSEQUENCE(::Parser::Token &token);
		const ::Parser::Types::NUMBER& NUMBER(const ::Parser::Token &token);
		::Parser::Types::NUMBER& NUMBER(::Parser::Token &token);
		const ::Parser::Types::cll_LOGICAL_OP& cll_LOGICAL_OP(const ::Parser::Token &token);
		::Parser::Types::cll_LOGICAL_OP& cll_LOGICAL_OP(::Parser::Token &token);
		const ::Parser::Types::AUTO_3& AUTO_3(const ::Parser::Token &token);
		::Parser::Types::AUTO_3& AUTO_3(::Parser::Token &token);
		const ::Parser::Types::AUTO_13& AUTO_13(const ::Parser::Token &token);
		::Parser::Types::AUTO_13& AUTO_13(::Parser::Token &token);
		const ::Parser::Types::AUTO_18& AUTO_18(const ::Parser::Token &token);
		::Parser::Types::AUTO_18& AUTO_18(::Parser::Token &token);
		const ::Parser::Types::rule_CSEQUENCE_ESCAPE& rule_CSEQUENCE_ESCAPE(const ::Parser::Token &token);
		::Parser::Types::rule_CSEQUENCE_ESCAPE& rule_CSEQUENCE_ESCAPE(::Parser::Token &token);
		const ::Parser::Types::AUTO_1& AUTO_1(const ::Parser::Token &token);
		::Parser::Types::AUTO_1& AUTO_1(::Parser::Token &token);
		const ::Parser::Types::SPACEMODE& SPACEMODE(const ::Parser::Token &token);
		::Parser::Types::SPACEMODE& SPACEMODE(::Parser::Token &token);
		const ::Parser::Types::AUTO_7& AUTO_7(const ::Parser::Token &token);
		::Parser::Types::AUTO_7& AUTO_7(::Parser::Token &token);
		const ::Parser::Types::BOOLEAN& BOOLEAN(const ::Parser::Token &token);
		::Parser::Types::BOOLEAN& BOOLEAN(::Parser::Token &token);
		const ::Parser::Types::rule_BIN& rule_BIN(const ::Parser::Token &token);
		::Parser::Types::rule_BIN& rule_BIN(::Parser::Token &token);
		const ::Parser::Types::AUTO_10& AUTO_10(const ::Parser::Token &token);
		::Parser::Types::AUTO_10& AUTO_10(::Parser::Token &token);
		const ::Parser::Types::rule_HEX& rule_HEX(const ::Parser::Token &token);
		::Parser::Types::rule_HEX& rule_HEX(::Parser::Token &token);
		const ::Parser::Types::AUTO_19& AUTO_19(const ::Parser::Token &token);
		::Parser::Types::AUTO_19& AUTO_19(::Parser::Token &token);
		const ::Parser::Types::AUTO_16& AUTO_16(const ::Parser::Token &token);
		::Parser::Types::AUTO_16& AUTO_16(::Parser::Token &token);
		const ::Parser::Types::cll_TEMPLATE& cll_TEMPLATE(const ::Parser::Token &token);
		::Parser::Types::cll_TEMPLATE& cll_TEMPLATE(::Parser::Token &token);
		const ::Parser::Types::AUTO_12& AUTO_12(const ::Parser::Token &token);
		::Parser::Types::AUTO_12& AUTO_12(::Parser::Token &token);
		const ::Parser::Types::AUTO_15& AUTO_15(const ::Parser::Token &token);
		::Parser::Types::AUTO_15& AUTO_15(::Parser::Token &token);
		const ::Parser::Types::AUTO_14& AUTO_14(const ::Parser::Token &token);
		::Parser::Types::AUTO_14& AUTO_14(::Parser::Token &token);
		const ::Parser::Types::AUTO_17& AUTO_17(const ::Parser::Token &token);
		::Parser::Types::AUTO_17& AUTO_17(::Parser::Token &token);
		const ::Parser::Types::rule_ESCAPED& rule_ESCAPED(const ::Parser::Token &token);
		::Parser::Types::rule_ESCAPED& rule_ESCAPED(::Parser::Token &token);
		const ::Parser::Types::AUTO_5& AUTO_5(const ::Parser::Token &token);
		::Parser::Types::AUTO_5& AUTO_5(::Parser::Token &token);
		const ::Parser::Types::cll_ASSIGNMENT_OP& cll_ASSIGNMENT_OP(const ::Parser::Token &token);
		::Parser::Types::cll_ASSIGNMENT_OP& cll_ASSIGNMENT_OP(::Parser::Token &token);
		const ::Parser::Types::AUTO_20& AUTO_20(const ::Parser::Token &token);
		::Parser::Types::AUTO_20& AUTO_20(::Parser::Token &token);
		const ::Parser::Types::AUTO_8& AUTO_8(const ::Parser::Token &token);
		::Parser::Types::AUTO_8& AUTO_8(::Parser::Token &token);
		const ::Parser::Types::AUTO_21& AUTO_21(const ::Parser::Token &token);
		::Parser::Types::AUTO_21& AUTO_21(::Parser::Token &token);
		const ::Parser::Types::STRING& STRING(const ::Parser::Token &token);
		::Parser::Types::STRING& STRING(::Parser::Token &token);
		const ::Parser::Types::rule_CSEQUENCE_SYMBOL& rule_CSEQUENCE_SYMBOL(const ::Parser::Token &token);
		::Parser::Types::rule_CSEQUENCE_SYMBOL& rule_CSEQUENCE_SYMBOL(::Parser::Token &token);
		const ::Parser::Types::AUTO_23& AUTO_23(const ::Parser::Token &token);
		::Parser::Types::AUTO_23& AUTO_23(::Parser::Token &token);
		const ::Parser::Types::ID& ID(const ::Parser::Token &token);
		::Parser::Types::ID& ID(::Parser::Token &token);
		const ::Parser::Types::AUTO_22& AUTO_22(const ::Parser::Token &token);
		::Parser::Types::AUTO_22& AUTO_22(::Parser::Token &token);
		const ::Parser::Types::AUTO_6& AUTO_6(const ::Parser::Token &token);
		::Parser::Types::AUTO_6& AUTO_6(::Parser::Token &token);
		const ::Parser::Types::rule_data_block_regular_datablock_key& rule_data_block_regular_datablock_key(const ::Parser::Rule &rule);
		::Parser::Types::rule_data_block_regular_datablock_key& rule_data_block_regular_datablock_key(::Parser::Rule &rule);
		const ::Parser::Types::cll_function_body_call& cll_function_body_call(const ::Parser::Rule &rule);
		::Parser::Types::cll_function_body_call& cll_function_body_call(::Parser::Rule &rule);
		const ::Parser::Types::rule_data_block& rule_data_block(const ::Parser::Rule &rule);
		::Parser::Types::rule_data_block& rule_data_block(::Parser::Rule &rule);
		const ::Parser::Types::cll_function_call& cll_function_call(const ::Parser::Rule &rule);
		::Parser::Types::cll_function_call& cll_function_call(::Parser::Rule &rule);
		const ::Parser::Types::cll_function_decl& cll_function_decl(const ::Parser::Rule &rule);
		::Parser::Types::cll_function_decl& cll_function_decl(::Parser::Rule &rule);
		const ::Parser::Types::cll_expr& cll_expr(const ::Parser::Rule &rule);
		::Parser::Types::cll_expr& cll_expr(::Parser::Rule &rule);
		const ::Parser::Types::cll_expr_term& cll_expr_term(const ::Parser::Rule &rule);
		::Parser::Types::cll_expr_term& cll_expr_term(::Parser::Rule &rule);
		const ::Parser::Types::cll_expr_logical& cll_expr_logical(const ::Parser::Rule &rule);
		::Parser::Types::cll_expr_logical& cll_expr_logical(::Parser::Rule &rule);
		const ::Parser::Types::cll__var& cll__var(const ::Parser::Rule &rule);
		::Parser::Types::cll__var& cll__var(::Parser::Rule &rule);
		const ::Parser::Types::cll_loop_while& cll_loop_while(const ::Parser::Rule &rule);
		::Parser::Types::cll_loop_while& cll_loop_while(::Parser::Rule &rule);
		const ::Parser::Types::cll_loop_for& cll_loop_for(const ::Parser::Rule &rule);
		::Parser::Types::cll_loop_for& cll_loop_for(::Parser::Rule &rule);
		const ::Parser::Types::cll__variable& cll__variable(const ::Parser::Rule &rule);
		::Parser::Types::cll__variable& cll__variable(::Parser::Rule &rule);
		const ::Parser::Types::rule_nested_rule& rule_nested_rule(const ::Parser::Rule &rule);
		::Parser::Types::rule_nested_rule& rule_nested_rule(::Parser::Rule &rule);
		const ::Parser::Types::rvalue& rvalue(const ::Parser::Rule &rule);
		::Parser::Types::rvalue& rvalue(::Parser::Rule &rule);
		const ::Parser::Types::_use_unit& _use_unit(const ::Parser::Rule &rule);
		::Parser::Types::_use_unit& _use_unit(::Parser::Rule &rule);
		const ::Parser::Types::moduleImport_from_import_list& moduleImport_from_import_list(const ::Parser::Rule &rule);
		::Parser::Types::moduleImport_from_import_list& moduleImport_from_import_list(::Parser::Rule &rule);
		const ::Parser::Types::_use& _use(const ::Parser::Rule &rule);
		::Parser::Types::_use& _use(::Parser::Rule &rule);
		const ::Parser::Types::cll_expr_arithmetic& cll_expr_arithmetic(const ::Parser::Rule &rule);
		::Parser::Types::cll_expr_arithmetic& cll_expr_arithmetic(::Parser::Rule &rule);
		const ::Parser::Types::rule& rule(const ::Parser::Rule &rule);
		::Parser::Types::rule& rule(::Parser::Rule &rule);
		const ::Parser::Types::main& main(const ::Parser::Rule &rule);
		::Parser::Types::main& main(::Parser::Rule &rule);
		const ::Parser::Types::array& array(const ::Parser::Rule &rule);
		::Parser::Types::array& array(::Parser::Rule &rule);
		const ::Parser::Types::rule_member& rule_member(const ::Parser::Rule &rule);
		::Parser::Types::rule_member& rule_member(::Parser::Rule &rule);
		const ::Parser::Types::rule_data_block_templated_datablock& rule_data_block_templated_datablock(const ::Parser::Rule &rule);
		::Parser::Types::rule_data_block_templated_datablock& rule_data_block_templated_datablock(::Parser::Rule &rule);
		const ::Parser::Types::rule_group& rule_group(const ::Parser::Rule &rule);
		::Parser::Types::rule_group& rule_group(::Parser::Rule &rule);
		const ::Parser::Types::cll_expr_value& cll_expr_value(const ::Parser::Rule &rule);
		::Parser::Types::cll_expr_value& cll_expr_value(::Parser::Rule &rule);
		const ::Parser::Types::cll_function_body_decl& cll_function_body_decl(const ::Parser::Rule &rule);
		::Parser::Types::cll_function_body_decl& cll_function_body_decl(::Parser::Rule &rule);
		const ::Parser::Types::rule_name& rule_name(const ::Parser::Rule &rule);
		::Parser::Types::rule_name& rule_name(::Parser::Rule &rule);
		const ::Parser::Types::rule_data_block_regular_datablock& rule_data_block_regular_datablock(const ::Parser::Rule &rule);
		::Parser::Types::rule_data_block_regular_datablock& rule_data_block_regular_datablock(::Parser::Rule &rule);
		const ::Parser::Types::moduleImport& moduleImport(const ::Parser::Rule &rule);
		::Parser::Types::moduleImport& moduleImport(::Parser::Rule &rule);
		const ::Parser::Types::cll_expr_group& cll_expr_group(const ::Parser::Rule &rule);
		::Parser::Types::cll_expr_group& cll_expr_group(::Parser::Rule &rule);
		const ::Parser::Types::cll& cll(const ::Parser::Rule &rule);
		::Parser::Types::cll& cll(::Parser::Rule &rule);
		const ::Parser::Types::moduleDeclaration& moduleDeclaration(const ::Parser::Rule &rule);
		::Parser::Types::moduleDeclaration& moduleDeclaration(::Parser::Rule &rule);
		const ::Parser::Types::cll__if& cll__if(const ::Parser::Rule &rule);
		::Parser::Types::cll__if& cll__if(::Parser::Rule &rule);
		const ::Parser::Types::rule_quantifier& rule_quantifier(const ::Parser::Rule &rule);
		::Parser::Types::rule_quantifier& rule_quantifier(::Parser::Rule &rule);
		const ::Parser::Types::moduleImport_from& moduleImport_from(const ::Parser::Rule &rule);
		::Parser::Types::moduleImport_from& moduleImport_from(::Parser::Rule &rule);
		const ::Parser::Types::rule_value& rule_value(const ::Parser::Rule &rule);
		::Parser::Types::rule_value& rule_value(::Parser::Rule &rule);
		const ::Parser::Types::object& object(const ::Parser::Rule &rule);
		::Parser::Types::object& object(::Parser::Rule &rule);
		const ::Parser::Types::cll_stmt& cll_stmt(const ::Parser::Rule &rule);
		::Parser::Types::cll_stmt& cll_stmt(::Parser::Rule &rule);
		const ::Parser::Types::cll_expr_compare& cll_expr_compare(const ::Parser::Rule &rule);
		::Parser::Types::cll_expr_compare& cll_expr_compare(::Parser::Rule &rule);
		const ::Parser::Types::cll_method_call& cll_method_call(const ::Parser::Rule &rule);
		::Parser::Types::cll_method_call& cll_method_call(::Parser::Rule &rule);
		const ::Parser::Types::cll_function_arguments& cll_function_arguments(const ::Parser::Rule &rule);
		::Parser::Types::cll_function_arguments& cll_function_arguments(::Parser::Rule &rule);
		const ::Parser::Types::rule_keyvalue& rule_keyvalue(const ::Parser::Rule &rule);
		::Parser::Types::rule_keyvalue& rule_keyvalue(::Parser::Rule &rule);
		const ::Parser::Types::cll_function_parameters& cll_function_parameters(const ::Parser::Rule &rule);
		::Parser::Types::cll_function_parameters& cll_function_parameters(::Parser::Rule &rule);
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
			Token_res AUTO_23(const char*);
			Token_res AUTO_22(const char*);
			Token_res AUTO_21(const char*);
			Token_res AUTO_20(const char*);
			Token_res AUTO_18(const char*);
			Token_res AUTO_17(const char*);
			Token_res AUTO_19(const char*);
			Token_res AUTO_16(const char*);
			Token_res AUTO_15(const char*);
			Token_res AUTO_14(const char*);
			Token_res AUTO_10(const char*);
			Token_res AUTO_8(const char*);
			Token_res AUTO_6(const char*);
			Token_res rule_BIN(const char*);
			Token_res rule_HEX(const char*);
			Token_res rule_ESCAPED(const char*);
			Token_res rule_NOSPACE(const char*);
			Token_res BOOLEAN(const char*);
			Token_res AUTO_1(const char*);
			Token_res rule_CSEQUENCE_ESCAPE(const char*);
			Token_res rule_CSEQUENCE_DIAPASON(const char*);
			Token_res rule_CSEQUENCE_SYMBOL(const char*);
			Token_res AUTO_9(const char*);
			Token_res AUTO_13(const char*);
			Token_res AUTO_3(const char*);
			Token_res AUTO_7(const char*);
			Token_res NUMBER(const char*);
			Token_res ID(const char*);
			Token_res AUTO_0(const char*);
			Token_res rule_OP(const char*);
			Token_res LINEAR_COMMENT(const char*);
			Token_res cll_LOGICAL_NOT(const char*);
			Token_res MODULO(const char*);
			Token_res cll_OP(const char*);
			Token_res MINUS(const char*);
			Token_res PLUS(const char*);
			Token_res QUESTION_MARK(const char*);
			Token_res rule_CSEQUENCE(const char*);
			Token_res MULTIPLE(const char*);
			Token_res AT(const char*);
			Token_res cll_LOGICAL_OR(const char*);
			Token_res AUTO_11(const char*);
			Token_res DOT(const char*);
			Token_res STRING(const char*);
			Token_res SPACEMODE(const char*);
			Token_res cll_ASSIGNMENT_OP(const char*);
			Token_res cll_COMPARE_OP(const char*);
			Token_res AUTO_2(const char*);
			Token_res NAME(const char*);
			Token_res cll_LOGICAL_AND(const char*);
			Token_res AUTO_5(const char*);
			Token_res AUTO_12(const char*);
			Token_res cll_TEMPLATE(const char*);
			Token_res cll_TYPE(const char*);
			Token_res AUTO_4(const char*);
			Token_res cll_LOGICAL_OP(const char*);
			Token_res DIVIDE(const char*);
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
		::Parser::Rule_res cll_expr_value(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::UNDEF _0;
			::Parser::bool_t success_1 = 1;
			dfa_lookup_result_2 = DFA_DECIDE(pos);
			switch (dfa_lookup_result_2)
			{
				case 0: {
					_0 = cll__variable(*pos);

					break;

				}
				case 1: {
					_0 = cll_expr_group(*pos);

					break;

				}
				case 2: {
					_0 = cll_method_call(*pos);

					break;

				}
				case 3: {
					_0 = cll_function_call(*pos);

					break;

				}
				case 4: {
					_0 = rvalue(*pos);

					break;

				}
			}
;
			skip_spaces(pos);
			::Parser::Types::cll_expr_value data = NONE;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_expr_value, data)};
		}
		template <class IT>
		::Parser::Rule_res cll_function_arguments(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Rule_res _0;
			::Parser::bool_t success_1 = false;
			_0 = cll_expr(pos);
			if (!(_0.node))
			{
				return {};
			}
			success_1 = true;
			pos += _0.node.length();
			skip_spaces(pos);
			::Parser::bool_t success_8 = false;
			::Parser::bool_t success_5 = false;
			::Parser::bool_t success_3 = false;
			auto begin_10 = pos;
			while (1)
			{
				::Parser::Token _4;
				::Parser::arr_t<::Parser::Token> shadow_6;
				if (!(begin_10->name() == ::Parser::Tokens::AUTO_1))
				{
					break;
				}
				_4 = *begin_10;
				success_5 = true;
				begin_10 += 1;
				shadow_6.push_back(_4);
				skip_spaces(begin_10);
				::Parser::Rule_res _7;
				_7 = cll_expr(begin_10);
				::Parser::arr_t<::Parser::Rule> shadow_9;
				if (!(_7.node))
				{
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
			skip_spaces(pos);
			::Parser::Types::cll_function_arguments data;
			data.first = _0.node;
			data.second = shadow_9;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_function_arguments, data)};
		}
		template <class IT>
		::Parser::Rule_res cll_method_call(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::ID))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::Token _2;
			::Parser::bool_t success_3 = false;
			if (!(pos->name() == ::Parser::Tokens::DOT))
			{
				return {};
			}
			_2 = *pos;
			success_3 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::Rule_res _4;
			::Parser::bool_t success_5 = false;
			_4 = cll_function_call(pos);
			if (!(_4.node))
			{
				return {};
			}
			success_5 = true;
			pos += _4.node.length();
			skip_spaces(pos);
			::Parser::Types::cll_method_call data;
			data.name = _0;
			data.body = _4.node;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_method_call, data)};
		}
		template <class IT>
		::Parser::Rule_res moduleImport_from(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::UNDEF _0;
			::Parser::bool_t success_1 = 1;
			dfa_lookup_result_2 = DFA_DECIDE(pos);
			switch (dfa_lookup_result_2)
			{
				case 0: {
					_0 = *pos;

					break;

				}
				case 1: {
					_0 = moduleImport_from_import_list(*pos);

					break;

				}
			}
;
			skip_spaces(pos);
			::Parser::Token _3;
			::Parser::bool_t success_4 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_9))
			{
				return {};
			}
			_3 = *pos;
			success_4 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::Token _5;
			::Parser::bool_t success_6 = false;
			if (!(pos->name() == ::Parser::Tokens::ID))
			{
				return {};
			}
			_5 = *pos;
			success_6 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::Types::moduleImport_from data;
			data.what = _0;
			data.from = _5;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::moduleImport_from, data)};
		}
		template <class IT>
		::Parser::Rule_res cll_function_parameters(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::ID))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::bool_t success_8 = false;
			::Parser::bool_t success_5 = false;
			::Parser::bool_t success_3 = false;
			auto begin_10 = pos;
			while (1)
			{
				::Parser::Token _4;
				::Parser::arr_t<::Parser::Token> shadow_6;
				if (!(begin_10->name() == ::Parser::Tokens::AUTO_1))
				{
					break;
				}
				_4 = *begin_10;
				success_5 = true;
				begin_10 += 1;
				shadow_6.push_back(_4);
				skip_spaces(begin_10);
				::Parser::Token _7;
				::Parser::arr_t<::Parser::Token> shadow_9;
				if (!(begin_10->name() == ::Parser::Tokens::ID))
				{
					break;
				}
				_7 = *begin_10;
				success_8 = true;
				begin_10 += 1;
				shadow_9.push_back(_7);
			}
			if (success_5 && success_8)
			{
				success_3 = true;
				pos = begin_10;
			}
			skip_spaces(pos);
			::Parser::Types::cll_function_parameters data;
			data.first = _0;
			data.second = shadow_9;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_function_parameters, data)};
		}
		template <class IT>
		::Parser::Rule_res rule_quantifier(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::UNDEF _0;
			::Parser::bool_t success_1 = 1;
			skip_spaces(pos);
			switch (*pos)
			{
				case Tokens::QUESTION_MARK: {
					::Parser::Token _2;
					::Parser::bool_t success_3 = false;
					if (!(pos->name() == ::Parser::Tokens::QUESTION_MARK))
					{
						return {};
					}
					_2 = *pos;
					success_3 = true;
					pos += 1;
					skip_spaces(pos);
					_0 = ;

					break;

				}
				case Tokens::PLUS: {
					::Parser::Token _4;
					::Parser::bool_t success_5 = false;
					if (!(pos->name() == ::Parser::Tokens::PLUS))
					{
						return {};
					}
					_4 = *pos;
					success_5 = true;
					pos += 1;
					skip_spaces(pos);
					_0 = ;

					break;

				}
				case Tokens::MULTIPLE: {
					::Parser::Token _6;
					::Parser::bool_t success_7 = false;
					if (!(pos->name() == ::Parser::Tokens::MULTIPLE))
					{
						return {};
					}
					_6 = *pos;
					success_7 = true;
					pos += 1;
					skip_spaces(pos);
					_0 = ;

					break;

				}
			}
;
			skip_spaces(pos);
			::Parser::Types::rule_quantifier data = NONE;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::rule_quantifier, data)};
		}
		template <class IT>
		::Parser::Rule_res rule_data_block_templated_datablock(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::AT))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::Token _2;
			::Parser::bool_t success_3 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_0))
			{
				return {};
			}
			_2 = *pos;
			success_3 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::bool_t success_14 = false;
			::Parser::bool_t success_11 = false;
			::Parser::bool_t success_7 = false;
			::Parser::bool_t success_5 = false;
			auto begin_17 = pos;
			do
			{
				::Parser::Token _6;
				if (!(begin_17->name() == ::Parser::Tokens::ID))
				{
					break;
				}
				_6 = *begin_17;
				success_7 = true;
				begin_17 += 1;
				skip_spaces(begin_17);
				::Parser::bool_t success_9 = false;
				auto begin_16 = begin_17;
				while (1)
				{
					::Parser::Token _10;
					::Parser::arr_t<::Parser::Token> shadow_12;
					if (!(begin_16->name() == ::Parser::Tokens::AUTO_1))
					{
						break;
					}
					_10 = *begin_16;
					success_11 = true;
					begin_16 += 1;
					shadow_12.push_back(_10);
					skip_spaces(begin_16);
					::Parser::Token _13;
					::Parser::arr_t<::Parser::Token> shadow_15;
					if (!(begin_16->name() == ::Parser::Tokens::ID))
					{
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
			if (success_7 && success_11 && success_14)
			{
				success_5 = true;
				pos = begin_17;
			}
			skip_spaces(pos);
			::Parser::Token _18;
			::Parser::bool_t success_19 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_2))
			{
				return {};
			}
			_18 = *pos;
			success_19 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::Types::rule_data_block_templated_datablock data;
			data.first_name = _6;
			data.second_name = shadow_15;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::rule_data_block_templated_datablock, data)};
		}
		template <class IT>
		::Parser::Rule_res rule_data_block_regular_datablock(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_0))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::UNDEF _2;
			::Parser::bool_t success_3 = 1;
			dfa_lookup_result_4 = DFA_DECIDE(pos);
			switch (dfa_lookup_result_4)
			{
				case 0: {
					_2 = cll_expr(*pos);

					break;

				}
				case 1: {
					_2 = rule_data_block_regular_datablock_key(*pos);

					break;

				}
			}
;
			skip_spaces(pos);
			::Parser::Token _5;
			::Parser::bool_t success_6 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_2))
			{
				return {};
			}
			_5 = *pos;
			success_6 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::Types::rule_data_block_regular_datablock data = NONE;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::rule_data_block_regular_datablock, data)};
		}
		template <class IT>
		::Parser::Rule_res cll_function_body_decl(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_3))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::Rule_res _2;
			::Parser::bool_t success_3 = false;
			_2 = cll_function_parameters(pos);
			if (!(_2.node))
			{
				return {};
			}
			success_3 = true;
			pos += _2.node.length();
			skip_spaces(pos);
			::Parser::Token _4;
			::Parser::bool_t success_5 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_4))
			{
				return {};
			}
			_4 = *pos;
			success_5 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::Types::cll_function_body_decl data = NONE;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_function_body_decl, data)};
		}
		template <class IT>
		::Parser::Rule_res rule_group(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_3))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::Rule_res _2;
			::Parser::bool_t success_3 = false;
			_2 = rule_member(pos);
			::Parser::arr_t<::Parser::Rule> shadow_4;
			while (_2.node)
			{
				success_3 = true;
				pos += _2.node.length();
				shadow_4.push_back(_2.node);
				_2 = rule_member(pos);
			}
			skip_spaces(pos);
			::Parser::Token _5;
			::Parser::bool_t success_6 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_4))
			{
				return {};
			}
			_5 = *pos;
			success_6 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::Types::rule_group data = NONE;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::rule_group, data)};
		}
		template <class IT>
		::Parser::Rule_res rule_name(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			if (pos->name() == ::Parser::Tokens::AUTO_5)
			{
				_0 = *pos;
				success_1 = true;
				pos += 1;
			}
			skip_spaces(pos);
			::Parser::Token _2;
			::Parser::bool_t success_3 = false;
			if (!(pos->name() == ::Parser::Tokens::ID))
			{
				return {};
			}
			_2 = *pos;
			success_3 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::bool_t success_10 = false;
			::Parser::bool_t success_7 = false;
			::Parser::bool_t success_5 = false;
			auto begin_12 = pos;
			while (1)
			{
				::Parser::Token _6;
				::Parser::arr_t<::Parser::Token> shadow_8;
				if (!(begin_12->name() == ::Parser::Tokens::DOT))
				{
					break;
				}
				_6 = *begin_12;
				success_7 = true;
				begin_12 += 1;
				shadow_8.push_back(_6);
				skip_spaces(begin_12);
				::Parser::Token _9;
				::Parser::arr_t<::Parser::Token> shadow_11;
				if (!(begin_12->name() == ::Parser::Tokens::ID))
				{
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
			skip_spaces(pos);
			::Parser::Types::rule_name data;
			data.is_nested = _0;
			data.name = _2;
			data.nested_name = shadow_11;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::rule_name, data)};
		}
		template <class IT>
		::Parser::Rule_res rule_keyvalue(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::AT))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::bool_t success_5 = false;
			::Parser::bool_t success_3 = false;
			auto begin_6 = pos;
			do
			{
				::Parser::Token _4;
				if (!(begin_6->name() == ::Parser::Tokens::ID))
				{
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
			skip_spaces(pos);
			::Parser::Types::rule_keyvalue data = NONE;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::rule_keyvalue, data)};
		}
		template <class IT>
		::Parser::Rule_res rule_member(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::bool_t success_3 = 1;
			::Parser::bool_t success_1 = false;
			auto begin_5 = pos;
			do
			{
				::Parser::UNDEF _2;
				dfa_lookup_result_4 = DFA_DECIDE(begin_5);
				switch (dfa_lookup_result_4)
				{
					case 0: {
						_2 = rule_keyvalue(*begin_5);

						break;

					}
					case 1: {
						_2 = rule_value(*begin_5);

						break;

					}
				}
;
				_0 = ;
			}
			while(0);
			if (success_3)
			{
				success_1 = true;
				pos = begin_5;
			}
			skip_spaces(pos);
			::Parser::UNDEF _6;
			::Parser::bool_t success_7 = 1;
			dfa_lookup_result_8 = DFA_DECIDE(pos);
			switch (dfa_lookup_result_8)
			{
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
					_6 = *pos;

					break;

				}
				case 9: {
					_6 = rule_group(*pos);

					break;

				}
				case 10: {
					_6 = cll(*pos);

					break;

				}
				case 11: {
					_6 = rule_name(*pos);

					break;

				}
			}
;
			skip_spaces(pos);
			::Parser::Rule_res _9;
			::Parser::bool_t success_10 = false;
			_9 = rule_quantifier(pos);
			if (_9.node)
			{
				success_10 = true;
				pos += _9.node.length();
			}
			skip_spaces(pos);
			::Parser::Types::rule_member data;
			data.prefix = _0;
			data.quantifier = _9.node;
			data.val = _6;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::rule_member, data)};
		}
		template <class IT>
		::Parser::Rule_res rule(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::ID))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::Token _2;
			::Parser::bool_t success_3 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_6))
			{
				return {};
			}
			_2 = *pos;
			success_3 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::Rule_res _4;
			::Parser::bool_t success_5 = false;
			_4 = rule_member(pos);
			::Parser::arr_t<::Parser::Rule> shadow_6;
			::Parser::bool_t success_7 = false;
			while (_4.node)
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
			::Parser::Rule_res _8;
			::Parser::bool_t success_9 = false;
			_8 = rule_data_block(pos);
			if (_8.node)
			{
				success_9 = true;
				pos += _8.node.length();
			}
			skip_spaces(pos);
			::Parser::Rule_res _10;
			::Parser::bool_t success_11 = false;
			_10 = rule_nested_rule(pos);
			::Parser::arr_t<::Parser::Rule> shadow_12;
			while (_10.node)
			{
				success_11 = true;
				pos += _10.node.length();
				shadow_12.push_back(_10.node);
				_10 = rule_nested_rule(pos);
			}
			skip_spaces(pos);
			::Parser::Token _13;
			::Parser::bool_t success_14 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_7))
			{
				return {};
			}
			_13 = *pos;
			success_14 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::Types::rule data;
			data.name = _0;
			data.data_block = _8.node;
			data.rule = shadow_6;
			data.nested_rules = shadow_12;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::rule, data)};
		}
		template <class IT>
		::Parser::Rule_res _use_unit(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::ID))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::Rule_res _2;
			::Parser::bool_t success_3 = false;
			_2 = rvalue(pos);
			if (_2.node)
			{
				success_3 = true;
				pos += _2.node.length();
			}
			skip_spaces(pos);
			::Parser::Types::_use_unit data;
			data.name = _0;
			data.value = _2.node;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::_use_unit, data)};
		}
		template <class IT>
		::Parser::Rule_res main(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::bool_t success_3 = 1;
			::Parser::bool_t success_1 = false;
			auto begin_5 = pos;
			::Parser::bool_t success_6 = false;
			while (1)
			{
				::Parser::UNDEF _2;
				dfa_lookup_result_4 = DFA_DECIDE(begin_5);
				switch (dfa_lookup_result_4)
				{
					case 0: {
						_2 = *begin_5;

						break;

					}
					case 1: {
						_2 = *begin_5;

						break;

					}
					case 2: {
						_2 = _use(*begin_5);

						break;

					}
					case 3: {
						_2 = rule(*begin_5);

						break;

					}
				}
;
				success_6 = true;
			}
			if (!success_6)
			{
				reportError(pos, "");
				return {};
			}
			if (success_3)
			{
				success_1 = true;
				pos = begin_5;
			}
			skip_spaces(pos);
			::Parser::Types::main data = NONE;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::main, data)};
		}
		template <class IT>
		::Parser::Rule_res _use(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_8))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::Rule_res _2;
			::Parser::bool_t success_3 = false;
			_2 = _use_unit(pos);
			if (!(_2.node))
			{
				return {};
			}
			success_3 = true;
			pos += _2.node.length();
			skip_spaces(pos);
			::Parser::bool_t success_10 = false;
			::Parser::bool_t success_7 = false;
			::Parser::bool_t success_5 = false;
			auto begin_12 = pos;
			while (1)
			{
				::Parser::Token _6;
				::Parser::arr_t<::Parser::Token> shadow_8;
				if (!(begin_12->name() == ::Parser::Tokens::AUTO_1))
				{
					break;
				}
				_6 = *begin_12;
				success_7 = true;
				begin_12 += 1;
				shadow_8.push_back(_6);
				skip_spaces(begin_12);
				::Parser::Rule_res _9;
				_9 = _use_unit(begin_12);
				::Parser::arr_t<::Parser::Rule> shadow_11;
				if (!(_9.node))
				{
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
			::Parser::Token _13;
			::Parser::bool_t success_14 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_7))
			{
				return {};
			}
			_13 = *pos;
			success_14 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::Types::_use data;
			data.first = _2.node;
			data.second = shadow_11;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::_use, data)};
		}
		template <class IT>
		::Parser::Rule_res moduleImport_from_import_list(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::ID))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::bool_t success_8 = false;
			::Parser::bool_t success_5 = false;
			::Parser::bool_t success_3 = false;
			auto begin_10 = pos;
			while (1)
			{
				::Parser::Token _4;
				::Parser::arr_t<::Parser::Token> shadow_6;
				if (!(begin_10->name() == ::Parser::Tokens::AUTO_1))
				{
					break;
				}
				_4 = *begin_10;
				success_5 = true;
				begin_10 += 1;
				shadow_6.push_back(_4);
				skip_spaces(begin_10);
				::Parser::Token _7;
				::Parser::arr_t<::Parser::Token> shadow_9;
				if (!(begin_10->name() == ::Parser::Tokens::ID))
				{
					break;
				}
				_7 = *begin_10;
				success_8 = true;
				begin_10 += 1;
				shadow_9.push_back(_7);
			}
			if (success_5 && success_8)
			{
				success_3 = true;
				pos = begin_10;
			}
			skip_spaces(pos);
			::Parser::Types::moduleImport_from_import_list data;
			data.first = _0;
			data.sequence = shadow_9;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::moduleImport_from_import_list, data)};
		}
		template <class IT>
		::Parser::Rule_res cll_expr_compare(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Rule_res _0;
			::Parser::bool_t success_1 = false;
			_0 = cll_expr_arithmetic(pos);
			if (!(_0.node))
			{
				return {};
			}
			success_1 = true;
			pos += _0.node.length();
			skip_spaces(pos);
			::Parser::bool_t success_8 = false;
			::Parser::bool_t success_5 = false;
			::Parser::bool_t success_3 = false;
			auto begin_10 = pos;
			while (1)
			{
				::Parser::Token _4;
				::Parser::arr_t<::Parser::Token> shadow_6;
				if (!(begin_10->name() == ::Parser::Tokens::cll_COMPARE_OP))
				{
					break;
				}
				_4 = *begin_10;
				success_5 = true;
				begin_10 += 1;
				shadow_6.push_back(_4);
				skip_spaces(begin_10);
				::Parser::Rule_res _7;
				_7 = cll_expr_arithmetic(begin_10);
				::Parser::arr_t<::Parser::Rule> shadow_9;
				if (!(_7.node))
				{
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
			skip_spaces(pos);
			::Parser::Types::cll_expr_compare data;
			data.first = _0.node;
			data.operators = shadow_6;
			data.sequence = shadow_9;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_expr_compare, data)};
		}
		template <class IT>
		::Parser::Rule_res moduleDeclaration(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_10))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::Token _2;
			::Parser::bool_t success_3 = false;
			if (!(pos->name() == ::Parser::Tokens::ID))
			{
				return {};
			}
			_2 = *pos;
			success_3 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::bool_t success_9 = false;
			::Parser::bool_t success_7 = false;
			::Parser::bool_t success_5 = false;
			auto begin_10 = pos;
			do
			{
				::Parser::Token _6;
				if (!(begin_10->name() == ::Parser::Tokens::AUTO_11))
				{
					break;
				}
				_6 = *begin_10;
				success_7 = true;
				begin_10 += 1;
				skip_spaces(begin_10);
				::Parser::Token _8;
				if (!(begin_10->name() == ::Parser::Tokens::ID))
				{
					break;
				}
				_8 = *begin_10;
				success_9 = true;
				begin_10 += 1;
			}
			while(0);
			if (success_7 && success_9)
			{
				success_5 = true;
				pos = begin_10;
			}
			skip_spaces(pos);
			::Parser::Token _11;
			::Parser::bool_t success_12 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_7))
			{
				return {};
			}
			_11 = *pos;
			success_12 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::Types::moduleDeclaration data;
			data.name = _2;
			data.base = _8;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::moduleDeclaration, data)};
		}
		template <class IT>
		::Parser::Rule_res cll_stmt(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_0))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::Rule_res _2;
			::Parser::bool_t success_3 = false;
			_2 = rule_member(pos);
			::Parser::arr_t<::Parser::Rule> shadow_4;
			while (_2.node)
			{
				success_3 = true;
				pos += _2.node.length();
				shadow_4.push_back(_2.node);
				_2 = rule_member(pos);
			}
			skip_spaces(pos);
			::Parser::Token _5;
			::Parser::bool_t success_6 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_2))
			{
				return {};
			}
			_5 = *pos;
			success_6 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::Types::cll_stmt data = NONE;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_stmt, data)};
		}
		template <class IT>
		::Parser::Rule_res cll(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_12))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::UNDEF _2;
			::Parser::bool_t success_3 = 1;
			dfa_lookup_result_4 = DFA_DECIDE(pos);
			switch (dfa_lookup_result_4)
			{
				case 0: {
					_2 = cll_loop_while(*pos);

					break;

				}
				case 1: {
					_2 = cll__var(*pos);

					break;

				}
				case 2: {
					_2 = cll_loop_for(*pos);

					break;

				}
				case 3: {
					_2 = cll__if(*pos);

					break;

				}
				case 4: {
					_2 = cll_expr(*pos);

					break;

				}
			}
;
			skip_spaces(pos);
			::Parser::Token _5;
			::Parser::bool_t success_6 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_7))
			{
				return {};
			}
			_5 = *pos;
			success_6 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::Types::cll data = NONE;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll, data)};
		}
		template <class IT>
		::Parser::Rule_res cll_expr_group(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_3))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::Rule_res _2;
			::Parser::bool_t success_3 = false;
			_2 = cll_expr(pos);
			if (!(_2.node))
			{
				return {};
			}
			success_3 = true;
			pos += _2.node.length();
			skip_spaces(pos);
			::Parser::Token _4;
			::Parser::bool_t success_5 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_4))
			{
				return {};
			}
			_4 = *pos;
			success_5 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::Types::cll_expr_group data = NONE;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_expr_group, data)};
		}
		template <class IT>
		::Parser::Rule_res rvalue(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::UNDEF _0;
			::Parser::bool_t success_1 = 1;
			dfa_lookup_result_2 = DFA_DECIDE(pos);
			switch (dfa_lookup_result_2)
			{
				case 0: {
					_0 = *pos;

					break;

				}
				case 1: {
					_0 = *pos;

					break;

				}
				case 2: {
					_0 = object(*pos);

					break;

				}
				case 3: {
					_0 = array(*pos);

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
;
			skip_spaces(pos);
			::Parser::Types::rvalue data = NONE;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::rvalue, data)};
		}
		template <class IT>
		::Parser::Rule_res array(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_13))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::bool_t success_10 = false;
			::Parser::bool_t success_7 = false;
			::Parser::bool_t success_3 = false;
			auto begin_13 = pos;
			do
			{
				::Parser::bool_t success_5 = false;
				auto begin_12 = begin_13;
				while (1)
				{
					::Parser::Rule_res _6;
					_6 = cll_expr(begin_12);
					::Parser::arr_t<::Parser::Rule> shadow_8;
					if (!(_6.node))
					{
						break;
					}
					success_7 = true;
					begin_12 += _6.node.length();
					shadow_8.push_back(_6.node);
					skip_spaces(begin_12);
					::Parser::Token _9;
					::Parser::arr_t<::Parser::Token> shadow_11;
					if (!(begin_12->name() == ::Parser::Tokens::AUTO_1))
					{
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
			if (success_7 && success_10)
			{
				success_3 = true;
				pos = begin_13;
			}
			skip_spaces(pos);
			::Parser::Token _14;
			::Parser::bool_t success_15 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_14))
			{
				return {};
			}
			_14 = *pos;
			success_15 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::Types::array data = NONE;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::array, data)};
		}
		template <class IT>
		::Parser::Rule_res cll__variable(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::bool_t success_3 = 1;
			::Parser::bool_t success_1 = false;
			auto begin_8 = pos;
			do
			{
				::Parser::UNDEF _2;
				skip_spaces(begin_8);
				switch (*begin_8)
				{
					case Tokens::AUTO_19: {
						::Parser::Token _4;
						::Parser::bool_t success_5 = false;
						if (!(begin_8->name() == ::Parser::Tokens::AUTO_19))
						{
							return {};
						}
						_4 = *begin_8;
						success_5 = true;
						begin_8 += 1;
						skip_spaces(begin_8);
						_2 = ;

						break;

					}
					case Tokens::AUTO_20: {
						::Parser::Token _6;
						::Parser::bool_t success_7 = false;
						if (!(begin_8->name() == ::Parser::Tokens::AUTO_20))
						{
							return {};
						}
						_6 = *begin_8;
						success_7 = true;
						begin_8 += 1;
						skip_spaces(begin_8);
						_2 = ;

						break;

					}
				}
;
				_0 = ;
			}
			while(0);
			if (success_3)
			{
				success_1 = true;
				pos = begin_8;
			}
			skip_spaces(pos);
			::Parser::Token _9;
			::Parser::bool_t success_10 = false;
			if (!(pos->name() == ::Parser::Tokens::ID))
			{
				return {};
			}
			_9 = *pos;
			success_10 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::bool_t success_18 = false;
			::Parser::bool_t success_16 = false;
			::Parser::bool_t success_14 = false;
			::Parser::bool_t success_12 = false;
			auto begin_19 = pos;
			do
			{
				::Parser::Token _13;
				if (!(begin_19->name() == ::Parser::Tokens::AUTO_13))
				{
					break;
				}
				_13 = *begin_19;
				success_14 = true;
				begin_19 += 1;
				skip_spaces(begin_19);
				::Parser::Rule_res _15;
				_15 = cll_expr(begin_19);
				if (!(_15.node))
				{
					break;
				}
				success_16 = true;
				begin_19 += _15.node.length();
				skip_spaces(begin_19);
				::Parser::Token _17;
				if (!(begin_19->name() == ::Parser::Tokens::AUTO_14))
				{
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
			::Parser::bool_t success_23 = 1;
			::Parser::bool_t success_21 = false;
			auto begin_28 = pos;
			do
			{
				::Parser::UNDEF _22;
				skip_spaces(begin_28);
				switch (*begin_28)
				{
					case Tokens::AUTO_19: {
						::Parser::Token _24;
						::Parser::bool_t success_25 = false;
						if (!(begin_28->name() == ::Parser::Tokens::AUTO_19))
						{
							return {};
						}
						_24 = *begin_28;
						success_25 = true;
						begin_28 += 1;
						skip_spaces(begin_28);
						_22 = ;

						break;

					}
					case Tokens::AUTO_20: {
						::Parser::Token _26;
						::Parser::bool_t success_27 = false;
						if (!(begin_28->name() == ::Parser::Tokens::AUTO_20))
						{
							return {};
						}
						_26 = *begin_28;
						success_27 = true;
						begin_28 += 1;
						skip_spaces(begin_28);
						_22 = ;

						break;

					}
				}
;
				_20 = ;
			}
			while(0);
			if (success_23)
			{
				success_21 = true;
				pos = begin_28;
			}
			skip_spaces(pos);
			::Parser::Types::cll__variable data;
			data.pre = _0;
			data.brace_expression = _15.node;
			data.pos = _20;
			data.name = _9;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll__variable, data)};
		}
		template <class IT>
		::Parser::Rule_res object(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_0))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::bool_t success_35 = false;
			::Parser::bool_t success_31 = false;
			::Parser::bool_t success_28 = false;
			::Parser::bool_t success_20 = 1;
			::Parser::bool_t success_17 = false;
			::Parser::bool_t success_13 = false;
			::Parser::bool_t success_11 = false;
			::Parser::bool_t success_5 = 1;
			::Parser::bool_t success_3 = false;
			auto begin_36 = pos;
			do
			{
				::Parser::UNDEF _4;
				skip_spaces(begin_36);
				switch (*begin_36)
				{
					case Tokens::ID: {
						::Parser::Token _6;
						::Parser::bool_t success_7 = false;
						if (!(begin_36->name() == ::Parser::Tokens::ID))
						{
							return {};
						}
						_6 = *begin_36;
						success_7 = true;
						begin_36 += 1;
						skip_spaces(begin_36);
						_4 = ;

						break;

					}
					case Tokens::NUMBER: {
						::Parser::Token _8;
						::Parser::bool_t success_9 = false;
						if (!(begin_36->name() == ::Parser::Tokens::NUMBER))
						{
							return {};
						}
						_8 = *begin_36;
						success_9 = true;
						begin_36 += 1;
						skip_spaces(begin_36);
						_4 = ;

						break;

					}
				}
;
				skip_spaces(begin_36);
				::Parser::Token _10;
				if (!(begin_36->name() == ::Parser::Tokens::AUTO_6))
				{
					break;
				}
				_10 = *begin_36;
				success_11 = true;
				begin_36 += 1;
				skip_spaces(begin_36);
				::Parser::Rule_res _12;
				_12 = cll_expr(begin_36);
				if (!(_12.node))
				{
					break;
				}
				success_13 = true;
				begin_36 += _12.node.length();
				skip_spaces(begin_36);
				::Parser::bool_t success_15 = false;
				auto begin_33 = begin_36;
				while (1)
				{
					::Parser::Token _16;
					::Parser::arr_t<::Parser::Token> shadow_18;
					if (!(begin_33->name() == ::Parser::Tokens::AUTO_1))
					{
						break;
					}
					_16 = *begin_33;
					success_17 = true;
					begin_33 += 1;
					shadow_18.push_back(_16);
					skip_spaces(begin_33);
					::Parser::UNDEF _19;
					skip_spaces(begin_33);
					switch (*begin_33)
					{
						case Tokens::ID: {
							::Parser::Token _21;
							::Parser::bool_t success_22 = false;
							::Parser::arr_t<::Parser::Token> shadow_23;
							if (!(begin_33->name() == ::Parser::Tokens::ID))
							{
								return {};
							}
							_21 = *begin_33;
							success_22 = true;
							begin_33 += 1;
							shadow_23.push_back(_21);
							skip_spaces(begin_33);
							_19 = ;

							break;

						}
						case Tokens::NUMBER: {
							::Parser::Token _24;
							::Parser::bool_t success_25 = false;
							::Parser::arr_t<::Parser::Token> shadow_26;
							if (!(begin_33->name() == ::Parser::Tokens::NUMBER))
							{
								return {};
							}
							_24 = *begin_33;
							success_25 = true;
							begin_33 += 1;
							shadow_26.push_back(_24);
							skip_spaces(begin_33);
							_19 = ;

							break;

						}
					}
;
					skip_spaces(begin_33);
					::Parser::Token _27;
					::Parser::arr_t<::Parser::Token> shadow_29;
					if (!(begin_33->name() == ::Parser::Tokens::AUTO_6))
					{
						break;
					}
					_27 = *begin_33;
					success_28 = true;
					begin_33 += 1;
					shadow_29.push_back(_27);
					skip_spaces(begin_33);
					::Parser::Rule_res _30;
					_30 = cll_expr(begin_33);
					::Parser::arr_t<::Parser::Rule> shadow_32;
					if (!(_30.node))
					{
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
				::Parser::Token _34;
				if (!(begin_36->name() == ::Parser::Tokens::AUTO_7))
				{
					break;
				}
				_34 = *begin_36;
				success_35 = true;
				begin_36 += 1;
			}
			while(0);
			if (success_5 && success_11 && success_13 && success_17 && success_20 && success_28 && success_31 && success_35)
			{
				success_3 = true;
				pos = begin_36;
			}
			skip_spaces(pos);
			::Parser::Token _37;
			::Parser::bool_t success_38 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_2))
			{
				return {};
			}
			_37 = *pos;
			success_38 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::Types::object data;
			data.key = _4;
			data.value = _12.node;
			data.keys = _19;
			data.values = shadow_32;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::object, data)};
		}
		template <class IT>
		::Parser::Rule_res cll__var(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			if (pos->name() == ::Parser::Tokens::cll_TYPE)
			{
				_0 = *pos;
				success_1 = true;
				pos += 1;
			}
			skip_spaces(pos);
			::Parser::Token _2;
			::Parser::bool_t success_3 = false;
			if (!(pos->name() == ::Parser::Tokens::ID))
			{
				return {};
			}
			_2 = *pos;
			success_3 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::bool_t success_9 = false;
			::Parser::bool_t success_7 = false;
			::Parser::bool_t success_5 = false;
			auto begin_10 = pos;
			do
			{
				::Parser::Token _6;
				if (!(begin_10->name() == ::Parser::Tokens::cll_ASSIGNMENT_OP))
				{
					break;
				}
				_6 = *begin_10;
				success_7 = true;
				begin_10 += 1;
				skip_spaces(begin_10);
				::Parser::Rule_res _8;
				_8 = cll_expr(begin_10);
				if (!(_8.node))
				{
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
			skip_spaces(pos);
			::Parser::Types::cll__var data;
			data.type = _0;
			data.id = _2;
			data.op = _6;
			data.value = _8.node;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll__var, data)};
		}
		template <class IT>
		::Parser::Rule_res cll_expr_logical(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Rule_res _0;
			::Parser::bool_t success_1 = false;
			_0 = cll_expr_compare(pos);
			if (!(_0.node))
			{
				return {};
			}
			success_1 = true;
			pos += _0.node.length();
			skip_spaces(pos);
			::Parser::bool_t success_8 = false;
			::Parser::bool_t success_5 = false;
			::Parser::bool_t success_3 = false;
			auto begin_10 = pos;
			while (1)
			{
				::Parser::Token _4;
				::Parser::arr_t<::Parser::Token> shadow_6;
				if (!(begin_10->name() == ::Parser::Tokens::cll_LOGICAL_OP))
				{
					break;
				}
				_4 = *begin_10;
				success_5 = true;
				begin_10 += 1;
				shadow_6.push_back(_4);
				skip_spaces(begin_10);
				::Parser::Rule_res _7;
				_7 = cll_expr_compare(begin_10);
				::Parser::arr_t<::Parser::Rule> shadow_9;
				if (!(_7.node))
				{
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
			skip_spaces(pos);
			::Parser::Types::cll_expr_logical data;
			data.left = _0.node;
			data.op = shadow_6;
			data.right = shadow_9;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_expr_logical, data)};
		}
		template <class IT>
		::Parser::Rule_res cll_expr_term(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Rule_res _0;
			::Parser::bool_t success_1 = false;
			_0 = cll_expr_value(pos);
			if (!(_0.node))
			{
				return {};
			}
			success_1 = true;
			pos += _0.node.length();
			skip_spaces(pos);
			::Parser::bool_t success_16 = false;
			::Parser::bool_t success_5 = 1;
			::Parser::bool_t success_3 = false;
			auto begin_18 = pos;
			while (1)
			{
				::Parser::UNDEF _4;
				skip_spaces(begin_18);
				switch (*begin_18)
				{
					case Tokens::DIVIDE: {
						::Parser::Token _6;
						::Parser::bool_t success_7 = false;
						::Parser::arr_t<::Parser::Token> shadow_8;
						if (!(begin_18->name() == ::Parser::Tokens::DIVIDE))
						{
							return {};
						}
						_6 = *begin_18;
						success_7 = true;
						begin_18 += 1;
						shadow_8.push_back(_6);
						skip_spaces(begin_18);
						_4 = ;

						break;

					}
					case Tokens::MULTIPLE: {
						::Parser::Token _9;
						::Parser::bool_t success_10 = false;
						::Parser::arr_t<::Parser::Token> shadow_11;
						if (!(begin_18->name() == ::Parser::Tokens::MULTIPLE))
						{
							return {};
						}
						_9 = *begin_18;
						success_10 = true;
						begin_18 += 1;
						shadow_11.push_back(_9);
						skip_spaces(begin_18);
						_4 = ;

						break;

					}
					case Tokens::MODULO: {
						::Parser::Token _12;
						::Parser::bool_t success_13 = false;
						::Parser::arr_t<::Parser::Token> shadow_14;
						if (!(begin_18->name() == ::Parser::Tokens::MODULO))
						{
							return {};
						}
						_12 = *begin_18;
						success_13 = true;
						begin_18 += 1;
						shadow_14.push_back(_12);
						skip_spaces(begin_18);
						_4 = ;

						break;

					}
				}
;
				skip_spaces(begin_18);
				::Parser::Rule_res _15;
				_15 = cll_expr_value(begin_18);
				::Parser::arr_t<::Parser::Rule> shadow_17;
				if (!(_15.node))
				{
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
			skip_spaces(pos);
			::Parser::Types::cll_expr_term data;
			data.first = _0.node;
			data.operators = _4;
			data.sequence = shadow_17;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_expr_term, data)};
		}
		template <class IT>
		::Parser::Rule_res cll_expr(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Rule_res _0;
			::Parser::bool_t success_1 = false;
			_0 = cll_expr_logical(pos);
			if (!(_0.node))
			{
				return {};
			}
			success_1 = true;
			pos += _0.node.length();
			skip_spaces(pos);
			::Parser::Types::cll_expr data = NONE;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_expr, data)};
		}
		template <class IT>
		::Parser::Rule_res cll_expr_arithmetic(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Rule_res _0;
			::Parser::bool_t success_1 = false;
			_0 = cll_expr_term(pos);
			if (!(_0.node))
			{
				return {};
			}
			success_1 = true;
			pos += _0.node.length();
			skip_spaces(pos);
			::Parser::bool_t success_13 = false;
			::Parser::bool_t success_5 = 1;
			::Parser::bool_t success_3 = false;
			auto begin_15 = pos;
			while (1)
			{
				::Parser::UNDEF _4;
				skip_spaces(begin_15);
				switch (*begin_15)
				{
					case Tokens::MINUS: {
						::Parser::Token _6;
						::Parser::bool_t success_7 = false;
						::Parser::arr_t<::Parser::Token> shadow_8;
						if (!(begin_15->name() == ::Parser::Tokens::MINUS))
						{
							return {};
						}
						_6 = *begin_15;
						success_7 = true;
						begin_15 += 1;
						shadow_8.push_back(_6);
						skip_spaces(begin_15);
						_4 = ;

						break;

					}
					case Tokens::PLUS: {
						::Parser::Token _9;
						::Parser::bool_t success_10 = false;
						::Parser::arr_t<::Parser::Token> shadow_11;
						if (!(begin_15->name() == ::Parser::Tokens::PLUS))
						{
							return {};
						}
						_9 = *begin_15;
						success_10 = true;
						begin_15 += 1;
						shadow_11.push_back(_9);
						skip_spaces(begin_15);
						_4 = ;

						break;

					}
				}
;
				skip_spaces(begin_15);
				::Parser::Rule_res _12;
				_12 = cll_expr_term(begin_15);
				::Parser::arr_t<::Parser::Rule> shadow_14;
				if (!(_12.node))
				{
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
			skip_spaces(pos);
			::Parser::Types::cll_expr_arithmetic data;
			data.first = _0.node;
			data.operators = _4;
			data.sequence = shadow_14;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_expr_arithmetic, data)};
		}
		template <class IT>
		::Parser::Rule_res cll__if(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_15))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::Rule_res _2;
			::Parser::bool_t success_3 = false;
			_2 = cll_expr(pos);
			if (!(_2.node))
			{
				return {};
			}
			success_3 = true;
			pos += _2.node.length();
			skip_spaces(pos);
			::Parser::Rule_res _4;
			::Parser::bool_t success_5 = false;
			_4 = cll_stmt(pos);
			if (!(_4.node))
			{
				return {};
			}
			success_5 = true;
			pos += _4.node.length();
			skip_spaces(pos);
			::Parser::Types::cll__if data;
			data.expr = _2.node;
			data.stmt = _4.node;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll__if, data)};
		}
		template <class IT>
		::Parser::Rule_res cll_function_decl(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_16))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::Token _2;
			::Parser::bool_t success_3 = false;
			::Parser::arr_t<::Parser::Token> shadow_4;
			::Parser::bool_t success_5 = false;
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
			::Parser::Rule_res _6;
			::Parser::bool_t success_7 = false;
			_6 = cll_function_body_decl(pos);
			if (!(_6.node))
			{
				return {};
			}
			success_7 = true;
			pos += _6.node.length();
			skip_spaces(pos);
			::Parser::Rule_res _8;
			::Parser::bool_t success_9 = false;
			_8 = cll_stmt(pos);
			if (_8.node)
			{
				success_9 = true;
				pos += _8.node.length();
			}
			skip_spaces(pos);
			::Parser::Types::cll_function_decl data;
			data.type = shadow_4;
			data.name = _6.node;
			data.stmt = _8.node;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_function_decl, data)};
		}
		template <class IT>
		::Parser::Rule_res cll_function_call(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::ID))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::Rule_res _2;
			::Parser::bool_t success_3 = false;
			_2 = cll_function_body_call(pos);
			if (!(_2.node))
			{
				return {};
			}
			success_3 = true;
			pos += _2.node.length();
			skip_spaces(pos);
			::Parser::Types::cll_function_call data;
			data.name = _0;
			data.body = _2.node;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_function_call, data)};
		}
		template <class IT>
		::Parser::Rule_res rule_data_block(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::UNDEF _0;
			::Parser::bool_t success_1 = 1;
			dfa_lookup_result_2 = DFA_DECIDE(pos);
			switch (dfa_lookup_result_2)
			{
				case 0: {
					_0 = rule_data_block_regular_datablock(*pos);

					break;

				}
				case 1: {
					_0 = rule_data_block_templated_datablock(*pos);

					break;

				}
			}
;
			skip_spaces(pos);
			::Parser::Types::rule_data_block data = NONE;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::rule_data_block, data)};
		}
		template <class IT>
		::Parser::Rule_res rule_nested_rule(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_5))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::Rule_res _2;
			::Parser::bool_t success_3 = false;
			_2 = rule(pos);
			if (!(_2.node))
			{
				return {};
			}
			success_3 = true;
			pos += _2.node.length();
			skip_spaces(pos);
			::Parser::Types::rule_nested_rule data = NONE;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::rule_nested_rule, data)};
		}
		template <class IT>
		::Parser::Rule_res cll_function_body_call(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_3))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::Rule_res _2;
			::Parser::bool_t success_3 = false;
			_2 = cll_function_arguments(pos);
			if (!(_2.node))
			{
				return {};
			}
			success_3 = true;
			pos += _2.node.length();
			skip_spaces(pos);
			::Parser::Token _4;
			::Parser::bool_t success_5 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_4))
			{
				return {};
			}
			_4 = *pos;
			success_5 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::Types::cll_function_body_call data = NONE;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_function_body_call, data)};
		}
		template <class IT>
		::Parser::Rule_res cll_loop_for(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_17))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::Token _2;
			::Parser::bool_t success_3 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_3))
			{
				return {};
			}
			_2 = *pos;
			success_3 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::bool_t success_7 = 1;
			::Parser::bool_t success_5 = false;
			auto begin_9 = pos;
			do
			{
				::Parser::UNDEF _6;
				dfa_lookup_result_8 = DFA_DECIDE(begin_9);
				switch (dfa_lookup_result_8)
				{
					case 0: {
						_6 = cll_expr(*begin_9);

						break;

					}
					case 1: {
						_6 = cll__var(*begin_9);

						break;

					}
				}
;
				_4 = ;
			}
			while(0);
			if (success_7)
			{
				success_5 = true;
				pos = begin_9;
			}
			skip_spaces(pos);
			::Parser::Token _10;
			::Parser::bool_t success_11 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_7))
			{
				return {};
			}
			_10 = *pos;
			success_11 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::Rule_res _12;
			::Parser::bool_t success_13 = false;
			_12 = cll_expr(pos);
			if (_12.node)
			{
				success_13 = true;
				pos += _12.node.length();
			}
			skip_spaces(pos);
			::Parser::Token _14;
			::Parser::bool_t success_15 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_7))
			{
				return {};
			}
			_14 = *pos;
			success_15 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::Rule_res _16;
			::Parser::bool_t success_17 = false;
			_16 = cll_expr(pos);
			if (_16.node)
			{
				success_17 = true;
				pos += _16.node.length();
			}
			skip_spaces(pos);
			::Parser::Token _18;
			::Parser::bool_t success_19 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_4))
			{
				return {};
			}
			_18 = *pos;
			success_19 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::Rule_res _20;
			::Parser::bool_t success_21 = false;
			_20 = cll_stmt(pos);
			if (!(_20.node))
			{
				return {};
			}
			success_21 = true;
			pos += _20.node.length();
			skip_spaces(pos);
			::Parser::Types::cll_loop_for data;
			data.decl = _4;
			data.end = _16.node;
			data.cond = _12.node;
			data.stmt = _20.node;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_loop_for, data)};
		}
		template <class IT>
		::Parser::Rule_res cll_loop_while(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_18))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::Rule_res _2;
			::Parser::bool_t success_3 = false;
			_2 = cll_expr(pos);
			if (!(_2.node))
			{
				return {};
			}
			success_3 = true;
			pos += _2.node.length();
			skip_spaces(pos);
			::Parser::Rule_res _4;
			::Parser::bool_t success_5 = false;
			_4 = cll_stmt(pos);
			if (!(_4.node))
			{
				return {};
			}
			success_5 = true;
			pos += _4.node.length();
			skip_spaces(pos);
			::Parser::Types::cll_loop_while data;
			data.expr = _2.node;
			data.stmt = _4.node;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_loop_while, data)};
		}
		template <class IT>
		::Parser::Rule_res rule_data_block_regular_datablock_key(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::ID))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::Token _2;
			::Parser::bool_t success_3 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_21))
			{
				return {};
			}
			_2 = *pos;
			success_3 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::Rule_res _4;
			::Parser::bool_t success_5 = false;
			_4 = cll_expr(pos);
			if (!(_4.node))
			{
				return {};
			}
			success_5 = true;
			pos += _4.node.length();
			skip_spaces(pos);
			::Parser::Types::rule_data_block_regular_datablock_key data;
			data.name = _0;
			data.dt = _4.node;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::rule_data_block_regular_datablock_key, data)};
		}
		template <class IT>
		::Parser::Rule_res moduleImport(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_22))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::UNDEF _2;
			::Parser::bool_t success_3 = 1;
			dfa_lookup_result_4 = DFA_DECIDE(pos);
			switch (dfa_lookup_result_4)
			{
				case 0: {
					_2 = *pos;

					break;

				}
				case 1: {
					_2 = moduleImport_from(*pos);

					break;

				}
			}
;
			skip_spaces(pos);
			::Parser::Types::moduleImport data = NONE;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::moduleImport, data)};
		}
		template <class IT>
		::Parser::Rule_res rule_value(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_23))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::Token _2;
			::Parser::bool_t success_3 = false;
			if (!(pos->name() == ::Parser::Tokens::ID))
			{
				return {};
			}
			_2 = *pos;
			success_3 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::Types::rule_value data = NONE;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::rule_value, data)};
		}
	};

} // Parser


#endif // PARSER
