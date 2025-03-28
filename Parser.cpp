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
	::Parser::Token_res _118;
	::Parser::bool_t success_119 = false;
	::Parser::Token_res _120;
	::Parser::bool_t success_121 = false;
	::Parser::Token_res _122;
	::Parser::bool_t success_123 = false;
	::Parser::Token_res _124;
	::Parser::bool_t success_125 = false;
	::Parser::Token_res _126;
	::Parser::bool_t success_127 = false;
	::Parser::Token_res _128;
	::Parser::bool_t success_129 = false;
	::Parser::Token_res _130;
	::Parser::bool_t success_131 = false;
	::Parser::Token_res _132;
	::Parser::bool_t success_133 = false;
	::Parser::Token_res _134;
	::Parser::bool_t success_135 = false;
	_2 = OP(_in);
	if (!(_2.status))
	{
		_4 = ASSIGNMENT_OP(_in);
		if (!(_4.status))
		{
			_6 = COMPARE_OP(_in);
			if (!(_6.status))
			{
				_8 = LOGICAL_OP(_in);
				if (!(_8.status))
				{
					_10 = STRING(_in);
					if (!(_10.status))
					{
						_12 = NUMBER(_in);
						if (!(_12.status))
						{
							_14 = AUTO_83(_in);
							if (!(_14.status))
							{
								_16 = AUTO_98(_in);
								if (!(_16.status))
								{
									_18 = AUTO_101(_in);
									if (!(_18.status))
									{
										_20 = AUTO_103(_in);
										if (!(_20.status))
										{
											_22 = __WHITESPACE(_in);
											if (!(_22.status))
											{
												_24 = AUTO_63(_in);
												if (!(_24.status))
												{
													_26 = AUTO_8(_in);
													if (!(_26.status))
													{
														_28 = AUTO_64(_in);
														if (!(_28.status))
														{
															_30 = AUTO_65(_in);
															if (!(_30.status))
															{
																_32 = AUTO_18(_in);
																if (!(_32.status))
																{
																	_34 = AUTO_10(_in);
																	if (!(_34.status))
																	{
																		_36 = AUTO_15(_in);
																		if (!(_36.status))
																		{
																			_38 = AUTO_40(_in);
																			if (!(_38.status))
																			{
																				_40 = AUTO_66(_in);
																				if (!(_40.status))
																				{
																					_42 = AUTO_9(_in);
																					if (!(_42.status))
																					{
																						_44 = AUTO_17(_in);
																						if (!(_44.status))
																						{
																							_46 = AUTO_19(_in);
																							if (!(_46.status))
																							{
																								_48 = AUTO_67(_in);
																								if (!(_48.status))
																								{
																									_50 = AUTO_91(_in);
																									if (!(_50.status))
																									{
																										_52 = AUTO_11(_in);
																										if (!(_52.status))
																										{
																											_54 = AUTO_20(_in);
																											if (!(_54.status))
																											{
																												_56 = AUTO_21(_in);
																												if (!(_56.status))
																												{
																													_58 = AUTO_22(_in);
																													if (!(_58.status))
																													{
																														_60 = AUTO_23(_in);
																														if (!(_60.status))
																														{
																															_62 = AUTO_24(_in);
																															if (!(_62.status))
																															{
																																_64 = AUTO_25(_in);
																																if (!(_64.status))
																																{
																																	_66 = AUTO_41(_in);
																																	if (!(_66.status))
																																	{
																																		_68 = AUTO_68(_in);
																																		if (!(_68.status))
																																		{
																																			_70 = AUTO_84(_in);
																																			if (!(_70.status))
																																			{
																																				_72 = AUTO_26(_in);
																																				if (!(_72.status))
																																				{
																																					_74 = AUTO_39(_in);
																																					if (!(_74.status))
																																					{
																																						_76 = AUTO_52(_in);
																																						if (!(_76.status))
																																						{
																																							_78 = AUTO_53(_in);
																																							if (!(_78.status))
																																							{
																																								_80 = AUTO_96(_in);
																																								if (!(_80.status))
																																								{
																																									_82 = AUTO_100(_in);
																																									if (!(_82.status))
																																									{
																																										_84 = AUTO_102(_in);
																																										if (!(_84.status))
																																										{
																																											_86 = AUTO_1(_in);
																																											if (!(_86.status))
																																											{
																																												_88 = AUTO_3(_in);
																																												if (!(_88.status))
																																												{
																																													_90 = AUTO_4(_in);
																																													if (!(_90.status))
																																													{
																																														_92 = AUTO_47(_in);
																																														if (!(_92.status))
																																														{
																																															_94 = AUTO_57(_in);
																																															if (!(_94.status))
																																															{
																																																_96 = AUTO_62(_in);
																																																if (!(_96.status))
																																																{
																																																	_98 = AUTO_69(_in);
																																																	if (!(_98.status))
																																																	{
																																																		_100 = AUTO_73(_in);
																																																		if (!(_100.status))
																																																		{
																																																			_102 = AUTO_74(_in);
																																																			if (!(_102.status))
																																																			{
																																																				_104 = AUTO_75(_in);
																																																				if (!(_104.status))
																																																				{
																																																					_106 = AUTO_76(_in);
																																																					if (!(_106.status))
																																																					{
																																																						_108 = AUTO_77(_in);
																																																						if (!(_108.status))
																																																						{
																																																							_110 = AUTO_78(_in);
																																																							if (!(_110.status))
																																																							{
																																																								_112 = AUTO_79(_in);
																																																								if (!(_112.status))
																																																								{
																																																									_114 = AUTO_80(_in);
																																																									if (!(_114.status))
																																																									{
																																																										_116 = AUTO_81(_in);
																																																										if (!(_116.status))
																																																										{
																																																											_118 = AUTO_82(_in);
																																																											if (!(_118.status))
																																																											{
																																																												_120 = AUTO_88(_in);
																																																												if (!(_120.status))
																																																												{
																																																													_122 = AUTO_89(_in);
																																																													if (!(_122.status))
																																																													{
																																																														_124 = AUTO_93(_in);
																																																														if (!(_124.status))
																																																														{
																																																															_126 = AUTO_95(_in);
																																																															if (!(_126.status))
																																																															{
																																																																_128 = AUTO_99(_in);
																																																																if (!(_128.status))
																																																																{
																																																																	_130 = BOOLEAN(_in);
																																																																	if (!(_130.status))
																																																																	{
																																																																		_132 = ID(_in);
																																																																		if (!(_132.status))
																																																																		{
																																																																			_134 = AUTO_97(_in);
																																																																			if (!(_134.status))
																																																																			{
																																																																				return {};
																																																																			}
																																																																			else 
																																																																			{
																																																																				success_135 = true;
																																																																				_in += _134.node.length();
																																																																				_0 = _134.node;
																																																																			}
																																																																		}
																																																																		else 
																																																																		{
																																																																			success_133 = true;
																																																																			_in += _132.node.length();
																																																																			_0 = _132.node;
																																																																		}
																																																																	}
																																																																	else 
																																																																	{
																																																																		success_131 = true;
																																																																		_in += _130.node.length();
																																																																		_0 = _130.node;
																																																																	}
																																																																}
																																																																else 
																																																																{
																																																																	success_129 = true;
																																																																	_in += _128.node.length();
																																																																	_0 = _128.node;
																																																																}
																																																															}
																																																															else 
																																																															{
																																																																success_127 = true;
																																																																_in += _126.node.length();
																																																																_0 = _126.node;
																																																															}
																																																														}
																																																														else 
																																																														{
																																																															success_125 = true;
																																																															_in += _124.node.length();
																																																															_0 = _124.node;
																																																														}
																																																													}
																																																													else 
																																																													{
																																																														success_123 = true;
																																																														_in += _122.node.length();
																																																														_0 = _122.node;
																																																													}
																																																												}
																																																												else 
																																																												{
																																																													success_121 = true;
																																																													_in += _120.node.length();
																																																													_0 = _120.node;
																																																												}
																																																											}
																																																											else 
																																																											{
																																																												success_119 = true;
																																																												_in += _118.node.length();
																																																												_0 = _118.node;
																																																											}
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
Parser::Rule_res Parser::Parser::accessor_group(::Parser::arr_t<Token>::iterator pos) {
	auto in = pos;
	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	::Parser::Token _2;
	::Parser::bool_t success_3 = false;
	if (!(pos->name() == Tokens::AUTO_4))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos++;
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name() == Tokens::NUMBER))
	{
		return {};
	}
	_2 = *pos;
	success_3 = true;
	pos++;
	accessor_group_data data = _2;
	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), Rules::accessor_group, data)};
}
Parser::Rule_res Parser::Parser::accessor_element(::Parser::arr_t<Token>::iterator pos) {
	auto in = pos;
	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	::Parser::Token _2;
	::Parser::bool_t success_3 = false;
	if (!(pos->name() == Tokens::AUTO_1))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos++;
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name() == Tokens::NUMBER))
	{
		return {};
	}
	_2 = *pos;
	success_3 = true;
	pos++;
	accessor_element_data data = _2;
	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), Rules::accessor_element, data)};
}
Parser::Rule_res Parser::Parser::accessor_char(::Parser::arr_t<Token>::iterator pos) {
	auto in = pos;
	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	::Parser::Token _2;
	::Parser::bool_t success_3 = false;
	if (!(pos->name() == Tokens::AUTO_81))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos++;
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name() == Tokens::NUMBER))
	{
		return {};
	}
	_2 = *pos;
	success_3 = true;
	pos++;
	accessor_char_data data = _2;
	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), Rules::accessor_char, data)};
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
	if (!(_2.status))
	{
		_4 = accessor_element(pos);
		if (!(_4.status))
		{
			_6 = accessor_char(pos);
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
	accessor_all_data data = _0;
	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), Rules::accessor_all, data)};
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
		if (!(begin_10->name() == Tokens::AUTO_3))
		{
			break;
		}
		_4 = *begin_10;
		success_5 = true;
		begin_10++;
		shadow_6.push_back(_4);
		ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
		_7 = accessor_all(begin_10);
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
	accessor_data data;
	data.second = shadow_9;
	data.first = _0.node;

	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), Rules::accessor, data)};
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
	if (!(pos->name() == Tokens::AUTO_4))
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
		if (!(_8.status))
		{
			_11 = cll_if(begin_29);
			if (!(_11.status))
			{
				_14 = expr(begin_29);
				if (!(_14.status))
				{
					_17 = method_call(begin_29);
					if (!(_17.status))
					{
						_20 = loop_while(begin_29);
						if (!(_20.status))
						{
							_23 = loop_for(begin_29);
							if (!(_23.status))
							{
								_26 = copiable_method_call(begin_29);
								if (!(_26.status))
								{
									break;
								}
								else 
								{
									success_27 = true;
									std::advance(begin_29, _26.node.length());
									shadow_28.push_back(_26.node);
									_6.push_back(_26.node);
								}
							}
							else 
							{
								success_24 = true;
								std::advance(begin_29, _23.node.length());
								shadow_25.push_back(_23.node);
								_6.push_back(_23.node);
							}
						}
						else 
						{
							success_21 = true;
							std::advance(begin_29, _20.node.length());
							shadow_22.push_back(_20.node);
							_6.push_back(_20.node);
						}
					}
					else 
					{
						success_18 = true;
						std::advance(begin_29, _17.node.length());
						shadow_19.push_back(_17.node);
						_6.push_back(_17.node);
					}
				}
				else 
				{
					success_15 = true;
					std::advance(begin_29, _14.node.length());
					shadow_16.push_back(_14.node);
					_6.push_back(_14.node);
				}
			}
			else 
			{
				success_12 = true;
				std::advance(begin_29, _11.node.length());
				shadow_13.push_back(_11.node);
				_6.push_back(_11.node);
			}
		}
		else 
		{
			success_9 = true;
			std::advance(begin_29, _8.node.length());
			shadow_10.push_back(_8.node);
			_6.push_back(_8.node);
		}
		success_7 = true;
		_4 = _6;
		if (success_7)
		{
			success_5 = true;
			begin_33 = begin_29;
		}
		ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
		if (!(begin_33->name() == Tokens::END))
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
	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), Rules::cll, data)};
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
	if (!(pos->name() == Tokens::AUTO_57))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos++;
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	while (pos->name() == Tokens::AUTO_73)
	{
		_2 = *pos;
		success_3 = true;
		pos++;
		shadow_4.push_back(_2);
	}
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name() == Tokens::AUTO_62))
	{
		return {};
	}
	_5 = *pos;
	success_6 = true;
	pos++;
	cll_block_data data = shadow_4;
	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), Rules::cll_block, data)};
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
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::OP, data)};
}
Parser::Token_res Parser::Tokenizator::ASSIGNMENT_OP(const char* pos) {
	auto in = pos;
	::Parser::Token_res _0;
	::Parser::bool_t success_1 = false;
	::Parser::Token_res _2;
	::Parser::bool_t success_3 = false;
	_0 = OP(pos);
	if (_0.status)
	{
		success_1 = true;
		pos += _0.node.length();
	}
	ISPA_STD::skip_spaces(pos);
	_2 = AUTO_47(pos);
	if (!(_2.status))
	{
		return {};
	}
	success_3 = true;
	pos += _2.node.length();
	ASSIGNMENT_OP_data data = _0.node;
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::ASSIGNMENT_OP, data)};
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
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::COMPARE_OP, data)};
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
	if (!(_2.status))
	{
		_4 = LOGICAL_OR(pos);
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
	LOGICAL_OP_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::LOGICAL_OP, data)};
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
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::LOGICAL_NOT)};
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
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::LOGICAL_AND)};
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
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::LOGICAL_OR)};
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
		if (!(begin_10->name() == Tokens::AUTO_69))
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
	cll_template_data data;
	data.second = shadow_9;
	data.first = _0.node;

	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), Rules::cll_template, data)};
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
		if (begin_26->name() == Tokens::AUTO_8)
		{
			_4 = *begin_26;
			success_5 = true;
			begin_26++;
		}
		ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
		auto begin_25 = begin_26;
		if (!(begin_25->name() == Tokens::AUTO_9))
		{
			if (!(begin_25->name() == Tokens::AUTO_10))
			{
				if (!(begin_25->name() == Tokens::AUTO_11))
				{
					if (!(begin_25->name() == Tokens::AUTO_17))
					{
						auto begin_24 = begin_25;
						do
						{
							if (!(begin_24->name() == Tokens::AUTO_17))
							{
								break;
							}
							_20 = *begin_24;
							success_21 = true;
							begin_24++;
							ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
							if (!(begin_24->name() == Tokens::AUTO_17))
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
			if (!(begin_42->name() == Tokens::AUTO_15))
			{
				if (!(begin_42->name() == Tokens::AUTO_18))
				{
					auto begin_41 = begin_42;
					do
					{
						if (!(begin_41->name() == Tokens::AUTO_17))
						{
							break;
						}
						_37 = *begin_41;
						success_38 = true;
						begin_41++;
						ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
						if (!(begin_41->name() == Tokens::AUTO_18))
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
						return {};
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

	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), Rules::cll_csupport_types, data)};
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
	if (!(begin_28->name() == Tokens::AUTO_19))
	{
		if (!(begin_28->name() == Tokens::AUTO_20))
		{
			if (!(begin_28->name() == Tokens::AUTO_21))
			{
				if (!(begin_28->name() == Tokens::AUTO_22))
				{
					if (!(begin_28->name() == Tokens::AUTO_23))
					{
						auto begin_20 = begin_28;
						do
						{
							if (!(begin_20->name() == Tokens::AUTO_24))
							{
								break;
							}
							_16 = *begin_20;
							success_17 = true;
							begin_20++;
							ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
							_18 = cll_template(begin_20);
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
								if (!(begin_27->name() == Tokens::AUTO_25))
								{
									break;
								}
								_23 = *begin_27;
								success_24 = true;
								begin_27++;
								ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
								_25 = cll_template(begin_27);
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
	cll_type_abstract_data data;
	data.templ = _23;
	data.type = _16;

	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), Rules::cll_type_abstract, data)};
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
	if (!(_2.status))
	{
		_4 = cll_type_abstract(pos);
		if (!(_4.status))
		{
			return {};
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
	cll_type_data data = _0;
	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), Rules::cll_type, data)};
}
Parser::Rule_res Parser::Parser::cll_if(::Parser::arr_t<Token>::iterator pos) {
	auto in = pos;
	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	::Parser::Rule_res _2;
	::Parser::bool_t success_3 = false;
	::Parser::Rule_res _4;
	::Parser::bool_t success_5 = false;
	if (!(pos->name() == Tokens::AUTO_26))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos++;
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	_2 = expr(pos);
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
	if (!(_0.status))
	{
		return {};
	}
	success_1 = true;
	std::advance(pos, _0.node.length());
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name() == Tokens::AUTO_74))
	{
		return {};
	}
	_2 = *pos;
	success_3 = true;
	pos++;
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	_4 = expr(pos);
	if (!(_4.status))
	{
		return {};
	}
	success_5 = true;
	std::advance(pos, _4.node.length());
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name() == Tokens::AUTO_95))
	{
		return {};
	}
	_6 = *pos;
	success_7 = true;
	pos++;
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	_8 = expr(pos);
	if (!(_8.status))
	{
		return {};
	}
	success_9 = true;
	std::advance(pos, _8.node.length());
	cll_ternary_data data;
	data.second = _8.node;
	data.first = _4.node;
	data.cond = _0.node;

	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), Rules::cll_ternary, data)};
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
	if (!(_2.status))
	{
		_4 = expr_arithmetic(pos);
		if (!(_4.status))
		{
			_6 = expr_for_arithmetic(pos);
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
	if (!(pos->name() == Tokens::LOGICAL_OP))
	{
		return {};
	}
	_8 = *pos;
	success_9 = true;
	pos++;
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	_12 = expr_compare(pos);
	if (!(_12.status))
	{
		_14 = expr_arithmetic(pos);
		if (!(_14.status))
		{
			_16 = expr_for_arithmetic(pos);
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
	expr_logical_data data;
	data.right = _10;
	data.op = _8;
	data.left = _0;

	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), Rules::expr_logical, data)};
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
		if (!(begin_10->name() == Tokens::COMPARE_OP))
		{
			break;
		}
		_4 = *begin_10;
		success_5 = true;
		begin_10++;
		shadow_6.push_back(_4);
		ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
		_7 = expr_arithmetic(begin_10);
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
	expr_compare_data data;
	data.sequence = shadow_9;
	data.operators = shadow_6;
	data.first = _0.node;

	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), Rules::expr_compare, data)};
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
		if (!(begin_10->name() == Tokens::OP))
		{
			return {};
		}
		_4 = *begin_10;
		success_5 = true;
		begin_10++;
		shadow_6.push_back(_4);
		ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
		_7 = expr_for_arithmetic(begin_10);
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
	expr_arithmetic_data data;
	data.sequence = shadow_9;
	data.operators = shadow_6;
	data.first = _0.node;

	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), Rules::expr_arithmetic, data)};
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
	if (!(_2.status))
	{
		_4 = method_call(pos);
		if (!(_4.status))
		{
			_6 = expr_group(pos);
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
	expr_for_arithmetic_data data = _0;
	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), Rules::expr_for_arithmetic, data)};
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
	if (!(pos->name() == Tokens::AUTO_78))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos++;
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	_4 = cll_ternary(pos);
	if (!(_4.status))
	{
		_6 = expr(pos);
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
	if (!(pos->name() == Tokens::AUTO_79))
	{
		return {};
	}
	_8 = *pos;
	success_9 = true;
	pos++;
	expr_group_data data = _2;
	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), Rules::expr_group, data)};
}
Parser::Rule_res Parser::Parser::expr_expr_copiable_method_call(::Parser::arr_t<Token>::iterator pos) {
	auto in = pos;
	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	::Parser::Rule_res _2;
	::Parser::bool_t success_3 = false;
	::Parser::Token _4;
	::Parser::bool_t success_5 = false;
	if (!(pos->name() == Tokens::AUTO_78))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos++;
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	_2 = copiable_method_call(pos);
	if (!(_2.status))
	{
		return {};
	}
	success_3 = true;
	std::advance(pos, _2.node.length());
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name() == Tokens::AUTO_79))
	{
		return {};
	}
	_4 = *pos;
	success_5 = true;
	pos++;
	expr_expr_copiable_method_call_data data = _2.node;
	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), Rules::expr_expr_copiable_method_call, data)};
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
	if (!(_2.status))
	{
		_4 = expr_compare(pos);
		if (!(_4.status))
		{
			_6 = expr_arithmetic(pos);
			if (!(_6.status))
			{
				_8 = cll_function_call(pos);
				if (!(_8.status))
				{
					_10 = expr_group(pos);
					if (!(_10.status))
					{
						_12 = expr_expr_copiable_method_call(pos);
						if (!(_12.status))
						{
							_14 = any_data(pos);
							if (!(_14.status))
							{
								return {};
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
							success_13 = true;
							std::advance(pos, _12.node.length());
							_0 = _12.node;
						}
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
	expr_data data = _0;
	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), Rules::expr, data)};
}
Parser::Rule_res Parser::Parser::function_body_call(::Parser::arr_t<Token>::iterator pos) {
	auto in = pos;
	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	::Parser::Rule_res _2;
	::Parser::bool_t success_3 = false;
	::Parser::Token _4;
	::Parser::bool_t success_5 = false;
	if (!(pos->name() == Tokens::AUTO_78))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos++;
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	_2 = function_arguments(pos);
	if (!(_2.status))
	{
		return {};
	}
	success_3 = true;
	std::advance(pos, _2.node.length());
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name() == Tokens::AUTO_79))
	{
		return {};
	}
	_4 = *pos;
	success_5 = true;
	pos++;
	function_body_call_data data = _2.node;
	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), Rules::function_body_call, data)};
}
Parser::Rule_res Parser::Parser::function_body_decl(::Parser::arr_t<Token>::iterator pos) {
	auto in = pos;
	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	::Parser::Rule_res _2;
	::Parser::bool_t success_3 = false;
	::Parser::Token _4;
	::Parser::bool_t success_5 = false;
	if (!(pos->name() == Tokens::AUTO_78))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos++;
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	_2 = function_parameters(pos);
	if (!(_2.status))
	{
		return {};
	}
	success_3 = true;
	std::advance(pos, _2.node.length());
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name() == Tokens::AUTO_79))
	{
		return {};
	}
	_4 = *pos;
	success_5 = true;
	pos++;
	function_body_decl_data data = _2.node;
	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), Rules::function_body_decl, data)};
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
		if (!(begin_15->name() == Tokens::AUTO_69))
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

	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), Rules::function_arguments, data)};
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
		if (!(begin_12->name() == Tokens::AUTO_69))
		{
			return {};
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
	function_parameters_data data;
	data.second = shadow_11;
	data.first = _2;

	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), Rules::function_parameters, data)};
}
Parser::Rule_res Parser::Parser::cll_function_call(::Parser::arr_t<Token>::iterator pos) {
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
	_2 = function_body_call(pos);
	if (!(_2.status))
	{
		return {};
	}
	success_3 = true;
	std::advance(pos, _2.node.length());
	cll_function_call_data data;
	data.body = _2.node;
	data.name = _0;

	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), Rules::cll_function_call, data)};
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
	if (!(pos->name() == Tokens::AUTO_39))
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
	_9 = function_body_decl(pos);
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
	function_decl_data data;
	data.value = val;
	data.name = _2;
	data.type = shadow_6;

	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), Rules::function_decl, data)};
}
Parser::Rule_res Parser::Parser::loop_while(::Parser::arr_t<Token>::iterator pos) {
	auto in = pos;
	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	::Parser::Rule_res _2;
	::Parser::bool_t success_3 = false;
	::Parser::Rule_res _4;
	::Parser::bool_t success_5 = false;
	if (!(pos->name() == Tokens::AUTO_40))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos++;
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	_2 = expr(pos);
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
	loop_while_data data;
	data.block = _4.node;
	data.expr = _2.node;

	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), Rules::loop_while, data)};
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
	if (!(pos->name() == Tokens::AUTO_41))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos++;
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name() == Tokens::AUTO_78))
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
	if (!(pos->name() == Tokens::AUTO_93))
	{
		return {};
	}
	_13 = *pos;
	success_14 = true;
	pos++;
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	_15 = expr(pos);
	if (_15.status)
	{
		success_16 = true;
		std::advance(pos, _15.node.length());
	}
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name() == Tokens::AUTO_93))
	{
		return {};
	}
	_17 = *pos;
	success_18 = true;
	pos++;
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	_19 = expr(pos);
	if (_19.status)
	{
		success_20 = true;
		std::advance(pos, _19.node.length());
	}
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name() == Tokens::AUTO_79))
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
	loop_for_data data;
	data.block = _21;
	data.end = _17;
	data.cond = _13;
	data.decl = _6;

	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), Rules::loop_for, data)};
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
	if (!(pos->name() == Tokens::ID))
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
		if (!(begin_10->name() == Tokens::AUTO_89))
		{
			break;
		}
		_4 = *begin_10;
		success_5 = true;
		begin_10++;
		shadow_6.push_back(_4);
		ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
		_7 = cll_function_call(begin_10);
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
	method_call_data data;
	data.call = shadow_9;
	data.object = _0;

	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), Rules::method_call, data)};
}
Parser::Rule_res Parser::Parser::copiable_method_call(::Parser::arr_t<Token>::iterator pos) {
	auto in = pos;
	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	::Parser::Rule_res _2;
	::Parser::bool_t success_3 = false;
	if (!(pos->name() == Tokens::AUTO_47))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos++;
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	_2 = method_call(pos);
	if (!(_2.status))
	{
		return {};
	}
	success_3 = true;
	std::advance(pos, _2.node.length());
	copiable_method_call_data data = _2.node;
	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), Rules::copiable_method_call, data)};
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
		if (!(begin_8->name() == Tokens::AUTO_52))
		{
			if (!(begin_8->name() == Tokens::AUTO_53))
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
		if (!(begin_19->name() == Tokens::AUTO_80))
		{
			break;
		}
		_13 = *begin_19;
		success_14 = true;
		begin_19++;
		ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
		_15 = expr(begin_19);
		if (!(_15.status))
		{
			break;
		}
		success_16 = true;
		std::advance(begin_19, _15.node.length());
		ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
		if (!(begin_19->name() == Tokens::AUTO_82))
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
		if (!(begin_28->name() == Tokens::AUTO_52))
		{
			if (!(begin_28->name() == Tokens::AUTO_53))
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
	data.brace_expression = _15.node;
	data.name = _2;

	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), Rules::var_refer, data)};
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
	auto begin_14 = pos;
	do
	{
		if (!(begin_14->name() == Tokens::ASSIGNMENT_OP))
		{
			break;
		}
		_6 = *begin_14;
		success_7 = true;
		begin_14++;
		ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
		_10 = expr(begin_14);
		if (!(_10.status))
		{
			_12 = cll_ternary(begin_14);
			if (!(_12.status))
			{
				break;
			}
			else 
			{
				success_13 = true;
				std::advance(begin_14, _12.node.length());
				_8 = _12.node;
			}
		}
		else 
		{
			success_11 = true;
			std::advance(begin_14, _10.node.length());
			_8 = _10.node;
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
	data.type = _0.node;

	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), Rules::cll_var, data)};
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
	if (!(pos->name() == Tokens::AUTO_80))
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
			if (!(begin_12->name() == Tokens::AUTO_69))
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
	if (!(pos->name() == Tokens::AUTO_82))
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
	if (!(pos->name() == Tokens::AUTO_57))
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
		if (!(begin_27->name() == Tokens::AUTO_95))
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
			if (!(begin_24->name() == Tokens::AUTO_69))
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
			if (!(begin_24->name() == Tokens::AUTO_95))
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
		if (!(begin_27->name() == Tokens::AUTO_93))
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
	if (!(pos->name() == Tokens::AUTO_62))
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
	if (!(pos->name() == Tokens::NUMBER))
	{
		if (!(pos->name() == Tokens::STRING))
		{
			_6 = accessor(pos);
			if (!(_6.status))
			{
				_8 = array(pos);
				if (!(_8.status))
				{
					_10 = object(pos);
					if (!(_10.status))
					{
						if (!(pos->name() == Tokens::BOOLEAN))
						{
							if (!(pos->name() == Tokens::ID))
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
	if (!(pos->name() == Tokens::AUTO_63))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos++;
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name() == Tokens::AUTO_64))
	{
		if (!(pos->name() == Tokens::AUTO_65))
		{
			if (!(pos->name() == Tokens::AUTO_66))
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
	if (!(pos->name() == Tokens::AUTO_67))
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
	if (!(pos->name() == Tokens::AUTO_73))
	{
		_4 = spacemode(pos);
		if (!(_4.status))
		{
			_6 = name(pos);
			if (!(_6.status))
			{
				_8 = use(pos);
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
		_2 = *pos;
		success_3 = true;
		std::advance(pos, 1);
		_0 = _2;
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
	if (!(pos->name() == Tokens::AUTO_68))
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
		if (!(begin_12->name() == Tokens::AUTO_69))
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
	if (!(_2.status))
	{
		if (!(pos->name() == Tokens::LINEAR_COMMENT))
		{
			if (!(pos->name() == Tokens::AUTO_89))
			{
				if (!(pos->name() == Tokens::AUTO_73))
				{
					_10 = cll(pos);
					if (!(_10.status))
					{
						auto begin_35 = pos;
						do
						{
							auto begin_32 = begin_35;
							_18 = expr_group(begin_32);
							if (!(_18.status))
							{
								_20 = Rule_csequence(begin_32);
								if (!(_20.status))
								{
									if (!(begin_32->name() == Tokens::STRING))
									{
										_24 = accessor(begin_32);
										if (!(_24.status))
										{
											_26 = Rule_hex(begin_32);
											if (!(_26.status))
											{
												_28 = Rule_bin(begin_32);
												if (!(_28.status))
												{
													_30 = Rule_other(begin_32);
													if (!(_30.status))
													{
														break;
													}
													else 
													{
														success_31 = true;
														std::advance(begin_32, _30.node.length());
														_16 = _30.node;
													}
												}
												else 
												{
													success_29 = true;
													std::advance(begin_32, _28.node.length());
													_16 = _28.node;
												}
											}
											else 
											{
												success_27 = true;
												std::advance(begin_32, _26.node.length());
												_16 = _26.node;
											}
										}
										else 
										{
											success_25 = true;
											std::advance(begin_32, _24.node.length());
											_16 = _24.node;
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
									std::advance(begin_32, _20.node.length());
									_16 = _20.node;
								}
							}
							else 
							{
								success_19 = true;
								std::advance(begin_32, _18.node.length());
								_16 = _18.node;
							}
							success_17 = true;
							if (success_17)
							{
								success_15 = true;
								begin_35 = begin_32;
							}
							ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
							_33 = Rule_qualifier(begin_35);
							if (_33.status)
							{
								success_34 = true;
								std::advance(begin_35, _33.node.length());
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
						std::advance(pos, _10.node.length());
						_0 = _10.node;
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
		std::advance(pos, _2.node.length());
		_0 = _2.node;
	}
	success_1 = true;
	Rule_rule_data data;
	data.qualifier = _14;
	data.val = _16;

	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), Rules::Rule_rule, data)};
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
	if (pos->name() == Tokens::AUTO_99)
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
		if (!(begin_12->name() == Tokens::AUTO_89))
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
	Rule_other_data data;
	data.nested_name = shadow_11;
	data.name = _2;
	data.is_nested = _0;

	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), Rules::Rule_other, data)};
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
	if (!(begin_10->name() == Tokens::AUTO_74))
	{
		if (!(begin_10->name() == Tokens::AUTO_75))
		{
			if (!(begin_10->name() == Tokens::AUTO_76))
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
	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), Rules::Rule_qualifier, data)};
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
		if (!(begin_10->name() == Tokens::AUTO_77))
		{
			break;
		}
		_2 = *begin_10;
		success_3 = true;
		begin_10++;
		ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
		_6 = method_call(begin_10);
		if (!(_6.status))
		{
			if (!(begin_10->name() == Tokens::ID))
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
			std::advance(begin_10, _6.node.length());
			_4 = _6.node;
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
	if (!(pos->name() == Tokens::AUTO_78))
	{
		return {};
	}
	_11 = *pos;
	success_12 = true;
	pos++;
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	_13 = Rule_rule(pos);
	while (_13.status)
	{
		success_14 = true;
		std::advance(pos, _13.node.length());
		_13 = Rule_rule(pos);
	}
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name() == Tokens::AUTO_79))
	{
		return {};
	}
	_15 = *pos;
	success_16 = true;
	pos++;
	Rule_group_data data;
	data.val = _13.node;
	data.variable = _2;

	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), Rules::Rule_group, data)};
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
	if (!(begin_10->name() == Tokens::AUTO_83))
	{
		if (!(begin_10->name() == Tokens::AUTO_84))
		{
			if (!(begin_10->name() == Tokens::AUTO_96))
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
	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), Rules::Rule_csequence_symbol, data)};
}
Parser::Rule_res Parser::Parser::Rule_csequence_escape(::Parser::arr_t<Token>::iterator pos) {
	auto in = pos;
	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	::Parser::Token _2;
	::Parser::bool_t success_3 = false;
	::Parser::Token _4;
	::Parser::bool_t success_5 = false;
	if (!(pos->name() == Tokens::AUTO_96))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos++;
	auto begin_6 = pos;
	if (!(begin_6->name() == Tokens::AUTO_97))
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
	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), Rules::Rule_csequence_escape, data)};
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
	if (!(_3.status))
	{
		return {};
	}
	success_4 = true;
	std::advance(begin_5, _3.node.length());
	from = _3.node;
	if (success_4)
	{
		success_2 = true;
		begin_12 = begin_5;
	}
	if (!(begin_12->name() == Tokens::AUTO_88))
	{
		return {};
	}
	_6 = *begin_12;
	success_7 = true;
	begin_12++;
	auto begin_11 = begin_12;
	_9 = Rule_csequence_symbol(begin_11);
	if (!(_9.status))
	{
		return {};
	}
	success_10 = true;
	std::advance(begin_11, _9.node.length());
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
	Rule_csequence_diapason_data data = {from,to};
	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), Rules::Rule_csequence_diapason, data)};
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
	if (!(pos->name() == Tokens::AUTO_80))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos++;
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	if (pos->name() == Tokens::AUTO_81)
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
		if (!(_7.status))
		{
			_10 = Rule_csequence_symbol(begin_16);
			if (!(_10.status))
			{
				_13 = Rule_csequence_diapason(begin_16);
				if (!(_13.status))
				{
					break;
				}
				else 
				{
					success_14 = true;
					std::advance(begin_16, _13.node.length());
					shadow_15.push_back(_13.node);
					_5.push_back(_13.node);
				}
			}
			else 
			{
				success_11 = true;
				std::advance(begin_16, _10.node.length());
				shadow_12.push_back(_10.node);
				_5.push_back(_10.node);
			}
		}
		else 
		{
			success_8 = true;
			std::advance(begin_16, _7.node.length());
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
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name() == Tokens::AUTO_82))
	{
		return {};
	}
	_18 = *pos;
	success_19 = true;
	pos++;
	Rule_csequence_data data;
	data.val = dt;
	data._not = _2;

	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), Rules::Rule_csequence, data)};
}
Parser::Rule_res Parser::Parser::Rule_data_block_inclosed_map(::Parser::arr_t<Token>::iterator pos) {
	auto in = pos;
	::Parser::Rule_res _0;
	::Parser::bool_t success_1 = false;
	::Parser::bool_t success_2 = false;
	_0 = Rule_data_block_key(pos);
	while (_0.status)
	{
		success_1 = true;
		std::advance(pos, _0.node.length());
		_0 = Rule_data_block_key(pos);
		success_2 = true;
	}
	if (!success_2)
	{
		return {};
	}
	Rule_data_block_inclosed_map_data data = _0.node;
	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), Rules::Rule_data_block_inclosed_map, data)};
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
	while (pos->name() == Tokens::AUTO_98)
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
	if (!(pos->name() == Tokens::AUTO_95))
	{
		return {};
	}
	_8 = *pos;
	success_9 = true;
	pos++;
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	auto begin_17 = pos;
	_13 = cll_ternary(begin_17);
	if (!(_13.status))
	{
		_15 = expr(begin_17);
		if (!(_15.status))
		{
			return {};
		}
		else 
		{
			success_16 = true;
			std::advance(begin_17, _15.node.length());
			_11 = _15.node;
		}
	}
	else 
	{
		success_14 = true;
		std::advance(begin_17, _13.node.length());
		_11 = _13.node;
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

	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), Rules::Rule_data_block_key, data)};
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
	while (pos->name() == Tokens::AUTO_98)
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
	if (!(pos->name() == Tokens::AUTO_91))
	{
		return {};
	}
	_4 = *pos;
	success_5 = true;
	pos++;
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name() == Tokens::AUTO_95))
	{
		return {};
	}
	_6 = *pos;
	success_7 = true;
	pos++;
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	_10 = any_data(pos);
	if (!(_10.status))
	{
		_12 = Rule_data_block_inclosed_map(pos);
		if (!(_12.status))
		{
			return {};
		}
		else 
		{
			success_13 = true;
			std::advance(pos, _12.node.length());
			_8 = _12.node;
		}
	}
	else 
	{
		success_11 = true;
		std::advance(pos, _10.node.length());
		_8 = _10.node;
	}
	success_9 = true;
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name() == Tokens::AUTO_93))
	{
		return {};
	}
	_14 = *pos;
	success_15 = true;
	pos++;
	Rule_data_block_data data = _8;
	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), Rules::Rule_data_block, data)};
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
	if (!(pos->name() == Tokens::AUTO_96))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos++;
	auto begin_6 = pos;
	if (!(begin_6->name() == Tokens::AUTO_97))
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
	if (pos->name() == Tokens::NUMBER)
	{
		_7 = *pos;
		success_8 = true;
		pos++;
	}
	Rule_escaped_data data;
	data.num = _2;
	data.c = _2;

	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), Rules::Rule_escaped, data)};
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
	while (pos->name() == Tokens::AUTO_98)
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
	if (!(pos->name() == Tokens::AUTO_99))
	{
		return {};
	}
	_4 = *pos;
	success_5 = true;
	pos++;
	auto begin_10 = pos;
	if (!(begin_10->name() == Tokens::AUTO_73))
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
	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), Rules::Rule_nested_rule, data)};
}
Parser::Rule_res Parser::Parser::Rule_hex(::Parser::arr_t<Token>::iterator pos) {
	auto in = pos;
	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	::Parser::Token _2;
	::Parser::bool_t success_3 = false;
	::Parser::arr_t<::Parser::Token> shadow_4;
	::Parser::bool_t success_5 = false;
	if (!(pos->name() == Tokens::AUTO_100))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos++;
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	while (pos->name() == Tokens::AUTO_101)
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
	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), Rules::Rule_hex, data)};
}
Parser::Rule_res Parser::Parser::Rule_bin(::Parser::arr_t<Token>::iterator pos) {
	auto in = pos;
	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	::Parser::Token _2;
	::Parser::bool_t success_3 = false;
	::Parser::arr_t<::Parser::Token> shadow_4;
	::Parser::bool_t success_5 = false;
	if (!(pos->name() == Tokens::AUTO_102))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos++;
	ISPA_STD::skip_spaces<::Parser::arr_t<::Parser::Token>::iterator, ::Parser::Tokens>(pos);
	while (pos->name() == Tokens::AUTO_103)
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
	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), Rules::Rule_bin, data)};
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
	if (!(pos->name() == Tokens::AUTO_95))
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
	if (!(pos->name() == Tokens::AUTO_93))
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
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::AUTO_1, data)};
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
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::AUTO_3, data)};
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
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::AUTO_4, data)};
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
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::AUTO_8, data)};
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
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::AUTO_9, data)};
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
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::AUTO_10, data)};
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
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::AUTO_11, data)};
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
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::AUTO_15, data)};
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
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::AUTO_17, data)};
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
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::AUTO_18, data)};
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
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::AUTO_19, data)};
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
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::AUTO_20, data)};
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
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::AUTO_21, data)};
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
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::AUTO_22, data)};
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
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::AUTO_23, data)};
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
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::AUTO_24, data)};
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
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::AUTO_25, data)};
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
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::AUTO_26, data)};
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
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::AUTO_39, data)};
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
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::AUTO_40, data)};
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
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::AUTO_41, data)};
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
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::AUTO_47, data)};
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
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::AUTO_52, data)};
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
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::AUTO_53, data)};
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
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::AUTO_57, data)};
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
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::AUTO_62, data)};
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
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::AUTO_63, data)};
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
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::AUTO_64, data)};
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
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::AUTO_65, data)};
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
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::AUTO_66, data)};
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
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::AUTO_67, data)};
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
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::AUTO_68, data)};
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
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::AUTO_69, data)};
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
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::AUTO_73, data)};
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
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::AUTO_74, data)};
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
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::AUTO_75, data)};
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
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::AUTO_76, data)};
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
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::AUTO_77, data)};
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
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::AUTO_78, data)};
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
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::AUTO_79, data)};
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
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::AUTO_80, data)};
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
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::AUTO_81, data)};
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
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::AUTO_82, data)};
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
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::AUTO_83, data)};
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
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::AUTO_84, data)};
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
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::AUTO_88, data)};
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
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::AUTO_89, data)};
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
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::AUTO_91, data)};
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
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::AUTO_93, data)};
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
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::AUTO_95, data)};
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
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::AUTO_96, data)};
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
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::AUTO_97, data)};
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
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::AUTO_98, data)};
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
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::AUTO_99, data)};
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
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::AUTO_100, data)};
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
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::AUTO_101, data)};
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
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::AUTO_102, data)};
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
	return {true, ::Parser::Token(getCurrentPos(pos), in, pos, Tokens::AUTO_103, data)};
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
