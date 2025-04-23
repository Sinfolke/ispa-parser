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
	if (!(*(pos + 0) == '('))
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
	if (!(*(pos + 0) == ')'))
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
	if (!(*(pos + 0) == '*'))
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
	if (!(*(pos + 0) == '/'))
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
	if (!(*(pos + 0) == '%'))
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
	if (!(*(pos + 0) == '!'))
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
	{{std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 10}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 1}), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 5}), std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 7}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 3}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 4}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 2}), std::nullopt, std::nullopt}},
	{{std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 0}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 0}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 0}), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 0}), std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 0}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 0}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 0}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 0}), std::nullopt, std::nullopt}},
	{{std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 12}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 1}), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 5}), std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 7}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 3}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 4}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 2}), std::nullopt, std::nullopt}},
	{{std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 12}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 1}), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 5}), std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 7}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 3}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 4}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 2}), std::nullopt, std::nullopt}},
	{{std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 12}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 1}), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 5}), std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 7}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 3}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 4}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 2}), std::nullopt, std::nullopt}},
	{{std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 10}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 1}), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 5}), std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 7}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 3}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 4}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 2}), std::nullopt, std::nullopt}},
	{{std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 1}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 1}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 1}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 1}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 1}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 1}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 1}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 1}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 1}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 1}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 1}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 1}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 1}), std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 18}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 17}), std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 1}), std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 1}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 1}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 1}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 1}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 1}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 1}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 1}), std::nullopt}},
	{{std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 12}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 1}), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 5}), std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 7}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 3}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 4}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 2}), std::nullopt, std::nullopt}},
	{{std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 2}), std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 28}), std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 27}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 26}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 24}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 23}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 22}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 21}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 20}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 25}), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 3}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 3}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 3}), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 3}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 3}), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 3}), std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 3}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 3}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 3}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 3}), std::nullopt, std::nullopt}},
	{{std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 4}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 4}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 4}), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 31}), std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 29}), std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 30}), std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 4}), std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 4}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 4}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 4}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 4}), std::nullopt, std::nullopt}},
	{{std::make_optional(::Parser::Action{::Parser::Action::Action_type::ACCEPT, 0}), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 4}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 4}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 4}), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 29}), std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 30}), std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 4}), std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 4}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 4}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 4}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 4}), std::nullopt, std::nullopt}},
	{{std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 5}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 5}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 5}), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 5}), std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 5}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 5}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 5}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 5}), std::nullopt, std::nullopt}},
	{{std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 6}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 6}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 6}), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 6}), std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 6}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 6}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 6}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 6}), std::nullopt, std::nullopt}},
	{{std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 7}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 7}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 7}), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 7}), std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 7}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 7}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 7}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 7}), std::nullopt, std::nullopt}},
	{{std::nullopt, std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 28}), std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 27}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 26}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 24}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 23}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 22}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 21}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 20}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 25}), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 32}), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 12}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 1}), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 5}), std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 7}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 3}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 4}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 2}), std::nullopt, std::nullopt}},
	{{std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 12}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 1}), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 5}), std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 7}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 3}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 4}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 2}), std::nullopt, std::nullopt}},
	{{std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 8}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 8}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 8}), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 8}), std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 8}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 8}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 8}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 8}), std::nullopt, std::nullopt}},
	{{std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 10}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 1}), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 5}), std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 7}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 3}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 4}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 2}), std::nullopt, std::nullopt}},
	{{std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 10}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 1}), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 5}), std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 7}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 3}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 4}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 2}), std::nullopt, std::nullopt}},
	{{std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 10}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 1}), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 5}), std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 7}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 3}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 4}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 2}), std::nullopt, std::nullopt}},
	{{std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 10}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 1}), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 5}), std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 7}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 3}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 4}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 2}), std::nullopt, std::nullopt}},
	{{std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 10}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 1}), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 5}), std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 7}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 3}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 4}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 2}), std::nullopt, std::nullopt}},
	{{std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 10}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 1}), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 5}), std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 7}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 3}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 4}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 2}), std::nullopt, std::nullopt}},
	{{std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 10}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 1}), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 5}), std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 7}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 3}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 4}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 2}), std::nullopt, std::nullopt}},
	{{std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 10}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 1}), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 5}), std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 7}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 3}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 4}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 2}), std::nullopt, std::nullopt}},
	{{std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 10}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 1}), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 5}), std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 7}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 3}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 4}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 2}), std::nullopt, std::nullopt}},
	{{std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 10}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 1}), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 5}), std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 7}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 3}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 4}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 2}), std::nullopt, std::nullopt}},
	{{std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 10}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 1}), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 9}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 5}), std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 7}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 3}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 4}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 2}), std::nullopt, std::nullopt}},
	{{std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 10}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 1}), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 5}), std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 7}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 3}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 4}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 2}), std::nullopt, std::nullopt}},
	{{std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 10}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 10}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 10}), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 10}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 10}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 10}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 10}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 10}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 10}), std::nullopt, std::nullopt}},
	{{std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 11}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 11}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 11}), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 11}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 11}), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 11}), std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 11}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 11}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 11}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 11}), std::nullopt, std::nullopt}},
	{{std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 12}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 12}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 12}), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 12}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 12}), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 12}), std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 12}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 12}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 12}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 12}), std::nullopt, std::nullopt}},
	{{std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 13}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 13}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 13}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 28}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 13}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 27}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 26}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 24}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 23}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 22}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 21}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 20}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 25}), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 13}), std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 13}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 13}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 13}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 13}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 13}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 13}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 13}), std::nullopt}},
	{{std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 14}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 14}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 14}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 28}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 14}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 27}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 26}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 24}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 23}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 22}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 21}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 20}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 25}), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 14}), std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 14}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 14}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 14}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 14}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 14}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 14}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 14}), std::nullopt}},
	{{std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 15}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 15}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 15}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 28}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 15}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 27}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 26}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 24}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 23}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 22}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 21}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 20}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 25}), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 15}), std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 15}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 15}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 15}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 15}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 15}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 15}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 15}), std::nullopt}},
	{{std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 16}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 16}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 16}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 28}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 16}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 27}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 26}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 24}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 23}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 22}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 21}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 20}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 25}), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 16}), std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 16}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 16}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 16}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 16}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 16}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 16}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 16}), std::nullopt}},
	{{std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 17}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 17}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 17}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 28}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 17}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 27}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 26}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 24}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 23}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 22}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 21}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 20}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 25}), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 17}), std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 17}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 17}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 17}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 17}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 17}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 17}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 17}), std::nullopt}},
	{{std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 18}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 18}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 18}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 28}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 18}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 27}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 26}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 24}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 23}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 22}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 21}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 20}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 25}), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 18}), std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 18}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 18}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 18}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 18}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 18}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 18}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 18}), std::nullopt}},
	{{std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 19}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 19}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 19}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 28}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 19}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 27}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 26}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 24}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 23}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 22}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 21}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 20}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 25}), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 19}), std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 19}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 19}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 19}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 19}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 19}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 19}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 19}), std::nullopt}},
	{{std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 20}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 20}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 20}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 28}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 20}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 27}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 26}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 24}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 23}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 22}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 21}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 20}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 25}), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 20}), std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 20}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 20}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 20}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 20}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 20}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 20}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 20}), std::nullopt}},
	{{std::nullopt, std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 28}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 49}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 27}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 26}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 24}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 23}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 22}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 21}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 20}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 25}), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 28}), std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 27}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 26}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 24}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 23}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 22}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 21}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 20}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 25}), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 50}), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 51}), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 21}), std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 28}), std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 27}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 26}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 24}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 23}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 22}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 21}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 20}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 25}), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 53}), std::nullopt}},
	{{std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 22}), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 23}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 23}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 23}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 28}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 23}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 27}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 26}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 24}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 23}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 22}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 21}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 20}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 25}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 23}), std::nullopt, std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 23}), std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 23}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 23}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 23}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 23}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 23}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 23}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 23}), std::nullopt}},
	{{std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 10}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 1}), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 5}), std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 7}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 3}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 4}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 2}), std::nullopt, std::nullopt}},
	{{std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 24}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 24}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 24}), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 24}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 24}), std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 24}), std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 24}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 24}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 24}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 24}), std::nullopt, std::nullopt}},
	{{std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 25}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 25}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 25}), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 25}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 25}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 25}), std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 25}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 25}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 25}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 25}), std::nullopt, std::nullopt}},
	{{std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 26}), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 26}), std::nullopt}},
	{{std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 10}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 1}), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 5}), std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 7}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 3}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 4}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 2}), std::nullopt, std::nullopt}},
	{{std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 27}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 27}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 27}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 28}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 27}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 27}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 26}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 24}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 23}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 22}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 21}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 20}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 25}), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 27}), std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 27}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 27}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 27}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 27}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 27}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 27}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 27}), std::nullopt}},
	{{std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 21}), std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 28}), std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 27}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 26}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 24}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 23}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 22}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 21}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 20}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 25}), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::SHIFT, 53}), std::nullopt}},
	{{std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 28}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 28}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 28}), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 28}), std::nullopt, std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 28}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 28}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 28}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 28}), std::make_optional(::Parser::Action{::Parser::Action::Action_type::REDUCE, 28}), std::nullopt}}
}};
Parser::GotoTable Parser::Parser::goto_table = {{
	{{std::nullopt, std::make_optional(11), std::make_optional(8), std::make_optional(6), std::make_optional(9), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::make_optional(13), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::make_optional(14), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::make_optional(15), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::nullopt, std::make_optional(16), std::make_optional(6), std::make_optional(9), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::make_optional(19), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::make_optional(33), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::make_optional(34), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::nullopt, std::make_optional(35), std::make_optional(6), std::make_optional(9), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::nullopt, std::make_optional(36), std::make_optional(6), std::make_optional(9), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::nullopt, std::make_optional(37), std::make_optional(6), std::make_optional(9), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::nullopt, std::make_optional(38), std::make_optional(6), std::make_optional(9), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::nullopt, std::make_optional(39), std::make_optional(6), std::make_optional(9), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::nullopt, std::make_optional(40), std::make_optional(6), std::make_optional(9), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::nullopt, std::make_optional(41), std::make_optional(6), std::make_optional(9), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::nullopt, std::make_optional(42), std::make_optional(6), std::make_optional(9), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::nullopt, std::make_optional(43), std::make_optional(6), std::make_optional(9), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::nullopt, std::make_optional(44), std::make_optional(6), std::make_optional(9), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::nullopt, std::make_optional(46), std::make_optional(6), std::make_optional(9), std::make_optional(47), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::make_optional(45), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::nullopt, std::make_optional(48), std::make_optional(6), std::make_optional(9), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
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
	{{std::nullopt, std::nullopt, std::make_optional(54), std::make_optional(6), std::make_optional(9), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
	{{std::nullopt, std::nullopt, std::make_optional(55), std::make_optional(6), std::make_optional(9), std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}},
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
	{::Parser::Rules::factor, 2},
	{::Parser::Rules::factor, 2},
	{::Parser::Rules::factor, 2},
	{::Parser::Rules::factor, 2},
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
