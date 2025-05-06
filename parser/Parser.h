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
		NONE, END, NEWLINE, QUESTION_MARK, PLUS, MINUS, DIVIDE, MULTIPLE, MODULO, LINEAR_COMMENT, ID, SPACEMODE, NAME, AT, STRING, NUMBER, BOOLEAN, cll_OP, cll_ASSIGNMENT_OP, cll_COMPARE_OP, cll_LOGICAL_OP, cll_LOGICAL_NOT, cll_LOGICAL_AND, cll_LOGICAL_OR, cll_TYPE, cll_TEMPLATE, Rule_OP, Rule_CSEQUENCE, Rule_CSEQUENCE_SYMBOL, Rule_CSEQUENCE_ESCAPE, Rule_CSEQUENCE_DIAPASON, Rule_NOSPACE, Rule_ESCAPED, Rule_HEX, Rule_BIN, AUTO_0, AUTO_1, AUTO_2, AUTO_3, AUTO_4, AUTO_5, AUTO_6, AUTO_7, AUTO_8, AUTO_9, AUTO_10, AUTO_11, AUTO_12, AUTO_13, AUTO_14, AUTO_15, AUTO_16, AUTO_17, AUTO_18, AUTO_19, AUTO_20, __WHITESPACE
	};
	enum class Rules {
		NONE, main, use, use_unit, array, object, any_data, cll, cll_if, cll_variable, cll_function_body_call, cll_function_body_decl, cll_function_arguments, cll_function_parameters, cll_cll_function_call, cll_function_decl, cll_expr, cll_expr_logical, cll_expr_compare, cll_expr_arithmetic, cll_expr_term, cll_expr_value, cll_expr_group, cll_var, cll_block, cll_loop_while, cll_loop_for, Rule, Rule_rule, Rule_name, Rule_group, Rule_keyvalue, Rule_value, Rule_nested_rule, Rule_data_block, Rule_data_block_regular_datablock, Rule_data_block_regular_datablock_key, Rule_data_block_templated_datablock, Rule_quantifier
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
			case Tokens::END: return "END";
			case Tokens::NEWLINE: return "NEWLINE";
			case Tokens::QUESTION_MARK: return "QUESTION_MARK";
			case Tokens::PLUS: return "PLUS";
			case Tokens::MINUS: return "MINUS";
			case Tokens::DIVIDE: return "DIVIDE";
			case Tokens::MULTIPLE: return "MULTIPLE";
			case Tokens::MODULO: return "MODULO";
			case Tokens::LINEAR_COMMENT: return "LINEAR_COMMENT";
			case Tokens::ID: return "ID";
			case Tokens::SPACEMODE: return "SPACEMODE";
			case Tokens::NAME: return "NAME";
			case Tokens::AT: return "AT";
			case Tokens::STRING: return "STRING";
			case Tokens::NUMBER: return "NUMBER";
			case Tokens::BOOLEAN: return "BOOLEAN";
			case Tokens::cll_OP: return "cll_OP";
			case Tokens::cll_ASSIGNMENT_OP: return "cll_ASSIGNMENT_OP";
			case Tokens::cll_COMPARE_OP: return "cll_COMPARE_OP";
			case Tokens::cll_LOGICAL_OP: return "cll_LOGICAL_OP";
			case Tokens::cll_LOGICAL_NOT: return "cll_LOGICAL_NOT";
			case Tokens::cll_LOGICAL_AND: return "cll_LOGICAL_AND";
			case Tokens::cll_LOGICAL_OR: return "cll_LOGICAL_OR";
			case Tokens::cll_TYPE: return "cll_TYPE";
			case Tokens::cll_TEMPLATE: return "cll_TEMPLATE";
			case Tokens::Rule_OP: return "Rule_OP";
			case Tokens::Rule_CSEQUENCE: return "Rule_CSEQUENCE";
			case Tokens::Rule_CSEQUENCE_SYMBOL: return "Rule_CSEQUENCE_SYMBOL";
			case Tokens::Rule_CSEQUENCE_ESCAPE: return "Rule_CSEQUENCE_ESCAPE";
			case Tokens::Rule_CSEQUENCE_DIAPASON: return "Rule_CSEQUENCE_DIAPASON";
			case Tokens::Rule_NOSPACE: return "Rule_NOSPACE";
			case Tokens::Rule_ESCAPED: return "Rule_ESCAPED";
			case Tokens::Rule_HEX: return "Rule_HEX";
			case Tokens::Rule_BIN: return "Rule_BIN";
			case Tokens::AUTO_0: return "AUTO_0";
			case Tokens::AUTO_1: return "AUTO_1";
			case Tokens::AUTO_2: return "AUTO_2";
			case Tokens::AUTO_3: return "AUTO_3";
			case Tokens::AUTO_4: return "AUTO_4";
			case Tokens::AUTO_5: return "AUTO_5";
			case Tokens::AUTO_6: return "AUTO_6";
			case Tokens::AUTO_7: return "AUTO_7";
			case Tokens::AUTO_8: return "AUTO_8";
			case Tokens::AUTO_9: return "AUTO_9";
			case Tokens::AUTO_10: return "AUTO_10";
			case Tokens::AUTO_11: return "AUTO_11";
			case Tokens::AUTO_12: return "AUTO_12";
			case Tokens::AUTO_13: return "AUTO_13";
			case Tokens::AUTO_14: return "AUTO_14";
			case Tokens::AUTO_15: return "AUTO_15";
			case Tokens::AUTO_16: return "AUTO_16";
			case Tokens::AUTO_17: return "AUTO_17";
			case Tokens::AUTO_18: return "AUTO_18";
			case Tokens::AUTO_19: return "AUTO_19";
			case Tokens::AUTO_20: return "AUTO_20";
			case Tokens::__WHITESPACE: return "__WHITESPACE";
		}
		return "NONE";
	}
	constexpr const char* RulesToString(Rules rule) {
		switch (rule) {
			case Rules::NONE: return "NONE";
			case Rules::main: return "main";
			case Rules::use: return "use";
			case Rules::use_unit: return "use_unit";
			case Rules::array: return "array";
			case Rules::object: return "object";
			case Rules::any_data: return "any_data";
			case Rules::cll: return "cll";
			case Rules::cll_if: return "cll_if";
			case Rules::cll_variable: return "cll_variable";
			case Rules::cll_function_body_call: return "cll_function_body_call";
			case Rules::cll_function_body_decl: return "cll_function_body_decl";
			case Rules::cll_function_arguments: return "cll_function_arguments";
			case Rules::cll_function_parameters: return "cll_function_parameters";
			case Rules::cll_cll_function_call: return "cll_cll_function_call";
			case Rules::cll_function_decl: return "cll_function_decl";
			case Rules::cll_expr: return "cll_expr";
			case Rules::cll_expr_logical: return "cll_expr_logical";
			case Rules::cll_expr_compare: return "cll_expr_compare";
			case Rules::cll_expr_arithmetic: return "cll_expr_arithmetic";
			case Rules::cll_expr_term: return "cll_expr_term";
			case Rules::cll_expr_value: return "cll_expr_value";
			case Rules::cll_expr_group: return "cll_expr_group";
			case Rules::cll_var: return "cll_var";
			case Rules::cll_block: return "cll_block";
			case Rules::cll_loop_while: return "cll_loop_while";
			case Rules::cll_loop_for: return "cll_loop_for";
			case Rules::Rule: return "Rule";
			case Rules::Rule_rule: return "Rule_rule";
			case Rules::Rule_name: return "Rule_name";
			case Rules::Rule_group: return "Rule_group";
			case Rules::Rule_keyvalue: return "Rule_keyvalue";
			case Rules::Rule_value: return "Rule_value";
			case Rules::Rule_nested_rule: return "Rule_nested_rule";
			case Rules::Rule_data_block: return "Rule_data_block";
			case Rules::Rule_data_block_regular_datablock: return "Rule_data_block_regular_datablock";
			case Rules::Rule_data_block_regular_datablock_key: return "Rule_data_block_regular_datablock_key";
			case Rules::Rule_data_block_templated_datablock: return "Rule_data_block_templated_datablock";
			case Rules::Rule_quantifier: return "Rule_quantifier";
		}
		return "NONE";
	}
	namespace Types {
		using ID_data = ::Parser::str_t;
		using SPACEMODE_data = ::Parser::str_t;
		using NAME_data = ::Parser::Token;
		using STRING_data = ::Parser::str_t;
		struct NUMBER_data {
			::Parser::str_t dec;
			::Parser::str_t main;
			::Parser::str_t sign;
		};
		using BOOLEAN_data = ::Parser::str_t;
		using cll_OP_data = ::Parser::str_t;
		using cll_ASSIGNMENT_OP_data = ::Parser::Token;
		using cll_COMPARE_OP_data = ::Parser::str_t;
		using cll_LOGICAL_OP_data = ::Parser::Token;
		struct cll_TYPE_data {
			::Parser::Token templ;
			::Parser::str_t type;
		};
		struct cll_TEMPLATE_data {
			::Parser::arr_t<::Parser::Token> second;
			::Parser::Token first;
		};
		using Rule_CSEQUENCE_SYMBOL_data = ::Parser::str_t;
		using Rule_CSEQUENCE_ESCAPE_data = ::Parser::str_t;
		using Rule_CSEQUENCE_DIAPASON_data = ::Parser::arr_t<::Parser::Token>;
		struct Rule_CSEQUENCE_data {
			::Parser::arr_t<::Parser::Token> val;
			::Parser::str_t _not;
		};
		using Rule_ESCAPED_data = ::Parser::str_t;
		using Rule_HEX_data = ::Parser::str_t;
		using Rule_BIN_data = ::Parser::str_t;
		using AUTO_0_data = ::Parser::str_t;
		using AUTO_1_data = ::Parser::str_t;
		using AUTO_2_data = ::Parser::str_t;
		using AUTO_3_data = ::Parser::str_t;
		using AUTO_4_data = ::Parser::str_t;
		using AUTO_5_data = ::Parser::str_t;
		using AUTO_6_data = ::Parser::str_t;
		using AUTO_7_data = ::Parser::str_t;
		using AUTO_8_data = ::Parser::str_t;
		using AUTO_9_data = ::Parser::str_t;
		using AUTO_10_data = ::Parser::str_t;
		using AUTO_11_data = ::Parser::str_t;
		using AUTO_12_data = ::Parser::str_t;
		using AUTO_13_data = ::Parser::str_t;
		using AUTO_14_data = ::Parser::str_t;
		using AUTO_15_data = ::Parser::str_t;
		using AUTO_16_data = ::Parser::str_t;
		using AUTO_17_data = ::Parser::str_t;
		using AUTO_18_data = ::Parser::str_t;
		using AUTO_19_data = ::Parser::str_t;
		using AUTO_20_data = ::Parser::str_t;
		using main_data = ::Parser::arr_t<::Parser::any_t>;
		struct use_unit_data {
			::Parser::Rule value;
			::Parser::Token name;
		};
		struct use_data {
			::Parser::arr_t<::Parser::Rule> second;
			::Parser::Rule first;
		};
		using array_data = ::Parser::arr_t<::Parser::Rule>;
		struct object_data {
			::Parser::arr_t<::Parser::Token> values;
			::Parser::arr_t<::Parser::Token> keys;
			::Parser::Rule value;
			::Parser::Rule key;
		};
		using any_data_data = ::Parser::any_t;
		struct cll_if_data {
			::Parser::Rule block;
			::Parser::Rule expr;
		};
		struct cll_variable_data {
			::Parser::Token post;
			::Parser::Token pre;
			::Parser::Rule brace_expression;
			::Parser::Token name;
		};
		using cll_function_body_call_data = ::Parser::Rule;
		using cll_function_body_decl_data = ::Parser::Rule;
		struct cll_function_arguments_data {
			::Parser::arr_t<::Parser::arr_t<::Parser::Token>> second;
			::Parser::any_t first;
		};
		struct cll_function_parameters_data {
			::Parser::arr_t<::Parser::Token> second;
			::Parser::Token first;
		};
		struct cll_cll_function_call_data {
			::Parser::Rule body;
			::Parser::Token name;
		};
		struct cll_function_decl_data {
			::Parser::Rule value;
			::Parser::Token name;
			::Parser::arr_t<::Parser::Token> type;
		};
		struct cll_expr_logical_data {
			::Parser::arr_t<::Parser::Rule> right;
			::Parser::arr_t<::Parser::Token> op;
			::Parser::Rule left;
		};
		struct cll_expr_compare_data {
			::Parser::arr_t<::Parser::Rule> sequence;
			::Parser::arr_t<::Parser::Token> operators;
			::Parser::Rule first;
		};
		struct cll_expr_arithmetic_data {
			::Parser::arr_t<::Parser::Rule> sequence;
			::Parser::arr_t<::Parser::Token> operators;
			::Parser::Rule first;
		};
		struct cll_expr_term_data {
			::Parser::arr_t<::Parser::Rule> sequence;
			::Parser::arr_t<::Parser::Token> operators;
			::Parser::Rule first;
		};
		using cll_expr_value_data = ::Parser::Rule;
		using cll_expr_group_data = ::Parser::Rule;
		using cll_expr_data = ::Parser::Rule;
		struct cll_var_data {
			::Parser::Rule value;
			::Parser::Token op;
			::Parser::Token id;
			::Parser::Token type;
		};
		using cll_block_data = ::Parser::arr_t<::Parser::Rule>;
		struct cll_loop_while_data {
			::Parser::Rule block;
			::Parser::Rule expr;
		};
		struct cll_loop_for_data {
			::Parser::Token block;
			::Parser::Token end;
			::Parser::Token cond;
			::Parser::Rule decl;
		};
		using cll_data = ::Parser::Rule;
		struct Rule_rule_data {
			::Parser::Rule quantifier;
			::Parser::any_t val;
			::Parser::Rule prefix;
		};
		struct Rule_name_data {
			::Parser::arr_t<::Parser::Token> nested_name;
			::Parser::Token name;
			::Parser::Token is_nested;
		};
		using Rule_group_data = ::Parser::arr_t<::Parser::Rule>;
		using Rule_keyvalue_data = ::Parser::Token;
		using Rule_value_data = ::Parser::Token;
		using Rule_nested_rule_data = ::Parser::Rule;
		struct Rule_data_block_regular_datablock_key_data {
			::Parser::Rule val;
			::Parser::Token name;
		};
		using Rule_data_block_regular_datablock_data = ::Parser::any_t;
		struct Rule_data_block_templated_datablock_data {
			::Parser::arr_t<::Parser::Token> second_name;
			::Parser::Token first_name;
		};
		using Rule_data_block_data = ::Parser::Rule;
		using Rule_quantifier_data = ::Parser::Token;
		struct Rule_data {
			::Parser::arr_t<::Parser::Rule> nested_rules;
			::Parser::Rule data_block;
			::Parser::arr_t<::Parser::Rule> rule;
			::Parser::Token name;
		};
	}

	namespace get {
		const ::Parser::Types::ID_data& ID(const ::Parser::Token &token);
		::Parser::Types::ID_data& ID(::Parser::Token &token);
		const ::Parser::Types::SPACEMODE_data& SPACEMODE(const ::Parser::Token &token);
		::Parser::Types::SPACEMODE_data& SPACEMODE(::Parser::Token &token);
		const ::Parser::Types::NAME_data& NAME(const ::Parser::Token &token);
		::Parser::Types::NAME_data& NAME(::Parser::Token &token);
		const ::Parser::Types::STRING_data& STRING(const ::Parser::Token &token);
		::Parser::Types::STRING_data& STRING(::Parser::Token &token);
		const ::Parser::Types::NUMBER_data& NUMBER(const ::Parser::Token &token);
		::Parser::Types::NUMBER_data& NUMBER(::Parser::Token &token);
		const ::Parser::Types::BOOLEAN_data& BOOLEAN(const ::Parser::Token &token);
		::Parser::Types::BOOLEAN_data& BOOLEAN(::Parser::Token &token);
		const ::Parser::Types::cll_OP_data& cll_OP(const ::Parser::Token &token);
		::Parser::Types::cll_OP_data& cll_OP(::Parser::Token &token);
		const ::Parser::Types::cll_ASSIGNMENT_OP_data& cll_ASSIGNMENT_OP(const ::Parser::Token &token);
		::Parser::Types::cll_ASSIGNMENT_OP_data& cll_ASSIGNMENT_OP(::Parser::Token &token);
		const ::Parser::Types::cll_COMPARE_OP_data& cll_COMPARE_OP(const ::Parser::Token &token);
		::Parser::Types::cll_COMPARE_OP_data& cll_COMPARE_OP(::Parser::Token &token);
		const ::Parser::Types::cll_LOGICAL_OP_data& cll_LOGICAL_OP(const ::Parser::Token &token);
		::Parser::Types::cll_LOGICAL_OP_data& cll_LOGICAL_OP(::Parser::Token &token);
		const ::Parser::Types::cll_TYPE_data& cll_TYPE(const ::Parser::Token &token);
		::Parser::Types::cll_TYPE_data& cll_TYPE(::Parser::Token &token);
		const ::Parser::Types::cll_TEMPLATE_data& cll_TEMPLATE(const ::Parser::Token &token);
		::Parser::Types::cll_TEMPLATE_data& cll_TEMPLATE(::Parser::Token &token);
		const ::Parser::Types::Rule_CSEQUENCE_SYMBOL_data& Rule_CSEQUENCE_SYMBOL(const ::Parser::Token &token);
		::Parser::Types::Rule_CSEQUENCE_SYMBOL_data& Rule_CSEQUENCE_SYMBOL(::Parser::Token &token);
		const ::Parser::Types::Rule_CSEQUENCE_ESCAPE_data& Rule_CSEQUENCE_ESCAPE(const ::Parser::Token &token);
		::Parser::Types::Rule_CSEQUENCE_ESCAPE_data& Rule_CSEQUENCE_ESCAPE(::Parser::Token &token);
		const ::Parser::Types::Rule_CSEQUENCE_DIAPASON_data& Rule_CSEQUENCE_DIAPASON(const ::Parser::Token &token);
		::Parser::Types::Rule_CSEQUENCE_DIAPASON_data& Rule_CSEQUENCE_DIAPASON(::Parser::Token &token);
		const ::Parser::Types::Rule_CSEQUENCE_data& Rule_CSEQUENCE(const ::Parser::Token &token);
		::Parser::Types::Rule_CSEQUENCE_data& Rule_CSEQUENCE(::Parser::Token &token);
		const ::Parser::Types::Rule_ESCAPED_data& Rule_ESCAPED(const ::Parser::Token &token);
		::Parser::Types::Rule_ESCAPED_data& Rule_ESCAPED(::Parser::Token &token);
		const ::Parser::Types::Rule_HEX_data& Rule_HEX(const ::Parser::Token &token);
		::Parser::Types::Rule_HEX_data& Rule_HEX(::Parser::Token &token);
		const ::Parser::Types::Rule_BIN_data& Rule_BIN(const ::Parser::Token &token);
		::Parser::Types::Rule_BIN_data& Rule_BIN(::Parser::Token &token);
		const ::Parser::Types::AUTO_0_data& AUTO_0(const ::Parser::Token &token);
		::Parser::Types::AUTO_0_data& AUTO_0(::Parser::Token &token);
		const ::Parser::Types::AUTO_1_data& AUTO_1(const ::Parser::Token &token);
		::Parser::Types::AUTO_1_data& AUTO_1(::Parser::Token &token);
		const ::Parser::Types::AUTO_2_data& AUTO_2(const ::Parser::Token &token);
		::Parser::Types::AUTO_2_data& AUTO_2(::Parser::Token &token);
		const ::Parser::Types::AUTO_3_data& AUTO_3(const ::Parser::Token &token);
		::Parser::Types::AUTO_3_data& AUTO_3(::Parser::Token &token);
		const ::Parser::Types::AUTO_4_data& AUTO_4(const ::Parser::Token &token);
		::Parser::Types::AUTO_4_data& AUTO_4(::Parser::Token &token);
		const ::Parser::Types::AUTO_5_data& AUTO_5(const ::Parser::Token &token);
		::Parser::Types::AUTO_5_data& AUTO_5(::Parser::Token &token);
		const ::Parser::Types::AUTO_6_data& AUTO_6(const ::Parser::Token &token);
		::Parser::Types::AUTO_6_data& AUTO_6(::Parser::Token &token);
		const ::Parser::Types::AUTO_7_data& AUTO_7(const ::Parser::Token &token);
		::Parser::Types::AUTO_7_data& AUTO_7(::Parser::Token &token);
		const ::Parser::Types::AUTO_8_data& AUTO_8(const ::Parser::Token &token);
		::Parser::Types::AUTO_8_data& AUTO_8(::Parser::Token &token);
		const ::Parser::Types::AUTO_9_data& AUTO_9(const ::Parser::Token &token);
		::Parser::Types::AUTO_9_data& AUTO_9(::Parser::Token &token);
		const ::Parser::Types::AUTO_10_data& AUTO_10(const ::Parser::Token &token);
		::Parser::Types::AUTO_10_data& AUTO_10(::Parser::Token &token);
		const ::Parser::Types::AUTO_11_data& AUTO_11(const ::Parser::Token &token);
		::Parser::Types::AUTO_11_data& AUTO_11(::Parser::Token &token);
		const ::Parser::Types::AUTO_12_data& AUTO_12(const ::Parser::Token &token);
		::Parser::Types::AUTO_12_data& AUTO_12(::Parser::Token &token);
		const ::Parser::Types::AUTO_13_data& AUTO_13(const ::Parser::Token &token);
		::Parser::Types::AUTO_13_data& AUTO_13(::Parser::Token &token);
		const ::Parser::Types::AUTO_14_data& AUTO_14(const ::Parser::Token &token);
		::Parser::Types::AUTO_14_data& AUTO_14(::Parser::Token &token);
		const ::Parser::Types::AUTO_15_data& AUTO_15(const ::Parser::Token &token);
		::Parser::Types::AUTO_15_data& AUTO_15(::Parser::Token &token);
		const ::Parser::Types::AUTO_16_data& AUTO_16(const ::Parser::Token &token);
		::Parser::Types::AUTO_16_data& AUTO_16(::Parser::Token &token);
		const ::Parser::Types::AUTO_17_data& AUTO_17(const ::Parser::Token &token);
		::Parser::Types::AUTO_17_data& AUTO_17(::Parser::Token &token);
		const ::Parser::Types::AUTO_18_data& AUTO_18(const ::Parser::Token &token);
		::Parser::Types::AUTO_18_data& AUTO_18(::Parser::Token &token);
		const ::Parser::Types::AUTO_19_data& AUTO_19(const ::Parser::Token &token);
		::Parser::Types::AUTO_19_data& AUTO_19(::Parser::Token &token);
		const ::Parser::Types::AUTO_20_data& AUTO_20(const ::Parser::Token &token);
		::Parser::Types::AUTO_20_data& AUTO_20(::Parser::Token &token);
		const ::Parser::Types::main_data& main(const ::Parser::Rule &rule);
		::Parser::Types::main_data& main(::Parser::Rule &rule);
		const ::Parser::Types::use_unit_data& use_unit(const ::Parser::Rule &rule);
		::Parser::Types::use_unit_data& use_unit(::Parser::Rule &rule);
		const ::Parser::Types::use_data& use(const ::Parser::Rule &rule);
		::Parser::Types::use_data& use(::Parser::Rule &rule);
		const ::Parser::Types::array_data& array(const ::Parser::Rule &rule);
		::Parser::Types::array_data& array(::Parser::Rule &rule);
		const ::Parser::Types::object_data& object(const ::Parser::Rule &rule);
		::Parser::Types::object_data& object(::Parser::Rule &rule);
		const ::Parser::Types::any_data_data& any_data(const ::Parser::Rule &rule);
		::Parser::Types::any_data_data& any_data(::Parser::Rule &rule);
		const ::Parser::Types::cll_if_data& cll_if(const ::Parser::Rule &rule);
		::Parser::Types::cll_if_data& cll_if(::Parser::Rule &rule);
		const ::Parser::Types::cll_variable_data& cll_variable(const ::Parser::Rule &rule);
		::Parser::Types::cll_variable_data& cll_variable(::Parser::Rule &rule);
		const ::Parser::Types::cll_function_body_call_data& cll_function_body_call(const ::Parser::Rule &rule);
		::Parser::Types::cll_function_body_call_data& cll_function_body_call(::Parser::Rule &rule);
		const ::Parser::Types::cll_function_body_decl_data& cll_function_body_decl(const ::Parser::Rule &rule);
		::Parser::Types::cll_function_body_decl_data& cll_function_body_decl(::Parser::Rule &rule);
		const ::Parser::Types::cll_function_arguments_data& cll_function_arguments(const ::Parser::Rule &rule);
		::Parser::Types::cll_function_arguments_data& cll_function_arguments(::Parser::Rule &rule);
		const ::Parser::Types::cll_function_parameters_data& cll_function_parameters(const ::Parser::Rule &rule);
		::Parser::Types::cll_function_parameters_data& cll_function_parameters(::Parser::Rule &rule);
		const ::Parser::Types::cll_cll_function_call_data& cll_cll_function_call(const ::Parser::Rule &rule);
		::Parser::Types::cll_cll_function_call_data& cll_cll_function_call(::Parser::Rule &rule);
		const ::Parser::Types::cll_function_decl_data& cll_function_decl(const ::Parser::Rule &rule);
		::Parser::Types::cll_function_decl_data& cll_function_decl(::Parser::Rule &rule);
		const ::Parser::Types::cll_expr_logical_data& cll_expr_logical(const ::Parser::Rule &rule);
		::Parser::Types::cll_expr_logical_data& cll_expr_logical(::Parser::Rule &rule);
		const ::Parser::Types::cll_expr_compare_data& cll_expr_compare(const ::Parser::Rule &rule);
		::Parser::Types::cll_expr_compare_data& cll_expr_compare(::Parser::Rule &rule);
		const ::Parser::Types::cll_expr_arithmetic_data& cll_expr_arithmetic(const ::Parser::Rule &rule);
		::Parser::Types::cll_expr_arithmetic_data& cll_expr_arithmetic(::Parser::Rule &rule);
		const ::Parser::Types::cll_expr_term_data& cll_expr_term(const ::Parser::Rule &rule);
		::Parser::Types::cll_expr_term_data& cll_expr_term(::Parser::Rule &rule);
		const ::Parser::Types::cll_expr_value_data& cll_expr_value(const ::Parser::Rule &rule);
		::Parser::Types::cll_expr_value_data& cll_expr_value(::Parser::Rule &rule);
		const ::Parser::Types::cll_expr_group_data& cll_expr_group(const ::Parser::Rule &rule);
		::Parser::Types::cll_expr_group_data& cll_expr_group(::Parser::Rule &rule);
		const ::Parser::Types::cll_expr_data& cll_expr(const ::Parser::Rule &rule);
		::Parser::Types::cll_expr_data& cll_expr(::Parser::Rule &rule);
		const ::Parser::Types::cll_var_data& cll_var(const ::Parser::Rule &rule);
		::Parser::Types::cll_var_data& cll_var(::Parser::Rule &rule);
		const ::Parser::Types::cll_block_data& cll_block(const ::Parser::Rule &rule);
		::Parser::Types::cll_block_data& cll_block(::Parser::Rule &rule);
		const ::Parser::Types::cll_loop_while_data& cll_loop_while(const ::Parser::Rule &rule);
		::Parser::Types::cll_loop_while_data& cll_loop_while(::Parser::Rule &rule);
		const ::Parser::Types::cll_loop_for_data& cll_loop_for(const ::Parser::Rule &rule);
		::Parser::Types::cll_loop_for_data& cll_loop_for(::Parser::Rule &rule);
		const ::Parser::Types::cll_data& cll(const ::Parser::Rule &rule);
		::Parser::Types::cll_data& cll(::Parser::Rule &rule);
		const ::Parser::Types::Rule_rule_data& Rule_rule(const ::Parser::Rule &rule);
		::Parser::Types::Rule_rule_data& Rule_rule(::Parser::Rule &rule);
		const ::Parser::Types::Rule_name_data& Rule_name(const ::Parser::Rule &rule);
		::Parser::Types::Rule_name_data& Rule_name(::Parser::Rule &rule);
		const ::Parser::Types::Rule_group_data& Rule_group(const ::Parser::Rule &rule);
		::Parser::Types::Rule_group_data& Rule_group(::Parser::Rule &rule);
		const ::Parser::Types::Rule_keyvalue_data& Rule_keyvalue(const ::Parser::Rule &rule);
		::Parser::Types::Rule_keyvalue_data& Rule_keyvalue(::Parser::Rule &rule);
		const ::Parser::Types::Rule_value_data& Rule_value(const ::Parser::Rule &rule);
		::Parser::Types::Rule_value_data& Rule_value(::Parser::Rule &rule);
		const ::Parser::Types::Rule_nested_rule_data& Rule_nested_rule(const ::Parser::Rule &rule);
		::Parser::Types::Rule_nested_rule_data& Rule_nested_rule(::Parser::Rule &rule);
		const ::Parser::Types::Rule_data_block_regular_datablock_key_data& Rule_data_block_regular_datablock_key(const ::Parser::Rule &rule);
		::Parser::Types::Rule_data_block_regular_datablock_key_data& Rule_data_block_regular_datablock_key(::Parser::Rule &rule);
		const ::Parser::Types::Rule_data_block_regular_datablock_data& Rule_data_block_regular_datablock(const ::Parser::Rule &rule);
		::Parser::Types::Rule_data_block_regular_datablock_data& Rule_data_block_regular_datablock(::Parser::Rule &rule);
		const ::Parser::Types::Rule_data_block_templated_datablock_data& Rule_data_block_templated_datablock(const ::Parser::Rule &rule);
		::Parser::Types::Rule_data_block_templated_datablock_data& Rule_data_block_templated_datablock(::Parser::Rule &rule);
		const ::Parser::Types::Rule_data_block_data& Rule_data_block(const ::Parser::Rule &rule);
		::Parser::Types::Rule_data_block_data& Rule_data_block(::Parser::Rule &rule);
		const ::Parser::Types::Rule_quantifier_data& Rule_quantifier(const ::Parser::Rule &rule);
		::Parser::Types::Rule_quantifier_data& Rule_quantifier(::Parser::Rule &rule);
		const ::Parser::Types::Rule_data& Rule(const ::Parser::Rule &rule);
		::Parser::Types::Rule_data& Rule(::Parser::Rule &rule);
	}
	class Lexer : public ISPA_STD::Lexer_base<Tokens> {
		public:
			Token makeToken(const char*& pos);
			Lexer(const std::string& in) : Lexer_base(in) {}
			Lexer(char*& in) : Lexer_base(in) {}
			Lexer(const char*& in) : Lexer_base(in) {}
			Lexer(TokenFlow &tokens) : Lexer_base(tokens) {}
			Lexer() {}
		private:
			Token_res NONE(const char*);
			Token_res END(const char*);
			Token_res NEWLINE(const char*);
			Token_res QUESTION_MARK(const char*);
			Token_res PLUS(const char*);
			Token_res MINUS(const char*);
			Token_res DIVIDE(const char*);
			Token_res MULTIPLE(const char*);
			Token_res MODULO(const char*);
			Token_res LINEAR_COMMENT(const char*);
			Token_res ID(const char*);
			Token_res SPACEMODE(const char*);
			Token_res NAME(const char*);
			Token_res AT(const char*);
			Token_res STRING(const char*);
			Token_res NUMBER(const char*);
			Token_res BOOLEAN(const char*);
			Token_res cll_OP(const char*);
			Token_res cll_ASSIGNMENT_OP(const char*);
			Token_res cll_COMPARE_OP(const char*);
			Token_res cll_LOGICAL_OP(const char*);
			Token_res cll_LOGICAL_NOT(const char*);
			Token_res cll_LOGICAL_AND(const char*);
			Token_res cll_LOGICAL_OR(const char*);
			Token_res cll_TYPE(const char*);
			Token_res cll_TEMPLATE(const char*);
			Token_res Rule_OP(const char*);
			Token_res Rule_CSEQUENCE(const char*);
			Token_res Rule_CSEQUENCE_SYMBOL(const char*);
			Token_res Rule_CSEQUENCE_ESCAPE(const char*);
			Token_res Rule_CSEQUENCE_DIAPASON(const char*);
			Token_res Rule_NOSPACE(const char*);
			Token_res Rule_ESCAPED(const char*);
			Token_res Rule_HEX(const char*);
			Token_res Rule_BIN(const char*);
			Token_res AUTO_0(const char*);
			Token_res AUTO_1(const char*);
			Token_res AUTO_2(const char*);
			Token_res AUTO_3(const char*);
			Token_res AUTO_4(const char*);
			Token_res AUTO_5(const char*);
			Token_res AUTO_6(const char*);
			Token_res AUTO_7(const char*);
			Token_res AUTO_8(const char*);
			Token_res AUTO_9(const char*);
			Token_res AUTO_10(const char*);
			Token_res AUTO_11(const char*);
			Token_res AUTO_12(const char*);
			Token_res AUTO_13(const char*);
			Token_res AUTO_14(const char*);
			Token_res AUTO_15(const char*);
			Token_res AUTO_16(const char*);
			Token_res AUTO_17(const char*);
			Token_res AUTO_18(const char*);
			Token_res AUTO_19(const char*);
			Token_res AUTO_20(const char*);
			Token_res __WHITESPACE(const char*);
	};
	class Parser : public ISPA_STD::LLParser_base<Tokens, Rules> {
		Rule_res getRule(Lexer::lazy_iterator&);
		Rule_res getRule(Lexer::iterator&);
		void parseFromTokens();
		void lazyParse();
		template <class IT>
		::Parser::Rule_res main(IT pos) {
			auto in = pos;
			skip_spaces(pos);
;
			::Parser::arr_t<::Parser::any_t> _0;
			::Parser::bool_t success_1 = false;
			::Parser::bool_t success_3 = false;
			::Parser::bool_t success_17 = false;
			::Parser::arr_t<::Parser::any_t> _2;
			::Parser::Token _4;
			::Parser::bool_t success_5 = false;
			::Parser::arr_t<::Parser::Token> shadow_6;
			::Parser::Rule_res _7;
			::Parser::bool_t success_8 = false;
			::Parser::arr_t<::Parser::Rule> shadow_9;
			::Parser::Rule_res _10;
			::Parser::bool_t success_11 = false;
			::Parser::arr_t<::Parser::Rule> shadow_12;
			::Parser::Token _13;
			::Parser::bool_t success_14 = false;
			::Parser::arr_t<::Parser::Token> shadow_15;
			::Parser::arr_t<::Parser::arr_t<::Parser::any_t>> shadow_16;
			success_17 = false;
			success_3 = false;
			success_1 = false;
			auto begin_2 = pos;
			while (1)
			{
				success_5 = false;
				if (!(begin_2->name() == ::Parser::Tokens::SPACEMODE))
				{
					success_8 = false;
					_7 = use(begin_2);
					if (!(_7.status))
					{
						success_11 = false;
						_10 = Rule(begin_2);
						if (!(_10.status))
						{
							success_14 = false;
							if (!(begin_2->name() == ::Parser::Tokens::NAME))
							{
								break;
							}
							else 
							{
								_13 = *begin_2;
								success_14 = true;
								begin_2 += 1;
								shadow_15.push_back(_13);
								_2.push_back(_13);
							}
						}
						else 
						{
							success_11 = true;
							begin_2 += _10.node.length();
							shadow_12.push_back(_10.node);
							_2.push_back(_10.node);
						}
					}
					else 
					{
						success_8 = true;
						begin_2 += _7.node.length();
						shadow_9.push_back(_7.node);
						_2.push_back(_7.node);
					}
				}
				else 
				{
					_4 = *begin_2;
					success_5 = true;
					begin_2 += 1;
					shadow_6.push_back(_4);
					_2.push_back(_4);
				}
				success_3 = true;
				shadow_16.push_back(_0);
				success_17 = true;
			}
			if (!success_17)
			{
				reportError(pos, "spacemode or use or rule or name");
				return {};
			}
			if (success_3)
			{
				success_1 = true;
				pos = begin_2;
			}
			::Parser::Types::main_data data = _2;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::main, data)};
		}
		template <class IT>
		::Parser::Rule_res use_unit(IT pos) {
			auto in = pos;
			skip_spaces(pos);
;
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Rule_res _2;
			::Parser::bool_t success_3 = false;
			success_3 = false;
			success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::ID))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			_2 = any_data(pos);
			if (_2.status)
			{
				success_3 = true;
				pos += _2.node.length();
			}
			::Parser::Types::use_unit_data data;
			data.value = _2.node;
			data.name = _0;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::use_unit, data)};
		}
		template <class IT>
		::Parser::Rule_res use(IT pos) {
			auto in = pos;
			skip_spaces(pos);
;
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
			success_7 = false;
			success_10 = false;
			success_5 = false;
			success_3 = false;
			success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_0))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			_2 = use_unit(pos);
			if (!(_2.status))
			{
				reportError(pos, "unit");
				return {};
			}
			success_3 = true;
			pos += _2.node.length();
			skip_spaces(pos);
			auto begin_6 = pos;
			while (1)
			{
				if (!(begin_6->name() == ::Parser::Tokens::AUTO_1))
				{
					reportError(pos, "auto_1");
					break;
				}
				_6 = *begin_6;
				success_7 = true;
				begin_6 += 1;
				shadow_8.push_back(_6);
				skip_spaces(begin_6);
				_9 = use_unit(begin_6);
				if (!(_9.status))
				{
					reportError(pos, "unit");
					break;
				}
				success_10 = true;
				begin_6 += _9.node.length();
				shadow_11.push_back(_9.node);
			}
			if (success_7 && success_10)
			{
				success_5 = true;
				pos = begin_6;
			}
			::Parser::Types::use_data data;
			data.second = shadow_11;
			data.first = _2.node;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::use, data)};
		}
		template <class IT>
		::Parser::Rule_res array(IT pos) {
			auto in = pos;
			skip_spaces(pos);
;
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
			::Parser::Token _12;
			::Parser::bool_t success_13 = false;
			success_13 = false;
			success_3 = false;
			success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_2))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			auto begin_4 = pos;
			do
			{
				success_7 = false;
				success_10 = false;
				success_5 = false;
				auto begin_6 = begin_4;
				while (1)
				{
					_6 = any_data(begin_6);
					if (!(_6.status))
					{
						reportError(pos, "any_data");
						break;
					}
					success_7 = true;
					begin_6 += _6.node.length();
					shadow_8.push_back(_6.node);
					skip_spaces(begin_6);
					if (!(begin_6->name() == ::Parser::Tokens::AUTO_1))
					{
						reportError(pos, "auto_1");
						break;
					}
					_9 = *begin_6;
					success_10 = true;
					begin_6 += 1;
					shadow_11.push_back(_9);
				}
				if (success_7 && success_10)
				{
					success_5 = true;
					begin_4 = begin_6;
				}
			}
			while(0);
			success_3 = true;
			pos = begin_4;
			skip_spaces(pos);
			if (!(pos->name() == ::Parser::Tokens::AUTO_3))
			{
				reportError(pos, "auto_3");
				return {};
			}
			_12 = *pos;
			success_13 = true;
			pos += 1;
			::Parser::Types::array_data data = shadow_8;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::array, data)};
		}
		template <class IT>
		::Parser::Rule_res object(IT pos) {
			auto in = pos;
			skip_spaces(pos);
;
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::bool_t success_3 = false;
			::Parser::bool_t success_25 = false;
			::Parser::bool_t success_9 = false;
			::Parser::bool_t success_7 = false;
			::Parser::bool_t success_5 = false;
			::Parser::Rule_res _4;
			::Parser::Token _6;
			::Parser::Rule_res _8;
			::Parser::bool_t success_11 = false;
			::Parser::bool_t success_22 = false;
			::Parser::bool_t success_19 = false;
			::Parser::bool_t success_16 = false;
			::Parser::bool_t success_13 = false;
			::Parser::Token _12;
			::Parser::arr_t<::Parser::Token> shadow_14;
			::Parser::Token _15;
			::Parser::arr_t<::Parser::Token> shadow_17;
			::Parser::Token _18;
			::Parser::arr_t<::Parser::Token> shadow_20;
			::Parser::Rule_res _21;
			::Parser::arr_t<::Parser::Rule> shadow_23;
			::Parser::Token _24;
			::Parser::Token _26;
			::Parser::bool_t success_27 = false;
			success_27 = false;
			success_5 = false;
			success_7 = false;
			success_9 = false;
			success_25 = false;
			success_3 = false;
			success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_4))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			auto begin_4 = pos;
			do
			{
				success_13 = false;
				success_16 = false;
				success_19 = false;
				success_22 = false;
				success_11 = false;
				_4 = any_data(begin_4);
				if (!(_4.status))
				{
					reportError(pos, "any_data");
					break;
				}
				success_5 = true;
				begin_4 += _4.node.length();
				skip_spaces(begin_4);
				if (!(begin_4->name() == ::Parser::Tokens::AUTO_5))
				{
					reportError(pos, "auto_5");
					break;
				}
				_6 = *begin_4;
				success_7 = true;
				begin_4 += 1;
				skip_spaces(begin_4);
				_8 = any_data(begin_4);
				if (!(_8.status))
				{
					reportError(pos, "any_data");
					break;
				}
				success_9 = true;
				begin_4 += _8.node.length();
				skip_spaces(begin_4);
				auto begin_12 = begin_4;
				while (1)
				{
					if (!(begin_12->name() == ::Parser::Tokens::AUTO_1))
					{
						reportError(pos, "auto_1");
						break;
					}
					_12 = *begin_12;
					success_13 = true;
					begin_12 += 1;
					shadow_14.push_back(_12);
					skip_spaces(begin_12);
					if (!(begin_12->name() == ::Parser::Tokens::ID))
					{
						reportError(pos, "id");
						break;
					}
					_15 = *begin_12;
					success_16 = true;
					begin_12 += 1;
					shadow_17.push_back(_15);
					skip_spaces(begin_12);
					if (!(begin_12->name() == ::Parser::Tokens::AUTO_5))
					{
						reportError(pos, "auto_5");
						break;
					}
					_18 = *begin_12;
					success_19 = true;
					begin_12 += 1;
					shadow_20.push_back(_18);
					skip_spaces(begin_12);
					_21 = any_data(begin_12);
					if (!(_21.status))
					{
						reportError(pos, "any_data");
						break;
					}
					success_22 = true;
					begin_12 += _21.node.length();
					shadow_23.push_back(_21.node);
				}
				if (success_13 && success_16 && success_19 && success_22)
				{
					success_11 = true;
					begin_4 = begin_12;
				}
				skip_spaces(begin_4);
				if (!(begin_4->name() == ::Parser::Tokens::AUTO_6))
				{
					reportError(pos, "auto_6");
					break;
				}
				_24 = *begin_4;
				success_25 = true;
				begin_4 += 1;
			}
			while(0);
			if (success_5 && success_7 && success_9 && success_25)
			{
				success_3 = true;
				pos = begin_4;
			}
			skip_spaces(pos);
			if (!(pos->name() == ::Parser::Tokens::AUTO_7))
			{
				reportError(pos, "auto_7");
				return {};
			}
			_26 = *pos;
			success_27 = true;
			pos += 1;
			::Parser::Types::object_data data;
			data.values = shadow_20;
			data.keys = shadow_14;
			data.value = _8.node;
			data.key = _4.node;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::object, data)};
		}
		template <class IT>
		::Parser::Rule_res any_data(IT pos) {
			auto in = pos;
			skip_spaces(pos);
;
			::Parser::any_t _0;
			::Parser::bool_t success_1 = false;
			::Parser::Token _2;
			::Parser::bool_t success_3 = false;
			::Parser::Token _4;
			::Parser::bool_t success_5 = false;
			::Parser::Token _6;
			::Parser::bool_t success_7 = false;
			::Parser::Token _8;
			::Parser::bool_t success_9 = false;
			::Parser::Rule_res _10;
			::Parser::bool_t success_11 = false;
			::Parser::Rule_res _12;
			::Parser::bool_t success_13 = false;
			::Parser::Token _14;
			::Parser::bool_t success_15 = false;
			success_3 = false;
			success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::BOOLEAN))
			{
				success_5 = false;
				if (!(pos->name() == ::Parser::Tokens::STRING))
				{
					success_7 = false;
					if (!(pos->name() == ::Parser::Tokens::NUMBER))
					{
						success_9 = false;
						if (!(pos->name() == ::Parser::Tokens::ID))
						{
							success_11 = false;
							_10 = object(pos);
							if (!(_10.status))
							{
								success_13 = false;
								_12 = array(pos);
								if (!(_12.status))
								{
									success_15 = false;
									if (!(pos->name() == ::Parser::Tokens::AT))
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
									success_13 = true;
									pos += _12.node.length();
									_0 = _12.node;
								}
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
							_8 = *pos;
							success_9 = true;
							pos += 1;
							_0 = _8;
						}
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
			::Parser::Types::any_data_data data = _0;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::any_data, data)};
		}
		template <class IT>
		::Parser::Rule_res cll_if(IT pos) {
			auto in = pos;
			skip_spaces(pos);
;
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Rule_res _2;
			::Parser::bool_t success_3 = false;
			::Parser::Rule_res _4;
			::Parser::bool_t success_5 = false;
			success_5 = false;
			success_3 = false;
			success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_9))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			_2 = cll_expr(pos);
			if (!(_2.status))
			{
				reportError(pos, "expr");
				return {};
			}
			success_3 = true;
			pos += _2.node.length();
			skip_spaces(pos);
			_4 = cll_block(pos);
			if (!(_4.status))
			{
				reportError(pos, "block");
				return {};
			}
			success_5 = true;
			pos += _4.node.length();
			::Parser::Types::cll_if_data data;
			data.block = _4.node;
			data.expr = _2.node;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_if, data)};
		}
		template <class IT>
		::Parser::Rule_res cll_variable(IT pos) {
			auto in = pos;
			skip_spaces(pos);
;
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::bool_t success_3 = false;
			::Parser::Token _2;
			::Parser::Token _4;
			::Parser::bool_t success_5 = false;
			::Parser::Token _6;
			::Parser::bool_t success_7 = false;
			::Parser::Token _8;
			::Parser::bool_t success_9 = false;
			::Parser::bool_t success_11 = false;
			::Parser::bool_t success_17 = false;
			::Parser::bool_t success_15 = false;
			::Parser::bool_t success_13 = false;
			::Parser::Token _12;
			::Parser::Rule_res _14;
			::Parser::Token _16;
			::Parser::Token _18;
			::Parser::bool_t success_19 = false;
			::Parser::bool_t success_21 = false;
			::Parser::Token _20;
			::Parser::Token _22;
			::Parser::bool_t success_23 = false;
			::Parser::Token _24;
			::Parser::bool_t success_25 = false;
			success_21 = false;
			success_19 = false;
			success_13 = false;
			success_15 = false;
			success_17 = false;
			success_11 = false;
			success_9 = false;
			success_3 = false;
			success_1 = false;
			auto begin_2 = pos;
			do
			{
				success_5 = false;
				if (!(begin_2->name() == ::Parser::Tokens::AUTO_10))
				{
					success_7 = false;
					if (!(begin_2->name() == ::Parser::Tokens::AUTO_11))
					{
						break;
					}
					else 
					{
						_6 = *begin_2;
						success_7 = true;
						begin_2 += 1;
						_2 = _6;
					}
				}
				else 
				{
					_4 = *begin_2;
					success_5 = true;
					begin_2 += 1;
					_2 = _4;
				}
				success_3 = true;
				_0 = _2;
			}
			while(0);
			if (success_3)
			{
				success_1 = true;
				pos = begin_2;
			}
			skip_spaces(pos);
			if (!(pos->name() == ::Parser::Tokens::ID))
			{
				reportError(pos, "id");
				return {};
			}
			_8 = *pos;
			success_9 = true;
			pos += 1;
			skip_spaces(pos);
			auto begin_12 = pos;
			do
			{
				if (!(begin_12->name() == ::Parser::Tokens::AUTO_2))
				{
					reportError(pos, "auto_2");
					break;
				}
				_12 = *begin_12;
				success_13 = true;
				begin_12 += 1;
				skip_spaces(begin_12);
				_14 = cll_expr(begin_12);
				if (!(_14.status))
				{
					reportError(pos, "expr");
					break;
				}
				success_15 = true;
				begin_12 += _14.node.length();
				skip_spaces(begin_12);
				if (!(begin_12->name() == ::Parser::Tokens::AUTO_3))
				{
					reportError(pos, "auto_3");
					break;
				}
				_16 = *begin_12;
				success_17 = true;
				begin_12 += 1;
			}
			while(0);
			if (success_13 && success_15 && success_17)
			{
				success_11 = true;
				pos = begin_12;
			}
			skip_spaces(pos);
			auto begin_20 = pos;
			do
			{
				success_23 = false;
				if (!(begin_20->name() == ::Parser::Tokens::AUTO_10))
				{
					success_25 = false;
					if (!(begin_20->name() == ::Parser::Tokens::AUTO_11))
					{
						break;
					}
					else 
					{
						_24 = *begin_20;
						success_25 = true;
						begin_20 += 1;
						_20 = _24;
					}
				}
				else 
				{
					_22 = *begin_20;
					success_23 = true;
					begin_20 += 1;
					_20 = _22;
				}
				success_21 = true;
				_18 = _20;
			}
			while(0);
			if (success_21)
			{
				success_19 = true;
				pos = begin_20;
			}
			::Parser::Types::cll_variable_data data;
			data.post = _18;
			data.pre = _0;
			data.brace_expression = _14.node;
			data.name = _0;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_variable, data)};
		}
		template <class IT>
		::Parser::Rule_res cll_function_body_call(IT pos) {
			auto in = pos;
			skip_spaces(pos);
;
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Rule_res _2;
			::Parser::bool_t success_3 = false;
			::Parser::Token _4;
			::Parser::bool_t success_5 = false;
			success_5 = false;
			success_3 = false;
			success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_12))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			_2 = cll_function_arguments(pos);
			if (!(_2.status))
			{
				reportError(pos, "function_arguments");
				return {};
			}
			success_3 = true;
			pos += _2.node.length();
			skip_spaces(pos);
			if (!(pos->name() == ::Parser::Tokens::AUTO_13))
			{
				reportError(pos, "auto_13");
				return {};
			}
			_4 = *pos;
			success_5 = true;
			pos += 1;
			::Parser::Types::cll_function_body_call_data data = _2.node;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_function_body_call, data)};
		}
		template <class IT>
		::Parser::Rule_res cll_function_body_decl(IT pos) {
			auto in = pos;
			skip_spaces(pos);
;
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Rule_res _2;
			::Parser::bool_t success_3 = false;
			::Parser::Token _4;
			::Parser::bool_t success_5 = false;
			success_5 = false;
			success_3 = false;
			success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_12))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			_2 = cll_function_parameters(pos);
			if (!(_2.status))
			{
				reportError(pos, "function_parameters");
				return {};
			}
			success_3 = true;
			pos += _2.node.length();
			skip_spaces(pos);
			if (!(pos->name() == ::Parser::Tokens::AUTO_13))
			{
				reportError(pos, "auto_13");
				return {};
			}
			_4 = *pos;
			success_5 = true;
			pos += 1;
			::Parser::Types::cll_function_body_decl_data data = _2.node;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_function_body_decl, data)};
		}
		template <class IT>
		::Parser::Rule_res cll_function_arguments(IT pos) {
			auto in = pos;
			skip_spaces(pos);
;
			::Parser::bool_t success_1 = false;
			::Parser::bool_t success_3 = false;
			::Parser::any_t _2;
			::Parser::Rule_res _4;
			::Parser::bool_t success_5 = false;
			::Parser::Token _6;
			::Parser::bool_t success_7 = false;
			::Parser::arr_t<::Parser::Token> _8;
			::Parser::bool_t success_9 = false;
			::Parser::bool_t success_11 = false;
			::Parser::arr_t<::Parser::Token> _10;
			::Parser::Token _12;
			::Parser::bool_t success_13 = false;
			::Parser::arr_t<::Parser::Token> shadow_14;
			::Parser::arr_t<::Parser::arr_t<::Parser::Token>> shadow_15;
			success_11 = false;
			success_9 = false;
			success_5 = false;
			success_3 = false;
			success_1 = false;
			auto begin_2 = pos;
			_4 = any_data(begin_2);
			if (!(_4.status))
			{
				success_7 = false;
				if (!(begin_2->name() == ::Parser::Tokens::ID))
				{
					return {};
				}
				else 
				{
					_6 = *begin_2;
					success_7 = true;
					begin_2 += 1;
					_2 = _6;
				}
			}
			else 
			{
				success_5 = true;
				begin_2 += _4.node.length();
				_2 = _4.node;
			}
			success_3 = true;
			skip_spaces(begin_2);
			auto begin_10 = begin_2;
			while (1)
			{
				success_13 = false;
				if (!(begin_10->name() == ::Parser::Tokens::AUTO_1))
				{
					break;
				}
				else 
				{
					_12 = *begin_10;
					success_13 = true;
					begin_10 += 1;
					shadow_14.push_back(_12);
					_10.push_back(_12);
				}
				success_11 = true;
				_8 = _10;
				shadow_15.push_back(_8);
			}
			if (success_11)
			{
				success_9 = true;
				begin_2 = begin_10;
			}
			if (success_3)
			{
				success_1 = true;
				pos = begin_2;
			}
			::Parser::Types::cll_function_arguments_data data;
			data.second = shadow_15;
			data.first = _2;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_function_arguments, data)};
		}
		template <class IT>
		::Parser::Rule_res cll_function_parameters(IT pos) {
			auto in = pos;
			skip_spaces(pos);
;
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
			success_7 = false;
			success_10 = false;
			success_5 = false;
			success_3 = false;
			success_1 = false;
			auto begin_2 = pos;
			if (!(begin_2->name() == ::Parser::Tokens::ID))
			{
				return {};
			}
			_2 = *begin_2;
			success_3 = true;
			begin_2 += 1;
			skip_spaces(begin_2);
			auto begin_6 = begin_2;
			while (1)
			{
				if (!(begin_6->name() == ::Parser::Tokens::AUTO_1))
				{
					reportError(pos, "auto_1");
					break;
				}
				_6 = *begin_6;
				success_7 = true;
				begin_6 += 1;
				shadow_8.push_back(_6);
				skip_spaces(begin_6);
				if (!(begin_6->name() == ::Parser::Tokens::ID))
				{
					reportError(pos, "id");
					break;
				}
				_9 = *begin_6;
				success_10 = true;
				begin_6 += 1;
				shadow_11.push_back(_9);
			}
			if (success_7 && success_10)
			{
				success_5 = true;
				begin_2 = begin_6;
			}
			if (success_3)
			{
				success_1 = true;
				pos = begin_2;
			}
			::Parser::Types::cll_function_parameters_data data;
			data.second = shadow_11;
			data.first = _2;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_function_parameters, data)};
		}
		template <class IT>
		::Parser::Rule_res cll_cll_function_call(IT pos) {
			auto in = pos;
			skip_spaces(pos);
;
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Rule_res _2;
			::Parser::bool_t success_3 = false;
			success_3 = false;
			success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::ID))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			_2 = cll_function_body_call(pos);
			if (!(_2.status))
			{
				reportError(pos, "function_body_call");
				return {};
			}
			success_3 = true;
			pos += _2.node.length();
			::Parser::Types::cll_cll_function_call_data data;
			data.body = _2.node;
			data.name = _0;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_cll_function_call, data)};
		}
		template <class IT>
		::Parser::Rule_res cll_function_decl(IT pos) {
			auto in = pos;
			skip_spaces(pos);
;
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Token _2;
			::Parser::bool_t success_3 = false;
			::Parser::bool_t success_5 = false;
			::Parser::Token _4;
			::Parser::arr_t<::Parser::Token> shadow_6;
			::Parser::bool_t success_7 = false;
			::Parser::Rule_res _8;
			::Parser::bool_t success_9 = false;
			::Parser::Rule _10;
			::Parser::Rule val;
			::Parser::bool_t success_11 = false;
			::Parser::bool_t success_13 = false;
			::Parser::Rule_res _12;
			success_13 = false;
			success_11 = false;
			success_9 = false;
			success_7 = false;
			success_5 = false;
			success_3 = false;
			success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_14))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			auto begin_4 = pos;
			while (begin_4->name() == ::Parser::Tokens::ID)
			{
				_4 = *begin_4;
				success_5 = true;
				begin_4 += 1;
				shadow_6.push_back(_4);
				success_7 = true;
			}
			if (!success_7)
			{
				reportError(pos, "id");
				return {};
			}
			_2 = _4;
			if (success_5)
			{
				success_3 = true;
				pos = begin_4;
			}
			skip_spaces(pos);
			_8 = cll_function_body_decl(pos);
			if (!(_8.status))
			{
				reportError(pos, "function_body_decl");
				return {};
			}
			success_9 = true;
			pos += _8.node.length();
			skip_spaces(pos);
			auto begin_12 = pos;
			do
			{
				_12 = cll_block(begin_12);
				if (!(_12.status))
				{
					reportError(pos, "block");
					break;
				}
				success_13 = true;
				begin_12 += _12.node.length();
				_10 = _12.node;
			}
			while(0);
			if (success_13)
			{
				success_11 = true;
				val = _10;
				pos = begin_12;
			}
			::Parser::Types::cll_function_decl_data data;
			data.value = val;
			data.name = _2;
			data.type = shadow_6;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_function_decl, data)};
		}
		template <class IT>
		::Parser::Rule_res cll_expr_logical(IT pos) {
			auto in = pos;
			skip_spaces(pos);
;
			::Parser::Rule_res _0;
			::Parser::bool_t success_1 = false;
			::Parser::bool_t success_3 = false;
			::Parser::bool_t success_8 = false;
			::Parser::bool_t success_5 = false;
			::Parser::Token _4;
			::Parser::arr_t<::Parser::Token> shadow_6;
			::Parser::Rule_res _7;
			::Parser::arr_t<::Parser::Rule> shadow_9;
			success_5 = false;
			success_8 = false;
			success_3 = false;
			success_1 = false;
			_0 = cll_expr_compare(pos);
			if (!(_0.status))
			{
				return {};
			}
			success_1 = true;
			pos += _0.node.length();
			skip_spaces(pos);
			auto begin_4 = pos;
			while (1)
			{
				if (!(begin_4->name() == ::Parser::Tokens::cll_LOGICAL_OP))
				{
					reportError(pos, "logical_op");
					break;
				}
				_4 = *begin_4;
				success_5 = true;
				begin_4 += 1;
				shadow_6.push_back(_4);
				skip_spaces(begin_4);
				_7 = cll_expr_compare(begin_4);
				if (!(_7.status))
				{
					reportError(pos, "compare");
					break;
				}
				success_8 = true;
				begin_4 += _7.node.length();
				shadow_9.push_back(_7.node);
			}
			if (success_5 && success_8)
			{
				success_3 = true;
				pos = begin_4;
			}
			::Parser::Types::cll_expr_logical_data data;
			data.right = shadow_9;
			data.op = shadow_6;
			data.left = _0.node;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_expr_logical, data)};
		}
		template <class IT>
		::Parser::Rule_res cll_expr_compare(IT pos) {
			auto in = pos;
			skip_spaces(pos);
;
			::Parser::Rule_res _0;
			::Parser::bool_t success_1 = false;
			::Parser::bool_t success_3 = false;
			::Parser::bool_t success_8 = false;
			::Parser::bool_t success_5 = false;
			::Parser::Token _4;
			::Parser::arr_t<::Parser::Token> shadow_6;
			::Parser::Rule_res _7;
			::Parser::arr_t<::Parser::Rule> shadow_9;
			success_5 = false;
			success_8 = false;
			success_3 = false;
			success_1 = false;
			_0 = cll_expr_arithmetic(pos);
			if (!(_0.status))
			{
				return {};
			}
			success_1 = true;
			pos += _0.node.length();
			skip_spaces(pos);
			auto begin_4 = pos;
			while (1)
			{
				if (!(begin_4->name() == ::Parser::Tokens::cll_COMPARE_OP))
				{
					reportError(pos, "compare_op");
					break;
				}
				_4 = *begin_4;
				success_5 = true;
				begin_4 += 1;
				shadow_6.push_back(_4);
				skip_spaces(begin_4);
				_7 = cll_expr_arithmetic(begin_4);
				if (!(_7.status))
				{
					reportError(pos, "arithmetic");
					break;
				}
				success_8 = true;
				begin_4 += _7.node.length();
				shadow_9.push_back(_7.node);
			}
			if (success_5 && success_8)
			{
				success_3 = true;
				pos = begin_4;
			}
			::Parser::Types::cll_expr_compare_data data;
			data.sequence = shadow_9;
			data.operators = shadow_6;
			data.first = _0.node;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_expr_compare, data)};
		}
		template <class IT>
		::Parser::Rule_res cll_expr_arithmetic(IT pos) {
			auto in = pos;
			skip_spaces(pos);
;
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
			success_5 = false;
			success_13 = false;
			success_3 = false;
			success_1 = false;
			_0 = cll_expr_term(pos);
			if (!(_0.status))
			{
				return {};
			}
			success_1 = true;
			pos += _0.node.length();
			skip_spaces(pos);
			auto begin_4 = pos;
			while (1)
			{
				success_7 = false;
				if (!(begin_4->name() == ::Parser::Tokens::MINUS))
				{
					success_10 = false;
					if (!(begin_4->name() == ::Parser::Tokens::PLUS))
					{
						break;
					}
					else 
					{
						_9 = *begin_4;
						success_10 = true;
						begin_4 += 1;
						shadow_11.push_back(_9);
						_4.push_back(_9);
					}
				}
				else 
				{
					_6 = *begin_4;
					success_7 = true;
					begin_4 += 1;
					shadow_8.push_back(_6);
					_4.push_back(_6);
				}
				success_5 = true;
				skip_spaces(begin_4);
				_12 = cll_expr_term(begin_4);
				if (!(_12.status))
				{
					reportError(pos, "term");
					break;
				}
				success_13 = true;
				begin_4 += _12.node.length();
				shadow_14.push_back(_12.node);
			}
			if (success_5 && success_13)
			{
				success_3 = true;
				pos = begin_4;
			}
			::Parser::Types::cll_expr_arithmetic_data data;
			data.sequence = shadow_14;
			data.operators = _4;
			data.first = _0.node;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_expr_arithmetic, data)};
		}
		template <class IT>
		::Parser::Rule_res cll_expr_term(IT pos) {
			auto in = pos;
			skip_spaces(pos);
;
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
			success_5 = false;
			success_16 = false;
			success_3 = false;
			success_1 = false;
			_0 = cll_expr_value(pos);
			if (!(_0.status))
			{
				return {};
			}
			success_1 = true;
			pos += _0.node.length();
			skip_spaces(pos);
			auto begin_4 = pos;
			while (1)
			{
				success_7 = false;
				if (!(begin_4->name() == ::Parser::Tokens::DIVIDE))
				{
					success_10 = false;
					if (!(begin_4->name() == ::Parser::Tokens::MULTIPLE))
					{
						success_13 = false;
						if (!(begin_4->name() == ::Parser::Tokens::MODULO))
						{
							break;
						}
						else 
						{
							_12 = *begin_4;
							success_13 = true;
							begin_4 += 1;
							shadow_14.push_back(_12);
							_4.push_back(_12);
						}
					}
					else 
					{
						_9 = *begin_4;
						success_10 = true;
						begin_4 += 1;
						shadow_11.push_back(_9);
						_4.push_back(_9);
					}
				}
				else 
				{
					_6 = *begin_4;
					success_7 = true;
					begin_4 += 1;
					shadow_8.push_back(_6);
					_4.push_back(_6);
				}
				success_5 = true;
				skip_spaces(begin_4);
				_15 = cll_expr_value(begin_4);
				if (!(_15.status))
				{
					reportError(pos, "value");
					break;
				}
				success_16 = true;
				begin_4 += _15.node.length();
				shadow_17.push_back(_15.node);
			}
			if (success_5 && success_16)
			{
				success_3 = true;
				pos = begin_4;
			}
			::Parser::Types::cll_expr_term_data data;
			data.sequence = shadow_17;
			data.operators = _4;
			data.first = _0.node;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_expr_term, data)};
		}
		template <class IT>
		::Parser::Rule_res cll_expr_value(IT pos) {
			auto in = pos;
			skip_spaces(pos);
;
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
			success_3 = false;
			success_1 = false;
			_2 = cll_variable(pos);
			if (!(_2.status))
			{
				success_5 = false;
				_4 = cll_expr_group(pos);
				if (!(_4.status))
				{
					success_7 = false;
					_6 = cll_cll_function_call(pos);
					if (!(_6.status))
					{
						success_9 = false;
						_8 = any_data(pos);
						if (!(_8.status))
						{
							return {};
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
			::Parser::Types::cll_expr_value_data data = _0;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_expr_value, data)};
		}
		template <class IT>
		::Parser::Rule_res cll_expr_group(IT pos) {
			auto in = pos;
			skip_spaces(pos);
;
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Rule_res _2;
			::Parser::bool_t success_3 = false;
			::Parser::Token _4;
			::Parser::bool_t success_5 = false;
			success_5 = false;
			success_3 = false;
			success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_12))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			_2 = cll_expr(pos);
			if (!(_2.status))
			{
				reportError(pos, "expr");
				return {};
			}
			success_3 = true;
			pos += _2.node.length();
			skip_spaces(pos);
			if (!(pos->name() == ::Parser::Tokens::AUTO_13))
			{
				reportError(pos, "auto_13");
				return {};
			}
			_4 = *pos;
			success_5 = true;
			pos += 1;
			::Parser::Types::cll_expr_group_data data = _2.node;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_expr_group, data)};
		}
		template <class IT>
		::Parser::Rule_res cll_expr(IT pos) {
			auto in = pos;
			skip_spaces(pos);
;
			::Parser::Rule _0;
			::Parser::bool_t success_1 = false;
			::Parser::Rule_res _2;
			::Parser::bool_t success_3 = false;
			::Parser::Rule_res _4;
			::Parser::bool_t success_5 = false;
			success_3 = false;
			success_1 = false;
			_2 = cll_expr_logical(pos);
			if (!(_2.status))
			{
				success_5 = false;
				_4 = cll_expr_compare(pos);
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
			::Parser::Types::cll_expr_data data = _0;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_expr, data)};
		}
		template <class IT>
		::Parser::Rule_res cll_var(IT pos) {
			auto in = pos;
			skip_spaces(pos);
;
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Token _2;
			::Parser::bool_t success_3 = false;
			::Parser::bool_t success_5 = false;
			::Parser::bool_t success_9 = false;
			::Parser::bool_t success_7 = false;
			::Parser::Token _6;
			::Parser::Rule_res _8;
			success_7 = false;
			success_9 = false;
			success_5 = false;
			success_3 = false;
			success_1 = false;
			if (pos->name() == ::Parser::Tokens::cll_TYPE)
			{
				_0 = *pos;
				success_1 = true;
				pos += 1;
			}
			skip_spaces(pos);
			if (!(pos->name() == ::Parser::Tokens::ID))
			{
				reportError(pos, "id");
				return {};
			}
			_2 = *pos;
			success_3 = true;
			pos += 1;
			skip_spaces(pos);
			auto begin_6 = pos;
			do
			{
				if (!(begin_6->name() == ::Parser::Tokens::cll_ASSIGNMENT_OP))
				{
					reportError(pos, "assignment_op");
					break;
				}
				_6 = *begin_6;
				success_7 = true;
				begin_6 += 1;
				skip_spaces(begin_6);
				_8 = cll_expr(begin_6);
				if (!(_8.status))
				{
					reportError(pos, "expr");
					break;
				}
				success_9 = true;
				begin_6 += _8.node.length();
			}
			while(0);
			if (success_7 && success_9)
			{
				success_5 = true;
				pos = begin_6;
			}
			::Parser::Types::cll_var_data data;
			data.value = _8.node;
			data.op = _6;
			data.id = _2;
			data.type = _0;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_var, data)};
		}
		template <class IT>
		::Parser::Rule_res cll_block(IT pos) {
			auto in = pos;
			skip_spaces(pos);
;
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Rule_res _2;
			::Parser::bool_t success_3 = false;
			::Parser::arr_t<::Parser::Rule> shadow_4;
			::Parser::Token _5;
			::Parser::bool_t success_6 = false;
			success_6 = false;
			success_3 = false;
			success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_4))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			_2 = Rule_rule(pos);
			while (_2.status)
			{
				success_3 = true;
				pos += _2.node.length();
				shadow_4.push_back(_2.node);
				_2 = Rule_rule(pos);
			}
			skip_spaces(pos);
			if (!(pos->name() == ::Parser::Tokens::AUTO_7))
			{
				reportError(pos, "auto_7");
				return {};
			}
			_5 = *pos;
			success_6 = true;
			pos += 1;
			::Parser::Types::cll_block_data data = shadow_4;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_block, data)};
		}
		template <class IT>
		::Parser::Rule_res cll_loop_while(IT pos) {
			auto in = pos;
			skip_spaces(pos);
;
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Rule_res _2;
			::Parser::bool_t success_3 = false;
			::Parser::Rule_res _4;
			::Parser::bool_t success_5 = false;
			success_5 = false;
			success_3 = false;
			success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_15))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			_2 = cll_expr(pos);
			if (!(_2.status))
			{
				reportError(pos, "expr");
				return {};
			}
			success_3 = true;
			pos += _2.node.length();
			skip_spaces(pos);
			_4 = cll_block(pos);
			if (!(_4.status))
			{
				reportError(pos, "block");
				return {};
			}
			success_5 = true;
			pos += _4.node.length();
			::Parser::Types::cll_loop_while_data data;
			data.block = _4.node;
			data.expr = _2.node;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_loop_while, data)};
		}
		template <class IT>
		::Parser::Rule_res cll_loop_for(IT pos) {
			auto in = pos;
			skip_spaces(pos);
;
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
			::Parser::Token _12;
			::Parser::bool_t success_13 = false;
			::Parser::Rule_res _14;
			::Parser::bool_t success_15 = false;
			::Parser::Token _16;
			::Parser::bool_t success_17 = false;
			::Parser::Rule_res _18;
			::Parser::bool_t success_19 = false;
			::Parser::Token _20;
			::Parser::bool_t success_21 = false;
			::Parser::Rule_res _22;
			::Parser::bool_t success_23 = false;
			success_23 = false;
			success_21 = false;
			success_19 = false;
			success_17 = false;
			success_15 = false;
			success_13 = false;
			success_7 = false;
			success_5 = false;
			success_3 = false;
			success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_16))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			if (!(pos->name() == ::Parser::Tokens::AUTO_12))
			{
				reportError(pos, "auto_12");
				return {};
			}
			_2 = *pos;
			success_3 = true;
			pos += 1;
			skip_spaces(pos);
			auto begin_6 = pos;
			do
			{
				success_9 = false;
				_8 = cll_expr(begin_6);
				if (!(_8.status))
				{
					success_11 = false;
					_10 = cll_var(begin_6);
					if (!(_10.status))
					{
						break;
					}
					else 
					{
						success_11 = true;
						begin_6 += _10.node.length();
						_6 = _10.node;
					}
				}
				else 
				{
					success_9 = true;
					begin_6 += _8.node.length();
					_6 = _8.node;
				}
				success_7 = true;
				_4 = _6;
			}
			while(0);
			if (success_7)
			{
				success_5 = true;
				pos = begin_6;
			}
			skip_spaces(pos);
			if (!(pos->name() == ::Parser::Tokens::AUTO_6))
			{
				reportError(pos, "\";\"");
				return {};
			}
			_12 = *pos;
			success_13 = true;
			pos += 1;
			skip_spaces(pos);
			_14 = cll_expr(pos);
			if (_14.status)
			{
				success_15 = true;
				pos += _14.node.length();
			}
			skip_spaces(pos);
			if (!(pos->name() == ::Parser::Tokens::AUTO_6))
			{
				reportError(pos, "\";\"");
				return {};
			}
			_16 = *pos;
			success_17 = true;
			pos += 1;
			skip_spaces(pos);
			_18 = cll_expr(pos);
			if (_18.status)
			{
				success_19 = true;
				pos += _18.node.length();
			}
			skip_spaces(pos);
			if (!(pos->name() == ::Parser::Tokens::AUTO_13))
			{
				reportError(pos, "auto_13");
				return {};
			}
			_20 = *pos;
			success_21 = true;
			pos += 1;
			skip_spaces(pos);
			_22 = cll_block(pos);
			if (!(_22.status))
			{
				reportError(pos, "block");
				return {};
			}
			success_23 = true;
			pos += _22.node.length();
			::Parser::Types::cll_loop_for_data data;
			data.block = _20;
			data.end = _16;
			data.cond = _12;
			data.decl = _6;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_loop_for, data)};
		}
		template <class IT>
		::Parser::Rule_res cll(IT pos) {
			auto in = pos;
			skip_spaces(pos);
;
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
			success_15 = false;
			success_5 = false;
			success_3 = false;
			success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_8))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			_4 = cll_var(pos);
			if (!(_4.status))
			{
				success_7 = false;
				_6 = cll_loop_while(pos);
				if (!(_6.status))
				{
					success_9 = false;
					_8 = cll_loop_for(pos);
					if (!(_8.status))
					{
						success_11 = false;
						_10 = cll_if(pos);
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
			if (!(pos->name() == ::Parser::Tokens::END))
			{
				reportError(pos, "end");
				return {};
			}
			_14 = *pos;
			success_15 = true;
			pos += 1;
			::Parser::Types::cll_data data = _2;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll, data)};
		}
		template <class IT>
		::Parser::Rule_res Rule_rule(IT pos) {
			auto in = pos;
			skip_spaces(pos);
;
			::Parser::Rule _0;
			::Parser::Rule prefix;
			::Parser::bool_t success_1 = false;
			::Parser::bool_t success_3 = false;
			::Parser::Rule _2;
			::Parser::Rule_res _4;
			::Parser::bool_t success_5 = false;
			::Parser::Rule_res _6;
			::Parser::bool_t success_7 = false;
			::Parser::any_t _8;
			::Parser::any_t val;
			::Parser::bool_t success_9 = false;
			::Parser::bool_t success_11 = false;
			::Parser::any_t _10;
			::Parser::Token _12;
			::Parser::bool_t success_13 = false;
			::Parser::Token _14;
			::Parser::bool_t success_15 = false;
			::Parser::Token _16;
			::Parser::bool_t success_17 = false;
			::Parser::Token _18;
			::Parser::bool_t success_19 = false;
			::Parser::Token _20;
			::Parser::bool_t success_21 = false;
			::Parser::Token _22;
			::Parser::bool_t success_23 = false;
			::Parser::Token _24;
			::Parser::bool_t success_25 = false;
			::Parser::Token _26;
			::Parser::bool_t success_27 = false;
			::Parser::Rule_res _28;
			::Parser::bool_t success_29 = false;
			::Parser::Token _30;
			::Parser::bool_t success_31 = false;
			::Parser::Rule_res _32;
			::Parser::bool_t success_33 = false;
			::Parser::Rule_res _34;
			::Parser::bool_t success_35 = false;
			::Parser::Rule _36;
			::Parser::Rule quantifier;
			::Parser::bool_t success_37 = false;
			::Parser::Rule_res _38;
			::Parser::bool_t success_39 = false;
			success_39 = false;
			success_37 = false;
			success_13 = false;
			success_11 = false;
			success_9 = false;
			success_3 = false;
			success_1 = false;
			auto begin_2 = pos;
			do
			{
				success_5 = false;
				_4 = Rule_keyvalue(begin_2);
				if (!(_4.status))
				{
					success_7 = false;
					_6 = Rule_value(begin_2);
					if (!(_6.status))
					{
						break;
					}
					else 
					{
						success_7 = true;
						begin_2 += _6.node.length();
						_2 = _6.node;
					}
				}
				else 
				{
					success_5 = true;
					begin_2 += _4.node.length();
					_2 = _4.node;
				}
				success_3 = true;
				_0 = _2;
			}
			while(0);
			if (success_3)
			{
				success_1 = true;
				prefix = _0;
				pos = begin_2;
			}
			skip_spaces(pos);
			auto begin_10 = pos;
			if (!(begin_10->name() == ::Parser::Tokens::Rule_NOSPACE))
			{
				success_15 = false;
				if (!(begin_10->name() == ::Parser::Tokens::Rule_ESCAPED))
				{
					success_17 = false;
					if (!(begin_10->name() == ::Parser::Tokens::Rule_HEX))
					{
						success_19 = false;
						if (!(begin_10->name() == ::Parser::Tokens::Rule_BIN))
						{
							success_21 = false;
							if (!(begin_10->name() == ::Parser::Tokens::LINEAR_COMMENT))
							{
								success_23 = false;
								if (!(begin_10->name() == ::Parser::Tokens::Rule_OP))
								{
									success_25 = false;
									if (!(begin_10->name() == ::Parser::Tokens::Rule_CSEQUENCE))
									{
										success_27 = false;
										if (!(begin_10->name() == ::Parser::Tokens::AUTO_18))
										{
											success_29 = false;
											_28 = Rule_group(begin_10);
											if (!(_28.status))
											{
												success_31 = false;
												if (!(begin_10->name() == ::Parser::Tokens::STRING))
												{
													success_33 = false;
													_32 = cll(begin_10);
													if (!(_32.status))
													{
														success_35 = false;
														_34 = Rule_name(begin_10);
														if (!(_34.status))
														{
															return {};
														}
														else 
														{
															success_35 = true;
															begin_10 += _34.node.length();
															_10 = _34.node;
														}
													}
													else 
													{
														success_33 = true;
														begin_10 += _32.node.length();
														_10 = _32.node;
													}
												}
												else 
												{
													_30 = *begin_10;
													success_31 = true;
													begin_10 += 1;
													_10 = _30;
												}
											}
											else 
											{
												success_29 = true;
												begin_10 += _28.node.length();
												_10 = _28.node;
											}
										}
										else 
										{
											_26 = *begin_10;
											success_27 = true;
											begin_10 += 1;
											_10 = _26;
										}
									}
									else 
									{
										_24 = *begin_10;
										success_25 = true;
										begin_10 += 1;
										_10 = _24;
									}
								}
								else 
								{
									_22 = *begin_10;
									success_23 = true;
									begin_10 += 1;
									_10 = _22;
								}
							}
							else 
							{
								_20 = *begin_10;
								success_21 = true;
								begin_10 += 1;
								_10 = _20;
							}
						}
						else 
						{
							_18 = *begin_10;
							success_19 = true;
							begin_10 += 1;
							_10 = _18;
						}
					}
					else 
					{
						_16 = *begin_10;
						success_17 = true;
						begin_10 += 1;
						_10 = _16;
					}
				}
				else 
				{
					_14 = *begin_10;
					success_15 = true;
					begin_10 += 1;
					_10 = _14;
				}
			}
			else 
			{
				_12 = *begin_10;
				success_13 = true;
				begin_10 += 1;
				_10 = _12;
			}
			success_11 = true;
			if (success_11)
			{
				success_9 = true;
				val = _8;
				pos = begin_10;
			}
			skip_spaces(pos);
			auto begin_38 = pos;
			_38 = Rule_quantifier(begin_38);
			if (_38.status)
			{
				success_39 = true;
				begin_38 += _38.node.length();
			}
			_36 = _38.node;
			success_37 = true;
			success_37 = true;
			pos = begin_38;
			::Parser::Types::Rule_rule_data data;
			data.quantifier = quantifier;
			data.val = val;
			data.prefix = prefix;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::Rule_rule, data)};
		}
		template <class IT>
		::Parser::Rule_res Rule_name(IT pos) {
			auto in = pos;
			skip_spaces(pos);
;
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
			success_7 = false;
			success_10 = false;
			success_5 = false;
			success_3 = false;
			success_1 = false;
			if (pos->name() == ::Parser::Tokens::AUTO_17)
			{
				_0 = *pos;
				success_1 = true;
				pos += 1;
			}
			skip_spaces(pos);
			if (!(pos->name() == ::Parser::Tokens::ID))
			{
				reportError(pos, "id");
				return {};
			}
			_2 = *pos;
			success_3 = true;
			pos += 1;
			skip_spaces(pos);
			auto begin_6 = pos;
			while (1)
			{
				if (!(begin_6->name() == ::Parser::Tokens::AUTO_18))
				{
					reportError(pos, "auto_18");
					break;
				}
				_6 = *begin_6;
				success_7 = true;
				begin_6 += 1;
				shadow_8.push_back(_6);
				skip_spaces(begin_6);
				if (!(begin_6->name() == ::Parser::Tokens::ID))
				{
					reportError(pos, "id");
					break;
				}
				_9 = *begin_6;
				success_10 = true;
				begin_6 += 1;
				shadow_11.push_back(_9);
			}
			if (success_7 && success_10)
			{
				success_5 = true;
				pos = begin_6;
			}
			::Parser::Types::Rule_name_data data;
			data.nested_name = shadow_11;
			data.name = _2;
			data.is_nested = _0;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::Rule_name, data)};
		}
		template <class IT>
		::Parser::Rule_res Rule_group(IT pos) {
			auto in = pos;
			skip_spaces(pos);
;
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Rule_res _2;
			::Parser::bool_t success_3 = false;
			::Parser::arr_t<::Parser::Rule> shadow_4;
			::Parser::Token _5;
			::Parser::bool_t success_6 = false;
			success_6 = false;
			success_3 = false;
			success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_12))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			_2 = Rule_rule(pos);
			while (_2.status)
			{
				success_3 = true;
				pos += _2.node.length();
				shadow_4.push_back(_2.node);
				_2 = Rule_rule(pos);
			}
			skip_spaces(pos);
			if (!(pos->name() == ::Parser::Tokens::AUTO_13))
			{
				reportError(pos, "auto_13");
				return {};
			}
			_5 = *pos;
			success_6 = true;
			pos += 1;
			::Parser::Types::Rule_group_data data = shadow_4;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::Rule_group, data)};
		}
		template <class IT>
		::Parser::Rule_res Rule_keyvalue(IT pos) {
			auto in = pos;
			skip_spaces(pos);
;
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::bool_t success_3 = false;
			::Parser::bool_t success_5 = false;
			::Parser::Token _4;
			success_5 = false;
			success_3 = false;
			success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::AT))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			auto begin_4 = pos;
			do
			{
				if (!(begin_4->name() == ::Parser::Tokens::ID))
				{
					reportError(pos, "id");
					break;
				}
				_4 = *begin_4;
				success_5 = true;
				begin_4 += 1;
			}
			while(0);
			if (success_5)
			{
				success_3 = true;
				pos = begin_4;
			}
			::Parser::Types::Rule_keyvalue_data data = _4;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::Rule_keyvalue, data)};
		}
		template <class IT>
		::Parser::Rule_res Rule_value(IT pos) {
			auto in = pos;
			skip_spaces(pos);
;
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Token _2;
			::Parser::bool_t success_3 = false;
			success_3 = false;
			success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_19))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			if (!(pos->name() == ::Parser::Tokens::ID))
			{
				reportError(pos, "id");
				return {};
			}
			_2 = *pos;
			success_3 = true;
			pos += 1;
			::Parser::Types::Rule_value_data data = _2;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::Rule_value, data)};
		}
		template <class IT>
		::Parser::Rule_res Rule_nested_rule(IT pos) {
			auto in = pos;
			skip_spaces(pos);
;
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Rule_res _2;
			::Parser::bool_t success_3 = false;
			success_3 = false;
			success_1 = false;
			if (pos->name() == ::Parser::Tokens::AUTO_17)
			{
				_0 = *pos;
				success_1 = true;
				pos += 1;
			}
			_2 = Rule(pos);
			if (!(_2.status))
			{
				reportError(pos, "rule");
				return {};
			}
			success_3 = true;
			pos += _2.node.length();
			::Parser::Types::Rule_nested_rule_data data = _2.node;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::Rule_nested_rule, data)};
		}
		template <class IT>
		::Parser::Rule_res Rule_data_block_regular_datablock_key(IT pos) {
			auto in = pos;
			skip_spaces(pos);
;
			::Parser::Token _0;
			::Parser::Token name;
			::Parser::bool_t success_1 = false;
			::Parser::bool_t success_3 = false;
			::Parser::Token _2;
			::Parser::Token _4;
			::Parser::bool_t success_5 = false;
			::Parser::Rule _6;
			::Parser::Rule dt;
			::Parser::bool_t success_7 = false;
			::Parser::bool_t success_9 = false;
			::Parser::Rule_res _8;
			success_9 = false;
			success_7 = false;
			success_5 = false;
			success_3 = false;
			success_1 = false;
			auto begin_2 = pos;
			if (!(begin_2->name() == ::Parser::Tokens::ID))
			{
				return {};
			}
			_2 = *begin_2;
			success_3 = true;
			begin_2 += 1;
			_0 = _2;
			if (success_3)
			{
				success_1 = true;
				name = _0;
				pos = begin_2;
			}
			skip_spaces(pos);
			if (!(pos->name() == ::Parser::Tokens::AUTO_20))
			{
				reportError(pos, "auto_20");
				return {};
			}
			_4 = *pos;
			success_5 = true;
			pos += 1;
			skip_spaces(pos);
			auto begin_8 = pos;
			_8 = cll_expr(begin_8);
			if (!(_8.status))
			{
				reportError(pos, "cll");
				return {};
			}
			success_9 = true;
			begin_8 += _8.node.length();
			_6 = _8.node;
			if (success_9)
			{
				success_7 = true;
				dt = _6;
				pos = begin_8;
			}
			::Parser::Types::Rule_data_block_regular_datablock_key_data data;
			data.val = dt;
			data.name = name;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::Rule_data_block_regular_datablock_key, data)};
		}
		template <class IT>
		::Parser::Rule_res Rule_data_block_regular_datablock(IT pos) {
			auto in = pos;
			skip_spaces(pos);
		
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::any_t _2;
			::Parser::bool_t success_3 = false;
			::Parser::Rule_res _4;
			::Parser::bool_t success_5 = false;
			std::vector<::Parser::Rule> key_nodes;
			::Parser::bool_t success_7 = false;
			::Parser::Token _8;
			::Parser::bool_t success_9 = false;
		
			success_9 = false;
			success_5 = false;
			success_3 = false;
			success_1 = false;
		
			if (!(pos->name() == ::Parser::Tokens::AUTO_4)) {
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
		
			_4 = any_data(pos);
			if (!(_4.status)) {
				// Attempt one or more Rule_data_block_regular_datablock_key
				while (true) {
					auto save = pos;
					auto res = Rule_data_block_regular_datablock_key(pos);
					if (!res.status) {
						pos = save;
						break;
					}
					key_nodes.push_back(res.node);
					pos += res.node.length();
					skip_spaces(pos);
				}
		
				if (key_nodes.empty()) {
					return {};
				} else {
					success_7 = true;
					// If needed, merge the keys into a group or composite node
					_2 = key_nodes;
				}
			} else {
				success_5 = true;
				pos += _4.node.length();
				_2 = _4.node;
			}
		
			success_3 = true;
			skip_spaces(pos);
			if (!(pos->name() == ::Parser::Tokens::AUTO_7)) {
				reportError(pos, "auto_7");
				return {};
			}
			_8 = *pos;
			success_9 = true;
			pos += 1;
		
			::Parser::Types::Rule_data_block_regular_datablock_data data = _2;
			return {
				true,
				::Parser::Rule(
					in->startpos(),
					in->start(),
					pos->end(),
					pos - in,
					pos->line(),
					pos->column(),
					::Parser::Rules::Rule_data_block_regular_datablock,
					data
				)
			};
		}
		
		template <class IT>
		::Parser::Rule_res Rule_data_block_templated_datablock(IT pos) {
			auto in = pos;
			skip_spaces(pos);
;
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Token _2;
			::Parser::bool_t success_3 = false;
			::Parser::bool_t success_5 = false;
			::Parser::bool_t success_7 = false;
			::Parser::Token _6;
			::Parser::Token first_name;
			::Parser::bool_t success_9 = false;
			::Parser::Token _8;
			::Parser::bool_t success_11 = false;
			::Parser::bool_t success_16 = false;
			::Parser::bool_t success_13 = false;
			::Parser::Token _12;
			::Parser::arr_t<::Parser::Token> shadow_14;
			::Parser::Token _15;
			::Parser::arr_t<::Parser::Token> second_name;
			::Parser::bool_t success_18 = false;
			::Parser::Token _17;
			::Parser::arr_t<::Parser::Token> shadow_19;
			::Parser::arr_t<::Parser::Token> shadow_20;
			::Parser::Token _21;
			::Parser::bool_t success_22 = false;
			success_22 = false;
			success_7 = false;
			success_5 = false;
			success_3 = false;
			success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::AT))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			if (!(pos->name() == ::Parser::Tokens::AUTO_4))
			{
				reportError(pos, "auto_4");
				return {};
			}
			_2 = *pos;
			success_3 = true;
			pos += 1;
			skip_spaces(pos);
			auto begin_6 = pos;
			do
			{
				success_13 = false;
				success_16 = false;
				success_11 = false;
				success_9 = false;
				auto begin_8 = begin_6;
				if (!(begin_8->name() == ::Parser::Tokens::ID))
				{
					reportError(pos, "id");
					break;
				}
				_8 = *begin_8;
				success_9 = true;
				begin_8 += 1;
				_6 = _8;
				if (success_9)
				{
					success_7 = true;
					first_name = _6;
					begin_6 = begin_8;
				}
				skip_spaces(begin_6);
				auto begin_12 = begin_6;
				while (1)
				{
					success_18 = false;
					if (!(begin_12->name() == ::Parser::Tokens::AUTO_1))
					{
						reportError(pos, "auto_1");
						break;
					}
					_12 = *begin_12;
					success_13 = true;
					begin_12 += 1;
					shadow_14.push_back(_12);
					skip_spaces(begin_12);
					auto begin_17 = begin_12;
					if (!(begin_17->name() == ::Parser::Tokens::ID))
					{
						reportError(pos, "id");
						break;
					}
					_17 = *begin_17;
					success_18 = true;
					begin_17 += 1;
					shadow_19.push_back(_17);
					_15 = _17;
					shadow_20.push_back(_15);
					if (success_18)
					{
						success_16 = true;
						second_name = shadow_20;
						begin_12 = begin_17;
					}
				}
				if (success_13 && success_16)
				{
					success_11 = true;
					begin_6 = begin_12;
				}
			}
			while(0);
			if (success_7)
			{
				success_5 = true;
				pos = begin_6;
			}
			skip_spaces(pos);
			if (!(pos->name() == ::Parser::Tokens::AUTO_7))
			{
				reportError(pos, "auto_7");
				return {};
			}
			_21 = *pos;
			success_22 = true;
			pos += 1;
			::Parser::Types::Rule_data_block_templated_datablock_data data;
			data.second_name = second_name;
			data.first_name = first_name;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::Rule_data_block_templated_datablock, data)};
		}
		template <class IT>
		::Parser::Rule_res Rule_data_block(IT pos) {
			auto in = pos;
			skip_spaces(pos);
;
			::Parser::Rule _0;
			::Parser::bool_t success_1 = false;
			::Parser::Rule_res _2;
			::Parser::bool_t success_3 = false;
			::Parser::Rule_res _4;
			::Parser::bool_t success_5 = false;
			success_3 = false;
			success_1 = false;
			_2 = Rule_data_block_regular_datablock(pos);
			if (!(_2.status))
			{
				success_5 = false;
				_4 = Rule_data_block_templated_datablock(pos);
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
			::Parser::Types::Rule_data_block_data data = _0;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::Rule_data_block, data)};
		}
		template <class IT>
		::Parser::Rule_res Rule_quantifier(IT pos) {
			auto in = pos;
			skip_spaces(pos);
;
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Token _2;
			::Parser::bool_t success_3 = false;
			::Parser::Token _4;
			::Parser::bool_t success_5 = false;
			::Parser::Token _6;
			::Parser::bool_t success_7 = false;
			success_3 = false;
			success_1 = false;
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
			::Parser::Types::Rule_quantifier_data data = _0;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::Rule_quantifier, data)};
		}
		template <class IT>
		::Parser::Rule_res Rule(IT pos) {
			auto in = pos;
			skip_spaces(pos);
;
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
			success_14 = false;
			success_11 = false;
			success_9 = false;
			success_7 = false;
			success_5 = false;
			success_3 = false;
			success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::ID))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			if (!(pos->name() == ::Parser::Tokens::AUTO_5))
			{
				reportError(pos, "auto_5");
				return {};
			}
			_2 = *pos;
			success_3 = true;
			pos += 1;
			skip_spaces(pos);
			_4 = Rule_rule(pos);
			while (_4.status)
			{
				success_5 = true;
				pos += _4.node.length();
				shadow_6.push_back(_4.node);
				_4 = Rule_rule(pos);
				success_7 = true;
			}
			if (!success_7)
			{
				reportError(pos, "rule");
				return {};
			}
			skip_spaces(pos);
			_8 = Rule_data_block(pos);
			if (_8.status)
			{
				success_9 = true;
				pos += _8.node.length();
			}
			skip_spaces(pos);
			_10 = Rule_nested_rule(pos);
			while (_10.status)
			{
				success_11 = true;
				pos += _10.node.length();
				shadow_12.push_back(_10.node);
				_10 = Rule_nested_rule(pos);
			}
			skip_spaces(pos);
			if (!(pos->name() == ::Parser::Tokens::AUTO_6))
			{
				reportError(pos, "\";\"");
				return {};
			}
			_13 = *pos;
			success_14 = true;
			pos += 1;
			::Parser::Types::Rule_data data;
			data.nested_rules = shadow_12;
			data.data_block = _8.node;
			data.rule = shadow_6;
			data.name = _0;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::Rule, data)};
		}
	};

} // Parser


#endif // PARSER
