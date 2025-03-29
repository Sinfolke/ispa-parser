#include "Parser.h"
std::string Parser::TokensToString(Tokens token) {
	switch (token) {
		case Tokens::NONE: return "NONE";
		case Tokens::cll_OP: return "cll_OP";
		case Tokens::cll_ASSIGNMENT_OP: return "cll_ASSIGNMENT_OP";
		case Tokens::cll_COMPARE_OP: return "cll_COMPARE_OP";
		case Tokens::cll_LOGICAL_OP: return "cll_LOGICAL_OP";
		case Tokens::cll_LOGICAL_NOT: return "cll_LOGICAL_NOT";
		case Tokens::cll_LOGICAL_AND: return "cll_LOGICAL_AND";
		case Tokens::cll_LOGICAL_OR: return "cll_LOGICAL_OR";
		case Tokens::STRING: return "STRING";
		case Tokens::NUMBER: return "NUMBER";
		case Tokens::BOOLEAN: return "BOOLEAN";
		case Tokens::END: return "END";
		case Tokens::NEWLINE: return "NEWLINE";
		case Tokens::LINEAR_COMMENT: return "LINEAR_COMMENT";
		case Tokens::ID: return "ID";
		case Tokens::Rule_OP: return "Rule_OP";
		case Tokens::Rule_QUANITIFIER: return "Rule_QUANITIFIER";
		case Tokens::Rule_CSEQUENCE: return "Rule_CSEQUENCE";
		case Tokens::Rule_CSEQUENCE_SYMBOL: return "Rule_CSEQUENCE_SYMBOL";
		case Tokens::Rule_CSEQUENCE_ESCAPE: return "Rule_CSEQUENCE_ESCAPE";
		case Tokens::Rule_CSEQUENCE_DIAPASON: return "Rule_CSEQUENCE_DIAPASON";
		case Tokens::Rule_ANY: return "Rule_ANY";
		case Tokens::Rule_ESCAPED: return "Rule_ESCAPED";
		case Tokens::Rule_HEX: return "Rule_HEX";
		case Tokens::Rule_BIN: return "Rule_BIN";
		case Tokens::AUTO_0: return "AUTO_0";
		case Tokens::AUTO_1: return "AUTO_1";
		case Tokens::AUTO_2: return "AUTO_2";
		case Tokens::AUTO_3: return "AUTO_3";
		case Tokens::AUTO_4: return "AUTO_4";
		case Tokens::AUTO_5: return "AUTO_5";
		case Tokens::AUTO_6: return "AUTO_6";
		case Tokens::AUTO_7: return "AUTO_7";
		case Tokens::AUTO_9: return "AUTO_9";
		case Tokens::AUTO_14: return "AUTO_14";
		case Tokens::AUTO_15: return "AUTO_15";
		case Tokens::AUTO_22: return "AUTO_22";
		case Tokens::AUTO_27: return "AUTO_27";
		case Tokens::AUTO_28: return "AUTO_28";
		case Tokens::AUTO_33: return "AUTO_33";
		case Tokens::AUTO_35: return "AUTO_35";
		case Tokens::AUTO_40: return "AUTO_40";
		case Tokens::AUTO_42: return "AUTO_42";
		case Tokens::AUTO_43: return "AUTO_43";
		case Tokens::AUTO_44: return "AUTO_44";
		case Tokens::AUTO_45: return "AUTO_45";
		case Tokens::AUTO_46: return "AUTO_46";
		case Tokens::AUTO_47: return "AUTO_47";
		case Tokens::AUTO_48: return "AUTO_48";
		case Tokens::AUTO_51: return "AUTO_51";
		case Tokens::AUTO_52: return "AUTO_52";
		case Tokens::AUTO_53: return "AUTO_53";
		case Tokens::AUTO_54: return "AUTO_54";
		case Tokens::AUTO_55: return "AUTO_55";
		case Tokens::AUTO_56: return "AUTO_56";
		case Tokens::AUTO_57: return "AUTO_57";
		case Tokens::AUTO_58: return "AUTO_58";
		case Tokens::AUTO_59: return "AUTO_59";
		case Tokens::__WHITESPACE: return "__WHITESPACE";
	}
	return "NONE";
}

Parser::Token Parser::Tokenizator::makeToken() {
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
	::Parser::Token_res _56;
	::Parser::bool_t success_57 = false;
	::Parser::Token_res _58;
	::Parser::bool_t success_59 = false;
	::Parser::Token_res _60;
	::Parser::bool_t success_61 = false;
	::Parser::Token_res _62;
	::Parser::bool_t success_63 = false;
	::Parser::Token_res _64;
	::Parser::bool_t success_65 = false;
	::Parser::Token_res _66;
	::Parser::bool_t success_67 = false;
	::Parser::Token_res _68;
	::Parser::bool_t success_69 = false;
	::Parser::Token_res _70;
	::Parser::bool_t success_71 = false;
	::Parser::Token_res _72;
	::Parser::bool_t success_73 = false;
	::Parser::Token_res _74;
	::Parser::bool_t success_75 = false;
	::Parser::Token_res _76;
	::Parser::bool_t success_77 = false;
	::Parser::Token_res _78;
	::Parser::bool_t success_79 = false;
	::Parser::Token_res _80;
	::Parser::bool_t success_81 = false;
	::Parser::Token_res _82;
	::Parser::bool_t success_83 = false;
	::Parser::Token_res _84;
	::Parser::bool_t success_85 = false;
	::Parser::Token_res _86;
	::Parser::bool_t success_87 = false;
	::Parser::Token_res _88;
	::Parser::bool_t success_89 = false;
	::Parser::Token_res _90;
	::Parser::bool_t success_91 = false;
	::Parser::Token_res _92;
	::Parser::bool_t success_93 = false;
	::Parser::Token_res _94;
	::Parser::bool_t success_95 = false;
	::Parser::Token_res _96;
	::Parser::bool_t success_97 = false;
	::Parser::Token_res _98;
	::Parser::bool_t success_99 = false;
	::Parser::Token_res _100;
	::Parser::bool_t success_101 = false;
	::Parser::Token_res _102;
	::Parser::bool_t success_103 = false;
	::Parser::Token_res _104;
	::Parser::bool_t success_105 = false;
	::Parser::Token_res _106;
	::Parser::bool_t success_107 = false;
	::Parser::Token_res _108;
	::Parser::bool_t success_109 = false;
	::Parser::Token_res _110;
	::Parser::bool_t success_111 = false;
	::Parser::Token_res _112;
	::Parser::bool_t success_113 = false;
	::Parser::Token_res _114;
	::Parser::bool_t success_115 = false;
	::Parser::Token_res _116;
	::Parser::bool_t success_117 = false;
	_2 = cll_OP(_in);
	if (!(_2.status))
	{
		_4 = cll_ASSIGNMENT_OP(_in);
		if (!(_4.status))
		{
			_6 = cll_COMPARE_OP(_in);
			if (!(_6.status))
			{
				_8 = cll_LOGICAL_OP(_in);
				if (!(_8.status))
				{
					_10 = cll_LOGICAL_NOT(_in);
					if (!(_10.status))
					{
						_12 = cll_LOGICAL_AND(_in);
						if (!(_12.status))
						{
							_14 = cll_LOGICAL_OR(_in);
							if (!(_14.status))
							{
								_16 = AUTO_42(_in);
								if (!(_16.status))
								{
									_18 = AUTO_43(_in);
									if (!(_18.status))
									{
										_20 = AUTO_44(_in);
										if (!(_20.status))
										{
											_22 = AUTO_27(_in);
											if (!(_22.status))
											{
												_24 = AUTO_45(_in);
												if (!(_24.status))
												{
													_26 = AUTO_1(_in);
													if (!(_26.status))
													{
														_28 = AUTO_46(_in);
														if (!(_28.status))
														{
															_30 = AUTO_2(_in);
															if (!(_30.status))
															{
																_32 = AUTO_3(_in);
																if (!(_32.status))
																{
																	_34 = AUTO_4(_in);
																	if (!(_34.status))
																	{
																		_36 = AUTO_5(_in);
																		if (!(_36.status))
																		{
																			_38 = AUTO_6(_in);
																			if (!(_38.status))
																			{
																				_40 = AUTO_7(_in);
																				if (!(_40.status))
																				{
																					_42 = AUTO_28(_in);
																					if (!(_42.status))
																					{
																						_44 = AUTO_47(_in);
																						if (!(_44.status))
																						{
																							_46 = LINEAR_COMMENT(_in);
																							if (!(_46.status))
																							{
																								_48 = Rule_ESCAPED(_in);
																								if (!(_48.status))
																								{
																									_50 = Rule_HEX(_in);
																									if (!(_50.status))
																									{
																										_52 = Rule_BIN(_in);
																										if (!(_52.status))
																										{
																											_54 = AUTO_9(_in);
																											if (!(_54.status))
																											{
																												_56 = AUTO_14(_in);
																												if (!(_56.status))
																												{
																													_58 = AUTO_15(_in);
																													if (!(_58.status))
																													{
																														_60 = AUTO_22(_in);
																														if (!(_60.status))
																														{
																															_62 = Rule_OP(_in);
																															if (!(_62.status))
																															{
																																_64 = AUTO_0(_in);
																																if (!(_64.status))
																																{
																																	_66 = AUTO_33(_in);
																																	if (!(_66.status))
																																	{
																																		_68 = AUTO_35(_in);
																																		if (!(_68.status))
																																		{
																																			_70 = AUTO_40(_in);
																																			if (!(_70.status))
																																			{
																																				_72 = AUTO_48(_in);
																																				if (!(_72.status))
																																				{
																																					_74 = AUTO_51(_in);
																																					if (!(_74.status))
																																					{
																																						_76 = AUTO_52(_in);
																																						if (!(_76.status))
																																						{
																																							_78 = AUTO_53(_in);
																																							if (!(_78.status))
																																							{
																																								_80 = AUTO_54(_in);
																																								if (!(_80.status))
																																								{
																																									_82 = AUTO_55(_in);
																																									if (!(_82.status))
																																									{
																																										_84 = AUTO_56(_in);
																																										if (!(_84.status))
																																										{
																																											_86 = AUTO_57(_in);
																																											if (!(_86.status))
																																											{
																																												_88 = AUTO_59(_in);
																																												if (!(_88.status))
																																												{
																																													_90 = __WHITESPACE(_in);
																																													if (!(_90.status))
																																													{
																																														_92 = NUMBER(_in);
																																														if (!(_92.status))
																																														{
																																															_94 = END(_in);
																																															if (!(_94.status))
																																															{
																																																_96 = AUTO_58(_in);
																																																if (!(_96.status))
																																																{
																																																	_98 = NEWLINE(_in);
																																																	if (!(_98.status))
																																																	{
																																																		_100 = STRING(_in);
																																																		if (!(_100.status))
																																																		{
																																																			_102 = BOOLEAN(_in);
																																																			if (!(_102.status))
																																																			{
																																																				_104 = ID(_in);
																																																				if (!(_104.status))
																																																				{
																																																					_106 = Rule_QUANITIFIER(_in);
																																																					if (!(_106.status))
																																																					{
																																																						_108 = Rule_CSEQUENCE_SYMBOL(_in);
																																																						if (!(_108.status))
																																																						{
																																																							_110 = Rule_CSEQUENCE_ESCAPE(_in);
																																																							if (!(_110.status))
																																																							{
																																																								_112 = Rule_CSEQUENCE(_in);
																																																								if (!(_112.status))
																																																								{
																																																									_114 = Rule_ANY(_in);
																																																									if (!(_114.status))
																																																									{
																																																										_116 = Rule_CSEQUENCE_DIAPASON(_in);
																																																										if (!(_116.status))
																																																										{
																																																											return {};
																																																										}
																																																										else 
																																																										{
																																																											success_117 = true;
																																																											_in += _116.node.length();
																																																											_0 = _116.node;
																																																										}
																																																									}
																																																									else 
																																																									{
																																																										success_115 = true;
																																																										_in += _114.node.length();
																																																										_0 = _114.node;
																																																									}
																																																								}
																																																								else 
																																																								{
																																																									success_113 = true;
																																																									_in += _112.node.length();
																																																									_0 = _112.node;
																																																								}
																																																							}
																																																							else 
																																																							{
																																																								success_111 = true;
																																																								_in += _110.node.length();
																																																								_0 = _110.node;
																																																							}
																																																						}
																																																						else 
																																																						{
																																																							success_109 = true;
																																																							_in += _108.node.length();
																																																							_0 = _108.node;
																																																						}
																																																					}
																																																					else 
																																																					{
																																																						success_107 = true;
																																																						_in += _106.node.length();
																																																						_0 = _106.node;
																																																					}
																																																				}
																																																				else 
																																																				{
																																																					success_105 = true;
																																																					_in += _104.node.length();
																																																					_0 = _104.node;
																																																				}
																																																			}
																																																			else 
																																																			{
																																																				success_103 = true;
																																																				_in += _102.node.length();
																																																				_0 = _102.node;
																																																			}
																																																		}
																																																		else 
																																																		{
																																																			success_101 = true;
																																																			_in += _100.node.length();
																																																			_0 = _100.node;
																																																		}
																																																	}
																																																	else 
																																																	{
																																																		success_99 = true;
																																																		_in += _98.node.length();
																																																		_0 = _98.node;
																																																	}
																																																}
																																																else 
																																																{
																																																	success_97 = true;
																																																	_in += _96.node.length();
																																																	_0 = _96.node;
																																																}
																																															}
																																															else 
																																															{
																																																success_95 = true;
																																																_in += _94.node.length();
																																																_0 = _94.node;
																																															}
																																														}
																																														else 
																																														{
																																															success_93 = true;
																																															_in += _92.node.length();
																																															_0 = _92.node;
																																														}
																																													}
																																													else 
																																													{
																																														success_91 = true;
																																														_in += _90.node.length();
																																														_0 = _90.node;
																																													}
																																												}
																																												else 
																																												{
																																													success_89 = true;
																																													_in += _88.node.length();
																																													_0 = _88.node;
																																												}
																																											}
																																											else 
																																											{
																																												success_87 = true;
																																												_in += _86.node.length();
																																												_0 = _86.node;
																																											}
																																										}
																																										else 
																																										{
																																											success_85 = true;
																																											_in += _84.node.length();
																																											_0 = _84.node;
																																										}
																																									}
																																									else 
																																									{
																																										success_83 = true;
																																										_in += _82.node.length();
																																										_0 = _82.node;
																																									}
																																								}
																																								else 
																																								{
																																									success_81 = true;
																																									_in += _80.node.length();
																																									_0 = _80.node;
																																								}
																																							}
																																							else 
																																							{
																																								success_79 = true;
																																								_in += _78.node.length();
																																								_0 = _78.node;
																																							}
																																						}
																																						else 
																																						{
																																							success_77 = true;
																																							_in += _76.node.length();
																																							_0 = _76.node;
																																						}
																																					}
																																					else 
																																					{
																																						success_75 = true;
																																						_in += _74.node.length();
																																						_0 = _74.node;
																																					}
																																				}
																																				else 
																																				{
																																					success_73 = true;
																																					_in += _72.node.length();
																																					_0 = _72.node;
																																				}
																																			}
																																			else 
																																			{
																																				success_71 = true;
																																				_in += _70.node.length();
																																				_0 = _70.node;
																																			}
																																		}
																																		else 
																																		{
																																			success_69 = true;
																																			_in += _68.node.length();
																																			_0 = _68.node;
																																		}
																																	}
																																	else 
																																	{
																																		success_67 = true;
																																		_in += _66.node.length();
																																		_0 = _66.node;
																																	}
																																}
																																else 
																																{
																																	success_65 = true;
																																	_in += _64.node.length();
																																	_0 = _64.node;
																																}
																															}
																															else 
																															{
																																success_63 = true;
																																_in += _62.node.length();
																																_0 = _62.node;
																															}
																														}
																														else 
																														{
																															success_61 = true;
																															_in += _60.node.length();
																															_0 = _60.node;
																														}
																													}
																													else 
																													{
																														success_59 = true;
																														_in += _58.node.length();
																														_0 = _58.node;
																													}
																												}
																												else 
																												{
																													success_57 = true;
																													_in += _56.node.length();
																													_0 = _56.node;
																												}
																											}
																											else 
																											{
																												success_55 = true;
																												_in += _54.node.length();
																												_0 = _54.node;
																											}
																										}
																										else 
																										{
																											success_53 = true;
																											_in += _52.node.length();
																											_0 = _52.node;
																										}
																									}
																									else 
																									{
																										success_51 = true;
																										_in += _50.node.length();
																										_0 = _50.node;
																									}
																								}
																								else 
																								{
																									success_49 = true;
																									_in += _48.node.length();
																									_0 = _48.node;
																								}
																							}
																							else 
																							{
																								success_47 = true;
																								_in += _46.node.length();
																								_0 = _46.node;
																							}
																						}
																						else 
																						{
																							success_45 = true;
																							_in += _44.node.length();
																							_0 = _44.node;
																						}
																					}
																					else 
																					{
																						success_43 = true;
																						_in += _42.node.length();
																						_0 = _42.node;
																					}
																				}
																				else 
																				{
																					success_41 = true;
																					_in += _40.node.length();
																					_0 = _40.node;
																				}
																			}
																			else 
																			{
																				success_39 = true;
																				_in += _38.node.length();
																				_0 = _38.node;
																			}
																		}
																		else 
																		{
																			success_37 = true;
																			_in += _36.node.length();
																			_0 = _36.node;
																		}
																	}
																	else 
																	{
																		success_35 = true;
																		_in += _34.node.length();
																		_0 = _34.node;
																	}
																}
																else 
																{
																	success_33 = true;
																	_in += _32.node.length();
																	_0 = _32.node;
																}
															}
															else 
															{
																success_31 = true;
																_in += _30.node.length();
																_0 = _30.node;
															}
														}
														else 
														{
															success_29 = true;
															_in += _28.node.length();
															_0 = _28.node;
														}
													}
													else 
													{
														success_27 = true;
														_in += _26.node.length();
														_0 = _26.node;
													}
												}
												else 
												{
													success_25 = true;
													_in += _24.node.length();
													_0 = _24.node;
												}
											}
											else 
											{
												success_23 = true;
												_in += _22.node.length();
												_0 = _22.node;
											}
										}
										else 
										{
											success_21 = true;
											_in += _20.node.length();
											_0 = _20.node;
										}
									}
									else 
									{
										success_19 = true;
										_in += _18.node.length();
										_0 = _18.node;
									}
								}
								else 
								{
									success_17 = true;
									_in += _16.node.length();
									_0 = _16.node;
								}
							}
							else 
							{
								success_15 = true;
								_in += _14.node.length();
								_0 = _14.node;
							}
						}
						else 
						{
							success_13 = true;
							_in += _12.node.length();
							_0 = _12.node;
						}
					}
					else 
					{
						success_11 = true;
						_in += _10.node.length();
						_0 = _10.node;
					}
				}
				else 
				{
					success_9 = true;
					_in += _8.node.length();
					_0 = _8.node;
				}
			}
			else 
			{
				success_7 = true;
				_in += _6.node.length();
				_0 = _6.node;
			}
		}
		else 
		{
			success_5 = true;
			_in += _4.node.length();
			_0 = _4.node;
		}
	}
	else 
	{
		success_3 = true;
		_in += _2.node.length();
		_0 = _2.node;
	}
	success_1 = true;
	ISPA_STD::skip_spaces(_in);
	return _0;
}
Parser::Token_res Parser::Tokenizator::cll_OP(const char* pos) {
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
						return {};
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
			_4 += ::Parser::str_t(pos, 1);
			success_5 = true;
			pos += 1;
			_0 += _4;
		}
	}
	else 
	{
		_2 += ::Parser::str_t(pos, 1);
		success_3 = true;
		pos += 1;
		_0 += _2;
	}
	success_1 = true;
	cll_OP_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::cll_OP, data)};
}
Parser::Token_res Parser::Tokenizator::cll_ASSIGNMENT_OP(const char* pos) {
	auto in = pos;
	::Parser::Token_res _0;
	::Parser::bool_t success_1 = false;
	::Parser::str_t _2;
	::Parser::bool_t success_3 = false;
	_0 = cll_OP(pos);
	if (_0.status)
	{
		success_1 = true;
		pos += _0.node.length();
	}
	ISPA_STD::skip_spaces(pos);
	if (!(*(pos + 0) == '='))
	{
		return {};
	}
	_2 += ::Parser::str_t(pos, 1);
	success_3 = true;
	pos += 1;
	cll_ASSIGNMENT_OP_data data = _0.node;
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::cll_ASSIGNMENT_OP, data)};
}
Parser::Token_res Parser::Tokenizator::cll_COMPARE_OP(const char* pos) {
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
	cll_COMPARE_OP_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::cll_COMPARE_OP, data)};
}
Parser::Token_res Parser::Tokenizator::cll_LOGICAL_OP(const char* pos) {
	auto in = pos;
	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	::Parser::Token_res _2;
	::Parser::bool_t success_3 = false;
	::Parser::Token_res _4;
	::Parser::bool_t success_5 = false;
	_2 = cll_LOGICAL_AND(pos);
	if (!(_2.status))
	{
		_4 = cll_LOGICAL_OR(pos);
		if (!(_4.status))
		{
			return {};
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
	cll_LOGICAL_OP_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::cll_LOGICAL_OP, data)};
}
Parser::Token_res Parser::Tokenizator::cll_LOGICAL_NOT(const char* pos) {
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
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::cll_LOGICAL_NOT)};
}
Parser::Token_res Parser::Tokenizator::cll_LOGICAL_AND(const char* pos) {
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
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::cll_LOGICAL_AND)};
}
Parser::Token_res Parser::Tokenizator::cll_LOGICAL_OR(const char* pos) {
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
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::cll_LOGICAL_OR)};
}
Parser::Rule_res Parser::Parser::cll_type(::Parser::arr_t<Token>::iterator pos) {
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
	if (!(begin_28->name() == Tokens::AUTO_1))
	{
		if (!(begin_28->name() == Tokens::AUTO_2))
		{
			if (!(begin_28->name() == Tokens::AUTO_3))
			{
				if (!(begin_28->name() == Tokens::AUTO_4))
				{
					if (!(begin_28->name() == Tokens::AUTO_5))
					{
						auto begin_20 = begin_28;
						do
						{
							if (!(begin_20->name() == Tokens::AUTO_6))
							{
								break;
							}
							_16 = *begin_20;
							success_17 = true;
							begin_20++;
							ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
							_18 = cll_cll_template(begin_20);
							if (!(_18.status))
							{
								break;
							}
							success_19 = true;
							std::advance(begin_20, _18.node.length());
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
								if (!(begin_27->name() == Tokens::AUTO_7))
								{
									break;
								}
								_23 = *begin_27;
								success_24 = true;
								begin_27++;
								ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
								_25 = cll_cll_template(begin_27);
								if (!(_25.status))
								{
									break;
								}
								success_26 = true;
								std::advance(begin_27, _25.node.length());
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
	cll_type_data data;
	data.templ = _23;
	data.type = _16;

	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), Rules::cll_type, data)};
}
Parser::Rule_res Parser::Parser::cll_cll_template(::Parser::arr_t<Token>::iterator pos) {
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
	if (!(_0.status))
	{
		return {};
	}
	success_1 = true;
	std::advance(pos, _0.node.length());
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	auto begin_10 = pos;
	while (1)
	{
		if (!(begin_10->name() == Tokens::AUTO_48))
		{
			break;
		}
		_4 = *begin_10;
		success_5 = true;
		begin_10++;
		shadow_6.push_back(_4);
		ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
		_7 = cll_type(begin_10);
		if (!(_7.status))
		{
			break;
		}
		success_8 = true;
		std::advance(begin_10, _7.node.length());
		shadow_9.push_back(_7.node);
	}
	if (success_5 && success_8)
	{
		success_3 = true;
		pos = begin_10;
	}
	cll_cll_template_data data;
	data.second = shadow_9;
	data.first = _0.node;

	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), Rules::cll_cll_template, data)};
}
Parser::Rule_res Parser::Parser::cll_if(::Parser::arr_t<Token>::iterator pos) {
	auto in = pos;
	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	::Parser::Rule_res _2;
	::Parser::bool_t success_3 = false;
	::Parser::Rule_res _4;
	::Parser::bool_t success_5 = false;
	if (!(pos->name() == Tokens::AUTO_9))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos++;
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	_2 = cll_expr(pos);
	if (!(_2.status))
	{
		return {};
	}
	success_3 = true;
	std::advance(pos, _2.node.length());
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	_4 = cll_block(pos);
	if (!(_4.status))
	{
		return {};
	}
	success_5 = true;
	std::advance(pos, _4.node.length());
	cll_if_data data;
	data.block = _4.node;
	data.expr = _2.node;

	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), Rules::cll_if, data)};
}
Parser::Rule_res Parser::Parser::cll_variable(::Parser::arr_t<Token>::iterator pos) {
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
		if (!(begin_8->name() == Tokens::AUTO_14))
		{
			if (!(begin_8->name() == Tokens::AUTO_15))
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
	if (!(pos->name() == Tokens::ID))
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
		if (!(begin_19->name() == Tokens::AUTO_33))
		{
			break;
		}
		_13 = *begin_19;
		success_14 = true;
		begin_19++;
		ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
		_15 = cll_expr(begin_19);
		if (!(_15.status))
		{
			break;
		}
		success_16 = true;
		std::advance(begin_19, _15.node.length());
		ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
		if (!(begin_19->name() == Tokens::AUTO_35))
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
		if (!(begin_28->name() == Tokens::AUTO_14))
		{
			if (!(begin_28->name() == Tokens::AUTO_15))
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
	cll_variable_data data;
	data.post = _20;
	data.pre = _0;
	data.brace_expression = _15.node;
	data.name = _0;

	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), Rules::cll_variable, data)};
}
Parser::Rule_res Parser::Parser::cll_function_body_call(::Parser::arr_t<Token>::iterator pos) {
	auto in = pos;
	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	::Parser::Rule_res _2;
	::Parser::bool_t success_3 = false;
	::Parser::Token _4;
	::Parser::bool_t success_5 = false;
	if (!(pos->name() == Tokens::AUTO_53))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos++;
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	_2 = cll_function_arguments(pos);
	if (!(_2.status))
	{
		return {};
	}
	success_3 = true;
	std::advance(pos, _2.node.length());
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name() == Tokens::AUTO_54))
	{
		return {};
	}
	_4 = *pos;
	success_5 = true;
	pos++;
	cll_function_body_call_data data = _2.node;
	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), Rules::cll_function_body_call, data)};
}
Parser::Rule_res Parser::Parser::cll_function_body_decl(::Parser::arr_t<Token>::iterator pos) {
	auto in = pos;
	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	::Parser::Rule_res _2;
	::Parser::bool_t success_3 = false;
	::Parser::Token _4;
	::Parser::bool_t success_5 = false;
	if (!(pos->name() == Tokens::AUTO_53))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos++;
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	_2 = cll_function_parameters(pos);
	if (!(_2.status))
	{
		return {};
	}
	success_3 = true;
	std::advance(pos, _2.node.length());
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name() == Tokens::AUTO_54))
	{
		return {};
	}
	_4 = *pos;
	success_5 = true;
	pos++;
	cll_function_body_decl_data data = _2.node;
	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), Rules::cll_function_body_decl, data)};
}
Parser::Rule_res Parser::Parser::cll_function_arguments(::Parser::arr_t<Token>::iterator pos) {
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
	if (!(_4.status))
	{
		if (!(begin_17->name() == Tokens::ID))
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
		std::advance(begin_17, _4.node.length());
		_2 = _4.node;
	}
	success_3 = true;
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	auto begin_15 = begin_17;
	while (1)
	{
		if (!(begin_15->name() == Tokens::AUTO_48))
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
	cll_function_arguments_data data;
	data.second = shadow_16;
	data.first = _2;

	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), Rules::cll_function_arguments, data)};
}
Parser::Rule_res Parser::Parser::cll_function_parameters(::Parser::arr_t<Token>::iterator pos) {
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
	if (!(begin_13->name() == Tokens::ID))
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
		if (!(begin_12->name() == Tokens::AUTO_48))
		{
			break;
		}
		_6 = *begin_12;
		success_7 = true;
		begin_12++;
		shadow_8.push_back(_6);
		ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
		if (!(begin_12->name() == Tokens::ID))
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
	cll_function_parameters_data data;
	data.second = shadow_11;
	data.first = _2;

	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), Rules::cll_function_parameters, data)};
}
Parser::Rule_res Parser::Parser::cll_cll_function_call(::Parser::arr_t<Token>::iterator pos) {
	auto in = pos;
	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	::Parser::Rule_res _2;
	::Parser::bool_t success_3 = false;
	if (!(pos->name() == Tokens::ID))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos++;
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	_2 = cll_function_body_call(pos);
	if (!(_2.status))
	{
		return {};
	}
	success_3 = true;
	std::advance(pos, _2.node.length());
	cll_cll_function_call_data data;
	data.body = _2.node;
	data.name = _0;

	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), Rules::cll_cll_function_call, data)};
}
Parser::Rule_res Parser::Parser::cll_function_decl(::Parser::arr_t<Token>::iterator pos) {
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
	if (!(pos->name() == Tokens::AUTO_22))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos++;
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	auto begin_8 = pos;
	while (begin_8->name() == Tokens::ID)
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
	_9 = cll_function_body_decl(pos);
	if (!(_9.status))
	{
		return {};
	}
	success_10 = true;
	std::advance(pos, _9.node.length());
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	auto begin_14 = pos;
	do
	{
		_12 = cll_block(begin_14);
		if (!(_12.status))
		{
			break;
		}
		success_13 = true;
		std::advance(begin_14, _12.node.length());
		val = _12.node;
	}
	while(0)
;
	if (success_13)
	{
		success_11 = true;
		pos = begin_14;
	}
	cll_function_decl_data data;
	data.value = val;
	data.name = _2;
	data.type = shadow_6;

	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), Rules::cll_function_decl, data)};
}
Parser::Rule_res Parser::Parser::cll_expr_logical(::Parser::arr_t<Token>::iterator pos) {
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
	_2 = cll_expr_compare(pos);
	if (!(_2.status))
	{
		_4 = cll_expr_arithmetic(pos);
		if (!(_4.status))
		{
			_6 = cll_expr_value(pos);
			if (!(_6.status))
			{
				return {};
			}
			else 
			{
				success_7 = true;
				std::advance(pos, _6.node.length());
				_0 = _6.node;
			}
		}
		else 
		{
			success_5 = true;
			std::advance(pos, _4.node.length());
			_0 = _4.node;
		}
	}
	else 
	{
		success_3 = true;
		std::advance(pos, _2.node.length());
		_0 = _2.node;
	}
	success_1 = true;
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name() == Tokens::cll_LOGICAL_OP))
	{
		return {};
	}
	_8 = *pos;
	success_9 = true;
	pos++;
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	_12 = cll_expr_compare(pos);
	if (!(_12.status))
	{
		_14 = cll_expr_arithmetic(pos);
		if (!(_14.status))
		{
			_16 = cll_expr_value(pos);
			if (!(_16.status))
			{
				return {};
			}
			else 
			{
				success_17 = true;
				std::advance(pos, _16.node.length());
				_10 = _16.node;
			}
		}
		else 
		{
			success_15 = true;
			std::advance(pos, _14.node.length());
			_10 = _14.node;
		}
	}
	else 
	{
		success_13 = true;
		std::advance(pos, _12.node.length());
		_10 = _12.node;
	}
	success_11 = true;
	cll_expr_logical_data data;
	data.right = _10;
	data.op = _8;
	data.left = _0;

	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), Rules::cll_expr_logical, data)};
}
Parser::Rule_res Parser::Parser::cll_expr_compare(::Parser::arr_t<Token>::iterator pos) {
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
	_0 = cll_expr_arithmetic(pos);
	if (!(_0.status))
	{
		return {};
	}
	success_1 = true;
	std::advance(pos, _0.node.length());
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	auto begin_10 = pos;
	while (1)
	{
		if (!(begin_10->name() == Tokens::cll_COMPARE_OP))
		{
			break;
		}
		_4 = *begin_10;
		success_5 = true;
		begin_10++;
		shadow_6.push_back(_4);
		ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
		_7 = cll_expr_arithmetic(begin_10);
		if (!(_7.status))
		{
			break;
		}
		success_8 = true;
		std::advance(begin_10, _7.node.length());
		shadow_9.push_back(_7.node);
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
	cll_expr_compare_data data;
	data.sequence = shadow_9;
	data.operators = shadow_6;
	data.first = _0.node;

	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), Rules::cll_expr_compare, data)};
}
Parser::Rule_res Parser::Parser::cll_expr_arithmetic(::Parser::arr_t<Token>::iterator pos) {
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
	_0 = cll_expr_value(pos);
	if (!(_0.status))
	{
		return {};
	}
	success_1 = true;
	std::advance(pos, _0.node.length());
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	auto begin_10 = pos;
	while (1)
	{
		if (!(begin_10->name() == Tokens::cll_OP))
		{
			break;
		}
		_4 = *begin_10;
		success_5 = true;
		begin_10++;
		shadow_6.push_back(_4);
		ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
		_7 = cll_expr_value(begin_10);
		if (!(_7.status))
		{
			return {};
		}
		success_8 = true;
		std::advance(begin_10, _7.node.length());
		shadow_9.push_back(_7.node);
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
	cll_expr_arithmetic_data data;
	data.sequence = shadow_9;
	data.operators = shadow_6;
	data.first = _0.node;

	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), Rules::cll_expr_arithmetic, data)};
}
Parser::Rule_res Parser::Parser::cll_expr_value(::Parser::arr_t<Token>::iterator pos) {
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
	_2 = cll_expr_group(pos);
	if (!(_2.status))
	{
		_4 = cll_variable(pos);
		if (!(_4.status))
		{
			_6 = cll_cll_function_call(pos);
			if (!(_6.status))
			{
				_8 = any_data(pos);
				if (!(_8.status))
				{
					return {};
				}
				else 
				{
					success_9 = true;
					std::advance(pos, _8.node.length());
					_0 = _8.node;
				}
			}
			else 
			{
				success_7 = true;
				std::advance(pos, _6.node.length());
				_0 = _6.node;
			}
		}
		else 
		{
			success_5 = true;
			std::advance(pos, _4.node.length());
			_0 = _4.node;
		}
	}
	else 
	{
		success_3 = true;
		std::advance(pos, _2.node.length());
		_0 = _2.node;
	}
	success_1 = true;
	cll_expr_value_data data = _0;
	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), Rules::cll_expr_value, data)};
}
Parser::Rule_res Parser::Parser::cll_expr_group(::Parser::arr_t<Token>::iterator pos) {
	auto in = pos;
	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	::Parser::Rule_res _2;
	::Parser::bool_t success_3 = false;
	::Parser::Token _4;
	::Parser::bool_t success_5 = false;
	if (!(pos->name() == Tokens::AUTO_53))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos++;
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	_2 = cll_expr(pos);
	if (!(_2.status))
	{
		return {};
	}
	success_3 = true;
	std::advance(pos, _2.node.length());
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name() == Tokens::AUTO_54))
	{
		return {};
	}
	_4 = *pos;
	success_5 = true;
	pos++;
	cll_expr_group_data data = _2.node;
	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), Rules::cll_expr_group, data)};
}
Parser::Rule_res Parser::Parser::cll_expr(::Parser::arr_t<Token>::iterator pos) {
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
	_2 = cll_expr_logical(pos);
	if (!(_2.status))
	{
		_4 = cll_expr_compare(pos);
		if (!(_4.status))
		{
			_6 = cll_expr_arithmetic(pos);
			if (!(_6.status))
			{
				_8 = cll_expr_group(pos);
				if (!(_8.status))
				{
					_10 = cll_expr_value(pos);
					if (!(_10.status))
					{
						return {};
					}
					else 
					{
						success_11 = true;
						std::advance(pos, _10.node.length());
						_0 = _10.node;
					}
				}
				else 
				{
					success_9 = true;
					std::advance(pos, _8.node.length());
					_0 = _8.node;
				}
			}
			else 
			{
				success_7 = true;
				std::advance(pos, _6.node.length());
				_0 = _6.node;
			}
		}
		else 
		{
			success_5 = true;
			std::advance(pos, _4.node.length());
			_0 = _4.node;
		}
	}
	else 
	{
		success_3 = true;
		std::advance(pos, _2.node.length());
		_0 = _2.node;
	}
	success_1 = true;
	cll_expr_data data = _0;
	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), Rules::cll_expr, data)};
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
	::Parser::Rule_res _8;
	::Parser::bool_t success_9 = false;
	_0 = cll_type(pos);
	if (_0.status)
	{
		success_1 = true;
		std::advance(pos, _0.node.length());
	}
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name() == Tokens::ID))
	{
		return {};
	}
	_2 = *pos;
	success_3 = true;
	pos++;
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	auto begin_10 = pos;
	do
	{
		if (!(begin_10->name() == Tokens::cll_ASSIGNMENT_OP))
		{
			break;
		}
		_6 = *begin_10;
		success_7 = true;
		begin_10++;
		ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
		_8 = cll_expr(begin_10);
		if (!(_8.status))
		{
			break;
		}
		success_9 = true;
		std::advance(begin_10, _8.node.length());
	}
	while(0)
;
	if (success_7 && success_9)
	{
		success_5 = true;
		pos = begin_10;
	}
	cll_var_data data;
	data.value = _8.node;
	data.op = _6;
	data.id = _2;
	data.type = _0.node;

	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), Rules::cll_var, data)};
}
Parser::Rule_res Parser::Parser::cll_block(::Parser::arr_t<Token>::iterator pos) {
	auto in = pos;
	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	::Parser::Rule_res _2;
	::Parser::bool_t success_3 = false;
	::Parser::Token _4;
	::Parser::bool_t success_5 = false;
	if (!(pos->name() == Tokens::AUTO_56))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos++;
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	_2 = Rule_rule(pos);
	while (_2.status)
	{
		success_3 = true;
		std::advance(pos, _2.node.length());
		_2 = Rule_rule(pos);
	}
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name() == Tokens::AUTO_57))
	{
		return {};
	}
	_4 = *pos;
	success_5 = true;
	pos++;
	cll_block_data data = _2.node;
	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), Rules::cll_block, data)};
}
Parser::Rule_res Parser::Parser::cll_loop_while(::Parser::arr_t<Token>::iterator pos) {
	auto in = pos;
	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	::Parser::Rule_res _2;
	::Parser::bool_t success_3 = false;
	::Parser::Rule_res _4;
	::Parser::bool_t success_5 = false;
	if (!(pos->name() == Tokens::AUTO_27))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos++;
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	_2 = cll_expr(pos);
	if (!(_2.status))
	{
		return {};
	}
	success_3 = true;
	std::advance(pos, _2.node.length());
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	_4 = cll_block(pos);
	if (!(_4.status))
	{
		return {};
	}
	success_5 = true;
	std::advance(pos, _4.node.length());
	cll_loop_while_data data;
	data.block = _4.node;
	data.expr = _2.node;

	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), Rules::cll_loop_while, data)};
}
Parser::Rule_res Parser::Parser::cll_loop_for(::Parser::arr_t<Token>::iterator pos) {
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
	if (!(pos->name() == Tokens::AUTO_28))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos++;
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name() == Tokens::AUTO_53))
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
		_8 = cll_expr(begin_12);
		if (!(_8.status))
		{
			_10 = cll_var(begin_12);
			if (!(_10.status))
			{
				break;
			}
			else 
			{
				success_11 = true;
				std::advance(begin_12, _10.node.length());
				_6 = _10.node;
			}
		}
		else 
		{
			success_9 = true;
			std::advance(begin_12, _8.node.length());
			_6 = _8.node;
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
	if (!(pos->name() == Tokens::AUTO_40))
	{
		return {};
	}
	_13 = *pos;
	success_14 = true;
	pos++;
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	_15 = cll_expr(pos);
	if (_15.status)
	{
		success_16 = true;
		std::advance(pos, _15.node.length());
	}
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name() == Tokens::AUTO_40))
	{
		return {};
	}
	_17 = *pos;
	success_18 = true;
	pos++;
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	_19 = cll_expr(pos);
	if (_19.status)
	{
		success_20 = true;
		std::advance(pos, _19.node.length());
	}
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name() == Tokens::AUTO_54))
	{
		return {};
	}
	_21 = *pos;
	success_22 = true;
	pos++;
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	_23 = cll_block(pos);
	if (!(_23.status))
	{
		return {};
	}
	success_24 = true;
	std::advance(pos, _23.node.length());
	cll_loop_for_data data;
	data.block = _21;
	data.end = _17;
	data.cond = _13;
	data.decl = _6;

	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), Rules::cll_loop_for, data)};
}
Parser::Rule_res Parser::Parser::cll(::Parser::arr_t<Token>::iterator pos) {
	auto in = pos;
	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	::Parser::Rule _2;
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
	::Parser::Token _14;
	::Parser::bool_t success_15 = false;
	if (!(pos->name() == Tokens::AUTO_0))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos++;
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	_4 = cll_if(pos);
	if (!(_4.status))
	{
		_6 = cll_var(pos);
		if (!(_6.status))
		{
			_8 = cll_expr(pos);
			if (!(_8.status))
			{
				_10 = cll_loop_while(pos);
				if (!(_10.status))
				{
					_12 = cll_loop_for(pos);
					if (!(_12.status))
					{
						return {};
					}
					else 
					{
						success_13 = true;
						std::advance(pos, _12.node.length());
						_2 = _12.node;
					}
				}
				else 
				{
					success_11 = true;
					std::advance(pos, _10.node.length());
					_2 = _10.node;
				}
			}
			else 
			{
				success_9 = true;
				std::advance(pos, _8.node.length());
				_2 = _8.node;
			}
		}
		else 
		{
			success_7 = true;
			std::advance(pos, _6.node.length());
			_2 = _6.node;
		}
	}
	else 
	{
		success_5 = true;
		std::advance(pos, _4.node.length());
		_2 = _4.node;
	}
	success_3 = true;
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name() == Tokens::END))
	{
		return {};
	}
	_14 = *pos;
	success_15 = true;
	pos++;
	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), Rules::cll)};
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
	::Parser::str_t _13;
	::Parser::bool_t success_14 = false;
	auto begin_15 = pos;
	if (!(*(begin_15 + 0) == '\''))
	{
		return {};
	}
	_2 += ::Parser::str_t(begin_15, 1);
	success_3 = true;
	begin_15 += 1;
	ISPA_STD::skip_spaces(begin_15);
	auto begin_12 = begin_15;
	while (1)
	{
		if (!(!std::strncmp(begin_12, "\\'", 2)))
		{
			if (!(!(*(begin_12 + 0) == '\'' || *(begin_12 + 0) == '\0')))
			{
				break;
			}
			else 
			{
				_10 += ::Parser::str_t(begin_12, 1);
				success_11 = true;
				begin_12 += 1;
				_6 += _10;
			}
		}
		else 
		{
			_8 += ::Parser::str_t(begin_12, 2);
			success_9 = true;
			begin_12 += 2;
			_6 += _8;
		}
		success_7 = true;
		_4 += _6;
	}
	if (success_7)
	{
		success_5 = true;
		begin_15 = begin_12;
	}
	ISPA_STD::skip_spaces(begin_15);
	if (!(*(begin_15 + 0) == '\''))
	{
		return {};
	}
	_13 += ::Parser::str_t(begin_15, 1);
	success_14 = true;
	begin_15 += 1;
	_0 += _2;
	_0 += _4;
	_0 += _13;
	if (success_3 && success_14)
	{
		success_1 = true;
		pos = begin_15;
	}
	STRING_data data = _4;
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::STRING, data)};
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
			return {};
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

	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::NUMBER, data)};
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
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::BOOLEAN, data)};
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
	if (!(pos->name() == Tokens::AUTO_33))
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
			if (!(_6.status))
			{
				break;
			}
			success_7 = true;
			std::advance(begin_12, _6.node.length());
			shadow_8.push_back(_6.node);
			ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
			if (!(begin_12->name() == Tokens::AUTO_48))
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
	if (!(pos->name() == Tokens::AUTO_35))
	{
		return {};
	}
	_14 = *pos;
	success_15 = true;
	pos++;
	array_data data = shadow_11;
	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), Rules::array, data)};
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
	if (!(pos->name() == Tokens::AUTO_56))
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
		if (!(_4.status))
		{
			break;
		}
		success_5 = true;
		std::advance(begin_27, _4.node.length());
		ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
		if (!(begin_27->name() == Tokens::AUTO_59))
		{
			break;
		}
		_6 = *begin_27;
		success_7 = true;
		begin_27++;
		ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
		_8 = any_data(begin_27);
		if (!(_8.status))
		{
			break;
		}
		success_9 = true;
		std::advance(begin_27, _8.node.length());
		ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
		auto begin_24 = begin_27;
		while (1)
		{
			if (!(begin_24->name() == Tokens::AUTO_48))
			{
				break;
			}
			_12 = *begin_24;
			success_13 = true;
			begin_24++;
			shadow_14.push_back(_12);
			ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
			if (!(begin_24->name() == Tokens::ID))
			{
				break;
			}
			_15 = *begin_24;
			success_16 = true;
			begin_24++;
			shadow_17.push_back(_15);
			ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
			if (!(begin_24->name() == Tokens::AUTO_59))
			{
				break;
			}
			_18 = *begin_24;
			success_19 = true;
			begin_24++;
			shadow_20.push_back(_18);
			ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
			_21 = any_data(begin_24);
			if (!(_21.status))
			{
				break;
			}
			success_22 = true;
			std::advance(begin_24, _21.node.length());
			shadow_23.push_back(_21.node);
		}
		if (success_13 && success_16 && success_19 && success_22)
		{
			success_11 = true;
			begin_27 = begin_24;
		}
		ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
		if (!(begin_27->name() == Tokens::AUTO_40))
		{
			break;
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
	if (!(pos->name() == Tokens::AUTO_57))
	{
		return {};
	}
	_28 = *pos;
	success_29 = true;
	pos++;
	object_data data;
	data.values = shadow_23;
	data.keys = shadow_17;
	data.value = _8.node;
	data.key = _4.node;

	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), Rules::object, data)};
}
Parser::Rule_res Parser::Parser::any_data(::Parser::arr_t<Token>::iterator pos) {
	auto in = pos;
	::Parser::any_t _0;
	::Parser::bool_t success_1 = false;
	::Parser::Rule_res _2;
	::Parser::bool_t success_3 = false;
	::Parser::Rule_res _4;
	::Parser::bool_t success_5 = false;
	::Parser::Token _6;
	::Parser::bool_t success_7 = false;
	::Parser::Token _8;
	::Parser::bool_t success_9 = false;
	::Parser::Token _10;
	::Parser::bool_t success_11 = false;
	::Parser::Token _12;
	::Parser::bool_t success_13 = false;
	_2 = array(pos);
	if (!(_2.status))
	{
		_4 = object(pos);
		if (!(_4.status))
		{
			if (!(pos->name() == Tokens::NUMBER))
			{
				if (!(pos->name() == Tokens::BOOLEAN))
				{
					if (!(pos->name() == Tokens::STRING))
					{
						if (!(pos->name() == Tokens::ID))
						{
							return {};
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
						_10 = *pos;
						success_11 = true;
						pos++;
						_0 = _10;
					}
				}
				else 
				{
					_8 = *pos;
					success_9 = true;
					pos++;
					_0 = _8;
				}
			}
			else 
			{
				_6 = *pos;
				success_7 = true;
				pos++;
				_0 = _6;
			}
		}
		else 
		{
			success_5 = true;
			std::advance(pos, _4.node.length());
			_0 = _4.node;
		}
	}
	else 
	{
		success_3 = true;
		std::advance(pos, _2.node.length());
		_0 = _2.node;
	}
	success_1 = true;
	any_data_data data = _0;
	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), Rules::any_data, data)};
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
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::END)};
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
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::NEWLINE)};
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
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::LINEAR_COMMENT)};
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
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::ID, data)};
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
	if (!(pos->name() == Tokens::AUTO_42))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos++;
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name() == Tokens::AUTO_43))
	{
		if (!(pos->name() == Tokens::AUTO_44))
		{
			if (!(pos->name() == Tokens::AUTO_45))
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
	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), Rules::spacemode, data)};
}
Parser::Rule_res Parser::Parser::name(::Parser::arr_t<Token>::iterator pos) {
	auto in = pos;
	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	::Parser::Token _2;
	::Parser::bool_t success_3 = false;
	if (!(pos->name() == Tokens::AUTO_46))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos++;
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name() == Tokens::ID))
	{
		return {};
	}
	_2 = *pos;
	success_3 = true;
	pos++;
	name_data data = _2;
	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), Rules::name, data)};
}
Parser::Rule_res Parser::Parser::main(::Parser::arr_t<Token>::iterator pos) {
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
	_2 = spacemode(pos);
	if (!(_2.status))
	{
		_4 = name(pos);
		if (!(_4.status))
		{
			_6 = use(pos);
			if (!(_6.status))
			{
				_8 = Rule(pos);
				if (!(_8.status))
				{
					return {};
				}
				else 
				{
					success_9 = true;
					std::advance(pos, _8.node.length());
					_0 = _8.node;
				}
			}
			else 
			{
				success_7 = true;
				std::advance(pos, _6.node.length());
				_0 = _6.node;
			}
		}
		else 
		{
			success_5 = true;
			std::advance(pos, _4.node.length());
			_0 = _4.node;
		}
	}
	else 
	{
		success_3 = true;
		std::advance(pos, _2.node.length());
		_0 = _2.node;
	}
	success_1 = true;
	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), Rules::main)};
}
Parser::Rule_res Parser::Parser::use_unit(::Parser::arr_t<Token>::iterator pos) {
	auto in = pos;
	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	::Parser::Rule_res _2;
	::Parser::bool_t success_3 = false;
	if (!(pos->name() == Tokens::ID))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos++;
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	_2 = any_data(pos);
	if (_2.status)
	{
		success_3 = true;
		std::advance(pos, _2.node.length());
	}
	use_unit_data data;
	data.value = _2.node;
	data.name = _0;

	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), Rules::use_unit, data)};
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
	if (!(pos->name() == Tokens::AUTO_47))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos++;
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	_2 = use_unit(pos);
	if (!(_2.status))
	{
		return {};
	}
	success_3 = true;
	std::advance(pos, _2.node.length());
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	auto begin_12 = pos;
	while (1)
	{
		if (!(begin_12->name() == Tokens::AUTO_48))
		{
			break;
		}
		_6 = *begin_12;
		success_7 = true;
		begin_12++;
		shadow_8.push_back(_6);
		ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
		_9 = use_unit(begin_12);
		if (!(_9.status))
		{
			break;
		}
		success_10 = true;
		std::advance(begin_12, _9.node.length());
		shadow_11.push_back(_9.node);
	}
	if (success_7 && success_10)
	{
		success_5 = true;
		pos = begin_12;
	}
	use_data data;
	data.second = shadow_11;
	data.first = _2.node;

	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), Rules::use, data)};
}
Parser::Rule_res Parser::Parser::Rule_rule(::Parser::arr_t<Token>::iterator pos) {
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
	::Parser::Token _10;
	::Parser::bool_t success_11 = false;
	::Parser::Token _12;
	::Parser::bool_t success_13 = false;
	::Parser::Rule_res _14;
	::Parser::bool_t success_15 = false;
	::Parser::Rule_res _16;
	::Parser::bool_t success_17 = false;
	::Parser::Token _18;
	::Parser::bool_t success_19 = false;
	::Parser::Rule_res _20;
	::Parser::bool_t success_21 = false;
	::Parser::Token _22;
	::Parser::bool_t success_23 = false;
	::Parser::Token _24;
	::Parser::bool_t success_25 = false;
	if (!(pos->name() == Tokens::Rule_HEX))
	{
		if (!(pos->name() == Tokens::Rule_BIN))
		{
			if (!(pos->name() == Tokens::Rule_ESCAPED))
			{
				if (!(pos->name() == Tokens::Rule_ANY))
				{
					if (!(pos->name() == Tokens::cll_OP))
					{
						if (!(pos->name() == Tokens::LINEAR_COMMENT))
						{
							_14 = cll_expr_group(pos);
							if (!(_14.status))
							{
								_16 = Rule_name(pos);
								if (!(_16.status))
								{
									if (!(pos->name() == Tokens::Rule_CSEQUENCE))
									{
										_20 = cll(pos);
										if (!(_20.status))
										{
											if (!(pos->name() == Tokens::STRING))
											{
												return {};
											}
											else 
											{
												_22 = *pos;
												success_23 = true;
												pos++;
												_0 = _22;
											}
										}
										else 
										{
											success_21 = true;
											std::advance(pos, _20.node.length());
											_0 = _20.node;
										}
									}
									else 
									{
										_18 = *pos;
										success_19 = true;
										std::advance(pos, 1);
										_0 = _18;
									}
								}
								else 
								{
									success_17 = true;
									std::advance(pos, _16.node.length());
									_0 = _16.node;
								}
							}
							else 
							{
								success_15 = true;
								std::advance(pos, _14.node.length());
								_0 = _14.node;
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
						_10 = *pos;
						success_11 = true;
						std::advance(pos, 1);
						_0 = _10;
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
				pos++;
				_0 = _6;
			}
		}
		else 
		{
			_4 = *pos;
			success_5 = true;
			pos++;
			_0 = _4;
		}
	}
	else 
	{
		_2 = *pos;
		success_3 = true;
		pos++;
		_0 = _2;
	}
	success_1 = true;
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	if (pos->name() == Tokens::Rule_QUANITIFIER)
	{
		_24 = *pos;
		success_25 = true;
		pos++;
	}
	Rule_rule_data data;
	data.qualifier = _24;
	data.val = _0;

	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), Rules::Rule_rule, data)};
}
Parser::Rule_res Parser::Parser::Rule_name(::Parser::arr_t<Token>::iterator pos) {
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
	if (pos->name() == Tokens::AUTO_55)
	{
		_0 = *pos;
		success_1 = true;
		pos++;
	}
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name() == Tokens::ID))
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
		if (!(begin_12->name() == Tokens::AUTO_51))
		{
			break;
		}
		_6 = *begin_12;
		success_7 = true;
		begin_12++;
		shadow_8.push_back(_6);
		ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
		if (!(begin_12->name() == Tokens::ID))
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
	Rule_name_data data;
	data.nested_name = shadow_11;
	data.name = _2;
	data.is_nested = _0;

	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), Rules::Rule_name, data)};
}
Parser::Rule_res Parser::Parser::Rule_group(::Parser::arr_t<Token>::iterator pos) {
	auto in = pos;
	::Parser::bool_t success_1 = false;
	::Parser::Token _2;
	::Parser::bool_t success_3 = false;
	::Parser::Token _4;
	::Parser::bool_t success_5 = false;
	::Parser::Token _7;
	::Parser::bool_t success_8 = false;
	::Parser::Rule_res _9;
	::Parser::bool_t success_10 = false;
	::Parser::Token _11;
	::Parser::bool_t success_12 = false;
	auto begin_6 = pos;
	do
	{
		if (!(begin_6->name() == Tokens::AUTO_52))
		{
			return {};
		}
		_2 = *begin_6;
		success_3 = true;
		begin_6++;
		ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
		if (!(begin_6->name() == Tokens::ID))
		{
			break;
		}
		_4 = *begin_6;
		success_5 = true;
		begin_6++;
	}
	while(0)
;
	if (success_3 && success_5)
	{
		success_1 = true;
		pos = begin_6;
	}
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name() == Tokens::AUTO_53))
	{
		return {};
	}
	_7 = *pos;
	success_8 = true;
	pos++;
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	_9 = Rule_rule(pos);
	while (_9.status)
	{
		success_10 = true;
		std::advance(pos, _9.node.length());
		_9 = Rule_rule(pos);
	}
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name() == Tokens::AUTO_54))
	{
		return {};
	}
	_11 = *pos;
	success_12 = true;
	pos++;
	Rule_group_data data;
	data.val = _9.node;
	data.variable = _2;

	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), Rules::Rule_group, data)};
}
Parser::Rule_res Parser::Parser::Rule_nested_rule(::Parser::arr_t<Token>::iterator pos) {
	auto in = pos;
	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	::Parser::Rule _2;
	::Parser::bool_t success_3 = false;
	::Parser::Rule_res _4;
	::Parser::bool_t success_5 = false;
	if (!(pos->name() == Tokens::AUTO_55))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos++;
	auto begin_6 = pos;
	_4 = Rule(begin_6);
	if (!(_4.status))
	{
		return {};
	}
	success_5 = true;
	std::advance(begin_6, _4.node.length());
	_2 = _4.node;
	if (success_5)
	{
		success_3 = true;
		pos = begin_6;
	}
	Rule_nested_rule_data data = _2;
	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), Rules::Rule_nested_rule, data)};
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
	::Parser::Rule_res _11;
	::Parser::bool_t success_12 = false;
	while (pos->name() == Tokens::AUTO_58)
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
	if (!(begin_7->name() == Tokens::ID))
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
	if (!(pos->name() == Tokens::AUTO_59))
	{
		return {};
	}
	_8 = *pos;
	success_9 = true;
	pos++;
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	auto begin_13 = pos;
	_11 = cll_expr(begin_13);
	if (!(_11.status))
	{
		return {};
	}
	success_12 = true;
	std::advance(begin_13, _11.node.length());
	dt = _11.node;
	if (success_12)
	{
		success_10 = true;
		pos = begin_13;
	}
	Rule_data_block_key_data data;
	data.val = dt;
	data.name = name;

	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), Rules::Rule_data_block_key, data)};
}
Parser::Rule_res Parser::Parser::Rule_data_block(::Parser::arr_t<Token>::iterator pos) {
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
	if (!(pos->name() == Tokens::AUTO_56))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos++;
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	_4 = any_data(pos);
	if (!(_4.status))
	{
		_6 = Rule_data_block_key(pos);
		if (!(_6.status))
		{
			return {};
		}
		else 
		{
			success_7 = true;
			std::advance(pos, _6.node.length());
			_2 = _6.node;
		}
	}
	else 
	{
		success_5 = true;
		std::advance(pos, _4.node.length());
		_2 = _4.node;
	}
	success_3 = true;
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name() == Tokens::AUTO_57))
	{
		return {};
	}
	_8 = *pos;
	success_9 = true;
	pos++;
	Rule_data_block_data data = _2;
	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), Rules::Rule_data_block, data)};
}
Parser::Token_res Parser::Tokenizator::Rule_OP(const char* pos) {
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
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::Rule_OP)};
}
Parser::Token_res Parser::Tokenizator::Rule_QUANITIFIER(const char* pos) {
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
	auto begin_10 = pos;
	if (!(*(begin_10 + 0) == '?'))
	{
		if (!(*(begin_10 + 0) == '+'))
		{
			if (!(*(begin_10 + 0) == '*'))
			{
				return {};
			}
			else 
			{
				_8 += ::Parser::str_t(begin_10, 1);
				success_9 = true;
				begin_10 += 1;
				_2 += _8;
			}
		}
		else 
		{
			_6 += ::Parser::str_t(begin_10, 1);
			success_7 = true;
			begin_10 += 1;
			_2 += _6;
		}
	}
	else 
	{
		_4 += ::Parser::str_t(begin_10, 1);
		success_5 = true;
		begin_10 += 1;
		_2 += _4;
	}
	success_3 = true;
	_0 += _2;
	if (success_3)
	{
		success_1 = true;
		pos = begin_10;
	}
	Rule_QUANITIFIER_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::Rule_QUANITIFIER, data)};
}
Parser::Token_res Parser::Tokenizator::Rule_CSEQUENCE_SYMBOL(const char* pos) {
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
	auto begin_10 = pos;
	if (!(!std::strncmp(begin_10, "\\]", 2)))
	{
		if (!(!std::strncmp(begin_10, "\\", 1)))
		{
			if (!(!(*(begin_10 + 0) == ']' || *(begin_10 + 0) == '\0')))
			{
				return {};
			}
			else 
			{
				_8 += ::Parser::str_t(begin_10, 1);
				success_9 = true;
				begin_10 += 1;
				_2 += _8;
			}
		}
		else 
		{
			_6 += ::Parser::str_t(begin_10, 1);
			success_7 = true;
			begin_10 += 1;
			_2 += _6;
		}
	}
	else 
	{
		_4 += ::Parser::str_t(begin_10, 2);
		success_5 = true;
		begin_10 += 2;
		_2 += _4;
	}
	success_3 = true;
	_0 += _2;
	if (success_3)
	{
		success_1 = true;
		pos = begin_10;
	}
	Rule_CSEQUENCE_SYMBOL_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::Rule_CSEQUENCE_SYMBOL, data)};
}
Parser::Token_res Parser::Tokenizator::Rule_CSEQUENCE_ESCAPE(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	::Parser::str_t _2;
	::Parser::bool_t success_3 = false;
	::Parser::str_t _4;
	::Parser::bool_t success_5 = false;
	if (!(!std::strncmp(pos + 0, "\\", 1)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 1);
	success_1 = true;
	pos += 1;
	auto begin_6 = pos;
	if (*(begin_6 + 0) == '\0')
	{
		return {};
	}
	_4 += ::Parser::str_t(begin_6, 1);
	success_5 = true;
	begin_6 += 1;
	_2 += _4;
	if (success_5)
	{
		success_3 = true;
		pos = begin_6;
	}
	Rule_CSEQUENCE_ESCAPE_data data = _2;
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::Rule_CSEQUENCE_ESCAPE, data)};
}
Parser::Token_res Parser::Tokenizator::Rule_CSEQUENCE_DIAPASON(const char* pos) {
	auto in = pos;
	::Parser::bool_t success_1 = false;
	::Parser::Token from;
	::Parser::bool_t success_2 = false;
	::Parser::Token_res _3;
	::Parser::bool_t success_4 = false;
	::Parser::str_t _6;
	::Parser::bool_t success_7 = false;
	::Parser::Token to;
	::Parser::bool_t success_8 = false;
	::Parser::Token_res _9;
	::Parser::bool_t success_10 = false;
	auto begin_12 = pos;
	auto begin_5 = begin_12;
	_3 = Rule_CSEQUENCE_SYMBOL(begin_5);
	if (!(_3.status))
	{
		return {};
	}
	success_4 = true;
	begin_5 += _3.node.length();
	from = _3.node;
	if (success_4)
	{
		success_2 = true;
		begin_12 = begin_5;
	}
	if (!(*(begin_12 + 0) == '-'))
	{
		return {};
	}
	_6 += ::Parser::str_t(begin_12, 1);
	success_7 = true;
	begin_12 += 1;
	auto begin_11 = begin_12;
	_9 = Rule_CSEQUENCE_SYMBOL(begin_11);
	if (!(_9.status))
	{
		return {};
	}
	success_10 = true;
	begin_11 += _9.node.length();
	to = _9.node;
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
	Rule_CSEQUENCE_DIAPASON_data data = {from,to};
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::Rule_CSEQUENCE_DIAPASON, data)};
}
Parser::Token_res Parser::Tokenizator::Rule_CSEQUENCE(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	::Parser::str_t _2;
	::Parser::bool_t success_3 = false;
	::Parser::arr_t<::Parser::arr_t<::Parser::Token>> shadow_17;
	::Parser::arr_t<::Parser::Token> dt;
	::Parser::bool_t success_4 = false;
	::Parser::arr_t<::Parser::Token> _5;
	::Parser::bool_t success_6 = false;
	::Parser::Token_res _7;
	::Parser::bool_t success_8 = false;
	::Parser::arr_t<::Parser::Token> shadow_9;
	::Parser::Token_res _10;
	::Parser::bool_t success_11 = false;
	::Parser::arr_t<::Parser::Token> shadow_12;
	::Parser::Token_res _13;
	::Parser::bool_t success_14 = false;
	::Parser::arr_t<::Parser::Token> shadow_15;
	::Parser::str_t _18;
	::Parser::bool_t success_19 = false;
	if (!(*(pos + 0) == '['))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 1);
	success_1 = true;
	pos += 1;
	ISPA_STD::skip_spaces(pos);
	if (*(pos + 0) == '^')
	{
		_2 += ::Parser::str_t(pos, 1);
		success_3 = true;
		pos += 1;
	}
	ISPA_STD::skip_spaces(pos);
	auto begin_16 = pos;
	while (1)
	{
		_7 = Rule_CSEQUENCE_ESCAPE(begin_16);
		if (!(_7.status))
		{
			_10 = Rule_CSEQUENCE_SYMBOL(begin_16);
			if (!(_10.status))
			{
				_13 = Rule_CSEQUENCE_DIAPASON(begin_16);
				if (!(_13.status))
				{
					break;
				}
				else 
				{
					success_14 = true;
					begin_16 += _13.node.length();
					shadow_15.push_back(_13.node);
					_5.push_back(_13.node);
				}
			}
			else 
			{
				success_11 = true;
				begin_16 += _10.node.length();
				shadow_12.push_back(_10.node);
				_5.push_back(_10.node);
			}
		}
		else 
		{
			success_8 = true;
			begin_16 += _7.node.length();
			shadow_9.push_back(_7.node);
			_5.push_back(_7.node);
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
	ISPA_STD::skip_spaces(pos);
	if (!(*(pos + 0) == ']'))
	{
		return {};
	}
	_18 += ::Parser::str_t(pos, 1);
	success_19 = true;
	pos += 1;
	Rule_CSEQUENCE_data data;
	data.val = dt;
	data._not = _2;

	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::Rule_CSEQUENCE, data)};
}
Parser::Token_res Parser::Tokenizator::Rule_ANY(const char* pos) {
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
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::Rule_ANY)};
}
Parser::Token_res Parser::Tokenizator::Rule_ESCAPED(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	::Parser::str_t _2;
	::Parser::bool_t success_3 = false;
	::Parser::str_t _4;
	::Parser::bool_t success_5 = false;
	::Parser::Token_res _7;
	::Parser::bool_t success_8 = false;
	if (!(!std::strncmp(pos + 0, "\\", 1)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 1);
	success_1 = true;
	pos += 1;
	auto begin_6 = pos;
	if (*(begin_6 + 0) == '\0')
	{
		return {};
	}
	_4 += ::Parser::str_t(begin_6, 1);
	success_5 = true;
	begin_6 += 1;
	_2 += _4;
	if (success_5)
	{
		success_3 = true;
		pos = begin_6;
	}
	_7 = NUMBER(pos);
	if (_7.status)
	{
		success_8 = true;
		pos += _7.node.length();
	}
	Rule_ESCAPED_data data;
	data.num = _2;
	data.c = _2;

	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::Rule_ESCAPED, data)};
}
Parser::Token_res Parser::Tokenizator::Rule_HEX(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	::Parser::str_t _2;
	::Parser::bool_t success_3 = false;
	::Parser::bool_t success_4 = false;
	if (!(!std::strncmp(pos + 0, "0x", 2)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 2);
	success_1 = true;
	pos += 2;
	ISPA_STD::skip_spaces(pos);
	while ((*(pos + 0)>='0' && *(pos + 0)<='9') || (*(pos + 0)>='A' && *(pos + 0)<='F') || (*(pos + 0)>='a' && *(pos + 0)<='f'))
	{
		_2 += ::Parser::str_t(pos, 1);
		success_3 = true;
		pos += 1;
		success_4 = true;
	}
	if (!success_4)
	{
		return {};
	}
	Rule_HEX_data data = _2;
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::Rule_HEX, data)};
}
Parser::Token_res Parser::Tokenizator::Rule_BIN(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	::Parser::str_t _2;
	::Parser::bool_t success_3 = false;
	::Parser::bool_t success_4 = false;
	if (!(!std::strncmp(pos + 0, "0b", 2)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 2);
	success_1 = true;
	pos += 2;
	ISPA_STD::skip_spaces(pos);
	while (*(pos + 0) == '0' || *(pos + 0) == '1')
	{
		_2 += ::Parser::str_t(pos, 1);
		success_3 = true;
		pos += 1;
		success_4 = true;
	}
	if (!success_4)
	{
		return {};
	}
	Rule_BIN_data data = _2;
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::Rule_BIN, data)};
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
	if (!(pos->name() == Tokens::ID))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos++;
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name() == Tokens::AUTO_59))
	{
		return {};
	}
	_2 = *pos;
	success_3 = true;
	pos++;
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	_4 = Rule_rule(pos);
	while (_4.status)
	{
		success_5 = true;
		std::advance(pos, _4.node.length());
		_4 = Rule_rule(pos);
	}
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	_6 = Rule_data_block(pos);
	if (!(_6.status))
	{
		return {};
	}
	success_7 = true;
	std::advance(pos, _6.node.length());
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	_8 = Rule_nested_rule(pos);
	while (_8.status)
	{
		success_9 = true;
		std::advance(pos, _8.node.length());
		_8 = Rule_nested_rule(pos);
	}
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name() == Tokens::AUTO_40))
	{
		return {};
	}
	_10 = *pos;
	success_11 = true;
	pos++;
	Rule_data data;
	data.nestedRules = _8.node;
	data.data_block = _6.node;
	data.rule = _4.node;
	data.name = _0;

	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), Rules::Rule, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_0(const char* pos) {
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
	AUTO_0_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::AUTO_0, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_1(const char* pos) {
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
	AUTO_1_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::AUTO_1, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_2(const char* pos) {
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
	AUTO_2_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::AUTO_2, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_3(const char* pos) {
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
	AUTO_3_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::AUTO_3, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_4(const char* pos) {
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
	AUTO_4_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::AUTO_4, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_5(const char* pos) {
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
	AUTO_5_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::AUTO_5, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_6(const char* pos) {
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
	AUTO_6_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::AUTO_6, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_7(const char* pos) {
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
	AUTO_7_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::AUTO_7, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_9(const char* pos) {
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
	AUTO_9_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::AUTO_9, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_14(const char* pos) {
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
	AUTO_14_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::AUTO_14, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_15(const char* pos) {
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
	AUTO_15_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::AUTO_15, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_22(const char* pos) {
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
	AUTO_22_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::AUTO_22, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_27(const char* pos) {
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
	AUTO_27_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::AUTO_27, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_28(const char* pos) {
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
	AUTO_28_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::AUTO_28, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_33(const char* pos) {
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
	AUTO_33_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::AUTO_33, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_35(const char* pos) {
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
	AUTO_35_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::AUTO_35, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_40(const char* pos) {
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
	AUTO_40_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::AUTO_40, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_42(const char* pos) {
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
	AUTO_42_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::AUTO_42, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_43(const char* pos) {
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
	AUTO_43_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::AUTO_43, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_44(const char* pos) {
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
	AUTO_44_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::AUTO_44, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_45(const char* pos) {
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
	AUTO_45_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::AUTO_45, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_46(const char* pos) {
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
	AUTO_46_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::AUTO_46, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_47(const char* pos) {
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
	AUTO_47_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::AUTO_47, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_48(const char* pos) {
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
	AUTO_48_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::AUTO_48, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_51(const char* pos) {
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
	AUTO_51_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::AUTO_51, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_52(const char* pos) {
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
	AUTO_52_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::AUTO_52, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_53(const char* pos) {
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
	AUTO_53_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::AUTO_53, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_54(const char* pos) {
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
	AUTO_54_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::AUTO_54, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_55(const char* pos) {
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
	AUTO_55_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::AUTO_55, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_56(const char* pos) {
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
	AUTO_56_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::AUTO_56, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_57(const char* pos) {
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
	AUTO_57_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::AUTO_57, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_58(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == '\n' || *(pos + 0) == '\r'))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 1);
	success_1 = true;
	pos += 1;
	AUTO_58_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::AUTO_58, data)};
}
Parser::Token_res Parser::Tokenizator::AUTO_59(const char* pos) {
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
	AUTO_59_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::AUTO_59, data)};
}
Parser::Token_res Parser::Tokenizator::__WHITESPACE(const char* pos) {
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
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::__WHITESPACE)};
}
