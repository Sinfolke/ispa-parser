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
		NONE, cll_OP, cll_ASSIGNMENT_OP, cll_COMPARE_OP, cll_LOGICAL_OP, cll_LOGICAL_NOT, cll_LOGICAL_AND, cll_LOGICAL_OR, STRING, NUMBER, BOOLEAN, END, NEWLINE, LINEAR_COMMENT, ID, Rule_OP, Rule_QUANITIFIER, Rule_CSEQUENCE, Rule_CSEQUENCE_SYMBOL, Rule_CSEQUENCE_ESCAPE, Rule_CSEQUENCE_DIAPASON, Rule_ANY, Rule_ESCAPED, Rule_HEX, Rule_BIN, AUTO_0, AUTO_1, AUTO_2, AUTO_3, AUTO_4, AUTO_5, AUTO_6, AUTO_7, AUTO_9, AUTO_14, AUTO_15, AUTO_22, AUTO_27, AUTO_28, AUTO_33, AUTO_35, AUTO_40, AUTO_42, AUTO_43, AUTO_44, AUTO_45, AUTO_46, AUTO_47, AUTO_48, AUTO_51, AUTO_52, AUTO_53, AUTO_54, AUTO_55, AUTO_56, AUTO_57, AUTO_58, AUTO_59, __WHITESPACE
	};
	enum class Rules {
		NONE, cll, cll_type, cll_cll_template, cll_if, cll_variable, cll_function_body_call, cll_function_body_decl, cll_function_arguments, cll_function_parameters, cll_cll_function_call, cll_function_decl, cll_expr, cll_expr_logical, cll_expr_compare, cll_expr_arithmetic, cll_expr_value, cll_expr_group, cll_var, cll_block, cll_loop_while, cll_loop_for, array, object, any_data, spacemode, name, main, use, use_unit, Rule, Rule_rule, Rule_name, Rule_group, Rule_nested_rule, Rule_data_block, Rule_data_block_key
	};
	using Rule = ISPA_STD::node<Rules>;
	using Rule_res = ISPA_STD::match_result<Rules>;
	using Token = ISPA_STD::node<Tokens>;
	using Token_res = ISPA_STD::match_result<Tokens>;
	using TokenFlow = arr_t<Token>;
	using Tree = arr_t<Rules>;
	std::string TokensToString(Tokens token);
	class Tokenizator : public ISPA_STD::Tokenizator_base<Tokens> {
		public:
			Token makeToken();
		private:
			using cll_OP_data = ::Parser::str_t;
			using cll_ASSIGNMENT_OP_data = ::Parser::Token;
			using cll_COMPARE_OP_data = ::Parser::str_t;
			using cll_LOGICAL_OP_data = ::Parser::Token;
			using STRING_data = ::Parser::str_t;
			struct NUMBER_data {
				::Parser::str_t dec;
				::Parser::str_t main;
				::Parser::str_t sign;
			};
			using BOOLEAN_data = ::Parser::str_t;
			using ID_data = ::Parser::str_t;
			using Rule_QUANITIFIER_data = ::Parser::str_t;
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
			using AUTO_2_data = ::Parser::str_t;
			using AUTO_3_data = ::Parser::str_t;
			using AUTO_4_data = ::Parser::str_t;
			using AUTO_5_data = ::Parser::str_t;
			using AUTO_6_data = ::Parser::str_t;
			using AUTO_7_data = ::Parser::str_t;
			using AUTO_9_data = ::Parser::str_t;
			using AUTO_14_data = ::Parser::str_t;
			using AUTO_15_data = ::Parser::str_t;
			using AUTO_22_data = ::Parser::str_t;
			using AUTO_27_data = ::Parser::str_t;
			using AUTO_28_data = ::Parser::str_t;
			using AUTO_33_data = ::Parser::str_t;
			using AUTO_35_data = ::Parser::str_t;
			using AUTO_40_data = ::Parser::str_t;
			using AUTO_42_data = ::Parser::str_t;
			using AUTO_43_data = ::Parser::str_t;
			using AUTO_44_data = ::Parser::str_t;
			using AUTO_45_data = ::Parser::str_t;
			using AUTO_46_data = ::Parser::str_t;
			using AUTO_47_data = ::Parser::str_t;
			using AUTO_48_data = ::Parser::str_t;
			using AUTO_51_data = ::Parser::str_t;
			using AUTO_52_data = ::Parser::str_t;
			using AUTO_53_data = ::Parser::str_t;
			using AUTO_54_data = ::Parser::str_t;
			using AUTO_55_data = ::Parser::str_t;
			using AUTO_56_data = ::Parser::str_t;
			using AUTO_57_data = ::Parser::str_t;
			using AUTO_58_data = ::Parser::str_t;
			using AUTO_59_data = ::Parser::str_t;
			Token_res cll_OP(const char*);
			Token_res cll_ASSIGNMENT_OP(const char*);
			Token_res cll_COMPARE_OP(const char*);
			Token_res cll_LOGICAL_OP(const char*);
			Token_res cll_LOGICAL_NOT(const char*);
			Token_res cll_LOGICAL_AND(const char*);
			Token_res cll_LOGICAL_OR(const char*);
			Token_res STRING(const char*);
			Token_res NUMBER(const char*);
			Token_res BOOLEAN(const char*);
			Token_res END(const char*);
			Token_res NEWLINE(const char*);
			Token_res LINEAR_COMMENT(const char*);
			Token_res ID(const char*);
			Token_res Rule_OP(const char*);
			Token_res Rule_QUANITIFIER(const char*);
			Token_res Rule_CSEQUENCE(const char*);
			Token_res Rule_CSEQUENCE_SYMBOL(const char*);
			Token_res Rule_CSEQUENCE_ESCAPE(const char*);
			Token_res Rule_CSEQUENCE_DIAPASON(const char*);
			Token_res Rule_ANY(const char*);
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
			Token_res AUTO_9(const char*);
			Token_res AUTO_14(const char*);
			Token_res AUTO_15(const char*);
			Token_res AUTO_22(const char*);
			Token_res AUTO_27(const char*);
			Token_res AUTO_28(const char*);
			Token_res AUTO_33(const char*);
			Token_res AUTO_35(const char*);
			Token_res AUTO_40(const char*);
			Token_res AUTO_42(const char*);
			Token_res AUTO_43(const char*);
			Token_res AUTO_44(const char*);
			Token_res AUTO_45(const char*);
			Token_res AUTO_46(const char*);
			Token_res AUTO_47(const char*);
			Token_res AUTO_48(const char*);
			Token_res AUTO_51(const char*);
			Token_res AUTO_52(const char*);
			Token_res AUTO_53(const char*);
			Token_res AUTO_54(const char*);
			Token_res AUTO_55(const char*);
			Token_res AUTO_56(const char*);
			Token_res AUTO_57(const char*);
			Token_res AUTO_58(const char*);
			Token_res AUTO_59(const char*);
			Token_res __WHITESPACE(const char*);
	};
	class Parser {
		public:
			struct cll_type_data {
				::Parser::Token templ;
				::Parser::Token type;
			};
			struct cll_cll_template_data {
				::Parser::arr_t<::Parser::Rule> second;
				::Parser::Rule first;
			};
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
				::Parser::Rule type;
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
			using name_data = ::Parser::Token;
			struct use_unit_data {
				::Parser::Rule value;
				::Parser::Token name;
			};
			struct use_data {
				::Parser::arr_t<::Parser::Rule> second;
				::Parser::Rule first;
			};
			struct Rule_rule_data {
				::Parser::Token qualifier;
				::Parser::any_t val;
			};
			struct Rule_name_data {
				::Parser::arr_t<::Parser::Token> nested_name;
				::Parser::Token name;
				::Parser::Token is_nested;
			};
			struct Rule_group_data {
				::Parser::Rule val;
				::Parser::Token variable;
			};
			using Rule_nested_rule_data = ::Parser::Rule;
			struct Rule_data_block_key_data {
				::Parser::Rule val;
				::Parser::Token name;
			};
			using Rule_data_block_data = ::Parser::Rule;
			struct Rule_data {
				::Parser::Rule nestedRules;
				::Parser::Rule data_block;
				::Parser::Rule rule;
				::Parser::Token name;
			};
			Rule_res cll(::Parser::arr_t<Token>::iterator pos);
			Rule_res cll_type(::Parser::arr_t<Token>::iterator pos);
			Rule_res cll_cll_template(::Parser::arr_t<Token>::iterator pos);
			Rule_res cll_if(::Parser::arr_t<Token>::iterator pos);
			Rule_res cll_variable(::Parser::arr_t<Token>::iterator pos);
			Rule_res cll_function_body_call(::Parser::arr_t<Token>::iterator pos);
			Rule_res cll_function_body_decl(::Parser::arr_t<Token>::iterator pos);
			Rule_res cll_function_arguments(::Parser::arr_t<Token>::iterator pos);
			Rule_res cll_function_parameters(::Parser::arr_t<Token>::iterator pos);
			Rule_res cll_cll_function_call(::Parser::arr_t<Token>::iterator pos);
			Rule_res cll_function_decl(::Parser::arr_t<Token>::iterator pos);
			Rule_res cll_expr(::Parser::arr_t<Token>::iterator pos);
			Rule_res cll_expr_logical(::Parser::arr_t<Token>::iterator pos);
			Rule_res cll_expr_compare(::Parser::arr_t<Token>::iterator pos);
			Rule_res cll_expr_arithmetic(::Parser::arr_t<Token>::iterator pos);
			Rule_res cll_expr_value(::Parser::arr_t<Token>::iterator pos);
			Rule_res cll_expr_group(::Parser::arr_t<Token>::iterator pos);
			Rule_res cll_var(::Parser::arr_t<Token>::iterator pos);
			Rule_res cll_block(::Parser::arr_t<Token>::iterator pos);
			Rule_res cll_loop_while(::Parser::arr_t<Token>::iterator pos);
			Rule_res cll_loop_for(::Parser::arr_t<Token>::iterator pos);
			Rule_res array(::Parser::arr_t<Token>::iterator pos);
			Rule_res object(::Parser::arr_t<Token>::iterator pos);
			Rule_res any_data(::Parser::arr_t<Token>::iterator pos);
			Rule_res spacemode(::Parser::arr_t<Token>::iterator pos);
			Rule_res name(::Parser::arr_t<Token>::iterator pos);
			Rule_res main(::Parser::arr_t<Token>::iterator pos);
			Rule_res use(::Parser::arr_t<Token>::iterator pos);
			Rule_res use_unit(::Parser::arr_t<Token>::iterator pos);
			Rule_res Rule(::Parser::arr_t<Token>::iterator pos);
			Rule_res Rule_rule(::Parser::arr_t<Token>::iterator pos);
			Rule_res Rule_name(::Parser::arr_t<Token>::iterator pos);
			Rule_res Rule_group(::Parser::arr_t<Token>::iterator pos);
			Rule_res Rule_nested_rule(::Parser::arr_t<Token>::iterator pos);
			Rule_res Rule_data_block(::Parser::arr_t<Token>::iterator pos);
			Rule_res Rule_data_block_key(::Parser::arr_t<Token>::iterator pos);
	};

} // Parser


#endif // PARSER
