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
            SHIFT, REDUCE, ACCEPT, ERROR
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
		NONE, ID, NUMBER, AUTO_0, AUTO_1, AUTO_2, AUTO_3, AUTO_4, AUTO_5, AUTO_6, AUTO_7, AUTO_8, AUTO_9, AUTO_10, AUTO_11, AUTO_12, AUTO_13, AUTO_14, AUTO_15, AUTO_16, AUTO_17, AUTO_18, AUTO_19, AUTO_20, AUTO_21, AUTO_22, AUTO_23, __WHITESPACE
	};
	enum class Rules {
		NONE, main, expr, term, factor, arg_list, __q2, __grp1, __start
	};
	using Rule = ISPA_STD::node<Rules>;
	using Rule_res = ISPA_STD::match_result<Rules>;
	using Token = ISPA_STD::node<Tokens>;
	using Token_res = ISPA_STD::match_result<Tokens>;
	using TokenFlow = ISPA_STD::TokenFlow<Tokens>;
	using Tree = ISPA_STD::Tree<Rules>;
	std::string TokensToString(Tokens token);
	std::string RulesToString(Rules rule);
		using ActionTable = std::array<std::array<std::optional<::Parser::Action>, 28>, 57>;
		using GotoTable = std::array<std::array<std::optional<size_t>, 31>, 57>;
		using RulesTable = std::array<std::pair<Rules, size_t>, 29>;
	namespace Types {
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
        Lexer() {}		private:
			Token_res NONE(const char*);
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
			Token_res __WHITESPACE(const char*);
	};
	class Parser : public ISPA_STD::LRParser_base<Tokens, Rules, Action, ActionTable, GotoTable, RulesTable> {
		private:
			static ActionTable action_table;
			static GotoTable goto_table;
			static RulesTable rules_table;
			std::string TokensToString(Tokens token);
			std::string RulesToString(Rules rule);
		void parseFromTokens();
		void lazyParse();
	};

} // Parser


#endif // PARSER
