#pragma once
#include <string>
#include <list>
#include <unordered_map>
#include <iscstdlibc++.h>
#ifndef ISPA_OBJECT_TYPE
#define ISPA_OBJECT_TYPE std::unordered_map
#endif
#ifndef ISPA_ARRAY_TYPE
#define ISPA_ARRAY_TYPE std::list
#endif
#ifndef ISPA_STR_TYPE
#define ISPA_STR_TYPE std::string
#endif
#ifndef ISPA_NUM_TYPE
#define ISPA_NUM_TYPE double
#endif
#ifndef ISPA_ANY_TYPE
#define ISPA_ANY_TYPE std::any
#endif
#ifndef ISPA_BOOLEAN_TYPE
#define ISPA_BOOLEAN_TYPE bool
#endif
namespace Parser {
	using str_t = ISPA_STR_TYPE;
	using num_t = ISPA_NUM_TYPE;
	using bool_t = ISPA_BOOLEAN_TYPE;
	using any_t = ISPA_ANY_TYPE;
	template<typename T>
	using arr_t = ISPA_ARRAY_TYPE<T>;
	template<typename Key, typename Value>
	using obj_t = ISPA_OBJECT_TYPE<Key, Value>;
	enum class Tokens {
		NONE, OP, ASSIGNMENT_OP, COMPARE_OP, LOGICAL_OP, LOGICAL_NOT, LOGICAL_AND, LOGICAL_OR, LOGICAL_ANDR, STRING, NUMBER, BOOLEAN, END, NEWLINE, ID, AUTO_1, AUTO_3, AUTO_4, AUTO_14, AUTO_15, AUTO_16, AUTO_17, AUTO_18, AUTO_19, AUTO_20, AUTO_21, AUTO_22, AUTO_23, AUTO_24, AUTO_25, AUTO_26, AUTO_27, AUTO_28, AUTO_29, AUTO_30, AUTO_31, AUTO_32, AUTO_33, AUTO_34, AUTO_35, AUTO_36, AUTO_48, AUTO_49, AUTO_55, AUTO_60, AUTO_61, AUTO_65, AUTO_70, AUTO_71, AUTO_72, AUTO_73, AUTO_74, AUTO_75, AUTO_76, AUTO_77, AUTO_78, AUTO_82, AUTO_83, AUTO_84, AUTO_85, AUTO_86, AUTO_87, AUTO_88, AUTO_89, AUTO_90, AUTO_91, AUTO_92, AUTO_94, AUTO_95, AUTO_98, AUTO_99, AUTO_101, AUTO_103, AUTO_104, AUTO_105, AUTO_106, AUTO_107, AUTO_108, AUTO_109, AUTO_110, AUTO_111, AUTO_112, AUTO_113
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
		public:
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
	};
	class Parser {
		public:
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