#include "Parser.h"
#include "Parser.h"
std::string Parser::TokensToString(Tokens token) {
	switch (token) {
		case Tokens::NONE: return "NONE";
		case Tokens::ID: return "ID";
		case Tokens::NUMBER: return "NUMBER";
		case Tokens::AUTO_0: return "AUTO_0";
		case Tokens::AUTO_1: return "AUTO_1";
		case Tokens::AUTO_2: return "AUTO_2";
		case Tokens::AUTO_3: return "AUTO_3";
		case Tokens::AUTO_4: return "AUTO_4";
		case Tokens::AUTO_5: return "AUTO_5";
		case Tokens::AUTO_6: return "AUTO_6";
		case Tokens::AUTO_7: return "AUTO_7";
		case Tokens::AUTO_8: return "AUTO_8";
		case Tokens::AUTO_9: return "AUTO_9";
		case Tokens::AUTO_10: return "AUTO_10";
		case Tokens::AUTO_11: return "AUTO_11";
		case Tokens::AUTO_12: return "AUTO_12";
		case Tokens::AUTO_13: return "AUTO_13";
		case Tokens::AUTO_14: return "AUTO_14";
		case Tokens::AUTO_15: return "AUTO_15";
		case Tokens::AUTO_16: return "AUTO_16";
		case Tokens::AUTO_17: return "AUTO_17";
		case Tokens::AUTO_18: return "AUTO_18";
		case Tokens::AUTO_19: return "AUTO_19";
		case Tokens::AUTO_20: return "AUTO_20";
		case Tokens::AUTO_21: return "AUTO_21";
		case Tokens::AUTO_22: return "AUTO_22";
		case Tokens::AUTO_23: return "AUTO_23";
		case Tokens::__WHITESPACE: return "__WHITESPACE";
	}
	return "NONE";
}
std::string Parser::RulesToString(Rules rule) {
	switch (rule) {
		case Rules::NONE: return "NONE";
		case Rules::main: return "main";
		case Rules::expr: return "expr";
		case Rules::term: return "term";
		case Rules::factor: return "factor";
		case Rules::arg_list: return "arg_list";
		case Rules::__q2: return "__q2";
		case Rules::__grp1: return "__grp1";
		case Rules::__start: return "__start";
	}
	return "NONE";
}
std::string Parser::Parser::TokensToString(Tokens token) {
		return ::Parser::TokensToString(token);
	}
std::string Parser::Parser::RulesToString(Rules rule) {
		return ::Parser::RulesToString(rule);
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
            parseFromPos(pos, action_table, goto_table, rules_table, dfa_table);
        }
void ::Parser::Parser::lazyParse() {
            if (lexer == nullptr) {
                Lexer lexer(text);
                auto pos = Lexer::lazy_iterator(lexer, text);
                parseFromPos(pos, action_table, goto_table, rules_table, dfa_table);
            } else {
                auto pos = Lexer::lazy_iterator(lexer, text);
                parseFromPos(pos, action_table, goto_table, rules_table, dfa_table);
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
	::Parser::Token_res _10;
	::Parser::bool_t success_11 = false;
	::Parser::Token_res _12;
	::Parser::bool_t success_13 = false;
	::Parser::Token_res _14;
	::Parser::bool_t success_15 = false;
	::Parser::Token_res _16;
	::Parser::bool_t success_17 = false;
	::Parser::Token_res _18;
	::Parser::bool_t success_19 = false;
	::Parser::Token_res _20;
	::Parser::bool_t success_21 = false;
	::Parser::Token_res _22;
	::Parser::bool_t success_23 = false;
	::Parser::Token_res _24;
	::Parser::bool_t success_25 = false;
	::Parser::Token_res _26;
	::Parser::bool_t success_27 = false;
	::Parser::Token_res _28;
	::Parser::bool_t success_29 = false;
	::Parser::Token_res _30;
	::Parser::bool_t success_31 = false;
	::Parser::Token_res _32;
	::Parser::bool_t success_33 = false;
	::Parser::Token_res _34;
	::Parser::bool_t success_35 = false;
	::Parser::Token_res _36;
	::Parser::bool_t success_37 = false;
	::Parser::Token_res _38;
	::Parser::bool_t success_39 = false;
	::Parser::Token_res _40;
	::Parser::bool_t success_41 = false;
	::Parser::Token_res _42;
	::Parser::bool_t success_43 = false;
	::Parser::Token_res _44;
	::Parser::bool_t success_45 = false;
	::Parser::Token_res _46;
	::Parser::bool_t success_47 = false;
	::Parser::Token_res _48;
	::Parser::bool_t success_49 = false;
	::Parser::Token_res _50;
	::Parser::bool_t success_51 = false;
	::Parser::Token_res _52;
	::Parser::bool_t success_53 = false;
	::Parser::Token_res _54;
	::Parser::bool_t success_55 = false;
	_2 = ID(pos);
	if (!(_2.status))
	{
		_4 = AUTO_2(pos);
		if (!(_4.status))
		{
			_6 = AUTO_3(pos);
			if (!(_6.status))
			{
				_8 = AUTO_4(pos);
				if (!(_8.status))
				{
					_10 = AUTO_5(pos);
					if (!(_10.status))
					{
						_12 = AUTO_6(pos);
						if (!(_12.status))
						{
							_14 = AUTO_7(pos);
							if (!(_14.status))
							{
								_16 = AUTO_23(pos);
								if (!(_16.status))
								{
									_18 = AUTO_22(pos);
									if (!(_18.status))
									{
										_20 = AUTO_21(pos);
										if (!(_20.status))
										{
											_22 = AUTO_20(pos);
											if (!(_22.status))
											{
												_24 = AUTO_19(pos);
												if (!(_24.status))
												{
													_26 = AUTO_18(pos);
													if (!(_26.status))
													{
														_28 = AUTO_17(pos);
														if (!(_28.status))
														{
															_30 = AUTO_16(pos);
															if (!(_30.status))
															{
																_32 = AUTO_15(pos);
																if (!(_32.status))
																{
																	_34 = AUTO_14(pos);
																	if (!(_34.status))
																	{
																		_36 = AUTO_13(pos);
																		if (!(_36.status))
																		{
																			_38 = AUTO_12(pos);
																			if (!(_38.status))
																			{
																				_40 = AUTO_11(pos);
																				if (!(_40.status))
																				{
																					_42 = AUTO_10(pos);
																					if (!(_42.status))
																					{
																						_44 = AUTO_9(pos);
																						if (!(_44.status))
																						{
																							_46 = AUTO_8(pos);
																							if (!(_46.status))
																							{
																								_48 = AUTO_1(pos);
																								if (!(_48.status))
																								{
																									_50 = AUTO_0(pos);
																									if (!(_50.status))
																									{
																										_52 = __WHITESPACE(pos);
																										if (!(_52.status))
																										{
																											_54 = NUMBER(pos);
																											if (!(_54.status))
																											{
																												return {};
																											}
																											else 
																											{
																												success_55 = true;
																												pos += _54.node.length();
																												_0 = _54.node;
																											}
																										}
																										else 
																										{
																											success_53 = true;
																											pos += _52.node.length();
																											_0 = _52.node;
																										}
																									}
																									else 
																									{
																										success_51 = true;
																										pos += _50.node.length();
																										_0 = _50.node;
																									}
																								}
																								else 
																								{
																									success_49 = true;
																									pos += _48.node.length();
																									_0 = _48.node;
																								}
																							}
																							else 
																							{
																								success_47 = true;
																								pos += _46.node.length();
																								_0 = _46.node;
																							}
																						}
																						else 
																						{
																							success_45 = true;
																							pos += _44.node.length();
																							_0 = _44.node;
																						}
																					}
																					else 
																					{
																						success_43 = true;
																						pos += _42.node.length();
																						_0 = _42.node;
																					}
																				}
																				else 
																				{
																					success_41 = true;
																					pos += _40.node.length();
																					_0 = _40.node;
																				}
																			}
																			else 
																			{
																				success_39 = true;
																				pos += _38.node.length();
																				_0 = _38.node;
																			}
																		}
																		else 
																		{
																			success_37 = true;
																			pos += _36.node.length();
																			_0 = _36.node;
																		}
																	}
																	else 
																	{
																		success_35 = true;
																		pos += _34.node.length();
																		_0 = _34.node;
																	}
																}
																else 
																{
																	success_33 = true;
																	pos += _32.node.length();
																	_0 = _32.node;
																}
															}
															else 
															{
																success_31 = true;
																pos += _30.node.length();
																_0 = _30.node;
															}
														}
														else 
														{
															success_29 = true;
															pos += _28.node.length();
															_0 = _28.node;
														}
													}
													else 
													{
														success_27 = true;
														pos += _26.node.length();
														_0 = _26.node;
													}
												}
												else 
												{
													success_25 = true;
													pos += _24.node.length();
													_0 = _24.node;
												}
											}
											else 
											{
												success_23 = true;
												pos += _22.node.length();
												_0 = _22.node;
											}
										}
										else 
										{
											success_21 = true;
											pos += _20.node.length();
											_0 = _20.node;
										}
									}
									else 
									{
										success_19 = true;
										pos += _18.node.length();
										_0 = _18.node;
									}
								}
								else 
								{
									success_17 = true;
									pos += _16.node.length();
									_0 = _16.node;
								}
							}
							else 
							{
								success_15 = true;
								pos += _14.node.length();
								_0 = _14.node;
							}
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
		success_3 = true;
		pos += _2.node.length();
		_0 = _2.node;
	}
	success_1 = true;
	skip_spaces(pos);
	return _0;
}
Parser::Token_res Parser::Lexer::ID(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	::Parser::str_t _2;
	::Parser::bool_t success_3 = false;
	if (!((*(pos + 0)>='a' && *(pos + 0)<='z') || (*(pos + 0)>='A' && *(pos + 0)<='Z') || *(pos + 0) == '_'))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 1);
	success_1 = true;
	pos += 1;
	skip_spaces(pos);
	while ((*(pos + 0)>='a' && *(pos + 0)<='z') || (*(pos + 0)>='A' && *(pos + 0)<='Z') || (*(pos + 0)>='0' && *(pos + 0)<='9') || *(pos + 0) == '_')
	{
		_2 += ::Parser::str_t(pos, 1);
		success_3 = true;
		pos += 1;
	}
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::ID)};
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
	if (!(*(pos + 0) == '?'))
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
	if (!(*(pos + 0) == ':'))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 1);
	success_1 = true;
	pos += 1;
	::Parser::Types::AUTO_1_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_1, data)};
}
Parser::Token_res Parser::Lexer::AUTO_2(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!std::strncmp(pos + 0, "||", 2)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 2);
	success_1 = true;
	pos += 2;
	::Parser::Types::AUTO_2_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_2, data)};
}
Parser::Token_res Parser::Lexer::AUTO_3(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!std::strncmp(pos + 0, "&&", 2)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 2);
	success_1 = true;
	pos += 2;
	::Parser::Types::AUTO_3_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_3, data)};
}
Parser::Token_res Parser::Lexer::AUTO_4(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!std::strncmp(pos + 0, "==", 2)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 2);
	success_1 = true;
	pos += 2;
	::Parser::Types::AUTO_4_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_4, data)};
}
Parser::Token_res Parser::Lexer::AUTO_5(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!std::strncmp(pos + 0, "!=", 2)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 2);
	success_1 = true;
	pos += 2;
	::Parser::Types::AUTO_5_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_5, data)};
}
Parser::Token_res Parser::Lexer::AUTO_6(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!std::strncmp(pos + 0, "<=", 2)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 2);
	success_1 = true;
	pos += 2;
	::Parser::Types::AUTO_6_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_6, data)};
}
Parser::Token_res Parser::Lexer::AUTO_7(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!std::strncmp(pos + 0, ">=", 2)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 2);
	success_1 = true;
	pos += 2;
	::Parser::Types::AUTO_7_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_7, data)};
}
Parser::Token_res Parser::Lexer::AUTO_8(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == '<'))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 1);
	success_1 = true;
	pos += 1;
	::Parser::Types::AUTO_8_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_8, data)};
}
Parser::Token_res Parser::Lexer::AUTO_9(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == '>'))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 1);
	success_1 = true;
	pos += 1;
	::Parser::Types::AUTO_9_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_9, data)};
}
Parser::Token_res Parser::Lexer::AUTO_10(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == '='))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 1);
	success_1 = true;
	pos += 1;
	::Parser::Types::AUTO_10_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_10, data)};
}
Parser::Token_res Parser::Lexer::AUTO_11(const char* pos) {
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
	::Parser::Types::AUTO_11_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_11, data)};
}
Parser::Token_res Parser::Lexer::AUTO_12(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == '-'))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 1);
	success_1 = true;
	pos += 1;
	::Parser::Types::AUTO_12_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_12, data)};
}
Parser::Token_res Parser::Lexer::AUTO_13(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == '['))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 1);
	success_1 = true;
	pos += 1;
	::Parser::Types::AUTO_13_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_13, data)};
}
Parser::Token_res Parser::Lexer::AUTO_14(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == ']'))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 1);
	success_1 = true;
	pos += 1;
	::Parser::Types::AUTO_14_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_14, data)};
}
Parser::Token_res Parser::Lexer::AUTO_15(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == '('))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 1);
	success_1 = true;
	pos += 1;
	::Parser::Types::AUTO_15_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_15, data)};
}
Parser::Token_res Parser::Lexer::AUTO_16(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == ')'))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 1);
	success_1 = true;
	pos += 1;
	::Parser::Types::AUTO_16_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_16, data)};
}
Parser::Token_res Parser::Lexer::AUTO_17(const char* pos) {
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
	::Parser::Types::AUTO_17_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_17, data)};
}
Parser::Token_res Parser::Lexer::AUTO_18(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == '/'))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 1);
	success_1 = true;
	pos += 1;
	::Parser::Types::AUTO_18_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_18, data)};
}
Parser::Token_res Parser::Lexer::AUTO_19(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == '%'))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 1);
	success_1 = true;
	pos += 1;
	::Parser::Types::AUTO_19_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_19, data)};
}
Parser::Token_res Parser::Lexer::AUTO_20(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == '!'))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 1);
	success_1 = true;
	pos += 1;
	::Parser::Types::AUTO_20_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_20, data)};
}
Parser::Token_res Parser::Lexer::AUTO_21(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == '('))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 1);
	success_1 = true;
	pos += 1;
	::Parser::Types::AUTO_21_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_21, data)};
}
Parser::Token_res Parser::Lexer::AUTO_22(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == ')'))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 1);
	success_1 = true;
	pos += 1;
	::Parser::Types::AUTO_22_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_22, data)};
}
Parser::Token_res Parser::Lexer::AUTO_23(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == ','))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 1);
	success_1 = true;
	pos += 1;
	::Parser::Types::AUTO_23_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_23, data)};
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
	{{std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 6}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 1}), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 2}), std::nullopt, std::nullopt, std::nullopt}},
	{{std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 0}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 0}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 0}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 0}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 0}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 0}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 0}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 0}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 0}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 0}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 0}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 0}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 0}), std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 0}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 0}), std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 0}), std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 0}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 0}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 0}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 0}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 0}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 0}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 0}), std::nullopt}},
	{{std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 6}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 1}), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 2}), std::nullopt, std::nullopt, std::nullopt}},
	{{std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 1}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 1}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 1}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 1}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 1}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 1}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 1}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 1}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 1}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 1}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 1}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 1}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 1}), std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 0}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 1}), std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 1}), std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 1}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 1}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 1}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 1}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 1}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 1}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 1}), std::nullopt}},
	{{std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 2}), std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 19}), std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 18}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 17}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 15}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 14}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 13}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 12}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 11}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 16}), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 3}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 3}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 3}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 3}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 3}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 3}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 3}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 3}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 3}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 3}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 3}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 3}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 3}), std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 3}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 3}), std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 3}), std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 2}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 3}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 4}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 5}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 3}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 3}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 3}), std::nullopt}},
	{{std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 4}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 4}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 4}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 4}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 4}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 4}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 4}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 4}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 4}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 4}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 4}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 4}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 4}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 26}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 4}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 4}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 24}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 4}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 25}), std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 4}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 4}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 4}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 4}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 4}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 4}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 4}), std::nullopt}},
	{{std::make_optional(::Parser::Action{::Parser::Action::Action_type::ACCEPT, 0}), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 19}), std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 18}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 17}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 15}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 14}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 13}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 12}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 11}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 16}), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 27}), std::nullopt, std::nullopt}},
	{{std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 29}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 1}), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 2}), std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 29}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 1}), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 2}), std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 6}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 1}), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 2}), std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 6}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 1}), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 2}), std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 6}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 1}), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 2}), std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 6}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 1}), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 2}), std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 6}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 1}), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 2}), std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 6}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 1}), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 2}), std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 6}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 1}), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 2}), std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 6}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 1}), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 2}), std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 6}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 1}), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 2}), std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 29}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 1}), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 2}), std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 29}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 1}), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 2}), std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 29}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 1}), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 2}), std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 29}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 1}), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 2}), std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 6}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 1}), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 2}), std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 6}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 1}), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 5}), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 2}), std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 6}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 1}), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 2}), std::nullopt, std::nullopt, std::nullopt}},
	{{std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 6}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 6}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 6}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 6}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 6}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 6}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 6}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 6}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 6}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 6}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 6}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 6}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 6}), std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 6}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 6}), std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 6}), std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 6}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 6}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 6}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 6}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 6}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 6}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 6}), std::nullopt}},
	{{std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 7}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 7}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 7}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 7}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 7}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 7}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 7}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 7}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 7}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 7}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 7}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 7}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 7}), std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 6}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 7}), std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 7}), std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 7}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 7}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 7}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 7}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 7}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 7}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 7}), std::nullopt}},
	{{std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 4}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 4}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 4}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 4}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 4}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 4}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 4}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 4}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 4}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 4}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 4}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 4}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 4}), std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 4}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 4}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 24}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 4}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 25}), std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 4}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 4}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 4}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 4}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 4}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 4}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 4}), std::nullopt}},
	{{std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 8}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 8}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 8}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 8}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 8}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 8}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 8}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 8}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 8}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 8}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 8}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 8}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 8}), std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 8}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 9}), std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 8}), std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 8}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 8}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 8}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 8}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 8}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 8}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 8}), std::nullopt}},
	{{std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 9}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 9}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 9}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 10}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 9}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 11}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 12}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 13}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 14}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 15}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 16}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 17}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 18}), std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 9}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 9}), std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 9}), std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 9}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 9}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 9}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 9}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 9}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 9}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 9}), std::nullopt}},
	{{std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 10}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 10}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 10}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 19}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 10}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 20}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 21}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 22}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 23}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 24}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 25}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 26}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 27}), std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 10}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 10}), std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 10}), std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 10}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 10}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 10}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 10}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 10}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 10}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 10}), std::nullopt}},
	{{std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 11}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 11}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 11}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 28}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 11}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 29}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 30}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 31}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 32}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 33}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 34}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 35}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 36}), std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 11}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 11}), std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 11}), std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 11}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 11}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 11}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 11}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 11}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 11}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 11}), std::nullopt}},
	{{std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 12}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 12}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 12}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 37}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 12}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 38}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 39}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 40}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 41}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 42}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 43}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 44}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 45}), std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 12}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 12}), std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 12}), std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 12}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 12}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 12}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 12}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 12}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 12}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 12}), std::nullopt}},
	{{std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 13}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 13}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 13}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 46}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 13}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 47}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 48}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 49}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 50}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 51}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 52}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 53}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 54}), std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 13}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 13}), std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 13}), std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 13}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 13}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 13}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 13}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 13}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 13}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 13}), std::nullopt}},
	{{std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 14}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 14}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 14}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 55}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 14}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 56}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 57}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 58}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 59}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 60}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 61}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 62}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 63}), std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 14}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 14}), std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 14}), std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 14}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 14}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 14}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 14}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 14}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 14}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 14}), std::nullopt}},
	{{std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 15}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 15}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 15}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 64}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 15}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 65}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 66}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 67}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 68}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 69}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 70}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 71}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 72}), std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 15}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 15}), std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 15}), std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 15}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 15}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 15}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 15}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 15}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 15}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 15}), std::nullopt}},
	{{std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 16}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 16}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 16}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 73}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 16}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 74}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 75}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 76}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 77}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 78}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 79}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 80}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 81}), std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 16}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 16}), std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 16}), std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 16}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 16}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 16}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 16}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 16}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 16}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 16}), std::nullopt}},
	{{std::nullopt, std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 19}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 49}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 18}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 17}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 15}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 14}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 13}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 12}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 11}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 16}), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 17}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 17}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 17}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 17}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 17}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 17}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 17}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 17}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 17}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 17}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 17}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 17}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 17}), std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 17}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 17}), std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 17}), std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 82}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 83}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 84}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 85}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 17}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 17}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 17}), std::nullopt}},
	{{std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 18}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 18}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 18}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 18}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 18}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 18}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 18}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 18}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 18}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 18}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 18}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 18}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 18}), std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 18}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 18}), std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 18}), std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 86}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 87}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 88}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 89}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 18}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 18}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 18}), std::nullopt}},
	{{std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 19}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 19}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 19}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 19}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 19}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 19}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 19}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 19}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 19}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 19}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 19}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 19}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 19}), std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 19}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 19}), std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 19}), std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 90}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 91}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 92}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 93}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 19}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 19}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 19}), std::nullopt}},
	{{std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 20}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 20}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 20}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 20}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 20}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 20}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 20}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 20}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 20}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 20}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 20}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 20}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 20}), std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 20}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 20}), std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 20}), std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 94}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 95}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 96}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 97}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 20}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 20}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 20}), std::nullopt}},
	{{std::nullopt, std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 19}), std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 18}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 17}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 15}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 14}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 13}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 12}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 11}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 16}), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 50}), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 51}), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 21}), std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 19}), std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 18}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 17}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 15}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 14}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 13}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 12}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 11}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 16}), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 98}), std::nullopt}},
	{{std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 22}), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 23}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 23}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 23}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 99}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 23}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 100}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 101}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 102}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 103}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 104}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 105}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 106}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 107}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 23}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 23}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 23}), std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 23}), std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 23}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 23}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 23}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 23}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 23}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 23}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 23}), std::nullopt}},
	{{std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 6}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 1}), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 2}), std::nullopt, std::nullopt, std::nullopt}},
	{{std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 24}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 24}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 24}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 24}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 24}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 24}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 24}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 24}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 24}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 24}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 24}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 24}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 24}), std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 24}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 24}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 24}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 24}), std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 24}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 24}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 24}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 24}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 24}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 24}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 24}), std::nullopt}},
	{{std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 25}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 25}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 25}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 25}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 25}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 25}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 25}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 25}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 25}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 25}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 25}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 25}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 25}), std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 25}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 25}), std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 25}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 25}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 25}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 25}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 25}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 25}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 25}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 25}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 25}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 25}), std::nullopt}},
	{{std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 26}), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 26}), std::nullopt}},
	{{std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 6}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 1}), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 2}), std::nullopt, std::nullopt, std::nullopt}},
	{{std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 27}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 27}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 27}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 108}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 27}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 109}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 110}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 111}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 112}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 113}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 114}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 115}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 116}), std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 27}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 27}), std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 27}), std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 27}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 27}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 27}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 27}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 27}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 27}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 27}), std::nullopt}},
	{{std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 21}), std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 19}), std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 18}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 17}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 15}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 14}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 13}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 12}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 11}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 16}), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::DFA_RESOLVE, 117}), std::nullopt}},
	{{std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 28}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 28}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 28}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 28}), std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 28}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 28}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 28}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 28}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 28}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 28}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 28}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 28}), std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 28}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 28}), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 28}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 28}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 28}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 28}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 28}), std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 28}), std::nullopt}}
}};
Parser::GotoTable Parser::Parser::goto_table = {{
	{{std::nullopt, std::make_optional(7), std::make_optional(4), std::make_optional(3), std::make_optional(5), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::nullopt, std::make_optional(8), std::make_optional(3), std::make_optional(5), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::nullopt, std::nullopt, std::make_optional(28), std::make_optional(5), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::nullopt, std::nullopt, std::make_optional(30), std::make_optional(5), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::nullopt, std::make_optional(31), std::make_optional(3), std::make_optional(5), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::nullopt, std::make_optional(32), std::make_optional(3), std::make_optional(5), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::nullopt, std::make_optional(33), std::make_optional(3), std::make_optional(5), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::nullopt, std::make_optional(34), std::make_optional(3), std::make_optional(5), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::nullopt, std::make_optional(35), std::make_optional(3), std::make_optional(5), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::nullopt, std::make_optional(36), std::make_optional(3), std::make_optional(5), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::nullopt, std::make_optional(37), std::make_optional(3), std::make_optional(5), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::nullopt, std::make_optional(38), std::make_optional(3), std::make_optional(5), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::nullopt, std::make_optional(39), std::make_optional(3), std::make_optional(5), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::make_optional(40), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::make_optional(41), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::make_optional(42), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::make_optional(43), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::nullopt, std::make_optional(44), std::make_optional(3), std::make_optional(5), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::nullopt, std::make_optional(46), std::make_optional(3), std::make_optional(5), std::make_optional(47), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::make_optional(45), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::nullopt, std::make_optional(48), std::make_optional(3), std::make_optional(5), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::make_optional(52), std::nullopt, std::nullopt}},
	{{std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::nullopt, std::make_optional(54), std::make_optional(3), std::make_optional(5), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::nullopt, std::make_optional(55), std::make_optional(3), std::make_optional(5), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::make_optional(56), std::nullopt, std::nullopt}}
}};
Parser::RulesTable Parser::Parser::rules_table = {
	{
	{::Parser::Rules::factor, 1},
	{::Parser::Rules::expr, 1},
	{::Parser::Rules::main, 1},
	{::Parser::Rules::term, 1},
	{::Parser::Rules::factor, 1},
	{::Parser::Rules::__q2, 0},
	{::Parser::Rules::factor, 3},
	{::Parser::Rules::term, 3},
	{::Parser::Rules::term, 3},
	{::Parser::Rules::expr, 3},
	{::Parser::Rules::expr, 3},
	{::Parser::Rules::expr, 3},
	{::Parser::Rules::expr, 3},
	{::Parser::Rules::expr, 3},
	{::Parser::Rules::expr, 3},
	{::Parser::Rules::expr, 3},
	{::Parser::Rules::expr, 3},
	{::Parser::Rules::factor, 3},
	{::Parser::Rules::factor, 3},
	{::Parser::Rules::factor, 3},
	{::Parser::Rules::factor, 3},
	{::Parser::Rules::__grp1, 0},
	{::Parser::Rules::__q2, 1},
	{::Parser::Rules::expr, 3},
	{::Parser::Rules::factor, 4},
	{::Parser::Rules::factor, 4},
	{::Parser::Rules::arg_list, 2},
	{::Parser::Rules::expr, 5},
	{::Parser::Rules::__grp1, 3}
	}
};
Parser::DFATable Parser::Parser::dfa_table = {
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 10}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 9}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 23}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 22}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 21}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 20}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::REDUCE, 7}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 118, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::REDUCE, 7}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 119, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::REDUCE, 8}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::REDUCE, 8}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 121, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::REDUCE, 9}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 122, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::REDUCE, 9}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 123, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::REDUCE, 9}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 124, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::REDUCE, 9}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 125, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::REDUCE, 9}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 126, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::REDUCE, 9}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 127, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::REDUCE, 9}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::REDUCE, 9}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 129, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::REDUCE, 9}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 130, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::REDUCE, 10}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 131, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::REDUCE, 10}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 132, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::REDUCE, 10}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 133, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::REDUCE, 10}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 134, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::REDUCE, 10}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 135, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::REDUCE, 10}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 136, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::REDUCE, 10}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 137, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::REDUCE, 10}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 138, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 16}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::REDUCE, 11}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 139, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::REDUCE, 11}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 140, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::REDUCE, 11}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 141, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::REDUCE, 11}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 142, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::REDUCE, 11}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 143, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::REDUCE, 11}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 144, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::REDUCE, 11}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 145, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 11}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 16}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::REDUCE, 12}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 146, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::REDUCE, 12}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 147, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::REDUCE, 12}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 148, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::REDUCE, 12}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 149, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::REDUCE, 12}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 150, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::REDUCE, 12}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 151, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 12}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 11}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 16}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::REDUCE, 13}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 152, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::REDUCE, 13}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 153, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::REDUCE, 13}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 154, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::REDUCE, 13}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 155, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::REDUCE, 13}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 156, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 13}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 12}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 11}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 16}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::REDUCE, 14}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 157, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::REDUCE, 14}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 158, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::REDUCE, 14}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 159, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::REDUCE, 14}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 160, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::REDUCE, 14}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 161, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::REDUCE, 14}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 162, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::REDUCE, 14}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 163, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::REDUCE, 14}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 164, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::REDUCE, 14}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 165, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::REDUCE, 15}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 166, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::REDUCE, 15}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 167, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::REDUCE, 15}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 168, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::REDUCE, 15}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 169, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 14}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 13}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 12}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 11}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 16}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::REDUCE, 16}, std::array<size_t, 28> {0, 0, 0, 0, 0, 170, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::REDUCE, 16}, std::array<size_t, 28> {0, 0, 0, 0, 0, 171, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::REDUCE, 16}, std::array<size_t, 28> {0, 0, 0, 0, 0, 172, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 15}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 14}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 13}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 12}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 11}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 16}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::REDUCE, 17}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 173, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::REDUCE, 17}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 174, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::REDUCE, 17}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 175, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::REDUCE, 17}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 176, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::REDUCE, 18}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 177, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::REDUCE, 18}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 178, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::REDUCE, 18}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 179, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::REDUCE, 18}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 180, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::REDUCE, 19}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 181, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::REDUCE, 19}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 182, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::REDUCE, 19}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 183, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 20}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::REDUCE, 20}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 184, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::REDUCE, 20}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 185, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 21}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 20}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 53}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::REDUCE, 23}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 186, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 18}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 17}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 15}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 14}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 13}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 12}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 11}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 16}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::REDUCE, 27}, std::array<size_t, 28> {0, 0, 0, 0, 187, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::REDUCE, 27}, std::array<size_t, 28> {0, 0, 0, 0, 188, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 17}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 15}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 14}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 13}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 12}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 11}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 16}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 53}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::ERROR, 0}, std::array<size_t, 28> {0, 189, 189, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 189, 189, 0, 0, 0, 0, 189, 189, 189, 189, 189, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::ERROR, 0}, std::array<size_t, 28> {0, 190, 190, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 190, 190, 0, 0, 0, 0, 190, 190, 190, 190, 190, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::ERROR, 0}, std::array<size_t, 28> {0, 191, 191, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 191, 191, 0, 0, 0, 0, 191, 191, 191, 191, 191, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::ERROR, 0}, std::array<size_t, 28> {0, 192, 192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 192, 192, 0, 0, 0, 0, 192, 192, 192, 192, 192, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::ERROR, 0}, std::array<size_t, 28> {0, 193, 193, 193, 0, 193, 193, 193, 193, 193, 193, 193, 193, 0, 193, 193, 0, 0, 0, 0, 193, 193, 193, 193, 193, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::ERROR, 0}, std::array<size_t, 28> {0, 194, 194, 194, 0, 194, 194, 194, 194, 194, 194, 194, 194, 0, 194, 194, 0, 0, 0, 0, 194, 194, 194, 194, 194, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::ERROR, 0}, std::array<size_t, 28> {0, 195, 195, 195, 0, 195, 195, 195, 195, 195, 195, 195, 195, 0, 195, 195, 0, 0, 0, 0, 195, 195, 195, 195, 195, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::ERROR, 0}, std::array<size_t, 28> {0, 196, 196, 196, 0, 196, 196, 196, 196, 196, 196, 196, 196, 0, 196, 196, 0, 0, 0, 0, 196, 196, 196, 196, 196, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::ERROR, 0}, std::array<size_t, 28> {0, 197, 197, 197, 0, 197, 197, 197, 197, 197, 197, 197, 197, 0, 197, 197, 0, 0, 0, 0, 197, 197, 197, 197, 197, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::ERROR, 0}, std::array<size_t, 28> {0, 198, 198, 198, 0, 198, 198, 198, 198, 198, 198, 198, 198, 0, 198, 198, 0, 0, 0, 0, 198, 198, 198, 198, 198, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::ERROR, 0}, std::array<size_t, 28> {0, 199, 199, 199, 0, 199, 199, 199, 199, 199, 199, 199, 199, 0, 199, 199, 0, 0, 0, 0, 199, 199, 199, 199, 199, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::ERROR, 0}, std::array<size_t, 28> {0, 200, 200, 200, 0, 200, 200, 200, 200, 200, 200, 200, 200, 0, 200, 200, 0, 0, 0, 0, 200, 200, 200, 200, 200, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::ERROR, 0}, std::array<size_t, 28> {0, 201, 201, 201, 0, 201, 201, 201, 201, 201, 201, 201, 201, 0, 201, 201, 0, 0, 0, 0, 201, 201, 201, 201, 201, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::ERROR, 0}, std::array<size_t, 28> {0, 202, 202, 202, 0, 202, 202, 202, 202, 202, 202, 202, 202, 0, 202, 202, 0, 0, 0, 0, 202, 202, 202, 202, 202, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::ERROR, 0}, std::array<size_t, 28> {0, 203, 203, 203, 0, 203, 203, 203, 203, 203, 203, 203, 203, 0, 203, 203, 0, 0, 0, 0, 203, 203, 203, 203, 203, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::ERROR, 0}, std::array<size_t, 28> {0, 204, 204, 204, 0, 204, 204, 204, 204, 204, 204, 204, 204, 0, 204, 204, 0, 0, 0, 0, 204, 204, 204, 204, 204, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::ERROR, 0}, std::array<size_t, 28> {0, 205, 205, 205, 0, 205, 205, 205, 205, 205, 205, 205, 205, 0, 205, 205, 0, 0, 0, 0, 205, 205, 205, 205, 205, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::ERROR, 0}, std::array<size_t, 28> {0, 206, 206, 206, 0, 206, 206, 206, 206, 206, 206, 206, 206, 0, 206, 206, 0, 0, 0, 0, 206, 206, 206, 206, 206, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::ERROR, 0}, std::array<size_t, 28> {0, 207, 207, 207, 0, 207, 207, 207, 207, 207, 207, 207, 207, 0, 207, 207, 0, 0, 0, 0, 207, 207, 207, 207, 207, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::ERROR, 0}, std::array<size_t, 28> {0, 208, 208, 208, 0, 208, 208, 208, 208, 208, 208, 208, 208, 0, 208, 208, 0, 0, 0, 0, 208, 208, 208, 208, 208, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::ERROR, 0}, std::array<size_t, 28> {0, 209, 209, 209, 0, 209, 209, 209, 209, 209, 209, 209, 209, 0, 209, 209, 0, 0, 0, 0, 209, 209, 209, 209, 209, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::ERROR, 0}, std::array<size_t, 28> {0, 210, 210, 210, 0, 210, 210, 210, 210, 210, 210, 210, 210, 0, 210, 210, 0, 0, 0, 0, 210, 210, 210, 210, 210, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::ERROR, 0}, std::array<size_t, 28> {0, 211, 211, 211, 0, 211, 211, 211, 211, 211, 211, 211, 211, 0, 211, 211, 0, 0, 0, 0, 211, 211, 211, 211, 211, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::ERROR, 0}, std::array<size_t, 28> {0, 212, 212, 212, 0, 212, 212, 212, 212, 212, 212, 212, 212, 0, 212, 212, 0, 0, 0, 0, 212, 212, 212, 212, 212, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::ERROR, 0}, std::array<size_t, 28> {0, 213, 213, 213, 0, 213, 213, 213, 213, 213, 213, 213, 213, 0, 213, 213, 0, 0, 0, 0, 213, 213, 213, 213, 213, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::ERROR, 0}, std::array<size_t, 28> {0, 214, 214, 214, 0, 214, 214, 214, 214, 214, 214, 214, 214, 0, 214, 214, 0, 0, 0, 0, 214, 214, 214, 214, 214, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::ERROR, 0}, std::array<size_t, 28> {0, 215, 215, 215, 0, 215, 215, 215, 215, 215, 215, 215, 215, 0, 215, 215, 0, 0, 0, 0, 215, 215, 215, 215, 215, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::ERROR, 0}, std::array<size_t, 28> {0, 216, 216, 216, 0, 216, 216, 216, 216, 216, 216, 216, 216, 0, 216, 216, 0, 0, 0, 0, 216, 216, 216, 216, 216, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::ERROR, 0}, std::array<size_t, 28> {0, 217, 217, 217, 0, 217, 217, 217, 217, 217, 217, 217, 217, 0, 217, 217, 0, 0, 0, 0, 217, 217, 217, 217, 217, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::ERROR, 0}, std::array<size_t, 28> {0, 218, 218, 218, 0, 218, 218, 218, 218, 218, 218, 218, 218, 0, 218, 218, 0, 0, 0, 0, 218, 218, 218, 218, 218, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::ERROR, 0}, std::array<size_t, 28> {0, 219, 219, 219, 0, 219, 219, 219, 219, 219, 219, 219, 219, 0, 219, 219, 0, 0, 0, 0, 219, 219, 219, 219, 219, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::ERROR, 0}, std::array<size_t, 28> {0, 220, 220, 220, 0, 220, 220, 220, 220, 220, 220, 220, 220, 0, 220, 220, 0, 0, 0, 0, 220, 220, 220, 220, 220, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::ERROR, 0}, std::array<size_t, 28> {0, 221, 221, 221, 0, 221, 221, 221, 221, 221, 221, 221, 221, 0, 221, 221, 0, 0, 0, 0, 221, 221, 221, 221, 221, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::ERROR, 0}, std::array<size_t, 28> {0, 222, 222, 222, 0, 222, 222, 222, 222, 222, 222, 222, 222, 0, 222, 222, 0, 0, 0, 0, 222, 222, 222, 222, 222, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::ERROR, 0}, std::array<size_t, 28> {0, 223, 223, 223, 0, 223, 223, 223, 223, 223, 223, 223, 223, 0, 223, 223, 0, 0, 0, 0, 223, 223, 223, 223, 223, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::ERROR, 0}, std::array<size_t, 28> {0, 224, 224, 224, 0, 224, 224, 224, 224, 224, 224, 224, 224, 0, 224, 224, 0, 0, 0, 0, 224, 224, 224, 224, 224, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::ERROR, 0}, std::array<size_t, 28> {0, 225, 225, 225, 0, 225, 225, 225, 225, 225, 225, 225, 225, 0, 225, 225, 0, 0, 0, 0, 225, 225, 225, 225, 225, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::ERROR, 0}, std::array<size_t, 28> {0, 226, 226, 226, 0, 226, 226, 226, 226, 226, 226, 226, 226, 0, 226, 226, 0, 0, 0, 0, 226, 226, 226, 226, 226, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::ERROR, 0}, std::array<size_t, 28> {0, 227, 227, 227, 0, 227, 227, 227, 227, 227, 227, 227, 227, 0, 227, 227, 0, 0, 0, 0, 227, 227, 227, 227, 227, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::ERROR, 0}, std::array<size_t, 28> {0, 228, 228, 228, 0, 228, 228, 228, 228, 228, 228, 228, 228, 0, 228, 228, 0, 0, 0, 0, 228, 228, 228, 228, 228, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::ERROR, 0}, std::array<size_t, 28> {0, 229, 229, 229, 0, 229, 229, 229, 229, 229, 229, 229, 229, 0, 229, 229, 0, 0, 0, 0, 229, 229, 229, 229, 229, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::ERROR, 0}, std::array<size_t, 28> {0, 230, 230, 230, 0, 230, 230, 230, 230, 230, 230, 230, 230, 0, 230, 230, 0, 0, 0, 0, 230, 230, 230, 230, 230, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::ERROR, 0}, std::array<size_t, 28> {0, 231, 231, 231, 0, 231, 231, 231, 231, 231, 231, 231, 231, 0, 231, 231, 0, 0, 0, 0, 231, 231, 231, 231, 231, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::ERROR, 0}, std::array<size_t, 28> {0, 232, 232, 232, 0, 232, 232, 232, 232, 232, 232, 232, 232, 0, 232, 232, 0, 0, 0, 0, 232, 232, 232, 232, 232, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::ERROR, 0}, std::array<size_t, 28> {0, 233, 233, 233, 0, 233, 233, 233, 233, 233, 233, 233, 233, 0, 233, 233, 0, 0, 0, 0, 233, 233, 233, 233, 233, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::ERROR, 0}, std::array<size_t, 28> {0, 234, 234, 234, 0, 234, 234, 234, 234, 234, 234, 234, 234, 0, 234, 234, 0, 0, 0, 0, 234, 234, 234, 234, 234, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::ERROR, 0}, std::array<size_t, 28> {0, 235, 235, 235, 0, 235, 235, 235, 235, 235, 235, 235, 235, 0, 235, 235, 0, 0, 0, 0, 235, 235, 235, 235, 235, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::ERROR, 0}, std::array<size_t, 28> {0, 236, 236, 236, 0, 236, 236, 236, 236, 236, 236, 236, 236, 0, 236, 236, 0, 0, 0, 0, 236, 236, 236, 236, 236, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::ERROR, 0}, std::array<size_t, 28> {0, 237, 237, 237, 0, 237, 237, 237, 237, 237, 237, 237, 237, 0, 237, 237, 0, 0, 0, 0, 237, 237, 237, 237, 237, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::ERROR, 0}, std::array<size_t, 28> {0, 238, 238, 238, 0, 238, 238, 238, 238, 238, 238, 238, 238, 0, 238, 238, 0, 0, 0, 0, 238, 238, 238, 238, 238, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::ERROR, 0}, std::array<size_t, 28> {0, 239, 239, 239, 0, 239, 239, 239, 239, 239, 239, 239, 239, 0, 239, 239, 0, 0, 0, 0, 239, 239, 239, 239, 239, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::ERROR, 0}, std::array<size_t, 28> {0, 240, 240, 240, 0, 240, 240, 240, 240, 240, 240, 240, 240, 0, 240, 240, 0, 0, 0, 0, 240, 240, 240, 240, 240, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::ERROR, 0}, std::array<size_t, 28> {0, 241, 241, 241, 0, 241, 241, 241, 241, 241, 241, 241, 241, 0, 241, 241, 0, 0, 0, 0, 241, 241, 241, 241, 241, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::ERROR, 0}, std::array<size_t, 28> {0, 242, 242, 242, 0, 242, 242, 242, 242, 242, 242, 242, 242, 0, 242, 242, 0, 0, 0, 0, 242, 242, 242, 242, 242, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::ERROR, 0}, std::array<size_t, 28> {0, 243, 243, 243, 0, 243, 243, 243, 243, 243, 243, 243, 243, 0, 243, 243, 0, 0, 0, 0, 243, 243, 243, 243, 243, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::ERROR, 0}, std::array<size_t, 28> {0, 244, 244, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 244, 244, 244, 244, 244, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::ERROR, 0}, std::array<size_t, 28> {0, 245, 245, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 245, 245, 245, 245, 245, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::ERROR, 0}, std::array<size_t, 28> {0, 246, 246, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 246, 246, 246, 246, 246, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::ERROR, 0}, std::array<size_t, 28> {0, 247, 247, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 247, 247, 247, 247, 247, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::ERROR, 0}, std::array<size_t, 28> {0, 248, 248, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 248, 248, 248, 248, 248, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::ERROR, 0}, std::array<size_t, 28> {0, 249, 249, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 249, 249, 249, 249, 249, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::ERROR, 0}, std::array<size_t, 28> {0, 250, 250, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 250, 250, 250, 250, 250, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::ERROR, 0}, std::array<size_t, 28> {0, 251, 251, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 251, 251, 251, 251, 251, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::ERROR, 0}, std::array<size_t, 28> {0, 252, 252, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 252, 252, 252, 252, 252, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::ERROR, 0}, std::array<size_t, 28> {0, 253, 253, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 253, 253, 253, 253, 253, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::ERROR, 0}, std::array<size_t, 28> {0, 254, 254, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 254, 254, 254, 254, 254, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::ERROR, 0}, std::array<size_t, 28> {0, 255, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255, 255, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::ERROR, 0}, std::array<size_t, 28> {0, 256, 256, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 256, 256, 256, 256, 256, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::ERROR, 0}, std::array<size_t, 28> {0, 257, 257, 257, 0, 257, 257, 257, 257, 257, 257, 257, 257, 0, 257, 257, 0, 0, 0, 0, 257, 257, 257, 257, 257, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::ERROR, 0}, std::array<size_t, 28> {0, 258, 258, 258, 0, 258, 258, 258, 258, 258, 258, 258, 258, 0, 258, 258, 0, 0, 0, 0, 258, 258, 258, 258, 258, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::ERROR, 0}, std::array<size_t, 28> {0, 259, 259, 259, 0, 259, 259, 259, 259, 259, 259, 259, 259, 0, 259, 259, 0, 0, 0, 0, 259, 259, 259, 259, 259, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 10}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 9}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 10}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 9}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 19}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 18}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 17}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 15}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 14}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 13}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 12}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 11}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 16}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 19}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 18}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 17}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 15}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 14}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 13}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 12}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 11}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 19}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 18}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 17}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 15}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 14}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 13}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 12}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 19}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 18}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 17}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 15}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 14}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 13}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 19}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 18}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 17}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 15}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 14}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 19}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 18}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 17}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 15}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 14}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 13}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 12}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 11}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 16}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 19}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 18}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 17}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 15}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 19}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 18}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 17}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 23}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 22}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 21}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 20}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 23}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 22}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 21}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 20}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 23}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 22}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 21}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 23}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 22}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 19}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 19}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
	std::make_pair(::Parser::Action {::Parser::Action::SHIFT, 18}, std::array<size_t, 28> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
};
