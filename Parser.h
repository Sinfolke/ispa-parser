#pragma once
#ifndef PARSER
#define PARSER

#include <string>
#include <list>
#include <unordered_map>
#include <iscstdlibc++.h>
#include <fstream>
#include <iterator>

#include <optional>

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
	struct Action {
        enum Action_type {
            SHIFT, REDUCE, ACCEPT, DFA_RESOLVE, ERROR 
        };
        Action_type type;
        size_t state;
    };
	using str_t = PARSER_STR_TYPE;
	using num_t = PARSER_NUM_TYPE;
	using bool_t = PARSER_BOOL_TYPE;
	using any_t = PARSER_ANY_TYPE;
	template<typename T>
	using arr_t = PARSER_ARR_TYPE<T>;
	template<typename Key, typename Value>
	using obj_t = PARSER_OBJ_TYPE<Key, Value>;
	enum class Tokens {
		NONE, cll_OP, cll_ASSIGNMENT_OP, cll_COMPARE_OP, cll_LOGICAL_OP, cll_LOGICAL_NOT, cll_LOGICAL_AND, cll_LOGICAL_OR, cll_TYPE, cll_TEMPLATE, STRING, NUMBER, BOOLEAN, END, STRICT_END, NEWLINE, PLUS, MINUS, DIVIDE, MULTIPLE, MODULO, LINEAR_COMMENT, ID, SPACEMODE, NAME, AT, Rule_OP, Rule_CSEQUENCE, Rule_CSEQUENCE_SYMBOL, Rule_CSEQUENCE_ESCAPE, Rule_CSEQUENCE_DIAPASON, Rule_ANY, Rule_NOSPACE, Rule_ESCAPED, Rule_HEX, Rule_BIN, AUTO_0, AUTO_1, AUTO_2, AUTO_3, AUTO_4, AUTO_5, AUTO_6, AUTO_7, AUTO_8, AUTO_9, AUTO_10, AUTO_11, AUTO_12, AUTO_13, AUTO_14, AUTO_15, AUTO_16, AUTO_17, AUTO_18, AUTO_19, AUTO_20, AUTO_21, AUTO_22, AUTO_23, AUTO_24, AUTO_25, AUTO_26, AUTO_27, AUTO_28, AUTO_29, AUTO_30, AUTO_31, AUTO_32, AUTO_33, AUTO_34, AUTO_35, AUTO_36, AUTO_37, AUTO_38, AUTO_39, AUTO_40, AUTO_41, AUTO_42, AUTO_43, AUTO_44, AUTO_45, AUTO_46, AUTO_47, AUTO_48, AUTO_49, AUTO_50, __WHITESPACE
	};
	enum class Rules {
		NONE, cll, cll_if, cll_variable, cll_function_body_call, cll_function_body_decl, cll_function_arguments, cll_function_parameters, cll_cll_function_call, cll_function_decl, cll_expr, cll_expr_logical, cll_expr_compare, cll_expr_arithmetic, cll_expr_term, cll_expr_value, cll_expr_group, cll_expr___rop0, cll_expr___rop2, cll_expr___grp1_tail, cll_expr___grp1, cll_var, cll_block, cll_loop_while, cll_loop_for, cll___grp2, cll___rop0, cll___grp1, cll___q0_tail, cll___q0, cll___q1_tail, cll___q1, cll___q4, array, object, any_data, main, use, use_unit, use___q1, Rule, Rule_rule, Rule_name, Rule_group, Rule_keyvalue, Rule_value, Rule_nested_rule, Rule_data_block, Rule_data_block_regular_datablock, Rule_data_block_regular_datablock_key, Rule_data_block_regular_datablock___q0_tail, Rule_data_block_regular_datablock___q0, Rule_data_block_templated_datablock, Rule_data_block___rop1, Rule_data_block___grp1, Rule_data_block___grp2, Rule_quantifier, Rule___rop1, Rule___q2, Rule___q0, Rule___grp2, Rule___q1_tail, Rule___q1, Rule___grp1, __rop1, __grp0, __grp3, __grp1, __grp2, Rule__q2_tail, Rule__q2, Rule__q3, Rule__q4_tail, Rule__q4, __start
	};
	using Rule = ISPA_STD::Node<Rules>;
	using Rule_res = ISPA_STD::match_result<Rules>;
	using Token = ISPA_STD::Node<Tokens>;
	using Token_res = ISPA_STD::match_result<Tokens>;
	using TokenFlow = ISPA_STD::TokenFlow<Tokens>;
	using Tree = ISPA_STD::Tree<Rules>;
	std::string TokensToString(Tokens token);
	std::string RulesToString(Rules rule);
	using ActionTable = std::array<std::array<std::optional<::Parser::Action>, 88>, 215>;
	using GotoTable = std::array<std::array<std::optional<size_t>, 75>, 215>;
	using RulesTable = std::array<std::pair<Rules, size_t>, 148>;
	using DFATable = std::array<std::pair<::Parser::Action, std::array<size_t, 88>>, 373>;
	namespace Types {
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
		using SPACEMODE_data = ::Parser::str_t;
		using NAME_data = ::Parser::Token;
		using Rule_CSEQUENCE_SYMBOL_data = ::Parser::str_t;
		using Rule_CSEQUENCE_ESCAPE_data = ::Parser::str_t;
		using Rule_CSEQUENCE_DIAPASON_data = ::Parser::arr_t<::Parser::any_t>;
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
		using AUTO_35_data = ::Parser::str_t;
		using AUTO_36_data = ::Parser::str_t;
		using AUTO_37_data = ::Parser::str_t;
		using AUTO_38_data = ::Parser::str_t;
		using AUTO_39_data = ::Parser::str_t;
		using AUTO_40_data = ::Parser::str_t;
		using AUTO_41_data = ::Parser::str_t;
		using AUTO_42_data = ::Parser::str_t;
		using AUTO_43_data = ::Parser::str_t;
		using AUTO_44_data = ::Parser::str_t;
		using AUTO_45_data = ::Parser::str_t;
		using AUTO_46_data = ::Parser::str_t;
		using AUTO_47_data = ::Parser::str_t;
		using AUTO_48_data = ::Parser::str_t;
		using AUTO_49_data = ::Parser::str_t;
		using AUTO_50_data = ::Parser::str_t;
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
            void printToken(std::ostream& os, const Token& token);
		Lexer(const std::string& in) : Lexer_base(in) {}
        Lexer(char*& in) : Lexer_base(in) {}
        Lexer(const char*& in) : Lexer_base(in) {}
        Lexer(TokenFlow &tokens) : Lexer_base(tokens) {}
        Lexer() {}
		private:
			Token_res NONE(const char*);
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
			Token_res STRICT_END(const char*);
			Token_res NEWLINE(const char*);
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
			Token_res Rule_OP(const char*);
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
			Token_res AUTO_21(const char*);
			Token_res AUTO_22(const char*);
			Token_res AUTO_23(const char*);
			Token_res AUTO_24(const char*);
			Token_res AUTO_25(const char*);
			Token_res AUTO_26(const char*);
			Token_res AUTO_27(const char*);
			Token_res AUTO_28(const char*);
			Token_res AUTO_29(const char*);
			Token_res AUTO_30(const char*);
			Token_res AUTO_31(const char*);
			Token_res AUTO_32(const char*);
			Token_res AUTO_33(const char*);
			Token_res AUTO_34(const char*);
			Token_res AUTO_35(const char*);
			Token_res AUTO_36(const char*);
			Token_res AUTO_37(const char*);
			Token_res AUTO_38(const char*);
			Token_res AUTO_39(const char*);
			Token_res AUTO_40(const char*);
			Token_res AUTO_41(const char*);
			Token_res AUTO_42(const char*);
			Token_res AUTO_43(const char*);
			Token_res AUTO_44(const char*);
			Token_res AUTO_45(const char*);
			Token_res AUTO_46(const char*);
			Token_res AUTO_47(const char*);
			Token_res AUTO_48(const char*);
			Token_res AUTO_49(const char*);
			Token_res AUTO_50(const char*);
			Token_res __WHITESPACE(const char*);
	};
	class Parser : public ISPA_STD::ELRParser_base<Tokens, Rules, Action, ActionTable, GotoTable, RulesTable, DFATable> {
		private:
			static ActionTable action_table;
			static GotoTable goto_table;
			static RulesTable rules_table;
			static DFATable dfa_table;
			std::string TokensToString(Tokens token);
			std::string RulesToString(Rules rule);
		void parseFromTokens();
		void lazyParse();
	};

} // Parser


#endif // PARSER
