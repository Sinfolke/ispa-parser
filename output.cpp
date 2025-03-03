Parser::Rule_res accessor_group() {
	Token _0
	bool success_1 = false
	Token _2
	bool success_3 = false
	if (!(CURRENT_TOKEN == "AUTO_4"))
	{
		return {}
	}
	_0 = *pos
	success_1 = true
	pos++
	skipspaces(TOKEN_SEQUENCE)
	if (!(CURRENT_TOKEN == "NUMBER"))
	{
		return {}
	}
	_2 = *pos
	success_3 = true
	pos++
	data = _2
}
Parser::Rule_res accessor_element() {
	Token _0
	bool success_1 = false
	Token _2
	bool success_3 = false
	if (!(CURRENT_TOKEN == "AUTO_1"))
	{
		return {}
	}
	_0 = *pos
	success_1 = true
	pos++
	skipspaces(TOKEN_SEQUENCE)
	if (!(CURRENT_TOKEN == "NUMBER"))
	{
		return {}
	}
	_2 = *pos
	success_3 = true
	pos++
	data = _2
}
Parser::Rule_res accessor_char() {
	Token _0
	bool success_1 = false
	Token _2
	bool success_3 = false
	if (!(CURRENT_TOKEN == "AUTO_90"))
	{
		return {}
	}
	_0 = *pos
	success_1 = true
	pos++
	skipspaces(TOKEN_SEQUENCE)
	if (!(CURRENT_TOKEN == "NUMBER"))
	{
		return {}
	}
	_2 = *pos
	success_3 = true
	pos++
	data = _2
}
Parser::Rule_res accessor_all() {
	Rule _0
	bool success_1 = false
	Rule _2
	bool success_3 = false
	Rule _4
	bool success_5 = false
	Rule _6
	bool success_7 = false
	_2 = accessor_group(tokens)
	if (!(_2.status))
	{
		_4 = accessor_element(tokens)
		if (!(_4.status))
		{
			_6 = accessor_char(tokens)
			if (!(_6.status))
			{
				return {}
			}
			else 
			{
				success_7 = true
				_0 = _6
			}
		}
		else 
		{
			success_5 = true
			_0 = _4
		}
	}
	else 
	{
		success_3 = true
		_0 = _2
	}
	_0 += *(pos0)
	success_1 = true
	pos++
	data = _0
}
Parser::Rule_res accessor() {
	Rule _0
	bool success_1 = false
	ISPA_STR_TYPE _2
	bool success_3 = false
	Token _4
	bool success_5 = false
	Rule _6
	bool success_7 = false
	_0 = accessor_all(tokens)
	if (!(_0.status))
	{
		return {}
	}
	success_1 = true
	pos++
	skipspaces(TOKEN_SEQUENCE)
	auto begin_8 = pos
	while (1)
	{
		if (!(CURRENT_TOKEN == "AUTO_3"))
		{
			break
		}
		_4 = *pos
		success_5 = true
		begin_8++
		skipspaces(TOKEN_SEQUENCE)
		_6 = accessor_all(tokens)
		if (!(_6.status))
		{
			break
		}
		success_7 = true
		begin_8++
	}
	if (success_7)
	{
		success_3 = true
		pos = begin_8
	}
	_2 += _4
	_2 += _6
	data = 
		second: _6
		first: _0
	;
}
Parser::Rule_res cll() {
	Token cll_begin
	bool success_0 = false
	Token _1
	bool success_2 = false
	ISPA_STR_TYPE _4
	bool success_5 = false
	bool success_28 = false
	Rule _6
	bool success_7 = false
	Rule _8
	bool success_9 = false
	Rule _10
	bool success_11 = false
	Rule _12
	bool success_13 = false
	Rule _14
	bool success_15 = false
	Rule _16
	bool success_17 = false
	Rule _18
	bool success_19 = false
	Rule _20
	bool success_21 = false
	Rule _22
	bool success_23 = false
	Token _25
	bool success_26 = false
	auto begin_3 = pos
	if (!(CURRENT_TOKEN == "AUTO_4"))
	{
		return {}
	}
	_1 = *pos
	success_2 = true
	begin_3++
	if (success_2)
	{
		success_0 = true
		pos = begin_3
	}
	cll_begin = _1
	skipspaces(TOKEN_SEQUENCE)
	auto begin_27 = pos
	while (1)
	{
		auto begin_24 = begin_27
		_10 = cll_var(tokens)
		if (!(_10.status))
		{
			_12 = cll_if(tokens)
			if (!(_12.status))
			{
				_14 = expr(tokens)
				if (!(_14.status))
				{
					_16 = copiable_method_call(tokens)
					if (!(_16.status))
					{
						_18 = method_call(tokens)
						if (!(_18.status))
						{
							_20 = loop_while(tokens)
							if (!(_20.status))
							{
								_22 = loop_for(tokens)
								if (!(_22.status))
								{
									break
								}
								else 
								{
									success_23 = true
									_8 = _22
								}
							}
							else 
							{
								success_21 = true
								_8 = _20
							}
						}
						else 
						{
							success_19 = true
							_8 = _18
						}
					}
					else 
					{
						success_17 = true
						_8 = _16
					}
				}
				else 
				{
					success_15 = true
					_8 = _14
				}
			}
			else 
			{
				success_13 = true
				_8 = _12
			}
		}
		else 
		{
			success_11 = true
			_8 = _10
		}
		_8 += *(pos0)
		success_9 = true
		begin_24++
		if (success_9)
		{
			success_7 = true
			begin_27 = begin_24
		}
		_6 = _8
		skipspaces(TOKEN_SEQUENCE)
		if (!(CURRENT_TOKEN == "END"))
		{
			break
		}
		_25 = *pos
		success_26 = true
		begin_27++
		success_28 = true
	}
	if (!success_28)
	{
		return {}
	}
	if (success_26)
	{
		success_5 = true
		pos = begin_27
	}
	_4 += _6
	_4 += _25
	data = _4
}
Parser::Rule_res cll_block() {
	Token _0
	bool success_1 = false
	Rule _2
	bool success_3 = false
	ISPA_ARRAY_TYPE<Rule> shadow_4
	Token _5
	bool success_6 = false
	if (!(CURRENT_TOKEN == "AUTO_64"))
	{
		return {}
	}
	_0 = *pos
	success_1 = true
	pos++
	skipspaces(TOKEN_SEQUENCE)
	_2 = Rule_rule(tokens)
	while (_2.status)
	{
		success_3 = true
		pos++
		shadow_4.push(_2)
		_2 = Rule_rule(tokens)
	}
	skipspaces(TOKEN_SEQUENCE)
	if (!(CURRENT_TOKEN == "AUTO_69"))
	{
		return {}
	}
	_5 = *pos
	success_6 = true
	pos++
	data = _2
}
Parser::Rule_res cll_spaced_block() {
	Rule _0
	bool success_1 = false
	while ((skipup(" ")>spaces_amount))
	{
		_0 = Rule_rule(tokens)
		if (!(_0.status))
		{
			return {}
		}
		success_1 = true
		pos++
		skipspaces(TOKEN_SEQUENCE)
	}
	data = _0
}
Parser::Token_res OP() {
	ISPA_ANY_TYPE _0
	bool success_1 = false
	ISPA_STR_TYPE _2
	bool success_3 = false
	if (!(*pos == '+'))
	{
		ISPA_STR_TYPE _4
		bool success_5 = false
		if (!(*pos == '-'))
		{
			ISPA_STR_TYPE _6
			bool success_7 = false
			if (!(*pos == '*'))
			{
				ISPA_STR_TYPE _8
				bool success_9 = false
				if (!(*pos == '/'))
				{
					ISPA_STR_TYPE _10
					bool success_11 = false
					if (!(*pos == '%'))
					{
					}
					else 
					{
						_10 += *(pos0)
						success_11 = true
						_0 = _10
					}
				}
				else 
				{
					_8 += *(pos0)
					success_9 = true
					_0 = _8
				}
			}
			else 
			{
				_6 += *(pos0)
				success_7 = true
				_0 = _6
			}
		}
		else 
		{
			_4 += *(pos0)
			success_5 = true
			_0 = _4
		}
	}
	else 
	{
		_2 += *(pos0)
		success_3 = true
		_0 = _2
	}
	_0 += *(pos0)
	success_1 = true
	pos++
	skipspaces(pos)
	ISPA_STR_TYPE _12
	bool success_13 = false
	ISPA_STR_TYPE _14
	bool success_15 = false
	if (!(*pos == '&'))
	{
		ISPA_STR_TYPE _16
		bool success_17 = false
		if (!(*pos == '|'))
		{
			ISPA_STR_TYPE _18
			bool success_19 = false
			if (!(*pos == '^'))
			{
				ISPA_STR_TYPE _20
				bool success_21 = false
				if (!(!std::strncmp(pos, "<<", 2)))
				{
					ISPA_STR_TYPE _22
					bool success_23 = false
					if (!(!std::strncmp(pos, ">>", 2)))
					{
						return {}
					}
					else 
					{
						_22 += *(pos0)
						success_23 = true
						_12 = _22
					}
				}
				else 
				{
					_20 += *(pos0)
					success_21 = true
					_12 = _20
				}
			}
			else 
			{
				_18 += *(pos0)
				success_19 = true
				_12 = _18
			}
		}
		else 
		{
			_16 += *(pos0)
			success_17 = true
			_12 = _16
		}
	}
	else 
	{
		_14 += *(pos0)
		success_15 = true
		_12 = _14
	}
	_12 += *(pos0)
	success_13 = true
	pos++
	data = _0
}
Parser::Token_res ASSIGNMENT_OP() {
	Token _0
	bool success_1 = false
	_0 = OP(tokens)
	if (_0.status)
	{
		success_1 = true
		pos++
	}
	skipspaces(pos)
	Token _2
	bool success_3 = false
	_2 = AUTO_54(tokens)
	if (!(_2.status))
	{
		return {}
	}
	success_3 = true
	pos++
	data = _0
}
Parser::Token_res COMPARE_OP() {
	ISPA_STR_TYPE _0
	bool success_1 = false
	ISPA_STR_TYPE _2
	bool success_3 = false
	if (!(!std::strncmp(pos, "==", 2)))
	{
		ISPA_STR_TYPE _4
		bool success_5 = false
		if (!(!std::strncmp(pos, "!=", 2)))
		{
			ISPA_STR_TYPE _6
			bool success_7 = false
			if (!(*pos == '>'))
			{
				ISPA_STR_TYPE _8
				bool success_9 = false
				if (!(*pos == '<'))
				{
					ISPA_STR_TYPE _10
					bool success_11 = false
					if (!(!std::strncmp(pos, ">=", 2)))
					{
						ISPA_STR_TYPE _12
						bool success_13 = false
						if (!(!std::strncmp(pos, "<=", 2)))
						{
							return {}
						}
						else 
						{
							_12 += *(pos0)
							success_13 = true
							_0 = _12
						}
					}
					else 
					{
						_10 += *(pos0)
						success_11 = true
						_0 = _10
					}
				}
				else 
				{
					_8 += *(pos0)
					success_9 = true
					_0 = _8
				}
			}
			else 
			{
				_6 += *(pos0)
				success_7 = true
				_0 = _6
			}
		}
		else 
		{
			_4 += *(pos0)
			success_5 = true
			_0 = _4
		}
	}
	else 
	{
		_2 += *(pos0)
		success_3 = true
		_0 = _2
	}
	_0 += *(pos0)
	success_1 = true
	pos++
	data = _0
}
Parser::Token_res LOGICAL_OP() {
	Token _0
	bool success_1 = false
	Token _2
	bool success_3 = false
	_2 = LOGICAL_AND(tokens)
	if (!(_2.status))
	{
		Token _4
		bool success_5 = false
		_4 = LOGICAL_OR(tokens)
		if (!(_4.status))
		{
			return {}
		}
		else 
		{
			success_5 = true
			_0 = _4
		}
	}
	else 
	{
		success_3 = true
		_0 = _2
	}
	_0 += *(pos0)
	success_1 = true
	pos++
	data = _0
}
Parser::Token_res LOGICAL_NOT() {
	ISPA_STR_TYPE _0
	bool success_1 = false
	ISPA_STR_TYPE _2
	bool success_3 = false
	if (!(*pos == '!'))
	{
		ISPA_STR_TYPE _4
		bool success_5 = false
		if (!(!std::strncmp(pos, "not", 3)))
		{
			return {}
		}
		else 
		{
			_4 += *(pos0)
			success_5 = true
			_0 = _4
		}
	}
	else 
	{
		_2 += *(pos0)
		success_3 = true
		_0 = _2
	}
	_0 += *(pos0)
	success_1 = true
	pos++
	data = _0
}
Parser::Token_res LOGICAL_AND() {
	ISPA_STR_TYPE _0
	bool success_1 = false
	ISPA_STR_TYPE _2
	bool success_3 = false
	if (!(!std::strncmp(pos, "&&", 2)))
	{
		ISPA_STR_TYPE _4
		bool success_5 = false
		if (!(!std::strncmp(pos, "and", 3)))
		{
			return {}
		}
		else 
		{
			_4 += *(pos0)
			success_5 = true
			_0 = _4
		}
	}
	else 
	{
		_2 += *(pos0)
		success_3 = true
		_0 = _2
	}
	_0 += *(pos0)
	success_1 = true
	pos++
	data = _0
}
Parser::Token_res LOGICAL_OR() {
	ISPA_STR_TYPE _0
	bool success_1 = false
	ISPA_STR_TYPE _2
	bool success_3 = false
	if (!(!std::strncmp(pos, "||", 2)))
	{
		ISPA_STR_TYPE _4
		bool success_5 = false
		if (!(!std::strncmp(pos, "or", 2)))
		{
			return {}
		}
		else 
		{
			_4 += *(pos0)
			success_5 = true
			_0 = _4
		}
	}
	else 
	{
		_2 += *(pos0)
		success_3 = true
		_0 = _2
	}
	_0 += *(pos0)
	success_1 = true
	pos++
	data = _0
}
Parser::Token_res LOGICAL_ANDR() {
	ISPA_ANY_TYPE _0
	bool success_1 = false
	ISPA_STR_TYPE _2
	bool success_3 = false
	if (!(!std::strncmp(pos, "|&", 2)))
	{
		ISPA_STR_TYPE _4
		bool success_5 = false
		auto begin_12 = pos
		do
		{
			ISPA_STR_TYPE _6
			bool success_7 = false
			if (!(!std::strncmp(pos, "and", 3)))
			{
				break
			}
			_6 += *(pos0)
			success_7 = true
			begin_12++
			ISPA_STR_TYPE _8
			bool success_9 = false
			if (*pos != ' ')
			{
				break
			}
			_8 += *(pos0)
			success_9 = true
			begin_12++
			ISPA_STR_TYPE _10
			bool success_11 = false
			if (!(!std::strncmp(pos, "or", 2)))
			{
				break
			}
			_10 += *(pos0)
			success_11 = true
			begin_12++
		}		while(0)

		if (success_11)
		{
			success_5 = true
			pos = begin_12
		}
		_4 += _6
		_4 += _8
		_4 += _10
		if (!success_5)
		{
			return {}
		}
		else 
		{
			_0 = _4
		}
	}
	else 
	{
		_2 += *(pos0)
		success_3 = true
		_0 = _2
	}
	_0 += *(pos0)
	success_1 = true
	pos++
	data = _6
}
Parser::Rule_res cll_template_content_typename() {
	Rule _0
	bool success_1 = false
	ISPA_STR_TYPE _2
	bool success_3 = false
	Token _4
	bool success_5 = false
	Rule _6
	bool success_7 = false
	_0 = cll_type(tokens)
	if (!(_0.status))
	{
		return {}
	}
	success_1 = true
	pos++
	skipspaces(TOKEN_SEQUENCE)
	auto begin_8 = pos
	while (1)
	{
		if (!(CURRENT_TOKEN == "AUTO_8"))
		{
			break
		}
		_4 = *pos
		success_5 = true
		begin_8++
		skipspaces(TOKEN_SEQUENCE)
		_6 = cll_type(tokens)
		if (!(_6.status))
		{
			break
		}
		success_7 = true
		begin_8++
	}
	if (success_7)
	{
		success_3 = true
		pos = begin_8
	}
	_2 += _4
	_2 += _6
	data = {,,}
}
Parser::Rule_res cll_template_content_int() {
	Token _0
	bool success_1 = false
	ISPA_STR_TYPE _2
	bool success_3 = false
	Token _4
	bool success_5 = false
	Token _6
	bool success_7 = false
	if (!(CURRENT_TOKEN == "NUMBER"))
	{
		return {}
	}
	_0 = *pos
	success_1 = true
	pos++
	skipspaces(TOKEN_SEQUENCE)
	auto begin_8 = pos
	while (1)
	{
		if (!(CURRENT_TOKEN == "AUTO_9"))
		{
			break
		}
		_4 = *pos
		success_5 = true
		begin_8++
		skipspaces(TOKEN_SEQUENCE)
		if (!(CURRENT_TOKEN == "NUMBER"))
		{
			break
		}
		_6 = *pos
		success_7 = true
		begin_8++
	}
	if (success_7)
	{
		success_3 = true
		pos = begin_8
	}
	_2 += _4
	_2 += _6
	data = {,,}
}
Parser::Rule_res cll_template_content_bool() {
	Token _0
	bool success_1 = false
	ISPA_STR_TYPE _2
	bool success_3 = false
	Token _4
	bool success_5 = false
	Token _6
	bool success_7 = false
	if (!(CURRENT_TOKEN == "BOOLEAN"))
	{
		return {}
	}
	_0 = *pos
	success_1 = true
	pos++
	skipspaces(TOKEN_SEQUENCE)
	auto begin_8 = pos
	while (1)
	{
		if (!(CURRENT_TOKEN == "AUTO_10"))
		{
			break
		}
		_4 = *pos
		success_5 = true
		begin_8++
		skipspaces(TOKEN_SEQUENCE)
		if (!(CURRENT_TOKEN == "BOOLEAN"))
		{
			break
		}
		_6 = *pos
		success_7 = true
		begin_8++
	}
	if (success_7)
	{
		success_3 = true
		pos = begin_8
	}
	_2 += _4
	_2 += _6
	data = {,,}
}
Parser::Rule_res cll_template_content_str() {
	Token _0
	bool success_1 = false
	ISPA_STR_TYPE _2
	bool success_3 = false
	Token _4
	bool success_5 = false
	Token _6
	bool success_7 = false
	if (!(CURRENT_TOKEN == "STRING"))
	{
		return {}
	}
	_0 = *pos
	success_1 = true
	pos++
	skipspaces(TOKEN_SEQUENCE)
	auto begin_8 = pos
	while (1)
	{
		if (!(CURRENT_TOKEN == "AUTO_11"))
		{
			break
		}
		_4 = *pos
		success_5 = true
		begin_8++
		skipspaces(TOKEN_SEQUENCE)
		if (!(CURRENT_TOKEN == "STRING"))
		{
			break
		}
		_6 = *pos
		success_7 = true
		begin_8++
	}
	if (success_7)
	{
		success_3 = true
		pos = begin_8
	}
	_2 += _4
	_2 += _6
	data = {,,}
}
Parser::Rule_res cll_template_content_arr() {
	Rule _0
	bool success_1 = false
	ISPA_STR_TYPE _2
	bool success_3 = false
	Token _4
	bool success_5 = false
	Rule _6
	bool success_7 = false
	_0 = array(tokens)
	if (!(_0.status))
	{
		return {}
	}
	success_1 = true
	pos++
	skipspaces(TOKEN_SEQUENCE)
	auto begin_8 = pos
	while (1)
	{
		if (!(CURRENT_TOKEN == "AUTO_12"))
		{
			break
		}
		_4 = *pos
		success_5 = true
		begin_8++
		skipspaces(TOKEN_SEQUENCE)
		_6 = array(tokens)
		if (!(_6.status))
		{
			break
		}
		success_7 = true
		begin_8++
	}
	if (success_7)
	{
		success_3 = true
		pos = begin_8
	}
	_2 += _4
	_2 += _6
	data = {,,}
}
Parser::Rule_res cll_template_content_obj() {
	Rule _0
	bool success_1 = false
	ISPA_STR_TYPE _2
	bool success_3 = false
	Token _4
	bool success_5 = false
	Rule _6
	bool success_7 = false
	_0 = object(tokens)
	if (!(_0.status))
	{
		return {}
	}
	success_1 = true
	pos++
	skipspaces(TOKEN_SEQUENCE)
	auto begin_8 = pos
	while (1)
	{
		if (!(CURRENT_TOKEN == "AUTO_13"))
		{
			break
		}
		_4 = *pos
		success_5 = true
		begin_8++
		skipspaces(TOKEN_SEQUENCE)
		_6 = object(tokens)
		if (!(_6.status))
		{
			break
		}
		success_7 = true
		begin_8++
	}
	if (success_7)
	{
		success_3 = true
		pos = begin_8
	}
	_2 += _4
	_2 += _6
	data = {,,}
}
Parser::Rule_res cll_template_content_any_data() {
	Rule _0
	bool success_1 = false
	ISPA_STR_TYPE _2
	bool success_3 = false
	Token _4
	bool success_5 = false
	Rule _6
	bool success_7 = false
	_0 = any_data(tokens)
	if (!(_0.status))
	{
		return {}
	}
	success_1 = true
	pos++
	skipspaces(TOKEN_SEQUENCE)
	auto begin_8 = pos
	while (1)
	{
		if (!(CURRENT_TOKEN == "AUTO_62"))
		{
			break
		}
		_4 = *pos
		success_5 = true
		begin_8++
		skipspaces(TOKEN_SEQUENCE)
		_6 = any_data(tokens)
		if (!(_6.status))
		{
			break
		}
		success_7 = true
		begin_8++
	}
	if (success_7)
	{
		success_3 = true
		pos = begin_8
	}
	_2 += _4
	_2 += _6
	data = {,,}
}
Parser::Rule_res cll_csupport_types() {
	bool is_unsigned = matched()
	ISPA_STR_TYPE _0
	bool success_1 = false
	ISPA_STR_TYPE _2
	bool success_3 = false
	Token _4
	bool success_5 = false
	Token _6
	bool success_7 = false
	Token _8
	bool success_9 = false
	Token _10
	bool success_11 = false
	Token _12
	bool success_13 = false
	Token _14
	bool success_15 = false
	Token _16
	bool success_17 = false
	Token _18
	bool success_19 = false
	Token _22
	bool success_23 = false
	Token _24
	bool success_25 = false
	Token _26
	bool success_27 = false
	Token _28
	bool success_29 = false
	Token _31
	bool success_32 = false
	Token _33
	bool success_34 = false
	Token _35
	bool success_36 = false
	Token _37
	bool success_38 = false
	Token _39
	bool success_40 = false
	Token _41
	bool success_42 = false
	Token _43
	bool success_44 = false
	Token _45
	bool success_46 = false
	Rule _48
	bool success_49 = false
	auto begin_21 = pos
	do
	{
		if (CURRENT_TOKEN == "AUTO_14")
		{
			_4 = *pos
			success_5 = true
			begin_21++
		}
		skipspaces(TOKEN_SEQUENCE)
		auto begin_20 = begin_21
		if (!(CURRENT_TOKEN == "AUTO_15"))
		{
			if (!(CURRENT_TOKEN == "AUTO_16"))
			{
				if (!(CURRENT_TOKEN == "AUTO_17"))
				{
					if (!(CURRENT_TOKEN == "AUTO_18"))
					{
						if (!(CURRENT_TOKEN == "AUTO_19"))
						{
							break
						}
						else 
						{
							_18 = *pos
							success_19 = true
							_8 = _18
						}
					}
					else 
					{
						_16 = *pos
						success_17 = true
						_8 = _16
					}
				}
				else 
				{
					_14 = *pos
					success_15 = true
					_8 = _14
				}
			}
			else 
			{
				_12 = *pos
				success_13 = true
				_8 = _12
			}
		}
		else 
		{
			_10 = *pos
			success_11 = true
			_8 = _10
		}
		_8 += *(pos0)
		success_9 = true
		begin_20++
		if (success_9)
		{
			success_7 = true
			begin_21 = begin_20
		}
		_6 = _8
	}	while(0)

	if (success_7)
	{
		success_3 = true
		pos = begin_21
	}
	_2 += _4
	_2 += _6
	if (!success_3)
	{
		auto begin_30 = pos
		do
		{
			if (!(CURRENT_TOKEN == "AUTO_20"))
			{
				if (!(CURRENT_TOKEN == "AUTO_21"))
				{
					break
				}
				else 
				{
					_28 = *pos
					success_29 = true
					_24 = _28
				}
			}
			else 
			{
				_26 = *pos
				success_27 = true
				_24 = _26
			}
			_24 += *(pos0)
			success_25 = true
			begin_30++
		}		while(0)

		if (success_25)
		{
			success_23 = true
			pos = begin_30
		}
		_22 = _24
		if (!success_23)
		{
			auto begin_47 = pos
			do
			{
				if (!(CURRENT_TOKEN == "AUTO_22"))
				{
					if (!(CURRENT_TOKEN == "AUTO_23"))
					{
						if (!(CURRENT_TOKEN == "AUTO_24"))
						{
							if (!(CURRENT_TOKEN == "AUTO_25"))
							{
								if (!(CURRENT_TOKEN == "AUTO_26"))
								{
									if (!(CURRENT_TOKEN == "AUTO_27"))
									{
										break
									}
									else 
									{
										_45 = *pos
										success_46 = true
										_33 = _45
									}
								}
								else 
								{
									_43 = *pos
									success_44 = true
									_33 = _43
								}
							}
							else 
							{
								_41 = *pos
								success_42 = true
								_33 = _41
							}
						}
						else 
						{
							_39 = *pos
							success_40 = true
							_33 = _39
						}
					}
					else 
					{
						_37 = *pos
						success_38 = true
						_33 = _37
					}
				}
				else 
				{
					_35 = *pos
					success_36 = true
					_33 = _35
				}
				_33 += *(pos0)
				success_34 = true
				begin_47++
			}			while(0)

			if (success_34)
			{
				success_32 = true
				pos = begin_47
			}
			_31 = _33
			if (!success_32)
			{
				return {}
			}
			else 
			{
				_0 = _31
			}
		}
		else 
		{
			_0 = _22
		}
	}
	else 
	{
		_0 = _2
	}
	_0 += *(pos0)
	success_1 = true
	pos++
	skipspaces(TOKEN_SEQUENCE)
	_48 = cll_template_typename(tokens)
	if (!(_48.status))
	{
		return {}
	}
	success_49 = true
	pos++
	data = 
		template: _8
		type: _4
	;
}
Parser::Rule_res cll_type_abstract() {
	ISPA_ANY_TYPE _0
	bool success_1 = false
	ISPA_ANY_TYPE _2
	bool success_3 = false
	Token _4
	bool success_5 = false
	Token _6
	bool success_7 = false
	Token _8
	bool success_9 = false
	Token _10
	bool success_11 = false
	Token _12
	bool success_13 = false
	ISPA_STR_TYPE _14
	bool success_15 = false
	Token _16
	bool success_17 = false
	Rule _18
	bool success_19 = false
	ISPA_STR_TYPE _21
	bool success_22 = false
	Token _23
	bool success_24 = false
	Rule _25
	bool success_26 = false
	auto begin_28 = pos
	if (!(CURRENT_TOKEN == "AUTO_28"))
	{
		if (!(CURRENT_TOKEN == "AUTO_29"))
		{
			if (!(CURRENT_TOKEN == "AUTO_30"))
			{
				if (!(CURRENT_TOKEN == "AUTO_31"))
				{
					if (!(CURRENT_TOKEN == "AUTO_32"))
					{
						auto begin_20 = begin_28
						do
						{
							if (!(CURRENT_TOKEN == "AUTO_33"))
							{
								break
							}
							_16 = *pos
							success_17 = true
							begin_20++
							skipspaces(TOKEN_SEQUENCE)
							_18 = cll_template_typename(tokens)
							if (!(_18.status))
							{
								break
							}
							success_19 = true
							begin_20++
						}						while(0)

						if (success_19)
						{
							success_15 = true
							begin_28 = begin_20
						}
						_14 += _16
						_14 += _18
						if (!success_15)
						{
							auto begin_27 = begin_28
							do
							{
								if (!(CURRENT_TOKEN == "AUTO_34"))
								{
									break
								}
								_23 = *pos
								success_24 = true
								begin_27++
								skipspaces(TOKEN_SEQUENCE)
								_25 = cll_template_typename(tokens)
								if (!(_25.status))
								{
									break
								}
								success_26 = true
								begin_27++
							}							while(0)

							if (success_26)
							{
								success_22 = true
								begin_28 = begin_27
							}
							_21 += _23
							_21 += _25
							if (!success_22)
							{
								return {}
							}
							else 
							{
								_2 = _21
							}
						}
						else 
						{
							_2 = _14
						}
					}
					else 
					{
						_12 = *pos
						success_13 = true
						_2 = _12
					}
				}
				else 
				{
					_10 = *pos
					success_11 = true
					_2 = _10
				}
			}
			else 
			{
				_8 = *pos
				success_9 = true
				_2 = _8
			}
		}
		else 
		{
			_6 = *pos
			success_7 = true
			_2 = _6
		}
	}
	else 
	{
		_4 = *pos
		success_5 = true
		_2 = _4
	}
	_2 += *(pos0)
	success_3 = true
	begin_28++
	if (success_3)
	{
		success_1 = true
		pos = begin_28
	}
	data = 
		template: _18
		type: _16
	;
}
Parser::Rule_res cll_type() {
	Rule _0
	bool success_1 = false
	Rule _2
	bool success_3 = false
	Rule _4
	bool success_5 = false
	_2 = cll_csupport_types(tokens)
	if (!(_2.status))
	{
		_4 = cll_type_abstract(tokens)
		if (!(_4.status))
		{
			return {}
		}
		else 
		{
			success_5 = true
			_0 = _4
		}
	}
	else 
	{
		success_3 = true
		_0 = _2
	}
	_0 += *(pos0)
	success_1 = true
	pos++
	data = _0
}
Parser::Rule_res cll_if() {
	Token _0
	bool success_1 = false
	Token _2
	bool success_3 = false
	ISPA_ARRAY_TYPE<Token> shadow_4
	Token _6
	bool success_7 = false
	Rule _8
	bool success_9 = false
	ISPA_STR_TYPE _10
	bool success_11 = false
	Rule _12
	bool success_13 = false
	Rule _14
	bool success_15 = false
	Rule _16
	bool success_17 = false
	ISPA_STR_TYPE _18
	bool success_19 = false
	UNDEF _21
	UNDEF shadow_22
	bool success_20 = false
	Token _23
	bool success_24 = false
	Rule _25
	bool success_26 = false
	UNDEF _27
	bool success_28 = false
	auto begin_5 = pos
	while (CURRENT_TOKEN == "AUTO_35")
	{
		_2 += *pos
		success_3 = true
		begin_5++
		shadow_4.push(_2)
	}
	if (success_3)
	{
		success_1 = true
		pos = begin_5
	}
	_0 = _2
	skipspaces(TOKEN_SEQUENCE)
	if (!(CURRENT_TOKEN == "AUTO_36"))
	{
		return {}
	}
	_6 = *pos
	success_7 = true
	pos++
	skipspaces(TOKEN_SEQUENCE)
	_8 = expr(tokens)
	if (!(_8.status))
	{
		return {}
	}
	success_9 = true
	pos++
	skipspaces(TOKEN_SEQUENCE)
	auto begin_31 = pos
	_14 = cll_block(tokens)
	if (!(_14.status))
	{
		_16 = cll_spaced_block(tokens)
		if (!(_16.status))
		{
			return {}
		}
		else 
		{
			success_17 = true
			_12 = _16
		}
	}
	else 
	{
		success_15 = true
		_12 = _14
	}
	_12 += *(pos0)
	success_13 = true
	begin_31++
	skipspaces(TOKEN_SEQUENCE)
	auto begin_30 = begin_31
	if (!(!std::strncmp(pos, _2, strlen(_2))))
	{
		return {}
	}
	_21 += *(pos0)
	success_20 = true
	begin_30++
	skipspaces(TOKEN_SEQUENCE)
	if (!(CURRENT_TOKEN == "AUTO_96"))
	{
		return {}
	}
	_23 = *pos
	success_24 = true
	begin_30++
	skipspaces(TOKEN_SEQUENCE)
	_25 = size(tokens)
	if (!(_25.status))
	{
		return {}
	}
	success_26 = true
	begin_30++
	skipspaces(TOKEN_SEQUENCE)
	auto begin_29 = begin_30
	if ()
	{
		success_28 = true
		begin_30 = begin_29
	}
	if (success_28)
	{
		success_19 = true
		begin_31 = begin_30
	}
	_18 += _21
	_18 += _23
	_18 += _25
	_18 += _27
	if (success_19)
	{
		success_11 = true
		pos = begin_31
	}
	_10 += _12
	_10 += _18
	data = 
		block: _0
		expr: _6
	;
}
Parser::Rule_res cll_ternary() {
	Rule _0
	bool success_1 = false
	Token _2
	bool success_3 = false
	Rule _4
	bool success_5 = false
	Token _6
	bool success_7 = false
	Rule _8
	bool success_9 = false
	_0 = expr(tokens)
	if (!(_0.status))
	{
		return {}
	}
	success_1 = true
	pos++
	skipspaces(TOKEN_SEQUENCE)
	if (!(CURRENT_TOKEN == "AUTO_83"))
	{
		return {}
	}
	_2 = *pos
	success_3 = true
	pos++
	skipspaces(TOKEN_SEQUENCE)
	_4 = expr(tokens)
	if (!(_4.status))
	{
		return {}
	}
	success_5 = true
	pos++
	skipspaces(TOKEN_SEQUENCE)
	if (!(CURRENT_TOKEN == "AUTO_65"))
	{
		return {}
	}
	_6 = *pos
	success_7 = true
	pos++
	skipspaces(TOKEN_SEQUENCE)
	_8 = expr(tokens)
	if (!(_8.status))
	{
		return {}
	}
	success_9 = true
	pos++
	data = 
		second: _8
		first: _4
		cond: _0
	;
}
Parser::Rule_res expr_logical() {
	Rule _0
	bool success_1 = false
	Rule _2
	bool success_3 = false
	Rule _4
	bool success_5 = false
	Rule _6
	bool success_7 = false
	Token _8
	bool success_9 = false
	Rule _10
	bool success_11 = false
	Rule _12
	bool success_13 = false
	Rule _14
	bool success_15 = false
	Rule _16
	bool success_17 = false
	_2 = expr_compare(tokens)
	if (!(_2.status))
	{
		_4 = expr_arithmetic(tokens)
		if (!(_4.status))
		{
			_6 = expr_for_arithmetic(tokens)
			if (!(_6.status))
			{
				return {}
			}
			else 
			{
				success_7 = true
				_0 = _6
			}
		}
		else 
		{
			success_5 = true
			_0 = _4
		}
	}
	else 
	{
		success_3 = true
		_0 = _2
	}
	_0 += *(pos0)
	success_1 = true
	pos++
	skipspaces(TOKEN_SEQUENCE)
	if (!(CURRENT_TOKEN == "LOGICAL_OP"))
	{
		return {}
	}
	_8 = *pos
	success_9 = true
	pos++
	skipspaces(TOKEN_SEQUENCE)
	_12 = expr_compare(tokens)
	if (!(_12.status))
	{
		_14 = expr_arithmetic(tokens)
		if (!(_14.status))
		{
			_16 = expr_for_arithmetic(tokens)
			if (!(_16.status))
			{
				return {}
			}
			else 
			{
				success_17 = true
				_10 = _16
			}
		}
		else 
		{
			success_15 = true
			_10 = _14
		}
	}
	else 
	{
		success_13 = true
		_10 = _12
	}
	_10 += *(pos0)
	success_11 = true
	pos++
	data = 
		right: _8
		op: _0
		left: _0
	;
}
Parser::Rule_res expr_compare() {
	Rule _0
	bool success_1 = false
	ISPA_STR_TYPE _2
	bool success_3 = false
	bool success_9 = false
	Token _4
	bool success_5 = false
	Rule _6
	bool success_7 = false
	_0 = expr_arithmetic(tokens)
	if (!(_0.status))
	{
		return {}
	}
	success_1 = true
	pos++
	skipspaces(TOKEN_SEQUENCE)
	auto begin_8 = pos
	while (1)
	{
		if (!(CURRENT_TOKEN == "COMPARE_OP"))
		{
			break
		}
		_4 = *pos
		success_5 = true
		begin_8++
		skipspaces(TOKEN_SEQUENCE)
		_6 = expr_arithmetic(tokens)
		if (!(_6.status))
		{
			break
		}
		success_7 = true
		begin_8++
		success_9 = true
	}
	if (!success_9)
	{
		return {}
	}
	if (success_7)
	{
		success_3 = true
		pos = begin_8
	}
	_2 += _4
	_2 += _6
	data = 
		sequence: _6
		operators: _4
		first: _0
	;
}
Parser::Rule_res expr_arithmetic() {
	Rule _0
	bool success_1 = false
	ISPA_STR_TYPE _2
	bool success_3 = false
	bool success_9 = false
	Token _4
	bool success_5 = false
	Rule _6
	bool success_7 = false
	_0 = expr_for_arithmetic(tokens)
	if (!(_0.status))
	{
		return {}
	}
	success_1 = true
	pos++
	skipspaces(TOKEN_SEQUENCE)
	auto begin_8 = pos
	while (1)
	{
		if (!(CURRENT_TOKEN == "OP"))
		{
			break
		}
		_4 = *pos
		success_5 = true
		begin_8++
		skipspaces(TOKEN_SEQUENCE)
		_6 = expr_for_arithmetic(tokens)
		if (!(_6.status))
		{
			break
		}
		success_7 = true
		begin_8++
		success_9 = true
	}
	if (!success_9)
	{
		return {}
	}
	if (success_7)
	{
		success_3 = true
		pos = begin_8
	}
	_2 += _4
	_2 += _6
	data = 
		sequence: _6
		operators: _4
		first: _0
	;
}
Parser::Rule_res expr_for_arithmetic() {
	Rule _0
	bool success_1 = false
	Rule _2
	bool success_3 = false
	Rule _4
	bool success_5 = false
	Rule _6
	bool success_7 = false
	Rule _8
	bool success_9 = false
	_2 = expr_group(tokens)
	if (!(_2.status))
	{
		_4 = method_call(tokens)
		if (!(_4.status))
		{
			_6 = cll_function_call(tokens)
			if (!(_6.status))
			{
				_8 = any_data(tokens)
				if (!(_8.status))
				{
					return {}
				}
				else 
				{
					success_9 = true
					_0 = _8
				}
			}
			else 
			{
				success_7 = true
				_0 = _6
			}
		}
		else 
		{
			success_5 = true
			_0 = _4
		}
	}
	else 
	{
		success_3 = true
		_0 = _2
	}
	_0 += *(pos0)
	success_1 = true
	pos++
	data = _0
}
Parser::Rule_res expr_group() {
	Token _0
	bool success_1 = false
	Rule _2
	bool success_3 = false
	Rule _4
	bool success_5 = false
	Rule _6
	bool success_7 = false
	Token _8
	bool success_9 = false
	if (!(CURRENT_TOKEN == "AUTO_40"))
	{
		return {}
	}
	_0 = *pos
	success_1 = true
	pos++
	skipspaces(TOKEN_SEQUENCE)
	_4 = cll_ternary(tokens)
	if (!(_4.status))
	{
		_6 = expr(tokens)
		if (!(_6.status))
		{
			return {}
		}
		else 
		{
			success_7 = true
			_2 = _6
		}
	}
	else 
	{
		success_5 = true
		_2 = _4
	}
	_2 += *(pos0)
	success_3 = true
	pos++
	skipspaces(TOKEN_SEQUENCE)
	if (!(CURRENT_TOKEN == "AUTO_41"))
	{
		return {}
	}
	_8 = *pos
	success_9 = true
	pos++
	data = _2
}
Parser::Rule_res expr_expr_copiable_method_call() {
	Token _0
	bool success_1 = false
	Rule _2
	bool success_3 = false
	Token _4
	bool success_5 = false
	if (!(CURRENT_TOKEN == "AUTO_42"))
	{
		return {}
	}
	_0 = *pos
	success_1 = true
	pos++
	skipspaces(TOKEN_SEQUENCE)
	_2 = copiable_method_call(tokens)
	if (!(_2.status))
	{
		return {}
	}
	success_3 = true
	pos++
	skipspaces(TOKEN_SEQUENCE)
	if (!(CURRENT_TOKEN == "AUTO_43"))
	{
		return {}
	}
	_4 = *pos
	success_5 = true
	pos++
	data = _2
}
Parser::Rule_res expr() {
	Rule _0
	bool success_1 = false
	Rule _2
	bool success_3 = false
	Rule _4
	bool success_5 = false
	Rule _6
	bool success_7 = false
	Rule _8
	bool success_9 = false
	Rule _10
	bool success_11 = false
	Rule _12
	bool success_13 = false
	Rule _14
	bool success_15 = false
	_2 = expr_logical(tokens)
	if (!(_2.status))
	{
		_4 = expr_compare(tokens)
		if (!(_4.status))
		{
			_6 = expr_arithmetic(tokens)
			if (!(_6.status))
			{
				_8 = expr_group(tokens)
				if (!(_8.status))
				{
					_10 = expr_expr_copiable_method_call(tokens)
					if (!(_10.status))
					{
						_12 = cll_function_call(tokens)
						if (!(_12.status))
						{
							_14 = any_data(tokens)
							if (!(_14.status))
							{
								return {}
							}
							else 
							{
								success_15 = true
								_0 = _14
							}
						}
						else 
						{
							success_13 = true
							_0 = _12
						}
					}
					else 
					{
						success_11 = true
						_0 = _10
					}
				}
				else 
				{
					success_9 = true
					_0 = _8
				}
			}
			else 
			{
				success_7 = true
				_0 = _6
			}
		}
		else 
		{
			success_5 = true
			_0 = _4
		}
	}
	else 
	{
		success_3 = true
		_0 = _2
	}
	_0 += *(pos0)
	success_1 = true
	pos++
	data = _0
}
Parser::Rule_res function_body_call() {
	Token _0
	bool success_1 = false
	Rule _2
	bool success_3 = false
	Token _4
	bool success_5 = false
	if (!(CURRENT_TOKEN == "AUTO_46"))
	{
		return {}
	}
	_0 = *pos
	success_1 = true
	pos++
	skipspaces(TOKEN_SEQUENCE)
	_2 = function_arguments(tokens)
	if (!(_2.status))
	{
		return {}
	}
	success_3 = true
	pos++
	skipspaces(TOKEN_SEQUENCE)
	if (!(CURRENT_TOKEN == "AUTO_47"))
	{
		return {}
	}
	_4 = *pos
	success_5 = true
	pos++
	data = _2
}
Parser::Rule_res function_body_decl() {
	Token _0
	bool success_1 = false
	Rule _2
	bool success_3 = false
	Token _4
	bool success_5 = false
	if (!(CURRENT_TOKEN == "AUTO_49"))
	{
		return {}
	}
	_0 = *pos
	success_1 = true
	pos++
	skipspaces(TOKEN_SEQUENCE)
	_2 = function_parameters(tokens)
	if (!(_2.status))
	{
		return {}
	}
	success_3 = true
	pos++
	skipspaces(TOKEN_SEQUENCE)
	if (!(CURRENT_TOKEN == "AUTO_52"))
	{
		return {}
	}
	_4 = *pos
	success_5 = true
	pos++
	data = _2
}
Parser::Rule_res function_arguments() {
	ISPA_ANY_TYPE _0
	bool success_1 = false
	ISPA_ANY_TYPE _2
	bool success_3 = false
	Rule _4
	bool success_5 = false
	Token _6
	bool success_7 = false
	ISPA_STR_TYPE _9
	bool success_10 = false
	ISPA_STR_TYPE _11
	bool success_12 = false
	ISPA_ANY_TYPE _13
	bool success_14 = false
	Rule _15
	bool success_16 = false
	Token _17
	bool success_18 = false
	auto begin_8 = pos
	do
	{
		_4 = any_data(tokens)
		if (!(_4.status))
		{
			if (!(CURRENT_TOKEN == "ID"))
			{
				break
			}
			else 
			{
				_6 = *pos
				success_7 = true
				_2 = _6
			}
		}
		else 
		{
			success_5 = true
			_2 = _4
		}
		_2 += *(pos0)
		success_3 = true
		begin_8++
	}	while(0)

	if (success_3)
	{
		success_1 = true
		pos = begin_8
	}
	skipspaces(TOKEN_SEQUENCE)
	if ((matched()))
	{
		auto begin_19 = pos
		while (1)
		{
			if (!(*pos == ','))
			{
				break
			}
			_11 += *(pos0)
			success_12 = true
			begin_19++
			skipspaces(TOKEN_SEQUENCE)
			_15 = any_data(tokens)
			if (!(_15.status))
			{
				if (!(CURRENT_TOKEN == "ID"))
				{
					break
				}
				else 
				{
					_17 = *pos
					success_18 = true
					_13 = _17
				}
			}
			else 
			{
				success_16 = true
				_13 = _15
			}
			_13 += *(pos0)
			success_14 = true
			begin_19++
		}
		if (success_14)
		{
			success_10 = true
			pos = begin_19
		}
		_9 += _11
		_9 += _13
		skipspaces(TOKEN_SEQUENCE)
	}
	data = {,,}
}
Parser::Rule_res function_parameters() {
	Token _0
	bool success_1 = false
	ISPA_STR_TYPE _2
	bool success_3 = false
	ISPA_STR_TYPE _4
	bool success_5 = false
	Token _6
	bool success_7 = false
	if (CURRENT_TOKEN == "ID")
	{
		_0 = *pos
		success_1 = true
		pos++
	}
	skipspaces(TOKEN_SEQUENCE)
	if ((matched()))
	{
		auto begin_8 = pos
		while (1)
		{
			if (!(*pos == ','))
			{
				break
			}
			_4 += *(pos0)
			success_5 = true
			begin_8++
			skipspaces(TOKEN_SEQUENCE)
			if (!(CURRENT_TOKEN == "ID"))
			{
				break
			}
			_6 = *pos
			success_7 = true
			begin_8++
		}
		if (success_7)
		{
			success_3 = true
			pos = begin_8
		}
		_2 += _4
		_2 += _6
		skipspaces(TOKEN_SEQUENCE)
	}
	data = {,,}
}
Parser::Rule_res cll_function_call() {
	Token _0
	bool success_1 = false
	Rule _2
	bool success_3 = false
	if (!(CURRENT_TOKEN == "ID"))
	{
		return {}
	}
	_0 = *pos
	success_1 = true
	pos++
	skipspaces(TOKEN_SEQUENCE)
	_2 = function_body_call(tokens)
	if (!(_2.status))
	{
		return {}
	}
	success_3 = true
	pos++
	data = 
		body: _2
		name: _0
	;
}
Parser::Rule_res loop_while() {
	Token _0
	bool success_1 = false
	Rule _2
	bool success_3 = false
	Rule _4
	bool success_5 = false
	Rule _6
	bool success_7 = false
	Rule _8
	bool success_9 = false
	if (!(CURRENT_TOKEN == "AUTO_48"))
	{
		return {}
	}
	_0 = *pos
	success_1 = true
	pos++
	skipspaces(TOKEN_SEQUENCE)
	_2 = expr(tokens)
	if (!(_2.status))
	{
		return {}
	}
	success_3 = true
	pos++
	skipspaces(TOKEN_SEQUENCE)
	_6 = cll_block(tokens)
	if (!(_6.status))
	{
		_8 = cll_spaced_block(tokens)
		if (!(_8.status))
		{
			return {}
		}
		else 
		{
			success_9 = true
			_4 = _8
		}
	}
	else 
	{
		success_7 = true
		_4 = _6
	}
	_4 += *(pos0)
	success_5 = true
	pos++
	data = 
		block: _4
		expr: _2
	;
}
Parser::Rule_res loop_for() {
	Rule _0
	bool success_1 = false
	Token _2
	bool success_3 = false
	Rule _4
	bool success_5 = false
	Rule _6
	bool success_7 = false
	Rule _8
	bool success_9 = false
	Rule _10
	bool success_11 = false
	Token _13
	bool success_14 = false
	Rule _15
	bool success_16 = false
	Token _17
	bool success_18 = false
	Rule _19
	bool success_20 = false
	Token _21
	bool success_22 = false
	Rule _23
	bool success_24 = false
	Rule _25
	bool success_26 = false
	Rule _27
	bool success_28 = false
	_0 = for(tokens)
	if (!(_0.status))
	{
		return {}
	}
	success_1 = true
	pos++
	skipspaces(TOKEN_SEQUENCE)
	if (!(CURRENT_TOKEN == "AUTO_87"))
	{
		return {}
	}
	_2 = *pos
	success_3 = true
	pos++
	skipspaces(TOKEN_SEQUENCE)
	auto begin_12 = pos
	do
	{
		_8 = expr(tokens)
		if (!(_8.status))
		{
			_10 = cll_var(tokens)
			if (!(_10.status))
			{
				break
			}
			else 
			{
				success_11 = true
				_6 = _10
			}
		}
		else 
		{
			success_9 = true
			_6 = _8
		}
		_6 += *(pos0)
		success_7 = true
		begin_12++
	}	while(0)

	if (success_7)
	{
		success_5 = true
		pos = begin_12
	}
	_4 = _6
	skipspaces(TOKEN_SEQUENCE)
	if (!(CURRENT_TOKEN == "AUTO_51"))
	{
		return {}
	}
	_13 = *pos
	success_14 = true
	pos++
	skipspaces(TOKEN_SEQUENCE)
	_15 = expr(tokens)
	if (_15.status)
	{
		success_16 = true
		pos++
	}
	skipspaces(TOKEN_SEQUENCE)
	if (!(CURRENT_TOKEN == "AUTO_68"))
	{
		return {}
	}
	_17 = *pos
	success_18 = true
	pos++
	skipspaces(TOKEN_SEQUENCE)
	_19 = expr(tokens)
	if (_19.status)
	{
		success_20 = true
		pos++
	}
	skipspaces(TOKEN_SEQUENCE)
	if (!(CURRENT_TOKEN == "AUTO_88"))
	{
		return {}
	}
	_21 = *pos
	success_22 = true
	pos++
	skipspaces(TOKEN_SEQUENCE)
	_25 = cll_block(tokens)
	if (!(_25.status))
	{
		_27 = cll_spaced_block(tokens)
		if (!(_27.status))
		{
			return {}
		}
		else 
		{
			success_28 = true
			_23 = _27
		}
	}
	else 
	{
		success_26 = true
		_23 = _25
	}
	_23 += *(pos0)
	success_24 = true
	pos++
	data = 
		block: _19
		end: _15
		cond: _4
		decl: _6
	;
}
Parser::Rule_res method_call() {
	Token _0
	bool success_1 = false
	ISPA_STR_TYPE _2
	bool success_3 = false
	bool success_9 = false
	Token _4
	bool success_5 = false
	Rule _6
	bool success_7 = false
	if (!(CURRENT_TOKEN == "ID"))
	{
		return {}
	}
	_0 = *pos
	success_1 = true
	pos++
	skipspaces(TOKEN_SEQUENCE)
	auto begin_8 = pos
	while (1)
	{
		if (!(CURRENT_TOKEN == "AUTO_80"))
		{
			break
		}
		_4 = *pos
		success_5 = true
		begin_8++
		skipspaces(TOKEN_SEQUENCE)
		_6 = cll_function_call(tokens)
		if (!(_6.status))
		{
			break
		}
		success_7 = true
		begin_8++
		success_9 = true
	}
	if (!success_9)
	{
		return {}
	}
	if (success_7)
	{
		success_3 = true
		pos = begin_8
	}
	_2 += _4
	_2 += _6
	data = 
		call: _6
		object: _0
	;
}
Parser::Rule_res copiable_method_call() {
	Token _0
	bool success_1 = false
	Rule _2
	bool success_3 = false
	if (!(CURRENT_TOKEN == "AUTO_54"))
	{
		return {}
	}
	_0 = *pos
	success_1 = true
	pos++
	skipspaces(TOKEN_SEQUENCE)
	_2 = method_call(tokens)
	if (!(_2.status))
	{
		return {}
	}
	success_3 = true
	pos++
	data = _2
}
Parser::Rule_res var_refer() {
	ISPA_ANY_TYPE pre = matched()
	ISPA_ANY_TYPE post = matched()
	Token _0
	bool success_1 = false
	Token _2
	bool success_3 = false
	Token _4
	bool success_5 = false
	Token _6
	bool success_7 = false
	Token _9
	bool success_10 = false
	ISPA_STR_TYPE _11
	bool success_12 = false
	Token _13
	bool success_14 = false
	Rule _15
	bool success_16 = false
	Token _17
	bool success_18 = false
	Token _20
	bool success_21 = false
	Token _22
	bool success_23 = false
	Token _24
	bool success_25 = false
	Token _26
	bool success_27 = false
	auto begin_8 = pos
	do
	{
		if (!(CURRENT_TOKEN == "AUTO_59"))
		{
			if (!(CURRENT_TOKEN == "AUTO_60"))
			{
				break
			}
			else 
			{
				_6 = *pos
				success_7 = true
				_2 = _6
			}
		}
		else 
		{
			_4 = *pos
			success_5 = true
			_2 = _4
		}
		_2 += *(pos0)
		success_3 = true
		begin_8++
	}	while(0)

	if (success_3)
	{
		success_1 = true
		pos = begin_8
	}
	_0 = _2
	skipspaces(TOKEN_SEQUENCE)
	if (!(CURRENT_TOKEN == "ID"))
	{
		return {}
	}
	_9 = *pos
	success_10 = true
	pos++
	skipspaces(TOKEN_SEQUENCE)
	auto begin_19 = pos
	do
	{
		if (!(CURRENT_TOKEN == "AUTO_61"))
		{
			break
		}
		_13 = *pos
		success_14 = true
		begin_19++
		skipspaces(TOKEN_SEQUENCE)
		_15 = expr(tokens)
		if (!(_15.status))
		{
			break
		}
		success_16 = true
		begin_19++
		skipspaces(TOKEN_SEQUENCE)
		if (!(CURRENT_TOKEN == "AUTO_63"))
		{
			break
		}
		_17 = *pos
		success_18 = true
		begin_19++
	}	while(0)

	if (success_18)
	{
		success_12 = true
		pos = begin_19
	}
	_11 += _13
	_11 += _15
	_11 += _17
	skipspaces(TOKEN_SEQUENCE)
	auto begin_28 = pos
	do
	{
		if (!(CURRENT_TOKEN == "AUTO_59"))
		{
			if (!(CURRENT_TOKEN == "AUTO_60"))
			{
				break
			}
			else 
			{
				_26 = *pos
				success_27 = true
				_22 = _26
			}
		}
		else 
		{
			_24 = *pos
			success_25 = true
			_22 = _24
		}
		_22 += *(pos0)
		success_23 = true
		begin_28++
	}	while(0)

	if (success_23)
	{
		success_21 = true
		pos = begin_28
	}
	_20 = _22
	data = 
		post: post
		pre: pre
		brace_expression: _15
		name: _2
	;
}
Parser::Rule_res cll_var() {
	Rule _0
	bool success_1 = false
	Token _2
	bool success_3 = false
	ISPA_STR_TYPE _4
	bool success_5 = false
	Rule _6
	bool success_7 = false
	Rule _8
	bool success_9 = false
	Rule _10
	bool success_11 = false
	Rule _12
	bool success_13 = false
	_0 = cll_type(tokens)
	if (_0.status)
	{
		success_1 = true
		pos++
	}
	skipspaces(TOKEN_SEQUENCE)
	if (!(CURRENT_TOKEN == "ID"))
	{
		return {}
	}
	_2 = *pos
	success_3 = true
	pos++
	skipspaces(TOKEN_SEQUENCE)
	auto begin_14 = pos
	do
	{
		_6 = assignment_op(tokens)
		if (!(_6.status))
		{
			break
		}
		success_7 = true
		begin_14++
		skipspaces(TOKEN_SEQUENCE)
		_10 = expr(tokens)
		if (!(_10.status))
		{
			_12 = cll_ternary(tokens)
			if (!(_12.status))
			{
				break
			}
			else 
			{
				success_13 = true
				_8 = _12
			}
		}
		else 
		{
			success_11 = true
			_8 = _10
		}
		_8 += *(pos0)
		success_9 = true
		begin_14++
	}	while(0)

	if (success_9)
	{
		success_5 = true
		pos = begin_14
	}
	_4 += _6
	_4 += _8
	data = 
		value: _8
		operator: _6
		id: _2
		type: _0
	;
}
Parser::Token_res STRING() {
	data = 
	ISPA_STR_TYPE _0
	bool success_1 = false
	ISPA_STR_TYPE _2
	bool success_3 = false
	auto begin_17 = pos
	do
	{
		ISPA_STR_TYPE _4
		bool success_5 = false
		if (!(*pos == '\''))
		{
			break
		}
		_4 += *(pos0)
		success_5 = true
		begin_17++
		skipspaces(pos)
		ISPA_ANY_TYPE _6
		bool success_7 = false
		auto begin_14 = begin_17
		while (1)
		{
			ISPA_ANY_TYPE _8
			bool success_9 = false
			ISPA_STR_TYPE _10
			bool success_11 = false
			if (!(!std::strncmp(pos, "\\'", 3)))
			{
				ISPA_STR_TYPE _12
				bool success_13 = false
				if (!(!(*pos == '\'')))
				{
					break
				}
				else 
				{
					_12 += *(pos0)
					success_13 = true
					_8 = _12
				}
			}
			else 
			{
				_10 += *(pos0)
				success_11 = true
				_8 = _10
			}
			_8 += *(pos0)
			success_9 = true
			begin_14++
		}
		if (success_9)
		{
			success_7 = true
			begin_17 = begin_14
		}
		skipspaces(pos)
		ISPA_STR_TYPE _15
		bool success_16 = false
		if (!(*pos == '\''))
		{
			break
		}
		_15 += *(pos0)
		success_16 = true
		begin_17++
	}	while(0)

	if (success_16)
	{
		success_3 = true
		pos = begin_17
	}
	_2 += _4
	_2 += _6
	_2 += _15
	if (!success_3)
	{
		ISPA_STR_TYPE _18
		bool success_19 = false
		auto begin_33 = pos
		do
		{
			ISPA_STR_TYPE _20
			bool success_21 = false
			if (!(*pos == '"'))
			{
				break
			}
			_20 += *(pos0)
			success_21 = true
			begin_33++
			skipspaces(pos)
			ISPA_ANY_TYPE _22
			bool success_23 = false
			auto begin_30 = begin_33
			while (1)
			{
				ISPA_ANY_TYPE _24
				bool success_25 = false
				ISPA_STR_TYPE _26
				bool success_27 = false
				if (!(!std::strncmp(pos, "\\"", 3)))
				{
					ISPA_STR_TYPE _28
					bool success_29 = false
					if (!(!(*pos == '"')))
					{
						break
					}
					else 
					{
						_28 += *(pos0)
						success_29 = true
						_24 = _28
					}
				}
				else 
				{
					_26 += *(pos0)
					success_27 = true
					_24 = _26
				}
				_24 += *(pos0)
				success_25 = true
				begin_30++
			}
			if (success_25)
			{
				success_23 = true
				begin_33 = begin_30
			}
			skipspaces(pos)
			ISPA_STR_TYPE _31
			bool success_32 = false
			if (!(*pos == '"'))
			{
				break
			}
			_31 += *(pos0)
			success_32 = true
			begin_33++
		}		while(0)

		if (success_32)
		{
			success_19 = true
			pos = begin_33
		}
		_18 += _20
		_18 += _22
		_18 += _31
		if (!success_19)
		{
			return {}
		}
		else 
		{
			_0 = _18
		}
	}
	else 
	{
		_0 = _2
	}
	_0 += *(pos0)
	success_1 = true
	pos++
}
Parser::Token_res NUMBER() {
	char sign = 
	ISPA_STR_TYPE main = 
	ISPA_NUM_TYPE main_n = NUMBER(main)
	char point = 
	ISPA_STR_TYPE dec = 
	ISPA_NUM_TYPE dec_n = NUMBER(dec)
	ISPA_STR_TYPE _0
	bool success_1 = false
	if (!(*pos == '+' || *pos == '-'))
	{
		return {}
	}
	_0 += *(pos0)
	success_1 = true
	pos++
	skipspaces(pos)
	ISPA_STR_TYPE _2
	bool success_3 = false
	ISPA_STR_TYPE _4
	bool success_5 = false
	auto begin_10 = pos
	do
	{
		ISPA_STR_TYPE _6
		bool success_7 = false
		ISPA_ARRAY_TYPE<ISPA_STR_TYPE> shadow_8
		bool success_9 = false
		while ((*pos>='0' && *pos<='9'))
		{
			_6 += *(pos0)
			success_7 = true
			begin_10++
			shadow_8.push(_6)
			success_9 = true
		}
		if (!success_9)
		{
			break
		}
	}	while(0)

	if (success_7)
	{
		success_5 = true
		pos = begin_10
	}
	_4 += shadow_8
	if (!success_5)
	{
		ISPA_STR_TYPE _11
		bool success_12 = false
		auto begin_19 = pos
		do
		{
			ISPA_STR_TYPE _13
			bool success_14 = false
			if (!(*pos == '.' || *pos == ','))
			{
				break
			}
			_13 += *(pos0)
			success_14 = true
			begin_19++
			skipspaces(pos)
			ISPA_STR_TYPE _15
			bool success_16 = false
			ISPA_ARRAY_TYPE<ISPA_STR_TYPE> shadow_17
			bool success_18 = false
			while ((*pos>='0' && *pos<='9'))
			{
				_15 += *(pos0)
				success_16 = true
				begin_19++
				shadow_17.push(_15)
				success_18 = true
			}
			if (!success_18)
			{
				break
			}
		}		while(0)

		if (success_16)
		{
			success_12 = true
			pos = begin_19
		}
		_11 += _13
		_11 += shadow_17
		if (!success_12)
		{
			return {}
		}
		else 
		{
			_2 = _11
		}
	}
	else 
	{
		_2 = _4
	}
	_2 += *(pos0)
	success_3 = true
	pos++
	data = 
		full: main+point+dec
		dec_n: dec_n
		dec: dec
		main_n: main_n
		main: main
		sign: sign
	;
}
Parser::Token_res BOOLEAN() {
	ISPA_STR_TYPE d
	bool success_0 = false
	auto begin_7 = pos
	ISPA_STR_TYPE _1
	bool success_2 = false
	ISPA_STR_TYPE _3
	bool success_4 = false
	if (!(!std::strncmp(pos, "true", 4)))
	{
		ISPA_STR_TYPE _5
		bool success_6 = false
		if (!(!std::strncmp(pos, "false", 5)))
		{
			return {}
		}
		else 
		{
			_5 += *(pos0)
			success_6 = true
			_1 = _5
		}
	}
	else 
	{
		_3 += *(pos0)
		success_4 = true
		_1 = _3
	}
	_1 += *(pos0)
	success_2 = true
	begin_7++
	if (success_2)
	{
		success_0 = true
		pos = begin_7
	}
	d += _1
	data = 
		lit: d
	;
}
Parser::Rule_res array() {
	Token _0
	bool success_1 = false
	ISPA_STR_TYPE _2
	bool success_3 = false
	ISPA_STR_TYPE _4
	bool success_5 = false
	Rule _6
	bool success_7 = false
	Token _8
	bool success_9 = false
	Token _12
	bool success_13 = false
	if (!(CURRENT_TOKEN == "AUTO_89"))
	{
		return {}
	}
	_0 = *pos
	success_1 = true
	pos++
	skipspaces(TOKEN_SEQUENCE)
	auto begin_11 = pos
	do
	{
		auto begin_10 = begin_11
		while (1)
		{
			_6 = any_data(tokens)
			if (!(_6.status))
			{
				break
			}
			success_7 = true
			begin_10++
			skipspaces(TOKEN_SEQUENCE)
			if (!(CURRENT_TOKEN == "AUTO_66"))
			{
				break
			}
			_8 = *pos
			success_9 = true
			begin_10++
		}
		if (success_9)
		{
			success_5 = true
			begin_11 = begin_10
		}
		_4 += _6
		_4 += _8
	}	while(0)

	if (success_5)
	{
		success_3 = true
		pos = begin_11
	}
	_2 += _4
	skipspaces(TOKEN_SEQUENCE)
	if (!(CURRENT_TOKEN == "AUTO_91"))
	{
		return {}
	}
	_12 = *pos
	success_13 = true
	pos++
	data = _8
}
Parser::Rule_res object() {
	Token _0
	bool success_1 = false
	ISPA_STR_TYPE _2
	bool success_3 = false
	Rule _4
	bool success_5 = false
	Token _6
	bool success_7 = false
	Rule _8
	bool success_9 = false
	ISPA_STR_TYPE _10
	bool success_11 = false
	Token _12
	bool success_13 = false
	Token _14
	bool success_15 = false
	Token _16
	bool success_17 = false
	Rule _18
	bool success_19 = false
	Token _21
	bool success_22 = false
	Token _24
	bool success_25 = false
	if (!(CURRENT_TOKEN == "AUTO_64"))
	{
		return {}
	}
	_0 = *pos
	success_1 = true
	pos++
	skipspaces(TOKEN_SEQUENCE)
	auto begin_23 = pos
	do
	{
		_4 = any_data(tokens)
		if (!(_4.status))
		{
			break
		}
		success_5 = true
		begin_23++
		skipspaces(TOKEN_SEQUENCE)
		if (!(CURRENT_TOKEN == "AUTO_67"))
		{
			break
		}
		_6 = *pos
		success_7 = true
		begin_23++
		skipspaces(TOKEN_SEQUENCE)
		_8 = any_data(tokens)
		if (!(_8.status))
		{
			break
		}
		success_9 = true
		begin_23++
		skipspaces(TOKEN_SEQUENCE)
		auto begin_20 = begin_23
		while (1)
		{
			if (!(CURRENT_TOKEN == "AUTO_77"))
			{
				break
			}
			_12 = *pos
			success_13 = true
			begin_20++
			skipspaces(TOKEN_SEQUENCE)
			if (!(CURRENT_TOKEN == "ID"))
			{
				break
			}
			_14 = *pos
			success_15 = true
			begin_20++
			skipspaces(TOKEN_SEQUENCE)
			if (!(CURRENT_TOKEN == "AUTO_78"))
			{
				break
			}
			_16 = *pos
			success_17 = true
			begin_20++
			skipspaces(TOKEN_SEQUENCE)
			_18 = any_data(tokens)
			if (!(_18.status))
			{
				break
			}
			success_19 = true
			begin_20++
		}
		if (success_19)
		{
			success_11 = true
			begin_23 = begin_20
		}
		_10 += _12
		_10 += _14
		_10 += _16
		_10 += _18
		skipspaces(TOKEN_SEQUENCE)
		if (!(CURRENT_TOKEN == "AUTO_102"))
		{
			break
		}
		_21 = *pos
		success_22 = true
		begin_23++
	}	while(0)

	if (success_22)
	{
		success_3 = true
		pos = begin_23
	}
	_2 += _4
	_2 += _6
	_2 += _8
	_2 += _10
	_2 += _21
	skipspaces(TOKEN_SEQUENCE)
	if (!(CURRENT_TOKEN == "AUTO_69"))
	{
		return {}
	}
	_24 = *pos
	success_25 = true
	pos++
	data = 
		values: _18
		keys: _14
		value: _8
		key: _4
	;
}
Parser::Rule_res any_data() {
	ISPA_ANY_TYPE _0
	bool success_1 = false
	Token _2
	bool success_3 = false
	Token _4
	bool success_5 = false
	Token _6
	bool success_7 = false
	Token _8
	bool success_9 = false
	Rule _10
	bool success_11 = false
	Rule _12
	bool success_13 = false
	Rule _14
	bool success_15 = false
	data = 
	if (!(CURRENT_TOKEN == "BOOLEAN"))
	{
		if (!(CURRENT_TOKEN == "NUMBER"))
		{
			if (!(CURRENT_TOKEN == "STRING"))
			{
				if (!(CURRENT_TOKEN == "ID"))
				{
					_10 = array(tokens)
					if (!(_10.status))
					{
						_12 = object(tokens)
						if (!(_12.status))
						{
							_14 = accessor(tokens)
							if (!(_14.status))
							{
								return {}
							}
							else 
							{
								success_15 = true
								_0 = _14
							}
						}
						else 
						{
							success_13 = true
							_0 = _12
						}
					}
					else 
					{
						success_11 = true
						_0 = _10
					}
				}
				else 
				{
					_8 = *pos
					success_9 = true
					_0 = _8
				}
			}
			else 
			{
				_6 = *pos
				success_7 = true
				_0 = _6
			}
		}
		else 
		{
			_4 = *pos
			success_5 = true
			_0 = _4
		}
	}
	else 
	{
		_2 = *pos
		success_3 = true
		_0 = _2
	}
	_0 += *(pos0)
	success_1 = true
	pos++
}
Parser::Token_res END() {
	ISPA_STR_TYPE _0
	bool success_1 = false
	if (!(*pos == ';' || *pos == '\n'))
	{
		return {}
	}
	_0 += *(pos0)
	success_1 = true
	pos++
}
Parser::Token_res NEWLINE() {
	ISPA_STR_TYPE _0
	bool success_1 = false
	if (!(*pos == '\n'))
	{
		return {}
	}
	_0 += *(pos0)
	success_1 = true
	pos++
}
Parser::Token_res ID() {
	ISPA_STR_TYPE _0
	bool success_1 = false
	auto begin_10 = pos
	ISPA_STR_TYPE _2
	bool success_3 = false
	ISPA_ARRAY_TYPE<ISPA_STR_TYPE> shadow_4
	while ((*pos>='0' && *pos<='9'))
	{
		_2 += *(pos0)
		success_3 = true
		begin_10++
		shadow_4.push(_2)
	}
	skipspaces(pos)
	ISPA_STR_TYPE _5
	bool success_6 = false
	if (!((*pos>='a' && *pos<='z') || (*pos>='A' && *pos<='Z') || *pos == '_'))
	{
		return {}
	}
	_5 += *(pos0)
	success_6 = true
	begin_10++
	skipspaces(pos)
	ISPA_STR_TYPE _7
	bool success_8 = false
	ISPA_ARRAY_TYPE<ISPA_STR_TYPE> shadow_9
	while ((*pos>='a' && *pos<='z') || (*pos>='A' && *pos<='Z') || (*pos>='0' && *pos<='9') || *pos == '_')
	{
		_7 += *(pos0)
		success_8 = true
		begin_10++
		shadow_9.push(_7)
	}
	if (success_8)
	{
		success_1 = true
		pos = begin_10
	}
	_0 += shadow_4
	_0 += _5
	_0 += shadow_9
	data = _0
}
Parser::Rule_res spacemode() {
	Token _0
	bool success_1 = false
	Token _2
	bool success_3 = false
	Token _4
	bool success_5 = false
	Token _6
	bool success_7 = false
	Token _8
	bool success_9 = false
	if (!(CURRENT_TOKEN == "AUTO_70"))
	{
		return {}
	}
	_0 = *pos
	success_1 = true
	pos++
	skipspaces(TOKEN_SEQUENCE)
	if (!(CURRENT_TOKEN == "AUTO_71"))
	{
		if (!(CURRENT_TOKEN == "AUTO_72"))
		{
			if (!(CURRENT_TOKEN == "AUTO_73"))
			{
				return {}
			}
			else 
			{
				_8 = *pos
				success_9 = true
				_2 = _8
			}
		}
		else 
		{
			_6 = *pos
			success_7 = true
			_2 = _6
		}
	}
	else 
	{
		_4 = *pos
		success_5 = true
		_2 = _4
	}
	_2 += *(pos0)
	success_3 = true
	pos++
	data = _0
}
Parser::Rule_res linear_comment() {
	Token _0
	bool success_1 = false
	Token _2
	bool success_3 = false
	ISPA_ARRAY_TYPE<Token> shadow_4
	if (!(CURRENT_TOKEN == "AUTO_74"))
	{
		return {}
	}
	_0 = *pos
	success_1 = true
	pos++
	skipspaces(TOKEN_SEQUENCE)
	while (CURRENT_TOKEN == "AUTO_75")
	{
		_2 += *pos
		success_3 = true
		pos++
		shadow_4.push(_2)
	}
}
Parser::Rule_res main() {
	Rule _0
	bool success_1 = false
	Rule _2
	bool success_3 = false
	Rule _4
	bool success_5 = false
	Rule _6
	bool success_7 = false
	_2 = use(tokens)
	if (!(_2.status))
	{
		_4 = Rule(tokens)
		if (!(_4.status))
		{
			_6 = spacemode(tokens)
			if (!(_6.status))
			{
				return {}
			}
			else 
			{
				success_7 = true
				_0 = _6
			}
		}
		else 
		{
			success_5 = true
			_0 = _4
		}
	}
	else 
	{
		success_3 = true
		_0 = _2
	}
	_0 += *(pos0)
	success_1 = true
	pos++
}
Parser::Rule_res use_unit() {
	Rule _0
	bool success_1 = false
	Rule _2
	bool success_3 = false
	_0 = id(tokens)
	if (!(_0.status))
	{
		return {}
	}
	success_1 = true
	pos++
	skipspaces(TOKEN_SEQUENCE)
	_2 = any_data(tokens)
	if (_2.status)
	{
		success_3 = true
		pos++
	}
	data = 
		value: _2
		name: _0
	;
}
Parser::Rule_res use() {
	Token _0
	bool success_1 = false
	Rule _2
	bool success_3 = false
	ISPA_STR_TYPE _4
	bool success_5 = false
	Token _6
	bool success_7 = false
	Rule _8
	bool success_9 = false
	if (!(CURRENT_TOKEN == "AUTO_76"))
	{
		return {}
	}
	_0 = *pos
	success_1 = true
	pos++
	skipspaces(TOKEN_SEQUENCE)
	_2 = use_unit(tokens)
	if (!(_2.status))
	{
		return {}
	}
	success_3 = true
	pos++
	skipspaces(TOKEN_SEQUENCE)
	auto begin_10 = pos
	while (1)
	{
		if (!(CURRENT_TOKEN == "AUTO_77"))
		{
			break
		}
		_6 = *pos
		success_7 = true
		begin_10++
		skipspaces(TOKEN_SEQUENCE)
		_8 = use_unit(tokens)
		if (!(_8.status))
		{
			break
		}
		success_9 = true
		begin_10++
	}
	if (success_9)
	{
		success_5 = true
		pos = begin_10
	}
	_4 += _6
	_4 += _8
	data = 
		second: _8
		first: _2
	;
}
Parser::Rule_res Rule_rule() {
	ISPA_ANY_TYPE _0
	bool success_1 = false
	ISPA_STR_TYPE _2
	bool success_3 = false
	ISPA_ANY_TYPE _4
	bool success_5 = false
	ISPA_ANY_TYPE _6
	bool success_7 = false
	Rule _8
	bool success_9 = false
	Rule _10
	bool success_11 = false
	Token _12
	bool success_13 = false
	Rule _14
	bool success_15 = false
	Rule _16
	bool success_17 = false
	Rule _18
	bool success_19 = false
	Rule _20
	bool success_21 = false
	Rule _23
	bool success_24 = false
	Rule _26
	bool success_27 = false
	Rule _28
	bool success_29 = false
	Rule _30
	bool success_31 = false
	Rule _32
	bool success_33 = false
	Rule _34
	bool success_35 = false
	auto begin_25 = pos
	do
	{
		auto begin_22 = begin_25
		_8 = Rule_group(tokens)
		if (!(_8.status))
		{
			_10 = Rule_csequence(tokens)
			if (!(_10.status))
			{
				if (!(CURRENT_TOKEN == "STRING"))
				{
					_14 = accessor(tokens)
					if (!(_14.status))
					{
						_16 = Rule_hex(tokens)
						if (!(_16.status))
						{
							_18 = Rule_bin(tokens)
							if (!(_18.status))
							{
								_20 = Rule_other(tokens)
								if (!(_20.status))
								{
									break
								}
								else 
								{
									success_21 = true
									_6 = _20
								}
							}
							else 
							{
								success_19 = true
								_6 = _18
							}
						}
						else 
						{
							success_17 = true
							_6 = _16
						}
					}
					else 
					{
						success_15 = true
						_6 = _14
					}
				}
				else 
				{
					_12 = *pos
					success_13 = true
					_6 = _12
				}
			}
			else 
			{
				success_11 = true
				_6 = _10
			}
		}
		else 
		{
			success_9 = true
			_6 = _8
		}
		_6 += *(pos0)
		success_7 = true
		begin_22++
		if (success_7)
		{
			success_5 = true
			begin_25 = begin_22
		}
		skipspaces(TOKEN_SEQUENCE)
		_23 = Rule_qualifier(tokens)
		if (_23.status)
		{
			success_24 = true
			begin_25++
		}
	}	while(0)

	if (success_24)
	{
		success_3 = true
		pos = begin_25
	}
	_2 += _4
	_2 += _23
	if (!success_3)
	{
		_26 = Rule_rule_escaped(tokens)
		if (!(_26.status))
		{
			_28 = Rule_rule_any(tokens)
			if (!(_28.status))
			{
				_30 = Rule_rule_op(tokens)
				if (!(_30.status))
				{
					_32 = cll(tokens)
					if (!(_32.status))
					{
						_34 = linear_comment(tokens)
						if (!(_34.status))
						{
							return {}
						}
						else 
						{
							success_35 = true
							_0 = _34
						}
					}
					else 
					{
						success_33 = true
						_0 = _32
					}
				}
				else 
				{
					success_31 = true
					_0 = _30
				}
			}
			else 
			{
				success_29 = true
				_0 = _28
			}
		}
		else 
		{
			success_27 = true
			_0 = _26
		}
	}
	else 
	{
		_0 = _2
	}
	_0 += *(pos0)
	success_1 = true
	pos++
	data = 
		qualifier: _6
		val: _6
	;
}
Parser::Rule_res Rule_other() {
	Token _0
	bool success_1 = false
	Token _2
	bool success_3 = false
	ISPA_STR_TYPE _4
	bool success_5 = false
	Token _6
	bool success_7 = false
	Token _8
	bool success_9 = false
	if (CURRENT_TOKEN == "AUTO_79")
	{
		_0 = *pos
		success_1 = true
		pos++
	}
	skipspaces(TOKEN_SEQUENCE)
	if (!(CURRENT_TOKEN == "ID"))
	{
		return {}
	}
	_2 = *pos
	success_3 = true
	pos++
	skipspaces(TOKEN_SEQUENCE)
	auto begin_10 = pos
	while (1)
	{
		if (!(CURRENT_TOKEN == "AUTO_80"))
		{
			break
		}
		_6 = *pos
		success_7 = true
		begin_10++
		skipspaces(TOKEN_SEQUENCE)
		if (!(CURRENT_TOKEN == "ID"))
		{
			break
		}
		_8 = *pos
		success_9 = true
		begin_10++
	}
	if (success_9)
	{
		success_5 = true
		pos = begin_10
	}
	_4 += _6
	_4 += _8
	data = 
		nested_name: _8
		name: _2
		is_nested: matched()
	;
}
Parser::Rule_res Rule_op() {
	Token _0
	bool success_1 = false
	Token _2
	bool success_3 = false
	Token _4
	bool success_5 = false
	Token _6
	bool success_7 = false
	data = 
	auto begin_8 = pos
	if (!(CURRENT_TOKEN == "AUTO_81"))
	{
		if (!(CURRENT_TOKEN == "AUTO_82"))
		{
			return {}
		}
		else 
		{
			_6 = *pos
			success_7 = true
			_2 = _6
		}
	}
	else 
	{
		_4 = *pos
		success_5 = true
		_2 = _4
	}
	_2 += *(pos0)
	success_3 = true
	begin_8++
	if (success_3)
	{
		success_1 = true
		pos = begin_8
	}
	_0 = _2
}
Parser::Rule_res Rule_qualifier() {
	Token _0
	bool success_1 = false
	Token _2
	bool success_3 = false
	Token _4
	bool success_5 = false
	Token _6
	bool success_7 = false
	Token _8
	bool success_9 = false
	data = 
	auto begin_10 = pos
	if (!(CURRENT_TOKEN == "AUTO_83"))
	{
		if (!(CURRENT_TOKEN == "AUTO_84"))
		{
			if (!(CURRENT_TOKEN == "AUTO_85"))
			{
				return {}
			}
			else 
			{
				_8 = *pos
				success_9 = true
				_2 = _8
			}
		}
		else 
		{
			_6 = *pos
			success_7 = true
			_2 = _6
		}
	}
	else 
	{
		_4 = *pos
		success_5 = true
		_2 = _4
	}
	_2 += *(pos0)
	success_3 = true
	begin_10++
	if (success_3)
	{
		success_1 = true
		pos = begin_10
	}
	_0 = _2
}
Parser::Rule_res Rule_group() {
	ISPA_ANY_TYPE name = 
	ISPA_ANY_TYPE r = 
	ISPA_STR_TYPE _0
	bool success_1 = false
	Token _2
	bool success_3 = false
	ISPA_ANY_TYPE _4
	bool success_5 = false
	Rule _6
	bool success_7 = false
	Token _8
	bool success_9 = false
	Token _11
	bool success_12 = false
	Rule _13
	bool success_14 = false
	ISPA_ARRAY_TYPE<Rule> shadow_15
	Token _16
	bool success_17 = false
	auto begin_10 = pos
	do
	{
		if (!(CURRENT_TOKEN == "AUTO_86"))
		{
			break
		}
		_2 = *pos
		success_3 = true
		begin_10++
		skipspaces(TOKEN_SEQUENCE)
		_6 = method_call(tokens)
		if (!(_6.status))
		{
			if (!(CURRENT_TOKEN == "ID"))
			{
				break
			}
			else 
			{
				_8 = *pos
				success_9 = true
				_4 = _8
			}
		}
		else 
		{
			success_7 = true
			_4 = _6
		}
		_4 += *(pos0)
		success_5 = true
		begin_10++
	}	while(0)

	if (success_5)
	{
		success_1 = true
		pos = begin_10
	}
	_0 += _2
	_0 += _4
	skipspaces(TOKEN_SEQUENCE)
	if (!(CURRENT_TOKEN == "AUTO_87"))
	{
		return {}
	}
	_11 = *pos
	success_12 = true
	pos++
	skipspaces(TOKEN_SEQUENCE)
	_13 = Rule_rule(tokens)
	while (_13.status)
	{
		success_14 = true
		pos++
		shadow_15.push(_13)
		_13 = Rule_rule(tokens)
	}
	skipspaces(TOKEN_SEQUENCE)
	if (!(CURRENT_TOKEN == "AUTO_88"))
	{
		return {}
	}
	_16 = *pos
	success_17 = true
	pos++
	data = 
		val: r
		variable: name
	;
}
Parser::Rule_res Rule_csequence_symbol() {
	Token _0
	bool success_1 = false
	Token _2
	bool success_3 = false
	Token _4
	bool success_5 = false
	Token _6
	bool success_7 = false
	Token _8
	bool success_9 = false
	data = 
	auto begin_10 = pos
	if (!(CURRENT_TOKEN == "AUTO_92"))
	{
		if (!(CURRENT_TOKEN == "AUTO_93"))
		{
			if (!(CURRENT_TOKEN == "AUTO_94"))
			{
				return {}
			}
			else 
			{
				_8 = *pos
				success_9 = true
				_2 = _8
			}
		}
		else 
		{
			_6 = *pos
			success_7 = true
			_2 = _6
		}
	}
	else 
	{
		_4 = *pos
		success_5 = true
		_2 = _4
	}
	_2 += *(pos0)
	success_3 = true
	begin_10++
	if (success_3)
	{
		success_1 = true
		pos = begin_10
	}
	_0 = _2
}
Parser::Rule_res Rule_csequence_escape() {
	Token _0
	bool success_1 = false
	Token _2
	bool success_3 = false
	Token _4
	bool success_5 = false
	data = 
	if (!(CURRENT_TOKEN == "AUTO_95"))
	{
		return {}
	}
	_0 = *pos
	success_1 = true
	pos++
	auto begin_6 = pos
	if (!(CURRENT_TOKEN == "AUTO_96"))
	{
		return {}
	}
	_4 = *pos
	success_5 = true
	begin_6++
	if (success_5)
	{
		success_3 = true
		pos = begin_6
	}
	_2 = _4
}
Parser::Rule_res Rule_csequence_diapason() {
	ISPA_STR_TYPE _0
	bool success_1 = false
	Rule from
	bool success_2 = false
	Rule _3
	bool success_4 = false
	Token _6
	bool success_7 = false
	Rule to
	bool success_8 = false
	Rule _9
	bool success_10 = false
	auto begin_12 = pos
	auto begin_5 = begin_12
	_3 = Rule_csequence_symbol(tokens)
	if (!(_3.status))
	{
		return {}
	}
	success_4 = true
	begin_5++
	if (success_4)
	{
		success_2 = true
		begin_12 = begin_5
	}
	from = _3
	if (!(CURRENT_TOKEN == "AUTO_97"))
	{
		return {}
	}
	_6 = *pos
	success_7 = true
	begin_12++
	auto begin_11 = begin_12
	_9 = Rule_csequence_symbol(tokens)
	if (!(_9.status))
	{
		return {}
	}
	success_10 = true
	begin_11++
	if (success_10)
	{
		success_8 = true
		begin_12 = begin_11
	}
	to = _9
	if (success_8)
	{
		success_1 = true
		pos = begin_12
	}
	_0 += from
	_0 += _6
	_0 += to
	data = {from,to,}
}
Parser::Rule_res Rule_csequence() {
	Token _0
	bool success_1 = false
	Token _2
	bool success_3 = false
	Rule dt
	bool success_4 = false
	Rule _5
	bool success_6 = false
	Rule _7
	bool success_8 = false
	Rule _9
	bool success_10 = false
	Rule _11
	bool success_12 = false
	Token _14
	bool success_15 = false
	if (!(CURRENT_TOKEN == "AUTO_89"))
	{
		return {}
	}
	_0 = *pos
	success_1 = true
	pos++
	skipspaces(TOKEN_SEQUENCE)
	if (CURRENT_TOKEN == "AUTO_90")
	{
		_2 = *pos
		success_3 = true
		pos++
	}
	skipspaces(TOKEN_SEQUENCE)
	auto begin_13 = pos
	while (1)
	{
		_7 = Rule_csequence_escape(tokens)
		if (!(_7.status))
		{
			_9 = Rule_csequence_symbol(tokens)
			if (!(_9.status))
			{
				_11 = Rule_csequence_diapason(tokens)
				if (!(_11.status))
				{
					break
				}
				else 
				{
					success_12 = true
					_5 = _11
				}
			}
			else 
			{
				success_10 = true
				_5 = _9
			}
		}
		else 
		{
			success_8 = true
			_5 = _7
		}
		_5 += *(pos0)
		success_6 = true
		begin_13++
	}
	if (success_6)
	{
		success_4 = true
		pos = begin_13
	}
	dt = _5
	skipspaces(TOKEN_SEQUENCE)
	if (!(CURRENT_TOKEN == "AUTO_91"))
	{
		return {}
	}
	_14 = *pos
	success_15 = true
	pos++
	data = 
		val: dt
		not: matched()
	;
}
Parser::Rule_res Rule_any() {
	Token _0
	bool success_1 = false
	if (!(CURRENT_TOKEN == "AUTO_98"))
	{
		return {}
	}
	_0 = *pos
	success_1 = true
	pos++
}
Parser::Rule_res Rule_data_block_inclosed_map() {
	Rule data
	bool success_0 = false
	Rule _1
	bool success_2 = false
	ISPA_ARRAY_TYPE<Rule> shadow_3
	bool success_4 = false
	auto begin_5 = pos
	_1 = Rule_data_block_key(tokens)
	while (_1.status)
	{
		success_2 = true
		begin_5++
		shadow_3.push(_1)
		_1 = Rule_data_block_key(tokens)
		success_4 = true
	}
	if (!success_4)
	{
		return {}
	}
	if (success_2)
	{
		success_0 = true
		pos = begin_5
	}
	data = _1
}
Parser::Rule_res Rule_data_block_key() {
	Token _0
	bool success_1 = false
	ISPA_ARRAY_TYPE<Token> shadow_2
	bool success_3 = false
	Rule name
	bool success_4 = false
	Rule _5
	bool success_6 = false
	Token _8
	bool success_9 = false
	Rule dt
	bool success_10 = false
	Rule _11
	bool success_12 = false
	Rule _13
	bool success_14 = false
	Rule _15
	bool success_16 = false
	while (CURRENT_TOKEN == "AUTO_103")
	{
		_0 += *pos
		success_1 = true
		pos++
		shadow_2.push(_0)
		success_3 = true
	}
	if (!success_3)
	{
		return {}
	}
	skipspaces(TOKEN_SEQUENCE)
	auto begin_7 = pos
	_5 = id(tokens)
	if (!(_5.status))
	{
		return {}
	}
	success_6 = true
	begin_7++
	if (success_6)
	{
		success_4 = true
		pos = begin_7
	}
	name = _5
	skipspaces(TOKEN_SEQUENCE)
	if (!(CURRENT_TOKEN == "AUTO_104"))
	{
		return {}
	}
	_8 = *pos
	success_9 = true
	pos++
	skipspaces(TOKEN_SEQUENCE)
	auto begin_17 = pos
	_13 = cll_ternary(tokens)
	if (!(_13.status))
	{
		_15 = expr(tokens)
		if (!(_15.status))
		{
			return {}
		}
		else 
		{
			success_16 = true
			_11 = _15
		}
	}
	else 
	{
		success_14 = true
		_11 = _13
	}
	_11 += *(pos0)
	success_12 = true
	begin_17++
	if (success_12)
	{
		success_10 = true
		pos = begin_17
	}
	dt = _11
	data = 
		val: dt
		name: name
	;
}
Parser::Rule_res Rule_data_block() {
	Token _0
	bool success_1 = false
	ISPA_ARRAY_TYPE<Token> shadow_2
	bool success_3 = false
	Token _4
	bool success_5 = false
	Token _6
	bool success_7 = false
	Rule data
	bool success_8 = false
	Rule _9
	bool success_10 = false
	Rule _11
	bool success_12 = false
	Rule _13
	bool success_14 = false
	Token _16
	bool success_17 = false
	while (CURRENT_TOKEN == "AUTO_99")
	{
		_0 += *pos
		success_1 = true
		pos++
		shadow_2.push(_0)
		success_3 = true
	}
	if (!success_3)
	{
		return {}
	}
	skipspaces(TOKEN_SEQUENCE)
	if (!(CURRENT_TOKEN == "AUTO_100"))
	{
		return {}
	}
	_4 = *pos
	success_5 = true
	pos++
	skipspaces(TOKEN_SEQUENCE)
	if (!(CURRENT_TOKEN == "AUTO_101"))
	{
		return {}
	}
	_6 = *pos
	success_7 = true
	pos++
	skipspaces(TOKEN_SEQUENCE)
	auto begin_15 = pos
	_11 = any_data(tokens)
	if (!(_11.status))
	{
		_13 = Rule_data_block_inclosed_map(tokens)
		if (!(_13.status))
		{
			return {}
		}
		else 
		{
			success_14 = true
			_9 = _13
		}
	}
	else 
	{
		success_12 = true
		_9 = _11
	}
	_9 += *(pos0)
	success_10 = true
	begin_15++
	if (success_10)
	{
		success_8 = true
		pos = begin_15
	}
	data = _9
	skipspaces(TOKEN_SEQUENCE)
	if (!(CURRENT_TOKEN == "AUTO_102"))
	{
		return {}
	}
	_16 = *pos
	success_17 = true
	pos++
}
Parser::Rule_res Rule_escaped() {
	Token _0
	bool success_1 = false
	Token _2
	bool success_3 = false
	Token _4
	bool success_5 = false
	if (!(CURRENT_TOKEN == "AUTO_105"))
	{
		return {}
	}
	_0 = *pos
	success_1 = true
	pos++
	if (!(CURRENT_TOKEN == "AUTO_106"))
	{
		return {}
	}
	_2 = *pos
	success_3 = true
	pos++
	if (CURRENT_TOKEN == "NUMBER")
	{
		_4 = *pos
		success_5 = true
		pos++
	}
	data = 
		num: _4
		c: _2
	;
}
Parser::Rule_res Rule_nested_rule() {
	Token _0
	bool success_1 = false
	ISPA_ARRAY_TYPE<Token> shadow_2
	bool success_3 = false
	Token _4
	bool success_5 = false
	Rule _6
	bool success_7 = false
	while (CURRENT_TOKEN == "AUTO_107")
	{
		_0 += *pos
		success_1 = true
		pos++
		shadow_2.push(_0)
		success_3 = true
	}
	if (!success_3)
	{
		return {}
	}
	skipspaces(TOKEN_SEQUENCE)
	if (!(CURRENT_TOKEN == "AUTO_108"))
	{
		return {}
	}
	_4 = *pos
	success_5 = true
	pos++
	_6 = Rule(tokens)
	if (!(_6.status))
	{
		return {}
	}
	success_7 = true
	pos++
	data = _6
}
Parser::Rule_res Rule_hex() {
	Token _0
	bool success_1 = false
	Token _2
	bool success_3 = false
	ISPA_ARRAY_TYPE<Token> shadow_4
	bool success_5 = false
	if (!(CURRENT_TOKEN == "AUTO_109"))
	{
		return {}
	}
	_0 = *pos
	success_1 = true
	pos++
	skipspaces(TOKEN_SEQUENCE)
	while (CURRENT_TOKEN == "AUTO_110")
	{
		_2 += *pos
		success_3 = true
		pos++
		shadow_4.push(_2)
		success_5 = true
	}
	if (!success_5)
	{
		return {}
	}
	data = _2
}
Parser::Rule_res Rule_bin() {
	Token _0
	bool success_1 = false
	Token _2
	bool success_3 = false
	ISPA_ARRAY_TYPE<Token> shadow_4
	bool success_5 = false
	if (!(CURRENT_TOKEN == "AUTO_111"))
	{
		return {}
	}
	_0 = *pos
	success_1 = true
	pos++
	skipspaces(TOKEN_SEQUENCE)
	while (CURRENT_TOKEN == "AUTO_112")
	{
		_2 += *pos
		success_3 = true
		pos++
		shadow_4.push(_2)
		success_5 = true
	}
	if (!success_5)
	{
		return {}
	}
	data = _2
}
Parser::Rule_res Rule() {
	ISPA_ANY_TYPE name = 
	ISPA_ANY_TYPE rule = 
	ISPA_ANY_TYPE data_block = 
	ISPA_ANY_TYPE nested_rules = 
	ISPA_STR_TYPE rule_begin
	bool success_0 = false
	Token _1
	bool success_2 = false
	Token _3
	bool success_4 = false
	Rule _6
	bool success_7 = false
	Rule _8
	bool success_9 = false
	Rule _10
	bool success_11 = false
	Rule _13
	bool success_14 = false
	Rule _15
	bool success_16 = false
	ISPA_ARRAY_TYPE<Rule> shadow_17
	Token _18
	bool success_19 = false
	auto begin_5 = pos
	if (!(CURRENT_TOKEN == "ID"))
	{
		return {}
	}
	_1 = *pos
	success_2 = true
	begin_5++
	skipspaces(TOKEN_SEQUENCE)
	if (!(CURRENT_TOKEN == "AUTO_101"))
	{
		return {}
	}
	_3 = *pos
	success_4 = true
	begin_5++
	if (success_4)
	{
		success_0 = true
		pos = begin_5
	}
	rule_begin += _1
	rule_begin += _3
	skipspaces(TOKEN_SEQUENCE)
	_6 = function_body_decl(tokens)
	if (_6.status)
	{
		success_7 = true
		pos++
	}
	skipspaces(TOKEN_SEQUENCE)
	auto begin_12 = pos
	while (1)
	{
		_10 = Rule_rule(tokens)
		if (!(_10.status))
		{
			break
		}
		success_11 = true
		begin_12++
	}
	if (success_11)
	{
		success_9 = true
		pos = begin_12
	}
	_8 = _10
	skipspaces(TOKEN_SEQUENCE)
	_13 = Rule_data_block(tokens)
	if (!(_13.status))
	{
		return {}
	}
	success_14 = true
	pos++
	skipspaces(TOKEN_SEQUENCE)
	_15 = Rule_nested_rule(tokens)
	while (_15.status)
	{
		success_16 = true
		pos++
		shadow_17.push(_15)
		_15 = Rule_nested_rule(tokens)
	}
	skipspaces(TOKEN_SEQUENCE)
	if (!(CURRENT_TOKEN == "AUTO_50"))
	{
		return {}
	}
	_18 = *pos
	success_19 = true
	pos++
	data = 
		nestedRules: nested_rules
		data_block: data_block
		rule: rule
		name: name
	;
}
Parser::Token_res AUTO_1() {
	ISPA_STR_TYPE _0
	bool success_1 = false
	if (!(*pos == '%'))
	{
		return {}
	}
	_0 += *(pos0)
	success_1 = true
	pos++
	data = _0
}
Parser::Token_res AUTO_3() {
	ISPA_STR_TYPE _0
	bool success_1 = false
	if (!(*pos == '>'))
	{
		return {}
	}
	_0 += *(pos0)
	success_1 = true
	pos++
	data = _0
}
Parser::Token_res AUTO_4() {
	ISPA_STR_TYPE _0
	bool success_1 = false
	if (!(*pos == '$'))
	{
		return {}
	}
	_0 += *(pos0)
	success_1 = true
	pos++
	data = _0
}
Parser::Token_res AUTO_14() {
	ISPA_STR_TYPE _0
	bool success_1 = false
	if (!(!std::strncmp(pos, "unsigned", 8)))
	{
		return {}
	}
	_0 += *(pos0)
	success_1 = true
	pos++
	data = _0
}
Parser::Token_res AUTO_15() {
	ISPA_STR_TYPE _0
	bool success_1 = false
	if (!(!std::strncmp(pos, "char", 4)))
	{
		return {}
	}
	_0 += *(pos0)
	success_1 = true
	pos++
	data = _0
}
Parser::Token_res AUTO_16() {
	ISPA_STR_TYPE _0
	bool success_1 = false
	if (!(!std::strncmp(pos, "short", 5)))
	{
		return {}
	}
	_0 += *(pos0)
	success_1 = true
	pos++
	data = _0
}
Parser::Token_res AUTO_17() {
	ISPA_STR_TYPE _0
	bool success_1 = false
	if (!(!std::strncmp(pos, "int", 3)))
	{
		return {}
	}
	_0 += *(pos0)
	success_1 = true
	pos++
	data = _0
}
Parser::Token_res AUTO_18() {
	ISPA_STR_TYPE _0
	bool success_1 = false
	if (!(!std::strncmp(pos, "long", 4)))
	{
		return {}
	}
	_0 += *(pos0)
	success_1 = true
	pos++
	data = _0
}
Parser::Token_res AUTO_19() {
	ISPA_STR_TYPE _0
	bool success_1 = false
	if (!(!std::strncmp(pos, "long long", 9)))
	{
		return {}
	}
	_0 += *(pos0)
	success_1 = true
	pos++
	data = _0
}
Parser::Token_res AUTO_20() {
	ISPA_STR_TYPE _0
	bool success_1 = false
	if (!(!std::strncmp(pos, "float", 5)))
	{
		return {}
	}
	_0 += *(pos0)
	success_1 = true
	pos++
	data = _0
}
Parser::Token_res AUTO_21() {
	ISPA_STR_TYPE _0
	bool success_1 = false
	if (!(!std::strncmp(pos, "double", 6)))
	{
		return {}
	}
	_0 += *(pos0)
	success_1 = true
	pos++
	data = _0
}
Parser::Token_res AUTO_22() {
	ISPA_STR_TYPE _0
	bool success_1 = false
	if (!(!std::strncmp(pos, "deque", 5)))
	{
		return {}
	}
	_0 += *(pos0)
	success_1 = true
	pos++
	data = _0
}
Parser::Token_res AUTO_23() {
	ISPA_STR_TYPE _0
	bool success_1 = false
	if (!(!std::strncmp(pos, "vector", 6)))
	{
		return {}
	}
	_0 += *(pos0)
	success_1 = true
	pos++
	data = _0
}
Parser::Token_res AUTO_24() {
	ISPA_STR_TYPE _0
	bool success_1 = false
	if (!(!std::strncmp(pos, "queue", 5)))
	{
		return {}
	}
	_0 += *(pos0)
	success_1 = true
	pos++
	data = _0
}
Parser::Token_res AUTO_25() {
	ISPA_STR_TYPE _0
	bool success_1 = false
	if (!(!std::strncmp(pos, "stack", 5)))
	{
		return {}
	}
	_0 += *(pos0)
	success_1 = true
	pos++
	data = _0
}
Parser::Token_res AUTO_26() {
	ISPA_STR_TYPE _0
	bool success_1 = false
	if (!(!std::strncmp(pos, "list", 4)))
	{
		return {}
	}
	_0 += *(pos0)
	success_1 = true
	pos++
	data = _0
}
Parser::Token_res AUTO_27() {
	ISPA_STR_TYPE _0
	bool success_1 = false
	if (!(!std::strncmp(pos, "forward_list", 12)))
	{
		return {}
	}
	_0 += *(pos0)
	success_1 = true
	pos++
	data = _0
}
Parser::Token_res AUTO_28() {
	ISPA_STR_TYPE _0
	bool success_1 = false
	if (!(!std::strncmp(pos, "var", 3)))
	{
		return {}
	}
	_0 += *(pos0)
	success_1 = true
	pos++
	data = _0
}
Parser::Token_res AUTO_29() {
	ISPA_STR_TYPE _0
	bool success_1 = false
	if (!(!std::strncmp(pos, "any", 3)))
	{
		return {}
	}
	_0 += *(pos0)
	success_1 = true
	pos++
	data = _0
}
Parser::Token_res AUTO_30() {
	ISPA_STR_TYPE _0
	bool success_1 = false
	if (!(!std::strncmp(pos, "num", 3)))
	{
		return {}
	}
	_0 += *(pos0)
	success_1 = true
	pos++
	data = _0
}
Parser::Token_res AUTO_31() {
	ISPA_STR_TYPE _0
	bool success_1 = false
	if (!(!std::strncmp(pos, "bool", 4)))
	{
		return {}
	}
	_0 += *(pos0)
	success_1 = true
	pos++
	data = _0
}
Parser::Token_res AUTO_32() {
	ISPA_STR_TYPE _0
	bool success_1 = false
	if (!(!std::strncmp(pos, "str", 3)))
	{
		return {}
	}
	_0 += *(pos0)
	success_1 = true
	pos++
	data = _0
}
Parser::Token_res AUTO_33() {
	ISPA_STR_TYPE _0
	bool success_1 = false
	if (!(!std::strncmp(pos, "arr", 3)))
	{
		return {}
	}
	_0 += *(pos0)
	success_1 = true
	pos++
	data = _0
}
Parser::Token_res AUTO_34() {
	ISPA_STR_TYPE _0
	bool success_1 = false
	if (!(!std::strncmp(pos, "obj", 3)))
	{
		return {}
	}
	_0 += *(pos0)
	success_1 = true
	pos++
	data = _0
}
Parser::Token_res AUTO_35() {
	ISPA_STR_TYPE _0
	bool success_1 = false
	if (*pos != ' ')
	{
		return {}
	}
	_0 += *(pos0)
	success_1 = true
	pos++
	data = _0
}
Parser::Token_res AUTO_36() {
	ISPA_STR_TYPE _0
	bool success_1 = false
	if (!(!std::strncmp(pos, "if", 2)))
	{
		return {}
	}
	_0 += *(pos0)
	success_1 = true
	pos++
	data = _0
}
Parser::Token_res AUTO_48() {
	ISPA_STR_TYPE _0
	bool success_1 = false
	if (!(!std::strncmp(pos, "while", 5)))
	{
		return {}
	}
	_0 += *(pos0)
	success_1 = true
	pos++
	data = _0
}
Parser::Token_res AUTO_54() {
	ISPA_STR_TYPE _0
	bool success_1 = false
	if (!(*pos == '='))
	{
		return {}
	}
	_0 += *(pos0)
	success_1 = true
	pos++
	data = _0
}
Parser::Token_res AUTO_59() {
	ISPA_STR_TYPE _0
	bool success_1 = false
	if (!(!std::strncmp(pos, "++", 2)))
	{
		return {}
	}
	_0 += *(pos0)
	success_1 = true
	pos++
	data = _0
}
Parser::Token_res AUTO_60() {
	ISPA_STR_TYPE _0
	bool success_1 = false
	if (!(!std::strncmp(pos, "--", 2)))
	{
		return {}
	}
	_0 += *(pos0)
	success_1 = true
	pos++
	data = _0
}
Parser::Token_res AUTO_64() {
	ISPA_STR_TYPE _0
	bool success_1 = false
	if (!(*pos == '{'))
	{
		return {}
	}
	_0 += *(pos0)
	success_1 = true
	pos++
	data = _0
}
Parser::Token_res AUTO_69() {
	ISPA_STR_TYPE _0
	bool success_1 = false
	if (!(*pos == '}'))
	{
		return {}
	}
	_0 += *(pos0)
	success_1 = true
	pos++
	data = _0
}
Parser::Token_res AUTO_70() {
	ISPA_STR_TYPE _0
	bool success_1 = false
	if (!(!std::strncmp(pos, "spacemode", 9)))
	{
		return {}
	}
	_0 += *(pos0)
	success_1 = true
	pos++
	data = _0
}
Parser::Token_res AUTO_71() {
	ISPA_STR_TYPE _0
	bool success_1 = false
	if (!(!std::strncmp(pos, "mixed", 5)))
	{
		return {}
	}
	_0 += *(pos0)
	success_1 = true
	pos++
	data = _0
}
Parser::Token_res AUTO_72() {
	ISPA_STR_TYPE _0
	bool success_1 = false
	if (!(!std::strncmp(pos, "skipped", 7)))
	{
		return {}
	}
	_0 += *(pos0)
	success_1 = true
	pos++
	data = _0
}
Parser::Token_res AUTO_73() {
	ISPA_STR_TYPE _0
	bool success_1 = false
	if (!(!std::strncmp(pos, "allowed", 7)))
	{
		return {}
	}
	_0 += *(pos0)
	success_1 = true
	pos++
	data = _0
}
Parser::Token_res AUTO_74() {
	ISPA_STR_TYPE _0
	bool success_1 = false
	if (!(!std::strncmp(pos, "//", 2)))
	{
		return {}
	}
	_0 += *(pos0)
	success_1 = true
	pos++
	data = _0
}
Parser::Token_res AUTO_75() {
	ISPA_STR_TYPE _0
	bool success_1 = false
	if (!(!(*pos == '\n')))
	{
		return {}
	}
	_0 += *(pos0)
	success_1 = true
	pos++
	data = _0
}
Parser::Token_res AUTO_76() {
	ISPA_STR_TYPE _0
	bool success_1 = false
	if (!(!std::strncmp(pos, "use", 3)))
	{
		return {}
	}
	_0 += *(pos0)
	success_1 = true
	pos++
	data = _0
}
Parser::Token_res AUTO_77() {
	ISPA_STR_TYPE _0
	bool success_1 = false
	if (!(*pos == ','))
	{
		return {}
	}
	_0 += *(pos0)
	success_1 = true
	pos++
	data = _0
}
Parser::Token_res AUTO_81() {
	ISPA_STR_TYPE _0
	bool success_1 = false
	if (!(*pos == '|'))
	{
		return {}
	}
	_0 += *(pos0)
	success_1 = true
	pos++
	data = _0
}
Parser::Token_res AUTO_82() {
	ISPA_STR_TYPE _0
	bool success_1 = false
	if (!(!std::strncmp(pos, "|&", 2)))
	{
		return {}
	}
	_0 += *(pos0)
	success_1 = true
	pos++
	data = _0
}
Parser::Token_res AUTO_83() {
	ISPA_STR_TYPE _0
	bool success_1 = false
	if (!(*pos == '?'))
	{
		return {}
	}
	_0 += *(pos0)
	success_1 = true
	pos++
	data = _0
}
Parser::Token_res AUTO_84() {
	ISPA_STR_TYPE _0
	bool success_1 = false
	if (!(*pos == '+'))
	{
		return {}
	}
	_0 += *(pos0)
	success_1 = true
	pos++
	data = _0
}
Parser::Token_res AUTO_85() {
	ISPA_STR_TYPE _0
	bool success_1 = false
	if (!(*pos == '*'))
	{
		return {}
	}
	_0 += *(pos0)
	success_1 = true
	pos++
	data = _0
}
Parser::Token_res AUTO_86() {
	ISPA_STR_TYPE _0
	bool success_1 = false
	if (!(*pos == '&'))
	{
		return {}
	}
	_0 += *(pos0)
	success_1 = true
	pos++
	data = _0
}
Parser::Token_res AUTO_87() {
	ISPA_STR_TYPE _0
	bool success_1 = false
	if (!(*pos == '('))
	{
		return {}
	}
	_0 += *(pos0)
	success_1 = true
	pos++
	data = _0
}
Parser::Token_res AUTO_88() {
	ISPA_STR_TYPE _0
	bool success_1 = false
	if (!(*pos == ')'))
	{
		return {}
	}
	_0 += *(pos0)
	success_1 = true
	pos++
	data = _0
}
Parser::Token_res AUTO_89() {
	ISPA_STR_TYPE _0
	bool success_1 = false
	if (!(*pos == '['))
	{
		return {}
	}
	_0 += *(pos0)
	success_1 = true
	pos++
	data = _0
}
Parser::Token_res AUTO_90() {
	ISPA_STR_TYPE _0
	bool success_1 = false
	if (!(*pos == '^'))
	{
		return {}
	}
	_0 += *(pos0)
	success_1 = true
	pos++
	data = _0
}
Parser::Token_res AUTO_91() {
	ISPA_STR_TYPE _0
	bool success_1 = false
	if (!(*pos == ']'))
	{
		return {}
	}
	_0 += *(pos0)
	success_1 = true
	pos++
	data = _0
}
Parser::Token_res AUTO_93() {
	ISPA_STR_TYPE _0
	bool success_1 = false
	if (!(!std::strncmp(pos, "\\]", 3)))
	{
		return {}
	}
	_0 += *(pos0)
	success_1 = true
	pos++
	data = _0
}
Parser::Token_res AUTO_94() {
	ISPA_STR_TYPE _0
	bool success_1 = false
	if (!(!(*pos == ']')))
	{
		return {}
	}
	_0 += *(pos0)
	success_1 = true
	pos++
	data = _0
}
Parser::Token_res AUTO_97() {
	ISPA_STR_TYPE _0
	bool success_1 = false
	if (!(*pos == '-'))
	{
		return {}
	}
	_0 += *(pos0)
	success_1 = true
	pos++
	data = _0
}
Parser::Token_res AUTO_98() {
	ISPA_STR_TYPE _0
	bool success_1 = false
	if (!(*pos == '.'))
	{
		return {}
	}
	_0 += *(pos0)
	success_1 = true
	pos++
	data = _0
}
Parser::Token_res AUTO_100() {
	ISPA_STR_TYPE _0
	bool success_1 = false
	if (!(!std::strncmp(pos, "data", 4)))
	{
		return {}
	}
	_0 += *(pos0)
	success_1 = true
	pos++
	data = _0
}
Parser::Token_res AUTO_102() {
	ISPA_STR_TYPE _0
	bool success_1 = false
	if (!(*pos == ';'))
	{
		return {}
	}
	_0 += *(pos0)
	success_1 = true
	pos++
	data = _0
}
Parser::Token_res AUTO_103() {
	ISPA_STR_TYPE _0
	bool success_1 = false
	if (!(*pos == '\n' || *pos == '\r'))
	{
		return {}
	}
	_0 += *(pos0)
	success_1 = true
	pos++
	data = _0
}
Parser::Token_res AUTO_104() {
	ISPA_STR_TYPE _0
	bool success_1 = false
	if (!(*pos == ':'))
	{
		return {}
	}
	_0 += *(pos0)
	success_1 = true
	pos++
	data = _0
}
Parser::Token_res AUTO_105() {
	ISPA_STR_TYPE _0
	bool success_1 = false
	if (!(!std::strncmp(pos, "\\", 2)))
	{
		return {}
	}
	_0 += *(pos0)
	success_1 = true
	pos++
	data = _0
}
Parser::Token_res AUTO_106() {
	UNDEF _0
	bool success_1 = false
	if (*pos == '\0')
	{
		return {}
	}
	_0 += *(pos0)
	success_1 = true
	pos++
	data = _0
}
Parser::Token_res AUTO_107() {
	ISPA_STR_TYPE _0
	bool success_1 = false
	if (!(*pos == '\r' || *pos == '\n'))
	{
		return {}
	}
	_0 += *(pos0)
	success_1 = true
	pos++
	data = _0
}
Parser::Token_res AUTO_108() {
	ISPA_STR_TYPE _0
	bool success_1 = false
	if (!(*pos == '#'))
	{
		return {}
	}
	_0 += *(pos0)
	success_1 = true
	pos++
	data = _0
}
Parser::Token_res AUTO_109() {
	ISPA_STR_TYPE _0
	bool success_1 = false
	if (!(!std::strncmp(pos, "0x", 2)))
	{
		return {}
	}
	_0 += *(pos0)
	success_1 = true
	pos++
	data = _0
}
Parser::Token_res AUTO_110() {
	ISPA_STR_TYPE _0
	bool success_1 = false
	if (!((*pos>='1' && *pos<='9') || (*pos>='A' && *pos<='F') || (*pos>='a' && *pos<='f')))
	{
		return {}
	}
	_0 += *(pos0)
	success_1 = true
	pos++
	data = _0
}
Parser::Token_res AUTO_111() {
	ISPA_STR_TYPE _0
	bool success_1 = false
	if (!(!std::strncmp(pos, "0b", 2)))
	{
		return {}
	}
	_0 += *(pos0)
	success_1 = true
	pos++
	data = _0
}
Parser::Token_res AUTO_112() {
	ISPA_STR_TYPE _0
	bool success_1 = false
	if (!(*pos == '0' || *pos == '1'))
	{
		return {}
	}
	_0 += *(pos0)
	success_1 = true
	pos++
	data = _0
}
