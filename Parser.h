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
		NONE, __WHITESPACE, AUTO_21, AUTO_18, AUTO_11, AUTO_7, AUTO_6, AUTO_3, AUTO_2, AUTO_1, AUTO_0, rule_BIN, rule_HEX, AUTO_14, rule_NOSPACE, rule_ANY, AUTO_8, rule_CSEQUENCE_ESCAPE, rule_QUANTIFIER, rule_CSEQUENCE_SYMBOL, rule_OP, AUTO_17, cll_COMPARE_OP, AUTO_9, AUTO_5, rule_ESCAPED, cll_OP, AUTO_15, rule_CSEQUENCE, LINEAR_COMMENT, AUTO_10, cll_ASSIGNMENT_OP, AUTO_19, cll_TEMPLATE, cll_LOGICAL_NOT, cll_LOGICAL_OP, cll_TYPE, AUTO_12, cll_LOGICAL_OR, STRING, NEWLINE, NUMBER, AUTO_16, AUTO_4, BOOLEAN, STRICT_END, SPACEMODE, AUTO_13, rule_CSEQUENCE_DIAPASON, cll_LOGICAL_AND, QUESTION_MARK, PLUS, MINUS, DIVIDE, MULTIPLE, MODULO, AT, ID, NAME, AUTO_20, END
	};
	enum class Rules {
		NONE, rule_data_block_templated_datablock, rule_data_block_regular_datablock_key, cll_loop_while, cll_method_call, cll_expr_group, cll_expr_logical, cll__var, cll_function_call, cll, cll_expr_compare, cll_expr_arithmetic, cll__if, cll_function_parameters, cll_function_arguments, cll_function_decl, cll__variable, cll_expr, cll_function_body_call, cll_stmt, rule, rule_value, rule_data_block, cll_function_body_decl, rule_name, array, rule_member, cll_expr_value, object, rvalue, cll_expr_term, rule_keyvalue, rule_group, cll_loop_for, rule_nested_rule, rule_data_block_regular_datablock
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
			case Tokens::AUTO_21: return "AUTO_21";
			case Tokens::AUTO_18: return "AUTO_18";
			case Tokens::AUTO_11: return "AUTO_11";
			case Tokens::AUTO_7: return "AUTO_7";
			case Tokens::AUTO_6: return "AUTO_6";
			case Tokens::AUTO_3: return "AUTO_3";
			case Tokens::AUTO_2: return "AUTO_2";
			case Tokens::AUTO_1: return "AUTO_1";
			case Tokens::AUTO_0: return "AUTO_0";
			case Tokens::rule_BIN: return "rule_BIN";
			case Tokens::rule_HEX: return "rule_HEX";
			case Tokens::AUTO_14: return "AUTO_14";
			case Tokens::rule_NOSPACE: return "rule_NOSPACE";
			case Tokens::rule_ANY: return "rule_ANY";
			case Tokens::AUTO_8: return "AUTO_8";
			case Tokens::rule_CSEQUENCE_ESCAPE: return "rule_CSEQUENCE_ESCAPE";
			case Tokens::rule_QUANTIFIER: return "rule_QUANTIFIER";
			case Tokens::rule_CSEQUENCE_SYMBOL: return "rule_CSEQUENCE_SYMBOL";
			case Tokens::rule_OP: return "rule_OP";
			case Tokens::AUTO_17: return "AUTO_17";
			case Tokens::cll_COMPARE_OP: return "cll_COMPARE_OP";
			case Tokens::AUTO_9: return "AUTO_9";
			case Tokens::AUTO_5: return "AUTO_5";
			case Tokens::rule_ESCAPED: return "rule_ESCAPED";
			case Tokens::cll_OP: return "cll_OP";
			case Tokens::AUTO_15: return "AUTO_15";
			case Tokens::rule_CSEQUENCE: return "rule_CSEQUENCE";
			case Tokens::LINEAR_COMMENT: return "LINEAR_COMMENT";
			case Tokens::AUTO_10: return "AUTO_10";
			case Tokens::cll_ASSIGNMENT_OP: return "cll_ASSIGNMENT_OP";
			case Tokens::AUTO_19: return "AUTO_19";
			case Tokens::cll_TEMPLATE: return "cll_TEMPLATE";
			case Tokens::cll_LOGICAL_NOT: return "cll_LOGICAL_NOT";
			case Tokens::cll_LOGICAL_OP: return "cll_LOGICAL_OP";
			case Tokens::cll_TYPE: return "cll_TYPE";
			case Tokens::AUTO_12: return "AUTO_12";
			case Tokens::cll_LOGICAL_OR: return "cll_LOGICAL_OR";
			case Tokens::STRING: return "STRING";
			case Tokens::NEWLINE: return "NEWLINE";
			case Tokens::NUMBER: return "NUMBER";
			case Tokens::AUTO_16: return "AUTO_16";
			case Tokens::AUTO_4: return "AUTO_4";
			case Tokens::BOOLEAN: return "BOOLEAN";
			case Tokens::STRICT_END: return "STRICT_END";
			case Tokens::SPACEMODE: return "SPACEMODE";
			case Tokens::AUTO_13: return "AUTO_13";
			case Tokens::rule_CSEQUENCE_DIAPASON: return "rule_CSEQUENCE_DIAPASON";
			case Tokens::cll_LOGICAL_AND: return "cll_LOGICAL_AND";
			case Tokens::QUESTION_MARK: return "QUESTION_MARK";
			case Tokens::PLUS: return "PLUS";
			case Tokens::MINUS: return "MINUS";
			case Tokens::DIVIDE: return "DIVIDE";
			case Tokens::MULTIPLE: return "MULTIPLE";
			case Tokens::MODULO: return "MODULO";
			case Tokens::AT: return "AT";
			case Tokens::ID: return "ID";
			case Tokens::NAME: return "NAME";
			case Tokens::AUTO_20: return "AUTO_20";
			case Tokens::END: return "END";
		}
		return "NONE";
	}
	constexpr const char* RulesToString(Rules rule) {
		switch (rule) {
			case Rules::NONE: return "NONE";
			case Rules::rule_data_block_templated_datablock: return "rule_data_block_templated_datablock";
			case Rules::rule_data_block_regular_datablock_key: return "rule_data_block_regular_datablock_key";
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
			case Rules::array: return "array";
			case Rules::rule_member: return "rule_member";
			case Rules::cll_expr_value: return "cll_expr_value";
			case Rules::object: return "object";
			case Rules::rvalue: return "rvalue";
			case Rules::cll_expr_term: return "cll_expr_term";
			case Rules::rule_keyvalue: return "rule_keyvalue";
			case Rules::rule_group: return "rule_group";
			case Rules::cll_loop_for: return "cll_loop_for";
			case Rules::rule_nested_rule: return "rule_nested_rule";
			case Rules::rule_data_block_regular_datablock: return "rule_data_block_regular_datablock";
		}
		return "NONE";
	}
	namespace Types {
		using cll_OP = ::Parser::UNDEF;
		using rule_ESCAPED = ::Parser::str_t;
		using AUTO_15 = ::Parser::str_t;
		using AUTO_9 = ::Parser::str_t;
		using rule_CSEQUENCE_SYMBOL = ::Parser::UNDEF;
		using rule_QUANTIFIER = ::Parser::UNDEF;
		using AUTO_1 = ::Parser::str_t;
		using AUTO_17 = ::Parser::str_t;
		using cll_COMPARE_OP = ::Parser::UNDEF;
		using AUTO_21 = ::Parser::str_t;
		using AUTO_0 = ::Parser::str_t;
		using AUTO_3 = ::Parser::str_t;
		using AUTO_18 = ::Parser::str_t;
		using AUTO_14 = ::Parser::str_t;
		using AUTO_5 = ::Parser::str_t;
		using AUTO_7 = ::Parser::str_t;
		using AUTO_6 = ::Parser::str_t;
		using AUTO_8 = ::Parser::str_t;
		using rule_CSEQUENCE_ESCAPE = ::Parser::str_t;
		using BOOLEAN = ::Parser::UNDEF;
		using AUTO_11 = ::Parser::str_t;
		using STRING = ::Parser::str_t;
		using rule_BIN = ::Parser::str_t;
		using AUTO_2 = ::Parser::str_t;
		using rule_HEX = ::Parser::str_t;
		using AUTO_10 = ::Parser::str_t;
		using cll_ASSIGNMENT_OP = ::Parser::str_t;
		using AUTO_19 = ::Parser::str_t;
		using NAME = ::Parser::UNDEF;
		using AUTO_12 = ::Parser::str_t;
		using cll_LOGICAL_OP = ::Parser::UNDEF;
		using AUTO_4 = ::Parser::str_t;
		using AUTO_16 = ::Parser::str_t;
		using SPACEMODE = ::Parser::UNDEF;
		using AUTO_13 = ::Parser::str_t;
		using ID = ::Parser::str_t;
		using AUTO_20 = ::Parser::str_t;
		using rule_data_block_regular_datablock = ::Parser::UNDEF;
		using rule_nested_rule = ::Parser::UNDEF;
		using rule_group = ::Parser::UNDEF;
		using rule_keyvalue = ::Parser::Token;
		using cll = ::Parser::UNDEF;
		using cll_stmt = ::Parser::UNDEF;
		using rvalue = ::Parser::UNDEF;
		using cll_expr_group = ::Parser::UNDEF;
		using cll_expr = ::Parser::UNDEF;
		using cll_function_body_call = ::Parser::UNDEF;
		using rule_value = ::Parser::Token;
		using rule_data_block = ::Parser::UNDEF;
		using cll_function_body_decl = ::Parser::UNDEF;
		using array = ::Parser::UNDEF;
		using cll_expr_value = ::Parser::UNDEF;
	}

	namespace get {
		const ::Parser::Types::cll_OP& cll_OP(const ::Parser::Token &token);
		::Parser::Types::cll_OP& cll_OP(::Parser::Token &token);
		const ::Parser::Types::rule_ESCAPED& rule_ESCAPED(const ::Parser::Token &token);
		::Parser::Types::rule_ESCAPED& rule_ESCAPED(::Parser::Token &token);
		const ::Parser::Types::AUTO_15& AUTO_15(const ::Parser::Token &token);
		::Parser::Types::AUTO_15& AUTO_15(::Parser::Token &token);
		const ::Parser::Types::AUTO_9& AUTO_9(const ::Parser::Token &token);
		::Parser::Types::AUTO_9& AUTO_9(::Parser::Token &token);
		const ::Parser::Types::rule_CSEQUENCE_SYMBOL& rule_CSEQUENCE_SYMBOL(const ::Parser::Token &token);
		::Parser::Types::rule_CSEQUENCE_SYMBOL& rule_CSEQUENCE_SYMBOL(::Parser::Token &token);
		const ::Parser::Types::rule_QUANTIFIER& rule_QUANTIFIER(const ::Parser::Token &token);
		::Parser::Types::rule_QUANTIFIER& rule_QUANTIFIER(::Parser::Token &token);
		const ::Parser::Types::AUTO_1& AUTO_1(const ::Parser::Token &token);
		::Parser::Types::AUTO_1& AUTO_1(::Parser::Token &token);
		const ::Parser::Types::AUTO_17& AUTO_17(const ::Parser::Token &token);
		::Parser::Types::AUTO_17& AUTO_17(::Parser::Token &token);
		const ::Parser::Types::cll_COMPARE_OP& cll_COMPARE_OP(const ::Parser::Token &token);
		::Parser::Types::cll_COMPARE_OP& cll_COMPARE_OP(::Parser::Token &token);
		const ::Parser::Types::AUTO_21& AUTO_21(const ::Parser::Token &token);
		::Parser::Types::AUTO_21& AUTO_21(::Parser::Token &token);
		const ::Parser::Types::AUTO_0& AUTO_0(const ::Parser::Token &token);
		::Parser::Types::AUTO_0& AUTO_0(::Parser::Token &token);
		const ::Parser::Types::AUTO_3& AUTO_3(const ::Parser::Token &token);
		::Parser::Types::AUTO_3& AUTO_3(::Parser::Token &token);
		const ::Parser::Types::AUTO_18& AUTO_18(const ::Parser::Token &token);
		::Parser::Types::AUTO_18& AUTO_18(::Parser::Token &token);
		const ::Parser::Types::AUTO_14& AUTO_14(const ::Parser::Token &token);
		::Parser::Types::AUTO_14& AUTO_14(::Parser::Token &token);
		const ::Parser::Types::AUTO_5& AUTO_5(const ::Parser::Token &token);
		::Parser::Types::AUTO_5& AUTO_5(::Parser::Token &token);
		const ::Parser::Types::AUTO_7& AUTO_7(const ::Parser::Token &token);
		::Parser::Types::AUTO_7& AUTO_7(::Parser::Token &token);
		const ::Parser::Types::AUTO_6& AUTO_6(const ::Parser::Token &token);
		::Parser::Types::AUTO_6& AUTO_6(::Parser::Token &token);
		const ::Parser::Types::AUTO_8& AUTO_8(const ::Parser::Token &token);
		::Parser::Types::AUTO_8& AUTO_8(::Parser::Token &token);
		const ::Parser::Types::rule_CSEQUENCE_ESCAPE& rule_CSEQUENCE_ESCAPE(const ::Parser::Token &token);
		::Parser::Types::rule_CSEQUENCE_ESCAPE& rule_CSEQUENCE_ESCAPE(::Parser::Token &token);
		const ::Parser::Types::BOOLEAN& BOOLEAN(const ::Parser::Token &token);
		::Parser::Types::BOOLEAN& BOOLEAN(::Parser::Token &token);
		const ::Parser::Types::AUTO_11& AUTO_11(const ::Parser::Token &token);
		::Parser::Types::AUTO_11& AUTO_11(::Parser::Token &token);
		const ::Parser::Types::STRING& STRING(const ::Parser::Token &token);
		::Parser::Types::STRING& STRING(::Parser::Token &token);
		const ::Parser::Types::rule_BIN& rule_BIN(const ::Parser::Token &token);
		::Parser::Types::rule_BIN& rule_BIN(::Parser::Token &token);
		const ::Parser::Types::AUTO_2& AUTO_2(const ::Parser::Token &token);
		::Parser::Types::AUTO_2& AUTO_2(::Parser::Token &token);
		const ::Parser::Types::rule_HEX& rule_HEX(const ::Parser::Token &token);
		::Parser::Types::rule_HEX& rule_HEX(::Parser::Token &token);
		const ::Parser::Types::AUTO_10& AUTO_10(const ::Parser::Token &token);
		::Parser::Types::AUTO_10& AUTO_10(::Parser::Token &token);
		const ::Parser::Types::cll_ASSIGNMENT_OP& cll_ASSIGNMENT_OP(const ::Parser::Token &token);
		::Parser::Types::cll_ASSIGNMENT_OP& cll_ASSIGNMENT_OP(::Parser::Token &token);
		const ::Parser::Types::AUTO_19& AUTO_19(const ::Parser::Token &token);
		::Parser::Types::AUTO_19& AUTO_19(::Parser::Token &token);
		const ::Parser::Types::NAME& NAME(const ::Parser::Token &token);
		::Parser::Types::NAME& NAME(::Parser::Token &token);
		const ::Parser::Types::AUTO_12& AUTO_12(const ::Parser::Token &token);
		::Parser::Types::AUTO_12& AUTO_12(::Parser::Token &token);
		const ::Parser::Types::cll_LOGICAL_OP& cll_LOGICAL_OP(const ::Parser::Token &token);
		::Parser::Types::cll_LOGICAL_OP& cll_LOGICAL_OP(::Parser::Token &token);
		const ::Parser::Types::AUTO_4& AUTO_4(const ::Parser::Token &token);
		::Parser::Types::AUTO_4& AUTO_4(::Parser::Token &token);
		const ::Parser::Types::AUTO_16& AUTO_16(const ::Parser::Token &token);
		::Parser::Types::AUTO_16& AUTO_16(::Parser::Token &token);
		const ::Parser::Types::SPACEMODE& SPACEMODE(const ::Parser::Token &token);
		::Parser::Types::SPACEMODE& SPACEMODE(::Parser::Token &token);
		const ::Parser::Types::AUTO_13& AUTO_13(const ::Parser::Token &token);
		::Parser::Types::AUTO_13& AUTO_13(::Parser::Token &token);
		const ::Parser::Types::ID& ID(const ::Parser::Token &token);
		::Parser::Types::ID& ID(::Parser::Token &token);
		const ::Parser::Types::AUTO_20& AUTO_20(const ::Parser::Token &token);
		::Parser::Types::AUTO_20& AUTO_20(::Parser::Token &token);
		const ::Parser::Types::rule_data_block_regular_datablock& rule_data_block_regular_datablock(const ::Parser::Rule &rule);
		::Parser::Types::rule_data_block_regular_datablock& rule_data_block_regular_datablock(::Parser::Rule &rule);
		const ::Parser::Types::rule_nested_rule& rule_nested_rule(const ::Parser::Rule &rule);
		::Parser::Types::rule_nested_rule& rule_nested_rule(::Parser::Rule &rule);
		const ::Parser::Types::rule_group& rule_group(const ::Parser::Rule &rule);
		::Parser::Types::rule_group& rule_group(::Parser::Rule &rule);
		const ::Parser::Types::rule_keyvalue& rule_keyvalue(const ::Parser::Rule &rule);
		::Parser::Types::rule_keyvalue& rule_keyvalue(::Parser::Rule &rule);
		const ::Parser::Types::cll& cll(const ::Parser::Rule &rule);
		::Parser::Types::cll& cll(::Parser::Rule &rule);
		const ::Parser::Types::cll_stmt& cll_stmt(const ::Parser::Rule &rule);
		::Parser::Types::cll_stmt& cll_stmt(::Parser::Rule &rule);
		const ::Parser::Types::rvalue& rvalue(const ::Parser::Rule &rule);
		::Parser::Types::rvalue& rvalue(::Parser::Rule &rule);
		const ::Parser::Types::cll_expr_group& cll_expr_group(const ::Parser::Rule &rule);
		::Parser::Types::cll_expr_group& cll_expr_group(::Parser::Rule &rule);
		const ::Parser::Types::cll_expr& cll_expr(const ::Parser::Rule &rule);
		::Parser::Types::cll_expr& cll_expr(::Parser::Rule &rule);
		const ::Parser::Types::cll_function_body_call& cll_function_body_call(const ::Parser::Rule &rule);
		::Parser::Types::cll_function_body_call& cll_function_body_call(::Parser::Rule &rule);
		const ::Parser::Types::rule_value& rule_value(const ::Parser::Rule &rule);
		::Parser::Types::rule_value& rule_value(::Parser::Rule &rule);
		const ::Parser::Types::rule_data_block& rule_data_block(const ::Parser::Rule &rule);
		::Parser::Types::rule_data_block& rule_data_block(::Parser::Rule &rule);
		const ::Parser::Types::cll_function_body_decl& cll_function_body_decl(const ::Parser::Rule &rule);
		::Parser::Types::cll_function_body_decl& cll_function_body_decl(::Parser::Rule &rule);
		const ::Parser::Types::array& array(const ::Parser::Rule &rule);
		::Parser::Types::array& array(::Parser::Rule &rule);
		const ::Parser::Types::cll_expr_value& cll_expr_value(const ::Parser::Rule &rule);
		::Parser::Types::cll_expr_value& cll_expr_value(::Parser::Rule &rule);
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
			Token_res AUTO_21(const char*);
			Token_res AUTO_18(const char*);
			Token_res AUTO_11(const char*);
			Token_res AUTO_7(const char*);
			Token_res AUTO_6(const char*);
			Token_res AUTO_3(const char*);
			Token_res AUTO_2(const char*);
			Token_res AUTO_1(const char*);
			Token_res AUTO_0(const char*);
			Token_res rule_BIN(const char*);
			Token_res rule_HEX(const char*);
			Token_res AUTO_14(const char*);
			Token_res rule_NOSPACE(const char*);
			Token_res rule_ANY(const char*);
			Token_res AUTO_8(const char*);
			Token_res rule_CSEQUENCE_ESCAPE(const char*);
			Token_res rule_QUANTIFIER(const char*);
			Token_res rule_CSEQUENCE_SYMBOL(const char*);
			Token_res rule_OP(const char*);
			Token_res AUTO_17(const char*);
			Token_res cll_COMPARE_OP(const char*);
			Token_res AUTO_9(const char*);
			Token_res AUTO_5(const char*);
			Token_res rule_ESCAPED(const char*);
			Token_res cll_OP(const char*);
			Token_res AUTO_15(const char*);
			Token_res rule_CSEQUENCE(const char*);
			Token_res LINEAR_COMMENT(const char*);
			Token_res AUTO_10(const char*);
			Token_res cll_ASSIGNMENT_OP(const char*);
			Token_res AUTO_19(const char*);
			Token_res cll_TEMPLATE(const char*);
			Token_res cll_LOGICAL_NOT(const char*);
			Token_res cll_LOGICAL_OP(const char*);
			Token_res cll_TYPE(const char*);
			Token_res AUTO_12(const char*);
			Token_res cll_LOGICAL_OR(const char*);
			Token_res STRING(const char*);
			Token_res NEWLINE(const char*);
			Token_res NUMBER(const char*);
			Token_res AUTO_16(const char*);
			Token_res AUTO_4(const char*);
			Token_res BOOLEAN(const char*);
			Token_res STRICT_END(const char*);
			Token_res SPACEMODE(const char*);
			Token_res AUTO_13(const char*);
			Token_res rule_CSEQUENCE_DIAPASON(const char*);
			Token_res cll_LOGICAL_AND(const char*);
			Token_res QUESTION_MARK(const char*);
			Token_res PLUS(const char*);
			Token_res MINUS(const char*);
			Token_res DIVIDE(const char*);
			Token_res MULTIPLE(const char*);
			Token_res MODULO(const char*);
			Token_res AT(const char*);
			Token_res ID(const char*);
			Token_res NAME(const char*);
			Token_res AUTO_20(const char*);
			Token_res END(const char*);
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
		::Parser::Rule_res rule_data_block_templated_datablock(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Token ;
			if (!(pos->name() == ::Parser::Tokens::AUTO_0))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::Token _2;
			::Parser::bool_t success_3 = false;
			::Parser::Token ;
			if (!(pos->name() == ::Parser::Tokens::AUTO_1))
			{
				reportError(pos, "AUTO_1");
				return {};
			}
			_2 = *pos;
			success_3 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::bool_t success_5 = false;
			auto begin_15 = pos;
			::Parser::bool_t success_9 = false;
			::Parser::bool_t success_7 = false;
			::Parser::Token _6;
			::Parser::Token ;
			if (!(begin_15->name() == ::Parser::Tokens::ID))
			{
				reportError(pos, "ID");
				return {};
			}
			_6 = *begin_15;
			success_7 = true;
			begin_15 += 1;
			skip_spaces(begin_15);
			auto begin_14 = begin_15;
			::Parser::bool_t success_13 = false;
			::Parser::bool_t success_11 = false;
			::Parser::Token _10;
			::Parser::Token ;
			if (!(begin_14->name() == ::Parser::Tokens::AUTO_2))
			{
				reportError(pos, "AUTO_2");
				return {};
			}
			_10 = *begin_14;
			success_11 = true;
			begin_14 += 1;
			skip_spaces(begin_14);
			::Parser::Token _12;
			::Parser::Token ;
			if (!(begin_14->name() == ::Parser::Tokens::ID))
			{
				reportError(pos, "ID");
				return {};
			}
			_12 = *begin_14;
			success_13 = true;
			begin_14 += 1;
			::Parser::UNDEF ;
			if (success_11 && success_13)
			{
				success_9 = true;
				begin_15 = begin_14;
			}
			::Parser::UNDEF ;
			if (success_7 && success_9)
			{
				success_5 = true;
				pos = begin_15;
			}
			skip_spaces(pos);
			::Parser::Token _16;
			::Parser::bool_t success_17 = false;
			::Parser::Token ;
			if (!(pos->name() == ::Parser::Tokens::AUTO_3))
			{
				reportError(pos, "AUTO_3");
				return {};
			}
			_16 = *pos;
			success_17 = true;
			pos += 1;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::rule_data_block_templated_datablock)};
		}
		template <class IT>
		::Parser::Rule_res rule_data_block_regular_datablock_key(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Token ;
			if (!(pos->name() == ::Parser::Tokens::ID))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::Token _2;
			::Parser::bool_t success_3 = false;
			::Parser::Token ;
			if (!(pos->name() == ::Parser::Tokens::AUTO_4))
			{
				reportError(pos, "AUTO_4");
				return {};
			}
			_2 = *pos;
			success_3 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::Rule_res _4;
			::Parser::bool_t success_5 = false;
			_4 = cll_expr(pos);
			if (!(_4.status))
			{
				reportError(pos, "expr");
				return {};
			}
			success_5 = true;
			pos += _4.node.length();
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::rule_data_block_regular_datablock_key)};
		}
		template <class IT>
		::Parser::Rule_res cll_loop_while(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Token ;
			if (!(pos->name() == ::Parser::Tokens::AUTO_5))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::Rule_res _2;
			::Parser::bool_t success_3 = false;
			_2 = cll_expr(pos);
			if (!(_2.status))
			{
				reportError(pos, "expr");
				return {};
			}
			success_3 = true;
			pos += _2.node.length();
			skip_spaces(pos);
			::Parser::Rule_res _4;
			::Parser::bool_t success_5 = false;
			_4 = cll_stmt(pos);
			if (!(_4.status))
			{
				reportError(pos, "stmt");
				return {};
			}
			success_5 = true;
			pos += _4.node.length();
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_loop_while)};
		}
		template <class IT>
		::Parser::Rule_res cll_method_call(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Token ;
			if (!(pos->name() == ::Parser::Tokens::ID))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::Token _2;
			::Parser::bool_t success_3 = false;
			::Parser::Token ;
			if (!(pos->name() == ::Parser::Tokens::AUTO_6))
			{
				reportError(pos, "AUTO_6");
				return {};
			}
			_2 = *pos;
			success_3 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::Rule_res _4;
			::Parser::bool_t success_5 = false;
			_4 = cll_function_call(pos);
			if (!(_4.status))
			{
				reportError(pos, "function_call");
				return {};
			}
			success_5 = true;
			pos += _4.node.length();
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_method_call)};
		}
		template <class IT>
		::Parser::Rule_res cll_expr_group(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Token ;
			if (!(pos->name() == ::Parser::Tokens::AUTO_7))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::Rule_res _2;
			::Parser::bool_t success_3 = false;
			_2 = cll_expr(pos);
			if (!(_2.status))
			{
				reportError(pos, "expr");
				return {};
			}
			success_3 = true;
			pos += _2.node.length();
			skip_spaces(pos);
			::Parser::Token _4;
			::Parser::bool_t success_5 = false;
			::Parser::Token ;
			if (!(pos->name() == ::Parser::Tokens::AUTO_8))
			{
				reportError(pos, "AUTO_8");
				return {};
			}
			_4 = *pos;
			success_5 = true;
			pos += 1;
			::Parser::Types::cll_expr_group_data data = ;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_expr_group, data)};
		}
		template <class IT>
		::Parser::Rule_res cll_expr_logical(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Rule_res _0;
			::Parser::bool_t success_1 = false;
			_0 = cll_expr_compare(pos);
			if (!(_0.status))
			{
				return {};
			}
			success_1 = true;
			pos += _0.node.length();
			skip_spaces(pos);
			::Parser::bool_t success_3 = false;
			auto begin_8 = pos;
			::Parser::bool_t success_7 = false;
			::Parser::bool_t success_5 = false;
			::Parser::Token _4;
			::Parser::Token ;
			if (!(begin_8->name() == ::Parser::Tokens::cll_LOGICAL_OP))
			{
				reportError(pos, "LOGICAL_OP");
				return {};
			}
			_4 = *begin_8;
			success_5 = true;
			begin_8 += 1;
			skip_spaces(begin_8);
			::Parser::Rule_res _6;
			_6 = cll_expr_compare(begin_8);
			if (!(_6.status))
			{
				reportError(pos, "compare");
				return {};
			}
			success_7 = true;
			begin_8 += _6.node.length();
			::Parser::UNDEF ;
			if (success_5 && success_7)
			{
				success_3 = true;
				pos = begin_8;
			}
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_expr_logical)};
		}
		template <class IT>
		::Parser::Rule_res cll__var(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Token ;
			if (!(pos->name() == ::Parser::Tokens::cll_TYPE))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::Token _2;
			::Parser::bool_t success_3 = false;
			::Parser::Token ;
			if (!(pos->name() == ::Parser::Tokens::ID))
			{
				reportError(pos, "ID");
				return {};
			}
			_2 = *pos;
			success_3 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::bool_t success_5 = false;
			auto begin_12 = pos;
			::Parser::bool_t success_11 = false;
			::Parser::bool_t success_7 = false;
			::Parser::Token _6;
			::Parser::UNDEF ;
			::Parser::Token _8;
			::Parser::bool_t success_9 = false;
			::Parser::Token ;
			if (!(begin_12->name() == ::Parser::Tokens::cll_ASSIGNMENT_OP))
			{
				return {};
			}
			else 
			{
				_8 = *begin_12;
				success_9 = true;
				begin_12 += 1;
				_6 = _8;
			}
			success_7 = true;
			skip_spaces(begin_12);
			::Parser::Rule_res _10;
			_10 = cll_expr(begin_12);
			if (!(_10.status))
			{
				reportError(pos, "expr");
				return {};
			}
			success_11 = true;
			begin_12 += _10.node.length();
			::Parser::UNDEF ;
			if (success_7 && success_11)
			{
				success_5 = true;
				pos = begin_12;
			}
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll__var)};
		}
		template <class IT>
		::Parser::Rule_res cll_function_call(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Token ;
			if (!(pos->name() == ::Parser::Tokens::ID))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::Rule_res _2;
			::Parser::bool_t success_3 = false;
			_2 = cll_function_body_call(pos);
			if (!(_2.status))
			{
				reportError(pos, "function_body_call");
				return {};
			}
			success_3 = true;
			pos += _2.node.length();
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_function_call)};
		}
		template <class IT>
		::Parser::Rule_res cll(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Token ;
			if (!(pos->name() == ::Parser::Tokens::AUTO_9))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::Rule _2;
			::Parser::bool_t success_3 = false;
			::Parser::UNDEF ;
			::Parser::Rule_res _4;
			::Parser::bool_t success_5 = false;
			_4 = cll__var(pos);
			if (!(_4.status))
			{
				::Parser::Rule_res _6;
				::Parser::bool_t success_7 = false;
				_6 = cll__if(pos);
				if (!(_6.status))
				{
					::Parser::Rule_res _8;
					::Parser::bool_t success_9 = false;
					_8 = cll_expr(pos);
					if (!(_8.status))
					{
						::Parser::Rule_res _10;
						::Parser::bool_t success_11 = false;
						_10 = cll_loop_while(pos);
						if (!(_10.status))
						{
							::Parser::Rule_res _12;
							::Parser::bool_t success_13 = false;
							_12 = cll_loop_for(pos);
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
			::Parser::Token _14;
			::Parser::bool_t success_15 = false;
			::Parser::Token ;
			if (!(pos->name() == ::Parser::Tokens::END))
			{
				reportError(pos, "END");
				return {};
			}
			_14 = *pos;
			success_15 = true;
			pos += 1;
			::Parser::Types::cll_data data = ;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll, data)};
		}
		template <class IT>
		::Parser::Rule_res cll_expr_compare(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Rule_res _0;
			::Parser::bool_t success_1 = false;
			_0 = cll_expr_arithmetic(pos);
			if (!(_0.status))
			{
				return {};
			}
			success_1 = true;
			pos += _0.node.length();
			skip_spaces(pos);
			::Parser::bool_t success_3 = false;
			auto begin_8 = pos;
			::Parser::bool_t success_7 = false;
			::Parser::bool_t success_5 = false;
			::Parser::Token _4;
			::Parser::Token ;
			if (!(begin_8->name() == ::Parser::Tokens::cll_COMPARE_OP))
			{
				reportError(pos, "COMPARE_OP");
				return {};
			}
			_4 = *begin_8;
			success_5 = true;
			begin_8 += 1;
			skip_spaces(begin_8);
			::Parser::Rule_res _6;
			_6 = cll_expr_arithmetic(begin_8);
			if (!(_6.status))
			{
				reportError(pos, "arithmetic");
				return {};
			}
			success_7 = true;
			begin_8 += _6.node.length();
			::Parser::UNDEF ;
			if (success_5 && success_7)
			{
				success_3 = true;
				pos = begin_8;
			}
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_expr_compare)};
		}
		template <class IT>
		::Parser::Rule_res cll_expr_arithmetic(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Rule_res _0;
			::Parser::bool_t success_1 = false;
			_0 = cll_expr_term(pos);
			if (!(_0.status))
			{
				return {};
			}
			success_1 = true;
			pos += _0.node.length();
			skip_spaces(pos);
			::Parser::bool_t success_3 = false;
			auto begin_12 = pos;
			::Parser::bool_t success_11 = false;
			::Parser::bool_t success_5 = false;
			::Parser::Token _4;
			::Parser::UNDEF ;
			::Parser::Token _6;
			::Parser::bool_t success_7 = false;
			::Parser::Token ;
			if (!(begin_12->name() == ::Parser::Tokens::PLUS))
			{
				::Parser::Token _8;
				::Parser::bool_t success_9 = false;
				::Parser::Token ;
				if (!(begin_12->name() == ::Parser::Tokens::MINUS))
				{
					return {};
				}
				else 
				{
					_8 = *begin_12;
					success_9 = true;
					begin_12 += 1;
					_4 = _8;
				}
			}
			else 
			{
				_6 = *begin_12;
				success_7 = true;
				begin_12 += 1;
				_4 = _6;
			}
			success_5 = true;
			skip_spaces(begin_12);
			::Parser::Rule_res _10;
			_10 = cll_expr_term(begin_12);
			if (!(_10.status))
			{
				reportError(pos, "term");
				return {};
			}
			success_11 = true;
			begin_12 += _10.node.length();
			::Parser::UNDEF ;
			if (success_5 && success_11)
			{
				success_3 = true;
				pos = begin_12;
			}
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_expr_arithmetic)};
		}
		template <class IT>
		::Parser::Rule_res cll__if(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Token ;
			if (!(pos->name() == ::Parser::Tokens::AUTO_10))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::Rule_res _2;
			::Parser::bool_t success_3 = false;
			_2 = cll_expr(pos);
			if (!(_2.status))
			{
				reportError(pos, "expr");
				return {};
			}
			success_3 = true;
			pos += _2.node.length();
			skip_spaces(pos);
			::Parser::Rule_res _4;
			::Parser::bool_t success_5 = false;
			_4 = cll_stmt(pos);
			if (!(_4.status))
			{
				reportError(pos, "stmt");
				return {};
			}
			success_5 = true;
			pos += _4.node.length();
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll__if)};
		}
		template <class IT>
		::Parser::Rule_res cll_function_parameters(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::bool_t success_1 = false;
			success_1 = false;
			auto begin_11 = pos;
			::Parser::bool_t success_5 = false;
			::Parser::bool_t success_3 = false;
			::Parser::Token _2;
			::Parser::Token ;
			if (!(begin_11->name() == ::Parser::Tokens::ID))
			{
				return {};
			}
			_2 = *begin_11;
			success_3 = true;
			begin_11 += 1;
			skip_spaces(begin_11);
			auto begin_10 = begin_11;
			::Parser::bool_t success_9 = false;
			::Parser::bool_t success_7 = false;
			::Parser::Token _6;
			::Parser::Token ;
			if (!(begin_10->name() == ::Parser::Tokens::AUTO_2))
			{
				reportError(pos, "AUTO_2");
				return {};
			}
			_6 = *begin_10;
			success_7 = true;
			begin_10 += 1;
			skip_spaces(begin_10);
			::Parser::Token _8;
			::Parser::Token ;
			if (!(begin_10->name() == ::Parser::Tokens::ID))
			{
				reportError(pos, "ID");
				return {};
			}
			_8 = *begin_10;
			success_9 = true;
			begin_10 += 1;
			::Parser::UNDEF ;
			if (success_7 && success_9)
			{
				success_5 = true;
				begin_11 = begin_10;
			}
			::Parser::UNDEF ;
			if (success_3 && success_5)
			{
				success_1 = true;
				pos = begin_11;
			}
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_function_parameters)};
		}
		template <class IT>
		::Parser::Rule_res cll_function_arguments(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::bool_t success_1 = false;
			success_1 = false;
			auto begin_11 = pos;
			::Parser::bool_t success_5 = false;
			::Parser::bool_t success_3 = false;
			::Parser::Rule_res _2;
			_2 = cll_expr(begin_11);
			if (!(_2.status))
			{
				return {};
			}
			success_3 = true;
			begin_11 += _2.node.length();
			skip_spaces(begin_11);
			auto begin_10 = begin_11;
			::Parser::bool_t success_9 = false;
			::Parser::bool_t success_7 = false;
			::Parser::Token _6;
			::Parser::Token ;
			if (!(begin_10->name() == ::Parser::Tokens::AUTO_2))
			{
				reportError(pos, "AUTO_2");
				return {};
			}
			_6 = *begin_10;
			success_7 = true;
			begin_10 += 1;
			skip_spaces(begin_10);
			::Parser::Rule_res _8;
			_8 = cll_expr(begin_10);
			if (!(_8.status))
			{
				reportError(pos, "expr");
				return {};
			}
			success_9 = true;
			begin_10 += _8.node.length();
			::Parser::UNDEF ;
			if (success_7 && success_9)
			{
				success_5 = true;
				begin_11 = begin_10;
			}
			::Parser::UNDEF ;
			if (success_3 && success_5)
			{
				success_1 = true;
				pos = begin_11;
			}
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_function_arguments)};
		}
		template <class IT>
		::Parser::Rule_res cll_function_decl(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Token ;
			if (!(pos->name() == ::Parser::Tokens::AUTO_11))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::Token _2;
			::Parser::bool_t success_3 = false;
			::Parser::Token ;
			if (!(pos->name() == ::Parser::Tokens::ID))
			{
				reportError(pos, "ID");
				return {};
			}
			_2 = *pos;
			success_3 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::Rule_res _4;
			::Parser::bool_t success_5 = false;
			_4 = cll_function_body_decl(pos);
			if (!(_4.status))
			{
				reportError(pos, "function_body_decl");
				return {};
			}
			success_5 = true;
			pos += _4.node.length();
			skip_spaces(pos);
			::Parser::Rule_res _6;
			::Parser::bool_t success_7 = false;
			_6 = cll_stmt(pos);
			if (!(_6.status))
			{
				reportError(pos, "stmt");
				return {};
			}
			success_7 = true;
			pos += _6.node.length();
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_function_decl)};
		}
		template <class IT>
		::Parser::Rule_res cll__variable(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::UNDEF ;
			::Parser::Token _2;
			::Parser::bool_t success_3 = false;
			::Parser::Token ;
			if (!(pos->name() == ::Parser::Tokens::AUTO_12))
			{
				::Parser::Token _4;
				::Parser::bool_t success_5 = false;
				::Parser::Token ;
				if (!(pos->name() == ::Parser::Tokens::AUTO_13))
				{
					return {};
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
			skip_spaces(pos);
			::Parser::Token _6;
			::Parser::bool_t success_7 = false;
			::Parser::Token ;
			if (!(pos->name() == ::Parser::Tokens::ID))
			{
				reportError(pos, "ID");
				return {};
			}
			_6 = *pos;
			success_7 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::bool_t success_9 = false;
			auto begin_16 = pos;
			::Parser::bool_t success_15 = false;
			::Parser::bool_t success_13 = false;
			::Parser::bool_t success_11 = false;
			::Parser::Token _10;
			::Parser::Token ;
			if (!(begin_16->name() == ::Parser::Tokens::AUTO_14))
			{
				reportError(pos, "AUTO_14");
				return {};
			}
			_10 = *begin_16;
			success_11 = true;
			begin_16 += 1;
			skip_spaces(begin_16);
			::Parser::Rule_res _12;
			_12 = cll_expr(begin_16);
			if (!(_12.status))
			{
				reportError(pos, "expr");
				return {};
			}
			success_13 = true;
			begin_16 += _12.node.length();
			skip_spaces(begin_16);
			::Parser::Token _14;
			::Parser::Token ;
			if (!(begin_16->name() == ::Parser::Tokens::AUTO_15))
			{
				reportError(pos, "AUTO_15");
				return {};
			}
			_14 = *begin_16;
			success_15 = true;
			begin_16 += 1;
			::Parser::UNDEF ;
			if (success_11 && success_13 && success_15)
			{
				success_9 = true;
				pos = begin_16;
			}
			skip_spaces(pos);
			::Parser::Token _17;
			::Parser::bool_t success_18 = false;
			::Parser::UNDEF ;
			::Parser::Token _19;
			::Parser::bool_t success_20 = false;
			::Parser::Token ;
			if (!(pos->name() == ::Parser::Tokens::AUTO_12))
			{
				::Parser::Token _21;
				::Parser::bool_t success_22 = false;
				::Parser::Token ;
				if (!(pos->name() == ::Parser::Tokens::AUTO_13))
				{
					return {};
				}
				else 
				{
					_21 = *pos;
					success_22 = true;
					pos += 1;
					_17 = _21;
				}
			}
			else 
			{
				_19 = *pos;
				success_20 = true;
				pos += 1;
				_17 = _19;
			}
			success_18 = true;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll__variable)};
		}
		template <class IT>
		::Parser::Rule_res cll_expr(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Rule_res _0;
			::Parser::bool_t success_1 = false;
			_0 = cll_expr_logical(pos);
			if (!(_0.status))
			{
				return {};
			}
			success_1 = true;
			pos += _0.node.length();
			::Parser::Types::cll_expr_data data = ;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_expr, data)};
		}
		template <class IT>
		::Parser::Rule_res cll_function_body_call(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Token ;
			if (!(pos->name() == ::Parser::Tokens::AUTO_7))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::Rule_res _2;
			::Parser::bool_t success_3 = false;
			_2 = cll_function_arguments(pos);
			if (!(_2.status))
			{
				reportError(pos, "function_arguments");
				return {};
			}
			success_3 = true;
			pos += _2.node.length();
			skip_spaces(pos);
			::Parser::Token _4;
			::Parser::bool_t success_5 = false;
			::Parser::Token ;
			if (!(pos->name() == ::Parser::Tokens::AUTO_8))
			{
				reportError(pos, "AUTO_8");
				return {};
			}
			_4 = *pos;
			success_5 = true;
			pos += 1;
			::Parser::Types::cll_function_body_call_data data = ;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_function_body_call, data)};
		}
		template <class IT>
		::Parser::Rule_res cll_stmt(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Token ;
			if (!(pos->name() == ::Parser::Tokens::AUTO_1))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::Rule_res _2;
			::Parser::bool_t success_3 = false;
			_2 = rule_member(pos);
			if (!(_2.status))
			{
				reportError(pos, "member");
				return {};
			}
			success_3 = true;
			pos += _2.node.length();
			skip_spaces(pos);
			::Parser::Token _4;
			::Parser::bool_t success_5 = false;
			::Parser::Token ;
			if (!(pos->name() == ::Parser::Tokens::AUTO_3))
			{
				reportError(pos, "AUTO_3");
				return {};
			}
			_4 = *pos;
			success_5 = true;
			pos += 1;
			::Parser::Types::cll_stmt_data data = ;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_stmt, data)};
		}
		template <class IT>
		::Parser::Rule_res rule(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Token ;
			if (!(pos->name() == ::Parser::Tokens::ID))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::Token _2;
			::Parser::bool_t success_3 = false;
			::Parser::Token ;
			if (!(pos->name() == ::Parser::Tokens::AUTO_16))
			{
				reportError(pos, "AUTO_16");
				return {};
			}
			_2 = *pos;
			success_3 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::Rule_res _4;
			::Parser::bool_t success_5 = false;
			_4 = rule_rule(pos);
			if (!(_4.status))
			{
				reportError(pos, "rule");
				return {};
			}
			success_5 = true;
			pos += _4.node.length();
			skip_spaces(pos);
			::Parser::Rule_res _6;
			::Parser::bool_t success_7 = false;
			_6 = rule_data_block(pos);
			if (!(_6.status))
			{
				reportError(pos, "data_block");
				return {};
			}
			success_7 = true;
			pos += _6.node.length();
			skip_spaces(pos);
			::Parser::Rule_res _8;
			::Parser::bool_t success_9 = false;
			_8 = rule_nested_rule(pos);
			if (!(_8.status))
			{
				reportError(pos, "nested_rule");
				return {};
			}
			success_9 = true;
			pos += _8.node.length();
			skip_spaces(pos);
			::Parser::Token _10;
			::Parser::bool_t success_11 = false;
			::Parser::Token ;
			if (!(pos->name() == ::Parser::Tokens::STRICT_END))
			{
				reportError(pos, "STRICT_END");
				return {};
			}
			_10 = *pos;
			success_11 = true;
			pos += 1;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::rule)};
		}
		template <class IT>
		::Parser::Rule_res rule_value(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Token ;
			if (!(pos->name() == ::Parser::Tokens::AUTO_17))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::Token _2;
			::Parser::bool_t success_3 = false;
			::Parser::Token ;
			if (!(pos->name() == ::Parser::Tokens::ID))
			{
				reportError(pos, "ID");
				return {};
			}
			_2 = *pos;
			success_3 = true;
			pos += 1;
			::Parser::Types::rule_value_data data = ;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::rule_value, data)};
		}
		template <class IT>
		::Parser::Rule_res rule_data_block(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Rule _0;
			::Parser::bool_t success_1 = false;
			::Parser::UNDEF ;
			::Parser::Rule_res _2;
			::Parser::bool_t success_3 = false;
			_2 = rule_data_block_templated_datablock(pos);
			if (!(_2.status))
			{
				::Parser::Rule_res _4;
				::Parser::bool_t success_5 = false;
				_4 = rule_data_block_regular_datablock(pos);
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
			::Parser::Types::rule_data_block_data data = ;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::rule_data_block, data)};
		}
		template <class IT>
		::Parser::Rule_res cll_function_body_decl(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Token ;
			if (!(pos->name() == ::Parser::Tokens::AUTO_7))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::Rule_res _2;
			::Parser::bool_t success_3 = false;
			_2 = cll_function_parameters(pos);
			if (!(_2.status))
			{
				reportError(pos, "function_parameters");
				return {};
			}
			success_3 = true;
			pos += _2.node.length();
			skip_spaces(pos);
			::Parser::Token _4;
			::Parser::bool_t success_5 = false;
			::Parser::Token ;
			if (!(pos->name() == ::Parser::Tokens::AUTO_8))
			{
				reportError(pos, "AUTO_8");
				return {};
			}
			_4 = *pos;
			success_5 = true;
			pos += 1;
			::Parser::Types::cll_function_body_decl_data data = ;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_function_body_decl, data)};
		}
		template <class IT>
		::Parser::Rule_res rule_name(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Token ;
			if (!(pos->name() == ::Parser::Tokens::AUTO_18))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::Token _2;
			::Parser::bool_t success_3 = false;
			::Parser::Token ;
			if (!(pos->name() == ::Parser::Tokens::ID))
			{
				reportError(pos, "ID");
				return {};
			}
			_2 = *pos;
			success_3 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::bool_t success_5 = false;
			auto begin_10 = pos;
			::Parser::bool_t success_9 = false;
			::Parser::bool_t success_7 = false;
			::Parser::Token _6;
			::Parser::Token ;
			if (!(begin_10->name() == ::Parser::Tokens::AUTO_6))
			{
				reportError(pos, "AUTO_6");
				return {};
			}
			_6 = *begin_10;
			success_7 = true;
			begin_10 += 1;
			skip_spaces(begin_10);
			::Parser::Token _8;
			::Parser::Token ;
			if (!(begin_10->name() == ::Parser::Tokens::ID))
			{
				reportError(pos, "ID");
				return {};
			}
			_8 = *begin_10;
			success_9 = true;
			begin_10 += 1;
			::Parser::UNDEF ;
			if (success_7 && success_9)
			{
				success_5 = true;
				pos = begin_10;
			}
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::rule_name)};
		}
		template <class IT>
		::Parser::Rule_res array(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Token ;
			if (!(pos->name() == ::Parser::Tokens::AUTO_14))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::UNDEF _2;
			::Parser::bool_t success_3 = false;
			::Parser::UNDEF ;
			::Parser::bool_t success_5 = false;
			auto begin_10 = pos;
			::Parser::bool_t success_9 = false;
			::Parser::bool_t success_9 = false;
			::Parser::bool_t success_7 = false;
			::Parser::bool_t success_7 = false;
			::Parser::Rule_res _6;
			_6 = cll_expr(begin_10);
			if (!(_6.status))
			{
				reportError(pos, "expr");
				return {};
			}
			success_7 = true;
			begin_10 += _6.node.length();
			skip_spaces(begin_10);
			::Parser::Token _8;
			::Parser::Token ;
			if (!(begin_10->name() == ::Parser::Tokens::AUTO_2))
			{
				reportError(pos, "AUTO_2");
				return {};
			}
			_8 = *begin_10;
			success_9 = true;
			begin_10 += 1;
			::Parser::UNDEF ;
			do
			{
				::Parser::Rule_res _6;
				_6 = cll_expr(begin_10);
				if (!(_6.status))
				{
					reportError(pos, "expr");
					break;
				}
				success_7 = true;
				begin_10 += _6.node.length();
				skip_spaces(begin_10);
				::Parser::Token _8;
				::Parser::Token ;
				if (!(begin_10->name() == ::Parser::Tokens::AUTO_2))
				{
					reportError(pos, "AUTO_2");
					break;
				}
				_8 = *begin_10;
				success_9 = true;
				begin_10 += 1;
				::Parser::UNDEF ;
			}
			while(0);
			if (success_7 && success_9)
			{
				success_5 = true;
				pos = begin_10;
			}
			;
			if (!success_5)
			{
				return {};
			}
			else 
			{
				_2 = _4;
			}
			success_3 = true;
			skip_spaces(pos);
			::Parser::Token _11;
			::Parser::bool_t success_12 = false;
			::Parser::Token ;
			if (!(pos->name() == ::Parser::Tokens::AUTO_15))
			{
				reportError(pos, "AUTO_15");
				return {};
			}
			_11 = *pos;
			success_12 = true;
			pos += 1;
			::Parser::Types::array_data data = ;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::array, data)};
		}
		template <class IT>
		::Parser::Rule_res rule_member(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::bool_t success_1 = false;
			success_1 = false;
			auto begin_10 = pos;
			::Parser::bool_t success_5 = false;
			::Parser::bool_t success_3 = false;
			::Parser::UNDEF _2;
			::Parser::UNDEF ;
			return {};
			success_3 = true;
			skip_spaces(begin_10);
			::Parser::Rule _4;
			::Parser::UNDEF ;
			::Parser::Rule_res _6;
			::Parser::bool_t success_7 = false;
			_6 = rule_keyvalue(begin_10);
			if (!(_6.status))
			{
				::Parser::Rule_res _8;
				::Parser::bool_t success_9 = false;
				_8 = rule_value(begin_10);
				if (!(_8.status))
				{
					return {};
				}
				else 
				{
					success_9 = true;
					begin_10 += _8.node.length();
					_4 = _8.node;
				}
			}
			else 
			{
				success_7 = true;
				begin_10 += _6.node.length();
				_4 = _6.node;
			}
			success_5 = true;
			::Parser::UNDEF ;
			if (success_3 && success_5)
			{
				success_1 = true;
				pos = begin_10;
			}
			skip_spaces(pos);
			::Parser::any_t _11;
			::Parser::bool_t success_12 = false;
			::Parser::UNDEF ;
			::Parser::Rule_res _13;
			::Parser::bool_t success_14 = false;
			_13 = rule_name(pos);
			if (!(_13.status))
			{
				::Parser::Rule_res _15;
				::Parser::bool_t success_16 = false;
				_15 = rule_group(pos);
				if (!(_15.status))
				{
					::Parser::Token _17;
					::Parser::bool_t success_18 = false;
					::Parser::Token ;
					if (!(pos->name() == ::Parser::Tokens::rule_CSEQUENCE))
					{
						::Parser::Token _19;
						::Parser::bool_t success_20 = false;
						::Parser::Token ;
						if (!(pos->name() == ::Parser::Tokens::STRING))
						{
							::Parser::Token _21;
							::Parser::bool_t success_22 = false;
							::Parser::Token ;
							if (!(pos->name() == ::Parser::Tokens::rule_HEX))
							{
								::Parser::Token _23;
								::Parser::bool_t success_24 = false;
								::Parser::Token ;
								if (!(pos->name() == ::Parser::Tokens::rule_BIN))
								{
									::Parser::Token _25;
									::Parser::bool_t success_26 = false;
									::Parser::Token ;
									if (!(pos->name() == ::Parser::Tokens::rule_NOSPACE))
									{
										::Parser::Token _27;
										::Parser::bool_t success_28 = false;
										::Parser::Token ;
										if (!(pos->name() == ::Parser::Tokens::rule_ESCAPED))
										{
											::Parser::Token _29;
											::Parser::bool_t success_30 = false;
											::Parser::Token ;
											if (!(pos->name() == ::Parser::Tokens::rule_ANY))
											{
												::Parser::Token _31;
												::Parser::bool_t success_32 = false;
												::Parser::Token ;
												if (!(pos->name() == ::Parser::Tokens::rule_OP))
												{
													::Parser::Token _33;
													::Parser::bool_t success_34 = false;
													::Parser::Token ;
													if (!(pos->name() == ::Parser::Tokens::LINEAR_COMMENT))
													{
														::Parser::Rule_res _35;
														::Parser::bool_t success_36 = false;
														_35 = cll(pos);
														if (!(_35.status))
														{
															return {};
														}
														else 
														{
															success_36 = true;
															pos += _35.node.length();
															_11 = _35.node;
														}
													}
													else 
													{
														_33 = *pos;
														success_34 = true;
														pos += 1;
														_11 = _33;
													}
												}
												else 
												{
													_31 = *pos;
													success_32 = true;
													pos += 1;
													_11 = _31;
												}
											}
											else 
											{
												_29 = *pos;
												success_30 = true;
												pos += 1;
												_11 = _29;
											}
										}
										else 
										{
											_27 = *pos;
											success_28 = true;
											pos += 1;
											_11 = _27;
										}
									}
									else 
									{
										_25 = *pos;
										success_26 = true;
										pos += 1;
										_11 = _25;
									}
								}
								else 
								{
									_23 = *pos;
									success_24 = true;
									pos += 1;
									_11 = _23;
								}
							}
							else 
							{
								_21 = *pos;
								success_22 = true;
								pos += 1;
								_11 = _21;
							}
						}
						else 
						{
							_19 = *pos;
							success_20 = true;
							pos += 1;
							_11 = _19;
						}
					}
					else 
					{
						_17 = *pos;
						success_18 = true;
						pos += 1;
						_11 = _17;
					}
				}
				else 
				{
					success_16 = true;
					pos += _15.node.length();
					_11 = _15.node;
				}
			}
			else 
			{
				success_14 = true;
				pos += _13.node.length();
				_11 = _13.node;
			}
			success_12 = true;
			skip_spaces(pos);
			::Parser::Token _37;
			::Parser::bool_t success_38 = false;
			::Parser::Token ;
			if (!(pos->name() == ::Parser::Tokens::rule_QUANTIFIER))
			{
				reportError(pos, "QUANTIFIER");
				return {};
			}
			_37 = *pos;
			success_38 = true;
			pos += 1;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::rule_member)};
		}
		template <class IT>
		::Parser::Rule_res cll_expr_value(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Rule _0;
			::Parser::bool_t success_1 = false;
			::Parser::UNDEF ;
			::Parser::Rule_res _2;
			::Parser::bool_t success_3 = false;
			_2 = cll_expr_group(pos);
			if (!(_2.status))
			{
				::Parser::Rule_res _4;
				::Parser::bool_t success_5 = false;
				_4 = cll__variable(pos);
				if (!(_4.status))
				{
					::Parser::Rule_res _6;
					::Parser::bool_t success_7 = false;
					_6 = rvalue(pos);
					if (!(_6.status))
					{
						::Parser::Rule_res _8;
						::Parser::bool_t success_9 = false;
						_8 = cll_function_call(pos);
						if (!(_8.status))
						{
							::Parser::Rule_res _10;
							::Parser::bool_t success_11 = false;
							_10 = cll_method_call(pos);
							if (!(_10.status))
							{
								return {};
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
			::Parser::Types::cll_expr_value_data data = ;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_expr_value, data)};
		}
		template <class IT>
		::Parser::Rule_res object(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Token ;
			if (!(pos->name() == ::Parser::Tokens::AUTO_1))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::bool_t success_3 = false;
			auto begin_31 = pos;
			::Parser::bool_t success_30 = false;
			::Parser::bool_t success_15 = false;
			::Parser::bool_t success_13 = false;
			::Parser::bool_t success_11 = false;
			::Parser::bool_t success_5 = false;
			::Parser::Token _4;
			::Parser::UNDEF ;
			::Parser::Token _6;
			::Parser::bool_t success_7 = false;
			::Parser::Token ;
			if (!(begin_31->name() == ::Parser::Tokens::ID))
			{
				::Parser::Token _8;
				::Parser::bool_t success_9 = false;
				::Parser::Token ;
				if (!(begin_31->name() == ::Parser::Tokens::NUMBER))
				{
					return {};
				}
				else 
				{
					_8 = *begin_31;
					success_9 = true;
					begin_31 += 1;
					_4 = _8;
				}
			}
			else 
			{
				_6 = *begin_31;
				success_7 = true;
				begin_31 += 1;
				_4 = _6;
			}
			success_5 = true;
			skip_spaces(begin_31);
			::Parser::Token _10;
			::Parser::Token ;
			if (!(begin_31->name() == ::Parser::Tokens::AUTO_16))
			{
				reportError(pos, "AUTO_16");
				return {};
			}
			_10 = *begin_31;
			success_11 = true;
			begin_31 += 1;
			skip_spaces(begin_31);
			::Parser::Rule_res _12;
			_12 = cll_expr(begin_31);
			if (!(_12.status))
			{
				reportError(pos, "expr");
				return {};
			}
			success_13 = true;
			begin_31 += _12.node.length();
			skip_spaces(begin_31);
			auto begin_28 = begin_31;
			::Parser::bool_t success_27 = false;
			::Parser::bool_t success_25 = false;
			::Parser::bool_t success_19 = false;
			::Parser::bool_t success_17 = false;
			::Parser::Token _16;
			::Parser::Token ;
			if (!(begin_28->name() == ::Parser::Tokens::AUTO_2))
			{
				reportError(pos, "AUTO_2");
				return {};
			}
			_16 = *begin_28;
			success_17 = true;
			begin_28 += 1;
			skip_spaces(begin_28);
			::Parser::Token _18;
			::Parser::UNDEF ;
			::Parser::Token _20;
			::Parser::bool_t success_21 = false;
			::Parser::Token ;
			if (!(begin_28->name() == ::Parser::Tokens::ID))
			{
				::Parser::Token _22;
				::Parser::bool_t success_23 = false;
				::Parser::Token ;
				if (!(begin_28->name() == ::Parser::Tokens::NUMBER))
				{
					return {};
				}
				else 
				{
					_22 = *begin_28;
					success_23 = true;
					begin_28 += 1;
					_18 = _22;
				}
			}
			else 
			{
				_20 = *begin_28;
				success_21 = true;
				begin_28 += 1;
				_18 = _20;
			}
			success_19 = true;
			skip_spaces(begin_28);
			::Parser::Token _24;
			::Parser::Token ;
			if (!(begin_28->name() == ::Parser::Tokens::AUTO_16))
			{
				reportError(pos, "AUTO_16");
				return {};
			}
			_24 = *begin_28;
			success_25 = true;
			begin_28 += 1;
			skip_spaces(begin_28);
			::Parser::Rule_res _26;
			_26 = cll_expr(begin_28);
			if (!(_26.status))
			{
				reportError(pos, "expr");
				return {};
			}
			success_27 = true;
			begin_28 += _26.node.length();
			::Parser::UNDEF ;
			if (success_17 && success_19 && success_25 && success_27)
			{
				success_15 = true;
				begin_31 = begin_28;
			}
			skip_spaces(begin_31);
			::Parser::Token _29;
			::Parser::Token ;
			if (!(begin_31->name() == ::Parser::Tokens::AUTO_19))
			{
				reportError(pos, "AUTO_19");
				return {};
			}
			_29 = *begin_31;
			success_30 = true;
			begin_31 += 1;
			::Parser::UNDEF ;
			if (success_5 && success_11 && success_13 && success_15 && success_30)
			{
				success_3 = true;
				pos = begin_31;
			}
			skip_spaces(pos);
			::Parser::Token _32;
			::Parser::bool_t success_33 = false;
			::Parser::Token ;
			if (!(pos->name() == ::Parser::Tokens::AUTO_3))
			{
				reportError(pos, "AUTO_3");
				return {};
			}
			_32 = *pos;
			success_33 = true;
			pos += 1;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::object)};
		}
		template <class IT>
		::Parser::Rule_res rvalue(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::any_t _0;
			::Parser::bool_t success_1 = false;
			::Parser::UNDEF ;
			::Parser::Token _2;
			::Parser::bool_t success_3 = false;
			::Parser::Token ;
			if (!(pos->name() == ::Parser::Tokens::BOOLEAN))
			{
				::Parser::Token _4;
				::Parser::bool_t success_5 = false;
				::Parser::Token ;
				if (!(pos->name() == ::Parser::Tokens::STRING))
				{
					::Parser::Token _6;
					::Parser::bool_t success_7 = false;
					::Parser::Token ;
					if (!(pos->name() == ::Parser::Tokens::AT))
					{
						::Parser::Rule_res _8;
						::Parser::bool_t success_9 = false;
						_8 = array(pos);
						if (!(_8.status))
						{
							::Parser::Rule_res _10;
							::Parser::bool_t success_11 = false;
							_10 = object(pos);
							if (!(_10.status))
							{
								::Parser::Token _12;
								::Parser::bool_t success_13 = false;
								::Parser::Token ;
								if (!(pos->name() == ::Parser::Tokens::NUMBER))
								{
									::Parser::Token _14;
									::Parser::bool_t success_15 = false;
									::Parser::Token ;
									if (!(pos->name() == ::Parser::Tokens::ID))
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
			::Parser::Types::rvalue_data data = ;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::rvalue, data)};
		}
		template <class IT>
		::Parser::Rule_res cll_expr_term(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Rule_res _0;
			::Parser::bool_t success_1 = false;
			_0 = cll_expr_value(pos);
			if (!(_0.status))
			{
				return {};
			}
			success_1 = true;
			pos += _0.node.length();
			skip_spaces(pos);
			::Parser::bool_t success_3 = false;
			auto begin_14 = pos;
			::Parser::bool_t success_13 = false;
			::Parser::bool_t success_5 = false;
			::Parser::Token _4;
			::Parser::UNDEF ;
			::Parser::Token _6;
			::Parser::bool_t success_7 = false;
			::Parser::Token ;
			if (!(begin_14->name() == ::Parser::Tokens::MULTIPLE))
			{
				::Parser::Token _8;
				::Parser::bool_t success_9 = false;
				::Parser::Token ;
				if (!(begin_14->name() == ::Parser::Tokens::DIVIDE))
				{
					::Parser::Token _10;
					::Parser::bool_t success_11 = false;
					::Parser::Token ;
					if (!(begin_14->name() == ::Parser::Tokens::MODULO))
					{
						return {};
					}
					else 
					{
						_10 = *begin_14;
						success_11 = true;
						begin_14 += 1;
						_4 = _10;
					}
				}
				else 
				{
					_8 = *begin_14;
					success_9 = true;
					begin_14 += 1;
					_4 = _8;
				}
			}
			else 
			{
				_6 = *begin_14;
				success_7 = true;
				begin_14 += 1;
				_4 = _6;
			}
			success_5 = true;
			skip_spaces(begin_14);
			::Parser::Rule_res _12;
			_12 = cll_expr_value(begin_14);
			if (!(_12.status))
			{
				reportError(pos, "value");
				return {};
			}
			success_13 = true;
			begin_14 += _12.node.length();
			::Parser::UNDEF ;
			if (success_5 && success_13)
			{
				success_3 = true;
				pos = begin_14;
			}
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_expr_term)};
		}
		template <class IT>
		::Parser::Rule_res rule_keyvalue(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Token ;
			if (!(pos->name() == ::Parser::Tokens::AUTO_0))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::bool_t success_3 = false;
			auto begin_6 = pos;
			::Parser::bool_t success_5 = false;
			::Parser::Token _4;
			::Parser::Token ;
			if (!(begin_6->name() == ::Parser::Tokens::ID))
			{
				reportError(pos, "ID");
				return {};
			}
			_4 = *begin_6;
			success_5 = true;
			begin_6 += 1;
			::Parser::UNDEF ;
			if (success_5)
			{
				success_3 = true;
				pos = begin_6;
			}
			::Parser::Types::rule_keyvalue_data data = ;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::rule_keyvalue, data)};
		}
		template <class IT>
		::Parser::Rule_res rule_group(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Token ;
			if (!(pos->name() == ::Parser::Tokens::AUTO_7))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::Rule_res _2;
			::Parser::bool_t success_3 = false;
			_2 = rule_member(pos);
			if (!(_2.status))
			{
				reportError(pos, "member");
				return {};
			}
			success_3 = true;
			pos += _2.node.length();
			skip_spaces(pos);
			::Parser::Token _4;
			::Parser::bool_t success_5 = false;
			::Parser::Token ;
			if (!(pos->name() == ::Parser::Tokens::AUTO_8))
			{
				reportError(pos, "AUTO_8");
				return {};
			}
			_4 = *pos;
			success_5 = true;
			pos += 1;
			::Parser::Types::rule_group_data data = ;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::rule_group, data)};
		}
		template <class IT>
		::Parser::Rule_res cll_loop_for(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Token ;
			if (!(pos->name() == ::Parser::Tokens::AUTO_20))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::Token _2;
			::Parser::bool_t success_3 = false;
			::Parser::Token ;
			if (!(pos->name() == ::Parser::Tokens::AUTO_7))
			{
				reportError(pos, "AUTO_7");
				return {};
			}
			_2 = *pos;
			success_3 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::Rule _4;
			::Parser::bool_t success_5 = false;
			::Parser::UNDEF ;
			::Parser::Rule_res _6;
			::Parser::bool_t success_7 = false;
			_6 = cll_expr(pos);
			if (!(_6.status))
			{
				::Parser::Rule_res _8;
				::Parser::bool_t success_9 = false;
				_8 = cll__var(pos);
				if (!(_8.status))
				{
					return {};
				}
				else 
				{
					success_9 = true;
					pos += _8.node.length();
					_4 = _8.node;
				}
			}
			else 
			{
				success_7 = true;
				pos += _6.node.length();
				_4 = _6.node;
			}
			success_5 = true;
			skip_spaces(pos);
			::Parser::Token _10;
			::Parser::bool_t success_11 = false;
			::Parser::Token ;
			if (!(pos->name() == ::Parser::Tokens::AUTO_19))
			{
				reportError(pos, "AUTO_19");
				return {};
			}
			_10 = *pos;
			success_11 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::Rule_res _12;
			::Parser::bool_t success_13 = false;
			_12 = cll_expr(pos);
			if (!(_12.status))
			{
				reportError(pos, "expr");
				return {};
			}
			success_13 = true;
			pos += _12.node.length();
			skip_spaces(pos);
			::Parser::Token _14;
			::Parser::bool_t success_15 = false;
			::Parser::Token ;
			if (!(pos->name() == ::Parser::Tokens::AUTO_19))
			{
				reportError(pos, "AUTO_19");
				return {};
			}
			_14 = *pos;
			success_15 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::Rule_res _16;
			::Parser::bool_t success_17 = false;
			_16 = cll_expr(pos);
			if (!(_16.status))
			{
				reportError(pos, "expr");
				return {};
			}
			success_17 = true;
			pos += _16.node.length();
			skip_spaces(pos);
			::Parser::Token _18;
			::Parser::bool_t success_19 = false;
			::Parser::Token ;
			if (!(pos->name() == ::Parser::Tokens::AUTO_8))
			{
				reportError(pos, "AUTO_8");
				return {};
			}
			_18 = *pos;
			success_19 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::Rule_res _20;
			::Parser::bool_t success_21 = false;
			_20 = cll_stmt(pos);
			if (!(_20.status))
			{
				reportError(pos, "stmt");
				return {};
			}
			success_21 = true;
			pos += _20.node.length();
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::cll_loop_for)};
		}
		template <class IT>
		::Parser::Rule_res rule_nested_rule(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Token ;
			if (!(pos->name() == ::Parser::Tokens::AUTO_21))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			::Parser::Rule_res _2;
			::Parser::bool_t success_3 = false;
			_2 = Rule(pos);
			if (!(_2.status))
			{
				reportError(pos, "Rule");
				return {};
			}
			success_3 = true;
			pos += _2.node.length();
			::Parser::Types::rule_nested_rule_data data = ;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::rule_nested_rule, data)};
		}
		template <class IT>
		::Parser::Rule_res rule_data_block_regular_datablock(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Token ;
			if (!(pos->name() == ::Parser::Tokens::AUTO_1))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::Rule _2;
			::Parser::bool_t success_3 = false;
			::Parser::UNDEF ;
			::Parser::Rule_res _4;
			::Parser::bool_t success_5 = false;
			_4 = cll_expr(pos);
			if (!(_4.status))
			{
				::Parser::Rule_res _6;
				::Parser::bool_t success_7 = false;
				_6 = rule_data_block_regular_datablock_key(pos);
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
			::Parser::Token _8;
			::Parser::bool_t success_9 = false;
			::Parser::Token ;
			if (!(pos->name() == ::Parser::Tokens::AUTO_3))
			{
				reportError(pos, "AUTO_3");
				return {};
			}
			_8 = *pos;
			success_9 = true;
			pos += 1;
			::Parser::Types::rule_data_block_regular_datablock_data data = ;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::rule_data_block_regular_datablock, data)};
		}
	};

} // Parser


#endif // PARSER
