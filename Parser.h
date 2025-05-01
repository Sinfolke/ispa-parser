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
		NONE, cll_OP, cll_ASSIGNMENT_OP, cll_COMPARE_OP, cll_LOGICAL_OP, cll_LOGICAL_NOT, cll_LOGICAL_AND, cll_LOGICAL_OR, cll_TYPE, cll_TEMPLATE, STRING, NUMBER, BOOLEAN, END, NEWLINE, QUESTION_MARK, PLUS, MINUS, DIVIDE, MULTIPLE, MODULO, LINEAR_COMMENT, ID, SPACEMODE, NAME, AT, Rule_OP, Rule_CSEQUENCE, Rule_CSEQUENCE_SYMBOL, Rule_CSEQUENCE_ESCAPE, Rule_CSEQUENCE_DIAPASON, Rule_NOSPACE, Rule_ESCAPED, Rule_HEX, Rule_BIN, AUTO_0, AUTO_1, AUTO_2, AUTO_3, AUTO_4, AUTO_5, AUTO_6, AUTO_7, AUTO_8, AUTO_9, AUTO_10, AUTO_11, AUTO_12, AUTO_13, AUTO_14, AUTO_15, AUTO_16, AUTO_17, AUTO_18, AUTO_19, AUTO_20, AUTO_21, __WHITESPACE
	};
	enum class Rules {
		NONE, cll, cll_if, cll_variable, cll_function_body_call, cll_function_body_decl, cll_function_arguments, cll_function_parameters, cll_cll_function_call, cll_function_decl, cll_expr, cll_expr_logical, cll_expr_compare, cll_expr_arithmetic, cll_expr_term, cll_expr_value, cll_expr_group, cll_var, cll_block, cll_loop_while, cll_loop_for, array, object, any_data, main, use, use_unit, Rule, Rule_rule, Rule_name, Rule_group, Rule_keyvalue, Rule_value, Rule_nested_rule, Rule_data_block, Rule_data_block_regular_datablock, Rule_data_block_regular_datablock_key, Rule_data_block_templated_datablock, Rule_quantifier
	};
	using Rule = ISPA_STD::Node<Rules>;
	using Rule_res = ISPA_STD::match_result<Rules>;
	using Token = ISPA_STD::Node<Tokens>;
	using Token_res = ISPA_STD::match_result<Tokens>;
	using TokenFlow = ISPA_STD::TokenFlow<Tokens>;
	using Tree = ISPA_STD::Tree<Rules>;
	std::string TokensToString(Tokens token);
	std::string RulesToString(Rules rule);
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
			::Parser::arr_t<::Parser::arr_t<::Parser::Token>> val;
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
			::Parser::arr_t<::Parser::arr_t<::Parser::Token>> sequence;
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
		using cll_expr_data = ::Parser::any_t;
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
		using array_data = ::Parser::arr_t<::Parser::Rule>;
		struct object_data {
			::Parser::arr_t<::Parser::Token> values;
			::Parser::arr_t<::Parser::Token> keys;
			::Parser::Rule value;
			::Parser::Rule key;
		};
		using any_data_data = ::Parser::any_t;
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
		using Rule_data_block_regular_datablock_data = ::Parser::Rule;
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
		::Parser::Types::cll_OP_data cll_OP(::Parser::Token &token);
		::Parser::Types::cll_ASSIGNMENT_OP_data cll_ASSIGNMENT_OP(::Parser::Token &token);
		::Parser::Types::cll_COMPARE_OP_data cll_COMPARE_OP(::Parser::Token &token);
		::Parser::Types::cll_LOGICAL_OP_data cll_LOGICAL_OP(::Parser::Token &token);
		::Parser::Types::cll_TYPE_data cll_TYPE(::Parser::Token &token);
		::Parser::Types::cll_TEMPLATE_data cll_TEMPLATE(::Parser::Token &token);
		::Parser::Types::STRING_data STRING(::Parser::Token &token);
		::Parser::Types::NUMBER_data NUMBER(::Parser::Token &token);
		::Parser::Types::BOOLEAN_data BOOLEAN(::Parser::Token &token);
		::Parser::Types::ID_data ID(::Parser::Token &token);
		::Parser::Types::SPACEMODE_data SPACEMODE(::Parser::Token &token);
		::Parser::Types::NAME_data NAME(::Parser::Token &token);
		::Parser::Types::Rule_CSEQUENCE_SYMBOL_data Rule_CSEQUENCE_SYMBOL(::Parser::Token &token);
		::Parser::Types::Rule_CSEQUENCE_ESCAPE_data Rule_CSEQUENCE_ESCAPE(::Parser::Token &token);
		::Parser::Types::Rule_CSEQUENCE_DIAPASON_data Rule_CSEQUENCE_DIAPASON(::Parser::Token &token);
		::Parser::Types::Rule_CSEQUENCE_data Rule_CSEQUENCE(::Parser::Token &token);
		::Parser::Types::Rule_ESCAPED_data Rule_ESCAPED(::Parser::Token &token);
		::Parser::Types::Rule_HEX_data Rule_HEX(::Parser::Token &token);
		::Parser::Types::Rule_BIN_data Rule_BIN(::Parser::Token &token);
		::Parser::Types::AUTO_0_data AUTO_0(::Parser::Token &token);
		::Parser::Types::AUTO_1_data AUTO_1(::Parser::Token &token);
		::Parser::Types::AUTO_2_data AUTO_2(::Parser::Token &token);
		::Parser::Types::AUTO_3_data AUTO_3(::Parser::Token &token);
		::Parser::Types::AUTO_4_data AUTO_4(::Parser::Token &token);
		::Parser::Types::AUTO_5_data AUTO_5(::Parser::Token &token);
		::Parser::Types::AUTO_6_data AUTO_6(::Parser::Token &token);
		::Parser::Types::AUTO_7_data AUTO_7(::Parser::Token &token);
		::Parser::Types::AUTO_8_data AUTO_8(::Parser::Token &token);
		::Parser::Types::AUTO_9_data AUTO_9(::Parser::Token &token);
		::Parser::Types::AUTO_10_data AUTO_10(::Parser::Token &token);
		::Parser::Types::AUTO_11_data AUTO_11(::Parser::Token &token);
		::Parser::Types::AUTO_12_data AUTO_12(::Parser::Token &token);
		::Parser::Types::AUTO_13_data AUTO_13(::Parser::Token &token);
		::Parser::Types::AUTO_14_data AUTO_14(::Parser::Token &token);
		::Parser::Types::AUTO_15_data AUTO_15(::Parser::Token &token);
		::Parser::Types::AUTO_16_data AUTO_16(::Parser::Token &token);
		::Parser::Types::AUTO_17_data AUTO_17(::Parser::Token &token);
		::Parser::Types::AUTO_18_data AUTO_18(::Parser::Token &token);
		::Parser::Types::AUTO_19_data AUTO_19(::Parser::Token &token);
		::Parser::Types::AUTO_20_data AUTO_20(::Parser::Token &token);
		::Parser::Types::AUTO_21_data AUTO_21(::Parser::Token &token);
		::Parser::Types::cll_if_data cll_if(::Parser::Rule &rule);
		::Parser::Types::cll_variable_data cll_variable(::Parser::Rule &rule);
		::Parser::Types::cll_function_body_call_data cll_function_body_call(::Parser::Rule &rule);
		::Parser::Types::cll_function_body_decl_data cll_function_body_decl(::Parser::Rule &rule);
		::Parser::Types::cll_function_arguments_data cll_function_arguments(::Parser::Rule &rule);
		::Parser::Types::cll_function_parameters_data cll_function_parameters(::Parser::Rule &rule);
		::Parser::Types::cll_cll_function_call_data cll_cll_function_call(::Parser::Rule &rule);
		::Parser::Types::cll_function_decl_data cll_function_decl(::Parser::Rule &rule);
		::Parser::Types::cll_expr_logical_data cll_expr_logical(::Parser::Rule &rule);
		::Parser::Types::cll_expr_compare_data cll_expr_compare(::Parser::Rule &rule);
		::Parser::Types::cll_expr_arithmetic_data cll_expr_arithmetic(::Parser::Rule &rule);
		::Parser::Types::cll_expr_term_data cll_expr_term(::Parser::Rule &rule);
		::Parser::Types::cll_expr_value_data cll_expr_value(::Parser::Rule &rule);
		::Parser::Types::cll_expr_group_data cll_expr_group(::Parser::Rule &rule);
		::Parser::Types::cll_expr_data cll_expr(::Parser::Rule &rule);
		::Parser::Types::cll_var_data cll_var(::Parser::Rule &rule);
		::Parser::Types::cll_block_data cll_block(::Parser::Rule &rule);
		::Parser::Types::cll_loop_while_data cll_loop_while(::Parser::Rule &rule);
		::Parser::Types::cll_loop_for_data cll_loop_for(::Parser::Rule &rule);
		::Parser::Types::array_data array(::Parser::Rule &rule);
		::Parser::Types::object_data object(::Parser::Rule &rule);
		::Parser::Types::any_data_data any_data(::Parser::Rule &rule);
		::Parser::Types::use_unit_data use_unit(::Parser::Rule &rule);
		::Parser::Types::use_data use(::Parser::Rule &rule);
		::Parser::Types::Rule_rule_data Rule_rule(::Parser::Rule &rule);
		::Parser::Types::Rule_name_data Rule_name(::Parser::Rule &rule);
		::Parser::Types::Rule_group_data Rule_group(::Parser::Rule &rule);
		::Parser::Types::Rule_keyvalue_data Rule_keyvalue(::Parser::Rule &rule);
		::Parser::Types::Rule_value_data Rule_value(::Parser::Rule &rule);
		::Parser::Types::Rule_nested_rule_data Rule_nested_rule(::Parser::Rule &rule);
		::Parser::Types::Rule_data_block_regular_datablock_key_data Rule_data_block_regular_datablock_key(::Parser::Rule &rule);
		::Parser::Types::Rule_data_block_regular_datablock_data Rule_data_block_regular_datablock(::Parser::Rule &rule);
		::Parser::Types::Rule_data_block_templated_datablock_data Rule_data_block_templated_datablock(::Parser::Rule &rule);
		::Parser::Types::Rule_data_block_data Rule_data_block(::Parser::Rule &rule);
		::Parser::Types::Rule_quantifier_data Rule_quantifier(::Parser::Rule &rule);
		::Parser::Types::Rule_data Rule(::Parser::Rule &rule);
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
			Token_res AUTO_21(const char*);
			Token_res __WHITESPACE(const char*);
	};
	class Parser : public ISPA_STD::LLParser_base<Tokens, Rules> {
		Rule_res getRule(Lexer::lazy_iterator&);
		Rule_res getRule(Lexer::iterator&);
		void parseFromTokens();
		void lazyParse();
		template <class IT>
		::Parser::Rule_res cll_if(IT pos) {
			auto in = pos;
			skip_spaces(pos);

std::cout << "running " << "cll_if" << ", pos: " << pos->startpos() << "\n";
;
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Rule_res _2;
			::Parser::bool_t success_3 = false;
			::Parser::Rule_res _4;
			::Parser::bool_t success_5 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_1))
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


std::cout << "success run cll_if\n";
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_if, data)};
		}
		template <class IT>
		::Parser::Rule_res cll_variable(IT pos) {
			auto in = pos;
			skip_spaces(pos);

std::cout << "running " << "cll_variable" << ", pos: " << pos->startpos() << "\n";
;
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Token _2;
			::Parser::bool_t success_3 = false;
			::Parser::Token _4;
			::Parser::bool_t success_5 = false;
			::Parser::Token _6;
			::Parser::bool_t success_7 = false;
			::Parser::Token _8;
			::Parser::bool_t success_9 = false;
			::Parser::bool_t success_11 = false;
			::Parser::Token _12;
			::Parser::bool_t success_13 = false;
			::Parser::Rule_res _14;
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
			auto begin_2 = pos;
			do
			{
				if (!(begin_2->name() == ::Parser::Tokens::AUTO_2))
				{
					if (!(begin_2->name() == ::Parser::Tokens::AUTO_3))
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
				if (!(begin_12->name() == ::Parser::Tokens::AUTO_4))
				{
					reportError(pos, "auto_4");
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
				if (!(begin_12->name() == ::Parser::Tokens::AUTO_5))
				{
					reportError(pos, "auto_5");
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
				if (!(begin_20->name() == ::Parser::Tokens::AUTO_2))
				{
					if (!(begin_20->name() == ::Parser::Tokens::AUTO_3))
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


std::cout << "success run cll_variable\n";
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_variable, data)};
		}
		template <class IT>
		::Parser::Rule_res cll_function_body_call(IT pos) {
			auto in = pos;
			skip_spaces(pos);

std::cout << "running " << "cll_function_body_call" << ", pos: " << pos->startpos() << "\n";
;
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Rule_res _2;
			::Parser::bool_t success_3 = false;
			::Parser::Token _4;
			::Parser::bool_t success_5 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_6))
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
			if (!(pos->name() == ::Parser::Tokens::AUTO_7))
			{
				reportError(pos, "auto_7");
				return {};
			}
			_4 = *pos;
			success_5 = true;
			pos += 1;
			::Parser::Types::cll_function_body_call_data data = _2.node;

std::cout << "success run cll_function_body_call\n";
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_function_body_call, data)};
		}
		template <class IT>
		::Parser::Rule_res cll_function_body_decl(IT pos) {
			auto in = pos;
			skip_spaces(pos);

std::cout << "running " << "cll_function_body_decl" << ", pos: " << pos->startpos() << "\n";
;
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Rule_res _2;
			::Parser::bool_t success_3 = false;
			::Parser::Token _4;
			::Parser::bool_t success_5 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_6))
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
			if (!(pos->name() == ::Parser::Tokens::AUTO_7))
			{
				reportError(pos, "auto_7");
				return {};
			}
			_4 = *pos;
			success_5 = true;
			pos += 1;
			::Parser::Types::cll_function_body_decl_data data = _2.node;

std::cout << "success run cll_function_body_decl\n";
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_function_body_decl, data)};
		}
		template <class IT>
		::Parser::Rule_res cll_function_arguments(IT pos) {
			auto in = pos;
			skip_spaces(pos);

std::cout << "running " << "cll_function_arguments" << ", pos: " << pos->startpos() << "\n";
;
			::Parser::bool_t success_1 = false;
			::Parser::any_t _2;
			::Parser::bool_t success_3 = false;
			::Parser::Rule_res _4;
			::Parser::bool_t success_5 = false;
			::Parser::Token _6;
			::Parser::bool_t success_7 = false;
			::Parser::arr_t<::Parser::Token> _8;
			::Parser::bool_t success_9 = false;
			::Parser::arr_t<::Parser::Token> _10;
			::Parser::bool_t success_11 = false;
			::Parser::Token _12;
			::Parser::bool_t success_13 = false;
			::Parser::arr_t<::Parser::Token> shadow_14;
			::Parser::arr_t<::Parser::arr_t<::Parser::Token>> shadow_15;
			auto begin_2 = pos;
			_4 = any_data(begin_2);
			if (!(_4.status))
			{
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
				if (!(begin_10->name() == ::Parser::Tokens::AUTO_8))
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


std::cout << "success run cll_function_arguments\n";
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_function_arguments, data)};
		}
		template <class IT>
		::Parser::Rule_res cll_function_parameters(IT pos) {
			auto in = pos;
			skip_spaces(pos);

std::cout << "running " << "cll_function_parameters" << ", pos: " << pos->startpos() << "\n";
;
			::Parser::bool_t success_1 = false;
			::Parser::Token _2;
			::Parser::bool_t success_3 = false;
			::Parser::bool_t success_5 = false;
			::Parser::Token _6;
			::Parser::bool_t success_7 = false;
			::Parser::arr_t<::Parser::Token> shadow_8;
			::Parser::Token _9;
			::Parser::bool_t success_10 = false;
			::Parser::arr_t<::Parser::Token> shadow_11;
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
				if (!(begin_6->name() == ::Parser::Tokens::AUTO_8))
				{
					reportError(pos, "auto_8");
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


std::cout << "success run cll_function_parameters\n";
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_function_parameters, data)};
		}
		template <class IT>
		::Parser::Rule_res cll_cll_function_call(IT pos) {
			auto in = pos;
			skip_spaces(pos);

std::cout << "running " << "cll_cll_function_call" << ", pos: " << pos->startpos() << "\n";
;
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Rule_res _2;
			::Parser::bool_t success_3 = false;
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


std::cout << "success run cll_cll_function_call\n";
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_cll_function_call, data)};
		}
		template <class IT>
		::Parser::Rule_res cll_function_decl(IT pos) {
			auto in = pos;
			skip_spaces(pos);

std::cout << "running " << "cll_function_decl" << ", pos: " << pos->startpos() << "\n";
;
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Token _2;
			::Parser::bool_t success_3 = false;
			::Parser::Token _4;
			::Parser::bool_t success_5 = false;
			::Parser::arr_t<::Parser::Token> shadow_6;
			::Parser::bool_t success_7 = false;
			::Parser::Rule_res _8;
			::Parser::bool_t success_9 = false;
			::Parser::Rule _10;
			::Parser::Rule val;
			::Parser::bool_t success_11 = false;
			::Parser::Rule_res _12;
			::Parser::bool_t success_13 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_9))
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


std::cout << "success run cll_function_decl\n";
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_function_decl, data)};
		}
		template <class IT>
		::Parser::Rule_res cll_expr_logical(IT pos) {
			auto in = pos;
			skip_spaces(pos);

std::cout << "running " << "cll_expr_logical" << ", pos: " << pos->startpos() << "\n";
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
			::Parser::Token _10;
			::Parser::bool_t success_11 = false;
			::Parser::Rule _12;
			::Parser::bool_t success_13 = false;
			::Parser::Rule_res _14;
			::Parser::bool_t success_15 = false;
			::Parser::Rule_res _16;
			::Parser::bool_t success_17 = false;
			::Parser::Rule_res _18;
			::Parser::bool_t success_19 = false;
			::Parser::Rule_res _20;
			::Parser::bool_t success_21 = false;
			_2 = cll_expr_compare(pos);
			if (!(_2.status))
			{
				_4 = cll_expr_arithmetic(pos);
				if (!(_4.status))
				{
					_6 = cll_expr_term(pos);
					if (!(_6.status))
					{
						_8 = cll_expr_value(pos);
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
			skip_spaces(pos);
			if (!(pos->name() == ::Parser::Tokens::cll_LOGICAL_OP))
			{
				reportError(pos, "logical_op");
				return {};
			}
			_10 = *pos;
			success_11 = true;
			pos += 1;
			skip_spaces(pos);
			_14 = cll_expr_compare(pos);
			if (!(_14.status))
			{
				_16 = cll_expr_arithmetic(pos);
				if (!(_16.status))
				{
					_18 = cll_expr_term(pos);
					if (!(_18.status))
					{
						_20 = cll_expr_value(pos);
						if (!(_20.status))
						{
							return {};
						}
						else 
						{
							success_21 = true;
							pos += _20.node.length();
							_12 = _20.node;
						}
					}
					else 
					{
						success_19 = true;
						pos += _18.node.length();
						_12 = _18.node;
					}
				}
				else 
				{
					success_17 = true;
					pos += _16.node.length();
					_12 = _16.node;
				}
			}
			else 
			{
				success_15 = true;
				pos += _14.node.length();
				_12 = _14.node;
			}
			success_13 = true;
			::Parser::Types::cll_expr_logical_data data;
			data.right = _12;
			data.op = _10;
			data.left = _0;


std::cout << "success run cll_expr_logical\n";
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_expr_logical, data)};
		}
		template <class IT>
		::Parser::Rule_res cll_expr_compare(IT pos) {
			auto in = pos;
			skip_spaces(pos);

std::cout << "running " << "cll_expr_compare" << ", pos: " << pos->startpos() << "\n";
;
			::Parser::Rule _0;
			::Parser::bool_t success_1 = false;
			::Parser::Rule_res _2;
			::Parser::bool_t success_3 = false;
			::Parser::Rule_res _4;
			::Parser::bool_t success_5 = false;
			::Parser::arr_t<::Parser::Token> _6;
			::Parser::bool_t success_7 = false;
			::Parser::bool_t success_14 = false;
			::Parser::arr_t<::Parser::Token> _8;
			::Parser::bool_t success_9 = false;
			::Parser::Token _10;
			::Parser::bool_t success_11 = false;
			::Parser::arr_t<::Parser::Token> shadow_12;
			::Parser::arr_t<::Parser::arr_t<::Parser::Token>> shadow_13;
			_2 = cll_expr_arithmetic(pos);
			if (!(_2.status))
			{
				_4 = cll_expr_term(pos);
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
			skip_spaces(pos);
			auto begin_8 = pos;
			while (1)
			{
				if (!(begin_8->name() == ::Parser::Tokens::cll_COMPARE_OP))
				{
					break;
				}
				else 
				{
					_10 = *begin_8;
					success_11 = true;
					begin_8 += 1;
					shadow_12.push_back(_10);
					_8.push_back(_10);
				}
				success_9 = true;
				_6 = _8;
				shadow_13.push_back(_6);
				success_14 = true;
			}
			if (!success_14)
			{
				reportError(pos, "compare_op");
				return {};
			}
			if (success_9)
			{
				success_7 = true;
				pos = begin_8;
			}
			::Parser::Types::cll_expr_compare_data data;
			data.sequence = shadow_13;
			data.operators = _8;
			data.first = _0;


std::cout << "success run cll_expr_compare\n";
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_expr_compare, data)};
		}
		template <class IT>
		::Parser::Rule_res cll_expr_arithmetic(IT pos) {
			auto in = pos;
			skip_spaces(pos);

std::cout << "running " << "cll_expr_arithmetic" << ", pos: " << pos->startpos() << "\n";
;
			::Parser::Rule_res _0;
			::Parser::bool_t success_1 = false;
			::Parser::bool_t success_3 = false;
			::Parser::bool_t success_15 = false;
			::Parser::arr_t<::Parser::Token> _4;
			::Parser::bool_t success_5 = false;
			::Parser::Token _6;
			::Parser::bool_t success_7 = false;
			::Parser::arr_t<::Parser::Token> shadow_8;
			::Parser::Token _9;
			::Parser::bool_t success_10 = false;
			::Parser::arr_t<::Parser::Token> shadow_11;
			::Parser::Rule_res _12;
			::Parser::bool_t success_13 = false;
			::Parser::arr_t<::Parser::Rule> shadow_14;
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
				if (!(begin_4->name() == ::Parser::Tokens::MINUS))
				{
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
				success_15 = true;
			}
			if (!success_15)
			{
				reportError(pos, "minus or plus");
				return {};
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


std::cout << "success run cll_expr_arithmetic\n";
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_expr_arithmetic, data)};
		}
		template <class IT>
		::Parser::Rule_res cll_expr_term(IT pos) {
			auto in = pos;
			skip_spaces(pos);

std::cout << "running " << "cll_expr_term" << ", pos: " << pos->startpos() << "\n";
;
			::Parser::Rule_res _0;
			::Parser::bool_t success_1 = false;
			::Parser::bool_t success_3 = false;
			::Parser::bool_t success_18 = false;
			::Parser::arr_t<::Parser::Token> _4;
			::Parser::bool_t success_5 = false;
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
			::Parser::bool_t success_16 = false;
			::Parser::arr_t<::Parser::Rule> shadow_17;
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
				if (!(begin_4->name() == ::Parser::Tokens::DIVIDE))
				{
					if (!(begin_4->name() == ::Parser::Tokens::MULTIPLE))
					{
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
				success_18 = true;
			}
			if (!success_18)
			{
				reportError(pos, "divide or multiple or modulo");
				return {};
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


std::cout << "success run cll_expr_term\n";
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_expr_term, data)};
		}
		template <class IT>
		::Parser::Rule_res cll_expr_value(IT pos) {
			auto in = pos;
			skip_spaces(pos);

std::cout << "running " << "cll_expr_value" << ", pos: " << pos->startpos() << "\n";
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
			_2 = cll_variable(pos);
			if (!(_2.status))
			{
				_4 = cll_expr_group(pos);
				if (!(_4.status))
				{
					_6 = any_data(pos);
					if (!(_6.status))
					{
						_8 = cll_cll_function_call(pos);
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

std::cout << "success run cll_expr_value\n";
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_expr_value, data)};
		}
		template <class IT>
		::Parser::Rule_res cll_expr_group(IT pos) {
			auto in = pos;
			skip_spaces(pos);

std::cout << "running " << "cll_expr_group" << ", pos: " << pos->startpos() << "\n";
;
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Rule_res _2;
			::Parser::bool_t success_3 = false;
			::Parser::Token _4;
			::Parser::bool_t success_5 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_6))
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
			if (!(pos->name() == ::Parser::Tokens::AUTO_7))
			{
				reportError(pos, "auto_7");
				return {};
			}
			_4 = *pos;
			success_5 = true;
			pos += 1;
			::Parser::Types::cll_expr_group_data data = _2.node;

std::cout << "success run cll_expr_group\n";
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_expr_group, data)};
		}
		template <class IT>
		::Parser::Rule_res cll_expr(IT pos) {
			auto in = pos;
			skip_spaces(pos);

std::cout << "running " << "cll_expr" << ", pos: " << pos->startpos() << "\n";
;
			::Parser::any_t _0;
			::Parser::bool_t success_1 = false;
			::Parser::Token _2;
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
			if (!(pos->name() == ::Parser::Tokens::AT))
			{
				_4 = cll_expr_logical(pos);
				if (!(_4.status))
				{
					_6 = cll_expr_compare(pos);
					if (!(_6.status))
					{
						_8 = cll_expr_arithmetic(pos);
						if (!(_8.status))
						{
							_10 = cll_expr_term(pos);
							if (!(_10.status))
							{
								_12 = cll_expr_value(pos);
								if (!(_12.status))
								{
									return {};
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
				_2 = *pos;
				success_3 = true;
				pos += 1;
				_0 = _2;
			}
			success_1 = true;
			::Parser::Types::cll_expr_data data = _0;

std::cout << "success run cll_expr\n";
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_expr, data)};
		}
		template <class IT>
		::Parser::Rule_res cll_var(IT pos) {
			auto in = pos;
			skip_spaces(pos);

std::cout << "running " << "cll_var" << ", pos: " << pos->startpos() << "\n";
;
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Token _2;
			::Parser::bool_t success_3 = false;
			::Parser::bool_t success_5 = false;
			::Parser::Token _6;
			::Parser::bool_t success_7 = false;
			::Parser::Rule_res _8;
			::Parser::bool_t success_9 = false;
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


std::cout << "success run cll_var\n";
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_var, data)};
		}
		template <class IT>
		::Parser::Rule_res cll_block(IT pos) {
			auto in = pos;
			skip_spaces(pos);

std::cout << "running " << "cll_block" << ", pos: " << pos->startpos() << "\n";
;
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Rule_res _2;
			::Parser::bool_t success_3 = false;
			::Parser::arr_t<::Parser::Rule> shadow_4;
			::Parser::Token _5;
			::Parser::bool_t success_6 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_10))
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
			if (!(pos->name() == ::Parser::Tokens::AUTO_11))
			{
				reportError(pos, "auto_11");
				return {};
			}
			_5 = *pos;
			success_6 = true;
			pos += 1;
			::Parser::Types::cll_block_data data = shadow_4;

std::cout << "success run cll_block\n";
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_block, data)};
		}
		template <class IT>
		::Parser::Rule_res cll_loop_while(IT pos) {
			auto in = pos;
			skip_spaces(pos);

std::cout << "running " << "cll_loop_while" << ", pos: " << pos->startpos() << "\n";
;
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Rule_res _2;
			::Parser::bool_t success_3 = false;
			::Parser::Rule_res _4;
			::Parser::bool_t success_5 = false;
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


std::cout << "success run cll_loop_while\n";
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_loop_while, data)};
		}
		template <class IT>
		::Parser::Rule_res cll_loop_for(IT pos) {
			auto in = pos;
			skip_spaces(pos);

std::cout << "running " << "cll_loop_for" << ", pos: " << pos->startpos() << "\n";
;
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Token _2;
			::Parser::bool_t success_3 = false;
			::Parser::Rule _4;
			::Parser::bool_t success_5 = false;
			::Parser::Rule _6;
			::Parser::bool_t success_7 = false;
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
			if (!(pos->name() == ::Parser::Tokens::AUTO_13))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			if (!(pos->name() == ::Parser::Tokens::AUTO_6))
			{
				reportError(pos, "auto_6");
				return {};
			}
			_2 = *pos;
			success_3 = true;
			pos += 1;
			skip_spaces(pos);
			auto begin_6 = pos;
			do
			{
				_8 = cll_expr(begin_6);
				if (!(_8.status))
				{
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
			if (!(pos->name() == ::Parser::Tokens::AUTO_14))
			{
				reportError(pos, "auto_14");
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
			if (!(pos->name() == ::Parser::Tokens::AUTO_14))
			{
				reportError(pos, "auto_14");
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
			if (!(pos->name() == ::Parser::Tokens::AUTO_7))
			{
				reportError(pos, "auto_7");
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


std::cout << "success run cll_loop_for\n";
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_loop_for, data)};
		}
		template <class IT>
		::Parser::Rule_res cll(IT pos) {
			auto in = pos;
			skip_spaces(pos);

std::cout << "running " << "cll" << ", pos: " << pos->startpos() << "\n";
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
			if (!(pos->name() == ::Parser::Tokens::AUTO_0))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			_4 = cll_loop_while(pos);
			if (!(_4.status))
			{
				_6 = cll_loop_for(pos);
				if (!(_6.status))
				{
					_8 = cll_if(pos);
					if (!(_8.status))
					{
						_10 = cll_expr(pos);
						if (!(_10.status))
						{
							_12 = cll_var(pos);
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

std::cout << "success run cll\n";
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll)};
		}
		template <class IT>
		::Parser::Rule_res array(IT pos) {
			auto in = pos;
			skip_spaces(pos);

std::cout << "running " << "array" << ", pos: " << pos->startpos() << "\n";
;
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::bool_t success_3 = false;
			::Parser::bool_t success_5 = false;
			::Parser::Rule_res _6;
			::Parser::bool_t success_7 = false;
			::Parser::arr_t<::Parser::Rule> shadow_8;
			::Parser::Token _9;
			::Parser::bool_t success_10 = false;
			::Parser::arr_t<::Parser::Token> shadow_11;
			::Parser::Token _12;
			::Parser::bool_t success_13 = false;
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
					if (!(begin_6->name() == ::Parser::Tokens::AUTO_8))
					{
						reportError(pos, "auto_8");
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
			if (!(pos->name() == ::Parser::Tokens::AUTO_5))
			{
				reportError(pos, "auto_5");
				return {};
			}
			_12 = *pos;
			success_13 = true;
			pos += 1;
			::Parser::Types::array_data data = shadow_8;

std::cout << "success run array\n";
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::array, data)};
		}
		template <class IT>
		::Parser::Rule_res object(IT pos) {
			auto in = pos;
			skip_spaces(pos);

std::cout << "running " << "object" << ", pos: " << pos->startpos() << "\n";
;
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::bool_t success_3 = false;
			::Parser::Rule_res _4;
			::Parser::bool_t success_5 = false;
			::Parser::Token _6;
			::Parser::bool_t success_7 = false;
			::Parser::Rule_res _8;
			::Parser::bool_t success_9 = false;
			::Parser::bool_t success_11 = false;
			::Parser::Token _12;
			::Parser::bool_t success_13 = false;
			::Parser::arr_t<::Parser::Token> shadow_14;
			::Parser::Token _15;
			::Parser::bool_t success_16 = false;
			::Parser::arr_t<::Parser::Token> shadow_17;
			::Parser::Token _18;
			::Parser::bool_t success_19 = false;
			::Parser::arr_t<::Parser::Token> shadow_20;
			::Parser::Rule_res _21;
			::Parser::bool_t success_22 = false;
			::Parser::arr_t<::Parser::Rule> shadow_23;
			::Parser::Token _24;
			::Parser::bool_t success_25 = false;
			::Parser::Token _26;
			::Parser::bool_t success_27 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_10))
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
				_4 = any_data(begin_4);
				if (!(_4.status))
				{
					reportError(pos, "any_data");
					break;
				}
				success_5 = true;
				begin_4 += _4.node.length();
				skip_spaces(begin_4);
				if (!(begin_4->name() == ::Parser::Tokens::AUTO_15))
				{
					reportError(pos, "auto_15");
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
					if (!(begin_12->name() == ::Parser::Tokens::AUTO_8))
					{
						reportError(pos, "auto_8");
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
					if (!(begin_12->name() == ::Parser::Tokens::AUTO_15))
					{
						reportError(pos, "auto_15");
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
				if (!(begin_4->name() == ::Parser::Tokens::AUTO_14))
				{
					reportError(pos, "auto_14");
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
			if (!(pos->name() == ::Parser::Tokens::AUTO_11))
			{
				reportError(pos, "auto_11");
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


std::cout << "success run object\n";
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::object, data)};
		}
		template <class IT>
		::Parser::Rule_res any_data(IT pos) {
			auto in = pos;
			skip_spaces(pos);

std::cout << "running " << "any_data" << ", pos: " << pos->startpos() << "\n";
;
			::Parser::any_t _0;
			::Parser::bool_t success_1 = false;
			::Parser::Rule_res _2;
			::Parser::bool_t success_3 = false;
			::Parser::Rule_res _4;
			::Parser::bool_t success_5 = false;
			::Parser::Token _6;
			::Parser::bool_t success_7 = false;
			::Parser::Token _8;
			::Parser::bool_t success_9 = false;
			::Parser::Token _10;
			::Parser::bool_t success_11 = false;
			::Parser::Token _12;
			::Parser::bool_t success_13 = false;
			::Parser::Token _14;
			::Parser::bool_t success_15 = false;
			_2 = object(pos);
			if (!(_2.status))
			{
				_4 = array(pos);
				if (!(_4.status))
				{
					if (!(pos->name() == ::Parser::Tokens::AT))
					{
						if (!(pos->name() == ::Parser::Tokens::ID))
						{
							if (!(pos->name() == ::Parser::Tokens::BOOLEAN))
							{
								if (!(pos->name() == ::Parser::Tokens::STRING))
								{
									if (!(pos->name() == ::Parser::Tokens::NUMBER))
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
									_12 = *pos;
									success_13 = true;
									pos += 1;
									_0 = _12;
								}
							}
							else 
							{
								_10 = *pos;
								success_11 = true;
								pos += 1;
								_0 = _10;
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
			::Parser::Types::any_data_data data = _0;

std::cout << "success run any_data\n";
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::any_data, data)};
		}
		template <class IT>
		::Parser::Rule_res main(IT pos) {
			auto in = pos;
			skip_spaces(pos);

std::cout << "running " << "main" << ", pos: " << pos->startpos() << "\n";
;
			::Parser::any_t _0;
			::Parser::bool_t success_1 = false;
			::Parser::Token _2;
			::Parser::bool_t success_3 = false;
			::Parser::Token _4;
			::Parser::bool_t success_5 = false;
			::Parser::Rule_res _6;
			::Parser::bool_t success_7 = false;
			::Parser::Rule_res _8;
			::Parser::bool_t success_9 = false;
			if (!(pos->name() == ::Parser::Tokens::SPACEMODE))
			{
				if (!(pos->name() == ::Parser::Tokens::NAME))
				{
					_6 = use(pos);
					if (!(_6.status))
					{
						_8 = Rule(pos);
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

std::cout << "success run main\n";
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::main)};
		}
		template <class IT>
		::Parser::Rule_res use_unit(IT pos) {
			auto in = pos;
			skip_spaces(pos);

std::cout << "running " << "use_unit" << ", pos: " << pos->startpos() << "\n";
;
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Rule_res _2;
			::Parser::bool_t success_3 = false;
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


std::cout << "success run use_unit\n";
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::use_unit, data)};
		}
		template <class IT>
		::Parser::Rule_res use(IT pos) {
			auto in = pos;
			skip_spaces(pos);

std::cout << "running " << "use" << ", pos: " << pos->startpos() << "\n";
;
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Rule_res _2;
			::Parser::bool_t success_3 = false;
			::Parser::bool_t success_5 = false;
			::Parser::Token _6;
			::Parser::bool_t success_7 = false;
			::Parser::arr_t<::Parser::Token> shadow_8;
			::Parser::Rule_res _9;
			::Parser::bool_t success_10 = false;
			::Parser::arr_t<::Parser::Rule> shadow_11;
			if (!(pos->name() == ::Parser::Tokens::AUTO_16))
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
				if (!(begin_6->name() == ::Parser::Tokens::AUTO_8))
				{
					reportError(pos, "auto_8");
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


std::cout << "success run use\n";
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::use, data)};
		}
		template <class IT>
		::Parser::Rule_res Rule_rule(IT pos) {
			auto in = pos;
			skip_spaces(pos);

std::cout << "running " << "Rule_rule" << ", pos: " << pos->startpos() << "\n";
;
			::Parser::Rule _0;
			::Parser::bool_t success_1 = false;
			::Parser::Rule _2;
			::Parser::bool_t success_3 = false;
			::Parser::Rule_res _4;
			::Parser::bool_t success_5 = false;
			::Parser::Rule_res _6;
			::Parser::bool_t success_7 = false;
			::Parser::any_t _8;
			::Parser::bool_t success_9 = false;
			::Parser::Token _10;
			::Parser::bool_t success_11 = false;
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
			::Parser::Rule_res _26;
			::Parser::bool_t success_27 = false;
			::Parser::Token _28;
			::Parser::bool_t success_29 = false;
			::Parser::Rule_res _30;
			::Parser::bool_t success_31 = false;
			::Parser::Rule_res _32;
			::Parser::bool_t success_33 = false;
			::Parser::Rule_res _34;
			::Parser::bool_t success_35 = false;
			auto begin_2 = pos;
			do
			{
				_4 = Rule_keyvalue(begin_2);
				if (!(_4.status))
				{
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
				pos = begin_2;
			}
			skip_spaces(pos);
			if (!(pos->name() == ::Parser::Tokens::Rule_NOSPACE))
			{
				if (!(pos->name() == ::Parser::Tokens::Rule_ESCAPED))
				{
					if (!(pos->name() == ::Parser::Tokens::Rule_HEX))
					{
						if (!(pos->name() == ::Parser::Tokens::Rule_BIN))
						{
							if (!(pos->name() == ::Parser::Tokens::LINEAR_COMMENT))
							{
								if (!(pos->name() == ::Parser::Tokens::Rule_OP))
								{
									if (!(pos->name() == ::Parser::Tokens::Rule_CSEQUENCE))
									{
										if (!(pos->name() == ::Parser::Tokens::AUTO_18))
										{
											_26 = Rule_group(pos);
											if (!(_26.status))
											{
												if (!(pos->name() == ::Parser::Tokens::STRING))
												{
													_30 = cll(pos);
													if (!(_30.status))
													{
														_32 = Rule_name(pos);
														if (!(_32.status))
														{
															return {};
														}
														else 
														{
															success_33 = true;
															pos += _32.node.length();
															_8 = _32.node;
														}
													}
													else 
													{
														success_31 = true;
														pos += _30.node.length();
														_8 = _30.node;
													}
												}
												else 
												{
													_28 = *pos;
													success_29 = true;
													pos += 1;
													_8 = _28;
												}
											}
											else 
											{
												success_27 = true;
												pos += _26.node.length();
												_8 = _26.node;
											}
										}
										else 
										{
											_24 = *pos;
											success_25 = true;
											pos += 1;
											_8 = _24;
										}
									}
									else 
									{
										_22 = *pos;
										success_23 = true;
										pos += 1;
										_8 = _22;
									}
								}
								else 
								{
									_20 = *pos;
									success_21 = true;
									pos += 1;
									_8 = _20;
								}
							}
							else 
							{
								_18 = *pos;
								success_19 = true;
								pos += 1;
								_8 = _18;
							}
						}
						else 
						{
							_16 = *pos;
							success_17 = true;
							pos += 1;
							_8 = _16;
						}
					}
					else 
					{
						_14 = *pos;
						success_15 = true;
						pos += 1;
						_8 = _14;
					}
				}
				else 
				{
					_12 = *pos;
					success_13 = true;
					pos += 1;
					_8 = _12;
				}
			}
			else 
			{
				_10 = *pos;
				success_11 = true;
				pos += 1;
				_8 = _10;
			}
			success_9 = true;
			skip_spaces(pos);
			_34 = Rule_quantifier(pos);
			if (_34.status)
			{
				success_35 = true;
				pos += _34.node.length();
			}
			::Parser::Types::Rule_rule_data data;
			data.quantifier = _8;
			data.val = _0;
			data.prefix = _2;


std::cout << "success run Rule_rule\n";
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::Rule_rule, data)};
		}
		template <class IT>
		::Parser::Rule_res Rule_name(IT pos) {
			auto in = pos;
			skip_spaces(pos);

std::cout << "running " << "Rule_name" << ", pos: " << pos->startpos() << "\n";
;
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Token _2;
			::Parser::bool_t success_3 = false;
			::Parser::bool_t success_5 = false;
			::Parser::Token _6;
			::Parser::bool_t success_7 = false;
			::Parser::arr_t<::Parser::Token> shadow_8;
			::Parser::Token _9;
			::Parser::bool_t success_10 = false;
			::Parser::arr_t<::Parser::Token> shadow_11;
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


std::cout << "success run Rule_name\n";
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::Rule_name, data)};
		}
		template <class IT>
		::Parser::Rule_res Rule_group(IT pos) {
			auto in = pos;
			skip_spaces(pos);

std::cout << "running " << "Rule_group" << ", pos: " << pos->startpos() << "\n";
;
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Rule_res _2;
			::Parser::bool_t success_3 = false;
			::Parser::arr_t<::Parser::Rule> shadow_4;
			::Parser::Token _5;
			::Parser::bool_t success_6 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_6))
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
			::Parser::Types::Rule_group_data data = shadow_4;

std::cout << "success run Rule_group\n";
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::Rule_group, data)};
		}
		template <class IT>
		::Parser::Rule_res Rule_keyvalue(IT pos) {
			auto in = pos;
			skip_spaces(pos);

std::cout << "running " << "Rule_keyvalue" << ", pos: " << pos->startpos() << "\n";
;
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::bool_t success_3 = false;
			::Parser::Token _4;
			::Parser::bool_t success_5 = false;
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

std::cout << "success run Rule_keyvalue\n";
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::Rule_keyvalue, data)};
		}
		template <class IT>
		::Parser::Rule_res Rule_value(IT pos) {
			auto in = pos;
			skip_spaces(pos);

std::cout << "running " << "Rule_value" << ", pos: " << pos->startpos() << "\n";
;
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Token _2;
			::Parser::bool_t success_3 = false;
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

std::cout << "success run Rule_value\n";
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::Rule_value, data)};
		}
		template <class IT>
		::Parser::Rule_res Rule_nested_rule(IT pos) {
			auto in = pos;
			skip_spaces(pos);

std::cout << "running " << "Rule_nested_rule" << ", pos: " << pos->startpos() << "\n";
;
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Rule_res _2;
			::Parser::bool_t success_3 = false;
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

std::cout << "success run Rule_nested_rule\n";
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::Rule_nested_rule, data)};
		}
		template <class IT>
		::Parser::Rule_res Rule_data_block_regular_datablock_key(IT pos) {
			auto in = pos;
			skip_spaces(pos);

std::cout << "running " << "Rule_data_block_regular_datablock_key" << ", pos: " << pos->startpos() << "\n";
;
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::arr_t<::Parser::Token> shadow_2;
			::Parser::bool_t success_3 = false;
			::Parser::Token _4;
			::Parser::Token name;
			::Parser::bool_t success_5 = false;
			::Parser::Token _6;
			::Parser::bool_t success_7 = false;
			::Parser::Token _8;
			::Parser::bool_t success_9 = false;
			::Parser::Rule _10;
			::Parser::Rule dt;
			::Parser::bool_t success_11 = false;
			::Parser::Rule_res _12;
			::Parser::bool_t success_13 = false;
			while (pos->name() == ::Parser::Tokens::AUTO_20)
			{
				_0 = *pos;
				success_1 = true;
				pos += 1;
				shadow_2.push_back(_0);
				success_3 = true;
			}
			if (!success_3)
			{
				return {};
			}
			skip_spaces(pos);
			auto begin_6 = pos;
			if (!(begin_6->name() == ::Parser::Tokens::ID))
			{
				reportError(pos, "id");
				return {};
			}
			_6 = *begin_6;
			success_7 = true;
			begin_6 += 1;
			_4 = _6;
			if (success_7)
			{
				success_5 = true;
				name = _4;
				pos = begin_6;
			}
			skip_spaces(pos);
			if (!(pos->name() == ::Parser::Tokens::AUTO_21))
			{
				reportError(pos, "auto_21");
				return {};
			}
			_8 = *pos;
			success_9 = true;
			pos += 1;
			skip_spaces(pos);
			auto begin_12 = pos;
			_12 = cll_expr(begin_12);
			if (!(_12.status))
			{
				reportError(pos, "cll");
				return {};
			}
			success_13 = true;
			begin_12 += _12.node.length();
			_10 = _12.node;
			if (success_13)
			{
				success_11 = true;
				dt = _10;
				pos = begin_12;
			}
			::Parser::Types::Rule_data_block_regular_datablock_key_data data;
			data.val = dt;
			data.name = name;


std::cout << "success run Rule_data_block_regular_datablock_key\n";
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::Rule_data_block_regular_datablock_key, data)};
		}
		template <class IT>
		::Parser::Rule_res Rule_data_block_regular_datablock(IT pos) {
			auto in = pos;
			skip_spaces(pos);

std::cout << "running " << "Rule_data_block_regular_datablock" << ", pos: " << pos->startpos() << "\n";
;
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Rule _2;
			::Parser::bool_t success_3 = false;
			::Parser::Rule_res _4;
			::Parser::bool_t success_5 = false;
			::Parser::Rule_res _6;
			::Parser::bool_t success_7 = false;
			::Parser::Token _8;
			::Parser::bool_t success_9 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_10))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			_4 = Rule_data_block_regular_datablock_key(pos);
			if (!(_4.status))
			{
				_6 = any_data(pos);
				if (!(_6.status))
				{
					return {};
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
			if (!(pos->name() == ::Parser::Tokens::AUTO_11))
			{
				reportError(pos, "auto_11");
				return {};
			}
			_8 = *pos;
			success_9 = true;
			pos += 1;
			::Parser::Types::Rule_data_block_regular_datablock_data data = _2;

std::cout << "success run Rule_data_block_regular_datablock\n";
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::Rule_data_block_regular_datablock, data)};
		}
		template <class IT>
		::Parser::Rule_res Rule_data_block_templated_datablock(IT pos) {
			auto in = pos;
			skip_spaces(pos);

std::cout << "running " << "Rule_data_block_templated_datablock" << ", pos: " << pos->startpos() << "\n";
;
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Token _2;
			::Parser::bool_t success_3 = false;
			::Parser::bool_t success_5 = false;
			::Parser::Token _6;
			::Parser::Token first_name;
			::Parser::bool_t success_7 = false;
			::Parser::Token _8;
			::Parser::bool_t success_9 = false;
			::Parser::bool_t success_11 = false;
			::Parser::Token _12;
			::Parser::bool_t success_13 = false;
			::Parser::arr_t<::Parser::Token> shadow_14;
			::Parser::Token _15;
			::Parser::arr_t<::Parser::Token> second_name;
			::Parser::bool_t success_16 = false;
			::Parser::Token _17;
			::Parser::bool_t success_18 = false;
			::Parser::arr_t<::Parser::Token> shadow_19;
			::Parser::arr_t<::Parser::Token> shadow_20;
			::Parser::Token _21;
			::Parser::bool_t success_22 = false;
			if (!(pos->name() == ::Parser::Tokens::AT))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			if (!(pos->name() == ::Parser::Tokens::AUTO_10))
			{
				reportError(pos, "auto_10");
				return {};
			}
			_2 = *pos;
			success_3 = true;
			pos += 1;
			skip_spaces(pos);
			auto begin_6 = pos;
			do
			{
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
					if (!(begin_12->name() == ::Parser::Tokens::AUTO_8))
					{
						reportError(pos, "auto_8");
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
			if (!(pos->name() == ::Parser::Tokens::AUTO_11))
			{
				reportError(pos, "auto_11");
				return {};
			}
			_21 = *pos;
			success_22 = true;
			pos += 1;
			::Parser::Types::Rule_data_block_templated_datablock_data data;
			data.second_name = second_name;
			data.first_name = first_name;


std::cout << "success run Rule_data_block_templated_datablock\n";
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::Rule_data_block_templated_datablock, data)};
		}
		template <class IT>
		::Parser::Rule_res Rule_data_block(IT pos) {
			auto in = pos;
			skip_spaces(pos);

std::cout << "running " << "Rule_data_block" << ", pos: " << pos->startpos() << "\n";
;
			::Parser::Rule _0;
			::Parser::bool_t success_1 = false;
			::Parser::Rule_res _2;
			::Parser::bool_t success_3 = false;
			::Parser::Rule_res _4;
			::Parser::bool_t success_5 = false;
			_2 = Rule_data_block_regular_datablock(pos);
			if (!(_2.status))
			{
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

std::cout << "success run Rule_data_block\n";
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::Rule_data_block, data)};
		}
		template <class IT>
		::Parser::Rule_res Rule_quantifier(IT pos) {
			auto in = pos;
			skip_spaces(pos);

std::cout << "running " << "Rule_quantifier" << ", pos: " << pos->startpos() << "\n";
;
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Token _2;
			::Parser::bool_t success_3 = false;
			::Parser::Token _4;
			::Parser::bool_t success_5 = false;
			::Parser::Token _6;
			::Parser::bool_t success_7 = false;
			if (!(pos->name() == ::Parser::Tokens::QUESTION_MARK))
			{
				if (!(pos->name() == ::Parser::Tokens::PLUS))
				{
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

std::cout << "success run Rule_quantifier\n";
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::Rule_quantifier, data)};
		}
		template <class IT>
		::Parser::Rule_res Rule(IT pos) {
			auto in = pos;
			skip_spaces(pos);

std::cout << "running " << "Rule" << ", pos: " << pos->startpos() << "\n";
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
			if (!(pos->name() == ::Parser::Tokens::ID))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			if (!(pos->name() == ::Parser::Tokens::AUTO_15))
			{
				reportError(pos, "auto_15");
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
			if (!(pos->name() == ::Parser::Tokens::AUTO_14))
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


std::cout << "success run Rule\n";
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::Rule, data)};
		}
	};

} // Parser


#endif // PARSER
