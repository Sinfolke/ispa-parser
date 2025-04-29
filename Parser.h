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
		NONE, cll_OP, cll_ASSIGNMENT_OP, cll_COMPARE_OP, cll_LOGICAL_OP, cll_LOGICAL_NOT, cll_LOGICAL_AND, cll_LOGICAL_OR, cll_TYPE, cll_TEMPLATE, STRING, NUMBER, BOOLEAN, END, NEWLINE, PLUS, MINUS, DIVIDE, MULTIPLE, MODULO, LINEAR_COMMENT, ID, SPACEMODE, NAME, AT, Rule_OP, Rule_CSEQUENCE, Rule_CSEQUENCE_SYMBOL, Rule_CSEQUENCE_ESCAPE, Rule_CSEQUENCE_DIAPASON, Rule_NOSPACE, Rule_ESCAPED, Rule_HEX, Rule_BIN, AUTO_0, AUTO_1, AUTO_6, AUTO_7, AUTO_14, AUTO_19, AUTO_20, AUTO_25, AUTO_27, AUTO_32, AUTO_34, AUTO_36, AUTO_38, AUTO_39, AUTO_40, AUTO_41, AUTO_42, AUTO_45, AUTO_46, AUTO_47, AUTO_48, AUTO_49, AUTO_50, __WHITESPACE
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
			::Parser::arr_t<::Parser::Token> val;
			::Parser::str_t _not;
		};
		using Rule_ESCAPED_data = ::Parser::str_t;
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
		using AUTO_36_data = ::Parser::str_t;
		using AUTO_38_data = ::Parser::str_t;
		using AUTO_39_data = ::Parser::str_t;
		using AUTO_40_data = ::Parser::str_t;
		using AUTO_41_data = ::Parser::str_t;
		using AUTO_42_data = ::Parser::str_t;
		using AUTO_45_data = ::Parser::str_t;
		using AUTO_46_data = ::Parser::str_t;
		using AUTO_47_data = ::Parser::str_t;
		using AUTO_48_data = ::Parser::str_t;
		using AUTO_49_data = ::Parser::str_t;
		using AUTO_50_data = ::Parser::str_t;
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
			::Parser::Token second_name;
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
		::Parser::Types::AUTO_6_data AUTO_6(::Parser::Token &token);
		::Parser::Types::AUTO_7_data AUTO_7(::Parser::Token &token);
		::Parser::Types::AUTO_14_data AUTO_14(::Parser::Token &token);
		::Parser::Types::AUTO_19_data AUTO_19(::Parser::Token &token);
		::Parser::Types::AUTO_20_data AUTO_20(::Parser::Token &token);
		::Parser::Types::AUTO_25_data AUTO_25(::Parser::Token &token);
		::Parser::Types::AUTO_27_data AUTO_27(::Parser::Token &token);
		::Parser::Types::AUTO_32_data AUTO_32(::Parser::Token &token);
		::Parser::Types::AUTO_34_data AUTO_34(::Parser::Token &token);
		::Parser::Types::AUTO_36_data AUTO_36(::Parser::Token &token);
		::Parser::Types::AUTO_38_data AUTO_38(::Parser::Token &token);
		::Parser::Types::AUTO_39_data AUTO_39(::Parser::Token &token);
		::Parser::Types::AUTO_40_data AUTO_40(::Parser::Token &token);
		::Parser::Types::AUTO_41_data AUTO_41(::Parser::Token &token);
		::Parser::Types::AUTO_42_data AUTO_42(::Parser::Token &token);
		::Parser::Types::AUTO_45_data AUTO_45(::Parser::Token &token);
		::Parser::Types::AUTO_46_data AUTO_46(::Parser::Token &token);
		::Parser::Types::AUTO_47_data AUTO_47(::Parser::Token &token);
		::Parser::Types::AUTO_48_data AUTO_48(::Parser::Token &token);
		::Parser::Types::AUTO_49_data AUTO_49(::Parser::Token &token);
		::Parser::Types::AUTO_50_data AUTO_50(::Parser::Token &token);
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
			Token_res AUTO_6(const char*);
			Token_res AUTO_7(const char*);
			Token_res AUTO_14(const char*);
			Token_res AUTO_19(const char*);
			Token_res AUTO_20(const char*);
			Token_res AUTO_25(const char*);
			Token_res AUTO_27(const char*);
			Token_res AUTO_32(const char*);
			Token_res AUTO_34(const char*);
			Token_res AUTO_36(const char*);
			Token_res AUTO_38(const char*);
			Token_res AUTO_39(const char*);
			Token_res AUTO_40(const char*);
			Token_res AUTO_41(const char*);
			Token_res AUTO_42(const char*);
			Token_res AUTO_45(const char*);
			Token_res AUTO_46(const char*);
			Token_res AUTO_47(const char*);
			Token_res AUTO_48(const char*);
			Token_res AUTO_49(const char*);
			Token_res AUTO_50(const char*);
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
			_2 = cll_expr(pos);
			if (!(_2.status))
			{
				reportError(pos, "expr");
				return {};
			}
			success_3 = true;
			pos += _2.node.length();
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
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Token _2;
			::Parser::bool_t success_3 = false;
			::Parser::Token _4;
			::Parser::bool_t success_5 = false;
			::Parser::Token _6;
			::Parser::bool_t success_7 = false;
			::Parser::Token _9;
			::Parser::bool_t success_10 = false;
			::Parser::bool_t success_12 = false;
			::Parser::Token _13;
			::Parser::bool_t success_14 = false;
			::Parser::Rule_res _15;
			::Parser::bool_t success_16 = false;
			::Parser::Token _17;
			::Parser::bool_t success_18 = false;
			::Parser::Token _20;
			::Parser::bool_t success_21 = false;
			::Parser::Token _22;
			::Parser::bool_t success_23 = false;
			::Parser::Token _24;
			::Parser::bool_t success_25 = false;
			::Parser::Token _26;
			::Parser::bool_t success_27 = false;
			auto begin_8 = pos;
			do
			{
				if (!(begin_8->name() == ::Parser::Tokens::AUTO_6))
				{
					if (!(begin_8->name() == ::Parser::Tokens::AUTO_7))
					{
						break;
					}
					else 
					{
						_6 = *begin_8;
						success_7 = true;
						begin_8 += 1;
						_2 = _6;
					}
				}
				else 
				{
					_4 = *begin_8;
					success_5 = true;
					begin_8 += 1;
					_2 = _4;
				}
				success_3 = true;
				_0 = _2;
			}
			while(0)
;
			if (success_3)
			{
				success_1 = true;
				pos = begin_8;
			}
			if (!(pos->name() == ::Parser::Tokens::ID))
			{
				reportError(pos, "id");
				return {};
			}
			_9 = *pos;
			success_10 = true;
			pos += 1;
			auto begin_19 = pos;
			do
			{
				if (!(begin_19->name() == ::Parser::Tokens::AUTO_25))
				{
					reportError(pos, "\"[\"");
					break;
				}
				_13 = *begin_19;
				success_14 = true;
				begin_19 += 1;
				_15 = cll_expr(begin_19);
				if (!(_15.status))
				{
					reportError(pos, "expr");
					break;
				}
				success_16 = true;
				begin_19 += _15.node.length();
				if (!(begin_19->name() == ::Parser::Tokens::AUTO_27))
				{
					reportError(pos, "\"]\"");
					break;
				}
				_17 = *begin_19;
				success_18 = true;
				begin_19 += 1;
			}
			while(0)
;
			if (success_14 && success_16 && success_18)
			{
				success_12 = true;
				pos = begin_19;
			}
			auto begin_28 = pos;
			do
			{
				if (!(begin_28->name() == ::Parser::Tokens::AUTO_6))
				{
					if (!(begin_28->name() == ::Parser::Tokens::AUTO_7))
					{
						break;
					}
					else 
					{
						_26 = *begin_28;
						success_27 = true;
						begin_28 += 1;
						_22 = _26;
					}
				}
				else 
				{
					_24 = *begin_28;
					success_25 = true;
					begin_28 += 1;
					_22 = _24;
				}
				success_23 = true;
				_20 = _22;
			}
			while(0)
;
			if (success_23)
			{
				success_21 = true;
				pos = begin_28;
			}
			::Parser::Types::cll_variable_data data;
			data.post = _20;
			data.pre = _0;
			data.brace_expression = _15.node;
			data.name = _0;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_variable, data)};
		}
		template <class IT>
		::Parser::Rule_res cll_function_body_call(IT pos) {
			auto in = pos;
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Rule_res _2;
			::Parser::bool_t success_3 = false;
			::Parser::Token _4;
			::Parser::bool_t success_5 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_39))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			_2 = cll_function_arguments(pos);
			if (!(_2.status))
			{
				reportError(pos, "function_arguments");
				return {};
			}
			success_3 = true;
			pos += _2.node.length();
			if (!(pos->name() == ::Parser::Tokens::AUTO_40))
			{
				reportError(pos, "\")\"");
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
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Rule_res _2;
			::Parser::bool_t success_3 = false;
			::Parser::Token _4;
			::Parser::bool_t success_5 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_39))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			_2 = cll_function_parameters(pos);
			if (!(_2.status))
			{
				reportError(pos, "function_parameters");
				return {};
			}
			success_3 = true;
			pos += _2.node.length();
			if (!(pos->name() == ::Parser::Tokens::AUTO_40))
			{
				reportError(pos, "\")\"");
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
			::Parser::bool_t success_1 = false;
			::Parser::any_t _2;
			::Parser::bool_t success_3 = false;
			::Parser::Rule_res _4;
			::Parser::bool_t success_5 = false;
			::Parser::Token _6;
			::Parser::bool_t success_7 = false;
			::Parser::arr_t<::Parser::Token> _8;
			::Parser::bool_t success_9 = false;
			::Parser::arr_t<::Parser::arr_t<::Parser::Token>> shadow_15;
			::Parser::arr_t<::Parser::Token> _10;
			::Parser::bool_t success_11 = false;
			::Parser::Token _12;
			::Parser::bool_t success_13 = false;
			::Parser::arr_t<::Parser::Token> shadow_14;
			auto begin_16 = pos;
			_4 = any_data(begin_16);
			if (!(_4.status))
			{
				if (!(begin_16->name() == ::Parser::Tokens::ID))
				{
					return {};
				}
				else 
				{
					_6 = *begin_16;
					success_7 = true;
					begin_16 += 1;
					_2 = _6;
				}
			}
			else 
			{
				success_5 = true;
				begin_16 += _4.node.length();
				_2 = _4.node;
			}
			success_3 = true;
			auto begin_15 = begin_16;
			while (1)
			{
				if (!(begin_15->name() == ::Parser::Tokens::AUTO_48))
				{
					break;
				}
				else 
				{
					_12 = *begin_15;
					success_13 = true;
					begin_15 += 1;
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
				begin_16 = begin_15;
			}
			if (success_3)
			{
				success_1 = true;
				pos = begin_16;
			}
			::Parser::Types::cll_function_arguments_data data;
			data.second = shadow_15;
			data.first = _2;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_function_arguments, data)};
		}
		template <class IT>
		::Parser::Rule_res cll_function_parameters(IT pos) {
			auto in = pos;
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
			auto begin_13 = pos;
			if (!(begin_13->name() == ::Parser::Tokens::ID))
			{
				return {};
			}
			_2 = *begin_13;
			success_3 = true;
			begin_13 += 1;
			auto begin_12 = begin_13;
			while (1)
			{
				if (!(begin_12->name() == ::Parser::Tokens::AUTO_48))
				{
					reportError(pos, "\",\"");
					break;
				}
				_6 = *begin_12;
				success_7 = true;
				begin_12 += 1;
				shadow_8.push_back(_6);
				if (!(begin_12->name() == ::Parser::Tokens::ID))
				{
					reportError(pos, "id");
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
			if (success_3)
			{
				success_1 = true;
				pos = begin_13;
			}
			::Parser::Types::cll_function_parameters_data data;
			data.second = shadow_11;
			data.first = _2;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_function_parameters, data)};
		}
		template <class IT>
		::Parser::Rule_res cll_cll_function_call(IT pos) {
			auto in = pos;
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
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Token _2;
			::Parser::bool_t success_3 = false;
			::Parser::Token _4;
			::Parser::bool_t success_5 = false;
			::Parser::arr_t<::Parser::Token> shadow_6;
			::Parser::bool_t success_7 = false;
			::Parser::Rule_res _9;
			::Parser::bool_t success_10 = false;
			::Parser::Rule val;
			::Parser::bool_t success_11 = false;
			::Parser::Rule_res _12;
			::Parser::bool_t success_13 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_14))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			auto begin_8 = pos;
			while (begin_8->name() == ::Parser::Tokens::ID)
			{
				_4 = *begin_8;
				success_5 = true;
				begin_8 += 1;
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
				pos = begin_8;
			}
			_9 = cll_function_body_decl(pos);
			if (!(_9.status))
			{
				reportError(pos, "function_body_decl");
				return {};
			}
			success_10 = true;
			pos += _9.node.length();
			auto begin_14 = pos;
			do
			{
				_12 = cll_block(begin_14);
				if (!(_12.status))
				{
					reportError(pos, "block");
					break;
				}
				success_13 = true;
				begin_14 += _12.node.length();
				val = _12.node;
			}
			while(0)
;
			if (success_13)
			{
				success_11 = true;
				pos = begin_14;
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
			_2 = cll_expr_term(pos);
			if (!(_2.status))
			{
				_4 = cll_expr_compare(pos);
				if (!(_4.status))
				{
					_6 = cll_expr_arithmetic(pos);
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
			if (!(pos->name() == ::Parser::Tokens::cll_LOGICAL_OP))
			{
				reportError(pos, "logical_op");
				return {};
			}
			_10 = *pos;
			success_11 = true;
			pos += 1;
			_14 = cll_expr_term(pos);
			if (!(_14.status))
			{
				_16 = cll_expr_compare(pos);
				if (!(_16.status))
				{
					_18 = cll_expr_arithmetic(pos);
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

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_expr_logical, data)};
		}
		template <class IT>
		::Parser::Rule_res cll_expr_compare(IT pos) {
			auto in = pos;
			::Parser::Rule _0;
			::Parser::bool_t success_1 = false;
			::Parser::Rule_res _2;
			::Parser::bool_t success_3 = false;
			::Parser::Rule_res _4;
			::Parser::bool_t success_5 = false;
			::Parser::arr_t<::Parser::Token> _6;
			::Parser::bool_t success_7 = false;
			::Parser::arr_t<::Parser::arr_t<::Parser::Token>> shadow_13;
			::Parser::bool_t success_14 = false;
			::Parser::arr_t<::Parser::Token> _8;
			::Parser::bool_t success_9 = false;
			::Parser::Token _10;
			::Parser::bool_t success_11 = false;
			::Parser::arr_t<::Parser::Token> shadow_12;
			_2 = cll_expr_term(pos);
			if (!(_2.status))
			{
				_4 = cll_expr_arithmetic(pos);
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
			auto begin_13 = pos;
			while (1)
			{
				if (!(begin_13->name() == ::Parser::Tokens::cll_COMPARE_OP))
				{
					break;
				}
				else 
				{
					_10 = *begin_13;
					success_11 = true;
					begin_13 += 1;
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
				pos = begin_13;
			}
			::Parser::Types::cll_expr_compare_data data;
			data.sequence = shadow_13;
			data.operators = _8;
			data.first = _0;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_expr_compare, data)};
		}
		template <class IT>
		::Parser::Rule_res cll_expr_arithmetic(IT pos) {
			auto in = pos;
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
			auto begin_15 = pos;
			while (1)
			{
				if (!(begin_15->name() == ::Parser::Tokens::PLUS))
				{
					if (!(begin_15->name() == ::Parser::Tokens::MINUS))
					{
						break;
					}
					else 
					{
						_9 = *begin_15;
						success_10 = true;
						begin_15 += 1;
						shadow_11.push_back(_9);
						_4.push_back(_9);
					}
				}
				else 
				{
					_6 = *begin_15;
					success_7 = true;
					begin_15 += 1;
					shadow_8.push_back(_6);
					_4.push_back(_6);
				}
				success_5 = true;
				_12 = cll_expr_term(begin_15);
				if (!(_12.status))
				{
					reportError(pos, "term");
					break;
				}
				success_13 = true;
				begin_15 += _12.node.length();
				shadow_14.push_back(_12.node);
				success_15 = true;
			}
			if (!success_15)
			{
				reportError(pos, "plus or minus");
				return {};
			}
			if (success_5 && success_13)
			{
				success_3 = true;
				pos = begin_15;
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
			auto begin_18 = pos;
			while (1)
			{
				if (!(begin_18->name() == ::Parser::Tokens::MULTIPLE))
				{
					if (!(begin_18->name() == ::Parser::Tokens::DIVIDE))
					{
						if (!(begin_18->name() == ::Parser::Tokens::MODULO))
						{
							break;
						}
						else 
						{
							_12 = *begin_18;
							success_13 = true;
							begin_18 += 1;
							shadow_14.push_back(_12);
							_4.push_back(_12);
						}
					}
					else 
					{
						_9 = *begin_18;
						success_10 = true;
						begin_18 += 1;
						shadow_11.push_back(_9);
						_4.push_back(_9);
					}
				}
				else 
				{
					_6 = *begin_18;
					success_7 = true;
					begin_18 += 1;
					shadow_8.push_back(_6);
					_4.push_back(_6);
				}
				success_5 = true;
				_15 = cll_expr_value(begin_18);
				if (!(_15.status))
				{
					reportError(pos, "value");
					break;
				}
				success_16 = true;
				begin_18 += _15.node.length();
				shadow_17.push_back(_15.node);
				success_18 = true;
			}
			if (!success_18)
			{
				reportError(pos, "multiple or divide or modulo");
				return {};
			}
			if (success_5 && success_16)
			{
				success_3 = true;
				pos = begin_18;
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
					_6 = cll_cll_function_call(pos);
					if (!(_6.status))
					{
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
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Rule_res _2;
			::Parser::bool_t success_3 = false;
			::Parser::Token _4;
			::Parser::bool_t success_5 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_39))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			_2 = cll_expr(pos);
			if (!(_2.status))
			{
				reportError(pos, "expr");
				return {};
			}
			success_3 = true;
			pos += _2.node.length();
			if (!(pos->name() == ::Parser::Tokens::AUTO_40))
			{
				reportError(pos, "\")\"");
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
			::Parser::any_t _0;
			::Parser::bool_t success_1 = false;
			::Parser::Rule_res _2;
			::Parser::bool_t success_3 = false;
			::Parser::Rule_res _4;
			::Parser::bool_t success_5 = false;
			::Parser::Rule_res _6;
			::Parser::bool_t success_7 = false;
			::Parser::Rule_res _8;
			::Parser::bool_t success_9 = false;
			::Parser::Rule_res _10;
			::Parser::bool_t success_11 = false;
			::Parser::Token _12;
			::Parser::bool_t success_13 = false;
			_2 = cll_expr_logical(pos);
			if (!(_2.status))
			{
				_4 = cll_expr_term(pos);
				if (!(_4.status))
				{
					_6 = cll_expr_compare(pos);
					if (!(_6.status))
					{
						_8 = cll_expr_arithmetic(pos);
						if (!(_8.status))
						{
							_10 = cll_expr_value(pos);
							if (!(_10.status))
							{
								if (!(pos->name() == ::Parser::Tokens::AT))
								{
									return {};
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
			if (!(pos->name() == ::Parser::Tokens::ID))
			{
				reportError(pos, "id");
				return {};
			}
			_2 = *pos;
			success_3 = true;
			pos += 1;
			auto begin_10 = pos;
			do
			{
				if (!(begin_10->name() == ::Parser::Tokens::cll_ASSIGNMENT_OP))
				{
					reportError(pos, "assignment_op");
					break;
				}
				_6 = *begin_10;
				success_7 = true;
				begin_10 += 1;
				_8 = cll_expr(begin_10);
				if (!(_8.status))
				{
					reportError(pos, "expr");
					break;
				}
				success_9 = true;
				begin_10 += _8.node.length();
			}
			while(0)
;
			if (success_7 && success_9)
			{
				success_5 = true;
				pos = begin_10;
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
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Rule_res _2;
			::Parser::bool_t success_3 = false;
			::Parser::arr_t<::Parser::Rule> shadow_4;
			::Parser::Token _5;
			::Parser::bool_t success_6 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_47))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			_2 = Rule_rule(pos);
			while (_2.status)
			{
				success_3 = true;
				pos += _2.node.length();
				shadow_4.push_back(_2.node);
				_2 = Rule_rule(pos);
			}
			if (!(pos->name() == ::Parser::Tokens::AUTO_49))
			{
				reportError(pos, "\"}\"");
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
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Rule_res _2;
			::Parser::bool_t success_3 = false;
			::Parser::Rule_res _4;
			::Parser::bool_t success_5 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_19))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			_2 = cll_expr(pos);
			if (!(_2.status))
			{
				reportError(pos, "expr");
				return {};
			}
			success_3 = true;
			pos += _2.node.length();
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
			::Parser::Token _13;
			::Parser::bool_t success_14 = false;
			::Parser::Rule_res _15;
			::Parser::bool_t success_16 = false;
			::Parser::Token _17;
			::Parser::bool_t success_18 = false;
			::Parser::Rule_res _19;
			::Parser::bool_t success_20 = false;
			::Parser::Token _21;
			::Parser::bool_t success_22 = false;
			::Parser::Rule_res _23;
			::Parser::bool_t success_24 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_20))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			if (!(pos->name() == ::Parser::Tokens::AUTO_39))
			{
				reportError(pos, "\"(\"");
				return {};
			}
			_2 = *pos;
			success_3 = true;
			pos += 1;
			auto begin_12 = pos;
			do
			{
				_8 = cll_var(begin_12);
				if (!(_8.status))
				{
					_10 = cll_expr(begin_12);
					if (!(_10.status))
					{
						break;
					}
					else 
					{
						success_11 = true;
						begin_12 += _10.node.length();
						_6 = _10.node;
					}
				}
				else 
				{
					success_9 = true;
					begin_12 += _8.node.length();
					_6 = _8.node;
				}
				success_7 = true;
				_4 = _6;
			}
			while(0)
;
			if (success_7)
			{
				success_5 = true;
				pos = begin_12;
			}
			if (!(pos->name() == ::Parser::Tokens::AUTO_32))
			{
				reportError(pos, "\";\"");
				return {};
			}
			_13 = *pos;
			success_14 = true;
			pos += 1;
			_15 = cll_expr(pos);
			if (_15.status)
			{
				success_16 = true;
				pos += _15.node.length();
			}
			if (!(pos->name() == ::Parser::Tokens::AUTO_32))
			{
				reportError(pos, "\";\"");
				return {};
			}
			_17 = *pos;
			success_18 = true;
			pos += 1;
			_19 = cll_expr(pos);
			if (_19.status)
			{
				success_20 = true;
				pos += _19.node.length();
			}
			if (!(pos->name() == ::Parser::Tokens::AUTO_40))
			{
				reportError(pos, "\")\"");
				return {};
			}
			_21 = *pos;
			success_22 = true;
			pos += 1;
			_23 = cll_block(pos);
			if (!(_23.status))
			{
				reportError(pos, "block");
				return {};
			}
			success_24 = true;
			pos += _23.node.length();
			::Parser::Types::cll_loop_for_data data;
			data.block = _21;
			data.end = _17;
			data.cond = _13;
			data.decl = _6;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_loop_for, data)};
		}
		template <class IT>
		::Parser::Rule_res cll(IT pos) {
			auto in = pos;
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
			_4 = cll_loop_for(pos);
			if (!(_4.status))
			{
				_6 = cll_loop_while(pos);
				if (!(_6.status))
				{
					_8 = cll_if(pos);
					if (!(_8.status))
					{
						_10 = cll_var(pos);
						if (!(_10.status))
						{
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
			if (!(pos->name() == ::Parser::Tokens::END))
			{
				reportError(pos, "end");
				return {};
			}
			_14 = *pos;
			success_15 = true;
			pos += 1;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll)};
		}
		template <class IT>
		::Parser::Rule_res array(IT pos) {
			auto in = pos;
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
			::Parser::Token _14;
			::Parser::bool_t success_15 = false;
			::Parser::arr_t<::Parser::Token> shadow_16;
			if (!(pos->name() == ::Parser::Tokens::AUTO_25))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			auto begin_13 = pos;
			do
			{
				auto begin_12 = begin_13;
				while (1)
				{
					_6 = any_data(begin_12);
					if (!(_6.status))
					{
						reportError(pos, "any_data");
						break;
					}
					success_7 = true;
					begin_12 += _6.node.length();
					shadow_8.push_back(_6.node);
					if (!(begin_12->name() == ::Parser::Tokens::AUTO_48))
					{
						reportError(pos, "\",\"");
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
			while(0)
;
			success_3 = true;
			pos = begin_13;
			if (!(pos->name() == ::Parser::Tokens::AUTO_27))
			{
				reportError(pos, "auto_27");
				return {};
			}
			_14 = *pos;
			success_15 = true;
			pos += 1;
			shadow_16.push_back(_14);
			::Parser::Types::array_data data = shadow_8;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::array, data)};
		}
		template <class IT>
		::Parser::Rule_res object(IT pos) {
			auto in = pos;
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
			::Parser::Token _25;
			::Parser::bool_t success_26 = false;
			::Parser::arr_t<::Parser::Token> shadow_27;
			::Parser::Token _29;
			::Parser::bool_t success_30 = false;
			::Parser::arr_t<::Parser::Token> shadow_31;
			if (!(pos->name() == ::Parser::Tokens::AUTO_47))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			auto begin_28 = pos;
			do
			{
				_4 = any_data(begin_28);
				if (!(_4.status))
				{
					reportError(pos, "any_data");
					break;
				}
				success_5 = true;
				begin_28 += _4.node.length();
				if (!(begin_28->name() == ::Parser::Tokens::AUTO_36))
				{
					reportError(pos, "\":\"");
					break;
				}
				_6 = *begin_28;
				success_7 = true;
				begin_28 += 1;
				_8 = any_data(begin_28);
				if (!(_8.status))
				{
					reportError(pos, "any_data");
					break;
				}
				success_9 = true;
				begin_28 += _8.node.length();
				auto begin_24 = begin_28;
				while (1)
				{
					if (!(begin_24->name() == ::Parser::Tokens::AUTO_48))
					{
						reportError(pos, "\",\"");
						break;
					}
					_12 = *begin_24;
					success_13 = true;
					begin_24 += 1;
					shadow_14.push_back(_12);
					if (!(begin_24->name() == ::Parser::Tokens::ID))
					{
						reportError(pos, "id");
						break;
					}
					_15 = *begin_24;
					success_16 = true;
					begin_24 += 1;
					shadow_17.push_back(_15);
					if (!(begin_24->name() == ::Parser::Tokens::AUTO_36))
					{
						reportError(pos, "\":\"");
						break;
					}
					_18 = *begin_24;
					success_19 = true;
					begin_24 += 1;
					shadow_20.push_back(_18);
					_21 = any_data(begin_24);
					if (!(_21.status))
					{
						reportError(pos, "any_data");
						break;
					}
					success_22 = true;
					begin_24 += _21.node.length();
					shadow_23.push_back(_21.node);
				}
				if (success_13 && success_16 && success_19 && success_22)
				{
					success_11 = true;
					begin_28 = begin_24;
				}
				if (!(begin_28->name() == ::Parser::Tokens::AUTO_32))
				{
					reportError(pos, "auto_32");
					break;
				}
				_25 = *begin_28;
				success_26 = true;
				begin_28 += 1;
				shadow_27.push_back(_25);
			}
			while(0)
;
			if (success_5 && success_7 && success_9 && success_26)
			{
				success_3 = true;
				pos = begin_28;
			}
			if (!(pos->name() == ::Parser::Tokens::AUTO_49))
			{
				reportError(pos, "\"}\"");
				return {};
			}
			_29 = *pos;
			success_30 = true;
			pos += 1;
			shadow_31.push_back(_29);
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
			::Parser::any_t _0;
			::Parser::bool_t success_1 = false;
			::Parser::Token _2;
			::Parser::bool_t success_3 = false;
			::Parser::Rule_res _4;
			::Parser::bool_t success_5 = false;
			::Parser::Rule_res _6;
			::Parser::bool_t success_7 = false;
			::Parser::Token _8;
			::Parser::bool_t success_9 = false;
			::Parser::Token _10;
			::Parser::bool_t success_11 = false;
			::Parser::Token _12;
			::Parser::bool_t success_13 = false;
			if (!(pos->name() == ::Parser::Tokens::STRING))
			{
				_4 = array(pos);
				if (!(_4.status))
				{
					_6 = object(pos);
					if (!(_6.status))
					{
						if (!(pos->name() == ::Parser::Tokens::NUMBER))
						{
							if (!(pos->name() == ::Parser::Tokens::ID))
							{
								if (!(pos->name() == ::Parser::Tokens::BOOLEAN))
								{
									return {};
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
			::Parser::Types::any_data_data data = _0;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::any_data, data)};
		}
		template <class IT>
		::Parser::Rule_res main(IT pos) {
			auto in = pos;
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
			_2 = Rule(pos);
			if (!(_2.status))
			{
				_4 = use(pos);
				if (!(_4.status))
				{
					if (!(pos->name() == ::Parser::Tokens::SPACEMODE))
					{
						if (!(pos->name() == ::Parser::Tokens::NAME))
						{
							return {};
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
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::main)};
		}
		template <class IT>
		::Parser::Rule_res use_unit(IT pos) {
			auto in = pos;
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
			if (!(pos->name() == ::Parser::Tokens::AUTO_34))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			_2 = use_unit(pos);
			if (!(_2.status))
			{
				reportError(pos, "unit");
				return {};
			}
			success_3 = true;
			pos += _2.node.length();
			auto begin_12 = pos;
			while (1)
			{
				if (!(begin_12->name() == ::Parser::Tokens::AUTO_48))
				{
					reportError(pos, "\",\"");
					break;
				}
				_6 = *begin_12;
				success_7 = true;
				begin_12 += 1;
				shadow_8.push_back(_6);
				_9 = use_unit(begin_12);
				if (!(_9.status))
				{
					reportError(pos, "unit");
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
			::Parser::Types::use_data data;
			data.second = shadow_11;
			data.first = _2.node;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::use, data)};
		}
		template <class IT>
		::Parser::Rule_res Rule_rule(IT pos) {
			auto in = pos;
			::Parser::Rule _0;
			::Parser::bool_t success_1 = false;
			::Parser::Rule _2;
			::Parser::bool_t success_3 = false;
			::Parser::Rule_res _4;
			::Parser::bool_t success_5 = false;
			::Parser::Rule_res _6;
			::Parser::bool_t success_7 = false;
			::Parser::any_t _9;
			::Parser::bool_t success_10 = false;
			::Parser::Token _11;
			::Parser::bool_t success_12 = false;
			::Parser::Token _13;
			::Parser::bool_t success_14 = false;
			::Parser::Rule_res _15;
			::Parser::bool_t success_16 = false;
			::Parser::Rule_res _17;
			::Parser::bool_t success_18 = false;
			::Parser::Token _19;
			::Parser::bool_t success_20 = false;
			::Parser::Rule_res _21;
			::Parser::bool_t success_22 = false;
			::Parser::Token _23;
			::Parser::bool_t success_24 = false;
			::Parser::Token _25;
			::Parser::bool_t success_26 = false;
			::Parser::Token _27;
			::Parser::bool_t success_28 = false;
			::Parser::Token _29;
			::Parser::bool_t success_30 = false;
			::Parser::Token _31;
			::Parser::bool_t success_32 = false;
			::Parser::Token _33;
			::Parser::bool_t success_34 = false;
			::Parser::Rule_res _35;
			::Parser::bool_t success_36 = false;
			auto begin_8 = pos;
			do
			{
				_4 = Rule_keyvalue(begin_8);
				if (!(_4.status))
				{
					_6 = Rule_value(begin_8);
					if (!(_6.status))
					{
						break;
					}
					else 
					{
						success_7 = true;
						begin_8 += _6.node.length();
						_2 = _6.node;
					}
				}
				else 
				{
					success_5 = true;
					begin_8 += _4.node.length();
					_2 = _4.node;
				}
				success_3 = true;
				_0 = _2;
			}
			while(0)
;
			if (success_3)
			{
				success_1 = true;
				pos = begin_8;
			}
			if (!(pos->name() == ::Parser::Tokens::Rule_CSEQUENCE))
			{
				if (!(pos->name() == ::Parser::Tokens::Rule_ESCAPED))
				{
					_15 = Rule_group(pos);
					if (!(_15.status))
					{
						_17 = Rule_name(pos);
						if (!(_17.status))
						{
							if (!(pos->name() == ::Parser::Tokens::STRING))
							{
								_21 = cll(pos);
								if (!(_21.status))
								{
									if (!(pos->name() == ::Parser::Tokens::Rule_HEX))
									{
										if (!(pos->name() == ::Parser::Tokens::Rule_BIN))
										{
											if (!(pos->name() == ::Parser::Tokens::LINEAR_COMMENT))
											{
												if (!(pos->name() == ::Parser::Tokens::Rule_NOSPACE))
												{
													if (!(pos->name() == ::Parser::Tokens::AUTO_38))
													{
														if (!(pos->name() == ::Parser::Tokens::Rule_OP))
														{
															return {};
														}
														else 
														{
															_33 = *pos;
															success_34 = true;
															pos += 1;
															_9 = _33;
														}
													}
													else 
													{
														_31 = *pos;
														success_32 = true;
														pos += 1;
														_9 = _31;
													}
												}
												else 
												{
													_29 = *pos;
													success_30 = true;
													pos += 1;
													_9 = _29;
												}
											}
											else 
											{
												_27 = *pos;
												success_28 = true;
												pos += 1;
												_9 = _27;
											}
										}
										else 
										{
											_25 = *pos;
											success_26 = true;
											pos += 1;
											_9 = _25;
										}
									}
									else 
									{
										_23 = *pos;
										success_24 = true;
										pos += 1;
										_9 = _23;
									}
								}
								else 
								{
									success_22 = true;
									pos += _21.node.length();
									_9 = _21.node;
								}
							}
							else 
							{
								_19 = *pos;
								success_20 = true;
								pos += 1;
								_9 = _19;
							}
						}
						else 
						{
							success_18 = true;
							pos += _17.node.length();
							_9 = _17.node;
						}
					}
					else 
					{
						success_16 = true;
						pos += _15.node.length();
						_9 = _15.node;
					}
				}
				else 
				{
					_13 = *pos;
					success_14 = true;
					pos += 1;
					_9 = _13;
				}
			}
			else 
			{
				_11 = *pos;
				success_12 = true;
				pos += 1;
				_9 = _11;
			}
			success_10 = true;
			_35 = Rule_quantifier(pos);
			if (_35.status)
			{
				success_36 = true;
				pos += _35.node.length();
			}
			::Parser::Types::Rule_rule_data data;
			data.quantifier = _9;
			data.val = _0;
			data.prefix = _2;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::Rule_rule, data)};
		}
		template <class IT>
		::Parser::Rule_res Rule_name(IT pos) {
			auto in = pos;
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
			if (pos->name() == ::Parser::Tokens::AUTO_42)
			{
				_0 = *pos;
				success_1 = true;
				pos += 1;
			}
			if (!(pos->name() == ::Parser::Tokens::ID))
			{
				reportError(pos, "id");
				return {};
			}
			_2 = *pos;
			success_3 = true;
			pos += 1;
			auto begin_12 = pos;
			while (1)
			{
				if (!(begin_12->name() == ::Parser::Tokens::AUTO_38))
				{
					reportError(pos, "auto_38");
					break;
				}
				_6 = *begin_12;
				success_7 = true;
				begin_12 += 1;
				shadow_8.push_back(_6);
				if (!(begin_12->name() == ::Parser::Tokens::ID))
				{
					reportError(pos, "id");
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
			::Parser::Types::Rule_name_data data;
			data.nested_name = shadow_11;
			data.name = _2;
			data.is_nested = _0;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::Rule_name, data)};
		}
		template <class IT>
		::Parser::Rule_res Rule_group(IT pos) {
			auto in = pos;
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Rule_res _2;
			::Parser::bool_t success_3 = false;
			::Parser::arr_t<::Parser::Rule> shadow_4;
			::Parser::Token _5;
			::Parser::bool_t success_6 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_39))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			_2 = Rule_rule(pos);
			while (_2.status)
			{
				success_3 = true;
				pos += _2.node.length();
				shadow_4.push_back(_2.node);
				_2 = Rule_rule(pos);
			}
			if (!(pos->name() == ::Parser::Tokens::AUTO_40))
			{
				reportError(pos, "auto_40");
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
			auto begin_6 = pos;
			do
			{
				if (!(begin_6->name() == ::Parser::Tokens::ID))
				{
					reportError(pos, "id");
					break;
				}
				_4 = *begin_6;
				success_5 = true;
				begin_6 += 1;
			}
			while(0)
;
			if (success_5)
			{
				success_3 = true;
				pos = begin_6;
			}
			::Parser::Types::Rule_keyvalue_data data = _4;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::Rule_keyvalue, data)};
		}
		template <class IT>
		::Parser::Rule_res Rule_value(IT pos) {
			auto in = pos;
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Token _2;
			::Parser::bool_t success_3 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_41))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
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
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Rule _2;
			::Parser::bool_t success_3 = false;
			::Parser::Rule_res _4;
			::Parser::bool_t success_5 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_42))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			auto begin_6 = pos;
			_4 = Rule(begin_6);
			if (!(_4.status))
			{
				reportError(pos, "rule");
				return {};
			}
			success_5 = true;
			begin_6 += _4.node.length();
			_2 = _4.node;
			if (success_5)
			{
				success_3 = true;
				pos = begin_6;
			}
			::Parser::Types::Rule_nested_rule_data data = _2;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::Rule_nested_rule, data)};
		}
		template <class IT>
		::Parser::Rule_res Rule_data_block_regular_datablock_key(IT pos) {
			auto in = pos;
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::arr_t<::Parser::Token> shadow_2;
			::Parser::bool_t success_3 = false;
			::Parser::Token name;
			::Parser::bool_t success_4 = false;
			::Parser::Token _5;
			::Parser::bool_t success_6 = false;
			::Parser::Token _8;
			::Parser::bool_t success_9 = false;
			::Parser::Rule dt;
			::Parser::bool_t success_10 = false;
			::Parser::Rule_res _11;
			::Parser::bool_t success_12 = false;
			while (pos->name() == ::Parser::Tokens::AUTO_45)
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
			auto begin_7 = pos;
			if (!(begin_7->name() == ::Parser::Tokens::ID))
			{
				reportError(pos, "id");
				return {};
			}
			_5 = *begin_7;
			success_6 = true;
			begin_7 += 1;
			name = _5;
			if (success_6)
			{
				success_4 = true;
				pos = begin_7;
			}
			if (!(pos->name() == ::Parser::Tokens::AUTO_46))
			{
				reportError(pos, "auto_46");
				return {};
			}
			_8 = *pos;
			success_9 = true;
			pos += 1;
			auto begin_13 = pos;
			_11 = cll_expr(begin_13);
			if (!(_11.status))
			{
				reportError(pos, "cll");
				return {};
			}
			success_12 = true;
			begin_13 += _11.node.length();
			dt = _11.node;
			if (success_12)
			{
				success_10 = true;
				pos = begin_13;
			}
			::Parser::Types::Rule_data_block_regular_datablock_key_data data;
			data.val = dt;
			data.name = name;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::Rule_data_block_regular_datablock_key, data)};
		}
		template <class IT>
		::Parser::Rule_res Rule_data_block_regular_datablock(IT pos) {
			auto in = pos;
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
			if (!(pos->name() == ::Parser::Tokens::AUTO_47))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
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
			if (!(pos->name() == ::Parser::Tokens::AUTO_49))
			{
				reportError(pos, "\"}\"");
				return {};
			}
			_8 = *pos;
			success_9 = true;
			pos += 1;
			::Parser::Types::Rule_data_block_regular_datablock_data data = _2;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::Rule_data_block_regular_datablock, data)};
		}
		template <class IT>
		::Parser::Rule_res Rule_data_block_templated_datablock(IT pos) {
			auto in = pos;
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Token _2;
			::Parser::bool_t success_3 = false;
			::Parser::bool_t success_5 = false;
			::Parser::Token first_name;
			::Parser::bool_t success_6 = false;
			::Parser::Token _7;
			::Parser::bool_t success_8 = false;
			::Parser::bool_t success_11 = false;
			::Parser::Token _12;
			::Parser::bool_t success_13 = false;
			::Parser::arr_t<::Parser::Token> shadow_14;
			::Parser::Token second_name;
			::Parser::bool_t success_15 = false;
			::Parser::Token _16;
			::Parser::bool_t success_17 = false;
			::Parser::arr_t<::Parser::Token> shadow_18;
			::Parser::Token _22;
			::Parser::bool_t success_23 = false;
			::Parser::arr_t<::Parser::Token> shadow_24;
			printf("token 1 name: %s\n", TokensToString(pos->name()).c_str());
			if (!(pos->name() == ::Parser::Tokens::AT))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			printf("token 2 name: %s\n", TokensToString(pos->name()).c_str());
			if (!(pos->name() == ::Parser::Tokens::AUTO_47))
			{
				reportError(pos, "auto_47");
				return {};
			}
			_2 = *pos;
			success_3 = true;
			pos += 1;
			auto begin_21 = pos;
			do
			{
				auto begin_9 = begin_21;
				printf("token 3 name: %s\n", TokensToString(pos->name()).c_str());
				if (!(begin_9->name() == ::Parser::Tokens::ID))
				{
					reportError(pos, "id");
					break;
				}
				_7 = *begin_9;
				success_8 = true;
				begin_9 += 1;
				first_name = _7;
				if (success_8)
				{
					success_6 = true;
					begin_21 = begin_9;
				}
				auto begin_20 = begin_21;
				while (1)
				{
					if (!(begin_20->name() == ::Parser::Tokens::AUTO_48))
					{
						reportError(pos, "auto_48");
						break;
					}
					_12 = *begin_20;
					success_13 = true;
					begin_20 += 1;
					shadow_14.push_back(_12);
					auto begin_19 = begin_20;
					if (!(begin_19->name() == ::Parser::Tokens::ID))
					{
						reportError(pos, "id");
						break;
					}
					_16 = *begin_19;
					success_17 = true;
					begin_19 += 1;
					shadow_18.push_back(_16);
					second_name = _16;
					if (success_17)
					{
						success_15 = true;
						begin_20 = begin_19;
					}
				}
				if (success_13 && success_15)
				{
					success_11 = true;
					begin_21 = begin_20;
				}
			}
			while(0)
;
			if (success_6)
			{
				success_5 = true;
				pos = begin_21;
			}
			if (!(pos->name() == ::Parser::Tokens::AUTO_49))
			{
				reportError(pos, "auto_49");
				return {};
			}
			_22 = *pos;
			success_23 = true;
			pos += 1;
			shadow_24.push_back(_22);
			::Parser::Types::Rule_data_block_templated_datablock_data data;
			data.second_name = second_name;
			data.first_name = first_name;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::Rule_data_block_templated_datablock, data)};
		}
		template <class IT>
		::Parser::Rule_res Rule_data_block(IT pos) {
			auto in = pos;
			::Parser::Rule _0;
			::Parser::bool_t success_1 = false;
			::Parser::Rule_res _2;
			::Parser::bool_t success_3 = false;
			::Parser::Rule_res _4;
			::Parser::bool_t success_5 = false;
			_2 = Rule_data_block_templated_datablock(pos);
			if (!(_2.status))
			{
				_4 = Rule_data_block_regular_datablock(pos);
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
			auto begin_10 = pos;
			if (!(begin_10->name() == ::Parser::Tokens::AUTO_50))
			{
				if (!(begin_10->name() == ::Parser::Tokens::PLUS))
				{
					if (!(begin_10->name() == ::Parser::Tokens::MULTIPLE))
					{
						return {};
					}
					else 
					{
						_8 = *begin_10;
						success_9 = true;
						begin_10 += 1;
						_2 = _8;
					}
				}
				else 
				{
					_6 = *begin_10;
					success_7 = true;
					begin_10 += 1;
					_2 = _6;
				}
			}
			else 
			{
				_4 = *begin_10;
				success_5 = true;
				begin_10 += 1;
				_2 = _4;
			}
			success_3 = true;
			_0 = _2;
			if (success_3)
			{
				success_1 = true;
				pos = begin_10;
			}
			::Parser::Types::Rule_quantifier_data data = _0;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::Rule_quantifier, data)};
		}
		template <class IT>
		::Parser::Rule_res Rule(IT pos) {
			auto in = pos;
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
			if (!(pos->name() == ::Parser::Tokens::AUTO_36))
			{
				reportError(pos, "auto_36");
				return {};
			}
			_2 = *pos;
			success_3 = true;
			pos += 1;
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
			_8 = Rule_data_block(pos);
			if (_8.status)
			{
				success_9 = true;
				pos += _8.node.length();
			}
			_10 = Rule_nested_rule(pos);
			while (_10.status)
			{
				success_11 = true;
				pos += _10.node.length();
				shadow_12.push_back(_10.node);
				_10 = Rule_nested_rule(pos);
			}
			if (!(pos->name() == ::Parser::Tokens::AUTO_32))
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
