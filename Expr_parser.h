#pragma once
#ifndef EXPR_PARSER
#define EXPR_PARSER

#include <string>
#include <list>
#include <unordered_map>
#include <iscstdlibc++.h>
#include <fstream>
#include <iterator>

#ifndef EXPR_PARSER_OBJ_TYPE
#define EXPR_PARSER_OBJ_TYPE std::unordered_map
#endif
#ifndef EXPR_PARSER_ARR_TYPE
#define EXPR_PARSER_ARR_TYPE std::list
#endif
#ifndef EXPR_PARSER_ANY_TYPE
#define EXPR_PARSER_ANY_TYPE std::any
#endif
#ifndef EXPR_PARSER_STR_TYPE
#define EXPR_PARSER_STR_TYPE std::string
#endif
#ifndef EXPR_PARSER_NUM_TYPE
#define EXPR_PARSER_NUM_TYPE double
#endif
#ifndef EXPR_PARSER_BOOL_TYPE
#define EXPR_PARSER_BOOL_TYPE bool
#endif
namespace Expr_parser {
	using str_t = EXPR_PARSER_STR_TYPE;
	using num_t = EXPR_PARSER_NUM_TYPE;
	using bool_t = EXPR_PARSER_BOOL_TYPE;
	using any_t = EXPR_PARSER_ANY_TYPE;
	template<typename T>
	using arr_t = EXPR_PARSER_ARR_TYPE<T>;
	template<typename Key, typename Value>
	using obj_t = EXPR_PARSER_OBJ_TYPE<Key, Value>;
	enum class Tokens {
		NONE, ID, NUMBER, AUTO_0, AUTO_1, AUTO_2, AUTO_3, AUTO_4, AUTO_5, AUTO_6, AUTO_7, AUTO_10, AUTO_11, AUTO_12, AUTO_13, AUTO_14, AUTO_15, AUTO_16, AUTO_17, AUTO_18, AUTO_21, AUTO_22, AUTO_23, AUTO_24, AUTO_25, AUTO_26, __WHITESPACE
	};
	enum class Rules {
		NONE, main, expr, term, power, factor, arg_list, expr, expr, expr, expr, expr, expr, expr, expr, expr, expr, expr, expr, expr, expr, expr, expr, expr, expr, expr, expr, expr, expr, term, term, term, term, term, power, __q2, __q2, factor, factor, factor, factor, factor, factor, factor, factor, factor, factor, factor, factor, __grp1, __grp1, __start
	};
	using Rule = ISPA_STD::node<Rules>;
	using Rule_res = ISPA_STD::match_result<Rules>;
	using Token = ISPA_STD::node<Tokens>;
	using Token_res = ISPA_STD::match_result<Tokens>;
	using TokenFlow = ISPA_STD::TokenFlow<Tokens>;
	using Tree = ISPA_STD::Tree<Rules>;
	std::string TokensToString(Tokens token);
	std::string RulesToString(Rules rule);
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
		private:
			Token_res ID(const char*);
			Token_res NUMBER(const char*);
			Token_res AUTO_0(const char*);
			Token_res AUTO_1(const char*);
			Token_res AUTO_2(const char*);
			Token_res AUTO_3(const char*);
			Token_res AUTO_4(const char*);
			Token_res AUTO_5(const char*);
			Token_res AUTO_6(const char*);
			Token_res AUTO_7(const char*);
			Token_res AUTO_10(const char*);
			Token_res AUTO_11(const char*);
			Token_res AUTO_12(const char*);
			Token_res AUTO_13(const char*);
			Token_res AUTO_14(const char*);
			Token_res AUTO_15(const char*);
			Token_res AUTO_16(const char*);
			Token_res AUTO_17(const char*);
			Token_res AUTO_18(const char*);
			Token_res AUTO_21(const char*);
			Token_res AUTO_22(const char*);
			Token_res AUTO_23(const char*);
			Token_res AUTO_24(const char*);
			Token_res AUTO_25(const char*);
			Token_res AUTO_26(const char*);
			Token_res __WHITESPACE(const char*);
	};
	class Parser : public ISPA_STD::Parser_base<Tokens, Rules> {
		Rule_res getRule(Lexer::lazy_iterator&);
		Rule_res getRule(Lexer::iterator&);
		void parseFromTokens();
		void lazyParse();
	};

} // Expr_parser


#endif // EXPR_PARSER
