#pragma once
#ifndef PARSER
#define PARSER

#include <string>
#include <list>
#include <unordered_map>
#include <iscstdlibc++.h>
#include <fstream>
#include <iterator>
#ifndef PARSER_OBJ_TYPE
#define PARSER_OBJ_TYPE std::unordered_map
#endif
#ifndef PARSER_ARR_TYPE
#define PARSER_ARR_TYPE std::list
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
		NONE, cll_OP, cll_ASSIGNMENT_OP, cll_COMPARE_OP, cll_LOGICAL_OP, cll_LOGICAL_NOT, cll_LOGICAL_AND, cll_LOGICAL_OR, cll_TYPE, cll_TEMPLATE, STRING, NUMBER, BOOLEAN, END, NEWLINE, LINEAR_COMMENT, ID, NAME, Rule_OP, Rule_QUANTIFIER, Rule_CSEQUENCE, Rule_CSEQUENCE_SYMBOL, Rule_CSEQUENCE_ESCAPE, Rule_CSEQUENCE_DIAPASON, Rule_ANY, Rule_NOSPACE, Rule_ESCAPED, Rule_HEX, Rule_BIN, AUTO_0, AUTO_1, AUTO_6, AUTO_7, AUTO_14, AUTO_19, AUTO_20, AUTO_25, AUTO_27, AUTO_32, AUTO_34, AUTO_35, AUTO_36, AUTO_37, AUTO_38, AUTO_39, AUTO_42, AUTO_43, AUTO_44, AUTO_45, AUTO_46, AUTO_47, AUTO_48, AUTO_49, AUTO_50, AUTO_51, __WHITESPACE
	};
	enum class Rules {
		NONE, cll, cll_if, cll_variable, cll_function_body_call, cll_function_body_decl, cll_function_arguments, cll_function_parameters, cll_cll_function_call, cll_function_decl, cll_expr, cll_expr_logical, cll_expr_compare, cll_expr_arithmetic, cll_expr_value, cll_expr_group, cll_var, cll_block, cll_loop_while, cll_loop_for, array, object, any_data, spacemode, main, use, use_unit, Rule, Rule_rule, Rule_name, Rule_group, Rule_keyvalue, Rule_value, Rule_nested_rule, Rule_data_block, Rule_data_block_key
	};
	using Rule = ISPA_STD::node<Rules>;
	using Rule_res = ISPA_STD::match_result<Rules>;
	using Token = ISPA_STD::node<Tokens>;
	using Token_res = ISPA_STD::match_result<Tokens>;
	using TokenFlow = arr_t<Token>;
	using Tree = arr_t<Rules>;
	std::string TokensToString(Tokens token);
	class Lexer : public ISPA_STD::Lexer_base<Tokens> {
		public:
			Token makeToken(const char*& pos);

            /**
             * @param os the output stream
             * @param sensitiveInfo - whether print such info as line number and position in line. These methods require the start pointer to be valid
             * Print the tokens into an output stream
             */
            void printTokens(std::ostream& os, bool sentitiveInfo = false);
            /**
             * @param os the output stream
             * @param token the token to print
             * @param sensitiveInfo - whether print such info as line number and position in line. These methods require the start pointer to be valid
             * Prints a single token into an output stream
             */
            void printToken(std::ostream& os, const Token& token, bool sensitiveInfo = false);
		private:
			using cll_OP_data = ::Parser::str_t;
			using cll_ASSIGNMENT_OP_data = ::Parser::Token;
			using cll_COMPARE_OP_data = ::Parser::str_t;
			using cll_LOGICAL_OP_data = ::Parser::Token;
			struct cll_TYPE_data {
				::Parser::str_t templ;
				::Parser::str_t type;
			};
			struct cll_TEMPLATE_data {
				::Parser::arr_t<::Parser::Token> second;
				::Parser::Token first;
			};
			using STRING_data = ::Parser::str_t;
			struct NUMBER_data {
				::Parser::str_t dec;
				::Parser::str_t main;
				::Parser::str_t sign;
			};
			using BOOLEAN_data = ::Parser::str_t;
			using ID_data = ::Parser::str_t;
			using NAME_data = ::Parser::Token;
			using Rule_QUANTIFIER_data = ::Parser::str_t;
			using Rule_CSEQUENCE_SYMBOL_data = ::Parser::str_t;
			using Rule_CSEQUENCE_ESCAPE_data = ::Parser::str_t;
			using Rule_CSEQUENCE_DIAPASON_data = ::Parser::arr_t<::Parser::any_t>;
			struct Rule_CSEQUENCE_data {
				::Parser::arr_t<::Parser::Token> val;
				::Parser::str_t _not;
			};
			struct Rule_ESCAPED_data {
				::Parser::str_t num;
				::Parser::str_t c;
			};
			using Rule_HEX_data = ::Parser::str_t;
			using Rule_BIN_data = ::Parser::str_t;
			using AUTO_0_data = ::Parser::str_t;
			using AUTO_1_data = ::Parser::str_t;
			using AUTO_6_data = ::Parser::str_t;
			using AUTO_7_data = ::Parser::str_t;
			using AUTO_14_data = ::Parser::str_t;
			using AUTO_19_data = ::Parser::str_t;
			using AUTO_20_data = ::Parser::str_t;
			using AUTO_25_data = ::Parser::str_t;
			using AUTO_27_data = ::Parser::str_t;
			using AUTO_32_data = ::Parser::str_t;
			using AUTO_34_data = ::Parser::str_t;
			using AUTO_35_data = ::Parser::str_t;
			using AUTO_36_data = ::Parser::str_t;
			using AUTO_37_data = ::Parser::str_t;
			using AUTO_38_data = ::Parser::str_t;
			using AUTO_39_data = ::Parser::str_t;
			using AUTO_42_data = ::Parser::str_t;
			using AUTO_43_data = ::Parser::str_t;
			using AUTO_44_data = ::Parser::str_t;
			using AUTO_45_data = ::Parser::str_t;
			using AUTO_46_data = ::Parser::str_t;
			using AUTO_47_data = ::Parser::str_t;
			using AUTO_48_data = ::Parser::str_t;
			using AUTO_49_data = ::Parser::str_t;
			using AUTO_50_data = ::Parser::str_t;
			using AUTO_51_data = ::Parser::str_t;
			Token_res cll_OP(const char*);
			Token_res cll_ASSIGNMENT_OP(const char*);
			Token_res cll_COMPARE_OP(const char*);
			Token_res cll_LOGICAL_OP(const char*);
			Token_res cll_LOGICAL_NOT(const char*);
			Token_res cll_LOGICAL_AND(const char*);
			Token_res cll_LOGICAL_OR(const char*);
			Token_res cll_TYPE(const char*);
			Token_res cll_TEMPLATE(const char*);
			Token_res STRING(const char*);
			Token_res NUMBER(const char*);
			Token_res BOOLEAN(const char*);
			Token_res END(const char*);
			Token_res NEWLINE(const char*);
			Token_res LINEAR_COMMENT(const char*);
			Token_res ID(const char*);
			Token_res NAME(const char*);
			Token_res Rule_OP(const char*);
			Token_res Rule_QUANTIFIER(const char*);
			Token_res Rule_CSEQUENCE(const char*);
			Token_res Rule_CSEQUENCE_SYMBOL(const char*);
			Token_res Rule_CSEQUENCE_ESCAPE(const char*);
			Token_res Rule_CSEQUENCE_DIAPASON(const char*);
			Token_res Rule_ANY(const char*);
			Token_res Rule_NOSPACE(const char*);
			Token_res Rule_ESCAPED(const char*);
			Token_res Rule_HEX(const char*);
			Token_res Rule_BIN(const char*);
			Token_res AUTO_0(const char*);
			Token_res AUTO_1(const char*);
			Token_res AUTO_6(const char*);
			Token_res AUTO_7(const char*);
			Token_res AUTO_14(const char*);
			Token_res AUTO_19(const char*);
			Token_res AUTO_20(const char*);
			Token_res AUTO_25(const char*);
			Token_res AUTO_27(const char*);
			Token_res AUTO_32(const char*);
			Token_res AUTO_34(const char*);
			Token_res AUTO_35(const char*);
			Token_res AUTO_36(const char*);
			Token_res AUTO_37(const char*);
			Token_res AUTO_38(const char*);
			Token_res AUTO_39(const char*);
			Token_res AUTO_42(const char*);
			Token_res AUTO_43(const char*);
			Token_res AUTO_44(const char*);
			Token_res AUTO_45(const char*);
			Token_res AUTO_46(const char*);
			Token_res AUTO_47(const char*);
			Token_res AUTO_48(const char*);
			Token_res AUTO_49(const char*);
			Token_res AUTO_50(const char*);
			Token_res AUTO_51(const char*);
			Token_res __WHITESPACE(const char*);
	};
	class Parser : public ISPA_STD::Parser_base<Tokens, Rules> {
		public:
			Rule_res getRule();
		private:
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
				::Parser::Rule right;
				::Parser::Token op;
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
			using cll_expr_value_data = ::Parser::Rule;
			using cll_expr_group_data = ::Parser::Rule;
			using cll_expr_data = ::Parser::Rule;
			struct cll_var_data {
				::Parser::Rule value;
				::Parser::Token op;
				::Parser::Token id;
				::Parser::Token type;
			};
			using cll_block_data = ::Parser::Rule;
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
			using array_data = ::Parser::arr_t<::Parser::Token>;
			struct object_data {
				::Parser::arr_t<::Parser::Rule> values;
				::Parser::arr_t<::Parser::Token> keys;
				::Parser::Rule value;
				::Parser::Rule key;
			};
			using any_data_data = ::Parser::any_t;
			using spacemode_data = ::Parser::Token;
			struct use_unit_data {
				::Parser::Rule value;
				::Parser::Token name;
			};
			struct use_data {
				::Parser::arr_t<::Parser::Rule> second;
				::Parser::Rule first;
			};
			struct Rule_rule_data {
				::Parser::any_t quantifier;
				::Parser::Rule val;
				::Parser::Rule _variable;
			};
			struct Rule_name_data {
				::Parser::arr_t<::Parser::Token> nested_name;
				::Parser::Token name;
				::Parser::Token is_nested;
			};
			using Rule_group_data = ::Parser::Rule;
			using Rule_keyvalue_data = ::Parser::Token;
			using Rule_value_data = ::Parser::Token;
			using Rule_nested_rule_data = ::Parser::Rule;
			struct Rule_data_block_key_data {
				::Parser::Rule val;
				::Parser::Token name;
			};
			using Rule_data_block_data = ::Parser::Rule;
			struct Rule_data {
				::Parser::Rule nested_rules;
				::Parser::Rule data_block;
				::Parser::Rule rule;
				::Parser::Token name;
			};
			Rule_res cll(::Parser::TokenFlow::iterator pos);
			Rule_res cll_if(::Parser::TokenFlow::iterator pos);
			Rule_res cll_variable(::Parser::TokenFlow::iterator pos);
			Rule_res cll_function_body_call(::Parser::TokenFlow::iterator pos);
			Rule_res cll_function_body_decl(::Parser::TokenFlow::iterator pos);
			Rule_res cll_function_arguments(::Parser::TokenFlow::iterator pos);
			Rule_res cll_function_parameters(::Parser::TokenFlow::iterator pos);
			Rule_res cll_cll_function_call(::Parser::TokenFlow::iterator pos);
			Rule_res cll_function_decl(::Parser::TokenFlow::iterator pos);
			Rule_res cll_expr(::Parser::TokenFlow::iterator pos);
			Rule_res cll_expr_logical(::Parser::TokenFlow::iterator pos);
			Rule_res cll_expr_compare(::Parser::TokenFlow::iterator pos);
			Rule_res cll_expr_arithmetic(::Parser::TokenFlow::iterator pos);
			Rule_res cll_expr_value(::Parser::TokenFlow::iterator pos);
			Rule_res cll_expr_group(::Parser::TokenFlow::iterator pos);
			Rule_res cll_var(::Parser::TokenFlow::iterator pos);
			Rule_res cll_block(::Parser::TokenFlow::iterator pos);
			Rule_res cll_loop_while(::Parser::TokenFlow::iterator pos);
			Rule_res cll_loop_for(::Parser::TokenFlow::iterator pos);
			Rule_res array(::Parser::TokenFlow::iterator pos);
			Rule_res object(::Parser::TokenFlow::iterator pos);
			Rule_res any_data(::Parser::TokenFlow::iterator pos);
			Rule_res spacemode(::Parser::TokenFlow::iterator pos);
			Rule_res main(::Parser::TokenFlow::iterator pos);
			Rule_res use(::Parser::TokenFlow::iterator pos);
			Rule_res use_unit(::Parser::TokenFlow::iterator pos);
			Rule_res Rule(::Parser::TokenFlow::iterator pos);
			Rule_res Rule_rule(::Parser::TokenFlow::iterator pos);
			Rule_res Rule_name(::Parser::TokenFlow::iterator pos);
			Rule_res Rule_group(::Parser::TokenFlow::iterator pos);
			Rule_res Rule_keyvalue(::Parser::TokenFlow::iterator pos);
			Rule_res Rule_value(::Parser::TokenFlow::iterator pos);
			Rule_res Rule_nested_rule(::Parser::TokenFlow::iterator pos);
			Rule_res Rule_data_block(::Parser::TokenFlow::iterator pos);
			Rule_res Rule_data_block_key(::Parser::TokenFlow::iterator pos);
	};

} // Parser


#endif // PARSER
