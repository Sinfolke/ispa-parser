#pragma once
#include <string>
#include <list>
#include <unordered_map>
#include <iscstdlibc++.h>
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
		NONE, OP, ASSIGNMENT_OP, COMPARE_OP, LOGICAL_OP, LOGICAL_NOT, LOGICAL_AND, LOGICAL_OR, LOGICAL_ANDR, STRING, NUMBER, BOOLEAN, END, NEWLINE, ID, AUTO_1, AUTO_3, AUTO_4, AUTO_14, AUTO_15, AUTO_16, AUTO_17, AUTO_18, AUTO_19, AUTO_20, AUTO_21, AUTO_22, AUTO_23, AUTO_24, AUTO_25, AUTO_26, AUTO_27, AUTO_28, AUTO_29, AUTO_30, AUTO_31, AUTO_32, AUTO_33, AUTO_34, AUTO_35, AUTO_36, AUTO_48, AUTO_49, AUTO_55, AUTO_60, AUTO_61, AUTO_65, AUTO_70, AUTO_71, AUTO_72, AUTO_73, AUTO_74, AUTO_75, AUTO_76, AUTO_77, AUTO_78, AUTO_82, AUTO_83, AUTO_84, AUTO_85, AUTO_86, AUTO_87, AUTO_88, AUTO_89, AUTO_90, AUTO_91, AUTO_92, AUTO_94, AUTO_95, AUTO_98, AUTO_99, AUTO_101, AUTO_103, AUTO_104, AUTO_105, AUTO_106, AUTO_107, AUTO_108, AUTO_109, AUTO_110, AUTO_111, AUTO_112, AUTO_113, __WHITESPACE
	};
	enum class Rules {
		NONE, accessor_group, accessor_element, accessor_char, accessor_all, accessor, cll, cll_block, cll_spaced_block, cll_template_content_typename, cll_template_content_int, cll_template_content_bool, cll_template_content_str, cll_template_content_arr, cll_template_content_obj, cll_template_content_any_data, cll_csupport_types, cll_type, cll_type_abstract, cll_if, cll_ternary, expr, expr_logical, expr_compare, expr_arithmetic, expr_for_arithmetic, expr_group, expr_expr_copiable_method_call, function_body_call, function_body_decl, function_arguments, function_parameters, cll_function_call, function_decl, loop_while, loop_for, method_call, copiable_method_call, var_refer, cll_var, array, object, any_data, spacemode, linear_comment, main, use, use_unit, Rule, Rule_rule, Rule_other, Rule_op, Rule_qualifier, Rule_group, Rule_csequence, Rule_csequence_symbol, Rule_csequence_escape, Rule_csequence_diapason, Rule_data_block, Rule_data_block_inclosed_map, Rule_data_block_key, Rule_escaped, Rule_nested_rule, Rule_hex, Rule_bin
	};
	using Rule = ISC_STD::_return<Rules>;
	using Rule_res = ISC_STD::match_result<Rules>;
	using Token = ISC_STD::_return<Tokens>;
	using Token_res = ISC_STD::match_result<Tokens>;
	using Tree = ISC_STD::Tree<Rules>;
	class Tokenizator {
		private:
			const char* str;
		public:
			using OP_data = ::Parser::any_t;
			using ASSIGNMENT_OP_data = ::Parser::Token;
			using COMPARE_OP_data = ::Parser::str_t;
			using LOGICAL_OP_data = ::Parser::Token;
			using LOGICAL_NOT_data = ::Parser::str_t;
			using LOGICAL_AND_data = ::Parser::str_t;
			using LOGICAL_OR_data = ::Parser::str_t;
			using LOGICAL_ANDR_data = ::Parser::str_t;
			struct NUMBER_data {
				::Parser::str_t full;
				::Parser::num_t dec_n;
				::Parser::str_t dec;
				::Parser::num_t main_n;
				::Parser::str_t main;
				char sign;
			};
			struct BOOLEAN_data {
				::Parser::str_t lit;
				::Parser::bool_t val;
			};
			using ID_data = ::Parser::str_t;
			using AUTO_1_data = ::Parser::str_t;
			using AUTO_3_data = ::Parser::str_t;
			using AUTO_4_data = ::Parser::str_t;
			using AUTO_14_data = ::Parser::str_t;
			using AUTO_15_data = ::Parser::str_t;
			using AUTO_16_data = ::Parser::str_t;
			using AUTO_17_data = ::Parser::str_t;
			using AUTO_18_data = ::Parser::str_t;
			using AUTO_19_data = ::Parser::str_t;
			using AUTO_20_data = ::Parser::str_t;
			using AUTO_21_data = ::Parser::str_t;
			using AUTO_22_data = ::Parser::str_t;
			using AUTO_23_data = ::Parser::str_t;
			using AUTO_24_data = ::Parser::str_t;
			using AUTO_25_data = ::Parser::str_t;
			using AUTO_26_data = ::Parser::str_t;
			using AUTO_27_data = ::Parser::str_t;
			using AUTO_28_data = ::Parser::str_t;
			using AUTO_29_data = ::Parser::str_t;
			using AUTO_30_data = ::Parser::str_t;
			using AUTO_31_data = ::Parser::str_t;
			using AUTO_32_data = ::Parser::str_t;
			using AUTO_33_data = ::Parser::str_t;
			using AUTO_34_data = ::Parser::str_t;
			using AUTO_35_data = ::Parser::arr_t<::Parser::str_t>;
			using AUTO_36_data = ::Parser::str_t;
			using AUTO_48_data = ::Parser::str_t;
			using AUTO_49_data = ::Parser::str_t;
			using AUTO_55_data = ::Parser::str_t;
			using AUTO_60_data = ::Parser::str_t;
			using AUTO_61_data = ::Parser::str_t;
			using AUTO_65_data = ::Parser::str_t;
			using AUTO_70_data = ::Parser::str_t;
			using AUTO_71_data = ::Parser::str_t;
			using AUTO_72_data = ::Parser::str_t;
			using AUTO_73_data = ::Parser::str_t;
			using AUTO_74_data = ::Parser::str_t;
			using AUTO_75_data = ::Parser::str_t;
			using AUTO_76_data = ::Parser::str_t;
			using AUTO_77_data = ::Parser::str_t;
			using AUTO_78_data = ::Parser::str_t;
			using AUTO_82_data = ::Parser::str_t;
			using AUTO_83_data = ::Parser::str_t;
			using AUTO_84_data = ::Parser::str_t;
			using AUTO_85_data = ::Parser::str_t;
			using AUTO_86_data = ::Parser::str_t;
			using AUTO_87_data = ::Parser::str_t;
			using AUTO_88_data = ::Parser::str_t;
			using AUTO_89_data = ::Parser::str_t;
			using AUTO_90_data = ::Parser::str_t;
			using AUTO_91_data = ::Parser::str_t;
			using AUTO_92_data = ::Parser::str_t;
			using AUTO_94_data = ::Parser::str_t;
			using AUTO_95_data = ::Parser::str_t;
			using AUTO_98_data = ::Parser::str_t;
			using AUTO_99_data = ::Parser::str_t;
			using AUTO_101_data = ::Parser::str_t;
			using AUTO_103_data = ::Parser::str_t;
			using AUTO_104_data = ::Parser::str_t;
			using AUTO_105_data = ::Parser::str_t;
			using AUTO_106_data = ::Parser::str_t;
			using AUTO_107_data = ::Parser::str_t;
			using AUTO_108_data = ::Parser::str_t;
			using AUTO_109_data = ::Parser::str_t;
			using AUTO_110_data = ::Parser::str_t;
			using AUTO_111_data = ::Parser::str_t;
			using AUTO_112_data = ::Parser::str_t;
			using AUTO_113_data = ::Parser::str_t;
			Token_res OP(const char*&);
			Token_res ASSIGNMENT_OP(const char*&);
			Token_res COMPARE_OP(const char*&);
			Token_res LOGICAL_OP(const char*&);
			Token_res LOGICAL_NOT(const char*&);
			Token_res LOGICAL_AND(const char*&);
			Token_res LOGICAL_OR(const char*&);
			Token_res LOGICAL_ANDR(const char*&);
			Token_res STRING(const char*&);
			Token_res NUMBER(const char*&);
			Token_res BOOLEAN(const char*&);
			Token_res END(const char*&);
			Token_res NEWLINE(const char*&);
			Token_res ID(const char*&);
			Token_res AUTO_1(const char*&);
			Token_res AUTO_3(const char*&);
			Token_res AUTO_4(const char*&);
			Token_res AUTO_14(const char*&);
			Token_res AUTO_15(const char*&);
			Token_res AUTO_16(const char*&);
			Token_res AUTO_17(const char*&);
			Token_res AUTO_18(const char*&);
			Token_res AUTO_19(const char*&);
			Token_res AUTO_20(const char*&);
			Token_res AUTO_21(const char*&);
			Token_res AUTO_22(const char*&);
			Token_res AUTO_23(const char*&);
			Token_res AUTO_24(const char*&);
			Token_res AUTO_25(const char*&);
			Token_res AUTO_26(const char*&);
			Token_res AUTO_27(const char*&);
			Token_res AUTO_28(const char*&);
			Token_res AUTO_29(const char*&);
			Token_res AUTO_30(const char*&);
			Token_res AUTO_31(const char*&);
			Token_res AUTO_32(const char*&);
			Token_res AUTO_33(const char*&);
			Token_res AUTO_34(const char*&);
			Token_res AUTO_35(const char*&);
			Token_res AUTO_36(const char*&);
			Token_res AUTO_48(const char*&);
			Token_res AUTO_49(const char*&);
			Token_res AUTO_55(const char*&);
			Token_res AUTO_60(const char*&);
			Token_res AUTO_61(const char*&);
			Token_res AUTO_65(const char*&);
			Token_res AUTO_70(const char*&);
			Token_res AUTO_71(const char*&);
			Token_res AUTO_72(const char*&);
			Token_res AUTO_73(const char*&);
			Token_res AUTO_74(const char*&);
			Token_res AUTO_75(const char*&);
			Token_res AUTO_76(const char*&);
			Token_res AUTO_77(const char*&);
			Token_res AUTO_78(const char*&);
			Token_res AUTO_82(const char*&);
			Token_res AUTO_83(const char*&);
			Token_res AUTO_84(const char*&);
			Token_res AUTO_85(const char*&);
			Token_res AUTO_86(const char*&);
			Token_res AUTO_87(const char*&);
			Token_res AUTO_88(const char*&);
			Token_res AUTO_89(const char*&);
			Token_res AUTO_90(const char*&);
			Token_res AUTO_91(const char*&);
			Token_res AUTO_92(const char*&);
			Token_res AUTO_94(const char*&);
			Token_res AUTO_95(const char*&);
			Token_res AUTO_98(const char*&);
			Token_res AUTO_99(const char*&);
			Token_res AUTO_101(const char*&);
			Token_res AUTO_103(const char*&);
			Token_res AUTO_104(const char*&);
			Token_res AUTO_105(const char*&);
			Token_res AUTO_106(const char*&);
			Token_res AUTO_107(const char*&);
			Token_res AUTO_108(const char*&);
			Token_res AUTO_109(const char*&);
			Token_res AUTO_110(const char*&);
			Token_res AUTO_111(const char*&);
			Token_res AUTO_112(const char*&);
			Token_res AUTO_113(const char*&);
			Token_res __WHITESPACE(const char*&);
	};
	class Parser {
		public:
			using accessor_group_data = ::Parser::Token;
			using accessor_element_data = ::Parser::Token;
			using accessor_char_data = ::Parser::Token;
			using accessor_all_data = ::Parser::Rule;
			struct accessor_data {
				::Parser::arr_t<::Parser::Rule_res> second;
				::Parser::Rule first;
			};
			using cll_data = ::Parser::arr_t<::Parser::str_t>;
			using cll_block_data = ::Parser::Rule;
			using cll_spaced_block_data = ::Parser::arr_t<::Parser::Rule_res>;
			using cll_template_content_typename_data = ::Parser::arr_t<::Parser::any_t>;
			using cll_template_content_int_data = ::Parser::arr_t<::Parser::any_t>;
			using cll_template_content_bool_data = ::Parser::arr_t<::Parser::any_t>;
			using cll_template_content_str_data = ::Parser::arr_t<::Parser::any_t>;
			using cll_template_content_arr_data = ::Parser::arr_t<::Parser::any_t>;
			using cll_template_content_obj_data = ::Parser::arr_t<::Parser::any_t>;
			using cll_template_content_any_data_data = ::Parser::arr_t<::Parser::any_t>;
			struct cll_csupport_types_data {
				::Parser::Token template;
				::Parser::Token type;
			};
			struct cll_type_abstract_data {
				::Parser::Token template;
				::Parser::Token type;
			};
			using cll_type_data = ::Parser::Rule;
			struct cll_if_data {
				::Parser::Token block;
				::Parser::Token expr;
			};
			struct cll_ternary_data {
				::Parser::Rule second;
				::Parser::Rule first;
				::Parser::Rule cond;
			};
			struct expr_logical_data {
				::Parser::Rule right;
				::Parser::Token op;
				::Parser::Rule left;
			};
			struct expr_compare_data {
				::Parser::arr_t<::Parser::Rule_res> sequence;
				::Parser::arr_t<::Parser::Token> operators;
				::Parser::Rule first;
			};
			struct expr_arithmetic_data {
				::Parser::arr_t<::Parser::Rule_res> sequence;
				::Parser::arr_t<::Parser::Token> operators;
				::Parser::Rule first;
			};
			using expr_for_arithmetic_data = ::Parser::Rule;
			using expr_group_data = ::Parser::Rule;
			using expr_expr_copiable_method_call_data = ::Parser::Rule;
			using expr_data = ::Parser::Rule;
			using function_body_call_data = ::Parser::Rule;
			using function_body_decl_data = ::Parser::Rule;
			using function_arguments_data = ::Parser::arr_t<::Parser::any_t>;
			using function_parameters_data = ::Parser::arr_t<::Parser::any_t>;
			struct cll_function_call_data {
				::Parser::Rule body;
				::Parser::Token name;
			};
			struct function_decl_data {
				::Parser::Rule value;
				::Parser::Token name;
				::Parser::arr_t<::Parser::Token> type;
			};
			struct loop_while_data {
				::Parser::Rule block;
				::Parser::Rule expr;
			};
			struct loop_for_data {
				::Parser::Token block;
				::Parser::Token end;
				::Parser::Token cond;
				::Parser::Rule decl;
			};
			struct method_call_data {
				::Parser::arr_t<::Parser::Rule_res> call;
				::Parser::Token object;
			};
			using copiable_method_call_data = ::Parser::Rule;
			struct var_refer_data {
				::Parser::any_t post;
				::Parser::any_t pre;
				::Parser::Rule brace_expression;
				::Parser::Token name;
			};
			struct cll_var_data {
				::Parser::Rule value;
				::Parser::Rule operator;
				::Parser::Token id;
				::Parser::Rule type;
			};
			using array_data = ::Parser::arr_t<::Parser::Token>;
			struct object_data {
				::Parser::arr_t<::Parser::Rule_res> values;
				::Parser::arr_t<::Parser::Token> keys;
				::Parser::Rule value;
				::Parser::Rule key;
			};
			using spacemode_data = ::Parser::Token;
			struct use_unit_data {
				::Parser::Rule value;
				::Parser::Rule name;
			};
			struct use_data {
				::Parser::arr_t<::Parser::Rule_res> second;
				::Parser::Rule first;
			};
			struct Rule_rule_data {
				::Parser::any_t qualifier;
				::Parser::any_t val;
			};
			struct Rule_other_data {
				::Parser::arr_t<::Parser::Token> nested_name;
				::Parser::Token name;
				::Parser::bool_t is_nested;
			};
			struct Rule_group_data {
				::Parser::any_t val;
				::Parser::any_t variable;
			};
			using Rule_csequence_diapason_data = ::Parser::arr_t<::Parser::any_t>;
			struct Rule_csequence_data {
				::Parser::Rule val;
				::Parser::bool_t _not;
			};
			struct Rule_data_block_key_data {
				::Parser::Rule val;
				::Parser::Token name;
			};
			struct Rule_escaped_data {
				::Parser::Token num;
				::Parser::Token c;
			};
			using Rule_nested_rule_data = ::Parser::Rule;
			using Rule_hex_data = ::Parser::arr_t<::Parser::Token>;
			using Rule_bin_data = ::Parser::arr_t<::Parser::Token>;
			struct Rule_data {
				::Parser::Rule nestedRules;
				::Parser::Rule data_block;
				::Parser::Rule rule;
				::Parser::Token name;
			};
			Rule_res accessor_group(Token*&);
			Rule_res accessor_element(Token*&);
			Rule_res accessor_char(Token*&);
			Rule_res accessor_all(Token*&);
			Rule_res accessor(Token*&);
			Rule_res cll(Token*&);
			Rule_res cll_block(Token*&);
			Rule_res cll_spaced_block(Token*&);
			Rule_res cll_template_content_typename(Token*&);
			Rule_res cll_template_content_int(Token*&);
			Rule_res cll_template_content_bool(Token*&);
			Rule_res cll_template_content_str(Token*&);
			Rule_res cll_template_content_arr(Token*&);
			Rule_res cll_template_content_obj(Token*&);
			Rule_res cll_template_content_any_data(Token*&);
			Rule_res cll_csupport_types(Token*&);
			Rule_res cll_type(Token*&);
			Rule_res cll_type_abstract(Token*&);
			Rule_res cll_if(Token*&);
			Rule_res cll_ternary(Token*&);
			Rule_res expr(Token*&);
			Rule_res expr_logical(Token*&);
			Rule_res expr_compare(Token*&);
			Rule_res expr_arithmetic(Token*&);
			Rule_res expr_for_arithmetic(Token*&);
			Rule_res expr_group(Token*&);
			Rule_res expr_expr_copiable_method_call(Token*&);
			Rule_res function_body_call(Token*&);
			Rule_res function_body_decl(Token*&);
			Rule_res function_arguments(Token*&);
			Rule_res function_parameters(Token*&);
			Rule_res cll_function_call(Token*&);
			Rule_res function_decl(Token*&);
			Rule_res loop_while(Token*&);
			Rule_res loop_for(Token*&);
			Rule_res method_call(Token*&);
			Rule_res copiable_method_call(Token*&);
			Rule_res var_refer(Token*&);
			Rule_res cll_var(Token*&);
			Rule_res array(Token*&);
			Rule_res object(Token*&);
			Rule_res any_data(Token*&);
			Rule_res spacemode(Token*&);
			Rule_res linear_comment(Token*&);
			Rule_res main(Token*&);
			Rule_res use(Token*&);
			Rule_res use_unit(Token*&);
			Rule_res Rule(Token*&);
			Rule_res Rule_rule(Token*&);
			Rule_res Rule_other(Token*&);
			Rule_res Rule_op(Token*&);
			Rule_res Rule_qualifier(Token*&);
			Rule_res Rule_group(Token*&);
			Rule_res Rule_csequence(Token*&);
			Rule_res Rule_csequence_symbol(Token*&);
			Rule_res Rule_csequence_escape(Token*&);
			Rule_res Rule_csequence_diapason(Token*&);
			Rule_res Rule_data_block(Token*&);
			Rule_res Rule_data_block_inclosed_map(Token*&);
			Rule_res Rule_data_block_key(Token*&);
			Rule_res Rule_escaped(Token*&);
			Rule_res Rule_nested_rule(Token*&);
			Rule_res Rule_hex(Token*&);
			Rule_res Rule_bin(Token*&);
	};

}