#pragma once
#ifndef EXPR_PARSER
#define EXPR_PARSER

#include <string>
#include <list>
#include <unordered_map>
#include <iscstdlibc++.h>
#include <fstream>
#include <iterator>

#include <optional>

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
	struct Action {
        enum Action_type {
            SHIFT, REDUCE, ACCEPT, ERROR
        };
        Action_type type;
        size_t state;
    };
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
		NONE, main, expr, term, power, factor, arg_list, __q2, __grp1, __start
	};
	using Rule = ISPA_STD::node<Rules>;
	using Rule_res = ISPA_STD::match_result<Rules>;
	using Token = ISPA_STD::node<Tokens>;
	using Token_res = ISPA_STD::match_result<Tokens>;
	using TokenFlow = ISPA_STD::TokenFlow<Tokens>;
	using Tree = ISPA_STD::Tree<Rules>;
	std::string TokensToString(Tokens token);
	std::string RulesToString(Rules rule);
		using ActionTable = std::array<std::array<std::optional<::Expr_parser::Action>, 26>, 53>;
		using GotoTable = std::array<std::array<std::optional<size_t>, 51>, 53>;
		using RulesTable = std::array<std::pair<Rules, size_t>, 51>;
	namespace Types {
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
	class Parser : public ISPA_STD::LRParser_base<Tokens, Rules, Action, ActionTable, GotoTable, RulesTable> {
		private:
			static ActionTable action_table;
			static GotoTable goto_table;
			static RulesTable rules_table;
	};

} // Expr_parser


#endif // EXPR_PARSER
