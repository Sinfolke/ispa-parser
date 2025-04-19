#include "Parser.h"
#include "Parser.h"
std::string Parser::TokensToString(Tokens token) {
	switch (token) {
		case Tokens::NONE: return "NONE";
		case Tokens::NUMBER: return "NUMBER";
		case Tokens::AUTO_0: return "AUTO_0";
		case Tokens::AUTO_1: return "AUTO_1";
		case Tokens::__WHITESPACE: return "__WHITESPACE";
	}
	return "NONE";
}
std::string Parser::RulesToString(Rules rule) {
	switch (rule) {
		case Rules::NONE: return "NONE";
		case Rules::main: return "main";
		case Rules::term: return "term";
		case Rules::__q0_tail: return "__q0_tail";
		case Rules::__q0: return "__q0";
		case Rules::__start: return "__start";
	}
	return "NONE";
}
void Parser::Lexer::printTokens(std::ostream& os) {
    for (const auto& token : tokens)
        printToken(os, token);
}
void Parser::Lexer::printToken(std::ostream& os, const Token& token) {
    os << TokensToString(token.name()) << ": ";

    if (token.data().type() == typeid(str_t)) {
        os << '"' << std::any_cast<str_t>(token.data()) << '"';
    } else if (token.data().type() == typeid(num_t)) {
        os << std::any_cast<num_t>(token.data());
    } else if (token.data().type() == typeid(bool_t)) {
        os << std::boolalpha << std::any_cast<bool_t>(token.data());
    } else if (token.data().type() == typeid(Token)) {
        os << "{ ";
        printToken(os, std::any_cast<Token>(token.data())); // Recursive call
        os << " }";
    } else if (token.data().type() == typeid(arr_t<Token>)) { // Handle array of tokens
        os << "[ ";
        auto arr = std::any_cast<arr_t<Token>>(token.data());
        for (auto it = arr.begin(); it != arr.end(); ++it) {
            printToken(os, *it);
            if (std::next(it) != arr.end()) os << ", ";
        }
        os << " ]";
    } else if (token.data().type() == typeid(arr_t<str_t>)) {
        os << "[ ";
        auto arr = std::any_cast<arr_t<str_t>>(token.data());
        for (auto it = arr.begin(); it != arr.end(); ++it) {
            os << '"' << *it << '"';
            if (std::next(it) != arr.end()) os << ", ";
        }
        os << " ]";
    } else if (token.data().type() == typeid(arr_t<num_t>)) {
        os << "[ ";
        auto arr = std::any_cast<arr_t<num_t>>(token.data());
        for (auto it = arr.begin(); it != arr.end(); ++it) {
            os << *it;
            if (std::next(it) != arr.end()) os << ", ";
        }
        os << " ]";
    } else if (token.data().type() == typeid(arr_t<bool_t>)) {
        os << "[ ";
        auto arr = std::any_cast<arr_t<bool_t>>(token.data());
        for (auto it = arr.begin(); it != arr.end(); ++it) {
            os << std::boolalpha << *it;
            if (std::next(it) != arr.end()) os << ", ";
        }
        os << " ]";
    }
    os << " # " << token.startpos();
    os << '\n';
}
void ::Parser::Parser::parseFromTokens() {
        auto pos = Lexer::iterator(lexer);
        parseFromPos(pos, action_table, goto_table, rules_table);
    }
void ::Parser::Parser::lazyParse() {
        if (lexer == nullptr) {
            Lexer lexer(text);
            auto pos = Lexer::lazy_iterator(lexer, text);
            parseFromPos(pos, action_table, goto_table, rules_table);
        } else {
            auto pos = Lexer::lazy_iterator(lexer, text);
            parseFromPos(pos, action_table, goto_table, rules_table);
        }
    }

Parser::Token Parser::Lexer::makeToken(const char*& pos) {
	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	::Parser::Token_res _2;
	::Parser::bool_t success_3 = false;
	::Parser::Token_res _4;
	::Parser::bool_t success_5 = false;
	::Parser::Token_res _6;
	::Parser::bool_t success_7 = false;
	::Parser::Token_res _8;
	::Parser::bool_t success_9 = false;
	_2 = AUTO_0(pos);
	if (!(_2.status))
	{
		_4 = AUTO_1(pos);
		if (!(_4.status))
		{
			_6 = __WHITESPACE(pos);
			if (!(_6.status))
			{
				_8 = NUMBER(pos);
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
	return _0;
}
Parser::Token_res Parser::Lexer::NUMBER(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	::Parser::bool_t success_2 = false;
	while ((*(pos + 0)>='0' && *(pos + 0)<='9'))
	{
		_0 += ::Parser::str_t(pos, 1);
		success_1 = true;
		pos += 1;
		success_2 = true;
	}
	if (!success_2)
	{
		return {};
	}
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::NUMBER)};
}
Parser::Token_res Parser::Lexer::AUTO_0(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == '+'))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 1);
	success_1 = true;
	pos += 1;
	::Parser::Types::AUTO_0_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_0, data)};
}
Parser::Token_res Parser::Lexer::AUTO_1(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == '*'))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 1);
	success_1 = true;
	pos += 1;
	::Parser::Types::AUTO_1_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_1, data)};
}
Parser::Token_res Parser::Lexer::__WHITESPACE(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	::Parser::bool_t success_2 = false;
	while (*(pos + 0) == ' ' || *(pos + 0) == '\t' || *(pos + 0) == '\n' || *(pos + 0) == '\r' || *(pos + 0) == '\v' || *(pos + 0) == '\f')
	{
		_0 += ::Parser::str_t(pos, 1);
		success_1 = true;
		pos += 1;
		success_2 = true;
	}
	if (!success_2)
	{
		return {};
	}
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::__WHITESPACE)};
}
Parser::ActionTable Parser::Parser::action_table = {{
	{{std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 1}), std::nullopt, std::nullopt, std::nullopt}},
	{{std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 0}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 0}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 0}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 0}), std::nullopt}},
	{{std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 1}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 1}), std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 6}), std::nullopt}},
	{{std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 8}), std::nullopt, std::nullopt}},
	{{std::make_optional(::Parser::Action{::Parser::Action::Action_type::ACCEPT, 0}), std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 1}), std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 6}), std::nullopt}},
	{{std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 1}), std::nullopt, std::nullopt, std::nullopt}},
	{{std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 2}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 2}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 2}), std::nullopt, std::nullopt}},
	{{std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 1}), std::nullopt, std::nullopt, std::nullopt}},
	{{std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 3}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 3}), std::nullopt, std::nullopt, std::nullopt}},
	{{std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 4}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 4}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 4}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 4}), std::nullopt}},
	{{std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 5}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 5}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 5}), std::nullopt, std::nullopt}}
}};
Parser::GotoTable Parser::Parser::goto_table = {{
	{{std::nullopt, std::make_optional(4), std::make_optional(2), std::nullopt, std::nullopt, std::make_optional(3), std::nullopt, std::nullopt}},
	{{std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::nullopt, std::make_optional(5), std::make_optional(7), std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::nullopt, std::make_optional(2), std::nullopt, std::nullopt, std::make_optional(9), std::nullopt, std::nullopt}},
	{{std::nullopt, std::nullopt, std::make_optional(10), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::nullopt, std::make_optional(2), std::nullopt, std::nullopt, std::make_optional(11), std::nullopt, std::nullopt}}
}};
Parser::RulesTable Parser::Parser::rules_table = {
	{
	{::Parser::Rules::NONE, 0},
	{::Parser::Rules::term, 1},
	{::Parser::Rules::__q0_tail, 0},
	{::Parser::Rules::__q0, 2},
	{::Parser::Rules::__q0_tail, 2},
	{::Parser::Rules::term, 3},
	{::Parser::Rules::main, 3}
	}
};
