#include "Parser.h"
Parser::Parser::Rule_res accessor_group(Token* &pos, const Token_sequence &tokens) {
	Token _0;
	bool success_1 = false;
	Token _2;
	bool success_3 = false;
	if (!(*token == Tokens::AUTO_4))
	{
		return {}
	}
	_0 = pos;
	success_1 = true;
	pos++;
	skipspaces(pos);
	if (!(*token == Tokens::NUMBER))
	{
		return {}
	}
	_2 = pos;
	success_3 = true;
	pos++;
	accessor_group_data data = _2;
}
Parser::Parser::Rule_res accessor_element(Token* &pos, const Token_sequence &tokens) {
	Token _0;
	bool success_1 = false;
	Token _2;
	bool success_3 = false;
	if (!(*token == Tokens::AUTO_1))
	{
		return {}
	}
	_0 = pos;
	success_1 = true;
	pos++;
	skipspaces(pos);
	if (!(*token == Tokens::NUMBER))
	{
		return {}
	}
	_2 = pos;
	success_3 = true;
	pos++;
	accessor_element_data data = _2;
}
Parser::Parser::Rule_res accessor_char(Token* &pos, const Token_sequence &tokens) {
	Token _0;
	bool success_1 = false;
	Token _2;
	bool success_3 = false;
	if (!(*token == Tokens::AUTO_90))
	{
		return {}
	}
	_0 = pos;
	success_1 = true;
	pos++;
	skipspaces(pos);
	if (!(*token == Tokens::NUMBER))
	{
		return {}
	}
	_2 = pos;
	success_3 = true;
	pos++;
	accessor_char_data data = _2;
}
Parser::Parser::Rule_res accessor_all(Token* &pos, const Token_sequence &tokens) {
	Rule _0;
	bool success_1 = false;
	Rule _2;
	bool success_3 = false;
	Rule _4;
	bool success_5 = false;
	Rule _6;
	bool success_7 = false;
	_2 = accessor_group(tokens);
	if (!(_2.status))
	{
		_4 = accessor_element(tokens);
		if (!(_4.status))
		{
			_6 = accessor_char(tokens);
			if (!(_6.status))
			{
				return {}
			}
			else 
			{
				success_7 = true;
				_0 = _6;
			}
		}
		else 
		{
			success_5 = true;
			_0 = _4;
		}
	}
	else 
	{
		success_3 = true;
		_0 = _2;
	}
	_0 += *(pos + 0);
	success_1 = true;
	pos++;
	accessor_all_data data = _0;
}
Parser::Parser::Rule_res accessor(Token* &pos, const Token_sequence &tokens) {
	Rule _0;
	bool success_1 = false;
	arr_t<str_t> shadow_9;
	str_t _2;
	bool success_3 = false;
	Token _4;
	bool success_5 = false;
	Rule _6;
	bool success_7 = false;
	_0 = accessor_all(tokens);
	if (!(_0.status))
	{
		return {}
	}
	success_1 = true;
	pos++;
	skipspaces(pos);
	auto begin_8 = pos;
	while (1)
	{
		if (!(*token == Tokens::AUTO_3))
		{
			break;
		}
		_4 = pos;
		success_5 = true;
		begin_8++;
		skipspaces(pos);
		_6 = accessor_all(tokens);
		if (!(_6.status))
		{
			break;
		}
		success_7 = true;
		begin_8++;
		shadow_9.push(_2);
	}
	if (success_7)
	{
		success_3 = true;
		pos = begin_8;
	}
	_2 += _4;
	_2 += _6;
	accessor_data data;
	data.second = _6;
	data.first = _0;

}
Parser::Parser::Rule_res cll(Token* &pos, const Token_sequence &tokens) {
	Token cll_begin;
	bool success_0 = false;
	Token _1;
	bool success_2 = false;
	arr_t<str_t> shadow_28;
	str_t _4;
	bool success_5 = false;
	bool success_29 = false;
	Rule _6;
	bool success_7 = false;
	Rule _8;
	bool success_9 = false;
	Rule _10;
	bool success_11 = false;
	Rule _12;
	bool success_13 = false;
	Rule _14;
	bool success_15 = false;
	Rule _16;
	bool success_17 = false;
	Rule _18;
	bool success_19 = false;
	Rule _20;
	bool success_21 = false;
	Rule _22;
	bool success_23 = false;
	Token _25;
	bool success_26 = false;
	auto begin_3 = pos;
	if (!(*token == Tokens::AUTO_4))
	{
		return {}
	}
	_1 = pos;
	success_2 = true;
	begin_3++;
	if (success_2)
	{
		success_0 = true;
		pos = begin_3;
	}
	cll_begin = _1;
	skipspaces(pos);
	auto begin_27 = pos;
	while (1)
	{
		auto begin_24 = begin_27;
		_10 = cll_var(tokens);
		if (!(_10.status))
		{
			_12 = cll_if(tokens);
			if (!(_12.status))
			{
				_14 = expr(tokens);
				if (!(_14.status))
				{
					_16 = copiable_method_call(tokens);
					if (!(_16.status))
					{
						_18 = method_call(tokens);
						if (!(_18.status))
						{
							_20 = loop_while(tokens);
							if (!(_20.status))
							{
								_22 = loop_for(tokens);
								if (!(_22.status))
								{
									break;
								}
								else 
								{
									success_23 = true;
									_8 = _22;
								}
							}
							else 
							{
								success_21 = true;
								_8 = _20;
							}
						}
						else 
						{
							success_19 = true;
							_8 = _18;
						}
					}
					else 
					{
						success_17 = true;
						_8 = _16;
					}
				}
				else 
				{
					success_15 = true;
					_8 = _14;
				}
			}
			else 
			{
				success_13 = true;
				_8 = _12;
			}
		}
		else 
		{
			success_11 = true;
			_8 = _10;
		}
		_8 += *(pos + 0);
		success_9 = true;
		begin_24++;
		if (success_9)
		{
			success_7 = true;
			begin_27 = begin_24;
		}
		_6 = _8;
		skipspaces(pos);
		if (!(*token == Tokens::END))
		{
			break;
		}
		_25 = pos;
		success_26 = true;
		begin_27++;
		shadow_28.push(_4);
		success_29 = true;
	}
	if (!success_29)
	{
		return {}
	}
	if (success_26)
	{
		success_5 = true;
		pos = begin_27;
	}
	_4 += _6;
	_4 += _25;
	cll_data data = shadow_28;
}
Parser::Parser::Rule_res cll_block(Token* &pos, const Token_sequence &tokens) {
	Token _0;
	bool success_1 = false;
	Rule _2;
	bool success_3 = false;
	arr_t<Rule> shadow_4;
	Token _5;
	bool success_6 = false;
	if (!(*token == Tokens::AUTO_64))
	{
		return {}
	}
	_0 = pos;
	success_1 = true;
	pos++;
	skipspaces(pos);
	_2 = Rule_rule(tokens);
	while (_2.status)
	{
		success_3 = true;
		pos++;
		shadow_4.push(_2);
		_2 = Rule_rule(tokens);
	}
	skipspaces(pos);
	if (!(*token == Tokens::AUTO_69))
	{
		return {}
	}
	_5 = pos;
	success_6 = true;
	pos++;
	cll_block_data data = _2;
}
Parser::Parser::Rule_res cll_spaced_block(Token* &pos, const Token_sequence &tokens) {
	Rule _0;
	bool success_1 = false;
	while ((skipup(" ")>spaces_amount))
	{
		_0 = Rule_rule(tokens);
		if (!(_0.status))
		{
			return {}
		}
		success_1 = true;
		pos++;
		skipspaces(pos);
	}
	cll_spaced_block_data data = _0;
}
Parser::Tokenizator::Token_res OP(const char* pos, const char* const str) {
	any_t _0;
	bool success_1 = false;
	str_t _2;
	bool success_3 = false;
	if (!(*pos == '+'))
	{
		str_t _4;
		bool success_5 = false;
		if (!(*pos == '-'))
		{
			str_t _6;
			bool success_7 = false;
			if (!(*pos == '*'))
			{
				str_t _8;
				bool success_9 = false;
				if (!(*pos == '/'))
				{
					str_t _10;
					bool success_11 = false;
					if (!(*pos == '%'))
					{
					}
					else 
					{
						_10 += *(pos + 0);
						success_11 = true;
						_0 = _10;
					}
				}
				else 
				{
					_8 += *(pos + 0);
					success_9 = true;
					_0 = _8;
				}
			}
			else 
			{
				_6 += *(pos + 0);
				success_7 = true;
				_0 = _6;
			}
		}
		else 
		{
			_4 += *(pos + 0);
			success_5 = true;
			_0 = _4;
		}
	}
	else 
	{
		_2 += *(pos + 0);
		success_3 = true;
		_0 = _2;
	}
	_0 += *(pos + 0);
	success_1 = true;
	pos++;
	skipspaces(pos);
	str_t _12;
	bool success_13 = false;
	str_t _14;
	bool success_15 = false;
	if (!(*pos == '&'))
	{
		str_t _16;
		bool success_17 = false;
		if (!(*pos == '|'))
		{
			str_t _18;
			bool success_19 = false;
			if (!(*pos == '^'))
			{
				str_t _20;
				bool success_21 = false;
				if (!(!std::strncmp(pos, "<<", 2)))
				{
					str_t _22;
					bool success_23 = false;
					if (!(!std::strncmp(pos, ">>", 2)))
					{
						return {}
					}
					else 
					{
						_22 += *(pos + 0);
						success_23 = true;
						_12 = _22;
					}
				}
				else 
				{
					_20 += *(pos + 0);
					success_21 = true;
					_12 = _20;
				}
			}
			else 
			{
				_18 += *(pos + 0);
				success_19 = true;
				_12 = _18;
			}
		}
		else 
		{
			_16 += *(pos + 0);
			success_17 = true;
			_12 = _16;
		}
	}
	else 
	{
		_14 += *(pos + 0);
		success_15 = true;
		_12 = _14;
	}
	_12 += *(pos + 0);
	success_13 = true;
	pos++;
	OP_data data = _0;
}
Parser::Tokenizator::Token_res ASSIGNMENT_OP(const char* pos, const char* const str) {
	Token _0;
	bool success_1 = false;
	_0 = OP(tokens);
	if (_0.status)
	{
		success_1 = true;
		pos++;
	}
	skipspaces(pos);
	Token _2;
	bool success_3 = false;
	_2 = AUTO_54(tokens);
	if (!(_2.status))
	{
		return {}
	}
	success_3 = true;
	pos++;
	ASSIGNMENT_OP_data data = _0;
}
Parser::Tokenizator::Token_res COMPARE_OP(const char* pos, const char* const str) {
	str_t _0;
	bool success_1 = false;
	str_t _2;
	bool success_3 = false;
	if (!(!std::strncmp(pos, "==", 2)))
	{
		str_t _4;
		bool success_5 = false;
		if (!(!std::strncmp(pos, "!=", 2)))
		{
			str_t _6;
			bool success_7 = false;
			if (!(*pos == '>'))
			{
				str_t _8;
				bool success_9 = false;
				if (!(*pos == '<'))
				{
					str_t _10;
					bool success_11 = false;
					if (!(!std::strncmp(pos, ">=", 2)))
					{
						str_t _12;
						bool success_13 = false;
						if (!(!std::strncmp(pos, "<=", 2)))
						{
							return {}
						}
						else 
						{
							_12 += *(pos + 0);
							success_13 = true;
							_0 = _12;
						}
					}
					else 
					{
						_10 += *(pos + 0);
						success_11 = true;
						_0 = _10;
					}
				}
				else 
				{
					_8 += *(pos + 0);
					success_9 = true;
					_0 = _8;
				}
			}
			else 
			{
				_6 += *(pos + 0);
				success_7 = true;
				_0 = _6;
			}
		}
		else 
		{
			_4 += *(pos + 0);
			success_5 = true;
			_0 = _4;
		}
	}
	else 
	{
		_2 += *(pos + 0);
		success_3 = true;
		_0 = _2;
	}
	_0 += *(pos + 0);
	success_1 = true;
	pos++;
	COMPARE_OP_data data = _0;
}
Parser::Tokenizator::Token_res LOGICAL_OP(const char* pos, const char* const str) {
	Token _0;
	bool success_1 = false;
	Token _2;
	bool success_3 = false;
	_2 = LOGICAL_AND(tokens);
	if (!(_2.status))
	{
		Token _4;
		bool success_5 = false;
		_4 = LOGICAL_OR(tokens);
		if (!(_4.status))
		{
			return {}
		}
		else 
		{
			success_5 = true;
			_0 = _4;
		}
	}
	else 
	{
		success_3 = true;
		_0 = _2;
	}
	_0 += *(pos + 0);
	success_1 = true;
	pos++;
	LOGICAL_OP_data data = _0;
}
Parser::Tokenizator::Token_res LOGICAL_NOT(const char* pos, const char* const str) {
	str_t _0;
	bool success_1 = false;
	str_t _2;
	bool success_3 = false;
	if (!(*pos == '!'))
	{
		str_t _4;
		bool success_5 = false;
		if (!(!std::strncmp(pos, "not", 3)))
		{
			return {}
		}
		else 
		{
			_4 += *(pos + 0);
			success_5 = true;
			_0 = _4;
		}
	}
	else 
	{
		_2 += *(pos + 0);
		success_3 = true;
		_0 = _2;
	}
	_0 += *(pos + 0);
	success_1 = true;
	pos++;
	LOGICAL_NOT_data data = _0;
}
Parser::Tokenizator::Token_res LOGICAL_AND(const char* pos, const char* const str) {
	str_t _0;
	bool success_1 = false;
	str_t _2;
	bool success_3 = false;
	if (!(!std::strncmp(pos, "&&", 2)))
	{
		str_t _4;
		bool success_5 = false;
		if (!(!std::strncmp(pos, "and", 3)))
		{
			return {}
		}
		else 
		{
			_4 += *(pos + 0);
			success_5 = true;
			_0 = _4;
		}
	}
	else 
	{
		_2 += *(pos + 0);
		success_3 = true;
		_0 = _2;
	}
	_0 += *(pos + 0);
	success_1 = true;
	pos++;
	LOGICAL_AND_data data = _0;
}
Parser::Tokenizator::Token_res LOGICAL_OR(const char* pos, const char* const str) {
	str_t _0;
	bool success_1 = false;
	str_t _2;
	bool success_3 = false;
	if (!(!std::strncmp(pos, "||", 2)))
	{
		str_t _4;
		bool success_5 = false;
		if (!(!std::strncmp(pos, "or", 2)))
		{
			return {}
		}
		else 
		{
			_4 += *(pos + 0);
			success_5 = true;
			_0 = _4;
		}
	}
	else 
	{
		_2 += *(pos + 0);
		success_3 = true;
		_0 = _2;
	}
	_0 += *(pos + 0);
	success_1 = true;
	pos++;
	LOGICAL_OR_data data = _0;
}
Parser::Tokenizator::Token_res LOGICAL_ANDR(const char* pos, const char* const str) {
	any_t _0;
	bool success_1 = false;
	str_t _2;
	bool success_3 = false;
	if (!(!std::strncmp(pos, "|&", 2)))
	{
		str_t _4;
		bool success_5 = false;
		auto begin_12 = pos;
		do
		{
			str_t _6;
			bool success_7 = false;
			if (!(!std::strncmp(pos, "and", 3)))
			{
				break;
			}
			_6 += *(pos + 0);
			success_7 = true;
			begin_12++;
			str_t _8;
			bool success_9 = false;
			if (*pos != ' ')
			{
				break;
			}
			_8 += *(pos + 0);
			success_9 = true;
			begin_12++;
			str_t _10;
			bool success_11 = false;
			if (!(!std::strncmp(pos, "or", 2)))
			{
				break;
			}
			_10 += *(pos + 0);
			success_11 = true;
			begin_12++;
		}		while(0)
;
		if (success_11)
		{
			success_5 = true;
			pos = begin_12;
		}
		_4 += _6;
		_4 += _8;
		_4 += _10;
		if (!success_5)
		{
			return {}
		}
		else 
		{
			_0 = _4;
		}
	}
	else 
	{
		_2 += *(pos + 0);
		success_3 = true;
		_0 = _2;
	}
	_0 += *(pos + 0);
	success_1 = true;
	pos++;
	LOGICAL_ANDR_data data = _6;
}
Parser::Parser::Rule_res cll_template_content_typename(Token* &pos, const Token_sequence &tokens) {
	Rule _0;
	bool success_1 = false;
	arr_t<str_t> shadow_9;
	str_t _2;
	bool success_3 = false;
	Token _4;
	bool success_5 = false;
	Rule _6;
	bool success_7 = false;
	_0 = cll_type(tokens);
	if (!(_0.status))
	{
		return {}
	}
	success_1 = true;
	pos++;
	skipspaces(pos);
	auto begin_8 = pos;
	while (1)
	{
		if (!(*token == Tokens::AUTO_8))
		{
			break;
		}
		_4 = pos;
		success_5 = true;
		begin_8++;
		skipspaces(pos);
		_6 = cll_type(tokens);
		if (!(_6.status))
		{
			break;
		}
		success_7 = true;
		begin_8++;
		shadow_9.push(_2);
	}
	if (success_7)
	{
		success_3 = true;
		pos = begin_8;
	}
	_2 += _4;
	_2 += _6;
	cll_template_content_typename_data data = {,};
}
Parser::Parser::Rule_res cll_template_content_int(Token* &pos, const Token_sequence &tokens) {
	Token _0;
	bool success_1 = false;
	arr_t<str_t> shadow_9;
	str_t _2;
	bool success_3 = false;
	Token _4;
	bool success_5 = false;
	Token _6;
	bool success_7 = false;
	if (!(*token == Tokens::NUMBER))
	{
		return {}
	}
	_0 = pos;
	success_1 = true;
	pos++;
	skipspaces(pos);
	auto begin_8 = pos;
	while (1)
	{
		if (!(*token == Tokens::AUTO_9))
		{
			break;
		}
		_4 = pos;
		success_5 = true;
		begin_8++;
		skipspaces(pos);
		if (!(*token == Tokens::NUMBER))
		{
			break;
		}
		_6 = pos;
		success_7 = true;
		begin_8++;
		shadow_9.push(_2);
	}
	if (success_7)
	{
		success_3 = true;
		pos = begin_8;
	}
	_2 += _4;
	_2 += _6;
	cll_template_content_int_data data = {,};
}
Parser::Parser::Rule_res cll_template_content_bool(Token* &pos, const Token_sequence &tokens) {
	Token _0;
	bool success_1 = false;
	arr_t<str_t> shadow_9;
	str_t _2;
	bool success_3 = false;
	Token _4;
	bool success_5 = false;
	Token _6;
	bool success_7 = false;
	if (!(*token == Tokens::BOOLEAN))
	{
		return {}
	}
	_0 = pos;
	success_1 = true;
	pos++;
	skipspaces(pos);
	auto begin_8 = pos;
	while (1)
	{
		if (!(*token == Tokens::AUTO_10))
		{
			break;
		}
		_4 = pos;
		success_5 = true;
		begin_8++;
		skipspaces(pos);
		if (!(*token == Tokens::BOOLEAN))
		{
			break;
		}
		_6 = pos;
		success_7 = true;
		begin_8++;
		shadow_9.push(_2);
	}
	if (success_7)
	{
		success_3 = true;
		pos = begin_8;
	}
	_2 += _4;
	_2 += _6;
	cll_template_content_bool_data data = {,};
}
Parser::Parser::Rule_res cll_template_content_str(Token* &pos, const Token_sequence &tokens) {
	Token _0;
	bool success_1 = false;
	arr_t<str_t> shadow_9;
	str_t _2;
	bool success_3 = false;
	Token _4;
	bool success_5 = false;
	Token _6;
	bool success_7 = false;
	if (!(*token == Tokens::STRING))
	{
		return {}
	}
	_0 = pos;
	success_1 = true;
	pos++;
	skipspaces(pos);
	auto begin_8 = pos;
	while (1)
	{
		if (!(*token == Tokens::AUTO_11))
		{
			break;
		}
		_4 = pos;
		success_5 = true;
		begin_8++;
		skipspaces(pos);
		if (!(*token == Tokens::STRING))
		{
			break;
		}
		_6 = pos;
		success_7 = true;
		begin_8++;
		shadow_9.push(_2);
	}
	if (success_7)
	{
		success_3 = true;
		pos = begin_8;
	}
	_2 += _4;
	_2 += _6;
	cll_template_content_str_data data = {,};
}
Parser::Parser::Rule_res cll_template_content_arr(Token* &pos, const Token_sequence &tokens) {
	Rule _0;
	bool success_1 = false;
	arr_t<str_t> shadow_9;
	str_t _2;
	bool success_3 = false;
	Token _4;
	bool success_5 = false;
	Rule _6;
	bool success_7 = false;
	_0 = array(tokens);
	if (!(_0.status))
	{
		return {}
	}
	success_1 = true;
	pos++;
	skipspaces(pos);
	auto begin_8 = pos;
	while (1)
	{
		if (!(*token == Tokens::AUTO_12))
		{
			break;
		}
		_4 = pos;
		success_5 = true;
		begin_8++;
		skipspaces(pos);
		_6 = array(tokens);
		if (!(_6.status))
		{
			break;
		}
		success_7 = true;
		begin_8++;
		shadow_9.push(_2);
	}
	if (success_7)
	{
		success_3 = true;
		pos = begin_8;
	}
	_2 += _4;
	_2 += _6;
	cll_template_content_arr_data data = {,};
}
Parser::Parser::Rule_res cll_template_content_obj(Token* &pos, const Token_sequence &tokens) {
	Rule _0;
	bool success_1 = false;
	arr_t<str_t> shadow_9;
	str_t _2;
	bool success_3 = false;
	Token _4;
	bool success_5 = false;
	Rule _6;
	bool success_7 = false;
	_0 = object(tokens);
	if (!(_0.status))
	{
		return {}
	}
	success_1 = true;
	pos++;
	skipspaces(pos);
	auto begin_8 = pos;
	while (1)
	{
		if (!(*token == Tokens::AUTO_13))
		{
			break;
		}
		_4 = pos;
		success_5 = true;
		begin_8++;
		skipspaces(pos);
		_6 = object(tokens);
		if (!(_6.status))
		{
			break;
		}
		success_7 = true;
		begin_8++;
		shadow_9.push(_2);
	}
	if (success_7)
	{
		success_3 = true;
		pos = begin_8;
	}
	_2 += _4;
	_2 += _6;
	cll_template_content_obj_data data = {,};
}
Parser::Parser::Rule_res cll_template_content_any_data(Token* &pos, const Token_sequence &tokens) {
	Rule _0;
	bool success_1 = false;
	arr_t<str_t> shadow_9;
	str_t _2;
	bool success_3 = false;
	Token _4;
	bool success_5 = false;
	Rule _6;
	bool success_7 = false;
	_0 = any_data(tokens);
	if (!(_0.status))
	{
		return {}
	}
	success_1 = true;
	pos++;
	skipspaces(pos);
	auto begin_8 = pos;
	while (1)
	{
		if (!(*token == Tokens::AUTO_62))
		{
			break;
		}
		_4 = pos;
		success_5 = true;
		begin_8++;
		skipspaces(pos);
		_6 = any_data(tokens);
		if (!(_6.status))
		{
			break;
		}
		success_7 = true;
		begin_8++;
		shadow_9.push(_2);
	}
	if (success_7)
	{
		success_3 = true;
		pos = begin_8;
	}
	_2 += _4;
	_2 += _6;
	cll_template_content_any_data_data data = {,};
}
Parser::Parser::Rule_res cll_csupport_types(Token* &pos, const Token_sequence &tokens) {
	bool is_unsigned = matched();
	str_t _0;
	bool success_1 = false;
	str_t _2;
	bool success_3 = false;
	Token _4;
	bool success_5 = false;
	Token _6;
	bool success_7 = false;
	Token _8;
	bool success_9 = false;
	Token _10;
	bool success_11 = false;
	Token _12;
	bool success_13 = false;
	Token _14;
	bool success_15 = false;
	Token _16;
	bool success_17 = false;
	Token _18;
	bool success_19 = false;
	Token _22;
	bool success_23 = false;
	Token _24;
	bool success_25 = false;
	Token _26;
	bool success_27 = false;
	Token _28;
	bool success_29 = false;
	Token _31;
	bool success_32 = false;
	Token _33;
	bool success_34 = false;
	Token _35;
	bool success_36 = false;
	Token _37;
	bool success_38 = false;
	Token _39;
	bool success_40 = false;
	Token _41;
	bool success_42 = false;
	Token _43;
	bool success_44 = false;
	Token _45;
	bool success_46 = false;
	Rule _48;
	bool success_49 = false;
	auto begin_21 = pos;
	do
	{
		if (*token == Tokens::AUTO_14)
		{
			_4 = pos;
			success_5 = true;
			begin_21++;
		}
		skipspaces(pos);
		auto begin_20 = begin_21;
		if (!(*token == Tokens::AUTO_15))
		{
			if (!(*token == Tokens::AUTO_16))
			{
				if (!(*token == Tokens::AUTO_17))
				{
					if (!(*token == Tokens::AUTO_18))
					{
						if (!(*token == Tokens::AUTO_19))
						{
							break;
						}
						else 
						{
							_18 = pos;
							success_19 = true;
							_8 = _18;
						}
					}
					else 
					{
						_16 = pos;
						success_17 = true;
						_8 = _16;
					}
				}
				else 
				{
					_14 = pos;
					success_15 = true;
					_8 = _14;
				}
			}
			else 
			{
				_12 = pos;
				success_13 = true;
				_8 = _12;
			}
		}
		else 
		{
			_10 = pos;
			success_11 = true;
			_8 = _10;
		}
		_8 += *(pos + 0);
		success_9 = true;
		begin_20++;
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
	_2 += _4;
	_2 += _6;
	if (!success_3)
	{
		auto begin_30 = pos;
		do
		{
			if (!(*token == Tokens::AUTO_20))
			{
				if (!(*token == Tokens::AUTO_21))
				{
					break;
				}
				else 
				{
					_28 = pos;
					success_29 = true;
					_24 = _28;
				}
			}
			else 
			{
				_26 = pos;
				success_27 = true;
				_24 = _26;
			}
			_24 += *(pos + 0);
			success_25 = true;
			begin_30++;
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
				if (!(*token == Tokens::AUTO_22))
				{
					if (!(*token == Tokens::AUTO_23))
					{
						if (!(*token == Tokens::AUTO_24))
						{
							if (!(*token == Tokens::AUTO_25))
							{
								if (!(*token == Tokens::AUTO_26))
								{
									if (!(*token == Tokens::AUTO_27))
									{
										break;
									}
									else 
									{
										_45 = pos;
										success_46 = true;
										_33 = _45;
									}
								}
								else 
								{
									_43 = pos;
									success_44 = true;
									_33 = _43;
								}
							}
							else 
							{
								_41 = pos;
								success_42 = true;
								_33 = _41;
							}
						}
						else 
						{
							_39 = pos;
							success_40 = true;
							_33 = _39;
						}
					}
					else 
					{
						_37 = pos;
						success_38 = true;
						_33 = _37;
					}
				}
				else 
				{
					_35 = pos;
					success_36 = true;
					_33 = _35;
				}
				_33 += *(pos + 0);
				success_34 = true;
				begin_47++;
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
				return {}
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
	_0 += *(pos + 0);
	success_1 = true;
	pos++;
	skipspaces(pos);
	_48 = cll_template_typename(tokens);
	if (!(_48.status))
	{
		return {}
	}
	success_49 = true;
	pos++;
	cll_csupport_types_data data;
	data.template = _8;
	data.type = _4;

}
Parser::Parser::Rule_res cll_type_abstract(Token* &pos, const Token_sequence &tokens) {
	any_t _0;
	bool success_1 = false;
	any_t _2;
	bool success_3 = false;
	Token _4;
	bool success_5 = false;
	Token _6;
	bool success_7 = false;
	Token _8;
	bool success_9 = false;
	Token _10;
	bool success_11 = false;
	Token _12;
	bool success_13 = false;
	str_t _14;
	bool success_15 = false;
	Token _16;
	bool success_17 = false;
	Rule _18;
	bool success_19 = false;
	str_t _21;
	bool success_22 = false;
	Token _23;
	bool success_24 = false;
	Rule _25;
	bool success_26 = false;
	auto begin_28 = pos;
	if (!(*token == Tokens::AUTO_28))
	{
		if (!(*token == Tokens::AUTO_29))
		{
			if (!(*token == Tokens::AUTO_30))
			{
				if (!(*token == Tokens::AUTO_31))
				{
					if (!(*token == Tokens::AUTO_32))
					{
						auto begin_20 = begin_28;
						do
						{
							if (!(*token == Tokens::AUTO_33))
							{
								break;
							}
							_16 = pos;
							success_17 = true;
							begin_20++;
							skipspaces(pos);
							_18 = cll_template_typename(tokens);
							if (!(_18.status))
							{
								break;
							}
							success_19 = true;
							begin_20++;
						}						while(0)
;
						if (success_19)
						{
							success_15 = true;
							begin_28 = begin_20;
						}
						_14 += _16;
						_14 += _18;
						if (!success_15)
						{
							auto begin_27 = begin_28;
							do
							{
								if (!(*token == Tokens::AUTO_34))
								{
									break;
								}
								_23 = pos;
								success_24 = true;
								begin_27++;
								skipspaces(pos);
								_25 = cll_template_typename(tokens);
								if (!(_25.status))
								{
									break;
								}
								success_26 = true;
								begin_27++;
							}							while(0)
;
							if (success_26)
							{
								success_22 = true;
								begin_28 = begin_27;
							}
							_21 += _23;
							_21 += _25;
							if (!success_22)
							{
								return {}
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
						_12 = pos;
						success_13 = true;
						_2 = _12;
					}
				}
				else 
				{
					_10 = pos;
					success_11 = true;
					_2 = _10;
				}
			}
			else 
			{
				_8 = pos;
				success_9 = true;
				_2 = _8;
			}
		}
		else 
		{
			_6 = pos;
			success_7 = true;
			_2 = _6;
		}
	}
	else 
	{
		_4 = pos;
		success_5 = true;
		_2 = _4;
	}
	_2 += *(pos + 0);
	success_3 = true;
	begin_28++;
	if (success_3)
	{
		success_1 = true;
		pos = begin_28;
	}
	cll_type_abstract_data data;
	data.template = _18;
	data.type = _16;

}
Parser::Parser::Rule_res cll_type(Token* &pos, const Token_sequence &tokens) {
	Rule _0;
	bool success_1 = false;
	Rule _2;
	bool success_3 = false;
	Rule _4;
	bool success_5 = false;
	_2 = cll_csupport_types(tokens);
	if (!(_2.status))
	{
		_4 = cll_type_abstract(tokens);
		if (!(_4.status))
		{
			return {}
		}
		else 
		{
			success_5 = true;
			_0 = _4;
		}
	}
	else 
	{
		success_3 = true;
		_0 = _2;
	}
	_0 += *(pos + 0);
	success_1 = true;
	pos++;
	cll_type_data data = _0;
}
Parser::Parser::Rule_res cll_if(Token* &pos, const Token_sequence &tokens) {
	Token _0;
	bool success_1 = false;
	Token _2;
	bool success_3 = false;
	arr_t<Token> shadow_4;
	Token _6;
	bool success_7 = false;
	Rule _8;
	bool success_9 = false;
	str_t _10;
	bool success_11 = false;
	Rule _12;
	bool success_13 = false;
	Rule _14;
	bool success_15 = false;
	Rule _16;
	bool success_17 = false;
	str_t _18;
	bool success_19 = false;
	UNDEF _21;
	UNDEF shadow_22;
	bool success_20 = false;
	Token _23;
	bool success_24 = false;
	Rule _25;
	bool success_26 = false;
	UNDEF _27;
	bool success_28 = false;
	auto begin_5 = pos;
	while (*token == Tokens::AUTO_35)
	{
		_2 += pos;
		success_3 = true;
		begin_5++;
		shadow_4.push(_2);
	}
	if (success_3)
	{
		success_1 = true;
		pos = begin_5;
	}
	_0 = _2;
	skipspaces(pos);
	if (!(*token == Tokens::AUTO_36))
	{
		return {}
	}
	_6 = pos;
	success_7 = true;
	pos++;
	skipspaces(pos);
	_8 = expr(tokens);
	if (!(_8.status))
	{
		return {}
	}
	success_9 = true;
	pos++;
	skipspaces(pos);
	auto begin_31 = pos;
	_14 = cll_block(tokens);
	if (!(_14.status))
	{
		_16 = cll_spaced_block(tokens);
		if (!(_16.status))
		{
			return {}
		}
		else 
		{
			success_17 = true;
			_12 = _16;
		}
	}
	else 
	{
		success_15 = true;
		_12 = _14;
	}
	_12 += *(pos + 0);
	success_13 = true;
	begin_31++;
	skipspaces(pos);
	auto begin_30 = begin_31;
	if (!(!std::strncmp(pos, _2, strlen(_2))))
	{
		return {}
	}
	_21 += *(pos + 0);
	success_20 = true;
	begin_30++;
	skipspaces(pos);
	if (!(*token == Tokens::AUTO_96))
	{
		return {}
	}
	_23 = pos;
	success_24 = true;
	begin_30++;
	skipspaces(pos);
	_25 = size(tokens);
	if (!(_25.status))
	{
		return {}
	}
	success_26 = true;
	begin_30++;
	skipspaces(pos);
	auto begin_29 = begin_30;
	if ()
	{
		success_28 = true;
		begin_30 = begin_29;
	}
	if (success_28)
	{
		success_19 = true;
		begin_31 = begin_30;
	}
	_18 += _21;
	_18 += _23;
	_18 += _25;
	_18 += _27;
	if (success_19)
	{
		success_11 = true;
		pos = begin_31;
	}
	_10 += _12;
	_10 += _18;
	cll_if_data data;
	data.block = _0;
	data.expr = _6;

}
Parser::Parser::Rule_res cll_ternary(Token* &pos, const Token_sequence &tokens) {
	Rule _0;
	bool success_1 = false;
	Token _2;
	bool success_3 = false;
	Rule _4;
	bool success_5 = false;
	Token _6;
	bool success_7 = false;
	Rule _8;
	bool success_9 = false;
	_0 = expr(tokens);
	if (!(_0.status))
	{
		return {}
	}
	success_1 = true;
	pos++;
	skipspaces(pos);
	if (!(*token == Tokens::AUTO_83))
	{
		return {}
	}
	_2 = pos;
	success_3 = true;
	pos++;
	skipspaces(pos);
	_4 = expr(tokens);
	if (!(_4.status))
	{
		return {}
	}
	success_5 = true;
	pos++;
	skipspaces(pos);
	if (!(*token == Tokens::AUTO_65))
	{
		return {}
	}
	_6 = pos;
	success_7 = true;
	pos++;
	skipspaces(pos);
	_8 = expr(tokens);
	if (!(_8.status))
	{
		return {}
	}
	success_9 = true;
	pos++;
	cll_ternary_data data;
	data.second = _8;
	data.first = _4;
	data.cond = _0;

}
Parser::Parser::Rule_res expr_logical(Token* &pos, const Token_sequence &tokens) {
	Rule _0;
	bool success_1 = false;
	Rule _2;
	bool success_3 = false;
	Rule _4;
	bool success_5 = false;
	Rule _6;
	bool success_7 = false;
	Token _8;
	bool success_9 = false;
	Rule _10;
	bool success_11 = false;
	Rule _12;
	bool success_13 = false;
	Rule _14;
	bool success_15 = false;
	Rule _16;
	bool success_17 = false;
	_2 = expr_compare(tokens);
	if (!(_2.status))
	{
		_4 = expr_arithmetic(tokens);
		if (!(_4.status))
		{
			_6 = expr_for_arithmetic(tokens);
			if (!(_6.status))
			{
				return {}
			}
			else 
			{
				success_7 = true;
				_0 = _6;
			}
		}
		else 
		{
			success_5 = true;
			_0 = _4;
		}
	}
	else 
	{
		success_3 = true;
		_0 = _2;
	}
	_0 += *(pos + 0);
	success_1 = true;
	pos++;
	skipspaces(pos);
	if (!(*token == Tokens::LOGICAL_OP))
	{
		return {}
	}
	_8 = pos;
	success_9 = true;
	pos++;
	skipspaces(pos);
	_12 = expr_compare(tokens);
	if (!(_12.status))
	{
		_14 = expr_arithmetic(tokens);
		if (!(_14.status))
		{
			_16 = expr_for_arithmetic(tokens);
			if (!(_16.status))
			{
				return {}
			}
			else 
			{
				success_17 = true;
				_10 = _16;
			}
		}
		else 
		{
			success_15 = true;
			_10 = _14;
		}
	}
	else 
	{
		success_13 = true;
		_10 = _12;
	}
	_10 += *(pos + 0);
	success_11 = true;
	pos++;
	expr_logical_data data;
	data.right = _8;
	data.op = _0;
	data.left = _0;

}
Parser::Parser::Rule_res expr_compare(Token* &pos, const Token_sequence &tokens) {
	Rule _0;
	bool success_1 = false;
	arr_t<str_t> shadow_9;
	str_t _2;
	bool success_3 = false;
	bool success_10 = false;
	Token _4;
	bool success_5 = false;
	Rule _6;
	bool success_7 = false;
	_0 = expr_arithmetic(tokens);
	if (!(_0.status))
	{
		return {}
	}
	success_1 = true;
	pos++;
	skipspaces(pos);
	auto begin_8 = pos;
	while (1)
	{
		if (!(*token == Tokens::COMPARE_OP))
		{
			break;
		}
		_4 = pos;
		success_5 = true;
		begin_8++;
		skipspaces(pos);
		_6 = expr_arithmetic(tokens);
		if (!(_6.status))
		{
			break;
		}
		success_7 = true;
		begin_8++;
		shadow_9.push(_2);
		success_10 = true;
	}
	if (!success_10)
	{
		return {}
	}
	if (success_7)
	{
		success_3 = true;
		pos = begin_8;
	}
	_2 += _4;
	_2 += _6;
	expr_compare_data data;
	data.sequence = _6;
	data.operators = _4;
	data.first = _0;

}
Parser::Parser::Rule_res expr_arithmetic(Token* &pos, const Token_sequence &tokens) {
	Rule _0;
	bool success_1 = false;
	arr_t<str_t> shadow_9;
	str_t _2;
	bool success_3 = false;
	bool success_10 = false;
	Token _4;
	bool success_5 = false;
	Rule _6;
	bool success_7 = false;
	_0 = expr_for_arithmetic(tokens);
	if (!(_0.status))
	{
		return {}
	}
	success_1 = true;
	pos++;
	skipspaces(pos);
	auto begin_8 = pos;
	while (1)
	{
		if (!(*token == Tokens::OP))
		{
			break;
		}
		_4 = pos;
		success_5 = true;
		begin_8++;
		skipspaces(pos);
		_6 = expr_for_arithmetic(tokens);
		if (!(_6.status))
		{
			break;
		}
		success_7 = true;
		begin_8++;
		shadow_9.push(_2);
		success_10 = true;
	}
	if (!success_10)
	{
		return {}
	}
	if (success_7)
	{
		success_3 = true;
		pos = begin_8;
	}
	_2 += _4;
	_2 += _6;
	expr_arithmetic_data data;
	data.sequence = _6;
	data.operators = _4;
	data.first = _0;

}
Parser::Parser::Rule_res expr_for_arithmetic(Token* &pos, const Token_sequence &tokens) {
	Rule _0;
	bool success_1 = false;
	Rule _2;
	bool success_3 = false;
	Rule _4;
	bool success_5 = false;
	Rule _6;
	bool success_7 = false;
	Rule _8;
	bool success_9 = false;
	_2 = expr_group(tokens);
	if (!(_2.status))
	{
		_4 = method_call(tokens);
		if (!(_4.status))
		{
			_6 = cll_function_call(tokens);
			if (!(_6.status))
			{
				_8 = any_data(tokens);
				if (!(_8.status))
				{
					return {}
				}
				else 
				{
					success_9 = true;
					_0 = _8;
				}
			}
			else 
			{
				success_7 = true;
				_0 = _6;
			}
		}
		else 
		{
			success_5 = true;
			_0 = _4;
		}
	}
	else 
	{
		success_3 = true;
		_0 = _2;
	}
	_0 += *(pos + 0);
	success_1 = true;
	pos++;
	expr_for_arithmetic_data data = _0;
}
Parser::Parser::Rule_res expr_group(Token* &pos, const Token_sequence &tokens) {
	Token _0;
	bool success_1 = false;
	Rule _2;
	bool success_3 = false;
	Rule _4;
	bool success_5 = false;
	Rule _6;
	bool success_7 = false;
	Token _8;
	bool success_9 = false;
	if (!(*token == Tokens::AUTO_40))
	{
		return {}
	}
	_0 = pos;
	success_1 = true;
	pos++;
	skipspaces(pos);
	_4 = cll_ternary(tokens);
	if (!(_4.status))
	{
		_6 = expr(tokens);
		if (!(_6.status))
		{
			return {}
		}
		else 
		{
			success_7 = true;
			_2 = _6;
		}
	}
	else 
	{
		success_5 = true;
		_2 = _4;
	}
	_2 += *(pos + 0);
	success_3 = true;
	pos++;
	skipspaces(pos);
	if (!(*token == Tokens::AUTO_41))
	{
		return {}
	}
	_8 = pos;
	success_9 = true;
	pos++;
	expr_group_data data = _2;
}
Parser::Parser::Rule_res expr_expr_copiable_method_call(Token* &pos, const Token_sequence &tokens) {
	Token _0;
	bool success_1 = false;
	Rule _2;
	bool success_3 = false;
	Token _4;
	bool success_5 = false;
	if (!(*token == Tokens::AUTO_42))
	{
		return {}
	}
	_0 = pos;
	success_1 = true;
	pos++;
	skipspaces(pos);
	_2 = copiable_method_call(tokens);
	if (!(_2.status))
	{
		return {}
	}
	success_3 = true;
	pos++;
	skipspaces(pos);
	if (!(*token == Tokens::AUTO_43))
	{
		return {}
	}
	_4 = pos;
	success_5 = true;
	pos++;
	expr_expr_copiable_method_call_data data = _2;
}
Parser::Parser::Rule_res expr(Token* &pos, const Token_sequence &tokens) {
	Rule _0;
	bool success_1 = false;
	Rule _2;
	bool success_3 = false;
	Rule _4;
	bool success_5 = false;
	Rule _6;
	bool success_7 = false;
	Rule _8;
	bool success_9 = false;
	Rule _10;
	bool success_11 = false;
	Rule _12;
	bool success_13 = false;
	Rule _14;
	bool success_15 = false;
	_2 = expr_logical(tokens);
	if (!(_2.status))
	{
		_4 = expr_compare(tokens);
		if (!(_4.status))
		{
			_6 = expr_arithmetic(tokens);
			if (!(_6.status))
			{
				_8 = expr_group(tokens);
				if (!(_8.status))
				{
					_10 = expr_expr_copiable_method_call(tokens);
					if (!(_10.status))
					{
						_12 = cll_function_call(tokens);
						if (!(_12.status))
						{
							_14 = any_data(tokens);
							if (!(_14.status))
							{
								return {}
							}
							else 
							{
								success_15 = true;
								_0 = _14;
							}
						}
						else 
						{
							success_13 = true;
							_0 = _12;
						}
					}
					else 
					{
						success_11 = true;
						_0 = _10;
					}
				}
				else 
				{
					success_9 = true;
					_0 = _8;
				}
			}
			else 
			{
				success_7 = true;
				_0 = _6;
			}
		}
		else 
		{
			success_5 = true;
			_0 = _4;
		}
	}
	else 
	{
		success_3 = true;
		_0 = _2;
	}
	_0 += *(pos + 0);
	success_1 = true;
	pos++;
	expr_data data = _0;
}
Parser::Parser::Rule_res function_body_call(Token* &pos, const Token_sequence &tokens) {
	Token _0;
	bool success_1 = false;
	Rule _2;
	bool success_3 = false;
	Token _4;
	bool success_5 = false;
	if (!(*token == Tokens::AUTO_46))
	{
		return {}
	}
	_0 = pos;
	success_1 = true;
	pos++;
	skipspaces(pos);
	_2 = function_arguments(tokens);
	if (!(_2.status))
	{
		return {}
	}
	success_3 = true;
	pos++;
	skipspaces(pos);
	if (!(*token == Tokens::AUTO_47))
	{
		return {}
	}
	_4 = pos;
	success_5 = true;
	pos++;
	function_body_call_data data = _2;
}
Parser::Parser::Rule_res function_body_decl(Token* &pos, const Token_sequence &tokens) {
	Token _0;
	bool success_1 = false;
	Rule _2;
	bool success_3 = false;
	Token _4;
	bool success_5 = false;
	if (!(*token == Tokens::AUTO_49))
	{
		return {}
	}
	_0 = pos;
	success_1 = true;
	pos++;
	skipspaces(pos);
	_2 = function_parameters(tokens);
	if (!(_2.status))
	{
		return {}
	}
	success_3 = true;
	pos++;
	skipspaces(pos);
	if (!(*token == Tokens::AUTO_52))
	{
		return {}
	}
	_4 = pos;
	success_5 = true;
	pos++;
	function_body_decl_data data = _2;
}
Parser::Parser::Rule_res function_arguments(Token* &pos, const Token_sequence &tokens) {
	any_t _0;
	bool success_1 = false;
	any_t _2;
	bool success_3 = false;
	Rule _4;
	bool success_5 = false;
	Token _6;
	bool success_7 = false;
	arr_t<str_t> shadow_20;
	str_t _9;
	bool success_10 = false;
	str_t _11;
	bool success_12 = false;
	any_t _13;
	bool success_14 = false;
	Rule _15;
	bool success_16 = false;
	Token _17;
	bool success_18 = false;
	auto begin_8 = pos;
	do
	{
		_4 = any_data(tokens);
		if (!(_4.status))
		{
			if (!(*token == Tokens::ID))
			{
				break;
			}
			else 
			{
				_6 = pos;
				success_7 = true;
				_2 = _6;
			}
		}
		else 
		{
			success_5 = true;
			_2 = _4;
		}
		_2 += *(pos + 0);
		success_3 = true;
		begin_8++;
	}	while(0)
;
	if (success_3)
	{
		success_1 = true;
		pos = begin_8;
	}
	skipspaces(pos);
	if ((matched()))
	{
		auto begin_19 = pos;
		while (1)
		{
			if (!(*pos == ','))
			{
				break;
			}
			_11 += *(pos + 0);
			success_12 = true;
			begin_19++;
			skipspaces(pos);
			_15 = any_data(tokens);
			if (!(_15.status))
			{
				if (!(*token == Tokens::ID))
				{
					break;
				}
				else 
				{
					_17 = pos;
					success_18 = true;
					_13 = _17;
				}
			}
			else 
			{
				success_16 = true;
				_13 = _15;
			}
			_13 += *(pos + 0);
			success_14 = true;
			begin_19++;
			shadow_20.push(_9);
		}
		if (success_14)
		{
			success_10 = true;
			pos = begin_19;
		}
		_9 += _11;
		_9 += _13;
		skipspaces(pos);
	}
	function_arguments_data data = {,};
}
Parser::Parser::Rule_res function_parameters(Token* &pos, const Token_sequence &tokens) {
	Token _0;
	bool success_1 = false;
	arr_t<str_t> shadow_9;
	str_t _2;
	bool success_3 = false;
	str_t _4;
	bool success_5 = false;
	Token _6;
	bool success_7 = false;
	if (*token == Tokens::ID)
	{
		_0 = pos;
		success_1 = true;
		pos++;
	}
	skipspaces(pos);
	if ((matched()))
	{
		auto begin_8 = pos;
		while (1)
		{
			if (!(*pos == ','))
			{
				break;
			}
			_4 += *(pos + 0);
			success_5 = true;
			begin_8++;
			skipspaces(pos);
			if (!(*token == Tokens::ID))
			{
				break;
			}
			_6 = pos;
			success_7 = true;
			begin_8++;
			shadow_9.push(_2);
		}
		if (success_7)
		{
			success_3 = true;
			pos = begin_8;
		}
		_2 += _4;
		_2 += _6;
		skipspaces(pos);
	}
	function_parameters_data data = {,};
}
Parser::Parser::Rule_res cll_function_call(Token* &pos, const Token_sequence &tokens) {
	Token _0;
	bool success_1 = false;
	Rule _2;
	bool success_3 = false;
	if (!(*token == Tokens::ID))
	{
		return {}
	}
	_0 = pos;
	success_1 = true;
	pos++;
	skipspaces(pos);
	_2 = function_body_call(tokens);
	if (!(_2.status))
	{
		return {}
	}
	success_3 = true;
	pos++;
	cll_function_call_data data;
	data.body = _2;
	data.name = _0;

}
Parser::Parser::Rule_res loop_while(Token* &pos, const Token_sequence &tokens) {
	Token _0;
	bool success_1 = false;
	Rule _2;
	bool success_3 = false;
	Rule _4;
	bool success_5 = false;
	Rule _6;
	bool success_7 = false;
	Rule _8;
	bool success_9 = false;
	if (!(*token == Tokens::AUTO_48))
	{
		return {}
	}
	_0 = pos;
	success_1 = true;
	pos++;
	skipspaces(pos);
	_2 = expr(tokens);
	if (!(_2.status))
	{
		return {}
	}
	success_3 = true;
	pos++;
	skipspaces(pos);
	_6 = cll_block(tokens);
	if (!(_6.status))
	{
		_8 = cll_spaced_block(tokens);
		if (!(_8.status))
		{
			return {}
		}
		else 
		{
			success_9 = true;
			_4 = _8;
		}
	}
	else 
	{
		success_7 = true;
		_4 = _6;
	}
	_4 += *(pos + 0);
	success_5 = true;
	pos++;
	loop_while_data data;
	data.block = _4;
	data.expr = _2;

}
Parser::Parser::Rule_res loop_for(Token* &pos, const Token_sequence &tokens) {
	Rule _0;
	bool success_1 = false;
	Token _2;
	bool success_3 = false;
	Rule _4;
	bool success_5 = false;
	Rule _6;
	bool success_7 = false;
	Rule _8;
	bool success_9 = false;
	Rule _10;
	bool success_11 = false;
	Token _13;
	bool success_14 = false;
	Rule _15;
	bool success_16 = false;
	Token _17;
	bool success_18 = false;
	Rule _19;
	bool success_20 = false;
	Token _21;
	bool success_22 = false;
	Rule _23;
	bool success_24 = false;
	Rule _25;
	bool success_26 = false;
	Rule _27;
	bool success_28 = false;
	_0 = for(tokens);
	if (!(_0.status))
	{
		return {}
	}
	success_1 = true;
	pos++;
	skipspaces(pos);
	if (!(*token == Tokens::AUTO_87))
	{
		return {}
	}
	_2 = pos;
	success_3 = true;
	pos++;
	skipspaces(pos);
	auto begin_12 = pos;
	do
	{
		_8 = expr(tokens);
		if (!(_8.status))
		{
			_10 = cll_var(tokens);
			if (!(_10.status))
			{
				break;
			}
			else 
			{
				success_11 = true;
				_6 = _10;
			}
		}
		else 
		{
			success_9 = true;
			_6 = _8;
		}
		_6 += *(pos + 0);
		success_7 = true;
		begin_12++;
	}	while(0)
;
	if (success_7)
	{
		success_5 = true;
		pos = begin_12;
	}
	_4 = _6;
	skipspaces(pos);
	if (!(*token == Tokens::AUTO_51))
	{
		return {}
	}
	_13 = pos;
	success_14 = true;
	pos++;
	skipspaces(pos);
	_15 = expr(tokens);
	if (_15.status)
	{
		success_16 = true;
		pos++;
	}
	skipspaces(pos);
	if (!(*token == Tokens::AUTO_68))
	{
		return {}
	}
	_17 = pos;
	success_18 = true;
	pos++;
	skipspaces(pos);
	_19 = expr(tokens);
	if (_19.status)
	{
		success_20 = true;
		pos++;
	}
	skipspaces(pos);
	if (!(*token == Tokens::AUTO_88))
	{
		return {}
	}
	_21 = pos;
	success_22 = true;
	pos++;
	skipspaces(pos);
	_25 = cll_block(tokens);
	if (!(_25.status))
	{
		_27 = cll_spaced_block(tokens);
		if (!(_27.status))
		{
			return {}
		}
		else 
		{
			success_28 = true;
			_23 = _27;
		}
	}
	else 
	{
		success_26 = true;
		_23 = _25;
	}
	_23 += *(pos + 0);
	success_24 = true;
	pos++;
	loop_for_data data;
	data.block = _19;
	data.end = _15;
	data.cond = _4;
	data.decl = _6;

}
Parser::Parser::Rule_res method_call(Token* &pos, const Token_sequence &tokens) {
	Token _0;
	bool success_1 = false;
	arr_t<str_t> shadow_9;
	str_t _2;
	bool success_3 = false;
	bool success_10 = false;
	Token _4;
	bool success_5 = false;
	Rule _6;
	bool success_7 = false;
	if (!(*token == Tokens::ID))
	{
		return {}
	}
	_0 = pos;
	success_1 = true;
	pos++;
	skipspaces(pos);
	auto begin_8 = pos;
	while (1)
	{
		if (!(*token == Tokens::AUTO_80))
		{
			break;
		}
		_4 = pos;
		success_5 = true;
		begin_8++;
		skipspaces(pos);
		_6 = cll_function_call(tokens);
		if (!(_6.status))
		{
			break;
		}
		success_7 = true;
		begin_8++;
		shadow_9.push(_2);
		success_10 = true;
	}
	if (!success_10)
	{
		return {}
	}
	if (success_7)
	{
		success_3 = true;
		pos = begin_8;
	}
	_2 += _4;
	_2 += _6;
	method_call_data data;
	data.call = _6;
	data.object = _0;

}
Parser::Parser::Rule_res copiable_method_call(Token* &pos, const Token_sequence &tokens) {
	Token _0;
	bool success_1 = false;
	Rule _2;
	bool success_3 = false;
	if (!(*token == Tokens::AUTO_54))
	{
		return {}
	}
	_0 = pos;
	success_1 = true;
	pos++;
	skipspaces(pos);
	_2 = method_call(tokens);
	if (!(_2.status))
	{
		return {}
	}
	success_3 = true;
	pos++;
	copiable_method_call_data data = _2;
}
Parser::Parser::Rule_res var_refer(Token* &pos, const Token_sequence &tokens) {
	any_t pre = matched();
	any_t post = matched();
	Token _0;
	bool success_1 = false;
	Token _2;
	bool success_3 = false;
	Token _4;
	bool success_5 = false;
	Token _6;
	bool success_7 = false;
	Token _9;
	bool success_10 = false;
	str_t _11;
	bool success_12 = false;
	Token _13;
	bool success_14 = false;
	Rule _15;
	bool success_16 = false;
	Token _17;
	bool success_18 = false;
	Token _20;
	bool success_21 = false;
	Token _22;
	bool success_23 = false;
	Token _24;
	bool success_25 = false;
	Token _26;
	bool success_27 = false;
	auto begin_8 = pos;
	do
	{
		if (!(*token == Tokens::AUTO_59))
		{
			if (!(*token == Tokens::AUTO_60))
			{
				break;
			}
			else 
			{
				_6 = pos;
				success_7 = true;
				_2 = _6;
			}
		}
		else 
		{
			_4 = pos;
			success_5 = true;
			_2 = _4;
		}
		_2 += *(pos + 0);
		success_3 = true;
		begin_8++;
	}	while(0)
;
	if (success_3)
	{
		success_1 = true;
		pos = begin_8;
	}
	_0 = _2;
	skipspaces(pos);
	if (!(*token == Tokens::ID))
	{
		return {}
	}
	_9 = pos;
	success_10 = true;
	pos++;
	skipspaces(pos);
	auto begin_19 = pos;
	do
	{
		if (!(*token == Tokens::AUTO_61))
		{
			break;
		}
		_13 = pos;
		success_14 = true;
		begin_19++;
		skipspaces(pos);
		_15 = expr(tokens);
		if (!(_15.status))
		{
			break;
		}
		success_16 = true;
		begin_19++;
		skipspaces(pos);
		if (!(*token == Tokens::AUTO_63))
		{
			break;
		}
		_17 = pos;
		success_18 = true;
		begin_19++;
	}	while(0)
;
	if (success_18)
	{
		success_12 = true;
		pos = begin_19;
	}
	_11 += _13;
	_11 += _15;
	_11 += _17;
	skipspaces(pos);
	auto begin_28 = pos;
	do
	{
		if (!(*token == Tokens::AUTO_59))
		{
			if (!(*token == Tokens::AUTO_60))
			{
				break;
			}
			else 
			{
				_26 = pos;
				success_27 = true;
				_22 = _26;
			}
		}
		else 
		{
			_24 = pos;
			success_25 = true;
			_22 = _24;
		}
		_22 += *(pos + 0);
		success_23 = true;
		begin_28++;
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
	data.brace_expression = _15;
	data.name = _2;

}
Parser::Parser::Rule_res cll_var(Token* &pos, const Token_sequence &tokens) {
	Rule _0;
	bool success_1 = false;
	Token _2;
	bool success_3 = false;
	str_t _4;
	bool success_5 = false;
	Rule _6;
	bool success_7 = false;
	Rule _8;
	bool success_9 = false;
	Rule _10;
	bool success_11 = false;
	Rule _12;
	bool success_13 = false;
	_0 = cll_type(tokens);
	if (_0.status)
	{
		success_1 = true;
		pos++;
	}
	skipspaces(pos);
	if (!(*token == Tokens::ID))
	{
		return {}
	}
	_2 = pos;
	success_3 = true;
	pos++;
	skipspaces(pos);
	auto begin_14 = pos;
	do
	{
		_6 = assignment_op(tokens);
		if (!(_6.status))
		{
			break;
		}
		success_7 = true;
		begin_14++;
		skipspaces(pos);
		_10 = expr(tokens);
		if (!(_10.status))
		{
			_12 = cll_ternary(tokens);
			if (!(_12.status))
			{
				break;
			}
			else 
			{
				success_13 = true;
				_8 = _12;
			}
		}
		else 
		{
			success_11 = true;
			_8 = _10;
		}
		_8 += *(pos + 0);
		success_9 = true;
		begin_14++;
	}	while(0)
;
	if (success_9)
	{
		success_5 = true;
		pos = begin_14;
	}
	_4 += _6;
	_4 += _8;
	cll_var_data data;
	data.value = _8;
	data.operator = _6;
	data.id = _2;
	data.type = _0;

}
Parser::Tokenizator::Token_res STRING(const char* pos, const char* const str) {
	data = ;
	str_t _0;
	bool success_1 = false;
	str_t _2;
	bool success_3 = false;
	auto begin_18 = pos;
	do
	{
		str_t _4;
		bool success_5 = false;
		if (!(*pos == '\''))
		{
			break;
		}
		_4 += *(pos + 0);
		success_5 = true;
		begin_18++;
		skipspaces(pos);
		arr_t<any_t> shadow_15;
		any_t _6;
		bool success_7 = false;
		auto begin_14 = begin_18;
		while (1)
		{
			any_t _8;
			bool success_9 = false;
			str_t _10;
			bool success_11 = false;
			if (!(!std::strncmp(pos, "\\'", 2)))
			{
				str_t _12;
				bool success_13 = false;
				if (!(!(*pos == '\'')))
				{
					break;
				}
				else 
				{
					_12 += *(pos + 0);
					success_13 = true;
					_8 = _12;
				}
			}
			else 
			{
				_10 += *(pos + 0);
				success_11 = true;
				_8 = _10;
			}
			_8 += *(pos + 0);
			success_9 = true;
			begin_14++;
			shadow_15.push(_6);
		}
		if (success_9)
		{
			success_7 = true;
			begin_18 = begin_14;
		}
		skipspaces(pos);
		str_t _16;
		bool success_17 = false;
		if (!(*pos == '\''))
		{
			break;
		}
		_16 += *(pos + 0);
		success_17 = true;
		begin_18++;
	}	while(0)
;
	if (success_17)
	{
		success_3 = true;
		pos = begin_18;
	}
	_2 += _4;
	_2 += shadow_15;
	_2 += _16;
	if (!success_3)
	{
		str_t _19;
		bool success_20 = false;
		auto begin_35 = pos;
		do
		{
			str_t _21;
			bool success_22 = false;
			if (!(*pos == '"'))
			{
				break;
			}
			_21 += *(pos + 0);
			success_22 = true;
			begin_35++;
			skipspaces(pos);
			arr_t<any_t> shadow_32;
			any_t _23;
			bool success_24 = false;
			auto begin_31 = begin_35;
			while (1)
			{
				any_t _25;
				bool success_26 = false;
				str_t _27;
				bool success_28 = false;
				if (!(!std::strncmp(pos, "\\\"", 2)))
				{
					str_t _29;
					bool success_30 = false;
					if (!(!(*pos == '"')))
					{
						break;
					}
					else 
					{
						_29 += *(pos + 0);
						success_30 = true;
						_25 = _29;
					}
				}
				else 
				{
					_27 += *(pos + 0);
					success_28 = true;
					_25 = _27;
				}
				_25 += *(pos + 0);
				success_26 = true;
				begin_31++;
				shadow_32.push(_23);
			}
			if (success_26)
			{
				success_24 = true;
				begin_35 = begin_31;
			}
			skipspaces(pos);
			str_t _33;
			bool success_34 = false;
			if (!(*pos == '"'))
			{
				break;
			}
			_33 += *(pos + 0);
			success_34 = true;
			begin_35++;
		}		while(0)
;
		if (success_34)
		{
			success_20 = true;
			pos = begin_35;
		}
		_19 += _21;
		_19 += shadow_32;
		_19 += _33;
		if (!success_20)
		{
			return {}
		}
		else 
		{
			_0 = _19;
		}
	}
	else 
	{
		_0 = _2;
	}
	_0 += *(pos + 0);
	success_1 = true;
	pos++;
}
Parser::Tokenizator::Token_res NUMBER(const char* pos, const char* const str) {
	char sign = ;
	str_t main = ;
	num_t main_n = NUMBER(main);
	char point = ;
	str_t dec = ;
	num_t dec_n = NUMBER(dec);
	str_t _0;
	bool success_1 = false;
	if (!(*pos == '+' || *pos == '-'))
	{
		return {}
	}
	_0 += *(pos + 0);
	success_1 = true;
	pos++;
	skipspaces(pos);
	str_t _2;
	bool success_3 = false;
	str_t _4;
	bool success_5 = false;
	auto begin_10 = pos;
	do
	{
		str_t _6;
		bool success_7 = false;
		arr_t<str_t> shadow_8;
		bool success_9 = false;
		while ((*pos>='0' && *pos<='9'))
		{
			_6 += *(pos + 0);
			success_7 = true;
			begin_10++;
			shadow_8.push(_6);
			success_9 = true;
		}
		if (!success_9)
		{
			break;
		}
	}	while(0)
;
	if (success_7)
	{
		success_5 = true;
		pos = begin_10;
	}
	_4 += shadow_8;
	if (!success_5)
	{
		str_t _11;
		bool success_12 = false;
		auto begin_19 = pos;
		do
		{
			str_t _13;
			bool success_14 = false;
			if (!(*pos == '.' || *pos == ','))
			{
				break;
			}
			_13 += *(pos + 0);
			success_14 = true;
			begin_19++;
			skipspaces(pos);
			str_t _15;
			bool success_16 = false;
			arr_t<str_t> shadow_17;
			bool success_18 = false;
			while ((*pos>='0' && *pos<='9'))
			{
				_15 += *(pos + 0);
				success_16 = true;
				begin_19++;
				shadow_17.push(_15);
				success_18 = true;
			}
			if (!success_18)
			{
				break;
			}
		}		while(0)
;
		if (success_16)
		{
			success_12 = true;
			pos = begin_19;
		}
		_11 += _13;
		_11 += shadow_17;
		if (!success_12)
		{
			return {}
		}
		else 
		{
			_2 = _11;
		}
	}
	else 
	{
		_2 = _4;
	}
	_2 += *(pos + 0);
	success_3 = true;
	pos++;
	NUMBER_data data;
	data.full = main+point+dec;
	data.dec_n = dec_n;
	data.dec = dec;
	data.main_n = main_n;
	data.main = main;
	data.sign = sign;

}
Parser::Tokenizator::Token_res BOOLEAN(const char* pos, const char* const str) {
	str_t d;
	bool success_0 = false;
	auto begin_7 = pos;
	str_t _1;
	bool success_2 = false;
	str_t _3;
	bool success_4 = false;
	if (!(!std::strncmp(pos, "true", 4)))
	{
		str_t _5;
		bool success_6 = false;
		if (!(!std::strncmp(pos, "false", 5)))
		{
			return {}
		}
		else 
		{
			_5 += *(pos + 0);
			success_6 = true;
			_1 = _5;
		}
	}
	else 
	{
		_3 += *(pos + 0);
		success_4 = true;
		_1 = _3;
	}
	_1 += *(pos + 0);
	success_2 = true;
	begin_7++;
	if (success_2)
	{
		success_0 = true;
		pos = begin_7;
	}
	d += _1;
	BOOLEAN_data data;
	data.lit = d;

}
Parser::Parser::Rule_res array(Token* &pos, const Token_sequence &tokens) {
	Token _0;
	bool success_1 = false;
	str_t _2;
	bool success_3 = false;
	arr_t<str_t> shadow_11;
	str_t _4;
	bool success_5 = false;
	Rule _6;
	bool success_7 = false;
	Token _8;
	bool success_9 = false;
	Token _13;
	bool success_14 = false;
	if (!(*token == Tokens::AUTO_89))
	{
		return {}
	}
	_0 = pos;
	success_1 = true;
	pos++;
	skipspaces(pos);
	auto begin_12 = pos;
	do
	{
		auto begin_10 = begin_12;
		while (1)
		{
			_6 = any_data(tokens);
			if (!(_6.status))
			{
				break;
			}
			success_7 = true;
			begin_10++;
			skipspaces(pos);
			if (!(*token == Tokens::AUTO_66))
			{
				break;
			}
			_8 = pos;
			success_9 = true;
			begin_10++;
			shadow_11.push(_4);
		}
		if (success_9)
		{
			success_5 = true;
			begin_12 = begin_10;
		}
		_4 += _6;
		_4 += _8;
	}	while(0)
;
	if (success_5)
	{
		success_3 = true;
		pos = begin_12;
	}
	_2 += shadow_11;
	skipspaces(pos);
	if (!(*token == Tokens::AUTO_91))
	{
		return {}
	}
	_13 = pos;
	success_14 = true;
	pos++;
	array_data data = _8;
}
Parser::Parser::Rule_res object(Token* &pos, const Token_sequence &tokens) {
	Token _0;
	bool success_1 = false;
	str_t _2;
	bool success_3 = false;
	Rule _4;
	bool success_5 = false;
	Token _6;
	bool success_7 = false;
	Rule _8;
	bool success_9 = false;
	arr_t<str_t> shadow_21;
	str_t _10;
	bool success_11 = false;
	Token _12;
	bool success_13 = false;
	Token _14;
	bool success_15 = false;
	Token _16;
	bool success_17 = false;
	Rule _18;
	bool success_19 = false;
	Token _22;
	bool success_23 = false;
	Token _25;
	bool success_26 = false;
	if (!(*token == Tokens::AUTO_64))
	{
		return {}
	}
	_0 = pos;
	success_1 = true;
	pos++;
	skipspaces(pos);
	auto begin_24 = pos;
	do
	{
		_4 = any_data(tokens);
		if (!(_4.status))
		{
			break;
		}
		success_5 = true;
		begin_24++;
		skipspaces(pos);
		if (!(*token == Tokens::AUTO_67))
		{
			break;
		}
		_6 = pos;
		success_7 = true;
		begin_24++;
		skipspaces(pos);
		_8 = any_data(tokens);
		if (!(_8.status))
		{
			break;
		}
		success_9 = true;
		begin_24++;
		skipspaces(pos);
		auto begin_20 = begin_24;
		while (1)
		{
			if (!(*token == Tokens::AUTO_77))
			{
				break;
			}
			_12 = pos;
			success_13 = true;
			begin_20++;
			skipspaces(pos);
			if (!(*token == Tokens::ID))
			{
				break;
			}
			_14 = pos;
			success_15 = true;
			begin_20++;
			skipspaces(pos);
			if (!(*token == Tokens::AUTO_78))
			{
				break;
			}
			_16 = pos;
			success_17 = true;
			begin_20++;
			skipspaces(pos);
			_18 = any_data(tokens);
			if (!(_18.status))
			{
				break;
			}
			success_19 = true;
			begin_20++;
			shadow_21.push(_10);
		}
		if (success_19)
		{
			success_11 = true;
			begin_24 = begin_20;
		}
		_10 += _12;
		_10 += _14;
		_10 += _16;
		_10 += _18;
		skipspaces(pos);
		if (!(*token == Tokens::AUTO_102))
		{
			break;
		}
		_22 = pos;
		success_23 = true;
		begin_24++;
	}	while(0)
;
	if (success_23)
	{
		success_3 = true;
		pos = begin_24;
	}
	_2 += _4;
	_2 += _6;
	_2 += _8;
	_2 += shadow_21;
	_2 += _22;
	skipspaces(pos);
	if (!(*token == Tokens::AUTO_69))
	{
		return {}
	}
	_25 = pos;
	success_26 = true;
	pos++;
	object_data data;
	data.values = _18;
	data.keys = _14;
	data.value = _8;
	data.key = _4;

}
Parser::Parser::Rule_res any_data(Token* &pos, const Token_sequence &tokens) {
	any_t _0;
	bool success_1 = false;
	Token _2;
	bool success_3 = false;
	Token _4;
	bool success_5 = false;
	Token _6;
	bool success_7 = false;
	Token _8;
	bool success_9 = false;
	Rule _10;
	bool success_11 = false;
	Rule _12;
	bool success_13 = false;
	Rule _14;
	bool success_15 = false;
	data = ;
	if (!(*token == Tokens::BOOLEAN))
	{
		if (!(*token == Tokens::NUMBER))
		{
			if (!(*token == Tokens::STRING))
			{
				if (!(*token == Tokens::ID))
				{
					_10 = array(tokens);
					if (!(_10.status))
					{
						_12 = object(tokens);
						if (!(_12.status))
						{
							_14 = accessor(tokens);
							if (!(_14.status))
							{
								return {}
							}
							else 
							{
								success_15 = true;
								_0 = _14;
							}
						}
						else 
						{
							success_13 = true;
							_0 = _12;
						}
					}
					else 
					{
						success_11 = true;
						_0 = _10;
					}
				}
				else 
				{
					_8 = pos;
					success_9 = true;
					_0 = _8;
				}
			}
			else 
			{
				_6 = pos;
				success_7 = true;
				_0 = _6;
			}
		}
		else 
		{
			_4 = pos;
			success_5 = true;
			_0 = _4;
		}
	}
	else 
	{
		_2 = pos;
		success_3 = true;
		_0 = _2;
	}
	_0 += *(pos + 0);
	success_1 = true;
	pos++;
}
Parser::Tokenizator::Token_res END(const char* pos, const char* const str) {
	str_t _0;
	bool success_1 = false;
	if (!(*pos == ';' || *pos == '\n'))
	{
		return {}
	}
	_0 += *(pos + 0);
	success_1 = true;
	pos++;
}
Parser::Tokenizator::Token_res NEWLINE(const char* pos, const char* const str) {
	str_t _0;
	bool success_1 = false;
	if (!(*pos == '\n'))
	{
		return {}
	}
	_0 += *(pos + 0);
	success_1 = true;
	pos++;
}
Parser::Tokenizator::Token_res ID(const char* pos, const char* const str) {
	str_t _0;
	bool success_1 = false;
	auto begin_10 = pos;
	str_t _2;
	bool success_3 = false;
	arr_t<str_t> shadow_4;
	while ((*pos>='0' && *pos<='9'))
	{
		_2 += *(pos + 0);
		success_3 = true;
		begin_10++;
		shadow_4.push(_2);
	}
	skipspaces(pos);
	str_t _5;
	bool success_6 = false;
	if (!((*pos>='a' && *pos<='z') || (*pos>='A' && *pos<='Z') || *pos == '_'))
	{
		return {}
	}
	_5 += *(pos + 0);
	success_6 = true;
	begin_10++;
	skipspaces(pos);
	str_t _7;
	bool success_8 = false;
	arr_t<str_t> shadow_9;
	while ((*pos>='a' && *pos<='z') || (*pos>='A' && *pos<='Z') || (*pos>='0' && *pos<='9') || *pos == '_')
	{
		_7 += *(pos + 0);
		success_8 = true;
		begin_10++;
		shadow_9.push(_7);
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
}
Parser::Parser::Rule_res spacemode(Token* &pos, const Token_sequence &tokens) {
	Token _0;
	bool success_1 = false;
	Token _2;
	bool success_3 = false;
	Token _4;
	bool success_5 = false;
	Token _6;
	bool success_7 = false;
	Token _8;
	bool success_9 = false;
	if (!(*token == Tokens::AUTO_70))
	{
		return {}
	}
	_0 = pos;
	success_1 = true;
	pos++;
	skipspaces(pos);
	if (!(*token == Tokens::AUTO_71))
	{
		if (!(*token == Tokens::AUTO_72))
		{
			if (!(*token == Tokens::AUTO_73))
			{
				return {}
			}
			else 
			{
				_8 = pos;
				success_9 = true;
				_2 = _8;
			}
		}
		else 
		{
			_6 = pos;
			success_7 = true;
			_2 = _6;
		}
	}
	else 
	{
		_4 = pos;
		success_5 = true;
		_2 = _4;
	}
	_2 += *(pos + 0);
	success_3 = true;
	pos++;
	spacemode_data data = _0;
}
Parser::Parser::Rule_res linear_comment(Token* &pos, const Token_sequence &tokens) {
	Token _0;
	bool success_1 = false;
	Token _2;
	bool success_3 = false;
	arr_t<Token> shadow_4;
	if (!(*token == Tokens::AUTO_74))
	{
		return {}
	}
	_0 = pos;
	success_1 = true;
	pos++;
	skipspaces(pos);
	while (*token == Tokens::AUTO_75)
	{
		_2 += pos;
		success_3 = true;
		pos++;
		shadow_4.push(_2);
	}
}
Parser::Parser::Rule_res main(Token* &pos, const Token_sequence &tokens) {
	Rule _0;
	bool success_1 = false;
	Rule _2;
	bool success_3 = false;
	Rule _4;
	bool success_5 = false;
	Rule _6;
	bool success_7 = false;
	_2 = use(tokens);
	if (!(_2.status))
	{
		_4 = Rule(tokens);
		if (!(_4.status))
		{
			_6 = spacemode(tokens);
			if (!(_6.status))
			{
				return {}
			}
			else 
			{
				success_7 = true;
				_0 = _6;
			}
		}
		else 
		{
			success_5 = true;
			_0 = _4;
		}
	}
	else 
	{
		success_3 = true;
		_0 = _2;
	}
	_0 += *(pos + 0);
	success_1 = true;
	pos++;
}
Parser::Parser::Rule_res use_unit(Token* &pos, const Token_sequence &tokens) {
	Rule _0;
	bool success_1 = false;
	Rule _2;
	bool success_3 = false;
	_0 = id(tokens);
	if (!(_0.status))
	{
		return {}
	}
	success_1 = true;
	pos++;
	skipspaces(pos);
	_2 = any_data(tokens);
	if (_2.status)
	{
		success_3 = true;
		pos++;
	}
	use_unit_data data;
	data.value = _2;
	data.name = _0;

}
Parser::Parser::Rule_res use(Token* &pos, const Token_sequence &tokens) {
	Token _0;
	bool success_1 = false;
	Rule _2;
	bool success_3 = false;
	arr_t<str_t> shadow_11;
	str_t _4;
	bool success_5 = false;
	Token _6;
	bool success_7 = false;
	Rule _8;
	bool success_9 = false;
	if (!(*token == Tokens::AUTO_76))
	{
		return {}
	}
	_0 = pos;
	success_1 = true;
	pos++;
	skipspaces(pos);
	_2 = use_unit(tokens);
	if (!(_2.status))
	{
		return {}
	}
	success_3 = true;
	pos++;
	skipspaces(pos);
	auto begin_10 = pos;
	while (1)
	{
		if (!(*token == Tokens::AUTO_77))
		{
			break;
		}
		_6 = pos;
		success_7 = true;
		begin_10++;
		skipspaces(pos);
		_8 = use_unit(tokens);
		if (!(_8.status))
		{
			break;
		}
		success_9 = true;
		begin_10++;
		shadow_11.push(_4);
	}
	if (success_9)
	{
		success_5 = true;
		pos = begin_10;
	}
	_4 += _6;
	_4 += _8;
	use_data data;
	data.second = _8;
	data.first = _2;

}
Parser::Parser::Rule_res Rule_rule(Token* &pos, const Token_sequence &tokens) {
	any_t _0;
	bool success_1 = false;
	str_t _2;
	bool success_3 = false;
	any_t _4;
	bool success_5 = false;
	any_t _6;
	bool success_7 = false;
	Rule _8;
	bool success_9 = false;
	Rule _10;
	bool success_11 = false;
	Token _12;
	bool success_13 = false;
	Rule _14;
	bool success_15 = false;
	Rule _16;
	bool success_17 = false;
	Rule _18;
	bool success_19 = false;
	Rule _20;
	bool success_21 = false;
	Rule _23;
	bool success_24 = false;
	Rule _26;
	bool success_27 = false;
	Rule _28;
	bool success_29 = false;
	Rule _30;
	bool success_31 = false;
	Rule _32;
	bool success_33 = false;
	Rule _34;
	bool success_35 = false;
	auto begin_25 = pos;
	do
	{
		auto begin_22 = begin_25;
		_8 = Rule_group(tokens);
		if (!(_8.status))
		{
			_10 = Rule_csequence(tokens);
			if (!(_10.status))
			{
				if (!(*token == Tokens::STRING))
				{
					_14 = accessor(tokens);
					if (!(_14.status))
					{
						_16 = Rule_hex(tokens);
						if (!(_16.status))
						{
							_18 = Rule_bin(tokens);
							if (!(_18.status))
							{
								_20 = Rule_other(tokens);
								if (!(_20.status))
								{
									break;
								}
								else 
								{
									success_21 = true;
									_6 = _20;
								}
							}
							else 
							{
								success_19 = true;
								_6 = _18;
							}
						}
						else 
						{
							success_17 = true;
							_6 = _16;
						}
					}
					else 
					{
						success_15 = true;
						_6 = _14;
					}
				}
				else 
				{
					_12 = pos;
					success_13 = true;
					_6 = _12;
				}
			}
			else 
			{
				success_11 = true;
				_6 = _10;
			}
		}
		else 
		{
			success_9 = true;
			_6 = _8;
		}
		_6 += *(pos + 0);
		success_7 = true;
		begin_22++;
		if (success_7)
		{
			success_5 = true;
			begin_25 = begin_22;
		}
		skipspaces(pos);
		_23 = Rule_qualifier(tokens);
		if (_23.status)
		{
			success_24 = true;
			begin_25++;
		}
	}	while(0)
;
	if (success_24)
	{
		success_3 = true;
		pos = begin_25;
	}
	_2 += _4;
	_2 += _23;
	if (!success_3)
	{
		_26 = Rule_rule_escaped(tokens);
		if (!(_26.status))
		{
			_28 = Rule_rule_any(tokens);
			if (!(_28.status))
			{
				_30 = Rule_rule_op(tokens);
				if (!(_30.status))
				{
					_32 = cll(tokens);
					if (!(_32.status))
					{
						_34 = linear_comment(tokens);
						if (!(_34.status))
						{
							return {}
						}
						else 
						{
							success_35 = true;
							_0 = _34;
						}
					}
					else 
					{
						success_33 = true;
						_0 = _32;
					}
				}
				else 
				{
					success_31 = true;
					_0 = _30;
				}
			}
			else 
			{
				success_29 = true;
				_0 = _28;
			}
		}
		else 
		{
			success_27 = true;
			_0 = _26;
		}
	}
	else 
	{
		_0 = _2;
	}
	_0 += *(pos + 0);
	success_1 = true;
	pos++;
	Rule_rule_data data;
	data.qualifier = _6;
	data.val = _6;

}
Parser::Parser::Rule_res Rule_other(Token* &pos, const Token_sequence &tokens) {
	Token _0;
	bool success_1 = false;
	Token _2;
	bool success_3 = false;
	arr_t<str_t> shadow_11;
	str_t _4;
	bool success_5 = false;
	Token _6;
	bool success_7 = false;
	Token _8;
	bool success_9 = false;
	if (*token == Tokens::AUTO_79)
	{
		_0 = pos;
		success_1 = true;
		pos++;
	}
	skipspaces(pos);
	if (!(*token == Tokens::ID))
	{
		return {}
	}
	_2 = pos;
	success_3 = true;
	pos++;
	skipspaces(pos);
	auto begin_10 = pos;
	while (1)
	{
		if (!(*token == Tokens::AUTO_80))
		{
			break;
		}
		_6 = pos;
		success_7 = true;
		begin_10++;
		skipspaces(pos);
		if (!(*token == Tokens::ID))
		{
			break;
		}
		_8 = pos;
		success_9 = true;
		begin_10++;
		shadow_11.push(_4);
	}
	if (success_9)
	{
		success_5 = true;
		pos = begin_10;
	}
	_4 += _6;
	_4 += _8;
	Rule_other_data data;
	data.nested_name = _8;
	data.name = _2;
	data.is_nested = matched();

}
Parser::Parser::Rule_res Rule_op(Token* &pos, const Token_sequence &tokens) {
	Token _0;
	bool success_1 = false;
	Token _2;
	bool success_3 = false;
	Token _4;
	bool success_5 = false;
	Token _6;
	bool success_7 = false;
	data = ;
	auto begin_8 = pos;
	if (!(*token == Tokens::AUTO_81))
	{
		if (!(*token == Tokens::AUTO_82))
		{
			return {}
		}
		else 
		{
			_6 = pos;
			success_7 = true;
			_2 = _6;
		}
	}
	else 
	{
		_4 = pos;
		success_5 = true;
		_2 = _4;
	}
	_2 += *(pos + 0);
	success_3 = true;
	begin_8++;
	if (success_3)
	{
		success_1 = true;
		pos = begin_8;
	}
	_0 = _2;
}
Parser::Parser::Rule_res Rule_qualifier(Token* &pos, const Token_sequence &tokens) {
	Token _0;
	bool success_1 = false;
	Token _2;
	bool success_3 = false;
	Token _4;
	bool success_5 = false;
	Token _6;
	bool success_7 = false;
	Token _8;
	bool success_9 = false;
	data = ;
	auto begin_10 = pos;
	if (!(*token == Tokens::AUTO_83))
	{
		if (!(*token == Tokens::AUTO_84))
		{
			if (!(*token == Tokens::AUTO_85))
			{
				return {}
			}
			else 
			{
				_8 = pos;
				success_9 = true;
				_2 = _8;
			}
		}
		else 
		{
			_6 = pos;
			success_7 = true;
			_2 = _6;
		}
	}
	else 
	{
		_4 = pos;
		success_5 = true;
		_2 = _4;
	}
	_2 += *(pos + 0);
	success_3 = true;
	begin_10++;
	if (success_3)
	{
		success_1 = true;
		pos = begin_10;
	}
	_0 = _2;
}
Parser::Parser::Rule_res Rule_group(Token* &pos, const Token_sequence &tokens) {
	any_t name = ;
	any_t r = ;
	str_t _0;
	bool success_1 = false;
	Token _2;
	bool success_3 = false;
	any_t _4;
	bool success_5 = false;
	Rule _6;
	bool success_7 = false;
	Token _8;
	bool success_9 = false;
	Token _11;
	bool success_12 = false;
	Rule _13;
	bool success_14 = false;
	arr_t<Rule> shadow_15;
	Token _16;
	bool success_17 = false;
	auto begin_10 = pos;
	do
	{
		if (!(*token == Tokens::AUTO_86))
		{
			break;
		}
		_2 = pos;
		success_3 = true;
		begin_10++;
		skipspaces(pos);
		_6 = method_call(tokens);
		if (!(_6.status))
		{
			if (!(*token == Tokens::ID))
			{
				break;
			}
			else 
			{
				_8 = pos;
				success_9 = true;
				_4 = _8;
			}
		}
		else 
		{
			success_7 = true;
			_4 = _6;
		}
		_4 += *(pos + 0);
		success_5 = true;
		begin_10++;
	}	while(0)
;
	if (success_5)
	{
		success_1 = true;
		pos = begin_10;
	}
	_0 += _2;
	_0 += _4;
	skipspaces(pos);
	if (!(*token == Tokens::AUTO_87))
	{
		return {}
	}
	_11 = pos;
	success_12 = true;
	pos++;
	skipspaces(pos);
	_13 = Rule_rule(tokens);
	while (_13.status)
	{
		success_14 = true;
		pos++;
		shadow_15.push(_13);
		_13 = Rule_rule(tokens);
	}
	skipspaces(pos);
	if (!(*token == Tokens::AUTO_88))
	{
		return {}
	}
	_16 = pos;
	success_17 = true;
	pos++;
	Rule_group_data data;
	data.val = r;
	data.variable = name;

}
Parser::Parser::Rule_res Rule_csequence_symbol(Token* &pos, const Token_sequence &tokens) {
	Token _0;
	bool success_1 = false;
	Token _2;
	bool success_3 = false;
	Token _4;
	bool success_5 = false;
	Token _6;
	bool success_7 = false;
	Token _8;
	bool success_9 = false;
	data = ;
	auto begin_10 = pos;
	if (!(*token == Tokens::AUTO_92))
	{
		if (!(*token == Tokens::AUTO_93))
		{
			if (!(*token == Tokens::AUTO_94))
			{
				return {}
			}
			else 
			{
				_8 = pos;
				success_9 = true;
				_2 = _8;
			}
		}
		else 
		{
			_6 = pos;
			success_7 = true;
			_2 = _6;
		}
	}
	else 
	{
		_4 = pos;
		success_5 = true;
		_2 = _4;
	}
	_2 += *(pos + 0);
	success_3 = true;
	begin_10++;
	if (success_3)
	{
		success_1 = true;
		pos = begin_10;
	}
	_0 = _2;
}
Parser::Parser::Rule_res Rule_csequence_escape(Token* &pos, const Token_sequence &tokens) {
	Token _0;
	bool success_1 = false;
	Token _2;
	bool success_3 = false;
	Token _4;
	bool success_5 = false;
	data = ;
	if (!(*token == Tokens::AUTO_95))
	{
		return {}
	}
	_0 = pos;
	success_1 = true;
	pos++;
	auto begin_6 = pos;
	if (!(*token == Tokens::AUTO_96))
	{
		return {}
	}
	_4 = pos;
	success_5 = true;
	begin_6++;
	if (success_5)
	{
		success_3 = true;
		pos = begin_6;
	}
	_2 = _4;
}
Parser::Parser::Rule_res Rule_csequence_diapason(Token* &pos, const Token_sequence &tokens) {
	str_t _0;
	bool success_1 = false;
	Rule from;
	bool success_2 = false;
	Rule _3;
	bool success_4 = false;
	Token _6;
	bool success_7 = false;
	Rule to;
	bool success_8 = false;
	Rule _9;
	bool success_10 = false;
	auto begin_12 = pos;
	auto begin_5 = begin_12;
	_3 = Rule_csequence_symbol(tokens);
	if (!(_3.status))
	{
		return {}
	}
	success_4 = true;
	begin_5++;
	if (success_4)
	{
		success_2 = true;
		begin_12 = begin_5;
	}
	from = _3;
	if (!(*token == Tokens::AUTO_97))
	{
		return {}
	}
	_6 = pos;
	success_7 = true;
	begin_12++;
	auto begin_11 = begin_12;
	_9 = Rule_csequence_symbol(tokens);
	if (!(_9.status))
	{
		return {}
	}
	success_10 = true;
	begin_11++;
	if (success_10)
	{
		success_8 = true;
		begin_12 = begin_11;
	}
	to = _9;
	if (success_8)
	{
		success_1 = true;
		pos = begin_12;
	}
	_0 += from;
	_0 += _6;
	_0 += to;
	Rule_csequence_diapason_data data = {from,to};
}
Parser::Parser::Rule_res Rule_csequence(Token* &pos, const Token_sequence &tokens) {
	Token _0;
	bool success_1 = false;
	Token _2;
	bool success_3 = false;
	arr_t<Rule> shadow_14;
	Rule dt;
	bool success_4 = false;
	Rule _5;
	bool success_6 = false;
	Rule _7;
	bool success_8 = false;
	Rule _9;
	bool success_10 = false;
	Rule _11;
	bool success_12 = false;
	Token _15;
	bool success_16 = false;
	if (!(*token == Tokens::AUTO_89))
	{
		return {}
	}
	_0 = pos;
	success_1 = true;
	pos++;
	skipspaces(pos);
	if (*token == Tokens::AUTO_90)
	{
		_2 = pos;
		success_3 = true;
		pos++;
	}
	skipspaces(pos);
	auto begin_13 = pos;
	while (1)
	{
		_7 = Rule_csequence_escape(tokens);
		if (!(_7.status))
		{
			_9 = Rule_csequence_symbol(tokens);
			if (!(_9.status))
			{
				_11 = Rule_csequence_diapason(tokens);
				if (!(_11.status))
				{
					break;
				}
				else 
				{
					success_12 = true;
					_5 = _11;
				}
			}
			else 
			{
				success_10 = true;
				_5 = _9;
			}
		}
		else 
		{
			success_8 = true;
			_5 = _7;
		}
		_5 += *(pos + 0);
		success_6 = true;
		begin_13++;
		shadow_14.push(dt);
	}
	if (success_6)
	{
		success_4 = true;
		pos = begin_13;
	}
	dt = _5;
	skipspaces(pos);
	if (!(*token == Tokens::AUTO_91))
	{
		return {}
	}
	_15 = pos;
	success_16 = true;
	pos++;
	Rule_csequence_data data;
	data.val = dt;
	data.not = matched();

}
Parser::Parser::Rule_res Rule_any(Token* &pos, const Token_sequence &tokens) {
	Token _0;
	bool success_1 = false;
	if (!(*token == Tokens::AUTO_98))
	{
		return {}
	}
	_0 = pos;
	success_1 = true;
	pos++;
}
Parser::Parser::Rule_res Rule_data_block_inclosed_map(Token* &pos, const Token_sequence &tokens) {
	Rule data;
	bool success_0 = false;
	Rule _1;
	bool success_2 = false;
	arr_t<Rule> shadow_3;
	bool success_4 = false;
	auto begin_5 = pos;
	_1 = Rule_data_block_key(tokens);
	while (_1.status)
	{
		success_2 = true;
		begin_5++;
		shadow_3.push(_1);
		_1 = Rule_data_block_key(tokens);
		success_4 = true;
	}
	if (!success_4)
	{
		return {}
	}
	if (success_2)
	{
		success_0 = true;
		pos = begin_5;
	}
	data = _1;
}
Parser::Parser::Rule_res Rule_data_block_key(Token* &pos, const Token_sequence &tokens) {
	Token _0;
	bool success_1 = false;
	arr_t<Token> shadow_2;
	bool success_3 = false;
	Rule name;
	bool success_4 = false;
	Rule _5;
	bool success_6 = false;
	Token _8;
	bool success_9 = false;
	Rule dt;
	bool success_10 = false;
	Rule _11;
	bool success_12 = false;
	Rule _13;
	bool success_14 = false;
	Rule _15;
	bool success_16 = false;
	while (*token == Tokens::AUTO_103)
	{
		_0 += pos;
		success_1 = true;
		pos++;
		shadow_2.push(_0);
		success_3 = true;
	}
	if (!success_3)
	{
		return {}
	}
	skipspaces(pos);
	auto begin_7 = pos;
	_5 = id(tokens);
	if (!(_5.status))
	{
		return {}
	}
	success_6 = true;
	begin_7++;
	if (success_6)
	{
		success_4 = true;
		pos = begin_7;
	}
	name = _5;
	skipspaces(pos);
	if (!(*token == Tokens::AUTO_104))
	{
		return {}
	}
	_8 = pos;
	success_9 = true;
	pos++;
	skipspaces(pos);
	auto begin_17 = pos;
	_13 = cll_ternary(tokens);
	if (!(_13.status))
	{
		_15 = expr(tokens);
		if (!(_15.status))
		{
			return {}
		}
		else 
		{
			success_16 = true;
			_11 = _15;
		}
	}
	else 
	{
		success_14 = true;
		_11 = _13;
	}
	_11 += *(pos + 0);
	success_12 = true;
	begin_17++;
	if (success_12)
	{
		success_10 = true;
		pos = begin_17;
	}
	dt = _11;
	Rule_data_block_key_data data;
	data.val = dt;
	data.name = name;

}
Parser::Parser::Rule_res Rule_data_block(Token* &pos, const Token_sequence &tokens) {
	Token _0;
	bool success_1 = false;
	arr_t<Token> shadow_2;
	bool success_3 = false;
	Token _4;
	bool success_5 = false;
	Token _6;
	bool success_7 = false;
	Rule data;
	bool success_8 = false;
	Rule _9;
	bool success_10 = false;
	Rule _11;
	bool success_12 = false;
	Rule _13;
	bool success_14 = false;
	Token _16;
	bool success_17 = false;
	while (*token == Tokens::AUTO_99)
	{
		_0 += pos;
		success_1 = true;
		pos++;
		shadow_2.push(_0);
		success_3 = true;
	}
	if (!success_3)
	{
		return {}
	}
	skipspaces(pos);
	if (!(*token == Tokens::AUTO_100))
	{
		return {}
	}
	_4 = pos;
	success_5 = true;
	pos++;
	skipspaces(pos);
	if (!(*token == Tokens::AUTO_101))
	{
		return {}
	}
	_6 = pos;
	success_7 = true;
	pos++;
	skipspaces(pos);
	auto begin_15 = pos;
	_11 = any_data(tokens);
	if (!(_11.status))
	{
		_13 = Rule_data_block_inclosed_map(tokens);
		if (!(_13.status))
		{
			return {}
		}
		else 
		{
			success_14 = true;
			_9 = _13;
		}
	}
	else 
	{
		success_12 = true;
		_9 = _11;
	}
	_9 += *(pos + 0);
	success_10 = true;
	begin_15++;
	if (success_10)
	{
		success_8 = true;
		pos = begin_15;
	}
	data = _9;
	skipspaces(pos);
	if (!(*token == Tokens::AUTO_102))
	{
		return {}
	}
	_16 = pos;
	success_17 = true;
	pos++;
}
Parser::Parser::Rule_res Rule_escaped(Token* &pos, const Token_sequence &tokens) {
	Token _0;
	bool success_1 = false;
	Token _2;
	bool success_3 = false;
	Token _4;
	bool success_5 = false;
	if (!(*token == Tokens::AUTO_105))
	{
		return {}
	}
	_0 = pos;
	success_1 = true;
	pos++;
	if (!(*token == Tokens::AUTO_106))
	{
		return {}
	}
	_2 = pos;
	success_3 = true;
	pos++;
	if (*token == Tokens::NUMBER)
	{
		_4 = pos;
		success_5 = true;
		pos++;
	}
	Rule_escaped_data data;
	data.num = _4;
	data.c = _2;

}
Parser::Parser::Rule_res Rule_nested_rule(Token* &pos, const Token_sequence &tokens) {
	Token _0;
	bool success_1 = false;
	arr_t<Token> shadow_2;
	bool success_3 = false;
	Token _4;
	bool success_5 = false;
	Rule _6;
	bool success_7 = false;
	while (*token == Tokens::AUTO_107)
	{
		_0 += pos;
		success_1 = true;
		pos++;
		shadow_2.push(_0);
		success_3 = true;
	}
	if (!success_3)
	{
		return {}
	}
	skipspaces(pos);
	if (!(*token == Tokens::AUTO_108))
	{
		return {}
	}
	_4 = pos;
	success_5 = true;
	pos++;
	_6 = Rule(tokens);
	if (!(_6.status))
	{
		return {}
	}
	success_7 = true;
	pos++;
	Rule_nested_rule_data data = _6;
}
Parser::Parser::Rule_res Rule_hex(Token* &pos, const Token_sequence &tokens) {
	Token _0;
	bool success_1 = false;
	Token _2;
	bool success_3 = false;
	arr_t<Token> shadow_4;
	bool success_5 = false;
	if (!(*token == Tokens::AUTO_109))
	{
		return {}
	}
	_0 = pos;
	success_1 = true;
	pos++;
	skipspaces(pos);
	while (*token == Tokens::AUTO_110)
	{
		_2 += pos;
		success_3 = true;
		pos++;
		shadow_4.push(_2);
		success_5 = true;
	}
	if (!success_5)
	{
		return {}
	}
	Rule_hex_data data = _2;
}
Parser::Parser::Rule_res Rule_bin(Token* &pos, const Token_sequence &tokens) {
	Token _0;
	bool success_1 = false;
	Token _2;
	bool success_3 = false;
	arr_t<Token> shadow_4;
	bool success_5 = false;
	if (!(*token == Tokens::AUTO_111))
	{
		return {}
	}
	_0 = pos;
	success_1 = true;
	pos++;
	skipspaces(pos);
	while (*token == Tokens::AUTO_112)
	{
		_2 += pos;
		success_3 = true;
		pos++;
		shadow_4.push(_2);
		success_5 = true;
	}
	if (!success_5)
	{
		return {}
	}
	Rule_bin_data data = _2;
}
Parser::Parser::Rule_res Rule(Token* &pos, const Token_sequence &tokens) {
	any_t name = ;
	any_t rule = ;
	any_t data_block = ;
	any_t nested_rules = ;
	str_t rule_begin;
	bool success_0 = false;
	Token _1;
	bool success_2 = false;
	Token _3;
	bool success_4 = false;
	Rule _6;
	bool success_7 = false;
	arr_t<Rule> shadow_13;
	Rule _8;
	bool success_9 = false;
	Rule _10;
	bool success_11 = false;
	Rule _14;
	bool success_15 = false;
	Rule _16;
	bool success_17 = false;
	arr_t<Rule> shadow_18;
	Token _19;
	bool success_20 = false;
	auto begin_5 = pos;
	if (!(*token == Tokens::ID))
	{
		return {}
	}
	_1 = pos;
	success_2 = true;
	begin_5++;
	skipspaces(pos);
	if (!(*token == Tokens::AUTO_101))
	{
		return {}
	}
	_3 = pos;
	success_4 = true;
	begin_5++;
	if (success_4)
	{
		success_0 = true;
		pos = begin_5;
	}
	rule_begin += _1;
	rule_begin += _3;
	skipspaces(pos);
	_6 = function_body_decl(tokens);
	if (_6.status)
	{
		success_7 = true;
		pos++;
	}
	skipspaces(pos);
	auto begin_12 = pos;
	while (1)
	{
		_10 = Rule_rule(tokens);
		if (!(_10.status))
		{
			break;
		}
		success_11 = true;
		begin_12++;
		shadow_13.push(_8);
	}
	if (success_11)
	{
		success_9 = true;
		pos = begin_12;
	}
	_8 = _10;
	skipspaces(pos);
	_14 = Rule_data_block(tokens);
	if (!(_14.status))
	{
		return {}
	}
	success_15 = true;
	pos++;
	skipspaces(pos);
	_16 = Rule_nested_rule(tokens);
	while (_16.status)
	{
		success_17 = true;
		pos++;
		shadow_18.push(_16);
		_16 = Rule_nested_rule(tokens);
	}
	skipspaces(pos);
	if (!(*token == Tokens::AUTO_50))
	{
		return {}
	}
	_19 = pos;
	success_20 = true;
	pos++;
	Rule_data data;
	data.nestedRules = nested_rules;
	data.data_block = data_block;
	data.rule = rule;
	data.name = name;

}
Parser::Tokenizator::Token_res AUTO_1(const char* pos, const char* const str) {
	str_t _0;
	bool success_1 = false;
	if (!(*pos == '%'))
	{
		return {}
	}
	_0 += *(pos + 0);
	success_1 = true;
	pos++;
	AUTO_1_data data = _0;
}
Parser::Tokenizator::Token_res AUTO_3(const char* pos, const char* const str) {
	str_t _0;
	bool success_1 = false;
	if (!(*pos == '>'))
	{
		return {}
	}
	_0 += *(pos + 0);
	success_1 = true;
	pos++;
	AUTO_3_data data = _0;
}
Parser::Tokenizator::Token_res AUTO_4(const char* pos, const char* const str) {
	str_t _0;
	bool success_1 = false;
	if (!(*pos == '$'))
	{
		return {}
	}
	_0 += *(pos + 0);
	success_1 = true;
	pos++;
	AUTO_4_data data = _0;
}
Parser::Tokenizator::Token_res AUTO_14(const char* pos, const char* const str) {
	str_t _0;
	bool success_1 = false;
	if (!(!std::strncmp(pos, "unsigned", 8)))
	{
		return {}
	}
	_0 += *(pos + 0);
	success_1 = true;
	pos++;
	AUTO_14_data data = _0;
}
Parser::Tokenizator::Token_res AUTO_15(const char* pos, const char* const str) {
	str_t _0;
	bool success_1 = false;
	if (!(!std::strncmp(pos, "char", 4)))
	{
		return {}
	}
	_0 += *(pos + 0);
	success_1 = true;
	pos++;
	AUTO_15_data data = _0;
}
Parser::Tokenizator::Token_res AUTO_16(const char* pos, const char* const str) {
	str_t _0;
	bool success_1 = false;
	if (!(!std::strncmp(pos, "short", 5)))
	{
		return {}
	}
	_0 += *(pos + 0);
	success_1 = true;
	pos++;
	AUTO_16_data data = _0;
}
Parser::Tokenizator::Token_res AUTO_17(const char* pos, const char* const str) {
	str_t _0;
	bool success_1 = false;
	if (!(!std::strncmp(pos, "int", 3)))
	{
		return {}
	}
	_0 += *(pos + 0);
	success_1 = true;
	pos++;
	AUTO_17_data data = _0;
}
Parser::Tokenizator::Token_res AUTO_18(const char* pos, const char* const str) {
	str_t _0;
	bool success_1 = false;
	if (!(!std::strncmp(pos, "long", 4)))
	{
		return {}
	}
	_0 += *(pos + 0);
	success_1 = true;
	pos++;
	AUTO_18_data data = _0;
}
Parser::Tokenizator::Token_res AUTO_19(const char* pos, const char* const str) {
	str_t _0;
	bool success_1 = false;
	if (!(!std::strncmp(pos, "long long", 9)))
	{
		return {}
	}
	_0 += *(pos + 0);
	success_1 = true;
	pos++;
	AUTO_19_data data = _0;
}
Parser::Tokenizator::Token_res AUTO_20(const char* pos, const char* const str) {
	str_t _0;
	bool success_1 = false;
	if (!(!std::strncmp(pos, "float", 5)))
	{
		return {}
	}
	_0 += *(pos + 0);
	success_1 = true;
	pos++;
	AUTO_20_data data = _0;
}
Parser::Tokenizator::Token_res AUTO_21(const char* pos, const char* const str) {
	str_t _0;
	bool success_1 = false;
	if (!(!std::strncmp(pos, "double", 6)))
	{
		return {}
	}
	_0 += *(pos + 0);
	success_1 = true;
	pos++;
	AUTO_21_data data = _0;
}
Parser::Tokenizator::Token_res AUTO_22(const char* pos, const char* const str) {
	str_t _0;
	bool success_1 = false;
	if (!(!std::strncmp(pos, "deque", 5)))
	{
		return {}
	}
	_0 += *(pos + 0);
	success_1 = true;
	pos++;
	AUTO_22_data data = _0;
}
Parser::Tokenizator::Token_res AUTO_23(const char* pos, const char* const str) {
	str_t _0;
	bool success_1 = false;
	if (!(!std::strncmp(pos, "vector", 6)))
	{
		return {}
	}
	_0 += *(pos + 0);
	success_1 = true;
	pos++;
	AUTO_23_data data = _0;
}
Parser::Tokenizator::Token_res AUTO_24(const char* pos, const char* const str) {
	str_t _0;
	bool success_1 = false;
	if (!(!std::strncmp(pos, "queue", 5)))
	{
		return {}
	}
	_0 += *(pos + 0);
	success_1 = true;
	pos++;
	AUTO_24_data data = _0;
}
Parser::Tokenizator::Token_res AUTO_25(const char* pos, const char* const str) {
	str_t _0;
	bool success_1 = false;
	if (!(!std::strncmp(pos, "stack", 5)))
	{
		return {}
	}
	_0 += *(pos + 0);
	success_1 = true;
	pos++;
	AUTO_25_data data = _0;
}
Parser::Tokenizator::Token_res AUTO_26(const char* pos, const char* const str) {
	str_t _0;
	bool success_1 = false;
	if (!(!std::strncmp(pos, "list", 4)))
	{
		return {}
	}
	_0 += *(pos + 0);
	success_1 = true;
	pos++;
	AUTO_26_data data = _0;
}
Parser::Tokenizator::Token_res AUTO_27(const char* pos, const char* const str) {
	str_t _0;
	bool success_1 = false;
	if (!(!std::strncmp(pos, "forward_list", 12)))
	{
		return {}
	}
	_0 += *(pos + 0);
	success_1 = true;
	pos++;
	AUTO_27_data data = _0;
}
Parser::Tokenizator::Token_res AUTO_28(const char* pos, const char* const str) {
	str_t _0;
	bool success_1 = false;
	if (!(!std::strncmp(pos, "var", 3)))
	{
		return {}
	}
	_0 += *(pos + 0);
	success_1 = true;
	pos++;
	AUTO_28_data data = _0;
}
Parser::Tokenizator::Token_res AUTO_29(const char* pos, const char* const str) {
	str_t _0;
	bool success_1 = false;
	if (!(!std::strncmp(pos, "any", 3)))
	{
		return {}
	}
	_0 += *(pos + 0);
	success_1 = true;
	pos++;
	AUTO_29_data data = _0;
}
Parser::Tokenizator::Token_res AUTO_30(const char* pos, const char* const str) {
	str_t _0;
	bool success_1 = false;
	if (!(!std::strncmp(pos, "num", 3)))
	{
		return {}
	}
	_0 += *(pos + 0);
	success_1 = true;
	pos++;
	AUTO_30_data data = _0;
}
Parser::Tokenizator::Token_res AUTO_31(const char* pos, const char* const str) {
	str_t _0;
	bool success_1 = false;
	if (!(!std::strncmp(pos, "bool", 4)))
	{
		return {}
	}
	_0 += *(pos + 0);
	success_1 = true;
	pos++;
	AUTO_31_data data = _0;
}
Parser::Tokenizator::Token_res AUTO_32(const char* pos, const char* const str) {
	str_t _0;
	bool success_1 = false;
	if (!(!std::strncmp(pos, "str", 3)))
	{
		return {}
	}
	_0 += *(pos + 0);
	success_1 = true;
	pos++;
	AUTO_32_data data = _0;
}
Parser::Tokenizator::Token_res AUTO_33(const char* pos, const char* const str) {
	str_t _0;
	bool success_1 = false;
	if (!(!std::strncmp(pos, "arr", 3)))
	{
		return {}
	}
	_0 += *(pos + 0);
	success_1 = true;
	pos++;
	AUTO_33_data data = _0;
}
Parser::Tokenizator::Token_res AUTO_34(const char* pos, const char* const str) {
	str_t _0;
	bool success_1 = false;
	if (!(!std::strncmp(pos, "obj", 3)))
	{
		return {}
	}
	_0 += *(pos + 0);
	success_1 = true;
	pos++;
	AUTO_34_data data = _0;
}
Parser::Tokenizator::Token_res AUTO_35(const char* pos, const char* const str) {
	str_t _0;
	bool success_1 = false;
	if (*pos != ' ')
	{
		return {}
	}
	_0 += *(pos + 0);
	success_1 = true;
	pos++;
	AUTO_35_data data = _0;
}
Parser::Tokenizator::Token_res AUTO_36(const char* pos, const char* const str) {
	str_t _0;
	bool success_1 = false;
	if (!(!std::strncmp(pos, "if", 2)))
	{
		return {}
	}
	_0 += *(pos + 0);
	success_1 = true;
	pos++;
	AUTO_36_data data = _0;
}
Parser::Tokenizator::Token_res AUTO_48(const char* pos, const char* const str) {
	str_t _0;
	bool success_1 = false;
	if (!(!std::strncmp(pos, "while", 5)))
	{
		return {}
	}
	_0 += *(pos + 0);
	success_1 = true;
	pos++;
	AUTO_48_data data = _0;
}
Parser::Tokenizator::Token_res AUTO_54(const char* pos, const char* const str) {
	str_t _0;
	bool success_1 = false;
	if (!(*pos == '='))
	{
		return {}
	}
	_0 += *(pos + 0);
	success_1 = true;
	pos++;
	AUTO_54_data data = _0;
}
Parser::Tokenizator::Token_res AUTO_59(const char* pos, const char* const str) {
	str_t _0;
	bool success_1 = false;
	if (!(!std::strncmp(pos, "++", 2)))
	{
		return {}
	}
	_0 += *(pos + 0);
	success_1 = true;
	pos++;
	AUTO_59_data data = _0;
}
Parser::Tokenizator::Token_res AUTO_60(const char* pos, const char* const str) {
	str_t _0;
	bool success_1 = false;
	if (!(!std::strncmp(pos, "--", 2)))
	{
		return {}
	}
	_0 += *(pos + 0);
	success_1 = true;
	pos++;
	AUTO_60_data data = _0;
}
Parser::Tokenizator::Token_res AUTO_64(const char* pos, const char* const str) {
	str_t _0;
	bool success_1 = false;
	if (!(*pos == '{'))
	{
		return {}
	}
	_0 += *(pos + 0);
	success_1 = true;
	pos++;
	AUTO_64_data data = _0;
}
Parser::Tokenizator::Token_res AUTO_69(const char* pos, const char* const str) {
	str_t _0;
	bool success_1 = false;
	if (!(*pos == '}'))
	{
		return {}
	}
	_0 += *(pos + 0);
	success_1 = true;
	pos++;
	AUTO_69_data data = _0;
}
Parser::Tokenizator::Token_res AUTO_70(const char* pos, const char* const str) {
	str_t _0;
	bool success_1 = false;
	if (!(!std::strncmp(pos, "spacemode", 9)))
	{
		return {}
	}
	_0 += *(pos + 0);
	success_1 = true;
	pos++;
	AUTO_70_data data = _0;
}
Parser::Tokenizator::Token_res AUTO_71(const char* pos, const char* const str) {
	str_t _0;
	bool success_1 = false;
	if (!(!std::strncmp(pos, "mixed", 5)))
	{
		return {}
	}
	_0 += *(pos + 0);
	success_1 = true;
	pos++;
	AUTO_71_data data = _0;
}
Parser::Tokenizator::Token_res AUTO_72(const char* pos, const char* const str) {
	str_t _0;
	bool success_1 = false;
	if (!(!std::strncmp(pos, "skipped", 7)))
	{
		return {}
	}
	_0 += *(pos + 0);
	success_1 = true;
	pos++;
	AUTO_72_data data = _0;
}
Parser::Tokenizator::Token_res AUTO_73(const char* pos, const char* const str) {
	str_t _0;
	bool success_1 = false;
	if (!(!std::strncmp(pos, "allowed", 7)))
	{
		return {}
	}
	_0 += *(pos + 0);
	success_1 = true;
	pos++;
	AUTO_73_data data = _0;
}
Parser::Tokenizator::Token_res AUTO_74(const char* pos, const char* const str) {
	str_t _0;
	bool success_1 = false;
	if (!(!std::strncmp(pos, "//", 2)))
	{
		return {}
	}
	_0 += *(pos + 0);
	success_1 = true;
	pos++;
	AUTO_74_data data = _0;
}
Parser::Tokenizator::Token_res AUTO_75(const char* pos, const char* const str) {
	str_t _0;
	bool success_1 = false;
	if (!(!(*pos == '\n')))
	{
		return {}
	}
	_0 += *(pos + 0);
	success_1 = true;
	pos++;
	AUTO_75_data data = _0;
}
Parser::Tokenizator::Token_res AUTO_76(const char* pos, const char* const str) {
	str_t _0;
	bool success_1 = false;
	if (!(!std::strncmp(pos, "use", 3)))
	{
		return {}
	}
	_0 += *(pos + 0);
	success_1 = true;
	pos++;
	AUTO_76_data data = _0;
}
Parser::Tokenizator::Token_res AUTO_77(const char* pos, const char* const str) {
	str_t _0;
	bool success_1 = false;
	if (!(*pos == ','))
	{
		return {}
	}
	_0 += *(pos + 0);
	success_1 = true;
	pos++;
	AUTO_77_data data = _0;
}
Parser::Tokenizator::Token_res AUTO_81(const char* pos, const char* const str) {
	str_t _0;
	bool success_1 = false;
	if (!(*pos == '|'))
	{
		return {}
	}
	_0 += *(pos + 0);
	success_1 = true;
	pos++;
	AUTO_81_data data = _0;
}
Parser::Tokenizator::Token_res AUTO_82(const char* pos, const char* const str) {
	str_t _0;
	bool success_1 = false;
	if (!(!std::strncmp(pos, "|&", 2)))
	{
		return {}
	}
	_0 += *(pos + 0);
	success_1 = true;
	pos++;
	AUTO_82_data data = _0;
}
Parser::Tokenizator::Token_res AUTO_83(const char* pos, const char* const str) {
	str_t _0;
	bool success_1 = false;
	if (!(*pos == '?'))
	{
		return {}
	}
	_0 += *(pos + 0);
	success_1 = true;
	pos++;
	AUTO_83_data data = _0;
}
Parser::Tokenizator::Token_res AUTO_84(const char* pos, const char* const str) {
	str_t _0;
	bool success_1 = false;
	if (!(*pos == '+'))
	{
		return {}
	}
	_0 += *(pos + 0);
	success_1 = true;
	pos++;
	AUTO_84_data data = _0;
}
Parser::Tokenizator::Token_res AUTO_85(const char* pos, const char* const str) {
	str_t _0;
	bool success_1 = false;
	if (!(*pos == '*'))
	{
		return {}
	}
	_0 += *(pos + 0);
	success_1 = true;
	pos++;
	AUTO_85_data data = _0;
}
Parser::Tokenizator::Token_res AUTO_86(const char* pos, const char* const str) {
	str_t _0;
	bool success_1 = false;
	if (!(*pos == '&'))
	{
		return {}
	}
	_0 += *(pos + 0);
	success_1 = true;
	pos++;
	AUTO_86_data data = _0;
}
Parser::Tokenizator::Token_res AUTO_87(const char* pos, const char* const str) {
	str_t _0;
	bool success_1 = false;
	if (!(*pos == '('))
	{
		return {}
	}
	_0 += *(pos + 0);
	success_1 = true;
	pos++;
	AUTO_87_data data = _0;
}
Parser::Tokenizator::Token_res AUTO_88(const char* pos, const char* const str) {
	str_t _0;
	bool success_1 = false;
	if (!(*pos == ')'))
	{
		return {}
	}
	_0 += *(pos + 0);
	success_1 = true;
	pos++;
	AUTO_88_data data = _0;
}
Parser::Tokenizator::Token_res AUTO_89(const char* pos, const char* const str) {
	str_t _0;
	bool success_1 = false;
	if (!(*pos == '['))
	{
		return {}
	}
	_0 += *(pos + 0);
	success_1 = true;
	pos++;
	AUTO_89_data data = _0;
}
Parser::Tokenizator::Token_res AUTO_90(const char* pos, const char* const str) {
	str_t _0;
	bool success_1 = false;
	if (!(*pos == '^'))
	{
		return {}
	}
	_0 += *(pos + 0);
	success_1 = true;
	pos++;
	AUTO_90_data data = _0;
}
Parser::Tokenizator::Token_res AUTO_91(const char* pos, const char* const str) {
	str_t _0;
	bool success_1 = false;
	if (!(*pos == ']'))
	{
		return {}
	}
	_0 += *(pos + 0);
	success_1 = true;
	pos++;
	AUTO_91_data data = _0;
}
Parser::Tokenizator::Token_res AUTO_93(const char* pos, const char* const str) {
	str_t _0;
	bool success_1 = false;
	if (!(!std::strncmp(pos, "\\]", 2)))
	{
		return {}
	}
	_0 += *(pos + 0);
	success_1 = true;
	pos++;
	AUTO_93_data data = _0;
}
Parser::Tokenizator::Token_res AUTO_94(const char* pos, const char* const str) {
	str_t _0;
	bool success_1 = false;
	if (!(!(*pos == ']')))
	{
		return {}
	}
	_0 += *(pos + 0);
	success_1 = true;
	pos++;
	AUTO_94_data data = _0;
}
Parser::Tokenizator::Token_res AUTO_97(const char* pos, const char* const str) {
	str_t _0;
	bool success_1 = false;
	if (!(*pos == '-'))
	{
		return {}
	}
	_0 += *(pos + 0);
	success_1 = true;
	pos++;
	AUTO_97_data data = _0;
}
Parser::Tokenizator::Token_res AUTO_98(const char* pos, const char* const str) {
	str_t _0;
	bool success_1 = false;
	if (!(*pos == '.'))
	{
		return {}
	}
	_0 += *(pos + 0);
	success_1 = true;
	pos++;
	AUTO_98_data data = _0;
}
Parser::Tokenizator::Token_res AUTO_100(const char* pos, const char* const str) {
	str_t _0;
	bool success_1 = false;
	if (!(!std::strncmp(pos, "data", 4)))
	{
		return {}
	}
	_0 += *(pos + 0);
	success_1 = true;
	pos++;
	AUTO_100_data data = _0;
}
Parser::Tokenizator::Token_res AUTO_102(const char* pos, const char* const str) {
	str_t _0;
	bool success_1 = false;
	if (!(*pos == ';'))
	{
		return {}
	}
	_0 += *(pos + 0);
	success_1 = true;
	pos++;
	AUTO_102_data data = _0;
}
Parser::Tokenizator::Token_res AUTO_103(const char* pos, const char* const str) {
	str_t _0;
	bool success_1 = false;
	if (!(*pos == '\n' || *pos == '\r'))
	{
		return {}
	}
	_0 += *(pos + 0);
	success_1 = true;
	pos++;
	AUTO_103_data data = _0;
}
Parser::Tokenizator::Token_res AUTO_104(const char* pos, const char* const str) {
	str_t _0;
	bool success_1 = false;
	if (!(*pos == ':'))
	{
		return {}
	}
	_0 += *(pos + 0);
	success_1 = true;
	pos++;
	AUTO_104_data data = _0;
}
Parser::Tokenizator::Token_res AUTO_105(const char* pos, const char* const str) {
	str_t _0;
	bool success_1 = false;
	if (!(!std::strncmp(pos, "\\", 1)))
	{
		return {}
	}
	_0 += *(pos + 0);
	success_1 = true;
	pos++;
	AUTO_105_data data = _0;
}
Parser::Tokenizator::Token_res AUTO_106(const char* pos, const char* const str) {
	UNDEF _0;
	bool success_1 = false;
	if (*pos == '\0')
	{
		return {}
	}
	_0 += *(pos + 0);
	success_1 = true;
	pos++;
	AUTO_106_data data = _0;
}
Parser::Tokenizator::Token_res AUTO_107(const char* pos, const char* const str) {
	str_t _0;
	bool success_1 = false;
	if (!(*pos == '\r' || *pos == '\n'))
	{
		return {}
	}
	_0 += *(pos + 0);
	success_1 = true;
	pos++;
	AUTO_107_data data = _0;
}
Parser::Tokenizator::Token_res AUTO_108(const char* pos, const char* const str) {
	str_t _0;
	bool success_1 = false;
	if (!(*pos == '#'))
	{
		return {}
	}
	_0 += *(pos + 0);
	success_1 = true;
	pos++;
	AUTO_108_data data = _0;
}
Parser::Tokenizator::Token_res AUTO_109(const char* pos, const char* const str) {
	str_t _0;
	bool success_1 = false;
	if (!(!std::strncmp(pos, "0x", 2)))
	{
		return {}
	}
	_0 += *(pos + 0);
	success_1 = true;
	pos++;
	AUTO_109_data data = _0;
}
Parser::Tokenizator::Token_res AUTO_110(const char* pos, const char* const str) {
	str_t _0;
	bool success_1 = false;
	if (!((*pos>='1' && *pos<='9') || (*pos>='A' && *pos<='F') || (*pos>='a' && *pos<='f')))
	{
		return {}
	}
	_0 += *(pos + 0);
	success_1 = true;
	pos++;
	AUTO_110_data data = _0;
}
Parser::Tokenizator::Token_res AUTO_111(const char* pos, const char* const str) {
	str_t _0;
	bool success_1 = false;
	if (!(!std::strncmp(pos, "0b", 2)))
	{
		return {}
	}
	_0 += *(pos + 0);
	success_1 = true;
	pos++;
	AUTO_111_data data = _0;
}
Parser::Tokenizator::Token_res AUTO_112(const char* pos, const char* const str) {
	str_t _0;
	bool success_1 = false;
	if (!(*pos == '0' || *pos == '1'))
	{
		return {}
	}
	_0 += *(pos + 0);
	success_1 = true;
	pos++;
	AUTO_112_data data = _0;
}
