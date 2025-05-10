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
		NONE, __WHITESPACE, AUTO_24, AUTO_22, AUTO_21, AUTO_18, AUTO_13, AUTO_11, AUTO_7, AUTO_6, AUTO_17, cll_COMPARE_OP, AUTO_9, AUTO_5, AUTO_10, cll_ASSIGNMENT_OP, AUTO_19, cll_TEMPLATE, cll_LOGICAL_NOT, cll_LOGICAL_OP, cll_TYPE, AUTO_12, cll_LOGICAL_OR, cll_OP, rule_ESCAPED, STRING, NUMBER, AUTO_16, AUTO_4, BOOLEAN, AUTO_23, AUTO_8, rule_CSEQUENCE_ESCAPE, AUTO_3, AUTO_20, rule_HEX, rule_QUANTIFIER, rule_CSEQUENCE_SYMBOL, rule_OP, AUTO_15, rule_CSEQUENCE, cll_LOGICAL_AND, rule_CSEQUENCE_DIAPASON, rule_ANY, AUTO_14, rule_NOSPACE, rule_BIN, AUTO_2, AUTO_0, AUTO_1
	};
	enum class Rules {
		NONE, cll_loop_while, cll_method_call, cll_expr_group, cll_expr_logical, cll__var, cll_function_call, cll, cll_expr_compare, cll_expr_arithmetic, cll__if, cll_function_parameters, cll_function_arguments, cll_expr_term, cll_function_decl, cll__variable, cll_expr, cll_function_body_call, cll_stmt, rule, rule_value, rule_data_block, cll_function_body_decl, rule_name, rule_group, rule_keyvalue, cll_loop_for, rule_nested_rule, rule_data_block_regular_datablock, rule_data_block_regular_datablock_key, rule_data_block_templated_datablock, rule_rule, cll_expr_value
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
			case Tokens::AUTO_24: return "AUTO_24";
			case Tokens::AUTO_22: return "AUTO_22";
			case Tokens::AUTO_21: return "AUTO_21";
			case Tokens::AUTO_18: return "AUTO_18";
			case Tokens::AUTO_13: return "AUTO_13";
			case Tokens::AUTO_11: return "AUTO_11";
			case Tokens::AUTO_7: return "AUTO_7";
			case Tokens::AUTO_6: return "AUTO_6";
			case Tokens::AUTO_17: return "AUTO_17";
			case Tokens::cll_COMPARE_OP: return "cll_COMPARE_OP";
			case Tokens::AUTO_9: return "AUTO_9";
			case Tokens::AUTO_5: return "AUTO_5";
			case Tokens::AUTO_10: return "AUTO_10";
			case Tokens::cll_ASSIGNMENT_OP: return "cll_ASSIGNMENT_OP";
			case Tokens::AUTO_19: return "AUTO_19";
			case Tokens::cll_TEMPLATE: return "cll_TEMPLATE";
			case Tokens::cll_LOGICAL_NOT: return "cll_LOGICAL_NOT";
			case Tokens::cll_LOGICAL_OP: return "cll_LOGICAL_OP";
			case Tokens::cll_TYPE: return "cll_TYPE";
			case Tokens::AUTO_12: return "AUTO_12";
			case Tokens::cll_LOGICAL_OR: return "cll_LOGICAL_OR";
			case Tokens::cll_OP: return "cll_OP";
			case Tokens::rule_ESCAPED: return "rule_ESCAPED";
			case Tokens::STRING: return "STRING";
			case Tokens::NUMBER: return "NUMBER";
			case Tokens::AUTO_16: return "AUTO_16";
			case Tokens::AUTO_4: return "AUTO_4";
			case Tokens::BOOLEAN: return "BOOLEAN";
			case Tokens::AUTO_23: return "AUTO_23";
			case Tokens::AUTO_8: return "AUTO_8";
			case Tokens::rule_CSEQUENCE_ESCAPE: return "rule_CSEQUENCE_ESCAPE";
			case Tokens::AUTO_3: return "AUTO_3";
			case Tokens::AUTO_20: return "AUTO_20";
			case Tokens::rule_HEX: return "rule_HEX";
			case Tokens::rule_QUANTIFIER: return "rule_QUANTIFIER";
			case Tokens::rule_CSEQUENCE_SYMBOL: return "rule_CSEQUENCE_SYMBOL";
			case Tokens::rule_OP: return "rule_OP";
			case Tokens::AUTO_15: return "AUTO_15";
			case Tokens::rule_CSEQUENCE: return "rule_CSEQUENCE";
			case Tokens::cll_LOGICAL_AND: return "cll_LOGICAL_AND";
			case Tokens::rule_CSEQUENCE_DIAPASON: return "rule_CSEQUENCE_DIAPASON";
			case Tokens::rule_ANY: return "rule_ANY";
			case Tokens::AUTO_14: return "AUTO_14";
			case Tokens::rule_NOSPACE: return "rule_NOSPACE";
			case Tokens::rule_BIN: return "rule_BIN";
			case Tokens::AUTO_2: return "AUTO_2";
			case Tokens::AUTO_0: return "AUTO_0";
			case Tokens::AUTO_1: return "AUTO_1";
		}
		return "NONE";
	}
	constexpr const char* RulesToString(Rules rule) {
		switch (rule) {
			case Rules::NONE: return "NONE";
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
			case Rules::cll_expr_term: return "cll_expr_term";
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
			case Rules::rule_group: return "rule_group";
			case Rules::rule_keyvalue: return "rule_keyvalue";
			case Rules::cll_loop_for: return "cll_loop_for";
			case Rules::rule_nested_rule: return "rule_nested_rule";
			case Rules::rule_data_block_regular_datablock: return "rule_data_block_regular_datablock";
			case Rules::rule_data_block_regular_datablock_key: return "rule_data_block_regular_datablock_key";
			case Rules::rule_data_block_templated_datablock: return "rule_data_block_templated_datablock";
			case Rules::rule_rule: return "rule_rule";
			case Rules::cll_expr_value: return "cll_expr_value";
		}
		return "NONE";
	}
	namespace Types {
		using AUTO_1_data = ::Parser::str_t;
		using AUTO_2_data = ::Parser::str_t;
		using rule_BIN_data = ::Parser::str_t;
		using rule_CSEQUENCE_SYMBOL_data = ::Parser::str_t;
		using rule_QUANTIFIER_data = ::Parser::str_t;
		using rule_HEX_data = ::Parser::str_t;
		using AUTO_20_data = ::Parser::str_t;
		using AUTO_3_data = ::Parser::str_t;
		using AUTO_8_data = ::Parser::str_t;
		using AUTO_23_data = ::Parser::str_t;
		using AUTO_6_data = ::Parser::str_t;
		using AUTO_7_data = ::Parser::str_t;
		using AUTO_5_data = ::Parser::str_t;
		using cll_ASSIGNMENT_OP_data = ::Parser::str_t;
		using AUTO_14_data = ::Parser::str_t;
		using AUTO_18_data = ::Parser::str_t;
		using AUTO_9_data = ::Parser::str_t;
		using AUTO_17_data = ::Parser::str_t;
		using AUTO_0_data = ::Parser::str_t;
		using AUTO_21_data = ::Parser::str_t;
		using cll_COMPARE_OP_data = ::Parser::str_t;
		using AUTO_13_data = ::Parser::str_t;
		using cll_LOGICAL_OP_data = ::Parser::Token_res;
		using AUTO_24_data = ::Parser::str_t;
		using AUTO_10_data = ::Parser::str_t;
		using AUTO_19_data = ::Parser::str_t;
		using AUTO_12_data = ::Parser::str_t;
		using AUTO_16_data = ::Parser::str_t;
		using AUTO_4_data = ::Parser::str_t;
		using cll_OP_data = ::Parser::str_t;
		using AUTO_15_data = ::Parser::str_t;
		using rule_ESCAPED_data = ::Parser::UNDEF;
		using AUTO_11_data = ::Parser::str_t;
		using AUTO_22_data = ::Parser::str_t;
		using STRING_data = ::Parser::str_t;
		using rule_CSEQUENCE_ESCAPE_data = ::Parser::str_t;
		using BOOLEAN_data = ::Parser::str_t;
		using cll_data = ::Parser::Rule_res;
		using cll_expr_value_data = ::Parser::Rule_res;
		using cll_stmt_data = ::Parser::Rule_res;
		using cll_expr_group_data = ::Parser::Rule_res;
		using cll_expr_data = ::Parser::Rule_res;
		using cll_function_body_call_data = ::Parser::Rule_res;
		using rule_value_data = ::Parser::Token;
		using rule_data_block_data = ::Parser::Rule_res;
		using rule_nested_rule_data = ::Parser::UNDEF;
		using cll_function_body_decl_data = ::Parser::Rule_res;
		using rule_group_data = ::Parser::Rule_res;
		using rule_keyvalue_data = ::Parser::Token;
		using rule_data_block_regular_datablock_data = ::Parser::Rule_res;
	}

	namespace get {
		const ::Parser::Types::AUTO_1& AUTO_1(const ::Parser::Token &token);
		::Parser::Types::AUTO_1& AUTO_1(::Parser::Token &token);
		const ::Parser::Types::AUTO_2& AUTO_2(const ::Parser::Token &token);
		::Parser::Types::AUTO_2& AUTO_2(::Parser::Token &token);
		const ::Parser::Types::rule_BIN& rule_BIN(const ::Parser::Token &token);
		::Parser::Types::rule_BIN& rule_BIN(::Parser::Token &token);
		const ::Parser::Types::rule_NOSPACE& rule_NOSPACE(const ::Parser::Token &token);
		::Parser::Types::rule_NOSPACE& rule_NOSPACE(::Parser::Token &token);
		const ::Parser::Types::rule_ANY& rule_ANY(const ::Parser::Token &token);
		::Parser::Types::rule_ANY& rule_ANY(::Parser::Token &token);
		const ::Parser::Types::rule_CSEQUENCE_DIAPASON& rule_CSEQUENCE_DIAPASON(const ::Parser::Token &token);
		::Parser::Types::rule_CSEQUENCE_DIAPASON& rule_CSEQUENCE_DIAPASON(::Parser::Token &token);
		const ::Parser::Types::cll_LOGICAL_AND& cll_LOGICAL_AND(const ::Parser::Token &token);
		::Parser::Types::cll_LOGICAL_AND& cll_LOGICAL_AND(::Parser::Token &token);
		const ::Parser::Types::rule_CSEQUENCE& rule_CSEQUENCE(const ::Parser::Token &token);
		::Parser::Types::rule_CSEQUENCE& rule_CSEQUENCE(::Parser::Token &token);
		const ::Parser::Types::rule_OP& rule_OP(const ::Parser::Token &token);
		::Parser::Types::rule_OP& rule_OP(::Parser::Token &token);
		const ::Parser::Types::rule_CSEQUENCE_SYMBOL& rule_CSEQUENCE_SYMBOL(const ::Parser::Token &token);
		::Parser::Types::rule_CSEQUENCE_SYMBOL& rule_CSEQUENCE_SYMBOL(::Parser::Token &token);
		const ::Parser::Types::rule_QUANTIFIER& rule_QUANTIFIER(const ::Parser::Token &token);
		::Parser::Types::rule_QUANTIFIER& rule_QUANTIFIER(::Parser::Token &token);
		const ::Parser::Types::rule_HEX& rule_HEX(const ::Parser::Token &token);
		::Parser::Types::rule_HEX& rule_HEX(::Parser::Token &token);
		const ::Parser::Types::AUTO_20& AUTO_20(const ::Parser::Token &token);
		::Parser::Types::AUTO_20& AUTO_20(::Parser::Token &token);
		const ::Parser::Types::AUTO_3& AUTO_3(const ::Parser::Token &token);
		::Parser::Types::AUTO_3& AUTO_3(::Parser::Token &token);
		const ::Parser::Types::AUTO_8& AUTO_8(const ::Parser::Token &token);
		::Parser::Types::AUTO_8& AUTO_8(::Parser::Token &token);
		const ::Parser::Types::AUTO_23& AUTO_23(const ::Parser::Token &token);
		::Parser::Types::AUTO_23& AUTO_23(::Parser::Token &token);
		const ::Parser::Types::AUTO_6& AUTO_6(const ::Parser::Token &token);
		::Parser::Types::AUTO_6& AUTO_6(::Parser::Token &token);
		const ::Parser::Types::AUTO_7& AUTO_7(const ::Parser::Token &token);
		::Parser::Types::AUTO_7& AUTO_7(::Parser::Token &token);
		const ::Parser::Types::AUTO_5& AUTO_5(const ::Parser::Token &token);
		::Parser::Types::AUTO_5& AUTO_5(::Parser::Token &token);
		const ::Parser::Types::cll_ASSIGNMENT_OP& cll_ASSIGNMENT_OP(const ::Parser::Token &token);
		::Parser::Types::cll_ASSIGNMENT_OP& cll_ASSIGNMENT_OP(::Parser::Token &token);
		const ::Parser::Types::AUTO_14& AUTO_14(const ::Parser::Token &token);
		::Parser::Types::AUTO_14& AUTO_14(::Parser::Token &token);
		const ::Parser::Types::AUTO_18& AUTO_18(const ::Parser::Token &token);
		::Parser::Types::AUTO_18& AUTO_18(::Parser::Token &token);
		const ::Parser::Types::AUTO_9& AUTO_9(const ::Parser::Token &token);
		::Parser::Types::AUTO_9& AUTO_9(::Parser::Token &token);
		const ::Parser::Types::AUTO_17& AUTO_17(const ::Parser::Token &token);
		::Parser::Types::AUTO_17& AUTO_17(::Parser::Token &token);
		const ::Parser::Types::AUTO_0& AUTO_0(const ::Parser::Token &token);
		::Parser::Types::AUTO_0& AUTO_0(::Parser::Token &token);
		const ::Parser::Types::AUTO_21& AUTO_21(const ::Parser::Token &token);
		::Parser::Types::AUTO_21& AUTO_21(::Parser::Token &token);
		const ::Parser::Types::cll_COMPARE_OP& cll_COMPARE_OP(const ::Parser::Token &token);
		::Parser::Types::cll_COMPARE_OP& cll_COMPARE_OP(::Parser::Token &token);
		const ::Parser::Types::AUTO_13& AUTO_13(const ::Parser::Token &token);
		::Parser::Types::AUTO_13& AUTO_13(::Parser::Token &token);
		const ::Parser::Types::cll_LOGICAL_OP& cll_LOGICAL_OP(const ::Parser::Token &token);
		::Parser::Types::cll_LOGICAL_OP& cll_LOGICAL_OP(::Parser::Token &token);
		const ::Parser::Types::NUMBER& NUMBER(const ::Parser::Token &token);
		::Parser::Types::NUMBER& NUMBER(::Parser::Token &token);
		const ::Parser::Types::AUTO_24& AUTO_24(const ::Parser::Token &token);
		::Parser::Types::AUTO_24& AUTO_24(::Parser::Token &token);
		const ::Parser::Types::__WHITESPACE& __WHITESPACE(const ::Parser::Token &token);
		::Parser::Types::__WHITESPACE& __WHITESPACE(::Parser::Token &token);
		const ::Parser::Types::AUTO_10& AUTO_10(const ::Parser::Token &token);
		::Parser::Types::AUTO_10& AUTO_10(::Parser::Token &token);
		const ::Parser::Types::cll_LOGICAL_NOT& cll_LOGICAL_NOT(const ::Parser::Token &token);
		::Parser::Types::cll_LOGICAL_NOT& cll_LOGICAL_NOT(::Parser::Token &token);
		const ::Parser::Types::AUTO_19& AUTO_19(const ::Parser::Token &token);
		::Parser::Types::AUTO_19& AUTO_19(::Parser::Token &token);
		const ::Parser::Types::cll_TYPE& cll_TYPE(const ::Parser::Token &token);
		::Parser::Types::cll_TYPE& cll_TYPE(::Parser::Token &token);
		const ::Parser::Types::cll_TEMPLATE& cll_TEMPLATE(const ::Parser::Token &token);
		::Parser::Types::cll_TEMPLATE& cll_TEMPLATE(::Parser::Token &token);
		const ::Parser::Types::AUTO_12& AUTO_12(const ::Parser::Token &token);
		::Parser::Types::AUTO_12& AUTO_12(::Parser::Token &token);
		const ::Parser::Types::AUTO_16& AUTO_16(const ::Parser::Token &token);
		::Parser::Types::AUTO_16& AUTO_16(::Parser::Token &token);
		const ::Parser::Types::AUTO_4& AUTO_4(const ::Parser::Token &token);
		::Parser::Types::AUTO_4& AUTO_4(::Parser::Token &token);
		const ::Parser::Types::cll_OP& cll_OP(const ::Parser::Token &token);
		::Parser::Types::cll_OP& cll_OP(::Parser::Token &token);
		const ::Parser::Types::AUTO_15& AUTO_15(const ::Parser::Token &token);
		::Parser::Types::AUTO_15& AUTO_15(::Parser::Token &token);
		const ::Parser::Types::cll_LOGICAL_OR& cll_LOGICAL_OR(const ::Parser::Token &token);
		::Parser::Types::cll_LOGICAL_OR& cll_LOGICAL_OR(::Parser::Token &token);
		const ::Parser::Types::rule_ESCAPED& rule_ESCAPED(const ::Parser::Token &token);
		::Parser::Types::rule_ESCAPED& rule_ESCAPED(::Parser::Token &token);
		const ::Parser::Types::AUTO_11& AUTO_11(const ::Parser::Token &token);
		::Parser::Types::AUTO_11& AUTO_11(::Parser::Token &token);
		const ::Parser::Types::AUTO_22& AUTO_22(const ::Parser::Token &token);
		::Parser::Types::AUTO_22& AUTO_22(::Parser::Token &token);
		const ::Parser::Types::STRING& STRING(const ::Parser::Token &token);
		::Parser::Types::STRING& STRING(::Parser::Token &token);
		const ::Parser::Types::rule_CSEQUENCE_ESCAPE& rule_CSEQUENCE_ESCAPE(const ::Parser::Token &token);
		::Parser::Types::rule_CSEQUENCE_ESCAPE& rule_CSEQUENCE_ESCAPE(::Parser::Token &token);
		const ::Parser::Types::BOOLEAN& BOOLEAN(const ::Parser::Token &token);
		::Parser::Types::BOOLEAN& BOOLEAN(::Parser::Token &token);
		const ::Parser::Types::rule_data_block_templated_datablock& rule_data_block_templated_datablock(const ::Parser::Rule &rule);
		::Parser::Types::rule_data_block_templated_datablock& rule_data_block_templated_datablock(::Parser::Rule &rule);
		const ::Parser::Types::rule_rule& rule_rule(const ::Parser::Rule &rule);
		::Parser::Types::rule_rule& rule_rule(::Parser::Rule &rule);
		const ::Parser::Types::cll_function_parameters& cll_function_parameters(const ::Parser::Rule &rule);
		::Parser::Types::cll_function_parameters& cll_function_parameters(::Parser::Rule &rule);
		const ::Parser::Types::cll_function_arguments& cll_function_arguments(const ::Parser::Rule &rule);
		::Parser::Types::cll_function_arguments& cll_function_arguments(::Parser::Rule &rule);
		const ::Parser::Types::cll_expr_term& cll_expr_term(const ::Parser::Rule &rule);
		::Parser::Types::cll_expr_term& cll_expr_term(::Parser::Rule &rule);
		const ::Parser::Types::cll__variable& cll__variable(const ::Parser::Rule &rule);
		::Parser::Types::cll__variable& cll__variable(::Parser::Rule &rule);
		const ::Parser::Types::cll_expr_arithmetic& cll_expr_arithmetic(const ::Parser::Rule &rule);
		::Parser::Types::cll_expr_arithmetic& cll_expr_arithmetic(::Parser::Rule &rule);
		const ::Parser::Types::cll__if& cll__if(const ::Parser::Rule &rule);
		::Parser::Types::cll__if& cll__if(::Parser::Rule &rule);
		const ::Parser::Types::cll_expr_compare& cll_expr_compare(const ::Parser::Rule &rule);
		::Parser::Types::cll_expr_compare& cll_expr_compare(::Parser::Rule &rule);
		const ::Parser::Types::cll& cll(const ::Parser::Rule &rule);
		::Parser::Types::cll& cll(::Parser::Rule &rule);
		const ::Parser::Types::rule& rule(const ::Parser::Rule &rule);
		::Parser::Types::rule& rule(::Parser::Rule &rule);
		const ::Parser::Types::cll_function_call& cll_function_call(const ::Parser::Rule &rule);
		::Parser::Types::cll_function_call& cll_function_call(::Parser::Rule &rule);
		const ::Parser::Types::cll__var& cll__var(const ::Parser::Rule &rule);
		::Parser::Types::cll__var& cll__var(::Parser::Rule &rule);
		const ::Parser::Types::cll_function_decl& cll_function_decl(const ::Parser::Rule &rule);
		::Parser::Types::cll_function_decl& cll_function_decl(::Parser::Rule &rule);
		const ::Parser::Types::cll_expr_value& cll_expr_value(const ::Parser::Rule &rule);
		::Parser::Types::cll_expr_value& cll_expr_value(::Parser::Rule &rule);
		const ::Parser::Types::cll_expr_logical& cll_expr_logical(const ::Parser::Rule &rule);
		::Parser::Types::cll_expr_logical& cll_expr_logical(::Parser::Rule &rule);
		const ::Parser::Types::cll_stmt& cll_stmt(const ::Parser::Rule &rule);
		::Parser::Types::cll_stmt& cll_stmt(::Parser::Rule &rule);
		const ::Parser::Types::cll_expr_group& cll_expr_group(const ::Parser::Rule &rule);
		::Parser::Types::cll_expr_group& cll_expr_group(::Parser::Rule &rule);
		const ::Parser::Types::cll_method_call& cll_method_call(const ::Parser::Rule &rule);
		::Parser::Types::cll_method_call& cll_method_call(::Parser::Rule &rule);
		const ::Parser::Types::cll_loop_while& cll_loop_while(const ::Parser::Rule &rule);
		::Parser::Types::cll_loop_while& cll_loop_while(::Parser::Rule &rule);
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
		const ::Parser::Types::rule_nested_rule& rule_nested_rule(const ::Parser::Rule &rule);
		::Parser::Types::rule_nested_rule& rule_nested_rule(::Parser::Rule &rule);
		const ::Parser::Types::cll_function_body_decl& cll_function_body_decl(const ::Parser::Rule &rule);
		::Parser::Types::cll_function_body_decl& cll_function_body_decl(::Parser::Rule &rule);
		const ::Parser::Types::rule_group& rule_group(const ::Parser::Rule &rule);
		::Parser::Types::rule_group& rule_group(::Parser::Rule &rule);
		const ::Parser::Types::rule_name& rule_name(const ::Parser::Rule &rule);
		::Parser::Types::rule_name& rule_name(::Parser::Rule &rule);
		const ::Parser::Types::rule_keyvalue& rule_keyvalue(const ::Parser::Rule &rule);
		::Parser::Types::rule_keyvalue& rule_keyvalue(::Parser::Rule &rule);
		const ::Parser::Types::rule_data_block_regular_datablock& rule_data_block_regular_datablock(const ::Parser::Rule &rule);
		::Parser::Types::rule_data_block_regular_datablock& rule_data_block_regular_datablock(::Parser::Rule &rule);
		const ::Parser::Types::rule_data_block_regular_datablock_key& rule_data_block_regular_datablock_key(const ::Parser::Rule &rule);
		::Parser::Types::rule_data_block_regular_datablock_key& rule_data_block_regular_datablock_key(::Parser::Rule &rule);
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
        Lexer(char*& in) : Lexer_base(in) {}
        Lexer(const char*& in) : Lexer_base(in) {}
        Lexer(TokenFlow &tokens) : Lexer_base(tokens) {}
        Lexer() {}
		private:
			Token_res NONE(const char*);
			Token_res __WHITESPACE(const char*);
			Token_res AUTO_24(const char*);
			Token_res AUTO_22(const char*);
			Token_res AUTO_21(const char*);
			Token_res AUTO_18(const char*);
			Token_res AUTO_13(const char*);
			Token_res AUTO_11(const char*);
			Token_res AUTO_7(const char*);
			Token_res AUTO_6(const char*);
			Token_res AUTO_17(const char*);
			Token_res cll_COMPARE_OP(const char*);
			Token_res AUTO_9(const char*);
			Token_res AUTO_5(const char*);
			Token_res AUTO_10(const char*);
			Token_res cll_ASSIGNMENT_OP(const char*);
			Token_res AUTO_19(const char*);
			Token_res cll_TEMPLATE(const char*);
			Token_res cll_LOGICAL_NOT(const char*);
			Token_res cll_LOGICAL_OP(const char*);
			Token_res cll_TYPE(const char*);
			Token_res AUTO_12(const char*);
			Token_res cll_LOGICAL_OR(const char*);
			Token_res cll_OP(const char*);
			Token_res rule_ESCAPED(const char*);
			Token_res STRING(const char*);
			Token_res NUMBER(const char*);
			Token_res AUTO_16(const char*);
			Token_res AUTO_4(const char*);
			Token_res BOOLEAN(const char*);
			Token_res AUTO_23(const char*);
			Token_res AUTO_8(const char*);
			Token_res rule_CSEQUENCE_ESCAPE(const char*);
			Token_res AUTO_3(const char*);
			Token_res AUTO_20(const char*);
			Token_res rule_HEX(const char*);
			Token_res rule_QUANTIFIER(const char*);
			Token_res rule_CSEQUENCE_SYMBOL(const char*);
			Token_res rule_OP(const char*);
			Token_res AUTO_15(const char*);
			Token_res rule_CSEQUENCE(const char*);
			Token_res cll_LOGICAL_AND(const char*);
			Token_res rule_CSEQUENCE_DIAPASON(const char*);
			Token_res rule_ANY(const char*);
			Token_res AUTO_14(const char*);
			Token_res rule_NOSPACE(const char*);
			Token_res rule_BIN(const char*);
			Token_res AUTO_2(const char*);
			Token_res AUTO_0(const char*);
			Token_res AUTO_1(const char*);
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
		::Parser::Rule_res __WHITESPACE(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::str_t _0;
			::Parser::bool_t success_1 = false;
			::Parser::bool_t success_2 = false;
			while (*(pos + 0) == ' ' || *(pos + 0) == '\t' || *(pos + 0) == '\n' || *(pos + 0) == '\r' || *(pos + 0) == '\v' || *(pos + 0) == '\f')
			{
				_0 += ::Parser::str_t(pos, 1);
				success_1 = true;
				pos += 1;
				success_2 = true;
			}
			if (!success_2)
			{
				return {};
			}
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::__WHITESPACE)};
		}
		template <class IT>
		::Parser::Rule_res AUTO_24(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::str_t _0;
			::Parser::bool_t success_1 = false;
			if (!(!std::strncmp(pos + 0, "while", 5)))
			{
				return {};
			}
			_0 += ::Parser::str_t(pos, 5);
			success_1 = true;
			pos += 5;
			::Parser::Types::AUTO_24_data data = _0;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::AUTO_24, data)};
		}
		template <class IT>
		::Parser::Rule_res AUTO_22(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::str_t _0;
			::Parser::bool_t success_1 = false;
			if (!(!std::strncmp(pos + 0, "fn", 2)))
			{
				return {};
			}
			_0 += ::Parser::str_t(pos, 2);
			success_1 = true;
			pos += 2;
			::Parser::Types::AUTO_22_data data = _0;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::AUTO_22, data)};
		}
		template <class IT>
		::Parser::Rule_res AUTO_21(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::str_t _0;
			::Parser::bool_t success_1 = false;
			if (!(*(pos + 0) == ':'))
			{
				return {};
			}
			_0 += ::Parser::str_t(pos, 1);
			success_1 = true;
			pos += 1;
			::Parser::Types::AUTO_21_data data = _0;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::AUTO_21, data)};
		}
		template <class IT>
		::Parser::Rule_res AUTO_18(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::str_t _0;
			::Parser::bool_t success_1 = false;
			if (!(*(pos + 0) == ']'))
			{
				return {};
			}
			_0 += ::Parser::str_t(pos, 1);
			success_1 = true;
			pos += 1;
			::Parser::Types::AUTO_18_data data = _0;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::AUTO_18, data)};
		}
		template <class IT>
		::Parser::Rule_res AUTO_13(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::str_t _0;
			::Parser::bool_t success_1 = false;
			if (!(*(pos + 0) == '('))
			{
				return {};
			}
			_0 += ::Parser::str_t(pos, 1);
			success_1 = true;
			pos += 1;
			::Parser::Types::AUTO_13_data data = _0;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::AUTO_13, data)};
		}
		template <class IT>
		::Parser::Rule_res AUTO_11(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::str_t _0;
			::Parser::bool_t success_1 = false;
			if (!(*(pos + 0) == '&'))
			{
				return {};
			}
			_0 += ::Parser::str_t(pos, 1);
			success_1 = true;
			pos += 1;
			::Parser::Types::AUTO_11_data data = _0;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::AUTO_11, data)};
		}
		template <class IT>
		::Parser::Rule_res AUTO_7(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::str_t _0;
			::Parser::bool_t success_1 = false;
			if (!(*(pos + 0) == '('))
			{
				return {};
			}
			_0 += ::Parser::str_t(pos, 1);
			success_1 = true;
			pos += 1;
			::Parser::Types::AUTO_7_data data = _0;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::AUTO_7, data)};
		}
		template <class IT>
		::Parser::Rule_res AUTO_6(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::str_t _0;
			::Parser::bool_t success_1 = false;
			if (!(*(pos + 0) == '#'))
			{
				return {};
			}
			_0 += ::Parser::str_t(pos, 1);
			success_1 = true;
			pos += 1;
			::Parser::Types::AUTO_6_data data = _0;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::AUTO_6, data)};
		}
		template <class IT>
		::Parser::Rule_res AUTO_17(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::str_t _0;
			::Parser::bool_t success_1 = false;
			if (!(*(pos + 0) == '['))
			{
				return {};
			}
			_0 += ::Parser::str_t(pos, 1);
			success_1 = true;
			pos += 1;
			::Parser::Types::AUTO_17_data data = _0;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::AUTO_17, data)};
		}
		template <class IT>
		::Parser::Rule_res cll_COMPARE_OP(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::str_t _0;
			::Parser::bool_t success_1 = false;
			if (!(!std::strncmp(pos + 0, "==", 2)))
			{
				return {};
			}
			_0 += ::Parser::str_t(pos, 2);
			success_1 = true;
			pos += 2;
			skip_spaces(pos);
			::Parser::str_t _2;
			::Parser::bool_t success_3 = false;
			if (!(!std::strncmp(pos + 0, "!=", 2)))
			{
				reportError(pos, "\"!=\"");
				return {};
			}
			_2 += ::Parser::str_t(pos, 2);
			success_3 = true;
			pos += 2;
			skip_spaces(pos);
			::Parser::str_t _4;
			::Parser::bool_t success_5 = false;
			if (!(*(pos + 0) == '>'))
			{
				reportError(pos, "\">\"");
				return {};
			}
			_4 += ::Parser::str_t(pos, 1);
			success_5 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::str_t _6;
			::Parser::bool_t success_7 = false;
			if (!(*(pos + 0) == '<'))
			{
				reportError(pos, "\"<\"");
				return {};
			}
			_6 += ::Parser::str_t(pos, 1);
			success_7 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::str_t _8;
			::Parser::bool_t success_9 = false;
			if (!(!std::strncmp(pos + 0, ">=", 2)))
			{
				reportError(pos, "\">=\"");
				return {};
			}
			_8 += ::Parser::str_t(pos, 2);
			success_9 = true;
			pos += 2;
			skip_spaces(pos);
			::Parser::str_t _10;
			::Parser::bool_t success_11 = false;
			if (!(!std::strncmp(pos + 0, "<=", 2)))
			{
				reportError(pos, "\"<=\"");
				return {};
			}
			_10 += ::Parser::str_t(pos, 2);
			success_11 = true;
			pos += 2;
			::Parser::Types::cll_COMPARE_OP_data data = _0;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_COMPARE_OP, data)};
		}
		template <class IT>
		::Parser::Rule_res AUTO_9(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::str_t _0;
			::Parser::bool_t success_1 = false;
			if (!(*(pos + 0) == '#'))
			{
				return {};
			}
			_0 += ::Parser::str_t(pos, 1);
			success_1 = true;
			pos += 1;
			::Parser::Types::AUTO_9_data data = _0;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::AUTO_9, data)};
		}
		template <class IT>
		::Parser::Rule_res AUTO_5(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::str_t _0;
			::Parser::bool_t success_1 = false;
			if (!(*(pos + 0) == '{'))
			{
				return {};
			}
			_0 += ::Parser::str_t(pos, 1);
			success_1 = true;
			pos += 1;
			::Parser::Types::AUTO_5_data data = _0;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::AUTO_5, data)};
		}
		template <class IT>
		::Parser::Rule_res AUTO_10(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::str_t _0;
			::Parser::bool_t success_1 = false;
			if (!(*(pos + 0) == '.'))
			{
				return {};
			}
			_0 += ::Parser::str_t(pos, 1);
			success_1 = true;
			pos += 1;
			::Parser::Types::AUTO_10_data data = _0;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::AUTO_10, data)};
		}
		template <class IT>
		::Parser::Rule_res cll_ASSIGNMENT_OP(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token_res _0;
			::Parser::bool_t success_1 = false;
			_0 = OP(pos);
			if (!(_0.status))
			{
				return {};
			}
			success_1 = true;
			pos += _0.node.length();
			skip_spaces(pos);
			::Parser::str_t _2;
			::Parser::bool_t success_3 = false;
			if (!(*(pos + 0) == '='))
			{
				reportError(pos, "\"=\"");
				return {};
			}
			_2 += ::Parser::str_t(pos, 1);
			success_3 = true;
			pos += 1;
			::Parser::Types::cll_ASSIGNMENT_OP_data data = _2;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_ASSIGNMENT_OP, data)};
		}
		template <class IT>
		::Parser::Rule_res AUTO_19(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::str_t _0;
			::Parser::bool_t success_1 = false;
			if (!(!std::strncmp(pos + 0, "if", 2)))
			{
				return {};
			}
			_0 += ::Parser::str_t(pos, 2);
			success_1 = true;
			pos += 2;
			::Parser::Types::AUTO_19_data data = _0;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::AUTO_19, data)};
		}
		template <class IT>
		::Parser::Rule_res cll_TEMPLATE(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::str_t _0;
			::Parser::bool_t success_1 = false;
			if (!(*(pos + 0) == '<'))
			{
				return {};
			}
			_0 += ::Parser::str_t(pos, 1);
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::Token_res _2;
			::Parser::bool_t success_3 = false;
			_2 = TYPE(pos);
			if (!(_2.status))
			{
				reportError(pos, "TYPE");
				return {};
			}
			success_3 = true;
			pos += _2.node.length();
			skip_spaces(pos);
			::Parser::bool_t success_5 = false;
			auto begin_6 = pos;
			::Parser::bool_t success_9 = false;
			::Parser::bool_t success_7 = false;
			::Parser::str_t _6;
			if (!(*(begin_6 + 0) == ','))
			{
				reportError(pos, "\",\"");
				return {};
			}
			_6 += ::Parser::str_t(begin_6, 1);
			success_7 = true;
			begin_6 += 1;
			skip_spaces(begin_6);
			::Parser::Token_res _8;
			_8 = TYPE(begin_6);
			if (!(_8.status))
			{
				reportError(pos, "TYPE");
				return {};
			}
			success_9 = true;
			begin_6 += _8.node.length();
			if (success_7 && success_9)
			{
				success_5 = true;
				pos = begin_6;
			}
			skip_spaces(pos);
			::Parser::str_t _10;
			::Parser::bool_t success_11 = false;
			if (!(*(pos + 0) == '>'))
			{
				reportError(pos, "\">\"");
				return {};
			}
			_10 += ::Parser::str_t(pos, 1);
			success_11 = true;
			pos += 1;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_TEMPLATE)};
		}
		template <class IT>
		::Parser::Rule_res cll_LOGICAL_NOT(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::str_t _0;
			::Parser::bool_t success_1 = false;
			if (!(*(pos + 0) == '!'))
			{
				return {};
			}
			_0 += ::Parser::str_t(pos, 1);
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::str_t _2;
			::Parser::bool_t success_3 = false;
			if (!(!std::strncmp(pos + 0, "not", 3)))
			{
				reportError(pos, "\"not\"");
				return {};
			}
			_2 += ::Parser::str_t(pos, 3);
			success_3 = true;
			pos += 3;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_LOGICAL_NOT)};
		}
		template <class IT>
		::Parser::Rule_res cll_LOGICAL_OP(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token_res _0;
			::Parser::bool_t success_1 = false;
			_0 = LOGICAL_AND(pos);
			if (!(_0.status))
			{
				return {};
			}
			success_1 = true;
			pos += _0.node.length();
			skip_spaces(pos);
			::Parser::Token_res _2;
			::Parser::bool_t success_3 = false;
			_2 = LOGICAL_OR(pos);
			if (!(_2.status))
			{
				reportError(pos, "LOGICAL_OR");
				return {};
			}
			success_3 = true;
			pos += _2.node.length();
			::Parser::Types::cll_LOGICAL_OP_data data = _0.node;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_LOGICAL_OP, data)};
		}
		template <class IT>
		::Parser::Rule_res cll_TYPE(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::bool_t success_1 = false;
			success_1 = false;
			auto begin_2 = pos;
			::Parser::bool_t success_17 = false;
			::Parser::bool_t success_11 = false;
			::Parser::bool_t success_9 = false;
			::Parser::bool_t success_7 = false;
			::Parser::bool_t success_5 = false;
			::Parser::bool_t success_3 = false;
			::Parser::str_t _2;
			if (!(!std::strncmp(begin_2 + 0, "var", 3)))
			{
				return {};
			}
			_2 += ::Parser::str_t(begin_2, 3);
			success_3 = true;
			begin_2 += 3;
			skip_spaces(begin_2);
			::Parser::str_t _4;
			if (!(!std::strncmp(begin_2 + 0, "num", 3)))
			{
				reportError(pos, "\"num\"");
				return {};
			}
			_4 += ::Parser::str_t(begin_2, 3);
			success_5 = true;
			begin_2 += 3;
			skip_spaces(begin_2);
			::Parser::str_t _6;
			if (!(!std::strncmp(begin_2 + 0, "bool", 4)))
			{
				reportError(pos, "\"bool\"");
				return {};
			}
			_6 += ::Parser::str_t(begin_2, 4);
			success_7 = true;
			begin_2 += 4;
			skip_spaces(begin_2);
			::Parser::str_t _8;
			if (!(!std::strncmp(begin_2 + 0, "str", 3)))
			{
				reportError(pos, "\"str\"");
				return {};
			}
			_8 += ::Parser::str_t(begin_2, 3);
			success_9 = true;
			begin_2 += 3;
			skip_spaces(begin_2);
			auto begin_12 = begin_2;
			::Parser::bool_t success_15 = false;
			::Parser::bool_t success_13 = false;
			::Parser::str_t _12;
			if (!(!std::strncmp(begin_12 + 0, "arr", 3)))
			{
				reportError(pos, "\"arr\"");
				return {};
			}
			_12 += ::Parser::str_t(begin_12, 3);
			success_13 = true;
			begin_12 += 3;
			skip_spaces(begin_12);
			::Parser::Token_res _14;
			_14 = TEMPLATE(begin_12);
			if (!(_14.status))
			{
				reportError(pos, "TEMPLATE");
				return {};
			}
			success_15 = true;
			begin_12 += _14.node.length();
			if (success_13 && success_15)
			{
				success_11 = true;
				begin_2 = begin_12;
			}
			skip_spaces(begin_2);
			auto begin_18 = begin_2;
			::Parser::bool_t success_21 = false;
			::Parser::bool_t success_19 = false;
			::Parser::str_t _18;
			if (!(!std::strncmp(begin_18 + 0, "obj", 3)))
			{
				reportError(pos, "\"obj\"");
				return {};
			}
			_18 += ::Parser::str_t(begin_18, 3);
			success_19 = true;
			begin_18 += 3;
			skip_spaces(begin_18);
			::Parser::Token_res _20;
			_20 = TEMPLATE(begin_18);
			if (!(_20.status))
			{
				reportError(pos, "TEMPLATE");
				return {};
			}
			success_21 = true;
			begin_18 += _20.node.length();
			if (success_19 && success_21)
			{
				success_17 = true;
				begin_2 = begin_18;
			}
			if (success_3 && success_5 && success_7 && success_9 && success_11 && success_17)
			{
				success_1 = true;
				pos = begin_2;
			}
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_TYPE)};
		}
		template <class IT>
		::Parser::Rule_res AUTO_12(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::str_t _0;
			::Parser::bool_t success_1 = false;
			if (!(!std::strncmp(pos + 0, "for", 3)))
			{
				return {};
			}
			_0 += ::Parser::str_t(pos, 3);
			success_1 = true;
			pos += 3;
			::Parser::Types::AUTO_12_data data = _0;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::AUTO_12, data)};
		}
		template <class IT>
		::Parser::Rule_res cll_LOGICAL_OR(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::str_t _0;
			::Parser::bool_t success_1 = false;
			if (!(!std::strncmp(pos + 0, "||", 2)))
			{
				return {};
			}
			_0 += ::Parser::str_t(pos, 2);
			success_1 = true;
			pos += 2;
			skip_spaces(pos);
			::Parser::str_t _2;
			::Parser::bool_t success_3 = false;
			if (!(!std::strncmp(pos + 0, "or", 2)))
			{
				reportError(pos, "\"or\"");
				return {};
			}
			_2 += ::Parser::str_t(pos, 2);
			success_3 = true;
			pos += 2;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_LOGICAL_OR)};
		}
		template <class IT>
		::Parser::Rule_res cll_OP(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::str_t _0;
			::Parser::bool_t success_1 = false;
			if (!(*(pos + 0) == '+'))
			{
				return {};
			}
			_0 += ::Parser::str_t(pos, 1);
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::str_t _2;
			::Parser::bool_t success_3 = false;
			if (!(*(pos + 0) == '-'))
			{
				reportError(pos, "\"-\"");
				return {};
			}
			_2 += ::Parser::str_t(pos, 1);
			success_3 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::str_t _4;
			::Parser::bool_t success_5 = false;
			if (!(*(pos + 0) == '*'))
			{
				reportError(pos, "\"*\"");
				return {};
			}
			_4 += ::Parser::str_t(pos, 1);
			success_5 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::str_t _6;
			::Parser::bool_t success_7 = false;
			if (!(*(pos + 0) == '/'))
			{
				reportError(pos, "\"/\"");
				return {};
			}
			_6 += ::Parser::str_t(pos, 1);
			success_7 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::str_t _8;
			::Parser::bool_t success_9 = false;
			if (!(*(pos + 0) == '%'))
			{
				reportError(pos, "\"%\"");
				return {};
			}
			_8 += ::Parser::str_t(pos, 1);
			success_9 = true;
			pos += 1;
			::Parser::Types::cll_OP_data data = _0;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_OP, data)};
		}
		template <class IT>
		::Parser::Rule_res rule_ESCAPED(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::str_t _0;
			::Parser::bool_t success_1 = false;
			if (!(!std::strncmp(pos + 0, "\\", 1)))
			{
				return {};
			}
			_0 += ::Parser::str_t(pos, 1);
			success_1 = true;
			pos += 1;
			::Parser::str_t _2;
			::Parser::bool_t success_3 = false;
			if (*(pos + 0) == '\0')
			{
				reportError(pos, "symbol");
				return {};
			}
			_2 += ::Parser::str_t(pos, 1);
			success_3 = true;
			pos += 1;
			::Parser::Types::rule_ESCAPED_data data = ;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::rule_ESCAPED, data)};
		}
		template <class IT>
		::Parser::Rule_res STRING(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::str_t _0;
			::Parser::bool_t success_1 = false;
			auto begin_2 = pos;
			::Parser::bool_t success_15 = false;
			::Parser::bool_t success_5 = false;
			::Parser::bool_t success_3 = false;
			::Parser::str_t _2;
			if (!(!std::strncmp(begin_2 + 0, "\'", 1)))
			{
				return {};
			}
			_2 += ::Parser::str_t(begin_2, 1);
			success_3 = true;
			begin_2 += 1;
			skip_spaces(begin_2);
			::Parser::str_t _4;
			auto begin_6 = begin_2;
			::Parser::bool_t success_13 = false;
			::Parser::bool_t success_7 = false;
			::Parser::str_t _6;
			auto begin_8 = begin_6;
			::Parser::bool_t success_11 = false;
			::Parser::bool_t success_9 = false;
			::Parser::str_t _8;
			if (!(!std::strncmp(begin_8 + 0, "\\", 1)))
			{
				reportError(pos, "\"\\\"");
				return {};
			}
			_8 += ::Parser::str_t(begin_8, 1);
			success_9 = true;
			begin_8 += 1;
			skip_spaces(begin_8);
			::Parser::str_t _10;
			if (*(begin_8 + 0) == '\0')
			{
				reportError(pos, "symbol");
				return {};
			}
			_10 += ::Parser::str_t(begin_8, 1);
			success_11 = true;
			begin_8 += 1;
			_6 += _8;
			_6 += ;
			if (success_9 && success_11)
			{
				success_7 = true;
				begin_6 = begin_8;
			}
			skip_spaces(begin_6);
			::Parser::str_t _12;
			if (!(!(*(begin_6 + 0) == '\'')))
			{
				reportError(pos, "not '");
				return {};
			}
			_12 += ::Parser::str_t(begin_6, 1);
			success_13 = true;
			begin_6 += 1;
			_4 += _6;
			_4 += _12;
			if (success_7 && success_13)
			{
				success_5 = true;
				begin_2 = begin_6;
			}
			skip_spaces(begin_2);
			::Parser::str_t _14;
			if (!(!std::strncmp(begin_2 + 0, "\'", 1)))
			{
				reportError(pos, "\"\'\"");
				return {};
			}
			_14 += ::Parser::str_t(begin_2, 1);
			success_15 = true;
			begin_2 += 1;
			_0 += _2;
			_0 += _4;
			_0 += _14;
			if (success_3 && success_5 && success_15)
			{
				success_1 = true;
				pos = begin_2;
			}
			::Parser::Types::STRING_data data = _10;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::STRING, data)};
		}
		template <class IT>
		::Parser::Rule_res NUMBER(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::str_t _0;
			::Parser::bool_t success_1 = false;
			if (!(*(pos + 0) == '+' || *(pos + 0) == '-'))
			{
				return {};
			}
			_0 += ::Parser::str_t(pos, 1);
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::str_t _2;
			::Parser::bool_t success_3 = false;
			if (!((*(pos + 0)>='0' && *(pos + 0)<='9')))
			{
				reportError(pos, "0-9");
				return {};
			}
			_2 += ::Parser::str_t(pos, 1);
			success_3 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::str_t _4;
			::Parser::bool_t success_5 = false;
			auto begin_6 = pos;
			::Parser::bool_t success_9 = false;
			::Parser::bool_t success_7 = false;
			::Parser::str_t _6;
			if (!(*(begin_6 + 0) == '.' || *(begin_6 + 0) == ','))
			{
				reportError(pos, ". or ,");
				return {};
			}
			_6 += ::Parser::str_t(begin_6, 1);
			success_7 = true;
			begin_6 += 1;
			skip_spaces(begin_6);
			::Parser::str_t _8;
			if (!((*(begin_6 + 0)>='0' && *(begin_6 + 0)<='9')))
			{
				reportError(pos, "0-9");
				return {};
			}
			_8 += ::Parser::str_t(begin_6, 1);
			success_9 = true;
			begin_6 += 1;
			_4 += _6;
			_4 += _8;
			if (success_7 && success_9)
			{
				success_5 = true;
				pos = begin_6;
			}
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::NUMBER)};
		}
		template <class IT>
		::Parser::Rule_res AUTO_16(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::str_t _0;
			::Parser::bool_t success_1 = false;
			if (!(!std::strncmp(pos + 0, "--", 2)))
			{
				return {};
			}
			_0 += ::Parser::str_t(pos, 2);
			success_1 = true;
			pos += 2;
			::Parser::Types::AUTO_16_data data = _0;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::AUTO_16, data)};
		}
		template <class IT>
		::Parser::Rule_res AUTO_4(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::str_t _0;
			::Parser::bool_t success_1 = false;
			if (!(*(pos + 0) == '='))
			{
				return {};
			}
			_0 += ::Parser::str_t(pos, 1);
			success_1 = true;
			pos += 1;
			::Parser::Types::AUTO_4_data data = _0;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::AUTO_4, data)};
		}
		template <class IT>
		::Parser::Rule_res BOOLEAN(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::str_t _0;
			::Parser::str_t d;
			::Parser::bool_t success_1 = false;
			auto begin_2 = pos;
			::Parser::bool_t success_5 = false;
			::Parser::bool_t success_3 = false;
			::Parser::str_t _2;
			if (!(!std::strncmp(begin_2 + 0, "true", 4)))
			{
				return {};
			}
			_2 += ::Parser::str_t(begin_2, 4);
			success_3 = true;
			begin_2 += 4;
			skip_spaces(begin_2);
			::Parser::str_t _4;
			if (!(!std::strncmp(begin_2 + 0, "false", 5)))
			{
				reportError(pos, "\"false\"");
				return {};
			}
			_4 += ::Parser::str_t(begin_2, 5);
			success_5 = true;
			begin_2 += 5;
			_0 += _2;
			_0 += _4;
			if (success_3 && success_5)
			{
				success_1 = true;
				d = _0;
				pos = begin_2;
			}
			::Parser::Types::BOOLEAN_data data = d;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::BOOLEAN, data)};
		}
		template <class IT>
		::Parser::Rule_res AUTO_23(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::str_t _0;
			::Parser::bool_t success_1 = false;
			if (!(*(pos + 0) == '.'))
			{
				return {};
			}
			_0 += ::Parser::str_t(pos, 1);
			success_1 = true;
			pos += 1;
			::Parser::Types::AUTO_23_data data = _0;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::AUTO_23, data)};
		}
		template <class IT>
		::Parser::Rule_res AUTO_8(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::str_t _0;
			::Parser::bool_t success_1 = false;
			if (!(*(pos + 0) == ')'))
			{
				return {};
			}
			_0 += ::Parser::str_t(pos, 1);
			success_1 = true;
			pos += 1;
			::Parser::Types::AUTO_8_data data = _0;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::AUTO_8, data)};
		}
		template <class IT>
		::Parser::Rule_res rule_CSEQUENCE_ESCAPE(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::str_t _0;
			::Parser::bool_t success_1 = false;
			if (!(!std::strncmp(pos + 0, "\\", 1)))
			{
				return {};
			}
			_0 += ::Parser::str_t(pos, 1);
			success_1 = true;
			pos += 1;
			::Parser::str_t _2;
			::Parser::bool_t success_3 = false;
			if (*(pos + 0) == '\0')
			{
				reportError(pos, "symbol");
				return {};
			}
			_2 += ::Parser::str_t(pos, 1);
			success_3 = true;
			pos += 1;
			::Parser::Types::rule_CSEQUENCE_ESCAPE_data data = _0;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::rule_CSEQUENCE_ESCAPE, data)};
		}
		template <class IT>
		::Parser::Rule_res AUTO_3(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::str_t _0;
			::Parser::bool_t success_1 = false;
			if (!(*(pos + 0) == '}'))
			{
				return {};
			}
			_0 += ::Parser::str_t(pos, 1);
			success_1 = true;
			pos += 1;
			::Parser::Types::AUTO_3_data data = _0;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::AUTO_3, data)};
		}
		template <class IT>
		::Parser::Rule_res AUTO_20(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::str_t _0;
			::Parser::bool_t success_1 = false;
			if (!(*(pos + 0) == '$'))
			{
				return {};
			}
			_0 += ::Parser::str_t(pos, 1);
			success_1 = true;
			pos += 1;
			::Parser::Types::AUTO_20_data data = _0;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::AUTO_20, data)};
		}
		template <class IT>
		::Parser::Rule_res rule_HEX(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::str_t _0;
			::Parser::bool_t success_1 = false;
			if (!(!std::strncmp(pos + 0, "0x", 2)))
			{
				return {};
			}
			_0 += ::Parser::str_t(pos, 2);
			success_1 = true;
			pos += 2;
			skip_spaces(pos);
			::Parser::str_t _2;
			::Parser::bool_t success_3 = false;
			if (!((*(pos + 0)>='0' && *(pos + 0)<='9') || (*(pos + 0)>='A' && *(pos + 0)<='F') || (*(pos + 0)>='a' && *(pos + 0)<='f')))
			{
				reportError(pos, "0-9, A-F or a-f");
				return {};
			}
			_2 += ::Parser::str_t(pos, 1);
			success_3 = true;
			pos += 1;
			::Parser::Types::rule_HEX_data data = _2;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::rule_HEX, data)};
		}
		template <class IT>
		::Parser::Rule_res rule_QUANTIFIER(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::str_t _0;
			::Parser::bool_t success_1 = false;
			auto begin_2 = pos;
			::Parser::bool_t success_7 = false;
			::Parser::bool_t success_5 = false;
			::Parser::bool_t success_3 = false;
			::Parser::str_t _2;
			if (!(*(begin_2 + 0) == '?'))
			{
				return {};
			}
			_2 += ::Parser::str_t(begin_2, 1);
			success_3 = true;
			begin_2 += 1;
			skip_spaces(begin_2);
			::Parser::str_t _4;
			if (!(*(begin_2 + 0) == '+'))
			{
				reportError(pos, "\"+\"");
				return {};
			}
			_4 += ::Parser::str_t(begin_2, 1);
			success_5 = true;
			begin_2 += 1;
			skip_spaces(begin_2);
			::Parser::str_t _6;
			if (!(*(begin_2 + 0) == '*'))
			{
				reportError(pos, "\"*\"");
				return {};
			}
			_6 += ::Parser::str_t(begin_2, 1);
			success_7 = true;
			begin_2 += 1;
			_0 += _2;
			_0 += _4;
			_0 += _6;
			if (success_3 && success_5 && success_7)
			{
				success_1 = true;
				pos = begin_2;
			}
			::Parser::Types::rule_QUANTIFIER_data data = _4;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::rule_QUANTIFIER, data)};
		}
		template <class IT>
		::Parser::Rule_res rule_CSEQUENCE_SYMBOL(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::str_t _0;
			::Parser::bool_t success_1 = false;
			auto begin_2 = pos;
			::Parser::bool_t success_7 = false;
			::Parser::bool_t success_5 = false;
			::Parser::bool_t success_3 = false;
			::Parser::str_t _2;
			if (!(!std::strncmp(begin_2 + 0, "\\", 1)))
			{
				return {};
			}
			_2 += ::Parser::str_t(begin_2, 1);
			success_3 = true;
			begin_2 += 1;
			skip_spaces(begin_2);
			::Parser::str_t _4;
			if (!(!std::strncmp(begin_2 + 0, "\\]", 2)))
			{
				reportError(pos, "\"\\]\"");
				return {};
			}
			_4 += ::Parser::str_t(begin_2, 2);
			success_5 = true;
			begin_2 += 2;
			skip_spaces(begin_2);
			::Parser::str_t _6;
			if (!(!(*(begin_2 + 0) == '\\')))
			{
				reportError(pos, "not \");
				return {};
			}
			_6 += ::Parser::str_t(begin_2, 1);
			success_7 = true;
			begin_2 += 1;
			_0 += _2;
			_0 += _4;
			_0 += _6;
			if (success_3 && success_5 && success_7)
			{
				success_1 = true;
				pos = begin_2;
			}
			::Parser::Types::rule_CSEQUENCE_SYMBOL_data data = _4;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::rule_CSEQUENCE_SYMBOL, data)};
		}
		template <class IT>
		::Parser::Rule_res rule_OP(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::str_t _0;
			::Parser::bool_t success_1 = false;
			if (!(*(pos + 0) == '|'))
			{
				return {};
			}
			_0 += ::Parser::str_t(pos, 1);
			success_1 = true;
			pos += 1;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::rule_OP)};
		}
		template <class IT>
		::Parser::Rule_res AUTO_15(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::str_t _0;
			::Parser::bool_t success_1 = false;
			if (!(!std::strncmp(pos + 0, "++", 2)))
			{
				return {};
			}
			_0 += ::Parser::str_t(pos, 2);
			success_1 = true;
			pos += 2;
			::Parser::Types::AUTO_15_data data = _0;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::AUTO_15, data)};
		}
		template <class IT>
		::Parser::Rule_res rule_CSEQUENCE(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::str_t _0;
			::Parser::bool_t success_1 = false;
			if (!(*(pos + 0) == '['))
			{
				return {};
			}
			_0 += ::Parser::str_t(pos, 1);
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::str_t _2;
			::Parser::bool_t success_3 = false;
			if (!(*(pos + 0) == '^'))
			{
				reportError(pos, "\"^\"");
				return {};
			}
			_2 += ::Parser::str_t(pos, 1);
			success_3 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::bool_t success_5 = false;
			auto begin_6 = pos;
			::Parser::bool_t success_11 = false;
			::Parser::bool_t success_9 = false;
			::Parser::bool_t success_7 = false;
			::Parser::Token_res _6;
			_6 = ESCAPE(begin_6);
			if (!(_6.status))
			{
				reportError(pos, "ESCAPE");
				return {};
			}
			success_7 = true;
			begin_6 += _6.node.length();
			skip_spaces(begin_6);
			::Parser::Token_res _8;
			_8 = SYMBOL(begin_6);
			if (!(_8.status))
			{
				reportError(pos, "SYMBOL");
				return {};
			}
			success_9 = true;
			begin_6 += _8.node.length();
			skip_spaces(begin_6);
			::Parser::Token_res _10;
			_10 = DIAPASON(begin_6);
			if (!(_10.status))
			{
				reportError(pos, "DIAPASON");
				return {};
			}
			success_11 = true;
			begin_6 += _10.node.length();
			if (success_7 && success_9 && success_11)
			{
				success_5 = true;
				pos = begin_6;
			}
			skip_spaces(pos);
			::Parser::str_t _12;
			::Parser::bool_t success_13 = false;
			if (!(*(pos + 0) == ']'))
			{
				reportError(pos, "\"]\"");
				return {};
			}
			_12 += ::Parser::str_t(pos, 1);
			success_13 = true;
			pos += 1;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::rule_CSEQUENCE)};
		}
		template <class IT>
		::Parser::Rule_res cll_LOGICAL_AND(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::str_t _0;
			::Parser::bool_t success_1 = false;
			if (!(!std::strncmp(pos + 0, "&&", 2)))
			{
				return {};
			}
			_0 += ::Parser::str_t(pos, 2);
			success_1 = true;
			pos += 2;
			skip_spaces(pos);
			::Parser::str_t _2;
			::Parser::bool_t success_3 = false;
			if (!(!std::strncmp(pos + 0, "and", 3)))
			{
				reportError(pos, "\"and\"");
				return {};
			}
			_2 += ::Parser::str_t(pos, 3);
			success_3 = true;
			pos += 3;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_LOGICAL_AND)};
		}
		template <class IT>
		::Parser::Rule_res rule_CSEQUENCE_DIAPASON(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::bool_t success_1 = false;
			success_1 = false;
			auto begin_2 = pos;
			::Parser::bool_t success_7 = false;
			::Parser::bool_t success_5 = false;
			::Parser::bool_t success_3 = false;
			::Parser::Token_res _2;
			_2 = SYMBOL(begin_2);
			if (!(_2.status))
			{
				return {};
			}
			success_3 = true;
			begin_2 += _2.node.length();
			::Parser::str_t _4;
			if (!(*(begin_2 + 0) == '-'))
			{
				reportError(pos, "\"-\"");
				return {};
			}
			_4 += ::Parser::str_t(begin_2, 1);
			success_5 = true;
			begin_2 += 1;
			::Parser::Token_res _6;
			_6 = SYMBOL(begin_2);
			if (!(_6.status))
			{
				reportError(pos, "SYMBOL");
				return {};
			}
			success_7 = true;
			begin_2 += _6.node.length();
			if (success_3 && success_5 && success_7)
			{
				success_1 = true;
				pos = begin_2;
			}
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::rule_CSEQUENCE_DIAPASON)};
		}
		template <class IT>
		::Parser::Rule_res rule_ANY(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::str_t _0;
			::Parser::bool_t success_1 = false;
			if (!(*(pos + 0) == '.'))
			{
				return {};
			}
			_0 += ::Parser::str_t(pos, 1);
			success_1 = true;
			pos += 1;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::rule_ANY)};
		}
		template <class IT>
		::Parser::Rule_res AUTO_14(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::str_t _0;
			::Parser::bool_t success_1 = false;
			if (!(*(pos + 0) == ';'))
			{
				return {};
			}
			_0 += ::Parser::str_t(pos, 1);
			success_1 = true;
			pos += 1;
			::Parser::Types::AUTO_14_data data = _0;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::AUTO_14, data)};
		}
		template <class IT>
		::Parser::Rule_res rule_NOSPACE(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::str_t _0;
			::Parser::bool_t success_1 = false;
			if (!(!std::strncmp(pos + 0, "\\s0", 3)))
			{
				return {};
			}
			_0 += ::Parser::str_t(pos, 3);
			success_1 = true;
			pos += 3;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::rule_NOSPACE)};
		}
		template <class IT>
		::Parser::Rule_res rule_BIN(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::str_t _0;
			::Parser::bool_t success_1 = false;
			if (!(!std::strncmp(pos + 0, "0b", 2)))
			{
				return {};
			}
			_0 += ::Parser::str_t(pos, 2);
			success_1 = true;
			pos += 2;
			skip_spaces(pos);
			::Parser::str_t _2;
			::Parser::bool_t success_3 = false;
			if (!(*(pos + 0) == '0' || *(pos + 0) == '1'))
			{
				reportError(pos, "0 or 1");
				return {};
			}
			_2 += ::Parser::str_t(pos, 1);
			success_3 = true;
			pos += 1;
			::Parser::Types::rule_BIN_data data = _2;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::rule_BIN, data)};
		}
		template <class IT>
		::Parser::Rule_res AUTO_2(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::str_t _0;
			::Parser::bool_t success_1 = false;
			if (!(*(pos + 0) == ','))
			{
				return {};
			}
			_0 += ::Parser::str_t(pos, 1);
			success_1 = true;
			pos += 1;
			::Parser::Types::AUTO_2_data data = _0;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::AUTO_2, data)};
		}
		template <class IT>
		::Parser::Rule_res AUTO_0(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::str_t _0;
			::Parser::bool_t success_1 = false;
			if (!(*(pos + 0) == '@'))
			{
				return {};
			}
			_0 += ::Parser::str_t(pos, 1);
			success_1 = true;
			pos += 1;
			::Parser::Types::AUTO_0_data data = _0;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::AUTO_0, data)};
		}
		template <class IT>
		::Parser::Rule_res AUTO_1(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::str_t _0;
			::Parser::bool_t success_1 = false;
			if (!(*(pos + 0) == '{'))
			{
				return {};
			}
			_0 += ::Parser::str_t(pos, 1);
			success_1 = true;
			pos += 1;
			::Parser::Types::AUTO_1_data data = _0;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::AUTO_1, data)};
		}
	};

} // Parser


#endif // PARSER
