#include "Parser.h"
Parser::Rule_res Parser::Parser::accessor_group(Token*& pos) {
	auto in = pos;
	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	::Parser::Token _2;
	::Parser::bool_t success_3 = false;
	if (!(pos->name == Tokens::AUTO_4))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos += 2;
	ISC_STD::skip_spaces(pos);
	if (!(pos->name == Tokens::NUMBER))
	{
		return {};
	}
	_2 = *pos;
	success_3 = true;
	pos += 2;
	accessor_group_data data = _2;
	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::accessor_group, data)};
}
Parser::Rule_res Parser::Parser::accessor_element(Token*& pos) {
	auto in = pos;
	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	::Parser::Token _2;
	::Parser::bool_t success_3 = false;
	if (!(pos->name == Tokens::AUTO_1))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos += 2;
	ISC_STD::skip_spaces(pos);
	if (!(pos->name == Tokens::NUMBER))
	{
		return {};
	}
	_2 = *pos;
	success_3 = true;
	pos += 2;
	accessor_element_data data = _2;
	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::accessor_element, data)};
}
Parser::Rule_res Parser::Parser::accessor_char(Token*& pos) {
	auto in = pos;
	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	::Parser::Token _2;
	::Parser::bool_t success_3 = false;
	if (!(pos->name == Tokens::AUTO_89))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos += 2;
	ISC_STD::skip_spaces(pos);
	if (!(pos->name == Tokens::NUMBER))
	{
		return {};
	}
	_2 = *pos;
	success_3 = true;
	pos += 2;
	accessor_char_data data = _2;
	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::accessor_char, data)};
}
Parser::Rule_res Parser::Parser::accessor_all(Token*& pos) {
	auto in = pos;
	::Parser::Rule _0;
	::Parser::bool_t success_1 = false;
	::Parser::Rule_res _2;
	::Parser::bool_t success_3 = false;
	::Parser::Rule_res _4;
	::Parser::bool_t success_5 = false;
	::Parser::Rule_res _6;
	::Parser::bool_t success_7 = false;
	_2 = accessor_group(pos);
	if (!(_2.result))
	{
		_4 = accessor_element(pos);
		if (!(_4.result))
		{
			_6 = accessor_char(pos);
			if (!(_6.result))
			{
				return {};
			}
			else 
			{
				success_7 = true;
				_0 = _6.token;
			}
		}
		else 
		{
			success_5 = true;
			_0 = _4.token;
		}
	}
	else 
	{
		success_3 = true;
		_0 = _2.token;
	}
	success_1 = true;
	pos += 1;
	accessor_all_data data = _0;
	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::accessor_all, data)};
}
Parser::Rule_res Parser::Parser::accessor(Token*& pos) {
	auto in = pos;
	::Parser::Rule_res _0;
	::Parser::bool_t success_1 = false;
	::Parser::arr_t<::Parser::UNDEF> shadow_11;
	::Parser::bool_t success_3 = false;
	::Parser::Token _4;
	::Parser::bool_t success_5 = false;
	::Parser::arr_t<::Parser::Token> shadow_6;
	::Parser::Rule_res _7;
	::Parser::bool_t success_8 = false;
	::Parser::arr_t<::Parser::Rule> shadow_9;
	_0 = accessor_all(pos);
	if (!(_0.result))
	{
		return {};
	}
	success_1 = true;
	pos += 1;
	ISC_STD::skip_spaces(pos);
	auto begin_10 = pos;
	while (1)
	{
		if (!(begin_10->name == Tokens::AUTO_3))
		{
			break;
		}
		_4 = *begin_10;
		success_5 = true;
		begin_10 += 2;
		shadow_6.push_back(_4);
		ISC_STD::skip_spaces(pos);
		_7 = accessor_all(begin_10);
		if (!(_7.result))
		{
			break;
		}
		success_8 = true;
		begin_10 += 1;
		shadow_9.push_back(_7.token);
		shadow_11.push_back(_2);
	}
	if (success_8)
	{
		success_3 = true;
		pos = begin_10;
	}
	accessor_data data;
	data.second = shadow_9;
	data.first = _0.token;

	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::accessor, data)};
}
Parser::Rule_res Parser::Parser::cll(Token*& pos) {
	auto in = pos;
	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	::Parser::arr_t<::Parser::UNDEF> shadow_35;
	::Parser::bool_t success_3 = false;
	::Parser::bool_t success_36 = false;
	::Parser::arr_t<::Parser::Rule> shadow_30;
	::Parser::Rule _4;
	::Parser::bool_t success_5 = false;
	::Parser::arr_t<::Parser::Rule> _6;
	::Parser::bool_t success_7 = false;
	::Parser::Rule_res _8;
	::Parser::bool_t success_9 = false;
	::Parser::arr_t<::Parser::Rule> shadow_10;
	::Parser::Rule_res _11;
	::Parser::bool_t success_12 = false;
	::Parser::arr_t<::Parser::Rule> shadow_13;
	::Parser::Rule_res _14;
	::Parser::bool_t success_15 = false;
	::Parser::arr_t<::Parser::Rule> shadow_16;
	::Parser::Rule_res _17;
	::Parser::bool_t success_18 = false;
	::Parser::arr_t<::Parser::Rule> shadow_19;
	::Parser::Rule_res _20;
	::Parser::bool_t success_21 = false;
	::Parser::arr_t<::Parser::Rule> shadow_22;
	::Parser::Rule_res _23;
	::Parser::bool_t success_24 = false;
	::Parser::arr_t<::Parser::Rule> shadow_25;
	::Parser::Rule_res _26;
	::Parser::bool_t success_27 = false;
	::Parser::arr_t<::Parser::Rule> shadow_28;
	::Parser::Token _31;
	::Parser::bool_t success_32 = false;
	::Parser::arr_t<::Parser::Token> shadow_33;
	if (!(pos->name == Tokens::AUTO_4))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos += 2;
	ISC_STD::skip_spaces(pos);
	auto begin_34 = pos;
	while (1)
	{
		auto begin_29 = begin_34;
		while (1)
		{
			_8 = cll_var(begin_29);
			if (!(_8.result))
			{
				_11 = cll_if(begin_29);
				if (!(_11.result))
				{
					_14 = expr(begin_29);
					if (!(_14.result))
					{
						_17 = copiable_method_call(begin_29);
						if (!(_17.result))
						{
							_20 = method_call(begin_29);
							if (!(_20.result))
							{
								_23 = loop_while(begin_29);
								if (!(_23.result))
								{
									_26 = loop_for(begin_29);
									if (!(_26.result))
									{
										break;
									}
									else 
									{
										success_27 = true;
										shadow_28.push_back(_26.token);
										_6 = shadow_28;
									}
								}
								else 
								{
									success_24 = true;
									shadow_25.push_back(_23.token);
									_6 = shadow_25;
								}
							}
							else 
							{
								success_21 = true;
								shadow_22.push_back(_20.token);
								_6 = shadow_22;
							}
						}
						else 
						{
							success_18 = true;
							shadow_19.push_back(_17.token);
							_6 = shadow_19;
						}
					}
					else 
					{
						success_15 = true;
						shadow_16.push_back(_14.token);
						_6 = shadow_16;
					}
				}
				else 
				{
					success_12 = true;
					shadow_13.push_back(_11.token);
					_6 = shadow_13;
				}
			}
			else 
			{
				success_9 = true;
				shadow_10.push_back(_8.token);
				_6 = shadow_10;
			}
			success_7 = true;
			begin_29 += 1;
			shadow_30.push_back(_4);
		}
		if (success_7)
		{
			success_5 = true;
			begin_34 = begin_29;
		}
		_4 = _6;
		ISC_STD::skip_spaces(pos);
		if (!(begin_34->name == Tokens::END))
		{
			break;
		}
		_31 = *begin_34;
		success_32 = true;
		begin_34 += 2;
		shadow_33.push_back(_31);
		shadow_35.push_back(_2);
		success_36 = true;
	}
	if (!success_36)
	{
		return {};
	}
	if (success_32)
	{
		success_3 = true;
		pos = begin_34;
	}
	cll_data data = shadow_30;
	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::cll, data)};
}
Parser::Rule_res Parser::Parser::cll_block(Token*& pos) {
	auto in = pos;
	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	::Parser::Rule_res _2;
	::Parser::bool_t success_3 = false;
	::Parser::Token _4;
	::Parser::bool_t success_5 = false;
	if (!(pos->name == Tokens::AUTO_63))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos += 2;
	ISC_STD::skip_spaces(pos);
	_2 = Rule_rule(pos);
	while (_2.result)
	{
		success_3 = true;
		pos += 1;
		_2 = Rule_rule(pos);
	}
	ISC_STD::skip_spaces(pos);
	if (!(pos->name == Tokens::AUTO_68))
	{
		return {};
	}
	_4 = *pos;
	success_5 = true;
	pos += 2;
	cll_block_data data = _2.token;
	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::cll_block, data)};
}
Parser::Rule_res Parser::Parser::cll_spaced_block(Token*& pos) {
	auto in = pos;
	::Parser::Rule_res _0;
	::Parser::bool_t success_1 = false;
	::Parser::arr_t<::Parser::Rule> shadow_2;
	while ((skipup(" ")>spaces_amount))
	{
		_0 = Rule_rule(pos);
		if (!(_0.result))
		{
			return {};
		}
		success_1 = true;
		pos += 1;
		shadow_2.push_back(_0.token);
		ISC_STD::skip_spaces(pos);
	}
	cll_spaced_block_data data = shadow_2;
	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::cll_spaced_block, data)};
}
Parser::Token_res Parser::Tokenizator::OP(const char* &pos) {
	auto in = pos;
	::Parser::any_t _0;
	::Parser::bool_t success_1 = false;
	::Parser::str_t _2;
	::Parser::bool_t success_3 = false;
	::Parser::str_t _4;
	::Parser::bool_t success_5 = false;
	::Parser::str_t _6;
	::Parser::bool_t success_7 = false;
	::Parser::str_t _8;
	::Parser::bool_t success_9 = false;
	::Parser::str_t _10;
	::Parser::bool_t success_11 = false;
	::Parser::str_t _12;
	::Parser::bool_t success_13 = false;
	::Parser::str_t _14;
	::Parser::bool_t success_15 = false;
	::Parser::str_t _16;
	::Parser::bool_t success_17 = false;
	::Parser::str_t _18;
	::Parser::bool_t success_19 = false;
	::Parser::str_t _20;
	::Parser::bool_t success_21 = false;
	::Parser::str_t _22;
	::Parser::bool_t success_23 = false;
	if (!(*(pos + 0) == '+'))
	{
		if (!(*(pos + 1) == '-'))
		{
			if (!(*(pos + 2) == '*'))
			{
				if (!(*(pos + 3) == '/'))
				{
					if (!(*(pos + 4) == '%'))
					{
					}
					else 
					{
						_10 += ::Parser::str_t(pos, 5);
						success_11 = true;
						_0 = _10;
					}
				}
				else 
				{
					_8 += ::Parser::str_t(pos, 5);
					success_9 = true;
					_0 = _8;
				}
			}
			else 
			{
				_6 += ::Parser::str_t(pos, 5);
				success_7 = true;
				_0 = _6;
			}
		}
		else 
		{
			_4 += ::Parser::str_t(pos, 5);
			success_5 = true;
			_0 = _4;
		}
	}
	else 
	{
		_2 += ::Parser::str_t(pos, 5);
		success_3 = true;
		_0 = _2;
	}
	success_1 = true;
	pos += 6;
	ISC_STD::skip_spaces(pos);
	if (!(*(pos + 0) == '&'))
	{
		if (!(*(pos + 1) == '|'))
		{
			if (!(*(pos + 2) == '^'))
			{
				if (!(!std::strncmp(pos, "<<", 2)))
				{
					if (!(!std::strncmp(pos, ">>", 2)))
					{
						return {};
					}
					else 
					{
						_22 += ::Parser::str_t(pos, 7);
						success_23 = true;
						_12 = _22;
					}
				}
				else 
				{
					_20 += ::Parser::str_t(pos, 7);
					success_21 = true;
					_12 = _20;
				}
			}
			else 
			{
				_18 += ::Parser::str_t(pos, 7);
				success_19 = true;
				_12 = _18;
			}
		}
		else 
		{
			_16 += ::Parser::str_t(pos, 7);
			success_17 = true;
			_12 = _16;
		}
	}
	else 
	{
		_14 += ::Parser::str_t(pos, 7);
		success_15 = true;
		_12 = _14;
	}
	success_13 = true;
	pos += 8;
	OP_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::OP, data)};
}
Parser::Token_res Parser::Tokenizator::ASSIGNMENT_OP(const char* &pos) {
	auto in = pos;
	::Parser::Token_res _0;
	::Parser::bool_t success_1 = false;
	::Parser::Token_res _2;
	::Parser::bool_t success_3 = false;
	_0 = OP(pos);
	if (_0.result)
	{
		success_1 = true;
		pos += 1;
	}
	ISC_STD::skip_spaces(pos);
	_2 = AUTO_53(pos);
	if (!(_2.result))
	{
		return {};
	}
	success_3 = true;
	pos += 1;
	ASSIGNMENT_OP_data data = _0.token;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::ASSIGNMENT_OP, data)};
}
Parser::Token_res Parser::Tokenizator::COMPARE_OP(const char* &pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	::Parser::str_t _2;
	::Parser::bool_t success_3 = false;
	::Parser::str_t _4;
	::Parser::bool_t success_5 = false;
	::Parser::str_t _6;
	::Parser::bool_t success_7 = false;
	::Parser::str_t _8;
	::Parser::bool_t success_9 = false;
	::Parser::str_t _10;
	::Parser::bool_t success_11 = false;
	::Parser::str_t _12;
	::Parser::bool_t success_13 = false;
	if (!(!std::strncmp(pos, "==", 2)))
	{
		if (!(!std::strncmp(pos, "!=", 2)))
		{
			if (!(*(pos + 4) == '>'))
			{
				if (!(*(pos + 5) == '<'))
				{
					if (!(!std::strncmp(pos, ">=", 2)))
					{
						if (!(!std::strncmp(pos, "<=", 2)))
						{
							return {};
						}
						else 
						{
							_12 += ::Parser::str_t(pos, 10);
							success_13 = true;
							_0 = _12;
						}
					}
					else 
					{
						_10 += ::Parser::str_t(pos, 10);
						success_11 = true;
						_0 = _10;
					}
				}
				else 
				{
					_8 += ::Parser::str_t(pos, 10);
					success_9 = true;
					_0 = _8;
				}
			}
			else 
			{
				_6 += ::Parser::str_t(pos, 10);
				success_7 = true;
				_0 = _6;
			}
		}
		else 
		{
			_4 += ::Parser::str_t(pos, 10);
			success_5 = true;
			_0 = _4;
		}
	}
	else 
	{
		_2 += ::Parser::str_t(pos, 10);
		success_3 = true;
		_0 = _2;
	}
	success_1 = true;
	pos += 11;
	COMPARE_OP_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::COMPARE_OP, data)};
}
Parser::Token_res Parser::Tokenizator::LOGICAL_OP(const char* &pos) {
	auto in = pos;
	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	::Parser::Token_res _2;
	::Parser::bool_t success_3 = false;
	::Parser::Token_res _4;
	::Parser::bool_t success_5 = false;
	_2 = LOGICAL_AND(pos);
	if (!(_2.result))
	{
		_4 = LOGICAL_OR(pos);
		if (!(_4.result))
		{
			return {};
		}
		else 
		{
			success_5 = true;
			_0 = _4.token;
		}
	}
	else 
	{
		success_3 = true;
		_0 = _2.token;
	}
	success_1 = true;
	pos += 1;
	LOGICAL_OP_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::LOGICAL_OP, data)};
}
Parser::Token_res Parser::Tokenizator::LOGICAL_NOT(const char* &pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	::Parser::str_t _2;
	::Parser::bool_t success_3 = false;
	::Parser::str_t _4;
	::Parser::bool_t success_5 = false;
	if (!(*(pos + 0) == '!'))
	{
		if (!(!std::strncmp(pos, "not", 3)))
		{
			return {};
		}
		else 
		{
			_4 += ::Parser::str_t(pos, 4);
			success_5 = true;
			_0 = _4;
		}
	}
	else 
	{
		_2 += ::Parser::str_t(pos, 4);
		success_3 = true;
		_0 = _2;
	}
	success_1 = true;
	pos += 5;
	LOGICAL_NOT_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::LOGICAL_NOT, data)};
}
Parser::Token_res Parser::Tokenizator::LOGICAL_AND(const char* &pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	::Parser::str_t _2;
	::Parser::bool_t success_3 = false;
	::Parser::str_t _4;
	::Parser::bool_t success_5 = false;
	if (!(!std::strncmp(pos, "&&", 2)))
	{
		if (!(!std::strncmp(pos, "and", 3)))
		{
			return {};
		}
		else 
		{
			_4 += ::Parser::str_t(pos, 5);
			success_5 = true;
			_0 = _4;
		}
	}
	else 
	{
		_2 += ::Parser::str_t(pos, 5);
		success_3 = true;
		_0 = _2;
	}
	success_1 = true;
	pos += 6;
	LOGICAL_AND_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::LOGICAL_AND, data)};
}
Parser::Token_res Parser::Tokenizator::LOGICAL_OR(const char* &pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	::Parser::str_t _2;
	::Parser::bool_t success_3 = false;
	::Parser::str_t _4;
	::Parser::bool_t success_5 = false;
	if (!(!std::strncmp(pos, "||", 2)))
	{
		if (!(!std::strncmp(pos, "or", 2)))
		{
			return {};
		}
		else 
		{
			_4 += ::Parser::str_t(pos, 4);
			success_5 = true;
			_0 = _4;
		}
	}
	else 
	{
		_2 += ::Parser::str_t(pos, 4);
		success_3 = true;
		_0 = _2;
	}
	success_1 = true;
	pos += 5;
	LOGICAL_OR_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::LOGICAL_OR, data)};
}
Parser::Token_res Parser::Tokenizator::LOGICAL_ANDR(const char* &pos) {
	auto in = pos;
	::Parser::any_t _0;
	::Parser::bool_t success_1 = false;
	::Parser::str_t _2;
	::Parser::bool_t success_3 = false;
	::Parser::bool_t success_5 = false;
	::Parser::str_t _6;
	::Parser::bool_t success_7 = false;
	::Parser::arr_t<::Parser::str_t> shadow_10;
	::Parser::str_t _8;
	::Parser::bool_t success_9 = false;
	::Parser::str_t _11;
	::Parser::bool_t success_12 = false;
	if (!(!std::strncmp(pos, "|&", 2)))
	{
		auto begin_13 = pos;
		do
		{
			if (!(!std::strncmp(pos, "and", 3)))
			{
				break;
			}
			_6 += ::Parser::str_t(begin_13, 5);
			success_7 = true;
			begin_13 += 6;
			if (*(pos + 0) != ' ')
			{
				break;
				shadow_10.push_back(_8);
			}
			_8 += ::Parser::str_t(begin_13, 1);
			success_9 = true;
			begin_13 += 2;
			if (!(!std::strncmp(pos, "or", 2)))
			{
				break;
			}
			_11 += ::Parser::str_t(begin_13, 2);
			success_12 = true;
			begin_13 += 3;
		}		while(0)
;
		if (success_12)
		{
			success_5 = true;
			pos = begin_13;
		}
		if (!success_5)
		{
			return {};
		}
		else 
		{
			_0 = _4;
		}
	}
	else 
	{
		_2 += ::Parser::str_t(pos, 0);
		success_3 = true;
		_0 = _2;
	}
	success_1 = true;
	pos += 1;
	LOGICAL_ANDR_data data = _6;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::LOGICAL_ANDR, data)};
}
Parser::Rule_res Parser::Parser::cll_template_content_typename(Token*& pos) {
	auto in = pos;
	::Parser::Rule_res _0;
	::Parser::bool_t success_1 = false;
	::Parser::arr_t<::Parser::UNDEF> shadow_11;
	::Parser::bool_t success_3 = false;
	::Parser::Token _4;
	::Parser::bool_t success_5 = false;
	::Parser::arr_t<::Parser::Token> shadow_6;
	::Parser::Rule_res _7;
	::Parser::bool_t success_8 = false;
	::Parser::arr_t<::Parser::Rule> shadow_9;
	_0 = cll_type(pos);
	if (!(_0.result))
	{
		return {};
	}
	success_1 = true;
	pos += 1;
	ISC_STD::skip_spaces(pos);
	auto begin_10 = pos;
	while (1)
	{
		if (!(begin_10->name == Tokens::AUTO_76))
		{
			break;
		}
		_4 = *begin_10;
		success_5 = true;
		begin_10 += 2;
		shadow_6.push_back(_4);
		ISC_STD::skip_spaces(pos);
		_7 = cll_type(begin_10);
		if (!(_7.result))
		{
			break;
		}
		success_8 = true;
		begin_10 += 1;
		shadow_9.push_back(_7.token);
		shadow_11.push_back(_2);
	}
	if (success_8)
	{
		success_3 = true;
		pos = begin_10;
	}
	cll_template_content_typename_data data = {,};
	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::cll_template_content_typename, data)};
}
Parser::Rule_res Parser::Parser::cll_template_content_int(Token*& pos) {
	auto in = pos;
	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	::Parser::arr_t<::Parser::UNDEF> shadow_11;
	::Parser::bool_t success_3 = false;
	::Parser::Token _4;
	::Parser::bool_t success_5 = false;
	::Parser::arr_t<::Parser::Token> shadow_6;
	::Parser::Token _7;
	::Parser::bool_t success_8 = false;
	::Parser::arr_t<::Parser::Token> shadow_9;
	if (!(pos->name == Tokens::NUMBER))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos += 2;
	ISC_STD::skip_spaces(pos);
	auto begin_10 = pos;
	while (1)
	{
		if (!(begin_10->name == Tokens::AUTO_76))
		{
			break;
		}
		_4 = *begin_10;
		success_5 = true;
		begin_10 += 2;
		shadow_6.push_back(_4);
		ISC_STD::skip_spaces(pos);
		if (!(begin_10->name == Tokens::NUMBER))
		{
			break;
		}
		_7 = *begin_10;
		success_8 = true;
		begin_10 += 2;
		shadow_9.push_back(_7);
		shadow_11.push_back(_2);
	}
	if (success_8)
	{
		success_3 = true;
		pos = begin_10;
	}
	cll_template_content_int_data data = {,};
	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::cll_template_content_int, data)};
}
Parser::Rule_res Parser::Parser::cll_template_content_bool(Token*& pos) {
	auto in = pos;
	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	::Parser::arr_t<::Parser::UNDEF> shadow_11;
	::Parser::bool_t success_3 = false;
	::Parser::Token _4;
	::Parser::bool_t success_5 = false;
	::Parser::arr_t<::Parser::Token> shadow_6;
	::Parser::Token _7;
	::Parser::bool_t success_8 = false;
	::Parser::arr_t<::Parser::Token> shadow_9;
	if (!(pos->name == Tokens::BOOLEAN))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos += 2;
	ISC_STD::skip_spaces(pos);
	auto begin_10 = pos;
	while (1)
	{
		if (!(begin_10->name == Tokens::AUTO_76))
		{
			break;
		}
		_4 = *begin_10;
		success_5 = true;
		begin_10 += 2;
		shadow_6.push_back(_4);
		ISC_STD::skip_spaces(pos);
		if (!(begin_10->name == Tokens::BOOLEAN))
		{
			break;
		}
		_7 = *begin_10;
		success_8 = true;
		begin_10 += 2;
		shadow_9.push_back(_7);
		shadow_11.push_back(_2);
	}
	if (success_8)
	{
		success_3 = true;
		pos = begin_10;
	}
	cll_template_content_bool_data data = {,};
	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::cll_template_content_bool, data)};
}
Parser::Rule_res Parser::Parser::cll_template_content_str(Token*& pos) {
	auto in = pos;
	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	::Parser::arr_t<::Parser::UNDEF> shadow_11;
	::Parser::bool_t success_3 = false;
	::Parser::Token _4;
	::Parser::bool_t success_5 = false;
	::Parser::arr_t<::Parser::Token> shadow_6;
	::Parser::Token _7;
	::Parser::bool_t success_8 = false;
	::Parser::arr_t<::Parser::Token> shadow_9;
	if (!(pos->name == Tokens::STRING))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos += 2;
	ISC_STD::skip_spaces(pos);
	auto begin_10 = pos;
	while (1)
	{
		if (!(begin_10->name == Tokens::AUTO_76))
		{
			break;
		}
		_4 = *begin_10;
		success_5 = true;
		begin_10 += 2;
		shadow_6.push_back(_4);
		ISC_STD::skip_spaces(pos);
		if (!(begin_10->name == Tokens::STRING))
		{
			break;
		}
		_7 = *begin_10;
		success_8 = true;
		begin_10 += 2;
		shadow_9.push_back(_7);
		shadow_11.push_back(_2);
	}
	if (success_8)
	{
		success_3 = true;
		pos = begin_10;
	}
	cll_template_content_str_data data = {,};
	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::cll_template_content_str, data)};
}
Parser::Rule_res Parser::Parser::cll_template_content_arr(Token*& pos) {
	auto in = pos;
	::Parser::Rule_res _0;
	::Parser::bool_t success_1 = false;
	::Parser::arr_t<::Parser::UNDEF> shadow_11;
	::Parser::bool_t success_3 = false;
	::Parser::Token _4;
	::Parser::bool_t success_5 = false;
	::Parser::arr_t<::Parser::Token> shadow_6;
	::Parser::Rule_res _7;
	::Parser::bool_t success_8 = false;
	::Parser::arr_t<::Parser::Rule> shadow_9;
	_0 = array(pos);
	if (!(_0.result))
	{
		return {};
	}
	success_1 = true;
	pos += 1;
	ISC_STD::skip_spaces(pos);
	auto begin_10 = pos;
	while (1)
	{
		if (!(begin_10->name == Tokens::AUTO_76))
		{
			break;
		}
		_4 = *begin_10;
		success_5 = true;
		begin_10 += 2;
		shadow_6.push_back(_4);
		ISC_STD::skip_spaces(pos);
		_7 = array(begin_10);
		if (!(_7.result))
		{
			break;
		}
		success_8 = true;
		begin_10 += 1;
		shadow_9.push_back(_7.token);
		shadow_11.push_back(_2);
	}
	if (success_8)
	{
		success_3 = true;
		pos = begin_10;
	}
	cll_template_content_arr_data data = {,};
	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::cll_template_content_arr, data)};
}
Parser::Rule_res Parser::Parser::cll_template_content_obj(Token*& pos) {
	auto in = pos;
	::Parser::Rule_res _0;
	::Parser::bool_t success_1 = false;
	::Parser::arr_t<::Parser::UNDEF> shadow_11;
	::Parser::bool_t success_3 = false;
	::Parser::Token _4;
	::Parser::bool_t success_5 = false;
	::Parser::arr_t<::Parser::Token> shadow_6;
	::Parser::Rule_res _7;
	::Parser::bool_t success_8 = false;
	::Parser::arr_t<::Parser::Rule> shadow_9;
	_0 = object(pos);
	if (!(_0.result))
	{
		return {};
	}
	success_1 = true;
	pos += 1;
	ISC_STD::skip_spaces(pos);
	auto begin_10 = pos;
	while (1)
	{
		if (!(begin_10->name == Tokens::AUTO_76))
		{
			break;
		}
		_4 = *begin_10;
		success_5 = true;
		begin_10 += 2;
		shadow_6.push_back(_4);
		ISC_STD::skip_spaces(pos);
		_7 = object(begin_10);
		if (!(_7.result))
		{
			break;
		}
		success_8 = true;
		begin_10 += 1;
		shadow_9.push_back(_7.token);
		shadow_11.push_back(_2);
	}
	if (success_8)
	{
		success_3 = true;
		pos = begin_10;
	}
	cll_template_content_obj_data data = {,};
	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::cll_template_content_obj, data)};
}
Parser::Rule_res Parser::Parser::cll_template_content_any_data(Token*& pos) {
	auto in = pos;
	::Parser::Rule_res _0;
	::Parser::bool_t success_1 = false;
	::Parser::arr_t<::Parser::UNDEF> shadow_11;
	::Parser::bool_t success_3 = false;
	::Parser::Token _4;
	::Parser::bool_t success_5 = false;
	::Parser::arr_t<::Parser::Token> shadow_6;
	::Parser::Rule_res _7;
	::Parser::bool_t success_8 = false;
	::Parser::arr_t<::Parser::Rule> shadow_9;
	_0 = any_data(pos);
	if (!(_0.result))
	{
		return {};
	}
	success_1 = true;
	pos += 1;
	ISC_STD::skip_spaces(pos);
	auto begin_10 = pos;
	while (1)
	{
		if (!(begin_10->name == Tokens::AUTO_76))
		{
			break;
		}
		_4 = *begin_10;
		success_5 = true;
		begin_10 += 2;
		shadow_6.push_back(_4);
		ISC_STD::skip_spaces(pos);
		_7 = any_data(begin_10);
		if (!(_7.result))
		{
			break;
		}
		success_8 = true;
		begin_10 += 1;
		shadow_9.push_back(_7.token);
		shadow_11.push_back(_2);
	}
	if (success_8)
	{
		success_3 = true;
		pos = begin_10;
	}
	cll_template_content_any_data_data data = {,};
	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::cll_template_content_any_data, data)};
}
Parser::Rule_res Parser::Parser::cll_csupport_types(Token*& pos) {
	auto in = pos;
	::Parser::bool_t is_unsigned = matched();
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	::Parser::bool_t success_3 = false;
	::Parser::Token _4;
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
	::Parser::Token _16;
	::Parser::bool_t success_17 = false;
	::Parser::Token _18;
	::Parser::bool_t success_19 = false;
	::Parser::Token _22;
	::Parser::bool_t success_23 = false;
	::Parser::Token _24;
	::Parser::bool_t success_25 = false;
	::Parser::Token _26;
	::Parser::bool_t success_27 = false;
	::Parser::Token _28;
	::Parser::bool_t success_29 = false;
	::Parser::Token _31;
	::Parser::bool_t success_32 = false;
	::Parser::Token _33;
	::Parser::bool_t success_34 = false;
	::Parser::Token _35;
	::Parser::bool_t success_36 = false;
	::Parser::Token _37;
	::Parser::bool_t success_38 = false;
	::Parser::Token _39;
	::Parser::bool_t success_40 = false;
	::Parser::Token _41;
	::Parser::bool_t success_42 = false;
	::Parser::Token _43;
	::Parser::bool_t success_44 = false;
	::Parser::Token _45;
	::Parser::bool_t success_46 = false;
	::Parser::Rule_res _48;
	::Parser::bool_t success_49 = false;
	auto begin_21 = pos;
	do
	{
		if (begin_21->name == Tokens::AUTO_14)
		{
			_4 = *begin_21;
			success_5 = true;
			begin_21 += 2;
		}
		ISC_STD::skip_spaces(pos);
		auto begin_20 = begin_21;
		if (!(begin_20->name == Tokens::AUTO_15))
		{
			if (!(begin_20->name == Tokens::AUTO_16))
			{
				if (!(begin_20->name == Tokens::AUTO_17))
				{
					if (!(begin_20->name == Tokens::AUTO_18))
					{
						if (!(begin_20->name == Tokens::AUTO_19))
						{
							break;
						}
						else 
						{
							_18 = *begin_20;
							success_19 = true;
							_8 = _18;
						}
					}
					else 
					{
						_16 = *begin_20;
						success_17 = true;
						_8 = _16;
					}
				}
				else 
				{
					_14 = *begin_20;
					success_15 = true;
					_8 = _14;
				}
			}
			else 
			{
				_12 = *begin_20;
				success_13 = true;
				_8 = _12;
			}
		}
		else 
		{
			_10 = *begin_20;
			success_11 = true;
			_8 = _10;
		}
		success_9 = true;
		begin_20 += 6;
		if (success_9)
		{
			success_7 = true;
			begin_21 = begin_20;
		}
		_6 = _8;
	}	while(0)
;
	if (success_7)
	{
		success_3 = true;
		pos = begin_21;
	}
	if (!success_3)
	{
		auto begin_30 = pos;
		do
		{
			if (!(begin_30->name == Tokens::AUTO_20))
			{
				if (!(begin_30->name == Tokens::AUTO_21))
				{
					break;
				}
				else 
				{
					_28 = *begin_30;
					success_29 = true;
					_24 = _28;
				}
			}
			else 
			{
				_26 = *begin_30;
				success_27 = true;
				_24 = _26;
			}
			success_25 = true;
			begin_30 += 3;
		}		while(0)
;
		if (success_25)
		{
			success_23 = true;
			pos = begin_30;
		}
		_22 = _24;
		if (!success_23)
		{
			auto begin_47 = pos;
			do
			{
				if (!(begin_47->name == Tokens::AUTO_22))
				{
					if (!(begin_47->name == Tokens::AUTO_23))
					{
						if (!(begin_47->name == Tokens::AUTO_24))
						{
							if (!(begin_47->name == Tokens::AUTO_25))
							{
								if (!(begin_47->name == Tokens::AUTO_26))
								{
									if (!(begin_47->name == Tokens::AUTO_27))
									{
										break;
									}
									else 
									{
										_45 = *begin_47;
										success_46 = true;
										_33 = _45;
									}
								}
								else 
								{
									_43 = *begin_47;
									success_44 = true;
									_33 = _43;
								}
							}
							else 
							{
								_41 = *begin_47;
								success_42 = true;
								_33 = _41;
							}
						}
						else 
						{
							_39 = *begin_47;
							success_40 = true;
							_33 = _39;
						}
					}
					else 
					{
						_37 = *begin_47;
						success_38 = true;
						_33 = _37;
					}
				}
				else 
				{
					_35 = *begin_47;
					success_36 = true;
					_33 = _35;
				}
				success_34 = true;
				begin_47 += 7;
			}			while(0)
;
			if (success_34)
			{
				success_32 = true;
				pos = begin_47;
			}
			_31 = _33;
			if (!success_32)
			{
				return {};
			}
			else 
			{
				_0 = _31;
			}
		}
		else 
		{
			_0 = _22;
		}
	}
	else 
	{
		_0 = _2;
	}
	success_1 = true;
	pos += 1;
	ISC_STD::skip_spaces(pos);
	_48 = cll_template_typename(pos);
	if (!(_48.result))
	{
		return {};
	}
	success_49 = true;
	pos += 1;
	cll_csupport_types_data data;
	data.template = _8;
	data.type = _4;

	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::cll_csupport_types, data)};
}
Parser::Rule_res Parser::Parser::cll_type_abstract(Token*& pos) {
	auto in = pos;
	::Parser::any_t _0;
	::Parser::bool_t success_1 = false;
	::Parser::any_t _2;
	::Parser::bool_t success_3 = false;
	::Parser::Token _4;
	::Parser::bool_t success_5 = false;
	::Parser::Token _6;
	::Parser::bool_t success_7 = false;
	::Parser::Token _8;
	::Parser::bool_t success_9 = false;
	::Parser::Token _10;
	::Parser::bool_t success_11 = false;
	::Parser::Token _12;
	::Parser::bool_t success_13 = false;
	::Parser::bool_t success_15 = false;
	::Parser::Token _16;
	::Parser::bool_t success_17 = false;
	::Parser::Rule_res _18;
	::Parser::bool_t success_19 = false;
	::Parser::bool_t success_22 = false;
	::Parser::Token _23;
	::Parser::bool_t success_24 = false;
	::Parser::Rule_res _25;
	::Parser::bool_t success_26 = false;
	auto begin_28 = pos;
	if (!(begin_28->name == Tokens::AUTO_28))
	{
		if (!(begin_28->name == Tokens::AUTO_29))
		{
			if (!(begin_28->name == Tokens::AUTO_30))
			{
				if (!(begin_28->name == Tokens::AUTO_31))
				{
					if (!(begin_28->name == Tokens::AUTO_32))
					{
						auto begin_20 = begin_28;
						do
						{
							if (!(begin_20->name == Tokens::AUTO_33))
							{
								break;
							}
							_16 = *begin_20;
							success_17 = true;
							begin_20 += 7;
							ISC_STD::skip_spaces(pos);
							_18 = cll_template_typename(begin_20);
							if (!(_18.result))
							{
								break;
							}
							success_19 = true;
							begin_20 += 1;
						}						while(0)
;
						if (success_19)
						{
							success_15 = true;
							begin_28 = begin_20;
						}
						if (!success_15)
						{
							auto begin_27 = begin_28;
							do
							{
								if (!(begin_27->name == Tokens::AUTO_34))
								{
									break;
								}
								_23 = *begin_27;
								success_24 = true;
								begin_27 += 2;
								ISC_STD::skip_spaces(pos);
								_25 = cll_template_typename(begin_27);
								if (!(_25.result))
								{
									break;
								}
								success_26 = true;
								begin_27 += 1;
							}							while(0)
;
							if (success_26)
							{
								success_22 = true;
								begin_28 = begin_27;
							}
							if (!success_22)
							{
								return {};
							}
							else 
							{
								_2 = _21;
							}
						}
						else 
						{
							_2 = _14;
						}
					}
					else 
					{
						_12 = *begin_28;
						success_13 = true;
						_2 = _12;
					}
				}
				else 
				{
					_10 = *begin_28;
					success_11 = true;
					_2 = _10;
				}
			}
			else 
			{
				_8 = *begin_28;
				success_9 = true;
				_2 = _8;
			}
		}
		else 
		{
			_6 = *begin_28;
			success_7 = true;
			_2 = _6;
		}
	}
	else 
	{
		_4 = *begin_28;
		success_5 = true;
		_2 = _4;
	}
	success_3 = true;
	begin_28 += 1;
	if (success_3)
	{
		success_1 = true;
		pos = begin_28;
	}
	cll_type_abstract_data data;
	data.template = _23;
	data.type = _16;

	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::cll_type_abstract, data)};
}
Parser::Rule_res Parser::Parser::cll_type(Token*& pos) {
	auto in = pos;
	::Parser::Rule _0;
	::Parser::bool_t success_1 = false;
	::Parser::Rule_res _2;
	::Parser::bool_t success_3 = false;
	::Parser::Rule_res _4;
	::Parser::bool_t success_5 = false;
	_2 = cll_csupport_types(pos);
	if (!(_2.result))
	{
		_4 = cll_type_abstract(pos);
		if (!(_4.result))
		{
			return {};
		}
		else 
		{
			success_5 = true;
			_0 = _4.token;
		}
	}
	else 
	{
		success_3 = true;
		_0 = _2.token;
	}
	success_1 = true;
	pos += 1;
	cll_type_data data = _0;
	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::cll_type, data)};
}
Parser::Rule_res Parser::Parser::cll_if(Token*& pos) {
	auto in = pos;
	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	::Parser::Rule_res _2;
	::Parser::bool_t success_3 = false;
	::Parser::Rule_res _4;
	::Parser::bool_t success_5 = false;
	if (!(pos->name == Tokens::AUTO_35))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos += 2;
	ISC_STD::skip_spaces(pos);
	_2 = expr(pos);
	if (!(_2.result))
	{
		return {};
	}
	success_3 = true;
	pos += 1;
	ISC_STD::skip_spaces(pos);
	_4 = cll_block(pos);
	if (!(_4.result))
	{
		return {};
	}
	success_5 = true;
	pos += 1;
	cll_if_data data;
	data.block = _4.token;
	data.expr = _2.token;

	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::cll_if, data)};
}
Parser::Rule_res Parser::Parser::cll_ternary(Token*& pos) {
	auto in = pos;
	::Parser::Rule_res _0;
	::Parser::bool_t success_1 = false;
	::Parser::Token _2;
	::Parser::bool_t success_3 = false;
	::Parser::Rule_res _4;
	::Parser::bool_t success_5 = false;
	::Parser::Token _6;
	::Parser::bool_t success_7 = false;
	::Parser::Rule_res _8;
	::Parser::bool_t success_9 = false;
	_0 = expr(pos);
	if (!(_0.result))
	{
		return {};
	}
	success_1 = true;
	pos += 1;
	ISC_STD::skip_spaces(pos);
	if (!(pos->name == Tokens::AUTO_82))
	{
		return {};
	}
	_2 = *pos;
	success_3 = true;
	pos += 2;
	ISC_STD::skip_spaces(pos);
	_4 = expr(pos);
	if (!(_4.result))
	{
		return {};
	}
	success_5 = true;
	pos += 1;
	ISC_STD::skip_spaces(pos);
	if (!(pos->name == Tokens::AUTO_103))
	{
		return {};
	}
	_6 = *pos;
	success_7 = true;
	pos += 2;
	ISC_STD::skip_spaces(pos);
	_8 = expr(pos);
	if (!(_8.result))
	{
		return {};
	}
	success_9 = true;
	pos += 1;
	cll_ternary_data data;
	data.second = _8.token;
	data.first = _4.token;
	data.cond = _0.token;

	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::cll_ternary, data)};
}
Parser::Rule_res Parser::Parser::expr_logical(Token*& pos) {
	auto in = pos;
	::Parser::Rule _0;
	::Parser::bool_t success_1 = false;
	::Parser::Rule_res _2;
	::Parser::bool_t success_3 = false;
	::Parser::Rule_res _4;
	::Parser::bool_t success_5 = false;
	::Parser::Rule_res _6;
	::Parser::bool_t success_7 = false;
	::Parser::Token _8;
	::Parser::bool_t success_9 = false;
	::Parser::Rule _10;
	::Parser::bool_t success_11 = false;
	::Parser::Rule_res _12;
	::Parser::bool_t success_13 = false;
	::Parser::Rule_res _14;
	::Parser::bool_t success_15 = false;
	::Parser::Rule_res _16;
	::Parser::bool_t success_17 = false;
	_2 = expr_compare(pos);
	if (!(_2.result))
	{
		_4 = expr_arithmetic(pos);
		if (!(_4.result))
		{
			_6 = expr_for_arithmetic(pos);
			if (!(_6.result))
			{
				return {};
			}
			else 
			{
				success_7 = true;
				_0 = _6.token;
			}
		}
		else 
		{
			success_5 = true;
			_0 = _4.token;
		}
	}
	else 
	{
		success_3 = true;
		_0 = _2.token;
	}
	success_1 = true;
	pos += 1;
	ISC_STD::skip_spaces(pos);
	if (!(pos->name == Tokens::LOGICAL_OP))
	{
		return {};
	}
	_8 = *pos;
	success_9 = true;
	pos += 2;
	ISC_STD::skip_spaces(pos);
	_12 = expr_compare(pos);
	if (!(_12.result))
	{
		_14 = expr_arithmetic(pos);
		if (!(_14.result))
		{
			_16 = expr_for_arithmetic(pos);
			if (!(_16.result))
			{
				return {};
			}
			else 
			{
				success_17 = true;
				_10 = _16.token;
			}
		}
		else 
		{
			success_15 = true;
			_10 = _14.token;
		}
	}
	else 
	{
		success_13 = true;
		_10 = _12.token;
	}
	success_11 = true;
	pos += 1;
	expr_logical_data data;
	data.right = _10;
	data.op = _8;
	data.left = _0;

	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::expr_logical, data)};
}
Parser::Rule_res Parser::Parser::expr_compare(Token*& pos) {
	auto in = pos;
	::Parser::Rule_res _0;
	::Parser::bool_t success_1 = false;
	::Parser::arr_t<::Parser::UNDEF> shadow_11;
	::Parser::bool_t success_3 = false;
	::Parser::bool_t success_12 = false;
	::Parser::Token _4;
	::Parser::bool_t success_5 = false;
	::Parser::arr_t<::Parser::Token> shadow_6;
	::Parser::Rule_res _7;
	::Parser::bool_t success_8 = false;
	::Parser::arr_t<::Parser::Rule> shadow_9;
	_0 = expr_arithmetic(pos);
	if (!(_0.result))
	{
		return {};
	}
	success_1 = true;
	pos += 1;
	ISC_STD::skip_spaces(pos);
	auto begin_10 = pos;
	while (1)
	{
		if (!(begin_10->name == Tokens::COMPARE_OP))
		{
			break;
		}
		_4 = *begin_10;
		success_5 = true;
		begin_10 += 2;
		shadow_6.push_back(_4);
		ISC_STD::skip_spaces(pos);
		_7 = expr_arithmetic(begin_10);
		if (!(_7.result))
		{
			break;
		}
		success_8 = true;
		begin_10 += 1;
		shadow_9.push_back(_7.token);
		shadow_11.push_back(_2);
		success_12 = true;
	}
	if (!success_12)
	{
		return {};
	}
	if (success_8)
	{
		success_3 = true;
		pos = begin_10;
	}
	expr_compare_data data;
	data.sequence = shadow_9;
	data.operators = shadow_6;
	data.first = _0.token;

	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::expr_compare, data)};
}
Parser::Rule_res Parser::Parser::expr_arithmetic(Token*& pos) {
	auto in = pos;
	::Parser::Rule_res _0;
	::Parser::bool_t success_1 = false;
	::Parser::arr_t<::Parser::UNDEF> shadow_11;
	::Parser::bool_t success_3 = false;
	::Parser::bool_t success_12 = false;
	::Parser::Token _4;
	::Parser::bool_t success_5 = false;
	::Parser::arr_t<::Parser::Token> shadow_6;
	::Parser::Rule_res _7;
	::Parser::bool_t success_8 = false;
	::Parser::arr_t<::Parser::Rule> shadow_9;
	_0 = expr_for_arithmetic(pos);
	if (!(_0.result))
	{
		return {};
	}
	success_1 = true;
	pos += 1;
	ISC_STD::skip_spaces(pos);
	auto begin_10 = pos;
	while (1)
	{
		if (!(begin_10->name == Tokens::OP))
		{
			break;
		}
		_4 = *begin_10;
		success_5 = true;
		begin_10 += 2;
		shadow_6.push_back(_4);
		ISC_STD::skip_spaces(pos);
		_7 = expr_for_arithmetic(begin_10);
		if (!(_7.result))
		{
			break;
		}
		success_8 = true;
		begin_10 += 1;
		shadow_9.push_back(_7.token);
		shadow_11.push_back(_2);
		success_12 = true;
	}
	if (!success_12)
	{
		return {};
	}
	if (success_8)
	{
		success_3 = true;
		pos = begin_10;
	}
	expr_arithmetic_data data;
	data.sequence = shadow_9;
	data.operators = shadow_6;
	data.first = _0.token;

	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::expr_arithmetic, data)};
}
Parser::Rule_res Parser::Parser::expr_for_arithmetic(Token*& pos) {
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
	_2 = expr_group(pos);
	if (!(_2.result))
	{
		_4 = method_call(pos);
		if (!(_4.result))
		{
			_6 = cll_function_call(pos);
			if (!(_6.result))
			{
				_8 = any_data(pos);
				if (!(_8.result))
				{
					return {};
				}
				else 
				{
					success_9 = true;
					_0 = _8.token;
				}
			}
			else 
			{
				success_7 = true;
				_0 = _6.token;
			}
		}
		else 
		{
			success_5 = true;
			_0 = _4.token;
		}
	}
	else 
	{
		success_3 = true;
		_0 = _2.token;
	}
	success_1 = true;
	pos += 1;
	expr_for_arithmetic_data data = _0;
	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::expr_for_arithmetic, data)};
}
Parser::Rule_res Parser::Parser::expr_group(Token*& pos) {
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
	if (!(pos->name == Tokens::AUTO_86))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos += 2;
	ISC_STD::skip_spaces(pos);
	_4 = cll_ternary(pos);
	if (!(_4.result))
	{
		_6 = expr(pos);
		if (!(_6.result))
		{
			return {};
		}
		else 
		{
			success_7 = true;
			_2 = _6.token;
		}
	}
	else 
	{
		success_5 = true;
		_2 = _4.token;
	}
	success_3 = true;
	pos += 1;
	ISC_STD::skip_spaces(pos);
	if (!(pos->name == Tokens::AUTO_87))
	{
		return {};
	}
	_8 = *pos;
	success_9 = true;
	pos += 2;
	expr_group_data data = _2;
	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::expr_group, data)};
}
Parser::Rule_res Parser::Parser::expr_expr_copiable_method_call(Token*& pos) {
	auto in = pos;
	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	::Parser::Rule_res _2;
	::Parser::bool_t success_3 = false;
	::Parser::Token _4;
	::Parser::bool_t success_5 = false;
	if (!(pos->name == Tokens::AUTO_86))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos += 2;
	ISC_STD::skip_spaces(pos);
	_2 = copiable_method_call(pos);
	if (!(_2.result))
	{
		return {};
	}
	success_3 = true;
	pos += 1;
	ISC_STD::skip_spaces(pos);
	if (!(pos->name == Tokens::AUTO_87))
	{
		return {};
	}
	_4 = *pos;
	success_5 = true;
	pos += 2;
	expr_expr_copiable_method_call_data data = _2.token;
	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::expr_expr_copiable_method_call, data)};
}
Parser::Rule_res Parser::Parser::expr(Token*& pos) {
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
	::Parser::Rule_res _10;
	::Parser::bool_t success_11 = false;
	::Parser::Rule_res _12;
	::Parser::bool_t success_13 = false;
	::Parser::Rule_res _14;
	::Parser::bool_t success_15 = false;
	_2 = expr_logical(pos);
	if (!(_2.result))
	{
		_4 = expr_compare(pos);
		if (!(_4.result))
		{
			_6 = expr_arithmetic(pos);
			if (!(_6.result))
			{
				_8 = expr_group(pos);
				if (!(_8.result))
				{
					_10 = expr_expr_copiable_method_call(pos);
					if (!(_10.result))
					{
						_12 = cll_function_call(pos);
						if (!(_12.result))
						{
							_14 = any_data(pos);
							if (!(_14.result))
							{
								return {};
							}
							else 
							{
								success_15 = true;
								_0 = _14.token;
							}
						}
						else 
						{
							success_13 = true;
							_0 = _12.token;
						}
					}
					else 
					{
						success_11 = true;
						_0 = _10.token;
					}
				}
				else 
				{
					success_9 = true;
					_0 = _8.token;
				}
			}
			else 
			{
				success_7 = true;
				_0 = _6.token;
			}
		}
		else 
		{
			success_5 = true;
			_0 = _4.token;
		}
	}
	else 
	{
		success_3 = true;
		_0 = _2.token;
	}
	success_1 = true;
	pos += 1;
	expr_data data = _0;
	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::expr, data)};
}
Parser::Rule_res Parser::Parser::function_body_call(Token*& pos) {
	auto in = pos;
	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	::Parser::Rule_res _2;
	::Parser::bool_t success_3 = false;
	::Parser::Token _4;
	::Parser::bool_t success_5 = false;
	if (!(pos->name == Tokens::AUTO_86))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos += 2;
	ISC_STD::skip_spaces(pos);
	_2 = function_arguments(pos);
	if (!(_2.result))
	{
		return {};
	}
	success_3 = true;
	pos += 1;
	ISC_STD::skip_spaces(pos);
	if (!(pos->name == Tokens::AUTO_87))
	{
		return {};
	}
	_4 = *pos;
	success_5 = true;
	pos += 2;
	function_body_call_data data = _2.token;
	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::function_body_call, data)};
}
Parser::Rule_res Parser::Parser::function_body_decl(Token*& pos) {
	auto in = pos;
	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	::Parser::Rule_res _2;
	::Parser::bool_t success_3 = false;
	::Parser::Token _4;
	::Parser::bool_t success_5 = false;
	if (!(pos->name == Tokens::AUTO_86))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos += 2;
	ISC_STD::skip_spaces(pos);
	_2 = function_parameters(pos);
	if (!(_2.result))
	{
		return {};
	}
	success_3 = true;
	pos += 1;
	ISC_STD::skip_spaces(pos);
	if (!(pos->name == Tokens::AUTO_87))
	{
		return {};
	}
	_4 = *pos;
	success_5 = true;
	pos += 2;
	function_body_decl_data data = _2.token;
	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::function_body_decl, data)};
}
Parser::Rule_res Parser::Parser::function_arguments(Token*& pos) {
	auto in = pos;
	::Parser::any_t _0;
	::Parser::bool_t success_1 = false;
	::Parser::any_t _2;
	::Parser::bool_t success_3 = false;
	::Parser::Rule_res _4;
	::Parser::bool_t success_5 = false;
	::Parser::Token _6;
	::Parser::bool_t success_7 = false;
	::Parser::arr_t<::Parser::UNDEF> shadow_23;
	::Parser::bool_t success_10 = false;
	::Parser::str_t _11;
	::Parser::bool_t success_12 = false;
	::Parser::arr_t<::Parser::str_t> shadow_13;
	::Parser::arr_t<::Parser::any_t> _14;
	::Parser::bool_t success_15 = false;
	::Parser::Rule_res _16;
	::Parser::bool_t success_17 = false;
	::Parser::arr_t<::Parser::Rule> shadow_18;
	::Parser::Token _19;
	::Parser::bool_t success_20 = false;
	::Parser::arr_t<::Parser::Token> shadow_21;
	auto begin_8 = pos;
	do
	{
		_4 = any_data(begin_8);
		if (!(_4.result))
		{
			if (!(begin_8->name == Tokens::ID))
			{
				break;
			}
			else 
			{
				_6 = *begin_8;
				success_7 = true;
				_2 = _6;
			}
		}
		else 
		{
			success_5 = true;
			_2 = _4.token;
		}
		success_3 = true;
		begin_8 += 2;
	}	while(0)
;
	if (success_3)
	{
		success_1 = true;
		pos = begin_8;
	}
	ISC_STD::skip_spaces(pos);
	if ((matched()))
	{
		auto begin_22 = pos;
		while (1)
		{
			if (!(*(pos + 0) == ','))
			{
				break;
			}
			_11 += ::Parser::str_t(begin_22, 1);
			success_12 = true;
			begin_22 += 2;
			shadow_13.push_back(_11);
			ISC_STD::skip_spaces(pos);
			_16 = any_data(begin_22);
			if (!(_16.result))
			{
				if (!(begin_22->name == Tokens::ID))
				{
					break;
				}
				else 
				{
					_19 = *begin_22;
					success_20 = true;
					shadow_21.push_back(_19);
					_14 = shadow_21;
				}
			}
			else 
			{
				success_17 = true;
				shadow_18.push_back(_16.token);
				_14 = shadow_18;
			}
			success_15 = true;
			begin_22 += 2;
			shadow_23.push_back(_9);
		}
		if (success_15)
		{
			success_10 = true;
			pos = begin_22;
		}
		ISC_STD::skip_spaces(pos);
	}
	function_arguments_data data = {,};
	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::function_arguments, data)};
}
Parser::Rule_res Parser::Parser::function_parameters(Token*& pos) {
	auto in = pos;
	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	::Parser::arr_t<::Parser::UNDEF> shadow_11;
	::Parser::bool_t success_3 = false;
	::Parser::str_t _4;
	::Parser::bool_t success_5 = false;
	::Parser::arr_t<::Parser::str_t> shadow_6;
	::Parser::Token _7;
	::Parser::bool_t success_8 = false;
	::Parser::arr_t<::Parser::Token> shadow_9;
	if (pos->name == Tokens::ID)
	{
		_0 = *pos;
		success_1 = true;
		pos += 2;
	}
	ISC_STD::skip_spaces(pos);
	if ((matched()))
	{
		auto begin_10 = pos;
		while (1)
		{
			if (!(*(pos + 0) == ','))
			{
				break;
			}
			_4 += ::Parser::str_t(begin_10, 1);
			success_5 = true;
			begin_10 += 2;
			shadow_6.push_back(_4);
			ISC_STD::skip_spaces(pos);
			if (!(begin_10->name == Tokens::ID))
			{
				break;
			}
			_7 = *begin_10;
			success_8 = true;
			begin_10 += 2;
			shadow_9.push_back(_7);
			shadow_11.push_back(_2);
		}
		if (success_8)
		{
			success_3 = true;
			pos = begin_10;
		}
		ISC_STD::skip_spaces(pos);
	}
	function_parameters_data data = {,};
	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::function_parameters, data)};
}
Parser::Rule_res Parser::Parser::cll_function_call(Token*& pos) {
	auto in = pos;
	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	::Parser::Rule_res _2;
	::Parser::bool_t success_3 = false;
	if (!(pos->name == Tokens::ID))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos += 2;
	ISC_STD::skip_spaces(pos);
	_2 = function_body_call(pos);
	if (!(_2.result))
	{
		return {};
	}
	success_3 = true;
	pos += 1;
	cll_function_call_data data;
	data.body = _2.token;
	data.name = _0;

	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::cll_function_call, data)};
}
Parser::Rule_res Parser::Parser::function_decl(Token*& pos) {
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
	::Parser::Rule _12;
	::Parser::bool_t success_13 = false;
	::Parser::Rule_res _14;
	::Parser::bool_t success_15 = false;
	::Parser::Rule_res _16;
	::Parser::bool_t success_17 = false;
	if (!(pos->name == Tokens::AUTO_46))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos += 2;
	ISC_STD::skip_spaces(pos);
	auto begin_8 = pos;
	while (begin_8->name == Tokens::ID)
	{
		_4 = *begin_8;
		success_5 = true;
		begin_8 += 2;
		shadow_6.push_back(_4);
		success_7 = true;
	}
	if (!success_7)
	{
		return {};
	}
	if (success_5)
	{
		success_3 = true;
		pos = begin_8;
	}
	_2 = _4;
	ISC_STD::skip_spaces(pos);
	_9 = function_body_decl(pos);
	if (!(_9.result))
	{
		return {};
	}
	success_10 = true;
	pos += 1;
	ISC_STD::skip_spaces(pos);
	auto begin_18 = pos;
	do
	{
		_14 = cll_block(begin_18);
		if (!(_14.result))
		{
			_16 = cll_spaced_block(begin_18);
			if (!(_16.result))
			{
				break;
			}
			else 
			{
				success_17 = true;
				_12 = _16.token;
			}
		}
		else 
		{
			success_15 = true;
			_12 = _14.token;
		}
		success_13 = true;
		begin_18 += 1;
	}	while(0)
;
	if (success_13)
	{
		success_11 = true;
		pos = begin_18;
	}
	val = _12;
	function_decl_data data;
	data.value = val;
	data.name = _2;
	data.type = shadow_6;

	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::function_decl, data)};
}
Parser::Rule_res Parser::Parser::loop_while(Token*& pos) {
	auto in = pos;
	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	::Parser::Rule_res _2;
	::Parser::bool_t success_3 = false;
	::Parser::Rule _4;
	::Parser::bool_t success_5 = false;
	::Parser::Rule_res _6;
	::Parser::bool_t success_7 = false;
	::Parser::Rule_res _8;
	::Parser::bool_t success_9 = false;
	if (!(pos->name == Tokens::AUTO_47))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos += 2;
	ISC_STD::skip_spaces(pos);
	_2 = expr(pos);
	if (!(_2.result))
	{
		return {};
	}
	success_3 = true;
	pos += 1;
	ISC_STD::skip_spaces(pos);
	_6 = cll_block(pos);
	if (!(_6.result))
	{
		_8 = cll_spaced_block(pos);
		if (!(_8.result))
		{
			return {};
		}
		else 
		{
			success_9 = true;
			_4 = _8.token;
		}
	}
	else 
	{
		success_7 = true;
		_4 = _6.token;
	}
	success_5 = true;
	pos += 1;
	loop_while_data data;
	data.block = _4;
	data.expr = _2.token;

	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::loop_while, data)};
}
Parser::Rule_res Parser::Parser::loop_for(Token*& pos) {
	auto in = pos;
	::Parser::Rule_res _0;
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
	::Parser::Rule _23;
	::Parser::bool_t success_24 = false;
	::Parser::Rule_res _25;
	::Parser::bool_t success_26 = false;
	::Parser::Rule_res _27;
	::Parser::bool_t success_28 = false;
	_0 = for(pos);
	if (!(_0.result))
	{
		return {};
	}
	success_1 = true;
	pos += 1;
	ISC_STD::skip_spaces(pos);
	if (!(pos->name == Tokens::AUTO_86))
	{
		return {};
	}
	_2 = *pos;
	success_3 = true;
	pos += 2;
	ISC_STD::skip_spaces(pos);
	auto begin_12 = pos;
	do
	{
		_8 = expr(begin_12);
		if (!(_8.result))
		{
			_10 = cll_var(begin_12);
			if (!(_10.result))
			{
				break;
			}
			else 
			{
				success_11 = true;
				_6 = _10.token;
			}
		}
		else 
		{
			success_9 = true;
			_6 = _8.token;
		}
		success_7 = true;
		begin_12 += 1;
	}	while(0)
;
	if (success_7)
	{
		success_5 = true;
		pos = begin_12;
	}
	_4 = _6;
	ISC_STD::skip_spaces(pos);
	if (!(pos->name == Tokens::AUTO_101))
	{
		return {};
	}
	_13 = *pos;
	success_14 = true;
	pos += 2;
	ISC_STD::skip_spaces(pos);
	_15 = expr(pos);
	if (_15.result)
	{
		success_16 = true;
		pos += 1;
	}
	ISC_STD::skip_spaces(pos);
	if (!(pos->name == Tokens::AUTO_101))
	{
		return {};
	}
	_17 = *pos;
	success_18 = true;
	pos += 2;
	ISC_STD::skip_spaces(pos);
	_19 = expr(pos);
	if (_19.result)
	{
		success_20 = true;
		pos += 1;
	}
	ISC_STD::skip_spaces(pos);
	if (!(pos->name == Tokens::AUTO_87))
	{
		return {};
	}
	_21 = *pos;
	success_22 = true;
	pos += 2;
	ISC_STD::skip_spaces(pos);
	_25 = cll_block(pos);
	if (!(_25.result))
	{
		_27 = cll_spaced_block(pos);
		if (!(_27.result))
		{
			return {};
		}
		else 
		{
			success_28 = true;
			_23 = _27.token;
		}
	}
	else 
	{
		success_26 = true;
		_23 = _25.token;
	}
	success_24 = true;
	pos += 1;
	loop_for_data data;
	data.block = _21;
	data.end = _17;
	data.cond = _13;
	data.decl = _6;

	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::loop_for, data)};
}
Parser::Rule_res Parser::Parser::method_call(Token*& pos) {
	auto in = pos;
	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	::Parser::arr_t<::Parser::UNDEF> shadow_11;
	::Parser::bool_t success_3 = false;
	::Parser::bool_t success_12 = false;
	::Parser::Token _4;
	::Parser::bool_t success_5 = false;
	::Parser::arr_t<::Parser::Token> shadow_6;
	::Parser::Rule_res _7;
	::Parser::bool_t success_8 = false;
	::Parser::arr_t<::Parser::Rule> shadow_9;
	if (!(pos->name == Tokens::ID))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos += 2;
	ISC_STD::skip_spaces(pos);
	auto begin_10 = pos;
	while (1)
	{
		if (!(begin_10->name == Tokens::AUTO_97))
		{
			break;
		}
		_4 = *begin_10;
		success_5 = true;
		begin_10 += 2;
		shadow_6.push_back(_4);
		ISC_STD::skip_spaces(pos);
		_7 = cll_function_call(begin_10);
		if (!(_7.result))
		{
			break;
		}
		success_8 = true;
		begin_10 += 1;
		shadow_9.push_back(_7.token);
		shadow_11.push_back(_2);
		success_12 = true;
	}
	if (!success_12)
	{
		return {};
	}
	if (success_8)
	{
		success_3 = true;
		pos = begin_10;
	}
	method_call_data data;
	data.call = shadow_9;
	data.object = _0;

	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::method_call, data)};
}
Parser::Rule_res Parser::Parser::copiable_method_call(Token*& pos) {
	auto in = pos;
	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	::Parser::Rule_res _2;
	::Parser::bool_t success_3 = false;
	if (!(pos->name == Tokens::AUTO_53))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos += 2;
	ISC_STD::skip_spaces(pos);
	_2 = method_call(pos);
	if (!(_2.result))
	{
		return {};
	}
	success_3 = true;
	pos += 1;
	copiable_method_call_data data = _2.token;
	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::copiable_method_call, data)};
}
Parser::Rule_res Parser::Parser::var_refer(Token*& pos) {
	auto in = pos;
	::Parser::any_t pre = matched();
	::Parser::any_t post = matched();
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
		if (!(begin_8->name == Tokens::AUTO_58))
		{
			if (!(begin_8->name == Tokens::AUTO_59))
			{
				break;
			}
			else 
			{
				_6 = *begin_8;
				success_7 = true;
				_2 = _6;
			}
		}
		else 
		{
			_4 = *begin_8;
			success_5 = true;
			_2 = _4;
		}
		success_3 = true;
		begin_8 += 3;
	}	while(0)
;
	if (success_3)
	{
		success_1 = true;
		pos = begin_8;
	}
	_0 = _2;
	ISC_STD::skip_spaces(pos);
	if (!(pos->name == Tokens::ID))
	{
		return {};
	}
	_9 = *pos;
	success_10 = true;
	pos += 2;
	ISC_STD::skip_spaces(pos);
	auto begin_19 = pos;
	do
	{
		if (!(begin_19->name == Tokens::AUTO_88))
		{
			break;
		}
		_13 = *begin_19;
		success_14 = true;
		begin_19 += 2;
		ISC_STD::skip_spaces(pos);
		_15 = expr(begin_19);
		if (!(_15.result))
		{
			break;
		}
		success_16 = true;
		begin_19 += 1;
		ISC_STD::skip_spaces(pos);
		if (!(begin_19->name == Tokens::AUTO_90))
		{
			break;
		}
		_17 = *begin_19;
		success_18 = true;
		begin_19 += 2;
	}	while(0)
;
	if (success_18)
	{
		success_12 = true;
		pos = begin_19;
	}
	ISC_STD::skip_spaces(pos);
	auto begin_28 = pos;
	do
	{
		if (!(begin_28->name == Tokens::AUTO_58))
		{
			if (!(begin_28->name == Tokens::AUTO_59))
			{
				break;
			}
			else 
			{
				_26 = *begin_28;
				success_27 = true;
				_22 = _26;
			}
		}
		else 
		{
			_24 = *begin_28;
			success_25 = true;
			_22 = _24;
		}
		success_23 = true;
		begin_28 += 3;
	}	while(0)
;
	if (success_23)
	{
		success_21 = true;
		pos = begin_28;
	}
	_20 = _22;
	var_refer_data data;
	data.post = post;
	data.pre = pre;
	data.brace_expression = _15.token;
	data.name = _2;

	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::var_refer, data)};
}
Parser::Rule_res Parser::Parser::cll_var(Token*& pos) {
	auto in = pos;
	::Parser::Rule_res _0;
	::Parser::bool_t success_1 = false;
	::Parser::Token _2;
	::Parser::bool_t success_3 = false;
	::Parser::bool_t success_5 = false;
	::Parser::Rule_res _6;
	::Parser::bool_t success_7 = false;
	::Parser::Rule _8;
	::Parser::bool_t success_9 = false;
	::Parser::Rule_res _10;
	::Parser::bool_t success_11 = false;
	::Parser::Rule_res _12;
	::Parser::bool_t success_13 = false;
	_0 = cll_type(pos);
	if (_0.result)
	{
		success_1 = true;
		pos += 1;
	}
	ISC_STD::skip_spaces(pos);
	if (!(pos->name == Tokens::ID))
	{
		return {};
	}
	_2 = *pos;
	success_3 = true;
	pos += 2;
	ISC_STD::skip_spaces(pos);
	auto begin_14 = pos;
	do
	{
		_6 = assignment_op(begin_14);
		if (!(_6.result))
		{
			break;
		}
		success_7 = true;
		begin_14 += 1;
		ISC_STD::skip_spaces(pos);
		_10 = expr(begin_14);
		if (!(_10.result))
		{
			_12 = cll_ternary(begin_14);
			if (!(_12.result))
			{
				break;
			}
			else 
			{
				success_13 = true;
				_8 = _12.token;
			}
		}
		else 
		{
			success_11 = true;
			_8 = _10.token;
		}
		success_9 = true;
		begin_14 += 1;
	}	while(0)
;
	if (success_9)
	{
		success_5 = true;
		pos = begin_14;
	}
	cll_var_data data;
	data.value = _8;
	data.operator = _6.token;
	data.id = _2;
	data.type = _0.token;

	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::cll_var, data)};
}
Parser::Token_res Parser::Tokenizator::STRING(const char* &pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	::Parser::bool_t success_3 = false;
	::Parser::str_t _4;
	::Parser::bool_t success_5 = false;
	::Parser::arr_t<::Parser::any_t> shadow_17;
	::Parser::any_t _6;
	::Parser::bool_t success_7 = false;
	::Parser::arr_t<::Parser::any_t> _8;
	::Parser::bool_t success_9 = false;
	::Parser::str_t _10;
	::Parser::bool_t success_11 = false;
	::Parser::arr_t<::Parser::str_t> shadow_12;
	::Parser::str_t _13;
	::Parser::bool_t success_14 = false;
	::Parser::arr_t<::Parser::str_t> shadow_15;
	::Parser::str_t _18;
	::Parser::bool_t success_19 = false;
	::Parser::bool_t success_22 = false;
	::Parser::str_t _23;
	::Parser::bool_t success_24 = false;
	::Parser::arr_t<::Parser::any_t> shadow_36;
	::Parser::any_t _25;
	::Parser::bool_t success_26 = false;
	::Parser::arr_t<::Parser::any_t> _27;
	::Parser::bool_t success_28 = false;
	::Parser::str_t _29;
	::Parser::bool_t success_30 = false;
	::Parser::arr_t<::Parser::str_t> shadow_31;
	::Parser::str_t _32;
	::Parser::bool_t success_33 = false;
	::Parser::arr_t<::Parser::str_t> shadow_34;
	::Parser::str_t _37;
	::Parser::bool_t success_38 = false;
	data = _4;
	auto begin_20 = pos;
	do
	{
		if (!(*(pos + 0) == '\''))
		{
			break;
		}
		_4 += ::Parser::str_t(begin_20, 1);
		success_5 = true;
		begin_20 += 2;
		ISC_STD::skip_spaces(pos);
		auto begin_16 = begin_20;
		while (1)
		{
			if (!(!std::strncmp(pos, "\\'", 2)))
			{
				if (!(!(*(pos + 1) == '\'')))
				{
					break;
				}
				else 
				{
					_13 += ::Parser::str_t(begin_16, 2);
					success_14 = true;
					shadow_15.push_back(_13);
					_8 = shadow_15;
				}
			}
			else 
			{
				_10 += ::Parser::str_t(begin_16, 2);
				success_11 = true;
				shadow_12.push_back(_10);
				_8 = shadow_12;
			}
			success_9 = true;
			begin_16 += 3;
			shadow_17.push_back(_6);
		}
		if (success_9)
		{
			success_7 = true;
			begin_20 = begin_16;
		}
		ISC_STD::skip_spaces(pos);
		if (!(*(pos + 0) == '\''))
		{
			break;
		}
		_18 += ::Parser::str_t(begin_20, 1);
		success_19 = true;
		begin_20 += 2;
	}	while(0)
;
	if (success_19)
	{
		success_3 = true;
		pos = begin_20;
	}
	if (!success_3)
	{
		auto begin_39 = pos;
		do
		{
			if (!(*(pos + 0) == '"'))
			{
				break;
			}
			_23 += ::Parser::str_t(begin_39, 1);
			success_24 = true;
			begin_39 += 2;
			ISC_STD::skip_spaces(pos);
			auto begin_35 = begin_39;
			while (1)
			{
				if (!(!std::strncmp(pos, "\\\"", 2)))
				{
					if (!(!(*(pos + 1) == '"')))
					{
						break;
					}
					else 
					{
						_32 += ::Parser::str_t(begin_35, 2);
						success_33 = true;
						shadow_34.push_back(_32);
						_27 = shadow_34;
					}
				}
				else 
				{
					_29 += ::Parser::str_t(begin_35, 2);
					success_30 = true;
					shadow_31.push_back(_29);
					_27 = shadow_31;
				}
				success_28 = true;
				begin_35 += 3;
				shadow_36.push_back(_25);
			}
			if (success_28)
			{
				success_26 = true;
				begin_39 = begin_35;
			}
			ISC_STD::skip_spaces(pos);
			if (!(*(pos + 0) == '"'))
			{
				break;
			}
			_37 += ::Parser::str_t(begin_39, 1);
			success_38 = true;
			begin_39 += 2;
		}		while(0)
;
		if (success_38)
		{
			success_22 = true;
			pos = begin_39;
		}
		if (!success_22)
		{
			return {};
		}
		else 
		{
			_0 = _21;
		}
	}
	else 
	{
		_0 = _2;
	}
	success_1 = true;
	pos += 1;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::STRING)};
}
Parser::Token_res Parser::Tokenizator::NUMBER(const char* &pos) {
	auto in = pos;
	char sign = _0;
	::Parser::str_t main = _6;
	::Parser::num_t main_n = NUMBER(main);
	char point = _0;
	::Parser::str_t dec = _0;
	::Parser::num_t dec_n = NUMBER(dec);
	::Parser::str_t full = main+point;
	::Parser::Rule_res _0;
	::Parser::bool_t success_1 = false;
	::Parser::str_t _2;
	::Parser::bool_t success_3 = false;
	::Parser::str_t _4;
	::Parser::bool_t success_5 = false;
	::Parser::str_t _6;
	::Parser::bool_t success_7 = false;
	::Parser::str_t _8;
	::Parser::bool_t success_9 = false;
	::Parser::arr_t<::Parser::str_t> shadow_10;
	::Parser::bool_t success_11 = false;
	::Parser::str_t _13;
	::Parser::bool_t success_14 = false;
	::Parser::str_t _15;
	::Parser::bool_t success_16 = false;
	::Parser::str_t _17;
	::Parser::bool_t success_18 = false;
	::Parser::arr_t<::Parser::str_t> shadow_19;
	::Parser::bool_t success_20 = false;
	ISC_STD::skip_spaces(pos);
	if (!(*(pos + 0) == '+' || *(pos + 0) == '-'))
	{
		return {};
	}
	_2 += ::Parser::str_t(pos, 0);
	success_3 = true;
	pos += 1;
	ISC_STD::skip_spaces(pos);
	auto begin_12 = pos;
	do
	{
		while ((*(pos + 0)>='0' && *(pos + 0)<='9'))
		{
			_8 += ::Parser::str_t(begin_12, 0);
			success_9 = true;
			begin_12 += 1;
			shadow_10.push_back(_8);
			success_11 = true;
		}
		if (!success_11)
		{
			break;
		}
	}	while(0)
;
	if (success_9)
	{
		success_7 = true;
		pos = begin_12;
	}
	_6 += shadow_10;
	if (!success_7)
	{
		auto begin_21 = pos;
		do
		{
			if (!(*(pos + 0) == '.' || *(pos + 0) == ','))
			{
				break;
			}
			_15 += ::Parser::str_t(begin_21, 0);
			success_16 = true;
			begin_21 += 1;
			ISC_STD::skip_spaces(pos);
			while ((*(pos + 0)>='0' && *(pos + 0)<='9'))
			{
				_17 += ::Parser::str_t(begin_21, 0);
				success_18 = true;
				begin_21 += 1;
				shadow_19.push_back(_17);
				success_20 = true;
			}
			if (!success_20)
			{
				break;
			}
		}		while(0)
;
		if (success_18)
		{
			success_14 = true;
			pos = begin_21;
		}
		_13 += _15;
		_13 += shadow_19;
		if (!success_14)
		{
			return {};
		}
		else 
		{
			_4 = _13;
		}
	}
	else 
	{
		_4 = _6;
	}
	success_5 = true;
	pos += 1;
	NUMBER_data data;
	data.full = full;
	data.dec_n = dec_n;
	data.dec = dec;
	data.main_n = main_n;
	data.main = main;
	data.sign = sign;

	return {true, ::Parser::Token(in - str, in, pos, Tokens::NUMBER, data)};
}
Parser::Token_res Parser::Tokenizator::BOOLEAN(const char* &pos) {
	auto in = pos;
	::Parser::str_t d;
	::Parser::bool_t success_0 = false;
	::Parser::str_t _1;
	::Parser::bool_t success_2 = false;
	::Parser::str_t _3;
	::Parser::bool_t success_4 = false;
	::Parser::str_t _5;
	::Parser::bool_t success_6 = false;
	::Parser::bool_t val;
	auto begin_7 = pos;
	if (!(!std::strncmp(pos, "true", 4)))
	{
		if (!(!std::strncmp(pos, "false", 5)))
		{
			return {};
		}
		else 
		{
			_5 += ::Parser::str_t(begin_7, 9);
			success_6 = true;
			_1 = _5;
		}
	}
	else 
	{
		_3 += ::Parser::str_t(begin_7, 9);
		success_4 = true;
		_1 = _3;
	}
	success_2 = true;
	begin_7 += 10;
	if (success_2)
	{
		success_0 = true;
		pos = begin_7;
	}
	d += _1;
	ISC_STD::skip_spaces(pos);
	BOOLEAN_data data;
	data.lit = d;
	data.val = val;

	return {true, ::Parser::Token(in - str, in, pos, Tokens::BOOLEAN, data)};
}
Parser::Rule_res Parser::Parser::array(Token*& pos) {
	auto in = pos;
	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	::Parser::bool_t success_3 = false;
	::Parser::arr_t<::Parser::UNDEF> shadow_13;
	::Parser::bool_t success_5 = false;
	::Parser::Rule_res _6;
	::Parser::bool_t success_7 = false;
	::Parser::arr_t<::Parser::Rule> shadow_8;
	::Parser::Token _9;
	::Parser::bool_t success_10 = false;
	::Parser::arr_t<::Parser::Token> shadow_11;
	::Parser::Token _15;
	::Parser::bool_t success_16 = false;
	if (!(pos->name == Tokens::AUTO_88))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos += 2;
	ISC_STD::skip_spaces(pos);
	auto begin_14 = pos;
	do
	{
		auto begin_12 = begin_14;
		while (1)
		{
			_6 = any_data(begin_12);
			if (!(_6.result))
			{
				break;
			}
			success_7 = true;
			begin_12 += 1;
			shadow_8.push_back(_6.token);
			ISC_STD::skip_spaces(pos);
			if (!(begin_12->name == Tokens::AUTO_76))
			{
				break;
			}
			_9 = *begin_12;
			success_10 = true;
			begin_12 += 2;
			shadow_11.push_back(_9);
			shadow_13.push_back(_4);
		}
		if (success_10)
		{
			success_5 = true;
			begin_14 = begin_12;
		}
	}	while(0)
;
	if (success_5)
	{
		success_3 = true;
		pos = begin_14;
	}
	ISC_STD::skip_spaces(pos);
	if (!(pos->name == Tokens::AUTO_90))
	{
		return {};
	}
	_15 = *pos;
	success_16 = true;
	pos += 2;
	array_data data = shadow_11;
	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::array, data)};
}
Parser::Rule_res Parser::Parser::object(Token*& pos) {
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
	::Parser::arr_t<::Parser::UNDEF> shadow_25;
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
	::Parser::Token _26;
	::Parser::bool_t success_27 = false;
	::Parser::Token _29;
	::Parser::bool_t success_30 = false;
	if (!(pos->name == Tokens::AUTO_63))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos += 2;
	ISC_STD::skip_spaces(pos);
	auto begin_28 = pos;
	do
	{
		_4 = any_data(begin_28);
		if (!(_4.result))
		{
			break;
		}
		success_5 = true;
		begin_28 += 1;
		ISC_STD::skip_spaces(pos);
		if (!(begin_28->name == Tokens::AUTO_103))
		{
			break;
		}
		_6 = *begin_28;
		success_7 = true;
		begin_28 += 2;
		ISC_STD::skip_spaces(pos);
		_8 = any_data(begin_28);
		if (!(_8.result))
		{
			break;
		}
		success_9 = true;
		begin_28 += 1;
		ISC_STD::skip_spaces(pos);
		auto begin_24 = begin_28;
		while (1)
		{
			if (!(begin_24->name == Tokens::AUTO_76))
			{
				break;
			}
			_12 = *begin_24;
			success_13 = true;
			begin_24 += 2;
			shadow_14.push_back(_12);
			ISC_STD::skip_spaces(pos);
			if (!(begin_24->name == Tokens::ID))
			{
				break;
			}
			_15 = *begin_24;
			success_16 = true;
			begin_24 += 2;
			shadow_17.push_back(_15);
			ISC_STD::skip_spaces(pos);
			if (!(begin_24->name == Tokens::AUTO_103))
			{
				break;
			}
			_18 = *begin_24;
			success_19 = true;
			begin_24 += 2;
			shadow_20.push_back(_18);
			ISC_STD::skip_spaces(pos);
			_21 = any_data(begin_24);
			if (!(_21.result))
			{
				break;
			}
			success_22 = true;
			begin_24 += 1;
			shadow_23.push_back(_21.token);
			shadow_25.push_back(_10);
		}
		if (success_22)
		{
			success_11 = true;
			begin_28 = begin_24;
		}
		ISC_STD::skip_spaces(pos);
		if (!(begin_28->name == Tokens::AUTO_101))
		{
			break;
		}
		_26 = *begin_28;
		success_27 = true;
		begin_28 += 2;
	}	while(0)
;
	if (success_27)
	{
		success_3 = true;
		pos = begin_28;
	}
	ISC_STD::skip_spaces(pos);
	if (!(pos->name == Tokens::AUTO_68))
	{
		return {};
	}
	_29 = *pos;
	success_30 = true;
	pos += 2;
	object_data data;
	data.values = shadow_23;
	data.keys = shadow_17;
	data.value = _8.token;
	data.key = _4.token;

	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::object, data)};
}
Parser::Rule_res Parser::Parser::any_data(Token*& pos) {
	auto in = pos;
	::Parser::any_t _0;
	::Parser::bool_t success_1 = false;
	::Parser::Token _2;
	::Parser::bool_t success_3 = false;
	::Parser::Token _4;
	::Parser::bool_t success_5 = false;
	::Parser::Token _6;
	::Parser::bool_t success_7 = false;
	::Parser::Token _8;
	::Parser::bool_t success_9 = false;
	::Parser::Rule_res _10;
	::Parser::bool_t success_11 = false;
	::Parser::Rule_res _12;
	::Parser::bool_t success_13 = false;
	::Parser::Rule_res _14;
	::Parser::bool_t success_15 = false;
	data = _0;
	if (!(pos->name == Tokens::BOOLEAN))
	{
		if (!(pos->name == Tokens::NUMBER))
		{
			if (!(pos->name == Tokens::STRING))
			{
				if (!(pos->name == Tokens::ID))
				{
					_10 = array(pos);
					if (!(_10.result))
					{
						_12 = object(pos);
						if (!(_12.result))
						{
							_14 = accessor(pos);
							if (!(_14.result))
							{
								return {};
							}
							else 
							{
								success_15 = true;
								_0 = _14.token;
							}
						}
						else 
						{
							success_13 = true;
							_0 = _12.token;
						}
					}
					else 
					{
						success_11 = true;
						_0 = _10.token;
					}
				}
				else 
				{
					_8 = *pos;
					success_9 = true;
					_0 = _8;
				}
			}
			else 
			{
				_6 = *pos;
				success_7 = true;
				_0 = _6;
			}
		}
		else 
		{
			_4 = *pos;
			success_5 = true;
			_0 = _4;
		}
	}
	else 
	{
		_2 = *pos;
		success_3 = true;
		_0 = _2;
	}
	success_1 = true;
	pos += 5;
	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::any_data)};
}
Parser::Token_res Parser::Tokenizator::END(const char* &pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == ';' || *(pos + 0) == '\n'))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 0);
	success_1 = true;
	pos += 1;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::END)};
}
Parser::Token_res Parser::Tokenizator::NEWLINE(const char* &pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == '\n'))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 0);
	success_1 = true;
	pos += 1;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::NEWLINE)};
}
Parser::Token_res Parser::Tokenizator::ID(const char* &pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	::Parser::str_t _2;
	::Parser::bool_t success_3 = false;
	::Parser::arr_t<::Parser::str_t> shadow_4;
	::Parser::str_t _5;
	::Parser::bool_t success_6 = false;
	::Parser::str_t _7;
	::Parser::bool_t success_8 = false;
	::Parser::arr_t<::Parser::str_t> shadow_9;
	auto begin_10 = pos;
	while ((*(pos + 0)>='0' && *(pos + 0)<='9'))
	{
		_2 += ::Parser::str_t(begin_10, 0);
		success_3 = true;
		begin_10 += 1;
		shadow_4.push_back(_2);
	}
	ISC_STD::skip_spaces(pos);
	if (!((*(pos + 0)>='a' && *(pos + 0)<='z') || (*(pos + 0)>='A' && *(pos + 0)<='Z') || *(pos + 0) == '_'))
	{
		return {};
	}
	_5 += ::Parser::str_t(begin_10, 0);
	success_6 = true;
	begin_10 += 1;
	ISC_STD::skip_spaces(pos);
	while ((*(pos + 0)>='a' && *(pos + 0)<='z') || (*(pos + 0)>='A' && *(pos + 0)<='Z') || (*(pos + 0)>='0' && *(pos + 0)<='9') || *(pos + 0) == '_')
	{
		_7 += ::Parser::str_t(begin_10, 0);
		success_8 = true;
		begin_10 += 1;
		shadow_9.push_back(_7);
	}
	if (success_8)
	{
		success_1 = true;
		pos = begin_10;
	}
	_0 += shadow_4;
	_0 += _5;
	_0 += shadow_9;
	ID_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::ID, data)};
}
Parser::Rule_res Parser::Parser::spacemode(Token*& pos) {
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
	if (!(pos->name == Tokens::AUTO_69))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos += 2;
	ISC_STD::skip_spaces(pos);
	if (!(pos->name == Tokens::AUTO_70))
	{
		if (!(pos->name == Tokens::AUTO_71))
		{
			if (!(pos->name == Tokens::AUTO_72))
			{
				return {};
			}
			else 
			{
				_8 = *pos;
				success_9 = true;
				_2 = _8;
			}
		}
		else 
		{
			_6 = *pos;
			success_7 = true;
			_2 = _6;
		}
	}
	else 
	{
		_4 = *pos;
		success_5 = true;
		_2 = _4;
	}
	success_3 = true;
	pos += 4;
	spacemode_data data = _0;
	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::spacemode, data)};
}
Parser::Rule_res Parser::Parser::linear_comment(Token*& pos) {
	auto in = pos;
	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	::Parser::Token _2;
	::Parser::bool_t success_3 = false;
	if (!(pos->name == Tokens::AUTO_73))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos += 2;
	ISC_STD::skip_spaces(pos);
	if (!(pos->name == Tokens::AUTO_74))
	{
		return {};
	}
	_2 = *pos;
	success_3 = true;
	pos += 2;
	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::linear_comment)};
}
Parser::Rule_res Parser::Parser::main(Token*& pos) {
	auto in = pos;
	::Parser::any_t _0;
	::Parser::bool_t success_1 = false;
	::Parser::Rule_res _2;
	::Parser::bool_t success_3 = false;
	::Parser::Rule_res _4;
	::Parser::bool_t success_5 = false;
	::Parser::Token _6;
	::Parser::bool_t success_7 = false;
	::Parser::Rule_res _8;
	::Parser::bool_t success_9 = false;
	_2 = Import(pos);
	if (!(_2.result))
	{
		_4 = use(pos);
		if (!(_4.result))
		{
			if (!(pos->name == Tokens::AUTO_97))
			{
				_8 = spacemode(pos);
				if (!(_8.result))
				{
					return {};
				}
				else 
				{
					success_9 = true;
					_0 = _8.token;
				}
			}
			else 
			{
				_6 = *pos;
				success_7 = true;
				_0 = _6;
			}
		}
		else 
		{
			success_5 = true;
			_0 = _4.token;
		}
	}
	else 
	{
		success_3 = true;
		_0 = _2.token;
	}
	success_1 = true;
	pos += 2;
	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::main)};
}
Parser::Rule_res Parser::Parser::use_unit(Token*& pos) {
	auto in = pos;
	::Parser::Rule_res _0;
	::Parser::bool_t success_1 = false;
	::Parser::Rule_res _2;
	::Parser::bool_t success_3 = false;
	_0 = id(pos);
	if (!(_0.result))
	{
		return {};
	}
	success_1 = true;
	pos += 1;
	ISC_STD::skip_spaces(pos);
	_2 = any_data(pos);
	if (_2.result)
	{
		success_3 = true;
		pos += 1;
	}
	use_unit_data data;
	data.value = _2.token;
	data.name = _0.token;

	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::use_unit, data)};
}
Parser::Rule_res Parser::Parser::use(Token*& pos) {
	auto in = pos;
	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	::Parser::Rule_res _2;
	::Parser::bool_t success_3 = false;
	::Parser::arr_t<::Parser::UNDEF> shadow_13;
	::Parser::bool_t success_5 = false;
	::Parser::Token _6;
	::Parser::bool_t success_7 = false;
	::Parser::arr_t<::Parser::Token> shadow_8;
	::Parser::Rule_res _9;
	::Parser::bool_t success_10 = false;
	::Parser::arr_t<::Parser::Rule> shadow_11;
	if (!(pos->name == Tokens::AUTO_75))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos += 2;
	ISC_STD::skip_spaces(pos);
	_2 = use_unit(pos);
	if (!(_2.result))
	{
		return {};
	}
	success_3 = true;
	pos += 1;
	ISC_STD::skip_spaces(pos);
	auto begin_12 = pos;
	while (1)
	{
		if (!(begin_12->name == Tokens::AUTO_76))
		{
			break;
		}
		_6 = *begin_12;
		success_7 = true;
		begin_12 += 2;
		shadow_8.push_back(_6);
		ISC_STD::skip_spaces(pos);
		_9 = use_unit(begin_12);
		if (!(_9.result))
		{
			break;
		}
		success_10 = true;
		begin_12 += 1;
		shadow_11.push_back(_9.token);
		shadow_13.push_back(_4);
	}
	if (success_10)
	{
		success_5 = true;
		pos = begin_12;
	}
	use_data data;
	data.second = shadow_11;
	data.first = _2.token;

	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::use, data)};
}
Parser::Rule_res Parser::Parser::Rule_rule(Token*& pos) {
	auto in = pos;
	::Parser::any_t _0;
	::Parser::bool_t success_1 = false;
	::Parser::bool_t success_3 = false;
	::Parser::any_t _4;
	::Parser::bool_t success_5 = false;
	::Parser::any_t _6;
	::Parser::bool_t success_7 = false;
	::Parser::Rule_res _8;
	::Parser::bool_t success_9 = false;
	::Parser::Rule_res _10;
	::Parser::bool_t success_11 = false;
	::Parser::Token _12;
	::Parser::bool_t success_13 = false;
	::Parser::Rule_res _14;
	::Parser::bool_t success_15 = false;
	::Parser::Rule_res _16;
	::Parser::bool_t success_17 = false;
	::Parser::Rule_res _18;
	::Parser::bool_t success_19 = false;
	::Parser::Rule_res _20;
	::Parser::bool_t success_21 = false;
	::Parser::Rule_res _23;
	::Parser::bool_t success_24 = false;
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
	auto begin_25 = pos;
	do
	{
		auto begin_22 = begin_25;
		_8 = Rule_group(begin_22);
		if (!(_8.result))
		{
			_10 = Rule_csequence(begin_22);
			if (!(_10.result))
			{
				if (!(begin_22->name == Tokens::STRING))
				{
					_14 = accessor(begin_22);
					if (!(_14.result))
					{
						_16 = Rule_hex(begin_22);
						if (!(_16.result))
						{
							_18 = Rule_bin(begin_22);
							if (!(_18.result))
							{
								_20 = Rule_other(begin_22);
								if (!(_20.result))
								{
									break;
								}
								else 
								{
									success_21 = true;
									_6 = _20.token;
								}
							}
							else 
							{
								success_19 = true;
								_6 = _18.token;
							}
						}
						else 
						{
							success_17 = true;
							_6 = _16.token;
						}
					}
					else 
					{
						success_15 = true;
						_6 = _14.token;
					}
				}
				else 
				{
					_12 = *begin_22;
					success_13 = true;
					_6 = _12;
				}
			}
			else 
			{
				success_11 = true;
				_6 = _10.token;
			}
		}
		else 
		{
			success_9 = true;
			_6 = _8.token;
		}
		success_7 = true;
		begin_22 += 2;
		if (success_7)
		{
			success_5 = true;
			begin_25 = begin_22;
		}
		ISC_STD::skip_spaces(pos);
		_23 = Rule_qualifier(begin_25);
		if (_23.result)
		{
			success_24 = true;
			begin_25 += 1;
		}
	}	while(0)
;
	if (success_24)
	{
		success_3 = true;
		pos = begin_25;
	}
	if (!success_3)
	{
		_26 = Rule_rule_escaped(pos);
		if (!(_26.result))
		{
			if (!(pos->name == Tokens::AUTO_97))
			{
				_30 = Rule_rule_op(pos);
				if (!(_30.result))
				{
					_32 = cll(pos);
					if (!(_32.result))
					{
						_34 = linear_comment(pos);
						if (!(_34.result))
						{
							return {};
						}
						else 
						{
							success_35 = true;
							_0 = _34.token;
						}
					}
					else 
					{
						success_33 = true;
						_0 = _32.token;
					}
				}
				else 
				{
					success_31 = true;
					_0 = _30.token;
				}
			}
			else 
			{
				_28 = *pos;
				success_29 = true;
				_0 = _28;
			}
		}
		else 
		{
			success_27 = true;
			_0 = _26.token;
		}
	}
	else 
	{
		_0 = _2;
	}
	success_1 = true;
	pos += 2;
	Rule_rule_data data;
	data.qualifier = _4;
	data.val = _6;

	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::Rule_rule, data)};
}
Parser::Rule_res Parser::Parser::Rule_other(Token*& pos) {
	auto in = pos;
	::Parser::bool_t m = matched();
	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	::Parser::Token _2;
	::Parser::bool_t success_3 = false;
	::Parser::arr_t<::Parser::UNDEF> shadow_13;
	::Parser::bool_t success_5 = false;
	::Parser::Token _6;
	::Parser::bool_t success_7 = false;
	::Parser::arr_t<::Parser::Token> shadow_8;
	::Parser::Token _9;
	::Parser::bool_t success_10 = false;
	::Parser::arr_t<::Parser::Token> shadow_11;
	if (pos->name == Tokens::AUTO_107)
	{
		_0 = *pos;
		success_1 = true;
		pos += 2;
	}
	ISC_STD::skip_spaces(pos);
	if (!(pos->name == Tokens::ID))
	{
		return {};
	}
	_2 = *pos;
	success_3 = true;
	pos += 2;
	ISC_STD::skip_spaces(pos);
	auto begin_12 = pos;
	while (1)
	{
		if (!(begin_12->name == Tokens::AUTO_97))
		{
			break;
		}
		_6 = *begin_12;
		success_7 = true;
		begin_12 += 2;
		shadow_8.push_back(_6);
		ISC_STD::skip_spaces(pos);
		if (!(begin_12->name == Tokens::ID))
		{
			break;
		}
		_9 = *begin_12;
		success_10 = true;
		begin_12 += 2;
		shadow_11.push_back(_9);
		shadow_13.push_back(_4);
	}
	if (success_10)
	{
		success_5 = true;
		pos = begin_12;
	}
	Rule_other_data data;
	data.nested_name = shadow_11;
	data.name = _2;
	data.is_nested = m;

	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::Rule_other, data)};
}
Parser::Rule_res Parser::Parser::Rule_op(Token*& pos) {
	auto in = pos;
	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	::Parser::Token _2;
	::Parser::bool_t success_3 = false;
	::Parser::Token _4;
	::Parser::bool_t success_5 = false;
	::Parser::Token _6;
	::Parser::bool_t success_7 = false;
	data = _0;
	auto begin_8 = pos;
	if (!(begin_8->name == Tokens::AUTO_80))
	{
		if (!(begin_8->name == Tokens::AUTO_81))
		{
			return {};
		}
		else 
		{
			_6 = *begin_8;
			success_7 = true;
			_2 = _6;
		}
	}
	else 
	{
		_4 = *begin_8;
		success_5 = true;
		_2 = _4;
	}
	success_3 = true;
	begin_8 += 3;
	if (success_3)
	{
		success_1 = true;
		pos = begin_8;
	}
	_0 = _2;
	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::Rule_op)};
}
Parser::Rule_res Parser::Parser::Rule_qualifier(Token*& pos) {
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
	data = _0;
	auto begin_10 = pos;
	if (!(begin_10->name == Tokens::AUTO_82))
	{
		if (!(begin_10->name == Tokens::AUTO_83))
		{
			if (!(begin_10->name == Tokens::AUTO_84))
			{
				return {};
			}
			else 
			{
				_8 = *begin_10;
				success_9 = true;
				_2 = _8;
			}
		}
		else 
		{
			_6 = *begin_10;
			success_7 = true;
			_2 = _6;
		}
	}
	else 
	{
		_4 = *begin_10;
		success_5 = true;
		_2 = _4;
	}
	success_3 = true;
	begin_10 += 4;
	if (success_3)
	{
		success_1 = true;
		pos = begin_10;
	}
	_0 = _2;
	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::Rule_qualifier)};
}
Parser::Rule_res Parser::Parser::Rule_group(Token*& pos) {
	auto in = pos;
	::Parser::any_t name = _2;
	::Parser::any_t r = _11;
	::Parser::bool_t success_1 = false;
	::Parser::Token _2;
	::Parser::bool_t success_3 = false;
	::Parser::any_t _4;
	::Parser::bool_t success_5 = false;
	::Parser::Rule_res _6;
	::Parser::bool_t success_7 = false;
	::Parser::Token _8;
	::Parser::bool_t success_9 = false;
	::Parser::Token _11;
	::Parser::bool_t success_12 = false;
	::Parser::Rule_res _13;
	::Parser::bool_t success_14 = false;
	::Parser::Token _15;
	::Parser::bool_t success_16 = false;
	auto begin_10 = pos;
	do
	{
		if (!(begin_10->name == Tokens::AUTO_85))
		{
			break;
		}
		_2 = *begin_10;
		success_3 = true;
		begin_10 += 2;
		ISC_STD::skip_spaces(pos);
		_6 = method_call(begin_10);
		if (!(_6.result))
		{
			if (!(begin_10->name == Tokens::ID))
			{
				break;
			}
			else 
			{
				_8 = *begin_10;
				success_9 = true;
				_4 = _8;
			}
		}
		else 
		{
			success_7 = true;
			_4 = _6.token;
		}
		success_5 = true;
		begin_10 += 2;
	}	while(0)
;
	if (success_5)
	{
		success_1 = true;
		pos = begin_10;
	}
	ISC_STD::skip_spaces(pos);
	if (!(pos->name == Tokens::AUTO_86))
	{
		return {};
	}
	_11 = *pos;
	success_12 = true;
	pos += 2;
	ISC_STD::skip_spaces(pos);
	_13 = Rule_rule(pos);
	while (_13.result)
	{
		success_14 = true;
		pos += 1;
		_13 = Rule_rule(pos);
	}
	ISC_STD::skip_spaces(pos);
	if (!(pos->name == Tokens::AUTO_87))
	{
		return {};
	}
	_15 = *pos;
	success_16 = true;
	pos += 2;
	Rule_group_data data;
	data.val = r;
	data.variable = name;

	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::Rule_group, data)};
}
Parser::Rule_res Parser::Parser::Rule_csequence_symbol(Token*& pos) {
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
	data = _0;
	auto begin_10 = pos;
	if (!(begin_10->name == Tokens::AUTO_104))
	{
		if (!(begin_10->name == Tokens::AUTO_92))
		{
			if (!(begin_10->name == Tokens::AUTO_93))
			{
				return {};
			}
			else 
			{
				_8 = *begin_10;
				success_9 = true;
				_2 = _8;
			}
		}
		else 
		{
			_6 = *begin_10;
			success_7 = true;
			_2 = _6;
		}
	}
	else 
	{
		_4 = *begin_10;
		success_5 = true;
		_2 = _4;
	}
	success_3 = true;
	begin_10 += 4;
	if (success_3)
	{
		success_1 = true;
		pos = begin_10;
	}
	_0 = _2;
	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::Rule_csequence_symbol)};
}
Parser::Rule_res Parser::Parser::Rule_csequence_escape(Token*& pos) {
	auto in = pos;
	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	::Parser::Token _2;
	::Parser::bool_t success_3 = false;
	::Parser::Token _4;
	::Parser::bool_t success_5 = false;
	data = _2;
	if (!(pos->name == Tokens::AUTO_104))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos += 2;
	auto begin_6 = pos;
	if (!(begin_6->name == Tokens::AUTO_105))
	{
		return {};
	}
	_4 = *begin_6;
	success_5 = true;
	begin_6 += 2;
	if (success_5)
	{
		success_3 = true;
		pos = begin_6;
	}
	_2 = _4;
	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::Rule_csequence_escape)};
}
Parser::Rule_res Parser::Parser::Rule_csequence_diapason(Token*& pos) {
	auto in = pos;
	::Parser::bool_t success_1 = false;
	::Parser::Rule from;
	::Parser::bool_t success_2 = false;
	::Parser::Rule_res _3;
	::Parser::bool_t success_4 = false;
	::Parser::Token _6;
	::Parser::bool_t success_7 = false;
	::Parser::Rule to;
	::Parser::bool_t success_8 = false;
	::Parser::Rule_res _9;
	::Parser::bool_t success_10 = false;
	auto begin_12 = pos;
	auto begin_5 = begin_12;
	_3 = Rule_csequence_symbol(begin_5);
	if (!(_3.result))
	{
		return {};
	}
	success_4 = true;
	begin_5 += 1;
	if (success_4)
	{
		success_2 = true;
		begin_12 = begin_5;
	}
	from = _3.token;
	if (!(begin_12->name == Tokens::AUTO_96))
	{
		return {};
	}
	_6 = *begin_12;
	success_7 = true;
	begin_12 += 2;
	auto begin_11 = begin_12;
	_9 = Rule_csequence_symbol(begin_11);
	if (!(_9.result))
	{
		return {};
	}
	success_10 = true;
	begin_11 += 1;
	if (success_10)
	{
		success_8 = true;
		begin_12 = begin_11;
	}
	to = _9.token;
	if (success_8)
	{
		success_1 = true;
		pos = begin_12;
	}
	Rule_csequence_diapason_data data = {from,to};
	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::Rule_csequence_diapason, data)};
}
Parser::Rule_res Parser::Parser::Rule_csequence(Token*& pos) {
	auto in = pos;
	::Parser::bool_t m = matched();
	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	::Parser::Token _2;
	::Parser::bool_t success_3 = false;
	::Parser::arr_t<::Parser::Rule> shadow_17;
	::Parser::Rule dt;
	::Parser::bool_t success_4 = false;
	::Parser::arr_t<::Parser::Rule> _5;
	::Parser::bool_t success_6 = false;
	::Parser::Rule_res _7;
	::Parser::bool_t success_8 = false;
	::Parser::arr_t<::Parser::Rule> shadow_9;
	::Parser::Rule_res _10;
	::Parser::bool_t success_11 = false;
	::Parser::arr_t<::Parser::Rule> shadow_12;
	::Parser::Rule_res _13;
	::Parser::bool_t success_14 = false;
	::Parser::arr_t<::Parser::Rule> shadow_15;
	::Parser::Token _18;
	::Parser::bool_t success_19 = false;
	if (!(pos->name == Tokens::AUTO_88))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos += 2;
	ISC_STD::skip_spaces(pos);
	if (pos->name == Tokens::AUTO_89)
	{
		_2 = *pos;
		success_3 = true;
		pos += 2;
	}
	ISC_STD::skip_spaces(pos);
	auto begin_16 = pos;
	while (1)
	{
		_7 = Rule_csequence_escape(begin_16);
		if (!(_7.result))
		{
			_10 = Rule_csequence_symbol(begin_16);
			if (!(_10.result))
			{
				_13 = Rule_csequence_diapason(begin_16);
				if (!(_13.result))
				{
					break;
				}
				else 
				{
					success_14 = true;
					shadow_15.push_back(_13.token);
					_5 = shadow_15;
				}
			}
			else 
			{
				success_11 = true;
				shadow_12.push_back(_10.token);
				_5 = shadow_12;
			}
		}
		else 
		{
			success_8 = true;
			shadow_9.push_back(_7.token);
			_5 = shadow_9;
		}
		success_6 = true;
		begin_16 += 1;
		shadow_17.push_back(dt);
	}
	if (success_6)
	{
		success_4 = true;
		pos = begin_16;
	}
	dt = _5;
	ISC_STD::skip_spaces(pos);
	if (!(pos->name == Tokens::AUTO_90))
	{
		return {};
	}
	_18 = *pos;
	success_19 = true;
	pos += 2;
	Rule_csequence_data data;
	data.val = dt;
	data._not = m;

	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::Rule_csequence, data)};
}
Parser::Rule_res Parser::Parser::Rule_data_block_inclosed_map(Token*& pos) {
	auto in = pos;
	::Parser::Rule_res _0;
	::Parser::bool_t success_1 = false;
	::Parser::bool_t success_2 = false;
	_0 = Rule_data_block_key(pos);
	while (_0.result)
	{
		success_1 = true;
		pos += 1;
		_0 = Rule_data_block_key(pos);
		success_2 = true;
	}
	if (!success_2)
	{
		return {};
	}
	Rule_data_block_inclosed_map_data data = _0.token;
	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::Rule_data_block_inclosed_map, data)};
}
Parser::Rule_res Parser::Parser::Rule_data_block_key(Token*& pos) {
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
	::Parser::Rule _11;
	::Parser::bool_t success_12 = false;
	::Parser::Rule_res _13;
	::Parser::bool_t success_14 = false;
	::Parser::Rule_res _15;
	::Parser::bool_t success_16 = false;
	while (pos->name == Tokens::AUTO_102)
	{
		_0 = *pos;
		success_1 = true;
		pos += 2;
		shadow_2.push_back(_0);
		success_3 = true;
	}
	if (!success_3)
	{
		return {};
	}
	ISC_STD::skip_spaces(pos);
	auto begin_7 = pos;
	if (!(begin_7->name == Tokens::ID))
	{
		return {};
	}
	_5 = *begin_7;
	success_6 = true;
	begin_7 += 2;
	if (success_6)
	{
		success_4 = true;
		pos = begin_7;
	}
	name = _5;
	ISC_STD::skip_spaces(pos);
	if (!(pos->name == Tokens::AUTO_103))
	{
		return {};
	}
	_8 = *pos;
	success_9 = true;
	pos += 2;
	ISC_STD::skip_spaces(pos);
	auto begin_17 = pos;
	_13 = cll_ternary(begin_17);
	if (!(_13.result))
	{
		_15 = expr(begin_17);
		if (!(_15.result))
		{
			return {};
		}
		else 
		{
			success_16 = true;
			_11 = _15.token;
		}
	}
	else 
	{
		success_14 = true;
		_11 = _13.token;
	}
	success_12 = true;
	begin_17 += 1;
	if (success_12)
	{
		success_10 = true;
		pos = begin_17;
	}
	dt = _11;
	Rule_data_block_key_data data;
	data.val = dt;
	data.name = name;

	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::Rule_data_block_key, data)};
}
Parser::Rule_res Parser::Parser::Rule_data_block(Token*& pos) {
	auto in = pos;
	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	::Parser::arr_t<::Parser::Token> shadow_2;
	::Parser::bool_t success_3 = false;
	::Parser::Token _4;
	::Parser::bool_t success_5 = false;
	::Parser::Token _6;
	::Parser::bool_t success_7 = false;
	::Parser::Rule _8;
	::Parser::bool_t success_9 = false;
	::Parser::Rule_res _10;
	::Parser::bool_t success_11 = false;
	::Parser::Rule_res _12;
	::Parser::bool_t success_13 = false;
	::Parser::Token _14;
	::Parser::bool_t success_15 = false;
	while (pos->name == Tokens::AUTO_106)
	{
		_0 = *pos;
		success_1 = true;
		pos += 2;
		shadow_2.push_back(_0);
		success_3 = true;
	}
	if (!success_3)
	{
		return {};
	}
	ISC_STD::skip_spaces(pos);
	if (!(pos->name == Tokens::AUTO_99))
	{
		return {};
	}
	_4 = *pos;
	success_5 = true;
	pos += 2;
	ISC_STD::skip_spaces(pos);
	if (!(pos->name == Tokens::AUTO_103))
	{
		return {};
	}
	_6 = *pos;
	success_7 = true;
	pos += 2;
	ISC_STD::skip_spaces(pos);
	_10 = any_data(pos);
	if (!(_10.result))
	{
		_12 = Rule_data_block_inclosed_map(pos);
		if (!(_12.result))
		{
			return {};
		}
		else 
		{
			success_13 = true;
			_8 = _12.token;
		}
	}
	else 
	{
		success_11 = true;
		_8 = _10.token;
	}
	success_9 = true;
	pos += 1;
	ISC_STD::skip_spaces(pos);
	if (!(pos->name == Tokens::AUTO_101))
	{
		return {};
	}
	_14 = *pos;
	success_15 = true;
	pos += 2;
	Rule_data_block_data data = _8;
	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::Rule_data_block, data)};
}
Parser::Rule_res Parser::Parser::Rule_escaped(Token*& pos) {
	auto in = pos;
	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	::Parser::Token _2;
	::Parser::bool_t success_3 = false;
	::Parser::Token _4;
	::Parser::bool_t success_5 = false;
	if (!(pos->name == Tokens::AUTO_104))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos += 2;
	if (!(pos->name == Tokens::AUTO_105))
	{
		return {};
	}
	_2 = *pos;
	success_3 = true;
	pos += 2;
	if (pos->name == Tokens::NUMBER)
	{
		_4 = *pos;
		success_5 = true;
		pos += 2;
	}
	Rule_escaped_data data;
	data.num = _4;
	data.c = _2;

	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::Rule_escaped, data)};
}
Parser::Rule_res Parser::Parser::Rule_nested_rule(Token*& pos) {
	auto in = pos;
	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	::Parser::arr_t<::Parser::Token> shadow_2;
	::Parser::bool_t success_3 = false;
	::Parser::Token _4;
	::Parser::bool_t success_5 = false;
	::Parser::Token _6;
	::Parser::bool_t success_7 = false;
	while (pos->name == Tokens::AUTO_106)
	{
		_0 = *pos;
		success_1 = true;
		pos += 2;
		shadow_2.push_back(_0);
		success_3 = true;
	}
	if (!success_3)
	{
		return {};
	}
	ISC_STD::skip_spaces(pos);
	if (!(pos->name == Tokens::AUTO_107))
	{
		return {};
	}
	_4 = *pos;
	success_5 = true;
	pos += 2;
	if (!(pos->name == Tokens::AUTO_97))
	{
		return {};
	}
	_6 = *pos;
	success_7 = true;
	pos += 2;
	Rule_nested_rule_data data = _6;
	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::Rule_nested_rule, data)};
}
Parser::Rule_res Parser::Parser::Rule_hex(Token*& pos) {
	auto in = pos;
	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	::Parser::Token _2;
	::Parser::bool_t success_3 = false;
	::Parser::arr_t<::Parser::Token> shadow_4;
	::Parser::bool_t success_5 = false;
	if (!(pos->name == Tokens::AUTO_108))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos += 2;
	ISC_STD::skip_spaces(pos);
	while (pos->name == Tokens::AUTO_109)
	{
		_2 = *pos;
		success_3 = true;
		pos += 2;
		shadow_4.push_back(_2);
		success_5 = true;
	}
	if (!success_5)
	{
		return {};
	}
	Rule_hex_data data = shadow_4;
	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::Rule_hex, data)};
}
Parser::Rule_res Parser::Parser::Rule_bin(Token*& pos) {
	auto in = pos;
	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	::Parser::Token _2;
	::Parser::bool_t success_3 = false;
	::Parser::arr_t<::Parser::Token> shadow_4;
	::Parser::bool_t success_5 = false;
	if (!(pos->name == Tokens::AUTO_110))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos += 2;
	ISC_STD::skip_spaces(pos);
	while (pos->name == Tokens::AUTO_111)
	{
		_2 = *pos;
		success_3 = true;
		pos += 2;
		shadow_4.push_back(_2);
		success_5 = true;
	}
	if (!success_5)
	{
		return {};
	}
	Rule_bin_data data = shadow_4;
	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::Rule_bin, data)};
}
Parser::Rule_res Parser::Parser::Rule(Token*& pos) {
	auto in = pos;
	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	::Parser::Token _2;
	::Parser::bool_t success_3 = false;
	::Parser::Rule_res _4;
	::Parser::bool_t success_5 = false;
	::Parser::Rule_res _6;
	::Parser::bool_t success_7 = false;
	::Parser::Rule_res _8;
	::Parser::bool_t success_9 = false;
	::Parser::Token _10;
	::Parser::bool_t success_11 = false;
	if (!(pos->name == Tokens::ID))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos += 2;
	ISC_STD::skip_spaces(pos);
	if (!(pos->name == Tokens::AUTO_103))
	{
		return {};
	}
	_2 = *pos;
	success_3 = true;
	pos += 2;
	ISC_STD::skip_spaces(pos);
	_4 = Rule_rule(pos);
	while (_4.result)
	{
		success_5 = true;
		pos += 1;
		_4 = Rule_rule(pos);
	}
	ISC_STD::skip_spaces(pos);
	_6 = Rule_data_block(pos);
	if (!(_6.result))
	{
		return {};
	}
	success_7 = true;
	pos += 1;
	ISC_STD::skip_spaces(pos);
	_8 = Rule_nested_rule(pos);
	while (_8.result)
	{
		success_9 = true;
		pos += 1;
		_8 = Rule_nested_rule(pos);
	}
	ISC_STD::skip_spaces(pos);
	if (!(pos->name == Tokens::AUTO_101))
	{
		return {};
	}
	_10 = *pos;
	success_11 = true;
	pos += 2;
	Rule_data data;
	data.nestedRules = _8.token;
	data.data_block = _6.token;
	data.rule = _4.token;
	data.name = _0;

	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::Rule, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_1(const char* &pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == '%'))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 1);
	success_1 = true;
	pos += 2;
	AUTO_1_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_1, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_3(const char* &pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == '>'))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 1);
	success_1 = true;
	pos += 2;
	AUTO_3_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_3, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_4(const char* &pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == '$'))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 1);
	success_1 = true;
	pos += 2;
	AUTO_4_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_4, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_14(const char* &pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!std::strncmp(pos, "unsigned", 8)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 8);
	success_1 = true;
	pos += 9;
	AUTO_14_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_14, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_15(const char* &pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!std::strncmp(pos, "char", 4)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 4);
	success_1 = true;
	pos += 5;
	AUTO_15_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_15, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_16(const char* &pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!std::strncmp(pos, "short", 5)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 5);
	success_1 = true;
	pos += 6;
	AUTO_16_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_16, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_17(const char* &pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!std::strncmp(pos, "int", 3)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 3);
	success_1 = true;
	pos += 4;
	AUTO_17_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_17, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_18(const char* &pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!std::strncmp(pos, "long", 4)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 4);
	success_1 = true;
	pos += 5;
	AUTO_18_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_18, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_19(const char* &pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!std::strncmp(pos, "long long", 9)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 9);
	success_1 = true;
	pos += 10;
	AUTO_19_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_19, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_20(const char* &pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!std::strncmp(pos, "float", 5)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 5);
	success_1 = true;
	pos += 6;
	AUTO_20_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_20, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_21(const char* &pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!std::strncmp(pos, "double", 6)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 6);
	success_1 = true;
	pos += 7;
	AUTO_21_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_21, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_22(const char* &pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!std::strncmp(pos, "deque", 5)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 5);
	success_1 = true;
	pos += 6;
	AUTO_22_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_22, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_23(const char* &pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!std::strncmp(pos, "vector", 6)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 6);
	success_1 = true;
	pos += 7;
	AUTO_23_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_23, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_24(const char* &pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!std::strncmp(pos, "queue", 5)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 5);
	success_1 = true;
	pos += 6;
	AUTO_24_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_24, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_25(const char* &pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!std::strncmp(pos, "stack", 5)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 5);
	success_1 = true;
	pos += 6;
	AUTO_25_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_25, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_26(const char* &pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!std::strncmp(pos, "list", 4)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 4);
	success_1 = true;
	pos += 5;
	AUTO_26_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_26, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_27(const char* &pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!std::strncmp(pos, "forward_list", 12)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 12);
	success_1 = true;
	pos += 13;
	AUTO_27_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_27, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_28(const char* &pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!std::strncmp(pos, "var", 3)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 3);
	success_1 = true;
	pos += 4;
	AUTO_28_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_28, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_29(const char* &pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!std::strncmp(pos, "any", 3)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 3);
	success_1 = true;
	pos += 4;
	AUTO_29_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_29, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_30(const char* &pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!std::strncmp(pos, "num", 3)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 3);
	success_1 = true;
	pos += 4;
	AUTO_30_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_30, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_31(const char* &pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!std::strncmp(pos, "bool", 4)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 4);
	success_1 = true;
	pos += 5;
	AUTO_31_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_31, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_32(const char* &pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!std::strncmp(pos, "str", 3)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 3);
	success_1 = true;
	pos += 4;
	AUTO_32_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_32, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_33(const char* &pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!std::strncmp(pos, "arr", 3)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 3);
	success_1 = true;
	pos += 4;
	AUTO_33_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_33, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_34(const char* &pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!std::strncmp(pos, "obj", 3)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 3);
	success_1 = true;
	pos += 4;
	AUTO_34_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_34, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_35(const char* &pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!std::strncmp(pos, "if", 2)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 2);
	success_1 = true;
	pos += 3;
	AUTO_35_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_35, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_46(const char* &pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!std::strncmp(pos, "fn", 2)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 2);
	success_1 = true;
	pos += 3;
	AUTO_46_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_46, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_47(const char* &pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!std::strncmp(pos, "while", 5)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 5);
	success_1 = true;
	pos += 6;
	AUTO_47_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_47, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_53(const char* &pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == '='))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 1);
	success_1 = true;
	pos += 2;
	AUTO_53_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_53, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_58(const char* &pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!std::strncmp(pos, "++", 2)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 2);
	success_1 = true;
	pos += 3;
	AUTO_58_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_58, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_59(const char* &pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!std::strncmp(pos, "--", 2)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 2);
	success_1 = true;
	pos += 3;
	AUTO_59_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_59, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_63(const char* &pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == '{'))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 1);
	success_1 = true;
	pos += 2;
	AUTO_63_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_63, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_68(const char* &pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == '}'))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 1);
	success_1 = true;
	pos += 2;
	AUTO_68_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_68, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_69(const char* &pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!std::strncmp(pos, "spacemode", 9)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 9);
	success_1 = true;
	pos += 10;
	AUTO_69_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_69, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_70(const char* &pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!std::strncmp(pos, "mixed", 5)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 5);
	success_1 = true;
	pos += 6;
	AUTO_70_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_70, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_71(const char* &pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!std::strncmp(pos, "skipped", 7)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 7);
	success_1 = true;
	pos += 8;
	AUTO_71_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_71, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_72(const char* &pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!std::strncmp(pos, "allowed", 7)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 7);
	success_1 = true;
	pos += 8;
	AUTO_72_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_72, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_73(const char* &pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!std::strncmp(pos, "//", 2)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 2);
	success_1 = true;
	pos += 3;
	AUTO_73_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_73, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_74(const char* &pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!(*(pos + 0) == '\n')))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 0);
	success_1 = true;
	pos += 1;
	AUTO_74_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_74, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_75(const char* &pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!std::strncmp(pos, "use", 3)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 3);
	success_1 = true;
	pos += 4;
	AUTO_75_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_75, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_76(const char* &pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == ','))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 1);
	success_1 = true;
	pos += 2;
	AUTO_76_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_76, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_80(const char* &pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == '|'))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 1);
	success_1 = true;
	pos += 2;
	AUTO_80_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_80, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_81(const char* &pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!std::strncmp(pos, "|&", 2)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 2);
	success_1 = true;
	pos += 3;
	AUTO_81_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_81, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_82(const char* &pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == '?'))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 1);
	success_1 = true;
	pos += 2;
	AUTO_82_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_82, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_83(const char* &pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == '+'))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 1);
	success_1 = true;
	pos += 2;
	AUTO_83_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_83, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_84(const char* &pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == '*'))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 1);
	success_1 = true;
	pos += 2;
	AUTO_84_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_84, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_85(const char* &pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == '&'))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 1);
	success_1 = true;
	pos += 2;
	AUTO_85_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_85, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_86(const char* &pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == '('))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 1);
	success_1 = true;
	pos += 2;
	AUTO_86_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_86, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_87(const char* &pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == ')'))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 1);
	success_1 = true;
	pos += 2;
	AUTO_87_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_87, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_88(const char* &pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == '['))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 1);
	success_1 = true;
	pos += 2;
	AUTO_88_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_88, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_89(const char* &pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == '^'))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 1);
	success_1 = true;
	pos += 2;
	AUTO_89_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_89, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_90(const char* &pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == ']'))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 1);
	success_1 = true;
	pos += 2;
	AUTO_90_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_90, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_92(const char* &pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!std::strncmp(pos, "\\]", 2)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 2);
	success_1 = true;
	pos += 3;
	AUTO_92_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_92, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_93(const char* &pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!(*(pos + 0) == ']')))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 0);
	success_1 = true;
	pos += 1;
	AUTO_93_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_93, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_96(const char* &pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == '-'))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 1);
	success_1 = true;
	pos += 2;
	AUTO_96_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_96, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_97(const char* &pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == '.'))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 1);
	success_1 = true;
	pos += 2;
	AUTO_97_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_97, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_99(const char* &pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!std::strncmp(pos, "data", 4)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 4);
	success_1 = true;
	pos += 5;
	AUTO_99_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_99, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_101(const char* &pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == ';'))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 1);
	success_1 = true;
	pos += 2;
	AUTO_101_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_101, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_102(const char* &pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == '\n' || *(pos + 0) == '\r'))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 0);
	success_1 = true;
	pos += 1;
	AUTO_102_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_102, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_103(const char* &pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == ':'))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 1);
	success_1 = true;
	pos += 2;
	AUTO_103_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_103, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_104(const char* &pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!std::strncmp(pos, "\\", 1)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 1);
	success_1 = true;
	pos += 2;
	AUTO_104_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_104, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_105(const char* &pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (*(pos + 0) == '\0')
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 1);
	success_1 = true;
	pos += 2;
	AUTO_105_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_105, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_106(const char* &pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == '\r' || *(pos + 0) == '\n'))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 0);
	success_1 = true;
	pos += 1;
	AUTO_106_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_106, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_107(const char* &pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == '#'))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 1);
	success_1 = true;
	pos += 2;
	AUTO_107_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_107, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_108(const char* &pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!std::strncmp(pos, "0x", 2)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 2);
	success_1 = true;
	pos += 3;
	AUTO_108_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_108, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_109(const char* &pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!((*(pos + 0)>='1' && *(pos + 0)<='9') || (*(pos + 0)>='A' && *(pos + 0)<='F') || (*(pos + 0)>='a' && *(pos + 0)<='f')))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 0);
	success_1 = true;
	pos += 1;
	AUTO_109_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_109, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_110(const char* &pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!std::strncmp(pos, "0b", 2)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 2);
	success_1 = true;
	pos += 3;
	AUTO_110_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_110, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_111(const char* &pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == '0' || *(pos + 0) == '1'))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 0);
	success_1 = true;
	pos += 1;
	AUTO_111_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_111, data)};
}
Parser::Token_res Parser::Tokenizator::__WHITESPACE(const char* &pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	::Parser::arr_t<::Parser::str_t> shadow_2;
	while (*(pos + 0) == ' ' || *(pos + 0) == '\t' || *(pos + 0) == '\n' || *(pos + 0) == '\r' || *(pos + 0) == '\v' || *(pos + 0) == '\f')
	{
		_0 += ::Parser::str_t(pos, 0);
		success_1 = true;
		pos += 1;
		shadow_2.push_back(_0);
	}
	return {true, ::Parser::Token(in - str, in, pos, Tokens::__WHITESPACE)};
}
