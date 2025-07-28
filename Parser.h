#pragma once
#ifndef PARSER
#define PARSER

#include <string>
#include <unordered_map>
#include <iterator>
#include <array>
#include <memory>
#include <ispastdlib.hpp>
#ifndef PARSER_OBJ_TYPE
#define PARSER_OBJ_TYPE std::unordered_map
#endif
#ifndef PARSER_ARR_TYPE
#define PARSER_ARR_TYPE std::vector
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
		using cll_COMPARE_OP = ::Parser::str_t;
		using AUTO_11 = ::Parser::str_t;
		struct rule_CSEQUENCE_DIAPASON {
			::Parser::Token to;
			::Parser::Token from;
		};
		using cll_OP = ::Parser::str_t;
		using AUTO_9 = ::Parser::str_t;
		using AUTO_0 = char;
		struct rule_CSEQUENCE {
			::Parser::arr_t<::Parser::Token> val;
			char _not;
		};
		struct NUMBER {
			::Parser::str_t main;
			::Parser::str_t dec;
			::Parser::str_t sign;
		};
		using cll_LOGICAL_OP = ::Parser::Token;
		using AUTO_3 = char;
		using AUTO_13 = char;
		using AUTO_18 = ::Parser::str_t;
		using rule_CSEQUENCE_ESCAPE = char;
		using AUTO_1 = char;
		using SPACEMODE = ::Parser::str_t;
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
		using cll_ASSIGNMENT_OP = ::Parser::Token;
		using AUTO_20 = ::Parser::str_t;
		using AUTO_8 = ::Parser::str_t;
		using AUTO_21 = char;
		using STRING = ::Parser::str_t;
		using rule_CSEQUENCE_SYMBOL = ::Parser::str_t;
		using AUTO_23 = char;
		using ID = ::Parser::str_t;
		using AUTO_22 = ::Parser::str_t;
		using AUTO_6 = char;
		struct cll_function_parameters {
			::Parser::Token first;
			::Parser::arr_t<::Parser::Token> second;
		};
		using rule_keyvalue = ::Parser::Token;
		struct cll_function_arguments {
			::Parser::Rule first;
			::Parser::arr_t<::Parser::Rule> second;
		};
		struct cll_method_call {
			::Parser::Token name;
			::Parser::Rule body;
		};
		struct cll_expr_compare {
			::Parser::Rule first;
			::Parser::arr_t<::Parser::Token> operators;
			::Parser::arr_t<::Parser::Rule> sequence;
		};
		using cll_stmt = ::Parser::arr_t<::Parser::Rule>;
		struct object {
			::Parser::Token key;
			::Parser::Rule value;
			::Parser::Token keys;
			::Parser::arr_t<::Parser::Rule> values;
		};
		using rule_value = ::Parser::Token;
		struct moduleImport_from {
			::Parser::any_t what;
			::Parser::Token from;
		};
		using rule_quantifier = ::Parser::Token;
		struct cll__if {
			::Parser::Rule expr;
			::Parser::Rule stmt;
		};
		struct moduleDeclaration {
			::Parser::Token name;
			::Parser::Token base;
		};
		using cll = ::Parser::Rule;
		using cll_expr_group = ::Parser::Rule;
		using moduleImport = ::Parser::any_t;
		using rule_data_block_regular_datablock = ::Parser::any_t;
		struct rule_name {
			::Parser::Token is_nested;
			::Parser::Token name;
			::Parser::arr_t<::Parser::Token> nested_name;
		};
		using cll_function_body_decl = ::Parser::Rule;
		using cll_expr_value = ::Parser::Rule;
		using rule_group = ::Parser::arr_t<::Parser::Rule>;
		struct rule_data_block_templated_datablock {
			::Parser::Token first_name;
			::Parser::arr_t<::Parser::Token> second_name;
		};
		struct rule_member {
			::Parser::Rule prefix;
			::Parser::Rule quantifier;
			::Parser::any_t val;
		};
		using array = ::Parser::arr_t<::Parser::Rule>;
		using main = ::Parser::any_t;
		struct rule {
			::Parser::Token name;
			::Parser::Rule data_block;
			::Parser::arr_t<::Parser::Rule> rule;
			::Parser::arr_t<::Parser::Rule> nested_rules;
		};
		struct cll_expr_arithmetic {
			::Parser::Rule first;
			::Parser::Token operators;
			::Parser::arr_t<::Parser::Rule> sequence;
		};
		struct _use {
			::Parser::Rule first;
			::Parser::arr_t<::Parser::Rule> second;
		};
		struct moduleImport_from_import_list {
			::Parser::Token first;
			::Parser::arr_t<::Parser::Token> sequence;
		};
		struct _use_unit {
			::Parser::Token name;
			::Parser::Rule value;
		};
		using rvalue = ::Parser::any_t;
		using rule_nested_rule = ::Parser::Rule;
		struct cll__variable {
			::Parser::Token pre;
			::Parser::Rule brace_expression;
			::Parser::Token pos;
			::Parser::Token name;
		};
		struct cll_loop_for {
			::Parser::Rule decl;
			::Parser::Rule end;
			::Parser::Rule cond;
			::Parser::Rule stmt;
		};
		struct cll_loop_while {
			::Parser::Rule expr;
			::Parser::Rule stmt;
		};
		struct cll__var {
			::Parser::Token type;
			::Parser::Token id;
			::Parser::Token op;
			::Parser::Rule value;
		};
		struct cll_expr_logical {
			::Parser::Rule left;
			::Parser::arr_t<::Parser::Token> op;
			::Parser::arr_t<::Parser::Rule> right;
		};
		struct cll_expr_term {
			::Parser::Rule first;
			::Parser::Token operators;
			::Parser::arr_t<::Parser::Rule> sequence;
		};
		using cll_expr = ::Parser::Rule;
		struct cll_function_decl {
			::Parser::arr_t<::Parser::Token> type;
			::Parser::Rule name;
			::Parser::Rule stmt;
		};
		struct cll_function_call {
			::Parser::Token name;
			::Parser::Rule body;
		};
		using rule_data_block = ::Parser::Rule;
		using cll_function_body_call = ::Parser::Rule;
		struct rule_data_block_regular_datablock_key {
			::Parser::Token name;
			::Parser::Rule dt;
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
		const ::Parser::Types::cll_function_parameters& cll_function_parameters(const ::Parser::Rule &rule);
		::Parser::Types::cll_function_parameters& cll_function_parameters(::Parser::Rule &rule);
		const ::Parser::Types::rule_keyvalue& rule_keyvalue(const ::Parser::Rule &rule);
		::Parser::Types::rule_keyvalue& rule_keyvalue(::Parser::Rule &rule);
		const ::Parser::Types::cll_function_arguments& cll_function_arguments(const ::Parser::Rule &rule);
		::Parser::Types::cll_function_arguments& cll_function_arguments(::Parser::Rule &rule);
		const ::Parser::Types::cll_method_call& cll_method_call(const ::Parser::Rule &rule);
		::Parser::Types::cll_method_call& cll_method_call(::Parser::Rule &rule);
		const ::Parser::Types::cll_expr_compare& cll_expr_compare(const ::Parser::Rule &rule);
		::Parser::Types::cll_expr_compare& cll_expr_compare(::Parser::Rule &rule);
		const ::Parser::Types::cll_stmt& cll_stmt(const ::Parser::Rule &rule);
		::Parser::Types::cll_stmt& cll_stmt(::Parser::Rule &rule);
		const ::Parser::Types::object& object(const ::Parser::Rule &rule);
		::Parser::Types::object& object(::Parser::Rule &rule);
		const ::Parser::Types::rule_value& rule_value(const ::Parser::Rule &rule);
		::Parser::Types::rule_value& rule_value(::Parser::Rule &rule);
		const ::Parser::Types::moduleImport_from& moduleImport_from(const ::Parser::Rule &rule);
		::Parser::Types::moduleImport_from& moduleImport_from(::Parser::Rule &rule);
		const ::Parser::Types::rule_quantifier& rule_quantifier(const ::Parser::Rule &rule);
		::Parser::Types::rule_quantifier& rule_quantifier(::Parser::Rule &rule);
		const ::Parser::Types::cll__if& cll__if(const ::Parser::Rule &rule);
		::Parser::Types::cll__if& cll__if(::Parser::Rule &rule);
		const ::Parser::Types::moduleDeclaration& moduleDeclaration(const ::Parser::Rule &rule);
		::Parser::Types::moduleDeclaration& moduleDeclaration(::Parser::Rule &rule);
		const ::Parser::Types::cll& cll(const ::Parser::Rule &rule);
		::Parser::Types::cll& cll(::Parser::Rule &rule);
		const ::Parser::Types::cll_expr_group& cll_expr_group(const ::Parser::Rule &rule);
		::Parser::Types::cll_expr_group& cll_expr_group(::Parser::Rule &rule);
		const ::Parser::Types::moduleImport& moduleImport(const ::Parser::Rule &rule);
		::Parser::Types::moduleImport& moduleImport(::Parser::Rule &rule);
		const ::Parser::Types::rule_data_block_regular_datablock& rule_data_block_regular_datablock(const ::Parser::Rule &rule);
		::Parser::Types::rule_data_block_regular_datablock& rule_data_block_regular_datablock(::Parser::Rule &rule);
		const ::Parser::Types::rule_name& rule_name(const ::Parser::Rule &rule);
		::Parser::Types::rule_name& rule_name(::Parser::Rule &rule);
		const ::Parser::Types::cll_function_body_decl& cll_function_body_decl(const ::Parser::Rule &rule);
		::Parser::Types::cll_function_body_decl& cll_function_body_decl(::Parser::Rule &rule);
		const ::Parser::Types::cll_expr_value& cll_expr_value(const ::Parser::Rule &rule);
		::Parser::Types::cll_expr_value& cll_expr_value(::Parser::Rule &rule);
		const ::Parser::Types::rule_group& rule_group(const ::Parser::Rule &rule);
		::Parser::Types::rule_group& rule_group(::Parser::Rule &rule);
		const ::Parser::Types::rule_data_block_templated_datablock& rule_data_block_templated_datablock(const ::Parser::Rule &rule);
		::Parser::Types::rule_data_block_templated_datablock& rule_data_block_templated_datablock(::Parser::Rule &rule);
		const ::Parser::Types::rule_member& rule_member(const ::Parser::Rule &rule);
		::Parser::Types::rule_member& rule_member(::Parser::Rule &rule);
		const ::Parser::Types::array& array(const ::Parser::Rule &rule);
		::Parser::Types::array& array(::Parser::Rule &rule);
		const ::Parser::Types::main& main(const ::Parser::Rule &rule);
		::Parser::Types::main& main(::Parser::Rule &rule);
		const ::Parser::Types::rule& rule(const ::Parser::Rule &rule);
		::Parser::Types::rule& rule(::Parser::Rule &rule);
		const ::Parser::Types::cll_expr_arithmetic& cll_expr_arithmetic(const ::Parser::Rule &rule);
		::Parser::Types::cll_expr_arithmetic& cll_expr_arithmetic(::Parser::Rule &rule);
		const ::Parser::Types::_use& _use(const ::Parser::Rule &rule);
		::Parser::Types::_use& _use(::Parser::Rule &rule);
		const ::Parser::Types::moduleImport_from_import_list& moduleImport_from_import_list(const ::Parser::Rule &rule);
		::Parser::Types::moduleImport_from_import_list& moduleImport_from_import_list(::Parser::Rule &rule);
		const ::Parser::Types::_use_unit& _use_unit(const ::Parser::Rule &rule);
		::Parser::Types::_use_unit& _use_unit(::Parser::Rule &rule);
		const ::Parser::Types::rvalue& rvalue(const ::Parser::Rule &rule);
		::Parser::Types::rvalue& rvalue(::Parser::Rule &rule);
		const ::Parser::Types::rule_nested_rule& rule_nested_rule(const ::Parser::Rule &rule);
		::Parser::Types::rule_nested_rule& rule_nested_rule(::Parser::Rule &rule);
		const ::Parser::Types::cll__variable& cll__variable(const ::Parser::Rule &rule);
		::Parser::Types::cll__variable& cll__variable(::Parser::Rule &rule);
		const ::Parser::Types::cll_loop_for& cll_loop_for(const ::Parser::Rule &rule);
		::Parser::Types::cll_loop_for& cll_loop_for(::Parser::Rule &rule);
		const ::Parser::Types::cll_loop_while& cll_loop_while(const ::Parser::Rule &rule);
		::Parser::Types::cll_loop_while& cll_loop_while(::Parser::Rule &rule);
		const ::Parser::Types::cll__var& cll__var(const ::Parser::Rule &rule);
		::Parser::Types::cll__var& cll__var(::Parser::Rule &rule);
		const ::Parser::Types::cll_expr_logical& cll_expr_logical(const ::Parser::Rule &rule);
		::Parser::Types::cll_expr_logical& cll_expr_logical(::Parser::Rule &rule);
		const ::Parser::Types::cll_expr_term& cll_expr_term(const ::Parser::Rule &rule);
		::Parser::Types::cll_expr_term& cll_expr_term(::Parser::Rule &rule);
		const ::Parser::Types::cll_expr& cll_expr(const ::Parser::Rule &rule);
		::Parser::Types::cll_expr& cll_expr(::Parser::Rule &rule);
		const ::Parser::Types::cll_function_decl& cll_function_decl(const ::Parser::Rule &rule);
		::Parser::Types::cll_function_decl& cll_function_decl(::Parser::Rule &rule);
		const ::Parser::Types::cll_function_call& cll_function_call(const ::Parser::Rule &rule);
		::Parser::Types::cll_function_call& cll_function_call(::Parser::Rule &rule);
		const ::Parser::Types::rule_data_block& rule_data_block(const ::Parser::Rule &rule);
		::Parser::Types::rule_data_block& rule_data_block(::Parser::Rule &rule);
		const ::Parser::Types::cll_function_body_call& cll_function_body_call(const ::Parser::Rule &rule);
		::Parser::Types::cll_function_body_call& cll_function_body_call(::Parser::Rule &rule);
		const ::Parser::Types::rule_data_block_regular_datablock_key& rule_data_block_regular_datablock_key(const ::Parser::Rule &rule);
		::Parser::Types::rule_data_block_regular_datablock_key& rule_data_block_regular_datablock_key(::Parser::Rule &rule);
	}
	class Lexer : public ISPA_STD::Lexer_base<Tokens> {
		public:
			using ISPA_STD::Lexer_base<Tokens>::Lexer_base;
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
        static void printToken(std::ostream& os, const Token& token);		private:
			Token makeToken(const char*& pos);
		static const ISPA_STD::DFAAPI::CharTableState<4> dfa_state_0;
		static const ISPA_STD::DFAAPI::CharEmptyState<::Parser::Tokens> dfa_state_1;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_2;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_3;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_4;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_5;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_6;
		static const ISPA_STD::DFAAPI::CharEmptyState<::Parser::Tokens> dfa_state_7;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_8;
		static const ISPA_STD::DFAAPI::CharEmptyState<::Parser::Tokens> dfa_state_9;
		static const ISPA_STD::DFAAPI::CharTableState<5> dfa_state_10;
		static const ISPA_STD::DFAAPI::CharEmptyState<::Parser::Tokens> dfa_state_11;
		static const ISPA_STD::DFAAPI::MultiTableState<::Parser::Tokens, 3> dfa_state_12;
		static const ISPA_STD::DFAAPI::MultiTableEmptyState<::Parser::Tokens> dfa_state_13;
		static const ISPA_STD::DFAAPI::MultiTableEmptyState<::Parser::Tokens> dfa_state_14;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_15;
		static const ISPA_STD::DFAAPI::MultiTableState<::Parser::Tokens, 3> dfa_state_16;
		static const ISPA_STD::DFAAPI::MultiTableEmptyState<::Parser::Tokens> dfa_state_17;
		static const ISPA_STD::DFAAPI::MultiTableEmptyState<::Parser::Tokens> dfa_state_18;
		static const ISPA_STD::DFAAPI::CharTableState<2> dfa_state_19;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_20;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_21;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_22;
		static const ISPA_STD::DFAAPI::CharEmptyState<::Parser::Tokens> dfa_state_23;
		static const ISPA_STD::DFAAPI::CharTableState<2> dfa_state_24;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_25;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_26;
		static const ISPA_STD::DFAAPI::CharEmptyState<::Parser::Tokens> dfa_state_27;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_28;
		static const ISPA_STD::DFAAPI::CharEmptyState<::Parser::Tokens> dfa_state_29;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_30;
		static const ISPA_STD::DFAAPI::CharEmptyState<::Parser::Tokens> dfa_state_31;
		static const ISPA_STD::DFAAPI::MultiTableState<::Parser::Tokens, 3> dfa_state_32;
		static const ISPA_STD::DFAAPI::MultiTableEmptyState<::Parser::Tokens> dfa_state_33;
		static const ISPA_STD::DFAAPI::MultiTableState<::Parser::Tokens, 14> dfa_state_34;
		static const ISPA_STD::DFAAPI::MultiTableEmptyState<::Parser::Tokens> dfa_state_35;
		static const ISPA_STD::DFAAPI::CharTableState<12> dfa_state_36;
		static const ISPA_STD::DFAAPI::CharTableState<10> dfa_state_37;
		static const ISPA_STD::DFAAPI::CharTableState<10> dfa_state_38;
		static const ISPA_STD::DFAAPI::CharTableState<10> dfa_state_39;
		static const ISPA_STD::DFAAPI::MultiTableEmptyState<::Parser::Tokens> dfa_state_40;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_41;
		static const ISPA_STD::DFAAPI::CharTableState<2> dfa_state_42;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_43;
		static const ISPA_STD::DFAAPI::CharEmptyState<::Parser::Tokens> dfa_state_44;
		static const ISPA_STD::DFAAPI::MultiTableState<::Parser::Tokens, 14> dfa_state_45;
		static const ISPA_STD::DFAAPI::MultiTableEmptyState<::Parser::Tokens> dfa_state_46;
		static const ISPA_STD::DFAAPI::MultiTableEmptyState<::Parser::Tokens> dfa_state_47;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_48;
		static const ISPA_STD::DFAAPI::CharTableState<3> dfa_state_49;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_50;
		static const ISPA_STD::DFAAPI::CharEmptyState<::Parser::Tokens> dfa_state_51;
		static const ISPA_STD::DFAAPI::MultiTableState<::Parser::Tokens, 3> dfa_state_52;
		static const ISPA_STD::DFAAPI::CharTableState<128> dfa_state_53;
		static const ISPA_STD::DFAAPI::CharTableState<128> dfa_state_54;
		static const ISPA_STD::DFAAPI::MultiTableEmptyState<::Parser::Tokens> dfa_state_55;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_56;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_57;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_58;
		static const ISPA_STD::DFAAPI::CharTableState<2> dfa_state_59;
		static const ISPA_STD::DFAAPI::CharTableState<2> dfa_state_60;
		static const ISPA_STD::DFAAPI::CharEmptyState<::Parser::Tokens> dfa_state_61;
		static const ISPA_STD::DFAAPI::CharTableState<22> dfa_state_62;
		static const ISPA_STD::DFAAPI::CharTableState<22> dfa_state_63;
		static const ISPA_STD::DFAAPI::CharEmptyState<::Parser::Tokens> dfa_state_64;
		static const ISPA_STD::DFAAPI::CharTableState<2> dfa_state_65;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_66;
		static const ISPA_STD::DFAAPI::CharEmptyState<::Parser::Tokens> dfa_state_67;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_68;
		static const ISPA_STD::DFAAPI::CharEmptyState<::Parser::Tokens> dfa_state_69;
		static const ISPA_STD::DFAAPI::CharTableState<4> dfa_state_70;
		static const ISPA_STD::DFAAPI::CharEmptyState<::Parser::Tokens> dfa_state_71;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_72;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_73;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_74;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_75;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_76;
		static const ISPA_STD::DFAAPI::CharEmptyState<::Parser::Tokens> dfa_state_77;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_78;
		static const ISPA_STD::DFAAPI::CharEmptyState<::Parser::Tokens> dfa_state_79;
		static const ISPA_STD::DFAAPI::CharTableState<53> dfa_state_80;
		static const ISPA_STD::DFAAPI::CharTableState<63> dfa_state_81;
		static const ISPA_STD::DFAAPI::CharTableState<63> dfa_state_82;
		static const ISPA_STD::DFAAPI::CharEmptyState<::Parser::Tokens> dfa_state_83;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_84;
		static const ISPA_STD::DFAAPI::MultiTableEmptyState<::Parser::Tokens> dfa_state_85;
		static const ISPA_STD::DFAAPI::MultiTableEmptyState<::Parser::Tokens> dfa_state_86;
		static const ISPA_STD::DFAAPI::MultiTableState<::Parser::Tokens, 4> dfa_state_87;
		static const ISPA_STD::DFAAPI::CharTableState<2> dfa_state_88;
		static const ISPA_STD::DFAAPI::MultiTableState<::Parser::Tokens, 1> dfa_state_89;
		static const ISPA_STD::DFAAPI::MultiTableEmptyState<::Parser::Tokens> dfa_state_90;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_91;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_92;
		static const ISPA_STD::DFAAPI::CharEmptyState<::Parser::Tokens> dfa_state_93;
		static const ISPA_STD::DFAAPI::CharTableState<129> dfa_state_94;
		static const ISPA_STD::DFAAPI::CharEmptyState<::Parser::Tokens> dfa_state_95;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_96;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_97;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_98;
		static const ISPA_STD::DFAAPI::CharEmptyState<::Parser::Tokens> dfa_state_99;
		static const ISPA_STD::DFAAPI::CharTableState<129> dfa_state_100;
		static const ISPA_STD::DFAAPI::CharEmptyState<::Parser::Tokens> dfa_state_101;
		static const ISPA_STD::DFAAPI::CharTableState<2> dfa_state_102;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_103;
		static const ISPA_STD::DFAAPI::CharTableState<2> dfa_state_104;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_105;
		static const ISPA_STD::DFAAPI::CharEmptyState<::Parser::Tokens> dfa_state_106;
		static const ISPA_STD::DFAAPI::MultiTableState<::Parser::Tokens, 59> dfa_state_107;
		static const ISPA_STD::DFAAPI::CharTableState<63> dfa_state_108;
		static const ISPA_STD::DFAAPI::CharTableState<63> dfa_state_109;
		static const ISPA_STD::DFAAPI::MultiTableEmptyState<::Parser::Tokens> dfa_state_110;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_111;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_112;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_113;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_114;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_115;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_116;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_117;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_118;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_119;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_120;
		static const ISPA_STD::DFAAPI::MultiTableState<::Parser::Tokens, 1> dfa_state_121;
		static const ISPA_STD::DFAAPI::MultiTableEmptyState<::Parser::Tokens> dfa_state_122;
		static const ISPA_STD::DFAAPI::MultiTableState<::Parser::Tokens, 1> dfa_state_123;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_124;
		static const ISPA_STD::DFAAPI::CharTableState<2> dfa_state_125;
		static const ISPA_STD::DFAAPI::CharTableState<2> dfa_state_126;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_127;
		static const ISPA_STD::DFAAPI::MultiTableState<::Parser::Tokens, 1> dfa_state_128;
		static const ISPA_STD::DFAAPI::MultiTableEmptyState<::Parser::Tokens> dfa_state_129;
		static const ISPA_STD::DFAAPI::CharTableState<57> dfa_state_130;
		static const ISPA_STD::DFAAPI::CharTableState<55> dfa_state_131;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_132;
		static const ISPA_STD::DFAAPI::CharEmptyState<::Parser::Tokens> dfa_state_133;
		static const ISPA_STD::DFAAPI::CharEmptyState<::Parser::Tokens> dfa_state_134;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_135;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_136;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_137;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_138;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_139;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_140;
		static const ISPA_STD::DFAAPI::CharEmptyState<::Parser::Tokens> dfa_state_141;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_142;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_143;
		static const ISPA_STD::DFAAPI::CharEmptyState<::Parser::Tokens> dfa_state_144;
		static const ISPA_STD::DFAAPI::CharTableState<63> dfa_state_145;
		static const ISPA_STD::DFAAPI::CharTableState<63> dfa_state_146;
		static const ISPA_STD::DFAAPI::CharTableState<4> dfa_state_147;
		static const ISPA_STD::DFAAPI::CharTableState<53> dfa_state_148;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_149;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_150;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_151;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_152;
		static const ISPA_STD::DFAAPI::CharEmptyState<::Parser::Tokens> dfa_state_153;
		static const ISPA_STD::DFAAPI::CharEmptyState<::Parser::Tokens> dfa_state_154;
		static const ISPA_STD::DFAAPI::CharTableState<63> dfa_state_155;
		static const ISPA_STD::DFAAPI::CharTableState<63> dfa_state_156;
		static const ISPA_STD::DFAAPI::CharTableState<3> dfa_state_157;
		static const ISPA_STD::DFAAPI::CharTableState<53> dfa_state_158;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_159;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_160;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_161;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_162;
		static const ISPA_STD::DFAAPI::CharEmptyState<::Parser::Tokens> dfa_state_163;
		static const ISPA_STD::DFAAPI::CharTableState<63> dfa_state_164;
		static const ISPA_STD::DFAAPI::CharTableState<63> dfa_state_165;
		static const ISPA_STD::DFAAPI::CharTableState<2> dfa_state_166;
		static const ISPA_STD::DFAAPI::CharTableState<57> dfa_state_167;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_168;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_169;
		static const ISPA_STD::DFAAPI::MultiTableState<::Parser::Tokens, 1> dfa_state_170;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_171;
		static const ISPA_STD::DFAAPI::MultiTableEmptyState<::Parser::Tokens> dfa_state_172;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_173;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_174;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_175;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_176;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_177;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_178;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_179;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_180;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_181;
		static const ISPA_STD::DFAAPI::MultiTableState<::Parser::Tokens, 1> dfa_state_182;
		static const ISPA_STD::DFAAPI::MultiTableState<::Parser::Tokens, 1> dfa_state_183;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_184;
		static const ISPA_STD::DFAAPI::CharTableState<2> dfa_state_185;
		static const ISPA_STD::DFAAPI::CharTableState<2> dfa_state_186;
		static const ISPA_STD::DFAAPI::CharTableState<2> dfa_state_187;
		static const ISPA_STD::DFAAPI::CharTableState<53> dfa_state_188;
		static const ISPA_STD::DFAAPI::CharTableState<63> dfa_state_189;
		static const ISPA_STD::DFAAPI::CharTableState<63> dfa_state_190;
		static const ISPA_STD::DFAAPI::CharTableState<57> dfa_state_191;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_192;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_193;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_194;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_195;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_196;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_197;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_198;
		static const ISPA_STD::DFAAPI::CharTableState<3> dfa_state_199;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_200;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_201;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_202;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_203;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_204;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_205;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_206;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_207;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_208;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_209;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_210;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_211;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_212;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_213;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_214;
		static const ISPA_STD::DFAAPI::MultiTableEmptyState<::Parser::Tokens> dfa_state_215;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_216;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_217;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_218;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_219;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_220;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_221;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_222;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_223;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_224;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_225;
		static const ISPA_STD::DFAAPI::MultiTableState<::Parser::Tokens, 1> dfa_state_226;
		static const ISPA_STD::DFAAPI::MultiTableState<::Parser::Tokens, 1> dfa_state_227;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_228;
		static const ISPA_STD::DFAAPI::CharTableState<3> dfa_state_229;
		static const ISPA_STD::DFAAPI::CharTableState<2> dfa_state_230;
		static const ISPA_STD::DFAAPI::CharTableState<55> dfa_state_231;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_232;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_233;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_234;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_235;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_236;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_237;
		static const ISPA_STD::DFAAPI::CharTableState<63> dfa_state_238;
		static const ISPA_STD::DFAAPI::CharTableState<63> dfa_state_239;
		static const ISPA_STD::DFAAPI::CharTableState<53> dfa_state_240;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_241;
		static const ISPA_STD::DFAAPI::CharEmptyState<::Parser::Tokens> dfa_state_242;
		static const ISPA_STD::DFAAPI::CharTableState<63> dfa_state_243;
		static const ISPA_STD::DFAAPI::CharTableState<63> dfa_state_244;
		static const ISPA_STD::DFAAPI::CharTableState<2> dfa_state_245;
		static const ISPA_STD::DFAAPI::CharTableState<53> dfa_state_246;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_247;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_248;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_249;
		static const ISPA_STD::DFAAPI::CharEmptyState<::Parser::Tokens> dfa_state_250;
		static const ISPA_STD::DFAAPI::CharTableState<63> dfa_state_251;
		static const ISPA_STD::DFAAPI::CharTableState<63> dfa_state_252;
		static const ISPA_STD::DFAAPI::CharTableState<2> dfa_state_253;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_254;
		static const ISPA_STD::DFAAPI::CharEmptyState<::Parser::Tokens> dfa_state_255;
		static const ISPA_STD::DFAAPI::MultiTableState<::Parser::Tokens, 3> dfa_state_256;
		static const ISPA_STD::DFAAPI::MultiTableEmptyState<::Parser::Tokens> dfa_state_257;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_258;
		static const ISPA_STD::DFAAPI::CharEmptyState<::Parser::Tokens> dfa_state_259;
		static const ::ISPA_STD::DFAAPI::CharTable<::Parser::Tokens, 6> dfa_table_0;
		static const ::ISPA_STD::DFAAPI::CharTable<::Parser::Tokens, 2> dfa_table_1;
		static const ::ISPA_STD::DFAAPI::CharTable<::Parser::Tokens, 2> dfa_table_2;
		static const ::ISPA_STD::DFAAPI::CharTable<::Parser::Tokens, 2> dfa_table_3;
		static const ::ISPA_STD::DFAAPI::MultiTable<::Parser::Tokens, 4> dfa_table_4;
		static const ::ISPA_STD::DFAAPI::MultiTable<::Parser::Tokens, 3> dfa_table_5;
		static const ::ISPA_STD::DFAAPI::CharTable<::Parser::Tokens, 5> dfa_table_6;
		static const ::ISPA_STD::DFAAPI::CharTable<::Parser::Tokens, 4> dfa_table_7;
		static const ::ISPA_STD::DFAAPI::CharTable<::Parser::Tokens, 2> dfa_table_8;
		static const ::ISPA_STD::DFAAPI::CharTable<::Parser::Tokens, 2> dfa_table_9;
		static const ::ISPA_STD::DFAAPI::CharTable<::Parser::Tokens, 2> dfa_table_10;
		static const ::ISPA_STD::DFAAPI::MultiTable<::Parser::Tokens, 4> dfa_table_11;
		static const ::ISPA_STD::DFAAPI::CharTable<::Parser::Tokens, 2> dfa_table_12;
		static const ::ISPA_STD::DFAAPI::MultiTable<::Parser::Tokens, 10> dfa_table_13;
		static const ::ISPA_STD::DFAAPI::CharTable<::Parser::Tokens, 2> dfa_table_14;
		static const ::ISPA_STD::DFAAPI::CharTable<::Parser::Tokens, 2> dfa_table_15;
		static const ::ISPA_STD::DFAAPI::MultiTable<::Parser::Tokens, 11> dfa_table_16;
		static const ::ISPA_STD::DFAAPI::CharTable<::Parser::Tokens, 2> dfa_table_17;
		static const ::ISPA_STD::DFAAPI::CharTable<::Parser::Tokens, 2> dfa_table_18;
		static const ::ISPA_STD::DFAAPI::MultiTable<::Parser::Tokens, 7> dfa_table_19;
		static const ::ISPA_STD::DFAAPI::CharTable<::Parser::Tokens, 8> dfa_table_20;
		static const ::ISPA_STD::DFAAPI::CharTable<::Parser::Tokens, 2> dfa_table_21;
		static const ::ISPA_STD::DFAAPI::CharTable<::Parser::Tokens, 2> dfa_table_22;
		static const ::ISPA_STD::DFAAPI::CharTable<::Parser::Tokens, 7> dfa_table_23;
		static const ::ISPA_STD::DFAAPI::CharTable<::Parser::Tokens, 2> dfa_table_24;
		static const ::ISPA_STD::DFAAPI::CharTable<::Parser::Tokens, 2> dfa_table_25;
		static const ::ISPA_STD::DFAAPI::CharTable<::Parser::Tokens, 4> dfa_table_26;
		static const ::ISPA_STD::DFAAPI::MultiTable<::Parser::Tokens, 5> dfa_table_27;
		static const ::ISPA_STD::DFAAPI::MultiTable<::Parser::Tokens, 2> dfa_table_28;
		static const ::ISPA_STD::DFAAPI::CharTable<::Parser::Tokens, 3> dfa_table_29;
		static const ::ISPA_STD::DFAAPI::CharTable<::Parser::Tokens, 3> dfa_table_30;
		static const ::ISPA_STD::DFAAPI::CharTable<::Parser::Tokens, 9> dfa_table_31;
		static const ::ISPA_STD::DFAAPI::CharTable<::Parser::Tokens, 2> dfa_table_32;
		static const ::ISPA_STD::DFAAPI::MultiTable<::Parser::Tokens, 21> dfa_table_33;
		static const ::ISPA_STD::DFAAPI::MultiTable<::Parser::Tokens, 3> dfa_table_34;
		static const ::ISPA_STD::DFAAPI::MultiTable<::Parser::Tokens, 3> dfa_table_35;
		static const ::ISPA_STD::DFAAPI::CharTable<::Parser::Tokens, 5> dfa_table_36;
		static const ::ISPA_STD::DFAAPI::CharTable<::Parser::Tokens, 4> dfa_table_37;
		static const ::ISPA_STD::DFAAPI::MultiTable<::Parser::Tokens, 20> dfa_table_38;
		static const ::ISPA_STD::DFAAPI::MultiTable<::Parser::Tokens, 3> dfa_table_39;
		static const ::ISPA_STD::DFAAPI::MultiTable<::Parser::Tokens, 3> dfa_table_40;
		static const ::ISPA_STD::DFAAPI::CharTable<::Parser::Tokens, 18> dfa_table_41;
		static const ::ISPA_STD::DFAAPI::CharTable<::Parser::Tokens, 11> dfa_table_42;
		static const ::ISPA_STD::DFAAPI::CharTable<::Parser::Tokens, 10> dfa_table_43;
		static const ::ISPA_STD::DFAAPI::MultiTable<::Parser::Tokens, 25> dfa_table_44;
		static const ::ISPA_STD::DFAAPI::CharTable<::Parser::Tokens, 4> dfa_table_45;
		static const ::ISPA_STD::DFAAPI::MultiTable<::Parser::Tokens, 3> dfa_table_46;
		static const ::ISPA_STD::DFAAPI::MultiTable<::Parser::Tokens, 3> dfa_table_47;
		static const ::ISPA_STD::DFAAPI::MultiTable<::Parser::Tokens, 46> dfa_table_48;
		static const ::ISPA_STD::DFAAPI::MultiTable<::Parser::Tokens, 3> dfa_table_49;
		static const ::ISPA_STD::DFAAPI::MultiTable<::Parser::Tokens, 3> dfa_table_50;
		static const ::ISPA_STD::DFAAPI::CharTable<::Parser::Tokens, 12> dfa_table_51;
		static const ::ISPA_STD::DFAAPI::CharTable<::Parser::Tokens, 7> dfa_table_52;
		static const ::ISPA_STD::DFAAPI::CharTable<::Parser::Tokens, 9> dfa_table_53;
		static const ::ISPA_STD::DFAAPI::CharTable<::Parser::Tokens, 2> dfa_table_54;
		static const ::ISPA_STD::DFAAPI::MultiTable<::Parser::Tokens, 3> dfa_table_55;
		static const ::ISPA_STD::DFAAPI::CharTable<::Parser::Tokens, 5> dfa_table_56;
		static const ::ISPA_STD::DFAAPI::CharTable<::Parser::Tokens, 4> dfa_table_57;
		static const ::ISPA_STD::DFAAPI::CharTable<::Parser::Tokens, 2> dfa_table_58;
		static const ::ISPA_STD::DFAAPI::SpanCharTable<::Parser::Tokens> dfa_span_0;
		static const ::ISPA_STD::DFAAPI::SpanCharTable<::Parser::Tokens> dfa_span_1;
		static const ::ISPA_STD::DFAAPI::SpanCharTable<::Parser::Tokens> dfa_span_2;
		static const ::ISPA_STD::DFAAPI::SpanCharTable<::Parser::Tokens> dfa_span_3;
		static const ::ISPA_STD::DFAAPI::SpanMultiTable<::Parser::Tokens> dfa_span_4;
		static const ::ISPA_STD::DFAAPI::SpanMultiTable<::Parser::Tokens> dfa_span_5;
		static const ::ISPA_STD::DFAAPI::SpanCharTable<::Parser::Tokens> dfa_span_6;
		static const ::ISPA_STD::DFAAPI::SpanCharTable<::Parser::Tokens> dfa_span_7;
		static const ::ISPA_STD::DFAAPI::SpanCharTable<::Parser::Tokens> dfa_span_8;
		static const ::ISPA_STD::DFAAPI::SpanCharTable<::Parser::Tokens> dfa_span_9;
		static const ::ISPA_STD::DFAAPI::SpanCharTable<::Parser::Tokens> dfa_span_10;
		static const ::ISPA_STD::DFAAPI::SpanMultiTable<::Parser::Tokens> dfa_span_11;
		static const ::ISPA_STD::DFAAPI::SpanCharTable<::Parser::Tokens> dfa_span_12;
		static const ::ISPA_STD::DFAAPI::SpanMultiTable<::Parser::Tokens> dfa_span_13;
		static const ::ISPA_STD::DFAAPI::SpanCharTable<::Parser::Tokens> dfa_span_14;
		static const ::ISPA_STD::DFAAPI::SpanCharTable<::Parser::Tokens> dfa_span_15;
		static const ::ISPA_STD::DFAAPI::SpanMultiTable<::Parser::Tokens> dfa_span_16;
		static const ::ISPA_STD::DFAAPI::SpanCharTable<::Parser::Tokens> dfa_span_17;
		static const ::ISPA_STD::DFAAPI::SpanCharTable<::Parser::Tokens> dfa_span_18;
		static const ::ISPA_STD::DFAAPI::SpanMultiTable<::Parser::Tokens> dfa_span_19;
		static const ::ISPA_STD::DFAAPI::SpanCharTable<::Parser::Tokens> dfa_span_20;
		static const ::ISPA_STD::DFAAPI::SpanCharTable<::Parser::Tokens> dfa_span_21;
		static const ::ISPA_STD::DFAAPI::SpanCharTable<::Parser::Tokens> dfa_span_22;
		static const ::ISPA_STD::DFAAPI::SpanCharTable<::Parser::Tokens> dfa_span_23;
		static const ::ISPA_STD::DFAAPI::SpanCharTable<::Parser::Tokens> dfa_span_24;
		static const ::ISPA_STD::DFAAPI::SpanCharTable<::Parser::Tokens> dfa_span_25;
		static const ::ISPA_STD::DFAAPI::SpanCharTable<::Parser::Tokens> dfa_span_26;
		static const ::ISPA_STD::DFAAPI::SpanMultiTable<::Parser::Tokens> dfa_span_27;
		static const ::ISPA_STD::DFAAPI::SpanMultiTable<::Parser::Tokens> dfa_span_28;
		static const ::ISPA_STD::DFAAPI::SpanCharTable<::Parser::Tokens> dfa_span_29;
		static const ::ISPA_STD::DFAAPI::SpanCharTable<::Parser::Tokens> dfa_span_30;
		static const ::ISPA_STD::DFAAPI::SpanCharTable<::Parser::Tokens> dfa_span_31;
		static const ::ISPA_STD::DFAAPI::SpanCharTable<::Parser::Tokens> dfa_span_32;
		static const ::ISPA_STD::DFAAPI::SpanMultiTable<::Parser::Tokens> dfa_span_33;
		static const ::ISPA_STD::DFAAPI::SpanMultiTable<::Parser::Tokens> dfa_span_34;
		static const ::ISPA_STD::DFAAPI::SpanMultiTable<::Parser::Tokens> dfa_span_35;
		static const ::ISPA_STD::DFAAPI::SpanCharTable<::Parser::Tokens> dfa_span_36;
		static const ::ISPA_STD::DFAAPI::SpanCharTable<::Parser::Tokens> dfa_span_37;
		static const ::ISPA_STD::DFAAPI::SpanMultiTable<::Parser::Tokens> dfa_span_38;
		static const ::ISPA_STD::DFAAPI::SpanMultiTable<::Parser::Tokens> dfa_span_39;
		static const ::ISPA_STD::DFAAPI::SpanMultiTable<::Parser::Tokens> dfa_span_40;
		static const ::ISPA_STD::DFAAPI::SpanCharTable<::Parser::Tokens> dfa_span_41;
		static const ::ISPA_STD::DFAAPI::SpanCharTable<::Parser::Tokens> dfa_span_42;
		static const ::ISPA_STD::DFAAPI::SpanCharTable<::Parser::Tokens> dfa_span_43;
		static const ::ISPA_STD::DFAAPI::SpanMultiTable<::Parser::Tokens> dfa_span_44;
		static const ::ISPA_STD::DFAAPI::SpanCharTable<::Parser::Tokens> dfa_span_45;
		static const ::ISPA_STD::DFAAPI::SpanMultiTable<::Parser::Tokens> dfa_span_46;
		static const ::ISPA_STD::DFAAPI::SpanMultiTable<::Parser::Tokens> dfa_span_47;
		static const ::ISPA_STD::DFAAPI::SpanMultiTable<::Parser::Tokens> dfa_span_48;
		static const ::ISPA_STD::DFAAPI::SpanMultiTable<::Parser::Tokens> dfa_span_49;
		static const ::ISPA_STD::DFAAPI::SpanMultiTable<::Parser::Tokens> dfa_span_50;
		static const ::ISPA_STD::DFAAPI::SpanCharTable<::Parser::Tokens> dfa_span_51;
		static const ::ISPA_STD::DFAAPI::SpanCharTable<::Parser::Tokens> dfa_span_52;
		static const ::ISPA_STD::DFAAPI::SpanCharTable<::Parser::Tokens> dfa_span_53;
		static const ::ISPA_STD::DFAAPI::SpanCharTable<::Parser::Tokens> dfa_span_54;
		static const ::ISPA_STD::DFAAPI::SpanMultiTable<::Parser::Tokens> dfa_span_55;
		static const ::ISPA_STD::DFAAPI::SpanCharTable<::Parser::Tokens> dfa_span_56;
		static const ::ISPA_STD::DFAAPI::SpanCharTable<::Parser::Tokens> dfa_span_57;
		static const ::ISPA_STD::DFAAPI::SpanCharTable<::Parser::Tokens> dfa_span_58;
		static const ISPA_STD::fcdt_table<Tokens> first_character_dispatch_table;
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
            static void printRule(std::ostream &os, const Token &token, std::size_t &indentLevel, bool addSpaceOnBegin);
            static void printRule(std::ostream &os, const Rule &rule, std::size_t &indentLevel, bool addSpaceOnBegin);
            static void printRule(std::ostream &os, const std::any& data, std::size_t &indentLevel, bool addSpaceOnBegin);
		private:
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 11> dfa_state_0;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> dfa_state_1;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_2;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 9> dfa_state_3;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 12> dfa_state_4;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_5;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_6;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_7;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_8;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 10> dfa_state_9;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_10;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_11;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 11> dfa_state_12;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> dfa_state_13;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_14;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> dfa_state_15;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> dfa_state_16;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_17;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_18;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_19;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_20;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_21;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_22;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_23;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_24;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_25;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_26;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> dfa_state_27;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_28;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 11> dfa_state_29;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> dfa_state_30;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_31;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_32;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 12> dfa_state_33;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_34;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_35;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_36;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_37;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_38;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 9> dfa_state_39;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 11> dfa_state_40;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_41;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 11> dfa_state_42;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_43;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_44;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_45;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_46;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 5> dfa_state_47;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_48;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> dfa_state_49;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_50;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_51;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_52;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_53;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_54;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_55;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_56;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 7> dfa_state_57;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_58;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_59;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_60;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_61;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_62;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 14> dfa_state_63;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_64;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_65;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 15> dfa_state_66;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_67;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_68;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_69;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 19> dfa_state_70;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_71;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> dfa_state_72;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_73;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 17> dfa_state_74;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_75;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_76;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_77;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_78;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 11> dfa_state_79;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> dfa_state_80;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_81;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_82;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_83;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 19> dfa_state_84;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 1> dfa_state_85;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_86;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 11> dfa_state_87;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_88;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_89;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_90;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_91;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_92;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 9> dfa_state_93;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 7> dfa_state_94;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_95;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 9> dfa_state_96;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_97;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 7> dfa_state_98;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_99;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_100;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_101;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_102;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_103;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_104;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_105;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_106;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_107;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_108;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_109;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_110;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_111;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 7> dfa_state_112;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_113;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_114;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_115;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_116;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_117;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_118;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_119;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_120;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_121;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_122;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 21> dfa_state_123;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_124;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_125;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_126;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 21> dfa_state_127;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_128;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 5> dfa_state_129;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 5> dfa_state_130;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_131;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_132;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_133;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 15> dfa_state_134;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_135;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_136;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_137;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_138;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 11> dfa_state_139;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> dfa_state_140;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_141;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_142;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_143;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_144;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_145;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 14> dfa_state_146;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 11> dfa_state_147;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 20> dfa_state_148;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_149;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 17> dfa_state_150;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_151;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_152;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_153;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_154;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_155;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_156;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 14> dfa_state_157;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_158;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_159;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_160;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_161;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_162;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_163;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 13> dfa_state_164;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 14> dfa_state_165;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 18> dfa_state_166;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 14> dfa_state_167;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_168;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 7> dfa_state_169;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 8> dfa_state_170;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_171;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> dfa_state_172;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 8> dfa_state_173;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_174;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> dfa_state_175;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> dfa_state_176;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> dfa_state_177;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_178;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_179;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 13> dfa_state_180;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_181;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_182;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_183;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 13> dfa_state_184;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_185;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 5> dfa_state_186;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> dfa_state_187;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> dfa_state_188;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> dfa_state_189;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> dfa_state_190;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> dfa_state_191;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> dfa_state_192;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> dfa_state_193;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> dfa_state_194;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> dfa_state_195;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_196;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> dfa_state_197;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_198;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> dfa_state_199;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> dfa_state_200;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> dfa_state_201;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> dfa_state_202;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> dfa_state_203;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 5> dfa_state_204;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 5> dfa_state_205;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 5> dfa_state_206;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 5> dfa_state_207;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 11> dfa_state_208;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 7> dfa_state_209;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 7> dfa_state_210;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 7> dfa_state_211;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 7> dfa_state_212;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 7> dfa_state_213;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 7> dfa_state_214;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 7> dfa_state_215;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 7> dfa_state_216;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 11> dfa_state_217;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_218;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_219;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_220;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_221;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_222;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_223;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_224;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_225;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 12> dfa_state_226;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_227;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 19> dfa_state_228;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_229;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 1> dfa_state_230;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_231;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_232;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_233;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_234;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 6> dfa_state_235;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 6> dfa_state_236;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 6> dfa_state_237;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_238;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 8> dfa_state_239;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> dfa_state_240;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_241;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_242;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 9> dfa_state_243;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_244;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_245;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_246;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_247;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 11> dfa_state_248;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 10> dfa_state_249;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 5> dfa_state_250;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_251;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_252;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_253;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_254;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_255;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_256;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_257;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> dfa_state_258;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_259;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_260;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_261;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_262;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 11> dfa_state_263;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_264;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> dfa_state_265;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_266;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_267;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_268;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_269;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_270;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_271;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 10> dfa_state_272;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 11> dfa_state_273;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_274;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_275;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_276;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_277;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_278;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_279;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 5> dfa_state_280;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_281;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_282;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_283;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_284;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_285;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_286;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_287;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_288;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 7> dfa_state_289;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 1> dfa_state_290;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 12> dfa_state_291;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_292;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_293;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 11> dfa_state_294;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 8> dfa_state_295;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> dfa_state_296;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_297;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_298;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_299;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_300;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 11> dfa_state_301;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_302;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_303;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_304;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_305;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 10> dfa_state_306;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_307;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_308;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 5> dfa_state_309;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 1> dfa_state_310;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 5> dfa_state_311;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> dfa_state_312;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_313;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_314;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_315;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_316;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_317;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_318;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_319;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 6> dfa_state_320;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_321;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_322;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_323;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_324;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_325;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_326;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_327;
		static const ::ISPA_STD::DFAAPI::TokenTable<::Parser::Tokens, 36> dfa_table_0;
		static const ::ISPA_STD::DFAAPI::TokenTable<::Parser::Tokens, 5> dfa_table_1;
		static const ::ISPA_STD::DFAAPI::TokenTable<::Parser::Tokens, 4> dfa_table_2;
		static const ::ISPA_STD::DFAAPI::TokenTable<::Parser::Tokens, 45> dfa_table_3;
		static const ::ISPA_STD::DFAAPI::TokenTable<::Parser::Tokens, 6> dfa_table_4;
		static const ::ISPA_STD::DFAAPI::TokenTable<::Parser::Tokens, 102> dfa_table_5;
		static const ::ISPA_STD::DFAAPI::TokenTable<::Parser::Tokens, 6> dfa_table_6;
		static const ::ISPA_STD::DFAAPI::TokenTable<::Parser::Tokens, 165> dfa_table_7;
		static const ::ISPA_STD::DFAAPI::TokenTable<::Parser::Tokens, 20> dfa_table_8;
		static const ::ISPA_STD::DFAAPI::TokenTable<::Parser::Tokens, 4> dfa_table_9;
		static const ::ISPA_STD::DFAAPI::TokenTable<::Parser::Tokens, 4> dfa_table_10;
		static const ::ISPA_STD::DFAAPI::TokenTable<::Parser::Tokens, 4> dfa_table_11;
		static const ::ISPA_STD::DFAAPI::TokenTable<::Parser::Tokens, 4> dfa_table_12;
		static const ::ISPA_STD::DFAAPI::TokenTable<::Parser::Tokens, 4> dfa_table_13;
		static const ::ISPA_STD::DFAAPI::TokenTable<::Parser::Tokens, 4> dfa_table_14;
		static const ::ISPA_STD::DFAAPI::TokenTable<::Parser::Tokens, 45> dfa_table_15;
		static const ::ISPA_STD::DFAAPI::TokenTable<::Parser::Tokens, 41> dfa_table_16;
		static const ::ISPA_STD::DFAAPI::TokenTable<::Parser::Tokens, 8> dfa_table_17;

		static const ::ISPA_STD::DFAAPI::SpanTokenTable<::Parser::Tokens> dfa_span_0;
		static const ::ISPA_STD::DFAAPI::SpanTokenTable<::Parser::Tokens> dfa_span_1;
		static const ::ISPA_STD::DFAAPI::SpanTokenTable<::Parser::Tokens> dfa_span_2;
		static const ::ISPA_STD::DFAAPI::SpanTokenTable<::Parser::Tokens> dfa_span_3;
		static const ::ISPA_STD::DFAAPI::SpanTokenTable<::Parser::Tokens> dfa_span_4;
		static const ::ISPA_STD::DFAAPI::SpanTokenTable<::Parser::Tokens> dfa_span_5;
		static const ::ISPA_STD::DFAAPI::SpanTokenTable<::Parser::Tokens> dfa_span_6;
		static const ::ISPA_STD::DFAAPI::SpanTokenTable<::Parser::Tokens> dfa_span_7;
		static const ::ISPA_STD::DFAAPI::SpanTokenTable<::Parser::Tokens> dfa_span_8;
		static const ::ISPA_STD::DFAAPI::SpanTokenTable<::Parser::Tokens> dfa_span_9;
		static const ::ISPA_STD::DFAAPI::SpanTokenTable<::Parser::Tokens> dfa_span_10;
		static const ::ISPA_STD::DFAAPI::SpanTokenTable<::Parser::Tokens> dfa_span_11;
		static const ::ISPA_STD::DFAAPI::SpanTokenTable<::Parser::Tokens> dfa_span_12;
		static const ::ISPA_STD::DFAAPI::SpanTokenTable<::Parser::Tokens> dfa_span_13;
		static const ::ISPA_STD::DFAAPI::SpanTokenTable<::Parser::Tokens> dfa_span_14;
		static const ::ISPA_STD::DFAAPI::SpanTokenTable<::Parser::Tokens> dfa_span_15;
		static const ::ISPA_STD::DFAAPI::SpanTokenTable<::Parser::Tokens> dfa_span_16;
		static const ::ISPA_STD::DFAAPI::SpanTokenTable<::Parser::Tokens> dfa_span_17;
			Rule_res getRule(Lexer::lazy_iterator&);
			Rule_res getRule(Lexer::iterator&);
		void parseFromTokens();
		void lazyParse();
		template <class IT>
		::Parser::Rule_res cll_expr_value(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Rule_res _0;
			::Parser::bool_t success_1 = 1;
			int dfa_lookup_result_2;
			success_1 = 1;
			dfa_lookup_result_2 = ISPA_STD::DFA<Tokens>::decide(dfa_span_0, pos, &ISPA_STD::LLParser_base<Tokens, Rules>::PANIC_MODE);
			switch (dfa_lookup_result_2)
			{
				case 0: {
					_0 = cll_expr_group(pos);

					break;

				}
				case 1: {
					_0 = cll__variable(pos);

					break;

				}
				case 2: {
					_0 = cll_function_call(pos);

					break;

				}
				case 3: {
					_0 = cll_method_call(pos);

					break;

				}
				case 4: {
					_0 = rvalue(pos);

					break;

				}
			}
;
			skip_spaces(pos);
			::Parser::Types::cll_expr_value data = _0.node;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_expr_value, data)};
		}
		template <class IT>
		::Parser::Rule_res cll_function_arguments(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Rule_res _0;
			::Parser::bool_t success_1 = false;
			::Parser::bool_t success_8 = false;
			::Parser::bool_t success_5 = false;
			::Parser::bool_t success_3 = false;
			::Parser::Token _4;
			::Parser::arr_t<::Parser::Token> shadow_6;
			::Parser::Rule_res _7;
			::Parser::arr_t<::Parser::Rule> shadow_9;
			success_1 = false;
			_0 = cll_expr(pos);
			if (!(_0.status))
			{
				return {};
			}
			success_1 = true;
			pos += _0.node.length();
			skip_spaces(pos);
			success_8 = false;
			success_5 = false;
			success_3 = false;
			auto begin_10 = pos;
			while (1)
			{
				if (!(begin_10->name() == ::Parser::Tokens::AUTO_1))
				{
					break;
				}
				_4 = *begin_10;
				success_5 = true;
				begin_10 += 1;
				shadow_6.push_back(_4);
				skip_spaces(begin_10);
				_7 = cll_expr(begin_10);
				if (!(_7.status))
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
			data.second = shadow_9;
			data.first = _0.node;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_function_arguments, data)};
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
				return {};
			}
			success_5 = true;
			pos += _4.node.length();
			skip_spaces(pos);
			::Parser::Types::cll_method_call data;
			data.body = _4.node;
			data.name = _0;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_method_call, data)};
		}
		template <class IT>
		::Parser::Rule_res moduleImport_from(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::any_t _0;
			::Parser::bool_t success_1 = 1;
			int dfa_lookup_result_2;
			::Parser::Token _3;
			::Parser::bool_t success_4 = false;
			::Parser::Token _5;
			::Parser::bool_t success_6 = false;
			success_1 = 1;
			dfa_lookup_result_2 = ISPA_STD::DFA<Tokens>::decide(dfa_span_1, pos, &ISPA_STD::LLParser_base<Tokens, Rules>::PANIC_MODE);
			switch (dfa_lookup_result_2)
			{
				case 0: {
					_0 = *pos;

					break;

				}
				case 1: {
					_0 = moduleImport_from_import_list(pos);

					break;

				}
			}
;
			skip_spaces(pos);
			success_4 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_9))
			{
				return {};
			}
			_3 = *pos;
			success_4 = true;
			pos += 1;
			skip_spaces(pos);
			success_6 = false;
			if (!(pos->name() == ::Parser::Tokens::ID))
			{
				return {};
			}
			_5 = *pos;
			success_6 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::Types::moduleImport_from data;
			data.from = _5;
			data.what = _0;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::moduleImport_from, data)};
		}
		template <class IT>
		::Parser::Rule_res cll_function_parameters(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::bool_t success_8 = false;
			::Parser::bool_t success_5 = false;
			::Parser::bool_t success_3 = false;
			::Parser::Token _4;
			::Parser::arr_t<::Parser::Token> shadow_6;
			::Parser::Token _7;
			::Parser::arr_t<::Parser::Token> shadow_9;
			success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::ID))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			success_8 = false;
			success_5 = false;
			success_3 = false;
			auto begin_10 = pos;
			while (1)
			{
				if (!(begin_10->name() == ::Parser::Tokens::AUTO_1))
				{
					break;
				}
				_4 = *begin_10;
				success_5 = true;
				begin_10 += 1;
				shadow_6.push_back(_4);
				skip_spaces(begin_10);
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
			data.second = shadow_9;
			data.first = _0;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_function_parameters, data)};
		}
		template <class IT>
		::Parser::Rule_res rule_quantifier(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = 1;
			int dfa_lookup_result_2;
			success_1 = 1;
			dfa_lookup_result_2 = ISPA_STD::DFA<Tokens>::decide(dfa_span_2, pos, &ISPA_STD::LLParser_base<Tokens, Rules>::PANIC_MODE);
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
					_0 = *pos;

					break;

				}
			}
;
			skip_spaces(pos);
			::Parser::Types::rule_quantifier data = _0;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::rule_quantifier, data)};
		}
		template <class IT>
		::Parser::Rule_res rule_data_block_templated_datablock(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Token _2;
			::Parser::bool_t success_3 = false;
			::Parser::bool_t success_14 = false;
			::Parser::bool_t success_11 = false;
			::Parser::bool_t success_7 = false;
			::Parser::bool_t success_5 = false;
			::Parser::Token _6;
			::Parser::bool_t success_9 = false;
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
				return {};
			}
			_2 = *pos;
			success_3 = true;
			pos += 1;
			skip_spaces(pos);
			success_14 = false;
			success_11 = false;
			success_7 = false;
			success_5 = false;
			auto begin_17 = pos;
			do
			{
				if (!(begin_17->name() == ::Parser::Tokens::ID))
				{
					break;
				}
				_6 = *begin_17;
				success_7 = true;
				begin_17 += 1;
				skip_spaces(begin_17);
				success_9 = false;
				auto begin_16 = begin_17;
				while (1)
				{
					if (!(begin_16->name() == ::Parser::Tokens::AUTO_1))
					{
						break;
					}
					_10 = *begin_16;
					success_11 = true;
					begin_16 += 1;
					shadow_12.push_back(_10);
					skip_spaces(begin_16);
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
			success_19 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_2))
			{
				return {};
			}
			_18 = *pos;
			success_19 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::Types::rule_data_block_templated_datablock data;
			data.second_name = shadow_15;
			data.first_name = _6;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::rule_data_block_templated_datablock, data)};
		}
		template <class IT>
		::Parser::Rule_res rule_data_block_regular_datablock(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::any_t _2;
			::Parser::bool_t success_3 = 1;
			int dfa_lookup_result_4;
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
			success_3 = 1;
			dfa_lookup_result_4 = ISPA_STD::DFA<Tokens>::decide(dfa_span_3, pos, &ISPA_STD::LLParser_base<Tokens, Rules>::PANIC_MODE);
			switch (dfa_lookup_result_4)
			{
				case 0: {
					_2 = cll_expr(pos);

					break;

				}
				case 1: {
					_2 = rule_data_block_regular_datablock_key(pos);

					break;

				}
			}
;
			skip_spaces(pos);
			success_6 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_2))
			{
				return {};
			}
			_5 = *pos;
			success_6 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::Types::rule_data_block_regular_datablock data = _2;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::rule_data_block_regular_datablock, data)};
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
			if (!(pos->name() == ::Parser::Tokens::AUTO_3))
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
				return {};
			}
			success_3 = true;
			pos += _2.node.length();
			skip_spaces(pos);
			success_5 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_4))
			{
				return {};
			}
			_4 = *pos;
			success_5 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::Types::cll_function_body_decl data = _2.node;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_function_body_decl, data)};
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
			if (!(pos->name() == ::Parser::Tokens::AUTO_3))
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
			if (!(pos->name() == ::Parser::Tokens::AUTO_4))
			{
				return {};
			}
			_5 = *pos;
			success_6 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::Types::rule_group data = shadow_4;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::rule_group, data)};
		}
		template <class IT>
		::Parser::Rule_res rule_name(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Token _2;
			::Parser::bool_t success_3 = false;
			::Parser::bool_t success_10 = false;
			::Parser::bool_t success_7 = false;
			::Parser::bool_t success_5 = false;
			::Parser::Token _6;
			::Parser::arr_t<::Parser::Token> shadow_8;
			::Parser::Token _9;
			::Parser::arr_t<::Parser::Token> shadow_11;
			success_1 = false;
			if (pos->name() == ::Parser::Tokens::AUTO_5)
			{
				_0 = *pos;
				success_1 = true;
				pos += 1;
			}
			skip_spaces(pos);
			success_3 = false;
			if (!(pos->name() == ::Parser::Tokens::ID))
			{
				return {};
			}
			_2 = *pos;
			success_3 = true;
			pos += 1;
			skip_spaces(pos);
			success_10 = false;
			success_7 = false;
			success_5 = false;
			auto begin_12 = pos;
			while (1)
			{
				if (!(begin_12->name() == ::Parser::Tokens::DOT))
				{
					break;
				}
				_6 = *begin_12;
				success_7 = true;
				begin_12 += 1;
				shadow_8.push_back(_6);
				skip_spaces(begin_12);
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
			data.nested_name = shadow_11;
			data.name = _2;
			data.is_nested = _0;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::rule_name, data)};
		}
		template <class IT>
		::Parser::Rule_res rule_keyvalue(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::bool_t success_5 = false;
			::Parser::bool_t success_3 = false;
			::Parser::Token _4;
			success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::AT))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			success_5 = false;
			success_3 = false;
			auto begin_6 = pos;
			do
			{
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
			::Parser::Types::rule_keyvalue data = _4;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::rule_keyvalue, data)};
		}
		template <class IT>
		::Parser::Rule_res rule_member(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::bool_t success_3 = 1;
			::Parser::Rule _0;
			::Parser::bool_t success_1 = false;
			::Parser::Rule_res _2;
			int dfa_lookup_result_4;
			::Parser::any_t _6;
			::Parser::bool_t success_7 = 1;
			int dfa_lookup_result_8;
			::Parser::Rule_res _9;
			::Parser::bool_t success_10 = false;
			success_3 = 1;
			success_1 = false;
			auto begin_5 = pos;
			do
			{
				dfa_lookup_result_4 = ISPA_STD::DFA<Tokens>::decide(dfa_span_4, begin_5, &ISPA_STD::LLParser_base<Tokens, Rules>::PANIC_MODE);
				switch (dfa_lookup_result_4)
				{
					case 0: {
						_2 = rule_keyvalue(begin_5);

						break;

					}
					case 1: {
						_2 = rule_value(begin_5);

						break;

					}
				}
;
				_0 = _2.node;
			}
			while(0);
			if (success_3)
			{
				success_1 = true;
				pos = begin_5;
			}
			skip_spaces(pos);
			success_7 = 1;
			dfa_lookup_result_8 = ISPA_STD::DFA<Tokens>::decide(dfa_span_5, pos, &ISPA_STD::LLParser_base<Tokens, Rules>::PANIC_MODE);
			switch (dfa_lookup_result_8)
			{
				case 0: {
					_6 = rule_name(pos);

					break;

				}
				case 1: {
					_6 = rule_group(pos);

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
					_6 = *pos;

					break;

				}
				case 10: {
					_6 = *pos;

					break;

				}
				case 11: {
					_6 = cll(pos);

					break;

				}
			}
;
			skip_spaces(pos);
			success_10 = false;
			_9 = rule_quantifier(pos);
			if (_9.status)
			{
				success_10 = true;
				pos += _9.node.length();
			}
			skip_spaces(pos);
			::Parser::Types::rule_member data;
			data.val = _6;
			data.quantifier = _9.node;
			data.prefix = _0;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::rule_member, data)};
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
			if (!(pos->name() == ::Parser::Tokens::AUTO_6))
			{
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
			if (!(pos->name() == ::Parser::Tokens::AUTO_7))
			{
				return {};
			}
			_13 = *pos;
			success_14 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::Types::rule data;
			data.nested_rules = shadow_12;
			data.rule = shadow_6;
			data.data_block = _8.node;
			data.name = _0;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::rule, data)};
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
			skip_spaces(pos);
			::Parser::Types::_use_unit data;
			data.value = _2.node;
			data.name = _0;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::_use_unit, data)};
		}
		template <class IT>
		::Parser::Rule_res main(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::bool_t success_3 = 1;
			::Parser::bool_t success_1 = false;
			::Parser::bool_t success_6 = false;
			::Parser::any_t _2;
			int dfa_lookup_result_4;
			success_3 = 1;
			success_1 = false;
			auto begin_5 = pos;
			success_6 = false;
			while (1)
			{
				dfa_lookup_result_4 = ISPA_STD::DFA<Tokens>::decide(dfa_span_6, begin_5, &ISPA_STD::LLParser_base<Tokens, Rules>::PANIC_MODE);
				switch (dfa_lookup_result_4)
				{
					case 0: {
						_2 = _use(begin_5);

						break;

					}
					case 1: {
						_2 = rule(begin_5);

						break;

					}
					case 2: {
						_2 = *begin_5;

						break;

					}
					case 3: {
						_2 = *begin_5;

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
			::Parser::bool_t success_10 = false;
			::Parser::bool_t success_7 = false;
			::Parser::bool_t success_5 = false;
			::Parser::Token _6;
			::Parser::arr_t<::Parser::Token> shadow_8;
			::Parser::Rule_res _9;
			::Parser::arr_t<::Parser::Rule> shadow_11;
			::Parser::Token _13;
			::Parser::bool_t success_14 = false;
			success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_8))
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
				return {};
			}
			success_3 = true;
			pos += _2.node.length();
			skip_spaces(pos);
			success_10 = false;
			success_7 = false;
			success_5 = false;
			auto begin_12 = pos;
			while (1)
			{
				if (!(begin_12->name() == ::Parser::Tokens::AUTO_1))
				{
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
			if (!(pos->name() == ::Parser::Tokens::AUTO_7))
			{
				return {};
			}
			_13 = *pos;
			success_14 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::Types::_use data;
			data.second = shadow_11;
			data.first = _2.node;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::_use, data)};
		}
		template <class IT>
		::Parser::Rule_res moduleImport_from_import_list(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::bool_t success_8 = false;
			::Parser::bool_t success_5 = false;
			::Parser::bool_t success_3 = false;
			::Parser::Token _4;
			::Parser::arr_t<::Parser::Token> shadow_6;
			::Parser::Token _7;
			::Parser::arr_t<::Parser::Token> shadow_9;
			success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::ID))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			success_8 = false;
			success_5 = false;
			success_3 = false;
			auto begin_10 = pos;
			while (1)
			{
				if (!(begin_10->name() == ::Parser::Tokens::AUTO_1))
				{
					break;
				}
				_4 = *begin_10;
				success_5 = true;
				begin_10 += 1;
				shadow_6.push_back(_4);
				skip_spaces(begin_10);
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
			data.sequence = shadow_9;
			data.first = _0;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::moduleImport_from_import_list, data)};
		}
		template <class IT>
		::Parser::Rule_res cll_expr_compare(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Rule_res _0;
			::Parser::bool_t success_1 = false;
			::Parser::bool_t success_8 = false;
			::Parser::bool_t success_5 = false;
			::Parser::bool_t success_3 = false;
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
			success_8 = false;
			success_5 = false;
			success_3 = false;
			auto begin_10 = pos;
			while (1)
			{
				if (!(begin_10->name() == ::Parser::Tokens::cll_COMPARE_OP))
				{
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
			data.sequence = shadow_9;
			data.operators = shadow_6;
			data.first = _0.node;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_expr_compare, data)};
		}
		template <class IT>
		::Parser::Rule_res moduleDeclaration(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Token _2;
			::Parser::bool_t success_3 = false;
			::Parser::bool_t success_9 = false;
			::Parser::bool_t success_7 = false;
			::Parser::bool_t success_5 = false;
			::Parser::Token _6;
			::Parser::Token _8;
			::Parser::Token _11;
			::Parser::bool_t success_12 = false;
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
			if (!(pos->name() == ::Parser::Tokens::ID))
			{
				return {};
			}
			_2 = *pos;
			success_3 = true;
			pos += 1;
			skip_spaces(pos);
			success_9 = false;
			success_7 = false;
			success_5 = false;
			auto begin_10 = pos;
			do
			{
				if (!(begin_10->name() == ::Parser::Tokens::AUTO_11))
				{
					break;
				}
				_6 = *begin_10;
				success_7 = true;
				begin_10 += 1;
				skip_spaces(begin_10);
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
			success_12 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_7))
			{
				return {};
			}
			_11 = *pos;
			success_12 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::Types::moduleDeclaration data;
			data.base = _8;
			data.name = _2;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::moduleDeclaration, data)};
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
				return {};
			}
			_5 = *pos;
			success_6 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::Types::cll_stmt data = shadow_4;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_stmt, data)};
		}
		template <class IT>
		::Parser::Rule_res cll(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Rule_res _2;
			::Parser::bool_t success_3 = 1;
			int dfa_lookup_result_4;
			::Parser::Token _5;
			::Parser::bool_t success_6 = false;
			success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_12))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			success_3 = 1;
			dfa_lookup_result_4 = ISPA_STD::DFA<Tokens>::decide(dfa_span_7, pos, &ISPA_STD::LLParser_base<Tokens, Rules>::PANIC_MODE);
			switch (dfa_lookup_result_4)
			{
				case 0: {
					_2 = cll__var(pos);

					break;

				}
				case 1: {
					_2 = cll__if(pos);

					break;

				}
				case 2: {
					_2 = cll_expr(pos);

					break;

				}
				case 3: {
					_2 = cll_loop_while(pos);

					break;

				}
				case 4: {
					_2 = cll_loop_for(pos);

					break;

				}
			}
;
			skip_spaces(pos);
			success_6 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_7))
			{
				return {};
			}
			_5 = *pos;
			success_6 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::Types::cll data = _2.node;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll, data)};
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
			if (!(pos->name() == ::Parser::Tokens::AUTO_3))
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
				return {};
			}
			success_3 = true;
			pos += _2.node.length();
			skip_spaces(pos);
			success_5 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_4))
			{
				return {};
			}
			_4 = *pos;
			success_5 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::Types::cll_expr_group data = _2.node;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_expr_group, data)};
		}
		template <class IT>
		::Parser::Rule_res rvalue(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::any_t _0;
			::Parser::bool_t success_1 = 1;
			int dfa_lookup_result_2;
			success_1 = 1;
			dfa_lookup_result_2 = ISPA_STD::DFA<Tokens>::decide(dfa_span_8, pos, &ISPA_STD::LLParser_base<Tokens, Rules>::PANIC_MODE);
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
					_0 = *pos;

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
					_0 = array(pos);

					break;

				}
				case 6: {
					_0 = object(pos);

					break;

				}
			}
;
			skip_spaces(pos);
			::Parser::Types::rvalue data = _0;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::rvalue, data)};
		}
		template <class IT>
		::Parser::Rule_res array(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::bool_t success_10 = false;
			::Parser::bool_t success_7 = false;
			::Parser::bool_t success_3 = false;
			::Parser::bool_t success_5 = false;
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
			success_10 = false;
			success_7 = false;
			success_3 = false;
			auto begin_13 = pos;
			do
			{
				success_5 = false;
				auto begin_12 = begin_13;
				while (1)
				{
					_6 = cll_expr(begin_12);
					if (!(_6.status))
					{
						break;
					}
					success_7 = true;
					begin_12 += _6.node.length();
					shadow_8.push_back(_6.node);
					skip_spaces(begin_12);
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
			success_15 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_14))
			{
				return {};
			}
			_14 = *pos;
			success_15 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::Types::array data = shadow_8;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::array, data)};
		}
		template <class IT>
		::Parser::Rule_res cll__variable(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::bool_t success_3 = 1;
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Token _2;
			int dfa_lookup_result_4;
			::Parser::Token _6;
			::Parser::bool_t success_7 = false;
			::Parser::bool_t success_15 = false;
			::Parser::bool_t success_13 = false;
			::Parser::bool_t success_11 = false;
			::Parser::bool_t success_9 = false;
			::Parser::Token _10;
			::Parser::Rule_res _12;
			::Parser::Token _14;
			::Parser::bool_t success_20 = 1;
			::Parser::Token _17;
			::Parser::bool_t success_18 = false;
			::Parser::Token _19;
			int dfa_lookup_result_21;
			success_3 = 1;
			success_1 = false;
			auto begin_5 = pos;
			do
			{
				dfa_lookup_result_4 = ISPA_STD::DFA<Tokens>::decide(dfa_span_9, begin_5, &ISPA_STD::LLParser_base<Tokens, Rules>::PANIC_MODE);
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
				}
;
				_0 = _2;
			}
			while(0);
			if (success_3)
			{
				success_1 = true;
				pos = begin_5;
			}
			skip_spaces(pos);
			success_7 = false;
			if (!(pos->name() == ::Parser::Tokens::ID))
			{
				return {};
			}
			_6 = *pos;
			success_7 = true;
			pos += 1;
			skip_spaces(pos);
			success_15 = false;
			success_13 = false;
			success_11 = false;
			success_9 = false;
			auto begin_16 = pos;
			do
			{
				if (!(begin_16->name() == ::Parser::Tokens::AUTO_13))
				{
					break;
				}
				_10 = *begin_16;
				success_11 = true;
				begin_16 += 1;
				skip_spaces(begin_16);
				_12 = cll_expr(begin_16);
				if (!(_12.status))
				{
					break;
				}
				success_13 = true;
				begin_16 += _12.node.length();
				skip_spaces(begin_16);
				if (!(begin_16->name() == ::Parser::Tokens::AUTO_14))
				{
					break;
				}
				_14 = *begin_16;
				success_15 = true;
				begin_16 += 1;
			}
			while(0);
			if (success_11 && success_13 && success_15)
			{
				success_9 = true;
				pos = begin_16;
			}
			skip_spaces(pos);
			success_20 = 1;
			success_18 = false;
			auto begin_22 = pos;
			do
			{
				dfa_lookup_result_21 = ISPA_STD::DFA<Tokens>::decide(dfa_span_10, begin_22, &ISPA_STD::LLParser_base<Tokens, Rules>::PANIC_MODE);
				switch (dfa_lookup_result_21)
				{
					case 0: {
						_19 = *begin_22;

						break;

					}
					case 1: {
						_19 = *begin_22;

						break;

					}
				}
;
				_17 = _19;
			}
			while(0);
			if (success_20)
			{
				success_18 = true;
				pos = begin_22;
			}
			skip_spaces(pos);
			::Parser::Types::cll__variable data;
			data.name = _6;
			data.pos = _17;
			data.brace_expression = _12.node;
			data.pre = _0;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll__variable, data)};
		}
		template <class IT>
		::Parser::Rule_res object(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::bool_t success_27 = false;
			::Parser::bool_t success_23 = false;
			::Parser::bool_t success_20 = false;
			::Parser::bool_t success_17 = 1;
			::Parser::bool_t success_14 = false;
			::Parser::bool_t success_10 = false;
			::Parser::bool_t success_8 = false;
			::Parser::bool_t success_5 = 1;
			::Parser::bool_t success_3 = false;
			::Parser::Token _4;
			int dfa_lookup_result_6;
			::Parser::Token _7;
			::Parser::Rule_res _9;
			::Parser::bool_t success_12 = false;
			::Parser::Token _13;
			::Parser::arr_t<::Parser::Token> shadow_15;
			::Parser::Token _16;
			int dfa_lookup_result_18;
			::Parser::Token _19;
			::Parser::arr_t<::Parser::Token> shadow_21;
			::Parser::Rule_res _22;
			::Parser::arr_t<::Parser::Rule> shadow_24;
			::Parser::Token _26;
			::Parser::Token _29;
			::Parser::bool_t success_30 = false;
			success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_0))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			success_27 = false;
			success_23 = false;
			success_20 = false;
			success_17 = 1;
			success_14 = false;
			success_10 = false;
			success_8 = false;
			success_5 = 1;
			success_3 = false;
			auto begin_28 = pos;
			do
			{
				dfa_lookup_result_6 = ISPA_STD::DFA<Tokens>::decide(dfa_span_11, begin_28, &ISPA_STD::LLParser_base<Tokens, Rules>::PANIC_MODE);
				switch (dfa_lookup_result_6)
				{
					case 0: {
						_4 = *begin_28;

						break;

					}
					case 1: {
						_4 = *begin_28;

						break;

					}
				}
;
				skip_spaces(begin_28);
				if (!(begin_28->name() == ::Parser::Tokens::AUTO_6))
				{
					break;
				}
				_7 = *begin_28;
				success_8 = true;
				begin_28 += 1;
				skip_spaces(begin_28);
				_9 = cll_expr(begin_28);
				if (!(_9.status))
				{
					break;
				}
				success_10 = true;
				begin_28 += _9.node.length();
				skip_spaces(begin_28);
				success_12 = false;
				auto begin_25 = begin_28;
				while (1)
				{
					if (!(begin_25->name() == ::Parser::Tokens::AUTO_1))
					{
						break;
					}
					_13 = *begin_25;
					success_14 = true;
					begin_25 += 1;
					shadow_15.push_back(_13);
					skip_spaces(begin_25);
					dfa_lookup_result_18 = ISPA_STD::DFA<Tokens>::decide(dfa_span_12, begin_25, &ISPA_STD::LLParser_base<Tokens, Rules>::PANIC_MODE);
					switch (dfa_lookup_result_18)
					{
						case 0: {
							_16 = *begin_25;

							break;

						}
						case 1: {
							_16 = *begin_25;

							break;

						}
					}
;
					skip_spaces(begin_25);
					if (!(begin_25->name() == ::Parser::Tokens::AUTO_6))
					{
						break;
					}
					_19 = *begin_25;
					success_20 = true;
					begin_25 += 1;
					shadow_21.push_back(_19);
					skip_spaces(begin_25);
					_22 = cll_expr(begin_25);
					if (!(_22.status))
					{
						break;
					}
					success_23 = true;
					begin_25 += _22.node.length();
					shadow_24.push_back(_22.node);
				}
				if (success_14 && success_17 && success_20 && success_23)
				{
					success_12 = true;
					begin_28 = begin_25;
				}
				skip_spaces(begin_28);
				if (!(begin_28->name() == ::Parser::Tokens::AUTO_7))
				{
					break;
				}
				_26 = *begin_28;
				success_27 = true;
				begin_28 += 1;
			}
			while(0);
			if (success_5 && success_8 && success_10 && success_14 && success_17 && success_20 && success_23 && success_27)
			{
				success_3 = true;
				pos = begin_28;
			}
			skip_spaces(pos);
			success_30 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_2))
			{
				return {};
			}
			_29 = *pos;
			success_30 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::Types::object data;
			data.values = shadow_24;
			data.keys = _16;
			data.value = _9.node;
			data.key = _4;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::object, data)};
		}
		template <class IT>
		::Parser::Rule_res cll__var(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Token _2;
			::Parser::bool_t success_3 = false;
			::Parser::bool_t success_9 = false;
			::Parser::bool_t success_7 = false;
			::Parser::bool_t success_5 = false;
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
				return {};
			}
			_2 = *pos;
			success_3 = true;
			pos += 1;
			skip_spaces(pos);
			success_9 = false;
			success_7 = false;
			success_5 = false;
			auto begin_10 = pos;
			do
			{
				if (!(begin_10->name() == ::Parser::Tokens::cll_ASSIGNMENT_OP))
				{
					break;
				}
				_6 = *begin_10;
				success_7 = true;
				begin_10 += 1;
				skip_spaces(begin_10);
				_8 = cll_expr(begin_10);
				if (!(_8.status))
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
			data.value = _8.node;
			data.op = _6;
			data.id = _2;
			data.type = _0;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll__var, data)};
		}
		template <class IT>
		::Parser::Rule_res cll_expr_logical(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Rule_res _0;
			::Parser::bool_t success_1 = false;
			::Parser::bool_t success_8 = false;
			::Parser::bool_t success_5 = false;
			::Parser::bool_t success_3 = false;
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
			success_8 = false;
			success_5 = false;
			success_3 = false;
			auto begin_10 = pos;
			while (1)
			{
				if (!(begin_10->name() == ::Parser::Tokens::cll_LOGICAL_OP))
				{
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
			data.right = shadow_9;
			data.op = shadow_6;
			data.left = _0.node;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_expr_logical, data)};
		}
		template <class IT>
		::Parser::Rule_res cll_expr_term(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Rule_res _0;
			::Parser::bool_t success_1 = false;
			::Parser::bool_t success_8 = false;
			::Parser::bool_t success_5 = 1;
			::Parser::bool_t success_3 = false;
			::Parser::Token _4;
			int dfa_lookup_result_6;
			::Parser::Rule_res _7;
			::Parser::arr_t<::Parser::Rule> shadow_9;
			success_1 = false;
			_0 = cll_expr_value(pos);
			if (!(_0.status))
			{
				return {};
			}
			success_1 = true;
			pos += _0.node.length();
			skip_spaces(pos);
			success_8 = false;
			success_5 = 1;
			success_3 = false;
			auto begin_10 = pos;
			while (1)
			{
				dfa_lookup_result_6 = ISPA_STD::DFA<Tokens>::decide(dfa_span_13, begin_10, &ISPA_STD::LLParser_base<Tokens, Rules>::PANIC_MODE);
				switch (dfa_lookup_result_6)
				{
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
;
				skip_spaces(begin_10);
				_7 = cll_expr_value(begin_10);
				if (!(_7.status))
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
			::Parser::Types::cll_expr_term data;
			data.sequence = shadow_9;
			data.operators = _4;
			data.first = _0.node;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_expr_term, data)};
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
			skip_spaces(pos);
			::Parser::Types::cll_expr data = _0.node;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_expr, data)};
		}
		template <class IT>
		::Parser::Rule_res cll_expr_arithmetic(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Rule_res _0;
			::Parser::bool_t success_1 = false;
			::Parser::bool_t success_8 = false;
			::Parser::bool_t success_5 = 1;
			::Parser::bool_t success_3 = false;
			::Parser::Token _4;
			int dfa_lookup_result_6;
			::Parser::Rule_res _7;
			::Parser::arr_t<::Parser::Rule> shadow_9;
			success_1 = false;
			_0 = cll_expr_term(pos);
			if (!(_0.status))
			{
				return {};
			}
			success_1 = true;
			pos += _0.node.length();
			skip_spaces(pos);
			success_8 = false;
			success_5 = 1;
			success_3 = false;
			auto begin_10 = pos;
			while (1)
			{
				dfa_lookup_result_6 = ISPA_STD::DFA<Tokens>::decide(dfa_span_14, begin_10, &ISPA_STD::LLParser_base<Tokens, Rules>::PANIC_MODE);
				switch (dfa_lookup_result_6)
				{
					case 0: {
						_4 = *begin_10;

						break;

					}
					case 1: {
						_4 = *begin_10;

						break;

					}
				}
;
				skip_spaces(begin_10);
				_7 = cll_expr_term(begin_10);
				if (!(_7.status))
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
			::Parser::Types::cll_expr_arithmetic data;
			data.sequence = shadow_9;
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
			if (!(pos->name() == ::Parser::Tokens::AUTO_15))
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
				return {};
			}
			success_3 = true;
			pos += _2.node.length();
			skip_spaces(pos);
			success_5 = false;
			_4 = cll_stmt(pos);
			if (!(_4.status))
			{
				return {};
			}
			success_5 = true;
			pos += _4.node.length();
			skip_spaces(pos);
			::Parser::Types::cll__if data;
			data.stmt = _4.node;
			data.expr = _2.node;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll__if, data)};
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
			if (!(pos->name() == ::Parser::Tokens::AUTO_16))
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
			skip_spaces(pos);
			::Parser::Types::cll_function_decl data;
			data.stmt = _8.node;
			data.name = _6.node;
			data.type = shadow_4;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_function_decl, data)};
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
				return {};
			}
			success_3 = true;
			pos += _2.node.length();
			skip_spaces(pos);
			::Parser::Types::cll_function_call data;
			data.body = _2.node;
			data.name = _0;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_function_call, data)};
		}
		template <class IT>
		::Parser::Rule_res rule_data_block(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Rule_res _0;
			::Parser::bool_t success_1 = 1;
			int dfa_lookup_result_2;
			success_1 = 1;
			dfa_lookup_result_2 = ISPA_STD::DFA<Tokens>::decide(dfa_span_15, pos, &ISPA_STD::LLParser_base<Tokens, Rules>::PANIC_MODE);
			switch (dfa_lookup_result_2)
			{
				case 0: {
					_0 = rule_data_block_templated_datablock(pos);

					break;

				}
				case 1: {
					_0 = rule_data_block_regular_datablock(pos);

					break;

				}
			}
;
			skip_spaces(pos);
			::Parser::Types::rule_data_block data = _0.node;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::rule_data_block, data)};
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
			if (!(pos->name() == ::Parser::Tokens::AUTO_5))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			success_3 = false;
			_2 = rule(pos);
			if (!(_2.status))
			{
				return {};
			}
			success_3 = true;
			pos += _2.node.length();
			skip_spaces(pos);
			::Parser::Types::rule_nested_rule data = _2.node;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::rule_nested_rule, data)};
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
			if (!(pos->name() == ::Parser::Tokens::AUTO_3))
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
				return {};
			}
			success_3 = true;
			pos += _2.node.length();
			skip_spaces(pos);
			success_5 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_4))
			{
				return {};
			}
			_4 = *pos;
			success_5 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::Types::cll_function_body_call data = _2.node;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_function_body_call, data)};
		}
		template <class IT>
		::Parser::Rule_res cll_loop_for(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Token _2;
			::Parser::bool_t success_3 = false;
			::Parser::bool_t success_7 = 1;
			::Parser::Rule _4;
			::Parser::bool_t success_5 = false;
			::Parser::Rule_res _6;
			int dfa_lookup_result_8;
			::Parser::Token _10;
			::Parser::bool_t success_11 = false;
			::Parser::Rule_res _12;
			::Parser::bool_t success_13 = false;
			::Parser::Token _14;
			::Parser::bool_t success_15 = false;
			::Parser::Rule_res _16;
			::Parser::bool_t success_17 = false;
			::Parser::Token _18;
			::Parser::bool_t success_19 = false;
			::Parser::Rule_res _20;
			::Parser::bool_t success_21 = false;
			success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_17))
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
				return {};
			}
			_2 = *pos;
			success_3 = true;
			pos += 1;
			skip_spaces(pos);
			success_7 = 1;
			success_5 = false;
			auto begin_9 = pos;
			do
			{
				dfa_lookup_result_8 = ISPA_STD::DFA<Tokens>::decide(dfa_span_16, begin_9, &ISPA_STD::LLParser_base<Tokens, Rules>::PANIC_MODE);
				switch (dfa_lookup_result_8)
				{
					case 0: {
						_6 = cll_expr(begin_9);

						break;

					}
					case 1: {
						_6 = cll__var(begin_9);

						break;

					}
				}
;
				_4 = _6.node;
			}
			while(0);
			if (success_7)
			{
				success_5 = true;
				pos = begin_9;
			}
			skip_spaces(pos);
			success_11 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_7))
			{
				return {};
			}
			_10 = *pos;
			success_11 = true;
			pos += 1;
			skip_spaces(pos);
			success_13 = false;
			_12 = cll_expr(pos);
			if (_12.status)
			{
				success_13 = true;
				pos += _12.node.length();
			}
			skip_spaces(pos);
			success_15 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_7))
			{
				return {};
			}
			_14 = *pos;
			success_15 = true;
			pos += 1;
			skip_spaces(pos);
			success_17 = false;
			_16 = cll_expr(pos);
			if (_16.status)
			{
				success_17 = true;
				pos += _16.node.length();
			}
			skip_spaces(pos);
			success_19 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_4))
			{
				return {};
			}
			_18 = *pos;
			success_19 = true;
			pos += 1;
			skip_spaces(pos);
			success_21 = false;
			_20 = cll_stmt(pos);
			if (!(_20.status))
			{
				return {};
			}
			success_21 = true;
			pos += _20.node.length();
			skip_spaces(pos);
			::Parser::Types::cll_loop_for data;
			data.stmt = _20.node;
			data.cond = _12.node;
			data.end = _16.node;
			data.decl = _4;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_loop_for, data)};
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
			if (!(pos->name() == ::Parser::Tokens::AUTO_18))
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
				return {};
			}
			success_3 = true;
			pos += _2.node.length();
			skip_spaces(pos);
			success_5 = false;
			_4 = cll_stmt(pos);
			if (!(_4.status))
			{
				return {};
			}
			success_5 = true;
			pos += _4.node.length();
			skip_spaces(pos);
			::Parser::Types::cll_loop_while data;
			data.stmt = _4.node;
			data.expr = _2.node;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_loop_while, data)};
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
			if (!(pos->name() == ::Parser::Tokens::AUTO_21))
			{
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
				return {};
			}
			success_5 = true;
			pos += _4.node.length();
			skip_spaces(pos);
			::Parser::Types::rule_data_block_regular_datablock_key data;
			data.dt = _4.node;
			data.name = _0;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::rule_data_block_regular_datablock_key, data)};
		}
		template <class IT>
		::Parser::Rule_res moduleImport(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::any_t _2;
			::Parser::bool_t success_3 = 1;
			int dfa_lookup_result_4;
			success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_22))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			success_3 = 1;
			dfa_lookup_result_4 = ISPA_STD::DFA<Tokens>::decide(dfa_span_17, pos, &ISPA_STD::LLParser_base<Tokens, Rules>::PANIC_MODE);
			switch (dfa_lookup_result_4)
			{
				case 0: {
					_2 = *pos;

					break;

				}
				case 1: {
					_2 = moduleImport_from(pos);

					break;

				}
			}
;
			skip_spaces(pos);
			::Parser::Types::moduleImport data = _2;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::moduleImport, data)};
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
			if (!(pos->name() == ::Parser::Tokens::AUTO_23))
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
				return {};
			}
			_2 = *pos;
			success_3 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::Types::rule_value data = _2;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::rule_value, data)};
		}
	};

} // Parser


#endif // PARSER
