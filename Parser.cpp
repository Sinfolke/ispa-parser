#include "Parser.h"

void Parser::Tokenizator::makeTokens(const char* pos) {
	this->str = pos;
	::Parser::arr_t<::Parser::arr_t<::Parser::Token>> shadow_233;
	::Parser::arr_t<::Parser::Token> _0;
	::Parser::bool_t success_1 = false;
	::Parser::bool_t success_234 = false;
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
	::Parser::Token_res _202;
	::Parser::bool_t success_203 = false;
	::Parser::arr_t<::Parser::Token> shadow_204;
	::Parser::Token_res _205;
	::Parser::bool_t success_206 = false;
	::Parser::arr_t<::Parser::Token> shadow_207;
	::Parser::Token_res _208;
	::Parser::bool_t success_209 = false;
	::Parser::arr_t<::Parser::Token> shadow_210;
	::Parser::Token_res _211;
	::Parser::bool_t success_212 = false;
	::Parser::arr_t<::Parser::Token> shadow_213;
	::Parser::Token_res _214;
	::Parser::bool_t success_215 = false;
	::Parser::arr_t<::Parser::Token> shadow_216;
	::Parser::Token_res _217;
	::Parser::bool_t success_218 = false;
	::Parser::arr_t<::Parser::Token> shadow_219;
	::Parser::Token_res _220;
	::Parser::bool_t success_221 = false;
	::Parser::arr_t<::Parser::Token> shadow_222;
	::Parser::Token_res _223;
	::Parser::bool_t success_224 = false;
	::Parser::arr_t<::Parser::Token> shadow_225;
	::Parser::Token_res _226;
	::Parser::bool_t success_227 = false;
	::Parser::arr_t<::Parser::Token> shadow_228;
	::Parser::Token_res _229;
	::Parser::bool_t success_230 = false;
	::Parser::arr_t<::Parser::Token> shadow_231;
	auto begin_232 = pos;
	while (1)
	{
		if (*(begin_232 + 0) == '\0')
		{
			break;
		}
		_4 = OP(begin_232);
		if (!(_4.result))
		{
			_7 = ASSIGNMENT_OP(begin_232);
			if (!(_7.result))
			{
				_10 = COMPARE_OP(begin_232);
				if (!(_10.result))
				{
					_13 = LOGICAL_OP(begin_232);
					if (!(_13.result))
					{
						_16 = STRING(begin_232);
						if (!(_16.result))
						{
							_19 = NUMBER(begin_232);
							if (!(_19.result))
							{
								_22 = BOOLEAN(begin_232);
								if (!(_22.result))
								{
									_25 = ID(begin_232);
									if (!(_25.result))
									{
										_28 = AUTO_1(begin_232);
										if (!(_28.result))
										{
											_31 = AUTO_3(begin_232);
											if (!(_31.result))
											{
												_34 = AUTO_4(begin_232);
												if (!(_34.result))
												{
													_37 = AUTO_8(begin_232);
													if (!(_37.result))
													{
														_40 = AUTO_9(begin_232);
														if (!(_40.result))
														{
															_43 = AUTO_10(begin_232);
															if (!(_43.result))
															{
																_46 = AUTO_11(begin_232);
																if (!(_46.result))
																{
																	_49 = AUTO_12(begin_232);
																	if (!(_49.result))
																	{
																		_52 = AUTO_13(begin_232);
																		if (!(_52.result))
																		{
																			_55 = AUTO_14(begin_232);
																			if (!(_55.result))
																			{
																				_58 = AUTO_15(begin_232);
																				if (!(_58.result))
																				{
																					_61 = AUTO_16(begin_232);
																					if (!(_61.result))
																					{
																						_64 = AUTO_17(begin_232);
																						if (!(_64.result))
																						{
																							_67 = AUTO_18(begin_232);
																							if (!(_67.result))
																							{
																								_70 = AUTO_19(begin_232);
																								if (!(_70.result))
																								{
																									_73 = AUTO_20(begin_232);
																									if (!(_73.result))
																									{
																										_76 = AUTO_21(begin_232);
																										if (!(_76.result))
																										{
																											_79 = AUTO_22(begin_232);
																											if (!(_79.result))
																											{
																												_82 = AUTO_23(begin_232);
																												if (!(_82.result))
																												{
																													_85 = AUTO_24(begin_232);
																													if (!(_85.result))
																													{
																														_88 = AUTO_25(begin_232);
																														if (!(_88.result))
																														{
																															_91 = AUTO_26(begin_232);
																															if (!(_91.result))
																															{
																																_94 = AUTO_27(begin_232);
																																if (!(_94.result))
																																{
																																	_97 = AUTO_28(begin_232);
																																	if (!(_97.result))
																																	{
																																		_100 = AUTO_29(begin_232);
																																		if (!(_100.result))
																																		{
																																			_103 = AUTO_42(begin_232);
																																			if (!(_103.result))
																																			{
																																				_106 = AUTO_43(begin_232);
																																				if (!(_106.result))
																																				{
																																					_109 = AUTO_44(begin_232);
																																					if (!(_109.result))
																																					{
																																						_112 = AUTO_50(begin_232);
																																						if (!(_112.result))
																																						{
																																							_115 = AUTO_55(begin_232);
																																							if (!(_115.result))
																																							{
																																								_118 = AUTO_56(begin_232);
																																								if (!(_118.result))
																																								{
																																									_121 = AUTO_60(begin_232);
																																									if (!(_121.result))
																																									{
																																										_124 = AUTO_65(begin_232);
																																										if (!(_124.result))
																																										{
																																											_127 = AUTO_66(begin_232);
																																											if (!(_127.result))
																																											{
																																												_130 = AUTO_67(begin_232);
																																												if (!(_130.result))
																																												{
																																													_133 = AUTO_68(begin_232);
																																													if (!(_133.result))
																																													{
																																														_136 = AUTO_69(begin_232);
																																														if (!(_136.result))
																																														{
																																															_139 = AUTO_70(begin_232);
																																															if (!(_139.result))
																																															{
																																																_142 = AUTO_71(begin_232);
																																																if (!(_142.result))
																																																{
																																																	_145 = AUTO_72(begin_232);
																																																	if (!(_145.result))
																																																	{
																																																		_148 = AUTO_73(begin_232);
																																																		if (!(_148.result))
																																																		{
																																																			_151 = AUTO_74(begin_232);
																																																			if (!(_151.result))
																																																			{
																																																				_154 = AUTO_78(begin_232);
																																																				if (!(_154.result))
																																																				{
																																																					_157 = AUTO_79(begin_232);
																																																					if (!(_157.result))
																																																					{
																																																						_160 = AUTO_80(begin_232);
																																																						if (!(_160.result))
																																																						{
																																																							_163 = AUTO_81(begin_232);
																																																							if (!(_163.result))
																																																							{
																																																								_166 = AUTO_82(begin_232);
																																																								if (!(_166.result))
																																																								{
																																																									_169 = AUTO_83(begin_232);
																																																									if (!(_169.result))
																																																									{
																																																										_172 = AUTO_84(begin_232);
																																																										if (!(_172.result))
																																																										{
																																																											_175 = AUTO_85(begin_232);
																																																											if (!(_175.result))
																																																											{
																																																												_178 = AUTO_86(begin_232);
																																																												if (!(_178.result))
																																																												{
																																																													_181 = AUTO_87(begin_232);
																																																													if (!(_181.result))
																																																													{
																																																														_184 = AUTO_88(begin_232);
																																																														if (!(_184.result))
																																																														{
																																																															_187 = AUTO_90(begin_232);
																																																															if (!(_187.result))
																																																															{
																																																																_190 = AUTO_91(begin_232);
																																																																if (!(_190.result))
																																																																{
																																																																	_193 = AUTO_94(begin_232);
																																																																	if (!(_193.result))
																																																																	{
																																																																		_196 = AUTO_95(begin_232);
																																																																		if (!(_196.result))
																																																																		{
																																																																			_199 = AUTO_97(begin_232);
																																																																			if (!(_199.result))
																																																																			{
																																																																				_202 = AUTO_99(begin_232);
																																																																				if (!(_202.result))
																																																																				{
																																																																					_205 = AUTO_101(begin_232);
																																																																					if (!(_205.result))
																																																																					{
																																																																						_208 = AUTO_102(begin_232);
																																																																						if (!(_208.result))
																																																																						{
																																																																							_211 = AUTO_103(begin_232);
																																																																							if (!(_211.result))
																																																																							{
																																																																								_214 = AUTO_104(begin_232);
																																																																								if (!(_214.result))
																																																																								{
																																																																									_217 = AUTO_105(begin_232);
																																																																									if (!(_217.result))
																																																																									{
																																																																										_220 = AUTO_106(begin_232);
																																																																										if (!(_220.result))
																																																																										{
																																																																											_223 = AUTO_107(begin_232);
																																																																											if (!(_223.result))
																																																																											{
																																																																												_226 = AUTO_108(begin_232);
																																																																												if (!(_226.result))
																																																																												{
																																																																													_229 = AUTO_109(begin_232);
																																																																													if (!(_229.result))
																																																																													{
																																																																														break;
																																																																													}
																																																																													else 
																																																																													{
																																																																														success_230 = true;
																																																																														begin_232 += _229.token.length();
																																																																														shadow_231.push_back(_229.token);
																																																																														_2.push_back(_229.token);
																																																																													}
																																																																													ISC_STD::skip_spaces(pos);
																																																																												}
																																																																												else 
																																																																												{
																																																																													success_227 = true;
																																																																													begin_232 += _226.token.length();
																																																																													shadow_228.push_back(_226.token);
																																																																													_2.push_back(_226.token);
																																																																												}
																																																																												ISC_STD::skip_spaces(pos);
																																																																											}
																																																																											else 
																																																																											{
																																																																												success_224 = true;
																																																																												begin_232 += _223.token.length();
																																																																												shadow_225.push_back(_223.token);
																																																																												_2.push_back(_223.token);
																																																																											}
																																																																											ISC_STD::skip_spaces(pos);
																																																																										}
																																																																										else 
																																																																										{
																																																																											success_221 = true;
																																																																											begin_232 += _220.token.length();
																																																																											shadow_222.push_back(_220.token);
																																																																											_2.push_back(_220.token);
																																																																										}
																																																																										ISC_STD::skip_spaces(pos);
																																																																									}
																																																																									else 
																																																																									{
																																																																										success_218 = true;
																																																																										begin_232 += _217.token.length();
																																																																										shadow_219.push_back(_217.token);
																																																																										_2.push_back(_217.token);
																																																																									}
																																																																									ISC_STD::skip_spaces(pos);
																																																																								}
																																																																								else 
																																																																								{
																																																																									success_215 = true;
																																																																									begin_232 += _214.token.length();
																																																																									shadow_216.push_back(_214.token);
																																																																									_2.push_back(_214.token);
																																																																								}
																																																																								ISC_STD::skip_spaces(pos);
																																																																							}
																																																																							else 
																																																																							{
																																																																								success_212 = true;
																																																																								begin_232 += _211.token.length();
																																																																								shadow_213.push_back(_211.token);
																																																																								_2.push_back(_211.token);
																																																																							}
																																																																							ISC_STD::skip_spaces(pos);
																																																																						}
																																																																						else 
																																																																						{
																																																																							success_209 = true;
																																																																							begin_232 += _208.token.length();
																																																																							shadow_210.push_back(_208.token);
																																																																							_2.push_back(_208.token);
																																																																						}
																																																																						ISC_STD::skip_spaces(pos);
																																																																					}
																																																																					else 
																																																																					{
																																																																						success_206 = true;
																																																																						begin_232 += _205.token.length();
																																																																						shadow_207.push_back(_205.token);
																																																																						_2.push_back(_205.token);
																																																																					}
																																																																					ISC_STD::skip_spaces(pos);
																																																																				}
																																																																				else 
																																																																				{
																																																																					success_203 = true;
																																																																					begin_232 += _202.token.length();
																																																																					shadow_204.push_back(_202.token);
																																																																					_2.push_back(_202.token);
																																																																				}
																																																																				ISC_STD::skip_spaces(pos);
																																																																			}
																																																																			else 
																																																																			{
																																																																				success_200 = true;
																																																																				begin_232 += _199.token.length();
																																																																				shadow_201.push_back(_199.token);
																																																																				_2.push_back(_199.token);
																																																																			}
																																																																			ISC_STD::skip_spaces(pos);
																																																																		}
																																																																		else 
																																																																		{
																																																																			success_197 = true;
																																																																			begin_232 += _196.token.length();
																																																																			shadow_198.push_back(_196.token);
																																																																			_2.push_back(_196.token);
																																																																		}
																																																																		ISC_STD::skip_spaces(pos);
																																																																	}
																																																																	else 
																																																																	{
																																																																		success_194 = true;
																																																																		begin_232 += _193.token.length();
																																																																		shadow_195.push_back(_193.token);
																																																																		_2.push_back(_193.token);
																																																																	}
																																																																	ISC_STD::skip_spaces(pos);
																																																																}
																																																																else 
																																																																{
																																																																	success_191 = true;
																																																																	begin_232 += _190.token.length();
																																																																	shadow_192.push_back(_190.token);
																																																																	_2.push_back(_190.token);
																																																																}
																																																																ISC_STD::skip_spaces(pos);
																																																															}
																																																															else 
																																																															{
																																																																success_188 = true;
																																																																begin_232 += _187.token.length();
																																																																shadow_189.push_back(_187.token);
																																																																_2.push_back(_187.token);
																																																															}
																																																															ISC_STD::skip_spaces(pos);
																																																														}
																																																														else 
																																																														{
																																																															success_185 = true;
																																																															begin_232 += _184.token.length();
																																																															shadow_186.push_back(_184.token);
																																																															_2.push_back(_184.token);
																																																														}
																																																														ISC_STD::skip_spaces(pos);
																																																													}
																																																													else 
																																																													{
																																																														success_182 = true;
																																																														begin_232 += _181.token.length();
																																																														shadow_183.push_back(_181.token);
																																																														_2.push_back(_181.token);
																																																													}
																																																													ISC_STD::skip_spaces(pos);
																																																												}
																																																												else 
																																																												{
																																																													success_179 = true;
																																																													begin_232 += _178.token.length();
																																																													shadow_180.push_back(_178.token);
																																																													_2.push_back(_178.token);
																																																												}
																																																												ISC_STD::skip_spaces(pos);
																																																											}
																																																											else 
																																																											{
																																																												success_176 = true;
																																																												begin_232 += _175.token.length();
																																																												shadow_177.push_back(_175.token);
																																																												_2.push_back(_175.token);
																																																											}
																																																											ISC_STD::skip_spaces(pos);
																																																										}
																																																										else 
																																																										{
																																																											success_173 = true;
																																																											begin_232 += _172.token.length();
																																																											shadow_174.push_back(_172.token);
																																																											_2.push_back(_172.token);
																																																										}
																																																										ISC_STD::skip_spaces(pos);
																																																									}
																																																									else 
																																																									{
																																																										success_170 = true;
																																																										begin_232 += _169.token.length();
																																																										shadow_171.push_back(_169.token);
																																																										_2.push_back(_169.token);
																																																									}
																																																									ISC_STD::skip_spaces(pos);
																																																								}
																																																								else 
																																																								{
																																																									success_167 = true;
																																																									begin_232 += _166.token.length();
																																																									shadow_168.push_back(_166.token);
																																																									_2.push_back(_166.token);
																																																								}
																																																								ISC_STD::skip_spaces(pos);
																																																							}
																																																							else 
																																																							{
																																																								success_164 = true;
																																																								begin_232 += _163.token.length();
																																																								shadow_165.push_back(_163.token);
																																																								_2.push_back(_163.token);
																																																							}
																																																							ISC_STD::skip_spaces(pos);
																																																						}
																																																						else 
																																																						{
																																																							success_161 = true;
																																																							begin_232 += _160.token.length();
																																																							shadow_162.push_back(_160.token);
																																																							_2.push_back(_160.token);
																																																						}
																																																						ISC_STD::skip_spaces(pos);
																																																					}
																																																					else 
																																																					{
																																																						success_158 = true;
																																																						begin_232 += _157.token.length();
																																																						shadow_159.push_back(_157.token);
																																																						_2.push_back(_157.token);
																																																					}
																																																					ISC_STD::skip_spaces(pos);
																																																				}
																																																				else 
																																																				{
																																																					success_155 = true;
																																																					begin_232 += _154.token.length();
																																																					shadow_156.push_back(_154.token);
																																																					_2.push_back(_154.token);
																																																				}
																																																				ISC_STD::skip_spaces(pos);
																																																			}
																																																			else 
																																																			{
																																																				success_152 = true;
																																																				begin_232 += _151.token.length();
																																																				shadow_153.push_back(_151.token);
																																																				_2.push_back(_151.token);
																																																			}
																																																			ISC_STD::skip_spaces(pos);
																																																		}
																																																		else 
																																																		{
																																																			success_149 = true;
																																																			begin_232 += _148.token.length();
																																																			shadow_150.push_back(_148.token);
																																																			_2.push_back(_148.token);
																																																		}
																																																		ISC_STD::skip_spaces(pos);
																																																	}
																																																	else 
																																																	{
																																																		success_146 = true;
																																																		begin_232 += _145.token.length();
																																																		shadow_147.push_back(_145.token);
																																																		_2.push_back(_145.token);
																																																	}
																																																	ISC_STD::skip_spaces(pos);
																																																}
																																																else 
																																																{
																																																	success_143 = true;
																																																	begin_232 += _142.token.length();
																																																	shadow_144.push_back(_142.token);
																																																	_2.push_back(_142.token);
																																																}
																																																ISC_STD::skip_spaces(pos);
																																															}
																																															else 
																																															{
																																																success_140 = true;
																																																begin_232 += _139.token.length();
																																																shadow_141.push_back(_139.token);
																																																_2.push_back(_139.token);
																																															}
																																															ISC_STD::skip_spaces(pos);
																																														}
																																														else 
																																														{
																																															success_137 = true;
																																															begin_232 += _136.token.length();
																																															shadow_138.push_back(_136.token);
																																															_2.push_back(_136.token);
																																														}
																																														ISC_STD::skip_spaces(pos);
																																													}
																																													else 
																																													{
																																														success_134 = true;
																																														begin_232 += _133.token.length();
																																														shadow_135.push_back(_133.token);
																																														_2.push_back(_133.token);
																																													}
																																													ISC_STD::skip_spaces(pos);
																																												}
																																												else 
																																												{
																																													success_131 = true;
																																													begin_232 += _130.token.length();
																																													shadow_132.push_back(_130.token);
																																													_2.push_back(_130.token);
																																												}
																																												ISC_STD::skip_spaces(pos);
																																											}
																																											else 
																																											{
																																												success_128 = true;
																																												begin_232 += _127.token.length();
																																												shadow_129.push_back(_127.token);
																																												_2.push_back(_127.token);
																																											}
																																											ISC_STD::skip_spaces(pos);
																																										}
																																										else 
																																										{
																																											success_125 = true;
																																											begin_232 += _124.token.length();
																																											shadow_126.push_back(_124.token);
																																											_2.push_back(_124.token);
																																										}
																																										ISC_STD::skip_spaces(pos);
																																									}
																																									else 
																																									{
																																										success_122 = true;
																																										begin_232 += _121.token.length();
																																										shadow_123.push_back(_121.token);
																																										_2.push_back(_121.token);
																																									}
																																									ISC_STD::skip_spaces(pos);
																																								}
																																								else 
																																								{
																																									success_119 = true;
																																									begin_232 += _118.token.length();
																																									shadow_120.push_back(_118.token);
																																									_2.push_back(_118.token);
																																								}
																																								ISC_STD::skip_spaces(pos);
																																							}
																																							else 
																																							{
																																								success_116 = true;
																																								begin_232 += _115.token.length();
																																								shadow_117.push_back(_115.token);
																																								_2.push_back(_115.token);
																																							}
																																							ISC_STD::skip_spaces(pos);
																																						}
																																						else 
																																						{
																																							success_113 = true;
																																							begin_232 += _112.token.length();
																																							shadow_114.push_back(_112.token);
																																							_2.push_back(_112.token);
																																						}
																																						ISC_STD::skip_spaces(pos);
																																					}
																																					else 
																																					{
																																						success_110 = true;
																																						begin_232 += _109.token.length();
																																						shadow_111.push_back(_109.token);
																																						_2.push_back(_109.token);
																																					}
																																					ISC_STD::skip_spaces(pos);
																																				}
																																				else 
																																				{
																																					success_107 = true;
																																					begin_232 += _106.token.length();
																																					shadow_108.push_back(_106.token);
																																					_2.push_back(_106.token);
																																				}
																																				ISC_STD::skip_spaces(pos);
																																			}
																																			else 
																																			{
																																				success_104 = true;
																																				begin_232 += _103.token.length();
																																				shadow_105.push_back(_103.token);
																																				_2.push_back(_103.token);
																																			}
																																			ISC_STD::skip_spaces(pos);
																																		}
																																		else 
																																		{
																																			success_101 = true;
																																			begin_232 += _100.token.length();
																																			shadow_102.push_back(_100.token);
																																			_2.push_back(_100.token);
																																		}
																																		ISC_STD::skip_spaces(pos);
																																	}
																																	else 
																																	{
																																		success_98 = true;
																																		begin_232 += _97.token.length();
																																		shadow_99.push_back(_97.token);
																																		_2.push_back(_97.token);
																																	}
																																	ISC_STD::skip_spaces(pos);
																																}
																																else 
																																{
																																	success_95 = true;
																																	begin_232 += _94.token.length();
																																	shadow_96.push_back(_94.token);
																																	_2.push_back(_94.token);
																																}
																																ISC_STD::skip_spaces(pos);
																															}
																															else 
																															{
																																success_92 = true;
																																begin_232 += _91.token.length();
																																shadow_93.push_back(_91.token);
																																_2.push_back(_91.token);
																															}
																															ISC_STD::skip_spaces(pos);
																														}
																														else 
																														{
																															success_89 = true;
																															begin_232 += _88.token.length();
																															shadow_90.push_back(_88.token);
																															_2.push_back(_88.token);
																														}
																														ISC_STD::skip_spaces(pos);
																													}
																													else 
																													{
																														success_86 = true;
																														begin_232 += _85.token.length();
																														shadow_87.push_back(_85.token);
																														_2.push_back(_85.token);
																													}
																													ISC_STD::skip_spaces(pos);
																												}
																												else 
																												{
																													success_83 = true;
																													begin_232 += _82.token.length();
																													shadow_84.push_back(_82.token);
																													_2.push_back(_82.token);
																												}
																												ISC_STD::skip_spaces(pos);
																											}
																											else 
																											{
																												success_80 = true;
																												begin_232 += _79.token.length();
																												shadow_81.push_back(_79.token);
																												_2.push_back(_79.token);
																											}
																											ISC_STD::skip_spaces(pos);
																										}
																										else 
																										{
																											success_77 = true;
																											begin_232 += _76.token.length();
																											shadow_78.push_back(_76.token);
																											_2.push_back(_76.token);
																										}
																										ISC_STD::skip_spaces(pos);
																									}
																									else 
																									{
																										success_74 = true;
																										begin_232 += _73.token.length();
																										shadow_75.push_back(_73.token);
																										_2.push_back(_73.token);
																									}
																									ISC_STD::skip_spaces(pos);
																								}
																								else 
																								{
																									success_71 = true;
																									begin_232 += _70.token.length();
																									shadow_72.push_back(_70.token);
																									_2.push_back(_70.token);
																								}
																								ISC_STD::skip_spaces(pos);
																							}
																							else 
																							{
																								success_68 = true;
																								begin_232 += _67.token.length();
																								shadow_69.push_back(_67.token);
																								_2.push_back(_67.token);
																							}
																							ISC_STD::skip_spaces(pos);
																						}
																						else 
																						{
																							success_65 = true;
																							begin_232 += _64.token.length();
																							shadow_66.push_back(_64.token);
																							_2.push_back(_64.token);
																						}
																						ISC_STD::skip_spaces(pos);
																					}
																					else 
																					{
																						success_62 = true;
																						begin_232 += _61.token.length();
																						shadow_63.push_back(_61.token);
																						_2.push_back(_61.token);
																					}
																					ISC_STD::skip_spaces(pos);
																				}
																				else 
																				{
																					success_59 = true;
																					begin_232 += _58.token.length();
																					shadow_60.push_back(_58.token);
																					_2.push_back(_58.token);
																				}
																				ISC_STD::skip_spaces(pos);
																			}
																			else 
																			{
																				success_56 = true;
																				begin_232 += _55.token.length();
																				shadow_57.push_back(_55.token);
																				_2.push_back(_55.token);
																			}
																			ISC_STD::skip_spaces(pos);
																		}
																		else 
																		{
																			success_53 = true;
																			begin_232 += _52.token.length();
																			shadow_54.push_back(_52.token);
																			_2.push_back(_52.token);
																		}
																		ISC_STD::skip_spaces(pos);
																	}
																	else 
																	{
																		success_50 = true;
																		begin_232 += _49.token.length();
																		shadow_51.push_back(_49.token);
																		_2.push_back(_49.token);
																	}
																	ISC_STD::skip_spaces(pos);
																}
																else 
																{
																	success_47 = true;
																	begin_232 += _46.token.length();
																	shadow_48.push_back(_46.token);
																	_2.push_back(_46.token);
																}
																ISC_STD::skip_spaces(pos);
															}
															else 
															{
																success_44 = true;
																begin_232 += _43.token.length();
																shadow_45.push_back(_43.token);
																_2.push_back(_43.token);
															}
															ISC_STD::skip_spaces(pos);
														}
														else 
														{
															success_41 = true;
															begin_232 += _40.token.length();
															shadow_42.push_back(_40.token);
															_2.push_back(_40.token);
														}
														ISC_STD::skip_spaces(pos);
													}
													else 
													{
														success_38 = true;
														begin_232 += _37.token.length();
														shadow_39.push_back(_37.token);
														_2.push_back(_37.token);
													}
													ISC_STD::skip_spaces(pos);
												}
												else 
												{
													success_35 = true;
													begin_232 += _34.token.length();
													shadow_36.push_back(_34.token);
													_2.push_back(_34.token);
												}
												ISC_STD::skip_spaces(pos);
											}
											else 
											{
												success_32 = true;
												begin_232 += _31.token.length();
												shadow_33.push_back(_31.token);
												_2.push_back(_31.token);
											}
											ISC_STD::skip_spaces(pos);
										}
										else 
										{
											success_29 = true;
											begin_232 += _28.token.length();
											shadow_30.push_back(_28.token);
											_2.push_back(_28.token);
										}
										ISC_STD::skip_spaces(pos);
									}
									else 
									{
										success_26 = true;
										begin_232 += _25.token.length();
										shadow_27.push_back(_25.token);
										_2.push_back(_25.token);
									}
									ISC_STD::skip_spaces(pos);
								}
								else 
								{
									success_23 = true;
									begin_232 += _22.token.length();
									shadow_24.push_back(_22.token);
									_2.push_back(_22.token);
								}
								ISC_STD::skip_spaces(pos);
							}
							else 
							{
								success_20 = true;
								begin_232 += _19.token.length();
								shadow_21.push_back(_19.token);
								_2.push_back(_19.token);
							}
							ISC_STD::skip_spaces(pos);
						}
						else 
						{
							success_17 = true;
							begin_232 += _16.token.length();
							shadow_18.push_back(_16.token);
							_2.push_back(_16.token);
						}
						ISC_STD::skip_spaces(pos);
					}
					else 
					{
						success_14 = true;
						begin_232 += _13.token.length();
						shadow_15.push_back(_13.token);
						_2.push_back(_13.token);
					}
					ISC_STD::skip_spaces(pos);
				}
				else 
				{
					success_11 = true;
					begin_232 += _10.token.length();
					shadow_12.push_back(_10.token);
					_2.push_back(_10.token);
				}
				ISC_STD::skip_spaces(pos);
			}
			else 
			{
				success_8 = true;
				begin_232 += _7.token.length();
				shadow_9.push_back(_7.token);
				_2.push_back(_7.token);
			}
			ISC_STD::skip_spaces(pos);
		}
		else 
		{
			success_5 = true;
			begin_232 += _4.token.length();
			shadow_6.push_back(_4.token);
			_2.push_back(_4.token);
		}
		ISC_STD::skip_spaces(pos);
		success_3 = true;
		_0 = _2;
		shadow_233.push_back(_0);
		success_234 = true;
	}
	if (!success_234)
	{
		return;
	}
	if (success_3)
	{
		success_1 = true;
		pos = begin_232;
	}
	ISC_STD::skip_spaces(pos);
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
	ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
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
	ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
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
	if (!(pos->name == Tokens::AUTO_87))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos++;
	ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
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
			ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
		}
		else 
		{
			success_5 = true;
			std::advance(pos, _4.token.length());
			_0 = _4.token;
		}
		ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	}
	else 
	{
		success_3 = true;
		std::advance(pos, _2.token.length());
		_0 = _2.token;
	}
	ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
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
	ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
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
		ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
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
	ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
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
									std::advance(begin_29, _26.token.length());
									shadow_28.push_back(_26.token);
									_6.push_back(_26.token);
								}
								ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
							}
							else 
							{
								success_24 = true;
								std::advance(begin_29, _23.token.length());
								shadow_25.push_back(_23.token);
								_6.push_back(_23.token);
							}
							ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
						}
						else 
						{
							success_21 = true;
							std::advance(begin_29, _20.token.length());
							shadow_22.push_back(_20.token);
							_6.push_back(_20.token);
						}
						ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
					}
					else 
					{
						success_18 = true;
						std::advance(begin_29, _17.token.length());
						shadow_19.push_back(_17.token);
						_6.push_back(_17.token);
					}
					ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
				}
				else 
				{
					success_15 = true;
					std::advance(begin_29, _14.token.length());
					shadow_16.push_back(_14.token);
					_6.push_back(_14.token);
				}
				ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
			}
			else 
			{
				success_12 = true;
				std::advance(begin_29, _11.token.length());
				shadow_13.push_back(_11.token);
				_6.push_back(_11.token);
			}
			ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
		}
		else 
		{
			success_9 = true;
			std::advance(begin_29, _8.token.length());
			shadow_10.push_back(_8.token);
			_6.push_back(_8.token);
		}
		ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
		success_7 = true;
		_4 = _6;
		if (success_7)
		{
			success_5 = true;
			begin_33 = begin_29;
		}
		ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
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
	::Parser::Rule_res _2;
	::Parser::bool_t success_3 = false;
	::Parser::Token _4;
	::Parser::bool_t success_5 = false;
	if (!(pos->name == Tokens::AUTO_60))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos++;
	ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	_2 = Rule_rule(pos);
	while (_2.result)
	{
		success_3 = true;
		std::advance(pos, _2.token.length());
		_2 = Rule_rule(pos);
	}
	ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name == Tokens::AUTO_65))
	{
		return {};
	}
	_4 = *pos;
	success_5 = true;
	pos++;
	cll_block_data data = _2.token;
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
									if (!(!std::strncmp(pos, "<<", 2)))
									{
										if (!(!std::strncmp(pos, ">>", 2)))
										{
											return {};
										}
										else 
										{
											_20 += ::Parser::str_t(pos, 2);
											success_21 = true;
											pos += 2;
											_0 += _20;
										}
										ISC_STD::skip_spaces(pos);
									}
									else 
									{
										_18 += ::Parser::str_t(pos, 2);
										success_19 = true;
										pos += 2;
										_0 += _18;
									}
									ISC_STD::skip_spaces(pos);
								}
								else 
								{
									_16 += ::Parser::str_t(pos, 1);
									success_17 = true;
									pos += 1;
									_0 += _16;
								}
								ISC_STD::skip_spaces(pos);
							}
							else 
							{
								_14 += ::Parser::str_t(pos, 1);
								success_15 = true;
								pos += 1;
								_0 += _14;
							}
							ISC_STD::skip_spaces(pos);
						}
						else 
						{
							_12 += ::Parser::str_t(pos, 1);
							success_13 = true;
							pos += 1;
							_0 += _12;
						}
						ISC_STD::skip_spaces(pos);
					}
					else 
					{
						_10 += ::Parser::str_t(pos, 1);
						success_11 = true;
						pos += 1;
						_0 += _10;
					}
					ISC_STD::skip_spaces(pos);
				}
				else 
				{
					_8 += ::Parser::str_t(pos, 1);
					success_9 = true;
					pos += 1;
					_0 += _8;
				}
				ISC_STD::skip_spaces(pos);
			}
			else 
			{
				_6 += ::Parser::str_t(pos, 1);
				success_7 = true;
				pos += 1;
				_0 += _6;
			}
			ISC_STD::skip_spaces(pos);
		}
		else 
		{
			_4 += ::Parser::str_t(pos, 1);
			success_5 = true;
			pos += 1;
			_0 += _4;
		}
		ISC_STD::skip_spaces(pos);
	}
	else 
	{
		_2 += ::Parser::str_t(pos, 1);
		success_3 = true;
		pos += 1;
		_0 += _2;
	}
	ISC_STD::skip_spaces(pos);
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
	ISC_STD::skip_spaces(pos);
	_2 = AUTO_50(pos);
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
			if (!(*(pos + 0) == '>'))
			{
				if (!(*(pos + 0) == '<'))
				{
					if (!(!std::strncmp(pos, ">=", 2)))
					{
						if (!(!std::strncmp(pos, "<=", 2)))
						{
							return {};
						}
						else 
						{
							_12 += ::Parser::str_t(pos, 2);
							success_13 = true;
							pos += 2;
							_0 += _12;
						}
						ISC_STD::skip_spaces(pos);
					}
					else 
					{
						_10 += ::Parser::str_t(pos, 2);
						success_11 = true;
						pos += 2;
						_0 += _10;
					}
					ISC_STD::skip_spaces(pos);
				}
				else 
				{
					_8 += ::Parser::str_t(pos, 1);
					success_9 = true;
					pos += 1;
					_0 += _8;
				}
				ISC_STD::skip_spaces(pos);
			}
			else 
			{
				_6 += ::Parser::str_t(pos, 1);
				success_7 = true;
				pos += 1;
				_0 += _6;
			}
			ISC_STD::skip_spaces(pos);
		}
		else 
		{
			_4 += ::Parser::str_t(pos, 2);
			success_5 = true;
			pos += 2;
			_0 += _4;
		}
		ISC_STD::skip_spaces(pos);
	}
	else 
	{
		_2 += ::Parser::str_t(pos, 2);
		success_3 = true;
		pos += 2;
		_0 += _2;
	}
	ISC_STD::skip_spaces(pos);
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
		ISC_STD::skip_spaces(pos);
	}
	else 
	{
		success_3 = true;
		pos += _2.token.length();
		_0 = _2.token;
	}
	ISC_STD::skip_spaces(pos);
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
	if (!(*(pos + 0) == '!'))
	{
		if (!(!std::strncmp(pos, "not", 3)))
		{
			return {};
		}
		else 
		{
			_4 += ::Parser::str_t(pos, 3);
			success_5 = true;
			pos += 3;
			_0 += _4;
		}
		ISC_STD::skip_spaces(pos);
	}
	else 
	{
		_2 += ::Parser::str_t(pos, 1);
		success_3 = true;
		pos += 1;
		_0 += _2;
	}
	ISC_STD::skip_spaces(pos);
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
	if (!(!std::strncmp(pos, "&&", 2)))
	{
		if (!(!std::strncmp(pos, "and", 3)))
		{
			return {};
		}
		else 
		{
			_4 += ::Parser::str_t(pos, 3);
			success_5 = true;
			pos += 3;
			_0 += _4;
		}
		ISC_STD::skip_spaces(pos);
	}
	else 
	{
		_2 += ::Parser::str_t(pos, 2);
		success_3 = true;
		pos += 2;
		_0 += _2;
	}
	ISC_STD::skip_spaces(pos);
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
		ISC_STD::skip_spaces(pos);
	}
	else 
	{
		_2 += ::Parser::str_t(pos, 2);
		success_3 = true;
		pos += 2;
		_0 += _2;
	}
	ISC_STD::skip_spaces(pos);
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
	ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	auto begin_10 = pos;
	while (1)
	{
		if (!(begin_10->name == Tokens::AUTO_74))
		{
			break;
		}
		_4 = *begin_10;
		success_5 = true;
		begin_10++;
		shadow_6.push_back(_4);
		ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
		_7 = cll_type(begin_10);
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
	cll_template_data data;
	data.second = shadow_9;
	data.first = _0.token;

	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::cll_template, data)};
}
Parser::Rule_res Parser::Parser::cll_csupport_types(::Parser::arr_t<Token>::iterator pos) {
	auto in = pos;
	::Parser::Token _0;
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
		if (begin_21->name == Tokens::AUTO_8)
		{
			_4 = *begin_21;
			success_5 = true;
			begin_21++;
		}
		ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
		auto begin_20 = begin_21;
		if (!(begin_20->name == Tokens::AUTO_9))
		{
			if (!(begin_20->name == Tokens::AUTO_10))
			{
				if (!(begin_20->name == Tokens::AUTO_11))
				{
					if (!(begin_20->name == Tokens::AUTO_12))
					{
						if (!(begin_20->name == Tokens::AUTO_13))
						{
							break;
						}
						else 
						{
							_18 = *begin_20;
							success_19 = true;
							begin_20++;
							_8 = _18;
						}
						ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
					}
					else 
					{
						_16 = *begin_20;
						success_17 = true;
						begin_20++;
						_8 = _16;
					}
					ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
				}
				else 
				{
					_14 = *begin_20;
					success_15 = true;
					begin_20++;
					_8 = _14;
				}
				ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
			}
			else 
			{
				_12 = *begin_20;
				success_13 = true;
				begin_20++;
				_8 = _12;
			}
			ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
		}
		else 
		{
			_10 = *begin_20;
			success_11 = true;
			begin_20++;
			_8 = _10;
		}
		ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
		success_9 = true;
		_6 = _8;
		if (success_9)
		{
			success_7 = true;
			begin_21 = begin_20;
		}
	}	while(0)
;
	if (success_7)
	{
		success_3 = true;
		pos = begin_21;
	}
	;
	if (!success_3)
	{
		auto begin_30 = pos;
		do
		{
			if (!(begin_30->name == Tokens::AUTO_14))
			{
				if (!(begin_30->name == Tokens::AUTO_15))
				{
					break;
				}
				else 
				{
					_28 = *begin_30;
					success_29 = true;
					begin_30++;
					_24 = _28;
				}
				ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
			}
			else 
			{
				_26 = *begin_30;
				success_27 = true;
				begin_30++;
				_24 = _26;
			}
			ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
			success_25 = true;
			_22 = _24;
		}		while(0)
;
		if (success_25)
		{
			success_23 = true;
			pos = begin_30;
		}
		;
		if (!success_23)
		{
			auto begin_47 = pos;
			do
			{
				if (!(begin_47->name == Tokens::AUTO_16))
				{
					if (!(begin_47->name == Tokens::AUTO_17))
					{
						if (!(begin_47->name == Tokens::AUTO_18))
						{
							if (!(begin_47->name == Tokens::AUTO_19))
							{
								if (!(begin_47->name == Tokens::AUTO_20))
								{
									if (!(begin_47->name == Tokens::AUTO_21))
									{
										break;
									}
									else 
									{
										_45 = *begin_47;
										success_46 = true;
										begin_47++;
										_33 = _45;
									}
									ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
								}
								else 
								{
									_43 = *begin_47;
									success_44 = true;
									begin_47++;
									_33 = _43;
								}
								ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
							}
							else 
							{
								_41 = *begin_47;
								success_42 = true;
								begin_47++;
								_33 = _41;
							}
							ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
						}
						else 
						{
							_39 = *begin_47;
							success_40 = true;
							begin_47++;
							_33 = _39;
						}
						ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
					}
					else 
					{
						_37 = *begin_47;
						success_38 = true;
						begin_47++;
						_33 = _37;
					}
					ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
				}
				else 
				{
					_35 = *begin_47;
					success_36 = true;
					begin_47++;
					_33 = _35;
				}
				ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
				success_34 = true;
				_31 = _33;
			}			while(0)
;
			if (success_34)
			{
				success_32 = true;
				pos = begin_47;
			}
			;
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
	success_1 = true;
	ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	_48 = cll_template(pos);
	if (!(_48.result))
	{
		return {};
	}
	success_49 = true;
	std::advance(pos, _48.token.length());
	cll_csupport_types_data data;
	data.templ = _8;
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
	if (!(begin_28->name == Tokens::AUTO_22))
	{
		if (!(begin_28->name == Tokens::AUTO_23))
		{
			if (!(begin_28->name == Tokens::AUTO_24))
			{
				if (!(begin_28->name == Tokens::AUTO_25))
				{
					if (!(begin_28->name == Tokens::AUTO_26))
					{
						auto begin_20 = begin_28;
						do
						{
							if (!(begin_20->name == Tokens::AUTO_27))
							{
								break;
							}
							_16 = *begin_20;
							success_17 = true;
							begin_20++;
							ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
							_18 = cll_template(begin_20);
							if (!(_18.result))
							{
								break;
							}
							success_19 = true;
							std::advance(begin_20, _18.token.length());
						}						while(0)
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
								if (!(begin_27->name == Tokens::AUTO_28))
								{
									break;
								}
								_23 = *begin_27;
								success_24 = true;
								begin_27++;
								ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
								_25 = cll_template(begin_27);
								if (!(_25.result))
								{
									break;
								}
								success_26 = true;
								std::advance(begin_27, _25.token.length());
							}							while(0)
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
					ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
				}
				else 
				{
					_10 = *begin_28;
					success_11 = true;
					std::advance(begin_28, 1);
					_2 = _10;
				}
				ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
			}
			else 
			{
				_8 = *begin_28;
				success_9 = true;
				std::advance(begin_28, 1);
				_2 = _8;
			}
			ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
		}
		else 
		{
			_6 = *begin_28;
			success_7 = true;
			std::advance(begin_28, 1);
			_2 = _6;
		}
		ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	}
	else 
	{
		_4 = *begin_28;
		success_5 = true;
		std::advance(begin_28, 1);
		_2 = _4;
	}
	ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
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
		ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	}
	else 
	{
		success_3 = true;
		std::advance(pos, _2.token.length());
		_0 = _2.token;
	}
	ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
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
	if (!(pos->name == Tokens::AUTO_29))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos++;
	ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	_2 = expr(pos);
	if (!(_2.result))
	{
		return {};
	}
	success_3 = true;
	std::advance(pos, _2.token.length());
	ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
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
	ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name == Tokens::AUTO_80))
	{
		return {};
	}
	_2 = *pos;
	success_3 = true;
	pos++;
	ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	_4 = expr(pos);
	if (!(_4.result))
	{
		return {};
	}
	success_5 = true;
	std::advance(pos, _4.token.length());
	ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name == Tokens::AUTO_101))
	{
		return {};
	}
	_6 = *pos;
	success_7 = true;
	pos++;
	ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
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
			ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
		}
		else 
		{
			success_5 = true;
			std::advance(pos, _4.token.length());
			_0 = _4.token;
		}
		ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	}
	else 
	{
		success_3 = true;
		std::advance(pos, _2.token.length());
		_0 = _2.token;
	}
	ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	success_1 = true;
	ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name == Tokens::LOGICAL_OP))
	{
		return {};
	}
	_8 = *pos;
	success_9 = true;
	pos++;
	ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
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
			ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
		}
		else 
		{
			success_15 = true;
			std::advance(pos, _14.token.length());
			_10 = _14.token;
		}
		ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	}
	else 
	{
		success_13 = true;
		std::advance(pos, _12.token.length());
		_10 = _12.token;
	}
	ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
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
	ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
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
		ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
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
	ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
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
		ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
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
					std::advance(pos, _8.token.length());
					_0 = _8.token;
				}
				ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
			}
			else 
			{
				success_7 = true;
				std::advance(pos, _6.token.length());
				_0 = _6.token;
			}
			ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
		}
		else 
		{
			success_5 = true;
			std::advance(pos, _4.token.length());
			_0 = _4.token;
		}
		ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	}
	else 
	{
		success_3 = true;
		std::advance(pos, _2.token.length());
		_0 = _2.token;
	}
	ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
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
	if (!(pos->name == Tokens::AUTO_84))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos++;
	ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
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
		ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	}
	else 
	{
		success_5 = true;
		std::advance(pos, _4.token.length());
		_2 = _4.token;
	}
	ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	success_3 = true;
	ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name == Tokens::AUTO_85))
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
	if (!(pos->name == Tokens::AUTO_84))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos++;
	ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	_2 = copiable_method_call(pos);
	if (!(_2.result))
	{
		return {};
	}
	success_3 = true;
	std::advance(pos, _2.token.length());
	ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name == Tokens::AUTO_85))
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
								std::advance(pos, _14.token.length());
								_0 = _14.token;
							}
							ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
						}
						else 
						{
							success_13 = true;
							std::advance(pos, _12.token.length());
							_0 = _12.token;
						}
						ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
					}
					else 
					{
						success_11 = true;
						std::advance(pos, _10.token.length());
						_0 = _10.token;
					}
					ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
				}
				else 
				{
					success_9 = true;
					std::advance(pos, _8.token.length());
					_0 = _8.token;
				}
				ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
			}
			else 
			{
				success_7 = true;
				std::advance(pos, _6.token.length());
				_0 = _6.token;
			}
			ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
		}
		else 
		{
			success_5 = true;
			std::advance(pos, _4.token.length());
			_0 = _4.token;
		}
		ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	}
	else 
	{
		success_3 = true;
		std::advance(pos, _2.token.length());
		_0 = _2.token;
	}
	ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
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
	if (!(pos->name == Tokens::AUTO_84))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos++;
	ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	_2 = function_arguments(pos);
	if (!(_2.result))
	{
		return {};
	}
	success_3 = true;
	std::advance(pos, _2.token.length());
	ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name == Tokens::AUTO_85))
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
	if (!(pos->name == Tokens::AUTO_84))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos++;
	ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	_2 = function_parameters(pos);
	if (!(_2.result))
	{
		return {};
	}
	success_3 = true;
	std::advance(pos, _2.token.length());
	ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name == Tokens::AUTO_85))
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
		ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	}
	else 
	{
		success_5 = true;
		std::advance(begin_17, _4.token.length());
		_2 = _4.token;
	}
	ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	success_3 = true;
	ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	auto begin_15 = begin_17;
	while (1)
	{
		if (!(begin_15->name == Tokens::AUTO_74))
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
		ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
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
	ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	auto begin_12 = begin_13;
	while (1)
	{
		if (!(begin_12->name == Tokens::AUTO_74))
		{
			break;
		}
		_6 = *begin_12;
		success_7 = true;
		begin_12++;
		shadow_8.push_back(_6);
		ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
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
	ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
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
	if (!(pos->name == Tokens::AUTO_42))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos++;
	ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
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
	ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	_9 = function_body_decl(pos);
	if (!(_9.result))
	{
		return {};
	}
	success_10 = true;
	std::advance(pos, _9.token.length());
	ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
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
	}	while(0)
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
	if (!(pos->name == Tokens::AUTO_43))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos++;
	ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	_2 = expr(pos);
	if (!(_2.result))
	{
		return {};
	}
	success_3 = true;
	std::advance(pos, _2.token.length());
	ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
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
	if (!(pos->name == Tokens::AUTO_44))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos++;
	ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name == Tokens::AUTO_84))
	{
		return {};
	}
	_2 = *pos;
	success_3 = true;
	pos++;
	ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
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
			ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
		}
		else 
		{
			success_9 = true;
			std::advance(begin_12, _8.token.length());
			_6 = _8.token;
		}
		ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
		success_7 = true;
		_4 = _6;
	}	while(0)
;
	if (success_7)
	{
		success_5 = true;
		pos = begin_12;
	}
	ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name == Tokens::AUTO_99))
	{
		return {};
	}
	_13 = *pos;
	success_14 = true;
	pos++;
	ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	_15 = expr(pos);
	if (_15.result)
	{
		success_16 = true;
		std::advance(pos, _15.token.length());
	}
	ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name == Tokens::AUTO_99))
	{
		return {};
	}
	_17 = *pos;
	success_18 = true;
	pos++;
	ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	_19 = expr(pos);
	if (_19.result)
	{
		success_20 = true;
		std::advance(pos, _19.token.length());
	}
	ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name == Tokens::AUTO_85))
	{
		return {};
	}
	_21 = *pos;
	success_22 = true;
	pos++;
	ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
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
	ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	auto begin_10 = pos;
	while (1)
	{
		if (!(begin_10->name == Tokens::AUTO_95))
		{
			return {};
		}
		_4 = *begin_10;
		success_5 = true;
		begin_10++;
		shadow_6.push_back(_4);
		ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
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
	if (!(pos->name == Tokens::AUTO_50))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos++;
	ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
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
		if (!(begin_8->name == Tokens::AUTO_55))
		{
			if (!(begin_8->name == Tokens::AUTO_56))
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
			ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
		}
		else 
		{
			_4 = *begin_8;
			success_5 = true;
			begin_8++;
			_2 = _4;
		}
		ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
		success_3 = true;
		_0 = _2;
	}	while(0)
;
	if (success_3)
	{
		success_1 = true;
		pos = begin_8;
	}
	ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name == Tokens::ID))
	{
		return {};
	}
	_9 = *pos;
	success_10 = true;
	pos++;
	ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	auto begin_19 = pos;
	do
	{
		if (!(begin_19->name == Tokens::AUTO_86))
		{
			break;
		}
		_13 = *begin_19;
		success_14 = true;
		begin_19++;
		ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
		_15 = expr(begin_19);
		if (!(_15.result))
		{
			break;
		}
		success_16 = true;
		std::advance(begin_19, _15.token.length());
		ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
		if (!(begin_19->name == Tokens::AUTO_88))
		{
			break;
		}
		_17 = *begin_19;
		success_18 = true;
		begin_19++;
	}	while(0)
;
	if (success_14 && success_16 && success_18)
	{
		success_12 = true;
		pos = begin_19;
	}
	ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	auto begin_28 = pos;
	do
	{
		if (!(begin_28->name == Tokens::AUTO_55))
		{
			if (!(begin_28->name == Tokens::AUTO_56))
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
			ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
		}
		else 
		{
			_24 = *begin_28;
			success_25 = true;
			begin_28++;
			_22 = _24;
		}
		ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
		success_23 = true;
		_20 = _22;
	}	while(0)
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
	ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name == Tokens::ID))
	{
		return {};
	}
	_2 = *pos;
	success_3 = true;
	pos++;
	ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
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
		ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
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
			ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
		}
		else 
		{
			success_11 = true;
			std::advance(begin_14, _10.token.length());
			_8 = _10.token;
		}
		ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
		success_9 = true;
	}	while(0)
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
		_4 += ::Parser::str_t(begin_17, 2);
		success_5 = true;
		begin_17 += 2;
		ISC_STD::skip_spaces(pos);
		auto begin_14 = begin_17;
		while (1)
		{
			if (!(!std::strncmp(begin_14, "\\'", 2)))
			{
				if (!(!(*(begin_14 + 0) == '\'')))
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
				ISC_STD::skip_spaces(pos);
			}
			else 
			{
				_10 += ::Parser::str_t(begin_14, 2);
				success_11 = true;
				begin_14 += 2;
				_8 += _10;
			}
			ISC_STD::skip_spaces(pos);
			success_9 = true;
			_6 += _8;
		}
		if (success_9)
		{
			success_7 = true;
			begin_17 = begin_14;
		}
		ISC_STD::skip_spaces(pos);
		if (!(*(begin_17 + 0) == '\''))
		{
			return {};
		}
		_15 += ::Parser::str_t(begin_17, 2);
		success_16 = true;
		begin_17 += 2;
		_2 += _4;
		_2 += _6;
		_2 += _15;
	}	while(0)
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
			_20 += ::Parser::str_t(begin_33, 2);
			success_21 = true;
			begin_33 += 2;
			ISC_STD::skip_spaces(pos);
			auto begin_30 = begin_33;
			while (1)
			{
				if (!(!std::strncmp(begin_30, "\\\"", 2)))
				{
					if (!(!(*(begin_30 + 0) == '"')))
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
					ISC_STD::skip_spaces(pos);
				}
				else 
				{
					_26 += ::Parser::str_t(begin_30, 2);
					success_27 = true;
					begin_30 += 2;
					_24 += _26;
				}
				ISC_STD::skip_spaces(pos);
				success_25 = true;
				_22 += _24;
			}
			if (success_25)
			{
				success_23 = true;
				begin_33 = begin_30;
			}
			ISC_STD::skip_spaces(pos);
			if (!(*(begin_33 + 0) == '"'))
			{
				break;
			}
			_31 += ::Parser::str_t(begin_33, 2);
			success_32 = true;
			begin_33 += 2;
			_18 += _20;
			_18 += _22;
			_18 += _31;
		}		while(0)
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
	STRING_data data = _2;
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
	ISC_STD::skip_spaces(pos);
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
	ISC_STD::skip_spaces(pos);
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
		ISC_STD::skip_spaces(pos);
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
	}	while(0)
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
	if (!(!std::strncmp(begin_7, "true", 4)))
	{
		if (!(!std::strncmp(begin_7, "false", 5)))
		{
			return {};
		}
		else 
		{
			_5 += ::Parser::str_t(begin_7, 5);
			success_6 = true;
			begin_7 += 5;
			_1 += _5;
		}
		ISC_STD::skip_spaces(pos);
	}
	else 
	{
		_3 += ::Parser::str_t(begin_7, 4);
		success_4 = true;
		begin_7 += 4;
		_1 += _3;
	}
	ISC_STD::skip_spaces(pos);
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
	if (!(pos->name == Tokens::AUTO_86))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos++;
	ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
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
			ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
			if (!(begin_12->name == Tokens::AUTO_74))
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
	}	while(0)
;
	if (success_5)
	{
		success_3 = true;
		pos = begin_13;
	}
	ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name == Tokens::AUTO_88))
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
	if (!(pos->name == Tokens::AUTO_60))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos++;
	ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
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
		ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
		if (!(begin_27->name == Tokens::AUTO_101))
		{
			return {};
		}
		_6 = *begin_27;
		success_7 = true;
		begin_27++;
		ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
		_8 = any_data(begin_27);
		if (!(_8.result))
		{
			break;
		}
		success_9 = true;
		std::advance(begin_27, _8.token.length());
		ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
		auto begin_24 = begin_27;
		while (1)
		{
			if (!(begin_24->name == Tokens::AUTO_74))
			{
				break;
			}
			_12 = *begin_24;
			success_13 = true;
			begin_24++;
			shadow_14.push_back(_12);
			ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
			if (!(begin_24->name == Tokens::ID))
			{
				break;
			}
			_15 = *begin_24;
			success_16 = true;
			begin_24++;
			shadow_17.push_back(_15);
			ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
			if (!(begin_24->name == Tokens::AUTO_101))
			{
				break;
			}
			_18 = *begin_24;
			success_19 = true;
			begin_24++;
			shadow_20.push_back(_18);
			ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
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
		ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
		if (!(begin_27->name == Tokens::AUTO_99))
		{
			break;
		}
		_25 = *begin_27;
		success_26 = true;
		begin_27++;
	}	while(0)
;
	if (success_5 && success_7 && success_9 && success_11 && success_26)
	{
		success_3 = true;
		pos = begin_27;
	}
	ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name == Tokens::AUTO_65))
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
								std::advance(pos, _14.token.length());
								_0 = _14.token;
							}
							ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
						}
						else 
						{
							success_13 = true;
							std::advance(pos, _12.token.length());
							_0 = _12.token;
						}
						ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
					}
					else 
					{
						success_11 = true;
						std::advance(pos, _10.token.length());
						_0 = _10.token;
					}
					ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
				}
				else 
				{
					_8 = *pos;
					success_9 = true;
					std::advance(pos, 1);
					_0 = _8;
				}
				ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
			}
			else 
			{
				_6 = *pos;
				success_7 = true;
				std::advance(pos, 1);
				_0 = _6;
			}
			ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
		}
		else 
		{
			_4 = *pos;
			success_5 = true;
			std::advance(pos, 1);
			_0 = _4;
		}
		ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	}
	else 
	{
		_2 = *pos;
		success_3 = true;
		pos++;
		_0 = _2;
	}
	ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
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
	ISC_STD::skip_spaces(pos);
	if (!((*(begin_8 + 0)>='a' && *(begin_8 + 0)<='z') || (*(begin_8 + 0)>='A' && *(begin_8 + 0)<='Z') || *(begin_8 + 0) == '_'))
	{
		return {};
	}
	_4 += ::Parser::str_t(begin_8, 1);
	success_5 = true;
	begin_8 += 1;
	ISC_STD::skip_spaces(pos);
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
	if (!(pos->name == Tokens::AUTO_66))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos++;
	ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name == Tokens::AUTO_67))
	{
		if (!(pos->name == Tokens::AUTO_68))
		{
			if (!(pos->name == Tokens::AUTO_69))
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
			ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
		}
		else 
		{
			_6 = *pos;
			success_7 = true;
			pos++;
			_2 = _6;
		}
		ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	}
	else 
	{
		_4 = *pos;
		success_5 = true;
		pos++;
		_2 = _4;
	}
	ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
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
	if (!(pos->name == Tokens::AUTO_70))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos++;
	ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
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
Parser::Rule_res Parser::Parser::linear_comment(::Parser::arr_t<Token>::iterator pos) {
	auto in = pos;
	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	::Parser::Token _2;
	::Parser::bool_t success_3 = false;
	if (!(pos->name == Tokens::AUTO_71))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos++;
	ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name == Tokens::AUTO_72))
	{
		return {};
	}
	_2 = *pos;
	success_3 = true;
	pos++;
	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::linear_comment)};
}
Parser::Rule_res Parser::Parser::main(::Parser::arr_t<Token>::iterator pos) {
	auto in = pos;
	::Parser::any_t _0;
	::Parser::bool_t success_1 = false;
	::Parser::Rule_res _2;
	::Parser::bool_t success_3 = false;
	::Parser::Token _4;
	::Parser::bool_t success_5 = false;
	::Parser::Rule_res _6;
	::Parser::bool_t success_7 = false;
	_2 = use(pos);
	if (!(_2.result))
	{
		if (!(pos->name == Tokens::AUTO_95))
		{
			_6 = spacemode(pos);
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
			ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
		}
		else 
		{
			_4 = *pos;
			success_5 = true;
			std::advance(pos, 1);
			_0 = _4;
		}
		ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	}
	else 
	{
		success_3 = true;
		std::advance(pos, _2.token.length());
		_0 = _2.token;
	}
	ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
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
	ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
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
	if (!(pos->name == Tokens::AUTO_73))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos++;
	ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	_2 = use_unit(pos);
	if (!(_2.result))
	{
		return {};
	}
	success_3 = true;
	std::advance(pos, _2.token.length());
	ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	auto begin_12 = pos;
	while (1)
	{
		if (!(begin_12->name == Tokens::AUTO_74))
		{
			break;
		}
		_6 = *begin_12;
		success_7 = true;
		begin_12++;
		shadow_8.push_back(_6);
		ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
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
									std::advance(begin_22, _20.token.length());
									_6 = _20.token;
								}
								ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
							}
							else 
							{
								success_19 = true;
								std::advance(begin_22, _18.token.length());
								_6 = _18.token;
							}
							ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
						}
						else 
						{
							success_17 = true;
							std::advance(begin_22, _16.token.length());
							_6 = _16.token;
						}
						ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
					}
					else 
					{
						success_15 = true;
						std::advance(begin_22, _14.token.length());
						_6 = _14.token;
					}
					ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
				}
				else 
				{
					_12 = *begin_22;
					success_13 = true;
					std::advance(begin_22, 1);
					_6 = _12;
				}
				ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
			}
			else 
			{
				success_11 = true;
				std::advance(begin_22, _10.token.length());
				_6 = _10.token;
			}
			ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
		}
		else 
		{
			success_9 = true;
			std::advance(begin_22, _8.token.length());
			_6 = _8.token;
		}
		ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
		success_7 = true;
		if (success_7)
		{
			success_5 = true;
			begin_25 = begin_22;
		}
		ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
		_23 = Rule_qualifier(begin_25);
		if (_23.result)
		{
			success_24 = true;
			std::advance(begin_25, _23.token.length());
		}
	}	while(0)
;
	if (success_5)
	{
		success_3 = true;
		pos = begin_25;
	}
	;
	if (!success_3)
	{
		_26 = Rule_escaped(pos);
		if (!(_26.result))
		{
			if (!(pos->name == Tokens::AUTO_95))
			{
				_30 = Rule_op(pos);
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
							std::advance(pos, _34.token.length());
							_0 = _34.token;
						}
						ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
					}
					else 
					{
						success_33 = true;
						std::advance(pos, _32.token.length());
						_0 = _32.token;
					}
					ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
				}
				else 
				{
					success_31 = true;
					std::advance(pos, _30.token.length());
					_0 = _30.token;
				}
				ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
			}
			else 
			{
				_28 = *pos;
				success_29 = true;
				std::advance(pos, 1);
				_0 = _28;
			}
			ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
		}
		else 
		{
			success_27 = true;
			std::advance(pos, _26.token.length());
			_0 = _26.token;
		}
		ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	}
	success_1 = true;
	Rule_rule_data data;
	data.qualifier = _4;
	data.val = _6;

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
	if (pos->name == Tokens::AUTO_105)
	{
		_0 = *pos;
		success_1 = true;
		pos++;
	}
	ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name == Tokens::ID))
	{
		return {};
	}
	_2 = *pos;
	success_3 = true;
	pos++;
	ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	auto begin_12 = pos;
	while (1)
	{
		if (!(begin_12->name == Tokens::AUTO_95))
		{
			break;
		}
		_6 = *begin_12;
		success_7 = true;
		begin_12++;
		shadow_8.push_back(_6);
		ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
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
Parser::Rule_res Parser::Parser::Rule_op(::Parser::arr_t<Token>::iterator pos) {
	auto in = pos;
	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	::Parser::Token _2;
	::Parser::bool_t success_3 = false;
	::Parser::Token _4;
	::Parser::bool_t success_5 = false;
	::Parser::Token _6;
	::Parser::bool_t success_7 = false;
	auto begin_8 = pos;
	if (!(begin_8->name == Tokens::AUTO_78))
	{
		if (!(begin_8->name == Tokens::AUTO_79))
		{
			return {};
		}
		else 
		{
			_6 = *begin_8;
			success_7 = true;
			begin_8++;
			_2 = _6;
		}
		ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	}
	else 
	{
		_4 = *begin_8;
		success_5 = true;
		begin_8++;
		_2 = _4;
	}
	ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	success_3 = true;
	_0 = _2;
	if (success_3)
	{
		success_1 = true;
		pos = begin_8;
	}
	Rule_op_data data = _0;
	return {true, ::Parser::Rule(in->startpos, in->start, pos->end, Rules::Rule_op, data)};
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
	if (!(begin_10->name == Tokens::AUTO_80))
	{
		if (!(begin_10->name == Tokens::AUTO_81))
		{
			if (!(begin_10->name == Tokens::AUTO_82))
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
			ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
		}
		else 
		{
			_6 = *begin_10;
			success_7 = true;
			begin_10++;
			_2 = _6;
		}
		ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	}
	else 
	{
		_4 = *begin_10;
		success_5 = true;
		begin_10++;
		_2 = _4;
	}
	ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
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
		if (!(begin_10->name == Tokens::AUTO_83))
		{
			break;
		}
		_2 = *begin_10;
		success_3 = true;
		begin_10++;
		ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
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
			ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
		}
		else 
		{
			success_7 = true;
			std::advance(begin_10, _6.token.length());
			_4 = _6.token;
		}
		ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
		success_5 = true;
	}	while(0)
;
	if (success_3 && success_5)
	{
		success_1 = true;
		pos = begin_10;
	}
	ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name == Tokens::AUTO_84))
	{
		return {};
	}
	_11 = *pos;
	success_12 = true;
	pos++;
	ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	_13 = Rule_rule(pos);
	while (_13.result)
	{
		success_14 = true;
		std::advance(pos, _13.token.length());
		_13 = Rule_rule(pos);
	}
	ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name == Tokens::AUTO_85))
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
	if (!(begin_10->name == Tokens::AUTO_102))
	{
		if (!(begin_10->name == Tokens::AUTO_90))
		{
			if (!(begin_10->name == Tokens::AUTO_91))
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
			ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
		}
		else 
		{
			_6 = *begin_10;
			success_7 = true;
			begin_10++;
			_2 = _6;
		}
		ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	}
	else 
	{
		_4 = *begin_10;
		success_5 = true;
		begin_10++;
		_2 = _4;
	}
	ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
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
	if (!(pos->name == Tokens::AUTO_102))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos++;
	auto begin_6 = pos;
	if (!(begin_6->name == Tokens::AUTO_103))
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
	if (!(begin_12->name == Tokens::AUTO_94))
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
	if (!(pos->name == Tokens::AUTO_86))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos++;
	ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	if (pos->name == Tokens::AUTO_87)
	{
		_2 = *pos;
		success_3 = true;
		pos++;
	}
	ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
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
				ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
			}
			else 
			{
				success_11 = true;
				std::advance(begin_16, _10.token.length());
				shadow_12.push_back(_10.token);
				_5.push_back(_10.token);
			}
			ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
		}
		else 
		{
			success_8 = true;
			std::advance(begin_16, _7.token.length());
			shadow_9.push_back(_7.token);
			_5.push_back(_7.token);
		}
		ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
		success_6 = true;
		dt = _5;
		shadow_17.push_back(dt);
	}
	if (success_6)
	{
		success_4 = true;
		pos = begin_16;
	}
	ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name == Tokens::AUTO_88))
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
	while (pos->name == Tokens::AUTO_104)
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
	ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
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
	ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name == Tokens::AUTO_101))
	{
		return {};
	}
	_8 = *pos;
	success_9 = true;
	pos++;
	ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
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
		ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	}
	else 
	{
		success_14 = true;
		std::advance(begin_17, _13.token.length());
		_11 = _13.token;
	}
	ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
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
	while (pos->name == Tokens::AUTO_104)
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
	ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name == Tokens::AUTO_97))
	{
		return {};
	}
	_4 = *pos;
	success_5 = true;
	pos++;
	ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name == Tokens::AUTO_101))
	{
		return {};
	}
	_6 = *pos;
	success_7 = true;
	pos++;
	ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
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
		ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	}
	else 
	{
		success_11 = true;
		std::advance(pos, _10.token.length());
		_8 = _10.token;
	}
	ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	success_9 = true;
	ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name == Tokens::AUTO_99))
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
	if (!(pos->name == Tokens::AUTO_102))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos++;
	if (!(pos->name == Tokens::AUTO_103))
	{
		return {};
	}
	_2 = *pos;
	success_3 = true;
	pos++;
	if (pos->name == Tokens::NUMBER)
	{
		_4 = *pos;
		success_5 = true;
		pos++;
	}
	Rule_escaped_data data;
	data.num = _4;
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
	while (pos->name == Tokens::AUTO_104)
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
	ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name == Tokens::AUTO_105))
	{
		return {};
	}
	_4 = *pos;
	success_5 = true;
	pos++;
	if (!(pos->name == Tokens::AUTO_95))
	{
		return {};
	}
	_6 = *pos;
	success_7 = true;
	pos++;
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
	if (!(pos->name == Tokens::AUTO_106))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos++;
	ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	while (pos->name == Tokens::AUTO_107)
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
	if (!(pos->name == Tokens::AUTO_108))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos++;
	ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	while (pos->name == Tokens::AUTO_109)
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
	ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name == Tokens::AUTO_101))
	{
		return {};
	}
	_2 = *pos;
	success_3 = true;
	pos++;
	ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	_4 = Rule_rule(pos);
	while (_4.result)
	{
		success_5 = true;
		std::advance(pos, _4.token.length());
		_4 = Rule_rule(pos);
	}
	ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	_6 = Rule_data_block(pos);
	if (!(_6.result))
	{
		return {};
	}
	success_7 = true;
	std::advance(pos, _6.token.length());
	ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	_8 = Rule_nested_rule(pos);
	while (_8.result)
	{
		success_9 = true;
		std::advance(pos, _8.token.length());
		_8 = Rule_nested_rule(pos);
	}
	ISC_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name == Tokens::AUTO_99))
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
	_0 += ::Parser::str_t(pos, 2);
	success_1 = true;
	pos += 2;
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
	_0 += ::Parser::str_t(pos, 2);
	success_1 = true;
	pos += 2;
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
	_0 += ::Parser::str_t(pos, 2);
	success_1 = true;
	pos += 2;
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
Parser::Token_res Parser::Tokenizator::AUTO_12(const char* pos) {
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
	AUTO_12_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_12, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_13(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!std::strncmp(pos + 0, "long long", 9)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 9);
	success_1 = true;
	pos += 9;
	AUTO_13_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_13, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_14(const char* pos) {
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
	AUTO_14_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_14, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_15(const char* pos) {
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
	AUTO_15_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_15, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_16(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!std::strncmp(pos + 0, "deque", 5)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 5);
	success_1 = true;
	pos += 5;
	AUTO_16_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_16, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_17(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!std::strncmp(pos + 0, "vector", 6)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 6);
	success_1 = true;
	pos += 6;
	AUTO_17_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_17, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_18(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!std::strncmp(pos + 0, "queue", 5)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 5);
	success_1 = true;
	pos += 5;
	AUTO_18_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_18, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_19(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!std::strncmp(pos + 0, "stack", 5)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 5);
	success_1 = true;
	pos += 5;
	AUTO_19_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_19, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_20(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!std::strncmp(pos + 0, "list", 4)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 4);
	success_1 = true;
	pos += 4;
	AUTO_20_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_20, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_21(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!std::strncmp(pos + 0, "forward_list", 12)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 12);
	success_1 = true;
	pos += 12;
	AUTO_21_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_21, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_22(const char* pos) {
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
	AUTO_22_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_22, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_23(const char* pos) {
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
	AUTO_23_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_23, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_24(const char* pos) {
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
	AUTO_24_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_24, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_25(const char* pos) {
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
	AUTO_25_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_25, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_26(const char* pos) {
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
	AUTO_26_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_26, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_27(const char* pos) {
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
	AUTO_27_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_27, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_28(const char* pos) {
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
	AUTO_28_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_28, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_29(const char* pos) {
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
	AUTO_29_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_29, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_42(const char* pos) {
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
	AUTO_42_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_42, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_43(const char* pos) {
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
	AUTO_43_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_43, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_44(const char* pos) {
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
	AUTO_44_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_44, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_50(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == '='))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 2);
	success_1 = true;
	pos += 2;
	AUTO_50_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_50, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_55(const char* pos) {
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
	AUTO_55_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_55, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_56(const char* pos) {
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
	AUTO_56_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_56, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_60(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == '{'))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 2);
	success_1 = true;
	pos += 2;
	AUTO_60_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_60, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_65(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == '}'))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 2);
	success_1 = true;
	pos += 2;
	AUTO_65_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_65, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_66(const char* pos) {
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
	AUTO_66_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_66, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_67(const char* pos) {
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
	AUTO_67_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_67, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_68(const char* pos) {
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
	AUTO_68_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_68, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_69(const char* pos) {
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
	AUTO_69_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_69, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_70(const char* pos) {
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
	AUTO_70_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_70, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_71(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!std::strncmp(pos + 0, "//", 2)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 2);
	success_1 = true;
	pos += 2;
	AUTO_71_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_71, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_72(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!(*(pos + 0) == '\n')))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 1);
	success_1 = true;
	pos += 1;
	AUTO_72_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_72, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_73(const char* pos) {
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
	AUTO_73_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_73, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_74(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == ','))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 2);
	success_1 = true;
	pos += 2;
	AUTO_74_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_74, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_78(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == '|'))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 2);
	success_1 = true;
	pos += 2;
	AUTO_78_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_78, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_79(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!std::strncmp(pos + 0, "|&", 2)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 2);
	success_1 = true;
	pos += 2;
	AUTO_79_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_79, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_80(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == '?'))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 2);
	success_1 = true;
	pos += 2;
	AUTO_80_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_80, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_81(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == '+'))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 2);
	success_1 = true;
	pos += 2;
	AUTO_81_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_81, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_82(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == '*'))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 2);
	success_1 = true;
	pos += 2;
	AUTO_82_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_82, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_83(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == '&'))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 2);
	success_1 = true;
	pos += 2;
	AUTO_83_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_83, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_84(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == '('))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 2);
	success_1 = true;
	pos += 2;
	AUTO_84_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_84, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_85(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == ')'))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 2);
	success_1 = true;
	pos += 2;
	AUTO_85_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_85, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_86(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == '['))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 2);
	success_1 = true;
	pos += 2;
	AUTO_86_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_86, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_87(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == '^'))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 2);
	success_1 = true;
	pos += 2;
	AUTO_87_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_87, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_88(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == ']'))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 2);
	success_1 = true;
	pos += 2;
	AUTO_88_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_88, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_90(const char* pos) {
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
	AUTO_90_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_90, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_91(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!(*(pos + 0) == ']')))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 1);
	success_1 = true;
	pos += 1;
	AUTO_91_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_91, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_94(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == '-'))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 2);
	success_1 = true;
	pos += 2;
	AUTO_94_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_94, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_95(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == '.'))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 2);
	success_1 = true;
	pos += 2;
	AUTO_95_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_95, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_97(const char* pos) {
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
	AUTO_97_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_97, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_99(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == ';'))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 2);
	success_1 = true;
	pos += 2;
	AUTO_99_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_99, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_101(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == ':'))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 2);
	success_1 = true;
	pos += 2;
	AUTO_101_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_101, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_102(const char* pos) {
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
	AUTO_102_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_102, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_103(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (*(pos + 0) == '\0')
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 2);
	success_1 = true;
	pos += 2;
	AUTO_103_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_103, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_104(const char* pos) {
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
	AUTO_104_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_104, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_105(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == '#'))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 2);
	success_1 = true;
	pos += 2;
	AUTO_105_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_105, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_106(const char* pos) {
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
	AUTO_106_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_106, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_107(const char* pos) {
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
	AUTO_107_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_107, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_108(const char* pos) {
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
	AUTO_108_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_108, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_109(const char* pos) {
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
	AUTO_109_data data = _0;
	return {true, ::Parser::Token(in - str, in, pos, Tokens::AUTO_109, data)};
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
