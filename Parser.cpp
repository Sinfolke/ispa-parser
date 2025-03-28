#include "Parser.h"
std::string Parser::TokenstoString(Tokens token) {
	switch (token) {
		case Tokens::NONE: return "NONE";
		case Tokens::OP: return "OP";
		case Tokens::ASSIGNMENT_OP: return "ASSIGNMENT_OP";
		case Tokens::COMPARE_OP: return "COMPARE_OP";
		case Tokens::LOGICAL_OP: return "LOGICAL_OP";
		case Tokens::LOGICAL_NOT: return "LOGICAL_NOT";
		case Tokens::LOGICAL_AND: return "LOGICAL_AND";
		case Tokens::LOGICAL_OR: return "LOGICAL_OR";
		case Tokens::STRING: return "STRING";
		case Tokens::NUMBER: return "NUMBER";
		case Tokens::BOOLEAN: return "BOOLEAN";
		case Tokens::END: return "END";
		case Tokens::NEWLINE: return "NEWLINE";
		case Tokens::LINEAR_COMMENT: return "LINEAR_COMMENT";
		case Tokens::ID: return "ID";
		case Tokens::AUTO_1: return "AUTO_1";
		case Tokens::AUTO_3: return "AUTO_3";
		case Tokens::AUTO_4: return "AUTO_4";
		case Tokens::AUTO_8: return "AUTO_8";
		case Tokens::AUTO_9: return "AUTO_9";
		case Tokens::AUTO_10: return "AUTO_10";
		case Tokens::AUTO_11: return "AUTO_11";
		case Tokens::AUTO_15: return "AUTO_15";
		case Tokens::AUTO_17: return "AUTO_17";
		case Tokens::AUTO_18: return "AUTO_18";
		case Tokens::AUTO_19: return "AUTO_19";
		case Tokens::AUTO_20: return "AUTO_20";
		case Tokens::AUTO_21: return "AUTO_21";
		case Tokens::AUTO_22: return "AUTO_22";
		case Tokens::AUTO_23: return "AUTO_23";
		case Tokens::AUTO_24: return "AUTO_24";
		case Tokens::AUTO_25: return "AUTO_25";
		case Tokens::AUTO_26: return "AUTO_26";
		case Tokens::AUTO_39: return "AUTO_39";
		case Tokens::AUTO_40: return "AUTO_40";
		case Tokens::AUTO_41: return "AUTO_41";
		case Tokens::AUTO_47: return "AUTO_47";
		case Tokens::AUTO_52: return "AUTO_52";
		case Tokens::AUTO_53: return "AUTO_53";
		case Tokens::AUTO_57: return "AUTO_57";
		case Tokens::AUTO_62: return "AUTO_62";
		case Tokens::AUTO_63: return "AUTO_63";
		case Tokens::AUTO_64: return "AUTO_64";
		case Tokens::AUTO_65: return "AUTO_65";
		case Tokens::AUTO_66: return "AUTO_66";
		case Tokens::AUTO_67: return "AUTO_67";
		case Tokens::AUTO_68: return "AUTO_68";
		case Tokens::AUTO_69: return "AUTO_69";
		case Tokens::AUTO_73: return "AUTO_73";
		case Tokens::AUTO_74: return "AUTO_74";
		case Tokens::AUTO_75: return "AUTO_75";
		case Tokens::AUTO_76: return "AUTO_76";
		case Tokens::AUTO_77: return "AUTO_77";
		case Tokens::AUTO_78: return "AUTO_78";
		case Tokens::AUTO_79: return "AUTO_79";
		case Tokens::AUTO_80: return "AUTO_80";
		case Tokens::AUTO_81: return "AUTO_81";
		case Tokens::AUTO_82: return "AUTO_82";
		case Tokens::AUTO_83: return "AUTO_83";
		case Tokens::AUTO_84: return "AUTO_84";
		case Tokens::AUTO_88: return "AUTO_88";
		case Tokens::AUTO_89: return "AUTO_89";
		case Tokens::AUTO_91: return "AUTO_91";
		case Tokens::AUTO_93: return "AUTO_93";
		case Tokens::AUTO_95: return "AUTO_95";
		case Tokens::AUTO_96: return "AUTO_96";
		case Tokens::AUTO_97: return "AUTO_97";
		case Tokens::AUTO_98: return "AUTO_98";
		case Tokens::AUTO_99: return "AUTO_99";
		case Tokens::AUTO_100: return "AUTO_100";
		case Tokens::AUTO_101: return "AUTO_101";
		case Tokens::AUTO_102: return "AUTO_102";
		case Tokens::AUTO_103: return "AUTO_103";
		case Tokens::__WHITESPACE: return "__WHITESPACE";
	}
	return "NONE";
}
bool Parser::Tokenizator::makeTokensFromFile(const char* path) {
    bool success;
    auto str = ISPA_STD::readFileToString(path, success);
    if (!success)
        return 0;
    makeTokens(str.c_str());
    return 1;
}
void Parser::Tokenizator::makeTokens(const char* pos) {
	this->str = pos;
	::Parser::arr_t<::Parser::arr_t<::Parser::Token>> shadow_203;
	::Parser::arr_t<::Parser::Token> _0;
	::Parser::bool_t success_1 = false;
	::Parser::bool_t success_204 = false;
	::Parser::arr_t<::Parser::Token> _2;
	::Parser::bool_t success_3 = false;
	::Parser::Token_res _4;
	::Parser::bool_t success_5 = false;
	::Parser::arr_t<::Parser::Token> shadow_6;
	::Parser::Token_res _7;
	::Parser::bool_t success_8 = false;
	::Parser::arr_t<::Parser::Token> shadow_9;
	::Parser::Token_res _10;
	::Parser::bool_t success_11 = false;
	::Parser::arr_t<::Parser::Token> shadow_12;
	::Parser::Token_res _13;
	::Parser::bool_t success_14 = false;
	::Parser::arr_t<::Parser::Token> shadow_15;
	::Parser::Token_res _16;
	::Parser::bool_t success_17 = false;
	::Parser::arr_t<::Parser::Token> shadow_18;
	::Parser::Token_res _19;
	::Parser::bool_t success_20 = false;
	::Parser::arr_t<::Parser::Token> shadow_21;
	::Parser::Token_res _22;
	::Parser::bool_t success_23 = false;
	::Parser::arr_t<::Parser::Token> shadow_24;
	::Parser::Token_res _25;
	::Parser::bool_t success_26 = false;
	::Parser::arr_t<::Parser::Token> shadow_27;
	::Parser::Token_res _28;
	::Parser::bool_t success_29 = false;
	::Parser::arr_t<::Parser::Token> shadow_30;
	::Parser::Token_res _31;
	::Parser::bool_t success_32 = false;
	::Parser::arr_t<::Parser::Token> shadow_33;
	::Parser::Token_res _34;
	::Parser::bool_t success_35 = false;
	::Parser::arr_t<::Parser::Token> shadow_36;
	::Parser::Token_res _37;
	::Parser::bool_t success_38 = false;
	::Parser::arr_t<::Parser::Token> shadow_39;
	::Parser::Token_res _40;
	::Parser::bool_t success_41 = false;
	::Parser::arr_t<::Parser::Token> shadow_42;
	::Parser::Token_res _43;
	::Parser::bool_t success_44 = false;
	::Parser::arr_t<::Parser::Token> shadow_45;
	::Parser::Token_res _46;
	::Parser::bool_t success_47 = false;
	::Parser::arr_t<::Parser::Token> shadow_48;
	::Parser::Token_res _49;
	::Parser::bool_t success_50 = false;
	::Parser::arr_t<::Parser::Token> shadow_51;
	::Parser::Token_res _52;
	::Parser::bool_t success_53 = false;
	::Parser::arr_t<::Parser::Token> shadow_54;
	::Parser::Token_res _55;
	::Parser::bool_t success_56 = false;
	::Parser::arr_t<::Parser::Token> shadow_57;
	::Parser::Token_res _58;
	::Parser::bool_t success_59 = false;
	::Parser::arr_t<::Parser::Token> shadow_60;
	::Parser::Token_res _61;
	::Parser::bool_t success_62 = false;
	::Parser::arr_t<::Parser::Token> shadow_63;
	::Parser::Token_res _64;
	::Parser::bool_t success_65 = false;
	::Parser::arr_t<::Parser::Token> shadow_66;
	::Parser::Token_res _67;
	::Parser::bool_t success_68 = false;
	::Parser::arr_t<::Parser::Token> shadow_69;
	::Parser::Token_res _70;
	::Parser::bool_t success_71 = false;
	::Parser::arr_t<::Parser::Token> shadow_72;
	::Parser::Token_res _73;
	::Parser::bool_t success_74 = false;
	::Parser::arr_t<::Parser::Token> shadow_75;
	::Parser::Token_res _76;
	::Parser::bool_t success_77 = false;
	::Parser::arr_t<::Parser::Token> shadow_78;
	::Parser::Token_res _79;
	::Parser::bool_t success_80 = false;
	::Parser::arr_t<::Parser::Token> shadow_81;
	::Parser::Token_res _82;
	::Parser::bool_t success_83 = false;
	::Parser::arr_t<::Parser::Token> shadow_84;
	::Parser::Token_res _85;
	::Parser::bool_t success_86 = false;
	::Parser::arr_t<::Parser::Token> shadow_87;
	::Parser::Token_res _88;
	::Parser::bool_t success_89 = false;
	::Parser::arr_t<::Parser::Token> shadow_90;
	::Parser::Token_res _91;
	::Parser::bool_t success_92 = false;
	::Parser::arr_t<::Parser::Token> shadow_93;
	::Parser::Token_res _94;
	::Parser::bool_t success_95 = false;
	::Parser::arr_t<::Parser::Token> shadow_96;
	::Parser::Token_res _97;
	::Parser::bool_t success_98 = false;
	::Parser::arr_t<::Parser::Token> shadow_99;
	::Parser::Token_res _100;
	::Parser::bool_t success_101 = false;
	::Parser::arr_t<::Parser::Token> shadow_102;
	::Parser::Token_res _103;
	::Parser::bool_t success_104 = false;
	::Parser::arr_t<::Parser::Token> shadow_105;
	::Parser::Token_res _106;
	::Parser::bool_t success_107 = false;
	::Parser::arr_t<::Parser::Token> shadow_108;
	::Parser::Token_res _109;
	::Parser::bool_t success_110 = false;
	::Parser::arr_t<::Parser::Token> shadow_111;
	::Parser::Token_res _112;
	::Parser::bool_t success_113 = false;
	::Parser::arr_t<::Parser::Token> shadow_114;
	::Parser::Token_res _115;
	::Parser::bool_t success_116 = false;
	::Parser::arr_t<::Parser::Token> shadow_117;
	::Parser::Token_res _118;
	::Parser::bool_t success_119 = false;
	::Parser::arr_t<::Parser::Token> shadow_120;
	::Parser::Token_res _121;
	::Parser::bool_t success_122 = false;
	::Parser::arr_t<::Parser::Token> shadow_123;
	::Parser::Token_res _124;
	::Parser::bool_t success_125 = false;
	::Parser::arr_t<::Parser::Token> shadow_126;
	::Parser::Token_res _127;
	::Parser::bool_t success_128 = false;
	::Parser::arr_t<::Parser::Token> shadow_129;
	::Parser::Token_res _130;
	::Parser::bool_t success_131 = false;
	::Parser::arr_t<::Parser::Token> shadow_132;
	::Parser::Token_res _133;
	::Parser::bool_t success_134 = false;
	::Parser::arr_t<::Parser::Token> shadow_135;
	::Parser::Token_res _136;
	::Parser::bool_t success_137 = false;
	::Parser::arr_t<::Parser::Token> shadow_138;
	::Parser::Token_res _139;
	::Parser::bool_t success_140 = false;
	::Parser::arr_t<::Parser::Token> shadow_141;
	::Parser::Token_res _142;
	::Parser::bool_t success_143 = false;
	::Parser::arr_t<::Parser::Token> shadow_144;
	::Parser::Token_res _145;
	::Parser::bool_t success_146 = false;
	::Parser::arr_t<::Parser::Token> shadow_147;
	::Parser::Token_res _148;
	::Parser::bool_t success_149 = false;
	::Parser::arr_t<::Parser::Token> shadow_150;
	::Parser::Token_res _151;
	::Parser::bool_t success_152 = false;
	::Parser::arr_t<::Parser::Token> shadow_153;
	::Parser::Token_res _154;
	::Parser::bool_t success_155 = false;
	::Parser::arr_t<::Parser::Token> shadow_156;
	::Parser::Token_res _157;
	::Parser::bool_t success_158 = false;
	::Parser::arr_t<::Parser::Token> shadow_159;
	::Parser::Token_res _160;
	::Parser::bool_t success_161 = false;
	::Parser::arr_t<::Parser::Token> shadow_162;
	::Parser::Token_res _163;
	::Parser::bool_t success_164 = false;
	::Parser::arr_t<::Parser::Token> shadow_165;
	::Parser::Token_res _166;
	::Parser::bool_t success_167 = false;
	::Parser::arr_t<::Parser::Token> shadow_168;
	::Parser::Token_res _169;
	::Parser::bool_t success_170 = false;
	::Parser::arr_t<::Parser::Token> shadow_171;
	::Parser::Token_res _172;
	::Parser::bool_t success_173 = false;
	::Parser::arr_t<::Parser::Token> shadow_174;
	::Parser::Token_res _175;
	::Parser::bool_t success_176 = false;
	::Parser::arr_t<::Parser::Token> shadow_177;
	::Parser::Token_res _178;
	::Parser::bool_t success_179 = false;
	::Parser::arr_t<::Parser::Token> shadow_180;
	::Parser::Token_res _181;
	::Parser::bool_t success_182 = false;
	::Parser::arr_t<::Parser::Token> shadow_183;
	::Parser::Token_res _184;
	::Parser::bool_t success_185 = false;
	::Parser::arr_t<::Parser::Token> shadow_186;
	::Parser::Token_res _187;
	::Parser::bool_t success_188 = false;
	::Parser::arr_t<::Parser::Token> shadow_189;
	::Parser::Token_res _190;
	::Parser::bool_t success_191 = false;
	::Parser::arr_t<::Parser::Token> shadow_192;
	::Parser::Token_res _193;
	::Parser::bool_t success_194 = false;
	::Parser::arr_t<::Parser::Token> shadow_195;
	::Parser::Token_res _196;
	::Parser::bool_t success_197 = false;
	::Parser::arr_t<::Parser::Token> shadow_198;
	::Parser::Token_res _199;
	::Parser::bool_t success_200 = false;
	::Parser::arr_t<::Parser::Token> shadow_201;
	auto begin_202 = pos;
	while (1)
	{
		if (*(begin_202 + 0) == '\0')
		{
			break;
		}
		_4 = OP(begin_202);
		if (!(_4.result))
		{
			_7 = ASSIGNMENT_OP(begin_202);
			if (!(_7.result))
			{
				_10 = COMPARE_OP(begin_202);
				if (!(_10.result))
				{
					_13 = LOGICAL_OP(begin_202);
					if (!(_13.result))
					{
						_16 = STRING(begin_202);
						if (!(_16.result))
						{
							_19 = NUMBER(begin_202);
							if (!(_19.result))
							{
								_22 = AUTO_83(begin_202);
								if (!(_22.result))
								{
									_25 = AUTO_98(begin_202);
									if (!(_25.result))
									{
										_28 = AUTO_101(begin_202);
										if (!(_28.result))
										{
											_31 = AUTO_103(begin_202);
											if (!(_31.result))
											{
												_34 = AUTO_63(begin_202);
												if (!(_34.result))
												{
													_37 = AUTO_8(begin_202);
													if (!(_37.result))
													{
														_40 = AUTO_64(begin_202);
														if (!(_40.result))
														{
															_43 = AUTO_65(begin_202);
															if (!(_43.result))
															{
																_46 = AUTO_18(begin_202);
																if (!(_46.result))
																{
																	_49 = AUTO_10(begin_202);
																	if (!(_49.result))
																	{
																		_52 = AUTO_15(begin_202);
																		if (!(_52.result))
																		{
																			_55 = AUTO_40(begin_202);
																			if (!(_55.result))
																			{
																				_58 = AUTO_66(begin_202);
																				if (!(_58.result))
																				{
																					_61 = AUTO_9(begin_202);
																					if (!(_61.result))
																					{
																						_64 = AUTO_17(begin_202);
																						if (!(_64.result))
																						{
																							_67 = AUTO_19(begin_202);
																							if (!(_67.result))
																							{
																								_70 = AUTO_67(begin_202);
																								if (!(_70.result))
																								{
																									_73 = AUTO_91(begin_202);
																									if (!(_73.result))
																									{
																										_76 = AUTO_11(begin_202);
																										if (!(_76.result))
																										{
																											_79 = AUTO_20(begin_202);
																											if (!(_79.result))
																											{
																												_82 = AUTO_21(begin_202);
																												if (!(_82.result))
																												{
																													_85 = AUTO_22(begin_202);
																													if (!(_85.result))
																													{
																														_88 = AUTO_23(begin_202);
																														if (!(_88.result))
																														{
																															_91 = AUTO_24(begin_202);
																															if (!(_91.result))
																															{
																																_94 = AUTO_25(begin_202);
																																if (!(_94.result))
																																{
																																	_97 = AUTO_41(begin_202);
																																	if (!(_97.result))
																																	{
																																		_100 = AUTO_68(begin_202);
																																		if (!(_100.result))
																																		{
																																			_103 = AUTO_84(begin_202);
																																			if (!(_103.result))
																																			{
																																				_106 = AUTO_26(begin_202);
																																				if (!(_106.result))
																																				{
																																					_109 = AUTO_39(begin_202);
																																					if (!(_109.result))
																																					{
																																						_112 = AUTO_52(begin_202);
																																						if (!(_112.result))
																																						{
																																							_115 = AUTO_53(begin_202);
																																							if (!(_115.result))
																																							{
																																								_118 = AUTO_96(begin_202);
																																								if (!(_118.result))
																																								{
																																									_121 = AUTO_100(begin_202);
																																									if (!(_121.result))
																																									{
																																										_124 = AUTO_102(begin_202);
																																										if (!(_124.result))
																																										{
																																											_127 = AUTO_1(begin_202);
																																											if (!(_127.result))
																																											{
																																												_130 = AUTO_3(begin_202);
																																												if (!(_130.result))
																																												{
																																													_133 = AUTO_4(begin_202);
																																													if (!(_133.result))
																																													{
																																														_136 = AUTO_47(begin_202);
																																														if (!(_136.result))
																																														{
																																															_139 = AUTO_57(begin_202);
																																															if (!(_139.result))
																																															{
																																																_142 = AUTO_62(begin_202);
																																																if (!(_142.result))
																																																{
																																																	_145 = AUTO_69(begin_202);
																																																	if (!(_145.result))
																																																	{
																																																		_148 = AUTO_73(begin_202);
																																																		if (!(_148.result))
																																																		{
																																																			_151 = AUTO_74(begin_202);
																																																			if (!(_151.result))
																																																			{
																																																				_154 = AUTO_75(begin_202);
																																																				if (!(_154.result))
																																																				{
																																																					_157 = AUTO_76(begin_202);
																																																					if (!(_157.result))
																																																					{
																																																						_160 = AUTO_77(begin_202);
																																																						if (!(_160.result))
																																																						{
																																																							_163 = AUTO_78(begin_202);
																																																							if (!(_163.result))
																																																							{
																																																								_166 = AUTO_79(begin_202);
																																																								if (!(_166.result))
																																																								{
																																																									_169 = AUTO_80(begin_202);
																																																									if (!(_169.result))
																																																									{
																																																										_172 = AUTO_81(begin_202);
																																																										if (!(_172.result))
																																																										{
																																																											_175 = AUTO_82(begin_202);
																																																											if (!(_175.result))
																																																											{
																																																												_178 = AUTO_88(begin_202);
																																																												if (!(_178.result))
																																																												{
																																																													_181 = AUTO_89(begin_202);
																																																													if (!(_181.result))
																																																													{
																																																														_184 = AUTO_93(begin_202);
																																																														if (!(_184.result))
																																																														{
																																																															_187 = AUTO_95(begin_202);
																																																															if (!(_187.result))
																																																															{
																																																																_190 = AUTO_99(begin_202);
																																																																if (!(_190.result))
																																																																{
																																																																	_193 = BOOLEAN(begin_202);
																																																																	if (!(_193.result))
																																																																	{
																																																																		_196 = ID(begin_202);
																																																																		if (!(_196.result))
																																																																		{
																																																																			_199 = AUTO_97(begin_202);
																																																																			if (!(_199.result))
																																																																			{
																																																																				break;
																																																																			}
																																																																			else 
																																																																			{
																																																																				success_200 = true;
																																																																				begin_202 += _199.token.length();
																																																																				shadow_201.push_back(_199.token);
																																																																				_2.push_back(_199.token);
																																																																			}
																																																																		}
																																																																		else 
																																																																		{
																																																																			success_197 = true;
																																																																			begin_202 += _196.token.length();
																																																																			shadow_198.push_back(_196.token);
																																																																			_2.push_back(_196.token);
																																																																		}
																																																																	}
																																																																	else 
																																																																	{
																																																																		success_194 = true;
																																																																		begin_202 += _193.token.length();
																																																																		shadow_195.push_back(_193.token);
																																																																		_2.push_back(_193.token);
																																																																	}
																																																																}
																																																																else 
																																																																{
																																																																	success_191 = true;
																																																																	begin_202 += _190.token.length();
																																																																	shadow_192.push_back(_190.token);
																																																																	_2.push_back(_190.token);
																																																																}
																																																															}
																																																															else 
																																																															{
																																																																success_188 = true;
																																																																begin_202 += _187.token.length();
																																																																shadow_189.push_back(_187.token);
																																																																_2.push_back(_187.token);
																																																															}
																																																														}
																																																														else 
																																																														{
																																																															success_185 = true;
																																																															begin_202 += _184.token.length();
																																																															shadow_186.push_back(_184.token);
																																																															_2.push_back(_184.token);
																																																														}
																																																													}
																																																													else 
																																																													{
																																																														success_182 = true;
																																																														begin_202 += _181.token.length();
																																																														shadow_183.push_back(_181.token);
																																																														_2.push_back(_181.token);
																																																													}
																																																												}
																																																												else 
																																																												{
																																																													success_179 = true;
																																																													begin_202 += _178.token.length();
																																																													shadow_180.push_back(_178.token);
																																																													_2.push_back(_178.token);
																																																												}
																																																											}
																																																											else 
																																																											{
																																																												success_176 = true;
																																																												begin_202 += _175.token.length();
																																																												shadow_177.push_back(_175.token);
																																																												_2.push_back(_175.token);
																																																											}
																																																										}
																																																										else 
																																																										{
																																																											success_173 = true;
																																																											begin_202 += _172.token.length();
																																																											shadow_174.push_back(_172.token);
																																																											_2.push_back(_172.token);
																																																										}
																																																									}
																																																									else 
																																																									{
																																																										success_170 = true;
																																																										begin_202 += _169.token.length();
																																																										shadow_171.push_back(_169.token);
																																																										_2.push_back(_169.token);
																																																									}
																																																								}
																																																								else 
																																																								{
																																																									success_167 = true;
																																																									begin_202 += _166.token.length();
																																																									shadow_168.push_back(_166.token);
																																																									_2.push_back(_166.token);
																																																								}
																																																							}
																																																							else 
																																																							{
																																																								success_164 = true;
																																																								begin_202 += _163.token.length();
																																																								shadow_165.push_back(_163.token);
																																																								_2.push_back(_163.token);
																																																							}
																																																						}
																																																						else 
																																																						{
																																																							success_161 = true;
																																																							begin_202 += _160.token.length();
																																																							shadow_162.push_back(_160.token);
																																																							_2.push_back(_160.token);
																																																						}
																																																					}
																																																					else 
																																																					{
																																																						success_158 = true;
																																																						begin_202 += _157.token.length();
																																																						shadow_159.push_back(_157.token);
																																																						_2.push_back(_157.token);
																																																					}
																																																				}
																																																				else 
																																																				{
																																																					success_155 = true;
																																																					begin_202 += _154.token.length();
																																																					shadow_156.push_back(_154.token);
																																																					_2.push_back(_154.token);
																																																				}
																																																			}
																																																			else 
																																																			{
																																																				success_152 = true;
																																																				begin_202 += _151.token.length();
																																																				shadow_153.push_back(_151.token);
																																																				_2.push_back(_151.token);
																																																			}
																																																		}
																																																		else 
																																																		{
																																																			success_149 = true;
																																																			begin_202 += _148.token.length();
																																																			shadow_150.push_back(_148.token);
																																																			_2.push_back(_148.token);
																																																		}
																																																	}
																																																	else 
																																																	{
																																																		success_146 = true;
																																																		begin_202 += _145.token.length();
																																																		shadow_147.push_back(_145.token);
																																																		_2.push_back(_145.token);
																																																	}
																																																}
																																																else 
																																																{
																																																	success_143 = true;
																																																	begin_202 += _142.token.length();
																																																	shadow_144.push_back(_142.token);
																																																	_2.push_back(_142.token);
																																																}
																																															}
																																															else 
																																															{
																																																success_140 = true;
																																																begin_202 += _139.token.length();
																																																shadow_141.push_back(_139.token);
																																																_2.push_back(_139.token);
																																															}
																																														}
																																														else 
																																														{
																																															success_137 = true;
																																															begin_202 += _136.token.length();
																																															shadow_138.push_back(_136.token);
																																															_2.push_back(_136.token);
																																														}
																																													}
																																													else 
																																													{
																																														success_134 = true;
																																														begin_202 += _133.token.length();
																																														shadow_135.push_back(_133.token);
																																														_2.push_back(_133.token);
																																													}
																																												}
																																												else 
																																												{
																																													success_131 = true;
																																													begin_202 += _130.token.length();
																																													shadow_132.push_back(_130.token);
																																													_2.push_back(_130.token);
																																												}
																																											}
																																											else 
																																											{
																																												success_128 = true;
																																												begin_202 += _127.token.length();
																																												shadow_129.push_back(_127.token);
																																												_2.push_back(_127.token);
																																											}
																																										}
																																										else 
																																										{
																																											success_125 = true;
																																											begin_202 += _124.token.length();
																																											shadow_126.push_back(_124.token);
																																											_2.push_back(_124.token);
																																										}
																																									}
																																									else 
																																									{
																																										success_122 = true;
																																										begin_202 += _121.token.length();
																																										shadow_123.push_back(_121.token);
																																										_2.push_back(_121.token);
																																									}
																																								}
																																								else 
																																								{
																																									success_119 = true;
																																									begin_202 += _118.token.length();
																																									shadow_120.push_back(_118.token);
																																									_2.push_back(_118.token);
																																								}
																																							}
																																							else 
																																							{
																																								success_116 = true;
																																								begin_202 += _115.token.length();
																																								shadow_117.push_back(_115.token);
																																								_2.push_back(_115.token);
																																							}
																																						}
																																						else 
																																						{
																																							success_113 = true;
																																							begin_202 += _112.token.length();
																																							shadow_114.push_back(_112.token);
																																							_2.push_back(_112.token);
																																						}
																																					}
																																					else 
																																					{
																																						success_110 = true;
																																						begin_202 += _109.token.length();
																																						shadow_111.push_back(_109.token);
																																						_2.push_back(_109.token);
																																					}
																																				}
																																				else 
																																				{
																																					success_107 = true;
																																					begin_202 += _106.token.length();
																																					shadow_108.push_back(_106.token);
																																					_2.push_back(_106.token);
																																				}
																																			}
																																			else 
																																			{
																																				success_104 = true;
																																				begin_202 += _103.token.length();
																																				shadow_105.push_back(_103.token);
																																				_2.push_back(_103.token);
																																			}
																																		}
																																		else 
																																		{
																																			success_101 = true;
																																			begin_202 += _100.token.length();
																																			shadow_102.push_back(_100.token);
																																			_2.push_back(_100.token);
																																		}
																																	}
																																	else 
																																	{
																																		success_98 = true;
																																		begin_202 += _97.token.length();
																																		shadow_99.push_back(_97.token);
																																		_2.push_back(_97.token);
																																	}
																																}
																																else 
																																{
																																	success_95 = true;
																																	begin_202 += _94.token.length();
																																	shadow_96.push_back(_94.token);
																																	_2.push_back(_94.token);
																																}
																															}
																															else 
																															{
																																success_92 = true;
																																begin_202 += _91.token.length();
																																shadow_93.push_back(_91.token);
																																_2.push_back(_91.token);
																															}
																														}
																														else 
																														{
																															success_89 = true;
																															begin_202 += _88.token.length();
																															shadow_90.push_back(_88.token);
																															_2.push_back(_88.token);
																														}
																													}
																													else 
																													{
																														success_86 = true;
																														begin_202 += _85.token.length();
																														shadow_87.push_back(_85.token);
																														_2.push_back(_85.token);
																													}
																												}
																												else 
																												{
																													success_83 = true;
																													begin_202 += _82.token.length();
																													shadow_84.push_back(_82.token);
																													_2.push_back(_82.token);
																												}
																											}
																											else 
																											{
																												success_80 = true;
																												begin_202 += _79.token.length();
																												shadow_81.push_back(_79.token);
																												_2.push_back(_79.token);
																											}
																										}
																										else 
																										{
																											success_77 = true;
																											begin_202 += _76.token.length();
																											shadow_78.push_back(_76.token);
																											_2.push_back(_76.token);
																										}
																									}
																									else 
																									{
																										success_74 = true;
																										begin_202 += _73.token.length();
																										shadow_75.push_back(_73.token);
																										_2.push_back(_73.token);
																									}
																								}
																								else 
																								{
																									success_71 = true;
																									begin_202 += _70.token.length();
																									shadow_72.push_back(_70.token);
																									_2.push_back(_70.token);
																								}
																							}
																							else 
																							{
																								success_68 = true;
																								begin_202 += _67.token.length();
																								shadow_69.push_back(_67.token);
																								_2.push_back(_67.token);
																							}
																						}
																						else 
																						{
																							success_65 = true;
																							begin_202 += _64.token.length();
																							shadow_66.push_back(_64.token);
																							_2.push_back(_64.token);
																						}
																					}
																					else 
																					{
																						success_62 = true;
																						begin_202 += _61.token.length();
																						shadow_63.push_back(_61.token);
																						_2.push_back(_61.token);
																					}
																				}
																				else 
																				{
																					success_59 = true;
																					begin_202 += _58.token.length();
																					shadow_60.push_back(_58.token);
																					_2.push_back(_58.token);
																				}
																			}
																			else 
																			{
																				success_56 = true;
																				begin_202 += _55.token.length();
																				shadow_57.push_back(_55.token);
																				_2.push_back(_55.token);
																			}
																		}
																		else 
																		{
																			success_53 = true;
																			begin_202 += _52.token.length();
																			shadow_54.push_back(_52.token);
																			_2.push_back(_52.token);
																		}
																	}
																	else 
																	{
																		success_50 = true;
																		begin_202 += _49.token.length();
																		shadow_51.push_back(_49.token);
																		_2.push_back(_49.token);
																	}
																}
																else 
																{
																	success_47 = true;
																	begin_202 += _46.token.length();
																	shadow_48.push_back(_46.token);
																	_2.push_back(_46.token);
																}
															}
															else 
															{
																success_44 = true;
																begin_202 += _43.token.length();
																shadow_45.push_back(_43.token);
																_2.push_back(_43.token);
															}
														}
														else 
														{
															success_41 = true;
															begin_202 += _40.token.length();
															shadow_42.push_back(_40.token);
															_2.push_back(_40.token);
														}
													}
													else 
													{
														success_38 = true;
														begin_202 += _37.token.length();
														shadow_39.push_back(_37.token);
														_2.push_back(_37.token);
													}
												}
												else 
												{
													success_35 = true;
													begin_202 += _34.token.length();
													shadow_36.push_back(_34.token);
													_2.push_back(_34.token);
												}
											}
											else 
											{
												success_32 = true;
												begin_202 += _31.token.length();
												shadow_33.push_back(_31.token);
												_2.push_back(_31.token);
											}
										}
										else 
										{
											success_29 = true;
											begin_202 += _28.token.length();
											shadow_30.push_back(_28.token);
											_2.push_back(_28.token);
										}
									}
									else 
									{
										success_26 = true;
										begin_202 += _25.token.length();
										shadow_27.push_back(_25.token);
										_2.push_back(_25.token);
									}
								}
								else 
								{
									success_23 = true;
									begin_202 += _22.token.length();
									shadow_24.push_back(_22.token);
									_2.push_back(_22.token);
								}
							}
							else 
							{
								success_20 = true;
								begin_202 += _19.token.length();
								shadow_21.push_back(_19.token);
								_2.push_back(_19.token);
							}
						}
						else 
						{
							success_17 = true;
							begin_202 += _16.token.length();
							shadow_18.push_back(_16.token);
							_2.push_back(_16.token);
						}
					}
					else 
					{
						success_14 = true;
						begin_202 += _13.token.length();
						shadow_15.push_back(_13.token);
						_2.push_back(_13.token);
					}
				}
				else 
				{
					success_11 = true;
					begin_202 += _10.token.length();
					shadow_12.push_back(_10.token);
					_2.push_back(_10.token);
				}
			}
			else 
			{
				success_8 = true;
				begin_202 += _7.token.length();
				shadow_9.push_back(_7.token);
				_2.push_back(_7.token);
			}
		}
		else 
		{
			success_5 = true;
			begin_202 += _4.token.length();
			shadow_6.push_back(_4.token);
			_2.push_back(_4.token);
		}
		success_3 = true;
		_0 = _2;
		shadow_203.push_back(_0);
		success_204 = true;
	}
	if (!success_204)
	{
		return;
	}
	if (success_3)
	{
		success_1 = true;
		pos = begin_202;
	}
	ISPA_STD::skip_spaces(pos);
	this->tokens = _0;
}
Parser::Rule_res Parser::Parser::accessor_group(::Parser::arr_t<Token>::iterator pos) {
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
	pos++;
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name == Tokens::NUMBER))
	{
		return {};
	}
	_2 = *pos;
	success_3 = true;
	pos++;
	accessor_group_data data = _2;
	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::accessor_group, data)};
}
Parser::Rule_res Parser::Parser::accessor_element(::Parser::arr_t<Token>::iterator pos) {
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
	pos++;
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name == Tokens::NUMBER))
	{
		return {};
	}
	_2 = *pos;
	success_3 = true;
	pos++;
	accessor_element_data data = _2;
	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::accessor_element, data)};
}
Parser::Rule_res Parser::Parser::accessor_char(::Parser::arr_t<Token>::iterator pos) {
	auto in = pos;
	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	::Parser::Token _2;
	::Parser::bool_t success_3 = false;
	if (!(pos->name == Tokens::AUTO_81))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos++;
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name == Tokens::NUMBER))
	{
		return {};
	}
	_2 = *pos;
	success_3 = true;
	pos++;
	accessor_char_data data = _2;
	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::accessor_char, data)};
}
Parser::Rule_res Parser::Parser::accessor_all(::Parser::arr_t<Token>::iterator pos) {
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
				std::advance(pos, _6.token.length());
				_0 = _6.token;
			}
		}
		else 
		{
			success_5 = true;
			std::advance(pos, _4.token.length());
			_0 = _4.token;
		}
	}
	else 
	{
		success_3 = true;
		std::advance(pos, _2.token.length());
		_0 = _2.token;
	}
	success_1 = true;
	accessor_all_data data = _0;
	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::accessor_all, data)};
}
Parser::Rule_res Parser::Parser::accessor(::Parser::arr_t<Token>::iterator pos) {
	auto in = pos;
	::Parser::Rule_res _0;
	::Parser::bool_t success_1 = false;
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
	std::advance(pos, _0.token.length());
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	auto begin_10 = pos;
	while (1)
	{
		if (!(begin_10->name == Tokens::AUTO_3))
		{
			break;
		}
		_4 = *begin_10;
		success_5 = true;
		begin_10++;
		shadow_6.push_back(_4);
		ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
		_7 = accessor_all(begin_10);
		if (!(_7.result))
		{
			break;
		}
		success_8 = true;
		std::advance(begin_10, _7.token.length());
		shadow_9.push_back(_7.token);
	}
	if (success_5 && success_8)
	{
		success_3 = true;
		pos = begin_10;
	}
	accessor_data data;
	data.second = shadow_9;
	data.first = _0.token;

	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::accessor, data)};
}
Parser::Rule_res Parser::Parser::cll(::Parser::arr_t<Token>::iterator pos) {
	auto in = pos;
	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	::Parser::bool_t success_3 = false;
	::Parser::bool_t success_34 = false;
	::Parser::arr_t<::Parser::Rule> _4;
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
	::Parser::Token _30;
	::Parser::bool_t success_31 = false;
	::Parser::arr_t<::Parser::Token> shadow_32;
	if (!(pos->name == Tokens::AUTO_4))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos++;
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	auto begin_33 = pos;
	while (1)
	{
		auto begin_29 = begin_33;
		_8 = cll_var(begin_29);
		if (!(_8.result))
		{
			_11 = cll_if(begin_29);
			if (!(_11.result))
			{
				_14 = expr(begin_29);
				if (!(_14.result))
				{
					_17 = method_call(begin_29);
					if (!(_17.result))
					{
						_20 = loop_while(begin_29);
						if (!(_20.result))
						{
							_23 = loop_for(begin_29);
							if (!(_23.result))
							{
								_26 = copiable_method_call(begin_29);
								if (!(_26.result))
								{
									break;
								}
								else 
								{
									success_27 = true;
									std::advance(begin_29, _26.token.length());
									shadow_28.push_back(_26.token);
									_6.push_back(_26.token);
								}
							}
							else 
							{
								success_24 = true;
								std::advance(begin_29, _23.token.length());
								shadow_25.push_back(_23.token);
								_6.push_back(_23.token);
							}
						}
						else 
						{
							success_21 = true;
							std::advance(begin_29, _20.token.length());
							shadow_22.push_back(_20.token);
							_6.push_back(_20.token);
						}
					}
					else 
					{
						success_18 = true;
						std::advance(begin_29, _17.token.length());
						shadow_19.push_back(_17.token);
						_6.push_back(_17.token);
					}
				}
				else 
				{
					success_15 = true;
					std::advance(begin_29, _14.token.length());
					shadow_16.push_back(_14.token);
					_6.push_back(_14.token);
				}
			}
			else 
			{
				success_12 = true;
				std::advance(begin_29, _11.token.length());
				shadow_13.push_back(_11.token);
				_6.push_back(_11.token);
			}
		}
		else 
		{
			success_9 = true;
			std::advance(begin_29, _8.token.length());
			shadow_10.push_back(_8.token);
			_6.push_back(_8.token);
		}
		success_7 = true;
		_4 = _6;
		if (success_7)
		{
			success_5 = true;
			begin_33 = begin_29;
		}
		ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
		if (!(begin_33->name == Tokens::END))
		{
			break;
		}
		_30 = *begin_33;
		success_31 = true;
		begin_33++;
		shadow_32.push_back(_30);
		success_34 = true;
	}
	if (!success_34)
	{
		return {};
	}
	if (success_5 && success_31)
	{
		success_3 = true;
		pos = begin_33;
	}
	cll_data data = _4;
	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::cll, data)};
}
Parser::Rule_res Parser::Parser::cll_block(::Parser::arr_t<Token>::iterator pos) {
	auto in = pos;
	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	::Parser::Token _2;
	::Parser::bool_t success_3 = false;
	::Parser::arr_t<::Parser::Token> shadow_4;
	::Parser::Token _5;
	::Parser::bool_t success_6 = false;
	if (!(pos->name == Tokens::AUTO_57))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos++;
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	while (pos->name == Tokens::AUTO_73)
	{
		_2 = *pos;
		success_3 = true;
		pos++;
		shadow_4.push_back(_2);
	}
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name == Tokens::AUTO_62))
	{
		return {};
	}
	_5 = *pos;
	success_6 = true;
	pos++;
	cll_block_data data = shadow_4;
	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::cll_block, data)};
}
Parser::Token_res Parser::Tokenizator::OP(const char* pos) {
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
	::Parser::str_t _14;
	::Parser::bool_t success_15 = false;
	::Parser::str_t _16;
	::Parser::bool_t success_17 = false;
	::Parser::str_t _18;
	::Parser::bool_t success_19 = false;
	::Parser::str_t _20;
	::Parser::bool_t success_21 = false;
	if (!(!std::strncmp(pos, "<<", 2)))
	{
		if (!(!std::strncmp(pos, ">>", 2)))
		{
			if (!(*(pos + 0) == '+'))
			{
				if (!(*(pos + 0) == '-'))
				{
					if (!(*(pos + 0) == '*'))
					{
						if (!(*(pos + 0) == '/'))
						{
							if (!(*(pos + 0) == '%'))
							{
								if (!(*(pos + 0) == '&'))
								{
									if (!(*(pos + 0) == '|'))
									{
										if (!(*(pos + 0) == '^'))
										{
											return {};
										}
										else 
										{
											_20 += ::Parser::str_t(pos, 1);
											success_21 = true;
											pos += 1;
											_0 += _20;
										}
									}
									else 
									{
										_18 += ::Parser::str_t(pos, 1);
										success_19 = true;
										pos += 1;
										_0 += _18;
									}
								}
								else 
								{
									_16 += ::Parser::str_t(pos, 1);
									success_17 = true;
									pos += 1;
									_0 += _16;
								}
							}
							else 
							{
								_14 += ::Parser::str_t(pos, 1);
								success_15 = true;
								pos += 1;
								_0 += _14;
							}
						}
						else 
						{
							_12 += ::Parser::str_t(pos, 1);
							success_13 = true;
							pos += 1;
							_0 += _12;
						}
					}
					else 
					{
						_10 += ::Parser::str_t(pos, 1);
						success_11 = true;
						pos += 1;
						_0 += _10;
					}
				}
				else 
				{
					_8 += ::Parser::str_t(pos, 1);
					success_9 = true;
					pos += 1;
					_0 += _8;
				}
			}
			else 
			{
				_6 += ::Parser::str_t(pos, 1);
				success_7 = true;
				pos += 1;
				_0 += _6;
			}
		}
		else 
		{
			_4 += ::Parser::str_t(pos, 2);
			success_5 = true;
			pos += 2;
			_0 += _4;
		}
	}
	else 
	{
		_2 += ::Parser::str_t(pos, 2);
		success_3 = true;
		pos += 2;
		_0 += _2;
	}
	success_1 = true;
	OP_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::OP, data)};
}
Parser::Token_res Parser::Tokenizator::ASSIGNMENT_OP(const char* pos) {
	auto in = pos;
	::Parser::Token_res _0;
	::Parser::bool_t success_1 = false;
	::Parser::Token_res _2;
	::Parser::bool_t success_3 = false;
	_0 = OP(pos);
	if (_0.result)
	{
		success_1 = true;
		pos += _0.token.length();
	}
	ISPA_STD::skip_spaces(pos);
	_2 = AUTO_47(pos);
	if (!(_2.result))
	{
		return {};
	}
	success_3 = true;
	pos += _2.token.length();
	ASSIGNMENT_OP_data data = _0.token;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::ASSIGNMENT_OP, data)};
}
Parser::Token_res Parser::Tokenizator::COMPARE_OP(const char* pos) {
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
			if (!(!std::strncmp(pos, ">=", 2)))
			{
				if (!(!std::strncmp(pos, "<=", 2)))
				{
					if (!(*(pos + 0) == '>'))
					{
						if (!(*(pos + 0) == '<'))
						{
							return {};
						}
						else 
						{
							_12 += ::Parser::str_t(pos, 1);
							success_13 = true;
							pos += 1;
							_0 += _12;
						}
					}
					else 
					{
						_10 += ::Parser::str_t(pos, 1);
						success_11 = true;
						pos += 1;
						_0 += _10;
					}
				}
				else 
				{
					_8 += ::Parser::str_t(pos, 2);
					success_9 = true;
					pos += 2;
					_0 += _8;
				}
			}
			else 
			{
				_6 += ::Parser::str_t(pos, 2);
				success_7 = true;
				pos += 2;
				_0 += _6;
			}
		}
		else 
		{
			_4 += ::Parser::str_t(pos, 2);
			success_5 = true;
			pos += 2;
			_0 += _4;
		}
	}
	else 
	{
		_2 += ::Parser::str_t(pos, 2);
		success_3 = true;
		pos += 2;
		_0 += _2;
	}
	success_1 = true;
	COMPARE_OP_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::COMPARE_OP, data)};
}
Parser::Token_res Parser::Tokenizator::LOGICAL_OP(const char* pos) {
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
			pos += _4.token.length();
			_0 = _4.token;
		}
	}
	else 
	{
		success_3 = true;
		pos += _2.token.length();
		_0 = _2.token;
	}
	success_1 = true;
	LOGICAL_OP_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::LOGICAL_OP, data)};
}
Parser::Token_res Parser::Tokenizator::LOGICAL_NOT(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	::Parser::str_t _2;
	::Parser::bool_t success_3 = false;
	::Parser::str_t _4;
	::Parser::bool_t success_5 = false;
	if (!(!std::strncmp(pos, "not", 3)))
	{
		if (!(*(pos + 0) == '!'))
		{
			return {};
		}
		else 
		{
			_4 += ::Parser::str_t(pos, 1);
			success_5 = true;
			pos += 1;
			_0 += _4;
		}
	}
	else 
	{
		_2 += ::Parser::str_t(pos, 3);
		success_3 = true;
		pos += 3;
		_0 += _2;
	}
	success_1 = true;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::LOGICAL_NOT)};
}
Parser::Token_res Parser::Tokenizator::LOGICAL_AND(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	::Parser::str_t _2;
	::Parser::bool_t success_3 = false;
	::Parser::str_t _4;
	::Parser::bool_t success_5 = false;
	if (!(!std::strncmp(pos, "and", 3)))
	{
		if (!(!std::strncmp(pos, "&&", 2)))
		{
			return {};
		}
		else 
		{
			_4 += ::Parser::str_t(pos, 2);
			success_5 = true;
			pos += 2;
			_0 += _4;
		}
	}
	else 
	{
		_2 += ::Parser::str_t(pos, 3);
		success_3 = true;
		pos += 3;
		_0 += _2;
	}
	success_1 = true;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::LOGICAL_AND)};
}
Parser::Token_res Parser::Tokenizator::LOGICAL_OR(const char* pos) {
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
			_4 += ::Parser::str_t(pos, 2);
			success_5 = true;
			pos += 2;
			_0 += _4;
		}
	}
	else 
	{
		_2 += ::Parser::str_t(pos, 2);
		success_3 = true;
		pos += 2;
		_0 += _2;
	}
	success_1 = true;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::LOGICAL_OR)};
}
Parser::Rule_res Parser::Parser::cll_template(::Parser::arr_t<Token>::iterator pos) {
	auto in = pos;
	::Parser::Rule_res _0;
	::Parser::bool_t success_1 = false;
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
	std::advance(pos, _0.token.length());
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	auto begin_10 = pos;
	while (1)
	{
		if (!(begin_10->name == Tokens::AUTO_69))
		{
			break;
		}
		_4 = *begin_10;
		success_5 = true;
		begin_10++;
		shadow_6.push_back(_4);
		ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
		_7 = cll_type(begin_10);
		if (!(_7.result))
		{
			return {};
		}
		success_8 = true;
		std::advance(begin_10, _7.token.length());
		shadow_9.push_back(_7.token);
	}
	if (success_5 && success_8)
	{
		success_3 = true;
		pos = begin_10;
	}
	cll_template_data data;
	data.second = shadow_9;
	data.first = _0.token;

	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::cll_template, data)};
}
Parser::Rule_res Parser::Parser::cll_csupport_types(::Parser::arr_t<Token>::iterator pos) {
	auto in = pos;
	::Parser::any_t _0;
	::Parser::bool_t success_1 = false;
	::Parser::bool_t success_3 = false;
	::Parser::Token _4;
	::Parser::bool_t success_5 = false;
	::Parser::any_t _6;
	::Parser::bool_t success_7 = false;
	::Parser::any_t _8;
	::Parser::bool_t success_9 = false;
	::Parser::Token _10;
	::Parser::bool_t success_11 = false;
	::Parser::Token _12;
	::Parser::bool_t success_13 = false;
	::Parser::Token _14;
	::Parser::bool_t success_15 = false;
	::Parser::Token _16;
	::Parser::bool_t success_17 = false;
	::Parser::bool_t success_19 = false;
	::Parser::Token _20;
	::Parser::bool_t success_21 = false;
	::Parser::Token _22;
	::Parser::bool_t success_23 = false;
	::Parser::any_t _27;
	::Parser::bool_t success_28 = false;
	::Parser::any_t _29;
	::Parser::bool_t success_30 = false;
	::Parser::Token _31;
	::Parser::bool_t success_32 = false;
	::Parser::Token _33;
	::Parser::bool_t success_34 = false;
	::Parser::bool_t success_36 = false;
	::Parser::Token _37;
	::Parser::bool_t success_38 = false;
	::Parser::Token _39;
	::Parser::bool_t success_40 = false;
	auto begin_26 = pos;
	do
	{
		if (begin_26->name == Tokens::AUTO_8)
		{
			_4 = *begin_26;
			success_5 = true;
			begin_26++;
		}
		ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
		auto begin_25 = begin_26;
		if (!(begin_25->name == Tokens::AUTO_9))
		{
			if (!(begin_25->name == Tokens::AUTO_10))
			{
				if (!(begin_25->name == Tokens::AUTO_11))
				{
					if (!(begin_25->name == Tokens::AUTO_17))
					{
						auto begin_24 = begin_25;
						do
						{
							if (!(begin_24->name == Tokens::AUTO_17))
							{
								break;
							}
							_20 = *begin_24;
							success_21 = true;
							begin_24++;
							ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
							if (!(begin_24->name == Tokens::AUTO_17))
							{
								break;
							}
							_22 = *begin_24;
							success_23 = true;
							begin_24++;
						}
						while(0)
;
						if (success_21 && success_23)
						{
							success_19 = true;
							begin_25 = begin_24;
						}
						;
						if (!success_19)
						{
							break;
						}
					}
					else 
					{
						_16 = *begin_25;
						success_17 = true;
						std::advance(begin_25, 1);
						_8 = _16;
					}
				}
				else 
				{
					_14 = *begin_25;
					success_15 = true;
					std::advance(begin_25, 1);
					_8 = _14;
				}
			}
			else 
			{
				_12 = *begin_25;
				success_13 = true;
				begin_25++;
				_8 = _12;
			}
		}
		else 
		{
			_10 = *begin_25;
			success_11 = true;
			begin_25++;
			_8 = _10;
		}
		success_9 = true;
		if (success_9)
		{
			success_7 = true;
			begin_26 = begin_25;
		}
	}
	while(0)
;
	if (success_7)
	{
		success_3 = true;
		pos = begin_26;
	}
	;
	if (!success_3)
	{
		auto begin_42 = pos;
		do
		{
			if (!(begin_42->name == Tokens::AUTO_15))
			{
				if (!(begin_42->name == Tokens::AUTO_18))
				{
					auto begin_41 = begin_42;
					do
					{
						if (!(begin_41->name == Tokens::AUTO_17))
						{
							break;
						}
						_37 = *begin_41;
						success_38 = true;
						begin_41++;
						ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
						if (!(begin_41->name == Tokens::AUTO_18))
						{
							break;
						}
						_39 = *begin_41;
						success_40 = true;
						begin_41++;
					}
					while(0)
;
					if (success_38 && success_40)
					{
						success_36 = true;
						begin_42 = begin_41;
					}
					;
					if (!success_36)
					{
						break;
					}
				}
				else 
				{
					_33 = *begin_42;
					success_34 = true;
					std::advance(begin_42, 1);
					_29 = _33;
				}
			}
			else 
			{
				_31 = *begin_42;
				success_32 = true;
				std::advance(begin_42, 1);
				_29 = _31;
			}
			success_30 = true;
		}
		while(0)
;
		if (success_30)
		{
			success_28 = true;
			pos = begin_42;
		}
		;
		if (!success_28)
		{
			return {};
		}
		else 
		{
			_0 = _27;
		}
	}
	success_1 = true;
	cll_csupport_types_data data;
	data.templ = _20;
	data.type = _4;

	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::cll_csupport_types, data)};
}
Parser::Rule_res Parser::Parser::cll_type_abstract(::Parser::arr_t<Token>::iterator pos) {
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
	if (!(begin_28->name == Tokens::AUTO_19))
	{
		if (!(begin_28->name == Tokens::AUTO_20))
		{
			if (!(begin_28->name == Tokens::AUTO_21))
			{
				if (!(begin_28->name == Tokens::AUTO_22))
				{
					if (!(begin_28->name == Tokens::AUTO_23))
					{
						auto begin_20 = begin_28;
						do
						{
							if (!(begin_20->name == Tokens::AUTO_24))
							{
								break;
							}
							_16 = *begin_20;
							success_17 = true;
							begin_20++;
							ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
							_18 = cll_template(begin_20);
							if (!(_18.result))
							{
								break;
							}
							success_19 = true;
							std::advance(begin_20, _18.token.length());
						}
						while(0)
;
						if (success_17 && success_19)
						{
							success_15 = true;
							begin_28 = begin_20;
						}
						;
						if (!success_15)
						{
							auto begin_27 = begin_28;
							do
							{
								if (!(begin_27->name == Tokens::AUTO_25))
								{
									break;
								}
								_23 = *begin_27;
								success_24 = true;
								begin_27++;
								ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
								_25 = cll_template(begin_27);
								if (!(_25.result))
								{
									break;
								}
								success_26 = true;
								std::advance(begin_27, _25.token.length());
							}
							while(0)
;
							if (success_24 && success_26)
							{
								success_22 = true;
								begin_28 = begin_27;
							}
							;
							if (!success_22)
							{
								return {};
							}
						}
					}
					else 
					{
						_12 = *begin_28;
						success_13 = true;
						std::advance(begin_28, 1);
						_2 = _12;
					}
				}
				else 
				{
					_10 = *begin_28;
					success_11 = true;
					std::advance(begin_28, 1);
					_2 = _10;
				}
			}
			else 
			{
				_8 = *begin_28;
				success_9 = true;
				std::advance(begin_28, 1);
				_2 = _8;
			}
		}
		else 
		{
			_6 = *begin_28;
			success_7 = true;
			std::advance(begin_28, 1);
			_2 = _6;
		}
	}
	else 
	{
		_4 = *begin_28;
		success_5 = true;
		std::advance(begin_28, 1);
		_2 = _4;
	}
	success_3 = true;
	if (success_3)
	{
		success_1 = true;
		pos = begin_28;
	}
	cll_type_abstract_data data;
	data.templ = _23;
	data.type = _16;

	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::cll_type_abstract, data)};
}
Parser::Rule_res Parser::Parser::cll_type(::Parser::arr_t<Token>::iterator pos) {
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
			std::advance(pos, _4.token.length());
			_0 = _4.token;
		}
	}
	else 
	{
		success_3 = true;
		std::advance(pos, _2.token.length());
		_0 = _2.token;
	}
	success_1 = true;
	cll_type_data data = _0;
	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::cll_type, data)};
}
Parser::Rule_res Parser::Parser::cll_if(::Parser::arr_t<Token>::iterator pos) {
	auto in = pos;
	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	::Parser::Rule_res _2;
	::Parser::bool_t success_3 = false;
	::Parser::Rule_res _4;
	::Parser::bool_t success_5 = false;
	if (!(pos->name == Tokens::AUTO_26))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos++;
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	_2 = expr(pos);
	if (!(_2.result))
	{
		return {};
	}
	success_3 = true;
	std::advance(pos, _2.token.length());
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	_4 = cll_block(pos);
	if (!(_4.result))
	{
		return {};
	}
	success_5 = true;
	std::advance(pos, _4.token.length());
	cll_if_data data;
	data.block = _4.token;
	data.expr = _2.token;

	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::cll_if, data)};
}
Parser::Rule_res Parser::Parser::cll_ternary(::Parser::arr_t<Token>::iterator pos) {
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
	std::advance(pos, _0.token.length());
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name == Tokens::AUTO_74))
	{
		return {};
	}
	_2 = *pos;
	success_3 = true;
	pos++;
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	_4 = expr(pos);
	if (!(_4.result))
	{
		return {};
	}
	success_5 = true;
	std::advance(pos, _4.token.length());
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name == Tokens::AUTO_95))
	{
		return {};
	}
	_6 = *pos;
	success_7 = true;
	pos++;
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	_8 = expr(pos);
	if (!(_8.result))
	{
		return {};
	}
	success_9 = true;
	std::advance(pos, _8.token.length());
	cll_ternary_data data;
	data.second = _8.token;
	data.first = _4.token;
	data.cond = _0.token;

	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::cll_ternary, data)};
}
Parser::Rule_res Parser::Parser::expr_logical(::Parser::arr_t<Token>::iterator pos) {
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
				std::advance(pos, _6.token.length());
				_0 = _6.token;
			}
		}
		else 
		{
			success_5 = true;
			std::advance(pos, _4.token.length());
			_0 = _4.token;
		}
	}
	else 
	{
		success_3 = true;
		std::advance(pos, _2.token.length());
		_0 = _2.token;
	}
	success_1 = true;
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name == Tokens::LOGICAL_OP))
	{
		return {};
	}
	_8 = *pos;
	success_9 = true;
	pos++;
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
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
				std::advance(pos, _16.token.length());
				_10 = _16.token;
			}
		}
		else 
		{
			success_15 = true;
			std::advance(pos, _14.token.length());
			_10 = _14.token;
		}
	}
	else 
	{
		success_13 = true;
		std::advance(pos, _12.token.length());
		_10 = _12.token;
	}
	success_11 = true;
	expr_logical_data data;
	data.right = _10;
	data.op = _8;
	data.left = _0;

	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::expr_logical, data)};
}
Parser::Rule_res Parser::Parser::expr_compare(::Parser::arr_t<Token>::iterator pos) {
	auto in = pos;
	::Parser::Rule_res _0;
	::Parser::bool_t success_1 = false;
	::Parser::bool_t success_3 = false;
	::Parser::bool_t success_11 = false;
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
	std::advance(pos, _0.token.length());
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	auto begin_10 = pos;
	while (1)
	{
		if (!(begin_10->name == Tokens::COMPARE_OP))
		{
			break;
		}
		_4 = *begin_10;
		success_5 = true;
		begin_10++;
		shadow_6.push_back(_4);
		ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
		_7 = expr_arithmetic(begin_10);
		if (!(_7.result))
		{
			break;
		}
		success_8 = true;
		std::advance(begin_10, _7.token.length());
		shadow_9.push_back(_7.token);
		success_11 = true;
	}
	if (!success_11)
	{
		return {};
	}
	if (success_5 && success_8)
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
Parser::Rule_res Parser::Parser::expr_arithmetic(::Parser::arr_t<Token>::iterator pos) {
	auto in = pos;
	::Parser::Rule_res _0;
	::Parser::bool_t success_1 = false;
	::Parser::bool_t success_3 = false;
	::Parser::bool_t success_11 = false;
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
	std::advance(pos, _0.token.length());
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	auto begin_10 = pos;
	while (1)
	{
		if (!(begin_10->name == Tokens::OP))
		{
			break;
		}
		_4 = *begin_10;
		success_5 = true;
		begin_10++;
		shadow_6.push_back(_4);
		ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
		_7 = expr_for_arithmetic(begin_10);
		if (!(_7.result))
		{
			break;
		}
		success_8 = true;
		std::advance(begin_10, _7.token.length());
		shadow_9.push_back(_7.token);
		success_11 = true;
	}
	if (!success_11)
	{
		return {};
	}
	if (success_5 && success_8)
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
Parser::Rule_res Parser::Parser::expr_for_arithmetic(::Parser::arr_t<Token>::iterator pos) {
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
	_2 = cll_function_call(pos);
	if (!(_2.result))
	{
		_4 = method_call(pos);
		if (!(_4.result))
		{
			_6 = expr_group(pos);
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
					std::advance(pos, _8.token.length());
					_0 = _8.token;
				}
			}
			else 
			{
				success_7 = true;
				std::advance(pos, _6.token.length());
				_0 = _6.token;
			}
		}
		else 
		{
			success_5 = true;
			std::advance(pos, _4.token.length());
			_0 = _4.token;
		}
	}
	else 
	{
		success_3 = true;
		std::advance(pos, _2.token.length());
		_0 = _2.token;
	}
	success_1 = true;
	expr_for_arithmetic_data data = _0;
	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::expr_for_arithmetic, data)};
}
Parser::Rule_res Parser::Parser::expr_group(::Parser::arr_t<Token>::iterator pos) {
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
	if (!(pos->name == Tokens::AUTO_78))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos++;
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
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
			std::advance(pos, _6.token.length());
			_2 = _6.token;
		}
	}
	else 
	{
		success_5 = true;
		std::advance(pos, _4.token.length());
		_2 = _4.token;
	}
	success_3 = true;
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name == Tokens::AUTO_79))
	{
		return {};
	}
	_8 = *pos;
	success_9 = true;
	pos++;
	expr_group_data data = _2;
	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::expr_group, data)};
}
Parser::Rule_res Parser::Parser::expr_expr_copiable_method_call(::Parser::arr_t<Token>::iterator pos) {
	auto in = pos;
	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	::Parser::Rule_res _2;
	::Parser::bool_t success_3 = false;
	::Parser::Token _4;
	::Parser::bool_t success_5 = false;
	if (!(pos->name == Tokens::AUTO_78))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos++;
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	_2 = copiable_method_call(pos);
	if (!(_2.result))
	{
		return {};
	}
	success_3 = true;
	std::advance(pos, _2.token.length());
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name == Tokens::AUTO_79))
	{
		return {};
	}
	_4 = *pos;
	success_5 = true;
	pos++;
	expr_expr_copiable_method_call_data data = _2.token;
	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::expr_expr_copiable_method_call, data)};
}
Parser::Rule_res Parser::Parser::expr(::Parser::arr_t<Token>::iterator pos) {
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
				_8 = cll_function_call(pos);
				if (!(_8.result))
				{
					_10 = expr_group(pos);
					if (!(_10.result))
					{
						_12 = expr_expr_copiable_method_call(pos);
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
								std::advance(pos, _14.token.length());
								_0 = _14.token;
							}
						}
						else 
						{
							success_13 = true;
							std::advance(pos, _12.token.length());
							_0 = _12.token;
						}
					}
					else 
					{
						success_11 = true;
						std::advance(pos, _10.token.length());
						_0 = _10.token;
					}
				}
				else 
				{
					success_9 = true;
					std::advance(pos, _8.token.length());
					_0 = _8.token;
				}
			}
			else 
			{
				success_7 = true;
				std::advance(pos, _6.token.length());
				_0 = _6.token;
			}
		}
		else 
		{
			success_5 = true;
			std::advance(pos, _4.token.length());
			_0 = _4.token;
		}
	}
	else 
	{
		success_3 = true;
		std::advance(pos, _2.token.length());
		_0 = _2.token;
	}
	success_1 = true;
	expr_data data = _0;
	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::expr, data)};
}
Parser::Rule_res Parser::Parser::function_body_call(::Parser::arr_t<Token>::iterator pos) {
	auto in = pos;
	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	::Parser::Rule_res _2;
	::Parser::bool_t success_3 = false;
	::Parser::Token _4;
	::Parser::bool_t success_5 = false;
	if (!(pos->name == Tokens::AUTO_78))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos++;
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	_2 = function_arguments(pos);
	if (!(_2.result))
	{
		return {};
	}
	success_3 = true;
	std::advance(pos, _2.token.length());
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name == Tokens::AUTO_79))
	{
		return {};
	}
	_4 = *pos;
	success_5 = true;
	pos++;
	function_body_call_data data = _2.token;
	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::function_body_call, data)};
}
Parser::Rule_res Parser::Parser::function_body_decl(::Parser::arr_t<Token>::iterator pos) {
	auto in = pos;
	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	::Parser::Rule_res _2;
	::Parser::bool_t success_3 = false;
	::Parser::Token _4;
	::Parser::bool_t success_5 = false;
	if (!(pos->name == Tokens::AUTO_78))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos++;
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	_2 = function_parameters(pos);
	if (!(_2.result))
	{
		return {};
	}
	success_3 = true;
	std::advance(pos, _2.token.length());
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name == Tokens::AUTO_79))
	{
		return {};
	}
	_4 = *pos;
	success_5 = true;
	pos++;
	function_body_decl_data data = _2.token;
	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::function_body_decl, data)};
}
Parser::Rule_res Parser::Parser::function_arguments(::Parser::arr_t<Token>::iterator pos) {
	auto in = pos;
	::Parser::bool_t success_1 = false;
	::Parser::any_t _2;
	::Parser::bool_t success_3 = false;
	::Parser::Rule_res _4;
	::Parser::bool_t success_5 = false;
	::Parser::Token _6;
	::Parser::bool_t success_7 = false;
	::Parser::arr_t<::Parser::arr_t<::Parser::Token>> shadow_16;
	::Parser::arr_t<::Parser::Token> _8;
	::Parser::bool_t success_9 = false;
	::Parser::arr_t<::Parser::Token> _10;
	::Parser::bool_t success_11 = false;
	::Parser::Token _12;
	::Parser::bool_t success_13 = false;
	::Parser::arr_t<::Parser::Token> shadow_14;
	auto begin_17 = pos;
	_4 = any_data(begin_17);
	if (!(_4.result))
	{
		if (!(begin_17->name == Tokens::ID))
		{
			return {};
		}
		else 
		{
			_6 = *begin_17;
			success_7 = true;
			begin_17++;
			_2 = _6;
		}
	}
	else 
	{
		success_5 = true;
		std::advance(begin_17, _4.token.length());
		_2 = _4.token;
	}
	success_3 = true;
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	auto begin_15 = begin_17;
	while (1)
	{
		if (!(begin_15->name == Tokens::AUTO_69))
		{
			break;
		}
		else 
		{
			_12 = *begin_15;
			success_13 = true;
			begin_15++;
			shadow_14.push_back(_12);
			_10.push_back(_12);
		}
		success_11 = true;
		_8 = _10;
		shadow_16.push_back(_8);
	}
	if (success_11)
	{
		success_9 = true;
		begin_17 = begin_15;
	}
	if (success_3)
	{
		success_1 = true;
		pos = begin_17;
	}
	function_arguments_data data;
	data.second = shadow_16;
	data.first = _2;

	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::function_arguments, data)};
}
Parser::Rule_res Parser::Parser::function_parameters(::Parser::arr_t<Token>::iterator pos) {
	auto in = pos;
	::Parser::bool_t success_1 = false;
	::Parser::Token _2;
	::Parser::bool_t success_3 = false;
	::Parser::bool_t success_5 = false;
	::Parser::Token _6;
	::Parser::bool_t success_7 = false;
	::Parser::arr_t<::Parser::Token> shadow_8;
	::Parser::Token _9;
	::Parser::bool_t success_10 = false;
	::Parser::arr_t<::Parser::Token> shadow_11;
	auto begin_13 = pos;
	if (!(begin_13->name == Tokens::ID))
	{
		return {};
	}
	_2 = *begin_13;
	success_3 = true;
	begin_13++;
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	auto begin_12 = begin_13;
	while (1)
	{
		if (!(begin_12->name == Tokens::AUTO_69))
		{
			break;
		}
		_6 = *begin_12;
		success_7 = true;
		begin_12++;
		shadow_8.push_back(_6);
		ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
		if (!(begin_12->name == Tokens::ID))
		{
			break;
		}
		_9 = *begin_12;
		success_10 = true;
		begin_12++;
		shadow_11.push_back(_9);
	}
	if (success_7 && success_10)
	{
		success_5 = true;
		begin_13 = begin_12;
	}
	if (success_3 && success_5)
	{
		success_1 = true;
		pos = begin_13;
	}
	function_parameters_data data;
	data.second = shadow_11;
	data.first = _2;

	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::function_parameters, data)};
}
Parser::Rule_res Parser::Parser::cll_function_call(::Parser::arr_t<Token>::iterator pos) {
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
	pos++;
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	_2 = function_body_call(pos);
	if (!(_2.result))
	{
		return {};
	}
	success_3 = true;
	std::advance(pos, _2.token.length());
	cll_function_call_data data;
	data.body = _2.token;
	data.name = _0;

	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::cll_function_call, data)};
}
Parser::Rule_res Parser::Parser::function_decl(::Parser::arr_t<Token>::iterator pos) {
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
	::Parser::Rule_res _12;
	::Parser::bool_t success_13 = false;
	if (!(pos->name == Tokens::AUTO_39))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos++;
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	auto begin_8 = pos;
	while (begin_8->name == Tokens::ID)
	{
		_4 = *begin_8;
		success_5 = true;
		begin_8++;
		shadow_6.push_back(_4);
		success_7 = true;
	}
	if (!success_7)
	{
		return {};
	}
	_2 = _4;
	if (success_5)
	{
		success_3 = true;
		pos = begin_8;
	}
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	_9 = function_body_decl(pos);
	if (!(_9.result))
	{
		return {};
	}
	success_10 = true;
	std::advance(pos, _9.token.length());
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	auto begin_14 = pos;
	do
	{
		_12 = cll_block(begin_14);
		if (!(_12.result))
		{
			break;
		}
		success_13 = true;
		std::advance(begin_14, _12.token.length());
		val = _12.token;
	}
	while(0)
;
	if (success_13)
	{
		success_11 = true;
		pos = begin_14;
	}
	function_decl_data data;
	data.value = val;
	data.name = _2;
	data.type = shadow_6;

	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::function_decl, data)};
}
Parser::Rule_res Parser::Parser::loop_while(::Parser::arr_t<Token>::iterator pos) {
	auto in = pos;
	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	::Parser::Rule_res _2;
	::Parser::bool_t success_3 = false;
	::Parser::Rule_res _4;
	::Parser::bool_t success_5 = false;
	if (!(pos->name == Tokens::AUTO_40))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos++;
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	_2 = expr(pos);
	if (!(_2.result))
	{
		return {};
	}
	success_3 = true;
	std::advance(pos, _2.token.length());
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	_4 = cll_block(pos);
	if (!(_4.result))
	{
		return {};
	}
	success_5 = true;
	std::advance(pos, _4.token.length());
	loop_while_data data;
	data.block = _4.token;
	data.expr = _2.token;

	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::loop_while, data)};
}
Parser::Rule_res Parser::Parser::loop_for(::Parser::arr_t<Token>::iterator pos) {
	auto in = pos;
	::Parser::Token _0;
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
	::Parser::Rule_res _23;
	::Parser::bool_t success_24 = false;
	if (!(pos->name == Tokens::AUTO_41))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos++;
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name == Tokens::AUTO_78))
	{
		return {};
	}
	_2 = *pos;
	success_3 = true;
	pos++;
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
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
				std::advance(begin_12, _10.token.length());
				_6 = _10.token;
			}
		}
		else 
		{
			success_9 = true;
			std::advance(begin_12, _8.token.length());
			_6 = _8.token;
		}
		success_7 = true;
		_4 = _6;
	}
	while(0)
;
	if (success_7)
	{
		success_5 = true;
		pos = begin_12;
	}
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name == Tokens::AUTO_93))
	{
		return {};
	}
	_13 = *pos;
	success_14 = true;
	pos++;
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	_15 = expr(pos);
	if (_15.result)
	{
		success_16 = true;
		std::advance(pos, _15.token.length());
	}
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name == Tokens::AUTO_93))
	{
		return {};
	}
	_17 = *pos;
	success_18 = true;
	pos++;
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	_19 = expr(pos);
	if (_19.result)
	{
		success_20 = true;
		std::advance(pos, _19.token.length());
	}
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name == Tokens::AUTO_79))
	{
		return {};
	}
	_21 = *pos;
	success_22 = true;
	pos++;
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	_23 = cll_block(pos);
	if (!(_23.result))
	{
		return {};
	}
	success_24 = true;
	std::advance(pos, _23.token.length());
	loop_for_data data;
	data.block = _21;
	data.end = _17;
	data.cond = _13;
	data.decl = _6;

	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::loop_for, data)};
}
Parser::Rule_res Parser::Parser::method_call(::Parser::arr_t<Token>::iterator pos) {
	auto in = pos;
	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	::Parser::bool_t success_3 = false;
	::Parser::bool_t success_11 = false;
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
	pos++;
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	auto begin_10 = pos;
	while (1)
	{
		if (!(begin_10->name == Tokens::AUTO_89))
		{
			break;
		}
		_4 = *begin_10;
		success_5 = true;
		begin_10++;
		shadow_6.push_back(_4);
		ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
		_7 = cll_function_call(begin_10);
		if (!(_7.result))
		{
			break;
		}
		success_8 = true;
		std::advance(begin_10, _7.token.length());
		shadow_9.push_back(_7.token);
		success_11 = true;
	}
	if (!success_11)
	{
		return {};
	}
	if (success_5 && success_8)
	{
		success_3 = true;
		pos = begin_10;
	}
	method_call_data data;
	data.call = shadow_9;
	data.object = _0;

	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::method_call, data)};
}
Parser::Rule_res Parser::Parser::copiable_method_call(::Parser::arr_t<Token>::iterator pos) {
	auto in = pos;
	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	::Parser::Rule_res _2;
	::Parser::bool_t success_3 = false;
	if (!(pos->name == Tokens::AUTO_47))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos++;
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	_2 = method_call(pos);
	if (!(_2.result))
	{
		return {};
	}
	success_3 = true;
	std::advance(pos, _2.token.length());
	copiable_method_call_data data = _2.token;
	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::copiable_method_call, data)};
}
Parser::Rule_res Parser::Parser::var_refer(::Parser::arr_t<Token>::iterator pos) {
	auto in = pos;
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
		if (!(begin_8->name == Tokens::AUTO_52))
		{
			if (!(begin_8->name == Tokens::AUTO_53))
			{
				break;
			}
			else 
			{
				_6 = *begin_8;
				success_7 = true;
				begin_8++;
				_2 = _6;
			}
		}
		else 
		{
			_4 = *begin_8;
			success_5 = true;
			begin_8++;
			_2 = _4;
		}
		success_3 = true;
		_0 = _2;
	}
	while(0)
;
	if (success_3)
	{
		success_1 = true;
		pos = begin_8;
	}
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name == Tokens::ID))
	{
		return {};
	}
	_9 = *pos;
	success_10 = true;
	pos++;
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	auto begin_19 = pos;
	do
	{
		if (!(begin_19->name == Tokens::AUTO_80))
		{
			break;
		}
		_13 = *begin_19;
		success_14 = true;
		begin_19++;
		ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
		_15 = expr(begin_19);
		if (!(_15.result))
		{
			break;
		}
		success_16 = true;
		std::advance(begin_19, _15.token.length());
		ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
		if (!(begin_19->name == Tokens::AUTO_82))
		{
			break;
		}
		_17 = *begin_19;
		success_18 = true;
		begin_19++;
	}
	while(0)
;
	if (success_14 && success_16 && success_18)
	{
		success_12 = true;
		pos = begin_19;
	}
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	auto begin_28 = pos;
	do
	{
		if (!(begin_28->name == Tokens::AUTO_52))
		{
			if (!(begin_28->name == Tokens::AUTO_53))
			{
				break;
			}
			else 
			{
				_26 = *begin_28;
				success_27 = true;
				begin_28++;
				_22 = _26;
			}
		}
		else 
		{
			_24 = *begin_28;
			success_25 = true;
			begin_28++;
			_22 = _24;
		}
		success_23 = true;
		_20 = _22;
	}
	while(0)
;
	if (success_23)
	{
		success_21 = true;
		pos = begin_28;
	}
	var_refer_data data;
	data.post = _20;
	data.pre = _0;
	data.brace_expression = _15.token;
	data.name = _2;

	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::var_refer, data)};
}
Parser::Rule_res Parser::Parser::cll_var(::Parser::arr_t<Token>::iterator pos) {
	auto in = pos;
	::Parser::Rule_res _0;
	::Parser::bool_t success_1 = false;
	::Parser::Token _2;
	::Parser::bool_t success_3 = false;
	::Parser::bool_t success_5 = false;
	::Parser::Token _6;
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
		std::advance(pos, _0.token.length());
	}
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name == Tokens::ID))
	{
		return {};
	}
	_2 = *pos;
	success_3 = true;
	pos++;
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	auto begin_14 = pos;
	do
	{
		if (!(begin_14->name == Tokens::ASSIGNMENT_OP))
		{
			break;
		}
		_6 = *begin_14;
		success_7 = true;
		begin_14++;
		ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
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
				std::advance(begin_14, _12.token.length());
				_8 = _12.token;
			}
		}
		else 
		{
			success_11 = true;
			std::advance(begin_14, _10.token.length());
			_8 = _10.token;
		}
		success_9 = true;
	}
	while(0)
;
	if (success_7 && success_9)
	{
		success_5 = true;
		pos = begin_14;
	}
	cll_var_data data;
	data.value = _8;
	data.op = _6;
	data.id = _2;
	data.type = _0.token;

	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::cll_var, data)};
}
Parser::Token_res Parser::Tokenizator::STRING(const char* pos) {
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
	::Parser::str_t _15;
	::Parser::bool_t success_16 = false;
	::Parser::str_t _18;
	::Parser::bool_t success_19 = false;
	::Parser::str_t _20;
	::Parser::bool_t success_21 = false;
	::Parser::str_t _22;
	::Parser::bool_t success_23 = false;
	::Parser::str_t _24;
	::Parser::bool_t success_25 = false;
	::Parser::str_t _26;
	::Parser::bool_t success_27 = false;
	::Parser::str_t _28;
	::Parser::bool_t success_29 = false;
	::Parser::str_t _31;
	::Parser::bool_t success_32 = false;
	auto begin_17 = pos;
	do
	{
		if (!(*(begin_17 + 0) == '\''))
		{
			break;
		}
		_4 += ::Parser::str_t(begin_17, 1);
		success_5 = true;
		begin_17 += 1;
		ISPA_STD::skip_spaces(begin_17);
		auto begin_14 = begin_17;
		while (1)
		{
			if (!(!std::strncmp(begin_14, "\\'", 2)))
			{
				if (!(!(*(begin_14 + 0) == '\'' || *(begin_14 + 0) == '\0')))
				{
					break;
				}
				else 
				{
					_12 += ::Parser::str_t(begin_14, 1);
					success_13 = true;
					begin_14 += 1;
					_8 += _12;
				}
			}
			else 
			{
				_10 += ::Parser::str_t(begin_14, 2);
				success_11 = true;
				begin_14 += 2;
				_8 += _10;
			}
			success_9 = true;
			_6 += _8;
		}
		if (success_9)
		{
			success_7 = true;
			begin_17 = begin_14;
		}
		ISPA_STD::skip_spaces(begin_17);
		if (!(*(begin_17 + 0) == '\''))
		{
			break;
		}
		_15 += ::Parser::str_t(begin_17, 1);
		success_16 = true;
		begin_17 += 1;
		_2 += _4;
		_2 += _6;
		_2 += _15;
	}
	while(0)
;
	if (success_5 && success_16)
	{
		success_3 = true;
		pos = begin_17;
	}
	;
	if (!success_3)
	{
		auto begin_33 = pos;
		do
		{
			if (!(*(begin_33 + 0) == '"'))
			{
				break;
			}
			_20 += ::Parser::str_t(begin_33, 1);
			success_21 = true;
			begin_33 += 1;
			ISPA_STD::skip_spaces(begin_33);
			auto begin_30 = begin_33;
			while (1)
			{
				if (!(!std::strncmp(begin_30, "\\\"", 2)))
				{
					if (!(!(*(begin_30 + 0) == '"' || *(begin_30 + 0) == '\0')))
					{
						break;
					}
					else 
					{
						_28 += ::Parser::str_t(begin_30, 1);
						success_29 = true;
						begin_30 += 1;
						_24 += _28;
					}
				}
				else 
				{
					_26 += ::Parser::str_t(begin_30, 2);
					success_27 = true;
					begin_30 += 2;
					_24 += _26;
				}
				success_25 = true;
				_22 += _24;
			}
			if (success_25)
			{
				success_23 = true;
				begin_33 = begin_30;
			}
			ISPA_STD::skip_spaces(begin_33);
			if (!(*(begin_33 + 0) == '"'))
			{
				break;
			}
			_31 += ::Parser::str_t(begin_33, 1);
			success_32 = true;
			begin_33 += 1;
			_18 += _20;
			_18 += _22;
			_18 += _31;
		}
		while(0)
;
		if (success_21 && success_32)
		{
			success_19 = true;
			pos = begin_33;
		}
		;
		if (!success_19)
		{
			return {};
		}
		else 
		{
			_0 += _18;
		}
	}
	else 
	{
		_0 += _2;
	}
	success_1 = true;
	STRING_data data = _6;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::STRING, data)};
}
Parser::Token_res Parser::Tokenizator::NUMBER(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	::Parser::str_t _2;
	::Parser::bool_t success_3 = false;
	::Parser::str_t _4;
	::Parser::bool_t success_5 = false;
	::Parser::bool_t success_6 = false;
	::Parser::str_t _8;
	::Parser::bool_t success_9 = false;
	::Parser::str_t _10;
	::Parser::bool_t success_11 = false;
	::Parser::str_t _12;
	::Parser::bool_t success_13 = false;
	::Parser::bool_t success_14 = false;
	if (!(*(pos + 0) == '+' || *(pos + 0) == '-'))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 1);
	success_1 = true;
	pos += 1;
	ISPA_STD::skip_spaces(pos);
	auto begin_7 = pos;
	while ((*(begin_7 + 0)>='0' && *(begin_7 + 0)<='9'))
	{
		_4 += ::Parser::str_t(begin_7, 1);
		success_5 = true;
		begin_7 += 1;
		success_6 = true;
	}
	if (!success_6)
	{
		return {};
	}
	_2 += _4;
	if (success_5)
	{
		success_3 = true;
		pos = begin_7;
	}
	ISPA_STD::skip_spaces(pos);
	auto begin_15 = pos;
	do
	{
		if (!(*(begin_15 + 0) == '.' || *(begin_15 + 0) == ','))
		{
			break;
		}
		_10 += ::Parser::str_t(begin_15, 1);
		success_11 = true;
		begin_15 += 1;
		ISPA_STD::skip_spaces(begin_15);
		while ((*(begin_15 + 0)>='0' && *(begin_15 + 0)<='9'))
		{
			_12 += ::Parser::str_t(begin_15, 1);
			success_13 = true;
			begin_15 += 1;
			success_14 = true;
		}
		if (!success_14)
		{
			break;
		}
		_8 += _10;
		_8 += _12;
	}
	while(0)
;
	if (success_11 && success_13)
	{
		success_9 = true;
		pos = begin_15;
	}
	NUMBER_data data;
	data.dec = _2;
	data.main = _4;
	data.sign = _0;

	return {true, ::Parser::Token(in - str, in, pos, Tokens::NUMBER, data)};
}
Parser::Token_res Parser::Tokenizator::BOOLEAN(const char* pos) {
	auto in = pos;
	::Parser::str_t d;
	::Parser::bool_t success_0 = false;
	::Parser::str_t _1;
	::Parser::bool_t success_2 = false;
	::Parser::str_t _3;
	::Parser::bool_t success_4 = false;
	::Parser::str_t _5;
	::Parser::bool_t success_6 = false;
	auto begin_7 = pos;
	if (!(!std::strncmp(begin_7, "false", 5)))
	{
		if (!(!std::strncmp(begin_7, "true", 4)))
		{
			return {};
		}
		else 
		{
			_5 += ::Parser::str_t(begin_7, 4);
			success_6 = true;
			begin_7 += 4;
			_1 += _5;
		}
	}
	else 
	{
		_3 += ::Parser::str_t(begin_7, 5);
		success_4 = true;
		begin_7 += 5;
		_1 += _3;
	}
	success_2 = true;
	d += _1;
	if (success_2)
	{
		success_0 = true;
		pos = begin_7;
	}
	BOOLEAN_data data = d;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::BOOLEAN, data)};
}
Parser::Rule_res Parser::Parser::array(::Parser::arr_t<Token>::iterator pos) {
	auto in = pos;
	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	::Parser::bool_t success_3 = false;
	::Parser::bool_t success_5 = false;
	::Parser::Rule_res _6;
	::Parser::bool_t success_7 = false;
	::Parser::arr_t<::Parser::Rule> shadow_8;
	::Parser::Token _9;
	::Parser::bool_t success_10 = false;
	::Parser::arr_t<::Parser::Token> shadow_11;
	::Parser::Token _14;
	::Parser::bool_t success_15 = false;
	if (!(pos->name == Tokens::AUTO_80))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos++;
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	auto begin_13 = pos;
	do
	{
		auto begin_12 = begin_13;
		while (1)
		{
			_6 = any_data(begin_12);
			if (!(_6.result))
			{
				break;
			}
			success_7 = true;
			std::advance(begin_12, _6.token.length());
			shadow_8.push_back(_6.token);
			ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
			if (!(begin_12->name == Tokens::AUTO_69))
			{
				break;
			}
			_9 = *begin_12;
			success_10 = true;
			begin_12++;
			shadow_11.push_back(_9);
		}
		if (success_7 && success_10)
		{
			success_5 = true;
			begin_13 = begin_12;
		}
	}
	while(0)
;
	if (success_5)
	{
		success_3 = true;
		pos = begin_13;
	}
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name == Tokens::AUTO_82))
	{
		return {};
	}
	_14 = *pos;
	success_15 = true;
	pos++;
	array_data data = shadow_11;
	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::array, data)};
}
Parser::Rule_res Parser::Parser::object(::Parser::arr_t<Token>::iterator pos) {
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
	::Parser::Token _25;
	::Parser::bool_t success_26 = false;
	::Parser::Token _28;
	::Parser::bool_t success_29 = false;
	if (!(pos->name == Tokens::AUTO_57))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos++;
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	auto begin_27 = pos;
	do
	{
		_4 = any_data(begin_27);
		if (!(_4.result))
		{
			break;
		}
		success_5 = true;
		std::advance(begin_27, _4.token.length());
		ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
		if (!(begin_27->name == Tokens::AUTO_95))
		{
			break;
		}
		_6 = *begin_27;
		success_7 = true;
		begin_27++;
		ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
		_8 = any_data(begin_27);
		if (!(_8.result))
		{
			return {};
		}
		success_9 = true;
		std::advance(begin_27, _8.token.length());
		ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
		auto begin_24 = begin_27;
		while (1)
		{
			if (!(begin_24->name == Tokens::AUTO_69))
			{
				break;
			}
			_12 = *begin_24;
			success_13 = true;
			begin_24++;
			shadow_14.push_back(_12);
			ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
			if (!(begin_24->name == Tokens::ID))
			{
				break;
			}
			_15 = *begin_24;
			success_16 = true;
			begin_24++;
			shadow_17.push_back(_15);
			ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
			if (!(begin_24->name == Tokens::AUTO_95))
			{
				break;
			}
			_18 = *begin_24;
			success_19 = true;
			begin_24++;
			shadow_20.push_back(_18);
			ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
			_21 = any_data(begin_24);
			if (!(_21.result))
			{
				break;
			}
			success_22 = true;
			std::advance(begin_24, _21.token.length());
			shadow_23.push_back(_21.token);
		}
		if (success_13 && success_16 && success_19 && success_22)
		{
			success_11 = true;
			begin_27 = begin_24;
		}
		ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
		if (!(begin_27->name == Tokens::AUTO_93))
		{
			return {};
		}
		_25 = *begin_27;
		success_26 = true;
		begin_27++;
	}
	while(0)
;
	if (success_5 && success_7 && success_9 && success_11 && success_26)
	{
		success_3 = true;
		pos = begin_27;
	}
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name == Tokens::AUTO_62))
	{
		return {};
	}
	_28 = *pos;
	success_29 = true;
	pos++;
	object_data data;
	data.values = shadow_23;
	data.keys = shadow_17;
	data.value = _8.token;
	data.key = _4.token;

	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::object, data)};
}
Parser::Rule_res Parser::Parser::any_data(::Parser::arr_t<Token>::iterator pos) {
	auto in = pos;
	::Parser::any_t _0;
	::Parser::bool_t success_1 = false;
	::Parser::Token _2;
	::Parser::bool_t success_3 = false;
	::Parser::Token _4;
	::Parser::bool_t success_5 = false;
	::Parser::Rule_res _6;
	::Parser::bool_t success_7 = false;
	::Parser::Rule_res _8;
	::Parser::bool_t success_9 = false;
	::Parser::Rule_res _10;
	::Parser::bool_t success_11 = false;
	::Parser::Token _12;
	::Parser::bool_t success_13 = false;
	::Parser::Token _14;
	::Parser::bool_t success_15 = false;
	if (!(pos->name == Tokens::NUMBER))
	{
		if (!(pos->name == Tokens::STRING))
		{
			_6 = accessor(pos);
			if (!(_6.result))
			{
				_8 = array(pos);
				if (!(_8.result))
				{
					_10 = object(pos);
					if (!(_10.result))
					{
						if (!(pos->name == Tokens::BOOLEAN))
						{
							if (!(pos->name == Tokens::ID))
							{
								return {};
							}
							else 
							{
								_14 = *pos;
								success_15 = true;
								pos++;
								_0 = _14;
							}
						}
						else 
						{
							_12 = *pos;
							success_13 = true;
							pos++;
							_0 = _12;
						}
					}
					else 
					{
						success_11 = true;
						std::advance(pos, _10.token.length());
						_0 = _10.token;
					}
				}
				else 
				{
					success_9 = true;
					std::advance(pos, _8.token.length());
					_0 = _8.token;
				}
			}
			else 
			{
				success_7 = true;
				std::advance(pos, _6.token.length());
				_0 = _6.token;
			}
		}
		else 
		{
			_4 = *pos;
			success_5 = true;
			std::advance(pos, 1);
			_0 = _4;
		}
	}
	else 
	{
		_2 = *pos;
		success_3 = true;
		std::advance(pos, 1);
		_0 = _2;
	}
	success_1 = true;
	any_data_data data = _0;
	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::any_data, data)};
}
Parser::Token_res Parser::Tokenizator::END(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == ';' || *(pos + 0) == '\n'))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 1);
	success_1 = true;
	pos += 1;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::END)};
}
Parser::Token_res Parser::Tokenizator::NEWLINE(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == '\n'))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 1);
	success_1 = true;
	pos += 1;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::NEWLINE)};
}
Parser::Token_res Parser::Tokenizator::LINEAR_COMMENT(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	::Parser::str_t _2;
	::Parser::bool_t success_3 = false;
	if (!(!std::strncmp(pos + 0, "//", 2)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 2);
	success_1 = true;
	pos += 2;
	ISPA_STD::skip_spaces(pos);
	if (!(!(*(pos + 0) == '\n' || *(pos + 0) == '\0')))
	{
		return {};
	}
	_2 += ::Parser::str_t(pos, 1);
	success_3 = true;
	pos += 1;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::LINEAR_COMMENT)};
}
Parser::Token_res Parser::Tokenizator::ID(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	::Parser::str_t _2;
	::Parser::bool_t success_3 = false;
	::Parser::str_t _4;
	::Parser::bool_t success_5 = false;
	::Parser::str_t _6;
	::Parser::bool_t success_7 = false;
	auto begin_8 = pos;
	while ((*(begin_8 + 0)>='0' && *(begin_8 + 0)<='9'))
	{
		_2 += ::Parser::str_t(begin_8, 1);
		success_3 = true;
		begin_8 += 1;
	}
	ISPA_STD::skip_spaces(begin_8);
	if (!((*(begin_8 + 0)>='a' && *(begin_8 + 0)<='z') || (*(begin_8 + 0)>='A' && *(begin_8 + 0)<='Z') || *(begin_8 + 0) == '_'))
	{
		return {};
	}
	_4 += ::Parser::str_t(begin_8, 1);
	success_5 = true;
	begin_8 += 1;
	ISPA_STD::skip_spaces(begin_8);
	while ((*(begin_8 + 0)>='a' && *(begin_8 + 0)<='z') || (*(begin_8 + 0)>='A' && *(begin_8 + 0)<='Z') || (*(begin_8 + 0)>='0' && *(begin_8 + 0)<='9') || *(begin_8 + 0) == '_')
	{
		_6 += ::Parser::str_t(begin_8, 1);
		success_7 = true;
		begin_8 += 1;
	}
	_0 += _2;
	_0 += _4;
	_0 += _6;
	if (success_5)
	{
		success_1 = true;
		pos = begin_8;
	}
	ID_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::ID, data)};
}
Parser::Rule_res Parser::Parser::spacemode(::Parser::arr_t<Token>::iterator pos) {
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
	if (!(pos->name == Tokens::AUTO_63))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos++;
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name == Tokens::AUTO_64))
	{
		if (!(pos->name == Tokens::AUTO_65))
		{
			if (!(pos->name == Tokens::AUTO_66))
			{
				return {};
			}
			else 
			{
				_8 = *pos;
				success_9 = true;
				pos++;
				_2 = _8;
			}
		}
		else 
		{
			_6 = *pos;
			success_7 = true;
			pos++;
			_2 = _6;
		}
	}
	else 
	{
		_4 = *pos;
		success_5 = true;
		pos++;
		_2 = _4;
	}
	success_3 = true;
	spacemode_data data = _0;
	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::spacemode, data)};
}
Parser::Rule_res Parser::Parser::name(::Parser::arr_t<Token>::iterator pos) {
	auto in = pos;
	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	::Parser::Token _2;
	::Parser::bool_t success_3 = false;
	if (!(pos->name == Tokens::AUTO_67))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos++;
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name == Tokens::ID))
	{
		return {};
	}
	_2 = *pos;
	success_3 = true;
	pos++;
	name_data data = _2;
	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::name, data)};
}
Parser::Rule_res Parser::Parser::main(::Parser::arr_t<Token>::iterator pos) {
	auto in = pos;
	::Parser::any_t _0;
	::Parser::bool_t success_1 = false;
	::Parser::Token _2;
	::Parser::bool_t success_3 = false;
	::Parser::Rule_res _4;
	::Parser::bool_t success_5 = false;
	::Parser::Rule_res _6;
	::Parser::bool_t success_7 = false;
	::Parser::Rule_res _8;
	::Parser::bool_t success_9 = false;
	if (!(pos->name == Tokens::AUTO_73))
	{
		_4 = spacemode(pos);
		if (!(_4.result))
		{
			_6 = name(pos);
			if (!(_6.result))
			{
				_8 = use(pos);
				if (!(_8.result))
				{
					return {};
				}
				else 
				{
					success_9 = true;
					std::advance(pos, _8.token.length());
					_0 = _8.token;
				}
			}
			else 
			{
				success_7 = true;
				std::advance(pos, _6.token.length());
				_0 = _6.token;
			}
		}
		else 
		{
			success_5 = true;
			std::advance(pos, _4.token.length());
			_0 = _4.token;
		}
	}
	else 
	{
		_2 = *pos;
		success_3 = true;
		std::advance(pos, 1);
		_0 = _2;
	}
	success_1 = true;
	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::main)};
}
Parser::Rule_res Parser::Parser::use_unit(::Parser::arr_t<Token>::iterator pos) {
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
	pos++;
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	_2 = any_data(pos);
	if (_2.result)
	{
		success_3 = true;
		std::advance(pos, _2.token.length());
	}
	use_unit_data data;
	data.value = _2.token;
	data.name = _0;

	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::use_unit, data)};
}
Parser::Rule_res Parser::Parser::use(::Parser::arr_t<Token>::iterator pos) {
	auto in = pos;
	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	::Parser::Rule_res _2;
	::Parser::bool_t success_3 = false;
	::Parser::bool_t success_5 = false;
	::Parser::Token _6;
	::Parser::bool_t success_7 = false;
	::Parser::arr_t<::Parser::Token> shadow_8;
	::Parser::Rule_res _9;
	::Parser::bool_t success_10 = false;
	::Parser::arr_t<::Parser::Rule> shadow_11;
	if (!(pos->name == Tokens::AUTO_68))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos++;
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	_2 = use_unit(pos);
	if (!(_2.result))
	{
		return {};
	}
	success_3 = true;
	std::advance(pos, _2.token.length());
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	auto begin_12 = pos;
	while (1)
	{
		if (!(begin_12->name == Tokens::AUTO_69))
		{
			break;
		}
		_6 = *begin_12;
		success_7 = true;
		begin_12++;
		shadow_8.push_back(_6);
		ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
		_9 = use_unit(begin_12);
		if (!(_9.result))
		{
			break;
		}
		success_10 = true;
		std::advance(begin_12, _9.token.length());
		shadow_11.push_back(_9.token);
	}
	if (success_7 && success_10)
	{
		success_5 = true;
		pos = begin_12;
	}
	use_data data;
	data.second = shadow_11;
	data.first = _2.token;

	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::use, data)};
}
Parser::Rule_res Parser::Parser::Rule_rule(::Parser::arr_t<Token>::iterator pos) {
	auto in = pos;
	::Parser::any_t _0;
	::Parser::bool_t success_1 = false;
	::Parser::Rule_res _2;
	::Parser::bool_t success_3 = false;
	::Parser::Token _4;
	::Parser::bool_t success_5 = false;
	::Parser::Token _6;
	::Parser::bool_t success_7 = false;
	::Parser::Token _8;
	::Parser::bool_t success_9 = false;
	::Parser::Rule_res _10;
	::Parser::bool_t success_11 = false;
	::Parser::bool_t success_13 = false;
	::Parser::any_t _14;
	::Parser::bool_t success_15 = false;
	::Parser::any_t _16;
	::Parser::bool_t success_17 = false;
	::Parser::Rule_res _18;
	::Parser::bool_t success_19 = false;
	::Parser::Rule_res _20;
	::Parser::bool_t success_21 = false;
	::Parser::Token _22;
	::Parser::bool_t success_23 = false;
	::Parser::Rule_res _24;
	::Parser::bool_t success_25 = false;
	::Parser::Rule_res _26;
	::Parser::bool_t success_27 = false;
	::Parser::Rule_res _28;
	::Parser::bool_t success_29 = false;
	::Parser::Rule_res _30;
	::Parser::bool_t success_31 = false;
	::Parser::Rule_res _33;
	::Parser::bool_t success_34 = false;
	_2 = Rule_escaped(pos);
	if (!(_2.result))
	{
		if (!(pos->name == Tokens::LINEAR_COMMENT))
		{
			if (!(pos->name == Tokens::AUTO_89))
			{
				if (!(pos->name == Tokens::AUTO_73))
				{
					_10 = cll(pos);
					if (!(_10.result))
					{
						auto begin_35 = pos;
						do
						{
							auto begin_32 = begin_35;
							_18 = expr_group(begin_32);
							if (!(_18.result))
							{
								_20 = Rule_csequence(begin_32);
								if (!(_20.result))
								{
									if (!(begin_32->name == Tokens::STRING))
									{
										_24 = accessor(begin_32);
										if (!(_24.result))
										{
											_26 = Rule_hex(begin_32);
											if (!(_26.result))
											{
												_28 = Rule_bin(begin_32);
												if (!(_28.result))
												{
													_30 = Rule_other(begin_32);
													if (!(_30.result))
													{
														break;
													}
													else 
													{
														success_31 = true;
														std::advance(begin_32, _30.token.length());
														_16 = _30.token;
													}
												}
												else 
												{
													success_29 = true;
													std::advance(begin_32, _28.token.length());
													_16 = _28.token;
												}
											}
											else 
											{
												success_27 = true;
												std::advance(begin_32, _26.token.length());
												_16 = _26.token;
											}
										}
										else 
										{
											success_25 = true;
											std::advance(begin_32, _24.token.length());
											_16 = _24.token;
										}
									}
									else 
									{
										_22 = *begin_32;
										success_23 = true;
										std::advance(begin_32, 1);
										_16 = _22;
									}
								}
								else 
								{
									success_21 = true;
									std::advance(begin_32, _20.token.length());
									_16 = _20.token;
								}
							}
							else 
							{
								success_19 = true;
								std::advance(begin_32, _18.token.length());
								_16 = _18.token;
							}
							success_17 = true;
							if (success_17)
							{
								success_15 = true;
								begin_35 = begin_32;
							}
							ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
							_33 = Rule_qualifier(begin_35);
							if (_33.result)
							{
								success_34 = true;
								std::advance(begin_35, _33.token.length());
							}
						}
						while(0)
;
						if (success_15)
						{
							success_13 = true;
							pos = begin_35;
						}
						;
						if (!success_13)
						{
							return {};
						}
					}
					else 
					{
						success_11 = true;
						std::advance(pos, _10.token.length());
						_0 = _10.token;
					}
				}
				else 
				{
					_8 = *pos;
					success_9 = true;
					std::advance(pos, 1);
					_0 = _8;
				}
			}
			else 
			{
				_6 = *pos;
				success_7 = true;
				std::advance(pos, 1);
				_0 = _6;
			}
		}
		else 
		{
			_4 = *pos;
			success_5 = true;
			std::advance(pos, 1);
			_0 = _4;
		}
	}
	else 
	{
		success_3 = true;
		std::advance(pos, _2.token.length());
		_0 = _2.token;
	}
	success_1 = true;
	Rule_rule_data data;
	data.qualifier = _14;
	data.val = _16;

	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::Rule_rule, data)};
}
Parser::Rule_res Parser::Parser::Rule_other(::Parser::arr_t<Token>::iterator pos) {
	auto in = pos;
	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	::Parser::Token _2;
	::Parser::bool_t success_3 = false;
	::Parser::bool_t success_5 = false;
	::Parser::Token _6;
	::Parser::bool_t success_7 = false;
	::Parser::arr_t<::Parser::Token> shadow_8;
	::Parser::Token _9;
	::Parser::bool_t success_10 = false;
	::Parser::arr_t<::Parser::Token> shadow_11;
	if (pos->name == Tokens::AUTO_99)
	{
		_0 = *pos;
		success_1 = true;
		pos++;
	}
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name == Tokens::ID))
	{
		return {};
	}
	_2 = *pos;
	success_3 = true;
	pos++;
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	auto begin_12 = pos;
	while (1)
	{
		if (!(begin_12->name == Tokens::AUTO_89))
		{
			break;
		}
		_6 = *begin_12;
		success_7 = true;
		begin_12++;
		shadow_8.push_back(_6);
		ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
		if (!(begin_12->name == Tokens::ID))
		{
			break;
		}
		_9 = *begin_12;
		success_10 = true;
		begin_12++;
		shadow_11.push_back(_9);
	}
	if (success_7 && success_10)
	{
		success_5 = true;
		pos = begin_12;
	}
	Rule_other_data data;
	data.nested_name = shadow_11;
	data.name = _2;
	data.is_nested = _0;

	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::Rule_other, data)};
}
Parser::Rule_res Parser::Parser::Rule_qualifier(::Parser::arr_t<Token>::iterator pos) {
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
	auto begin_10 = pos;
	if (!(begin_10->name == Tokens::AUTO_74))
	{
		if (!(begin_10->name == Tokens::AUTO_75))
		{
			if (!(begin_10->name == Tokens::AUTO_76))
			{
				return {};
			}
			else 
			{
				_8 = *begin_10;
				success_9 = true;
				begin_10++;
				_2 = _8;
			}
		}
		else 
		{
			_6 = *begin_10;
			success_7 = true;
			begin_10++;
			_2 = _6;
		}
	}
	else 
	{
		_4 = *begin_10;
		success_5 = true;
		begin_10++;
		_2 = _4;
	}
	success_3 = true;
	_0 = _2;
	if (success_3)
	{
		success_1 = true;
		pos = begin_10;
	}
	Rule_qualifier_data data = _0;
	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::Rule_qualifier, data)};
}
Parser::Rule_res Parser::Parser::Rule_group(::Parser::arr_t<Token>::iterator pos) {
	auto in = pos;
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
		if (!(begin_10->name == Tokens::AUTO_77))
		{
			break;
		}
		_2 = *begin_10;
		success_3 = true;
		begin_10++;
		ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
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
				begin_10++;
				_4 = _8;
			}
		}
		else 
		{
			success_7 = true;
			std::advance(begin_10, _6.token.length());
			_4 = _6.token;
		}
		success_5 = true;
	}
	while(0)
;
	if (success_3 && success_5)
	{
		success_1 = true;
		pos = begin_10;
	}
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name == Tokens::AUTO_78))
	{
		return {};
	}
	_11 = *pos;
	success_12 = true;
	pos++;
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	_13 = Rule_rule(pos);
	while (_13.result)
	{
		success_14 = true;
		std::advance(pos, _13.token.length());
		_13 = Rule_rule(pos);
	}
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name == Tokens::AUTO_79))
	{
		return {};
	}
	_15 = *pos;
	success_16 = true;
	pos++;
	Rule_group_data data;
	data.val = _13.token;
	data.variable = _2;

	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::Rule_group, data)};
}
Parser::Rule_res Parser::Parser::Rule_csequence_symbol(::Parser::arr_t<Token>::iterator pos) {
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
	auto begin_10 = pos;
	if (!(begin_10->name == Tokens::AUTO_83))
	{
		if (!(begin_10->name == Tokens::AUTO_84))
		{
			if (!(begin_10->name == Tokens::AUTO_96))
			{
				return {};
			}
			else 
			{
				_8 = *begin_10;
				success_9 = true;
				begin_10++;
				_2 = _8;
			}
		}
		else 
		{
			_6 = *begin_10;
			success_7 = true;
			begin_10++;
			_2 = _6;
		}
	}
	else 
	{
		_4 = *begin_10;
		success_5 = true;
		begin_10++;
		_2 = _4;
	}
	success_3 = true;
	_0 = _2;
	if (success_3)
	{
		success_1 = true;
		pos = begin_10;
	}
	Rule_csequence_symbol_data data = _0;
	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::Rule_csequence_symbol, data)};
}
Parser::Rule_res Parser::Parser::Rule_csequence_escape(::Parser::arr_t<Token>::iterator pos) {
	auto in = pos;
	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	::Parser::Token _2;
	::Parser::bool_t success_3 = false;
	::Parser::Token _4;
	::Parser::bool_t success_5 = false;
	if (!(pos->name == Tokens::AUTO_96))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos++;
	auto begin_6 = pos;
	if (!(begin_6->name == Tokens::AUTO_97))
	{
		return {};
	}
	_4 = *begin_6;
	success_5 = true;
	begin_6++;
	_2 = _4;
	if (success_5)
	{
		success_3 = true;
		pos = begin_6;
	}
	Rule_csequence_escape_data data = _2;
	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::Rule_csequence_escape, data)};
}
Parser::Rule_res Parser::Parser::Rule_csequence_diapason(::Parser::arr_t<Token>::iterator pos) {
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
	std::advance(begin_5, _3.token.length());
	from = _3.token;
	if (success_4)
	{
		success_2 = true;
		begin_12 = begin_5;
	}
	if (!(begin_12->name == Tokens::AUTO_88))
	{
		return {};
	}
	_6 = *begin_12;
	success_7 = true;
	begin_12++;
	auto begin_11 = begin_12;
	_9 = Rule_csequence_symbol(begin_11);
	if (!(_9.result))
	{
		return {};
	}
	success_10 = true;
	std::advance(begin_11, _9.token.length());
	to = _9.token;
	if (success_10)
	{
		success_8 = true;
		begin_12 = begin_11;
	}
	if (success_2 && success_7 && success_8)
	{
		success_1 = true;
		pos = begin_12;
	}
	Rule_csequence_diapason_data data = {from,to};
	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::Rule_csequence_diapason, data)};
}
Parser::Rule_res Parser::Parser::Rule_csequence(::Parser::arr_t<Token>::iterator pos) {
	auto in = pos;
	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	::Parser::Token _2;
	::Parser::bool_t success_3 = false;
	::Parser::arr_t<::Parser::arr_t<::Parser::Rule>> shadow_17;
	::Parser::arr_t<::Parser::Rule> dt;
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
	if (!(pos->name == Tokens::AUTO_80))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos++;
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	if (pos->name == Tokens::AUTO_81)
	{
		_2 = *pos;
		success_3 = true;
		pos++;
	}
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
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
					std::advance(begin_16, _13.token.length());
					shadow_15.push_back(_13.token);
					_5.push_back(_13.token);
				}
			}
			else 
			{
				success_11 = true;
				std::advance(begin_16, _10.token.length());
				shadow_12.push_back(_10.token);
				_5.push_back(_10.token);
			}
		}
		else 
		{
			success_8 = true;
			std::advance(begin_16, _7.token.length());
			shadow_9.push_back(_7.token);
			_5.push_back(_7.token);
		}
		success_6 = true;
		dt = _5;
		shadow_17.push_back(dt);
	}
	if (success_6)
	{
		success_4 = true;
		pos = begin_16;
	}
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name == Tokens::AUTO_82))
	{
		return {};
	}
	_18 = *pos;
	success_19 = true;
	pos++;
	Rule_csequence_data data;
	data.val = dt;
	data._not = _2;

	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::Rule_csequence, data)};
}
Parser::Rule_res Parser::Parser::Rule_data_block_inclosed_map(::Parser::arr_t<Token>::iterator pos) {
	auto in = pos;
	::Parser::Rule_res _0;
	::Parser::bool_t success_1 = false;
	::Parser::bool_t success_2 = false;
	_0 = Rule_data_block_key(pos);
	while (_0.result)
	{
		success_1 = true;
		std::advance(pos, _0.token.length());
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
Parser::Rule_res Parser::Parser::Rule_data_block_key(::Parser::arr_t<Token>::iterator pos) {
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
	while (pos->name == Tokens::AUTO_98)
	{
		_0 = *pos;
		success_1 = true;
		pos++;
		shadow_2.push_back(_0);
		success_3 = true;
	}
	if (!success_3)
	{
		return {};
	}
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	auto begin_7 = pos;
	if (!(begin_7->name == Tokens::ID))
	{
		return {};
	}
	_5 = *begin_7;
	success_6 = true;
	begin_7++;
	name = _5;
	if (success_6)
	{
		success_4 = true;
		pos = begin_7;
	}
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name == Tokens::AUTO_95))
	{
		return {};
	}
	_8 = *pos;
	success_9 = true;
	pos++;
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
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
			std::advance(begin_17, _15.token.length());
			_11 = _15.token;
		}
	}
	else 
	{
		success_14 = true;
		std::advance(begin_17, _13.token.length());
		_11 = _13.token;
	}
	success_12 = true;
	dt = _11;
	if (success_12)
	{
		success_10 = true;
		pos = begin_17;
	}
	Rule_data_block_key_data data;
	data.val = dt;
	data.name = name;

	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::Rule_data_block_key, data)};
}
Parser::Rule_res Parser::Parser::Rule_data_block(::Parser::arr_t<Token>::iterator pos) {
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
	while (pos->name == Tokens::AUTO_98)
	{
		_0 = *pos;
		success_1 = true;
		pos++;
		shadow_2.push_back(_0);
		success_3 = true;
	}
	if (!success_3)
	{
		return {};
	}
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name == Tokens::AUTO_91))
	{
		return {};
	}
	_4 = *pos;
	success_5 = true;
	pos++;
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name == Tokens::AUTO_95))
	{
		return {};
	}
	_6 = *pos;
	success_7 = true;
	pos++;
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
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
			std::advance(pos, _12.token.length());
			_8 = _12.token;
		}
	}
	else 
	{
		success_11 = true;
		std::advance(pos, _10.token.length());
		_8 = _10.token;
	}
	success_9 = true;
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name == Tokens::AUTO_93))
	{
		return {};
	}
	_14 = *pos;
	success_15 = true;
	pos++;
	Rule_data_block_data data = _8;
	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::Rule_data_block, data)};
}
Parser::Rule_res Parser::Parser::Rule_escaped(::Parser::arr_t<Token>::iterator pos) {
	auto in = pos;
	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	::Parser::Token _2;
	::Parser::bool_t success_3 = false;
	::Parser::Token _4;
	::Parser::bool_t success_5 = false;
	::Parser::Token _7;
	::Parser::bool_t success_8 = false;
	if (!(pos->name == Tokens::AUTO_96))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos++;
	auto begin_6 = pos;
	if (!(begin_6->name == Tokens::AUTO_97))
	{
		return {};
	}
	_4 = *begin_6;
	success_5 = true;
	begin_6++;
	_2 = _4;
	if (success_5)
	{
		success_3 = true;
		pos = begin_6;
	}
	if (pos->name == Tokens::NUMBER)
	{
		_7 = *pos;
		success_8 = true;
		pos++;
	}
	Rule_escaped_data data;
	data.num = _2;
	data.c = _2;

	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::Rule_escaped, data)};
}
Parser::Rule_res Parser::Parser::Rule_nested_rule(::Parser::arr_t<Token>::iterator pos) {
	auto in = pos;
	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	::Parser::arr_t<::Parser::Token> shadow_2;
	::Parser::bool_t success_3 = false;
	::Parser::Token _4;
	::Parser::bool_t success_5 = false;
	::Parser::Token _6;
	::Parser::bool_t success_7 = false;
	::Parser::Token _8;
	::Parser::bool_t success_9 = false;
	while (pos->name == Tokens::AUTO_98)
	{
		_0 = *pos;
		success_1 = true;
		pos++;
		shadow_2.push_back(_0);
		success_3 = true;
	}
	if (!success_3)
	{
		return {};
	}
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name == Tokens::AUTO_99))
	{
		return {};
	}
	_4 = *pos;
	success_5 = true;
	pos++;
	auto begin_10 = pos;
	if (!(begin_10->name == Tokens::AUTO_73))
	{
		return {};
	}
	_8 = *begin_10;
	success_9 = true;
	begin_10++;
	_6 = _8;
	if (success_9)
	{
		success_7 = true;
		pos = begin_10;
	}
	Rule_nested_rule_data data = _6;
	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::Rule_nested_rule, data)};
}
Parser::Rule_res Parser::Parser::Rule_hex(::Parser::arr_t<Token>::iterator pos) {
	auto in = pos;
	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	::Parser::Token _2;
	::Parser::bool_t success_3 = false;
	::Parser::arr_t<::Parser::Token> shadow_4;
	::Parser::bool_t success_5 = false;
	if (!(pos->name == Tokens::AUTO_100))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos++;
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	while (pos->name == Tokens::AUTO_101)
	{
		_2 = *pos;
		success_3 = true;
		pos++;
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
Parser::Rule_res Parser::Parser::Rule_bin(::Parser::arr_t<Token>::iterator pos) {
	auto in = pos;
	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	::Parser::Token _2;
	::Parser::bool_t success_3 = false;
	::Parser::arr_t<::Parser::Token> shadow_4;
	::Parser::bool_t success_5 = false;
	if (!(pos->name == Tokens::AUTO_102))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos++;
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	while (pos->name == Tokens::AUTO_103)
	{
		_2 = *pos;
		success_3 = true;
		pos++;
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
Parser::Rule_res Parser::Parser::Rule(::Parser::arr_t<Token>::iterator pos) {
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
	pos++;
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name == Tokens::AUTO_95))
	{
		return {};
	}
	_2 = *pos;
	success_3 = true;
	pos++;
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	_4 = Rule_rule(pos);
	while (_4.result)
	{
		success_5 = true;
		std::advance(pos, _4.token.length());
		_4 = Rule_rule(pos);
	}
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	_6 = Rule_data_block(pos);
	if (!(_6.result))
	{
		return {};
	}
	success_7 = true;
	std::advance(pos, _6.token.length());
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	_8 = Rule_nested_rule(pos);
	while (_8.result)
	{
		success_9 = true;
		std::advance(pos, _8.token.length());
		_8 = Rule_nested_rule(pos);
	}
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name == Tokens::AUTO_93))
	{
		return {};
	}
	_10 = *pos;
	success_11 = true;
	pos++;
	Rule_data data;
	data.nestedRules = _8.token;
	data.data_block = _6.token;
	data.rule = _4.token;
	data.name = _0;

	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::Rule, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_1(const char* pos) {
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
	AUTO_1_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_1, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_3(const char* pos) {
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
	AUTO_3_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_3, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_4(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == '$'))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 1);
	success_1 = true;
	pos += 1;
	AUTO_4_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_4, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_8(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!std::strncmp(pos + 0, "unsigned", 8)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 8);
	success_1 = true;
	pos += 8;
	AUTO_8_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_8, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_9(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!std::strncmp(pos + 0, "char", 4)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 4);
	success_1 = true;
	pos += 4;
	AUTO_9_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_9, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_10(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!std::strncmp(pos + 0, "short", 5)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 5);
	success_1 = true;
	pos += 5;
	AUTO_10_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_10, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_11(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!std::strncmp(pos + 0, "int", 3)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 3);
	success_1 = true;
	pos += 3;
	AUTO_11_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_11, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_15(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!std::strncmp(pos + 0, "float", 5)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 5);
	success_1 = true;
	pos += 5;
	AUTO_15_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_15, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_17(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!std::strncmp(pos + 0, "long", 4)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 4);
	success_1 = true;
	pos += 4;
	AUTO_17_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_17, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_18(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!std::strncmp(pos + 0, "double", 6)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 6);
	success_1 = true;
	pos += 6;
	AUTO_18_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_18, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_19(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!std::strncmp(pos + 0, "bool", 4)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 4);
	success_1 = true;
	pos += 4;
	AUTO_19_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_19, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_20(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!std::strncmp(pos + 0, "var", 3)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 3);
	success_1 = true;
	pos += 3;
	AUTO_20_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_20, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_21(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!std::strncmp(pos + 0, "any", 3)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 3);
	success_1 = true;
	pos += 3;
	AUTO_21_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_21, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_22(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!std::strncmp(pos + 0, "num", 3)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 3);
	success_1 = true;
	pos += 3;
	AUTO_22_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_22, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_23(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!std::strncmp(pos + 0, "str", 3)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 3);
	success_1 = true;
	pos += 3;
	AUTO_23_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_23, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_24(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!std::strncmp(pos + 0, "arr", 3)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 3);
	success_1 = true;
	pos += 3;
	AUTO_24_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_24, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_25(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!std::strncmp(pos + 0, "obj", 3)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 3);
	success_1 = true;
	pos += 3;
	AUTO_25_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_25, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_26(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!std::strncmp(pos + 0, "if", 2)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 2);
	success_1 = true;
	pos += 2;
	AUTO_26_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_26, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_39(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!std::strncmp(pos + 0, "fn", 2)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 2);
	success_1 = true;
	pos += 2;
	AUTO_39_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_39, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_40(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!std::strncmp(pos + 0, "while", 5)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 5);
	success_1 = true;
	pos += 5;
	AUTO_40_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_40, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_41(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!std::strncmp(pos + 0, "for", 3)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 3);
	success_1 = true;
	pos += 3;
	AUTO_41_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_41, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_47(const char* pos) {
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
	AUTO_47_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_47, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_52(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!std::strncmp(pos + 0, "++", 2)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 2);
	success_1 = true;
	pos += 2;
	AUTO_52_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_52, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_53(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!std::strncmp(pos + 0, "--", 2)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 2);
	success_1 = true;
	pos += 2;
	AUTO_53_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_53, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_57(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == '{'))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 1);
	success_1 = true;
	pos += 1;
	AUTO_57_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_57, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_62(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == '}'))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 1);
	success_1 = true;
	pos += 1;
	AUTO_62_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_62, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_63(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!std::strncmp(pos + 0, "spacemode", 9)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 9);
	success_1 = true;
	pos += 9;
	AUTO_63_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_63, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_64(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!std::strncmp(pos + 0, "skipped", 7)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 7);
	success_1 = true;
	pos += 7;
	AUTO_64_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_64, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_65(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!std::strncmp(pos + 0, "allowed", 7)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 7);
	success_1 = true;
	pos += 7;
	AUTO_65_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_65, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_66(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!std::strncmp(pos + 0, "mixed", 5)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 5);
	success_1 = true;
	pos += 5;
	AUTO_66_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_66, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_67(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!std::strncmp(pos + 0, "name", 4)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 4);
	success_1 = true;
	pos += 4;
	AUTO_67_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_67, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_68(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!std::strncmp(pos + 0, "use", 3)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 3);
	success_1 = true;
	pos += 3;
	AUTO_68_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_68, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_69(const char* pos) {
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
	AUTO_69_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_69, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_73(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == '|'))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 1);
	success_1 = true;
	pos += 1;
	AUTO_73_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_73, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_74(const char* pos) {
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
	AUTO_74_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_74, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_75(const char* pos) {
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
	AUTO_75_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_75, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_76(const char* pos) {
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
	AUTO_76_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_76, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_77(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == '&'))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 1);
	success_1 = true;
	pos += 1;
	AUTO_77_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_77, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_78(const char* pos) {
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
	AUTO_78_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_78, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_79(const char* pos) {
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
	AUTO_79_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_79, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_80(const char* pos) {
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
	AUTO_80_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_80, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_81(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == '^'))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 1);
	success_1 = true;
	pos += 1;
	AUTO_81_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_81, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_82(const char* pos) {
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
	AUTO_82_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_82, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_83(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!(*(pos + 0) == ']' || *(pos + 0) == '\0')))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 1);
	success_1 = true;
	pos += 1;
	AUTO_83_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_83, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_84(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!std::strncmp(pos + 0, "\\]", 2)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 2);
	success_1 = true;
	pos += 2;
	AUTO_84_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_84, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_88(const char* pos) {
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
	AUTO_88_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_88, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_89(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == '.'))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 1);
	success_1 = true;
	pos += 1;
	AUTO_89_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_89, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_91(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!std::strncmp(pos + 0, "data", 4)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 4);
	success_1 = true;
	pos += 4;
	AUTO_91_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_91, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_93(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == ';'))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 1);
	success_1 = true;
	pos += 1;
	AUTO_93_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_93, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_95(const char* pos) {
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
	AUTO_95_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_95, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_96(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!std::strncmp(pos + 0, "\\", 1)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 1);
	success_1 = true;
	pos += 1;
	AUTO_96_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_96, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_97(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (*(pos + 0) == '\0')
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 1);
	success_1 = true;
	pos += 1;
	AUTO_97_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_97, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_98(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == '\r' || *(pos + 0) == '\n'))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 1);
	success_1 = true;
	pos += 1;
	AUTO_98_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_98, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_99(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == '#'))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 1);
	success_1 = true;
	pos += 1;
	AUTO_99_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_99, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_100(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!std::strncmp(pos + 0, "0x", 2)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 2);
	success_1 = true;
	pos += 2;
	AUTO_100_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_100, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_101(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!((*(pos + 0)>='1' && *(pos + 0)<='9') || (*(pos + 0)>='A' && *(pos + 0)<='F') || (*(pos + 0)>='a' && *(pos + 0)<='f')))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 1);
	success_1 = true;
	pos += 1;
	AUTO_101_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_101, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_102(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!std::strncmp(pos + 0, "0b", 2)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 2);
	success_1 = true;
	pos += 2;
	AUTO_102_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_102, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_103(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == '0' || *(pos + 0) == '1'))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 1);
	success_1 = true;
	pos += 1;
	AUTO_103_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_103, data)};
}
Parser::Token_res Parser::Tokenizator::__WHITESPACE(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	while (*(pos + 0) == ' ' || *(pos + 0) == '\t' || *(pos + 0) == '\n' || *(pos + 0) == '\r' || *(pos + 0) == '\v' || *(pos + 0) == '\f')
	{
		_0 += ::Parser::str_t(pos, 1);
		success_1 = true;
		pos += 1;
	}
	return {true, ::Parser::Token(in - str, in, pos, Tokens::__WHITESPACE)};
}
