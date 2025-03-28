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
		NONE, OP, ASSIGNMENT_OP, COMPARE_OP, LOGICAL_OP, LOGICAL_NOT, LOGICAL_AND, LOGICAL_OR, STRING, NUMBER, BOOLEAN, END, NEWLINE, LINEAR_COMMENT, ID, AUTO_1, AUTO_3, AUTO_4, AUTO_8, AUTO_9, AUTO_10, AUTO_11, AUTO_15, AUTO_17, AUTO_18, AUTO_19, AUTO_20, AUTO_21, AUTO_22, AUTO_23, AUTO_24, AUTO_25, AUTO_26, AUTO_39, AUTO_40, AUTO_41, AUTO_47, AUTO_52, AUTO_53, AUTO_57, AUTO_62, AUTO_63, AUTO_64, AUTO_65, AUTO_66, AUTO_67, AUTO_68, AUTO_69, AUTO_73, AUTO_74, AUTO_75, AUTO_76, AUTO_77, AUTO_78, AUTO_79, AUTO_80, AUTO_81, AUTO_82, AUTO_83, AUTO_84, AUTO_88, AUTO_89, AUTO_91, AUTO_93, AUTO_95, AUTO_96, AUTO_97, AUTO_98, AUTO_99, AUTO_100, AUTO_101, AUTO_102, AUTO_103, __WHITESPACE
	};
	enum class Rules {
		NONE, accessor_group, accessor_element, accessor_char, accessor_all, accessor, cll, cll_block, cll_template, cll_csupport_types, cll_type, cll_type_abstract, cll_if, cll_ternary, expr, expr_logical, expr_compare, expr_arithmetic, expr_for_arithmetic, expr_group, expr_expr_copiable_method_call, function_body_call, function_body_decl, function_arguments, function_parameters, cll_function_call, function_decl, loop_while, loop_for, method_call, copiable_method_call, var_refer, cll_var, array, object, any_data, spacemode, name, main, use, use_unit, Rule, Rule_rule, Rule_other, Rule_qualifier, Rule_group, Rule_csequence, Rule_csequence_symbol, Rule_csequence_escape, Rule_csequence_diapason, Rule_data_block, Rule_data_block_inclosed_map, Rule_data_block_key, Rule_escaped, Rule_nested_rule, Rule_hex, Rule_bin
	};
	using Rule = ISPA_STD::node<Rules>;
	using Rule_res = ISPA_STD::match_result<Rules>;
	using Token = ISPA_STD::node<Tokens>;
	using Token_res = ISPA_STD::match_result<Tokens>;
	using TokenFlow = arr_t<Token>;
	using Tree = arr_t<Rules>;
	std::string TokenstoString(Tokens token);
	class Tokenizator : public ISPA_STD::Tokenizator_base<Tokens> {
		public:
			Token makeToken();
		private:
			using OP_data = ::Parser::str_t;
			using ASSIGNMENT_OP_data = ::Parser::Token;
			using COMPARE_OP_data = ::Parser::str_t;
			using LOGICAL_OP_data = ::Parser::Token;
			using STRING_data = ::Parser::str_t;
			struct NUMBER_data {
				::Parser::str_t dec;
				::Parser::str_t main;
				::Parser::str_t sign;
			};
			using BOOLEAN_data = ::Parser::str_t;
			using ID_data = ::Parser::str_t;
			using AUTO_1_data = ::Parser::str_t;
			using AUTO_3_data = ::Parser::str_t;
			using AUTO_4_data = ::Parser::str_t;
			using AUTO_8_data = ::Parser::str_t;
			using AUTO_9_data = ::Parser::str_t;
			using AUTO_10_data = ::Parser::str_t;
			using AUTO_11_data = ::Parser::str_t;
			using AUTO_15_data = ::Parser::str_t;
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
			using AUTO_39_data = ::Parser::str_t;
			using AUTO_40_data = ::Parser::str_t;
			using AUTO_41_data = ::Parser::str_t;
			using AUTO_47_data = ::Parser::str_t;
			using AUTO_52_data = ::Parser::str_t;
			using AUTO_53_data = ::Parser::str_t;
			using AUTO_57_data = ::Parser::str_t;
			using AUTO_62_data = ::Parser::str_t;
			using AUTO_63_data = ::Parser::str_t;
			using AUTO_64_data = ::Parser::str_t;
			using AUTO_65_data = ::Parser::str_t;
			using AUTO_66_data = ::Parser::str_t;
			using AUTO_67_data = ::Parser::str_t;
			using AUTO_68_data = ::Parser::str_t;
			using AUTO_69_data = ::Parser::str_t;
			using AUTO_73_data = ::Parser::str_t;
			using AUTO_74_data = ::Parser::str_t;
			using AUTO_75_data = ::Parser::str_t;
			using AUTO_76_data = ::Parser::str_t;
			using AUTO_77_data = ::Parser::str_t;
			using AUTO_78_data = ::Parser::str_t;
			using AUTO_79_data = ::Parser::str_t;
			using AUTO_80_data = ::Parser::str_t;
			using AUTO_81_data = ::Parser::str_t;
			using AUTO_82_data = ::Parser::str_t;
			using AUTO_83_data = ::Parser::str_t;
			using AUTO_84_data = ::Parser::str_t;
			using AUTO_88_data = ::Parser::str_t;
			using AUTO_89_data = ::Parser::str_t;
			using AUTO_91_data = ::Parser::str_t;
			using AUTO_93_data = ::Parser::str_t;
			using AUTO_95_data = ::Parser::str_t;
			using AUTO_96_data = ::Parser::str_t;
			using AUTO_97_data = ::Parser::str_t;
			using AUTO_98_data = ::Parser::str_t;
			using AUTO_99_data = ::Parser::str_t;
			using AUTO_100_data = ::Parser::str_t;
			using AUTO_101_data = ::Parser::str_t;
			using AUTO_102_data = ::Parser::str_t;
			using AUTO_103_data = ::Parser::str_t;
			Token_res OP(const char*);
			Token_res ASSIGNMENT_OP(const char*);
			Token_res COMPARE_OP(const char*);
			Token_res LOGICAL_OP(const char*);
			Token_res LOGICAL_NOT(const char*);
			Token_res LOGICAL_AND(const char*);
			Token_res LOGICAL_OR(const char*);
			Token_res STRING(const char*);
			Token_res NUMBER(const char*);
			Token_res BOOLEAN(const char*);
			Token_res END(const char*);
			Token_res NEWLINE(const char*);
			Token_res LINEAR_COMMENT(const char*);
			Token_res ID(const char*);
			Token_res AUTO_1(const char*);
			Token_res AUTO_3(const char*);
			Token_res AUTO_4(const char*);
			Token_res AUTO_8(const char*);
			Token_res AUTO_9(const char*);
			Token_res AUTO_10(const char*);
			Token_res AUTO_11(const char*);
			Token_res AUTO_15(const char*);
			Token_res AUTO_17(const char*);
			Token_res AUTO_18(const char*);
			Token_res AUTO_19(const char*);
			Token_res AUTO_20(const char*);
			Token_res AUTO_21(const char*);
			Token_res AUTO_22(const char*);
			Token_res AUTO_23(const char*);
			Token_res AUTO_24(const char*);
			Token_res AUTO_25(const char*);
			Token_res AUTO_26(const char*);
			Token_res AUTO_39(const char*);
			Token_res AUTO_40(const char*);
			Token_res AUTO_41(const char*);
			Token_res AUTO_47(const char*);
			Token_res AUTO_52(const char*);
			Token_res AUTO_53(const char*);
			Token_res AUTO_57(const char*);
			Token_res AUTO_62(const char*);
			Token_res AUTO_63(const char*);
			Token_res AUTO_64(const char*);
			Token_res AUTO_65(const char*);
			Token_res AUTO_66(const char*);
			Token_res AUTO_67(const char*);
			Token_res AUTO_68(const char*);
			Token_res AUTO_69(const char*);
			Token_res AUTO_73(const char*);
			Token_res AUTO_74(const char*);
			Token_res AUTO_75(const char*);
			Token_res AUTO_76(const char*);
			Token_res AUTO_77(const char*);
			Token_res AUTO_78(const char*);
			Token_res AUTO_79(const char*);
			Token_res AUTO_80(const char*);
			Token_res AUTO_81(const char*);
			Token_res AUTO_82(const char*);
			Token_res AUTO_83(const char*);
			Token_res AUTO_84(const char*);
			Token_res AUTO_88(const char*);
			Token_res AUTO_89(const char*);
			Token_res AUTO_91(const char*);
			Token_res AUTO_93(const char*);
			Token_res AUTO_95(const char*);
			Token_res AUTO_96(const char*);
			Token_res AUTO_97(const char*);
			Token_res AUTO_98(const char*);
			Token_res AUTO_99(const char*);
			Token_res AUTO_100(const char*);
			Token_res AUTO_101(const char*);
			Token_res AUTO_102(const char*);
			Token_res AUTO_103(const char*);
			Token_res __WHITESPACE(const char*);
	};
	class Parser {
		public:
			using accessor_group_data = ::Parser::Token;
			using accessor_element_data = ::Parser::Token;
			using accessor_char_data = ::Parser::Token;
			using accessor_all_data = ::Parser::Rule;
			struct accessor_data {
				::Parser::arr_t<::Parser::Rule> second;
				::Parser::Rule first;
			};
			using cll_data = ::Parser::arr_t<::Parser::Rule>;
			using cll_block_data = ::Parser::arr_t<::Parser::Token>;
			struct cll_template_data {
				::Parser::arr_t<::Parser::Rule> second;
				::Parser::Rule first;
			};
			struct cll_csupport_types_data {
				::Parser::Token templ;
				::Parser::Token type;
			};
			struct cll_type_abstract_data {
				::Parser::Token templ;
				::Parser::Token type;
			};
			using cll_type_data = ::Parser::Rule;
			struct cll_if_data {
				::Parser::Rule block;
				::Parser::Rule expr;
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
				::Parser::arr_t<::Parser::Rule> sequence;
				::Parser::arr_t<::Parser::Token> operators;
				::Parser::Rule first;
			};
			struct expr_arithmetic_data {
				::Parser::arr_t<::Parser::Rule> sequence;
				::Parser::arr_t<::Parser::Token> operators;
				::Parser::Rule first;
			};
			using expr_for_arithmetic_data = ::Parser::Rule;
			using expr_group_data = ::Parser::Rule;
			using expr_expr_copiable_method_call_data = ::Parser::Rule;
			using expr_data = ::Parser::Rule;
			using function_body_call_data = ::Parser::Rule;
			using function_body_decl_data = ::Parser::Rule;
			struct function_arguments_data {
				::Parser::arr_t<::Parser::arr_t<::Parser::Token>> second;
				::Parser::any_t first;
			};
			struct function_parameters_data {
				::Parser::arr_t<::Parser::Token> second;
				::Parser::Token first;
			};
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
				::Parser::arr_t<::Parser::Rule> call;
				::Parser::Token object;
			};
			using copiable_method_call_data = ::Parser::Rule;
			struct var_refer_data {
				::Parser::Token post;
				::Parser::Token pre;
				::Parser::Rule brace_expression;
				::Parser::Token name;
			};
			struct cll_var_data {
				::Parser::Rule value;
				::Parser::Token op;
				::Parser::Token id;
				::Parser::Rule type;
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
				::Parser::any_t qualifier;
				::Parser::any_t val;
			};
			struct Rule_other_data {
				::Parser::arr_t<::Parser::Token> nested_name;
				::Parser::Token name;
				::Parser::Token is_nested;
			};
			using Rule_qualifier_data = ::Parser::Token;
			struct Rule_group_data {
				::Parser::Rule val;
				::Parser::Token variable;
			};
			using Rule_csequence_symbol_data = ::Parser::Token;
			using Rule_csequence_escape_data = ::Parser::Token;
			using Rule_csequence_diapason_data = ::Parser::arr_t<::Parser::any_t>;
			struct Rule_csequence_data {
				::Parser::arr_t<::Parser::Rule> val;
				::Parser::Token _not;
			};
			using Rule_data_block_inclosed_map_data = ::Parser::Rule;
			struct Rule_data_block_key_data {
				::Parser::Rule val;
				::Parser::Token name;
			};
			using Rule_data_block_data = ::Parser::Rule;
			struct Rule_escaped_data {
				::Parser::Token num;
				::Parser::Token c;
			};
			using Rule_nested_rule_data = ::Parser::Token;
			using Rule_hex_data = ::Parser::arr_t<::Parser::Token>;
			using Rule_bin_data = ::Parser::arr_t<::Parser::Token>;
			struct Rule_data {
				::Parser::Rule nestedRules;
				::Parser::Rule data_block;
				::Parser::Rule rule;
				::Parser::Token name;
			};
			Rule_res accessor_group(::Parser::arr_t<Token>::iterator pos);
			Rule_res accessor_element(::Parser::arr_t<Token>::iterator pos);
			Rule_res accessor_char(::Parser::arr_t<Token>::iterator pos);
			Rule_res accessor_all(::Parser::arr_t<Token>::iterator pos);
			Rule_res accessor(::Parser::arr_t<Token>::iterator pos);
			Rule_res cll(::Parser::arr_t<Token>::iterator pos);
			Rule_res cll_block(::Parser::arr_t<Token>::iterator pos);
			Rule_res cll_template(::Parser::arr_t<Token>::iterator pos);
			Rule_res cll_csupport_types(::Parser::arr_t<Token>::iterator pos);
			Rule_res cll_type(::Parser::arr_t<Token>::iterator pos);
			Rule_res cll_type_abstract(::Parser::arr_t<Token>::iterator pos);
			Rule_res cll_if(::Parser::arr_t<Token>::iterator pos);
			Rule_res cll_ternary(::Parser::arr_t<Token>::iterator pos);
			Rule_res expr(::Parser::arr_t<Token>::iterator pos);
			Rule_res expr_logical(::Parser::arr_t<Token>::iterator pos);
			Rule_res expr_compare(::Parser::arr_t<Token>::iterator pos);
			Rule_res expr_arithmetic(::Parser::arr_t<Token>::iterator pos);
			Rule_res expr_for_arithmetic(::Parser::arr_t<Token>::iterator pos);
			Rule_res expr_group(::Parser::arr_t<Token>::iterator pos);
			Rule_res expr_expr_copiable_method_call(::Parser::arr_t<Token>::iterator pos);
			Rule_res function_body_call(::Parser::arr_t<Token>::iterator pos);
			Rule_res function_body_decl(::Parser::arr_t<Token>::iterator pos);
			Rule_res function_arguments(::Parser::arr_t<Token>::iterator pos);
			Rule_res function_parameters(::Parser::arr_t<Token>::iterator pos);
			Rule_res cll_function_call(::Parser::arr_t<Token>::iterator pos);
			Rule_res function_decl(::Parser::arr_t<Token>::iterator pos);
			Rule_res loop_while(::Parser::arr_t<Token>::iterator pos);
			Rule_res loop_for(::Parser::arr_t<Token>::iterator pos);
			Rule_res method_call(::Parser::arr_t<Token>::iterator pos);
			Rule_res copiable_method_call(::Parser::arr_t<Token>::iterator pos);
			Rule_res var_refer(::Parser::arr_t<Token>::iterator pos);
			Rule_res cll_var(::Parser::arr_t<Token>::iterator pos);
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
			Rule_res Rule_other(::Parser::arr_t<Token>::iterator pos);
			Rule_res Rule_qualifier(::Parser::arr_t<Token>::iterator pos);
			Rule_res Rule_group(::Parser::arr_t<Token>::iterator pos);
			Rule_res Rule_csequence(::Parser::arr_t<Token>::iterator pos);
			Rule_res Rule_csequence_symbol(::Parser::arr_t<Token>::iterator pos);
			Rule_res Rule_csequence_escape(::Parser::arr_t<Token>::iterator pos);
			Rule_res Rule_csequence_diapason(::Parser::arr_t<Token>::iterator pos);
			Rule_res Rule_data_block(::Parser::arr_t<Token>::iterator pos);
			Rule_res Rule_data_block_inclosed_map(::Parser::arr_t<Token>::iterator pos);
			Rule_res Rule_data_block_key(::Parser::arr_t<Token>::iterator pos);
			Rule_res Rule_escaped(::Parser::arr_t<Token>::iterator pos);
			Rule_res Rule_nested_rule(::Parser::arr_t<Token>::iterator pos);
			Rule_res Rule_hex(::Parser::arr_t<Token>::iterator pos);
			Rule_res Rule_bin(::Parser::arr_t<Token>::iterator pos);
	};

} // Parser


#endif // PARSER
